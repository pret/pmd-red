#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/trap.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "bg_palette_buffer.h"
#include "cpu.h"
#include "graphics_memory.h"
#include "effect_main.h"
#include "def_filearchives.h"
#include "dungeon_info.h"
#include "dungeon_generation.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "dungeon_vram.h"
#include "file_system.h"
#include "game_options.h"
#include "sprite.h"
#include "text_1.h"
#include "trap.h"
#include "run_dungeon.h"

struct UnkStruct1
{
    u32 **unk0;
};

struct DungeonMapGfx
{
    struct UnkStruct1 *gfx;
    RGB *pal;
};

enum {
    MAP_GFX_NOTHING,
    MAP_GFX_UNK1, // Appears to be nothing too
    MAP_GFX_ENEMY,
    MAP_GFX_ITEM,
    MAP_GFX_TRAP,
    MAP_GFX_SPECIAL_STAIRS,
    MAP_GFX_STAIRS,
    MAP_GFX_WONDER_TILE,
    MAP_GFX_PLAYER,
    MAP_GFX_WHITE_SQUARE, // Possibly unused? It's like Stairs, but white instead of blue
    MAP_GFX_ALLY,
    MAP_GFX_GREEN_DOT, // Used when hallucinating
};

#define MAP_GFX_TERRAIN_TILES_VISITED 0x10
#define MAP_GFX_TERRAIN_TILES_REVEALED 0x20
#define MAP_GFX_TERRAIN_LINE_UP 0x1
#define MAP_GFX_TERRAIN_LINE_RIGHT 0x2
#define MAP_GFX_TERRAIN_LINE_DOWN 0x4
#define MAP_GFX_TERRAIN_LINE_LEFT 0x8

EWRAM_DATA bool8 gShowMonsterDotsInDungeonMap = FALSE;
EWRAM_DATA bool8 gShowDungeonMap = FALSE;
EWRAM_DATA static u8 sPlayerDotFrames = 0;
EWRAM_DATA static OpenedFile *sDungeonMapGfxFile = NULL;
EWRAM_DATA static void *sDungeonMapVramDst = NULL;
EWRAM_INIT DungeonPos gPlayerDotMapPosition = {100, 100};

// All traps look the same on Map, except for the Wonder Tile.
static const u8 sTrapToMapGfxId[NUM_TRAPS] =
{
    [TRAP_TRIP_TRAP] = MAP_GFX_TRAP,
    [TRAP_MUD_TRAP] = MAP_GFX_TRAP,
    [TRAP_STICKY_TRAP] = MAP_GFX_TRAP,
    [TRAP_GRIMY_TRAP] = MAP_GFX_TRAP,
    [TRAP_SUMMON_TRAP] = MAP_GFX_TRAP,
    [TRAP_PITFALL_TRAP] = MAP_GFX_TRAP,
    [TRAP_WARP_TRAP] = MAP_GFX_TRAP,
    [TRAP_WHIRLWIND_TRAP] = MAP_GFX_TRAP,
    [TRAP_SPIN_TRAP] = MAP_GFX_TRAP,
    [TRAP_SLUMBER_TRAP] = MAP_GFX_TRAP,
    [TRAP_SLOW_TRAP] = MAP_GFX_TRAP,
    [TRAP_SEAL_TRAP] = MAP_GFX_TRAP,
    [TRAP_POISON_TRAP] = MAP_GFX_TRAP,
    [TRAP_SELFDESTRUCT_TRAP] = MAP_GFX_TRAP,
    [TRAP_EXPLOSION_TRAP] = MAP_GFX_TRAP,
    [TRAP_PP_ZERO_TRAP] = MAP_GFX_TRAP,
    [TRAP_CHESTNUT_TRAP] = MAP_GFX_TRAP,
    [TRAP_WONDER_TILE] = MAP_GFX_WONDER_TILE,
    [TRAP_POKEMON_TRAP] = MAP_GFX_TRAP,
    [TRAP_SPIKE_TRAP] = MAP_GFX_TRAP,
};

void SetDungeonMapToNotShown(void)
{
    gShowDungeonMap = FALSE;
}

void OpenDungeonMapFile(void)
{
    sDungeonMapGfxFile = OpenFileAndGetFileDataPtr("zmappat", &gDungeonFileArchive);
}

