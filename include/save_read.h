#ifndef GUARD_SAVE_READ_H
#define GUARD_SAVE_READ_H

// size: 0x8
struct SavePakRead
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 readStatus;
};

void PrepareSavePakRead(void);
bool8 ReadSavePak(void);
void FinishReadSavePak(void);

#endif // GUARD_SAVE_READ_H