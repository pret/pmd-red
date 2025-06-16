#include "global.h"
#include "globaldata.h"
#include "ground_place.h"
#include "event_flag.h"

static const u8 *const sGroundPlaceNames[] = {
    [0] = _("Square"),
    [1] = _("Square"),
    [2] = _("Pokémon Square"),
    [3] = _("Whiscash Pond"),
    [4] = _("Pelipper Post Office"),
    [5] = _("Pelipper Post Office"),
    [6] = _("Makuhita Dojo"),
    [7] = _("Makuhita Dojo"),
    [8] = _("Luminous Cave"),
    [9] = _("Friend Areas"),
    [10] = _("$t Team Base"),
    [11] = _("$t Team Base"),
    [12] = _("Dungeon"),
    [13] = _("Tiny Woods"),
    [14] = _("Thunderwave Cave"),
    [15] = _("Mt. Steel"),
    [16] = _("Sinister Woods"),
    [17] = _("Silent Chasm"),
    [18] = _("Mt. Thunder"),
    [19] = _("Mt. Thunder Mid"),
    [20] = _("Great Canyon"),
    [21] = _("Hill of the Ancients"),
    [22] = _("Lapis Cave"),
    [23] = _("Lapis Cave Exit"),
    [24] = _("Mt. Blaze"),
    [25] = _("Mt. Blaze Mid"),
    [26] = _("Frosty Forest"),
    [27] = _("Frosty Clearing"),
    [28] = _("Mt. Freeze"),
    [29] = _("Mt. Freeze Mid"),
    [30] = _("Magma Cavern"),
    [31] = _("Magma Cavern Mid"),
    [32] = _("Sky Tower"),
    [33] = _("Sky Tower Mid"),
    [34] = _("Western Cave"),
    [35] = _("{COLOR YELLOW_C}direction{RESET}"),
    [36] = _("New Game"),
    [37] = _("{COLOR YELLOW_C}scene{RESET}"),
    [38] = _("{COLOR RED_W}invalidity{RESET}"),
};

// Returns Location string for the pause menu
const u8 *GetGroundPlaceName(s16 id_)
{
    s32 id = id_;
    return sGroundPlaceNames[id];
}

// There's an identical function in ground_main.c
UNUSED static const u8 *UnusedGetCurrentGroundPlaceName(void)
{
    return GetGroundPlaceName(GetScriptVarValue(NULL, GROUND_PLACE));
}
