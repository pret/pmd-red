#include "global.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "random.h"
#include "constants/dungeon.h"
#include "constants/evolve_type.h"
#include "constants/evolution_status.h"
#include "constants/iq_skill.h"
#include "constants/tactic.h"
#include "constants/type.h"
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
extern s32 gUnknown_81076C4[6]; // x-coord positioning for shadow sprites

extern SpriteOAM gShadowSprites[3]; // Shadow sprites of some kind
extern s16 gUnknown_810AC60; // 0xC
extern s16 gUnknown_810AC62; // 0xC
extern s16 gUnknown_810AC68; // 0x8
extern s16 gUnknown_810AC64; // 0x8
extern s16 gUnknown_810AC66; // 0x8

// 2, 4, 6, 7, 8, 9, 0xA, 0xD, 0xF, 0x11
extern s32 gUnknown_810AC90[10];

#include "data/pokemon_3.h"

extern void SaveDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
extern void xxx_save_poke_sub_c_808F41C(struct unkStruct_8094924*, struct unkPokeSubStruct_C*);
void RestoreDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
void xxx_restore_poke_sub_c_808F410(struct unkStruct_8094924*, struct unkPokeSubStruct_C*);

extern void sub_809449C(struct unkStruct_8094924*, void*);
extern void SavePokemonHiddenPower(struct unkStruct_8094924*, HiddenPower*);
extern void sub_809447C(struct unkStruct_8094924*, void*);
extern void RestorePokemonHiddenPower(struct unkStruct_8094924*, HiddenPower*);
s16 GetPokemonEvolveConditions(s16 index, unkEvolve *r1);

u32 sub_808F798(PokemonStruct1 *, s16);

bool8 AddShadowSprite(s16 species, s16* a2, s16* a3)
{
    if (species != MONSTER_DIGLETT && species != MONSTER_DUGTRIO) {
        u8 shadowSize = GetShadowSize(species);
        u32 x, unk6;
        SpriteOAM* spr;

        x = a2[0] + a3[8];
        unk6 = a2[1] + a3[9];
        x += gUnknown_81076C4[shadowSize];
        unk6 -= 4;
        x &= SPRITEOAM_MAX_X;

        spr = &gShadowSprites[shadowSize];
        spr->attrib2 &= ~SPRITEOAM_MASK_X;
        spr->attrib2 |= x;
        unk6 &= SPRITEOAM_MAX_UNK6_4;
        unk6 <<= SPRITEOAM_SHIFT_UNK6_4;
        spr->unk6 &= ~SPRITEOAM_MASK_UNK6_4;
        spr->unk6 |= unk6;
        AddSprite(spr, 0, NULL, NULL);
    }

    return TRUE;
}


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
    register s32 a1_ asm("r2") = index;
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

u32 ExtractSpeciesIndex(PokemonStruct1 *r0)
{
    return r0->unk0 & 0x000001ff;
}

void sub_808E9C4(PokemonStruct1 *r0, s16 r1)
{
    s32 r1_s32 = r1; // cast needed to match
    r0->unk0 =  ((0xFE << 8) & r0->unk0) | r1_s32 ;
}

void sub_808E9D8(PokemonStruct1 *r0, s32 r1, s16 r2)
{
    s32 r2_32 = r2; // dumb cast to match
    r0->unk0 =  r2_32 | (r1 << 9) ;
}

u32 ExtractLevel(PokemonStruct1 *r0)
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

void ToggleIQSkill(u8 *param_1, u32 skillIndex)
{
  int iVar2; // a mask?

  iVar2 = 1 << (skillIndex);
  if (IsIQSkillSet(param_1, iVar2)) {
    param_1[0] = param_1[0] & ~iVar2;
    param_1[1] = param_1[1] & ~(iVar2 >> 8);
    param_1[2] = param_1[2] & ~(iVar2 >> 0x10);
  }
  else
  {
    SetIQSkill(param_1, skillIndex);
  }
}

