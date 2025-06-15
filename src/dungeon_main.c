#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "structs/str_text.h"
#include "text_1.h"
#include "text_3.h"
#include "bg_control.h"
#include "dungeon_move_util.h"
#include "code_800D090.h"
#include "code_801602C.h"
#include "code_801B3C0.h"
#include "dungeon_vram.h"
#include "code_803E724.h"
#include "dungeon_action.h"
#include "code_8066D04.h"
#include "code_806CD90.h"
#include "dungeon_action.h"
#include "dungeon_ai_movement.h"
#include "dungeon_logic.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_main.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_menu_items.h"
#include "dungeon_menu_moves.h"
#include "dungeon_menu_others.h"
#include "dungeon_menu_stairs.h"
#include "dungeon_menu_team.h"
#include "dungeon_menu_tile.h"
#include "dungeon_message.h"
#include "dungeon_message_log.h"
#include "dungeon_misc.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "game_options.h"
#include "input.h"
#include "items.h"
#include "menu_input.h"
#include "moves.h"
#include "music.h"
#include "number_util.h"
#include "play_time.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "sprite.h"
#include "string_format.h"
#include "trap.h"
#include "weather.h"

extern void HandleUnsetItemAction(Entity *,bool8);
extern bool8 sub_8048A68(Entity *param_1,Item *item);
extern bool8 sub_8048950(Entity *param_1,Item *item);
extern bool8 sub_8048B9C(Entity *param_1,Item *item);
extern Item *sub_8044D90(Entity *, s32, u32);
extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);
extern void sub_806A6E8(Entity *);
extern void HandleTrap(Entity *pokemon, DungeonPos *pos, int param_3, char param_4);
bool8 sub_807EF48(void);
void sub_806A2BC(Entity *a0, u8 a1);
bool8 sub_80701A4(Entity *a0);
void sub_8075680(u32);
void sub_8094C88(void);
void ClearUnpaidFlagFromAllItems(void);
void sub_806A914(u8 a0, u8 a1, u8 a2);
void SetLeaderActionToNothing(u8 a0);
u16 GetLeaderActionId(void);
void sub_80978C8(s16 a0);
static void TryCreateModeArrows(Entity *leader);
bool8 sub_8094C48(void);
void sub_803E724(s32 a0);
void HandleTalkFieldAction(Entity *);
bool8 sub_8044B28(void);
bool8 IsNotAttacking(Entity *param_1, bool8 param_2);
s32 GetTeamMemberEntityIndex(Entity *pokemon);
bool8 sub_8070F80(Entity * pokemon, s32 direction);
void sub_806752C(ActionContainer *a0);
void sub_8067768(ActionContainer *a0);
void ChangeDungeonCameraPos(DungeonPos *pos, s32 a1, u8 a2, u8 a3);
extern bool8 sub_8071A8C(Entity *pokemon);
extern void GetWeatherName(u8 *dst, u8 weatherId);
extern bool8 sub_8070F14(Entity * pokemon, s32 direction);
extern Entity *sub_80696A8(Entity *a0);
extern void sub_803F508(Entity *);
extern void sub_8041AD0(Entity *pokemon);
extern void sub_8041AE0(Entity *pokemon);
extern void sub_807EC28(bool8);
extern const u8 *GetCurrentDungeonName(void);

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

extern MenuInputStruct gDungeonMenu;
extern s32 gTeamMenuChosenId;

static EWRAM_DATA bool8 sInDiagonalMode = 0;
static EWRAM_DATA bool8 sInRotateMode = 0;
// Frames counter for arrows in diagonal/rotate mode.
static EWRAM_DATA s16 sArrowsFrames = 0;
// If both of these are set to TRUE, there are 3 arrows visible instead of 1 in rotate mode
static EWRAM_DATA bool8 sShowThreeArrows1 = 0;
static EWRAM_DATA bool8 sShowThreeArrows2 = 0;

static void sub_805E738(Entity *a0);
static bool8 sub_805E874(void);
static bool8 sub_805EC2C(Entity *a0, s32 x, s32 y);
static bool8 sub_805EC4C(Entity *a0, u8 a1);
static bool8 sub_805EF60(Entity *a0, EntityInfo *a1);
static void ShowMainMenu(bool8 fromBPress, bool8 a1);
static void PrintOnMainMenu(bool8 printAll);

