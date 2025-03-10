#include "global.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "random.h"
#include "constants/colors.h"
#include "constants/dungeon.h"
#include "constants/evolve_type.h"
#include "constants/evolution_status.h"
#include "constants/iq_skill.h"
#include "constants/tactic.h"
#include "constants/type.h"
#include "constants/ability.h"
#include "structs/str_pokemon.h"
#include "sprite.h"
#include "text_util.h"
#include "friend_area.h"
#include "luminous_cave.h"
#include "code_8097670.h"
#include "moves.h"
#include "string_format.h"
#include "dungeon.h"
#include "text.h"

extern u8 *gIQSkillNames[];
extern u8 *gIQSkillDescriptions[];
extern u8 *gTacticsDescriptions[];
extern u8 *gTactics[];
extern u32 gIQSkillGroups[];

extern SpriteOAM gShadowSprites[3]; // Shadow sprites of some kind
extern const s16 gUnknown_810AC60; // 0xC
extern const s16 gUnknown_810AC62; // 0xC
extern const s16 gUnknown_810AC68; // 0x8
extern const s16 gUnknown_810AC64; // 0x8
extern const s16 gUnknown_810AC66; // 0x8
extern u8 *gUnknown_810DD58[];
extern u8 *gEvolutionStrings[];
extern u8 *gExpPts810DD9C_Ptr[];
extern u8 *gIQSkill810DD68_Ptr[];
extern u8 *gLevel810DD6C_Ptr[];
extern u8 *gStatusNames[];
extern u8 gUnknown_8107754[];
extern u8 gUnknown_810775C[];
extern u8 gUnknown_8107768[];
extern u8 gUnknown_8107770[];
extern u8 gUnknown_8107784[];
extern u8 gUnknown_8107788[];
extern u8 gUnknown_810778C[];
extern u8 gUnknown_8107790[];
extern u8 gUnknown_8107798[];
extern u8 *gUnknown_810DDB8[];
extern u8 *gUnknown_810DDD0[];
extern u8 *gUnknown_810DDE4[];
extern u8 *gUnknown_810DDFC[];
extern u8 *gUnknown_810DE0C[];
extern u8 *gUnknown_810DE20[];
extern u8 *gUnknown_810DE24[];
extern u8 *gUnknown_810DE28[];
extern u8 *gUnknown_810DE38[];
extern u8 *gUnknown_810DE4C[];
extern u8 *gUnknown_810DE50[];
extern u8 *gUnknown_810DE54[];
extern u8 *gUnknown_810DE58[];
extern u8 *gUnknown_810DE6C[];
extern u8 *gUnknown_810DE80[];
extern u8 *gUnknown_810DE98[];
extern u8 *gUnknown_810DEB4[];
extern u8 *gUnknown_810DEC8[];
extern u8 *gUnknown_810DEDC[];
extern u8 *gUnknown_810DEF4[];
extern u8 *gUnknown_810DF78[];
extern u8 *gUnknown_810DF84[];
extern u8 *gUnknown_810DF98[];
extern u8 *gUnknown_810DFB4[];
extern u8 *gUnknown_810DFC8[];
extern u8 *gUnknown_810E02C[];
extern u8 *gUnknown_8115718[];

// 2, 4, 6, 7, 8, 9, 0xA, 0xD, 0xF, 0x11
extern s32 gUnknown_810AC90[10];

#include "data/pokemon_3.h"

extern void WriteDungeonLocationBits(DataSerializer*, DungeonLocation*);
extern void WritePoke1LevelBits(DataSerializer*, struct unkPokeSubStruct_C*);
void ReadDungeonLocationBits(DataSerializer*, DungeonLocation*);
void ReadPoke1LevelBits(DataSerializer*, struct unkPokeSubStruct_C*);

extern void WriteBellyBits(DataSerializer*, FixedPoint *src);
extern void WriteHiddenPowerBits(DataSerializer*, HiddenPower*);
extern void ReadBellyBits(DataSerializer*, FixedPoint *dst);
extern void ReadHiddenPowerBits(DataSerializer*, HiddenPower*);
s16 GetPokemonEvolveConditions(s16 index, unkEvolve *r1);

void GenerateHiddenPower(HiddenPower* a1)
{
  s32 i;

  a1->hiddenPowerBasePower = gUnknown_810AC90[RandInt(10)];
  for (i = 0; i < 100; i++) {
    a1->hiddenPowerType = RandInt(NUM_TYPES);
    if ( a1->hiddenPowerType )
      break;
  }
  if ( i == 100 )
    a1->hiddenPowerType = TYPE_FIRE;
}

bool8 HasRecruitedMon(s16 species) {
    s32 species_s32 = species;
    s32 i = 0;
    PokemonStruct1 *pokemon = gRecruitedPokemonRef->pokemon;

    for (i = 0; i < NUM_MONSTERS; i++) {
        if (((u8)pokemon->unk0 & 1)) {
            if(pokemon->speciesNum == species_s32)
                return TRUE;
        }
        pokemon++;
    }
    return FALSE;
}

s16 GetBaseSpecies(s16 index) {
    if (index == MONSTER_CASTFORM_SNOWY)
        return MONSTER_CASTFORM;
    if (index == MONSTER_CASTFORM_SUNNY)
        return MONSTER_CASTFORM;
    if (index == MONSTER_CASTFORM_RAINY)
        return MONSTER_CASTFORM;
    if(index == MONSTER_UNOWN_B)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_C)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_D)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_E)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_F)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_G)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_H)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_I)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_J)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_K)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_L)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_M)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_N)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_O)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_P)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_Q)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_R)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_S)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_T)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_U)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_V)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_W)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_X)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_Y)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_Z)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_EMARK)
        return MONSTER_UNOWN;
    if(index == MONSTER_UNOWN_QMARK)
        return MONSTER_UNOWN;
    if (index == MONSTER_DEOXYS_ATTACK)
        return MONSTER_DEOXYS_NORMAL;
    if (index == MONSTER_DEOXYS_DEFENSE)
        return MONSTER_DEOXYS_NORMAL;
    if (index == MONSTER_DEOXYS_SPEED)
        return MONSTER_DEOXYS_NORMAL;
    if (index == MONSTER_RAYQUAZA_CUTSCENE)
        return MONSTER_RAYQUAZA;

    return index;
}

