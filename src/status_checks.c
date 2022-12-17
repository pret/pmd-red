#include "global.h"
#include "status_checks.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/status.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "charge_move.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_random.h"

const s16 gConfusedAttackChance = 70;

extern const char *gPtrFrozenMessage[];
extern const char *gPtrWrappedAroundMessage[];
extern const char *gPtrWrappedByMessage[];
extern const char *gPtrBideMessage[];
extern const char *gPtrPausedMessage[];
extern const char *gPtrInfatuatedMessage[];
extern u8 gAvailablePokemonNames[];
extern u8 *gUnknown_80F95EC[];
extern char *gPtrMoveInterruptedMessage[];

extern void SetMessageArgument(char[], struct DungeonEntity*, u32);

bool8 HasStatusAffectingActions(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
    SetAction(&pokemonData->action, DUNGEON_ACTION_WAIT);
    switch (pokemonData->sleepStatus)
    {
        case SLEEP_STATUS_NIGHTMARE:
        case SLEEP_STATUS_SLEEP:
        case SLEEP_STATUS_NAPPING:
            return TRUE;
    }
    switch (pokemonData->immobilizeStatus)
    {
        case IMMOBILIZE_STATUS_FROZEN:
            SendMessage(pokemon, *gPtrFrozenMessage);
            return TRUE;
        case IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE:
            SendMessage(pokemon, *gPtrWrappedAroundMessage);
            return TRUE;
        case IMMOBILIZE_STATUS_WRAPPED_BY_FOE:
            SendMessage(pokemon, *gPtrWrappedByMessage);
            return TRUE;
        case IMMOBILIZE_STATUS_PETRIFIED:
            return TRUE;
    }
    switch (pokemonData->volatileStatus)
    {
        case VOLATILE_STATUS_PAUSED:
            SendMessage(pokemon, *gPtrPausedMessage);
            return TRUE;
        case VOLATILE_STATUS_INFATUATED:
            SendMessage(pokemon, *gPtrInfatuatedMessage);
            return TRUE;
    }
    if (pokemonData->chargingStatus == CHARGING_STATUS_BIDE)
    {
        SendMessage(pokemon, *gPtrBideMessage);
        return TRUE;
    }
    if (pokemonData->waitingStatus == WAITING_STATUS_DECOY)
    {
        SetWalkAction(&pokemonData->action, pokemonData->entityID);
        pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
        pokemonData->targetPosition.x = pokemon->posWorld.x;
        pokemonData->targetPosition.y = pokemon->posWorld.y - 1;
        return TRUE;
    }
    if (pokemonData->shopkeeperMode == SHOPKEEPER_FRIENDLY)
    {
        return TRUE;
    }
    if (pokemonData->eyesightStatus == EYESIGHT_STATUS_BLINKER)
    {
        if (!CanMoveInDirection(pokemon, pokemonData->action.facingDir))
        {
            if (DungeonRandomCapped(2) != 0)
            {
                pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
                pokemonData->action.facingDir = pokemonData->action.facingDir & DIRECTION_MASK;
                goto walk;
            }
        }
        else
        {
            walk:
            SetWalkAction(&pokemonData->action, pokemonData->entityID);
            return TRUE;
        }
        DecideAttack(pokemon);
        return TRUE;
    }
    if (pokemonData->eyesightStatus == EYESIGHT_STATUS_CROSS_EYED)
    {
        SetWalkAction(&pokemonData->action, pokemonData->entityID);
        pokemonData->action.facingDir = DungeonRandomCapped(NUM_DIRECTIONS);
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80701A4(struct DungeonEntity *pokemon)
{
  bool8 flag;
  struct PokemonMove *move;
  struct PokemonMove *move2;
  s32 index;
  s32 index_1;
  struct DungeonEntityData * entityData;
  u8 *r7;
  
  entityData = pokemon->entityData;
  flag = FALSE;
  SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
  SetAction(&entityData->action, DUNGEON_ACTION_WAIT);
  switch(entityData->sleepStatus)
  {
      case SLEEP_STATUS_SLEEP:
      case SLEEP_STATUS_NIGHTMARE:
      case SLEEP_STATUS_NAPPING:
          SendMessage(pokemon,*gUnknown_80F95EC);
          return TRUE;
  }

  switch(entityData->immobilizeStatus)
  {
    case IMMOBILIZE_STATUS_FROZEN:
        SendMessage(pokemon,*gPtrFrozenMessage);
        return TRUE;
    case IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE:
        SendMessage(pokemon,*gPtrWrappedAroundMessage);
        return TRUE;
    case IMMOBILIZE_STATUS_WRAPPED_BY_FOE:
        SendMessage(pokemon,*gPtrWrappedByMessage);
        return TRUE;
    case IMMOBILIZE_STATUS_PETRIFIED:
        return TRUE;
  }

  switch(entityData->volatileStatus) {
    case VOLATILE_STATUS_CONFUSED:
        flag = TRUE;
        goto _0807026C;
    case VOLATILE_STATUS_PAUSED:
        SendMessage(pokemon,*gPtrPausedMessage);
        return TRUE;
    case VOLATILE_STATUS_INFATUATED:
        SendMessage(pokemon,*gPtrInfatuatedMessage);
        return TRUE;
    default:
    case VOLATILE_STATUS_NONE:
    case VOLATILE_STATUS_CRINGING:
    case 8:
    _0807026C:
        if (entityData->chargingStatus == CHARGING_STATUS_BIDE) {
             SendMessage(pokemon,*gPtrBideMessage);
             return TRUE;
        }
        else if (((entityData->chargingStatus != CHARGING_STATUS_NONE) && (entityData->chargingStatus != CHARGING_STATUS_CHARGE)) && (entityData->chargingStatus != CHARGING_STATUS_RAGE)) {
            if (flag) {
                SendMessage(pokemon,*gPtrMoveInterruptedMessage);
            }
            else {
                for(index = 0, move = entityData->moves; index < MAX_MON_MOVES; move++, index++) {
                    if ((move->moveFlags & MOVE_FLAG_EXISTS) &&
                    (MoveMatchesChargingStatus(pokemon,move)) &&
                    (entityData->chargingStatusMoveIndex == index)) {
                        SetAction(&entityData->action, DUNGEON_ACTION_USE_MOVE_LEADER);
                        index_1 = index;
                        r7 = &entityData->action.unkC;
                        if((index > 0) && (move->moveFlags & MOVE_FLAG_LINKED))
                        {   
                            do {
                                move2 = &entityData->moves[index_1 + 1];
                                move2--, index_1--;
                                if(index_1 <= 0) break;
                                if(!(entityData->moves[index_1].moveFlags & MOVE_FLAG_LINKED))
                                {
                                    break;
                                }
                            }
                            while(TRUE);
                        }
                        *r7 = index_1;
                        return TRUE;
                    }
                }
            }
            sub_8079764(pokemon);
        }   
        return FALSE;
  }
}
