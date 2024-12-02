#include "global.h"
#include "globaldata.h"
#include "memory.h"
#include "cpu.h"
#include "debug.h"

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
    /* 0x10 */ s32 freeListLength;
    /* 0x14 */ u8 *start;
    /* 0x18 */ u32 size;
};

// size: 0x8
struct unkMemoryStruct
{
    struct HeapDescriptor *unk0;
    u32 end;
};

static EWRAM_DATA struct HeapDescriptor *sHeapDescriptorList[8] = {0};
static EWRAM_DATA s32 sHeapCount = {0};
UNUSED static EWRAM_DATA u32 sUnused1 = 0;
static EWRAM_DATA struct HeapDescriptor sMainHeapDescriptor = {0};
UNUSED static EWRAM_DATA u32 sUnused2 = 0;
static EWRAM_DATA struct HeapFreeListElement sMainHeapFreeList[32] = {0};
static EWRAM_DATA u8 sMainHeap[HEAP_SIZE] = {0};

static void DoFree(struct HeapDescriptor *, void *);
static void *DoAlloc(struct HeapDescriptor *, s32, u32);
static void DoInitHeap(struct HeapDescriptor *, struct HeapSettings *, struct HeapFreeListElement *, u32);
static void InitSubHeap(struct HeapDescriptor *, struct HeapMemoryBlock2 *, u32);
static struct HeapDescriptor *DoCreateSubHeap(struct unkMemoryStruct *a, u32 b);
static void *DoAlloc(struct HeapDescriptor *heap, s32 size, u32 a2);
static void InitHeapInternal(void);

ALIGNED(4) static const char sFileNameText[] = "../system/memory_locate.c";

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

static void InitHeapInternal(void)
{
    struct HeapSettings settings;

    settings.start = sMainHeap;
    settings.size = HEAP_SIZE;
    sHeapCount = 0;
    DoInitHeap(&sMainHeapDescriptor, &settings, sMainHeapFreeList, sizeof(sMainHeapFreeList) / sizeof(struct HeapFreeListElement));
}

