#include "global.h"
#include "input.h"
#include "item.h"
#include "team_inventory.h"
#include "memory.h"
#include "menu.h"
#include "text1.h"
#include "text2.h"
#include "menu_input.h"
#include "friend_area.h"

struct unkStruct_203B3F0
{
    // size: 0x138
    u32 state;
    u8 id;
    u32 menuAction;
    struct MenuItem menuItems[8];
    struct MenuStruct unk4C;
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
    u8 friendArea;
    u8 fill5[0x8 - 5];
    u32 menuAction;
    struct MenuItem menuItems[8];
    struct MenuStruct unk4C;
    struct UnkTextStruct2 unk9C[4];
};

extern struct unkStruct_203B3F4 *gUnknown_203B3F4;



const struct UnkTextStruct2 gUnknown_80E7E34 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E7E4C = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x14, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E7E64 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x14, 0x0e,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};
ALIGNED(4) const char gDebug_NumberText[] = "Number?";
ALIGNED(4) static const u8 fill0[] = "pksdir0";
const struct UnkTextStruct2 gUnknown_80E7E8C = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E7EA4 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};
ALIGNED(4) const u8 gDebug_CloseText[] = "CLOSE";
ALIGNED(4) const u8 gDebug_OpenText[] = "OPEN";
ALIGNED(4) static const u8 fill1[] = "pksdir0";
extern bool8 *gFriendAreas;
extern const char *gUnknown_80D4970[];

extern void sub_801B3C0(struct Item *);
extern void sub_8013AA0(u32 *);
extern void sub_801C8C4(u32, u32, u32, u32);
extern void sub_801CB5C(u32);
extern void sub_801CCD8();
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void sub_8013C68(u32 *);
extern u32 sub_801CA08(u32);
extern u8 sub_801CB24();
extern void sub_801CBB8();
extern u32 sub_8013BBC(u32 *);
extern u32 sub_801B410();
extern void sub_801B450();
extern void sub_80211AC(u32, u32);
extern void sub_8021354(u32);
extern void sub_8021494();
extern void sub_803AA34();
extern void sub_8021774(u8,u32, u32);
extern void sub_809249C(u8, u32);
extern void sub_8021830(void);
extern u32 sub_80217EC(void);
extern u8 sub_803ABC8(void);
extern u32 sub_8021274(u32);
extern u8 sub_802132C(void);
extern void sub_80213A0(void);
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
    s32 index;

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
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B3F0->unkD8[index] = gUnknown_80E7E34;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B3F0->unkD8, 1, 1);
}

void sub_803A5A0(void)
{
  struct Item item;

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
        sub_8012D60(&gUnknown_203B3F0->unk4C, gUnknown_203B3F0->menuItems, 0, 0, gUnknown_203B3F0->menuAction, 2);
        break;
    case 3:
        gUnknown_203B3F0->unkAC = 3;
        gUnknown_203B3F0->unkA4 = 0;
        gUnknown_203B3F0->unkA8 = 0x3e7;
        gUnknown_203B3F0->unkA0 = gTeamInventoryRef->teamStorage[gUnknown_203B3F0->id];
        gUnknown_203B3F0->unkB0 = 1;
        gUnknown_203B3F0->unkB4 = &gUnknown_203B3F0->unkD8[1];
        gUnknown_203B3F0->unkB8 = 0x2C;
        gUnknown_203B3F0->unkBC = 0x12;
        sub_8013AA0(&gUnknown_203B3F0->unk9C);
        sub_803A690();
        break;
    case 4:
        xxx_init_itemslot_8090A8C(&item,gUnknown_203B3F0->id,0);
        sub_801B3C0(&item);
        break;
    case 5:
        break;
  }
}

void sub_803A690(void)
{
  sub_8008C54(gUnknown_203B3F0->unkB0);
  sub_80073B8(gUnknown_203B3F0->unkB0);
  xxx_call_draw_string(4, 0, gDebug_NumberText, gUnknown_203B3F0->unkB0, 0);
  sub_8013C68(&gUnknown_203B3F0->unk9C);
  sub_80073E0(gUnknown_203B3F0->unkB0);
  sub_801CCD8();
  sub_8012EA4(&gUnknown_203B3F0->unk4C,0);
}

