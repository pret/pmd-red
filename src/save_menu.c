#include "global.h"
#include "input.h"
#include "menu.h"
#include "main_menu.h"
#include "memory.h"
#include "text.h"
#include "save.h"

struct unkSprite
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

struct unkStruct_203B360
{
    // size: 0x1b4
    u32 currMenu;
    u32 unk4;
    u32 unk8;
    u8 fill8[0x148 - 0xC];
    struct UnkTextStruct2 unk148[4];
    struct unkSprite unk1A8;
    u32 unk1B0; // Sprite count?
};

extern struct unkStruct_203B360 *gUnknown_203B364;
extern struct UnkTextStruct2 gUnknown_80E6F20;
extern struct UnkTextStruct2 gUnknown_80E6F38;
extern struct MenuItem gUnknown_80E7090[];
extern struct MenuItem gUnknown_80E6F50[];
extern struct MenuItem gUnknown_80E70CC;
extern struct MenuItem gUnknown_80E6FBC;
extern struct MenuItem gUnknown_80E7114;
extern struct MenuItem gUnknown_80E701C;
extern u8 gUnknown_80E7178[];
extern void ResetSprites(u32);
extern void sub_8038440();
extern void sub_8035CF4(u32 *, u32, u32);
extern void SetMenuItems(void *, struct UnkTextStruct2 *, u32, struct UnkTextStruct2 *, struct MenuItem *, u32, u32, u32);
extern u8 sub_80130A8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern void sub_80384D0();
extern void sub_8038830();
extern void sub_80388C4(void);
extern u8 sub_8012FD8(u32 *);
extern void sub_8014114();
extern void sub_80140F8(void);
extern void sub_8035CC0(struct UnkTextStruct2 *, u32);
extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern void AddSprite(struct unkSprite *, u32, u32, u32);

void CreateSaveMenu(s32 currMenu)
{
  s32 index;
  
  if (gUnknown_203B364 == NULL) {
    gUnknown_203B364 = MemoryAlloc(sizeof(struct unkStruct_203B360),8);
    MemoryFill8((u8 *)gUnknown_203B364,0,sizeof(struct unkStruct_203B360));
  }
  for(index = 0; index < 4; index++){
    gUnknown_203B364->unk148[index] = gUnknown_80E6F20;
  } 
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B364->unk148,1,1);

  if (currMenu == MENU_DELETE_SAVE) {
      // Beware, Deleting your Adventure
    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,gUnknown_80E7090,
                 0,6,0);
  }
  else {
      // Saving your Adventure
    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,gUnknown_80E6F50,
                 0,6,0);
  }
  sub_8035CF4(&gUnknown_203B364->unk8,0,1);
  gUnknown_203B364->unk4 = 0;
  gUnknown_203B364->currMenu = currMenu;
  sub_8038830();
}

void CleanSaveMenu(void)
{
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  if (gUnknown_203B364 != NULL) {
    MemoryFree(gUnknown_203B364);
    gUnknown_203B364 = NULL;
  }
}

