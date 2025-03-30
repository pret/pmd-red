#include "global.h"
#include "globaldata.h"
#include "code_803E46C.h"
#include "code_803E724.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "code_808417C.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_logic.h"
#include "dungeon_config.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_move.h"
#include "dungeon_logic.h"
#include "dungeon_move_util.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "moves.h"
#include "move_effects_target.h"
#include "move_util.h"
#include "number_util.h"
#include "pokemon.h"
#include "status.h"
#include "status_actions.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "text_util.h"
#include "trap.h"
#include "weather.h"

extern void sub_806A5B8(Entity *entity);
void sub_8075900(Entity *pokemon, u8 r1);
extern u8 sub_8044B28(void);
extern void sub_807EC28(bool8);
extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void CalcDamage(Entity *, Entity *, u8, u32, u32, s32 *, u32, u16, u32);
static void sub_805A7D4(Entity *, Entity *, Item *, DungeonPos *);
extern void MudWaterSportEffect(u32);
extern void CalcDamage(Entity *, Entity *, u8, u32, u32, s32 *, u32, u16, u32);
extern void sub_806A6E8(Entity *);

extern void EndAbilityImmuneStatus(Entity *, Entity *);
extern u8 sub_806F4A4(Entity *, u32);
extern void HandleExplosion(Entity *pokemon, Entity *target, DungeonPos *pos, u32, u8 moveType, s16);
extern void nullsub_92(Entity *);
extern u8 sub_807EAA0(u32, u32);

// move_util.h
extern bool8 sub_805727C(Entity *, Entity *, s32);
bool8 RollSecondaryEffect(Entity *pokemon, s32 chance);
bool8 sub_80571F0(Entity * pokemon, Move *move);

extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void DealDamageToEntity(Entity *, s32, u32, u32);
extern s16 sub_8057600(Move *move, s32 itemID);

extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;

bool8 PoisonStingMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gPoisonStingSecondaryChance))
    {
        PoisonedStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 JumpKickMoveAction(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5)
{
  u8 moveType;
  u32 movePower;
  u32 moveCritChance;
  bool8 flag;
  s32 local_30 [4];
  u8 auStack_20;

  flag = FALSE;
  if (param_5 == 0) {
    flag = HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0 ? TRUE : FALSE;
  }
  if (!flag) {
    moveType = GetMoveTypeForMonster(pokemon,move);
    movePower = GetMovePower(pokemon,move);
    moveCritChance = GetMoveCritChance(move);
    CalcDamage(pokemon,target,moveType,movePower,moveCritChance,local_30,0x100,move->id,0);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],GetEntInfo(pokemon),0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC7C8);
    local_30[0] = local_30[0] / 2;
    if (local_30[0] == 0) {
      local_30[0] = 1;
    }
    sub_806F370(pokemon,pokemon,local_30[0],0,&auStack_20,0,0x1f7,0x13,1,0);
  }
  return flag;
}

bool8 BounceMoveAction(Entity * pokemon,Entity * target,Move * move,u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (MoveMatchesBideClassStatus(pokemon, move)) {
    if (HandleDamagingMove(pokemon, target, move, gBounceModifier, param_4) != 0) {
      flag = TRUE;
      if (sub_805727C(pokemon, target, gBounceSecondaryChance) != 0) {
        ParalyzeStatusTarget(pokemon, target, FALSE);
      }
    }
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon, pokemon, STATUS_BOUNCING, move, gUnknown_80FAD10);
    flag = TRUE;
  }
  return flag;
}

