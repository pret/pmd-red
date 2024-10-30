#include "global.h"
#include "charge_move.h"
#include "code_803E46C.h"
#include "code_8045A00.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "code_808417C.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_effects_target.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "status_actions.h"
#include "status_checks_1.h"
#include "status.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"
#include "weather.h"
#include "called_move_data.h"

extern const u8 *const gUnknown_80FD350;
extern const u8 *const gUnknown_80FD370;
extern u8 *gUnknown_80FE3BC[];
extern u8 *gUnknown_80FE38C[];
extern u8 *gUnknown_80FC888[];
extern u8 *gUnknown_80FC8C0[];
extern s16 gUnknown_80F4DEA;
extern u8 *gUnknown_80FEB88[];
extern s16 gUnknown_80F4DE8;
extern u8 *gUnknown_80FAD6C[];
extern s16 gUnknown_80F4DE4;
extern u8 *gUnknown_80FBD58[];
extern u32 gUnknown_80F51B4[];
extern s16 gUnknown_80F4DC0;
extern s16 gUnknown_80F4DF8;
extern s16 gUnknown_80F4DD0;
extern s16 gUnknown_80F4DBC;
extern u8 *gUnknown_80FACC4[];
extern s16 gUnknown_80F4DF4;
extern u32 gUnknown_80F4F4C;
extern s16 gUnknown_80F4EB8[];
extern u8 gUnknown_202F21A;
extern s16 gUnknown_80F500A[];
extern s16 gUnknown_80F4DD6;
extern u8 gUnknown_202F219;
extern u32 gUnknown_80F51A4[];
extern u8 *gUnknown_80FACA4[];
extern u32 gUnknown_80F4F54;
extern u8 *gUnknown_80FD104[];
extern s16 gUnknown_80F4DD4;
extern u32 gUnknown_80F4F6C;
extern u32 gUnknown_80F4DE6;
extern u32 gUnknown_80F4DEE;
extern u32 gUnknown_80F4DC2;
extern u8 *gUnknown_80FD294[];
extern u8 *gUnknown_80FD2B4[];
extern u8 *gUnknown_80FAC74[];
extern u8 *gUnknown_80FAC54[];
extern u32 gUnknown_80F4F50;
extern s16 gUnknown_80F4DB8;
extern s16 gUnknown_80F4DBA;
extern s16 gUnknown_80F55BC[];
extern u8 *gUnknown_80FAE00[];
extern u8 *gUnknown_80FADD8[];
extern s16 gUnknown_80F4E02;
extern s16 gUnknown_80F4E04;
extern s16 gUnknown_80F4DB6;
extern s16 gUnknown_80F4EDC[];
extern u16 gUnknown_80F4F42;
extern u8 *gUnknown_80FAC88;
extern u8 *gUnknown_80FD018[];
extern u8 *gUnknown_80FCFBC[];
extern u8 *gUnknown_80FCFE4[];
extern u32 gUnknown_8106A4C;
extern s16 gUnknown_80F4DF6;
extern s16 gUnknown_80F4E0A;
extern u8 gUnknown_80F51E4[];
extern u32 gUnknown_80F51EC[];
extern u8 *gUnknown_80FC734[];
extern u8 *gUnknown_80FC7EC[];
extern u8 *gUnknown_80FCF74[];
extern u8 *gUnknown_80FCF80[];
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4E08;
extern u8 *gUnknown_80FD14C[];
extern u8 *gUnknown_80FAD4C[];
extern u32 gUnknown_80F4F68;
extern s16 gUnknown_80F502A[];
extern s16 gUnknown_80F4E74[];
extern s16 gUnknown_80F4E78[];
extern s16 gUnknown_80F4F28[];
extern u32 gUnknown_8106A54[];
extern s16 gUnknown_80F4DF0;
extern s16 gUnknown_80F4DE0;
extern s16 gUnknown_80F4DC4;
extern u8 *gUnknown_80FCF78[];
extern s16 gUnknown_80F4DF0;
extern u32 gUnknown_80F4F5C;
extern u8 *gUnknown_80FACFC[];
extern s16 gUnknown_80F4F7C;
extern s32 gSolarBeamMovePower;
extern u8 *gUnknown_80FACE4[];
extern u8 *gUnknown_80FEB8C[];
extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4DC8;
extern s16 gUnknown_80F4DEC;
extern s16 gUnknown_80F4E00;
extern u8 *gUnknown_80FD128[];
extern u8 *gUnknown_80FAD2C[];
extern u32 gUnknown_80F4F64;
extern u8 gSecretPowerTable[];
extern s16 gUnknown_80F4E06;
extern s16 gUnknown_80F4E94[];
extern u8 *gUnknown_80FC74C[];
extern u8 *gUnknown_80FC790[];
extern u8 *gUnknown_80FC7AC[];
extern u8 *gUnknown_80FD578[];
extern u8 *gUnknown_80FCCE4[];
extern u8 *gUnknown_80FC81C[];
extern u8 *gUnknown_80FC854[];
extern u8 *gUnknown_80FCF7C[];
extern u8 *gUnknown_80FC730[];
extern u16 gUnknown_80F4F42;
extern s16 gUnknown_80F4DF2;
extern u8 *gUnknown_80FC770[];
extern s32 gUnknown_80F51D4[];
extern s16 gUnknown_80F4DD2;
extern u8 *gUnknown_80FCA3C[];
extern u8 *gUnknown_80FD170[];
extern u8 *gUnknown_80FCCE8[];
extern u8 *gUnknown_80FD18C[];
extern u8 *gUnknown_80FD57C[];
extern s16 gUnknown_80F4F82;
extern u8 *gUnknown_80FEBDC[];
extern u8 *gUnknown_80FC5CC[];
extern s16 gUnknown_80F4DFA;
extern s16 gUnknown_80F4EE0;
extern u8 *gUnknown_81004EC[];
extern s16 gUnknown_80F4DDA;
extern s16 gUnknown_80F4DFE;
extern u8 *gUnknown_81004EC[];
extern s16 gUnknown_80F4DFC;
extern u8 *gUnknown_80FC7C8[];
extern u32 gUnknown_80F4F60;
extern u8 *gUnknown_80FAD10[];
extern s16 gUnknown_80F4DCC;
extern s16 gUnknown_80F4DBE;
extern s16 gUnknown_80F4DCA;
extern s16 gUnknown_80F4DE2;
extern u8 *gUnknown_80FEB90[];
extern s16 gUnknown_80F501A[];
extern u8 *gUnknown_80FEB60[];
extern u8 *gUnknown_80FE330[];
extern u8 *gUnknown_80FE36C[];
extern u8 *gPtrForecastPreventsTypeSwitchMessage[];

extern u32 gUnknown_202F210;
extern u32 gUnknown_202F214;
extern u8 gUnknown_202F218;
extern u32 gUnknown_202F21C;
extern bool8 gUnknown_202F220;

extern void sub_806A5B8(Entity *entity);
extern void sub_80694C0(Entity *, s32, s32, u32);
void sub_8075900(Entity *pokemon, u8 r1);
extern u8 sub_8044B28(void);
extern u8 sub_803F428(Position *pos);
extern void sub_807EC28(bool8);
extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_804652C(Entity *, Entity *, Item *, u32, Position *);
extern void sub_806EAF4(Entity *, Entity *, u8, u32, u32, s32 *, u32, u16, u32);
extern void sub_8045C28(Item *, u8 , u8);
extern void sub_805A7D4(Entity *, Entity *, Item *, Position *);
extern void MudWaterSportEffect(u32);
extern void sub_806EAF4(Entity *, Entity *, u8, u32, u32, s32 *, u32, u16, u32);
extern void sub_806A6E8(Entity *);

