#include "global.h"

extern u32 sub_8016080(void);
extern void sub_803ACD0(u32);
extern void sub_80160D8(void);

void sub_803B034(void)
{
    switch(sub_8016080())
    {
        case 2:
        case 3:
            sub_80160D8();
            sub_803ACD0(2);
            break;
    }
}