void InitDungeonMap(bool8 a0)
{
    s32 i, j;

    for (i = 0; i < DUNGEON_MAP_MAX_Y; i++) {
        for (j = 0; j < DUNGEON_MAP_MAX_X; j++) {
            CpuClear(&gDungeon->dungeonMap.perTile[i][j], sizeof(struct UnkDungeonGlobal_1822C_Sub));
            gDungeon->dungeonMap.tileScheduledForCopy[i][j] = FALSE;
        }
    }

    if (!a0) {
        gPlayerDotMapPosition.x = 100;
        gPlayerDotMapPosition.y = 100;
    }

    gDungeon->dungeonMap.scheduledVramCopiesCount = 0;
    gDungeon->dungeonMap.copyToVram = TRUE;
    gDungeon->dungeonMap.resetTilesScheduledForCopy = FALSE;
    gShowMonsterDotsInDungeonMap = TRUE;
    sDungeonMapVramDst = (void *) VRAM + 0x1700;
    gShowDungeonMap = TRUE;
    LoadDungeonMapPalette();
}

void CloseDungeonMapFile(void)
{
    if (sDungeonMapGfxFile != NULL) {
        CloseFile(sDungeonMapGfxFile);
    }
    SetDungeonMapToNotShown();
}

// Used in Pmd's Blue version. Stores different Vram address in sDungeonMapVramDst(maybe?), depending on TOP_MAP_AND_TEAM_NO_BOTTOM map option.
UNUSED static void nullsub_203(void)
{

}

void LoadDungeonMapPalette(void)
{
    s32 i;

    if (sDungeonMapGfxFile == NULL)
        return;
    if (!gShowDungeonMap)
        return;

    for (i = 0; i < 16; i++) {
        if (i == 14) {
            SetBGPaletteBufferColorArray(238, &gFontPalette[1]);
            nullsub_5(238, &gFontPalette[1]);
        }
        else {
            SetBGPaletteBufferColorArray(i + 224, &((struct DungeonMapGfx *)(sDungeonMapGfxFile->data))->pal[i]);
            nullsub_5(i + 224, &((struct DungeonMapGfx *)(sDungeonMapGfxFile->data))->pal[i]);
        }
    }
}