extern void sub_806ABAC(Entity *, Entity *);
extern u8 sub_806F4A4(Entity *, u32);
extern void sub_807DF38(Entity *pokemon, Entity *target, Position *pos, u32, u8 moveType, s16);
extern void nullsub_92(Entity *);
extern u32 sub_8055864(Entity *pokemon, Entity *target, Move *param_3, s32 param_4, s32 param_5);
extern u8 sub_807EAA0(u32, u32);
extern s32 sub_80556BC(Entity *, Entity *, u8, Move *, u32, u32);

// move_util.h
extern bool8 sub_805727C(Entity *, Entity *, s16);
bool8 sub_8057308(Entity *pokemon, s32 chance);
bool8 sub_80571F0(Entity * pokemon, Move *move);

extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern u32 HandleDamagingMove(Entity *, Entity *, Move *, u32, u32);
u8 sub_8057620(u32 param_1);
extern s16 sub_8094828(u16, u8);
extern void DealDamageToEntity(Entity *, s32, u32, u32);

extern s16 gUnknown_80F4DB4;
extern u32 gUnknown_8106A4C;

bool8 sub_805755C(Entity* pokemon, u16 moveID)
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

    if (EntityExists(pokemon)) {
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
    return sub_8094828(move->id, sub_8057620(itemID));
}

u8 sub_8057620(u32 itemID)
{
    if(itemID == ITEM_NOTHING)
        return ITEM_NOTHING;
    else
        return itemID;
}

bool8 sub_8057634(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon, target, gUnknown_80F4DB4)) {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, FALSE);
        }
    }
    return flag;
}

bool8 sub_805768C(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    gUnknown_202F21C++;

    if (HandleDamagingMove(pokemon, target, move, gUnknown_8106A54[gUnknown_202F21C], param_4) == 0)
        gUnknown_202F220 = 1;
    else
        flag = TRUE;
    return flag;
}

bool8 YawnMoveAction(Entity * pokemon, Entity *target, Move *move, s32 param_4)
{
    YawnedStatusTarget(pokemon, target, CalculateStatusTurns(target,gUnknown_80F4F28,TRUE) + 1);
    return TRUE;
}

bool8 sub_80576F8(Entity * pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_8075C58(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4E74, TRUE), TRUE);
    return TRUE;
}

bool8 NightmareMoveAction(Entity * pokemon, Entity *target, Move *move, s32 param_4)
{
    NightmareStatusTarget(pokemon, target, CalculateStatusTurns(target,gUnknown_80F4E78,TRUE));
    return TRUE;
}

bool8 sub_8057748(Entity * pokemon,Entity * target, Move *move, s32 param_4)
{
    HealTargetHP(pokemon, target, gUnknown_80F502A[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 VitalThrowMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    VitalThrowStatusTarget(pokemon, target);
    return TRUE;
}

bool8 DigMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    struct Tile *tile;
    bool8 flag;

    flag = FALSE;
    tile = GetTileAtEntitySafe(pokemon);
    if ((!IsTileGround(tile)) || ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != 1)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD14C); // It can only be used on land!
    }
    else {
        if (MoveMatchesChargingStatus(pokemon,move)) {
            HandleDamagingMove(pokemon,target,move,gUnknown_80F4F68,param_4);
            sub_8079764(pokemon);
        }
        else {
            SetChargeStatusTarget(pokemon,pokemon,STATUS_DIGGING,move,*gUnknown_80FAD4C); // $m0 burrowed underground!
        }
        flag = TRUE;
    }
    return flag;
}

bool32 sub_8057824(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  LowerAccuracyStageTarget(pokemon,target,gUnknown_8106A50,TRUE);
  return TRUE;
}

bool32 sub_805783C(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A4C,0x80,TRUE);
  return TRUE;
}

bool32 RainDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  gDungeon->weather.unkE267[WEATHER_RAIN] = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCF74);
  }
  return TRUE;
}

bool32 HailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  gDungeon->weather.unkE267[WEATHER_HAIL]= gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCF80);
  }
  return TRUE;
}

bool32 sub_80578EC(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_8079F20(pokemon, target, 1, 0);
    return TRUE;
}

bool32 sub_80578FC(Entity *pokemon, Entity *target, Move * move, u32 param_4)
{
  bool32 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target, gUnknown_80F4DB6)) {
      LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool32 EncoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    EncoreStatusTarget(pokemon, target);
    return TRUE;
}

bool32 RageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  // {POKEMON_0} is enraged
  SetChargeStatusTarget(pokemon,target,STATUS_ENRAGED,move,gUnknown_80FAC88);
  return TRUE;
}

bool32 sub_8057974(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  s32 newHP;
  bool8 local_24;

  newHP = GetEntInfo(target)->HP / 2;
  local_24 = FALSE;
  if (newHP != 0) {
    sub_806F370(pokemon,target,newHP,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = local_24 == 0;
  }
  else
  {
    // The target's HP can't be halved anymore
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD018);
  }
  return local_24;
}

bool8 PainSplitMoveAction(Entity *attacker, Entity *target, Move *move, s32 param_4)
{
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 newHP = (attackerInfo->HP + targetInfo->HP) / 2;

    attackerInfo->HP = newHP;
    targetInfo->HP = newHP;
    if (attackerInfo->HP > attackerInfo->maxHPStat) {
        attackerInfo->HP = attackerInfo->maxHPStat;
    }
    if (targetInfo->HP > targetInfo->maxHPStat) {
        targetInfo->HP = targetInfo->maxHPStat;
    }
    SetMessageArgument(gFormatBuffer_Monsters[0],attacker,0);
    SetMessageArgument(gFormatBuffer_Monsters[1],target,0);
    SetExpMultplier(attackerInfo);

    // $m0 and $m1 shared their HP
    TryDisplayDungeonLoggableMessage3(attacker,target,*gUnknown_80FC7EC);
    return TRUE;
}

bool8 TormentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  Move *movePtr;
  s32 iVar4;
  Move struggleMove;
  EntityInfo *entityInfo;
  bool8 isTormented;

  entityInfo = GetEntInfo(target);
  isTormented = FALSE;

  for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
  {
    movePtr = &entityInfo->moves.moves[iVar4];
    if ((movePtr->moveFlags & MOVE_FLAG_EXISTS) != 0) {
      if ((movePtr->moveFlags & MOVE_FLAG_DISABLED) == 0) {
        if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) != 0) {
          sub_80928C0(gFormatBuffer_Items[0],movePtr,0);
          // $i0 was tormented
          TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCFBC);
          movePtr->moveFlags |= MOVE_FLAG_DISABLED;
          isTormented = TRUE;
        }
      }
      else if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) == 0) {
        movePtr->moveFlags &= ~(MOVE_FLAG_DISABLED);
      }
    }
  };

  if ((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_DISABLED) == 0) {
    if ((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) != 0) {
      InitPokemonMove(&struggleMove, MOVE_STRUGGLE);
      entityInfo->moves.struggleMoveFlags |= MOVE_FLAG_DISABLED;
      isTormented = TRUE;
      sub_80928C0(gFormatBuffer_Items[0],&struggleMove,0);
      // $i0 was tormented
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCFBC);
    }
  }
  else if ((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) {
    entityInfo->moves.struggleMoveFlags &= ~(MOVE_FLAG_DISABLED);
  }
  if (isTormented)
  {
    if(entityInfo->charging.chargingStatus == STATUS_BIDE) {
        entityInfo->charging.chargingStatus = STATUS_NONE;
    }
  }
  else
  {
    // The target couldn't be tormented
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCFE4);
  }
  return isTormented;
}

bool8 sub_8057BB4(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
    return TRUE;
}

bool8 sub_8057BC4(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 SnoreMoveAction(Entity *pokemon, Entity *target, Move * move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (IsSleeping(pokemon)) {
    if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
      flag = TRUE;
      if (sub_805727C(pokemon,target,gUnknown_80F4E0A)) {
        CringeStatusTarget(pokemon,target,FALSE);
      }
    }
  }
  else {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC734);
  }
  return flag;
}

