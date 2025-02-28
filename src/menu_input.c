#include "global.h"
#include "globaldata.h"
#include "code_800558C.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "input.h"
#include "menu_input.h"
#include "sprite.h"
#include "text_util.h"
#include "text.h"
#include "util.h"
#include "structs/struct_sub80095e4.h"

const u32 gDefaultMenuTextColors[3] = { COLOR_WHITE_2, COLOR_RED, COLOR_RED };

const WindowHeader UnkData_80D47C4 = {0x01, 0x00, 0x10, 0x00};

const Window gUnknown_80D47C8[MAX_WINDOWS] = {
    0,
    0x06,
    0x02, 0x02,
    0x1a, 0x0c,
    0x0c, 0x00,
    &UnkData_80D47C4,

    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL,

    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL,

    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL,
};

ALIGNED(4) const u8 gUnknown_80D4828[] = _("{COLOR}%c%s");

const s32 gUnknown_80D4830[9] = {
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
        100000000
};

static void sub_8013134(MenuInputStruct *, u32, u32);
static void sub_801332C(DungeonPos *a0);
static void sub_8013470(MenuInputStruct *);
static bool8 sub_8013DD0(unkStructFor8013AA0 *);


u32 sub_8012A64(MenuInputStructSub *r0, s32 r1)
{
    if (r0 == NULL)
        return sub_8012AE8();

    if (r1 != -1)
        nullsub_34(r0, r1);

    if (r0->a_button != 0) {
        r0->a_button = 0;
        return INPUT_A_BUTTON;
    }

    if (r0->b_button == 0)
        return sub_8012AE8();

    r0->b_button = 0;
    return INPUT_B_BUTTON;
}

s32 GetKeyPress(MenuInputStruct *r0)
{
    if (r0 != NULL) {
        if (r0->unk28.a_button != 0)
            return INPUT_A_BUTTON;

        if (r0->unk28.b_button != 0)
            return INPUT_B_BUTTON;

        if (r0->unk28.dpad_left != 0)
            return INPUT_DPAD_LEFT;

        if (r0->unk28.dpad_right != 0)
            return INPUT_DPAD_RIGHT;
    }

    return sub_8012AE8();
}

s32 sub_8012AE8(void)
{
    if (gRealInputs.held & R_BUTTON) {
        if (gRealInputs.pressed & A_BUTTON)
            return INPUT_R_A_BUTTONS;

        if (gRealInputs.repeated & DPAD_UP)
            return INPUT_R_DPAD_UP_BUTTONS;

        if (gRealInputs.repeated & DPAD_DOWN)
            return INPUT_R_DPAD_DOWN_BUTTONS;

        if (gRealInputs.repeated & DPAD_LEFT)
            return INPUT_R_DPAD_LEFT_BUTTONS;

        if (gRealInputs.repeated & DPAD_RIGHT)
            return INPUT_R_DPAD_RIGHT_BUTTONS;

        if (gRealInputs.repeated & R_BUTTON)
            return INPUT_R_BUTTON;
    }
    else {
        if (gRealInputs.pressed & A_BUTTON)
            return INPUT_A_BUTTON;

        if (gRealInputs.pressed & B_BUTTON)
            return INPUT_B_BUTTON;

        if (gRealInputs.pressed & SELECT_BUTTON)
            return INPUT_SELECT_BUTTON;

        if (gRealInputs.pressed & START_BUTTON)
            return INPUT_START_BUTTON;

        if (gRealInputs.repeated & DPAD_UP)
            return INPUT_DPAD_UP;

        if (gRealInputs.repeated & DPAD_DOWN)
            return INPUT_DPAD_DOWN;

        if (gRealInputs.repeated & DPAD_LEFT)
            return INPUT_DPAD_LEFT;

        if (gRealInputs.repeated & DPAD_RIGHT)
            return INPUT_DPAD_RIGHT;

        if (gRealInputs.repeated & L_BUTTON)
            return INPUT_L_BUTTON;
    }

    return INPUT_NONE;
}

