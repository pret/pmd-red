#include "global.h"
#include "charge_move.h"

#include "constants/move_id.h"
#include "constants/status.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "moves.h"

struct MultiTurnChargeMove
{
    u16 moveID;
    u8 chargingStatus;
};

const struct MultiTurnChargeMove gMultiTurnChargeMoves[10] = {
    {MOVE_SOLARBEAM, CHARGING_STATUS_SOLARBEAM},
    {MOVE_SKY_ATTACK, CHARGING_STATUS_SKY_ATTACK},
    {MOVE_RAZOR_WIND, CHARGING_STATUS_RAZOR_WIND},
    {MOVE_FOCUS_PUNCH, CHARGING_STATUS_FOCUS_PUNCH},
    {MOVE_SKULL_BASH, CHARGING_STATUS_SKULL_BASH},
    {MOVE_FLY, CHARGING_STATUS_FLY},
    {MOVE_BOUNCE, CHARGING_STATUS_BOUNCE},
    {MOVE_DIVE, CHARGING_STATUS_DIVE},
    {MOVE_DIG, CHARGING_STATUS_DIG},
    {MOVE_NONE, CHARGING_STATUS_NONE}
};

const u32 gMultiTurnChargingStatuses[10] = {
    CHARGING_STATUS_SOLARBEAM,
    CHARGING_STATUS_SKY_ATTACK,
    CHARGING_STATUS_RAZOR_WIND,
    CHARGING_STATUS_FOCUS_PUNCH,
    CHARGING_STATUS_SKULL_BASH,
    CHARGING_STATUS_FLY,
    CHARGING_STATUS_BOUNCE,
    CHARGING_STATUS_DIVE,
    CHARGING_STATUS_DIG,
    CHARGING_STATUS_NONE
};

ALIGNED(4) const char chargingStatusFill[] = "pksdir0";

u32 sub_8057070(struct PokemonMove *move)
{
    u32 hitCount;
    hitCount = GetMoveHitCount(move);
    if(hitCount == 0)
        return DungeonRandomRange(2, 6);
    else
        return hitCount;
}

bool8 MoveCausesPaused(struct PokemonMove *move)
{
    if(move->moveID == MOVE_FRENZY_PLANT) return TRUE;
    if(move->moveID == MOVE_HYDRO_CANNON) return TRUE;
    if(move->moveID == MOVE_HYPER_BEAM) return TRUE;
    if(move->moveID == MOVE_BLAST_BURN) return TRUE;

    return FALSE;
}

bool8 MoveMatchesChargingStatus(struct DungeonEntity *pokemon, struct PokemonMove *move)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct DungeonEntityData *pokemonData = pokemon->entityData;
        s32 i;
        for (i = 0; i < 100; i++)
        {
            if (gMultiTurnChargeMoves[i].moveID == MOVE_NONE)
            {
                return FALSE;
            }
            if (move->moveID == gMultiTurnChargeMoves[i].moveID &&
                pokemonData->chargingStatus == gMultiTurnChargeMoves[i].chargingStatus)
            {
                return TRUE;
            }
        }
        return FALSE;
    }
}

bool8 IsCharging(struct DungeonEntity *pokemon, bool8 checkCharge)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        struct DungeonEntityData *pokemonData = pokemon->entityData;
        int i = 0;
        u8 *chargingStatusPointer = &pokemonData->chargingStatus;
        u8 *chargingStatusPointer2;
        u8 chargeStatus = CHARGING_STATUS_CHARGE;
        for (; i < 100; i++)
        {
            u8 currentStatus = gMultiTurnChargingStatuses[i];
            u8 chargingStatus;
            if (currentStatus == CHARGING_STATUS_NONE)
            {
                return FALSE;
            }
            chargingStatus = *chargingStatusPointer;
            chargingStatusPointer2 = &pokemonData->chargingStatus;
            if (chargingStatus == currentStatus)
            {
                return TRUE;
            }
        }
        if (checkCharge && *chargingStatusPointer2 == chargeStatus)
        {
            return TRUE;
        }
        return FALSE;
    }
}
