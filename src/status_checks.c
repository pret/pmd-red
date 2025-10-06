#include "global.h"
#include "globaldata.h"
#include "status_checks.h"
#include "dungeon_util.h"
#include "dungeon_move_util.h"
#include "dungeon_message.h"
#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/status.h"
#include "dungeon_action.h"
#include "dungeon_strings.h"
#include "dungeon_ai_attack.h"
#include "dungeon_random.h"
#include "dungeon_logic.h"
#include "moves.h"
#include "move_orb_effects_3.h"

bool8 HasStatusThatPreventsActing(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], pokemon, 0);
    SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
    switch (pokemonInfo->sleepClassStatus.status)
    {
        case STATUS_NIGHTMARE:
        case STATUS_SLEEP:
        case STATUS_NAPPING:
            return TRUE;
    }
    switch (pokemonInfo->frozenClassStatus.status)
    {
        case STATUS_FROZEN:
            LogMessageByIdWithPopupCheckUser(pokemon, gPtrFrozenMessage);
            return TRUE;
        case STATUS_WRAP:
            LogMessageByIdWithPopupCheckUser(pokemon, gPtrWrappedAroundMessage);
            return TRUE;
        case STATUS_WRAPPED:
            LogMessageByIdWithPopupCheckUser(pokemon, gPtrWrappedByMessage);
            return TRUE;
        case STATUS_PETRIFIED:
            return TRUE;
    }
    switch (pokemonInfo->cringeClassStatus.status)
    {
        case STATUS_PAUSED:
            LogMessageByIdWithPopupCheckUser(pokemon, gPtrPausedMessage);
            return TRUE;
        case STATUS_INFATUATED:
            LogMessageByIdWithPopupCheckUser(pokemon, gPtrInfatuatedMessage);
            return TRUE;
    }
    if (pokemonInfo->bideClassStatus.status == STATUS_BIDE)
    {
        LogMessageByIdWithPopupCheckUser(pokemon, gPtrBideMessage);
        return TRUE;
    }
    if (pokemonInfo->curseClassStatus.status == STATUS_DECOY)
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
    if (pokemonInfo->blinkerClassStatus.status == STATUS_BLINKER)
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
        ChooseAIMove(pokemon);
        return TRUE;
    }
    if (pokemonInfo->blinkerClassStatus.status == STATUS_CROSS_EYED)
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

  pokemonInfo = GetEntInfo(pokemon);
  flag = FALSE;
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], pokemon, 0);
  SetMonsterActionFields(&pokemonInfo->action, ACTION_PASS_TURN);
  switch(pokemonInfo->sleepClassStatus.status)
  {
      case STATUS_SLEEP:
      case STATUS_NIGHTMARE:
      case STATUS_NAPPING:
          LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80F95EC);
          return TRUE;
  }

  switch(pokemonInfo->frozenClassStatus.status)
  {
    case STATUS_FROZEN:
        LogMessageByIdWithPopupCheckUser(pokemon,gPtrFrozenMessage);
        return TRUE;
    case STATUS_WRAP:
        LogMessageByIdWithPopupCheckUser(pokemon,gPtrWrappedAroundMessage);
        return TRUE;
    case STATUS_WRAPPED:
        LogMessageByIdWithPopupCheckUser(pokemon,gPtrWrappedByMessage);
        return TRUE;
    case STATUS_PETRIFIED:
        return TRUE;
  }

  switch(pokemonInfo->cringeClassStatus.status) {
    case STATUS_CONFUSED:
        flag = TRUE;
        goto _0807026C;
    case STATUS_PAUSED:
        LogMessageByIdWithPopupCheckUser(pokemon,gPtrPausedMessage);
        return TRUE;
    case STATUS_INFATUATED:
        LogMessageByIdWithPopupCheckUser(pokemon,gPtrInfatuatedMessage);
        return TRUE;
    default:
    case STATUS_NONE:
    case STATUS_CRINGE:
    case 8:
    _0807026C:
        if (pokemonInfo->bideClassStatus.status == STATUS_BIDE) {
             LogMessageByIdWithPopupCheckUser(pokemon,gPtrBideMessage);
             return TRUE;
        }
        else if (((pokemonInfo->bideClassStatus.status != STATUS_NONE) && (pokemonInfo->bideClassStatus.status != STATUS_CHARGING)) && (pokemonInfo->bideClassStatus.status != STATUS_ENRAGED)) {
            if (flag) {
                LogMessageByIdWithPopupCheckUser(pokemon,gPtrMoveInterruptedMessage);
            }
            else {
                for(index = 0, move = pokemonInfo->moves.moves; index < MAX_MON_MOVES; move++, index++) {
                    if ((move->moveFlags & MOVE_FLAG_EXISTS) &&
                    (MoveMatchesBideClassStatus(pokemon,move)) &&
                    (pokemonInfo->bideClassStatus.moveSlot == index)) {
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_USE_MOVE_PLAYER);
                        index_1 = index;
                        r7 = &pokemonInfo->action.actionParameters[1].actionUseIndex;
                        if((index > 0) && MOVE_FLAG_LINK_CHAIN(move))
                        {
                            do {
                                move2 = &pokemonInfo->moves.moves[index_1 + 1];
                                move2--, index_1--;
                                if(index_1 <= 0) break;
                                if(!(pokemonInfo->moves.moves[index_1].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
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
