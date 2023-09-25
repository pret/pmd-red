#include "global.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801B3C0.h"
#include "code_801BEEC.h"
#include "code_801EE10.h"
#include "code_801EE10_mid.h"
#include "code_80227B8.h"
#include "code_8024458.h"
#include "code_8098BDC.h"
#include "common_strings.h"
#include "constants/dungeon.h"
#include "event_flag.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "party_list_menu.h"
#include "pokemon.h"
#include "text_util.h"
#include "text1.h"
#include "text2.h"

// TODO: Clean this

extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202DEA8[];
extern u8 gAvailablePokemonNames[]; // 202DF98

static EWRAM_DATA_2 unkStruct_203B2B8 *sUnknown_203B2B8 = {0};

#include "data/party_list_menu.h"

extern u32 sub_8026F04(PokemonStruct1 *);
bool8 CanTakePokemonHeldItem(PokemonStruct1 *r0);
extern bool8 sub_808D750(s16 index_);
extern void sub_808ED00(void);
bool8 sub_8026E88(PokemonStruct1 *r0);
bool8 sub_8026EB8(PokemonStruct1 *r0);
void sub_8026E08(u32 r0);
void sub_8026DAC(u32 r0, BulkItem *item);
void sub_8026FA4(void);
void sub_8026878(void);
extern void sub_808D31C(PokemonStruct1 *);

void sub_802678C(void);
void sub_80264CC(void);
void sub_80261D0(void);

void sub_80268CC(void);
void sub_8026A78(void);
void sub_8026A94(void);
void sub_8026AB0(void);
void sub_8026B10(void);
void sub_8026B48(void);
void sub_8026B64(void);
void sub_8026C14(void);
void sub_8026CF0(void);
void sub_8026D0C(void);
void sub_8026D6C(void);
void sub_8026D88(void);

static void sub_8026074(s32 newState);
static void sub_802608C(void);

bool8 sub_8025EF4(PokemonStruct1 *pokeStruct)
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
    sub_8026074(0);
    return TRUE;
}

u32 sub_8025F68(void)
{
    switch (sUnknown_203B2B8->state) {
        case 0:
            sub_8026074(1);
            break;
        case 1:
        case 2:
            sub_80268CC();
            break;
        case 3:
            sub_8026A78();
            break;
        case 4:
            sub_8026A94();
            break;
        case 0xc:
            sub_8026AB0();
            break;
        case 0xd:
            sub_8026B10();
            break;
        case 0xe:
            sub_8026B48();
            break;
        case 0x12:
        case 0x13:
            sub_8026B64();
            break;
        case 0x14:
            sub_8026C14();
            break;
        case 0x15:
            sub_8026CF0();
            break;
        case 0x16:
        case 0x17:
            sub_8026D0C();
            break;
        case 0x18:
            sub_8026D6C();
            break;
        default:
            sub_8026D88();
            break;
        case 0x19:
            return 3;
    }
    return 0;
}

bool8 sub_802604C(void)
{
    return sUnknown_203B2B8->unk8;
}

void sub_8026058(void)
{
    if (sUnknown_203B2B8) {
        MemoryFree(sUnknown_203B2B8);
        sUnknown_203B2B8 = NULL;
    }
}

static void sub_8026074(s32 newState)
{
    sUnknown_203B2B8->state = newState;
    sub_802608C();
    sub_80261D0();
}

static void sub_802608C(void)
{
    s32 index;
    sub_8006518(sUnknown_203B2B8->unk220);
    switch(sUnknown_203B2B8->state)
    {
        case 1:
        case 2:
            for(index = 0; index < 4; index++)
            {
                sUnknown_203B2B8->unk220[index] = sUnknown_80DD310;
            }
            sUnknown_203B2B8->unk220[0] = sUnknown_80DD358;
            sUnknown_203B2B8->unk220[3] = sUnknown_80DD370;
            sub_80264CC();
            sUnknown_203B2B8->unk220[2] = sUnknown_80DD328;
            sub_8012CAC(&sUnknown_203B2B8->unk220[2], sUnknown_203B2B8->unk16C);
            sUnknown_203B2B8->unk220[2].unkC = 9;
            break;
        case 0x14:
            sub_802678C();
            sUnknown_203B2B8->unk220[2] = sUnknown_80DD340;
            sub_8012CAC(&sUnknown_203B2B8->unk220[2], sUnknown_203B2B8->unk16C);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                sUnknown_203B2B8->unk220[index] = sUnknown_80DD310;
            }
            break; 
    }
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2B8->unk220, TRUE, TRUE);
}

