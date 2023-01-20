#include "global.h"
#include "file_system.h"
#include "memory.h"
#include "pokemon.h"
#include "input.h"
#include "item.h"
#include "kecleon_items.h"
#include "team_inventory.h"
#include "code_800D090.h"

extern struct unkStruct_203B210 *gUnknown_203B210;
extern u16 gUnknown_203B218;
extern u16 gUnknown_203B220;
extern u16 gUnknown_203B228;
extern u16 gUnknown_203B22A;
extern u8 gUnknown_80DB8E4[];
extern u8 gUnknown_80DB8EC[];
extern u8 gUnknown_80DB92C[];
extern u8 gUnknown_80DB934[];
extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 gUnknown_80DB9A8[];
extern u8 gUnknown_80DB9B0[];
extern u8 gTeamToolboxA[];
extern u8 gTeamToolboxB[];
extern u8 gUnknown_80DB9A0[];
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_80DB994[];


extern s32 sub_80144A4(s32 *);
void UpdateKecleonStoreState(u32);
extern u32 sub_801B410(void);
extern void sub_801B450(void);

extern void sub_8099690(u32);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern u32 sub_8019EDC(u8);
extern u32 sub_801A2A8(u8);
extern s32 sub_801A8AC(void);
extern u32 sub_801A6E8(u8);
extern void sub_801A928(void);
extern void DrawTeamMoneyBox(u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern s32 sub_8013800(void *, u32);
extern void  xxx_call_draw_string(s32 x, s32, u8 *, u32, u32);
extern void sub_8012BC4(s32, s32, s32, s32, s32, s32);
extern void xxx_format_and_draw(u32, u32, u8 *, u32, u32);
extern s32 sub_801AED0(s32);
void sub_8007B7C(s32, s32, s32, s32, s32);
extern void sub_801AE84(void);
extern void sub_8012D08(void *, u32);
extern void sub_801A998(void);
extern void sub_801A9E0(void);
extern void Kecleon_SortItems(void);
extern bool8 sub_801ADA0(s32);
extern s32 sub_801AEA8(void);
s32 sub_801AE24(u32);


extern struct unkStruct_203B224 *gUnknown_203B224;

struct unkStruct_203B214
{;
    // size: 0xA0
    u8 fill0[0x18];
    u16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    u16 shopItemCount;
    u8 fill24[0x34 - 0x24];
    u32 unk34;
    struct UnkTextStruct2 *unk38;
    struct UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

extern struct unkStruct_203B214 *gUnknown_203B214;
extern struct unkStruct_203B214 *gUnknown_203B21C;

extern void sub_8013818(void *, u32, u32, u32);

extern u8 sub_8019FB0(void);
extern u8 sub_80138B8(void *, u32);

extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(void *);
extern void sub_8013660(void *);

extern struct UnkTextStruct2 gUnknown_80DB8CC;
extern struct UnkTextStruct2 gUnknown_80DB8B4;
extern struct UnkTextStruct2 gUnknown_80DB8FC;
extern struct UnkTextStruct2 gUnknown_80DB944;
extern struct UnkTextStruct2 gUnknown_80DB95C;
extern const struct UnkTextStruct2 gUnknown_80DB914;
extern void sub_801A430(void);
extern void sub_801A4A4(void);
extern void sub_8013984(u8 *);
extern void sub_801A064(void);
extern void sub_801A0D8(void);
extern void AddMenuCursorSprite(void *);
extern u8 sub_801A37C(void);

extern void sub_801A010(void);
extern void sub_801A3DC(void);
extern void sub_801AD34(u32);
extern void PlaySound(u16 songIndex);

u32 CountKecleonItems(void);

void sub_8019700(void)
{
    u32 menuAction;
    struct unkStruct_203B210 *preload;
    u8 *nullText;

    preload = gUnknown_203B210;
    nullText = NULL;
    preload->unk34[0].text = *gUnknown_80D4920;
    preload->unk34[0].menuAction = 5;
    menuAction = 1;
    preload->unk34[1].text = *gUnknown_80D4928;
    preload->unk34[1].menuAction = 6;
    preload->unk34[2].text = nullText;
    preload->unk34[2].menuAction = menuAction;
}

void sub_8019730(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) != 0)
    return;
  if (menuAction != 1)
    gUnknown_203B210->unk28 = menuAction;
  switch(menuAction) {
    case 2:
        if (CountKecleonItems() == 0)
            UpdateKecleonStoreState(5);
        else if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
            UpdateKecleonStoreState(0xA);
        else
            UpdateKecleonStoreState(0xF);
        break;
    case 3:
        if (GetNumberOfFilledInventorySlots() == 0)
            UpdateKecleonStoreState(9);
        else if (gUnknown_203B210->numInventoryItemToSell == 0)
            UpdateKecleonStoreState(8);
        else if (gTeamInventory_203B460->teamMoney < 99999)
            UpdateKecleonStoreState(0x17);
        else
            UpdateKecleonStoreState(7);
        break;
    case 4:
        if (GetNumberOfFilledInventorySlots() == 0)
            UpdateKecleonStoreState(9);
        else if (gUnknown_203B210->numInventoryItemToSell == 0)
            UpdateKecleonStoreState(8);
        else if (gUnknown_203B210->inventoryItemSellPrice + gTeamInventory_203B460->teamMoney > 99999)
            UpdateKecleonStoreState(7);
        else
            UpdateKecleonStoreState(0x1f);
        break;
    case 7:
        UpdateKecleonStoreState(2);
        break;
    case 1:
        UpdateKecleonStoreState(3);
        break;
  }
}

