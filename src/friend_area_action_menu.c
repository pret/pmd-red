#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "code_801B3C0.h"
#include "code_801EE10.h"
#include "code_801EE10_mid.h"
#include "friend_list.h"
#include "code_8024458.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "event_flag.h"
#include "friend_area_action_menu.h"
#include "input.h"
#include "iq_skill_menu.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "unk_ds_only_feature.h"

static EWRAM_INIT struct unkStruct_203B2BC *sUnknown_203B2BC = {NULL};

void sub_8027D40(u32, BulkItem *heldItem);
void sub_8027794(void);
extern void SetFriendAreaActionMenuState(u32);
extern void sub_802719C();
extern void sub_8027274();
extern void sub_80277FC();
extern void sub_80278B4();
extern void sub_8027A40();
extern void sub_8027A5C();
extern void FriendAreaActionMenu_GotoFallbackState();
extern void sub_8027A78();
extern void sub_8027AE4();
extern void sub_8027B28();
extern void sub_8027BD8();
extern void sub_8027C84();
extern void sub_8027CA0();
extern void sub_8027D00();
extern void CreateFriendActionMenu();
extern void sub_80276A8();
bool8 sub_8027D9C(Pokemon *pokeStruct);
extern u8 sub_8027DCC(Pokemon *);
extern void SetFriendAreaActionMenuState(u32);
extern void PlaySound(u32);
extern void sub_808D31C(Pokemon *);
extern bool8 sub_808D750(s16 index_);

u32 sub_8027E18(Pokemon *);
u8 sub_8027E4C(Pokemon *r0);
void sub_8027EB8(void);

#include "data/friend_area_action_menu.h"

u32 sub_8027074(void)
{
    ResetSprites(FALSE);
    sUnknown_203B2BC = MemoryAlloc(sizeof(struct unkStruct_203B2BC), 8);
    sUnknown_203B2BC->menuAction1 = 0;
    sUnknown_203B2BC->menuAction2 = 0;
    sUnknown_203B2BC->menuAction3 = 0;
    SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_INIT);
    return 1;
}

u32 sub_80270A4(void)
{
  switch(sUnknown_203B2BC->state) {
      case FRIEND_AREA_ACTION_MENU_INIT:
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN);
        break;
      case FRIEND_AREA_ACTION_MENU_MAIN:
      case FRIEND_AREA_ACTION_MENU_MAIN_2:
        sub_80277FC();
        break;
      case 3:
        sub_80278B4();
        break;
      case FRIEND_AREA_ACTION_MENU_SUMMARY:
        sub_8027A40();
        break;
      case FRIEND_AREA_ACTION_MENU_CHECK_IQ:
        sub_8027A5C();
        break;
      case FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_PROMPT:
        sub_8027A78();
        break;
      case FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_CONFIRM:
        sub_8027AE4();
        break;
      case 10:
      case 0xb:
        sub_8027B28();
        break;
      case 0xc:
        sub_8027BD8();
        break;
      case 0xd:
        sub_8027C84();
        break;
      case 0xe:
      case 0xf:
        sub_8027CA0();
        break;
      case 0x10:
        sub_8027D00();
        break;
      default:
        FriendAreaActionMenu_GotoFallbackState();
        break;
      case FRIEND_AREA_ACTION_MENU_EXIT:
        return 3;
  }
  return 0;
}

void sub_8027168(void)
{
    if(sUnknown_203B2BC != NULL)
    {
        MemoryFree(sUnknown_203B2BC);
        sUnknown_203B2BC = NULL;
    }
}

void SetFriendAreaActionMenuState(u32 newState)
{
    sUnknown_203B2BC->state = newState;
    sub_802719C();
    sub_8027274();
}

