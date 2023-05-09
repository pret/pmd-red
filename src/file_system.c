#include "global.h"
#include "file_system.h"

EWRAM_DATA u32 gUnknown_202D2A4 = {0};
EWRAM_DATA struct OpenedFile gFileCache[64] = {0};
EWRAM_DATA u32 *gDecompressBufferPtr = {0};
EWRAM_DATA u32 *gDecompressBufferStart = {0};
EWRAM_DATA u32 gDecompressBufferCurrent = {0};
EWRAM_DATA u32 gDecompressBufferByteInInt = {0};

EWRAM_DATA_2 u32 gFileCacheCursorPosition = {0};

extern const u32 gByteShiftLookup[4];


extern int sprintf(char *, const char *, ...);

void DecompressAT_Init(u32 *buffer);
void DecompressAT_AppendByte(char value);
void DecompressAT_Finish(void);
char DecompressAT_GetByte(int index);

u32 DecompressAT(char *result, s32 resultLength, const char *compressedData);
u32 DecompressATGlobal(u32 *result, s32 resultLength, const char *compressedData);
u8 *GetSiroPtr(struct OpenedFile *);
void NDS_DecompressRLE(void *);

struct UnkFileStruct
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
};

extern u32 gUnknown_80B96E4[];

void sub_800A894(struct UnkFileStruct *r0, s32 r1)
{
    s32 temp;
    temp = r1;
    if(r1 <= 0)
        temp = 1;
    if(temp > 299)
        temp = 299;
    r0->unk4 = gUnknown_80B96E4[temp];
    r0->unk0 = 0;
}

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

void nullsub_16(void)
{
}

void nullsub_175(void)
{
}

u32 DecompressATFile(char *result, s32 resultLength, struct OpenedFile *file)
{
    return DecompressAT(result, resultLength, file->data);
}

