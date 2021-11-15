#include "global.h"
#include "pokemon.h"
#include "file_system.h"


extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
EWRAM_DATA struct gPokemon *gMonsterParameters;
EWRAM_DATA struct OpenedFile *gMonsterParametersFile;
EWRAM_DATA struct unkStruct_203B45C gRecruitedPokemon;
extern struct unkStruct_203B45C *gRecruitedPokemonRef;
EWRAM_DATA u16 gLevelCurrentPokeId;


void LoadMonsterParameters(void)
{
    gRecruitedPokemonRef = &gRecruitedPokemon;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gSystemFileArchive);
    gMonsterParameters = (struct gPokemon *)gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

struct unkStruct_203B45C *GetRecruitedPokemon(void)
{
    return &gRecruitedPokemon;
}

void InitializeRecruitedPokemon(void)
{
  s32 iVar3;
  
  for(iVar3 = 0; iVar3 < NUM_SPECIES; iVar3++)
  {
    gRecruitedPokemonRef->pokemon[iVar3].unk0 = 0;
  }

  for(iVar3 = 0; iVar3 < 4; iVar3++)
  {
    gRecruitedPokemonRef->pokemon2[iVar3].unk0 = 0;
  }

  for(iVar3 = 0; iVar3 < MAX_TEAM_MEMBERS; iVar3++)
  {
    gRecruitedPokemonRef->team[iVar3].speciesNum = 0;
    gRecruitedPokemonRef->team[iVar3].unk0 = 0;
  }
}

// void sub_808CE74(s32 _species, u8 a2, u8* a3)  
// {
//     struct PokemonStruct pokemon;
//     u8 name_buffer[20];
//     u8 friend_area;
//     s32 i;
//     register s16 species asm("r7") = (s16)_species;
//     s32 cond = a2 << 24;

//     pokemon.unk0 = 3;
//     if (cond) {
//         pokemon.unk2 = 1;
//         pokemon.unk4.unk4 = 64;
//     }
//     else {
//         pokemon.unk2 = 1;
//         pokemon.unk4.unk4 = 65;
//     }
//     pokemon.unkHasNextStage = 1;
//     pokemon.pokeHP = GetBaseHP(species);
//     pokemon.offense.att[0] = GetPokemonAttSpatt(species, 0);
//     pokemon.offense.att[1] = GetPokemonAttSpatt(species, 1);
//     pokemon.offense.def[0] = GetPokemonDefSpdef(species, 0);
//     pokemon.offense.def[1] = GetPokemonDefSpdef(species, 1);
//     pokemon.IQ = 1;
//     pokemon.unkC[0].unk0 = 0;
//     pokemon.unkC[1].unk0 = 0;
//     SetDefaultIQSkills((u8*)&pokemon.IQSkills, 0);
//     pokemon.speciesNum = species;
//     pokemon.heldItem.itemIndex = 0;
//     pokemon.heldItem.numItems = 0;
//     pokemon.unk1C = 0;
//     pokemon.unk24 = 0;
//     pokemon.unk4.unk5 = 0;
//     sub_808E490(pokemon.moves, species);

//     // mostly incorrect below this:
//     if (!a3) {
//         CopySpeciesNametoBuffer(name_buffer, species);
//         BoundedCopyStringtoBuffer(pokemon.name, name_buffer, 10);
//     }
//     else {
//         s32 j;
//         for (j = 0; j < 10; j++) {
//             pokemon.name[j] = a3[j];
//         }
//     }
//     friend_area = gMonsterParameters[species].friend_area;
//     for (i = 0; i < 413; i++) {
//         if (!((u8)gRecruitedPokemonRef->pokemon[i].unk0 & 1)) {
//             u8 species_friend_area = sub_80923D4(i);
//             if (species_friend_area == friend_area) {
//                 gRecruitedPokemonRef->pokemon[i] = pokemon;
//                 gFriendAreas[species_friend_area] = 1;
//                 sub_80980B4(species);
//                 break;
//             }
//         }
//     }  
// }
