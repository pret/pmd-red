#!/usr/bin/env python3
"""gen_audio.py -- build-time parser: GBA m4a sound sources -> host C data.

Parses the game's own music data (sound/songs/seq_*.s, sound/voicegroups/,
sound/wave/, sound/song_table.inc, MPlayDef.s, VoiceDef.s) and emits a C
file defining gSongTable plus all song/voice/wave tables described in
platform/pc/audio_data.h.

This is the data-ingestion half of native PC audio (chunk 1). The engine
half (m4a_port.c + audio_pc.c, chunk 2) interprets the emitted track byte
streams with GBA-player semantics; see audio_data.h for the binary contract.

Game-code impact: none (new files only). The generated file is gitignored
(build/bin/gen/) like the other blob outputs.

Usage:
    gen_audio.py --root <repo-root> --out <audio_data.c>
"""

import argparse
import os
import re
import sys


class AudioGenError(Exception):
    pass


# --------------------------------------------------------------------------
# Expression evaluator (GAS subset: int arithmetic over .equ constants).
# Values are ints, ('sym', name) for bare-label aliases, or
# ('add', name, offset) for label +/- constant.
# --------------------------------------------------------------------------

_TOKEN_RE = re.compile(
    r'0[xX][0-9a-fA-F]+|\d+|[A-Za-z_][A-Za-z0-9_]*|[+\-*/()]')


def _truncdiv(a, b):
    if b == 0:
        raise AudioGenError('division by zero')
    q = abs(a) // abs(b)
    return -q if (a < 0) != (b < 0) else q


class ExprParser:
    def __init__(self, text, equs, src):
        self.toks = _TOKEN_RE.findall(text)
        # ensure full coverage (catches typos/unsupported syntax early)
        joined = ''.join(self.toks)
        nospace = re.sub(r'\s+', '', text)
        if joined != nospace:
            raise AudioGenError('%s: cannot tokenize %r' % (src, text))
        self.pos = 0
        self.equs = equs
        self.src = src

    def peek(self):
        return self.toks[self.pos] if self.pos < len(self.toks) else None

    def next(self):
        t = self.peek()
        self.pos += 1
        return t

    def parse(self):
        if not self.toks:
            raise AudioGenError('%s: empty expression' % self.src)
        v = self.parse_expr()
        if self.peek() is not None:
            raise AudioGenError('%s: trailing tokens in expression' %
                                self.src)
        return v

    def parse_expr(self):
        v = self.parse_term()
        while self.peek() in ('+', '-'):
            op = self.next()
            rhs = self.parse_term()
            v = self._binop(v, op, rhs)
        return v

    def parse_term(self):
        v = self.parse_factor()
        while self.peek() in ('*', '/'):
            op = self.next()
            rhs = self.parse_factor()
            v = self._binop(v, op, rhs)
        return v

    def parse_factor(self):
        t = self.next()
        if t is None:
            raise AudioGenError('%s: unexpected end of expression' % self.src)
        if t == '(':
            v = self.parse_expr()
            if self.next() != ')':
                raise AudioGenError('%s: missing )' % self.src)
            return v
        if t in ('+', '-'):
            v = self.parse_factor()
            if t == '-':
                v = self._neg(v)
            return v
        if re.match(r'0[xX][0-9a-fA-F]+|\d+$', t):
            return int(t, 0)
        if re.match(r'[A-Za-z_][A-Za-z0-9_]*$', t):
            return self._ident(t)
        raise AudioGenError('%s: bad token %r' % (self.src, t))

    def _ident(self, name):
        # Resolve .equ chains; unresolvable idents are label references.
        seen = set()
        cur = name
        while True:
            if cur in seen:
                raise AudioGenError('%s: equ cycle at %r' % (self.src, cur))
            seen.add(cur)
            if cur not in self.equs:
                return ('sym', cur)
            val = self.equs[cur]
            if isinstance(val, int):
                return val
            if not (isinstance(val, tuple) and val[0] == 'sym'):
                raise AudioGenError('%s: bad equ value %r' % (self.src, val))
            cur = val[1]

    def _neg(self, v):
        if isinstance(v, int):
            return -v
        raise AudioGenError('%s: cannot negate non-constant' % self.src)

    def _binop(self, a, op, b):
        if isinstance(a, int) and isinstance(b, int):
            if op == '+':
                return a + b
            if op == '-':
                return a - b
            if op == '*':
                return a * b
            return _truncdiv(a, b)
        # label +/- constant (assembler address arithmetic)
        if op in ('+', '-') and isinstance(b, int):
            if isinstance(a, tuple) and a[0] == 'sym' and op == '+':
                if b == 0:
                    return a
                return ('add', a[1], b)
            if isinstance(a, tuple) and a[0] == 'add':
                off = a[2] + b if op == '+' else a[2] - b
                return ('sym', a[1]) if off == 0 else ('add', a[1], off)
            if isinstance(a, tuple) and a[0] == 'sym' and op == '-':
                return ('add', a[1], -b)
        raise AudioGenError('%s: illegal operation in expression' % self.src)


