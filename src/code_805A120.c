#include "global.h"
#include "code_806CD90.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "item.h"
#include "moves.h"
#include "move_effects_target.h"
#include "move_util.h"
#include "number_util.h"
#include "status.h"
#include "status_actions.h"
#include "tile_types.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "charge_move.h"
#include "weather.h"

extern u32 gUnknown_202F210;
extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202F218;
extern u32 gUnknown_202F214;

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
extern s16 gUnknown_80F4E74;
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

extern u32 sub_8055864(struct Entity *pokemon, struct Entity *target, struct Move *param_3, s32 param_4, s32 param_5);
extern void sub_80943A0(void*, s32);
extern s16 sub_8057600(struct Move*, u32);
extern u8 sub_8044B28(void);
extern u8 sub_803F428(struct Position *pos);
extern void IncreaseEntityPixelPos(struct Entity *, u32, u32);
extern void sub_803E46C(u32);
extern void sub_807EC28(bool8);
extern void sub_806F370(struct Entity *r0, struct Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
void sub_8075900(struct Entity *pokemon, u8 r1);
extern void sub_804535C(struct Entity *, u32);
extern void sub_804AC20(struct Position *);
extern void sub_806A5B8(struct Entity *entity);
extern void sub_80694C0(struct Entity *, s32, s32, u32);
extern void sub_807D148(struct Entity *pokemon, struct Entity *target, u32 r2, struct Position *r3);
extern void SetMessageArgument(u8 *buffer, struct Entity *r1, u32);
extern void SetMessageArgument_2(u8 *buffer, struct EntityInfo *r1, u32);
void sub_80522F4(struct Entity *r0, struct Entity *r1, char r2[]);
extern void sub_806A6E8(struct Entity *);
extern u32 sub_8055640(struct Entity *, struct Entity *, struct Move *, u32, u32);
extern void sub_807EA30(u32);
extern void sub_806ABAC(struct Entity *, struct Entity *);
extern u8 sub_807EAA0(u32, u32);
extern void sub_8045C28(struct Item *, u8 , u8);
extern void sub_805A7D4(struct Entity *, struct Entity *, struct Item *, struct Position *);
extern void sub_8045394(struct Entity *, s32, s32);
extern void sub_804652C(struct Entity *, struct Entity *, struct Item *, u32, struct Position *);
extern void sub_806EAF4(struct Entity *, struct Entity *, u8, u32, u32, s32 *, u32, u16, u32);
extern u8 *gUnknown_80FEB60[];
extern u8 *gUnknown_80FE330[];
extern u8 *gUnknown_80FE36C[];
extern u8 *gPtrForecastPreventsTypeSwitchMessage[];

extern u8 sub_806F4A4(struct Entity *, u32);
extern void sub_807DF38(struct Entity *pokemon, struct Entity *target, struct Position *pos, u32, u8 moveType, s16);


bool8 sub_8059424(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DF0))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_805946C(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  s32 HP;
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if ((!HasAbility(pokemon, ABILITY_ROCK_HEAD)) && (sub_8057308(pokemon,0) != 0)) {
      HP = pokemon->info->maxHPStat;
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

bool8 sub_80594E0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    gDungeon->unkE269 = gUnknown_80F4F42;
    if(sub_807EAA0(1, 0) == 0)
    {
        sub_80522F4(pokemon, target, *gUnknown_80FCF78);
    }
    return TRUE;
}

bool8 sub_8059528(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, TRUE);
    return TRUE;
}

bool8 sub_8059540(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DC4))
    {
        PoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059588(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A50, 1);
    return TRUE;
}

bool8 sub_80595A0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE0))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 sub_80595EC(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  u8 moveType;
  u8 local_20;
  
  local_20 = 0;
  if (sub_806F4A4(target,GetMoveType(move)) == 0) {
    sub_80522F4(pokemon,target,*gUnknown_80FEB8C);
    return FALSE;
  }
  else {
    moveType = GetMoveType(move);
    sub_806F370(pokemon,target,9999,1,&local_20,moveType,sub_8057600(move,param_4),0,1,0);
    local_20 = (local_20 == 0);
    return local_20;
  }
}

