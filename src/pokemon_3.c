#include "global.h"
#include "globaldata.h"
#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/tactic.h"
#include "constants/type.h"
#include "structs/sprite_oam.h"
#include "structs/str_pokemon.h"
#include "dungeon_info.h"
#include "friend_area.h"
#include "luminous_cave.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "random.h"
#include "string_format.h"
#include "strings.h"
#include "text_1.h"
#include "text_util.h"
#include "dungeon_data.h"
#include "number_util.h"

struct UnusedOffenseStruct
{
    s32 att[2];
    s32 def[2];
    u8 atkBoost;
    u8 spAtkBoost;
    u8 defBoost;
    u8 spDefBoost;
};

extern SpriteOAM gShadowSprites[3]; // Shadow sprites of some kind

extern void WriteDungeonLocationBits(DataSerializer*, DungeonLocation*);
extern void WritePoke1LevelBits(DataSerializer*, struct unkPokeSubStruct_C*);
void ReadDungeonLocationBits(DataSerializer*, DungeonLocation*);
void ReadPoke1LevelBits(DataSerializer*, struct unkPokeSubStruct_C*);

extern void WriteHiddenPowerBits(DataSerializer*, HiddenPower*);
extern void ReadHiddenPowerBits(DataSerializer*, HiddenPower*);
s16 GetPokemonEvolveConditions(s16 index, unkEvolve *r1);

// arm9.bin::02059FDC
void GenerateHiddenPower(HiddenPower* a1)
{
    s32 i;

    a1->hiddenPowerBasePower = gUnknown_810AC90[RandInt(10)];

    for (i = 0; i < 100; i++) {
        a1->hiddenPowerType = RandInt(NUM_TYPES);
        if (a1->hiddenPowerType)
            break;
    }

    if (i == 100)
        a1->hiddenPowerType = TYPE_FIRE;
}

// arm9.bin::02059F70
bool8 HasRecruitedMon(s32 species_)
{
    s32 species = (s16) species_;
    s32 i = 0;
    Pokemon *pokemon = gRecruitedPokemonRef->pokemon;

    for (i = 0; i < NUM_MONSTERS; i++) {
        if (PokemonExists(pokemon)) {
            if (pokemon->speciesNum == species)
                return TRUE;
        }
        pokemon++;
    }
    return FALSE;
}

// arm9.bin::02059D94
s16 GetBaseSpecies(s16 index)
{
    if (index == MONSTER_CASTFORM_SNOWY)
        return MONSTER_CASTFORM;
    if (index == MONSTER_CASTFORM_SUNNY)
        return MONSTER_CASTFORM;
    if (index == MONSTER_CASTFORM_RAINY)
        return MONSTER_CASTFORM;
    if (index == MONSTER_UNOWN_B)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_C)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_D)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_E)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_F)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_G)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_H)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_I)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_J)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_K)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_L)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_M)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_N)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_O)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_P)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_Q)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_R)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_S)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_T)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_U)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_V)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_W)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_X)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_Y)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_Z)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_EMARK)
        return MONSTER_UNOWN;
    if (index == MONSTER_UNOWN_QMARK)
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

