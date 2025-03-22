#ifndef GUARD_SAVE_WRITE_H
#define GUARD_SAVE_WRITE_H

void FinishWriteSavePak(void);
u32 GetSavePakStatus(void);
void PrepareSavePakWrite(s16 pokemonID);
bool8 WriteSavePak(void);

#endif // GUARD_SAVE_WRITE_H
