
// Includes
#include "global.h"
#include "code_800B540.h"

// Static type declarations

struct HeapInitArgs {
    u8 *ptr;
    u32 size;
};

struct MemoryBlock {
    u32 unk_00;
    u32 unk_04;
    struct MemoryBlock *next;
    u32 unk_0c;
    size_t unk_10;
    u8 *data;
    size_t unk_18;
    u32 unk_1c;
};

// Static RAM declarations

struct MemoryBlock *gUnknown_2000E88[8] = {};
u32 gUnknown_2000EA8 = 0;
struct MemoryBlock gUnknown_2000EB0 = {};
struct MemoryBlock gUnknown_2000ED0[24] = {};
u8 gUnknown_20011D0[0x24000] = {};

// Static ROM declarations

// .rodata

// .text

void InitHeapInternal(void);
void DoInitHeap(struct MemoryBlock *a0, struct HeapInitArgs *args, struct MemoryBlock *a2, size_t a3);

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
    DoInitHeap(&gUnknown_2000EB0, &args, gUnknown_2000ED0, sizeof gUnknown_2000EB0);
}

void DoInitHeap(struct MemoryBlock *a0, struct HeapInitArgs *args, struct MemoryBlock *a2, size_t a3)
{
    size_t size = args->size & ~3; // r9
    gUnknown_2000E88[gUnknown_2000EA8] = a0;
    gUnknown_2000EA8++;
    a0->data = args->ptr;
    a0->unk_18 = size;
    a0->unk_00 = 2;
    a0->unk_04 = 0;
    a0->next = a2;
    a0->unk_0c = 1;
    a0->unk_10 = a3;
    a2->unk_00 = 0;
    a2->unk_04 = 0;
    a2->unk_0c = (intptr_t)args->ptr;
    a2->unk_10 = size;
    a2->data = NULL;
    a2->next = NULL;
}

void InitSubHeap(struct MemoryBlock *a0, struct HeapInitArgs *srcArgs, size_t size)
{
    size_t size_ = size * 3;
    int r2 = ~3;
    size_t size__ = r2 & (srcArgs->size - size_ * 8);
    struct HeapInitArgs args = {srcArgs->ptr + size_ * 8, size__};
    DoInitHeap(a0, &args, (struct MemoryBlock *)srcArgs->ptr, size);
}
