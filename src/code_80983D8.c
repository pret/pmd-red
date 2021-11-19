#include "global.h"

extern u32 gUnknown_8115E94[5][3]; // NOTE: Factor of two difference in array sizes

s32 CalculateFacingDir(short *param_1,short *param_2)
{
  s32 uVar1;
  s32 uVar2;
  s32 uVar3;

  uVar3 = param_2[0] - param_1[0];
  uVar2 = param_2[1] - param_1[1];
  if ((uVar3 == 0) && (uVar2 == 0)) {
    uVar1 = 0;
  }
  else {
    if (0 < uVar3) {
      uVar3 = 1;
    }
    if (0 < uVar2) {
      uVar2 = 1;
    }
    if (-1 >= uVar3) {
      uVar3 = -1;
    }
    if (-1 >= uVar2) {
      uVar2 = -1;
    }
    uVar1 = gUnknown_8115E94[(uVar2 + 1)][(uVar3 + 1)];
  }
  return uVar1;
}

s32 GetMaxPositionDifference(short param_1[],short param_2[])
{
  s32 diff_index1;
  s32 diff_index0;

  diff_index0 = param_1[0] - param_2[0];
  if (diff_index0 < 0) {
    diff_index0 = -diff_index0;
  }
  diff_index1 = param_1[1] - param_2[1];
  if (diff_index1 < 0) {
    diff_index1 = -diff_index1;
  }
  if (diff_index1 < diff_index0) {
    diff_index1 = diff_index0;
  }
  return diff_index1;
}

