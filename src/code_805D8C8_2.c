#include "global.h"
#include "structs/str_dungeon.h"
#include "number_util.h"
#include "input.h"
#include "structs/map.h"
#include "dungeon_main.h"
#include "dungeon_message.h"
#include "dungeon_action.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "moves.h"
#include "items.h"
#include "dungeon_music.h"
#include "dungeon_ai_movement.h"
#include "code_8045A00.h"
#include "string_format.h"
#include "code_803E46C.h"
#include "code_801602C.h"
#include "code_800D090.h"
#include "trap.h"
#include "charge_move.h"
#include "dungeon_map_access.h"
#include "status_checks_1.h"
#include "game_options.h"
#include "weather.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "tile_types.h"
#include "dungeon_visibility.h"
#include "dungeon_movement.h"
#include "bg_control.h"
#include "menu_input.h"
#include "music.h"
#include "items.h"
#include "play_time.h"
#include "pokemon_3.h"
#include "text.h"
#include "code_806CD90.h"
#include "code_8044CC8.h"
#include "code_801B3C0.h"
#include "dungeon_capabilities.h"
#include "constants/dungeon.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/iq_skill.h"
#include "constants/dungeon_action.h"
#include "structs/struct_sub80095e4.h"
#include "structs/str_text.h"

struct UnkMenuBitsStruct {
    u8 a0_8;
    u8 a0_16;
    u8 a0_24;
    u8 a0_32;
};

extern void HandleSetItemAction(Entity *,bool8);
extern void HandleUnsetItemAction(Entity *,bool8);
extern bool8 sub_8048A68(Entity *param_1,Item *item);
extern bool8 sub_8048950(Entity *param_1,Item *item);
extern bool8 sub_8048B9C(Entity *param_1,Item *item);
extern Item *sub_8044D90(Entity *, s32, u32);
extern void PlayDungeonStartButtonSE(void);
extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);
extern void sub_806A6E8(Entity *);
extern bool8 sub_8047084(s32 itemFlag);
extern void HandleTrap(Entity *pokemon, DungeonPos *pos, int param_3, char param_4);
extern void sub_8045DB4(DungeonPos *, u32);
bool8 sub_807EF48(void);
void sub_806A2BC(Entity *a0, u8 a1);
bool8 sub_805E874(void);
bool8 sub_80701A4(Entity *a0);
void ShowDungeonStairsMenu(Entity *a0);
void sub_805E738(Entity *a0);
void sub_803E708(s32 a0, s32 a1);
void sub_8040A78(void);
void sub_805E804(void);
void ShowDungeonOthersMenu(void);
void sub_8075680(u32);
void sub_8094C88(void);
void sub_8040A84(void);
void sub_8047158(void);
void sub_806A914(u8 a0, u8 a1, u8 a2);
void SetLeaderActionToNothing(u8 a0);
u16 GetLeaderActionId(void);
void sub_80978C8(s16 a0);
bool8 sub_8094C48(void);
bool8 sub_805EC4C(Entity *a0, u8 a1);
void sub_803E724(s32 a0);
void HandleTalkFieldAction(Entity *);
bool8 sub_8044B28(void);
bool8 IsNotAttacking(Entity *param_1, bool8 param_2);
void ShowMainMenu(bool8 fromBPress, bool8 a1);
bool8 sub_805EF60(Entity *a0, EntityInfo *a1);
s32 GetTeamMemberEntityIndex(Entity *pokemon);
bool8 sub_8070F80(Entity * pokemon, s32 direction);
void PrintOnMainMenu(bool8 printAll);
bool8 ShowDungeonItemsMenu(Entity * a0, struct UnkMenuBitsStruct *a1);
bool8 sub_805FD3C(struct UnkMenuBitsStruct *a0);
void sub_8060D24(UNUSED ActionContainer *a0);
bool8 ShowDungeonTeamMenu(Entity *a0);
void sub_8062D8C(ActionContainer *a0);
void sub_80637E8(ActionContainer *a0);
void sub_8063B54(ActionContainer *a0);
void sub_8063BB4(ActionContainer *a0);
void sub_806752C(ActionContainer *a0);
void sub_8061A38(ActionContainer *a0, bool8 a1);
void sub_8063A70(ActionContainer *a0, bool8 a1);
void sub_8063CF0(ActionContainer *a0, bool8 a1);
void sub_8067768(ActionContainer *a0);
void ShowTacticsMenu(ActionContainer *a0);
void ChangeDungeonCameraPos(DungeonPos *pos, s32 a1, u8 a2, u8 a3);
extern bool8 sub_8071A8C(Entity *pokemon);
extern void sub_80643AC(Entity *pokemon);
extern bool8 ShowDungeonMovesMenu(Entity * entity, u8 a1, u8 a2, s32 a3, s32 a4);

extern u8 gUnknown_202EE00;
extern Entity *gLeaderPointer;

extern const u8 *gUnknown_80F8A84;
extern const u8 *gUnknown_80F8A6C;
extern const u8 *gUnknown_80F8ADC;
extern const u8 *gUnknown_80F8AB0;
extern const u8 *gUnknown_80F8B0C;
extern const u8 *gUnknown_80FD4B0;
extern const u8 *gUnknown_80F8A4C;
extern const u8 *gUnknown_80F8A28;
extern const u8 *gUnknown_8100208;
extern const u8 *gUnknown_80F9BD8;
extern const u8 *gUnknown_80F9C08;
extern const u8 *gUnknown_80F9C2C;
extern const u8 *gUnknown_80F9BB0;
extern const u8 *gUnknown_80FDE18;
extern const u8 *gUnknown_80F8B24;
extern const u8 *gTeamToolboxAPtr;
extern const u8 *gTeamToolboxBPtr;
extern const u8 *gFieldItemMenuGroundTextPtr;
extern const u8 *gUnknown_80FE940;
extern const u8 *gWhichTextPtr1;
extern const u8 *const gFieldMenuMovesPtr;
extern const u8 *const gFieldMenuItemsPtr;
extern const u8 *const gFieldMenuTeamPtr;
extern const u8 *const gFieldMenuOthersPtr;
extern const u8 *const gFieldMenuGroundPtr;
extern const u8 *const gUnknown_80F9174;
extern const u8 *const gUnknown_80F9190;
extern const u8 *const gUnknown_80F91C8;
extern const u8 *const gUnknown_80F91E0;
extern const u8 *const gUnknown_80F91A8;
extern const u8 *const gUnknown_80FE954;

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

extern MenuInputStruct gDungeonMenu;

s32 sub_8060D64(s16 *a0, bool8 a1, bool8 a2, bool8 a3, Entity *a4);

void sub_8060890(DungeonPos *a0);
bool8 sub_8060860(s32 a0);
void sub_8060900(Entity *a0);
s32 sub_8060800(WindowHeader *a0, s32 a1);
void ChosenSubMenuToAction(ActionContainer *a0);
Entity *DrawFieldGiveItemMenu(s32 *teamId, s32 a1);

// Could this be a start of a new file?
static UNUSED EWRAM_DATA u8 sUnused[4] = {0};
static EWRAM_DATA ActionParameter sUnknownActionUnk4 = {0};
static EWRAM_DATA s32 sUnknown_202F240 = 0;
static UNUSED EWRAM_DATA u8 sUnused2[4] = {0};
static EWRAM_DATA s16 sUnknown_202F248[8] = {0};
static EWRAM_DATA s32 sUnknown_202F258 = 0;
static UNUSED EWRAM_DATA u8 sUnused3[4] = {0};
EWRAM_DATA s32 gTeamMenuChosenId = 0;
static UNUSED EWRAM_DATA u8 sUnused4[4] = {0};