def eval_expr(text, equs, src):
    return ExprParser(text, equs, src).parse()


# --------------------------------------------------------------------------
# Source file model: ordered items + label positions.
# --------------------------------------------------------------------------

class AsmFile:
    def __init__(self, path):
        self.path = path
        # items: ('byte', exprstr, line) | ('word', exprstr, line) |
        #        ('hword', exprstr, line) ; labels: name -> item index
        self.items = []
        self.labels = {}

    def src(self, line):
        return '%s:%d' % (self.path, line)


def strip_comment(line):
    return line.split('@', 1)[0].rstrip()


def parse_asm_file(path, equs_global):
    """Parse one .s file. Returns (AsmFile, local_equs dict)."""
    af = AsmFile(path)
    local_equs = {}
    equs = dict(equs_global)
    equs.update(local_equs)  # local equs visible below (updated as we go)
    with open(path, 'r', errors='replace') as f:
        lines = f.read().splitlines()
    for lineno, raw in enumerate(lines, 1):
        line = strip_comment(raw).strip()
        if not line:
            continue
        # label (optionally followed by a directive on the same line)
        m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*):(.*)$', line)
        if m:
            name = m.group(1)
            if name in af.labels:
                raise AudioGenError('%s: duplicate label %r' %
                                    (af.src(lineno), name))
            af.labels[name] = len(af.items)
            line = m.group(2).strip()
            if not line:
                continue
        m = re.match(r'^\.([A-Za-z_][A-Za-z0-9_]*)\b(.*)$', line)
        if not m:
            raise AudioGenError('%s: cannot parse line %r' %
                                (af.src(lineno), raw.strip()))
        d, args = m.group(1), m.group(2).strip()
        if d in ('equ', 'equiv'):
            mm = re.match(r'^([A-Za-z_][A-Za-z0-9_]*)\s*,\s*(.+)$', args)
            if not mm:
                raise AudioGenError('%s: bad .equ %r' %
                                    (af.src(lineno), raw.strip()))
            name, expr = mm.group(1), mm.group(2)
            if name in local_equs:
                raise AudioGenError('%s: duplicate .equ %r' %
                                    (af.src(lineno), name))
            local_equs[name] = eval_expr(expr, equs, af.src(lineno))
            equs[name] = local_equs[name]
        elif d in ('byte', 'word', 'hword', '4byte'):
            kind = 'word' if d == '4byte' else d
            parts = [p.strip() for p in args.split(',')]
            for p in parts:
                if not p:
                    raise AudioGenError('%s: empty operand' % af.src(lineno))
                af.items.append((kind, p, lineno))
        elif d in ('section', 'global', 'globl', 'align', 'end', 'include',
                   'text', 'size', 'comm', 'type'):
            continue  # structural only; no data impact in sound sources
        elif d == 'space':
            raise AudioGenError('%s: unexpected .space in sound data' %
                                af.src(lineno))
        else:
            raise AudioGenError('%s: unsupported directive .%s' %
                                (af.src(lineno), d))
    return af, local_equs


def read_inc_list(path):
    """Return the quoted include paths from a .inc file, in order."""
    out = []
    with open(path, 'r', errors='replace') as f:
        for raw in f.read().splitlines():
            line = strip_comment(raw).strip()
            m = re.match(r'^\.include\s+"([^"]+)"$', line)
            if m:
                out.append(m.group(1))
    return out


# --------------------------------------------------------------------------
# Driver
# --------------------------------------------------------------------------

BASE_EQUS_FILES = ['MPlayDef.s', 'VoiceDef.s']


def load_base_equs(root):
    equs = {}
    for name in BASE_EQUS_FILES:
        af, local = parse_asm_file(os.path.join(root, name), equs)
        if af.items:
            raise AudioGenError('%s: unexpected data items' % af.path)
        equs.update(local)
    return equs


