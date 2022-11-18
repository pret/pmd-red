#include "global.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "charge_move.h"
#include "dungeon_global_data.h"
#include "dungeon_entity.h"
#include "dungeon_util.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "map.h"
#include "moves.h"
#include "status.h"
#include "status_checks_1.h"
#include "tile_types.h"
#include "weather.h"

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[];

extern s16 gUnknown_80F4DB6;
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
extern u32 gUnknown_202F21C;
extern bool8 gUnknown_202F220;
extern u32 gUnknown_8106A54[];

struct unkStruct_80928C0
{
    u32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void sub_80928C0(u8 *buffer, struct PokemonMove *move, struct unkStruct_80928C0 *param_3);

extern void SqueezedStatusTarget(struct DungeonEntity *, struct DungeonEntity *, u32, u32);
extern u8 sub_807EAA0(u32, u32);
extern void sub_80522F4(struct DungeonEntity *r1, struct DungeonEntity *r2, const char[]);
extern s32 sub_80556BC(struct DungeonEntity *, struct DungeonEntity *, u8, struct PokemonMove *, u32, u32);
extern u8 sub_805727C(struct DungeonEntity *, struct DungeonEntity *, s16);
extern void sub_8078968(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void RaiseAttackStageTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32, u32);
extern void LowerDefenseStageTarget(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32, u32);
extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern u32 sub_8055640(struct DungeonEntity *, struct DungeonEntity *, struct PokemonMove *, u32, u32);
extern void NightmareStatusTarget(struct DungeonEntity *, struct DungeonEntity *, s32);
extern void YawnedStatusTarget(struct DungeonEntity *, struct DungeonEntity *, s32);
extern void sub_8075C58(struct DungeonEntity *, struct DungeonEntity *, s32, s32);
u8 sub_8057620(u32 param_1);
extern s16 sub_8094828(u16, u8);

extern s16 gUnknown_80F4DB4;
extern u32 gUnknown_8106A4C;

bool8 sub_805755C(struct DungeonEntity* pokemon, u16 moveID)
{
    if ((moveID == MOVE_SOLARBEAM) && (GetWeather(pokemon) == WEATHER_SUNNY)) {
        return FALSE;
    }
    else {
        return DoesMoveCharge(moveID);
    }
}

void sub_8057588(struct DungeonEntity * pokemon, u8 param_2)
{
    struct PokemonMove *move;
    s32 index;
    s32 PPtoRemove;
    s32 PPCounter;
    struct DungeonEntityData *entityData;

    if (EntityExists(pokemon)) {
        entityData = pokemon->entityData;
        for(index = 0; index < MAX_MON_MOVES; index++)
        {
            move = &entityData->moves[index];
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

s16 sub_8057600(struct PokemonMove *param_1, s32 param_2)
{
    return sub_8094828(param_1->moveID, sub_8057620(param_2));
}

u8 sub_8057620(u32 param_1)
{
    if(param_1 == 0)
        return 0;
    else
        return param_1;
}

bool8 sub_8057634(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4)
{
    bool8 uVar3;

    uVar3 = FALSE;
    if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
        uVar3 = TRUE;
        if (sub_805727C(pokemon, target, gUnknown_80F4DB4) != 0) {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, 0);
        }
    }
    return uVar3;
}

bool8 sub_805768C(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4)
{
    bool8 iVar1;

    iVar1 = FALSE;  
    gUnknown_202F21C++;

    if (sub_8055640(pokemon, target, move, gUnknown_8106A54[gUnknown_202F21C], param_4) == 0)
        gUnknown_202F220 = 1;
    else
        iVar1 = TRUE;
    return iVar1;
}

bool8 sub_80576D0(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
    YawnedStatusTarget(pokemon, target, CalculateStatusTurns(target,gUnknown_80F4F28,TRUE) + 1);
    return TRUE;
}

bool8 sub_80576F8(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
    sub_8075C58(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4E74, TRUE), 1);
    return TRUE;
}

bool8 sub_8057720(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
    NightmareStatusTarget(pokemon, target, CalculateStatusTurns(target,gUnknown_80F4E78,TRUE));
    return TRUE;
}

bool8 sub_8057748(struct DungeonEntity * pokemon,struct DungeonEntity * target)
{
    HealTargetHP(pokemon, target, gUnknown_80F502A[GetWeather(pokemon)], 0, 1);
    return TRUE;
}

bool8 sub_805777C(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    VitalThrowStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_8057788(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    struct MapTile *tile;
    bool8 uVar3;

    uVar3 = FALSE;
    tile = GetMapTileForDungeonEntity_2(pokemon);
    if ((!IsTileGround(tile)) || ((tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) != 1)) {
        sub_80522F4(pokemon,target,*gUnknown_80FD14C); // It can only be used on land!
    }
    else {
        if (MoveMatchesChargingStatus(pokemon,move)) {
            sub_8055640(pokemon,target,move,gUnknown_80F4F68,param_4);
            sub_8079764(pokemon);
        }
        else {
            sub_8079618(pokemon,pokemon,10,move,*gUnknown_80FAD4C); // $m0 burrowed underground!
        }
        uVar3 = TRUE;
    }
    return uVar3;
}

bool32 sub_8057824(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    // Lower evasion?
  sub_80775DC(pokemon,target,gUnknown_8106A50,1);
  return TRUE;
}

bool32 sub_805783C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    // Lower attack?
  sub_80772C0(pokemon,target,gUnknown_8106A4C,0x80,1);
  return TRUE;
}

bool32 sub_805785C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  gDungeonGlobalData->unkE26B = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    sub_80522F4(pokemon,target,*gUnknown_80FCF74);
  }
  return TRUE;
}

