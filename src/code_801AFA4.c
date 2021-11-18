#include "global.h"
#include "memory.h"
#include "text.h"
#include "item.h"
#include "team_inventory.h"
#include "menu.h"
#include "pokemon.h"

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

extern void InitZeroedPPPokemonMove(struct PokemonMove*, u16);
extern void sub_809401C(struct PokemonMove *, struct PokemonMove *);
extern bool8 IsHMItem(u8);
extern void DisplayGulpinDialogueSprite(u32, u32, void *);
extern void sub_801B178(void);
extern void sub_8094060(void *, struct PokemonMove *);
extern void PlaySound(u32);
extern void sub_80141B4(u32 *, u32, u32 ,u32);
extern void sub_8014248(u32 *, u32, u32, struct MenuItem *, u32, u32, u32, u32, u32);
extern void sub_808DA34(u8 *buffer, struct PokemonStruct *pokemon);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801E8C0(void);
extern void sub_801E93C(void);

extern bool8 CanMonLearnMove(u16 moveID, s16 _species);
extern s32 sub_808D580(s32*);

struct unkStruct_203B22C
{
    // size: 0xa4
    /* 0x0 */ s32 state;
    /* 0x4 */ u32 teamItemIndex;
    /* 0x8 */ u8 itemIndex; // item index
    /* 0xA */ u16 moveID; // item move??
    /* 0xC */ struct PokemonMove moves[MAX_MON_MOVES * 2];
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
    gUnknown_203B22C->itemIndex = gTeamInventory_203B460->teamItems[index].itemIndex;
    gUnknown_203B22C->moveID = GetItemMove(gUnknown_203B22C->itemIndex);
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
            // #+Who will learn the move
            // #+{COLOR_1 CYAN}$m7{END_COLOR_TEXT_1}?
            sub_8014248(&gUnknown_80DB9BC, 0, gUnknown_203B22C->unk60, gUnknown_203B22C->menuItems, 0, 4, 0, 0, 0x20);
            break;
        case 1:
            DisplayGulpinDialogueSprite(2, gUnknown_203B22C->chosenPokemon, gUnknown_203B22C->moves);
            break;
        case 2:
            sub_8094060(gUnknown_203B22C->moves, gUnknown_203B22C->pokeStruct->moves);
            if(!IsHMItem(gUnknown_203B22C->itemIndex))
            {
                gTeamInventory_203B460->teamItems[gUnknown_203B22C->teamItemIndex].numItems = gUnknown_203B22C->itemIndex - 0x7D;
                gTeamInventory_203B460->teamItems[gUnknown_203B22C->teamItemIndex].itemIndex = ITEM_ID_USED_TM;
            }
            PlaySound(0x9C << 1);
            // #+CM$m8{END_COLOR_TEXT_1} learned
            // #+the move {COLOR_1 CYAN}$m7{END_COLOR_TEXT_1}!
            sub_80141B4(&gUnknown_80DB9E4, 0, 0, 0x121);
            break;
        case 3:
            // #+No one in the current team
            // #+can learn this move.
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
        sub_808DA34(bufferPtr, &gRecruitedPokemonRef->pokemon[gUnknown_203B22C->unk50[monIndex]]);
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
    struct PokemonMove *pokeMove;

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
                sub_808DA34(gUnknown_202E218, gUnknown_203B22C->pokeStruct);
                sub_809401C(gUnknown_203B22C->moves, gUnknown_203B22C->pokeStruct->moves);
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
            sub_801E93C();
            sub_801B064(2);
            break;
        case 2:
            sub_801E93C();
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
    s32 iVar4;
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
            iVar4 = gUnknown_203B22C->monsAbleToLearnMove;
            if (iVar4 >= MAX_TEAM_MEMBERS) break;
            gUnknown_203B22C->monsAbleToLearnMove = iVar4 + 1;
        }
    }
    return gUnknown_203B22C->monsAbleToLearnMove;
}
