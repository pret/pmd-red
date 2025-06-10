#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_8092334.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "friend_area.h"
#include "items.h"
#include "pokemon.h"
#include "strings.h"
#include "dungeon_data.h"

EWRAM_DATA static bool8 sBoughtFriendAreas[NUM_FRIEND_AREAS] = {0};

EWRAM_INIT bool8 *gFriendAreas = {NULL};

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
        sum += gFriendAreaSettings[i].num_pokemon;
        if (sum > target)
            return i;
    }

    return 0;
}

void sub_8092404(u8 r0, u16 *r1, bool8 allowLeader, bool8 allowPartner)
{
    s32 i;
    s32 count;

    count = 0;
    for (i = 0; i < NUM_MONSTERS; i++) {
        if (PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])
            && (!IsMonTeamLeader(&gRecruitedPokemonRef->pokemon[i]) || allowLeader)
            && (!IsMonPartner(&gRecruitedPokemonRef->pokemon[i]) || allowPartner)
            && sub_80923D4(i) == r0
            && count < 16
            )
        {
            r1[count] = i;
            count++;
        }
    }

    r1[count] = 0xFFFF;
}

void sub_809249C(u8 friendArea, bool8 clear)
{
    s32 i;

    if (!gFriendAreas[friendArea])
        return;

    for (i = 0; i < NUM_MONSTERS; i++) {
        PokemonStruct1 *pokemon = &gRecruitedPokemonRef->pokemon[i];

        if (PokemonFlag1(pokemon) && sub_80923D4(i) == friendArea) {
            if (IsMonPartner(pokemon) || IsMonTeamLeader(pokemon))
                clear = FALSE;
            else
                pokemon->unk0 = 0;
        }
    }

    if (clear)
        gFriendAreas[friendArea] = FALSE;
}

const u8 *GetFriendAreaName(u8 index)
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
    sprintfStatic(buffer, _("{color GREEN_RAW}%s{reset}"), gFriendAreaNames[index]);
}

void WriteFriendAreaName(u8 *buffer, u8 index, bool8 printPrice)
{
    // I think this is when we buy the friend area from wigglytuff
    u8 priceBuffer[20];

    if (printPrice) {
        WriteHighDecimal(gFriendAreaSettings[index].price, priceBuffer, 1);
        sprintfStatic(buffer, _("%s{MOVE_X_POSITION}%c{COLOR GREEN_RAW}%s{RESET}"), gFriendAreaNames[index], 96, priceBuffer);
    }
    else
        strcpy(buffer, gFriendAreaNames[index]);
}

const u8 *GetFriendAreaDescription(u8 index)
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
    s32 i;

    for (i = 1; i < NUM_FRIEND_AREAS; i++) {
        if (!gFriendAreas[i])
            return FALSE;
    }

    return TRUE;
}

void GetFriendAreaCapacity2(u8 friendArea, FriendAreaCapacity *dst, bool8 checkLeader, bool8 checkPartner)
{
    PokemonStruct1 *pokeStruct;
    s32 i;
    s32 iVar4;

    iVar4 = 0;

    for (i = 0; i < friendArea; i++)
        iVar4 += gFriendAreaSettings[i].num_pokemon;

    dst->unk8 = iVar4;
    dst->hasFriendArea = gFriendAreas[i];

    if (dst->hasFriendArea) {
        dst->currNoPokemon = 0;
        dst->maxPokemon = gFriendAreaSettings[i].num_pokemon;

        for (i = 0; i < dst->maxPokemon; i++, iVar4++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[iVar4];

            if (PokemonFlag1(pokeStruct) &&
                (!checkLeader || !IsMonTeamLeader(pokeStruct)) &&
                (!checkPartner || pokeStruct->dungeonLocation.id != DUNGEON_JOIN_LOCATION_PARTNER)) {
                dst->currNoPokemon++;
            }
        }
    }
    else {
        dst->currNoPokemon = 0;
        dst->maxPokemon = 0;
    }
}

void GetFriendAreaCapacity(u8 areaId, FriendAreaCapacity *dst, bool8 checkPartner)
{
    PokemonStruct1 *mon;
    s32 r5;
    s32 i;
    s32 max;

    r5 = 0;

    for (i = 0; i < areaId; i++)
        r5 += gFriendAreaSettings[i].num_pokemon;

    dst->unk8 = r5;
    dst->hasFriendArea = gFriendAreas[i];

    if (dst->hasFriendArea) {
        dst->currNoPokemon = 0;
        dst->maxPokemon = gFriendAreaSettings[i].num_pokemon;
        max = dst->maxPokemon;

        for (i = 0; i < max; i++, r5++) {
            mon = &gRecruitedPokemonRef->pokemon[r5];
            if (PokemonFlag1(mon)) {
                if (mon->isTeamLeader || (!checkPartner && mon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER))
                    dst->maxPokemon--;
                else
                    dst->currNoPokemon++;
            }
        }
    }
    else {
        dst->currNoPokemon = 0;
        dst->maxPokemon = 0;
    }
}

u32 SaveFriendAreas(u8 *r0, u32 size)
{
    DataSerializer unk;
    u32 temp;
    s32 i;

    InitBitWriter(&unk, r0, size);

    for (i = 0; i < NUM_FRIEND_AREAS; i++) {
        if (gFriendAreas[i] != 0)
            temp = -1;
        else
            temp = 0;
        WriteBits(&unk, (u8*)&temp, 1);
    }

    FinishBitSerializer(&unk);
    return unk.count;
}

u32 ReadSavedFriendAreas(u8 *r0, s32 size)
{
    DataSerializer unk;
    u32 temp;
    s32 i;

    InitBitReader(&unk, r0, size);

    for (i = 0; i < NUM_FRIEND_AREAS; i++) {
        ReadBits(&unk, &temp, 1);
        // It's setting whether we have the friend area or not
        if (temp & 1)
            gFriendAreas[i] = TRUE;
        else
            gFriendAreas[i] = FALSE;
    }

    FinishBitSerializer(&unk);
    return unk.count;
}
