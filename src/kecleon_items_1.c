#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "item.h"
#include "kecleon_items.h"
#include "gUnknown_203B460.h"

extern struct unkStruct_203B210 *gUnknown_203B210;
extern struct unkStruct_203B460 *gUnknown_203B460;

extern u32 sub_8090CCC(struct ItemSlot *);
extern bool8 sub_80914E4(u8);
extern u32 sub_8091814(void);
extern u32 sub_8091A48(void);
extern s32 sub_80144A4(s32 *);
void UpdateKecleonStoreState(u32);
extern u32 sub_801B410(void);
extern void sub_801B450(void);

extern void sub_8099690(u32);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern void sub_8019EDC(u32);
extern void sub_801A2A8(u32);
extern s32 sub_801A8AC(void);
extern u32 sub_801A6E8(u32);
extern void sub_801A928(void);
extern void sub_8016C40(u32);

void sub_8019B08(void)
{
  switch(sub_801A6E8(1)) 
  {
    case 0:
        break;
    case 3:
        gUnknown_203B210->unk24 = sub_801A8AC();
        gUnknown_203B210->unk1C = gUnknown_203B460->teamItems[gUnknown_203B210->unk24];
        gUnknown_203B210->itemSellPrice = sub_8090CCC(&gUnknown_203B210->unk1C);
        UpdateKecleonStoreState(0x1c);
        break;
    case 4:
        gUnknown_203B210->unk24 = sub_801A8AC();
        gUnknown_203B210->unk1C = gUnknown_203B460->teamItems[gUnknown_203B210->unk24];
        gUnknown_203B210->itemSellPrice = sub_8090CCC(&gUnknown_203B210->unk1C);
        sub_8099690(0);
        UpdateKecleonStoreState(0x1d);
        break;
    case 2:
        sub_801A928();
        UpdateKecleonStoreState(1);
        break;
    case 1:
    default:
        sub_8016C40(1);
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
        if (gUnknown_203B460->teamMoney == 0) {
            UpdateKecleonStoreState(0x6);
        }
        else if (gUnknown_203B210->itemSellPrice > gUnknown_203B460->teamMoney) {
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
        if (!sub_80914E4(gUnknown_203B210->unk1C.itemIndex)) {
            UpdateKecleonStoreState(0xd);
        }
        else if (gUnknown_203B210->itemSellPrice + gUnknown_203B460->teamMoney > 99999) {
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
    {
        return sub_8091814();
    }
    else
    {
        return sub_8091A48();
    }
}

void sub_8019DAC(void)
{
  s32 iVar3;
  struct ItemSlot *pbVar4;
  s32 iVar5;
  
  gUnknown_203B210->unk14 = 0;
  gUnknown_203B210->unk18 = 0;
  for(iVar5 = 0; iVar5 < 0x14; iVar5++){
    pbVar4 = &gUnknown_203B460->teamItems[iVar5];
    if (((pbVar4->unk0 & 1) != 0) && (sub_80914E4(pbVar4->itemIndex))) {
      iVar3 = sub_8090CCC(pbVar4);
      gUnknown_203B210->unk18 += iVar3;
      gUnknown_203B210->unk14++;
    }
  }
}

void sub_8019E04(int param_1)
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

