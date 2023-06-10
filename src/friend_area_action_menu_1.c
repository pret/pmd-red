#include "global.h"
#include "constants/dungeon.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "item.h"
#include "team_inventory.h"
#include "pokemon.h"
#include "friend_area_action_menu.h"
#include "menu_input.h"

extern struct unkStruct_203B2BC *gUnknown_203B2BC;
extern struct TeamInventory *gTeamInventory_203B460;

extern u32 sub_801B410();
extern void sub_801B450();
extern u32 sub_801EF38(u8 r0);
extern void sub_801F214();

extern void SetFriendAreaActionMenuState(u32);
extern void PlaySound(u32);
extern void nullsub_104();
extern void sub_801A928();
extern void sub_8099690(u32);
extern u32 sub_801A8AC();
extern u32 sub_801A6E8(u32);

extern s32 sub_80144A4(s32 *);
extern void sub_8027EB8();
extern void sub_808D31C(struct PokemonStruct *);
extern bool8 sub_80023E4(u32);
extern struct PokemonStruct *sub_808D3F8(void);
extern struct PokemonStruct *sub_808D3BC(void);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern void xxx_format_and_draw(u32, u32, const u8 *, ...);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u8 gUnknown_202DE58[];
extern u32 sub_801F194(void);

u32 sub_8027E18(struct PokemonStruct *);
u8 sub_8027E4C(struct PokemonStruct *r0);

extern u32 sub_801BF48(void);
extern void sub_801BF98(void);
extern u32 sub_80244E4(void);
extern void sub_802453C(void);

extern u32 sub_8023A94(u32);
extern bool8 sub_808D750(s16 index_);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void sub_808ED00();
extern s16 sub_8023B44(void);
extern void sub_8023C60(void);

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


extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 *gUnknown_80D4970[];

void sub_80276A8(void)
{
  int index;
  s32 loopMax;

  loopMax = 0;
  MemoryFill16(gUnknown_203B2BC->unk16C,0,sizeof(gUnknown_203B2BC->unk16C));
  gUnknown_203B2BC->menuItems[loopMax].text = gFriendActionGive;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = 10;
  if (GetNumberOfFilledInventorySlots() == 0) {
    gUnknown_203B2BC->unk16C[loopMax] = 1;
  }
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = 4;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = 0;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = 1;


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
  gUnknown_203B2BC->menuItems[loopMax].menuAction = 0x2;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = *gUnknown_80D4928;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = 3;
  loopMax += 1;
  gUnknown_203B2BC->menuItems[loopMax].text = NULL;
  gUnknown_203B2BC->menuItems[loopMax].menuAction = 1;
}

void sub_80277FC(void)
{
  struct PokemonStruct *pokeStruct;

  switch(sub_8023A94(1)) {
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
  sub_8023A94(0);
  if ((sub_8012FD8(&gUnknown_203B2BC->unk7C) == 0) && (sub_8013114(&gUnknown_203B2BC->unk7C,&menuAction), menuAction != 1)) {
    gUnknown_203B2BC->menuAction1 = menuAction;
  }
  switch(menuAction) {
      case 6:
        if (sub_808D750(gUnknown_203B2BC->targetPoke)) {
#ifdef NONMATCHING
            pokeStruct1 = &gRecruiedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
#else
        register size_t offset asm("r1") = offsetof(struct unkStruct_203B45C, pokemon[gUnknown_203B2BC->targetPoke]);
        struct PokemonStruct* p = gRecruitedPokemonRef->pokemon;
        size_t addr = offset + (size_t)p;
        pokeStruct1 = (struct PokemonStruct*)addr;
#endif
          pokeStruct1->unk0 |= 2;
          nullsub_104();
        }
        sub_808ED00();
        SetFriendAreaActionMenuState(2);
        break;
      case 7:
        gUnknown_203B2BC->pokeStruct->unk0 &= 0xfffd;
        nullsub_104();
        sub_808ED00();
        SetFriendAreaActionMenuState(2);
        break;
      case 8:
        pokeStruct2 = &gRecruitedPokemonRef->pokemon[gUnknown_203B2BC->targetPoke];
        playerStruct = GetPlayerPokemonStruct();
        if (!pokeStruct2->isTeamLeader) {
          playerStruct->isTeamLeader = FALSE;
          pokeStruct2->isTeamLeader = TRUE;
          nullsub_104();
        }
        sub_808ED00();
        SetFriendAreaActionMenuState(2);
        break;
      case 9:
        SetFriendAreaActionMenuState(8);
        break;
      case 0xc:
        SetFriendAreaActionMenuState(0xe);
        break;
      case 10:
        SetFriendAreaActionMenuState(10);
        break;
      case 0xb:
        PlaySound(0x14d);
        if (gUnknown_203B2BC->item2.id != ITEM_NOTHING) {
          AddHeldItemToInventory(&gUnknown_203B2BC->item2);
        }
        FillInventoryGaps();
        gUnknown_203B2BC->item2.id = ITEM_NOTHING;
        gUnknown_203B2BC->item2.quantity = 0;
        GivePokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->item2);
        nullsub_104();
        SetFriendAreaActionMenuState(2);
        break;
      case 4:
        SetFriendAreaActionMenuState(4);
        break;
      case 5:
        SetFriendAreaActionMenuState(5);
        break;
      case 1:
        SetFriendAreaActionMenuState(2);
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
            SetFriendAreaActionMenuState(2);
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
            SetFriendAreaActionMenuState(2);
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
            case 1:
            case 3:
                SetFriendAreaActionMenuState(2);
                break;
            case 2:
                if (sub_8027A78_sub())
                    SetFriendAreaActionMenuState(9);
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
        case 1:
        case 3:
            SetFriendAreaActionMenuState(2);
            break;
        case 2:
            sub_8027EB8();
            sub_808D31C(gUnknown_203B2BC->pokeStruct);
            break;
    }
  }
}

