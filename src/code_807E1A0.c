#include "global.h"
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
#include "move_util.h"
#include "moves.h"
#include "structs/str_dungeon.h"

extern u8 UseAttack(Entity *);
extern void sub_805E804(void);
void sub_806A2BC(Entity *pokemon, u8 param_2);
extern u8 sub_8044B28(void);
extern void nullsub_93(DungeonPos *);
extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
extern void sub_807EC28(bool8);
extern void sub_806A5B8(Entity *);

extern u8 *gUnknown_80F9C4C[];
extern u8 *gUnknown_80F9C70[];
extern u8 *gUnknown_80F9C8C[];
extern u8 *gUnknown_80F9CBC[];
extern u8 *gUnknown_80FCAC0[];




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
        sub_806A2BC(leader,1);
        UseAttack(leader);
        if (sub_8044B28() == 0) {
          LogMessageByIdWithPopupCheckUser(leader,*gUnknown_80F9C4C);
          sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],0);
          gDungeon->unk644.unk36 = 1;
        }
      }
    }
    else if (gDungeon->unk644.unk36 == 1) {
      if (gDungeon->unk644.windTurns < 0x96) {
        sub_805E804();
        sub_806A2BC(leader,1);
        UseAttack(leader);
        if (sub_8044B28() == 0) {
          LogMessageByIdWithPopupCheckUser(leader,*gUnknown_80F9C70);
          sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],1);
          gDungeon->unk644.unk36 = 2;
        }
      }
    }
    else if (gDungeon->unk644.unk36 == 2) {
      if (gDungeon->unk644.windTurns < 0x32) {
        sub_805E804();
        sub_806A2BC(leader,1);
        UseAttack(leader);
        if (sub_8044B28() == 0) {
          LogMessageByIdWithPopupCheckUser(leader,*gUnknown_80F9C8C);
          sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],2);
          gDungeon->unk644.unk36 = 3;
        }
      }
    }
    else if (gDungeon->unk644.windTurns < 1) {
      sub_805E804();
      sub_806A2BC(leader,1);
      UseAttack(leader);
      if (sub_8044B28() == 0) {
        LogMessageByIdWithPopupCheckUser(leader,*gUnknown_80F9CBC);
        sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],3);
        gDungeon->unk644.unk36 = 4;
        sub_8068FE0(leader,0x21e,leader);
      }
    }
  }
}
