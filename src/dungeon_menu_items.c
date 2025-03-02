#include "global.h"
#include "globaldata.h"
#include "dungeon_menu_items.h"
#include "dungeon_menu_team.h"
#include "structs/str_dungeon.h"
#include "input.h"
#include "structs/map.h"
#include "dungeon_main.h"
#include "dungeon_message.h"
#include "dungeon_action.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "items.h"
#include "dungeon_music.h"
#include "dungeon_ai_movement.h"
#include "code_8045A00.h"
#include "string_format.h"
#include "code_803E46C.h"
#include "trap.h"
#include "dungeon_map_access.h"
#include "status_checks_1.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "tile_types.h"
#include "menu_input.h"
#include "text.h"
#include "code_8044CC8.h"
#include "code_801B3C0.h"
#include "dungeon_capabilities.h"

extern void PlayDungeonStartButtonSE(void);
extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);
extern void sub_806A2BC(Entity *a0, u8 a1);
extern void SetLeaderActionToNothing(u8 a0);
extern void sub_803E708(s32 a0, s32 a1);
extern void sub_8047158(void);
extern Item *sub_8044D90(Entity *, s32, u32);
extern bool8 sub_8070F14(Entity * pokemon, s32 direction);
bool8 sub_805EC2C(Entity *a0, s32 x, s32 y);
extern Entity *sub_80696A8(Entity *a0);
extern u8 sub_806A538(s32);
extern void sub_803EAF0(u32, u8 *);
extern void sub_803F508(Entity *);
extern void sub_8041AD0(Entity *pokemon);
extern void sub_8041AE0(Entity *pokemon);
extern void sub_807EC28(bool8);
extern void PlayDungeonCursorSE(u8 param_1);
extern u8 *GetDungeonSubMenuItemString(s32 param_1);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern s32 gDungeonSubMenuItemsCount;
extern const u8 gUnknown_8106B50[];
extern void DungeonShowWindows(Windows *a0, u8 a1);
extern Item * sub_8044CC8(Entity *param_1, ActionParameter *param_2, UNUSED s32 a3);
extern void sub_8044F5C(u16 param_1, u8 param_2);
extern void sub_8044FF0(u16 param_1);
extern u16 sub_8044DC8(Item *param_1);
extern bool8 sub_8046F00(Item *item);
extern void sub_8045064(void);
extern bool8 PosHasItem(DungeonPos *pos);

extern u8 gUnknown_202EE00;
extern Entity *gLeaderPointer;

extern MenuInputStruct gDungeonMenu;

extern const u8 *gUnknown_80F8B24;
extern const u8 *gTeamToolboxAPtr;
extern const u8 *gTeamToolboxBPtr;
extern const u8 *gFieldItemMenuGroundTextPtr;
extern const u8 *gUnknown_80FE940;
extern const u8 *gWhichTextPtr1;

static EWRAM_DATA ActionParameter sUnknownActionUnk4 = {0};
static EWRAM_DATA s32 sUnknown_202F240 = 0;
static UNUSED EWRAM_DATA u8 sUnused[4] = {0};
static EWRAM_DATA s16 sUnknown_202F248[8] = {0};
static EWRAM_DATA s32 sUnknown_202F258 = 0;

static void PrintOnDungeonItemsMenu(s32 a0, Entity *a1, bool8 a2, bool8 a3, Windows *a4, WindowHeader *a5);
static s32 sub_8060800(WindowHeader *a0, s32 a1);
static bool8 sub_8060860(s32 a0);
static void sub_8060890(DungeonPos *a0);
static void sub_8060900(Entity *a0);
static void ChosenSubMenuToAction(ActionContainer *a0);
static s32 sub_8060D64(s16 *a0, bool8 a1, bool8 a2, bool8 a3, Entity *a4);

bool8 sub_805FD3C(struct UnkMenuBitsStruct *a0)
{
    u16 action = GetLeaderActionId();

    a0->a0_8 = 0;
    a0->a0_16 = 0;
    a0->a0_24 = 0;
    a0->a0_32 = 0;
    if (action == 0xA) {
        a0->a0_8 = 1;
        a0->a0_32 = 1;
    }
    if (action == 0x3E) {
        a0->a0_8 = 1;
        a0->a0_16 = 0;
        a0->a0_32 = 1;
    }
    return a0->a0_8;
}

