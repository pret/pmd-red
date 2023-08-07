#include "global.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "friend_area.h"
#include "pokemon.h"
#include "code_800D090.h"

EWRAM_DATA bool8 gBoughtFriendAreas[NUM_FRIEND_AREAS] = {0};
EWRAM_DATA_2 bool8 *gFriendAreas = {0};


extern bool8 *gFriendAreas;

extern u8 *gFriendAreaDescriptions[];
extern const char *gFriendAreaNames[];
extern const char gUnknown_81098A4;
extern const char gUnknown_81098AC;

extern void sub_8090FEC(u32, u8 *r1, u32);

const struct FriendAreaSettings gFriendAreaSettings[NUM_FRIEND_AREAS] =
{
    [NONE] = {
        .num_pokemon = 0,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 0,
    },
    [BOUNTIFUL_SEA] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500,
    },
    [TREASURE_SEA] = {
        .num_pokemon = 10,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 4500,
    },
    [SERENE_SEA] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8000,
    },
    [DEEP_SEA_FLOOR] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500,
    },
    [DEEP_SEA_CURRENT] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0,
    },
    [SEAFLOOR_CAVE] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0,
    },
    [SHALLOW_BEACH] = {
        .num_pokemon = 5,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000,
    },
    [MT_DEEPGREEN] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 130,
    },
    [MT_CLEFT] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000,
    },
    [MT_MOONVIEW] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0,
    },
    [RAINBOW_PEAK] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500,
    },
    [WILD_PLAINS] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 100,
    },
    [BEAU_PLAINS] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 600,
    },
    [SKY_BLUE_PLAINS] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0,
    },
    [SAFARI] = {
        .num_pokemon = 15,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 700,
    },
    [SCORCHED_PLAINS] = {
        .num_pokemon = 10,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000,
    },
    [SACRED_FIELD] =  {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500
    },
    [MIST_RISE_FOREST] = {
        .num_pokemon = 14,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 150
    },
    [FLYAWAY_FOREST] = {
        .num_pokemon = 12,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 550
    },
    [OVERGROWN_FOREST] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 600
    },
    [ENERGETIC_FOREST] = {
        .num_pokemon = 15,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5000
    },
    [MUSHROOM_FOREST] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [HEALING_FOREST] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [TRANSFORM_FOREST] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [SECRETIVE_FOREST] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500
    },
    [RUB_A_DUB_RIVER] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [TADPOLE_POND] = {
        .num_pokemon = 9,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 500
    },
    [TURTLESHELL_POND] = {
        .num_pokemon = 10,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500
    },
    [MYSTIC_LAKE] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 2500
    },
    [WATERFALL_LAKE] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 3500
    },
    [PEANUT_SWAMP] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 2500
    },
    [POISON_SWAMP] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8500
    },
    [ECHO_CAVE] = {
        .num_pokemon = 11,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 7500
    },
    [CRYPTIC_CAVE] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 6500
    },
    [DRAGON_CAVE] = {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0
    },
    [BOULDER_CAVE] = {
        .num_pokemon = 4,
        .unlock_condition = UNLOCK_WONDER_MAIL,
        .price = 0
    },
    [JUNGLE] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 800
    },
    [DECREPIT_LAB] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [MT_DISCIPLINE] = {
        .num_pokemon = 11,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1200
    },
    [THUNDER_MEADOW] = {
        .num_pokemon = 11,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [POWER_PLANT] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 600
    },
    [CRATER] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 7500
    },
    [FURNACE_DESERT] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8500
    },
    [AGED_CHAMBER_AN] = {
        .num_pokemon = 14,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500
    },
    [AGED_CHAMBER_O_EXCLAIM] = {
        .num_pokemon = 14,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 5500
    },
    [ANCIENT_RELIC] = {
        .num_pokemon = 6,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8000
    },
    [DARKNESS_RIDGE] = {
        .num_pokemon = 13,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [FRIGID_CAVERN] = {
        .num_pokemon = 7,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 9000
    },
    [ICE_FLOE_BEACH] = {
        .num_pokemon = 5,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 9500
    },
    [VOLCANIC_PIT] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [STRATOS_LOOKOUT] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [RAVAGED_FIELD] = {
        .num_pokemon = 5,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [MAGNETIC_QUARRY] = {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_SHOP_STORY,
        .price = 1000
    },
    [LEGENDARY_ISLAND] = {
        .num_pokemon = 3,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 7500
    },
    [SOUTHERN_ISLAND] = {
        .num_pokemon = 2,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 9500
    },
    [ENCLOSED_ISLAND] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_LEGENDARY_REQUEST,
        .price = 0
    },
    [FINAL_ISLAND] = {
        .num_pokemon = 1,
        .unlock_condition = UNLOCK_SHOP_POST_GAME,
        .price = 8500
    },
};

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

