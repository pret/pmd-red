#include "global.h"
#include "constants/type.h"
#include "constants/trap.h"
#include "structs/str_dungeon.h"
#include "trap.h"
#include "status.h"
#include "code_80521D0.h"
#include "items.h"
#include "moves.h"
#include "code_808417C.h"

#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "structs/map.h"
#include "move_effects_target.h"

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];

extern u8 *gTrapNames[];
extern u8 *gUnknown_80FC5FC[];
extern u8 *gUnknown_80FC5F8[];
extern u8 *gUnknown_80FDB5C[];
extern u8 *gUnknown_80FDB7C[];
extern u8 *gUnknown_80FD7F4[];
extern u8 *gUnknown_80FD7F8[];
extern s16 gUnknown_80F4E74[];
extern u8 *gUnknown_80FDC18[];
extern u8 *gUnknown_80FDC40[];
extern u8 *gUnknown_80FDC7C[];
extern u8 *gUnknown_80FD7AC[];
extern u8 *gUnknown_80FD788[];
extern u8 *gUnknown_80FD7D4[];
extern u8 *gUnknown_80F970C[];
extern u8 *gUnknown_80F9728[];
extern u8 *gUnknown_80FED00[];
extern u8 *gUnknown_80FED04[];
extern u8 *gUnknown_80FED0C[];
extern u8 *gUnknown_80FDAA0[];
extern u8 *gUnknown_80FDA80[];

extern s16 gUnknown_80F4E0E;
extern s16 gUnknown_80F4F84;
extern s16 gUnknown_80F4F86;
extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4F8A;

struct unkStruct_806B7F8
{
    s16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    u8 fillA[2];
    struct Position pos;
    u8 unk10;
};
extern u32 sub_806B7F8(struct unkStruct_806B7F8 *, u32);

void sub_806A9B4(Entity *, u32);

void sub_8079E34(Entity *param_1, Entity *param_2, u32);
s16 sub_803D970(u32);
u8 sub_806AA0C(s32, s32);
void sub_80421EC(Position *, u32);

bool8 sub_8045888(Entity *);
void SetTrap(Tile *, u32);
void sub_803E708(u32, u32);
u8 sub_8043D10(void);
void SetMessageArgument(u8 *, Entity *, u32);
void sub_8068FE0(Entity *, u32, Entity *);
void sub_805239C(Entity *, u8 *);
void sub_8045C28(Item *, u8 , u8);
void sub_8045BF8(u8 *, Item *);
void HandleTripTrap(Entity *pokemon,Entity *target);
void HandleMudTrap(Entity *pokemon,Entity *target);
void HandleStickyTrap(Entity *pokemon,Entity *target);
void HandleGrimyTrap(Entity *pokemon,Entity *target);
void HandleSummonTrap(Entity *pokemon,Position *pos);
void HandlePitfallTrap(Entity *pokemon,Entity *target,Tile *tile);
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
extern void sub_80421C0(Entity *, u32);
void sub_804225C(Entity *, Position *, u8);
void sub_8071DA4(Entity *);
extern u8 sub_803F428(Position *pos);
void sub_806A1E8(Entity *pokemon);
void sub_8052364(Entity *, Position *, u8 *);
void sub_8049ED4(void);
void sub_80522F4(Entity *r0, Entity *r1, const char r2[]);
u8 sub_803D6FC(void);
Entity *sub_8045684(u8, Position *, u8);
extern void sub_807D148(Entity *pokemon, Entity *target, u32 r2, Position *r3);
extern void sub_807DF38(Entity *pokemon, Entity *target, Position *pos, u32, u8 moveType, s16);

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
            HandlePitfallTrap(pokemon,target,tile);
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

// https://decomp.me/scratch/Yq32k (Seth)