static void PrintOnDungeonItemsMenu(s32 a0, Entity *a1, bool8 a2, bool8 a3, Windows *a4, WindowHeader *a5);

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
                else if (a0Info->action.action == 0x36) {
                    s32 teamId;
                    if (DrawFieldGiveItemMenu(&teamId, 2) != NULL) {
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

extern const struct Window gUnknown_8106B6C;
extern const struct unkStruct_8090F58 gUnknown_8106B60;

static void PrintOnDungeonItemsMenu(s32 a0, Entity *a1, bool8 a2, bool8 a3, Windows *windows, WindowHeader *a5)
{
    s32 i, x, y;
    s32 r10;
    UnkTextStruct1 *txtStrPtr;
    Window var_94;
    u8 txtBuff[80];
    EntityInfo *a1Info;

    var_94 = gUnknown_8106B6C;
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

    if (a2) {
        gDungeonMenu.unkC += 0x40;
        windows->id[0].pos.x = 0xA;
        windows->id[1] = var_94;
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
    if (a2) {
        sub_80073B8(1);
        PrintFormattedStringOnWindow(4, 2, gWhichTextPtr1, 1, 0);
        sub_80073E0(1);
    }
}

s32 sub_8060800(WindowHeader *a0, s32 a1)
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

bool8 sub_8060860(s32 a0)
{
    if (gDungeonMenu.unk1A <= 1 || sUnknown_202F248[a0] > 1)
        return FALSE;
    else
        return TRUE;
}

void sub_8060890(DungeonPos *a0)
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

extern Item * sub_8044CC8(Entity *param_1, ActionParameter *param_2, UNUSED s32 a3);
extern void sub_8044F5C(u16 param_1, u8 param_2);
extern void sub_8044FF0(u16 param_1);
extern u16 sub_8044DC8(Item *param_1);
extern bool8 sub_8046F00(Item *item);
extern void sub_8045064(void);

void sub_8060900(Entity *a0)
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

void ChosenSubMenuToAction(ActionContainer *a0)
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

extern bool8 PosHasItem(DungeonPos *pos);

s32 sub_8060D64(s16 *a0, bool8 a1, bool8 a2, bool8 a3, Entity *a4)
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

extern WindowHeader gUnknown_202F270;

struct UnkFieldTeamMenuStruct
{
    s32 unk0;
    s32 unk4[MAX_TEAM_MEMBERS];
    u8 unk14[MAX_TEAM_MEMBERS];
};

void PrintOnDungeonTeamMenu(struct UnkFieldTeamMenuStruct *a0, Windows *a1, bool8 a2);
void sub_806145C(struct UnkFieldTeamMenuStruct *a0);
void sub_80615B4(ActionContainer *a0, struct UnkFieldTeamMenuStruct *a1);

extern u8 gUnknown_202EE39;

bool8 ShowDungeonTeamMenu(Entity *a0)
{
    s32 i;
    bool32 r10, ret;
    struct UnkFieldTeamMenuStruct sp;
    Windows windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 14,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .unk14 = &gUnknown_202F270,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityIsValid(teamMon)) {
            GetEntInfo(teamMon)->unk157 = TRUE;
        }
    }

    if (!gDungeon->unk644.unk17) {
        windows.id[0].type = WINDOW_TYPE_NORMAL;
        windows.id[0].pos.y++;
    }

    while (1) {
        s32 id;
        bool32 r4;

        ret = FALSE;
        PrintOnDungeonTeamMenu(&sp, &windows, TRUE);
        r10 = FALSE;
        while (1) {
            s32 id = sp.unk4[gDungeonMenu.menuIndex];
            if (id >= 0) {
                Entity *teamMon = gDungeon->teamPokemon[id];
                sub_806A2BC(teamMon, 0);
                ChangeDungeonCameraPos(&teamMon->pos, 0, 1, 1);
            }

            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x1B);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(1);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(1);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.pressed & START_BUTTON) {
                if (sp.unk14[gDungeonMenu.menuIndex] != 0) {
                    PlayDungeonStartButtonSE();
                    r10 = TRUE;
                    break;
                }
                PlayDungeonCancelSE();
            }
            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button)
            {
                if (sp.unk14[gDungeonMenu.menuIndex] != 0) {
                    PlayDungeonConfirmationSE();
                    break;
                }
                PlayDungeonCancelSE();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                ret = TRUE;
                break;
            }
        }

        id = sp.unk4[gDungeonMenu.menuIndex];
        if (id >= 0) {
            Entity *teamMon = gDungeon->teamPokemon[id];
            sub_806A2BC(teamMon, 0);
            ChangeDungeonCameraPos(&teamMon->pos, 0, 1, 1);
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x1B);
        sub_804AA60();
        if (ret) {
            break;
        }

        sp.unk0 = gDungeonMenu.menuIndex;
        gTeamMenuChosenId = gDungeonMenu.menuIndex;
        sub_806145C(&sp);
        if (r10) {
            EntityInfo *info = GetEntInfo(a0);
            SetMonsterActionFields(&info->action, 0x1B);
            info->action.actionParameters[0].actionUseIndex = sp.unk4[sp.unk0];
            ret = FALSE;
            break;
        }

        CreateDungeonMenuSubWindow(&windows.id[0], 0x12);
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x1B);
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
                    sub_80615B4(&GetEntInfo(a0)->action, &sp);
                    PlayDungeonConfirmationSE();
                    r4 = FALSE;
                    break;
                }
                PlayDungeonCancelSE();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                r4 = TRUE;
                break;
            }
        }
        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x1B);
        if (r4 != TRUE) {
            ret = FALSE;
            break;
        }
    }

    if (ret) {
        sub_806A2BC(GetLeader(), 0);
    }
    sub_803EAF0(0, NULL);
    return ret;
}

bool32 sub_8069D18(DungeonPos *a0, Entity *a1);

extern const u8 gTeamFormat[];
extern const u8 gHeartRedTiny[];
extern const u8 gHeartRedSmall[];
extern const u8 gHeartRedMedium[];
extern const u8 gHeartRedLarge[];
extern const u8 gHeartYellowTiny[];
extern const u8 gHeartYellowSmall[];
extern const u8 gHeartYellowMedium[];
extern const u8 gHeartYellowLarge[];
extern const u8 gUnknown_8106BD4[];
extern const u8 gUnknown_8106BE0[];
extern const u8 gUnknown_8106BEC[];
extern const u8 gUnknown_8106BF4[];

extern void sub_8070968(u8 *buffer, EntityInfo *entityInfo, s32 colorNum);

void PrintOnDungeonTeamMenu(struct UnkFieldTeamMenuStruct *a0, Windows *windows, bool8 a2)
{
    s32 r0;
    DungeonPos pos;
    s32 i;

    s32 count = 0;
    bool8 r10 = (windows->id[0].type == WINDOW_TYPE_WITH_HEADER);

    sub_8069D18(&pos, GetLeader());
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        EntityInfo *monInfo;
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityIsValid(teamMon)) {
            a0->unk4[count] = i;
            monInfo = GetEntInfo(teamMon);
            a0->unk14[count] = monInfo->unk157;
            if (pos.x == teamMon->pos.x && pos.y == teamMon->pos.y && gTeamMenuChosenId < 0) {
                gTeamMenuChosenId = count;
            }
            count++;
        }
    }

    if (gTeamMenuChosenId >= count) {
        gTeamMenuChosenId = count - 1;
    }
    if (gTeamMenuChosenId < 0) {
        gTeamMenuChosenId = 0;
    }

    for (i = count; i < MAX_TEAM_MEMBERS; i++) {
        a0->unk4[i] = -1;
        a0->unk14[i] = 0;
    }

    gUnknown_202F270.f0 = 1;
    gUnknown_202F270.f1 = 0;
    gUnknown_202F270.f3 = 0;
    gDungeonMenu.menuIndex = gTeamMenuChosenId;
    gDungeonMenu.unk1A = count;
    gDungeonMenu.unk1C = count;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = (r10 != FALSE) * 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    r0 = sub_80095E4(count, 0);
    if (r10) {
        r0 += 2;
    }
    windows->id[0].unk10 = r0;
    windows->id[0].height = r0;
    gUnknown_202F270.f2 = 8;
    if (a2) {
        windows->id[1] = windows->id[3];
    }

    DungeonShowWindows(windows, 1);
    sub_80137B0(&gDungeonMenu, 0);
    sub_80073B8(0);
    if (r10) {
        PrintFormattedStringOnWindow(0xC, 0, gTeamFormat, 0, 0);
    }

    // Print hp/max hp
    for (i = 0; i < count; i++) {
        s32 y;
        s32 id = a0->unk4[i];
        if (id >= 0) {
            Entity *teamMon = gDungeon->teamPokemon[id];
            if (EntityIsValid(teamMon))
            {
                EntityInfo *monInfo = GetEntInfo(teamMon);
                s32 color = (a0->unk14[i] != 0) ? 6 : 2;

                sub_8070968(gFormatBuffer_Monsters[0], monInfo, color);
                if (sub_806A538(gRecruitedPokemonRef->pokemon2[monInfo->teamIndex].unkA)) {
                    if (monInfo->HP <= monInfo->maxHPStat / 4) {
                        strcpy(gFormatBuffer_Monsters[1], gHeartRedTiny);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 2) {
                        strcpy(gFormatBuffer_Monsters[1], gHeartRedSmall);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 3) {
                        strcpy(gFormatBuffer_Monsters[1], gHeartRedMedium);
                    }
                    else {
                        strcpy(gFormatBuffer_Monsters[1], gHeartRedLarge);
                    }
                }
                else {
                    if (monInfo->HP <= monInfo->maxHPStat / 4) {
                        strcpy(gFormatBuffer_Monsters[1], gHeartYellowTiny);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 2) {
                        strcpy(gFormatBuffer_Monsters[1], gHeartYellowSmall);
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 3) {
                        strcpy(gFormatBuffer_Monsters[1], gHeartYellowMedium);
                    }
                    else {
                        strcpy(gFormatBuffer_Monsters[1], gHeartYellowLarge);
                    }
                }

                gFormatArgs[0] = monInfo->HP;
                gFormatArgs[1] = monInfo->maxHPStat;
                y = GetMenuEntryYCoord(&gDungeonMenu, i);
                if (monInfo->isTeamLeader) {
                    PrintFormattedStringOnWindow(9, y, gUnknown_8106BD4, 0, 0);
                }
                else {
                    PrintFormattedStringOnWindow(9, y, gUnknown_8106BE0, 0, 0);
                }
            }
        }
    }

    sub_80073E0(0);
}

