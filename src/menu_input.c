#include "global.h"
#include "constants/input.h"
#include "menu.h"
#include "text.h"

extern struct UnkTextStruct1 gUnknown_2027370[4];
extern u8 gUnknown_80D4828[];

extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(u32 *);
extern u32 sub_80137A8(u32 *);
void MoveMenuCursorUp(u32 *);
void MoveMenuCursorDown(u32 *);
extern void sub_80073B8(u32);
extern s32 sub_8008ED0(u8 *);
extern void xxx_format_and_draw(u32, u32, u8 *, u32, u32);
void sprintfStatic(char *buffer, const char *text, ...);
extern s32 sub_8013800(u32 *, s32);
extern void sub_80073E0(u32);
extern void sub_8013660(u32 *);
void AddMenuCursorSprite(void *);

void sub_8012EBC(struct MenuStruct *param_1);

extern u32 gUnknown_80D47B8;
extern void sub_8013134(u32 *, u32, u32);
extern void sub_80137B0(u32 *, u32);

extern s16 sub_8009614(u32, u32);

void sub_8012D60(struct MenuStruct *param_1,struct MenuItem *menuItems,u32 *param_3,u16 *param_4,s32 param_5,
                s32 index)
{
  const u8 *textPtr;
  s32 counter;
  s32 menuIndex;
  s32 iVar1;
  
  counter = 0;
  menuIndex = -1;
  iVar1 = 0;
  param_1->index = index;
  param_1->menuItems = menuItems;
  param_1->unk8 = param_3;
  if (param_3 == 0) {
    param_1->unk8 = &gUnknown_80D47B8;
  }
  param_1->unkC = param_4;
  textPtr = menuItems->text;
  if(textPtr)
  {
      while (textPtr != 0) {
        if ((0 <= param_5) && (param_5 == menuItems->menuAction)) {
          menuIndex = counter;
        }
        if (*menuItems->text == '*') {
          iVar1 = counter;
        }
        menuItems++;
        counter++;
        textPtr = menuItems->text;
      }
  }
  if (menuIndex < 0) {
    menuIndex = iVar1;
  }
  sub_8013134(&param_1->unk14,counter,index);
  param_1->menuIndex = menuIndex;
  sub_80137B0(&param_1->unk14,0);
  param_1->unk4C = 1;
  param_1->unk4D = 1;
  param_1->unk4E = 1;
  param_1->menuAction = -1;
}

void sub_8012E04(struct MenuStruct *param_1,struct MenuItem *menuItems,u32 *param_3,u16 *param_4,s32 param_5,
                s32 index)
{
  const u8 *textPtr;
  s32 counter;
  struct MenuItem *menuItemPtr;
  s32 iVar1;
  s32 menuIndex;
  
  counter = 0;
  menuIndex = -1;
  iVar1 = 0;
  textPtr = menuItems->text;
  if (textPtr) {
    menuItemPtr = menuItems;
    while (textPtr != NULL) {
      if ((0 <= param_5) && (param_5 == menuItemPtr->menuAction)) {
        menuIndex = counter;
      }
      if (*menuItemPtr->text == '*') {
        iVar1 = counter;
      }
      menuItemPtr++;
      counter++;
      textPtr = menuItemPtr->text;
    }
  }
    
  if (menuIndex < 0) {
    menuIndex = iVar1;
  }
  sub_8013134(&param_1->unk14,counter,index);
  param_1->menuIndex = menuIndex;
  sub_80137B0(&param_1->unk14,0);
  param_1->index = index;
  param_1->unk8 = param_3;
  if (param_3 == 0) {
    param_1->unk8 = &gUnknown_80D47B8;
  }
  param_1->unkC = param_4;
  param_1->menuItems = menuItems;
  param_1->unk4E = 0;
  param_1->unk4C = 1;
  param_1->unk4D = 1;
  param_1->menuAction = -1;
}

void sub_8012EA4(struct MenuStruct *param_1, u32 r1)
{
    param_1->unk4C = r1;
    param_1->unk4D = 1;
    sub_8012EBC(param_1);
}

