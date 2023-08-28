#ifndef GUARD_FILE_SYSTEM_H
#define GUARD_FILE_SYSTEM_H

// size: 0x8
struct File
{
    /* 0x0 */ char *name;
    /* 0x4 */ u8 *data;
};

// size: 0x8
struct OpenedFile
{
    /* 0x0 */ struct File *file;
    /* 0x4 */ u8 *data;
};

// size: 0x10
struct FileArchive
{
    /* 0x0 */ char magic[8];
    /* 0x8 */ s32 count;
    /* 0xC */ struct File *entries;
};

// size: 0x8
struct SiroArchive
{
    /* 0x0 */ u32 magic;
    /* 0x4 */ u8 *data;
};

// size: 0x8
struct UnkFileStruct1
{
    u32 unk0;
    u32 unk4;
};

void InitFileSystem(void);
struct OpenedFile *OpenFile(const char *filename, const struct FileArchive *arc);
u8 *GetFileDataPtr(struct OpenedFile *openedFile, int unused);
struct OpenedFile *OpenFileAndGetFileDataPtr(const char *filename, const struct FileArchive *arc);
struct OpenedFile *Call_OpenFileAndGetFileDataPtr(const char *filename, const struct FileArchive *arc);
u32 DecompressATFile(char *result, s32 resultLength, struct OpenedFile *file);
void CloseFile(struct OpenedFile *openedFile);
u32 DecompressATGlobalFile(u32 *result, s32 resultLength, struct OpenedFile *file);

#endif //GUARD_FILE_SYSTEM_H