void sub_80261D0(void)
{
    Item item;

    switch(sUnknown_203B2B8->state) {
        case 1:
            sub_8026E08(3);
            sub_8026DAC(0,&sUnknown_203B2B8->item2);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames,sUnknown_203B2B8->pokeStruct,7);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames + 0x50,sUnknown_203B2B8->pokeStruct,6);
            sub_8012D60(&sUnknown_203B2B8->unk7C,sUnknown_203B2B8->unk16C,0,sUnknown_203B2B8->unk20C,sUnknown_203B2B8->menuAction1,2);
            break;
        case 2:
            sub_8026E08(3);
            sub_8026DAC(0,&sUnknown_203B2B8->item2);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames,sUnknown_203B2B8->pokeStruct,7);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames + 0x50,sUnknown_203B2B8->pokeStruct,6);
            sub_8012EA4(&sUnknown_203B2B8->unk7C,1);
            break;
        case 3:
            sub_8024458(sUnknown_203B2B8->pokeSpecies,2);
            break;
        case 4:
            sub_801BEEC(sUnknown_203B2B8->pokeSpecies);
            break;
        case 0xe:
            sub_80227B8(sUnknown_203B2B8->pokeStruct);
            break;
        case 0x12:
            sub_801A5D8(1,0,NULL,10);
            break;
        case 0x13:
            sub_801A8D0(TRUE);
            break;
        case 0x14:
            sub_801A9E0();
            sub_8012D60(&sUnknown_203B2B8->unkCC,sUnknown_203B2B8->unk16C,0,sUnknown_203B2B8->unk20C,sUnknown_203B2B8->menuAction2,2);
            break;
        case 0x15:
            HeldItemToSlot(&item,&sUnknown_203B2B8->item1);
            sub_801B3C0(&item);
            break;
        case 0x16:
            unk_CopyMoves4To8(sUnknown_203B2B8->moves,sUnknown_203B2B8->pokeStruct->moves);
            sub_801EE10(3,sUnknown_203B2B8->pokeSpecies,sUnknown_203B2B8->moves,0,NULL,0);
            break;
        case 0x17:
            sub_801F1B0(TRUE, FALSE);
            break;
        case 0xc:
            sub_8026878();
            sub_8014248(sUnknown_80DD388,0,3,sUnknown_203B2B8->unk1BC,0,4,0,0,0x101);
            break;
        case 0xd:
            sub_8026878();
            sub_8014248(sUnknown_80DD420,0,3,sUnknown_203B2B8->unk1BC,0,4,0,0,0x101);
            break;
        case 0x18:
            GetLinkedSequence(sUnknown_203B2B8->moveIndex, sUnknown_203B2B8->moves,sUnknown_203B2B8->moveIDs);
            sub_801F808(sUnknown_203B2B8->moveIDs);
            break;
        case 5:
            sUnknown_203B2B8->fallbackState = 0x19;
            PlaySound(0xcf);
            sub_80141B4(sUnknown_80DD4C4,0,0,0x101);
            break;
        case 6:
            sUnknown_203B2B8->fallbackState = 0x19;
            PlaySound(0xcf);
            sub_80141B4(sUnknown_80DD4F4,0,0,0x101);
            break;
        case 7:
            sUnknown_203B2B8->fallbackState = 0x19;
            PlaySound(0xcc);
            sub_80141B4(sBecameLeader,0,0,0x101);
            break;
        case 8:
            sUnknown_203B2B8->fallbackState = 9;
            PlaySound(0xca);
            sub_80141B4(sUnknown_80DD564,0,0,0x101);
            break;
        case 9:
            sub_8026FA4();
            sub_808D31C(sUnknown_203B2B8->pokeStruct);
            sUnknown_203B2B8->unk8 = TRUE;
            break;
        case 0xf:
            sUnknown_203B2B8->fallbackState = 2;
            sub_80141B4(sUnknown_80DD594,0,0,0x101);
            break;
        case 0x10:
            sUnknown_203B2B8->fallbackState = 2;
            sub_80141B4(sUnknown_80DD5B8,0,0,0x101);
            break;
        case 0x11:
            sUnknown_203B2B8->fallbackState = 2;
            sub_80141B4(sUnknown_80DD60C,0,0,0x101);
            break;
        case 10:
            sUnknown_203B2B8->fallbackState = 0x19;
            sub_80141B4(sUnknown_80DD60C,0,0,0x101);
            break;
        case 0xb:
            sUnknown_203B2B8->fallbackState = 0x19;
            sub_80141B4(sUnknown_80DD63C,0,0,0x101);
            break;
        case 0:
        case 0x19:
            break;
    }
}

