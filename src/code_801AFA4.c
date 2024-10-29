#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "code_801AFA4.h"
#include "code_8099360.h"
#include "gulpin_shop.h"
#include "memory.h"
#include "moves.h"
#include "pokemon_mid.h"

static EWRAM_DATA_2 unkStruct_203B22C *sUnknown_203B22C = {0};

#include "data/code_801AFA4.h"

static s32 GetNumMonsAbleToLearnItemMove(void);
static void nullsub_37(void);

static void sub_801B064(s32);
static void sub_801B080(void);
static void sub_801B178(void);
static void sub_801B200(void);
static void sub_801B2AC(void);
static void sub_801B2D8(void);

bool8 sub_801AFA4(u32 index)
{
    sUnknown_203B22C = MemoryAlloc(sizeof(unkStruct_203B22C), 8);
    sUnknown_203B22C->teamItemIndex = index;
    sUnknown_203B22C->id = gTeamInventoryRef->teamItems[index].id;
    sUnknown_203B22C->moveID = GetItemMoveID(sUnknown_203B22C->id);
    sub_8092C84(gAvailablePokemonNames[7], sUnknown_203B22C->moveID);
    sub_8099690(0);

    if (GetNumMonsAbleToLearnItemMove() == 0)
        sub_801B064(3);
    else {
        sUnknown_203B22C->unk60 = 4;
        sub_801B064(0);
    }
    return TRUE;
}

u32 sub_801B00C(void)
{
    switch (sUnknown_203B22C->state) {
        case 4:
            return 3;
        case 0:
            sub_801B200();
            break;
        case 1:
            sub_801B2AC();
            break;
        default:
            sub_801B2D8();
            break;
    }
    return 0;
}

void sub_801B048(void)
{
    if (sUnknown_203B22C != NULL) {
        MemoryFree(sUnknown_203B22C);
        sUnknown_203B22C = NULL;
    }
}

static void sub_801B064(s32 newState)
{
    sUnknown_203B22C->state = newState;
    nullsub_37();
    sub_801B080();
}

static void nullsub_37(void)
{
}

static void sub_801B080(void)
{
    switch (sUnknown_203B22C->state) {
        case 0:
            sub_801B178();
            CreateMenuDialogueBoxAndPortrait(sFmtWhoWillLearnTheMove, 0, sUnknown_203B22C->unk60, sUnknown_203B22C->menuItems, 0, 4, 0, NULL, 32);
            break;
        case 1:
            CreateGulpinShop(2, sUnknown_203B22C->chosenPokemon, sUnknown_203B22C->moves);
            break;
        case 2:
            sub_8094060(sUnknown_203B22C->moves, sUnknown_203B22C->pokeStruct->moves);
            if (!IsHMItem(sUnknown_203B22C->id)) {
                gTeamInventoryRef->teamItems[sUnknown_203B22C->teamItemIndex].quantity = sUnknown_203B22C->id - 125;
                gTeamInventoryRef->teamItems[sUnknown_203B22C->teamItemIndex].id = ITEM_TM_USED_TM;
            }
            PlaySound(312);
            CreateDialogueBoxAndPortrait(sFmtLearnedTheMove, 0, 0, 0x121);
            break;
        case 3:
            CreateDialogueBoxAndPortrait(sFmtNoOneCanLearnThisMove, 0, 0, 0x121);
            break;
        default:
        case 4:
            break;
    }
}

static void sub_801B178(void)
{
    s32 monIndex;
    u8 *bufferPtr;

    for (monIndex = 0; monIndex < sUnknown_203B22C->monsAbleToLearnMove; monIndex++) {
        bufferPtr = gAvailablePokemonNames[monIndex];
        PrintPokeNameToBuffer(bufferPtr, &gRecruitedPokemonRef->pokemon[sUnknown_203B22C->unk50[monIndex]]);
        sUnknown_203B22C->menuItems[monIndex].text = bufferPtr;
        sUnknown_203B22C->menuItems[monIndex].menuAction = monIndex + 4;
    }

    sUnknown_203B22C->menuItems[monIndex].text = NULL;
    sUnknown_203B22C->menuItems[monIndex].menuAction = 1;
}

static void sub_801B200(void)
{
    s32 temp;
    s32 moveIndex;
    Move *pokeMove;

    if (sub_80144A4(&temp))
        return;

    sUnknown_203B22C->unk60 = temp;
    switch (temp) {
        case 1:
            sub_801B064(4);
            break;
        default:
            sUnknown_203B22C->chosenPokemon = sUnknown_203B22C->unk50[temp - 4];
            sUnknown_203B22C->pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B22C->chosenPokemon];
            PrintPokeNameToBuffer(gAvailablePokemonNames[8], sUnknown_203B22C->pokeStruct);
            unk_CopyMoves4To8(sUnknown_203B22C->moves, sUnknown_203B22C->pokeStruct->moves);

            for (moveIndex = 0; moveIndex < MAX_MON_MOVES * 2; moveIndex++) {
                pokeMove = &sUnknown_203B22C->moves[moveIndex];

                if ((pokeMove->moveFlags & MOVE_FLAG_EXISTS) == 0) {
                    InitZeroedPPPokemonMove(pokeMove, sUnknown_203B22C->moveID);
                    break;
                }
            }

            if (moveIndex >= MAX_MON_MOVES)
                sub_801B064(1);
            else
                sub_801B064(2);
            break;
        case 0:
            break;
    }
}

static void sub_801B2AC(void)
{
    switch (sub_801E8C0()) {
        case 3:
            DestroyGulpinShop();
            sub_801B064(2);
            break;
        case 2:
            DestroyGulpinShop();
            sub_801B064(0);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_801B2D8(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sub_801B064(4);
}

static s32 GetNumMonsAbleToLearnItemMove(void)
{
    s32 length;
    s32 numMons;
    s32 i;
    s32 team[MAX_TEAM_MEMBERS];
    PokemonStruct1 *preload;

    length = sub_808D580(team);
    sUnknown_203B22C->monsAbleToLearnMove = 0;

    for (i = 0; i < length; i++) {
        preload = &gRecruitedPokemonRef->pokemon[team[i]];

        if (CanMonLearnMove(sUnknown_203B22C->moveID, preload->speciesNum)) {
            sUnknown_203B22C->unk50[sUnknown_203B22C->monsAbleToLearnMove] = team[i];
            numMons = sUnknown_203B22C->monsAbleToLearnMove;
            if (numMons >= MAX_TEAM_MEMBERS)
                break;
            sUnknown_203B22C->monsAbleToLearnMove = numMons + 1;
        }
    }
    return sUnknown_203B22C->monsAbleToLearnMove;
}

UNUSED static bool8 sub_801B374(u8 id)
{
    u16 moveID;
    PokemonStruct1 *pokeStruct;
    s32 i;

    pokeStruct = &gRecruitedPokemonRef->pokemon[0];
    moveID = GetItemMoveID(id);

    for (i = 0; i < NUM_MONSTERS; i++, pokeStruct++) {
        if ((pokeStruct->unk0 >> 1) & 1)
            if (CanMonLearnMove(moveID, pokeStruct->speciesNum))
                return FALSE;
    }
    return TRUE;
}