void sub_802719C(void)
{
    s32 index;

    RestoreSavedWindows(&sUnknown_203B2BC->unk180);
    switch(sUnknown_203B2BC->state)
    {
        case 3:
            sUnknown_203B2BC->unk180.id[3] = sUnknown_80DD74C;
            CreateFriendActionMenu();
            sUnknown_203B2BC->unk180.id[2] = sUnknown_80DD704;
            sub_8012CAC(&sUnknown_203B2BC->unk180.id[2], sUnknown_203B2BC->menuItems);
            break;
        case 0xC:
            sub_80276A8();
            sUnknown_203B2BC->unk180.id[2] = sUnknown_80DD71C;
            sub_8012CAC(&sUnknown_203B2BC->unk180.id[2], sUnknown_203B2BC->menuItems);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                sUnknown_203B2BC->unk180.id[index] = sUnknown_80DD6EC;
            }
            break;
    }
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2BC->unk180, TRUE, TRUE);
}

void sub_8027274(void)
{
    Item slot;

    switch (sUnknown_203B2BC->state) {
        case FRIEND_AREA_ACTION_MENU_INIT:
        case FRIEND_AREA_ACTION_MENU_EXIT:
            break;
        case FRIEND_AREA_ACTION_MENU_MAIN:
            FriendList_Init(1,0,0,7);
            break;
        case FRIEND_AREA_ACTION_MENU_MAIN_2:
            sub_8023B7C(1);
            break;
        case 3:
            sub_8027D40(3, &sUnknown_203B2BC->item2);
            FriendList_ShowWindow();
            sub_8012D60(&sUnknown_203B2BC->unk7C, sUnknown_203B2BC->menuItems, 0, sUnknown_203B2BC->unk16C, sUnknown_203B2BC->menuAction1, 2);
            break;
        case FRIEND_AREA_ACTION_MENU_SUMMARY:
            sub_8024458(sUnknown_203B2BC->targetPoke, 2);
            break;
        case FRIEND_AREA_ACTION_MENU_CHECK_IQ:
            CreateIQSkillMenu(sUnknown_203B2BC->targetPoke);
            break;
        case 10:
            sub_801A5D8(1, 0, NULL, 10);
            break;
        case 0xb:
            sub_801A8D0(TRUE);
            break;
        case 0xc:
            sub_801A9E0();
            sub_8012D60(&sUnknown_203B2BC->unk7C,sUnknown_203B2BC->menuItems,0,sUnknown_203B2BC->unk16C,sUnknown_203B2BC->menuAction2,2);
            break;
        case 0xd:
            BulkItemToItem(&slot, &sUnknown_203B2BC->itemToGive);
            InitItemDescriptionWindow(&slot);
            break;
        case 0xe:
            unk_CopyMoves4To8(sUnknown_203B2BC->moves,sUnknown_203B2BC->pokeStruct->moves);
            sub_801EE10(3,sUnknown_203B2BC->targetPoke,sUnknown_203B2BC->moves,0,NULL,0);
            break;
        case 0xf:
            sub_801F1B0(TRUE, FALSE);
            break;
        case FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_PROMPT:
            sub_8027794();
            CreateMenuDialogueBoxAndPortrait(sSayFarewellPrompt,0,3,sUnknown_203B2BC->menuItems,0,4,0,0,0x101);
            break;
        case FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_CONFIRM:
            sub_8027794();
            CreateMenuDialogueBoxAndPortrait(sSayFarewellConfirm,0,3,sUnknown_203B2BC->menuItems,0,4,0,0,0x101);
            break;
        case 0x10:
            GetLinkedSequence(sUnknown_203B2BC->moveIndex,sUnknown_203B2BC->moves,sUnknown_203B2BC->moveIDs);
            sub_801F808(sUnknown_203B2BC->moveIDs);
            break;
        case 6:
            sUnknown_203B2BC->fallbackState = FRIEND_AREA_ACTION_MENU_MAIN_2;
            CreateDialogueBoxAndPortrait(sReturnedToToolbox, 0, 0, 0x101);
            break;
        case 7:
            sUnknown_203B2BC->fallbackState = FRIEND_AREA_ACTION_MENU_MAIN_2;
            CreateDialogueBoxAndPortrait(sSentToStorage, 0, 0, 0x101);
            break;
    }
}

