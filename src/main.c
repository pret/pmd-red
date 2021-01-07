#include "global.h"
#include "crt0.h"
#include "random.h"
#include "flash.h"
#include "text.h"

extern char ewram_start[];

typedef void (*IntrCallback)(void);

extern u8 IntrMain_Buffer[0x120];
extern IntrCallback gUnknown_202D5F0[6];
extern u16 gUnknown_202D7FC;
extern u8 gUnknown_202D7FE;
extern u8 gInterruptsEnabled;
extern u16 gUnknown_203B0AC;
extern s16 gUnknown_203B0AE;
extern u32 gIntrTable[];


extern char alt_203B038[];

extern char gTitlePaletteFile[];
extern char gUnknown_203BC04[];

extern char iwram_start[];

extern char alt_3001B58[];

extern char unk_code_ram[];
extern char unk_code_ram_end[];

extern u8 gUnknown_80B9BF1[];
extern u32 gUnknown_80B9C00;

extern char gUnknown_8270000[];

extern char unk_code[];

extern void sub_800CDA8(int);
extern void sub_800B540(void);
extern void InitSprites(void);
extern void nullsub_9(void);
extern void nullsub_6(void);
extern void InitInput(void);
extern void InitBGPaletteBuffer(void);
extern void sub_80057E8(void);
extern void InitFileSystem(void);
extern void sub_80098A0(void);
extern void InitGraphics(void);
extern void GameLoop(void);
extern void Hang(void);
extern void sub_800CE54(void);

extern void nullsub_17(void);
extern void sub_800BD08(void); // music initializer
extern void sub_800D6AC(void);
extern void sub_800D7D0(void);

bool8 EnableInterrupts(void);
void InitIntrTable(const u32 *interrupt_table);
void *sub_800B6F4(u32 index, void * new_callback);


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

    if (alt_203B038 - ewram_start > 0)
    {
        memset(value, 0, 4);
        CpuSet(&value, ewram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((alt_203B038 - ewram_start) / 4) & 0x1FFFFF));
    }

    if (unk_code_ram_end - unk_code_ram > 0)
        CpuCopy32(unk_code, unk_code_ram, unk_code_ram_end - unk_code_ram);

    if (alt_3001B58 - iwram_start > 0)
    {
        memset(value, 0, 4);
        CpuSet(&value, iwram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((alt_3001B58 - iwram_start) / 4) & 0x1FFFFF));
    }

    REG_WIN0H = 0;
    REG_WIN1H = 0;
    REG_WIN0V = 0;
    REG_WIN1V = 0;
    REG_WININ = WININ_WIN0_ALL | WININ_WIN1_ALL; // 16191
    REG_WINOUT = WINOUT_WIN01_BG0 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR; // 61
    gUnknown_202D7FC = REG_BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD | BLDCNT_TGT2_OBJ; // 15426
    REG_BLDALPHA = BLDALPHA_BLEND(10, 6); // 1546
    gUnknown_202D7FE = 0;
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
    sub_800B6F4(1, sub_800CE54);
    REG_DISPCNT = DISPCNT_WIN1_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP; // 32576
    GameLoop();
    Hang();
}

void sub_800B540(void)
{
    s32 i;
    for (i = 0; i < 6; i++) {
        gUnknown_202D5F0[i] = NULL;
    }

    nullsub_17();
    sub_800BD08(); // initialize music and stop DMAs

    while(REG_VCOUNT <= 159){}

    REG_IE ^= INTR_FLAG_TIMER3 | INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT; // 0x45

    *(u8*)&REG_DISPCNT |= DISPCNT_FORCED_BLANK; 

    InitIntrTable(&gUnknown_80B9C00); // set up intrrupt vector/table

    REG_TM3CNT = (TIMER_64CLK | TIMER_INTR_ENABLE | TIMER_ENABLE) << 16; 

    REG_IE |= INTR_FLAG_GAMEPAK | INTR_FLAG_TIMER3 | INTR_FLAG_VCOUNT | INTR_FLAG_VBLANK; // 0x2045
    REG_DISPSTAT = DISPSTAT_VCOUNT_INTR | DISPSTAT_VBLANK_INTR;
    gUnknown_203B0AE = -1;
    gUnknown_203B0AC = 0;
    sub_800D6AC(); // Some other IO REG update func
    sub_800D7D0(); // Some other IO REG update func
    gInterruptsEnabled = 1;
    EnableInterrupts();

    while(REG_VCOUNT <= 159){}
}

bool8 EnableInterrupts(void)
{
    if(!gInterruptsEnabled)
    {
        return FALSE;
    }

    if(REG_IME & 1)
    {
        return FALSE;
    }
    else
    {
        REG_IME = 1;
        return TRUE;
    }
}

bool8 DisableInterrupts(void)
{
    if(!gInterruptsEnabled)
    {
        return FALSE;
    }

    if(!(REG_IME & 1))
    {
        return FALSE;
    }
    else
    {
        REG_IME = 0;
        return TRUE;
    }

}

bool8 sub_800B650(void)
{
    if(!gInterruptsEnabled)
    {
        return FALSE;
    }

    if(REG_IME & 1)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void SetInterruptFlag(u16 flag)
{
    if(!gInterruptsEnabled)
    {
        return;
    }

    REG_IME = 0;
    INTR_CHECK |= flag;
    REG_IME = 1;
}

void InitIntrTable(const u32 *interrupt_table)
{
    CpuCopy32(interrupt_table, &gIntrTable, 0x18); // 0x18 = 0x6 * 4 (0x4f00 is 32 bits)
    CpuCopy32(&IntrMain, &IntrMain_Buffer, 0x120); // 0x120 = 0x48 * 4 (0x4f00 is 32 bits)
    INTR_VECTOR = &IntrMain_Buffer;
}

u32 *sub_800B6E8(u32 r0)
{
    return &gIntrTable[r0];
}

void *sub_800B6F4(u32 index, void * new_callback)
{
    void *old_callback;
    u32 interrupt_var;

    interrupt_var = DisableInterrupts();
    old_callback = gUnknown_202D5F0[index];
    gUnknown_202D5F0[index] = new_callback;
    if(interrupt_var){
        EnableInterrupts();
    }
    return old_callback;
}

