#include "global.h"
#include "dungeon_pokemon_attributes.h"

#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/type.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_3.h"

const s16 gItemMasterMinWildLevel[] = {16};

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
            if((sub_805744C(param_1, pokeMove2, 1) != '\0') && (pokeMove->PP != 0))
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
        if (pokemonData->abilities[0] == ability || pokemonData->abilities[1] == ability)
        {
            return TRUE;
        }
        return FALSE;
    }
}

bool8 HasType(struct DungeonEntity *pokemon, u8 type)
{
    struct DungeonEntityData *pokemonData = pokemonData = pokemon->entityData;
    if (type == TYPE_NONE)
    {
        return FALSE;
    }
    if (pokemonData->type1 == type)
    {
        return TRUE;
    }
    if (pokemonData->type2 == type)
    {
        return TRUE;
    }
    return FALSE;
}

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
    if (pokemonData->level >= *gItemMasterMinWildLevel)
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

u8 GetMoveTypeForPokemon(struct DungeonEntity *pokemon, struct PokemonMove *pokeMove)
{
    if (pokeMove->moveID == MOVE_HIDDEN_POWER)
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
