#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern u32 *gUnknown_203B45C;
extern u32 gUnknown_202F400;
extern struct FileArchive gSystemFileArchive;
extern const char gUnknown_81075F4;
extern struct OpenedFile *gMonsterParametersFile;
extern u16 gLevelCurrentPokeId;
extern struct gPokemon gMonsterParameters;

extern u64 gUnknown_8107544[];
extern u32 gUnknown_810697C;
extern void sub_8086448();
extern void sub_80866C4(u32 *r0);

void sub_808CD9C(u8 r0)
{
    sub_8086448();
    sub_80866C4(&gUnknown_810697C);
}

u64 *sub_808CDB0(u8 r0)
{
    return &gUnknown_8107544[r0];
}

void LoadMonsterParameters(void)
{
    gUnknown_203B45C = &gUnknown_202F400;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(&gUnknown_81075F4, &gSystemFileArchive);
    // TODO verify this... other parts imply this is an array
    gMonsterParameters.species = gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

u32 *sub_808CE00(void)
{
    return &gUnknown_202F400;

}