#ifdef NONMATCHING
void HandleStickyTrap(Entity *pokemon,Entity *target)
{
  EntityInfo *info;
  Item *item;
  Item *pbVar3;
  int index;
  int itemCount;
  int newIndex;
  Item *itemStack [20];
  bool32 flag;

  info = target->info;
  if (HasHeldItem(target,0xe)) {
    sub_80522F4(pokemon,target,*gUnknown_80FDC7C);
  }
  else
  {
    itemCount = 0;
    if (flag = info->isTeamLeader, item = &info->heldItem, flag != '\0') {
      for(index = 0; index < 0x14; index++)
      {
        pbVar3 = &gTeamInventoryRef->teamItems[index];
        if ((((pbVar3->flags & 1) != 0) && (IsNotSpecialItem(pbVar3->id))) &&
           (gTeamInventoryRef->teamItems[index].flags & 8) == 0) {
              itemStack[itemCount] = pbVar3;
              itemCount++;
        }
      }
    }
    if ((((item->flags & 1) != 0) && (IsNotSpecialItem((info->heldItem).id)))
       && ((item->flags & 8) == 0)) {
      itemStack[itemCount] = item;
      itemCount = itemCount + 1;
    }
    if (itemCount == 0) {
        sub_80522F4(pokemon,target,*gUnknown_80FDC40);
    }
    else
    {
      newIndex = DungeonRandInt(itemCount);
      sub_8045BF8(gUnknown_202DE58, itemStack[newIndex]);
      itemStack[newIndex]->flags |= 8;
      sub_80421C0(target, 0x192);
      sub_80522F4(pokemon,target,*gUnknown_80FDC18);
    }
  }
}
#else
NAKED
void HandleStickyTrap(Entity *pokemon,Entity *target)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmov r7, r10\n"
	"\tmov r6, r9\n"
	"\tmov r5, r8\n"
	"\tpush {r5-r7}\n"
	"\tsub sp, 0x5C\n"
	"\tstr r0, [sp, 0x54]\n"
	"\tmov r10, r1\n"
	"\tldr r0, [r1, 0x70]\n"
	"\tmov r8, r0\n"
	"\tmov r0, r10\n"
	"\tmovs r1, 0xE\n"
	"\tbl HasHeldItem\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08080278\n"
	"\tldr r0, _08080274\n"
	"\tb _08080300\n"
	"\t.align 2, 0\n"
"_08080274: .4byte gUnknown_80FDC7C\n"
"_08080278:\n"
	"\tmovs r6, 0\n"
	"\tmov r1, r8\n"
	"\tldrb r0, [r1, 0x7]\n"
	"\tmovs r1, 0x60\n"
	"\tadd r1, r8\n"
	"\tmov r9, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _080802C8\n"
	"\tmovs r5, 0\n"
	"\tldr r7, _0808030C\n"
	"\tmov r0, sp\n"
	"\tstr r0, [sp, 0x58]\n"
"_08080290:\n"
	"\tlsls r4, r5, 2\n"
	"\tldr r0, [r7]\n"
	"\tadds r2, r4, r0\n"
	"\tldrb r1, [r2]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _080802C2\n"
	"\tldrb r0, [r2, 0x2]\n"
	"\tbl IsNotSpecialItem\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _080802C2\n"
	"\tldr r0, [r7]\n"
	"\tadds r2, r0, r4\n"
	"\tldrb r1, [r2]\n"
	"\tmovs r0, 0x8\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbne _080802C2\n"
	"\tldr r1, [sp, 0x58]\n"
	"\tstm r1!, {r2}\n"
	"\tstr r1, [sp, 0x58]\n"
	"\tadds r6, 0x1\n"
"_080802C2:\n"
	"\tadds r5, 0x1\n"
	"\tcmp r5, 0x13\n"
	"\tble _08080290\n"
"_080802C8:\n"
	"\tmov r0, r9\n"
	"\tldrb r1, [r0]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _080802FA\n"
	"\tmov r0, r8\n"
	"\tadds r0, 0x62\n"
	"\tldrb r0, [r0]\n"
	"\tbl IsNotSpecialItem\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _080802FA\n"
	"\tmov r0, r9\n"
	"\tldrb r1, [r0]\n"
	"\tmovs r0, 0x8\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbne _080802FA\n"
	"\tlsls r0, r6, 2\n"
	"\tadd r0, sp\n"
	"\tmov r1, r9\n"
	"\tstr r1, [r0]\n"
	"\tadds r6, 0x1\n"
"_080802FA:\n"
	"\tcmp r6, 0\n"
	"\tbne _08080314\n"
	"\tldr r0, _08080310\n"
"_08080300:\n"
	"\tldr r2, [r0]\n"
	"\tldr r0, [sp, 0x54]\n"
	"\tmov r1, r10\n"
	"\tbl sub_80522F4\n"
	"\tb _0808034A\n"
	"\t.align 2, 0\n"
