#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "code_801602C.h"
#include "code_801B3C0.h"
#include "code_8097670.h"
#include "code_8098BDC.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "constants/bg_music.h"
#include "constants/colors.h"
#include "constants/evolution_status.h"
#include "input.h"
#include "kecleon_bros4.h"
#include "luminous_cave.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "random.h"
#include "text_util.h"
#include "text.h"

enum
{
    LUMINOUS_CAVE_ENTRY,
    LUMINOUS_CAVE_ASK_EVOLVE,
    LUMINOUS_CAVE_EVOLVE_INFO,
    LUMINOUS_CAVE_SHALL_RETURN,
    // 4
    LUMINOUS_CAVE_GIVE_ITEM_1 = 5,
    // 6 - 9
    LUMINOUS_CAVE_GIVE_ITEM_2 = 10,
    // 11 - 14
    LUMINOUS_CAVE_LACK_WHAT_NEEDED = 15,
    LUMINOUS_CAVE_ONLY_ONE_ITEM,
    LUMINOUS_CAVE_LET_US_BEGIN,
    LUMINOUS_CAVE_CHANGED_APPEARANCE,
    LUMINOUS_CAVE_EVOLVED,
    LUMINOUS_CAVE_PROMPT_NAME,
    LUMINOUS_CAVE_FINISH_NAME,
    LUMINOUS_CAVE_COME_ALONE,
    LUMINOUS_CAVE_LACK_LEVEL,
    LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE,
    LUMINOUS_CAVE_LACK_FRIEND_AREA,
    LUMINOUS_CAVE_LACK_ROOM,
    LUMINOUS_CAVE_LACK_IQ,
    LUMINOUS_CAVE_LACK_ITEM,
    LUMINOUS_CAVE_CANT_EVOLVE_YET,
};

enum LuminousCaveMenuActions
{
    LUMINOUS_CAVE_CANCEL = 1,
    LUMINOUS_CAVE_INFO,
    LUMINOUS_CAVE_EVOLVE,
    LUMINOUS_CAVE_NO,
    LUMINOUS_CAVE_YES,

};

static EWRAM_INIT LuminousCaveWork *sLuminousCaveWork = {NULL};

#include "data/luminous_cave.h"

static void LuminousCave_AdvancetoFallbackState(void);
static bool8 LuminousCave_HasOnly1Member(void);
static void UpdateLuminousCaveDialogue(void);
static void UpdateLuminousCaveState(u32);

static void sub_8024804(void);
static void sub_8024CFC(void);
static void sub_8024D48(void);
static void sub_8024DBC(void);
static void sub_8024E30(void);
static void sub_8024E9C(void);
static void sub_8024F00(void);
static void sub_8024F70(void);
static void sub_8024FD4(void);
static void sub_8025058(void);
static void sub_80250EC(void);
static void sub_802515C(void);
static void sub_80251CC(void);
static void sub_80251E8(void);
static void sub_8025204(void);
static void sub_8025254(void);

u32 sub_802465C(void)
{
    OpenedFile *faceFile;

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    sLuminousCaveWork = MemoryAlloc(sizeof(LuminousCaveWork), 8);
    sLuminousCaveWork->menuAction1 = 0;
    sLuminousCaveWork->menuAction2 = 0;
    sLuminousCaveWork->menuAction3 = 0;
    sLuminousCaveWork->pokeStruct = GetPlayerPokemonStruct();
    sLuminousCaveWork->pokeRenamed = IsPokemonRenamed(sLuminousCaveWork->pokeStruct);
    sLuminousCaveWork->evolutionComplete = FALSE;
    faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
    sLuminousCaveWork->unk104 = faceFile;
    sLuminousCaveWork->unk108 = faceFile->data;
    sLuminousCaveWork->unk110 = 0;
    sLuminousCaveWork->unk111 = 0;
    sLuminousCaveWork->unk112 = 0;
    sLuminousCaveWork->unk10C = 2;
    sLuminousCaveWork->unk10E = 8;
    UpdateLuminousCaveState(LUMINOUS_CAVE_ENTRY);
    return TRUE;
}

