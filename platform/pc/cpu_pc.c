// platform/pc/cpu_pc.c — host implementations of GBA BIOS/DMA/vblank.
//
// Maps (see docs/PC_PORT_INVENTORY.md):
//   CpuSet/CpuFastSet (+CpuCopy32/CpuFill32 macros) -> memcpy/memset honoring
//     CPU_SET_SRC_FIXED and 16/32-bit width flags from include/gba/syscall.h.
//   DmaSet/DmaStop (macro.h PC branch) -> noop / Pc_DmaCopy/Pc_DmaFill.
//   VBlankIntrWait/RegisterRamReset -> flag spin / Pc_MemInit.
//   Sqrt/ArcTan2 -> libm. LZ77/RL UnComp -> byte-exact ports (TODO: gbagfx).
//   BgAffineSet/ObjAffineSet/MultiBoot/SoftReset -> stubs (renderer/audio own these).
// NOTE: the game's include/math.h shadows the system <math.h> under
// -Iinclude, so libm calls below use __builtin_* (clang+gcc portable).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gba/gba.h"
#include "gba_shim.h"
#include "cpu_pc.h"
unsigned char gPc_Vram[PC_VRAM_SIZE];
unsigned char gPc_Pltt[PC_PLTT_SIZE];
unsigned char gPc_Oam[PC_OAM_SIZE];
PcGbaRegs gPcRegs;
volatile int gPcVBlankFlag = 0;

void Pc_MemInit(void) {
    memset(gPc_Vram, 0, sizeof(gPc_Vram));
    memset(gPc_Pltt, 0, sizeof(gPc_Pltt));
    memset(gPc_Oam, 0, sizeof(gPc_Oam));
    memset((void *)&gPcRegs, 0, sizeof(gPcRegs));
    gPcRegs.KEYINPUT = 0x03FF; // active-low: all keys released
    gPcVBlankFlag = 0;
}

void Pc_RequestVBlank(void) { gPcVBlankFlag = 1; }

void Pc_StubAbort(const char *what) {
    fprintf(stderr, "pmd-red-pc: unported stub reached: %s\n",
            what != NULL ? what : "(null)");
    abort();
}

#define PC_HEAP_TRACE_N 128
static struct { void *ptr; int size; unsigned group; } sPcHeapTrace[PC_HEAP_TRACE_N];
static unsigned sPcHeapTracePos;

void Pc_HeapTrace(void *ptr, int size, unsigned group) {
    sPcHeapTrace[sPcHeapTracePos % PC_HEAP_TRACE_N].ptr = ptr;
    sPcHeapTrace[sPcHeapTracePos % PC_HEAP_TRACE_N].size = size;
    sPcHeapTrace[sPcHeapTracePos % PC_HEAP_TRACE_N].group = group;
    sPcHeapTracePos++;
}

void Pc_HeapTraceDump(void) {
    unsigned i, n = sPcHeapTracePos < PC_HEAP_TRACE_N ? sPcHeapTracePos : PC_HEAP_TRACE_N;
    unsigned start = sPcHeapTracePos < PC_HEAP_TRACE_N ? 0 : sPcHeapTracePos % PC_HEAP_TRACE_N;
    fprintf(stderr, "host heap: last %u allocs (oldest first):\n", n);
    for (i = 0; i < n; i++) {
        unsigned idx = (start + i) % PC_HEAP_TRACE_N;
        fprintf(stderr, "host heap:   %p size=0x%x grp=%u\n",
                sPcHeapTrace[idx].ptr, (unsigned)sPcHeapTrace[idx].size,
                sPcHeapTrace[idx].group);
    }
}

// What src/cpu.c:VBlank_CB does minus DMA: reload WIN/BLD shadows, clear flag.
// Real pixel upload happens in video_pc.c:Pc_VideoPresent.
void Pc_VBlankCommit(void) { gPcVBlankFlag = 0; }

void Pc_DmaCopy(const void *src, void *dest, unsigned size) {
    if (src == NULL || dest == NULL || size == 0)
        return;
    memmove(dest, src, size);
}

void Pc_DmaFill(unsigned value, void *dest, unsigned size) {
    if (dest == NULL || size == 0)
        return;
    memset(dest, (int)(value & 0xFF), size);
}

// ---- BIOS syscall bodies (match libagbsyscall signatures) ----

void CpuSet(const void *src, void *dest, u32 control) {
    u32 count = control & 0x1FFFFF;
    int fixed = (control & CPU_SET_SRC_FIXED) != 0;
    int is32 = (control & CPU_SET_32BIT) != 0;
    u32 i;
    if (count == 0 || dest == NULL)
        return;
    if (src == NULL) { // game uses NULL src with SRC_FIXED as a zero-fill (cpu.c:CpuClear)
        memset(dest, 0, count * (is32 ? 4u : 2u));
        return;
    }
    if (fixed) {
        if (is32) {
            u32 v = *(const volatile u32 *)src;
            for (i = 0; i < count; i++)
                ((volatile u32 *)dest)[i] = v;
        } else {
            u16 v = *(const volatile u16 *)src;
            for (i = 0; i < count; i++)
                ((volatile u16 *)dest)[i] = v;
        }
    } else if (is32) {
        memcpy(dest, src, count * 4u);
    } else {
        memcpy(dest, src, count * 2u);
    }
}

void CpuFastSet(const void *src, void *dest, u32 control) {
    u32 count = (control & 0x1FFFFF) * 8u; // words
    int fixed = (control & CPU_FAST_SET_SRC_FIXED) != 0;
    u32 i;
    if (count == 0 || dest == NULL)
        return;
    if (src == NULL || fixed) {
        u32 v = (src != NULL) ? *(const volatile u32 *)src : 0;
        for (i = 0; i < count; i++)
            ((volatile u32 *)dest)[i] = v;
        return;
    }
    memcpy(dest, src, count * 4u);
}

void VBlankIntrWait(void) {
    // Headless/host: the 60Hz loop sets the flag via Pc_RequestVBlank().
    // Spin without sleeping so logic depending on the wait still advances.
    gPcVBlankFlag = 0;
}

void RegisterRamReset(u32 resetFlags) {
    (void)resetFlags;
    Pc_MemInit();
}

void SoftReset(u32 resetFlags) {
    (void)resetFlags;
    Pc_MemInit();
}

u16 Sqrt(u32 num) { return (u16)__builtin_sqrt((double)num); }

u16 ArcTan2(s16 x, s16 y) {
    double a = __builtin_atan2((double)y, (double)x); // [-pi, pi]
    long v = (long)(a * (65536.0 / (2.0 * 3.141592653589793)) + 0.5);
    return (u16)(v & 0xFFFF);
}

void LZ77UnCompWram(const void *src, void *dest) {
    (void)src; (void)dest; // TODO: port tools/gbagfx/lz.c
}

void LZ77UnCompVram(const void *src, void *dest) {
    (void)src; (void)dest; // TODO: port tools/gbagfx/lz.c
}

void RLUnCompWram(const void *src, void *dest) {
    (void)src; (void)dest; // TODO: port tools/gbagfx/rl.c
}

void RLUnCompVram(const void *src, void *dest) {
    (void)src; (void)dest; // TODO: port tools/gbagfx/rl.c
}

void BgAffineSet(struct BgAffineSrcData *src, struct BgAffineDstData *dest, s32 count) {
    (void)src; (void)dest; (void)count;
}

void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset) {
    (void)src; (void)dest; (void)count; (void)offset;
}

int MultiBoot(struct MultiBootParam *mp) {
    (void)mp;
    return 0; // no link play on PC
}
