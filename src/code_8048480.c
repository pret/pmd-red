#include "global.h"
#include "constants/dungeon.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_action.h"
#include "structs/dungeon_entity.h"
#include "dungeon_util.h"
#include "structs/str_dungeon.h"
#include "move_effects_target.h"
#include "dungeon_capabilities.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "number_util.h"
#include "moves.h"
#include "code_8077274_1.h"
#include "code_80521D0.h"
#include "pokemon.h"
#include "structs/str_position.h"
#include "status.h"

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];

extern s16 gTypeGummiIQBoost[NUM_TYPES][NUMBER_OF_GUMMIS];
extern s16 gUnknown_810A808[NUM_TYPES][NUMBER_OF_GUMMIS];

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

extern void sub_80421C0(Entity *r0, u16 r1);
extern void sub_8078B5C(Entity *, Entity *, u32, u32, u32);
extern u8 sub_806A538(s32);
extern void sub_8051E7C(Entity *pokemon);
extern void sub_8045BF8(u8 *, Item *);
extern void sub_8063B54(ActionContainer *);
extern void sub_80637E8(ActionContainer *);
extern void sub_8063BB4(ActionContainer *);
extern void sub_8063CF0(ActionContainer *, u32);
extern void sub_8063A70(ActionContainer *, u32);
extern u8 sub_8062F90(Entity *, u32, u32, u32, u32);
extern void sub_8044DF0(Entity *, u32, u32);
extern s32 sub_8052B8C(u32, u8 *, u32);
extern void sub_803EAF0(u32, u32);
extern void sub_8044C10(bool8);
Entity *DrawFieldGiveItemMenu(u32, u32);
extern void PrintFieldMessage(u32, u8 *, u32);
extern void sub_8044E24(u32, u32, u32);
extern void sub_804245C(u32, Item *);
extern u8 sub_8072938(Entity *, u16);
extern void sub_807D148(Entity *pokemon, Entity *r1, u32 r2, Position *r3);
extern void sub_8072008(Entity *pokemon, Entity *r1, u32 r2, u8 r3, u32);
extern void LevelDownTarget(Entity *pokemon, Entity *r1, u32 r2);
extern void SetMessageArgument(u8 *buffer, Entity *r1, u32);
extern void sub_80522F4(Entity *pokemon, Entity *r1, const u8[]);
extern void sub_806F370(Entity *pokemon, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8078A58(Entity *, Entity *, s16, u32);
extern s32 sub_8042520(Entity *);
Entity *sub_80696FC(Entity *);
extern void sub_80943A0(void*, s32);
extern void sub_803E708(u32 r0, u32 r1);
extern void sub_806A7E8(EntityInfo *, s32);


void sub_8048340(Entity *pokemon, Entity *target, u32 r2)
{
    sub_806F370(pokemon, target, r2, 1, 0, 0, 528, 0, 0, 0);
}

void sub_8048364(Entity *pokemon, Entity *target, u8 r2)
{
    sub_8079F20(pokemon, target, 1, r2);
}

void sub_8048374(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FB6, gUnknown_80F4FB8, TRUE);
}

void sub_804839C(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FBA, gUnknown_80F4FBC, TRUE);
}

void sub_80483C4(Entity *pokemon, Entity *target)
{
    RestorePPTarget(pokemon, target, 999);
}

void sub_80483D4(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, 0, gUnknown_80F4FBE, TRUE);
}

void sub_80483F4(Entity *pokemon, Entity *target)
{
    BlindTarget(pokemon, target);
}

void XEyeSeedAction(Entity *pokemon, Entity *target)
{
    CrossEyeVisionTarget(pokemon, target);
}

void sub_804840C(Entity *pokemon, Entity *target)
{
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
}

void sub_804841C(Entity *pokemon, Entity *target)
{
    RestoreVisionTarget(pokemon, target);
}

