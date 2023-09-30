#include "global.h"
#include "code_80118A4.h"
#include "code_803B050.h"
#include "constants/input.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "structs/str_802C39C.h"
#include "structs/str_wonder_mail.h"
#include "text1.h"
#include "text2.h"
#include "wonder_mail_802CDD4.h"

static EWRAM_DATA_2 unkStruct_203B2F4 *sUnknown_203B2F4 = {0};

#include "data/wonder_mail_802CDD4.h"

static void sub_802CF5C(void);

bool8 sub_802CDD4(u32 a0)
{
    if (sUnknown_203B2F4 == NULL)
        sUnknown_203B2F4 = MemoryAlloc(sizeof(unkStruct_203B2F4), 8);

    sUnknown_203B2F4->unk34 = a0;
    sUnknown_203B2F4->unk38 = &sUnknown_203B2F4->unk3C[sUnknown_203B2F4->unk34];
    sub_8006518(sUnknown_203B2F4->unk3C);
    sUnknown_203B2F4->unk3C[sUnknown_203B2F4->unk34] = sUnknown_80DFDA4;
    sUnknown_203B2F4->unk38->unk14 = sUnknown_203B2F4->unk9C;
    sub_8012D34(sUnknown_203B2F4->unk38, 4);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2F4->unk3C, TRUE, TRUE);
    sub_8013848(&sUnknown_203B2F4->input, 5, 4, a0);
    sub_802CF5C();
    sub_802CFD0();
    return TRUE;
}

u32 sub_802CE5C(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2F4->input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2F4->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            return 3;
        default:
            if (sub_80138B8(&sUnknown_203B2F4->input, TRUE)) {
                sub_802CF5C();
                sub_802CFD0();
                return 1;
            }
            return 0;
    }
}

u8 sub_802CEBC(void)
{
    return (sUnknown_203B2F4->input.unk1E * sUnknown_203B2F4->input.unk1C) + sUnknown_203B2F4->input.menuIndex;
}

void sub_802CED8(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2F4->unk3C, FALSE, FALSE);
    sub_8013984(&sUnknown_203B2F4->input);
    sub_802CF5C();
    sub_802CFD0();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2F4->input);
}

void sub_802CF14(void)
{
    if (sUnknown_203B2F4 != NULL) {
        sUnknown_203B2F4->unk3C[sUnknown_203B2F4->unk34] = sUnknown_80DFD8C;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B2F4->unk3C, TRUE, TRUE);
        MemoryFree(sUnknown_203B2F4);
        sUnknown_203B2F4 = NULL;
    }
}

NAKED
static void sub_802CF5C(void)
{
    asm_unified(
    "\tpush {r4,lr}\n"
    "\tldr r4, _0802CFCC\n"
    "\tldr r0, [r4]\n"
    "\tldrh r1, [r0, 0x20]\n"
    "\tadds r0, 0x9C\n"
    "\tmovs r2, 0\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tldrh r1, [r0, 0x1E]\n"
    "\tadds r0, 0x9D\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x9E\n"
    "\tmovs r1, 0xC\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x9F\n"
    "\tstrb r2, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tmovs r1, 0x1A\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0x18\n"
    "\tbl sub_8009614\n"
    "\tadds r0, 0x2\n"
    "\tlsls r0, 16\n"
    "\tldr r2, [r4]\n"
    "\tldr r3, [r2, 0x34]\n"
    "\tlsls r1, r3, 1\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r1, r2, r1\n"
    "\tadds r1, 0x4A\n"
    "\tasrs r3, r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, [r2, 0x34]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 3\n"
    "\tadds r2, r0\n"
    "\tadds r3, 0x2\n"
    "\tadds r2, 0x4C\n"
    "\tstrh r3, [r2]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x3C\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tpop {r4}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_0802CFCC: .4byte sUnknown_203B2F4");
}

void sub_802CFD0(void)
{
    unkStruct_802C39C local;
    unkStruct_803B344 *iVar1;
    s32 r5;
    s32 r4;

    sub_8008C54(sUnknown_203B2F4->unk34);
    sub_80073B8(sUnknown_203B2F4->unk34);

    r5 = r4 = (sUnknown_203B2F4->input.unk1E * 8) + 10;
    xxx_call_draw_string(r5, 0, sRescueEvent, sUnknown_203B2F4->unk34, 0);

    r4 -= 6;
    r5 = r4 + (sUnknown_203B2F4->unk9C[2] * 8);
    sub_8012BC4(r5, 0, sUnknown_203B2F4->input.unk1E + 1, 2, 7, sUnknown_203B2F4->unk34);

    for (r5 = 0; r5 < sUnknown_203B2F4->input.unk1A; r5++) {
        iVar1 = sub_803B344((sUnknown_203B2F4->input.unk1E * sUnknown_203B2F4->input.unk1C) + r5);

        local.unk0[0] = sUnknown_203B2F4->unk34;
        local.y = sub_8013800(&sUnknown_203B2F4->input, r5);
        sub_803B35C(&iVar1->mail, &local);

        local.unk43 = 1;
        local.unk4C = iVar1->unk14;
        CreateRescueTitle(&local);
    }

    sub_80073E0(sUnknown_203B2F4->unk34);
}