#include "global.h"
#include "dungeon_util_1.h"
#include "dungeon_misc.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_806CD90.h"
#include "constants/direction.h"
#include "constants/dungeon.h"
#include "code_80861A8.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "random.h"
#include "math.h"
#include "structs/str_dungeon.h"

extern s32 gUnknown_202F3D8;
extern const u8 gUnknown_8107358[25];

extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F4A0(u32);
extern void sub_803F878(s32, s32);

Entity *xxx_call_GetLeader(void)
{
    return GetLeader();
}

Entity *GetPartnerEntity(void)
{
    s32 counter;
    Entity *entity;
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        entity = gDungeon->teamPokemon[counter];
        if(EntityIsValid(entity) && GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            return entity;
        }
    }
    return GetEntityFromMonsterBehavior(BEHAVIOR_ALLY);
}

void sub_80854D4(void)
{
    Entity *stack1[MAX_TEAM_MEMBERS];
    Entity *stack2[MAX_TEAM_MEMBERS];
    s32 counter = 0;
    s32 index;
    Entity *entity;
    Entity *entity2;
    Entity *entity3;
    Entity *entity4;
    Entity *entity5;

    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityIsValid(entity))
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
        if(entity2 != NULL && GetEntInfo(entity2)->isTeamLeader)
        {
            stack1[index] = NULL;
            stack2[counter] = entity2;
            counter++;
        }
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity3 = stack1[index];
        if(entity3 != NULL && GetEntInfo(entity3)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
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
    Entity * entity;
    Entity * partnerEntity;
    s32 index;

    flag = FALSE;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if (EntityIsValid(entity)) {
            if (GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER) {
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
    Entity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->joinedAt.id != 0x41)) {
            func(entity);
        }
    }
}

Entity *GetEntityFromMonsterBehavior(u8 entityType)
{
    Entity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->monsterBehavior == entityType)) return entity;
    }
    return NULL;
}

void sub_80856C8(Entity * pokemon, s32 x, s32 y)
{
    sub_80694C0(pokemon, x, y, 1);
    sub_804535C(pokemon,NULL);
}

void sub_80856E0(Entity * pokemon, s32 direction)
{
    EntityInfo *entityInfo;
    s32 counter;

    entityInfo = GetEntInfo(pokemon);
    sub_80861D4(pokemon, 6, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 = F248_Add(entityInfo->unk174, IntToF248(2));
        DungeonRunFrameActions(0x46);
    }
    entityInfo->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 = F248_Sub(entityInfo->unk174, IntToF248(2));
        DungeonRunFrameActions(0x46);
    }
    entityInfo->unk174.raw = 0; // weird one that doesn't match with struct assignment
    DungeonRunFrameActions(0x46);
}

void sub_8085764(void)
{
    Entity *entity;
    s32 index;
    Entity stackEntity;

    sub_80457DC(&stackEntity);
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->monsterBehavior == BEHAVIOR_ALLY)) {
            sub_8068FE0(entity,0x207,&stackEntity);
        }
    }
}

void sub_80857B8(void)
{
    u8 *direction;
    EntityInfo *entityInfo;
    Entity *entity;
    int index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if (EntityIsValid(entity)) {
            entityInfo = GetEntInfo(entity);
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
  sub_803F878(X_POS_TO_PIXELPOS(x), Y_POS_TO_PIXELPOS(y));
}

void sub_8085890(s32 x, s32 y)
{
    sub_803F4A0(0);
    sub_803F878(x, y);
}

void ShiftCameraToPosition(PixelPos *posStruct, s32 cameraSteps)
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
      DungeonRunFrameActions(0x46);
      cameraSteps--;
    } while (cameraSteps != 0);
  }
  sub_803F878(posStruct->x,posStruct->y);
  DungeonRunFrameActions(0x46);
}

void SetFacingDirection(Entity *pokemon, s32 direction)
{
    GetEntInfo(pokemon)->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);
}

void sub_8085930(s32 direction)
{
    s32 index;
    Entity *entity;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityIsValid(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityIsValid(entity))
        {
            if(GetEntInfo(entity)->monsterBehavior == BEHAVIOR_ALLY)
            {
                if(direction >= NUM_DIRECTIONS)
                {
                    sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
                }
                else
                {
                    GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                    sub_806CE68(entity, direction);
                }
            }
        }
    }
}

