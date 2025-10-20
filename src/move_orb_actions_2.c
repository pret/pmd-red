#include "global.h"
#include "globaldata.h"
#include "move_orb_actions_2.h"
#include "move_orb_effects_2.h"
#include "dungeon_move_util.h"
#include "dungeon_vram.h"
#include "dungeon_tilemap.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/dungeon_exit.h"
#include "constants/residual_damage.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_logic.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_move.h"
#include "dungeon_misc.h"
#include "move_orb_effects_1.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "move_orb_actions_1.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_strings.h"
#include "dungeon_damage.h"
#include "warp_target.h"
#include "explosion.h"
#include "move_orb_effects_3.h"
#include "move_orb_effects_4.h"

extern void nullsub_92(Entity *);

bool8 SkyAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    bool8 flag = FALSE;

    if(MoveMatchesBideClassStatus(pokemon, move))
    {
        if (HandleDamagingMove(pokemon, target, move, gSkyAttackModifier, itemId) != 0) {
           flag = TRUE;
            if(sub_805727C(pokemon, target, gSkyAttackSecondaryChance))
                CringeStatusTarget(pokemon, target, FALSE);
        }
        sub_8079764(pokemon);
    }
    else {
       SetChargeStatusTarget(pokemon, pokemon, STATUS_SKY_ATTACK, move, gUnknown_80FACC4);
       flag = TRUE;
    }
    return flag;
}

// NOTE: Is there a better name for this?
bool8 BasicIceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gIceMoveFreezeSecondaryChance))
    {
        FrozenStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 MeteorMashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;
  EntityInfo *entityInfo;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, pokemon, gMeteorMashSecondaryChance))
    {
        entityInfo = GetEntInfo(pokemon);
        RaiseAttackStageTarget(pokemon, pokemon, gStatIndexAtkDef, 1);
        SetExpMultplier(entityInfo);
    }
  }
  return flag;
}

bool8 EndureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    EndureStatusTarget(pokemon, pokemon);
    return TRUE;
}

bool8 ScaryFaceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
    return TRUE;
}

bool8 sub_8058C00(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gMovesConfusionSecondaryChance))
    {
        ConfuseStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 PsywaveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  s32 rand;
  bool8 flag;

  rand = DungeonRandRange(128, 384); // 0x80 - 0x180
  rand = (rand * GetEntInfo(pokemon)->level) / 256;
  if (rand < 0) {
    rand = 1;
  }
  if (199 < rand) {
    rand = 199;
  }
  flag = sub_8055864(pokemon,target,move,rand,itemId) != 0 ? TRUE: FALSE;
  return flag;
}

bool8 sub_8058C98(Entity *pokemon, Entity *target, Move *move, s32 itemId, u32 param_5)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_5) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gPsychicSecondaryChance))
    {
        LowerDefenseStageTarget(pokemon, target,  itemId, 1, 1, FALSE);
    }
  }
  return flag;
}

bool8 PsychoBoostMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    bool8 flag = FALSE;
    if(HandleDamagingMove(pokemon, target, move, IntToF248_2(1), itemId) != 0)
    {
        flag = TRUE;
        if(RollSecondaryEffect(pokemon, 0))
        {
            LowerAttackStageTarget(pokemon, pokemon, gStatIndexSpecial, 2, 0, FALSE);
        }
    }
    return flag;
}

bool8 UproarMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    SleeplessStatusTarget(pokemon, target);
    return TRUE;
}

bool8 WaterSpoutMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId)
{
    s32 index;
    bool8 flag;
    EntityInfo *entityInfo = GetEntInfo(pokemon);
    s32 maxHp = entityInfo->maxHPStat;
    if (entityInfo->HP <= entityInfo->maxHPStat / 4) {
        index = 0;
    }
    else if (entityInfo->HP <= maxHp / 2) {
        index = 1;
    }
    else if (entityInfo->HP <= (maxHp * 3) / 4) {
        index = 2;
    }
    else {
        index = 3;
    }

    flag = HandleDamagingMove(pokemon,target,move,gWaterSpoutModifiers[index],itemId) ? TRUE : FALSE;
    return flag;
}

