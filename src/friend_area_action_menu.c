#include "global.h"
#include "constants/dungeon.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "item.h"
#include "pokemon.h"
#include "team_inventory.h"
#include "friend_area_action_menu.h"
#include "menu_input.h"
#include "kecleon_bros.h"
#include "sprite.h"
#include "code_80130A8.h"
#include "code_801EE10_1.h"
#include "code_801B3C0.h"
#include "event_flag.h"
#include "moves.h"

extern struct unkStruct_203B2BC *gUnknown_203B2BC;

extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 *gUnknown_80D4970[];

extern void sub_8024458(s16, u32);
extern void sub_801BEEC(s16);
extern void sub_801F808(u16*);
extern void sub_801F1B0(u32, u32);
extern void sub_801EE10(u32, s16, struct Move *, u32, u32, u32);

void sub_8027D40(u32, struct BulkItem *heldItem);
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
bool8 sub_8027D9C(struct PokemonStruct *pokeStruct);
extern u8 sub_8027DCC(struct PokemonStruct *);
extern u32 sub_801EF38(u8 r0);
extern void sub_801F214();

extern void SetFriendAreaActionMenuState(u32);
extern void PlaySound(u32);
extern void nullsub_104();
extern void sub_8099690(u32);

extern void sub_808D31C(struct PokemonStruct *);
extern struct PokemonStruct *sub_808D3F8(void);
extern struct PokemonStruct *sub_808D3BC(void);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern u8 gUnknown_202DE58[];
extern u32 sub_801F194(void);
extern u32 sub_801BF48(void);
extern void sub_801BF98(void);
extern u32 sub_80244E4(void);
extern void sub_802453C(void);
extern bool8 sub_808D750(s16 index_);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void sub_808ED00(void);

u32 sub_8027E18(struct PokemonStruct *);
u8 sub_8027E4C(struct PokemonStruct *r0);
void sub_8027EB8(void);

const struct UnkTextStruct2 gUnknown_80DD6EC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};


const struct UnkTextStruct2 gUnknown_80DD704 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x04,
    0x09, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DD71C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x14, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DD734 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DD74C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x02, 0x11,
    0x1A, 0x02,
    0x02, 0x00,
    NULL
};


ALIGNED(4) const u8 gFriendAreaActionSayFarewellPrompt[] = _(
         "You have chosen to say farewell\n"
         "to this Pokémon.{EXTRA_MSG}"
         "The Pokémon will leave its Friend Area.\n"
         "It will no longer be available for\n"
         "adventures. Is that OK?");

ALIGNED(4) const u8 gFriendAreaActionSayFarewellConfirm[] = _(
         "If you say farewell to this\n"
         "Pokémon{COMMA} it will be gone forever.{EXTRA_MSG}"
         "You will never be able to get another one\n"
         "like it to join your team.\n"
         "Will you release it anyway?");

ALIGNED(4) const u8 gUnknown_80DD8A0[] = _(
         "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
         "{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) const u8 gUnknown_80DD8D0[] = _(
         "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n{CENTER_ALIGN}sent to storage.");

ALIGNED(4) const u8 gFriendActionStandby[] = "Stand By";
ALIGNED(4) const u8 gFriendActionMakeLeader[] = "Make Leader";
ALIGNED(4) const u8 gFriendActionJoinTeam[] = "Join Team";
ALIGNED(4) const u8 gFriendActionSayFarewell[] = "Say Farewell";
ALIGNED(4) const u8 gFriendActionGive[] = "Give";
ALIGNED(4) const u8 gFriendActionTake[] = "Take";
ALIGNED(4) const u8 gFriendActionSummary[] = "Summary";
ALIGNED(4) const u8 gFriendActionMoves[] = "Moves";
ALIGNED(4) const u8 gFriendActionCheckIQ[] = "Check IQ";

ALIGNED(4) const u8 gUnknown_80DD958[] = _("Item: {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} ");
static const u8 filler[] = "pksdir0";