void SetIQSkill(u8 *param_1, u32 skillIndex)
{
  s32 iVar1;
  s32 iqSkill;
  s32 iqSkillGroup;
  s32 iVar5;

  for (iqSkill = 0, iqSkillGroup = gIQSkillGroups[skillIndex]; iqSkill < NUM_IQ_SKILLS; iqSkill++)
  {
    // Turn off each IQ Skill that's in the same group as the chosen skill
    if (iqSkillGroup == gIQSkillGroups[iqSkill]) {
      iVar1 = 1 << (iqSkill);
      param_1[0] = param_1[0] & ~iVar1;
      param_1[1] = param_1[1] & ~(iVar1 >> 8);
      param_1[2] = param_1[2] & ~(iVar1 >> 0x10);
    }
  }

  iVar5 = 1 << (skillIndex);
  param_1[0] |= iVar5;
  param_1[1] |= (iVar5 >> 8);
  param_1[2] |= (iVar5 >> 0x10);
}

void SetDefaultIQSkills(u8 *param_1, bool8 enableSelfCurer)
{

  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  SetIQSkill(param_1, IQ_ITEM_CATCHER);
  SetIQSkill(param_1, IQ_COURSE_CHECKER);
  SetIQSkill(param_1, IQ_ITEM_MASTER);

  // Flag is usually enabled for Boss fights.
  if (enableSelfCurer) {
    SetIQSkill(param_1, IQ_SELF_CURER);
  }
}

bool8 IsIQSkillSet(u8 *IQSkillFlags, u32 IQSkill)
{
  if (!(IQSkillFlags[0] & IQSkill) &&
      !(IQSkillFlags[1] & IQSkill >> 8) &&
      !(IQSkillFlags[2] & IQSkill >> 16))
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
        gRecruitedPokemonRef->team[i].unk0 = 0;
    }
}

s32 SaveRecruitedPokemon(u8 *a1, s32 a2)
{
    u16 buffer[6];
    struct unkStruct_8094924 backup;
    u8 data_u8;
    s16 data_s16;
    s32 count;
    s32 i;
    PokemonStruct1 *pokemon;

    xxx_init_struct_8094924_save_809486C(&backup, a1, a2);

    for (i = 0; i < 6; i++) {
        buffer[i] = -1;
    }

    data_s16 = 1;
    data_s16 = -data_s16;
    count = 0;
    for (i = 0; i < NUM_MONSTERS; i++) {
        // Some check was optimized out. Needed for matching. Thanks kaz
        if (i) {
            u8 unk = -unk;
        }

        pokemon = &gRecruitedPokemonRef->pokemon[i];

        if (pokemon->unk0 & 1) {
            if (pokemon->unk0 & FLAG_ON_TEAM) {
                buffer[count++] = i;
            }
            if (pokemon->isTeamLeader) {
                data_s16 = i;
            }
        }
        else {
            pokemon->level = 0;
        }
        SavePokemonStruct(&backup, pokemon);
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if ((u8)i[gRecruitedPokemonRef->team].unk0 & 1) {
            data_u8 = 0xff;
        }
        else {
            data_u8 = 0;
        }
        SaveIntegerBits(&backup, &data_u8, 1);
        SavePokemonStruct(&backup, &gRecruitedPokemonRef->team[i]);
    }

    for (i = 0; i < 6; i++) {
        SaveIntegerBits(&backup, (u8*)&buffer[i], 16);
    }
    SaveIntegerBits(&backup, (u8*)&data_s16, 16);
    nullsub_102(&backup);
    return backup.unk8;
}