s16 GetBaseSpeciesNoUnown(s16 index) {
    s32 a1_ = SpeciesId(index);
    if (index == MONSTER_CASTFORM_SNOWY) {
        return MONSTER_CASTFORM;
    }
    if (index == MONSTER_CASTFORM_SUNNY) {
        return MONSTER_CASTFORM;
    }
    if (index == MONSTER_CASTFORM_RAINY) {
        return MONSTER_CASTFORM;
    }
    if (index == MONSTER_DEOXYS_ATTACK) {
        return MONSTER_DEOXYS_NORMAL;
    }
    if (index == MONSTER_DEOXYS_DEFENSE) {
        return MONSTER_DEOXYS_NORMAL;
    }
    if (index == MONSTER_DEOXYS_SPEED) {
        return MONSTER_DEOXYS_NORMAL;
    }
    // these last 2 use r2 instead of just r0
    if (a1_ == MONSTER_RAYQUAZA_CUTSCENE) {
        return MONSTER_RAYQUAZA;
    }
    return a1_;
}

s32 GetUnownIndex(s16 index)
{
    if(index == MONSTER_UNOWN_B)
        return 1;
    if(index == MONSTER_UNOWN_C)
        return 2;
    if(index == MONSTER_UNOWN_D)
        return 3;
    if(index == MONSTER_UNOWN_E)
        return 4;
    if(index == MONSTER_UNOWN_F)
        return 5;
    if(index == MONSTER_UNOWN_G)
        return 6;
    if(index == MONSTER_UNOWN_H)
        return 7;
    if(index == MONSTER_UNOWN_I)
        return 8;
    if(index == MONSTER_UNOWN_J)
        return 9;
    if(index == MONSTER_UNOWN_K)
        return 10;
    if(index == MONSTER_UNOWN_L)
        return 11;
    if(index == MONSTER_UNOWN_M)
        return 12;
    if(index == MONSTER_UNOWN_N)
        return 13;
    if(index == MONSTER_UNOWN_O)
        return 14;
    if(index == MONSTER_UNOWN_P)
        return 15;
    if(index == MONSTER_UNOWN_Q)
        return 16;
    if(index == MONSTER_UNOWN_R)
        return 17;
    if(index == MONSTER_UNOWN_S)
        return 18;
    if(index == MONSTER_UNOWN_T)
        return 19;
    if(index == MONSTER_UNOWN_U)
        return 20;
    if(index == MONSTER_UNOWN_V)
        return 21;
    if(index == MONSTER_UNOWN_W)
        return 22;
    if(index == MONSTER_UNOWN_X)
        return 23;
    if(index == MONSTER_UNOWN_Y)
        return 24;
    if(index == MONSTER_UNOWN_Z)
        return 25;
    if(index == MONSTER_UNOWN_EMARK)
        return 26;
    if(index == MONSTER_UNOWN_QMARK)
        return 27;
    return 0;
}

s16 ExtractSpeciesIndex(UnkDungeonGlobal_unk1CD98 *r0)
{
    return r0->unk0 & 0x000001ff;
}

void sub_808E9C4(PokemonStruct1 *r0, s16 r1)
{
    s32 r1_s32 = r1; // cast needed to match
    r0->unk0 =  ((0xFE << 8) & r0->unk0) | r1_s32 ;
}

void SetSpeciesLevelToExtract(UnkDungeonGlobal_unk1CD98 *r0, s32 level, s32 species)
{
    species = SpeciesId(species);
    r0->unk0 = species | (level << 9) ;
}

s32 ExtractLevel(UnkDungeonGlobal_unk1CD98 *r0)
{
    return (r0->unk0 >> 9);
}

struct UnusedOffenseStruct
{
    s32 att[2];
    s32 def[2];
    u8 atkBoost;
    u8 spAtkBoost;
    u8 defBoost;
    u8 spDefBoost;
};

UNUSED static void GetMonOffenseStats(PokemonStruct1 *mon, struct UnusedOffenseStruct *dst)
{
    dst->att[0] = mon->offense.att[0];
    dst->att[1] = mon->offense.att[1];
    dst->def[0] = mon->offense.def[0];
    dst->def[1] = mon->offense.def[1];
    dst->atkBoost = 0;
    dst->spAtkBoost = 0;
    dst->defBoost = 0;
    dst->spDefBoost = 0;
    if (mon->heldItem.id != ITEM_NOTHING) {
        u16 itemId = mon->heldItem.id;
        if (itemId == ITEM_POWER_BAND) {
            dst->atkBoost += gUnknown_810AC60;
            dst->att[0] += gUnknown_810AC60;
        }
        if (itemId == ITEM_SPECIAL_BAND) {
            dst->spAtkBoost += gUnknown_810AC62;
            dst->att[1] += gUnknown_810AC62;
        }
        if (itemId == ITEM_MUNCH_BELT) {
            dst->atkBoost += gUnknown_810AC68;
            dst->spAtkBoost += gUnknown_810AC68;
            dst->att[0] += gUnknown_810AC68;
            dst->att[1] += gUnknown_810AC68;
        }
        if (itemId == ITEM_DEF_SCARF) {
            dst->defBoost += gUnknown_810AC64;
            dst->def[0] += gUnknown_810AC64;
        }
        if (itemId == ITEM_ZINC_BAND) {
            dst->spDefBoost += gUnknown_810AC66;
            dst->def[1] += gUnknown_810AC66;
        }
    }
}

u8 *GetIQSkillName(u8 skill)
{
    return gIQSkillNames[skill];
}

void CopyTacticsNameToBuffer(char *buffer, u8 tactic)
{
    strncpy(buffer, gTactics[tactic], 0x14);
}

u8 *GetIQSkillDescription(u8 skill)
{
    return gIQSkillDescriptions[skill];
}

