#include "global.h"
#include "globaldata.h"
#include "decompress_at.h"

EWRAM_DATA u32 *gDecompressBufferPtr = {0}; // NDS=020EDCC8
EWRAM_DATA u32 *gDecompressBufferStart = {0}; // NDS=02EDCD4
EWRAM_DATA u32 gDecompressBufferCurrent = {0}; // NDS=020EDCCC
EWRAM_DATA u32 gDecompressBufferByteInInt = {0}; // NDS=020EDCD0

#include "data/decompress_at.h"

static void DecompressAT_AppendByte(u8);
static void DecompressAT_Finish(void);
static u8 DecompressAT_GetByte(s32);
static void DecompressAT_Init(u32 *);
static u32 DecompressATGlobal(u32 *, s32, const u8 *);

// arm9.bin::02003148
u32 DecompressATFile(void *dst, s32 dstLen, OpenedFile *file)
{
    return DecompressAT(dst, dstLen, file->data);
}

// arm9.bin::02002CE4
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

// arm9.bin::02002CD4
u32 DecompressATGlobalFile(u32 *result, s32 resultLength, OpenedFile *file)
{
    return DecompressATGlobal(result, resultLength, file->data);
}

// arm9.bin::02002804
static u32 DecompressATGlobal(u32 *result, s32 resultLength, const u8 *compressedData)
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

// arm9.bin::020027C0
static void DecompressAT_Init(u32 *buffer)
{
    gDecompressBufferPtr = buffer;
    gDecompressBufferStart = buffer;
    gDecompressBufferCurrent = 0;
    gDecompressBufferByteInInt = 0;
}

// arm9.bin::02002754
static u8 DecompressAT_GetByte(s32 index)
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

// arm9.bin::020026DC
static void DecompressAT_AppendByte(u8 value)
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

// arm9.bin::020026AC
static void DecompressAT_Finish(void)
{
    if (gDecompressBufferByteInInt)
        *gDecompressBufferPtr = gDecompressBufferCurrent;
}