def require_num(value, src):
    if not isinstance(value, int):
        raise AudioGenError('%s: expected numeric constant, got %r' %
                            (src, value))
    return value


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--root', required=True)
    ap.add_argument('--out', required=True)
    args = ap.parse_args()
    root = args.root
    sound = os.path.join(root, 'sound')

    equs = load_base_equs(root)

    # ---- file inventory (include lists are authoritative) ----
    vg_list = read_inc_list(os.path.join(sound, 'voice_groups.inc'))
    wave_list = read_inc_list(os.path.join(sound, 'waves.inc'))
    gbwave_list = read_inc_list(os.path.join(sound, 'gb_waves.inc'))
    if not vg_list or not wave_list or not gbwave_list:
        raise AudioGenError('empty include list; refusing to guess')

    # ---- pass 1: parse everything, collect labels ----
    parsed = {}  # relpath -> (AsmFile, local_equs)

    def get(rel):
        if rel not in parsed:
            full = os.path.join(root, rel)
            if not os.path.isfile(full):
                raise AudioGenError('listed but missing: %s' % rel)
            parsed[rel] = parse_asm_file(full, equs)
        return parsed[rel]

    for rel in vg_list + wave_list + gbwave_list:
        get(rel)
    song_files = sorted(
        f for f in os.listdir(os.path.join(sound, 'songs'))
        if re.match(r'seq_\d+\.s$', f))
    for f in song_files:
        get('sound/songs/' + f)

    # global label registry: label -> relpath
    label_file = {}
    for rel, (af, _local) in parsed.items():
        for name in af.labels:
            if name in label_file:
                raise AudioGenError(
                    'label %r defined in both %s and %s' %
                    (name, label_file[name], rel))
            label_file[name] = rel

    def classify(name):
        if re.match(r'^wave_\d+$', name):
            return 'wave'
        if re.match(r'^gbwave_\d+$', name):
            return 'gbwave'
        if re.match(r'^map_\d+$', name):
            return 'map'
        if re.match(r'^bank_\d+$', name):
            return 'bank'
        if re.match(r'^drums_\d+$', name):
            return 'drums'
        if re.match(r'^seq_\d+$', name):
            return 'song'
        if re.match(r'^seq_\d+_\d+$', name):
            return 'track'
        return None

    for name in label_file:
        if classify(name) is None:
            raise AudioGenError('unclassifiable label %r in %s' %
                                (name, label_file[name]))

    # ---- waves ----
    waves = {}  # name -> dict
    for rel in wave_list:
        af, _local = parsed[rel]
        eq = dict(equs)
        items = af.items
        # expect: hword,hword,word,word,word, then bytes
        kinds = [k for k, _e, _l in items]
        if kinds[:5] != ['hword', 'hword', 'word', 'word', 'word']:
            raise AudioGenError('%s: bad wave header' % af.path)
        if any(k != 'byte' for k in kinds[5:]):
            raise AudioGenError('%s: non-byte wave data' % af.path)
        vals = [require_num(eval_expr(e, eq, af.src(l)), af.src(l))
                for k, e, l in items]
        names = [n for n in af.labels if classify(n) == 'wave']
        if len(names) != 1:
            raise AudioGenError('%s: expected 1 wave label' % af.path)
        data = bytes(v & 0xFF for v in vals[5:])
        waves[names[0]] = {
            'type': vals[0], 'status': vals[1], 'freq': vals[2],
            'loopStart': vals[3], 'loopEnd': vals[4], 'data': data,
            'loop': 1 if ((vals[1] >> 8) & 0xC0) != 0 else 0,
        }
        w = waves[names[0]]
        if not (0 <= w['loopStart'] <= w['loopEnd'] <= len(data)):
            raise AudioGenError(
                '%s: bad loop [%d, %d] for %d samples' %
                (af.path, w['loopStart'], w['loopEnd'], len(data)))

    gbwaves = {}
    for rel in gbwave_list:
        af, _local = parsed[rel]
        eq = dict(equs)
        if any(k != 'byte' for k, _e, _l in af.items):
            raise AudioGenError('%s: non-byte gbwave data' % af.path)
        names = [n for n in af.labels if classify(n) == 'gbwave']
        if len(names) != 1:
            raise AudioGenError('%s: expected 1 gbwave label' % af.path)
        data = bytes(require_num(eval_expr(e, eq, af.src(l)), af.src(l)) & 0xFF
                      for _k, e, l in af.items)
        if len(data) != 16:
            raise AudioGenError('%s: gbwave is %d bytes, want 16' %
                                (af.path, len(data)))
        gbwaves[names[0]] = data

    # ---- voice groups + key maps ----
    KEY_SPLIT = require_num(equs['KeySplit'], 'VoiceDef.s')
    DRUM_TABLE = require_num(equs['DrumTable'], 'VoiceDef.s')

    groups = {}  # name -> list of voice dicts
    keymaps = {}  # name -> bytes

    for rel in vg_list:
        af, local = parsed[rel]
        eq = dict(equs)
        eq.update(local)
        # split items into regions by label: voice region vs map regions
        # region boundaries: sorted label positions
        bounds = sorted(af.labels.values())
        # map label positions -> names
        pos_name = {v: k for k, v in af.labels.items()}

        def region_of(idx):
            # innermost label at or before idx
            best = None
            for b in bounds:
                if b <= idx:
                    best = b
                else:
                    break
            return pos_name[best]

        # voice region = items under a bank_/drums_ label; map regions raw
        voices = None
        vname = None
        # iterate items; group consecutive items by region
        cur_region = None
        cur_items = []
        regions = []

        # seed with label at position 0 if any
        for i, (kind, expr, lineno) in enumerate(af.items):
            r = region_of(i)
            if r != cur_region:
                if cur_region is not None:
                    regions.append((cur_region, cur_items))
                cur_region = r
                cur_items = []
            cur_items.append((kind, expr, lineno))
        if cur_region is not None:
            regions.append((cur_region, cur_items))

        for rname, ritems in regions:
            cls = classify(rname)
            if cls in ('bank', 'drums'):
                if voices is not None:
                    raise AudioGenError(
                        '%s: two voice regions (%s, %s)' %
                        (af.path, vname, rname))
                vname = rname
                voices = parse_voices(af, ritems, eq, KEY_SPLIT, DRUM_TABLE,
                                      label_file, classify)
                groups[vname] = voices
            elif cls == 'map':
                # A map region may start with a trailing bank voice whose
                # label doubles as the map label (e.g. map_003 in
                # bank_026.s: a 12-byte DirectSound voice followed by the
                # actual key bytes). Split it: the voice joins the file's
                # voice array (positional indexing), the rest is the map.
                lead, rest = split_leading_voice(af, ritems, eq, label_file,
                                                 classify)
                if lead is not None:
                    if voices is None:
                        raise AudioGenError(
                            '%s: map %s has leading voice but no voice '
                            'region' % (af.path, rname))
                    voices.append(lead)
                    ritems = rest
                data = bytearray()
                for kind, expr, lineno in ritems:
                    if kind != 'byte':
                        raise AudioGenError(
                            '%s: non-byte map data' % af.src(lineno))
                    v = require_num(eval_expr(expr, eq, af.src(lineno)),
                                    af.src(lineno))
                    if not 0 <= v <= 255:
                        raise AudioGenError('%s: map byte out of range' %
                                            af.src(lineno))
                    data.append(v)
                if rname in keymaps:
                    raise AudioGenError('duplicate map %s' % rname)
                keymaps[rname] = bytes(data)
                if len(data) != 128:
                    sys.stderr.write(
                        'warning: map %s is %d bytes (want 128)\n' %
                        (rname, len(data)))
            else:
                raise AudioGenError('%s: unexpected region %r' %
                                    (af.path, rname))
        if voices is None and vname is None and not any(
                classify(r) == 'map' for r, _i in regions):
            raise AudioGenError('%s: no voice or map region' % af.path)

    # ---- songs ----
    songs = {}  # header label -> parsed song
    for f in song_files:
        rel = 'sound/songs/' + f
        af, local = parsed[rel]
        eq = dict(equs)
        eq.update(local)
        hdr_names = [n for n in af.labels if classify(n) == 'song']
        if len(hdr_names) != 1:
            raise AudioGenError('%s: expected 1 song header' % af.path)
        songs[hdr_names[0]] = parse_song(af, hdr_names[0], eq)

    # ---- song table ----
    table = []  # (label|None, ms, me)
    with open(os.path.join(sound, 'song_table.inc')) as f:
        for raw in f.read().splitlines():
            line = strip_comment(raw).strip()
            m = re.match(r'^song\s+([A-Za-z_][A-Za-z0-9_]*)\s*,'
                         r'\s*(\d+)\s*,\s*(\d+)\s*$', line)
            if m:
                table.append((m.group(1), int(m.group(2)), int(m.group(3))))
    if not table:
        raise AudioGenError('song_table.inc: no entries parsed')
    for label, ms, me in table:
        if not 0 <= ms <= 7:
            raise AudioGenError(
                'song_table entry %r: player %d out of range (want 0-7)' %
                (label, ms))
        if label == 'empty_song':
            continue
        if label not in songs:
            raise AudioGenError('song_table references unknown song %r' %
                                label)
    referenced = set(l for l, _ms, _me in table if l != 'empty_song')
    for name in sorted(songs):
        if name not in referenced:
            sys.stderr.write('warning: %s not referenced by song_table\n'
                             % name)

    # ---- resolve cross-references to indices ----
    wave_index = {n: i for i, n in enumerate(sorted(waves))}
    gbwave_index = {n: i for i, n in enumerate(sorted(gbwaves))}
    group_index = {n: i for i, n in enumerate(sorted(groups))}
    map_index = {n: i for i, n in enumerate(sorted(keymaps))}

    for gname, voices in groups.items():
        for v in voices:
            v['ref'] = resolve_voice_ref(v, wave_index, gbwave_index,
                                         group_index, map_index)

    emit_c(args.out, table, songs, groups, group_index, keymaps, map_index,
           waves, wave_index, gbwaves, gbwave_index)

    # ---- stats ----
    ntracks = sum(len(s['tracks']) for s in songs.values())
    nbytes = sum(len(b) for s in songs.values() for b in s['tracks'].values())
    nvoices = sum(len(v) for v in groups.values())
    sys.stderr.write(
        'audio: %d table entries, %d songs, %d tracks (%d bytes), '
        '%d groups/%d voices, %d maps, %d waves, %d gbwaves\n' %
        (len(table), len(songs), ntracks, nbytes, len(groups), nvoices,
         len(keymaps), len(waves), len(gbwaves)))


