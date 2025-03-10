#ifndef GUARD_CPU_H
#define GUARD_CPU_H

void CpuClear(void *, s32);
void CpuCopy(void *dest, const void *src, s32 size);
void nullsub_23(bool8);
void SetWindowTitle(const u8 *);
void sub_800CDA8(u32);
u32 sub_800CDC8(void);
void VBlank_CB(void);

#endif //GUARD_CPU_H
