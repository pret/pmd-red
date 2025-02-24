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
#include "structs/str_pokemon.h"
#include "sprite.h"
#include "text_util.h"
#include "friend_area.h"
#include "luminous_cave.h"
#include "code_8097670.h"
#include "moves.h"

extern u8 *gIQSkillNames[];
extern u8 *gIQSkillDescriptions[];
extern u8 *gTacticsDescriptions[];
extern u8 *gTactics[];
extern u32 gIQSkillGroups[];

struct unkStruct_808E9EC
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
};

extern SpriteOAM gShadowSprites[3]; // Shadow sprites of some kind
extern s16 gUnknown_810AC60; // 0xC
extern s16 gUnknown_810AC62; // 0xC
extern s16 gUnknown_810AC68; // 0x8
extern s16 gUnknown_810AC64; // 0x8
extern s16 gUnknown_810AC66; // 0x8
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

// Unused
#ifdef NONMATCHING
void sub_808E9EC(PokemonStruct1 *r0, struct unkStruct_808E9EC *r1)
{
    u8 pokeAtt;
    u8 r4;
    u32 reg1_8;
    s16 reg1;

    pokeAtt = r0->offense.att[0];

    r1->unk0 = pokeAtt;
    r1->unk4 = r0->offense.att[1];
    r1->unk8 = r0->offense.def[0];
    r1->unkC = r0->offense.def[1];
    r1->unk10 = 0;
    r1->unk11 = 0;
    r1->unk12 = 0;
    r1->unk13 = 0;
    if(r0->heldItem.id != 0)
    {
        r4 = r0->heldItem.id;
        if(r4 == 0x13)
        {
            r1->unk10 = gUnknown_810AC60;
            r1->unk0 = pokeAtt + gUnknown_810AC60;
        }
        if(r4 == 0x21)
        {
            r1->unk11 += gUnknown_810AC62;
            r1->unk4 += gUnknown_810AC62;
        }
        if(r4 == 0x2B)
        {
            // TODO: regs get a little f**ked
            reg1_8 = (u8)gUnknown_810AC68;
            r1->unk10 += reg1_8;
            r1->unk11 += reg1_8;

            reg1 = gUnknown_810AC68;
            r1->unk0 += reg1;
            r1->unk4 += reg1;
        }
        if(r4 == 0x1E)
        {
            r1->unk12 += gUnknown_810AC64;
            r1->unk8 += gUnknown_810AC64;
        }
        if(r4 == 0x22)
        {
            r1->unk13 += gUnknown_810AC66;
            r1->unkC += gUnknown_810AC66;
        }
    }
}
#else
NAKED
void sub_808E9EC(PokemonStruct1 *r0, struct unkStruct_808E9EC *r1)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tadds r3, r1, 0\n"
	"\tldrb r2, [r0, 0x18]\n"
	"\tstr r2, [r3]\n"
	"\tldrb r1, [r0, 0x19]\n"
	"\tstr r1, [r3, 0x4]\n"
	"\tldrb r1, [r0, 0x1A]\n"
	"\tstr r1, [r3, 0x8]\n"
	"\tldrb r1, [r0, 0x1B]\n"
	"\tstr r1, [r3, 0xC]\n"
	"\tmovs r1, 0\n"
	"\tstrb r1, [r3, 0x10]\n"
	"\tstrb r1, [r3, 0x11]\n"
	"\tstrb r1, [r3, 0x12]\n"
	"\tstrb r1, [r3, 0x13]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x28\n"
	"\tldrb r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808EA96\n"
	"\tadds r4, r0, 0\n"
	"\tadds r5, r4, 0\n"
	"\tcmp r4, 0x13\n"
	"\tbne _0808EA2A\n"
	"\tldr r1, _0808EA9C\n"
	"\tldrh r0, [r1]\n"
	"\tstrb r0, [r3, 0x10]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r0, [r1, r6]\n"
	"\tadds r0, r2, r0\n"
	"\tstr r0, [r3]\n"
"_0808EA2A:\n"
	"\tcmp r4, 0x21\n"
	"\tbne _0808EA42\n"
	"\tldr r1, _0808EAA0\n"
	"\tldrb r0, [r1]\n"
	"\tldrb r2, [r3, 0x11]\n"
	"\tadds r0, r2\n"
	"\tstrb r0, [r3, 0x11]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r1, r6]\n"
	"\tldr r0, [r3, 0x4]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0x4]\n"
"_0808EA42:\n"
	"\tcmp r4, 0x2B\n"
	"\tbne _0808EA66\n"
	"\tldr r2, _0808EAA4\n"
	"\tldrb r0, [r2]\n"
	"\tldrb r6, [r3, 0x10]\n"
	"\tadds r1, r0, r6\n"
	"\tstrb r1, [r3, 0x10]\n"
	"\tldrb r1, [r3, 0x11]\n"
	"\tadds r0, r1\n"
	"\tstrb r0, [r3, 0x11]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r2, r6]\n"
	"\tldr r0, [r3]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3]\n"
	"\tldr r0, [r3, 0x4]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0x4]\n"
