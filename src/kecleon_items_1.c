#include "global.h"
#include "file_system.h"
#include "memory.h"
#include "pokemon.h"
#include "input.h"
#include "item.h"
#include "kecleon_items.h"
#include "team_inventory.h"

extern struct unkStruct_203B210 *gUnknown_203B210;
extern u8 gUnknown_80DB8E4[];
extern u8 gUnknown_80DB8EC[];
extern u8 gUnknown_80DB92C[];
extern u8 gUnknown_80DB934[];

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
extern void ExpandPlaceholdersBuffer(u8 *, u8 *, ...);
extern void  xxx_call_draw_string(s32 x, s32, u8 *, u32, u32);
extern void sub_801AE84(void);
extern void sub_8012D08(void *, u32);
extern void sub_801A998(void);
extern void sub_801A9E0(void);
extern void sub_801AEF8(void);
extern bool8 sub_801ADA0(u32);
extern u32 sub_801AEA8(void);


extern struct unkStruct_203B224 *gUnknown_203B224;

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
extern struct unkStruct_203B214 *gUnknown_203B21C;

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
extern struct UnkTextStruct2 gUnknown_80DB8FC;
extern struct UnkTextStruct2 gUnknown_80DB944;
extern const struct UnkTextStruct2 gUnknown_80DB914;
extern u16 gUnknown_203B218;
extern u16 gUnknown_203B220;
extern void sub_801A430(void);
extern void sub_801A4A4(void);
extern void sub_8013984(u8 *);
extern void sub_801A064(void);
extern void sub_801A0D8(void);
extern void AddMenuCursorSprite(void *);
extern s32 xxx_count_inv_unk230();
extern u8 sub_801A37C(void);
extern u16 gUnknown_203B228;
extern u16 gUnknown_203B22A;
extern struct UnkTextStruct2 gUnknown_80DB95C;

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
  struct HeldItem *heldItem;
  s32 iVar2;
  s32 y;
  s32 iVar4;
  u8 auStack204 [80];
  struct unkStruct_8090F58 local_7c;
  u8 auStack112 [80];
  struct ItemSlot_Alt slot;
  u8 temp_calc;

  // Needed for the shifts..
  u32 index_shift;
  u32 numItems_shift;
  
  sub_8008C54(gUnknown_203B214->unk34);
  sub_80073B8(gUnknown_203B214->unk34);
  xxx_call_draw_string(gUnknown_203B214->unk1E * 8 + 10,0,gUnknown_80DB8E4,
                        gUnknown_203B214->unk34,0);

  for(iVar4 = 0; iVar4 < gUnknown_203B214->unk1A; iVar4++)
    {
      temp_calc = (gUnknown_203B214->unk1E * gUnknown_203B214->unk1C) + iVar4;
      heldItem = xxx_get_inv_unk230_at_809185C(temp_calc);

      index_shift = heldItem->itemIndex << 16;
      slot.temp.full_bits = (slot.temp.full_bits & 0xff00ffff) | index_shift;

      numItems_shift = heldItem->numItems << 8;
      slot.temp.full_bits = (slot.temp.full_bits & 0xffff00ff) | numItems_shift;

      slot.temp.full_bits = (slot.temp.full_bits & 0xffffff00) | (ITEM_FLAG_EXISTS | ITEM_FLAG_FOR_SALE);

      local_7c.unk0 = 1;
      local_7c.unk4 = 0;
      local_7c.unk6 = 0x58;
      local_7c.unk8 = 1;
      sub_8090E14(auStack204,(struct ItemSlot *)&slot,&local_7c);
      iVar2 = GetStackBuyPrice((struct ItemSlot *)&slot);
      if (iVar2 <= gTeamInventory_203B460->teamMoney) {
        y = sub_8013800(gUnknown_203B214,iVar4);
        xxx_call_draw_string(8,y,auStack204,gUnknown_203B214->unk34,0);
      }
      else {
        ExpandPlaceholdersBuffer(auStack112,gUnknown_80DB8EC,auStack204);
        y = sub_8013800(gUnknown_203B214,iVar4);
        xxx_call_draw_string(8,y,auStack112,gUnknown_203B214->unk34,0);
      }
   }
  sub_80073E0(gUnknown_203B214->unk34);
}

u32 sub_801A20C(u32 r0)
{
    if(xxx_count_non_empty_inv_unk250_8091A48() == 0)
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
        sub_8013818(gUnknown_203B21C, xxx_count_non_empty_inv_unk250_8091A48(), 0xA, r0);
        gUnknown_203B21C->temp.unk18 = gUnknown_203B220;
        sub_8013984((u8 *)gUnknown_203B21C);
        sub_801A430();
        sub_801A4A4();
        return 1;
    }
}

