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
#include "dungeon_logic.h"
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
#include "structs/str_806B7F8.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"

extern void ShowWholeRevealedDungeonMap();
extern void EntityUpdateStatusSprites(Entity *);
extern void sub_8042A74(Entity *r0);
extern void sub_807EC28(bool8);
extern s32 GetMonsterApparentID(Entity *param_1, s16 param_2);
extern void sub_806A898(Entity *, u32, u32);
extern void HealTargetHP(Entity *pokemon, Entity *r1, s16, s16, u32);
extern void DealDamageToEntity(Entity *, s16, u32, u32);
extern void ResetMonEntityData(EntityInfo *, u32);
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
extern void sub_803F580(u32);
extern void sub_8041E1C(Entity *);
extern void nullsub_89(Entity *);
extern void nullsub_88(Entity *);
extern void nullsub_87(Entity *);
extern void nullsub_86(Entity *);
extern void sub_8041E0C(Entity *);
extern bool8 sub_806AA0C(s32, u32);

void CounterStatusTarget(Entity * pokemon, Entity * target, u8 newStatus)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status == newStatus) {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB10C);
    }
    else {
      nullsub_57(target);
      if ((entityInfo->reflectClassStatus.status != STATUS_COUNTER) && (entityInfo->reflectClassStatus.status != STATUS_MINI_COUNTER)) {
        entityInfo->reflectClassStatus.turns =  CalculateStatusTurns(target,gCounterTurnRange, FALSE) + 1;
      }
      entityInfo->reflectClassStatus.status = newStatus;
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB0E0);
      EntityUpdateStatusSprites(target);
    }
  }
}

void SafeguardStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_SAFEGUARD) {
      entityInfo->reflectClassStatus.status = STATUS_SAFEGUARD;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gSafeguardTurnRange, FALSE) + 1;
      nullsub_58(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB048);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB074);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MistStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_MIST) {
      entityInfo->reflectClassStatus.status = STATUS_MIST;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gMistTurnRange, FALSE) + 1;
      nullsub_59(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB09C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB0C4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void WishStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_WISH) {
      entityInfo->reflectClassStatus.status = STATUS_WISH;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gWishTurnRange, FALSE) + 1;
      sub_8041B34(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAE1C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAE3C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MagicCoatStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_MAGIC_COAT) {
      entityInfo->reflectClassStatus.status = STATUS_MAGIC_COAT;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gMagicCoatTurnRange, FALSE) + 1;
      nullsub_60(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAF5C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAF8C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LightScreenStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_LIGHT_SCREEN) {
      entityInfo->reflectClassStatus.status = STATUS_LIGHT_SCREEN;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gLightScreenTurnRange, FALSE) + 1;
      nullsub_61(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB130);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB160);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ReflectStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_REFLECT) {
      entityInfo->reflectClassStatus.status = STATUS_REFLECT;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gReflectTurnRange, FALSE) + 1;
      nullsub_62(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB17C);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB1A8);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ProtectStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    nullsub_63(target);
    entityInfo = GetEntInfo(target);
    if (entityInfo->reflectClassStatus.status != STATUS_PROTECT) {
      entityInfo->reflectClassStatus.status = STATUS_PROTECT;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gProtectTurnRange, FALSE) + 1;
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB9B0);
    }
    else {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FB9D8);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MirrorCoatStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_MIRROR_COAT) {
      entityInfo->reflectClassStatus.status = STATUS_MIRROR_COAT;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gMirrorCoatTurnRange, FALSE) + 1;
      nullsub_64(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBAC0);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBAE4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void EndureStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_ENDURING) {
      entityInfo->reflectClassStatus.status = STATUS_ENDURING;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gEnduringTurnRange, FALSE) + 1;
      nullsub_65(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBBF0);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBC14);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MirrorMoveStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_MIRROR_MOVE) {
      entityInfo->reflectClassStatus.status = STATUS_MIRROR_MOVE;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gMirrorMoveTurnRange, FALSE) + 1;
      nullsub_66(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBC38);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBC5C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void Conversion2StatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);

    if(AbilityIsActive(target, ABILITY_FORECAST))
        TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrForecastPreventsConversion2Message);
    else
    {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if (entityInfo->reflectClassStatus.status != STATUS_CONVERSION2) {
            entityInfo->reflectClassStatus.status = STATUS_CONVERSION2;
            entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gConversion2TurnRange, FALSE) + 1;
            nullsub_67(target);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBC7C);
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBCA4);
        }
        EntityUpdateStatusSprites(target);
    }
  }
}

void VitalThrowStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (entityInfo->reflectClassStatus.status != STATUS_VITAL_THROW) {
      entityInfo->reflectClassStatus.status = STATUS_VITAL_THROW;
      entityInfo->reflectClassStatus.turns = CalculateStatusTurns(target, gVitalThrowTurnRange, FALSE) + 1;
      nullsub_68(target);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBCC8);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBCF0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void sub_8079E34(Entity * pokemon, Entity * target, bool8 param_3)
{
  bool8 statChanged;
  EntityInfo *entityInfo;
  s32 index;

  statChanged = FALSE;
  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);

    for(index = 0; index < 2; index++)
    {
      if (entityInfo->offensiveStages[index] != DEFAULT_STAT_STAGE) {
        entityInfo->offensiveStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (entityInfo->defensiveStages[index] != DEFAULT_STAT_STAGE) {
        entityInfo->defensiveStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (entityInfo->hitChanceStages[index] != DEFAULT_STAT_STAGE) {
        entityInfo->hitChanceStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (!F248EqualsInt(entityInfo->offensiveMultipliers[index], 1)) {
        entityInfo->offensiveMultipliers[index] = F248_ONE;
        statChanged = TRUE;
      }
      if (!F248EqualsInt(entityInfo->defensiveMultipliers[index], 1)) {
        entityInfo->defensiveMultipliers[index] = F248_ONE;
        statChanged = TRUE;
      }
    }
    if (statChanged) {
      sub_80420C8(target);
    }
    else if (param_3 != 0) {
      sub_80420C8(target);
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (statChanged) {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBD18);
    }
    else {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBD3C);
    }
    EntityUpdateStatusSprites(target);
  }
}

