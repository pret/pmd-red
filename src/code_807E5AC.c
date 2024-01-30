#include "global.h"
#include "structs/str_dungeon.h"

void sub_807FC3C(Position *pos, u32 trapID, u32 param_3)
{
  gDungeon->trapPos.x = pos->x;
  gDungeon->trapPos.y = pos->y;
  gDungeon->trapID = trapID;
  gDungeon->unk13579 = param_3;
  gDungeon->unk13570 = 1;
}
