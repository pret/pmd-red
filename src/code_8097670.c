#include "global.h"
#include "code_8097670.h"
#include "exclusive_pokemon.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "friend_area.h"

static EWRAM_DATA struct unkStruct_203B494 sUnknown_2039778 = {0};

EWRAM_DATA_2 struct unkStruct_203B494 *gUnknown_203B494 = {0};

// data_810AE24.s
extern const u8 *gAdventureLogText[];

extern void SaveDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
void ReadGameOptions(struct unkStruct_8094924 *param_1);
void ReadPlayTime(struct unkStruct_8094924 *r0);
void WriteGameOptions(struct unkStruct_8094924 *param_1);
void WritePlayTime(struct unkStruct_8094924 *r0);

void sub_8097670(void)
{
    gUnknown_203B494 = &sUnknown_2039778;
}

struct unkStruct_203B494 *sub_8097680(void)
{
    return &sUnknown_2039778;
}

void SetDungeonLocationInfo(DungeonLocation *r0)
{
    gUnknown_203B494->dungeonLocation.id = r0->id;
    gUnknown_203B494->dungeonLocation.floor = r0->floor;
}

DungeonLocation *GetDungeonLocationInfo(void)
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

void sub_8097944(void)
{
    bool8 bVar2;
    bool8 bVar3;
    int index;
    s32 counter;
    Move *move;
    PokemonStruct1 *pokeStruct;
    s32 index1;
    s32 temp;

    bVar2 = 1;
    bVar3 = 1;
    if ((sub_8097710(0xd) == 0) && (HasAllFriendAreas())) {
        sub_80976F8(0xd);
    }

    for(index = 0; index < NUM_MONSTERS; index++)
    {

#ifdef NONMATCHING
        pokeStruct = &index[gRecruitedPokemonRef->pokemon];
#else
        register size_t offset asm("r1") = offsetof(unkStruct_203B45C, pokemon[index]);
        PokemonStruct1* p = gRecruitedPokemonRef->pokemon;
        size_t addr = offset + (size_t)p;
        pokeStruct = (PokemonStruct1*)addr;
#endif


        if (((u8)(pokeStruct->unk0) & 1)) {
            temp = pokeStruct->speciesNum;
            gUnknown_203B494->unk1C[(temp / 32)] |= (1 << (temp + (temp / 32) * -32));

            for(index1 = 0; index1 < MAX_MON_MOVES; index1++)
            {
                move = &gRecruitedPokemonRef->pokemon[index].moves[index1];
                if ((move->moveFlags & 1) != 0) {
                    gUnknown_203B494->unk8C[move->id / 32] |= 1 << (move->id & 0x1f);
                }
            }
        }
  }
    
  for(index = 0; index < MONSTER_MAX; index++)
  {
    if (index != MONSTER_NONE)
        if(index != MONSTER_CASTFORM_SNOWY)
            if(index != MONSTER_CASTFORM_SUNNY)
                if(index != MONSTER_CASTFORM_RAINY)
                    if(index != MONSTER_DEOXYS_ATTACK)
                        if(index != MONSTER_DEOXYS_DEFENSE)
                            if(index != MONSTER_DEOXYS_SPEED)
                                if(index != MONSTER_MUNCHLAX)
                                    if(index != MONSTER_DECOY)
                                        if(index != MONSTER_STATUE)
                                            if(index != MONSTER_RAYQUAZA_CUTSCENE)
                                            {
                                              if ((gUnknown_203B494->unk54[(index / 32)] & (1 << (index + (index / 32) * -32))) == 0) {
                                                bVar3 = 0;
                                              }
                                              if ((gUnknown_203B494->unk1C[(index / 32 )] & (1 << (index + (index / 32) * -32))) != 0)
                                              {
                                                if (index == MONSTER_MOLTRES) {
                                                  sub_80976F8(0x10);
                                                }
                                                if (index == MONSTER_ZAPDOS) {
                                                  sub_80976F8(0x11);
                                                }
                                                if (index == MONSTER_ARTICUNO) {
                                                  sub_80976F8(0x12);
                                                }
                                                if (index == MONSTER_DEOXYS_NORMAL) {
                                                  sub_80976F8(0x13);
                                                }
                                                if (index == MONSTER_ENTEI) {
                                                  sub_80976F8(0x14);
                                                }
                                                if (index == MONSTER_RAIKOU) {
                                                  sub_80976F8(0x15);
                                                }
                                                if (index == MONSTER_SUICUNE) {
                                                  sub_80976F8(0x16);
                                                }
                                                if (index == MONSTER_HO_OH) {
                                                  sub_80976F8(0x17);
                                                }
                                                if (index == MONSTER_KYOGRE) {
                                                  sub_80976F8(0x18);
                                                }
                                                if (index == MONSTER_GROUDON) {
                                                  sub_80976F8(0x19);
                                                }
                                                if (index == MONSTER_RAYQUAZA) {
                                                  sub_80976F8(0x1a);
                                                }
                                                if (index == MONSTER_LUGIA) {
                                                  sub_80976F8(0x1b);
                                                }
                                                if (index == MONSTER_CELEBI) {
                                                  sub_80976F8(0x1c);
                                                }
                                                if (index == MONSTER_MEW) {
                                                  sub_80976F8(0x1d);
                                                }
                                                if (index == MONSTER_MEWTWO) {
                                                  sub_80976F8(0x1e);
                                                }
                                                if (index == MONSTER_JIRACHI) {
                                                  sub_80976F8(0x1f);
                                                }
                                              }
                                              else
                                              {
                                                bVar2 = 0;
                                              }
                                            }
  }
    
  if (bVar2) {
    sub_80976F8(0xf);
  }
  if (bVar3) {
    sub_80976F8(0xe);
  }
  counter = 0;
  for(index = 0; index < NUM_MONSTERS; index++)
  {
    if ((((index != 0) && (index != 0x163)) && (index != 0x164)) && (index != 0x165)) {
      if ((gUnknown_203B494->unk8C[(index / 32 )] & (1 << (index + (index / 32) * -32))) != 0) {
        counter = counter + 1;
      }
    }
  }
  if (counter != 0) {
    gUnknown_203B494->unk18 = counter;
    sub_80976F8(7);
  }
}
