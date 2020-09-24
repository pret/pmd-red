#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern u32 *gUnknown_203B45C;
extern u32 gUnknown_202F400;
extern struct FileArchive gUnknown_8300500;
extern const char gUnknown_81075F4;
extern struct OpenedFile *gMonsterParametersFile;
extern u16 gUnknown_20384E8;
extern struct gPokemon gMonsterParameters;

void LoadMonsterParameters(void)
{
    gUnknown_203B45C = &gUnknown_202F400;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gUnknown_8300500);
    gMonsterParameters.unk0 = gMonsterParametersFile->data;
    gUnknown_20384E8 = 0;
}

u32 *sub_808CE00(void)
{
    return &gUnknown_202F400;

}