void sub_8019850(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
      switch(menuAction)
      {
          case 5:
            AddToTeamMoney(-gUnknown_203B210->itemSellPrice);
            if (gUnknown_203B210->isKecleonItemShop) {
                AddHeldItemToInventory(GetKecleonShopItem(gUnknown_203B210->itemShopItemIndex));
                InitKecleonShopItem(gUnknown_203B210->itemShopItemIndex);
                FillKecleonShopGaps();
            }
            else {
                AddHeldItemToInventory(GetKecleonWareItem(gUnknown_203B210->wareShopItemIndex));
                InitKecleonWareItem(gUnknown_203B210->wareShopItemIndex);
                FillKecleonWareGaps();
            }
            PlaySound(0x14c);
            UpdateKecleonStoreState(0x11);
            break;
        case 6:
        case 1:
            UpdateKecleonStoreState(0x10);
            break;
      }
  }
}

void sub_80198E8(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
      switch(menuAction)
      {
          case 5:
            AddToTeamMoney(gUnknown_203B210->itemSellPrice);
            ShiftItemsDownFrom(gUnknown_203B210->unk24);
            PlaySound(0x14c);
            UpdateKecleonStoreState(0x19);
            break;
        case 6:
        case 1:
            UpdateKecleonStoreState(0x18);
            break;
      }
  }
}

void sub_8019944(void)
{
  s32 slotIndex;
  s32 menuAction;
  struct Item *item;

  if (sub_80144A4(&menuAction) == 0) {
    switch(menuAction)
    {
        case 5:
            for(slotIndex = 0; slotIndex < INVENTORY_SIZE; slotIndex++)
            {
                item = &gTeamInventory_203B460->teamItems[slotIndex];
                if ((item->flags & ITEM_FLAG_EXISTS) && CanSellItem(item->id)) {
                    ClearItemSlotAt(slotIndex);
                }
            }
            FillInventoryGaps();
            AddToTeamMoney(gUnknown_203B210->inventoryItemSellPrice);
            PlaySound(0x14c);
            UpdateKecleonStoreState(0x20);
            break;
        case 1:
        case 6:
            UpdateKecleonStoreState(1);
            break;
    }
  }
}

void sub_80199CC(void)
{
  u32 uVar2;
  struct BulkItem *item;

  if (gUnknown_203B210->isKecleonItemShop) {
    uVar2 = sub_8019EDC(1);
  }
  else {
    uVar2 = sub_801A2A8(1);
  }

  switch(uVar2)
  {
    case 3:
        if (gUnknown_203B210->isKecleonItemShop) {
            gUnknown_203B210->itemShopItemIndex = sub_8019FB0();
            item = GetKecleonShopItem(gUnknown_203B210->itemShopItemIndex);
        }
        else {
            gUnknown_203B210->wareShopItemIndex = sub_801A37C();
            item = GetKecleonWareItem(gUnknown_203B210->wareShopItemIndex);
        }
        xxx_init_itemslot_8090A8C(&gUnknown_203B210->unk1C,item->id,0);
        gUnknown_203B210->unk1C.quantity =item->quantity;
        gUnknown_203B210->itemSellPrice = GetStackBuyPrice(&gUnknown_203B210->unk1C);
        UpdateKecleonStoreState(0x14);
        break;
    case 4:
        if (gUnknown_203B210->isKecleonItemShop) {
            gUnknown_203B210->itemShopItemIndex = sub_8019FB0();
            item = GetKecleonShopItem(gUnknown_203B210->itemShopItemIndex);
        }
        else {
            gUnknown_203B210->wareShopItemIndex = sub_801A37C();
            item = GetKecleonWareItem(gUnknown_203B210->wareShopItemIndex);
        }
        xxx_init_itemslot_8090A8C(&gUnknown_203B210->unk1C,item->id,0);
        gUnknown_203B210->unk1C.quantity = item->quantity;
        gUnknown_203B210->itemSellPrice = GetStackBuyPrice(&gUnknown_203B210->unk1C);
        UpdateKecleonStoreState(0x15);
        break;
    case 2:
        if (gUnknown_203B210->isKecleonItemShop)
            sub_801A010();
        else
            sub_801A3DC();
        UpdateKecleonStoreState(1);
        break;
    case 1:
        sub_801AD34(0);
        DrawTeamMoneyBox(1);
        break;
  }
}

