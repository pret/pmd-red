#include "global.h"
#include "input.h"
#include "item.h"
#include "team_inventory.h"
#include "memory.h"
#include "menu.h"
#include "text.h"

struct unkStruct_203B3F0
{
    // size: 0x138
    u32 state;
    u8 itemIndex;
    u8 fill5[0x8 - 5];
    u32 unk8;
    struct MenuItem menuItems[8];
    u32 unk4C;
    u8 fill50[0x9C - 0x50];
    u32 unk9C;
    u32 unkA0;
    u32 unkA4;
    u32 unkA8;
    u32 unkAC;
    u32 unkB0;
    struct UnkTextStruct2 *unkB4;
    u32 unkB8;
    u32 unkBC;
    u8 fill4[0xD8 - 0xC0];
    struct UnkTextStruct2 unkD8[4];
};

extern struct unkStruct_203B3F0 *gUnknown_203B3F0;

struct unkStruct_203B3F4
{
    // size: 0xFC
    u32 state;
    u8 unk4;
    u8 fill5[0x8 - 5];
    u32 unk8;
    struct MenuItem menuItems[8];
    u32 unk4C;
    u8 fill50[0x9C - 0x50];
    struct UnkTextStruct2 unk9C[4];
};

extern struct unkStruct_203B3F4 *gUnknown_203B3F4;


extern struct TeamInventory *gTeamInventory_203B460;
extern void sub_801B3C0(struct ItemSlot *);
extern void sub_8013AA0(u32 *);

extern struct UnkTextStruct2 gUnknown_80E7E34;
extern struct UnkTextStruct2 gUnknown_80E7E4C;
extern struct UnkTextStruct2 gUnknown_80E7E64;
extern const char gDebug_NumberText;
extern struct UnkTextStruct2 gUnknown_80E7E8C;
extern struct UnkTextStruct2 gUnknown_80E7EA4;

extern const char *gUnknown_80D4970[];


extern void sub_801C8C4(u32, u32, u32, u32);
extern void sub_801CB5C(u32);
extern void sub_801CCD8();
extern void sub_8012D60(u32 *, struct MenuItem *, u32, u32, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8012EA4(u32 *, u32);
extern void sub_80073E0(u32);
extern void sub_8013C68(u32 *);
extern void xxx_call_draw_string(s32, u32, const char *, u32, u32);
extern bool8 IsNotMoneyOrUsedTMItem(u8);
extern u32 sub_801CA08(u32);
extern u8 sub_801CB24();
extern void sub_801CBB8();
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, s32 *);
extern u32 sub_8013BBC(u32 *);
extern u32 sub_801B410();
extern void sub_801B450();
extern void sub_80211AC(u32, u32);
extern void sub_8021354(u32);
extern void sub_8021494();
extern void sub_803AA34();
extern void sub_8021774(u8,u32, u32);


extern void sub_803AAC4();
extern void sub_803AB34();
extern void sub_803ABAC();

void sub_803A924(u32);
void sub_803A93C();
void sub_803A9AC();

void sub_803A504(u32);
void sub_803A51C();
void sub_803A5A0();
void sub_803A690();
void sub_803A6F0();
void sub_803A740();
void sub_803A7B0();
void sub_803A810();
void sub_803A86C();


u32 sub_803A45C(void)
{
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B3F0 = MemoryAlloc(sizeof(struct unkStruct_203B3F0), 8);
  sub_803A504(0);
  return 1;
}

u32 sub_803A48C(void)
{
  switch(gUnknown_203B3F0->state) {
    case 0:
    case 1:
        sub_803A740();
        break;
    case 2:
        sub_803A7B0();
        break;
    case 3:
        sub_803A810();
        break;
    case 4:
        sub_803A86C();
        break;
    case 5:
        return 3;
  }
  return 0;
}

void sub_803A4E8(void)
{
    if(gUnknown_203B3F0 != NULL)
    {
        MemoryFree(gUnknown_203B3F0);
        gUnknown_203B3F0 = NULL;
    }
}

void sub_803A504(u32 newState)
{
    gUnknown_203B3F0->state = newState;
    sub_803A51C();
    sub_803A5A0();
}

