#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern u32 *gRecruitedPokemonRef;
extern u32 gRecruitedPokemon;
extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
extern struct OpenedFile *gMonsterParametersFile;
extern u16 gLevelCurrentPokeId;
extern struct gPokemon *gMonsterParameters;

void LoadMonsterParameters(void)
{
    gRecruitedPokemonRef = &gRecruitedPokemon;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gSystemFileArchive);
    gMonsterParameters = (struct gPokemon *)gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

u32 *sub_808CE00(void)
{
    return &gRecruitedPokemon;
}

