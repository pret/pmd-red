#ifndef GUARD_GBA_FLASH_H
#define GUARD_GBA_FLASH_H

typedef void (*FlashIntrFunc)(void);

extern u16 (*ProgramFlashSector)(u16, u8 *);
extern u16 (*EraseFlashChip)(void);
extern u16 (*EraseFlashSector)(u16);

u16 IdentifyFlash(void);
u16 SetFlashTimerIntr(u8 timerNum, FlashIntrFunc *func);
void ReadFlash(u16 sectorNum, u32 offset, u8 *dest, u32 size);
u32 VerifyFlashSector(u16 sectorNum, u8 *src);
u32 VerifyFlashSectorNBytes(u16 sectorNum, u8 *src, u32 n);
u32 ProgramFlashSectorAndVerify(u16 sectorNum, u8 *src);
u32 ProgramFlashSectorAndVerifyNBytes(u16 sectorNum, u8 *src, u32 n);

#endif // GUARD_GBA_FLASH_H
