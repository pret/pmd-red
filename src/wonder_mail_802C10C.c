#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "code_80118A4.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "text_1.h"
#include "text_2.h"
#include "wonder_mail_802C10C.h"

static EWRAM_INIT struct unkStruct_203B2E0 *gUnknown_203B2E0 = {NULL};
static EWRAM_INIT u16 gUnknown_203B2E4 = {0};

#include "data/wonder_mail_802C10C.h"

static s32 CountPelipperBoardSlots(void);
static void sub_802C328(void);

bool8 sub_802C10C(s32 a0, DungeonPos *a1, s32 a2)
{
    if (HasNoPelipperBoardJobs())
        return FALSE;

    if (gUnknown_203B2E0 == NULL)
        gUnknown_203B2E0 = MemoryAlloc(sizeof(struct unkStruct_203B2E0), 8);

    gUnknown_203B2E0->unk8.s0.winId = a0;
    gUnknown_203B2E0->unk8.s0.unk38 = &gUnknown_203B2E0->unk8.s0.windows.id[a0];
    RestoreSavedWindows(&gUnknown_203B2E0->unk8.s0.windows);

    gUnknown_203B2E0->unk8.s0.windows.id[gUnknown_203B2E0->unk8.s0.winId] = sUnknown_80DFCB4;
    gUnknown_203B2E0->unk8.s0.unk38->header = &gUnknown_203B2E0->unk8.header;

    if (a1 != NULL)
        gUnknown_203B2E0->unk8.s0.windows.id[gUnknown_203B2E0->unk8.s0.winId].pos = *a1;

    sub_8012D34(gUnknown_203B2E0->unk8.s0.unk38, a2);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E0->unk8.s0.windows, TRUE, TRUE);
    sub_8013848(&gUnknown_203B2E0->unk8.s0.input, CountPelipperBoardSlots(), a2, a0);
    gUnknown_203B2E0->unk8.s0.input.menuIndex = gUnknown_203B2E4;
    sub_8013984(&gUnknown_203B2E0->unk8.s0.input);
    sub_802C328();
    DrawPelipperBoardJobMenu();
    return TRUE;
}

u32 sub_802C1E4(bool8 a0)
{
    if (!a0) {
        sub_8013660(&gUnknown_203B2E0->unk8.s0.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B2E0->unk8.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B2E0->unk8.s0.input, 1)) {
                sub_802C328();
                DrawPelipperBoardJobMenu();
                return 1;
            }
            return 0;
    }
}

u8 sub_802C26C(void)
{
    return gUnknown_203B2E0->pelipperBoardSlots[(gUnknown_203B2E0->unk8.s0.input.unk1E * gUnknown_203B2E0->unk8.s0.input.unk1C) + gUnknown_203B2E0->unk8.s0.input.menuIndex];
}

void sub_802C28C(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E0->unk8.s0.windows, FALSE, FALSE);
    gUnknown_203B2E0->unk8.s0.input.unk22 = CountPelipperBoardSlots();
    sub_8013984(&gUnknown_203B2E0->unk8.s0.input);
    sub_802C328();
    DrawPelipperBoardJobMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B2E0->unk8.s0.input);
}

void sub_802C2D4(void)
{
    if (gUnknown_203B2E0 != NULL) {
        gUnknown_203B2E4 = gUnknown_203B2E0->unk8.s0.input.menuIndex;
        gUnknown_203B2E0->unk8.s0.windows.id[gUnknown_203B2E0->unk8.s0.winId] = sUnknown_80DFC9C;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B2E0->unk8.s0.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B2E0);
        gUnknown_203B2E0 = NULL;
    }
}

static void sub_802C328(void)
{
    gUnknown_203B2E0->unk8.header.count = gUnknown_203B2E0->unk8.s0.input.unk20;
    gUnknown_203B2E0->unk8.header.currId = gUnknown_203B2E0->unk8.s0.input.unk1E;
    gUnknown_203B2E0->unk8.header.width = 12;
    gUnknown_203B2E0->unk8.header.f3 = 0;

    SUB_8009614_CALL(gUnknown_203B2E0->unk8.s0);
}

void DrawPelipperBoardJobMenu(void)
{
    u32 slotIndex;
    WonderMail *mail;
    s32 iVar4;
    s32 x;
    s32 i;
    unkStruct_802C39C local;

    CallPrepareTextbox_8008C54(gUnknown_203B2E0->unk8.s0.winId);
    sub_80073B8(gUnknown_203B2E0->unk8.s0.winId);
    iVar4 = gUnknown_203B2E0->unk8.s0.input.unk1E * 8;
    x = iVar4;
    x += 10;
    PrintStringOnWindow(x, 0, sBulletinBoard, gUnknown_203B2E0->unk8.s0.winId, 0);

    iVar4 += 4;
    x = iVar4 + (gUnknown_203B2E0->unk8.header.width * 8);
    sub_8012BC4(x, 0, gUnknown_203B2E0->unk8.s0.input.unk1E + 1, 2, 7, gUnknown_203B2E0->unk8.s0.winId);

    for (i = 0; i < gUnknown_203B2E0->unk8.s0.input.unk1A; i++) {
        slotIndex = (gUnknown_203B2E0->pelipperBoardSlots[(gUnknown_203B2E0->unk8.s0.input.unk1E * gUnknown_203B2E0->unk8.s0.input.unk1C) + i]);
        mail = GetPelipperBoardSlotInfo(slotIndex);
        local.unk0[0] = gUnknown_203B2E0->unk8.s0.winId;
        local.y = GetMenuEntryYCoord(&gUnknown_203B2E0->unk8.s0.input, i);
        sub_803B35C(mail, &local);

        if (IsMailinJobSlot(GetPelipperBoardSlotInfo(slotIndex)))
            local.unk43 = 2;

        CreateRescueTitle(&local);
    }

    sub_80073E0(gUnknown_203B2E0->unk8.s0.winId);
}

static s32 CountPelipperBoardSlots(void)
{
    s32 i;
    s32 counter = 0;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsPelipperBoardSlotEmpty(i)) {
            gUnknown_203B2E0->pelipperBoardSlots[counter] = i;
            counter++;
        }
    }

    return counter;
}

bool8 HasNoPelipperBoardJobs(void)
{
    s32 i;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsPelipperBoardSlotEmpty(i))
            return FALSE;
    }

    return TRUE;
}