def split_leading_voice(af, ritems, eq, label_file, classify):
    """If a map region starts with a full 12-byte voice entry whose word
    resolves to a known wave/bank/drums target, split it off.

    Returns (voice_dict, remaining_items) or (None, ritems) when the
    region is a pure key map.
    """
    # need: byte,byte,byte,byte,word,byte,byte,byte,byte + remainder
    if len(ritems) < 9 + 1:
        return None, ritems
    head, rest = ritems[:9], ritems[9:]
    if (head[0][0] != 'byte' or head[1][0] != 'byte' or
            head[2][0] != 'byte' or head[3][0] != 'byte' or
            head[4][0] != 'word' or head[5][0] != 'byte' or
            head[6][0] != 'byte' or head[7][0] != 'byte' or
            head[8][0] != 'byte'):
        return None, ritems
    try:
        f = [require_num(eval_expr(e, eq, af.src(l)), af.src(l))
             for _k, e, l in head[:4]]
        w = eval_expr(head[4][1], eq, af.src(head[4][2]))
        adsr = [require_num(eval_expr(e, eq, af.src(l)), af.src(l))
                for _k, e, l in head[5:9]]
    except AudioGenError:
        return None, ritems
    if not all(-128 <= v <= 255 for v in f + adsr):
        return None, ritems
    # word must resolve to a known voice target (else: not a voice)
    if isinstance(w, int):
        pass  # duty constant: plausible voice
    elif isinstance(w, tuple) and w[0] == 'sym' and w[1] in label_file:
        if classify(w[1]) not in ('wave', 'gbwave', 'bank', 'drums'):
            return None, ritems
    else:
        return None, ritems
    v = {'type': f[0] & 0xFF, 'key': f[1] & 0xFF, 'p2': f[2] & 0xFF,
         'p3': f[3] & 0xFF, 'w1': w, 'w1src': af.src(head[4][2]),
         'adsr': [a & 0xFF for a in adsr]}
    return v, rest


