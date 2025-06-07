#include "global.h"
#include "globaldata.h"
#include "dungeon_move_util.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "structs/str_damage.h"
#include "dungeon_move_util.h"
#include "code_800DAC0.h"
#include "code_800E9E4.h"
#include "code_800ED38.h"
#include "dungeon_vram.h"
#include "code_803E724.h"
#include "code_8041AD0.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "dungeon_logic.h"
#include "dungeon_config.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_move.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "move_util.h"
#include "moves.h"
#include "position_util.h"
#include "sprite.h"
#include "status.h"
#include "move_orb_actions_4.h"
#include "weather.h"
#include "targeting_flags.h"
#include "text_util.h"

extern void sub_80429C8(Entity *r0);
extern bool8 sub_8045888(Entity *r0);
extern void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4, bool32 arg8, s32 argC);
extern void CalcDamage(Entity *, Entity *, u8, u32, u32, struct DamageStruct *dmgStruct, s24_8, u16, u32);
extern void sub_806A1E8(Entity *pokemon);
extern bool8 sub_8044B28(void);
extern void sub_804178C(u32);
extern void sub_8071DA4(Entity *);
extern void sub_80428A0(Entity *r0);
extern bool8 sub_8040BB0(Entity *entity, Move *move, bool8);
extern void sub_8040DA0(Entity *entity, Move *move);
extern u16 sub_80412E0(u16 moveId, u8 weather, u8 a2);
extern void sub_800EF10(u16 r0);
extern s32 sub_800E710(s16 a0, u16 a1);
extern void sub_800E3AC(s32 a0, DungeonPos *pos, s32 a2);
extern void sub_8041168(Entity *entity, Entity *entity2, Move *,DungeonPos *);
extern Entity *GetMonsterAtPos(DungeonPos *pos);
extern s32 sub_800ED20(u16 param_1);
extern s16 sub_8094828(u16, u8);
struct UnkStruct_sub_800E308_1
{
    s16 unk0;
    s16 unk2;
    DungeonPos unk4;
    DungeonPos unk8;
    s32 unkC;
    s32 unk10;
};
extern s32 sub_800E308(struct UnkStruct_sub_800E308_1 *, DungeonPos *);

static u8 ToItemID(u32 itemID);

static EWRAM_INIT Entity *gUnknown_203B438 = NULL;

bool32 sub_8055A00(Entity *attacker, s32 firstMoveId, s32 var_34, s32 itemId, s32 arg_0)
{
    s32 i, j;
    s32 moveId;
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    bool32 isLinkedMove;

    moveId = firstMoveId;
    if (firstMoveId >= MAX_MON_MOVES)
        return FALSE;

    attackerInfo->abilityEffectFlags = 0;
    attackerInfo->unk159 = 0;
    if (attackerInfo->cringeClassStatus.status == STATUS_CRINGE) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC714); // is cringing!
        return FALSE;
    }
    else if (attackerInfo->cringeClassStatus.status == STATUS_INFATUATED) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC718); // is infatuated!
        return FALSE;
    }
    else if (attackerInfo->burnClassStatus.status == STATUS_PARALYSIS) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC6A8); // is paralyzed!
        return FALSE;
    }

    gUnknown_202F222 = 0;
    gUnknown_202F208 = 0;
    gUnknown_202F221 = 0;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        attackerInfo->mimicMoveIDs[i] = 0;
    }

    for (i = 0, j = 0; i < MAX_MON_MOVES; i++) {
        j++;
        if (++moveId >= MAX_MON_MOVES)
            break;
        if (!(attackerInfo->moves.moves[moveId].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            break;
    }

    isLinkedMove = (j > 1);
    moveId = firstMoveId;

    while (1) {
        Move *currMove = &attackerInfo->moves.moves[moveId];
        if (!EntityIsValid(attacker) || sub_8044B28())
            break;

        if (currMove->id == MOVE_SNORE || currMove->id == MOVE_SLEEP_TALK) {
            if (!IsSleeping(attacker)) {
                if (CannotAttack(attacker, TRUE))
                    break;
            }
        }
        else {
            if (CannotAttack(attacker, FALSE))
                break;
        }

        if (gUnknown_202F221 != 0)
            break;

        if (MoveFlagExists(currMove)) {
            bool32 moveUsable = TRUE;
            bool32 var_28 = FALSE;
            bool32 statusMoveMatch = MoveMatchesBideClassStatus(attacker, currMove);

            if (currMove->PP != 0) {
                if (!statusMoveMatch) {
                    var_28 = TRUE;
                }
            }
            else {
                if (!statusMoveMatch) {
                    BufferMoveName(gFormatBuffer_Items[0],  currMove, NULL);
                    LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80F93C8); // The move can't be used!
                    moveUsable = FALSE;
                }
            }

            if (moveUsable) {
                bool32 moveWasUsed;
                s32 unkBefore = gUnknown_202F208;

                attackerInfo->unk159 = statusMoveMatch;
                if (currMove->id == MOVE_ASSIST) {
                    Move assistMove = *currMove;

                    assistMove.id = sub_8057144(attacker);
                    BufferMoveName(gFormatBuffer_Items[0], &assistMove, NULL);
                    LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FD2DC); // Assist:
                    moveWasUsed = TryUseChosenMove(attacker, var_34, itemId, arg_0, isLinkedMove, &assistMove);
                }
                else {
                    moveWasUsed = TryUseChosenMove(attacker, var_34, itemId, arg_0, isLinkedMove, currMove);
                }

                if (var_28 && moveWasUsed) {
                    if (currMove->moveFlags2 & MOVE_FLAG2_UNK4) {
                        currMove->moveFlags2 &= ~(MOVE_FLAG2_UNK4);
                    }
                    else {
                        currMove->moveFlags2 |= MOVE_FLAG_TEMPORARY;
                    }
                }

                if (unkBefore == gUnknown_202F208) {
                    if (itemId == 0) {
                        LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC690); // The currMove failed!
                    }
                    else {
                        LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC6A4); // The Orb failed!
                    }
                }
            }
        }

        sub_804178C(1);
        if (!EntityIsValid(attacker) || sub_8044B28())
            break;
        if (++moveId >= MAX_MON_MOVES)
            break;
        if (!MoveFlagLinkChain(&attackerInfo->moves.moves[moveId]))
            break;
    }

    if (EntityIsValid(attacker)) {
        for (i = 0; i < MAX_MON_MOVES; i++) {
            if (attackerInfo->mimicMoveIDs[i] != 0) {
                Move mimicMove, assistMove;
                Move *movePtr;

                movePtr = &mimicMove;
                InitPokemonMoveOrNullObject(&mimicMove, attackerInfo->mimicMoveIDs[i]);
                if (MoveFlagExists(&mimicMove)) {
                    if (mimicMove.id == MOVE_ASSIST) {
                        assistMove = mimicMove;
                        assistMove.id = sub_8057144(attacker);
                        movePtr = &assistMove;
                        BufferMoveName(gFormatBuffer_Items[0], &assistMove, NULL);
                        LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FD2DC); // Assist:
                    }
                    TryUseChosenMove(attacker, 0, itemId, arg_0, isLinkedMove, movePtr);
                }
                sub_804178C(1);
            }
        }
    }

    if (EntityIsValid(attacker)) {
        sub_8071DA4(attacker);
        if (EntityIsValid(attacker) && gUnknown_202F222 != 0) {
            gUnknown_202F222 = 0;
            if (EntityIsValid(attacker)) {
                EntityInfo *attackerInfo = GetEntInfo(attacker);
                s32 statusTurns = CalculateStatusTurns(attacker, gPauseTurnRange, TRUE);
                PausedStatusTarget(attacker, attacker, 1, statusTurns, FALSE);
                SetExpMultplier(attackerInfo);
            }
        }
    }

    return TRUE;
}

