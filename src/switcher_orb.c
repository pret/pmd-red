#include "global.h"
#include "globaldata.h"
#include "constants/ability.h"
#include "constants/weather.h"
#include "dungeon_vram.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "structs/str_dungeon.h"
#include "code_8077274_1.h"
#include "dungeon_ai.h"
#include "run_dungeon.h"
#include "dungeon_generation.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "moves.h"
#include "move_util.h"
#include "code_8041AD0.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"

extern void sub_807EC28(bool8);
extern void nullsub_93(DungeonPos *);

void HandleSwitcherOrb(Entity *pokemon,Entity *target)
{
  DungeonPos pokemonPos;
  DungeonPos targetPos;


  if (AbilityIsActive(pokemon, ABILITY_SUCTION_CUPS)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCAC0); // $m0 is anchored! It won't switch places
  }
  else if(AbilityIsActive(target, ABILITY_SUCTION_CUPS))
  {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCAC0); // $m0 is anchored! It won't switch places
  }
  else
  {
    pokemonPos.x = pokemon->pos.x;
    pokemonPos.y = pokemon->pos.y;
    targetPos.x = target->pos.x;
    targetPos.y = target->pos.y;
    nullsub_93(&pokemonPos);
    nullsub_93(&targetPos);
    sub_80694C0(pokemon,targetPos.x,targetPos.y,1);
    sub_80694C0(target,pokemonPos.x,pokemonPos.y,1);
    UpdateEntityPixelPos(pokemon,NULL);
    UpdateEntityPixelPos(target,NULL);

    if (EntityIsValid(pokemon)) {
      if (GetEntInfo(pokemon)->isTeamLeader) {
        DiscoverMinimap(&pokemon->pos);
        sub_807EC28(FALSE);
      }
      sub_806A5B8(pokemon);
      sub_8075900(pokemon,gDungeon->forceMonsterHouse);
    }

    if (EntityIsValid(target)) {
      if (GetEntInfo(target)->isTeamLeader) {
        DiscoverMinimap(&target->pos);
        sub_807EC28(FALSE);
      }
      sub_806A5B8(target);
      sub_8075900(target,gDungeon->forceMonsterHouse);
    }
  }
}

