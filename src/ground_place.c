#include "global.h"
#include "globaldata.h"
#include "ground_place.h"
#include "event_flag.h"

static const u8 *const sGroundPlaceNames[] = {
    [GROUND_PLACE_SQUARE] =                     _("Square"),
    [GROUND_PLACE_SQUARE_2] =                   _("Square"),
    [GROUND_PLACE_POKEMON_SQUARE] =             _("Pokémon Square"),
    [GROUND_PLACE_WHISCASH_POND] =              _("Whiscash Pond"),
    [GROUND_PLACE_PELIPPER_POST_OFFICE] =       _("Pelipper Post Office"),
    [GROUND_PLACE_PELIPPER_POST_OFFICE_INSIDE] =_("Pelipper Post Office"),
    [GROUND_PLACE_MAKUHITA_DOJO] =              _("Makuhita Dojo"),
    [GROUND_PLACE_MAKUHITA_DOJO_INSIDE] =       _("Makuhita Dojo"),
    [GROUND_PLACE_LUMINOUS_CAVE] =              _("Luminous Cave"),
    [GROUND_PLACE_FRIEND_AREAS] =               _("Friend Areas"),
    [GROUND_PLACE_TEAM_BASE] =                  _("$t Team Base"),
    [GROUND_PLACE_TEAM_BASE_INSIDE] =           _("$t Team Base"),
    [GROUND_PLACE_DUNGEON] =                    _("Dungeon"),
    [GROUND_PLACE_TINY_WOODS] =                 _("Tiny Woods"),
    [GROUND_PLACE_THUNDERWAVE_CAVE] =           _("Thunderwave Cave"),
    [GROUND_PLACE_MT_STEEL] =                   _("Mt. Steel"),
    [GROUND_PLACE_SINISTER_WOODS] =             _("Sinister Woods"),
    [GROUND_PLACE_SILENT_CHASM] =               _("Silent Chasm"),
    [GROUND_PLACE_MT_THUNDER] =                 _("Mt. Thunder"),
    [GROUND_PLACE_MT_THUNDER_MID] =             _("Mt. Thunder Mid"),
    [GROUND_PLACE_GREAT_CANYON] =               _("Great Canyon"),
    [GROUND_PLACE_HILL_OF_THE_ANCIENTS] =       _("Hill of the Ancients"),
    [GROUND_PLACE_LAPIS_CAVE] =                 _("Lapis Cave"),
    [GROUND_PLACE_LAPIS_CAVE_EXIT] =            _("Lapis Cave Exit"),
    [GROUND_PLACE_MT_BLAZE] =                   _("Mt. Blaze"),
    [GROUND_PLACE_MT_BLAZE_MID] =               _("Mt. Blaze Mid"),
    [GROUND_PLACE_FROSTY_FOREST] =              _("Frosty Forest"),
    [GROUND_PLACE_FROSTY_CLEARING] =            _("Frosty Clearing"),
    [GROUND_PLACE_MT_FREEZE] =                  _("Mt. Freeze"),
    [GROUND_PLACE_MT_FREEZE_MID] =              _("Mt. Freeze Mid"),
    [GROUND_PLACE_MAGMA_CAVERN] =               _("Magma Cavern"),
    [GROUND_PLACE_MAGMA_CAVERN_MID] =           _("Magma Cavern Mid"),
    [GROUND_PLACE_SKY_TOWER] =                  _("Sky Tower"),
    [GROUND_PLACE_SKY_TOWER_MID] =              _("Sky Tower Mid"),
    [GROUND_PLACE_WESTERN_CAVE] =               _("Western Cave"),
    [GROUND_PLACE_DIRECTION] =                  _("{COLOR YELLOW_C}direction{RESET}"),
    [GROUND_PLACE_NEW_GAME] =                   _("New Game"),
    [GROUND_PLACE_SCENE] =                      _("{COLOR YELLOW_C}scene{RESET}"),
    [GROUND_PLACE_INVALIDITY] =                 _("{COLOR RED_W}invalidity{RESET}"),
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
