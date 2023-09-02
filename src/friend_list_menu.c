#include "global.h"
#include "constants/dungeon.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "items.h"
#include "pokemon.h"
#include "moves.h"
#include "menu_input.h"

#include "kecleon_bros.h"
#include "code_80130A8.h"
#include "code_801EE10_1.h"
#include "code_8012A18_1.h"
#include "code_801B3C0.h"
#include "code_80118A4.h"
#include "event_flag.h"

// there might be more overlap with unkStruct_203B2BC
// I was working on the moves and put the data that seemed to correspond to that
// into a separate struct
struct unkStruct_203B2B4
{
    // size: 0x178
    s32 unk0;
    s32 state;
    u32 fallbackState;
    u8 unkC;
    u8 unkD;
    s16 species;
    u32 itemIndex;
    BulkItem item1;
    BulkItem item2;
    /* 0x1C */ PokemonStruct1 *pokeStruct;
    u32 moveIndex;  // some sort of move index
    u16 moveID;
    struct Move moves[8];
    u16 moveIDs[4];   // some list of move IDs
    u32 menuAction1;
    s32 menuAction2;
    MenuStruct unk78;
    MenuItem unkC8[8];
    u16 unk108[8];
    UnkTextStruct2 unk118[4];
};
EWRAM_DATA_2 struct unkStruct_203B2B4 *gUnknown_203B2B4 = {0};

const UnkTextStruct2 gUnknown_80DD148 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80DD160 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x04,
    0x08, 0x03,
    0x03, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80DD178 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x14, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80DD190 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x02, 0x11,
    0x1A, 0x02,
    0x02, 0x00,
    NULL
};

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DEA8[];
extern u8 *gUnknown_80D4970[];
extern u8 gUnknown_202DE58[];

ALIGNED(4) const u8 gUnknown_80DD1A8[] = "Whom would you like to visit?";

ALIGNED(4) const u8 gUnknown_80DD1C8[] = _(
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}handed over. ");

ALIGNED(4) const u8 gUnknown_80DD1EC[] = _(
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}handed over.{EXTRA_MSG}"
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) const u8 gUnknown_80DD240[] = _(
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) const u8 gUnknown_80DD270[] = _(
    "{CENTER_ALIGN}{ARG_POKEMON_1} left the team to remain\n"
    "{CENTER_ALIGN}on standby in the Friend Area.");

ALIGNED(4) const u8 gFriendListGive[] = "Give";
ALIGNED(4) const u8 gFriendListTake[] = "Take";
ALIGNED(4) const u8 gFriendListStandBy[] = "Stand By";
ALIGNED(4) const u8 gFriendListVisit[] = "Visit";
ALIGNED(4) const u8 gFriendListName[] = "Name";
ALIGNED(4) const u8 gFriendListSummary[] = "Summary";
ALIGNED(4) const u8 gFriendListMoves[] = "Moves";
ALIGNED(4) const u8 gFriendListCheckIQ[] = "Check IQ";
ALIGNED(4) const u8 gFriendListItem[] = _("Item: {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} ");
ALIGNED(4) static const u8 fill0[] = "pksdir0";

extern s16 sub_80A5728(void);
extern u8 sub_8002658(s16);
extern bool8 sub_8024108(u32);
extern void sub_801F1B0(u32, u32);
extern void sub_8024458(s16, u32);
extern void sub_801BEEC(s16);
extern void nullsub_104(void);
extern void sub_808ED00(void);
extern u32 sub_80244E4(void);
extern void sub_802453C(void);
extern u32 sub_801BF48(void);
extern void sub_801BF98(void);

extern u32 sub_801EF38(u32);
extern u32 sub_801F194(void);
extern void sub_801F214(void);
extern void sub_801EE10(u32, s16, struct Move *, u32, u32, u32);
extern void sub_801F808(u16 *);
extern void sub_8099690(u32);
extern void sub_801F8D0(void);
extern u32 sub_801F890(void);
extern void sub_80160D8(void);
extern u32 sub_8016080(void);
extern s32 sub_80144A4(s32 *);

