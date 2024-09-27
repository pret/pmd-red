#include "global.h"
#include "dungeon_ai.h"

#include "code_803E668.h"
#include "code_8045A00.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "constants/ability.h"
#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_movement.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "pokemon.h"
#include "status_checks.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "targeting.h"
#include "tile_types.h"

extern char gAvailablePokemonNames[];
extern char *gPtrCouldntBeUsedMessage;
extern char *gPtrItsaMonsterHouseMessage;

extern u8 sub_8044B28(void);
extern void sub_807AB38(Entity *, u32);
extern void sub_8041888(u32);
extern u8 sub_803F428(s16 *);

void sub_8075900(Entity *pokemon, u8 r1)
{
    if(EntityExists(pokemon))
    {
        if(!pokemon->axObj.info->isNotTeamMember)
        {
            if(!sub_8044B28())
            {
                if(!gDungeon->monsterHouseTriggered)
                {
                    if((GetTileAtEntitySafe(pokemon)->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE))
                    {
                        // It's a monster house!
                        SendMessage(GetLeader(), gPtrItsaMonsterHouseMessage);
                        gDungeon->monsterHouseTriggeredEvent = TRUE;
                        sub_807AB38(pokemon, r1);
                        sub_8041888(0);
                        if(sub_803F428(&pokemon->pos.x) != 0)
                            sub_803E708(0x78, 0x39);
                    }
                }
            }
        }
    }
}

void RunMonsterAI(Entity *pokemon, u32 unused)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    if (pokemonInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)
    {
        if (pokemonInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED)
        {
            SendImmobilizeEndMessage(pokemon, pokemon);
        }
    }
    else
    {
        pokemonInfo->targetingDecoy = TARGETING_DECOY_NONE;
        if (pokemonInfo->clientType == CLIENT_TYPE_NONE || IsMovingClient(pokemon))
        {
            if (pokemonInfo->clientType != CLIENT_TYPE_CLIENT && pokemonInfo->useHeldItem)
            {
                if (CheckVariousConditions(pokemon))
                {
                    pokemonInfo->useHeldItem = FALSE;
                    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
                    SendMessage(pokemon, gPtrCouldntBeUsedMessage);
                    return;
                }
                AIDecideUseItem(pokemon);
                if (pokemonInfo->action.action != ACTION_NOTHING)
                {
                    return;
                }
            }
            if (!HasStatusAffectingActions(pokemon))
            {
                if (gDungeon->decoyActive)
                {
                    s32 i;
                    Entity *target;
                    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
                    {
                        target = gDungeon->allPokemon[i];
                        if (EntityExists(target) &&
                            target->axObj.info->waitingStruct.waitingStatus == STATUS_DECOY &&
                            CanSeeTarget(pokemon, target))
                        {
                            bool8 enemyDecoy = target->axObj.info->waitingStruct.enemyDecoy;
                            u8 targetingDecoy = TARGETING_DECOY_TEAM;
                            if (enemyDecoy)
                            {
                                targetingDecoy = TARGETING_DECOY_WILD;
                            }
                            pokemonInfo->targetingDecoy = targetingDecoy;
                            break;
                        }
                    }
                }
                ClearMonsterActionFields(&pokemonInfo->action);
                if (pokemonInfo->clientType == CLIENT_TYPE_CLIENT)
                {
                    SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                    pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
                    pokemonInfo->targetPos.x = pokemon->pos.x;
                    pokemonInfo->targetPos.y = pokemon->pos.y - 1;
                }
                else
                {
                    AIDecideUseItem(pokemon);
                    if (pokemonInfo->action.action == ACTION_NOTHING)
                    {
                        if (!IQSkillIsEnabled(pokemon, IQ_DEDICATED_TRAVELER))
                        {
                            DecideAttack(pokemon);
                            if (pokemonInfo->action.action != ACTION_NOTHING)
                            {
                                return;
                            }
                            if (pokemonInfo->volatileStatus.volatileStatus == STATUS_CONFUSED)
                            {
                                SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                            }
                            else
                            {
                                if (!CanMove(pokemonInfo->id))
                                {
                                    return;
                                }
                                MoveIfPossible(pokemon, TRUE);
                            }
                        }
                        else
                        {
                            if (pokemonInfo->volatileStatus.volatileStatus == STATUS_CONFUSED)
                            {
                                SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                            }
                            else
                            {
                                if (CanMove(pokemonInfo->id))
                                {
                                    MoveIfPossible(pokemon, TRUE);
                                }
                                if (pokemonInfo->action.action > ACTION_PASS_TURN)
                                {
                                    return;
                                }
                                DecideAttack(pokemon);
                                if (pokemonInfo->action.action <= ACTION_PASS_TURN)
                                {
                                    return;
                                }
                                pokemonInfo->aiTarget.aiNotNextToTarget = FALSE;
                                pokemonInfo->aiNextToTarget = FALSE;
                                pokemonInfo->waiting = FALSE;
                            }
                        }
                    }
                }
            }
        }
    }
}