bool32 sub_80578A4(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  gDungeonGlobalData->weatherTurnsLeft = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    sub_80522F4(pokemon,target,*gUnknown_80FCF80);
  }
  return TRUE;
}

bool32 sub_80578EC(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8079F20(r0, r1, 1, 0);
    return TRUE;
}

bool32 sub_80578FC(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove * move, u32 param_4)
{
  bool32 uVar3;

  uVar3 = FALSE;
  if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
    uVar3 = TRUE;
    if (sub_805727C(pokemon,target, gUnknown_80F4DB6) != 0) {
      sub_80779F0(pokemon, target, 1, 0);
    }
  }
  return uVar3;
}

bool32 sub_8057948(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8078968(pokemon, target);
    return TRUE;
}

bool32 sub_8057954(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move)
{
  // {ARG_POKEMON_0} is enraged
  sub_8079618(pokemon,target,0xc,move,gUnknown_80FAC88);
  return TRUE;
}

bool32 sub_8057974(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, u32 param_4)
{
  s32 newHP;
  bool8 local_24;

  newHP = target->entityData->HP / 2;
  local_24 = FALSE;
  if (newHP != 0) {
    sub_806F370(pokemon,target,newHP,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = local_24 == 0;
  }
  else
  {
    // The target's HP can't be halved anymore
    sub_80522F4(pokemon,target,*gUnknown_80FD018);
  }
  return local_24;
}

bool8 PainSplitMoveAction(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  s32 newHP;
  struct DungeonEntityData *iVar2;
  struct DungeonEntityData *iVar3;
  struct DungeonEntityData *iVar4;
  struct DungeonEntityData *iVar5;

  // Need copies for some reason to match..
  iVar3 = (pokemon->entityData);
  iVar4 = iVar3;
  iVar2 = (target->entityData);
  iVar5 = iVar2;

  newHP = ((iVar3->HP + iVar2->HP) / 2);
  iVar3->HP = newHP;
  iVar5->HP = newHP;
  if (iVar3->HP > iVar3->maxHP) {
    iVar3->HP = iVar3->maxHP;
  }
  if (iVar5->HP > iVar5->maxHP) {
    iVar5->HP = iVar5->maxHP;
  }
  SetMessageArgument(gAvailablePokemonNames,pokemon,0);
  SetMessageArgument(gAvailablePokemonNames + 0x50,target,0);
  if (iVar4->unkFB == 0) {
    iVar4->unkFB = 1;
  }
  // $m0 and $m1 shared their HP
  sub_80522F4(pokemon,target,*gUnknown_80FC7EC);
  return TRUE;
}

bool8 TormentMoveAction(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct PokemonMove *movePtr;
  s32 iVar4;
  struct PokemonMove struggleMove;
  struct DungeonEntityData *entityData;
  bool8 isTormented;
  
  entityData = target->entityData;
  isTormented = FALSE;

  for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
  {
    movePtr = &entityData->moves[iVar4];
    if ((movePtr->moveFlags & MOVE_FLAG_EXISTS) != 0) {
      if ((movePtr->moveFlags & MOVE_FLAG_DISABLED) == 0) {
        if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) != 0) {
          sub_80928C0(gUnknown_202DE58,movePtr,0);
          // $i0 was tormented
          sub_80522F4(pokemon,target,*gUnknown_80FCFBC);
          movePtr->moveFlags |= MOVE_FLAG_DISABLED;
          isTormented = TRUE;
        }
      }
      else if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) == 0) {
        movePtr->moveFlags &= ~(MOVE_FLAG_DISABLED);
      }
    }
  };

  if ((entityData->struggleMoveFlags & MOVE_FLAG_DISABLED) == 0) {
    if ((entityData->struggleMoveFlags & MOVE_FLAG_LAST_USED) != 0) {
      InitPokemonMove(&struggleMove, MOVE_STRUGGLE);
      entityData->struggleMoveFlags |= MOVE_FLAG_DISABLED;
      isTormented = TRUE;
      sub_80928C0(gUnknown_202DE58,&struggleMove,0);
      // $i0 was tormented
      sub_80522F4(pokemon,target,*gUnknown_80FCFBC);
    }
  }
  else if ((entityData->struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) {
    entityData->struggleMoveFlags &= ~(MOVE_FLAG_DISABLED);
  }
  if (isTormented)
  {
    if(entityData->chargingStatus == CHARGING_STATUS_BIDE) {
        entityData->chargingStatus = CHARGING_STATUS_NONE;
    }
  }
  else
  {
    // The target couldn't be tormented
    sub_80522F4(pokemon,target,*gUnknown_80FCFE4);
  }
  return isTormented;
}

