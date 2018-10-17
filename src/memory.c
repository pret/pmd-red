#include "global.h"

extern void InitHeapInternal(void);
extern void CpuClear(u32 *dest, s32 size);

void InitHeap(void)
{
    InitHeapInternal();
}

void MemoryClear8(u8 *dest, s32 size)
{
    while (size > 0)
    {
        size -= 1;
        *dest++ = 0;
    }
}

void MemoryClear16(u16 *dest, s32 size)
{
    while (size > 0)
    {
        size -= 2;
        *dest++ = 0;
    }
}
void MemoryClear32(u32 *dest, s32 size)
{
    CpuClear(dest, size);
}

void MemoryFill8(u8 *dest, u8 value, s32 size)
{
    while (size > 0)
    {
        size -= 1;
        *dest++ = value;
    }
}

void MemoryFill16(u16 *dest, u16 value, s32 size)
{
    while (size > 0)
    {
        size -= 2;
        *dest++ = value;
    }
}

void MemoryFill32(u32 *dest, u32 value, s32 size)
{
    while (size > 0)
    {
        size -= 4;
        *dest++ = value;
    }
}

void MemoryCopy8(u8 *dest, u8 *src, s32 size)
{
    while (size > 0)
    {
        size -= 1;
        *dest++ = *src++;
    }
}

void MemoryCopy16(u16 *dest, u16 *src, s32 size)
{
    while (size > 0)
    {
        size -= 2;
        *dest++ = *src++;
    }
}

void MemoryCopy32(u32 *dest, u32 *src, s32 size)
{
    while (size > 0)
    {
        size -= 4;
        *dest++ = *src++;
    }
}