bool8 HiJumpKickMoveAction(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5)
{
  u8 moveType;
  u32 movePower;
  u32 moveCritChance;
  bool8 flag;
  s32 local_30 [4];
  u8 auStack_20;

  flag = FALSE;
  if (param_5 == 0) {
    flag = HandleDamagingMove(pokemon,target,move,IntToF248_2(2),param_4) != 0 ? TRUE : FALSE;
  }
  if (!flag) {
    moveType = GetMoveTypeForMonster(pokemon,move);
    movePower = GetMovePower(pokemon,move);
    moveCritChance = GetMoveCritChance(move);
    CalcDamage(pokemon,target,moveType,movePower,moveCritChance,local_30,0x200,move->id,0);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],GetEntInfo(pokemon),0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC7C8);
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
    if(HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4))
    {
        flag = TRUE;
        if(sub_805727C(pokemon, target, gTriAttackSecondaryChance))
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

bool8 TrickMoveAction(Entity * pokemon,Entity * target, Move *move, u32 param_4)
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

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
    if (AbilityIsActive(target, ABILITY_STICKY_HOLD)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCCE4);
        return FALSE;
    }
    else if (HasHeldItem(target, ITEM_ALERT_SPECS)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD578);
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
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC7AC); // The item trade failed
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
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC790); // Traded items
            return TRUE;
        }
    }
}

bool8 TripleKickMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    gUnknown_202F210++;
    flag = HandleDamagingMove(pokemon, target, move, IntToF248_2(gUnknown_202F210), param_4) ? TRUE : FALSE;
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

bool8 MudSlapMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, FALSE);
    }
  }
  return flag;
}

bool8 ThiefMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    return ThiefAction(pokemon, target, move, param_4);
}

bool8 AmnesiaMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A50, 2);
    return TRUE;
}

bool8 GrowlMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, TRUE);
    return TRUE;
}

bool8 SurfMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;
  s32 modifierInt;
  s24_8 modifier;

  flag = FALSE;
  if (GetEntInfo(target)->bideClassStatus.status == STATUS_DIVING) {
      modifierInt = IntToF248_2(2).raw;
  }
  else {
      modifierInt = IntToF248_2(1).raw;
  }
  modifier.raw = modifierInt;
  if(HandleDamagingMove(pokemon,target,move,modifier,param_4) != 0)
    flag = TRUE;
  return flag;
}

bool8 RolePlayMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  EntityInfo * entityInfo;
  EntityInfo * targetEntityInfo;

  entityInfo = GetEntInfo(pokemon);
  targetEntityInfo = GetEntInfo(target);
  if (AbilityIsActive(target, ABILITY_WONDER_GUARD)) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC854);
    return FALSE;
  }
  else
  {
    entityInfo->abilities[0] = targetEntityInfo->abilities[0];
    entityInfo->abilities[1] = targetEntityInfo->abilities[1];
    gDungeon->unkC = 1;
    SetExpMultplier(entityInfo);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC81C);
    EndAbilityImmuneStatus(pokemon, pokemon);
    return TRUE;
  }
}

bool8 SunnyDayMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  gDungeon->weather.unkE267[WEATHER_SUNNY] = gMoveWeatherDuration;
  if (sub_807EAA0(1,0) == 0) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCF7C);
  }
  return TRUE;
}

bool8 LeerMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, TRUE);
    return TRUE;
}

bool8 WishMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    WishStatusTarget(pokemon, target);
    return TRUE;
}

bool8 FakeOutMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gFakeOutSecondaryChance))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_805A450(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC730);
  return FALSE;
}

bool8 PayDayMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool32 flag;
  Item item;
  DungeonPos pos;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
    flag = TRUE;
    if (RollSecondaryEffect(pokemon, 0) != 0) {
      if (!EntityIsValid(target)) {
        pos.x = 0;
        pos.y = 0;
        CreateItemWithStickyChance(&item,ITEM_POKE,2);
        sub_805A7D4(pokemon,target,&item,&pos);
      }
    }
  }
  return flag;
}

bool8 AssistMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC74C);
  return FALSE;
}

bool8 RestMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    NappingStatusTarget(pokemon, target, CalculateStatusTurns(target, gNappingTurnRange, FALSE));
    return TRUE;
}

bool8 IngrainMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    IngrainedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SwallowMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  u8 *stockpileStage;

  stockpileStage = &GetEntInfo(target)->stockpileStage;
  if (*stockpileStage != 0) {
    HealTargetHP(pokemon,target,gStockpileHealHpValues[*stockpileStage],0,TRUE);
    *stockpileStage = 0;
  }
  else {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC770);
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

    flag = HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) ? TRUE : FALSE;
    return flag;
}

