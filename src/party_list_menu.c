#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "code_800D090.h"
#include "music_util.h"
#include "code_801B3C0.h"
#include "code_801EE10.h"
#include "code_801EE10_mid.h"
#include "code_80227B8.h"
#include "code_8024458.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "event_flag.h"
#include "input.h"
#include "iq_skill_menu.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "party_list_menu.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "text_util.h"
#include "unk_ds_only_feature.h"

// size: 0x280
typedef struct unkStruct_203B2B8
{
    /* 0x0 */ s32 state;
    /* 0x4 */ s32 fallbackState;
    bool8 unk8;
    /* 0xA */ s16 pokeSpecies;
    /* 0xC */ u32 id;
    /* 0x10 */ BulkItem item1;
    /* 0x14 */ BulkItem item2;
    /* 0x18 */ Pokemon *pokeStruct;
    /* 0x1C */ bool8 isTeamLeader;
    /* 0x20 */ u32 moveIndex;
    /* 0x24 */ u16 moveID;
    /* 0x28 */ Move moves[8];
    /* 0x68 */ u16 moveIDs[4]; // some list of move IDs
    /* 0x70 */ u32 menuAction1;
    /* 0x74 */ u32 menuAction2;
    /* 0x78 */ u32 menuAction3; // unused
    MenuStruct unk7C;
    MenuStruct unkCC;
    MenuStruct unk11C; // unused
    MenuItem unk16C[10];
    MenuItem unk1BC[10];
    u16 unk20C[10];
    WindowTemplates unk220;
} unkStruct_203B2B8;

static EWRAM_INIT unkStruct_203B2B8 *sUnknown_203B2B8 = {NULL};

#include "data/party_list_menu.h"

static u32 sub_8026F04(Pokemon *);
static bool8 CanTakePokemonHeldItem(Pokemon *r0);
static bool8 sub_8026E88(Pokemon *r0);
static bool8 sub_8026EB8(Pokemon *r0);
static void sub_8026E08(u32 r0);
static void sub_8026DAC(u32 r0, BulkItem *item);
static void sub_8026FA4(void);
static void PartyListMenu_BuildYesNoMenu(void);
static void PartyListMenu_CreateMenu2(void);
static void PartyListMenu_CreateMenu1(void);
static void HandlePartyListMenuCallback(void);
static void PartyListMenu_HandleMenu1(void);
static void sub_8026A78(void);
static void sub_8026A94(void);
static void sub_8026AB0(void);
static void sub_8026B10(void);
static void sub_8026B48(void);
static void sub_8026B64(void);
static void PartyListMenu_HandleMenu2(void);
static void sub_8026CF0(void);
static void sub_8026D0C(void);
static void sub_8026D6C(void);
static void PartyListMenu_GotoFallbackState(void);
static void SetPartyListMenuState(s32 newState);
static void sub_802608C(void);

enum PartyListMenuStates
{
    PARTY_LIST_STATE_INIT,
    PARTY_LIST_STATE_MAIN_MENU,
    PARTY_LIST_STATE_MAIN_MENU_1,
    PARTY_LIST_STATE_SUMMARY = 3,
    PARTY_LIST_STATE_CHECK_IQ = 4,
    PARTY_LIST_STATE_JOIN_TEAM = 5,
    PARTY_LIST_STATE_STANDBY = 6,
    PARTY_LIST_STATE_MAKE_LEADER = 7,
    PARTY_LIST_STATE_POKEMON_FAREWELL = 8,
    // 9
    // 0xA
    // 0xB
    PARTY_LIST_STATE_SAY_FAREWELL = 0xC,
    PARTY_LIST_STATE_CONFIRM_SAY_FAREWELL = 0xD,
    PARTY_LIST_STATE_GIVE_GUMMI = 0xe,
    PARTY_LIST_STATE_GIVEN_ITEM = 0xF,
    PARTY_LIST_STATE_GIVEN_ITEM_HELD_ITEM = 0x10,
    PARTY_LIST_STATE_TAKE_ITEM = 0x11,
    PARTY_LIST_STATE_GIVE_ITEM = 0x12,
    PARTY_LIST_STATE_GIVE_ITEM_1 = 0x13,
    // 0x14
    // 0x15
    PARTY_LIST_STATE_MOVES = 0x16,
    // 0x17
    // 0x18
    PARTY_LIST_STATE_EXIT = 0x19,

};

