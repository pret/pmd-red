#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "constants/species.h"

extern struct unkStruct_203B45C gRecruitedPokemon[];
extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
extern struct OpenedFile *gMonsterParametersFile;
extern u16 gLevelCurrentPokeId;
extern struct gPokemon *gMonsterParameters;
extern struct unkStruct_203B45C *gRecruitedPokemonRef;

void LoadMonsterParameters(void)
{
    gRecruitedPokemonRef = gRecruitedPokemon;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gSystemFileArchive);
    gMonsterParameters = (struct gPokemon *)gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

struct unkStruct_203B45C *GetRecruitedPokemon(void)
{
    return gRecruitedPokemon;
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
    gRecruitedPokemonRef->pokemon3[iVar3].unk8 = 0;
    gRecruitedPokemonRef->pokemon3[iVar3].unk0 = 0;
  }
}