u8 *GetTacticsDescription(u8 tactic)
{
    return gTacticsDescriptions[tactic];
}

bool8 TacticsTargetLeader(u8 tactic)
{
    return gTacticsTargetLeader[tactic];
}

void GetAvailTacticsforLvl(u8 *tacticsBuffer, s32 pokeLevel)
{
    s32 tactic;
    s32 availTactics;

    availTactics = 0;
    for(tactic = TACTIC_LETS_GO_TOGETHER; tactic < NUM_TACTICS; tactic++)
    {
        if(gReqTacticLvls[tactic] <= pokeLevel)
        {
            tacticsBuffer[availTactics] = tactic;
            availTactics++;
        }
    }
    if(availTactics > TACTIC_UNUSED)
    {
        return;
    }
    while(availTactics < NUM_TACTICS)
    {
        tacticsBuffer[availTactics] = TACTIC_UNUSED;
        availTactics++;
    }
}

// Instead of assigning the Tactic, a bool is assigned showing it is available
void GetAvailTacticsforLvl_Bool(u8 *tacticsBuffer, s32 pokeLevel)
{
    s32 tactic;

    for(tactic = TACTIC_LETS_GO_TOGETHER; tactic < NUM_TACTICS; tactic++)
    {
        if(gReqTacticLvls[tactic] <= pokeLevel)
        {
            tacticsBuffer[tactic] = TRUE;
        }
        else
        {
            tacticsBuffer[tactic] = FALSE;
        }
    }
}

bool8 HasIQForSkill(s32 pokeIQ, u8 IQSkillIndex)
{
    if(IQSkillIndex == IQ_NONE)
    {
        return FALSE;
    }

    return gReqIQSkillPts[IQSkillIndex] <= pokeIQ;
}

// Fills buffer with all avaiable IQ Skills and returns the amount
s32 GetNumAvailableIQSkills(u8 *iqSkillBuffer, s32 pokeIQ)
{
  s32 counter_2;
  s32 counter_1;
  u8 iqSkill_u8;
  s32 availIQSkills;

  availIQSkills = 0;

  for(counter_1 = IQ_TYPE_ADVANTAGE_MASTER; counter_1 < NUM_IQ_SKILLS; counter_1++) {
    iqSkill_u8 = counter_1; // force this cast to be in a reg
    if (HasIQForSkill(pokeIQ, iqSkill_u8)) {
      iqSkillBuffer[availIQSkills] = iqSkill_u8;
      availIQSkills++;
    }
  }

  for (counter_2 = availIQSkills; counter_2 < NUM_IQ_SKILLS; counter_2++) {
    iqSkillBuffer[counter_2] = IQ_NONE;
  }
  return availIQSkills;
}

void ToggleIQSkill(IqSkillFlags *iq, u32 skillIndex)
{
    s32 bit = 1 << (skillIndex);
    if (IsIQSkillSet(iq, bit)) {
        iq->flags[0] &= ~(bit);
        iq->flags[1] &= ~(bit >> 8);
        iq->flags[2] &= ~(bit >> 16);
    }
    else {
        SetIQSkill(iq, skillIndex);
    }
}

void SetIQSkill(IqSkillFlags *iq, u32 skillIndex)
{
    s32 iqSkill;
    s32 iqSkillGroup;
    s32 bit;

    for (iqSkill = 0, iqSkillGroup = gIQSkillGroups[skillIndex]; iqSkill < NUM_IQ_SKILLS; iqSkill++) {
        // Turn off each IQ Skill that's in the same group as the chosen skill
        if (iqSkillGroup == gIQSkillGroups[iqSkill]) {
            s32 bit = 1 << (iqSkill);
            iq->flags[0] &= ~(bit);
            iq->flags[1] &= ~(bit >> 8);
            iq->flags[2] &= ~(bit >> 16);
        }
    }

    bit = 1 << (skillIndex);
    iq->flags[0] |= bit;
    iq->flags[1] |= (bit >> 8);
    iq->flags[2] |= (bit >> 16);
}

void SetDefaultIQSkills(IqSkillFlags *iq, bool8 enableSelfCurer)
{
    iq->flags[0] = 0;
    iq->flags[1] = 0;
    iq->flags[2] = 0;
    SetIQSkill(iq, IQ_ITEM_CATCHER);
    SetIQSkill(iq, IQ_COURSE_CHECKER);
    SetIQSkill(iq, IQ_ITEM_MASTER);

    // Flag is usually enabled for Boss fights.
    if (enableSelfCurer) {
        SetIQSkill(iq, IQ_SELF_CURER);
    }
}

bool8 IsIQSkillSet(IqSkillFlags *iq, u32 IQSkillBit)
{
    if (!(iq->flags[0] & IQSkillBit) &&
        !(iq->flags[1] & IQSkillBit >> 8) &&
        !(iq->flags[2] & IQSkillBit >> 16))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

u32 sub_808ECFC(void)
{
    return 0;
}

void sub_808ED00()
{
    s32 team[4];
    s32 i;
    s32 length = sub_808D580(team);

    for (i = 0; i < length; i++) {
        gRecruitedPokemonRef->team[i] = gRecruitedPokemonRef->pokemon[team[i]];
    }

    for (; i < MAX_TEAM_MEMBERS; i++) {
        gRecruitedPokemonRef->team[i].unk0 = FLAG_NONE;
    }
}

s32 SaveRecruitedPokemon(u8 *a1, s32 a2)
{
    u16 sixMons[6];
    DataSerializer backup;
    u8 data_u8;
    s16 teamLeader;
    s32 count;
    s32 i;
    PokemonStruct1 *pokemon;

    InitBitWriter(&backup, a1, a2);

    for (i = 0; i < 6; i++)
        sixMons[i] = -1;

    teamLeader = 1; // Maybe fakematch, should be -1
    teamLeader = -teamLeader;
    count = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        // Fakematch, probably need the PokemonFlag2 inline
        if (i) {
            u8 unk = -unk;
        }

        pokemon = &gRecruitedPokemonRef->pokemon[i];

        if (PokemonFlag1(pokemon)) {
            if (pokemon->unk0 & FLAG_ON_TEAM)
                sixMons[count++] = i;

            if (IsMonTeamLeader(pokemon))
                teamLeader = i;
        }
        else
            pokemon->level = 0;

        WritePoke1Bits(&backup, pokemon);
    }

    // Team members
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if (PokemonFlag1(&gRecruitedPokemonRef->team[i]))
            data_u8 = 0xFF;
        else
            data_u8 = 0;

        WriteBits(&backup, &data_u8, 1);
        WritePoke1Bits(&backup, &gRecruitedPokemonRef->team[i]);
    }

    // ???
    for (i = 0; i < 6; i++)
        WriteBits(&backup, &sixMons[i], 16);

    // Team leader
    WriteBits(&backup, &teamLeader, 16);

    FinishBitSerializer(&backup);
    return backup.count;
}

