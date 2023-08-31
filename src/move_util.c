#include "global.h"
#include "move_util.h"

#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "moves.h"
#include "dungeon_util.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_global_data.h"


extern bool8 sub_8044B28(void);
extern void sub_80429C8(struct Entity *r0);

typedef bool8 (*MoveCallback)(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
struct NaturePowerMove
{
    u16 moveID;
    u16 unk2;
    MoveCallback move;
};

extern struct NaturePowerMove gNaturePowerMoveTable[76];
bool8 sub_805755C(struct Entity* pokemon,u16 param_2);

u32 sub_8057144(struct Entity * pokemon)
{
  struct Move **ppbVar3;
  s32 entityIndex;
  struct Move *move1;
  struct Move *move2;
  s32 index;
  struct Entity *entity;
  s32 counter;
  struct Move *moveStack [80];
  struct Move **local_20;
#ifndef NONMATCHING
  register s32 counter_1 asm("r0");
  register struct Move** move_1 asm("r1");
#else
  s32 counter_1;
  struct Move** move_1;
#endif

  counter = 0;

  for(entityIndex = 0; entityIndex < DUNGEON_MAX_POKEMON; entityIndex++)
  {
    entity = gDungeon->allPokemon[entityIndex];
    if (EntityExists(entity)) {
      move1 = move2 = &entity->info->moves[0];
      
      // NOTE: reg flip here 
       // add  r2, r0, r1 -> add     r2, r1, r0
#ifdef NONMATCHING
      ppbVar3 = &moveStack[counter]; 
#else
      counter_1 = counter;
      move_1 = moveStack;
      ppbVar3 = (move_1 + counter_1);
#endif

      for(index = 0; index < MAX_MON_MOVES; move1++, move2++, index++)
      {
        if ((move1->moveFlags & MOVE_FLAG_EXISTS)) {
          local_20 = ppbVar3;
          if (!sub_805755C(pokemon, move1->id) && (move1->id != MOVE_SKETCH) && (counter < 80)) {
            *local_20 = move2;
            ppbVar3++;
            counter++;
          }
        }
      }
    }
  }
  if (counter == 0) {
    return MOVE_REGULAR_ATTACK; // MOVE_REGULAR_ATTACK
  }
  else {
    return moveStack[DungeonRandInt(counter)]->id;
  }
}

bool8 sub_80571F0(struct Entity * pokemon, struct Move *move)
{
    u16 moveID;
    s32 tileset;
    struct EntityInfo *entityInfo;

    entityInfo = pokemon->info;

    if (entityInfo->unkFF == 1) {
        moveID = move->id;
        if ((moveID == MOVE_SKY_UPPERCUT) || (moveID == MOVE_TWISTER) || (moveID == MOVE_GUST) || (moveID == MOVE_THUNDER))
            return FALSE;
        else
            return TRUE;
    }
    else if (entityInfo->unkFF == 2) {
        if (entityInfo->chargingStatus == STATUS_DIVING) {
            if (move->id == MOVE_WHIRLPOOL || move->id == MOVE_SURF) return FALSE;
        }
        else if (entityInfo->chargingStatus == STATUS_DIGGING) {
            moveID = move->id;
            if (moveID == MOVE_EARTHQUAKE || moveID == MOVE_MAGNITUDE) return FALSE;
            if (moveID == MOVE_NATURE_POWER) {
                tileset = gDungeon->tileset;
                if (tileset < 0) {
                    tileset = 0;
                }
                if (0x4a < tileset) {
                    tileset = 0x4a;
                }
                if (gNaturePowerMoveTable[tileset].moveID == MOVE_EARTHQUAKE) return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_805727C(struct Entity * pokemon, struct Entity * target, s32 chance)
{
    bool8 uVar2;
    if (!sub_8044B28() && EntityExists(pokemon) && EntityExists(target) && 
        (target->info->unk158 != 0) &&
        (target->info->HP != 0)) {
        if (chance != 0) {
            if (HasAbility(pokemon, ABILITY_SERENE_GRACE)) {
                uVar2 = DungeonRandOutcome_2(chance * 2);
            }
            else
            {
                uVar2 = DungeonRandOutcome_2(chance);
            }
        }
        else
        {
            uVar2 = TRUE;
        }
        if ((uVar2 != 0) && (pokemon != target) && HasAbility(target, ABILITY_SHIELD_DUST))
        {
            sub_80429C8(target);
end:
            return FALSE;
        }
        else
            return uVar2;
    }

    goto end;
}

bool8 sub_8057308(struct Entity *pokemon, s32 chance)
{
    if(!EntityExists(pokemon))
        return FALSE;
    if(chance == 0)
        return TRUE;
    if(HasAbility(pokemon, ABILITY_SERENE_GRACE))
        return DungeonRandOutcome_2(chance * 2);
    else
        return DungeonRandOutcome_2(chance);
}

bool8 CanAIUseMove(struct Entity *pokemon, s32 moveIndex, bool8 hasPPChecker)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    struct Move *move = &pokemonInfo->moves[moveIndex];
    s32 i;
    if (!(move->moveFlags & MOVE_FLAG_EXISTS))
    {
        return FALSE;
    }
    if (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)
    {
        return FALSE;
    }
    if (move->moveFlags & MOVE_FLAG_DISABLED ||
        move->moveFlags2 & MOVE_FLAG_SEALED)
    {
        return FALSE;
    }
    goto initMoveIndex;
    returnTrue:
    return TRUE;
    initMoveIndex:
    i = 0;
    goto checkMoveUsable;
    incMoveIndex:
    i++;
    checkMoveUsable:
    if (i >= MAX_MON_MOVES)
    {
        return FALSE;
    }
    if (CanMonsterUseMove(pokemon, move, hasPPChecker))
    {
        goto returnTrue;
    }
    move++;
    if ((u32) move >= (u32) &pokemonInfo->struggleMoveFlags || !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
    {
        return FALSE;
    }
    goto incMoveIndex;
}

bool8 CanMonsterUseMove(struct Entity *pokemon, struct Move *move, bool8 hasPPChecker)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    if (move->id == MOVE_REGULAR_ATTACK)
    {
        return TRUE;
    }
    if (move->moveFlags & MOVE_FLAG_DISABLED || move->moveFlags2 & MOVE_FLAG_SEALED)
    {
        return FALSE;
    }
    if (hasPPChecker)
    {
        if (move->PP == 0)
        {
            return FALSE;
        }
        if (pokemonInfo->volatileStatus == STATUS_TAUNTED && !MovesIgnoresTaunted(move))
        {
            return FALSE;
        }
        if (pokemonInfo->volatileStatus == STATUS_ENCORE)
        {
            if (move->id == MOVE_STRUGGLE)
            {
                if (!(pokemonInfo->struggleMoveFlags & MOVE_FLAG_LAST_USED))
                {
                    return FALSE;
                }
            }
            else if (!(move->moveFlags & MOVE_FLAG_LAST_USED))
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

bool8 sub_805744C(struct Entity * pokemon, struct Move *move, bool8 param_3)
{
  struct EntityInfo *entityInfo;
  
  entityInfo = pokemon->info;
  if (move->id != MOVE_REGULAR_ATTACK) {
    if (((move->moveFlags & MOVE_FLAG_DISABLED)) || ((move->moveFlags2 & MOVE_FLAG_EXISTS))) {
        return FALSE;
    }
    if (param_3 != 0) {
      if ((entityInfo->volatileStatus == STATUS_TAUNTED) && (!MovesIgnoresTaunted(move))) return FALSE;
      if (entityInfo->volatileStatus == STATUS_ENCORE) {
        if (move->id == MOVE_STRUGGLE) {
          if((entityInfo->struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
        else {
          if((move->moveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
      }
    }
  }
  return TRUE;
}
