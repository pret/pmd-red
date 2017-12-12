#include "global.h"

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

extern struct OpenedFile gUnknown_202D2A8[];

extern u32 gUnknown_203B094;
extern u32 gUnknown_202D2A4;

extern int sprintf(char *, const char *, ...);

u8 *GetSiroPtr(struct OpenedFile *);

void InitFileSystem(void)
{
    s32 i;

    for (i = 0; i < 64; i++)
    {
        gUnknown_202D2A8[i].file = NULL;
        gUnknown_202D2A8[i].data = NULL;
    }

    gUnknown_203B094 = 0;
    gUnknown_202D2A4 = 1;
}

u32 sub_800A8F8(u32 value)
{
    u32 oldValue = gUnknown_202D2A4;
    gUnknown_202D2A4 = value;
    return oldValue;
}

struct OpenedFile *OpenFile(char *filename, struct FileArchive *arc)
{
    char buffer[0x12C];
    s32 left, right;
    s32 cursor;
    s32 i;
    s32 magic = 0;
    s32 magicFound;
    struct File *entries;
    struct File *file;

    magic = strcmp(arc->magic, "pksdir0") != 0;

    magicFound = 0;

    if (!(u8)magic)
        magicFound = 1;

    if (!magicFound)
        return NULL;

    entries = arc->entries;
    left = 0;
    right = arc->count - 1;

    while (left < right)
    {
        s32 mid = (left + right) / 2;
        int result = strcmp(entries[mid].name, filename);
        if (result == 0)
        {
            left = mid;
            break;
        }
        else if (result < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    file = &entries[left];

    if (strcmp(file->name, filename))
    {
        sprintf(buffer, "not find file [%s]\n", filename);
        return NULL;
    }

    cursor = gUnknown_203B094;

    for (i = 0; i < 64; i++)
    {
        cursor++;
        if (cursor > 63)
            cursor = 0;
        if (!gUnknown_202D2A8[cursor].file)
        {
            gUnknown_202D2A8[cursor].file = file;
            gUnknown_202D2A8[cursor].data = NULL;
            return &gUnknown_202D2A8[cursor];
        }
    }

    return NULL;
}

static u8 *_GetFileDataPtr(struct OpenedFile *openedFile)
{
    openedFile->data = openedFile->file->data;
    return openedFile->data;
}

u8 *GetFileDataPtr(struct OpenedFile *openedFile, int unused)
{
    _GetFileDataPtr(openedFile);
    return GetSiroPtr(openedFile);
}

struct OpenedFile *OpenFileAndGetFileDataPtr(char *filename, struct FileArchive *arc)
{
    struct OpenedFile *openedFile = OpenFile(filename, arc);
    if (openedFile)
        GetFileDataPtr(openedFile, 0);
    return openedFile;
}

struct OpenedFile *Call_OpenFileAndGetFileDataPtr(char *filename, struct FileArchive *arc)
{
    return OpenFileAndGetFileDataPtr(filename, arc);
}
