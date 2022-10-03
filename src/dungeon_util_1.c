#include "global.h"
#include "dungeon_util_1.h"

#include "constants/direction.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"
#include "random.h"

extern const u8 gUnknown_8107358[25];

extern void sub_806CE68(struct DungeonEntity *, u32);
extern void sub_804535C(struct DungeonEntity *, u32);
extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F4A0(u32);
extern void sub_803F878(s32, s32);
extern void sub_803E46C(u32);
extern void sub_803E708(u32, u32);

extern void sub_8068FE0(struct DungeonEntity *, u32, u8 *);
extern void sub_80457DC(u8 *);
extern void sub_80861D4(struct DungeonEntity *, u32, s32 direction);
extern void sub_80694C0(struct DungeonEntity *, s32, s32, u32);
extern struct DungeonEntity *GetPartnerEntity();

typedef void (*DungeonCallback)(struct DungeonEntity *);

void sub_80855E4(DungeonCallback func)
{
    bool8 bVar1;
    struct DungeonEntity * entity;
    struct DungeonEntity * partnerEntity;
    s32 index;

    bVar1 = FALSE;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeonGlobalData->teamPokemon[index];
        if (EntityExists(entity)) {
            if (entity->entityData->joinLocation == 0x41) {
                bVar1 = TRUE;
            }
            func(entity);
        }
    }
    if ((!bVar1) && (partnerEntity = GetPartnerEntity(), partnerEntity != NULL)) {
        func(partnerEntity);
    }
}

void sub_808563C(DungeonCallback func)
{
    struct DungeonEntity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeonGlobalData->wildPokemon[index];
        if ((EntityExists(entity)) && (entity->entityData->joinLocation != 0x41)) {
            func(entity);
        }
    }
}

struct DungeonEntity *GetEntityFromClientType(u8 entityType)
{
    struct DungeonEntity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeonGlobalData->allPokemon[index];
        if ((EntityExists(entity)) && (entity->entityData->clientType == entityType)) return entity;
    }
    return NULL;
}

void sub_80856C8(struct DungeonEntity * pokemon, s32 x, s32 y)
{
    sub_80694C0(pokemon, x, y, 1);
    sub_804535C(pokemon,0);
}

void sub_80856E0(struct DungeonEntity * pokemon, s32 direction)
{
    struct DungeonEntityData *entityData;
    s32 counter;

    entityData = pokemon->entityData;
    sub_80861D4(pokemon, 6, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityData->unk174 += 0x200;
        sub_803E46C(0x46);
    }
    entityData->action.facingDir = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityData->unk174 -= 0x200;
        sub_803E46C(0x46);
    }
    entityData->unk174 = 0;
    sub_803E46C(0x46);
}

void sub_8085764(void)
{
    struct DungeonEntity *entity;
    s32 index;
    u8 auStack128 [116];

    sub_80457DC(auStack128);
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeonGlobalData->wildPokemon[index];
        if ((EntityExists(entity)) && (entity->entityData->clientType == 2)) {
            sub_8068FE0(entity,0x207,auStack128);
        }
    }
}

void sub_80857B8(void)
{
    u8 *facingDir;
    struct DungeonEntityData *entityData;
    struct DungeonEntity *entity;
    int index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeonGlobalData->allPokemon[index];
        if (EntityExists(entity)) {
            entityData = entity->entityData;
            if ((gDungeonGlobalData->unk4 == 0) && (gDungeonGlobalData->unk2 == 0)) {
                sub_804535C(entity, 0);
                entityData->unk15C = 0;
                entityData->unkFE = 99;
                facingDir = &entityData->action.facingDir;
                entityData->targetPosition.x = gAdjacentTileOffsets[*facingDir].x + entity->posWorld.x;
                entityData->targetPosition.y = gAdjacentTileOffsets[*facingDir].y + entity->posWorld.y;
                sub_806CE68(entity,*facingDir);
            }
        }
    }
}

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

void ShiftCameraToPosition(struct Position32 *posStruct, s32 cameraSteps)
{
  s32 XPos;
  s32 YPos;
  s32 XIncrement;
  s32 YIncrement;

  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  XIncrement = (posStruct->x - XPos) / cameraSteps;
  YIncrement = (posStruct->y - YPos) / cameraSteps;
  sub_803F4A0(0);
  if (0 < cameraSteps) {
    do {
      XPos += XIncrement;
      YPos += YIncrement;
      sub_803F878(XPos,YPos);
      sub_803E46C(0x46);
      cameraSteps--;
    } while (cameraSteps != 0);
  }
  sub_803F878(posStruct->x,posStruct->y);
  sub_803E46C(0x46);
}

void SetFacingDirection(struct DungeonEntity *pokemon, s32 direction)
{
    pokemon->entityData->action.facingDir = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);
}

void sub_8085930(s32 direction)
{
    s32 index;
    struct DungeonEntity *entity;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeonGlobalData->teamPokemon[index];
        if(EntityExists(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandomCapped(NUM_DIRECTIONS));
            }
            else
            {
                entity->entityData->action.facingDir = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeonGlobalData->wildPokemon[index];
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
                    entity->entityData->action.facingDir = direction & DIRECTION_MASK;
                    sub_806CE68(entity, direction);
                }
            }
        }
    }
}

void sub_80859F0(s32 direction)
{
    s32 index;
    struct DungeonEntity *entity;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeonGlobalData->wildPokemon[index];
        if(EntityExists(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandomCapped(NUM_DIRECTIONS));
            }
            else
            {
                entity->entityData->action.facingDir = direction & DIRECTION_MASK;
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
        case 0x3:
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
        case CLIENT_TYPE_DONT_MOVE:
        case 0xA:
        case 0xB:
        case 0xC:
        default:
            return FALSE;
    }
}

void sub_8085B0C(struct DungeonEntity *pokemon)
{
  s32 index;
  u8 local_28 [25];

  index = 0;

  memcpy(local_28, gUnknown_8107358, 25);
  while (local_28[index] != 0) {
    SetFacingDirection(pokemon, local_28[index]);
    sub_803E708(6,0x46);
    index++;
  }
}
