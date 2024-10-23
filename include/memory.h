#ifndef GUARD_MEMORY_H
#define GUARD_MEMORY_H

#define HEAP_SIZE 0x24000

// size: 0x8
struct HeapSettings
{
    /* 0x0 */ u8 *start;
    /* 0x4 */ u32 size;
};

// size: 0xC
struct HeapMemoryBlock
{
    /* 0x0 */ u8 *start;
    /* 0x4 */ s32 size;
    /* 0x8 */ s32 allocatedSize;
};

// size: 0x8
struct HeapMemoryBlock2
{
    /* 0x0 */ struct HeapFreeListElement *start;
    /* 0x4 */ s32 size;
};

// size: 0x10
struct HeapFreeListElement
{
    /* 0x0 */ u32 unk_atb;
    /* 0x4 */ u32 atb;
    /* 0x8 */ u32 grp;
    /* 0xC */ struct HeapMemoryBlock block;
};

// size: 0x1C
struct HeapDescriptor
{
    u32 unk0;
    /* 0x4 */ struct HeapDescriptor *parentHeap;
    /* 0x8 */ struct HeapFreeListElement *freeList;
    /* 0xC */ s32 freeCount;
    /* 0x10 */ u32 freeListLength;
    /* 0x14 */ u8 *start;
    /* 0x18 */ u32 size;
};

// size: 0x8
struct unkMemoryStruct
{
    struct HeapDescriptor *unk0;
    u32 end;
};

// size: 0x1C
struct unkMemoryStruct2
{
    u8 fill[0xC];
    /* 0xC */ struct HeapDescriptor *unkC;
    /* 0x10 */ u32 end;
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
void InitSubHeap(struct HeapDescriptor *, struct HeapMemoryBlock2 *, u32);
struct HeapDescriptor * _LocateSet(struct HeapDescriptor *heap, s32 size, s32 param_3);
void *MemoryAlloc(s32 size, s32 group);
void MemoryFree(void *a);
struct HeapDescriptor *DoCreateSubHeap(struct unkMemoryStruct *a, u32 b);

#endif // GUARD_MEMORY_H