bool8 sub_8057C68(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ChangeDefenseMultiplierTarget(pokemon, target, gUnknown_8106A4C, 0x40, 1);
    return TRUE;
}

bool8 sub_8057C88(Entity *pokemon, Entity *target, Move * move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4DF6)) {
      CringeStatusTarget(pokemon,target,FALSE);
    }
  }
  return flag;
}

bool32 sub_8057CD0(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  u32 weather;
  s32 flag;

  weather = GetApparentWeather(pokemon);
  flag = sub_80556BC(pokemon,target,gUnknown_80F51E4[weather],move,
                      gUnknown_80F51EC[weather],param_4);
  if (flag) {
    flag = TRUE;
  }
  return flag;
}

bool8 WhirlpoolMoveAction(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  u32 uVar3;
  bool8 flag;
  u8 chargeStatus;

  flag = FALSE;
  chargeStatus = GetEntInfo(target)->charging.chargingStatus;
  uVar3 = 0x100;
  if (chargeStatus == STATUS_DIVING) {
    uVar3 = 0x200;
  }
  if (HandleDamagingMove(pokemon,target,move,uVar3,param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4E08)) {
      SqueezedStatusTarget(pokemon,target,0x3b,FALSE);
    }
  }
  return flag;
}

bool8 sub_8057D7C(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 2, 1, TRUE);
  return TRUE;
}

bool8 sub_8057D9C(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 i;
    EntityInfo *targetInfo = GetEntInfo(target);
    bool8 flag = FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &targetInfo->moves.moves[i];
        if (MoveFlagExists(move) && MoveFlagLastUsed(move)) {
            move->PP = 0;
            flag = TRUE;
        }
    }

    SetMessageArgument(gFormatBuffer_Monsters[1], target, 0);
    if (flag) {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD350);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD370);
    }

    return flag;
}

bool8 FocusEnergyMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    FocusEnergyStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SmokescreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    WhifferStatusTarget(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4EDC, TRUE));
    return TRUE;
}

bool8 sub_8057E50(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    SendThawedMessage(pokemon, target);
    MirrorMoveStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_8057E6C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  EntityInfo *entityInfo;
  bool8 flag;

  flag = FALSE;
  entityInfo = GetEntInfo(pokemon);
  SendThawedMessage(pokemon,target);
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if (sub_8057308(pokemon, 0)) {
      entityInfo->unk155 = 1;
    }
  }
  return flag;
}

bool8 sub_8057ED0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4E04))
    {
        ChangeAttackMultiplierTarget(pokemon, target, gUnknown_8106A4C, 0x80, FALSE);
    }
  }
  return flag;
}

bool8 sub_8057F24(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  EntityInfo *entityInfo;

  entityInfo = GetEntInfo(pokemon);
  entityInfo->HP = 1;
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A4C,0x40,TRUE);
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A50,0x40,TRUE);
  entityInfo->unk154 = 1;
  return TRUE;
}

bool8 sub_8057F7C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4E02))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, FALSE);
    }
  }
  return flag;
}

bool8 sub_8057FCC(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A50, 1);
    return TRUE;
}

bool8 sub_8057FF4(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  u8 flashFireStatus;

  flashFireStatus = GetFlashFireStatus(target);
  if (flashFireStatus != FLASH_FIRE_STATUS_NONE) {
    if (GetEntInfo(target)->unk152 == 0) {
      GetEntInfo(target)->unk152 = 1;
      SetMessageArgument(gFormatBuffer_Monsters[1],target,0);
      if (flashFireStatus == FLASH_FIRE_STATUS_MAXED) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FAE00); // Fire moves won't become stronger
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FADD8); // $m0 used flash fire to absorb fire
      }
    }
  }
  else {
    BurnedStatusTarget(pokemon,target, 0, TRUE);
  }
  return TRUE;
}

bool8 sub_805805C(Entity * pokemon,Entity * target,Move * move,s32 param_4)
{
  s16 *psVar3;
  s32 index;
  s32 r6;
  bool8 local_24;
  EntityInfo *entityInfo;
  s32 IQ;

  entityInfo = GetEntInfo(pokemon);


  r6 = 1;
  index = 0;
  if (0 <= gUnknown_80F55BC[0]) {
    IQ = entityInfo->IQ;
    for(psVar3 = &gUnknown_80F55BC[index]; (999 > index) && (*psVar3 >= 0); psVar3 = psVar3 + 2, index++)
        {
            if ((IQ < *psVar3)){
                r6 = psVar3[1];
                goto _080580B0;
            }
        }
 }
_080580B0:
  sub_806F370(pokemon,target,r6,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
  local_24 = local_24 == 0;
  return local_24;
}

bool8 GrudgeMoveAction(Entity *pokemon, Entity * target, Move *move, s32 param_4)
{
  EntityInfo *entityInfo;
  bool8 hasGrudge;

  hasGrudge = FALSE;
  entityInfo = GetEntInfo(target);
  SetMessageArgument(gFormatBuffer_Monsters[1],target,0);
  if (entityInfo->grudge) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD2B4);
  }
  else {
    entityInfo->grudge = TRUE;
    hasGrudge = TRUE;
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD294);
  }
  return hasGrudge;
}

bool8 CounterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    CounterStatusTarget(pokemon, target, STATUS_COUNTER);
    return TRUE;
}

bool8 sub_805816C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  SendThawedMessage(pokemon, target);
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DB8))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 sub_80581D0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  SendThawedMessage(pokemon, target);
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DBA))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058234(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    u16 uVar1;
    uVar1 = (move->id == MOVE_FORESIGHT) ? 0x7A : 0x51;
    ExposeStatusTarget(pokemon, target, uVar1);
    return TRUE;
}

bool8 sub_805825C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseAccuracyStageTarget(pokemon, target, gUnknown_8106A50);
    return TRUE;
}

bool8 sub_8058270(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;
  u32 r3;

  r3 = 1;
  if((u8)(GetEntInfo(target)->charging.chargingStatus - 7) <= 1)
    r3 = 2;
  flag =  HandleDamagingMove(pokemon,target,move,r3 << 8,param_4) ? TRUE : FALSE;
  return flag;
}

bool8 sub_80582AC(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    return TRUE;
}

bool8 sub_80582C4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_80582D4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    return TRUE;
}

bool8 RazorWindMoveAction(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  bool8 flag;

  if (MoveMatchesChargingStatus(pokemon,move)) {
    flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F4F50,param_4) ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_RAZOR_WIND,move,*gUnknown_80FAC54);
    flag = TRUE;
  }
  return flag;
}

bool8 BideMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
   SetChargeStatusTarget(pokemon, target, STATUS_BIDE, move, *gUnknown_80FAC74);
   return TRUE;
}

bool8 sub_805836C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  s32 iVar2;
  bool8 local_18;

  local_18 = FALSE;
  iVar2 = GetEntInfo(pokemon)->unkA0 * 2;
  if (999 < iVar2) {
    iVar2 = 999;
  }
  sub_806F370(pokemon,target,iVar2,1,&local_18, GetMoveType(move),0x1ff,0,1,0);

  local_18 = local_18 == 0;
  return local_18;
}

bool8 sub_80583D8(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DC2))
    {
        LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 1, 1, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058430(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DEE))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058478(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE6))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_80584C0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  s32 diffHP;
  bool8 local_24;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo1;


  local_24 = 0;
  entityInfo = GetEntInfo(pokemon);
  entityInfo1 = GetEntInfo(target);
  diffHP = entityInfo1->HP - entityInfo->HP;
  if (diffHP < 0) {
    diffHP = 0;
  }
  sub_806F370(pokemon,target,diffHP,0,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);

  local_24 = local_24 == 0;
  return local_24;
}

bool8 sub_8058548(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;
  u32 r5;

  r5 = 0x80 << 1;
  if((GetEntInfo(pokemon)->nonVolatile.nonVolatileStatus) != STATUS_NONE)
    r5 = gUnknown_80F4F6C;
  flag =  HandleDamagingMove(pokemon,target,move,r5,param_4) ? TRUE : FALSE;
  return flag;
}

