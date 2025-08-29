#include "global.h"
#include "globaldata.h"
#include "dungeon_vram.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_effects_target.h"
#include "moves.h"
#include "math.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_config.h"
#include "dungeon_logic.h"
#include "dungeon_strings.h"
#include "dungeon_pos_data.h"
#include "dungeon_damage.h"
#include "dungeon_mon_spawn.h"
#include "dungeon_kecleon_shop.h"

extern void UpdateMinimap();
extern void EntityUpdateStatusSprites(Entity *);
extern void sub_8042A74(Entity *r0);
extern s32 GetMonsterApparentID(Entity *param_1, s16 param_2);
extern void sub_806A898(Entity *, u32, u32);
extern void HealTargetHP(Entity *pokemon, Entity *r1, s16, s16, u32);
extern void sub_80420C8(Entity *r0);
extern void nullsub_68(Entity *);
extern void nullsub_67(Entity *);
extern void nullsub_66(Entity *);
extern void nullsub_65(Entity *);
extern void nullsub_64(Entity *);
extern void nullsub_63(Entity *);
extern void nullsub_62(Entity *);
extern void nullsub_61(Entity *);
extern void nullsub_60(Entity *);
extern void nullsub_59(Entity *);
extern void nullsub_58(Entity *);
extern void nullsub_57(Entity *);
extern void sub_8041B34(Entity *);
void sub_8041BD0(Entity *r0, u8 r1);
void sub_8041EB4(Entity *);
void sub_8041EA4(Entity *);
extern void sub_8041E84(Entity *);
extern void sub_8041E94(Entity *);
extern void sub_8041E74(Entity *);
extern void sub_8041E60(Entity *);
extern void sub_8041E4C(Entity *);
extern void sub_8041E3C(Entity *);
extern void sub_8041E1C(Entity *);
extern void nullsub_89(Entity *);
extern void nullsub_88(Entity *);
extern void nullsub_87(Entity *);
extern void nullsub_86(Entity *);
extern void sub_8041E0C(Entity *);

void sub_8079F20(Entity * pokemon, Entity * target, u8 param_3, u8 param_4)
{
  bool8 moveUnsealed; // r9
  s32 moveSpeed;
  Move *move;
  EntityInfo *entityInfo; // r7
  bool8 bVar8; // r8
  s32 index;

  bVar8 = FALSE;
  moveUnsealed = FALSE;
  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    if (HasNegativeStatus(target)) {
      bVar8 = TRUE;
      EndSleepClassStatus(pokemon,target,0,0);
      if (!EntityIsValid(target)) {
        return;
      }
      EndBurnClassStatus(pokemon,target);
      EndFrozenClassStatus(pokemon,target);
      EndCringeClassStatus(pokemon,target);
      EndCurseClassStatus(pokemon,target,0);
      EndLeechSeedClassStatus(pokemon,target);
      SendMoveEndMessage(pokemon,target);
      SendEyesightEndMessage(pokemon,target);
      SendMuzzledEndMessage(pokemon,target);
      if (entityInfo->perishSongTurns != 0) {
        entityInfo->perishSongTurns = 0;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_8100594);
      }
      if (entityInfo->exposed) {
        entityInfo->exposed = FALSE;
        TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrExposedWoreOffMessage);
      }
    }

    moveSpeed = CalcSpeedStage(target);
    for(index = 0; index < NUM_SPEED_COUNTERS; index++)
    {
      entityInfo->speedDownCounters[index] = 0;
    }

    if (moveSpeed != CalcSpeedStage(target)) {
      bVar8 = TRUE;
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA124[entityInfo->speedStage]);
    }

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &entityInfo->moves.moves[index];
        if ((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags2 & MOVE_FLAG_EXISTS)) {
            bVar8 = TRUE;
            moveUnsealed = TRUE;
            move->moveFlags2 &= ~(MOVE_FLAG_EXISTS);
        }
    }

    if (bVar8) {
      if (param_3 != 0) {
        sub_80420C8(target);
      }
      if (moveUnsealed) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrSealedMoveReleasedMessage);
      }
    }
    else if (param_4 == 0) {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_81004E8);
    }
    EntityUpdateStatusSprites(target);
  }
}

void sub_807A0CC(Entity * pokemon, Entity * target)
{
  Move *move;
  EntityInfo *entityInfo;
  s32 index;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    ResetMonEntityData(entityInfo,0);
    entityInfo->perishSongTurns = 0;
    entityInfo->exposed = FALSE;

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &entityInfo->moves.moves[index];
        if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
            move->moveFlags2 &= ~(MOVE_FLAG_EXISTS);
        }
    }
    EntityUpdateStatusSprites(target);
  };
}

