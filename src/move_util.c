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
extern void sub_80429C8(struct DungeonEntity *r0);
extern u16 gNaturePowerMoveTable[];
bool8 sub_805755C(struct DungeonEntity* pokemon,u16 param_2);

u32 sub_8057144(struct DungeonEntity * pokemon)
{
  struct PokemonMove **ppbVar3;
  s32 entityIndex;
  struct PokemonMove *move1;
  struct PokemonMove *move2;
  s32 index;
  struct DungeonEntity *entity;
  s32 counter;
  struct PokemonMove *moveStack [80];
  struct PokemonMove **local_20;
  register s32 counter_1 asm("r0");
  register struct PokemonMove** move_1 asm("r1");

  counter = 0;

  for(entityIndex = 0; entityIndex < DUNGEON_MAX_POKEMON; entityIndex++)
  {
    entity = gDungeonGlobalData->allPokemon[entityIndex];
    if (EntityExists(entity)) {
      move1 = move2 = &entity->entityData->moves[0];
      
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
          if (!sub_805755C(pokemon, move1->moveID) && (move1->moveID != MOVE_SKETCH) && (counter < 80)) {
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
    return moveStack[DungeonRandomCapped(counter)]->moveID;
  }
}

bool8 sub_80571F0(struct DungeonEntity * pokemon, struct PokemonMove *move)
{
    u16 moveID;
    s32 tileset;
    struct DungeonEntityData *entityData;

    entityData = pokemon->entityData;

    if (entityData->unkFF == 1) {
        moveID = move->moveID;
        if ((moveID == MOVE_SKY_UPPERCUT) || (moveID == MOVE_TWISTER) || (moveID == MOVE_GUST) || (moveID == MOVE_THUNDER))
            return FALSE;
        else
            return TRUE;
    }
    else if (entityData->unkFF == 2) {
        if (entityData->chargingStatus == CHARGING_STATUS_DIVE) {
            if (move->moveID == MOVE_WHIRLPOOL || move->moveID == MOVE_SURF) return FALSE;
        }
        else if (entityData->chargingStatus == CHARGING_STATUS_DIG) {
            moveID = move->moveID;
            if (moveID == MOVE_EARTHQUAKE || moveID == MOVE_MAGNITUDE) return FALSE;
            if (moveID == MOVE_NATURE_POWER) {
                tileset = gDungeonGlobalData->tileset;
                if (tileset < 0) {
                    tileset = 0;
                }
                if (0x4a < tileset) {
                    tileset = 0x4a;
                }
                if (gNaturePowerMoveTable[tileset << 2] == MOVE_EARTHQUAKE) return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_805727C(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 chance)
{
    bool8 uVar2;
    if (!sub_8044B28() && EntityExists(pokemon) && EntityExists(target) && 
        (target->entityData->unk158 != 0) &&
        (target->entityData->HP != 0)) {
        if (chance != 0) {
            if (HasAbility(pokemon, ABILITY_SERENE_GRACE)) {
                uVar2 = RollPercentChance_2(chance * 2);
            }
            else
            {
                uVar2 = RollPercentChance_2(chance);
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

bool8 sub_8057308(struct DungeonEntity *pokemon, s32 chance)
{
    if(!EntityExists(pokemon))
        return FALSE;
    if(chance == 0)
        return TRUE;
    if(HasAbility(pokemon, ABILITY_SERENE_GRACE))
        return RollPercentChance_2(chance * 2);
    else
        return RollPercentChance_2(chance);
}

bool8 IsMoveIndexUsable(struct DungeonEntity *pokemon, s32 moveIndex, bool8 hasPPChecker)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct PokemonMove *move = &pokemonData->moves[moveIndex];
    s32 i;
    if (!(move->moveFlags & MOVE_FLAG_EXISTS))
    {
        return FALSE;
    }
    if (move->moveFlags & MOVE_FLAG_LINKED)
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
    if (IsMoveUsable(pokemon, move, hasPPChecker))
    {
        goto returnTrue;
    }
    move++;
    if ((u32) move >= (u32) &pokemonData->struggleMoveFlags || !(move->moveFlags & MOVE_FLAG_LINKED))
    {
        return FALSE;
    }
    goto incMoveIndex;
}

bool8 IsMoveUsable(struct DungeonEntity *pokemon, struct PokemonMove *move, bool8 hasPPChecker)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (move->moveID == MOVE_REGULAR_ATTACK)
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
        if (pokemonData->volatileStatus == VOLATILE_STATUS_TAUNTED && !MoveDealsDirectDamage(move))
        {
            return FALSE;
        }
        if (pokemonData->volatileStatus == VOLATILE_STATUS_ENCORE)
        {
            if (move->moveID == MOVE_STRUGGLE)
            {
                if (!(pokemonData->struggleMoveFlags & MOVE_FLAG_LAST_USED))
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

bool8 sub_805744C(struct DungeonEntity * pokemon, struct PokemonMove *move, bool8 param_3)
{
  struct DungeonEntityData *entityData;
  
  entityData = pokemon->entityData;
  if (move->moveID != MOVE_REGULAR_ATTACK) {
    if (((move->moveFlags & MOVE_FLAG_DISABLED)) || ((move->moveFlags2 & MOVE_FLAG_EXISTS))) {
        return FALSE;
    }
    if (param_3 != 0) {
      if ((entityData->volatileStatus == VOLATILE_STATUS_TAUNTED) && (!MoveDealsDirectDamage(move))) return FALSE;
      if (entityData->volatileStatus == VOLATILE_STATUS_ENCORE) {
        if (move->moveID == MOVE_STRUGGLE) {
          if((entityData->struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
        else {
          if((move->moveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
      }
    }
  }
  return TRUE;
}
