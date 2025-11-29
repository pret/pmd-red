#include "global.h"
#include "globaldata.h"
#include "move_orb_effects_3.h"
#include "dungeon_vram.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "code_805D8C8.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_items.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_orb_effects_1.h"
#include "moves.h"
#include "math.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "dungeon_pos_data.h"
#include "dungeon_8041AD0.h"

void SetChargeStatusTarget(Entity *pokemon, Entity *target, u8 newStatus, Move *move, const u8 *message)
{
  bool8 bVar2;
  Move *movePtr;
  s32 index;
  bool8 uVar5;
  s32 iVar7;
  s32 iVar8;
  EntityInfo *entityInfo;

  if (EntityIsValid(target)) {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if ((entityInfo->bideClassStatus.status == newStatus) && (newStatus == STATUS_ENRAGED)) {
      TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FC074);
    }
    else {
      entityInfo->bideClassStatus.status = newStatus;

      for(index = 0; index < MAX_MON_MOVES; index++)
      {
        movePtr = &entityInfo->moves.moves[index];
        if(movePtr == move)
        {
            entityInfo->bideClassStatus.moveSlot = index;
            break;
        }
      }
      entityInfo->unk14A = 1;

      uVar5 = FALSE;
      if (newStatus == STATUS_FLYING || newStatus == STATUS_BOUNCING) {
        entityInfo->unkFF = 1;
        uVar5 = TRUE;
      }
      else if (newStatus == STATUS_DIVING || newStatus == STATUS_DIGGING) {
        entityInfo->unkFF = 2;
      }
      if (newStatus == STATUS_BIDE) {
        entityInfo->bideClassStatus.turns = CalculateStatusTurns(target,gBideTurnRange, FALSE) + 1;
        entityInfo->unkA0 = 0;
      }
      if (newStatus == STATUS_ENRAGED) {
        entityInfo->bideClassStatus.turns = CalculateStatusTurns(target,gEnragedTurnRange, FALSE) + 1;
      }
      sub_8041BD0(target,uVar5);
      TryDisplayDungeonLoggableMessage3_Async(pokemon,target,message);
      UpdateStatusIconFlags(target);

      // TODO: this could probably be cleaner..
      for (index = 0, iVar8 = 0xc7ff; index < 400; index++) {
        bVar2 = TRUE;
        if (entityInfo->unkFF == 1)
            if(iVar7 = entityInfo->unk174, bVar2 = FALSE, iVar7 > iVar8) // unk174 -> u32 to s32
            {
                bVar2 = TRUE;
            }
        if (bVar2) {
          break;
        }
        DungeonRunFrameActions(0x53);
      }
    }
  }
}

void sub_8079764(Entity * pokemon)
{
    EntityInfo *entityInfo;

    if (EntityIsValid(pokemon)) {
        entityInfo = GetEntInfo(pokemon);
        if ((entityInfo->bideClassStatus.status != STATUS_BIDE) && (entityInfo->bideClassStatus.status != STATUS_ENRAGED)) {
            entityInfo->bideClassStatus.status = STATUS_NONE;
            entityInfo->unk14A = 0;
            entityInfo->unkFF = 0;
        }
        UpdateStatusIconFlags(pokemon);
    }
}