void sub_8019B08(void)
{
  switch(sub_801A6E8(1))
  {
    case 0:
        break;
    case 3:
        gUnknown_203B210->unk24 = sub_801A8AC();
        gUnknown_203B210->unk1C = gTeamInventory_203B460->teamItems[gUnknown_203B210->unk24];
        gUnknown_203B210->itemSellPrice = GetStackSellPrice(&gUnknown_203B210->unk1C);
        UpdateKecleonStoreState(0x1c);
        break;
    case 4:
        gUnknown_203B210->unk24 = sub_801A8AC();
        gUnknown_203B210->unk1C = gTeamInventory_203B460->teamItems[gUnknown_203B210->unk24];
        gUnknown_203B210->itemSellPrice = GetStackSellPrice(&gUnknown_203B210->unk1C);
        sub_8099690(0);
        UpdateKecleonStoreState(0x1d);
        break;
    case 2:
        sub_801A928();
        UpdateKecleonStoreState(1);
        break;
    case 1:
    default:
        DrawTeamMoneyBox(1);
        break;
  }
}

void sub_8019BBC(void)
{
  int menuAction;

  menuAction = 0;
  if (gUnknown_203B210->isKecleonItemShop) {
    sub_8019EDC(0);
  }
  else {
    sub_801A2A8(0);
  }
  if ((sub_8012FD8(&gUnknown_203B210->unk84) == 0) && (sub_8013114(&gUnknown_203B210->unk84,&menuAction), menuAction != 1)) {
    gUnknown_203B210->unk30 = menuAction;
  }
  switch(menuAction){
      case 2:
        if (gTeamInventory_203B460->teamMoney == 0)
            UpdateKecleonStoreState(0x6);
        else if (gUnknown_203B210->itemSellPrice > gTeamInventory_203B460->teamMoney)
            UpdateKecleonStoreState(0xC);
        else
            UpdateKecleonStoreState(0x16);
        break;
    case 7:
        UpdateKecleonStoreState(0x15);
        break;
    case 1:
        UpdateKecleonStoreState(0x13);
        break;
  }
}

void sub_8019C78(void)
{
  int menuAction;

  menuAction = 0;
  sub_801A6E8(0);
  if ((sub_8012FD8(&gUnknown_203B210->unk84) == '\0') && (sub_8013114(&gUnknown_203B210->unk84,&menuAction), menuAction != 1)) {
    gUnknown_203B210->unk2C = menuAction;
  }
  switch(menuAction){
      case 3:
        sub_8099690(0);
        if (!CanSellItem(gUnknown_203B210->unk1C.id))
            UpdateKecleonStoreState(0xd);
        else if (gUnknown_203B210->itemSellPrice + gTeamInventory_203B460->teamMoney > 99999)
            UpdateKecleonStoreState(0xe);
        else
            UpdateKecleonStoreState(0x1e);
        break;
    case 7:
        sub_8099690(0);
        UpdateKecleonStoreState(0x1d);
        break;
    case 1:
        UpdateKecleonStoreState(0x1b);
        break;
  }
}

void sub_8019D30(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            UpdateKecleonStoreState(0x13);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8019D4C(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            UpdateKecleonStoreState(0x1B);
            break;
        case 0:
        case 1:
            break;
    }
}


void sub_8019D68(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateKecleonStoreState(gUnknown_203B210->fallbackState);
    }
}

u32 CountKecleonItems(void)
{
    if(gUnknown_203B210->isKecleonItemShop)
        return CountKecleonShopItems();
    else
        return CountKecleonWareItems();
}

void sub_8019DAC(void)
{
  s32 sellPrice;
  struct Item *item;
  s32 index;

  gUnknown_203B210->numInventoryItemToSell = 0;
  gUnknown_203B210->inventoryItemSellPrice = 0;
  for(index = 0; index < INVENTORY_SIZE; index++){
    item = &gTeamInventory_203B460->teamItems[index];
    if (((item->flags & ITEM_FLAG_EXISTS) != 0) && (CanSellItem(item->id))) {
      sellPrice = GetStackSellPrice(item);
      gUnknown_203B210->inventoryItemSellPrice += sellPrice;
      gUnknown_203B210->numInventoryItemToSell++;
    }
  }
}

void sub_8019E04(s32 param_1)
{

  if (gUnknown_203B210->isKecleonItemShop) {
    if (param_1 == 1)
        gUnknown_203B210->unkE0 = 1;
    else
        gUnknown_203B210->unkE0 = 0;
  }
  else
  {
    if (param_1 == 1)
      gUnknown_203B210->unkE0 = 7;
    else
      gUnknown_203B210->unkE0  = 6;
  }
}

u32 sub_8019E40(u32 r0)
{
    if(CountKecleonShopItems() == 0)
    {
        return 0;
    }
    else
    {
        gUnknown_203B214 = MemoryAlloc(sizeof(struct unkStruct_203B214), 0x8);
        gUnknown_203B214->unk34 = r0;
        gUnknown_203B214->unk38 = &gUnknown_203B214->unk3C[gUnknown_203B214->unk34];
        sub_8006518(gUnknown_203B214->unk3C);
        gUnknown_203B214->unk3C[gUnknown_203B214->unk34] = gUnknown_80DB8CC;
        gUnknown_203B214->unk38->unk14 = gUnknown_203B214->unk9C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B214->unk3C, 1, 1);
        sub_8013818(gUnknown_203B214, CountKecleonShopItems(), 0xA, r0);
        gUnknown_203B214->unk18 = gUnknown_203B218;
        sub_8013984((u8 *)gUnknown_203B214);
        sub_801A064();
        sub_801A0D8();
        return 1;
    }
}

