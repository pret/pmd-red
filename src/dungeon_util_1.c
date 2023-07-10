#include "global.h"
#include "dungeon_util_1.h"

#include "constants/direction.h"
#include "constants/dungeon.h"
#include "dungeon_global_data.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "random.h"

extern const u8 gUnknown_8107358[25];

extern void sub_806CE68(struct Entity *, u32);
extern void sub_804535C(struct Entity *, u32);
extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F4A0(u32);
extern void sub_803F878(s32, s32);
extern void sub_803E46C(u32);
extern void sub_803E708(u32, u32);

extern void sub_8068FE0(struct Entity *, u32, u8 *);
extern void sub_80457DC(u8 *);
extern void sub_80861D4(struct Entity *, u32, s32 direction);
extern void sub_80694C0(struct Entity *, s32, s32, u32);

typedef void (*DungeonCallback)(struct Entity *);

struct Entity *xxx_call_GetLeader(void)
{
    return GetLeader();
}

struct Entity *GetPartnerEntity(void)
{
    s32 counter;
    struct Entity *entity;
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        entity = gDungeon->teamPokemon[counter];
        if(EntityExists(entity) && entity->info->joinedAt == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            return entity;
        }
    }
    return GetEntityFromClientType(CLIENT_TYPE_PARTNER);
}

void sub_80854D4(void)
{
    struct Entity *stack1[MAX_TEAM_MEMBERS];
    struct Entity *stack2[MAX_TEAM_MEMBERS];
    s32 counter = 0;
    s32 index;
    struct Entity *entity;
    struct Entity *entity2;
    struct Entity *entity3;
    struct Entity *entity4;
    struct Entity *entity5;
    
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityExists(entity))
        {
            stack1[counter] = entity;
            counter++;
        }
    }
    for(; counter < MAX_TEAM_MEMBERS; counter++)
    {
        stack1[counter] = NULL;
    }
    counter = 0;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity2 = stack1[index];
        if(entity2 != NULL && entity2->info->isTeamLeader)
        {
            stack1[index] = NULL;
            stack2[counter] = entity2;
            counter++;
        }
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity3 = stack1[index];
        if(entity3 != NULL && entity3->info->joinedAt == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            stack1[index] = NULL;
            stack2[counter] = entity3;
            counter++;
        }
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity4 = stack1[index];
        if(entity4 != NULL)
        {
            stack1[index] = NULL;
            stack2[counter] = entity4;
            counter++;
        }
    }
    for(; counter < MAX_TEAM_MEMBERS; counter++)
    {
        stack2[counter] = NULL;
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity5 = stack2[index];
        if(entity5 != NULL)
            sub_80856C8(entity5, gDungeon->unkE220[index].x, gDungeon->unkE220[index].y);
    }
}

void sub_80855E4(DungeonCallback func)
{
    bool8 flag;
    struct Entity * entity;
    struct Entity * partnerEntity;
    s32 index;

    flag = FALSE;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if (EntityExists(entity)) {
            if (entity->info->joinedAt == DUNGEON_JOIN_LOCATION_PARTNER) {
                flag = TRUE;
            }
            func(entity);
        }
    }
    if ((!flag) && (partnerEntity = GetPartnerEntity(), partnerEntity != NULL)) {
        func(partnerEntity);
    }
}

void sub_808563C(DungeonCallback func)
{
    struct Entity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityExists(entity)) && (entity->info->joinedAt != 0x41)) {
            func(entity);
        }
    }
}

struct Entity *GetEntityFromClientType(u8 entityType)
{
    struct Entity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if ((EntityExists(entity)) && (entity->info->clientType == entityType)) return entity;
    }
    return NULL;
}

void sub_80856C8(struct Entity * pokemon, s32 x, s32 y)
{
    sub_80694C0(pokemon, x, y, 1);
    sub_804535C(pokemon,0);
}

void sub_80856E0(struct Entity * pokemon, s32 direction)
{
    struct EntityInfo *entityInfo;
    s32 counter;

    entityInfo = pokemon->info;
    sub_80861D4(pokemon, 6, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 += 0x200;
        sub_803E46C(0x46);
    }
    entityInfo->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 -= 0x200;
        sub_803E46C(0x46);
    }
    entityInfo->unk174 = 0;
    sub_803E46C(0x46);
}

void sub_8085764(void)
{
    struct Entity *entity;
    s32 index;
    u8 auStack128 [116];

    sub_80457DC(auStack128);
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityExists(entity)) && (entity->info->clientType == CLIENT_TYPE_PARTNER)) {
            sub_8068FE0(entity,0x207,auStack128);
        }
    }
}

void sub_80857B8(void)
{
    u8 *direction;
    struct EntityInfo *entityInfo;
    struct Entity *entity;
    int index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if (EntityExists(entity)) {
            entityInfo = entity->info;
            if ((gDungeon->unk4 == 0) && (gDungeon->unk2 == 0)) {
                sub_804535C(entity, 0);
                entityInfo->unk15C = 0;
                entityInfo->unkFE = 99;
                direction = &entityInfo->action.direction;
                entityInfo->targetPos.x = gAdjacentTileOffsets[*direction].x + entity->pos.x;
                entityInfo->targetPos.y = gAdjacentTileOffsets[*direction].y + entity->pos.y;
                sub_806CE68(entity,*direction);
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

void SetFacingDirection(struct Entity *pokemon, s32 direction)
{
    pokemon->info->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);
}

void sub_8085930(s32 direction)
{
    s32 index;
    struct Entity *entity;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityExists(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                entity->info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityExists(entity))
        {
            if(entity->info->clientType == CLIENT_TYPE_PARTNER)
            {
                if(direction >= NUM_DIRECTIONS)
                {
                    sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
                }
                else
                {
                    entity->info->action.direction = direction & DIRECTION_MASK;
                    sub_806CE68(entity, direction);
                }
            }
        }
    }
}

void sub_80859F0(s32 direction)
{
    s32 index;
    struct Entity *entity;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityExists(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                entity->info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
}

bool8 IsMovingClient(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    switch (pokemonInfo->clientType)
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
        case CLIENT_TYPE_PARTNER:
        case CLIENT_TYPE_DONT_MOVE:
        case 0xA:
        case 0xB:
        case 0xC:
        default:
            return FALSE;
    }
}

void sub_8085B0C(struct Entity *pokemon)
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
