#include "global.h"
#include "globaldata.h"
#include "dungeon_menu_moves.h"
#include "dungeon_menu_team.h"
#include "dungeon_submenu.h"
#include "structs/str_dungeon.h"
#include "input.h"
#include "structs/map.h"
#include "dungeon_main.h"
#include "dungeon_message.h"
#include "dungeon_action.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "moves.h"
#include "dungeon_music.h"
#include "code_8045A00.h"
#include "string_format.h"
#include "code_803E46C.h"
#include "status_checks_1.h"
#include "dungeon_leader.h"
#include "tile_types.h"
#include "dungeon_visibility.h"
#include "dungeon_movement.h"
#include "menu_input.h"
#include "music.h"
#include "text.h"
#include "code_8044CC8.h"
#include "move_util.h"

extern bool8 ShowDungeonMovesMenu(Entity * entity, u8 a1, u8 a2, s32 a3, s32 a4);
extern void PlayDungeonStartButtonSE(void);
extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);
extern void PlayDungeonCursorSE(u8 param_1);
extern u8 *GetDungeonSubMenuItemString(s32 param_1);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern void sub_8045064(void);
extern void sub_803EAF0(u32, u8 *);
extern void sub_803E708(s32 a0, s32 a1);
extern void sub_8044F5C(u16 param_1, u8 param_2);
extern void sub_8044FF0(u16 param_1);
extern void DungeonShowWindows(WindowTemplates *a0, u8 a1);
extern s32 GetTeamMemberEntityIndex(Entity *pokemon);
extern u32 sub_8062D88(void);
extern void ChangeDungeonCameraPos(DungeonPos *pos, s32 a1, u8 a2, u8 a3);
extern void SetLeaderActionToNothing(u8 a0);
extern void sub_80637E8(ActionContainer *a0);
extern void sub_8063B54(ActionContainer *a0);
extern void sub_8063BB4(ActionContainer *a0);
extern void sub_806752C(ActionContainer *a0);
extern void ShowDungeonSummaryOrIQMenu(ActionContainer *a0, bool8 a1);
extern void sub_8063A70(ActionContainer *a0, bool8 a1);
extern void sub_8063CF0(ActionContainer *a0, bool8 a1);
extern void sub_8067768(ActionContainer *a0);
extern void sub_806A2BC(Entity *a0, u8 a1);
extern bool8 sub_8071A8C(Entity *pokemon);

extern s32 gDungeonSubMenuItemsCount;
extern MenuInputStruct gDungeonMenu;
extern s32 gUnknown_202F2D8;
extern s32 sub_8044FB4(u16 param_1);

extern const u8 *const gUnknown_80FE978;
extern const WindowTemplate gUnknown_8106CAC;
extern const u8 *const gUnknown_80FDFE8;
extern const u8 gUnknown_8106CC4[];

void sub_80633E4(Entity *entity, EntityInfo *entInfo, u8 a2, WindowTemplates *windows, WindowHeader *header, u8 *arg5, s32 arg6, s32 arg7);
void sub_8063698(Entity *entity, u8 a1, u8 a2);
void sub_80637BC(ActionContainer *a0, s32 a1, s32 a2);
void sub_80637A4(ActionContainer *a0, s32 a1);
void sub_8063578(s32 a0, Entity *entity, Moves *moves, s32 a3, u8 a4, s32 a5);
bool8 sub_8063C88(EntityInfo *entInfo, s32 a1);
bool8 sub_8063DD4(EntityInfo *entInfo, s32 a1);
void sub_8063834(Move *moves, s32 a1, s32 a2);

// Needed to match some functions.
static inline u32 CheckPressed(u32 button)
{
    u32 check = button;
    check &= gRealInputs.pressed;
    return check;
}

u32 sub_8062D88(void)
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
        else if (GetLeaderActionId() == ACTION_UNK1D) {
            sub_80637E8(GetLeaderActionContainer());
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_SET_MOVE) {
            sub_803EAF0(0, NULL);
            sub_8063A70(GetLeaderActionContainer(), TRUE);
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_UNSET_MOVE) {
            sub_803EAF0(0, NULL);
            sub_8063A70(GetLeaderActionContainer(), FALSE);
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_UNK1F) {
            sub_803EAF0(0, NULL);
            sub_8063B54(GetLeaderActionContainer());
            SetLeaderActionToNothing(TRUE);
        }
        else if (GetLeaderActionId() == ACTION_UNK21) {
            sub_803EAF0(0, NULL);
            sub_8063CF0(GetLeaderActionContainer(), TRUE);
            SetLeaderActionToNothing(TRUE);
        }

        if (GetLeaderActionId() != ACTION_NOTHING)
            break;
    }

    sub_806A2BC(entityOrg, 0);
    ChangeDungeonCameraPos(&entityOrg->pos, 0, 1, 1);
}

bool8 ShowDungeonMovesMenu(Entity * entity, u8 a1, u8 a2, s32 a3, s32 a4)
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

void sub_80633E4(Entity *entity, EntityInfo *entInfo, u8 a2, WindowTemplates *windows, WindowHeader *header, u8 *arg5, s32 arg6, s32 arg7)
{
    s32 i, movesCount;
    WindowTemplate windowNew = gUnknown_8106CAC;

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
    gDungeonMenu.unkC = (gWindows[0].unk0 + 16) * 8;
    gDungeonMenu.unkE = ((gWindows[0].unk2 + 1) * 8) - 2;
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
    SetMonsterActionFields(a0, gDungeonSubMenu[a1].actionId);
    a0->actionParameters[0].actionUseIndex = a2;
    a0->actionParameters[1].actionUseIndex = gUnknown_202F2D8;
}

void sub_80637E8(ActionContainer *a0)
{
    Entity *mon = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    EntityInfo *monInfo = GetEntInfo(mon);

    monInfo->moves.moves[a0->actionParameters[1].actionUseIndex].moveFlags2 |= 2;
    sub_8063834(monInfo->moves.moves, a0->actionParameters[1].actionUseIndex, 4);
}

void sub_8063834(Move *moves, s32 a1, s32 a2)
{
    WindowTemplates windows;
    WindowHeader header;
    struct subStruct_203B240 *statuses[4];
    s32 i, count, currId;

    sub_80140B4(&windows);
    windows.id[0].unk14 = &header;

    count = 1;
    for (i = a1 + 1; i < a2; i++) {
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

        header.f0 = count;
        header.f1 = currId;
        header.f2 = 12;
        header.f3 = 0;

        gDungeonMenu.unk1E = currId;
        gDungeonMenu.unk20 = count;
        gDungeonMenu.unkC = (gWindows[0].unk0 + 23) * 8;
        gDungeonMenu.unkE = ((gWindows[0].unk2 + 1) * 8) - 2;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk0 = 0;
        sub_801317C(&gDungeonMenu.unk28);
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.unk1A = 0;
        gDungeonMenu.unk1C = 0;
        DungeonShowWindows(&windows, TRUE);
        statusesCount = unk_PrintMoveDescription(currId, &moves[a1 + currId], 0, statuses);
        while (1) {
            if (statusesCount != 0) {
                ShowStatusDescriptionMenuArrow();
            }

            nullsub_34(&gDungeonMenu.unk28, 0);
            DungeonRunFrameActions(0x1C);

            if ((gRealInputs.pressed & sub_8062D88()) || gDungeonMenu.unk28.a_button) {
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

    sub_803EAF0(0, 0);
}

//
