# `platform/pc` — native PC hardware-abstraction layer (SDL2 target)

Goal: run the decomp's game logic on macOS/Linux/Windows with **zero changes to
`src/`/`include/` game code**. All GBA hardware is emulated behind this directory.

Pixel-perfect first: internal framebuffer stays **240x160**, integer-scaled by SDL
(`SDL_RenderSetLogicalSize(240,160)`). HD/widescreen comes later in `video_pc.c` only.

## Layout

| file | replaces | status |
|---|---|---|
| `gba_shim.h` | `include/gba/{defines,io_reg,syscall}.h` fixed addrs, section attrs, `REG_*` | DONE (header-only, no SDL needed) |
| `cpu_pc.c` / `cpu_pc.h` | `libagbsyscall` `CpuSet/FastSet`, `src/cpu.c` `CpuCopy/Clear/Fill`, LZ/RL/Huff BIOS | TODO (port `tools/gbagfx/{lz,rl,huff}.c`) |
| `video_pc.c` | `DISPCNT/BGCNT/WIN/BLD/VRAM/PLTT/OAM`, `VBlank_CB` commit, `bg_control/sprite/window_buffer/bg_palette_buffer/graphics_memory/dungeon_vram` | TODO (SDL2 compositor) |
| `audio_pc.c` | SDL2 sample renderer (DS wavetable + CGB synth + envelopes) | DONE (push model via `SDL_QueueAudio`, headless no-op without SDL2) |
| `m4a_port.c` / `m4a_port.h` | `src/m4a.c` player logic + `src/m4a_1.s` scheduler/note setup, minus HW | DONE (native C port; game calls `m4aSongNumStart`/`m4aSoundMain` unchanged) |
| `audio_data.h` + `tools/gen_audio.py` | `sound/song_table.inc`, `sound/songs`, `sound/voicegroups`, `sound/wave` | DONE (build-time parse to `build/bin/gen/audio_data.c`: 940-song table + voices/waves) |
| `input_pc.c` | `src/input.c`, `code_800C9CC.c`, KEYCNT sleep loops | TODO (SDL keyboard+pad) |
| `save_pc.c` | `agb_flash*.c`, `flash.c`, `save*.c`, `file_system.c` flash/SRAM side | TODO (host FS, keep GBA save format) |
| `main_pc.c` | `src/crt0.s`, `rom_header.s`, `main.c:AgbMain` boot + `Hang()` | SKETCH (documents init order) |
| `CMakeLists-host.txt` | `Makefile`+`ld_script*.ld`+`tools/agbcc` for host builds | SKETCH (host clang, SDL2) |

## How the shim works (`gba_shim.h`)

Include **before** `global.h` in PC-only translation units (or force via
`-include platform/pc/gba_shim.h -DPLATFORM_PC` in `CMakeLists-host.txt`):

1. **Section attrs → empty.** `EWRAM_DATA/IWRAM_DATA/EWRAM_LIB/EWRAM_INIT/IWRAM_INIT`
   become no-ops (flat address space; `ld_script*.ld` unused on PC).
2. **Fixed addresses → heap buffers.** `VRAM/PLTT/OAM` macros re-point at
   `gPc_Vram/gPc_Pltt/gPc_Oam` (same sizes as `defines.h`: `0x18000/0x400/0x400`).
   `BG_CHAR_ADDR/SCREEN_ADDR/TILE_ADDR/OBJ_VRAM0` derive from the buffer.
3. **Registers → shadow struct.** `REG_DISPCNT/BGxCNT/WININ/WINOUT/BLDCNT/BLDALPHA/WIN0H/...`
   become lvalues in `gPcRegs` so game code compiles; `video_pc.c` reads them each frame.
   Sound/DMA/Timer/Interrupt regs exist as shadows but areoker ignored (mute/noop) until backends land.
4. **BIOS → C functions.** `CpuSet/CpuFastSet` → `memcpy/memset` wrappers honoring
   `CPU_SET_SRC_FIXED`; `VBlankIntrWait` → frame-flag spin; `Sqrt/ArcTan2` → libm.

Game logic keeps writing shadows exactly like hardware; only the commit side
(`VBlank_CB` → `Pc_VBlankCommit()`, `TransferBGPaletteBuffer`, `CopySpritesToOam`)
is reimplemented with SDL.

## Build (host, GBA tree untouched)

```sh
git submodule update --init --recursive   # platform/pc/imgui (Dear ImGui, v1.92.9b)
make -f platform/pc/Makefile.pc pc          # build in build/bin, stage to build/
make -f platform/pc/Makefile.pc run         # + 60-frame smoke -> build/frame.ppm
make -f platform/pc/Makefile.pc pc-syntax   # all 544 src/*.c via preproc pipe (now 544/544)
```

Outputs: `build/bin/pmd-red-pc` (link) + host tools (`build/bin/gbagfx`,
`build/bin/gbagfx-nopng`), staged run-from dir `build/pmd-red-pc` (+ `build/assets/`).
`build/` is gitignored. SDL2 is optional (`sdl2-config` → `-DHAVE_SDL2`, else headless).
libpng auto-builds static into `build/deps/prefix` (no sudo/brew) for full `gbagfx`.

## Milestones

1. Host compiles with shim (errors enumerate remaining HW deps).
2. Boot reaches `GameLoop_Async` (input/timing stubs).
3. Title + ground + dungeon render at 240x160 (video_pc).
4. Save/load round-trips (save_pc).
5. Audio unmuted (audio_pc + m4a_port + gen_audio): BGM/fanfare/SE play the
   game's own song data through SDL2; reverb is an approximation.
