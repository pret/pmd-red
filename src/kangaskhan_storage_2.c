#include "global.h"
#include "input.h"
#include "memory.h"
#include "text.h"
#include "item.h"
#include "team_inventory.h"
#include "input.h"
#include "kangaskhan_storage.h"

extern struct unkStruct_203B208 *gUnknown_203B208;
extern struct TeamInventory *gTeamInventory_203B460;

struct unkStruct_203B20C
{
    u32 state;
    u8 unk4[4];
    struct ItemSlot unk8;
    u8 fillC[0x14 - 0xC];
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u8 fill24[0x60 - 0x24];
    u16 unk60[8];
    u32 unk70;
    u8 fill74[0xC0 - 0x74];
    u32 unkC0;
    u32 unkC4;
    u32 unkC8;
    u32 unkCC;
    u32 unkD0;
    u32 unkD4;
    struct UnkTextStruct2 *unkD8;
    u32 unkDC;
    u32 unkE0;
    u8 fillE4[0xF0 - 0xE4];
    struct UnkTextStruct2 unkF0[4];
};
extern struct unkStruct_203B20C *gUnknown_203B20C;

extern void sub_8017F10(u32);
extern void sub_8018588(void);
extern void sub_8018620(void);
extern void sub_8018904(void);
extern void sub_8018AC8(void);
extern void sub_80186F8(void);
extern void sub_8018854(void);
extern void sub_80189C8(void);
extern void sub_8018AE4(void);


extern void sub_8017F28();
extern void sub_8018100();
extern void UpdateKangaskhanStorageState(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_801B450();
extern u32 sub_801B410(void);

extern u8 sub_8012FD8(u32 *r0);
extern void sub_8013114(u32 *, s32 *);
extern void sub_801CBB8();

extern bool8 IsNotMoneyOrUsedTMItem(u8);
extern bool8 sub_801ADA0(u32);
extern void sub_8099690(u32);
extern u32 sub_8013BBC(u32 *);
extern void sub_8017598(void);

extern u32 sub_801CA08(u32);
extern u32 sub_801CFB8(void);
extern u8 sub_801CB24();
extern void sub_801AD34(u32);
extern u32 sub_801A6E8(u32);
extern u32 sub_801AEA8(void);
extern u32 sub_801A8AC(void);
extern void sub_801A928(void);
extern void sub_8012CAC(struct UnkTextStruct2 *, u32 *);
extern void sub_80182E4(void);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);
extern void sub_8012EA4(u32 *, u32);
extern void xxx_call_draw_string(u32 x, u32 y, u8 *, u32, u32);


extern void sub_801A9E0();
extern void sub_801841C();
extern void sub_801CCD8();
extern void sub_80184D4();
extern void sub_8018280();
extern void sub_8013AA0(u32 *);
extern void sub_801B3C0(struct ItemSlot *);
extern void sub_801A5D8(u32, u32, u32, u32);
extern void sub_801C8C4(u32, u32, u32, u32);
extern void sub_8012D60(u32 *, u32 *, u32, u16 *, u32, u32);
extern void sub_801CB5C(u32);
extern void sub_801A8D0(u32);

extern struct UnkTextStruct2 gUnknown_80DB7B8;
extern struct UnkTextStruct2 gUnknown_80DB7E8;
extern struct UnkTextStruct2 gUnknown_80DB7D0;
extern struct UnkTextStruct2 gUnknown_80DB800;
extern struct UnkTextStruct2 gUnknown_80DB818;
extern u8 gUnknown_80DB830[];

void sub_8017AF8(void)
{
    switch(sub_801A6E8(1))
    {
        case 3:
            if(sub_801AEA8() != 0)
            {
                sub_8099690(0);
                UpdateKangaskhanStorageState(0x12);
            }
            else
            {
                gUnknown_203B208->unk10 = sub_801A8AC();
                gUnknown_203B208->unkC = gTeamInventory_203B460->teamItems[gUnknown_203B208->unk10];
                UpdateKangaskhanStorageState(0xF);
            }
            break;
        case 4:
            gUnknown_203B208->unk10 = sub_801A8AC();
            gUnknown_203B208->unkC = gTeamInventory_203B460->teamItems[gUnknown_203B208->unk10];
            UpdateKangaskhanStorageState(0x10);
            break;
        case 2:
            sub_801A928();
            UpdateKangaskhanStorageState(1);
            break;
    }
}