bool8 ShowDungeonItemsMenu(Entity * a0, struct UnkMenuBitsStruct *a1)
{
    s32 i, i_r6;
    s32 r8;
    s32 r9 = 0;

    u8 var_34 = 1;
    u8 var_30 = 0;
    u8 var_2C = 0;
    u8 var_28 = 0;
    EntityInfo *a0Info = GetEntInfo(a0);
    WindowHeader header;

    Windows windows =
    {
        .id =
        {
            [0] =
            {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 0x12,
                .height = 0x10,
                .unk10 = 0x10,
                .unk14 = &header,
            },
            WINDOW_DUMMY, WINDOW_DUMMY, WINDOW_DUMMY
        },
    };

    sUnknownActionUnk4.actionUseIndex = 0;
    sUnknownActionUnk4.itemPos.x = 0;
    sUnknownActionUnk4.itemPos.y = 0;
    if (a1 != NULL) {
        var_2C = (a1->a0_8 != 0);
        var_34 = (a1->a0_16 != 0);
        var_30 = (a1->a0_24 != 0);
        var_28 = (a1->a0_32 != 0);
    }

    sUnknown_202F258 = sub_8060D64(sUnknown_202F248, var_30, var_34, var_28, a0);
    if (sUnknown_202F258 == 0) {
        DisplayDungeonMessage(0, gUnknown_80F8B24, 1);
        return TRUE;
    }

    r8 = 0;
    sUnknown_202F240 = 0;
    while (1)
    {
        s32 id;
        Entity *r4;

        r9 = 0;
        for (i = 0; i < INVENTORY_SIZE; i++) {
            Item *item = &gTeamInventoryRef->teamItems[i];
            if (item->flags & ITEM_FLAG_EXISTS && item->flags & ITEM_FLAG_UNPAID) {
                item->flags &= ~(ITEM_FLAG_UNPAID);
                r8 = i / 10;
                sUnknown_202F240 = i % 10;
            }
        }
        for (i_r6 = 0; i_r6 < MAX_TEAM_MEMBERS; i_r6++) {
            Entity *teamMon = gDungeon->teamPokemon[i_r6];
            if (EntityIsValid(teamMon)) {
                EntityInfo *monInfo = GetEntInfo(teamMon);
                if (monInfo->heldItem.flags & ITEM_FLAG_EXISTS && monInfo->heldItem.flags & ITEM_FLAG_UNPAID) {
                    monInfo->heldItem.flags &= ~(ITEM_FLAG_UNPAID);
                    for (i = 0; i < sUnknown_202F258; i++) {
                        if (sUnknown_202F248[i] == i_r6 + 4) {
                            r8 = i;
                            break;
                        }
                    }
                    sUnknown_202F240 = 0;
                }
            }
        }
        PrintOnDungeonItemsMenu(r8, a0, var_2C, var_30, &windows, &header);

        id = sUnknown_202F248[gDungeonMenu.unk1E];
        if (id >= MAX_TEAM_MEMBERS) {
            r4 = gDungeon->teamPokemon[id - MAX_TEAM_MEMBERS];
        }
        else {
            r4 = a0;
        }
        sub_806A2BC(r4, 0);
        ChangeDungeonCameraPos(&r4->pos, 0, 1, 1);

        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x14);
            if (!var_30) {
                if (sUnknown_202F258 > 1) {
                    if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
                        PlayDungeonCursorSE(0);
                        if (--r8 < 0) {
                            r8 = sUnknown_202F258 - 1;
                        }
                        sUnknown_202F240 = var_30;
                        break;
                    }
                    if ((gRealInputs.pressed & DPAD_RIGHT) || gDungeonMenu.unk28.dpad_right) {
                        PlayDungeonCursorSE(0);
                        if (++r8 == sUnknown_202F258) {
                            r8 = 0;
                        }
                        sUnknown_202F240 = var_30;
                        break;
                    }
                }
                if (gRealInputs.repeated & DPAD_DOWN && sub_8060860(r8)) {
                    PlayDungeonCursorSE(1);
                    MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
                }
                if (gRealInputs.repeated & DPAD_UP && sub_8060860(r8)) {
                    PlayDungeonCursorSE(1);
                    MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
                }
                if (gRealInputs.pressed & SELECT_BUTTON && sUnknown_202F248[r8] <= 1) {
                    s32 r3;
                    bool32 r7 = TRUE;
                    s16 arr[10];

                    PlaySoundEffect(0x132);
                    sub_8047158();
                    ConvertMoneyItemToMoney();
                    sUnknown_202F240 = 0;
                    r3 = sub_8060D64(arr, var_30, var_34, var_28, a0);
                    if (sUnknown_202F258 == r3) {
                        for (i_r6 = 0; i_r6 < r3; i_r6++) {
                            if (arr[i_r6] != sUnknown_202F248[i_r6]) {
                                break;
                            }
                        }
                        if (i_r6 == r3) {
                            r7 = FALSE;
                        }
                    }
                    if (r7) {
                        r8 = 0;
                        sUnknown_202F240 = 0;
                        sUnknown_202F258 = r3;
                        for (i_r6 = 0; i_r6 < sUnknown_202F258; i_r6++) {
                            sUnknown_202F248[i_r6] = arr[i_r6];
                        }
                    }
                    break;
                }
                if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                    PlayDungeonConfirmationSE();
                    sub_8060890(&a0->pos);
                    r9 = 1;
                    break;
                }
                if (gRealInputs.pressed & START_BUTTON) {
                    PlayDungeonStartButtonSE();
                    sub_8060890(&a0->pos);
                    r9 = 3;
                    break;
                }
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                    PlayDungeonCancelSE();
                    r9 = 2;
                    break;
                }
            }
            else {
                sub_8060890(&a0->pos);
                r9 = 1;
                break;
            }
        }
        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x14);
        if (sUnknown_202F248[gDungeonMenu.unk1E] <= 1 && !(gTeamInventoryRef->teamItems[0].flags & ITEM_FLAG_EXISTS)) {
            r9 = 2;
        }

        if (r9 == 2) {
            sub_803EAF0(0, NULL);
            r9 = 1;
            break;
        }
        else if (r9 == 0) {
            continue;
        }
        else if (r9 == 3) {
            SetMonsterActionFields(&a0Info->action, 0xC);
            a0Info->action.actionParameters[0] = sUnknownActionUnk4;
            sub_803EAF0(0, NULL);
            r9 = 0;
            break;
        }
        else {
            sUnknown_202F240 = gDungeonMenu.menuIndex;
            if (var_2C != 0) {
                a0Info->action.actionParameters[1] = sUnknownActionUnk4;
                sub_803EAF0(0, NULL);
                r9 = 0;
                break;
            }

            sub_8060900(a0);
            sub_8060800(&header, gDungeonMenu.unk1E);
            CreateDungeonMenuSubWindow(&windows.id[0], 0x16);
            while (1) {
                AddMenuCursorSprite(&gDungeonMenu);
                DungeonRunFrameActions(0x14);
                if (gRealInputs.repeated & DPAD_DOWN) {
                    PlayDungeonCursorSE(1);
                    MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    PlayDungeonCursorSE(1);
                    MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
                }
                if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                    if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                        PlayDungeonConfirmationSE();
                        ChosenSubMenuToAction(&a0Info->action);
                        r9 = 0;
                        break;
                    }
                    PlayDungeonCancelSE();
                }
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                    PlayDungeonCancelSE();
                    r9 = 1;
                    break;
                }
            }
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x14);
            gDungeon->unk181e8.unk18212 = 0;
            if (r9 != 1 || var_30 != 0) {
                if (a0Info->action.action == 0x37 || a0Info->action.action == 0x38 || a0Info->action.action == 0x3E) {
                    // Hm...
                    int newAction = sUnknownActionUnk4.actionUseIndex - 0x90;
                    a0Info->action.actionParameters[0].actionUseIndex = newAction;
                    sub_803EAF0(0, 0);
                    r9 = 0;
                    break;
                }
                else if (a0Info->action.action == ACTION_GIVE_ITEM) {
                    s32 teamId;
                    if (ShowDungeonToWhichMonMenu(&teamId, WHICH_MENU_ITEMS) != NULL) {
                        a0Info->action.actionParameters[1].actionUseIndex = teamId;
                        sub_803EAF0(0, 0);
                        r9 = 0;
                        break;
                    }
                    sub_803EAF0(0, NULL);
                    SetLeaderActionToNothing(1);
                }
                else {
                    sub_803EAF0(0, 0);
                    r9 = 0;
                    break;
                }
            }
        }
    }

    gDungeon->unk181e8.unk18212 = 0;
    sub_803E708(2, 0x61);
    sub_804AA60();
    sub_803E708(2, 0x61);
    return r9;
}

