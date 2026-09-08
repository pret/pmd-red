// platform/pc/cpu_pc.h — host BIOS/DMA/vblank replacements.
#ifndef PMDRED_PC_CPU_PC_H
#define PMDRED_PC_CPU_PC_H

#ifdef __cplusplus
extern "C" {
#endif

void Pc_MemInit(void);
void Pc_VBlankCommit(void);
void Pc_RequestVBlank(void);
void Pc_DmaCopy(const void *src, void *dest, unsigned size);
void Pc_DmaFill(unsigned value, void *dest, unsigned size);
// Abort with a message when a not-yet-ported host stub is reached.
void Pc_StubAbort(const char *what);
// Host heap trace (no-op on GBA builds): ring log of game-heap allocs.
void Pc_HeapTrace(void *ptr, int size, unsigned group);
void Pc_HeapTraceDump(void);

#ifdef __cplusplus
}
#endif
#endif
