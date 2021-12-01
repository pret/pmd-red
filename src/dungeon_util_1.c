#include "global.h"
#include "constants/direction.h"
#include "dungeon_util_1.h"
#include "dungeon_global_data.h"
#include "random.h"

extern struct DungeonGlobalData *gDungeonGlobalData;
extern bool8 EntityExists(struct DungeonEntity *);
extern void sub_806CE68(struct DungeonEntity *, s32);

extern s32 sub_803F994(void);
extern s32 sub_803F9B0(void);
extern void sub_803F4A0(u32);
extern void sub_803F878(s32, s32);
extern void sub_803E46C(u32);

void sub_8085860(s32 x, s32 y)
{
  
  sub_803F4A0(0);
  sub_803F878(x * 0x1800 + 0xc00, y * 0x1800 + 0x1000);
}

void sub_8085890(s32 x, s32 y)
{
    sub_803F4A0(0);
    sub_803F878(x, y);
}

void sub_80858AC(s32 *param_1, s32 param_2)
{
  s32 iVar1;
  s32 iVar2;
  s32 iVar3;
  s32 iVar4;
  
  iVar1 = sub_803F994();
  iVar2 = sub_803F9B0();
  iVar3 = (param_1[0] - iVar1) / param_2;
  iVar4 = (param_1[1] - iVar2) / param_2;
  sub_803F4A0(0);
  if (0 < param_2) {
    do {
      iVar1 += iVar3;
      iVar2 += iVar4;
      sub_803F878(iVar1,iVar2);
      sub_803E46C(0x46);
      param_2--;
    } while (param_2 != 0);
  }
  sub_803F878(param_1[0],param_1[1]);
  sub_803E46C(0x46);
}

void SetFacingDirection(struct DungeonEntity *pokemon, s32 direction)
{
    pokemon->entityData->facingDir = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);
}

void sub_8085930(s32 direction)
{
    s32 iVar2;
    struct DungeonEntity *entity;
    for(iVar2 = 0; iVar2 < MAX_TEAM_MEMBERS; iVar2++)
    {
        entity = gDungeonGlobalData->teamPokemon[iVar2];
        if(EntityExists(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandomCapped(NUM_DIRECTIONS));
            }
            else
            {
                entity->entityData->facingDir = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
    for(iVar2 = 0; iVar2 < DUNGEON_MAX_WILD_POKEMON; iVar2++)
    {
        entity = gDungeonGlobalData->wildPokemon[iVar2];
        if(EntityExists(entity))
        {
            if(entity->entityData->clientType == 2)
            {
                if(direction >= NUM_DIRECTIONS)
                {
                    sub_806CE68(entity, RandomCapped(NUM_DIRECTIONS));
                }
                else
                {
                    entity->entityData->facingDir = direction & DIRECTION_MASK;
                    sub_806CE68(entity, direction);
                }
            }
        }
    }
}

void sub_80859F0(s32 direction)
{
    s32 iVar2;
    struct DungeonEntity *entity;
    for(iVar2 = 0; iVar2 < DUNGEON_MAX_WILD_POKEMON; iVar2++)
    {
        entity = gDungeonGlobalData->wildPokemon[iVar2];
        if(EntityExists(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandomCapped(NUM_DIRECTIONS));
            }
            else
            {
                entity->entityData->facingDir = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
}

bool8 IsMovingClient(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    switch (pokemonData->clientType)
    {
        case CLIENT_TYPE_CLIENT:
        case CLIENT_TYPE_DONT_MOVE:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0x9:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            return TRUE;
        case CLIENT_TYPE_NONE:
        case 0x2:
        case 0x4:
        case 0xA:
        case 0xB:
        case 0xC:
        default:
            return FALSE;
    }
}
