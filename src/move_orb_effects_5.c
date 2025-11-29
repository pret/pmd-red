#include "global.h"
#include "globaldata.h"
#include "move_orb_effects_5.h"
#include "dungeon_vram.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "code_805D8C8.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/dungeon_exit.h"
#include "constants/item.h"
#include "constants/residual_damage.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_orb_effects_1.h"
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
#include "dungeon_misc.h"
#include "dungeon_mon_spawn.h"
#include "dungeon_kecleon_shop.h"
#include "dungeon_map.h"
#include "move_orb_effects_2.h"
#include "dungeon_8041AD0.h"

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
    if (MonsterHasNegativeStatus(target)) {
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
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_8100594);
      }
      if (entityInfo->exposed) {
        entityInfo->exposed = FALSE;
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gPtrExposedWoreOffMessage);
      }
    }

    moveSpeed = CalcSpeedStage(target);
    for(index = 0; index < NUM_SPEED_COUNTERS; index++)
    {
      entityInfo->speedDownCounters[index] = 0;
    }

    if (moveSpeed != CalcSpeedStage(target)) {
      bVar8 = TRUE;
      TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA124[entityInfo->speedStage]);
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
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gPtrSealedMoveReleasedMessage);
      }
    }
    else if (param_4 == 0) {
      TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_81004E8);
    }
    UpdateStatusIconFlags(target);
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
    UpdateStatusIconFlags(target);
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
            TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA6E8);
            break;
        case STATUS_SLEEPLESS:
            TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA708);
            break;
        case STATUS_NIGHTMARE:
            isAsleep = TRUE;
            TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA70C);
            if (param_4) {
                DealDamageToEntity_Async(target,gNightmareDmgValue,RESIDUAL_DAMAGE_NIGHTMARE,DUNGEON_EXIT_FAINTED_WHILE_IN_NIGHTMARE);
            }
            break;
        case STATUS_NAPPING:
            isAsleep = TRUE;
            TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA710);
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
            TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA734);
            break;
  }
  entityInfo->sleepClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA8A8);
        break;
    case STATUS_PARALYSIS:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA868);
        break;
    case STATUS_BURN:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA888);
        break;

  }
  entityInfo->burnClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA8BC);
        isFrozen = TRUE;
        break;
    case STATUS_CONSTRICTION:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA820);
        break;
    case STATUS_SHADOW_HOLD:
    case STATUS_INGRAIN:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA824);
        break;
    case STATUS_WRAP:
    case STATUS_WRAPPED:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA81C);
        sub_8076CB4(entityInfo->unk9C);
        break;
    case STATUS_PETRIFIED:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target, gPtrMonNoLongerPetrifiedMessage);
        break;
  }
  entityInfo->frozenClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA800);
        break;
    case STATUS_COWERING:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA97C);
        break;
    case STATUS_TAUNTED:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA9DC);
        break;
    case STATUS_PAUSED:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FAC38);
        break;
    case STATUS_INFATUATED:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FAB90);
        break;
    case STATUS_ENCORE:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FAAAC);
        break;
    case STATUS_CRINGE:
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target, gPtrMonNoLongerCringingMessage);
        break;
  }
  entityInfo->cringeClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA638);
        break;
    case STATUS_SAFEGUARD:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA69C);
        break;
    case STATUS_LIGHT_SCREEN:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA658);
        break;
    case STATUS_COUNTER:
    case STATUS_MINI_COUNTER:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA67C);
        break;
    case STATUS_MAGIC_COAT:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA6BC);
        break;
    case STATUS_WISH:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA6D4);
        break;
    case STATUS_PROTECT:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA9C0);
        break;
    case STATUS_MIRROR_COAT:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FAA68);
        break;
    case STATUS_ENDURING:
        LogMessageByIdWithPopupCheckUser_Async(target, gPtrMonStoppedEnduringMessage);
        break;
    case STATUS_MIRROR_MOVE:
        LogMessageByIdWithPopupCheckUser_Async(target,gPtrMonMirrorMoveFadedMessage);
        break;
    case STATUS_CONVERSION2:
        LogMessageByIdWithPopupCheckUser_Async(target, gPtrMonConversion2FailedMessage);
        break;
    case STATUS_VITAL_THROW:
        LogMessageByIdWithPopupCheckUser_Async(target, gPtrMonGaveUpVitalThrowMessage);
        break;
    case STATUS_MIST:
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FAB40);
        break;
  }
  entityInfo->reflectClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
                LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA7BC);
            }
            break;
        case STATUS_SNATCH:
            if (curseClassStatus != STATUS_SNATCH) {
                LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA7DC);
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
                LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA9A0);
            }
            break;
    }
    entityInfo->curseClassStatus.status = STATUS_NONE;
    UpdateStatusIconFlags(target);
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
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA79C);
            break;
        case STATUS_DESTINY_BOND:
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FAA8C);
            break;
    }
    entityInfo->leechSeedClassStatus.status = STATUS_NONE;
    entityInfo->leechSeedClassStatus.unk8 = 0xff;
    UpdateStatusIconFlags(target);
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
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA8E0);
            break;
        case STATUS_WHIFFER:
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA90C);
            break;
        case STATUS_SET_DAMAGE:
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA934);
            break;
        case STATUS_FOCUS_ENERGY:
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA95C);
            break;
  }
  entityInfo->sureShotClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FA9F4);
            break;
        case STATUS_MOBILE:
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FABBC);
            break;
        case STATUS_TRANSFORMED:
            entityInfo->apparentID = GetMonsterApparentID(target, entityInfo->id);
            target->axObj.spriteFile = GetSpriteData(entityInfo->apparentID);
            uVar3 = sub_806CEBC(target);
            sub_806CCB4(target,uVar3);
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FAB6C);
            break;
  }
  entityInfo->invisibleClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FAA0C);
            break;
        case STATUS_CROSS_EYED:
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FAA2C);
            break;
        case STATUS_EYEDROPS:
            LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FAA48);
            break;
  }
  entityInfo->blinkerClassStatus.status = STATUS_NONE;
  UpdateStatusIconFlags(target);
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
        LogMessageByIdWithPopupCheckUser_Async(target,gUnknown_80FABC0);
        break;
  }
  entityInfo->muzzled.muzzled = FALSE;
  UpdateStatusIconFlags(target);
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
  UpdateStatusIconFlags(pokemon);
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
      TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FA8BC); // $m0 thawed out!
      UpdateStatusIconFlags(target);
    }
  }
}