void sub_8012EBC(struct MenuStruct *param_1)
{
  s32 x;
  s32 y;
  u32 uVar1;
  const u8 *textPtr;
  struct MenuItem *menuItemsPtr;
  u16 *_puVar2;
  u32 *puVar3;
  s32 counter;
  s32 index;
  struct UnkTextStruct2 textStack[4];
  u8 buffer [256];
  struct UnkTextStruct1 *ptr_text;
  struct UnkTextStruct2 *ptr_text2;
  
  if (param_1->unk4D != 0) {
    sub_80073B8(param_1->index);
    index = param_1->index;
    ptr_text = &gUnknown_2027370[index];
    if ((ptr_text->unkC) == 6) {
      ptr_text2 = &textStack[index];
      sub_8006518(textStack);
      x = sub_8008ED0(param_1->unk0);
      xxx_format_and_draw((((ptr_text2->unk14[2]) * 8 - x) /2) + 8,
          0,*(u8 **)param_1, param_1->index, 0);
    }
    puVar3 = param_1->unk8;
    menuItemsPtr = param_1->menuItems;
    _puVar2 = param_1->unkC;
    counter = 0;
    if (menuItemsPtr->text != NULL) {
      do {
        textPtr = menuItemsPtr->text;
        if (*textPtr == '*') {
          textPtr++;
        }
        if (_puVar2 != NULL) {
            uVar1 = puVar3[*_puVar2];
            _puVar2++;
        }
        else if (menuItemsPtr->menuAction < 0) {
            uVar1 = puVar3[1];
        }
        else {
            uVar1 = puVar3[0];
        }
        sprintfStatic(buffer,gUnknown_80D4828,uVar1,textPtr);
        y = sub_8013800(&param_1->unk14,counter);
        xxx_format_and_draw(8,y,buffer,param_1->index,0);
        menuItemsPtr++;
        counter++;
      } while (menuItemsPtr->text != NULL);
    }
    sub_80073E0(param_1->index);
    param_1->unk4D = 0;
  }
  if (param_1->unk4E != 0) {
    if (param_1->unk4C != 0) {
      AddMenuCursorSprite(&param_1->unk14);
    }
    else {
      sub_8013660(&param_1->unk14);
    }
  }
}

u8 sub_8012FD8(struct MenuStruct *param_1) {
  u32 prevMenuIndex;
  s32 index;
  struct MenuItem *item;
  
  prevMenuIndex = param_1->menuIndex;
  if (param_1->unk4C != 0) {
    switch(GetKeyPress(&param_1->unk14))
    {
        case INPUT_DPAD_DOWN:
            MoveMenuCursorDown(&param_1->unk14);
            if (prevMenuIndex != param_1->menuIndex) {
                PlayMenuSoundEffect(3);
            }
            break;
        case INPUT_DPAD_UP:
            MoveMenuCursorUp(&param_1->unk14);
            if (prevMenuIndex != param_1->menuIndex) {
                PlayMenuSoundEffect(3);
            }
            break;
        case INPUT_A_BUTTON:
            index = sub_80137A8(&param_1->unk14);
            item = &param_1->menuItems[index];
            if ((-1 < item->menuAction) &&
               ((param_1->unkC == NULL || (param_1->unkC[index] != 1)))) {
              param_1->menuAction = item->menuAction;
              ++param_1; --param_1;
              param_1->unk4C = 0;
              param_1->unk38 = 0;
            }
            else
            {
                PlayMenuSoundEffect(2);
                break;
            }
            if ((param_1->unkC != NULL) && (param_1->unkC[index] == 2)) {
                PlayMenuSoundEffect(2);
            }
            else
                PlayMenuSoundEffect(0);
            break;
        case INPUT_B_BUTTON:
            if (-1 < param_1->menuItems[param_1->unk2E].menuAction) {
                param_1->menuAction = param_1->menuItems[param_1->unk2E].menuAction;
                param_1->unk4C = 0;
                PlayMenuSoundEffect(1);
            }
            break;
    }
  }
  sub_8012EBC(param_1);
  return param_1->unk4C;
}

u8 sub_80130A8(struct MenuStruct *param_1) {
  s32 index;
  s32 menuAction;
  struct MenuItem *menuItem;
  
  if (param_1->unk4C != 0) {

    switch(GetKeyPress(&param_1->unk14))
    {
        case INPUT_A_BUTTON:
            index = sub_80137A8(&param_1->unk14);
            menuItem = &param_1->menuItems[index];
            param_1->menuAction = menuItem->menuAction;
            param_1->unk4C = 0;
            param_1->unk38 = 0;
            PlayMenuSoundEffect(0);
            break;
        case INPUT_B_BUTTON:
            if(menuAction = param_1->menuItems[param_1->unk2E].menuAction, -1 < menuAction) {
              param_1->menuAction = menuAction;
              param_1->unk4C = 0;
              PlayMenuSoundEffect(0);
            }
            break;
    }
  }
  sub_8012EBC(param_1);
  return param_1->unk4C;
}

bool8 sub_8013114(struct MenuStruct *param_1, s32 *menuAction){
    if(param_1->unk4C != 0){
        return TRUE;
    }
    if (menuAction != NULL){
        *menuAction = param_1->menuAction;
    }
    return FALSE;
}