void DrawMinimapTile(s32 x, s32 y)
{
    s32 yAdd = 0;
    const Tile *tile;
    Dungeon *dungeon;
    bool8 blinded;
    u32 terrainType;
    bool8 hallucinating;
    bool8 showItems;
    bool8 showHiddenTraps;
    bool8 allTilesRevealed;
    bool8 var_24;
    bool8 tileKnown;
    s32 mapGfxType;
    s32 xDiv2, yDiv2;
    u32 *src, *dst;
    bool8 lookForMapObject;
    s32 r3, yMinus;

    dungeon = gDungeon;
    lookForMapObject = TRUE;

    if (sDungeonMapGfxFile == NULL)
        return;
    if (!gShowDungeonMap)
        return;
    if (sub_800EC74())
        return;
    if (GAME_VERSION == VERSION_BLUE) {
        if (gGameOptionsRef->mapOption == TOP_MAP_AND_TEAM_NO_BOTTOM) {
            if (x < 0 || y < 1 || x >= DUNGEON_MAX_SIZE_X || y >= DUNGEON_MAX_SIZE_Y)
                return;
            yAdd = 1;
        }
        else {
            if (x < 0 || y < 2 || x >= DUNGEON_MAX_SIZE_X || y >= DUNGEON_MAX_SIZE_Y)
                return;
            yAdd = 0;
        }
        // FUN_0001d198(); Unknown function call which doesn't exist in red
    }
    else if (GAME_VERSION == VERSION_RED) {
        if (x < 0 || y < 2 || x >= DUNGEON_MAX_SIZE_X || y >= DUNGEON_MAX_SIZE_Y - 1)
            return;
    }

    tile = GetTile(x, y);
    terrainType = GetTerrainType(tile);
    hallucinating = gDungeon->unk181e8.hallucinating;
    blinded = gDungeon->unk181e8.blinded;
    showHiddenTraps = gDungeon->unk181e8.showInvisibleTrapsMonsters;
    showItems = gDungeon->unk181e8.showAllFloorItems;
    allTilesRevealed = gDungeon->unk181e8.allTilesRevealed;
    if (blinded) {
        tileKnown = tile->spawnOrVisibilityFlags.visibility & VISIBILITY_FLAG_REVEALED;
        var_24 = FALSE;
    }
    else {
        if (allTilesRevealed) {
            tileKnown = TRUE;
        }
        else {
            tileKnown = tile->spawnOrVisibilityFlags.visibility & VISIBILITY_FLAG_REVEALED;
        }

        if (GetFloorType() == FLOOR_TYPE_NORMAL) {
            var_24 = gDungeon->unk181e8.unk18211;
        }
        else {
            var_24 = FALSE;
        }
    }

    if (GameOptions_ShowMiniMap() && !gDungeon->unk1356C) {
        mapGfxType = MAP_GFX_NOTHING;
        if (!blinded) {
            Entity *entity = tile->monster;
            if (entity != NULL) {
                s32 entType = GetEntityType(entity);
                if (gShowMonsterDotsInDungeonMap && entType == ENTITY_MONSTER && ShouldMinimapDisplayEntity(entity)) {
                    EntityInfo *entInfo = GetEntInfo(entity);
                    if (IsExperienceLocked(entInfo->joinedAt.id) || entInfo->monsterBehavior == 1 || entInfo->monsterBehavior == 4) {
                        mapGfxType = MAP_GFX_ALLY;
                    }
                    else {
                        if (entInfo->isNotTeamMember) {
                            mapGfxType = MAP_GFX_ENEMY;
                        }
                        else if (entInfo->isTeamLeader) {
                            gPlayerDotMapPosition.x = x;
                            gPlayerDotMapPosition.y = y;
                            if (gDungeon->unk181e8.inFloorMapMode) {
                                mapGfxType = MAP_GFX_PLAYER;
                            }
                        }
                        else {
                            mapGfxType = MAP_GFX_ALLY;
                        }
                    }
                    lookForMapObject = FALSE;
                }
            }
        }
        if (lookForMapObject && !blinded) {
            Entity *entity = tile->object;
            if (entity != NULL) {
                s32 entType = GetEntityType(entity);
                if (!tileKnown) {
                    mapGfxType = MAP_GFX_NOTHING;
                    if (entType == ENTITY_ITEM) {
                        if ((showItems || (tile->spawnOrVisibilityFlags.spawn & SPAWN_FLAG_ITEM)) && terrainType != TERRAIN_TYPE_WALL) {
                            mapGfxType = MAP_GFX_ITEM;
                        }
                    }
                    lookForMapObject = FALSE;
                }
                else {
                    if (entType == ENTITY_TRAP) {
                        if (entity->isVisible || showHiddenTraps) {
                            Trap *trap = GetTrapInfo(entity);
                            mapGfxType = sTrapToMapGfxId[trap->id];
                            lookForMapObject = FALSE;
                        }
                    }
                }

                if (lookForMapObject) {
                    if (entType == ENTITY_ITEM) {
                        if ((showItems || (tile->spawnOrVisibilityFlags.spawn & SPAWN_FLAG_ITEM)) && terrainType != TERRAIN_TYPE_WALL) {
                            mapGfxType = MAP_GFX_ITEM;
                            lookForMapObject = FALSE;
                        }
                    }
                }
                if (lookForMapObject) {
                    if (terrainType != TERRAIN_TYPE_NORMAL) {
                        mapGfxType = MAP_GFX_NOTHING;
                        lookForMapObject = FALSE;
                    }
                }
            }
            else {
                if (!tileKnown) {
                    if (var_24 && (tile->terrainFlags & TERRAIN_TYPE_STAIRS)) {
                        if (GetFloorType() == FLOOR_TYPE_NORMAL) {
                            mapGfxType = MAP_GFX_STAIRS;
                        }
                        else {
                            mapGfxType = MAP_GFX_SPECIAL_STAIRS;
                        }
                        lookForMapObject = FALSE;
                    }
                }
                else {
                    if ((tile->terrainFlags & TERRAIN_TYPE_STAIRS)) {
                        if (GetFloorType() == FLOOR_TYPE_NORMAL) {
                            mapGfxType = MAP_GFX_STAIRS;
                        }
                        else {
                            mapGfxType = MAP_GFX_SPECIAL_STAIRS;
                        }
                        lookForMapObject = FALSE;
                    }
                }
            }
        }
        if (!lookForMapObject) {
            if (hallucinating) {
                if (mapGfxType != MAP_GFX_NOTHING) {
                    mapGfxType = MAP_GFX_GREEN_DOT;
                }
            }
        }
        if (mapGfxType == MAP_GFX_NOTHING) {
            if (!tileKnown) {
                mapGfxType = 1;
            }
            else if (terrainType != TERRAIN_TYPE_NORMAL) {
                mapGfxType = 1;
            }
            else {
                s32 terrainLine = MAP_GFX_TERRAIN_LINE_UP | MAP_GFX_TERRAIN_LINE_RIGHT | MAP_GFX_TERRAIN_LINE_DOWN | MAP_GFX_TERRAIN_LINE_LEFT;
                if (y < DUNGEON_MAX_SIZE_Y - 1) {
                    const Tile *adjacentTile = GetTile(x, y + 1);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        terrainLine &= ~(MAP_GFX_TERRAIN_LINE_UP);
                    }
                }
                if (y >= 1) {
                    const Tile *adjacentTile = GetTile(x, y - 1);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        terrainLine &= ~(MAP_GFX_TERRAIN_LINE_DOWN);
                    }
                }
                if (x < DUNGEON_MAX_SIZE_X - 1) {
                    const Tile *adjacentTile = GetTile(x + 1, y);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        terrainLine &= ~(MAP_GFX_TERRAIN_LINE_RIGHT);
                    }
                }
                if (x >= 1) {
                    const Tile *adjacentTile = GetTile(x - 1, y);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        terrainLine &= ~(MAP_GFX_TERRAIN_LINE_LEFT);
                    }
                }

                mapGfxType = (s16) terrainLine;
                if (tile->spawnOrVisibilityFlags.visibility & VISIBILITY_FLAG_VISITED) {
                    mapGfxType = (s16) (mapGfxType + MAP_GFX_TERRAIN_TILES_VISITED);
                }
                else {
                    mapGfxType = (s16) (mapGfxType + MAP_GFX_TERRAIN_TILES_REVEALED);
                }
            }
        }

        // Not possible on GBA.
        if (gGameOptionsRef->mapOption == TOP_MAP_AND_TEAM_NO_BOTTOM) {
            mapGfxType = (s16) (mapGfxType + 128);
        }
        else if (GameOptions_IsTransparentMiniMap() == TRUE) {
            mapGfxType = (s16) (mapGfxType + 64);
        }
    }
    else {
        mapGfxType = 1;
        gPlayerDotMapPosition.x = 100;
    }

    xDiv2 = x / 2;
    yMinus = (y - 2) + yAdd;
    yDiv2 = (yMinus / 2);
    r3 = x - (xDiv2 * 2);
    r3 += (yMinus - (yDiv2 * 2)) * 2;
    dst = dungeon->dungeonMap.perTile[yDiv2][xDiv2].arr;
    {
        struct DungeonMapGfx *ptr = ((struct DungeonMapGfx *)(&sDungeonMapGfxFile->data));
        src = ptr->gfx->unk0[mapGfxType * 4 + r3];
    }

    dst[0] = (dst[0] & src[0]) | src[1];
    dst[1] = (dst[1] & src[2]) | src[3];
    dst[2] = (dst[2] & src[4]) | src[5];
    dst[3] = (dst[3] & src[6]) | src[7];
    dst[4] = (dst[4] & src[8]) | src[9];
    dst[5] = (dst[5] & src[10]) | src[11];
    dst[6] = (dst[6] & src[12]) | src[13];
    dst[7] = (dst[7] & src[14]) | src[15];

    if (!dungeon->dungeonMap.copyAllAtOnce && !dungeon->dungeonMap.tileScheduledForCopy[yDiv2][xDiv2]) {
        s32 id;

        dungeon->dungeonMap.tileScheduledForCopy[yDiv2][xDiv2] = TRUE;
        id = dungeon->dungeonMap.scheduledVramCopiesCount;
        if (id < MAX_SCHEDULED_DUNGEON_MAP_COPIES) {
            dungeon->dungeonMap.vramCopies[id].vramPtr = sDungeonMapVramDst + ((xDiv2 + yDiv2 * DUNGEON_MAP_MAX_X) * sizeof(struct UnkDungeonGlobal_1822C_Sub));
            dungeon->dungeonMap.vramCopies[id].mapArrayPtr = dst;
            dungeon->dungeonMap.vramCopies[id].boolPtr = &dungeon->dungeonMap.tileScheduledForCopy[yDiv2][xDiv2];
            dungeon->dungeonMap.scheduledVramCopiesCount++;
        }
        else {
            dungeon->dungeonMap.copyAllAtOnce = TRUE;
        }
    }
}