"_0808EA66:\n"
	"\tcmp r4, 0x1E\n"
	"\tbne _0808EA7E\n"
	"\tldr r1, _0808EAA8\n"
	"\tldrb r0, [r1]\n"
	"\tldrb r2, [r3, 0x12]\n"
	"\tadds r0, r2\n"
	"\tstrb r0, [r3, 0x12]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r1, r6]\n"
	"\tldr r0, [r3, 0x8]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0x8]\n"
"_0808EA7E:\n"
	"\tcmp r5, 0x22\n"
	"\tbne _0808EA96\n"
	"\tldr r1, _0808EAAC\n"
	"\tldrb r0, [r1]\n"
	"\tldrb r2, [r3, 0x13]\n"
	"\tadds r0, r2\n"
	"\tstrb r0, [r3, 0x13]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r1, r6]\n"
	"\tldr r0, [r3, 0xC]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0xC]\n"
"_0808EA96:\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808EA9C: .4byte gUnknown_810AC60\n"
"_0808EAA0: .4byte gUnknown_810AC62\n"
"_0808EAA4: .4byte gUnknown_810AC68\n"
"_0808EAA8: .4byte gUnknown_810AC64\n"
"_0808EAAC: .4byte gUnknown_810AC66");
}
#endif

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

void sub_808ED00() {
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

void sub_808F468(PokemonStruct1 *param_1, EvolveStatus *evolveStatus, u8 param_3)
{
    bool8 evolFlag;
    u8 friendArea;
    u8 uVar2;
    s32 numPokemon;
    FriendAreaCapacity local_40; // sp 0x0
    unkEvolve evolveConditions; // r7
    s32 index, index2;
#ifndef NONMATCHING
    register s32 defaultReason asm("sl");
#else
    s32 defaultReason;
#endif

    evolveStatus->evolutionConditionStatus = 0;
    for(index = MONSTER_BULBASAUR; index < MONSTER_MAX; index++)
    {
        if ((s16)index == MONSTER_ALAKAZAM) {
            GetPokemonEvolveConditions(MONSTER_ALAKAZAM, &evolveConditions);
        }
        else {
            GetPokemonEvolveConditions(index, &evolveConditions);
        }
        if(((evolveConditions.preEvolution.evolveType != EVOLVE_TYPE_NONE) && (param_1->speciesNum == evolveConditions.preEvolution.evolveFrom)))
            break;
    };
    if (index == MONSTER_MAX) {
        evolveStatus->evolutionConditionStatus = EVOLUTION_NO_MORE;
    }
    else {
        for(index = MONSTER_BULBASAUR, defaultReason = EVOLUTION_LACK_ITEM; index < MONSTER_MAX; index++)
        {
            evolFlag = FALSE;
            index2 = (s16)index;
            GetPokemonEvolveConditions(index2, &evolveConditions);
            if ((evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_NONE) || (param_1->speciesNum != evolveConditions.preEvolution.evolveFrom)) continue;
            friendArea = ((u8 (*)(s32))GetFriendArea)(index2); // UB
            uVar2 = GetFriendArea(param_1->speciesNum);
            GetFriendAreaCapacity2(friendArea,&local_40,FALSE,FALSE);
            if (!local_40.hasFriendArea) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_FRIEND_AREA;
                evolFlag = TRUE;
            }
            else {
                numPokemon = local_40.currNoPokemon;
                if (friendArea == uVar2) {
                    numPokemon--;
                }
                if (local_40.maxPokemon <= numPokemon) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ROOM;
                    evolFlag = TRUE;
                }
            }
            if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_LEVEL) {
                if ((evolveStatus->evolutionConditionStatus & EVOLUTION_GOOD)) continue;
                if (param_1->level < evolveConditions.evolutionRequirements.mainRequirement) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_LEVEL;
                    evolFlag = TRUE;
                }
            }
            else if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_IQ) {
                if (param_1->IQ < evolveConditions.evolutionRequirements.mainRequirement) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_IQ;
                    evolFlag = TRUE;
                }
            }
            else if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_ITEM) {
                if (param_3 != 0) {
                    if ((evolveStatus->evoItem1 != evolveConditions.evolutionRequirements.mainRequirement) &&
                        (evolveStatus->evoItem2 != evolveConditions.evolutionRequirements.mainRequirement)) {
                        evolveStatus->evolutionConditionStatus |= defaultReason;
                        evolFlag = TRUE;
                    }
                }
                else
                {
                    if (FindItemInInventory(evolveConditions.evolutionRequirements.mainRequirement) < 0) {
                        evolveStatus->evolutionConditionStatus |= defaultReason;
                        evolFlag = TRUE;
                    }
                }
            }
            if (evolveConditions.evolutionRequirements.additionalRequirement == 4) {
                if (param_3 != 0) {
                    if ((evolveStatus->evoItem1 != ITEM_LINK_CABLE) && (evolveStatus->evoItem2 != ITEM_LINK_CABLE))
                    {
                        evolveStatus->evolutionConditionStatus |= defaultReason;
                        continue;
                    }
                }
                else
                {
                    if (-1 < FindItemInInventory(ITEM_LINK_CABLE)) goto _0808F6CA;
                    evolveStatus->evolutionConditionStatus |= defaultReason;
                    continue;
                }
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 5) {
                if ((param_1->offense).att[0] > (param_1->offense).def[0]) goto _0808F6CA;
                else continue;
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 6) {
                if ((param_1->offense).att[0] < (param_1->offense).def[0]) goto _0808F6CA;
                else continue;
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 7) {
                if ((param_1->offense).att[0] == (param_1->offense).def[0]) goto _0808F6CA;
                else continue;
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 8)
            {
                if (param_3 != 0) {
                    if ((evolveStatus->evoItem1 != ITEM_SUN_RIBBON) && (evolveStatus->evoItem2 != ITEM_SUN_RIBBON))
                    {
                        evolveStatus->evolutionConditionStatus |= defaultReason;
                        continue;
                    }
                    else goto _0808F6CA;
                }
                else {
                    if (-1 < FindItemInInventory(ITEM_SUN_RIBBON)) goto _0808F6CA;
                    evolveStatus->evolutionConditionStatus |= defaultReason;
                    continue;
                }
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 9) {
                if (param_3 != 0) {
                    if ((evolveStatus->evoItem1 != ITEM_LUNAR_RIBBON) && (evolveStatus->evoItem2 != ITEM_LUNAR_RIBBON))
                    {
                        evolveStatus->evolutionConditionStatus |= defaultReason;
                        continue;
                    }
                    else goto _0808F6CA;
                }
                else
                {
                    if (-1 < FindItemInInventory(ITEM_LUNAR_RIBBON)) goto _0808F6CA;
                    evolveStatus->evolutionConditionStatus |= defaultReason;
                    continue;
                }
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 11) {
                if (!(evolveStatus->wurmpleVal & 1)) goto _0808F6CA;
                else  continue;
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 12) {
                if ((evolveStatus->wurmpleVal & 1)) goto _0808F6CA;
                else  continue;
            }
            else if (evolveConditions.evolutionRequirements.additionalRequirement == 10) {
                if (param_3 != 0) {
                    if ((evolveStatus->evoItem1 == ITEM_BEAUTY_SCARF) || (evolveStatus->evoItem2 == ITEM_BEAUTY_SCARF)) goto _0808F6CA;
                    else continue;
                }
                else
                {
                    if ( FindItemInInventory(ITEM_BEAUTY_SCARF) < 0) evolFlag = TRUE;
                }
            }
        _0808F6CA:
            if (!evolFlag) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_GOOD;
                evolveStatus->targetEvolveSpecies = index2;
            }
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


