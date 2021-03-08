#include "global.h"
#include "debug_menu.h"
#include "main_menu.h"

struct unkData
{
    u8 unk0[24];
};


struct DebugMenu
{
    // size: 0x1A4
    u8 fill0[0x140];
    /* 0x140 */ struct unkData unk140[4];
};
extern struct DebugMenu *gUnknown_203B3EC;
extern struct unkData gUnknown_80E7D40;

struct MenuItem
{
    const char *text;
    u32 menuAction; // action??
};



extern struct MenuItem gDebugMenuItems[8];
extern u32 gUnknown_80E7D58[6];

extern void *MemoryAlloc(u32, u32);
extern void MemoryFree(void *);
extern void MemoryFill8(u8 *, u8, u32);
extern void sub_800641C(void *, u32, u32);

extern void ResetUnusedInputStruct(void);
extern u8 sub_8012FD8(struct DebugMenu *);
extern void sub_8013114(struct DebugMenu *, s32 *);
extern void sub_80976F8(u8);
extern void sub_803A3BC(void);
extern void sub_803A3A0(void);

extern void SetMenuItems(void *menu, void *, u32, u32 *, struct MenuItem *entries, u32, u32, u32);
extern void sub_8035CF4(struct DebugMenu *, u32, u32);
extern void sub_8035CC0(struct unkData *, u32);

void CreateDebugMenu(void)
{
  int iVar2;

  if (gUnknown_203B3EC == NULL) {
    gUnknown_203B3EC = MemoryAlloc(0x1a4, 8);
    MemoryFill8((u8 *)gUnknown_203B3EC, 0, 0x1a4);
  }
  for(iVar2 = 0; iVar2 < 4; iVar2++){
    gUnknown_203B3EC->unk140[iVar2] = gUnknown_80E7D40;
  }
  ResetUnusedInputStruct();
  sub_800641C(&gUnknown_203B3EC->unk140, 1, 1);
  SetDebugMenuItems();
}

void DeleteDebugMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    if(gUnknown_203B3EC != NULL)
    {
        MemoryFree(gUnknown_203B3EC);
        gUnknown_203B3EC = NULL;
    }
}

u32 UpdateDebugMenu(void)
{
  u32 nextMenu;
  s32 counter;
  s32 debugMenuAction;

  nextMenu = MENU_NO_SCREEN_CHANGE;
  debugMenuAction = 11;

  if (sub_8012FD8(gUnknown_203B3EC) == 0) {
    sub_8013114(gUnknown_203B3EC, &debugMenuAction);
  }

  switch(debugMenuAction) {
      case MENU_DEBUG_MENU_DUNGEONS:
        nextMenu = MENU_DEBUG_DUNGEON;
        break;
      case MENU_DEBUG_MENU_FIELD:
        nextMenu = MENU_DEBUG_FIELD;
        break;
      case MENU_DEBUG_MENU_FIELD_MAP:
        nextMenu = MENU_DEBUG_FIELD_MAP;
        break;
      case MENU_DEBUG_MENU_FIELD_SCRIPT:
        nextMenu = MENU_DEBUG_FIELD_SCRIPT;
        break;
      case MENU_DEBUG_MENU_DEBUG_MENU:
        nextMenu = MENU_DEBUG_DEBUG_MENU;
        break;
      case MENU_DEBUG_MENU_UNKNOWN_1: // No option that correponds to this one
        nextMenu = MENU_DEBUG_UNKNOWN_1;
        break;
      case MENU_DEBUG_MENU_STORAGE:
        sub_803A3BC();
        nextMenu = MENU_MAIN_SCREEN;
        break;
      case MENU_DEBUG_MENU_H_OPEN:
        for(counter = 0; counter < 0x20; counter++){
          sub_80976F8(counter);
        }
        nextMenu = MENU_MAIN_SCREEN;
        break;
      case 10:
        sub_803A3A0();
        nextMenu = MENU_MAIN_SCREEN;
        break;
      case 11:
        nextMenu = MENU_NO_SCREEN_CHANGE;
  }
  return nextMenu;
}

void SetDebugMenuItems(void)
{
  SetMenuItems(gUnknown_203B3EC, gUnknown_203B3EC->unk140, 0, gUnknown_80E7D58, gDebugMenuItems, 1, 0xd, 0);
  sub_8035CF4(gUnknown_203B3EC,0,1);
}

void sub_803A3A0(void)
{
    sub_8035CC0(gUnknown_203B3EC->unk140, 0);
}