static const struct unkStruct_8090F58 gUnknown_8106B60 = {1, 1, 0, 80, 1};

static void PrintOnDungeonItemsMenu(s32 a0, Entity *a1, bool8 showWhichWindow, bool8 a3, Windows *windows, WindowHeader *a5)
{
    s32 i, x, y;
    s32 r10;
    UnkTextStruct1 *txtStrPtr;
    Window whichWindow = {
        .type = WINDOW_TYPE_NORMAL,
        .pos = {2, 4},
        .width = 6,
        .height = 2,
        .unk10 = 2,
        .unk12 = 0,
        .unk14 = NULL,
    };
    u8 txtBuff[80];
    EntityInfo *a1Info;

    a1Info = GetEntInfo(a1);
    r10 = sub_8060800(a5, a0);
    gDungeonMenu.menuIndex = sUnknown_202F240;
    gDungeonMenu.unk1A = 0;
    gDungeonMenu.unk1E = a0;
    gDungeonMenu.unk20 = sUnknown_202F258;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.unk0 = 0;
    gDungeonMenu.unk14.x = 0;
    sub_801317C(&gDungeonMenu.unk28);
    gDungeon->unk181e8.unk18212 = 0;
    switch (sUnknown_202F248[a0]) {
        case 0:
        case 1:
            windows->id[0].unk10 = 0x10;
            windows->id[0].height = 0x10;
            a5->f2 = 0xC;
            gDungeonMenu.firstEntryY = 0x10;
            gDungeonMenu.unk1C = 0xA;
            gDungeon->unk181e8.unk18212 = 1;
            break;
        case 2:
            windows->id[0].unk10 = 4;
            windows->id[0].height = 4;
            a5->f2 = 6;
            gDungeonMenu.firstEntryY = 0x12;
            gDungeonMenu.unk1C = 1;
            break;
        case 3:
        default:
            windows->id[0].unk10 = 4;
            windows->id[0].height = 4;
            a5->f2 = 0xC;
            gDungeonMenu.firstEntryY = 0x12;
            gDungeonMenu.unk1C = 1;
            break;
    }

    if (showWhichWindow) {
        gDungeonMenu.unkC += 0x40;
        windows->id[0].pos.x = 0xA;
        windows->id[1] = whichWindow;
    }
    else {
        windows->id[0].pos.x = 2;
        windows->id[1] = windows->id[3];
    }

    DungeonShowWindows(windows, 1);
    txtStrPtr = &gUnknown_2027370[0];
    gDungeonMenu.unkC = (txtStrPtr->unk0 + 0x10) * 8;
    gDungeonMenu.unkE = ((txtStrPtr->unk2 + 1) * 8) - 2;
    sub_80137B0(&gDungeonMenu, 0x70);
    sub_80073B8(0);
    x = ((a0 - r10) * 8) + 0xC;
    switch (sUnknown_202F248[a0])
    {
    case 0:
        PrintFormattedStringOnWindow(x, 0, gTeamToolboxAPtr, 0, 0);
        for (i = 0; i < 10; i++) {
            if (ItemExists(&gTeamInventoryRef->teamItems[i])) {
                gDungeonMenu.unk1A++;
                sub_8090E14(txtBuff, &gTeamInventoryRef->teamItems[i], &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gDungeonMenu, i);
                PrintFormattedStringOnWindow(8, y, txtBuff, 0, 0);
            }
            else {
                break;
            }
        }
        break;
    case 1:
        PrintFormattedStringOnWindow(x, 0, gTeamToolboxBPtr, 0, 0);
        for (i = 0; i < 10; i++) {
            if (ItemExists(&gTeamInventoryRef->teamItems[i + 10])) {
                gDungeonMenu.unk1A++;
                sub_8090E14(txtBuff, &gTeamInventoryRef->teamItems[i + 10], &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gDungeonMenu, i);
                PrintFormattedStringOnWindow(8, y, txtBuff, 0, 0);
            }
            else {
                break;
            }
        }
        break;
    case 2: {
            const Tile *tile = GetTile(a1->pos.x, a1->pos.y);
            Item *item = GetItemData(tile->object);
            PrintFormattedStringOnWindow(x, 0, gFieldItemMenuGroundTextPtr, 0, 0);
            if (item->flags & ITEM_FLAG_EXISTS) {
                gDungeonMenu.unk1A++;
                sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gDungeonMenu, 0);
                PrintFormattedStringOnWindow(8, y, txtBuff, 0, 0);
            }
            if (a3) {
                gDungeonMenu.unk8.x = gDungeonMenu.unk8.y = 0;
            }
        }
        break;
    case 3: {
            Item *item = &GetEntInfo(a1)->heldItem;
            SetMessageArgument_2(gFormatBuffer_Monsters[0], a1Info, 0);
            PrintFormattedStringOnWindow(x, 0, gUnknown_80FE940, 0, 0);
            if (item->flags & ITEM_FLAG_EXISTS) {
                gDungeonMenu.unk1A++;
                sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gDungeonMenu, 0);
                PrintFormattedStringOnWindow(8, y, txtBuff, 0, 0);
            }
        }
        break;
    default: {
            Entity *chosenTeamMember = gDungeon->teamPokemon[sUnknown_202F248[a0] - MAX_TEAM_MEMBERS];
            if (EntityIsValid(chosenTeamMember)) {
                EntityInfo *monInfo = GetEntInfo(chosenTeamMember);
                Item *item = &monInfo->heldItem;
                SetMessageArgument_2(gFormatBuffer_Monsters[0], monInfo, 0);
                PrintFormattedStringOnWindow(x, 0, gUnknown_80FE940, 0, 0);
                if (item->flags & ITEM_FLAG_EXISTS) {
                    gDungeonMenu.unk1A++;
                    sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                    y = GetMenuEntryYCoord(&gDungeonMenu, 0);
                    PrintFormattedStringOnWindow(8, y, txtBuff, 0, 0);
                }
            }
        }
        break;
    }

    if (gDungeonMenu.menuIndex >= gDungeonMenu.unk1A) {
        gDungeonMenu.menuIndex = 0;
    }
    sub_80073E0(0);
    if (showWhichWindow) {
        sub_80073B8(1);
        PrintFormattedStringOnWindow(4, 2, gWhichTextPtr1, 1, 0);
        sub_80073E0(1);
    }
}

