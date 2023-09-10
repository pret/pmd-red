#ifndef GUARD_POST_OFFICE_GUIDE1_H
#define GUARD_POST_OFFICE_GUIDE1_H

#include "file_system.h"

// size: 0x18
typedef struct PostOfficeWork
{
    /* 0x0 */ u8 state;
    /* 0x4 */ s32 currMenuChoice;
    /* 0x8 */ OpenedFile *faceFile;
    /* 0xC */ u8 *faceData;
    u16 unk10;
    u16 unk12;
    u8 unk14;
    u8 unk15;
    u8 unk16;
} PostOfficeWork;

void CleanHelperPelipper(void);
bool8 CreateHelperPelipperMenu(s16 speciesID);
u32 HelperPelipperCallback(void);

#endif // GUARD_POST_OFFICE_GUIDE1_H