void CreateFriendActionMenu(void)
{
  int index;
  s32 loopMax;
  Pokemon *pokeStruct;

  loopMax = 0;
  pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B2BC->targetPoke];
  MemoryFill16(sUnknown_203B2BC->unk16C,0,sizeof(sUnknown_203B2BC->unk16C));

  if (PokemonFlag2(pokeStruct)) {
      sUnknown_203B2BC->menuItems[loopMax].text = sStandBy;
      sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_STANDBY;
      if(!sub_8027D9C(pokeStruct))
      {
          sUnknown_203B2BC->unk16C[loopMax] = 1;
      }
      loopMax += 1;
      if(sub_80023E4(8) && !pokeStruct->isTeamLeader)
      {
          sUnknown_203B2BC->menuItems[loopMax].text = sMakeLeader;
          sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_MAKE_LEADER;
          loopMax += 1;
      }
  }
  else
  {
      sUnknown_203B2BC->menuItems[loopMax].text = sJoinTeam;
      sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_JOIN_TEAM;
      if(!sub_808D750(sUnknown_203B2BC->targetPoke))
      {
          sUnknown_203B2BC->unk16C[loopMax] = 1;
      }
      loopMax += 1;
      sUnknown_203B2BC->menuItems[loopMax].text = sSayFarewell;
      sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_SAY_FAREWELL;
      if(!sub_8027DCC(pokeStruct))
      {
          sUnknown_203B2BC->unk16C[loopMax] = 1;
      }
      loopMax += 1;

  }

  sUnknown_203B2BC->menuItems[loopMax].text = sGive;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_GIVE;
  if(GetNumberOfFilledInventorySlots() == 0)
  {
      sUnknown_203B2BC->unk16C[loopMax] = 1;
  }
  loopMax += 1;

  sUnknown_203B2BC->menuItems[loopMax].text = sTake;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_TAKE;
  if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE || sUnknown_203B2BC->item2.id == ITEM_NOTHING)
  {
      sUnknown_203B2BC->unk16C[loopMax] = 1;
  }
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = sSummary;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_SUMMARY;
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = sMoves;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_MOVES;
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = sCheckIQ;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_CHECK_IQ;
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = NULL;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NONE;

  for(index = 0; index < loopMax; index++)
  {
      if(sUnknown_203B2BC->unk16C[index] == 0)
      {
          if(sUnknown_203B2BC->menuItems[index].menuAction == sUnknown_203B2BC->menuAction1)
              return;
      }
  }

  for(index = 0; index < loopMax; index++)
  {
      if(sUnknown_203B2BC->unk16C[index] == 0)
      {
             sUnknown_203B2BC->menuAction1 = sUnknown_203B2BC->menuItems[index].menuAction;
             break;
      }
  }
}

void sub_80276A8(void)
{
  int index;
  s32 loopMax;

  loopMax = 0;
  MemoryFill16(sUnknown_203B2BC->unk16C,0,sizeof(sUnknown_203B2BC->unk16C));
  sUnknown_203B2BC->menuItems[loopMax].text = sGive;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_GIVE;
  if (GetNumberOfFilledInventorySlots() == 0) {
    sUnknown_203B2BC->unk16C[loopMax] = 1;
  }
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = gCommonInfo[0];
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_INFO;
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = 0;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NONE;

  for(index = 0; index < loopMax; index++)
  {
      if(sUnknown_203B2BC->unk16C[index] == 0)
      {
          if(sUnknown_203B2BC->menuItems[index].menuAction == sUnknown_203B2BC->menuAction2)
              return;
      }
  }

  for(index = 0; index < loopMax; index++)
  {
      if(sUnknown_203B2BC->unk16C[index] == 0)
      {
             sUnknown_203B2BC->menuAction2 = sUnknown_203B2BC->menuItems[index].menuAction;
             break;
      }
  }
}

void sub_8027794(void)
{
  s32 loopMax = 0;

  MemoryFill16(sUnknown_203B2BC->unk16C,0,sizeof(sUnknown_203B2BC->unk16C));
  sUnknown_203B2BC->menuItems[loopMax].text = gCommonYes[0];
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_YES;
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = gCommonNo[0];
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NO;
  loopMax += 1;
  sUnknown_203B2BC->menuItems[loopMax].text = NULL;
  sUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NONE;
}

