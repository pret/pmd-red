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

extern void sub_807D148(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2, u32 r3);
extern void sub_8075FCC(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void sub_8077AE4(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2);
extern void sub_8072008(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2, u8 r3, u32);
extern void sub_8076D10(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void LevelDownTarget(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2);
extern void sub_8078B5C(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32);
extern void SetMessageArgument(u8 *r0, struct DungeonEntity *r1, u32);
extern void sub_807A290(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void sub_80522F4(struct DungeonEntity *r0, struct DungeonEntity *r1, const char[]);
extern void RestoreVisionTarget(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void sub_8077910(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32);
extern void sub_80791D8(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void BlindTarget(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void HealTargetHP(struct DungeonEntity *r0, struct DungeonEntity *r1, s16, s16, u32);
extern void sub_80792F8(struct DungeonEntity *r0, struct DungeonEntity *r1, u32);
extern void sub_8079F20(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u8);
extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8078A58(struct DungeonEntity *, struct DungeonEntity *, s16, u32);
extern void SendImmobilizeEndMessage(struct DungeonEntity*, struct DungeonEntity*);
extern s32 sub_8042520(struct DungeonEntity *);
struct DungeonEntity *sub_80696FC(struct DungeonEntity *);
extern void sub_80943A0(void*, s32);
extern void sub_803E708(u32 r0, u32 r1);

void sub_8048340(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2)
{
    sub_806F370(r0, r1, r2, 1, 0, 0, 528, 0, 0, 0);
}

void sub_8048364(struct DungeonEntity *r0, struct DungeonEntity *r1, u8 r2)
{
    sub_8079F20(r0, r1, 1, r2);
}

void sub_8048374(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    HealTargetHP(r0, r1, gUnknown_80F4FB6, gUnknown_80F4FB8, 1);
}

void sub_804839C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    HealTargetHP(r0, r1, gUnknown_80F4FBA, gUnknown_80F4FBC, 1);
}

void sub_80483C4(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_80792F8(r0, r1, 999);
}

void sub_80483D4(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    HealTargetHP(r0, r1, 0, gUnknown_80F4FBE, 1);
}

void sub_80483F4(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    BlindTarget(r0, r1);
}

void sub_8048400(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_80791D8(r0, r1);
}

void sub_804840C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8077910(r0, r1, 0, 1);
}

void sub_804841C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    RestoreVisionTarget(r0, r1);
}

void sub_8048428(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    if(r1->entityData->nonVolatileStatus == NON_VOLATILE_STATUS_PARALYZED)
        sub_807A290(r0, r1);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, *gUnknown_80F89F4);
}

void sub_8048450(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    if((u8)(r1->entityData->nonVolatileStatus - 2) <= 1)
        sub_807A290(r0, r1);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, *gUnknown_80F89F4);
}

void sub_8048480(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_807D148(r0, r1, 0, 0);
}

void sub_8048490(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8075FCC(r0, r1);
}

void sub_804849C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8077AE4(r0, r1, 1);
}

void sub_80484A8(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8072008(r0, r1, 1, 1, 1);
}

void sub_80484BC(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8076D10(r0, r1);
}

void sub_80484C8(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    // Pointer to "But nothing happened!"
    sub_80522F4(r0, r1, *gUnknown_80F89F4);
}

void sub_80484DC(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    LevelDownTarget(r0, r1, 1);
}

void sub_80484E8(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    if(r1->entityData->nonVolatileStatus == NON_VOLATILE_STATUS_BURNED)
        sub_807A290(r0, r1);
    else
    {
        SetMessageArgument(gAvailablePokemonNames, r1, 0);
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, *gUnknown_80FB580);
    }
}

void sub_8048524(struct DungeonEntity *param_1, struct DungeonEntity * param_2)
{
  struct DungeonEntityData *iVar2;
  struct DungeonEntityData *iVar3;
  u32 *belly;
  u32 local_14;

  iVar2 = param_2->entityData;
  iVar3 = iVar2;
  if (iVar2->isLeader)
    sub_8078A58(param_1, param_2, 0, 5);
  else
  {
    SetMessageArgument(gAvailablePokemonNames, param_2, 0);
    if (HasIQSkill(param_2, IQ_SKILL_SELF_CURER))
        sub_80522F4(param_1, param_2, *gPtrSelfHealPreventedHungerMessage);
    else
    {
      belly = &iVar3->belly;
      if (RoundUpFixedPoint(*belly) != 0) {
        sub_80943A0(&local_14, 0);
        *belly = local_14;
        sub_80522F4(param_1, param_2, *gUnknown_80F9740);
      }
      else
        sub_80522F4(param_1, param_2, *gUnknown_80F9760);
    }
  }
}