u32 sub_8019EDC(u8 r0)
{
    struct Item slot;
    struct BulkItem *item;

    if(r0 == 0)
    {
        sub_8013660(gUnknown_203B214);
        return 0;
    }
    else
    {
        switch(GetKeyPress(gUnknown_203B214))
        {
            case 2:
                PlayMenuSoundEffect(1);
                return 2;
            case 1:
                item = GetKecleonShopItem(sub_8019FB0());
                slot.id = item->id;
                slot.quantity = item->quantity;
                if(GetStackBuyPrice(&slot) > gTeamInventory_203B460->teamMoney)
                {
                    PlayMenuSoundEffect(2);
                }
                else
                {
                    PlayMenuSoundEffect(0);
                }
                 return 3;
            case 4:
                PlayMenuSoundEffect(4);
                return 4;
            default:
                if(sub_80138B8(gUnknown_203B214, 1) != 0)
                {
                    sub_801A064();
                    sub_801A0D8();
                    return 1;
                }
                else
                {
                    return 0;
                }
        }
    }
}

u8 sub_8019FB0(void)
{
    return (gUnknown_203B214->unk1E * gUnknown_203B214->unk1C) + (u8)gUnknown_203B214->unk18;
}

void sub_8019FCC(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, 0, 0);
    gUnknown_203B214->shopItemCount = CountKecleonShopItems();
    sub_8013984((u8 *)gUnknown_203B214);
    sub_801A064();
    sub_801A0D8();
    if(r0)
        AddMenuCursorSprite(gUnknown_203B214);
}

void sub_801A010(void)
{
    if(gUnknown_203B214 != NULL)
    {
        gUnknown_203B218 = gUnknown_203B214->unk18;
        gUnknown_203B214->unk3C[gUnknown_203B214->unk34] = gUnknown_80DB8B4;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B214->unk3C, 1, 1);
        MemoryFree(gUnknown_203B214);
        gUnknown_203B214 = NULL;
    }
}

NAKED
void sub_801A064(void)
{
    asm_unified(
            "\tpush {r4,lr}\n"
            "\tldr r4, _0801A0D4\n"
            "\tldr r0, [r4]\n"
            "\tldrh r1, [r0, 0x20]\n"
            "\tadds r0, 0x9C\n"
            "\tmovs r2, 0\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tldrh r1, [r0, 0x1E]\n"
            "\tadds r0, 0x9D\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x9E\n"
            "\tmovs r1, 0xA\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x9F\n"
            "\tstrb r2, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tmovs r1, 0x1A\n"
            "\tldrsh r0, [r0, r1]\n"
            "\tmovs r1, 0xC\n"
            "\tbl sub_80095E4\n"
            "\tadds r0, 0x2\n"
            "\tlsls r0, 16\n"
            "\tldr r2, [r4]\n"
            "\tldr r3, [r2, 0x34]\n"
            "\tlsls r1, r3, 1\n"
            "\tadds r1, r3\n"
            "\tlsls r1, 3\n"
            "\tadds r1, r2, r1\n"
            "\tadds r1, 0x4A\n"
            "\tasrs r3, r0, 16\n"
            "\tlsrs r0, 16\n"
            "\tstrh r0, [r1]\n"
            "\tldr r1, [r2, 0x34]\n"
            "\tlsls r0, r1, 1\n"
            "\tadds r0, r1\n"
            "\tlsls r0, 3\n"
            "\tadds r2, r0\n"
            "\tadds r3, 0x2\n"
            "\tadds r2, 0x4C\n"
            "\tstrh r3, [r2]\n"
            "\tbl ResetUnusedInputStruct\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x3C\n"
            "\tmovs r1, 0x1\n"
            "\tmovs r2, 0x1\n"
            "\tbl sub_800641C\n"
            "\tpop {r4}\n"
            "\tpop {r0}\n"
            "\tbx r0\n"
            "\t.align 2, 0\n"
    "_0801A0D4: .4byte gUnknown_203B214");
}

