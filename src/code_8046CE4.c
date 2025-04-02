#include "global.h"
#include "globaldata.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_items.h"
#include "dungeon_config.h"
#include "structs/dungeon_entity.h"

// Decompile code_8046CE4.s from bottom instead of top and put functions before sub_8047930

bool8 sub_8047930(Entity *pokemon, Entity *target)
{
  bool8 flag;

  if (((GetEntInfo(target)->shopkeeper == TRUE) ||
       (GetEntInfo(target)->monsterBehavior == BEHAVIOR_DIGLETT)) || (GetEntInfo(target)->monsterBehavior == BEHAVIOR_RESCUE_TARGET)) {
    return FALSE;
  }
  else {
    if(DungeonRandInt(100) < gUnknownDungeonChance)
        flag = TRUE;
    else
        flag = FALSE;
    if (GetEntityType(pokemon) == ENTITY_MONSTER) {
      if (HasHeldItem(pokemon, ITEM_WHIFF_SPECS)) {
          flag = FALSE;
      }
      else {
        if (HasHeldItem(pokemon, ITEM_LOCKON_SPECS)) {
          flag = TRUE;
        }
      }
    }
    if ((GetEntityType(target) == ENTITY_MONSTER) && (HasHeldItem(target, ITEM_DODGE_SCARF))) {
      flag = FALSE;
    }
  }
  return flag;
}
