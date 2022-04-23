#include "global.h"
#include "dungeon_global_data.h"

void sub_807FC3C(struct Position *param_1, u32 param_2, u32 param_3)
{
  gDungeonGlobalData->unk13574 = param_1->x;
  gDungeonGlobalData->unk13576 = param_1->y;
  gDungeonGlobalData->unk13578 = param_2;
  gDungeonGlobalData->unk13579 = param_3;
  gDungeonGlobalData->unk13570 = 1;
}
