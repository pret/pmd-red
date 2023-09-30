#include "global.h"
#include "code_80118A4.h"
#include "code_803B050.h"
#include "code_80958E8_1.h"
#include "constants/input.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"
#include "wonder_mail_802C10C.h"

static EWRAM_DATA_2 struct unkStruct_203B2E0 *gUnknown_203B2E0 = {0};
static EWRAM_DATA_2 u16 gUnknown_203B2E4 = {0};

#include "data/wonder_mail_802C10C.h"

static s32 CountPelipperBoardSlots(void);

static void sub_802C328(void);

bool8 sub_802C10C(s32 a0, UnkTextStruct2_sub *a1, s32 a2)
{
    if (HasNoPelipperBoardJobs())
        return FALSE;

    if (gUnknown_203B2E0 == NULL)
        gUnknown_203B2E0 = MemoryAlloc(sizeof(struct unkStruct_203B2E0), 8);

    gUnknown_203B2E0->unk3C = a0;
    gUnknown_203B2E0->unk40 = &gUnknown_203B2E0->unk44[a0];
    sub_8006518(gUnknown_203B2E0->unk44);

    gUnknown_203B2E0->unk44[gUnknown_203B2E0->unk3C] = sUnknown_80DFCB4;
    gUnknown_203B2E0->unk40->unk14 = gUnknown_203B2E0->unkA4;

    if (a1 != NULL)
        gUnknown_203B2E0->unk44[gUnknown_203B2E0->unk3C].unk8 = *a1;

    sub_8012D34(gUnknown_203B2E0->unk40, a2);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2E0->unk44, TRUE, TRUE);
    sub_8013848(&gUnknown_203B2E0->input, CountPelipperBoardSlots(), a2, a0);
    gUnknown_203B2E0->input.menuIndex = gUnknown_203B2E4;
    sub_8013984(&gUnknown_203B2E0->input);
    sub_802C328();
    DrawPelipperBoardJobMenu();
    return TRUE;
}

u32 sub_802C1E4(bool8 a0)
{
    if (!a0) {
        sub_8013660(&gUnknown_203B2E0->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B2E0->input)) {
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
            if (sub_80138B8(&gUnknown_203B2E0->input, 1)) {
                sub_802C328();
                DrawPelipperBoardJobMenu();
                return 1;
            }
            return 0;
    }
}

u8 sub_802C26C(void)
{
    return gUnknown_203B2E0->pelipperBoardSlots[(gUnknown_203B2E0->input.unk1E * gUnknown_203B2E0->input.unk1C) + gUnknown_203B2E0->input.menuIndex];
}

void sub_802C28C(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2E0->unk44, FALSE, FALSE);
    gUnknown_203B2E0->input.unk22 = CountPelipperBoardSlots();
    sub_8013984(&gUnknown_203B2E0->input);
    sub_802C328();
    DrawPelipperBoardJobMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B2E0->input);
}

void sub_802C2D4(void)
{
    if (gUnknown_203B2E0 != NULL) {
        gUnknown_203B2E4 = gUnknown_203B2E0->input.menuIndex;
        gUnknown_203B2E0->unk44[gUnknown_203B2E0->unk3C] = sUnknown_80DFC9C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2E0->unk44, TRUE, TRUE);
        MemoryFree(gUnknown_203B2E0);
        gUnknown_203B2E0 = NULL;
    }
}

NAKED
static void sub_802C328(void)
{
    asm_unified(
    "\tpush {r4,lr}\n"
    "\tldr r4, _0802C398\n"
    "\tldr r0, [r4]\n"
    "\tldrh r1, [r0, 0x28]\n"
    "\tadds r0, 0xA4\n"
    "\tmovs r2, 0\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tldrh r1, [r0, 0x26]\n"
    "\tadds r0, 0xA5\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xA6\n"
    "\tmovs r1, 0xC\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xA7\n"
    "\tstrb r2, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tmovs r1, 0x22\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0x18\n"
    "\tbl sub_8009614\n"
    "\tadds r0, 0x2\n"
    "\tlsls r0, 16\n"
    "\tldr r2, [r4]\n"
    "\tldr r3, [r2, 0x3C]\n"
    "\tlsls r1, r3, 1\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r1, r2, r1\n"
    "\tadds r1, 0x52\n"
    "\tasrs r3, r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, [r2, 0x3C]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 3\n"
    "\tadds r2, r0\n"
    "\tadds r3, 0x2\n"
    "\tadds r2, 0x54\n"
    "\tstrh r3, [r2]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x44\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tpop {r4}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_0802C398: .4byte gUnknown_203B2E0");
}

void DrawPelipperBoardJobMenu(void)
{
    u32 slotIndex;
    WonderMail *mail;
    s32 iVar4;
    s32 x;
    s32 i;
    unkStruct_802C39C local;

    sub_8008C54(gUnknown_203B2E0->unk3C);
    sub_80073B8(gUnknown_203B2E0->unk3C);
    iVar4 = gUnknown_203B2E0->input.unk1E * 8;
    x = iVar4;
    x += 10;
    xxx_call_draw_string(x, 0, sBulletinBoard, gUnknown_203B2E0->unk3C, 0);

    iVar4 += 4;
    x = iVar4 + (gUnknown_203B2E0->unkA4[2] * 8);
    sub_8012BC4(x, 0, gUnknown_203B2E0->input.unk1E + 1, 2, 7, gUnknown_203B2E0->unk3C);

    for (i = 0; i < gUnknown_203B2E0->input.unk1A; i++) {
        slotIndex = (gUnknown_203B2E0->pelipperBoardSlots[(gUnknown_203B2E0->input.unk1E * gUnknown_203B2E0->input.unk1C) + i]);
        mail = GetPelipperBoardSlotInfo(slotIndex);
        local.unk0[0] = gUnknown_203B2E0->unk3C;
        local.y = sub_8013800(&gUnknown_203B2E0->input, i);
        sub_803B35C(mail, &local);

        if (IsMailinJobSlot(GetPelipperBoardSlotInfo(slotIndex)))
            local.unk43 = 2;

        CreateRescueTitle(&local);
    }

    sub_80073E0(gUnknown_203B2E0->unk3C);
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