void sub_803A6F0(void)
{
  s32 loopMax = 0;

  gUnknown_203B3F0->menuItems[loopMax].text = gDebug_NumberText;
  gUnknown_203B3F0->menuItems[loopMax].menuAction = 2;
  gUnknown_203B3F0->menuAction = 2;
  if (!IsNotMoneyOrUsedTMItem(gUnknown_203B3F0->id)) {
    gUnknown_203B3F0->menuItems[loopMax].menuAction = -1;
    gUnknown_203B3F0->menuAction = 3;
  }
  loopMax += 1;
  gUnknown_203B3F0->menuItems[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B3F0->menuItems[loopMax].menuAction = 3;
  loopMax += 1;
  gUnknown_203B3F0->menuItems[loopMax].text = NULL;
  gUnknown_203B3F0->menuItems[loopMax].menuAction = 1;
}

void sub_803A740(void)
{
  switch(sub_801CA08(1)) {
    case 0:
    case 1:
        break;
    case 3:
        gUnknown_203B3F0->id = sub_801CB24();
        sub_803A504(2);
        break;
    case 4:
        gUnknown_203B3F0->id = sub_801CB24();
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
  s32 menuAction;

  menuAction = 0;
  sub_801CA08(0);
  if (sub_8012FD8(&gUnknown_203B3F0->unk4C) == '\0') {
    sub_8013114(&gUnknown_203B3F0->unk4C,&menuAction);
  }
  switch(menuAction)
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
        gTeamInventoryRef->teamStorage[gUnknown_203B3F0->id] = gUnknown_203B3F0->unk9C;
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
    s32 index;
    sub_8006518(gUnknown_203B3F4->unk9C);
    if(gUnknown_203B3F4->state == 2)
    {
        gUnknown_203B3F4->unk9C[2] = gUnknown_80E7EA4;
    }
    else
    {
        for(index = 0; index < 4; index++)
        {
            gUnknown_203B3F4->unk9C[index] = gUnknown_80E7E8C;
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
        sub_8012D60(&gUnknown_203B3F4->unk4C,gUnknown_203B3F4->menuItems,0,0,gUnknown_203B3F4->menuAction,2);
        break;
    case 3:
        sub_8021774(gUnknown_203B3F4->friendArea,1,0);
        break;
    case 4:
        break;
  }
}

void sub_803AA34(void)
{
    s32 index;
    u8 *FriendAreas;


    index = 0;

    // So dumb that it matches...
    FriendAreas = gFriendAreas;

    if(FriendAreas[gUnknown_203B3F4->friendArea])
    {
        gUnknown_203B3F4->menuItems[0].text = gDebug_CloseText;
        if(sub_803ABC8())
            gUnknown_203B3F4->menuItems[0].menuAction = 3;
        else
            gUnknown_203B3F4->menuItems[0].menuAction = -1;
    }
    else
    {
        gUnknown_203B3F4->menuItems[0].text = gDebug_OpenText;
        gUnknown_203B3F4->menuItems[0].menuAction = 2;
    }

    index++;
    gUnknown_203B3F4->menuItems[index].text = *gUnknown_80D4970;
    gUnknown_203B3F4->menuItems[index].menuAction = 4;

    index++;
    gUnknown_203B3F4->menuItems[index].text = NULL;
    gUnknown_203B3F4->menuItems[index].menuAction = 1;

    gUnknown_203B3F4->menuAction = gUnknown_203B3F4->menuItems[0].menuAction;
}

void sub_803AAC4(void)
{
    switch(sub_8021274(1))
    {
        case 0:
        case 1:
            break;
        case 3:
            gUnknown_203B3F4->friendArea = sub_802132C();
            sub_803A924(2);
            break;
        case 4:
            gUnknown_203B3F4->friendArea = sub_802132C();
            sub_803A924(3);
            break;
        case 2:
            sub_80213A0();
            sub_803A924(4);
            break;
   }
}

void sub_803AB34(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_8021274(0);
    if(!sub_8012FD8(&gUnknown_203B3F4->unk4C))
        sub_8013114(&gUnknown_203B3F4->unk4C, &menuAction);
    switch(menuAction)
    {
        case 2:
            UnlockFriendArea(gUnknown_203B3F4->friendArea);
            sub_803A924(1);
            break;
        case 3:
            sub_809249C(gUnknown_203B3F4->friendArea, 1);
            sub_803A924(1);
            break;
        case 4:
            sub_803A924(3);
            break;
        case 1:
            sub_803A924(1);
            break;
    }
}

void sub_803ABAC(void)
{
    switch(sub_80217EC())
    {
        case 2:
        case 3:
            sub_8021830();
            sub_803A924(1);
            break;
        case 0:
        case 1:
            break;
    }
}