u32 sub_8027074(void)
{
    ResetSprites(FALSE);
    gUnknown_203B2BC = MemoryAlloc(sizeof(struct unkStruct_203B2BC), 8);
    gUnknown_203B2BC->menuAction1 = 0;
    gUnknown_203B2BC->menuAction2 = 0;
    gUnknown_203B2BC->menuAction3 = 0;
    SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_INIT);
    return 1;
}

u32 sub_80270A4(void)
{
  switch(gUnknown_203B2BC->state) {
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
    if(gUnknown_203B2BC != NULL)
    {
        MemoryFree(gUnknown_203B2BC);
        gUnknown_203B2BC = NULL;
    }
}

void SetFriendAreaActionMenuState(u32 newState)
{
    gUnknown_203B2BC->state = newState;
    sub_802719C();
    sub_8027274();
}

void sub_802719C(void)
{
    s32 index;

    sub_8006518(gUnknown_203B2BC->unk180);
    switch(gUnknown_203B2BC->state)
    {
        case 3:
            gUnknown_203B2BC->unk180[3] = gUnknown_80DD74C;
            CreateFriendActionMenu();
            gUnknown_203B2BC->unk180[2] = gUnknown_80DD704;
            sub_8012CAC(&gUnknown_203B2BC->unk180[2], gUnknown_203B2BC->menuItems);
            break;
        case 0xC:
            sub_80276A8();
            gUnknown_203B2BC->unk180[2] = gUnknown_80DD71C;
            sub_8012CAC(&gUnknown_203B2BC->unk180[2], gUnknown_203B2BC->menuItems);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B2BC->unk180[index] = gUnknown_80DD6EC;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2BC->unk180, 1, 1);
}

void sub_8027274(void)
{
  struct Item slot;

  switch(gUnknown_203B2BC->state) {
    case FRIEND_AREA_ACTION_MENU_INIT:
    case FRIEND_AREA_ACTION_MENU_EXIT:
        break;
    case FRIEND_AREA_ACTION_MENU_MAIN:
        sub_8023868(1,0,0,7);
        break;
    case FRIEND_AREA_ACTION_MENU_MAIN_2:
        sub_8023B7C(1);
        break;
    case 3:
        sub_8027D40(3,&gUnknown_203B2BC->item2);
        sub_8023DA4();
        sub_8012D60(&gUnknown_203B2BC->unk7C,gUnknown_203B2BC->menuItems,0,gUnknown_203B2BC->unk16C,gUnknown_203B2BC->menuAction1,2);
        break;
    case FRIEND_AREA_ACTION_MENU_SUMMARY:
        sub_8024458(gUnknown_203B2BC->targetPoke,2);
        break;
    case FRIEND_AREA_ACTION_MENU_CHECK_IQ:
        sub_801BEEC(gUnknown_203B2BC->targetPoke);
        break;
    case 10:
        sub_801A5D8(1,0,0,10);
        break;
    case 0xb:
        sub_801A8D0(1);
        break;
    case 0xc:
        sub_801A9E0();
        sub_8012D60(&gUnknown_203B2BC->unk7C,gUnknown_203B2BC->menuItems,0,gUnknown_203B2BC->unk16C,gUnknown_203B2BC->menuAction2,2);
        break;
    case 0xd:
        HeldItemToSlot(&slot, &gUnknown_203B2BC->itemToGive);
        sub_801B3C0(&slot);
        break;
    case 0xe:
        unk_CopyMoves4To8(gUnknown_203B2BC->moves,gUnknown_203B2BC->pokeStruct->moves);
        sub_801EE10(3,gUnknown_203B2BC->targetPoke,gUnknown_203B2BC->moves,0,0,0);
        break;
    case 0xf:
        sub_801F1B0(1,0);
        break;
    case FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_PROMPT:
        sub_8027794();
        sub_8014248(gFriendAreaActionSayFarewellPrompt,0,3,gUnknown_203B2BC->menuItems,0,4,0,0,0x101);
        break;
    case FRIEND_AREA_ACTION_MENU_SAY_FAREWELL_CONFIRM:
        sub_8027794();
        sub_8014248(gFriendAreaActionSayFarewellConfirm,0,3,gUnknown_203B2BC->menuItems,0,4,0,0,0x101);
        break;
    case 0x10:
        GetLinkedSequence(gUnknown_203B2BC->moveIndex,gUnknown_203B2BC->moves,gUnknown_203B2BC->moveIDs);
        sub_801F808(gUnknown_203B2BC->moveIDs);
        break;
    case 6:
        gUnknown_203B2BC->fallbackState = FRIEND_AREA_ACTION_MENU_MAIN_2;
        // The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was
        // returned to the Toolbox
        sub_80141B4(gUnknown_80DD8A0,0,0,0x101);
        break;
    case 7:
        gUnknown_203B2BC->fallbackState = FRIEND_AREA_ACTION_MENU_MAIN_2;
        // The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was
        // returned to storage
        sub_80141B4(gUnknown_80DD8D0,0,0,0x101);
        break;
  }
}

void CreateFriendActionMenu(void)
{
  int index;
  s32 loopMax;
  struct PokemonStruct *pokeStruct;

  loopMax = 0;
  pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
  MemoryFill16(gUnknown_203B2BC->unk16C,0,sizeof(gUnknown_203B2BC->unk16C));

  if((pokeStruct->unk0 >> 1) % 2)
  {
      gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionStandby;
      gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_STANDBY;
      if(!sub_8027D9C(pokeStruct))
      {
          gUnknown_203B2BC->unk16C[loopMax] = 1;
      }
      loopMax += 1;
      if(sub_80023E4(8) && !pokeStruct->isTeamLeader)
      {
          gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionMakeLeader;
          gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_MAKE_LEADER;
          loopMax += 1;
      }
  }
  else
  {
      gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionJoinTeam;
      gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_JOIN_TEAM;
      if(!sub_808D750(gUnknown_203B2BC->targetPoke))
      {
          gUnknown_203B2BC->unk16C[loopMax] = 1;
      }
      loopMax += 1;
      gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionSayFarewell;
      gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_SAY_FAREWELL;
      if(!sub_8027DCC(pokeStruct))
      {
          gUnknown_203B2BC->unk16C[loopMax] = 1;
      }
      loopMax += 1;

  }

  gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionGive;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_GIVE;
  if(GetNumberOfFilledInventorySlots() == 0)
  {
      gUnknown_203B2BC->unk16C[loopMax] = 1;
  }
  loopMax += 1;
    
  gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionTake;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_TAKE;
  if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE || gUnknown_203B2BC->item2.id == ITEM_NOTHING)
  {
      gUnknown_203B2BC->unk16C[loopMax] = 1;
  }
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionSummary;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_SUMMARY;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionMoves;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_MOVES;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionCheckIQ;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_CHECK_IQ;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = 0;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NONE;

  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2BC->unk16C[index] == 0)
      {
          if(gUnknown_203B2BC->menuItems[index].menuAction == gUnknown_203B2BC->menuAction1)
              return;
      }
  }
    
  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2BC->unk16C[index] == 0)
      {
             gUnknown_203B2BC->menuAction1 = gUnknown_203B2BC->menuItems[index].menuAction;
             break;
      }
  }
}

