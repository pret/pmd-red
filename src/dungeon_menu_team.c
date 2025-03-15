#include "global.h"
#include "globaldata.h"
#include "dungeon_menu_team.h"
#include "dungeon_menu_moves.h"
#include "dungeon_submenu.h"
#include "structs/str_dungeon.h"
#include "number_util.h"
#include "input.h"
#include "structs/map.h"
#include "dungeon_main.h"
#include "dungeon_message.h"
#include "dungeon_action.h"
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
#include "dungeon_map_access.h"
#include "status_checks_1.h"
#include "weather.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "tile_types.h"
#include "dungeon_visibility.h"
#include "dungeon_movement.h"
#include "menu_input.h"
#include "music.h"
#include "items.h"
#include "pokemon_3.h"
#include "text.h"
#include "code_806CD90.h"
#include "code_8044CC8.h"
#include "code_801B3C0.h"
#include "dungeon_capabilities.h"
#include "constants/tactic.h"
#include "structs/struct_sub80095e4.h"
#include "structs/str_text.h"
#include "code_8097DD0.h"
#include "move_util.h"

extern Item *sub_8044D90(Entity *, s32, u32);
extern void sub_806A6E8(Entity *);
bool8 sub_807EF48(void);
void sub_806A2BC(Entity *a0, u8 a1);
bool8 sub_80701A4(Entity *a0);
void sub_803E708(s32 a0, s32 a1);
void sub_8075680(u32);
void sub_806A914(u8 a0, u8 a1, u8 a2);
void sub_80978C8(s16 a0);
bool8 sub_8094C48(void);
void sub_803E724(s32 a0);
void HandleTalkFieldAction(Entity *);
bool8 sub_8044B28(void);
bool8 IsNotAttacking(Entity *param_1, bool8 param_2);
bool8 sub_8070F80(Entity * pokemon, s32 direction);
void sub_806752C(ActionContainer *a0);
void sub_8067768(ActionContainer *a0);
extern void sub_80643AC(Entity *pokemon);
extern bool8 sub_8070F14(Entity * pokemon, s32 direction);
extern Entity *sub_80696A8(Entity *a0);
extern u8 sub_806A538(s32);
extern void sub_803EAF0(u32, u8 *);
extern void sub_803F508(Entity *);
extern void sub_8041AD0(Entity *pokemon);
extern void sub_8041AE0(Entity *pokemon);
extern void sub_807EC28(bool8);
extern u8 *GetDungeonSubMenuItemString(s32 param_1);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern s32 gDungeonSubMenuItemsCount;
extern const u8 gUnknown_8106B50[];
extern void DungeonShowWindows(WindowTemplates *a0, u8 a1);
extern Item * sub_8044CC8(Entity *param_1, ActionParameter *param_2, UNUSED s32 a3);
extern void AddActionToDungeonSubMenu(u16 actionId, u8 param_2);
extern void SetActionUnusableInDungeonSubMenu(u16 param_1);
extern u16 sub_8044DC8(Item *param_1);
extern bool8 sub_8046F00(Item *item);
extern void sub_8045064(void);
extern void sub_8070968(u8 *buffer, EntityInfo *entityInfo, s32 colorNum);
extern bool8 CanLeaderSwitch(u8 dungeon);
extern void GetAvailTacticsforLvl(u8 *tacticsBuffer, s32 pokeLevel);
extern void sub_8069844(struct unkStruct_808FF20 *param_1, Entity *target);
extern u32 sub_8014140(s32 a0, const void *a1);
extern char* sub_808E4FC(s32 a1);
extern char* sub_808E51C(s32 a1);
extern void sub_8045C18(u8 *buffer, Item *item);
extern bool32 sub_8069D18(DungeonPos *a0, Entity *a1);

extern u8 gUnknown_202EE00;
extern Entity *gLeaderPointer;
extern MenuInputStruct gDungeonMenu;
extern s32 gDungeonFramesCounter;
extern u8 gUnknown_202EE39;

