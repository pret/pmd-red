#!/usr/bin/env python3
"""platform/pc/tools/gen_assets.py — generate every derived GBA asset the host
compile/link needs.

Scans src/ and include/ for INCBIN_*("path") references and, for each missing
derived asset ( *.4bpp/.8bpp/.1bpp from .png, *.pmdpal/.gbapal from .pal ),
runs gbagfx <src> <dst>. Idempotent: already-generated assets are skipped.

Usage:
  python3 platform/pc/tools/gen_assets.py [--gbagfx PATH] [--jobs N]

Run from the repo root. All outputs land in graphics/ and data/ (gitignored
derived files), mirroring what the GBA Makefile's implicit rules produce.
"""
import argparse, glob, os, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor

SRC_FILES = glob.glob('src/**/*', recursive=True) + glob.glob('include/**/*', recursive=True)

# derived extension -> source extension
PAIRS = [('.4bpp', '.png'), ('.8bpp', '.png'), ('.1bpp', '.png'),
         ('.pmdpal', '.pal'), ('.gbapal', '.pal')]

# Match each INCBIN*(...) call and capture EVERY string-literal argument; the
# game uses multi-file concat forms like INCBIN_U8("a.4bpp","b.4bpp",...)
# (e.g. src/dungeon_pokemon_sprites.c sStatusGfx) where every arg is a file.
CALL = re.compile(r'INCBIN(?:_\w+)?\s*\((.*?)\)', re.S)
ARG = re.compile(r'"([^"]+)"')


def collect_refs(text):
    out = set()
    for call in CALL.finditer(text):
        for m in ARG.finditer(call.group(1)):
            out.add(m.group(1))
    return out


def collect_missing():
    refs = set()
    jobs = []
    for f in SRC_FILES:
        if not os.path.isfile(f):
            continue
        try:
            t = open(f, encoding='latin-1').read()
        except Exception:
            continue
        refs |= collect_refs(t)
    for dst in sorted(refs):
        if os.path.exists(dst):
            continue
        src = None
        for d, s in PAIRS:
            if dst.endswith(d):
                cand = dst[:-len(d)] + s
                if os.path.exists(cand):
                    src = cand
                    break
        if src:
            jobs.append((src, dst))
        else:
            sys.stderr.write('no source for: %s\n' % dst)
    return jobs


def run_one(gbagfx, job):
    src, dst = job
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    r = subprocess.run([gbagfx, src, dst])
    return (src, dst, r.returncode)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--gbagfx', default=os.path.join('build', 'bin', 'gbagfx'))
    ap.add_argument('--jobs', type=int, default=1)
    args = ap.parse_args()
    try:
        os.makedirs(os.path.dirname(args.gbagfx), exist_ok=True)
    except Exception:
        pass
    jobs = collect_missing()
    if not jobs:
        print('gen_assets: nothing missing')
        return 0
    print('gen_assets: %d missing assets' % len(jobs))
    failed = 0
    done = 0
    if args.jobs > 1:
        ex = ThreadPoolExecutor(max_workers=args.jobs)
        for src, dst, rc in ex.map(lambda j: run_one(args.gbagfx, j), jobs):
            done += 1
            if rc != 0:
                failed += 1
                sys.stderr.write('FAIL %s <- %s (rc=%d)\n' % (dst, src, rc))
            if done % 500 == 0:
                print('gen_assets: %d/%d ...' % (done, len(jobs)), flush=True)
    else:
        for j in jobs:
            src, dst, rc = run_one(args.gbagfx, j)
            done += 1
            if rc != 0:
                failed += 1
                sys.stderr.write('FAIL %s <- %s (rc=%d)\n' % (dst, src, rc))
            if done % 500 == 0:
                print('gen_assets: %d/%d ...' % (done, len(jobs)), flush=True)
    print('gen_assets: done %d, failed %d' % (done, failed))
    return 1 if failed else 0


if __name__ == '__main__':
    sys.exit(main())
