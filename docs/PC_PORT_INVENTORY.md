# PC-port hardware inventory (generated 2026-09-08, branch `pc-port`)

Source of truth for what `platform/pc/` must replace. Counts via `grep`, not rg.

## 0. Baseline status

- `baserom.gba` SHA1 `9f4cfc5b5f4859d17169a485462e977c7aac2b89` — MATCHES `red.sha1`.
- Toolchain MISSING on this Mac: no `arm-none-eabi-gcc`, no `cmake`, no `brew`, no `tools/agbcc`.
  `make compare` cannot run until INSTALL.md prereqs are installed:
  `xcode-select --install`, Homebrew, `brew install arm-none-eabi-gcc arm-none-eabi-binutils libpng cmake`,
  then `git clone pret/agbcc && ./build.sh && ./install.sh ../pmd-red`.
- Host compiler present: Apple clang 14.0.3, GNU Make 3.81, python3, perl. `platform/pc/` builds with host clang only.

## 1. Direct `REG_*` users (only 11 C files + 3 asm)

| count | file | notes for HAL |
|---:|---|---|
| 70 | `src/m4a.c` | sound FIFO/DMA/timer regs — replace with SDL_Audio backend |
| 45 | `src/reg_control.c` | `VCOUNT/IE/IME/DISPCNT/DISPSTAT/TM3/KEYINPUT/KEYCNT` + ISR install — replace with 60Hz callback |
| 44 | `src/code_800D090.c` | SIO/link + sleep loops (`while(REG_KEYINPUT...)`) — stub no-link |
| 16 | `src/cpu.c` | `VBlank_CB`: kills DMA0, reloads WIN/BLD, HBlank DMA of window table — core frame commit |
| 15 | `src/main.c` | boot HW init (`WAITCNT/WIN/BLD/BGxCNT/DISPCNT`) — replace in `main_pc.c` |
| 12 | `src/agb_flash.c` | `IME/IE/IF/TM/WAITCNT/FLASH_BASE` — stub with host file I/O |
| 5 | `src/libisagbprn.c` | debug print regs — noop on PC |
| 5 | `src/agb_flash_mx.c` | flash variant — stub |
| 1 | `src/code_800C9CC.c` | `REG_KEYINPUT ^ KEYS_MASK` — SDL input |
| 1 | `src/bg_control.c` | `REG_DISPCNT` — tile renderer |
| 1 | `src/agb_flash_1m.c` | flash variant — stub |

`src/m4a_1.s`, `src/arm_funcs.s`, `src/crt0.s` also touch regs (mixer, link, boot).

## 2. `gba/` include coupling

- Only 7 C files directly `#include "gba/..."`: `agb_flash.c/.1m/.mx/.le`, `flash.c`, `m4a.c`, `m4a_tables.c`.
- Everything else gets regs transitively via `include/global.h:10 #include "gba/gba.h"`.
- `include/gba/` = 11 headers: `io_reg.h` (all REG_xxx), `defines.h` (fixed addresses + section attrs),
  `syscall.h` (CpuSet/FastSet/LZ77/Huff/RL/Sqrt/ArcTan/MultiBoot), `m4a_internal.h`, `macro.h`, `types.h`,
  `defines.h`, `flash*.h`, `multiboot.h`, `isagbprint.h`.

## 3. BIOS syscall users (`CpuSet/FastSet/Dma/VBlankIntrWait/LZ77/...`)

15 C files: `bg_palette_buffer.c`, `code_800D090.c`, `code_803DA7C_2.c`, `cpu.c`, `dungeon_map.c`,
`dungeon_pokemon_sprites.c`, `graphics_memory.c`, `m4a.c`, `main.c`, `main_loops.c`, `music.c`,
`pokemon.c`, `reg_control.c`, `sprite.c`, `text_2.c`.
PC mapping: `CpuSet/FastSet/CpuCopy32/CpuFill32 -> memcpy/memset`,
`DmaSet/DmaStop -> memcpy/noop`, `VBlankIntrWait/IntrWait -> SDL vsync`,
`LZ77UnCompWram/Vram, RLUnComp*, HuffUnComp -> port tools/gbagfx/{lz,rl,huff}.c`,
`Sqrt/ArcTan2/Div/Mod -> libm`, `RegisterRamReset/SoftReset -> buffer memset`,
`BgAffineSet/ObjAffineSet -> renderer matrix`, `SoundDriver* -> SDL_Audio`, `MultiBoot -> stub`.

## 4. Fixed-address memory users (`VRAM/PLTT/OAM/SRAM/FLASH/0x04000000...`)

