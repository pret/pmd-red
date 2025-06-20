#include "global.h"
#include "bg_control.h"
#include "code_800558C.h"
#include "cpu.h"

EWRAM_DATA u32 gUnknown_202D800 = {0};

EWRAM_INIT u16 gRawKeyInput = {0}; // Not used here, but has to be declare along with sBldCntTable for alignment. Perhaps this file should be merged with bg_control and code_800C9CC.
// Despite being in EWRAM, these never change.
static EWRAM_INIT u16 sBldCntTable[] = {
    (BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD),
    (BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD),
    (BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD),
    (BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD),
    (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD),
    (BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD),
    (0),
};

void sub_800CDA8(u32 r0)
{
    gUnknown_202D800 = r0;
    gBldCnt = sBldCntTable[r0];
}

u32 sub_800CDC8(void)
{
    return gUnknown_202D800;
}

// arm9.bin::02007FF4
void SetWindowTitle(const u8 *title)
{
}

void nullsub_23(bool8 a0)
{
}

UNUSED static void nullsub_182(void)
{
}

UNUSED static bool8 sub_800CDE0(void)
{
    return TRUE;
}

// In NDS, this func is copied to 01FF9FC4
void CpuCopy(void *dest, const void *src, s32 size)
{
    CpuCopy32(src, dest, size);
}

// In NDS, this func is copied to 01FF9FB0
void CpuClear(void *dest, s32 size)
{
    CpuFill32(NULL, dest, size);
}

void CpuFill(void *dest, void *value, s32 size)
{
    CpuFill32(value, dest, size);
}

void VBlank_CB(void)
{
    // Looks like a macro?
    u16 cnt = REG_DMA0CNT_H;
    cnt |= DMA_ENABLE;
    cnt &= ~(DMA_START_HBLANK | DMA_START_VBLANK | DMA_REPEAT);
    REG_DMA0CNT_H = cnt;
    asm("mov \tr8, r8");
    asm("mov \tr8, r8");
    asm("mov \tr8, r8");
    asm("mov \tr8, r8");
    REG_DMA0CNT_H = cnt & ~(DMA_ENABLE);

    REG_WININ = WININ_WIN0_ALL | WININ_WIN1_ALL;
    REG_WINOUT = WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WIN01_BG3 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG0;
    REG_BLDCNT = gBldCnt;
    REG_BLDALPHA = gBldAlpha;
    if (gUnknown_2026E38) {
        // Very interesting use of DmaCopy16 here.
        DmaSet(0, &gUnknown_2026E3C[2], REG_ADDR_WIN0H, ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_SRC_INC | DMA_DEST_RELOAD | DMA_16BIT) << 16) | 2);
        REG_WIN0H = gUnknown_2026E3C[0];
        REG_WIN1H = gUnknown_2026E3C[1];
        REG_WIN0V = DISPLAY_HEIGHT;
        REG_WIN1V = DISPLAY_HEIGHT;
    }
    else {
        REG_WIN0H = 0;
        REG_WIN1H = 0;
        REG_WIN0V = 0;
        REG_WIN1V = 0;
    }
}
