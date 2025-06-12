#include "global.h"
#include "globaldata.h"
#include "structs/axdata.h"
#include "structs/struct_sub80095e4.h"
#include "code_800D090.h"
#include "music_util.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "input.h"
#include "menu_input.h"
#include "sprite.h"
#include "string_format.h"
#include "text_2.h"
#include "text_util.h"
#include "util.h"

const u32 gDefaultMenuTextColors[3] = { COLOR_WHITE_2, COLOR_RED, COLOR_RED };

const WindowHeader UnkData_80D47C4 = {0x01, 0x00, 0x10, 0x00};

const WindowTemplate gUnknown_80D47C8[MAX_WINDOWS] = {
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
static void ShowLeftRightArrows(MenuInputStruct *);
static bool8 sub_8013DD0(unkStructFor8013AA0 *);
static void MenuScrollLeft(MenuInputStruct *menuInput);
static void MenuScrollRight(MenuInputStruct *menuInput);

u32 sub_8012A64(MenuInputStructSub *r0, s32 r1)
{
    if (r0 == NULL)
        return GetMenuInput();

    if (r1 != -1)
        nullsub_34(r0, r1);

    if (r0->a_button != 0) {
        r0->a_button = 0;
        return INPUT_A_BUTTON;
    }

    if (r0->b_button == 0)
        return GetMenuInput();

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

    return GetMenuInput();
}

s32 GetMenuInput(void)
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

// arm9.bin::0201C4A0
void sub_8012BC4(u32 x, u32 y, s32 n, s32 len, u32 color, u32 windowId)
{
    s32 iVar1;
    u32 chr;
    const unkChar *iVar3;
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
            chr = GetCharId(iVar1 + 0x30);
            iVar3 = GetCharacter(chr);
            total_x += iVar3->width;
            DrawCharOnWindow(x - total_x, y, chr, color, windowId);
            counter++;
            if (counter >= len)
                break;
        } while (*piVar4 != 0xff);
    }
}

void DrawCharOnWindowWidth12(u32 x, u32 y, u32 chr, u32 color, u32 windowId)
{
    u32 add_x;
    u32 chrId = GetCharId(chr);
    const unkChar *chrInfo = GetCharacter(chrId);

    if (chrInfo->width < 12)
        add_x = ((12 - chrInfo->width) / 2);
    else
        add_x = 0;

    DrawCharOnWindow(x + add_x, y, chrId, color, windowId);
}

void sub_8012CAC(WindowTemplate *a0, const MenuItem *a1)
{
    s32 length;
    s32 maxLength;
    s32 count;

    count = 0;
    maxLength = 0;

    for (; a1->text != NULL; a1++) {
        count = (s16)(count + 1); // Because a simple `count++;` wasn't enough.
        length = (s16) GetStringLineWidth(a1->text);
        if (length > maxLength) {
            maxLength = length;
        }
  }

    a0->width = (maxLength / 8) + 2;
    sub_8012D08(a0, count);
}

void sub_8012D08(WindowTemplate *winTemplate, s32 param_2)
{
    s32 sVar2;
    s16 sVar3;

    sVar2 = (s16) sub_80095E4(param_2, 12);
    if (winTemplate->type == WINDOW_TYPE_WITH_HEADER)
        sVar2 = (s16)(sVar2 + 2);

    sVar3 = sVar2;
    winTemplate->height = sVar3;
    winTemplate->unk10 = sVar3;
}

void sub_8012D34(WindowTemplate *winTemplate, s32 param_2)
{
    s32 sVar2;
    s16 sVar3;

    sVar2 = (s16) sub_8009614(param_2, 24);
    if (winTemplate->type == WINDOW_TYPE_WITH_HEADER)
        sVar2 = (s16)(sVar2 + 2);

    sVar3 = sVar2;
    winTemplate->height = sVar3;
    winTemplate->unk10 = sVar3;

}