void sub_801A0D8(void)
{
  struct BulkItem *heldItem;
  s32 buyPrice;
  s32 y;
  s32 index;
  u8 auStack204 [80];
  struct unkStruct_8090F58 local_7c;
  u8 auStack112 [80];
  struct Item item;
  u8 temp_calc;

  // Needed for the shifts..
  u32 index_shift;
  u32 quantity_shift;

  sub_8008C54(gUnknown_203B214->unk34);
  sub_80073B8(gUnknown_203B214->unk34);
  xxx_call_draw_string(gUnknown_203B214->unk1E * 8 + 10,0,gUnknown_80DB8E4,
                        gUnknown_203B214->unk34,0);

  for(index = 0; index < gUnknown_203B214->unk1A; index++)
    {
      temp_calc = (gUnknown_203B214->unk1E * gUnknown_203B214->unk1C) + index;
      heldItem = GetKecleonShopItem(temp_calc);
      item.id = heldItem->id;
      item.quantity = heldItem->quantity;
      item.flags = (ITEM_FLAG_EXISTS | ITEM_FLAG_IN_SHOP);
      local_7c.unk0 = 1;
      local_7c.unk4 = 0;
      local_7c.unk6 = 0x58;
      local_7c.unk8 = 1;
      sub_8090E14(auStack204,&item,&local_7c);
      buyPrice = GetStackBuyPrice(&item);
      if (buyPrice <= gTeamInventory_203B460->teamMoney) {
        y = sub_8013800(gUnknown_203B214,index);
        xxx_call_draw_string(8,y,auStack204,gUnknown_203B214->unk34,0);
      }
      else {
        sprintfStatic(auStack112,gUnknown_80DB8EC,auStack204);
        y = sub_8013800(gUnknown_203B214,index);
        xxx_call_draw_string(8,y,auStack112,gUnknown_203B214->unk34,0);
      }
   }
  sub_80073E0(gUnknown_203B214->unk34);
}

u32 sub_801A20C(u32 r0)
{
    if(CountKecleonWareItems() == 0)
    {
        return 0;
    }
    else
    {
        gUnknown_203B21C = MemoryAlloc(sizeof(struct unkStruct_203B214), 0x8);
        gUnknown_203B21C->unk34 = r0;
        gUnknown_203B21C->unk38 = &gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34];
        sub_8006518(gUnknown_203B21C->unk3C);
        gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34] = gUnknown_80DB914;
        gUnknown_203B21C->unk38->unk14 = gUnknown_203B21C->unk9C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B21C->unk3C, 1, 1);
        sub_8013818(gUnknown_203B21C, CountKecleonWareItems(), 0xA, r0);
        gUnknown_203B21C->unk18 = gUnknown_203B220;
        sub_8013984((u8 *)gUnknown_203B21C);
        sub_801A430();
        sub_801A4A4();
        return 1;
    }
}

u32 sub_801A2A8(u8 r0)
{
    struct Item slot;
    struct BulkItem *item;

    if(r0 == 0)
    {
        sub_8013660(gUnknown_203B21C);
        return 0;
    }
    else
    {
        switch(GetKeyPress(gUnknown_203B21C))
        {
            case 2:
                PlayMenuSoundEffect(1);
                return 2;
            case 1:
                item = GetKecleonWareItem(sub_801A37C());

                // NOTE: needs seperate vars to match
                slot.id = item->id;
                slot.quantity = item->quantity;

                if(GetStackBuyPrice(&slot) > gTeamInventory_203B460->teamMoney)
                {
                    PlayMenuSoundEffect(2);
                }
                else
                {
                    PlayMenuSoundEffect(0);
                }
                 return 3;
            case 4:
                PlayMenuSoundEffect(4);
                return 4;
            default:
                if(sub_80138B8(gUnknown_203B21C, 1) != 0)
                {
                    sub_801A430();
                    sub_801A4A4();
                    return 1;
                }
                else
                {
                    return 0;
                }
        }
    }
}

u8 sub_801A37C(void)
{
    return (gUnknown_203B21C->unk1E * gUnknown_203B21C->unk1C) + gUnknown_203B21C->unk18;
}

void sub_801A398(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B21C->unk3C, 0, 0);
    gUnknown_203B21C->shopItemCount = CountKecleonWareItems();
    sub_8013984((u8 *)gUnknown_203B21C);
    sub_801A430();
    sub_801A4A4();
    if(r0)
        AddMenuCursorSprite(gUnknown_203B21C);
}

void sub_801A3DC(void)
{
    if(gUnknown_203B21C != NULL)
    {
        gUnknown_203B220 = gUnknown_203B21C->unk18;
        gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34] = gUnknown_80DB8FC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B21C->unk3C, 1, 1);
        MemoryFree(gUnknown_203B21C);
        gUnknown_203B21C = NULL;
    }
}

NAKED
void sub_801A430(void)
{
	asm_unified("\tpush {r4,lr}\n"
	"\tldr r4, _0801A4A0\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x20]\n"
	"\tadds r0, 0x9C\n"
	"\tmovs r2, 0\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x1E]\n"
	"\tadds r0, 0x9D\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9E\n"
	"\tmovs r1, 0xA\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9F\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x1A\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x34]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x4A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x34]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x4C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801A4A0: .4byte gUnknown_203B21C");
}

