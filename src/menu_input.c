#include "global.h"
#include "code_800558C.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "input.h"
#include "menu_input.h"
#include "sprite.h"
#include "text_util.h"
#include "text1.h"
#include "text2.h"
#include "util.h"

// data_80D47B8.s
extern const u8 gUnknown_80D4828[];
extern const s32 gUnknown_80D4830[9];

// text.s
extern s16 sub_8009614(u32, u32);

static void sub_8013134(MenuInputStruct *, u32, u32);
static void sub_801332C(s16 *);
static void sub_8013470(MenuInputStruct *);
static bool8 sub_8013DD0(unkStructFor8013AA0 *);

ALIGNED(4) static const char fill_save7[] = _("pksdir0");
const u32 gDefaultMenuTextColors[3] = { COLOR_WHITE_2, COLOR_RED, COLOR_RED };

u32 sub_8012A64(MenuInputStructSub *r0, s32 r1)
{
    if (r0 == NULL)
        return sub_8012AE8();

    if (r1 != -1)
        nullsub_34(r0);

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
    struct unkChar *iVar3;
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
    struct unkChar *iVar3;
    u32 uVar2;

    uVar2 = ReturnIntFromChar2(a2);
    iVar3 = GetCharacter(uVar2);

    if (iVar3->unk6 < 12)
        add_x = ((12 - iVar3->unk6) / 2);
    else
        add_x = 0;

    xxx_call_draw_char(x + add_x, y, uVar2, color, a4);
}

void sub_8012CAC(UnkTextStruct2 *a0, const MenuItem *a1)
{
    s16 length;
    int r5;
    int r6;
    int r7;
    s32 iVar4;
    #ifndef NONMATCHING
    register s32 r0 asm("r0");
    #else
    s32 r0;
    #endif
    
    r7 = 0;
    r6 = 0;

    if (a1->text != NULL) {
        r5 = 0x10000; // s16 memes?
        r0 = r5;
        do {
            r0 = r5;
            r5 = r5 + 0x10000;
            r7 = r0 >> 0x10;
            length = sub_8008ED0(a1->text);

            if (length > r6)
                r6 = length;

            a1++;
        } while (a1->text != NULL);
    }

    if (r6 < 0)
        iVar4 = r6 + 7;
    else
        iVar4 = r6;

    a0->unkC = (iVar4 >> 3) + 2;
    sub_8012D08(a0, r7);
}

NAKED // sub_80095E4 memes
void sub_8012D08(UnkTextStruct2 *a0, s32 a1)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tadds r0, r1, 0\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tldr r0, [r4, 0x4]\n"
	"\tcmp r0, 0x6\n"
	"\tbne _08012D24\n"
	"\tadds r0, r1, 0x2\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
"_08012D24:\n"
	"\tlsls r0, r1, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r4, 0xE]\n"
	"\tstrh r0, [r4, 0x10]\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}

// https://decomp.me/scratch/QadfW  (200 - 90% matched)  - Seth
NAKED
void sub_8012D34(UnkTextStruct2 *a0, s32 a1)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tadds r0, r1, 0\n"
	"\tmovs r1, 0x18\n"
	"\tbl sub_8009614\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tldr r0, [r4, 0x4]\n"
	"\tcmp r0, 0x6\n"
	"\tbne _08012D50\n"
	"\tadds r0, r1, 0x2\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
"_08012D50:\n"
	"\tlsls r0, r1, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r4, 0xE]\n"
	"\tstrh r0, [r4, 0x10]\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}

void sub_8012D60(MenuStruct *param_1, const MenuItem *menuItems, u32 *colorArray, u16 *param_4, s32 menuAction, s32 index)
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

