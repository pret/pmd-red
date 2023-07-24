#include "global.h"
#include "memory.h"
#include "text.h"
#include "item.h"
#include "team_inventory.h"
#include "menu.h"
#include "pokemon.h"
#include "gulpin_shop.h"

extern void sub_8092C84(u8 *, u16);
extern void sub_8099690(u32);
extern s32 GetNumMonsAbleToLearnItemMove(void);
extern void sub_801B064(s32);


extern void sub_801B200(void);
extern void sub_801B2AC(void);
extern void sub_801B2D8(void);
extern void nullsub_37();
extern void sub_801B080();

extern u32 gUnknown_80DB9BC;
extern u32 gUnknown_80DB9E4;
extern u32 gUnknown_80DBA0C;

extern u8 gUnknown_202E1C8[0x50];
extern u8 gAvailablePokemonNames[0x50];
extern u8 gUnknown_202E218[0x50];

extern void InitZeroedPPPokemonMove(struct Move*, u16);
extern void unk_CopyMoves4To8(struct Move *, struct Move *);
extern bool8 IsHMItem(u8);
extern void sub_801B178(void);
extern void sub_8094060(void *, struct Move *);
extern void PlaySound(u32);
extern void sub_80141B4(u32 *, u32, u32 ,u32);
extern void sub_8014248(u32 *, u32, u32, struct MenuItem *, u32, u32, u32, u32, u32);
extern void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801E8C0(void);

extern bool8 CanMonLearnMove(u16 moveID, s16 _species);
extern s32 sub_808D580(s32*);

struct unkStruct_203B22C
{
    // size: 0xa4
    /* 0x0 */ s32 state;
    /* 0x4 */ u32 teamItemIndex;
    /* 0x8 */ u8 id; // item index
    /* 0xA */ u16 moveID; // item move??
    /* 0xC */ struct Move moves[MAX_MON_MOVES * 2];
    /* 0x4C */ s32 monsAbleToLearnMove; // number of party members able to learn move
    /* 0x50 */ s16 unk50[MAX_TEAM_MEMBERS]; // species IDs of each member able to learn move
    /* 0x58 */ s16 chosenPokemon; // species of pokemon that will learn move
    /* 0x5C */ struct PokemonStruct *pokeStruct; // PokemonStruct of said pokemon
    u32 unk60;
    /* 0x64 */ struct MenuItem menuItems[8];
};
extern struct unkStruct_203B22C *gUnknown_203B22C;

u32 sub_801AFA4(u32 index)
{
    gUnknown_203B22C = MemoryAlloc(sizeof(struct unkStruct_203B22C), 8);
    gUnknown_203B22C->teamItemIndex = index;
    gUnknown_203B22C->id = gTeamInventory_203B460->teamItems[index].id;
    gUnknown_203B22C->moveID = GetItemMoveID(gUnknown_203B22C->id);
    sub_8092C84(gUnknown_202E1C8, gUnknown_203B22C->moveID);
    sub_8099690(0);
    if(GetNumMonsAbleToLearnItemMove() == 0)
    {
        sub_801B064(3);
    }
    else
    {
        gUnknown_203B22C->unk60 = 4;
        sub_801B064(0);
    }
    return 1;
}