void sub_801A4A4(void)
{
  struct BulkItem *heldItem;
  s32 buyPrice;
  s32 y;
  s32 index;
  u8 buffer1 [80];
  struct unkStruct_8090F58 local_7c;
  u8 buffer2 [80];
  struct Item item;
  u8 temp_calc;

  // Needed for the shifts..
  u32 index_shift;
  u32 quantity_shift;

  sub_8008C54(gUnknown_203B21C->unk34);
  sub_80073B8(gUnknown_203B21C->unk34);
  xxx_call_draw_string(gUnknown_203B21C->unk1E * 8 + 10,0,gUnknown_80DB92C,
                        gUnknown_203B21C->unk34,0);

  for(index = 0; index < gUnknown_203B21C->unk1A; index++)
    {
      temp_calc = (gUnknown_203B21C->unk1E * gUnknown_203B21C->unk1C) + index;
      heldItem = GetKecleonWareItem(temp_calc);
      item.id = heldItem->id;
      item.quantity = heldItem->quantity;
      item.flags =  (ITEM_FLAG_EXISTS | ITEM_FLAG_IN_SHOP);
      local_7c.unk0 = 1;
      local_7c.unk4 = 0;
      local_7c.unk6 = 0x58;
      local_7c.unk8 = 1;
      sub_8090E14(buffer1,(struct Item *)&item,&local_7c);
      buyPrice = GetStackBuyPrice((struct Item *)&item);
      if (buyPrice <= gTeamInventory_203B460->teamMoney) {
        y = sub_8013800(gUnknown_203B21C,index);
        xxx_call_draw_string(8,y,buffer1,gUnknown_203B21C->unk34,0);
      }
      else {
        sprintfStatic(buffer2,gUnknown_80DB934,buffer1);
        y = sub_8013800(gUnknown_203B21C,index);
        xxx_call_draw_string(8,y,buffer2,gUnknown_203B21C->unk34,0);
      }
   }
  sub_80073E0(gUnknown_203B21C->unk34);
}

u32 sub_801A5D8(u32 param_1,int param_2,struct UnkTextStruct2_sub *param_3,u32 param_4)
{

  if (GetNumberOfFilledInventorySlots() == 0) {
      return 0;
  }
  else {
    if (gUnknown_203B224 == NULL) {
        gUnknown_203B224 = MemoryAlloc(sizeof(struct unkStruct_203B224),8);
    }
    gUnknown_203B224->unk0 = param_1;
    FillInventoryGaps();
    sub_801AE84();

    gUnknown_203B224->unk88 = param_2;
    gUnknown_203B224->unk8C = &gUnknown_203B224->unk90[param_2];

    sub_8006518(gUnknown_203B224->unk90);
    gUnknown_203B224->unk90[gUnknown_203B224->unk88] = gUnknown_80DB95C;

    gUnknown_203B224->unk8C->unk14 = gUnknown_203B224->unkF0;
    if (param_3 != NULL) {
        gUnknown_203B224->unk90[gUnknown_203B224->unk88].unk08 = *param_3;
    }
    sub_8012D08(gUnknown_203B224->unk8C,param_4);
    sub_8099690(1);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90,1,1);
    sub_8013818(&gUnknown_203B224->unk54,GetNumberOfFilledInventorySlots(),param_4,param_2);
    gUnknown_203B224->unk6C = gUnknown_203B228;
    gUnknown_203B224->unk72 = gUnknown_203B22A;
    sub_8013984((u8 *)&gUnknown_203B224->unk54);
    sub_801A998();
    sub_801A9E0();
    return 1;
  }
}

u32 sub_801A6E8(u8 param_1)
{
  s32 index;
  struct Item item;

  if (param_1 == 0) {
    sub_8013660(&gUnknown_203B224->unk54);
    return 0;
  }
  switch(GetKeyPress(&gUnknown_203B224->unk54)) {
    case 2:
        PlayMenuSoundEffect(1);
        return 2;
    case 1:
        switch(gUnknown_203B224->unk0) {
            case 0:
            case 1:
            case 2:
                if (gUnknown_203B224->unk4[sub_801A8AC()] != 0)
                    PlayMenuSoundEffect(2);
                else
                    PlayMenuSoundEffect(0);
                break;
            case 3:
                if ((sub_801AEA8() != 0) || (sub_801ADA0(sub_801A8AC()) != 0))
                    PlayMenuSoundEffect(0);
                else
                    PlayMenuSoundEffect(2);
                break;
            case 4:
                item = gTeamInventory_203B460->teamItems[sub_801A8AC()];
                if (CanSellItem(item.id) && (GetStackSellPrice(&item) + gTeamInventory_203B460->teamMoney < 100000))
                    PlayMenuSoundEffect(0);
                else
                    PlayMenuSoundEffect(2);
                break;
            case 5:
                PlayMenuSoundEffect(0);
                break;
        }
        return 3;
    case 4:
        PlayMenuSoundEffect(4);
        return 4;
    case 5:
    case 6:
        if (gUnknown_203B224->unk0 != 3) goto _0801A87C;
        index = sub_801A8AC();
        if ((gUnknown_203B224->unk4[index] != 0) || (sub_801ADA0(index) != 0)) {
            PlayMenuSoundEffect(6);
            gUnknown_203B224->unk4[index] ^= 1;
            sub_80138B8(&gUnknown_203B224->unk54,0);
            sub_801A9E0();
            return 1;
        }
        else
        {
            PlayMenuSoundEffect(2);
            goto _0801A87C;
        }
    case 3:
        if (gUnknown_203B224->unk0 != 2) {
            PlayMenuSoundEffect(5);
            Kecleon_SortItems();
            sub_801A9E0();
        }
        // NOTE: fallthrough needed here
    default:
_0801A87C:
        if (sub_80138B8(&gUnknown_203B224->unk54,1) != '\0') {
            sub_801A998();
            sub_801A9E0();
            return 1;
        }
        else {
            return 0;
        }
        break;
  }
}

