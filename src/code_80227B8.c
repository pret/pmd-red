#include "global.h"
#include "globaldata.h"
#include "code_80130A8.h"
#include "code_801AFA4.h"
#include "code_801B3C0.h"
#include "code_80227B8.h"
#include "code_8098BDC.h"
#include "code_8099360.h"
#include "code_80118A4.h"
#include "common_strings.h"
#include "constants/colors.h"
#include "input.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

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
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);

    sUnknown_203B294 = MemoryAlloc(sizeof(unkStruct_203B294), 8);
    sUnknown_203B294->menuAction = 0;
    sUnknown_203B294->pokeStruct = pkmn;

    if (pkmn != NULL) {
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames[0], pkmn, COLOR_WHITE_2);
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames[1], pkmn, COLOR_YELLOW);

        if (HasGummiItem())
            sub_8022924(0);
        else
            sub_8022924(17);
    }
    else {
        strcpy(gAvailablePokemonNames[0], sTripleQuestionMark);
        strcpy(gAvailablePokemonNames[1], sTripleQuestionMark);

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

    RestoreUnkTextStruct_8006518(sUnknown_203B294->unk148);

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
    xxx_call_save_unk_text_struct_800641C(sUnknown_203B294->unk148, TRUE, TRUE);
}

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
            CreateDialogueBoxAndPortrait(sDoesNotAppearHungry, 0, 0, 0x301);
            break;
        case 6:
            CreateDialogueBoxAndPortrait(sFmtGummiBigFav, 0, 0, 0x101);
            break;
        case 7:
            CreateDialogueBoxAndPortrait(sFmtGummiFav, 0, 0, 0x101);
            break;
        case 8:
            CreateDialogueBoxAndPortrait(sFmtGummiOkay, 0, 0, 0x101);
            break;
        case 9:
            CreateDialogueBoxAndPortrait(sFmtGummiSatisfied, 0, 0, 0x101);
            break;
        case 10:
            do {
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
                    strcpy(gFormatItems[1], GetIQSkillName(sUnknown_203B294->unk40));
                    PlaySound(203);
                    CreateDialogueBoxAndPortrait(sFmtIQHelpedLearn, 0, 0, 0x101);
                    sUnknown_203B294->unk40++;
                    break;
                }
                sUnknown_203B294->unk40++;
            } while (sUnknown_203B294->unk40 < NUM_IQ_SKILLS);
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
            CreateDialogueBoxAndPortrait(sFmtPlusEverything, 0, 0, 0x301);
            break;
        case 13:
            CreateDialogueBoxAndPortrait(sFmtPlusAtk, 0, 0, 0x301);
            break;
        case 14:
            CreateDialogueBoxAndPortrait(sFmtPlusSpAtk, 0, 0, 0x301);
            break;
        case 15:
            CreateDialogueBoxAndPortrait(sFmtPlusDef, 0, 0, 0x301);
            break;
        case 16:
            CreateDialogueBoxAndPortrait(sFmtPlusSpDef, 0, 0, 0x301);
            break;
        case 17:
            sUnknown_203B294->fallbackState = 22;
            CreateDialogueBoxAndPortrait(sNoGummis, 0, 0, 0x301);
            break;
        case 18:
            sUnknown_203B294->fallbackState = 22;
            CreateDialogueBoxAndPortrait(sNoItem, 0, 0, 0x301);
            break;
        case 19:
            sUnknown_203B294->fallbackState = 22;
            CreateDialogueBoxAndPortrait(sGummiGone, 0, 0, 0x301);
            break;
        case 20:
            sUnknown_203B294->fallbackState = 22;
            CreateDialogueBoxAndPortrait(sItemGone, 0, 0, 0x301);
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

            sub_8090E14(gFormatItems[0], &gTeamInventoryRef->teamItems[sUnknown_203B294->itemIndex], NULL);

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