extern const u8 *gUnknown_80FE940;
extern const u8 *const gUnknown_80FE954;
extern const u8 gUnknown_8106BEC[];
extern const u8 gUnknown_8106BF4[];
extern const u8 *const gUnknown_80FE95C;
extern const u8 *const gUnknown_80FE960;
extern const u8 *const gUnknown_80FE964;
extern const u8 *const gUnknown_80FE978;
extern const u8 *const gWhichTextPtr2;

EWRAM_DATA s32 gTeamMenuChosenId = 0;
static UNUSED EWRAM_DATA u8 sUnused[4] = {0};
EWRAM_DATA static SpriteOAM gUnknown_202F268 = {0};
EWRAM_DATA static WindowHeader sTeamWindowHeader = {0};

struct UnkFieldTeamMenuStruct
{
    s32 unk0;
    s32 unk4[MAX_TEAM_MEMBERS];
    u8 unk14[MAX_TEAM_MEMBERS];
};

static void PrintOnDungeonTeamMenu(struct UnkFieldTeamMenuStruct *a0, WindowTemplates *windows, bool8 a2);
static void AddTeamSubMenuOptions(struct UnkFieldTeamMenuStruct *a0);
static void ChosenSubMenuToAction(ActionContainer *a0, struct UnkFieldTeamMenuStruct *a1);
static void PrintMonTactics(s32 firstId, u8 *tacticIds, EntityInfo *mon, s32 windowId);
static void ShowUpArrowSprite(void);
static void ShowDownArrowSprite(void);
static void ShowIqDescriptionWindow(u8 iqSkillId);
static void ShowTacticDescriptionWindow(u8 tacticId);
static void ShowStatusInfoWindow(s32 a0);
static void PrintMoveNamesOnBottomWindow(Entity *entity);
static void PrintItemNameOnBottomWindow(Entity *entity);
static void ResetDungeonMenu(void);

// Struct only used in Blue maybe?
static const u8 gUnknown_8106B8C[] = {1, 0, 56, 0, 0, 0, 24, 0, 24, 0, 0, 0, 2, 0, 56, 0, 104, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

bool8 ShowDungeonTeamMenu(Entity *a0)
{
    s32 i;
    bool32 r10, ret;
    struct UnkFieldTeamMenuStruct sp;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 14,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &sTeamWindowHeader,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityIsValid(teamMon)) {
            GetEntInfo(teamMon)->unk157 = TRUE;
        }
    }

    if (!gDungeon->unk644.hasInventory) {
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
        AddTeamSubMenuOptions(&sp);
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
                    ChosenSubMenuToAction(&GetEntInfo(a0)->action, &sp);
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

static void PrintOnDungeonTeamMenu(struct UnkFieldTeamMenuStruct *a0, WindowTemplates *windows, bool8 a2)
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

    sTeamWindowHeader.count = 1;
    sTeamWindowHeader.currId = 0;
    sTeamWindowHeader.f3 = 0;
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
    sTeamWindowHeader.width = 8;
    if (a2) {
        windows->id[1] = windows->id[3];
    }

    DungeonShowWindows(windows, 1);
    sub_80137B0(&gDungeonMenu, 0);
    sub_80073B8(0);
    if (r10) {
        PrintFormattedStringOnWindow(0xC, 0, _("$t"), 0, 0);
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
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_RED_TINY}"));
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 2) {
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_RED_SMALL}"));
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 3) {
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_RED_MEDIUM}"));
                    }
                    else {
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_RED_LARGE}"));
                    }
                }
                else {
                    if (monInfo->HP <= monInfo->maxHPStat / 4) {
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_YELLOW_TINY}"));
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 2) {
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_YELLOW_SMALL}"));
                    }
                    else if (monInfo->HP <= (monInfo->maxHPStat / 4) * 3) {
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_YELLOW_MEDIUM}"));
                    }
                    else {
                        InlineStrcpy(gFormatBuffer_Monsters[1], _("{HEART_YELLOW_LARGE}"));
                    }
                }

                gFormatArgs[0] = monInfo->HP;
                gFormatArgs[1] = monInfo->maxHPStat;
                y = GetMenuEntryYCoord(&gDungeonMenu, i);
                if (monInfo->isTeamLeader) {
                    PrintFormattedStringOnWindow(9, y, _("{STAR_BULLET}{POKEMON_0}{UNK_MACRO_3D}{0x59}{POKEMON_1}"), 0, 0);
                }
                else {
                    PrintFormattedStringOnWindow(9, y, _("{ICON_BLANK}{POKEMON_0}{UNK_MACRO_3D}{0x59}{POKEMON_1}"), 0, 0);
                }
            }
        }
    }

    sub_80073E0(0);
}

