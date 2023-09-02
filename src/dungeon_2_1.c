#include "global.h"
#include "dungeon.h"
#include "constants/dungeon.h"
#include "code_800D090.h"
#include "pokemon.h"
#include "random.h"
#include "code_8092334.h"

extern u8 gUnknown_810A350[];
extern u8 gDungeonFloorCount[];
extern u8 *gUnknown_8108084[];

s32 sub_8091E94(s32 a1, s32 a2, s32 a3); // items.c


bool8 sub_8090820(u16 moveID)
{
    PokemonStruct1 *pokeStruct;
    Move *move;
    s32 moveIndex;
    s32 index;
    s32 one;

    for(index = 0; index < 0x19d; index++)
    {
        pokeStruct = &gRecruitedPokemonRef->pokemon[index];
        one = 1;
        if (pokeStruct->unk0 & 1)
        {
            if(pokeStruct->unk0 >> 1 & one){
                for(moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
                {
                    move = &pokeStruct->moves[moveIndex];
                    if ((move->moveFlags & MOVE_FLAG_EXISTS) && (move->id == moveID)) {
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

void sub_8090888(u8 *param_1, u8 *param_2)
{
    s32 iVar3;

    iVar3 = 0;

    if(*param_1 != 0)  
    {
        do {
            if (*param_1 == 0xA) {
                iVar3++;
            }
            param_1++;
        } while (*param_1 != 0);
    }

    while (iVar3 % 3) {
        *param_1 = 0xA;
        param_1++;
        iVar3++;
    }

    while (*param_2 != 0) {
        *param_1 = *param_2;
        param_1++;
        param_2++;
    }

    *param_1 = 0;
}

u32 sub_80908D8(DungeonLocation *dungeon)
{
  if ((dungeon->id < DUNGEON_OUT_ON_RESCUE) && (dungeon->floor < gDungeonFloorCount[dungeon->id])) {
   return gUnknown_8108084[dungeon->id][dungeon->floor];
  }
  else {
    return 1;
  }
}

u8 sub_8090910(DungeonLocation *dungeon, u32 param_2)
{
  u32 rand1;
  u32 rand2;
  
  rand1 = RandInt(9999);
  rand2 = RandInt(9999);
  if ((dungeon->id < DUNGEON_OUT_ON_RESCUE) && (dungeon->floor < gDungeonFloorCount[dungeon->id])) {
    return sub_8091E94(param_2, rand1, rand2);
  }
  else {
    return 0x46;
  }
}

bool8 sub_809095C(u8 dungeon)
{
  s32 counter;
  
  if (dungeon >= DUNGEON_OUT_ON_RESCUE) {
      return TRUE;
  }
  else
  {
    counter = 0;
    if (gUnknown_810A350[0] != DUNGEON_OUT_ON_RESCUE) {
      for(; gUnknown_810A350[counter] != DUNGEON_OUT_ON_RESCUE; counter++)
      {
        if (gUnknown_810A350[counter] == dungeon) return TRUE;
      }
    }
    return FALSE;
  }
}