void sub_8025434(s32);
void sub_802544C(void);
void sub_8025518(void);
void sub_8025728(void);
void sub_802591C(void);
void sub_80259F0(void);
void sub_8025A84(void);
void sub_8025BCC(void);
void sub_8025BE8(void);
void sub_8025C04(void);
void sub_8025CB4(void);
void sub_8025D90(void);
void sub_8025DAC(void);
void sub_8025E08(void);
void sub_8025E24(void);
void sub_8025E44(void);
void sub_8025E68(u32 , BulkItem *);
bool8 sub_8025EC4(PokemonStruct1 *);


bool8 sub_80252F0(s32 param_1)
{
  if ((param_1 == 2) && (sub_8024108(4) != 0)) {
    return FALSE;
  }
  else {
    gUnknown_203B2B4 = MemoryAlloc(sizeof(struct unkStruct_203B2B4),8);
    gUnknown_203B2B4->menuAction1 = 0;
    gUnknown_203B2B4->unk0 = param_1;
    gUnknown_203B2B4->unkC = sub_8002658(sub_80A5728());
    gUnknown_203B2B4->unkD = 0;
    if (gUnknown_203B2B4->unk0 == 2) {
      sub_8025434(0);
    }
    else {
      sub_8025434(1);
    }
    return TRUE;
  }
}

u32 sub_8025354(void)
{
  switch(gUnknown_203B2B4->state) {
    case 0x13:
        return 3;
    case 1:
    case 2:
        sub_80259F0();
        break;
    case 3:
        sub_8025A84();
        break;
    case 4:
        sub_8025BCC();
        break;
    case 5:
        sub_8025BE8();
        break;
    case 0xb:
    case 0xc:
        sub_8025C04();
        break;
    case 0xd:
        sub_8025CB4();
        break;
    case 0xe:
        sub_8025D90();
        break;
    case 0xf:
    case 0x10:
        sub_8025DAC();
        break;
    case 0x11:
        sub_8025E08();
        break;
    case 0x12:
        sub_8025E24();
        break;
    default:
        sub_8025E44();
        break;
  }
  return 0;
}

u8 sub_802540C(void)
{
    return gUnknown_203B2B4->unkD;
}

void sub_8025418(void)
{
    if(gUnknown_203B2B4 != NULL)
    {
        MemoryFree(gUnknown_203B2B4);
        gUnknown_203B2B4 = NULL;
    }
}

void sub_8025434(s32 newState)
{
    gUnknown_203B2B4->state = newState;
    sub_802544C();
    sub_8025518();
}

void sub_802544C(void)
{
  s32 index;
  
  sub_8006518(gUnknown_203B2B4->unk118);

  switch(gUnknown_203B2B4->state)
  {
    case 3:
        if (gUnknown_203B2B4->unk0 == 0) {
            gUnknown_203B2B4->unk118[3] = gUnknown_80DD190;
        }
        sub_8025728();
        gUnknown_203B2B4->unk118[2] = gUnknown_80DD160;
        sub_8012CAC(&gUnknown_203B2B4->unk118[2],gUnknown_203B2B4->unkC8);
        break;
    case 0xD:
        sub_802591C();
        gUnknown_203B2B4->unk118[2] = gUnknown_80DD178;
        sub_8012CAC(&gUnknown_203B2B4->unk118[2],gUnknown_203B2B4->unkC8);
        break;
    default:
        for(index = 0; index < 4; index++)
        {
            gUnknown_203B2B4->unk118[index] = gUnknown_80DD148;
        }
        break;

  }
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B2B4->unk118, TRUE, TRUE);
}

