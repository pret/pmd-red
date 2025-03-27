#include "global.h"
#include "globaldata.h"
#include "dungeon_generation_fixed.h"
#include "dungeon_generation.h"
#include "dungeon_map_access.h"
#include "items.h"
#include "pokemon.h"
#include "code_80450F8.h"
#include "dungeon_util.h"
#include "dungeon_items.h"
#include "dungeon_message.h"
#include "code_803E668.h"
#include "structs/str_806B7F8.h"
#include "constants/monster.h"
#include "constants/trap.h"
#include "constants/item.h"

extern s32 sub_803DA20(s16 species);
extern void sub_80429FC(DungeonPos *r0);

static bool8 sub_805210C(u8 itemId);

static void SpawnItemAtPos(u8 itemId, s32 x, s32 y, s32 quantity, u32 itemFlags)
{
    Item item;
    DungeonPos pos = {x, y};

    if (sub_805210C(itemId)) {
        ItemIdToSlot(&item, ITEM_LINK_CABLE, 0);
    }
    else {
        ItemIdToSlot(&item, itemId, 0);
    }

    item.flags |= itemFlags;
    if (quantity != 0) {
        item.quantity = quantity;
    }

    AddItemToDungeonAt(&pos, &item, 1);
}

// s16 species memes strike again. Will the fix ever be discovered?
static void SpawnSpeciesAtPos(s16 species_, s32 x, s32 y, u32 unk2_, u32 UNUSED unused)
{
    struct unkStruct_806B7F8 unkStruct;
    s32 species = SpeciesId(species_);
    u8 unk2 = unk2_;

    if (species_ == MONSTER_DECOY) {
        unkStruct.species = MONSTER_POLIWAG;
        unkStruct.level = sub_803DA20(MONSTER_POLIWAG);
        unkStruct.unk2 = unk2;
        unkStruct.unk4 = 0;
        unkStruct.unk10 = 0;
        unkStruct.pos.x = x;
        unkStruct.pos.y = y;
        sub_806B7F8(&unkStruct, TRUE);
    }
    else if (species != MONSTER_NONE) {
        unkStruct.species = species;
        unkStruct.level = sub_803DA20(species);
        unkStruct.unk2 = unk2;
        unkStruct.unk4 = 0;
        unkStruct.unk10 = 0;
        unkStruct.pos.x = x;
        unkStruct.pos.y = y;
        sub_806B7F8(&unkStruct, TRUE);
    }
}

static void SpawnEnemyTrapAtPos(u8 trapId, s32 x, s32 y, bool8 isVisible)
{
    DungeonPos pos;
    Entity *trapEntity;
    Tile *tile = GetTileMut(x, y);

    pos.x = x;
    pos.y = y;
    trapEntity = SpawnTrap(trapId, &pos, 0);
    if (trapEntity != NULL) {
        tile->object = trapEntity;
        trapEntity->isVisible = isVisible;
    }
}

struct UnkStruct_80F6D20
{
    u8 itemId;
    s16 unk2;
    u32 unk4;
    s16 speciesId;
    u8 unkA;
    u8 trapId;
    u8 roomId;
    bool8 trapVisible;
    bool8 setTerrainToSecondary;
};

extern const struct UnkStruct_80F6D20 gUnknown_80F6E20[];