void TriggerTargetAbilityEffect(Entity *attacker)
{
    if (EntityIsValid(attacker)) {
        EntityInfo *entInfo = GetEntInfo(attacker);

        if (entInfo->abilityEffectFlags & ABILITY_FLAG_ARENA_TRAP) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEEA4); // Arena Trap prevents movement!
            ImmobilizedStatusTarget(attacker, attacker);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_SHADOW_TAG) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEEC8); // Shadow Tag prevents movement!
            ImmobilizedStatusTarget(attacker, attacker);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_MAGNET_PULL) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEEEC); // Magnet Pull prevents movement!
            ImmobilizedStatusTarget(attacker, attacker);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_STATIC) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEF0C); // Static caused paralysis!
            ParalyzeStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_PRLZ) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEF30); // Effect Spore scattered spores
            ParalyzeStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_POISON_POINT) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEF4C); // Poison Point struck!
            PoisonedStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_PSN) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEF50); // Effect Spore scattered spores!
            PoisonedStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_SLP) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEF54); // Effect Spore scattered spores!
            SleepStatusTarget(attacker, attacker, CalculateStatusTurns(attacker, gSleepTurnRange, TRUE), TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_FLAME_BODY) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEF74); // Flame Body caused a burn!
            BurnedStatusTarget(attacker, attacker, TRUE, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_CUTE_CHARM) {
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEF98); // Cute Charm caused infatuation
            InfatuateStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_STENCH) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FEFD0); // A horrid stench billowed out
            sub_80428A0(attacker);
            entInfo->terrifiedTurns = gStenchTerrifiedTurnsNo;
        }

        entInfo->abilityEffectFlags = 0;
    }
}

