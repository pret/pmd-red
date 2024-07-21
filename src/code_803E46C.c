#include "global.h"
#include "code_803E46C.h"

#include "code_803E668.h"

extern u8 gUnknown_203B40C;

extern void sub_803E490(u32);

void sub_803E46C(u32 a0)
{
    if (gUnknown_203B40C != 0)
        sub_803E490(a0);
    else
        sub_803E668(a0);
}
