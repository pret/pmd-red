#include "global.h"
#include "globaldata.h"
#include "decompress.h"

#define MAGIC_SIR0 0x30524953
#define MAGIC_SIRO 0x4F524953

EWRAM_DATA u32 *gDecompressBufferPtr = {0};
EWRAM_DATA u32 *gDecompressBufferStart = {0};
EWRAM_DATA u32 gDecompressBufferCurrent = {0};
EWRAM_DATA u32 gDecompressBufferByteInInt = {0};

#include "data/decompress.h"

static void DecompressAT_AppendByte(char);
static void DecompressAT_Finish(void);
static char DecompressAT_GetByte(s32);
static void DecompressAT_Init(u32 *);
static u32 DecompressATGlobal(u32 *, s32, const char *);
static void NDS_DecompressRLE(const void *);

const u8 *GetSiroPtr(OpenedFile *openedFile)
{
    struct SiroArchive *siro = (struct SiroArchive *)openedFile->data;

    if (siro->magic == MAGIC_SIR0)
        NDS_DecompressRLE(openedFile->data);
    else if (siro->magic != MAGIC_SIRO)
        return openedFile->data;

    openedFile->data = siro->data;

    return openedFile->data;
}

UNUSED static void *UnusedGetSir0Ptr(struct SiroArchive *siro)
{
    if (siro->magic != MAGIC_SIR0)
        return siro;

    NDS_DecompressRLE(siro);
    return siro->data;
}

static void NDS_DecompressRLE(const void *unused)
{
}

void nullsub_16(void)
{
}

UNUSED static void nullsub_175(void)
{
}

u32 DecompressATFile(u8 *result, s32 resultLength, OpenedFile *file)
{
    return DecompressAT(result, resultLength, file->data);
}

u32 DecompressAT(u8 *result, s32 resultLength, const u8 *compressedData)
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
    }
    else if (compressedData[0] == 'A'
            && compressedData[1] == 'T'
            && compressedData[2] == '3'
            && compressedData[3] == 'P') {
        idxStart = 0x10;
    }
    else
        return 0;

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

u32 DecompressATGlobalFile(u32 *result, s32 resultLength, OpenedFile *file)
{
    return DecompressATGlobal(result, resultLength, file->data);
}

static u32 DecompressATGlobal(u32 *result, s32 resultLength, const char *compressedData)
{
    s32 flags[9];
    s32 curIndex;
    s32 firstIndex;
    u32 c;
    s32 compressedLength = compressedData[5] + (compressedData[6] << 8);
    s32 bytesWritten = 0;
    s32 currentByte = 0;
    s32 cmdBit = 8;

    DecompressAT_Init(result);

    if (compressedData[0] == 'A'
     && compressedData[1] == 'T'
     && compressedData[2] == '4'
     && compressedData[3] == 'P') {
        s32 checkLength = compressedData[0x10] + (compressedData[0x11] << 8);
        if (resultLength != 0 && resultLength != checkLength)
            return bytesWritten;
        firstIndex = 0x12;
    }
    else if (compressedData[0] == 'A'
            && compressedData[1] == 'T'
            && compressedData[2] == '3'
            && compressedData[3] == 'P') {
        firstIndex = 0x10;
    }
    else {
        return 0;
    }

    if (compressedData[4] == 'N') {
        // uncompressed mode, unused
        for (curIndex = 0; curIndex < compressedLength; curIndex++) {
            DecompressAT_AppendByte(compressedData[curIndex + 7]);
        }
        DecompressAT_Finish();
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

    curIndex = firstIndex;

    while (curIndex < compressedLength) {
        if (resultLength != 0 && bytesWritten >= resultLength)
            return 0;

        if (cmdBit == 8) {
            currentByte = compressedData[curIndex++];
            cmdBit = 0;
        }
        if ((currentByte & 0x80) == 0) {
            // if bit is unset, process command
            s32 command = (compressedData[curIndex] >> 4) + 3;
            s32 tmp2 = (compressedData[curIndex] & 0xf) << 8;

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
                    s32 i;
                    s32 a;

                    curIndex++;
                    tmp2 += compressedData[curIndex++];
                    a = tmp2 - 0x1000;
                    tmp2 = a + bytesWritten;
                    for (i = 0; i < command; i++) {
                        DecompressAT_AppendByte(DecompressAT_GetByte(tmp2)); bytesWritten++;
                        tmp2++;
                    }
                }
            }
        }
        else {
            // if bit is set, just copy next byte
            DecompressAT_AppendByte(compressedData[curIndex]); bytesWritten++;
            curIndex++;
        }
        cmdBit++;
        currentByte <<= 1;
    }

    DecompressAT_Finish();
    return bytesWritten;
}

static void DecompressAT_Init(u32 *buffer)
{
    gDecompressBufferPtr = buffer;
    gDecompressBufferStart = buffer;
    gDecompressBufferCurrent = 0;
    gDecompressBufferByteInInt = 0;
}

static char DecompressAT_GetByte(s32 index)
{
    u32 data;
    s32 offset;

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

static void DecompressAT_AppendByte(char value)
{
    gDecompressBufferCurrent |= value << gByteShiftLookup[gDecompressBufferByteInInt];
    *gDecompressBufferPtr = gDecompressBufferCurrent;
    gDecompressBufferByteInInt++;

    if (gDecompressBufferByteInInt == 4) {
        gDecompressBufferPtr++;
        gDecompressBufferCurrent = 0;
        gDecompressBufferByteInInt = 0;
    }
}

static void DecompressAT_Finish(void)
{
    if (gDecompressBufferByteInInt)
        *gDecompressBufferPtr = gDecompressBufferCurrent;
}

UNUSED static bool32 IsATxPCompressed_unused(char *data)
{
    if ((data[0] == 'A' && data[1] == 'T' && data[2] == '4' && data[3] == 'P')) return TRUE;
    if ((data[0] == 'A' && data[1] == 'T' && data[2] == '3' && data[3] == 'P')) return TRUE;
    return FALSE;
}

bool8 sub_800B2D4(char *arg0, char *arg1, s32 length)
{
    s32 i;
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
