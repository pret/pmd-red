#ifndef GUARD_FILE_SYSTEM_H
#define GUARD_FILE_SYSTEM_H

// size: 0x8
typedef struct File
{
    /* 0x0 */ char *name;
    /* 0x4 */ u8 *data;
} File;

// size: 0x8
typedef struct OpenedFile
{
    /* 0x0 */ File *file;
    /* 0x4 */ u8 *data;
} OpenedFile;

// size: 0x10
typedef struct FileArchive
{
    /* 0x0 */ char magic[8];
    /* 0x8 */ s32 count;
    /* 0xC */ File *entries;
} FileArchive;

// size: 0x8
typedef struct SiroArchive
{
    /* 0x0 */ u32 magic;
    /* 0x4 */ u8 *data;
} SiroArchive;

// size: 0x8
typedef struct UnkFileStruct
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} UnkFileStruct;

OpenedFile *Call_OpenFileAndGetFileDataPtr(const u8 *, const FileArchive *);
void CloseFile(OpenedFile *);
u8 *GetFileDataPtr(OpenedFile *, s32);
void InitFileSystem(void);
OpenedFile *OpenFile(const u8 *, const FileArchive *);
OpenedFile *OpenFileAndGetFileDataPtr(const u8 *, const FileArchive *);

u32 sub_800A8F8(u32);

#endif //GUARD_FILE_SYSTEM_H
