#include "global.h"
#include "type_effectiveness.h"

#include "constants/ability.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "structs/str_dungeon.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "status.h"
#include "type_chart.h"
#include "weather.h"

u32 gTypeEffectivenessMultipliers[] = {0, 1, 2, 4};

s32 WeightWeakTypePicker(Entity *user, Entity *target, u8 moveType)
{
    s32 weight = 1;
    bool8 checkExposed = FALSE;
    EntityInfo *userData;
    EntityInfo *targetData;
    u8 *targetTypes;
    u8 *targetType;
    u32 moveTypeOffset;
    if (!EntityExists(target))
    {
        return 1;
    }
    if (moveType == TYPE_NORMAL || moveType == TYPE_FIGHTING)
    {
        checkExposed = TRUE;
    }
    userData = user->info;
    targetData = target->info;
    if (moveType == TYPE_FIRE && GetFlashFireStatus(target) != FLASH_FIRE_STATUS_NONE)
    {
        return 0;
    }
    if (moveType == TYPE_ELECTRIC && HasAbility(target, ABILITY_VOLT_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_WATER && HasAbility(target, ABILITY_WATER_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_GROUND && HasAbility(target, ABILITY_LEVITATE))
    {
        return 1;
    }
    targetTypes = targetData->types;
    moveTypeOffset = moveType * NUM_TYPES * sizeof(s16);
    targetType = targetData->types;
    do
    {
        s32 effectiveness;
        u32 typeEffectivenessMultipliers[NUM_EFFECTIVENESS];
        memcpy(typeEffectivenessMultipliers, gTypeEffectivenessMultipliers, NUM_EFFECTIVENESS * sizeof(u32));
        if (checkExposed && *targetType == TYPE_GHOST && !targetData->exposed)
        {
            effectiveness = 0;
            gDungeon->pokemonExposed = TRUE;
        }
        else
        {
            effectiveness = gTypeEffectivenessChart[moveType][*targetType];
            // Used to swap variable initialization order at the loop start.
            effectiveness = *(s16*)(((s8*) gTypeEffectivenessChart) + moveTypeOffset + *targetType * 2);
        }
        if (weight == 0)
        {
            goto breakLoop;
        }
        weight *= typeEffectivenessMultipliers[effectiveness];
        weight /= 2;
        if (weight == 0)
        {
            // BUG: If the Pokémon's first type resists the move, the second type is ignored.
            // This calculates type effectiveness incorrectly if the first type resists the move and the second type is weak to the move.
            // For example, a Fire-type move is considered not very effective against a Rock/Bug-type like Anorith.
            return 2;
        }
    } while ((s32)(++targetType) <= (s32)(targetTypes + 1));
    breakLoop:
    if ((moveType == TYPE_FIRE || moveType == TYPE_ICE) && HasAbility(target, ABILITY_THICK_FAT))
    {
        return 2;
    }
    if (moveType == TYPE_WATER && HasAbility(user, ABILITY_TORRENT))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_GRASS && HasAbility(user, ABILITY_OVERGROW))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_BUG && HasAbility(user, ABILITY_SWARM))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_FIRE && HasAbility(user, ABILITY_BLAZE))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (weight == 0)
    {
        return 2;
    }
    if (MonsterIsType(user, moveType))
    {
        weight *= 2;
    }
    targetTypes = targetData->types;
    if (GetApparentWeather(user) == WEATHER_SUNNY)
    {
        if (moveType == TYPE_FIRE)
        {
            weight *= 2;
        }
        else if (moveType == TYPE_WATER)
        {
            return 2;
        }
    }
    if (gDungeon->mudSportTurns != 0 && moveType == TYPE_ELECTRIC)
    {
        return 2;
    }
    if (gDungeon->waterSportTurns != 0 && moveType == TYPE_FIRE)
    {
        return 2;
    }
    if (moveType == TYPE_ELECTRIC && userData->charging.chargingStatus == STATUS_CHARGING)
    {
        weight *= 2;
    }
    if (weight > 2)
    {
        weight = 3;
    }
    return weight + 2;
}