void sub_8012BC4(u32 x, u32 y, s32 n, s32 len, u32 color, u32 a5)
{
    s32 iVar1;
    u32 uVar2;
    const struct unkChar *iVar3;
    s32 counter;
    s32 *piVar3;
    s32 *piVar4;
    s32 total_x;
    s32 decimal[8];

    total_x = 0;

    ConvertToDecimal(decimal, n, len);

    counter = len - 1;
    if (counter > 0) {
        piVar3 = &decimal[counter];
        if (*piVar3 == 0) {
            do {
                *piVar3 = 0xFF;
                piVar3--;
                counter--;
                if (counter <= 0)
                    break;
            } while(*piVar3 == 0);
        }
    }

    counter = 0;
    if (counter < len && decimal[0] != 0xFF) {
        piVar4 = &decimal[0];
        do {
            iVar1 = *piVar4;
            piVar4++;
            uVar2 = ReturnIntFromChar2(iVar1 + 0x30);
            iVar3 = GetCharacter(uVar2);
            total_x += iVar3->unk6;
            xxx_call_draw_char(x - total_x, y, uVar2, color, a5);
            counter++;
            if (counter >= len)
                break;
        } while (*piVar4 != 0xff);
    }
}

void sub_8012C60(u32 x, u32 y, u32 a2, u32 color, u32 a4)
{
    u32 add_x;
    const struct unkChar *iVar3;
    u32 uVar2;

    uVar2 = ReturnIntFromChar2(a2);
    iVar3 = GetCharacter(uVar2);

    if (iVar3->unk6 < 12)
        add_x = ((12 - iVar3->unk6) / 2);
    else
        add_x = 0;

    xxx_call_draw_char(x + add_x, y, uVar2, color, a4);
}

void sub_8012CAC(Window *a0, const MenuItem *a1)
{
    s32 length;
    s32 maxLength;
    s32 count;

    count = 0;
    maxLength = 0;

    for (; a1->text != NULL; a1++) {
        count = (s16)(count + 1); // Because a simple `count++;` wasn't enough.
        length = (s16) sub_8008ED0(a1->text);
        if (length > maxLength) {
            maxLength = length;
        }
  }

    a0->width = (maxLength / 8) + 2;
    sub_8012D08(a0, count);
}

void sub_8012D08(Window *param_1, s32 param_2)
{
    s32 sVar2;
    s16 sVar3;

    sVar2 = (s16) sub_80095E4(param_2, 12);
    if (param_1->type == WINDOW_TYPE_WITH_HEADER)
        sVar2 = (s16)(sVar2 + 2);

    sVar3 = sVar2;
    param_1->height = sVar3;
    param_1->unk10 = sVar3;
}

void sub_8012D34(struct Window *param_1, s32 param_2)
{
    s32 sVar2;
    s16 sVar3;

    sVar2 = (s16) sub_8009614(param_2, 24);
    if (param_1->type == WINDOW_TYPE_WITH_HEADER)
        sVar2 = (s16)(sVar2 + 2);

    sVar3 = sVar2;
    param_1->height = sVar3;
    param_1->unk10 = sVar3;

}

void sub_8012D60(MenuStruct *param_1, const MenuItem *menuItems, const u32 *colorArray, u16 *param_4, s32 menuAction, s32 index)
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
    param_1->menuTextColorArray = colorArray;

    if (colorArray == NULL)
        param_1->menuTextColorArray = gDefaultMenuTextColors;

    param_1->unkC = param_4;
    textPtr = menuItems->text;

    if (textPtr) {
        while (textPtr != 0) {
            if (menuAction >= 0 && menuAction == menuItems->menuAction)
                menuIndex = counter;

            if (*menuItems->text == '*')
                iVar1 = counter;

            menuItems++;
            counter++;
            textPtr = menuItems->text;
        }
    }

    if (menuIndex < 0)
        menuIndex = iVar1;

    sub_8013134(&param_1->input, counter, index);
    param_1->input.menuIndex = menuIndex;
    sub_80137B0(&param_1->input, 0);

    param_1->unk4C = TRUE;
    param_1->unk4D = TRUE;
    param_1->unk4E = TRUE;
    param_1->menuAction = -1;
}

