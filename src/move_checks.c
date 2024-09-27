#include "global.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "structs/str_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "move_checks.h"
#include "moves.h"
#include "number_util.h"
#include "status.h"
#include "status_actions.h"
#include "status_checks_1.h"

#include "text_util.h"
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


bool8 CanUseOnSelfWithStatusChecker(Entity *pokemon, Move *move)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    switch (move->id)
    {
        case MOVE_HAIL:
            if (GetApparentWeather(pokemon) == WEATHER_HAIL)
            {
                return FALSE;
            }
            break;
        case MOVE_RAGE:
            if (pokemonInfo->charging.chargingStatus == STATUS_ENRAGED)
            {
                return FALSE;
            }
            break;
        case MOVE_COUNTER:
        case MOVE_PURSUIT:
            if (pokemonInfo->protection.protectionStatus == STATUS_COUNTER)
            {
                return FALSE;
            }
            break;
        case MOVE_MIRROR_MOVE:
            if (pokemonInfo->protection.protectionStatus == STATUS_MIRROR_MOVE)
            {
                return FALSE;
            }
            break;
        case MOVE_HOWL:
        case MOVE_MEDITATE:
        case MOVE_SHARPEN:
            if (pokemonInfo->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BELLY_DRUM:
            if (pokemonInfo->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE || FixedPointToInt(pokemonInfo->belly) <= 0)
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
            if (pokemonInfo->defensiveStages[STAT_STAGE_DEF] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BIDE:
        case MOVE_REVENGE:
            if (pokemonInfo->charging.chargingStatus == STATUS_BIDE)
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
            if (pokemon->axObj.info->speedStage >= MAX_SPEED_STAGE)
            {
                r1 = !r1;
                return FALSE;
            }
            break;
        }
        case MOVE_LOCK_ON:
        case MOVE_MIND_READER:
            if (pokemonInfo->moveStatus.moveStatus == STATUS_SURE_SHOT)
            {
                return FALSE;
            }
            break;
        case MOVE_COSMIC_POWER:
            if (pokemonInfo->defensiveStages[STAT_STAGE_DEF] >= MAX_STAT_STAGE && pokemonInfo->defensiveStages[STAT_STAGE_SP_DEF] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_ENDURE:
            if (pokemonInfo->protection.protectionStatus == STATUS_ENDURING)
            {
                return FALSE;
            }
            break;
        case MOVE_CHARGE:
            if (pokemonInfo->charging.chargingStatus == STATUS_CHARGING)
            {
                return FALSE;
            }
            break;
        case MOVE_MIST:
            if (pokemonInfo->protection.protectionStatus == STATUS_MIST)
            {
                return FALSE;
            }
            break;
        case MOVE_LIGHT_SCREEN:
            if (pokemonInfo->protection.protectionStatus == STATUS_LIGHT_SCREEN)
            {
                return FALSE;
            }
            break;
        case MOVE_MINIMIZE:
            if (pokemonInfo->hitChanceStages[STAT_STAGE_EVASION] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_INGRAIN:
            if (pokemonInfo->immobilize.immobilizeStatus == STATUS_INGRAIN || pokemonInfo->maxHPStat / 2 < pokemonInfo->HP)
            {
                return FALSE;
            }
            break;
        case MOVE_SWALLOW:
            if (pokemonInfo->maxHPStat <= pokemonInfo->HP || pokemonInfo->stockpileStage == 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SPIT_UP:
            if (pokemonInfo->stockpileStage == 0)
            {
                return FALSE;
            }
            break;
        case MOVE_DOOM_DESIRE:
        case MOVE_FUTURE_SIGHT:
            if (pokemonInfo->moveStatus.moveStatus == STATUS_SET_DAMAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BULK_UP:
            if (pokemonInfo->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE && pokemonInfo->defensiveStages[STAT_STAGE_DEF] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_CAMOUFLAGE:
            if (MonsterIsType(pokemon, gDungeonCamouflageTypes[gDungeon->tileset]))
            {
                return FALSE;
            }
            break;
        case MOVE_TAIL_GLOW:
            if (pokemonInfo->offensiveStages[STAT_STAGE_SP_ATK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_DESTINY_BOND:
            if (pokemonInfo->linked.linkedStatus == STATUS_DESTINY_BOND)
            {
                return FALSE;
            }
            break;
        case MOVE_MIRROR_COAT:
            if (pokemonInfo->protection.protectionStatus == STATUS_MIRROR_COAT)
            {
                return FALSE;
            }
            break;
        case MOVE_REFLECT:
            if (pokemonInfo->protection.protectionStatus == STATUS_REFLECT)
            {
                return FALSE;
            }
            break;
        case MOVE_DRAGON_DANCE:
            if (pokemonInfo->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE && pokemon->axObj.info->speedStage >= MAX_SPEED_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_MAGIC_COAT:
            if (pokemonInfo->protection.protectionStatus == STATUS_MAGIC_COAT)
            {
                return FALSE;
            }
            break;
        case MOVE_DETECT:
        case MOVE_PROTECT:
            if (pokemonInfo->protection.protectionStatus == STATUS_PROTECT)
            {
                return FALSE;
            }
            break;
        case MOVE_RAIN_DANCE:
            if (GetApparentWeather(pokemon) == WEATHER_RAIN)
            {
                return FALSE;
            }
            break;
        case MOVE_SANDSTORM:
            if (GetApparentWeather(pokemon) == WEATHER_SANDSTORM)
            {
                return FALSE;
            }
            break;
        case MOVE_SUNNY_DAY:
            if (GetApparentWeather(pokemon) == WEATHER_SUNNY)
            {
                return FALSE;
            }
            break;
        case MOVE_SAFEGUARD:
            if (pokemonInfo->protection.protectionStatus == STATUS_SAFEGUARD)
            {
                return FALSE;
            }
            break;
        case MOVE_INVISIFY:
            if (pokemonInfo->transformStatus.transformStatus == STATUS_INVISIBLE)
            {
                return FALSE;
            }
            break;
        case MOVE_FOCUS_ENERGY:
            if (pokemonInfo->moveStatus.moveStatus == STATUS_FOCUS_ENERGY)
            {
                return FALSE;
            }
            break;
        case MOVE_TAKEAWAY:
            if (pokemonInfo->heldItem.flags & ITEM_FLAG_EXISTS)
            {
                return FALSE;
            }
            break;
        case MOVE_REST:
            if (!HasLowHealth(pokemon) && !HasNegativeStatus(pokemon))
            {
                return FALSE;
            }
            break;
        case MOVE_DIVE:
            if (IsTileGround(GetTileAtEntitySafe(pokemon)))
            {
                return FALSE;
            }
            break;
        case MOVE_DIG:
        {
            struct Tile *tile = GetTileAtEntitySafe(pokemon);
            if (!IsTileGround(tile) || (tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_NORMAL)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_TRAP_BUSTER:
        {
            Entity *object = GetTileAtEntitySafe(pokemon)->object;
            if (object == NULL || GetEntityType(object) != ENTITY_TRAP)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_MUD_SPORT:
            if (gDungeon->weather.mudSportTurns > 0)
            {
                return FALSE;
            }
            break;
        case MOVE_WATER_SPORT:
            if (gDungeon->weather.waterSportTurns > 0)
            {
                return FALSE;
            }
            break;
        case MOVE_GRUDGE:
            if (pokemonInfo->grudge)
            {
                return FALSE;
            }
            break;
        case MOVE_DECOY_MAKER:
        case MOVE_FOLLOW_ME:
        case MOVE_SUBSTITUTE:
            if (gDungeon->decoyActive)
            {
                return FALSE;
            }
            break;
        case MOVE_STOCKPILE:
            if (pokemonInfo->stockpileStage >= MAX_STOCKPILE_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_CLEANSE:
            if (pokemonInfo->heldItem.flags & ITEM_FLAG_EXISTS &&
                !(pokemonInfo->heldItem.flags & ITEM_FLAG_STICKY))
            {
                return FALSE;
            }
            break;
        case MOVE_DOUBLE_TEAM:
            if (pokemonInfo->hitChanceStages[STAT_STAGE_EVASION] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_GROWTH:
            if (pokemonInfo->offensiveStages[STAT_STAGE_SP_ATK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_SWORDS_DANCE:
            if (pokemonInfo->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_WISH:
            if (pokemonInfo->isNotTeamMember || pokemonInfo->protection.protectionStatus == STATUS_WISH)
            {
                return FALSE;
            }
            break;
        case MOVE_TRANSFORM:
            if (pokemonInfo->transformStatus.transformStatus == STATUS_TRANSFORMED)
            {
                return FALSE;
            }
            break;
        case MOVE_SPIKES:
            if (!CanLayTrap(&pokemon->pos))
            {
                return FALSE;
            }
            break;
        case MOVE_CALM_MIND:
            if (pokemonInfo->offensiveStages[STAT_STAGE_SP_ATK] < MAX_STAT_STAGE)
            {
                break;
            }
        case MOVE_AMNESIA:
            if (pokemonInfo->defensiveStages[STAT_STAGE_SP_DEF] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_SNATCH:
            if (pokemonInfo->waitingStruct.waitingStatus == STATUS_SNATCH)
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
            if (IsBossFight())
            {
                return FALSE;
            }
            break;
        case MOVE_CONVERSION_2:
            if (pokemonInfo->protection.protectionStatus == STATUS_CONVERSION2)
            {
                return FALSE;
            }
            break;
        case MOVE_HELPING_HAND:
            if (pokemonInfo->isNotTeamMember)
            {
                s32 i;
                for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++)
                {
                    Entity *target = gDungeon->wildPokemon[i];
                    if (EntityExists(target) && target != pokemon && CanSeeTarget(pokemon, target))
                    {
                        if (target->axObj.info->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->axObj.info->offensiveStages[STAT_STAGE_SP_ATK] < MAX_STAT_STAGE)
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
                    Entity *target = gDungeon->teamPokemon[i];
                    if (EntityExists(target) && target != pokemon && CanSeeTarget(pokemon, target))
                    {
                        if (target->axObj.info->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->axObj.info->offensiveStages[STAT_STAGE_SP_ATK] < MAX_STAT_STAGE)
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

bool8 CanUseOnTargetWithStatusChecker(Entity *user, Entity *target, Move *move)
{
    EntityInfo *userData = user->axObj.info;
    EntityInfo *targetData = target->axObj.info;
    s32 i;
    if (targetData->immobilize.immobilizeStatus == STATUS_FROZEN && MoveCannotHitFrozen(move))
    {
        return FALSE;
    }
    switch (move->id)
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
            if (targetData->sleep.sleep == STATUS_YAWNING)
            {
                return FALSE;
            }
            if (IsSleeping(target))
            {
                return FALSE;
            }
            break;
        case MOVE_NIGHTMARE:
            if (targetData->sleep.sleep == STATUS_NIGHTMARE)
            {
                return FALSE;
            }
            break;
        case MOVE_SWEET_SCENT:
            if (targetData->hitChanceStages[STAT_STAGE_EVASION] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_CHARM:
            if (targetData->offensiveMultipliers[STAT_STAGE_ATK] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_ENCORE:
            if (targetData->volatileStatus.volatileStatus == STATUS_ENCORE)
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
            if (target->axObj.info->speedStage <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SCREECH:
            if (targetData->defensiveMultipliers[STAT_STAGE_DEF] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_FAKE_TEARS:
            if (targetData->defensiveStages[STAT_STAGE_SP_DEF] <= 0)
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
            if (targetData->moveStatus.moveStatus == STATUS_WHIFFER)
            {
                return FALSE;
            }
            break;
        case MOVE_MEMENTO:
            if (targetData->offensiveMultipliers[STAT_STAGE_ATK] < STAT_MULTIPLIER_THRESHOLD &&
                targetData->offensiveMultipliers[STAT_STAGE_SP_ATK] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_WILL_O_WISP:
            if (targetData->nonVolatile.nonVolatileStatus == STATUS_BURN)
            {
                return FALSE;
            }
            break;
        case MOVE_FORESIGHT:
        case MOVE_ODOR_SLEUTH:
            if (targetData->types[0] == TYPE_GHOST || targetData->types[1] == TYPE_GHOST)
            {
                if (!targetData->exposed)
                {
                    break;
                }
            }
            if (targetData->hitChanceStages[STAT_STAGE_EVASION] <= DEFAULT_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_DISABLE:
        case MOVE_GLARE:
        case MOVE_STUN_SPORE:
        case MOVE_THUNDER_WAVE:
            if (targetData->nonVolatile.nonVolatileStatus == STATUS_PARALYSIS)
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
            if (targetData->defensiveStages[STAT_STAGE_DEF] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_METAL_SOUND:
            if (targetData->defensiveStages[STAT_STAGE_SP_DEF] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_TICKLE:
            if (targetData->offensiveStages[STAT_STAGE_ATK] <= 0 &&
                targetData->defensiveStages[STAT_STAGE_DEF] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_BLOCK:
        case MOVE_MEAN_LOOK:
        case MOVE_SPIDER_WEB:
            if (targetData->immobilize.immobilizeStatus == STATUS_SHADOW_HOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_HAZE:
        {
            for (i = 0; i < 2; i++)
            {
                if (targetData->offensiveStages[i] < DEFAULT_STAT_STAGE) break;
                if (targetData->defensiveStages[i] < DEFAULT_STAT_STAGE) break;
                if (targetData->hitChanceStages[i] < DEFAULT_STAT_STAGE ||
                    targetData->offensiveMultipliers[i] < DEFAULT_STAT_MULTIPLIER ||
                    targetData->defensiveMultipliers[i] < DEFAULT_STAT_MULTIPLIER)
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
            if (targetData->sleep.sleep == STATUS_SLEEPLESS)
            {
                return FALSE;
            }
            break;
        case MOVE_PSYCH_UP:
        {
            for (i = 0; i < 2; i++)
            {
                if (userData->offensiveStages[i] < targetData->offensiveStages[i]) break;
                if (userData->defensiveStages[i] < targetData->defensiveStages[i] ||
                    userData->hitChanceStages[i] < targetData->hitChanceStages[i] ||
                    userData->offensiveMultipliers[i] < targetData->offensiveMultipliers[i] ||
                    userData->defensiveMultipliers[i] < targetData->defensiveMultipliers[i])
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
            if (targetData->hitChanceStages[STAT_STAGE_ACCURACY] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_TAUNT:
            if (targetData->volatileStatus.volatileStatus == STATUS_TAUNTED)
            {
                return FALSE;
            }
            break;
        case MOVE_TRICK:
            if (!(userData->heldItem.flags & ITEM_FLAG_EXISTS) ||
                !(targetData->heldItem.flags & ITEM_FLAG_EXISTS))
            {
                return FALSE;
            }
            break;
        case MOVE_KNOCK_OFF:
            if (!(targetData->heldItem.flags & ITEM_FLAG_EXISTS))
            {
                return FALSE;
            }
            break;
        case MOVE_FEATHERDANCE:
        case MOVE_GROWL:
            if (targetData->offensiveStages[STAT_STAGE_ATK] <= 0)
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
            if (MonsterIsType(user, TYPE_GHOST))
            {
                if (targetData->waitingStruct.waitingStatus == STATUS_CURSED)
                {
                    return FALSE;
                }
            }
            else
            {
                if (userData->offensiveStages[STAT_STAGE_ATK] >= MAX_STAT_STAGE &&
                    userData->defensiveStages[STAT_STAGE_DEF] >= MAX_STAT_STAGE)
                {
                    return FALSE;
                }
            }
            break;
        case MOVE_IMPRISON:
        case MOVE_OBSERVER:
            if (targetData->volatileStatus.volatileStatus == STATUS_PAUSED)
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
            if (targetData->linked.linkedStatus == STATUS_LEECH_SEED)
            {
                return FALSE;
            }
            break;
        case MOVE_PERISH_SONG:
            if (targetData->perishSongTurns != 0)
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
            if (targetData->volatileStatus.volatileStatus == STATUS_INFATUATED)
            {
                return FALSE;
            }
            break;
        case MOVE_WRAP:
            if (targetData->immobilize.immobilizeStatus == STATUS_WRAP)
            {
                return FALSE;
            }
            if (targetData->immobilize.immobilizeStatus == STATUS_WRAPPED)
            {
                return FALSE;
            }
            break;
        case MOVE_TOXIC:
            if (targetData->nonVolatile.nonVolatileStatus == STATUS_BADLY_POISONED)
            {
                return FALSE;
            }
            break;
        case MOVE_POISON_GAS:
        case MOVE_POISONPOWDER:
            if (targetData->nonVolatile.nonVolatileStatus == STATUS_POISONED)
            {
                return FALSE;
            }
            if (targetData->nonVolatile.nonVolatileStatus == STATUS_BADLY_POISONED)
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
            if (targetData->volatileStatus.volatileStatus == STATUS_CONFUSED)
            {
                return FALSE;
            }
            break;
    }
    return TRUE;
}

bool8 HasDisabledMove(Move *moves)
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

bool8 LastUsedMoveOutOfPP(Move *moves)
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

bool8 HasLastUsedMove(Move *moves)
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