static s32 sub_8060800(WindowHeader *a0, s32 a1)
{
    s32 i, r1, r2, r3;

    r1 = 0;
    for (i = 0; i < sUnknown_202F258; i++) {
        if (sUnknown_202F248[i] <= 1) {
            r1++;
        }
    }

    if (sUnknown_202F248[a1] <= 1) {
        r3 = a1;
        r2 = r1;
        r1 = 0;
    }
    else {
        r3 = a1 - r1;
        r2 = sUnknown_202F258 - r1;
    }

    if (a0 != NULL) {
        a0->f0 = r2;
        a0->f1 = r3;
        a0->f3 = 0;
    }

    return r1;
}

static bool8 sub_8060860(s32 a0)
{
    if (gDungeonMenu.unk1A <= 1 || sUnknown_202F248[a0] > 1)
        return FALSE;
    else
        return TRUE;
}

static void sub_8060890(DungeonPos *a0)
{
    s32 var = sUnknown_202F248[gDungeonMenu.unk1E];
    switch (var)
    {
    case 0:
        sUnknownActionUnk4.actionUseIndex = gDungeonMenu.menuIndex + 1;
        break;
    case 1:
        sUnknownActionUnk4.actionUseIndex = gDungeonMenu.menuIndex + 11;
        break;
    case 2:
        sUnknownActionUnk4.actionUseIndex = 128;
        break;
    default:
        sUnknownActionUnk4.actionUseIndex = var - 116;
        break;
    }

    sUnknownActionUnk4.itemPos.x = a0->x;
    sUnknownActionUnk4.itemPos.y = a0->y;
}

