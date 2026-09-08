# Matching-ROM regression gate (macOS arm64, no brew/sudo)

`make compare` must print `pmd_red.gba: OK`. Verified 2026-09-08 on Apple clang 14.
All third-party payloads live under `build/deps/` (gitignored); nothing needs sudo.

## One-time setup

```sh
# 1. ARM toolchain (binutils+gcc used for as/ld/objcopy/objdump/cpp)
mkdir -p build/deps/src
curl -sL -o build/deps/src/arm-gnu-toolchain.tar.xz \
  https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-darwin-arm64-arm-none-eabi.tar.xz
tar xJf build/deps/src/arm-gnu-toolchain.tar.xz -C build/deps/
export TC=$PWD/build/deps/arm-gnu-toolchain-13.2.Rel1-darwin-arm64-arm-none-eabi/bin

# 2. agbcc (GBA C compiler for MODERN=0 matching build)
git clone --depth 1 https://github.com/pret/agbcc build/deps/src/agbcc
export PATH="$TC:$PATH"
(cd build/deps/src/agbcc && ./build.sh && ./install.sh $PWD/../../..)
# ($PWD there is build/deps/src/agbcc, so ../../.. is the repo root)

# 3. libpng (static, for gbagfx/rsfont) + pkg-config shim
# -> build/deps/prefix (see platform/pc/Makefile.pc `$(LIBPNG_LIB)` rule)
make -f platform/pc/Makefile.pc build/bin/gbagfx   # builds libpng + full gbagfx
export PATH="$PWD/build/bin:$PATH"                  # provides pkg-config shim
```

`tools/agbcc/`, `tools/*/tool-binary`, `build/`, `*.gba/elf/map`, derived assets
(`*.4bpp/*.pmdpal/...`) are all gitignored — the tree stays clean.

## Run the gate

```sh
export PATH="$PWD/build/bin:$PWD/build/deps/arm-gnu-toolchain-13.2.Rel1-darwin-arm64-arm-none-eabi/bin:$PATH"
make -j8 compare   # expect: pmd_red.gba: OK
```

Notes:
- agbcc builds natively on arm64 with Apple clang (no Rosetta needed).
- `make tools` uses `build/bin/pkg-config` (shim serving `build/deps/prefix`).
  With real brew libpng + pkg-config installed, the shim is unnecessary —
  just drop `build/bin` from PATH.
- PC work must never break this gate: `include/gba/*` + `src/cpu.c` changes are
  strict `#ifdef PLATFORM_PC` additions (see `git diff --stat`: insertions only).
