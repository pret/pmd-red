#include "global.h"
#include "dungeon_movement.h"

#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "dungeon_global_data.h"
#include "map.h"

extern char gAvailablePokemonNames[];
extern char *gPtrCouldntBeUsedMessage;
extern struct DungeonGlobalData *gDungeonGlobalData;

extern void SendImmobilizeEndMessage(struct DungeonEntity*, struct DungeonEntity*);
extern bool8 IsMovingClient(struct DungeonEntity*);
extern bool8 CannotUseItems(struct DungeonEntity*);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern void SendMessage(struct DungeonEntity*, char*);
extern void DecideUseItem(struct DungeonEntity*);
extern bool8 HasStatusAffectingActions(struct DungeonEntity*);
extern bool8 EntityExists(struct DungeonEntity*);
extern bool8 CanSee(struct DungeonEntity*, struct DungeonEntity*);
extern void ResetAction(u16*);
extern void SetWalkAction(u16*, s16);
extern s32 DungeonRandomCapped(s32);
extern bool8 HasIQSkill(struct DungeonEntity*, u8);
extern void DecideAttack(struct DungeonEntity*);
extern bool8 GetIsMoving(s16);
extern void MoveIfPossible(struct DungeonEntity*, bool8);

void DecideAction(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if ((pokemonData->flags & MOVEMENT_FLAG_SWAPPED_PLACES_PETRIFIED) != 0)
    {
        if (pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_PETRIFIED)
        {
            SendImmobilizeEndMessage(pokemon, pokemon);
        }
    }
    else
    {
        pokemonData->targetingDecoy = TARGETING_DECOY_NONE;
        if (pokemonData->clientType == CLIENT_TYPE_NONE || IsMovingClient(pokemon))
        {
            if (pokemonData->clientType != CLIENT_TYPE_CLIENT && pokemonData->useHeldItem)
            {
                if (CannotUseItems(pokemon))
                {
                    pokemonData->useHeldItem = FALSE;
                    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
                    SendMessage(pokemon, gPtrCouldntBeUsedMessage);
                    return;
                }
                DecideUseItem(pokemon);
                if (pokemonData->action != DUNGEON_ACTION_NONE)
                {
                    return;
                }
            }
            if (!HasStatusAffectingActions(pokemon))
            {
                if (gDungeonGlobalData->decoyActive)
                {
                    s32 i;
                    struct DungeonEntity *target;
                    for (i = 0; i < ALL_POKEMON_SIZE; i++)
                    {
                        target = gDungeonGlobalData->allPokemon[i];
                        if (EntityExists(target) &&
                            target->entityData->waitingStatus == WAITING_STATUS_DECOY &&
                            CanSee(pokemon, target))
                        {
                            bool8 enemyDecoy = target->entityData->enemyDecoy;
                            u8 targetingDecoy = TARGETING_DECOY_TEAM;
                            if (enemyDecoy)
                            {
                                targetingDecoy = TARGETING_DECOY_WILD;
                            }
                            pokemonData->targetingDecoy = targetingDecoy;
                            break;
                        }
                    }
                }
                ResetAction(&pokemonData->action);
                if (pokemonData->clientType == CLIENT_TYPE_CLIENT)
                {
                    SetWalkAction(&pokemonData->action, pokemonData->entityID);
                    pokemonData->facingDir = DungeonRandomCapped(8);
                    pokemonData->targetPositionX = pokemon->posWorldX;
                    pokemonData->targetPositionY = pokemon->posWorldY - 1;
                }
                else
                {
                    DecideUseItem(pokemon);
                    if (pokemonData->action == DUNGEON_ACTION_NONE)
                    {
                        if (!HasIQSkill(pokemon, IQ_SKILL_DEDICATED_TRAVELER))
                        {
                            DecideAttack(pokemon);
                            if (pokemonData->action != DUNGEON_ACTION_NONE)
                            {
                                return;
                            }
                            if (pokemonData->volatileStatus == VOLATILE_STATUS_CONFUSED)
                            {
                                SetWalkAction(&pokemonData->action, pokemonData->entityID);
                            }
                            else
                            {
                                if (!GetIsMoving(pokemonData->entityID))
                                {
                                    return;
                                }
                                MoveIfPossible(pokemon, TRUE);
                            }
                        }
                        else
                        {
                            if (pokemonData->volatileStatus == VOLATILE_STATUS_CONFUSED)
                            {
                                SetWalkAction(&pokemonData->action, pokemonData->entityID);
                            }
                            else
                            {
                                if (GetIsMoving(pokemonData->entityID))
                                {
                                    MoveIfPossible(pokemon, TRUE);
                                }
                                if (pokemonData->action > DUNGEON_ACTION_WAIT)
                                {
                                    return;
                                }
                                DecideAttack(pokemon);
                                if (pokemonData->action <= DUNGEON_ACTION_WAIT)
                                {
                                    return;
                                }
                                pokemonData->notAdjacentToTarget = FALSE;
                                pokemonData->movingIntoTarget = FALSE;
                                pokemonData->waiting = FALSE;
                            }
                        }
                    }
                }
            }
        }
    }
}
