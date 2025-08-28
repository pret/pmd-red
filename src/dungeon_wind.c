#include "global.h"
#include "globaldata.h"
#include "dungeon_misc.h"
#include "code_804267C.h"
#include "dungeon_message.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "dungeon_ai.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_util.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "dungeon_main.h"
#include "dungeon_misc.h"
#include "move_util.h"
#include "moves.h"
#include "structs/str_dungeon.h"
#include "dungeon_engine.h"

extern u8 DisplayActions(Entity *);

void sub_807E378(void)
{
  u16 uVar2;
  Entity *leader;

  leader = GetLeader();
  if (EntityIsValid(leader)) {

    uVar2 = gDungeon->unk644.windTurns;
    if ((gDungeon->unk644.windTurns < 1) ||
       (gDungeon->unk644.windTurns--, ((uVar2 - 1) << 0x10) < 1)) {
      gDungeon->unk644.unk36 = 3;
    }

    if (gDungeon->unk644.unk36 == 0) {
      if (gDungeon->unk644.windTurns < 0xfa) {
        sub_805E804();
        TryPointCameraToMonster(leader,1);
        DisplayActions(leader);
        if (IsFloorOver() == 0) {
          LogMessageByIdWithPopupCheckUser(leader,gUnknown_80F9C4C);
          sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],0);
          gDungeon->unk644.unk36 = 1;
        }
      }
    }
    else if (gDungeon->unk644.unk36 == 1) {
      if (gDungeon->unk644.windTurns < 0x96) {
        sub_805E804();
        TryPointCameraToMonster(leader,1);
        DisplayActions(leader);
        if (IsFloorOver() == 0) {
          LogMessageByIdWithPopupCheckUser(leader,gUnknown_80F9C70);
          sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],1);
          gDungeon->unk644.unk36 = 2;
        }
      }
    }
    else if (gDungeon->unk644.unk36 == 2) {
      if (gDungeon->unk644.windTurns < 0x32) {
        sub_805E804();
        TryPointCameraToMonster(leader,1);
        DisplayActions(leader);
        if (IsFloorOver() == 0) {
          LogMessageByIdWithPopupCheckUser(leader,gUnknown_80F9C8C);
          sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],2);
          gDungeon->unk644.unk36 = 3;
        }
      }
    }
    else if (gDungeon->unk644.windTurns < 1) {
      sub_805E804();
      TryPointCameraToMonster(leader,1);
      DisplayActions(leader);
      if (IsFloorOver() == 0) {
        LogMessageByIdWithPopupCheckUser(leader,gUnknown_80F9CBC);
        sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],3);
        gDungeon->unk644.unk36 = 4;
        HandleFaint(leader,0x21e,leader);
      }
    }
  }
}