bool8 SolarBeamMoveAction(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  u8 weather; // weather and flag are reused in same variable
  s32 movePower;
  
  weather = GetApparentWeather(pokemon);
  if ((weather == WEATHER_SUNNY) || (MoveMatchesChargingStatus(pokemon,move))) {
    movePower = gSolarBeamMovePower;
    
    if (((weather == WEATHER_SANDSTORM) || (weather == WEATHER_RAIN)) || weather == WEATHER_HAIL) {
      movePower /= 2;
    }
    weather = sub_8055640(pokemon,target,move,movePower,param_4) != 0 ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_SOLARBEAM,move,*gUnknown_80FACE4);
    weather = TRUE;
  }
  return weather;
}

bool8 sub_8059714(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
    u8 local_20;
    
    local_20 = 0;
    sub_806F370(pokemon,target,gUnknown_80F4F7C,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = local_20 == 0;
    return local_20;
}

bool8 FlyMoveAction(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (MoveMatchesChargingStatus(pokemon,move)) {
      flag = sub_8055640(pokemon,target,move,gUnknown_80F4F5C,param_4) != 0 ? TRUE : FALSE;
      sub_8079764(pokemon);
  }
  else {
      SetChargeStatusTarget(pokemon,pokemon,STATUS_FLYING,move,*gUnknown_80FACFC);
      flag = TRUE;
  }
  return flag;
}

bool8 sub_80597F0(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
    sub_807DF38(pokemon,target,&target->pos,2,GetMoveType(move),sub_8057600(move,param_4));
    return TRUE;
}

bool8 DiveMoveAction(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (IsTileGround(GetTileAtEntitySafe(pokemon))) {
    sub_80522F4(pokemon,target,*gUnknown_80FD128);
  }
  else if (MoveMatchesChargingStatus(pokemon,move)) {
      flag = sub_8055640(pokemon,target,move,gUnknown_80F4F64,param_4) != 0 ? TRUE : FALSE;
      sub_8079764(pokemon);
  }
  else {
      SetChargeStatusTarget(pokemon,pokemon,STATUS_DIVING,move,*gUnknown_80FAD2C);
      flag = TRUE;
  }
  return flag;
}

bool8 sub_80598CC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4E00))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, FALSE);
    }
  }
  return flag;
}

bool8 StockpileMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    HandleStockpile(pokemon, target);
    return TRUE;
}

bool8 sub_8059928(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  bool8 flag;
  s32 iVar2;
  
  iVar2 = 1;
  flag = FALSE;
  if ((u8)(target->info->chargingStatus - 7) <= 1){
      iVar2 = 2;
  }
  if (sub_8055640(pokemon,target,move,iVar2 << 8,param_4) != 0)
  {
    flag = TRUE;
    if(sub_805727C(pokemon,target,gUnknown_80F4DEC) != 0) {
        CringeStatusTarget(pokemon,target,FALSE);
    } 
  }
  return flag;
}

bool8 sub_8059988(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    gUnknown_202F218 = 1;
  }
  if (((gUnknown_202F218 != 0) && (gUnknown_202F214 == 2)) &&
     (sub_805727C(pokemon,target,gUnknown_80F4DC8) != 0)) {
    PoisonedStatusTarget(pokemon,target,FALSE);
  }
  return flag;
}

bool8 sub_80599EC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    s32 HP;

    HP = target->info->maxHPStat;
    if(HP < 0)
        HP += 3;
    HealTargetHP(pokemon, target, HP >> 2, 0, TRUE);
    return TRUE;
}

bool8 sub_8059A18(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseAccuracyStageTarget(pokemon, target, gUnknown_8106A50);
    return TRUE;
}

