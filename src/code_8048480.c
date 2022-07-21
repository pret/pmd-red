#include "global.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "number_util.h"
#include "moves.h"

extern u8 *gUnknown_80F89F4[];
extern u8 gAvailablePokemonNames[0x58];
extern u8 *gUnknown_80FB580[];
extern s16 gUnknown_80F4FB6;
extern s16 gUnknown_80F4FB8;
extern s16 gUnknown_80F4FBA;
extern s16 gUnknown_80F4FBC;
extern s16 gUnknown_80F4FBE;
extern s16 gUnknown_80F4F46; // 0xC
extern s16 gUnknown_80F4FAA; // 0x1E
extern s16 gUnknown_80F4FA8; // 0xF
extern s16 gUnknown_80F4FA4; // 0x14 
extern s16 gUnknown_80F4FA6; // 0x2D


extern u8 *gUnknown_80FEAE8[];
extern u8 *gUnknown_80FDBA0[];
extern u8 *gUnknown_80FE434[];
extern u8 *gUnknown_80FE40C[];
extern u8 *gUnknown_80FE454[];
extern u8 *gPtrSelfHealPreventedHungerMessage[];
extern u8 *gUnknown_80F9740[];
extern u8 *gUnknown_80F9760[];

extern void sub_807D148(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32 r2, u32 r3);
extern void sub_8075FCC(struct DungeonEntity *pokemon, struct DungeonEntity *r1);
extern void sub_8077AE4(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32 r2);
extern void sub_8072008(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32 r2, u8 r3, u32);
extern void sub_8076D10(struct DungeonEntity *pokemon, struct DungeonEntity *r1);
extern void LevelDownTarget(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32 r2);
extern void sub_8078B5C(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32);
extern void SetMessageArgument(u8 *buffer, struct DungeonEntity *r1, u32);
extern void sub_807A290(struct DungeonEntity *pokemon, struct DungeonEntity *r1);
extern void sub_80522F4(struct DungeonEntity *pokemon, struct DungeonEntity *r1, const char[]);
extern void RestoreVisionTarget(struct DungeonEntity *pokemon, struct DungeonEntity *r1);
extern void sub_8077910(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32, u32);
extern void sub_80791D8(struct DungeonEntity *pokemon, struct DungeonEntity *r1);
extern void BlindTarget(struct DungeonEntity *pokemon, struct DungeonEntity *r1);
extern void HealTargetHP(struct DungeonEntity *pokemon, struct DungeonEntity *r1, s16, s16, u32);
extern void sub_80792F8(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32);
extern void sub_8079F20(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32, u8);
extern void sub_806F370(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8078A58(struct DungeonEntity *, struct DungeonEntity *, s16, u32);
extern void SendImmobilizeEndMessage(struct DungeonEntity*, struct DungeonEntity*);
extern s32 sub_8042520(struct DungeonEntity *);
struct DungeonEntity *sub_80696FC(struct DungeonEntity *);
extern void sub_80943A0(void*, s32);
extern void sub_803E708(u32 r0, u32 r1);

void sub_8048340(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32 r2)
{
    sub_806F370(pokemon, target, r2, 1, 0, 0, 528, 0, 0, 0);
}

void sub_8048364(struct DungeonEntity *pokemon, struct DungeonEntity *target, u8 r2)
{
    sub_8079F20(pokemon, target, 1, r2);
}

void sub_8048374(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FB6, gUnknown_80F4FB8, 1);
}

void sub_804839C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FBA, gUnknown_80F4FBC, 1);
}

void sub_80483C4(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_80792F8(pokemon, target, 999);
}

void sub_80483D4(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    HealTargetHP(pokemon, target, 0, gUnknown_80F4FBE, 1);
}

void sub_80483F4(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    BlindTarget(pokemon, target);
}

void sub_8048400(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_80791D8(pokemon, target);
}

void sub_804840C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8077910(pokemon, target, 0, 1);
}

void sub_804841C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    RestoreVisionTarget(pokemon, target);
}