def parse_voices(af, ritems, eq, KEY_SPLIT, DRUM_TABLE, label_file, classify):
    """Consume a voice region item stream into voice dicts."""
    voices = []
    i = 0
    n = len(ritems)

    def take_byte():
        nonlocal i
        if i >= n:
            raise AudioGenError('%s: truncated voice entry' % af.path)
        kind, expr, lineno = ritems[i]
        i += 1
        if kind != 'byte':
            raise AudioGenError('%s: expected .byte in voice' %
                                af.src(lineno))
        v = require_num(eval_expr(expr, eq, af.src(lineno)), af.src(lineno))
        if not -128 <= v <= 255:
            raise AudioGenError('%s: voice byte out of range' % af.src(lineno))
        return v & 0xFF

    def take_word():
        nonlocal i
        if i >= n:
            raise AudioGenError('%s: truncated voice entry' % af.path)
        kind, expr, lineno = ritems[i]
        i += 1
        if kind != 'word':
            raise AudioGenError('%s: expected .word in voice' %
                                af.src(lineno))
        return eval_expr(expr, eq, af.src(lineno)), af.src(lineno)

    while i < n:
        f0 = take_byte()
        f1 = take_byte()
        f2 = take_byte()
        f3 = take_byte()
        w1, w1src = take_word()
        if f0 == KEY_SPLIT:
            # KeySplit: second word is the 128-byte key map (no ADSR).
            w2, w2src = take_word()
            voices.append({'type': f0, 'key': f1, 'p2': f2, 'p3': f3,
                           'w1': w1, 'w1src': w1src, 'w2': w2,
                           'w2src': w2src})
        else:
            # Normal voice and DrumTable: word + 4 trailing bytes
            # (ADSR, or zero padding for DrumTable).
            adsr = [take_byte(), take_byte(), take_byte(), take_byte()]
            voices.append({'type': f0, 'key': f1, 'p2': f2, 'p3': f3,
                           'w1': w1, 'w1src': w1src, 'adsr': adsr})
    return voices


