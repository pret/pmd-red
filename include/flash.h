#ifndef GUARD_FLASH_H
#define GUARD_FLASH_H

void InitFlash(void);
void ClearFlashData(void);
s32 ReadFlashData(s32 sector, u8 *dest, s32 size);
s32 WriteFlashData(s32 sector, u8 *src, s32 size);

#endif // GUARD_FLASH_H
