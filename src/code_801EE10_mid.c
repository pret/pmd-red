#include "global.h"
#include "code_801EE10.h"

extern unkStruct_203B270 *gUnknown_203B270;

s32 sub_801F3F8(void)
{
  Move *move;
  int index;
  s32 counter;

  counter = 0;
  for(index = 0; index < 8; index++)
  {
    move = &gUnknown_203B270->moves[index];
    if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
      counter++;
    }
  }
  return counter;
}
