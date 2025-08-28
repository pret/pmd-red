#include "global.h"
#include "globaldata.h"
#include "trap.h"
#include "dungeon_tilemap.h"
#include "code_8041AD0.h"
#include "dungeon_message.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "code_806CD90.h"
#include "constants/trap.h"
#include "constants/type.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_vram.h"
#include "dungeon_spawns.h"
#include "items.h"
#include "move_effects_target.h"
#include "moves.h"
#include "status.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "structs/str_806B7F8.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_strings.h"
#include "sprite.h"
#include "dungeon_pos_data.h"
#include "dungeon_damage.h"

extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;

bool8 sub_806AA0C(s32, s32);
void sub_80421EC(DungeonPos *, u32);
u8 GetFloorType(void);
void sub_8045BF8(u8 *, Item *);
void sub_804225C(Entity *, DungeonPos *, u8);
void EnemyEvolution(Entity *);
void sub_806A1E8(Entity *pokemon);
Entity *sub_8045684(u8, DungeonPos *, u8);
extern void HandleExplosion(Entity *pokemon, Entity *target, DungeonPos *pos, u32, u8 moveType, s16);

void sub_807FA18(void)
{
    s32 x, y;

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            Tile *tile = GetTileMut(x, y);

            if (tile->spawnOrVisibilityFlags.spawn & SPAWN_FLAG_TRAP) {
                s32 trapId;
                DungeonPos pos = {x, y};

                if (tile->spawnOrVisibilityFlags.spawn & SPAWN_FLAG_UNK6) {
                    trapId = TRAP_WARP_TRAP;
                }
                else {
                    trapId = GetRandomFloorTrap();
                }

                if (trapId == TRAP_WONDER_TILE) {
                    Entity *trap = SpawnTrap(trapId, &pos, 2);
                    if (trap != NULL) {
                        tile->object = trap;
                        trap->isVisible = TRUE;
                    }
                }
                else {
                    Entity *trap = SpawnTrap(trapId, &pos, 0);
                    if (trap != NULL) {
                        tile->object = trap;
                        trap->isVisible = FALSE;
                    }
                }
            }
        }
    }
}

void sub_807FA9C(void)
{
    s32 x, y;
    bool8 showInvisibles = gDungeon->unk181e8.showInvisibleTrapsMonsters;

    for (y = gDungeon->unk181e8.cameraPos.y - 5; y < gDungeon->unk181e8.cameraPos.y + 5; y++) {
        for (x = gDungeon->unk181e8.cameraPos.x - 6; x < gDungeon->unk181e8.cameraPos.x + 6; x++) {
            bool8 r6 = FALSE;
            const Tile *tile = GetTile(x, y);

            if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP && (tile->object->isVisible || showInvisibles)) {
                r6 = TRUE;
            }
            if (tile->terrainFlags & TERRAIN_TYPE_STAIRS) {
                r6 = TRUE;
            }

            if (r6) {
                s32 spriteX = (x * 24) - gDungeon->unk181e8.cameraPixelPos.x;
                s32 spriteY = (y * 24) - gDungeon->unk181e8.cameraPixelPos.y;
                if (spriteX >= -32 && spriteY >= -32 && spriteX <= 272 && spriteY <= 192)  {
                    SpriteSetObjMode(&gUnknown_202EDC0, 0);
                    SpriteSetY(&gUnknown_202EDC0, spriteY);
                    SpriteSetX(&gUnknown_202EDC0, spriteX);
                    SpriteSetPriority(&gUnknown_202EDC0, 3);
                    SpriteSetPalNum(&gUnknown_202EDC0, 10);
                    SpriteSetTileNum(&gUnknown_202EDC0, 0x1FC);

                    AddSprite(&gUnknown_202EDC0, 0, NULL, NULL);
                }
            }
        }
    }
}

void sub_807FC3C(DungeonPos *pos, u32 trapID, u32 param_3)
{
  gDungeon->trapPos.x = pos->x;
  gDungeon->trapPos.y = pos->y;
  gDungeon->trapID = trapID;
  gDungeon->unk13579 = param_3;
  gDungeon->unk13570 = 1;
}

