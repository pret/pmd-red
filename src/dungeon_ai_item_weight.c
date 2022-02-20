#include "global.h"
#include "dungeon_ai_item_weight.h"

#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_ai_1.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "moves.h"
#include "number_util.h"
#include "status_checks_1.h"

u32 EvaluateItem(struct DungeonEntity *targetPokemon, struct ItemSlot *item, u32 itemTargetFlags)
{
    struct DungeonEntityData *pokemonData = targetPokemon->entityData;
    s32 itemWeight = 0;
    bool8 targetOther = itemTargetFlags & 1;
    u16 targetAlly = (itemTargetFlags >> 1) & 1;
    s32 i;
    struct PokemonMove *move;
    struct PokemonMove *move2;
    switch (item->itemIndex)
    {
        case ITEM_ID_STICK:
        case ITEM_ID_IRON_THORN:
        case ITEM_ID_SILVER_SPIKE:
        case ITEM_ID_GOLD_FANG:
        case ITEM_ID_CACNEA_SPIKE:
        case ITEM_ID_CORSOLA_TWIG:
        case ITEM_ID_GRAVELEROCK:
        case ITEM_ID_GEO_PEBBLE:
            if (targetOther)
            {
                itemWeight = 70;
            }
            break;
        case ITEM_ID_DIET_RIBBON:
            if (targetOther && RoundUpFixedPoint(pokemonData->belly) > 0)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_WHIFF_SPECS:
        case ITEM_ID_NO_AIM_SCOPE:
            if (targetOther)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_ORAN_BERRY:
        case ITEM_ID_SITRUS_BERRY:
            if (pokemonData->HP < pokemonData->maxHP && pokemonData->HP <= pokemonData->maxHP / 4)
            {
                if (!targetOther)
                {
                    if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_MAX_ELIXIR:
            itemWeight = 0;
            move = pokemonData->moves;
            move2 = move;
            for (i = 0; i < MAX_MON_MOVES; move++, move2++, i++)
            {
                if (move->moveFlags & MOVE_FLAG_EXISTS)
                {
                    if (move->PP == 0)
                    {
                        itemWeight += 30;
                    }
                    if (move->PP != GetMoveMaxPP(move2))
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
        case ITEM_ID_HEAL_SEED:
            if (HasNegativeStatus(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_PROTEIN:
            if (pokemonData->attack > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_CALCIUM:
            if (pokemonData->specialAttack > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_IRON:
            if (pokemonData->defense > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_ZINC:
            if (pokemonData->specialDefense > 249)
            {
                itemWeight = 0;
            }
            else
            {
                itemWeight = 100;
            }
            break;
        case ITEM_ID_LIFE_SEED:
            if (!targetOther)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_EYEDROP_SEED:
            if (!CanSeeInvisible(targetPokemon))
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_QUICK_SEED:
            if (targetPokemon->entityData->movementSpeed < MAX_MOVEMENT_SPEED)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_ALLURE_SEED:
            if (pokemonData->eyesightStatus != EYESIGHT_STATUS_CROSS_EYED)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_CHERI_BERRY:
            if (pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_PARALYZED)
            {
                return 0;
            }
            else if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 30;
            }
            break;
        case ITEM_ID_TOTTER_SEED:
            if (pokemonData->volatileStatus != VOLATILE_STATUS_CONFUSED)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_PECHA_BERRY:
            if (pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_POISONED &&
                pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                return 0;
            }
            else if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 100;
            }
            else
            {
                itemWeight = 50;
            }
            break;
        case ITEM_ID_BLINKER_SEED:
            if (pokemonData->eyesightStatus != EYESIGHT_STATUS_BLINKER)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_WARP_SEED:
            if (!targetAlly)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
                {
                    itemWeight = 40;
                }
                else
                {
                    itemWeight = 5;
                }
            }
            else if (pokemonData->HP < pokemonData->maxHP && pokemonData->HP < 20)
            {
                if (!targetOther)
                {
                    if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_PATSY_BAND:
            itemWeight = 40;
            break;
        case ITEM_ID_SLEEP_SEED:
            if (pokemonData->sleepStatus != SLEEP_STATUS_SLEEP &&
                pokemonData->sleepStatus != SLEEP_STATUS_NAPPING &&
                pokemonData->sleepStatus != SLEEP_STATUS_NIGHTMARE)
            {
                if (CanTargetAdjacentPokemon(targetPokemon))
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
        case ITEM_ID_CHESTO_BERRY:
            if (pokemonData->sleepStatus != SLEEP_STATUS_SLEEPLESS)
            {
                itemWeight = 5;
            }
            else
            {
                return 0;
            }
            break;
        case ITEM_ID_JOY_SEED:
            if (pokemonData->level < 99)
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_GINSENG:
            itemWeight = 80;
            break;
        case ITEM_ID_RAWST_BERRY:
            if (pokemonData->nonVolatileStatus == NON_VOLATILE_STATUS_BURNED)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_HUNGER_SEED:
            if (RoundUpFixedPoint(pokemonData->belly) > 0)
            {
                return 50;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_DOOM_SEED:
            if (pokemonData->level > 1)
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_STUN_SEED:
            if (pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED)
            {
                return 0;
            }
            else if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 5;
            }
            break;
        case ITEM_ID_BLAST_SEED:
            if (CanTargetAdjacentPokemon(targetPokemon))
            {
                itemWeight = 80;
            }
            else
            {
                itemWeight = 30;
            }
            break;
        case ITEM_ID_APPLE:
        case ITEM_ID_BIG_APPLE:
        case ITEM_ID_HUGE_APPLE:
            if (RoundUpFixedPoint(pokemonData->belly) < 10)
            {
                return 100;
            }
            else
            {
                itemWeight = 0;
            }
            break;
        case ITEM_ID_GRIMY_FOOD:
            itemWeight = 30;
            break;
        case ITEM_ID_ROLLCALL_ORB:
            move = pokemonData->moves; // Fixes a regswap.
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

bool8 CanTargetAdjacentPokemon(struct DungeonEntity *pokemon)
{
    s32 facingDir;
    for (facingDir = 0; facingDir < NUM_DIRECTIONS; facingDir++)
    {
        struct MapTile *mapTile = GetMapTileAtPosition(pokemon->posWorld.x + gAdjacentTileOffsets[facingDir].x, pokemon->posWorld.y + gAdjacentTileOffsets[facingDir].y);
        struct DungeonEntity *adjacentPokemon = mapTile->pokemon;
        if (adjacentPokemon != NULL && GetEntityType(adjacentPokemon) != ENTITY_NONE &&
            CanTarget(pokemon, adjacentPokemon, FALSE, TRUE) == TARGET_CAPABILITY_CAN_TARGET)
        {
            return TRUE;
        }
    }
    return FALSE;
}