void sub_8048428(Entity *pokemon, Entity *target)
{
    if(target->info->nonVolatileStatus == STATUS_PARALYSIS)
        SendNonVolatileEndMessage(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_8048450(Entity *pokemon, Entity *target)
{
    if((u8)(target->info->nonVolatileStatus - 2) <= 1)
        SendNonVolatileEndMessage(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_8048480(Entity *pokemon, Entity *target)
{
    sub_807D148(pokemon, target, 0, NULL);
}

void sub_8048490(Entity *pokemon, Entity *target)
{
    SleeplessStatusTarget(pokemon, target);
}

void sub_804849C(Entity *pokemon, Entity *target)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
}

void sub_80484A8(Entity *pokemon, Entity *target)
{
    sub_8072008(pokemon, target, 1, 1, 1);
}

void sub_80484BC(Entity *pokemon, Entity *target)
{
    PetrifiedStatusTarget(pokemon, target);
}

void sub_80484C8(Entity *pokemon, Entity *target)
{
    // Pointer to "But nothing happened!"
    sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void sub_80484DC(Entity *pokemon, Entity *target)
{
    LevelDownTarget(pokemon, target, 1);
}

void sub_80484E8(Entity *pokemon, Entity *target)
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

void sub_8048524(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo;
  EntityInfo *entityInfo_1;
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

void sub_80485B0(Entity *pokemon, Entity * target)
{
  bool8 isMoveBoosted;
  s32 moveIndex;
  EntityInfo *entityInfo;
#ifndef NONMATCHING
  register Move *movePtr1 asm("r4"); // r4
  register Move *movePtr2 asm("r5"); // r5
#else
  Move *movePtr1; // r4
  Move *movePtr2; // r5
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

void sub_804869C(Entity *pokemon, Entity * target, u8 param_3)
{
  s32 uVar1;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo_1;
  Entity *entity;
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

void sub_80487CC(Entity *pokemon, Entity * target, u32 param_3, u32 param_4)
{
    sub_8078B5C(pokemon, target, param_3, param_4, 1);
}

static inline bool8 JoinLocationCannotUseItems_1(EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
        return TRUE;

    if (pokemonInfo->joinedAt == DUNGEON_RESCUE_TEAM_BASE)
        return TRUE;

    return FALSE;
}

void sub_80487E0(Entity *pokemon, Entity *target, u8 gummiIndex)
{
  s32 iVar3;
  EntityInfo *targetInfo;
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
    if (!JoinLocationCannotUseItems_1(targetInfo)) {
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

void sub_804891C(Entity *pokemon, Entity *target)
{
    RaiseAtkStatTarget(pokemon, target, 3);
}

void sub_8048928(Entity *pokemon, Entity *target)
{
    RaiseSpAtkStatTarget(pokemon, target, 3);
}

void sub_8048934(Entity *pokemon, Entity *target)
{
    RaiseDefStatTarget(pokemon, target, 3);
}

void sub_8048940(Entity *pokemon, Entity *target)
{
    RaiseSpDefStatTarget(pokemon, target, 3);
}

void nullsub_94(void)
{}

static inline bool8 JoinLocationCannotUseItems_2(EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == DUNGEON_RESCUE_TEAM_BASE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8048950(u32 param_1,Item *item)
{
    u8 flag;
    u16 moveID;
    Entity *entity2;
    Entity *entity;
    EntityInfo *entityInfo;
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
                if (JoinLocationCannotUseItems_2(entityInfo)) {
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

static inline bool8 JoinLocationCannotUseItems_3(EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == DUNGEON_RESCUE_TEAM_BASE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8048A68(u32 param_1,Item *item)
{
  u8 flag;
  Entity *entity2;
  Entity *entity;
  EntityInfo *pEVar6;
  s32 index;
  PokemonStruct2 *pokemon;
  
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
          if (JoinLocationCannotUseItems_3(pEVar6)) {
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

static inline bool8 JoinLocationCannotUseItems_4(EntityInfo *pokemonInfo)
{
    if (pokemonInfo->joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
    {
        return TRUE;
    }
    if (pokemonInfo->joinedAt == DUNGEON_RESCUE_TEAM_BASE)
    {
        return TRUE;
    }
    return FALSE;
}

// TODO: should be bool8
bool32 sub_8048B9C(Entity *entity,Item *param_2)
{
#ifndef NONMATCHING
  register bool32 bVar2 asm("r8");
#else
  bool32 bVar2;
#endif
  bool8 flag;
  EntityInfo *entityInfo;
  Entity * entity2;
  int index;
  Entity *entity1;
  EntityInfo *entity1Info;
  ActionContainer *actionPointer;
  ActionContainer actionContainer;
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
        if(JoinLocationCannotUseItems_4(entity1Info))
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

bool8 sub_8048D50(Entity * pokemon, Item *item)
{
  EntityInfo *entityInfo;

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

void sub_8048DB8(Entity *pokemon, Entity *target, u8 r2)
{
    u8 temp;
    if(r2 != 0)
        sub_806F370(pokemon, target, gUnknown_80F4FAC, 1, &temp, 0, 0x217, 0, 0, 0);
    else
        sub_8051E7C(pokemon);
}

void sub_8048E04(Entity *pokemon, Entity * target)
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

void sub_8048EB0(Entity *pokemon)
{
    SendMessage(pokemon, *gPtrIcePartCrumbledMessage);
}

void sub_8048EC4(Entity *pokemon)
{
    SendMessage(pokemon, *gPtrRockPartCrumbledMessage);
}

void sub_8048ED8(Entity *pokemon)
{
    SendMessage(pokemon, *gPtrSteelPartCrumbledMessage);
}

void sub_8048EEC(Entity *pokemon)
{
    SendMessage(pokemon, *gPtrWishStoneCrumbledMessage);
}

void sub_8048F00(Entity *pokemon)
{
    sub_80421C0(pokemon, 0xD6);
    SendMessage(pokemon, *gPtrMusicBoxPlayedCrumbledMessage);
    sub_803E708(0x3C, 0x46);
}