bool8 sub_8059A2C(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
    u8 local_20;
    u32 level;
    
    local_20 = 0;
    level = pokemon->info->level;
    sub_806F370(pokemon,target,level,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = local_20 == 0;
    return local_20;
}

bool8 sub_8059AA8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059AB8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    TauntStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_8059AC4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    HealTargetHP(pokemon, target, gUnknown_80F501A[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 sub_8059AF8(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  u8 local_20;
  
  local_20 = 0;
  if (sub_806F4A4(target,GetMoveType(move)) == 0) {
    sub_80522F4(pokemon,target,*gUnknown_80FEB90);
    return FALSE;
  }
  else {
    sub_806F370(pokemon,target,9999,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,0,0);
    local_20 = local_20 == 0;
    return local_20;
  }
}

bool8 sub_8059B94(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 ConversionMoveAction(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  u8 moveType;
  struct Move *movePtr;
  s32 index;
  struct EntityInfo * info;
  s32 counter;
  s32 newIndex;
  struct Move *moveStack [MAX_MON_MOVES];
  
  counter = 0;
  info = target->info;
  if (HasAbility(target, ABILITY_FORECAST)) {
      sub_80522F4(pokemon,target,*gPtrForecastPreventsTypeSwitchMessage);
      return FALSE;
  }
  else
  {
    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &info->moves[index];
      if (((movePtr->moveFlags & MOVE_FLAG_EXISTS)) && (GetMoveTypeForMonster(target,movePtr) != TYPE_NONE)) {
        moveStack[counter]  = movePtr;
        counter++;
      }
    }
    if (counter == 0) {
        sub_80522F4(pokemon,target,*gUnknown_80FE36C);
        return FALSE;
    }
    else
    {
      newIndex = DungeonRandInt(counter);
      moveType = GetMoveTypeForMonster(target,moveStack[newIndex]);
      info->types[0] = moveType;
      info->types[1] = TYPE_NONE;
      info->isColorChanged = TRUE;
      sub_80928C0(gUnknown_202DE58, moveStack[newIndex], NULL);
      sub_80522F4(pokemon,target,*gUnknown_80FE330);
      return TRUE;
    }
  }
}

bool8 Conversion2MoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    Conversion2StatusTarget(pokemon, target);
    return TRUE;
}

bool8 HelpingHandMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    bool8 flag;
    flag = FALSE;
    if(pokemon == target)
    {
        sub_80522F4(target, target, *gUnknown_80FEB60);
    }
    else {
        RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1);
        RaiseAttackStageTarget(pokemon, target, gUnknown_8106A50, 1);
        flag = TRUE;
    }
    return flag;
}

bool8 sub_8059CD8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 sub_8059CF0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    sub_807D148(pokemon, target, 0, NULL);
    return TRUE;
}