void DungeonHandlePlayerInput(void)
{
    struct UnkMenuBitsStruct r6;
    bool8 triggers[5]; // Always FALSE, if one of these is TRUE - they can open various menus or cause an item throw. Used in Blue's touch screen.
    s32 frames;
    s32 var_38;
    UnkDungeonGlobal_unk181E8_sub *unkPtr;

    unkPtr = &gDungeon->unk181e8;
    var_38 = 3;
    gDungeon->unk12 = 0;
    sub_806A2BC(GetLeader(), 1);
    if (sub_80701A4(GetLeader())) {
        sub_803E708(60, 16);
        return;
    }

    gDungeon->unk644.unk2F = 0;
    ResetMapPlayerDotFrames();
    if (gDungeon->unk1 != 0) {
        gDungeon->unk1 = 0;
        if (!ShouldMonsterRunAwayAndShowEffect(GetLeader(), TRUE)) {
            SetLeaderActionToNothing(TRUE);
            sub_805E804();
            ShowDungeonStairsMenu(GetLeader());
            ResetRepeatTimers();
            ResetUnusedInputStruct();
            if (GetLeaderActionId() != ACTION_NOTHING) {
                return;
            }
        }
    }

    sub_806A914(1, 1, 1);
    while (1) {
        Entity *leader = GetLeader();
        EntityInfo *leaderInfo = GetEntInfo(leader);

        sub_80978C8(leaderInfo->id);
        if (gDungeon->unk644.unk28 != 0) {
            if (sub_805E874()) {
                leaderInfo->action.action = 2;
                leaderInfo->action.actionParameters[0].actionUseIndex = 0;
                break;
            }
            sub_805E804();
        }
        sInRotateMode = FALSE;
        sInDiagonalMode = FALSE;
        if (gDungeon->unk5C0 >= 0) {
            r6.a0_8 = 1;
            r6.a0_16 = 0;
            r6.a0_24 = 0;
        }
        else {
            r6.a0_8 = 0;
            r6.a0_16 = 0;
            r6.a0_24 = 0;
        }

        frames = 0;
        sub_8044C50(ACTION_NOTHING);
        sShowThreeArrows1 = FALSE;
        sShowThreeArrows2 = FALSE;

        while (r6.a0_8 == 0) {
            u32 dpadDiagonal, dpadSimple;
            bool32 highlightTiles, tryItemThrow;
            bool32 bPress, rPress, unkBool; // Always FALSE, might've been used in Blue.
            s32 directionNew;

            sArrowsFrames++;
            if (unkPtr->unk1821A != 0) {
                frames = 0;
            }
            else {
                frames++;
            }

            if (var_38 != 0 && --var_38 == 0) {
                sub_8075680(0);
            }

            TryCreateModeArrows(leader);
            unkBool = FALSE;
            {
                s32 i;
                for (i = 0; i < 5; i++) {
                    triggers[i] = FALSE;
                }
            }

            if (gRealInputs.held & A_BUTTON && gRealInputs.held & B_BUTTON && FixedPointToInt(leaderInfo->belly) != 0) {
                sub_8044C50(ACTION_PASS_TURN);
                gDungeon->unk644.unk2F = 1;
                break;
            }

            bPress = FALSE;
            rPress = FALSE;

            if (gRealInputs.pressed & A_BUTTON) {
                if (gRealInputs.held & B_BUTTON) {
                    if (FixedPointToInt(leaderInfo->belly) != 0) {
                        sub_8044C50(ACTION_PASS_TURN);
                        gDungeon->unk644.unk2F = 1;
                        break;
                    }
                }
                else if (ShouldMonsterRunAwayAndShowEffect(leader, TRUE)) {
                    LogMessageByIdWithPopupCheckUser(leader, gUnknown_80FD4B0);
                    sub_8044C50(ACTION_PASS_TURN);
                    gDungeon->unk644.unk2F = 1;
                    break;
                }
                else if (gRealInputs.held & L_BUTTON) {
                    bool32 canUseMove;
                    s32 i, j;

                    for (i = 0; i < MAX_MON_MOVES; i++) {
                        if (MoveFlagExists(&leaderInfo->moves.moves[i]) && MoveFlagSet(&leaderInfo->moves.moves[i])) {
                            break;
                        }
                    }
                    if (i == MAX_MON_MOVES) {
                        LogMessageByIdWithPopupCheckUser(leader, gUnknown_80F8A28);
                        break;
                    }

                    for (j = 0; j < MAX_MON_MOVES; j++) {
                        if (MoveFlagExists(&leaderInfo->moves.moves[j])) {
                            if (leaderInfo->moves.moves[j].PP != 0)
                                break;
                        }
                    }
                    if (j == MAX_MON_MOVES) {
                        SetMonsterActionFields(&leaderInfo->action, ACTION_STRUGGLE);
                        break;
                    }

                    canUseMove = FALSE;
                    for (j = i; j < MAX_MON_MOVES; j++) {
                        if (j != i && !(leaderInfo->moves.moves[j].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
                            break;
                        }
                        if (leaderInfo->moves.moves[j].PP != 0) {
                            canUseMove = TRUE;
                            break;
                        }
                    }
                    if (!canUseMove) {
                        LogMessageByIdWithPopupCheckUser(leader, gUnknown_80F8A4C);
                    }
                    else {
                        SetMonsterActionFields(&leaderInfo->action, ACTION_USE_MOVE_PLAYER);
                        leaderInfo->action.actionParameters[0].actionUseIndex = GetTeamMemberEntityIndex(leader);
                        leaderInfo->action.actionParameters[1].actionUseIndex = i;
                    }
                    break;
                }
                else {
                    if (!sub_805EF60(leader, leaderInfo)) {
                        SetMonsterActionFields(&leaderInfo->action, ACTION_REGULAR_ATTACK);
                    }
                    break;
                }
            }

            if (gRealInputs.shortPress & B_BUTTON) {
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 0;
                break;
            }
            else if (triggers[1]) { // Opens moves menu
                gDungeon->unk5C0 = 0;
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (triggers[2]) { // Opens item menu
                gDungeon->unk5C0 = 1;
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (triggers[3]) { // Opens pokemon menu
                gDungeon->unk5C0 = 2;
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (triggers[4]) { // Opens regular menu
                r6.a0_8 = 1;
                r6.a0_16 = 0;
                r6.a0_24 = 1;
                break;
            }
            else if (frames > 0x707) { // Opens simple menu when idling
                r6.a0_8 = 1;
                r6.a0_16 = 1;
                r6.a0_24 = 0;
                break;
            }

            if (gGameOptionsRef->unk9 == 0
                && (gRealInputs.pressed & B_BUTTON || (!unkBool && bPress))
                && unkPtr->unk1821A != 0)
            {
                sub_804AA60();
                sInRotateMode = FALSE;
                ResetRepeatTimers();
                ResetUnusedInputStruct();
            }

            if (gRealInputs.held & L_BUTTON) {
                if (gRealInputs.pressed & B_BUTTON) {
                    DisplayMessageLog();
                    ResetRepeatTimers();
                    ResetUnusedInputStruct();
                }
            }

            tryItemThrow = FALSE;
            if (gRealInputs.held & R_BUTTON) {
                if (!sInDiagonalMode) {
                    sArrowsFrames = 0;
                }
                sInDiagonalMode = TRUE;
            }
            else {
                sInDiagonalMode = FALSE;
            }

            highlightTiles = FALSE;
            if (gGameOptionsRef->unk9 == 0) {
                if (gRealInputs.shortPress & R_BUTTON || rPress || gRealInputs.pressed & START_BUTTON) {
                    highlightTiles = TRUE;
                }
            }
            if (highlightTiles) {
                sub_805E738(leader);
                sInRotateMode = TRUE;
                unkPtr->rotateModeDirection = leaderInfo->action.direction;
                unkPtr->prevRotateModeDirection = 0xFF;
                ResetRepeatTimers();
            }

            if ((gRealInputs.held & L_BUTTON) == L_BUTTON && (gRealInputs.pressed & R_BUTTON) == R_BUTTON) {
                tryItemThrow = TRUE;
            }
            if (triggers[0]) {
                tryItemThrow = TRUE;
            }
            if (tryItemThrow) {
                s32 i;
                for (i = 0; i < INVENTORY_SIZE; i++) {
                    if (ItemExists(&gTeamInventoryRef->teamItems[i]) && ItemSet(&gTeamInventoryRef->teamItems[i])) {
                        sub_8044C50(ACTION_THROW_ITEM_PLAYER);
                        leaderInfo->action.actionParameters[0].actionUseIndex = i +1;
                        leaderInfo->action.actionParameters[0].itemPos.x = 0;
                        leaderInfo->action.actionParameters[0].itemPos.y = 0;
                        break;
                    }
                }
                if (leaderInfo->action.action != 0) {
                    break;
                }
            }

            // SELECT button
            if (!gDungeon->unk181e8.blinded && gGameOptionsRef->mapOption != 6 && gRealInputs.pressed & SELECT_BUTTON) {
                s32 prevMapOption = gGameOptionsRef->mapOption;
                gShowMonsterDotsInDungeonMap = TRUE;
                gDungeon->unk181e8.inFloorMapMode = TRUE;
                if (!sub_8094C48()) {
                    sub_8094C88();
                }
                sub_8052210(1);
                ShowWholeRevealedDungeonMap();
                SetBGOBJEnableFlags(0x1E);
                sub_803E708(0xA, 0x2F);
                while (1) {
                    DungeonRunFrameActions(0x2F);
                    if (gRealInputs.pressed & SELECT_BUTTON)
                        break;
                    if (gRealInputs.pressed & B_BUTTON)
                        break;

                    if (gRealInputs.pressed & A_BUTTON) {
                        gShowMonsterDotsInDungeonMap = (gShowMonsterDotsInDungeonMap == FALSE) ? TRUE : FALSE; // Flip
                        ShowWholeRevealedDungeonMap();
                    }
                }
                gDungeon->unk181e8.inFloorMapMode = FALSE;
                gGameOptionsRef->mapOption = prevMapOption;
                gShowMonsterDotsInDungeonMap = TRUE;
                ShowWholeRevealedDungeonMap();
                SetBGOBJEnableFlags(0);
                DungeonRunFrameActions(0x2F);
                DungeonRunFrameActions(0x2F);
            }

            if (gDungeon->unk644.unk29 != 0 && !sInDiagonalMode) {
                dpadDiagonal = dpadSimple = gRealInputs.pressed;
            }
            else {
                dpadDiagonal = gRealInputs.held;
                dpadSimple = (unkPtr->unk1821A == 0) ? gRealInputs.held : gRealInputs.pressed;
            }

            dpadDiagonal &= DPAD_ANY;
            dpadSimple &= DPAD_ANY;
            directionNew = -1;
            if (dpadDiagonal == (DPAD_UP | DPAD_RIGHT))
                directionNew = DIRECTION_NORTHEAST;
            if (dpadDiagonal == (DPAD_UP | DPAD_LEFT))
                directionNew = DIRECTION_NORTHWEST;
            if (dpadDiagonal == (DPAD_DOWN | DPAD_RIGHT))
                directionNew = DIRECTION_SOUTHEAST;
            if (dpadDiagonal == (DPAD_DOWN | DPAD_LEFT))
                directionNew = DIRECTION_SOUTHWEST;

            if (dpadSimple == DPAD_UP)
                directionNew = DIRECTION_NORTH;
            if (dpadSimple == DPAD_DOWN)
                directionNew = DIRECTION_SOUTH;
            if (dpadSimple == DPAD_RIGHT)
                directionNew = DIRECTION_EAST;
            if (dpadSimple == DPAD_LEFT)
                directionNew = DIRECTION_WEST;

            if (directionNew >= 0 && (!sInDiagonalMode || (directionNew & 1))) {
                bool32 directionChanged = (leaderInfo->action.direction != directionNew);
                leaderInfo->action.direction = directionNew & DIRECTION_MASK;
                if (sInRotateMode) {
                    unkPtr->rotateModeDirection = directionNew;
                    sub_806CDD4(leader, sub_806CEBC(leader), directionNew);
                }
                else {
                    u8 canMoveFlags = 0;
                    const u8 *immobilizedMsg = NULL;

                    if (sub_805EC4C(leader, 1))
                        break;

                    if (leaderInfo->frozenClassStatus.status == STATUS_SHADOW_HOLD) {
                        immobilizedMsg = gUnknown_80F8A84, canMoveFlags |= 1;
                    }
                    else if (leaderInfo->frozenClassStatus.status == STATUS_CONSTRICTION) {
                        immobilizedMsg = gUnknown_80F8A6C, canMoveFlags |= 1;
                    }
                    else if (leaderInfo->frozenClassStatus.status == STATUS_INGRAIN) {
                        immobilizedMsg = gUnknown_80F8AB0, canMoveFlags |= 1;
                    }
                    else if (leaderInfo->frozenClassStatus.status == STATUS_WRAP) {
                        immobilizedMsg = gUnknown_80F8ADC, canMoveFlags |= 1;
                    }
                    else if (leaderInfo->frozenClassStatus.status == STATUS_WRAPPED) {
                        immobilizedMsg = gUnknown_80F8B0C, canMoveFlags |= 1;
                    }

                    if (!CanMoveInDirection(leader, directionNew))
                        canMoveFlags |= 2;

                    if (directionChanged) {
                        sub_806CDD4(leader, sub_806CEBC(leader), directionNew);
                    }

                    if (!(canMoveFlags & 2)) {
                        if (canMoveFlags & 1) {
                            if (immobilizedMsg != NULL) {
                                LogMessageByIdWithPopupCheckUser(leader, immobilizedMsg);
                            }
                            sub_8044C50(ACTION_PASS_TURN);
                            gDungeon->unk644.unk2F = 1;
                        }
                        else {
                            sub_8044C50(ACTION_WALK);
                            if ((gRealInputs.held & B_BUTTON || bPress) && FixedPointToInt(leaderInfo->belly) != 0) {
                                if (GetEntInfo(leader)->cringeClassStatus.status != STATUS_CONFUSED) {
                                    gDungeon->unk644.unk28 = 1;
                                }
                                leaderInfo->action.actionParameters[0].actionUseIndex = 0;
                            }
                            else {
                                leaderInfo->action.actionParameters[0].actionUseIndex = 1;
                            }
                        }
                        break;
                    }
                    else if (canMoveFlags & 1) {
                        sub_803E724(0x23);
                    }

                }
            }
            DungeonRunFrameActions(0xF);
        }

        if (unkPtr->unk1821A != 0) {
            sub_804AA60();
        }

        if (leaderInfo->action.action == 0x2D || leaderInfo->action.action == 0x13) {
            HandleTalkFieldAction(leader);
            if (sub_8044B28())
                break;
            sub_8044C50(ACTION_NOTHING);
        }
        else if ((r6.a0_8) == 0) {
            gDungeon->unk644.unk29 = 0;
            if (leaderInfo->action.action != 0) {
                if (!IsNotAttacking(leader, FALSE)) {
                    DungeonRunFrameActions(0xF);
                }
                break;
            }
            DungeonRunFrameActions(0xF);
        }
        else {
            DungeonRunFrameActions(0xF);
            ClearUnpaidFlagFromAllItems();
            ShowMainMenu((r6.a0_16 == 0), r6.a0_24);
            ResetRepeatTimers();
            ResetUnusedInputStruct();
            sInRotateMode = FALSE;
            unkPtr->unk1821A = 0;
            sub_804AA60();
            if (sub_8044B28())
                break;
            if (leaderInfo->action.action != 0) {
                if (leaderInfo->action.action == 0x2B) {
                    gDungeon->unk4 = 1;
                    gDungeon->unk3 = 1;
                }
                if (leaderInfo->action.action == 0x2E) {
                    gDungeon->unk4 = 1;
                    gDungeon->unk3 = 0;
                }
                break;
            }
            DungeonRunFrameActions(0xF);
            if (gDungeon->unk4 != 0)
                break;
        }
    }
}

struct DiagonalArrowInfo
{
    s16 x;
    s16 y;
    bool8 unk4;
    bool8 unk5;
};

static const struct DiagonalArrowInfo sDiagonalArrowsInfo[] =
{
    {-1, -1, TRUE, FALSE},
    {-1, 1, TRUE, TRUE},
    {1, 1, FALSE, TRUE},
    {1, -1, FALSE, FALSE},
};

struct RotateArrowInfo
{
    s16 x;
    s16 y;
    u32 tilemapNum;
    bool8 unk8;
    bool8 unk9;
};

static const struct RotateArrowInfo sRotateArrowsInfo[] =
{
    {0, 1,   0x212, FALSE, TRUE},
    {1, 1,   0x213, FALSE, TRUE},
    {1, 0,   0x214, FALSE, FALSE},
    {1, -1,  0x213, FALSE, FALSE},
    {0, -1,  0x212, TRUE, FALSE},
    {-1, -1, 0x213, TRUE, FALSE},
    {-1, 0,  0x214, TRUE, TRUE},
    {-1, 1,  0x213, TRUE, TRUE},
};

// Creates arrow sprites which are used when in rotate or diagonal modes.
static void TryCreateModeArrows(Entity *leader)
{
    UnkDungeonGlobal_unk181E8_sub *unkPtr = &gDungeon->unk181e8;

    if (sInDiagonalMode) {
        s32 i;
        SpriteOAM sprite;

        for (i = 0; i < 4; i++) {
            u32 matrixNum;
            s32 x, xMul, x2;
            s32 y, yMul, y2;

            SpriteSetAffine1(&sprite, 0);
            SpriteSetAffine2(&sprite, 0);
            SpriteSetObjMode(&sprite, 1);
            SpriteSetMosaic(&sprite, 0);
            SpriteSetBpp(&sprite, 0);
            SpriteSetShape(&sprite, 0);

            matrixNum = (sDiagonalArrowsInfo[i].unk4) ? 8 : 0;

            if (sDiagonalArrowsInfo[i].unk5)
                matrixNum += 16;

            SpriteSetMatrixNum_UseLocalVar(&sprite, matrixNum);
            SpriteSetSize(&sprite, 0);

            SpriteSetTileNum(&sprite, 0x213);
            SpriteSetPriority(&sprite, 2);
            SpriteSetPalNum(&sprite, 0);

            SpriteSetUnk6_0(&sprite, 0);
            SpriteSetUnk6_1(&sprite, 0);

            xMul = sDiagonalArrowsInfo[i].x * 10;
            x2 = (sArrowsFrames / 2) & 7;
            x = (x2 * sDiagonalArrowsInfo[i].x) + xMul + 116;
            SpriteSetX(&sprite, x);

            yMul = sDiagonalArrowsInfo[i].y * 10;
            y2 = (sArrowsFrames / 2) & 7;
            y = (y2 * sDiagonalArrowsInfo[i].y) + yMul + 82;
            SpriteSetY(&sprite, y);

            AddSprite(&sprite, 0x100, NULL, NULL);
        }
    }

    else if (unkPtr->unk1821A) {
        s32 i;
        SpriteOAM sprite;
        s32 direction = unkPtr->rotateModeDirection;

        if (unkPtr->rotateModeDirection < NUM_DIRECTIONS) {
            s32 x, xMul, x2;
            s32 y, yMul, y2;
            s32 to = (sShowThreeArrows2 != FALSE && sShowThreeArrows1 != FALSE) ? 3 : 1;

            xMul = sRotateArrowsInfo[direction].x * 10;
            x2 = (sArrowsFrames / 2) & 7;
            x = (sRotateArrowsInfo[direction].x * x2) + xMul + 116;

            yMul = sRotateArrowsInfo[direction].y * 10;
            y2 = (sArrowsFrames / 2) & 7;
            y = (y2 * sRotateArrowsInfo[direction].y) + yMul + 82;
            for (i = 0; i < to; i++) {
                u32 matrixNum;

                SpriteSetAffine1(&sprite, 0);
                SpriteSetAffine2(&sprite, 0);
                SpriteSetObjMode(&sprite, 1);
                SpriteSetMosaic(&sprite, 0);
                SpriteSetBpp(&sprite, 0);
                SpriteSetShape(&sprite, 0);

                matrixNum = (sRotateArrowsInfo[direction].unk8 != 0) ? 8 : 0;

                if (sRotateArrowsInfo[direction].unk9)
                    matrixNum += 16;

                SpriteSetMatrixNum_UseLocalVar(&sprite, matrixNum);
                SpriteSetSize(&sprite, 0);

                SpriteSetTileNum(&sprite, sRotateArrowsInfo[direction].tilemapNum);
                SpriteSetPriority(&sprite, 2);
                SpriteSetPalNum(&sprite, 0);

                SpriteSetUnk6_0(&sprite, 0);
                SpriteSetUnk6_1(&sprite, 0);

                SpriteSetX(&sprite, x);
                SpriteSetY(&sprite, y);

                AddSprite(&sprite, 0x100, NULL, NULL);
                x += sRotateArrowsInfo[direction].x * 4;
                y += sRotateArrowsInfo[direction].y * 4;
            }
        }
    }

    if (sInRotateMode && unkPtr->prevRotateModeDirection != unkPtr->rotateModeDirection) {
        unkPtr->prevRotateModeDirection = unkPtr->rotateModeDirection;
        ChangeDungeonCameraPos(&leader->pos, unkPtr->rotateModeDirection, 0, sInRotateMode);
    }
}

static void sub_805E738(Entity *a0)
{
    const Tile *tile;
    s32 i, j;
    EntityInfo *entityInfo = GetEntInfo(a0);
    if (entityInfo->blinkerClassStatus.status != 1 && entityInfo->blinkerClassStatus.status != 2) {
        // What???
        for (i = 0; i < 1; i++) {
            bool8 r9 = FALSE;
            u32 direction = entityInfo->action.direction;
            direction++;
            for (j = 1; j < 8; j++, direction++) {
                direction &= DIRECTION_MASK;
                tile = GetTile(a0->pos.x + gAdjacentTileOffsets[direction].x, a0->pos.y + gAdjacentTileOffsets[direction].y);
                if (tile->monster != NULL && GetEntityType(tile->monster) == ENTITY_MONSTER) {
                    EntityInfo *tileMonsterInfo = GetEntInfo(tile->monster);
                    if (CanSeeTarget(a0, tile->monster)) {
                        if (i != 0 || tileMonsterInfo->isNotTeamMember) {
                            r9 = TRUE;
                            break;
                        }
                    }
                }
            }
            if (r9) {
                GetEntInfo(a0)->action.direction = direction & DIRECTION_MASK;
                sub_806CDD4(a0, sub_806CEBC(a0), direction);
                break;
            }
        }
    }
}

void sub_805E804(void)
{
    gDungeon->unk644.unk29 |= gDungeon->unk644.unk28;
    gDungeon->unk644.unk28 = 0;
    while (gDungeon->unk644.unk29 != 0 && gRealInputs.held & R_BUTTON) {
        DungeonRunFrameActions(0x54);
    }
}

static bool8 sub_805E874(void)
{
    u8 r7, r8, r0;
    s32 i, j, k;
    s32 xArray[3];
    s32 yArray[3];
    Dungeon *dungeon = gDungeon;
    Entity *leader = GetLeader();
    s32 direction = GetEntInfo(leader)->action.direction;
    s32 x = leader->pos.x;
    s32 y = leader->pos.y;
    const Tile *leaderTile = GetTile(x, y);
    s32 xAdjacent = x + gAdjacentTileOffsets[direction].x;
    s32 yAdjacent = y + gAdjacentTileOffsets[direction].y;
    s32 room;

    if (dungeon->unk644.unk28 == 0)
        return FALSE;
    if (leaderTile->object != NULL)
        return FALSE;
    if (sub_805EC2C(leader, x, y))
        return FALSE;
    if (!sub_8070F14(leader, direction))
        return FALSE;

    room = leaderTile->room;
    if (room == 0xFF) {
        if (GetTile(xAdjacent, yAdjacent)->room != 0xFF)
            return FALSE;
    }
    else {
        if (leaderTile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
            return FALSE;
    }

    for (j = -1; j < 2; j++) {
        const Tile *tile = GetTile(x + gAdjacentTileOffsets[(direction + j) & 7].x, y + gAdjacentTileOffsets[(direction + j) & 7].y);
        if (tile->monster != NULL)
            return FALSE;
        if (tile->terrainType & TERRAIN_TYPE_STAIRS)
            return FALSE;
    }

    xArray[0] = x + gAdjacentTileOffsets[(direction + 3) & 7].x;
    xArray[1] = x + gAdjacentTileOffsets[(direction + 4) & 7].x;
    xArray[2] = x + gAdjacentTileOffsets[(direction + 5) & 7].x;

    yArray[0] = y + gAdjacentTileOffsets[(direction + 3) & 7].y;
    yArray[1] = y + gAdjacentTileOffsets[(direction + 4) & 7].y;
    yArray[2] = y + gAdjacentTileOffsets[(direction + 5) & 7].y;

    for (i = -1; i < 2; i++) {
        for (j = -1; j < 2; j++) {
            const Tile *tile = GetTile(x + i, y + j);
            if (tile->object != NULL) {
                for (k = 0; k < 3; k++) {
                    if (x + i == xArray[k] && y + j == yArray[k])
                        break;
                }
                if (k == 3 && GetEntityType(tile->object) == ENTITY_ITEM)
                    return FALSE;
            }

            if (direction & 1) {
                // This doesn't really have to be called two times...
                if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP && GetEntityType(tile->object) == ENTITY_TRAP) {
                    if (tile->object->isVisible)
                        return FALSE;
                    if (gDungeon->unk181e8.showInvisibleTrapsMonsters)
                        return FALSE;
                }
            }
            else if (i == 0 || j == 0) {
                if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP) {
                    if (tile->object->isVisible)
                        return FALSE;
                    if (gDungeon->unk181e8.showInvisibleTrapsMonsters)
                        return FALSE;
                }
            }

            if (i != 0 && j != 0) continue;
            if (i == 0 && j == 0) continue;

            if ((xArray[1] != x + i || yArray[1] != y + j) && !sub_805EC2C(leader, x + i, y + j) && room != 0xFF && room != tile->room)
                return FALSE;
        }
    }

    if (!(direction & 1)) {
        if (direction == 0 || direction == 4) {
            r8 = sub_805EC2C(leader, x - 1, y - 1);
            r7 = sub_805EC2C(leader, x - 1, y);
            r0 = sub_805EC2C(leader, x - 1, y + 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }

            r8 = sub_805EC2C(leader, x + 1, y - 1);
            r7 = sub_805EC2C(leader, x + 1, y);
            r0 = sub_805EC2C(leader, x + 1, y + 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }
        }
        else {
            r8 = sub_805EC2C(leader, x - 1, y - 1);
            r7 = sub_805EC2C(leader, x, y - 1);
            r0 = sub_805EC2C(leader, x + 1, y - 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }

            r8 = sub_805EC2C(leader, x - 1, y + 1);
            r7 = sub_805EC2C(leader, x, y + 1);
            r0 = sub_805EC2C(leader, x + 1, y + 1);
            if (r7 == 0) {
                if (r8 != 0 || r7 != r0)
                    return FALSE;
            }
        }
    }

    return TRUE;
}

static bool8 sub_805EC2C(Entity *a0, s32 x, s32 y)
{
    DungeonPos pos = {.x = x, .y = y};
    return sub_8070564(a0, &pos);
}

static bool8 sub_805EC4C(Entity *a0, u8 a1)
{
    DungeonPos pos;
    const Tile *tile;
    EntityInfo *tileMonsterInfo;
    Entity *tileMonster;
    EntityInfo *entityInfo = GetEntInfo(a0);

    pos.x = a0->pos.x + gAdjacentTileOffsets[entityInfo->action.direction].x;
    pos.y = a0->pos.y + gAdjacentTileOffsets[entityInfo->action.direction].y;
    tile = GetTile(pos.x, pos.y);
    tileMonster = tile->monster;

    if (tileMonster == NULL) return FALSE;
    if (GetEntityType(tileMonster) != ENTITY_MONSTER) return FALSE;

    tileMonsterInfo = GetEntInfo(tileMonster);
    if (tileMonsterInfo->isNotTeamMember
        && (tileMonsterInfo->shopkeeper != 1 && tileMonsterInfo->shopkeeper != 2)
        && !IsExperienceLocked(tileMonsterInfo->joinedAt.id)
        && tileMonsterInfo->monsterBehavior != BEHAVIOR_RESCUE_TARGET) {
        return FALSE;
    }

    if (entityInfo->frozenClassStatus.status == STATUS_SHADOW_HOLD) return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_FROZEN) return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_CONSTRICTION) return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_INGRAIN) return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_WRAP) return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_WRAPPED) return FALSE;

    if (tileMonsterInfo->frozenClassStatus.status == STATUS_SHADOW_HOLD) return FALSE;
    if (tileMonsterInfo->frozenClassStatus.status == STATUS_FROZEN) return FALSE;
    if (tileMonsterInfo->frozenClassStatus.status == STATUS_CONSTRICTION) return FALSE;
    if (tileMonsterInfo->frozenClassStatus.status == STATUS_INGRAIN) return FALSE;
    if (tileMonsterInfo->frozenClassStatus.status == STATUS_WRAP) return FALSE;
    if (tileMonsterInfo->frozenClassStatus.status == STATUS_WRAPPED) return FALSE;

    if (entityInfo->cringeClassStatus.status == STATUS_CONFUSED) return FALSE;
    if (tileMonsterInfo->cringeClassStatus.status == STATUS_CONFUSED) return FALSE;

    if (tileMonsterInfo->sleepClassStatus.status != STATUS_NONE && tileMonsterInfo->sleepClassStatus.status != STATUS_SLEEPLESS && tileMonsterInfo->sleepClassStatus.status != STATUS_YAWNING)  return FALSE;
    if (entityInfo->sleepClassStatus.status != STATUS_NONE      && entityInfo->sleepClassStatus.status != STATUS_SLEEPLESS      && entityInfo->sleepClassStatus.status != STATUS_YAWNING)       return FALSE;

    if (IsChargingAnyTwoTurnMove(tileMonster, FALSE)) return FALSE;
    if (!sub_8070F80(a0, entityInfo->action.direction)) return FALSE;

    if (a1 != 0 && sub_807049C(tileMonster, &a0->pos) && !DisplayDungeonYesNoMessage(0, gUnknown_8100208, 0)) return FALSE;

    SetMonsterActionFields(&entityInfo->action, ACTION_WALK);
    if (gRealInputs.held & B_BUTTON) {
        entityInfo->action.actionParameters[0].actionUseIndex = 0;
    }
    else {
        entityInfo->action.actionParameters[0].actionUseIndex = 1;
    }
    entityInfo->flags |= 0x8000;

    SetMonsterActionFields(&tileMonsterInfo->action, ACTION_WALK);
    tileMonsterInfo->action.actionParameters[0].actionUseIndex = 0;
    tileMonsterInfo->action.direction = (entityInfo->action.direction + 4) & 7;
    tileMonsterInfo->flags |= 0x8000;
    tileMonsterInfo->targetPos.x = tileMonster->pos.x;
    tileMonsterInfo->targetPos.y = tileMonster->pos.y;
    gDungeon->unkE = 1;
    return TRUE;
}