u32 sub_80246F0(void)
{
    switch (sLuminousCaveWork->state) {
        case LUMINOUS_CAVE_ENTRY:
        case LUMINOUS_CAVE_ASK_EVOLVE:
            sub_8024E9C();
            break;
        case LUMINOUS_CAVE_GIVE_ITEM_1:
            sub_8024F00();
            break;
        case 6:
        case 7:
            sub_8024FD4();
            break;
        case 8:
            sub_80250EC();
            break;
        case 9:
            sub_80251CC();
            break;
        case LUMINOUS_CAVE_GIVE_ITEM_2:
            sub_8024F70();
            break;
        case 11:
        case 12:
            sub_8025058();
            break;
        case 13:
            sub_802515C();
            break;
        case 14:
            sub_80251E8();
            break;
        case LUMINOUS_CAVE_FINISH_NAME:
            sub_8025204();
            break;
        case 4:
            return 3;
        default:
            LuminousCave_AdvancetoFallbackState();
            break;
    }
    return 0;
}

bool8 HasEvolutionCompleted(void)
{
    return sLuminousCaveWork->evolutionComplete;
}

void CleanLuminousCave(void)
{
    if (sLuminousCaveWork != NULL) {
        CloseFile(sLuminousCaveWork->unk104);
        MemoryFree(sLuminousCaveWork);
        sLuminousCaveWork = NULL;
    }
}

static void UpdateLuminousCaveState(u32 newState)
{
    sLuminousCaveWork->state = newState;
    sub_8024804();
    UpdateLuminousCaveDialogue();
}

static void sub_8024804(void)
{
    s32 i;

    RestoreUnkTextStruct_8006518(sLuminousCaveWork->unk114);

    switch (sLuminousCaveWork->state) {
        case 8:
        case 13:
            sLuminousCaveWork->unk114[2] = sUnknown_80DCA00;
            break;
        case LUMINOUS_CAVE_LET_US_BEGIN:
        case LUMINOUS_CAVE_CHANGED_APPEARANCE:
        case LUMINOUS_CAVE_EVOLVED:
        case LUMINOUS_CAVE_COME_ALONE:
        case LUMINOUS_CAVE_LACK_LEVEL:
        case LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE:
        case LUMINOUS_CAVE_LACK_FRIEND_AREA:
        case LUMINOUS_CAVE_LACK_ROOM:
        case LUMINOUS_CAVE_LACK_IQ:
        case LUMINOUS_CAVE_LACK_ITEM:
            break;
        default:
            for (i = 0; i < 4; i++)
                sLuminousCaveWork->unk114[i] = sUnknown_80DC9E8;
            break;
    }

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sLuminousCaveWork->unk114, TRUE, TRUE);
}