void CopyDungeonMapToVram(void)
{
    s32 i;
    Dungeon *dungeon = gDungeon;
    if (dungeon == NULL)
        return;
    if (!dungeon->dungeonMap.copyToVram)
        return;
    if (sub_800EC74())
        return;

    if (!dungeon->dungeonMap.copyAllAtOnce) {
        for (i = 0; i < dungeon->dungeonMap.scheduledVramCopiesCount; i++) {
            struct DungeonMapVramCopy *ptr = &dungeon->dungeonMap.vramCopies[i];
            u32 *src = ptr->mapArrayPtr;
            u32 *dst = ptr->vramPtr;

            if (gUnknown_202EDD0 == 0 || gUnknown_202EDD0 == 3) {
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
            }
            *ptr->boolPtr = FALSE;
        }
    }
    else {
        void *dst, *src;

        dungeon->dungeonMap.copyAllAtOnce = FALSE;
        dst = sDungeonMapVramDst;
        src = dungeon->dungeonMap.perTile[0][0].arr;

        for (i = 0; i < DUNGEON_MAX_SIZE_X * 8; i += 8) {
            if (gUnknown_202EDD0 == 0 || gUnknown_202EDD0 == 3) {
                CpuCopy(dst, src, 0x100);
            }
            dst += 0x100;
            src += 0x100;
        }
        dungeon->dungeonMap.resetTilesScheduledForCopy = TRUE;
    }
    dungeon->dungeonMap.scheduledVramCopiesCount = 0;
}