bool8 CanLayTrap(DungeonPos *pos)
{
    Tile *tile = GetTileMut(pos->x, pos->y);
    if (tile->terrainFlags & TERRAIN_TYPE_STAIRS)
        return FALSE;

    if (tile->room == CORRIDOR_ROOM)
        return FALSE;

    if (tile->terrainFlags & TERRAIN_TYPE_NATURAL_JUNCTION)
        return FALSE;

    if (tile->terrainFlags & TERRAIN_TYPE_SHOP)
        return FALSE;

    if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
        return FALSE;

    if (tile->object != NULL) {
        if (GetEntityType(tile->object) != ENTITY_TRAP)
            return FALSE;
        else
            return TRUE;
    }

    return TRUE;
}

bool8 LayTrap(DungeonPos *pos, u8 trapID, u8 param_3)
{
    Tile *tile;
    Entity *entity;
    int counter;
    u16 terrainFlags;

    tile = GetTileMut(pos->x, pos->y);
    if (TRAP_SPIKE_TRAP < trapID) {
        counter = 0;
        while ((counter < 0x1e && (trapID = GetRandomFloorTrap(), trapID == TRAP_WONDER_TILE))) {
            counter++;
        }
        if (counter == 0x1e) {
            trapID = TRAP_CHESTNUT_TRAP;
        }
    }
    terrainFlags = tile->terrainFlags;
    if ((terrainFlags & TERRAIN_TYPE_STAIRS) != 0) goto _0807FD6E;
    if (tile->room == CORRIDOR_ROOM) goto _0807FD6E;
    if ((terrainFlags & TERRAIN_TYPE_NATURAL_JUNCTION) != 0) goto _0807FD6E;
    if ((terrainFlags & TERRAIN_TYPE_SHOP) != 0) goto _0807FD6E;
    if (((terrainFlags & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_NORMAL)) goto _0807FD6E;
    if (tile->object != NULL) {
        if (GetEntityType(tile->object) != ENTITY_TRAP) goto _0807FD6E;
        GetTrapInfo(tile->object)->id = trapID;
        GetTrapInfo(tile->object)->unk1 = param_3;
        tile->object->isVisible = TRUE;
    }
    else {
        entity = SpawnTrap(trapID,pos,param_3);
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
            LogMessageByIdWithPopupCheckUserUnknown(entity,&gDungeon->trapPos,gUnknown_80FC5F8); // A trap was laid!
        }
        else {
            LogMessageByIdWithPopupCheckUserUnknown(entity,&gDungeon->trapPos,gUnknown_80FC5FC); // A trap can't be laid here.
        }
        UpdateTrapsVisibility();
    }
    return flag;
}