bool8 TryUseChosenMove(struct Entity *attacker, u32 r6, s32 itemId, u32 var_30, bool32 isLinkedMove, struct Move *move)
{
    s32 i;
    Entity *targetsArray[MAX_MOVE_TARGETS + 1];
    const u8 *msg;
    Move metronomeMove, naturePwrMove;
    s32 var_2C;
    s32 var_28;
    s32 var_24;
    bool8 moveUsable;

    msg = NULL;
    targetsArray[0] = NULL;

    sub_804178C(1);
    if (move->id == MOVE_METRONOME) {
        gMetronomeCalledArrayId = DungeonRandInt(METRONOME_AVAILABLE_CALLED_MOVES);
        InitPokemonMove(&metronomeMove, gMetronomeCalledMoves[gMetronomeCalledArrayId].moveID);
        metronomeMove.moveFlags = move->moveFlags;
        metronomeMove.moveFlags2 = move->moveFlags2;
        sub_8056468(attacker, move, gUnknown_80FECBC, targetsArray, itemId, TRUE, FALSE);
        sub_804178C(1);
        move = &metronomeMove;
    }
    else if (move->id == MOVE_NATURE_POWER)
    {
        s32 tileset = gDungeon->tileset;

        if (tileset < 0)
            tileset = 0;
        if (tileset > 74)
            tileset = 74;

        InitPokemonMove(&naturePwrMove, gNaturePowerCalledMoves[tileset].moveID);
        naturePwrMove.moveFlags = move->moveFlags;
        naturePwrMove.moveFlags2 = move->moveFlags2;
        sub_8056468(attacker, move, gUnknown_80FECE0, targetsArray, itemId, TRUE, FALSE);
        sub_804178C(1);
        move = &naturePwrMove;
    }

    var_28 = 0;
    if ((GetMoveTargetAndRangeForPokemon(attacker, move, TRUE)
         & (0xF0)) == TARGETING_FLAG_TARGET_LINE)
    {
        var_28 = 10;
    }
    if ((GetMoveTargetAndRangeForPokemon(attacker, move, TRUE)
         & (0xF0)) == TARGETING_FLAG_CUT_CORNERS)
        {
        var_28 = 1;
        if ((move->id != MOVE_SOLARBEAM || GetApparentWeather(attacker) != WEATHER_SUNNY) && DoesMoveCharge(move->id)) {
            if (!MoveMatchesBideClassStatus(attacker, move)) {
                var_28 = 0;
            }
        }
    }

    SetMessageArgument_2(gFormatBuffer_Monsters[0], GetEntInfo(attacker), 0);
    BufferMoveName(gFormatBuffer_Items[0], move, NULL);
    if (MoveMatchesBideClassStatus(attacker, move)) {
        msg = gUnknown_80FC72C; // mon loosed move
        GetEntInfo(attacker)->unkFF = 0;
        moveUsable = sub_805744C(attacker, move, TRUE);
    }
    else {
        if (itemId == 0) {
            msg = GetMoveUseText(move->id);
        }
        else {
            msg = gUnknown_80F9158;
        }
        moveUsable = CanMonsterUseMove(attacker, move, TRUE);
    }

    if (moveUsable && r6) {
        MarkLastUsedMonMove(attacker, move);
    }

    if (GetEntInfo(attacker)->muzzled.muzzled == TRUE && FailsWhileMuzzled(move->id)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        LogMessageByIdWithPopupCheckUser(attacker, msg);
        sub_803E708(0xA, 0x3F);
        LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC710); // is muzzled!
        return FALSE;
    }
    else if (!moveUsable) {
        SetMessageArgument_2(gFormatBuffer_Monsters[0], GetEntInfo(attacker), 0);
        if (itemId == 0) {
            BufferMoveName(gFormatBuffer_Items[0], move, NULL);
            LogMessageByIdWithPopupCheckUser(attacker, msg);
            sub_803E708(0xA, 0x3F);
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC6D0); // But the move couldn't be used!
        }
        else {
            BufferItemName(gFormatBuffer_Items[0], itemId, NULL);
            LogMessageByIdWithPopupCheckUser(attacker, msg);
            sub_803E708(0xA, 0x3F);
            LogMessageByIdWithPopupCheckUser(attacker, gUnknown_80FC6FC); // But Orbs are prevented from being used!
        }
        return FALSE;
    }

    gUnknown_202F214 = 0;
    gUnknown_202F20C = 0;
    gUnknown_202F210 = 0;
    gUnknown_202F218 = 0;
    gUnknown_202F219 = 0;
    gUnknown_202F21A = 0;
    gUnknown_202F21C = 0;
    gUnknown_202F220 = 0;
    if (isLinkedMove && GetEntInfo(attacker)->unk153 <= 3) {
        GetEntInfo(attacker)->unk153++;
    }

    var_2C = sub_8057070(move);
    for (i = 0; i < var_2C; i++) {
        u8 r4;
        EntityInfo *entInfo;

        var_24 = 1;
        if (gUnknown_202F220 != 0 || gUnknown_202F221 != 0)
            break;
        if (!EntityIsValid(attacker) || sub_8044B28())
            return TRUE;

        entInfo = GetEntInfo(attacker);
        if (var_30 != 0 || move->id == MOVE_SNORE || move->id == MOVE_SLEEP_TALK) {
            if (!IsSleeping(attacker) && CannotAttack(attacker, TRUE))
                break;
        }
        else {
            if (CannotAttack(attacker, FALSE))
                break;
        }
        entInfo->unk14A = 0;
        if (move->id == MOVE_THRASH) {
            GetEntInfo(attacker)->action.direction = DungeonRandInt(NUM_DIRECTIONS);
            TargetTileInFront(attacker);
            var_24 = 0;
        }
        gUnknown_203B438 = NULL;
        targetsArray[0] = 0;
        if (var_28 == 0 || var_28 == 1) {
            SetTargetsForMove(targetsArray, attacker, move);
            SortTargets(targetsArray, attacker);
            if (i != 0 && var_24 != 0 && targetsArray[0] == NULL)
                break;
        }
        r4 = sub_8056468(attacker, move, msg, targetsArray, itemId, (i == 0), var_28);
        msg = NULL;
        if (gUnknown_203B438 != 0) {
            sub_806A1E8(gUnknown_203B438);
        }

        if (GetEntInfo(attacker)->cringeClassStatus.status != STATUS_CONFUSED && GetEntInfo(attacker)->cringeClassStatus.status != STATUS_COWERING) {
            EntityInfo *entInfo = GetEntInfo(attacker);
            entInfo->targetPos.x = 0;
            entInfo->targetPos.y = 0;
        }

        gUnknown_202F214++;
        if (var_28 != 0) {
            sub_80566F8(attacker, move, var_28, r4, itemId, isLinkedMove);
        }
        else {
            UseMoveAgainstTargets(targetsArray, attacker, move, itemId, isLinkedMove);
        }

        if (!EntityIsValid(attacker))
            break;

        sub_806CF18(attacker);
        if (GetEntInfo(attacker)->unk14A == 0) {
            GetEntInfo(attacker)->unk14A = 0; // Redundant as it's already 0
            sub_8079764(attacker);
        }
    }


    if (gUnknown_202F21A != 0) {
        EndFrozenClassStatus(attacker, attacker);
        EndLeechSeedClassStatus(attacker, attacker);
    }

    if (gUnknown_202F219 != 0 && EntityIsValid(attacker)) {
        EntityInfo *entInfo = GetEntInfo(attacker);

        ConfuseStatusTarget(attacker, attacker, FALSE);
        SetExpMultplier(entInfo);
    }
    return TRUE;
}

bool8 sub_8056468(Entity *entity, Move *move, const u8 *str, Entity **unkArray, bool32 itemId, bool8 arg_4, bool32 unused)
{
    s32 i;
    bool8 ret = FALSE;
    bool32 r7 = (sub_8045888(entity) != FALSE);

    if (str != NULL) {
        for (i = 0; i < 65; i++) {
            if (unkArray[i] == NULL) {
                break;
            }
            if (sub_8045888(unkArray[i])) {
                r7 = TRUE;
                break;
            }
        }

        if (r7) {
            SetMessageArgument_2(gFormatBuffer_Monsters[0], GetEntInfo(entity), 0);
            if (itemId == 0) {
                BufferMoveName(gFormatBuffer_Items[0], move, NULL);
            }
            else {
                BufferItemName(gFormatBuffer_Items[0], itemId, NULL);
            }
        }

        if (move->id != MOVE_REGULAR_ATTACK) {
            DisplayDungeonLoggableMessageTrue(entity, str);
        }
        else {
            DisplayDungeonLoggableMessageFalse(entity, str);
        }
    }

    if (r7) {
        if (arg_4) {
            ret = sub_8040BB0(entity, move, TRUE);
        }
        else {
            ret = sub_8040BB0(entity, move, FALSE);
        }
        sub_8040DA0(entity, move);
    }
    else {
        sub_806CE68(entity, GetEntInfo(entity)->action.direction);
    }

    return ret;
}

