#include "global.h"
#include "code_80130A8.h"
#include "code_801AFA4.h"
#include "code_801B3C0.h"
#include "code_80227B8.h"
#include "code_8098BDC.h"
#include "common_strings.h"
#include "constants/colors.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[]; // 202DF98

static EWRAM_DATA_2 unkStruct_203B294 *sUnknown_203B294 = {0};

#include "data/code_80227B8.h"

static void sub_8022924(s32 newState);
static void sub_802293C(void);
static void sub_8022A10(void);
static void sub_8022D2C(void);
static void sub_8022E78(void);
static void sub_8022EF4(void);
static void sub_8023068(void);
static void sub_80230E8(void);
static void sub_8023104(void);
static void sub_8023120(void);

bool8 sub_80227B8(PokemonStruct1 *pkmn)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);

    sUnknown_203B294 = MemoryAlloc(sizeof(unkStruct_203B294), 8);
    sUnknown_203B294->menuAction = 0;
    sUnknown_203B294->pokeStruct = pkmn;

    if (pkmn != NULL) {
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames, pkmn, COLOR_WHITE_2);
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames + 80, pkmn, COLOR_YELLOW);

        if (HasGummiItem())
            sub_8022924(0);
        else
            sub_8022924(17);
    }
    else {
        strcpy(gAvailablePokemonNames, sTripleQuestionMark);
        strcpy(gAvailablePokemonNames + 80, sTripleQuestionMark);

        if (GetNumberOfFilledInventorySlots() == 0)
            sub_8022924(18);
        else
            sub_8022924(00);
    }

    return TRUE;
}

u32 sub_8022860(void)
{
    switch (sUnknown_203B294->state) {
        case 0:
        case 1:
            sub_8022E78();
            break;
        case 2:
            sub_8022EF4();
            break;
        case 3:
            sub_8023068();
            break;
        case 4:
            sub_80230E8();
            break;
        case 0x15:
            sub_8023104();
            break;
        case 0x16:
            return 3;
        default:
            sub_8023120();
            break;
    }
    return 0;
}

void sub_8022908(void)
{
    if (sUnknown_203B294) {
        MemoryFree(sUnknown_203B294);
        sUnknown_203B294 = NULL;
    }
}

static void sub_8022924(s32 newState)
{
    sUnknown_203B294->state = newState;
    sub_802293C();
    sub_8022A10();
}

static void sub_802293C(void)
{
    s32 i;

    sub_8006518(sUnknown_203B294->unk148);

    switch (sUnknown_203B294->state) {
        case 2:
            sub_8022D2C();
            sUnknown_203B294->unk148[2] = sUnknown_80DC5BC;
            sub_8012CAC(&sUnknown_203B294->unk148[2], sUnknown_203B294->unkF8);
            sUnknown_203B294->unk148[2].unkC = 6;
            break;
        case 3:
            sUnknown_203B294->unk148[1] = sUnknown_80DC5D4;
            break;
        default:
            for (i = 0; i < 4; i++)
                sUnknown_203B294->unk148[i] = sUnknown_80DC5A4;
            break;
        case 10 ... 16:
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B294->unk148, TRUE, TRUE);
}

