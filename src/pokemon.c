#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "pokemon_3.h"
#include "text_util.h"
#include "moves.h"


extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
EWRAM_DATA MonsterDataEntry *gMonsterParameters;
EWRAM_DATA OpenedFile *gMonsterParametersFile;
EWRAM_DATA unkStruct_203B45C gRecruitedPokemon;
EWRAM_DATA u16 gLevelCurrentPokeId;

EWRAM_DATA_2 unkStruct_203B45C *gRecruitedPokemonRef = {0};
extern void sub_808E490(Move* a1, s32 species);


void LoadMonsterParameters(void)
{
    gRecruitedPokemonRef = &gRecruitedPokemon;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gSystemFileArchive);
    gMonsterParameters = (MonsterDataEntry *)gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

unkStruct_203B45C *GetRecruitedPokemon(void)
{
    return &gRecruitedPokemon;
}

void InitializeRecruitedPokemon(void)
{
  s32 index;

  for(index = 0; index < NUM_MONSTERS; index++)
  {
    gRecruitedPokemonRef->pokemon[index].unk0 = 0;
  }

  for(index = 0; index < 4; index++)
  {
    gRecruitedPokemonRef->pokemon2[index].unk0 = 0;
  }

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    gRecruitedPokemonRef->team[index].speciesNum = 0;
    gRecruitedPokemonRef->team[index].unk0 = 0;
  }
}

// https://decomp.me/scratch/wQbZB

NAKED
void sub_808CE74(s16 species, bool8 isLeader, u8 *name)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r10\n"
	"\tmov r6, r9\n"
	"\tmov r5, r8\n"
	"\tpush {r5-r7}\n"
	"\tsub sp, 0x6C\n"
	"\tmov r8, r2\n"
	"\tlsls r0, 16\n"
	"\tasrs r7, r0, 16\n"
	"\tlsls r1, 24\n"
	"\tmov r2, sp\n"
	"\tmovs r0, 0x3\n"
	"\tstrh r0, [r2]\n"
	"\tcmp r1, 0\n"
	"\tbeq _0808CE9C\n"
	"\tmov r1, sp\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tmovs r0, 0x40\n"
	"\tb _0808CEA4\n"
"_0808CE9C:\n"
	"\tmov r1, sp\n"
	"\tmovs r0, 0\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tmovs r0, 0x41\n"
"_0808CEA4:\n"
	"\tstrb r0, [r1, 0x4]\n"
	"\tmov r0, sp\n"
	"\tmovs r6, 0\n"
	"\tmovs r5, 0x1\n"
	"\tstrb r5, [r0, 0x3]\n"
	"\tadds r0, r7, 0\n"
	"\tbl GetBaseHP\n"
	"\tmov r1, sp\n"
	"\tmovs r4, 0\n"
	"\tstrh r0, [r1, 0x16]\n"
	"\tadds r0, r7, 0\n"
	"\tmovs r1, 0\n"
	"\tbl GetBaseOffensiveStat\n"
	"\tmov r1, sp\n"
	"\tstrb r0, [r1, 0x18]\n"
	"\tadds r0, r7, 0\n"
	"\tmovs r1, 0x1\n"
	"\tbl GetBaseOffensiveStat\n"
	"\tmov r1, sp\n"
	"\tstrb r0, [r1, 0x19]\n"
	"\tadds r0, r7, 0\n"
	"\tmovs r1, 0\n"
	"\tbl GetBaseDefensiveStat\n"
	"\tmov r1, sp\n"
	"\tstrb r0, [r1, 0x1A]\n"
	"\tadds r0, r7, 0\n"
	"\tmovs r1, 0x1\n"
	"\tbl GetBaseDefensiveStat\n"
	"\tmov r1, sp\n"
	"\tstrb r0, [r1, 0x1B]\n"
	"\tmov r0, sp\n"
	"\tstrh r5, [r0, 0x14]\n"
	"\tstrb r4, [r0, 0xC]\n"
	"\tstrb r4, [r0, 0x10]\n"
	"\tadd r0, sp, 0x20\n"
	"\tmovs r1, 0\n"
	"\tbl SetDefaultIQSkills\n"
	"\tmov r0, sp\n"
	"\tstrh r7, [r0, 0x8]\n"
	"\tadd r0, sp, 0x28\n"
	"\tstrb r4, [r0]\n"
	"\tadds r0, 0x1\n"
	"\tstrb r4, [r0]\n"
	"\tstr r6, [sp, 0x1C]\n"
	"\tadd r0, sp, 0x24\n"
	"\tstrb r4, [r0]\n"
	"\tmov r0, sp\n"
	"\tstrb r4, [r0, 0x5]\n"
	"\tadd r0, sp, 0x2C\n"
	"\tadds r1, r7, 0\n"
	"\tbl sub_808E490\n"
	"\tmov r0, r8\n"
	"\tcmp r0, 0\n"
	"\tbne _0808CF5C\n"
	"\tadd r4, sp, 0x58\n"
	"\tadds r0, r4, 0\n"
	"\tadds r1, r7, 0\n"
	"\tbl CopyMonsterNameToBuffer\n"
	"\tadd r0, sp, 0x4C\n"
	"\tadds r1, r4, 0\n"
	"\tmovs r2, 0xA\n"
	"\tbl BoundedCopyStringtoBuffer\n"
	"\tlsls r4, r7, 3\n"
	"\tb _0808CF72\n"