s32 sub_8056564(Entity *entity, DungeonPos *pos, Move *move, s32 r4)
{
    struct UnkStruct_sub_800E308_1 unkSp1;
    DungeonPos unkSp2;
    EntityInfo *entInfo = GetEntInfo(entity);

    if (!gDungeon->unk181e8.blinded && (GetBodySize(entInfo->apparentID) < 4 || r4 != 1)) {
        s32 unk6 = sub_800ECB8(sub_80412E0(move->id, GetApparentWeather(entity), 1))->unk6;
        s32 pixelPosX = X_POS_TO_PIXELPOS(pos->x);
        s32 pixelPosY = Y_POS_TO_PIXELPOS(pos->y);

        unkSp2.x = pixelPosX / 256;
        unkSp2.y = pixelPosY / 256;

        if (unk6 != 0) {
            s32 someRetVal;

            sub_800EF10(sub_80412E0(move->id, GetApparentWeather(entity), 1));
            sub_800EF64();
            DungeonRunFrameActions(0x5E);
            someRetVal = sub_800E710(entInfo->apparentID, sub_80412E0(move->id, GetApparentWeather(entity), 1));
            if (someRetVal != -1) {
                sub_800569C(&unkSp1.unk8, &entity->axObj.axdata, someRetVal);
            }
            else {
                unkSp1.unk8 = (DungeonPos) {0};
            }
            unkSp1.unk0 = sub_80412E0(move->id, GetApparentWeather(entity), 1);
            unkSp1.unk2 = entInfo->apparentID;
            unkSp1.unk4.x = entity->pixelPos.x / 256;
            unkSp1.unk4.y = entity->pixelPos.y / 256;
            unkSp1.unkC = entInfo->action.direction;
            unkSp1.unk10 = 0;

            return sub_800E308(&unkSp1, &unkSp2);
        }
    }

    return -1;
}

static const s32 gUnknown_81069D4[NUM_DIRECTIONS] =
{
    [DIRECTION_SOUTH] = 1,
    [DIRECTION_SOUTHEAST] = 1,
    [DIRECTION_EAST] = 1,
    [DIRECTION_NORTHEAST] = 0,
    [DIRECTION_NORTH] = 0,
    [DIRECTION_NORTHWEST] = 0,
    [DIRECTION_WEST] = 1,
    [DIRECTION_SOUTHWEST] = 1
};

