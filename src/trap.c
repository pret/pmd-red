#include "global.h"
#include "constants/trap.h"
#include "structs/str_dungeon.h"
#include "trap.h"
#include "code_80521D0.h"

#include "dungeon_items.h"
#include "dungeon_random.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "structs/map.h"
#include "move_effects_target.h"

extern u8 gAvailablePokemonNames[];

extern u8 *gTrapNames[];
extern u8 *gUnknown_80FC5FC[];
extern u8 *gUnknown_80FC5F8[];
extern u8 *gUnknown_80FDB5C[];
extern u8 *gUnknown_80FDB7C[];
extern u8 *gUnknown_80FD7F4[];
extern u8 *gUnknown_80FD7F8[];

extern s16 gUnknown_80F4F84;
extern s16 gUnknown_80F4F86;
extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;


void HandleTripTrap(Entity *pokemon,Entity *target);
void HandleMudTrap(Entity *pokemon,Entity *target);
void HandleStickyTrap(Entity *pokemon,Entity *target);
void HandleGrimyTrap(Entity *pokemon,Entity *target);
void HandleSummonTrap(Entity *pokemon,Position *pos);
void sub_8080504(Entity *pokemon,Entity *target,Tile *tile);
void HandleWarpTrap(Entity *pokemon,Entity *target);
void HandleWhirlwindTrap(Entity *entity,Entity *target);
void HandleSpinTrap(Entity *pokemon,Entity *target);
void HandleSlumberTrap(Entity *pokemon,Entity *target);
void HandleSlowTrap(Entity *pokemon,Entity *target);
void HandleSealTrap(Entity *pokemon,Entity *target);
void HandlePoisonTrap(Entity *pokemon,Entity *target);
void HandleSelfdestructTrap(Entity *pokemon,Entity *target);
void HandleExplosionTrap(Entity *pokemon,Entity *target);
void HandlePPZeroTrap(Entity *pokemon,Entity *target);
void HandleWonderTile(Entity *pokemon,Entity *target);
void HandlePokemonTrap(Entity *pokemon,Position *pos);
void sub_806F324(Entity *,s16,u32,u32);
void sub_806F480(Entity *, u32);
extern void sub_80421C0(u32, u32);
void sub_804225C(Entity *, Position *, u8);
void sub_8071DA4(Entity *);
extern u8 sub_803F428(Position *pos);
void sub_806A1E8(Entity *pokemon);
void sub_8052364(Entity *, Position *, u8 *);
void sub_8049ED4(void);
void sub_80522F4(Entity *r0, Entity *r1, const char r2[]);
u8 sub_803D6FC(void);
Entity *sub_8045684(u8, Position *, u8);