"_0808CF36:\n"
	"\tmov r1, r8\n"
	"\tldr r0, [r1]\n"
	"\tadds r0, r6\n"
	"\tmov r1, sp\n"
	"\tmovs r2, 0x58\n"
	"\tbl memcpy\n"
	"\tldr r0, _0808CF58\n"
	"\tldr r0, [r0]\n"
	"\tadds r0, r4\n"
	"\tmov r5, r9\n"
	"\tstrb r5, [r0]\n"
	"\tadds r0, r7, 0\n"
	"\tbl sub_80980B4\n"
	"\tb _0808CFB8\n"
	"\t.align 2, 0\n"
"_0808CF58: .4byte gFriendAreas\n"
"_0808CF5C:\n"
	"\tmovs r2, 0\n"
	"\tlsls r4, r7, 3\n"
	"\tadd r3, sp, 0x4C\n"
"_0808CF62:\n"
	"\tadds r0, r3, r2\n"
	"\tmov r5, r8\n"
	"\tadds r1, r5, r2\n"
	"\tldrb r1, [r1]\n"
	"\tstrb r1, [r0]\n"
	"\tadds r2, 0x1\n"
	"\tcmp r2, 0x9\n"
	"\tble _0808CF62\n"
"_0808CF72:\n"
	"\tldr r0, _0808CFC8\n"
	"\tldr r1, [r0]\n"
	"\tadds r0, r4, r7\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tldrb r0, [r0, 0x16]\n"
	"\tmov r10, r0\n"
	"\tmovs r5, 0\n"
	"\tldr r0, _0808CFCC\n"
	"\tmov r8, r0\n"
	"\tmovs r1, 0x1\n"
	"\tmov r9, r1\n"
"_0808CF8A:\n"
	"\tmovs r0, 0x58\n"
	"\tadds r6, r5, 0\n"
	"\tmuls r6, r0\n"
	"\tmov r1, r8\n"
	"\tldr r0, [r1]\n"
	"\tadds r0, r6, r0\n"
	"\tldrb r1, [r0]\n"
	"\tmov r0, r9\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbne _0808CFAE\n"
	"\tadds r0, r5, 0\n"
	"\tbl sub_80923D4\n"
	"\tlsls r0, 24\n"
	"\tlsrs r4, r0, 24\n"
	"\tcmp r4, r10\n"
	"\tbeq _0808CF36\n"
"_0808CFAE:\n"
	"\tadds r5, 0x1\n"
	"\tmovs r0, 0xCE\n"
	"\tlsls r0, 1\n"
	"\tcmp r5, r0\n"
	"\tble _0808CF8A\n"
"_0808CFB8:\n"
	"\tadd sp, 0x6C\n"
	"\tpop {r3-r5}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tmov r10, r5\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808CFC8: .4byte gMonsterParameters\n"
"_0808CFCC: .4byte gRecruitedPokemonRef");
}