void sub_80485B0(struct DungeonEntity *param_1, struct DungeonEntity * param_2)
{
  bool8 isMoveBoosted;
  s32 moveIndex;
  struct DungeonEntityData *iVar5;
  register struct PokemonMove *movePtr1 asm("r4"); // r4
  register struct PokemonMove *movePtr2 asm("r5"); // r5
  u8 cVar8;
  s32 movePowerBoost;
  s32 moveUnk12;

  isMoveBoosted = FALSE;
  cVar8 = 1;
  iVar5 = param_2->entityData;
  if (DungeonRandomCapped(100) < gUnknown_80F4F46)
    cVar8 = 3;
  if (iVar5->isLeader) {
    for(moveIndex = 0, movePtr1 = &iVar5->moves[0], movePtr2 = movePtr1; moveIndex < MAX_MON_MOVES; movePtr1++, movePtr2++, moveIndex++)
    {
        if((movePtr1->moveFlags & MOVE_FLAG_EXISTS) && (movePtr1->moveFlags & MOVE_FLAG_SET))
        {
            if(GetMovePower(movePtr2) == 0) continue;
            movePowerBoost = movePtr1->powerBoost;
            moveUnk12 = GetMoveUnk12(movePtr2);
            movePtr1->powerBoost += cVar8;
            if(movePtr1->powerBoost >= moveUnk12)
                movePtr1->powerBoost = moveUnk12;
            if(movePowerBoost != movePtr1->powerBoost)
                isMoveBoosted = TRUE;
        }
    }

    if (isMoveBoosted) {
      sub_80522F4(param_1,param_2,*gUnknown_80FE454);
      if (cVar8 != 1) {
        sub_803E708(10,0x40);
        sub_80522F4(param_1,param_2,*gUnknown_80FE434);
     }
    }
    else
      sub_80522F4(param_1,param_2,*gUnknown_80FE40C);
  }
  else
     sub_80522F4(param_1,param_2,*gUnknown_80FE40C);
}

void sub_804869C(struct DungeonEntity *param_1, struct DungeonEntity * param_2, u8 param_3)
{
  s32 uVar1;
  struct DungeonEntityData *iVar2;
  struct DungeonEntityData *iVar4;
  struct DungeonEntity *iVar3;
  u8 auStack28 [4];
  
  if (param_3 != '\0') {
    iVar2 = param_2->entityData;
    iVar4 = iVar2;
    if (gDungeonGlobalData->unk675 != 0) {
        uVar1 = gUnknown_80F4FA8;
        sub_80522F4(param_1, param_2, *gUnknown_80FEAE8);
    }
    else {
        uVar1 = gUnknown_80F4FA4;
    }
    if (iVar4->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN) {
      SendImmobilizeEndMessage(param_1, param_2);
    }
    sub_806F370(param_1, param_2, uVar1, 1, auStack28, 0, 0x216, 0, 0, 0);
  }
  else
  {
    sub_8042520(param_1);
    iVar3 = sub_80696FC(param_1);
    if (iVar3 == NULL)
    {
      sub_80522F4(param_1, param_2, *gUnknown_80FDBA0);
    }
    else
    {
      iVar2 = iVar3->entityData;
      if (gDungeonGlobalData->unk675 != 0) {
        uVar1 = gUnknown_80F4FAA;
        sub_80522F4(param_1, param_2, *gUnknown_80FEAE8);
      }
      else {
        uVar1 = gUnknown_80F4FA6;
      }
      if (iVar2->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN) {
        SendImmobilizeEndMessage(param_1, iVar3);
      }
      sub_806F370(param_1, iVar3, uVar1, 1, auStack28, 0, 0x216, 0, 0, 0);
    }
  }
}

void sub_80487CC(struct DungeonEntity *param_1, struct DungeonEntity * param_2, u32 param_3, u32 param_4)
{
    sub_8078B5C(param_1, param_2, param_3, param_4, 1);
}