// arm9.bin::02059D04
s16 GetBaseSpeciesNoUnown(s16 index)
{
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

// arm9.bin::02059BB4
s32 GetUnownIndex(s16 index)
{
    if (index == MONSTER_UNOWN_B)
        return 1;
    if (index == MONSTER_UNOWN_C)
        return 2;
    if (index == MONSTER_UNOWN_D)
        return 3;
    if (index == MONSTER_UNOWN_E)
        return 4;
    if (index == MONSTER_UNOWN_F)
        return 5;
    if (index == MONSTER_UNOWN_G)
        return 6;
    if (index == MONSTER_UNOWN_H)
        return 7;
    if (index == MONSTER_UNOWN_I)
        return 8;
    if (index == MONSTER_UNOWN_J)
        return 9;
    if (index == MONSTER_UNOWN_K)
        return 10;
    if (index == MONSTER_UNOWN_L)
        return 11;
    if (index == MONSTER_UNOWN_M)
        return 12;
    if (index == MONSTER_UNOWN_N)
        return 13;
    if (index == MONSTER_UNOWN_O)
        return 14;
    if (index == MONSTER_UNOWN_P)
        return 15;
    if (index == MONSTER_UNOWN_Q)
        return 16;
    if (index == MONSTER_UNOWN_R)
        return 17;
    if (index == MONSTER_UNOWN_S)
        return 18;
    if (index == MONSTER_UNOWN_T)
        return 19;
    if (index == MONSTER_UNOWN_U)
        return 20;
    if (index == MONSTER_UNOWN_V)
        return 21;
    if (index == MONSTER_UNOWN_W)
        return 22;
    if (index == MONSTER_UNOWN_X)
        return 23;
    if (index == MONSTER_UNOWN_Y)
        return 24;
    if (index == MONSTER_UNOWN_Z)
        return 25;
    if (index == MONSTER_UNOWN_EMARK)
        return 26;
    if (index == MONSTER_UNOWN_QMARK)
        return 27;
    return 0;
}

// arm9.bin::02059B98
s16 ExtractSpeciesIndex(SpawnPokemonData *data)
{
    return data->bits & PACKED_BITS_SPECIES;
}

// arm9.bin::02059B7C
void SetSpeciesToExtract(SpawnPokemonData *data, s32 species_)
{
    s32 species = (s16) species_;
    data->bits &= (PACKED_BITS_LEVEL << PACKED_BITS_LEVEL_SHIFT);
    data->bits |= species;
}

#if (GAME_VERSION == VERSION_RED)
void SetSpeciesLevelToExtract(SpawnPokemonData *data, s32 level, s32 species_)
{
    s32 species = (s16) (species_);
    data->bits = species | (level << PACKED_BITS_LEVEL_SHIFT) ;
}
#endif

// arm9.bin::02059B6C
s32 ExtractLevel(SpawnPokemonData *data)
{
    return (data->bits >> PACKED_BITS_LEVEL_SHIFT) & PACKED_BITS_LEVEL;
}

UNUSED static void GetMonOffenseStats(Pokemon *mon, struct UnusedOffenseStruct *dst)
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

// NOTE: File boundary is here in Blue, however pksdir string is missing, so we can't split here.
const u8 *GetIQSkillName(u8 skill)
{
    return gIQSkillNames[skill];
}

void CopyTacticsNameToBuffer(char *buffer, u8 tactic)
{
    strncpy(buffer, gTacticsNames[tactic], 0x14);
}

const u8 *GetIQSkillDescription(u8 skill)
{
    return gIQSkillDescriptions[skill];
}

const u8 *GetTacticsDescription(u8 tactic)
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
        if (gReqTacticLvls[tactic] <= pokeLevel)
        {
            tacticsBuffer[availTactics] = tactic;
            availTactics++;
        }
    }
    if (availTactics > TACTIC_UNUSED)
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
        if (gReqTacticLvls[tactic] <= pokeLevel)
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
    if (IQSkillIndex == IQ_NONE)
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

static const s32 sIQSkillGroups[NUM_IQ_SKILLS] = {
    [IQ_NONE] = 9999,
    [IQ_TYPE_ADVANTAGE_MASTER] = 4,
    [IQ_ITEM_CATCHER] = 1,
    [IQ_COURSE_CHECKER] = 2,
    [IQ_SURE_HIT_ATTACKER] = 4,
    [IQ_QUICK_DODGER] = 4,
    [IQ_PP_CHECKER] = 6,
    [IQ_NONTRAITOR] = 7,
    [IQ_STATUS_CHECKER] = 8,
    [IQ_EXP_GO_GETTER] = 9,
    [IQ_EFFICIENCY_EXPERT] = 9,
    [IQ_WEAK_TYPE_PICKER] = 9,
    [IQ_ALL_TERRAIN_HIKER] = 10,
    [IQ_SUPER_MOBILE] = 10,
    [IQ_TRAP_AVOIDER] = 11,
    [IQ_HOUSE_AVOIDER] = 11,
    [IQ_ENERGY_SAVER] = 14,
    [IQ_NONSLEEPER] = 14,
    [IQ_SELF_CURER] = 14,
    [IQ_TRAP_SEER] = 16,
    [IQ_LAVA_EVADER] = 16,
    [IQ_DEDICATED_TRAVELER] = 9,
    [IQ_ITEM_MASTER] = 17,
    [IQ_EXCLUSIVE_MOVE_USER] = 6,
};