enum PartyListMenuActions
{
    PARTY_LIST_MENU_NULL = 1,
    PARTY_LIST_MENU_YES,
    PARTY_LIST_MENU_NO,
    PARTY_LIST_MENU_INFO = 4,
    PARTY_LIST_MENU_SUMMARY = 4,
    PARTY_LIST_MENU_CHECK_IQ,
    PARTY_LIST_MENU_JOIN_TEAM,
    PARTY_LIST_MENU_STANDBY,
    PARTY_LIST_MENU_MAKE_LEADER,
    PARTY_LIST_MENU_SAY_FAREWELL,
    PARTY_LIST_MENU_GIVE_GUMMI,
    PARTY_LIST_MENU_GIVE_ITEM,
    PARTY_LIST_MENU_TAKE_ITEM,
    PARTY_LIST_MENU_MOVES,
};

bool8 CreatePartyListMenu(Pokemon *pokeStruct)
{
    s32 i;

    sUnknown_203B2B8 = MemoryAlloc(sizeof(unkStruct_203B2B8), 8);
    sUnknown_203B2B8->pokeStruct = pokeStruct;

    for (i = 0; i < NUM_MONSTERS; i++) {
        if (sUnknown_203B2B8->pokeStruct == &gRecruitedPokemonRef->pokemon[(s16)i]) {
            sUnknown_203B2B8->pokeSpecies = i;
            break;
        }
    }

    sUnknown_203B2B8->menuAction1 = 0;
    sUnknown_203B2B8->menuAction2 = 0;
    sUnknown_203B2B8->menuAction3 = 0;
    sUnknown_203B2B8->unk8 = FALSE;
    SetPartyListMenuState(PARTY_LIST_STATE_INIT);
    return TRUE;
}

u32 sub_8025F68(void)
{
    switch (sUnknown_203B2B8->state) {
        case PARTY_LIST_STATE_INIT:
            SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU);
            break;
        case PARTY_LIST_STATE_MAIN_MENU:
        case PARTY_LIST_STATE_MAIN_MENU_1:
            PartyListMenu_HandleMenu1();
            break;
        case PARTY_LIST_STATE_SUMMARY:
            sub_8026A78();
            break;
        case PARTY_LIST_STATE_CHECK_IQ:
            sub_8026A94();
            break;
        case PARTY_LIST_STATE_SAY_FAREWELL:
            sub_8026AB0();
            break;
        case PARTY_LIST_STATE_CONFIRM_SAY_FAREWELL:
            sub_8026B10();
            break;
        case PARTY_LIST_STATE_GIVE_GUMMI:
            sub_8026B48();
            break;
        case PARTY_LIST_STATE_GIVE_ITEM:
        case PARTY_LIST_STATE_GIVE_ITEM_1:
            sub_8026B64();
            break;
        case 0x14:
            PartyListMenu_HandleMenu2();
            break;
        case 0x15:
            sub_8026CF0();
            break;
        case PARTY_LIST_STATE_MOVES:
        case 0x17:
            sub_8026D0C();
            break;
        case 0x18:
            sub_8026D6C();
            break;
        default:
            PartyListMenu_GotoFallbackState();
            break;
        case PARTY_LIST_STATE_EXIT:
            return 3;
    }
    return 0;
}

bool8 sub_802604C(void)
{
    return sUnknown_203B2B8->unk8;
}

void CleanPartyListMenu(void)
{
    TRY_FREE_AND_SET_NULL(sUnknown_203B2B8);
}

static void SetPartyListMenuState(s32 newState)
{
    sUnknown_203B2B8->state = newState;
    sub_802608C();
    HandlePartyListMenuCallback();
}