void sub_80264CC(void) {
    PokemonStruct1 *pokeStruct;
    s32 index;
    s32 one;
    u16 temp;
    s32 loopMax = 0;
    pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B2B8->pokeSpecies];
    MemoryFill16(sUnknown_203B2B8->unk20C, 0, sizeof(sUnknown_203B2B8->unk20C));
    sUnknown_203B2B8->isTeamLeader = sUnknown_203B2B8->pokeStruct->isTeamLeader;

    PeekPokemonItem(sUnknown_203B2B8->pokeSpecies, &sUnknown_203B2B8->item2);

    if(temp = pokeStruct->unk0 >> 1, one = 1, temp & one)
    {
        sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuStandBy;
        sUnknown_203B2B8->unk16C[loopMax].menuAction = 7;
        if(!sub_8026E88(pokeStruct))
        {
            sUnknown_203B2B8->unk20C[loopMax] = 1;
        }
        loopMax += 1;

        if(sub_80023E4(8) && !pokeStruct->isTeamLeader)
        {
            sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuMakeLeader;
            sUnknown_203B2B8->unk16C[loopMax].menuAction = 8;
            loopMax += 1;
        }
    }
    else
    {
        sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuJoinTeam;
        sUnknown_203B2B8->unk16C[loopMax].menuAction = 6;
        if(!sub_808D750(sUnknown_203B2B8->pokeSpecies))
        {
            sUnknown_203B2B8->unk20C[loopMax] = 1;
        }
        loopMax += 1;
    }
    
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuGiveGummi;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 10;
    if(!HasGummiItem())
    {
        sUnknown_203B2B8->unk20C[loopMax] = 1;
    }
    loopMax += 1;
    
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuGive;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 0xB;
    if(GetNumberOfFilledInventorySlots() == 0)
    {
        sUnknown_203B2B8->unk20C[loopMax] = 1; 
    }
    loopMax += 1;
    
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuTake;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 0xC;
    if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE || sUnknown_203B2B8->item2.id == ITEM_NOTHING)
    {
        sUnknown_203B2B8->unk20C[loopMax] = 1; 
    }
    loopMax += 1;

    if((temp = pokeStruct->unk0 >> 1, one = 1, temp & one) == 0)
    {
        sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuSayFarewell;
        sUnknown_203B2B8->unk16C[loopMax].menuAction = 9;
        if(!sub_8026EB8(pokeStruct))
        {
            sUnknown_203B2B8->unk20C[loopMax] = 1; 
        }
        loopMax += 1;
    }
    
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuSummary;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 4;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuMoves;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 0xD;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuCheckIQ;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 5;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = NULL;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 1;

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

