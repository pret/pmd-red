#include "global.h"
#include "structs/str_dungeon.h"
#include "number_util.h"
#include "input.h"
#include "structs/map.h"
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
extern void sub_8083D44(void);
extern void sub_8083D30(void);
extern void sub_8083D08(void);
extern void sub_806A6E8(Entity *);
extern bool8 sub_8047084(s32 itemFlag);
extern void HandleTrap(Entity *pokemon, DungeonPos *pos, int param_3, char param_4);
extern void sub_8045DB4(DungeonPos *, u32);
bool8 sub_807EF48(void);
void sub_806A2BC(Entity *a0, u8 a1);
bool8 sub_805E874(void);
bool8 sub_80701A4(Entity *a0);
void sub_80647F0(Entity *a0);
void sub_805E738(Entity *a0);
void sub_803E708(s32 a0, s32 a1);
void sub_8040A78(void);
void sub_805E804(void);
void sub_8064BE0(void);
void sub_8075680(u32);
void sub_8094C88(void);
void sub_8040A84(void);
void sub_8047158(void);
void sub_806A914(u8 a0, u8 a1, u8 a2);
void sub_8044C10(u8 a0);
u16 GetLeaderActionId(void);
void sub_80978C8(s16 a0);
static void TryCreateModeArrows(Entity *leader);
bool8 sub_8094C48(void);
bool8 sub_805EC4C(Entity *a0, u8 a1);
void sub_803E724(s32 a0);
void HandleTalkFieldAction(Entity *);
bool8 sub_8044B28(void);
bool8 IsNotAttacking(Entity *param_1, bool8 param_2);
void ShowFieldMenu(u8 a0, bool8 a1);
bool8 sub_805EF60(Entity *a0, EntityInfo *a1);
s32 GetTeamMemberEntityIndex(Entity *pokemon);
bool8 sub_8070F80(Entity * pokemon, s32 direction);
void DrawFieldMenu(u8 a0);
bool8 sub_805FD74(Entity * a0, struct UnkMenuBitsStruct *a1);
bool8 sub_805FD3C(struct UnkMenuBitsStruct *a0);
void sub_8060D24(UNUSED ActionContainer *a0);
bool8 sub_8060E38(Entity *a0);
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
void sub_804A728(DungeonPos *pos, s32 a1, u8 a2, u8 a3);
extern bool8 sub_8071A8C(Entity *pokemon);
extern void sub_80643AC(Entity *pokemon);
extern bool8 sub_8062F90(Entity * entity, u8 a1, u8 a2, s32 a3, s32 a4);

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

static EWRAM_DATA bool8 sInDiagonalMode = 0;
static EWRAM_DATA bool8 sInRotateMode = 0;
// Frames counter for arrows in diagonal/rotate mode.
static EWRAM_DATA s16 sArrowsFrames = 0;
// If both of these are set to TRUE, there are 3 arrows visible instead of 1 in rotate mode
static EWRAM_DATA bool8 sShowThreeArrows1 = 0;
static EWRAM_DATA bool8 sShowThreeArrows2 = 0;

void DungeonHandlePlayerInput(void)
{
    struct UnkMenuBitsStruct r6;
    bool8 triggers[5]; // Always FALSE, if one of these is TRUE - they can open various menus or cause an item throw. Most likely used for debugging/testing.
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
    sub_8040A78();
    if (gDungeon->unk1 != 0) {
        gDungeon->unk1 = 0;
        if (!ShouldMonsterRunAwayAndShowEffect(GetLeader(), TRUE)) {
            sub_8044C10(1);
            sub_805E804();
            sub_80647F0(GetLeader());
            ResetRepeatTimers();
            ResetUnusedInputStruct();
            if (GetLeaderActionId() != 0) {
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
            if (sub_805E874() != 0) {
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
            bool32 bPress, rPress, unkBool; // Always FALSE, might've been used as debug variables.
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
                unkPtr->unk1821B = leaderInfo->action.direction;
                unkPtr->unk1821C = 0xFF;
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
                gUnknown_202EE00 = 1;
                gDungeon->unk181e8.unk18214 = 1;
                if (!sub_8094C48()) {
                    sub_8094C88();
                }
                sub_8052210(1);
                sub_8040A84();
                SetBGOBJEnableFlags(0x1E);
                sub_803E708(0xA, 0x2F);
                while (1) {
                    sub_803E46C(0x2F);
                    if (gRealInputs.pressed & SELECT_BUTTON)
                        break;
                    if (gRealInputs.pressed & B_BUTTON)
                        break;

                    if (gRealInputs.pressed & A_BUTTON) {
                        gUnknown_202EE00 = (gUnknown_202EE00 == 0) ? 1 : 0; // Flip
                        sub_8040A84();
                    }
                }
                gDungeon->unk181e8.unk18214 = 0;
                gGameOptionsRef->mapOption = prevMapOption;
                gUnknown_202EE00 = 1;
                sub_8040A84();
                SetBGOBJEnableFlags(0);
                sub_803E46C(0x2F);
                sub_803E46C(0x2F);
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
                    unkPtr->unk1821B = directionNew;
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
            sub_803E46C(0xF);
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
                    sub_803E46C(0xF);
                }
                break;
            }
            sub_803E46C(0xF);
        }
        else {
            sub_803E46C(0xF);
            sub_8047158();
            ShowFieldMenu((r6.a0_16 == 0) ? 1 : 0, r6.a0_24);
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
            sub_803E46C(0xF);
            if (gDungeon->unk4 != 0)
                break;
        }
    }
}

struct UnkStruct_8106AC8
{
    s16 unk0;
    s16 unk2;
    u8 unk4;
    u8 unk5;
};

extern const struct UnkStruct_8106AC8 gUnknown_8106AC8[];

struct UnkStruct_8106AE8
{
    s16 unk0;
    s16 unk2;
    u32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
};

extern const struct UnkStruct_8106AE8 gUnknown_8106AE8[];

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

            matrixNum = (gUnknown_8106AC8[i].unk4 != 0) ? 8 : 0;

            if (gUnknown_8106AC8[i].unk5)
                matrixNum += 16;

            SpriteSetMatrixNum_UseLocalVar(&sprite, matrixNum);
            SpriteSetSize(&sprite, 0);

            SpriteSetTileNum(&sprite, 0x213);
            SpriteSetPriority(&sprite, 2);
            SpriteSetPalNum(&sprite, 0);

            SpriteSetUnk6_0(&sprite, 0);
            SpriteSetUnk6_1(&sprite, 0);

            xMul = gUnknown_8106AC8[i].unk0 * 10;
            x2 = (sArrowsFrames / 2) & 7;
            x = (x2 * gUnknown_8106AC8[i].unk0) + xMul + 116;
            SpriteSetX(&sprite, x);

            yMul = gUnknown_8106AC8[i].unk2 * 10;
            y2 = (sArrowsFrames / 2) & 7;
            y = (y2 * gUnknown_8106AC8[i].unk2) + yMul + 82;
            SpriteSetY(&sprite, y);

            AddSprite(&sprite, 0x100, NULL, NULL);
        }
    }

    else if (unkPtr->unk1821A) {
        s32 i;
        SpriteOAM sprite;
        s32 var_2C = unkPtr->unk1821B;

        if (unkPtr->unk1821B < 8) {
            s32 x, xMul, x2;
            s32 y, yMul, y2;
            s32 to = (sShowThreeArrows2 != FALSE && sShowThreeArrows1 != FALSE) ? 3 : 1;

            xMul = gUnknown_8106AE8[var_2C].unk0 * 10;
            x2 = (sArrowsFrames / 2) & 7;
            x = (gUnknown_8106AE8[var_2C].unk0 * x2) + xMul + 116;

            yMul = gUnknown_8106AE8[var_2C].unk2 * 10;
            y2 = (sArrowsFrames / 2) & 7;
            y = (y2 * gUnknown_8106AE8[var_2C].unk2) + yMul + 82;
            for (i = 0; i < to; i++) {
                u32 matrixNum;

                SpriteSetAffine1(&sprite, 0);
                SpriteSetAffine2(&sprite, 0);
                SpriteSetObjMode(&sprite, 1);
                SpriteSetMosaic(&sprite, 0);
                SpriteSetBpp(&sprite, 0);
                SpriteSetShape(&sprite, 0);

                matrixNum = (gUnknown_8106AE8[var_2C].unk8 != 0) ? 8 : 0;

                if (gUnknown_8106AE8[var_2C].unk9)
                    matrixNum += 16;

                SpriteSetMatrixNum_UseLocalVar(&sprite, matrixNum);
                SpriteSetSize(&sprite, 0);

                SpriteSetTileNum(&sprite, gUnknown_8106AE8[var_2C].unk4);
                SpriteSetPriority(&sprite, 2);
                SpriteSetPalNum(&sprite, 0);

                SpriteSetUnk6_0(&sprite, 0);
                SpriteSetUnk6_1(&sprite, 0);

                SpriteSetX(&sprite, x);
                SpriteSetY(&sprite, y);

                AddSprite(&sprite, 0x100, NULL, NULL);
                x += gUnknown_8106AE8[var_2C].unk0 * 4;
                y += gUnknown_8106AE8[var_2C].unk2 * 4;
            }
        }
    }

    if (sInRotateMode && unkPtr->unk1821C != unkPtr->unk1821B) {
        unkPtr->unk1821C = unkPtr->unk1821B;
        sub_804A728(&leader->pos, unkPtr->unk1821B, 0, sInRotateMode);
    }
}

