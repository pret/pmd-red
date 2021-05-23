#include "global.h"

extern u32 sub_801B410();
extern void sub_801B450();
extern void sub_8017F10(u32);

void sub_8018AC8(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(0x5);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}

void sub_8018AE4(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(0xB);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}