// This function looks important, but what does it do?
void sub_80566F8(Entity *attacker, Move *move, s32 a2, bool8 a3, s32 itemId, s32 isLinkedMove)
{
    DungeonPos var_68;
    DungeonPos var_64;
    Entity *targetsArray[2]; // Only 2 hmm
    s32 var_4C, var_48;
    s32 i, j;
    s32 targetArrId;
    s32 var_3C;
    s32 var_38;
    s32 var_34;
    s32 var_30;
    s32 var_2C;
    s32 var_28, var_24;
    s32 someCount;
    EntityInfo *attackerInfo;
    s32 unkRetVal;
    s32 divResult;
    s32 r9;

    targetArrId = 0;
    someCount = 0;
    attackerInfo = GetEntInfo(attacker);
    unkRetVal = sub_800ED20(move->id);
    var_30 = 2;
    if (unkRetVal != 1) {
        var_30 = 6;
        if (unkRetVal == 2) {
            var_30 = 3;
        }
    }

    var_68.x = attacker->pos.x;
    var_68.y = attacker->pos.y;
    var_4C = gAdjacentTileOffsets[attackerInfo->action.direction].x;
    var_48 = gAdjacentTileOffsets[attackerInfo->action.direction].y;
    for (i = 0; i < a2; i++)
    {
        const Tile *tile;

        if (var_68.x < 0 || var_68.y < 0 || var_68.x > 55 || var_68.y > 31)
            break;

        var_68.x += var_4C;
        var_68.y += var_48;
        someCount++;
        tile = GetTile(var_68.x, var_68.y);
        if (!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
            break;
        if (tile->monster != NULL && GetEntityType(tile->monster) == ENTITY_MONSTER)
            break;
    }

    if (MoveRequiresCharging(attacker, move->id) && !MoveMatchesBideClassStatus(attacker, move)) {
        var_34 = -1;
    }
    else {
        var_34 = sub_8056564(attacker, &var_68, move, a2);
    }

    var_68.x = attacker->pos.x;
    var_68.y = attacker->pos.y;
    var_4C = gAdjacentTileOffsets[attackerInfo->action.direction].x;
    var_48 = gAdjacentTileOffsets[attackerInfo->action.direction].y;
    divResult = someCount * (24 / var_30);
    if (a2 > 1) {
        var_3C = divResult + 8;
        if (var_3C >= 64) {
            var_3C = 64;
        }
    }
    else {
        var_3C = 32;
    }

    r9 = 0;
    var_2C = 0x80000 / divResult;
    var_38 = gUnknown_81069D4[attackerInfo->action.direction];
    gDungeon->unk1BDD4.unk1C05E = 1;

    for (i = 0; i < a2; i++)
    {
        DungeonPos var_68Before;
        const Tile *tile;

        if (var_68.x < 0 || var_68.y < 0 || var_68.x > 55 || var_68.y > 31)
            break;

        var_68Before = var_68;
        var_68.x += var_4C;
        var_68.y += var_48;
        if (sub_803F428(&var_68) && !gDungeon->unk181e8.blinded) {
            PixelPos pos32;
            pos32.x = X_POS_TO_PIXELPOS(var_68Before.x);
            pos32.y = Y_POS_TO_PIXELPOS(var_68Before.y);
            var_28 = var_30 * (var_4C << 8);
            var_24 = var_30 * (var_48 << 8);
            for (j = 0; j < 24 / var_30; j++) {
                if (var_34 >= 0) {
                    s32 r3;
                    s32 r2;

                    if (a3 != 0) {
                        r3 = sin_4096(r9 / 256) * var_3C;
                    }
                    else {
                        r3 = 0;
                    }
                    var_64.x = pos32.x / 256;
                    var_64.y = (pos32.y - r3) / 256;
                    r2 = pos32.y / 256;
                    r2 -= gDungeon->unk181e8.cameraPixelPos.y;
                    r2 /= 2;
                    sub_800E3AC(var_34, &var_64, r2 + var_38);
                }
                DungeonRunFrameActions(0x30);
                pos32.x += var_28;
                pos32.y += var_24;
                r9 += var_2C;
            }
        }
        else {
            r9 += (24 / var_30) * var_2C;
        }

        tile = GetTile(var_68.x, var_68.y);
        if (!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
            break;
        if (tile->monster != NULL && GetEntityType(tile->monster) == ENTITY_MONSTER && !sub_80571F0(tile->monster, move)) {
            if (targetArrId <= 0) {
                bool8 canHitAnyone = FALSE;
                s32 targetFlags;
                EntityInfo *attackerInfo = GetEntInfo(attacker);
                if (attackerInfo->cringeClassStatus.status == STATUS_CONFUSED
                    || attackerInfo->blinkerClassStatus.status == STATUS_BLINKER
                    || attackerInfo->cringeClassStatus.status == STATUS_COWERING)
                {
                    canHitAnyone = TRUE;
                }
                targetFlags = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
                targetArrId = SetNewTarget(targetArrId, targetsArray, targetFlags, attacker, tile->monster, move, canHitAnyone);
            }
            break;
        }
    }

    if (var_34 >= 0) {
        sub_800DC14(var_34);
    }
    sub_804178C(1);
    gDungeon->unk1BDD4.unk1C05E = 0;

    if (targetArrId > 0) {
        targetsArray[targetArrId] = NULL;
        UseMoveAgainstTargets(targetsArray, attacker, move, itemId, isLinkedMove);
    }
    else if (a2 == 1 && sub_803F428(&var_68)) {
        sub_803E708(1, 0x4A);
        sub_8041168(attacker, NULL, move, &var_68);
    }
}

bool8 AccuracyCalc(Entity *attacker, Entity *target, Move *move, s32 accuracyType, bool8 selfAlwaysHits)
{
    s32 statStageAccuracy, statStageEvasion;
    s24_8 statStageMul;
    s32 accuracy = GetMoveAccuracyOrAIChance(move, accuracyType);
    s32 rand = DungeonRandInt(100);
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);

    if (selfAlwaysHits && attacker == target)
        return TRUE;
    if (move->id == MOVE_REGULAR_ATTACK && IQSkillIsEnabled(attacker, IQ_SURE_HIT_ATTACKER))
        return TRUE;
    if (attackerInfo->sureShotClassStatus.status == STATUS_SURE_SHOT)
        return TRUE;
    if (attackerInfo->sureShotClassStatus.status == STATUS_WHIFFER)
        return FALSE;
    if (accuracy > 100)
        return TRUE;

    if (HasHeldItem(target, ITEM_DETECT_BAND)) {
        accuracy -= gDetectBandAccuracyDebuffValue;
    }
    if (IQSkillIsEnabled(target, IQ_QUICK_DODGER)) {
        accuracy -= gIqQuickDodgerAccuracyDebuffValue;
    }

    statStageAccuracy = attackerInfo->hitChanceStages[0];
    if (AbilityIsActive(attacker, ABILITY_COMPOUNDEYES)) {
        statStageAccuracy += 2;
    }
    if (move->id == MOVE_THUNDER) {
        s32 weather = GetApparentWeather(attacker);
        if (weather == WEATHER_RAIN) {
            return TRUE;
        }
        else if (weather == WEATHER_SUNNY) {
            statStageAccuracy -= 2;
        }
    }

    if (statStageAccuracy < 0) statStageAccuracy = 0;
    if (statStageAccuracy > 20) statStageAccuracy = 20;

    statStageMul = gAccEvsStatStageMultipliers[0][statStageAccuracy];
    if (statStageMul.raw < 0) statStageMul.raw = 0;
    if (statStageMul.raw > IntToF248_2(100).raw) statStageMul = IntToF248_2(100);

    accuracy *= statStageMul.raw;
    accuracy /= 256;

    statStageEvasion = targetInfo->hitChanceStages[1];
    if (targetInfo->exposed) {
        statStageEvasion = 10;
    }
    if (GetApparentWeather(target) == WEATHER_SANDSTORM && AbilityIsActive(target, ABILITY_SAND_VEIL)) {
        statStageEvasion += 2;
    }
    if (AbilityIsActive(attacker, ABILITY_HUSTLE)) {
        bool32 specialMove = (IsTypePhysical(GetMoveType(move)) == FALSE);
        if (!specialMove) {
            statStageEvasion += 2;
        }
    }

    if (statStageEvasion < 0) statStageEvasion = 0;
    if (statStageEvasion > 20) statStageEvasion = 20;

    statStageMul = gAccEvsStatStageMultipliers[1][statStageEvasion];
    if (statStageMul.raw < 0) statStageMul.raw = 0;
    if (statStageMul.raw > IntToF248_2(100).raw) statStageMul = IntToF248_2(100);

    accuracy *= statStageMul.raw;
    accuracy /= 256;
    if (rand < accuracy)
        return TRUE;
    else
        return FALSE;
}

void SetTargetsForMove(Entity **targetsArray, Entity *attacker, Move *move)
{
    s32 targetFlags;
    s32 targetFlagsAnd;
    s32 arrId = 0;
    bool8 canHitPartner = (GetEntInfo(attacker)->cringeClassStatus.status == STATUS_CONFUSED
                    || GetEntInfo(attacker)->blinkerClassStatus.status == STATUS_BLINKER
                    || GetEntInfo(attacker)->cringeClassStatus.status == STATUS_COWERING);
    bool8 canHitSelf = (GetEntInfo(attacker)->cringeClassStatus.status == STATUS_CONFUSED || GetEntInfo(attacker)->cringeClassStatus.status == STATUS_COWERING);

    if (IQSkillIsEnabled(attacker, IQ_NONTRAITOR)) {
        canHitSelf = FALSE;
        canHitPartner = FALSE;
    }
    targetFlags = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
    if ((targetFlags & 0xF) == 4) {
        bool32 usable = MoveMatchesBideClassStatus(attacker, move);
        if (move->id == MOVE_SOLARBEAM && GetApparentWeather(attacker) == WEATHER_SUNNY) {
            usable = TRUE;
        }
        if (usable)
            targetFlags = 0;
        else
            targetFlags = 0x73;
    }

    targetFlagsAnd = targetFlags & 0xF0;
    if (targetFlagsAnd == 0) {
        Entity *targetEntity = sub_80696A8(attacker);
        if (targetEntity != NULL) {
            arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
        }
    }
    else if (targetFlagsAnd == 0x10 || targetFlagsAnd == 0x20) {
        s32 i;
        s32 direction, to;
        EntityInfo *entInfo = GetEntInfo(attacker);
        if (targetFlagsAnd == 0x20) {
            direction = entInfo->action.direction;
            to = 8;
        }
        else {
            direction = entInfo->action.direction - 1;
            to = 3;
        }
        for (i = 0; i < to; i++, direction++) {
            Entity *targetEntity;
            DungeonPos unkPositon;

            direction &= DIRECTION_MASK;
            unkPositon.x = attacker->pos.x + gAdjacentTileOffsets[direction].x ;
            unkPositon.y = attacker->pos.y + gAdjacentTileOffsets[direction].y;
            targetEntity = GetMonsterAtPos(&unkPositon);
            if (targetEntity != NULL) {
                arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
            }
        }
    }
    else if (targetFlagsAnd == 0x30) {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *dungeonMon = gDungeon->activePokemon[i];
            if (EntityIsValid(dungeonMon) && sub_8045A70(attacker, dungeonMon)) {
                if (dungeonMon == attacker) {
                    arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, attacker, move, canHitSelf);
                }
                else {
                    arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, dungeonMon, move, canHitPartner);
                }
            }
        }
    }
    else if (targetFlagsAnd == 0x40) {
        bool32 r4 = FALSE;
        Entity *targetEntity = sub_80696FC(attacker);
        if (targetEntity != NULL) {
            s32 arrIdBefore = arrId;
            arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
            r4 = (arrId != arrIdBefore);
        }
        if (!r4) {
            targetEntity = sub_806977C(attacker);
            if (targetEntity != NULL) {
                arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
            }
        }
    }
    else if (targetFlagsAnd == 0x50) {
        // Nothing happens here
    }
    else if (targetFlagsAnd == 0x80) {
        Entity *targetEntity = sub_80696FC(attacker);
        if (targetEntity != NULL) {
            arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
        }
    }
    else if (targetFlagsAnd == 0x60) {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *dungeonMon = gDungeon->activePokemon[i];
            if (EntityIsValid(dungeonMon)) {
                arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, dungeonMon, move, canHitPartner);
            }
        }
    }
    else if (targetFlagsAnd == 0x70) {
        arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, attacker, move, canHitPartner);
    }

    targetsArray[arrId] = NULL;
}