extern bool8 CanLeaderSwitch(u8 dungeon);

void sub_806145C(struct UnkFieldTeamMenuStruct *a0)
{
    Entity *teamMon;
    EntityInfo *monInfo;

    gDungeonSubMenuItemsCount = 0;
    teamMon = gDungeon->teamPokemon[a0->unk4[gDungeonMenu.menuIndex]];
    monInfo = GetEntInfo(teamMon);
    sub_8044F5C(0x1B, 0);
    sub_8044F5C(0x19, 0);
    if (!monInfo->isTeamLeader) {
        if (!gDungeon->unk644.unk19 && (monInfo->joinedAt.id != DUNGEON_JOIN_LOCATION_PARTNER || gDungeon->unk644.unk18)) {
            sub_8044F5C(0x34, 0);
        }
        sub_8044F5C(0x1C, 0);
    }
    sub_8044F5C(0x30, 0);
    if (!monInfo->isTeamLeader) {
        sub_8044F5C(0x1A, 0);
    }
    if (!monInfo->isTeamLeader && gDungeon->unk644.unk18 && CanLeaderSwitch(gDungeon->unk644.dungeonLocation.id)) {
        bool32 r5;

        sub_8044F5C(0x3B, 0);
        r5 = TRUE;
        if (monInfo->teamIndex >= MAX_TEAM_MEMBERS) {
            r5 = FALSE;
        }
        else {
            PokemonStruct2 *mon = &gRecruitedPokemonRef->pokemon2[monInfo->teamIndex];
            if (sub_806A538(mon->unkA)) {
                r5 = FALSE;
            }
        }

        if (CheckVariousStatuses2(teamMon, FALSE)) {
            r5 = FALSE;
        }
        if (!r5) {
            sub_8044FF0(0x3B);
        }
    }

    if (IsExperienceLocked(monInfo->joinedAt.id)) {
        sub_8044FF0(0x19);
        sub_8044FF0(0x3B);
        sub_8044FF0(0x1A);
        sub_8044FF0(0x30);
        sub_8044FF0(0x34);
    }

    sub_8045064();
}

void sub_80615B4(ActionContainer *a0, struct UnkFieldTeamMenuStruct *a1)
{
    SetMonsterActionFields(a0, gUnknown_202EE44[gDungeonMenu.menuIndex].unk0);
    a0->actionParameters[0].actionUseIndex = a1->unk4[a1->unk0];
}

void PrintMonTactics(s32 a0, u8 *tacticIds, EntityInfo *mon, s32 windowId);
void sub_80623B0(void);
void sub_8062D68(void);
void sub_8062230(void);
void sub_8062748(u8 a0);

void ShowTacticsMenu(ActionContainer *a0)
{
    Windows windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 14,
                .unk10 = 18,
                .unk12 = 2,
                .unk14 = &gUnknown_202F270,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };
    EntityInfo *monInfo;
    u8 tacticIds[NUM_TACTICS];
    s32 scrollFirstId;
    s32 menuIndex;
    Entity *teamMon;

    teamMon = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    monInfo = GetEntInfo(teamMon);
    menuIndex = 0;
    scrollFirstId = 0;
    while (1) {
        s32 i;
        bool32 addCursor = TRUE;
        bool32 loopBreak = FALSE;

        gUnknown_202F270.f0 = 1;
        gUnknown_202F270.f1 = 0;
        gUnknown_202F270.f2 = 10;
        gUnknown_202F270.f3 = 0;
        DungeonShowWindows(&windows, 1);
        PrintMonTactics(scrollFirstId, tacticIds, monInfo, 0);
        for (i = 0; i < 8; i++) {
            if (tacticIds[i] == TACTIC_UNUSED)
                break;
        }
        gDungeonMenu.unk1A = i;
        gDungeonMenu.unk1C = 8;
        gDungeonMenu.unk1E = 0;
        gDungeonMenu.unk20 = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unkC = 0;
        gDungeonMenu.unkE = 0;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk0 = 0;
        sub_801317C(&gDungeonMenu.unk28);
        sub_80137B0(&gDungeonMenu, 0);
        gDungeonMenu.menuIndex = menuIndex;
        while (1) {
            s32 i;

            AddMenuCursorSprite(&gDungeonMenu);
            if (tacticIds[8] != TACTIC_UNUSED) {
                sub_80623B0();
            }
            if (scrollFirstId != 0) {
                sub_8062230();
            }
            DungeonRunFrameActions(0x3D);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(1);
                if (gDungeonMenu.menuIndex == 7) {
                    if (tacticIds[8] != TACTIC_UNUSED) {
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc1(0);
                            DungeonRunFrameActions(0x3D);
                        }
                        scrollFirstId++;
                    }
                    menuIndex = 7;
                    break;
                }
                MoveMenuCursorDownWrapAround(&gDungeonMenu, 0);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(1);
                if (gDungeonMenu.menuIndex == 0) {
                    if (scrollFirstId != 0) {
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc2(0);
                            DungeonRunFrameActions(0x3D);
                        }
                        scrollFirstId--;
                    }
                    menuIndex = 0;
                    break;
                }
                MoveMenuCursorUpWrapAround(&gDungeonMenu, 0);
            }
            if (gRealInputs.pressed & START_BUTTON) {
                u32 tacticId = tacticIds[gDungeonMenu.menuIndex];
                menuIndex = gDungeonMenu.menuIndex;
                PlayDungeonStartButtonSE();
                sub_8062748(tacticId);
                loopBreak = FALSE;
                break;
            }
            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                bool32 changed;

                u32 tacticId = tacticIds[gDungeonMenu.menuIndex];
                menuIndex = gDungeonMenu.menuIndex;
                sub_8062D68();
                PlayDungeonConfirmationSE();
                gDungeonSubMenuItemsCount = 0;
                sub_8044F5C(0x2F, 0);
                sub_8044F5C(0xC, 0);
                if (CheckVariousStatuses2(teamMon, TRUE)) {
                    sub_8044FF0(0x2F);
                }
                CreateDungeonMenuSubWindow(&windows.id[0], 0x16);
                while (1) {
                    changed = FALSE;
                    AddMenuCursorSprite(&gDungeonMenu);
                    DungeonRunFrameActions(0x3D);
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
                            changed = TRUE;
                            break;
                        }
                        PlayDungeonCancelSE();
                    }
                    if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                        PlayDungeonCancelSE();
                        changed = FALSE;
                        break;
                    }
                }
                if (changed) {
                    PlayDungeonConfirmationSE();
                    if (gDungeonMenu.menuIndex == 0) {
                        PlaySoundEffect(0x133);
                        monInfo->tactic = tacticId;
                        monInfo->aiTarget.aiObjective = 6;
                        monInfo->aiTarget.aiTarget = NULL;
                        monInfo->aiTarget.unkC = 0;
                        monInfo->aiTarget.aiTargetSpawnGenID = 0;
                        if (!monInfo->isTeamLeader) {
                            AIMovement(teamMon, TRUE);
                        }
                    }
                    else {
                        sub_8062748(tacticId);
                        addCursor = FALSE;
                    }
                }
                loopBreak = FALSE;
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                loopBreak = TRUE;
                break;
            }
        }

        if (addCursor) {
            AddMenuCursorSprite(&gDungeonMenu);
        }
        DungeonRunFrameActions(0x3D);
        if (loopBreak)
            break;
    }
    sub_803EAF0(0, NULL);
}