// 800AAB4
u32 DecompressAT(char *result, s32 resultLength, const char *compressedData)
{
    s32 compressedLength = compressedData[5] + (compressedData[6] << 8);
    s32 bytesWritten = 0;
    s32 currentByte = 0;
    s32 cmdBit = 8;
    s32 curIndex;
    s32 flags[9];
    s32 idxStart;

    if (compressedData[0] == 'A'
     && compressedData[1] == 'T'
     && compressedData[2] == '4'
     && compressedData[3] == 'P') {
        u32 tmp2 = compressedData[0x10] + (compressedData[0x11] << 8);
        if (resultLength != 0 && resultLength != tmp2)
            return 0;
        idxStart = 0x12;
    } else if (compressedData[0] == 'A'
            && compressedData[1] == 'T'
            && compressedData[2] == '3'
            && compressedData[3] == 'P') {
        idxStart = 0x10;
    } else {
        return 0;
    }

    if (compressedData[4] == 'N') {
        // uncompressed mode, unused
        for (curIndex = 0; curIndex < compressedLength; curIndex++) {
            result[curIndex] = compressedData[curIndex + 7];
        }
        return curIndex;
    }

    flags[0] = compressedData[0x7] + 3;
    flags[1] = compressedData[0x8] + 3;
    flags[2] = compressedData[0x9] + 3;
    flags[3] = compressedData[0xa] + 3;
    flags[4] = compressedData[0xb] + 3;
    flags[5] = compressedData[0xc] + 3;
    flags[6] = compressedData[0xd] + 3;
    flags[7] = compressedData[0xe] + 3;
    flags[8] = compressedData[0xf] + 3;

    curIndex = idxStart;
    if (curIndex < compressedLength) {

        do {
            if (resultLength != 0 && bytesWritten >= resultLength)
                return 0;

            if (cmdBit == 8) {
                currentByte = compressedData[curIndex++];
                cmdBit = 0;
            }
            if ((currentByte & 0x80) == 0) {
                // if bit is unset, process command
                u32 command = (compressedData[curIndex] >> 4) + 3;
                u32 tmp = (compressedData[curIndex] & 0xf) << 8;
                u32 c;

                if (command == flags[0]) command = 0x1f;
                if (command == flags[1]) command = 0x1e;
                if (command == flags[2]) command = 0x1d;
                if (command == flags[3]) command = 0x1c;
                if (command == flags[4]) command = 0x1b;
                if (command == flags[5]) command = 0x1a;
                if (command == flags[6]) command = 0x19;
                if (command == flags[7]) command = 0x18;
                if (command == flags[8]) command = 0x17;

                switch (command) {
                    case 0x1f: { // aaaa
                        c = compressedData[curIndex++] & 0xf;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x1e: { // abbb
                        u8 byte = compressedData[curIndex];
                        c = 0xF;
                        c = byte & c;
                        curIndex++;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf));
                        result[bytesWritten++] = ((((c + 1) & 0xf) << 4) | ((c + 1) & 0xf));
                        break;
                    }
                    case 0x1d: { // babb
                        c = compressedData[curIndex++] & 0xf;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf));
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x1c: { // bbab
                        c = compressedData[curIndex++] & 0xf;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        result[bytesWritten++] = ((((c - 1) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x1b: { // bbba
                        c = compressedData[curIndex++] & 0xf;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf));
                        break;
                    }
                    case 0x1a: { // baaa -- the horrible, hard-to-match case
                        u8 byte = compressedData[curIndex];
                        c = 0xF;
                        c = byte & c;
                        curIndex++;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf));
                        result[bytesWritten++] = ((((c - 1) & 0xf) << 4) | ((c - 1) & 0xf));
                        break;
                    }
                    case 0x19: { // abaa
                        c = compressedData[curIndex++] & 0xf;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf));
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x18: { // aaba
                        c = compressedData[curIndex++] & 0xf;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        result[bytesWritten++] = ((((c + 1) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x17: { // aaab
                        c = compressedData[curIndex++] & 0xf;
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        result[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf));
                        break;
                    }
                    default: {
                        tmp += (compressedData[curIndex++, curIndex++]);
                        tmp += bytesWritten - 0x1000;
                        for(;command;command--)
                        {
                            result[bytesWritten++] = result[tmp];
                            tmp++;
                        }
                    }
                }
            } else {
                // if bit is set, just copy next byte
                result[bytesWritten++] = (compressedData[curIndex]);
                curIndex++;
            }
            cmdBit++;
            currentByte <<= 1;
        } while (curIndex < compressedLength);
    }

    return bytesWritten;
}

u32 DecompressATGlobalFile(u32 *result, s32 resultLength, struct OpenedFile *file)
{
    return DecompressATGlobal(result, resultLength, file->data);
}