void sub_80277FC(void)
{
  Pokemon *pokeStruct;

  switch(FriendList_HandleInput(TRUE)) {
      case 0:
      case 1:
        break;
      case 3:
        sUnknown_203B2BC->targetPoke = FriendList_GetCurrId();
        pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B2BC->targetPoke];
        sUnknown_203B2BC->pokeStruct = pokeStruct;
        sUnknown_203B2BC->isTeamLeader = pokeStruct->isTeamLeader;
        PeekPokemonItem(sUnknown_203B2BC->targetPoke,&sUnknown_203B2BC->item2);
        SetFriendAreaActionMenuState(3);
        break;
      case 4:
        sUnknown_203B2BC->targetPoke = FriendList_GetCurrId();
        pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B2BC->targetPoke];
        sUnknown_203B2BC->pokeStruct = pokeStruct;
        sUnknown_203B2BC->isTeamLeader = pokeStruct->isTeamLeader;
        PeekPokemonItem(sUnknown_203B2BC->targetPoke,&sUnknown_203B2BC->item2);
        SetFriendAreaActionMenuState(4);
        break;
      case 2:
        FriendList_Free();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_EXIT);
        break;
  }
}

void sub_80278B4(void)
{
  Pokemon *playerStruct;
  Pokemon *newLeader;
  u32 menuAction;

  menuAction = 0;
  FriendList_HandleInput(FALSE);
  if ((sub_8012FD8(&sUnknown_203B2BC->unk7C) == 0) && (sub_8013114(&sUnknown_203B2BC->unk7C,&menuAction), menuAction != FRIEND_AREA_ACTION_MENU_ACTION_NONE)) {
    sUnknown_203B2BC->menuAction1 = menuAction;
  }
  switch(menuAction) {
      case FRIEND_AREA_ACTION_MENU_ACTION_JOIN_TEAM:
        if (sub_808D750(sUnknown_203B2BC->targetPoke)) {
          SetPokemonFlag2(&gRecruitedPokemonRef->pokemon[sUnknown_203B2BC->targetPoke]);
          nullsub_104();
        }
        sub_808ED00();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_STANDBY:
        sUnknown_203B2BC->pokeStruct->flags &= ~(POKEMON_FLAG_ON_TEAM);
        nullsub_104();
        sub_808ED00();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_MAKE_LEADER:
        newLeader = &gRecruitedPokemonRef->pokemon[sUnknown_203B2BC->targetPoke];
        playerStruct = GetPlayerPokemonStruct();
        if (!newLeader->isTeamLeader) {
          playerStruct->isTeamLeader = FALSE;
          newLeader->isTeamLeader = TRUE;
          nullsub_104();
        }
        sub_808ED00();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_SAY_FAREWELL:
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_PROMPT);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_MOVES:
        SetFriendAreaActionMenuState(0xe);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_GIVE:
        SetFriendAreaActionMenuState(10);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_TAKE:
        PlaySound(0x14d);
        if (sUnknown_203B2BC->item2.id != ITEM_NOTHING) {
          AddHeldItemToInventory(&sUnknown_203B2BC->item2);
        }
        FillInventoryGaps();
        sUnknown_203B2BC->item2.id = ITEM_NOTHING;
        sUnknown_203B2BC->item2.quantity = 0;
        GivePokemonItem(sUnknown_203B2BC->targetPoke,&sUnknown_203B2BC->item2);
        nullsub_104();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_SUMMARY:
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_SUMMARY);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_CHECK_IQ:
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_CHECK_IQ);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_NONE:
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
  }
}

void sub_8027A40(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8027A5C(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            CleanIQSkillMenu();
            SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
            break;
        case 0:
        case 1:
            break;
    }
}

static inline bool8 sub_8027A78_sub(void) {
    if (sUnknown_203B2BC->pokeStruct->dungeonLocation.id == DUNGEON_HOWLING_FOREST_2 || sUnknown_203B2BC->pokeStruct->dungeonLocation.id == DUNGEON_POKEMON_SQUARE)
        return TRUE;
    else
        return FALSE;
}

