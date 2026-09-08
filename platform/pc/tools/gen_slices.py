#!/usr/bin/env python3
"""platform/pc/tools/gen_slices.py — extract baserom.gba .incbin slices.

For each named data/*.s blob, scan the top-level assembly for
    .incbin "baserom.gba", ROM_OFFSET, SIZE
(in source order, which is also .rodata layout order) and emit a JSON file
mapping blob base -> ordered [[romOffset, size], ...].

Usage:
  python3 platform/pc/tools/gen_slices.py data --out OUT.json base1 base2 ...
"""
import argparse
import json
import os
import re
import sys

PAT = re.compile(r'\.incbin\s+"baserom\.gba"\s*,\s*(0x[0-9A-Fa-f]+)\s*,\s*(0x[0-9A-Fa-f]+)')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('datadir')
    ap.add_argument('--out', required=True)
    ap.add_argument('bases', nargs='+')
    args = ap.parse_args()

    result = {}
    for base in args.bases:
        slices = []
        path = os.path.join(args.datadir, base + '.s')
        if not os.path.isfile(path):
            print(f'gen_slices: WARNING missing {path}', file=sys.stderr)
            continue
        with open(path, encoding='latin-1') as f:
            for line in f:
                m = PAT.search(line)
                if m:
                    slices.append([int(m.group(1), 16), int(m.group(2), 16)])
        result[base] = slices
        print(f'gen_slices: {base}: {len(slices)} baserom slices')

    with open(args.out, 'w') as f:
        json.dump(result, f, indent=1)
    print(f'gen_slices: wrote {args.out}')


if __name__ == '__main__':
    main()