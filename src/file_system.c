#include "global.h"
#include "decompress.h"
#include "file_system.h"

EWRAM_DATA u32 gUnknown_202D2A4 = {0};
EWRAM_DATA OpenedFile gFileCache[64] = {0};

static EWRAM_DATA_2 u32 sFileCacheCursorPosition = {0};

#include "data/file_system.h"

// ???
extern s32 sprintf(char *, const char *, ...);

UNUSED static void sub_800A894(UnkFileStruct *r0, s32 r1)
{
    s32 temp;

    temp = r1;
    if (temp < 1)
        temp = 1;
    if (temp > 299)
        temp = 299;

    r0->unk4 = gUnknown_80B96E4[temp];
    r0->unk0 = 0;
}

void InitFileSystem(void)
{
    s32 i;

    for (i = 0; i < 64; i++) {
        gFileCache[i].file = NULL;
        gFileCache[i].data = NULL;
    }

    sFileCacheCursorPosition = 0;
    gUnknown_202D2A4 = 1;
}

u32 sub_800A8F8(u32 value)
{
    u32 oldValue = gUnknown_202D2A4;
    gUnknown_202D2A4 = value;
    return oldValue;
}

OpenedFile *OpenFile(const u8 *filename, const FileArchive *arc)
{
    u8 buffer[300];
    s32 left, right;
    s32 cursor;
    s32 i;
    u32 magic = 0;
    bool32 magicFound;
    File *entries;
    File *file;

    magic = strcmp(arc->magic, gUnknown_80B9B94) != 0;

    magicFound = 0;

    if (!(bool8)magic)
        magicFound = 1;

    if (!magicFound)
        return NULL;

    entries = arc->entries;
    left = 0;
    right = arc->count - 1;

    while (left < right) {
        s32 mid = (left + right) / 2;
        s32 result = strcmp(entries[mid].name, filename);
        if (result == 0) {
            left = mid;
            break;
        }

        if (result < 0)
            left = mid + 1;
        else
            right = mid;
    }

    file = &entries[left];

    if (strcmp(file->name, filename)) {
        sprintf(buffer, gUnknown_80B9B9C, filename);
        return NULL;
    }

    cursor = sFileCacheCursorPosition;

    for (i = 0; i < 64; i++) {
        cursor++;
        if (cursor > 63)
            cursor = 0;

        if (!gFileCache[cursor].file) {
            gFileCache[cursor].file = file;
            gFileCache[cursor].data = NULL;
            return &gFileCache[cursor];
        }
    }

    return NULL;
}

static u8 *_GetFileDataPtr(OpenedFile *openedFile)
{
    openedFile->data = openedFile->file->data;
    return openedFile->data;
}

u8 *GetFileDataPtr(OpenedFile *openedFile, s32 unused)
{
    _GetFileDataPtr(openedFile);
    return GetSiroPtr(openedFile);
}

OpenedFile *OpenFileAndGetFileDataPtr(const u8 *filename, const FileArchive *arc)
{
    OpenedFile *openedFile = OpenFile(filename, arc);
    if (openedFile)
        GetFileDataPtr(openedFile, 0);
    return openedFile;
}

OpenedFile *Call_OpenFileAndGetFileDataPtr(const u8 *filename, const FileArchive *arc)
{
    return OpenFileAndGetFileDataPtr(filename, arc);
}

void CloseFile(OpenedFile *openedFile)
{
    s32 i;

    for (i = 0; i < 64; i++) {
        if (&gFileCache[i] == openedFile) {
            gFileCache[i].file = NULL;
            gFileCache[i].data = NULL;
            sFileCacheCursorPosition = i;
            return;
        }
    }
}