def resolve_voice_ref(v, wave_index, gbwave_index, group_index, map_index):
    """Map a voice's word operand(s) to (refKind, refA, refB, adsr)."""
    t = v['type']

    def word_target(w, src):
        if isinstance(w, int):
            return ('const', w)
        if isinstance(w, tuple) and w[0] == 'sym':
            return ('sym', w[1])
        raise AudioGenError('%s: bad voice word %r' % (src, w))

    if t == 0x40:  # KeySplit
        k1, n1 = word_target(v['w1'], v['w1src'])
        k2, n2 = word_target(v['w2'], v['w2src'])
        if k1 != 'sym' or n1 not in group_index:
            raise AudioGenError('%s: KeySplit bank %r' % (v['w1src'], v['w1']))
        if k2 != 'sym' or n2 not in map_index:
            raise AudioGenError('%s: KeySplit map %r' % (v['w2src'], v['w2']))
        return (3, group_index[n1], map_index[n2], (0, 0, 0, 0))  # KEYMAP (PC_VOICE_KEYMAP=3)
    if t == 0x80:  # DrumTable
        k1, n1 = word_target(v['w1'], v['w1src'])
        if k1 != 'sym' or n1 not in group_index:
            raise AudioGenError('%s: DrumTable bank %r' %
                                (v['w1src'], v['w1']))
        if tuple(v['adsr']) != (0, 0, 0, 0):
            raise AudioGenError('%s: DrumTable has non-zero tail %r' %
                                (v['w1src'], v['adsr']))
        return (4, group_index[n1], 0, (0, 0, 0, 0))  # DRUMS
    # normal voice: single word = wave | gbwave | duty constant
    k1, n1 = word_target(v['w1'], v['w1src'])
    if k1 == 'const':
        return (2, n1, 0, tuple(v['adsr']))  # DUTY
    if n1 in wave_index:
        return (0, wave_index[n1], 0, tuple(v['adsr']))  # WAVE
    if n1 in gbwave_index:
        return (1, gbwave_index[n1], 0, tuple(v['adsr']))  # GBWAVE (PC_VOICE_GBWAVE=1)
    raise AudioGenError('%s: voice wave %r resolves to nothing' %
                        (v['w1src'], v['w1']))


