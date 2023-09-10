#ifndef GUARD_QUICK_SAVE_WRITE_H
#define GUARD_QUICK_SAVE_WRITE_H

// size: 0x14
typedef struct QuickSaveWrite
{
    /* 0x0 */ s32 state;
    u8 *unk4;
    u32 unk8;
    u8 unkC;
    /* 0x10 */ u32 quickSaveStatus;
} QuickSaveWrite;

void FinishQuickSaveWrite(void);
void PrepareQuickSaveWrite(u8 *, u32, u8);
u32 WriteQuickSave(void);

#endif // GUARD_QUICK_SAVE_WRITE_H