s32 SetNewTarget(s32 targetArrId, Entity **targetsArray, s32 targetFlags_, Entity *attacker, Entity *target, Move *move, bool32 canHitAnyone_)
{
    bool32 canHitTarget;
    EntityInfo *targetInfo;

    // It's happening again, all over the codebase there are problems with s16 arguments, where the lsl/asr asm can't be matched. What is going on with that?
    s32 targetFlags = (s16)targetFlags_;
    bool8 canHitAnyone = canHitAnyone_;
    canHitTarget = FALSE;
    targetInfo = GetEntInfo(target);

    if (move->id == MOVE_BATON_PASS && attacker == target)
        return targetArrId;
    if (targetInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER)
        return targetArrId;
    if (targetInfo->monsterBehavior == BEHAVIOR_DIGLETT || targetInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET)
        return targetArrId;

    if (canHitAnyone) {
        canHitTarget = TRUE;
    }
    else {
        s32 targetFlagsAnd = targetFlags & 0xF;
        if (targetFlagsAnd == 0 || targetFlagsAnd == 4) {
            if (GetTreatmentBetweenMonsters(attacker, target, TRUE, FALSE) == 1) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 1) {
            if (GetTreatmentBetweenMonsters(attacker, target, TRUE, FALSE) == 0) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 2) {
            canHitTarget = TRUE;
        }
        else if (targetFlagsAnd == 5) {
            if (attacker != target) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 6) {
            if (GetTreatmentBetweenMonsters(attacker, target, TRUE, FALSE) == 0 && attacker != target) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 3) {
            canHitTarget = TRUE;
        }
    }

    if (sub_80571F0(target, move)) {
        canHitTarget = FALSE;
    }

    if (canHitTarget && targetArrId < MAX_MOVE_TARGETS) {
        targetsArray[targetArrId] = target;
        if (!GetEntInfo(target)->isNotTeamMember && gUnknown_203B438 == NULL) {
            gUnknown_203B438 = target;
        }
        targetArrId++;
    }

    return targetArrId;
}

struct MultiTurnChargeMove
{
    u16 moveID;
    u8 status;
};