static void AddTeamSubMenuOptions(struct UnkFieldTeamMenuStruct *a0)
{
    Entity *teamMon;
    EntityInfo *monInfo;

    gDungeonSubMenuItemsCount = 0;
    teamMon = gDungeon->teamPokemon[a0->unk4[gDungeonMenu.menuIndex]];
    monInfo = GetEntInfo(teamMon);
    AddActionToDungeonSubMenu(ACTION_CHECK_SUMMARY, 0);
    AddActionToDungeonSubMenu(ACTION_CHECK_MOVES, 0);
    if (!monInfo->isTeamLeader) {
        if (!gDungeon->unk644.unk19 && (monInfo->joinedAt.id != DUNGEON_JOIN_LOCATION_PARTNER || gDungeon->unk644.unk18)) {
            AddActionToDungeonSubMenu(0x34, 0);
        }
        AddActionToDungeonSubMenu(ACTION_TALK_MENU, 0);
    }
    AddActionToDungeonSubMenu(0x30, 0);
    if (!monInfo->isTeamLeader) {
        AddActionToDungeonSubMenu(ACTION_CHANGE_TACTICS, 0);
    }
    if (!monInfo->isTeamLeader && gDungeon->unk644.unk18 && CanLeaderSwitch(gDungeon->unk644.dungeonLocation.id)) {
        bool32 r5;

        AddActionToDungeonSubMenu(0x3B, 0);
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
            SetActionUnusableInDungeonSubMenu(0x3B);
        }
    }

    if (IsExperienceLocked(monInfo->joinedAt.id)) {
        SetActionUnusableInDungeonSubMenu(ACTION_CHECK_MOVES);
        SetActionUnusableInDungeonSubMenu(0x3B);
        SetActionUnusableInDungeonSubMenu(ACTION_CHANGE_TACTICS);
        SetActionUnusableInDungeonSubMenu(ACTION_VIEW_IQ);
        SetActionUnusableInDungeonSubMenu(0x34);
    }

    sub_8045064();
}

static void ChosenSubMenuToAction(ActionContainer *a0, struct UnkFieldTeamMenuStruct *a1)
{
    SetMonsterActionFields(a0, gDungeonSubMenu[gDungeonMenu.menuIndex].actionId);
    a0->actionParameters[0].actionUseIndex = a1->unk4[a1->unk0];
}

