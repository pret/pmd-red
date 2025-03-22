#include "global.h"
#include "globaldata.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "code_803E46C.h"
#include "code_803E724.h"
#include "code_8044CC8.h"
#include "code_8045A00.h"
#include "dungeon_action.h"
#include "dungeon_leader.h"
#include "dungeon_main.h"
#include "dungeon_menu_moves.h"
#include "dungeon_menu_team.h"
#include "dungeon_message.h"
#include "dungeon_movement.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_submenu.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "input.h"
#include "moves.h"
#include "menu_input.h"
#include "move_util.h"
#include "music.h"
#include "pokemon.h"
#include "status_checks_1.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "tile_types.h"

extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);
extern u8 *GetDungeonSubMenuItemString(s32 param_1);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern void sub_8045064(void);
extern void sub_803E708(s32 a0, s32 a1);
extern void DungeonShowWindows(WindowTemplates *a0, u8 a1);
extern s32 GetTeamMemberEntityIndex(Entity *pokemon);
extern void ChangeDungeonCameraPos(DungeonPos *pos, s32 a1, u8 a2, u8 a3);
extern void SetLeaderActionToNothing(u8 a0);
extern void sub_806752C(ActionContainer *a0);
extern void ShowDungeonSummaryOrIQMenu(ActionContainer *a0, bool8 a1);
extern void sub_8067768(ActionContainer *a0);
extern void sub_806A2BC(Entity *a0, u8 a1);
extern bool8 sub_8071A8C(Entity *pokemon);
extern void sub_8083D1C(void);
extern s32 ActionToDungeonSubMenuId(u16 param_1);

extern s32 gDungeonSubMenuItemsCount;
extern MenuInputStruct gDungeonMenu;

extern const u8 *const gUnknown_80FE978;
extern const u8 *const gUnknown_80FDFE8;
extern const u8 *const gUnknown_80F8B40;
extern const u8 *const gUnknown_80F8B64;
extern const u8 *const gUnknown_80F8BB4;
extern const u8 *const gUnknown_80F8B88;
extern const u8 *const gUnknown_80FDF70;
extern const u8 *const gUnknown_80FDF00;

static void ShowMovesMenuWindows(Entity *entity, EntityInfo *entInfo, u8 a2, WindowTemplates *windows, WindowHeader *header, u8 *arg5, s32 arg6, s32 arg7);
static void AddMovesSubMenuOptions(Entity *entity, bool8 addLinkOptions, bool8 addUseMove);
static void SetSubMenuOptionAction(ActionContainer *a0, s32 a1, s32 a2);
static void MenuChosenOptionToAction(ActionContainer *a0, s32 a1);
static void PrintMoveNamesOnWindow(s32 count, Entity *entity, Move *moves, s32 windowId, u8 a4, s32 a5);
static bool8 IsMoveLinkedAndNotCharging(EntityInfo *entInfo, s32 moveId_);
static bool8 IsMoveLinked(EntityInfo *entInfo, s32 id);
static void ShowMovesInfoWindow(Move *moves, s32 firstMoveId, s32 movesCount);
static void sub_8064228(Entity *entity, Move *moves, WindowTemplates *windows, WindowHeader *header);
static void sub_8064310(Move *moves);
static bool8 sub_8064358(Move *moves, s32 id);

EWRAM_DATA static WindowTemplates sMovesMenuWindows = {0};
EWRAM_DATA static s32 sChosenMoveSlotId = 0;

// Needed to match some functions.
static inline u32 CheckPressed(u32 button)
{
    u32 check = button;
    check &= gRealInputs.pressed;
    return check;
}

// In Blue it's 0x401, so A_BUTTON + 0x400 whatever that is
static u32 GetConfirmationButtons(void)
{
    return A_BUTTON;
}

