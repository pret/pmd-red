#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "code_801602C.h"
#include "code_801B3C0.h"
#include "friend_list_menu.h"
#include "iq_skill_menu.h"
#include "code_801EE10.h"
#include "code_801EE10_mid.h"
#include "code_8023868.h"
#include "code_8024458.h"
#include "code_8098BDC.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "constants/dungeon.h"
#include "event_flag.h"
#include "ground_map_1.h"
#include "input.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text.h"

EWRAM_INIT unkStruct_203B2B4 *gUnknown_203B2B4 = {NULL};

#include "data/friend_list_menu.h"

extern u8 sub_8002658(s16);
extern s32 sub_80144A4(s32 *);

void SetFriendListMenuState(s32);
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
void FriendListMenu_GotoFallbackState(void);
void sub_8025E68(u32 , BulkItem *);
bool8 FriendListMenu_isOnTeam(PokemonStruct1 *);


bool8 CreateFriendListMenu(s32 param_1)
{
  if ((param_1 == 2) && (sub_8024108(4) != 0)) {
    return FALSE;
  }
  else {
    gUnknown_203B2B4 = MemoryAlloc(sizeof(unkStruct_203B2B4),8);
    gUnknown_203B2B4->menuAction1 = 0;
    gUnknown_203B2B4->unk0 = param_1;
    gUnknown_203B2B4->unkC = sub_8002658(sub_80A5728());
    gUnknown_203B2B4->unkD = 0;
    if (gUnknown_203B2B4->unk0 == 2) {
      SetFriendListMenuState(0);
    }
    else {
      SetFriendListMenuState(1);
    }
    return TRUE;
  }
}

u32 sub_8025354(void)
{
  switch(gUnknown_203B2B4->state) {
    case FRIEND_LIST_MENU_STATE_EXIT:
        return 3;
    case 1:
    case 2:
        sub_80259F0();
        break;
    case 3:
        sub_8025A84();
        break;
    case FRIEND_LIST_MENU_STATE_SUMMARY:
        sub_8025BCC();
        break;
    case FRIEND_LIST_MENU_STATE_CHECK_IQ:
        sub_8025BE8();
        break;
    case FRIEND_LIST_MENU_STATE_GIVE:
    case 0xc:
        sub_8025C04();
        break;
    case 0xd:
        sub_8025CB4();
        break;
    case FRIEND_LIST_MENU_STATE_INFO:
        sub_8025D90();
        break;
    case FRIEND_LIST_MENU_STATE_MOVES:
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
        FriendListMenu_GotoFallbackState();
        break;
  }
  return 0;
}

u8 sub_802540C(void)
{
    return gUnknown_203B2B4->unkD;
}

void CleanFriendListMenu(void)
{
    if(gUnknown_203B2B4 != NULL)
    {
        MemoryFree(gUnknown_203B2B4);
        gUnknown_203B2B4 = NULL;
    }
}

void SetFriendListMenuState(s32 newState)
{
    gUnknown_203B2B4->state = newState;
    sub_802544C();
    sub_8025518();
}

void sub_802544C(void)
{
    s32 i;

    RestoreUnkTextStruct_8006518(&gUnknown_203B2B4->unk118);

    switch (gUnknown_203B2B4->state) {
        case 3:
            if (gUnknown_203B2B4->unk0 == 0)
                gUnknown_203B2B4->unk118.id[3] = sUnknown_80DD190;

            sub_8025728();
            gUnknown_203B2B4->unk118.id[2] = sUnknown_80DD160;
            sub_8012CAC(&gUnknown_203B2B4->unk118.id[2], gUnknown_203B2B4->unkC8);
            break;
        case 13:
            sub_802591C();
            gUnknown_203B2B4->unk118.id[2] = sUnknown_80DD178;
            sub_8012CAC(&gUnknown_203B2B4->unk118.id[2], gUnknown_203B2B4->unkC8);
            break;
        default:
            for (i = 0; i < 4; i++)
                gUnknown_203B2B4->unk118.id[i] = sUnknown_80DD148;
            break;

    }

    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2B4->unk118, TRUE, TRUE);
}