void sub_8027A78(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case FRIEND_AREA_ACTION_MENU_ACTION_NONE:
            case FRIEND_AREA_ACTION_MENU_ACTION_NO:
                SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
                break;
            case FRIEND_AREA_ACTION_MENU_ACTION_YES:
                if (sub_8027A78_sub())
                    SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_CONFIRM);
                else
                {
                    sub_8027EB8();
                    sub_808D31C(sUnknown_203B2BC->pokeStruct);
                }
                break;
        }
    }
}

void sub_8027AE4(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
      switch(menuAction)
      {
        case FRIEND_AREA_ACTION_MENU_ACTION_NONE:
        case FRIEND_AREA_ACTION_MENU_ACTION_NO:
            SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
            break;
        case FRIEND_AREA_ACTION_MENU_ACTION_YES:
            sub_8027EB8();
            sub_808D31C(sUnknown_203B2BC->pokeStruct);
            break;
    }
  }
}

void sub_8027B28(void)
{
  switch(sub_801A6E8(TRUE))
  {
    case 3:
        sUnknown_203B2BC->id = sub_801A8AC();
        sUnknown_203B2BC->itemToGive.id = gTeamInventoryRef->teamItems[sUnknown_203B2BC->id].id;
        sUnknown_203B2BC->itemToGive.quantity = gTeamInventoryRef->teamItems[sUnknown_203B2BC->id].quantity;
        SetFriendAreaActionMenuState(0xc);
        break;
    case 4:
        sUnknown_203B2BC->id = sub_801A8AC();
        sUnknown_203B2BC->itemToGive.id = gTeamInventoryRef->teamItems[sUnknown_203B2BC->id].id;
        sUnknown_203B2BC->itemToGive.quantity = gTeamInventoryRef->teamItems[sUnknown_203B2BC->id].quantity;
        sub_8099690(0);
        SetFriendAreaActionMenuState(0xd);
        break;
    case 2:
        sub_801A928();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
    case 0:
    case 1:
        break;
  }
}

void sub_8027BD8(void)
{
  s32 menuAction;

  menuAction = 0;
  sub_801A6E8(FALSE);
  if ((sub_8012FD8(&sUnknown_203B2BC->unk7C) == 0) && (sub_8013114(&sUnknown_203B2BC->unk7C,&menuAction), menuAction != FRIEND_AREA_ACTION_MENU_ACTION_NONE)) {
    sUnknown_203B2BC->menuAction2 = menuAction;
  }
  switch(menuAction)
  {
    case FRIEND_AREA_ACTION_MENU_ACTION_GIVE:
        PlaySound(0x14d);
        ShiftItemsDownFrom(sUnknown_203B2BC->id);
        FillInventoryGaps();
        if (sUnknown_203B2BC->item2.id != ITEM_NOTHING) {
            AddHeldItemToInventory(&sUnknown_203B2BC->item2);
        }
        GivePokemonItem(sUnknown_203B2BC->targetPoke,&sUnknown_203B2BC->itemToGive);
        sub_801A928();
        nullsub_104();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
    case FRIEND_AREA_ACTION_MENU_ACTION_INFO:
        sub_8099690(0);
        SetFriendAreaActionMenuState(0xd);
        break;
    case FRIEND_AREA_ACTION_MENU_ACTION_NONE:
        SetFriendAreaActionMenuState(0xb);
        break;
  }
}

void sub_8027C84()
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            SetFriendAreaActionMenuState(0xB);
        case 0:
        case 1:
            break;
    }
}

void sub_8027CA0(void)
{
    switch(sub_801EF38(1))
    {
        case 3:
        case 4:
            sUnknown_203B2BC->moveIndex = sub_801F194();
            sUnknown_203B2BC->moveID = sUnknown_203B2BC->moves[sUnknown_203B2BC->moveIndex].id;
            SetFriendAreaActionMenuState(0x10);
            break;
        case 2:
            sub_801F214();
            SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8027D00(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            SetFriendAreaActionMenuState(0xF);
            break;
        case 0:
        case 1:
            break;
    }
}

void FriendAreaActionMenu_GotoFallbackState(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendAreaActionMenuState(sUnknown_203B2BC->fallbackState);
    }
}

