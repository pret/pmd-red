#include "global.h"

extern void sub_8272774(u32 *r0, u32 r1);
extern void sub_8272884(u32 *r0, u32 r1);

extern u32 gUnknown_2027370; // TODO defined in text.c and join later

void sub_8272760(u32 r0)
{
    sub_8272774(&gUnknown_2027370, r0);
}

// TODO once sub_8272774 is decomped
//void sub_8272870(u32 r0)
//{
//    sub_8272884(&gUnknown_2027370, r0);
//}
