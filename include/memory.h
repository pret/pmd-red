#ifndef GUARD_MEMORY_H
#define GUARD_MEMORY_H

#define HEAP_SIZE 0x24000

struct HeapSettings
{
    u8 *start;
    u32 size;
};

struct HeapMemoryBlock {
    u8 *start;
    s32 size;
    s32 allocatedSize;
};

struct HeapFreeListElement
{
    u32 unk_atb;
    u32 atb;
    u32 grp;
    struct HeapMemoryBlock block;
};

struct HeapDescriptor
{
    u32 unk0;
    struct HeapDescriptor *parentHeap;
    struct HeapFreeListElement *freeList;
    s32 freeCount;
    u32 freeListLength;
    u8 *start;
    u32 size;
};

void InitHeap(void);

void MemoryClear8(u8 *dest, s32 size);
void MemoryClear16(u16 *dest, s32 size);
void MemoryClear32(u32 *dest, s32 size);
void MemoryFill8(u8 *dest, u8 value, s32 size);
void MemoryFill16(u16 *dest, u16 value, s32 size);
void MemoryFill32(u32 *dest, u32 value, s32 size);
void MemoryCopy8(u8 *dest, u8 *src, s32 size);
void MemoryCopy16(u16 *dest, u16 *src, s32 size);
void MemoryCopy32(u32 *dest, u32 *src, s32 size);
void MemoryCopy8(u8 *dest, u8 *src, s32 size);
void MemoryCopy16(u16 *dest, u16 *src, s32 size);
void MemoryCopy32(u32 *dest, u32 *src, s32 size);

void InitHeapInternal(void);
void DoInitHeap(struct HeapDescriptor *, struct HeapSettings *, struct HeapFreeListElement *, u32);
void InitSubHeap(struct HeapDescriptor *, struct HeapMemoryBlock *, u32);

#endif // GUARD_MEMORY_H