extern void GetAvailTacticsforLvl(u8 *tacticsBuffer, s32 pokeLevel);

void PrintMonTactics(s32 firstId, u8 *tacticIds, EntityInfo *mon, s32 windowId)
{
    u8 tacticsBuffer[NUM_TACTICS];
    u32 tactic;
    s32 y, i, j;

    firstId--;
    sub_80073B8(windowId);
    PrintStringOnWindow(0x10, 0, gUnknown_80FE954, windowId, 0);
    y = 0x14;
    for (j = 0; j < 9; j++) {
        tacticIds[j] = TACTIC_UNUSED;
    }
    GetAvailTacticsforLvl(tacticsBuffer, GetLeaderInfo()->level);
    for (i = -1; i < 10; i++, y += 12, firstId++) {
        if (firstId < 0)
            continue;
        if (firstId >= NUM_TACTICS)
            continue;

        tactic = tacticsBuffer[firstId];
        if (i >= 0 && i < 9) {
            tacticIds[i] = tactic;
        }
        if (tactic == TACTIC_UNUSED)
            break;

        CopyTacticsNameToBuffer(gFormatBuffer_Monsters[0], tactic);
        if (mon->tactic == tactic) {
            PrintFormattedStringOnWindow(0x10, y, gUnknown_8106BEC, windowId, 0);
        }
        else {
            PrintFormattedStringOnWindow(0x10, y, gUnknown_8106BF4, windowId, 0);
        }
    }

    sub_80073E0(windowId);
}

EWRAM_INIT u8 gUnknown_203B43C[4] = {2, 0, 0xD, 0}; // TODO: Move to a better file and figure out the array count. Apparently it's only written to.

extern void sub_8069844(struct unkStruct_808FF20 *param_1, Entity *target);
extern u32 sub_8014140(s32 a0, const void *a1);
void sub_806285C(s32 a0);
void sub_806262C(u8 iqSkillId);

extern const u8 gUnknown_8106B8C[];

void sub_8061A38(ActionContainer *a0, bool8 a1)
{
    s32 spArr[6];
    struct unkStruct_808FF20 unkMonStruct;
    struct UnkInfoTabStruct unkInfoTabStruct;
    Windows windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 14,
                .unk10 = 18,
                .unk12 = 2,
                .unk14 = &gUnknown_202F270,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };
    s32 r8;
    Entity *entity;
    s32 var_3C;
    s32 var_38;
    EntityInfo *entityInfo;

    var_3C = 0;
    r8 = 0;
    entity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    entityInfo = GetEntInfo(entity);

    if (IsExperienceLocked(entityInfo->joinedAt.id)) {
        spArr[0] = 1;
        spArr[1] = 0;
        spArr[2] = 0;
        spArr[3] = 0;
        spArr[4] = 0;
        spArr[5] = 0;
        var_38 = 1;
    }
    else if (a1) {
        spArr[0] = 4;
        spArr[1] = 0;
        spArr[2] = 0;
        spArr[3] = 0;
        spArr[4] = 0;
        spArr[5] = 0;
        var_38 = 1;
    }
    else {
        spArr[0] = 2;
        spArr[1] = 1;
        spArr[2] = 3;
        spArr[3] = 5;
        spArr[4] = 0;
        spArr[5] = 0;
        var_38 = 4;
    }

    unkMonStruct.unk40 = 0;
    unkMonStruct.unk56 = 0;
    gDungeonMenu.menuIndex = 0;

    while (1) {
        bool8 loopBreak = FALSE;
        s32 var_30 = 0;
        s32 var_2C = 0;
        s32 var_28 = 1;
        UnkTextStruct1 *unkTxtStr1Ptr = &gUnknown_2027370[0];

        gUnknown_202F270.f0 = var_38;
        gUnknown_202F270.f1 = var_3C;
        gUnknown_202F270.f2 = 10;
        gUnknown_202F270.f3 = 0;
        DungeonShowWindows(&windows, TRUE);
        sub_8069844(&unkMonStruct, entity);
        CreatePokemonInfoTabScreen(spArr[var_3C], var_3C, &unkMonStruct, &unkInfoTabStruct, 0);
        gDungeonMenu.unk1E = var_3C;
        gDungeonMenu.unk20 = var_38;
        gDungeonMenu.unkC = (unkTxtStr1Ptr->unk0 + 15) * 8;
        gDungeonMenu.unkE = ((unkTxtStr1Ptr->unk2 + 1) * 8) - 2;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk0 = 0;
        sub_801317C(&gDungeonMenu.unk28);
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.unk1A = 0;
        gDungeonMenu.unk1C = 0;

        if (spArr[var_3C] == 1) {
            s32 i;

            for (i = 0; i < 8; i++) {
                if (unkInfoTabStruct.unkC[i] == 0) {
                    break;
                }
            }

            if (i != 0) {
                var_2C = 1;
                gDungeonMenu.unk1A = i;
                gDungeonMenu.unk1C = 8;
                sub_80137B0(&gDungeonMenu, 0);
            }
            gDungeonMenu.menuIndex = r8;
        }
        else if (spArr[var_3C] == 4) {
            s32 i;

            for (i = 0; i < 8; i++) {
                if (unkInfoTabStruct.unk0[i] == 0) {
                    break;
                }
            }

            if (i != 0) {
                var_30 = 1;
                gDungeonMenu.unk1A = i;
                gDungeonMenu.unk1C = 8;
                sub_80137B0(&gDungeonMenu, 0);
            }
            gDungeonMenu.menuIndex = r8;
        }

        while (1) {
            s32 unkVar;
            bool8 r5, r6;

            AddMenuCursorSprite(&gDungeonMenu);
            unkVar = sub_8014140(0, gUnknown_8106B8C);
            r5 = FALSE;
            r6 = FALSE;
            if (var_30) {
                if (unkInfoTabStruct.unk0[8] != 0) {
                    r5 = TRUE;
                    sub_80623B0();
                }
                if (unkMonStruct.unk40 != 0) {
                    r6 = TRUE;
                    sub_8062230();
                }
            }
            if (var_2C) {
                if (unkInfoTabStruct.unkC[8] != 0) {
                    r5 = TRUE;
                    sub_80623B0();
                }
                if (unkMonStruct.unk56 != 0) {
                    r6 = TRUE;
                    sub_8062230();
                }
            }

            DungeonRunFrameActions(0x1C);
            if (gUnknown_202F270.f0 > 1 && !sub_80048C8()) {
                if ((gRealInputs.pressed & DPAD_RIGHT) || gDungeonMenu.unk28.dpad_right) {
                    PlayDungeonCursorSE(0);
                    var_3C++;
                    if (spArr[var_3C] == 0) {
                        var_3C = 0;
                    }
                    break;
                }
                if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
                    PlayDungeonCursorSE(0);
                    var_3C--;
                    if (var_3C == -1) {
                        var_3C = 5;
                        while (spArr[var_3C] == 0) {
                            var_3C--;
                        }
                    }
                    break;
                }
            }

            if (var_2C) {
                if (unkVar == 2 && r5) {
                    PlayDungeonCursorSE(0);
                    if (unkInfoTabStruct.unkC[8] != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc1(0);
                            DungeonRunFrameActions(28);
                        }
                        unkMonStruct.unk56++;
                    }
                    r8 = 7;
                    break;
                }
                if (gRealInputs.repeated & DPAD_DOWN) {
                    PlayDungeonCursorSE(0);
                    if (gDungeonMenu.menuIndex == 7) {
                        if (unkInfoTabStruct.unkC[8] != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc1(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk56++;
                        }
                        r8 = 7;
                        break;
                    }
                    else {
                        MoveMenuCursorDownWrapAround(&gDungeonMenu, 0);
                    }
                }

                if (unkVar == 1 && r6) {
                    if (unkMonStruct.unk56 != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc2(0);
                            DungeonRunFrameActions(28);
                        }
                        unkMonStruct.unk56--;
                    }
                    r8 = 0;
                    break;
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    PlayDungeonCursorSE(1);
                    if (gDungeonMenu.menuIndex == 0) {
                        if (unkMonStruct.unk56 != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc2(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk56--;
                        }
                        r8 = 0;
                        break;
                    }
                    else {
                        MoveMenuCursorUpWrapAround(&gDungeonMenu, 0);
                    }
                }
            }
            else if (var_30) {
                if (unkVar == 2 && r5) {
                    if (unkInfoTabStruct.unk0[8] != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc1(0);
                            DungeonRunFrameActions(28);
                        }
                        unkMonStruct.unk40++;
                    }
                    r8 = 7;
                    break;
                }
                if (gRealInputs.repeated & DPAD_DOWN) {
                    PlayDungeonCursorSE(1);
                    if (gDungeonMenu.menuIndex == 7) {
                        if (unkInfoTabStruct.unk0[8] != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc1(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk40++;
                        }
                        r8 = 7;
                        break;
                    }
                    else {
                        MoveMenuCursorDownWrapAround(&gDungeonMenu, 0);
                    }
                }

                if (unkVar == 1 && r6) {
                    if (unkMonStruct.unk40 != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc2(0);
                            DungeonRunFrameActions(28);
                        }
                        unkMonStruct.unk40--;
                    }
                    r8 = 0;
                    break;
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    PlayDungeonCursorSE(1);
                    if (gDungeonMenu.menuIndex == 0) {
                        if (unkMonStruct.unk40 != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc2(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk40--;
                        }
                        r8 = 0;
                        break;
                    }
                    else {
                        MoveMenuCursorUpWrapAround(&gDungeonMenu, 0);
                    }
                }
            }

            if (sub_80048C8())
                continue;

            if (gRealInputs.pressed & START_BUTTON) {
                if (var_2C) {
                    s32 var = unkInfoTabStruct.unkC[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    PlayDungeonStartButtonSE();
                    sub_806285C(var);
                    var_28 = 0;
                    loopBreak = FALSE;
                    break;
                }
                else if (var_30) {
                    s32 var = unkInfoTabStruct.unk0[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    PlayDungeonStartButtonSE();
                    sub_806262C(var);
                    var_28 = 0;
                    loopBreak = FALSE;
                    break;
                }
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                if (var_2C) {
                    s32 var = unkInfoTabStruct.unkC[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    sub_8062D68();
                    gDungeonSubMenuItemsCount = 0;
                    PlayDungeonConfirmationSE();
                    sub_8044F5C(0xC, 0);
                    CreateDungeonMenuSubWindow(&windows.id[0], 0x16);
                    while (1) {
                        AddMenuCursorSprite(&gDungeonMenu);
                        DungeonRunFrameActions(0x1C);
                        if (gRealInputs.repeated & DPAD_DOWN) {
                            PlayDungeonCursorSE(1);
                            MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
                        }
                        if (gRealInputs.repeated & DPAD_UP) {
                            PlayDungeonCursorSE(1);
                            MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
                        }

                        if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                            PlayDungeonConfirmationSE();
                            sub_806285C(var);
                            var_28 = 0;
                            loopBreak = FALSE;
                            break;
                        }
                        if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                            PlayDungeonCancelSE();
                            loopBreak = FALSE;
                            break;
                        }
                    }
                }
                else if (var_30) {
                    bool8 aPress = FALSE;
                    s32 var = unkInfoTabStruct.unk0[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    sub_8062D68();
                    gDungeonSubMenuItemsCount = var_2C;
                    PlayDungeonConfirmationSE();
                    sub_8044F5C(0x28, 0);
                    sub_8044F5C(0xC, 0);
                    if (CheckVariousStatuses2(entity, TRUE)) {
                        sub_8044FF0(0x28);
                    }
                    CreateDungeonMenuSubWindow(&windows.id[0], 0x16);
                    while (1) {
                        AddMenuCursorSprite(&gDungeonMenu);
                        DungeonRunFrameActions(0x1C);
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
                                aPress = TRUE;
                                break;
                            }
                            PlayDungeonCancelSE();
                        }
                        if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                            PlayDungeonCancelSE();
                            loopBreak = FALSE;
                            aPress = FALSE;
                            break;
                        }
                    }

                    if (aPress) {
                        if (gDungeonMenu.menuIndex == 0) {
                            PlaySoundEffect(0x133);
                            ToggleIQSkill(&entityInfo->IQSkillMenuFlags, var);
                        }
                        else {
                            sub_806262C(var);
                            var_28 = 0;
                        }
                        loopBreak = FALSE;
                        break;
                    }
                }
                else {
                    PlayDungeonConfirmationSE();
                    loopBreak = TRUE;
                }
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                loopBreak = TRUE;
                break;
            }
        }

        if (var_28) {
            if (var_30 != 0 || var_2C != 0) {
                AddMenuCursorSprite(&gDungeonMenu);
            }
            DungeonRunFrameActions(0x1C);
        }

        if (loopBreak) {
            break;
        }
    }

    sub_803EAF0(0, NULL);
    LoadIQSkills(entity);
}