void sub_80859F0(s32 direction)
{
    s32 index;
    Entity *entity;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityIsValid(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
}

bool8 ShouldRunMonsterAI(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    switch (pokemonInfo->monsterBehavior)
    {
        case BEHAVIOR_RESCUE_TARGET:
        case BEHAVIOR_SKARMORY:
        case BEHAVIOR_GENGAR:
        case BEHAVIOR_EKANS:
        case BEHAVIOR_MEDICHAM:
        case BEHAVIOR_ZAPDOS:
        case BEHAVIOR_MOLTRES:
        case BEHAVIOR_ARTICUNO:
        case BEHAVIOR_GROUDON_2:
        case BEHAVIOR_RAYQUAZA:
        case BEHAVIOR_MANKEY:
        case BEHAVIOR_MEWTWO:
        case BEHAVIOR_ENTEI:
        case BEHAVIOR_RAIKOU:
        case BEHAVIOR_SUICUNE:
        case BEHAVIOR_HO_OH:
        case BEHAVIOR_LATIOS:
        case BEHAVIOR_REGIROCK:
        case BEHAVIOR_REGICE:
        case BEHAVIOR_REGISTEEL:
        case BEHAVIOR_JIRACHI:
        case BEHAVIOR_LUGIA:
        case BEHAVIOR_KYOGRE:
        case BEHAVIOR_29:
        case BEHAVIOR_CELEBI:
        case BEHAVIOR_SMEARGLE:
        case BEHAVIOR_32:
        case BEHAVIOR_33:
        case BEHAVIOR_34:
        case BEHAVIOR_35:
        case BEHAVIOR_MAZE_BOSS:
            return TRUE;
        case BEHAVIOR_FIXED_ENEMY:
        case BEHAVIOR_ALLY:
        case BEHAVIOR_DIGLETT:
        case BEHAVIOR_ALAKAZAM_1:
        case BEHAVIOR_GROUDON_1:
        case BEHAVIOR_ALAKAZAM_2:
        default:
            return FALSE;
    }
}

void sub_8085B0C(Entity *pokemon)
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

void sub_8085B4C(struct_8085B80 a0[], s16 *a1[], Entity *a2[], s32 a3)
{
    s32 i;

    gUnknown_202F3D8 = a3;

    for (i = 0; i < a3; i++) {
        a0[i].unk0 = 1;
        a0[i].unk4 = a2[i];
        a0[i].unkC = a1[i];
        a0[i].unk8 = a1[i][2];
    }
}

bool8 sub_8085B80(struct_8085B80 *a0)
{
    s16 *unkCPtr;
    int i;
    bool8 ret = FALSE;

    for (i = 0; i < gUnknown_202F3D8; i++) {
        Entity *entity = a0[i].unk4;
        EntityInfo *enInfo = GetEntInfo(entity);
        unkCPtr = a0[i].unkC;
        if (a0[i].unk0 != 0) {
            ret = TRUE;
            if (a0[i].unk8 == 0) {
                unkCPtr = unkCPtr + 4;
                if (unkCPtr[2] == 0) {
                    a0[i].unk0 = 0;
                    enInfo->action.direction = unkCPtr[0] & DIRECTION_MASK;
                    sub_806CDD4(entity, 7, unkCPtr[0]);
                    sub_80856C8(entity, unkCPtr[5], unkCPtr[6]);
                    continue;
                }
                a0[i].unk8 = unkCPtr[2];
                a0[i].unkC = unkCPtr;
              enInfo->action.direction = unkCPtr[0] & DIRECTION_MASK;
                sub_806CDD4(entity, 0, (int)*unkCPtr);
            }

            a0[i].unk8--;
            IncreaseEntityPixelPos(entity,
                gAdjacentTileOffsets[*unkCPtr].x * unkCPtr[1] * 0x100,
                gAdjacentTileOffsets[*unkCPtr].y * unkCPtr[1] * 0x100);
        }
    }
    return ret;
}
