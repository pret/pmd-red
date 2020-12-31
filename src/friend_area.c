#include "global.h"
#include "constants/friend_area.h"
#include "friend_area.h"

extern bool8 gBoughtFriendAreas[NUM_FRIEND_AREAS];
extern bool8 *gFriendAreas;


extern struct FriendAreaSettings gFriendAreaSettings[NUM_FRIEND_AREAS];

struct unkStruct_203B45C
{
    // size: 0x58?
    u16 unk0;
    s16 unk2;
    u8 unk4[0x24];
    u8 unk28;
    u8 unk29[0x2f];
};

struct unkFriendAreaStruct
{
    // size: 0x18
    u32 unk0;
    u32 unk4;
    u32 padding[4];
};

extern struct unkStruct_203B45C gUnknown_203B45C[];

extern struct FriendAreaSettings gFriendAreaSettings[58];
extern bool8 *gFriendAreas;

extern u32 gFriendAreaDescriptions[];
extern const char *gFriendAreaNames[];
extern u32 gUnknown_81098A4;

extern void sub_800D158(u8 *buffer, u32 *r1, const char *r2, ...);
extern void sub_8090FEC(u32, u32 *r1, u32);


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

#ifdef NONMATCHING
void sub_8092404(u8 r0, u16 *r1, bool8 r2, bool8 r3)
{
    s32 counter;
    bool32 flag;
    s32 r6;
    r6 = 0;
    for(counter = 0; counter <= 412; counter++)
    {
        if((u8)(gUnknown_203B45C[counter].unk0) & 1)
        {
            if(((u8)gUnknown_203B45C[counter].unk2 == 0) || r2)
            {
                flag = (u8)gUnknown_203B45C[counter].unk4[0] == 65;
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
"_08092494: .4byte gUnknown_203B45C\n"
"_08092498: .4byte 0x0000ffff");
} 
#endif

#ifdef NONMATCHING
void sub_809249C(u8 index, u8 clear)
{
    s32 counter;
    bool32 flag;
    u8 temp8;
    u8 neg8;

    if(!gFriendAreas[index])
        return;
    for(counter = 0; counter <= 412; counter++)
    {
        if((u8)(gUnknown_203B45C[counter].unk0) & 1)
        {
            if(sub_80923D4(counter) == index)
            {
                flag = (u8)gUnknown_203B45C[counter].unk4[0] == 65;
                if(!flag)
                {
                    temp8 = (u8)gUnknown_203B45C[counter].unk2;
                    neg8 = -temp8;
                    neg8 |= temp8;
                    // still tries to left shift before the right shift..
                    neg8 >>= 7;
                    if(neg8 != 0)
                    {
                        clear = 0;
                    }
                    else
                    {
                       gUnknown_203B45C[counter].unk0 = neg8;
                    }
                }
            }
        }
    }
    if(clear)
    {
        gFriendAreas[index] = FALSE;
    }
}
#else
NAKED void sub_809249C(u8 index, u8 clear) 
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tlsls r0, 24\n"
	"\tlsrs r6, r0, 24\n"
	"\tlsls r1, 24\n"
	"\tlsrs r7, r1, 24\n"
	"\tldr r0, _080924F8\n"
	"\tldr r0, [r0]\n"
	"\tadds r0, r6\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0809251A\n"
	"\tmovs r5, 0\n"
"_080924B4:\n"
	"\tldr r2, _080924FC\n"
	"\tmovs r0, 0x58\n"
	"\tadds r1, r5, 0\n"
	"\tmuls r1, r0\n"
	"\tldr r0, [r2]\n"
	"\tadds r4, r0, r1\n"
	"\tldrb r1, [r4]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _08092502\n"
	"\tadds r0, r5, 0\n"
	"\tbl sub_80923D4\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r0, r6\n"
	"\tbne _08092502\n"
	"\tmovs r1, 0\n"
	"\tldrb r0, [r4, 0x4]\n"
	"\tcmp r0, 0x41\n"
	"\tbne _080924E2\n"
	"\tmovs r1, 0x1\n"
"_080924E2:\n"
	"\tcmp r1, 0\n"
	"\tbne _080924F2\n"
	"\tldrb r1, [r4, 0x2]\n"
	"\tnegs r0, r1\n"
	"\torrs r0, r1\n"
	"\tlsrs r0, 31\n"
	"\tcmp r0, 0\n"
	"\tbeq _08092500\n"
"_080924F2:\n"
	"\tmovs r7, 0\n"
	"\tb _08092502\n"
	"\t.align 2, 0\n"
"_080924F8: .4byte gFriendAreas\n"
"_080924FC: .4byte gUnknown_203B45C\n"
"_08092500:\n"
	"\tstrh r0, [r4]\n"
"_08092502:\n"
	"\tadds r5, 0x1\n"
	"\tmovs r0, 0xCE\n"
	"\tlsls r0, 1\n"
	"\tcmp r5, r0\n"
	"\tble _080924B4\n"
	"\tcmp r7, 0\n"
	"\tbeq _0809251A\n"
	"\tldr r0, _08092520\n"
	"\tldr r0, [r0]\n"
	"\tadds r0, r6\n"
	"\tmovs r1, 0\n"
	"\tstrb r1, [r0]\n"
"_0809251A:\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08092520: .4byte gFriendAreas");
}
#endif

