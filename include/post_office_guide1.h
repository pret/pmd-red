#ifndef GUARD_POST_OFFICE_GUIDE1_H
#define GUARD_POST_OFFICE_GUIDE1_H

#include "structs/str_mon_portrait.h"

// size: 0x18
typedef struct PostOfficeWork
{
    /* 0x0 */ u8 state;
    /* 0x4 */ s32 currMenuChoice;
    /* 0x8 */ MonPortraitMsg monPortrait;
} PostOfficeWork;

void CleanHelperPelipper(void);
bool8 CreateHelperPelipperMenu(s16 speciesID);
u32 HelperPelipperCallback(void);

#endif // GUARD_POST_OFFICE_GUIDE1_H