void sub_8025518(void)
{
  u32 uVar3;
  Item item;

  switch(gUnknown_203B2B4->state)
  {
    case 0:
        gUnknown_203B2B4->fallbackState = 1;
        CreateDialogueBoxAndPortrait(sVisitWhoPrompt,0,0,0x301);
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
        PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0],gUnknown_203B2B4->pokeStruct,7);
        PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[1],gUnknown_203B2B4->pokeStruct,6);
        sub_8012D60(&gUnknown_203B2B4->unk78,gUnknown_203B2B4->unkC8,0,gUnknown_203B2B4->unk108,gUnknown_203B2B4->menuAction1,2);
        break;
    case FRIEND_LIST_MENU_STATE_SUMMARY:
        sub_8024458(gUnknown_203B2B4->species,2);
        break;
    case FRIEND_LIST_MENU_STATE_CHECK_IQ:
        CreateIQSkillMenu(gUnknown_203B2B4->species);
        break;
    case FRIEND_LIST_MENU_STATE_GIVE:
        sub_801A5D8(1, 0, NULL, 10);
        break;
    case 0xc:
        sub_801A8D0(TRUE);
        break;
    case 0xd:
        sub_801A9E0();
        sub_8012D60(&gUnknown_203B2B4->unk78,gUnknown_203B2B4->unkC8,0,gUnknown_203B2B4->unk108,gUnknown_203B2B4->menuAction2,2);
        break;
    case FRIEND_LIST_MENU_STATE_INFO:
        HeldItemToSlot(&item, &gUnknown_203B2B4->item1);
        InitItemDescriptionWindow(&item);
        break;
    case FRIEND_LIST_MENU_STATE_ITEM_GIVEN:
        gUnknown_203B2B4->fallbackState = 2;
        CreateDialogueBoxAndPortrait(sItemHandedOver,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_ITEM_EXCHANGE:
        gUnknown_203B2B4->fallbackState = 2;
        CreateDialogueBoxAndPortrait(sItemExchanged,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_TAKE:
        gUnknown_203B2B4->fallbackState = 2;
        CreateDialogueBoxAndPortrait(sReturnedToToolbox,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_STANDBY:
        gUnknown_203B2B4->fallbackState = 1;
        PlaySound(0xcf);
        CreateDialogueBoxAndPortrait(sLeftOnStandby,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_MOVES:
        unk_CopyMoves4To8(gUnknown_203B2B4->moves,gUnknown_203B2B4->pokeStruct->moves);
        sub_801EE10(3,gUnknown_203B2B4->species,gUnknown_203B2B4->moves,0,NULL,0);
        break;
    case 0x10:
        sub_801F1B0(TRUE, FALSE);
        break;
    case 0x11:
        GetLinkedSequence(gUnknown_203B2B4->moveIndex,gUnknown_203B2B4->moves, gUnknown_203B2B4->moveIDs);
        sub_801F808(gUnknown_203B2B4->moveIDs);
        break;
    case 0x12:
        CreateConfirmNameMenu(2,gUnknown_203B2B4->pokeStruct->name);
        break;
    case FRIEND_LIST_MENU_STATE_EXIT:
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
        gUnknown_203B2B4->unkC8[loopMax].text = sGive;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_GIVE;
        if (GetNumberOfFilledInventorySlots() == 0) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;

        gUnknown_203B2B4->unkC8[loopMax].text = sTake;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_TAKE;
        if ((INVENTORY_SIZE <= GetNumberOfFilledInventorySlots()) || (gUnknown_203B2B4->item2.id == ITEM_NOTHING)) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;

        if (FriendListMenu_isOnTeam(pokeStruct)) {
            gUnknown_203B2B4->unkC8[loopMax].text = sStandBy;
            gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_STANDBY;
            loopMax += 1;
        }
    }
    else {
        gUnknown_203B2B4->unkC8[loopMax].text = sVisit;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_VISIT;
        if (gUnknown_203B2B4->unkC == GetFriendArea(gUnknown_203B2B4->pokeStruct->speciesNum)) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;
    }
    if ((pokeStruct->speciesNum == 0x13d) &&
        (IsPokemonRenamed(pokeStruct))) {
        gUnknown_203B2B4->unkC8[loopMax].text = sName;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = 8;
        loopMax += 1;
    }
    gUnknown_203B2B4->unkC8[loopMax].text = sSummary;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_SUMMARY;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = sMoves;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_MOVES;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = sCheckIQ;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_CHECK_IQ;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = NULL;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_NULL;

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

  gUnknown_203B2B4->unkC8[loopMax].text = sGive;
  gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_GIVE;
  if (GetNumberOfFilledInventorySlots() == 0) {
      gUnknown_203B2B4->unk108[loopMax] = 1;
  }
  loopMax += 1;
  gUnknown_203B2B4->unkC8[loopMax].text = gCommonInfo[0];
  gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_INFO;
  loopMax += 1;
  gUnknown_203B2B4->unkC8[loopMax].text = NULL;
  gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_NULL;

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
            SetFriendListMenuState(3);
            break;
        case 4:
            gUnknown_203B2B4->species = sub_8023B44();
            gUnknown_203B2B4->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B4->species];
            PeekPokemonItem(gUnknown_203B2B4->species, &gUnknown_203B2B4->item2);
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_SUMMARY);
            break;
        case 2:
            sub_8023C60();
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_EXIT);
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
        if(menuAction != FRIEND_LIST_MENU_NULL) gUnknown_203B2B4->menuAction1 = menuAction;
    }
    switch(menuAction)
    {
        case FRIEND_LIST_MENU_VISIT:
            gUnknown_203B2B4->unkD = GetFriendArea(gUnknown_203B2B4->pokeStruct->speciesNum);
            sub_8023C60();
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_EXIT);
            break;
        case FRIEND_LIST_MENU_GIVE:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_GIVE);
            break;
        case FRIEND_LIST_MENU_TAKE:
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
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_TAKE);
            break;
        case FRIEND_LIST_MENU_STANDBY:
            gUnknown_203B2B4->pokeStruct->unk0 &= ~(FLAG_ON_TEAM);
            nullsub_104();
            sub_808ED00();
            sub_8023C60();
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_STANDBY);
            break;
        case FRIEND_LIST_MENU_MOVES:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_MOVES);
            break;
        case 8:
            SetFriendListMenuState(0x12);
            break;
        case FRIEND_LIST_MENU_SUMMARY:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_SUMMARY);
            break;
        case FRIEND_LIST_MENU_CHECK_IQ:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_CHECK_IQ);
            break;
        case FRIEND_LIST_MENU_NULL:
            SetFriendListMenuState(0x2);
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
            SetFriendListMenuState(2);
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
            CleanIQSkillMenu();
            SetFriendListMenuState(2);
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
            SetFriendListMenuState(0xD);
            break;
        case 4:
            gUnknown_203B2B4->itemIndex = sub_801A8AC();
            gUnknown_203B2B4->item1.id = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].id;
            gUnknown_203B2B4->item1.quantity = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].quantity;
            sub_8099690(0);
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_INFO);
            break;
        case 2:
            sub_801A928();
            SetFriendListMenuState(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8025CB4(void)
{
  u32 nextState;
  s32 menuAction;
  struct unkStruct_8090F58 a3;
  Item item;

  menuAction = 0;
  sub_801A6E8(FALSE);
  if ((!sub_8012FD8(&gUnknown_203B2B4->unk78)) && (sub_8013114(&gUnknown_203B2B4->unk78,&menuAction), menuAction != FRIEND_LIST_MENU_NULL)) {
    gUnknown_203B2B4->menuAction2 = menuAction;
  }

    switch(menuAction)
    {
        case FRIEND_LIST_MENU_GIVE:
            nextState = FRIEND_LIST_MENU_STATE_ITEM_GIVEN;
            PlaySound(0x14d);
            ShiftItemsDownFrom(gUnknown_203B2B4->itemIndex);
            FillInventoryGaps();
            if ((gUnknown_203B2B4->item2).id != 0) {
                AddHeldItemToInventory(&gUnknown_203B2B4->item2);
                nextState = FRIEND_LIST_MENU_STATE_ITEM_EXCHANGE;
            }
            HeldItemToSlot(&item,&gUnknown_203B2B4->item1);
            a3.unk0 = 0;
            a3.unk4 = 0;
            a3.unk8 = 1;
            item.flags = ITEM_FLAG_EXISTS;
            sub_8090E14(gFormatBuffer_Items[1],&item,&a3);
            GivePokemonItem(gUnknown_203B2B4->species,&gUnknown_203B2B4->item1);
            sub_801A928();
            nullsub_104();
            SetFriendListMenuState(nextState);
            break;
        case FRIEND_LIST_MENU_INFO:
            sub_8099690(0);
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_INFO);
            break;
        case FRIEND_LIST_MENU_NULL:
            SetFriendListMenuState(0xc);
            break;
    }
}