extern s32 gUnknown_202EDCC;

// The same as sub_8068344
void sub_8062230(void)
{
    if ((gUnknown_202EDCC & 8) != 0) {
        UnkTextStruct1 *txtStrPtr = &gUnknown_2027370[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 16);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (txtStrPtr->unk2  * 8) + 0x8);
        SpriteSetX(&sprite, (txtStrPtr->unk0  * 8) + 0x40);

        AddSprite(&sprite, 0x100, NULL, NULL);
    }
}

// The same as sub_80684C4
void sub_80623B0(void)
{
    if ((gUnknown_202EDCC & 8) != 0) {
        UnkTextStruct1 *ptr = &gUnknown_2027370[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 0);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (ptr->unk2  * 8) + 0x70);
        SpriteSetX(&sprite, (ptr->unk0  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}

extern SpriteOAM gUnknown_202F268;

void sub_8062500(void)
{
    if ((gUnknown_202EDCC & 8) != 0) {
        UnkTextStruct1 *ptr = &gUnknown_2027370[0];

        SpriteSetAffine1(&gUnknown_202F268, 0);
        SpriteSetAffine2(&gUnknown_202F268, 0);
        SpriteSetObjMode(&gUnknown_202F268, 0);
        SpriteSetMosaic(&gUnknown_202F268, 0);
        SpriteSetBpp(&gUnknown_202F268, 0);
        SpriteSetShape(&gUnknown_202F268, 1);
        SpriteSetMatrixNum(&gUnknown_202F268, 0);
        SpriteSetSize(&gUnknown_202F268, 0);
        SpriteSetTileNum(&gUnknown_202F268, 0x3F0);
        SpriteSetPriority(&gUnknown_202F268, 0);
        SpriteSetPalNum(&gUnknown_202F268, 15);
        SpriteSetY(&gUnknown_202F268, (ptr->unk2  * 8) + 0x60);
        SpriteSetX(&gUnknown_202F268, 0x70);
        AddSprite(&gUnknown_202F268,0x100,NULL,NULL);
    }
}

void sub_80639E4(struct subStruct_203B240 *strings, MenuInputStructSub *menuSub);

void sub_80625A4(s32 count, struct subStruct_203B240 **strings)
{
    s32 i;
    MenuInputStructSub menuSub;

    sub_801317C(&menuSub);
    for (i = 0; i < count; i++) {
        sub_80639E4(strings[i], &menuSub);
        while (1) {
            if (i < count - 1) {
                sub_8062500();
            }
            nullsub_34(&menuSub, 0);
            DungeonRunFrameActions(0x16);
            if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                PlayDungeonCancelSE();
                break;
            }
        }
    }
}

#include "code_8097DD0.h"
#include "move_util.h"
#include "move_util.h"

extern const u8 *const gUnknown_80FE95C;
extern const u8 *const gUnknown_80FE960;
extern const u8 *const gUnknown_80FE964;
extern const u8 *const gUnknown_80FE978;
extern const u8 gUnknown_8106C90[];
extern const u8 gUnknown_8106C98[];
extern const u8 gUnknown_8106C9C[];
extern const u8 *const gWhichTextPtr2;
extern char* sub_808E4FC(s32 a1);
extern char* sub_808E51C(s32 a1);
extern void sub_8062B74(Entity *entity);
extern void sub_8062CA8(Entity *entity);
extern void sub_8045C18(u8 *buffer, Item *item);

void sub_806262C(u8 iqSkillId)
{
    MenuInputStructSub menuSub;
    Windows windows;
    WindowHeader header;
    struct subStruct_203B240 *result[4];

    while (1) {
        s32 count;
        bool8 bPress;

        sub_801317C(&menuSub);
        sub_80140B4(&windows);
        windows.id[0].unk14 = &header;
        header.f0 = 1;
        header.f1 = 0;
        header.f2 = 16;
        header.f3 = 0;
        DungeonShowWindows(&windows, TRUE);
        sub_80073B8(0);

        strcpy(gFormatBuffer_Items[0], GetIQSkillName(iqSkillId));
        PrintFormattedStringOnWindow(16, 0, gUnknown_80FE95C, 0, '\0');
        PrintFormattedStringOnWindow(8, 16, GetIQSkillDescription(iqSkillId), 0, '\0');
        sub_80073E0(0);
        count = sub_8097DF0(GetIQSkillDescription(iqSkillId), result);
        while (1) {
            if (count != 0) {
                sub_8062500();
            }
            nullsub_34(&menuSub, 0);
            DungeonRunFrameActions(0x16);
            if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                bPress = FALSE;
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                bPress = TRUE;
                PlayDungeonCancelSE();
                break;
            }
        }

        if (bPress || count == 0)
            break;

        sub_80625A4(count, result);
    }

    sub_803E708(4, 0x3E);
}

