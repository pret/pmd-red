#include "global.h"
#include "constants/status.h"
#include "dungeon_global_data.h"
#include "dungeon_entity.h"
#include "code_8077274_1.h"
#include "moves.h"
#include "status_checks_1.h"
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

struct unkStruct_80928C0
{
    u32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void sub_80928C0(u8 *buffer, struct PokemonMove *move, struct unkStruct_80928C0 *param_3);

extern void sub_80775DC(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32);
extern void sub_80768DC(struct DungeonEntity *, struct DungeonEntity *, u32, u32);
extern void sub_80772C0(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u32);
extern u8 sub_807EAA0(u32, u32);
extern void sub_80522F4(struct DungeonEntity *r1, struct DungeonEntity *r2, const char[]);
extern void sub_8077434(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 , u32, u32);
extern s32 sub_80556BC(struct DungeonEntity *, struct DungeonEntity *, u8, u32, u32, u32);
extern u8 sub_805727C(struct DungeonEntity *, struct DungeonEntity *, s16);
extern u32 sub_8055640(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32);
extern void sub_80779F0(struct DungeonEntity *, struct DungeonEntity *, u32, u32);
extern void sub_8078968(struct DungeonEntity *r0, struct DungeonEntity *r1);

extern void sub_8077AE4(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32);
extern void sub_8077084(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32, u32);
extern u8 sub_80776C0(struct DungeonEntity *, struct DungeonEntity *, u8);

extern void sub_8076F80(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32, u32);
extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);


extern s16 sub_8057600(void*, u32);

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

bool32 sub_80578FC(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32 param_3, u32 param_4)
{
  bool32 uVar3;

  uVar3 = FALSE;
  if (sub_8055640(pokemon, target, param_3, 0x100, param_4) != 0) {
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

bool32 sub_8057974(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *param_3, u32 param_4)
{
  s32 newHP;
  bool8 local_24;

  newHP = target->entityData->HP / 2;
  local_24 = FALSE;
  if (newHP != 0) {
    sub_806F370(pokemon,target,newHP,1,&local_24,GetMoveType(param_3),sub_8057600(param_3,param_4),0,1,0);
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
    sub_8077AE4(pokemon, target, 1);
    sub_8077084(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 sub_8057BEC(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32 param_3, u32 param_4)
{
  bool8 uVar3;

  uVar3 = FALSE;
  if (IsSleeping(pokemon)) {
    if (sub_8055640(pokemon,target,param_3,0x100,param_4) != 0) {
      uVar3 = TRUE;
      if (sub_805727C(pokemon,target,gUnknown_80F4E0A) != 0) {
        sub_80776C0(pokemon,target,0);
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

bool8 sub_8057C88(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32 param_3, u32 param_4)
{
  u8 uVar3;

  uVar3 = FALSE;
  if (sub_8055640(pokemon, target, param_3, 0x100, param_4) != 0) {
    uVar3 = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4DF6) != 0) {
      sub_80776C0(pokemon,target,0);
    }
  }
  return uVar3;
}

s32 sub_8057CD0(struct DungeonEntity * pokemon, struct DungeonEntity * target, u32 param_3, u32 param_4)
{
  u32 uVar1;
  s32 iVar2;
  
  uVar1 = GetWeather(pokemon);
  iVar2 = sub_80556BC(pokemon,target,gUnknown_80F51E4[uVar1],param_3,
                      gUnknown_80F51EC[uVar1],param_4);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

bool8 sub_8057D20(struct DungeonEntity * pokemon, struct DungeonEntity * target, u32 param_3, u32 param_4)
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
  if (sub_8055640(pokemon,target,param_3,uVar3,param_4) != 0) {
    uVar4 = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4E08) != 0) {
      sub_80768DC(pokemon,target,0x3b,0);
    }
  }
  return uVar4;
}

bool8 sub_8057D7C(struct DungeonEntity * param_1, struct DungeonEntity * param_2)
{
  sub_8076F80(param_1, param_2, gUnknown_8106A50, 2, 1, 1);
  return TRUE;
}