bool8 sub_807FE04(DungeonPos *pos, char param_2)
{
    Tile *tile;

    tile = GetTileMut(pos->x,pos->y);
    if ((tile->object != NULL) && (GetEntityType(tile->object) == ENTITY_TRAP)) {
        tile->object->type = 0;
        tile->object = NULL;
        if (param_2 != 0) {
            UpdateTrapsVisibility();
        }
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_807FE44(DungeonPos *pos, char param_2)
{
    const Tile *tile;

    tile = GetTile(pos->x,pos->y);
    if ((tile->object != NULL) && (GetEntityType(tile->object) == ENTITY_TRAP)) {
        tile->object->isVisible = TRUE;
        if (param_2 != 0) {
            UpdateTrapsVisibility();
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

void TryTriggerTrap(Entity *pokemon, DungeonPos *pos, int param_3, char param_4)
{
    Tile *tile;
    bool8 flag1;
    bool8 flag;

    Entity *entity;
    s32 rand;
    Trap *trapData;
    Entity *target;
    const u8 *text;

    tile = GetTileMut(pos->x,pos->y);
    entity = tile->object;
    flag1 = FALSE;
    if (entity == NULL) {
        return;
    }
    if (GetEntityType(entity) != ENTITY_TRAP) {
        return;
    }
    trapData = GetTrapInfo(entity);
    GetTrapName(gFormatBuffer_Monsters[0],trapData->id);
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
            text = gUnknown_80FDB5C;
        }
        if ((flag == TRUE) || (gDungeon->unk181e8.showInvisibleTrapsMonsters != 0)) {
            if (rand < 0) text = gUnknown_80FDB7C;
        }
        else if (rand < 0xf) {
            text = gUnknown_80FDB7C;
        }
        if (text != NULL) {
            if (sub_803F428(pos)) {
                UpdateTrapsVisibility();
            }
            TryDisplayDungeonLoggableMessage3(pokemon,target,text);
            if (param_3 == 0) {
                return;
            }
        }
    }
    if (sub_803F428(pos)) {
        sub_80421C0(0,0x15c);
        UpdateTrapsVisibility();
        sub_804225C(pokemon,pos,trapData->id);
        if (gDungeon->unk181e8.blinded) {
            LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FD7F4);
        }
        else {
            LogMessageByIdWithPopupCheckUser(pokemon,gSteppedOnTrapStrings[trapData->id]);
        }
    }
    if (target != NULL) {
        if (trapData->unk1 == 2) {
            sub_806F480(target,TRUE);
        }
        else if (trapData->unk1 == 1) {
            sub_806F480(target,FALSE);
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
                DealDamageToEntity(target,gChestnutTrapDmgValue,0xf,0x213);
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
                DealDamageToEntity(target,gSpikeTrapDmgValue,10,0x206);
            }
    }
    if (EntityIsValid(target)) {
        EnemyEvolution(target);
    }
    if (flag1) {
        sub_807FE04(pos,1);
    }
}

void HandleMudTrap(Entity *pokemon, Entity *target)
{
    int rand, randDef;

    if (target == NULL)
        return;

    rand = DungeonRandInt(100);
    randDef = rand;
    if (rand < 25) {
        LowerAttackStageTarget(pokemon,target,gUnknown_8106A4C,1,1,1);
    }
    else if (rand < 50) {
        LowerAttackStageTarget(pokemon,target,gUnknown_8106A50,1,1,1);
    }
    else if (randDef < 75) {
        LowerDefenseStageTarget(pokemon,target,gUnknown_8106A4C,1,1,1);
    }
    else {
        LowerDefenseStageTarget(pokemon,target,gUnknown_8106A50,1,1,1);
    }
}

void HandleStickyTrap(Entity *pokemon,Entity *target)
{
    EntityInfo *info;
    int index;
    int itemCount;
    int newIndex;
    Item *itemStack[21];

    info = GetEntInfo(target);
    if (HasHeldItem(target,0xe)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDC7C);
    }
    else
    {
        itemCount = 0;
        if (info->isTeamLeader) {
            for (index = 0; index < INVENTORY_SIZE; index++) {
                if (ItemExists(&gTeamInventoryRef->teamItems[index]) && IsNotSpecialItem(gTeamInventoryRef->teamItems[index].id)) {
                    Item *item = &gTeamInventoryRef->teamItems[index];
                    if (!ItemSticky(item)) {
                        itemStack[itemCount] = item;
                        itemCount++;
                    }
                }
            }
        }
        if (ItemExists(&info->heldItem) && IsNotSpecialItem((info->heldItem).id) && !ItemSticky(&info->heldItem)) {
            itemStack[itemCount] = &info->heldItem;
            itemCount++;
        }

        if (itemCount == 0) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDC40);
        }
        else {
            newIndex = DungeonRandInt(itemCount);
            sub_8045BF8(gFormatBuffer_Items[0], itemStack[newIndex]);
            itemStack[newIndex]->flags |= ITEM_FLAG_STICKY;
            sub_80421C0(target, 0x192);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDC18);
        }
    }
}

void HandleSpinTrap(Entity *pokemon, Entity *target)
{
    if(target != NULL)
        ConfuseStatusTarget(pokemon, target, TRUE);
}

void HandleWarpTrap(Entity *pokemon, Entity *target)
{
    if(target != NULL)
        WarpTarget(pokemon, target, 0, NULL);
}