static void sub_8060900(Entity *a0)
{
    u16 val_sub8044DC8;
    Item *item = sub_8044CC8(a0, &sUnknownActionUnk4, 0xA);
    EntityInfo *a0Info = GetEntInfo(a0);

    gDungeonSubMenuItemsCount = 0;
    if (sUnknownActionUnk4.actionUseIndex < 144) {
        if (sUnknownActionUnk4.actionUseIndex == 128) {
            sub_8044F5C(9, item->id);
            if (GetItemCategory(item->id) != CATEGORY_POKE) {
                bool32 r2 = 0;
                if (gDungeon->unk644.unk17 != 0) {
                    if (gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags & ITEM_FLAG_EXISTS) {
                        r2 = TRUE;
                    }
                }
                else if (a0Info->heldItem.flags & ITEM_FLAG_EXISTS) {
                    r2 = TRUE;
                }

                if (r2) {
                    sub_8044FF0(9);
                }
            }
        }
        if (sUnknownActionUnk4.actionUseIndex == 128 && gDungeon->unk644.unk17 != 0) {
            sub_8044F5C(10, item->id);
        }
        val_sub8044DC8 = sub_8044DC8(item);
        if (val_sub8044DC8 != 0) {
            sub_8044F5C(val_sub8044DC8, item->id);
            if (item->flags & ITEM_FLAG_STICKY) {
                sub_8044FF0(val_sub8044DC8);
            }
            if (!sub_8046F00(item)) {
                sub_8044FF0(val_sub8044DC8);
            }
        }

        if (sUnknownActionUnk4.actionUseIndex <= 20
            && (GetItemCategory(item->id) == CATEGORY_THROWN_LINE || GetItemCategory(item->id) == CATEGORY_THROWN_ARC))
        {
            s32 i;

            if (ItemSet(item)) {
                sub_8044F5C(0x3D, item->id);
            }
            else {
                sub_8044F5C(0x3C, item->id);
            }

            for (i = 0; i < INVENTORY_SIZE; i++) {
                if (ItemExists(&gTeamInventoryRef->teamItems[i])
                    && ItemSet(&gTeamInventoryRef->teamItems[i])
                    && ItemSticky(&gTeamInventoryRef->teamItems[i]))
                {
                    sub_8044FF0(0x3C);
                    sub_8044FF0(0x3D);
                    break;
                }
            }
        }

        if (sUnknownActionUnk4.actionUseIndex != 129) {
            if (sUnknownActionUnk4.actionUseIndex != 128) {
                s32 i;
                bool32 r8 = FALSE;

                sub_8044F5C(0x36, item->id);
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (EntityIsValid(teamMon)) {
                        EntityInfo *teamMonInfo = GetEntInfo(teamMon);
                        teamMonInfo->unk157 = FALSE;
                        if (!CheckVariousConditions(teamMon)) {
                            r8 = TRUE;
                            teamMonInfo->unk157 = TRUE;
                        }
                    }
                }
                if (!r8) {
                    sub_8044FF0(0x36);
                }
            }
        }
        else if (gDungeon->unk644.unk17) {
            if (gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags & ITEM_FLAG_EXISTS) {
                sub_8044F5C(0x3E, item->id);
            }
            else {
                sub_8044F5C(0x37, item->id);
            }

            if (CheckVariousConditions(a0)) {
                sub_8044FF0(0x37);
                sub_8044FF0(0x3E);
            }
        }

        if (sUnknownActionUnk4.actionUseIndex <= 20) {
            Entity *tileEntity = GetTile(a0->pos.x, a0->pos.y)->object;
            if (tileEntity == NULL) {
                sub_8044F5C(8, item->id);
            }
            else if (GetEntityType(tileEntity) == ENTITY_ITEM) {
                sub_8044F5C(0x3A, item->id);
            }
        }

        if (GetItemCategory(item->id) == CATEGORY_THROWN_LINE) {
            sub_8044F5C(0x27, item->id);
        }
        else if (GetItemCategory(item->id) == CATEGORY_THROWN_ARC) {
            sub_8044F5C(0x41, item->id);
        }
        else {
            sub_8044F5C(0xB, item->id);
        }

        if (!MonsterCanThrowItems(a0Info)) {
            sub_8044FF0(0x27);
            sub_8044FF0(0x41);
            sub_8044FF0(0xB);
        }
    }
    else {
        s32 index = sUnknownActionUnk4.actionUseIndex - 144;
        Entity *teamMon = gDungeon->teamPokemon[index];
        if (EntityIsValid(teamMon)) {
            bool32 r5, r6, r4;
            EntityInfo *teamMonInfo = GetEntInfo(teamMon);

            r5 = FALSE;
            if (CheckVariousConditions(teamMon))
                r6 = TRUE;
            else
                r6 = FALSE;

            if (gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags & ITEM_FLAG_EXISTS)
                r4 = TRUE;
            else
                r4 = FALSE;

            if (GetItemCategory(item->id) == CATEGORY_TMS_HMS) r5 = TRUE;
            if (GetItemCategory(item->id) == CATEGORY_ORBS) r5 = TRUE;

            if (gDungeon->unk644.unk17) {
                if (r4) {
                    sub_8044F5C(0x3E, item->id);
                }
                else {
                    sub_8044F5C(0x37, item->id);
                }

                if (r6) {
                    sub_8044FF0(0x37);
                    sub_8044FF0(0x3E);
                }
            }

            if (teamMonInfo->isTeamLeader) {
                val_sub8044DC8 = sub_8044DC8(item);
                if (val_sub8044DC8 != 0) {
                    sub_8044F5C(val_sub8044DC8, item->id);
                    if (item->flags & ITEM_FLAG_STICKY) {
                        sub_8044FF0(val_sub8044DC8);
                    }
                    if (!sub_8046F00(item)) {
                        sub_8044FF0(val_sub8044DC8);
                    }
                }
            }
            else {
                sub_8044F5C(0x38, item->id);
                if (r5) {
                    sub_8044FF0(0x38);
                }
            }
        }
    }

    sub_8044F5C(0xC, item->id);
    sub_8045064();
}