s32 RestoreRecruitedPokemon(u8 *a1, s32 a2)
{
    DataSerializer backup;
    u8 data_u8;
    s16 data_s16;
    s32 i;

    InitBitReader(&backup, a1, a2);

    for (i = 0; i < NUM_MONSTERS; i++) {
        ReadPoke1Bits(&backup, &gRecruitedPokemonRef->pokemon[i]);
    }

    // Team members
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        ReadBits(&backup, &data_u8, 1);
        ReadPoke1Bits(&backup, &gRecruitedPokemonRef->team[i]);
        if (data_u8 & 1)
            gRecruitedPokemonRef->team[i].unk0 = FLAG_ON_TEAM | FLAG_UNK_1;
        else
            gRecruitedPokemonRef->team[i].unk0 = FLAG_NONE;
    }

    // ???
    for (i = 0; i < 6; i++) {
        ReadBits(&backup, &data_s16, 16);
        if ((u16)data_s16 < NUM_MONSTERS)
            gRecruitedPokemonRef->pokemon[data_s16].unk0 |= FLAG_ON_TEAM;
    }

    // Team leader
    ReadBits(&backup, &data_s16, 16);
    if ((u16)data_s16 < NUM_MONSTERS)
        gRecruitedPokemonRef->pokemon[data_s16].isTeamLeader = TRUE;

    FinishBitSerializer(&backup);
    return backup.count;
}

void WritePoke1Bits(DataSerializer* a1, PokemonStruct1* pokemon)
{
    WriteBits(a1, &pokemon->level, 7);
    WriteBits(a1, &pokemon->speciesNum, 9);
    WriteDungeonLocationBits(a1, &pokemon->dungeonLocation);
    WritePoke1LevelBits(a1, &pokemon->unkC[0]);
    WritePoke1LevelBits(a1, &pokemon->unkC[1]);
    WriteBits(a1, &pokemon->IQ, 10);
    WriteBits(a1, &pokemon->pokeHP, 10);
    WriteBits(a1, &pokemon->offense.att[0], 8);
    WriteBits(a1, &pokemon->offense.att[1], 8);
    WriteBits(a1, &pokemon->offense.def[0], 8);
    WriteBits(a1, &pokemon->offense.def[1], 8);
    WriteBits(a1, &pokemon->currExp, 24);
    WriteBits(a1, &pokemon->IQSkills, 24);
    WriteBits(a1, &pokemon->tacticIndex, 4);
    WriteHeldItemBits(a1, &pokemon->heldItem);
    WritePoke1MovesBits(a1, pokemon->moves);
    WriteBits(a1, pokemon->name, 10 * 8);
}

void ReadPoke1Bits(DataSerializer* a1, PokemonStruct1* pokemon)
{
    memset(pokemon, 0, sizeof(PokemonStruct1));

    pokemon->unk0 = FLAG_NONE;
    pokemon->isTeamLeader = FALSE;

    ReadBits(a1, &pokemon->level, 7);
    if (pokemon->level)
        pokemon->unk0 |= FLAG_UNK_1;

    ReadBits(a1, &pokemon->speciesNum, 9);
    ReadDungeonLocationBits(a1, &pokemon->dungeonLocation);
    ReadPoke1LevelBits(a1, &pokemon->unkC[0]);
    ReadPoke1LevelBits(a1, &pokemon->unkC[1]);
    ReadBits(a1, &pokemon->IQ, 10);
    ReadBits(a1, &pokemon->pokeHP, 10);
    ReadBits(a1, &pokemon->offense.att[0], 8);
    ReadBits(a1, &pokemon->offense.att[1], 8);
    ReadBits(a1, &pokemon->offense.def[0], 8);
    ReadBits(a1, &pokemon->offense.def[1], 8);
    ReadBits(a1, &pokemon->currExp, 24);
    ReadBits(a1, &pokemon->IQSkills, 24);
    ReadBits(a1, &pokemon->tacticIndex, 4);
    ReadHeldItemBits(a1, &pokemon->heldItem);
    ReadPoke1MovesBits(a1, pokemon->moves);
    ReadBits(a1, pokemon->name, 10 * 8);
}