void sub_8025518(void)
{
  u32 uVar3;
  Item item;

  switch(gUnknown_203B2B4->state)
  {
    case 0:
        gUnknown_203B2B4->fallbackState = 1;
        sub_80141B4(gUnknown_80DD1A8,0,0,0x301);
        break;
    case 1:
        uVar3 = 4;
        if (gUnknown_203B2B4->unk0 == 0) {
            uVar3 = 2;
        }
        sub_8023868(uVar3,0,0,10);
        break;
    case 2:
        sub_8023B7C(1);
        break;
    case 3:
        if (gUnknown_203B2B4->unk0 == 0) {
            sub_8025E68(3,&gUnknown_203B2B4->item2);
        }
        sub_8023DA4();
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames,gUnknown_203B2B4->pokeStruct,7);
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames + 0x50,gUnknown_203B2B4->pokeStruct,6);
        sub_8012D60(&gUnknown_203B2B4->unk78,gUnknown_203B2B4->unkC8,0,gUnknown_203B2B4->unk108,gUnknown_203B2B4->menuAction1,2);
        break;
    case 4:
        sub_8024458(gUnknown_203B2B4->species,2);
        break;
    case 5:
        sub_801BEEC(gUnknown_203B2B4->species);
        break;
    case 0xb:
        sub_801A5D8(1,0,0,10);
        break;
    case 0xc:
        sub_801A8D0(1);
        break;
    case 0xd:
        sub_801A9E0();
        sub_8012D60(&gUnknown_203B2B4->unk78,gUnknown_203B2B4->unkC8,0,gUnknown_203B2B4->unk108,gUnknown_203B2B4->menuAction2,2);
        break;
    case 0xe:
        HeldItemToSlot(&item, &gUnknown_203B2B4->item1);
        sub_801B3C0(&item);
        break;
    case 8:
        gUnknown_203B2B4->fallbackState = 2;
        sub_80141B4(gUnknown_80DD1C8,0,0,0x101);
        break;
    case 9:
        gUnknown_203B2B4->fallbackState = 2;
        sub_80141B4(gUnknown_80DD1EC,0,0,0x101);
        break;
    case 10:
        gUnknown_203B2B4->fallbackState = 2;
        sub_80141B4(gUnknown_80DD240,0,0,0x101);
        break;
    case 7:
        gUnknown_203B2B4->fallbackState = 1;
        PlaySound(0xcf);
        sub_80141B4(gUnknown_80DD270,0,0,0x101);
        break;
    case 0xf:
        unk_CopyMoves4To8(gUnknown_203B2B4->moves,gUnknown_203B2B4->pokeStruct->moves);
        sub_801EE10(3,gUnknown_203B2B4->species,gUnknown_203B2B4->moves,0,0,0);
        break;
    case 0x10:
        sub_801F1B0(1,0);
        break;
    case 0x11:
        GetLinkedSequence(gUnknown_203B2B4->moveIndex,gUnknown_203B2B4->moves, gUnknown_203B2B4->moveIDs);
        sub_801F808(gUnknown_203B2B4->moveIDs);
        break;
    case 0x12:
        sub_801602C(2,gUnknown_203B2B4->pokeStruct->name);
        break;
    case 0x13:
        break;
  }
}

void sub_8025728(void)
{
    int index;
    PokemonStruct1 *pokeStruct;
    s32 loopMax = 0;

    pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B4->species];
    MemoryFill16(gUnknown_203B2B4->unk108,0,sizeof(gUnknown_203B2B4->unk108));
    if (gUnknown_203B2B4->unk0 == 0) {
        gUnknown_203B2B4->unkC8[loopMax].text = gFriendListGive;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = 10;
        if (GetNumberOfFilledInventorySlots() == 0) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;

        gUnknown_203B2B4->unkC8[loopMax].text = gFriendListTake;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = 0xb;
        if ((INVENTORY_SIZE <= GetNumberOfFilledInventorySlots()) || (gUnknown_203B2B4->item2.id == ITEM_NOTHING)) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;

        if (sub_8025EC4(pokeStruct)) {
            gUnknown_203B2B4->unkC8[loopMax].text = gFriendListStandBy;
            gUnknown_203B2B4->unkC8[loopMax].menuAction = 9;
            loopMax += 1;
        }
    }
    else {
        gUnknown_203B2B4->unkC8[loopMax].text = gFriendListVisit;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = 7;
        if (gUnknown_203B2B4->unkC == GetFriendArea(gUnknown_203B2B4->pokeStruct->speciesNum)) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;
    }
    if ((pokeStruct->speciesNum == 0x13d) &&
        (IsPokemonRenamed(pokeStruct))) {
        gUnknown_203B2B4->unkC8[loopMax].text = gFriendListName;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = 8;
        loopMax += 1;
    }
    gUnknown_203B2B4->unkC8[loopMax].text = gFriendListSummary;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = gFriendListMoves;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = 6;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = gFriendListCheckIQ;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = NULL;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B4->unk108[index] == 0)
        {
            if (gUnknown_203B2B4->unkC8[index].menuAction == gUnknown_203B2B4->menuAction1)
                return;
        }
    }
    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B4->unk108[index] == 0)
        {
            gUnknown_203B2B4->menuAction1 = gUnknown_203B2B4->unkC8[index].menuAction;
            break;
        }
    }
}