// 800AE34
#ifndef NONMATCHING
NAKED
#endif
u32 DecompressATGlobal(u32 *result, s32 resultLength, const char *compressedData)
{
#ifdef NONMATCHING
    s32 compressedLength;
    s32 curIndex;
    s32 bytesWritten;
    s32 cmdBit;
    s32 currentByte;
    s32 flags1;
    s32 flags2;
    s32 flags3;
    s32 flags4;
    s32 flags5;
    s32 flags6;
    s32 flags7;
    s32 flags8;
    s32 flags9;
    u32 command;
    u32 tmp;
    u32 tmp2;
    u32 c;

    compressedLength = compressedData[5] + (compressedData[6] << 8);
    bytesWritten = 0;
    currentByte = 0;
    cmdBit = 8;

    DecompressAT_Init(result);

    if (compressedData[0] == 'A'
     && compressedData[1] == 'T'
     && compressedData[2] == '4'
     && compressedData[3] == 'P') {
        tmp2 = compressedData[0x10] + (compressedData[0x11] << 8);
        if (resultLength != 0 && resultLength != tmp2)
            return bytesWritten;
        curIndex = 0x12;
    } else if (compressedData[0] == 'A'
            && compressedData[1] == 'T'
            && compressedData[2] == '3'
            && compressedData[3] == 'P') {
        curIndex = 0x10;
    } else {
        return 0;
    }

    if (compressedData[4] == 'N') {
        // uncompressed mode, unused
        for (bytesWritten = 0; bytesWritten < compressedLength; bytesWritten++) {
            DecompressAT_AppendByte(compressedData[bytesWritten + 7]);
        }
        DecompressAT_Finish();
        return bytesWritten;
    }

    flags1 = compressedData[0x7] + 3;
    flags2 = compressedData[0x8] + 3;
    flags3 = compressedData[0x9] + 3;
    flags4 = compressedData[0xa] + 3;
    flags5 = compressedData[0xb] + 3;
    flags6 = compressedData[0xc] + 3;
    flags7 = compressedData[0xd] + 3;
    flags8 = compressedData[0xe] + 3;
    flags9 = compressedData[0xf] + 3;

    if (curIndex < compressedLength) {

        do {
            if (resultLength != 0 && bytesWritten >= resultLength)
                return 0;

            if (cmdBit == 8) {
                currentByte = compressedData[curIndex++];
                cmdBit = 0;
            }
            if ((currentByte & 0x80) == 0) {
                // if bit is unset, process command
                command = (compressedData[curIndex] >> 4) + 3;
                tmp2 = (compressedData[curIndex] & 0xf) << 8;

                if (command == flags1) command = 0x1f;
                if (command == flags2) command = 0x1e;
                if (command == flags3) command = 0x1d;
                if (command == flags4) command = 0x1c;
                if (command == flags5) command = 0x1b;
                if (command == flags6) command = 0x1a;
                if (command == flags7) command = 0x19;
                if (command == flags8) command = 0x18;
                if (command == flags9) command = 0x17;

                switch (command) {
                    case 0x1f: { // aaaa
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x1e: { // abbb
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c + 1) & 0xf) << 4) | ((c + 1) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x1d: { // babb
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x1c: { // bbab
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c - 1) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x1b: { // bbba
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x1a: { // baaa -- the horrible, unmatching case
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf)); bytesWritten++;
                        c -= 1;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x19: { // abaa
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x18: { // aaba
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c + 1) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        break;
                    }
                    case 0x17: { // aaab
                        c = compressedData[curIndex++] & 0xf;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf)); bytesWritten++;
                        DecompressAT_AppendByte((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf)); bytesWritten++;
                        break;
                    }
                    default: {
                        tmp = compressedData[curIndex++, curIndex++] + tmp2 - 0x1000 + bytesWritten;
                        for (; command != 0; tmp++, command--) {
                            DecompressAT_AppendByte(DecompressAT_GetByte(tmp)); bytesWritten++;
                        }
                    }
                }
            } else {
                // if bit is set, just copy next byte
                DecompressAT_AppendByte(compressedData[curIndex]); bytesWritten++;
                curIndex++;
            }
            cmdBit++;
            currentByte <<= 1;
        } while (curIndex < compressedLength);
        DecompressAT_Finish();
    }

    return bytesWritten;