void HandleSlumberTrap(Entity *pokemon, Entity *target)
{
    s32 turns;

    if(target != NULL)
    {
        turns  = CalculateStatusTurns(target, gSleepTurnRange, TRUE);
        SleepStatusTarget(pokemon, target, turns, TRUE);
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
    HandleExplosion(pokemon, target, &target->pos, 1, TYPE_NONE, 0x212);
}

void HandleExplosionTrap(Entity *pokemon, Entity *target)
{
    HandleExplosion(pokemon, target, &target->pos, 2, TYPE_NONE, 0x212);
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
        info = GetEntInfo(target);
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
                (DungeonRandInt(100) < gGrimyTrapActivateChance)) {
                badFoodCount++;
                CreateItemWithStickyChance(itemStack[index], ITEM_GRIMY_FOOD, 2);
            }
        }
        if (badFoodCount == 1) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD788); // A food item went bad.
        }
        else if (badFoodCount == 0) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD7D4); // Nothing particularly bad happened.
        }
        else
        {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD7AC); // Several food items went bad
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
            LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FED0C); // But nothing happened...
        }
        else
        {
            info = GetEntInfo(target);
            if (ShouldDisplayEntity(target)) {
                SetTrap(tile, 0x1B);
                flag = TRUE;
                sub_80421C0(target,0x193);
                sub_803E708(0x1e,0x48);
            }
            if (info->isTeamLeader) {
                if (GetFloorType() != 2) {
                    info->unk15C = 1;
                    info->unk15E = 1;
                    sub_803E708(0x28,0x4b);
                    DealDamageToEntity(target,gPitfallTrapDmgValue,0x11,0x215);
                    gDungeon->unk2 = 2;
                    return;
                }
                LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80F9728);
            }
            else
            {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
                if (info->isNotTeamMember) {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80F970C); // $m0 fell into the pitfall!
                }
                else {
                    DisplayDungeonLoggableMessageTrue(pokemon,gUnknown_80F970C); // $m0 fell into the pitfall!
                }
                HandleFaint(target,0x215,pokemon);
            }
            if (flag) {
                SetTrap(tile, TRAP_PITFALL_TRAP);
            }
        }
    }
}

void HandleSummonTrap(Entity *pokemon,DungeonPos *pos)
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
            species = GetRandomFloorMonsterId(0);
            direction &= DIRECTION_MASK;
            stack.species = species;
            if (sub_806AA0C(stack.species,0)) {
              stack.level = 0;
              stack.unk2 = 0;
              stack.pos.x = pos->x + gAdjacentTileOffsets[direction].x;
              stack.pos.y = pos->y + gAdjacentTileOffsets[direction].y;
              stack.unk4 = 0;
              stack.unk10 = 0;
              if (sub_806B7F8(&stack, TRUE) != NULL) {
                pokemonSummonCount++;
              }
            }
            direction++;
        }
    }
    sub_80421EC(pos,0x194);
    if (pokemonSummonCount == 0) {
_ret:
        LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FED04);
    }
    else
    {
        LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FED00);
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
    info = GetEntInfo(param_2);
    counter = 0;
    for(i = 0;  i < MAX_MON_MOVES; move++, i++)
    {
      move = &info->moves.moves[i];
      if (((move->moveFlags & MOVE_FLAG_EXISTS) != 0) && (move->PP != 0)) {
        moveStack[counter] = move;
        indexStack[counter] = i;
        counter++;
      }
    }
    if (counter != 0) {
      moveIndex = DungeonRandInt(counter);
      moveStack[moveIndex]->PP = 0;
      BufferMoveName(gFormatBuffer_Items[0],moveStack[moveIndex],0);
      sub_806A9B4(param_2, indexStack[moveIndex]);
      flag = TRUE;
    }
    if(flag)
        TryDisplayDungeonLoggableMessage3(param_1,param_2,gUnknown_80FDA80);
    else
        TryDisplayDungeonLoggableMessage3(param_1,param_2,gUnknown_80FDAA0);
  }
}

void HandleWonderTile(Entity *pokemon, Entity *target)
{
    sub_8079E34(pokemon, target, FALSE);
}

void HandleSealTrap(Entity *param_1,Entity *param_2)
{
    Move *move;
    s32 moveIndex;
    s32 i;
    s32 counter;
    EntityInfo *info;
    Move *moveStack [MAX_MON_MOVES];
    bool8 flag = FALSE;


    if (param_2 != NULL && !HasSafeguardStatus(param_1, param_2, TRUE)) {
        info = GetEntInfo(param_2);
        counter = 0;
        for(i = 0;  i < MAX_MON_MOVES;i++)
        {
            move = &info->moves.moves[i];
            if ((move->moveFlags & MOVE_FLAG_EXISTS) && !(move->moveFlags2 & MOVE_FLAG_SEALED)) {
                moveStack[counter] = move;
                counter++;
            }
        }
        if (counter != 0) {
            moveIndex = DungeonRandInt(counter);
            moveStack[moveIndex]->moveFlags2 |= MOVE_FLAG_SEALED;
            BufferMoveName(gFormatBuffer_Items[0],moveStack[moveIndex], NULL);
            flag = TRUE;
        }
        if(flag)
            TryDisplayDungeonLoggableMessage3(param_1,param_2,gUnknown_80FDB04);
        else
            TryDisplayDungeonLoggableMessage3(param_1,param_2,gUnknown_80FDB2C);
    }
}