const char *GetFriendAreaName(u8 index)
{
    return gFriendAreaNames[index];
}

u8 GetFriendAreaUnlockCondition(u8 index)
{
    return gFriendAreaSettings[index].unlock_condition;
}

u32 GetFriendAreaPrice(u8 index)
{
    return gFriendAreaSettings[index].price;
}

void sub_8092558(u8 *buffer, u8 index)
{
    // colors the friend area name green and prints to buffer?
    sub_800D158(buffer, &gUnknown_81098A4, gFriendAreaNames[index]);
}

#ifdef NONMATCHING
void sub_8092578(u8 *buffer, u8 index, u8 r2)
{
    // I think this is when we buy the friend area from wigglytuff
    struct unkFriendAreaStruct temp;
    if(r2)
    {
        sub_8090FEC(gFriendAreaSettings[index].price, &(temp.unk4), 1);
        // TODO: There's some stack storage here in the middle calling this func
        //         add     r0, sp, 0x4
        //          str     r0, [sp] 
        //temp.unk0 = temp.unk4;
        sub_800D158(buffer, &gUnknown_81098AC, gFriendAreaNames[index], 96);
    }
    else
    {
        strcpy(buffer, gFriendAreaNames[index]);
    }
}
#else
NAKED void sub_8092578(u8 *buffer, u8 index, u8 r2)
{
        asm_unified("\tpush {r4,r5,lr}\n"
	"\tsub sp, 0x18\n"
	"\tadds r5, r0, 0\n"
	"\tlsls r1, 24\n"
	"\tlsrs r4, r1, 24\n"
	"\tlsls r2, 24\n"
	"\tcmp r2, 0\n"
	"\tbeq _080925C0\n"
	"\tldr r0, _080925B4\n"
	"\tlsls r1, r4, 3\n"
	"\tadds r0, 0x4\n"
	"\tadds r1, r0\n"
	"\tldr r0, [r1]\n"
	"\tadd r1, sp, 0x4\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_8090FEC\n"
	"\tldr r1, _080925B8\n"
	"\tldr r2, _080925BC\n"
	"\tlsls r0, r4, 2\n"
	"\tadds r0, r2\n"
	"\tldr r2, [r0]\n"
	"\tadd r0, sp, 0x4\n"
	"\tstr r0, [sp]\n"
	"\tadds r0, r5, 0\n"
	"\tmovs r3, 0x60\n"
	"\tbl sub_800D158\n"
	"\tb _080925CE\n"
	"\t.align 2, 0\n"
"\t_080925B4: .4byte gFriendAreaSettings\n"
"\t_080925B8: .4byte gUnknown_81098AC\n"
"\t_080925BC: .4byte gFriendAreaNames\n"
"\t_080925C0:\n"
	"\tldr r0, _080925D8\n"
	"\tlsls r1, r4, 2\n"
	"\tadds r1, r0\n"
	"\tldr r1, [r1]\n"
	"\tadds r0, r5, 0\n"
	"\tbl strcpy\n"
"\t_080925CE:\n"
	"\tadd sp, 0x18\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"\t_080925D8: .4byte gFriendAreaNames");
}
#endif

u32 GetFriendAreaDescription(u8 index)
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