bool8 PsychUpMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId)
{
  s32 index;
  EntityInfo *iVar3;
  EntityInfo *iVar4;

  iVar4 = GetEntInfo(pokemon);
  iVar3 = GetEntInfo(target);
  nullsub_92(target);

  for(index = 0; index < 2; index++)
  {
    iVar4->offensiveStages[index] = iVar3->offensiveStages[index];
    iVar4->defensiveStages[index] = iVar3->defensiveStages[index];
    iVar4->hitChanceStages[index] = iVar3->hitChanceStages[index];
    iVar4->offensiveMultipliers[index] = iVar3->offensiveMultipliers[index];
    iVar4->defensiveMultipliers[index] = iVar3->defensiveMultipliers[index];
  }
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
  TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FBD58); // It psyched itself up!
  SetExpMultplier(iVar4);
  return TRUE;
}

bool8 sub_8058E5C(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  int iVar2;
  int iVar3;
  bool8 flag;

  flag = FALSE;
  if ((HandleDamagingMove(pokemon, target, move, IntToF248_2(1), itemId) != 0) && (EntityIsValid(pokemon))) {
    iVar2 = GetEntInfo(pokemon)->maxHPStat;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    iVar3 = iVar2 >> 3;
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    flag = TRUE;
    if ((!AbilityIsActive(pokemon, ABILITY_ROCK_HEAD)) && RollSecondaryEffect(pokemon, 0)) {
      sub_806F370(pokemon,pokemon,iVar3,0,0,0,DUNGEON_EXIT_FAINTED_FROM_RECOIL,RESIDUAL_DAMAGE_RECOIL,1,0);
    }
  }
  return flag;
}

bool8 sub_8058EE0(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    HealTargetHP(pokemon, target, GetEntInfo(target)->maxHPStat / 2, 0, TRUE);
    return TRUE;
}

bool32 EarthquakeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool32 flag;
  EntityInfo *entityInfo;
  s32 modifierInt;

  entityInfo = GetEntInfo(target);
  modifierInt = 1;
  gDungeon->unk181e8.unk18200 = 0xc;
  gDungeon->unk181e8.unk18204 = 0;
  if (entityInfo->bideClassStatus.status == STATUS_DIGGING) {
    modifierInt = 2;
  }
  flag = HandleDamagingMove(pokemon,target,move,IntToF248_2(modifierInt),itemId);
  if (flag != 0) {
    flag = TRUE;
  }
  return flag;
}

bool8 NaturePowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;
  s32 tileset;
  Move natureMove;

  tileset = gDungeon->tileset;
  if (tileset < 0) {
    tileset = 0;
  }
  if (0x4a < tileset) {
    tileset = 0x4a;
  }
  InitPokemonMove(&natureMove, gNaturePowerCalledMoves[tileset].moveID);
  flag = gNaturePowerCalledMoves[tileset].callback(pokemon,target,&natureMove,itemId);
  return flag;
}

bool8 LickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gLickSecondaryChance))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 SelfDestructMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    HandleExplosion(pokemon, target, &target->pos, 1, GetMoveType(move), GetDungeonExitReasonFromMoveOrItem(move, itemId));
    return TRUE;
}

bool8 StunSporeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 ChargeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    SetChargeStatusTarget(pokemon, target, STATUS_CHARGING, move, gUnknown_80FAD6C);
    return TRUE;
}

bool8 ThunderboltMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gThunderboltSecondaryChance))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 MistMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    MistStatusTarget(pokemon, target);
    return TRUE;
}

bool8 FissureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  u8 moveType;
  bool8 uVar5;
  bool8 flag;

  flag = FALSE;
  moveType = GetMoveType(move);

  uVar5 = sub_806F4A4(target, moveType) != 0 ? TRUE : FALSE;

  if (AbilityIsActive(target, ABILITY_LEVITATE)) {
    uVar5 = FALSE;
  }
  if (!uVar5) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEB88);
  }
  else {
    sub_806F370(pokemon,target,9999,1,&flag,GetMoveType(move),GetDungeonExitReasonFromMoveOrItem(move,itemId),RESIDUAL_DAMAGE_REGULAR,1,1);
    flag = flag == 0;
  }
  return flag;
}

bool8 ExtrasensoryMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gExtrasensorySecondaryChance))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 SafeguardMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    SafeguardStatusTarget(pokemon, target);
    return TRUE;
}