void sub_803A51C(void)
{
    s32 iVar4;

    sub_8006518(gUnknown_203B3F0->unkD8);
    switch(gUnknown_203B3F0->state)
    {
        case 3:
            gUnknown_203B3F0->unkD8[1] = gUnknown_80E7E64;
            break;
        case 2:
            gUnknown_203B3F0->unkD8[2] = gUnknown_80E7E4C;
            break;
        default:
            for(iVar4 = 0; iVar4 < 4; iVar4++)
            {
                gUnknown_203B3F0->unkD8[iVar4] = gUnknown_80E7E34;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B3F0->unkD8, 1, 1);
}

void sub_803A5A0(void)
{
  struct ItemSlot auStack8;
  
  switch(gUnknown_203B3F0->state) {
    case 0:
        sub_801C8C4(2,3,0,10);
        break;
    case 1:
        sub_801CB5C(1);
        break;
    case 2:
        sub_801CCD8();
        sub_803A6F0();
        sub_8012D60(&gUnknown_203B3F0->unk4C, gUnknown_203B3F0->menuItems, 0, 0, gUnknown_203B3F0->unk8, 2);
        break;
    case 3:
        gUnknown_203B3F0->unkAC = 3;
        gUnknown_203B3F0->unkA4 = 0;
        gUnknown_203B3F0->unkA8 = 0x3e7;
        gUnknown_203B3F0->unkA0 = gTeamInventory_203B460->teamStorage[gUnknown_203B3F0->itemIndex];
        gUnknown_203B3F0->unkB0 = 1;
        gUnknown_203B3F0->unkB4 = &gUnknown_203B3F0->unkD8[1];
        gUnknown_203B3F0->unkB8 = 0x2C;
        gUnknown_203B3F0->unkBC = 0x12;
        sub_8013AA0(&gUnknown_203B3F0->unk9C);
        sub_803A690();
        break;
    case 4:
        xxx_init_itemslot_8090A8C(&auStack8,gUnknown_203B3F0->itemIndex,0);
        sub_801B3C0(&auStack8);
        break;
    case 5:
        break;
  }
}

void sub_803A690(void)
{
  sub_8008C54(gUnknown_203B3F0->unkB0);
  sub_80073B8(gUnknown_203B3F0->unkB0);
  xxx_call_draw_string(4, 0, &gDebug_NumberText, gUnknown_203B3F0->unkB0, 0);
  sub_8013C68(&gUnknown_203B3F0->unk9C);
  sub_80073E0(gUnknown_203B3F0->unkB0);
  sub_801CCD8();
  sub_8012EA4(&gUnknown_203B3F0->unk4C,0);
}

void sub_803A6F0(void)
{
  s32 temp1;
  struct unkStruct_203B3F0 *preload;

  gUnknown_203B3F0->menuItems[0].text = &gDebug_NumberText;
  gUnknown_203B3F0->menuItems[0].menuAction = 2;
  gUnknown_203B3F0->unk8 = 2;
  if (!IsNotMoneyOrUsedTMItem(gUnknown_203B3F0->itemIndex)) {
    gUnknown_203B3F0->menuItems[0].menuAction = -1;
    gUnknown_203B3F0->unk8 = 3;
  }
  preload = gUnknown_203B3F0;
  // this var gets loaded in between the sets... very dumb
  temp1 = 1;
  preload->menuItems[1].text = *gUnknown_80D4970;
  preload->menuItems[1].menuAction = 3;
  preload->menuItems[2].text = NULL;
  preload->menuItems[2].menuAction = temp1;
}

void sub_803A740(void)
{
  switch(sub_801CA08(1)) {
    case 0:
    case 1:
        break;
    case 3:
        gUnknown_203B3F0->itemIndex = sub_801CB24();
        sub_803A504(2);
        break;
    case 4:
        gUnknown_203B3F0->itemIndex = sub_801CB24();
        sub_803A504(4);
        break;
    case 2:
        sub_801CBB8();
        sub_803A504(5);
        break;
  }
}

void sub_803A7B0(void)
{
  s32 local_c;

  local_c = 0;
  sub_801CA08(0);
  if (sub_8012FD8(&gUnknown_203B3F0->unk4C) == '\0') {
    sub_8013114(&gUnknown_203B3F0->unk4C,&local_c);
  }
  switch(local_c)
  {
      case 2:
        sub_803A504(3);
        break;
      case 3:
        sub_803A504(4);
        break;
      case 1:
        sub_803A504(1);
        break;

  }
}

void sub_803A810(void)
{
  sub_801CA08(0);
  sub_8012FD8(&gUnknown_203B3F0->unk4C);
  switch(sub_8013BBC(&gUnknown_203B3F0->unk9C))
  {
      case 3:
        gTeamInventory_203B460->teamStorage[gUnknown_203B3F0->itemIndex] = gUnknown_203B3F0->unk9C;
        // Fallthrough needed to match
      case 2:
        sub_803A504(1);
        break;
      case 1:
        sub_803A690();
        break;
  }
}

void sub_803A86C(void)
{
    switch(sub_801B410())
    {
        case 1:
        case 0:
            break;
        case 2:
        case 3:
            sub_801B450();
            sub_803A504(1);
            break;
    }
}

//////////////////////////////////////////

u32 sub_803A888(void)
{
    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
    gUnknown_203B3F4 = MemoryAlloc(sizeof(struct unkStruct_203B3F4), 8);
    sub_803A924(0);
    return 1;
}

u32 sub_803A8B8(void)
{
  switch(gUnknown_203B3F4->state) {
    case 0:
    case 1:
        sub_803AAC4();
        break;
    case 2:
        sub_803AB34();
        break;
    case 3:
        sub_803ABAC();
        break;
    case 4:
        return 3;
  }
    return 0;
}

void sub_803A908(void)
{
    if(gUnknown_203B3F4 != NULL)
    {
        MemoryFree(gUnknown_203B3F4);
        gUnknown_203B3F4 = NULL;
    }
}

void sub_803A924(u32 newState)
{
    gUnknown_203B3F4->state = newState;
    sub_803A93C();
    sub_803A9AC();
}

void sub_803A93C(void)
{
    s32 iVar4;
    sub_8006518(gUnknown_203B3F4->unk9C);
    if(gUnknown_203B3F4->state == 2)
    {
        gUnknown_203B3F4->unk9C[2] = gUnknown_80E7EA4;
    }
    else
    {
        for(iVar4 = 0; iVar4 < 4; iVar4++)
        {
            gUnknown_203B3F4->unk9C[iVar4] = gUnknown_80E7E8C;
        }
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B3F4->unk9C, 1, 1);
}

void sub_803A9AC(void)
{
  switch(gUnknown_203B3F4->state) {
    case 0:
        sub_80211AC(0,3);
        break;
    case 1:
        sub_8021354(1);
        break;
    case 2:
        sub_8021494();
        sub_803AA34();
        sub_8012D60(&gUnknown_203B3F4->unk4C,gUnknown_203B3F4->menuItems,0,0,gUnknown_203B3F4->unk8,2);
        break;
    case 3:
        sub_8021774(gUnknown_203B3F4->unk4,1,0);
        break;
    case 4:
        break;
  }
}