static void sub_802608C(void)
{
    s32 index;
    RestoreSavedWindows(&sUnknown_203B2B8->unk220);
    switch(sUnknown_203B2B8->state)
    {
        case PARTY_LIST_STATE_MAIN_MENU:
        case PARTY_LIST_STATE_MAIN_MENU_1:
            for(index = 0; index < 4; index++)
            {
                sUnknown_203B2B8->unk220.id[index] = sUnknown_80DD310;
            }
            sUnknown_203B2B8->unk220.id[0] = sUnknown_80DD358;
            sUnknown_203B2B8->unk220.id[3] = sUnknown_80DD370;
            PartyListMenu_CreateMenu1();
            sUnknown_203B2B8->unk220.id[2] = sUnknown_80DD328;
            sub_8012CAC(&sUnknown_203B2B8->unk220.id[2], sUnknown_203B2B8->unk16C);
            sUnknown_203B2B8->unk220.id[2].width = 9;
            break;
        case 0x14:
            PartyListMenu_CreateMenu2();
            sUnknown_203B2B8->unk220.id[2] = sUnknown_80DD340;
            sub_8012CAC(&sUnknown_203B2B8->unk220.id[2], sUnknown_203B2B8->unk16C);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                sUnknown_203B2B8->unk220.id[index] = sUnknown_80DD310;
            }
            break;
    }
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2B8->unk220, TRUE, TRUE);
}

static void HandlePartyListMenuCallback(void)
{
    Item item;

    switch(sUnknown_203B2B8->state) {
        case PARTY_LIST_STATE_MAIN_MENU:
            sub_8026E08(3);
            sub_8026DAC(0,&sUnknown_203B2B8->item2);
            PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0],sUnknown_203B2B8->pokeStruct,7);
            PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[1],sUnknown_203B2B8->pokeStruct,6);
            sub_8012D60(&sUnknown_203B2B8->unk7C,sUnknown_203B2B8->unk16C,0,sUnknown_203B2B8->unk20C,sUnknown_203B2B8->menuAction1,2);
            break;
        case PARTY_LIST_STATE_MAIN_MENU_1:
            sub_8026E08(3);
            sub_8026DAC(0,&sUnknown_203B2B8->item2);
            PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0],sUnknown_203B2B8->pokeStruct,7);
            PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[1],sUnknown_203B2B8->pokeStruct,6);
            sub_8012EA4(&sUnknown_203B2B8->unk7C,1);
            break;
        case PARTY_LIST_STATE_SUMMARY:
            sub_8024458(sUnknown_203B2B8->pokeSpecies,2);
            break;
        case PARTY_LIST_STATE_CHECK_IQ:
            CreateIQSkillMenu(sUnknown_203B2B8->pokeSpecies);
            break;
        case PARTY_LIST_STATE_GIVE_GUMMI:
            sub_80227B8(sUnknown_203B2B8->pokeStruct);
            break;
        case PARTY_LIST_STATE_GIVE_ITEM:
            sub_801A5D8(1,0,NULL,10);
            break;
        case PARTY_LIST_STATE_GIVE_ITEM_1:
            sub_801A8D0(TRUE);
            break;
        case 0x14:
            sub_801A9E0();
            sub_8012D60(&sUnknown_203B2B8->unkCC,sUnknown_203B2B8->unk16C,0,sUnknown_203B2B8->unk20C,sUnknown_203B2B8->menuAction2,2);
            break;
        case 0x15:
            BulkItemToItem(&item,&sUnknown_203B2B8->item1);
            InitItemDescriptionWindow(&item);
            break;
        case PARTY_LIST_STATE_MOVES:
            unk_CopyMoves4To8(sUnknown_203B2B8->moves,sUnknown_203B2B8->pokeStruct->moves);
            sub_801EE10(3,sUnknown_203B2B8->pokeSpecies,sUnknown_203B2B8->moves,0,NULL,0);
            break;
        case 0x17:
            sub_801F1B0(TRUE, FALSE);
            break;
        case PARTY_LIST_STATE_SAY_FAREWELL:
            PartyListMenu_BuildYesNoMenu();
            CreateMenuDialogueBoxAndPortrait(sUnknown_80DD388,0,3,sUnknown_203B2B8->unk1BC,0,4,0,0,0x101);
            break;
        case PARTY_LIST_STATE_CONFIRM_SAY_FAREWELL:
            PartyListMenu_BuildYesNoMenu();
            CreateMenuDialogueBoxAndPortrait(sUnknown_80DD420,0,3,sUnknown_203B2B8->unk1BC,0,4,0,0,0x101);
            break;
        case 0x18:
            GetLinkedSequence(sUnknown_203B2B8->moveIndex, sUnknown_203B2B8->moves,sUnknown_203B2B8->moveIDs);
            sub_801F808(sUnknown_203B2B8->moveIDs);
            break;
        case PARTY_LIST_STATE_JOIN_TEAM:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_EXIT;
            PlaySound(0xcf);
            CreateDialogueBoxAndPortrait(sUnknown_80DD4C4,0,0,0x101);
            break;
        case PARTY_LIST_STATE_STANDBY:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_EXIT;
            PlaySound(0xcf);
            CreateDialogueBoxAndPortrait(sUnknown_80DD4F4,0,0,0x101);
            break;
        case PARTY_LIST_STATE_MAKE_LEADER:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_EXIT;
            PlaySound(0xcc);
            CreateDialogueBoxAndPortrait(sBecameLeader,0,0,0x101);
            break;
        case PARTY_LIST_STATE_POKEMON_FAREWELL:
            sUnknown_203B2B8->fallbackState = 9;
            PlaySound(0xca);
            CreateDialogueBoxAndPortrait(sUnknown_80DD564,0,0,0x101);
            break;
        case 9:
            sub_8026FA4();
            sub_808D31C(sUnknown_203B2B8->pokeStruct);
            sUnknown_203B2B8->unk8 = TRUE;
            break;
        case PARTY_LIST_STATE_GIVEN_ITEM:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_MAIN_MENU_1;
            CreateDialogueBoxAndPortrait(sUnknown_80DD594,0,0,0x101);
            break;
        case PARTY_LIST_STATE_GIVEN_ITEM_HELD_ITEM:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_MAIN_MENU_1;
            CreateDialogueBoxAndPortrait(sUnknown_80DD5B8,0,0,0x101);
            break;
        case PARTY_LIST_STATE_TAKE_ITEM:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_MAIN_MENU_1;
            CreateDialogueBoxAndPortrait(sUnknown_80DD60C,0,0,0x101);
            break;
        case 10:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_EXIT;
            CreateDialogueBoxAndPortrait(sUnknown_80DD60C,0,0,0x101);
            break;
        case 0xb:
            sUnknown_203B2B8->fallbackState = PARTY_LIST_STATE_EXIT;
            CreateDialogueBoxAndPortrait(sUnknown_80DD63C,0,0,0x101);
            break;
        case PARTY_LIST_STATE_INIT:
        case PARTY_LIST_STATE_EXIT:
            break;
    }
}

