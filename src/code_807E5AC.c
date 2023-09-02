#include "global.h"
#include "dungeon_global_data.h"

void sub_807FC3C(Position *pos, u32 param_2, u32 param_3)
{
  gDungeon->unk13574 = pos->x;
  gDungeon->unk13576 = pos->y;
  gDungeon->unk13578 = param_2;
  gDungeon->unk13579 = param_3;
  gDungeon->unk13570 = 1;
}
