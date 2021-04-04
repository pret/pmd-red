#include "global.h"

s32 sub_8011FA8(void);
s32 sub_8095324(u32);
s32 sub_8011C1C(void);

bool8 sub_8039844(void)
{
  int iVar1;
  bool8 return_var;
  
  iVar1 = sub_8011FA8();
  return_var = 0;
  if (sub_8095324(1) != 0 || sub_8095324(7) != 0)
  {
      if (iVar1 == 0xf1207)
        return_var  = 1;
  }
  else if (sub_8011C1C() == 2 && iVar1 == 0xf1207)
    return_var = 1;
  return return_var;
}
