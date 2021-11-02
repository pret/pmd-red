#include "global.h"
#include "file_system.h"
#include "memory.h"
#include "pokemon.h"
#include "input.h"
#include "item.h"
#include "kecleon_items.h"
#include "team_inventory.h"

extern struct unkStruct_203B210 *gUnknown_203B210;

extern s32 sub_80144A4(s32 *);
void UpdateKecleonStoreState(u32);
extern u32 sub_801B410(void);
extern void sub_801B450(void);

extern void sub_8099690(u32);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern u32 sub_8019EDC(u8);
extern void sub_801A2A8(u32);
extern s32 sub_801A8AC(void);
extern u32 sub_801A6E8(u32);
extern void sub_801A928(void);
extern void DrawTeamMoneyBox(u32);

struct unkStruct_203B214
{;
    // size: 0xA0
    u8 fill0[0x18];
    // NOTE: has to be packed here so it doesn't take 4 bytes..
    union __attribute__ ((__packed__)) temp2
    {
        u16 unk18;
        u8 unk18_u8;
    } temp;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    u16 unk22;
    u8 fill24[0x34 - 0x24];
    u32 unk34;
    struct UnkTextStruct2 *unk38;
    struct UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

extern struct unkStruct_203B214 *gUnknown_203B214;

struct ItemSlot_Alt
{
    union temp {
        struct ItemSlot norm;
        u32 full_bits;
    } temp;
};

extern void sub_8013818(void *, u32, u32, u32);

extern u8 sub_8019FB0(void);
extern u8 sub_80138B8(void *, u32);

extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(void *);
extern void sub_8013660(void *);

extern struct UnkTextStruct2 gUnknown_80DB8CC;
extern struct UnkTextStruct2 gUnknown_80DB8B4;
extern u16 gUnknown_203B218;
extern void sub_8013984(u8 *);
extern void sub_801A064(void);
extern void sub_801A0D8(void);
extern void AddMenuCursorSprite(void *);
extern s32 xxx_count_inv_unk230();

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
  if (gUnknown_203B210->unk4) {
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
        if (gTeamInventory_203B460->teamMoney == 0) {
            UpdateKecleonStoreState(0x6);
        }
        else if (gUnknown_203B210->itemSellPrice > gTeamInventory_203B460->teamMoney) {
            UpdateKecleonStoreState(0xC);
        }
        else {
            UpdateKecleonStoreState(0x16);
        }
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
        if (!CanSellItem(gUnknown_203B210->unk1C.itemIndex)) {
            UpdateKecleonStoreState(0xd);
        }
        else if (gUnknown_203B210->itemSellPrice + gTeamInventory_203B460->teamMoney > 99999) {
            UpdateKecleonStoreState(0xe);
        }
        else {
            UpdateKecleonStoreState(0x1e);
        }
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
        UpdateKecleonStoreState(gUnknown_203B210->unkC);
    }
}

u32 sub_8019D8C(void)
{
    if(gUnknown_203B210->unk4)
        return xxx_count_inv_unk230();
    else
        return xxx_count_non_empty_inv_unk250_8091A48();
}

void sub_8019DAC(void)
{
  s32 iVar3;
  struct ItemSlot *pbVar4;
  s32 iVar5;

  gUnknown_203B210->unk14 = 0;
  gUnknown_203B210->unk18 = 0;
  for(iVar5 = 0; iVar5 < INVENTORY_SIZE; iVar5++){
    pbVar4 = &gTeamInventory_203B460->teamItems[iVar5];
    if (((pbVar4->itemFlags & ITEM_FLAG_EXISTS) != 0) && (CanSellItem(pbVar4->itemIndex))) {
      iVar3 = GetStackSellPrice(pbVar4);
      gUnknown_203B210->unk18 += iVar3;
      gUnknown_203B210->unk14++;
    }
  }
}

void sub_8019E04(s32 param_1)
{

  if (gUnknown_203B210->unk4) {
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
    if(xxx_count_inv_unk230() == 0)
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
        sub_8013818(gUnknown_203B214, xxx_count_inv_unk230(), 0xA, r0);
        gUnknown_203B214->temp.unk18 = gUnknown_203B218;
        sub_8013984((u8 *)gUnknown_203B214);
        sub_801A064();
        sub_801A0D8();
        return 1;
    }
}

u32 sub_8019EDC(u8 r0)
{
    struct ItemSlot_Alt slot;
    struct HeldItem *return_var;
    u32 r2;
    u32 r3;

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
                return_var = xxx_get_inv_unk230_at_809185C(sub_8019FB0());

                // NOTE: needs seperate vars to match
                r2 = return_var->itemIndex << 16;
                slot.temp.full_bits =  (slot.temp.full_bits & 0xff00ffff) | r2;
                r3 = return_var->numItems << 8;
                slot.temp.full_bits =  (slot.temp.full_bits & 0xffff00ff) | r3;

                if(GetStackBuyPrice((struct ItemSlot *)&slot) > gTeamInventory_203B460->teamMoney)
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
    return (gUnknown_203B214->unk1E * gUnknown_203B214->unk1C) + gUnknown_203B214->temp.unk18_u8;
}

void sub_8019FCC(u32 r0)
{
    u8 r0_u8;

    r0_u8 = r0;

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, 0, 0);
    gUnknown_203B214->unk22 = xxx_count_inv_unk230();
    sub_8013984((u8 *)gUnknown_203B214);
    sub_801A064();
    sub_801A0D8();
    if(r0_u8)
        AddMenuCursorSprite(gUnknown_203B214);
}

void sub_801A010(void)
{
    if(gUnknown_203B214 != NULL)
    {
        gUnknown_203B218 = gUnknown_203B214->temp.unk18;
        gUnknown_203B214->unk3C[gUnknown_203B214->unk34] = gUnknown_80DB8B4;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B214->unk3C, 1, 1);
        MemoryFree(gUnknown_203B214);
        gUnknown_203B214 = NULL;
    }
}