"_0808030C: .4byte gTeamInventoryRef\n"
"_08080310: .4byte gUnknown_80FDC40\n"
"_08080314:\n"
	"\tadds r0, r6, 0\n"
	"\tbl DungeonRandInt\n"
	"\tldr r2, _0808035C\n"
	"\tlsls r0, 2\n"
	"\tmov r1, sp\n"
	"\tadds r4, r1, r0\n"
	"\tldr r1, [r4]\n"
	"\tadds r0, r2, 0\n"
	"\tbl sub_8045BF8\n"
	"\tldr r2, [r4]\n"
	"\tldrb r1, [r2]\n"
	"\tmovs r0, 0x8\n"
	"\torrs r0, r1\n"
	"\tstrb r0, [r2]\n"
	"\tmovs r1, 0xC9\n"
	"\tlsls r1, 1\n"
	"\tmov r0, r10\n"
	"\tbl sub_80421C0\n"
	"\tldr r0, _08080360\n"
	"\tldr r2, [r0]\n"
	"\tldr r0, [sp, 0x54]\n"
	"\tmov r1, r10\n"
	"\tbl sub_80522F4\n"
"_0808034A:\n"
	"\tadd sp, 0x5C\n"
	"\tpop {r3-r5}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tmov r10, r5\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808035C: .4byte gUnknown_202DE58\n"
"_08080360: .4byte gUnknown_80FDC18");

}
#endif

void HandleSpinTrap(Entity *pokemon, Entity *target)
{
    if(target != NULL)
        ConfuseStatusTarget(pokemon, target, TRUE);
}

void HandleWarpTrap(Entity *pokemon, Entity *target)
{
    if(target != NULL)
        sub_807D148(pokemon, target, 0, NULL);
}

void HandleSlumberTrap(Entity *pokemon, Entity *target)
{
    s32 turns;

    if(target != NULL)
    {
        turns  = CalculateStatusTurns(target, gUnknown_80F4E74, TRUE);
        sub_8075C58(pokemon, target, turns, TRUE);
    }
}

void HandleSlowTrap(Entity *pokemon, Entity *target)
{
    if(target != NULL)
        LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
}

void HandlePoisonTrap(Entity *pokemon, Entity *target)
{
    if(target != NULL)
        PoisonedStatusTarget(pokemon, target, TRUE);
}

void HandleSelfdestructTrap(Entity *pokemon, Entity *target)
{
    sub_807DF38(pokemon, target, &target->pos, 1, TYPE_NONE, 0x212);
}

void HandleExplosionTrap(Entity *pokemon, Entity *target)
{
    sub_807DF38(pokemon, target, &target->pos, 2, TYPE_NONE, 0x212);
}

void HandleGrimyTrap(Entity *pokemon, Entity *target)
{
    Item *item;
    Item *heldItem;
    int counter;
    int index;
    EntityInfo *info;
    int badFoodCount;
    Item *itemStack [22];

    badFoodCount = 0;
    if (target != NULL) {
        info = target->info;
        counter = 0;
        if (info->isTeamLeader) {
            for(index = 0; index < INVENTORY_SIZE; index++)
            {
                item = &gTeamInventoryRef->teamItems[index];
                if ((item->flags & ITEM_FLAG_EXISTS)) {
                    itemStack[counter] = item;
                    counter++;
                }
            }
        }
        heldItem = &info->heldItem;
        if ((heldItem->flags & ITEM_FLAG_EXISTS)) {
            itemStack[counter] = heldItem;
            counter++;
        }
        for (index = 0; index < counter; index++) {
            if (((GetItemCategory(itemStack[index]->id) == CATEGORY_FOOD_GUMMIES) && (itemStack[index]->id != ITEM_GRIMY_FOOD)) &&
                (DungeonRandInt(100) < gUnknown_80F4E0E)) {
                badFoodCount++;
                sub_8045C28(itemStack[index], ITEM_GRIMY_FOOD, 2);
            }
        }
        if (badFoodCount == 1) {
            sub_80522F4(pokemon,target,*gUnknown_80FD788); // A food item went bad.
        }
        else if (badFoodCount == 0) {
            sub_80522F4(pokemon,target,*gUnknown_80FD7D4); // Nothing particularly bad happened.
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FD7AC); // Several food items went bad
        }
    }
}

