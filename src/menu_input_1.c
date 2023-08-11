#include "global.h"
#include "constants/input.h"
#include "input.h"
#include "text1.h"
#include "menu_input.h"

extern void PlayMenuSoundEffect(u32);
void sub_801332C(u16 *);

void sub_8013660(struct MenuInputStruct *param_1)
{
    if (0 < param_1->unk1A) 
    {
        UpdateMenuCursorSpriteCoords(param_1);
        sub_801332C(&param_1->unk8);
    }
}

void UpdateMenuCursorSpriteCoords(struct MenuInputStruct *param_1)
{
    s32 index;
    struct UnkTextStruct1 *temp;

    index = param_1->unk0;
    temp = &gUnknown_2027370[index];
    param_1->unk8 = temp->unk0 * 8 + param_1->unk4;
    param_1->unkA = temp->unk2 * 8 + sub_8013800(param_1, param_1->menuIndex);
}

void MoveMenuCursorDown(struct MenuInputStruct *param_1)
{ 
    param_1->unk24 = 0;
    if (param_1->unk1A < 1) {
        param_1->menuIndex = 0;
    }
    else {
        param_1->menuIndex++;
        if (param_1->menuIndex >= param_1->unk1A) {
            param_1->menuIndex = 0;
        }
    }
}

void sub_80136E0(struct MenuInputStruct *param_1, u8 param_2)
{ 
    param_1->unk24 = 0;
    if (param_1->unk1A < 1) {
        param_1->menuIndex = 0;
    }
    else {
        param_1->menuIndex++;
        if (param_1->menuIndex >= param_1->unk1A) {
            if (param_2 != 0) {
                param_1->menuIndex = 0;    
            }
            else
            {
                param_1->menuIndex = param_1->unk1A - 1;
            }
        }
    }
}

void MoveMenuCursorUp(struct MenuInputStruct *param_1)
{ 
    param_1->unk24 = 0;
    if (param_1->unk1A < 1) {
        param_1->menuIndex = 0;
    }
    else {
        param_1->menuIndex--;
        if (param_1->menuIndex < 0) {
            param_1->menuIndex = param_1->unk1A + -1;
        }
    }
}

void sub_8013744(struct MenuInputStruct *param_1, u8 param_2)
{ 
    param_1->unk24 = 0;
    if (param_1->unk1A < 1) {
        param_1->menuIndex = 0;
    }
    else {
        param_1->menuIndex--;
        if (param_1->menuIndex < 0) {
            if (param_2 != 0) {
                param_1->menuIndex = param_1->unk1A + -1;
            }
            else {
                param_1->menuIndex = 0;
            }
        }
    }
}

void sub_8013780(struct MenuInputStruct *param_1, s32 param_2)
{
    if (param_2 < 0) {
        param_1->menuIndex = 0;
    }
    else if (param_2 >= param_1->unk1A) {
        param_1->menuIndex = param_1->unk1A - 1;
    }
    else {
        param_1->menuIndex = param_2;
    }
    param_1->unk24 = 0;
}

s32 sub_80137A8(struct MenuInputStruct *param_1)
{
    return param_1->menuIndex;
}

void sub_80137B0(struct MenuInputStruct *param_1, s32 param_2)
{
    s32 iVar1;
#ifndef NONMATCHING
    register s32 iVar2 asm("r0");
#else
    s32 iVar2;
#endif

    if (param_2 >= 1) {
        iVar2 = param_2 << 8;
    }
    else
    {
        if (gUnknown_2027370[param_1->unk0].unkC == 6)
        {
            iVar1 = 0x10;
        }
        else
        {
            iVar1 = 0;
        }
        iVar2 = (gUnknown_2027370[param_1->unk0].unk6 * 8 - iVar1);
        iVar2 <<= 8;
    }
    param_1->unk10 = iVar2 / param_1->unk1C;
}

void sub_80137F8(struct MenuInputStruct *param_1, u32 param_2)
{
    param_1->unk10 = param_2 << 8;
}

s32 sub_8013800(struct MenuInputStruct *param_1, s32 param_2)
{
    s32 iVar1;
    s32 iVar2;

    iVar2 = param_1->unk6;
    iVar1 = param_2 * param_1->unk10;
    if (iVar1 < 0) {
        iVar1 = iVar1 + 0xff;
    }
    return (iVar2 + (iVar1 >> 8));
}

void sub_8013818(struct MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4)
{
    param_1->unk0 = param_4;
    param_1->unk22 = param_2;
    param_1->unk1C = param_3;
    param_1->unk14 = 0;
    param_1->unk24 = 0;
    param_1->menuIndex = 0;
    param_1->unk1E = 0;
    sub_801317C(&param_1->unk28);
    sub_8013984(param_1);
    sub_80137F8(param_1,0xC);
}