void sub_802678C(void)
{
    s32 index;
    s32 loopMax = 0;
    MemoryFill16(sUnknown_203B2B8->unk20C, 0, sizeof(sUnknown_203B2B8->unk20C));
    sUnknown_203B2B8->unk16C[loopMax].text = sPartyMenuGive;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 0xB;
    if(GetNumberOfFilledInventorySlots() == 0)
    {
        sUnknown_203B2B8->unk20C[0] = 1;
    }
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = gCommonInfo[0];
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 4;
    loopMax += 1;
    sUnknown_203B2B8->unk16C[loopMax].text = NULL;
    sUnknown_203B2B8->unk16C[loopMax].menuAction = 1;

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

void sub_8026878(void) {
    s32 loopMax = 0;
    sUnknown_203B2B8->unk1BC[loopMax].text = gCommonYes[0];
    sUnknown_203B2B8->unk1BC[loopMax].menuAction = 2;
    loopMax += 1;
    sUnknown_203B2B8->unk1BC[loopMax].text = gCommonNo[0];
    sUnknown_203B2B8->unk1BC[loopMax].menuAction = 3;
    loopMax += 1;
    sUnknown_203B2B8->unk1BC[loopMax].text = NULL;
    sUnknown_203B2B8->unk1BC[loopMax].menuAction = 1;
}

void sub_80268CC(void)
{
  PokemonStruct1 *playerPokemon;
  PokemonStruct1 *pokeStruct;
  PokemonStruct1 *pokeStruct2;
  s32 choice;
  
  choice = 0;
  if ((sub_8012FD8(&sUnknown_203B2B8->unk7C) == 0) && (sub_8013114(&sUnknown_203B2B8->unk7C,&choice), choice != 1)) {
    sUnknown_203B2B8->menuAction1 = choice;
  }
  switch(choice) {
    case 6:
        if (sub_808D750(sUnknown_203B2B8->pokeSpecies)) {

#ifdef NONMATCHING
            pokeStruct = &sUnknown_203B2B8->pokeSpecies[gRecruitedPokemonRef->pokemon];
#else
            register size_t offset asm("r1") = offsetof(unkStruct_203B45C, pokemon[sUnknown_203B2B8->pokeSpecies]);
            PokemonStruct1* p = gRecruitedPokemonRef->pokemon;
            size_t addr = offset + (size_t)p;
            pokeStruct = (PokemonStruct1*)addr;
#endif

            pokeStruct->unk0 |= FLAG_ON_TEAM;
            nullsub_104();
        }
        sub_808ED00();
        sub_8026074(5);
        break;
    case 7:
        sUnknown_203B2B8->pokeStruct->unk0 &= ~(FLAG_ON_TEAM);
        nullsub_104();
        sub_808ED00();
        sub_8026074(6);
        break;
    case 8:
        pokeStruct2 = &gRecruitedPokemonRef->pokemon[sUnknown_203B2B8->pokeSpecies];
        playerPokemon = GetPlayerPokemonStruct();

        if (!pokeStruct2->isTeamLeader) {
            playerPokemon->isTeamLeader = FALSE;
            pokeStruct2->isTeamLeader = TRUE;
            nullsub_104();
        }
        sub_808ED00();
        sub_8026074(7);
        break;
    case 9:
        sub_8026074(0xc);
        break;
    case 0xd:
        sub_8026074(0x16);
        break;
    case 10:
        sub_8026074(0xe);
        break;
    case 0xb:
        sub_8026074(0x12);
        break;
    case 0xc:
        PlaySound(0x14d);
        if (sUnknown_203B2B8->item2.id != ITEM_NOTHING) {
            AddHeldItemToInventory(&sUnknown_203B2B8->item2);
        }
        FillInventoryGaps();
        sUnknown_203B2B8->item2.id = ITEM_NOTHING;
        sUnknown_203B2B8->item2.quantity = 0;
        GivePokemonItem(sUnknown_203B2B8->pokeSpecies,&sUnknown_203B2B8->item2);
        nullsub_104();
        sub_8026074(0x11);
        break;
    case 4:
        sub_8026074(3);
        break;
    case 5:
        sub_8026074(4);
        break;
    case 1:
        sub_8026074(0x19);
        break;

  }
}

void sub_8026A78(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            sub_8026074(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8026A94(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            sub_801BF98();
            sub_8026074(2);
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

void sub_8026AB0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
            case 3:
                sub_8026074(2);
                break;
            case 2:
                if (sub_8026AB0_sub())
                    sub_8026074(0xD);
                else
                    sub_8026074(8);
                break;
        }
    }
}

void sub_8026B10(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
            case 3:
                sub_8026074(2);
                break;
            case 2:
                sub_8026074(8);
                break;
        }
    }
}


void sub_8026B48(void)
{
    switch(sub_8022860())
    {
        case 2:
        case 3:
            sub_8022908();
            sub_8026074(2);
            break;
        case 0:
        case 1:
            break;
    }
}


