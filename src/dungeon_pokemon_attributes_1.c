#include "global.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_util.h"
#include "pokemon.h"

#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "pokemon_3.h"

extern s16 gItemMasterMinWildLevel;

extern u8 HasItem(struct DungeonEntity *, u32);

extern bool8 IsIQSkillSet(u8 *, u32);
extern void SetIQSkill(u8 *param_1, u32 skillIndex);
extern bool8 HasIQForSkill(s32 pokeIQ, u8 IQSkillIndex);

extern bool8 CanSee(struct DungeonEntity *, struct DungeonEntity *);

extern u8 GetMoveType(struct PokemonMove *move);
extern s32 GetMovePower(struct PokemonMove *move);

bool8 CanSeeInvisible(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (pokemonData->eyesightStatus != EYESIGHT_STATUS_EYEDROPS)
    {
        if (!HasItem(pokemon, ITEM_ID_GOGGLE_SPECS))
            return FALSE;
        else
            return TRUE;
    }
    else
        return TRUE;
}

bool8 HasTactic(struct DungeonEntity *pokemon, u8 tactic)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (pokemonData->isLeader)
    {
        bool8 isGoTheOtherWay = tactic == TACTIC_GO_THE_OTHER_WAY;
        return isGoTheOtherWay;
    }
    return pokemonData->tactic == tactic;
}

bool8 HasIQSkill(struct DungeonEntity *pokemon, u8 IQSkill)
{
    return IsIQSkillSet(pokemon->entityData->IQSkillsEnabled, 1 << IQSkill);
}

bool8 HasIQSkillPair(struct DungeonEntity *pokemon, u8 IQSkill1, u8 IQSkill2)
{
    return IsIQSkillSet(pokemon->entityData->IQSkillsEnabled, 1 << IQSkill1 | 1 << IQSkill2);
}

void LoadIQSkills(struct DungeonEntity *pokemon)
{
  u8 *iVar2;
  s32 IQSkill;
  struct DungeonEntityData *pokemonData;

  pokemonData = pokemon->entityData;
  if (pokemonData->isEnemy) {
    iVar2 = pokemonData->IQSkillsEnabled;
    SetIQSkill(iVar2, IQ_SKILL_STATUS_CHECKER);
    SetIQSkill(iVar2, IQ_SKILL_PP_CHECKER);
    SetIQSkill(iVar2, IQ_SKILL_ITEM_CATCHER);
    if (pokemonData->isBoss)
      SetIQSkill(iVar2, IQ_SKILL_SELF_CURER);
    if (pokemonData->level >= gItemMasterMinWildLevel)
      SetIQSkill(iVar2, IQ_SKILL_ITEM_MASTER);
    pokemonData->tactic = TACTIC_GO_AFTER_FOES;
  }
  else {
    pokemonData->IQSkillsEnabled[0] = 0;
    pokemonData->IQSkillsEnabled[1] = 0;
    pokemonData->IQSkillsEnabled[2] = 0;
    for(IQSkill = IQ_SKILL_TYPE_ADVANTAGE_MASTER; IQSkill < NUM_IQ_SKILLS; IQSkill++)
    {
      if (HasIQForSkill(pokemonData->IQ,IQSkill) &&
            IsIQSkillSet(pokemonData->IQSkillsSelected, 1 << IQSkill))
        {
            SetIQSkill(pokemonData->IQSkillsEnabled,IQSkill);
      }
    }
  }
}

bool8 CanSeeTeammate(struct DungeonEntity * pokemon)
{
  struct DungeonEntity *teamMember;
  s32 memberIdx;

  if (pokemon->entityData->isEnemy) {
      return FALSE;
  }
  else
  {
    for(memberIdx = 0; memberIdx < MAX_TEAM_MEMBERS; memberIdx++)
    {
      teamMember = gDungeonGlobalData->teamPokemon[memberIdx];
      if (EntityExists(pokemon) && (pokemon != teamMember) && (CanSee(pokemon,teamMember)))
      {
        return TRUE;
      }
    }
    return FALSE;
  }
}

u8 GetMoveType_2(struct DungeonEntity *pokemon, struct PokemonMove *pokeMove)
{
    if(pokeMove->moveID == MOVE_HIDDEN_POWER)
        return pokemon->entityData->hiddenPowerType;
    else
        return GetMoveType(pokeMove);
}

s32 CalculateMovePower(struct DungeonEntity *pokemon, struct PokemonMove *pokeMove)
{
    if(pokeMove->moveID == MOVE_HIDDEN_POWER)
        return (pokemon->entityData->hiddenPowerPower + pokeMove->powerBoost);
    else
        return (GetMovePower(pokeMove) + pokeMove->powerBoost);
}

bool8 ToolboxEnabled(struct DungeonEntityData *pokemon)
{
    if(!IsToolboxEnabled(pokemon->entityID))
        return FALSE;
    return TRUE;
}

static inline bool8 sub_8071A8C_sub(struct DungeonEntityData *pokemonData)
{
    if(pokemonData->joinLocation == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON ||
        pokemonData->joinLocation == DUNGEON_RESCUE_TEAM_BASE)
        return TRUE;
    else
        return FALSE;
}

bool8 sub_8071A8C(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData;
    if(EntityExists(pokemon))
    {
        pokemonData = pokemon->entityData;
        if(pokemonData->clientType != CLIENT_TYPE_CLIENT)
        {
            if(!sub_8071A8C_sub(pokemonData))
                return TRUE;
        }
    }
    return FALSE;
}