bool8 sub_8058580(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DD4))
    {
        LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool8 BrickBreakMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if ((GetEntInfo(target)->protection.protectionStatus == STATUS_REFLECT) || (GetEntInfo(target)->protection.protectionStatus == STATUS_LIGHT_SCREEN)) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD104); // The barrier was shattered
    SendProtectionEndMessage(pokemon,target);
    flag = TRUE;
  }

  flag |= (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0);
  return flag;
}

bool8 sub_8058638(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool8 FocusPunchMoveAction(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  bool8 flag;

  if (MoveMatchesChargingStatus(pokemon,move)) {
    flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F4F54,param_4) ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_FOCUS_PUNCH,move,*gUnknown_80FACA4);
    flag = TRUE;
  }
  return flag;
}

bool8 sub_80586DC(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  bool8 hasLiquidOoze;
  s32 uVar3;
  s32 newHP;
  bool8 flag;
  EntityInfo *entityInfo;

  hasLiquidOoze = HasAbility(target, ABILITY_LIQUID_OOZE);
  uVar3 = HandleDamagingMove(pokemon,target,move,0x100,param_4);
  flag = uVar3 != 0 ? TRUE : FALSE;
  if (flag && sub_8057308(pokemon, 0)) {
    newHP = uVar3 / 2;
    entityInfo = GetEntInfo(pokemon);
    flag = TRUE;
    if (newHP < 1) {
      newHP = 1;
    }
    SetExpMultplier(entityInfo);
    if (hasLiquidOoze) {
        DealDamageToEntity(pokemon, newHP, 0xd, 0x1fa);
    }
    else {
        HealTargetHP(pokemon, pokemon, newHP, 0, TRUE);
    }
  }
  return flag;
}


// NOTE: almost the same as sub_8058D44 and sub_805AFA4 in status_actions.c
bool8 sub_8058770(Entity * pokemon, Entity * target, Move * move, u32 param_4)
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

    flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F51A4[index],param_4) ? TRUE : FALSE;
    return flag;
}

bool8 sub_80587E8(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  bool8 flag;

  if (GetEntInfo(target)->nonVolatile.nonVolatileStatus == STATUS_PARALYSIS) {
    flag = HandleDamagingMove(pokemon,target,move,0x80 << 2,param_4) ? TRUE : FALSE;
    SendNonVolatileEndMessage(pokemon, target);
  }
  else {
    flag = HandleDamagingMove(pokemon,target,move,0x80 << 1,param_4) ? TRUE : FALSE;
  }
  return flag;
}

bool8 sub_8058838(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 3, 1, TRUE);
    return TRUE;
}

bool8 sub_8058858(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    s32 index = gUnknown_8106A4C;
    LowerAttackStageTarget(pokemon, target, index, 1, 1, TRUE);
    LowerDefenseStageTarget(pokemon, target, index, 1, 1, TRUE);
    return TRUE;
}

bool8 sub_805889C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    ImmobilizedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_80588A8(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    sub_8079E34(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_80588B8(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    if(HandleDamagingMove(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, 0))
        {
            gUnknown_202F219 = 1;
        }
    }
    return flag;
}

bool8 sub_80588F4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    bool8 flag;
    EntityInfo *entityInfo = GetEntInfo(target);

    flag = HandleDamagingMove(pokemon, target, move, GetWeight(entityInfo->apparentID), param_4) != 0 ? TRUE: FALSE;
    return flag;
}


bool8 sub_8058930(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    EntityInfo *entityInfo;
    s32 index1;
    s32 index2;
    if(HandleDamagingMove(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, gUnknown_80F4DD6))
        {
            entityInfo = GetEntInfo(pokemon);
            RaiseMovementSpeedTarget(pokemon, pokemon, 0, TRUE);
            index1 = gUnknown_8106A4C;
            RaiseAttackStageTarget(pokemon, pokemon, index1, 1);
            index2 = gUnknown_8106A50;
            RaiseAttackStageTarget(pokemon, pokemon, index2, 1);
            RaiseDefenseStageTarget(pokemon, pokemon, index1, 1);
            RaiseDefenseStageTarget(pokemon, pokemon, index2, 1);
            SetExpMultplier(entityInfo);
        }
    }
    return flag;
}

bool8 sub_80589D4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    HealTargetHP(pokemon, target, gUnknown_80F500A[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 sub_8058A08(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
    return TRUE;
}

bool8 sub_8058A18(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    if(HandleDamagingMove(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, 0))
        {
            gUnknown_202F21A = 1;
        }
    }
    return flag;
}

bool8 sub_8058A54(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    SureShotStatusTarget(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4EB8, FALSE));
    return TRUE;
}

bool8 sub_8058A7C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A50, 1);
    return TRUE;
}

bool8 SkyAttackMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    bool8 flag = FALSE;

    if(MoveMatchesChargingStatus(pokemon, move))
    {
        if (HandleDamagingMove(pokemon, target, move, gUnknown_80F4F4C, param_4) != 0) {
           flag = TRUE;
            if(sub_805727C(pokemon, target, gUnknown_80F4DF4))
                CringeStatusTarget(pokemon, target, FALSE);
        }
        sub_8079764(pokemon);
    }
    else {
       SetChargeStatusTarget(pokemon, pokemon, STATUS_SKY_ATTACK, move, *gUnknown_80FACC4);
       flag = TRUE;
    }
    return flag;
}

bool8 sub_8058B3C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DBC))
    {
        FrozenStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058B84(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;
  EntityInfo *entityInfo;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, pokemon, gUnknown_80F4DD0))
    {
        entityInfo = GetEntInfo(pokemon);
        RaiseAttackStageTarget(pokemon, pokemon, gUnknown_8106A4C, 1);
        SetExpMultplier(entityInfo);
    }
  }
  return flag;
}

bool8 EndureMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    EndureStatusTarget(pokemon, pokemon);
    return TRUE;
}

bool8 sub_8058BF0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
    return TRUE;
}

bool8 sub_8058C00(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DF8))
    {
        ConfuseStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058C48(Entity *pokemon, Entity *target, Move *move, u32 param_4)
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
  flag = sub_8055864(pokemon,target,move,rand,param_4) != 0 ? TRUE: FALSE;
  return flag;
}

bool8 sub_8058C98(Entity *pokemon, Entity *target, Move *move, u32 param_4, u32 param_5)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_5) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DC0))
    {
        LowerDefenseStageTarget(pokemon, target,  param_4, 1, 1, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058CEC(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    if(HandleDamagingMove(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, 0))
        {
            LowerAttackStageTarget(pokemon, pokemon, gUnknown_8106A50, 2, 0, FALSE);
        }
    }
    return flag;
}

bool8 sub_8058D38(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    SleeplessStatusTarget(pokemon, target);
    return TRUE;
}


// NOTE: same as sub_8058770
bool8 sub_8058D44(Entity * pokemon, Entity * target, Move * move, u32 param_4)
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

    flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F51B4[index],param_4) ? TRUE : FALSE;
    return flag;
}


bool8 PsychUpMoveAction(Entity * pokemon, Entity * target, Move * move, u32 param_4)
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
  SetMessageArgument(gFormatBuffer_Monsters[0],target,0);
  TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FBD58); // It psyched itself up!
  SetExpMultplier(iVar4);
  return TRUE;
}

bool8 sub_8058E5C(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  int iVar2;
  int iVar3;
  bool8 flag;

  flag = FALSE;
  if ((HandleDamagingMove(pokemon, target, move, 0x80 << 1, param_4) != 0) && (EntityExists(pokemon))) {
    iVar2 = GetEntInfo(pokemon)->maxHPStat;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    iVar3 = iVar2 >> 3;
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    flag = TRUE;
    if ((!HasAbility(pokemon, ABILITY_ROCK_HEAD)) && sub_8057308(pokemon, 0)) {
      sub_806F370(pokemon,pokemon,iVar3,0,0,0,0x1fd,0x14,1,0);
    }
  }
  return flag;
}

