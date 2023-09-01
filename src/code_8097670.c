#include "global.h"
#include "code_8097670.h"
#include "pokemon.h"
#include "pokemon_3.h"

static EWRAM_DATA struct unkStruct_203B494 sUnknown_2039778 = {0};

EWRAM_DATA_2 struct unkStruct_203B494 *gUnknown_203B494 = {0};

// data_810AE24.s
extern const u8 *gAdventureLogText[];

void sub_8097670(void)
{
    gUnknown_203B494 = &sUnknown_2039778;
}

struct unkStruct_203B494 *sub_8097680(void)
{
    return &sUnknown_2039778;
}

void SetDungeonLocationInfo(struct DungeonLocation *r0)
{
    gUnknown_203B494->dungeonLocation.id = r0->id;
    gUnknown_203B494->dungeonLocation.floor = r0->floor;
}

struct DungeonLocation *GetDungeonLocationInfo(void)
{
    return &gUnknown_203B494->dungeonLocation;
}

void sub_80976A8(void)
{
    s32 index;

    gUnknown_203B494->unk0 = 0;
    gUnknown_203B494->unk14 = 0;
    gUnknown_203B494->unk16 = 0;
    gUnknown_203B494->unk18 = 0;
    gUnknown_203B494->unkC0 = 0;
    gUnknown_203B494->unk8 = 0;
    gUnknown_203B494->unkC = 0;

    for (index = 0; index < 14; index++)
        gUnknown_203B494->unk1C[index] = 0;

    for (index = 0; index < 13; index++)
        gUnknown_203B494->unk8C[index] = 0;
}

void sub_80976F8(u8 r0)
{
    gUnknown_203B494->unk0 |= (1 << r0);
}

bool8 sub_8097710(u8 r0)
{
    if (gUnknown_203B494->unk0 & (1 << r0))
        return TRUE;
    return FALSE;
}

const u8 *GetAdventureLogLine(u8 index)
{
    return gAdventureLogText[index];
}

void ResetNumAdventures(void)
{
    gUnknown_203B494->numAdventures = 0;
}

void IncrementNumAdventures(void)
{
    gUnknown_203B494->numAdventures++;
    if (gUnknown_203B494->numAdventures > 99999)
        gUnknown_203B494->numAdventures = 99999;
}

s32 GetNumAdventures(void)
{
    return gUnknown_203B494->numAdventures;
}

UNUSED static void SetNumAdventures(s32 numAdventures)
{
    gUnknown_203B494->numAdventures = numAdventures;
}

void sub_8097790(void)
{
    gUnknown_203B494->unk8++;
    if (gUnknown_203B494->unk8 > 99999)
        gUnknown_203B494->unk8 = 99999;

    sub_80976F8(8);
}

s32 sub_80977B8(void)
{
    return gUnknown_203B494->unk8;
}

UNUSED static void sub_80977C4(s32 r0)
{
    gUnknown_203B494->unk8 = r0;
}

void sub_80977D0(void)
{
    gUnknown_203B494->unkC++;
    if (gUnknown_203B494->unkC > 99999)
        gUnknown_203B494->unkC = 99999;

    sub_80976F8(9);
}

s32 sub_80977F8(void)
{
    return gUnknown_203B494->unkC;
}

UNUSED static void sub_8097804(s32 r0)
{
    gUnknown_203B494->unkC = r0;
}

void sub_8097810(void)
{
    if (gUnknown_203B494->unk14 < 9999)
        gUnknown_203B494->unk14++;

    sub_80976F8(11);
}

s16 sub_8097838(void)
{
    return gUnknown_203B494->unk14;
}

void sub_8097848(void)
{
    if (gUnknown_203B494->unk16 < 9999)
        gUnknown_203B494->unk16++;

    sub_80976F8(10);
}

s16 sub_8097870(void)
{
    return gUnknown_203B494->unk16;
}

s16 sub_8097880(void)
{
    return gUnknown_203B494->unk18;
}

void sub_8097890(void)
{
    if (gUnknown_203B494->unkC0 < 99999)
        gUnknown_203B494->unkC0++;

    sub_80976F8(12);
}

s16 sub_80978B8(void)
{
    return gUnknown_203B494->unkC0;
}

void sub_80978C8(s16 pokeIndex)
{
    s32 iVar2;
    struct unkStruct_203B494 *preload;
    s32 baseSpecies;

    baseSpecies = GetBaseSpeciesNoUnown(pokeIndex);
    preload = gUnknown_203B494;
    iVar2 = baseSpecies;
    if (baseSpecies < 0)
        iVar2 = baseSpecies + 0x1F; // 0x1F == MONSTER_NIDOQUEEN

    preload->unk54[iVar2 >> 5] |=  1 << (baseSpecies + (iVar2 >> 5) * -0x20);
}

bool8 sub_8097900(s16 pokeIndex)
{
    s32 iVar2;
    struct unkStruct_203B494 *preload;
    s32 baseSpecies;

    baseSpecies = GetBaseSpeciesNoUnown(pokeIndex);
    preload = gUnknown_203B494;
    iVar2 = baseSpecies;
    if (baseSpecies < 0)
        iVar2 = baseSpecies + 0x1F; // 0x1F == MONSTER_NIDOQUEEN

    if (preload->unk1C[iVar2 >> 5] & (1 << (baseSpecies + (iVar2 >> 5) * -0x20)))
        return TRUE;
    return FALSE;
}