bool8 sub_8057BB4(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_80779F0(pokemon, target, 1, 1);
    return TRUE;
}

bool8 sub_8057BC4(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    ConfuseStatusTarget(pokemon, target, 1);
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 sub_8057BEC(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove * move, u32 param_4)
{
  bool8 uVar3;

  uVar3 = FALSE;
  if (IsSleeping(pokemon)) {
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
      uVar3 = TRUE;
      if (sub_805727C(pokemon,target,gUnknown_80F4E0A) != 0) {
        CringeStatusTarget(pokemon,target,0);
      }
    }
  }
  else {
    sub_80522F4(pokemon,target,*gUnknown_80FC734);
  }
  return uVar3;
}

bool8 sub_8057C68(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8077434(pokemon, target, gUnknown_8106A4C, 0x40, 1);
    return TRUE;
}

bool8 sub_8057C88(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove * move, u32 param_4)
{
  u8 uVar3;

  uVar3 = FALSE;
  if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
    uVar3 = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4DF6) != 0) {
      CringeStatusTarget(pokemon,target,0);
    }
  }
  return uVar3;
}

s32 sub_8057CD0(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove * move, u32 param_4)
{
  u32 uVar1;
  s32 iVar2;
  
  uVar1 = GetWeather(pokemon);
  iVar2 = sub_80556BC(pokemon,target,gUnknown_80F51E4[uVar1],move,
                      gUnknown_80F51EC[uVar1],param_4);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

bool8 sub_8057D20(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove * move, u32 param_4)
{
  u32 uVar3;
  bool8 uVar4;
  u8 chargeStatus;

  uVar4 = FALSE;
  chargeStatus = target->entityData->chargingStatus;
  uVar3 = 0x100;
  if (chargeStatus == CHARGING_STATUS_DIVE) {
    uVar3 = 0x200;
  }
  if (sub_8055640(pokemon,target,move,uVar3,param_4) != 0) {
    uVar4 = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4E08) != 0) {
      SqueezedStatusTarget(pokemon,target,0x3b,0);
    }
  }
  return uVar4;
}

bool8 sub_8057D7C(struct DungeonEntity * param_1, struct DungeonEntity * param_2)
{
  LowerDefenseStageTarget(param_1, param_2, gUnknown_8106A50, 2, 1, 1);
  return TRUE;
}