void sub_805EE30(void)
{
    Entity *tileObject;
    Tile *tile;
    Entity *leader = GetLeader();
    if (leader == NULL)
        return;
    if (sub_8044B28())
        return;

    tile = GetTileAtEntitySafe(leader);
    if (IQSkillIsEnabled(leader, IQ_SUPER_MOBILE) && GetEntInfo(leader)->invisibleClassStatus.status != STATUS_MOBILE && !HasHeldItem(leader, ITEM_MOBILE_SCARF))
        sub_804AE84(&leader->pos);
    if (tile->terrainType & TERRAIN_TYPE_STAIRS)
        gDungeon->unk1 = 1;

    tileObject = tile->object;
    if (tileObject == NULL)
        return;
    switch (GetEntityType(tileObject))
    {
        case ENTITY_TRAP: {
            Trap *trap = GetTrapData(tileObject);
            bool32 r8 = FALSE;
            bool32 r7 = FALSE;
            if (IQSkillIsEnabled(leader, IQ_TRAP_SEER) && !tileObject->isVisible) {
                tileObject->isVisible = TRUE;
                sub_8049ED4();
                r7 = TRUE;
            }
            if (trap->unk1 != 0) {
                if (trap->unk1 == 1)
                    break;
                if (trap->unk1 == 2)
                    r8 = TRUE;
                if (r8 == FALSE)
                    break;
            }
            if (!r7) {
                HandleTrap(leader, &leader->pos, 0, 1);
            }
        }
        break;
        case ENTITY_ITEM: {
            Item *item = GetItemData(tileObject);
            if (!(item->flags & ITEM_FLAG_IN_SHOP)) {
                PickUpItemFromPos(&leader->pos, 1);
            }
            else {
                gDungeon->unk5C0 = 4;
            }
        }
        break;
        case ENTITY_NOTHING:
        case ENTITY_MONSTER:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
        default:
            break;
    }
}