bool8 AbsorbMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 hasLiquidOoze;
  s32 iVar3;
  s32 iVar4;
  bool8 flag;

  flag = FALSE;
  hasLiquidOoze = AbilityIsActive(target, ABILITY_LIQUID_OOZE);
  iVar3 = HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId);
  if (iVar3 != 0) {
    iVar4 = iVar3 / 2;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    if (EntityIsValid(pokemon)) {
      EntityInfo *entityInfo = GetEntInfo(pokemon);
      flag = TRUE;
      SetExpMultplier(entityInfo);
      if (RollSecondaryEffect(pokemon,0)) {
        if (hasLiquidOoze) {
            DealDamageToEntity(pokemon,iVar4,RESIDUAL_DAMAGE_LIQUID_OOZE,DUNGEON_EXIT_FAINTED_COVERED_IN_SLUDGE);
        }
        else {
            HealTargetHP(pokemon,pokemon,iVar4,0,1);
        }
      }
    }
  }
  return flag;
}

bool8 SkillSwapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool32 flag;

  EntityInfo *pokeEntityData = GetEntInfo(pokemon);
  EntityInfo *targetEntityInfo = GetEntInfo(target);
  if ((AbilityIsActive(target, ABILITY_WONDER_GUARD)) || (AbilityIsActive(pokemon, ABILITY_WONDER_GUARD))) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC8C0);
    flag = FALSE;
  }
  else
  {
    s32 ability1 = targetEntityInfo->abilities[0];
    s32 ability2 = targetEntityInfo->abilities[1];
    targetEntityInfo->abilities[0] = pokeEntityData->abilities[0];
    targetEntityInfo->abilities[1] = pokeEntityData->abilities[1];
    pokeEntityData->abilities[0] = ability1;
    pokeEntityData->abilities[1] = ability2;
    gDungeon->unkC = 1;
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC888);
    // Weirdly enough SetExpMultplier inline doesn't work here...
    if (pokeEntityData->expMultiplier == EXP_HALVED) {
        pokeEntityData->expMultiplier = EXP_REGULAR;
    }
    EndAbilityImmuneStatus(pokemon,pokemon);
    EndAbilityImmuneStatus(pokemon,target);
    flag = TRUE;
  }
  return flag;
}

bool8 SketchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    s32 i;
    bool8 ret = FALSE;
    EntityInfo *pokeInfo = GetEntInfo(pokemon);
    EntityInfo *targetInfo = GetEntInfo(target);
    bool32 moveFound = FALSE;
    u16 moveId = MOVE_NOTHING;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        if (MoveFlagExists(&targetInfo->moves.moves[i]) && targetInfo->moves.moves[i].moveFlags & MOVE_FLAG_LAST_USED) {
            moveId = targetInfo->moves.moves[i].id;
            moveFound = TRUE;
            break;
        }
    }

    if (!moveFound) {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FE3BC);
        return FALSE;
    }

    if (moveId == MOVE_NOTHING) {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FE3BC);
    }
    else {
        InitPokemonMove(move, moveId);
        BufferMoveName(gFormatBuffer_Items[0], move, 0);
        move->moveFlags2 |= MOVE_FLAG2_UNK4;
        move->moveFlags2 |= MOVE_FLAG_REPLACE;
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FE38C);
        ASM_MATCH_TRICK(pokeInfo);
        SetExpMultplier(pokeInfo);
        ret = TRUE;
    }

    return ret;
}

bool8 HeadbuttMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gHeadbuttSecondaryChance))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 DoubleEdgeMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
  s32 HP;
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, IntToF248_2(1), itemId) != 0) {
    flag = TRUE;
    if ((!AbilityIsActive(pokemon, ABILITY_ROCK_HEAD)) && (RollSecondaryEffect(pokemon,0) != 0)) {
      HP = GetEntInfo(pokemon)->maxHPStat;
      if (HP < 0) {
        HP = HP + 7;
      }
      HP = HP >> 3;
      if (HP == 0) {
        HP = 1;
      }
      sub_806F370(pokemon,pokemon,HP,0,0,0,DUNGEON_EXIT_FAINTED_FROM_RECOIL,RESIDUAL_DAMAGE_RECOIL,1,0);
    }
  }
  return flag;
}

bool8 SandstormMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    gDungeon->weather.unkE267[WEATHER_SANDSTORM] = gMoveWeatherDuration;
    if(sub_807EAA0(1, 0) == 0)
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FCF78);
    }
    return TRUE;
}

