#include "global.h"
#include "constants/friend_area.h"
#include "friend_area.h"

extern bool8 gBoughtFriendAreas[NUM_FRIEND_AREAS];
extern bool8 *gFriendAreas;


extern struct FriendAreaSettings gFriendAreaSettings[NUM_FRIEND_AREAS];

// TODO uncomment when all references have been moved
//static struct FriendAreaSettings gFriendAreaSettings[NUM_FRIEND_AREAS] = 
//{
//    [NONE] = {
//        .num_pokemon = 0,
//        .unlock_condition = 0,
//        .price = 0,
//    },
//    [BOUNTIFUL_SEA] = {
//        .num_pokemon = 9,
//        .unlock_condition = 1,
//        .price = 5500,
//    },
//    [TREASURE_SEA] = {
//        .num_pokemon = 10,
//        .unlock_condition = 1,
//        .price = 4500,
//    },
//    [SERENE_SEA] = {
//        .num_pokemon = 4,
//        .unlock_condition = 1,
//        .price = 8000,
//    },
//    [DEEP_SEA_FLOOR] = {
//        .num_pokemon = 12,
//        .unlock_condition = 1,
//        .price = 5500,
//    },
//    [DEEP_SEA_CURRENT] = {
//        .num_pokemon = 1,
//        .unlock_condition = 3,
//        .price = 0,
//    },
//    [SEAFLOOR_CAVE] = {
//        .num_pokemon = 0,
//        .unlock_condition = 0,
//        .price = 0,
//    },
//    [SHALLOW_CAVE] = {
//        .num_pokemon = 5,
//        .unlock_condition = 1,
//        .price = 5000,
//    },
//    [MT_DEEPGREEN] = {
//        .num_pokemon = 12,
//        .unlock_condition = 0,
//        .price = 130,
//    },
//    [MT_CLEFT] = {
//        .num_pokemon = 9,
//        .unlock_condition = 1,
//        .price = 5000,
//    },
//    [MT_MOONVIEW] = {
//        .num_pokemon = 6,
//        .unlock_condition = 2,
//        .price = 0,
//    },
//    [RAINBOW_PEAK] = {
//        .num_pokemon = 1,
//        .unlock_condition = 1,
//        .price = 6500,
//    },
//    [WILD_PLAINS] = {
//        .num_pokemon = 13,
//        .unlock_condition = 0,
//        .price = 100,
//    },
//    [BEAU_PLAINS] = {
//        .num_pokemon = 12,
//        .unlock_condition = 0,
//        .price = 600,
//    },
//    [SKY_BLUE_PLAINS] = {
//        .num_pokemon = 13,
//        .unlock_condition = 2,
//        .price = 0,
//    },
//    [SAFARI] = {
//        .num_pokemon = 15,
//        .unlock_condition = 0,
//        .price = 700,
//    },
//    [SCORCHED_PLAINS] = {
//        .num_pokemon = 10,
//        .unlock_condition = 1,
//        .price = 5000,
//    },
//    [SACRED_FIELD] = {
//        .num_pokemon = 3,
//        .unlock_condition = 1,
//        .price = 6500
//    },
//    [MIST_RISE_FOREST] = {
//        .num_pokemon = 14,
//        .unlock_condition = 0,
//        .price = 150
//    },
//    [FLYAWAY_FOREST] = {
//        .num_pokemon = 12,
//        .unlock_condition = 0,
//        .price = 550
//    },
//    [OVERGROWN_FOREST] = {
//        .num_pokemon = 9,
//        .unlock_condition = 0,
//        .price = 600
//    },
//    [ENERGETIC_FOREST] = {
//        .num_pokemon = 15,
//        .unlock_condition = 1,
//        .price = 5000
//    },
//    [MUSHROOM_FOREST] = {
//        .num_pokemon = 7,
//        .unlock_condition = 0,
//        .price = 500
//    },
//    [HEALING_FOREST] = {
//        .num_pokemon = 1,
//        .unlock_condition = 3,
//        .price = 0
//    },
//    [TRANSFORM_FOREST] = {
//        .num_pokemon = 6,
//        .unlock_condition = 0,
//        .price = 500
//    },
//    [SECRETIVE_FOREST] = {
//        .num_pokemon = 9,
//        .unlock_condition = 1,
//        .price = 6500
//    },
//    [RUB_A_DUB_RIVER] = {
//        .num_pokemon = 7,
//        .unlock_condition = 0,
//        .price = 500
//    },
//    [TADPOLE_POND] = {
//        .num_pokemon = 9,
//        .unlock_condition = 0,
//        .price = 500
//    },
//    [TURTLESHELL_POND] = {
//        .num_pokemon = 10,
//        .unlock_condition = 1,
//        .price = 5500
//    },
//    [MYSTIC_LAKE] = {
//        .num_pokemon = 4,
//        .unlock_condition = 1,
//        .price = 2500
//    },
//    [WATERFALL_LAKE] = {
//        .num_pokemon = 4,
//        .unlock_condition = 1,
//        .price = 3500
//    },
//    [PEANUT_SWAMP] = {
//        .num_pokemon = 7,
//        .unlock_condition = 0,
//        .price = 2500
//    },
//    [POISON_SWAMP] = {
//        .num_pokemon = 6,
//        .unlock_condition = 1,
//        .price = 8500
//    },
//    [ECHO_CAVE] = {
//        .num_pokemon = 11,
//        .unlock_condition = 1,
//        .price = 7500
//    },
//    [CRYPTIC_CAVE] = {
//        .num_pokemon = 1,
//        .unlock_condition = 1,
//        .price = 6500
//    },
//    [DRAGON_CAVE] = {
//        .num_pokemon = 3,
//        .unlock_condition = 2,
//        .price = 0
//    },
//    [BOULDER_CAVE] = {
//        .num_pokemon = 4,
//        .unlock_condition = 2,
//        .price = 0
//    },
//    [JUNGLE] = {
//        .num_pokemon = 13,
//        .unlock_condition = 0,
//        .price = 800
//    },
//    [DECRPEPIT_LAB] = {
//        .num_pokemon = 7,
//        .unlock_condition = 0,
//        .price = 1000
//    },
//    [MT_DISCIPLINE] = {
//        .num_pokemon = 11,
//        .unlock_condition = 0,
//        .price = 1200
//    },
//    [THUNDER_MEADOW] = {
//        .num_pokemon = 11,
//        .unlock_condition = 0,
//        .price = 1000
//    },
//    [POWER_PLANT] = {
//        .num_pokemon = 6,
//        .unlock_condition = 0,
//        .price = 600
//    },
//    [CRATER] = {
//        .num_pokemon = 7,
//        .unlock_condition = 1,
//        .price = 7500
//    },
//    [FURNACE_DESERT] = {
//        .num_pokemon = 7,
//        .unlock_condition = 1,
//        .price = 8500
//    },
//    [AGED_CHAMBER_AN] = {
//        .num_pokemon = 14,
//        .unlock_condition = 1,
//        .price = 5500
//    },
//    [AGED_CHAMBER_O_EXCLAIM] = {
//        .num_pokemon = 14,
//        .unlock_condition = 1,
//        .price = 5500
//    },
//    [ANCIENT_RELIC] = {
//        .num_pokemon = 6,
//        .unlock_condition = 1,
//        .price = 8000
//    },
//    [DARKNESS_RIDGE] = {
//        .num_pokemon = 13,
//        .unlock_condition = 3,
//        .price = 0
//    },
//    [FRIGID_CAVERN] = {
//        .num_pokemon = 7,
//        .unlock_condition = 1,
//        .price = 9000
//    },
//    [ICE_FLOE_BEACH] = {
//        .num_pokemon = 5,
//        .unlock_condition = 1,
//        .price = 9500
//    },
//    [VOLCANIC_PIT] = {
//        .num_pokemon = 1,
//        .unlock_condition = 3,
//        .price = 0
//    },
//    [STRATOS_LOOKOUT] = {
//        .num_pokemon = 1,
//        .unlock_condition = 3,
//        .price = 0
//    },
//    [RAVAGED_FIELD] = {
//        .num_pokemon = 5,
//        .unlock_condition = 0,
//        .price = 1000
//    },
//    [MAGNETIC_QUARRY] = {
//        .num_pokemon = 3,
//        .unlock_condition = 0,
//        .price = 1000
//    },
//    [LEGENDARY_ISLAND] = {
//        .num_pokemon = 3,
//        .unlock_condition = 3,
//        .price = 7500
//    },
//    [SOUTHERN_ISLAND] = {
//        .num_pokemon = 2,
//        .unlock_condition = 1,
//        .price = 9500
//    },
//    [ENCLOSED_ISLAND] = {
//        .num_pokemon = 1,
//        .unlock_condition = 3,
//        .price = 0
//    },
//    [FINAL_ISLAND] = {
//        .num_pokemon = 1,
//        .unlock_condition = 1,
//        .price = 8500
//    },
//};

void LoadFriendAreas(void)
{
    gFriendAreas = gBoughtFriendAreas;
}

bool8 *GetBoughtFriendAreas(void)
{
    return gBoughtFriendAreas;
}

void InitializeFriendAreas(void)
{
    s32 counter;
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        gFriendAreas[counter] = FALSE;
    }
}

u8 sub_80923D4(s32 target)
{
    s32 counter;
    s32 sum = 0;
    for(counter = 0; counter < NUM_FRIEND_AREAS; counter++)
    {
        sum += gFriendAreaSettings[counter].num_pokemon;
        if(sum > target)
        {
            return counter;
        }
    }
    return 0;
}