static void PartyListMenu_CreateMenu1(void)
{
    Pokemon *pokeStruct;
    s32 index;
    s32 loopMax = 0;
    pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B2B8->pokeSpecies];
    MemoryFill16(sUnknown_203B2B8->unk20C, 0, sizeof(sUnknown_203B2B8->unk20C));
    sUnknown_203B2B8->isTeamLeader = sUnknown_203B2B8->pokeStruct->isTeamLeader;

    PeekPokemonItem(sUnknown_203B2B8->pokeSpecies, &sUnknown_203B2B8->item2);

    if (PokemonFlag2(pokeStruct))
    {
        sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuStandBy;
        sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_STANDBY;
        if(!sub_8026E88(pokeStruct))
        {
            sUnknown_203B2B8->unk20C[loopMax] = 1;
        }
        loopMax += 1;

        if(sub_80023E4(8) && !pokeStruct->isTeamLeader)
        {
            sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuMakeLeader;
            sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_MAKE_LEADER;
            loopMax += 1;
        }
    }
    else
    {
        sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuJoinTeam;
        sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_JOIN_TEAM;
        if(!sub_808D750(sUnknown_203B2B8->pokeSpecies))
        {
            sUnknown_203B2B8->unk20C[loopMax] = 1;
        }
        loopMax += 1;
    }

    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuGiveGummi;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_GIVE_GUMMI;
    if(!HasGummiItem())
    {
        sUnknown_203B2B8->unk20C[loopMax] = 1;
    }
    loopMax += 1;

    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuGive;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_GIVE_ITEM;
    if(GetNumberOfFilledInventorySlots() == 0)
    {
        sUnknown_203B2B8->unk20C[loopMax] = 1;
    }
    loopMax += 1;

    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuTake;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_TAKE_ITEM;
    if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE || sUnknown_203B2B8->item2.id == ITEM_NOTHING)
    {
        sUnknown_203B2B8->unk20C[loopMax] = 1;
    }
    loopMax += 1;

    if (!PokemonFlag2(pokeStruct))
    {
        sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuSayFarewell;
        sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_SAY_FAREWELL;
        if(!sub_8026EB8(pokeStruct))
        {
            sUnknown_203B2B8->unk20C[loopMax] = 1;
        }
        loopMax += 1;
    }

    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuSummary;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_SUMMARY;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuMoves;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_MOVES;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuCheckIQ;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_CHECK_IQ;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = NULL;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_NULL;

    for(index = 0; index < loopMax; index++)
    {
        if(sUnknown_203B2B8->unk20C[index] == 0)
        {
            if(sUnknown_203B2B8->unk16C[index].menuAction == sUnknown_203B2B8->menuAction1)
                return;
        }
    }
    for(index = 0; index < loopMax; index++)
    {
        if(sUnknown_203B2B8->unk20C[index] == 0)
        {
            sUnknown_203B2B8->menuAction1 = sUnknown_203B2B8->unk16C[index].menuAction;
            break;
        }
    }
}