const struct MultiTurnChargeMove gMultiTurnChargeMoves[10] = {
    {MOVE_SOLARBEAM, STATUS_SOLARBEAM},
    {MOVE_SKY_ATTACK, STATUS_SKY_ATTACK},
    {MOVE_RAZOR_WIND, STATUS_RAZOR_WIND},
    {MOVE_FOCUS_PUNCH, STATUS_FOCUS_PUNCH},
    {MOVE_SKULL_BASH, STATUS_SKULL_BASH},
    {MOVE_FLY, STATUS_FLYING},
    {MOVE_BOUNCE, STATUS_BOUNCING},
    {MOVE_DIVE, STATUS_DIVING},
    {MOVE_DIG, STATUS_DIGGING},
    {MOVE_NOTHING, STATUS_NONE}
};

const u32 gMultiTurnBideClassStatuses[10] = {
    STATUS_SOLARBEAM,
    STATUS_SKY_ATTACK,
    STATUS_RAZOR_WIND,
    STATUS_FOCUS_PUNCH,
    STATUS_SKULL_BASH,
    STATUS_FLYING,
    STATUS_BOUNCING,
    STATUS_DIVING,
    STATUS_DIGGING,
    STATUS_NONE
};

s32 sub_8057070(Move *move)
{
    s32 numberOfChainedHits = GetMoveNumberOfChainedHits(move);
    if (numberOfChainedHits == 0)
        return DungeonRandRange(2, 6);
    else
        return numberOfChainedHits;
}

bool8 MoveCausesPaused(Move *move)
{
    if(move->id == MOVE_FRENZY_PLANT) return TRUE;
    if(move->id == MOVE_HYDRO_CANNON) return TRUE;
    if(move->id == MOVE_HYPER_BEAM) return TRUE;
    if(move->id == MOVE_BLAST_BURN) return TRUE;

    return FALSE;
}

bool8 MoveMatchesBideClassStatus(Entity *pokemon, Move *move)
{
    if (!EntityIsValid(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = GetEntInfo(pokemon);
        s32 i;
        for (i = 0; i < 100; i++)
        {
            if (gMultiTurnChargeMoves[i].moveID == MOVE_NOTHING)
            {
                return FALSE;
            }
            if (move->id == gMultiTurnChargeMoves[i].moveID &&
                pokemonInfo->bideClassStatus.status == gMultiTurnChargeMoves[i].status)
            {
                return TRUE;
            }
        }
        return FALSE;
    }
}

bool8 IsChargingAnyTwoTurnMove(Entity *pokemon, bool8 checkCharge)
{
    if (!EntityIsValid(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = GetEntInfo(pokemon);
        int i = 0;
        u8 *bideClassStatusPointer = &pokemonInfo->bideClassStatus.status;
        u8 *bideClassStatusPointer2;
        u8 chargeStatus = STATUS_CHARGING;
        for (; i < 100; i++)
        {
            u8 currentStatus = gMultiTurnBideClassStatuses[i];
            u8 bideClassStatus;
            if (currentStatus == STATUS_NONE)
            {
                return FALSE;
            }
            bideClassStatus = *bideClassStatusPointer;
            bideClassStatusPointer2 = &pokemonInfo->bideClassStatus.status;
            if (bideClassStatus == currentStatus)
            {
                return TRUE;
            }
        }
        // BUG: This condition is never reached because the for loop terminates by returning FALSE at the end of the gMultiTurnBideClassStatuses array.
        if (checkCharge && *bideClassStatusPointer2 == chargeStatus)
        {
            return TRUE;
        }
        return FALSE;
    }
}

u32 sub_8057144(Entity * pokemon)
{
    Move *moveStack[80];
    int i, j, nMoves;

    nMoves = 0;
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        Entity *dungeonMon = gDungeon->activePokemon[i];
        if (EntityIsValid(dungeonMon)) {
            Move *moves = GetEntInfo(dungeonMon)->moves.moves;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (moves[j].moveFlags & MOVE_FLAG_EXISTS
                    && !MoveRequiresCharging(pokemon, moves[j].id)
                    && moves[j].id != MOVE_SKETCH
                    && nMoves < 80) {
                    moveStack[nMoves++] = &moves[j];
                }
            }
        }
    }

    if (nMoves == 0) {
        return MOVE_REGULAR_ATTACK;
    }
    else {
        return moveStack[DungeonRandInt(nMoves)]->id;
    }
}