void ShowDungeonTacticsMenu(ActionContainer *a0)
{
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 14,
                .unk10 = 18,
                .unk12 = 2,
                .header = &sTeamWindowHeader,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
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

        sTeamWindowHeader.count = 1;
        sTeamWindowHeader.currId = 0;
        sTeamWindowHeader.width = 10;
        sTeamWindowHeader.f3 = 0;
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
                ShowDownArrowSprite();
            }
            if (scrollFirstId != 0) {
                ShowUpArrowSprite();
            }
            DungeonRunFrameActions(0x3D);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(1);
                if (gDungeonMenu.menuIndex == 7) {
                    if (tacticIds[8] != TACTIC_UNUSED) {
                        for (i = 0; i < 6; i++) {
                            ScrollDownWindowFunc(0);
                            DungeonRunFrameActions(0x3D);
                        }
                        scrollFirstId++;
                    }
                    menuIndex = 7;
                    break;
                }
                MoveMenuCursorDownWrapAround(&gDungeonMenu, FALSE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(1);
                if (gDungeonMenu.menuIndex == 0) {
                    if (scrollFirstId != 0) {
                        for (i = 0; i < 6; i++) {
                            ScrollUpWindowFunc(0);
                            DungeonRunFrameActions(0x3D);
                        }
                        scrollFirstId--;
                    }
                    menuIndex = 0;
                    break;
                }
                MoveMenuCursorUpWrapAround(&gDungeonMenu, FALSE);
            }
            if (gRealInputs.pressed & START_BUTTON) {
                u32 tacticId = tacticIds[gDungeonMenu.menuIndex];
                menuIndex = gDungeonMenu.menuIndex;
                PlayDungeonStartButtonSE();
                ShowTacticDescriptionWindow(tacticId);
                loopBreak = FALSE;
                break;
            }
            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                bool32 changed;

                u32 tacticId = tacticIds[gDungeonMenu.menuIndex];
                menuIndex = gDungeonMenu.menuIndex;
                ResetDungeonMenu();
                PlayDungeonConfirmationSE();
                gDungeonSubMenuItemsCount = 0;
                AddActionToDungeonSubMenu(0x2F, 0);
                AddActionToDungeonSubMenu(0xC, 0);
                if (CheckVariousStatuses2(teamMon, TRUE)) {
                    SetActionUnusableInDungeonSubMenu(0x2F);
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
                        ShowTacticDescriptionWindow(tacticId);
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

static void PrintMonTactics(s32 firstId, u8 *tacticIds, EntityInfo *mon, s32 windowId)
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
            PrintFormattedStringOnWindow(0x10, y, _("{STAR_BULLET}{POKEMON_0}"), windowId, 0);
        }
        else {
            PrintFormattedStringOnWindow(0x10, y, _("{ICON_BLANK}{POKEMON_0}"), windowId, 0);
        }
    }

    sub_80073E0(windowId);
}

enum
{
    SUB_WINDOW_NONE,
    SUB_WINDOW_STATUS,
    SUB_WINDOW_STATS,
    SUB_WINDOW_FEATUERS,
    SUB_WINDOW_IQ,
    SUB_WINDOW_INFO,
};