u32 sub_801B00C(void)
{
    switch(gUnknown_203B22C->state)
    {
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
    if(gUnknown_203B22C != NULL)
    {
        MemoryFree(gUnknown_203B22C);
        gUnknown_203B22C = NULL;
    }
}

void sub_801B064(s32 newState)
{
    gUnknown_203B22C->state = newState;
    nullsub_37();
    sub_801B080();
}

void nullsub_37(void)
{
}

void sub_801B080(void)
{
    switch(gUnknown_203B22C->state)
    {
        case 0:
            sub_801B178();
            // {CENTER_ALIGN}Who will learn the move
            // {CENTER_ALIGN}{COLOR_1 CYAN}{ARG_POKEMON_7}{END_COLOR_TEXT_1}?
            sub_8014248(&gUnknown_80DB9BC, 0, gUnknown_203B22C->unk60, gUnknown_203B22C->menuItems, 0, 4, 0, 0, 0x20);
            break;
        case 1:
            CreateGulpinShop(2, gUnknown_203B22C->chosenPokemon, gUnknown_203B22C->moves);
            break;
        case 2:
            sub_8094060(gUnknown_203B22C->moves, gUnknown_203B22C->pokeStruct->moves);
            if(!IsHMItem(gUnknown_203B22C->id))
            {
                gTeamInventory_203B460->teamItems[gUnknown_203B22C->teamItemIndex].quantity = gUnknown_203B22C->id - 0x7D;
                gTeamInventory_203B460->teamItems[gUnknown_203B22C->teamItemIndex].id = ITEM_TM_USED_TM;
            }
            PlaySound(0x9C << 1);
            // {CENTER_ALIGN}CM{ARG_POKEMON_8}{END_COLOR_TEXT_1} learned
            // {CENTER_ALIGN}the move {COLOR_1 CYAN}{ARG_POKEMON_7}{END_COLOR_TEXT_1}!
            sub_80141B4(&gUnknown_80DB9E4, 0, 0, 0x121);
            break;
        case 3:
            // {CENTER_ALIGN}No one in the current team
            // {CENTER_ALIGN}can learn this move.
            sub_80141B4(&gUnknown_80DBA0C, 0, 0, 0x121);
            break;
        default:
        case 4:
            break;
    }
}

void sub_801B178(void)
{
    int monIndex;
    u8 *bufferPtr;

    for(monIndex = 0; monIndex < gUnknown_203B22C->monsAbleToLearnMove; monIndex++)
    {
        bufferPtr = gAvailablePokemonNames + (0x50 * monIndex);
        PrintPokeNameToBuffer(bufferPtr, &gRecruitedPokemonRef->pokemon[gUnknown_203B22C->unk50[monIndex]]);
        gUnknown_203B22C->menuItems[monIndex].text = bufferPtr;
        gUnknown_203B22C->menuItems[monIndex].menuAction = monIndex + 4;
    }
    gUnknown_203B22C->menuItems[monIndex].text = NULL;
    gUnknown_203B22C->menuItems[monIndex].menuAction = 1;
}

void sub_801B200(void)
{
    s32 temp;
    s32 moveIndex;
    struct Move *pokeMove;

    if(sub_80144A4(&temp) == 0)
    {
        gUnknown_203B22C->unk60 = temp;
        switch(temp)
        {
            case 1:
                sub_801B064(4);
                break;
            default:
                gUnknown_203B22C->chosenPokemon = gUnknown_203B22C->unk50[temp - 4];
                gUnknown_203B22C->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B22C->chosenPokemon];
                PrintPokeNameToBuffer(gUnknown_202E218, gUnknown_203B22C->pokeStruct);
                unk_CopyMoves4To8(gUnknown_203B22C->moves, gUnknown_203B22C->pokeStruct->moves);
                for(moveIndex = 0; moveIndex < MAX_MON_MOVES * 2; moveIndex++)
                {
                    pokeMove = &gUnknown_203B22C->moves[moveIndex];
                    if((pokeMove->moveFlags & MOVE_FLAG_EXISTS) == 0)
                    {
                        InitZeroedPPPokemonMove(pokeMove, gUnknown_203B22C->moveID);
                        break;
                    }
                }
                if(moveIndex >= MAX_MON_MOVES)
                    sub_801B064(1);
                else
                    sub_801B064(2);
                break;
            case 0:
                break;
        }
    }
}

void sub_801B2AC(void)
{
    switch(sub_801E8C0())
    {
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


void sub_801B2D8(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        sub_801B064(4);
    }
}

s32 GetNumMonsAbleToLearnItemMove(void)
{
    s32 length;
    s32 numMons;
    s32 index;
    s32 team [MAX_TEAM_MEMBERS];
    struct PokemonStruct *preload;

    length = sub_808D580(team);
    gUnknown_203B22C->monsAbleToLearnMove = 0;

    for(index = 0; index < length; index++)
    {
        preload = &gRecruitedPokemonRef->pokemon[team[index]];
        if (CanMonLearnMove(gUnknown_203B22C->moveID, preload->speciesNum)) {
            gUnknown_203B22C->unk50[gUnknown_203B22C->monsAbleToLearnMove] = team[index];
            numMons = gUnknown_203B22C->monsAbleToLearnMove;
            if (numMons >= MAX_TEAM_MEMBERS) break;
            gUnknown_203B22C->monsAbleToLearnMove = numMons + 1;
        }
    }
    return gUnknown_203B22C->monsAbleToLearnMove;
}

// Unused
bool8 sub_801B374(u8 id)
{
  u16 moveID;
  struct PokemonStruct *pokeStruct;
  s32 index;

  pokeStruct = &gRecruitedPokemonRef->pokemon[0];
  moveID = GetItemMoveID(id);

  for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
  {
      if((pokeStruct->unk0 >> 1 & 1) != 0)
        if(CanMonLearnMove(moveID, pokeStruct->speciesNum))
            return FALSE;
  }
  return TRUE;
}