//  https://decomp.me/scratch/qONOW  - 91.59% matched (Seth)
NAKED
void CreatePokemonInfoTabScreen(u32 param_1, s32 param_2, struct unkStruct_808FF20 *param_3, u8 *param_4, u32 param_5)
{
    asm_unified(
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x30\n"
"	adds r5, r0, 0\n"
"	adds r4, r1, 0\n"
"	mov r10, r2\n"
"	str r3, [sp, 0x2C]\n"
"	ldr r0, [sp, 0x50]\n"
"	bl sub_80073B8\n"
"	ldr r0, _0808F880\n"
"	mov r1, r10\n"
"	adds r1, 0x2\n"
"	movs r2, 0x14\n"
"	bl strncpy\n"
"	movs r0, 0x20\n"
"	mov r9, r0\n"
"	cmp r5, 0x5\n"
"	bls _0808F874\n"
"	b _0808FED6\n"
"_0808F874:\n"
"	lsls r0, r5, 2\n"
"	ldr r1, _0808F884\n"
"	adds r0, r1\n"
"	ldr r0, [r0]\n"
"	mov pc, r0\n"
"	.align 2, 0\n"
"_0808F880: .4byte gFormatBuffer_Monsters\n"
"_0808F884: .4byte _0808F888\n"
"	.align 2, 0\n"
"_0808F888:\n"
"	.4byte _0808FED6\n"
"	.4byte _0808FBF4\n"
"	.4byte _0808F8A0\n"
"	.4byte _0808FB44\n"
"	.4byte _0808FCB0\n"
"	.4byte _0808FDB0\n"
"_0808F8A0:\n"
"	lsls r0, r4, 3\n"
"	adds r0, 0x10\n"
"	ldr r2, _0808F998\n"
"	movs r5, 0\n"
"	str r5, [sp]\n"
"	movs r1, 0\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	ldr r4, _0808F99C\n"
"	mov r1, r10\n"
"	ldr r0, [r1, 0x2C]\n"
"	str r0, [r4]\n"
"	ldr r0, [r1, 0x30]\n"
"	str r0, [r4, 0x4]\n"
"	ldr r0, _0808F9A0\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r2, 0xA\n"
"	add r9, r2\n"
"	ldr r0, _0808F9A4\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r3, 0xA\n"
"	add r9, r3\n"
"	mov r0, r10\n"
"	ldr r2, [r0, 0x2C]\n"
"	cmp r2, 0x63\n"
"	bgt _0808F914\n"
"	movs r3, 0\n"
"	ldrsh r1, [r0, r3]\n"
"	adds r2, 0x1\n"
"	add r0, sp, 0x8\n"
"	bl GetPokemonLevelData\n"
"	ldr r0, [sp, 0x8]\n"
"	mov r2, r10\n"
"	ldr r1, [r2, 0x30]\n"
"	subs r0, r1\n"
"	str r0, [r4]\n"
"	ldr r0, _0808F9A8\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"_0808F914:\n"
"	movs r3, 0xC\n"
"	add r9, r3\n"
"	mov r1, r10\n"
"	ldr r0, [r1, 0x24]\n"
"	str r0, [r4]\n"
"	ldr r0, [r1, 0x28]\n"
"	str r0, [r4, 0x4]\n"
"	ldr r0, _0808F9AC\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r2, 0xA\n"
"	add r9, r2\n"
"	ldr r0, _0808F9B0\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	ldr r0, _0808F9B4\n"
"	ldr r2, [r0]\n"
"	mov r0, r10\n"
"	adds r0, 0x34\n"
"	ldrb r3, [r0]\n"
"	str r3, [r4]\n"
"	mov r1, r10\n"
"	adds r1, 0x39\n"
"	ldrb r0, [r1]\n"
"	cmp r0, 0\n"
"	beq _0808F964\n"
"	adds r0, r3, r0\n"
"	str r0, [r4]\n"
"	ldr r0, _0808F9B8\n"
"	ldr r2, [r0]\n"
"_0808F964:\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	mov r1, r10\n"
"	adds r1, 0x3B\n"
"	ldrb r3, [r1]\n"
"	cmp r3, 0\n"
"	beq _0808F9C0\n"
"	mov r0, r10\n"
"	adds r0, 0x36\n"
"	ldrb r0, [r0]\n"
"	adds r1, r3, 0\n"
"	adds r0, r1\n"
"	str r0, [r4]\n"
"	ldr r0, _0808F9BC\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	b _0808F9D8\n"
"	.align 2, 0\n"
"_0808F998: .4byte gUnknown_8107754\n"
"_0808F99C: .4byte gFormatArgs\n"
"_0808F9A0: .4byte gLevel810DD6C_Ptr\n"
"_0808F9A4: .4byte gExpPts810DD9C_Ptr\n"
"_0808F9A8: .4byte gUnknown_810DDB8\n"
"_0808F9AC: .4byte gUnknown_810DDD0\n"
"_0808F9B0: .4byte gUnknown_810DDE4\n"
"_0808F9B4: .4byte gUnknown_810DE0C\n"
"_0808F9B8: .4byte gUnknown_810DE20\n"
"_0808F9BC: .4byte gUnknown_810DE4C\n"
"_0808F9C0:\n"
"	mov r0, r10\n"
"	adds r0, 0x36\n"
"	ldrb r0, [r0]\n"
"	str r0, [r4]\n"
"	ldr r0, _0808FA44\n"
"	ldr r2, [r0]\n"
"	str r3, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"_0808F9D8:\n"
"	movs r3, 0xA\n"
"	add r9, r3\n"
"	ldr r0, _0808FA48\n"
"	ldr r2, [r0]\n"
"	movs r5, 0\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	ldr r0, _0808FA4C\n"
"	ldr r2, [r0]\n"
"	ldr r4, _0808FA50\n"
"	mov r0, r10\n"
"	adds r0, 0x35\n"
"	ldrb r3, [r0]\n"
"	str r3, [r4]\n"
"	mov r1, r10\n"
"	adds r1, 0x3A\n"
"	ldrb r0, [r1]\n"
"	cmp r0, 0\n"
"	beq _0808FA0E\n"
"	adds r0, r3, r0\n"
"	str r0, [r4]\n"
"	ldr r0, _0808FA54\n"
"	ldr r2, [r0]\n"
"_0808FA0E:\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	mov r1, r10\n"
"	adds r1, 0x3C\n"
"	ldrb r3, [r1]\n"
"	cmp r3, 0\n"
"	beq _0808FA5C\n"
"	mov r0, r10\n"
"	adds r0, 0x37\n"
"	ldrb r0, [r0]\n"
"	adds r1, r3, 0\n"
"	adds r0, r1\n"
"	str r0, [r4]\n"
"	ldr r0, _0808FA58\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	b _0808FA74\n"
"	.align 2, 0\n"
"_0808FA44: .4byte gUnknown_810DE38\n"
"_0808FA48: .4byte gUnknown_810DDFC\n"
"_0808FA4C: .4byte gUnknown_810DE24\n"
"_0808FA50: .4byte gFormatArgs\n"
"_0808FA54: .4byte gUnknown_810DE28\n"
"_0808FA58: .4byte gUnknown_810DE54\n"
"_0808FA5C:\n"
"	mov r0, r10\n"
"	adds r0, 0x37\n"
"	ldrb r0, [r0]\n"
"	str r0, [r4]\n"
"	ldr r0, _0808FA94\n"
"	ldr r2, [r0]\n"
"	str r3, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"_0808FA74:\n"
"	movs r0, 0xA\n"
"	add r9, r0\n"
"	mov r2, r10\n"
"	adds r2, 0x20\n"
"	ldrb r1, [r2]\n"
"	movs r0, 0x1\n"
"	ands r0, r1\n"
"	cmp r0, 0\n"
"	beq _0808FA9C\n"
"	ldr r0, _0808FA98\n"
"	adds r1, r2, 0\n"
"	movs r2, 0\n"
"	bl sub_8090E14\n"
"	b _0808FAA6\n"
"	.align 2, 0\n"
"_0808FA94: .4byte gUnknown_810DE50\n"
"_0808FA98: .4byte gFormatBuffer_Items\n"
"_0808FA9C:\n"
"	ldr r0, _0808FB24\n"
"	ldr r1, _0808FB28\n"
"	ldr r1, [r1]\n"
"	bl strcpy\n"
"_0808FAA6:\n"
"	ldr r0, _0808FB2C\n"
"	ldr r2, [r0]\n"
"	movs r4, 0\n"
"	str r4, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r1, 0xC\n"
"	add r9, r1\n"
"	ldr r1, _0808FB30\n"
"	mov r2, r10\n"
"	movs r3, 0x3E\n"
"	ldrsh r0, [r2, r3]\n"
"	str r0, [r1]\n"
"	movs r1, 0x3E\n"
"	ldrsh r0, [r2, r1]\n"
"	movs r1, 0xA\n"
"	bl __divsi3\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	cmp r0, 0\n"
"	bge _0808FADA\n"
"	movs r0, 0\n"
"_0808FADA:\n"
"	cmp r0, 0x62\n"
"	ble _0808FAE0\n"
"	movs r0, 0x63\n"
"_0808FAE0:\n"
"	ldr r1, _0808FB34\n"
"	lsls r0, 2\n"
"	adds r0, r1\n"
"	ldr r5, _0808FB38\n"
"	ldr r1, [r0]\n"
"	adds r0, r5, 0\n"
"	bl strcpy\n"
"	ldr r0, _0808FB3C\n"
"	ldr r2, [r0]\n"
"	str r4, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r2, 0xA\n"
"	add r9, r2\n"
"	mov r0, r10\n"
"	adds r0, 0x38\n"
"	ldrb r4, [r0]\n"
"	cmp r4, 0\n"
"	beq _0808FB10\n"
"	b _0808FED6\n"
"_0808FB10:\n"
"	adds r0, 0x1C\n"
"	ldrb r1, [r0]\n"
"	adds r0, r5, 0\n"
"	bl CopyTacticsNameToBuffer\n"
"	ldr r0, _0808FB40\n"
"	ldr r2, [r0]\n"
"	str r4, [sp]\n"
"	b _0808FECC\n"
"	.align 2, 0\n"
"_0808FB24: .4byte gFormatBuffer_Items\n"
"_0808FB28: .4byte gUnknown_810DE58\n"
"_0808FB2C: .4byte gUnknown_810DE6C\n"
"_0808FB30: .4byte gFormatArgs\n"
"_0808FB34: .4byte gUnknown_8115718\n"
"_0808FB38: .4byte gFormatBuffer_Monsters\n"
"_0808FB3C: .4byte gUnknown_810DE80\n"
"_0808FB40: .4byte gUnknown_810DE98\n"
"_0808FB44:\n"
"	lsls r0, r4, 3\n"
"	adds r0, 0x10\n"
"	ldr r2, _0808FBE8\n"
"	movs r4, 0\n"
"	str r4, [sp]\n"
"	movs r1, 0\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	ldr r2, _0808FBEC\n"
"	str r4, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	mov r3, r10\n"
"	ldrb r0, [r3, 0x16]\n"
"	bl GetFormattedTypeString\n"
"	adds r2, r0, 0\n"
"	str r4, [sp]\n"
"	movs r0, 0x38\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	mov r1, r10\n"
"	ldrb r0, [r1, 0x17]\n"
"	cmp r0, 0\n"
"	beq _0808FB94\n"
"	bl GetFormattedTypeString\n"
"	adds r2, r0, 0\n"
"	str r4, [sp]\n"
"	movs r0, 0x60\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"_0808FB94:\n"
"	movs r2, 0xC\n"
"	add r9, r2\n"
"	ldr r2, _0808FBF0\n"
"	str r4, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r3, 0xC\n"
"	add r9, r3\n"
"	mov r1, r10\n"
"	ldrb r0, [r1, 0x18]\n"
"	bl GetAbilityDescription\n"
"	adds r2, r0, 0\n"
"	str r4, [sp]\n"
"	movs r5, 0xB\n"
"	str r5, [sp, 0x4]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow2\n"
"	movs r2, 0x21\n"
"	add r9, r2\n"
"	mov r3, r10\n"
"	ldrb r0, [r3, 0x19]\n"
"	cmp r0, 0\n"
"	bne _0808FBD2\n"
"	b _0808FED6\n"
"_0808FBD2:\n"
"	bl GetAbilityDescription\n"
"	adds r2, r0, 0\n"
"	str r4, [sp]\n"
"	str r5, [sp, 0x4]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow2\n"
"	b _0808FED6\n"
"	.align 2, 0\n"
"_0808FBE8: .4byte gUnknown_810775C\n"
"_0808FBEC: .4byte gUnknown_8107768\n"
"_0808FBF0: .4byte gUnknown_8107770\n"
"_0808FBF4:\n"
"	lsls r0, r4, 3\n"
"	adds r0, 0x10\n"
"	ldr r1, _0808FC34\n"
"	ldr r2, [r1]\n"
"	movs r1, 0\n"
"	str r1, [sp]\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	mov r0, r10\n"
"	adds r0, 0x56\n"
"	movs r1, 0\n"
"	ldrsh r0, [r0, r1]\n"
"	subs r5, r0, 0x1\n"
"	movs r2, 0xC\n"
"	negs r2, r2\n"
"	add r9, r2\n"
"	movs r7, 0\n"
"	ldr r6, [sp, 0x2C]\n"
"	adds r6, 0xC\n"
"	adds r1, r6, 0\n"
"	movs r2, 0\n"
"	ldr r0, [sp, 0x2C]\n"
"	adds r0, 0x2C\n"
"_0808FC24:\n"
"	str r2, [r0]\n"
"	subs r0, 0x4\n"
"	cmp r0, r1\n"
"	bge _0808FC24\n"
"	movs r3, 0\n"
"	mov r8, r3\n"
"	b _0808FC88\n"
"	.align 2, 0\n"
"_0808FC34: .4byte gUnknown_810DD58\n"
"_0808FC38:\n"
"	mov r0, r10\n"
"	adds r0, 0x58\n"
"	adds r4, r0, r5\n"
"	ldrb r0, [r4]\n"
"	cmp r0, 0\n"
"	beq _0808FC78\n"
"	movs r7, 0x1\n"
"	ldr r0, _0808FCA0\n"
"	ldrb r1, [r4]\n"
"	lsls r1, 2\n"
"	adds r1, r0\n"
"	ldr r0, _0808FCA4\n"
"	ldr r1, [r1]\n"
"	movs r2, 0x50\n"
"	bl strncpy\n"
"	ldr r2, _0808FCA8\n"
"	movs r0, 0\n"
"	str r0, [sp]\n"
"	movs r0, 0xC\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	mov r0, r8\n"
"	cmp r0, 0\n"
"	ble _0808FC78\n"
"	subs r0, 0x1\n"
"	lsls r0, 2\n"
"	adds r0, r6, r0\n"
"	ldrb r1, [r4]\n"
"	str r1, [r0]\n"
"_0808FC78:\n"
"	movs r1, 0x1\n"
"	add r8, r1\n"
"	adds r5, 0x1\n"
"	movs r2, 0xC\n"
"	add r9, r2\n"
"	mov r3, r8\n"
"	cmp r3, 0x9\n"
"	bgt _0808FC90\n"
"_0808FC88:\n"
"	cmp r5, 0\n"
"	blt _0808FC78\n"
"	cmp r5, 0xB\n"
"	ble _0808FC38\n"
"_0808FC90:\n"
"	cmp r7, 0\n"
"	beq _0808FC96\n"
"	b _0808FED6\n"
"_0808FC96:\n"
"	ldr r0, _0808FCAC\n"
"	ldr r2, [r0]\n"
"	str r7, [sp]\n"
"	b _0808FD98\n"
"	.align 2, 0\n"
"_0808FCA0: .4byte gStatusNames\n"
"_0808FCA4: .4byte gFormatBuffer_Items + 0x50\n"
"_0808FCA8: .4byte gUnknown_8107784\n"
"_0808FCAC: .4byte gUnknown_810DF78\n"
"_0808FCB0:\n"
"	lsls r0, r4, 3\n"
"	adds r0, 0x10\n"
"	ldr r1, _0808FCF8\n"
"	ldr r2, [r1]\n"
"	movs r1, 0\n"
"	str r1, [sp]\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	add r4, sp, 0x14\n"
"	mov r0, r10\n"
"	movs r2, 0x3E\n"
"	ldrsh r1, [r0, r2]\n"
"	adds r0, r4, 0\n"
"	bl GetNumAvailableIQSkills\n"
"	mov r0, r10\n"
"	adds r0, 0x40\n"
"	movs r3, 0\n"
"	ldrsh r0, [r0, r3]\n"
"	subs r7, r0, 0x1\n"
"	mov r1, r9\n"
"	subs r1, 0xC\n"
"	movs r2, 0\n"
"	ldr r0, [sp, 0x2C]\n"
"	adds r0, 0x8\n"
"_0808FCE4:\n"
"	strb r2, [r0]\n"
"	subs r0, 0x1\n"
"	ldr r3, [sp, 0x2C]\n"
"	cmp r0, r3\n"
"	bge _0808FCE4\n"
"	mov r9, r1\n"
"	movs r4, 0\n"
"	mov r8, r4\n"
"	b _0808FD84\n"
"	.align 2, 0\n"
"_0808FCF8: .4byte gIQSkill810DD68_Ptr\n"
"_0808FCFC:\n"
"	mov r5, sp\n"
"	adds r5, r7\n"
"	adds r5, 0x14\n"
"	ldrb r0, [r5]\n"
"	cmp r0, 0\n"
"	beq _0808FD74\n"
"	movs r4, 0x1\n"
"	bl GetIQSkillName\n"
"	adds r1, r0, 0\n"
"	ldr r6, _0808FD3C\n"
"	adds r0, r6, 0\n"
"	movs r2, 0x50\n"
"	bl strncpy\n"
"	mov r0, r10\n"
"	adds r0, 0x50\n"
"	adds r1, r4, 0\n"
"	ldrb r5, [r5]\n"
"	lsls r1, r5\n"
"	bl IsIQSkillSet\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0808FD44\n"
"	adds r0, r6, 0\n"
"	subs r0, 0x50\n"
"	ldr r1, _0808FD40\n"
"	bl strcpy\n"
"	b _0808FD4E\n"
"	.align 2, 0\n"
"_0808FD3C: .4byte gFormatBuffer_Items + 0x50\n"
"_0808FD40: .4byte gUnknown_8107788\n"
"_0808FD44:\n"
"	adds r0, r6, 0\n"
"	subs r0, 0x50\n"
"	ldr r1, _0808FDA4\n"
"	bl strcpy\n"
"_0808FD4E:\n"
"	mov r0, r8\n"
"	cmp r0, 0\n"
"	ble _0808FD64\n"
"	subs r0, 0x1\n"
"	ldr r1, [sp, 0x2C]\n"
"	adds r0, r1, r0\n"
"	mov r1, sp\n"
"	adds r1, r7\n"
"	adds r1, 0x14\n"
"	ldrb r1, [r1]\n"
"	strb r1, [r0]\n"
"_0808FD64:\n"
"	ldr r2, _0808FDA8\n"
"	movs r0, 0\n"
"	str r0, [sp]\n"
"	movs r0, 0xC\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"_0808FD74:\n"
"	movs r2, 0x1\n"
"	add r8, r2\n"
"	adds r7, 0x1\n"
"	movs r3, 0xC\n"
"	add r9, r3\n"
"	mov r0, r8\n"
"	cmp r0, 0x9\n"
"	bgt _0808FD8C\n"
"_0808FD84:\n"
"	cmp r7, 0\n"
"	blt _0808FD74\n"
"	cmp r7, 0x17\n"
"	ble _0808FCFC\n"
"_0808FD8C:\n"
"	cmp r4, 0\n"
"	beq _0808FD92\n"
"	b _0808FED6\n"
"_0808FD92:\n"
"	ldr r0, _0808FDAC\n"
"	ldr r2, [r0]\n"
"	str r4, [sp]\n"
"_0808FD98:\n"
"	movs r0, 0xC\n"
"	movs r1, 0x20\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	b _0808FED6\n"
"	.align 2, 0\n"
"_0808FDA4: .4byte gUnknown_810778C\n"
"_0808FDA8: .4byte gUnknown_8107790\n"
"_0808FDAC: .4byte gUnknown_810DF84\n"
"_0808FDB0:\n"
"	lsls r0, r4, 3\n"
"	adds r0, 0x10\n"
"	ldr r2, _0808FEEC\n"
"	movs r5, 0\n"
"	str r5, [sp]\n"
"	movs r1, 0\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	ldr r6, _0808FEF0\n"
"	mov r2, r10\n"
"	movs r3, 0\n"
"	ldrsh r1, [r2, r3]\n"
"	adds r0, r6, 0\n"
"	bl CopyMonsterNameToBuffer\n"
"	ldr r1, _0808FEF4\n"
"	mov r2, r10\n"
"	movs r3, 0\n"
"	ldrsh r0, [r2, r3]\n"
"	str r0, [r1]\n"
"	ldr r0, _0808FEF8\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r0, 0xA\n"
"	add r9, r0\n"
"	mov r1, r10\n"
"	movs r2, 0\n"
"	ldrsh r0, [r1, r2]\n"
"	bl GetFriendArea\n"
"	lsls r0, 24\n"
"	lsrs r0, 24\n"
"	bl GetFriendAreaName\n"
"	adds r1, r0, 0\n"
"	ldr r4, _0808FEFC\n"
"	adds r0, r4, 0\n"
"	movs r2, 0x50\n"
"	bl strncpy\n"
"	ldr r0, _0808FF00\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r3, 0xA\n"
"	add r9, r3\n"
"	ldr r0, _0808FF04\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r0, 0xD\n"
"	add r9, r0\n"
"	ldr r0, _0808FF08\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r1, 0xA\n"
"	add r9, r1\n"
"	mov r1, r10\n"
"	adds r1, 0x1C\n"
"	adds r0, r4, 0\n"
"	bl PrintYellowDungeonNametoBuffer\n"
"	ldr r0, _0808FF0C\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r2, 0xD\n"
"	add r9, r2\n"
"	mov r3, r10\n"
"	movs r1, 0\n"
"	ldrsh r0, [r3, r1]\n"
"	bl GetCategoryString\n"
"	adds r1, r0, 0\n"
"	adds r0, r6, 0\n"
"	movs r2, 0x14\n"
"	bl strncpy\n"
"	ldr r0, _0808FF10\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r2, 0xD\n"
"	add r9, r2\n"
"	ldr r4, _0808FF14\n"
"	mov r3, r10\n"
"	movs r1, 0\n"
"	ldrsh r0, [r3, r1]\n"
"	bl GetBodySize\n"
"	lsls r0, 24\n"
"	lsrs r0, 22\n"
"	adds r0, r4\n"
"	ldr r1, [r0]\n"
"	adds r0, r6, 0\n"
"	bl strcpy\n"
"	ldr r0, _0808FF18\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"	movs r2, 0xD\n"
"	add r9, r2\n"
"	ldr r1, _0808FF1C\n"
"	mov r0, r10\n"
"	adds r0, 0x4C\n"
"	ldrb r0, [r0]\n"
"	lsls r0, 2\n"
"	adds r0, r1\n"
"	ldr r2, [r0]\n"
"	str r5, [sp]\n"
"_0808FECC:\n"
"	movs r0, 0x4\n"
"	mov r1, r9\n"
"	ldr r3, [sp, 0x50]\n"
"	bl PrintFormattedStringOnWindow\n"
"_0808FED6:\n"
"	ldr r0, [sp, 0x50]\n"
"	bl sub_80073E0\n"
"	add sp, 0x30\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0808FEEC: .4byte gUnknown_8107798\n"
"_0808FEF0: .4byte gFormatBuffer_Monsters\n"
"_0808FEF4: .4byte gFormatArgs\n"
"_0808FEF8: .4byte gUnknown_810DEB4\n"
"_0808FEFC: .4byte gFormatBuffer_Items\n"
"_0808FF00: .4byte gUnknown_810DEC8\n"
"_0808FF04: .4byte gUnknown_810DEDC\n"
"_0808FF08: .4byte gUnknown_810DFB4\n"
"_0808FF0C: .4byte gUnknown_810DFC8\n"
"_0808FF10: .4byte gUnknown_810DEF4\n"
"_0808FF14: .4byte gUnknown_810E02C\n"
"_0808FF18: .4byte gUnknown_810DF98\n"
"_0808FF1C: .4byte gEvolutionStrings");
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