static bool8 sub_805EF60(Entity *a0, EntityInfo *a1)
{
    Entity *r4 = sub_80696A8(a0);

    if (r4 == NULL)
        return FALSE;
    if (GetEntityType(r4) != ENTITY_MONSTER)
        return FALSE;
    if (!sub_8070BC0(a0))
        return FALSE;
    if (GetEntInfo(r4)->isNotTeamMember && GetEntInfo(r4)->monsterBehavior != BEHAVIOR_RESCUE_TARGET && GetEntInfo(r4)->shopkeeper != 1)
        return FALSE;

    SetMonsterActionFields(&a1->action, ACTION_TALK_FIELD);
    return TRUE;
}

void sub_805EFB4(Entity *a0, bool8 a1)
{
    s32 i;
    EntityInfo *leaderInfo = GetLeaderInfo();
    if (a1 && leaderInfo->cringeClassStatus.status == STATUS_COWERING) {
        leaderInfo->action.direction += 4;
        leaderInfo->action.direction &= 7;
    }
    else if (leaderInfo->cringeClassStatus.status == STATUS_CONFUSED) {
        s32 rnd = DungeonRandInt(8);
        for (i = 0; i < 8; i++) {
            if (a1 || CanMoveInDirection(a0, rnd)) {
                leaderInfo->action.direction = rnd & 7;
                return;
            }
            rnd = (rnd + 1) & 7;
        }
    }
}