#else
    asm_unified(
        "DecompressATGlobal:\n"
        "  push {r4-r7,lr}\n"
        "  mov r7, r10\n"
        "  mov r6, r9\n"
        "  mov r5, r8\n"
        "  push {r5-r7}\n"
        "  sub sp, 0x34\n"
        "  str r1, [sp, 0x24]\n"
        "  mov r10, r2\n"
        "  ldrb r2, [r2, 0x5]\n"
        "  mov r3, r10\n"
        "  ldrb r1, [r3, 0x6]\n"
        "  lsls r1, 8\n"
        "  adds r2, r1\n"
        "  str r2, [sp, 0x28]\n"
        "  movs r1, 0\n"
        "  mov r9, r1\n"
        "  movs r2, 0\n"
        "  str r2, [sp, 0x2C]\n"
        "  movs r3, 0x8\n"
        "  str r3, [sp, 0x30]\n"
        "  bl DecompressAT_Init\n"
        "  mov r1, r10\n"
        "  ldrb r0, [r1]\n"
        "  cmp r0, 0x41\n"
        "  bne _0800AE90\n"
        "  ldrb r0, [r1, 0x1]\n"
        "  adds r1, r0, 0\n"
        "  cmp r1, 0x54\n"
        "  bne _0800AE98\n"
        "  mov r2, r10\n"
        "  ldrb r0, [r2, 0x2]\n"
        "  cmp r0, 0x34\n"
        "  bne _0800AE98\n"
        "  ldrb r0, [r2, 0x3]\n"
        "  cmp r0, 0x50\n"
        "  bne _0800AE98\n"
        "  ldrb r1, [r2, 0x10]\n"
        "  ldrb r0, [r2, 0x11]\n"
        "  lsls r0, 8\n"
        "  adds r1, r0\n"
        "  ldr r3, [sp, 0x24]\n"
        "  cmp r3, 0\n"
        "  beq _0800AE94\n"
        "  cmp r3, r1\n"
        "  beq _0800AE94\n"
        "_0800AE90:\n"
        "  movs r0, 0\n"
        "  b _0800B1AA\n"
        "_0800AE94:\n"
        "  movs r1, 0x12\n"
        "  b _0800AEB2\n"
        "_0800AE98:\n"
        "  mov r2, r10\n"
        "  ldrb r0, [r2]\n"
        "  cmp r0, 0x41\n"
        "  bne _0800AE90\n"
        "  cmp r1, 0x54\n"
        "  bne _0800AE90\n"
        "  ldrb r0, [r2, 0x2]\n"
        "  cmp r0, 0x33\n"
        "  bne _0800AE90\n"
        "  ldrb r0, [r2, 0x3]\n"
        "  cmp r0, 0x50\n"
        "  bne _0800AE90\n"
        "  movs r1, 0x10\n"
        "_0800AEB2:\n"
        "  mov r3, r10\n"
        "  ldrb r0, [r3, 0x4]\n"
        "  cmp r0, 0x4E\n"
        "  bne _0800AEE0\n"
        "  movs r0, 0\n"
        "  mov r8, r0\n"
        "  ldr r1, [sp, 0x28]\n"
        "  cmp r8, r1\n"
        "  bge _0800AED8\n"
        "_0800AEC4:\n"
        "  mov r0, r8\n"
        "  add r0, r10\n"
        "  ldrb r0, [r0, 0x7]\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  ldr r3, [sp, 0x28]\n"
        "  cmp r8, r3\n"
        "  blt _0800AEC4\n"
        "_0800AED8:\n"
        "  bl DecompressAT_Finish\n"
        "  mov r0, r8\n"
        "  b _0800B1AA\n"
        "_0800AEE0:\n"
        "  mov r2, r10\n"
        "  ldrb r0, [r2, 0x7]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp]\n"
        "  ldrb r0, [r2, 0x8]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0x4]\n"
        "  ldrb r0, [r2, 0x9]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0x8]\n"
        "  ldrb r0, [r2, 0xA]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0xC]\n"
        "  ldrb r0, [r2, 0xB]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0x10]\n"
        "  ldrb r0, [r2, 0xC]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0x14]\n"
        "  ldrb r0, [r2, 0xD]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0x18]\n"
        "  ldrb r0, [r2, 0xE]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0x1C]\n"
        "  ldrb r0, [r2, 0xF]\n"
        "  adds r0, 0x3\n"
        "  str r0, [sp, 0x20]\n"
        "  mov r8, r1\n"
        "  ldr r3, [sp, 0x28]\n"
        "  cmp r8, r3\n"
        "  blt _0800AF22\n"
        "  b _0800B1A4\n"
        "_0800AF22:\n"
        "  ldr r0, [sp, 0x24]\n"
        "  cmp r0, 0\n"
        "  beq _0800AF2C\n"
        "  cmp r9, r0\n"
        "  bge _0800AE90\n"
        "_0800AF2C:\n"
        "  ldr r1, [sp, 0x30]\n"
        "  cmp r1, 0x8\n"
        "  bne _0800AF42\n"
        "  mov r0, r10\n"
        "  add r0, r8\n"
        "  ldrb r0, [r0]\n"
        "  str r0, [sp, 0x2C]\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  movs r3, 0\n"
        "  str r3, [sp, 0x30]\n"
        "_0800AF42:\n"
        "  movs r0, 0x80\n"
        "  ldr r1, [sp, 0x2C]\n"
        "  ands r0, r1\n"
        "  cmp r0, 0\n"
        "  beq _0800AF4E\n"
        "  b _0800B180\n"
        "_0800AF4E:\n"
        "  mov r2, r10\n"
        "  add r2, r8\n"
        "  ldrb r1, [r2]\n"
        "  lsrs r0, r1, 4\n"
        "  adds r3, r0, 0x3\n"
        "  movs r0, 0xF\n"
        "  ands r0, r1\n"
        "  lsls r7, r0, 8\n"
        "  ldr r0, [sp]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF66\n"
        "  movs r3, 0x1F\n"
        "_0800AF66:\n"
        "  ldr r0, [sp, 0x4]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF6E\n"
        "  movs r3, 0x1E\n"
        "_0800AF6E:\n"
        "  ldr r0, [sp, 0x8]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF76\n"
        "  movs r3, 0x1D\n"
        "_0800AF76:\n"
        "  ldr r0, [sp, 0xC]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF7E\n"
        "  movs r3, 0x1C\n"
        "_0800AF7E:\n"
        "  ldr r0, [sp, 0x10]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF86\n"
        "  movs r3, 0x1B\n"
        "_0800AF86:\n"
        "  ldr r0, [sp, 0x14]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF8E\n"
        "  movs r3, 0x1A\n"
        "_0800AF8E:\n"
        "  ldr r0, [sp, 0x18]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF96\n"
        "  movs r3, 0x19\n"
        "_0800AF96:\n"
        "  ldr r0, [sp, 0x1C]\n"
        "  cmp r3, r0\n"
        "  bne _0800AF9E\n"
        "  movs r3, 0x18\n"
        "_0800AF9E:\n"
        "  ldr r0, [sp, 0x20]\n"
        "  cmp r3, r0\n"
        "  bne _0800AFA6\n"
        "  movs r3, 0x17\n"
        "_0800AFA6:\n"
        "  adds r0, r3, 0\n"
        "  subs r0, 0x17\n"
        "  cmp r0, 0x8\n"
        "  bls _0800AFB0\n"
        "  b _0800B13C\n"
        "_0800AFB0:\n"
        "  lsls r0, 2\n"
        "  ldr r1, _0800AFBC\n"
        "  adds r0, r1\n"
        "  ldr r0, [r0]\n"
        "  mov pc, r0\n"
        "  .align 2, 0\n"
        "_0800AFBC: .4byte _0800AFC0\n"
        "  .align 2, 0\n"
        "_0800AFC0:\n"
        "  .4byte _0800B104\n"
        "  .4byte _0800B0DE\n"
        "  .4byte _0800B0BA\n"
        "  .4byte _0800B090\n"
        "  .4byte _0800B06E\n"
        "  .4byte _0800B048\n"
        "  .4byte _0800B024\n"
        "  .4byte _0800AFFE\n"
        "  .4byte _0800AFE4\n"
        "_0800AFE4:\n"
        "  ldrb r0, [r2]\n"
        "  movs r1, 0xF\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  ands r1, r0\n"
        "  lsls r4, r1, 4\n"
        "  orrs r4, r1\n"
        "  adds r0, r4, 0\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  b _0800B128\n"
        "_0800AFFE:\n"
        "  ldrb r0, [r2]\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  movs r1, 0xF\n"
        "  lsls r0, r6, 4\n"
        "  adds r4, r6, 0x1\n"
        "  ands r4, r1\n"
        "  orrs r0, r4\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  lsls r0, r4, 4\n"
        "  orrs r0, r4\n"
        "  lsls r0, 24\n"
        "  lsrs r0, 24\n"
        "  b _0800B12A\n"
        "_0800B024:\n"
        "  ldrb r0, [r2]\n"
        "  movs r1, 0xF\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  adds r5, r6, 0\n"
        "  ands r5, r1\n"
        "  lsls r4, r5, 4\n"
        "  subs r0, r6, 0x1\n"
        "  ands r0, r1\n"
        "  orrs r0, r4\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  orrs r4, r5\n"
        "  b _0800B128\n"
        "_0800B048:\n"
        "  ldrb r0, [r2]\n"
        "  movs r5, 0xF\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  adds r4, r6, 0\n"
        "  ands r4, r5\n"
        "  lsls r0, r4, 4\n"
        "  orrs r0, r4\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  subs r0, r6, 0x1\n"
        "  ands r0, r5\n"
        "  lsls r0, 4\n"
        "  orrs r0, r4\n"
        "  b _0800B12A\n"
        "_0800B06E:\n"
        "  ldrb r0, [r2]\n"
        "  movs r5, 0xF\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  adds r1, r6, 0\n"
        "  ands r1, r5\n"
        "  lsls r4, r1, 4\n"
        "  adds r0, r4, 0\n"
        "  orrs r0, r1\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  subs r0, r6, 0x1\n"
        "  b _0800B124\n"
        "_0800B090:\n"
        "  ldrb r0, [r2]\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  movs r1, 0xF\n"
        "  lsls r0, r6, 4\n"
        "  subs r4, r6, 0x1\n"
        "  ands r4, r1\n"
        "  orrs r0, r4\n"
        "  lsls r0, 24\n"
        "  lsrs r0, 24\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  lsls r0, r4, 4\n"
        "  orrs r0, r4\n"
        "  lsls r0, 24\n"
        "  lsrs r0, 24\n"
        "  b _0800B12A\n"
        "_0800B0BA:\n"
        "  ldrb r0, [r2]\n"
        "  movs r1, 0xF\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  adds r5, r6, 0\n"
        "  ands r5, r1\n"
        "  lsls r4, r5, 4\n"
        "  adds r0, r6, 0x1\n"
        "  ands r0, r1\n"
        "  orrs r0, r4\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  orrs r4, r5\n"
        "  b _0800B128\n"
        "_0800B0DE:\n"
        "  ldrb r0, [r2]\n"
        "  movs r5, 0xF\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  adds r4, r6, 0\n"
        "  ands r4, r5\n"
        "  lsls r0, r4, 4\n"
        "  orrs r0, r4\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  adds r0, r6, 0x1\n"
        "  ands r0, r5\n"
        "  lsls r0, 4\n"
        "  orrs r0, r4\n"
        "  b _0800B12A\n"
        "_0800B104:\n"
        "  ldrb r0, [r2]\n"
        "  movs r5, 0xF\n"
        "  movs r6, 0xF\n"
        "  ands r6, r0\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  adds r1, r6, 0\n"
        "  ands r1, r5\n"
        "  lsls r4, r1, 4\n"
        "  adds r0, r4, 0\n"
        "  orrs r0, r1\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r3, 0x1\n"
        "  add r9, r3\n"
        "  adds r0, r6, 0x1\n"
        "_0800B124:\n"
        "  ands r0, r5\n"
        "  orrs r4, r0\n"
        "_0800B128:\n"
        "  adds r0, r4, 0\n"
        "_0800B12A:\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r0, 0x1\n"
        "  add r9, r0\n"
        "  ldr r5, [sp, 0x30]\n"
        "  adds r5, 0x1\n"
        "  ldr r1, [sp, 0x2C]\n"
        "  lsls r4, r1, 1\n"
        "  b _0800B198\n"
        "_0800B13C:\n"
        "  movs r2, 0x1\n"
        "  add r8, r2\n"
        "  mov r0, r10\n"
        "  add r0, r8\n"
        "  ldrb r0, [r0]\n"
        "  adds r7, r0\n"
        "  add r8, r2\n"
        "  ldr r1, _0800B17C\n"
        "  adds r0, r7, r1\n"
        "  mov r2, r9\n"
        "  adds r7, r0, r2\n"
        "  ldr r5, [sp, 0x30]\n"
        "  adds r5, 0x1\n"
        "  ldr r0, [sp, 0x2C]\n"
        "  lsls r4, r0, 1\n"
        "  cmp r3, 0\n"
        "  beq _0800B198\n"
        "  adds r6, r3, 0\n"
        "_0800B160:\n"
        "  adds r0, r7, 0\n"
        "  bl DecompressAT_GetByte\n"
        "  lsls r0, 24\n"
        "  lsrs r0, 24\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r1, 0x1\n"
        "  add r9, r1\n"
        "  adds r7, 0x1\n"
        "  subs r6, 0x1\n"
        "  cmp r6, 0\n"
        "  bne _0800B160\n"
        "  b _0800B198\n"
        "  .align 2, 0\n"
        "_0800B17C: .4byte 0xfffff000\n"
        "_0800B180:\n"
        "  mov r0, r10\n"
        "  add r0, r8\n"
        "  ldrb r0, [r0]\n"
        "  bl DecompressAT_AppendByte\n"
        "  movs r2, 0x1\n"
        "  add r9, r2\n"
        "  add r8, r2\n"
        "  ldr r5, [sp, 0x30]\n"
        "  adds r5, 0x1\n"
        "  ldr r3, [sp, 0x2C]\n"
        "  lsls r4, r3, 1\n"
        "_0800B198:\n"
        "  str r5, [sp, 0x30]\n"
        "  str r4, [sp, 0x2C]\n"
        "  ldr r0, [sp, 0x28]\n"
        "  cmp r8, r0\n"
        "  bge _0800B1A4\n"
        "  b _0800AF22\n"
        "_0800B1A4:\n"
        "  bl DecompressAT_Finish\n"
        "  mov r0, r9\n"
        "_0800B1AA:\n"
        "  add sp, 0x34\n"
        "  pop {r3-r5}\n"
        "  mov r8, r3\n"
        "  mov r9, r4\n"
        "  mov r10, r5\n"
        "  pop {r4-r7}\n"
        "  pop {r1}\n"
        "  bx r1");