bool8 sub_80571F0(Entity * pokemon, Move *move)
{
    u16 moveID;
    s32 tileset;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(pokemon);

    if (entityInfo->unkFF == 1) {
        moveID = move->id;
        if ((moveID == MOVE_SKY_UPPERCUT) || (moveID == MOVE_TWISTER) || (moveID == MOVE_GUST) || (moveID == MOVE_THUNDER))
            return FALSE;
        else
            return TRUE;
    }
    else if (entityInfo->unkFF == 2) {
        if (entityInfo->bideClassStatus.status == STATUS_DIVING) {
            if (move->id == MOVE_WHIRLPOOL || move->id == MOVE_SURF) return FALSE;
        }
        else if (entityInfo->bideClassStatus.status == STATUS_DIGGING) {
            moveID = move->id;
            if (moveID == MOVE_EARTHQUAKE || moveID == MOVE_MAGNITUDE) return FALSE;
            if (moveID == MOVE_NATURE_POWER) {
                tileset = gDungeon->tileset;
                if (tileset < 0) {
                    tileset = 0;
                }
                if (0x4a < tileset) {
                    tileset = 0x4a;
                }
                if (gNaturePowerCalledMoves[tileset].moveID == MOVE_EARTHQUAKE) return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_805727C(Entity * pokemon, Entity * target, s32 chance)
{
    bool8 uVar2;
    if (sub_8044B28())
        return FALSE;
    if (!EntityIsValid(pokemon) || !EntityIsValid(target))
        return FALSE;
    if (GetEntInfo(target)->unk158 == 0 || GetEntInfo(target)->HP == 0)
        return FALSE;

    if (chance != 0) {
        if (AbilityIsActive(pokemon, ABILITY_SERENE_GRACE)) {
            uVar2 = DungeonRandOutcome_2(chance * 2);
        }
        else
        {
            uVar2 = DungeonRandOutcome_2(chance);
        }
    }
    else
    {
        uVar2 = TRUE;
    }

    if (uVar2 && (pokemon != target) && AbilityIsActive(target, ABILITY_SHIELD_DUST))
    {
        sub_80429C8(target);
        return FALSE;
    }

    return uVar2;
}

bool8 RollSecondaryEffect(Entity *pokemon, s32 chance)
{
    if(!EntityIsValid(pokemon))
        return FALSE;
    if(chance == 0)
        return TRUE;
    if(AbilityIsActive(pokemon, ABILITY_SERENE_GRACE))
        return DungeonRandOutcome_2(chance * 2);
    else
        return DungeonRandOutcome_2(chance);
}

bool8 CanAIUseMove(Entity *pokemon, s32 moveIndex, bool8 hasPPChecker)
{
    s32 i;
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    Move *move = &pokemonInfo->moves.moves[moveIndex];
    if (!MoveFlagExists(move))
        return FALSE;
    if (MoveFlagLinkChain(move) || MoveFlagDisabled(move) || MoveFlagSealed(move))
        return FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        if (CanMonsterUseMove(pokemon, move, hasPPChecker))
            return TRUE;
        move++;
        if (move >= &pokemonInfo->moves.moves[MAX_MON_MOVES])
            break;
        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            break;
    }

    return FALSE;
}

bool8 CanMonsterUseMove(Entity *pokemon, Move *move, bool8 hasPPChecker)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    if (move->id == MOVE_REGULAR_ATTACK)
    {
        return TRUE;
    }
    if (move->moveFlags & MOVE_FLAG_DISABLED || move->moveFlags2 & MOVE_FLAG_SEALED)
    {
        return FALSE;
    }
    if (hasPPChecker)
    {
        if (move->PP == 0)
        {
            return FALSE;
        }
        if (pokemonInfo->cringeClassStatus.status == STATUS_TAUNTED && !MoveIgnoresTaunted(move))
        {
            return FALSE;
        }
        if (pokemonInfo->cringeClassStatus.status == STATUS_ENCORE)
        {
            if (move->id == MOVE_STRUGGLE)
            {
                if (!(pokemonInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED))
                {
                    return FALSE;
                }
            }
            else if (!(move->moveFlags & MOVE_FLAG_LAST_USED))
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

bool8 sub_805744C(Entity * pokemon, Move *move, bool8 param_3)
{
  EntityInfo *entityInfo;

  entityInfo = GetEntInfo(pokemon);
  if (move->id != MOVE_REGULAR_ATTACK) {
    if (((move->moveFlags & MOVE_FLAG_DISABLED)) || ((move->moveFlags2 & MOVE_FLAG_EXISTS))) {
        return FALSE;
    }
    if (param_3 != 0) {
      if ((entityInfo->cringeClassStatus.status == STATUS_TAUNTED) && (!MoveIgnoresTaunted(move))) return FALSE;
      if (entityInfo->cringeClassStatus.status == STATUS_ENCORE) {
        if (move->id == MOVE_STRUGGLE) {
          if((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
        else {
          if((move->moveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
      }
    }
  }
  return TRUE;
}

// Attacker always goes last
void SortTargets(Entity **targetsArray, Entity *attacker)
{
    Entity *localArray[MAX_MOVE_TARGETS + 1];
    s32 i;
    s32 count = 0;

    for (i = 0; i < MAX_MOVE_TARGETS + 1; i++) {
        if (targetsArray[i] == NULL)
            break;
        if (targetsArray[i] == attacker)
            continue;
        if (count >= MAX_MOVE_TARGETS)
            break;
        localArray[count++] = targetsArray[i];
    }

    for (i = 0; i < MAX_MOVE_TARGETS + 1; i++) {
        if (targetsArray[i] == NULL)
            break;
        if (targetsArray[i] != attacker)
            continue;
        if (count >= MAX_MOVE_TARGETS)
            break;
        localArray[count++] = targetsArray[i];
    }

    for (; count < MAX_MOVE_TARGETS + 1; count++) {
        localArray[count] = NULL;
    }

    for (i = 0; i < MAX_MOVE_TARGETS + 1; i++) {
        targetsArray[i] = localArray[i];
    }
}

bool8 MoveRequiresCharging(Entity* pokemon, u16 moveID)
{
    if ((moveID == MOVE_SOLARBEAM) && (GetApparentWeather(pokemon) == WEATHER_SUNNY)) {
        return FALSE;
    }
    else {
        return DoesMoveCharge(moveID);
    }
}

void sub_8057588(Entity * pokemon, u8 param_2)
{
    Move *move;
    s32 index;
    s32 PPtoRemove;
    s32 PPCounter;
    EntityInfo *entityInfo;

    if (EntityIsValid(pokemon)) {
        entityInfo = GetEntInfo(pokemon);
        for(index = 0; index < MAX_MON_MOVES; index++)
        {
            move = &entityInfo->moves.moves[index];
            if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
                PPtoRemove = 1;
                if ((move->moveFlags2 & MOVE_FLAG_LAST_USED)) {
                    move->moveFlags2 &= ~(MOVE_FLAG_LAST_USED);
                    PPtoRemove = 2;
                }
                if (((move->moveFlags2 & MOVE_FLAG_SET)) && (move->moveFlags2 &= ~(MOVE_FLAG_SET), param_2 != 0))
                {
                    if(PPtoRemove != 0)
                    {
                        PPCounter = PPtoRemove;
                        for (; PPCounter != 0; PPCounter--) {
                            if (move->PP != 0) {
                                move->PP--;
                            }
                        }
                    }
                }
            }
        }
    }
}

s16 sub_8057600(Move *move, s32 itemID)
{
    return sub_8094828(move->id, ToItemID(itemID));
}

static u8 ToItemID(u32 itemID)
{
    if(itemID == ITEM_NOTHING)
        return ITEM_NOTHING;
    else
        return itemID;
}