s32 RestoreRecruitedPokemon(u8 *a1, s32 a2)
{
    struct unkStruct_8094924 backup;
    u8 data_u8;  // same as saverecruitedpokemon
    s16 data_s16;  // same as saverecruitedpokemon
    s32 i;

    xxx_init_struct_8094924_restore_809485C(&backup, a1, a2);
    for (i = 0; i < NUM_MONSTERS; i++) {
        RestorePokemonStruct(&backup, &gRecruitedPokemonRef->pokemon[i]);
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        RestoreIntegerBits(&backup, &data_u8, 1);
        RestorePokemonStruct(&backup, &gRecruitedPokemonRef->team[i]);
        if (data_u8 & 1) {
            gRecruitedPokemonRef->team[i].unk0 = 3; // FLAG_ON_TEAM (2) + ??? (1)
        }
        else {
            gRecruitedPokemonRef->team[i].unk0 = 0;
        }
    }

    for (i = 0; i < 6; i++) {
        RestoreIntegerBits(&backup, &data_s16, 16);
        if ((u16)data_s16 < NUM_MONSTERS) {
            gRecruitedPokemonRef->pokemon[data_s16].unk0 |= FLAG_ON_TEAM;
        }
    }
    RestoreIntegerBits(&backup, &data_s16, 16);
    if ((u16)data_s16 < NUM_MONSTERS) {
        gRecruitedPokemonRef->pokemon[data_s16].isTeamLeader = TRUE;
    }
    nullsub_102(&backup);
    return backup.unk8;
}

void SavePokemonStruct(struct unkStruct_8094924* a1, PokemonStruct1* pokemon)
{
  SaveIntegerBits(a1, &pokemon->level, 7);
  SaveIntegerBits(a1, &pokemon->speciesNum, 9);
  SaveDungeonLocation(a1, &pokemon->dungeonLocation);
  xxx_save_poke_sub_c_808F41C(a1, &pokemon->unkC[0]);
  xxx_save_poke_sub_c_808F41C(a1, &pokemon->unkC[1]);
  SaveIntegerBits(a1, &pokemon->IQ, 10);
  SaveIntegerBits(a1, &pokemon->pokeHP, 10);
  SaveIntegerBits(a1, &pokemon->offense.att[0], 8);
  SaveIntegerBits(a1, &pokemon->offense.att[1], 8);
  SaveIntegerBits(a1, &pokemon->offense.def[0], 8);
  SaveIntegerBits(a1, &pokemon->offense.def[1], 8);
  SaveIntegerBits(a1, &pokemon->currExp, 24);
  SaveIntegerBits(a1, &pokemon->IQSkills, 24);
  SaveIntegerBits(a1, &pokemon->tacticIndex, 4);
  SaveHeldItem(a1, &pokemon->heldItem);
  SavePokemonMoves(a1, pokemon->moves);
  SaveIntegerBits(a1, pokemon->name, 80);
}

void RestorePokemonStruct(struct unkStruct_8094924* a1, PokemonStruct1* pokemon)
{
  memset(pokemon, 0, sizeof(PokemonStruct1));
  pokemon->unk0 = 0;
  pokemon->isTeamLeader = 0;
  RestoreIntegerBits(a1, &pokemon->level, 7);
  if (pokemon->level) {
      pokemon->unk0 |= 1;
  }
  RestoreIntegerBits(a1, &pokemon->speciesNum, 9);
  RestoreDungeonLocation(a1, &pokemon->dungeonLocation);
  xxx_restore_poke_sub_c_808F410(a1, &pokemon->unkC[0]);
  xxx_restore_poke_sub_c_808F410(a1, &pokemon->unkC[1]);
  RestoreIntegerBits(a1, &pokemon->IQ, 10);
  RestoreIntegerBits(a1, &pokemon->pokeHP, 10);
  RestoreIntegerBits(a1, &pokemon->offense.att[0], 8);
  RestoreIntegerBits(a1, &pokemon->offense.att[1], 8);
  RestoreIntegerBits(a1, &pokemon->offense.def[0], 8);
  RestoreIntegerBits(a1, &pokemon->offense.def[1], 8);
  RestoreIntegerBits(a1, &pokemon->currExp, 24);
  RestoreIntegerBits(a1, &pokemon->IQSkills, 24);
  RestoreIntegerBits(a1, &pokemon->tacticIndex, 4);
  RestoreHeldItem(a1, &pokemon->heldItem);
  RestorePokemonMoves(a1, pokemon->moves);
  RestoreIntegerBits(a1, pokemon->name, 80);
}