bool8 SuperpowerMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  u32 stat;
  bool32 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,pokemon,0) != 0) {
      stat = gUnknown_8106A4C;
      LowerAttackStageTarget(pokemon,pokemon,stat,1,0,FALSE);
      LowerDefenseStageTarget(pokemon,pokemon,stat,1,0,FALSE);
    }
  }
  return flag;
}

bool8 SteelWingMoveAction(Entity *pokemon, Entity *target, Move *move, u32 stat, u32 param_5)
{
  EntityInfo *entityInfo;
  bool32 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_5) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,pokemon,gSteelWingSecondaryChance) != 0) {
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
    HandleDamagingMove(pokemon,target,move,IntToF248_2(*stockpileStage),param_4);
    *stockpileStage = 0;
  }
  else {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCA3C);
  }
  return TRUE;
}

bool8 DynamicPunchMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
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
    DungeonPos pos;

    entityInfo = GetEntInfo(pokemon);
    targetEntityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], pokemon, 0);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
    if (AbilityIsActive(target, ABILITY_STICKY_HOLD))
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCCE8);
        return FALSE;
    }
    else if (HasHeldItem(target, ITEM_ALERT_SPECS))
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD57C);
        return FALSE;
    }
    else
    {
        heldItem = targetEntityInfo->heldItem;
        if (!ItemExists(&heldItem))
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD18C);
            return FALSE;
        }
        else
        {
            ZeroOutItem(&targetEntityInfo->heldItem);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD170); // $m1's item was swatted down!
            pos.x = gAdjacentTileOffsets[entityInfo->action.direction].x;
            pos.y = gAdjacentTileOffsets[entityInfo->action.direction].y;
            sub_805A7D4(pokemon,target,&heldItem,&pos);
            if (sub_80706A4(target, &target->pos) != 0)
            {
                WarpTarget(pokemon, target, 0, NULL);
            }
            return TRUE;
        }
    }
}

static void sub_805A7D4(Entity * pokemon, Entity * target, Item *item,
                 DungeonPos *pos)
{
  Entity stackEntity;

  stackEntity.type = ENTITY_ITEM;
  stackEntity.unk24 = 0;
  stackEntity.isVisible = TRUE;
  stackEntity.unk22 = 0;
  stackEntity.axObj.info.item = item;
  stackEntity.pos.x = target->pos.x + pos->x;
  stackEntity.pos.y = target->pos.y + pos->y;
  SetEntityPixelPos(&stackEntity,(target->pos.x * 0x18 + 4) * 0x100,
              (target->pos.y * 0x18 + 4) * 0x100);
  stackEntity.spawnGenID = 0;
  SubstitutePlaceholderStringTags(gFormatBuffer_Items[0],&stackEntity,0);
  sub_804652C(pokemon,&stackEntity,item,1,0);
}