s32 UpdateSaveMenu(void)
{
  int saveStatus;
  struct MainMenu *mainMenu;
  u32 menu;
  u32 uStack_18;
  u32 action;
  
  menu = MENU_NO_SCREEN_CHANGE;
  action = 3;

  switch(gUnknown_203B364->unk4)
  {
      default:
      case 2:  
        menu = MENU_NO_SCREEN_CHANGE;
        break;
      case 0:
        sub_8012FD8(&gUnknown_203B364->unk8);
        uStack_18 = 0;
        sub_80140F8();
        saveStatus = WriteSavetoPak(&uStack_18,sub_8011C1C());
        sub_8014114();
        switch(saveStatus)
        {
            case SAVE_COMPLETED:
                sub_8035CC0(gUnknown_203B364->unk148,0);
                if (gUnknown_203B364->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                &gUnknown_80E70CC,0,6,0);
                }
                else {
                    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                &gUnknown_80E6FBC,0,6,0);
                }
                if (gUnknown_203B364->currMenu == 0x2d) {
                    gUnknown_203B364->unk4 = 1;
                    return MENU_COMMUNICATION_1;
                }
                sub_8035CF4(&gUnknown_203B364->unk8,0,1);
                gUnknown_203B364->unk4 = 1;
                break;
            case SAVE_NOT_WRTTEN:
                sub_80141B4(gUnknown_80E7178,0,0,0);
                gUnknown_203B364->unk4 = 5;
                break;
            default:
                sub_8035CC0(gUnknown_203B364->unk148,0);
                if (gUnknown_203B364->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                    &gUnknown_80E7114,0,6,0);
                }
                else {
                    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                    &gUnknown_80E701C,0,6,0);
                }
                sub_8035CF4(&gUnknown_203B364->unk8,0,1);
                gUnknown_203B364->unk4 = 1;
                break;
        }
        menu = MENU_NO_SCREEN_CHANGE;
        break;
      case 1:
        if (sub_80130A8(&gUnknown_203B364->unk8) == '\0') {
            sub_8013114(&gUnknown_203B364->unk8,&action);
        }
        switch(action)
        {
            case 2:
            case 4:
                if ((gUnknown_203B364->currMenu == 0x29) || (gUnknown_203B364->currMenu == MENU_DELETE_SAVE)) {
                    gUnknown_203B364->unk4 = 1;
                    menu = MENU_MAIN_SCREEN;
                }
                else if (gUnknown_203B364->currMenu == 0x2d) {
                    gUnknown_203B364->unk4 = 1;
                    menu = MENU_COMMUNICATION_1;
                }
                else if (gUnknown_203B364->currMenu == 0x2c) {
                    gUnknown_203B364->unk4 = 1;
                    menu = 0x1f;
                }
                else {
                    mainMenu = GetMainMenu();
                    if (mainMenu->unk3A != 0) {
                        gUnknown_203B364->unk4 = 1;
                        menu = 0x35;
                    }
                    else {
                        gUnknown_203B364->unk4 = 1;
                        menu = gUnknown_203B364->currMenu == 0x2b ? MENU_WONDER_MAIL : MENU_FRIEND_RESCUE;
                    }
                }
                break;
            case 3:
                gUnknown_203B364->unk4 = 1;
                break;
        }
        sub_80388C4();
  }
    return menu;
}

void sub_8038830(void)
{
#ifdef NONMATCHING
    u32 r0;
    u32 r2;
#else
    register u32 r0 asm("r0");
    register u32 r2 asm("r2");
#endif
    u32 r1;
    u32 r4;
    u32 r5;
    struct unkSprite *sprite;
    
    r5 = 0;
    sprite = &gUnknown_203B364->unk1A8;

    r1 = sprite->unk0;
    r0 = 0xfeff;
    r0 &= r1;
    r0 &= 0xfdff;
    r0 &= 0xf3ff;
    r0 &= 0xefff;
    r0 &= 0xdfff;
    r2 = 0x4000;
    r0 &= 0x3fff;
    r0 |= r2;
    sprite->unk0 = r0;

    r2 = 0x3F0;
    r1 = sprite->unk4;
    r0 = 0xFC00;
    r0 &= r1;
    r0 |= r2;
    r0 &= 0xf3ff;
    r2 = 0xF;
    r4 = 0xF000;
    r0 &= 0xfff;
    r0 |= r4;

    sprite->unk4 = r0;
    
    sprite->unk2 = 0x70;

    r1 = 0x680;
    r2 &= sprite->unk6;
    r2 |= r1;
    sprite->unk6 = r2;
    
    gUnknown_203B364->unk1B0 = r5;
    ResetSprites(0);
}

void sub_80388C4(void) {
    if ((gUnknown_203B364->unk1B0 & 8) != 0) {
    AddSprite(&gUnknown_203B364->unk1A8, 0x100, 0, 0);
  }
  gUnknown_203B364->unk1B0++;
}