#ifdef NONMATCHING // 90.42%. Functionally equivalent but code is placed in the wrong location: https://decomp.me/scratch/HzklC
static void sub_8022A10(void)
{
    s32 r3;
    bool8 r5;
    bool8 r6;

    switch (sUnknown_203B294->state) {
        case 0:
            if (sUnknown_203B294->pokeStruct != NULL)
                sub_801A5D8(5, 3, NULL, 10);
            else
                sub_801A5D8(1, 3, NULL, 10);
            break;
        case 1:
            sub_801A8D0(TRUE);
            break;
        case 2:
            sub_801A9E0();
            sub_8012D60(&sUnknown_203B294->unk54, sUnknown_203B294->unkF8, 0, sUnknown_203B294->unk138, sUnknown_203B294->menuAction, 2);
            break;
        case 3:
            sub_801A9E0();
            sub_8012EA4(&sUnknown_203B294->unk54, FALSE);
            sub_8012D60(&sUnknown_203B294->unkA4, sUnknown_80DC584, 0, 0, 3, 1);
            break;
        case 4:
            sub_801B3C0(&sUnknown_203B294->item);
            break;
        case 5:
            sub_80141B4(sDoesNotAppearHungry, 0, 0, 0x301);
            break;
        case 6:
            sub_80141B4(sFmtGummiBigFav, 0, 0, 0x101);
            break;
        case 7:
            sub_80141B4(sFmtGummiFav, 0, 0, 0x101);
            break;
        case 8:
            sub_80141B4(sFmtGummiOkay, 0, 0, 0x101);
            break;
        case 9:
            sub_80141B4(sFmtGummiSatisfied, 0, 0, 0x101);
            break;
        case 10:
            while (++sUnknown_203B294->unk40 < NUM_IQ_SKILLS) {
                r5 = FALSE;
                r6 = FALSE;

                for (r3 = 0; r3 < sUnknown_203B294->availIQSkillPreGummi; r3++) {
                    if (sUnknown_203B294->iqSkillPreGummi[r3] == sUnknown_203B294->unk40) {
                        r5 = TRUE;
                        break;
                    }
                }

                for (r3 = 0; r3 < sUnknown_203B294->availIQSkillPostGummi; r3++) {
                    if (sUnknown_203B294->iqSkillPostGummi[r3] == sUnknown_203B294->unk40) {
                        r6 = TRUE;
                        break;
                    }
                }

                if (r5 != r6) {
                    sUnknown_203B294->fallbackState = 10;
                    strcpy(gUnknown_202DEA8, GetIQSkillName(sUnknown_203B294->unk40));
                    PlaySound(203);
                    sub_80141B4(sFmtIQHelpedLearn, 0, 0, 0x101);
                    sUnknown_203B294->unk40++;
                    break;
                }
            }
            if (sUnknown_203B294->unk40 >= NUM_IQ_SKILLS)
                sub_8022924(11);
            break;
        case 11:
            sUnknown_203B294->fallbackState = 22;
            nullsub_104();

            switch (sUnknown_203B294->gummi.flags) {
                case 0:
                    sub_8022924(22);
                    break;
                case 1:
                    sub_8022924(13);
                    break;
                case 2:
                    sub_8022924(14);
                    break;
                case 4:
                    sub_8022924(15);
                    break;
                case 8:
                    sub_8022924(16);
                    break;
                default:
                    sub_8022924(12);
                    break;
            }
            break;
        case 12:
            sub_80141B4(sFmtPlusEverything, 0, 0, 0x301);
            break;
        case 13:
            sub_80141B4(sFmtPlusAtk, 0, 0, 0x301);
            break;
        case 14:
            sub_80141B4(sFmtPlusSpAtk, 0, 0, 0x301);
            break;
        case 15:
            sub_80141B4(sFmtPlusDef, 0, 0, 0x301);
            break;
        case 16:
            sub_80141B4(sFmtPlusSpDef, 0, 0, 0x301);
            break;
        case 17:
            sUnknown_203B294->fallbackState = 22;
            sub_80141B4(sNoGummis, 0, 0, 0x301);
            break;
        case 18:
            sUnknown_203B294->fallbackState = 22;
            sub_80141B4(sNoItem, 0, 0, 0x301);
            break;
        case 19:
            sUnknown_203B294->fallbackState = 22;
            sub_80141B4(sGummiGone, 0, 0, 0x301);
            break;
        case 20:
            sUnknown_203B294->fallbackState = 22;
            sub_80141B4(sItemGone, 0, 0, 0x301);
            break;
        case 21:
            sub_801AFA4(sUnknown_203B294->itemIndex);
            break;
        case 22:
        default:
            sub_801A928();
            break;
    }
}
#else
NAKED static void sub_8022A10(void)
{
    asm_unified(
    "\tpush {r4-r7,lr}\n"
    "\tsub sp, 0x8\n"
    "\tldr r1, _08022A2C\n"
    "\tldr r0, [r1]\n"
    "\tldr r0, [r0]\n"
    "\tadds r4, r1, 0\n"
    "\tcmp r0, 0x16\n"
    "\tbls _08022A22\n"
    "\tb _08022D1E\n"
"_08022A22:\n"
    "\tlsls r0, 2\n"
    "\tldr r1, _08022A30\n"
    "\tadds r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
"_08022A2C: .4byte sUnknown_203B294\n"
"_08022A30: .4byte _08022A34\n"
    "\t.align 2, 0\n"
"_08022A34:\n"
    "\t.4byte _08022A90\n"
    "\t.4byte _08022AAA\n"
    "\t.4byte _08022AB2\n"
    "\t.4byte _08022AE0\n"
    "\t.4byte _08022B10\n"
    "\t.4byte _08022B1A\n"
    "\t.4byte _08022B24\n"
    "\t.4byte _08022B34\n"
    "\t.4byte _08022B44\n"
    "\t.4byte _08022B54\n"
    "\t.4byte _08022B64\n"
    "\t.4byte _08022C28\n"
    "\t.4byte _08022CA0\n"
    "\t.4byte _08022CA8\n"
    "\t.4byte _08022CB0\n"
    "\t.4byte _08022CB8\n"
    "\t.4byte _08022CC0\n"
    "\t.4byte _08022CC8\n"
    "\t.4byte _08022CD8\n"
    "\t.4byte _08022CE8\n"
    "\t.4byte _08022CF8\n"
    "\t.4byte _08022D14\n"
    "\t.4byte _08022D1E\n"
"_08022A90:\n"
    "\tldr r0, [r4]\n"
    "\tldr r0, [r0, 0x48]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08022A9C\n"
    "\tmovs r0, 0x5\n"
    "\tb _08022A9E\n"
"_08022A9C:\n"
    "\tmovs r0, 0x1\n"
"_08022A9E:\n"
    "\tmovs r1, 0x3\n"
    "\tmovs r2, 0\n"
    "\tmovs r3, 0xA\n"
    "\tbl sub_801A5D8\n"
    "\tb _08022D22\n"
"_08022AAA:\n"
    "\tmovs r0, 0x1\n"
    "\tbl sub_801A8D0\n"
    "\tb _08022D22\n"
"_08022AB2:\n"
    "\tbl sub_801A9E0\n"
    "\tldr r0, _08022ADC\n"
    "\tldr r2, [r0]\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x54\n"
    "\tadds r1, r2, 0\n"
    "\tadds r1, 0xF8\n"
    "\tmovs r4, 0x9C\n"
    "\tlsls r4, 1\n"
    "\tadds r3, r2, r4\n"
    "\tadds r2, 0xF4\n"
    "\tldr r2, [r2]\n"
    "\tstr r2, [sp]\n"
    "\tmovs r2, 0x2\n"
    "\tstr r2, [sp, 0x4]\n"
    "\tmovs r2, 0\n"
    "\tbl sub_8012D60\n"
    "\tb _08022D22\n"
    "\t.align 2, 0\n"
"_08022ADC: .4byte sUnknown_203B294\n"
"_08022AE0:\n"
    "\tbl sub_801A9E0\n"
    "\tldr r4, _08022B08\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x54\n"
    "\tmovs r1, 0\n"
    "\tbl sub_8012EA4\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xA4\n"
    "\tldr r1, _08022B0C\n"
    "\tmovs r2, 0x3\n"
    "\tstr r2, [sp]\n"
    "\tmovs r2, 0x1\n"
    "\tstr r2, [sp, 0x4]\n"
    "\tmovs r2, 0\n"
    "\tmovs r3, 0\n"
    "\tbl sub_8012D60\n"
    "\tb _08022D22\n"
    "\t.align 2, 0\n"
"_08022B08: .4byte sUnknown_203B294\n"
"_08022B0C: .4byte sUnknown_80DC584\n"
"_08022B10:\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x50\n"
    "\tbl sub_801B3C0\n"
    "\tb _08022D22\n"
"_08022B1A:\n"
    "\tldr r0, _08022B20\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022B20: .4byte sDoesNotAppearHungry\n"
"_08022B24:\n"
    "\tldr r0, _08022B2C\n"
    "\tldr r3, _08022B30\n"
    "\tb _08022D02\n"
    "\t.align 2, 0\n"
"_08022B2C: .4byte sFmtGummiBigFav\n"
"_08022B30: .4byte 0x00000101\n"
"_08022B34:\n"
    "\tldr r0, _08022B3C\n"
    "\tldr r3, _08022B40\n"
    "\tb _08022D02\n"
    "\t.align 2, 0\n"
"_08022B3C: .4byte sFmtGummiFav\n"
"_08022B40: .4byte 0x00000101\n"
"_08022B44:\n"
    "\tldr r0, _08022B4C\n"
    "\tldr r3, _08022B50\n"
    "\tb _08022D02\n"
    "\t.align 2, 0\n"
"_08022B4C: .4byte sFmtGummiOkay\n"
"_08022B50: .4byte 0x00000101\n"
"_08022B54:\n"
    "\tldr r0, _08022B5C\n"
    "\tldr r3, _08022B60\n"
    "\tb _08022D02\n"
    "\t.align 2, 0\n"
"_08022B5C: .4byte sFmtGummiSatisfied\n"
"_08022B60: .4byte 0x00000101\n"
"_08022B64:\n"
    "\tldr r7, _08022B68\n"
    "\tb _08022B78\n"
    "\t.align 2, 0\n"
"_08022B68: .4byte sUnknown_203B294\n"
"_08022B6C:\n"
    "\tldr r1, [r4]\n"
    "\tldr r0, [r1, 0x40]\n"
    "\tadds r0, 0x1\n"
    "\tstr r0, [r1, 0x40]\n"
    "\tcmp r0, 0x17\n"
    "\tbgt _08022C10\n"
"_08022B78:\n"
    "\tmovs r5, 0\n"
    "\tmovs r6, 0\n"
    "\tmovs r3, 0\n"
    "\tldr r2, [r4]\n"
    "\tldr r0, [r2, 0x38]\n"
    "\tcmp r5, r0\n"
    "\tbge _08022BA4\n"
    "\tldrb r1, [r2, 0x8]\n"
    "\tb _08022B9C\n"
"_08022B8A:\n"
    "\tadds r3, 0x1\n"
    "\tldr r2, [r4]\n"
    "\tldr r0, [r2, 0x38]\n"
    "\tcmp r3, r0\n"
    "\tbge _08022BA4\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x8\n"
    "\tadds r0, r3\n"
    "\tldrb r1, [r0]\n"
"_08022B9C:\n"
    "\tldr r0, [r2, 0x40]\n"
    "\tcmp r1, r0\n"
    "\tbne _08022B8A\n"
    "\tmovs r5, 0x1\n"
"_08022BA4:\n"
    "\tmovs r3, 0\n"
    "\tldr r2, [r4]\n"
    "\tldr r0, [r2, 0x3C]\n"
    "\tcmp r3, r0\n"
    "\tbge _08022BCE\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x20\n"
    "\tb _08022BC4\n"
"_08022BB4:\n"
    "\tadds r3, 0x1\n"
    "\tldr r2, [r4]\n"
    "\tldr r0, [r2, 0x3C]\n"
    "\tcmp r3, r0\n"
    "\tbge _08022BCE\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x20\n"
    "\tadds r0, r3\n"
"_08022BC4:\n"
    "\tldrb r1, [r0]\n"
    "\tldr r0, [r2, 0x40]\n"
    "\tcmp r1, r0\n"
    "\tbne _08022BB4\n"
    "\tmovs r6, 0x1\n"
"_08022BCE:\n"
    "\tcmp r5, r6\n"
    "\tbeq _08022B6C\n"
    "\tldr r1, [r7]\n"
    "\tmovs r0, 0xA\n"
    "\tstr r0, [r1, 0x4]\n"
    "\tldr r0, [r1, 0x40]\n"
    "\tlsls r0, 24\n"
    "\tlsrs r0, 24\n"
    "\tbl GetIQSkillName\n"
    "\tadds r1, r0, 0\n"
    "\tldr r0, _08022C18\n"
    "\tbl strcpy\n"
    "\tmovs r0, 0xCB\n"
    "\tbl PlaySound\n"
    "\tldr r0, _08022C1C\n"
    "\tmovs r1, 0\n"
    "\tmovs r2, 0\n"
    "\tldr r3, _08022C20\n"
    "\tbl sub_80141B4\n"
    "\tldr r1, [r7]\n"
    "\tldr r0, [r1, 0x40]\n"
    "\tadds r0, 0x1\n"
    "\tstr r0, [r1, 0x40]\n"
    "\tldr r0, _08022C24\n"
    "\tldr r0, [r0]\n"
    "\tldr r0, [r0, 0x40]\n"
    "\tcmp r0, 0x17\n"
    "\tbgt _08022C10\n"
    "\tb _08022D22\n"
"_08022C10:\n"
    "\tmovs r0, 0xB\n"
    "\tbl sub_8022924\n"
    "\tb _08022D22\n"
    "\t.align 2, 0\n"
"_08022C18: .4byte gUnknown_202DEA8\n"
"_08022C1C: .4byte sFmtIQHelpedLearn\n"
"_08022C20: .4byte 0x00000101\n"
"_08022C24: .4byte sUnknown_203B294\n"
"_08022C28:\n"
    "\tldr r1, [r4]\n"
    "\tmovs r0, 0x16\n"
    "\tstr r0, [r1, 0x4]\n"
    "\tbl nullsub_104\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x46\n"
    "\tldrh r0, [r0]\n"
    "\tcmp r0, 0x8\n"
    "\tbhi _08022C98\n"
    "\tlsls r0, 2\n"
    "\tldr r1, _08022C48\n"
    "\tadds r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
"_08022C48: .4byte _08022C4C\n"
    "\t.align 2, 0\n"
"_08022C4C:\n"
    "\t.4byte _08022C70\n"
    "\t.4byte _08022C78\n"
    "\t.4byte _08022C80\n"
    "\t.4byte _08022C98\n"
    "\t.4byte _08022C88\n"
    "\t.4byte _08022C98\n"
    "\t.4byte _08022C98\n"
    "\t.4byte _08022C98\n"
    "\t.4byte _08022C90\n"
"_08022C70:\n"
    "\tmovs r0, 0x16\n"
    "\tbl sub_8022924\n"
    "\tb _08022D22\n"
"_08022C78:\n"
    "\tmovs r0, 0xD\n"
    "\tbl sub_8022924\n"
    "\tb _08022D22\n"
"_08022C80:\n"
    "\tmovs r0, 0xE\n"
    "\tbl sub_8022924\n"
    "\tb _08022D22\n"
"_08022C88:\n"
    "\tmovs r0, 0xF\n"
    "\tbl sub_8022924\n"
    "\tb _08022D22\n"
"_08022C90:\n"
    "\tmovs r0, 0x10\n"
    "\tbl sub_8022924\n"
    "\tb _08022D22\n"
"_08022C98:\n"
    "\tmovs r0, 0xC\n"
    "\tbl sub_8022924\n"
    "\tb _08022D22\n"
"_08022CA0:\n"
    "\tldr r0, _08022CA4\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CA4: .4byte sFmtPlusEverything\n"
"_08022CA8:\n"
    "\tldr r0, _08022CAC\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CAC: .4byte sFmtPlusAtk\n"
"_08022CB0:\n"
    "\tldr r0, _08022CB4\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CB4: .4byte sFmtPlusSpAtk\n"
"_08022CB8:\n"
    "\tldr r0, _08022CBC\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CBC: .4byte sFmtPlusDef\n"
"_08022CC0:\n"
    "\tldr r0, _08022CC4\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CC4: .4byte sFmtPlusSpDef\n"
"_08022CC8:\n"
    "\tldr r1, [r4]\n"
    "\tmovs r0, 0x16\n"
    "\tstr r0, [r1, 0x4]\n"
    "\tldr r0, _08022CD4\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CD4: .4byte sNoGummis\n"
"_08022CD8:\n"
    "\tldr r1, [r4]\n"
    "\tmovs r0, 0x16\n"
    "\tstr r0, [r1, 0x4]\n"
    "\tldr r0, _08022CE4\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CE4: .4byte sNoItem\n"
"_08022CE8:\n"
    "\tldr r1, [r4]\n"
    "\tmovs r0, 0x16\n"
    "\tstr r0, [r1, 0x4]\n"
    "\tldr r0, _08022CF4\n"
    "\tb _08022D00\n"
    "\t.align 2, 0\n"
"_08022CF4: .4byte sGummiGone\n"
"_08022CF8:\n"
    "\tldr r1, [r4]\n"
    "\tmovs r0, 0x16\n"
    "\tstr r0, [r1, 0x4]\n"
    "\tldr r0, _08022D0C\n"
"_08022D00:\n"
    "\tldr r3, _08022D10\n"
"_08022D02:\n"
    "\tmovs r1, 0\n"
    "\tmovs r2, 0\n"
    "\tbl sub_80141B4\n"
    "\tb _08022D22\n"
    "\t.align 2, 0\n"
"_08022D0C: .4byte sItemGone\n"
"_08022D10: .4byte 0x00000301\n"
"_08022D14:\n"
    "\tldr r0, [r4]\n"
    "\tldr r0, [r0, 0x4C]\n"
    "\tbl sub_801AFA4\n"
    "\tb _08022D22\n"
"_08022D1E:\n"
    "\tbl sub_801A928\n"
"_08022D22:\n"
    "\tadd sp, 0x8\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}
#endif // NONMATCHING

static void sub_8022D2C(void)
{
    s32 index;
    s32 loopMax = 0;

    MemoryFill16(sUnknown_203B294->unk138, 0, sizeof(sUnknown_203B294->unk138));

    if (sUnknown_203B294->pokeStruct) {
        sUnknown_203B294->unkF8[loopMax].text = sGive;
        sUnknown_203B294->unkF8[loopMax].menuAction = 5;
        if (!IsGummiItem(sUnknown_203B294->item.id))
            sUnknown_203B294->unk138[loopMax] = 1;

        loopMax++;
    }
    else {
        if (GetItemCategory(sUnknown_203B294->item.id) == CATEGORY_TMS_HMS) {
            sUnknown_203B294->unkF8[loopMax].text = sUse;
            sUnknown_203B294->unkF8[loopMax].menuAction = 6;
            loopMax++;
        }

        sUnknown_203B294->unkF8[loopMax].text = gCommonTrash[0];
        sUnknown_203B294->unkF8[loopMax].menuAction = 4;
        loopMax++;
    }

    sUnknown_203B294->unkF8[loopMax].text = gCommonInfo[0];
    sUnknown_203B294->unkF8[loopMax].menuAction = 7;

    loopMax++;
    sUnknown_203B294->unkF8[loopMax].text = NULL;
    sUnknown_203B294->unkF8[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B294->unk138[index] == 0) {
            if (sUnknown_203B294->unkF8[index].menuAction == sUnknown_203B294->menuAction)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B294->unk138[index] == 0) {
            sUnknown_203B294->menuAction = sUnknown_203B294->unkF8[index].menuAction;
            break;
        }
    }
}

static void sub_8022E78(void)
{
    switch (sub_801A6E8(TRUE)) {
        case 3:
            sUnknown_203B294->itemIndex = sub_801A8AC();
            sUnknown_203B294->item = gTeamInventoryRef->teamItems[sUnknown_203B294->itemIndex];
            sub_8022924(2);
            break;
        case 4:
            sUnknown_203B294->itemIndex = sub_801A8AC();
            sUnknown_203B294->item = gTeamInventoryRef->teamItems[sUnknown_203B294->itemIndex];
            sub_8099690(0);
            sub_8022924(4);
            break;
        case 2:
            sub_8022924(22);
            break;
    }
}

static void sub_8022EF4(void)
{
    s32 menuAction;
    s32 boostAmount;

    menuAction = 0;
    sub_801A6E8(FALSE);

    if (sub_8012FD8(&sUnknown_203B294->unk54) == 0) {
        sub_8013114(&sUnknown_203B294->unk54, &menuAction);
        if (menuAction != 1)
            sUnknown_203B294->menuAction = menuAction;
    }

    switch (menuAction) {
        case 1:
            sub_8022924(1);
            break;
        case 2:
        case 3:
            break;
        case 5:
            sUnknown_203B294->availIQSkillPreGummi = GetNumAvailableIQSkills(sUnknown_203B294->iqSkillPreGummi, sUnknown_203B294->pokeStruct->IQ);
            GetGummiItemStatBoost(sUnknown_203B294->pokeStruct, sUnknown_203B294->item.id, FALSE, &sUnknown_203B294->gummi);
            sUnknown_203B294->availIQSkillPostGummi = GetNumAvailableIQSkills(sUnknown_203B294->iqSkillPostGummi, sUnknown_203B294->pokeStruct->IQ);
            sUnknown_203B294->unk40 = 1;
            boostAmount = sUnknown_203B294->gummi.boostAmount;

            sub_8090E14(gUnknown_202DE58, &gTeamInventoryRef->teamItems[sUnknown_203B294->itemIndex], NULL);

            if (boostAmount != -1)
                ShiftItemsDownFrom(sUnknown_203B294->itemIndex);

            sub_8099690(0);
            sUnknown_203B294->fallbackState = 10;

            switch (boostAmount + 1) {
                case 1:
                    sub_8022924(6);
                    break;
                case 2:
                    sub_8022924(7);
                    break;
                case 3:
                    sub_8022924(8);
                    break;
                case 4:
                    sub_8022924(9);
                    break;
                default:
                case 0:
                    sUnknown_203B294->fallbackState = 22;
                    sub_8022924(5);
                    break;
            }
            break;
        case 6:
            sub_8022924(21);
            break;
        case 4:
            sub_8022924(3);
            break;
        case 7:
            sub_8099690(0);
            sub_8022924(4);
            break;
    }
}

static void sub_8023068(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801A6E8(FALSE);
    sub_8012FD8(&sUnknown_203B294->unk54);

    if (sub_8012FD8(&sUnknown_203B294->unkA4) == 0)
        sub_8013114(&sUnknown_203B294->unkA4, &menuAction);

    switch (menuAction) {
        case 1:
        case 3:
            sub_8022924(1);
            break;
        case 2:
            ShiftItemsDownFrom(sUnknown_203B294->itemIndex);
            if (GetNumberOfFilledInventorySlots() == 0) {
                sub_8099690(0);
                sub_801A928();
                sub_8022924(20);
            }
            else
                sub_8022924(1);
            break;
    }
}

static void sub_80230E8(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            sub_801B450();
            sub_8022924(1);
        case 1:
        case 0:
            break;
    }
}

static void sub_8023104(void)
{
    switch (sub_801B00C()) {
        case 2:
        case 3:
            sub_801B048();
            sub_8022924(1);
        case 1:
        case 0:
            break;
    }
}

static void sub_8023120(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sub_8022924(sUnknown_203B294->fallbackState);
}