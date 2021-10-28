#include "global.h"
#include "charge_move.h"

#include "constants/status.h"
#include "dungeon_util.h"

extern u32 gMultiTurnChargingStatuses[];

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