void sub_802591C(void)
{
  int index;
  s32 loopMax = 0;
  

  MemoryFill16(gUnknown_203B2B4->unk108,0, sizeof(gUnknown_203B2B4->unk108));

  gUnknown_203B2B4->unkC8[loopMax].text = gFriendListGive;
  gUnknown_203B2B4->unkC8[loopMax].menuAction = 10;
  if (GetNumberOfFilledInventorySlots() == 0) {
      gUnknown_203B2B4->unk108[loopMax] = 1;
  }
  loopMax += 1;
  gUnknown_203B2B4->unkC8[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B2B4->unkC8[loopMax].menuAction = 4;
  loopMax += 1;
  gUnknown_203B2B4->unkC8[loopMax].text = NULL;
  gUnknown_203B2B4->unkC8[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2B4->unk108[index] == 0)
      {
          if (gUnknown_203B2B4->unkC8[index].menuAction == gUnknown_203B2B4->menuAction2)
            return;
      }
  }
  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2B4->unk108[index] == 0)
      {
          gUnknown_203B2B4->menuAction2 = gUnknown_203B2B4->unkC8[index].menuAction;
          break;
      }
  }
}

void sub_80259F0(void)
{
    switch(sub_8023A94(TRUE))
    {
        case 3:
            gUnknown_203B2B4->species = sub_8023B44();
            gUnknown_203B2B4->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B4->species];
            PeekPokemonItem(gUnknown_203B2B4->species, &gUnknown_203B2B4->item2);
            sub_8025434(3);
            break;
        case 4:
            gUnknown_203B2B4->species = sub_8023B44();
            gUnknown_203B2B4->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B4->species];
            PeekPokemonItem(gUnknown_203B2B4->species, &gUnknown_203B2B4->item2);
            sub_8025434(4);
            break;
        case 2:
            sub_8023C60();
            sub_8025434(0x13);
            break;
    }
}

void sub_8025A84(void)
{
    s32 menuAction = 0;

    sub_8023A94(FALSE);
    if(!sub_8012FD8(&gUnknown_203B2B4->unk78))
    {
        sub_8013114(&gUnknown_203B2B4->unk78, &menuAction);
        if(menuAction != 1) gUnknown_203B2B4->menuAction1 = menuAction;
    }
    switch(menuAction)
    {
        case 7:
            gUnknown_203B2B4->unkD = GetFriendArea(gUnknown_203B2B4->pokeStruct->speciesNum);
            sub_8023C60();
            sub_8025434(0x13);
            break;
        case 10:
            sub_8025434(0xB);
            break;
        case 11:
            PlaySound(0x14d);
            if(gUnknown_203B2B4->item2.id != ITEM_NOTHING)
            {
                AddHeldItemToInventory(&gUnknown_203B2B4->item2);
            }
            FillInventoryGaps();
            gUnknown_203B2B4->item2.id = ITEM_NOTHING;
            gUnknown_203B2B4->item2.quantity = 0;
            GivePokemonItem(gUnknown_203B2B4->species, &gUnknown_203B2B4->item2);
            nullsub_104();
            sub_8025434(0xA);
            break;
        case 9:
            gUnknown_203B2B4->pokeStruct->unk0 &= ~(FLAG_ON_TEAM);
            nullsub_104();
            sub_808ED00();
            sub_8023C60();
            sub_8025434(0x7);
            break;
        case 6:
            sub_8025434(0xF);
            break;
        case 8:
            sub_8025434(0x12);
            break;
        case 4:
            sub_8025434(0x4);
            break;
        case 5:
            sub_8025434(0x5);
            break;
        case 1:
            sub_8025434(0x2);
            break;
        case 2:
        case 3:
            break;
    }
}