static void PartyListMenu_CreateMenu2(void)
{
    s32 index;
    s32 loopMax = 0;
    MemoryFill16(sUnknown_203B2B8->unk20C, 0, sizeof(sUnknown_203B2B8->unk20C));
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuGive;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_GIVE_ITEM;
    if(GetNumberOfFilledInventorySlots() == 0)
    {
        sUnknown_203B2B8->unk20C[0] = 1;
    }
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = gCommonInfo[0];
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_INFO;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = NULL;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = PARTY_LIST_MENU_NULL;

    for(index = 0; index < loopMax; index++)
    {
        if(sUnknown_203B2B8->unk20C[index] == 0)
        {
            if(sUnknown_203B2B8->unk16C[index].menuAction == sUnknown_203B2B8->menuAction2)
                return;
        }
    }
    for(index = 0; index < loopMax; index++)
    {
        if(sUnknown_203B2B8->unk20C[index] == 0)
        {
            sUnknown_203B2B8->menuAction2 = sUnknown_203B2B8->unk16C[index].menuAction;
            break;
        }
    }
}

static void PartyListMenu_BuildYesNoMenu(void)
{
    s32 loopMax = 0;
    sUnknown_203B2B8->unk1BC[loopMax].text = gCommonYes[0];
    sUnknown_203B2B8->unk1BC[loopMax].menuAction = PARTY_LIST_MENU_YES;
    loopMax += 1;
    sUnknown_203B2B8->unk1BC[loopMax].text = gCommonNo[0];
    sUnknown_203B2B8->unk1BC[loopMax].menuAction = PARTY_LIST_MENU_NO;
    loopMax += 1;
    sUnknown_203B2B8->unk1BC[loopMax].text = NULL;
    sUnknown_203B2B8->unk1BC[loopMax].menuAction = PARTY_LIST_MENU_NULL;
}

