#include "global.h"
#include "memory.h"

extern u32 gUnknown_80B7F14;
extern u32 gUnknown_80B7F20;
extern struct HeapDescriptor gMainHeapDescriptor;

extern s32 MemorySearchFromBack(struct HeapDescriptor *heap, s32, s32);
extern s32 MemorySearchFromFront(struct HeapDescriptor *heap, s32, s32);
extern struct HeapDescriptor * _LocateSetBack(struct HeapDescriptor *, u32, u32, u32, u32);
extern struct HeapDescriptor * _LocateSetFront(struct HeapDescriptor *, u32, u32, u32, u32);
void DoFree(struct HeapDescriptor *, void *);
void *DoAlloc(struct HeapDescriptor *, s32, u32);

void FatalError(u32 *, u32 *, ...) __attribute__((noreturn));


s32 _LocateSet(struct HeapDescriptor *heap, s32 size, s32 param_3)
{
  s32 index;
  struct HeapDescriptor * uVar2;
  s32 uVar3;
  
  if (heap == NULL) {
    heap = &gMainHeapDescriptor;
  }

  // Set some sort flag/attr?
  uVar3 = param_3 >> 8 | 1;

  // Reset it?
  param_3 = param_3 & 0xff;

  if ((uVar3 & 2) != 0) {
    index = MemorySearchFromFront(heap,uVar3,size);
    if (index < 0) goto error;
    uVar2 = _LocateSetFront(heap,index,uVar3,size,param_3);
    return uVar2->freeCount;
  }
  else {
    index = MemorySearchFromBack(heap,uVar3,size);
    if (index < 0) goto error;
    uVar2 = _LocateSetBack(heap,index,uVar3,size,param_3);
    return uVar2->freeCount;
  }

error:
    // LocateSet [%p] buffer %8x size can't locate
        // atb %02x grp %3d
   FatalError(&gUnknown_80B7F14,
                 &gUnknown_80B7F20,
                 heap,size,uVar3,param_3);
}

void *MemoryAlloc(s32 size, s32 b)
{
    DoAlloc(&gMainHeapDescriptor, size, b);
}

void MemoryFree(void *a)
{
    DoFree(&gMainHeapDescriptor, a);
}