s32 sub_801A8AC(void)
{
    return (gUnknown_203B224->unk72 * gUnknown_203B224->unk70) + gUnknown_203B224->unk6C;
}

void sub_801A8D0(u8 r0)
{
    sub_8099690(1);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, 0, 0);
    FillInventoryGaps();
    gUnknown_203B224->unk76 = GetNumberOfFilledInventorySlots();
    sub_8013984((u8 *)&gUnknown_203B224->unk54);
    sub_801A998();
    sub_801A9E0();
    if(r0)
        AddMenuCursorSprite((u8 *)&gUnknown_203B224->unk54);
}

void sub_801A928(void)
{
    if(gUnknown_203B224 != NULL)
    {
        gUnknown_203B228 = gUnknown_203B224->unk6C;
        gUnknown_203B22A = gUnknown_203B224->unk72;
        gUnknown_203B224->unk90[gUnknown_203B224->unk88] = gUnknown_80DB944;
        sub_8099690(0);
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B224->unk90, 1, 1);
        MemoryFree(gUnknown_203B224);
        gUnknown_203B224 = NULL;
    }
}

void sub_801A998(void)
{
    gUnknown_203B224->unkF0[0] = gUnknown_203B224->unk74;
    gUnknown_203B224->unkF0[1] = gUnknown_203B224->unk72;
    gUnknown_203B224->unkF0[2] = 0xB;
    gUnknown_203B224->unkF0[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, 1, 1);
}

void sub_801A9E0(void)
{
    s32 teamItemIndex;
    s32 r7;
    s32 x;
    char buffer1 [0x50]; // sp 0x4
    struct unkStruct_8090F58 stack; // sp 0x54
    struct unkStruct_8090F58 stack1; // sp 0x60
    struct unkStruct_8090F58 stack2; // sp 0x6C
    struct unkStruct_8090F58 stack3; // sp 0x78
    // NOTE: this var is unused but makes sure we get correct stack size
    // This is also why we need special build flag for this file
    u8 local_6c[0x44]; // sp 0x78 ?? (why is this at same location..)
    struct Item item; // sp 0xC8

    sub_8008C54(gUnknown_203B224->unk88);
    sub_80073B8(gUnknown_203B224->unk88);
    x = gUnknown_203B224->unk72 * 8 + 10;
    if (gUnknown_203B224->unk72 == 0) {
        xxx_call_draw_string(x,0,gTeamToolboxA,gUnknown_203B224->unk88,0);
    }
    else {
        xxx_call_draw_string(x,0,gTeamToolboxB,gUnknown_203B224->unk88,0);
    }
    for(r7 = 0; r7 < gUnknown_203B224->unk6E; r7++)
    {
        teamItemIndex = (gUnknown_203B224->unk72 * gUnknown_203B224->unk70) + r7;
        item = gTeamInventory_203B460->teamItems[teamItemIndex];
        switch(gUnknown_203B224->unk0) {
            case 0:
                sub_8090E14(buffer1,&item,0);
                xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->unk54,r7),buffer1,gUnknown_203B224->unk88,0);
                break;
            case 1:
            case 2:
                stack.unk0 = 0;
                stack.unk4 = 0;
                stack.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buffer1,&item, &stack);
                xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->unk54,r7),buffer1,gUnknown_203B224->unk88,0);
                break;
            case 3:
                stack1.unk0 = 0;
                stack1.unk4 = 0;
                stack1.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buffer1,&item,&stack1);
                if (gUnknown_203B224->unk4[teamItemIndex] != 0 || sub_801ADA0(teamItemIndex) != '\0'){
                    xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->unk54,r7),buffer1,gUnknown_203B224->unk88,0);
                }
                else
                {
                    strncpy(gUnknown_202DE58,buffer1,0x50);
                    xxx_format_and_draw(8,sub_8013800(&gUnknown_203B224->unk54,r7),gUnknown_80DB994,gUnknown_203B224->unk88,0);  
                }
                break;
            case 4:
                if (CanSellItem(item.id)) {
                    stack2.unk0 = 3;
                    stack2.unk4 = 0;
                    stack2.unk6 = 0x58;
                    stack2.unk8 = 1;
                    item.flags = 3;
                    sub_8090E14(buffer1,&item, &stack2);
                    if (GetStackSellPrice(&item) + gTeamInventory_203B460->teamMoney > 99999){
                        // very dumb but this matches...
                        sprintfStatic((char *)&stack3,gUnknown_80DB9A0,buffer1);
                        xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->unk54,r7),(u8 *)&stack3,gUnknown_203B224->unk88,0);
                    }
                    else
                        xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->unk54,r7),buffer1,gUnknown_203B224->unk88,0);;
                }
                else {
                    sub_8090E14(buffer1,&item, 0);
                    strncpy(gUnknown_202DE58,buffer1,0x50);
                    xxx_format_and_draw(8,sub_8013800(&gUnknown_203B224->unk54,r7),gUnknown_80DB994,gUnknown_203B224->unk88,0);
                }
                break;
            case 5:
                stack3.unk0 = 0;
                stack3.unk4 = 0;
                stack3.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buffer1,&item,&stack3);
                if (IsGummiItem(item.id)) {
                    xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->unk54,r7),buffer1,gUnknown_203B224->unk88,0);
                }
                else
                {
                    strncpy(gUnknown_202DE58,buffer1,0x50);
                    xxx_format_and_draw(8,sub_8013800(&gUnknown_203B224->unk54,r7),gUnknown_80DB994,gUnknown_203B224->unk88,0);
                }
                break;
        }
        if ((sub_801AED0(teamItemIndex) & 1) != 0) {
            sub_8007B7C(gUnknown_203B224->unk88,8,sub_8013800(&gUnknown_203B224->unk54,r7),(gUnknown_203B224->unk8C->unk0c - 2) * 8,10);
        }
    }
    sub_80073E0(gUnknown_203B224->unk88);
}