void ShowMovesFromTeamMenu(ActionContainer *a0)
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

        if (GetLeaderActionId() == ACTION_MOVES_MENU_NEXT_MON) {
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
            SetLeaderActionToNothing(TRUE);
        }
        // Everything is the same as in the above if except for add/sub difference.
        else if (GetLeaderActionId() == ACTION_MOVES_MENU_PREV_MON) {
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
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_MOVE_INFO) {
            ActionShowMoveInfo(GetLeaderActionContainer());
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_SET_MOVE) {
            sub_803EAF0(0, NULL);
            ActionSetOrUnsetMove(GetLeaderActionContainer(), TRUE);
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_UNSET_MOVE) {
            sub_803EAF0(0, NULL);
            ActionSetOrUnsetMove(GetLeaderActionContainer(), FALSE);
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_SWITCH_AI_MOVE) {
            sub_803EAF0(0, NULL);
            ActionToggleMoveUsableForAi(GetLeaderActionContainer());
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_DELINK_MOVES) {
            sub_803EAF0(0, NULL);
            ActionDelinkMoves(GetLeaderActionContainer(), TRUE);
            SetLeaderActionToNothing(TRUE);
        }

        if (GetLeaderActionId() != ACTION_NOTHING)
            break;
    }

    sub_806A2BC(entityOrg, 0);
    ChangeDungeonCameraPos(&entityOrg->pos, 0, 1, 1);
}