void sub_805F02C(void)
{
    s32 i;
    Entity *r7 = gDungeon->unkBC;
    Entity *leader = GetLeader();
    EntityInfo *r8 = GetEntInfo(r7);
    EntityInfo *leaderInfo = GetEntInfo(leader);

    if (r8->isTeamLeader) {
        DisplayDungeonLoggableMessageTrue(r7, gUnknown_80F9BD8);
    }
    else if (PlayerHasItemWithFlag(ITEM_FLAG_IN_SHOP) || sub_807EF48()) {
        DisplayDungeonLoggableMessageTrue(r7, gUnknown_80F9C08);
    }
    else if (gDungeon->unk644.unk2A) {
        DisplayDungeonLoggableMessageTrue(r7, gUnknown_80F9C2C);
    }
    else {
        gDungeon->unk644.unk35 = 0;
        r8->isTeamLeader = TRUE;
        leaderInfo->isTeamLeader = FALSE;
        for (i = 0; i < 4; i++) {
            DungeonMon *mon = &gRecruitedPokemonRef->dungeonTeam[i];
            Pokemon *r5 = NULL;

            if ((u8)mon->flags & 1) {
                if (!sub_806A538(mon->recruitedPokemonId)) {
                    r5 = &gRecruitedPokemonRef->pokemon[mon->recruitedPokemonId];
                }
                if (i == r8->teamIndex) {
                    mon->isTeamLeader = TRUE;
                    if (r5 != NULL) {
                        r5->isTeamLeader = TRUE;
                    }
                }
                else {
                    mon->isTeamLeader = FALSE;
                    if (r5 != NULL) {
                        r5->isTeamLeader = FALSE;
                    }
                }
            }
        }
        gLeaderPointer = NULL;
        r8->action = leaderInfo->action;
        sub_803F508(r7);
        sub_8041AD0(leader);
        sub_8041AE0(GetLeader());
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], r7, 0);
        LogMessageByIdWithPopupCheckUser(r7, gUnknown_80F9BB0);
        sub_807EC28(FALSE);
        r8->unk64 = 0;
        leaderInfo->unk64 = 0;
        sub_806A6E8(leader);
        sub_806A6E8(r7);
    }
}

