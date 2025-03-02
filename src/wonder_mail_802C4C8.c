#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "constants/input.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "wonder_mail_802C10C.h"
#include "structs/str_802C39C.h"
#include "structs/str_wonder_mail.h"
#include "text.h"
#include "wonder_mail_802C4C8.h"

static EWRAM_INIT struct unkStruct_203B2E0* gUnknown_203B2E8 = {NULL};
static EWRAM_INIT u16 gUnknown_203B2EC = {0};

#include "data/wonder_mail_802C4C8.h"

static s32 CountAcceptedJobs(void);

static void sub_802C6DC(void);

bool8 sub_802C4C8(s32 a0, DungeonPos *a1, u32 a2)
{
    if (HasNoAcceptedJobs())
        return FALSE;

    gUnknown_203B2E8 = MemoryAlloc(sizeof(struct unkStruct_203B2E0), 8);
    gUnknown_203B2E8->unk8.s0.unk34 = a0;
    gUnknown_203B2E8->unk8.s0.unk38 = &gUnknown_203B2E8->unk8.s0.windows.id[a0];
    RestoreUnkTextStruct_8006518(&gUnknown_203B2E8->unk8.s0.windows);

    gUnknown_203B2E8->unk8.s0.windows.id[gUnknown_203B2E8->unk8.s0.unk34] = sUnknown_80DFCFC;
    gUnknown_203B2E8->unk8.s0.unk38->header = &gUnknown_203B2E8->unk8.unk9C;

    if (a1 != NULL)
        gUnknown_203B2E8->unk8.s0.windows.id[gUnknown_203B2E8->unk8.s0.unk34].pos = *a1;

    sub_8012D34(gUnknown_203B2E8->unk8.s0.unk38, a2);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E8->unk8.s0.windows, TRUE, TRUE);
    sub_8013848(&gUnknown_203B2E8->unk8.s0.input, CountAcceptedJobs(), a2, a0);
    gUnknown_203B2E8->unk8.s0.input.menuIndex = gUnknown_203B2EC;
    sub_8013984(&gUnknown_203B2E8->unk8.s0.input);
    sub_802C6DC();
    DrawJobListMenu();
    return TRUE;
}

u32 sub_802C598(bool8 a0)
{
    if (!a0) {
        sub_8013660(&gUnknown_203B2E8->unk8.s0.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B2E8->unk8.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
    }

    if (sub_80138B8(&gUnknown_203B2E8->unk8.s0.input, 1)) {
        sub_802C6DC();
        DrawJobListMenu();
        return 1;
    }
    return 0;
}

u8 GetPelipperBoardSlotIndex(void)
{
    return gUnknown_203B2E8->pelipperBoardSlots[(gUnknown_203B2E8->unk8.s0.input.unk1E * gUnknown_203B2E8->unk8.s0.input.unk1C) + gUnknown_203B2E8->unk8.s0.input.menuIndex];
}

void sub_802C640(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E8->unk8.s0.windows, FALSE, FALSE);
    gUnknown_203B2E8->unk8.s0.input.unk22 = CountAcceptedJobs();
    sub_8013984(&gUnknown_203B2E8->unk8.s0.input);
    sub_802C6DC();
    DrawJobListMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B2E8->unk8.s0.input);
}

void sub_802C688(void)
{
    if (gUnknown_203B2E8 != NULL) {
        gUnknown_203B2EC = gUnknown_203B2E8->unk8.s0.input.menuIndex;
        gUnknown_203B2E8->unk8.s0.windows.id[gUnknown_203B2E8->unk8.s0.unk34] = sUnknown_80DFCE4;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B2E8->unk8.s0.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B2E8);
        gUnknown_203B2E8 = NULL;
    }
}

static void sub_802C6DC(void)
{
    gUnknown_203B2E8->unk8.unk9C.count = gUnknown_203B2E8->unk8.s0.input.unk20;
    gUnknown_203B2E8->unk8.unk9C.currId = gUnknown_203B2E8->unk8.s0.input.unk1E;
    gUnknown_203B2E8->unk8.unk9C.width = 12;
    gUnknown_203B2E8->unk8.unk9C.f3 = 0;

    SUB_8009614_CALL(gUnknown_203B2E8->unk8.s0);
}

void DrawJobListMenu(void)
{
    WonderMail *mail;
    s32 i;
    s32 r4;
    s32 x;
    unkStruct_802C39C local;

    CallPrepareTextbox_8008C54(gUnknown_203B2E8->unk8.s0.unk34);
    sub_80073B8(gUnknown_203B2E8->unk8.s0.unk34);
    r4 = gUnknown_203B2E8->unk8.s0.input.unk1E * 8;
    x = r4;
    x += 10;
    PrintStringOnWindow(x, 0, sJobList, gUnknown_203B2E8->unk8.s0.unk34, 0);

    r4 += 4;
    x = r4 + (gUnknown_203B2E8->unk8.unk9C.width * 8);
    sub_8012BC4(x, 0, gUnknown_203B2E8->unk8.s0.input.unk1E + 1, 2, 7, gUnknown_203B2E8->unk8.s0.unk34);

    for (i = 0;  i < gUnknown_203B2E8->unk8.s0.input.unk1A; i++) {
        mail = GetJobSlotInfo(gUnknown_203B2E8->pelipperBoardSlots[(gUnknown_203B2E8->unk8.s0.input.unk1E * gUnknown_203B2E8->unk8.s0.input.unk1C) + i]);
        local.unk0[0] = gUnknown_203B2E8->unk8.s0.unk34;
        local.y = GetMenuEntryYCoord(&gUnknown_203B2E8->unk8.s0.input, i);
        sub_803B35C(mail, &local);
        CreateRescueTitle(&local);
    }

    sub_80073E0(gUnknown_203B2E8->unk8.s0.unk34);
}

static s32 CountAcceptedJobs(void)
{
    s32 i;
    s32 sum = 0;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsJobSlotEmpty(i)) {
            gUnknown_203B2E8->pelipperBoardSlots[sum] = i;
            sum++;
        }
    }

    return sum;
}

bool8 HasNoAcceptedJobs(void)
{
    s32 i;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsJobSlotEmpty(i))
            return FALSE;
    }

    return TRUE;
}