static void UpdateLuminousCaveDialogue(void)
{
    u8 *monName;

    switch (sLuminousCaveWork->state) {
        case LUMINOUS_CAVE_ENTRY:
            if (LuminousCave_HasOnly1Member())
                sLuminousCaveWork->menuAction1 = LUMINOUS_CAVE_EVOLVE;
            else
                sLuminousCaveWork->menuAction1 = LUMINOUS_CAVE_CANCEL;

            sub_8024CFC();
            CreateMenuDialogueBoxAndPortrait(sSeekEvolutionIntro,0,sLuminousCaveWork->menuAction1,sLuminousCaveWork->unk34,sLuminousCaveWork->unk74,4,0,0,5);
            break;
        case LUMINOUS_CAVE_ASK_EVOLVE:
            sub_8024CFC();
            CreateMenuDialogueBoxAndPortrait(sSeekEvolutionPrompt,0,sLuminousCaveWork->menuAction1,sLuminousCaveWork->unk34,sLuminousCaveWork->unk74,4,0,0,5);
            break;
        case LUMINOUS_CAVE_EVOLVE_INFO:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_ASK_EVOLVE;
            CreateDialogueBoxAndPortrait(sEvolveInfo,0,0,0x105);
            break;
        case LUMINOUS_CAVE_SHALL_RETURN:
            sLuminousCaveWork->fallbackState = 4;
            xxx_call_fade_in_new_bgm(MUS_FILE_SELECT,0x3c);
            CreateDialogueBoxAndPortrait(sYeShallReturn,0,0,0x305);
            break;
        case LUMINOUS_CAVE_GIVE_ITEM_1:
            sub_8024D48();
            CreateMenuDialogueBoxAndPortrait(sGiveItemPrompt,0,sLuminousCaveWork->menuAction2,sLuminousCaveWork->unk34,sLuminousCaveWork->unk74,4,0,0,5);
            break;
        case 6:
            sub_801A5D8(2,3,NULL,10);
            break;
        case 7:
            sub_801A8D0(TRUE);
            break;
        case LUMINOUS_CAVE_GIVE_ITEM_2:
            sub_8024DBC();
            CreateMenuDialogueBoxAndPortrait(sGiveAnotherItemPrompt,0,sLuminousCaveWork->menuAction2,sLuminousCaveWork->unk34,sLuminousCaveWork->unk74,4,0,0,5);
            break;
        case 11:
            sub_801A5D8(2,3,NULL,10);
            sub_801AEE4(sLuminousCaveWork->evoItem1_InvIndex,1);
            sub_801A9E0();
            break;
        case 12:
            sub_801A8D0(TRUE);
            sub_801AEE4(sLuminousCaveWork->evoItem1_InvIndex,1);
            sub_801A9E0();
            break;
        case 8:
        case 13:
            sub_801A9E0();
            sub_8024E30();
            sub_8012D60(&sLuminousCaveWork->unk84,sLuminousCaveWork->unk34,0,sLuminousCaveWork->unk74,
                        sLuminousCaveWork->menuAction3,2);
            break;
        case 9:
        case 14:
            sub_801B3C0(&sLuminousCaveWork->chosenItem);
            break;
        case LUMINOUS_CAVE_LACK_WHAT_NEEDED:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_GIVE_ITEM_1;
            CreateDialogueBoxAndPortrait(sLackWhatIsNeeded,0,0,0x105);
            break;
        case LUMINOUS_CAVE_ONLY_ONE_ITEM:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_GIVE_ITEM_2;
            CreateDialogueBoxAndPortrait(sOnlyOneItem,0,0,0x105);
            break;
        case LUMINOUS_CAVE_LET_US_BEGIN:
            sub_8025254();

            if((sLuminousCaveWork->evolveStatus.evolutionConditionStatus & EVOLUTION_GOOD))
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_CHANGED_APPEARANCE;
            else if(sLuminousCaveWork->evolveStatus.evolutionConditionStatus == EVOLUTION_NO_MORE)
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE;
            else if(sLuminousCaveWork->evolveStatus.evolutionConditionStatus == EVOLUTION_LACK_LEVEL)
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_LACK_LEVEL;
            else if(sLuminousCaveWork->evolveStatus.evolutionConditionStatus == EVOLUTION_LACK_IQ)
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_LACK_IQ;
            else if(sLuminousCaveWork->evolveStatus.evolutionConditionStatus == EVOLUTION_LACK_FRIEND_AREA)
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_LACK_FRIEND_AREA;
            else if(sLuminousCaveWork->evolveStatus.evolutionConditionStatus == EVOLUTION_LACK_ROOM)
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_LACK_ROOM;
            else if(sLuminousCaveWork->evolveStatus.evolutionConditionStatus == EVOLUTION_LACK_ITEM)
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_LACK_ITEM;
            else
                sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_CANT_EVOLVE_YET;
            xxx_call_fade_out_bgm(0x3c);
            CreateDialogueBoxAndPortrait(sLetUsBegin,0,0,0x105);
            break;
        case LUMINOUS_CAVE_CHANGED_APPEARANCE:
            PrintColoredPokeNameToBuffer(gFormatBuffer_Names[0],sLuminousCaveWork->pokeStruct, COLOR_CYAN);
            PlaySound(0x1ff);
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_EVOLVED;
            CreateDialogueBoxAndPortrait(sFmtChangedAppearance,0,0,0x105);
            break;
        case LUMINOUS_CAVE_EVOLVED:
            monName = GetMonSpecies(sLuminousCaveWork->pokeStruct->speciesNum);
            strcpy(gFormatBuffer_Monsters[0],monName);
            monName = GetMonSpecies(sLuminousCaveWork->evolveStatus.targetEvolveSpecies);
            strcpy(gFormatBuffer_Monsters[1],monName);
            sLuminousCaveWork->evolutionComplete = TRUE;
            IncrementNumEvolved();
            sub_808F734(sLuminousCaveWork->pokeStruct,sLuminousCaveWork->evolveStatus.targetEvolveSpecies);
            nullsub_104();
            sLuminousCaveWork->pokeStruct = GetPlayerPokemonStruct();
            if (sLuminousCaveWork->evoItem1_InvIndex != INVENTORY_SIZE) {
                ClearItemSlotAt(sLuminousCaveWork->evoItem1_InvIndex);
            }
            if (sLuminousCaveWork->evoItem2_InvIndex != INVENTORY_SIZE) {
                ClearItemSlotAt(sLuminousCaveWork->evoItem2_InvIndex);
            }
            FillInventoryGaps();
            xxx_call_stop_fanfare_se(0x1ff);
            PlaySound(0xd2);
            if (sLuminousCaveWork->pokeRenamed) {
                    BoundedCopyStringtoBuffer(sLuminousCaveWork->pokeStruct->name,GetMonSpecies(sLuminousCaveWork->pokeStruct->speciesNum),POKEMON_NAME_LENGTH);
            }
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sFmtEvolved,0,0,0x105);
            break;
        case LUMINOUS_CAVE_COME_ALONE:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sComeAlone,0,0,0x105);
            break;
        case LUMINOUS_CAVE_LACK_LEVEL:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sLackLevel,0,0,0x105);
            break;
        case LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sNoMoreEvolutions,0,0,0x105);
            break;
        case LUMINOUS_CAVE_LACK_FRIEND_AREA:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sLackFriendArea,0,0,0x105);
            break;
        case LUMINOUS_CAVE_LACK_ROOM:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sLackFriendAreaRoom,0,0,0x105);
            break;
        case LUMINOUS_CAVE_LACK_IQ:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sLackIQ,0,0,0x105);
            break;
        case LUMINOUS_CAVE_LACK_ITEM:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sLackItem,0,0,0x105);
            break;
        case LUMINOUS_CAVE_CANT_EVOLVE_YET:
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
            CreateDialogueBoxAndPortrait(sCannotEvolveYet,0,0,0x105);
            break;
        case LUMINOUS_CAVE_PROMPT_NAME:
            xxx_call_fade_in_new_bgm(8,0x3c);
            sLuminousCaveWork->fallbackState = LUMINOUS_CAVE_FINISH_NAME;
            CreateDialogueBoxAndPortrait(sMustGiveName,0,0,0x105);
            break;
        case LUMINOUS_CAVE_FINISH_NAME:
            if (sLuminousCaveWork->pokeRenamed) {
                    BoundedCopyStringtoBuffer(sLuminousCaveWork->pokeStruct->name,GetMonSpecies(sLuminousCaveWork->pokeStruct->speciesNum),POKEMON_NAME_LENGTH);
            }
            CreateConfirmNameMenu(0,sLuminousCaveWork->pokeStruct->name);
            break;
        default:
            break;
    }
}

