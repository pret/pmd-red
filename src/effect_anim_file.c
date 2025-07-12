#include "global.h"
#include "globaldata.h"
#include "file_system.h"
#include "def_filearchives.h"

OpenedFile *OpenEffectFile(u32 animType, s32 effectID)
{
    u8 fileName[8];

    switch (animType) {
        case 1:
        case 2:
        case 3:
            sprintf(fileName,"efob%03d",effectID);
            break;
        case 4:
            sprintf(fileName,"efbg%03d",effectID);
            break;

    }
    return Call_OpenFileAndGetFileDataPtr(fileName,&gEffectFileArchive);
}

void CloseEffectFile(OpenedFile *file)
{
    CloseFile(file);
}