s32 SavePoke2s(u8* buffer, s32 size)
{
  DataSerializer backup;
  s32 i;
  u8 data_u8_neg1;
  u8 data_u8_zero;

  InitBitWriter(&backup, buffer, size);
  data_u8_neg1 = -1;
  data_u8_zero = 0;

  for (i = 0; i < 4; i++) {
    PokemonStruct2* pokemon2 = &gRecruitedPokemonRef->pokemon2[i];
    WriteBits(&backup, &pokemon2->unk0, 2);

    WriteBits(&backup, pokemon2->isTeamLeader ? &data_u8_neg1 : &data_u8_zero, 1);
    WriteBits(&backup, &pokemon2->level, 7);

    WriteDungeonLocationBits(&backup, &pokemon2->dungeonLocation);
    WriteBits(&backup, &pokemon2->IQ, 10);
    WriteBits(&backup, &pokemon2->unkA, 16);
    WriteBits(&backup, &pokemon2->unkC, 16);
    WriteBits(&backup, &pokemon2->speciesNum, 9);
    WriteBits(&backup, &pokemon2->unk10, 10);
    WriteBits(&backup, &pokemon2->unk12, 10);
    WriteBits(&backup, &pokemon2->offense.att[0], 8);
    WriteBits(&backup, &pokemon2->offense.att[1], 8);
    WriteBits(&backup, &pokemon2->offense.def[0], 8);
    WriteBits(&backup, &pokemon2->offense.def[1], 8);
    WriteBits(&backup, &pokemon2->currExp, 24);
    WritePoke2MovesBits(&backup, &pokemon2->moves);
    WriteItemSlotBits(&backup, &pokemon2->itemSlot);
    WriteBellyBits(&backup, &pokemon2->belly);
    WriteBellyBits(&backup, &pokemon2->maxBelly);
    WriteBits(&backup, &pokemon2->IQSkills, 24);
    WriteBits(&backup, &pokemon2->tacticIndex, 4);
    WriteHiddenPowerBits(&backup, &pokemon2->hiddenPower);
    WriteBits(&backup, &pokemon2->name, 10 * 8);
  }

  FinishBitSerializer(&backup);
  return backup.count;
}

s32 RestorePoke2s(u8* a1, s32 size)
{
  DataSerializer backup;
  s32 i;

  InitBitReader(&backup, a1, size);
  for (i = 0; i < 4; i++) {
    PokemonStruct2* pokemon2 = &gRecruitedPokemonRef->pokemon2[i];
    u8 unk2;

    memset(pokemon2, 0, sizeof(PokemonStruct2));

    ReadBits(&backup, &pokemon2->unk0, 2);

    ReadBits(&backup, &unk2, 1);
    if (unk2 & 1) {
        pokemon2->isTeamLeader = TRUE;
    }
    else {
        pokemon2->isTeamLeader = FALSE;
    }
    ReadBits(&backup, &pokemon2->level, 7);

    ReadDungeonLocationBits(&backup, &pokemon2->dungeonLocation);
    ReadBits(&backup, &pokemon2->IQ, 10);
    ReadBits(&backup, &pokemon2->unkA, 16);
    ReadBits(&backup, &pokemon2->unkC, 16);
    ReadBits(&backup, &pokemon2->speciesNum, 9);
    ReadBits(&backup, &pokemon2->unk10, 10);
    ReadBits(&backup, &pokemon2->unk12, 10);
    ReadBits(&backup, &pokemon2->offense.att[0], 8);
    ReadBits(&backup, &pokemon2->offense.att[1], 8);
    ReadBits(&backup, &pokemon2->offense.def[0], 8);
    ReadBits(&backup, &pokemon2->offense.def[1], 8);
    ReadBits(&backup, &pokemon2->currExp, 24);
    ReadPoke2MovesBits(&backup, &pokemon2->moves);
    ReadItemSlotBits(&backup, &pokemon2->itemSlot);
    ReadBellyBits(&backup, &pokemon2->belly);
    ReadBellyBits(&backup, &pokemon2->maxBelly);
    ReadBits(&backup, &pokemon2->IQSkills, 24);
    ReadBits(&backup, &pokemon2->tacticIndex, 4);
    ReadHiddenPowerBits(&backup, &pokemon2->hiddenPower);
    ReadBits(&backup, &pokemon2->name, 80);
  }

  FinishBitSerializer(&backup);
  return backup.count;
}

void ReadPoke1LevelBits(DataSerializer* a1, struct unkPokeSubStruct_C* unkC)
{
  ReadBits(a1, &unkC->level, 7);
}

void WritePoke1LevelBits(DataSerializer* a1, struct unkPokeSubStruct_C* unkC)
{
  WriteBits(a1, &unkC->level, 7);
}

void ReadHiddenPowerBits(DataSerializer* a1, HiddenPower* a2)
{
  ReadBits(a1, &a2->hiddenPowerBasePower, 10);
  ReadBits(a1, &a2->hiddenPowerType, 5);
}

void WriteHiddenPowerBits(DataSerializer* a1, HiddenPower* a2)
{
  WriteBits(a1, &a2->hiddenPowerBasePower, 10);
  WriteBits(a1, &a2->hiddenPowerType, 5);
}

