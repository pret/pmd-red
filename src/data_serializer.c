#include "global.h"
#include "globaldata.h"
#include "data_serializer.h"
#include "memory.h"
#include "items.h"

// arm9.bin::02064998
void InitBitReader(DataSerializer *r0, u8 *buffer, s32 bufLen)
{
    r0->stream = buffer;
    r0->count = 0;
    r0->unkC = 0;
    r0->end = buffer + bufLen;
}

// arm9.bin::0206496C
void InitBitWriter(DataSerializer *r0, u8 *buffer, s32 bufLen)
{
    r0->stream = buffer;
    r0->count = 0;
    r0->unkC = 0;
    r0->end = buffer + bufLen;
    MemoryClear8(buffer, bufLen);
}

// arm9.bin::02064968
void FinishBitSerializer(DataSerializer *seri)
{
}

// arm9.bin::020648D0
void WriteBits(DataSerializer *r0, void *src, s32 numBits)
{
    s32 curBit;
    u8 *curByte;

    curBit = 0;
    curByte = src;

    while (numBits != 0) {
        if ((*curByte >> curBit) & 1)
            *r0->stream |= (1 << r0->count);

        curBit++;
        if (curBit == 8) {
            curByte++;
            curBit = 0;
        }

        r0->count++;
        if (r0->count == 8) {
            r0->stream++;
            r0->count = 0;
        }

        r0->unkC++;
        numBits--;
    }
}

static UNUSED void sub_80948E4(DataSerializer *seri, void *src, s32 numBytes)
{
    s32 iVar1;
    u8 *curByte;

    curByte = src;

    while (numBytes != 0) {
        iVar1 = (*curByte << seri->count);
        *seri->stream |= iVar1;
        seri->stream++;
        *seri->stream |= iVar1 >> 8;
        curByte++;
        seri->unkC += 8;
        numBytes--;
    }
}

// arm9.bin::0206482C
void ReadBits(DataSerializer *r0, void *dst, s32 numBits)
{
    s32 curBit;
    u8 *curByte;

    curBit = 0;
    curByte = dst;

    while (numBits != 0) {
        if (curBit == 0)
            *curByte = 0;

        if ((*r0->stream >> r0->count) & 1)
            *curByte |= (1 << curBit);

        curBit++;
        if (curBit == 8) {
            curByte++;
            curBit = 0;
        }

        r0->count++;
        if (r0->count == 8) {
            r0->stream++;
            r0->count = 0;
        }

        r0->unkC++;
        numBits--;
    }
}