void sub_80276A8(void)
{
  int index;
  s32 loopMax;

  loopMax = 0;
  MemoryFill16(gUnknown_203B2BC->unk16C,0,sizeof(gUnknown_203B2BC->unk16C));
  gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionGive;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_GIVE;
  if (GetNumberOfFilledInventorySlots() == 0) {
    gUnknown_203B2BC->unk16C[loopMax] = 1;
  }
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_INFO;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = 0;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NONE;

  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2BC->unk16C[index] == 0)
      {
          if(gUnknown_203B2BC->menuItems[index].menuAction == gUnknown_203B2BC->menuAction2)
              return;
      }
  }
    
  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2BC->unk16C[index] == 0)
      {
             gUnknown_203B2BC->menuAction2 = gUnknown_203B2BC->menuItems[index].menuAction;
             break;
      }
  }
}

void sub_8027794(void)
{
  s32 loopMax = 0;
  
  MemoryFill16(gUnknown_203B2BC->unk16C,0,sizeof(gUnknown_203B2BC->unk16C));
  gUnknown_203B2BC->menuItems[loopMax].text = *gUnknown_80D4920;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_YES;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = *gUnknown_80D4928;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NO;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = NULL;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = FRIEND_AREA_ACTION_MENU_ACTION_NONE;
}