void sub_808CFD0(PokemonStruct1 *pokemon, s16 _species, u8* name, u32 _itemID, DungeonLocation *location, u16 *moveID)
{
    u8 name_buffer[20];
    s32 i;

    s32 species = _species;
    u8 itemID = _itemID;

    pokemon->unk0 = 1;
    pokemon->isTeamLeader = 0;
    pokemon->level = 1;
    pokemon->pokeHP = GetBaseHP(species);
    pokemon->offense.att[0] = GetBaseOffensiveStat(species, 0);
    pokemon->offense.att[1] = GetBaseOffensiveStat(species, 1);
    pokemon->offense.def[0] = GetBaseDefensiveStat(species, 0);
    pokemon->offense.def[1] = GetBaseDefensiveStat(species, 1);
    pokemon->speciesNum = species;
    xxx_init_helditem_8090B08(&pokemon->heldItem, itemID);
    pokemon->currExp = 0;
    pokemon->tacticIndex = 0;
    pokemon->IQ = 1;
    pokemon->dungeonLocation = *location;
    pokemon->unkC[0].level = 0;
    pokemon->unkC[1].level = 0;
    SetDefaultIQSkills((u8*)&pokemon->IQSkills, FALSE);

    if(moveID != NULL)
    {
        for(i = 0; i < MAX_MON_MOVES; i++)
        {
            if(moveID[i] != 0)
            {
                InitZeroedPPPokemonMove(&pokemon->moves[i], moveID[i]);
            }
            else
            {
                pokemon->moves[i].moveFlags = 0;
            }
        }
    }
    else
    {
        sub_808E490(pokemon->moves, species);
    }

    if (name == NULL) {
        // HACK
        register u8 *buffer asm("r0") = name_buffer;
        CopyMonsterNameToBuffer(buffer, species);
        BoundedCopyStringtoBuffer(pokemon->name, name_buffer, POKEMON_NAME_LENGTH);
    }
    else {
        s32 j;
        for (j = 0; j < POKEMON_NAME_LENGTH; j++) {
            pokemon->name[j] = name[j];
        }
    }
}

void sub_808D0D8(PokemonStruct1 *pokemon)
{
     pokemon->level = 1;
     pokemon->pokeHP = GetBaseHP(pokemon->speciesNum);
     pokemon->offense.att[0] = GetBaseOffensiveStat(pokemon->speciesNum, 0);
     pokemon->offense.att[1] = GetBaseOffensiveStat(pokemon->speciesNum, 1);
     pokemon->offense.def[0] = GetBaseDefensiveStat(pokemon->speciesNum, 0);
     pokemon->offense.def[1] = GetBaseDefensiveStat(pokemon->speciesNum, 1);
     pokemon->currExp = 0;
     pokemon->tacticIndex = 0;
     pokemon->IQ = 1;
     SetDefaultIQSkills((u8*)&pokemon->IQSkills, FALSE);
     sub_808E490(pokemon->moves, pokemon->speciesNum);
}

struct unkStruct_808D144
{
    /* 0x0 */ u8 *name;
    /* 0x4 */ s16 speciesNum;
    /* 0x6 */ u8 itemID;
    /* 0x8 */ struct DungeonLocation dungeonLocation;
    /* 0xC */ u16 moveID[MAX_MON_MOVES];
    /* 0x14 */ s16 pokeHP;
    /* 0x16 */ u16 level;
    /* 0x18 */ u16 IQ;
    s16 offense[4]; // atk, spatt, def, spdef (not sure why s16/u16 and not u8)
    /* 0x24 */ u32 currExp;
};

void sub_808D144(PokemonStruct1 *pokemon, struct unkStruct_808D144 *r1)
{
    s32 i;

    pokemon->unk0 = 1;
    pokemon->isTeamLeader = FALSE;
    pokemon->level = r1->level;
    pokemon->pokeHP = r1->pokeHP;
    pokemon->offense.att[0] = r1->offense[0];
    pokemon->offense.att[1] = r1->offense[1];
    pokemon->offense.def[0] = r1->offense[2];
    pokemon->offense.def[1] = r1->offense[3];
    pokemon->speciesNum = r1->speciesNum;
    xxx_init_helditem_8090B08(&pokemon->heldItem, r1->itemID);
    pokemon->currExp = r1->currExp;
    pokemon->tacticIndex = 0;
    pokemon->IQ = r1->IQ;
    pokemon->dungeonLocation = r1->dungeonLocation;
    pokemon->unkC[0].level = 0;
    pokemon->unkC[1].level = 0;
    SetDefaultIQSkills((u8*)&pokemon->IQSkills, FALSE);

    for(i = 0; i < MAX_MON_MOVES; i++)
    {
        if(r1->moveID[i] != 0)
        {
            InitZeroedPPPokemonMove(&pokemon->moves[i], r1->moveID[i]);
        }
        else
        {
            pokemon->moves[i].moveFlags = 0;
        }
    }

    for(i = 0; i < POKEMON_NAME_LENGTH; i++)
    {
        pokemon->name[i] = r1->name[i];
    }
}