21 C files: `agb_flash*.c`, `bg_palette_buffer.c`, `code_800D090.c`, `code_803DA7C_2.c`,
`dungeon_main.c`, `dungeon_map.c`, `dungeon_name_banner.c`, `dungeon_pokemon_sprites.c`,
`dungeon_tilemap.c`, `dungeon_vram.c`, `friend_areas_map_util.c`, `graphics_memory.c`, `ground_bg.c`,
`main_loops.c`, `pokemon.c`, `reg_control.c`, `sprite.c`, `text_1.c`, `world_map.c`.
Key map (`include/gba/defines.h`): `PLTT 0x5000000/0x400`, `VRAM 0x6000000/0x18000`
(`BG_VRAM 0x10000`, `OBJ_VRAM0 +0x10000/0x8000`, `OBJ_VRAM1 +0x14000/0x4000`),
`OAM 0x7000000/0x400`, `DISPLAY 240x160`, `SOUND_INFO 0x3007FF0`, flash `0x0E000000`.
PC: heap buffers in `platform/pc/gba_shim.h` (`gPc_Vram/gPc_Pltt/gPc_Oam`), same sizes.

## 5. Section attributes (`EWRAM_DATA/IWRAM_DATA/...`)

188 files under `src/`+`include/` use them (`72` C files with `EWRAM_DATA|IWRAM_DATA` alone).
`include/gba/defines.h:9-14`: `IWRAM_DATA/EWRAM_DATA/EWRAM_LIB/EWRAM_INIT/IWRAM_INIT`
= `__attribute__((section(...)))` consumed by `ld_script.ld` (256K EWRAM @0x2000000, 32K IWRAM @0x3000000).
PC: `#define` them empty in shim (all RAM is flat).

## 6. Interrupts / boot

Users: `cpu.c`, `reg_control.c`, `code_800D090.c`, `music.c`, `main.c`, `agb_flash*.c`,
`include/cpu.h`, `include/reg_control.h`.
Sequence: `rom_header.s:Start -> crt0.s:Init (sp_irq/sys stacks, IntrMain demux IE&IF) -> main.c:AgbMain`
(`WAITCNT, DmaStop x4, EWRAM/IWRAM init-copy, WIN/BLD/BGxCNT/DISPCNT=FORCED_BLANK`,
`sub_800B540` installs VBlank/VCount/Timer3 ISRs + `TM3CNT/IE/DISPSTAT/IME`,
`InitFlash/SeedRng/InitSprites/InitInput/InitBGPaletteBuffer/WindowBgBufferInit/InitFileSystem/`
`LoadCharmaps/InitGraphics/SetInterruptCallback(1,VBlank_CB)`, clear blank, `GameLoop_Async()+Hang()`).
Frame pump: `main_loops.c:273 MainLoops_RunFrameActions`
(`CopyWindowBgBuffer, LoadBufferedInputs, CopySpritesToOam, TransferBGPaletteBuffer, ...`).
PC: `platform/pc/main_pc.c` replicates init minus HW, calls pump at 60Hz; `VBlank_CB` becomes
`Pc_VBlankCommit()` (WIN/BLD reload + window-table upload, no DMA).

## 7. Sound

`src/m4a.c`, `src/m4a_1.s` (1656-line mixer `SoundMain/BTM/MPlayMain/CgbSound`),
`src/m4a_tables.c`, `src/music.c`, `src/dungeon_music.c`, `include/m4a.h/music.h`, `sound/` (588 songs).
Stage 1: mute stubs (`m4aSoundInit/Main` noop) so game boots; Stage 2: SDL_Audio sequencer
from `sound/songs/midi/*.mid` + `direct_sound_samples/`.

## 8. Save / filesystem

`src/adventure_save.c`, `src/agb_flash*.c`, `src/flash.c`, `src/file_system.c` (`pksdir0` ROM archive + SIR),
`src/save*.c`, `src/quick_save_*.c`, `src/save_menu.c`.
PC: host file I/O (`~/.pmd-red/save.bin`, extracted `assets/`), keep GBA save format.

## 9. What `platform/pc/` provides (see `platform/pc/README.md`)

`gba_shim.h` (addr/section/REG shadow), `cpu_pc.c` (memcpy syscalls + LZ/RL/Huff ports),
`video_pc.c` (240x160 compositor), `audio_pc.c` (mute-first), `input_pc.c` (SDL keymap),
`save_pc.c` (host FS), `main_pc.c` (boot + 60Hz loop). `CMakeLists-host.txt` builds host clang
without touching `Makefile`/`ld_script*.ld`.