void sub_8013848(struct MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4)
{
    param_1->unk0 = param_4;
    param_1->unk22 = param_2;
    param_1->unk1C = param_3;
    param_1->unk14 = 0;
    param_1->unk24 = 0;
    param_1->menuIndex = 0;
    param_1->unk1E = 0;
    sub_801317C(&param_1->unk28);
    sub_8013984(param_1);
    sub_80137F8(param_1,0x18);
}

void sub_8013878(struct MenuInputStruct *param_1, s32 param_2)
{
    if (param_2 < 0) {
        param_2 = 0;
    }
    else if (param_2 >= param_1->unk22) {
        param_2 = param_1->unk22 + -1;
    }
    param_1->unk1E = param_2 / param_1->unk1C;
    param_1->menuIndex = param_2 % param_1->unk1C;
    param_1->unk24 = 0;
    sub_8013984(param_1);
}

bool8 sub_80138B8(struct MenuInputStruct *param_1, bool8 param_2)
{
    s32 sVar1;
    s32 oldIndex;

    sVar1 = param_1->unk1E;
    oldIndex = param_1->menuIndex;
    AddMenuCursorSprite(param_1);
    if(param_2)
    {
        switch(GetKeyPress(param_1))
        {
            case INPUT_DPAD_UP:
                MoveMenuCursorUp(param_1);
                if(oldIndex != param_1->menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_DPAD_DOWN:
                MoveMenuCursorDown(param_1);
                if(oldIndex != param_1->menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_DPAD_LEFT:
                sub_8013A7C(param_1);
                break;
            case INPUT_DPAD_RIGHT:
                sub_8013A54(param_1);
                break;
        }
    }
    if (sVar1 != param_1->unk1E) {
        PlayMenuSoundEffect(4);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 sub_8013938(struct MenuInputStruct *param_1)
{
    s32 sVar1;

    sVar1 = param_1->unk1E;
    param_1->unk1A = 0;
    param_1->unk14 = 0;
    AddMenuCursorSprite(param_1);
    switch(GetKeyPress(param_1))
    {
        case INPUT_DPAD_LEFT:
            sub_8013A7C(param_1);
            break;
        case INPUT_DPAD_RIGHT:
            sub_8013A54(param_1);
            break;
    }
    if (sVar1 != param_1->unk1E) {
        PlayMenuSoundEffect(4);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void sub_8013984(struct MenuInputStruct * param_1)
{
    s32 iVar2;
    s32 iVar4;
    struct UnkTextStruct1 *ptr;

    iVar4 = param_1->unk0;
    ptr = &gUnknown_2027370[iVar4];
    if (param_1->unk1C == 0) {
        param_1->unk1C++;
    }
    param_1->unk20 = param_1->unk22 / param_1->unk1C;
    iVar2 = (param_1->unk22 % param_1->unk1C);
    if (iVar2 != 0) {
        param_1->unk20++;
    }
    if (param_1->unk1E > param_1->unk20 - 1) {
        param_1->unk1E = param_1->unk20 - 1;
    }
    if ((param_1->unk1E != param_1->unk20 - 1) || (param_1->unk22 % param_1->unk1C == 0)) 
    {
        param_1->unk1A = param_1->unk1C;
    }
    else
    {
        param_1->unk1A = param_1->unk22 % param_1->unk1C;
    }
    if (param_1->menuIndex > param_1->unk1A - 1) {
        param_1->menuIndex = param_1->unk1A - 1;
    }
    param_1->unk4 = 0;
    if (ptr->unkC == 6) {
        param_1->unk6 = 0x10;
    }
    else {
        param_1->unk6 = 0;
    }
    if (param_1->unk20 < 2) {
        param_1->unkC = 0;
    }
    else {
        param_1->unkC = (ptr->unk0 + ptr->unk4 + -2) * 8;
    }
    param_1->unkE = ((ptr->unk2) + 1) * 8 + -2;
}

void sub_8013A54(struct MenuInputStruct *param_1)
{
  if (param_1->unk1E < param_1->unk20 - 1) {
    param_1->unk1E++;
  }
  else
  {
    param_1->unk1E = 0;
  }
  sub_8013984(param_1);
}

void sub_8013A7C(struct MenuInputStruct *param_1)
{
  if (param_1->unk1E < 1) {
    param_1->unk1E = param_1->unk20 - 1;
  }
  else
  {
    param_1->unk1E--;
  }
  sub_8013984(param_1);
}
