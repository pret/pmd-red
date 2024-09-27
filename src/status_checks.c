#include "global.h"
#include "status_checks.h"

#include "charge_move.h"
#include "code_8045A00.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/status.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_capabilities.h"
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

bool8 HasStatusAffectingActions(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
    SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
    switch (pokemonInfo->sleep.sleep)
    {
        case STATUS_NIGHTMARE:
        case STATUS_SLEEP:
        case STATUS_NAPPING:
            return TRUE;
    }
    switch (pokemonInfo->immobilize.immobilizeStatus)
    {
        case STATUS_FROZEN:
            SendMessage(pokemon, *gPtrFrozenMessage);
            return TRUE;
        case STATUS_WRAP:
            SendMessage(pokemon, *gPtrWrappedAroundMessage);
            return TRUE;
        case STATUS_WRAPPED:
            SendMessage(pokemon, *gPtrWrappedByMessage);
            return TRUE;
        case STATUS_PETRIFIED:
            return TRUE;
    }
    switch (pokemonInfo->volatileStatus.volatileStatus)
    {
        case STATUS_PAUSED:
            SendMessage(pokemon, *gPtrPausedMessage);
            return TRUE;
        case STATUS_INFATUATED:
            SendMessage(pokemon, *gPtrInfatuatedMessage);
            return TRUE;
    }
    if (pokemonInfo->charging.chargingStatus == STATUS_BIDE)
    {
        SendMessage(pokemon, *gPtrBideMessage);
        return TRUE;
    }
    if (pokemonInfo->waitingStruct.waitingStatus == STATUS_DECOY)
    {
        SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
        pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
        pokemonInfo->targetPos.x = pokemon->pos.x;
        pokemonInfo->targetPos.y = pokemon->pos.y - 1;
        return TRUE;
    }
    if (pokemonInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER)
    {
        return TRUE;
    }
    if (pokemonInfo->eyesightStatus.eyesightStatus == STATUS_BLINKER)
    {
        if (!CanMoveInDirection(pokemon, pokemonInfo->action.direction))
        {
            if (DungeonRandInt(2) != 0)
            {
                pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
                pokemonInfo->action.direction = pokemonInfo->action.direction & DIRECTION_MASK;
                goto walk;
            }
        }
        else
        {
            walk:
            SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
            return TRUE;
        }
        DecideAttack(pokemon);
        return TRUE;
    }
    if (pokemonInfo->eyesightStatus.eyesightStatus == STATUS_CROSS_EYED)
    {
        SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
        pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80701A4(Entity *pokemon)
{
  bool8 flag;
  Move *move;
  Move *move2;
  s32 index;
  s32 index_1;
  EntityInfo * pokemonInfo;
  u8 *r7;

  pokemonInfo = pokemon->axObj.info;
  flag = FALSE;
  SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
  SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
  switch(pokemonInfo->sleep.sleep)
  {
      case STATUS_SLEEP:
      case STATUS_NIGHTMARE:
      case STATUS_NAPPING:
          SendMessage(pokemon,*gUnknown_80F95EC);
          return TRUE;
  }

  switch(pokemonInfo->immobilize.immobilizeStatus)
  {
    case STATUS_FROZEN:
        SendMessage(pokemon,*gPtrFrozenMessage);
        return TRUE;
    case STATUS_WRAP:
        SendMessage(pokemon,*gPtrWrappedAroundMessage);
        return TRUE;
    case STATUS_WRAPPED:
        SendMessage(pokemon,*gPtrWrappedByMessage);
        return TRUE;
    case STATUS_PETRIFIED:
        return TRUE;
  }

  switch(pokemonInfo->volatileStatus.volatileStatus) {
    case STATUS_CONFUSED:
        flag = TRUE;
        goto _0807026C;
    case STATUS_PAUSED:
        SendMessage(pokemon,*gPtrPausedMessage);
        return TRUE;
    case STATUS_INFATUATED:
        SendMessage(pokemon,*gPtrInfatuatedMessage);
        return TRUE;
    default:
    case STATUS_NONE:
    case STATUS_CRINGE:
    case 8:
    _0807026C:
        if (pokemonInfo->charging.chargingStatus == STATUS_BIDE) {
             SendMessage(pokemon,*gPtrBideMessage);
             return TRUE;
        }
        else if (((pokemonInfo->charging.chargingStatus != STATUS_NONE) && (pokemonInfo->charging.chargingStatus != STATUS_CHARGING)) && (pokemonInfo->charging.chargingStatus != STATUS_ENRAGED)) {
            if (flag) {
                SendMessage(pokemon,*gPtrMoveInterruptedMessage);
            }
            else {
                for(index = 0, move = pokemonInfo->moves; index < MAX_MON_MOVES; move++, index++) {
                    if ((move->moveFlags & MOVE_FLAG_EXISTS) &&
                    (MoveMatchesChargingStatus(pokemon,move)) &&
                    (pokemonInfo->charging.chargingStatusMoveIndex == index)) {
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_USE_MOVE_PLAYER);
                        index_1 = index;
                        r7 = &pokemonInfo->action.unk4[1].actionUseIndex;
                        if((index > 0) && (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
                        {
                            do {
                                move2 = &pokemonInfo->moves[index_1 + 1];
                                move2--, index_1--;
                                if(index_1 <= 0) break;
                                if(!(pokemonInfo->moves[index_1].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
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