void sub_805E738(Entity *a0)
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
        sub_803E46C(0x54);
    }
}

extern bool8 sub_8070F14(Entity * pokemon, s32 direction);
bool8 sub_805EC2C(Entity *a0, s32 x, s32 y);

bool8 sub_805E874(void)
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
                    if (gDungeon->unk181e8.unk1820F)
                        return FALSE;
                }
            }
            else if (i == 0 || j == 0) {
                if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP) {
                    if (tile->object->isVisible)
                        return FALSE;
                    if (gDungeon->unk181e8.unk1820F)
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

bool8 sub_805EC2C(Entity *a0, s32 x, s32 y)
{
    DungeonPos pos = {.x = x, .y = y};
    return sub_8070564(a0, &pos);
}

bool8 sub_805EC4C(Entity *a0, u8 a1)
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
                sub_8045DB4(&leader->pos, 1);
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

extern Entity *sub_80696A8(Entity *a0);
extern u8 sub_806A538(s32);

bool8 sub_805EF60(Entity *a0, EntityInfo *a1)
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

extern void sub_803EAF0(u32, u8 *);
extern void sub_803F508(Entity *);
extern void sub_8041AD0(Entity *pokemon);
extern void sub_8041AE0(Entity *pokemon);
extern void sub_807EC28(bool8);
extern void sub_8083CE0(u8 param_1);

extern MenuInputStruct gUnknown_202EE10;

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
    else if (sub_8047084(ITEM_FLAG_IN_SHOP) || sub_807EF48()) {
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
            PokemonStruct2 *mon = &gRecruitedPokemonRef->pokemon2[i];
            PokemonStruct1 *r5 = NULL;

            if ((u8)mon->unk0 & 1) {
                if (!sub_806A538(mon->unkA)) {
                    r5 = &gRecruitedPokemonRef->pokemon[mon->unkA];
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

// Could this be a start of a new file?
static UNUSED EWRAM_DATA u8 sUnused[4] = {0};
static EWRAM_DATA ActionParameter sUnknownActionUnk4 = {0};
static EWRAM_DATA s32 sUnknown_202F240 = 0;
static UNUSED EWRAM_DATA u8 sUnused2[4] = {0};
static EWRAM_DATA s16 sUnknown_202F248[8] = {0};
static EWRAM_DATA s32 sUnknown_202F258 = 0;
static UNUSED EWRAM_DATA u8 sUnused3[4] = {0};
static EWRAM_DATA s32 sTeamMenuChosenId = 0;
static UNUSED EWRAM_DATA u8 sUnused4[4] = {0};

void ShowFieldMenu(u8 a0_, bool8 a1)
{
    Item *item;
    s32 r10;
    u8 a0 = a0_; // Needed to match.
    s32 var_28;
    s32 var_24;
    struct UnkMenuBitsStruct var_30;
    struct UnkMenuBitsStruct var_34;

    r10 = gDungeon->unk5C0;
    var_28 = 0;
    var_24 = (gDungeon->unk5C0 > - 1);
    gDungeon->unk5C0 = -1;
    if (r10 >= 0) {
        var_28 = r10;
    }

    if (a1) {
        PlayFanfareSE(0x137, 0x100);
    }
    else {
        sub_8083D44();
    }

    while (1) {
        if (r10 < 0) {
            sub_8044C10(1);
            sTeamMenuChosenId = -1;
            DrawFieldMenu(a0);
            sub_806A2BC(GetLeader(), 0);
            while (1) {
                AddMenuCursorSprite(&gUnknown_202EE10);
                sub_803E46C(0x1D);
                if (gRealInputs.repeated & DPAD_DOWN) {
                    sub_8083CE0(1);
                    sub_80136E0(&gUnknown_202EE10, 1);
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    sub_8083CE0(1);
                    sub_8013744(&gUnknown_202EE10, 1);
                }
                if ((gRealInputs.pressed & A_BUTTON || gUnknown_202EE10.unk28.a_button)) {
                    if (gUnknown_202749A[gUnknown_202EE10.menuIndex + 1] == 7) {
                        sub_8083D08();
                        var_28 = gUnknown_202EE10.menuIndex;
                        break;
                    }
                    sub_8083D30();
                }
                if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                    sub_8083D30();
                    var_28 = -1;
                    break;
                }
            }
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x1D);
            a0 = 1;
        }

        r10 = var_28;
        if (var_28 == 1) {
            u16 action;

            sub_8044C10(1);
            var_34.a0_8 = 0;
            var_34.a0_16 = 1;
            var_34.a0_24 = 0;
            var_34.a0_32 = 0;
            if (sub_805FD74(GetLeader(), &var_34)) {
                r10 = -1;
            }
            if (sub_805FD3C(&var_34) && sub_805FD74(GetLeader(), &var_34)) {
                sub_8044C10(1);
            }
            action = GetLeaderActionId();
            if (action == 12) {
                sub_8044D90(GetLeader(), 0, 12)->flags |= ITEM_FLAG_UNPAID;
                sub_8060D24(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (action == 53) {
                item = sub_8044D90(GetLeader(), 0, 13);
                if (!sub_8048A68(GetLeader(), item)) {
                    sub_8044C10(1);
                }
            }
            else if (action == 16) {
                item = sub_8044D90(GetLeader(), 0, 14);
                if (!sub_8048950(GetLeader(), item)) {
                    sub_8044C10(1);
                }
            }
            else if (action == 44) {
                item = sub_8044D90(GetLeader(), 0, 15);
                if (!sub_8048B9C(GetLeader(), item)) {
                    sub_8044C10(1);
                }
            }
            else if (action == 60) {
                HandleSetItemAction(GetLeader(), TRUE);
                sub_8044C10(1);
                sub_803E708(0x50, 0x4D);
                sub_8052210(0);
                break;
            }
            else if (action == 61) {
                HandleUnsetItemAction(GetLeader(), TRUE);
                sub_8044C10(1);
                sub_803E708(0x50, 0x4D);
                sub_8052210(0);
                break;
            }

            if (GetLeaderActionId() != 0)
                break;
        }
        else if (var_28 == 2) {
            sub_8044C10(1);
            if (sub_8060E38(GetLeader())) {
                r10 = -1;
            }

            if (GetLeaderActionId() == 0x1B) {
                sub_8061A38(GetLeaderActionContainer(), FALSE);
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x1C) {
                sub_806752C(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x34) {
                sub_8067768(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x1A) {
                ShowTacticsMenu(GetLeaderActionContainer());
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x30) {
                sub_8061A38(GetLeaderActionContainer(), TRUE);
                sub_8044C10(1);
            }
            else if (GetLeaderActionId() == 0x19) {
                s32 i, count;

                sub_8062D8C(GetLeaderActionContainer());
                count = 0;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (EntityIsValid(teamMon)) {
                        if (i == GetLeaderActionContainer()->actionParameters[0].actionUseIndex) {
                            sTeamMenuChosenId = count;
                            if (GetLeaderActionId() != 0) {
                                sub_806A2BC(teamMon, 0);
                            }
                            break;
                        }
                        count++;
                    }
                }
            }

            if (GetLeaderActionId() != 0)
                break;
        }
        else if (var_28 == 0) {
            s32 i, r7, r8, r9, r4;
            Entity *r6;

            r7 = 0;
            sub_8044C10(1);
            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                Entity *teamMon = gDungeon->teamPokemon[i];
                if (EntityIsValid(teamMon)) {
                    if (GetEntInfo(teamMon)->isTeamLeader) {
                        r7 = i;
                        break;
                    }
                }
            }


            while (1) {
                sub_8044C10(0);
            LOOP_START_NO_CALL: // Actions 6 and 7 don't call sub_8044C10
                r6 = NULL;
                r9 = 0;
                r8 = 0;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                    Entity *teamMon = gDungeon->teamPokemon[i];
                    if (sub_8071A8C(teamMon)) {
                        if (i == r7) {
                            r9 = r8;
                            r6 = teamMon;
                        }
                        r8++;
                    }
                }
                if (r6 == NULL) {
                    r6 = GetLeader();
                }

                sub_806A2BC(r6, 0);
                sub_804A728(&r6->pos, 0, 1, 1);
                GetLeaderInfo()->action.actionParameters[0].actionUseIndex = r7;
                sub_8044C10(0);
                if (sub_8062F90(r6, 0, 1, r9, r8)) {
                    r10 = -1;
                }

                if (GetLeaderActionId() == 6) {
                    r4 = r7;
                    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                        if (++r7 >= MAX_TEAM_MEMBERS) {
                            r7 = 0;
                        }
                        r6 = gDungeon->teamPokemon[r7];
                        if (sub_8071A8C(r6))
                            break;
                    }
                    GetLeaderInfo()->action.actionParameters[0].actionUseIndex = r7;
                    if (r4 != r7) {
                        sub_8083CE0(0);
                    }
                    goto LOOP_START_NO_CALL;
                }
                else if (GetLeaderActionId() == 7) {
                    r4 = r7;
                    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                        if (--r7 < 0) {
                            r7 = MAX_TEAM_MEMBERS - 1;
                        }
                        r6 = gDungeon->teamPokemon[r7];
                        if (sub_8071A8C(r6))
                            break;
                    }
                    GetLeaderInfo()->action.actionParameters[0].actionUseIndex = r7;
                    if (r4 != r7) {
                        sub_8083CE0(0);
                    }
                    goto LOOP_START_NO_CALL;
                }
                else if (GetLeaderActionId() == 0x1D) {
                    sub_80637E8(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == 0x1E || GetLeaderActionId() == 0x33) {
                    sub_8063A70(GetLeaderActionContainer(), FALSE);
                }
                else if (GetLeaderActionId() == 0x1F) {
                    sub_8063B54(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == 0x20) {
                    sub_8063BB4(GetLeaderActionContainer());
                }
                else if (GetLeaderActionId() == 0x21) {
                    sub_8063CF0(GetLeaderActionContainer(), FALSE);
                }
                else {
                    break;
                }
            }
            sub_806A2BC(GetLeader(), 0);
            sub_804A728(&GetLeader()->pos, 0, 1, 1);
            if (GetLeaderActionId() != 0)
                break;
        }
        else if (var_28 == 4) {
            Entity *leader = GetLeader();
            const Tile *tile = GetTile(leader->pos.x, leader->pos.y);
            Entity *tileObject = tile->object;
            if (tileObject != NULL) {
                if (GetEntityType(tileObject) == ENTITY_ITEM) {
                    u16 action;

                    sub_8044C10(1);
                    var_30.a0_8 = 0;
                    var_30.a0_16 = 1;
                    var_30.a0_24 = 1;
                    var_30.a0_32 = 1;
                    if (sub_805FD74(GetLeader(), &var_30)) {
                        // This actually doesn't do anything, it's just there to make the code match as the compiler does a `lsl r0, r0, #0x10, mov r0, r4`
                        ASM_MATCH_TRICK(leader);
                    }
                    if (sub_805FD3C(&var_30) && sub_805FD74(GetLeader(), &var_30)) {
                        sub_8044C10(1);
                    }

                    action = GetLeaderActionId();
                    if (action == 0xC) {
                        sub_8044D90(GetLeader(), 0, 0x10)->flags |= ITEM_FLAG_UNPAID;
                        sub_8060D24(GetLeaderActionContainer());
                        sub_8044C10(1);
                    }
                    else if (action == 0x35) {
                        item = sub_8044D90(GetLeader(), 0, 0x11);
                        if (!sub_8048A68(GetLeader(), item)) {
                            sub_8044C10(1);
                        }
                    }
                    else if (action == 0x10) {
                        item = sub_8044D90(GetLeader(), 0, 0x12);
                        if (!sub_8048950(GetLeader(), item)) {
                            sub_8044C10(1);
                        }
                    }
                    else if (action == 0x2C) {
                        item = sub_8044D90(GetLeader(), 0, 0x13);
                        if (!sub_8048B9C(GetLeader(), item)) {
                            sub_8044C10(1);
                        }
                    }
                    if (GetLeaderActionId() != 0)
                        break;
                }
                else if (GetEntityType(tileObject) == ENTITY_TRAP) {
                    sub_8044C10(1);
                    sub_80643AC(GetLeader());
                    if (GetLeaderActionId() != 0)
                        break;
                }
            }
            else
            {
                if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                    sub_8044C10(1);
                    sub_80647F0(GetLeader());
                    if (GetLeaderActionId() != 0)
                        break;
                }
                else {
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
                    DisplayDungeonMessage(0, gUnknown_80FDE18, 1);
                }
            }
            r10 = -1;
        }
        else if (var_28 == 3) {
            sub_8064BE0();
            if (gDungeon->unk4)
                break;
            if (GetLeaderActionId() != 0)
                break;
            r10 = -1;
        }

        if (var_28 < 0)
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

const u8 *GetCurrentDungeonName(void);
void GetWeatherName(u8 *dst, u8 weatherId);

extern s32 gFormatArgs[];

void DrawFieldMenu(u8 a0)
{
    s32 i, x, y, yLoop;

    gUnknown_202EE10.menuIndex = 0;
    gUnknown_202EE10.unk1A = 5;
    gUnknown_202EE10.unk1C = 5;
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.firstEntryY = 2;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk0 = 0;
    gUnknown_202EE10.unk14.x = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
    sub_80137B0(&gUnknown_202EE10, 0x38);
    if (a0) {
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

    y = GetMenuEntryYCoord(&gUnknown_202EE10, 0);
    PrintStringOnWindow(8, y, gFieldMenuMovesPtr, 0, 0);

    y = GetMenuEntryYCoord(&gUnknown_202EE10, 1);
    PrintStringOnWindow(8, y, gFieldMenuItemsPtr, 0, 0);

    y = GetMenuEntryYCoord(&gUnknown_202EE10, 2);
    PrintStringOnWindow(8, y, gFieldMenuTeamPtr, 0, 0);

    y = GetMenuEntryYCoord(&gUnknown_202EE10, 3);
    PrintStringOnWindow(8, y, gFieldMenuOthersPtr, 0, 0);

    y = GetMenuEntryYCoord(&gUnknown_202EE10, 4);
    PrintStringOnWindow(8, y, gFieldMenuGroundPtr, 0, 0);

    sub_80073E0(0);
    if (a0) {
        u32 hours, minutes, seconds;
        EntityInfo *leaderInfo = GetEntInfo(GetLeader());
        const u8 *dungeonName = GetCurrentDungeonName();

        x = (136 - sub_8008ED0(dungeonName)) / 2;
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

bool8 sub_805FBE8(u8 *a0)
{
    s32 r4;
    sub_803EAF0(8, a0);
    do
    {
        sub_803E46C(0xE);
        DrawDialogueBoxString();
        r4 = sub_8016080();
    } while (r4 == 0);
    CleanConfirmNameMenu();
    sub_803E46C(0xE);
    sub_803EAF0(0, NULL);
    if (r4 == 3 && *a0 != 0)
        return TRUE;

    return FALSE;
}

extern u8 *sub_8044EC8(s32 param_1);
extern bool8 sub_8044F3C(s32 param_1);
extern s32 gUnknown_202EE6C;
extern const u8 gUnknown_8106B50[];

extern void sub_803ECB4(Windows *a0, u8 a1);
static void CreateFieldItemMenu(s32 a0, Entity *a1, bool8 a2, bool8 a3, Windows *a4, WindowHeader *a5);

void sub_805FC30(Windows *a0, s32 a1)
{
    s32 i;
    Windows windows = {
        .id = {
            [0] = WINDOW_DUMMY,
            [1] = {
                .type = WINDOW_TYPE_NORMAL,
                .pos = {22, 4},
                .width = 6,
                .height = 4,
                .unk10 = 4,
            },
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };

    windows.id[0] = a0->id[0];
    windows.id[0].unk0 = 0x80;

    gUnknown_202EE10.menuIndex = 0;
    gUnknown_202EE10.unk1C = gUnknown_202EE6C;
    gUnknown_202EE10.unk1A = gUnknown_202EE6C;
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk20 = 0;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.firstEntryY = 0;
    gUnknown_202EE10.unk0 = 1;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk14 = gUnknown_202EE10.unk8;

    sub_801317C(&gUnknown_202EE10.unk28);

    windows.id[1].pos.x = a1;
    windows.id[1].width = 28 - a1;
    windows.id[1].height = windows.id[1].unk10 = sub_80095E4(gUnknown_202EE10.unk1C, 0);
    sub_803ECB4(&windows, 0);
    sub_80137B0(&gUnknown_202EE10, windows.id[1].height * 8);
    sub_80073B8(1);

    for (i = 0; i < gUnknown_202EE6C; i++) {
        s32 r4, y;
        u8 text[20];

        r4 = (sub_8044F3C(i) != 0) ? 7 : 2;
        sprintfStatic(text, gUnknown_8106B50, r4, sub_8044EC8(i));
        y = GetMenuEntryYCoord(&gUnknown_202EE10, i);
        PrintStringOnWindow(8, y, text, 1, 0);
    }
    sub_80073E0(1);
}

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

s32 sub_8060D64(s16 *a0, bool8 a1, bool8 a2, bool8 a3, Entity *a4);

void sub_8060890(DungeonPos *a0);
bool8 sub_8060860(s32 a0);
void sub_8060900(Entity *a0);
s32 sub_8060800(WindowHeader *a0, s32 a1);
void sub_8060CE8(ActionContainer *a0);
Entity *DrawFieldGiveItemMenu(s32 *teamId, s32 a1);

bool8 sub_805FD74(Entity * a0, struct UnkMenuBitsStruct *a1)
{
    s32 i, i_r6;
    s32 r8;
    s32 r9 = 0;

    u8 var_34 = 1;
    u8 var_30 = 0;
    u8 var_2C = 0;
    u8 var_28 = 0;
    EntityInfo *a0Info = GetEntInfo(a0);
    WindowHeader var_3C;

    Windows var_FC =
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
                .unk14 = &var_3C,
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
        CreateFieldItemMenu(r8, a0, var_2C, var_30, &var_FC, &var_3C);

        id = sUnknown_202F248[gUnknown_202EE10.unk1E];
        if (id >= MAX_TEAM_MEMBERS) {
            r4 = gDungeon->teamPokemon[id - MAX_TEAM_MEMBERS];
        }
        else {
            r4 = a0;
        }
        sub_806A2BC(r4, 0);
        sub_804A728(&r4->pos, 0, 1, 1);

        while (1) {
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x14);
            if (!var_30) {
                if (sUnknown_202F258 > 1) {
                    if ((gRealInputs.pressed & DPAD_LEFT) || gUnknown_202EE10.unk28.dpad_left) {
                        sub_8083CE0(0);
                        if (--r8 < 0) {
                            r8 = sUnknown_202F258 - 1;
                        }
                        sUnknown_202F240 = var_30;
                        break;
                    }
                    if ((gRealInputs.pressed & DPAD_RIGHT) || gUnknown_202EE10.unk28.dpad_right) {
                        sub_8083CE0(0);
                        if (++r8 == sUnknown_202F258) {
                            r8 = 0;
                        }
                        sUnknown_202F240 = var_30;
                        break;
                    }
                }
                if (gRealInputs.repeated & DPAD_DOWN && sub_8060860(r8)) {
                    sub_8083CE0(1);
                    sub_80136E0(&gUnknown_202EE10, 1);
                }
                if (gRealInputs.repeated & DPAD_UP && sub_8060860(r8)) {
                    sub_8083CE0(1);
                    sub_8013744(&gUnknown_202EE10, 1);
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
                if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                    sub_8083D08();
                    sub_8060890(&a0->pos);
                    r9 = 1;
                    break;
                }
                if (gRealInputs.pressed & START_BUTTON) {
                    sub_8083D44();
                    sub_8060890(&a0->pos);
                    r9 = 3;
                    break;
                }
                if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                    sub_8083D30();
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
        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x14);
        if (sUnknown_202F248[gUnknown_202EE10.unk1E] <= 1 && !(gTeamInventoryRef->teamItems[0].flags & ITEM_FLAG_EXISTS)) {
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
            sUnknown_202F240 = gUnknown_202EE10.menuIndex;
            if (var_2C != 0) {
                a0Info->action.actionParameters[1] = sUnknownActionUnk4;
                sub_803EAF0(0, NULL);
                r9 = 0;
                break;
            }

            sub_8060900(a0);
            sub_8060800(&var_3C, gUnknown_202EE10.unk1E);
            sub_805FC30(&var_FC, 0x16);
            while (1) {
                AddMenuCursorSprite(&gUnknown_202EE10);
                sub_803E46C(0x14);
                if (gRealInputs.repeated & DPAD_DOWN) {
                    sub_8083CE0(1);
                    sub_80136E0(&gUnknown_202EE10, 1);
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    sub_8083CE0(1);
                    sub_8013744(&gUnknown_202EE10, 1);
                }
                if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                    if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                        sub_8083D08();
                        sub_8060CE8(&a0Info->action);
                        r9 = 0;
                        break;
                    }
                    sub_8083D30();
                }
                if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                    sub_8083D30();
                    r9 = 1;
                    break;
                }
            }
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x14);
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
                    sub_8044C10(1);
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

static void CreateFieldItemMenu(s32 a0, Entity *a1, bool8 a2, bool8 a3, Windows *windows, WindowHeader *a5)
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
    gUnknown_202EE10.menuIndex = sUnknown_202F240;
    gUnknown_202EE10.unk1A = 0;
    gUnknown_202EE10.unk1E = a0;
    gUnknown_202EE10.unk20 = sUnknown_202F258;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.unk0 = 0;
    gUnknown_202EE10.unk14.x = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
    gDungeon->unk181e8.unk18212 = 0;
    switch (sUnknown_202F248[a0]) {
        case 0:
        case 1:
            windows->id[0].unk10 = 0x10;
            windows->id[0].height = 0x10;
            a5->f2 = 0xC;
            gUnknown_202EE10.firstEntryY = 0x10;
            gUnknown_202EE10.unk1C = 0xA;
            gDungeon->unk181e8.unk18212 = 1;
            break;
        case 2:
            windows->id[0].unk10 = 4;
            windows->id[0].height = 4;
            a5->f2 = 6;
            gUnknown_202EE10.firstEntryY = 0x12;
            gUnknown_202EE10.unk1C = 1;
            break;
        case 3:
        default:
            windows->id[0].unk10 = 4;
            windows->id[0].height = 4;
            a5->f2 = 0xC;
            gUnknown_202EE10.firstEntryY = 0x12;
            gUnknown_202EE10.unk1C = 1;
            break;
    }

    if (a2) {
        gUnknown_202EE10.unkC += 0x40;
        windows->id[0].pos.x = 0xA;
        windows->id[1] = var_94;
    }
    else {
        windows->id[0].pos.x = 2;
        windows->id[1] = windows->id[3];
    }

    sub_803ECB4(windows, 1);
    txtStrPtr = &gUnknown_2027370[0];
    gUnknown_202EE10.unkC = (txtStrPtr->unk0 + 0x10) * 8;
    gUnknown_202EE10.unkE = ((txtStrPtr->unk2 + 1) * 8) - 2;
    sub_80137B0(&gUnknown_202EE10, 0x70);
    sub_80073B8(0);
    x = ((a0 - r10) * 8) + 0xC;
    switch (sUnknown_202F248[a0])
    {
    case 0:
        PrintFormattedStringOnWindow(x, 0, gTeamToolboxAPtr, 0, 0);
        for (i = 0; i < 10; i++) {
            if (ItemExists(&gTeamInventoryRef->teamItems[i])) {
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, &gTeamInventoryRef->teamItems[i], &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gUnknown_202EE10, i);
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
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, &gTeamInventoryRef->teamItems[i + 10], &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gUnknown_202EE10, i);
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
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gUnknown_202EE10, 0);
                PrintFormattedStringOnWindow(8, y, txtBuff, 0, 0);
            }
            if (a3) {
                gUnknown_202EE10.unk8.x = gUnknown_202EE10.unk8.y = 0;
            }
        }
        break;
    case 3: {
            Item *item = &GetEntInfo(a1)->heldItem;
            SetMessageArgument_2(gFormatBuffer_Monsters[0], a1Info, 0);
            PrintFormattedStringOnWindow(x, 0, gUnknown_80FE940, 0, 0);
            if (item->flags & ITEM_FLAG_EXISTS) {
                gUnknown_202EE10.unk1A++;
                sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                y = GetMenuEntryYCoord(&gUnknown_202EE10, 0);
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
                    gUnknown_202EE10.unk1A++;
                    sub_8090E14(txtBuff, item, &gUnknown_8106B60);
                    y = GetMenuEntryYCoord(&gUnknown_202EE10, 0);
                    PrintFormattedStringOnWindow(8, y, txtBuff, 0, 0);
                }
            }
        }
        break;
    }

    if (gUnknown_202EE10.menuIndex >= gUnknown_202EE10.unk1A) {
        gUnknown_202EE10.menuIndex = 0;
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
    if (gUnknown_202EE10.unk1A <= 1 || sUnknown_202F248[a0] > 1)
        return FALSE;
    else
        return TRUE;
}

void sub_8060890(DungeonPos *a0)
{
    s32 var = sUnknown_202F248[gUnknown_202EE10.unk1E];
    switch (var)
    {
    case 0:
        sUnknownActionUnk4.actionUseIndex = gUnknown_202EE10.menuIndex + 1;
        break;
    case 1:
        sUnknownActionUnk4.actionUseIndex = gUnknown_202EE10.menuIndex + 11;
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

    gUnknown_202EE6C = 0;
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

void sub_8060CE8(ActionContainer *a0)
{
    SetMonsterActionFields(a0, gUnknown_202EE44[gUnknown_202EE10.menuIndex].unk0);
    a0->actionParameters[0] = sUnknownActionUnk4;
    a0->actionParameters[1].actionUseIndex = 0;
    a0->actionParameters[1].itemPos.x = 0;
    a0->actionParameters[1].itemPos.y = 0;
}

void sub_8060D24(UNUSED ActionContainer *a0)
{
    Item *item = sub_8044D90(GetLeader(), 0, 0xB);
    sub_803ECB4(NULL, 0);
    sub_801B3C0(item);

    do {
        sub_803E46C(0x16);
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

void DrawFieldTeamMenu(struct UnkFieldTeamMenuStruct *a0, Windows *a1, bool8 a2);
void sub_806145C(struct UnkFieldTeamMenuStruct *a0);
void sub_80615B4(ActionContainer *a0, struct UnkFieldTeamMenuStruct *a1);

extern u8 gUnknown_202EE39;

bool8 sub_8060E38(Entity *a0)
{
    s32 i;
    bool32 r10, ret;

    struct UnkFieldTeamMenuStruct sp;
    Windows var_84 = {0};

    var_84.id[0].type = WINDOW_TYPE_WITH_HEADER;
    var_84.id[0].pos.x = 2;
    var_84.id[0].pos.y = 2;
    var_84.id[0].width = 0xE;
    var_84.id[0].height = 0x10;
    var_84.id[0].unk10 = 0x10;
    var_84.id[0].unk14 = &gUnknown_202F270;
    var_84.id[1].type = WINDOW_TYPE_NORMAL;
    var_84.id[2].type = WINDOW_TYPE_NORMAL;
    var_84.id[3].type = WINDOW_TYPE_NORMAL;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityIsValid(teamMon)) {
            GetEntInfo(teamMon)->unk157 = TRUE;
        }
    }

    if (!gDungeon->unk644.unk17) {
        var_84.id[0].type = WINDOW_TYPE_NORMAL;
        var_84.id[0].pos.y++;
    }

    while (1) {
        s32 id;
        bool32 r4;

        ret = FALSE;
        DrawFieldTeamMenu(&sp, &var_84, TRUE);
        r10 = FALSE;
        while (1) {
            s32 id = sp.unk4[gUnknown_202EE10.menuIndex];
            if (id >= 0) {
                Entity *teamMon = gDungeon->teamPokemon[id];
                sub_806A2BC(teamMon, 0);
                sub_804A728(&teamMon->pos, 0, 1, 1);
            }

            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x1B);
            if (gRealInputs.repeated & DPAD_DOWN) {
                sub_8083CE0(1);
                sub_80136E0(&gUnknown_202EE10, 1);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                sub_8083CE0(1);
                sub_8013744(&gUnknown_202EE10, 1);
            }
            if (gRealInputs.pressed & START_BUTTON) {
                if (sp.unk14[gUnknown_202EE10.menuIndex] != 0) {
                    sub_8083D44();
                    r10 = TRUE;
                    break;
                }
                sub_8083D30();
            }
            if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button)
            {
                if (sp.unk14[gUnknown_202EE10.menuIndex] != 0) {
                    sub_8083D08();
                    break;
                }
                sub_8083D30();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                ret = TRUE;
                break;
            }
        }

        id = sp.unk4[gUnknown_202EE10.menuIndex];
        if (id >= 0) {
            Entity *teamMon = gDungeon->teamPokemon[id];
            sub_806A2BC(teamMon, 0);
            sub_804A728(&teamMon->pos, 0, 1, 1);
        }

        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x1B);
        sub_804AA60();
        if (ret) {
            break;
        }

        sp.unk0 = gUnknown_202EE10.menuIndex;
        sTeamMenuChosenId = gUnknown_202EE10.menuIndex;
        sub_806145C(&sp);
        if (r10) {
            EntityInfo *info = GetEntInfo(a0);
            SetMonsterActionFields(&info->action, 0x1B);
            info->action.actionParameters[0].actionUseIndex = sp.unk4[sp.unk0];
            ret = FALSE;
            break;
        }

        sub_805FC30(&var_84, 0x12);
        while (1) {
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x1B);
            if (gRealInputs.repeated & DPAD_DOWN) {
                sub_8083CE0(1);
                sub_80136E0(&gUnknown_202EE10, 1);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                sub_8083CE0(1);
                sub_8013744(&gUnknown_202EE10, 1);
            }
            if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                    sub_80615B4(&GetEntInfo(a0)->action, &sp);
                    sub_8083D08();
                    r4 = FALSE;
                    break;
                }
                sub_8083D30();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                r4 = TRUE;
                break;
            }
        }
        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x1B);
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

