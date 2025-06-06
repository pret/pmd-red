#ifndef GUARD_FILE_SYSTEM_H
#define GUARD_FILE_SYSTEM_H

#include "structs/str_file_system.h"

OpenedFile *Call_OpenFileAndGetFileDataPtr(const u8 *filename, const FileArchive *arc);
void CloseFile(OpenedFile *openedFile);
const u8 *GetFileDataPtr(OpenedFile *openedFile, s32 unused);
void InitFileSystem(void);
OpenedFile *OpenFile(const u8 *filename, const FileArchive *arc);
OpenedFile *OpenFileAndGetFileDataPtr(const u8 *filename, const FileArchive *arc);

u32 sub_800A8F8(u32 value);

#define CLOSE_FILE_AND_SET_NULL(filePtr)    \
{                                           \
    CloseFile(filePtr);                     \
    filePtr = NULL;                         \
}

#define TRY_CLOSE_FILE_AND_SET_NULL(filePtr) if (filePtr != NULL) CLOSE_FILE_AND_SET_NULL(filePtr)

#endif //GUARD_FILE_SYSTEM_H