void HandleWhirlwindTrap(Entity *pokemon, Entity *target)
{
    if(target)
    {
        BlowAwayTarget(pokemon, target, DungeonRandInt(NUM_DIRECTIONS));
    }
}

void HandlePokemonTrap(Entity *param_1,DungeonPos *pos)
{
    s32 x, y, roomId;
    s32 maxX;
    struct unkStruct_806B7F8 local_50;
    s32 bottomX;
    s32 maxY;
    s32 bottomY;
    s32 counter = 0;
    s32 range = gDungeon->unk181e8.visibilityRange;

    if (IsBossFight()) {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80FED08);
        return;
    }

    if (range == 0) {
        range = 2;
    }

    roomId = GetTile(pos->x,pos->y)->room;
    if (roomId == CORRIDOR_ROOM) {
        bottomX = pos->x - range;
        bottomY = pos->y - range;
        maxX = pos->x + range;
        maxY = pos->y + range;
    }
    else {
        RoomData *room = &gDungeon->roomData[roomId];
        bottomX = room->bottomRightCornerX + -1;
        bottomY = room->bottomRightCornerY + -1;
        maxX = room->topLeftCornerX + 1;
        maxY = room->topLeftCornerY + 1;
    }

    for (y = bottomY; y <= maxY; y++) {
        for (x = bottomX; x <= maxX; x++) {
            const Tile *tile = GetTile(x,y);
            if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_ITEM && !(GetItemInfo(tile->object)->flags & ITEM_FLAG_IN_SHOP)) {
                s32 i, species;

                local_50.species = MONSTER_KECLEON;
                for (i = 0; i < 100; i++) {
                    if (gDungeon->unk644.unk2A != 0) {
                        species = MONSTER_KECLEON;
                    }
                    else {
                        species = (s16) GetRandomFloorMonsterId(0);
                        ASM_MATCH_TRICK(species);
                    }

                    local_50.species = species;
                    if (sub_806AA0C(local_50.species, 0) != 0)
                        break;
                }

                if (sub_806AA0C(local_50.species, 0)) {
                    local_50.level = 0;
                    local_50.unk2 = 0;
                    local_50.pos.x = x;
                    local_50.pos.y = y;
                    local_50.unk4 = 0;
                    local_50.unk10 = 0;
                    if (sub_806B7F8(&local_50, TRUE) != 0) {
                        RemoveGroundItem(&local_50.pos,0);
                        counter++;
                    }
                }
                DrawMinimapTile(x,y);
            }
        }
    }

    if (counter != 0) {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80FDACC);
    }
    else {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80FDAE4);
    }
}

void HandleTripTrap(Entity *pokemon, Entity *target)
{
    u32 direction;
    EntityInfo *info;
    DungeonPos pos;
    Item item;

    if (target != NULL) {
        sub_806CDD4(target, 6, NUM_DIRECTIONS);
        sub_803E708(0x10, 0x55);
        sub_806CE68(target, NUM_DIRECTIONS);
        info = GetEntInfo(target);
        if ((info->heldItem).flags & ITEM_FLAG_EXISTS) {
            item =  (info->heldItem);
            (info->heldItem).flags = 0;
            FillInventoryGaps();
            sub_80421C0(target, 400);
            direction = (info->action).direction & DIRECTION_MASK;
            pos.x = (target->pos).x + gAdjacentTileOffsets[direction].x;
            pos.y =  (target->pos).y + gAdjacentTileOffsets[direction].y;
            sub_804687C(pokemon, &target->pos, &pos, &item, 1);
        }
    }
}

void SetTrap(Tile *tile, u8 id)
{
    Trap *trapData;
    Entity *entity;

    entity = tile->object;
    if (EntityIsValid(entity)) {
        if (GetEntityType(entity) == ENTITY_TRAP) {
            trapData = GetTrapInfo(entity);
            trapData->id = id;
        }
        UpdateTrapsVisibility();
    }
}