static void PartyListMenu_HandleMenu1(void)
{
  Pokemon *playerPokemon;
  Pokemon *newLeader;
  s32 choice;

  choice = 0;
  if ((sub_8012FD8(&sUnknown_203B2B8->unk7C) == 0) && (sub_8013114(&sUnknown_203B2B8->unk7C,&choice), choice != PARTY_LIST_MENU_NULL)) {
    sUnknown_203B2B8->menuAction1 = choice;
  }
  switch(choice) {
    case PARTY_LIST_MENU_JOIN_TEAM:
        if (sub_808D750(sUnknown_203B2B8->pokeSpecies)) {
            SetPokemonFlag2(&sUnknown_203B2B8->pokeSpecies[gRecruitedPokemonRef->pokemon]);
            nullsub_104();
        }
        sub_808ED00();
        SetPartyListMenuState(PARTY_LIST_STATE_JOIN_TEAM);
        break;
    case PARTY_LIST_MENU_STANDBY:
        sUnknown_203B2B8->pokeStruct->flags &= ~(POKEMON_FLAG_ON_TEAM);
        nullsub_104();
        sub_808ED00();
        SetPartyListMenuState(PARTY_LIST_STATE_STANDBY);
        break;
    case PARTY_LIST_MENU_MAKE_LEADER:
        newLeader = &gRecruitedPokemonRef->pokemon[sUnknown_203B2B8->pokeSpecies];
        playerPokemon = GetPlayerPokemonStruct();

        if (!newLeader->isTeamLeader) {
            playerPokemon->isTeamLeader = FALSE;
            newLeader->isTeamLeader = TRUE;
            nullsub_104();
        }
        sub_808ED00();
        SetPartyListMenuState(PARTY_LIST_STATE_MAKE_LEADER);
        break;
    case PARTY_LIST_MENU_SAY_FAREWELL:
        SetPartyListMenuState(PARTY_LIST_STATE_SAY_FAREWELL);
        break;
    case PARTY_LIST_MENU_MOVES:
        SetPartyListMenuState(PARTY_LIST_STATE_MOVES);
        break;
    case PARTY_LIST_MENU_GIVE_GUMMI:
        SetPartyListMenuState(PARTY_LIST_STATE_GIVE_GUMMI);
        break;
    case PARTY_LIST_MENU_GIVE_ITEM:
        SetPartyListMenuState(PARTY_LIST_STATE_GIVE_ITEM);
        break;
    case PARTY_LIST_MENU_TAKE_ITEM:
        PlaySound(0x14d);
        if (sUnknown_203B2B8->item2.id != ITEM_NOTHING) {
            AddHeldItemToInventory(&sUnknown_203B2B8->item2);
        }
        FillInventoryGaps();
        sUnknown_203B2B8->item2.id = ITEM_NOTHING;
        sUnknown_203B2B8->item2.quantity = 0;
        GivePokemonItem(sUnknown_203B2B8->pokeSpecies,&sUnknown_203B2B8->item2);
        nullsub_104();
        SetPartyListMenuState(PARTY_LIST_STATE_TAKE_ITEM);
        break;
    case PARTY_LIST_MENU_SUMMARY:
        SetPartyListMenuState(PARTY_LIST_STATE_SUMMARY);
        break;
    case PARTY_LIST_MENU_CHECK_IQ:
        SetPartyListMenuState(PARTY_LIST_STATE_CHECK_IQ);
        break;
    case PARTY_LIST_MENU_NULL:
        SetPartyListMenuState(PARTY_LIST_STATE_EXIT);
        break;

  }
}

static void sub_8026A78(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU_1);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8026A94(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            CleanIQSkillMenu();
            SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU_1);
            break;
        case 0:
        case 1:
            break;
    }
}

static inline bool8 sub_8026AB0_sub(void) {
    if (sUnknown_203B2B8->pokeStruct->dungeonLocation.id == DUNGEON_HOWLING_FOREST_2 || sUnknown_203B2B8->pokeStruct->dungeonLocation.id == DUNGEON_POKEMON_SQUARE)
        return TRUE;
    else
        return FALSE;
}

static void sub_8026AB0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
            case 3:
                SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU_1);
                break;
            case 2:
                if (sub_8026AB0_sub())
                    SetPartyListMenuState(PARTY_LIST_STATE_CONFIRM_SAY_FAREWELL);
                else
                    SetPartyListMenuState(PARTY_LIST_STATE_POKEMON_FAREWELL);
                break;
        }
    }
}

static void sub_8026B10(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
            case 3:
                SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU_1);
                break;
            case 2:
                SetPartyListMenuState(PARTY_LIST_STATE_POKEMON_FAREWELL);
                break;
        }
    }
}

