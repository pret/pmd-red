#include "global.h"
#include "globaldata.h"
#include "dungeon_action_execution.h"
#include "dungeon_ai_leader.h"
#include "dungeon_move_util.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_8066D04.h"
#include "dungeon_message.h"
#include "constants/dungeon_action.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_logic.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_util.h"
#include "moves.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "trap.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_pos_data.h"
#include "dungeon_engine.h"
#include "dungeon_strings.h"
#include "dungeon_action.h"
#include "dungeon_turn_effects.h"
#include "dungeon_leveling.h"
#include "dungeon_cutscene.h"
#include "dungeon_move.h"
#include "dungeon_map_access.h"
#include "warp_target.h"
#include "move_orb_effects_1.h"
#include "move_orb_effects_3.h"

void sub_8075BA4(Entity *param_1, u8 param_2);
void sub_804178C(u8 param_1);
void nullsub_95(Entity *);
extern void sub_80671A0(Entity *);
extern void sub_8067110(Entity *);
void HandleUseMoveAIAction(Entity *target);
void sub_8041888(u8 param_1);
void sub_805EFB4(Entity *, u8);
void sub_8074FB0(Entity *, u8, DungeonPos *);
void HandlePlaceItemAction(Entity *);
void HandlePickUpPlayerAction(Entity *);
void sub_8066E14(Entity * );
void sub_8066BD4(Entity*);
void HandleTalkFieldAction(Entity *);
void HandleUseMovePlayerAction(Entity *);
void HandleUseOrbAction(Entity *);
void sub_8067904(Entity *, u32);
void HandleGiveItemAction(Entity *);
void HandleTakeItemAction(Entity *);
void HandleUseItemAction(Entity *);
void sub_8066FA4(Entity *);
void HandleUnsetItemAction(Entity *,bool8);
extern u8 DisplayActions(Entity *);
void sub_806A1E8(Entity *pokemon);
void HandlePickUpAIAction(Entity *pokemon);
void HandleThrowItemAIAction(Entity *pokemon);
void HandleEatAIAction(Entity *pokemon);
u32 sub_8075818(Entity *entity);;

EWRAM_DATA u8 gUnknown_202F32C = 0;
EWRAM_DATA u8 gUnknown_202F32D = 0;

static void HandleSleepTalk(void);
static void HandleSnore(void);
static void HandleFlashFire(void);