void sub_8048428(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    if(target->entityData->nonVolatileStatus == NON_VOLATILE_STATUS_PARALYZED)
        sub_807A290(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_8048450(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    if((u8)(target->entityData->nonVolatileStatus - 2) <= 1)
        sub_807A290(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_8048480(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_807D148(pokemon, target, 0, 0);
}

void sub_8048490(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8075FCC(pokemon, target);
}

void sub_804849C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8077AE4(pokemon, target, 1);
}

void sub_80484A8(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8072008(pokemon, target, 1, 1, 1);
}

void sub_80484BC(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8076D10(pokemon, target);
}

void sub_80484C8(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    // Pointer to "But nothing happened!"
    sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_80484DC(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    LevelDownTarget(pokemon, target, 1);
}

void sub_80484E8(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    if(target->entityData->nonVolatileStatus == NON_VOLATILE_STATUS_BURNED)
        sub_807A290(pokemon, target);
    else
    {
        SetMessageArgument(gAvailablePokemonNames, target, 0);
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80FB580);
    }
}

void sub_8048524(struct DungeonEntity *pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData_1;
  u32 *belly;
  u32 newBelly;

  entityData = target->entityData;
  entityData_1 = entityData;
  if (entityData->isLeader)
    sub_8078A58(pokemon, target, 0, 5);
  else
  {
    SetMessageArgument(gAvailablePokemonNames, target, 0);
    if (HasIQSkill(target, IQ_SKILL_SELF_CURER))
        sub_80522F4(pokemon, target, *gPtrSelfHealPreventedHungerMessage);
    else
    {
      belly = &entityData_1->belly;
      if (RoundUpFixedPoint(*belly) != 0) {
        sub_80943A0(&newBelly, 0);
        *belly = newBelly;
        sub_80522F4(pokemon, target, *gUnknown_80F9740);
      }
      else
        sub_80522F4(pokemon, target, *gUnknown_80F9760);
    }
  }
}

void sub_80485B0(struct DungeonEntity *pokemon, struct DungeonEntity * target)
{
  bool8 isMoveBoosted;
  s32 moveIndex;
  struct DungeonEntityData *iVar5;
  register struct PokemonMove *movePtr1 asm("r4"); // r4
  register struct PokemonMove *movePtr2 asm("r5"); // r5
  u8 cVar8;
  s32 movePowerBoost;
  s32 maxPowerBoost;

  isMoveBoosted = FALSE;
  cVar8 = 1;
  iVar5 = target->entityData;
  if (DungeonRandomCapped(100) < gUnknown_80F4F46)
    cVar8 = 3;
  if (iVar5->isLeader) {
    for(moveIndex = 0, movePtr1 = &iVar5->moves[0], movePtr2 = movePtr1; moveIndex < MAX_MON_MOVES; movePtr1++, movePtr2++, moveIndex++)
    {
        if((movePtr1->moveFlags & MOVE_FLAG_EXISTS) && (movePtr1->moveFlags & MOVE_FLAG_SET))
        {
            if(GetMovePower(movePtr2) == 0) continue;
            movePowerBoost = movePtr1->powerBoost;
            maxPowerBoost = GetMoveMaxPowerBoost(movePtr2);
            movePtr1->powerBoost += cVar8;
            if(movePtr1->powerBoost >= maxPowerBoost)
                movePtr1->powerBoost = maxPowerBoost;
            if(movePowerBoost != movePtr1->powerBoost)
                isMoveBoosted = TRUE;
        }
    }

    if (isMoveBoosted) {
      sub_80522F4(pokemon,target,*gUnknown_80FE454);
      if (cVar8 != 1) {
        sub_803E708(10,0x40);
        sub_80522F4(pokemon,target,*gUnknown_80FE434);
     }
    }
    else
      sub_80522F4(pokemon,target,*gUnknown_80FE40C);
  }
  else
     sub_80522F4(pokemon,target,*gUnknown_80FE40C);
}

void sub_804869C(struct DungeonEntity *pokemon, struct DungeonEntity * target, u8 param_3)
{
  s32 uVar1;
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData_1;
  struct DungeonEntity *entity;
  u8 auStack28 [4];
  
  if (param_3 != '\0') {
    entityData = target->entityData;
    entityData_1 = entityData;
    if (gDungeonGlobalData->unk675 != 0) {
        uVar1 = gUnknown_80F4FA8;
        sub_80522F4(pokemon, target, *gUnknown_80FEAE8);
    }
    else {
        uVar1 = gUnknown_80F4FA4;
    }
    if (entityData_1->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN) {
      SendImmobilizeEndMessage(pokemon, target);
    }
    sub_806F370(pokemon, target, uVar1, 1, auStack28, 0, 0x216, 0, 0, 0);
  }
  else
  {
    sub_8042520(pokemon);
    entity = sub_80696FC(pokemon);
    if (entity == NULL)
    {
      sub_80522F4(pokemon, target, *gUnknown_80FDBA0);
    }
    else
    {
      entityData = entity->entityData;
      if (gDungeonGlobalData->unk675 != 0) {
        uVar1 = gUnknown_80F4FAA;
        sub_80522F4(pokemon, target, *gUnknown_80FEAE8);
      }
      else {
        uVar1 = gUnknown_80F4FA6;
      }
      if (entityData->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN) {
        SendImmobilizeEndMessage(pokemon, entity);
      }
      sub_806F370(pokemon, entity, uVar1, 1, auStack28, 0, 0x216, 0, 0, 0);
    }
  }
}

void sub_80487CC(struct DungeonEntity *pokemon, struct DungeonEntity * target, u32 param_3, u32 param_4)
{
    sub_8078B5C(pokemon, target, param_3, param_4, 1);
}
