#include "global.h"
#include "dungeon_pokemon_attributes.h"

#include "dungeon_util.h"
#include "constants/ability.h"
#include "constants/status.h"

extern u8 gAvailablePokemonNames[];
extern u32 gUnknown_80FC31C;
extern u32 gUnknown_80FCEFC;
extern u32 gUnknown_80FC2FC;

extern bool8 sub_805744C(struct DungeonEntity *, struct PokemonMove *, u32);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern void sub_80522F4(struct DungeonEntity *r1, struct DungeonEntity *r2, u32);

bool8 sub_80716E8(struct DungeonEntity * param_1, struct DungeonEntity * param_2, u8 param_3)
{
  if (param_2->entityData->protectionStatus == PROTECTION_STATUS_SAFEGUARD) {
    if (param_3 != '\0') {
      SetMessageArgument(gAvailablePokemonNames,param_2,0);
      sub_80522F4(param_1,param_2,gUnknown_80FC2FC);
    }
    return TRUE;
  }
  return FALSE;
}

bool8 sub_8071728(struct DungeonEntity * param_1, struct DungeonEntity * param_2, u8 param_3)
{
  if (param_2->entityData->protectionStatus == PROTECTION_STATUS_MIST) {
    if (param_3 != '\0') {
      SetMessageArgument(gAvailablePokemonNames, param_2, 0);
      sub_80522F4(param_1, param_2, gUnknown_80FC31C);
    }
    return TRUE;
  }
  else {
    if (HasAbility(param_2, ABILITY_CLEAR_BODY) || HasAbility(param_2, ABILITY_WHITE_SMOKE)) {
        if (param_3 != '\0') {
            SetMessageArgument(gAvailablePokemonNames, param_2, 0);
            sub_80522F4(param_1, param_2, gUnknown_80FCEFC);
        }
        return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_80717A4(struct DungeonEntity *param_1, u16 moveID)
{
  struct DungeonEntityData * entityData;
  s32 iVar3;
  
  entityData = param_1->entityData;
  if ((entityData->sleepStatus != SLEEP_STATUS_SLEEP) && (entityData->sleepStatus != SLEEP_STATUS_NAPPING) && (entityData->sleepStatus != SLEEP_STATUS_NIGHTMARE)) {
      return FALSE;
  }
  else
  {
    // Pin this register to match
    register struct PokemonMove *pokeMove asm("r4");

    struct PokemonMove *pokeMove2; // some reason uses another pointer to same struct

    for(iVar3 = 0, pokeMove = entityData->moves, pokeMove2 = pokeMove; iVar3 < MAX_MON_MOVES; pokeMove++, pokeMove2++, iVar3++)
    {
      if (((pokeMove->moveFlags & MOVE_FLAG_EXISTS) != 0) && (entityData->isLeader || ((pokeMove->moveFlags & MOVE_FLAG_ENABLED) != 0)))
            if((sub_805744C(param_1, pokeMove2, 1) != '\0') && (pokeMove->pp != 0))
                    if(pokeMove->moveID == moveID)
                        return TRUE;
    } 
    return FALSE;
  }
}

bool8 HasAbility(struct DungeonEntity *pokemon, u8 ability)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct DungeonEntityData *pokemonData = pokemon->entityData;
        if (pokemonData->ability1 == ability || pokemonData->ability2 == ability)
        {
            return TRUE;
        }
        return FALSE;
    }
}