bool8 sub_8059D00(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE2))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059D48(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059D58(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059D98(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    ImmobilizedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_8059DA4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    PoisonedStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059DB4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    BadlyPoisonedStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_8059DC4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DCA))
    {
        BadlyPoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059E0C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DBE))
    {
        PoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059E54(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4,u8 param_5)
{
  u8 moveType;
  u32 movePower;
  u32 moveCritChance;
  bool8 flag;
  s32 local_30 [4];
  u8 auStack_20;
  
  flag = FALSE;
  if (param_5 == 0) {
    flag = sub_8055640(pokemon,target,move,0x100,param_4) != 0 ? TRUE : FALSE;
  }
  if (!flag) {
    moveType = GetMoveTypeForMonster(pokemon,move);
    movePower = GetMovePower(pokemon,move);
    moveCritChance = GetMoveCritChance(move);
    sub_806EAF4(pokemon,target,moveType,movePower,moveCritChance,local_30,0x100,move->id,0);
    SetMessageArgument_2(gAvailablePokemonNames,pokemon->info,0);
    sub_80522F4(pokemon,target,*gUnknown_80FC7C8);
    local_30[0] = local_30[0] / 2;
    if (local_30[0] == 0) {
      local_30[0] = 1;
    }
    sub_806F370(pokemon,pokemon,local_30[0],0,&auStack_20,0,0x1f7,0x13,1,0);
  }
  return flag;
}

bool8 sub_8059F38(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (MoveMatchesChargingStatus(pokemon, move)) {
    if (sub_8055640(pokemon, target, move, gUnknown_80F4F60, param_4) != 0) {
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

bool8 sub_8059FC8(struct Entity * pokemon,struct Entity * target,struct Move * move,u32 param_4,u8 param_5)
{
  u8 moveType;
  u32 movePower;
  u32 moveCritChance;
  bool8 flag;
  s32 local_30 [4];
  u8 auStack_20;
  
  flag = FALSE;
  if (param_5 == 0) {
    flag = sub_8055640(pokemon,target,move,0x200,param_4) != 0 ? TRUE : FALSE;
  }
  if (!flag) {
    moveType = GetMoveTypeForMonster(pokemon,move);
    movePower = GetMovePower(pokemon,move);
    moveCritChance = GetMoveCritChance(move);
    sub_806EAF4(pokemon,target,moveType,movePower,moveCritChance,local_30,0x200,move->id,0);
    SetMessageArgument_2(gAvailablePokemonNames,pokemon->info,0);
    sub_80522F4(pokemon,target,*gUnknown_80FC7C8);
    local_30[0] = local_30[0] / 2;
    if (local_30[0] == 0) {
      local_30[0] = 1;
    }
    sub_806F370(pokemon,pokemon,local_30[0],0,&auStack_20,0,0x1f8,0x13,1,0);
  }
  return flag;
}

bool8 TriAttackMoveAction(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if(sub_8055640(pokemon, target, move, 0x100, param_4))
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

bool8 sub_805A120(struct Entity * pokemon,struct Entity * target, struct Move *move, u32 param_4)
{
    struct EntityInfo *r9;
    struct EntityInfo *r8;
    struct EntityInfo *r7;
    struct EntityInfo *sp;
    struct Item item;
    bool32 flag;
    struct Item *item1;
    struct Item *item2;

    flag = FALSE;
    r9 = pokemon->info;
    r7 = r9;
    r8 = target->info;
    sp = r8;

    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    SetMessageArgument(gAvailablePokemonNames + 0x50,target,0);
    if (HasAbility(target, ABILITY_STICKY_HOLD)) {
        sub_80522F4(pokemon,target,*gUnknown_80FCCE4);
        return FALSE;
    }
    else if (HasHeldItem(target, ITEM_ALERT_SPECS)) {
        sub_80522F4(pokemon,target,*gUnknown_80FD578);
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
                sub_80522F4(pokemon,target,*gUnknown_80FC7AC);   
                return FALSE;
        }
        else
        {
            item = r7->heldItem;
            r7->heldItem = sp->heldItem;
            sp->heldItem = item;
            sub_806A6E8(pokemon);
            sub_806A6E8(target);
            if (r7->unkFB == 0) {
                r7->unkFB = 1;
            }
            sub_80522F4(pokemon,target,*gUnknown_80FC790);
            return TRUE;
        }
    }
}

bool8 sub_805A210(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    bool8 flag;

    gUnknown_202F210++;
    flag = sub_8055640(pokemon, target, move, gUnknown_202F210 << 8, param_4) ? TRUE : FALSE;
    return flag;
}

bool8 sub_805A23C(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    if(move->id == MOVE_MUD_SPORT)
    {
        sub_807EA30(0);
    }
    else
    {
        sub_807EA30(1);
    }
    return TRUE;
}


bool8 sub_805A258(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, FALSE);
    }
  }
  return flag;
}

bool8 sub_805A2A0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    return sub_805BA50(pokemon, target, move, param_4);
}

bool8 sub_805A2B0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A50, 2);
    return TRUE;
}

bool8 sub_805A2C8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, TRUE);
    return TRUE;
}

bool8 SurfMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  u32 uVar2;
  
  flag = FALSE;
  if (target->info->chargingStatus == STATUS_DIVING) {
      uVar2 = 0x200;
  }
  else
  {
      uVar2 = 0x100;
  }
  if(sub_8055640(pokemon,target,move,uVar2,param_4) != 0)
    flag = TRUE;
  return flag;
}

