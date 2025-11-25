#include "global.h"
#include "globaldata.h"
#include "bg_control.h"
#include "crt0.h"
#include "debug.h"
#include "input.h"
#include "music.h"
#include "reg_control.h"
#include "sprite.h"

extern void (gUnknown_202DBB8)(void);

EWRAM_DATA u8 IntrMain_Buffer[0x120] = {0};
EWRAM_DATA IntrCallback gIntrTable[6] = {0};
EWRAM_DATA IntrCallback gIntrCallbacks[6] = {0};
EWRAM_DATA unkStruct_202D648 gUnknown_202D608[8] = {0};
EWRAM_DATA unkStruct_202D648 gUnknown_202D648[8] = {0};

EWRAM_INIT u8 gInterruptsEnabled = {0};
EWRAM_INIT bool8 gUnknown_203B099 = {0};
EWRAM_INIT bool8 gUnknown_203B09A = {0};
EWRAM_INIT bool8 gUnknown_203B09B = {0};
EWRAM_INIT u32 gUnknown_203B09C = {0};
EWRAM_INIT u32 gUnknown_203B0A0 = {0};
EWRAM_INIT u32 gUnknown_203B0A4 = {0}; // Written to but never read
EWRAM_INIT s16 gUnknown_203B0A8 = {0};
EWRAM_INIT s16 gUnknown_203B0AA = {0};
EWRAM_INIT s16 gUnknown_203B0AC = {0};
EWRAM_INIT s16 gUnknown_203B0AE = {-1};
EWRAM_INIT s16 gUnknown_203B0B0 = {-1}; // Written to but never read
EWRAM_INIT s16 gUnknown_203B0B2 = {-1}; // Written to but never read

// code_800D090.s
extern void sub_800D6AC(void);
extern void sub_800D7D0(void);

static void UpdateBGControlRegisters(void);
static void VBlankIntr(void);
static void VCountIntr(void);
static void UnusedIntrFunc(void);
static void Timer3Intr(void);

static const IntrCallback sInitialIntrTable[6] =
{
    &gUnknown_202DBB8,
    VBlankIntr,
    VCountIntr,
    UnusedIntrFunc,
    Timer3Intr,
    UnusedIntrFunc,
};

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

    InitIntrTable(sInitialIntrTable); // set up intrrupt vector/table

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

UNUSED static bool8 sub_800B650(void)
{
    if (!gInterruptsEnabled)
        return FALSE;

    if (REG_IME & 1)
        return FALSE;

    return TRUE;
}

static void AckInterrupt(u16 flag)
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

UNUSED static s32 sub_800B720(s32 a0, IntrCallback a1)
{
    s32 r2;
    s32 i;
    struct unkStruct_202D648 *strPtr;
    bool8 sp4;
    s32 asS16, asU16;

    asS16 = (s16) a0;
    sp4 = DisableInterrupts();

    while (TRUE) {
        bool8 sp10 = FALSE;
        for (i = 0, strPtr = gUnknown_202D608; i < gUnknown_203B0AA; i++, strPtr++) {
            if (strPtr->unk0 == gUnknown_203B0A8) {
                gUnknown_203B0A8 = (gUnknown_203B0A8 + 1) & 0x7fff;
                sp10 = TRUE;
                break;
            }
        }
        if (!sp10)
            break;
    }

    for (i = 0, strPtr = gUnknown_202D608; i < gUnknown_203B0AA; i++, strPtr++) {
        if (strPtr->unk2 > asS16)
            break;
    }

    for (r2 = gUnknown_203B0AA - 1, strPtr = &gUnknown_202D608[r2]; r2 >= i; r2--, strPtr--) {
        strPtr[1] = strPtr[0];
    }

    gUnknown_203B0AA++;
    gUnknown_202D608[i].unk0 = gUnknown_203B0A8;
    asU16 = (u16) asS16;
    gUnknown_202D608[i].unk2 = asU16;
    gUnknown_202D608[i].unk4 = a1;

    if (sp4)
        EnableInterrupts();

    return gUnknown_203B0A8;
}

UNUSED static void sub_800B850(s16 a0)
{
    s32 r2;
    unkStruct_202D648 *r4;
    bool8 r5;
    s32 r6;

    r6 = a0;
    r5 = DisableInterrupts();

    r2 = 0;
    r4 = &gUnknown_202D608[r2];
    r4++; r4--;
    for (; r2 < gUnknown_203B0AA; r2++, r4++) {
        if (r4->unk0 != r6)
            continue;

        gUnknown_203B0AA--;
        for (; r2 < gUnknown_203B0AA; r2++, r4++)
            r4[0] = r4[1];

        if (!r5)
            return;
        EnableInterrupts();
        return;
    }

    if (r5)
        EnableInterrupts();
}

static void UnusedIntrFunc(void)
{
}

static void VBlankIntr(void)
{
    s32 index;

    gUnknown_203B0A0++;
    SoundVSync();
    BlinkSavingIcon();

    if (gIntrCallbacks[1] != NULL)
        gIntrCallbacks[1]();

    for (index = 0; index < gUnknown_203B0AA; index++)
        gUnknown_202D648[index] = gUnknown_202D608[index];

    gUnknown_203B0AC = gUnknown_203B0AA;
    gUnknown_203B0AE = -1;
    gUnknown_203B0B0 = -1;
    gUnknown_203B0B2 = -1;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR | DISPSTAT_VCOUNT_INTR;

    if (!gUnknown_203B099)
        UpdateSound();

    AckInterrupt(INTR_FLAG_VBLANK);
}

