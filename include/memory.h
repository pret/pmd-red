#ifndef GUARD_MEMORY_H
#define GUARD_MEMORY_H

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

void *MemoryAlloc(s32 size, s32 group);
void MemoryFree(void *a);

#endif // GUARD_MEMORY_H