// Used to spawn a single tile when generating a fixed room. The tile might contain an item or a monster.
bool8 PlaceFixedRoomTile(Tile *tile, u8 fixedRoomActionId, s32 x, s32 y, bool8 spawnTrapOrItem)
{
    if (fixedRoomActionId > 0xF) {
        SetTerrainNormal(tile);
    }

    switch (fixedRoomActionId) {
        case 69:
            gDungeon->unk644.unk40 = x;
            gDungeon->unk644.unk42 = y;
            SpawnEnemyTrapAtPos(TRAP_SEAL_TRAP, x, y, FALSE);
            // fall through
        case 0:
            SetTerrainNormal(tile);
            tile->room = 0;
            break;
        case 1:
            SetTerrainWall(tile);
            tile->terrainType &= ~(TERRAIN_TYPE_UNBREAKABLE);
            tile->room = CORRIDOR_ROOM;
            break;
        case 4:
            SetTerrainNormal(tile);
            gDungeon->playerSpawn.x = x;
            gDungeon->playerSpawn.y = y;
            tile->room = 0;
            break;
        case 5:
            SetTerrainSecondary(tile);
            tile->room = 0;
            break;
        case 6:
            SetTerrainType(tile, TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL);
            tile->room = CORRIDOR_ROOM;
            break;
        case 7:
            gUnknown_202F1A8 = 1;
            sub_8049840();
            // fall through
        case 10:
            SetTerrainType(tile, TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL);
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
            tile->room = CORRIDOR_ROOM;
            break;
        case 8:
        case 67:
            SetTerrainNormal(tile);
            tile->spawnOrVisibilityFlags |= SPAWN_FLAG_STAIRS;
            tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
            tile->room = 0;
            gDungeon->stairsSpawn.x = x;
            gDungeon->stairsSpawn.y = y;
            break;
        case 68:
            tile->terrainType |= TERRAIN_TYPE_UNK_x800;
            SetTerrainNormal(tile);
            tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
            tile->room = 0;
            break;
        case 9:
            SetTerrainNormal(tile);
            tile->room = CORRIDOR_ROOM;
            break;
        case 11:
            SetTerrainNormal(tile);
            tile->terrainType |= TERRAIN_TYPE_UNK_x800;
            tile->room = 0;
            break;
        case 12:
            SetTerrainNormal(tile);
            tile->terrainType |= TERRAIN_TYPE_UNK_x1000;
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
            tile->terrainType |= TERRAIN_TYPE_UNK_x800;
            tile->room = 0;
            break;
        case 2:
        case 13:
        case 14:
            SetTerrainWall(tile);
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
            tile->room = CORRIDOR_ROOM;
            break;
        default:
            if (fixedRoomActionId >= 16 && fixedRoomActionId <= 219) {
                const struct UnkStruct_80F6D20 *ptr = &gUnknown_80F6E20[fixedRoomActionId - 16];
                tile->room = ptr->roomId;
                if (ptr->itemId != 0) {
                    if (spawnTrapOrItem) {
                        SpawnItemAtPos(ptr->itemId, x, y, ptr->unk2, ptr->unk4);
                    }
                    else {
                        gDungeon->unk644.unk47 = ptr->itemId;
                    }
                }
                else {
                    if (ptr->unk4 != 0) {
                        gDungeon->unkE220[ptr->unk4 - 1].x = x;
                        gDungeon->unkE220[ptr->unk4 - 1].y = y;
                    }
                }

                if (ptr->speciesId != 0) {
                    SpawnSpeciesAtPos(ptr->speciesId, x, y, ptr->unkA, fixedRoomActionId);
                }

                if (ptr->trapId != NUM_TRAPS && spawnTrapOrItem) {
                    SpawnEnemyTrapAtPos(ptr->trapId, x, y, ptr->trapVisible);
                }

                if (ptr->setTerrainToSecondary) {
                    SetTerrainSecondary(tile);
                }
            }
            break;
        case 3:
        case 15:
            break;
    }

    return FALSE;
}

void sub_8051E3C(void)
{
    s32 x, y;

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            Tile *tile = GetTileMut(x, y);
            if (tile->unkE > 0xF) {
                PlaceFixedRoomTile(tile, tile->unkE, x, y, FALSE);
            }
        }
    }
}

extern const u8 *const gUnknown_80FDDF0;
extern const u8 *const gUnknown_80FDDD0;

