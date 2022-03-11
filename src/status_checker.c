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
#include "moves.h"
#include "number_util.h"
#include "status_checks_1.h"
#include "tile_types.h"
#include "trap.h"
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
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BELLY_DRUM:
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE || RoundUpFixedPoint(pokemonData->belly) <= 0)
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
            if (pokemonData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE)
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
            if (pokemonData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE && pokemonData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] >= MAX_STAT_STAGE)
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
            if (pokemonData->accuracyStages[STAT_STAGE_EVASION] >= MAX_STAT_STAGE)
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
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE && pokemonData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE)
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
            if (pokemonData->attackStages[STAT_STAGE_SPECIAL_ATTACK] >= MAX_STAT_STAGE)
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
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE && pokemon->entityData->movementSpeed >= MAX_MOVEMENT_SPEED)
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
            if (pokemonData->accuracyStages[STAT_STAGE_EVASION] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_GROWTH:
            if (pokemonData->attackStages[STAT_STAGE_SPECIAL_ATTACK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_SWORDS_DANCE:
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
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
            if (pokemonData->attackStages[STAT_STAGE_SPECIAL_ATTACK] < MAX_STAT_STAGE)
            {
                break;
            }
        case MOVE_AMNESIA:
            if (pokemonData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] >= MAX_STAT_STAGE)
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
                        if (target->entityData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->entityData->attackStages[STAT_STAGE_SPECIAL_ATTACK] < MAX_STAT_STAGE)
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
                        if (target->entityData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->entityData->attackStages[STAT_STAGE_SPECIAL_ATTACK] < MAX_STAT_STAGE)
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

bool8 CanUseOnTargetWithStatusChecker(struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move)
{
    struct DungeonEntityData *userData = user->entityData;
    struct DungeonEntityData *targetData = target->entityData;
    s32 i;
    if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN && MoveCannotHitFrozen(move))
    {
        return FALSE;
    }
    switch (move->moveID)
    {
        case MOVE_GRASSWHISTLE:
        case MOVE_HYPNOSIS:
        case MOVE_LOVELY_KISS:
        case MOVE_SING:
        case MOVE_SLEEP_POWDER:
        case MOVE_SPORE:
            if (IsSleeping(target))
            {
                return FALSE;
            }
            break;
        case MOVE_YAWN:
            if (targetData->sleepStatus == SLEEP_STATUS_YAWNING)
            {
                return FALSE;
            }
            if (IsSleeping(target))
            {
                return FALSE;
            }
            break;
        case MOVE_NIGHTMARE:
            if (targetData->sleepStatus == SLEEP_STATUS_NIGHTMARE)
            {
                return FALSE;
            }
            break;
        case MOVE_SWEET_SCENT:
            if (targetData->accuracyStages[STAT_STAGE_EVASION] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_CHARM:
            if (targetData->attackMultipliers[STAT_STAGE_ATTACK] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_ENCORE:
            if (targetData->volatileStatus == VOLATILE_STATUS_ENCORE)
            {
                return FALSE;
            }
            if (!HasLastUsedMove(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_SUPER_FANG:
            if (targetData->HP <= 1)
            {
                return FALSE;
            }
            break;
        case MOVE_PAIN_SPLIT:
            if (targetData->HP <= userData->HP)
            {
                return FALSE;
            }
            break;
        case MOVE_TORMENT:
            if (HasDisabledMove(targetData->moves) || !HasLastUsedMove(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_COTTON_SPORE:
        case MOVE_SCARY_FACE:
        case MOVE_STRING_SHOT:
            if (target->entityData->movementSpeed <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SCREECH:
            if (targetData->defenseMultipliers[STAT_STAGE_DEFENSE] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_FAKE_TEARS:
            if (targetData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SPITE:
            if (LastUsedMoveOutOfPP(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_SMOKESCREEN:
            if (targetData->moveStatus == MOVE_STATUS_WHIFFER)
            {
                return FALSE;
            }
            break;
        case MOVE_MEMENTO:
            if (targetData->attackMultipliers[STAT_STAGE_ATTACK] < STAT_MULTIPLIER_THRESHOLD &&
                targetData->attackMultipliers[STAT_STAGE_SPECIAL_ATTACK] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_WILL_O_WISP:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_BURNED)
            {
                return FALSE;
            }
            break;
        case MOVE_FORESIGHT:
        case MOVE_ODOR_SLEUTH:
            if (targetData->types[0] == TYPE_GHOST || targetData->types[1] == TYPE_GHOST)
            {
                if (!targetData->exposedStatus)
                {
                    break;
                }
            }
            if (targetData->accuracyStages[STAT_STAGE_EVASION] <= DEFAULT_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_DISABLE:
        case MOVE_GLARE:
        case MOVE_STUN_SPORE:
        case MOVE_THUNDER_WAVE:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_PARALYZED)
            {
                return FALSE;
            }
            break;
        case MOVE_ENDEAVOR:
            if (targetData->HP - userData->HP <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_LEER:
        case MOVE_TAIL_WHIP:
            if (targetData->defenseStages[STAT_STAGE_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_METAL_SOUND:
            if (targetData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_TICKLE:
            if (targetData->attackStages[STAT_STAGE_ATTACK] <= 0 &&
                targetData->defenseStages[STAT_STAGE_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_BLOCK:
        case MOVE_MEAN_LOOK:
        case MOVE_SPIDER_WEB:
            if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_IMMOBILIZED)
            {
                return FALSE;
            }
            break;
        case MOVE_HAZE:
        {
            for (i = 0; i < 2; i++)
            {
                if (targetData->attackStages[i] < DEFAULT_STAT_STAGE) break;
                if (targetData->defenseStages[i] < DEFAULT_STAT_STAGE) break;
                if (targetData->accuracyStages[i] < DEFAULT_STAT_STAGE ||
                    targetData->attackMultipliers[i] < DEFAULT_STAT_MULTIPLIER ||
                    targetData->defenseMultipliers[i] < DEFAULT_STAT_MULTIPLIER)
                {
                    break;
                }
            }
            if (i == 2)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_UPROAR:
            if (targetData->sleepStatus == SLEEP_STATUS_SLEEPLESS)
            {
                return FALSE;
            }
            break;
        case MOVE_PSYCH_UP:
        {
            for (i = 0; i < 2; i++)
            {
                if (userData->attackStages[i] < targetData->attackStages[i]) break;
                if (userData->defenseStages[i] < targetData->defenseStages[i] ||
                    userData->accuracyStages[i] < targetData->accuracyStages[i] ||
                    userData->attackMultipliers[i] < targetData->attackMultipliers[i] ||
                    userData->defenseMultipliers[i] < targetData->defenseMultipliers[i])
                {
                    break;
                }
            }
            if (i == 2)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_FLASH:
        case MOVE_KINESIS:
        case MOVE_SAND_ATTACK:
            if (targetData->accuracyStages[STAT_STAGE_ACCURACY] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_TAUNT:
            if (targetData->volatileStatus == VOLATILE_STATUS_TAUNTED)
            {
                return FALSE;
            }
            break;
        case MOVE_TRICK:
            if (!(userData->heldItem.itemFlags & ITEM_FLAG_EXISTS) ||
                !(targetData->heldItem.itemFlags & ITEM_FLAG_EXISTS))
            {
                return FALSE;
            }
            break;
        case MOVE_KNOCK_OFF:
            if (!(targetData->heldItem.itemFlags & ITEM_FLAG_EXISTS))
            {
                return FALSE;
            }
            break;
        case MOVE_FEATHERDANCE:
        case MOVE_GROWL:
            if (targetData->attackStages[STAT_STAGE_ATTACK] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_ROLE_PLAY:
            if (userData->abilities[0] == targetData->abilities[0] &&
                userData->abilities[1] == targetData->abilities[1])
            {
                return FALSE;
            }
            break;
        case MOVE_CURSE:
            if (HasType(user, TYPE_GHOST))
            {
                if (targetData->waitingStatus == WAITING_STATUS_CURSED)
                {
                    return FALSE;
                }
            }
            else
            {
                if (userData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE &&
                    userData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE)
                {
                    return FALSE;
                }
            }
            break;
        case MOVE_IMPRISON:
        case MOVE_OBSERVER:
            if (targetData->volatileStatus == VOLATILE_STATUS_PAUSED)
            {
                return FALSE;
            }
            break;
        case MOVE_FALSE_SWIPE:
            if (targetData->HP <= 1)
            {
                return FALSE;
            }
            break;
        case MOVE_LEECH_SEED:
            if (targetData->linkedStatus == LINKED_STATUS_LEECH_SEED)
            {
                return FALSE;
            }
            break;
        case MOVE_PERISH_SONG:
            if (targetData->perishSongTimer != 0)
            {
                return FALSE;
            }
            break;
        case MOVE_MIMIC:
        case MOVE_SKETCH:
            if (!HasLastUsedMove(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_ATTRACT:
            if (targetData->volatileStatus == VOLATILE_STATUS_INFATUATED)
            {
                return FALSE;
            }
            break;
        case MOVE_WRAP:
            if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE)
            {
                return FALSE;
            }
            if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_BY_FOE)
            {
                return FALSE;
            }
            break;
        case MOVE_TOXIC:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                return FALSE;
            }
            break;
        case MOVE_POISON_GAS:
        case MOVE_POISONPOWDER:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_POISONED)
            {
                return FALSE;
            }
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                return FALSE;
            }
            break;
        case MOVE_CONFUSE_RAY:
        case MOVE_FLATTER:
        case MOVE_SUPERSONIC:
        case MOVE_SWAGGER:
        case MOVE_SWEET_KISS:
        case MOVE_TEETER_DANCE:
        case MOVE_TOTTER:
            if (targetData->volatileStatus == VOLATILE_STATUS_CONFUSED)
            {
                return FALSE;
            }
            break;
    }
    return TRUE;
}

bool8 HasDisabledMove(struct PokemonMove *moves)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags & MOVE_FLAG_DISABLED)
        {
            return TRUE;
        }
    }
    if (moves[STRUGGLE_MOVE_INDEX].moveFlags & MOVE_FLAG_DISABLED)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 LastUsedMoveOutOfPP(struct PokemonMove *moves)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS &&
            moves[i].moveFlags & MOVE_FLAG_LAST_USED &&
            moves[i].PP == 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 HasLastUsedMove(struct PokemonMove *moves)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags & MOVE_FLAG_LAST_USED)
        {
            return TRUE;
        }
    }
    if (moves[STRUGGLE_MOVE_INDEX].moveFlags & MOVE_FLAG_LAST_USED)
    {
        return TRUE;
    }
    return FALSE;
}