s32 SavePokemonStruct2(u8* a1, s32 size)
{
  struct unkStruct_8094924 backup;
  s32 i;
  u8 data_u8_neg1;
  u8 data_u8_zero;

  xxx_init_struct_8094924_save_809486C(&backup, a1, size);
  data_u8_neg1 = -1;
  data_u8_zero = 0;

  for (i = 0; i < 4; i++) {
    PokemonStruct2* pokemon2 = &gRecruitedPokemonRef->pokemon2[i];
    SaveIntegerBits(&backup, &pokemon2->unk0, 2);

    SaveIntegerBits(&backup, pokemon2->isTeamLeader ? &data_u8_neg1 : &data_u8_zero, 1);
    SaveIntegerBits(&backup, &pokemon2->level, 7);

    SaveDungeonLocation(&backup, &pokemon2->dungeonLocation);
    SaveIntegerBits(&backup, &pokemon2->IQ, 10);
    SaveIntegerBits(&backup, &pokemon2->unkA, 16);
    SaveIntegerBits(&backup, &pokemon2->unkC, 16);
    SaveIntegerBits(&backup, &pokemon2->speciesNum, 9);
    SaveIntegerBits(&backup, &pokemon2->unk10, 10);
    SaveIntegerBits(&backup, &pokemon2->unk12, 10);
    SaveIntegerBits(&backup, &pokemon2->offense.att[0], 8);
    SaveIntegerBits(&backup, &pokemon2->offense.att[1], 8);
    SaveIntegerBits(&backup, &pokemon2->offense.def[0], 8);
    SaveIntegerBits(&backup, &pokemon2->offense.def[1], 8);
    SaveIntegerBits(&backup, &pokemon2->currExp, 24);
    sub_8094184(&backup, &pokemon2->moves);
    SaveItemSlot(&backup, &pokemon2->itemSlot);
    sub_809449C(&backup, &pokemon2->belly);
    sub_809449C(&backup, &pokemon2->maxBelly);
    SaveIntegerBits(&backup, &pokemon2->IQSkills, 24);
    SaveIntegerBits(&backup, &pokemon2->tacticIndex, 4);
    SavePokemonHiddenPower(&backup, &pokemon2->hiddenPower);
    SaveIntegerBits(&backup, &pokemon2->name, 80);
  }
  nullsub_102(&backup);
  return backup.unk8;
}