bool8 ExecuteEntityDungeonAction(Entity *entity)
{
    bool8 bVar4;
    bool8 bVar5;
    Move *move;
    s32 index;
    EntityInfo *info;
    bool8 bVar14;
    DungeonPos pos;
    DungeonPos pos1;

    sub_804178C(1);
    gUnknown_203B434 = TRUE;
    info = GetEntInfo(entity);
    info->useHeldItem = FALSE;
    info->unkF3 = FALSE;
    gDungeon->unkB8 = entity;
    if (gUnknown_80F58F4[(info->action).action][0] != 0) {
        if (info->isTeamLeader) {
            sub_805EFB4(entity,gUnknown_80F58F4[(info->action).action][1]);
        }
        else {
            sub_8075BA4(entity,gUnknown_80F58F4[(info->action).action][1]);
        }
    }
    if ((CannotAttack(entity, FALSE)) && (IsChargingAnyTwoTurnMove(entity, TRUE))) {
        sub_8079764(entity);
    }

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &info->moves.moves[index];
        if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
            move->moveFlags2 &= ~(MOVE_FLAG2_UNK4);
        }
    }
    if (!IsNotAttacking(entity, FALSE)) {
        if (DisplayActions(entity)) {
            if (IsFloorOver()) {
                return FALSE;
            }
            if (!EntityIsValid(entity)) {
                return FALSE;
            }
            if (gUnknown_202F32D != 0) {
                return TRUE;
            }
        }
        if (!info->isTeamLeader) {
            sub_8052740(10);
        }
        sub_806A1E8(entity);
        DungeonRunFrameActions(10);
    }
    if (((ACTION_PASS_TURN < info->action.action) && (info->action.action != 4)) && (info->action.action != ACTION_WALK)) {
        info->attacking = TRUE;
    }
    bVar14 = FALSE;
    info->unk14A = 0;
    gUnknown_202F221 = 0;
    gUnknown_202F222 = 0;
    switch(info->action.action) {
        case ACTION_WALK:
            if(info->frozenClassStatus.status == STATUS_SHADOW_HOLD)
            {
                goto _282;
            }
            else if(info->frozenClassStatus.status == STATUS_CONSTRICTION)
            {
                goto _282;
            }
            else if(info->frozenClassStatus.status == STATUS_INGRAIN)
            {
                goto _282;
            }
            else if(info->frozenClassStatus.status == STATUS_WRAP)
            {
                goto _282;
            }
            else if(info->frozenClassStatus.status == STATUS_WRAPPED)
            {
            _282:
                info->action.action = ACTION_NOTHING;
                info->waiting = TRUE;
            }
            else {
                bVar5 = FALSE;
                pos1.x = (entity->pos).x + gAdjacentTileOffsets[(info->action).direction].x;
                pos1.y = (entity->pos).y + gAdjacentTileOffsets[(info->action).direction].y;
                if ((!(info->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)) &&
                    (!CanMoveInDirection(entity,(info->action).direction))) {
                    bVar5 = TRUE;
                }
                if (bVar5) {
                    info->action.action = ACTION_NOTHING;
                    info->waiting = TRUE;
                    break;
                }
                else
                {
                    pos.x = entity->pos.x;
                    pos.y = entity->pos.y;
                    sub_80694C0(entity,pos1.x,pos1.y,0);
                    sub_8074FB0(entity,(info->action).direction,&pos);
                    if (((IQSkillIsEnabled(entity, IQ_SUPER_MOBILE)) && (info->invisibleClassStatus.status != STATUS_MOBILE)) &&
                        (!HasHeldItem(entity,ITEM_MOBILE_SCARF))) {
                        sub_804AE08(&entity->pos);
                    }
                    bVar14 = TRUE;
                    break;
                }
            }
            break;
        case ACTION_USE_MOVE_AI:
            HandleUseMoveAIAction(entity);
            break;
        case ACTION_STAIRS:
            if ((gDungeon->unk644.dungeonLocation.id == DUNGEON_METEOR_CAVE) && (!gDungeon->deoxysDefeat)) {
                LogMessageByIdWithPopupCheckUser(entity,gUnknown_80FA5B4); // It's impossible to go down the stairs now!
            }
            else
            {
                PlayStairsSound();
                gDungeon->unk2 = 1;
                gUnknown_202F32C = (info->action).direction;
            }
            break;
        case ACTION_EAT_BERRY_SEED_DRINK:
        case 0xe:
        case ACTION_USE_TM:
            sub_8067110(entity);
            break;
        case ACTION_USE_ORB:
            HandleUseOrbAction(entity);
            break;
        case ACTION_PICK_UP_PLAYER:
            HandlePickUpPlayerAction(entity);
            break;
        case ACTION_GIVE_ITEM:
            HandleGiveItemAction(entity);
            break;
        case ACTION_TAKE_ITEM:
            HandleTakeItemAction(entity);
            break;
        case 0x3e:
            sub_8066BD4(entity); // ITEM_SWITCH_TOOLBOX (When you switch item in Toolbox)
            break;
        case ACTION_USE_ITEM:
            HandleUseItemAction(entity);
            break;
        case ACTION_SET_ITEM:
            HandleSetItemAction(entity, TRUE);
            break;
        case ACTION_UNSET_ITEM:
            HandleUnsetItemAction(entity, TRUE);
            break;
        case 0x3b:
            gDungeon->unkBC = gDungeon->teamPokemon[(info->action).actionParameters[0].actionUseIndex];
            break;
        case ACTION_PLACE_ITEM:
            HandlePlaceItemAction(entity);
            break;
        case 10: // Switch with Item on Ground
            sub_8066E14(entity);
            break;
        case 0x3a: // Switch with Item on Ground (also??)
            sub_8066FA4(entity);
            break;
        case ACTION_THROW_ITEM_PLAYER:
        case ACTION_THROW_STRAIGHT_PLAYER:
        case ACTION_THROW_ARC_PLAYER:
            if (MonsterCanThrowItems(info)) {
                nullsub_95(entity);
                sub_80671A0(entity);
                break;
            }
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
            LogMessageByIdWithPopupCheckUser(entity,gUnknown_80FE6D4);
            break;
        case ACTION_TALK_FIELD:
            HandleTalkFieldAction(entity);
            break;
        case ACTION_USE_MOVE_PLAYER:
            HandleUseMovePlayerAction(entity);
            break;
        case ACTION_STRUGGLE:
            sub_8067904(entity, MOVE_STRUGGLE);
            break;
        case ACTION_REGULAR_ATTACK:
            sub_8067904(entity, MOVE_REGULAR_ATTACK);
            break;
        case ACTION_STEPPED_ON_TRAP:
            TryTriggerTrap(entity,&entity->pos,0,0);
            break;
        case ACTION_PICK_UP_AI:
            HandlePickUpAIAction(entity);
            break;
        case ACTION_EAT_AI:
            HandleEatAIAction(entity);
            break;
        case ACTION_THROW_ITEM_AI:
            HandleThrowItemAIAction(entity);
            break;
        case ACTION_SECOND_THOUGHTS:
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
            LogMessageByIdWithPopupCheckUser(entity,gUnknown_80FE478);
            break;
        default:
            info->action.action = ACTION_PASS_TURN;
            break;
    }
    sub_807FD84(entity);
    if (EntityIsValid(entity)) {
        if (GetEntInfo(entity)->unk14A == 0) {
            GetEntInfo(entity)->unk14A = 0;
            sub_8079764(entity);
        }
        sub_8041888(0);
        if (EntityIsValid(entity)) {
            sub_8085140();
            if (info->unk14B != 0) {
                bVar4 = FALSE;
                info->unk14B = 0;

                for(index = 0; index < MAX_MON_MOVES; index++)
                {
                    move = &info->moves.moves[index];
                    if ((info->moves.moves[index].moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_LAST_USED)) {
                        move->PP = 0;
                        bVar4 = TRUE;
                    }
                }
                if (bVar4) {
                    LogMessageByIdWithPopupCheckUser(entity,gUnknown_80FD2CC);
                }
            }
            HandleFlashFire();
            if (!sub_8044B84()) {
                HandleSnore();
                HandleSleepTalk();
                if (!EntityIsValid(entity)) {
                    return FALSE;
                }
            }
            if (bVar14) {
                sub_8075818(entity);
            }
            if (EntityIsValid(entity)) {
                if (!sub_8044B84()) {
                    sub_8046D20();
                }
                sub_8041888(0);
                if (((EntityIsValid(entity)) && (!info->aiAllySkip)) && (!bVar14)) {
                    if (sub_80706A4(entity,&entity->pos) != '\0') {
                        WarpTarget(entity,entity,0,0);
                    }
                    ApplyEndOfTurnEffects(entity);
                    EnemyEvolution(entity);
                }
            }
        }
    }
    return FALSE;
}