bool8 sub_8058EE0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    HealTargetHP(pokemon, target, GetEntInfo(target)->maxHPStat / 2, 0, TRUE);
    return TRUE;
}

bool32 sub_8058F04(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool32 flag;
  EntityInfo *entityInfo;
  s32 iVar3;

  entityInfo = GetEntInfo(target);
  iVar3 = 1;
  gDungeon->unk181e8.unk18200 = 0xc;
  gDungeon->unk181e8.unk18204 = 0;
  if (entityInfo->charging.chargingStatus == STATUS_DIGGING) {
    iVar3 = 2;
  }
  flag = HandleDamagingMove(pokemon,target,move,iVar3 << 8,param_4);
  if (flag != 0) {
    flag = TRUE;
  }
  return flag;
}

bool8 NaturePowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
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
  flag = gNaturePowerCalledMoves[tileset].callback(pokemon,target,&natureMove,param_4);
  return flag;
}

bool8 sub_8058FBC(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE4))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059004(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    sub_807DF38(pokemon, target, &target->pos, 1, GetMoveType(move), sub_8057600(move, param_4));
    return TRUE;
}

bool8 sub_8059050(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 ChargeMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    SetChargeStatusTarget(pokemon, target, STATUS_CHARGING, move, *gUnknown_80FAD6C);
    return TRUE;
}

bool8 sub_8059080(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE8))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 MistMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    MistStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_80590D4(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  u8 moveType;
  bool8 uVar5;
  bool8 flag;

  flag = FALSE;
  moveType = GetMoveType(move);

  uVar5 = sub_806F4A4(target, moveType) != 0 ? TRUE : FALSE;

  if (HasAbility(target, ABILITY_LEVITATE)) {
    uVar5 = FALSE;
  }
  if (!uVar5) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEB88);
  }
  else {
    sub_806F370(pokemon,target,9999,1,&flag,GetMoveType(move),sub_8057600(move,param_4),0,1,1);
    flag = flag == 0;
  }
  return flag;
}

bool8 sub_8059190(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DEA))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 SafeguardMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    SafeguardStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_80591E4(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 hasLiquidOoze;
  s32 iVar3;
  s32 iVar4;
  bool8 flag;

  flag = FALSE;
  hasLiquidOoze = HasAbility(target, ABILITY_LIQUID_OOZE);
  iVar3 = HandleDamagingMove(pokemon,target,move,0x100,param_4);
  if (iVar3 != 0) {
    iVar4 = iVar3 / 2;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    if (EntityExists(pokemon)) {
      EntityInfo *entityInfo = GetEntInfo(pokemon);
      flag = TRUE;
      SetExpMultplier(entityInfo);
      if (sub_8057308(pokemon,0)) {
        if (hasLiquidOoze) {
            DealDamageToEntity(pokemon,iVar4,0xd,0x1fa);
        }
        else {
            HealTargetHP(pokemon,pokemon,iVar4,0,1);
        }
      }
    }
  }
  return flag;
}

bool8 SkillSwapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool32 flag;

  EntityInfo *pokeEntityData = GetEntInfo(pokemon);
  EntityInfo *targetEntityInfo = GetEntInfo(target);
  if ((HasAbility(target, ABILITY_WONDER_GUARD)) || (HasAbility(pokemon, ABILITY_WONDER_GUARD))) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC8C0);
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
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC888);
    // Weirdly enough SetExpMultplier inline doesn't work here...
    if (pokeEntityData->expMultiplier == EXP_HALVED) {
        pokeEntityData->expMultiplier = EXP_REGULAR;
    }
    sub_806ABAC(pokemon,pokemon);
    sub_806ABAC(pokemon,target);
    flag = TRUE;
  }
  return flag;
}

bool32 SketchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    s32 i;
    bool32 ret = FALSE;
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
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FE3BC);
        return FALSE;
    }

    if (moveId == MOVE_NOTHING) {
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FE3BC);
    }
    else {
        InitPokemonMove(move, moveId);
        sub_80928C0(gFormatBuffer_Items[0], move, 0);
        move->moveFlags2 |= MOVE_FLAG2_UNK4;
        move->moveFlags2 |= MOVE_FLAG_REPLACE;
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FE38C);
        ASM_MATCH_TRICK(pokeInfo);
        SetExpMultplier(pokeInfo);
        ret = TRUE;
    }

    return ret;
}

bool8 sub_8059424(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DF0))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_805946C(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  s32 HP;
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if ((!HasAbility(pokemon, ABILITY_ROCK_HEAD)) && (sub_8057308(pokemon,0) != 0)) {
      HP = GetEntInfo(pokemon)->maxHPStat;
      if (HP < 0) {
        HP = HP + 7;
      }
      HP = HP >> 3;
      if (HP == 0) {
        HP = 1;
      }
      sub_806F370(pokemon,pokemon,HP,0,0,0,0x1fd,0x14,1,0);
    }
  }
  return flag;
}


bool8 SandstormMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    gDungeon->weather.unkE267[WEATHER_SANDSTORM] = gUnknown_80F4F42;
    if(sub_807EAA0(1, 0) == 0)
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FCF78);
    }
    return TRUE;
}

bool8 sub_8059528(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, TRUE);
    return TRUE;
}

bool8 sub_8059540(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DC4))
    {
        PoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059588(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A50, 1);
    return TRUE;
}

bool8 sub_80595A0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE0))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 sub_80595EC(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  u8 moveType;
  u8 local_20;

  local_20 = 0;
  if (sub_806F4A4(target,GetMoveType(move)) == 0) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEB8C);
    return FALSE;
  }
  else {
    moveType = GetMoveType(move);
    sub_806F370(pokemon,target,9999,1,&local_20,moveType,sub_8057600(move,param_4),0,1,0);
    local_20 = (local_20 == 0);
    return local_20;
  }
}

bool8 SolarBeamMoveAction(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  u8 weather; // weather and flag are reused in same variable
  s32 movePower;

  weather = GetApparentWeather(pokemon);
  if ((weather == WEATHER_SUNNY) || (MoveMatchesChargingStatus(pokemon,move))) {
    movePower = gSolarBeamMovePower;

    if (((weather == WEATHER_SANDSTORM) || (weather == WEATHER_RAIN)) || weather == WEATHER_HAIL) {
      movePower /= 2;
    }
    weather = HandleDamagingMove(pokemon,target,move,movePower,param_4) != 0 ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_SOLARBEAM,move,*gUnknown_80FACE4);
    weather = TRUE;
  }
  return weather;
}

bool8 sub_8059714(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
    u8 local_20;

    local_20 = 0;
    sub_806F370(pokemon,target,gUnknown_80F4F7C,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = local_20 == 0;
    return local_20;
}

bool8 FlyMoveAction(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (MoveMatchesChargingStatus(pokemon,move)) {
      flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F4F5C,param_4) != 0 ? TRUE : FALSE;
      sub_8079764(pokemon);
  }
  else {
      SetChargeStatusTarget(pokemon,pokemon,STATUS_FLYING,move,*gUnknown_80FACFC);
      flag = TRUE;
  }
  return flag;
}

bool8 sub_80597F0(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
    sub_807DF38(pokemon,target,&target->pos,2,GetMoveType(move),sub_8057600(move,param_4));
    return TRUE;
}

bool8 DiveMoveAction(Entity * pokemon, Entity * target, Move * move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (IsTileGround(GetTileAtEntitySafe(pokemon))) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD128);
  }
  else if (MoveMatchesChargingStatus(pokemon,move)) {
      flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F4F64,param_4) != 0 ? TRUE : FALSE;
      sub_8079764(pokemon);
  }
  else {
      SetChargeStatusTarget(pokemon,pokemon,STATUS_DIVING,move,*gUnknown_80FAD2C);
      flag = TRUE;
  }
  return flag;
}

