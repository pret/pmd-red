#include "global.h"
#include "status_checker.h"

#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "map.h"
#include "number_util.h"
#include "status_checks_1.h"
#include "weather.h"

// Array indices correspond to the current dungeon tileset.
const u8 gDungeonCamouflageTypes[76] = {
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_GRASS,
    TYPE_ICE,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_ICE,
    TYPE_ICE,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GROUND,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_ICE,
    TYPE_ROCK,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_WATER,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_WATER,
    TYPE_WATER,
    TYPE_ROCK
};

extern bool8 HasQuarterHPOrLess(struct DungeonEntity*);
extern bool8 IsTileGround(struct MapTile*);
extern bool8 CanLayTrap(struct Position*);

bool8 CanUseOnSelfWithStatusChecker(struct DungeonEntity *pokemon, struct PokemonMove *move)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    switch (move->moveID)
    {
        case MOVE_HAIL:
            if (GetWeather(pokemon) == WEATHER_HAIL)
            {
                return FALSE;
            }
            break;
        case MOVE_RAGE:
            if (pokemonData->chargingStatus == CHARGING_STATUS_RAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_COUNTER:
        case MOVE_PURSUIT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_COUNTER)
            {
                return FALSE;
            }
            break;
        case MOVE_MIRROR_MOVE:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MIRROR_MOVE)
            {
                return FALSE;
            }
            break;
        case MOVE_HOWL:
        case MOVE_MEDITATE:
        case MOVE_SHARPEN:
            if (pokemonData->attackStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BELLY_DRUM:
            if (pokemonData->attackStage >= MAX_STAT_STAGE || RoundUpFixedPoint(pokemonData->belly) <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_ACID_ARMOR:
        case MOVE_BARRIER:
        case MOVE_DEFENSE_CURL:
        case MOVE_HARDEN:
        case MOVE_IRON_DEFENSE:
        case MOVE_WITHDRAW:
            if (pokemonData->defenseStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BIDE:
        case MOVE_REVENGE:
            if (pokemonData->chargingStatus == CHARGING_STATUS_BIDE)
            {
                return FALSE;
            }
            break;
        case MOVE_AGILITY:
        {
            u32 r1;
#ifndef NONMATCHING
            asm("":"=r"(r1));
#else
            r1 = 0;
#endif
            if (pokemon->entityData->movementSpeed >= MAX_MOVEMENT_SPEED)
            {
                r1 = !r1;
                return FALSE;
            }
            break;
        }
        case MOVE_LOCK_ON:
        case MOVE_MIND_READER:
            if (pokemonData->moveStatus == MOVE_STATUS_SURE_SHOT)
            {
                return FALSE;
            }
            break;
        case MOVE_COSMIC_POWER:
            if (pokemonData->defenseStage >= MAX_STAT_STAGE && pokemonData->specialDefenseStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_ENDURE:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_ENDURE)
            {
                return FALSE;
            }
            break;
        case MOVE_CHARGE:
            if (pokemonData->chargingStatus == CHARGING_STATUS_CHARGE)
            {
                return FALSE;
            }
            break;
        case MOVE_MIST:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MIST)
            {
                return FALSE;
            }
            break;
        case MOVE_LIGHT_SCREEN:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_LIGHT_SCREEN)
            {
                return FALSE;
            }
            break;
        case MOVE_MINIMIZE:
            if (pokemonData->evasionStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_INGRAIN:
            if (pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_INGRAIN || pokemonData->maxHP / 2 < pokemonData->HP)
            {
                return FALSE;
            }
            break;
        case MOVE_SWALLOW:
            if (pokemonData->maxHP <= pokemonData->HP || pokemonData->stockpileCount == 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SPIT_UP:
            if (pokemonData->stockpileCount == 0)
            {
                return FALSE;
            }
            break;
        case MOVE_DOOM_DESIRE:
        case MOVE_FUTURE_SIGHT:
            if (pokemonData->moveStatus == MOVE_STATUS_SET_DAMAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BULK_UP:
            if (pokemonData->attackStage >= MAX_STAT_STAGE && pokemonData->defenseStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_CAMOUFLAGE:
            if (HasType(pokemon, gDungeonCamouflageTypes[gDungeonGlobalData->tileset]))
            {
                return FALSE;
            }
            break;
        case MOVE_TAIL_GLOW:
            if (pokemonData->specialAttackStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_DESTINY_BOND:
            if (pokemonData->linkedStatus == LINKED_STATUS_DESTINY_BOND)
            {
                return FALSE;
            }
            break;
        case MOVE_MIRROR_COAT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MIRROR_COAT)
            {
                return FALSE;
            }
            break;
        case MOVE_REFLECT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_REFLECT)
            {
                return FALSE;
            }
            break;
        case MOVE_DRAGON_DANCE:
            if (pokemonData->attackStage >= MAX_STAT_STAGE && pokemon->entityData->movementSpeed >= MAX_MOVEMENT_SPEED)
            {
                return FALSE;
            }
            break;
        case MOVE_MAGIC_COAT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MAGIC_COAT)
            {
                return FALSE;
            }
            break;
        case MOVE_DETECT:
        case MOVE_PROTECT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_PROTECT)
            {
                return FALSE;
            }
            break;
        case MOVE_RAIN_DANCE:
            if (GetWeather(pokemon) == WEATHER_RAIN)
            {
                return FALSE;
            }
            break;
        case MOVE_SANDSTORM:
            if (GetWeather(pokemon) == WEATHER_SANDSTORM)
            {
                return FALSE;
            }
            break;
        case MOVE_SUNNY_DAY:
            if (GetWeather(pokemon) == WEATHER_SUNNY)
            {
                return FALSE;
            }
            break;
        case MOVE_SAFEGUARD:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_SAFEGUARD)
            {
                return FALSE;
            }
            break;
        case MOVE_INVISIFY:
            if (pokemonData->transformStatus == TRANSFORM_STATUS_INVISIBLE)
            {
                return FALSE;
            }
            break;
        case MOVE_FOCUS_ENERGY:
            if (pokemonData->moveStatus == MOVE_STATUS_FOCUS_ENERGY)
            {
                return FALSE;
            }
            break;
        case MOVE_TAKEAWAY:
            if (pokemonData->heldItem.itemFlags & ITEM_FLAG_EXISTS)
            {
                return FALSE;
            }
            break;
        case MOVE_REST:
            if (!HasQuarterHPOrLess(pokemon) && !HasNegativeStatus(pokemon))
            {
                return FALSE;
            }
            break;
        case MOVE_DIVE:
            if (IsTileGround(GetMapTileForDungeonEntity_2(pokemon)))
            {
                return FALSE;
            }
            break;
        case MOVE_DIG:
        {
            struct MapTile *tile = GetMapTileForDungeonEntity_2(pokemon);
            if (!IsTileGround(tile) || (tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) != TILE_TYPE_FLOOR)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_TRAP_BUSTER:
        {
            struct DungeonEntity *mapObject = GetMapTileForDungeonEntity_2(pokemon)->mapObject;
            if (mapObject == NULL || GetEntityType(mapObject) != ENTITY_TRAP)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_MUD_SPORT:
            if (gDungeonGlobalData->mudSportTurnsLeft > 0)
            {
                return FALSE;
            }
            break;
        case MOVE_WATER_SPORT:
            if (gDungeonGlobalData->waterSportTurnsLeft > 0)
            {
                return FALSE;
            }
            break;
        case MOVE_GRUDGE:
            if (pokemonData->grudgeStatus)
            {
                return FALSE;
            }
            break;
        case MOVE_DECOY_MAKER:
        case MOVE_FOLLOW_ME:
        case MOVE_SUBSTITUTE:
            if (gDungeonGlobalData->decoyActive)
            {
                return FALSE;
            }
            break;
        case MOVE_STOCKPILE:
            if (pokemonData->stockpileCount >= MAX_STOCKPILE_COUNT)
            {
                return FALSE;
            }
            break;
        case MOVE_CLEANSE:
            if (pokemonData->heldItem.itemFlags & ITEM_FLAG_EXISTS &&
                !(pokemonData->heldItem.itemFlags & ITEM_FLAG_STICKY))
            {
                return FALSE;
            }
            break;
        case MOVE_DOUBLE_TEAM:
            if (pokemonData->evasionStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_GROWTH:
            if (pokemonData->specialAttackStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_SWORDS_DANCE:
            if (pokemonData->attackStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_WISH:
            if (pokemonData->isEnemy || pokemonData->protectionStatus == PROTECTION_STATUS_WISH)
            {
                return FALSE;
            }
            break;
        case MOVE_TRANSFORM:
            if (pokemonData->transformStatus == TRANSFORM_STATUS_TRANSFORMED)
            {
                return FALSE;
            }
            break;
        case MOVE_SPIKES:
            if (!CanLayTrap(&pokemon->posWorld))
            {
                return FALSE;
            }
            break;
        case MOVE_CALM_MIND:
            if (pokemonData->specialAttackStage < MAX_STAT_STAGE)
            {
                break;
            }
        case MOVE_AMNESIA:
            if (pokemonData->specialDefenseStage >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_SNATCH:
            if (pokemonData->waitingStatus == WAITING_STATUS_SNATCH)
            {
                return FALSE;
            }
            break;
        case MOVE_BEAT_UP:
        case MOVE_BLOWBACK:
        case MOVE_HURL:
        case MOVE_MEMENTO:
        case MOVE_ROAR:
        case MOVE_STAY_AWAY:
        case MOVE_SWITCHER:
        case MOVE_TELEPORT:
        case MOVE_VITAL_THROW:
        case MOVE_WARP:
        case MOVE_WHIRLWIND:
            if (IsBossBattle())
            {
                return FALSE;
            }
            break;
        case MOVE_CONVERSION_2:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_CONVERSION_2)
            {
                return FALSE;
            }
            break;
        case MOVE_HELPING_HAND:
            if (pokemonData->isEnemy)
            {
                s32 i;
                for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++)
                {
                    struct DungeonEntity *target = gDungeonGlobalData->wildPokemon[i];
                    if (EntityExists(target) && target != pokemon && CanSee(pokemon, target))
                    {
                        if (target->entityData->attackStage >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->entityData->specialAttackStage < MAX_STAT_STAGE)
                        {
                            break;
                        }
                    }
                }
                if (i == DUNGEON_MAX_WILD_POKEMON)
                {
                    return FALSE;
                }
                break;
            }
            else
            {
                s32 i;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++)
                {
                    struct DungeonEntity *target = gDungeonGlobalData->teamPokemon[i];
                    if (EntityExists(target) && target != pokemon && CanSee(pokemon, target))
                    {
                        if (target->entityData->attackStage >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->entityData->specialAttackStage < MAX_STAT_STAGE)
                        {
                            break;
                        }
                    }
                }
                if (i == MAX_TEAM_MEMBERS)
                {
                    return FALSE;
                }
                break;
            }
    }
    return TRUE;
}
