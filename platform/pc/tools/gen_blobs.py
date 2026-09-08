#!/usr/bin/env python3
"""gen_blobs.py — translate assembled GBA data objects into host C sources.

Inputs are ARM .o files built from data/*.s through the exact GBA pipeline
(arm-cpp + preproc + arm-as), so bytes, charmap expansion, macros, alignment
and `.incbin` slices match the matching ROM bit-for-bit.

Each labeled object in .rodata becomes one C definition, classified by shape:
    byte-only          -> const u8 LABEL[] = { ... };
    all R_ARM_ABS32    -> const void *LABEL[] = { &a, &b, ... };
    FileArchive shape  -> const FileArchive LABEL = { magic, count, entries };
    SIRO shape (16B,   -> const SiroArchive LABEL = { "SIRO", &data, u1, u2 };
      reloc @ +4)
    File-table shape   -> const File LABEL[] = { {name, data}, ... };
    other mixed        -> bytes with zeroed reloc slots + fixup log (deep-port TODO)

Symbols in --keep (default: gDungeonFileArchive gSystemFileArchive) keep their
names because headers declare their types; all other labels are prefixed with
--prefix (default: blob) + object basename. All cross-references are rewritten
consistently. Every reloc target must resolve to an emitted symbol or a --extern
entry, otherwise this script fails loudly.
"""
import os
import re
import sys
import argparse
import subprocess

def run_tool(tool, *args):
    p = subprocess.run([tool, *args], capture_output=True, text=True)
    if p.returncode != 0:
        raise RuntimeError(f'{tool} failed: {p.stderr[:500]}')
    return p.stdout

class Obj:
    def __init__(self, name, offset, size, bind):
        self.name = name
        self.offset = offset
        self.size = size
        self.bind = bind

def read_object(path, toolchain):
    prefix = os.path.join(toolchain, 'arm-none-eabi-')
    sym_out = run_tool(prefix + 'readelf', '-sW', path)
    rel_out = run_tool(prefix + 'readelf', '-rW', path)
    sec_out = run_tool(prefix + 'readelf', '-SW', path)

    rodata_ndx = None
    for line in sec_out.splitlines():
        m = re.match(r'\s*\[\s*(\d+)\]\s+(\S+)', line)
        if m and m.group(2) == '.rodata':
            rodata_ndx = m.group(1)
    if rodata_ndx is None:
        raise ValueError(f'{path}: no .rodata section')

    syms = []
    for line in sym_out.splitlines():
        m = re.match(r'\s*\d+:\s+([0-9a-fA-F]+)\s+(\d+)\s+(\S+)\s+(\S+)\s+\S+\s+(\S+)\s*(\S*)', line)
        if not m:
            continue
        value, size, typ, bind, ndx, name = m.groups()
        if ndx != rodata_ndx or typ == 'SECTION' or not name:
            continue
        if typ not in ('OBJECT', 'NOTYPE'):
            continue
        if name.startswith('$'):
            continue  # ARM mapping symbols ($a, $d)
        syms.append(Obj(name, int(value, 16), int(size), bind))
    syms.sort(key=lambda s: s.offset)

    # section size via size tool output: parse from -SW line ([Nr] .rodata ... size)
    sec_size = None
    for line in sec_out.splitlines():
        m = re.match(r'\s*\[\s*\d+\]\s+\.rodata\s+\S+\s+[0-9a-fA-F]+\s+[0-9a-fA-F]+\s+([0-9a-fA-F]+)', line)
        if m:
            sec_size = int(m.group(1), 16)
    if sec_size is None:
        raise ValueError(f'{path}: cannot determine .rodata size')

    # infer sizes (assembler leaves NOTYPE sizes at 0). Aliases share an
    # offset, so measure to the next DISTINCT offset.
    distinct = sorted({s.offset for s in syms} | {sec_size})
    for s in syms:
        nxt = next(o for o in distinct if o > s.offset)
        if nxt < s.offset:
            raise ValueError(f'{path}: overlapping symbols at {s.offset:x}')
        s.size = nxt - s.offset
    # capture leading unlabeled content (e.g. archive preambles) as a header obj
    if syms and syms[0].offset > 0:
        syms.insert(0, Obj(f'{os.path.splitext(os.path.basename(path))[0]}__header',
                           0, syms[0].offset, 'LOCAL'))

    relocs = []  # (offset, target); target may be a symbol or '.rodata' etc.
    for line in rel_out.splitlines():
        m = re.match(r'([0-9a-fA-F]+)\s+[0-9a-fA-F]+\s+R_ARM_ABS32\s+[0-9a-fA-F]+\s+(\S+)', line)
        if m:
            relocs.append((int(m.group(1), 16), m.group(2)))

    tmp = path + '.rodata.bin'
    subprocess.run([prefix + 'objcopy', '-O', 'binary', '--only-section=.rodata', path, tmp],
                   check=True, capture_output=True)
    with open(tmp, 'rb') as f:
        blob = f.read()
    os.unlink(tmp)
    if len(blob) != sec_size:
        raise ValueError(f'{path}: rodata dump size {len(blob)} != {sec_size}')
    return syms, relocs, blob