static void ChosenSubMenuToAction(ActionContainer *a0)
{
    SetMonsterActionFields(a0, gUnknown_202EE44[gDungeonMenu.menuIndex].unk0);
    a0->actionParameters[0] = sUnknownActionUnk4;
    a0->actionParameters[1].actionUseIndex = 0;
    a0->actionParameters[1].itemPos.x = 0;
    a0->actionParameters[1].itemPos.y = 0;
}

void sub_8060D24(UNUSED ActionContainer *a0)
{
    Item *item = sub_8044D90(GetLeader(), 0, 0xB);
    DungeonShowWindows(NULL, 0);
    sub_801B3C0(item);

    do {
        DungeonRunFrameActions(0x16);
    } while (sub_801B410() == 0);

    sub_801B450();
    sub_803EAF0(0, NULL);
}

static s32 sub_8060D64(s16 *a0, bool8 a1, bool8 a2, bool8 a3, Entity *a4)
{
    s32 i;
    s32 count = 0;

    if (gDungeon->unk644.unk17 && !a1) {
        if (gTeamInventoryRef->teamItems[0].flags & ITEM_FLAG_EXISTS) {
            a0[count++] = 0;
        }
        if (gTeamInventoryRef->teamItems[INVENTORY_SIZE / 2].flags & ITEM_FLAG_EXISTS) {
            a0[count++] = 1;
        }
    }

    if (a2 && PosHasItem(&a4->pos)) {
        a0[count++] = 2;
    }

    if (!a1 && !a3) {
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            Entity *teamMon = gDungeon->teamPokemon[i];
            if (EntityIsValid(teamMon) && GetEntInfo(teamMon)->heldItem.flags & ITEM_FLAG_EXISTS) {
                a0[count++] = i + MAX_TEAM_MEMBERS;
            }
        }
    }

    return count;
}
