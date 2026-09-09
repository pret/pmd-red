#!/usr/bin/env python3
"""platform/pc/tools/gen_slices.py — extract baserom.gba .incbin slices.

Parses each named data/*.s blob (a tiny subset of GNU as) so every
    .incbin "baserom.gba", ROM_OFFSET, SIZE
is associated with the symbol that owns it and its byte offset within that
symbol. That (not section-offset heuristics) is what gen_blobs.py uses to fill
the runtime arrays, since a symbol's GBA label can sit before its content and
non-incbin objects (.4byte/.string tables) can sit between incbins.

Emitted JSON: { base: [ [romOff, size, "symbol", withinOffset], ... ] }
"""
import argparse
import json
import os
import re
import sys

INCBIN = re.compile(r'\.incbin\s+"baserom\.gba"\s*,\s*(0x[0-9A-Fa-f]+)\s*,\s*(0x[0-9A-Fa-f]+)')
LABEL = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)\s*:')
DIR = re.compile(r'^\.([A-Za-z0-9_]+)\s*(.*)$')


def strip_comment(line):
    # ARM comments start with '@'; keep '@' inside string literals.
    out = []
    in_str = False
    i = 0
    while i < len(line):
        c = line[i]
        if c == '"':
            in_str = not in_str
            out.append(c)
        elif c == '@' and not in_str:
            break
        else:
            out.append(c)
        i += 1
    return ''.join(out)


def parse_operands(text):
    """Split comma-separated operands (ignoring quotes/comments)."""
    parts = []
    cur = []
    in_str = False
    for c in text:
        if c == '"':
            in_str = not in_str
            cur.append(c)
        elif c == ',' and not in_str:
            parts.append(''.join(cur).strip())
            cur = []
        else:
            cur.append(c)
    if cur:
        parts.append(''.join(cur).strip())
    return parts


class MiniAsm:
    def __init__(self):
        self.sym = None
        self.off = 0
        self.shown = set()

    def _mark_label(self, m):
        self.sym = m.group(1)
        self.off = 0

    def _emit(self, n):
        self.off += n

    def _align(self, n_bytes):
        self.off = (self.off + n_bytes - 1) // n_bytes * n_bytes

    def handle(self, body, slices):
        m = LABEL.match(body)
        if m:
            self._mark_label(m)
            return
        m = DIR.match(body)
        if not m:
            return
        name, rest = m.group(1), m.group(2)
        ops = parse_operands(strip_comment(rest))
        if name == 'global':
            return
        if name in ('align', 'balign'):
            n = int(ops[0], 0) if ops else 2
            if name == 'balign':
                n = max(n, 1)
            else:
                n = 1 << n  # GNU as: .align N = 2^N bytes
            if self.sym is not None:
                self._align(max(n, 1))
            return
        if name == 'p2align':
            n = (1 << int(ops[0], 0)) if ops else 4
            if self.sym is not None:
                self._align(n)
            return
        if name in ('incbin',):
            mi = INCBIN.search(body)
            if mi:
                roff, size = int(mi.group(1), 16), int(mi.group(2), 16)
                sym = self.sym
                if sym is None:
                    sym = '?'
                slices.append([roff, size, sym, self.off])
                self._emit(size)
                self.shown.add(sym)
            return
        if name == 'byte':
            self._emit(len(ops))
            return
        if name in ('2byte', 'hword', 'short'):
            self._emit(2 * len(ops))
            return
        if name in ('4byte', 'word', 'long', 'int'):
            self._emit(4 * len(ops))
            return
        if name == '8byte':
            self._emit(8 * len(ops))
            return
        if name in ('string', 'ascii', 'asciz', 'string8'):
            # approximate string byte count (ignore escapes/lengths prefixes)
            s = ops[0] if ops else ''
            # ops splitting already kept quotes; recompute literal length
            inner = []
            ins = False
            for c in rest:
                if c == '"':
                    ins = not ins
                elif ins:
                    inner.append(c)
            s2 = ''.join(inner)
            if name in ('string', 'asciz'):
                s2 += '\0'
            self._emit(len(s2.encode('utf-8')))
            return
        if name in ('space', 'skip', 'zero'):
            n = int(ops[0].strip('"').strip(), 0) if ops else 0
            self._emit(n)
            return
        # unknown directives: ignore (data only)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('datadir')
    ap.add_argument('--out', required=True)
    ap.add_argument('bases', nargs='+')
    args = ap.parse_args()

    result = {}
    for base in args.bases:
        path = os.path.join(args.datadir, base + '.s')
        if not os.path.isfile(path):
            print(f'gen_slices: WARNING missing {path}', file=sys.stderr)
            continue
        slices = []
        asm = MiniAsm()
        with open(path, encoding='latin-1') as f:
            for raw in f:
                body = strip_comment(raw).strip()
                if not body:
                    continue
                asm.handle(body, slices)
        result[base] = slices
        print(f'gen_slices: {base}: {len(slices)} baserom slices')

    with open(args.out, 'w') as f:
        json.dump(result, f)
    print(f'gen_slices: wrote {args.out}')


if __name__ == '__main__':
    main()