static void sub_8024CFC(void)
{
    s32 loopMax = 0;

    MemoryFill16(sLuminousCaveWork->unk74, 0, sizeof(sLuminousCaveWork->unk74));

    sLuminousCaveWork->unk34[loopMax].text = sEvolve0;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_EVOLVE;

    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = gCommonInfo[0];
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_INFO;

    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = gCommonCancel[0];
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_CANCEL;

    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = NULL;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_CANCEL;
}

static void sub_8024D48(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(sLuminousCaveWork->unk74, 0, sizeof(sLuminousCaveWork->unk74));
    sLuminousCaveWork->unk34[loopMax].text = sNo0;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_NO;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = sYes0;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_YES;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = gCommonCancel[0];
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_CANCEL;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = NULL;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_CANCEL;

    for (index = 0; index < loopMax; index++) {
        if (sLuminousCaveWork->unk74[index] == 0) {
            if (sLuminousCaveWork->unk34[index].menuAction == sLuminousCaveWork->menuAction2)
                return;
        }
    }

    sLuminousCaveWork->menuAction2 = LUMINOUS_CAVE_NO;
}

static void sub_8024DBC(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(sLuminousCaveWork->unk74, 0, sizeof(sLuminousCaveWork->unk74));
    sLuminousCaveWork->unk34[loopMax].text = sNo0;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_NO;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = sYes0;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_YES;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = gCommonCancel[0];
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_CANCEL;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = NULL;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_CANCEL;

    for(index = 0; index < loopMax; index++)
    {
        if(sLuminousCaveWork->unk74[index] == 0)
        {
            if(sLuminousCaveWork->unk34[index].menuAction == sLuminousCaveWork->menuAction2)
                return;
        }
    }

    sLuminousCaveWork->menuAction2 = LUMINOUS_CAVE_NO;
}

