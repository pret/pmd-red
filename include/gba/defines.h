#ifndef GUARD_GBA_DEFINES
#define GUARD_GBA_DEFINES

#include <stddef.h>

#define TRUE  1
#define FALSE 0

#ifdef PLATFORM_PC
// Native PC port: flat address space, heap-backed video/palette/OAM buffers.
// (See platform/pc/README.md. GBA build is untouched.)
#define IWRAM_DATA
#define EWRAM_DATA
#define EWRAM_LIB // Used only for agb flash and m4a
#define EWRAM_INIT
#define IWRAM_INIT
#else
#define IWRAM_DATA __attribute__((section("iwram_data")))
#define EWRAM_DATA __attribute__((section("ewram_data")))
#define EWRAM_LIB __attribute__((section("ewram_lib"))) // Used only for agb flash and m4a
#define EWRAM_INIT __attribute__((section("ewram_init")))
#define IWRAM_INIT __attribute__((section("iwram_init")))
#endif
#define UNUSED __attribute__((unused))
#define USED __attribute__((used))
#define NAKED __attribute__((naked))
#define NORETURN __attribute__((noreturn))
#define PACKED __attribute__((packed))
#define ALIGNED(n) __attribute__((aligned(n)))
#define ALIGNED_PACKED(n) __attribute__((packed, aligned(n)))

#define SOUND_INFO_PTR (*(struct SoundInfo **)0x3007FF0)
#define INTR_CHECK     (*(u16 *)0x3007FF8)
#define INTR_VECTOR    (*(void **)0x3007FFC)

#ifdef PLATFORM_PC
// Heap-backed shadows owned by platform/pc/cpu_pc.c (same sizes as hardware).
// Pointer expressions (NOT integers): game code does `(u32 *)(VRAM + off)` and
// `(void *)VRAM + off`, which would truncate 64-bit host addresses as numbers.
// The VRAM shadow is 128KB (not 96KB): GBA VRAM mirrors every 128KB, and game
// code relies on it (e.g. font copy to VRAM+0x17e00 of 0x1100 bytes overruns
// 0x18000 into the mirror). VRAM_SIZE stays 0x18000 for logic bounds.
#define PC_VRAM_SIZE 0x20000
#define PC_PLTT_SIZE 0x400
#define PC_OAM_SIZE  0x400
extern unsigned char gPc_Vram[PC_VRAM_SIZE];
extern unsigned char gPc_Pltt[PC_PLTT_SIZE];
extern unsigned char gPc_Oam[PC_OAM_SIZE];

#define PLTT      ((void *)gPc_Pltt)
#define PLTT_SIZE 0x400

#define BG_PLTT      PLTT
#define BG_PLTT_SIZE 0x200

#define OBJ_PLTT      ((void *)(gPc_Pltt + 0x200))
#define OBJ_PLTT_SIZE 0x200

#define VRAM      ((void *)gPc_Vram)
#define VRAM_SIZE 0x18000

#define BG_VRAM           VRAM
#define BG_VRAM_SIZE      0x10000
#define BG_CHAR_SIZE      0x4000
#define BG_SCREEN_SIZE    0x800
#define BG_CHAR_ADDR(n)   ((void *)(gPc_Vram + (BG_CHAR_SIZE * (n))))
#define BG_SCREEN_ADDR(n) ((void *)(gPc_Vram + (BG_SCREEN_SIZE * (n))))
#define BG_TILE_ADDR(n)    ((void *)(gPc_Vram + (0x80 * (n))))

// text-mode BG
#define OBJ_VRAM0      ((void *)(gPc_Vram + 0x10000))
#define OBJ_VRAM0_SIZE 0x8000

// bitmap-mode BG
#define OBJ_VRAM1      ((void *)(gPc_Vram + 0x14000))
#define OBJ_VRAM1_SIZE 0x4000

#define OAM      ((void *)gPc_Oam)
#define OAM_SIZE 0x400
#else
#define PLTT      0x5000000
#define PLTT_SIZE 0x400

#define BG_PLTT      PLTT
#define BG_PLTT_SIZE 0x200

#define OBJ_PLTT      (PLTT + 0x200)
#define OBJ_PLTT_SIZE 0x200

#define VRAM      0x6000000
#define VRAM_SIZE 0x18000

#define BG_VRAM           VRAM
#define BG_VRAM_SIZE      0x10000
#define BG_CHAR_SIZE      0x4000
#define BG_SCREEN_SIZE    0x800
#define BG_CHAR_ADDR(n)   (void *)(BG_VRAM + (BG_CHAR_SIZE * (n)))
#define BG_SCREEN_ADDR(n) (void *)(BG_VRAM + (BG_SCREEN_SIZE * (n)))
#define BG_TILE_ADDR(n)    (void *)(BG_VRAM + (0x80 * (n)))

// text-mode BG
#define OBJ_VRAM0      (void *)(VRAM + 0x10000)
#define OBJ_VRAM0_SIZE 0x8000

// bitmap-mode BG
#define OBJ_VRAM1      (void *)(VRAM + 0x14000)
#define OBJ_VRAM1_SIZE 0x4000

#define OAM      0x7000000
#define OAM_SIZE 0x400
#endif

#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 160

#define TILE_SIZE_4BPP 32
#define TILE_SIZE_8BPP 64

#define TOTAL_OBJ_TILE_COUNT 1024

// 32 bit RGB color
#define RGB_U32(r, g, b) (((r) << 16) | ((g) << 8) | (b))
#define RGB(r, g, b) ((r) | ((g) << 5) | ((b) << 10))
#define RGB2(r, g, b) (((b) << 10) | ((g) << 5) | (r))

#define RGB_BLACK RGB(0, 0, 0)
#define RGB_WHITE RGB(31, 31, 31)

#define WIN_RANGE(a, b) (((a) << 8) | (b))

#endif // GUARD_GBA_DEFINES
