#include "global.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C_1.h"
#include "cpu.h"
#include "crt0.h"
#include "file_system.h"
#include "flash.h"
#include "input.h"
#include "main.h"
#include "random.h"
#include "reg_control.h"
#include "sprite.h"
#include "text1.h"
#include "text2.h"

EWRAM_DATA u8 IntrMain_Buffer[0x120] = {0};
EWRAM_DATA IntrCallback gIntrTable[6] = {0};
EWRAM_DATA IntrCallback gIntrCallbacks[6] = {0};

extern char ewram_start[];
extern char alt_203B038[];
extern char gTitlePaletteFile[];
extern char gUnknown_203BC04[];
extern char iwram_start[];
extern char alt_3001B58[];
extern char unk_code[];
extern char unk_code_ram[];
extern char unk_code_ram_end[];

EWRAM_DATA_2 u8 gInterruptsEnabled = {0};

// data_8270000.s
extern const char gUnknown_8270000[];
// data_80B9BB8.s
extern const u8 gUnknown_80B9BF1[];
extern const IntrCallback gInitialIntrTable[6];

// code_8009804.c
extern void sub_80098A0(void);
// code_2.c
extern void GameLoop(void);
// code_800D090.c
extern void Hang(void);
extern void sub_800D6AC(void);
extern void sub_800D7D0(void);
// music.c
extern void InitMusic(void); // music initializer

void InitIntrTable(const IntrCallback *interrupt_table);
IntrCallback SetInterruptCallback(u32 index, IntrCallback new_callback);

void sub_800B540(void);

void AgbMain(void)
{
    u8 value[4];
    u8 seed[6];

    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_S_1 | WAITCNT_WS0_N_3;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    if (gUnknown_203BC04 - gTitlePaletteFile > 0)
        CpuCopy32(gUnknown_8270000, gTitlePaletteFile, gUnknown_203BC04 - gTitlePaletteFile);

    if (alt_203B038 - ewram_start > 0) {
        memset(value, 0, 4);
        CpuSet(&value, ewram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((alt_203B038 - ewram_start) / 4) & 0x1FFFFF));
    }

    if (unk_code_ram_end - unk_code_ram > 0)
        CpuCopy32(unk_code, unk_code_ram, unk_code_ram_end - unk_code_ram);

    if (alt_3001B58 - iwram_start > 0) {
        memset(value, 0, 4);
        CpuSet(&value, iwram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((alt_3001B58 - iwram_start) / 4) & 0x1FFFFF));
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
    memcpy(seed, gUnknown_80B9BF1, 6);
    SeedRng(seed);
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

void sub_800B540(void)
{
    s32 i;

    for (i = 0; i < 6; i++)
        gIntrCallbacks[i] = NULL;

    nullsub_17();
    InitMusic(); // initialize music and stop DMAs

    while (REG_VCOUNT < 160){}

    REG_IE ^= INTR_FLAG_TIMER3 | INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT; // 0x45

    *(u8*)&REG_DISPCNT |= DISPCNT_FORCED_BLANK; 

    InitIntrTable(gInitialIntrTable); // set up intrrupt vector/table

    REG_TM3CNT = (TIMER_64CLK | TIMER_INTR_ENABLE | TIMER_ENABLE) << 16; 

    REG_IE |= INTR_FLAG_GAMEPAK | INTR_FLAG_TIMER3 | INTR_FLAG_VCOUNT | INTR_FLAG_VBLANK; // 0x2045
    REG_DISPSTAT = DISPSTAT_VCOUNT_INTR | DISPSTAT_VBLANK_INTR;
    gUnknown_203B0AE = -1;
    gUnknown_203B0AC = 0;
    sub_800D6AC(); // Some other IO REG update func
    sub_800D7D0(); // Some other IO REG update func
    gInterruptsEnabled = 1;
    EnableInterrupts();

    while(REG_VCOUNT < 160){}
}

bool8 EnableInterrupts(void)
{
    if (!gInterruptsEnabled)
        return FALSE;

    if (REG_IME & 1)
        return FALSE;

    REG_IME = 1;
    return TRUE;
}

bool8 DisableInterrupts(void)
{
    if (!gInterruptsEnabled)
        return FALSE;

    if (!(REG_IME & 1))
        return FALSE;

    REG_IME = 0;
    return TRUE;
}

bool8 sub_800B650(void)
{
    if (!gInterruptsEnabled)
        return FALSE;

    if (REG_IME & 1)
        return FALSE;

    return TRUE;
}

void AckInterrupt(u16 flag)
{
    if (!gInterruptsEnabled)
        return;

    REG_IME = 0;
    INTR_CHECK |= flag;
    REG_IME = 1;
}

void InitIntrTable(const IntrCallback *interrupt_table)
{
    CpuCopy32(interrupt_table, gIntrTable, sizeof(gIntrTable)); // 0x18 = 0x6 * 4 (0x4F00 is 32 bits)
    CpuCopy32(IntrMain, IntrMain_Buffer, sizeof(IntrMain_Buffer)); // 0x120 = 0x48 * 4 (0x4F00 is 32 bits)
    INTR_VECTOR = IntrMain_Buffer;
}

IntrCallback *GetInterruptHandler(u32 index)
{
    return &gIntrTable[index];
}

IntrCallback SetInterruptCallback(u32 index, IntrCallback new_callback)
{
    IntrCallback old_callback;
    u32 interrupt_var;

    interrupt_var = DisableInterrupts();
    old_callback = gIntrCallbacks[index];
    gIntrCallbacks[index] = new_callback;

    if (interrupt_var)
        EnableInterrupts();

    return old_callback;
}