void sub_801AD34(u32 param_1)
{ 
  sub_8008C54(param_1);
  sub_80073B8(param_1);
  xxx_call_draw_string(6,0,gUnknown_80DB9A8,param_1,0);
  sub_8012BC4(0x12,0xd,GetNumberOfFilledInventorySlots(),2,7,param_1);
  xxx_call_draw_string(0x16,0xd,gUnknown_80DB9B0,param_1,0);
  sub_8012BC4(0x2b,0xd,INVENTORY_SIZE,2,7,param_1);
  sub_80073E0(param_1);
}

bool8 sub_801ADA0(s32 param_1)
{
  u16 uVar2;
  u32 uVar2_32;

  u16 uVar3;
  u32 uVar3_32;
  s32 sum1;
  s32 sum2;
  struct Item item;
 
  item = gTeamInventory_203B460->teamItems[param_1];
  if (!IsNotMoneyOrUsedTMItem(item.id)) {
      return FALSE;
  }
  else
  {
    if (IsThrowableItem(item.id)) {
      uVar3_32 = sub_801AE24(item.id);
      sum1 = gTeamInventory_203B460->teamStorage[item.id];
      uVar3 = uVar3_32;
      sum1 += uVar3;
      sum1 += (item.quantity);
      if (sum1 > 999)
        return FALSE;
    }
    else {
      uVar2_32 = sub_801AE24(item.id);
      sum2 = gTeamInventory_203B460->teamStorage[item.id];
      uVar2 = uVar2_32;
      sum2 +=  uVar2;
      if (sum2 > 998)
        return FALSE;
    }
  }
  return 1;
}

s32 sub_801AE24(u32 itemID)
{
  struct Item item;
  u16 count;
  s32 invIndex;

  count = 0;
  for (invIndex = 0; invIndex < GetNumberOfFilledInventorySlots(); invIndex++) {
    if (gUnknown_203B224->unk4[invIndex] != 0) {
      item = gTeamInventory_203B460->teamItems[invIndex];
      if (item.id == itemID) {
        if (IsThrowableItem(item.id)) {
            count += item.quantity;
        }
        else {
            count++;
        }
      }
    }
  }
  return count;
}

void sub_801AE84(void)
{
  s32 index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    gUnknown_203B224->unk4[index] = 0;
  }
}

s32 sub_801AEA8(void)
{
  s32 index;
  s32 count;

  count = 0;
  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    if (gUnknown_203B224->unk4[index] != 0) {
      count++;
    }
  }
  return count;
}

s32 sub_801AED0(s32 index)
{
    return gUnknown_203B224->unk4[index];
}

void sub_801AEE4(s32 index, s32 value)
{
    gUnknown_203B224->unk4[index] = value ;
}

void Kecleon_SortItems(void)
{
  struct Item *itemSlotR;
  u32 *itemIDR;
  u32 *base;
  s32 orderL;
  s32 orderR;
  u32 itemIDL;
  struct Item itemSlotL;
  s32 itemR;
  s32 itemL;

  for (itemL = 0; itemL < GetNumberOfFilledInventorySlots() - 1; itemL++) {
    for (itemR = itemL + 1; itemR < GetNumberOfFilledInventorySlots(); itemR++) {
      orderL = GetItemOrder(gTeamInventory_203B460->teamItems[itemL].id);
      orderR = GetItemOrder(gTeamInventory_203B460->teamItems[itemR].id);
      if ((orderL > orderR) || ((orderL == orderR) &&
        (gTeamInventory_203B460->teamItems[itemL].quantity < gTeamInventory_203B460->teamItems[itemR].quantity))) {

        itemSlotL = gTeamInventory_203B460->teamItems[itemL];
        itemSlotR = &gTeamInventory_203B460->teamItems[itemR];
        gTeamInventory_203B460->teamItems[itemL] = *itemSlotR;
        *itemSlotR = itemSlotL;

        base = gUnknown_203B224->unk4;
        itemIDL = gUnknown_203B224->unk4[itemL];
        itemIDR = &base[itemR];
        base[itemL] = *itemIDR;
        *itemIDR = itemIDL;
      }
    }
  }
}

struct unkStruct_203B224 * sub_801AF98(void)
{
    return gUnknown_203B224;
}
