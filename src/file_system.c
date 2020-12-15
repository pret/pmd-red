#include "global.h"
#include "file_system.h"

extern struct OpenedFile gFileCache[64];

extern u32 gFileCacheCursorPosition;
extern u32 gUnknown_202D2A4;

extern const u32 gByteShiftLookup[4];

extern u32 *gDecompressBufferPtr;
extern u32 *gDecompressBufferStart;
extern u32 gDecompressBufferCurrent;
extern u32 gDecompressBufferByteInInt;

extern int sprintf(char *, const char *, ...);

void DecompressAT_Init(u32 *buffer);
void DecompressAT_AppendByte(char value);
void DecompressAT_Finish(void);
char DecompressAT_GetByte(int index);

u32 DecompressAT(char *result, u32 resultLength, const char *compressedData);
u32 DecompressATGlobal(u32 *result, u32 resultLength, const char *compressedData);
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

u32 DecompressATFile(char *result, u32 resultLength, struct OpenedFile *file)
{
    return DecompressAT(result, resultLength, file->data);
}

// 800AAB4
#ifndef NONMATCHING
NAKED
#endif
u32 DecompressAT(char *result, u32 resultLength, const char *compressedData)
{
#ifdef NONMATCHING

    // This function is an absolute mess, the compiler does some extremely weird things
    // which makes matching it difficult.

    // As-is, it's likely that this implementation is nonfunctional
    // as I've shuffled things around a lot while trying to make some parts match.

    int flags1;
    int flags2;
    int flags3;
    int flags4;
    int flags5;
    int flags6;
    int flags7;
    int flags8;
    int flags9;
    int compressedLength;
    char c10;
    char c11;
    u32 curIndex;
    int v12;
    char c13;
    const char *p;
    int command;
    int resultIndex;
    int v16;
    int cmdBit;
    int currentByte;

    compressedLength = compressedData[5] + (compressedData[6] << 8);
    resultIndex = 0;
    currentByte = 0;
    cmdBit = 8;

    if (compressedData[0] == 'A'
     && compressedData[1] == 'T'
     && compressedData[2] == '4'
     && compressedData[3] == 'P') {
        if (resultLength != compressedData[0x10] + (compressedData[0x11] << 8) && resultLength != 0)
            return 0;
        curIndex = 0x12;
    } else if (compressedData[0] == 'A'
            && compressedData[1] == 'T'
            && compressedData[2] == '3'
            && compressedData[3] == 'P') {
        // Can't get this to match - compiler chooses beq, b pairs instead of bne
        // I tried multiple if (... != 'x') return 0;
        // I tried != chained with ||
        // I tried == chained with &&
        // I tried nested if (... == 'x')
        // None of that produced matching code.
        curIndex = 0x10;
    } else {
        return 0;
    }

    if (compressedData[5] == 'N') {
        // uncompressed mode, unused
        int i;
        for (i = 0; i < compressedLength; i++)
            result[i] = compressedData[i + 7];
        return i;
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

    // Some mismatches regarding the signedness of these two conditionals, extremely fragile
    if (curIndex < compressedLength) {
        while (resultLength == 0 || resultIndex < resultLength) {
            if (cmdBit == 8) {
                currentByte = compressedData[curIndex++];
                cmdBit = 0;
            }
            if (currentByte & 0x80) { // some weird reordering happens here, couldn't figure it out
                result[resultIndex++] = compressedData[curIndex++];
                goto end_800AE08;
            }
            p = &compressedData[curIndex];
            command = (*p >> 4) + 3;
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
            case 0x1f:
                c10 = *p & 0xf;
                c10 = c10 | (c10 << 4);
                result[resultIndex++] = c10;
                result[resultIndex++] = c10;
                curIndex++;
                // if curIndex is incremented inside each case, the compiler leaves them inside, but if curIndex is moved after the switch
                // then it moves the second result assignment (just the 'strb' instruction) after the switch.
                // Can't figure out how to make the compiler move only one without the other.
                break;
            case 0x1e:
                v12 = *p & 0xf;
                v12 = (v12 + 1) & 0xf;
                c10 = v12;
                result[resultIndex++] = ((*p & 0xf) << 4) | c10;
                result[resultIndex++] = (v12 << 4) | c10;
                curIndex++;
                break;
            case 0x1d:
                c11 = *p & 0xf;
                c10 = c11 << 4;
                result[resultIndex++] = ((c11 - 1) & 0xf) | c10;
                result[resultIndex++] = c10 | c11;
                curIndex++;
                break;
            case 0x1c:
                v12 = *p & 0xf;
                c10 = v12;
                result[resultIndex++] = (v12 << 4) | c10;
                result[resultIndex++] = ((v12 & 0xf) << 4) | c10;
                v12--;
                curIndex++;
                break;
            case 0x1b:
                c10 = *p;
                c11 = c10 & 0xf;
                c13 = c11 << 4;
                result[resultIndex++] = c13 | c11;
                c10 = (c10 & 0xf) - 1;
                result[resultIndex++] = c13 | (c10 & 0xf);
                curIndex++;
                break;
            case 0x1a:
                v12 = ((*p & 0xf) - 1) & 0xf;
                c10 = v12;
                result[resultIndex++] = ((*p & 0xf) << 4) | c10;
                result[resultIndex++] = (v12 << 4) | c10;
                curIndex++;
                break;
            case 0x19:
                c11 = *p & 0xf;
                c10 = c11 << 4;
                result[resultIndex++] = ((c11 + 1) & 0xf) | c10;
                result[resultIndex++] = c10 | c11;
                curIndex++;
                break;
            case 0x18:
                v12 = *p & 0xf;
                c10 = v12;
                result[resultIndex++] = (v12 << 4) | c10;
                v12++;
                curIndex++;
                result[resultIndex++] = ((v12 & 0xf) << 4) | c10;
                break;
            case 0x17:
                c10 = *p;
                c11 = c10 & 0xf;
                c13 = c11 << 4;
                result[resultIndex++] = c11 | c13;
                c10 = (c10 & 0xf) + 1;
                result[resultIndex++] = c13 | (c10 & 0xf);
                curIndex++;
                break;
            default:
                v16 = curIndex + 1;
                curIndex += 2;
                v16 = ((*p & 0xf) << 8) + compressedData[v16] + (-0x1000) + resultIndex;
                while (command) {
                    result[resultIndex++] = result[v16++];
                    command--;
                }
                break;
            }
end_800AE08:
            cmdBit++;
            currentByte <<= 1;
            if (curIndex > compressedLength)
                return resultIndex;
        }
    }

    return 0;
#else
    asm_unified(
        "DecompressAT:\n"
        "  push {r4-r7,lr}\n"
        "  mov r7, r10\n"
        "  mov r6, r9\n"
        "  mov r5, r8\n"
        "  push {r5-r7}\n"
        "  sub sp, 0x2C\n"
        "  mov r12, r0\n"
        "  str r1, [sp, 0x24]\n"
        "  mov r8, r2\n"
        "  ldrb r0, [r2, 0x5]\n"
        "  ldrb r1, [r2, 0x6]\n"
        "  lsls r1, 8\n"
        "  adds r0, r1\n"
        "  str r0, [sp, 0x28]\n"
        "  movs r6, 0\n"
        "  mov r10, r6\n"
        "  movs r0, 0x8\n"
        "  mov r9, r0\n"
        "  ldrb r0, [r2]\n"
        "  cmp r0, 0x41\n"
        "  bne _0800AB04\n"
        "  ldrb r0, [r2, 0x1]\n"
        "  adds r1, r0, 0\n"
        "  cmp r1, 0x54\n"
        "  bne _0800AB0C\n"
        "  ldrb r0, [r2, 0x2]\n"
        "  cmp r0, 0x34\n"
        "  bne _0800AB0C\n"
        "  ldrb r0, [r2, 0x3]\n"
        "  cmp r0, 0x50\n"
        "  bne _0800AB0C\n"
        "  ldrb r1, [r2, 0x10]\n"
        "  ldrb r0, [r2, 0x11]\n"
        "  lsls r0, 8\n"
        "  adds r1, r0\n"
        "  ldr r2, [sp, 0x24]\n"
        "  cmp r2, 0\n"
        "  beq _0800AB08\n"
        "  cmp r2, r1\n"
        "  beq _0800AB08\n"
        "_0800AB04:\n"
        "  movs r0, 0\n"
        "  b _0800AE16\n"
        "_0800AB08:\n"
        "  movs r1, 0x12\n"
        "  b _0800AB26\n"
        "_0800AB0C:\n"
        "  mov r3, r8\n"
        "  ldrb r0, [r3]\n"
        "  cmp r0, 0x41\n"
        "  bne _0800AB04\n"
        "  cmp r1, 0x54\n"
        "  bne _0800AB04\n"
        "  ldrb r0, [r3, 0x2]\n"
        "  cmp r0, 0x33\n"
        "  bne _0800AB04\n"
        "  ldrb r0, [r3, 0x3]\n"
        "  cmp r0, 0x50\n"
        "  bne _0800AB04\n"
        "  movs r1, 0x10\n"
        "_0800AB26:\n"
        "  mov r2, r8\n"
        "  ldrb r0, [r2, 0x4]\n"
        "  cmp r0, 0x4E\n"
        "  bne _0800AB4A\n"
        "  movs r7, 0\n"
        "  b _0800AB40\n"
        "_0800AB32:\n"
        "  mov r1, r12\n"
        "  adds r0, r1, r7\n"
        "  mov r2, r8\n"
        "  adds r1, r7, r2\n"
        "  ldrb r1, [r1, 0x7]\n"
        "  strb r1, [r0]\n"
        "  adds r7, 0x1\n"
        "_0800AB40:\n"
        "  ldr r3, [sp, 0x28]\n"
        "  cmp r7, r3\n"
        "  blt _0800AB32\n"
        "  adds r0, r7, 0\n"
        "  b _0800AE16\n"
        "_0800AB4A:\n"
        "  mov r2, r8\n"
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
        "  adds r7, r1, 0\n"
        "  ldr r3, [sp, 0x28]\n"
        "  cmp r7, r3\n"
        "  blt _0800AB8C\n"
        "  b _0800AE14\n"
        "_0800AB8C:\n"
        "  ldr r0, [sp, 0x24]\n"
        "  cmp r0, 0\n"
        "  beq _0800AB96\n"
        "  cmp r6, r0\n"
        "  bge _0800AB04\n"
        "_0800AB96:\n"
        "  mov r1, r9\n"
        "  cmp r1, 0x8\n"
        "  bne _0800ABAA\n"
        "  mov r2, r8\n"
        "  adds r0, r2, r7\n"
        "  ldrb r0, [r0]\n"
        "  mov r10, r0\n"
        "  adds r7, 0x1\n"
        "  movs r3, 0\n"
        "  mov r9, r3\n"
        "_0800ABAA:\n"
        "  movs r0, 0x80\n"
        "  mov r1, r10\n"
        "  ands r0, r1\n"
        "  cmp r0, 0\n"
        "  beq _0800ABB6\n"
        "  b _0800ADF0\n"
        "_0800ABB6:\n"
        "  mov r3, r8\n"
        "  adds r2, r3, r7\n"
        "  ldrb r1, [r2]\n"
        "  lsrs r0, r1, 4\n"
        "  adds r3, r0, 0x3\n"
        "  movs r0, 0xF\n"
        "  ands r0, r1\n"
        "  lsls r5, r0, 8\n"
        "  ldr r0, [sp]\n"
        "  cmp r3, r0\n"
        "  bne _0800ABCE\n"
        "  movs r3, 0x1F\n"
        "_0800ABCE:\n"
        "  ldr r0, [sp, 0x4]\n"
        "  cmp r3, r0\n"
        "  bne _0800ABD6\n"
        "  movs r3, 0x1E\n"
        "_0800ABD6:\n"
        "  ldr r0, [sp, 0x8]\n"
        "  cmp r3, r0\n"
        "  bne _0800ABDE\n"
        "  movs r3, 0x1D\n"
        "_0800ABDE:\n"
        "  ldr r0, [sp, 0xC]\n"
        "  cmp r3, r0\n"
        "  bne _0800ABE6\n"
        "  movs r3, 0x1C\n"
        "_0800ABE6:\n"
        "  ldr r0, [sp, 0x10]\n"
        "  cmp r3, r0\n"
        "  bne _0800ABEE\n"
        "  movs r3, 0x1B\n"
        "_0800ABEE:\n"
        "  ldr r0, [sp, 0x14]\n"
        "  cmp r3, r0\n"
        "  bne _0800ABF6\n"
        "  movs r3, 0x1A\n"
        "_0800ABF6:\n"
        "  ldr r0, [sp, 0x18]\n"
        "  cmp r3, r0\n"
        "  bne _0800ABFE\n"
        "  movs r3, 0x19\n"
        "_0800ABFE:\n"
        "  ldr r0, [sp, 0x1C]\n"
        "  cmp r3, r0\n"
        "  bne _0800AC06\n"
        "  movs r3, 0x18\n"
        "_0800AC06:\n"
        "  ldr r0, [sp, 0x20]\n"
        "  cmp r3, r0\n"
        "  bne _0800AC0E\n"
        "  movs r3, 0x17\n"
        "_0800AC0E:\n"
        "  adds r0, r3, 0\n"
        "  subs r0, 0x17\n"
        "  cmp r0, 0x8\n"
        "  bls _0800AC18\n"
        "  b _0800ADB0\n"
        "_0800AC18:\n"
        "  lsls r0, 2\n"
        "  ldr r1, _0800AC24\n"
        "  adds r0, r1\n"
        "  ldr r0, [r0]\n"
        "  mov pc, r0\n"
        "  .align 2, 0\n"
        "_0800AC24: .4byte _0800AC28\n"
        "  .align 2, 0\n"
        "_0800AC28:\n"
        "  .4byte _0800AD7C\n"
        "  .4byte _0800AD48\n"
        "  .4byte _0800AD20\n"
        "  .4byte _0800ACFA\n"
        "  .4byte _0800ACD6\n"
        "  .4byte _0800ACB4\n"
        "  .4byte _0800AC8C\n"
        "  .4byte _0800AC66\n"
        "  .4byte _0800AC4C\n"
        "_0800AC4C:\n"
        "  ldrb r1, [r2]\n"
        "  movs r0, 0xF\n"
        "  adds r7, 0x1\n"
        "  mov r3, r12\n"
        "  adds r2, r3, r6\n"
        "  ands r0, r1\n"
        "  lsls r1, r0, 4\n"
        "  orrs r1, r0\n"
        "  strb r1, [r2]\n"
        "  adds r6, 0x1\n"
        "  adds r0, r3, r6\n"
        "  strb r1, [r0]\n"
        "  b _0800ADA4\n"
        "_0800AC66:\n"
        "  ldrb r0, [r2]\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r1, r12\n"
        "  adds r3, r1, r6\n"
        "  movs r2, 0xF\n"
        "  lsls r0, r5, 4\n"
        "  adds r1, r5, 0x1\n"
        "  ands r1, r2\n"
        "  orrs r0, r1\n"
        "  strb r0, [r3]\n"
        "  adds r6, 0x1\n"
        "  mov r3, r12\n"
        "  adds r2, r3, r6\n"
        "  lsls r0, r1, 4\n"
        "  orrs r0, r1\n"
        "  strb r0, [r2]\n"
        "  b _0800ADA4\n"
        "_0800AC8C:\n"
        "  ldrb r0, [r2]\n"
        "  movs r3, 0xF\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r1, r12\n"
        "  adds r4, r1, r6\n"
        "  adds r2, r5, 0\n"
        "  ands r2, r3\n"
        "  lsls r1, r2, 4\n"
        "  subs r0, r5, 0x1\n"
        "  ands r0, r3\n"
        "  orrs r0, r1\n"
        "  strb r0, [r4]\n"
        "  adds r6, 0x1\n"
        "  mov r3, r12\n"
        "  adds r0, r3, r6\n"
        "  orrs r1, r2\n"
        "  strb r1, [r0]\n"
        "  b _0800ADA4\n"
        "_0800ACB4:\n"
        "  ldrb r0, [r2]\n"
        "  movs r3, 0xF\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r1, r12\n"
        "  adds r2, r1, r6\n"
        "  adds r1, r5, 0\n"
        "  ands r1, r3\n"
        "  lsls r0, r1, 4\n"
        "  orrs r0, r1\n"
        "  strb r0, [r2]\n"
        "  adds r6, 0x1\n"
        "  mov r0, r12\n"
        "  adds r2, r0, r6\n"
        "  subs r0, r5, 0x1\n"
        "  b _0800AD68\n"
        "_0800ACD6:\n"
        "  ldrb r0, [r2]\n"
        "  movs r4, 0xF\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r2, r12\n"
        "  adds r3, r2, r6\n"
        "  adds r1, r5, 0\n"
        "  ands r1, r4\n"
        "  lsls r2, r1, 4\n"
        "  adds r0, r2, 0\n"
        "  orrs r0, r1\n"
        "  strb r0, [r3]\n"
        "  adds r6, 0x1\n"
        "  mov r3, r12\n"
        "  adds r1, r3, r6\n"
        "  subs r0, r5, 0x1\n"
        "  b _0800AD9E\n"
        "_0800ACFA:\n"
        "  ldrb r0, [r2]\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r1, r12\n"
        "  adds r3, r1, r6\n"
        "  movs r2, 0xF\n"
        "  lsls r0, r5, 4\n"
        "  subs r1, r5, 0x1\n"
        "  ands r1, r2\n"
        "  orrs r0, r1\n"
        "  strb r0, [r3]\n"
        "  adds r6, 0x1\n"
        "  mov r3, r12\n"
        "  adds r2, r3, r6\n"
        "  lsls r0, r1, 4\n"
        "  orrs r0, r1\n"
        "  strb r0, [r2]\n"
        "  b _0800ADA4\n"
        "_0800AD20:\n"
        "  ldrb r0, [r2]\n"
        "  movs r3, 0xF\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r1, r12\n"
        "  adds r4, r1, r6\n"
        "  adds r2, r5, 0\n"
        "  ands r2, r3\n"
        "  lsls r1, r2, 4\n"
        "  adds r0, r5, 0x1\n"
        "  ands r0, r3\n"
        "  orrs r0, r1\n"
        "  strb r0, [r4]\n"
        "  adds r6, 0x1\n"
        "  mov r3, r12\n"
        "  adds r0, r3, r6\n"
        "  orrs r1, r2\n"
        "  strb r1, [r0]\n"
        "  b _0800ADA4\n"
        "_0800AD48:\n"
        "  ldrb r0, [r2]\n"
        "  movs r3, 0xF\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r1, r12\n"
        "  adds r2, r1, r6\n"
        "  adds r1, r5, 0\n"
        "  ands r1, r3\n"
        "  lsls r0, r1, 4\n"
        "  orrs r0, r1\n"
        "  strb r0, [r2]\n"
        "  adds r6, 0x1\n"
        "  mov r0, r12\n"
        "  adds r2, r0, r6\n"
        "  adds r0, r5, 0x1\n"
        "_0800AD68:\n"
        "  ands r0, r3\n"
        "  lsls r0, 4\n"
        "  orrs r0, r1\n"
        "  strb r0, [r2]\n"
        "  adds r6, 0x1\n"
        "  mov r4, r9\n"
        "  adds r4, 0x1\n"
        "  mov r1, r10\n"
        "  lsls r2, r1, 1\n"
        "  b _0800AE08\n"
        "_0800AD7C:\n"
        "  ldrb r0, [r2]\n"
        "  movs r4, 0xF\n"
        "  movs r5, 0xF\n"
        "  ands r5, r0\n"
        "  adds r7, 0x1\n"
        "  mov r2, r12\n"
        "  adds r3, r2, r6\n"
        "  adds r1, r5, 0\n"
        "  ands r1, r4\n"
        "  lsls r2, r1, 4\n"
        "  adds r0, r2, 0\n"
        "  orrs r0, r1\n"
        "  strb r0, [r3]\n"
        "  adds r6, 0x1\n"
        "  mov r3, r12\n"
        "  adds r1, r3, r6\n"
        "  adds r0, r5, 0x1\n"
        "_0800AD9E:\n"
        "  ands r0, r4\n"
        "  orrs r2, r0\n"
        "  strb r2, [r1]\n"
        "_0800ADA4:\n"
        "  adds r6, 0x1\n"
        "  mov r4, r9\n"
        "  adds r4, 0x1\n"
        "  mov r0, r10\n"
        "  lsls r2, r0, 1\n"
        "  b _0800AE08\n"
        "_0800ADB0:\n"
        "  adds r7, 0x1\n"
        "  mov r1, r8\n"
        "  adds r0, r1, r7\n"
        "  ldrb r0, [r0]\n"
        "  adds r5, r0\n"
        "  adds r7, 0x1\n"
        "  ldr r2, _0800ADEC\n"
        "  adds r0, r5, r2\n"
        "  adds r5, r0, r6\n"
        "  mov r4, r9\n"
        "  adds r4, 0x1\n"
        "  mov r0, r10\n"
        "  lsls r2, r0, 1\n"
        "  cmp r3, 0\n"
        "  beq _0800AE08\n"
        "_0800ADCE:\n"
        "  mov r1, r12\n"
        "  adds r1, r6\n"
        "  mov r10, r1\n"
        "  mov r0, r12\n"
        "  adds r0, r5\n"
        "  ldrb r1, [r0]\n"
        "  mov r0, r10\n"
        "  strb r1, [r0]\n"
        "  adds r6, 0x1\n"
        "  adds r5, 0x1\n"
        "  subs r3, 0x1\n"
        "  cmp r3, 0\n"
        "  bne _0800ADCE\n"
        "  b _0800AE08\n"
        "  .align 2, 0\n"
        "_0800ADEC: .4byte 0xfffff000\n"
        "_0800ADF0:\n"
        "  mov r1, r12\n"
        "  adds r0, r1, r6\n"
        "  mov r2, r8\n"
        "  adds r1, r2, r7\n"
        "  ldrb r1, [r1]\n"
        "  strb r1, [r0]\n"
        "  adds r6, 0x1\n"
        "  adds r7, 0x1\n"
        "  mov r4, r9\n"
        "  adds r4, 0x1\n"
        "  mov r3, r10\n"
        "  lsls r2, r3, 1\n"
        "_0800AE08:\n"
        "  mov r9, r4\n"
        "  mov r10, r2\n"
        "  ldr r0, [sp, 0x28]\n"
        "  cmp r7, r0\n"
        "  bge _0800AE14\n"
        "  b _0800AB8C\n"
        "_0800AE14:\n"
        "  adds r0, r6, 0\n"
        "_0800AE16:\n"
        "  add sp, 0x2C\n"
        "  pop {r3-r5}\n"
        "  mov r8, r3\n"
        "  mov r9, r4\n"
        "  mov r10, r5\n"
        "  pop {r4-r7}\n"
        "  pop {r1}\n"
        "  bx r1");
#endif
}