void sub_808F468(struct PokemonStruct1 *pokemon,struct EvolveStatus *evolveStatus,bool8 param_3)
{
    struct FriendAreaCapacity friendAreaCapacity;
    struct unkEvolve evolveConditions;
    s32 index;

    evolveStatus->evolutionConditionStatus = 0;
    for (index = MONSTER_BULBASAUR; index < MONSTER_MAX; index++) {
        s32 speciesId = (s16) index;
        if (speciesId == MONSTER_ALAKAZAM) {
            GetPokemonEvolveConditions(MONSTER_ALAKAZAM,&evolveConditions);
        }
        else {
            GetPokemonEvolveConditions(speciesId,&evolveConditions);
        }
        if (evolveConditions.preEvolution.evolveType != 0 && pokemon->speciesNum == evolveConditions.preEvolution.evolveFrom)
            break;
    };

    if (index == MONSTER_MAX) {
        evolveStatus->evolutionConditionStatus = EVOLUTION_NO_MORE;
        return;
    }

    for (index = MONSTER_BULBASAUR; index < MONSTER_MAX; index++) {
        u8 evolvedMonFriendArea, monFriendArea;
        bool8 cannotEvolve = FALSE;
        s32 speciesId = (s16) (index);

        GetPokemonEvolveConditions(speciesId, &evolveConditions);
        if (evolveConditions.preEvolution.evolveType == 0 || pokemon->speciesNum != evolveConditions.preEvolution.evolveFrom)
            continue;

        evolvedMonFriendArea = GetFriendArea(speciesId);
        monFriendArea = GetFriendArea(pokemon->speciesNum);
        GetFriendAreaCapacity2(evolvedMonFriendArea,&friendAreaCapacity,0,0);
        if (!friendAreaCapacity.hasFriendArea) {
            evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_FRIEND_AREA;
            cannotEvolve = TRUE;
        }
        else {
            s32 currMonsNo = friendAreaCapacity.currNoPokemon;
            if (evolvedMonFriendArea == monFriendArea) {
                currMonsNo--;
            }
            if (friendAreaCapacity.maxPokemon <= currMonsNo) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ROOM;
                cannotEvolve = TRUE;
            }
         }

        if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_LEVEL) {
            if (evolveStatus->evolutionConditionStatus & 1)
                continue;
            if (pokemon->level < evolveConditions.evolutionRequirements.mainRequirement) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_LEVEL;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_IQ) {
            if (pokemon->IQ < evolveConditions.evolutionRequirements.mainRequirement) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_IQ;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_ITEM) {
            if (param_3) {
                if ((evolveStatus->evoItem1 != evolveConditions.evolutionRequirements.mainRequirement) &&
                        (evolveStatus->evoItem2 != evolveConditions.evolutionRequirements.mainRequirement))
                {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
            }
            else if (FindItemInInventory(evolveConditions.evolutionRequirements.mainRequirement) < 0) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                cannotEvolve = TRUE;
            }
        }

        if (evolveConditions.evolutionRequirements.additionalRequirement == 4) {
            if (param_3) {
                if ((evolveStatus->evoItem1 != ITEM_LINK_CABLE) && (evolveStatus->evoItem2 != ITEM_LINK_CABLE)) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
            }
            else if (FindItemInInventory(ITEM_LINK_CABLE) < 0) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 5) {
            if (pokemon->offense.att[0] <= pokemon->offense.def[0]) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 6) {
            if (pokemon->offense.att[0] >= pokemon->offense.def[0]) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 7) {
            if (pokemon->offense.att[0] != pokemon->offense.def[0]) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 8) {
            if (param_3) {
                if ((evolveStatus->evoItem1 != ITEM_SUN_RIBBON) && (evolveStatus->evoItem2 != ITEM_SUN_RIBBON)) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
            }
            else if (FindItemInInventory(ITEM_SUN_RIBBON) < 0) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 9) {
                if (param_3) {
                    if ((evolveStatus->evoItem1 != ITEM_LUNAR_RIBBON) && (evolveStatus->evoItem2 != ITEM_LUNAR_RIBBON)) {
                        evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                        cannotEvolve = TRUE;
                    }
                }
                else if (FindItemInInventory(ITEM_LUNAR_RIBBON) < 0) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 0xb) {
            if ((evolveStatus->wurmpleVal & 1)) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 0xc) {
            if (!(evolveStatus->wurmpleVal & 1)) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 10) {
            if (param_3 != 0) {
                if ((evolveStatus->evoItem1 != ITEM_BEAUTY_SCARF) && (evolveStatus->evoItem2 != ITEM_BEAUTY_SCARF)) {
                    cannotEvolve = TRUE;
                }
            }
            else {
                if (FindItemInInventory(ITEM_BEAUTY_SCARF) < 0) {
                    cannotEvolve = TRUE;
                }
            }
        }

        if (!cannotEvolve) {
            evolveStatus->evolutionConditionStatus |= EVOLUTION_GOOD;
            evolveStatus->targetEvolveSpecies = speciesId;
        }
    }
}

s32 sub_808F700(PokemonStruct1 *pokemon)
{
    EvolveStatus evolveStatus;

    sub_808F468(pokemon, &evolveStatus, 0);
    if ((evolveStatus.evolutionConditionStatus & EVOLUTION_GOOD)) {
        return 1;
    }
    else if ((evolveStatus.evolutionConditionStatus & EVOLUTION_NO_MORE)) {
        return 2;
    }
    else {
        return 0;
    }
}

PokemonStruct1 *sub_808F734(PokemonStruct1 *pokemon, s16 _species)
{
    PokemonStruct1 *uVar1;
    PokemonStruct1 *iVar3;
    PokemonStruct1 pokeStruct;
    s32 species = _species;

    iVar3 = NULL;
    pokeStruct = *pokemon;
    uVar1 = sub_808F798(pokemon, species);
    if (species == MONSTER_NINJASK) {
        pokeStruct.isTeamLeader = FALSE;
        pokeStruct.heldItem.id = ITEM_NOTHING;
        BoundedCopyStringtoBuffer(pokeStruct.name, GetMonSpecies(MONSTER_SHEDINJA),POKEMON_NAME_LENGTH);
        iVar3 = sub_808F798(&pokeStruct,MONSTER_SHEDINJA);
    }
    if (iVar3 != NULL) {
        IncrementAdventureNumJoined();
    }
    return uVar1;
}

PokemonStruct1 *sub_808F798(PokemonStruct1 *pokemon, short _species)
{
      s32 r6;
      s32 index;
      PokemonStruct1 pokeStruct;
      LevelData levelData;
      u8 buffer [64];
      s32 species = _species;
      bool32 flag = TRUE;

      pokeStruct = *pokemon;
      r6 = pokeStruct.speciesNum;
      GetPokemonLevelData(&levelData,species,pokeStruct.level);
      pokeStruct.currExp = levelData.expRequired;
      pokemon->unk0 = 0;
      pokeStruct.speciesNum = species;
      if (pokeStruct.unkC[0].level == 0) {
        pokeStruct.unkC[0].level = pokeStruct.level;
      }
      else if (pokeStruct.unkC[1].level == 0) {
        pokeStruct.unkC[1].level = pokeStruct.level;
      }

      CopyStringtoBuffer(buffer, GetMonSpecies(r6));

      index = 0;
      goto _start;
      do
      {
          index++;
_start:
          if(index >= POKEMON_NAME_LENGTH) break;
          if(buffer[index] != pokeStruct.name[index]) goto _end;
          if(buffer[index] == 0) break;

      } while(TRUE);
      if(flag)
          BoundedCopyStringtoBuffer(pokeStruct.name, GetMonSpecies(species), POKEMON_NAME_LENGTH);
_end:
      return sub_808D1DC(&pokeStruct);
}

UNUSED void sub_808F83C(PokemonStruct1 *pokemon, s16 species, u8 *r2)
{
    *r2 = 0;
}

