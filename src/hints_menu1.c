#include "global.h"
#include "code_80118A4.h"
#include "common_strings.h"
#include "hints_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B264 *sUnknown_203B264 = {0};

#include "data/hints_menu1.h"

static void DrawHintSelectionMenu(void);

static void sub_801E594(void);

bool8 sub_801E3F0(u32 a0)
{
    if (sUnknown_203B264 == NULL)
        sUnknown_203B264 = MemoryAlloc(sizeof(struct unkStruct_203B264), 8);

    sUnknown_203B264->unk34 = a0;
    sUnknown_203B264->unk38 = &sUnknown_203B264->unk3C[a0];
    sub_8006518(sUnknown_203B264->unk3C);
    sUnknown_203B264->unk3C[sUnknown_203B264->unk34] = sUnknown_80DC0BC;
    sub_8012D08(sUnknown_203B264->unk38, 10);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B264->unk3C, TRUE, TRUE);
    sub_8013818(&sUnknown_203B264->input, 5, 10, a0);
    sub_801E594();
    DrawHintSelectionMenu();
    return TRUE;
}

u32 sub_801E474(bool8 a0)
{
    if (a0 == 0) {
        sub_8013660(&sUnknown_203B264->input);
        return 0;
    }

    switch(GetKeyPress(&sUnknown_203B264->input))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        case 4:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if(sub_80138B8(&sUnknown_203B264->input, 1))
            {
                sub_801E594();
                DrawHintSelectionMenu();
                return 1;
            }
            else
                return 0;
    }
}

s32 GetChosenHintIndex(void)
{
    return (sUnknown_203B264->input.unk1E * sUnknown_203B264->input.unk1C) + sUnknown_203B264->input.menuIndex;
}

void CreateHintSelectionScreen(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B264->unk3C, FALSE, FALSE);
    sub_8013984(&sUnknown_203B264->input);
    sub_801E594();
    DrawHintSelectionMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B264->input);
}

void sub_801E54C(void)
{
    if (sUnknown_203B264 != NULL) {
        sUnknown_203B264->unk3C[sUnknown_203B264->unk34] = sUnknown_80DC0A0;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B264->unk3C, TRUE, TRUE);
        MemoryFree(sUnknown_203B264);
        sUnknown_203B264 = NULL;
    }
}

NAKED // sub_80095E4 memes
static void sub_801E594(void)
{
    asm_unified(
    "\tpush {r4,lr}\n"
    "\tldr r4, _0801E5E4\n"
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
"_0801E5E4: .4byte sUnknown_203B264");
}

static void DrawHintSelectionMenu(void)
{
    s32 hintIndex;
    s32 y;

    sub_8008C54(sUnknown_203B264->unk34);
    sub_80073B8(sUnknown_203B264->unk34);
    xxx_call_draw_string(16, 0, sHints, sUnknown_203B264->unk34, 0);

    for (hintIndex = 0; hintIndex < NUM_HINTS; hintIndex++) {
        y = sub_8013800(&sUnknown_203B264->input, hintIndex);
        xxx_call_draw_string(10, y, gCommonHints[hintIndex].heading, sUnknown_203B264->unk34, 0);
    }

    sub_80073E0(sUnknown_203B264->unk34);
}