static void sub_8026B48(void)
{
    switch(sub_8022860())
    {
        case 2:
        case 3:
            sub_8022908();
            SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU_1);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8026B64(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            sUnknown_203B2B8->id = sub_801A8AC();
            sUnknown_203B2B8->item1.id = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].id;
            sUnknown_203B2B8->item1.quantity = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].quantity;
            SetPartyListMenuState(0x14);
            break;
        case 4:
            sUnknown_203B2B8->id = sub_801A8AC();
            sUnknown_203B2B8->item1.id = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].id;
            sUnknown_203B2B8->item1.quantity = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].quantity;
            sub_8099690(0);
            SetPartyListMenuState(0x15);
            break;
        case 2:
            sub_801A928();
            SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU_1);
            break;
        case 0:
        case 1:
            break;
    }
}

static void PartyListMenu_HandleMenu2(void)
{
  u32 nextState;
  struct unkStruct_8090F58 temp;
  s32 menuAction;
  Item slot;

  menuAction = 0;
  sub_801A6E8(FALSE);
  if ((sub_8012FD8(&sUnknown_203B2B8->unkCC) == '\0') && (sub_8013114(&sUnknown_203B2B8->unkCC,&menuAction), menuAction != PARTY_LIST_MENU_NULL)) {
    sUnknown_203B2B8->menuAction2 = menuAction;
  }
  switch(menuAction)
  {
      case PARTY_LIST_MENU_GIVE_ITEM:
        nextState = PARTY_LIST_STATE_GIVEN_ITEM;
        PlaySound(0x14d);
        ShiftItemsDownFrom(sUnknown_203B2B8->id);
        FillInventoryGaps();
        if (sUnknown_203B2B8->item2.id != ITEM_NOTHING) {
          AddHeldItemToInventory(&sUnknown_203B2B8->item2);
          nextState = PARTY_LIST_STATE_GIVEN_ITEM_HELD_ITEM;
        }
        BulkItemToItem(&slot,&sUnknown_203B2B8->item1);
        temp.unk0 = 0;
        temp.unk4 = 0;
        temp.unk8 = 1;
        slot.flags = ITEM_FLAG_EXISTS;
        sub_8090E14(gFormatBuffer_Items[1],&slot,&temp);
        GivePokemonItem(sUnknown_203B2B8->pokeSpecies,&sUnknown_203B2B8->item1);
        sub_801A928();
        nullsub_104();
        SetPartyListMenuState(nextState);
        break;
      case PARTY_LIST_MENU_INFO:
        sub_8099690(0);
        SetPartyListMenuState(0x15);
        break;
      case PARTY_LIST_MENU_NULL:
        SetPartyListMenuState(PARTY_LIST_STATE_GIVE_ITEM_1);
        break;
  }
}

static void sub_8026CF0(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            SetPartyListMenuState(PARTY_LIST_STATE_GIVE_ITEM_1);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8026D0C(void)
{
    switch(sub_801EF38(1))
    {
        case 0:
        case 1:
            break;
        case 3:
        case 4:
            sUnknown_203B2B8->moveIndex = sub_801F194();
            sUnknown_203B2B8->moveID = sUnknown_203B2B8->moves[sUnknown_203B2B8->moveIndex].id;
            SetPartyListMenuState(0x18);
            break;
        case 2:
            sub_801F214();
            SetPartyListMenuState(PARTY_LIST_STATE_MAIN_MENU_1);
            break;
    }
}

static void sub_8026D6C(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            SetPartyListMenuState(0x17);
            break;
        case 0:
        case 1:
            break;
    }
}

static void PartyListMenu_GotoFallbackState(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetPartyListMenuState(sUnknown_203B2B8->fallbackState);
    }
}

static void sub_8026DAC(u32 r0, BulkItem *item)
{
    Item slot;
    struct unkStruct_8090F58 temp;

    CallPrepareTextbox_8008C54(r0);
    sub_80073B8(r0);
    BulkItemToItem(&slot, item);
    temp.unk0 = 0;
    temp.unk4 = 0;
    temp.unk8 = 1;
    slot.flags = ITEM_FLAG_EXISTS;
    sub_8090E14(gFormatBuffer_Items[0], &slot, &temp);
    PrintFormattedStringOnWindow(4, 3, sPartyMenuItemPlaceholder, r0, 0);
    sub_80073E0(r0);
}