ActionContainer *GetLeaderActionContainer(void)
{
    return &GetLeaderInfo()->action;
}

u16 GetLeaderActionId(void)
{
    return GetLeaderInfo()->action.action;
}

enum
{
    MAIN_MENU_MOVES,
    MAIN_MENU_ITEMS,
    MAIN_MENU_TEAM,
    MAIN_MENU_OTHERS,
    MAIN_MENU_GROUND,
};

static void ShowMainMenu(bool8 fromBPress, bool8 a1)
{
    Item *item;
    s32 r10;
    bool8 printAll = fromBPress;
    s32 chosenOption;
    s32 var_24;
    struct UnkMenuBitsStruct var_30;
    struct UnkMenuBitsStruct var_34;

    r10 = gDungeon->unk5C0;
    chosenOption = 0;
    var_24 = (gDungeon->unk5C0 > - 1);
    gDungeon->unk5C0 = -1;
    if (r10 >= 0) {
        chosenOption = r10;
    }

    if (a1) {
        PlayFanfareSE(0x137, 0x100);
    }
    else {
        PlayDungeonStartButtonSE();
    }

    while (1) {
        if (r10 < 0) {
            SetLeaderActionToNothing(TRUE);
            gTeamMenuChosenId = -1;
            PrintOnMainMenu(printAll);
            sub_806A2BC(GetLeader(), 0);
            while (1) {
                AddMenuCursorSprite(&gDungeonMenu);
                DungeonRunFrameActions(0x1D);
                if (gRealInputs.repeated & DPAD_DOWN) {
                    PlayDungeonCursorSE(1);
                    MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    PlayDungeonCursorSE(1);
                    MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
                }
                if ((gRealInputs.pressed & A_BUTTON || gDungeonMenu.touchScreen.a_button)) {
                    if (gUnknown_202749A[gDungeonMenu.menuIndex + 1] == 7) {
                        PlayDungeonConfirmationSE();
                        chosenOption = gDungeonMenu.menuIndex;
                        break;
                    }
                    PlayDungeonCancelSE();
                }
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.touchScreen.b_button) {
                    PlayDungeonCancelSE();
                    chosenOption = -1;
                    break;
                }
            }
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x1D);
            printAll = TRUE;
        }

        r10 = chosenOption;
        if (chosenOption == MAIN_MENU_ITEMS) {
            u16 action;

            SetLeaderActionToNothing(TRUE);
            var_34.a0_8 = 0;
            var_34.a0_16 = 1;
            var_34.a0_24 = 0;
            var_34.a0_32 = 0;
            if (ShowDungeonItemsMenu(GetLeader(), &var_34)) {
                r10 = -1;
            }
            if (sub_805FD3C(&var_34) && ShowDungeonItemsMenu(GetLeader(), &var_34)) {
                SetLeaderActionToNothing(TRUE);
            }
            action = GetLeaderActionId();
            if (action == ACTION_SHOW_INFO) {
                sub_8044D90(GetLeader(), 0, 12)->flags |= ITEM_FLAG_UNPAID;
                DungeonShowItemDescription(GetLeaderActionContainer());
                SetLeaderActionToNothing(TRUE);
            }
            else if (action == ACTION_UNK35) {
                item = sub_8044D90(GetLeader(), 0, 13);
                if (!sub_8048A68(GetLeader(), item)) {
                    SetLeaderActionToNothing(TRUE);
                }
            }
            else if (action == ACTION_UNK10) {
                item = sub_8044D90(GetLeader(), 0, 14);
                if (!sub_8048950(GetLeader(), item)) {
                    SetLeaderActionToNothing(TRUE);
                }
            }
            else if (action == ACTION_USE_LINK_BOX) {
                item = sub_8044D90(GetLeader(), 0, 15);
                if (!sub_8048B9C(GetLeader(), item)) {
                    SetLeaderActionToNothing(TRUE);
                }
            }
            else if (action == ACTION_SET_ITEM) {
                HandleSetItemAction(GetLeader(), TRUE);
                SetLeaderActionToNothing(TRUE);
                sub_803E708(0x50, 0x4D);
                sub_8052210(0);
                break;
            }
            else if (action == ACTION_UNSET_ITEM) {
                HandleUnsetItemAction(GetLeader(), TRUE);
                SetLeaderActionToNothing(TRUE);
                sub_803E708(0x50, 0x4D);
                sub_8052210(0);
                break;
            }

            if (GetLeaderActionId() != ACTION_NOTHING)
                break;
        }
        else if (chosenOption == MAIN_MENU_TEAM) {
            SetLeaderActionToNothing(TRUE);
            if (ShowDungeonTeamMenu(GetLeader())) {
                r10 = -1;
            }

            if (GetLeaderActionId() == ACTION_CHECK_SUMMARY) {
                ShowDungeonSummaryOrIQMenu(GetLeaderActionContainer(), FALSE);
                SetLeaderActionToNothing(TRUE);
            }
            else if (GetLeaderActionId() == ACTION_TALK_MENU) {
                sub_806752C(GetLeaderActionContainer());
                SetLeaderActionToNothing(TRUE);
            }
            else if (GetLeaderActionId() == ACTION_UNK34) {
                sub_8067768(GetLeaderActionContainer());
                SetLeaderActionToNothing(TRUE);
            }
            else if (GetLeaderActionId() == ACTION_CHANGE_TACTICS) {
                ShowDungeonTacticsMenu(GetLeaderActionContainer());
                SetLeaderActionToNothing(TRUE);
            }
            else if (GetLeaderActionId() == ACTION_VIEW_IQ) {
                ShowDungeonSummaryOrIQMenu(GetLeaderActionContainer(), TRUE);
                SetLeaderActionToNothing(TRUE);
            }
            else if (GetLeaderActionId() == ACTION_CHECK_MOVES) {
                s32 i, count;

                ShowMovesFromTeamMenu(GetLeaderActionContainer());
                count = 0;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (EntityIsValid(teamMon)) {
                        if (i == GetLeaderActionContainer()->actionParameters[0].actionUseIndex) {
                            gTeamMenuChosenId = count;
                            if (GetLeaderActionId() != ACTION_NOTHING) {
                                sub_806A2BC(teamMon, 0);
                            }
                            break;
                        }
                        count++;
                    }
                }
            }

            if (GetLeaderActionId() != ACTION_NOTHING)
                break;
        }
        else if (chosenOption == MAIN_MENU_MOVES) {
            s32 i, currMonId, teamMonsCount, r9;
            Entity *currEntity;

            currMonId = 0;
            SetLeaderActionToNothing(TRUE);
            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                Entity *teamMon = gDungeon->teamPokemon[i];
                if (EntityIsValid(teamMon)) {
                    if (GetEntInfo(teamMon)->isTeamLeader) {
                        currMonId = i;
                        break;
                    }
                }
            }

            while (1) {
                SetLeaderActionToNothing(0);
            LOOP_START_NO_CALL: // Actions 6 and 7 don't call SetLeaderActionToNothing
                currEntity = NULL;
                r9 = 0;
                teamMonsCount = 0;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (sub_8071A8C(teamMon)) {
                        if (i == currMonId) {
                            r9 = teamMonsCount;
                            currEntity = teamMon;
                        }
                        teamMonsCount++;
                    }
                }
                if (currEntity == NULL) {
                    currEntity = GetLeader();
                }

                sub_806A2BC(currEntity, 0);
                ChangeDungeonCameraPos(&currEntity->pos, 0, 1, 1);
                GetLeaderInfo()->action.actionParameters[0].actionUseIndex = currMonId;
                SetLeaderActionToNothing(FALSE);
                if (ShowDungeonMovesMenu(currEntity, 0, 1, r9, teamMonsCount)) {
                    r10 = -1;
                }

                if (GetLeaderActionId() == ACTION_MOVES_MENU_NEXT_MON) {
                    s32 prevMonId = currMonId;
                    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                        if (++currMonId >= MAX_TEAM_MEMBERS) {
                            currMonId = 0;
                        }
                        currEntity = gDungeon->teamPokemon[currMonId];
                        if (sub_8071A8C(currEntity))
                            break;
                    }
                    GetLeaderInfo()->action.actionParameters[0].actionUseIndex = currMonId;
                    if (prevMonId != currMonId) {
                        PlayDungeonCursorSE(0);
                    }
                    goto LOOP_START_NO_CALL;
                }
                else if (GetLeaderActionId() == ACTION_MOVES_MENU_PREV_MON) {
                    s32 prevMonId = currMonId;
                    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                        if (--currMonId < 0) {
                            currMonId = MAX_TEAM_MEMBERS - 1;
                        }
                        currEntity = gDungeon->teamPokemon[currMonId];
                        if (sub_8071A8C(currEntity))
                            break;
                    }
                    GetLeaderInfo()->action.actionParameters[0].actionUseIndex = currMonId;
                    if (prevMonId != currMonId) {
                        PlayDungeonCursorSE(0);
                    }
                    goto LOOP_START_NO_CALL;
                }
                else if (GetLeaderActionId() == ACTION_MOVE_INFO) {
                    ActionShowMoveInfo(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == ACTION_SET_MOVE || GetLeaderActionId() == ACTION_UNSET_MOVE) {
                    ActionSetOrUnsetMove(GetLeaderActionContainer(), FALSE);
                }
                else if (GetLeaderActionId() == ACTION_SWITCH_AI_MOVE) {
                    ActionToggleMoveUsableForAi(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == ACTION_LINK_MOVES) {
                    ActionLinkMoves(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == ACTION_DELINK_MOVES) {
                    ActionDelinkMoves(GetLeaderActionContainer(), FALSE);
                }
                else {
                    break;
                }
            }
            sub_806A2BC(GetLeader(), 0);
            ChangeDungeonCameraPos(&GetLeader()->pos, 0, 1, 1);
            if (GetLeaderActionId() != ACTION_NOTHING)
                break;
        }
        else if (chosenOption == MAIN_MENU_GROUND) {
            Entity *leader = GetLeader();
            const Tile *tile = GetTile(leader->pos.x, leader->pos.y);
            Entity *tileObject = tile->object;
            if (tileObject != NULL) {
                if (GetEntityType(tileObject) == ENTITY_ITEM) {
                    u16 action;

                    SetLeaderActionToNothing(TRUE);
                    var_30.a0_8 = 0;
                    var_30.a0_16 = 1;
                    var_30.a0_24 = 1;
                    var_30.a0_32 = 1;
                    if (ShowDungeonItemsMenu(GetLeader(), &var_30)) {
                        // This actually doesn't do anything, it's just there to make the code match as the compiler does a `lsl r0, r0, #0x10, mov r0, r4`
                        ASM_MATCH_TRICK(leader);
                    }
                    if (sub_805FD3C(&var_30) && ShowDungeonItemsMenu(GetLeader(), &var_30)) {
                        SetLeaderActionToNothing(TRUE);
                    }

                    action = GetLeaderActionId();
                    if (action == ACTION_SHOW_INFO) {
                        sub_8044D90(GetLeader(), 0, 0x10)->flags |= ITEM_FLAG_UNPAID;
                        DungeonShowItemDescription(GetLeaderActionContainer());
                        SetLeaderActionToNothing(TRUE);
                    }
                    else if (action == ACTION_UNK35) {
                        item = sub_8044D90(GetLeader(), 0, 0x11);
                        if (!sub_8048A68(GetLeader(), item)) {
                            SetLeaderActionToNothing(TRUE);
                        }
                    }
                    else if (action == ACTION_UNK10) {
                        item = sub_8044D90(GetLeader(), 0, 0x12);
                        if (!sub_8048950(GetLeader(), item)) {
                            SetLeaderActionToNothing(TRUE);
                        }
                    }
                    else if (action == ACTION_USE_LINK_BOX) {
                        item = sub_8044D90(GetLeader(), 0, 0x13);
                        if (!sub_8048B9C(GetLeader(), item)) {
                            SetLeaderActionToNothing(TRUE);
                        }
                    }
                    if (GetLeaderActionId() != ACTION_NOTHING)
                        break;
                }
                else if (GetEntityType(tileObject) == ENTITY_TRAP) {
                    SetLeaderActionToNothing(TRUE);
                    ShowDungeonTileMenu(GetLeader());
                    if (GetLeaderActionId() != ACTION_NOTHING)
                        break;
                }
            }
            else if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                SetLeaderActionToNothing(TRUE);
                ShowDungeonStairsMenu(GetLeader());
                if (GetLeaderActionId() != ACTION_NOTHING)
                    break;
            }
            else {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
                DisplayDungeonMessage(0, gUnknown_80FDE18, 1);
            }

            r10 = -1;
        }
        else if (chosenOption == MAIN_MENU_OTHERS) {
            ShowDungeonOthersMenu();
            if (gDungeon->unk4)
                break;
            if (GetLeaderActionId() != ACTION_NOTHING)
                break;
            r10 = -1;
        }

        // B button
        if (chosenOption < 0)
            break;

        if (var_24 == 0) {
            ResetRepeatTimers();
            ResetUnusedInputStruct();
        }
        else {
            sub_806A2BC(GetLeader(), 0);
            break;
        }
    }

    sub_803EAF0(0, NULL);
    ResetRepeatTimers();
    ResetUnusedInputStruct();
}