void sub_8012E04(MenuStruct *param_1, const MenuItem *menuItems, const u32 *colorArray, u16 *param_4, s32 menuAction, s32 index)
{
    const u8 *textPtr;
    s32 counter;
    const MenuItem *menuItemPtr;
    s32 iVar1;
    s32 menuIndex;

    counter = 0;
    menuIndex = -1;
    iVar1 = 0;
    textPtr = menuItems->text;

    if (textPtr) {
        menuItemPtr = menuItems;
        while (textPtr != NULL) {
            if (menuAction >= 0 && menuAction == menuItemPtr->menuAction)
                menuIndex = counter;

            if (*menuItemPtr->text == '*')
                iVar1 = counter;

            menuItemPtr++;
            counter++;
            textPtr = menuItemPtr->text;
        }
    }

    if (menuIndex < 0)
        menuIndex = iVar1;

    sub_8013134(&param_1->input, counter, index);
    param_1->input.menuIndex = menuIndex;
    sub_80137B0(&param_1->input, 0);

    param_1->index = index;
    param_1->menuTextColorArray = colorArray;
    if (colorArray == NULL)
        param_1->menuTextColorArray = gDefaultMenuTextColors;

    param_1->unkC = param_4;
    param_1->menuItems = menuItems;
    param_1->unk4E = FALSE;
    param_1->unk4C = TRUE;
    param_1->unk4D = TRUE;
    param_1->menuAction = -1;
}

void sub_8012EA4(MenuStruct *param_1, bool8 r1)
{
    param_1->unk4C = r1;
    param_1->unk4D = TRUE;
    sub_8012EBC(param_1);
}

void sub_8012EBC(MenuStruct *param_1)
{
    s32 x;
    s32 y;
    u32 color;
    const u8 *textPtr;
    const MenuItem *menuItemsPtr;
    u16 *_puVar2;
    const u32 *colorArray;
    s32 counter;
    s32 index;
    Windows textStack;
    u8 buffer[256];
    UnkTextStruct1 *ptr_text;
    Window *ptr_text2;

    if (param_1->unk4D) {
        sub_80073B8(param_1->index);
        index = param_1->index;
        ptr_text = &gUnknown_2027370[index];

        if (ptr_text->unkC == 6) {
            ptr_text2 = &textStack.id[index];
            RestoreUnkTextStruct_8006518(&textStack);
            x = sub_8008ED0(param_1->unk0);
            PrintFormattedStringOnWindow(((ptr_text2->unk14->f2 * 8 - x) / 2) + 8, 0, param_1->unk0, param_1->index, 0);
        }

        colorArray = param_1->menuTextColorArray;
        menuItemsPtr = param_1->menuItems;
        _puVar2 = param_1->unkC;
        counter = 0;

        if (menuItemsPtr->text != NULL) {
            do {
                textPtr = menuItemsPtr->text;
                if (*textPtr == '*')
                    textPtr++;

                if (_puVar2 != NULL) {
                    color = colorArray[*_puVar2];
                    _puVar2++;
                }
                else if (menuItemsPtr->menuAction < 0)
                    color = colorArray[1]; // Color the action red
                else
                    color = colorArray[0]; // Use the default white

                sprintfStatic(buffer,gUnknown_80D4828, color, textPtr);
                y = GetMenuEntryYCoord(&param_1->input, counter);
                PrintFormattedStringOnWindow(8, y, buffer, param_1->index, 0);
                menuItemsPtr++;
                counter++;
            } while (menuItemsPtr->text != NULL);
        }

        sub_80073E0(param_1->index);
        param_1->unk4D = FALSE;
    }

    if (param_1->unk4E) {
        if (param_1->unk4C)
            AddMenuCursorSprite(&param_1->input);
        else
            sub_8013660(&param_1->input);
    }
}

