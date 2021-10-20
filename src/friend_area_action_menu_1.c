#include "global.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "item.h"
#include "team_inventory.h"
#include "friend_area_action_menu.h"

extern struct unkStruct_203B2BC *gUnknown_203B2BC;
extern struct TeamInventory *gTeamInventory_203B460;

u32 sub_801B410();
void sub_801B450();
u32 sub_801EF38(u8 r0);
void sub_801F214();

extern void SetFriendAreaActionMenuState(u32);
extern u8 sub_8012FD8(u32 *r0);
extern void sub_8013114(u32 *, s32 *);
extern void PlaySound(u32);
extern void ShiftItemsDownFrom(u32);
extern void FillInventoryGaps();
extern void nullsub_104();
extern void sub_8091274(struct ItemSlot *);
extern void sub_801A928();
extern void sub_8099690(u32);
extern void GivePokemonItem(s16, struct HeldItem *);
extern u32 sub_801A8AC();
extern u32 sub_801A6E8(u32);

extern s32 sub_80144A4(s32 *);
extern void sub_8027EB8();
extern void sub_808D31C(struct unkSubStruct_203B2BC *);

void sub_8027AE4(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
      switch(local_8)
      {
        case 1:
        case 3:
            SetFriendAreaActionMenuState(2);
            break;
        case 2:
            sub_8027EB8();
            sub_808D31C(gUnknown_203B2BC->unk18);
            break;
    }
  }
}

void sub_8027B28(void)
{
  switch(sub_801A6E8(1))
  {
    case 3:
        gUnknown_203B2BC->itemIndex = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.itemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].itemIndex;
        gUnknown_203B2BC->itemToGive.numItems = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].numItems;
        SetFriendAreaActionMenuState(0xc);
        break;
    case 4:
        gUnknown_203B2BC->itemIndex = sub_801A8AC();
        gUnknown_203B2BC->itemToGive.itemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].itemIndex;
        gUnknown_203B2BC->itemToGive.numItems = gTeamInventory_203B460->teamItems[gUnknown_203B2BC->itemIndex].numItems;
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
    gUnknown_203B2BC->unk74 = menuAction;
  }
  switch(menuAction)
  {
    case 10:
        PlaySound(0x14d);
        ShiftItemsDownFrom(gUnknown_203B2BC->itemIndex);
        FillInventoryGaps();
        if (gUnknown_203B2BC->unk14.itemFlags != 0) {
            sub_8091274(&gUnknown_203B2BC->unk14);
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