void CreatePokemonInfoTabScreen(s32 param_1, s32 param_2, struct unkStruct_808FF20 *mon, struct UnkInfoTabStruct *param_4, u32 windowId)
{
    s32 i, y;
    s32 j;

    sub_80073B8(windowId);
    strncpy(gFormatBuffer_Monsters[0],mon->nameBuffer,0x14);
    y = 0x20;
    switch (param_1) {
        case 0:
            break;
        case 2: {
            const u8 *str;
            s32 iVar8;
            LevelData levelData;

            PrintFormattedStringOnWindow(param_2 * 8 + 0x10,0,gUnknown_8107754,windowId,'\0');
            gFormatArgs[0] = mon->level;
            gFormatArgs[1] = mon->exp;
            PrintFormattedStringOnWindow(4,y,*gLevel810DD6C_Ptr,windowId,'\0');
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,*gExpPts810DD9C_Ptr,windowId,'\0');
            y += 0xA;
            if (mon->level < 100) {
                GetPokemonLevelData(&levelData,mon->species,mon->level + 1);
                gFormatArgs[0] = levelData.expRequired - mon->exp;
                PrintFormattedStringOnWindow(4,y,*gUnknown_810DDB8,windowId,'\0');
            }
            y += 0xC;
            gFormatArgs[0] = mon->HP1;
            gFormatArgs[1] = mon->HP2;
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DDD0,windowId,'\0');
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DDE4,windowId,'\0');
            str = *gUnknown_810DE0C;
            gFormatArgs[0] = mon->offense.att[0];
            if (mon->atkBoost != 0) {
                gFormatArgs[0] = gFormatArgs[0] + mon->atkBoost;
                str = *gUnknown_810DE20;
            }
            PrintFormattedStringOnWindow(4,y,str,windowId,'\0');
            if (mon->defBoost != 0) {
                gFormatArgs[0] = mon->offense.def[0] + mon->defBoost;
                PrintFormattedStringOnWindow(4,y,*gUnknown_810DE4C,windowId,'\0');
            }
            else {
                gFormatArgs[0] = mon->offense.def[0];
                PrintFormattedStringOnWindow(4,y,*gUnknown_810DE38,windowId,'\0');
            }
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DDFC,windowId,'\0');
            str = *gUnknown_810DE24;
            gFormatArgs[0] = mon->offense.att[1];
            if (mon->spAtkBoost != 0) {
                gFormatArgs[0] = gFormatArgs[0] + mon->spAtkBoost;
                str = *gUnknown_810DE28;
            }
            PrintFormattedStringOnWindow(4,y,str,windowId,'\0');
            if (mon->spDefBoost != 0) {
                gFormatArgs[0] = mon->offense.def[1] + mon->spDefBoost;
                PrintFormattedStringOnWindow(4,y,*gUnknown_810DE54,windowId,'\0');
            }
            else {
                gFormatArgs[0] = mon->offense.def[1];
                PrintFormattedStringOnWindow(4,y,*gUnknown_810DE50,windowId,'\0');
            }
            y += 0xA;
            if (ItemExists(&mon->item)) {
                 sub_8090E14(gFormatBuffer_Items[0],&mon->item,0);
            }
            else {
                strcpy(gFormatBuffer_Items[0],*gUnknown_810DE58);
            }
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DE6C,windowId,'\0');
            y += 0xC;
            gFormatArgs[0] = mon->IQ;
            iVar8 = mon->IQ / 10;
            if (iVar8 < 0) {
                iVar8 = 0;
            }
            if (0x62 < iVar8) {
                iVar8 = 99;
            }

            InlineStrcpy(gFormatBuffer_Monsters[0],gUnknown_8115718[iVar8]);
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DE80,windowId,'\0');
            y += 0xA;
            if (!mon->isTeamLeader)
            {
                CopyTacticsNameToBuffer(gFormatBuffer_Monsters[0],mon->tactic);
                PrintFormattedStringOnWindow(4,y,*gUnknown_810DE98,windowId,'\0');
            }
            y += 0xA;
            break;
        }
     case 3: {
            PrintFormattedStringOnWindow(param_2 * 8 + 0x10,0,gUnknown_810775C,windowId,'\0');
            PrintFormattedStringOnWindow(4,y,gUnknown_8107768,windowId,'\0');
            PrintFormattedStringOnWindow(0x38,y,GetFormattedTypeString(mon->types[0]),windowId,'\0');
            if (mon->types[1] != TYPE_NONE) {
                PrintFormattedStringOnWindow(0x60,y,GetFormattedTypeString(mon->types[1]),windowId,'\0');
            }
            y += 0xC;
            PrintFormattedStringOnWindow(4,y,gUnknown_8107770,windowId,'\0');
            y += 0xC;
            PrintFormattedStringOnWindow2(4,y,GetAbilityDescription(mon->abilities[0]),windowId,'\0',0xb);
            y += 0x21;
            if (mon->abilities[1] != ABILITY_UNKNOWN) {
                PrintFormattedStringOnWindow2(4,y,GetAbilityDescription(mon->abilities[1]),windowId,'\0',0xb);
            }
            break;
        }
        case 1: {
            s32 iVar11;
            bool8 bVar10;

            PrintFormattedStringOnWindow(param_2 * 8 + 0x10,0,*gUnknown_810DD58,windowId,'\0');
            iVar11 = mon->unk56 - 1;
            y -= 0xC;
            bVar10 = FALSE;

            for (i = 0; i < 9; i++) {
                param_4->unkC[i] = 0;
            }

            for (j = 0; j < 10; j++, iVar11++, y += 0xC) {
                if (-1 < iVar11) {
                    if (0xb < iVar11)
                        break;
                    if (mon->unk58[iVar11] != 0) {
                        bVar10 = TRUE;
                        InlineStrncpy(gFormatBuffer_Items[1],gStatusNames[mon->unk58[iVar11]],0x50);
                        PrintFormattedStringOnWindow(0xc,y,gUnknown_8107784,windowId,'\0');
                        if (0 < j) {
                            param_4->unkC[j - 1] = mon->unk58[iVar11];
                        }
                    }
                }
            }

            if (!bVar10) {
                PrintFormattedStringOnWindow(0xc,0x20,*gUnknown_810DF78,windowId,'\0');
            }
            break;
        }
        case 4: {
            s32 iVar13;
            bool8 bVar11;
            u8 iqSkillBuffer[24];

            PrintFormattedStringOnWindow(param_2 * 8 + 0x10,0,*gIQSkill810DD68_Ptr,windowId,'\0');
            GetNumAvailableIQSkills(iqSkillBuffer,mon->IQ);
            iVar13 = mon->unk40 - 1;

            for (i = 0; i < 9; i++) {
                param_4->unk0[i] = 0;
            }
            y -= 0xC;
            bVar11 = FALSE;

            for(j = 0; j < 10; j++, iVar13++, y += 0xC) {
                if (-1 < iVar13) {
                    if (0x17 < iVar13)
                        break;
                    if (iqSkillBuffer[iVar13] != 0) {
                        u8 *iqSkillName;

                        bVar11 = TRUE;
                        iqSkillName = GetIQSkillName(iqSkillBuffer[iVar13]);
                        strncpy(gFormatBuffer_Items[1],iqSkillName,0x50);
                        if (IsIQSkillSet(&mon->IQSkills,1 << iqSkillBuffer[iVar13])) {
                            strcpy(gFormatBuffer_Items[0],gUnknown_8107788);
                        }
                        else {
                            strcpy(gFormatBuffer_Items[0],gUnknown_810778C);
                        }
                        if (j >= 1) {
                            param_4->unk0[j - 1] = iqSkillBuffer[iVar13];
                        }
                        PrintFormattedStringOnWindow(0xc,y,gUnknown_8107790,windowId,'\0');
                    }
                }
            }

            if (!bVar11) {
                PrintFormattedStringOnWindow(0xc,0x20,*gUnknown_810DF84,windowId,'\0');
            }
            break;
        }
        case 5: {
            PrintFormattedStringOnWindow(param_2 * 8 + 0x10,0,gUnknown_8107798,windowId,'\0');
            CopyMonsterNameToBuffer(gFormatBuffer_Monsters[0],mon->species);
            gFormatArgs[0] = mon->species;
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DEB4,windowId,'\0');
            y += 0xA;
            InlineStrncpy(gFormatBuffer_Items[0],GetFriendAreaName(GetFriendArea(mon->species)),0x50);
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DEC8,windowId,'\0');
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DEDC,windowId,'\0');
            y += 0xD;
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DFB4,windowId,'\0');
            y += 0xA;
            PrintYellowDungeonNametoBuffer(gFormatBuffer_Items[0],&mon->dungeonLocation);
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DFC8,windowId,'\0');
            y += 0xD;
            strncpy(gFormatBuffer_Monsters[0],GetCategoryString(mon->species),0x14);
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DEF4,windowId,'\0');
            y += 0xD;
            strcpy(gFormatBuffer_Monsters[0],gUnknown_810E02C[GetBodySize(mon->species)]);
            PrintFormattedStringOnWindow(4,y,*gUnknown_810DF98,windowId,'\0');
            y += 0xD;
            PrintFormattedStringOnWindow(4,y,gEvolutionStrings[mon->unk4C],windowId,'\0');
            break;
        }
    }
    sub_80073E0(windowId);
}


