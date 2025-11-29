#include "global.h"
#include "globaldata.h"
#include "exclusive_pokemon.h"
#include "dungeon_data.h"

EWRAM_INIT ExclusivePokemonData *gExclusiveMonPtr = { NULL };

EWRAM_DATA ExclusivePokemonData gExclusivePokemonInfo = { 0 };

// This file is more of a pokedex rather than just exclusive mon stuff

void LoadExclusivePokemon(void)
{
    gExclusiveMonPtr = &gExclusivePokemonInfo;
}

ExclusivePokemonData *GetExclusivePokemon(void)
{
    return &gExclusivePokemonInfo;
}

void InitializeExclusivePokemon(void)
{
    s32 i;

    memset(gExclusiveMonPtr, 0, sizeof(ExclusivePokemonData));

    for (i = 0; i < NUM_EXCLUSIVE_POKEMON; i++) {
        gExclusiveMonPtr->exclusives[i] = gExclusivePokemon[i].in_rrt;
    }
}

void SetTempCutsceneFlag(u8 flag)
{
    gExclusiveMonPtr->tempCutsceneFlags[flag / 32] |= 1 << (flag % 32);
}

void SetCutsceneFlag(u8 flag)
{
    gExclusiveMonPtr->cutsceneFlags[flag / 32] |= 1 << (flag % 32);
}

void FlushTempCutsceneFlags(void)
{
    s32 i;

    for (i = 0; i < NUM_CUTSCENE_FLAGS; i++) {
        if ((gExclusiveMonPtr->tempCutsceneFlags[i / 32] & (1 << (i % 32))) != 0) {
            gExclusiveMonPtr->cutsceneFlags[i / 32] |= 1 << (i % 32);
        }
    }

    ClearTempCutsceneFlags();
}

void UnsetCutsceneFlag(u8 flag)
{
    gExclusiveMonPtr->cutsceneFlags[flag / 32] &= ~(1 << (flag % 32));
    gExclusiveMonPtr->tempCutsceneFlags[flag / 32] &= ~(1 << (flag % 32));
}

void ClearTempCutsceneFlags(void)
{
    s32 i;

    for (i = 0; i < CUTSCENE_FLAGS_U32STORAGE; i++)
        gExclusiveMonPtr->tempCutsceneFlags[i] = 0;
}

bool8 sub_80980A4(void)
{
    bool8 temp = gExclusiveMonPtr->unk0;
    gExclusiveMonPtr->unk0 = TRUE;
    return temp;
}

void SetMonSeenFlag(s16 monID)
{
    s32 pokeID_s32 = monID;
    s32 pokeID_s32_1 = pokeID_s32;

    if (pokeID_s32 == MONSTER_DECOY)
        return;
    if (pokeID_s32 == MONSTER_STATUE)
        return;
    if (pokeID_s32 == MONSTER_RAYQUAZA_CUTSCENE)
        return;

    gExclusiveMonPtr->monSeenFlags[pokeID_s32 / 32] |= 1 << (s16)(pokeID_s32_1 % 32);
}

bool8 GetCutsceneFlag(u8 flag)
{
    if (flag >= NUM_CUTSCENE_FLAGS)
        return FALSE;

    return (gExclusiveMonPtr->cutsceneFlags[flag / 32] & (1 << (flag % 32))) != 0;
}

bool8 GetMonSeenFlag(s16 monID)
{
    s32 pokeID_s32;
    s32 pokeID_s32_1;

    pokeID_s32 = monID;
    pokeID_s32_1 = pokeID_s32;
    return (gExclusiveMonPtr->monSeenFlags[pokeID_s32 / 32] & (1 << (s16)(pokeID_s32_1 % 32))) != 0;
}

void SetTutorialFlag(s32 flag)
{
    gExclusiveMonPtr->tutorialFlags[flag / 32] |= (1 << (flag % 32));
}

bool8 GetTutorialFlag(s32 flag)
{
    if (flag >= NUM_TUTORIAL_FLAGS)
        return FALSE;

    return ((gExclusiveMonPtr->tutorialFlags[flag / 32]) & (1 << (flag % 32))) != 0;
}

bool8 IsExclusivePokemonUnlocked(s32 pokeID)
{
    s32 i;
    s32 pokeID_s32 = (s16) pokeID;

    for (i = 0; i < NUM_EXCLUSIVE_POKEMON; i++) {
        if (gExclusivePokemon[i].poke_id == pokeID_s32)
            return gExclusiveMonPtr->exclusives[i];
    }

    return TRUE;
}

void UnlockExclusivePokemon(s16 pokeID)
{
    s32 i;
    s32 pokeID_s32 = pokeID;

    for (i = 0; i < NUM_EXCLUSIVE_POKEMON; i++) {
        if (gExclusivePokemon[i].poke_id == pokeID_s32)
            gExclusiveMonPtr->exclusives[i] = TRUE;
    }
}

void WriteExclusivePokemon(DataSerializer *r0)
{
    s32 i;

    u8 neg_1 = -1;
    u8 zero = 0;

    WriteBits(r0, &gExclusiveMonPtr->unk0, 1);

    for (i = 0; i < MONSTER_MAX; i++) {
        bool8 b = GetMonSeenFlag(i);
        WriteBits(r0, &b, 1);
    }

    for (i = 0; i < NUM_CUTSCENE_FLAGS; i++) {
        bool8 b = GetCutsceneFlag(i);
        WriteBits(r0, &b, 1);
    }

    for (i = 0; i < NUM_TUTORIAL_FLAGS; i++) {
        bool8 b = GetTutorialFlag(i);
        WriteBits(r0, &b, 1);
    }

    for (i = 0; i < NUM_EXCLUSIVE_POKEMON; i++) {
        u8 *p;

        if (gExclusiveMonPtr->exclusives[i])
            p = &neg_1;
        else
            p = &zero;

        WriteBits(r0, p, 1);
    }
}

void ReadExclusivePokemon(DataSerializer *r0)
{
    s32 i;

    memset(gExclusiveMonPtr, 0, sizeof(ExclusivePokemonData));

    ReadBits(r0, &gExclusiveMonPtr->unk0, 1);

    for (i = 0; i < MONSTER_MAX; i++) {
        bool8 b;
        ReadBits(r0, &b, 1);
        if (b)
            SetMonSeenFlag(i);
    }

    for (i = 0; i < NUM_CUTSCENE_FLAGS; i++) {
        bool8 b;
        ReadBits(r0, &b, 1);
        if (b)
            SetTempCutsceneFlag(i);
    }

    for (i = 0; i < NUM_TUTORIAL_FLAGS; i++) {
        bool8 b;
        ReadBits(r0, &b, 1);
        if (b)
            SetTutorialFlag(i);
    }

    for (i = 0; i < NUM_EXCLUSIVE_POKEMON; i++) {
        bool8 b;
        ReadBits(r0, &b, 1);
        do; while(0); // do/while needed for matching - jiang
        gExclusiveMonPtr->exclusives[i] = (b & 1) != 0;
    }

    FlushTempCutsceneFlags();
}
