#include "constants/dungeon_action.h"
#include "global.h"
#include "constants/status.h"
#include "code_80521D0.h"
#include "move_effects_target.h"
#include "dungeon_global_data.h"
#include "dungeon_action.h"
#include "dungeon_capabilities.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "item.h"
#include "status.h"

extern void sub_803E708(u32, u32);
extern void sub_80421C0(struct Entity *r0, u16 r1);
extern void sub_8078B5C(struct Entity *, struct Entity *, u32, u32, u32);

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];

extern u8 *gPtrMusicBoxPlayedCrumbledMessage[];
extern u8 *gPtrWishStoneCrumbledMessage[];
extern u8 *gPtrIcePartCrumbledMessage[];
extern u8 *gPtrRockPartCrumbledMessage[];
extern u8 *gPtrSteelPartCrumbledMessage[];
extern u8 *gUnknown_80FDCA4[];
extern u8 *gUnknown_80FE3E8[];
extern u8 *gUnknown_80FECA0[];

extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4FAC;

extern void sub_806F370(struct Entity *r0, struct Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8051E7C(struct Entity *pokemon);
extern void sub_8045BF8(u8 *, struct Item *);
extern void SetMessageArgument(char[], struct Entity*, u32);
struct Entity *DrawFieldGiveItemMenu(u32, u32);
extern void PrintFieldMessage(u32, u8 *, u32);
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

