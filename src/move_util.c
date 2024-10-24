#include "global.h"
#include "move_util.h"

#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "moves.h"
#include "dungeon_util.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "structs/str_dungeon.h"
#include "called_move_data.h"


extern bool8 sub_8044B28(void);
extern void sub_80429C8(Entity *r0);

bool8 sub_805755C(Entity* pokemon,u16 param_2);

u32 sub_8057144(Entity * pokemon)
{
    Move *moveStack[80];
    int i, j, nMoves;

    nMoves = 0;
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        Entity *dungeonMon = gDungeon->allPokemon[i];
        if (EntityExists(dungeonMon)) {
            Move *moves = dungeonMon->info->moves.moves;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (moves[j].moveFlags & MOVE_FLAG_EXISTS
                    && !sub_805755C(pokemon, moves[j].id)
                    && moves[j].id != MOVE_SKETCH
                    && nMoves < 80) {
                    moveStack[nMoves++] = &moves[j];
                }
            }
        }
    }

    if (nMoves == 0) {
        return MOVE_REGULAR_ATTACK;
    }
    else {
        return moveStack[DungeonRandInt(nMoves)]->id;
    }
}

bool8 sub_80571F0(Entity * pokemon, Move *move)
{
    u16 moveID;
    s32 tileset;
    EntityInfo *entityInfo;

    entityInfo = pokemon->info;

    if (entityInfo->unkFF == 1) {
        moveID = move->id;
        if ((moveID == MOVE_SKY_UPPERCUT) || (moveID == MOVE_TWISTER) || (moveID == MOVE_GUST) || (moveID == MOVE_THUNDER))
            return FALSE;
        else
            return TRUE;
    }
    else if (entityInfo->unkFF == 2) {
        if (entityInfo->charging.chargingStatus == STATUS_DIVING) {
            if (move->id == MOVE_WHIRLPOOL || move->id == MOVE_SURF) return FALSE;
        }
        else if (entityInfo->charging.chargingStatus == STATUS_DIGGING) {
            moveID = move->id;
            if (moveID == MOVE_EARTHQUAKE || moveID == MOVE_MAGNITUDE) return FALSE;
            if (moveID == MOVE_NATURE_POWER) {
                tileset = gDungeon->tileset;
                if (tileset < 0) {
                    tileset = 0;
                }
                if (0x4a < tileset) {
                    tileset = 0x4a;
                }
                if (gNaturePowerCalledMoves[tileset].moveID == MOVE_EARTHQUAKE) return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_805727C(Entity * pokemon, Entity * target, s32 chance)
{
    bool8 uVar2;
    if (sub_8044B28())
        return FALSE;
    if (!EntityExists(pokemon) || !EntityExists(target))
        return FALSE;
    if (target->info->unk158 == 0 || target->info->HP == 0)
        return FALSE;

    if (chance != 0) {
        if (HasAbility(pokemon, ABILITY_SERENE_GRACE)) {
            uVar2 = DungeonRandOutcome_2(chance * 2);
        }
        else
        {
            uVar2 = DungeonRandOutcome_2(chance);
        }
    }
    else
    {
        uVar2 = TRUE;
    }

    if (uVar2 && (pokemon != target) && HasAbility(target, ABILITY_SHIELD_DUST))
    {
        sub_80429C8(target);
        return FALSE;
    }

    return uVar2;
}

bool8 sub_8057308(Entity *pokemon, s32 chance)
{
    if(!EntityExists(pokemon))
        return FALSE;
    if(chance == 0)
        return TRUE;
    if(HasAbility(pokemon, ABILITY_SERENE_GRACE))
        return DungeonRandOutcome_2(chance * 2);
    else
        return DungeonRandOutcome_2(chance);
}

bool8 CanAIUseMove(Entity *pokemon, s32 moveIndex, bool8 hasPPChecker)
{
    s32 i;
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    Move *move = &pokemonInfo->moves.moves[moveIndex];
    if (!MoveFlagExists(move))
        return FALSE;
    if (MoveFlagLinkChain(move) || MoveFlagDisabled(move) || MoveFlagSealed(move))
        return FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        if (CanMonsterUseMove(pokemon, move, hasPPChecker))
            return TRUE;
        move++;
        if (move >= &pokemonInfo->moves.moves[MAX_MON_MOVES])
            break;
        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            break;
    }

    return FALSE;
}

bool8 CanMonsterUseMove(Entity *pokemon, Move *move, bool8 hasPPChecker)
{
    EntityInfo *pokemonInfo = pokemon->info;
    if (move->id == MOVE_REGULAR_ATTACK)
    {
        return TRUE;
    }
    if (move->moveFlags & MOVE_FLAG_DISABLED || move->moveFlags2 & MOVE_FLAG_SEALED)
    {
        return FALSE;
    }
    if (hasPPChecker)
    {
        if (move->PP == 0)
        {
            return FALSE;
        }
        if (pokemonInfo->volatileStatus.volatileStatus == STATUS_TAUNTED && !MoveIgnoresTaunted(move))
        {
            return FALSE;
        }
        if (pokemonInfo->volatileStatus.volatileStatus == STATUS_ENCORE)
        {
            if (move->id == MOVE_STRUGGLE)
            {
                if (!(pokemonInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED))
                {
                    return FALSE;
                }
            }
            else if (!(move->moveFlags & MOVE_FLAG_LAST_USED))
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

bool8 sub_805744C(Entity * pokemon, Move *move, bool8 param_3)
{
  EntityInfo *entityInfo;

  entityInfo = pokemon->info;
  if (move->id != MOVE_REGULAR_ATTACK) {
    if (((move->moveFlags & MOVE_FLAG_DISABLED)) || ((move->moveFlags2 & MOVE_FLAG_EXISTS))) {
        return FALSE;
    }
    if (param_3 != 0) {
      if ((entityInfo->volatileStatus.volatileStatus == STATUS_TAUNTED) && (!MoveIgnoresTaunted(move))) return FALSE;
      if (entityInfo->volatileStatus.volatileStatus == STATUS_ENCORE) {
        if (move->id == MOVE_STRUGGLE) {
          if((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
        else {
          if((move->moveFlags & MOVE_FLAG_LAST_USED) == 0) return FALSE;
        }
      }
    }
  }
  return TRUE;
}