void DrawFieldTeamMenu(struct UnkFieldTeamMenuStruct *a0, Windows *windows, bool8 a2)
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
            if (pos.x == teamMon->pos.x && pos.y == teamMon->pos.y && sTeamMenuChosenId < 0) {
                sTeamMenuChosenId = count;
            }
            count++;
        }
    }

    if (sTeamMenuChosenId >= count) {
        sTeamMenuChosenId = count - 1;
    }
    if (sTeamMenuChosenId < 0) {
        sTeamMenuChosenId = 0;
    }

    for (i = count; i < MAX_TEAM_MEMBERS; i++) {
        a0->unk4[i] = -1;
        a0->unk14[i] = 0;
    }

    gUnknown_202F270.f0 = 1;
    gUnknown_202F270.f1 = 0;
    gUnknown_202F270.f3 = 0;
    gUnknown_202EE10.menuIndex = sTeamMenuChosenId;
    gUnknown_202EE10.unk1A = count;
    gUnknown_202EE10.unk1C = count;
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk20 = 0;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.firstEntryY = (r10 != FALSE) * 16;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk14.x = 0;
    gUnknown_202EE10.unk0 = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
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

    sub_803ECB4(windows, 1);
    sub_80137B0(&gUnknown_202EE10, 0);
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
                y = GetMenuEntryYCoord(&gUnknown_202EE10, i);
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

    gUnknown_202EE6C = 0;
    teamMon = gDungeon->teamPokemon[a0->unk4[gUnknown_202EE10.menuIndex]];
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
    SetMonsterActionFields(a0, gUnknown_202EE44[gUnknown_202EE10.menuIndex].unk0);
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
        sub_803ECB4(&windows, 1);
        PrintMonTactics(scrollFirstId, tacticIds, monInfo, 0);
        for (i = 0; i < 8; i++) {
            if (tacticIds[i] == TACTIC_UNUSED)
                break;
        }
        gUnknown_202EE10.unk1A = i;
        gUnknown_202EE10.unk1C = 8;
        gUnknown_202EE10.unk1E = 0;
        gUnknown_202EE10.unk20 = 0;
        gUnknown_202EE10.unk4 = 0;
        gUnknown_202EE10.firstEntryY = 16;
        gUnknown_202EE10.unkC = 0;
        gUnknown_202EE10.unkE = 0;
        gUnknown_202EE10.unk14.x = 0;
        gUnknown_202EE10.unk0 = 0;
        sub_801317C(&gUnknown_202EE10.unk28);
        sub_80137B0(&gUnknown_202EE10, 0);
        gUnknown_202EE10.menuIndex = menuIndex;
        while (1) {
            s32 i;

            AddMenuCursorSprite(&gUnknown_202EE10);
            if (tacticIds[8] != TACTIC_UNUSED) {
                sub_80623B0();
            }
            if (scrollFirstId != 0) {
                sub_8062230();
            }
            sub_803E46C(0x3D);
            if (gRealInputs.repeated & DPAD_DOWN) {
                sub_8083CE0(1);
                if (gUnknown_202EE10.menuIndex == 7) {
                    if (tacticIds[8] != TACTIC_UNUSED) {
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc1(0);
                            sub_803E46C(0x3D);
                        }
                        scrollFirstId++;
                    }
                    menuIndex = 7;
                    break;
                }
                sub_80136E0(&gUnknown_202EE10, 0);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                sub_8083CE0(1);
                if (gUnknown_202EE10.menuIndex == 0) {
                    if (scrollFirstId != 0) {
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc2(0);
                            sub_803E46C(0x3D);
                        }
                        scrollFirstId--;
                    }
                    menuIndex = 0;
                    break;
                }
                sub_8013744(&gUnknown_202EE10, 0);
            }
            if (gRealInputs.pressed & START_BUTTON) {
                u32 tacticId = tacticIds[gUnknown_202EE10.menuIndex];
                menuIndex = gUnknown_202EE10.menuIndex;
                sub_8083D44();
                sub_8062748(tacticId);
                loopBreak = FALSE;
                break;
            }
            if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                bool32 changed;

                u32 tacticId = tacticIds[gUnknown_202EE10.menuIndex];
                menuIndex = gUnknown_202EE10.menuIndex;
                sub_8062D68();
                sub_8083D08();
                gUnknown_202EE6C = 0;
                sub_8044F5C(0x2F, 0);
                sub_8044F5C(0xC, 0);
                if (CheckVariousStatuses2(teamMon, TRUE)) {
                    sub_8044FF0(0x2F);
                }
                sub_805FC30(&windows, 0x16);
                while (1) {
                    changed = FALSE;
                    AddMenuCursorSprite(&gUnknown_202EE10);
                    sub_803E46C(0x3D);
                    if (gRealInputs.repeated & DPAD_DOWN) {
                        sub_8083CE0(1);
                        sub_80136E0(&gUnknown_202EE10, 1);
                    }
                    if (gRealInputs.repeated & DPAD_UP) {
                        sub_8083CE0(1);
                        sub_8013744(&gUnknown_202EE10, 1);
                    }
                    if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                        if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                            changed = TRUE;
                            break;
                        }
                        sub_8083D30();
                    }
                    if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                        sub_8083D30();
                        changed = FALSE;
                        break;
                    }
                }
                if (changed) {
                    sub_8083D08();
                    if (gUnknown_202EE10.menuIndex == 0) {
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
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                loopBreak = TRUE;
                break;
            }
        }

        if (addCursor) {
            AddMenuCursorSprite(&gUnknown_202EE10);
        }
        sub_803E46C(0x3D);
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
    gUnknown_202EE10.menuIndex = 0;

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
        sub_803ECB4(&windows, TRUE);
        sub_8069844(&unkMonStruct, entity);
        CreatePokemonInfoTabScreen(spArr[var_3C], var_3C, &unkMonStruct, &unkInfoTabStruct, 0);
        gUnknown_202EE10.unk1E = var_3C;
        gUnknown_202EE10.unk20 = var_38;
        gUnknown_202EE10.unkC = (unkTxtStr1Ptr->unk0 + 15) * 8;
        gUnknown_202EE10.unkE = ((unkTxtStr1Ptr->unk2 + 1) * 8) - 2;
        gUnknown_202EE10.unk14.x = 0;
        gUnknown_202EE10.unk4 = 0;
        gUnknown_202EE10.firstEntryY = 16;
        gUnknown_202EE10.unk0 = 0;
        sub_801317C(&gUnknown_202EE10.unk28);
        gUnknown_202EE10.menuIndex = 0;
        gUnknown_202EE10.unk1A = 0;
        gUnknown_202EE10.unk1C = 0;

        if (spArr[var_3C] == 1) {
            s32 i;

            for (i = 0; i < 8; i++) {
                if (unkInfoTabStruct.unkC[i] == 0) {
                    break;
                }
            }

            if (i != 0) {
                var_2C = 1;
                gUnknown_202EE10.unk1A = i;
                gUnknown_202EE10.unk1C = 8;
                sub_80137B0(&gUnknown_202EE10, 0);
            }
            gUnknown_202EE10.menuIndex = r8;
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
                gUnknown_202EE10.unk1A = i;
                gUnknown_202EE10.unk1C = 8;
                sub_80137B0(&gUnknown_202EE10, 0);
            }
            gUnknown_202EE10.menuIndex = r8;
        }

        while (1) {
            s32 unkVar;
            bool8 r5, r6;

            AddMenuCursorSprite(&gUnknown_202EE10);
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

            sub_803E46C(0x1C);
            if (gUnknown_202F270.f0 > 1 && !sub_80048C8()) {
                if ((gRealInputs.pressed & DPAD_RIGHT) || gUnknown_202EE10.unk28.dpad_right) {
                    sub_8083CE0(0);
                    var_3C++;
                    if (spArr[var_3C] == 0) {
                        var_3C = 0;
                    }
                    break;
                }
                if ((gRealInputs.pressed & DPAD_LEFT) || gUnknown_202EE10.unk28.dpad_left) {
                    sub_8083CE0(0);
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
                    sub_8083CE0(0);
                    if (unkInfoTabStruct.unkC[8] != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc1(0);
                            sub_803E46C(28);
                        }
                        unkMonStruct.unk56++;
                    }
                    r8 = 7;
                    break;
                }
                if (gRealInputs.repeated & DPAD_DOWN) {
                    sub_8083CE0(0);
                    if (gUnknown_202EE10.menuIndex == 7) {
                        if (unkInfoTabStruct.unkC[8] != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc1(0);
                                sub_803E46C(28);
                            }
                            unkMonStruct.unk56++;
                        }
                        r8 = 7;
                        break;
                    }
                    else {
                        sub_80136E0(&gUnknown_202EE10, 0);
                    }
                }

                if (unkVar == 1 && r6) {
                    if (unkMonStruct.unk56 != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc2(0);
                            sub_803E46C(28);
                        }
                        unkMonStruct.unk56--;
                    }
                    r8 = 0;
                    break;
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    sub_8083CE0(1);
                    if (gUnknown_202EE10.menuIndex == 0) {
                        if (unkMonStruct.unk56 != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc2(0);
                                sub_803E46C(28);
                            }
                            unkMonStruct.unk56--;
                        }
                        r8 = 0;
                        break;
                    }
                    else {
                        sub_8013744(&gUnknown_202EE10, 0);
                    }
                }
            }
            else if (var_30) {
                if (unkVar == 2 && r5) {
                    if (unkInfoTabStruct.unk0[8] != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc1(0);
                            sub_803E46C(28);
                        }
                        unkMonStruct.unk40++;
                    }
                    r8 = 7;
                    break;
                }
                if (gRealInputs.repeated & DPAD_DOWN) {
                    sub_8083CE0(1);
                    if (gUnknown_202EE10.menuIndex == 7) {
                        if (unkInfoTabStruct.unk0[8] != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc1(0);
                                sub_803E46C(28);
                            }
                            unkMonStruct.unk40++;
                        }
                        r8 = 7;
                        break;
                    }
                    else {
                        sub_80136E0(&gUnknown_202EE10, 0);
                    }
                }

                if (unkVar == 1 && r6) {
                    if (unkMonStruct.unk40 != 0) {
                        s32 i;
                        for (i = 0; i < 6; i++) {
                            gIwramTextFunc2(0);
                            sub_803E46C(28);
                        }
                        unkMonStruct.unk40--;
                    }
                    r8 = 0;
                    break;
                }
                if (gRealInputs.repeated & DPAD_UP) {
                    sub_8083CE0(1);
                    if (gUnknown_202EE10.menuIndex == 0) {
                        if (unkMonStruct.unk40 != 0) {
                            s32 i;
                            for (i = 0; i < 6; i++) {
                                gIwramTextFunc2(0);
                                sub_803E46C(28);
                            }
                            unkMonStruct.unk40--;
                        }
                        r8 = 0;
                        break;
                    }
                    else {
                        sub_8013744(&gUnknown_202EE10, 0);
                    }
                }
            }

            if (sub_80048C8())
                continue;

            if (gRealInputs.pressed & START_BUTTON) {
                if (var_2C) {
                    s32 var = unkInfoTabStruct.unkC[gUnknown_202EE10.menuIndex];

                    r8 = gUnknown_202EE10.menuIndex;
                    sub_8083D44();
                    sub_806285C(var);
                    var_28 = 0;
                    loopBreak = FALSE;
                    break;
                }
                else if (var_30) {
                    s32 var = unkInfoTabStruct.unk0[gUnknown_202EE10.menuIndex];

                    r8 = gUnknown_202EE10.menuIndex;
                    sub_8083D44();
                    sub_806262C(var);
                    var_28 = 0;
                    loopBreak = FALSE;
                    break;
                }
            }

            if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                if (var_2C) {
                    s32 var = unkInfoTabStruct.unkC[gUnknown_202EE10.menuIndex];

                    r8 = gUnknown_202EE10.menuIndex;
                    sub_8062D68();
                    gUnknown_202EE6C = 0;
                    sub_8083D08();
                    sub_8044F5C(0xC, 0);
                    sub_805FC30(&windows, 0x16);
                    while (1) {
                        AddMenuCursorSprite(&gUnknown_202EE10);
                        sub_803E46C(0x1C);
                        if (gRealInputs.repeated & DPAD_DOWN) {
                            sub_8083CE0(1);
                            sub_80136E0(&gUnknown_202EE10, 1);
                        }
                        if (gRealInputs.repeated & DPAD_UP) {
                            sub_8083CE0(1);
                            sub_8013744(&gUnknown_202EE10, 1);
                        }

                        if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                            sub_8083D08();
                            sub_806285C(var);
                            var_28 = 0;
                            loopBreak = FALSE;
                            break;
                        }
                        if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                            sub_8083D30();
                            loopBreak = FALSE;
                            break;
                        }
                    }
                }
                else if (var_30) {
                    bool8 aPress = FALSE;
                    s32 var = unkInfoTabStruct.unk0[gUnknown_202EE10.menuIndex];

                    r8 = gUnknown_202EE10.menuIndex;
                    sub_8062D68();
                    gUnknown_202EE6C = var_2C;
                    sub_8083D08();
                    sub_8044F5C(0x28, 0);
                    sub_8044F5C(0xC, 0);
                    if (CheckVariousStatuses2(entity, TRUE)) {
                        sub_8044FF0(0x28);
                    }
                    sub_805FC30(&windows, 0x16);
                    while (1) {
                        AddMenuCursorSprite(&gUnknown_202EE10);
                        sub_803E46C(0x1C);
                        if (gRealInputs.repeated & DPAD_DOWN) {
                            sub_8083CE0(1);
                            sub_80136E0(&gUnknown_202EE10, 1);
                        }
                        if (gRealInputs.repeated & DPAD_UP) {
                            sub_8083CE0(1);
                            sub_8013744(&gUnknown_202EE10, 1);
                        }

                        if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
                            if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                                sub_8083D08();
                                aPress = TRUE;
                                break;
                            }
                            sub_8083D30();
                        }
                        if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                            sub_8083D30();
                            loopBreak = FALSE;
                            aPress = FALSE;
                            break;
                        }
                    }

                    if (aPress) {
                        if (gUnknown_202EE10.menuIndex == 0) {
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
                    sub_8083D08();
                    loopBreak = TRUE;
                }
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                loopBreak = TRUE;
                break;
            }
        }

        if (var_28) {
            if (var_30 != 0 || var_2C != 0) {
                AddMenuCursorSprite(&gUnknown_202EE10);
            }
            sub_803E46C(0x1C);
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
            sub_803E46C(0x16);
            if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                sub_8083D08();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                sub_8083D30();
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
        sub_803ECB4(&windows, TRUE);
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
            sub_803E46C(0x16);
            if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                bPress = FALSE;
                sub_8083D08();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                bPress = TRUE;
                sub_8083D30();
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
        sub_803ECB4(&windows, TRUE);
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
            sub_803E46C(62);
            if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
                bPress = FALSE;
                sub_8083D08();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
                bPress = TRUE;
                sub_8083D30();
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
    sub_803ECB4(&windows, TRUE);
    sub_80073B8(0);
    str = sub_808E4FC(a0);
    strcpy(gFormatBuffer_Items[0], str);
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FE964, 0, '\0');
    PrintFormattedStringOnWindow(8, 16, sub_808E51C(a0), 0, '\0');
    sub_80073E0(0);

    while (1) {
        nullsub_34(&menuSub, 0);
        sub_803E46C(22);
        if ((gRealInputs.pressed & A_BUTTON) || menuSub.a_button) {
            sub_8083D08();
            break;
        }
        if ((gRealInputs.pressed & B_BUTTON) || menuSub.b_button) {
            sub_8083D30();
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

    DrawFieldTeamMenu(&unkStruct, &windows, FALSE);
    sub_80073B8(1);
    PrintStringOnWindow(4, 3, gWhichTextPtr2, 1, '\0');
    sub_80073E0(1);
    prevId = -985; // Magic number or does it actually mean anything?

    while (1) {
        currId = unkStruct.unk4[gUnknown_202EE10.menuIndex];

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
            sub_804A728(&entity->pos, 0, 1, 1);
        }

        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x1B);
        if (gRealInputs.repeated & DPAD_DOWN) {
            sub_8083CE0(1);
            sub_80136E0(&gUnknown_202EE10, 1);
        }
        if (gRealInputs.repeated & DPAD_UP) {
            sub_8083CE0(1);
            sub_8013744(&gUnknown_202EE10, 1);
        }

        if ((gRealInputs.pressed & A_BUTTON) || gUnknown_202EE10.unk28.a_button) {
            if (unkStruct.unk14[gUnknown_202EE10.menuIndex] != 0) {
                sub_8083D08();
                break;
            }
            sub_8083D30();
        }
        if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
            sub_8083D30();
            bPress = TRUE;
            break;
        }
    }

    AddMenuCursorSprite(&gUnknown_202EE10);
    sub_803E46C(0x1B);
    sub_804AA60();
    sub_806A2BC(GetLeader(), 0);
    sub_803EAF0(0, 0);
    sub_803E708(4, 0x3E);
    if (bPress) {
        return NULL;
    }
    currId = unkStruct.unk4[gUnknown_202EE10.menuIndex];
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
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk20 = 0;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk14.x = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
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
        sub_804A728(&entityNew->pos, 0, 1, 1);
        sub_8044C10(1);
        if (sub_8062F90(entityNew, 0, 1, countUntilId, count)) {
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
                sub_8083CE0(0);
            }
            sub_8044C10(1);
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
                sub_8083CE0(0);
            }
            sub_8044C10(1);
        }
        else if (GetLeaderActionId() == 29) {
            sub_80637E8(GetLeaderActionContainer());
            sub_8044C10(1);
        }
        else if (GetLeaderActionId() == 30) {
            sub_803EAF0(0, NULL);
            sub_8063A70(GetLeaderActionContainer(), TRUE);
            sub_8044C10(1);
        }
        else if (GetLeaderActionId() == 51) {
            sub_803EAF0(0, NULL);
            sub_8063A70(GetLeaderActionContainer(), FALSE);
            sub_8044C10(1);
        }
        else if (GetLeaderActionId() == 31) {
            sub_803EAF0(0, NULL);
            sub_8063B54(GetLeaderActionContainer());
            sub_8044C10(1);
        }
        else if (GetLeaderActionId() == 33) {
            sub_803EAF0(0, NULL);
            sub_8063CF0(GetLeaderActionContainer(), TRUE);
            sub_8044C10(1);
        }

        if (GetLeaderActionId() != 0)
            break;
    }

    sub_806A2BC(entityOrg, 0);
    sub_804A728(&entityOrg->pos, 0, 1, 1);
}