#ifdef NONMATCHING
void sub_8092404(u8 r0, u16 *r1, bool8 r2, bool8 r3)
{
    s32 counter;
    bool32 flag;
    s32 r6;
    struct PokemonStruct *pokemon;

    r6 = 0;
    for(counter = 0; counter <= 412; counter++)
    {
        pokemon = &gRecruitedPokemonRef->pokemon[counter];
        if((u8)(pokemon->unk0) & 1)
        {
            if((pokemon->isTeamLeader == 0) || r2)
            {
                flag = pokemon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER;
                if(!flag || r3)
                {
                    if(sub_80923D4(counter) == r0)
                    {
                        if(r6 <= 15)
                        {
                            r1[r6] = counter;
                            r6++;
                        }
                    }
                }
            }
        }
    }
    r1[r6] = 0xffff;
}
#else
NAKED void sub_8092404(u8 r0, u16 *r1, bool8 r2, bool8 r3)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmov r7, r10\n"
	"\tmov r6, r9\n"
	"\tmov r5, r8\n"
	"\tpush {r5-r7}\n"
	"\tmov r10, r1\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tmov r9, r0\n"
	"\tlsls r2, 24\n"
	"\tlsrs r2, 24\n"
	"\tmov r8, r2\n"
	"\tlsls r3, 24\n"
	"\tlsrs r7, r3, 24\n"
	"\tmovs r6, 0\n"
	"\tmovs r4, 0\n"
	"\tmov r5, r10\n"
"_08092426:\n"
	"\tmovs r0, 0x58\n"
	"\tadds r1, r4, 0\n"
	"\tmuls r1, r0\n"
	"\tldr r0, _08092494\n"
	"\tldr r0, [r0]\n"
	"\tadds r2, r1, r0\n"
	"\tldrb r1, [r2]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _08092472\n"
	"\tldrb r0, [r2, 0x2]\n"
	"\tcmp r0, 0\n"
	"\tbeq _08092448\n"
	"\tmov r0, r8\n"
	"\tcmp r0, 0\n"
	"\tbeq _08092472\n"
"_08092448:\n"
	"\tmovs r1, 0\n"
	"\tldrb r0, [r2, 0x4]\n"
	"\tcmp r0, 0x41\n"
	"\tbne _08092452\n"
	"\tmovs r1, 0x1\n"
"_08092452:\n"
	"\tcmp r1, 0\n"
	"\tbeq _0809245A\n"
	"\tcmp r7, 0\n"
	"\tbeq _08092472\n"
"_0809245A:\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_80923D4\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r0, r9\n"
	"\tbne _08092472\n"
	"\tcmp r6, 0xF\n"
	"\tbgt _08092472\n"
	"\tstrh r4, [r5]\n"
	"\tadds r5, 0x2\n"
	"\tadds r6, 0x1\n"
"_08092472:\n"
	"\tadds r4, 0x1\n"
	"\tmovs r0, 0xCE\n"
	"\tlsls r0, 1\n"
	"\tcmp r4, r0\n"
	"\tble _08092426\n"
	"\tlsls r0, r6, 1\n"
	"\tadd r0, r10\n"
	"\tldr r2, _08092498\n"
	"\tadds r1, r2, 0\n"
	"\tstrh r1, [r0]\n"
	"\tpop {r3-r5}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tmov r10, r5\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08092494: .4byte gRecruitedPokemonRef\n"
