#include "global.h"
#include "dungeon_engine.h"
#include "constants/dungeon.h"
#include "dungeon_global_data.h"

extern bool8 sub_8044B28(void);
extern bool8 xxx_dungeon_80442D0(u8);
extern void CheckElectricAbilities(void);
extern void sub_807E378(void);
extern void sub_8044574(void);
extern void sub_8044820(void);
extern void sub_8044AB4(void);

bool8 IsBossBattle()
{
    if (gDungeonGlobalData->bossBattleIndex != 0 && gDungeonGlobalData->bossBattleIndex <= 0x31)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsFixedDungeon()
{
    if (gDungeonGlobalData->tileset > DUNGEON_OUT_ON_RESCUE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8044210(void)
{
    if( (u8)(gDungeonGlobalData->unk644 - 0x4B) < 0x17)
        return TRUE;
    else
        return FALSE;
}

void RunDungeon(u8 param_1)
{
  bool8 cVar2;
  
  if (!sub_8044B28()) {
    CheckElectricAbilities();
    if (!sub_8044B28()) {
      cVar2 = xxx_dungeon_80442D0(param_1);
      if (!sub_8044B28()) {
        if (cVar2 != 0) {
          sub_807E378();
          if (sub_8044B28()) {
            return;
          }
        }
        if (!sub_8044B28()) {
          sub_8044574();
          if (!sub_8044B28()) {
            sub_8044820();
            if (!sub_8044B28()) {
              sub_8044AB4();
              gDungeonGlobalData->speedTurnCounter++;
              if (gDungeonGlobalData->speedTurnCounter == 24) {
                 gDungeonGlobalData->speedTurnCounter = 0;
              }
            }
          }
        }
      }
    }
  }
}