// arm9.bin::0201C26C
void sub_8012D60(MenuStruct *menu, const MenuItem *menuItems, const u32 *colorArray, u16 *param_4, s32 menuAction, s32 index)
{
    const u8 *textPtr;
    s32 counter;
    s32 menuIndex;
    s32 iVar1;

    counter = 0;
    menuIndex = -1;
    iVar1 = 0;
    menu->index = index;
    menu->menuItems = menuItems;
    menu->menuTextColorArray = colorArray;

    if (colorArray == NULL)
        menu->menuTextColorArray = gDefaultMenuTextColors;

    menu->unkC = param_4;
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

    sub_8013134(&menu->input, counter, index);
    menu->input.menuIndex = menuIndex;
    sub_80137B0(&menu->input, 0);

    menu->unk4C = TRUE;
    menu->unk4D = TRUE;
    menu->unk4E = TRUE;
    menu->menuAction = -1;
}

void sub_8012E04(MenuStruct *menu, const MenuItem *menuItems, const u32 *colorArray, u16 *param_4, s32 menuAction, s32 index)
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

    sub_8013134(&menu->input, counter, index);
    menu->input.menuIndex = menuIndex;
    sub_80137B0(&menu->input, 0);

    menu->index = index;
    menu->menuTextColorArray = colorArray;
    if (colorArray == NULL)
        menu->menuTextColorArray = gDefaultMenuTextColors;

    menu->unkC = param_4;
    menu->menuItems = menuItems;
    menu->unk4E = FALSE;
    menu->unk4C = TRUE;
    menu->unk4D = TRUE;
    menu->menuAction = -1;
}

void sub_8012EA4(MenuStruct *menu, bool8 r1)
{
    menu->unk4C = r1;
    menu->unk4D = TRUE;
    sub_8012EBC(menu);
}

void sub_8012EBC(MenuStruct *menu)
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
    WindowTemplates winTemplates;
    u8 buffer[256];
    Window *window;

    if (menu->unk4D) {
        sub_80073B8(menu->index);
        index = menu->index;
        window = &gWindows[index];

        if (window->type == WINDOW_TYPE_WITH_HEADER) {
            WindowTemplate *windowTemplate = &winTemplates.id[index];
            RestoreSavedWindows(&winTemplates);
            x = GetStringLineWidth(menu->unk0);
            PrintFormattedStringOnWindow(((windowTemplate->header->width * 8 - x) / 2) + 8, 0, menu->unk0, menu->index, 0);
        }

        colorArray = menu->menuTextColorArray;
        menuItemsPtr = menu->menuItems;
        _puVar2 = menu->unkC;
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
                y = GetMenuEntryYCoord(&menu->input, counter);
                PrintFormattedStringOnWindow(8, y, buffer, menu->index, 0);
                menuItemsPtr++;
                counter++;
            } while (menuItemsPtr->text != NULL);
        }

        sub_80073E0(menu->index);
        menu->unk4D = FALSE;
    }

    if (menu->unk4E) {
        if (menu->unk4C)
            AddMenuCursorSprite(&menu->input);
        else
            sub_8013660(&menu->input);
    }
}