void HandlePitfallTrap(Entity *pokemon, Entity *target, Tile *tile)
{
    bool8 flag;
    EntityInfo *info;

    flag = FALSE;
    if (target != NULL) {
        if (IsBossFight()) {
            SendMessage(pokemon,*gUnknown_80FED0C); // But nothing happened...
        }
        else
        {
            info = target->info;
            if (sub_8045888(target)) {
                SetTrap(tile, 0x1B);
                flag = TRUE;
                sub_80421C0(target,0x193);
                sub_803E708(0x1e,0x48);
            }
            if (info->isTeamLeader) {
                if (sub_8043D10() != 2) {
                    info->unk15C = 1;
                    info->unk15E = 1;
                    sub_803E708(0x28,0x4b);
                    sub_806F324(target,gUnknown_80F4F8A,0x11,0x215);
                    gDungeon->unk2 = 2;
                    return;
                }
                SendMessage(pokemon,*gUnknown_80F9728);
            }
            else
            {
                SetMessageArgument(gAvailablePokemonNames,target,0);
                if (info->isNotTeamMember) {
                    sub_80522F4(pokemon,target,*gUnknown_80F970C); // $m0 fell into the pitfall!
                }
                else {
                    sub_805239C(pokemon,*gUnknown_80F970C); // $m0 fell into the pitfall!
                }
                sub_8068FE0(target,0x215,pokemon);
            }
            if (flag) {
                SetTrap(tile, TRAP_PITFALL_TRAP);
            }
        }
    }
}

void HandleSummonTrap(Entity *pokemon,Position *pos)
{
  s32 r4;
  u32 direction;
  int pokemonSummonCount;
  s16 species;
  struct unkStruct_806B7F8 stack;
  s32 i;


  r4 = DungeonRandInt(3) + 2;
  direction = DungeonRandInt(NUM_DIRECTIONS);
  if (IsBossFight()) {
      goto _ret;
  }
  else
  {
    pokemonSummonCount = 0;
    if (pokemonSummonCount < r4) {
        for (i = 0; i < r4; i++)
        {
            species = sub_803D970(0);
            direction &= DIRECTION_MASK;
            stack.species = species;
            if (sub_806AA0C(stack.species,0) != 0) {
              stack.level = 0;
              stack.unk2 = 0;
              stack.pos.x = pos->x + gAdjacentTileOffsets[direction].x;
              stack.pos.y = pos->y + gAdjacentTileOffsets[direction].y;
              stack.unk4 = 0;
              stack.unk10 = 0;
              if (sub_806B7F8(&stack,1) != 0) {
                pokemonSummonCount++;
              }
            }
            direction++;
        }
    }
    sub_80421EC(pos,0x194);
    if (pokemonSummonCount == 0) {
_ret:
        SendMessage(pokemon,*gUnknown_80FED04);
    }
    else
    {
        SendMessage(pokemon,*gUnknown_80FED00);
    }
  }
}

void HandlePPZeroTrap(Entity *param_1,Entity *param_2)
{
  Move *move;
  s32 moveIndex;
  s32 i;
  s32 counter;
  EntityInfo *info;
  Move *moveStack [MAX_MON_MOVES];
  s32 indexStack [MAX_MON_MOVES];
  bool8 flag = FALSE;
  

  if (param_2 != NULL) {
    info = param_2->info;
    counter = 0;
    for(i = 0;  i < MAX_MON_MOVES; move++, i++)
    {
      move = &info->moves[i];
      if (((move->moveFlags & MOVE_FLAG_EXISTS) != 0) && (move->PP != 0)) {
        moveStack[counter] = move;
        indexStack[counter] = i;
        counter++;
      }
    }
    if (counter != 0) {
      moveIndex = DungeonRandInt(counter);
      moveStack[moveIndex]->PP = 0;
      sub_80928C0(gUnknown_202DE58,moveStack[moveIndex],0);
      sub_806A9B4(param_2, indexStack[moveIndex]);
      flag = TRUE;
    }
    if(flag)
        sub_80522F4(param_1,param_2,*gUnknown_80FDA80);
    else
        sub_80522F4(param_1,param_2,*gUnknown_80FDAA0);
  }
}

void HandleWonderTile(Entity *param_1, Entity *param_2)
{
    sub_8079E34(param_1, param_2, 0);
}