void FlashLeaderIcon(void)
{
    if (gDungeon->unk181e8.inFloorMapMode)
        return;
    if (!gDungeon->unk181e8.unk18219)
        return;
    if (gPlayerDotMapPosition.x >= 100)
        return;
    if ((++sPlayerDotFrames & 8) == 0) {
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 0);
        SpriteSetMatrixNum(&sprite, 0);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x215);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetUnk6_0(&sprite, 0);
        SpriteSetUnk6_1(&sprite, 0);
        // Nulled on GBA
        if (gGameOptionsRef->mapOption == TOP_MAP_AND_TEAM_NO_BOTTOM) {
            SpriteSetX(&sprite, (gPlayerDotMapPosition.x * 4) + 16);
            SpriteSetY(&sprite, (gPlayerDotMapPosition.y + 1) * 4);
            nullsub_11(&sprite,0x100,NULL,NULL);
        }
        else {
            SpriteSetX(&sprite, (gPlayerDotMapPosition.x * 4) + 8);
            SpriteSetY(&sprite, (gPlayerDotMapPosition.y) * 4);
            AddSprite(&sprite,0x100,NULL,NULL);
        }
    }
}

void ResetMapPlayerDotFrames(void)
{
    sPlayerDotFrames = 0;
}

void UpdateMinimap(void)
{
    s32 x, y;

    gDungeon->dungeonMap.copyAllAtOnce = TRUE;

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            DrawMinimapTile(x, y);
        }
    }
}

void UpdateBgTilemapForDungeonMap(bool8 a0)
{
    s32 id, count1, count2;
    s32 i, j;
    u16 tilemapValue;

    if (gGameOptionsRef->mapOption == TOP_MAP_AND_TEAM_NO_BOTTOM) {
        count1 = 15;
        count2 = 0;
    }
    else if (a0) {
        count1 = 14;
        count2 = 0;
    }
    else {
        count1 = 16;
        count2 = 3;
    }

    tilemapValue = TILEMAP_TILE_NUM(0xB8) | TILEMAP_PAL(14);
    id = 1;
    for (i = 0; i < count1; i++) {
        u16 *ptr = &gBgTilemaps[0][id][1];
        for (j = 0; j < 28; j++) {
            *ptr++ = tilemapValue++;
        }
        id++;
    }

    for (i = 0; i < count2; i++) {
        u16 *ptr = &gBgTilemaps[0][id][1];
        for (j = 0; j < 28; j++) {
            *ptr++ = TILEMAP_TILE_NUM(0) | TILEMAP_PAL(14);
        }
        id++;
    }
}

// BUG: Overflowing into vramCopies. They forgot that the array size is max X/Y divided by two...
void TryResetDungeonMapTilesScheduledForCopy(void)
{
    s32 x, y;
    Dungeon *dungeon = gDungeon;
    if (dungeon->dungeonMap.resetTilesScheduledForCopy) {
        #ifdef BUGFIX
        for (y = 0; y < DUNGEON_MAP_MAX_Y; y++) {
            for (x = 0; x < DUNGEON_MAP_MAX_X; x++) {
                dungeon->dungeonMap.tileScheduledForCopy[y][x] = FALSE;
            }
        }
        #else
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
                dungeon->dungeonMap.tileScheduledForCopy[y][x] = FALSE;
            }
        }
        #endif // BUGFIX
        dungeon->dungeonMap.resetTilesScheduledForCopy = FALSE;
    }
}