bool8 sub_80598CC(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4E00))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, FALSE);
    }
  }
  return flag;
}

bool8 StockpileMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    HandleStockpile(pokemon, target);
    return TRUE;
}

bool8 sub_8059928(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  bool8 flag;
  s32 iVar2;

  iVar2 = 1;
  flag = FALSE;
  if ((u8)(GetEntInfo(target)->charging.chargingStatus - 7) <= 1){
      iVar2 = 2;
  }
  if (HandleDamagingMove(pokemon,target,move,iVar2 << 8,param_4) != 0)
  {
    flag = TRUE;
    if(sub_805727C(pokemon,target,gUnknown_80F4DEC) != 0) {
        CringeStatusTarget(pokemon,target,FALSE);
    }
  }
  return flag;
}

bool8 sub_8059988(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    gUnknown_202F218 = 1;
  }
  if (((gUnknown_202F218 != 0) && (gUnknown_202F214 == 2)) &&
     (sub_805727C(pokemon,target,gUnknown_80F4DC8) != 0)) {
    PoisonedStatusTarget(pokemon,target,FALSE);
  }
  return flag;
}

bool8 sub_80599EC(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    s32 HP;

    HP = GetEntInfo(target)->maxHPStat;
    if(HP < 0)
        HP += 3;
    HealTargetHP(pokemon, target, HP >> 2, 0, TRUE);
    return TRUE;
}

bool8 sub_8059A18(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseAccuracyStageTarget(pokemon, target, gUnknown_8106A50);
    return TRUE;
}

bool8 sub_8059A2C(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
    u8 local_20;
    u32 level;

    local_20 = 0;
    level = GetEntInfo(pokemon)->level;
    sub_806F370(pokemon,target,level,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = local_20 == 0;
    return local_20;
}

bool8 sub_8059AA8(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059AB8(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    TauntStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_8059AC4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    HealTargetHP(pokemon, target, gUnknown_80F501A[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 sub_8059AF8(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  u8 local_20;

  local_20 = 0;
  if (sub_806F4A4(target,GetMoveType(move)) == 0) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEB90);
    return FALSE;
  }
  else {
    sub_806F370(pokemon,target,9999,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,0,0);
    local_20 = local_20 == 0;
    return local_20;
  }
}

bool8 sub_8059B94(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 ConversionMoveAction(Entity * pokemon,Entity * target,Move * move,u32 param_4)
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
  if (HasAbility(target, ABILITY_FORECAST)) {
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gPtrForecastPreventsTypeSwitchMessage);
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
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FE36C);
        return FALSE;
    }
    else
    {
      newIndex = DungeonRandInt(counter);
      moveType = GetMoveTypeForMonster(target,moveStack[newIndex]);
      info->types[0] = moveType;
      info->types[1] = TYPE_NONE;
      info->isColorChanged = TRUE;
      sub_80928C0(gFormatBuffer_Items[0], moveStack[newIndex], NULL);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FE330);
      return TRUE;
    }
  }
}

bool8 Conversion2MoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    Conversion2StatusTarget(pokemon, target);
    return TRUE;
}

bool8 HelpingHandMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    bool8 flag;
    flag = FALSE;
    if(pokemon == target)
    {
        TryDisplayDungeonLoggableMessage3(target, target, *gUnknown_80FEB60);
    }
    else {
        RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1);
        RaiseAttackStageTarget(pokemon, target, gUnknown_8106A50, 1);
        flag = TRUE;
    }
    return flag;
}

bool8 sub_8059CD8(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 sub_8059CF0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    sub_807D148(pokemon, target, 0, NULL);
    return TRUE;
}

bool8 sub_8059D00(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE2))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059D48(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059D58(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059D98(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    ImmobilizedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_8059DA4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    PoisonedStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059DB4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    BadlyPoisonedStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059DC4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DCA))
    {
        BadlyPoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059E0C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DBE))
    {
        PoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059E54(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5)
{
  u8 moveType;
  u32 movePower;
  u32 moveCritChance;
  bool8 flag;
  s32 local_30 [4];
  u8 auStack_20;

  flag = FALSE;
  if (param_5 == 0) {
    flag = HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0 ? TRUE : FALSE;
  }
  if (!flag) {
    moveType = GetMoveTypeForMonster(pokemon,move);
    movePower = GetMovePower(pokemon,move);
    moveCritChance = GetMoveCritChance(move);
    sub_806EAF4(pokemon,target,moveType,movePower,moveCritChance,local_30,0x100,move->id,0);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],GetEntInfo(pokemon),0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC7C8);
    local_30[0] = local_30[0] / 2;
    if (local_30[0] == 0) {
      local_30[0] = 1;
    }
    sub_806F370(pokemon,pokemon,local_30[0],0,&auStack_20,0,0x1f7,0x13,1,0);
  }
  return flag;
}

bool8 sub_8059F38(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (MoveMatchesChargingStatus(pokemon, move)) {
    if (HandleDamagingMove(pokemon, target, move, gUnknown_80F4F60, param_4) != 0) {
      flag = TRUE;
      if (sub_805727C(pokemon, target, gUnknown_80F4DCC) != 0) {
        ParalyzeStatusTarget(pokemon, target, FALSE);
      }
    }
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon, pokemon, STATUS_BOUNCING, move, *gUnknown_80FAD10);
    flag = TRUE;
  }
  return flag;
}

bool8 sub_8059FC8(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5)
{
  u8 moveType;
  u32 movePower;
  u32 moveCritChance;
  bool8 flag;
  s32 local_30 [4];
  u8 auStack_20;

  flag = FALSE;
  if (param_5 == 0) {
    flag = HandleDamagingMove(pokemon,target,move,0x200,param_4) != 0 ? TRUE : FALSE;
  }
  if (!flag) {
    moveType = GetMoveTypeForMonster(pokemon,move);
    movePower = GetMovePower(pokemon,move);
    moveCritChance = GetMoveCritChance(move);
    sub_806EAF4(pokemon,target,moveType,movePower,moveCritChance,local_30,0x200,move->id,0);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],GetEntInfo(pokemon),0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC7C8);
    local_30[0] = local_30[0] / 2;
    if (local_30[0] == 0) {
      local_30[0] = 1;
    }
    sub_806F370(pokemon,pokemon,local_30[0],0,&auStack_20,0,0x1f8,0x13,1,0);
  }
  return flag;
}

bool8 TriAttackMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if(HandleDamagingMove(pokemon, target, move, 0x100, param_4))
    {
        flag = TRUE;
        if(sub_805727C(pokemon, target, gUnknown_80F4DFC))
        {
            switch(DungeonRandInt(3))
            {
                case 0:
                default:
                    ParalyzeStatusTarget(pokemon, target, FALSE);
                    break;
                case 1:
                    BurnedStatusTarget(pokemon, target, 0, FALSE);
                    break;
                case 2:
                    FrozenStatusTarget(pokemon, target, FALSE);
                    break;
            }
        }
    }
    return flag;
}

bool8 sub_805A120(Entity * pokemon,Entity * target, Move *move, u32 param_4)
{
    EntityInfo *r9;
    EntityInfo *r8;
    EntityInfo *r7;
    EntityInfo *sp;
    Item item;
    bool32 flag;
    Item *item1;
    Item *item2;

    flag = FALSE;
    r9 = GetEntInfo(pokemon);
    r7 = r9;
    r8 = GetEntInfo(target);
    sp = r8;

    SetMessageArgument(gFormatBuffer_Monsters[0],pokemon,0);
    SetMessageArgument(gFormatBuffer_Monsters[1],target,0);
    if (HasAbility(target, ABILITY_STICKY_HOLD)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCCE4);
        return FALSE;
    }
    else if (HasHeldItem(target, ITEM_ALERT_SPECS)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD578);
        return FALSE;
    }
    else
    {
        item1 = &r9->heldItem;
        item2 = &r8->heldItem;
        if (!(item1->flags & ITEM_FLAG_EXISTS))
            flag = TRUE;

        if(!(item2->flags & ITEM_FLAG_EXISTS))
            flag = TRUE;

        if (flag)
        {
                TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC7AC); // The item trade failed
                return FALSE;
        }
        else
        {
            item = r7->heldItem;
            r7->heldItem = sp->heldItem;
            sp->heldItem = item;
            sub_806A6E8(pokemon);
            sub_806A6E8(target);
            SetExpMultplier(r7);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC790); // Traded items
            return TRUE;
        }
    }
}

