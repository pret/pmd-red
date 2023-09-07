#ifndef GUARD_QUICK_SAVE_READ_H
#define GUARD_QUICK_SAVE_READ_H

// size: 0x10
typedef struct QuickSaveRead
{
    /* 0x0 */ s32 state;
    /* 0x4 */ u8 *dest;
    /* 0x8 */ u32 size;
    /* 0xC */ bool8 saveValid;
} QuickSaveRead;

void FinishQuickSaveRead(void);
bool8 IsQuickSaveValid(void);
void PrepareQuickSaveRead(u8 *, u32);
bool8 ReadQuickSave(void);

#endif // GUARD_QUICK_SAVE_READ_H