#include "global.h"

extern void sub_80338C4(u32);
extern u32 *gUnknown_203B33C;
extern s32 sub_80144A4(s32 *);

void sub_8035374(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            sub_80338C4(0x78);
            break;
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
            gUnknown_203B33C[0x159] = temp;
            sub_80338C4(0x7B);
            break;
    }
}

void sub_80353BC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            sub_80338C4(0x78);
            break;
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
            gUnknown_203B33C[0x159] = temp;
            sub_80338C4(0x7D);
            break;
    }
}

void sub_8035404(u32 param_1)
{
  s32 iVar1;

  if(sub_80144A4(&iVar1) == 0){
    sub_80338C4(param_1);
  }
}

void sub_8035424(void)
{
    sub_80338C4(6);
}

void sub_8035430(void)
{
    sub_80338C4(0x4F);
}

void nullsub_50(void)
{
}

void nullsub_51(void)
{
}