u32 DecompressATGlobalFile(u32 *result, u32 resultLength, struct OpenedFile *file)
{
    return DecompressATGlobal(result, resultLength, file->data);
}

// 800AE34
#ifndef NONMATCHING
NAKED
#endif
u32 DecompressATGlobal(u32 *result, u32 resultLength, const char *compressedData)
{
#ifdef NONMATCHING

    // This function has the same issues as above, except is possibly a bit nicer due to the function calls
    // I'd say this one is more likely to be at least correct

    int flags1;
    int flags2;
    int flags3;
    int flags4;
    int flags5;
    int flags6;
    int flags7;
    int flags8;
    int flags9;
    int compressedLength;
    u32 c10;
    char c11;
    u32 curIndex;
    const char *p;
    int command;
    int bytesWritten;
    int v16;
    int cmdBit;
    int currentByte;

    compressedLength = compressedData[5] + (compressedData[6] << 8);
    bytesWritten = 0;
    currentByte = 0;
    cmdBit = 8;

    DecompressAT_Init(result);

    if (compressedData[0] == 'A'
     && compressedData[1] == 'T'
     && compressedData[2] == '4'
     && compressedData[3] == 'P') {
        if (resultLength != compressedData[0x10] + (compressedData[0x11] << 8) && resultLength != 0)
            return 0;
        curIndex = 0x12;
    } else if (compressedData[0] == 'A'
            && compressedData[1] == 'T'
            && compressedData[2] == '3'
            && compressedData[3] == 'P') {
        curIndex = 0x10;
    } else {
        return 0;
    }

    if (compressedData[5] == 'N') {
        // uncompressed mode, unused
        int i;
        for (i = 0; i < compressedLength; i++)
            DecompressAT_AppendByte(compressedData[i + 7]);
        DecompressAT_Finish();
        return i;
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

    // Some mismatches regarding the signedness of these two conditionals, extremely fragile
    if (curIndex < compressedLength) {
        while (resultLength == 0 || bytesWritten < resultLength) {
            if (cmdBit == 8) {
                currentByte = compressedData[curIndex++];
                cmdBit = 0;
            }
            if (currentByte & 0x80) { // some weird reordering happens here, couldn't figure it out
                DecompressAT_AppendByte(compressedData[curIndex++]);
                goto end_800B198;
            }
            p = &compressedData[curIndex];
            command = (*p >> 4) + 3;
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
            case 0x1f:
                c10 = *p & 0xf;
                c10 = c10 | (c10 << 4);
                DecompressAT_AppendByte(c10);
                break;
            case 0x1e:
                c10 = ((*p & 0xf) + 1) & 0xf;
                DecompressAT_AppendByte(((*p & 0xf) << 4) | c10);
                c10 |= c10 << 4;
                break;
            case 0x1d:
                c10 = *p & 0xf;
                DecompressAT_AppendByte(((c10 - 1) & 0xf) | (c10 << 4));
                c10 |= c10 << 4;
                break;
            case 0x1c:
                c10 = *p & 0xf;
                DecompressAT_AppendByte((c10 << 4) | c10);
                c10 |= ((c10 - 1) & 0xf) << 4;
                break;
            case 0x1b:
                c11 = *p & 0xf;
                c10 = c11 << 4;
                DecompressAT_AppendByte(c10 | c11);
                c11--;
                c10 |= c11 & 0xf;
                break;
            case 0x1a:
                c10 = ((*p & 0xf) - 1) & 0xf;
                DecompressAT_AppendByte(((*p & 0xf) << 4) | c10);
                c10 |= c10 << 4;
                break;
            case 0x19:
                c10 = *p & 0xf;
                DecompressAT_AppendByte(((c10 + 1) & 0xf) | (c10 << 4));
                c10 |= c10 << 4;
                break;
            case 0x18:
                c10 = *p & 0xf;
                DecompressAT_AppendByte((c10 << 4) | c10);
                c10 |= ((c10 + 1) & 0xf) << 4;
                break;
            case 0x17:
                c11 = *p & 0xf;
                c10 = c11 << 4;
                DecompressAT_AppendByte(c10 | c11);
                c11++;
                c10 |= c11 & 0xf;
                break;
            default:
                v16 = curIndex + 1;
                curIndex += 2;
                v16 = ((*p & 0xf) << 8) + compressedData[v16] + (-0x1000) + bytesWritten;
                while (command) {
                    char c = DecompressAT_GetByte(v16);
                    DecompressAT_AppendByte(c);
                    bytesWritten++;
                    v16++;
                    command--;
                }
                goto end_800B198;
            }
            curIndex++;
            DecompressAT_AppendByte(c10);
            bytesWritten += 2;
end_800B198:
            cmdBit++;
            currentByte <<= 1;
            if (curIndex > compressedLength)
                break;
        }
        DecompressAT_Finish();
        return bytesWritten;
    }

    return 0;
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
#ifndef NONMATCHING
NAKED
#endif
char DecompressAT_GetByte(int index) {
#ifdef NONMATCHING
    char result;
    u32 data;
    int offset;

    offset = index < 0 ? index + 3 : index;

    data = gDecompressBufferStart[offset >> 2];
    // compiler inserts a ldrb here for some reason?
    result = data;
    index &= 3;
    // Need to reorder these somehow to match
    if (index == 1) result = data >> 8;
    else if (index == 2) result = data >> 16;
    else if (index == 3) return data >> 24;
    return result;
#else
    asm_unified(
        "DecompressAT_GetByte:\n"
        "  push {lr}\n"
        "  adds r2, r0, 0\n"
        "  cmp r2, 0\n"
        "  bge _0800B1EA\n"
        "  adds r0, r2, 0x3\n"
        "_0800B1EA:\n"
        "  asrs r0, 2\n"
        "  ldr r1, _0800B20C\n"
        "  ldr r1, [r1]\n"
        "  lsls r0, 2\n"
        "  adds r0, r1\n"
        "  ldr r0, [r0]\n"
        "  movs r1, 0x3\n"
        "  ands r1, r2\n"
        "  cmp r1, 0x1\n"
        "  beq _0800B210\n"
        "  cmp r1, 0x1\n"
        "  ble _0800B216\n"
        "  cmp r1, 0x2\n"
        "  beq _0800B214\n"
        "  cmp r1, 0x3\n"
        "  beq _0800B218\n"
        "  b _0800B216\n"
        "  .align 2, 0\n"
        "_0800B20C: .4byte gDecompressBufferStart\n"
        "_0800B210:\n"
        "  lsrs r0, 8\n"
        "  b _0800B216\n"
        "_0800B214:\n"
        "  lsrs r0, 16\n"
        "_0800B216:\n"
        "  lsls r0, 24\n"
        "_0800B218:\n"
        "  lsrs r0, 24\n"
        "  pop {r1}\n"
        "  bx r1");
#endif
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
