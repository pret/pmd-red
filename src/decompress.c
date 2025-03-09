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
static void NDS_DecompressRLE(const SiroArchive *);

const void *GetSiroPtr(OpenedFile *openedFile)
{
    const SiroArchive *siro = (const SiroArchive *)openedFile->data;

    if (siro->magic == MAGIC_SIR0)
        NDS_DecompressRLE(openedFile->data);
    else if (siro->magic != MAGIC_SIRO)
        return openedFile->data;

    openedFile->data = siro->data;

    return openedFile->data;
}

UNUSED static const void *UnusedGetSir0Ptr(const SiroArchive *siro)
{
    if (siro->magic != MAGIC_SIR0)
        return siro;

    NDS_DecompressRLE(siro);
    return siro->data;
}

static void NDS_DecompressRLE(const SiroArchive *siro)
{
}

void nullsub_16(void)
{
}

UNUSED static void nullsub_175(void)
{
}

u32 DecompressATFile(void *dst, s32 dstLen, OpenedFile *file)
{
    return DecompressAT(dst, dstLen, file->data);
}

u32 DecompressAT(u8 *dst, s32 dstLen, const u8 *src)
{
    s32 compressedLength = src[5] + (src[6] << 8);
    s32 bytesWritten = 0;
    s32 currentByte = 0;
    s32 cmdBit = 8;
    s32 curIndex;
    s32 flags[9];
    s32 idxStart;

    if (src[0] == 'A'
     && src[1] == 'T'
     && src[2] == '4'
     && src[3] == 'P') {
        u32 tmp2 = src[0x10] + (src[0x11] << 8);
        if (dstLen != 0 && dstLen != tmp2)
            return 0;
        idxStart = 0x12;
    }
    else if (src[0] == 'A'
            && src[1] == 'T'
            && src[2] == '3'
            && src[3] == 'P') {
        idxStart = 0x10;
    }
    else
        return 0;

    if (src[4] == 'N') {
        // uncompressed mode, unused
        for (curIndex = 0; curIndex < compressedLength; curIndex++) {
            dst[curIndex] = src[curIndex + 7];
        }
        return curIndex;
    }

    flags[0] = src[0x7] + 3;
    flags[1] = src[0x8] + 3;
    flags[2] = src[0x9] + 3;
    flags[3] = src[0xa] + 3;
    flags[4] = src[0xb] + 3;
    flags[5] = src[0xc] + 3;
    flags[6] = src[0xd] + 3;
    flags[7] = src[0xe] + 3;
    flags[8] = src[0xf] + 3;

    curIndex = idxStart;
    if (curIndex < compressedLength) {

        do {
            if (dstLen != 0 && bytesWritten >= dstLen)
                return 0;

            if (cmdBit == 8) {
                currentByte = src[curIndex++];
                cmdBit = 0;
            }
            if ((currentByte & 0x80) == 0) {
                // if bit is unset, process command
                u32 command = (src[curIndex] >> 4) + 3;
                u32 tmp = (src[curIndex] & 0xf) << 8;
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
                        c = src[curIndex++] & 0xf;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x1e: { // abbb
                        u8 byte = src[curIndex];
                        c = 0xF;
                        c = byte & c;
                        curIndex++;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf));
                        dst[bytesWritten++] = ((((c + 1) & 0xf) << 4) | ((c + 1) & 0xf));
                        break;
                    }
                    case 0x1d: { // babb
                        c = src[curIndex++] & 0xf;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf));
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x1c: { // bbab
                        c = src[curIndex++] & 0xf;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        dst[bytesWritten++] = ((((c - 1) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x1b: { // bbba
                        c = src[curIndex++] & 0xf;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf));
                        break;
                    }
                    case 0x1a: { // baaa -- the horrible, hard-to-match case
                        u8 byte = src[curIndex];
                        c = 0xF;
                        c = byte & c;
                        curIndex++;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c - 1) & 0xf));
                        dst[bytesWritten++] = ((((c - 1) & 0xf) << 4) | ((c - 1) & 0xf));
                        break;
                    }
                    case 0x19: { // abaa
                        c = src[curIndex++] & 0xf;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf));
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x18: { // aaba
                        c = src[curIndex++] & 0xf;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        dst[bytesWritten++] = ((((c + 1) & 0xf) << 4) | ((c + 0) & 0xf));
                        break;
                    }
                    case 0x17: { // aaab
                        c = src[curIndex++] & 0xf;
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 0) & 0xf));
                        dst[bytesWritten++] = ((((c + 0) & 0xf) << 4) | ((c + 1) & 0xf));
                        break;
                    }
                    default: {
                        tmp += (src[curIndex++, curIndex++]);
                        tmp += bytesWritten - 0x1000;
                        for(;command;command--)
                        {
                            dst[bytesWritten++] = dst[tmp];
                            tmp++;
                        }
                    }
                }
            } else {
                // if bit is set, just copy next byte
                dst[bytesWritten++] = (src[curIndex]);
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

// Is this for sure part of this file?

bool8 StrsDifferent_IgnoreCase(char *strA, char *strB, s32 maxLen)
{
    s32 i;

    for (i = 0; i < maxLen; i++) {
        char a = strA[i];
        char b = strB[i];

        // Uppercase -> lowercase
        if ('A' <= a && a <= 'Z')
            a += 0x20;
        if ('A' <= b && b <= 'Z')
            b += 0x20;

        if (a != b)
            return TRUE;
        // `a` and `b` are equal here, but we check them for null terminators since `maxLen` is just a suggestion
        if (a == '\0' /*&& b == '\0'*/)
            break;
    }
    return FALSE;
}