static void sub_8024E30(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(sLuminousCaveWork->unk74, 0, sizeof(sLuminousCaveWork->unk74));
    sLuminousCaveWork->unk34[loopMax].text = sYes0;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_YES;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = gCommonInfo[0];
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_INFO;
    loopMax += 1;
    sLuminousCaveWork->unk34[loopMax].text = NULL;
    sLuminousCaveWork->unk34[loopMax].menuAction = LUMINOUS_CAVE_CANCEL;

    for(index = 0; index < loopMax; index++)
    {
        if(sLuminousCaveWork->unk74[index] == 0)
        {
            if(sLuminousCaveWork->unk34[index].menuAction == sLuminousCaveWork->menuAction3)
                return;
        }
    }

    sLuminousCaveWork->menuAction3 = LUMINOUS_CAVE_YES;
}

static void sub_8024E9C(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        if(menuAction != LUMINOUS_CAVE_CANCEL) sLuminousCaveWork->menuAction1 = menuAction;
        switch(menuAction)
        {
            case LUMINOUS_CAVE_EVOLVE:
                if(LuminousCave_HasOnly1Member())
                    UpdateLuminousCaveState(LUMINOUS_CAVE_GIVE_ITEM_1);
                else
                    UpdateLuminousCaveState(LUMINOUS_CAVE_COME_ALONE);
                break;
            case LUMINOUS_CAVE_INFO:
                UpdateLuminousCaveState(LUMINOUS_CAVE_EVOLVE_INFO);
                break;
            case LUMINOUS_CAVE_CANCEL:
                UpdateLuminousCaveState(LUMINOUS_CAVE_SHALL_RETURN);
                break;
        }
    }
}

static void sub_8024F00(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        if(menuAction != LUMINOUS_CAVE_CANCEL) sLuminousCaveWork->menuAction2 = menuAction;
        switch(menuAction)
        {
            case LUMINOUS_CAVE_NO:
                sLuminousCaveWork->evoItem1_InvIndex = INVENTORY_SIZE;
                sLuminousCaveWork->evoItem2_InvIndex = INVENTORY_SIZE;
                UpdateLuminousCaveState(LUMINOUS_CAVE_LET_US_BEGIN);
                break;
            case LUMINOUS_CAVE_YES:
                if(GetNumberOfFilledInventorySlots() == 0)
                    UpdateLuminousCaveState(LUMINOUS_CAVE_LACK_WHAT_NEEDED);
                else
                    UpdateLuminousCaveState(0x6);
                break;
            case LUMINOUS_CAVE_CANCEL:
                UpdateLuminousCaveState(LUMINOUS_CAVE_ASK_EVOLVE);
                break;
        }
    }
}

static void sub_8024F70(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        if(menuAction != LUMINOUS_CAVE_CANCEL) sLuminousCaveWork->menuAction2 = menuAction;
        switch(menuAction)
        {
            case LUMINOUS_CAVE_NO:
                UpdateLuminousCaveState(LUMINOUS_CAVE_LET_US_BEGIN);
                break;
            case LUMINOUS_CAVE_YES:
                if(GetNumberOfFilledInventorySlots() < 2)
                    UpdateLuminousCaveState(LUMINOUS_CAVE_ONLY_ONE_ITEM);
                else
                    UpdateLuminousCaveState(0xB);
                break;
            case LUMINOUS_CAVE_CANCEL:
                UpdateLuminousCaveState(LUMINOUS_CAVE_ASK_EVOLVE);
                break;
        }
    }
}

static void sub_8024FD4(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            sLuminousCaveWork->evoItem1_InvIndex = sub_801A8AC();
            sLuminousCaveWork->evoItem2_InvIndex = INVENTORY_SIZE;
            sLuminousCaveWork->chosenItem = gTeamInventoryRef->teamItems[sLuminousCaveWork->evoItem1_InvIndex];
            UpdateLuminousCaveState(8);
            break;
        case 4:
            sLuminousCaveWork->chosenItem = gTeamInventoryRef->teamItems[sub_801A8AC()];
            sub_8099690(0);
            UpdateLuminousCaveState(9);
            break;
        case 2:
            sub_801A928();
            UpdateLuminousCaveState(LUMINOUS_CAVE_GIVE_ITEM_1);
            break;
    }
}

