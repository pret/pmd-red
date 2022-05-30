#include "global.h"

extern u32 sub_8030DA0(void);
extern void sub_8030DE4();
extern void sub_80310E4(u32);


void sub_8031498(void)
{
    switch(sub_8030DA0())
    {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
            sub_8030DE4();
            sub_80310E4(0);
            break;
    }
}