void sub_8062748(u8 tacticId)
{
    MenuInputStructSub menuSub;
    Windows windows;
    WindowHeader header;
    struct subStruct_203B240 *result[4];

    while (1) {
        s32 count;
        bool8 bPress;

        sub_801317C(&menuSub);
        sub_80140B4(&windows);
        windows.id[0].unk14 = &header;
        header.f0 = 1;
        header.f1 = 0;
        header.f2 = 16;
        header.f3 = 0;
        DungeonShowWindows(&windows, TRUE);
        sub_80073B8(0);

        CopyTacticsNameToBuffer(gFormatBuffer_Items[0], tacticId);
        PrintFormattedStringOnWindow(16, 0, gUnknown_80FE960, 0, '\0');
        PrintFormattedStringOnWindow(8, 16, GetTacticsDescription(tacticId), 0, '\0');
        sub_80073E0(0);
        count = sub_8097DF0(GetTacticsDescription(tacticId), result);
        while (1) {
            if (count != 0) {
                sub_8062500();
            }
            nullsub_34(&menuSub, 0);
            DungeonRunFrameActions(62);
            if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                bPress = FALSE;
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                bPress = TRUE;
                PlayDungeonCancelSE();
                break;
            }
        }

        if (bPress || count == 0)
            break;

        sub_80625A4(count, result);
    }

    sub_803E708(4, 0x3E);
}

void sub_806285C(s32 a0)
{
    const u8 *str;
    MenuInputStructSub menuSub;
    WindowHeader header;
    Windows windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 26,
                .height = 12,
                .unk10 = 12,
                .unk12 = 0,
                .unk14 = &header,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };

    sub_801317C(&menuSub);
    header.f0 = 1;
    header.f1 = 0;
    header.f2 = 16;
    header.f3 = 0;
    DungeonShowWindows(&windows, TRUE);
    sub_80073B8(0);
    str = sub_808E4FC(a0);
    strcpy(gFormatBuffer_Items[0], str);
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FE964, 0, '\0');
    PrintFormattedStringOnWindow(8, 16, sub_808E51C(a0), 0, '\0');
    sub_80073E0(0);

    while (1) {
        nullsub_34(&menuSub, 0);
        DungeonRunFrameActions(22);
        if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
            PlayDungeonConfirmationSE();
            break;
        }
        if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
            PlayDungeonCancelSE();
            break;
        }
    }

    sub_803E708(4, 0x3E);
}

extern const Windows gUnknown_8106C30;
extern const Window gUnknown_8106C00;
extern const Window gUnknown_8106C18;

Entity *DrawFieldGiveItemMenu(s32 *teamId, s32 a1)
{
    struct UnkFieldTeamMenuStruct unkStruct;
    Windows windows = gUnknown_8106C30;
    bool8 bPress = FALSE;
    s32 prevId, currId;

    if (teamId != NULL) {
        *teamId = -1;
    }

    if (a1 == 1) {
        windows.id[2] = gUnknown_8106C00;
    }
    else if (a1 == 2) {
        windows.id[2] = gUnknown_8106C18;
    }

    PrintOnDungeonTeamMenu(&unkStruct, &windows, FALSE);
    sub_80073B8(1);
    PrintStringOnWindow(4, 3, gWhichTextPtr2, 1, '\0');
    sub_80073E0(1);
    prevId = -985; // Magic number or does it actually mean anything?

    while (1) {
        currId = unkStruct.unk4[gDungeonMenu.menuIndex];

        if (currId >= 0) {
            Entity *entity = gDungeon->teamPokemon[currId];

            if (EntityIsValid(entity) && prevId != currId) {
                if (a1 == 1) {
                    sub_8062B74(entity);
                }
                else if (a1 == 2) {
                    sub_8062CA8(entity);
                }
            }
            prevId = currId;
            sub_806A2BC(entity, 0);
            ChangeDungeonCameraPos(&entity->pos, 0, 1, 1);
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x1B);
        if (gRealInputs.repeated & DPAD_DOWN) {
            PlayDungeonCursorSE(1);
            MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
        }
        if (gRealInputs.repeated & DPAD_UP) {
            PlayDungeonCursorSE(1);
            MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
        }

        if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
            if (unkStruct.unk14[gDungeonMenu.menuIndex] != 0) {
                PlayDungeonConfirmationSE();
                break;
            }
            PlayDungeonCancelSE();
        }
        if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
            PlayDungeonCancelSE();
            bPress = TRUE;
            break;
        }
    }

    AddMenuCursorSprite(&gDungeonMenu);
    DungeonRunFrameActions(0x1B);
    sub_804AA60();
    sub_806A2BC(GetLeader(), 0);
    sub_803EAF0(0, 0);
    sub_803E708(4, 0x3E);
    if (bPress) {
        return NULL;
    }
    currId = unkStruct.unk4[gDungeonMenu.menuIndex];
    if (teamId != NULL) {
        *teamId = currId;
    }
    if (currId >= 0) {
        return gDungeon->teamPokemon[currId];
    }

    return NULL;
}

void sub_8062B74(Entity *entity)
{
    s32 x, y;
    EntityInfo *entInfo = GetEntInfo(entity);

    CallPrepareTextbox_8008C54(2);
    sub_80073B8(2);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
    PrintFormattedStringOnWindow(12, 0, gUnknown_80FE978, 2, '\0');
    y = 16;

    if (entInfo->monsterBehavior == 1 || IsExperienceLocked(entInfo->joinedAt.id)) {
        PrintFormattedStringOnWindow(12, y, gUnknown_8106C90, 2, '\0');
    }
    else {
        s32 i;

        for (i = 0; i < MAX_MON_MOVES; i++) {
            unkStruct_80928C0 movStruct = {0, 106, 0, 0};
            Move *move = &entInfo->moves.moves[i];

            if (MoveFlagExists(move)) {
                if (entInfo->isTeamLeader) {
                    movStruct.unk0 = 2;
                }
                else {
                    movStruct.unk0 = 4;
                }

                movStruct.unk8 = (CanMonsterUseMove(entity, move, TRUE) == FALSE);
                BufferMoveName(gFormatBuffer_Items[0], move, &movStruct);

                if (MoveFlagLinkChain(move)) {
                    x = 13;
                }
                else {
                    x = 8;
                    if (i != 0) {
                        sub_80078A4(2, 12, y - 2, 120, 7);
                    }
                }
                PrintFormattedStringOnWindow(x, y, gUnknown_8106C98, 2, '\0');
                y += 12;
            }
        }
    }

    sub_80073E0(2);
}

void sub_8062CA8(Entity *entity)
{
    s32 x, y;
    EntityInfo *entInfo = GetEntInfo(entity);

    CallPrepareTextbox_8008C54(2);
    sub_80073B8(2);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
    PrintFormattedStringOnWindow(12, 0, gUnknown_80FE940, 2, '\0');
    x = 8;
    y = 18;

    if (entInfo->monsterBehavior == 1 || IsExperienceLocked(entInfo->joinedAt.id)) {
        PrintFormattedStringOnWindow(8, y, gUnknown_8106C90, 2, '\0');
    }
    else {
        Item *item = &entInfo->heldItem;
        if (!ItemExists(item)) {
            PrintFormattedStringOnWindow(x, y, gUnknown_8106C9C, 2, '\0');
        }
        else {
            sub_8045C18(gFormatBuffer_Items[0], item);
            PrintFormattedStringOnWindow(x, y, gUnknown_8106C98, 2, '\0');
        }
    }

    sub_80073E0(2);
}