void sub_8012E04(MenuStruct *param_1, const MenuItem *menuItems, u32 *colorArray, u16 *param_4, s32 menuAction, s32 index)
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
    UnkTextStruct2 textStack[4];
    u8 buffer[256];
    UnkTextStruct1 *ptr_text;
    UnkTextStruct2 *ptr_text2;

    if (param_1->unk4D) {
        sub_80073B8(param_1->index);
        index = param_1->index;
        ptr_text = &gUnknown_2027370[index];

        if (ptr_text->unkC == 6) {
            ptr_text2 = &textStack[index];
            sub_8006518(textStack);
            x = sub_8008ED0(param_1->unk0);
            xxx_format_and_draw(((ptr_text2->unk14[2] * 8 - x) / 2) + 8, 0, param_1->unk0, param_1->index, 0);
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
                y = sub_8013800(&param_1->input, counter);
                xxx_format_and_draw(8, y, buffer, param_1->index, 0);
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
        param_1->unk6 = 16;
    else
        param_1->unk6 = 2;

    param_1->unkC = 0;
    param_1->unkE = 0;
    param_1->unk14 = 0;
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

void AddMenuCursorSprite_(MenuInputStruct *a0, u32 a1)
{
    SpriteOAM sp = {};
    SpriteOAM* ptr;
    s32 value;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r5;

    if (a0->unk1A > 0) {
        UpdateMenuCursorSpriteCoords(a0);

        if (!(a0->unk24 & 8)) {
            #ifdef NONMATCHING // SpriteOAM memes https://decomp.me/scratch/T9aXl TODO: Match like sub_8039174 with multiple vars and while(0)
            u32 tmp, tmp2;
            #else
            register u32 tmp asm("r0"), tmp2 asm("r1");
            #endif

            tmp = sp.attrib1;
            sp.attrib1 = tmp & ~SPRITEOAM_MASK_AFFINEMODE1;
            sp.attrib1 = sp.attrib1;

            tmp2 = sp.attrib1;
            sp.attrib1 = tmp2 & ~SPRITEOAM_MASK_AFFINEMODE2;
            sp.attrib1 = sp.attrib1;

            tmp2 = sp.attrib1;
            sp.attrib1 = tmp2 & ~SPRITEOAM_MASK_OBJMODE;
            sp.attrib1 = sp.attrib1;

            tmp2 = sp.attrib1;
            sp.attrib1 = tmp2 & ~SPRITEOAM_MASK_MOSAIC;
            sp.attrib1 = sp.attrib1;

            tmp2 = sp.attrib1;
            sp.attrib1 = tmp2 & ~SPRITEOAM_MASK_BPP;
            sp.attrib1 = sp.attrib1;

            tmp2 = sp.attrib1;
            sp.attrib1 = tmp2 & ~SPRITEOAM_MASK_SHAPE;
            sp.attrib1 = sp.attrib1;

            ptr = &sp;

            r2 = 0x3F4 << SPRITEOAM_SHIFT_TILENUM;
            ptr->attrib3 &= ~SPRITEOAM_MASK_TILENUM;
            ptr->attrib3 |= r2;

            ptr->attrib3 &= ~SPRITEOAM_MASK_PRIORITY;

            r5 = (u16)~SPRITEOAM_MASK_UNK6_4;

            r1 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
            ptr->attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
            ptr->attrib3 |= r1;

            ptr->unk6 &= ~SPRITEOAM_MASK_UNK6_0;
            ptr->unk6 &= ~SPRITEOAM_MASK_UNK6_1;

            r0 = a0->unk8;
            r0 &= SPRITEOAM_MAX_X;
            ptr->attrib2 = r0;

            value = a0->unkA + 1;
            value &= SPRITEOAM_MAX_UNK6_4;
            value <<= SPRITEOAM_SHIFT_UNK6_4;
            ptr->unk6 &= r5;
            ptr->unk6 |= value;

            AddSprite(&sp, 0xFF, 0, 0);
        }
    }

    sub_8013470(a0);
    if (a0->unk14 != 0)
        sub_801332C(&a0->unk14);

    a0->unk24++;
}

void nullsub_34(MenuInputStructSub *a0)
{
}

// Maybe Position
static void sub_801332C(s16 *a0)
{
    SpriteOAM sp = {};
    SpriteOAM* ptr;
    #ifdef NONMATCHING // SpriteOAM memes https://decomp.me/scratch/zeLxS TODO: Match like sub_8039174 with multiple vars and while(0)
    u32 r0, r1, r2;
    #else
    register u32 r0 asm("r0");
    register u32 r1 asm("r1");
    register u32 r2 asm("r2");
    #endif
    u32 r3;
    u32 r5;
    u32 r6;

    r1 = sp.attrib1;
    sp.attrib1 = r1 & ~SPRITEOAM_MASK_AFFINEMODE1;
    sp.attrib1 = sp.attrib1;

    r2 = sp.attrib1;
    sp.attrib1 = r2 & ~SPRITEOAM_MASK_AFFINEMODE2;
    sp.attrib1 = sp.attrib1;

    r5 = 1 << SPRITEOAM_SHIFT_OBJMODE;
    r2 = sp.attrib1;
    sp.attrib1 = r2 & ~SPRITEOAM_MASK_OBJMODE;
    sp.attrib1 = sp.attrib1 | r5;

    r2 = sp.attrib1;
    sp.attrib1 = r2 & ~SPRITEOAM_MASK_MOSAIC;
    sp.attrib1 = sp.attrib1;

    r2 = sp.attrib1;
    sp.attrib1 = r2 & ~SPRITEOAM_MASK_BPP;
    sp.attrib1 = sp.attrib1;

    r2 = sp.attrib1;
    sp.attrib1 = r2 & ~SPRITEOAM_MASK_SHAPE;
    sp.attrib1 = sp.attrib1;

    ptr = &sp;

    r3 = 0x3F5 << SPRITEOAM_SHIFT_TILENUM;
    ptr->attrib3 &= ~SPRITEOAM_MASK_TILENUM;
    ptr->attrib3 |= r3;

    ptr->attrib3 &= ~SPRITEOAM_MASK_PRIORITY;

    r6 = (u16)~SPRITEOAM_MASK_UNK6_4;

    r2 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
    ptr->attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
    ptr->attrib3 |= r2;

    ptr->unk6 &= ~SPRITEOAM_MASK_UNK6_0;
    ptr->unk6 &= ~SPRITEOAM_MASK_UNK6_1;

    r1 = a0[0];
    r1 &= SPRITEOAM_MAX_X;
    ptr->attrib2 = r1;

    r0 = a0[1] + 1;
    r0 &= SPRITEOAM_MAX_UNK6_4;
    r0 <<= SPRITEOAM_SHIFT_UNK6_4;
    ptr->unk6 &= r6;
    ptr->unk6 |= r0;

    AddSprite(&sp, 0xFF, NULL, NULL);
}

static void sub_8013470(MenuInputStruct *a0)
{
    SpriteOAM sp = {};
    #if NONMATCHING // SpriteOAM memes https://decomp.me/scratch/70Ieb TODO: Match like sub_8039174 with multiple vars and while(0)
    SpriteOAM *ptr;
    u32 r0, r1, r5;
    #else
    register SpriteOAM *ptr asm("r3");
    register u32 r0 asm("r0");
    register u32 r1 asm("r1");
    register u32 r5 asm("r5");
    #endif
    u32 r2;

    if (a0->unkC != 0) {
        if (a0->unk1E != 0) {
            r0 = sp.attrib1;
            sp.attrib1 = r0 & ~SPRITEOAM_MASK_AFFINEMODE1;
            sp.attrib1 = sp.attrib1;

            r1 = sp.attrib1;
            sp.attrib1 = r1 & ~SPRITEOAM_MASK_AFFINEMODE2;
            sp.attrib1 = sp.attrib1;

            r1 = sp.attrib1;
            sp.attrib1 = r1 & (u16)~SPRITEOAM_MASK_OBJMODE;
            sp.attrib1 = sp.attrib1;

            r1 = sp.attrib1;
            sp.attrib1 = r1 & ~SPRITEOAM_MASK_MOSAIC;
            sp.attrib1 = sp.attrib1;

            r1 = sp.attrib1;
            sp.attrib1 = r1 & ~SPRITEOAM_MASK_BPP;
            sp.attrib1 = sp.attrib1;

            r1 = sp.attrib1;
            sp.attrib1 = r1 & ~SPRITEOAM_MASK_SHAPE;
            sp.attrib1 = sp.attrib1;

            ptr = &sp;

            r2 = 0x3F2 << SPRITEOAM_SHIFT_TILENUM;
            r1 = ptr->attrib3;
            r0 = r1 & (u16)~SPRITEOAM_MASK_TILENUM;
            r0 |= r2;
        
            r0 &= (u16)~SPRITEOAM_MASK_PRIORITY;

            r5 = (u16)~SPRITEOAM_MASK_UNK6_4;

            r1 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
            r0 &= (u16)~SPRITEOAM_MASK_PALETTENUM;
            r0 |= r1;
            ptr->attrib3 = r0;

            r0 = ptr->unk6;
            r1 = r0 & (u16)~SPRITEOAM_MASK_UNK6_0;
            r1 &= (u16)~SPRITEOAM_MASK_UNK6_1;

            r0 = a0->unkC;
            r0 &= SPRITEOAM_MAX_X;
            ptr->attrib2 = r0;

            r0 = a0->unkE;
            r0 &= SPRITEOAM_MAX_UNK6_4;
            r0 <<= SPRITEOAM_SHIFT_UNK6_4;
            r1 &= r5;
            r1 |= r0;
            ptr->unk6 = r1;

            AddSprite(&sp, 0xFF, NULL, NULL);
        }
        if (a0->unk20 != 0 && a0->unk20 != a0->unk1E + 1) {
            r0 = sp.attrib1;
            sp.attrib1 = r0 & ~SPRITEOAM_MASK_AFFINEMODE1;
            sp.attrib1 = sp.attrib1;

            sp.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2;
            sp.attrib1 = sp.attrib1;

            sp.attrib1 &= (u16)~SPRITEOAM_MASK_OBJMODE;
            sp.attrib1 = sp.attrib1;

            sp.attrib1 &= ~SPRITEOAM_MASK_MOSAIC;
            sp.attrib1 = sp.attrib1;

            sp.attrib1 &= ~SPRITEOAM_MASK_BPP;
            sp.attrib1 = sp.attrib1;

            sp.attrib1 &= ~SPRITEOAM_MASK_SHAPE;
            sp.attrib1 = sp.attrib1;

            ptr = &sp;

            r2 = 0x3F3 << SPRITEOAM_SHIFT_TILENUM;
            r1 = ptr->attrib3;
            r0 = r1 & (u16)~SPRITEOAM_MASK_TILENUM;
            r0 |= r2;
        
            r0 &= (u16)~SPRITEOAM_MASK_PRIORITY;

            r5 = (u16)~SPRITEOAM_MASK_UNK6_4;

            r1 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
            r0 &= (u16)~SPRITEOAM_MASK_PALETTENUM;
            r0 |= r1;
            ptr->attrib3 = r0;

            r0 = ptr->unk6;
            r1 = r0 & (u16)~SPRITEOAM_MASK_UNK6_0;
            r1 &= (u16)~SPRITEOAM_MASK_UNK6_1;

            r0 = a0->unkC + 10;
            r0 &= SPRITEOAM_MAX_X;
            ptr->attrib2 = r0;

            r0 = a0->unkE;
            r0 &= SPRITEOAM_MAX_UNK6_4;
            r0 <<= SPRITEOAM_SHIFT_UNK6_4;
            r1 &= r5;
            r1 |= r0;
            ptr->unk6 = r1;

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
    param_1->unk8 = temp->unk0 * 8 + param_1->unk4;
    param_1->unkA = temp->unk2 * 8 + sub_8013800(param_1, param_1->menuIndex);
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
#ifndef NONMATCHING
    register s32 iVar2 asm("r0");
#else
    s32 iVar2;
#endif

    if (param_2 >= 1)
        iVar2 = param_2 << 8;
    else {
        if (gUnknown_2027370[param_1->unk0].unkC == 6)
            iVar1 = 16;
        else
            iVar1 = 0;

        iVar2 = gUnknown_2027370[param_1->unk0].unk6 * 8 - iVar1;
        iVar2 <<= 8;
    }

    param_1->unk10 = iVar2 / param_1->unk1C;
}

void sub_80137F8(MenuInputStruct *param_1, u32 param_2)
{
    param_1->unk10 = param_2 << 8;
}

s32 sub_8013800(MenuInputStruct *param_1, s32 param_2)
{
    s32 iVar1;
    s32 iVar2;

    iVar2 = param_1->unk6;
    iVar1 = param_2 * param_1->unk10;
    if (iVar1 < 0)
        iVar1 = iVar1 + 0xff;

    return iVar2 + (iVar1 >> 8);
}

void sub_8013818(MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4)
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
    sub_80137F8(param_1, 12);
}

void sub_8013848(MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4)
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
    param_1->unk14 = 0;
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
        param_1->unk6 = 16;
    else
        param_1->unk6 = 0;

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
    s32 r1;
    s32 test;
    s32 r3;
    s32 r4;
    s32 test2;
    s16 earlyF;
    s32 sp[10];

    a0->unk28.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1;
    a0->unk28.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2;
    a0->unk28.attrib1 &= ~SPRITEOAM_MASK_OBJMODE;
    a0->unk28.attrib1 &= ~SPRITEOAM_MASK_MOSAIC;
    a0->unk28.attrib1 &= ~SPRITEOAM_MASK_BPP;

    r1 = 1 << SPRITEOAM_SHIFT_SHAPE;
    a0->unk28.attrib1 &= ~SPRITEOAM_MASK_SHAPE;
    a0->unk28.attrib1 |= r1;

    test = 16 << SPRITEOAM_SHIFT_MATRIXNUM;
    a0->unk28.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;
    a0->unk28.attrib2 |= test;

    a0->unk28.attrib2 &= ~SPRITEOAM_MASK_SIZE;

    r3 = 0x3F0 << SPRITEOAM_SHIFT_TILENUM;
    a0->unk28.attrib3 &= ~SPRITEOAM_MASK_TILENUM;
    a0->unk28.attrib3 |= r3;

    a0->unk28.attrib3 &= ~SPRITEOAM_MASK_PRIORITY;

    earlyF = (s16)~SPRITEOAM_MASK_UNK6_4;

    r4 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
    a0->unk28.attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
    a0->unk28.attrib3 |= r4;

    a0->unk28.attrib2 &= ~SPRITEOAM_MASK_X;
    a0->unk28.attrib2 |= DISPLAY_WIDTH;

    test2 = DISPLAY_WIDTH << SPRITEOAM_SHIFT_UNK6_4;
    a0->unk28.unk6 &= earlyF;
    a0->unk28.unk6 |= test2;

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
        {
            s32 temp = 16 << SPRITEOAM_SHIFT_MATRIXNUM;
            a0->unk28.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;
            a0->unk28.attrib2 |= temp;
        }
        AddSprite(&a0->unk28, 0x100, NULL, NULL);
    
        a0->unk28.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;
        {
            u32 temp = a0->unk28.unk6;
            s32 max = SPRITEOAM_MAX_UNK6_4;
            temp >>= SPRITEOAM_SHIFT_UNK6_4;
            temp += 16;
            temp &= max;
            temp <<= SPRITEOAM_SHIFT_UNK6_4;
            a0->unk28.unk6 &= ~SPRITEOAM_MASK_UNK6_4;
            a0->unk28.unk6 |= temp;
        }
        AddSprite(&a0->unk28, 0x100, NULL, NULL);
    }

    if (sub_8013DD0(a0))
        return 1;

    switch (sub_8012AE8()) {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
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
    u8 uVar4;
    UnkTextStruct1 *ptr;

    ptr = &gUnknown_2027370[a0->unk14];
    uVar4 = a0->unk24;

    switch (sub_8012AE8()) {
        case 9:
            uVar4 = a0->unk24 < a0->unk25 - 1 ? a0->unk24 + 1 : 0;
            break;
        case 10:
            uVar4 = a0->unk24 == 0 ? a0->unk25 - 1 : a0->unk24 - 1;
            break;
    }

    if (uVar4 != a0->unk24) {
        a0->unk24 = uVar4;
        PlayMenuSoundEffect(3);
        a0->unk26 = 8;
    }

    {
        s32 temp = (a0->unk1C - ((a0->unk24 + 1) * 12) + (ptr->unk0 * 8)) - 3;
        temp &= SPRITEOAM_MAX_X;
        temp <<= SPRITEOAM_SHIFT_X;
        a0->unk28.attrib2 &= ~SPRITEOAM_MASK_X;
        a0->unk28.attrib2 |= temp;
    } while (0);

    {
        s32 temp = a0->unk20 + (ptr->unk2 * 8) - 7;
        temp &= SPRITEOAM_MAX_UNK6_4;
        temp <<= SPRITEOAM_SHIFT_UNK6_4;
        a0->unk28.unk6 &= ~SPRITEOAM_MASK_UNK6_4;
        a0->unk28.unk6 |= temp;
    } while (0);
}

static bool8 sub_8013DD0(unkStructFor8013AA0 *a0)
{
    s32 iVar2;

    switch (sub_8012AE8()) {
        case 7:
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
        case 8:
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