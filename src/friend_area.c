#include "global.h"
#include "code_800D090.h"
#include "code_8092334.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "friend_area.h"
#include "items.h"
#include "pokemon.h"

EWRAM_DATA static bool8 sBoughtFriendAreas[NUM_FRIEND_AREAS] = {0};

EWRAM_DATA_2 bool8 *gFriendAreas = {0};

// data_8107010.s
extern const u8 sUnknown_81098A4[];
extern const u8 sUnknown_81098AC[];
#include "data/friend_area_settings.h" // 810AA90
// data_810AE24.s
extern const u8 *sFriendAreaNames[]; // 81139D0
extern const u8 *sFriendAreaDescriptions[]; // 8113E30

void LoadFriendAreas(void)
{
    gFriendAreas = sBoughtFriendAreas;
}

bool8 *GetBoughtFriendAreas(void)
{
    return sBoughtFriendAreas;
}

void InitializeFriendAreas(void)
{
    s32 i;

    for (i = 0; i < NUM_FRIEND_AREAS; i++)
        gFriendAreas[i] = FALSE;
}

u8 sub_80923D4(s32 target)
{
    s32 i;
    s32 sum = 0;

    for (i = 0; i < NUM_FRIEND_AREAS; i++) {
        sum += sFriendAreaSettings[i].num_pokemon;
        if (sum > target)
            return i;
    }

    return 0;
}