void sub_80277FC(void)
{
  struct PokemonStruct *pokeStruct;

  switch(sub_8023A94(TRUE)) {
      case 0:
      case 1:
        break;
      case 3:
        gUnknown_203B2BC->targetPoke = sub_8023B44();
        pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
        gUnknown_203B2BC->pokeStruct = pokeStruct;
        gUnknown_203B2BC->isTeamLeader = pokeStruct->isTeamLeader;
        PeekPokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->item2);
        SetFriendAreaActionMenuState(3);
        break;
      case 4:
        gUnknown_203B2BC->targetPoke = sub_8023B44();
        pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
        gUnknown_203B2BC->pokeStruct = pokeStruct;
        gUnknown_203B2BC->isTeamLeader = pokeStruct->isTeamLeader;
        PeekPokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->item2);
        SetFriendAreaActionMenuState(4);
        break;
      case 2:
        sub_8023C60();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_EXIT);
        break;
  }
}

void sub_80278B4(void)
{
  struct PokemonStruct *playerStruct;
  struct PokemonStruct *pokeStruct1;
  struct PokemonStruct *pokeStruct2;
  u32 menuAction;

  menuAction = 0;
  sub_8023A94(FALSE);
  if ((sub_8012FD8(&gUnknown_203B2BC->unk7C) == 0) && (sub_8013114(&gUnknown_203B2BC->unk7C,&menuAction), menuAction != FRIEND_AREA_ACTION_MENU_ACTION_NONE)) {
    gUnknown_203B2BC->menuAction1 = menuAction;
  }
  switch(menuAction) {
      case FRIEND_AREA_ACTION_MENU_ACTION_JOIN_TEAM:
        if (sub_808D750(gUnknown_203B2BC->targetPoke)) {
#ifdef NONMATCHING
            pokeStruct1 = &gRecruiedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
#else
        register size_t offset asm("r1") = offsetof(struct unkStruct_203B45C, pokemon[gUnknown_203B2BC->targetPoke]);
        struct PokemonStruct* p = gRecruitedPokemonRef->pokemon;
        size_t addr = offset + (size_t)p;
        pokeStruct1 = (struct PokemonStruct*)addr;
#endif
          pokeStruct1->unk0 |= FLAG_ON_TEAM;
          nullsub_104();
        }
        sub_808ED00();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_STANDBY:
        gUnknown_203B2BC->pokeStruct->unk0 &= ~(FLAG_ON_TEAM);
        nullsub_104();
        sub_808ED00();
        SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
        break;
      case FRIEND_AREA_ACTION_MENU_ACTION_MAKE_LEADER:
        pokeStruct2 = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
        playerStruct = GetPlayerPokemonStruct();
        if (!pokeStruct2->isTeamLeader) {
          playerStruct->isTeamLeader = FALSE;
          pokeStruct2->isTeamLeader = TRUE;
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
        if (gUnknown_203B2BC->item2.id != ITEM_NOTHING) {
          AddHeldItemToInventory(&gUnknown_203B2BC->item2);
        }
        FillInventoryGaps();
        gUnknown_203B2BC->item2.id = ITEM_NOTHING;
        gUnknown_203B2BC->item2.quantity = 0;
        GivePokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->item2);
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
            sub_801BF98();
            SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
            break;
        case 0:
        case 1:
            break;
    }
}

static inline bool8 sub_8027A78_sub(void) {
    if (gUnknown_203B2BC->pokeStruct->dungeonLocation.id == DUNGEON_HOWLING_FOREST_2 || gUnknown_203B2BC->pokeStruct->dungeonLocation.id == DUNGEON_POKEMON_SQUARE)
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
                    sub_808D31C(gUnknown_203B2BC->pokeStruct);
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
            sub_808D31C(gUnknown_203B2BC->pokeStruct);
            break;
    }
  }
}