bool8 sub_805A210(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    gUnknown_202F210++;
    flag = HandleDamagingMove(pokemon, target, move, gUnknown_202F210 << 8, param_4) ? TRUE : FALSE;
    return flag;
}

bool8 MudWaterSportMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    if(move->id == MOVE_MUD_SPORT)
    {
        MudWaterSportEffect(0);
    }
    else
    {
        MudWaterSportEffect(1);
    }
    return TRUE;
}


bool8 sub_805A258(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, FALSE);
    }
  }
  return flag;
}

bool8 sub_805A2A0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    return sub_805BA50(pokemon, target, move, param_4);
}

bool8 sub_805A2B0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A50, 2);
    return TRUE;
}

bool8 sub_805A2C8(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, TRUE);
    return TRUE;
}

bool8 SurfMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;
  u32 uVar2;

  flag = FALSE;
  if (GetEntInfo(target)->charging.chargingStatus == STATUS_DIVING) {
      uVar2 = 0x200;
  }
  else
  {
      uVar2 = 0x100;
  }
  if(HandleDamagingMove(pokemon,target,move,uVar2,param_4) != 0)
    flag = TRUE;
  return flag;
}

bool8 RolePlayMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  EntityInfo * entityInfo;
  EntityInfo * targetEntityInfo;

  entityInfo = GetEntInfo(pokemon);
  targetEntityInfo = GetEntInfo(target);
  if (HasAbility(target, ABILITY_WONDER_GUARD)) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC854);
    return FALSE;
  }
  else
  {
    entityInfo->abilities[0] = targetEntityInfo->abilities[0];
    entityInfo->abilities[1] = targetEntityInfo->abilities[1];
    gDungeon->unkC = 1;
    SetExpMultplier(entityInfo);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC81C);
    sub_806ABAC(pokemon, pokemon);
    return TRUE;
  }
}

bool8 SunnyDayMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  gDungeon->weather.unkE267[WEATHER_SUNNY] = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCF7C);
  }
  return TRUE;
}

bool8 sub_805A3DC(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, TRUE);
    return TRUE;
}

bool8 WishMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    WishStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805A408(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DF2))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_805A450(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC730);
  return FALSE;
}

bool8 sub_805A464(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool32 flag;
  Item item;
  Position pos;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_8057308(pokemon, 0) != 0) {
      if (!EntityExists(target)) {
        pos.x = 0;
        pos.y = 0;
        sub_8045C28(&item,0x69,2);
        sub_805A7D4(pokemon,target,&item,&pos);
      }
    }
  }
  return flag;
}

bool8 sub_805A4C0(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC74C);
  return FALSE;
}

bool8 sub_805A4D4(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    NappingStatusTarget(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4E94, FALSE));
    return TRUE;
}

bool8 sub_805A4FC(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    IngrainedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SwallowMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  u8 *stockpileStage;

  stockpileStage = &GetEntInfo(target)->stockpileStage;
  if (*stockpileStage != 0) {
    HealTargetHP(pokemon,target,gUnknown_80F51D4[*stockpileStage],0,TRUE);
    *stockpileStage = 0;
  }
  else {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC770);
  }
  return TRUE;
}

bool8 CurseMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    CurseStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805A568(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    flag = HandleDamagingMove(pokemon, target, move, 0x100, param_4) ? TRUE : FALSE;
    return flag;
}

bool8 TickleMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  u32 stat;
  bool32 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,pokemon,0) != 0) {
      stat = gUnknown_8106A4C;
      LowerAttackStageTarget(pokemon,pokemon,stat,1,0,FALSE);
      LowerDefenseStageTarget(pokemon,pokemon,stat,1,0,FALSE);
    }
  }
  return flag;
}

bool8 sub_805A5E8(Entity *pokemon, Entity *target, Move *move, u32 stat, u32 param_5)
{
  EntityInfo *entityInfo;
  bool32 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_5) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,pokemon,gUnknown_80F4DD2) != 0) {
      entityInfo = GetEntInfo(pokemon);
      RaiseDefenseStageTarget(pokemon,pokemon,stat,1);
      SetExpMultplier(entityInfo);
    }
  }
  return flag;
}

bool8 SpitUpMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  u8 *stockpileStage;

  stockpileStage = &GetEntInfo(pokemon)->stockpileStage;
  if (*stockpileStage != 0) {
    HandleDamagingMove(pokemon,target,move,*stockpileStage << 8,param_4);
    *stockpileStage = 0;
  }
  else {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCA3C);
  }
  return TRUE;
}

bool8 sub_805A688(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        ConfuseStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 KnockOffMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    EntityInfo *entityInfo;
    EntityInfo *targetEntityInfo;
    Item heldItem;
    Position pos;

    entityInfo = GetEntInfo(pokemon);
    targetEntityInfo = GetEntInfo(target);
    SetMessageArgument(gFormatBuffer_Monsters[0], pokemon, 0);
    SetMessageArgument(gFormatBuffer_Monsters[1], target, 0);
    if (HasAbility(target, ABILITY_STICKY_HOLD))
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCCE8);
        return FALSE;
    }
    else if (HasHeldItem(target, ITEM_ALERT_SPECS))
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD57C);
        return FALSE;
    }
    else
    {
        heldItem = targetEntityInfo->heldItem;
        if (!ItemExists(&heldItem))
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD18C);
            return FALSE;
        }
        else
        {
            ZeroOutItem(&targetEntityInfo->heldItem);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD170); // $m1's item was swatted down!
            pos.x = gAdjacentTileOffsets[entityInfo->action.direction].x;
            pos.y = gAdjacentTileOffsets[entityInfo->action.direction].y;
            sub_805A7D4(pokemon,target,&heldItem,&pos);
            if (sub_80706A4(target, &target->pos) != 0)
            {
                sub_807D148(pokemon, target, 0, NULL);
            }
            return TRUE;
        }
    }
}

void sub_805A7D4(Entity * pokemon, Entity * target, Item *item, Position *pos)
{
  Entity stackEntity;

  stackEntity.type = ENTITY_ITEM;
  stackEntity.unk24 = 0;
  stackEntity.isVisible = TRUE;
  stackEntity.unk22 = 0;
  stackEntity.axObj.info = (EntityInfo*) item;
  stackEntity.pos.x = target->pos.x + pos->x;
  stackEntity.pos.y = target->pos.y + pos->y;
  SetEntityPixelPos(&stackEntity,(target->pos.x * 0x18 + 4) * 0x100,
              (target->pos.y * 0x18 + 4) * 0x100);
  stackEntity.spawnGenID = 0;
  SetMessageArgument(gFormatBuffer_Items[0],&stackEntity,0);
  sub_804652C(pokemon,&stackEntity,item,1,0);
}