bool8 sub_8059528(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    LowerAccuracyStageTarget(pokemon, target, gStatIndexAtkDef, TRUE);
    return TRUE;
}

bool8 SmogMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gSmogSecondaryChance))
    {
        PoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 GrowthMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    RaiseAttackStageTarget(pokemon, target, gStatIndexSpecial, 1);
    return TRUE;
}

bool8 SacredFireMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gSacredFireSecondaryChance))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 sub_80595EC(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
  u8 moveType;
  u8 local_20;

  local_20 = 0;
  if (sub_806F4A4(target,GetMoveType(move)) == 0) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEB8C);
    return FALSE;
  }
  else {
    moveType = GetMoveType(move);
    sub_806F370(pokemon,target,9999,1,&local_20,moveType,GetDungeonExitReasonFromMoveOrItem(move,itemId),RESIDUAL_DAMAGE_REGULAR,1,0);
    local_20 = (local_20 == 0);
    return local_20;
  }
}

bool8 SolarBeamMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
  u8 weather; // weather and flag are reused in same variable
  s24_8 modifier;

  weather = GetApparentWeather(pokemon);
  if ((weather == WEATHER_SUNNY) || (MoveMatchesBideClassStatus(pokemon,move))) {
    modifier = gSolarBeamModifier;

    if (((weather == WEATHER_SANDSTORM) || (weather == WEATHER_RAIN)) || weather == WEATHER_HAIL) {
      modifier.raw /= 2;
    }
    weather = HandleDamagingMove(pokemon,target,move,modifier,itemId) != 0 ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_SOLARBEAM,move,gUnknown_80FACE4);
    weather = TRUE;
  }
  return weather;
}

bool8 SonicboomMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
    u8 local_20;

    local_20 = 0;
    sub_806F370(pokemon,target,gSonicboomDmgValue,1,&local_20,GetMoveType(move),GetDungeonExitReasonFromMoveOrItem(move,itemId),RESIDUAL_DAMAGE_REGULAR,1,0);
    local_20 = local_20 == 0;
    return local_20;
}

bool8 FlyMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (MoveMatchesBideClassStatus(pokemon,move)) {
      flag = HandleDamagingMove(pokemon,target,move,gFlyModifier,itemId) != 0 ? TRUE : FALSE;
      sub_8079764(pokemon);
  }
  else {
      SetChargeStatusTarget(pokemon,pokemon,STATUS_FLYING,move,gUnknown_80FACFC);
      flag = TRUE;
  }
  return flag;
}

bool8 ExplosionMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
    HandleExplosion(pokemon,target,&target->pos,2,GetMoveType(move),GetDungeonExitReasonFromMoveOrItem(move,itemId));
    return TRUE;
}

bool8 DiveMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (IsTileGround(GetTileAtEntitySafe(pokemon))) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD128);
  }
  else if (MoveMatchesBideClassStatus(pokemon,move)) {
      flag = HandleDamagingMove(pokemon,target,move,gDiveModifier,itemId) != 0 ? TRUE : FALSE;
      sub_8079764(pokemon);
  }
  else {
      SetChargeStatusTarget(pokemon,pokemon,STATUS_DIVING,move,gUnknown_80FAD2C);
      flag = TRUE;
  }
  return flag;
}

bool8 MuddyWaterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gMuddyWaterAccLowerChance))
    {
        LowerAccuracyStageTarget(pokemon, target, gStatIndexAtkDef, FALSE);
    }
  }
  return flag;
}

bool8 StockpileMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    HandleStockpile(pokemon, target);
    return TRUE;
}

bool8 TwisterMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
  s32 modifierInt = 1;
  bool8 flag = FALSE;
  EntityInfo *entInfo = GetEntInfo(target);

  if (entInfo->bideClassStatus.status == STATUS_FLYING || entInfo->bideClassStatus.status == STATUS_BOUNCING) {
      modifierInt = 2;
  }
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(modifierInt),itemId) != 0)
  {
    flag = TRUE;
    if(sub_805727C(pokemon,target,gTwisterSecondaryChance) != 0) {
        CringeStatusTarget(pokemon,target,FALSE);
    }
  }
  return flag;
}

