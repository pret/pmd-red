#include "global.h"

extern s32 sub_80144A4(s32 *);
extern void sub_80338C4(u32);
extern void sub_80338C4(u32);

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