u32 sub_801A2A8(u8 r0)
{
    struct ItemSlot_Alt slot;
    struct HeldItem *return_var;
    u32 r2;
    u32 r3;

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
                return_var = xxx_get_unk250_at_8091A90(sub_801A37C());

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
    return (gUnknown_203B21C->unk1E * gUnknown_203B21C->unk1C) + gUnknown_203B21C->temp.unk18_u8;
}

void sub_801A398(u32 r0)
{
    u8 r0_u8;

    r0_u8 = r0;

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B21C->unk3C, 0, 0);
    gUnknown_203B21C->unk22 = xxx_count_non_empty_inv_unk250_8091A48();
    sub_8013984((u8 *)gUnknown_203B21C);
    sub_801A430();
    sub_801A4A4();
    if(r0_u8)
        AddMenuCursorSprite(gUnknown_203B21C);
}

void sub_801A3DC(void)
{
    if(gUnknown_203B21C != NULL)
    {
        gUnknown_203B220 = gUnknown_203B21C->temp.unk18;
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
  struct HeldItem *heldItem;
  s32 iVar2;
  s32 y;
  s32 iVar4;
  u8 auStack204 [80];
  struct unkStruct_8090F58 local_7c;
  u8 auStack112 [80];
  struct ItemSlot_Alt slot;
  u8 temp_calc;

  // Needed for the shifts..
  u32 index_shift;
  u32 numItems_shift;
  
  sub_8008C54(gUnknown_203B21C->unk34);
  sub_80073B8(gUnknown_203B21C->unk34);
  xxx_call_draw_string(gUnknown_203B21C->unk1E * 8 + 10,0,gUnknown_80DB92C,
                        gUnknown_203B21C->unk34,0);

  for(iVar4 = 0; iVar4 < gUnknown_203B21C->unk1A; iVar4++)
    {
      temp_calc = (gUnknown_203B21C->unk1E * gUnknown_203B21C->unk1C) + iVar4;
      heldItem = xxx_get_unk250_at_8091A90(temp_calc);

      index_shift = heldItem->itemIndex << 16;
      slot.temp.full_bits = (slot.temp.full_bits & 0xff00ffff) | index_shift;

      numItems_shift = heldItem->numItems << 8;
      slot.temp.full_bits = (slot.temp.full_bits & 0xffff00ff) | numItems_shift;

      slot.temp.full_bits = (slot.temp.full_bits & 0xffffff00) | (ITEM_FLAG_EXISTS | ITEM_FLAG_FOR_SALE);

      local_7c.unk0 = 1;
      local_7c.unk4 = 0;
      local_7c.unk6 = 0x58;
      local_7c.unk8 = 1;
      sub_8090E14(auStack204,(struct ItemSlot *)&slot,&local_7c);
      iVar2 = GetStackBuyPrice((struct ItemSlot *)&slot);
      if (iVar2 <= gTeamInventory_203B460->teamMoney) {
        y = sub_8013800(gUnknown_203B21C,iVar4);
        xxx_call_draw_string(8,y,auStack204,gUnknown_203B21C->unk34,0);
      }
      else {
        ExpandPlaceholdersBuffer(auStack112,gUnknown_80DB934,auStack204);
        y = sub_8013800(gUnknown_203B21C,iVar4);
        xxx_call_draw_string(8,y,auStack112,gUnknown_203B21C->unk34,0);
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
  s32 iVar5;
  struct ItemSlot local_10;
  
  if (param_1 == '\0') {
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
                if ((sub_801AEA8() != 0) || (sub_801ADA0(sub_801A8AC()) != '\0'))
                    PlayMenuSoundEffect(0);
                else
                    PlayMenuSoundEffect(2);
                break;
            case 4:
                local_10 = gTeamInventory_203B460->teamItems[sub_801A8AC()];
                if (CanSellItem(local_10.itemIndex) && (GetStackSellPrice(&local_10) + gTeamInventory_203B460->teamMoney < 100000))
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
        iVar5 = sub_801A8AC();
        if ((gUnknown_203B224->unk4[iVar5] != 0) || (sub_801ADA0(iVar5) != '\0')) {
            PlayMenuSoundEffect(6);
            gUnknown_203B224->unk4[iVar5] = gUnknown_203B224->unk4[iVar5] ^ 1;
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
            sub_801AEF8();
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

void sub_801A8D0(u32 r0)
{
    u8 r0_u8;

    r0_u8 = r0;

    sub_8099690(1);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, 0, 0);
    FillInventoryGaps();
    gUnknown_203B224->unk76 = GetNumberOfFilledInventorySlots();
    sub_8013984((u8 *)&gUnknown_203B224->unk54);
    sub_801A998();
    sub_801A9E0();
    if(r0_u8)
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
