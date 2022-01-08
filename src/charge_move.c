#include "global.h"
#include "charge_move.h"

#include "constants/status.h"
#include "dungeon_util.h"

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
