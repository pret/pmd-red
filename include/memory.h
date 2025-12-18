#ifndef GUARD_MEMORY_H
#define GUARD_MEMORY_H

enum MemAllocGroup
{
    // Only used for the Title Menu file
    MEMALLOC_GROUP_0,
    // Used for quicksave and save
    MEMALLOC_GROUP_5 = 5,
    // Used for "ground" and script files?
    MEMALLOC_GROUP_6,
    // Used for the dungeon loading?
    MEMALLOC_GROUP_7,
    // Used for menus and credits?
    MEMALLOC_GROUP_8,
    // Used for "effect" files?
    MEMALLOC_GROUP_11 = 11,
    // Only used for dungeon mon sprites
    MEMALLOC_GROUP_12,
};

void InitHeap(void);

void MemoryClear8(void *dest, s32 size);
void MemoryClear16(u16 *dest, s32 size);
void MemoryFill8(void *dest, u8 value, s32 size);
void MemoryFill16(u16 *dest, u16 value, s32 size);
void MemoryCopy8(void *dest, const void *src, s32 size);
void MemoryCopy32(u32 *dest, const u32 *src, s32 size);

// group: See enum "MemAllocGroup"
void *MemoryAlloc(s32 size, s32 group);
void MemoryFree(void *a);

#define FREE_AND_SET_NULL(ptr)          \
{                                       \
    MemoryFree(ptr);                    \
    ptr = NULL;                         \
}

#define TRY_FREE_AND_SET_NULL(ptr) if (ptr != NULL) FREE_AND_SET_NULL(ptr)

#endif // GUARD_MEMORY_H
