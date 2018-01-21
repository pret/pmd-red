#ifndef GUARD_FILE_SYSTEM_H
#define GUARD_FILE_SYSTEM_H

struct File
{
    char *name;
    u8 *data;
};

struct OpenedFile
{
    struct File *file;
    u8 *data;
};

struct FileArchive
{
    char magic[8];
    s32 count;
    struct File *entries;
};

struct SiroArchive
{
    u32 magic;
    u8 *data;
};

struct OpenedFile *OpenFile(const char *filename, const struct FileArchive *arc);
u8 *GetFileDataPtr(struct OpenedFile *openedFile, int unused);
struct OpenedFile *OpenFileAndGetFileDataPtr(const char *filename, const struct FileArchive *arc);
struct OpenedFile *Call_OpenFileAndGetFileDataPtr(const char *filename, const struct FileArchive *arc);

#endif //GUARD_FILE_SYSTEM_H
