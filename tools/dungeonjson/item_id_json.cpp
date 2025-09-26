#include <string>
using std::string;

#include <map>
using std::map;

#include <algorithm>
using std::find;

#include "dungeonjson.h"
#include "item_id_json.h"

static map<std::string, int> item_macro_ids;

void set_item_ids(){
    item_macro_ids["CATEGORY_THROWN_LINE"] = 0x0;
    item_macro_ids["CATEGORY_THROWN_ARC"] = 0x1;
    item_macro_ids["CATEGORY_BERRIES_SEEDS_VITAMINS"] = 0x2;
    item_macro_ids["CATEGORY_FOOD_GUMMIES"] = 0x3;
    item_macro_ids["CATEGORY_HELD_ITEMS"] = 0x4;
    item_macro_ids["CATEGORY_TMS_HMS"] = 0x5;
    item_macro_ids["CATEGORY_POKE"] = 0x6;
    item_macro_ids["CATEGORY_7"] = 0x7;
    item_macro_ids["CATEGORY_OTHER"] = 0x8;
    item_macro_ids["CATEGORY_ORBS"] = 0x9;
    item_macro_ids["CATEGORY_LINK_BOX"] = 0xA;
    item_macro_ids["CATEGORY_USED_TM"] = 0xB;
    item_macro_ids["ITEM_NOTHING"] = 0xC;
    item_macro_ids["ITEM_STICK"] = 0xD;
    item_macro_ids["ITEM_IRON_THORN"] = 0xE;
    item_macro_ids["ITEM_SILVER_SPIKE"] = 0xF;
    item_macro_ids["ITEM_GOLD_FANG"] = 0x10;
    item_macro_ids["ITEM_CACNEA_SPIKE"] = 0x11;
    item_macro_ids["ITEM_CORSOLA_TWIG"] = 0x12;
    item_macro_ids["ITEM_GRAVELEROCK"] = 0x13;
    item_macro_ids["ITEM_GEO_PEBBLE"] = 0x14;
    item_macro_ids["ITEM_MOBILE_SCARF"] = 0x15;
    item_macro_ids["ITEM_HEAL_RIBBON"] = 0x16;
    item_macro_ids["ITEM_TWIST_BAND"] = 0x17;
    item_macro_ids["ITEM_SCOPE_LENS"] = 0x18;
    item_macro_ids["ITEM_PATSY_BAND"] = 0x19;
    item_macro_ids["ITEM_NOSTICK_CAP"] = 0x1A;
    item_macro_ids["ITEM_PIERCE_BAND"] = 0x1B;
    item_macro_ids["ITEM_JOY_RIBBON"] = 0x1C;
    item_macro_ids["ITEM_X_RAY_SPECS"] = 0x1D;
    item_macro_ids["ITEM_PERSIM_BAND"] = 0x1E;
    item_macro_ids["ITEM_POWER_BAND"] = 0x1F;
    item_macro_ids["ITEM_PECHA_SCARF"] = 0x20;
    item_macro_ids["ITEM_INSOMNISCOPE"] = 0x21;
    item_macro_ids["ITEM_WARP_SCARF"] = 0x22;
    item_macro_ids["ITEM_TIGHT_BELT"] = 0x23;
    item_macro_ids["ITEM_SNEAK_SCARF"] = 0x24;
    item_macro_ids["ITEM_GOLD_RIBBON"] = 0x25;
    item_macro_ids["ITEM_GOGGLE_SPECS"] = 0x26;
    item_macro_ids["ITEM_DIET_RIBBON"] = 0x27;
    item_macro_ids["ITEM_TRAP_SCARF"] = 0x28;
    item_macro_ids["ITEM_RACKET_BAND"] = 0x29;
    item_macro_ids["ITEM_DEF_SCARF"] = 0x2A;
    item_macro_ids["ITEM_STAMINA_BAND"] = 0x2B;
    item_macro_ids["ITEM_PLAIN_RIBBON"] = 0x2C;
    item_macro_ids["ITEM_SPECIAL_BAND"] = 0x2D;
    item_macro_ids["ITEM_ZINC_BAND"] = 0x2E;
    item_macro_ids["ITEM_DETECT_BAND"] = 0x2F;
    item_macro_ids["ITEM_ALERT_SPECS"] = 0x30;
    item_macro_ids["ITEM_DODGE_SCARF"] = 0x31;
    item_macro_ids["ITEM_BOUNCE_BAND"] = 0x32;
    item_macro_ids["ITEM_CURVE_BAND"] = 0x33;
    item_macro_ids["ITEM_WHIFF_SPECS"] = 0x34;
    item_macro_ids["ITEM_NO_AIM_SCOPE"] = 0x35;
    item_macro_ids["ITEM_LOCKON_SPECS"] = 0x36;
    item_macro_ids["ITEM_MUNCH_BELT"] = 0x37;
    item_macro_ids["ITEM_PASS_SCARF"] = 0x38;
    item_macro_ids["ITEM_WEATHER_BAND"] = 0x39;
    item_macro_ids["ITEM_FRIEND_BOW"] = 0x3A;
    item_macro_ids["ITEM_BEAUTY_SCARF"] = 0x3B;
    item_macro_ids["ITEM_SUN_RIBBON"] = 0x3C;
    item_macro_ids["ITEM_LUNAR_RIBBON"] = 0x3D;
    item_macro_ids["ITEM_RING_D"] = 0x3E;
    item_macro_ids["ITEM_RING_E"] = 0x3F;
    item_macro_ids["ITEM_RING_F"] = 0x40;
    item_macro_ids["ITEM_HEAL_SEED"] = 0x41;
    item_macro_ids["ITEM_WISH_STONE"] = 0x42;
    item_macro_ids["ITEM_ORAN_BERRY"] = 0x43;
    item_macro_ids["ITEM_SITRUS_BERRY"] = 0x44;
    item_macro_ids["ITEM_EYEDROP_SEED"] = 0x45;
    item_macro_ids["ITEM_REVIVER_SEED"] = 0x46;
    item_macro_ids["ITEM_BLINKER_SEED"] = 0x47;
    item_macro_ids["ITEM_DOOM_SEED"] = 0x48;
    item_macro_ids["ITEM_ALLURE_SEED"] = 0x49;
    item_macro_ids["ITEM_LIFE_SEED"] = 0x4A;
    item_macro_ids["ITEM_RAWST_BERRY"] = 0x4B;
    item_macro_ids["ITEM_HUNGER_SEED"] = 0x4C;
    item_macro_ids["ITEM_QUICK_SEED"] = 0x4D;
    item_macro_ids["ITEM_PECHA_BERRY"] = 0x4E;
    item_macro_ids["ITEM_CHERI_BERRY"] = 0x4F;
    item_macro_ids["ITEM_TOTTER_SEED"] = 0x50;
    item_macro_ids["ITEM_SLEEP_SEED"] = 0x51;
    item_macro_ids["ITEM_PLAIN_SEED"] = 0x52;
    item_macro_ids["ITEM_WARP_SEED"] = 0x53;
    item_macro_ids["ITEM_BLAST_SEED"] = 0x54;
    item_macro_ids["ITEM_GINSENG"] = 0x55;
    item_macro_ids["ITEM_JOY_SEED"] = 0x56;
    item_macro_ids["ITEM_CHESTO_BERRY"] = 0x57;
    item_macro_ids["ITEM_STUN_SEED"] = 0x58;
    item_macro_ids["ITEM_MAX_ELIXIR"] = 0x59;
    item_macro_ids["ITEM_PROTEIN"] = 0x5A;
    item_macro_ids["ITEM_CALCIUM"] = 0x5B;
    item_macro_ids["ITEM_IRON"] = 0x5C;
    item_macro_ids["ITEM_ZINC"] = 0x5D;
    item_macro_ids["ITEM_APPLE"] = 0x5E;
    item_macro_ids["ITEM_BIG_APPLE"] = 0x5F;
    item_macro_ids["ITEM_GRIMY_FOOD"] = 0x60;
    item_macro_ids["ITEM_HUGE_APPLE"] = 0x61;
    item_macro_ids["ITEM_WHITE_GUMMI"] = 0x62;
    item_macro_ids["ITEM_RED_GUMMI"] = 0x63;
    item_macro_ids["ITEM_BLUE_GUMMI"] = 0x64;
    item_macro_ids["ITEM_GRASS_GUMMI"] = 0x65;
    item_macro_ids["ITEM_YELLOW_GUMMI"] = 0x66;
    item_macro_ids["ITEM_CLEAR_GUMMI"] = 0x67;
    item_macro_ids["ITEM_ORANGE_GUMMI"] = 0x68;
    item_macro_ids["ITEM_PINK_GUMMI"] = 0x69;
    item_macro_ids["ITEM_BROWN_GUMMI"] = 0x6A;
    item_macro_ids["ITEM_SKY_GUMMI"] = 0x6B;
    item_macro_ids["ITEM_GOLD_GUMMI"] = 0x6C;
    item_macro_ids["ITEM_GREEN_GUMMI"] = 0x6D;
    item_macro_ids["ITEM_GRAY_GUMMI"] = 0x6E;
    item_macro_ids["ITEM_PURPLE_GUMMI"] = 0x6F;
    item_macro_ids["ITEM_ROYAL_GUMMI"] = 0x70;
    item_macro_ids["ITEM_BLACK_GUMMI"] = 0x71;
    item_macro_ids["ITEM_SILVER_GUMMI"] = 0x72;
    item_macro_ids["ITEM_BANANA"] = 0x73;
    item_macro_ids["ITEM_CHESTNUT"] = 0x74;
    item_macro_ids["ITEM_POKE"] = 0x75;
    item_macro_ids["ITEM_UPGRADE"] = 0x76;
    item_macro_ids["ITEM_KINGS_ROCK"] = 0x77;
    item_macro_ids["ITEM_THUNDERSTONE"] = 0x78;
    item_macro_ids["ITEM_DEEPSEASCALE"] = 0x79;
    item_macro_ids["ITEM_DEEPSEATOOTH"] = 0x7A;
    item_macro_ids["ITEM_SUN_STONE"] = 0x7B;
    item_macro_ids["ITEM_MOON_STONE"] = 0x7C;
    item_macro_ids["ITEM_FIRE_STONE"] = 0x7D;
    item_macro_ids["ITEM_WATER_STONE"] = 0x7E;
    item_macro_ids["ITEM_METAL_COAT"] = 0x7F;
    item_macro_ids["ITEM_LEAF_STONE"] = 0x80;
    item_macro_ids["ITEM_DRAGON_SCALE"] = 0x81;
    item_macro_ids["ITEM_LINK_CABLE"] = 0x82;
    item_macro_ids["ITEM_ICE_PART"] = 0x83;
    item_macro_ids["ITEM_STEEL_PART"] = 0x84;
    item_macro_ids["ITEM_ROCK_PART"] = 0x85;
    item_macro_ids["ITEM_MUSIC_BOX"] = 0x86;
    item_macro_ids["ITEM_KEY"] = 0x87;
    item_macro_ids["ITEM_TM_USED_TM"] = 0x88;
    item_macro_ids["ITEM_TM_FOCUS_PUNCH"] = 0x89;
    item_macro_ids["ITEM_TM_DRAGON_CLAW"] = 0x8A;
    item_macro_ids["ITEM_TM_WATER_PULSE"] = 0x8B;
    item_macro_ids["ITEM_TM_CALM_MIND"] = 0x8C;
    item_macro_ids["ITEM_TM_ROAR"] = 0x8D;
    item_macro_ids["ITEM_TM_TOXIC"] = 0x8E;
    item_macro_ids["ITEM_HAIL_ORB"] = 0x8F;
    item_macro_ids["ITEM_TM_BULK_UP"] = 0x90;
    item_macro_ids["ITEM_TM_BULLET_SEED"] = 0x91;
    item_macro_ids["ITEM_TM_HIDDEN_POWER"] = 0x92;
    item_macro_ids["ITEM_SUNNY_ORB"] = 0x93;
    item_macro_ids["ITEM_TM_TAUNT"] = 0x94;
    item_macro_ids["ITEM_TM_ICE_BEAM"] = 0x95;
    item_macro_ids["ITEM_TM_BLIZZARD"] = 0x96;
    item_macro_ids["ITEM_TM_HYPER_BEAM"] = 0x97;
    item_macro_ids["ITEM_TM_LIGHT_SCREEN"] = 0x98;
    item_macro_ids["ITEM_TM_PROTECT"] = 0x99;
    item_macro_ids["ITEM_RAINY_ORB"] = 0x9A;
    item_macro_ids["ITEM_TM_GIGA_DRAIN"] = 0x9B;
    item_macro_ids["ITEM_TM_SAFEGUARD"] = 0x9C;
    item_macro_ids["ITEM_TM_FRUSTRATION"] = 0x9D;
    item_macro_ids["ITEM_TM_SOLARBEAM"] = 0x9E;
    item_macro_ids["ITEM_TM_IRON_TAIL"] = 0x9F;
    item_macro_ids["ITEM_TM_THUNDERBOLT"] = 0xA0;
    item_macro_ids["ITEM_TM_THUNDER"] = 0xA1;
    item_macro_ids["ITEM_TM_EARTHQUAKE"] = 0xA2;
    item_macro_ids["ITEM_TM_RETURN"] = 0xA3;
    item_macro_ids["ITEM_TM_DIG"] = 0xA4;
    item_macro_ids["ITEM_TM_PSYCHIC"] = 0xA5;
    item_macro_ids["ITEM_TM_SHADOW_BALL"] = 0xA6;
    item_macro_ids["ITEM_TM_BRICK_BREAK"] = 0xA7;
    item_macro_ids["ITEM_EVASION_ORB"] = 0xA8;
    item_macro_ids["ITEM_TM_REFLECT"] = 0xA9;
    item_macro_ids["ITEM_TM_SHOCK_WAVE"] = 0xAA;
    item_macro_ids["ITEM_TM_FLAMETHROWER"] = 0xAB;
    item_macro_ids["ITEM_TM_SLUDGE_BOMB"] = 0xAC;
    item_macro_ids["ITEM_SANDY_ORB"] = 0xAD;
    item_macro_ids["ITEM_TM_FIRE_BLAST"] = 0xAE;
    item_macro_ids["ITEM_ROCKY_ORB"] = 0xAF;
    item_macro_ids["ITEM_TM_AERIAL_ACE"] = 0xB0;
    item_macro_ids["ITEM_TM_TORMENT"] = 0xB1;
    item_macro_ids["ITEM_TM_FACADE"] = 0xB2;
    item_macro_ids["ITEM_TM_SECRET_POWER"] = 0xB3;
    item_macro_ids["ITEM_TM_REST"] = 0xB4;
    item_macro_ids["ITEM_TM_ATTRACT"] = 0xB5;
    item_macro_ids["ITEM_TM_THIEF"] = 0xB6;
    item_macro_ids["ITEM_TM_STEEL_WING"] = 0xB7;
    item_macro_ids["ITEM_TM_SKILL_SWAP"] = 0xB8;
    item_macro_ids["ITEM_SNATCH_ORB"] = 0xB9;
    item_macro_ids["ITEM_TM_OVERHEAT"] = 0xBA;
    item_macro_ids["ITEM_TM_WIDE_SLASH"] = 0xBB;
    item_macro_ids["ITEM_TM_EXCAVATE"] = 0xBC;
    item_macro_ids["ITEM_TM_SPIN_SLASH"] = 0xBD;
    item_macro_ids["ITEM_SEE_TRAP_ORB"] = 0xBE;
    item_macro_ids["ITEM_MUG_ORB"] = 0xBF;
    item_macro_ids["ITEM_REBOUND_ORB"] = 0xC0;
    item_macro_ids["ITEM_LOB_ORB"] = 0xC1;
    item_macro_ids["ITEM_SWITCHER_ORB"] = 0xC2;
    item_macro_ids["ITEM_BLOWBACK_ORB"] = 0xC3;
    item_macro_ids["ITEM_WARP_ORB"] = 0xC4;
    item_macro_ids["ITEM_TRANSFER_ORB"] = 0xC5;
    item_macro_ids["ITEM_SLOW_ORB"] = 0xC6;
    item_macro_ids["ITEM_QUICK_ORB"] = 0xC7;
    item_macro_ids["ITEM_LUMINOUS_ORB"] = 0xC8;
    item_macro_ids["ITEM_PETRIFY_ORB"] = 0xC9;
    item_macro_ids["ITEM_STAYAWAY_ORB"] = 0xCA;
    item_macro_ids["ITEM_POUNCE_ORB"] = 0xCB;
    item_macro_ids["ITEM_TRAWL_ORB"] = 0xCC;
    item_macro_ids["ITEM_CLEANSE_ORB"] = 0xCD;
    item_macro_ids["ITEM_OBSERVER_ORB"] = 0xCE;
    item_macro_ids["ITEM_DECOY_ORB"] = 0xCF;
    item_macro_ids["ITEM_SLUMBER_ORB"] = 0xD0;
    item_macro_ids["ITEM_TOTTER_ORB"] = 0xD1;
    item_macro_ids["ITEM_TWO_EDGE_ORB"] = 0xD2;
    item_macro_ids["ITEM_SILENCE_ORB"] = 0xD3;
    item_macro_ids["ITEM_ESCAPE_ORB"] = 0xD4;
    item_macro_ids["ITEM_SCANNER_ORB"] = 0xD5;
    item_macro_ids["ITEM_RADAR_ORB"] = 0xD6;
    item_macro_ids["ITEM_DROUGHT_ORB"] = 0xD7;
    item_macro_ids["ITEM_TRAPBUST_ORB"] = 0xD8;
    item_macro_ids["ITEM_ROLLCALL_ORB"] = 0xD9;
    item_macro_ids["ITEM_INVISIFY_ORB"] = 0xDA;
    item_macro_ids["ITEM_ONE_SHOT_ORB"] = 0xDB;
    item_macro_ids["ITEM_IDENTIFY_ORB"] = 0xDC;
    item_macro_ids["ITEM_TM_VACUUM_CUT"] = 0xDD;
    item_macro_ids["ITEM_REVIVER_ORB"] = 0xDE;
    item_macro_ids["ITEM_SHOCKER_ORB"] = 0xDF;
    item_macro_ids["ITEM_SIZEBUST_ORB"] = 0xE0;
    item_macro_ids["ITEM_ONE_ROOM_ORB"] = 0xE1;
    item_macro_ids["ITEM_FILL_IN_ORB"] = 0xE2;
    item_macro_ids["ITEM_TRAPPER_ORB"] = 0xE3;
    item_macro_ids["ITEM_POSSESS_ORB"] = 0xE4;
    item_macro_ids["ITEM_ITEMIZER_ORB"] = 0xE5;
    item_macro_ids["ITEM_HURL_ORB"] = 0xE6;
    item_macro_ids["ITEM_MOBILE_ORB"] = 0xE7;
    item_macro_ids["ITEM_TOSS_ORB"] = 0xE8;
    item_macro_ids["ITEM_STAIRS_ORB"] = 0xE9;
    item_macro_ids["ITEM_LONGTOSS_ORB"] = 0xEA;
    item_macro_ids["ITEM_PIERCE_ORB"] = 0xEB;
    item_macro_ids["ITEM_HM_CUT"] = 0xEC;
    item_macro_ids["ITEM_HM_FLY"] = 0xED;
    item_macro_ids["ITEM_HM_SURF"] = 0xEE;
    item_macro_ids["ITEM_HM_STRENGTH"] = 0xEF;
    item_macro_ids["ITEM_HM_FLASH"] = 0xF0;
    item_macro_ids["ITEM_HM_ROCK_SMASH"] = 0xF1;
    item_macro_ids["ITEM_HM_WATERFALL"] = 0xF2;
    item_macro_ids["ITEM_HM_DIVE"] = 0xF3;
    item_macro_ids["ITEM_LINK_BOX"] = 0xF4;
    item_macro_ids["ITEM_SWITCH_BOX"] = 0xF5;
    item_macro_ids["ITEM_WEAVILE_FIG"] = 0xF6;
    item_macro_ids["ITEM_MIME_JR_FIG"] = 0xF7;
    item_macro_ids["ITEM_BEATUP_ORB"] = 0xF8;
    item_macro_ids["ITEM_G_MACHINE_6"] = 0xF9;
    item_macro_ids["ITEM_G_MACHINE_7"] = 0xFA;
    item_macro_ids["ITEM_G_MACHINE_8"] = 0xFB;
}

int get_item_id(string item_macro){
    if (item_macro_ids.size() == 0)
    {
        set_item_ids();
    }
    if (item_macro_ids.count(item_macro))
    {
        return item_macro_ids.at(item_macro);
    }
    else
    {
        FATAL_ERROR("Unknown move %s when generating learnsets. Make sure the move is registered in tools/data/move_id_json.cpp.\n", item_macro.c_str());
    }
}

int get_num_item_ids(){
    if (item_macro_ids.size() == 0)
    {
        set_item_ids();
    }
    return item_macro_ids.size();
}
