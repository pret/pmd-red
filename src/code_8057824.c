#include "global.h"
#include "dungeon_global_data.h"
#include "dungeon_entity.h"
#include "constants/move.h"

extern u32 gUnknown_80FCF74;
extern u32 gUnknown_80FCF80;
extern u16 gUnknown_80F4F42;

extern u32 gUnknown_8106A50;
extern u32 gUnknown_8106A4C;
extern s16 gUnknown_80F4DB6;
extern u32 gUnknown_80FAC88;

extern void sub_80775DC(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32);
extern void sub_80772C0(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u32);
extern u8 sub_807EAA0(u32, u32);
extern void sub_80522F4(struct DungeonEntity *r1, struct DungeonEntity *r2, u32);
extern void sub_8079F20(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32);

extern u8 sub_805727C(struct DungeonEntity *, struct DungeonEntity *, s16);
extern u32 sub_8055640(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32);
extern void sub_80779F0(struct DungeonEntity *, struct DungeonEntity *, u32, u32);
extern void sub_8078968(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void sub_8079618(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u32);

extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);



extern u32 gUnknown_80FD018;
extern s16 sub_8057600(void*, u32);
extern u32 GetMoveType(void*);

bool32 sub_8057824(struct DungeonEntity *param_1, struct DungeonEntity *param_2)
{
    // Lower evasion?
  sub_80775DC(param_1,param_2,gUnknown_8106A50,1);
  return TRUE;
}

bool32 sub_805783C(struct DungeonEntity *param_1, struct DungeonEntity *param_2)
{
    // Lower attack?
  sub_80772C0(param_1,param_2,gUnknown_8106A4C,0x80,1);
  return TRUE;
}

bool32 sub_805785C(struct DungeonEntity *param_1, struct DungeonEntity *param_2)
{
  gDungeonGlobalData->unkE26B = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == '\0') {
    // The weather remains unchanged
    sub_80522F4(param_1,param_2,gUnknown_80FCF74);
  }
  return TRUE;
}

bool32 sub_80578A4(struct DungeonEntity *param_1, struct DungeonEntity *param_2)
{
  gDungeonGlobalData->weatherTurnsLeft = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == '\0') {
    // The weather remains unchanged
    sub_80522F4(param_1,param_2,gUnknown_80FCF80);
  }
  return TRUE;
}

bool32 sub_80578EC(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8079F20(r0, r1, 1, 0);
    return TRUE;
}

bool32 sub_80578FC(struct DungeonEntity *param_1, struct DungeonEntity *param_2, u32 param_3, u32 param_4)
{
  bool32 uVar3;

  uVar3 = 0;
  if (sub_8055640(param_1, param_2, param_3, 0x80 << 1, param_4) != 0) {
    uVar3 = TRUE;
    if (sub_805727C(param_1,param_2, gUnknown_80F4DB6) != '\0') {
      sub_80779F0(param_1, param_2, 1, 0);
    }
  }
  return uVar3;
}

bool32 sub_8057948(struct DungeonEntity *param_1, struct DungeonEntity *param_2)
{
    sub_8078968(param_1, param_2);
    return TRUE;
}

bool32 sub_8057954(struct DungeonEntity *param_1, struct DungeonEntity *param_2, u32 param_3)
{
  // {ARG_POKEMON_0} is enraged
  sub_8079618(param_1,param_2,0xc,param_3,gUnknown_80FAC88);
  return TRUE;
}

bool32 sub_8057974(struct DungeonEntity *param_1, struct DungeonEntity *param_2, struct PokemonMove *param_3, u32 param_4)
{
  s32 newHP;
  u8 local_24;

  newHP = param_2->entityData->HP / 2;
  local_24 = 0;
  if (newHP != 0) {
    sub_806F370(param_1,param_2,newHP,1,&local_24,GetMoveType(param_3),sub_8057600(param_3,param_4),0,1,0);
    local_24 = local_24 == 0;
  }
  else
  {
    // The target's HP can't be halved anymore
    sub_80522F4(param_1,param_2,gUnknown_80FD018);
  }
  return local_24;
}