static void HandleSleepTalk(void)
{
    s32 index;
    Entity *entity;
    EntityInfo *info;
    s32 moveIndex;
    s32 counter;
    s32 otherIndex;
    u8 flag;
    Move *move;
    Move *move2;
    Move moveStack;
    u8 sl;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++){
        flag = FALSE;
        entity = gDungeon->activePokemon[index];
        if(EntityIsValid(entity)){
            info = GetEntInfo(entity);
            if(info->unk164 != 0xFF){
                sl = info->unk164;
                if(CannotAttack(entity, TRUE)){
                    info->unk164 |= 0xFF;
                }
                else if(!IsSleeping(entity)){
                    info->unk164 |= 0xFF;
                }
                else if(info->muzzled.muzzled == TRUE){
                    info->unk164 |= 0xFF;
                }
                else{
                    moveIndex = DungeonRandInt(MAX_MON_MOVES);
                    for(counter = 0; counter < MAX_MON_MOVES; counter++){
                        move = &info->moves.moves[moveIndex];
                        if(MoveFlagExists(move)){
                            moveStack = *move;
                            if(moveStack.id == MOVE_SKETCH)
                                goto _increase;
                            if(moveStack.id == MOVE_MIMIC)
                                goto _increase;
                            for(otherIndex = 0; otherIndex < MAX_MON_MOVES; otherIndex++){
                                move2 = &info->moves.moves[otherIndex];
                                if(MoveFlagExists(move2)){
                                    if(!info->isTeamLeader){
                                        if(!(move2->moveFlags & MOVE_FLAG_ENABLED_FOR_AI)) continue;
                                    }
                                    if(move2->id == MOVE_SLEEP_TALK){
                                        if(CanMonsterUseMove(entity, move2, TRUE))
                                        {
                                             sub_80838EC(&move2->PP);
                                             break;
                                        }
                                    }
                                }
                            }
                            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
                            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80FCF38); // {ARG_POKEMON_0} uttered its sleep talk!
                            info->action.direction = sl & DIRECTION_MASK;
                            TryUseChosenMove(entity, 0, ITEM_NOTHING, 1, FALSE, &moveStack);
                            flag = TRUE;
                            break;

                        }
                        else
                        {
_increase:
                            moveIndex++;
                            if(moveIndex == MAX_MON_MOVES)
                                moveIndex = 0;
                        }
                    }
                    info->unk164 |= 0xFF;
                    if(flag)
                        sub_80421C0(entity, 0x2E0);
                }
            }
        }
    }
}

