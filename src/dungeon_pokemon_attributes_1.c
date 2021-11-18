#include "global.h"
#include "dungeon_pokemon_attributes_1.h"

#include "constants/status.h"
#include "constants/tactic.h"

extern bool8 IsIQSkillSet(u8 *, u32);
extern u8 HasItem(struct DungeonEntity *, u32);

bool8 sub_8071884(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if(pokemonData->eyesightStatus != EYESIGHT_STATUS_EYEDROPS)
    {
        if(!HasItem(pokemon, ITEM_ID_GOGGLE_SPECS))
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

bool8 HasIQSkill(struct DungeonEntity* pokemon, u8 IQSkill)
{
    return IsIQSkillSet(pokemon->entityData->IQSkillsEnabled, 1 << IQSkill);
}

bool8 HasIQSkillPair(struct DungeonEntity* pokemon, u8 IQSkill1, u8 IQSkill2)
{
    return IsIQSkillSet(pokemon->entityData->IQSkillsEnabled, 1 << IQSkill1 | 1 << IQSkill2);
}