bool8 SplashMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
  int x;
  int y;
  int counter;
  DungeonPos *r9;
  DungeonPos pos1;
  Move stackMove;
  PixelPos pos2;
  Tile *tile;
  Entity *entity;
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
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEBDC);
    return FALSE;
  }

  pos2.x = (X_POS_TO_PIXELPOS(pos1.x) - target->pixelPos.x) / 0xc;
  pos2.y = (Y_POS_TO_PIXELPOS(pos1.y) - target->pixelPos.y) / 0xc;

  if (((check = sub_803F428(&target->pos), r9 = &target->pos, check)) || (sub_803F428(&pos1))) {
    for(counter = 0; counter < 0xC; counter++)
    {
      IncreaseEntityPixelPos(target,pos2.x,pos2.y);
      DungeonRunFrameActions(0x2c);
    }
  }
  tile = GetTileMut(pos1.x,pos1.y);
  entity = tile->monster;
  if (entity != NULL) {
    if (GetEntityType(entity) == ENTITY_MONSTER) {
      InitPokemonMove(&stackMove,MOVE_REGULAR_ATTACK);
      if (sub_80571F0(entity,&stackMove) == 0) {
        sub_806F370(pokemon,entity,gSplashDmgValue,0,0,TYPE_NONE,sub_8057600(move, param_4),0,1,0);
      }
      if ((sub_8044B28() == 0) && (EntityIsValid(pokemon))) {
        sub_806F370(pokemon,pokemon,gSplashDmgValue,0,0,0,0x1fe,0,0,0);
        if ((sub_8044B28() == 0) && (EntityIsValid(pokemon))) goto _0805A9FE;
      }
    }
    else {
_0805A9FE:
      if (EntityIsValid(target)) {
        if ((sub_803F428(r9)) || (sub_803F428(&pos1))) {
          for(counter = 0; counter < 0xC; counter++)
          {
            IncreaseEntityPixelPos(target, -pos2.x,-pos2.y);
            DungeonRunFrameActions(0x2c);
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
    if (EntityIsValid(target)) {
#ifndef NOMATCHING
      register DungeonPos *pos asm("r1");
#else
      DungeonPos *pos;
#endif
      sub_804535C(target, NULL);
      pos = r9;
      if (sub_80706A4(target, pos)) {
        WarpTarget(pokemon,target,0,0);
      }
      if (GetEntInfo(target)->isTeamLeader) {
        sub_804AC20(r9);
        sub_807EC28(FALSE);
      }
      sub_806A5B8(target);
      sub_8075900(target,gDungeon->forceMonsterHouse);
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
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC5CC);
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
  if ( HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gSecretPowerSecondaryEffectChance) != 0) {
        switch(gSecretPowerTable[gDungeon->tileset]) {
            case 0:
                PoisonedStatusTarget(pokemon,target,FALSE);
                break;
            case 1:
                SleepStatusTarget(pokemon,target,CalculateStatusTurns(target,gSleepTurnRange,TRUE),FALSE);
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
    if ( HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gDizzyPunchSecondaryChance) != 0) {
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

bool8 ObserverOrbAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    PausedStatusTarget(pokemon, target, 1, CalculateStatusTurns(target, gObserverOrbPausedTurnRange, TRUE), TRUE);
    return TRUE;
}

bool8 FeatherDanceMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2, 1, TRUE);
    return TRUE;
}

bool32 BeatUpMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
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
        if (EntityIsValid(targetEntity)
             && pokemon != targetEntity
             && GetTreatmentBetweenMonsters(pokemon,targetEntity,FALSE,FALSE) == TREATMENT_TREAT_AS_ALLY)
        {
            EntityInfo *targetInfo = GetEntInfo(targetEntity);
            if (targetInfo->monsterBehavior != BEHAVIOR_RESCUE_TARGET && !IsExperienceLocked(targetInfo->joinedAt.id)) {
                WarpTarget(pokemon,targetEntity,2,&target->pos);
                flag = TRUE;
                SetExpMultplier(info);
            }
        }
    }

    if (!flag) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_81004EC);
    }
    return flag;
}

bool8 BlastBurnMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
  bool8 flag;

  SendThawedMessage(pokemon, target);
  flag = HandleDamagingMove(pokemon,target,move,IntToF248_2(2),param_4) != 0 ? TRUE : FALSE;
  return flag;
}

bool8 CrushClawMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if ( HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gCrushClawSecondaryChance) != 0) {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, FALSE);
        }
    }
    return flag;
}