#endif
}

// 800B1BC
void DecompressAT_Init(u32 *buffer) {
    gDecompressBufferPtr = buffer;
    gDecompressBufferStart = buffer;
    gDecompressBufferCurrent = 0;
    gDecompressBufferByteInInt = 0;
}

// 800B1E0
char DecompressAT_GetByte(int index) {
    u32 data;
    int offset;

    offset = index < 0 ? index + 3 : index;
    data = gDecompressBufferStart[offset >> 2];

    switch (index & 3) {
        case 0: return data;
        case 1: return data >> 8;
        case 2: return data >> 16;
        case 3: return data >> 24;
    }

    return data;
}

// 800B220
void DecompressAT_AppendByte(char value) {
    gDecompressBufferCurrent |= value << gByteShiftLookup[gDecompressBufferByteInInt];
    *gDecompressBufferPtr = gDecompressBufferCurrent;
    gDecompressBufferByteInInt++;
    if (gDecompressBufferByteInInt == 4) {
        gDecompressBufferPtr++;
        gDecompressBufferCurrent = 0;
        gDecompressBufferByteInInt = 0;
    }
}

// 800B270
void DecompressAT_Finish(void) {
    if (gDecompressBufferByteInInt)
        *gDecompressBufferPtr = gDecompressBufferCurrent;
}

// 800B294
bool32 IsATxPCompressed_unused(char *data) {
    if ((data[0] == 'A' && data[1] == 'T' && data[2] == '4' && data[3] == 'P')) return TRUE;
    if ((data[0] == 'A' && data[1] == 'T' && data[2] == '3' && data[3] == 'P')) return TRUE;
    return FALSE;
}

// 800B2D4
bool32 sub_800B2D4(char *arg0, char *arg1, int length) {
    int i;
    char a, b;
    for (i = 0; i < length; i++) {
        a = arg0[i];
        b = arg1[i];
        // convert to lowercase
        if ('A' <= a && a <= 'Z') a += 0x20;
        if ('A' <= b && b <= 'Z') b += 0x20;
        if (a != b)
            return TRUE;
        if (a == '\0')
            break;
    }
    return FALSE;
}

// Has to be down here to match (rodata ordering)
ALIGNED(4) const char file_filler[] = _("pksdir0");
const u32 gByteShiftLookup[4] = {0, 8, 16, 24};
ALIGNED(4) const char file_filler1[] = _("pksdir0");
ALIGNED(4) const char file_filler2[] = _("pksdir0");