static void PrintOnMainMenu(bool8 printAll)
{
    s32 i, x, y, yLoop;

    gDungeonMenu.menuIndex = 0;
    gDungeonMenu.currPageEntries = 5;
    gDungeonMenu.entriesPerPage = 5;
    gDungeonMenu.currPage = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 2;
    gDungeonMenu.leftRightArrowsPos.x = 0;
    gDungeonMenu.leftRightArrowsPos.y = 0;
    gDungeonMenu.windowId = 0;
    gDungeonMenu.unk14.x = 0;
    ResetTouchScreenMenuInput(&gDungeonMenu.touchScreen);
    sub_80137B0(&gDungeonMenu, 0x38);
    if (printAll) {
        sub_803EAF0(7, NULL);
    }
    else {
        sub_803EAF0(6, NULL);
    }

    sub_80073B8(0);
    if (ShouldMonsterRunAwayAndShowEffect(GetLeader(), TRUE)) {
        gUnknown_202749A[1] = 2;
        gUnknown_202749A[2] = 2;
        gUnknown_202749A[3] = 2;
        gUnknown_202749A[4] = 7;
        gUnknown_202749A[5] = 2;
    }
    else
    {
        gUnknown_202749A[1] = 7;
        gUnknown_202749A[2] = 7;
        gUnknown_202749A[3] = 7;
        gUnknown_202749A[4] = 7;
        gUnknown_202749A[5] = 7;
    }

    y = GetMenuEntryYCoord(&gDungeonMenu, 0);
    PrintStringOnWindow(8, y, gFieldMenuMovesPtr, 0, 0);

    y = GetMenuEntryYCoord(&gDungeonMenu, 1);
    PrintStringOnWindow(8, y, gFieldMenuItemsPtr, 0, 0);

    y = GetMenuEntryYCoord(&gDungeonMenu, 2);
    PrintStringOnWindow(8, y, gFieldMenuTeamPtr, 0, 0);

    y = GetMenuEntryYCoord(&gDungeonMenu, 3);
    PrintStringOnWindow(8, y, gFieldMenuOthersPtr, 0, 0);

    y = GetMenuEntryYCoord(&gDungeonMenu, 4);
    PrintStringOnWindow(8, y, gFieldMenuGroundPtr, 0, 0);

    sub_80073E0(0);
    if (printAll) {
        u32 hours, minutes, seconds;
        EntityInfo *leaderInfo = GetEntInfo(GetLeader());
        const u8 *dungeonName = GetCurrentDungeonName();

        x = (136 - GetStringLineWidth(dungeonName)) / 2;
        sub_80073B8(1);
        PrintStringOnWindow(x, 2, dungeonName, 1, 0);
        sub_80073E0(1);
        sub_80073B8(2);
        DeconstructPlayTime(gPlayTimeRef, &hours, &minutes, &seconds);

        gFormatArgs[0] = FixedPointToInt(leaderInfo->belly);
        gFormatArgs[1] = FixedPointToInt(leaderInfo->maxBelly);
        PrintFormattedStringOnWindow(0x73, 0, gUnknown_80F9174, 2, 0);

        gFormatArgs[0] = gTeamInventoryRef->teamMoney;
        PrintFormattedStringOnWindow(0x73, 12, gUnknown_80F9190, 2, 0);

        GetWeatherName(gFormatBuffer_Monsters[0], GetApparentWeather(NULL));
        PrintFormattedStringOnWindow(0x73, 24, gUnknown_80F91A8, 2, 0);

        gFormatArgs[0] = hours;
        gFormatArgs[1] = minutes;
        gFormatArgs[2] = seconds;
        PrintFormattedStringOnWindow(0x73, 36, gUnknown_80F91C8, 2, 0);
        for (yLoop = 0, i = 0; i < MAX_TEAM_MEMBERS; i++) {
            Entity *teamMon = gDungeon->teamPokemon[i];
            if (EntityIsValid(teamMon)) {
                EntityInfo *monInfo = GetEntInfo(teamMon);
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], teamMon, 0);
                gFormatArgs[0] = monInfo->HP;
                gFormatArgs[1] = monInfo->maxHPStat;
                PrintFormattedStringOnWindow(4, yLoop, gUnknown_80F91E0, 2, 0);
                yLoop += 12;
                if (yLoop >= 12 * MAX_TEAM_MEMBERS)
                    break;
            }
        }
        sub_80073E0(2);
    }
}

bool8 DungeonGiveNameToRecruitedMon(u8 *name)
{
    s32 r4;
    sub_803EAF0(8, name);
    do
    {
        DungeonRunFrameActions(0xE);
        DrawDialogueBoxString();
        r4 = sub_8016080();
    } while (r4 == 0);
    CleanConfirmNameMenu();
    DungeonRunFrameActions(0xE);
    sub_803EAF0(0, NULL);
    if (r4 == 3 && *name != '\0')
        return TRUE;

    return FALSE;
}
