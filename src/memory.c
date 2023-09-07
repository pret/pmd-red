#include "global.h"
#include "cpu.h"
#include "memory.h"

EWRAM_DATA struct HeapDescriptor *gHeapDescriptorList[8] = {0}; // 2000E88
EWRAM_DATA u32 gHeapCount = {0}; // 2000EA8
// space of 4?
EWRAM_DATA struct HeapDescriptor gMainHeapDescriptor = {0}; // 2000EB0
// space of 4?
extern struct HeapFreeListElement gMainHeapFreeList[32]; // 2000ED0
extern u8 gMainHeap[HEAP_SIZE]; // 20011D0

void InitHeapInternal(void);

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

void InitHeapInternal(void)
{
    struct HeapSettings settings;

    settings.start = gMainHeap;
    settings.size = HEAP_SIZE;
    gHeapCount = 0;
    DoInitHeap(&gMainHeapDescriptor, &settings, gMainHeapFreeList, sizeof(gMainHeapFreeList) / sizeof(struct HeapFreeListElement));
}

void DoInitHeap(struct HeapDescriptor *descriptor, struct HeapSettings *settings, struct HeapFreeListElement *freeList, u32 freeListLength)
{
    u32 aligned_size;

    aligned_size = settings->size & 0xFFFFFFFC;

    gHeapDescriptorList[gHeapCount++] = descriptor;

    descriptor->start = settings->start;
    descriptor->size = aligned_size;
    descriptor->unk0 = 2;
    descriptor->parentHeap = NULL;
    descriptor->freeList = freeList;
    descriptor->freeCount = 1;
    descriptor->freeListLength = freeListLength;

    freeList->unk_atb = 0;
    freeList->atb = 0;
    freeList->block.start = descriptor->start;
    freeList->block.size = aligned_size;
    freeList->block.allocatedSize = 0;
    freeList->grp = 0;
}

void InitSubHeap(struct HeapDescriptor *parentHeap, struct HeapMemoryBlock *block, u32 freeListMax)
{
    u32 freeListSize;
    u32 aligned_size;
    u32 alignment;
    struct HeapFreeListElement *freeList;
    struct HeapSettings settings;

    freeListSize = freeListMax * 3;
    alignment = ~3;
    freeListSize *= 8;
    aligned_size = (block->size - freeListSize) & alignment;
    freeList = (struct HeapFreeListElement *)block->start;
    settings.start = &((u8 *)block->start)[freeListSize];
    settings.size = aligned_size;
    DoInitHeap(parentHeap, &settings, freeList, freeListMax);
}

u8 xxx_memory_attr_related(u32 r0)
{
    u32 temp;
    u32 return_var;
    if(r0 == 0)
    {
        return 0;
    }
    if((r0 & 8) != 0)
    {
        return 4;
    }

    temp = r0 & 7;
    if(temp == 7)
    {
        return_var = 1;;
    }
    else if(temp == 1)
    {
        return_var = 2;
    }
    else if(temp == 3)
    {
        return_var = 3;
    }
    else 
    {
        return_var = 5;
    }
    return return_var;
}
