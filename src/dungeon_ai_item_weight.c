#include "global.h"
#include "dungeon_ai_item_weight.h"

#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "moves.h"
#include "number_util.h"
#include "status_checks_1.h"

u32 GetAIUseItemProbability(Entity *targetPokemon, Item *item, u32 itemTargetFlags)
{
    EntityInfo *pokemonInfo = targetPokemon->axObj.info;
    s32 itemWeight = 0;
    bool8 targetOther = itemTargetFlags & 1;
    u16 targetAlly = (itemTargetFlags >> 1) & 1;
    s32 i;
    Move *move;
    Move *move2;
    switch (item->id)
    {
        case ITEM_STICK:
        case ITEM_IRON_THORN:
        case ITEM_SILVER_SPIKE:
        case ITEM_GOLD_FANG:
        case ITEM_CACNEA_SPIKE:
        case ITEM_CORSOLA_TWIG:
        case ITEM_GRAVELEROCK:
        case ITEM_GEO_PEBBLE:
            if (targetOther)
            {
                itemWeight = 70;
            }
            break;
        case ITEM_DIET_RIBBON:
            if (targetOther && FixedPointToInt(pokemonInfo->belly) > 0)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_WHIFF_SPECS:
        case ITEM_NO_AIM_SCOPE:
            if (targetOther)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ORAN_BERRY:
        case ITEM_SITRUS_BERRY:
            if (pokemonInfo->HP < pokemonInfo->maxHPStat && pokemonInfo->HP <= pokemonInfo->maxHPStat / 4)
            {
                if (!targetOther)
                {
                    if (IsAdjacentToEnemy(targetPokemon))
                    {
                        itemWeight = 100;
                    }
                    else
                    {
                        itemWeight = 50;
                    }
                }
                else
                {
                    itemWeight = 50;
                }
            }
            break;
        case ITEM_MAX_ELIXIR:
            itemWeight = 0;
            move = pokemonInfo->moves;
            move2 = move;
            for (i = 0; i < MAX_MON_MOVES; move++, move2++, i++)
            {
                if (move->moveFlags & MOVE_FLAG_EXISTS)
                {
                    if (move->PP == 0)
                    {
                        itemWeight += 30;
                    }
                    if (move->PP != GetMoveBasePP(move2))
                    {
                        itemWeight += 6;
                    }
                }
            }
            if (itemWeight >= 99)
            {
                itemWeight = 99;
            }
            break;
        case ITEM_HEAL_SEED:
            if (HasNegativeStatus(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_PROTEIN:
            if (pokemonInfo->atk > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_CALCIUM:
            if (pokemonInfo->spAtk > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_IRON:
            if (pokemonInfo->def > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ZINC:
            if (pokemonInfo->spDef > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_LIFE_SEED:
            if (!targetOther)
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 10;
                }
                else
                {
                    itemWeight = 100;
                }
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_EYEDROP_SEED:
            if (!CanSeeInvisibleMonsters(targetPokemon))
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_QUICK_SEED:
            if (targetPokemon->axObj.info->speedStage < MAX_SPEED_STAGE)
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ALLURE_SEED:
            if (pokemonInfo->eyesightStatus.eyesightStatus != STATUS_CROSS_EYED)
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_CHERI_BERRY:
            if (pokemonInfo->nonVolatile.nonVolatileStatus != STATUS_PARALYSIS)
            {
                return 0;
            }
            else if (IsAdjacentToEnemy(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 30;
            }
            break;
        case ITEM_TOTTER_SEED:
            if (pokemonInfo->volatileStatus.volatileStatus != STATUS_CONFUSED)
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 15;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_PECHA_BERRY:
            if (pokemonInfo->nonVolatile.nonVolatileStatus != STATUS_POISONED &&
                pokemonInfo->nonVolatile.nonVolatileStatus != STATUS_BADLY_POISONED)
            {
                return 0;
            }
            else if (IsAdjacentToEnemy(targetPokemon))
            {
                itemWeight = 100;
            }
            else
            {
                itemWeight = 50;
            }
            break;
        case ITEM_BLINKER_SEED:
            if (pokemonInfo->eyesightStatus.eyesightStatus != STATUS_BLINKER)
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_WARP_SEED:
            if (!targetAlly)
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 40;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else if (pokemonInfo->HP < pokemonInfo->maxHPStat && pokemonInfo->HP < 20)
            {
                if (!targetOther)
                {
                    if (IsAdjacentToEnemy(targetPokemon))
                    {
                        itemWeight = 100;
                    }
                    else
                    {
                        itemWeight = 50;
                    }
                }
                else
                {
                    itemWeight = 50;
                }
            }
            break;
        case ITEM_PATSY_BAND:
            itemWeight = 40;
            break;
        case ITEM_SLEEP_SEED:
            if (pokemonInfo->sleep.sleep != STATUS_SLEEP &&
                pokemonInfo->sleep.sleep != STATUS_NAPPING &&
                pokemonInfo->sleep.sleep != STATUS_NIGHTMARE)
            {
                if (IsAdjacentToEnemy(targetPokemon))
                {
                    itemWeight = 80;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_CHESTO_BERRY:
            if (pokemonInfo->sleep.sleep != STATUS_SLEEPLESS)
            {
                itemWeight = 5;
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_JOY_SEED:
            if (pokemonInfo->level < 99)
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_GINSENG:
            itemWeight = 80;
            break;
        case ITEM_RAWST_BERRY:
            if (pokemonInfo->nonVolatile.nonVolatileStatus == STATUS_BURN)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_HUNGER_SEED:
            if (FixedPointToInt(pokemonInfo->belly) > 0)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_DOOM_SEED:
            if (pokemonInfo->level > 1)
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_STUN_SEED:
            if (pokemonInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED)
            {
                return 0;
            }
            else if (IsAdjacentToEnemy(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 5;
            }
            break;
        case ITEM_BLAST_SEED:
            if (IsAdjacentToEnemy(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 30;
            }
            break;
        case ITEM_APPLE:
        case ITEM_BIG_APPLE:
        case ITEM_HUGE_APPLE:
            if (FixedPointToInt(pokemonInfo->belly) < 10)
            {
                return 100;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_GRIMY_FOOD:
            itemWeight = 30;
            break;
        case ITEM_ROLLCALL_ORB:
            move = pokemonInfo->moves; // Fixes a regswap.
            if (targetOther)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 20;
            }
            break;
        default:
            itemWeight = 0;
    }
    return itemWeight;
}

bool8 IsAdjacentToEnemy(Entity *pokemon)
{
    s32 direction;
    for (direction = 0; direction < NUM_DIRECTIONS; direction++)
    {
        struct Tile *mapTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
        Entity *adjacentPokemon = mapTile->monster;
        if (adjacentPokemon != NULL && GetEntityType(adjacentPokemon) != ENTITY_NOTHING &&
            GetTreatmentBetweenMonsters(pokemon, adjacentPokemon, FALSE, TRUE) == TREATMENT_TREAT_AS_ENEMY)
        {
            return TRUE;
        }
    }
    return FALSE;
}
