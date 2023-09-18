#include "global.h"
#include "code_80118A4.h"
#include "code_801D9E4.h"
#include "constants/input.h"
#include "ground_main.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B258 *sUnknown_203B258 = {0};

extern struct unkStruct_81188F0 gUnknown_81188F0[10];
extern unkStruct_811BAF4 gUnknown_811BAF4[10];

#include "data/code_801D9E4.h"

static void sub_801DB54(void);
static void sub_801DBD4(void);

bool8 sub_801D9E4(void)
{
    sUnknown_203B258 = MemoryAlloc(sizeof(struct unkStruct_203B258), 8);
    sUnknown_203B258->unk34 = 3;
    sUnknown_203B258->unk38 = &sUnknown_203B258->unk3C[3];
    sub_8006518(sUnknown_203B258->unk3C);
    sUnknown_203B258->unk3C[sUnknown_203B258->unk34] = sUnknown_80DBF88;
    sUnknown_203B258->unk38->unk14 = sUnknown_203B258->unk9C;
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B258->unk3C, TRUE, TRUE);
    sub_8013818(&sUnknown_203B258->input, 229, 10, sUnknown_203B258->unk34);
    sub_801DB54();
    sub_801DBD4();
    return TRUE;
}

void sub_801DA58(s16 a0)
{
    s32 cast;
    cast = a0;
    sub_8013878(&sUnknown_203B258->input, cast);
    sub_801DB54();
    sub_801DBD4();
}

u32 sub_801DA78(void)
{
    switch (GetKeyPress(&sUnknown_203B258->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            return 3;
        default:
            if (sub_80138B8(&sUnknown_203B258->input, 1)) {
                sub_801DB54();
                sub_801DBD4();
                return 1;
            }
            return 0;
    }
}

s16 sub_801DAC0(void)
{
    return (sUnknown_203B258->input.unk1E * sUnknown_203B258->input.unk1C) + sUnknown_203B258->input.menuIndex;
}

UNUSED static void sub_801DADC(bool8 a0)
{
    sUnknown_203B258->input.unk22 = 229;
    sub_8013984(&sUnknown_203B258->input);
    sub_801DB54();
    sub_801DBD4();
    if (a0)
        AddMenuCursorSprite(&sUnknown_203B258->input);
}

void sub_801DB0C(void)
{
    if (sUnknown_203B258 != NULL) {
        sUnknown_203B258->unk3C[sUnknown_203B258->unk34] = sUnknown_80DBF70;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B258->unk3C, TRUE, TRUE);
        MemoryFree(sUnknown_203B258);
        sUnknown_203B258 = NULL;
    }
}

NAKED // sub_80095E4 memes
static void sub_801DB54(void)
{
    asm_unified(
    "\tpush {r4,lr}\n"
    "\tldr r4, _0801DBD0\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x9C\n"
    "\tmovs r2, 0\n"
    "\tmovs r1, 0x1\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x9D\n"
    "\tstrb r2, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x9E\n"
    "\tmovs r1, 0x8\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x9F\n"
    "\tstrb r2, [r0]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x3C\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tldr r0, [r4]\n"
    "\tmovs r1, 0x1A\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0xC\n"
    "\tbl sub_80095E4\n"
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
"_0801DBD0: .4byte sUnknown_203B258");
}

static void sub_801DBD4(void)
{
    unkStruct_811BAF4 *temp;
    struct unkStruct_81188F0 *temp2;
    s32 y;
#ifndef NONMATCHING
    register s32 x asm("r4");
#else
    s32 x;
#endif
    s16 index;
    int counter;

    sub_8008C54(sUnknown_203B258->unk34);
    sub_80073B8(sUnknown_203B258->unk34);
    xxx_call_draw_string(10, 0, sField, sUnknown_203B258->unk34, 0); // Field

    x = (sUnknown_203B258->unk9C[2] * 8) - 2;
    sub_8012BC4(x, 0, sUnknown_203B258->input.unk1E + 1, 2, 7, sUnknown_203B258->unk34);

    for (counter = 0; counter < sUnknown_203B258->input.unk1A; counter++) {
        index = (sUnknown_203B258->input.unk1E * sUnknown_203B258->input.unk1C) + counter;
        temp = &gUnknown_811BAF4[index];
        temp2 = &gUnknown_81188F0[temp->unk4];

        y = sub_8013800(&sUnknown_203B258->input, counter);
        xxx_call_draw_string(8, y, temp2->text1, sUnknown_203B258->unk34, 0);

        y = sub_8013800(&sUnknown_203B258->input, counter);
        xxx_call_draw_string(62, y, temp->text, sUnknown_203B258->unk34, 0);
    }

    sub_80073E0(sUnknown_203B258->unk34);
}