bool8 sub_805A85C(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
  int x;
  int y;
  int counter;
  Position *r9;
  Position pos1;
  Move stackMove;
  Position32 pos2;
  struct Tile *tile;
  Entity *entity;
  s32 temp;
  s32 temp2;
  u8 check;


  pos1 = target->pos;
  sub_806CDD4(target,10,8);

  for(counter = 0; counter < 0x28; counter++)
  {
    x = DungeonRandInt(3);
    y = DungeonRandInt(3);
    x--;
    y--;
    if ((x != 0) || (y != 0)) {
      pos1.x = target->pos.x + x;
      pos1.y = target->pos.y + y;
      if (sub_80705F0(target,&pos1) == 0) goto _0805A8C2;
    }
  }
_0805A8C2:
  if (counter == 0x28) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEBDC);
    return FALSE;
  }
  temp = pos1.x * 0x1800;
  temp += (0xC00);
  pos2.x =  (temp - target->pixelPos.x) / 0xc;

  temp2 = pos1.y * 0x1800;
  temp2 += (0x80 << 5);
  pos2.y = ((temp2 - target->pixelPos.y) / 0xc);


  if (((check = sub_803F428(&target->pos), r9 = &target->pos, check != 0)) || (sub_803F428(&pos1) != 0)) {
    for(counter = 0; counter < 0xC; counter++)
    {
      IncreaseEntityPixelPos(target,pos2.x,pos2.y);
      sub_803E46C(0x2c);
    }
  }
  tile = GetTileSafe(pos1.x,pos1.y);
  entity = tile->monster;
  if (entity != NULL) {
    if (GetEntityType(entity) == ENTITY_MONSTER) {
      InitPokemonMove(&stackMove,MOVE_REGULAR_ATTACK);
      if (sub_80571F0(entity,&stackMove) == 0) {
        sub_806F370(pokemon,entity,gUnknown_80F4F82,0,0,TYPE_NONE,sub_8057600(move, param_4),0,1,0);
      }
      if ((sub_8044B28() == 0) && (EntityExists(pokemon))) {
        sub_806F370(pokemon,pokemon,gUnknown_80F4F82,0,0,0,0x1fe,0,0,0);
        if ((sub_8044B28() == 0) && (EntityExists(pokemon))) goto _0805A9FE;
      }
    }
    else {
_0805A9FE:
      if (EntityExists(target)) {
        if ((sub_803F428(r9) != 0) || (sub_803F428(&pos1) != 0)) {
          for(counter = 0; counter < 0xC; counter++)
          {
            IncreaseEntityPixelPos(target, -pos2.x,-pos2.y);
            sub_803E46C(0x2c);
          }
        }
        goto _0805AA5E;
      }
    }
  }
  else
  {
    sub_80694C0(target,pos1.x,pos1.y,0);
_0805AA5E:
    if (EntityExists(target)) {
#ifndef NOMATCHING
      register Position *pos asm("r1");
#else
      Position *pos;
#endif
      sub_804535C(target, NULL);
      pos = r9;
      if (sub_80706A4(target, pos)) {
        sub_807D148(pokemon,target,0,0);
      }
      if (GetEntInfo(target)->isTeamLeader) {
        sub_804AC20(r9);
        sub_807EC28(FALSE);
      }
      sub_806A5B8(target);
      sub_8075900(target,gDungeon->unk3A08);
    }
  }
  return TRUE;
}

bool8 sub_805AAD0(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    FixedDamageStatusTarget(pokemon, pokemon);
    return TRUE;
}

bool8 BellyDrumMoveAction(Entity * pokemon,Entity * target, Move *move, u32 param_4)
{
  EntityInfo *info;
  bool8 flag;

  info = GetEntInfo(pokemon);
  flag = FALSE;
  if (FixedPointToInt(info->belly) > 1) {
    RaiseAttackStageTarget(pokemon,target,gUnknown_8106A4C,99);
    info->belly = IntToFixedPoint(1);
    flag = TRUE;
  }
  else {
    SetMessageArgument(gFormatBuffer_Monsters[0],pokemon,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC5CC);
  }
  return flag;
}

bool8 LightScreenMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    LightScreenStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SecretPowerMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if ( HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4E06) != 0) {
        switch(gSecretPowerTable[gDungeon->tileset]) {
            case 0:
                PoisonedStatusTarget(pokemon,target,FALSE);
                break;
            case 1:
                sub_8075C58(pokemon,target,CalculateStatusTurns(target,gUnknown_80F4E74,TRUE),FALSE);
                break;
            case 2:
                LowerMovementSpeedTarget(pokemon,target,1,FALSE);
                break;
            case 3:
                LowerAttackStageTarget(pokemon,target,gUnknown_8106A4C,1,1,FALSE);
                break;
            case 4:
                LowerDefenseStageTarget(pokemon,target,gUnknown_8106A4C,1,1,FALSE);
                break;
            case 5:
                LowerAccuracyStageTarget(pokemon,target,gUnknown_8106A4C,FALSE);
                break;
            case 6:
                ConfuseStatusTarget(pokemon,target,FALSE);
                break;
            case 7:
                CringeStatusTarget(pokemon,target,FALSE);
                break;
            case 8:
            default:
                ParalyzeStatusTarget(pokemon,target,FALSE);
                break;
        }
    }
  }
  return flag;
}

bool8 sub_805AC90(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
    if ( HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DFA) != 0) {
            ConfuseStatusTarget(pokemon, target, FALSE);
        }
    }
    return flag;
}

bool8 BulkUpMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    s32 stat = gUnknown_8106A4C;
    RaiseAttackStageTarget(pokemon, target, stat, 1);
    RaiseDefenseStageTarget(pokemon, target, stat, 1);
    return TRUE;
}

bool8 sub_805AD04(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    PausedStatusTarget(pokemon, target, 1, CalculateStatusTurns(target, &gUnknown_80F4EE0, TRUE), TRUE);
    return TRUE;
}

bool8 sub_805AD34(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2, 1, TRUE);
    return TRUE;
}

bool32 sub_805AD54(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    s32 numPossibleTargets;
    s32 i;
    Entity **possibleTargets;
    bool32 flag = FALSE;
    EntityInfo *info = GetEntInfo(pokemon);

    if (info->isNotTeamMember) {
        possibleTargets = gDungeon->wildPokemon;
        numPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
    }
    else {
        possibleTargets = gDungeon->teamPokemon;
        numPossibleTargets = MAX_TEAM_MEMBERS;
    }

    for (i = 0; i < numPossibleTargets; i++) {
        Entity *targetEntity = possibleTargets[i];
        if (EntityExists(targetEntity)
             && pokemon != targetEntity
             && GetTreatmentBetweenMonsters(pokemon,targetEntity,FALSE,FALSE) == TREATMENT_TREAT_AS_ALLY)
        {
            EntityInfo *targetInfo = GetEntInfo(targetEntity);
            if (targetInfo->clientType != CLIENT_TYPE_CLIENT && !IsClientOrTeamBase(targetInfo->joinedAt.joinedAt)) {
                sub_807D148(pokemon,targetEntity,2,&target->pos);
                flag = TRUE;
                SetExpMultplier(info);
            }
        }
    }

    if (!flag) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_81004EC);
    }
    return flag;
}

bool8 sub_805AE3C(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  SendThawedMessage(pokemon, target);
  flag = HandleDamagingMove(pokemon,target,move,0x80 << 2,param_4) != 0 ? TRUE : FALSE;
  return flag;
}

bool8 sub_805AE74(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if ( HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DDA) != 0) {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, FALSE);
        }
    }
    return flag;
}

bool8 sub_805AECC(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    flag = FALSE;
    SendThawedMessage(pokemon, target);
    if ( HandleDamagingMove(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DFE) != 0) {
            BurnedStatusTarget(pokemon, target, 0, FALSE);
        }
    }
    return flag;
}

bool8 PresentMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    s32 rand1 = DungeonRandInt(100);
    s32 rand2 = rand1;
    if (rand1 < 10) {
        flag = (sub_8055864(pokemon,target,move,0x78,param_4) != 0);
        return flag;
    }
    else {
        if (rand1 < 30) {
            HealTargetHP(pokemon,target,GetEntInfo(target)->maxHPStat/4,0,
                         TRUE);
            return TRUE;
        }
        else if (rand2 >= 60) {
            flag = (sub_8055864(pokemon,target,move,0x28,param_4) != 0);
            return flag;
        }
        else {
            flag = (sub_8055864(pokemon,target,move,0x50,param_4) != 0);
            return flag;
        }
    }
}