void sub_8025D90(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            SetFriendListMenuState(0xC);
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
            SetFriendListMenuState(0x11);
            break;
        case 4:
            gUnknown_203B2B4->moveIndex = sub_801F194();
            gUnknown_203B2B4->moveID = gUnknown_203B2B4->moves[gUnknown_203B2B4->moveIndex].id;
            SetFriendListMenuState(0x11);
            break;
        case 2:
            sub_801F214();
            sub_8094060(gUnknown_203B2B4->moves,gUnknown_203B2B4->pokeStruct->moves);
            SetFriendListMenuState(0x2);
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
            SetFriendListMenuState(0x10);
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
            CleanConfirmNameMenu();
            nullsub_104();
            SetFriendListMenuState(0x2);
            break;
    }
}

void FriendListMenu_GotoFallbackState(void)
{
    s32 local;
    if(sub_80144A4(&local) == 0)
    {
        SetFriendListMenuState(gUnknown_203B2B4->fallbackState);
    }
}

void sub_8025E68(u32 r0, BulkItem *heldItem)
{
    Item item;
    struct unkStruct_8090F58 a3;

    CallPrepareTextbox_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&item, heldItem);
    a3.unk0 = 0;
    a3.unk4 = 0;
    a3.unk8 = 1;
    item.flags = ITEM_FLAG_EXISTS;
    sub_8090E14(gFormatBuffer_Items[0], &item, &a3);
    PrintFormattedStringOnWindow(4, 3, sItemBuffered, r0, 0);
    sub_80073E0(r0);
}

bool8 FriendListMenu_isOnTeam(PokemonStruct1 *pokeStruct)
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