void sub_8027B28(void)
{
  switch(sub_801A6E8(TRUE))
  {
    case 3:
        gUnknown_203B2BC->id = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.id = gTeamInventoryRef->teamItems[gUnknown_203B2BC->id].id;
        gUnknown_203B2BC->itemToGive.quantity = gTeamInventoryRef->teamItems[gUnknown_203B2BC->id].quantity;
        SetFriendAreaActionMenuState(0xc);
        break;
    case 4:
        gUnknown_203B2BC->id = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.id = gTeamInventoryRef->teamItems[gUnknown_203B2BC->id].id;
        gUnknown_203B2BC->itemToGive.quantity = gTeamInventoryRef->teamItems[gUnknown_203B2BC->id].quantity;
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
  if ((sub_8012FD8(&gUnknown_203B2BC->unk7C) == 0) && (sub_8013114(&gUnknown_203B2BC->unk7C,&menuAction), menuAction != FRIEND_AREA_ACTION_MENU_ACTION_NONE)) {
    gUnknown_203B2BC->menuAction2 = menuAction;
  }
  switch(menuAction)
  {
    case FRIEND_AREA_ACTION_MENU_ACTION_GIVE:
        PlaySound(0x14d);
        ShiftItemsDownFrom(gUnknown_203B2BC->id);
        FillInventoryGaps();
        if (gUnknown_203B2BC->item2.id != ITEM_NOTHING) {
            AddHeldItemToInventory(&gUnknown_203B2BC->item2);
        }
        GivePokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->itemToGive);
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
            sub_801B450();
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
            gUnknown_203B2BC->moveIndex = sub_801F194();
            gUnknown_203B2BC->moveID = gUnknown_203B2BC->moves[gUnknown_203B2BC->moveIndex].id;
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
        SetFriendAreaActionMenuState(gUnknown_203B2BC->fallbackState);
    }
}

void sub_8027D40(u32 r0, struct BulkItem *heldItem)
{

    struct Item slot;
    struct unkStruct_8090F58 a3;

    sub_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&slot, heldItem);
    a3.unk0 = 0;
    a3.unk4 = 0;
    a3.unk8 = 1;
    slot.flags = ITEM_FLAG_EXISTS;
    sub_8090E14(gUnknown_202DE58, &slot, &a3);
    xxx_format_and_draw(4, 3, gUnknown_80DD958, r0, 0);
    sub_80073E0(r0);
}

bool8 sub_8027D9C(struct PokemonStruct *pokeStruct)
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

bool8 sub_8027DCC(struct PokemonStruct *pokeStruct)
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

u32 sub_8027E18(struct PokemonStruct *pokeStruct)
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

bool8 sub_8027E4C(struct PokemonStruct *pokeStruct)
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
    switch(sub_8027E18(gUnknown_203B2BC->pokeStruct))
    {
        case 1:
            PlaySound(0x14d);
            AddHeldItemToInventory(&gUnknown_203B2BC->item2);
            FillInventoryGaps();
            gUnknown_203B2BC->item2.id = ITEM_NOTHING;
            gUnknown_203B2BC->item2.quantity = 0;
            GivePokemonItem(gUnknown_203B2BC->targetPoke, &gUnknown_203B2BC->item2);
            SetFriendAreaActionMenuState(6);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrowableItem(gUnknown_203B2BC->item2.id))
                gTeamInventoryRef->teamStorage[gUnknown_203B2BC->item2.id] += gUnknown_203B2BC->item2.quantity;
            else
                gTeamInventoryRef->teamStorage[gUnknown_203B2BC->item2.id] += 1;
            gUnknown_203B2BC->item2.id = ITEM_NOTHING;
            gUnknown_203B2BC->item2.quantity = 0;
            GivePokemonItem(gUnknown_203B2BC->targetPoke, &gUnknown_203B2BC->item2);
            SetFriendAreaActionMenuState(7);
            break;
        case 0:
        default:
            SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_MAIN_2);
            break;
    }
}