void sub_8025BCC(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            sub_8025434(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8025BE8(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            sub_801BF98();
            sub_8025434(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8025C04(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            gUnknown_203B2B4->itemIndex = sub_801A8AC();
            gUnknown_203B2B4->item1.id = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].id;
            gUnknown_203B2B4->item1.quantity = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].quantity;
            sub_8025434(0xD);
            break;
        case 4:
            gUnknown_203B2B4->itemIndex = sub_801A8AC();
            gUnknown_203B2B4->item1.id = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].id;
            gUnknown_203B2B4->item1.quantity = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].quantity;
            sub_8099690(0);
            sub_8025434(0xE);
            break;
        case 2:
            sub_801A928();
            sub_8025434(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8025CB4(void)
{
  u32 uVar2;
  s32 menuAction;
  struct unkStruct_8090F58 a3;
  Item item;
  
  menuAction = 0;
  sub_801A6E8(FALSE);
  if ((!sub_8012FD8(&gUnknown_203B2B4->unk78)) && (sub_8013114(&gUnknown_203B2B4->unk78,&menuAction), menuAction != 1)) {
    gUnknown_203B2B4->menuAction2 = menuAction;
  }

    switch(menuAction)
    {
        case 10:
            uVar2 = 8;
            PlaySound(0x14d);
            ShiftItemsDownFrom(gUnknown_203B2B4->itemIndex);
            FillInventoryGaps();
            if ((gUnknown_203B2B4->item2).id != 0) {
                AddHeldItemToInventory(&gUnknown_203B2B4->item2);
                uVar2 = 9;
            }
            HeldItemToSlot(&item,&gUnknown_203B2B4->item1);
            a3.unk0 = 0;
            a3.unk4 = 0;
            a3.unk8 = 1;
            item.flags = ITEM_FLAG_EXISTS;
            sub_8090E14(gUnknown_202DEA8,&item,&a3);
            GivePokemonItem(gUnknown_203B2B4->species,&gUnknown_203B2B4->item1);
            sub_801A928();
            nullsub_104();
            sub_8025434(uVar2);
            break;
        case 4:
            sub_8099690(0);
            sub_8025434(0xe);
            break;
        case 1:
            sub_8025434(0xc);
            break;
    }
}

void sub_8025D90(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8025434(0xC);
        case 0:
        case 1:
            break;
    }
}

void sub_8025DAC(void)
{
    switch(sub_801EF38(1))
    {
        case 3:
            gUnknown_203B2B4->moveIndex = sub_801F194();
            gUnknown_203B2B4->moveID = gUnknown_203B2B4->moves[gUnknown_203B2B4->moveIndex].id;
            sub_8025434(0x11);
            break;
        case 4:
            gUnknown_203B2B4->moveIndex = sub_801F194();
            gUnknown_203B2B4->moveID = gUnknown_203B2B4->moves[gUnknown_203B2B4->moveIndex].id;
            sub_8025434(0x11);
            break;
        case 2:
            sub_801F214();
            sub_8094060(gUnknown_203B2B4->moves,gUnknown_203B2B4->pokeStruct->moves);
            sub_8025434(0x2);
            break;
    }
}

void sub_8025E08(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            sub_8025434(0x10);
        case 0:
        case 1:
            break;
    }
}

void sub_8025E24(void)
{
    switch(sub_8016080())
    {
        case 2:
        case 3:
            sub_80160D8();
            nullsub_104();
            sub_8025434(0x2);
            break;
    }
}

void sub_8025E44(void)
{
    s32 local;
    if(sub_80144A4(&local) == 0)
    {
        sub_8025434(gUnknown_203B2B4->fallbackState);
    }
}

void sub_8025E68(u32 r0, BulkItem *heldItem)
{
    Item item;
    struct unkStruct_8090F58 a3;

    sub_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&item, heldItem);
    a3.unk0 = 0;
    a3.unk4 = 0;
    a3.unk8 = 1;
    item.flags = ITEM_FLAG_EXISTS;
    sub_8090E14(gUnknown_202DE58, &item, &a3);
    xxx_format_and_draw(4, 3, gFriendListItem, r0, 0);
    sub_80073E0(r0);
}

bool8 sub_8025EC4(PokemonStruct1 *pokeStruct)
{
    bool32 flag;
    if (pokeStruct->isTeamLeader)
        {
            return FALSE;
        }
    else
    {
        flag = FALSE;
        if(pokeStruct->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER)
            flag = TRUE;
        if(flag && !sub_80023E4(8))
            return FALSE;
        else
            return TRUE;
    }
}