bool8 sub_8012FD8(MenuStruct *menu)
{
    u32 prevMenuIndex;
    s32 index;
    const MenuItem *item;

    prevMenuIndex = menu->input.menuIndex;

    if (menu->unk4C) {
        switch (GetKeyPress(&menu->input)) {
            case INPUT_DPAD_DOWN:
                MoveMenuCursorDown(&menu->input);
                if (prevMenuIndex != menu->input.menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_DPAD_UP:
                MoveMenuCursorUp(&menu->input);
                if (prevMenuIndex != menu->input.menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_A_BUTTON:
                index = sub_80137A8(&menu->input);
                item = &menu->menuItems[index];

                if (item->menuAction > -1 && (menu->unkC == NULL || menu->unkC[index] != 1)) {
                    menu->menuAction = item->menuAction;
                    ++menu; --menu;
                    menu->unk4C = FALSE;
                    menu->input.unk24 = 0;
                }
                else {
                    PlayMenuSoundEffect(2);
                    break;
                }

                if (menu->unkC != NULL && menu->unkC[index] == 2)
                    PlayMenuSoundEffect(2);
                else
                    PlayMenuSoundEffect(0);
                break;
            case INPUT_B_BUTTON:
                if (menu->menuItems[menu->input.unk1A].menuAction > -1) {
                    menu->menuAction = menu->menuItems[menu->input.unk1A].menuAction;
                    menu->unk4C = FALSE;
                    PlayMenuSoundEffect(1);
                }
                break;
        }
    }

    sub_8012EBC(menu);
    return menu->unk4C;
}

bool8 sub_80130A8(MenuStruct *menu)
{
    s32 index;
    const MenuItem *menuItem;

    if (menu->unk4C) {
        switch (GetKeyPress(&menu->input))
        {
            case INPUT_A_BUTTON:
                index = sub_80137A8(&menu->input);
                menuItem = &menu->menuItems[index];
                menu->menuAction = menuItem->menuAction;
                menu->unk4C = FALSE;
                menu->input.unk24 = 0;
                PlayMenuSoundEffect(0);
                break;
            case INPUT_B_BUTTON:
                if (menu->menuItems[menu->input.unk1A].menuAction > -1) {
                    menu->menuAction = menu->menuItems[menu->input.unk1A].menuAction;
                    menu->unk4C = FALSE;
                    PlayMenuSoundEffect(0);
                }
                break;
        }
    }

    sub_8012EBC(menu);
    return menu->unk4C;
}

bool8 sub_8013114(MenuStruct *menu, s32 *menuAction)
{
    if (menu->unk4C)
        return TRUE;

    if (menuAction != NULL)
        *menuAction = menu->menuAction;

    return FALSE;
}

static void sub_8013134(MenuInputStruct *menuInput, u32 menuItemCounter, u32 windowId)
{
    Window *window = &gWindows[windowId];

    menuInput->windowId = windowId;
    menuInput->menuIndex = 0;
    menuInput->unk1A = menuItemCounter;
    menuInput->entriesPerPage = menuItemCounter;
    menuInput->currPage = 0;
    menuInput->unk4 = 0;

    if (window->type == WINDOW_TYPE_WITH_HEADER)
        menuInput->firstEntryY = 16;
    else
        menuInput->firstEntryY = 2;

    menuInput->leftRightArrowsPos.x = 0;
    menuInput->leftRightArrowsPos.y = 0;
    menuInput->unk14.x = 0;
    menuInput->unk24 = 0;
    sub_801317C(&menuInput->unk28);
}

// arm9.bin::0201BD28
void sub_801317C(MenuInputStructSub *param_1)
{
    param_1->unk0 = 0;
    param_1->a_button = 0;
    param_1->b_button = 0;
    param_1->dpad_left = 0;
    param_1->dpad_right = 0;
    param_1->unk8.x = -1;
    param_1->unk8.y = -1;
    nullsub_7(&param_1->unk8);
    ResetUnusedInputStruct();
}

// arm9.bin::0201BD18
void AddMenuCursorSprite(MenuInputStruct *menuInput)
{
    AddMenuCursorSprite_(menuInput, NULL);
}

// arm9.bin::0201B978
void AddMenuCursorSprite_(MenuInputStruct *menuInput, u8 *a1)
{
    struct SpriteOAM sp = {0};

    if (menuInput->unk1A > 0) {
        UpdateMenuCursorSpriteCoords(menuInput);

        if (!(menuInput->unk24 & 8)) {
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
            SpriteSetX(&sp, menuInput->cursorArrowPos.x);
            SpriteSetY(&sp, menuInput->cursorArrowPos.y + 1);

            AddSprite(&sp, 0xFF, 0, 0);
        }
    }

    ShowLeftRightArrows(menuInput);
    if (menuInput->unk14.x != 0)
        sub_801332C(&menuInput->unk14);

    menuInput->unk24++;

    // More here in NDS
}

void nullsub_34(MenuInputStructSub *a0, s32 a1)
{
}

// arm9.bin::0201B490
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

// arm9.bin::0201B1C0
static void ShowLeftRightArrows(MenuInputStruct *menuInput)
{
    struct SpriteOAM sp = {0};

    if (menuInput->leftRightArrowsPos.x != 0) {
        if (menuInput->currPage != 0) { // Left arrow
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
            SpriteSetX(&sp, menuInput->leftRightArrowsPos.x);
            SpriteSetY(&sp, menuInput->leftRightArrowsPos.y);

            AddSprite(&sp, 0xFF, NULL, NULL);
        }
        if (menuInput->unk20 != 0 && menuInput->unk20 != menuInput->currPage + 1) { // Right arrow
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
            SpriteSetX(&sp, menuInput->leftRightArrowsPos.x + 10);
            SpriteSetY(&sp, menuInput->leftRightArrowsPos.y);

            AddSprite(&sp, 0xFF, NULL, NULL);
        }
    }
}

void sub_8013660(MenuInputStruct *menuInput)
{
    if (0 < menuInput->unk1A) {
        UpdateMenuCursorSpriteCoords(menuInput);
        sub_801332C(&menuInput->cursorArrowPos);
    }
}

// arm9.bin::0201B14C
void UpdateMenuCursorSpriteCoords(MenuInputStruct *menuInput)
{
    Window *window = &gWindows[menuInput->windowId];
    menuInput->cursorArrowPos.x = window->x * 8 + menuInput->unk4;
    menuInput->cursorArrowPos.y = window->y * 8 + GetMenuEntryYCoord(menuInput, menuInput->menuIndex);
}

void MoveMenuCursorDown(MenuInputStruct *menuInput)
{
    menuInput->unk24 = 0;

    if (menuInput->unk1A < 1)
        menuInput->menuIndex = 0;
    else {
        menuInput->menuIndex++;

        if (menuInput->menuIndex >= menuInput->unk1A)
            menuInput->menuIndex = 0;
    }
}

void MoveMenuCursorDownWrapAround(MenuInputStruct *menuInput, u8 param_2)
{
    menuInput->unk24 = 0;

    if (menuInput->unk1A < 1)
        menuInput->menuIndex = 0;
    else {
        menuInput->menuIndex++;

        if (menuInput->menuIndex >= menuInput->unk1A) {
            if (param_2 != 0)
                menuInput->menuIndex = 0;
            else
                menuInput->menuIndex = menuInput->unk1A - 1;
        }
    }
}

void MoveMenuCursorUp(MenuInputStruct *menuInput)
{
    menuInput->unk24 = 0;

    if (menuInput->unk1A < 1)
        menuInput->menuIndex = 0;
    else {
        menuInput->menuIndex--;

        if (menuInput->menuIndex < 0)
            menuInput->menuIndex = menuInput->unk1A - 1;
    }
}

void MoveMenuCursorUpWrapAround(MenuInputStruct *menuInput, u8 param_2)
{
    menuInput->unk24 = 0;

    if (menuInput->unk1A < 1)
        menuInput->menuIndex = 0;
    else {
        menuInput->menuIndex--;

        if (menuInput->menuIndex < 0) {
            if (param_2 != 0)
                menuInput->menuIndex = menuInput->unk1A - 1;
            else
                menuInput->menuIndex = 0;
        }
    }
}

void sub_8013780(MenuInputStruct *menuInput, s32 param_2)
{
    if (param_2 < 0)
        menuInput->menuIndex = 0;
    else if (param_2 >= menuInput->unk1A)
        menuInput->menuIndex = menuInput->unk1A - 1;
    else
        menuInput->menuIndex = param_2;

    menuInput->unk24 = 0;
}

s32 sub_80137A8(MenuInputStruct *menuInput)
{
    return menuInput->menuIndex;
}

void sub_80137B0(MenuInputStruct *menuInput, s32 param_2)
{
    s32 iVar1;
    s32 iVar2;

    if (param_2 >= 1) {
        iVar2 = param_2 << 8;
    }
    else {
        if (gWindows[menuInput->windowId].type == WINDOW_TYPE_WITH_HEADER)
            iVar1 = 16;
        else
            iVar1 = 0;

        iVar2 = (gWindows[menuInput->windowId].height * 8 - iVar1) << 8;
    }

    menuInput->unk10 = iVar2 / menuInput->entriesPerPage;
}

void sub_80137F8(MenuInputStruct *menuInput, u32 param_2)
{
    menuInput->unk10 = param_2 << 8;
}

// arm9.bin::0201AF70
s32 GetMenuEntryYCoord(MenuInputStruct *menuInput, s32 entryId)
{
    s32 firstY = menuInput->firstEntryY;
    s32 iVar1 = entryId * menuInput->unk10;

    return firstY + (iVar1 / 256);
}

void CreateMenuOnWindow(MenuInputStruct *menuInput, s32 totalCount, u32 perPageCount, s32 windowId)
{
    menuInput->windowId = windowId;
    menuInput->totalEntriesCount = totalCount;
    menuInput->entriesPerPage = perPageCount;
    menuInput->unk14.x = 0;
    menuInput->unk24 = 0;
    menuInput->menuIndex = 0;
    menuInput->currPage = 0;

    sub_801317C(&menuInput->unk28);
    sub_8013984(menuInput);
    sub_80137F8(menuInput, 12);
}

void sub_8013848(MenuInputStruct *menuInput, s32 totalCount, u32 perPageCount, s32 windowId)
{
    menuInput->windowId = windowId;
    menuInput->totalEntriesCount = totalCount;
    menuInput->entriesPerPage = perPageCount;
    menuInput->unk14.x = 0;
    menuInput->unk24 = 0;
    menuInput->menuIndex = 0;
    menuInput->currPage = 0;

    sub_801317C(&menuInput->unk28);
    sub_8013984(menuInput);
    sub_80137F8(menuInput, 24);
}

void sub_8013878(MenuInputStruct *menuInput, s32 param_2)
{
    if (param_2 < 0)
        param_2 = 0;
    else if (param_2 >= menuInput->totalEntriesCount)
        param_2 = menuInput->totalEntriesCount - 1;

    menuInput->currPage = param_2 / menuInput->entriesPerPage;
    menuInput->menuIndex = param_2 % menuInput->entriesPerPage;
    menuInput->unk24 = 0;
    sub_8013984(menuInput);
}

bool8 sub_80138B8(MenuInputStruct *menuInput, bool8 param_2)
{
    s32 sVar1;
    s32 oldIndex;

    sVar1 = menuInput->currPage;
    oldIndex = menuInput->menuIndex;
    AddMenuCursorSprite(menuInput);

    if (param_2) {
        switch (GetKeyPress(menuInput)) {
            case INPUT_DPAD_UP:
                MoveMenuCursorUp(menuInput);
                if (oldIndex != menuInput->menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_DPAD_DOWN:
                MoveMenuCursorDown(menuInput);
                if (oldIndex != menuInput->menuIndex)
                    PlayMenuSoundEffect(3);
                break;
            case INPUT_DPAD_LEFT:
                MenuScrollLeft(menuInput);
                break;
            case INPUT_DPAD_RIGHT:
                MenuScrollRight(menuInput);
                break;
        }
    }

    if (sVar1 != menuInput->currPage) {
        PlayMenuSoundEffect(4);
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8013938(MenuInputStruct *menuInput)
{
    s32 sVar1;

    sVar1 = menuInput->currPage;
    menuInput->unk1A = 0;
    menuInput->unk14.x = 0;
    AddMenuCursorSprite(menuInput);

    switch (GetKeyPress(menuInput)) {
        case INPUT_DPAD_LEFT:
            MenuScrollLeft(menuInput);
            break;
        case INPUT_DPAD_RIGHT:
            MenuScrollRight(menuInput);
            break;
    }

    if (sVar1 != menuInput->currPage) {
        PlayMenuSoundEffect(4);
        return TRUE;
    }
    return FALSE;
}

void sub_8013984(MenuInputStruct *menuInput)
{
    s32 iVar2;
    Window *window;

    window = &gWindows[menuInput->windowId];

    if (menuInput->entriesPerPage == 0)
        menuInput->entriesPerPage++;

    menuInput->unk20 = menuInput->totalEntriesCount / menuInput->entriesPerPage;
    iVar2 = menuInput->totalEntriesCount % menuInput->entriesPerPage;
    if (iVar2 != 0)
        menuInput->unk20++;

    if (menuInput->currPage > menuInput->unk20 - 1)
        menuInput->currPage = menuInput->unk20 - 1;

    if (menuInput->currPage != menuInput->unk20 - 1 || menuInput->totalEntriesCount % menuInput->entriesPerPage == 0)
        menuInput->unk1A = menuInput->entriesPerPage;
    else
        menuInput->unk1A = menuInput->totalEntriesCount % menuInput->entriesPerPage;

    if (menuInput->menuIndex > menuInput->unk1A - 1)
        menuInput->menuIndex = menuInput->unk1A - 1;

    menuInput->unk4 = 0;

    if (window->type== WINDOW_TYPE_WITH_HEADER)
        menuInput->firstEntryY = 16;
    else
        menuInput->firstEntryY = 0;

    if (menuInput->unk20 < 2)
        menuInput->leftRightArrowsPos.x = 0;
    else
        menuInput->leftRightArrowsPos.x = (window->x + window->width - 2) * 8;

    menuInput->leftRightArrowsPos.y = (window->y + 1) * 8 - 2;
}

void MenuScrollRight(MenuInputStruct *menuInput)
{
    if (menuInput->currPage < menuInput->unk20 - 1)
        menuInput->currPage++;
    else
        menuInput->currPage = 0;

    sub_8013984(menuInput);
}

static void MenuScrollLeft(MenuInputStruct *menuInput)
{
    if (menuInput->currPage < 1)
        menuInput->currPage = menuInput->unk20 - 1;
    else
        menuInput->currPage--;

    sub_8013984(menuInput);
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

    switch (GetMenuInput()) {
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

        DrawCharOnWindowWidth12(a0->unk1C - ((i + 1) * 12), a0->unk20, ch, 7, a0->unk14);
    }

    for (i = 0; i < a0->unk10; i++)
        AddUnderScoreHighlight(a0->unk14, a0->unk1C - ((i + 1) * 12) - 1, a0->unk20 + 10, 11, 5);
}

void sub_8013D10(unkStructFor8013AA0 *a0)
{
    s32 x, y;
    u8 uVar4;
    Window *window;

    window = &gWindows[a0->unk14];
    uVar4 = a0->unk24;

    switch (GetMenuInput()) {
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

    x = (a0->unk1C - ((a0->unk24 + 1) * 12) + (window->x * 8)) - 3;
    SpriteSetX(&a0->unk28, x);

    y = a0->unk20 + (window->y * 8) - 7;
    SpriteSetY(&a0->unk28, y);
}

static bool8 sub_8013DD0(unkStructFor8013AA0 *a0)
{
    s32 iVar2;

    switch (GetMenuInput()) {
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
    Window *window = &gWindows[0];
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
    SpriteSetY(&SStack_18, (window->y * 8) + 0x80);
    SpriteSetX(&SStack_18, 112);

    AddSprite(&SStack_18,0x100,0,0x0);
}

void sub_8013F84(void)
{
    Window *window = &gWindows[0];
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
    SpriteSetY(&SStack_18, (window->y * 8) + 0x60);
    SpriteSetX(&SStack_18, 112);

    AddSprite(&SStack_18,0x100,0,0x0);
}

// arm9.bin::0201A100
void sub_80140B4(WindowTemplates *a0)
{
    s32 i;

    for (i = 0; i < 4; i++)
        a0->id[i] = gUnknown_80D47C8[i];
}
