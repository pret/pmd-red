#include "global.h"
#include "text.h"

extern void sub_8272774(UnkTextStruct1 *r0, u32 r1);
extern void sub_8272884(UnkTextStruct1 *r0, u32 r1);

IWRAM_INIT void sub_8272760(u32 r0)
{
    sub_8272774(gUnknown_2027370, r0);
}

// Note: when decompiling make sure to add IWRAM_INIT before the function declaration just like in sub_8272760's case, so the compiler knows there to put the functions.

// TODO once sub_8272774 is decomped
//IWRAM_INIT void sub_8272870(u32 r0)
//{
//    sub_8272884(gUnknown_2027370, r0);
//}