extern s32 gUnknown_202F2D8;
extern s32 sub_8044FB4(u16 param_1);

void sub_80633E4(Entity *entity, EntityInfo *entInfo, u8 a2, Windows *windows, WindowHeader *header, u8 *arg5, s32 arg6, s32 arg7);
void sub_8063698(Entity *entity, u8 a1, u8 a2);
void sub_80637BC(ActionContainer *a0, s32 a1, s32 a2);
void sub_80637A4(ActionContainer *a0, s32 a1);

bool8 sub_8062F90(Entity * entity, u8 a1, u8 a2, s32 a3, s32 a4)
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
    u8 unk[0x60];
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
            AddMenuCursorSprite_(&gUnknown_202EE10, unk);
            sub_803E46C(0x1E);
            if (gRealInputs.repeated & DPAD_DOWN) {
                bool8 rHeld = (gRealInputs.held & R_BUTTON) != 0;
                s32 id = gUnknown_202EE10.menuIndex;

                if (rHeld) {
                    gUnknown_202F2D8 = unk_SetMoveToLastInLinkedSequence4(entInfo->moves.moves, id);
                    if (id != gUnknown_202F2D8) {
                        sub_8083CE0(0);
                    }
                    else {
                        sub_8083D30();
                    }
                    r10 = TRUE;
                    break;
                }
                else {
                    sub_8013780(&gUnknown_202EE10, unk_FindMoveEnabledForAIAfter4(entInfo->moves.moves, id));
                    if (id != gUnknown_202EE10.menuIndex) {
                        sub_8083CE0(0);
                    }
                }
            }
            if (gRealInputs.repeated & DPAD_UP) {
                bool8 rHeld = (gRealInputs.held & R_BUTTON) != 0;
                s32 id = gUnknown_202EE10.menuIndex;

                if (rHeld) {
                    gUnknown_202F2D8 = unk_SetMoveToFirstInLinkedSequence4(entInfo->moves.moves, id);
                    if (id != gUnknown_202F2D8) {
                        sub_8083CE0(0);
                    }
                    else {
                        sub_8083D30();
                    }
                    r10 = TRUE;
                    break;
                }
                else {
                    sub_8013780(&gUnknown_202EE10, sub_8092DB8(entInfo->moves.moves, id));
                    if (id != gUnknown_202EE10.menuIndex) {
                        sub_8083CE0(0);
                    }
                }
            }

            if ((gRealInputs.repeated & DPAD_RIGHT) || gUnknown_202EE10.unk28.dpad_right) {
                SetMonsterActionFields(&leaderInfo->action, 6);
                break;
            }
            if ((gRealInputs.repeated & DPAD_LEFT) || gUnknown_202EE10.unk28.dpad_left) {
                SetMonsterActionFields(&leaderInfo->action, 7);
                break;
            }

            if ((gRealInputs.pressed & sub_8062D88()) || gUnknown_202EE10.unk28.a_button) {
                if (a1) {
                    bool8 rHeld = (gRealInputs.held & R_BUTTON) != 0;
                    if (rHeld) {
                        r5 = 3;
                    }
                }
                sub_8083D08();
                break;
            }

            if (gRealInputs.pressed & START_BUTTON) {
                r5 = 1;
                sub_8083D44();
                break;
            }
            if (gRealInputs.pressed & SELECT_BUTTON) {
                r5 = 2;
                sub_8083D44();
                break;
            }
            // Fixme: r0/r1 regswap...
            {
                u32 pressed = B_BUTTON;
                pressed &= gRealInputs.pressed;
                if ((pressed) || gUnknown_202EE10.unk28.b_button) {
                    sub_8083D30();
                    ret = TRUE;
                    break;
                }
            }
        }

        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x1E);
        if (leaderInfo->action.action == 6 || leaderInfo->action.action == 7) {
            unkBool = FALSE;
            break;
        }

        if (r10)
            continue;
        if (ret)
            break;

        gUnknown_202F2D8 = gUnknown_202EE10.menuIndex;
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
            if (!sub_8044F3C(r6)) {
                r6 = sub_8044FB4(0x21);
                if (sub_8044F3C(r6)) {
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
                if (!sub_8044F3C(r6)) {
                    r6 = sub_8044FB4(0x33);
                    if (sub_8044F3C(r6)) {
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
                if (sub_8044F3C(r6)) {
                    sub_80637BC(&leaderInfo->action, r6, GetTeamMemberEntityIndex(entity));
                    break;
                }
            }
        }

        sub_8009524(2);
        sub_805FC30(&windows, 0x16);
        while (1) {
            AddMenuCursorSprite(&gUnknown_202EE10);
            sub_803E46C(0x1B);
            if (gRealInputs.repeated & DPAD_DOWN) {
                sub_8083CE0(1);
                sub_80136E0(&gUnknown_202EE10, 1);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                sub_8083CE0(1);
                sub_8013744(&gUnknown_202EE10, 1);
            }

            if ((gRealInputs.pressed & sub_8062D88()) || gUnknown_202EE10.unk28.a_button) {
                if (sub_8044F3C(gUnknown_202EE10.menuIndex)) {
                    sub_80637A4(&leaderInfo->action, GetTeamMemberEntityIndex(entity));
                    if (leaderInfo->action.action != 20 && leaderInfo->action.action != 21) {
                        sub_8083D08();
                    }
                    bPress = FALSE;
                    break;
                }
                sub_8083D30();
            }
            if ((gRealInputs.pressed & B_BUTTON) || gUnknown_202EE10.unk28.b_button) {
                sub_8083D30();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gUnknown_202EE10);
        sub_803E46C(0x1B);
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

    gUnknown_202EE10.menuIndex = gUnknown_202F2D8;
    gUnknown_202EE10.unk1A = movesCount;
    gUnknown_202EE10.unk1C = 4;
    gUnknown_202EE10.unk1E = arg6;
    gUnknown_202EE10.unk20 = arg7;
    gUnknown_202EE10.unk4 = 0;
    gUnknown_202EE10.firstEntryY = 16;
    gUnknown_202EE10.unk14.x = 0;
    gUnknown_202EE10.unk0 = 0;
    sub_801317C(&gUnknown_202EE10.unk28);

    windows->id[0].height = windows->id[0].unk10 = sub_80095E4(4, 0xC) + 2;
    header->f2 = 13;
    windows->id[0].pos.x = 2;
    windows->id[1] = windows->id[3];
    windows->id[2] = windowNew;
    sub_803ECB4(windows, TRUE);
    sub_80137B0(&gUnknown_202EE10, 0);
    gUnknown_202EE10.unkC = (gUnknown_2027370[0].unk0 + 16) * 8;
    gUnknown_202EE10.unkE = ((gUnknown_2027370[0].unk2 + 1) * 8) - 2;
    SetMessageArgument_2(gFormatBuffer_Monsters[0], entInfo, 0);
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entInfo->moves.moves[i];

        arg5[i] = 0;
        if (!MoveFlagExists(move)) {
            if (gUnknown_202EE10.menuIndex == i) {
                gUnknown_202EE10.menuIndex = 0;
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
            y = GetMenuEntryYCoord(&gUnknown_202EE10, i);
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


//