void sub_8017B88(void)
{
    switch(sub_801CA08(1))
    {
        case 3:
            if(sub_801CFB8() != 0){
                UpdateKangaskhanStorageState(0x1C);
            }
            else
            {
                gUnknown_203B208->itemIndex = sub_801CB24();
                xxx_init_itemslot_8090A8C(&gUnknown_203B208->unkC, gUnknown_203B208->itemIndex, 0);
                gUnknown_203B208->unkC.numItems = 1;
                UpdateKangaskhanStorageState(0x19);
            }
            break;
        case 4:
            gUnknown_203B208->itemIndex = sub_801CB24();
            xxx_init_itemslot_8090A8C(&gUnknown_203B208->unkC, gUnknown_203B208->itemIndex, 0);
            gUnknown_203B208->unkC.numItems = 1;
            UpdateKangaskhanStorageState(0x1A);
            break;
        case 2:
            sub_801CBB8();
            UpdateKangaskhanStorageState(1);
            break;
        case 1:
            sub_801AD34(0);
            break;
    }
}

void sub_8017C28(void)
{
    sub_801CA08(0);
    sub_8012FD8(&gUnknown_203B208->unk58);
    switch(sub_8013BBC(&gUnknown_203B208->unkA8))
    {
        case 1:
            sub_8017598();
            break;
        case 3:
            gUnknown_203B208->unkC.numItems = gUnknown_203B208->unkA8;
            UpdateKangaskhanStorageState(0x1B);
            break;
        case 2:
            UpdateKangaskhanStorageState(0x17);
            break;
        case 0:
        default:
            break;
    }
}

void sub_8017C7C(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801A6E8(0);
    if (sub_8012FD8(&gUnknown_203B208->unk58) == 0) {
        sub_8013114(&gUnknown_203B208->unk58, &menuAction);
        if(menuAction != 1) gUnknown_203B208->unk1C = menuAction;
    }

    switch(menuAction)
    {
      case 2:
        sub_8099690(0);
        if(!IsNotMoneyOrUsedTMItem(gUnknown_203B208->unkC.itemIndex))
            UpdateKangaskhanStorageState(9);
        else
            if(!sub_801ADA0(gUnknown_203B208->unk10))
                UpdateKangaskhanStorageState(0xA);
            else
                UpdateKangaskhanStorageState(0x11);
        break;
      case 6:
        sub_8099690(0);
        UpdateKangaskhanStorageState(0x10);
        break;
      case 1:
        UpdateKangaskhanStorageState(0xE);
        break;
    }
}

void sub_8017D24(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801CA08(0);
    if (sub_8012FD8(&gUnknown_203B208->unk58) == 0) {
        sub_8013114(&gUnknown_203B208->unk58, &menuAction);
        if(menuAction != 1) gUnknown_203B208->unk20 = menuAction;
    }

    switch(menuAction)
    {
      case 3:
        if (GetNumberOfFilledInventorySlots() > 0x13)
        {
            sub_801CBB8();
            UpdateKangaskhanStorageState(6);
        }
        else
        {
            if(IsThrowableItem(gUnknown_203B208->unkC.itemIndex))
                UpdateKangaskhanStorageState(0x18);
            else
                UpdateKangaskhanStorageState(0x1B);
        }
        break;
      case 6:
        UpdateKangaskhanStorageState(0x1A);
        break;
      case 1:
        UpdateKangaskhanStorageState(0x17);
        break;
    }
}

void sub_8017DC0(void)
{
    switch(sub_801B410())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(0xE);
            break;
    }
}

void sub_8017DDC(void)
{
    switch(sub_801B410())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(0x17);
            break;
    }
}

void sub_8017DF8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateKangaskhanStorageState(gUnknown_203B208->unk8);
    }
}

u32 sub_8017E1C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    gUnknown_203B20C = MemoryAlloc(sizeof(struct unkStruct_203B20C), 8);
    gUnknown_203B20C->unk14 = 0;
    gUnknown_203B20C->unk18 = 0;
    gUnknown_203B20C->unk1C = 0;
    sub_8017F10(0);
    return 1;
}

