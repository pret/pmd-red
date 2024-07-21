#include "global.h"
#include "bg_control.h"
#include "debug.h"
#include "input.h"
#include "music.h"
#include "reg_control.h"
#include "sprite.h"

EWRAM_DATA unkStruct_202D648 gUnknown_202D608[8] = {0};
EWRAM_DATA unkStruct_202D648 gUnknown_202D648[8] = {0};

EWRAM_DATA_2 bool8 gUnknown_203B099 = {0};
EWRAM_DATA_2 bool8 gUnknown_203B09A = {0};
EWRAM_DATA_2 bool8 gUnknown_203B09B = {0};
EWRAM_DATA_2 u32 gUnknown_203B09C = {0};
EWRAM_DATA_2 u32 gUnknown_203B0A0 = {0};
EWRAM_DATA_2 u32 gUnknown_203B0A4 = {0}; // Written to but never read
EWRAM_DATA_2 s16 gUnknown_203B0A8 = {0};
EWRAM_DATA_2 s16 gUnknown_203B0AA = {0};
EWRAM_DATA_2 s16 gUnknown_203B0AC = {0};
EWRAM_DATA_2 s16 gUnknown_203B0AE = {0};
EWRAM_DATA_2 s16 gUnknown_203B0B0 = {0}; // Written to but never read
EWRAM_DATA_2 s16 gUnknown_203B0B2 = {0}; // Written to but never read

static void UpdateBGControlRegisters(void);

void VBlankIntr(void)
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

    if (gUnknown_203B099 == 0)
        UpdateSound();

    AckInterrupt(INTR_FLAG_VBLANK);
}

void VCountIntr(void)
{
    s32 sVar2 = (s16) REG_VCOUNT;

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

void Timer3Intr(void)
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
