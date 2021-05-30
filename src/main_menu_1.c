#include "global.h"
#include "main_menu.h"
#include "menu.h"
#include "text.h"

struct unkStruct_203B34C
{
    // size: 0x1A8
    u32 unk0;
    u32 unk4;
    struct MenuItem *unk8; // Array of menu choices??
    u8 fillC[0x30 - 0xC];
    s16 menuIndex;
    u8 fill32[0x144 - 0x32];
    struct UnkTextStruct2 unk144[4];
    /* 0x1A4 */ u32 currMenuChoice;
};

extern struct unkStruct_203B34C *gUnknown_203B34C;
extern u32 gUnknown_203B350;


extern u32 gUnknown_80E59E0;
extern u32 gUnknown_80E5A78;
extern u32 gUnknown_80E5B34;
extern u32 gUnknown_80E5BC4;
extern u32 gUnknown_80E5CB4;
extern u32 gUnknown_80E5A60;

extern const struct MenuItem gUnknown_80E59F8[];
extern const struct MenuItem gUnknown_80E5A90[];
extern const struct MenuItem gUnknown_80E5AFC[];
extern const struct MenuItem gUnknown_80E5B4C[];
extern const struct MenuItem gUnknown_80E5B8C[];
extern const struct MenuItem gUnknown_80E5BDC[];
extern const struct MenuItem gUnknown_80E5C18[];
extern const struct MenuItem gUnknown_80E5CCC[];
extern const struct MenuItem gUnknown_80E5D0C[];
extern const struct MenuItem gUnknown_80E5D48[];
extern const struct MenuItem gUnknown_80E5DA0[];
extern const struct MenuItem gUnknown_80E5DF0[];
extern const struct MenuItem gUnknown_80E5E5C[];
extern const struct MenuItem gUnknown_80E5EBC[];
extern const struct MenuItem gUnknown_80E5F1C[];
extern const struct MenuItem gUnknown_80E5F80[];
extern const struct MenuItem gUnknown_80E5FCC[];
extern const struct MenuItem gUnknown_80E6030[];

extern u8 sub_803D0D8();
extern s32 sub_8011C34();
extern s32 sub_8095324(u32);
extern void SetMenuItems(u32 *, struct UnkTextStruct2 *, u32, u32 *, const struct MenuItem *, u32, u32, u32);
void SetMainMenuItems(void);
extern bool8 SetMainMenuText();
extern void sub_8035CF4(u32 *, u32, u32);
extern void sub_8035CC0(struct UnkTextStruct2 *, u32);

bool8 SetMainMenuText(void)
{
  u32 menuChoice;
  struct MenuItem *preload;

 // Have to load the pointer before the index
  preload = gUnknown_203B34C->unk8;
  menuChoice = preload[gUnknown_203B34C->menuIndex].menuAction; // chosen menu action?
  if (gUnknown_203B34C->currMenuChoice == menuChoice) {
    return FALSE;
  }

  gUnknown_203B34C->currMenuChoice = menuChoice;
  sub_8035CC0(gUnknown_203B34C->unk144,2);
  sub_8035CC0(gUnknown_203B34C->unk144,3);
  switch(menuChoice) {
    case MENU_WIRELESS_COMMS:
        // Using wireless communications, you can go on an adventure to unknown worlds.
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E6030,0,0,0);
        break;
    case MENU_WONDER_MAIL:
        // Using passwords, you can receive Wonder Mail
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5F80,0,0,0);
        break;
    case MENU_AWAITING_RESCUE:
        // You are awaiting resuce by a friend
        // You can give up waiting for rescue
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5F1C,0,0,0);
        break;
    case MENU_NEW_GAME:
        // Start an entirely new adventure
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5CCC,0,0,0);
        break;
    case MENU_CONTINUE:
        // Resume your adventure from where you last saved
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5DA0,0,0,0);
        break;
    case MENU_DELETE_SAVE_PROMPT:
        // This will delete your saved game data.
        // Beware! This will delete it forever
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5DF0,0,0,0);
        break;
    case MENU_ADVENTURE_LOG:
        // Check your career as an adventurer
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5D0C,0,0,0);
        break;
    case MENU_FRIEND_RESCUE:
        // Using a Game Link cable or passwords, friends may rescue each other
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5E5C,0,0,0);
        break;
    case MENU_TRADE_ITEMS:
        // Using a Game Link cable you can trade stored items with a friend
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5EBC,0,0,0);
        break;
    case MENU_DUAL_SLOT:
        // Using Dual Slot function, you can receive teams from your friends
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5FCC,0,0,0);
        break;
    case MENU_DEBUG:
        // This is the Debug Mode.
        // It won't be in the release version
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5D48,0,0,0);
        break;
    default:
        break;
  }
  return TRUE;
}

void sub_803623C(void)
{
  sub_8035CC0(gUnknown_203B34C->unk144,1);
  SetMainMenuItems();
  gUnknown_203B34C->currMenuChoice = -1;
  if (SetMainMenuText()) {
    sub_8035CF4(&gUnknown_203B34C->unk4,2,0);
  }
  sub_8035CF4(&gUnknown_203B34C->unk4,0,1);
}

void SetMainMenuItems(void)
{ 
  if (sub_8011C34() != -1) {
    if (sub_8095324(1) == 0) {
      if (sub_8095324(7) != 0) {
        if (sub_803D0D8() != 0) {
            // Revive Team
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
            // Wonder Mail
          SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5C18,1,gUnknown_203B350,1);
        }
        else {
            // Revive Team
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
          SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5BC4,gUnknown_80E5BDC,1,gUnknown_203B350,1);
        }
      }
      else {
        if (sub_803D0D8() != 0) {
            // Continue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
            // Wonder Mail
          SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5AFC,1,gUnknown_203B350,1);
        }
        else {
            // Continue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
          SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A60,gUnknown_80E5A90,1,gUnknown_203B350,1);
        }
      }
    }
    else {
      if (sub_803D0D8() != 0) {
            // Awaiting Rescue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
            // Wonder Mail
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5B8C,1,gUnknown_203B350,1);
      }
      else {
            // Awaiting Rescue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
        SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5B34,gUnknown_80E5B4C,1,gUnknown_203B350,1);
      }
    }
  }
  else
  {
      // New Game
      // Adventure Log
    SetMenuItems(&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E59E0,gUnknown_80E59F8,1,gUnknown_203B350,1);
  }
}

bool8 sub_80363E0(void)
{
    if(gUnknown_203B34C == NULL)
        return FALSE;
    if(gUnknown_203B34C->unk0 == 0xC)
        return FALSE;
    return TRUE;
}
