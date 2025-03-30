#include "global.h"
#include "dungeon_misc.h"
#include "code_804267C.h"
#include "dungeon_message.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "dungeon_ai.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
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

void sub_807E1A0(Entity *pokemon,Entity *target,u8 moveType,s16 param_4,s32 param_5)
{
  EntityInfo *targetInfo;
  u8 flag;
  Move move;
  s32 newHP;
  s32 param_4_s32;

  param_4_s32 = param_4;

  if (EntityIsValid(target)) {
    targetInfo = GetEntInfo(target);
    InitPokemonMove(&move, MOVE_REGULAR_ATTACK);
    if (!sub_80571F0(target,&move)) {
      if (!targetInfo->isNotTeamMember) {
        newHP = targetInfo->HP;
        newHP /= 2;
        if (MonsterIsType(target, TYPE_FIRE)) {
          newHP /= 2;
        }
        if (newHP < 1) {
          newHP = 1;
        }
      }
      else {
        newHP = param_5;
        if (MonsterIsType(target, TYPE_FIRE)) {
           newHP /= 2;
        }
      }
      sub_806F370(pokemon,target,newHP,0,&flag,moveType,param_4_s32,0,0,0);
    }
  }
}

void HandleSwitcherOrb(Entity *pokemon,Entity *target)
{
  DungeonPos pokemonPos;
  DungeonPos targetPos;


  if (AbilityIsActive(pokemon, ABILITY_SUCTION_CUPS)) {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCAC0); // $m0 is anchored! It won't switch places
  }
  else if(AbilityIsActive(target, ABILITY_SUCTION_CUPS))
  {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCAC0); // $m0 is anchored! It won't switch places
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
    sub_804535C(pokemon,NULL);
    sub_804535C(target,NULL);

    if (EntityIsValid(pokemon)) {
      if (GetEntInfo(pokemon)->isTeamLeader) {
        sub_804AC20(&pokemon->pos);
        sub_807EC28(FALSE);
      }
      sub_806A5B8(pokemon);
      sub_8075900(pokemon,gDungeon->forceMonsterHouse);
    }

    if (EntityIsValid(target)) {
      if (GetEntInfo(target)->isTeamLeader) {
        sub_804AC20(&target->pos);
        sub_807EC28(FALSE);
      }
      sub_806A5B8(target);
      sub_8075900(target,gDungeon->forceMonsterHouse);
    }
  }
}

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