u32 sub_8017E54(void)
{
  switch(gUnknown_203B20C->state)
  {
      case 0:
        sub_8017F10(1);
        break;
      case 1:
        sub_8018588();
        break;
      case 4:
      case 5:
        sub_8018620();
        break;
      case 6:
        sub_8018904();
        break;
      case 7:
        sub_8018AC8();
        break;
      case 10:
      case 11:
        sub_80186F8();
        break;
      case 12:
        sub_8018854();
        break;
      case 13:
        sub_80189C8();
        break;
      case 14:
        sub_8018AE4();
        break;
      case 3:
        return 3;
  }
  return 0;
}

void sub_8017EF4(void)
{
    if(gUnknown_203B20C != NULL)
    {
        MemoryFree(gUnknown_203B20C);
        gUnknown_203B20C = NULL;
    }
}

void sub_8017F10(u32 newState)
{
    gUnknown_203B20C->state = newState;
    sub_8017F28();
    sub_8018100();
}

void sub_8017F28(void)
{
    s32 iVar2;

    sub_8006518(gUnknown_203B20C->unkF0);

    switch(gUnknown_203B20C->state)
    {
        case 1:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            sub_80182E4();
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7D0;
            sub_8012CAC(&gUnknown_203B20C->unkF0[2], &gUnknown_203B20C->unk20);
            break;
        case 4:
        case 5:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            break;
        case 10:
        case 11:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB800;
            break;
        case 12:
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB818;
            break;
        case 6:
        case 13:
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7E8;
            break;
        default:
        case 0:
            for(iVar2 = 0; iVar2 < 4; iVar2++)
            {
                gUnknown_203B20C->unkF0[iVar2] = gUnknown_80DB7B8;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B20C->unkF0, 1, 1);
}

void sub_8018100(void)
{

    switch(gUnknown_203B20C->state)
    {
        case 1:
            sub_8012D60(&gUnknown_203B20C->unk70, &gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->unk14, 2);
            break;
        case 4:
            sub_801A5D8(3, 3, 0, 0xA);
            break;
        case 5:
            sub_801A8D0(1);
            break;
        case 6:
            sub_801A9E0();
            sub_801841C();
            sub_8012D60(&gUnknown_203B20C->unk70, &gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->unk18, 2);
            break;
        case 7:
            sub_801B3C0(&gUnknown_203B20C->unk8);
            break;
        case 10:
            sub_801C8C4(1, 3, 0, 0xA);
            sub_801AD34(0);
            break;
        case 11:
            sub_801CB5C(1);
            sub_801AD34(0);
            break;
        case 12:
            gUnknown_203B20C->unkD0 = 2;
            gUnknown_203B20C->unkC8 = 1;
            if(gTeamInventory_203B460->teamStorage[gUnknown_203B20C->unk8.itemIndex] > 99)
                gUnknown_203B20C->unkCC = 99;
            else
                gUnknown_203B20C->unkCC = gTeamInventory_203B460->teamStorage[gUnknown_203B20C->unk8.itemIndex];
            gUnknown_203B20C->unkC4 = gUnknown_203B20C->unkCC;
            gUnknown_203B20C->unkD4 = 1;
            gUnknown_203B20C->unkD8 = &gUnknown_203B20C->unkF0[1];
            gUnknown_203B20C->unkDC = 0x28;
            gUnknown_203B20C->unkE0 = 0x12;
            sub_8013AA0(&gUnknown_203B20C->unkC0);
            sub_8018280();
            break;
        case 13:
            sub_801CCD8();
            sub_801AD34(0);
            sub_80184D4();
            sub_8012D60(&gUnknown_203B20C->unk70, &gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->unk1C, 2);
            break;
        case 14:
            sub_801B3C0(&gUnknown_203B20C->unk8);
            break;
        case 0:
        default:
            break;
    }
}

void sub_8018280(void)
{
    sub_8008C54(gUnknown_203B20C->unkD4);
    sub_80073B8(gUnknown_203B20C->unkD4);
    xxx_call_draw_string(4, 0, gUnknown_80DB830, gUnknown_203B20C->unkD4, 0); // Number?
    sub_8013C68(&gUnknown_203B20C->unkC0);
    sub_80073E0(gUnknown_203B20C->unkD4);
    sub_801CCD8();
    sub_801AD34(0);
    sub_8012EA4(&gUnknown_203B20C->unk70,0);
}