static void HandleSnore(void)
{
    int index;
    s32 moveIndex;
    Move *move;
    EntityInfo *info;
    Entity *pokemon;
    Move chosenMove;
    u8 r8;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++) {
        pokemon = gDungeon->activePokemon[index];
        if (EntityIsValid(pokemon)) {
            info = GetEntInfo(pokemon);
            if (info->unk165 != 0xff) {
                r8 = info->unk165;
                if (CannotAttack(pokemon,TRUE)) {
                    info->unk165 |= 0xff;
                    info->unk164 |= 0xff;
                }
                else if (!IsSleeping(pokemon)) {
                    info->unk165 |= 0xff;
                    info->unk164 |= 0xff;
                }
                else if (info->muzzled.muzzled == TRUE) {
                    info->unk165 |= 0xff;
                    info->unk164 |= 0xff;
                }
                else {
                    for(moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
                    {
                        move = &info->moves.moves[moveIndex];
                        if (((MoveFlagExists(move)) &&
                            ((info->isTeamLeader || (move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI)) && move->id == MOVE_SNORE)) &&
                            (CanMonsterUseMove(pokemon,move,TRUE))) {
                            chosenMove = *move;
                            sub_80838EC(&move->PP);
                            MarkLastUsedMonMove(pokemon,move);
                            break;
                        }
                    }
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
                    LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FCF50);
                    info->action.direction = r8 & DIRECTION_MASK;
                    TryUseChosenMove(pokemon,0,ITEM_NOTHING,1,FALSE,&chosenMove);
                    info->unk165 |= 0xff;
                    info->unk164 |= 0xff;
                }
            }
        }
    }
}

static void HandleFlashFire(void)
{
    s32 index;

    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
        Entity *entity = gDungeon->activePokemon[index];
        if (EntityIsValid(entity)) {
            if (GetEntInfo(entity)->unk152 != 0) {
               GetEntInfo(entity)->unk152 = 0;
               UpdateFlashFireBoost(entity, entity);
            }
        }
    }
}

