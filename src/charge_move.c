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
    {MOVE_SOLARBEAM, STATUS_SOLARBEAM},
    {MOVE_SKY_ATTACK, STATUS_SKY_ATTACK},
    {MOVE_RAZOR_WIND, STATUS_RAZOR_WIND},
    {MOVE_FOCUS_PUNCH, STATUS_FOCUS_PUNCH},
    {MOVE_SKULL_BASH, STATUS_SKULL_BASH},
    {MOVE_FLY, STATUS_FLYING},
    {MOVE_BOUNCE, STATUS_BOUNCING},
    {MOVE_DIVE, STATUS_DIVING},
    {MOVE_DIG, STATUS_DIGGING},
    {MOVE_NOTHING, STATUS_NONE}
};

const u32 gMultiTurnChargingStatuses[10] = {
    STATUS_SOLARBEAM,
    STATUS_SKY_ATTACK,
    STATUS_RAZOR_WIND,
    STATUS_FOCUS_PUNCH,
    STATUS_SKULL_BASH,
    STATUS_FLYING,
    STATUS_BOUNCING,
    STATUS_DIVING,
    STATUS_DIGGING,
    STATUS_NONE
};

u32 sub_8057070(Move *move)
{
    u32 numberOfChainedHits;
    numberOfChainedHits = GetMoveNumberOfChainedHits(move);
    if(numberOfChainedHits == 0)
        return DungeonRandRange(2, 6);
    else
        return numberOfChainedHits;
}

bool8 MoveCausesPaused(Move *move)
{
    if(move->id == MOVE_FRENZY_PLANT) return TRUE;
    if(move->id == MOVE_HYDRO_CANNON) return TRUE;
    if(move->id == MOVE_HYPER_BEAM) return TRUE;
    if(move->id == MOVE_BLAST_BURN) return TRUE;

    return FALSE;
}

bool8 MoveMatchesChargingStatus(Entity *pokemon, Move *move)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = pokemon->axObj.info;
        s32 i;
        for (i = 0; i < 100; i++)
        {
            if (gMultiTurnChargeMoves[i].moveID == MOVE_NOTHING)
            {
                return FALSE;
            }
            if (move->id == gMultiTurnChargeMoves[i].moveID &&
                pokemonInfo->charging.chargingStatus == gMultiTurnChargeMoves[i].chargingStatus)
            {
                return TRUE;
            }
        }
        return FALSE;
    }
}

bool8 IsChargingAnyTwoTurnMove(Entity *pokemon, bool8 checkCharge)
{
    if (!EntityExists(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = pokemon->axObj.info;
        int i = 0;
        u8 *chargingStatusPointer = &pokemonInfo->charging.chargingStatus;
        u8 *chargingStatusPointer2;
        u8 chargeStatus = STATUS_CHARGING;
        for (; i < 100; i++)
        {
            u8 currentStatus = gMultiTurnChargingStatuses[i];
            u8 chargingStatus;
            if (currentStatus == STATUS_NONE)
            {
                return FALSE;
            }
            chargingStatus = *chargingStatusPointer;
            chargingStatusPointer2 = &pokemonInfo->charging.chargingStatus;
            if (chargingStatus == currentStatus)
            {
                return TRUE;
            }
        }
        // BUG: This condition is never reached because the for loop terminates by returning FALSE at the end of the gMultiTurnChargingStatuses array.
        if (checkCharge && *chargingStatusPointer2 == chargeStatus)
        {
            return TRUE;
        }
        return FALSE;
    }
}
