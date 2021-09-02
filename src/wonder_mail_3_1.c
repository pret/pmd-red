#include "global.h"

u8 sub_80A27CC(s16);

u8 sub_802FCF0(void)
{
  s32 iVar3;
  
  for(iVar3 = 0; iVar3 < 0x2E; iVar3++){
    if (sub_80A27CC(iVar3) != '\0') {
      return 0;
    }
  }
  return 1;
}