bool8 RolePlayMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  struct EntityInfo * entityInfo;
  struct EntityInfo * targetEntityInfo;
  
  entityInfo = pokemon->info;
  targetEntityInfo = target->info;
  if (HasAbility(target, ABILITY_WONDER_GUARD)) {
    sub_80522F4(pokemon,target,*gUnknown_80FC854);
    return FALSE;
  }
  else
  {
    entityInfo->abilities[0] = targetEntityInfo->abilities[0];
    entityInfo->abilities[1] = targetEntityInfo->abilities[1];
    gDungeon->unkC = 1;
    if (entityInfo->unkFB == 0) {
      entityInfo->unkFB = 1;
    }
    sub_80522F4(pokemon,target,*gUnknown_80FC81C);
    sub_806ABAC(pokemon, pokemon);
    return TRUE;
  }
}

bool8 sub_805A394(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  gDungeon->unkE267[1] = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    sub_80522F4(pokemon,target,*gUnknown_80FCF7C);
  }
  return TRUE;
}

bool8 sub_805A3DC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, TRUE);
    return TRUE;
}

bool8 WishMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    WishStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805A408(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DF2))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_805A450(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  sub_80522F4(pokemon,target,*gUnknown_80FC730);
  return FALSE;
}

bool8 sub_805A464(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool32 flag;
  struct Item item;
  struct Position pos;
  
  flag = FALSE;
  if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
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

bool8 sub_805A4C0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  sub_80522F4(pokemon,target,*gUnknown_80FC74C);
  return FALSE;
}

bool8 sub_805A4D4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    NappingStatusTarget(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4E94, FALSE));
    return TRUE;
}

bool8 sub_805A4FC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    IngrainedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SwallowMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4) 
{
  u8 *stockpileStage;
  
  stockpileStage = &target->info->stockpileStage;
  if (*stockpileStage != 0) {
    HealTargetHP(pokemon,target,gUnknown_80F51D4[*stockpileStage],0,TRUE);
    *stockpileStage = 0;
  }
  else {
    sub_80522F4(pokemon,target,*gUnknown_80FC770);
  }
  return TRUE;
}

bool8 CurseMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    CurseStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805A568(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    bool8 flag;

    flag = sub_8055640(pokemon, target, move, 0x100, param_4) ? TRUE : FALSE;
    return flag;
}

bool8 TickleMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4) 
{
  u32 stat;
  bool32 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,pokemon,0) != 0) {
      stat = gUnknown_8106A4C;
      LowerAttackStageTarget(pokemon,pokemon,stat,1,0,FALSE);
      LowerDefenseStageTarget(pokemon,pokemon,stat,1,0,FALSE);
    }
  }
  return flag;
}

bool8 sub_805A5E8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 stat, u32 param_5) 
{
  struct EntityInfo *entityInfo;
  bool32 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_5) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,pokemon,gUnknown_80F4DD2) != 0) {
      entityInfo = pokemon->info;
      RaiseDefenseStageTarget(pokemon,pokemon,stat,1);
      if (entityInfo->unkFB == 0) {
        entityInfo->unkFB = 1;
      }
    }
  }
  return flag;
}

bool8 SpitUpMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4) 
{
  u8 *stockpileStage;
  
  stockpileStage = &pokemon->info->stockpileStage;
  if (*stockpileStage != 0) {
    sub_8055640(pokemon,target,move,*stockpileStage << 8,param_4);
    *stockpileStage = 0;
  }
  else {
    sub_80522F4(pokemon,target,*gUnknown_80FCA3C);
  }
  return TRUE;
}