def owner_of(syms, off):
    """Symbol owning section offset off (or None)."""
    best = None
    for s in syms:
        if s.offset <= off and (best is None or s.offset > best.offset):
            best = s
    return best


_ADDR_RE = re.compile(r'^gUnknown_([0-9a-fA-F]+)$')


def blob_addr_map(files, names, canon):
    """Per-blob .rodata base GBA address + canonical-name->GBA address.

    The .s data symbols are named by ROM address (gUnknown_830F66C is the u32
    0x0830F66C); the first parseable gUnknown anchors each blob's base, and
    every object's address = base + rodata offset.  Returns
    (file_base, addr_of) where file_base maps base->base GBA addr (None if no
    anchor) and addr_of maps canonical symbol name -> GBA addr.
    """
    file_base = {}
    addr_of = {}
    for base, syms, _, _ in files:
        anchor = None
        for s in sorted(syms, key=lambda x: x.offset):
            m = _ADDR_RE.match(s.name)
            if m:
                anchor = (int(m.group(1), 16), s.offset)
                break
        if anchor is None:
            continue
        baddr, boff = anchor
        baddr -= boff
        file_base[base] = baddr
        for s in syms:
            addr_of.setdefault(canon[s.name], baddr + s.offset)
    return file_base, addr_of

_SCALAR_SIZES = {'u8': (1, False), 's8': (1, True), 'bool8': (1, False),
                 'u16': (2, False), 's16': (2, True),
                 'u32': (4, False), 's32': (4, True)}

def _scalar_lit(kind, data):
    size, signed = _SCALAR_SIZES[kind]
    return str(int.from_bytes(data[:size], 'little', signed=signed))

