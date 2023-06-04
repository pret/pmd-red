#include "global.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "dungeon_action.h"
#include "dungeon_entity.h"
#include "dungeon_util.h"
#include "dungeon_global_data.h"
#include "move_effects_target.h"
#include "dungeon_capabilities.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "number_util.h"
#include "moves.h"
#include "code_8077274_1.h"
#include "code_80521D0.h"
#include "pokemon.h"
#include "position.h"
#include "status.h"

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];

extern s16 gTypeGummiIQBoost[0x12][NUMBER_OF_GUMMIS];
extern s16 gUnknown_810A808[0x12][NUMBER_OF_GUMMIS];

extern u8 *gUnknown_80F89F4[];
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
extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4FAC;

extern u8 *gUnknown_80FEAE8[];
extern u8 *gUnknown_80FDBA0[];
extern u8 *gUnknown_80FE434[];
extern u8 *gUnknown_80FE40C[];
extern u8 *gUnknown_80FE454[];
extern u8 *gPtrSelfHealPreventedHungerMessage[];
extern u8 *gUnknown_80F9740[];
extern u8 *gUnknown_80F9760[];
extern u8 *gUnknown_80FD644[];
extern u8 *gUnknown_80FD648[];
extern u8 *gUnknown_80FD6E8[];
extern u8 *gPtrCantUseInDungeonMessage[];
extern u8 *gUnknown_80FE3E8[];
extern u8 *gPtrMusicBoxPlayedCrumbledMessage[];
extern u8 *gPtrWishStoneCrumbledMessage[];
extern u8 *gPtrIcePartCrumbledMessage[];
extern u8 *gPtrRockPartCrumbledMessage[];
extern u8 *gPtrSteelPartCrumbledMessage[];
extern u8 *gUnknown_80FDCA4[];
extern u8 *gUnknown_80FE3E8[];
extern u8 *gUnknown_80FECA0[];
extern u8 *gUnknown_80FE3E8[];
extern u8 *gUnknown_80F9BD8[];

extern void sub_80421C0(struct Entity *r0, u16 r1);
extern void sub_8078B5C(struct Entity *, struct Entity *, u32, u32, u32);
extern u8 sub_806A538(s32);
extern void sub_8051E7C(struct Entity *pokemon);
extern void sub_8045BF8(u8 *, struct Item *);
extern void sub_8063B54(struct ActionContainer *);
extern void sub_80637E8(struct ActionContainer *);
extern void sub_8063BB4(struct ActionContainer *);
extern void sub_8063CF0(struct ActionContainer *, u32);
extern void sub_8063A70(struct ActionContainer *, u32);
extern u8 sub_8062F90(struct Entity *, u32, u32, u32, u32);
extern void sub_8044DF0(struct Entity *, u32, u32);
extern s32 sub_8052B8C(u32, u8 *, u32);
extern void sub_803EAF0(u32, u32);
extern void sub_8044C10(bool8);
struct Entity *DrawFieldGiveItemMenu(u32, u32);
extern void PrintFieldMessage(u32, u8 *, u32);
extern void sub_8044E24(u32, u32, u32);
extern void sub_804245C(u32, struct Item *);
extern u8 sub_8072938(struct Entity *, u16);
extern void sub_807D148(struct Entity *pokemon, struct Entity *r1, u32 r2, struct Position *r3);
extern void sub_8072008(struct Entity *pokemon, struct Entity *r1, u32 r2, u8 r3, u32);
extern void LevelDownTarget(struct Entity *pokemon, struct Entity *r1, u32 r2);
extern void SetMessageArgument(u8 *buffer, struct Entity *r1, u32);
extern void sub_80522F4(struct Entity *pokemon, struct Entity *r1, const char[]);
extern void sub_806F370(struct Entity *pokemon, struct Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8078A58(struct Entity *, struct Entity *, s16, u32);
extern s32 sub_8042520(struct Entity *);
struct Entity *sub_80696FC(struct Entity *);
extern void sub_80943A0(void*, s32);
extern void sub_803E708(u32 r0, u32 r1);
extern void sub_806A7E8(struct EntityInfo *, s32);


void sub_8048340(struct Entity *pokemon, struct Entity *target, u32 r2)
{
    sub_806F370(pokemon, target, r2, 1, 0, 0, 528, 0, 0, 0);
}

void sub_8048364(struct Entity *pokemon, struct Entity *target, u8 r2)
{
    sub_8079F20(pokemon, target, 1, r2);
}

void sub_8048374(struct Entity *pokemon, struct Entity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FB6, gUnknown_80F4FB8, TRUE);
}