#ifdef NONMATCHING // 96.99% https://decomp.me/scratch/pj7Q5
void sub_8092404(u8 r0, u16 *r1, bool8 r2, bool8 r3)
{
    s32 i;
    bool32 flag;
    s32 count;
    PokemonStruct1 *pokemon;

    count = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        pokemon = &gRecruitedPokemonRef->pokemon[i];

        if (!((u8)pokemon->unk0 & 1))
            continue;
        if (pokemon->isTeamLeader && !r2)
            continue;

        flag = pokemon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER;
        if (flag && !r3)
            continue;
        if (sub_80923D4(i) != r0)
            continue;
        if (count > 15)
            continue;

        r1[count] = i;
        count++;
    }

    r1[count] = 0xFFFF;
}
#else
NAKED
void sub_8092404(u8 r0, u16 *r1, bool8 r2, bool8 r3)
{
	asm_unified("push {r4-r7,lr}\n"
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
#endif // NONMATCHING

void sub_809249C(u8 friendArea, bool8 clear)
{
    s32 i;
    bool32 dungeonCheck;
    bool32 isTeamLeader;

    if (!gFriendAreas[friendArea])
        return;

    for (i = 0; i < NUM_MONSTERS; i++) {
        PokemonStruct1 *pokemon = &gRecruitedPokemonRef->pokemon[i];

        if (!((u8)pokemon->unk0 & 1))
            continue;
        if (sub_80923D4(i) != friendArea)
            continue;

        dungeonCheck = pokemon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER;
        if (dungeonCheck || (isTeamLeader = pokemon->isTeamLeader != FALSE, isTeamLeader))
            clear = FALSE;
        else
            pokemon->unk0 = 0;
    }

    if (clear)
        gFriendAreas[friendArea] = FALSE;
}

const u8 *GetFriendAreaName(u8 index)
{
    return sFriendAreaNames[index];
}

u8 GetFriendAreaUnlockCondition(u8 index)
{
    return sFriendAreaSettings[index].unlock_condition;
}

s32 GetFriendAreaPrice(u8 index)
{
    return sFriendAreaSettings[index].price;
}

void sub_8092558(u8 *buffer, u8 index)
{
    sprintfStatic(buffer, sUnknown_81098A4, sFriendAreaNames[index]);
}

void sub_8092578(u8 *buffer, u8 index, bool8 printPrice)
{
    // I think this is when we buy the friend area from wigglytuff
    u8 priceBuffer[20];

    if (printPrice) {
        sub_8090FEC(sFriendAreaSettings[index].price, priceBuffer, 1);
        sprintfStatic(buffer, sUnknown_81098AC, sFriendAreaNames[index], 96, priceBuffer);
    }
    else
        strcpy(buffer, sFriendAreaNames[index]);
}

const u8 *GetFriendAreaDescription(u8 index)
{
    return sFriendAreaDescriptions[index];
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
    s32 i;

    for (i = 1; i < NUM_FRIEND_AREAS; i++) {
        if (!gFriendAreas[i])
            return FALSE;
    }

    return TRUE;
}

void sub_8092638(u8 friendArea, unkStruct_8092638 *param_2, bool8 checkLeader, bool8 checkDungeon)
{
    PokemonStruct1 *pokeStruct;
    s32 i;
    s32 iVar4;

    iVar4 = 0;

    for (i = 0; i < friendArea; i++)
        iVar4 += sFriendAreaSettings[i].num_pokemon;

    param_2->unk8 = iVar4;
    param_2->hasFriendArea = gFriendAreas[i];

    if (param_2->hasFriendArea) {
        param_2->unk2 = 0;
        param_2->numPokemon = sFriendAreaSettings[i].num_pokemon;

        for (i = 0; i < param_2->numPokemon; i++, iVar4++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[iVar4];

            if ((((u8)pokeStruct->unk0 & 1) &&
                (!checkLeader || !pokeStruct->isTeamLeader)) &&
                (!checkDungeon || pokeStruct->dungeonLocation.id != DUNGEON_JOIN_LOCATION_PARTNER)) {
                param_2->unk2++;
            }
        }
    }
    else {
        param_2->unk2 = 0;
        param_2->numPokemon = 0;
    }
}

void sub_80926F8(u8 a0, unkStruct_8092638 *a1, u8 a2)
{
    PokemonStruct1 *mon;
    s32 r5;
    s32 i;
    s32 max;

    r5 = 0;

    for (i = 0; i < a0; i++)
        r5 += sFriendAreaSettings[i].num_pokemon;

    a1->unk8 = r5;
    a1->hasFriendArea = gFriendAreas[i];

    if (a1->hasFriendArea) {
        a1->unk2 = 0;
        a1->numPokemon = sFriendAreaSettings[i].num_pokemon;
        max = a1->numPokemon;

        for (i = 0; i < max; i++, r5++) {
            mon = &gRecruitedPokemonRef->pokemon[r5];
            if ((u8)mon->unk0 & 1) {
                if (mon->isTeamLeader || (a2 == 0 && mon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER))
                    a1->numPokemon--;
                else
                    a1->unk2++;
            }
        }
    }
    else {
        a1->unk2 = 0;
        a1->numPokemon = 0;
    }
}

u32 SaveFriendAreas(u8 *r0, u32 size)
{
    struct unkStruct_8094924 unk;
    u32 temp;
    s32 i;

    xxx_init_struct_8094924_save_809486C(&unk, r0, size);

    for (i = 0; i < NUM_FRIEND_AREAS; i++) {
        if (gFriendAreas[i] != 0)
            temp = -1;
        else
            temp = 0;
        SaveIntegerBits(&unk, (u8*)&temp, 1);
    }

    nullsub_102(&unk);
    return unk.unk8;
}

u32 ReadSavedFriendAreas(u8 *r0, s32 size)
{
    struct unkStruct_8094924 unk;
    u32 temp;
    s32 i;

    xxx_init_struct_8094924_restore_809485C(&unk, r0, size);

    for (i = 0; i < NUM_FRIEND_AREAS; i++) {
        RestoreIntegerBits(&unk, &temp, 1);
        // It's setting whether we have the friend area or not
        if (temp & 1)
            gFriendAreas[i] = TRUE;
        else
            gFriendAreas[i] = FALSE;
    }

    nullsub_102(&unk);
    return unk.unk8;
}