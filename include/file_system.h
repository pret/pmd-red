#ifndef GUARD_FILE_SYSTEM_H
#define GUARD_FILE_SYSTEM_H

#include "structs/str_file_system.h"

enum FileSystemUnk
{
    FILESYSTEM_UNK_0,
    FILESYSTEM_UNK_1,
    FILESYSTEM_UNK_2,
    FILESYSTEM_UNK_3,
    FILESYSTEM_UNK_4,
};

OpenedFile *Call_OpenFileAndGetFileDataPtr(const u8 *filename, const FileArchive *arc);
void CloseFile(OpenedFile *openedFile);
const u8 *GetFileDataPtr(OpenedFile *openedFile, s32 unused);
void InitFileSystem(void);
OpenedFile *OpenFile(const u8 *filename, const FileArchive *arc);
OpenedFile *OpenFileAndGetFileDataPtr(const u8 *filename, const FileArchive *arc);
// value: See enum "FileSystemUnk"
// Return: See enum "FileSystemUnk"
u32 SetFileSystemUnk(u32 value);

#define CLOSE_FILE_AND_SET_NULL(filePtr)    \
{                                           \
    CloseFile(filePtr);                     \
    filePtr = NULL;                         \
}

#define TRY_CLOSE_FILE_AND_SET_NULL(filePtr) if (filePtr != NULL) CLOSE_FILE_AND_SET_NULL(filePtr)

#define TRY_CLOSE_FILE(filePtr) if (filePtr != NULL) CloseFile(filePtr)

#endif // GUARD_FILE_SYSTEM_H