def parse_song(af, hdr_name, eq):
    """Split a song file into labeled sections; build tracks + header."""
    # sections: label -> list of (kind, expr, lineno)
    order = []
    sections = {}
    # label positions over item indices
    label_pos = sorted(af.labels.values())
    pos_name = {v: k for k, v in af.labels.items()}

    def section_of(idx):
        best = None
        for b in label_pos:
            if b <= idx:
                best = b
            else:
                break
        if best is None:
            raise AudioGenError('%s: data before first label' % af.path)
        return pos_name[best]

    cur = None
    for i, (kind, expr, lineno) in enumerate(af.items):
        s = section_of(i)
        if s != cur:
            cur = s
            order.append(s)
            sections[s] = []
        sections[cur].append((kind, expr, lineno))

    if hdr_name not in sections:
        raise AudioGenError('%s: header section missing' % af.path)

    # absolute bases for fixup arithmetic (tracks laid out back-to-back;
    # only differences within one track are ever used)
    label_abs = {}
    base = 0
    for tname in sorted(n for n in sections if n != hdr_name):
        label_abs[tname] = base
        for kind, _expr, _lineno in sections[tname]:
            if kind == 'byte':
                base += 1
            elif kind == 'word':
                base += 4
            else:
                raise AudioGenError('%s: unexpected .%s in song track' %
                                    (af.path, kind))

    # ---- tracks: byte streams with word fixups ----
    track_streams = {}  # track label -> bytearray
    track_names = sorted(n for n in sections if n != hdr_name)
    for tname in track_names:
        buf = bytearray()
        fixups = []  # (pos, target_label, addend, src)
        for kind, expr, lineno in sections[tname]:
            src = af.src(lineno)
            if kind == 'byte':
                v = require_num(eval_expr(expr, eq, src), src)
                if not -128 <= v <= 255:
                    raise AudioGenError('%s: track byte out of range' % src)
                buf.append(v & 0xFF)
            elif kind == 'word':
                val = eval_expr(expr, eq, src)
                if isinstance(val, int):
                    raise AudioGenError(
                        '%s: numeric .word in track (want label ref)' % src)
                if isinstance(val, tuple) and val[0] == 'sym':
                    target, add = val[1], 0
                elif isinstance(val, tuple) and val[0] == 'add':
                    target, add = val[1], val[2]
                else:
                    raise AudioGenError('%s: bad track word %r' % (src, val))
                fixups.append((len(buf), target, add, src))
                buf.extend(b'\x00\x00\x00\x00')
            elif kind == 'hword':
                raise AudioGenError('%s: unexpected .hword in track' % src)
        # resolve fixups to track-relative offsets
        for pos, target, add, src in fixups:
            if target not in sections or target == hdr_name:
                raise AudioGenError(
                    '%s: word target %r is not a track of this song' %
                    (src, target))
            if target != tname:
                raise AudioGenError(
                    '%s: cross-track word %r (only same-track PATT/GOTO '
                    'supported)' % (src, target))
            # absolute address of target, minus this track's start
            abs_addr = label_abs[target] + add
            rel = abs_addr - label_abs[tname]
            if not 0 <= rel <= len(buf):
                raise AudioGenError(
                    '%s: word target out of track bounds' % src)
            buf[pos:pos + 4] = rel.to_bytes(4, 'little')
        track_streams[tname] = bytes(buf)

    # ---- header ----
    hitems = sections[hdr_name]
    hbytes = []
    hwords = []  # (expr, src)
    for kind, expr, lineno in hitems:
        src = af.src(lineno)
        if kind == 'byte':
            v = require_num(eval_expr(expr, eq, src), src)
            hbytes.append(v & 0xFF)
        elif kind == 'word':
            hwords.append((expr, src))
        else:
            raise AudioGenError('%s: bad header item' % src)
    if len(hbytes) != 4:
        raise AudioGenError('%s: header wants 4 bytes, got %d' %
                            (af.path, len(hbytes)))
    ntrks, nblks, pri, rev = hbytes
    if len(hwords) != 1 + ntrks:
        raise AudioGenError(
            '%s: header wants %d words, got %d' %
            (af.path, 1 + ntrks, len(hwords)))
    tone_expr, tone_src = hwords[0]
    tone_val = eval_expr(tone_expr, eq, tone_src)
    if isinstance(tone_val, tuple) and tone_val[0] == 'sym':
        tone_bank = tone_val[1]
    else:
        raise AudioGenError('%s: bad tone word %r' % (tone_src, tone_val))
    parts = []
    for expr, src in hwords[1:]:
        pv = eval_expr(expr, eq, src)
        if (isinstance(pv, tuple) and pv[0] == 'sym' and pv[1] in sections
                and pv[1] != hdr_name):
            parts.append(pv[1])
        else:
            raise AudioGenError('%s: bad part word %r' % (src, pv))

    return {'tracks': track_streams, 'ntrks': ntrks, 'nblks': nblks,
            'pri': pri, 'rev': rev, 'tone_bank': tone_bank, 'parts': parts}