static void sub_8026E08(u32 r0)
{
    u8 buffer1[40];
    u8 buffer[20];
    s32 x;

    CallPrepareTextbox_8008C54(r0);
    sub_80073B8(r0);
    StrncpyCustom(gFormatBuffer_Monsters[0], sUnknown_203B2B8->pokeStruct->name, POKEMON_NAME_LENGTH);
    sub_808D930(buffer, sUnknown_203B2B8->pokeStruct->speciesNum);
    sprintfStatic(buffer1, sUnknown_80DD6E0, gFormatBuffer_Monsters[0]);
    x = GetStringLineWidth(buffer1);
    PrintStringOnWindow(((sUnknown_80DD370.width << 3) - x) / 2, 3, buffer1, r0, 0);
    sub_80073E0(r0);
}

static bool8 sub_8026E88(Pokemon *r0)
{
    bool8 flag;
    if(!r0->isTeamLeader)
    {
        flag = (r0->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER);
        if(flag)
            if(!sub_80023E4(0x8))
                return FALSE;
    }
    else
        return FALSE;
    return TRUE;
}

static bool8 sub_8026EB8(Pokemon *r0)
{
    bool8 flag;
    if(sub_808D3BC() != r0)
        if(sub_808D3F8() != r0)
            if(!r0->isTeamLeader)
            {
                flag = (r0->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER);
                if(flag)
                {
                    if(sub_80023E4(0x8))
                        goto check;
                }
                else
                    check:
                    if(sub_8026F04(r0) != 3)
                        return TRUE;
            }
    return FALSE;
}

static u32 sub_8026F04(Pokemon *r0)
{
    if(r0->heldItem.id == ITEM_NOTHING)
        return 0;
    else if(GetNumberOfFilledInventorySlots() < INVENTORY_SIZE)
        return 1;
    else if(CanTakePokemonHeldItem(r0))
        return 2;
    else
        return 3;
}

static bool8 CanTakePokemonHeldItem(Pokemon *r0)
{
    if(IsNotMoneyOrUsedTMItem(r0->heldItem.id))
    {
        if(IsThrownItem(r0->heldItem.id))
        {
            if((gTeamInventoryRef->teamStorage[r0->heldItem.id] + r0->heldItem.quantity) > 999)
                return FALSE;
        }
        else
        {
            if(gTeamInventoryRef->teamStorage[r0->heldItem.id] > 998)
                return FALSE;
        }
    }
    else
        return FALSE;
    return TRUE;
}

static void sub_8026FA4(void)
{
    switch(sub_8026F04(sUnknown_203B2B8->pokeStruct))
    {
        case 1:
            PlaySound(0x14d);
            AddHeldItemToInventory(&sUnknown_203B2B8->item2);
            FillInventoryGaps();
            sUnknown_203B2B8->item2.id = ITEM_NOTHING;
            sUnknown_203B2B8->item2.quantity = 0;
            GivePokemonItem(sUnknown_203B2B8->pokeSpecies, &sUnknown_203B2B8->item2);
            SetPartyListMenuState(0xA);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrownItem(sUnknown_203B2B8->item2.id))
            {
                gTeamInventoryRef->teamStorage[sUnknown_203B2B8->item2.id] += sUnknown_203B2B8->item2.quantity;
            }
            else
            {
                gTeamInventoryRef->teamStorage[sUnknown_203B2B8->item2.id] += 1;
            }

            sUnknown_203B2B8->item2.id = ITEM_NOTHING;
            sUnknown_203B2B8->item2.quantity = 0;
            GivePokemonItem(sUnknown_203B2B8->pokeSpecies, &sUnknown_203B2B8->item2);
            SetPartyListMenuState(0xB);
            break;
        case 0:
        default:
            SetPartyListMenuState(PARTY_LIST_STATE_EXIT);
            break;
    }
}