bool8 sub_805A688(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        ConfuseStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 KnockOffMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    struct EntityInfo *entityInfo;
    struct EntityInfo *targetEntityInfo1;
    struct EntityInfo *targetEntityInfo2;
    struct Item heldItem;
    struct Position pos;
    struct Item *itemPtr;
    u32 flag;
    u32 itemFlag;

    entityInfo = pokemon->info;
    targetEntityInfo1 = target->info;
    targetEntityInfo2 = targetEntityInfo1;
    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
    SetMessageArgument(gAvailablePokemonNames + 0x50, target, 0);
    if (HasAbility(target, ABILITY_STICKY_HOLD)) 
    {
        sub_80522F4(pokemon,target,*gUnknown_80FCCE8);
        return FALSE;
    }
    else if (HasHeldItem(target, ITEM_ALERT_SPECS)) 
    {
        sub_80522F4(pokemon,target,*gUnknown_80FD57C);
        return FALSE;
    }
    else
    {
        heldItem = targetEntityInfo1->heldItem;
        itemFlag = heldItem.flags;
        flag = ITEM_FLAG_EXISTS;
        flag &= itemFlag;
        if (flag == 0) 
        {
            sub_80522F4(pokemon,target,*gUnknown_80FD18C);
            return FALSE;
        }
        else
        {
            itemPtr = &targetEntityInfo2->heldItem;
            itemPtr->id = ITEM_NOTHING;
            itemPtr->quantity = 0;
            itemPtr->flags = 0;
            sub_80522F4(pokemon,target,*gUnknown_80FD170); // $m1's item was swatted down!
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

void sub_805A7D4(struct Entity * pokemon, struct Entity * target, struct Item *item, struct Position *pos)
{
  struct Entity stackEntity;
  
  stackEntity.type = ENTITY_ITEM;
  stackEntity.unk24 = 0;
  stackEntity.isVisible = TRUE;
  stackEntity.unk22 = 0;
  stackEntity.info = (struct EntityInfo*) item;
  stackEntity.pos.x = target->pos.x + pos->x;
  stackEntity.pos.y = target->pos.y + pos->y;
  sub_8045394(&stackEntity,(target->pos.x * 0x18 + 4) * 0x100,
              (target->pos.y * 0x18 + 4) * 0x100);
  stackEntity.spawnGenID = 0;
  SetMessageArgument(gUnknown_202DE58,&stackEntity,0);
  sub_804652C(pokemon,&stackEntity,item,1,0);
}

bool8 sub_805A85C(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
  int x;
  int y;
  int counter;
  struct Position *r9;
  struct Position pos1;
  struct Move stackMove;
  struct Position32 pos2;
  struct Tile *tile;
  struct Entity *entity;
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
    sub_80522F4(pokemon,target,*gUnknown_80FEBDC);
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
      register struct Position *pos asm("r1");
#else
      struct Position *pos;
#endif
      sub_804535C(target, 0);
      pos = r9;
      if (sub_80706A4(target, pos)) {
        sub_807D148(pokemon,target,0,0);
      }
      if (target->info->isTeamLeader) {
        sub_804AC20(r9);
        sub_807EC28(FALSE);
      }
      sub_806A5B8(target);
      sub_8075900(target,gDungeon->unk3A08);
    }
  }
  return TRUE;
}

bool8 sub_805AAD0(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    FixedDamageStatusTarget(pokemon, pokemon);
    return TRUE;
}

bool8 BellyDrumMoveAction(struct Entity * pokemon,struct Entity * target, struct Move *move, u32 param_4)
{
  u32 *belly;
  u32 newBelly;
  struct EntityInfo *info;
  bool8 flag;

  info = pokemon->info;
  flag = FALSE;
  belly = &info->belly;
  if (RoundUpFixedPoint(*belly) > 1) {
    RaiseAttackStageTarget(pokemon,target,gUnknown_8106A4C,99);
    sub_80943A0(&newBelly,1);
    *belly = newBelly;
    flag = TRUE;
  }
  else {
    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    sub_80522F4(pokemon,target,*gUnknown_80FC5CC);
  }
  return flag;
}

bool8 LightScreenMoveAction(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    LightScreenStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SecretPowerMoveAction(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if ( sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4E06) != 0) {
        switch(gSecretPowerTable[gDungeon->tileset]) {
            case 0:
                PoisonedStatusTarget(pokemon,target,FALSE);
                break;
            case 1:
                sub_8075C58(pokemon,target,CalculateStatusTurns(target,&gUnknown_80F4E74,TRUE),FALSE);
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

bool8 sub_805AC90(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
    if ( sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DFA) != 0) {
            ConfuseStatusTarget(pokemon, target, FALSE);
        }
    }
    return flag;
}

bool8 BulkUpMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    s32 stat = gUnknown_8106A4C;
    RaiseAttackStageTarget(pokemon, target, stat, 1);
    RaiseDefenseStageTarget(pokemon, target, stat, 1);
    return TRUE;
}

bool8 sub_805AD04(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    PausedStatusTarget(pokemon, target, 1, CalculateStatusTurns(target, &gUnknown_80F4EE0, TRUE), TRUE);
    return TRUE;
}

bool8 sub_805AD34(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2, 1, TRUE);
    return TRUE;
}