bool8 BlazeKickMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    bool8 flag;

    flag = FALSE;
    SendThawedMessage(pokemon, target);
    if ( HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gBlazeKickSecondaryChance) != 0) {
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

bool8 EruptionMoveAction(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    EntityInfo *entityInfo;
    s32 maxHp;
    s32 index;
    bool8 flag;
    SendThawedMessage(pokemon, target);

    entityInfo = GetEntInfo(pokemon);
    maxHp = entityInfo->maxHPStat;
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

    flag = HandleDamagingMove(pokemon,target,move,gEruptionModifiers[index],param_4) ? TRUE : FALSE;
    return flag;
}

bool8 GlareMoveAction(Entity * pokemon,Entity * target,Move *move)
{
    ParalyzeStatusTarget(pokemon,target, TRUE);
    return TRUE;
}

bool8 TransformMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  if (IsBossFight()) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEFF4);
    return FALSE;
  }
  else {
    move->PP = 0;
    TransformStatusTarget(pokemon,target);
    return TRUE;
  }
}

bool8 PoisonTailMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gPoisonTailSecondaryChance) != 0) {
            PoisonedStatusTarget(pokemon,target,FALSE);
        }
    }
    return flag;
}

bool8 RoarMoveAction(Entity * pokemon, Entity * target)
{
    BlowAwayTarget(pokemon, target, GetEntInfo(pokemon)->action.direction);
    return TRUE;
}

bool8 HandleColorChange(Entity * pokemon, Entity * target)
{
    u8 newType;
    const char *typeString;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(target);
    newType = gDungeonCamouflageTypes[gDungeon->tileset];
    if (AbilityIsActive(target, ABILITY_FORECAST)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrForecastPreventsTypeSwitchMessage);
        return FALSE;
    }
    else {
        entityInfo->types[0] = newType;
        entityInfo->types[1] = TYPE_NONE;
        entityInfo->isColorChanged = TRUE;
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
        typeString = GetUnformattedTypeString(newType);
        strcpy(gFormatBuffer_Items[0], typeString);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FEB08);
        return TRUE;
    }
}

bool8 TailGlowMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    RaiseAttackStageTarget(pokemon,target,gUnknown_8106A50, 2);
    return TRUE;
}

bool8 sub_805B17C(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 uVar4;
    bool8 flag;

    flag = FALSE;
    if (move->id == MOVE_FIRE_SPIN) {
        SendThawedMessage(pokemon,target);
        uVar4 = 0x13c;
    }
    else {
        uVar4 = 0x75;
        if ((move->id != MOVE_CLAMP) && (uVar4 = 0xf1, move->id == MOVE_BIND)) {
            uVar4 = 0x7e;
        }
    }
    if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gMovesConstrictionChance) != 0) {
            SqueezedStatusTarget(pokemon,target,uVar4,0);
        }
    }
    return flag;
}

bool8 PerishSongMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    PerishSongTarget(pokemon, target);
    return TRUE;
}

bool8 WrapMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    WrapTarget(pokemon, target);
    return TRUE;
}

bool8 SpikesMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    bool8 trapLaid;
    u8 uVar2;
    bool8 isNotTeamMember;

    trapLaid = FALSE;
    isNotTeamMember = GetEntInfo(pokemon)->isNotTeamMember;
    uVar2 = 1;

    if (isNotTeamMember) {
        uVar2 = 2;
    }
    if (LayTrap(&pokemon->pos,TRAP_SPIKE_TRAP,uVar2) != 0) {
        trapLaid = TRUE;
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC5A8); // A trap can't be laid here!
    }
    sub_8049ED4();
    return trapLaid;
}

const s32 gUnknown_8106A8C[] = {6, 12, 18, 20, 24, 30, 30};

bool8 MagnitudeMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 r3;
    bool8 r6;
    s32 magnitudeDmgVal;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(target);
    r3 = gUnknown_202F224;
    r6 = FALSE;

    gDungeon->unk181e8.unk18200 = gUnknown_8106A8C[r3];
    gDungeon->unk181e8.unk18204 = 0;
    magnitudeDmgVal = gMagnitudeDmgValues[r3];
    if (entityInfo->bideClassStatus.status == STATUS_DIGGING) {
        magnitudeDmgVal *= 2;
    }
    r6 = sub_8055864(pokemon,target,move,magnitudeDmgVal,param_4) ? TRUE : FALSE;
    return r6;
}

bool8 MagicCoatMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    MagicCoatStatusTarget(pokemon, target);
    return TRUE;
}

