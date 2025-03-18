#ifndef GUARD_STR_FILE_SYSTEM_H
#define GUARD_STR_FILE_SYSTEM_H

// size: 0x8
typedef struct File
{
    /* 0x0 */ char *name;
    /* 0x4 */ const void *data;
} File;

// size: 0x10
typedef struct FileArchive
{
    /* 0x0 */ char magic[8];
    /* 0x8 */ s32 count;
    /* 0xC */ const File *entries;
} FileArchive;

// size: 0x8
typedef struct OpenedFile
{
    /* 0x0 */ const File *file;
    /* 0x4 */ const void *data;
} OpenedFile;

#endif // GUARD_STR_FILE_SYSTEM_H
