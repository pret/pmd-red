#include "global.h"
#include "file_system.h"

extern struct OpenedFile gFileCache[64];

extern u32 gFileCacheCursorPosition;
extern u32 gUnknown_202D2A4;

extern int sprintf(char *, const char *, ...);

u8 *GetSiroPtr(struct OpenedFile *);
void NDS_DecompressRLE(void *);

void InitFileSystem(void)
{
    s32 i;

    for (i = 0; i < 64; i++)
    {
        gFileCache[i].file = NULL;
        gFileCache[i].data = NULL;
    }

    gFileCacheCursorPosition = 0;
    gUnknown_202D2A4 = 1;
}

u32 sub_800A8F8(u32 value)
{
    u32 oldValue = gUnknown_202D2A4;
    gUnknown_202D2A4 = value;
    return oldValue;
}

struct OpenedFile *OpenFile(const char *filename, const struct FileArchive *arc)
{
    char buffer[0x12C];
    s32 left, right;
    s32 cursor;
    s32 i;
    u32 magic = 0;
    bool32 magicFound;
    struct File *entries;
    struct File *file;

    magic = strcmp(arc->magic, "pksdir0") != 0;

    magicFound = 0;

    if (!(bool8)magic)
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

    cursor = gFileCacheCursorPosition;

    for (i = 0; i < 64; i++)
    {
        cursor++;
        if (cursor > 63)
            cursor = 0;
        if (!gFileCache[cursor].file)
        {
            gFileCache[cursor].file = file;
            gFileCache[cursor].data = NULL;
            return &gFileCache[cursor];
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

struct OpenedFile *OpenFileAndGetFileDataPtr(const char *filename, const struct FileArchive *arc)
{
    struct OpenedFile *openedFile = OpenFile(filename, arc);
    if (openedFile)
        GetFileDataPtr(openedFile, 0);
    return openedFile;
}

struct OpenedFile *Call_OpenFileAndGetFileDataPtr(const char *filename, const struct FileArchive *arc)
{
    return OpenFileAndGetFileDataPtr(filename, arc);
}

void CloseFile(struct OpenedFile *openedFile)
{
    s32 i;

    for (i = 0; i < 64; i++)
    {
        if (&gFileCache[i] == openedFile)
        {
            gFileCache[i].file = NULL;
            gFileCache[i].data = NULL;
            gFileCacheCursorPosition = i;
            return;
        }
    }
}

u8 *GetSiroPtr(struct OpenedFile *openedFile)
{
    struct SiroArchive *siro = (struct SiroArchive *)openedFile->data;

    if (siro->magic == 0x30524953)
    {
        NDS_DecompressRLE(openedFile->data);
    }
    else if (siro->magic != 0x4F524953)
    {
        return openedFile->data;
    }

    openedFile->data = siro->data;

    return openedFile->data;
}

void *UnusedGetSir0Ptr(struct SiroArchive *siro)
{
    if (siro->magic != 0x30524953)
        return siro;

    NDS_DecompressRLE(siro);
    return siro->data;
}

void NDS_DecompressRLE(void *unused)
{
}
