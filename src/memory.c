
// Includes
#include "global.h"
#include "code_800B540.h"

// Static type declarations

struct HeapInitArgs {
    void *ptr;
    u32 size;
};

// Static RAM declarations

u32 gUnknown_2000EA8 = 0;
u8 gUnknown_2000EB0[0x20] = {};
u8 gUnknown_2000ED0[0x300] = {};
u8 gUnknown_20011D0[0x24000] = {};

// Static ROM declarations

// .rodata

// .text

void InitHeapInternal(void);
void DoInitHeap(void *a0, struct HeapInitArgs *args, void *a2, size_t a3);

void InitHeap(void)
{
    InitHeapInternal();
}

void MemoryClear8(u8 *dst, int size)
{
    while (size > 0)
    {
        size -= 1;
        *dst++ = 0;
    }
}

void MemoryClear16(u16 *dst, int size)
{
    while (size > 0)
    {
        size -= 2;
        *dst++ = 0;
    }
}

void MemoryClear32(u32 *dst, int size)
{
    CpuClear(dst, size);
}

void MemoryFill8(u8 *dst, u8 val, int size)
{
    while (size > 0)
    {
        size -= 1;
        *dst++ = val;
    }
}

void MemoryFill16(u16 *dst, u16 val, int size)
{
    while (size > 0)
    {
        size -= 2;
        *dst++ = val;
    }
}

void MemoryFill32(u32 *dst, u32 val, int size)
{
    while (size > 0)
    {
        size -= 4;
        *dst++ = val;
    }
}

void MemoryCopy8(u8 *dst, const u8 *src, int size)
{
    while (size > 0)
    {
        size -= 1;
        *dst++ = *src++;
    }
}

void MemoryCopy16(u16 *dst, const u16 *src, int size)
{
    while (size > 0)
    {
        size -= 2;
        *dst++ = *src++;
    }
}

void MemoryCopy32(u32 *dst, const u32 *src, int size)
{
    while (size > 0)
    {
        size -= 4;
        *dst++ = *src++;
    }
}

void InitHeapInternal(void)
{
    struct HeapInitArgs args;
    args.ptr = gUnknown_20011D0;
    args.size = sizeof gUnknown_20011D0;
    gUnknown_2000EA8 = 0;
    DoInitHeap(gUnknown_2000EB0, &args, gUnknown_2000ED0, sizeof gUnknown_2000EB0);
}
