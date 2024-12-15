#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "pokemon_3.h"
#include "text_util.h"
#include "moves.h"
#include "friend_area.h"
#include "exclusive_pokemon.h"

extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
EWRAM_DATA MonsterDataEntry *gMonsterParameters;
EWRAM_DATA OpenedFile *gMonsterParametersFile;
EWRAM_DATA unkStruct_203B45C gRecruitedPokemon;
EWRAM_DATA u16 gLevelCurrentPokeId;

EWRAM_INIT unkStruct_203B45C *gRecruitedPokemonRef = {NULL};
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

void sub_808CE74(s16 _species, bool32 _isLeader, u8* name)
{
     struct PokemonStruct1 pokemon;
     u8 name_buffer[20];
     u32 friendArea;
     s32 i;
     s32 species = _species;
     bool8 isLeader = _isLeader;

     pokemon.unk0 = 3;
     if (isLeader) {
         pokemon.isTeamLeader = TRUE;
         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_LEADER;
     }
     else {
         pokemon.isTeamLeader = FALSE;
         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_PARTNER;
     }
     pokemon.level = 1;
     pokemon.pokeHP = GetBaseHP(species);
     pokemon.offense.att[0] = GetBaseOffensiveStat(species, 0);
     pokemon.offense.att[1] = GetBaseOffensiveStat(species, 1);
     pokemon.offense.def[0] = GetBaseDefensiveStat(species, 0);
     pokemon.offense.def[1] = GetBaseDefensiveStat(species, 1);
     pokemon.IQ = 1;
     pokemon.unkC[0].level = 0;
     pokemon.unkC[1].level = 0;
     SetDefaultIQSkills(&pokemon.IQSkills, FALSE);
     pokemon.speciesNum = species;
     pokemon.heldItem.id = ITEM_NOTHING;
     pokemon.heldItem.quantity = 0;
     pokemon.currExp = 0;
     pokemon.tacticIndex = 0; // TACTIC_LETS_GO_TOGETHER
     pokemon.dungeonLocation.floor = 0;
     sub_808E490(pokemon.moves, species);

     if (name == NULL) {
         CopyMonsterNameToBuffer(name_buffer, species);
         BoundedCopyStringtoBuffer(pokemon.name, name_buffer, POKEMON_NAME_LENGTH);
     }
     else {
         s32 j;
         for (j = 0; j < POKEMON_NAME_LENGTH; j++) {
             pokemon.name[j] = name[j];
         }
     }
     friendArea = gMonsterParameters[species].friendArea;
     for (i = 0; i < NUM_MONSTERS; i++) {
         if (!PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])) {
             u8 speciesFriendArea = sub_80923D4(i);
             if (speciesFriendArea == friendArea) {
                 gRecruitedPokemonRef->pokemon[i] = pokemon;
                 gFriendAreas[speciesFriendArea] = TRUE;
                 sub_80980B4(species);
                 break;
             }
         }
     }
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
    SetDefaultIQSkills(&pokemon->IQSkills, FALSE);

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
        CopyMonsterNameToBuffer(name_buffer, species);
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
     SetDefaultIQSkills(&pokemon->IQSkills, FALSE);
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
    SetDefaultIQSkills(&pokemon->IQSkills, FALSE);

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

