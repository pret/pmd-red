#include "global.h"
#include "globaldata.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "cpu.h"
#include "crt0.h"
#include "file_system.h"
#include "flash.h"
#include "input.h"
#include "main.h"
#include "music.h"
#include "random.h"
#include "reg_control.h"
#include "sprite.h"
#include "text.h"

extern u8 ewram_start[];
extern u8 ewram_end[]; // Force a second storage in the asm
extern u8 ewram_init_start[];
extern u8 ewram_init_end[];
extern u8 iwram_start[];
extern u8 iwram_end[];
extern u8 iwram_init_start[];
extern u8 iwram_init_end[];

extern const u8 EWRAM_INIT_ROM_START[];
extern const u8 IWRAM_INIT_ROM_START[];

UNUSED static const char sStringRomUserData[] = "PKD ROM USER DATA 000000";

// code_2.c
extern void GameLoop(void);
extern void InitGraphics(void);

extern void Hang(void);

void AgbMain(void)
{
    ALIGNED(4) u8 value[4];

    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_S_1 | WAITCNT_WS0_N_3;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    if (ewram_init_end - ewram_init_start > 0)
        CpuCopy32(EWRAM_INIT_ROM_START, ewram_init_start, ewram_init_end - ewram_init_start);

    if (ewram_end - ewram_start > 0) {
        memset(value, 0, sizeof(value));
        CpuSet(&value, ewram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((ewram_end - ewram_start) / 4) & 0x1FFFFF));
    }

    if (iwram_init_end - iwram_init_start > 0)
        CpuCopy32(IWRAM_INIT_ROM_START, iwram_init_start, iwram_init_end - iwram_init_start);

    if (iwram_end - iwram_start > 0) {
        memset(value, 0, sizeof(value));
        CpuSet(&value, iwram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((iwram_end - iwram_start) / 4) & 0x1FFFFF));
    }

    REG_WIN0H = 0;
    REG_WIN1H = 0;
    REG_WIN0V = 0;
    REG_WIN1V = 0;
    REG_WININ = WININ_WIN0_ALL | WININ_WIN1_ALL; // 16191
    REG_WINOUT = WINOUT_WIN01_BG0 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR; // 61
    gBldCnt = REG_BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD | BLDCNT_TGT2_OBJ; // 15426
    REG_BLDALPHA = BLDALPHA_BLEND(10, 6); // 1546
    gUnknown_202D7FE = FALSE;
    REG_BG0CNT = BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_WRAP | BGCNT_SCREENBASE(12); // 11264
    REG_BG1CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_WRAP | BGCNT_SCREENBASE(13); // 11521
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_WRAP | BGCNT_SCREENBASE(14); // 11786
    REG_BG3CNT = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(2) | BGCNT_WRAP | BGCNT_SCREENBASE(15); // 12043
    REG_DISPCNT = DISPCNT_WIN1_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK; // 32704
    sub_800CDA8(1);
    sub_800B540();
    InitFlash();

{
    u8 seed[] = {0x36, 0x27, 0x46, 0x01, 0xB9, 0x48};
    SeedRng(seed);
}

    InitSprites();
    nullsub_9();
    nullsub_6();
    InitInput();
    InitBGPaletteBuffer();
    sub_80057E8();
    InitFileSystem();
    LoadCharmaps();
    sub_80098A0();
    InitGraphics();
    SetInterruptCallback(1, VBlank_CB);
    REG_DISPCNT = DISPCNT_WIN1_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP; // 32576
    GameLoop();
    Hang();
}
