#ifndef GUARD_MEMORY_H
#define GUARD_MEMORY_H

void InitHeap(void);

void MemoryClear8(void *dest, s32 size);
void MemoryClear16(u16 *dest, s32 size);
void MemoryFill8(void *dest, u8 value, s32 size);
void MemoryFill16(u16 *dest, u16 value, s32 size);
void MemoryCopy8(void *dest, void *src, s32 size);
void MemoryCopy32(u32 *dest, u32 *src, s32 size);

void *MemoryAlloc(s32 size, s32 group);
void MemoryFree(void *a);

#define FREE_AND_SET_NULL(ptr)          \
{                                       \
    MemoryFree(ptr);                    \
    ptr = NULL;                         \
}

#define TRY_FREE_AND_SET_NULL(ptr) if (ptr != NULL) FREE_AND_SET_NULL(ptr)

#endif // GUARD_MEMORY_H