void sub_804839C(struct Entity *pokemon, struct Entity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FBA, gUnknown_80F4FBC, TRUE);
}

void sub_80483C4(struct Entity *pokemon, struct Entity *target)
{
    RestorePPTarget(pokemon, target, 999);
}

void sub_80483D4(struct Entity *pokemon, struct Entity *target)
{
    HealTargetHP(pokemon, target, 0, gUnknown_80F4FBE, TRUE);
}

void sub_80483F4(struct Entity *pokemon, struct Entity *target)
{
    BlindTarget(pokemon, target);
}

void XEyeSeedAction(struct Entity *pokemon, struct Entity *target)
{
    CrossEyeVisionTarget(pokemon, target);
}

void sub_804840C(struct Entity *pokemon, struct Entity *target)
{
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
}

void sub_804841C(struct Entity *pokemon, struct Entity *target)
{
    RestoreVisionTarget(pokemon, target);
}

void sub_8048428(struct Entity *pokemon, struct Entity *target)
{
    if(target->info->nonVolatileStatus == STATUS_PARALYSIS)
        SendNonVolatileEndMessage(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_8048450(struct Entity *pokemon, struct Entity *target)
{
    if((u8)(target->info->nonVolatileStatus - 2) <= 1)
        SendNonVolatileEndMessage(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_8048480(struct Entity *pokemon, struct Entity *target)
{
    sub_807D148(pokemon, target, 0, NULL);
}

void sub_8048490(struct Entity *pokemon, struct Entity *target)
{
    SleeplessStatusTarget(pokemon, target);
}

void sub_804849C(struct Entity *pokemon, struct Entity *target)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
}

void sub_80484A8(struct Entity *pokemon, struct Entity *target)
{
    sub_8072008(pokemon, target, 1, 1, 1);
}

void sub_80484BC(struct Entity *pokemon, struct Entity *target)
{
    PetrifiedStatusTarget(pokemon, target);
}

void sub_80484C8(struct Entity *pokemon, struct Entity *target)
{
    // Pointer to "But nothing happened!"
    sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_80484DC(struct Entity *pokemon, struct Entity *target)
{
    LevelDownTarget(pokemon, target, 1);
}

void sub_80484E8(struct Entity *pokemon, struct Entity *target)
{
    if(target->info->nonVolatileStatus == STATUS_BURN)
        SendNonVolatileEndMessage(pokemon, target);
    else
    {
        SetMessageArgument(gAvailablePokemonNames, target, 0);
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80FB580);
    }
}

void sub_8048524(struct Entity *pokemon, struct Entity * target)
{
  struct EntityInfo *entityInfo;
  struct EntityInfo *entityInfo_1;
  u32 *belly;
  u32 newBelly;

  entityInfo = target->info;
  entityInfo_1 = entityInfo;
  if (entityInfo->isTeamLeader)
    sub_8078A58(pokemon, target, 0, 5);
  else
  {
    SetMessageArgument(gAvailablePokemonNames, target, 0);
    if (IQSkillIsEnabled(target, IQ_SELF_CURER))
        sub_80522F4(pokemon, target, *gPtrSelfHealPreventedHungerMessage);
    else
    {
      belly = &entityInfo_1->belly;
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

void sub_80485B0(struct Entity *pokemon, struct Entity * target)
{
  bool8 isMoveBoosted;
  s32 moveIndex;
  struct EntityInfo *entityInfo;
#ifndef NONMATCHING
  register struct Move *movePtr1 asm("r4"); // r4
  register struct Move *movePtr2 asm("r5"); // r5
#else
  struct Move *movePtr1; // r4
  struct Move *movePtr2; // r5
#endif
  u8 moveBoost;
  s32 movePowerBoost;
  s32 maxPowerBoost;

  isMoveBoosted = FALSE;
  moveBoost = 1;
  entityInfo = target->info;
  if (DungeonRandInt(100) < gUnknown_80F4F46)
    moveBoost = 3;
  if (entityInfo->isTeamLeader) {
    for(moveIndex = 0, movePtr1 = &entityInfo->moves[0], movePtr2 = movePtr1; moveIndex < MAX_MON_MOVES; movePtr1++, movePtr2++, moveIndex++)
    {
        if((movePtr1->moveFlags & MOVE_FLAG_EXISTS) && (movePtr1->moveFlags & MOVE_FLAG_SET))
        {
            if(GetMoveBasePower(movePtr2) == 0) continue;
            movePowerBoost = movePtr1->ginseng;
            maxPowerBoost = GetMoveMaxUpgradeLevel(movePtr2);
            movePtr1->ginseng += moveBoost;
            if(movePtr1->ginseng >= maxPowerBoost)
                movePtr1->ginseng = maxPowerBoost;
            if(movePowerBoost != movePtr1->ginseng)
                isMoveBoosted = TRUE;
        }
    }

    if (isMoveBoosted) {
      sub_80522F4(pokemon,target,*gUnknown_80FE454);
      if (moveBoost != 1) {
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

void sub_804869C(struct Entity *pokemon, struct Entity * target, u8 param_3)
{
  s32 uVar1;
  struct EntityInfo *entityInfo;
  struct EntityInfo *entityInfo_1;
  struct Entity *entity;
  u8 auStack28 [4];
  
  if (param_3 != 0) {
    entityInfo = target->info;
    entityInfo_1 = entityInfo;
    if (gDungeon->unk675 != 0) {
        uVar1 = gUnknown_80F4FA8;
        sub_80522F4(pokemon, target, *gUnknown_80FEAE8);
    }
    else {
        uVar1 = gUnknown_80F4FA4;
    }
    if (entityInfo_1->immobilizeStatus == STATUS_FROZEN) {
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
      entityInfo = entity->info;
      if (gDungeon->unk675 != 0) {
        uVar1 = gUnknown_80F4FAA;
        sub_80522F4(pokemon, target, *gUnknown_80FEAE8);
      }
      else {
        uVar1 = gUnknown_80F4FA6;
      }
      if (entityInfo->immobilizeStatus == STATUS_FROZEN) {
        SendImmobilizeEndMessage(pokemon, entity);
      }
      sub_806F370(pokemon, entity, uVar1, 1, auStack28, 0, 0x216, 0, 0, 0);
    }
  }
}

void sub_80487CC(struct Entity *pokemon, struct Entity * target, u32 param_3, u32 param_4)
{
    sub_8078B5C(pokemon, target, param_3, param_4, 1);
}

static inline bool8 sub_80487E0_sub(struct EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == 0x4A)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == 0x47)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_80487E0(struct Entity *pokemon, struct Entity *target, u8 gummiIndex)
{
  s32 iVar3;
  struct EntityInfo *targetInfo;
  s32 gummiBoost;
  s32 baseIQ;
  s32 iVar4;
  s32 iVar5;
  s32 currIQ;
    
  targetInfo = target->info;
  gummiBoost = gTypeGummiIQBoost[targetInfo->types[0]][gummiIndex];
  gummiBoost += gTypeGummiIQBoost[targetInfo->types[1]][gummiIndex];
  sub_8078B5C(pokemon,target,
             gUnknown_810A808[targetInfo->types[0]][gummiIndex] +
             gUnknown_810A808[targetInfo->types[1]][gummiIndex],0,1);
  if (!targetInfo->isNotTeamMember) {
    if (!sub_80487E0_sub(targetInfo)) {
      baseIQ = targetInfo->IQ;
      targetInfo->IQ += gummiBoost;
      currIQ = baseIQ + gummiBoost;
      if (targetInfo->IQ <= 0) {
        targetInfo->IQ = 1;
      }
      if (999 < targetInfo->IQ) {
        targetInfo->IQ = 999;
      }
      if (baseIQ == targetInfo->IQ) {
        sub_80522F4(pokemon,target,*gUnknown_80FD644);
      }
      else {
        iVar5 = currIQ - baseIQ;
        iVar4 = 0;
        if (((iVar5 < 9) && (iVar4 = 1, iVar5 < 5)) && (iVar4 = 3, 2 < iVar5)) {
          iVar4 = 2;
        }
        iVar5 = targetInfo->IQ - baseIQ;
        iVar3 = 0;
        if (((iVar5 < 9) && (iVar3 = 1, iVar5 < 5)) && (iVar3 = 3, 2 < iVar5)) {
          iVar3 = 2;
        }
        sub_80522F4(pokemon,target,gUnknown_80FD648[iVar4]);
        sub_80522F4(pokemon,target,gUnknown_80FD6E8[iVar3]);
        LoadIQSkills(target);
        sub_806A7E8(targetInfo,baseIQ);
      }
    }
  }
}

void sub_804891C(struct Entity *pokemon, struct Entity *target)
{
    RaiseAtkStatTarget(pokemon, target, 3);
}

void sub_8048928(struct Entity *pokemon, struct Entity *target)
{
    RaiseSpAtkStatTarget(pokemon, target, 3);
}

void sub_8048934(struct Entity *pokemon, struct Entity *target)
{
    RaiseDefStatTarget(pokemon, target, 3);
}

void sub_8048940(struct Entity *pokemon, struct Entity *target)
{
    RaiseSpDefStatTarget(pokemon, target, 3);
}

void nullsub_94(void)
{}

static inline bool8 sub_8048950_sub(struct EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == 0x4A)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == 0x47)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8048950(u32 param_1,struct Item *item)
{
    u8 flag;
    u16 moveID;
    struct Entity *entity2;
    struct Entity *entity;
    struct EntityInfo *entityInfo;
    int index;

    moveID = GetItemMoveID(item->id);
    if ((item->flags & ITEM_FLAG_STICKY)) {
        PrintFieldMessage(0,*gUnknown_80FE3E8,1);
        return FALSE;
    }
    else if (IsHMItem(item->id)) {
        PrintFieldMessage(0,*gPtrCantUseInDungeonMessage,1);
        return FALSE;
    }
    else
    {
        for(index = 0; index < MAX_TEAM_MEMBERS; index++)
        {
            entity = gDungeon->teamPokemon[index];
            if (EntityExists(entity)) {
                entityInfo = entity->info;
                flag = CanMonLearnMove(moveID, entityInfo->id);
                if (CannotMove(entity, FALSE)) {
                    flag = FALSE;
                }
                if (entityInfo->clientType == CLIENT_TYPE_CLIENT) {
                    flag = FALSE;
                }
                if (sub_8048950_sub(entityInfo)) {
                    flag = FALSE;
                }
                entityInfo->unk157 = flag;
            }
        }
        entity2 = DrawFieldGiveItemMenu(0,1);
        if (!EntityExists(entity2)) {
            return FALSE;
        }
        sub_804245C(param_1,item);
        if (sub_8072938(entity2,moveID) == 0) {
            return FALSE;
        }
        sub_8044E24(param_1,0,0x141);
        return TRUE;
    }
    return FALSE;
}

static inline bool8 sub_8048A68_sub(struct EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == 0x4A)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == 0x47)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8048A68(u32 param_1,struct Item *item)
{
  u8 flag;
  struct Entity *entity2;
  struct Entity *entity;
  struct EntityInfo *pEVar6;
  s32 index;
  struct PokemonStruct2 *pokemon;
  
  if ((item->flags & ITEM_FLAG_STICKY)) {
    PrintFieldMessage(0,*gUnknown_80FE3E8,1);
    return FALSE;
  }
  else
  {
    if (gDungeon->unk65C == 0) {
        PrintFieldMessage(0,*gUnknown_80F9BD8,1);
        return FALSE;
    }
    else
    {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeon->teamPokemon[index];
        if (EntityExists(entity)) {
          pEVar6 = entity->info;
          flag = TRUE;
          if(((MAX_TEAM_MEMBERS - 1) < pEVar6->teamIndex))
             flag =  FALSE;
          else
          {
             pokemon = &gRecruitedPokemonRef->pokemon2[pEVar6->teamIndex];
             if (sub_806A538(pokemon->unkA))
                 flag =  FALSE;   
          }
            
          if (CannotMove(entity, FALSE)) {
            flag = FALSE;
          }
          if (pEVar6->clientType == CLIENT_TYPE_CLIENT) {
            flag = FALSE;
          }
          if (sub_8048A68_sub(pEVar6)) {
            flag = FALSE;
          }
          if (pEVar6->isTeamLeader) {
            flag = FALSE;
          }
          pEVar6->unk157 = flag;
        }
      }
      entity2 = DrawFieldGiveItemMenu(0,1);
      if (!EntityExists(entity2)) {
        return FALSE;
      }
      sub_804245C(param_1,item);
      gDungeon->unkBC = entity2;
      sub_8044E24(param_1,0,0x142);
      return TRUE;
    }
  }
  return FALSE;
}

static inline bool8 sub_8048B9C_sub(struct EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == 0x4A)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == 0x47)
    {
        return TRUE;
    }
    return FALSE;
}

// TODO: should be bool8
bool32 sub_8048B9C(struct Entity *entity,struct Item *param_2)
{
#ifndef NONMATCHING
  register bool32 bVar2 asm("r8");
#else
  bool32 bVar2;
#endif
  bool8 flag;
  struct EntityInfo *entityInfo;
  struct Entity * entity2;
  int index;
  struct Entity *entity1;
  struct EntityInfo *entity1Info;
  struct ActionContainer *actionPointer;
  struct ActionContainer actionContainer;
  u16 action;
  
  bVar2 = FALSE;
  entityInfo = entity->info;
  actionPointer = &(entityInfo->action);
  if ((param_2->flags & ITEM_FLAG_STICKY)) {
      PrintFieldMessage(0,*gUnknown_80FE3E8,1);
      return FALSE;
  }
  else
  {
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
      entity1 = gDungeon->teamPokemon[index];
      if (EntityExists(entity1)) {
        entity1Info = entity1->info;
        flag = TRUE;
        if(CannotMove(entity1, FALSE))
        {
            flag = FALSE;
        }
        if(entity1Info->clientType == CLIENT_TYPE_CLIENT)
        {
            flag = FALSE;
        }
        if(sub_8048B9C_sub(entity1Info))
        {
            flag = FALSE;
        }
        entity1Info->unk157 = flag;
      }
    }
    entity2 = DrawFieldGiveItemMenu(0,1);
    if (!EntityExists(entity2)) {
        return FALSE;
    }
    else
    {
      while( TRUE ) {
        entityInfo = entity2->info;
        actionContainer = *actionPointer;
        goto _clear;
_load:
        action = actionPointer->action;
        if (action == ACTION_UNK1D) {
          sub_80637E8(actionPointer);
        }
        else if (action == ACTION_UNK20) {
          sub_803EAF0(0,0);
          sub_8063BB4(actionPointer);
          sub_8044C10(TRUE);
          bVar2 = TRUE;
        }
        else if (action == ACTION_UNK21) {
          sub_803EAF0(0,0);
          sub_8063CF0(actionPointer,0);
          sub_8044C10(TRUE);
        }
        else if ((action == ACTION_SET_MOVE) || (action == ACTION_UNSET_MOVE)) {
          sub_803EAF0(0,0);
          sub_8063A70(actionPointer,0);
        }
        else if (action == ACTION_UNK1F) {
          sub_803EAF0(0,0);
          sub_8063B54(actionPointer);
        }
_clear:
        ClearMonsterActionFields(actionPointer);
        if (sub_8062F90(entity2,1,0,0,1) != 0) {
          if (bVar2)
          {
              if (sub_8052B8C(0,*gUnknown_80FECA0,1) == 1) {
                *actionPointer = actionContainer;
                sub_8044DF0(entity,0,0x6e);
                SetMonsterActionFields(actionPointer,0x2c);
                break;
              }
          } 
          else
          {
               sub_8044C10(TRUE);
               break;
          }
        }
        goto _load;
      } 
    }
  }
  return bVar2;
}

bool8 sub_8048D50(struct Entity * pokemon, struct Item *item)
{
  struct EntityInfo *entityInfo;

  entityInfo = pokemon->info;
  
  if ((item->flags & ITEM_FLAG_STICKY) != 0) {
    sub_8045BF8(gUnknown_202DE58, item);
    SendMessage(pokemon,*gUnknown_80FE3E8);
    return FALSE;
  }
  else
  {
    if ((entityInfo->muzzled == TRUE) && (IsEdibleItem(item->id))) {
        SetMessageArgument(gAvailablePokemonNames,pokemon,0);
        SendMessage(pokemon,*gUnknown_80FDCA4);
        return FALSE;
    }
  }
  return TRUE;
}

void sub_8048DB8(struct Entity *pokemon, struct Entity *target, u8 r2)
{
    u8 temp;
    if(r2 != 0)
        sub_806F370(pokemon, target, gUnknown_80F4FAC, 1, &temp, 0, 0x217, 0, 0, 0);
    else
        sub_8051E7C(pokemon);
}

void sub_8048E04(struct Entity *pokemon, struct Entity * target)
{
    sub_8078B5C(pokemon, target, 0x1E, 0, 1);
    switch(DungeonRandInt(5))
    {
        case 0:
            PoisonedStatusTarget(pokemon, target, TRUE);
            break;
        case 1:
            ImmobilizedStatusTarget(pokemon, target);
            break;
        case 2:
            BurnedStatusTarget(pokemon, target, 1, TRUE);
            break;
        case 3:
            ParalyzeStatusTarget(pokemon, target, TRUE);
            break;
        case 4:
            LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 3, 1, TRUE);
            LowerAttackStageTarget(pokemon, target, gUnknown_8106A50, 3, 1, TRUE);
            break;
    } 
}

void sub_8048EB0(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrIcePartCrumbledMessage);
}

void sub_8048EC4(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrRockPartCrumbledMessage);
}

void sub_8048ED8(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrSteelPartCrumbledMessage);
}

void sub_8048EEC(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrWishStoneCrumbledMessage);
}

void sub_8048F00(struct Entity *pokemon)
{
    sub_80421C0(pokemon, 0xD6);
    SendMessage(pokemon, *gPtrMusicBoxPlayedCrumbledMessage);
    sub_803E708(0x3C, 0x46);
}