"_08092498: .4byte 0x0000ffff");
}
#endif

void sub_809249C(u8 friendArea, bool8 clear)
{
    s32 index;
    bool32 dungeonCheck;
    bool32 isTeamLeader;

    if(!gFriendAreas[friendArea])
        return;
    for(index = 0; index < NUM_MONSTERS; index++)
    {
        struct PokemonStruct *pokemon = &gRecruitedPokemonRef->pokemon[index]; 
        
        if((u8)(pokemon->unk0) & 1)
        {
            if(sub_80923D4(index) == friendArea)
            {
                dungeonCheck = pokemon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER;
                if(dungeonCheck || (isTeamLeader = pokemon->isTeamLeader != FALSE, isTeamLeader))
                    clear = FALSE;
                else
                    pokemon->unk0 = 0;
            }
        }
    }
    if(clear)
    {
        gFriendAreas[friendArea] = FALSE;
    }
}

const char *GetFriendAreaName(u8 index)
{
    return gFriendAreaNames[index];
}

u8 GetFriendAreaUnlockCondition(u8 index)
{
    return gFriendAreaSettings[index].unlock_condition;
}

s32 GetFriendAreaPrice(u8 index)
{
    return gFriendAreaSettings[index].price;
}

void sub_8092558(u8 *buffer, u8 index)
{
    // colors the friend area name green and prints to buffer?
    sprintfStatic(buffer, &gUnknown_81098A4, gFriendAreaNames[index]);
}

void sub_8092578(u8 *buffer, u8 index, bool8 printPrice)
{
    // I think this is when we buy the friend area from wigglytuff
    u8 priceBuffer[0x14];
    if(printPrice)
    {
        sub_8090FEC(gFriendAreaSettings[index].price, priceBuffer, 1);
        sprintfStatic(buffer, &gUnknown_81098AC, gFriendAreaNames[index], 96, priceBuffer);
    }
    else
    {
        strcpy(buffer, gFriendAreaNames[index]);
    }
}

u8 *GetFriendAreaDescription(u8 index)
{
    return gFriendAreaDescriptions[index];
}

void UnlockFriendArea(u8 index)
{
    gFriendAreas[index] = TRUE;
}

bool8 GetFriendAreaStatus(u8 index)
{
    return gFriendAreas[index];
}

bool8 HasAllFriendAreas(void)
{
    s32 counter;
    for(counter = 1; counter < NUM_FRIEND_AREAS; counter++)
    {
        if(!gFriendAreas[counter])
        {
            return FALSE;
        }
    }
    return TRUE;
}

void sub_8092638(u8 friendArea, struct unkStruct_8092638 *param_2, bool8 checkLeader, bool8 checkDungeon)
{
    struct PokemonStruct *pokeStruct;
    s32 counter;
    s32 iVar4;


    iVar4 = 0;

    for(counter = 0; counter < friendArea; counter++)
    {
        iVar4 += gFriendAreaSettings[counter].num_pokemon;
    }
    param_2->unk8 = iVar4;

    param_2->hasFriendArea = gFriendAreas[counter];
    if (param_2->hasFriendArea) {
        param_2->unk2 = 0;
        param_2->numPokemon = gFriendAreaSettings[counter].num_pokemon;

        for(counter = 0; counter < param_2->numPokemon; counter++, iVar4++)
        {
            pokeStruct = &gRecruitedPokemonRef->pokemon[iVar4];
            if (((((u8)pokeStruct->unk0 & 1) != 0) &&
                ((checkLeader == 0 || (!pokeStruct->isTeamLeader)))) &&
                ((checkDungeon == 0 || ((pokeStruct->dungeonLocation).id != DUNGEON_JOIN_LOCATION_PARTNER)))) {
                param_2->unk2++;
            }
        }
    }
    else {
        param_2->unk2 = 0;
        param_2->numPokemon = 0;
    }
}