bool8 CanLayTrap(Position *pos)
{
    struct Tile *tile = GetTileSafe(pos->x, pos->y);
    if (tile->terrainType & TERRAIN_TYPE_STAIRS ||
        tile->room == CORRIDOR_ROOM ||
        tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
    {
        return FALSE;
    }
    if (tile->terrainType & TERRAIN_TYPE_SHOP)
    {
        return FALSE;
    }
    if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_NORMAL ||
        (tile->object != NULL && GetEntityType(tile->object) != ENTITY_TRAP))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 LayTrap(Position *pos, u8 trapID, u8 param_3)
{
    Tile *tile;
    Entity *entity;
    int counter;
    u16 terrainType;

    tile = GetTileSafe(pos->x, pos->y);
    if (TRAP_SPIKE_TRAP < trapID) {
        counter = 0;
        while ((counter < 0x1e && (trapID = sub_803D6FC(), trapID == TRAP_WONDER_TILE))) {
            counter++;
        }
        if (counter == 0x1e) {
            trapID = TRAP_CHESTNUT_TRAP;
        }
    }
    terrainType = tile->terrainType;
    if ((terrainType & TERRAIN_TYPE_STAIRS) != 0) goto _0807FD6E;
    if (tile->room == CORRIDOR_ROOM) goto _0807FD6E;
    if ((terrainType & TERRAIN_TYPE_NATURAL_JUNCTION) != 0) goto _0807FD6E;
    if ((terrainType & TERRAIN_TYPE_SHOP) != 0) goto _0807FD6E;
    if (((terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_NORMAL)) goto _0807FD6E;
    if (tile->object != NULL) {
        if (GetEntityType(tile->object) != ENTITY_TRAP) goto _0807FD6E;
        GetTrapData(tile->object)->id = trapID;
        GetTrapData(tile->object)->unk1 = param_3;
        tile->object->isVisible = TRUE;
    }
    else {
        entity = sub_8045684(trapID,pos,param_3);
        if (entity == NULL)
_0807FD6E:
            return FALSE;
        else
        {
                tile->object = entity;
                tile->object->isVisible = TRUE;
        }
    }
    return TRUE;
}

bool8 sub_807FD84(Entity *entity)
{
    bool8 flag;
    flag = FALSE;

    if (gDungeon->unk13570 == 0) {
        return FALSE;
    }
    else {
        gDungeon->unk13570 = 0;
        flag = LayTrap(&gDungeon->trapPos,gDungeon->trapID,gDungeon->unk13579);
        if (flag) {
            sub_8052364(entity,&gDungeon->trapPos,*gUnknown_80FC5F8); // A trap was laid!
        }
        else {
            sub_8052364(entity,&gDungeon->trapPos,*gUnknown_80FC5FC); // A trap can't be laid here.
        }
        sub_8049ED4();
    }
    return flag;
}

bool8 sub_807FE04(Position *pos, char param_2)
{
    Tile *tile;

    tile = GetTileSafe(pos->x,pos->y);
    if ((tile->object != NULL) && (GetEntityType(tile->object) == ENTITY_TRAP)) {
        tile->object->type = 0;
        tile->object = NULL;
        if (param_2 != 0) {
            sub_8049ED4();
        }
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_807FE44(Position *pos, char param_2)
{
    Tile *tile;

    tile = GetTile(pos->x,pos->y);
    if ((tile->object != NULL) && (GetEntityType(tile->object) == ENTITY_TRAP)) {
        tile->object->isVisible = TRUE;
        if (param_2 != 0) {
            sub_8049ED4();
        }
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void GetTrapName(u8 *buffer, u8 trapIndex)
{
    strcpy(buffer, gTrapNames[trapIndex]);
}

void sub_807FE9C(Entity *pokemon, Position *pos, int param_3, char param_4)
{
    Tile *tile;
    bool8 flag1;
    bool8 flag;

    Entity *entity;
    s32 rand;
    Trap *trapData;
    Entity *target;
    u8 *text;

    tile = GetTileSafe(pos->x,pos->y);
    entity = tile->object;
    flag1 = FALSE;
    if (entity == NULL) {
        return;
    }
    if (GetEntityType(entity) != ENTITY_TRAP) {
        return;
    }
    trapData = GetTrapData(entity);
    GetTrapName(gAvailablePokemonNames,trapData->id);
    target = tile->monster;
    if ((target != NULL) && (GetEntityType(target) != ENTITY_MONSTER)) {
        target = NULL;
    }
    flag = entity->isVisible;
    entity->isVisible = TRUE;
    if (((target != NULL) && (sub_806A1E8(target), param_4 != '\0')) && (trapData->id != TRAP_WONDER_TILE)) {
        rand = DungeonRandInt(100);
        text = NULL;
        if (HasHeldItem(target, ITEM_TRAP_SCARF)) {
            text = *gUnknown_80FDB5C;
        }
        if ((flag == TRUE) || (gDungeon->unk1820F != 0)) {
            if (rand < 0) text = *gUnknown_80FDB7C;
        }
        else if (rand < 0xf) {
            text = *gUnknown_80FDB7C;
        }
        if (text != NULL) {
            if (sub_803F428(pos) != '\0') {
                sub_8049ED4();
            }
            sub_80522F4(pokemon,target,text);
            if (param_3 == 0) {
                return;
            }
        }
    }
    if (sub_803F428(pos) != '\0') {
        sub_80421C0(0,0x15c);
        sub_8049ED4();
        sub_804225C(pokemon,pos,trapData->id);
        if (gDungeon->blinded) {
            SendMessage(pokemon,*gUnknown_80FD7F4);
        }
        else {
            SendMessage(pokemon,(gUnknown_80FD7F8)[trapData->id]);
        }
    }
    if (target != NULL) {
        if (trapData->unk1 == 2) {
            sub_806F480(target,1);
        }
        else if (trapData->unk1 == 1) {
            sub_806F480(target,0);
        }
    }
    switch(trapData->id) {
        case TRAP_TRIP_TRAP:
            HandleTripTrap(pokemon,target);
            break;
        case TRAP_MUD_TRAP:
            HandleMudTrap(pokemon,target);
            break;
        case TRAP_STICKY_TRAP:
            HandleStickyTrap(pokemon,target);
            break;
        case TRAP_GRIMY_TRAP:
            HandleGrimyTrap(pokemon,target);
            break;
        case TRAP_SUMMON_TRAP:
            HandleSummonTrap(pokemon,pos);
            flag1 = TRUE;
            break;
        case TRAP_PITFALL_TRAP:
        case 0x1B: // ???
            sub_8080504(pokemon,target,tile);
            break;
        case TRAP_WARP_TRAP:
            HandleWarpTrap(pokemon,target);
            break;
        case TRAP_WHIRLWIND_TRAP:
            HandleWhirlwindTrap(entity,target);
            break;
        case TRAP_SPIN_TRAP:
            HandleSpinTrap(pokemon,target);
            break;
        case TRAP_SLUMBER_TRAP:
            HandleSlumberTrap(pokemon,target);
            break;
        case TRAP_SLOW_TRAP:
            HandleSlowTrap(pokemon,target);
            break;
        case TRAP_SEAL_TRAP:
            HandleSealTrap(pokemon,target);
            break;
        case TRAP_POISON_TRAP:
            HandlePoisonTrap(pokemon,target);
            break;
        case TRAP_SELFDESTRUCT_TRAP:
            HandleSelfdestructTrap(pokemon,target);
            break;
        case TRAP_EXPLOSION_TRAP:
            HandleExplosionTrap(pokemon,target);
            break;
        case TRAP_PP_ZERO_TRAP:
            HandlePPZeroTrap(pokemon,target);
            break;
        case TRAP_CHESTNUT_TRAP:
            if (target != NULL) {
                sub_806F324(target,gUnknown_80F4F86,0xf,0x213);
            }
            break;
        case TRAP_WONDER_TILE:
            HandleWonderTile(pokemon,target);
            break;
        case TRAP_POKEMON_TRAP:
            HandlePokemonTrap(pokemon,pos);
            flag1 = TRUE;
            break;
        case TRAP_SPIKE_TRAP:
            if (target != NULL) {
                sub_806F324(target,gUnknown_80F4F84,10,0x206);
            }
    }
    if (EntityExists(target)) {
        sub_8071DA4(target);
    }
    if (flag1) {
        sub_807FE04(pos,1);
    }
}

void HandleMudTrap(Entity *pokemon, Entity *target)
{
    int rand;
#ifdef NONMATCHING
    int rand1;
#else
    register int rand1 asm("r1");
#endif

    if (target != NULL) {
        rand1 = rand = DungeonRandInt(100);
        if (rand <= 0x18) {
            LowerAttackStageTarget(pokemon,target,gUnknown_8106A4C,1,1,1);
        }
        else if (0x32 > rand) {
            LowerAttackStageTarget(pokemon,target,gUnknown_8106A50,1,1,1);
        }
        else if (rand1 < 0x4b) {
            LowerDefenseStageTarget(pokemon,target,gUnknown_8106A4C,1,1,1);
        }
        else {
            LowerDefenseStageTarget(pokemon,target,gUnknown_8106A50,1,1,1);
        }
    }
}