// The way this function was written, it seems that they planned to put IQ skills in the Summary Menu first, but later decided to create a separate menu for it.
void ShowDungeonSummaryOrIQMenu(ActionContainer *a0, bool8 showIq)
{
    s32 subWindowIds[6];
    struct unkStruct_808FF20 unkMonStruct;
    struct UnkInfoTabStruct unkInfoTabStruct;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 14,
                .unk10 = 18,
                .unk12 = 2,
                .header = &sTeamWindowHeader,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };
    s32 r8;
    Entity *entity;
    s32 currSubWindowId;
    s32 totalSubWindows;
    EntityInfo *entityInfo;

    currSubWindowId = 0;
    r8 = 0;
    entity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    entityInfo = GetEntInfo(entity);

    if (IsExperienceLocked(entityInfo->joinedAt.id)) {
        subWindowIds[0] = SUB_WINDOW_STATUS;
        subWindowIds[1] = SUB_WINDOW_NONE;
        subWindowIds[2] = SUB_WINDOW_NONE;
        subWindowIds[3] = SUB_WINDOW_NONE;
        subWindowIds[4] = SUB_WINDOW_NONE;
        subWindowIds[5] = SUB_WINDOW_NONE;
        totalSubWindows = 1;
    }
    else if (showIq) {
        subWindowIds[0] = SUB_WINDOW_IQ;
        subWindowIds[1] = SUB_WINDOW_NONE;
        subWindowIds[2] = SUB_WINDOW_NONE;
        subWindowIds[3] = SUB_WINDOW_NONE;
        subWindowIds[4] = SUB_WINDOW_NONE;
        subWindowIds[5] = SUB_WINDOW_NONE;
        totalSubWindows = 1;
    }
    else {
        subWindowIds[0] = SUB_WINDOW_STATS;
        subWindowIds[1] = SUB_WINDOW_STATUS;
        subWindowIds[2] = SUB_WINDOW_FEATUERS;
        subWindowIds[3] = SUB_WINDOW_INFO;
        subWindowIds[4] = SUB_WINDOW_NONE;
        subWindowIds[5] = SUB_WINDOW_NONE;
        totalSubWindows = 4;
    }

    unkMonStruct.unk40 = 0;
    unkMonStruct.unk56 = 0;
    gDungeonMenu.menuIndex = 0;

    while (1) {
        bool8 loopBreak = FALSE;
        bool8 hasIqSkills = FALSE;
        bool8 hasStatusProblems = FALSE;
        bool8 addCursorSprite = TRUE;
        Window *mainWindow = &gWindows[0];

        sTeamWindowHeader.count = totalSubWindows;
        sTeamWindowHeader.currId = currSubWindowId;
        sTeamWindowHeader.width = 10;
        sTeamWindowHeader.f3 = 0;
        DungeonShowWindows(&windows, TRUE);
        sub_8069844(&unkMonStruct, entity);
        CreatePokemonInfoTabScreen(subWindowIds[currSubWindowId], currSubWindowId, &unkMonStruct, &unkInfoTabStruct, 0);
        gDungeonMenu.unk1E = currSubWindowId;
        gDungeonMenu.unk20 = totalSubWindows;
        gDungeonMenu.unkC = (mainWindow->x + 15) * 8;
        gDungeonMenu.unkE = ((mainWindow->y + 1) * 8) - 2;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk0 = 0;
        sub_801317C(&gDungeonMenu.unk28);
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.unk1A = 0;
        gDungeonMenu.unk1C = 0;

        if (subWindowIds[currSubWindowId] == SUB_WINDOW_STATUS) {
            s32 i;

            for (i = 0; i < 8; i++) {
                if (unkInfoTabStruct.unkC[i] == 0) {
                    break;
                }
            }

            if (i != 0) {
                hasStatusProblems = TRUE;
                gDungeonMenu.unk1A = i;
                gDungeonMenu.unk1C = 8;
                sub_80137B0(&gDungeonMenu, 0);
            }
            gDungeonMenu.menuIndex = r8;
        }
        else if (subWindowIds[currSubWindowId] == SUB_WINDOW_IQ) {
            s32 i;

            for (i = 0; i < 8; i++) {
                if (unkInfoTabStruct.unk0[i] == 0) {
                    break;
                }
            }

            if (i != 0) {
                hasIqSkills = TRUE;
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
            if (hasIqSkills) {
                if (unkInfoTabStruct.unk0[8] != 0) {
                    r5 = TRUE;
                    ShowDownArrowSprite();
                }
                if (unkMonStruct.unk40 != 0) {
                    r6 = TRUE;
                    ShowUpArrowSprite();
                }
            }
            if (hasStatusProblems) {
                if (unkInfoTabStruct.unkC[8] != 0) {
                    r5 = TRUE;
                    ShowDownArrowSprite();
                }
                if (unkMonStruct.unk56 != 0) {
                    r6 = TRUE;
                    ShowUpArrowSprite();
                }
            }

            DungeonRunFrameActions(0x1C);
            if (sTeamWindowHeader.count > 1 && !sub_80048C8()) {
                if ((gRealInputs.pressed & DPAD_RIGHT) || gDungeonMenu.unk28.dpad_right) {
                    PlayDungeonCursorSE(0);
                    currSubWindowId++;
                    if (subWindowIds[currSubWindowId] == SUB_WINDOW_NONE) {
                        currSubWindowId = 0;
                    }
                    break;
                }
                if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
                    PlayDungeonCursorSE(0);
                    currSubWindowId--;
                    if (currSubWindowId == -1) {
                        currSubWindowId = 5;
                        while (subWindowIds[currSubWindowId] == SUB_WINDOW_NONE) {
                            currSubWindowId--;
                        }
                    }
                    break;
                }
            }

            if (hasStatusProblems) {
                if (unkVar == 2 && r5) {
                    PlayDungeonCursorSE(0);
                    if (unkInfoTabStruct.unkC[8] != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollDownWindowFunc(0);
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
                                ScrollDownWindowFunc(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk56++;
                        }
                        r8 = 7;
                        break;
                    }
                    else {
                        MoveMenuCursorDownWrapAround(&gDungeonMenu, FALSE);
                    }
                }

                if (unkVar == 1 && r6) {
                    if (unkMonStruct.unk56 != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollUpWindowFunc(0);
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
                                ScrollUpWindowFunc(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk56--;
                        }
                        r8 = 0;
                        break;
                    }
                    else {
                        MoveMenuCursorUpWrapAround(&gDungeonMenu, FALSE);
                    }
                }
            }
            else if (hasIqSkills) {
                if (unkVar == 2 && r5) {
                    if (unkInfoTabStruct.unk0[8] != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollDownWindowFunc(0);
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
                                ScrollDownWindowFunc(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk40++;
                        }
                        r8 = 7;
                        break;
                    }
                    else {
                        MoveMenuCursorDownWrapAround(&gDungeonMenu, FALSE);
                    }
                }

                if (unkVar == 1 && r6) {
                    if (unkMonStruct.unk40 != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            ScrollUpWindowFunc(0);
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
                                ScrollUpWindowFunc(0);
                                DungeonRunFrameActions(28);
                            }
                            unkMonStruct.unk40--;
                        }
                        r8 = 0;
                        break;
                    }
                    else {
                        MoveMenuCursorUpWrapAround(&gDungeonMenu, FALSE);
                    }
                }
            }

            if (sub_80048C8())
                continue;

            if (gRealInputs.pressed & START_BUTTON) {
                if (hasStatusProblems) {
                    s32 var = unkInfoTabStruct.unkC[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    PlayDungeonStartButtonSE();
                    ShowStatusInfoWindow(var);
                    addCursorSprite = FALSE;
                    loopBreak = FALSE;
                    break;
                }
                else if (hasIqSkills) {
                    s32 iqSkillId = unkInfoTabStruct.unk0[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    PlayDungeonStartButtonSE();
                    ShowIqDescriptionWindow(iqSkillId);
                    addCursorSprite = FALSE;
                    loopBreak = FALSE;
                    break;
                }
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                if (hasStatusProblems) {
                    s32 var = unkInfoTabStruct.unkC[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    ResetDungeonMenu();
                    gDungeonSubMenuItemsCount = 0;
                    PlayDungeonConfirmationSE();
                    AddActionToDungeonSubMenu(0xC, 0);
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
                            ShowStatusInfoWindow(var);
                            addCursorSprite = FALSE;
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
                else if (hasIqSkills) {
                    bool8 aPress = FALSE;
                    s32 var = unkInfoTabStruct.unk0[gDungeonMenu.menuIndex];

                    r8 = gDungeonMenu.menuIndex;
                    ResetDungeonMenu();
                    gDungeonSubMenuItemsCount = 0;
                    PlayDungeonConfirmationSE();
                    AddActionToDungeonSubMenu(0x28, 0);
                    AddActionToDungeonSubMenu(0xC, 0);
                    if (CheckVariousStatuses2(entity, TRUE)) {
                        SetActionUnusableInDungeonSubMenu(0x28);
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
                            ShowIqDescriptionWindow(var);
                            addCursorSprite = FALSE;
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

        if (addCursorSprite) {
            if (hasIqSkills || hasStatusProblems) {
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

// The same as sub_8068344
static void ShowUpArrowSprite(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
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
        SpriteSetY(&sprite, (window->y  * 8) + 0x8);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);

        AddSprite(&sprite, 0x100, NULL, NULL);
    }
}

// The same as sub_80684C4
static void ShowDownArrowSprite(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
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
        SpriteSetY(&sprite, (window->y  * 8) + 0x70);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}

void ShowStatusDescriptionMenuArrow(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];

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
        SpriteSetY(&gUnknown_202F268, (window->y  * 8) + 0x60);
        SpriteSetX(&gUnknown_202F268, 0x70);
        AddSprite(&gUnknown_202F268,0x100,NULL,NULL);
    }
}

void ShowStatusesDescriptionMenu(s32 count, STATUSTEXTS(statuses))
{
    s32 i;
    MenuInputStructSub menuSub;

    sub_801317C(&menuSub);
    for (i = 0; i < count; i++) {
        ShowStatusDescriptionMenu(statuses[i], &menuSub);
        while (1) {
            if (i < count - 1) {
                ShowStatusDescriptionMenuArrow();
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

static void ShowIqDescriptionWindow(u8 iqSkillId)
{
    MenuInputStructSub menuSub;
    WindowTemplates windows;
    WindowHeader header;
    STATUSTEXTS(result);

    while (1) {
        s32 count;
        bool8 bPress;

        sub_801317C(&menuSub);
        sub_80140B4(&windows);
        windows.id[0].header = &header;
        header.count = 1;
        header.currId = 0;
        header.width = 16;
        header.f3 = 0;
        DungeonShowWindows(&windows, TRUE);
        sub_80073B8(0);

        strcpy(gFormatBuffer_Items[0], GetIQSkillName(iqSkillId));
        PrintFormattedStringOnWindow(16, 0, gUnknown_80FE95C, 0, '\0');
        PrintFormattedStringOnWindow(8, 16, GetIQSkillDescription(iqSkillId), 0, '\0');
        sub_80073E0(0);
        count = PrepareStatusStringArrays(GetIQSkillDescription(iqSkillId), result);
        while (1) {
            if (count != 0) {
                ShowStatusDescriptionMenuArrow();
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

        ShowStatusesDescriptionMenu(count, result);
    }

    sub_803E708(4, 0x3E);
}

static void ShowTacticDescriptionWindow(u8 tacticId)
{
    MenuInputStructSub menuSub;
    WindowTemplates windows;
    WindowHeader header;
    STATUSTEXTS(result);

    while (TRUE) {
        s32 count;
        bool8 bPress;

        sub_801317C(&menuSub);
        sub_80140B4(&windows);
        windows.id[0].header = &header;
        header.count = 1;
        header.currId = 0;
        header.width = 16;
        header.f3 = 0;
        DungeonShowWindows(&windows, TRUE);
        sub_80073B8(0);

        CopyTacticsNameToBuffer(gFormatBuffer_Items[0], tacticId);
        PrintFormattedStringOnWindow(16, 0, gUnknown_80FE960, 0, '\0');
        PrintFormattedStringOnWindow(8, 16, GetTacticsDescription(tacticId), 0, '\0');
        sub_80073E0(0);
        count = PrepareStatusStringArrays(GetTacticsDescription(tacticId), result);
        while (1) {
            if (count != 0) {
                ShowStatusDescriptionMenuArrow();
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

        ShowStatusesDescriptionMenu(count, result);
    }

    sub_803E708(4, 0x3E);
}

static void ShowStatusInfoWindow(s32 statusId)
{
    const u8 *str;
    MenuInputStructSub menuSub;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 26,
                .height = 12,
                .unk10 = 12,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    sub_801317C(&menuSub);
    header.count = 1;
    header.currId = 0;
    header.width = 16;
    header.f3 = 0;
    DungeonShowWindows(&windows, TRUE);
    sub_80073B8(0);
    str = sub_808E4FC(statusId);
    strcpy(gFormatBuffer_Items[0], str);
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FE964, 0, '\0');
    PrintFormattedStringOnWindow(8, 16, sub_808E51C(statusId), 0, '\0');
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

static const WindowHeader sBottomWindowHeader = {1, 0, 15, 0};
static const WindowTemplate sMovesSubMenu = {
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = {2, 10},
    .width = 18,
    .height = 8,
    .unk10 = 8,
    .unk12 = 0,
    .header = &sBottomWindowHeader,
};
static const WindowTemplate sItemSubMenu = {
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = {2, 10},
    .width = 18,
    .height = 4,
    .unk10 = 4,
    .unk12 = 0,
    .header = &sBottomWindowHeader,
};

Entity *ShowDungeonToWhichMonMenu(s32 *teamId, s32 caseId)
{
    struct UnkFieldTeamMenuStruct unkStruct;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_NORMAL, // Since the window has a header, it should probably be WINDOW_TYPE_WTIH_HEADER.
                .pos = {14, 2},
                .width = 14,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &sTeamWindowHeader,
            },
            [1] = {
                .type = WINDOW_TYPE_NORMAL,
                .pos = {2, 2},
                .width = 10,
                .height = 2,
                .unk10 = 2,
                .unk12 = 0,
                .header = NULL,
            },
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };
    bool8 bPress = FALSE;
    s32 prevId, currId;

    if (teamId != NULL) {
        *teamId = -1;
    }

    if (caseId == WHICH_MENU_MOVES) {
        windows.id[2] = sMovesSubMenu;
    }
    else if (caseId == WHICH_MENU_ITEMS) {
        windows.id[2] = sItemSubMenu;
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
                if (caseId == WHICH_MENU_MOVES) {
                    PrintMoveNamesOnBottomWindow(entity);
                }
                else if (caseId == WHICH_MENU_ITEMS) {
                    PrintItemNameOnBottomWindow(entity);
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

static void PrintMoveNamesOnBottomWindow(Entity *entity)
{
    s32 x, y;
    EntityInfo *entInfo = GetEntInfo(entity);

    CallPrepareTextbox_8008C54(2);
    sub_80073B8(2);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
    PrintFormattedStringOnWindow(12, 0, gUnknown_80FE978, 2, '\0');
    y = 16;

    if (entInfo->monsterBehavior == 1 || IsExperienceLocked(entInfo->joinedAt.id)) {
        PrintFormattedStringOnWindow(12, y, _("????"), 2, '\0');
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
                        AddDoubleUnderScoreHighlight(2, 12, y - 2, 120, 7);
                    }
                }
                PrintFormattedStringOnWindow(x, y, _("{MOVE_ITEM_0}"), 2, '\0');
                y += 12;
            }
        }
    }

    sub_80073E0(2);
}

static void PrintItemNameOnBottomWindow(Entity *entity)
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
        PrintFormattedStringOnWindow(8, y, _("????"), 2, '\0');
    }
    else {
        Item *item = &entInfo->heldItem;
        if (!ItemExists(item)) {
            PrintFormattedStringOnWindow(x, y, _("None"), 2, '\0');
        }
        else {
            sub_8045C18(gFormatBuffer_Items[0], item);
            PrintFormattedStringOnWindow(x, y, _("{MOVE_ITEM_0}"), 2, '\0');
        }
    }

    sub_80073E0(2);
}

static void ResetDungeonMenu(void)
{
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    sub_801317C(&gDungeonMenu.unk28);
}