void sub_8027D40(u32 r0, BulkItem *heldItem)
{

    Item slot;
    struct unkStruct_8090F58 a3;

    CallPrepareTextbox_8008C54(r0);
    sub_80073B8(r0);
    BulkItemToItem(&slot, heldItem);
    a3.unk0 = 0;
    a3.unk4 = 0;
    a3.unk8 = 1;
    slot.flags = ITEM_FLAG_EXISTS;
    sub_8090E14(gFormatBuffer_Items[0], &slot, &a3);
    PrintFormattedStringOnWindow(4, 3, sItemBuffered, r0, 0);
    sub_80073E0(r0);
}

bool8 sub_8027D9C(Pokemon *pokeStruct)
{
    u32 var1;
    if(!pokeStruct->isTeamLeader)
    {
        var1 = 0;
        if(pokeStruct->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER)
            var1 = 1;
        if(var1 != 0)
        {
            if(!sub_80023E4(8))
                return FALSE;
        }
    }
    else
        return FALSE;
    return TRUE;
}

bool8 sub_8027DCC(Pokemon *pokeStruct)
{
    u32 var1;
    if(sub_808D3BC() != pokeStruct)
        if(sub_808D3F8() != pokeStruct)
            if(!pokeStruct->isTeamLeader)
            {
                var1 = 0;
                if(pokeStruct->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER)
                    var1 = 1;
                if(var1 != 0)
                {
                    if(sub_80023E4(8))
                        goto check;
                }
                else
                {
                    check:
                    if(sub_8027E18(pokeStruct) != 3)
                        return TRUE;
                }
            }
    return FALSE;
}

u32 sub_8027E18(Pokemon *pokeStruct)
{
    if(pokeStruct->heldItem.id == ITEM_NOTHING)
        return 0;
    else if(GetNumberOfFilledInventorySlots() < INVENTORY_SIZE)
        return 1;
    else if(sub_8027E4C(pokeStruct))
        return 2;
    else
        return 3;
}

bool8 sub_8027E4C(Pokemon *pokeStruct)
{
    if(!IsNotMoneyOrUsedTMItem(pokeStruct->heldItem.id))
        return FALSE;
    else
    {
        if(IsThrowableItem(pokeStruct->heldItem.id))
        {
            if(gTeamInventoryRef->teamStorage[pokeStruct->heldItem.id] + pokeStruct->heldItem.quantity > 0x3e7)
                return FALSE;
        }
        else if(gTeamInventoryRef->teamStorage[pokeStruct->heldItem.id] > 0x3e6)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void sub_8027EB8(void)
{
    switch(sub_8027E18(sUnknown_203B2BC->pokeStruct))
    {
        case 1:
            PlaySound(0x14d);
            AddHeldItemToInventory(&sUnknown_203B2BC->item2);
            FillInventoryGaps();
            sUnknown_203B2BC->item2.id = ITEM_NOTHING;
            sUnknown_203B2BC->item2.quantity = 0;
            GivePokemonItem(sUnknown_203B2BC->targetPoke, &sUnknown_203B2BC->item2);
            SetFriendAreaActionMenuState(6);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrowableItem(sUnknown_203B2BC->item2.id))
                gTeamInventoryRef->teamStorage[sUnknown_203B2BC->item2.id] += sUnknown_203B2BC->item2.quantity;
            else
                gTeamInventoryRef->teamStorage[sUnknown_203B2BC->item2.id] += 1;
            sUnknown_203B2BC->item2.id = ITEM_NOTHING;
            sUnknown_203B2BC->item2.quantity = 0;
            GivePokemonItem(sUnknown_203B2BC->targetPoke, &sUnknown_203B2BC->item2);
            SetFriendAreaActionMenuState(7);
            break;
        case 0:
        default:
            SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
            break;
    }
}

