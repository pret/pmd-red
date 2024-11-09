#include "global.h"
#include "code_8092334.h"
#include "memory.h"
#include "items.h"


s16 sub_8094828(u16 moveID, u8 id)
{
    if(id != 0)
    {
        if(GetItemCategory(id) == CATEGORY_ORBS)
            return 0x223;
        else
            return 0x224;
    }
    else
    {
        return moveID;
    }
}



// New file here


void InitBitReader(DataSerializer *r0, u8 *buffer, s32 bufLen)
{
    r0->stream = buffer;
    r0->count = 0;
    r0->unkC = 0;
    r0->end = buffer + bufLen;
}

void InitBitWriter(DataSerializer *r0, u8 *buffer, s32 bufLen)
{
    r0->stream = buffer;
    r0->count = 0;
    r0->unkC = 0;
    r0->end = buffer + bufLen;
    MemoryClear8(buffer, bufLen);
}

// Finish reading/writing bits
void nullsub_102(DataSerializer *r0)
{

}

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

UNUSED void sub_80948E4(DataSerializer *seri, void *src, s32 numBytes)
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