def emit_c(path, table, songs, groups, group_index, keymaps, map_index,
           waves, wave_index, gbwaves, gbwave_index):
    L = []

    def w(s=''):
        L.append(s)

    w('/* Auto-generated by platform/pc/tools/gen_audio.py — do not edit. */')
    w('/* Native PC-port audio data: songs, voices, waves, song table. */')
    w('#include "audio_data.h"')
    w('#include "gba/m4a_internal.h"')
    w('')
    w('const PcSong *Pc_SongHeader(const void *p) { return (const PcSong *)p; }')
    w('')

    # ---- waves ----
    w('/* ---- waveforms ---- */')
    for name in sorted(waves):
        wd = waves[name]
        w('static const signed char pcWaveData_%s[] = {' % name)
        dump_bytes(L, wd['data'])
        w('};')
    w('static const PcWave pcWaves[] = {')
    for name in sorted(waves):
        wd = waves[name]
        w('    { %d, %d, %du, %du, %du, %du, %d, pcWaveData_%s },' %
          (wd['type'], wd['status'], wd['freq'], wd['loopStart'],
           wd['loopEnd'], len(wd['data']), wd['loop'], name))
    w('};')
    w('const PcWave *Pc_Waves(unsigned int *n)'
      ' { if (n) *n = %d; return pcWaves; }' % len(waves))
    w('')
    for name in sorted(gbwaves):
        w('static const PcGbWave pcGbWave_%s = { { %s } };' %
          (name, ', '.join('%d' % b for b in gbwaves[name])))
    w('static const PcGbWave pcGbWaves[] = {')
    for name in sorted(gbwaves):
        w('    pcGbWave_%s,' % name)
    w('};')
    w('const PcGbWave *Pc_GbWaves(unsigned int *n)'
      ' { if (n) *n = %d; return pcGbWaves; }' % len(gbwaves))
    w('')

    # ---- key maps ----
    w('/* ---- key-split maps ---- */')
    for name in sorted(keymaps):
        w('static const unsigned char pcMap_%s[] = {' % name)
        dump_bytes(L, keymaps[name])
        w('};')
    w('static const PcKeyMap pcKeyMaps[] = {')
    for name in sorted(keymaps):
        w('    { "%s", %d, pcMap_%s },' % (name, len(keymaps[name]), name))
    w('};')
    w('const PcKeyMap *Pc_KeyMaps(unsigned int *n)'
      ' { if (n) *n = %d; return pcKeyMaps; }' % len(keymaps))
    w('')

    # ---- voice groups ----
    w('/* ---- voice groups ---- */')
    for name in sorted(groups):
        w('static const PcVoice pcVoices_%s[] = {' % name)
        for v in groups[name]:
            rk, ra, rb, adsr = v['ref']
            w('    { %d, %d, %d, %d, %d, 0, %d, %d, %d, %d, %d, %d },' %
              (v['type'], v['key'], v['p2'], v['p3'], rk, ra, rb,
               adsr[0], adsr[1], adsr[2], adsr[3]))
        w('};')
    w('static const PcVoiceGroup pcVoiceGroups[] = {')
    for name in sorted(groups):
        w('    { "%s", %d, pcVoices_%s },' % (name, len(groups[name]), name))
    w('};')
    w('const PcVoiceGroup *Pc_VoiceGroups(unsigned int *n)'
      ' { if (n) *n = %d; return pcVoiceGroups; }' % len(groups))
    w('')

    # ---- songs ----
    w('/* ---- songs ---- */')
    for sname in sorted(songs):
        s = songs[sname]
        for tname in sorted(s['tracks']):
            w('static const unsigned char pcTrk_%s[] = {' % tname)
            dump_bytes(L, s['tracks'][tname])
            w('};')
    for sname in sorted(songs):
        s = songs[sname]
        w('static const PcSong pcSong_%s = {' % sname)
        w('    %d, %d, %d, %d, %d, %d, {0, 0},' %
          (s['ntrks'], s['nblks'], s['pri'], s['rev'],
           group_index[s['tone_bank']], len(s['parts'])))
        w('    { %s },' % ', '.join(
            'pcTrk_%s' % t for t in s['parts']))
        w('    { %s },' % ', '.join(
            '%d' % len(s['tracks'][t]) for t in s['parts']))
        w('};')
    w('static const PcSong pcSongs[] = {')
    for sname in sorted(songs):
        w('    pcSong_%s, /* %s */' % (sname, sname))
    w('};')
    song_index = {n: i for i, n in enumerate(sorted(songs))}
    w('const PcSong *Pc_Songs(unsigned int *n)'
      ' { if (n) *n = %d; return pcSongs; }' % len(songs))
    w('')

    # ---- song table (real struct Song: game code reads .ms) ----
    w('/* ---- song table: indices 0..%d ---- */' % (len(table) - 1))
    w('const struct Song gSongTable[] = {')
    for label, ms, me in table:
        if label == 'empty_song':
            w('    { (struct SongHeader *)0, %d, %d },' % (ms, me))
        else:
            w('    { (struct SongHeader *)&pcSong_%s, %d, %d }, /* %s */' %
              (label, ms, me, label))
    w('};')

    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, 'w') as f:
        f.write('\n'.join(L) + '\n')

    # late validation now that indices exist
    for label, ms, me in table:
        if label != 'empty_song' and label not in song_index:
            raise AudioGenError('table song %r has no data' % label)
    for sname, s in songs.items():
        if s['tone_bank'] not in group_index:
            raise AudioGenError('%s: tone bank %r unknown' %
                                (sname, s['tone_bank']))


def dump_bytes(L, data):
    for i in range(0, len(data), 12):
        chunk = data[i:i + 12]
        L.append('    ' + ', '.join('%d' % b for b in chunk) + ',')


if __name__ == '__main__':
    try:
        main()
    except AudioGenError as e:
        sys.stderr.write('gen_audio: error: %s\n' % e)
        sys.exit(1)