void sub_8062D68(void)
{
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    sub_801317C(&gDungeonMenu.unk28);
}

u32 sub_8062D88(void)
{
    return A_BUTTON;
}

void sub_8062D8C(ActionContainer *a0)
{
    s32 id = a0->actionParameters[0].actionUseIndex;
    Entity *entityOrg = gDungeon->teamPokemon[id];
    Entity *entityNew = entityOrg;

    while (1) {
        s32 i, count, countUntilId;

        countUntilId = 0;
        count = 0;
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            if (sub_8071A8C(gDungeon->teamPokemon[i])) {
                if (i == id) {
                    countUntilId = count;
                }
                count++;
            }
        }

        sub_806A2BC(entityNew, 0);
        ChangeDungeonCameraPos(&entityNew->pos, 0, 1, 1);
        SetLeaderActionToNothing(1);
        if (ShowDungeonMovesMenu(entityNew, 0, 1, countUntilId, count)) {
            return;
        }

        if (GetLeaderActionId() == 6) {
            s32 idBefore = id;
            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                if (++id >= MAX_TEAM_MEMBERS) {
                    id = 0;
                }
                entityNew = gDungeon->teamPokemon[id];
                if (sub_8071A8C(entityNew)) {
                    break;
                }
            }

            a0->actionParameters[0].actionUseIndex = id;
            if (idBefore != id) {
                PlayDungeonCursorSE(0);
            }
            SetLeaderActionToNothing(1);
        }
        // Everything is the same as in the above if except for add/sub difference.
        else if (GetLeaderActionId() == 7) {
            s32 idBefore = id;
            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                if (--id < 0) {
                    id = MAX_TEAM_MEMBERS - 1;
                }
                entityNew = gDungeon->teamPokemon[id];
                if (sub_8071A8C(entityNew)) {
                    break;
                }
            }

            a0->actionParameters[0].actionUseIndex = id;
            if (idBefore != id) {
                PlayDungeonCursorSE(0);
            }
            SetLeaderActionToNothing(1);
        }
        else if (GetLeaderActionId() == 29) {
            sub_80637E8(GetLeaderActionContainer());
            SetLeaderActionToNothing(1);
        }
        else if (GetLeaderActionId() == 30) {
            sub_803EAF0(0, NULL);
            sub_8063A70(GetLeaderActionContainer(), TRUE);
            SetLeaderActionToNothing(1);
        }
        else if (GetLeaderActionId() == 51) {
            sub_803EAF0(0, NULL);
            sub_8063A70(GetLeaderActionContainer(), FALSE);
            SetLeaderActionToNothing(1);
        }
        else if (GetLeaderActionId() == 31) {
            sub_803EAF0(0, NULL);
            sub_8063B54(GetLeaderActionContainer());
            SetLeaderActionToNothing(1);
        }
        else if (GetLeaderActionId() == 33) {
            sub_803EAF0(0, NULL);
            sub_8063CF0(GetLeaderActionContainer(), TRUE);
            SetLeaderActionToNothing(1);
        }

        if (GetLeaderActionId() != 0)
            break;
    }

    sub_806A2BC(entityOrg, 0);
    ChangeDungeonCameraPos(&entityOrg->pos, 0, 1, 1);
}

extern s32 gUnknown_202F2D8;
extern s32 sub_8044FB4(u16 param_1);

void sub_80633E4(Entity *entity, EntityInfo *entInfo, u8 a2, Windows *windows, WindowHeader *header, u8 *arg5, s32 arg6, s32 arg7);
void sub_8063698(Entity *entity, u8 a1, u8 a2);
void sub_80637BC(ActionContainer *a0, s32 a1, s32 a2);
void sub_80637A4(ActionContainer *a0, s32 a1);

bool8 ShowDungeonMovesMenu(Entity * entity, u8 a1, u8 a2, s32 a3, s32 a4)
{
    s32 i;
    bool8 ret;
    EntityInfo *entInfo = GetEntInfo(entity);
    bool8 unkBool = TRUE;
    EntityInfo *leaderInfo = GetEntInfo(GetLeader());
    WindowHeader header;
    Windows windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .unk14 = &header,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };
    u8 unk[4];
    bool8 r10;
    s32 r5;
    bool8 bPress;

    gUnknown_202F2D8 = 0;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entInfo->moves.moves[i];

        if (MoveFlagExists(move) && move->moveFlags2 & 2) {
            move->moveFlags2 &= ~(2);
            gUnknown_202F2D8 = i;
        }
    }

    while (1) {
        r5 = 0;
        ret = FALSE;
        r10 = FALSE;
        sub_80633E4(entity, entInfo, a1, &windows, &header, unk, a3, a4);
        while (1) {
            AddMenuCursorSprite_(&gDungeonMenu, unk);
            DungeonRunFrameActions(0x1E);
            if (gRealInputs.repeated & DPAD_DOWN) {
                bool8 rHeld = (gRealInputs.held & R_BUTTON) != 0;
                s32 id = gDungeonMenu.menuIndex;

                if (rHeld) {
                    gUnknown_202F2D8 = unk_SetMoveToLastInLinkedSequence4(entInfo->moves.moves, id);
                    if (id != gUnknown_202F2D8) {
                        PlayDungeonCursorSE(0);
                    }
                    else {
                        PlayDungeonCancelSE();
                    }
                    r10 = TRUE;
                    break;
                }
                else {
                    sub_8013780(&gDungeonMenu, unk_FindMoveEnabledForAIAfter4(entInfo->moves.moves, id));
                    if (id != gDungeonMenu.menuIndex) {
                        PlayDungeonCursorSE(0);
                    }
                }
            }
            if (gRealInputs.repeated & DPAD_UP) {
                bool8 rHeld = (gRealInputs.held & R_BUTTON) != 0;
                s32 id = gDungeonMenu.menuIndex;

                if (rHeld) {
                    gUnknown_202F2D8 = unk_SetMoveToFirstInLinkedSequence4(entInfo->moves.moves, id);
                    if (id != gUnknown_202F2D8) {
                        PlayDungeonCursorSE(0);
                    }
                    else {
                        PlayDungeonCancelSE();
                    }
                    r10 = TRUE;
                    break;
                }
                else {
                    sub_8013780(&gDungeonMenu, sub_8092DB8(entInfo->moves.moves, id));
                    if (id != gDungeonMenu.menuIndex) {
                        PlayDungeonCursorSE(0);
                    }
                }
            }

            if ((gRealInputs.repeated & DPAD_RIGHT) || gDungeonMenu.unk28.dpad_right) {
                SetMonsterActionFields(&leaderInfo->action, 6);
                break;
            }
            if ((gRealInputs.repeated & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
                SetMonsterActionFields(&leaderInfo->action, 7);
                break;
            }

            if ((gRealInputs.pressed & sub_8062D88()) || gDungeonMenu.unk28.a_button) {
                if (a1) {
                    bool8 rHeld = (gRealInputs.held & R_BUTTON) != 0;
                    if (rHeld) {
                        r5 = 3;
                    }
                }
                PlayDungeonConfirmationSE();
                break;
            }

            if (gRealInputs.pressed & START_BUTTON) {
                r5 = 1;
                PlayDungeonStartButtonSE();
                break;
            }
            if (gRealInputs.pressed & SELECT_BUTTON) {
                r5 = 2;
                PlayDungeonStartButtonSE();
                break;
            }
            // Fixme: r0/r1 regswap...
            {
                u32 bPressed = B_BUTTON;
                bPressed &= gRealInputs.pressed;
                if ((bPressed) || gDungeonMenu.unk28.b_button) {
                    PlayDungeonCancelSE();
                    ret = TRUE;
                    break;
                }
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x1E);
        if (leaderInfo->action.action == 6 || leaderInfo->action.action == 7) {
            unkBool = FALSE;
            break;
        }

        if (r10)
            continue;
        if (ret)
            break;

        gUnknown_202F2D8 = gDungeonMenu.menuIndex;
        if (r5 == 1) {
            SetMonsterActionFields(&leaderInfo->action, 0x1D);
            leaderInfo->action.actionParameters[0].actionUseIndex = entity->unk24;
            leaderInfo->action.actionParameters[1].actionUseIndex = gUnknown_202F2D8;
            sub_803EAF0(0, NULL);
            sub_803E708(8, 0x1B);
            ret = FALSE;
            break;
        }

        sub_8063698(entity, a1, a2);
        if (r5 == 3) {
            s32 r6 = sub_8044FB4(0x20);
            if (!CanSubMenuItemBeChosen(r6)) {
                r6 = sub_8044FB4(0x21);
                if (CanSubMenuItemBeChosen(r6)) {
                    sub_80637BC(&leaderInfo->action, r6, GetTeamMemberEntityIndex(entity));
                    break;
                }
            }
            else {
                sub_80637BC(&leaderInfo->action, r6, GetTeamMemberEntityIndex(entity));
                break;
            }
        }
        else if (r5 == 2) {
            if (entInfo->isTeamLeader) {
                s32 r6 = sub_8044FB4(0x1E);
                if (!CanSubMenuItemBeChosen(r6)) {
                    r6 = sub_8044FB4(0x33);
                    if (CanSubMenuItemBeChosen(r6)) {
                        sub_80637BC(&leaderInfo->action, r6, GetTeamMemberEntityIndex(entity));
                        break;
                    }
                }
                else {
                    sub_80637BC(&leaderInfo->action, r6, GetTeamMemberEntityIndex(entity));
                    break;
                }
            }
            else {
                s32 r6 = sub_8044FB4(0x1F);
                if (CanSubMenuItemBeChosen(r6)) {
                    sub_80637BC(&leaderInfo->action, r6, GetTeamMemberEntityIndex(entity));
                    break;
                }
            }
        }

        sub_8009524(2);
        CreateDungeonMenuSubWindow(&windows.id[0], 0x16);
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x1B);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(1);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(1);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & sub_8062D88()) || gDungeonMenu.unk28.a_button) {
                if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                    sub_80637A4(&leaderInfo->action, GetTeamMemberEntityIndex(entity));
                    if (leaderInfo->action.action != 20 && leaderInfo->action.action != 21) {
                        PlayDungeonConfirmationSE();
                    }
                    bPress = FALSE;
                    break;
                }
                PlayDungeonCancelSE();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x1B);
        if (bPress != TRUE) {
            ret = 0;
            break;
        }
    }

    if (unkBool) {
        sub_803EAF0(0, NULL);
        sub_803E708(8, 0x1E);
    }

    return ret;
}