void EndSleepClassStatus(Entity * pokemon, Entity * target, bool8 param_3, bool8 param_4)
{
  EntityInfo *entityInfo;
  bool8 isAsleep;

  isAsleep = FALSE;
  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->sleepClassStatus.status) {
        case STATUS_NONE:
        case 6:
            break;
        case STATUS_SLEEP:
            isAsleep = TRUE;
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA6E8);
            break;
        case STATUS_SLEEPLESS:
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA708);
            break;
        case STATUS_NIGHTMARE:
            isAsleep = TRUE;
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA70C);
            if (param_4) {
                DealDamageToEntity(target,gNightmareDmgValue,8,0x20f);
            }
            break;
        case STATUS_NAPPING:
            isAsleep = TRUE;
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA710);
            HealTargetHP(pokemon,target,gNappingHpHealValue, 0, FALSE);
            entityInfo->sleepClassStatus.status = 0;
            sub_8079F20(pokemon,target,1,1);
            break;
        case STATUS_YAWNING:
            if (param_3) {
                entityInfo->sleepClassStatus.status = STATUS_NONE;
                SleepStatusTarget(pokemon,target,CalculateStatusTurns(target, gSleepFromYawnTurnRange, TRUE) + 1, TRUE);
                return;
            }
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA734);
            break;
  }
  entityInfo->sleepClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (isAsleep) {
    sub_806CE68(target,8);
  }
}

void EndBurnClassStatus(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->burnClassStatus.status) {
    case STATUS_NONE:
    case 5:
        break;
    case STATUS_POISONED:
    case STATUS_BADLY_POISONED:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA8A8);
        break;
    case STATUS_PARALYSIS:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA868);
        break;
    case STATUS_BURN:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA888);
        break;

  }
  entityInfo->burnClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
}

void EndFrozenClassStatus(Entity * pokemon, Entity *target)
{
  bool8 isFrozen;
  EntityInfo *entityInfo;

  isFrozen = FALSE;
  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->frozenClassStatus.status) {
    case STATUS_NONE:
    case 8:
        break;
    case STATUS_FROZEN:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA8BC);
        isFrozen = TRUE;
        break;
    case STATUS_CONSTRICTION:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA820);
        break;
    case STATUS_SHADOW_HOLD:
    case STATUS_INGRAIN:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA824);
        break;
    case STATUS_WRAP:
    case STATUS_WRAPPED:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA81C);
        sub_8076CB4(entityInfo->unk9C);
        break;
    case STATUS_PETRIFIED:
        TryDisplayDungeonLoggableMessage3(pokemon,target, gPtrMonNoLongerPetrifiedMessage);
        break;
  }
  entityInfo->frozenClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (isFrozen) {
    sub_8042A74(target);
  }
}

void EndCringeClassStatus(Entity * pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->cringeClassStatus.status) {
    case STATUS_NONE:
    case 8:
        break;
    case STATUS_CONFUSED:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA800);
        break;
    case STATUS_COWERING:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA97C);
        break;
    case STATUS_TAUNTED:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA9DC);
        break;
    case STATUS_PAUSED:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAC38);
        break;
    case STATUS_INFATUATED:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAB90);
        break;
    case STATUS_ENCORE:
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAAAC);
        break;
    case STATUS_CRINGE:
        TryDisplayDungeonLoggableMessage3(pokemon,target, gPtrMonNoLongerCringingMessage);
        break;
  }
  entityInfo->cringeClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  CalcSpeedStage(target);
}

void EndReflectClassStatus(Entity * pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->reflectClassStatus.status) {
    case STATUS_NONE:
    case 0xF:
        break;
    case STATUS_REFLECT:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA638);
        break;
    case STATUS_SAFEGUARD:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA69C);
        break;
    case STATUS_LIGHT_SCREEN:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA658);
        break;
    case STATUS_COUNTER:
    case STATUS_MINI_COUNTER:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA67C);
        break;
    case STATUS_MAGIC_COAT:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA6BC);
        break;
    case STATUS_WISH:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA6D4);
        break;
    case STATUS_PROTECT:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA9C0);
        break;
    case STATUS_MIRROR_COAT:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FAA68);
        break;
    case STATUS_ENDURING:
        LogMessageByIdWithPopupCheckUser(target, gPtrMonStoppedEnduringMessage);
        break;
    case STATUS_MIRROR_MOVE:
        LogMessageByIdWithPopupCheckUser(target,gPtrMonMirrorMoveFadedMessage);
        break;
    case STATUS_CONVERSION2:
        LogMessageByIdWithPopupCheckUser(target, gPtrMonConversion2FailedMessage);
        break;
    case STATUS_VITAL_THROW:
        LogMessageByIdWithPopupCheckUser(target, gPtrMonGaveUpVitalThrowMessage);
        break;
    case STATUS_MIST:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FAB40);
        break;
  }
  entityInfo->reflectClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
}