void sub_8027B28(void)
{
  switch(sub_801A6E8(1))
  {
    case 3:
        gUnknown_203B2BC->id = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.id = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->id].id;
        gUnknown_203B2BC->itemToGive.quantity = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->id].quantity;
        SetFriendAreaActionMenuState(0xc);
        break;
    case 4:
        gUnknown_203B2BC->id = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.id = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->id].id;
        gUnknown_203B2BC->itemToGive.quantity = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->id].quantity;
        sub_8099690(0);
        SetFriendAreaActionMenuState(0xd);
        break;
    case 2:
        sub_801A928();
        SetFriendAreaActionMenuState(2);
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
  sub_801A6E8(0);
  if ((sub_8012FD8(&gUnknown_203B2BC->unk7C) == 0) && (sub_8013114(&gUnknown_203B2BC->unk7C,&menuAction), menuAction != 1)) {
    gUnknown_203B2BC->menuAction2 = menuAction;
  }
  switch(menuAction)
  {
    case 10:
        PlaySound(0x14d);
        ShiftItemsDownFrom(gUnknown_203B2BC->id);
        FillInventoryGaps();
        if (gUnknown_203B2BC->item2.id != ITEM_NOTHING) {
            AddHeldItemToInventory(&gUnknown_203B2BC->item2);
        }
        GivePokemonItem(gUnknown_203B2BC->targetPoke,&gUnknown_203B2BC->itemToGive);
        sub_801A928();
        nullsub_104();
        SetFriendAreaActionMenuState(2);
        break;
    case 4:
        sub_8099690(0);
        SetFriendAreaActionMenuState(0xd);
        break;
    case 1:
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
            SetFriendAreaActionMenuState(0x2);
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
            if(gTeamInventory_203B460->teamStorage[pokeStruct->heldItem.id] + pokeStruct->heldItem.quantity > 0x3e7)
                return FALSE;
        }
        else if(gTeamInventory_203B460->teamStorage[pokeStruct->heldItem.id] > 0x3e6)
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
                gTeamInventory_203B460->teamStorage[gUnknown_203B2BC->item2.id] += gUnknown_203B2BC->item2.quantity;
            else
                gTeamInventory_203B460->teamStorage[gUnknown_203B2BC->item2.id] += 1;
            gUnknown_203B2BC->item2.id = ITEM_NOTHING;
            gUnknown_203B2BC->item2.quantity = 0;
            GivePokemonItem(gUnknown_203B2BC->targetPoke, &gUnknown_203B2BC->item2);
            SetFriendAreaActionMenuState(7);
            break;
        case 0:
        default:
            SetFriendAreaActionMenuState(2);
            break;
    }
}