void sub_8026B64(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            sUnknown_203B2B8->id = sub_801A8AC();
            sUnknown_203B2B8->item1.id = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].id;
            sUnknown_203B2B8->item1.quantity = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].quantity;
            sub_8026074(0x14);
            break;
        case 4:
            sUnknown_203B2B8->id = sub_801A8AC();
            sUnknown_203B2B8->item1.id = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].id;
            sUnknown_203B2B8->item1.quantity = gTeamInventoryRef->teamItems[sUnknown_203B2B8->id].quantity;
            sub_8099690(0);
            sub_8026074(0x15);
            break;
        case 2:
            sub_801A928();
            sub_8026074(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8026C14(void)
{
  u32 nextState;
  struct unkStruct_8090F58 temp;
  int menuAction;
  Item slot;

  menuAction = 0;
  sub_801A6E8(FALSE);
  if ((sub_8012FD8(&sUnknown_203B2B8->unkCC) == '\0') && (sub_8013114(&sUnknown_203B2B8->unkCC,&menuAction), menuAction != 1)) {
    sUnknown_203B2B8->menuAction2 = menuAction;
  }
  switch(menuAction)
  {
      case 0xb:
        nextState = 0xF;
        PlaySound(0x14d);
        ShiftItemsDownFrom(sUnknown_203B2B8->id);
        FillInventoryGaps();
        if (sUnknown_203B2B8->item2.id != ITEM_NOTHING) {
          AddHeldItemToInventory(&sUnknown_203B2B8->item2);
          nextState = 0x10;
        }
        HeldItemToSlot(&slot,&sUnknown_203B2B8->item1);
        temp.unk0 = 0;
        temp.unk4 = 0;
        temp.unk8 = 1;
        slot.flags = ITEM_FLAG_EXISTS;
        sub_8090E14(gUnknown_202DEA8,&slot,&temp);
        GivePokemonItem(sUnknown_203B2B8->pokeSpecies,&sUnknown_203B2B8->item1);
        sub_801A928();
        nullsub_104();
        sub_8026074(nextState);
        break;
      case 4:
        sub_8099690(0);
        sub_8026074(0x15);
        break;
      case 1:
        sub_8026074(0x13);
        break;
  }
}

void sub_8026CF0(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8026074(0x13);
            break;
        case 0:
        case 1:
            break;
    }
}


void sub_8026D0C(void)
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
            sub_8026074(0x18);
            break;
        case 2:
            sub_801F214();
            sub_8026074(2);
            break;
    }
}

void sub_8026D6C(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            sub_8026074(0x17);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8026D88(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_8026074(sUnknown_203B2B8->fallbackState);
    }
}

void sub_8026DAC(u32 r0, BulkItem *item)
{
    Item slot;
    struct unkStruct_8090F58 temp;

    sub_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&slot, item);
    temp.unk0 = 0;
    temp.unk4 = 0;
    temp.unk8 = 1;
    slot.flags = ITEM_FLAG_EXISTS;
    sub_8090E14(gUnknown_202DE58, &slot, &temp);
    xxx_format_and_draw(4, 3, sPartyMenuItemPlaceholder, r0, 0);
    sub_80073E0(r0);
}

void sub_8026E08(u32 r0)
{
    u8 buffer1[40];
    u8 buffer[20];
    s32 x;

    sub_8008C54(r0);
    sub_80073B8(r0);
    sub_80922B4(gAvailablePokemonNames, sUnknown_203B2B8->pokeStruct->name, POKEMON_NAME_LENGTH);
    sub_808D930(buffer, sUnknown_203B2B8->pokeStruct->speciesNum);
    sprintfStatic(buffer1, sUnknown_80DD6E0, gAvailablePokemonNames);
    x = sub_8008ED0(buffer1);
    xxx_call_draw_string(((sUnknown_80DD370.unkC << 3) - x) / 2, 3, buffer1, r0, 0);
    sub_80073E0(r0);
}

bool8 sub_8026E88(PokemonStruct1 *r0)
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

bool8 sub_8026EB8(PokemonStruct1 *r0)
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


u32 sub_8026F04(PokemonStruct1 *r0)
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

bool8 CanTakePokemonHeldItem(PokemonStruct1 *r0)
{
    if(IsNotMoneyOrUsedTMItem(r0->heldItem.id))
    {
        if(IsThrowableItem(r0->heldItem.id))
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

void sub_8026FA4(void)
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
            sub_8026074(0xA);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrowableItem(sUnknown_203B2B8->item2.id))
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
            sub_8026074(0xB);
            break;
        case 0:
        default:
            sub_8026074(0x19);
            break;
    }
}