void SetIQSkill(IqSkillFlags *iq, u32 skillIndex)
{
    s32 iqSkill;
    s32 iqSkillGroup;
    s32 bit;

    for (iqSkill = 0, iqSkillGroup = sIQSkillGroups[skillIndex]; iqSkill < NUM_IQ_SKILLS; iqSkill++) {
        // Turn off each IQ Skill that's in the same group as the chosen skill
        if (iqSkillGroup == sIQSkillGroups[iqSkill]) {
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

UNUSED static u32 sub_808ECFC(void)
{
    return 0;
}

// This function does nothing in Blue
void sub_808ED00(void)
{
    if (GAME_VERSION == VERSION_RED) {
        s32 team[4];
        s32 i;
        s32 length = sub_808D580(team);

        for (i = 0; i < length; i++) {
            gRecruitedPokemonRef->team[i] = gRecruitedPokemonRef->pokemon[team[i]];
        }

        for (; i < MAX_TEAM_MEMBERS; i++) {
            gRecruitedPokemonRef->team[i].flags = POKEMON_FLAG_NONE;
        }
    }
}

// arm9.bin::0205CC54
s32 SaveRecruitedPokemon(u8 *a1, s32 a2)
{
    s16 sixMons[6];
    DataSerializer backup;
    s16 teamLeader;
    s32 minus1;
    s32 count;
    s32 i;

    InitBitWriter(&backup, a1, a2);

    for (i = 0; i < 6; i++)
        sixMons[i] = -1;

    // s16 memes
    minus1 = -1;
    teamLeader = minus1;
    count = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        Pokemon *pokemon = &gRecruitedPokemonRef->pokemon[i];

        if (PokemonExists(pokemon)) {
            if (pokemon->flags & POKEMON_FLAG_ON_TEAM)
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
        u8 data_u8;
        if (PokemonExists(&gRecruitedPokemonRef->team[i]))
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

// arm9.bin::0205CAE4
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
            gRecruitedPokemonRef->team[i].flags = POKEMON_FLAG_ON_TEAM | POKEMON_FLAG_EXISTS;
        else
            gRecruitedPokemonRef->team[i].flags = POKEMON_FLAG_NONE;
    }

    // ???
    for (i = 0; i < 6; i++) {
        ReadBits(&backup, &data_s16, 16);
        if ((u16)data_s16 < NUM_MONSTERS)
            gRecruitedPokemonRef->pokemon[data_s16].flags |= POKEMON_FLAG_ON_TEAM;
    }

    // Team leader
    ReadBits(&backup, &data_s16, 16);
    if ((u16)data_s16 < NUM_MONSTERS)
        gRecruitedPokemonRef->pokemon[data_s16].isTeamLeader = TRUE;

    FinishBitSerializer(&backup);
    return backup.count;
}

// arm9.bin::0205C9D4
void WritePoke1Bits(DataSerializer* a1, Pokemon* pokemon)
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
    WriteBits(a1, pokemon->name, POKEMON_NAME_LENGTH * 8);
}

// arm9.bin::0205C890
void ReadPoke1Bits(DataSerializer* a1, Pokemon* pokemon)
{
    memset(pokemon, 0, sizeof(Pokemon));

    pokemon->flags = POKEMON_FLAG_NONE;
    pokemon->isTeamLeader = FALSE;

    ReadBits(a1, &pokemon->level, 7);
    if (pokemon->level)
        pokemon->flags |= POKEMON_FLAG_EXISTS;

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
    ReadBits(a1, pokemon->name, POKEMON_NAME_LENGTH * 8);
}

// arm9.bin::0205C688
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
        DungeonMon* pokemon2 = &gRecruitedPokemonRef->dungeonTeam[i];
        WriteBits(&backup, &pokemon2->flags, 2);

        WriteBits(&backup, pokemon2->isTeamLeader ? &data_u8_neg1 : &data_u8_zero, 1);
        WriteBits(&backup, &pokemon2->level, 7);

        WriteDungeonLocationBits(&backup, &pokemon2->dungeonLocation);
        WriteBits(&backup, &pokemon2->IQ, 10);
        WriteBits(&backup, &pokemon2->recruitedPokemonId, 16);
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
        WriteBits(&backup, &pokemon2->name, POKEMON_NAME_LENGTH * 8);
    }

    FinishBitSerializer(&backup);
    return backup.count;
}

// arm9.bin::0205C464
s32 RestorePoke2s(u8* a1, s32 size)
{
    DataSerializer backup;
    s32 i;

    InitBitReader(&backup, a1, size);

    for (i = 0; i < 4; i++) {
        DungeonMon* pokemon2 = &gRecruitedPokemonRef->dungeonTeam[i];
        u8 unk2;

        memset(pokemon2, 0, sizeof(DungeonMon));

        ReadBits(&backup, &pokemon2->flags, 2);

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
        ReadBits(&backup, &pokemon2->recruitedPokemonId, 16);
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
        ReadBits(&backup, &pokemon2->name, POKEMON_NAME_LENGTH * 8);
    }

    FinishBitSerializer(&backup);
    return backup.count;
}

// arm9.bin::0205C454
void ReadPoke1LevelBits(DataSerializer* a1, struct unkPokeSubStruct_C* unkC)
{
    ReadBits(a1, &unkC->level, 7);
}

// arm9.bin::0205C444
void WritePoke1LevelBits(DataSerializer* a1, struct unkPokeSubStruct_C* unkC)
{
    WriteBits(a1, &unkC->level, 7);
}

// arm9.bin::0205C414
void ReadHiddenPowerBits(DataSerializer* a1, HiddenPower* a2)
{
    ReadBits(a1, &a2->hiddenPowerBasePower, 10);
    ReadBits(a1, &a2->hiddenPowerType, 5);
}

// arm9.bin::0205C3E4
void WriteHiddenPowerBits(DataSerializer* a1, HiddenPower* a2)
{
    WriteBits(a1, &a2->hiddenPowerBasePower, 10);
    WriteBits(a1, &a2->hiddenPowerType, 5);
}