bool8 ShowDungeonMovesMenu(Entity * entity, bool8 addLinkOptions, bool8 addUseMove, s32 a3, s32 a4)
{
    s32 i;
    bool8 ret;
    EntityInfo *entInfo = GetEntInfo(entity);
    bool8 unkBool = TRUE;
    EntityInfo *leaderInfo = GetEntInfo(GetLeader());
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };
    u8 unk[4];
    bool8 r10;
    s32 r5;
    bool8 bPress;

    sChosenMoveSlotId = 0;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entInfo->moves.moves[i];

        if (MoveFlagExists(move) && move->moveFlags2 & 2) {
            move->moveFlags2 &= ~(2);
            sChosenMoveSlotId = i;
        }
    }

    while (TRUE) {
        r5 = 0;
        ret = FALSE;
        r10 = FALSE;
        ShowMovesMenuWindows(entity, entInfo, addLinkOptions, &windows, &header, unk, a3, a4);
        while (TRUE) {
            AddMenuCursorSprite_(&gDungeonMenu, unk);
            DungeonRunFrameActions(0x1E);
            if (gRealInputs.repeated & DPAD_DOWN) {
                bool8 rHeld = (gRealInputs.held & R_BUTTON) != 0;
                s32 id = gDungeonMenu.menuIndex;

                if (rHeld) {
                    sChosenMoveSlotId = unk_SetMoveToLastInLinkedSequence4(entInfo->moves.moves, id);
                    if (id != sChosenMoveSlotId) {
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
                    sChosenMoveSlotId = unk_SetMoveToFirstInLinkedSequence4(entInfo->moves.moves, id);
                    if (id != sChosenMoveSlotId) {
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

            if ((gRealInputs.pressed & GetConfirmationButtons()) || gDungeonMenu.unk28.a_button) {
                if (addLinkOptions) {
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

            if (CheckPressed(B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                ret = TRUE;
                break;
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

        sChosenMoveSlotId = gDungeonMenu.menuIndex;
        if (r5 == 1) {
            SetMonsterActionFields(&leaderInfo->action, 0x1D);
            leaderInfo->action.actionParameters[0].actionUseIndex = entity->unk24;
            leaderInfo->action.actionParameters[1].actionUseIndex = sChosenMoveSlotId;
            sub_803EAF0(0, NULL);
            sub_803E708(8, 0x1B);
            ret = FALSE;
            break;
        }

        AddMovesSubMenuOptions(entity, addLinkOptions, addUseMove);
        if (r5 == 3) {
            s32 subMenuId = ActionToDungeonSubMenuId(ACTION_LINK_MOVES);
            if (!CanSubMenuItemBeChosen(subMenuId)) {
                subMenuId = ActionToDungeonSubMenuId(ACTION_DELINK_MOVES);
                if (CanSubMenuItemBeChosen(subMenuId)) {
                    SetSubMenuOptionAction(&leaderInfo->action, subMenuId, GetTeamMemberEntityIndex(entity));
                    break;
                }
            }
            else {
                SetSubMenuOptionAction(&leaderInfo->action, subMenuId, GetTeamMemberEntityIndex(entity));
                break;
            }
        }
        else if (r5 == 2) {
            if (entInfo->isTeamLeader) {
                s32 subMenuId = ActionToDungeonSubMenuId(ACTION_SET_MOVE);
                if (!CanSubMenuItemBeChosen(subMenuId)) {
                    subMenuId = ActionToDungeonSubMenuId(ACTION_UNSET_MOVE);
                    if (CanSubMenuItemBeChosen(subMenuId)) {
                        SetSubMenuOptionAction(&leaderInfo->action, subMenuId, GetTeamMemberEntityIndex(entity));
                        break;
                    }
                }
                else {
                    SetSubMenuOptionAction(&leaderInfo->action, subMenuId, GetTeamMemberEntityIndex(entity));
                    break;
                }
            }
            else {
                s32 subMenuId = ActionToDungeonSubMenuId(ACTION_SWITCH_AI_MOVE);
                if (CanSubMenuItemBeChosen(subMenuId)) {
                    SetSubMenuOptionAction(&leaderInfo->action, subMenuId, GetTeamMemberEntityIndex(entity));
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

            if ((gRealInputs.pressed & GetConfirmationButtons()) || gDungeonMenu.unk28.a_button) {
                if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                    MenuChosenOptionToAction(&leaderInfo->action, GetTeamMemberEntityIndex(entity));
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

static void ShowMovesMenuWindows(Entity *entity, EntityInfo *entInfo, u8 a2, WindowTemplates *windows, WindowHeader *header, u8 *arg5, s32 arg6, s32 arg7)
{
    s32 i, movesCount;
    WindowTemplate windowNew = {
        .type = WINDOW_TYPE_NORMAL,
        .pos = {2, 14},
        .width = 26,
        .height = 3,
        .unk10 = 3,
        .unk12 = 0,
        .header = NULL,
    };

    header->count = arg7;
    header->currId = arg6;
    header->f3 = 0;

    movesCount = 0;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entInfo->moves.moves[i];
        if (MoveFlagExists(move)) {
            movesCount++;
        }
    }

    gDungeonMenu.menuIndex = sChosenMoveSlotId;
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
    header->width = 13;
    windows->id[0].pos.x = 2;
    windows->id[1] = windows->id[3];
    windows->id[2] = windowNew;
    DungeonShowWindows(windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    gDungeonMenu.unkC = (gWindows[0].x + 16) * 8;
    gDungeonMenu.unkE = ((gWindows[0].y + 1) * 8) - 2;
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

    PrintMoveNamesOnWindow(4, entity, entInfo->moves.moves, 0, a2, arg6);
    sub_80073B8(2);
    PrintFormattedStringOnWindow(4, 0, gUnknown_80FDFE8, 2, '\0');
    sub_80073E0(2);
}

static void PrintMoveNamesOnWindow(s32 count, Entity *entity, Move *moves, s32 windowId, u8 a4, s32 a5)
{
    s32 i;
    EntityInfo *entInfo = GetEntInfo(entity);

    sub_80073B8(windowId);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
    PrintFormattedStringOnWindow((a5 * 8) + 10, 0, gUnknown_80FE978, windowId, '\0');
    for (i = 0; i < count; i++) {
        s32 x, y;
        unkStruct_80928C0 movStruct = {0, 106, 0, a4};
        Move *move = &moves[i];

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
                    AddDoubleUnderScoreHighlight(windowId, 12, y - 2, 120, 7);
                }
            }
            PrintFormattedStringOnWindow(x, y, _("{MOVE_ITEM_0}"), windowId, '\0');
        }
    }

    sub_80073E0(windowId);
}

static void AddMovesSubMenuOptions(Entity *entity, bool8 addLinkOptions, bool8 addUseMove)
{
    EntityInfo *entInfo = GetEntInfo(entity);
    Move *move = &entInfo->moves.moves[sChosenMoveSlotId];

    gDungeonSubMenuItemsCount = 0;
    if (entInfo->isTeamLeader) {
        if (addUseMove) {
            AddActionToDungeonSubMenu(ACTION_USE_MOVE_PLAYER, 0);
        }
        if (MoveFlagExists(move)) {
            if (MoveFlagSet(move)) {
                AddActionToDungeonSubMenu(ACTION_UNSET_MOVE, 0);
            }
            else {
                AddActionToDungeonSubMenu(ACTION_SET_MOVE, 0);
            }
        }
    }
    else {
        AddActionToDungeonSubMenu(ACTION_SWITCH_AI_MOVE, 0);
    }

    if (addLinkOptions) {
        AddActionToDungeonSubMenu(ACTION_LINK_MOVES, 0);
        AddActionToDungeonSubMenu(ACTION_DELINK_MOVES, 0);
    }
    AddActionToDungeonSubMenu(ACTION_MOVE_INFO, 0);
    if (!addLinkOptions) {
        SetActionUnusableInDungeonSubMenu(ACTION_LINK_MOVES);
    }
    else {
        if (!IsMoveLinkedAndNotCharging(entInfo, sChosenMoveSlotId)) {
            SetActionUnusableInDungeonSubMenu(ACTION_LINK_MOVES);
        }
        if (!IsMoveLinked(entInfo, sChosenMoveSlotId)) {
            SetActionUnusableInDungeonSubMenu(ACTION_DELINK_MOVES);
        }
    }

    if (!IsMoveLinked(entInfo, sChosenMoveSlotId)) {
        SetActionUnusableInDungeonSubMenu(ACTION_DELINK_MOVES);
    }

    if (addUseMove) {
        bool8 moveUnusable = FALSE;
        if (sChosenMoveSlotId < MAX_MON_MOVES) {
            moveUnusable = CanAIUseMove(entity, sChosenMoveSlotId, TRUE) != FALSE;
        }
        if (!moveUnusable) {
            SetActionUnusableInDungeonSubMenu(ACTION_USE_MOVE_PLAYER);
        }
    }

    sub_8045064();
}

static void MenuChosenOptionToAction(ActionContainer *a0, s32 teamId)
{
    SetSubMenuOptionAction(a0, gDungeonMenu.menuIndex, teamId);
}

static void SetSubMenuOptionAction(ActionContainer *a0, s32 subMenuOptionId, s32 teamId)
{
    SetMonsterActionFields(a0, gDungeonSubMenu[subMenuOptionId].actionId);
    a0->actionParameters[0].actionUseIndex = teamId;
    a0->actionParameters[1].actionUseIndex = sChosenMoveSlotId;
}

void ActionShowMoveInfo(ActionContainer *a0)
{
    Entity *mon = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    EntityInfo *monInfo = GetEntInfo(mon);

    monInfo->moves.moves[a0->actionParameters[1].actionUseIndex].moveFlags2 |= 2;
    ShowMovesInfoWindow(monInfo->moves.moves, a0->actionParameters[1].actionUseIndex, MAX_MON_MOVES);
}

static void ShowMovesInfoWindow(Move *moves, s32 firstMoveId, s32 movesCount)
{
    WindowTemplates windows;
    WindowHeader header;
    STATUSTEXTS(statuses);
    s32 i, count, currId;

    sub_80140B4(&windows);
    windows.id[0].header = &header;

    count = 1;
    for (i = firstMoveId + 1; i < movesCount; i++) {
        if (!MoveFlagExists(&moves[i]))
            break;
        if (!MoveFlagLinkChain(&moves[i]))
            break;
        count++;
    }

    currId = 0;
    while (1) {
        s32 statusesCount;
        s32 inputAction = 0;

        header.count = count;
        header.currId = currId;
        header.width = 12;
        header.f3 = 0;

        gDungeonMenu.unk1E = currId;
        gDungeonMenu.unk20 = count;
        gDungeonMenu.unkC = (gWindows[0].x + 23) * 8;
        gDungeonMenu.unkE = ((gWindows[0].y + 1) * 8) - 2;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk0 = 0;
        sub_801317C(&gDungeonMenu.unk28);
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.unk1A = 0;
        gDungeonMenu.unk1C = 0;
        DungeonShowWindows(&windows, TRUE);
        statusesCount = unk_PrintMoveDescription(currId, &moves[firstMoveId + currId], 0, statuses);
        while (1) {
            if (statusesCount != 0) {
                ShowStatusDescriptionMenuArrow();
            }

            nullsub_34(&gDungeonMenu.unk28, 0);
            DungeonRunFrameActions(0x1C);

            if ((gRealInputs.pressed & GetConfirmationButtons()) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                inputAction = 1;
                if (statusesCount != 0) {
                    inputAction = 2;
                }
            }
            else if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                inputAction = 1;
            }
            else if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
                s32 prevId = currId;
                if (currId == 0) {
                    currId = count;
                }
                currId--;
                if (prevId != currId) {
                    PlayDungeonCursorSE(FALSE);
                }
            }
            else if ((CheckPressed(DPAD_RIGHT)) || gDungeonMenu.unk28.dpad_right) {
                s32 prevId = currId;
                if (currId == count - 1) {
                    currId = 0;
                }
                else {
                    currId++;
                }
                if (prevId != currId) {
                    PlayDungeonCursorSE(FALSE);
                }
            }
            else {
                continue;
            }

            break;
        }

        if (inputAction == 1)
            break;

        if (inputAction != 0 && statusesCount != 0) {
            ShowStatusesDescriptionMenu(statusesCount, statuses);
        }
    }

    sub_803EAF0(0, NULL);
}

static const WindowHeader sStatusDescriptionHeader = {
    .count = 1,
    .width = 16,
};

void ShowStatusDescriptionMenu(const StatusText *status, MenuInputStructSub *menuSub)
{
    sub_80140B4(&sMovesMenuWindows);
    sMovesMenuWindows.id[0].header = &sStatusDescriptionHeader;
    DungeonShowWindows(&sMovesMenuWindows, TRUE);
    sub_80073B8(0);

    strcpy(gFormatBuffer_Monsters[0], status->name);
    PrintFormattedStringOnWindow(16, 0, _("{POKEMON_0}"), 0, '\0');
    PrintFormattedStringOnWindow(4, 16, status->desc, 0, '\0');
    sub_80073E0(0);
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unk0 = 0;
    gDungeonMenu.menuIndex = 0;
    gDungeonMenu.unk1A = 0;
    gDungeonMenu.unk1C = 0;
    sub_801317C(menuSub);
}

void ActionSetOrUnsetMove(ActionContainer *a0, bool8 flagToSet)
{
    s32 i;
    Entity *entity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    EntityInfo *entInfo = GetEntInfo(entity);
    Move *move = &entInfo->moves.moves[a0->actionParameters[1].actionUseIndex];
    bool8 wasSet = MoveFlagSet(move) != 0;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        if (MoveFlagExists(&entInfo->moves.moves[i])) {
            entInfo->moves.moves[i].moveFlags &= ~(MOVE_FLAG_SET);
        }
    }

    BufferMoveName(gFormatBuffer_Items[0], move, NULL);
    if (!wasSet) {
        move->moveFlags |= MOVE_FLAG_SET;
    }
    unk_FixLinkedMovesSetEnabled4(entInfo->moves.moves);
    move->moveFlags2 |= 2;
    PlaySoundEffect(0x133);
    if (flagToSet) {
        if (!wasSet) {
            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80F8B40);
        }
        else {
            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80F8B64);
        }
        sub_803E708(0x78, 0x1F);
    }
}

void ActionToggleMoveUsableForAi(ActionContainer *a0)
{
    Entity *entity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    EntityInfo *entInfo = GetEntInfo(entity);
    Move *move = &entInfo->moves.moves[a0->actionParameters[1].actionUseIndex];

    BufferMoveName(gFormatBuffer_Items[0], move, NULL);
    move->moveFlags ^= MOVE_FLAG_ENABLED_FOR_AI;
    unk_FixLinkedMovesSetEnabled4(entInfo->moves.moves);
    move->moveFlags2 |= 2;
    PlaySoundEffect(0x133);
}

void ActionLinkMoves(ActionContainer *a0)
{
    s32 linkedCount;
    Entity *entity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    EntityInfo *entInfo = GetEntInfo(entity);
    s32 id = a0->actionParameters[1].actionUseIndex;

    BufferMoveName(gFormatBuffer_Items[0], &entInfo->moves.moves[id], NULL);
    entInfo->moves.moves[id].moveFlags2 |= 2;
    linkedCount = 0;
    for (id++; id < MAX_MON_MOVES; id++) {
        if (!MoveFlagExists(&entInfo->moves.moves[id]))
            break;
        if (!MoveFlagLinkChain(&entInfo->moves.moves[id]))
            break;
        if (++linkedCount >= MAX_MON_MOVES)
            break;
    }

    if (!MoveFlagExists(&entInfo->moves.moves[id]))
        id = MAX_MON_MOVES;

    if (id < MAX_MON_MOVES) {
        Move *move = &entInfo->moves.moves[id];
        move->moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
        BufferMoveName(gFormatBuffer_Items[1], move, NULL);
    }
    unk_FixLinkedMovesSetEnabled4(entInfo->moves.moves);
    PlaySoundEffect(0x133);
}

static bool8 IsMoveLinkedAndNotCharging(EntityInfo *entInfo, s32 moveId_)
{
    s32 i;
    bool8 ret = FALSE;
    s32 moveId = moveId_;

    if (DoesMoveCharge(entInfo->moves.moves[moveId].id))
        return FALSE;

    moveId++;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entInfo->moves.moves[moveId];

        if (DoesMoveCharge(move->id))
            return FALSE;

        if (!MoveFlagExists(move))
            break;
        if (!MoveFlagLinkChain(move)) {
            ret = TRUE;
            break;
        }
        if (++moveId >= MAX_MON_MOVES)
            break;
    }

    return ret;
}

void ActionDelinkMoves(ActionContainer *a0, bool8 showMsg)
{
    s32 linkedCount;
    Entity *entity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    EntityInfo *entInfo = GetEntInfo(entity);
    s32 id = a0->actionParameters[1].actionUseIndex;
    bool8 unlInked = FALSE;

    BufferMoveName(gFormatBuffer_Items[0], &entInfo->moves.moves[id], NULL);
    entInfo->moves.moves[id].moveFlags2 |= 2;

    id++;
    for (linkedCount = 0; linkedCount < MAX_MON_MOVES && id < MAX_MON_MOVES; id++, linkedCount++) {
        Move *move = &entInfo->moves.moves[id];
        if (MoveFlagLinkChain(move)) {
            move->moveFlags &= ~(MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN);
            unlInked = TRUE;
        }
        else {
            break;
        }
    }

    unk_FixLinkedMovesSetEnabled4(entInfo->moves.moves);
    PlaySoundEffect(0x133);
    if (showMsg) {
        if (unlInked) {
            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80F8B88);
        }
        else {
            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80F8BB4);
        }
        sub_803E708(0x78, 0x1F);
    }
}

static bool8 IsMoveLinked(EntityInfo *entInfo, s32 id)
{
    bool8 linkFound = FALSE;
    s32 linkedCount;

    id++;
    for (linkedCount = 0; linkedCount < MAX_MON_MOVES && id < MAX_MON_MOVES; linkedCount++) {
        Move *move = &entInfo->moves.moves[id];

        if (MoveFlagLinkChain(move)) {
            linkFound = TRUE;
            id++;
        }
        else {
            break;
        }
    }

    if (linkFound)
        return TRUE;
    return FALSE;
}

static void sub_8063E30(Move *moves, s32 id)
{
    s32 i;

    id++;
    for (i = 0; i < 8 && id < 8; id++, i++) {
        if (MoveFlagLinkChain(&moves[id])) {
            moves[id].moveFlags &= ~(MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN);
        }
        else {
            break;
        }
    }

    unk_FixLinkedMovesSetEnabled8(moves);
}

static inline void ResetMoveFlags(Move *move)
{
    move->moveFlags = 0;
}

bool8 sub_8063E70(Entity *entity, Move *moves, bool8 showYesNoBox, bool8 allowBPress)
{
    s32 i, count;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };
    Move movesLocal[8];

    sChosenMoveSlotId = 0;
    while (1) {
        s32 inputAction;
        s32 yesNoAnswer;

        sub_8064228(entity, moves, &windows, &header);
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x1E);
            if (gRealInputs.repeated & DPAD_DOWN) {
                s32 prev = gDungeonMenu.menuIndex;

                sub_8013780(&gDungeonMenu, unk_FindMoveEnabledForAIAfter8(moves, prev));
                if (prev != gDungeonMenu.menuIndex) {
                    PlayDungeonCursorSE(FALSE);
                }
            }
            if (gRealInputs.repeated & DPAD_UP) {
                s32 prev = gDungeonMenu.menuIndex;

                sub_8013780(&gDungeonMenu, unk_FindMoveEnabledForAIBefore8(moves, prev));
                if (prev != gDungeonMenu.menuIndex) {
                    PlayDungeonCursorSE(FALSE);
                }
            }
            ASM_MATCH_TRICK(sChosenMoveSlotId);
            if ((gRealInputs.pressed & GetConfirmationButtons()) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                inputAction = 0;
                break;
            }
            if (gRealInputs.pressed & START_BUTTON) {
                PlayDungeonStartButtonSE();
                inputAction = 2;
                break;
            }
            if (allowBPress && (CheckPressed(B_BUTTON) || gDungeonMenu.unk28.b_button)) {
                PlayDungeonCancelSE();
                inputAction = 1;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x1E);
        if (inputAction == 1) {
            sChosenMoveSlotId = -1;
        }
        else {
            sChosenMoveSlotId = gDungeonMenu.menuIndex;

            if (inputAction == 2) {
                sub_803EAF0(0, NULL);
                sub_803E708(8, 0x1B);
                ASM_MATCH_TRICK(sChosenMoveSlotId);
                ShowMovesInfoWindow(moves, sChosenMoveSlotId, MAX_MON_MOVES);
                continue;
            }

            sub_8064310(moves);
            CreateDungeonMenuSubWindow(&windows.id[0], 22);

            while (1) {
                AddMenuCursorSprite(&gDungeonMenu);
                DungeonRunFrameActions(0x1B);

                if (gRealInputs.repeated & DPAD_DOWN) {
                    PlayDungeonCursorSE(TRUE);
                    MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    PlayDungeonCursorSE(TRUE);
                    MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
                }

                if ((gRealInputs.pressed & GetConfirmationButtons()) || gDungeonMenu.unk28.a_button) {
                    if (CanSubMenuItemBeChosen(gDungeonMenu.menuIndex)) {
                        if (gDungeonMenu.menuIndex == 2) {
                            PlayDungeonConfirmationSE();
                        }
                        else {
                            sub_8083D1C();
                        }
                        inputAction = 0;
                        break;
                    }
                    PlayDungeonCancelSE();
                }
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                    PlayDungeonCancelSE();
                    inputAction = 1;
                    break;
                }
            }

            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x1b);
            sub_803EAF0(0, NULL);
            if (inputAction == 1)
                continue;
            if (gDungeonMenu.menuIndex == 1) {
                sub_8063E30(moves, sChosenMoveSlotId);
                continue;
            }
            if (gDungeonMenu.menuIndex == 2) {
                ShowMovesInfoWindow(moves, sChosenMoveSlotId, 8);
                continue;
            }
        }

        if (sChosenMoveSlotId < 0)
            break;

        if (showYesNoBox) {
            bool8 linked = FALSE;
            Move *move = &moves[sChosenMoveSlotId];
            s32 nextMoveId = sChosenMoveSlotId + 1;

            if (nextMoveId < 8 && MoveFlagExists(&moves[nextMoveId])) {
                linked = MoveFlagLinkChain(&moves[nextMoveId]) != 0;
            }
            BufferMoveName(gFormatBuffer_Items[0], move, NULL);
            yesNoAnswer = DisplayDungeonYesNoMessage(NULL, (!linked) ? gUnknown_80FDF70 : gUnknown_80FDF00, FALSE);
        }
        else {
            yesNoAnswer = 1;
        }

        if (yesNoAnswer == 1) {
            moves[sChosenMoveSlotId].moveFlags = 0;
            for (i = sChosenMoveSlotId + 1; i < 8; i++) {
                Move *move = &moves[i];
                if (!MoveFlagExists(move))
                    break;
                if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
                    break;

                ResetMoveFlags(move);
            }

            count = 0;
            for (i = 0; i < 8; i++) {
                Move *move = &moves[i];
                if (MoveFlagExists(move)) {
                    movesLocal[count++] = *move;
                }
            }

            for (; count < 8; count++) {
                ResetMoveFlags(&movesLocal[count]);
            }

            for (i = 0; i < 8; i++) {
                moves[i] = movesLocal[i];
            }

            break;
        }
    }

    if (sChosenMoveSlotId < 0)
        return FALSE;

    return TRUE;
}