void EndCurseClassStatus(Entity * pokemon, Entity * target, u8 curseClassStatus)
{
  u32 uVar3;
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    switch(entityInfo->curseClassStatus.status) {
        case STATUS_NONE:
        case 4:
            break;
        case STATUS_CURSED:
            if (curseClassStatus != STATUS_CURSED) {
                LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA7BC);
            }
            break;
        case STATUS_SNATCH:
            if (curseClassStatus != STATUS_SNATCH) {
                LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA7DC);
            }
            gDungeon->snatchPokemon = NULL;
            gDungeon->unk17B3C = 0;
            break;
        case STATUS_DECOY:
            entityInfo->curseClassStatus.status = STATUS_NONE;
            uVar3 = sub_806CEBC(target);
            sub_806CCB4(target,uVar3);
            gDungeon->decoyIsActive = FALSE;
            if (curseClassStatus != STATUS_DECOY) {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
                LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA9A0);
            }
            break;
    }
    entityInfo->curseClassStatus.status = STATUS_NONE;
    EntityUpdateStatusSprites(target);
  }
}

void EndLeechSeedClassStatus(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    switch(entityInfo->leechSeedClassStatus.status)
    {
        case STATUS_NONE:
            break;
        case STATUS_LEECH_SEED:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA79C);
            break;
        case STATUS_DESTINY_BOND:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FAA8C);
            break;
    }
    entityInfo->leechSeedClassStatus.status = STATUS_NONE;
    entityInfo->leechSeedClassStatus.unk8 = 0xff;
    EntityUpdateStatusSprites(target);
  }
}

void SendMoveEndMessage(Entity * pokemon, Entity * target)
{
  EntityInfo * entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->sureShotClassStatus.status) {
        case STATUS_NONE:
        case 5:
            break;
        case STATUS_SURE_SHOT:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA8E0);
            break;
        case STATUS_WHIFFER:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA90C);
            break;
        case STATUS_SET_DAMAGE:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA934);
            break;
        case STATUS_FOCUS_ENERGY:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA95C);
            break;
  }
  entityInfo->sureShotClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
}

void SendTransformEndMessage(Entity * pokemon, Entity *target)
{
  bool8 isInvisible;
  EntityInfo *entityInfo;
  u32 uVar3;

  isInvisible = FALSE;
  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->invisibleClassStatus.status) {
        case STATUS_NONE:
        case 4:
            break;
        case STATUS_INVISIBLE:
            isInvisible = TRUE;
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FA9F4);
            break;
        case STATUS_MOBILE:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FABBC);
            break;
        case STATUS_TRANSFORMED:
            entityInfo->apparentID = GetMonsterApparentID(target, entityInfo->id);
            target->axObj.spriteFile = GetSpriteData(entityInfo->apparentID);
            uVar3 = sub_806CEBC(target);
            sub_806CCB4(target,uVar3);
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FAB6C);
            break;
  }
  entityInfo->invisibleClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (isInvisible) {
    sub_807EC28(TRUE);
  }
}

void SendEyesightEndMessage(Entity * pokemon,Entity * target)
{
  EntityInfo *entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->blinkerClassStatus.status) {
        case STATUS_NONE:
        case 4:
            break;
        case STATUS_BLINKER:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FAA0C);
            break;
        case STATUS_CROSS_EYED:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FAA2C);
            break;
        case STATUS_EYEDROPS:
            LogMessageByIdWithPopupCheckUser(target,gUnknown_80FAA48);
            break;
  }
  entityInfo->blinkerClassStatus.status = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (entityInfo->isTeamLeader) {
    DungeonRunFrameActions(0x31);
    UpdateTrapsVisibility();
    UpdateMinimap();
  }
}

void SendMuzzledEndMessage(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (!EntityIsValid(target)) {
    return;
  }
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  switch(entityInfo->muzzled.muzzled) {
    case FALSE:
    case 2:
        break;
    case TRUE:
        LogMessageByIdWithPopupCheckUser(target,gUnknown_80FABC0);
        break;
  }
  entityInfo->muzzled.muzzled = FALSE;
  EntityUpdateStatusSprites(target);
}

bool8 TrySendImmobilizeSleepEndMsg(Entity * pokemon, Entity * target)
{
    EntityInfo *entityInfo = GetEntInfo(target);
    bool32 msg = FALSE;

    if (entityInfo->frozenClassStatus.status == STATUS_PETRIFIED) {
        EndFrozenClassStatus(pokemon, target);
        msg = TRUE;
    }
    if (entityInfo->sleepClassStatus.status == STATUS_SLEEP && entityInfo->sleepClassStatus.turns == 0x7f) {
        EndSleepClassStatus(pokemon,target, FALSE, TRUE);
        msg = TRUE;
    }
    return msg;
}

void WakeUpPokemon(Entity * pokemon)
{
  EntityInfo *entityInfo;

  entityInfo = GetEntInfo(pokemon);
  entityInfo->sleepClassStatus.status = STATUS_NONE;
  entityInfo->sleepClassStatus.turns = 0;
  sub_806A898(pokemon, 1, 1);
  EntityUpdateStatusSprites(pokemon);
}

void SendThawedMessage(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    if (entityInfo->frozenClassStatus.status == STATUS_FROZEN) {
      entityInfo->frozenClassStatus.status = STATUS_NONE;
      entityInfo->frozenClassStatus.turns = 0;
      entityInfo->frozenClassStatus.damageCountdown = 0;
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FA8BC); // $m0 thawed out!
      EntityUpdateStatusSprites(target);
    }
  }
}

