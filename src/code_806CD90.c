#include "global.h"
#include "constants/direction.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"

extern struct DungeonGlobalData *gDungeonGlobalData;

extern u8 sub_806CEBC(struct DungeonEntity *);
extern void sub_806CCB4(struct DungeonEntity *, u8);

void sub_806CD90(void)
{
    s32 iVar3;
    struct DungeonEntity *iVar2;
    for(iVar3 = 0; iVar3 < DUNGEON_MAX_POKEMON; iVar3++)
    {
        iVar2 = gDungeonGlobalData->allPokemon[iVar3];
        if(EntityExists(iVar2))
            sub_806CCB4(iVar2, sub_806CEBC(iVar2));
    }
}

void sub_806CDD4(struct DungeonEntity *r0, u8 r1, u32 r2)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = r1;
        if(r2 < NUM_DIRECTIONS) r0->facingDir = r2;
    }
}

void sub_806CDFC(struct DungeonEntity *r0, u8 r1, u32 r2)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        if(r0->unk6B == r1)
        {
            if(r0->facingDir2 == r2)
                return;
            else
                goto change_dir;
        }
        else
        {
change_dir:
            sub_806CDD4(r0, r1, r2);
        }
    }
}

void sub_806CE34(struct DungeonEntity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = sub_806CEBC(r0);
        if(newDir < NUM_DIRECTIONS)
        {
            r0->entityData->action.facingDir = newDir & DIRECTION_MASK;
            r0->facingDir = newDir & DIRECTION_MASK;
        }
    }
}

void sub_806CE68(struct DungeonEntity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = sub_806CEBC(r0);
        if(newDir < NUM_DIRECTIONS)
        {
            r0->facingDir = newDir;
        }
    }
}

void sub_806CE94(struct DungeonEntity *r0, u32 newDir)
{
    if(GetEntityType(r0) == ENTITY_POKEMON)
    {
        r0->unk6A = 6;
        if(newDir < NUM_DIRECTIONS)
        {
            r0->facingDir = newDir;
        }
    }
}