bool8 sub_8012FD8(MenuStruct *param_1)
{
    u32 prevMenuIndex;
    s32 index;
    const MenuItem *item;

    prevMenuIndex = param_1->input.menuIndex;

    if (param_1->unk4C) {
        switch (GetKeyPress(&param_1->input)) {
            case INPUT_DPAD_DOWN:
                MoveMenuCursorDown(&param_1->input);
                if (prevMenuIndex != param_1->input.menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_DPAD_UP:
                MoveMenuCursorUp(&param_1->input);
                if (prevMenuIndex != param_1->input.menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_A_BUTTON:
                index = sub_80137A8(&param_1->input);
                item = &param_1->menuItems[index];

                if (item->menuAction > -1 && (param_1->unkC == NULL || param_1->unkC[index] != 1)) {
                    param_1->menuAction = item->menuAction;
                    ++param_1; --param_1;
                    param_1->unk4C = FALSE;
                    param_1->input.unk24 = 0;
                }
                else {
                    PlayMenuSoundEffect(2);
                    break;
                }

                if (param_1->unkC != NULL && param_1->unkC[index] == 2)
                    PlayMenuSoundEffect(2);
                else
                    PlayMenuSoundEffect(0);
                break;
            case INPUT_B_BUTTON:
                if (param_1->menuItems[param_1->input.unk1A].menuAction > -1) {
                    param_1->menuAction = param_1->menuItems[param_1->input.unk1A].menuAction;
                    param_1->unk4C = FALSE;
                    PlayMenuSoundEffect(1);
                }
                break;
        }
    }

    sub_8012EBC(param_1);
    return param_1->unk4C;
}

bool8 sub_80130A8(MenuStruct *param_1)
{
    s32 index;
    const MenuItem *menuItem;

    if (param_1->unk4C) {
        switch (GetKeyPress(&param_1->input))
        {
            case INPUT_A_BUTTON:
                index = sub_80137A8(&param_1->input);
                menuItem = &param_1->menuItems[index];
                param_1->menuAction = menuItem->menuAction;
                param_1->unk4C = FALSE;
                param_1->input.unk24 = 0;
                PlayMenuSoundEffect(0);
                break;
            case INPUT_B_BUTTON:
                if (param_1->menuItems[param_1->input.unk1A].menuAction > -1) {
                    param_1->menuAction = param_1->menuItems[param_1->input.unk1A].menuAction;
                    param_1->unk4C = FALSE;
                    PlayMenuSoundEffect(0);
                }
                break;
        }
    }

    sub_8012EBC(param_1);
    return param_1->unk4C;
}

bool8 sub_8013114(MenuStruct *param_1, s32 *menuAction)
{
    if (param_1->unk4C)
        return TRUE;

    if (menuAction != NULL)
        *menuAction = param_1->menuAction;

    return FALSE;
}

static void sub_8013134(MenuInputStruct *param_1, u32 menuItemCounter, u32 index)
{
    UnkTextStruct1 *temp;

    temp = &gUnknown_2027370[index];

    param_1->unk0 = index;
    param_1->menuIndex = 0;
    param_1->unk1A = menuItemCounter;
    param_1->unk1C = menuItemCounter;
    param_1->unk1E = 0;
    param_1->unk4 = 0;

    if (temp->unkC == 6)
        param_1->firstEntryY = 16;
    else
        param_1->firstEntryY = 2;

    param_1->unkC = 0;
    param_1->unkE = 0;
    param_1->unk14.x = 0;
    param_1->unk24 = 0;
    sub_801317C(&param_1->unk28);
}

void sub_801317C(MenuInputStructSub *param_1)
{
    param_1->unk0 = 0;
    param_1->a_button = 0;
    param_1->b_button = 0;
    param_1->dpad_left = 0;
    param_1->dpad_right = 0;
    param_1->unk8 = -1;
    param_1->unkA = -1;
    nullsub_7(&param_1->unk8);
    ResetUnusedInputStruct();
}

void AddMenuCursorSprite(MenuInputStruct *param_1)
{
    AddMenuCursorSprite_(param_1, 0);
}

void AddMenuCursorSprite_(MenuInputStruct *a0, u8 *a1)
{
    struct SpriteOAM sp = {0};

    if (a0->unk1A > 0) {
        UpdateMenuCursorSpriteCoords(a0);

        if (!(a0->unk24 & 8)) {
            SpriteSetAffine1(&sp, 0);
            SpriteSetAffine2(&sp, 0);
            SpriteSetObjMode(&sp, 0);
            SpriteSetMosaic(&sp, 0);
            SpriteSetBpp(&sp, 0);
            SpriteSetShape(&sp, 0);
            SpriteSetMatrixNum(&sp, 0);
            SpriteSetSize(&sp, 0);
            SpriteSetTileNum(&sp, 0x3F4);
            SpriteSetPriority(&sp, 0);
            SpriteSetPalNum(&sp, 15);
            SpriteSetUnk6_0(&sp, 0);
            SpriteSetUnk6_1(&sp, 0);
            SpriteSetX(&sp, a0->unk8.x);
            SpriteSetY(&sp, a0->unk8.y + 1);

            AddSprite(&sp, 0xFF, 0, 0);
        }
    }

    sub_8013470(a0);
    if (a0->unk14.x != 0)
        sub_801332C(&a0->unk14);

    a0->unk24++;
}

void nullsub_34(MenuInputStructSub *a0, s32 a1)
{
}

static void sub_801332C(DungeonPos *a0)
{
    struct SpriteOAM sp = {0};

    SpriteSetAffine1(&sp, 0);
    SpriteSetAffine2(&sp, 0);
    SpriteSetObjMode(&sp, 1);
    SpriteSetMosaic(&sp, 0);
    SpriteSetBpp(&sp, 0);
    SpriteSetShape(&sp, 0);
    SpriteSetMatrixNum(&sp, 0);
    SpriteSetSize(&sp, 0);
    SpriteSetTileNum(&sp, 0x3F5);
    SpriteSetPriority(&sp, 0);
    SpriteSetPalNum(&sp, 15);
    SpriteSetUnk6_0(&sp, 0);
    SpriteSetUnk6_1(&sp, 0);
    SpriteSetX(&sp, a0->x);
    SpriteSetY(&sp, a0->y + 1);

    AddSprite(&sp, 0xFF, NULL, NULL);
}

static void sub_8013470(MenuInputStruct *a0)
{
    struct SpriteOAM sp = {0};

    if (a0->unkC != 0) {
        if (a0->unk1E != 0) {
            SpriteSetAffine1(&sp, 0);
            SpriteSetAffine2(&sp, 0);
            SpriteSetObjMode(&sp, 0);
            SpriteSetMosaic(&sp, 0);
            SpriteSetBpp(&sp, 0);
            SpriteSetShape(&sp, 0);
            SpriteSetMatrixNum(&sp, 0);
            SpriteSetSize(&sp, 0);
            SpriteSetTileNum(&sp, 0x3F2);
            SpriteSetPriority(&sp, 0);
            SpriteSetPalNum(&sp, 15);
            SpriteSetUnk6_0(&sp, 0);
            SpriteSetUnk6_1(&sp, 0);
            SpriteSetX(&sp, a0->unkC);
            SpriteSetY(&sp, a0->unkE);

            AddSprite(&sp, 0xFF, NULL, NULL);
        }
        if (a0->unk20 != 0 && a0->unk20 != a0->unk1E + 1) {
            SpriteSetAffine1(&sp, 0);
            SpriteSetAffine2(&sp, 0);
            SpriteSetObjMode(&sp, 0);
            SpriteSetMosaic(&sp, 0);
            SpriteSetBpp(&sp, 0);
            SpriteSetShape(&sp, 0);
            SpriteSetMatrixNum(&sp, 0);
            SpriteSetSize(&sp, 0);
            SpriteSetTileNum(&sp, 0x3F3);
            SpriteSetPriority(&sp, 0);
            SpriteSetPalNum(&sp, 15);
            SpriteSetUnk6_0(&sp, 0);
            SpriteSetUnk6_1(&sp, 0);
            SpriteSetX(&sp, a0->unkC + 10);
            SpriteSetY(&sp, a0->unkE);

            AddSprite(&sp, 0xFF, NULL, NULL);
        }
    }
}

void sub_8013660(MenuInputStruct *param_1)
{
    if (0 < param_1->unk1A) {
        UpdateMenuCursorSpriteCoords(param_1);
        sub_801332C(&param_1->unk8);
    }
}

void UpdateMenuCursorSpriteCoords(MenuInputStruct *param_1)
{
    s32 index;
    UnkTextStruct1 *temp;

    index = param_1->unk0;
    temp = &gUnknown_2027370[index];
    param_1->unk8.x = temp->unk0 * 8 + param_1->unk4;
    param_1->unk8.y = temp->unk2 * 8 + GetMenuEntryYCoord(param_1, param_1->menuIndex);
}

void MoveMenuCursorDown(MenuInputStruct *param_1)
{
    param_1->unk24 = 0;

    if (param_1->unk1A < 1)
        param_1->menuIndex = 0;
    else {
        param_1->menuIndex++;

        if (param_1->menuIndex >= param_1->unk1A)
            param_1->menuIndex = 0;
    }
}

void sub_80136E0(MenuInputStruct *param_1, u8 param_2)
{
    param_1->unk24 = 0;

    if (param_1->unk1A < 1)
        param_1->menuIndex = 0;
    else {
        param_1->menuIndex++;

        if (param_1->menuIndex >= param_1->unk1A) {
            if (param_2 != 0)
                param_1->menuIndex = 0;
            else
                param_1->menuIndex = param_1->unk1A - 1;
        }
    }
}

void MoveMenuCursorUp(MenuInputStruct *param_1)
{
    param_1->unk24 = 0;

    if (param_1->unk1A < 1)
        param_1->menuIndex = 0;
    else {
        param_1->menuIndex--;

        if (param_1->menuIndex < 0)
            param_1->menuIndex = param_1->unk1A - 1;
    }
}

void sub_8013744(MenuInputStruct *param_1, u8 param_2)
{
    param_1->unk24 = 0;

    if (param_1->unk1A < 1)
        param_1->menuIndex = 0;
    else {
        param_1->menuIndex--;

        if (param_1->menuIndex < 0) {
            if (param_2 != 0)
                param_1->menuIndex = param_1->unk1A - 1;
            else
                param_1->menuIndex = 0;
        }
    }
}

void sub_8013780(MenuInputStruct *param_1, s32 param_2)
{
    if (param_2 < 0)
        param_1->menuIndex = 0;
    else if (param_2 >= param_1->unk1A)
        param_1->menuIndex = param_1->unk1A - 1;
    else
        param_1->menuIndex = param_2;

    param_1->unk24 = 0;
}

s32 sub_80137A8(MenuInputStruct *param_1)
{
    return param_1->menuIndex;
}

void sub_80137B0(MenuInputStruct *param_1, s32 param_2)
{
    s32 iVar1;
    s32 iVar2;

    if (param_2 >= 1) {
        iVar2 = param_2 << 8;
    }
    else {
        if (gUnknown_2027370[param_1->unk0].unkC == 6)
            iVar1 = 16;
        else
            iVar1 = 0;

        iVar2 = (gUnknown_2027370[param_1->unk0].unk6 * 8 - iVar1) << 8;
    }

    param_1->unk10 = iVar2 / param_1->unk1C;
}

void sub_80137F8(MenuInputStruct *param_1, u32 param_2)
{
    param_1->unk10 = param_2 << 8;
}

s32 GetMenuEntryYCoord(MenuInputStruct *menu, s32 entryId)
{
    s32 firstY = menu->firstEntryY;
    s32 iVar1 = entryId * menu->unk10;

    return firstY + (iVar1 / 256);
}

void sub_8013818(MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4)
{
    param_1->unk0 = param_4;
    param_1->unk22 = param_2;
    param_1->unk1C = param_3;
    param_1->unk14.x = 0;
    param_1->unk24 = 0;
    param_1->menuIndex = 0;
    param_1->unk1E = 0;

    sub_801317C(&param_1->unk28);
    sub_8013984(param_1);
    sub_80137F8(param_1, 12);
}

void sub_8013848(MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4)
{
    param_1->unk0 = param_4;
    param_1->unk22 = param_2;
    param_1->unk1C = param_3;
    param_1->unk14.x = 0;
    param_1->unk24 = 0;
    param_1->menuIndex = 0;
    param_1->unk1E = 0;

    sub_801317C(&param_1->unk28);
    sub_8013984(param_1);
    sub_80137F8(param_1, 24);
}

void sub_8013878(MenuInputStruct *param_1, s32 param_2)
{
    if (param_2 < 0)
        param_2 = 0;
    else if (param_2 >= param_1->unk22)
        param_2 = param_1->unk22 - 1;

    param_1->unk1E = param_2 / param_1->unk1C;
    param_1->menuIndex = param_2 % param_1->unk1C;
    param_1->unk24 = 0;
    sub_8013984(param_1);
}

bool8 sub_80138B8(MenuInputStruct *param_1, bool8 param_2)
{
    s32 sVar1;
    s32 oldIndex;

    sVar1 = param_1->unk1E;
    oldIndex = param_1->menuIndex;
    AddMenuCursorSprite(param_1);

    if (param_2) {
        switch (GetKeyPress(param_1)) {
            case INPUT_DPAD_UP:
                MoveMenuCursorUp(param_1);
                if (oldIndex != param_1->menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_DPAD_DOWN:
                MoveMenuCursorDown(param_1);
                if (oldIndex != param_1->menuIndex)
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
    return FALSE;
}

bool8 sub_8013938(MenuInputStruct *param_1)
{
    s32 sVar1;

    sVar1 = param_1->unk1E;
    param_1->unk1A = 0;
    param_1->unk14.x = 0;
    AddMenuCursorSprite(param_1);

    switch (GetKeyPress(param_1)) {
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
    return FALSE;
}

void sub_8013984(MenuInputStruct *param_1)
{
    s32 iVar2;
    s32 iVar4;
    UnkTextStruct1 *ptr;

    iVar4 = param_1->unk0;
    ptr = &gUnknown_2027370[iVar4];

    if (param_1->unk1C == 0)
        param_1->unk1C++;

    param_1->unk20 = param_1->unk22 / param_1->unk1C;
    iVar2 = param_1->unk22 % param_1->unk1C;
    if (iVar2 != 0)
        param_1->unk20++;

    if (param_1->unk1E > param_1->unk20 - 1)
        param_1->unk1E = param_1->unk20 - 1;

    if (param_1->unk1E != param_1->unk20 - 1 || param_1->unk22 % param_1->unk1C == 0)
        param_1->unk1A = param_1->unk1C;
    else
        param_1->unk1A = param_1->unk22 % param_1->unk1C;

    if (param_1->menuIndex > param_1->unk1A - 1)
        param_1->menuIndex = param_1->unk1A - 1;

    param_1->unk4 = 0;

    if (ptr->unkC == 6)
        param_1->firstEntryY = 16;
    else
        param_1->firstEntryY = 0;

    if (param_1->unk20 < 2)
        param_1->unkC = 0;
    else
        param_1->unkC = (ptr->unk0 + ptr->unk4 - 2) * 8;

    param_1->unkE = (ptr->unk2 + 1) * 8 - 2;
}

void sub_8013A54(MenuInputStruct *param_1)
{
    if (param_1->unk1E < param_1->unk20 - 1)
        param_1->unk1E++;
    else
        param_1->unk1E = 0;

    sub_8013984(param_1);
}

void sub_8013A7C(MenuInputStruct *param_1)
{
    if (param_1->unk1E < 1)
        param_1->unk1E = param_1->unk20 - 1;
    else
        param_1->unk1E--;

    sub_8013984(param_1);
}

void sub_8013AA0(unkStructFor8013AA0 *a0)
{
    s32 sp[10];

    SpriteSetAffine1(&a0->unk28, 0);
    SpriteSetAffine2(&a0->unk28, 0);
    SpriteSetObjMode(&a0->unk28, 0);
    SpriteSetMosaic(&a0->unk28, 0);
    SpriteSetBpp(&a0->unk28, 0);
    SpriteSetShape(&a0->unk28, 1);
    SpriteSetMatrixNum(&a0->unk28, 16);
    SpriteSetSize(&a0->unk28, 0);
    SpriteSetTileNum(&a0->unk28, 0x3F0);
    SpriteSetPriority(&a0->unk28, 0);
    SpriteSetPalNum(&a0->unk28, 15);
    SpriteSetX(&a0->unk28, DISPLAY_WIDTH);
    SpriteSetY(&a0->unk28, DISPLAY_WIDTH);

    a0->unk26 = 0;

    ConvertToDecimal(sp, a0->unkC, a0->unk10);

    a0->unk25 = a0->unk10;

    while (sp[a0->unk25 - 1] == 0 && a0->unk25 > 1)
        a0->unk25--;

    a0->unk0 = a0->unk4;

    ConvertToDecimal(sp, a0->unk4, a0->unk10);

    a0->unk24 = a0->unk25 - 1;

    while (sp[a0->unk24] == 0 && a0->unk24 != 0)
        a0->unk24--;
}

u32 sub_8013BBC(unkStructFor8013AA0 *a0)
{
    a0->unk26++;

    sub_8013D10(a0);

    if (a0->unk26 & 8) {
        SpriteSetMatrixNum(&a0->unk28, 16);
        AddSprite(&a0->unk28, 0x100, NULL, NULL);

        SpriteSetMatrixNum(&a0->unk28, 0);
        SpriteAddY(&a0->unk28, 16);

        AddSprite(&a0->unk28, 0x100, NULL, NULL);
    }

    if (sub_8013DD0(a0))
        return 1;

    switch (sub_8012AE8()) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
    }
    return 0;
}

void sub_8013C68(unkStructFor8013AA0 *a0)
{
    u8 ch;
    s32 i;
    s32 sp[10];

    ConvertToDecimal(sp, a0->unk0, a0->unk10);

    for (i = a0->unk10 - 1; i > 0 && sp[i] == 0; i--)
        sp[i] = 0xFF;

    for (i = 0; i < a0->unk25; i++) {
        if (sp[i] == 0xFF)
            ch = '*';
        else
            ch = '0' + sp[i];

        sub_8012C60(a0->unk1C - ((i + 1) * 12), a0->unk20, ch, 7, a0->unk14);
    }

    for (i = 0; i < a0->unk10; i++)
        sub_800792C(a0->unk14, a0->unk1C - ((i + 1) * 12) - 1, a0->unk20 + 10, 11, 5);
}

void sub_8013D10(unkStructFor8013AA0 *a0)
{
    s32 x, y;
    u8 uVar4;
    UnkTextStruct1 *ptr;

    ptr = &gUnknown_2027370[a0->unk14];
    uVar4 = a0->unk24;

    switch (sub_8012AE8()) {
        case INPUT_DPAD_LEFT:
            uVar4 = a0->unk24 < a0->unk25 - 1 ? a0->unk24 + 1 : 0;
            break;
        case INPUT_DPAD_RIGHT:
            uVar4 = a0->unk24 == 0 ? a0->unk25 - 1 : a0->unk24 - 1;
            break;
    }

    if (uVar4 != a0->unk24) {
        a0->unk24 = uVar4;
        PlayMenuSoundEffect(3);
        a0->unk26 = 8;
    }

    x = (a0->unk1C - ((a0->unk24 + 1) * 12) + (ptr->unk0 * 8)) - 3;
    SpriteSetX(&a0->unk28, x);

    y = a0->unk20 + (ptr->unk2 * 8) - 7;
    SpriteSetY(&a0->unk28, y);
}

static bool8 sub_8013DD0(unkStructFor8013AA0 *a0)
{
    s32 iVar2;

    switch (sub_8012AE8()) {
        case INPUT_DPAD_UP:
            if (a0->unk0 == a0->unkC) {
                PlayMenuSoundEffect(2);
                return FALSE;
            }

            iVar2 = a0->unk0 + gUnknown_80D4830[a0->unk24];
            PlayMenuSoundEffect(3);

            if (iVar2 > a0->unkC)
                a0->unk0 = a0->unkC;
            else
                a0->unk0 = iVar2;
            return TRUE;
        case INPUT_DPAD_DOWN:
            if (a0->unk0 == a0->unk8) {
                PlayMenuSoundEffect(2);
                return FALSE;
            }

            iVar2 = a0->unk0 - gUnknown_80D4830[a0->unk24];
            PlayMenuSoundEffect(3);

            if (iVar2 < a0->unk8)
                a0->unk0 = a0->unk8;
            else
                a0->unk0 = iVar2;
            return TRUE;
        default:
            return FALSE;
    }
}

void sub_8013E54(void)
{
    UnkTextStruct1 *ptr = &gUnknown_2027370[0];
    SpriteOAM SStack_18 = {0};

    SpriteSetAffine1(&SStack_18, 0);
    SpriteSetAffine2(&SStack_18, 0);
    SpriteSetObjMode(&SStack_18, 0);
    SpriteSetMosaic(&SStack_18, 0);
    SpriteSetBpp(&SStack_18, 0);
    SpriteSetShape(&SStack_18, 1);
    SpriteSetMatrixNum(&SStack_18, 0);
    SpriteSetSize(&SStack_18, 0);
    SpriteSetTileNum(&SStack_18, 0x3F0);
    SpriteSetPriority(&SStack_18, 0);
    SpriteSetPalNum(&SStack_18, 15);
    SpriteSetY(&SStack_18, (ptr->unk2 * 8) + 0x80);
    SpriteSetX(&SStack_18, 112);

    AddSprite(&SStack_18,0x100,0,0x0);
}

void sub_8013F84(void)
{
    UnkTextStruct1 *ptr = &gUnknown_2027370[0];
    SpriteOAM SStack_18 = {0};

    SpriteSetAffine1(&SStack_18, 0);
    SpriteSetAffine2(&SStack_18, 0);
    SpriteSetObjMode(&SStack_18, 0);
    SpriteSetMosaic(&SStack_18, 0);
    SpriteSetBpp(&SStack_18, 0);
    SpriteSetShape(&SStack_18, 1);
    SpriteSetMatrixNum(&SStack_18, 0);
    SpriteSetSize(&SStack_18, 0);
    SpriteSetTileNum(&SStack_18, 0x3F0);
    SpriteSetPriority(&SStack_18, 0);
    SpriteSetPalNum(&SStack_18, 15);
    SpriteSetY(&SStack_18, (ptr->unk2 * 8) + 0x60);
    SpriteSetX(&SStack_18, 112);

    AddSprite(&SStack_18,0x100,0,0x0);
}

void sub_80140B4(Windows *a0)
{
    s32 i;

    for(i = 0; i < 4; i++)
    {
        a0->id[i] = gUnknown_80D47C8[i];
    }
}

