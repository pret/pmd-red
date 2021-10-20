#include "global.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "item.h"
#include "team_inventory.h"
#include "pokemon.h"
#include "friend_area_action_menu.h"

extern struct unkStruct_203B2BC *gUnknown_203B2BC;
extern struct TeamInventory *gTeamInventory_203B460;

u32 sub_801B410();
void sub_801B450();
extern u32 sub_801EF38(u8 r0);
extern void sub_801F214();

extern void SetFriendAreaActionMenuState(u32);
extern u8 sub_8012FD8(u32 *r0);
extern void sub_8013114(u32 *, s32 *);
extern void PlaySound(u32);
extern void nullsub_104();
extern void sub_801A928();
extern void sub_8099690(u32);
extern void GivePokemonItem(s16, struct HeldItem *);
extern u32 sub_801A8AC();
extern u32 sub_801A6E8(u32);

extern s32 sub_80144A4(s32 *);
extern void sub_8027EB8();
extern void sub_808D31C(struct PokemonStruct *);
u32 sub_8027E18(struct PokemonStruct *);
bool8 IsNotMoneyOrUsedTMItem(u8 id);
u8 sub_8027E4C(struct PokemonStruct *r0);
extern u8 sub_80023E4(u32);
extern struct PokemonStruct *sub_808D3F8(void);
extern struct PokemonStruct *sub_808D3BC(void);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern u8 gUnknown_80DD958[];
extern void xxx_format_and_draw(u32, u32, u8 *, ...);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u8 gUnknown_202DE58[];
extern u32 sub_801F194(void);

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
        if (gUnknown_203B2BC->unk14.itemIndex != 0) {
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

void sub_8027CA0(void)
{
    switch(sub_801EF38(1))
    {
        case 3:
        case 4:
            gUnknown_203B2BC->unk20 = sub_801F194();
            gUnknown_203B2BC->unk24 = gUnknown_203B2BC->unk28[gUnknown_203B2BC->unk20].moveID;
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

void sub_8027D1C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendAreaActionMenuState(gUnknown_203B2BC->unk4);
    }
}

void sub_8027D40(u32 r0, struct HeldItem *heldItem)
{

    struct ItemSlot slot;
    struct unkStruct_8090F58 a3;

    sub_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&slot, heldItem);
    a3.unk0 = 0;
    a3.unk4 = 0;
    a3.unk8 = 1;
    slot.itemFlags = 1;
    sub_8090E14(gUnknown_202DE58, &slot, &a3);
    xxx_format_and_draw(4, 3, gUnknown_80DD958, r0, 0);
    sub_80073E0(r0);
}

u32 sub_8027D9C(struct PokemonStruct *r0)
{
    u32 var1;
    if(r0->unk2 == 0)
    {
        var1 = 0;
        if(r0->unk4.unk4 == 0x41)
            var1 = 1;
            if(var1 != 0)
            {
                if(sub_80023E4(8) == 0)
                    return 0;
            }
    }
    else
        return 0;
    return 1;
}

u32 sub_8027DCC(struct PokemonStruct *r0)
{
    u32 var1;
    if(sub_808D3BC() != r0)
        if(sub_808D3F8() != r0)
            if(r0->unk2 == 0)
            {
                var1 = 0;
                if(r0->unk4.unk4 == 0x41)
                    var1 = 1;
                if(var1 != 0)
                {
                    if(sub_80023E4(8) != 0)
                        goto check;
                }
                else
                {
                    check:
                    if(sub_8027E18(r0) != 3)
                        return 1;
                }
            }
    return 0;
}

u32 sub_8027E18(struct PokemonStruct *r0)
{
    if(r0->heldItem.itemIndex == 0)
        return 0;
    else if(GetNumberOfFilledInventorySlots() < INVENTORY_SIZE)
        return 1;
    else if(sub_8027E4C(r0))
        return 2;
    else
        return 3;
}

u8 sub_8027E4C(struct PokemonStruct *r0)
{
    if(!IsNotMoneyOrUsedTMItem(r0->heldItem.itemIndex))
        return 0;
    else
    {
        if(IsThrowableItem(r0->heldItem.itemIndex))
        {
            if(gTeamInventory_203B460->teamStorage[r0->heldItem.itemIndex] + r0->heldItem.numItems > 0x3e7)
                return 0;
        }
        else if(gTeamInventory_203B460->teamStorage[r0->heldItem.itemIndex] > 0x3e6)
        {
            return 0;
        }
    }
    return 1;
}

void sub_8027EB8(void)
{
    switch(sub_8027E18(gUnknown_203B2BC->unk18))
    {
        case 1:
            PlaySound(0x14d);
            sub_8091274(&gUnknown_203B2BC->unk14);
            FillInventoryGaps();
            gUnknown_203B2BC->unk14.itemIndex = 0;
            gUnknown_203B2BC->unk14.numItems = 0;
            GivePokemonItem(gUnknown_203B2BC->targetPoke, &gUnknown_203B2BC->unk14);
            SetFriendAreaActionMenuState(6);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrowableItem(gUnknown_203B2BC->unk14.itemIndex))
                gTeamInventory_203B460->teamStorage[gUnknown_203B2BC->unk14.itemIndex] += gUnknown_203B2BC->unk14.numItems;
            else
                gTeamInventory_203B460->teamStorage[gUnknown_203B2BC->unk14.itemIndex] += 1;
            gUnknown_203B2BC->unk14.itemIndex = 0;
            gUnknown_203B2BC->unk14.numItems = 0;
            GivePokemonItem(gUnknown_203B2BC->targetPoke, &gUnknown_203B2BC->unk14);
            SetFriendAreaActionMenuState(7);
            break;
        case 0:
        default:
            SetFriendAreaActionMenuState(2);
            break;
    }
}