void sub_808FF20(struct unkStruct_808FF20 *param_1, struct PokemonStruct1 *pokemon, bool8 param_3)
{
    s32 index;

    PrintColoredPokeNameToBuffer(param_1->nameBuffer, pokemon, COLOR_WHITE);
    param_1->species = pokemon->speciesNum;
    param_1->HP1 = pokemon->pokeHP;
    param_1->HP2 = pokemon->pokeHP;
    param_1->level = pokemon->level;
    param_1->exp = pokemon->currExp;
    for(index = 0; index < 2; index++)
    {
        param_1->offense.att[index] = pokemon->offense.att[index];
        param_1->offense.def[index] = pokemon->offense.def[index];
        param_1->types[index] = GetPokemonType(pokemon->speciesNum,index);
        param_1->abilities[index] = GetPokemonAbility(pokemon->speciesNum,index);
    }
    param_1->isTeamLeader = pokemon->isTeamLeader;
    param_1->atkBoost = 0;
    param_1->spAtkBoost = 0;
    param_1->defBoost = 0;
    param_1->spDefBoost = 0;

    if (pokemon->heldItem.id != 0) {
        if (pokemon->heldItem.id == ITEM_POWER_BAND) {
            param_1->atkBoost += gUnknown_810AC60;
        }
        if (pokemon->heldItem.id == ITEM_SPECIAL_BAND) {
            param_1->spAtkBoost+= gUnknown_810AC62;
        }
        if (pokemon->heldItem.id == ITEM_MUNCH_BELT) {
            param_1->atkBoost += gUnknown_810AC68;
        }
        if (pokemon->heldItem.id == ITEM_MUNCH_BELT) {
            param_1->spAtkBoost+= gUnknown_810AC68;
        }
        if (pokemon->heldItem.id == ITEM_DEF_SCARF) {
            param_1->defBoost += gUnknown_810AC64;
        }
        if (pokemon->heldItem.id == ITEM_ZINC_BAND) {
            param_1->spDefBoost += gUnknown_810AC66;
        }
    }
    param_1->tactic = pokemon->tacticIndex;
    HeldItemToSlot(&param_1->item,&pokemon->heldItem);
    param_1->IQ = pokemon->IQ;
    param_1->dungeonLocation = pokemon->dungeonLocation;
    param_1->unk44[0] = pokemon->unkC[0];
    param_1->unk44[1] = pokemon->unkC[1];
    param_1->IQSkills = pokemon->IQSkills;
    if (param_3) {
        param_1->unk4C = sub_808F700(pokemon);
    }
    else {
        param_1->unk4C = 3;
    }

    for(index = 0; index < 0xC; index++)
    {
        param_1->unk58[index] = 0;
    }
}