static void VCountIntr(void)
{
    s32 sVar2 = (vs16) REG_VCOUNT;

    if (gUnknown_203B0AE < 0) {
        if (gIntrCallbacks[2] != 0) {
            gIntrCallbacks[2]();
        }
        gUnknown_203B0AE = 0;
    }

    while (gUnknown_203B0AE < gUnknown_203B0AC && gUnknown_202D648[gUnknown_203B0AE].unk2 <= sVar2) {
        if (gUnknown_202D648[gUnknown_203B0AE].unk4 != NULL) {
            gUnknown_202D648[gUnknown_203B0AE].unk4();
        }
        gUnknown_203B0AE++;
    }

    if (gUnknown_203B0AE < gUnknown_203B0AC) {
        REG_DISPSTAT = gUnknown_202D648[gUnknown_203B0AE].unk2 << 8 | DISPSTAT_VBLANK_INTR | DISPSTAT_VCOUNT_INTR;
    }
    AckInterrupt(INTR_FLAG_VCOUNT);
}

// This func waits for vblank and may update sound/input
void sub_800BA5C(void)
{
    if (gUnknown_203B09A) {
        gUnknown_203B09C++;
        xxx_update_bg_sound_input();
    }

    gUnknown_203B09A = TRUE;
    gUnknown_203B09B = FALSE;
    gUnknown_203B09C = 0;
    nullsub_25();

    while (REG_VCOUNT >= 160){}

    gUnknown_203B099 = TRUE;
    VBlankIntrWait();
    nullsub_18();
}

void xxx_update_bg_sound_input(void)
{
    if (gUnknown_203B09B)
        gUnknown_203B09C++;
    else {
        gUnknown_203B09B = TRUE;
        gUnknown_203B09A = FALSE;
        gUnknown_203B09C = 0;
        UpdateBGControlRegisters();

        if (gUnknown_203B099)
            UpdateSound();

        UpdateInput();
        gUnknown_203B099 = FALSE;
        gUnknown_203B0A4 = gUnknown_203B0A0;
    }
}

static void Timer3Intr(void)
{
    if (gIntrCallbacks[4])
        gIntrCallbacks[4]();
    AckInterrupt(INTR_FLAG_TIMER3);
}

UNUSED static u32 sub_800BB34(void)
{
    return gUnknown_203B0A0;
}

UNUSED static void nullsub_178(void)
{
}

UNUSED static void sub_800BB44(void)
{
    u16 ie_store;
    u16 dispcnt_store;
    bool8 interrupt_flag;

    while (REG_KEYINPUT != KEYS_MASK){}

    interrupt_flag = DisableInterrupts();

    while (REG_VCOUNT < 160){}

    dispcnt_store = REG_DISPCNT;
    REG_DISPCNT = DISPCNT_FORCED_BLANK;

    *(vu16 *)BG_PLTT = RGB_WHITE;

    ie_store = REG_IE;
    REG_IE = INTR_FLAG_KEYPAD | INTR_FLAG_GAMEPAK;

    REG_KEYCNT = KEY_AND_INTR | R_BUTTON | L_BUTTON | SELECT_BUTTON; // 0x8304
    REG_IME = 1;

    SoundBiasReset();
    asm("swi 0x3");
    SoundBiasSet();

    REG_IME = 0;
    REG_IE = ie_store;
    REG_KEYCNT = 0;
    REG_DISPCNT = dispcnt_store;
    *(vu16 *)BG_PLTT = RGB_BLACK;

    if (interrupt_flag)
        EnableInterrupts();
    while (REG_KEYINPUT != KEYS_MASK){}
}

void nullsub_17(void)
{
}

static void UpdateBGControlRegisters(void)
{
    u32 BGCNT_Priority[NUM_BGS];

    if (gUnknown_202D7FE == TRUE) {
        BGCNT_Priority[BG0] = BGCNT_PRIORITY(1);
        BGCNT_Priority[BG1] = BGCNT_PRIORITY(2);
        BGCNT_Priority[BG2] = BGCNT_PRIORITY(0);
        BGCNT_Priority[BG3] = BGCNT_PRIORITY(3);
    }
    else {
        BGCNT_Priority[BG0] = BGCNT_PRIORITY(0);
        BGCNT_Priority[BG1] = BGCNT_PRIORITY(1);
        BGCNT_Priority[BG2] = BGCNT_PRIORITY(2);
        BGCNT_Priority[BG3] = BGCNT_PRIORITY(3);
    }

    REG_BG0HOFS = gBG0Control.hofs;
    REG_BG0VOFS = gBG0Control.vofs;
    REG_BG1HOFS = gBG1Control.hofs;
    REG_BG1VOFS = gBG1Control.vofs;
    REG_BG2HOFS = gBG2Control.hofs;
    REG_BG2VOFS = gBG2Control.vofs;
    REG_BG3HOFS = gBG3Control.hofs;
    REG_BG3VOFS = gBG3Control.vofs;

    REG_BG0CNT = BGCNT_Priority[BG0] | BGCNT_SCREENBASE(12) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2C00
    REG_BG1CNT = BGCNT_Priority[BG1] | BGCNT_SCREENBASE(13) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2D00
    if (gBG2Control.unk2 == 0x8000)
        REG_BG2CNT = BGCNT_Priority[BG2] | BGCNT_SCREENBASE(14) | BGCNT_CHARBASE(2) | BGCNT_WRAP; // 0x2E08
    else
        REG_BG2CNT = BGCNT_Priority[BG2] | BGCNT_SCREENBASE(14) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2E00
    REG_BG3CNT = BGCNT_Priority[BG3] | BGCNT_SCREENBASE(15) | BGCNT_CHARBASE(2) | BGCNT_WRAP;
    REG_BLDCNT = gBldCnt;
}
