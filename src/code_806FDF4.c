#include "global.h"
#include "structs/str_pokemon.h"
#include "structs/struct_8069D4C.h"
#include "code_80118A4.h"
#include "code_8045A00.h"
#include "code_8097670.h"
#include "friend_area.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text_util.h"
#include "dungeon_util_1.h"

extern u8 gUnknown_202E628[];
extern u8 gUnknown_202E088[];
extern u8 gAvailablePokemonNames[];

extern u8 *gUnknown_80FA0C8[];
extern u8 gUnknown_202E088[];
extern u8 *gUnknown_80FA120[];
extern u8 *gUnknown_80FA090[];

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target);
void sub_8068FE0(Entity *, u32, Entity *);
u8 sub_806B8CC();
bool8 sub_805FBE8(u8 *a0);
extern s32 sub_8052B8C(u32, const u8 *, u32);
extern void PrintFieldMessage(u32, const u8 *, u32);

bool8 sub_806FDF4(Entity *entity1,Entity *entity2,Entity **entityPtr)
{
  u8 friendArea;
  bool8 flag;
  Entity *leader;
  PokemonStruct2 *pokeStruct2;
  int index;
  struct unkStruct_8069D4C local_74;
  Entity *local_2c;
  u8 *buffer;
  s32 index2;

   flag = 0;
  *entityPtr = NULL;

  sub_8069D4C(&local_74,entity2);

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    if (((u8)(index[gRecruitedPokemonRef->pokemon2].unk0) & 1) == 0) break;
  }
    
  if (index == MAX_TEAM_MEMBERS) {
    return FALSE;
  }
  else {
    friendArea = GetFriendArea(local_74.id);
    pokeStruct2 = &gRecruitedPokemonRef->pokemon2[index];
    pokeStruct2->unk0 = 3;
    pokeStruct2->isTeamLeader = FALSE;
    pokeStruct2->level = local_74.level;
    pokeStruct2->IQ = 1;
    SetDefaultIQSkills((u8 *)&(pokeStruct2->IQSkills),FALSE);
    pokeStruct2->hiddenPower = local_74.hiddenPower;
    pokeStruct2->tacticIndex = 0;
    pokeStruct2->unkA = -1;
    pokeStruct2->unkC = index;
    pokeStruct2->speciesNum = local_74.id;
    pokeStruct2->dungeonLocation = gDungeon->dungeonLocation;
    pokeStruct2->unk10 = local_74.HP;
    pokeStruct2->unk12 = local_74.HP;
    pokeStruct2->belly = local_74.belly;
    pokeStruct2->maxBelly = local_74.maxBelly;

    for(index2 = 0; index2 < 2; index2++)
    {
      pokeStruct2->offense.att[index2] = local_74.att[index2];
      pokeStruct2->offense.def[index2] = local_74.def[index2];
    }
      
    pokeStruct2->currExp = local_74.exp;
    pokeStruct2->moves = local_74.moves;
      
    pokeStruct2->itemSlot = local_74.heldItem;
    buffer = pokeStruct2->name;
    BoundedCopyStringtoBuffer(buffer,GetMonSpecies(local_74.id), POKEMON_NAME_LENGTH);
    if (GetFriendAreaStatus(friendArea) == 0) {
      UnlockFriendArea(friendArea);
      flag = TRUE;
    }
    sub_8097848();
    sub_8068FE0(entity2,500,entity1);
    if (sub_806B8CC(local_74.id,local_74.pos.x,local_74.pos.y,pokeStruct2,&local_2c,0,0) == 0) {
      pokeStruct2->unk0 = 0;
    }
    else {
      if (sub_8052B8C(0,*gUnknown_80FA090,1) == 1) {
        while (!sub_805FBE8(buffer)) {
          PrintFieldMessage(0,*gUnknown_80FA0C8,1);
        }
      }
      if (flag) {
        leader = xxx_call_GetLeader();
        SetMessageArgument(gAvailablePokemonNames,leader,0);
        sub_8092558(gUnknown_202E628,friendArea);
        PlaySound(0xce);
        PrintFieldMessage(0,*gUnknown_80FA120,1);
      }
      sub_808D9DC(gUnknown_202E088,pokeStruct2,0);
      *entityPtr = local_2c;
    }
   return TRUE;
  }
}