static void sub_8064228(Entity *entity, Move *moves, WindowTemplates *windows, WindowHeader *header)
{
    s32 i, count;

    header->count = 1;
    header->currId = 0;
    header->f3 = 0;

    count = 0;
    for (i = 0; i < 8; i++) {
        if (MoveFlagExists(&moves[i])) {
            count++;
        }
    }

    gDungeonMenu.menuIndex = sChosenMoveSlotId;
    gDungeonMenu.unk1A = count;
    gDungeonMenu.unk1C = count;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows->id[0].height = windows->id[0].unk10 = sub_80095E4(count, 12) + 2;
    header->width = 14;
    windows->id[0].pos.x = 2;
    windows->id[1] = windows->id[3];
    windows->id[2] = windows->id[3];
    DungeonShowWindows(windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    SetMessageArgument_2(gFormatBuffer_Monsters[0], GetEntInfo(entity), 0);
    PrintMoveNamesOnWindow(count, entity, moves, 0, 0, 0);
}

static void sub_8064310(Move *moves)
{
    gDungeonSubMenuItemsCount = 0;
    AddActionToDungeonSubMenu(ACTION_UNK22, 0);
    AddActionToDungeonSubMenu(ACTION_DELINK_MOVES, 0);
    if (!sub_8064358(moves, sChosenMoveSlotId)) {
        SetActionUnusableInDungeonSubMenu(ACTION_DELINK_MOVES);
    }
    AddActionToDungeonSubMenu(ACTION_MOVE_INFO, 0);
}

static bool8 sub_8064358(Move *moves, s32 id)
{
    bool8 linkFound = FALSE;
    s32 linkedCount;

    id++;
    for (linkedCount = 0; linkedCount < 8 && id < 8; linkedCount++) {
        Move *move = &moves[id];

        if (MoveFlagLinkChain(move)) {
            linkFound = TRUE;
            id++;
        }
        else {
            break;
        }
    }

    if (linkFound)
        return TRUE;
    return FALSE;
}
