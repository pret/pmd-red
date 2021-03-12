#include "global.h"

s32 sub_8098434(short param_1[],short param_2[])
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
