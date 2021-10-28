#include "global.h"
#include "dungeon_util_1.h"

bool8 IsMovingClient(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    switch (pokemonData->clientType)
    {
        case CLIENT_TYPE_CLIENT:
        case CLIENT_TYPE_DONT_MOVE:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0x9:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            return TRUE;
        case CLIENT_TYPE_NONE:
        case 0x2:
        case 0x4:
        case 0xA:
        case 0xB:
        case 0xC:
        default:
            return FALSE;
    }
}