static inline bool8 sub_805AD54_sub(struct Entity *entity)
{
    if ((entity->info->joinedAt == 0x4A) || (entity->info->joinedAt == 0x47)) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_805AD54(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
  s32 numPossibleTargets;
  struct EntityInfo *info;
  struct Entity *targetEntity;
#ifndef NONMATCHING
  register s32 index asm("r6");
#else
  s32 index;
#endif
  struct Entity **possibleTargets;
  bool8 flag;
  
  flag = FALSE;
  info = pokemon->info;
  if (pokemon->info->isNotTeamMember) {
    possibleTargets = gDungeon->wildPokemon;
    numPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
  }
  else {
    possibleTargets = gDungeon->teamPokemon;
    numPossibleTargets = MAX_TEAM_MEMBERS;
  }
  for ( index = 0; index < numPossibleTargets; index++) {
    targetEntity = possibleTargets[index];
    if ((((EntityExists(targetEntity)) && (pokemon != targetEntity)) &&
        (CanTarget(pokemon,targetEntity,FALSE,FALSE) == TARGET_CAPABILITY_CANNOT_ATTACK)) &&
       (targetEntity->info->clientType != CLIENT_TYPE_CLIENT)) {
      if (!sub_805AD54_sub(targetEntity)) {
        sub_807D148(pokemon,targetEntity,2,&target->pos);
        flag = TRUE;
        if (info->unkFB == 0) {
          info->unkFB = 1;
        }
      }
    }
  }
  if (!flag) {
    sub_80522F4(pokemon,target,*gUnknown_81004EC);
  }
  return flag;
}

bool8 sub_805AE3C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
 
  SendThawedMessage(pokemon, target);
  flag = sub_8055640(pokemon,target,move,0x80 << 2,param_4) != 0 ? TRUE : FALSE;
  return flag;
}

bool8 sub_805AE74(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if ( sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DDA) != 0) {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, FALSE);
        }
    }
    return flag;
}

bool8 sub_805AECC(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
    bool8 flag;
  
    flag = FALSE;
    SendThawedMessage(pokemon, target);
    if ( sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DFE) != 0) {
            BurnedStatusTarget(pokemon, target, 0, FALSE);
        }
    }
    return flag;
}

bool8 PresentMoveAction(struct Entity * pokemon, struct Entity * target, struct Move *move, u32 param_4)
{
  s32 rand1;
  s32 rand2;
  s32 HP;
  bool8 flag;
#ifndef NONMATCHING    
  register struct Move *move_r6 asm("r6");
  register u32 param_4_r4 asm("r4");
#else
  struct Move *move_r6;
  u32 param_4_r4;
#endif

  move_r6 = move;
  param_4_r4 = param_4;

  rand1 = DungeonRandInt(100);
  rand2 = rand1;
  if (rand1 < 10) {
    flag = sub_8055864(pokemon,target,move_r6,0x78,param_4_r4) != 0 ? TRUE : FALSE;
    return flag;
  }
  else {
    if (rand1 < 0x1e) {
      HP = target->info->maxHPStat;
      if (HP < 0) {
        HP = HP + 3;
      }
      HealTargetHP(pokemon,target,HP >> 2,0,TRUE);
      return TRUE;
    }
    if (rand2 > 0x3B) {
        flag = sub_8055864(pokemon,target,move_r6,0x28,param_4_r4) != 0 ? TRUE : FALSE;
        return flag;
    }
    else {
        flag = sub_8055864(pokemon,target,move_r6,0x50,param_4_r4) != 0 ? TRUE : FALSE;
        return flag;
    }
  }
}
