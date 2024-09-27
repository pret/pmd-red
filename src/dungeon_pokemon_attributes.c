#include "global.h"
#include "dungeon_pokemon_attributes.h"

#include "code_8045A00.h"
#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/tactic.h"
#include "constants/type.h"
#include "dungeon_items.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "moves.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "structs/str_dungeon.h"

const s16 gItemMasterMinWildLevel[] = {16};

extern u8 gAvailablePokemonNames[];
extern u32 gUnknown_80FC31C;
extern u32 gUnknown_80FCEFC;
extern u32 gUnknown_80FC2FC;
extern bool8 sub_805744C(Entity *, Move *, u32);
extern void sub_80522F4(Entity *r1, Entity *r2, u32);

bool8 HasSafeguardStatus(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  if (target->axObj.info->protection.protectionStatus == STATUS_SAFEGUARD) {
    if (displayMessage) {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,gUnknown_80FC2FC);
    }
    return TRUE;
  }
  return FALSE;
}

bool8 sub_8071728(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  if (target->axObj.info->protection.protectionStatus == STATUS_MIST) {
    if (displayMessage) {
      SetMessageArgument(gAvailablePokemonNames, target, 0);
      sub_80522F4(pokemon, target, gUnknown_80FC31C);
    }
    return TRUE;
  }
  else {
    if (HasAbility(target, ABILITY_CLEAR_BODY) || HasAbility(target, ABILITY_WHITE_SMOKE)) {
        if (displayMessage) {
            SetMessageArgument(gAvailablePokemonNames, target, 0);
            sub_80522F4(pokemon, target, gUnknown_80FCEFC);
        }
        return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_80717A4(Entity *pokemon, u16 moveID)
{
  EntityInfo * entityInfo;
  s32 index;

  entityInfo = pokemon->axObj.info;
  if ((entityInfo->sleep.sleep != STATUS_SLEEP) && (entityInfo->sleep.sleep != STATUS_NAPPING) && (entityInfo->sleep.sleep != STATUS_NIGHTMARE)) {
      return FALSE;
  }
  else
  {
    // Pin this register to match
#ifndef NONMATCHING
    register Move *pokeMove asm("r4");
#else
    Move *pokeMove;
#endif

    Move *pokeMove2; // some reason uses another pointer to same struct

    for(index = 0, pokeMove = entityInfo->moves, pokeMove2 = pokeMove; index < MAX_MON_MOVES; pokeMove++, pokeMove2++, index++)
    {
      if (((pokeMove->moveFlags & MOVE_FLAG_EXISTS)) && (entityInfo->isTeamLeader || ((pokeMove->moveFlags & MOVE_FLAG_ENABLED_FOR_AI))))
            if((sub_805744C(pokemon, pokeMove2, TRUE) != 0) && (pokeMove->PP != 0))
                    if(pokeMove->id == moveID)
                        return TRUE;
    }
    return FALSE;
  }
}

bool8 HasAbility(Entity *pokemon, u8 ability)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = pokemon->axObj.info;
        if (pokemonInfo->abilities[0] == ability || pokemonInfo->abilities[1] == ability)
        {
            return TRUE;
        }
        return FALSE;
    }
}

bool8 MonsterIsType(Entity *pokemon, u8 type)
{
    EntityInfo *pokemonInfo = pokemonInfo = pokemon->axObj.info;
    if (type == TYPE_NONE)
    {
        return FALSE;
    }
    if (pokemonInfo->types[0] == type)
    {
        return TRUE;
    }
    if (pokemonInfo->types[1] == type)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CanSeeInvisibleMonsters(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    if (pokemonInfo->eyesightStatus.eyesightStatus != STATUS_EYEDROPS)
    {
        if (!HasHeldItem(pokemon, ITEM_GOGGLE_SPECS))
            return FALSE;
        else
            return TRUE;
    }
    else
        return TRUE;
}

bool8 HasTactic(Entity *pokemon, u8 tactic)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    if (pokemonInfo->isTeamLeader)
    {
        bool8 isGoTheOtherWay = tactic == TACTIC_GO_THE_OTHER_WAY;
        return isGoTheOtherWay;
    }
    return pokemonInfo->tactic == tactic;
}

bool8 IQSkillIsEnabled(Entity *pokemon, u8 IQSkill)
{
    return IsIQSkillSet(pokemon->axObj.info->IQSkillFlags, 1 << IQSkill);
}

bool8 IQSkillPairIsEnabled(Entity *pokemon, u8 IQSkill1, u8 IQSkill2)
{
    return IsIQSkillSet(pokemon->axObj.info->IQSkillFlags,
                        1 << IQSkill1 | 1 << IQSkill2);
}

void LoadIQSkills(Entity *pokemon)
{
  u8 *iVar2;
  s32 IQSkill;
  EntityInfo *pokemonInfo;

  pokemonInfo = pokemon->axObj.info;
  if (pokemonInfo->isNotTeamMember) {
    iVar2 = pokemonInfo->IQSkillFlags;
    SetIQSkill(iVar2, IQ_STATUS_CHECKER);
    SetIQSkill(iVar2, IQ_PP_CHECKER);
    SetIQSkill(iVar2, IQ_ITEM_CATCHER);
    if (pokemonInfo->bossFlag)
      SetIQSkill(iVar2, IQ_SELF_CURER);
    if (pokemonInfo->level >= *gItemMasterMinWildLevel)
      SetIQSkill(iVar2, IQ_ITEM_MASTER);
    pokemonInfo->tactic = TACTIC_GO_AFTER_FOES;
  }
  else {
    pokemonInfo->IQSkillFlags[0] = 0;
    pokemonInfo->IQSkillFlags[1] = 0;
    pokemonInfo->IQSkillFlags[2] = 0;
    for(IQSkill = IQ_TYPE_ADVANTAGE_MASTER; IQSkill < NUM_IQ_SKILLS; IQSkill++)
    {
      if (HasIQForSkill(pokemonInfo->IQ,IQSkill) &&
            IsIQSkillSet(pokemonInfo->IQSkillMenuFlags, 1 << IQSkill))
        {
            SetIQSkill(pokemonInfo->IQSkillFlags,IQSkill);
      }
    }
  }
}

bool8 CanSeeTeammate(Entity * pokemon)
{
  Entity *teamMember;
  s32 memberIdx;

  if (pokemon->axObj.info->isNotTeamMember) {
      return FALSE;
  }
  else
  {
    for(memberIdx = 0; memberIdx < MAX_TEAM_MEMBERS; memberIdx++)
    {
      teamMember = gDungeon->teamPokemon[memberIdx];
      if (EntityExists(pokemon) && (pokemon != teamMember) && (CanSeeTarget(pokemon,teamMember)))
      {
        return TRUE;
      }
    }
    return FALSE;
  }
}

u8 GetMoveTypeForMonster(Entity *pokemon, Move *pokeMove)
{
    if (pokeMove->id == MOVE_HIDDEN_POWER)
        return pokemon->axObj.info->hiddenPower.hiddenPowerType;
    else
        return GetMoveType(pokeMove);
}

s32 GetMovePower(Entity *pokemon, Move *pokeMove)
{
    if(pokeMove->id == MOVE_HIDDEN_POWER)
        return (pokemon->axObj.info->hiddenPower.hiddenPowerBasePower + pokeMove->ginseng);
    else
        return (GetMoveBasePower(pokeMove) + pokeMove->ginseng);
}

bool8 MonsterCanThrowItems(EntityInfo *pokemon)
{
    if(!MonsterIDCanThrowItems(pokemon->id))
        return FALSE;
    return TRUE;
}

static inline bool8 sub_8071A8C_sub(EntityInfo *pokemonInfo)
{
    if(pokemonInfo->joinedAt.joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON ||
        pokemonInfo->joinedAt.joinedAt == DUNGEON_RESCUE_TEAM_BASE)
        return TRUE;
    else
        return FALSE;
}

bool8 sub_8071A8C(Entity *pokemon)
{
    EntityInfo *pokemonInfo;
    if(EntityExists(pokemon))
    {
        pokemonInfo = pokemon->axObj.info;
        if(pokemonInfo->clientType != CLIENT_TYPE_CLIENT)
        {
            if(!sub_8071A8C_sub(pokemonInfo))
                return TRUE;
        }
    }
    return FALSE;
}

bool8 SetVisualFlags(EntityInfo *entityInfo, u16 newFlag, bool8 param_3)
{
  if ((entityInfo->visualFlags & newFlag)) {
    entityInfo->previousVisualFlags = newFlag | entityInfo->previousVisualFlags;
  }
  else {
    entityInfo->previousVisualFlags = entityInfo->previousVisualFlags & ~newFlag;
  }

  if (param_3) {
    entityInfo->visualFlags = newFlag | entityInfo->visualFlags;
  }
  else {
    entityInfo->visualFlags = entityInfo->visualFlags & ~newFlag;
  }
  if ( ((entityInfo->previousVisualFlags & newFlag) == 0) && ((entityInfo->visualFlags & newFlag)) ) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
