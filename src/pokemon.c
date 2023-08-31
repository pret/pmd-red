#include "global.h"
#include "pokemon.h"
#include "file_system.h"


extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
EWRAM_DATA struct MonsterDataEntry *gMonsterParameters;
EWRAM_DATA struct OpenedFile *gMonsterParametersFile;
EWRAM_DATA struct unkStruct_203B45C gRecruitedPokemon;
EWRAM_DATA u16 gLevelCurrentPokeId;

EWRAM_DATA_2 struct unkStruct_203B45C *gRecruitedPokemonRef = {0};


void LoadMonsterParameters(void)
{
    gRecruitedPokemonRef = &gRecruitedPokemon;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gSystemFileArchive);
    gMonsterParameters = (struct MonsterDataEntry *)gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

struct unkStruct_203B45C *GetRecruitedPokemon(void)
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
 // void sub_808CE74(s16 _species, bool8 _isLeader, u8* name)  
 // {
 //     struct PokemonStruct pokemon;
 //     struct PokemonStruct *temp;
 //     u8 name_buffer[20];
 //     u32 friendArea;
 //     s32 i;
 //     s32 species = _species;
 //     bool32 isLeader = _isLeader << 24;
 //
 //     pokemon.unk0 = 3;
 //     if (isLeader) {
 //         pokemon.isTeamLeader = TRUE;
 //         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_LEADER; 
 //     }
 //     else {
 //         pokemon.isTeamLeader = FALSE;
 //         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_PARTNER;
 //     }
 //     pokemon.level = 1;
 //     pokemon.pokeHP = GetBaseHP(species);
 //     pokemon.offense.att[0] = GetBaseOffensiveStat(species, 0);
 //     pokemon.offense.att[1] = GetBaseOffensiveStat(species, 1);
 //     pokemon.offense.def[0] = GetBaseDefensiveStat(species, 0);
 //     pokemon.offense.def[1] = GetBaseDefensiveStat(species, 1);
 //     pokemon.IQ = 1;
 //     pokemon.unkC[0].level = 0;
 //     pokemon.unkC[1].level = 0;
 //     SetDefaultIQSkills((u8*)&pokemon.IQSkills, FALSE);
 //     pokemon.speciesNum = species;
 //     pokemon.heldItem.id = ITEM_NOTHING;
 //     pokemon.heldItem.quantity = 0;
 //     pokemon.currExp = 0;
 //     pokemon.tacticIndex = 0; // TACTIC_LETS_GO_TOGETHER
 //     pokemon.dungeonLocation.floor = 0;
 //     sub_808E490(pokemon.moves, species);
 //
 //     if (name == NULL) {
 //         CopyMonsterNametoBuffer(name_buffer, species);
 //         BoundedCopyStringtoBuffer(pokemon.name, name_buffer, POKEMON_NAME_LENGTH);
 //     }
 //     else {
 //         s32 j;
 //         for (j = 0; j < POKEMON_NAME_LENGTH; j++) {
 //             pokemon.name[j] = name[j];
 //         }
 //     }
 //     friendArea = gMonsterParameters[species].friendArea;
 //     for (i = 0; i < NUM_MONSTERS; i++) {
 //         temp = &gRecruitedPokemonRef->pokemon[i];
 //         if (!((u8)gRecruitedPokemonRef->pokemon[i].unk0 & 1)) {
 //             u8 speciesFriendArea = sub_80923D4(i);
 //             if (speciesFriendArea == friendArea) {
 //                 gRecruitedPokemonRef->pokemon[i] = pokemon;
 //                 gFriendAreas[speciesFriendArea] = TRUE;
 //                 sub_80980B4(species);
 //                 break;
 //             }
 //         }
 //     }  
 // }