bool8 TwineedleMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    gUnknown_202F218 = 1;
  }
  if (((gUnknown_202F218 != 0) && (gUnknown_202F214 == 2)) &&
     (sub_805727C(pokemon,target,gTwineedleSecondaryChance) != 0)) {
    PoisonedStatusTarget(pokemon,target,FALSE);
  }
  return flag;
}

bool8 sub_80599EC(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    s32 HP;

    HP = GetEntInfo(target)->maxHPStat;
    if(HP < 0)
        HP += 3;
    HealTargetHP(pokemon, target, HP >> 2, 0, TRUE);
    return TRUE;
}

bool8 MinimizeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    RaiseAccuracyStageTarget(pokemon, target, gStatIndexSpecial);
    return TRUE;
}

bool8 sub_8059A2C(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
    u8 local_20;
    u32 level;

    local_20 = 0;
    level = GetEntInfo(pokemon)->level;
    sub_806F370(pokemon,target,level,1,&local_20,GetMoveType(move),GetDungeonExitReasonFromMoveOrItem(move,itemId),RESIDUAL_DAMAGE_REGULAR,1,0);
    local_20 = local_20 == 0;
    return local_20;
}

bool8 SupersonicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 TauntMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    TauntStatusTarget(pokemon, target);
    return TRUE;
}

bool8 MoonlightMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    HealTargetHP(pokemon, target, gMoonlightHealValueByWeather[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 HornDrillMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
  u8 local_20;

  local_20 = 0;
  if (sub_806F4A4(target,GetMoveType(move)) == 0) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEB90);
    return FALSE;
  }
  else {
    sub_806F370(pokemon,target,9999,1,&local_20,GetMoveType(move),GetDungeonExitReasonFromMoveOrItem(move,itemId),RESIDUAL_DAMAGE_REGULAR,0,0);
    local_20 = local_20 == 0;
    return local_20;
  }
}

bool8 SwordsDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    RaiseAttackStageTarget(pokemon, target, gStatIndexAtkDef, 2);
    return TRUE;
}

bool8 ConversionMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId)
{
  u8 moveType;
  Move *movePtr;
  s32 index;
  EntityInfo * info;
  s32 counter;
  s32 newIndex;
  Move *moveStack [MAX_MON_MOVES];

  counter = 0;
  info = GetEntInfo(target);
  if (AbilityIsActive(target, ABILITY_FORECAST)) {
      TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrForecastPreventsTypeSwitchMessage);
      return FALSE;
  }
  else
  {
    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &info->moves.moves[index];
      if (((movePtr->moveFlags & MOVE_FLAG_EXISTS)) && (GetMoveTypeForMonster(target,movePtr) != TYPE_NONE)) {
        moveStack[counter]  = movePtr;
        counter++;
      }
    }
    if (counter == 0) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE36C);
        return FALSE;
    }
    else
    {
      newIndex = DungeonRandInt(counter);
      moveType = GetMoveTypeForMonster(target,moveStack[newIndex]);
      info->types[0] = moveType;
      info->types[1] = TYPE_NONE;
      info->isColorChanged = TRUE;
      BufferMoveName(gFormatBuffer_Items[0], moveStack[newIndex], NULL);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE330);
      return TRUE;
    }
  }
}

bool8 Conversion2MoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    Conversion2StatusTarget(pokemon, target);
    return TRUE;
}

bool8 HelpingHandMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    bool8 flag;
    flag = FALSE;
    if(pokemon == target)
    {
        TryDisplayDungeonLoggableMessage3(target, target, gUnknown_80FEB60);
    }
    else {
        RaiseAttackStageTarget(pokemon, target, gStatIndexAtkDef, 1);
        RaiseAttackStageTarget(pokemon, target, gStatIndexSpecial, 1);
        flag = TRUE;
    }
    return flag;
}

bool8 sub_8059CD8(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    RaiseDefenseStageTarget(pokemon, target, gStatIndexAtkDef, 2);
    return TRUE;
}

bool8 WarpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    WarpTarget(pokemon, target, 0, NULL);
    return TRUE;
}

bool8 ThundershockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gThundershockSecondaryChance))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 ThunderWaveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 ZapCannonMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 BlockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    ImmobilizedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 PoisonGasMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    PoisonedStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 ToxicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
    BadlyPoisonedStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 PoisonFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),itemId) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gPoisonFangSecondaryChance))
    {
        BadlyPoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