def _emit_typed_fields(fields, img, pos, slots, names, canon, consumed=None):
    """Emit `{ .f = v, ... }` for fields; returns (text, new_pos)."""
    import re as _re
    parts = []
    for fname, fkind in fields:
        if isinstance(fkind, dict):  # nested struct
            sub, pos = _emit_typed_fields(list(fkind.items()), img, pos, slots,
                                          names, canon, consumed)
            parts.append(f'.{fname} = {sub}')
        elif fkind.startswith('pad:'):  # assembler padding, consume silently
            pos += int(fkind[4:])
        elif fkind.startswith('expr:'):  # verbatim C expression (numeric ROM ptrs)
            parts.append(f'.{fname} = ({fkind[5:]})')
            pos += 4
        elif fkind.startswith('ptr:'):
            cast = fkind[4:]
            if pos not in slots:
                raise ValueError(f'typed table: no reloc for ptr field {fname} @+{pos:x}')
            parts.append(f'.{fname} = ({cast}){slots[pos]}')
            if consumed is not None:
                consumed.add(pos)
            pos += 4
        else:
            m = _re.match(r'^(u8|s8|u16|s16|u32|s32|bool8)\[(\d+)\]$', fkind)
            if m:
                base, n = m.group(1), int(m.group(2))
                size = _SCALAR_SIZES[base][0]
                vals = [_scalar_lit(base, img[pos + k * size:pos + (k + 1) * size])
                        for k in range(n)]
                parts.append(f'.{fname} = {{ {", ".join(vals)} }}')
                pos += n * size
            else:
                size = _SCALAR_SIZES[fkind][0]
                parts.append(f'.{fname} = {_scalar_lit(fkind, img[pos:pos + size])}')
                pos += size
    return '{ ' + ', '.join(parts) + ' }', pos

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('inputs', nargs='+', help='ARM .o files from data/*.s')
    ap.add_argument('-o', '--outdir', required=True)
    ap.add_argument('--toolchain', required=True, help='dir with arm-none-eabi-* tools')
    ap.add_argument('--keep', default='gDungeonFileArchive,gSystemFileArchive')
    ap.add_argument('--extern', default='', help='comma-separated symbols defined elsewhere (C code)')
    ap.add_argument('--prefix', default='')
    ap.add_argument('--tables', default=None, help='tables.json for typed struct tables')
    ap.add_argument('--fixup-log', default=None)
    ap.add_argument('--baserom', default=None,
                    help='JSON { base: [[romOff, size], ...] } in source/rodata order; '
                         'those byte arrays are emitted writable and collected into '
                         'rom_slices_all.c for the runtime ROM loader')
    ap.add_argument('--addresses', default=None,
                    help='emit ONLY a GBA-address->host-pointer registry '
                         '(blob_addrs.c/.h) for every emitted object and exit')
    args = ap.parse_args()

    keep = set(args.keep.split(',')) if args.keep else set()
    externs = set(args.extern.split(',')) if args.extern else set()
    import json as _json
    baserom = {}
    if args.baserom:
        with open(args.baserom) as _f:
            baserom = _json.load(_f)
    typed = {}
    if args.tables:
        with open(args.tables) as f:
            typed = _json.load(f)
    outdir = os.path.abspath(args.outdir)
    os.makedirs(outdir, exist_ok=True)
    if args.fixup_log:
        args.fixup_log = os.path.abspath(args.fixup_log)

    # pass 1: read all objects
    files = []  # (base, syms, relocs, blob)
    all_manifest = []
    for path in args.inputs:
        base = os.path.splitext(os.path.basename(path))[0]
        syms, relocs, blob = read_object(path, args.toolchain)
        # Unlabeled baserom blobs (pure .incbin regions, no symbol) get a
        # synthetic symbol so the runtime ROM loader has an array to fill.
        if not syms and baserom.get(base):
            syms.append(Obj(f'pcBlob_{base}', 0, len(blob), 'LOCAL'))
            print(f'gen_blobs: {path}: no symbols; synthetic pcBlob_{base}')
        files.append((base, syms, relocs, blob))
        print(f'gen_blobs: {path}: {len(syms)} symbols, {len(relocs)} relocs, {len(blob)} bytes')

    # global rename map; alias groups share one definition
    names = {}
    canon = {}  # alias -> canonical original name
    for base, syms, _, _ in files:
        by_off = {}
        for s in syms:
            by_off.setdefault(s.offset, []).append(s)
        for off, group in by_off.items():
            first = group[0].name
            for s in group:
                canon[s.name] = first
            if args.prefix:
                names[first] = first if first in keep else f'{args.prefix}_{base}__{first}'
            else:
                names[first] = first

    defined = set(canon.keys())

    if args.addresses:
        # GBA-address -> host-pointer registry over every emitted object.
        file_base, addr_of = blob_addr_map(files, names, canon)
        entries = []  # (gba_addr, cname, size)
        relocs = []   # (vec_expr for the word, gba) — BAKED address words inside
                      # byte arrays, so the runtime can re-home them if the
                      # fixed 0x08000000 window is unavailable.
        externs_seen = set()
        import bisect as _bisect
        for base, syms, relocs_raw, blob in files:
            if base not in file_base:
                continue
            seen_off = set()
            for s in sorted(syms, key=lambda x: x.offset):
                if s.offset in seen_off:
                    continue
                seen_off.add(s.offset)
                cname = names[canon[s.name]]
                if cname in externs_seen:
                    continue
                externs_seen.add(cname)
                entries.append((file_base[base] + s.offset, cname, s.size))
            # baked address words inside byte objects (raw bytes + reloc slots
            # that are neither archive/siro/filetable/typed shapes)
            syms_sorted = sorted(syms, key=lambda x: x.offset)
            offs = [s.offset for s in syms_sorted]
            by_owner = {}
            for roff, target in relocs_raw:
                idx = _bisect.bisect_right(offs, roff) - 1
                if idx < 0:
                    continue
                owner = syms_sorted[idx].name
                by_owner.setdefault(canon[owner], []).append((roff - syms_sorted[idx].offset, roff, target))
            for s in syms_sorted:
                can = canon[s.name]
                slots = by_owner.get(can, [])
                if not slots or can in typed:
                    continue
                raw_len = s.size - 4 * len(slots)
                magic4 = blob[s.offset:s.offset + 4] if s.size >= 4 else b''
                is_siro = (magic4 in (b'SIRO', b'SIR0') and len(slots) == 1 and
                           slots[0][0] == 4 and raw_len <= 24)
                is_archive = (raw_len >= 12 and len(slots) == 1 and slots[0][0] == 12)
                if is_siro or is_archive or raw_len == 0:
                    continue  # typed/pointer-table shapes; host ptrs, not baked
                cname = names[can]
                for rel_off, roff, target in slots:
                    va = None
                    addend = int.from_bytes(blob[roff:roff + 4], 'little')
                    if target.startswith('.'):
                        if file_base.get(base) is not None and addend < len(blob):
                            va = file_base[base] + addend
                    elif target in canon:
                        va = addr_of.get(canon[target])
                        if va is not None:
                            va += addend
                    if va is not None:
                        relocs.append((f'(unsigned int *)((u8 *){cname} + 0x{rel_off:x})', va))
        entries.sort(key=lambda e: e[0])
        c_lines = ['/* generated by platform/pc/tools/gen_blobs.py — GBA address registry */']
        c_lines.append('#include "global.h"')
        c_lines.append('#include "rom_load.h"')
        for _, cname, _sz in entries:
            c_lines.append(f'extern u8 {cname}[];')
        c_lines.append('const PcGbaAddr pcGbaAddrTable[] = {')
        for gba, cname, sz in entries:
            c_lines.append(f'    {{ 0x{gba:08x}, 0x{sz:x}, (const u8 *){cname} }},')
        c_lines.append('};')
        c_lines.append(f'const unsigned pcGbaAddrCount = {len(entries)};')
        c_lines.append('')
        c_lines.append('const unsigned int *const pcGbaRelocTable[] = {')
        for ve, _ in sorted(relocs, key=lambda r: r[1]):
            c_lines.append(f'    {ve},')
        c_lines.append('};')
        c_lines.append(f'const unsigned pcGbaRelocCount = {len(relocs)};')
        out_c = args.addresses + '.c'
        with open(out_c, 'w') as f:
            f.write('\n'.join(c_lines) + '\n')
        h_lines = ['#ifndef PMDRED_PC_BLOB_ADDRS_H']
        h_lines.append('#define PMDRED_PC_BLOB_ADDRS_H')
        h_lines.append('#include "rom_load.h"')
        h_lines.append('extern const PcGbaAddr pcGbaAddrTable[];')
        h_lines.append('extern const unsigned pcGbaAddrCount;')
        h_lines.append('#endif')
        with open(args.addresses + '.h', 'w') as f:
            f.write('\n'.join(h_lines) + '\n')
        print(f'gen_blobs: address registry: {len(entries)} objects -> {args.addresses}.c/.h')
        return 0

    def slot_expr(base, syms, blob, off, target):
        """C pointer-valued expression for a reloc slot."""
        if target in canon:
            return f'&{names[canon[target]]}'
        if target in externs:
            return f'&{target}'
        if target.startswith('.'):
            # section-relative: .rodata + addend stored in the slot itself
            addend = int.from_bytes(blob[off:off + 4], 'little')
            owner = owner_of(syms, addend)
            if owner is None:
                raise ValueError(f'{base}: {target}+{addend:x} @+{off:x} resolves nowhere')
            inner = addend - owner.offset
            return f'((const u8 *)&{names[canon[owner.name]]} + 0x{inner:x})'
        raise ValueError(f'{base}: reloc target {target} @+{off:x} resolves nowhere')

    import bisect
    fixups = []
    file_ctx = []  # (base, syms, blob, order, kinds, slots_by_owner, table_targets)
    # Blob .rodata base GBA addresses + canonical-name->address (for writing
    # baked ROM-address reloc slots into byte objects; see bytes emission).
    _file_base, _addr_of = blob_addr_map(files, names, canon)
    for base, syms, relocs, blob in files:
        offs = [s.offset for s in syms]
        slots_by_owner = {s.name: [] for s in syms}
        for off, target in relocs:
            idx = bisect.bisect_right(offs, off) - 1
            if idx < 0 or off >= syms[idx].offset + syms[idx].size:
                raise ValueError(f'{base}: reloc @{off:x} outside all symbols')
            owner = syms[idx].name
            expr = slot_expr(base, syms, blob, off, target)
            slots_by_owner[owner].append((off - syms[idx].offset, expr, target))
        # merge slots of same-offset aliases into the canonical owner
        by_off = {}
        for s in syms:
            by_off.setdefault(s.offset, []).append(s.name)
        for off, group in by_off.items():
            first = group[0]
            for other in group[1:]:
                slots_by_owner[first].extend(slots_by_owner[other])
                slots_by_owner[other] = []
        for v in slots_by_owner.values():
            v.sort()

        # classify canonical objects only
        seen_offsets = set()
        kinds = {}
        table_targets = set()  # target NAMES that are File tables
        archive_objs = set()
        order = []
        for s in syms:
            if s.offset in seen_offsets:
                continue
            seen_offsets.add(s.offset)
            order.append(s)
        for s in order:
            slots = slots_by_owner[s.name]
            raw_len = s.size - 4 * len(slots)
            first8 = blob[s.offset:s.offset + 8] if s.size >= 8 else b''
            # FileArchive shape: magic[8] + s32 count + exactly one ptr (the
            # entries table). Trailing bytes (usually a second "pksdir0") are
            # assembler padding with no references; the struct drops them.
            if (raw_len >= 12 and len(slots) == 1 and slots[0][0] == 12 and
                    len(raw_len_bytes(s, blob, slots, 0, 8)) == 8 and
                    not slots[0][2].startswith('.')):
                archive_objs.add(s.name)
                table_targets.add(slots[0][2])
        for s in order:
            slots = slots_by_owner[s.name]
            raw_len = s.size - 4 * len(slots)
            is_archive = s.name in archive_objs
            # SIRO header: "SIRO"/"SIR0" magic + data ptr @+4. Trailing bytes
            # (unused fields, assembler alignment pad absorbed by size
            # inference) are dropped; only magic+ptr+unused words are real.
            magic4 = blob[s.offset:s.offset + 4] if s.size >= 4 else b''
            is_siro = (magic4 in (b'SIRO', b'SIR0') and len(slots) == 1 and
                       slots[0][0] == 4 and raw_len <= 24)
            is_filetable = (s.name in table_targets and len(slots) > 0 and
                            len(slots) % 2 == 0 and raw_len == 0)
            if is_archive:
                kinds[s.name] = 'archive'
            elif s.name in typed:
                kinds[s.name] = 'typed'
            elif is_siro:
                kinds[s.name] = 'siro'
            elif is_filetable:
                kinds[s.name] = 'filetable'
            elif slots and raw_len == 0:
                kinds[s.name] = 'ptrs'
            else:
                kinds[s.name] = 'bytes'

        lines = []
        lines.append(f'/* generated by platform/pc/tools/gen_blobs.py — do not edit */')
        lines.append('#include "global.h"')
        lines.append('#include "structs/str_file_system.h"')
        lines.append('#include "decompress_sir.h"')

        # baserom ROM slices are filled at runtime by rom_load.c. gen_slices.py parsed
        # the .s so each slice carries the exact owning symbol + within-symbol
        # offset (symbol label address can skew from content start, and
        # non-incbin objects can sit between incbins).
        slices = baserom.get(base, [])
        manifest = []  # (cname, off_in_array, rom_off, size)
        writable = set()  # canonical symbol names covered by slices -> writable
        for item in slices:
            rom_off, size, usym, usym_off = item[0], item[1], item[2], item[3]
            # Only writable byte arrays are fill targets (typed objects like
            # SIRO headers are emitted as const C structs; their trailing
            # incbin bytes are alignment pads the game never reads).
            if kinds.get(usym) != 'bytes':
                print(f'gen_blobs: {base}: slice @0x{rom_off:x} owner {usym} '
                      f'is {kinds.get(usym, "?")} — skipped (not a byte array)')
                continue
            if usym in canon:
                cname = names[canon[usym]]
                writable.add(canon[usym])
                manifest.append((cname, usym_off, rom_off, size))
            else:
                print(f'gen_blobs: {base}: slice @0x{rom_off:x} owned by unknown symbol '
                      f'"{usym}" — skipped (array not emitted)')

        for s in order:
            if kinds[s.name] == 'typed':
                for h in typed[s.name].get('headers', []):
                    inc = f'#include "{h}"'
                    if inc not in lines:
                        lines.append(inc)
        lines.append('')
        for s in order:  # forward declarations
            cname = names[canon[s.name]]
            k = kinds[s.name]
            if k == 'archive':
                lines.append(f'extern const FileArchive {cname};')
            elif k == 'typed':
                lines.append(f'extern const {typed[s.name]["ctype"]} {cname}[];')
            elif k == 'siro':
                lines.append(f'extern const SiroArchive {cname};')
            elif k == 'filetable':
                lines.append(f'extern const File {cname}[];')
            elif k == 'ptrs':
                lines.append(f'extern const void *{cname}[];')
            else:
                # byte blobs are writable (runtime ROM-slice fill + reloc patch)
                lines.append(f'extern u8 {cname}[];')
        lines.append('')
        for s in order:
            cname = names[canon[s.name]]
            k = kinds[s.name]
            slots = slots_by_owner[s.name]
            img = bytearray(blob[s.offset:s.offset + s.size])
            for off, _, _ in slots:
                img[off:off + 4] = b'\0\0\0\0'
            raw = raw_len_bytes(s, blob, slots, 0, None)
            if k == 'archive':
                magic = bytes(raw[:8])
                count = int.from_bytes(raw[8:12], 'little', signed=True)
                entries = slots[0][1]
                if entries.startswith('&'):
                    entries = entries[1:]  # File tables decay; &T[] -> (const File *)T
                m_esc = ''.join(f'\\x{b:02x}' for b in magic)
                lines.append(f'const FileArchive {cname} = {{ "{m_esc}", {count}, (const File *){entries} }};')
            elif k == 'siro':
                magic = raw[:4].decode('ascii', 'replace')
                target = slots[0][1]
                u1 = int.from_bytes(raw[4:8], 'little')
                u2 = int.from_bytes(raw[8:12], 'little')
                lines.append(f'const SiroArchive {cname} = {{ "{magic}", {target}, 0x{u1:x}, 0x{u2:x} }};')
            elif k == 'filetable':
                pairs = [f'{{ (char *)({slots[i][1]}), {slots[i+1][1]} }}'
                         for i in range(0, len(slots), 2)]
                lines.append(f'const File {cname}[{len(pairs)}] = {{')
                lines.append('    ' + ',\n    '.join(pairs))
                lines.append('};')
            elif k == 'ptrs':
                refs = ', '.join(expr for _, expr, _ in slots)
                lines.append(f'const void *{cname}[{len(slots)}] = {{ {refs} }};')
            elif k == 'typed':
                t = typed[s.name]
                stride = t['stride']
                if s.size % stride != 0:
                    raise ValueError(f'{base}:{s.name}: size {s.size} not a multiple of stride {stride}')
                count = s.size // stride
                slotmap = {off: expr for off, expr, _ in slots}
                entries = []
                for e in range(count):
                    base_off = e * stride
                    fieldmap = {}
                    for off, expr, _ in slots:
                        if base_off <= off < base_off + stride:
                            fieldmap[off - base_off] = expr
                    img = blob[s.offset + base_off:s.offset + base_off + stride]
                    consumed = set()
                    entry, endpos = _emit_typed_fields(t['fields'], img, 0, fieldmap,
                                                       names, canon, consumed)
                    tailpad = t.get('tailpad', 0)
                    if endpos + tailpad != stride:
                        raise ValueError(f'{base}:{s.name}: fields consume {endpos} (+tailpad {tailpad}) != stride {stride}')
                    extra = set(fieldmap) - consumed
                    if extra:
                        raise ValueError(f'{base}:{s.name}: unconsumed slots {sorted(hex(x) for x in extra)}')
                    entries.append(entry)
                # warn about slots the layout did not consume (shouldn't happen)
                lines.append(f'const {t["ctype"]} {cname}[{count}] = {{')
                lines.append('    ' + ',\n    '.join(entries))
                lines.append('};')
            else:
                # Byte blob: emitted writable so the runtime can fill baserom
                # slices and re-home baked 0x08xxxxxx address words (the GBA
                # ROM window may live somewhere other than 0x08000000).
                # Reloc slots get the target's GBA ROM address written back as
                # a 4-byte value; the runtime relocates them to the mirror.
                img = bytearray(blob[s.offset:s.offset + s.size])
                if _file_base.get(base) is not None:
                    for off, _, t in slots:
                        va = None
                        addend = int.from_bytes(img[off:off + 4], 'little')
                        if t.startswith('.'):
                            basegba = _file_base[base]
                            owner = owner_of(syms, addend)
                            if owner is not None:
                                inner = addend - owner.offset
                                va = _addr_of[canon[owner.name]] + inner
                        elif t in canon:
                            va = _addr_of.get(canon[t]) if canon[t] in _addr_of else None
                            if va is not None:
                                va += addend
                        if va is not None:
                            img[off:off + 4] = va.to_bytes(4, 'little')
                        else:
                            fixups.append(f'{base}:{s.name}+{off:x} -> {t} (zeroed; needs typed port)')
                else:
                    for off, _, t in slots:
                        fixups.append(f'{base}:{s.name}+{off:x} -> {t} (zeroed; no addr anchor)')
                hexbytes = ', '.join(f'0x{b:02x}' for b in img)
                lines.append(f'u8 {cname}[{len(img)}] = {{ {hexbytes} }};')
            lines.append('')
        # aliases
        for s in order:
            for alias in [x.name for x in syms if x.offset == s.offset and x.name != s.name]:
                lines.append(f'#define {alias} {names[canon[s.name]]}')
        out = os.path.join(outdir, f'blobs_{base}.c')
        with open(out, 'w') as f:
            f.write('\n'.join(lines) + '\n')
        print(f'gen_blobs: {base}: {len(order)} objects -> {out}')
        if manifest:
            all_manifest.extend(manifest)
    if all_manifest:
        c_lines = ['/* generated by platform/pc/tools/gen_blobs.py — runtime ROM slices */']
        c_lines.append('#include "global.h"')
        c_lines.append('#include "rom_load.h"')
        for cname in sorted({m[0] for m in all_manifest}):
            c_lines.append(f'extern u8 {cname}[];')
        c_lines.append('const PcRomSlice pcRomSliceTable[] = {')
        for cname, off_in_array, rom_off, size in all_manifest:
            c_lines.append(f'    {{ (u8 *){cname} + 0x{off_in_array:x}, 0x0, 0x{rom_off:x}, 0x{size:x} }},')
        c_lines.append('};')
        c_lines.append(f'const unsigned pcRomSliceCount = {len(all_manifest)};')
        with open(os.path.join(outdir, 'rom_slices_all.c'), 'w') as f:
            f.write('\n'.join(c_lines) + '\n')
        h_lines = ['#ifndef PMDRED_PC_ROM_SLICES_ALL_H']
        h_lines.append('#define PMDRED_PC_ROM_SLICES_ALL_H')
        h_lines.append('#include "rom_load.h"')
        h_lines.append('extern const PcRomSlice pcRomSliceTable[];')
        h_lines.append('extern const unsigned pcRomSliceCount;')
        h_lines.append('#endif')
        with open(os.path.join(outdir, 'rom_slices_all.h'), 'w') as f:
            f.write('\n'.join(h_lines) + '\n')
        print(f'gen_blobs: {len(all_manifest)} baserom slices -> rom_slices_all.c/.h')
    if args.fixup_log and fixups:
        with open(args.fixup_log, 'w') as f:
            f.write('\n'.join(fixups) + '\n')
        print(f'gen_blobs: {len(fixups)} pointer fixups need typed port (see {args.fixup_log})')

def raw_len_bytes(s, blob, slots, start, end):
    """Raw (non-reloc) bytes of a symbol image slice (for shape checks)."""
    img = blob[s.offset:s.offset + s.size]
    out = bytearray()
    pos = 0
    for off, _, _ in sorted(slots, key=lambda x: x[0]):
        out += img[pos:off]
        pos = off + 4
    out += img[pos:]
    if end is not None:
        return bytes(out[start:end])
    return bytes(out[start:])

def refname(target, names, canon):
    if target in canon:
        return names[canon[target]]
    return target  # --extern symbol, keep original name

if __name__ == '__main__':
    main()