s32 RestorePokemonStruct2(u8* a1, s32 size)
{
  struct unkStruct_8094924 backup;
  s32 i;

  xxx_init_struct_8094924_restore_809485C(&backup, a1, size);
  for (i = 0; i < 4; i++) {
    PokemonStruct2* pokemon2 = &gRecruitedPokemonRef->pokemon2[i];
    u8 unk2;

    memset(pokemon2, 0, sizeof(PokemonStruct2));

    RestoreIntegerBits(&backup, &pokemon2->unk0, 2);

    RestoreIntegerBits(&backup, &unk2, 1);
    if (unk2 & 1) {
        pokemon2->isTeamLeader = TRUE;
    }
    else {
        pokemon2->isTeamLeader = FALSE;
    }
    RestoreIntegerBits(&backup, &pokemon2->level, 7);

    RestoreDungeonLocation(&backup, &pokemon2->dungeonLocation);
    RestoreIntegerBits(&backup, &pokemon2->IQ, 10);
    RestoreIntegerBits(&backup, &pokemon2->unkA, 16);
    RestoreIntegerBits(&backup, &pokemon2->unkC, 16);
    RestoreIntegerBits(&backup, &pokemon2->speciesNum, 9);
    RestoreIntegerBits(&backup, &pokemon2->unk10, 10);
    RestoreIntegerBits(&backup, &pokemon2->unk12, 10);
    RestoreIntegerBits(&backup, &pokemon2->offense.att[0], 8);
    RestoreIntegerBits(&backup, &pokemon2->offense.att[1], 8);
    RestoreIntegerBits(&backup, &pokemon2->offense.def[0], 8);
    RestoreIntegerBits(&backup, &pokemon2->offense.def[1], 8);
    RestoreIntegerBits(&backup, &pokemon2->currExp, 24);
    sub_80941FC(&backup, &pokemon2->moves);
    RestoreItemSlot(&backup, &pokemon2->itemSlot);
    sub_809447C(&backup, &pokemon2->belly);
    sub_809447C(&backup, &pokemon2->maxBelly);
    RestoreIntegerBits(&backup, &pokemon2->IQSkills, 24);
    RestoreIntegerBits(&backup, &pokemon2->tacticIndex, 4);
    RestorePokemonHiddenPower(&backup, &pokemon2->hiddenPower);
    RestoreIntegerBits(&backup, &pokemon2->name, 80);
  }
  nullsub_102(&backup);
  return backup.unk8;
}

void xxx_restore_poke_sub_c_808F410(struct unkStruct_8094924* a1, struct unkPokeSubStruct_C* unkC)
{
  RestoreIntegerBits(a1, &unkC->level, 7);
}

void xxx_save_poke_sub_c_808F41C(struct unkStruct_8094924* a1, struct unkPokeSubStruct_C* unkC)
{
  SaveIntegerBits(a1, &unkC->level, 7);
}

void RestorePokemonHiddenPower(unkStruct_8094924* a1, HiddenPower* a2)
{
  RestoreIntegerBits(a1, &a2->hiddenPowerBasePower, 10);
  RestoreIntegerBits(a1, &a2->hiddenPowerType, 5);
}

void SavePokemonHiddenPower(unkStruct_8094924* a1, HiddenPower* a2)
{
  SaveIntegerBits(a1, &a2->hiddenPowerBasePower, 10);
  SaveIntegerBits(a1, &a2->hiddenPowerType, 5);
}

void sub_808F468(PokemonStruct1 *param_1, EvolveStatus *evolveStatus, u8 param_3)
{
    bool8 evolFlag;
    u8 friendArea;
    u8 uVar2;
    s32 numPokemon;
    unkStruct_8092638 local_40; // sp 0x0
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
            sub_8092638(friendArea,&local_40,FALSE,FALSE);
            if (!local_40.hasFriendArea) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_FRIEND_AREA;
                evolFlag = TRUE;
            }
            else {
                numPokemon = local_40.unk2;
                if (friendArea == uVar2) {
                    numPokemon--;
                }
                if (local_40.numPokemon <= numPokemon) {
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

u8 sub_808F700(PokemonStruct1 *pokemon)
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

u32 sub_808F734(PokemonStruct1 *pokemon, s16 _species)
{
    u32 uVar1;
    int iVar3;
    PokemonStruct1 pokeStruct;
    s32 species = _species;

    iVar3 = 0;
    pokeStruct = *pokemon;
    uVar1 = sub_808F798(pokemon, species);
    if (species == MONSTER_NINJASK) {
        pokeStruct.isTeamLeader = FALSE;
        pokeStruct.heldItem.id = ITEM_NOTHING;
        BoundedCopyStringtoBuffer(pokeStruct.name, GetMonSpecies(MONSTER_SHEDINJA),POKEMON_NAME_LENGTH);
        iVar3 = sub_808F798(&pokeStruct,MONSTER_SHEDINJA);
    }
    if (iVar3 != 0) {
        sub_8097848();
    }
    return uVar1;
}
