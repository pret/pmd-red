#include "global.h"
#include "memory.h"

extern u32 gUnknown_80B7F14;
extern u32 gUnknown_80B7F88;
extern const char gLocateSetErrorMessage[];
extern struct HeapDescriptor gMainHeapDescriptor;
extern const char gLocalCreateErrorMessage[];

extern s32 MemorySearchFromBack(struct HeapDescriptor *heap, s32, s32);
extern s32 MemorySearchFromFront(struct HeapDescriptor *heap, s32, s32);
extern struct unkMemoryStruct2 * _LocateSetBack(struct HeapDescriptor *, u32, u32, u32, u32);
extern struct unkMemoryStruct2 * _LocateSetFront(struct HeapDescriptor *, u32, u32, u32, u32);
void DoFree(struct HeapDescriptor *, void *);
void *DoAlloc(struct HeapDescriptor *, s32, u32);

void FatalError(u32 *, const char *, ...) __attribute__((noreturn));


struct HeapDescriptor* _LocateSet(struct HeapDescriptor *heap, s32 size, s32 group)
{
  s32 index;
  struct unkMemoryStruct2 * uVar2;
  s32 atb;

  if (heap == NULL) {
    heap = &gMainHeapDescriptor;
  }

  // Set some sort flag/attr?
  atb = group >> 8 | 1;

  // Reset it?
  group = group & 0xff;

  if ((atb & 2) != 0) {
    index = MemorySearchFromFront(heap,atb,size);
    if (index < 0) goto error;
    uVar2 = _LocateSetFront(heap,index,atb,size,group);
    return uVar2->unkC;
  }
  else {
    index = MemorySearchFromBack(heap,atb,size);
    if (index < 0) goto error;
    uVar2 = _LocateSetBack(heap,index,atb,size,group);
    return uVar2->unkC;
  }

error:
    // LocateSet [%p] buffer %8x size can't locate
        // atb %02x grp %3d
   FatalError(&gUnknown_80B7F14,
                 gLocateSetErrorMessage,
                 heap,size,atb,group);
}

void *MemoryAlloc(s32 size, s32 group)
{
    DoAlloc(&gMainHeapDescriptor, size, group);
}

void MemoryFree(void *a)
{
    DoFree(&gMainHeapDescriptor, a);
}

struct HeapDescriptor *MemoryLocate_LocalCreate(struct HeapDescriptor *parentHeap,u32 size,u32 param_3,u32 group)
{
  int index;
  struct unkMemoryStruct2 *iVar2;
  struct HeapDescriptor *iVar3;
  struct unkMemoryStruct local_1c;

  if (parentHeap == NULL) {
    parentHeap = &gMainHeapDescriptor;
  }

  index = MemorySearchFromBack(parentHeap,9,size);
  if (index < 0)
    // Memroy LocalCreate buffer %08x size can't locate
    FatalError(&gUnknown_80B7F88,gLocalCreateErrorMessage,size);

  iVar2 = _LocateSetBack(parentHeap,index,9,size,group);
  local_1c.unk0 = iVar2->unkC;
  local_1c.end = iVar2->end;

  iVar3 = DoCreateSubHeap(&local_1c,param_3);
  iVar3->parentHeap = parentHeap;
  return iVar3;
}

struct HeapDescriptor *DoCreateSubHeap(struct unkMemoryStruct *a, u32 b)
{
    struct HeapMemoryBlock2 s2;
    struct HeapDescriptor *a1;
    u32 end;

    a1 = a->unk0;
    s2.start = (struct HeapFreeListElement *)((u8*)a1 + sizeof(struct HeapDescriptor));
    end = a->end;
    s2.size = end - sizeof(struct HeapDescriptor);
    InitSubHeap(a1, &s2, b);
    return a1;
}

void xxx_unused_memory_free(struct HeapDescriptor *a1)
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
        for (; i < gHeapCount; i++) {
            if (gHeapDescriptorList[i] == a1) {
                gHeapCount--;
                for (; i < gHeapCount; i++) {
                    gHeapDescriptorList[i] = gHeapDescriptorList[i + 1];
                }
                temp = TRUE;
                break;
            }
        }
        if (temp && a1->parentHeap != NULL)
            DoFree(a1->parentHeap, a1);
    }
}

void *DoAlloc(struct HeapDescriptor *heap, s32 size, u32 a2)
{
    return _LocateSet(heap, size, a2 | 0x100);
}