void sub_8051E7C(Entity *pokemon)
{
    Tile *tile = GetTileMut(pokemon->pos.x, pokemon->pos.y - 1);

    if (!(tile->terrainType & TERRAIN_TYPE_UNK_x1000)) {
        LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FDDF0); // It can't be used here!
    }
    else if (!gDungeon->unk3A09) {
        s32 x, y;
        DungeonPos pos = {pokemon->pos.x, pokemon->pos.y - 1};
        u32 roomId = GetEntityRoom(pokemon);

        for (y = pokemon->pos.y - 21; y <= pokemon->pos.y + 19; y++) {
            for (x = pokemon->pos.x -20; x <= pokemon->pos.x + 20; x++) {
                Tile *loopTile;
                s32 xDiff = x - gDungeon->unkE250.minX;
                s32 yDiff = y - gDungeon->unkE250.minY;

                if (xDiff < 0 || yDiff < 0)
                    continue;
                if (xDiff >= 8 || yDiff >= 8)
                    continue;
                if (x < gDungeon->unkE250.minX + 1 || y < gDungeon->unkE250.minY + 1)
                    continue;
                if (x >= gDungeon->unkE250.maxX - 1 || y >= gDungeon->unkE250.maxY - 1)
                    continue;

                loopTile = GetTileMut(x, y);
                if (loopTile->terrainType & TERRAIN_TYPE_UNBREAKABLE) {
                    loopTile->terrainType = gDungeon->unkE27C[xDiff][yDiff].terrainType;
                    loopTile->spawnOrVisibilityFlags = gDungeon->unkE27C[xDiff][yDiff].spawnOrVisibilityFlags;
                }

                PlaceFixedRoomTile(loopTile, gDungeon->unkE87C[xDiff][yDiff], x, y, TRUE);
                loopTile->spawnOrVisibilityFlags |= 3;
                if (roomId != CORRIDOR_ROOM) {
                    loopTile->room = roomId;
                }
            }
        }

        for (y = pokemon->pos.y - 21; y <= pokemon->pos.y + 19; y++) {
            for (x = pokemon->pos.x -20; x <= pokemon->pos.x + 20; x++) {
                s32 xDiff = x - gDungeon->unkE250.minX;
                s32 yDiff = y - gDungeon->unkE250.minY;

                if (xDiff < 0 || yDiff < 0)
                    continue;
                if (xDiff >= 8 || yDiff >= 8)
                    continue;
                if (x < gDungeon->unkE250.minX + 1 || y < gDungeon->unkE250.minY + 1)
                    continue;
                if (x >= gDungeon->unkE250.maxX - 1 || y >= gDungeon->unkE250.maxY - 1)
                    continue;

                sub_80498A8(x, y);
            }
        }

        gDungeon->unk3A09 = TRUE;
        tile->terrainType &= ~(TERRAIN_TYPE_IMPASSABLE_WALL | TERRAIN_TYPE_UNK_x1000);
        sub_80498A8(pokemon->pos.x, pokemon->pos.y - 1);
        sub_8049B8C();
        sub_8049ED4();
        sub_80429FC(&pos);
        LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FDDD0); // The closed corridor was opened!
        sub_803E708(0x14, 0x3C);
    }
    else {
        LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FDDF0); // It can't be used here!
    }
}

static inline bool8 MonHasItem(PokemonStruct1 *mon)
{
    return (mon->heldItem.id != 0);
}

static bool8 sub_805210C(u8 itemId)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (ItemExists(&gTeamInventoryRef->teamItems[i])) {
            if (gTeamInventoryRef->teamItems[i].id == itemId)
                return TRUE;
        }
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if (PokemonFlag1Struct2(&gRecruitedPokemonRef->pokemon2[i]) && ItemExists(&gRecruitedPokemonRef->pokemon2[i].itemSlot)) {
            if (gRecruitedPokemonRef->pokemon2[i].itemSlot.id == itemId)
                return TRUE;
        }
    }

    for (i = 0; i < NUM_MONSTERS; i++) {
        if (PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])) {
            if (MonHasItem(&gRecruitedPokemonRef->pokemon[i]) && gRecruitedPokemonRef->pokemon[i].heldItem.id == itemId)
                return TRUE;
        }
    }

    if (gTeamInventoryRef->teamStorage[itemId] != 0)
        return TRUE;

    return FALSE;
}