extern const Window gUnknown_8106CAC;
void sub_8063578(s32 a0, Entity *entity, Moves *moves, s32 a3, u8 a4, s32 a5);
extern const u8 *const gUnknown_80FDFE8;

void sub_80633E4(Entity *entity, EntityInfo *entInfo, u8 a2, Windows *windows, WindowHeader *header, u8 *arg5, s32 arg6, s32 arg7)
{
    s32 i, movesCount;
    Window windowNew = gUnknown_8106CAC;

    header->f0 = arg7;
    header->f1 = arg6;
    header->f3 = 0;

    movesCount = 0;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entInfo->moves.moves[i];
        if (MoveFlagExists(move)) {
            movesCount++;
        }
    }

    gDungeonMenu.menuIndex = gUnknown_202F2D8;
    gDungeonMenu.unk1A = movesCount;
    gDungeonMenu.unk1C = 4;
    gDungeonMenu.unk1E = arg6;
    gDungeonMenu.unk20 = arg7;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);

    windows->id[0].height = windows->id[0].unk10 = sub_80095E4(4, 0xC) + 2;
    header->f2 = 13;
    windows->id[0].pos.x = 2;
    windows->id[1] = windows->id[3];
    windows->id[2] = windowNew;
    DungeonShowWindows(windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    gDungeonMenu.unkC = (gUnknown_2027370[0].unk0 + 16) * 8;
    gDungeonMenu.unkE = ((gUnknown_2027370[0].unk2 + 1) * 8) - 2;
    SetMessageArgument_2(gFormatBuffer_Monsters[0], entInfo, 0);
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entInfo->moves.moves[i];

        arg5[i] = 0;
        if (!MoveFlagExists(move)) {
            if (gDungeonMenu.menuIndex == i) {
                gDungeonMenu.menuIndex = 0;
            }
        }
        else if (MoveFlagLinkChain(move)) {
            arg5[i] = 1;
        }
    }

    sub_8063578(4, entity, &entInfo->moves, 0, a2, arg6);
    sub_80073B8(2);
    PrintFormattedStringOnWindow(4, 0, gUnknown_80FDFE8, 2, '\0');
    sub_80073E0(2);
}

extern const u8 gUnknown_8106CC4[];

void sub_8063578(s32 count, Entity *entity, Moves *moves, s32 windowId, u8 a4, s32 a5)
{
    s32 i;
    EntityInfo *entInfo = GetEntInfo(entity);

    sub_80073B8(windowId);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
    PrintFormattedStringOnWindow((a5 * 8) + 10, 0, gUnknown_80FE978, windowId, '\0');
    for (i = 0; i < count; i++) {
        s32 x, y;
        unkStruct_80928C0 movStruct = {0, 106, 0, a4};
        Move *move = &moves->moves[i];

        if (MoveFlagExists(move)) {
            if (entInfo->isTeamLeader) {
                movStruct.unk0 = 2;
            }
            else {
                movStruct.unk0 = 4;
            }

            movStruct.unk8 = (CanMonsterUseMove(entity, move, TRUE) == FALSE);
            BufferMoveName(gFormatBuffer_Items[0], move, &movStruct);
            y = GetMenuEntryYCoord(&gDungeonMenu, i);
            if (MoveFlagLinkChain(move)) {
                x = 13;
            }
            else {
                x = 8;
                if (i != 0) {
                    sub_80078A4(windowId, 12, y - 2, 120, 7);
                }
            }
            PrintFormattedStringOnWindow(x, y, gUnknown_8106CC4, windowId, '\0');
        }
    }

    sub_80073E0(windowId);
}

bool8 sub_8063C88(EntityInfo *entInfo, s32 a1);
bool8 sub_8063DD4(EntityInfo *entInfo, s32 a1);

void sub_8063698(Entity *entity, u8 a1, u8 a2)
{
    EntityInfo *entInfo = GetEntInfo(entity);
    Move *move = &entInfo->moves.moves[gUnknown_202F2D8];

    gDungeonSubMenuItemsCount = 0;
    if (entInfo->isTeamLeader) {
        if (a2) {
            sub_8044F5C(0x14, 0);
        }
        if (MoveFlagExists(move)) {
            if (MoveFlagSet(move)) {
                sub_8044F5C(0x33, 0);
            }
            else {
                sub_8044F5C(0x1E, 0);
            }
        }
    }
    else {
        sub_8044F5C(0x1F, 0);
    }

    if (a1) {
        sub_8044F5C(0x20, 0);
        sub_8044F5C(0x21, 0);
    }
    sub_8044F5C(0x1D, 0);
    if (!a1) {
        sub_8044FF0(0x20);
    }
    else {
        if (!sub_8063C88(entInfo, gUnknown_202F2D8)) {
            sub_8044FF0(0x20);
        }
        if (!sub_8063DD4(entInfo, gUnknown_202F2D8)) {
            sub_8044FF0(0x21);
        }
    }

    if (!sub_8063DD4(entInfo, gUnknown_202F2D8)) {
        sub_8044FF0(0x21);
    }

    if (a2) {
        bool8 unkBool = FALSE;
        if (gUnknown_202F2D8 < MAX_MON_MOVES) {
            unkBool = CanAIUseMove(entity, gUnknown_202F2D8, TRUE) != FALSE;
        }
        if (!unkBool) {
            sub_8044FF0(0x14);
        }
    }

    sub_8045064();
}

void sub_80637A4(ActionContainer *a0, s32 a1)
{
    sub_80637BC(a0, gDungeonMenu.menuIndex, a1);
}

void sub_80637BC(ActionContainer *a0, s32 a1, s32 a2)
{
    SetMonsterActionFields(a0, gUnknown_202EE44[a1].unk0);
    a0->actionParameters[0].actionUseIndex = a2;
    a0->actionParameters[1].actionUseIndex = gUnknown_202F2D8;
}

void sub_8063834(Move *moves, s32 a1, s32 a2);

void sub_80637E8(ActionContainer *a0)
{
    Entity *mon = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    EntityInfo *monInfo = GetEntInfo(mon);

    monInfo->moves.moves[a0->actionParameters[1].actionUseIndex].moveFlags2 |= 2;
    sub_8063834(monInfo->moves.moves, a0->actionParameters[1].actionUseIndex, 4);
}

//
