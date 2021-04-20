#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern u32 *gUnknown_203B45C;
extern u32 gUnknown_202F400;
extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
extern struct OpenedFile *gMonsterParametersFile;
extern u16 gLevelCurrentPokeId;
extern struct gPokemon *gMonsterParameters;

void LoadMonsterParameters(void)
{
    gUnknown_203B45C = &gUnknown_202F400;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gSystemFileArchive);
    gMonsterParameters = (struct gPokemon *)gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

u32 *sub_808CE00(void)
{
    return &gUnknown_202F400;
}

