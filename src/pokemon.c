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

  for(iVar3 = 0; iVar3 < 4; iVar3++)
  {
    gRecruitedPokemonRef->team[iVar3].speciesNum = 0;
    gRecruitedPokemonRef->team[iVar3].unk0 = 0;
  }
}