static void sub_8025058(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            if(sLuminousCaveWork->evoItem1_InvIndex != sub_801A8AC())
            {
                sLuminousCaveWork->evoItem2_InvIndex = sub_801A8AC();
                sLuminousCaveWork->chosenItem = gTeamInventoryRef->teamItems[sLuminousCaveWork->evoItem2_InvIndex];
                UpdateLuminousCaveState(0xD);
            }
            else
                PlayMenuSoundEffect(2);
            break;
        case 4:
            sLuminousCaveWork->chosenItem = gTeamInventoryRef->teamItems[sub_801A8AC()];
            sub_8099690(0);
            UpdateLuminousCaveState(0xE);
            break;
        case 2:
            sub_801A928();
            UpdateLuminousCaveState(0xA);
            break;
    }
}

static void sub_80250EC(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801A6E8(FALSE);

    if(!sub_8012FD8(&sLuminousCaveWork->unk84))
    {
        sub_8013114(&sLuminousCaveWork->unk84, &menuAction);
        if(menuAction != LUMINOUS_CAVE_CANCEL) sLuminousCaveWork->menuAction3 = menuAction;
    }
    switch(menuAction)
    {
        case LUMINOUS_CAVE_YES:
            sub_801A928();
            UpdateLuminousCaveState(0xA);
            break;
        case LUMINOUS_CAVE_INFO:
            sub_8099690(0);
            UpdateLuminousCaveState(0x9);
            break;
        case LUMINOUS_CAVE_CANCEL:
            UpdateLuminousCaveState(0x7);
            break;
    }
}

static void sub_802515C(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801A6E8(FALSE);

    if(!sub_8012FD8(&sLuminousCaveWork->unk84))
    {
        sub_8013114(&sLuminousCaveWork->unk84, &menuAction);
        if(menuAction != LUMINOUS_CAVE_CANCEL) sLuminousCaveWork->menuAction3 = menuAction;
    }
    switch(menuAction)
    {
        case LUMINOUS_CAVE_YES:
            sub_801A928();
            UpdateLuminousCaveState(LUMINOUS_CAVE_LET_US_BEGIN);
            break;
        case LUMINOUS_CAVE_INFO:
            sub_8099690(0);
            UpdateLuminousCaveState(0xE);
            break;
        case LUMINOUS_CAVE_CANCEL:
            UpdateLuminousCaveState(0xC);
            break;
    }
}

static void sub_80251CC(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            UpdateLuminousCaveState(0x7);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_80251E8(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            UpdateLuminousCaveState(0xC);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8025204(void)
{
    switch(sub_8016080())
    {
        case 3:
            CleanConfirmNameMenu();
            sLuminousCaveWork->pokeRenamed = IsPokemonRenamed(sLuminousCaveWork->pokeStruct);
            UpdateLuminousCaveState(LUMINOUS_CAVE_SHALL_RETURN);
            break;
        default:
            break;
    }
}

static void LuminousCave_AdvancetoFallbackState(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateLuminousCaveState(sLuminousCaveWork->fallbackState);
    }
}

static void sub_8025254(void)
{
    if(sLuminousCaveWork->evoItem1_InvIndex == INVENTORY_SIZE)
        sLuminousCaveWork->evolveStatus.evoItem1 = 0;
    else
    {
        sLuminousCaveWork->evolveStatus.evoItem1 = gTeamInventoryRef->teamItems[sLuminousCaveWork->evoItem1_InvIndex].id;
    }
    if(sLuminousCaveWork->evoItem2_InvIndex == INVENTORY_SIZE)
        sLuminousCaveWork->evolveStatus.evoItem2 = 0;
    else
    {
        sLuminousCaveWork->evolveStatus.evoItem2 = gTeamInventoryRef->teamItems[sLuminousCaveWork->evoItem2_InvIndex].id;
    }

    sLuminousCaveWork->evolveStatus.wurmpleVal = RandInt(0xFF);
    sub_808F468(sLuminousCaveWork->pokeStruct, &sLuminousCaveWork->evolveStatus, 1);
}

static bool8 LuminousCave_HasOnly1Member(void)
{
    s32 memberCount;
    s32 index;
    PokemonStruct1 *preload;

    preload = &gRecruitedPokemonRef->pokemon[0];
    memberCount = 0;
    for(index = 0; index < NUM_MONSTERS; index++, preload++)
    {
        if((preload->unk0 >> 1) & 1)
            memberCount++;
    }

    if(memberCount == 1)
        return TRUE;
    else
        return FALSE;
}