static void DoInitHeap(struct HeapDescriptor *descriptor, struct HeapSettings *settings, struct HeapFreeListElement *freeList, u32 freeListLength)
{
    u32 aligned_size;

    aligned_size = settings->size & ~(3);

    sHeapDescriptorList[sHeapCount++] = descriptor;

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

static void InitSubHeap(struct HeapDescriptor *parentHeap, struct HeapMemoryBlock2 *block, u32 freeListMax)
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

static u32 xxx_memory_attr_related(u32 r0)
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

static s32 MemorySearchFromFront(struct HeapDescriptor *heap, s32 atb, s32 size)
{
    s32 i;
    struct HeapFreeListElement *curr;

    if (atb & 4) {
        i = 0;
        curr = &heap->freeList[0];

        for (; i < heap->freeCount; i++, curr++) {
            if (!(curr->atb & 1)) {
                if (curr->block.size >= size)
                    return i;

                break;
            }
        }

        for (; i < heap->freeCount; i++, curr++) {
            if (!(curr->atb & 1)) {
                if (curr->block.size >= size)
                    return i;
            }
        }

    }
    else {
        s32 ret = -1;
        s32 sizeMax = HEAP_SIZE + 1;
        i = 0;
        curr = &heap->freeList[0];

        for (; i < heap->freeCount; i++, curr++) {
            if (!(curr->atb & 1) && curr->block.size >= size && curr->block.size < sizeMax) {
                ret = i;
                sizeMax = curr->block.size;
            }
        }
        return ret;
    }

    return -1;
}

static s32 MemorySearchFromBack(struct HeapDescriptor *heap, s32 atb, s32 size)
{
    s32 i;
    struct HeapFreeListElement *curr;

    if (atb & 4) {
        i = heap->freeCount - 1;
        curr = &heap->freeList[i];

        for (; i >= 0; i--, curr--) {
            if (!(curr->atb & 1)) {
                if (curr->block.size >= size)
                    return i;

                break;
            }
        }

        for (; i >= 0; i--, curr--) {
            if (!(curr->atb & 1)) {
                if (curr->block.size >= size)
                    return i;
            }
        }

    }
    else {
        s32 ret = -1;
        s32 sizeMax = HEAP_SIZE + 1;
        i = heap->freeCount - 1;
        curr = &heap->freeList[i];

        for (; i >= 0; i--, curr--) {
            if (!(curr->atb & 1) && curr->block.size >= size && curr->block.size < sizeMax) {
                ret = i;
                sizeMax = curr->block.size;
            }
        }
        return ret;
    }

    return -1;
}

ALIGNED(4) static const char sText_LocateSetFront[] = "_LocateSetFront";
static const DebugLocation sLocateSetFrontDebugLocation =
{
    .file = sFileNameText,
    .line = 581,
    .func = sText_LocateSetFront
};

static struct HeapFreeListElement * _LocateSetFront(struct HeapDescriptor *heap, s32 index, s32 atb, s32 size, s32 group)
{
    s32 i;
    struct HeapFreeListElement *curr;
    struct HeapFreeListElement *block;
    s32 sizeAligned;

    sizeAligned = size + 3;
    sizeAligned &= ~(3);
    curr = &heap->freeList[index];
    if (curr->block.size > sizeAligned) {
        i = heap->freeCount;
        block = &heap->freeList[heap->freeCount];
        for (; i > index; i--, block--) {
            block[0] = block[-1];
        }

        heap->freeCount++;
        if (heap->freeCount > heap->freeListLength) {
            FatalError(&sLocateSetFrontDebugLocation, "Memory Locate sprit max over [%3d/%3d]", heap->freeCount, heap->freeListLength);
        }

        block = &heap->freeList[index + 1];
        block->block.start += sizeAligned;
        block->block.size -= sizeAligned;

        curr->block.size = sizeAligned;
        curr->block.allocatedSize = size;
    }

    curr->unk_atb = xxx_memory_attr_related(atb);
    curr->atb = atb;
    curr->grp = group;
    return curr;
}

ALIGNED(4) static const char sText_LocateSetBack[] = "_LocateSetBack";
static const DebugLocation sLocateSetBackDebugLocation =
{
    .file = sFileNameText,
    .line = 673,
    .func = sText_LocateSetBack
};

static struct HeapFreeListElement * _LocateSetBack(struct HeapDescriptor *heap, s32 index, s32 atb, s32 size, s32 group)
{
    s32 i;
    struct HeapFreeListElement *curr;
    struct HeapFreeListElement *block;
    s32 sizeAligned;
    u8 *newBlockStart;

    sizeAligned = size + 3;
    sizeAligned &= ~(3);
    curr = &heap->freeList[index];
    if (curr->block.size > sizeAligned) {
        i = heap->freeCount;
        block = &heap->freeList[heap->freeCount];
        for (; i > index; i--, block--) {
            block[0] = block[-1];
        }

        heap->freeCount++;
        if (heap->freeCount > heap->freeListLength) {
            FatalError(&sLocateSetBackDebugLocation, "Memory Locate sprit max over [%3d/%3d]", heap->freeCount, heap->freeListLength);
        }

        curr->block.size -= sizeAligned;
        newBlockStart = curr->block.size + curr->block.start;

        curr++;
        curr->block.start = newBlockStart;
        curr->block.size = sizeAligned;
        curr->block.allocatedSize = size;
    }

    curr->unk_atb = xxx_memory_attr_related(atb);
    curr->atb = atb;
    curr->grp = group;
    return curr;
}

ALIGNED(4) static const char sText_LocateSet[] = "_LocateSet";
static const DebugLocation sLocateSetDebugLocation =
{
    .file = sFileNameText,
    .line = 812,
    .func = sText_LocateSet
};

static void * _LocateSet(struct HeapDescriptor *heap, s32 size, s32 group)
{
  s32 index;
  struct HeapFreeListElement * foundSet;
  s32 atb;

  if (heap == NULL) {
    heap = &sMainHeapDescriptor;
  }

  // Set some sort flag/attr?
  atb = group >> 8 | 1;

  // Reset it?
  group = group & 0xff;

  if ((atb & 2) != 0) {
    index = MemorySearchFromFront(heap,atb,size);
    if (index < 0) goto error;
    foundSet = _LocateSetFront(heap,index,atb,size,group);
    return foundSet->block.start;
  }
  else {
    index = MemorySearchFromBack(heap,atb,size);
    if (index < 0) goto error;
    foundSet = _LocateSetBack(heap,index,atb,size,group);
    return foundSet->block.start;
  }

error:
   FatalError(&sLocateSetDebugLocation,
                 "Memroy LocateSet [%p] buffer %8x size can't locate\n    atb %02x grp %3d ", // Spelling error is intentional
                 heap,size,atb,group);
}

void *MemoryAlloc(s32 size, s32 group)
{
    DoAlloc(&sMainHeapDescriptor, size, group);
}

void MemoryFree(void *a)
{
    DoFree(&sMainHeapDescriptor, a);
}

ALIGNED(4) static const char sText_MemoryLocate_LocalCreate[] = "MemoryLocate_LocalCreate";

UNUSED static struct HeapDescriptor *MemoryLocate_LocalCreate(struct HeapDescriptor *parentHeap,u32 size,u32 param_3,u32 group)
{
  int index;
  struct HeapFreeListElement *foundSet;
  struct HeapDescriptor *iVar3;
  struct unkMemoryStruct local_1c;

  if (parentHeap == NULL) {
    parentHeap = &sMainHeapDescriptor;
  }

  index = MemorySearchFromBack(parentHeap,9,size);
  if (index < 0) {
    static const DebugLocation debugInfo = {
        .file = sFileNameText,
        .line = 1109,
        .func = sText_MemoryLocate_LocalCreate
    };
    FatalError(&debugInfo,"Memroy LocalCreate buffer %08x size can't locate",size); // Spelling error is intentional
  }

  foundSet = _LocateSetBack(parentHeap,index,9,size,group);
  local_1c.unk0 = (void *) foundSet->block.start;
  local_1c.end = foundSet->block.size;

  iVar3 = DoCreateSubHeap(&local_1c,param_3);
  iVar3->parentHeap = parentHeap;
  return iVar3;
}

static struct HeapDescriptor *DoCreateSubHeap(struct unkMemoryStruct *a, u32 b)
{
    struct HeapMemoryBlock2 s2;
    struct HeapDescriptor *a1;

    a1 = a->unk0;
    s2.start = (struct HeapFreeListElement *)((u8*)a1 + sizeof(struct HeapDescriptor));
    s2.size = a->end - sizeof(struct HeapDescriptor);
    InitSubHeap(a1, &s2, b);
    return a1;
}

UNUSED static void xxx_unused_memory_free(struct HeapDescriptor *a1)
{
    bool8 b;
    s32 i;
    bool8 temp;

    if (a1 == NULL)
        return;

    b = FALSE;
    if (a1->freeCount == 1 && a1->freeList->atb == 0)
        b = TRUE;

    if (b) {
        temp = FALSE;
        i = 0;
        for (; i < sHeapCount; i++) {
            if (sHeapDescriptorList[i] == a1) {
                sHeapCount--;
                for (; i < sHeapCount; i++) {
                    sHeapDescriptorList[i] = sHeapDescriptorList[i + 1];
                }
                temp = TRUE;
                break;
            }
        }
        if (temp && a1->parentHeap != NULL)
            DoFree(a1->parentHeap, a1);
    }
}

static void *DoAlloc(struct HeapDescriptor *heap, s32 size, u32 a2)
{
    return _LocateSet(heap, size, a2 | 0x100);
}

static void DoFree(struct HeapDescriptor *heapDescriptior, void *ptrToFree)
{
    struct HeapFreeListElement *curr;
    struct HeapFreeListElement *next;
    struct HeapFreeListElement *prev;
    s32 i;

    if (heapDescriptior == NULL)
        heapDescriptior = &sMainHeapDescriptor;

    if (ptrToFree == NULL)
        return;

    i = 0;
    curr = &heapDescriptior->freeList[0];
    for (; i < heapDescriptior->freeCount; i++, curr++) {
        if (curr->block.start == (u8 *)ptrToFree) {
            curr->unk_atb = 0;
            curr->atb = 0;
            curr->block.allocatedSize = 0;
            curr->grp = 0;

            if (i < heapDescriptior->freeCount - 1) {
                s32 j;

                next = curr + 1;
                if (next->atb == 0) {
                    curr->block.size += next->block.size;
                    heapDescriptior->freeCount--;
                    for (j = i + 1; j < heapDescriptior->freeCount; j++, next++)
                        next[0] = next[1];
                }
            }

            if (i >= 1) {
                s32 j;
                prev = curr - 1;
                if (prev->atb == 0) {
                    prev->block.size += curr->block.size;
                    heapDescriptior->freeCount--;
                    prev = curr;
                    for (j = i; j < heapDescriptior->freeCount; j++, prev++)
                        prev[0] = prev[1];
                }
            }

            break;
        }
    }
}

UNUSED static void nullsub_141(void)
{

}

UNUSED static void nullsub_142(void)
{

}
