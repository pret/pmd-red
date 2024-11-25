#include "global.h"
#include "dungeon_generation.h"
#include "file_system.h"
#include "tile_types.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "items.h"
#include "pokemon.h"
#include "code_80450F8.h"
#include "code_803E668.h"
#include "constants/direction.h"
#include "constants/item.h"
#include "constants/monster.h"
#include "structs/str_dungeon.h"
#include "structs/map.h"
#include "structs/str_806B7F8.h"

extern const u8 gUnknown_80F6DCC[];
extern struct FileArchive gDungeonFileArchive;

extern void sub_80460F8(DungeonPos *, Item *, u32);
extern s32 sub_803DA20(s16 species);
extern void sub_8049840(void);
extern void sub_80429FC(DungeonPos *r0);
extern void sub_80498A8(s32, s32);
extern void sub_8049B8C(void);
extern u8 GetFloorType();
extern void sub_806C330(s32 a0, s32 a1, s16 a2, u8 a3);

extern const bool8 gUnknown_80F6DD5[][NUM_DIRECTIONS];

enum CardinalDirection
{
	CARDINAL_DIR_RIGHT,
	CARDINAL_DIR_UP,
	CARDINAL_DIR_LEFT,
	CARDINAL_DIR_DOWN,
	NUM_CARDINAL_DIRECTIONS
};

#define CARDINAL_DIRECTION_MASK 3

struct GridCell
{
    DungeonPos start;
    DungeonPos end;
    bool8 isInvalid;
    bool8 hasSecondaryStructure;
    bool8 isRoom;
    bool8 isConnected;
    bool8 isKecleonShop;
    bool8 unk13;
    bool8 isMonsterHouse;
    bool8 unk15;
    bool8 isMazeRoom;
    bool8 hasBeenMerged;
    bool8 isMerged;
    bool8 connectedToTop;
    bool8 connectedToBottom;
    bool8 connectedToLeft;
    bool8 connectedToRight;
    bool8 shouldConnectToTop;
    bool8 shouldConnectToBottom;
    bool8 shouldConnectToLeft;
    bool8 shouldConnectToRight;
    bool8 unk27;
    bool8 flagImperfect;
    bool8 flagSecondaryStructure;
    bool8 unk30;
    bool8 unk31;
};

#define GRID_CELL_LEN 15

static void ResetFloor(void);
static void sub_804C790(s32 gridSizeX, s32 gridSizeY, s32 fixedRoomSizeX, s32 fixedRoomSizeY, s32 fixedRoomNumber, FloorProperties *floorProps);
static void CreateRoomsAndAnchorsForFixedFloor(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, s32 a5, s32 fixedRoomSizeX, s32 fixedRoomSizeY);
static void sub_8051438(struct GridCell *gridCell, s32 fixedRoomNumber);
static void sub_8051288(s32 fixedRoomNumber);
static void GetGridPositions(s32 *listX, s32 *listY, s32 gridSizeX, s32 gridSizeY);
static void InitDungeonGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY);
static void GenerateRoomImperfections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY);
static void GenerateSecondaryStructure(struct GridCell *gridCell);
static void GenerateSecondaryStructures(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY);
static void AssignRooms(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 roomsNumber);
static void CreateRoomsAndAnchors(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, u32 roomFlags);
static void CreateGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, bool8 disableRoomMerging);
static void EnsureConnectedGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY);
static void AssignRandomGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, FloorProperties *floorProps);
static void AssignGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 cursorX, s32 cursorY, FloorProperties *floorProps);
static void GenerateMazeRoom(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance);
static void GenerateMaze(struct GridCell *gridCell, bool8 useSecondaryTerrain);
static void GenerateMazeLine(s32 x0, s32 y0, s32 xMin, s32 yMin, s32 xMax, s32 yMax, bool8 useSecondaryTerrain, u32 roomIndex);
static void GenerateKecleonShop(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance);
static void GenerateMonsterHouse(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance);
static void GenerateExtraHallways(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 numExtraHallways);
static void MergeRoomsVertically(s32 roomX, s32 roomY1, s32 room_dy, struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN]);
static void CreateHallway(s32 startX, s32 startY, s32 endX, s32 endY, bool8 vertical, s32 turnX, s32 turnY);
static void EnsureImpassableTilesAreWalls(void);
static void sub_804FC74(void);
static void FinalizeJunctions(void);
static void sub_804B534(s32 a0, s32 a1, s32 a2, s32 a3);
static bool8 ProcessFixedRoom(s32 fixedRoomNumber, FloorProperties *floorProps);
static void GenerateStandardFloor(s32 a0, s32 a1, FloorProperties *a2);
static void GenerateOuterRingFloor(FloorProperties *a0);
static void GenerateCrossroadsFloor(FloorProperties *a0);
static void GenerateLineFloor(FloorProperties *a0);
static void GenerateCrossFloor(FloorProperties *a0);
static void GenerateBeetleFloor(FloorProperties *a0);
static void GenerateOuterRoomsFloor(s32 gridSizeX_, s32 gridSizeY_, FloorProperties *floorProps);
static void sub_8051654(FloorProperties *floorProps);
static void GenerateSecondaryTerrainFormations(u32 flag, FloorProperties *floorProps);
static void SpawnNonEnemies(FloorProperties *floorProps, bool8 isEmptyMonsterHouse);
static void SpawnEnemies(FloorProperties *floorProps, bool8 isEmptyMonsterHouse);
static void ResetInnerBoundaryTileRows(void);
static void GenerateOneRoomMonsterHouseFloor(void);
static void ResolveInvalidSpawns(void);
static void GenerateTwoRoomsWithMonsterHouseFloor(void);

EWRAM_DATA bool8 gUnknown_202F1A8 = FALSE;
static EWRAM_DATA bool8 sInvalidGeneration = FALSE;
static EWRAM_DATA bool8 sHasKecleonShop = FALSE;
static EWRAM_DATA bool8 sHasMonsterHouse = FALSE;
static EWRAM_DATA bool8 sHasMaze = FALSE;
static EWRAM_DATA bool8 sSecondSpawn = FALSE;
static EWRAM_DATA u8 sFloorSize = 0;
static EWRAM_DATA s16 sKecleonShopChance = 0;
static EWRAM_DATA s16 sMonsterHouseChance = 0;
static EWRAM_DATA u8 sStairsRoomIndex = 0;
static EWRAM_DATA struct MinMaxPosition sKecleonShopPosition = {0};
static EWRAM_DATA s32 sSecondaryStructuresBudget = 0;
static EWRAM_DATA s32 sNumRooms = 0;
static EWRAM_DATA s32 sFloorLayout = 0;
static EWRAM_DATA s32 sNumTilesReachableFromStairs = 0;
static EWRAM_DATA DungeonPos sKecleonShopMiddlePos = {0};

struct FixedRoomsData
{
    u8 x;
    u8 y;
    u8 unk2;
    u8 unk3[0]; // Not sure about the size;
};

/*
 * GenerateFloor - The Master Function for generating a dungeon floor
 *
 * Runs based on 3 loop levels of safety
 *
 * Innermost Loop: 32 attempts for deciding the maximum rooms in each dimension for the floor
 * 		- The dimensions are capped at 6x4 (but we can randomize outside this range and fail)
 * 		- Must maintain a certain number of tiles per grid cell in both dimensions
 * 		- If this loop fails 32 times, defaults to a 4x4 maximum
 *
 * Inner Main Loop: 10 attempts for the main layout of a floor
 * 		- This loop can fail by being marked invalid during generation
 * 		- Or, it can fail by having < 2 rooms or < 20 room tiles
 * 		- This occurs prior to secondary terrain generation
 * 		- If the loop fails 10 times, defaults to generating a One-Room Monster House
 *
 * Outermost Loop: 10 attempts for everything involved in generating a layout
 * 		- This is where secondary terrain generation and junction additions takes place
 * 		- This loop can fail during spawn location verification (can you get to the stairs?)
 * 		- If the loop fails 10 times, defaults to generating a One-Room Monster House
 */
void GenerateFloor(void)
{
    s32 x, y;
    s32 spawnAttempts;
    bool8 secondaryGen = FALSE;
    FloorProperties *floorProps = &gDungeon->unk1C574;

    gDungeon->unk13568 = OpenFileAndGetFileDataPtr(gUnknown_80F6DCC, &gDungeonFileArchive);
    sHasKecleonShop = FALSE;
    sHasMonsterHouse = 0;
    sHasMaze = FALSE;
    gUnknown_202F1A8 = (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_WATER);
    sStairsRoomIndex = 0xFF;
    sFloorSize = 0;
    sKecleonShopChance = floorProps->kecleonShopChance;
    sMonsterHouseChance = floorProps->monsterHouseChance;
    sSecondSpawn = TRUE;
    sKecleonShopPosition.minX = -1;
    sKecleonShopPosition.maxX = -1;
    sKecleonShopPosition.minY = -1;
    sKecleonShopPosition.maxY = -1;

    ResetFloor();

    gDungeon->unk644.unk20 = abs(floorProps->enemyDensity);

    gDungeon->unk3A09 = 0;
    gDungeon->unk3A0A = 0;

    sSecondaryStructuresBudget = floorProps->secondaryStructuresBudget;

    for (spawnAttempts = 0; spawnAttempts < 10; spawnAttempts++) {
        s32 genAttempts;
        bool32 isEmptyMonsterHouse;

        gDungeon->playerSpawn.x = -1;
        gDungeon->playerSpawn.y = -1;
        gDungeon->stairsSpawn.x = -1;
        gDungeon->stairsSpawn.y = -1;
        // Actual generation attempts, up to 10 times per entity
        for (genAttempts = 0; genAttempts < 10; genAttempts++) {
            gDungeon->unk3A16 = genAttempts;
            if (genAttempts > 0) {
                sSecondaryStructuresBudget = 0;
            }
            sInvalidGeneration = FALSE;
            sKecleonShopMiddlePos.x = -1;
            sKecleonShopMiddlePos.y = -1;

            ResetFloor();

            gDungeon->playerSpawn.x = -1;
            gDungeon->playerSpawn.y = -1;
            gDungeon->forceMonsterHouse = FALSE;
            if (gDungeon->fixedRoomNumber != 0) {
                // Check for a full-floor fixed room, if this is the case, generation is done.
                if (ProcessFixedRoom(gDungeon->fixedRoomNumber, floorProps)) {
                    break;
                }
            }
            else {
                s32 gridSizeX, gridSizeY;
                s32 attempts;
                u8 layout = floorProps->layout;

                // Attempt to generate random grid dimensions
                attempts = 32;
                while (1) {
                    if (layout != LAYOUT_LARGE_0x8) {
                        gridSizeX = DungeonRandRange(2, 9);
                        gridSizeY = DungeonRandRange(2, 8);
                    }
                    else {
                        gridSizeX = DungeonRandRange(2, 5);
                        gridSizeY = DungeonRandRange(2, 4);
                    }

                    // Limit overall dimensions
                    if (gridSizeX <= 6 && gridSizeY <= 4) {
                        break;
                    }
                    if (--attempts == 0) {
                        // We failed to generate random grid dimensions, default to 4x4
                        gridSizeX = 4;
                        gridSizeY = 4;
                        break;
                    }
                }

                // Make sure there are at least 7 tiles per grid cell in both
                // dimensions. Otherwise, the grid size is too big so default to 1
                if (DUNGEON_MAX_SIZE_X / gridSizeX < 8) {
                    gridSizeX = 1;
                }
                if (DUNGEON_MAX_SIZE_Y / gridSizeY < 8) {
                    gridSizeY = 1;
                }

                gDungeon->forceMonsterHouse = FALSE;
                gDungeon->monsterHouseRoom = 0xFF;
                sFloorLayout = layout;
                switch (layout % NUM_FLOOR_LAYOUTS) {
                    case LAYOUT_SMALL:
                        gridSizeX = 4;
                        gridSizeY = DungeonRandInt(2) + 2;
                        sFloorSize = FLOOR_SIZE_SMALL;
                        GenerateStandardFloor(gridSizeX, gridSizeY, floorProps);
                        secondaryGen = TRUE;
                        break;
                    case LAYOUT_MEDIUM:
                        gridSizeX = 4;
                        gridSizeY = DungeonRandInt(2) + 2;
                        sFloorSize = FLOOR_SIZE_MEDIUM;
                        GenerateStandardFloor(gridSizeX, gridSizeY, floorProps);
                        secondaryGen = TRUE;
                        break;
                    case LAYOUT_LARGE:
                    case LAYOUT_LARGE_0x8:
                    default:
                        GenerateStandardFloor(gridSizeX, gridSizeY, floorProps);
                        secondaryGen = TRUE;
                        break;
                    case LAYOUT_ONE_ROOM_MONSTER_HOUSE:
                        GenerateOneRoomMonsterHouseFloor();
                        gDungeon->forceMonsterHouse = TRUE;
                        break;
                    case LAYOUT_OUTER_RING:
                        GenerateOuterRingFloor(floorProps);
                        secondaryGen = TRUE;
                        break;
                    case LAYOUT_CROSSROADS:
                        GenerateCrossroadsFloor(floorProps);
                        secondaryGen = TRUE;
                        break;
                    case LAYOUT_TWO_ROOMS_WITH_MONSTER_HOUSE:
                        GenerateTwoRoomsWithMonsterHouseFloor();
                        gDungeon->forceMonsterHouse = TRUE;
                        break;
                    case LAYOUT_LINE:
                        GenerateLineFloor(floorProps);
                        secondaryGen = TRUE;
                        break;
                    case LAYOUT_CROSS:
                        GenerateCrossFloor(floorProps);
                        break;
                    case LAYOUT_BEETLE:
                        GenerateBeetleFloor(floorProps);
                        break;
                    case LAYOUT_OUTER_ROOMS:
                        GenerateOuterRoomsFloor(gridSizeX, gridSizeY, floorProps);
                        secondaryGen = TRUE;
                        break;
                }
            }

            ResetInnerBoundaryTileRows();
            EnsureImpassableTilesAreWalls();

            // Nothing failed during generation. This variable is always set to FALSE, so the check always passes
            if (!sInvalidGeneration) {
                // We need to make sure there are at least 2 rooms with at least 20 total tiles
                s32 numRooms = 0;
                bool8 rooms[64];
                s32 roomTiles = 0;
                s32 i;

                for (i = 0; i < 64; i++) {
                    rooms[i] = FALSE;
                }

                for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
                    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
                        const Tile *tile = GetTile(x, y);
                        if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL && tile->room <= 240) {
                            roomTiles++;
                            if (tile->room < 64) {
                                rooms[tile->room] = TRUE;
                            }
                        }
                    }
                }

                numRooms = 0;
                // In order to match, 'y' had to be re-used as an iterator var
                for (y = 0; y < 64; y++) {
                    if (rooms[y]) {
                        numRooms++;
                    }
                }

                if (roomTiles >= 30 && numRooms >= 2) {
                    break; // This layout is good!
                }
            }
        }

        // If we fail to generate a layout in 10 attempts, just abort and make a one-room Monster House
        if (genAttempts == 10) {
            sKecleonShopMiddlePos.x = -1;
            sKecleonShopMiddlePos.y = -1;
            GenerateOneRoomMonsterHouseFloor();
            gDungeon->forceMonsterHouse = TRUE;
        }

        // We will be guaranteed to have a good layout by this point
        FinalizeJunctions();
        if (secondaryGen) {
            GenerateSecondaryTerrainFormations(ROOM_FLAG_ALLOW_SECONDARY_TERRAIN, floorProps);
        }

        isEmptyMonsterHouse = (DungeonRandInt(100) < floorProps->itemlessMonsterHouseChance);
        SpawnNonEnemies(floorProps, isEmptyMonsterHouse);
        SpawnEnemies(floorProps, isEmptyMonsterHouse);

        ResolveInvalidSpawns(); // Make sure multiple flags aren't set for one tile
        if (gDungeon->playerSpawn.x != -1 && gDungeon->playerSpawn.y != -1) {
            // This is for normal fixed rooms, we don't need to validate the stairs in this scenario
            // Since it's fixed already
            if (GetFloorType() == FLOOR_TYPE_FIXED)
                break;
            if (gDungeon->stairsSpawn.x != -1 && gDungeon->stairsSpawn.y != -1 && StairsAlwaysReachable(gDungeon->stairsSpawn.x, gDungeon->stairsSpawn.y, FALSE))
                break; // We can reach the stairs, we're good!
        }

        // Something went bad with spawns, we'll need to retry on a new generation
    }

    // If we fail with spawns (or otherwise) 10 times, opt for a One-Room Monster House generation
    if (spawnAttempts == 10) {
        sKecleonShopMiddlePos.x = -1;
        sKecleonShopMiddlePos.y = -1;

        ResetFloor();
        GenerateOneRoomMonsterHouseFloor();
        gDungeon->forceMonsterHouse = TRUE;

        FinalizeJunctions();
        SpawnNonEnemies(floorProps, FALSE);
        SpawnEnemies(floorProps, FALSE);
        ResolveInvalidSpawns();
        // We don't care about validating because this is our bailout, so we're done!
    }

    if (sKecleonShopMiddlePos.x >= 0 && sKecleonShopMiddlePos.y >= 0) {
        sub_806C330(sKecleonShopMiddlePos.x, sKecleonShopMiddlePos.y, MONSTER_KECLEON, 0);
    }

    if (sKecleonShopPosition.minX >= 0) {
        sub_8051654(floorProps);
        gDungeon->unk3A0A = 1;
    }
    else {
        gDungeon->unk3A0A = 0;
    }

    sub_804B534(0, 0, DUNGEON_MAX_SIZE_X, DUNGEON_MAX_SIZE_Y);
    if (gUnknown_202F1A8) {
        sub_804FC74();
    }

    CloseFile(gDungeon->unk13568);
}

static void sub_804B534(s32 xStart, s32 yStart, s32 maxX, s32 maxY)
{
    s32 x, y;
    for (x = xStart; x < maxX; x++) {
        for (y = yStart; y < maxY; y++) {
            s32 unkCount = 0;
            Tile *tile = GetTileMut(x, y);

            tile->terrainType &= ~(TERRAIN_TYPE_CORNER_CUTTABLE);
            if (tile->room == CORRIDOR_ROOM && (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL)) {
                if (x > 0 && (GetTerrainType(GetTile(x - 1, y)) == TERRAIN_TYPE_NORMAL))
                    unkCount++;
                if (y > 0 && (GetTerrainType(GetTile(x, y - 1)) == TERRAIN_TYPE_NORMAL))
                    unkCount++;
                if (x < DUNGEON_MAX_SIZE_X - 2 && (GetTerrainType(GetTile(x + 1, y)) == TERRAIN_TYPE_NORMAL))
                    unkCount++;
                // BUG: It should check for y and not x. Not sure if it has any effect, because this function is called only once with maxY equal to DUNGEON_MAX_SIZE_Y
                if (x < DUNGEON_MAX_SIZE_Y - 2 && (GetTerrainType(GetTile(x, y + 1)) == TERRAIN_TYPE_NORMAL))
                    unkCount++;

                if (unkCount > 2) {
                    tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                }
            }
        }
    }
}

/*
 * GenerateStandardFloor - Generates a standard, typical floor layout.
 *
 * Overview:
 * 1. Determine the grid based on gridSizeX, gridSizeY
 * 2. Assign and create rooms and hallway anchors to each grid cell
 * 3. Assign and create connections between grid cells (these are traditional hallways connecting the map together)
 * 4. Fix any unconnected grid cells by adding more connections or removing their rooms/hallway anchors
 * 5. Generate special rooms like a Maze Room (unused in vanilla?), Kecleon Shop, or Monster House
 * 6. Create additional "extra hallways" with random walks outside of existing rooms
 * 7. Finalize extra room details with imperfections (unused in vanilla?), and structures with secondary terrain
 */
static void GenerateStandardFloor(s32 gridSizeX, s32 gridSizeY, FloorProperties *floorProps)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];

    GetGridPositions(listX, listY, gridSizeX, gridSizeY);

    InitDungeonGrid(grid, gridSizeX, gridSizeY);

    AssignRooms(grid, gridSizeX, gridSizeY, floorProps->roomDensity);

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, floorProps->roomFlags);

    AssignRandomGridCellConnections(grid, gridSizeX, gridSizeY, floorProps);
    CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, FALSE);

    EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

    GenerateMazeRoom(grid, gridSizeX, gridSizeY, floorProps->mazeRoomChance);
    GenerateKecleonShop(grid, gridSizeX, gridSizeY, sKecleonShopChance);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, sMonsterHouseChance);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, floorProps->numExtraHallways);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
    GenerateSecondaryStructures(grid, gridSizeX, gridSizeY);
}

// GenerateOuterRingFloor - Generates on a 6x4 grid, with the outer border of grid cells being hallways and the inner 4x2 grid being rooms.
static void GenerateOuterRingFloor(FloorProperties *floorProps)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 x, y;
    s32 currRoomIndex;
	s32 gridSizeX = 6;
	s32 gridSizeY = 4;
	// These are needed to match. Perhaps they wanted the code to be clear that inside = rooms, and outside = hallways.
    bool8 outerIsRoom = FALSE;
    bool8 innerIsRoom = TRUE;

	listX[0] = 0;
	listX[1] = 5;
    listX[3] = 28;
    listX[5] = 51;
	listX[6] = 56;
    listX[2] = 16;
	listX[4] = 39;

	listY[0] = 2;
	listY[1] = 7;
	listY[2] = 16;
	listY[3] = 25;
	listY[4] = 30;

	InitDungeonGrid(grid, gridSizeX, gridSizeY);

	// Mark the outer ring as not being rooms
	for (x = 0; x < gridSizeX; x++) {
		grid[x][0].isRoom = outerIsRoom;
		grid[x][gridSizeY - 1].isRoom = outerIsRoom;
	}

	for (y = 0; y < gridSizeY; y++) {
		grid[0][y].isRoom = outerIsRoom;
		grid[gridSizeX - 1][y].isRoom = outerIsRoom;
	}

	// Mark the inner tiles as rooms
	for (x = 1; x < gridSizeX - 1; x++) {
		for (y = 1; y < gridSizeY - 1; y++) {
            grid[x][y].isRoom = innerIsRoom;
		}
	}

    currRoomIndex = 0;

	for (y = 0; y < gridSizeY; y++) {
		for (x = 0; x < gridSizeX; x++) {
            if (grid[x][y].isRoom) {
            	// Room
            	s32 curX, curY;
                s32 minX = listX[x] + 2;
                s32 minY = listY[y] + 2;
            	s32 rangeX = listX[x + 1] - listX[x] - 3;
            	s32 rangeY = listY[y + 1] - listY[y] - 3;

            	s32 roomSizeX = DungeonRandRange(5, rangeX);
            	s32 roomSizeY = DungeonRandRange(4, rangeY);
            	s32 startX = DungeonRandInt(rangeX - roomSizeX) + minX;
            	s32 startY = DungeonRandInt(rangeY - roomSizeY) + minY;
            	s32 endX = startX + roomSizeX;
            	s32 endY = startY + roomSizeY;

            	grid[x][y].start.x = startX;
            	grid[x][y].end.x = endX;
            	grid[x][y].start.y = startY;
            	grid[x][y].end.y = startY + roomSizeY;
            	for (curX = startX; curX < endX; curX++) {
            		for (curY = startY; curY < endY; curY++) {
                        SetTerrainNormal(GetTileMut(curX, curY));
                        GetTileMut(curX, curY)->room = currRoomIndex;
            		}
            	}

            	currRoomIndex++;
            }
            else
            {
            	// Hallway Anchor
            	s32 minX = listX[x] + 1;
                s32 minY = listY[y] + 1;
                s32 rangeX = listX[x + 1] - listX[x] - 3;
                s32 rangeY = listY[y + 1] - listY[y] - 3;
            	s32 startX = DungeonRandRange(minX, minX + rangeX);
            	s32 startY = DungeonRandRange(minY, minY + rangeY);

            	grid[x][y].start.x = startX;
            	grid[x][y].end.x = startX + 1;
            	grid[x][y].start.y = startY;
            	grid[x][y].end.y = startY + 1;

            	SetTerrainNormal(GetTileMut(startX, startY));
            	GetTileMut(startX, startY)->room = CORRIDOR_ROOM;
            }
		}
	}

	grid[0][0].connectedToRight = TRUE;
	grid[1][0].connectedToLeft = TRUE;
	grid[1][0].connectedToRight = TRUE;
	grid[2][0].connectedToLeft = TRUE;
	grid[2][0].connectedToRight = TRUE;
	grid[3][0].connectedToLeft = TRUE;
	grid[3][0].connectedToRight = TRUE;
	grid[4][0].connectedToLeft = TRUE;
	grid[4][0].connectedToRight = TRUE;
	grid[5][0].connectedToLeft = TRUE;
	grid[0][0].connectedToBottom = TRUE;
	grid[0][1].connectedToTop = TRUE;
	grid[0][1].connectedToBottom = TRUE;
	grid[0][2].connectedToTop = TRUE;
	grid[0][2].connectedToBottom = TRUE;
	grid[0][3].connectedToTop = TRUE;
	grid[0][3].connectedToRight = TRUE;
	grid[1][3].connectedToLeft = TRUE;
	grid[1][3].connectedToRight = TRUE;
	grid[2][3].connectedToLeft = TRUE;
	grid[2][3].connectedToRight = TRUE;
	grid[3][3].connectedToLeft = TRUE;
	grid[3][3].connectedToRight = TRUE;
	grid[4][3].connectedToLeft = TRUE;
	grid[4][3].connectedToRight = TRUE;
	grid[5][3].connectedToLeft = TRUE;
	grid[5][0].connectedToBottom = TRUE;
	grid[5][1].connectedToTop = TRUE;
	grid[5][1].connectedToBottom = TRUE;
	grid[5][2].connectedToTop = TRUE;
	grid[5][2].connectedToBottom = TRUE;
	grid[5][3].connectedToTop = TRUE;

	AssignRandomGridCellConnections(grid, gridSizeX, gridSizeY, floorProps);
	CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, FALSE);

	EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

	GenerateKecleonShop(grid, gridSizeX, gridSizeY, sKecleonShopChance);
	GenerateMonsterHouse(grid, gridSizeX, gridSizeY, sMonsterHouseChance);

	GenerateExtraHallways(grid, gridSizeX, gridSizeY, floorProps->numExtraHallways);
	GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

/*
 * GenerateCrossroadsFloor - Generates a floor layout with hallways on the inside and rooms on the outside, with empty corners.
 * Also nicknamed "Ladder Layout" by some.
 */
static void GenerateCrossroadsFloor(FloorProperties *floorProps)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 x, y;
    s32 currRoomIndex;
    s32 gridSizeX = 5;
	s32 gridSizeY = 4;
    // These are needed to match. Perhaps they wanted the code to be clear that outside = rooms, and inside = hallways.
    bool8 outerIsRoom = TRUE;
    bool8 innerIsRoom = FALSE;

	listX[0] = 0;
	listX[1] = 11;
	listX[2] = 22;
	listX[3] = 33;
	listX[4] = 44;
	listX[5] = 56;

	listY[0] = 1;
	listY[1] = 9;
	listY[2] = 16;
	listY[3] = 23;
	listY[4] = 31;

	InitDungeonGrid(grid, gridSizeX, gridSizeY);

    // Mark the outer ring as rooms
	for (x = 0; x < gridSizeX; x++) {
		grid[x][0].isRoom = outerIsRoom;
		grid[x][gridSizeY - 1].isRoom = outerIsRoom;
	}

	for (y = 0; y < gridSizeY; y++) {
		grid[0][y].isRoom = outerIsRoom;
		grid[gridSizeX - 1][y].isRoom = outerIsRoom;
	}

	// Mark the inner cells as hallways
	for (x = 1; x < gridSizeX - 1; x++) {
		for (y = 1; y < gridSizeY - 1; y++) {
            grid[x][y].isRoom = innerIsRoom;
		}
	}

	// Invalidate the corners
	grid[0][0].isInvalid = TRUE;
	grid[4][0].isInvalid = TRUE;
    grid[0][3].isInvalid = TRUE;
	grid[4][3].isInvalid = TRUE;

    currRoomIndex = 0;
	for (y = 0; y < gridSizeY; y++) {
		for (x = 0; x < gridSizeX; x++) {
            if (grid[x][y].isInvalid)
                continue;

            if (grid[x][y].isRoom) {
            	// Room
                s32 curX, curY;
                s32 minX = listX[x] + 2;
                s32 minY = listY[y] + 2;
            	s32 rangeX = listX[x + 1] - listX[x] - 3;
            	s32 rangeY = listY[y + 1] - listY[y] - 3;

            	s32 roomSizeX = DungeonRandRange(5, rangeX);
            	s32 roomSizeY = DungeonRandRange(4, rangeY);
            	s32 startX = DungeonRandInt(rangeX - roomSizeX) + minX;
            	s32 startY = DungeonRandInt(rangeY - roomSizeY) + minY;
            	s32 endX = startX + roomSizeX;
            	s32 endY = startY + roomSizeY;

            	grid[x][y].start.x = startX;
                grid[x][y].end.x = endX;
            	grid[x][y].start.y = startY;
            	grid[x][y].end.y = endY;
            	for (curX = startX; curX < endX; curX++) {
            		for (curY = startY; curY < endY; curY++) {
                        SetTerrainNormal(GetTileMut(curX, curY));
                        GetTileMut(curX, curY)->room = currRoomIndex;
            		}
            	}

            	currRoomIndex += 1;
            }
            else {
            	// Hallway Anchor
                s32 minX = listX[x] + 1;
                s32 minY = listY[y] + 1;
                s32 rangeX = listX[x + 1] - listX[x] - 3;
                s32 rangeY = listY[y + 1] - listY[y] - 3;
            	s32 startX = DungeonRandRange(minX, minX + rangeX);
            	s32 startY = DungeonRandRange(minY, minY + rangeY);

            	grid[x][y].start.x = startX;
                grid[x][y].end.x = startX + 1;
            	grid[x][y].start.y = startY;
            	grid[x][y].end.y = startY + 1;

            	SetTerrainNormal(GetTileMut(startX, startY));
            	GetTileMut(startX, startY)->room = CORRIDOR_ROOM;
            }
		}
	}

    for (x = 1; x < 5 - 1; x++) {
        for (y = 0; y < 4 - 1; y++) {
            grid[x][y].connectedToBottom = TRUE;
            grid[x][y + 1].connectedToTop = TRUE;
        }
    }

    for (y = 1; y < 4 - 1; y++) {
        for (x = 0; x < 5 - 1; x++) {
            grid[x][y].connectedToRight = TRUE;
            grid[x + 1][y].connectedToLeft = TRUE;
        }
    }

	CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, TRUE);

	EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);
	GenerateKecleonShop(grid, gridSizeX, gridSizeY, sKecleonShopChance);
	GenerateMonsterHouse(grid, gridSizeX, gridSizeY, sMonsterHouseChance);

	GenerateExtraHallways(grid, gridSizeX, gridSizeY, floorProps->numExtraHallways);
	GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

// GenerateLineFloor - Generates a floor layout with 5 grid cells in a horizontal line.
static void GenerateLineFloor(FloorProperties *floorProps)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 gridSizeX, gridSizeY;
    bool8 disableRoomMerging;

    listX[0] = 0;
    listX[1] = 11;
    listX[2] = 22;
    listX[3] = 33;
    listX[4] = 44;
    listX[5] = 56;

    listY[0] = 4;
    listY[1] = 15;

    disableRoomMerging = 1;
    gridSizeX = 5, gridSizeY = 1;
    InitDungeonGrid(grid, gridSizeX, gridSizeY);

    AssignRooms(grid, gridSizeX, gridSizeY, floorProps->roomDensity);
    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, floorProps->roomFlags);

    AssignRandomGridCellConnections(grid, gridSizeX, gridSizeY, floorProps);
    CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, disableRoomMerging);

    EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

    GenerateKecleonShop(grid, gridSizeX, gridSizeY, sKecleonShopChance);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, sMonsterHouseChance);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, floorProps->numExtraHallways);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

// GenerateCrossFloor - Generates a floor layout with 5 rooms arranged in a "plus" or "cross" configuration.
static void GenerateCrossFloor(FloorProperties *floorProps)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 x, y, gridSizeX, gridSizeY;

    listX[0] = 11;
    listX[1] = 22;
    listX[2] = 33;
    listX[3] = 44;

    listY[0] = 2;
    listY[1] = 11;
    listY[2] = 20;
    listY[3] = 30;

    gridSizeX = 3, gridSizeY = 3;
    InitDungeonGrid(grid, gridSizeX, gridSizeY);

    // Set all cells as rooms
    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            grid[x][y].isRoom = TRUE;
        }
    }

    // Invalidate the corners
    grid[0][0].isInvalid = TRUE;
    grid[2][0].isInvalid = TRUE;
    grid[0][2].isInvalid = TRUE;
    grid[2][2].isInvalid = TRUE;

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, floorProps->roomFlags);

    grid[0][1].connectedToRight = TRUE;
    grid[1][1].connectedToLeft = TRUE;
    grid[1][1].connectedToRight = TRUE;
    grid[2][1].connectedToLeft = TRUE;
    grid[1][0].connectedToBottom = TRUE;
    grid[1][1].connectedToTop = TRUE;
    grid[1][1].connectedToBottom = TRUE;
    grid[1][2].connectedToTop = TRUE;
    CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, TRUE);

    EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

    GenerateKecleonShop(grid, gridSizeX, gridSizeY, sKecleonShopChance);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, sMonsterHouseChance);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, floorProps->numExtraHallways);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

// GenerateBeetleFloor - Generates a floor layout in a "beetle" shape, with a
// 3x3 grid of rooms, a merged center column, and hallways along each row
static void GenerateBeetleFloor(FloorProperties *floorProps)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 x, y, gridSizeX, gridSizeY;

    listX[0] = 5;
    listX[1] = 15;
    listX[2] = 35;
    listX[3] = 50;

    listY[0] = 2;
    listY[1] = 11;
    listY[2] = 20;
    listY[3] = 30;

    gridSizeX = 3, gridSizeY = 3;
    InitDungeonGrid(grid, gridSizeX, gridSizeY);
    // Set all cells as rooms
    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            grid[x][y].isRoom = TRUE;
        }
    }

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, floorProps->roomFlags);

    // Connect rooms in the same row together
    for (y = 0; y < 3; y++) {
        grid[0][y].connectedToRight = TRUE;
        grid[1][y].connectedToLeft = TRUE;
        grid[1][y].connectedToRight = TRUE;
        grid[2][y].connectedToLeft = TRUE;
    }
    CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, TRUE);

    // Merge the center column into one large room
    MergeRoomsVertically(1, 0, 1, grid);
    MergeRoomsVertically(1, 0, 2, grid);

    EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

    GenerateKecleonShop(grid, gridSizeX, gridSizeY, sKecleonShopChance);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, sMonsterHouseChance);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, floorProps->numExtraHallways);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

// MergeRoomsVertically - Merges two vertically stacked rooms into one larger room.
static void MergeRoomsVertically(s32 roomX, s32 roomY1, s32 room_dy, struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN])
{
    s32 x, y;
    s32 xStart = min(grid[roomX][roomY1].start.x, grid[roomX][roomY1+room_dy].start.x);
    s32 yStart = grid[roomX][roomY1].start.y;
    s32 xEnd = max(grid[roomX][roomY1].end.x, grid[roomX][roomY1+room_dy].end.x);
    s32 yEnd = grid[roomX][roomY1 + room_dy].end.y;

    // Carve out the new larger room, retaining the index of the first room
    u8 roomId = GetTile(grid[roomX][roomY1].start.x, grid[roomX][roomY1].start.y)->room;

    for (x = xStart; x < xEnd; x++) {
        for (y = yStart; y < yEnd; y++) {
            Tile *tile = GetTileMut(x, y);
            SetTerrainNormal(tile);
            tile->room = roomId;
        }
    }

    grid[roomX][roomY1].start.x = xStart;
    grid[roomX][roomY1].end.x = xEnd;
    grid[roomX][roomY1].start.y = yStart;
    grid[roomX][roomY1].end.y = yEnd;

    grid[roomX][roomY1 + room_dy].isMerged = TRUE;
    grid[roomX][roomY1].isMerged = TRUE;
    grid[roomX][roomY1 + room_dy].isConnected = FALSE;
    grid[roomX][roomY1 + room_dy].hasBeenMerged = TRUE;
}

// GenerateOuterRoomsFloor - Generates a floor layout with a ring of rooms and nothing on the interior.
// This layout is bugged and will not properly connect rooms for gridSizeX < 3.
static void GenerateOuterRoomsFloor(s32 gridSizeX_, s32 gridSizeY_, FloorProperties *floorProps)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 x, y;
    s32 gridSizeX = gridSizeX_;
    s32 gridSizeY = gridSizeY_;

    GetGridPositions(listX, listY, gridSizeX, gridSizeY);
    InitDungeonGrid(grid, gridSizeX, gridSizeY);

    // Make all cells rooms
    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            grid[x][y].isRoom = TRUE;
        }
    }

    // Invalidate all interior cells
    for (x = 1; x < gridSizeX - 1; x++) {
        for (y = 1; y < gridSizeY - 1; y++) {
            grid[x][y].isInvalid = TRUE;
        }
    }

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, floorProps->roomFlags);

    // Maybe Todo: Add EpicYoshiMaster's fixed implementation of this function

    // The original implementation fails for gridSizeX <= 2, as one of the branches
    // is never taken, and the other branch does not provide a backup connection, leaving the two sides unconnected.
    // Additionally, there is a minor issue for top/bottom connections which results in hallways being connected from the bottom
    // instead of from the top, but this does not affect the connectivity of the map.
    for (x = 0; x < gridSizeX - 1; x++) {
        if (x != 0) {
            grid[x][0].connectedToRight = TRUE;
            grid[x][gridSizeY-1].connectedToRight = TRUE;
        }

        // Bug: if gridSizeX <= 2, this branch will never be run.
        // Additionally, because the branch above this has no meaningful hallways produced for
        // gridSizeX == 1, no connections will be made between columns here.
        // This results in an unconnected map for gridSizeX <= 2.
        if (x < gridSizeX - 2) {
            grid[x+1][0].connectedToLeft = TRUE;
            grid[x+1][gridSizeY-1].connectedToLeft = TRUE;
        }
    }

    for (y = 0; y < gridSizeY - 1; y++) {
        if (y != 0) {
            grid[0][y].connectedToTop = TRUE;
            grid[gridSizeX-1][y].connectedToTop = TRUE;
        }

        // This connection ends up not being set for the bottom row, but this is fine because the other
        // connection to this room is still correct. The result is that hallways here will be using the opposing end
        // of the grid cell boundary for their turns compared to top/bottom hallways between other rows.
        if (y < gridSizeY - 2) {
            grid[0][y].connectedToBottom = TRUE;
            grid[gridSizeX-1][y].connectedToBottom = TRUE;
        }
    }

    CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, FALSE);

    EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

    GenerateMazeRoom(grid, gridSizeX, gridSizeY, floorProps->mazeRoomChance);
    GenerateKecleonShop(grid, gridSizeX, gridSizeY, sKecleonShopChance);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, sMonsterHouseChance);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, floorProps->numExtraHallways);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
    GenerateSecondaryStructures(grid, gridSizeX, gridSizeY);
}

static bool8 ProcessFixedRoom(s32 fixedRoomNumber, FloorProperties *floorProps)
{
    s32 fixedRoomSizeX = ((struct FixedRoomsData **)(gDungeon->unk13568->data))[fixedRoomNumber]->x;
    s32 fixedRoomSizeY = ((struct FixedRoomsData **)(gDungeon->unk13568->data))[fixedRoomNumber]->y;
    s32 gridSizeX, gridSizeY;

    if (fixedRoomSizeX == 0 || fixedRoomSizeY == 0) {
        GenerateOneRoomMonsterHouseFloor();
        return FALSE;
    }
    else if (fixedRoomNumber < 50) {
        sub_8051288(fixedRoomNumber);
        return TRUE;
    }
    else {
        gridSizeX = DUNGEON_MAX_SIZE_X / (fixedRoomSizeX + 4);
        if (gridSizeX <= 1)
            gridSizeX = 1;
        gridSizeY = DUNGEON_MAX_SIZE_Y / (fixedRoomSizeY + 4);
        if (gridSizeY <= 1)
            gridSizeY = 1;
        sub_804C790(gridSizeX, gridSizeY, fixedRoomSizeX, fixedRoomSizeY, fixedRoomNumber, floorProps);
        return FALSE;
    }
}

static void sub_804C790(s32 gridSizeX, s32 gridSizeY, s32 fixedRoomSizeX, s32 fixedRoomSizeY, s32 fixedRoomNumber, FloorProperties *floorProps)
{
    s32 tries;
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 r10 = 0;
    s32 cursorX = 0, cursorY = 0;

    GetGridPositions(listX, listY, gridSizeX, gridSizeY);
    InitDungeonGrid(grid, gridSizeX, gridSizeY);
    AssignRooms(grid, gridSizeX, gridSizeY, floorProps->roomDensity);
    for (cursorX = 0; cursorX < gridSizeX; cursorX++) {
        for (cursorY = 0; cursorY < gridSizeY; cursorY++) {
            grid[cursorX][cursorY].unk27 = 1;
        }
    }

    for (tries = 0; tries < 64; tries++) {
        cursorX = DungeonRandInt(gridSizeX);
        cursorY = DungeonRandInt(gridSizeY);
        r10 = cursorY * gridSizeX + cursorX;
        if (grid[cursorX][cursorY].isRoom)
            break;
    }
    CreateRoomsAndAnchorsForFixedFloor(grid, gridSizeX, gridSizeY, listX, listY, r10, fixedRoomSizeX, fixedRoomSizeY);
    if (gridSizeX != 1 || gridSizeY != 1) {
        AssignGridCellConnections(grid, gridSizeX, gridSizeY, cursorX, cursorY, floorProps);
        CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, TRUE);
        EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);
    }
    sub_8051438(&grid[cursorX][cursorY], fixedRoomNumber);
}

/*
 * GenerateOneRoomMonsterHouseFloor - Generates a floor layout with just one large room which is a Monster House.
 * This generator is used as a fallback if the event generation fails too many times.
 */
static void GenerateOneRoomMonsterHouseFloor(void)
{
    s32 x, y;
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];

    InitDungeonGrid(grid, 1, 1);

    grid[0][0].start.x = 2;
    grid[0][0].end.x = DUNGEON_MAX_SIZE_X - 2;
    grid[0][0].start.y = 2;
    grid[0][0].end.y = DUNGEON_MAX_SIZE_Y - 2;

    grid[0][0].isRoom = TRUE;
    grid[0][0].isConnected = TRUE;
    grid[0][0].isInvalid = FALSE;

    for (x = grid[0][0].start.x; x < grid[0][0].end.x; x++) {
        for (y = grid[0][0].start.y; y < grid[0][0].end.y; y++) {
            SetTerrainNormal(GetTileMut(x, y));
            GetTileMut(x, y)->room = 0;
        }
    }
    GenerateMonsterHouse(grid, 1, 1, 999);
}

// GenerateTwoRoomsWithMonsterHouseFloor - Generates a floor layout with two rooms (left and right), with one being a Monster House.
static void GenerateTwoRoomsWithMonsterHouseFloor(void)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    const s32 gridSizeX = 2;
    const s32 gridSizeY = 1;
    s32 currRoomId = 0;
    s32 x, y;

    listX[0] = 2;
    listX[1] = 28;
    listX[2] = 54;
    listY[0] = 2;
    listY[1] = 30;
    InitDungeonGrid(grid, gridSizeX, gridSizeY);

    for (y = 0; y < gridSizeY; y++) {
        for (x = 0; x < gridSizeX; x++) {
            s32 currX, currY;
            s32 minX = listX[x] + 1;
            s32 minY = listY[y] + 1;
            s32 rangeX = listX[x + 1] - listX[x] - 3;
            s32 rangeY = listY[y + 1] - listY[y] - 3;
            s32 roomSizeX = DungeonRandRange(10, rangeX);
            s32 roomSizeY = DungeonRandRange(16, rangeY);
            s32 startX = DungeonRandInt(rangeX - roomSizeX) + minX;
            s32 startY = DungeonRandInt(rangeY - roomSizeY) + minY;
            s32 endX = startX + roomSizeX;
            s32 endY = startY + roomSizeY;

            grid[x][y].isRoom = TRUE;
            grid[x][y].start.x = startX;
            grid[x][y].end.x = endX;
            grid[x][y].start.y = startY;
            grid[x][y].end.y = endY;

            for (currX = startX; currX < endX; currX++) {
                for (currY = startY; currY < endY; currY++) {
                    SetTerrainNormal(GetTileMut(currX, currY));
                    GetTileMut(currX, currY)->room = currRoomId;
                }
            }
            currRoomId++;
        }
    }

    grid[0][0].connectedToRight = TRUE;
	grid[1][0].connectedToLeft = TRUE;

	CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, FALSE);
	GenerateMonsterHouse(grid, gridSizeX, gridSizeY, 999);
}

/*
 * GenerateExtraHallways - Generate extra hallways on the floor via a series of random walks.
 *
 * These paths are often visibly dead-end hallways, or hallways which loop on themselves.
 *
 * Each walk begin at a random tile in a random room, leaving in a random cardinal direction, tunneling
 * through obstacles until it reaches open terrain, is out of bounds, or reaches an impassable obstruction.
 *
 * For each hallway the following steps are done:
 *
 * 1. Select a room, tile, and cardinal direction (specific conditions documented below)
 *
 * 2. Walk from the tile in that direction until we are out of the room, and reach an obstacle (could traverse hallways on the way)
 *
 * 3. Check we're safe to proceed (not at map borders, counterclockwise/clockwise tiles are not open)
 *
 * Begin our random-length walk strides:
 *
 * 4. Check we're safe to proceed (not at borders, not open tile, not impassable wall, will not make a 2x2 open square)
 *
 * 5. Place Open Terrain at this tile
 *
 * 6. Check we're safe to proceed (counterclockwise/clockwise tiles are not open)
 *
 * 7. Check if we've reached the end of the current stride (steps at 0), if so, turn left or right at random and start a new stride.
 *
 * 8. Move in the current direction.
 *
 * Repeat 4-8 until a check fails.
 */
static void GenerateExtraHallways(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 numExtraHallways)
{
    s32 i, j;

    if (numExtraHallways == 0)
        return;

	for (i = 0; i < numExtraHallways; i++) {
        s32 currX, currY;
        s32 direction;
        u8 roomId;
        bool8 invalid;
	    s32 checkX, checkY, checkX2, checkY2;
        s32 xLoop, yLoop;
		// Select a random grid cell
		s32 x = DungeonRandInt(gridSizeX);
		s32 y = DungeonRandInt(gridSizeY);

		// To generate extra hallways the cell must be:
		// - a room
		// - connected
		// - valid
		// - not a maze room
		if (!grid[x][y].isRoom || !grid[x][y].isConnected || grid[x][y].isInvalid || grid[x][y].isMazeRoom) continue;

		// Choose a random tile in the room
        currX = DungeonRandRange(grid[x][y].start.x, grid[x][y].end.x);
        currY = DungeonRandRange(grid[x][y].start.y, grid[x][y].end.y);

		// Choose a random cardinal direction
        direction = DungeonRandInt(4) * 2;

		// If invalid, rotate counter-clockwise until one works
		for (j = 0; j < 3; j++) {
            if (direction == DIRECTION_SOUTH && y >= gridSizeY - 1) {
            	direction = DIRECTION_EAST;
            }

            if (direction == DIRECTION_EAST && x >= gridSizeX - 1) {
            	direction = DIRECTION_NORTH;
            }

            if (direction == DIRECTION_NORTH && y <= 0) {
            	direction = DIRECTION_WEST;
            }

            if (direction == DIRECTION_WEST && x <= 0) {
            	direction = DIRECTION_SOUTH;
            }
		}

        roomId = GetTile(currX, currY)->room;
		// Walk in the random direction until out of the room
		while (1) {
            if (roomId != GetTile(currX, currY)->room)
                break;
            // gAdjacentTileOffsets gives us the proper (x,y) offset to move one tile in the given direction.
            currX += gAdjacentTileOffsets[direction].x;
            currY += gAdjacentTileOffsets[direction].y;
		}

		// Keep walking until an obstacle is encountered
		while (1) {
            if (GetTerrainType(GetTile(currX, currY)) != TERRAIN_TYPE_NORMAL)
                break;

            currX += gAdjacentTileOffsets[direction].x;
            currY += gAdjacentTileOffsets[direction].y;
		}

		// Abort if we reached secondary terrain
		if (GetTerrainType(GetTile(currX, currY)) == TERRAIN_TYPE_SECONDARY)
            continue;

		// Check that the current tile is at least 2 away from the map border
        invalid = FALSE;
		for (xLoop = currX - 2; xLoop <= currX + 2; xLoop++) {
            for (yLoop = currY - 2; yLoop <= currY + 2; yLoop++) {
            	if (xLoop < 0 || xLoop >= DUNGEON_MAX_SIZE_X || yLoop < 0 || yLoop >= DUNGEON_MAX_SIZE_Y) {
            		invalid = TRUE;
            		break;
            	}
            }

            if (invalid) break;
		}

		if (invalid) continue;

		// Make sure the direction 90 degrees counterclockwise isn't an open tile
		checkX = gAdjacentTileOffsets[(direction + 2) & DIRECTION_MASK_CARDINAL].x;
		checkY = gAdjacentTileOffsets[(direction + 2) & DIRECTION_MASK_CARDINAL].y;
		if (GetTerrainType(GetTile(currX + checkX, currY + checkY)) == TERRAIN_TYPE_NORMAL)
            continue;

		// Do the same for 90 degrees clockwise (or 270 counterclockwise) and make sure it's not an open tile
		checkX2 = gAdjacentTileOffsets[(direction - 2) & DIRECTION_MASK_CARDINAL].x;
		checkY2 = gAdjacentTileOffsets[(direction - 2) & DIRECTION_MASK_CARDINAL].y;
		if (GetTerrainType(GetTile(currX + checkX2, currY + checkY2)) == TERRAIN_TYPE_NORMAL)
            continue;

		// Number of steps to walk in one direction before turning
        j = DungeonRandInt(3) + 3;
		while (TRUE) {
            s32 checkX, checkY, checkX2, checkY2;
            bool8 willNotMakeSquare;
            // Check for stopping conditions:
            // - Out of bounds or on the 1-tile border of impassable walls
            // - Reached an open tile
            // - Reached an impassable wall
            // - Would result in carving out a 2x2 square (not a hallway at that point)

            if (currX <= 1 || currY <= 1 || currX >= DUNGEON_MAX_SIZE_X - 1 || currY >= DUNGEON_MAX_SIZE_Y - 1)
                break;
            if (GetTerrainType(GetTile(currX, currY)) == TERRAIN_TYPE_NORMAL)
                break;
            if (GetTile(currX, currY)->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
                break;

            willNotMakeSquare = TRUE;

            // Check Bottom to Right
            if ((GetTerrainType(GetTile(currX + 1, currY)) == TERRAIN_TYPE_NORMAL) &&
                (GetTerrainType(GetTile(currX + 1, currY + 1)) == TERRAIN_TYPE_NORMAL) &&
            	(GetTerrainType(GetTile(currX, currY + 1)) == TERRAIN_TYPE_NORMAL))
            {
            	willNotMakeSquare = FALSE;
            }

            // Check Top to Right
            if ((GetTerrainType(GetTile(currX + 1, currY)) == TERRAIN_TYPE_NORMAL) &&
            	(GetTerrainType(GetTile(currX + 1, currY - 1)) == TERRAIN_TYPE_NORMAL) &&
            	(GetTerrainType(GetTile(currX, currY - 1)) == TERRAIN_TYPE_NORMAL))
            {
            	willNotMakeSquare = FALSE;
            }

            // Check Bottom to Left
            if ((GetTerrainType(GetTile(currX - 1, currY)) == TERRAIN_TYPE_NORMAL) &&
            	(GetTerrainType(GetTile(currX - 1, currY + 1)) == TERRAIN_TYPE_NORMAL) &&
            	(GetTerrainType(GetTile(currX, currY + 1)) == TERRAIN_TYPE_NORMAL))
            {
            	willNotMakeSquare = FALSE;
            }

            // Check Top to Left
            if ((GetTerrainType(GetTile(currX - 1, currY)) == TERRAIN_TYPE_NORMAL) &&
            	(GetTerrainType(GetTile(currX - 1, currY - 1)) == TERRAIN_TYPE_NORMAL) &&
            	(GetTerrainType(GetTile(currX, currY - 1)) == TERRAIN_TYPE_NORMAL))
            {
            	willNotMakeSquare = FALSE;
            }

            // If TRUE, make the tile open, it will not produce a 2x2 opening
            // If FALSE, it will abort from neighbor checks so we don't break here
            if (willNotMakeSquare) {
                SetTerrainNormal(GetTileMut(currX, currY));
            }

            // Make sure the direction 90 degrees counterclockwise isn't an open tile
            checkX = gAdjacentTileOffsets[(direction + 2) & DIRECTION_MASK_CARDINAL].x;
            checkY = gAdjacentTileOffsets[(direction + 2) & DIRECTION_MASK_CARDINAL].y;
            if (GetTerrainType(GetTile(currX + checkX, currY + checkY)) == TERRAIN_TYPE_NORMAL)
                break;

            // Do the same for 90 degrees clockwise (or 270 counterclockwise) and make sure it's not an open tile
            checkX2 = gAdjacentTileOffsets[(direction - 2) & DIRECTION_MASK_CARDINAL].x;
            checkY2 = gAdjacentTileOffsets[(direction - 2) & DIRECTION_MASK_CARDINAL].y;
            if (GetTerrainType(GetTile(currX + checkX2, currY + checkY2)) == TERRAIN_TYPE_NORMAL)
                break;

            j--;
            if (j == 0) {
            	j = DungeonRandInt(3) + 3;

            	// Turn left or right with an equal chance
            	if (DungeonRandInt(100) < 50) {
            		direction += 2;
            	}
                else {
            		direction -= 2;
            	}

            	// If we'd step into an invalid grid cell, stop
            	// (We don't always utilize the entire floor space)
            	direction &= DIRECTION_MASK_CARDINAL;
            	if (currX >= 32 && sFloorSize == FLOOR_SIZE_SMALL && direction == DIRECTION_EAST) break;
            	if (currX >= 48 && sFloorSize == FLOOR_SIZE_MEDIUM && direction == DIRECTION_EAST) break;
            }

            // Move in the current direction
            currX += gAdjacentTileOffsets[direction].x;
            currY += gAdjacentTileOffsets[direction].y;
		}
	}
}

// GetGridPositions - Determines the starting positions of grid cells based on the given floor grid dimensions
static void GetGridPositions(s32 *listX, s32 *listY, s32 gridSizeX, s32 gridSizeY)
{
    s32 i, sum;

    for (i = 0, sum = 0; i < gridSizeX; i++) {
        listX[i] = sum;
        sum += DUNGEON_MAX_SIZE_X / gridSizeX;
    }
    listX[gridSizeX] = sum;

    for (i = 0, sum = 0; i < gridSizeY; i++) {
        listY[i] = sum;
        sum += DUNGEON_MAX_SIZE_Y / gridSizeY;
    }
    listY[gridSizeY] = sum;
}

/*
 * InitDungeonGrid - Initializes the default state of the dungeon grid
 *
 * The dungeon grid is an array of grid cells stored in column-major order
 * (to give contiguous storage to cells with the same x value), with a fixed column size of 15.
 */
static void InitDungeonGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY)
{
    s32 x, y;

    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            if (sFloorSize == 1 && x >= gridSizeX / 2) {
                grid[x][y].isInvalid = TRUE;
            }
            else if (sFloorSize == 2 && x >= (gridSizeX * 3) / 4) {
                grid[x][y].isInvalid = TRUE;
            }
            else {
                grid[x][y].isInvalid = FALSE;
            }

            grid[x][y].isRoom = TRUE;
            grid[x][y].isConnected = FALSE;
            grid[x][y].unk15 = FALSE;
            grid[x][y].isMonsterHouse = FALSE;
            grid[x][y].isKecleonShop = FALSE;
            grid[x][y].connectedToRight = FALSE;
            grid[x][y].connectedToLeft = FALSE;
            grid[x][y].connectedToBottom = FALSE;
            grid[x][y].connectedToTop = FALSE;
            grid[x][y].shouldConnectToRight = FALSE;
            grid[x][y].shouldConnectToLeft = FALSE;
            grid[x][y].shouldConnectToBottom = FALSE;
            grid[x][y].shouldConnectToTop = FALSE;
            grid[x][y].hasSecondaryStructure = FALSE;
            grid[x][y].hasBeenMerged = FALSE;
            grid[x][y].isMazeRoom = FALSE;
            grid[x][y].isMerged = FALSE;
            grid[x][y].flagImperfect = FALSE;
            grid[x][y].flagSecondaryStructure = FALSE;
        }
    }
}

/*
 * AssignRooms - Randomly selects a subset of grid cells to become rooms
 *
 * If number_of_rooms is positive, number_of_rooms + [0..2] will become rooms
 * If the selected cells for rooms are invalid, less rooms will be generated.
 * The number of rooms assigned will always be at least 2 and always <= MAX_ROOM_COUNT (32).
 *
 * Any cells which aren't marked as rooms will become hallway anchors (those single 1x1 "rooms")
 * which will be connected as hallways later, to "anchor" hallway generation
 *
 * Primarily Modifies: grid to assign certain grid cells to have isRoom TRUE.
 */

#define ROOM_BITS_COUNT 256 // Despite max rooms being 32, randomRoomBits can hold up to 256 possible rooms
static void AssignRooms(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 roomsNumber)
{
    bool8 randomRoomBits[ROOM_BITS_COUNT];
    s32 i, nShuffles;
    s32 x, y;
    s32 attempts;
    s32 maxRooms;
    // Extra Rooms
    i = DungeonRandInt(3);

	// A negative # for room count requests an exact number of rooms
	if (roomsNumber < 0) {
		roomsNumber = -roomsNumber;
	}
	else {
		roomsNumber += i;
	}

	for (i = 0; i < roomsNumber; i++) {
		randomRoomBits[i] = TRUE;
	}
    for (; i < ROOM_BITS_COUNT; i++) {
        randomRoomBits[i] = FALSE;
    }

	// Shuffle around the acceptable rooms
    maxRooms = gridSizeX * gridSizeY;

	for (nShuffles = 0; nShuffles < 64; nShuffles++) {
        bool8 temp;
		s32 a = DungeonRandInt(maxRooms);
		s32 b = DungeonRandInt(maxRooms);

		SWAP(randomRoomBits[a], randomRoomBits[b], temp);
	}

    // Counter for randomRoomBits
    i = 0;
    sNumRooms = 0;
	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
            if (grid[x][y].isInvalid)
                continue;

            // There are too many rooms, remove
            if (sNumRooms >= MAX_ROOM_COUNT) {
            	grid[x][y].isRoom = FALSE;
            }

            // Using the randomly shuffled bits, create or remove the room
            if (randomRoomBits[i]) {
            	grid[x][y].isRoom = TRUE;
            	sNumRooms++;

            	// Don't make a room at (x_mid, 1)
            	if (gridSizeX % 2 != 0 && x == (gridSizeX - 1) / 2 && y == 1 ) {
            		grid[x][y].isRoom = FALSE;
            	}
            }
            else {
            	grid[x][y].isRoom = FALSE;
            }

            i++;
		}
	}

	// We have at least 2 rooms, we're done.
	if (sNumRooms >= 2)
        return;

	for (attempts = 0; attempts < 200; attempts++) {
        bool8 enoughRooms = FALSE;
		for (x = 0; x < gridSizeX; x++) {
            for (y = 0; y < gridSizeY; y++) {
            	if (grid[x][y].isInvalid)
                    continue;

            	if (DungeonRandInt(100) < 60) {
            		grid[x][y].isRoom = TRUE;
            		enoughRooms = TRUE;
                    // This goto is needed to match, it's used to break from two nested loops.
                    goto LOOP_BREAK;
            	}
            }
		}
        LOOP_BREAK:
        if (enoughRooms)
            break;
	}

	sSecondSpawn = FALSE;
}

/*
 * CreateRoomsAndAnchors - Creates the rectangle regions of open terrain for each room
 * leaving a margin relative to the border
 *
 * If the room is an anchor, a single tile is placed with a hallway indicator for later.
 */
static void CreateRoomsAndAnchors(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, u32 roomFlags)
{
    s32 roomNumber = 0;
    s32 x, y;

	for (y = 0; y < gridSizeY; y++) {
		for (x = 0; x < gridSizeX; x++) {
            s32 minX = listX[x] + 2;
            s32 minY = listY[y] + 2;
            s32 rangeX = listX[x + 1] - listX[x] - 4;
            s32 rangeY = listY[y + 1] - listY[y] - 3;

            if (grid[x][y].isInvalid) continue;

            if (grid[x][y].isRoom) {
                // This cell is a room!
                s32 roomSizeX, roomSizeY;
                s32 startX, endX;
                s32 startY, endY;
                s32 roomX, roomY;
                bool8 flagSecondary, flagImperfect;

                roomSizeX = DungeonRandRange(5, rangeX);
                roomSizeY = DungeonRandRange(4, rangeY);

            	// Force small rooms to have odd-numbered dimensions (?)
            	if ((roomSizeX | 1) < rangeX) {
            		roomSizeX |= 1;
            	}

            	if ((roomSizeY | 1) < rangeY) {
            		roomSizeY |= 1;
            	}

            	// Aspect ratio 2/3 < x/y < 3/2
            	if (roomSizeX > (roomSizeY * 3) / 2) {
            		roomSizeX = (roomSizeY * 3) / 2;
            	}

            	if (roomSizeY > (roomSizeX * 3) / 2) {
            		roomSizeY = (roomSizeX * 3) / 2;
            	}

                startX = DungeonRandInt(rangeX - roomSizeX) + minX;
                startY = DungeonRandInt(rangeY - roomSizeY) + minY;
                endX = startX + roomSizeX;
                endY = startY + roomSizeY;

            	// Create the room!
            	grid[x][y].start.x = startX;
                grid[x][y].end.x = endX;
            	grid[x][y].start.y = startY;
            	grid[x][y].end.y = endY;

            	for (roomX = startX; roomX < endX; roomX++) {
            		for (roomY = startY; roomY < endY; roomY++) {
                        SetTerrainNormal(GetTileMut(roomX, roomY));
                        GetTileMut(roomX, roomY)->room = roomNumber;
            		}
            	}

                flagImperfect = TRUE;
            	// Randomly flag the room for a secondary structure
                flagSecondary = DungeonRandInt(100) < GENERATION_CONSTANT_SECONDARY_STRUCTURE_FLAG_CHANCE;
            	if (sSecondaryStructuresBudget == 0) {
            		flagSecondary = FALSE;
            	}

            	// Flag for imperfections if needed
                if (!(roomFlags & ROOM_FLAG_ALLOW_IMPERFECTIONS)) {
                    flagImperfect = FALSE;
                }

            	if (flagImperfect && flagSecondary) {
            		// If a room gets both, pick one at random
            		if (DungeonRandInt(100) < 50) {
                        flagImperfect = FALSE;
            		}
            		else {
                        flagSecondary = FALSE;
            		}
            	}

            	if (flagImperfect) {
            		grid[x][y].flagImperfect = TRUE;
            	}

            	if (flagSecondary) {
            		grid[x][y].flagSecondaryStructure = TRUE;
            	}

            	roomNumber++;
            }
            else {
                // This cell is not a room, create a 1x1 hallway anchor
                s32 pt_x, pt_y;
                s32 unk_x1 = 2;
                s32 unk_x2 = 4;
                s32 unk_y1 = 2;
                s32 unk_y2 = 4;

            	if (x == 0) {
            		unk_x1 = 1;
            	}
            	if (y == 0) {
            		unk_y1 = 1;
            	}

                if (x == gridSizeX - 1) {
            		unk_x2 = 2;
            	}
            	if (y == gridSizeY - 1) {
            		unk_y2 = 2;
            	}

                pt_x = DungeonRandRange(minX + unk_x1, minX + rangeX - unk_x2);
                pt_y = DungeonRandRange(minY + unk_y1, minY + rangeY - unk_y2);

            	grid[x][y].start.x = pt_x;
                grid[x][y].end.x = pt_x + 1;
            	grid[x][y].start.y = pt_y;
            	grid[x][y].end.y = pt_y + 1;

            	// Flag the tile as open to serve as a hallway anchor
            	SetTerrainNormal(GetTileMut(pt_x, pt_y));

            	// Set the room index to 0xFE for anchor
            	GetTileMut(pt_x, pt_y)->room = ROOM_0xFE;
            }
		}
	}
}

/*
 * GenerateSecondaryStructures - Attempt to generate secondary structures in flagged rooms.
 *
 * For a valid flagged room with no extra features, one of the following will attempt to generate:
 * 0. No Secondary Structure
 * 1. A maze (made of water/lava walls), or a "plus" sign fallback, or a single dot in the center fallback
 * 2. Checkerboard pattern of water/lava
 * 3. A central pool in the room made of water/lava
 * 4. A central island with items and a warp tile, surrounded by water/lava
 * 5. A horizontal or vertical line of water/lava splitting the room in two.
 *
 * If a room doesn't meet the conditions for the secondary structure chosen, it will be left unchanged.
 */
static void GenerateSecondaryStructures(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY)
{
    s32 x, y;

    for (y = 0; y < gridSizeY; y++) {
        for (x = 0; x < gridSizeX; x++) {
            // To have a secondary structure a room must be:
            // - valid
            // - not a monster house, merged, or have imperfections
            // - be a room
            // - be flagged for a secondary structure
            if (!grid[x][y].isInvalid &&
            	!grid[x][y].isMonsterHouse &&
            	!grid[x][y].isMerged &&
            	grid[x][y].isRoom &&
                !grid[x][y].flagImperfect &&
            	grid[x][y].flagSecondaryStructure)
            {
                GenerateSecondaryStructure(&grid[x][y]);
            }
        }
    }
}

static void AssignRandomGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, FloorProperties *floorProps)
{
    s32 cursorX = DungeonRandInt(gridSizeX);
    s32 cursorY = DungeonRandInt(gridSizeY);

    AssignGridCellConnections(grid, gridSizeX, gridSizeY, cursorX, cursorY, floorProps);
}

/*
 * AssignGridCellConnections - Responsible for assigning connections to randomly adjacent grid cells
 *
 * Connections begin from the grid cell at (cursorX, cursorY), and are created using a
 * random walk with momentum.
 *
 * There's a 50% chance it will continue in the same direction, otherwise it will be assigned a new random direction.
 * If the direction traveled runs into the border of the map, the direction turns counterclockwise.
 * If the direction walks towards an invalid grid tile, nothing happens and iteration continues.
 *
 * The random walk will be repeated floorConnectivity number of times (specified in FloorProperties)
 *
 * Once finished, if dead ends are disabled, an additional phase occurs to remove dead end hallway anchors (not rooms)
 * The original implementation contains a bug when applying new connections to these rooms, where the incorrect
 * grid cell index will be checked for validity (always the grid cell to the right), so some connections may go to
 * invalid tiles or not be applied to valid ones.
 *
 */

static void AssignGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 cursorX, s32 cursorY, FloorProperties *floorProps)
{
	s32 i;
    s32 x = cursorX;
    s32 y = cursorY;
	s32 floorConnectivity = floorProps->floorConnectivity;
	// Draw a random connection direction.
	// Connect the current cell with the cell to the:
	//	0: east
	// 	1: north
	//	2: west
	// 	3: south
	s32 cardinalDirection = DungeonRandInt(NUM_CARDINAL_DIRECTIONS);

	// Try to connect the current cell to another grid cell, repeat based on floorConnectivity
	for (i = 0; i < floorConnectivity; i++) {
		// Keep moving in the same cardinalDirection with probability 1/2 ("momentum" to connect in a straight line)
		// Less forks and less doubling back
		s32 test = DungeonRandInt(NUM_CARDINAL_DIRECTIONS * 2);
		s32 newDirection = DungeonRandInt(NUM_CARDINAL_DIRECTIONS);

		if (test < NUM_CARDINAL_DIRECTIONS) {
            // Shuffle to a new cardinalDirection
            cardinalDirection = newDirection;
		}

		// Make sure our cardinalDirection isn't going into a border
		// If so, rotate counterclockwise
		while (1) {
            bool8 notOk = FALSE;
            switch (cardinalDirection & CARDINAL_DIRECTION_MASK) {
            	case CARDINAL_DIR_RIGHT:
            		if (x < gridSizeX - 1)
                        notOk = TRUE;
                    else
                        cardinalDirection++;
            		break;
            	case CARDINAL_DIR_UP:
            		if (y > 0)
                        notOk = TRUE;
                    else
                        cardinalDirection++;
            		break;
            	case CARDINAL_DIR_LEFT:
            		if (x > 0)
                        notOk = TRUE;
                    else
                        cardinalDirection++;
            		break;
            	case CARDINAL_DIR_DOWN:
            		if (y < gridSizeY - 1)
                        notOk = TRUE;
                    else
                        cardinalDirection++;
            		break;
            }

            if (notOk)
                break;
		}

		// Set the connection, then move in that cardinalDirection
		switch (cardinalDirection & CARDINAL_DIRECTION_MASK) {
		    case CARDINAL_DIR_RIGHT:
		        if (!grid[x + 1][y].isInvalid) {
                    grid[x][y].connectedToRight = TRUE;
                    grid[x + 1][y].connectedToLeft = TRUE;

                    x++;
		        }
                break;
            case CARDINAL_DIR_UP:
                if (!grid[x][y - 1].isInvalid) {
                    grid[x][y].connectedToTop = TRUE;
                    grid[x][y - 1].connectedToBottom = TRUE;

                    y--;
                }
                break;
            case CARDINAL_DIR_LEFT:
                if (!grid[x - 1][y].isInvalid) {
                    grid[x][y].connectedToLeft = TRUE;
                    grid[x - 1][y].connectedToRight = TRUE;

                    x--;
                }
                break;
            case CARDINAL_DIR_DOWN:
                if (!grid[x][y + 1].isInvalid) {
                    grid[x][y].connectedToBottom = TRUE;
                    grid[x][y + 1].connectedToTop = TRUE;

                    y++;
                }
                break;
		}
	}

	if (floorProps->allowDeadEnds)
        return;

    // No dead ends, add some extra connections!
    while (1) {
        bool8 more = FALSE;

        // Locate potential dead ends
        for (x = 0; x < gridSizeX; x++) {
            for (y = 0; y < gridSizeY; y++) {
                if (grid[x][y].isInvalid)
                    continue;
                if (!grid[x][y].isRoom)
                {
                    // Find which cardinalDirections this tile is connected in
                    s32 countConnect = 0;

                    if (grid[x][y].connectedToTop) countConnect++;
                    if (grid[x][y].connectedToBottom) countConnect++;
                    if (grid[x][y].connectedToLeft) countConnect++;
                    if (grid[x][y].connectedToRight) countConnect++;

                    if (countConnect == 1) {
                        s32 i;
                        bool8 ok;

                        // This tile has only one connection, it's a dead end
                        // Connect it to a random other cell to remove the dead end

                        cardinalDirection = DungeonRandInt(NUM_CARDINAL_DIRECTIONS);

                        for (i = 0, ok = FALSE; i < 8; i++) {
                            switch (cardinalDirection & CARDINAL_DIRECTION_MASK) {
                                case CARDINAL_DIR_RIGHT:
                                    if (x < gridSizeX - 1 && !grid[x][y].connectedToRight)
                                        ok = TRUE;
                                    else
                                        cardinalDirection++;
                                    break;
                                case CARDINAL_DIR_UP:
                                    if (y > 0 && !grid[x][y].connectedToTop)
                                        ok = TRUE;
                                    else
                                        cardinalDirection++;
                                    break;
                                case CARDINAL_DIR_LEFT:
                                    if (x > 0 && !grid[x][y].connectedToLeft)
                                        ok = TRUE;
                                    else
                                        cardinalDirection++;
                                    break;
                                case CARDINAL_DIR_DOWN:
                                    if (y < gridSizeY - 1 && !grid[x][y].connectedToBottom)
                                        ok = TRUE;
                                    else
                                        cardinalDirection++;
                                    break;
                            }

                            // Once we find a successful cardinalDirection, stop
                            if (ok)
                                break;
                        }

                        // We couldn't find any successful cardinalDirection, give up.
                        if (!ok)
                            continue;

                        // This section retains the original functionality
                        switch (cardinalDirection & CARDINAL_DIRECTION_MASK) {
                            case CARDINAL_DIR_RIGHT:
                                if (!grid[x + 1][y].isInvalid) {
                                    grid[x][y].connectedToRight = TRUE;
                                    grid[x + 1][y].connectedToLeft = TRUE;

                                    more = TRUE;
                                }
                                break;
                            // BUG: the wrong grid index is used for the validity check
                            case CARDINAL_DIR_UP:
                                if (!grid[x + 1][y].isInvalid) {
                                    grid[x][y].connectedToTop = TRUE;
                                    grid[x][y - 1].connectedToBottom = TRUE;

                                    more = TRUE;
                                }
                                break;
                            // BUG: the wrong grid index is used for the validity check
                            case CARDINAL_DIR_LEFT:
                                if (!grid[x + 1][y].isInvalid) {
                                    grid[x][y].connectedToLeft = TRUE;
                                    grid[x - 1][y].connectedToRight = TRUE;

                                    more = TRUE;
                                }
                                break;
                            // BUG: the wrong grid index is used for the validity check
                            case CARDINAL_DIR_DOWN:
                                if (!grid[x + 1][y].isInvalid) {
                                    grid[x][y].connectedToBottom = TRUE;
                                    grid[x][y + 1].connectedToTop = TRUE;

                                    more = TRUE;
                                }
                                break;
                        }
                    }
                }
            }
        }

        if (!more)
            break;
    }
}

/*
 * CreateGridCellConnections - Creates connections through generating hallways and merging rooms
 *
 * First, connection links are copied over to a work array for managing hallway generation.
 *
 * Then, for each connection specified between two cells, a hallway is generated based on the following:
 * 	- If the cell is a hallway anchor, the hallway is generated based on the exact point of the anchor tile
 * 	- If the cell is a room, the hallway is generated based on a random interior point inside the room
 *
 * See: CreateHallway for how these points generate the hallway path
 *
 * Finally, if room merging is enabled there is a 9.75% chance that two connected rooms will be merged
 * into a single larger room. (9.75% comes from two 5% rolls, one for each of the two rooms being merged)
 * A room can only participate in a merge once.
 *
 * Merged rooms take up the full tile space occupied between the two rooms.
 *
 */
static void CreateGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, bool8 disableRoomMerging)
{
    s32 x, y;

    // Validate and copy grid connections over to a work array
    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            if (grid[x][y].isInvalid) {
                // For invalid cells, assign no connections

            	grid[x][y].shouldConnectToTop = FALSE;
            	grid[x][y].shouldConnectToBottom = FALSE;
            	grid[x][y].shouldConnectToLeft = FALSE;
            	grid[x][y].shouldConnectToRight = FALSE;
            }
            else {
            	// For valid cells, remove cell connections beyond the grid bounds
            	if (x <= 0) {
            		grid[x][y].connectedToLeft = FALSE;
            	}

            	if (y <= 0) {
            		grid[x][y].connectedToTop = FALSE;
            	}

            	if (x >= gridSizeX - 1) {
            		grid[x][y].connectedToRight = FALSE;
            	}

            	if (y >= gridSizeY - 1) {
            		grid[x][y].connectedToBottom = FALSE;
            	}

            	// Assign the connections
            	grid[x][y].shouldConnectToTop = grid[x][y].connectedToTop;
            	grid[x][y].shouldConnectToBottom = grid[x][y].connectedToBottom;
            	grid[x][y].shouldConnectToLeft = grid[x][y].connectedToLeft;
            	grid[x][y].shouldConnectToRight = grid[x][y].connectedToRight;
            }
		}
	}

	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
		    s32 pt_x, pt_y, pt2_x, pt2_y;

            if (grid[x][y].isInvalid)
                continue;

            if (grid[x][y].isRoom) {
            	// Room, pick a random point in the interior of the room
            	pt_x = DungeonRandRange(grid[x][y].start.x + 1, grid[x][y].end.x - 1);
            	pt_y = DungeonRandRange(grid[x][y].start.y + 1, grid[x][y].end.y - 1);
            }
            else {
                // Hallway anchor, point is the 1x1 we've placed
            	pt_x = grid[x][y].start.x;
            	pt_y = grid[x][y].start.y;
            }

            if (grid[x][y].shouldConnectToTop) {
            	// Connect to the cell above
            	if (!grid[x][y - 1].isInvalid) {
            		if (grid[x][y - 1].isRoom) {
                        // Room, pick a random interior x coordinate
                        pt2_x = DungeonRandRange(grid[x][y - 1].start.x + 1, grid[x][y - 1].end.x - 1);
            		}
            		else {
                        // Anchor, use the central x coordinate
                        pt2_x = grid[x][y - 1].start.x;
            		}

            		// Create the hallway
            		CreateHallway(pt_x, grid[x][y].start.y, pt2_x, grid[x][y - 1].end.y - 1, TRUE, listX[x], listY[y]);
            	}

            	// Mark the connection and unassign it so we don't try to draw
            	// a second connection from the other way

            	grid[x][y].shouldConnectToTop = FALSE;
            	grid[x][y - 1].shouldConnectToBottom = FALSE;
            	grid[x][y].isConnected = TRUE;
            	grid[x][y - 1].isConnected = TRUE;
            }

            if (grid[x][y].shouldConnectToBottom) {
            	// Connect to the cell below
            	if (!grid[x][y + 1].isInvalid) {
            		if (grid[x][y + 1].isRoom) {
                        // Room, pick a random interior x coordinate
                        pt2_x = DungeonRandRange(grid[x][y + 1].start.x + 1, grid[x][y + 1].end.x - 1);
            		}
            		else {
                        // Anchor, use the central x coordinate
                        pt2_x = grid[x][y + 1].start.x;
            		}

            		// Create the hallway
            		CreateHallway(pt_x, grid[x][y].end.y - 1, pt2_x, grid[x][y + 1].start.y, TRUE, listX[x], listY[y + 1] - 1);
            	}

            	// Mark the connection and unassign it so we don't try to draw
            	// a second connection from the other way

            	grid[x][y].shouldConnectToBottom = FALSE;
            	grid[x][y + 1].shouldConnectToTop = FALSE;
            	grid[x][y].isConnected = TRUE;
            	grid[x][y + 1].isConnected = TRUE;
            }

            if (grid[x][y].shouldConnectToLeft) {
            	// Connect to the cell on the left
            	if (!grid[x - 1][y].isInvalid) {
            		if (grid[x - 1][y].isRoom) {
                        // Room, pick a random interior y coordinate
                        pt2_y = DungeonRandRange(grid[x - 1][y].start.y + 1, grid[x - 1][y].end.y - 1);
            		}
            		else {
                        // Anchor, use the central y coordinate
                        pt2_y = grid[x - 1][y].start.y;
            		}

            		// Create the hallway
            		// Using (grid[x-1][y].start.x - 1) is a bug, it should be (grid[x-1][y].end.x - 1)
            		// But CreateHallway has safety checks making the end result the same anyways.
            		CreateHallway(grid[x][y].start.x, pt_y, grid[x - 1][y].start.x - 1, pt2_y, FALSE, listX[x], listY[y]);
            	}

            	// Mark the connection and unassign it so we don't try to draw
            	// a second connection from the other way

            	grid[x][y].shouldConnectToLeft = FALSE;
            	grid[x - 1][y].shouldConnectToRight = FALSE;
            	grid[x][y].isConnected = TRUE;
            	grid[x - 1][y].isConnected = TRUE;
            }

            if (grid[x][y].shouldConnectToRight) {
            	// Connect to the cell on the right
            	if (!grid[x + 1][y].isInvalid) {
            		if (grid[x + 1][y].isRoom) {
                        // Room, pick a random interior y coordinate
                        pt2_y = DungeonRandRange(grid[x + 1][y].start.y + 1, grid[x + 1][y].end.y - 1);
            		}
            		else {
                        // Anchor, use the central y coordinate
                        pt2_y = grid[x + 1][y].start.y;
            		}

            		// Create the hallway
            		CreateHallway(grid[x][y].end.x - 1, pt_y, grid[x + 1][y].start.x, pt2_y, FALSE, listX[x + 1] - 1, listY[y]);
            	}

            	// Mark the connection and unassign it so we don't try to draw
            	// a second connection from the other way

            	grid[x][y].shouldConnectToRight = FALSE;
            	grid[x + 1][y].shouldConnectToLeft = FALSE;
            	grid[x][y].isConnected = TRUE;
            	grid[x + 1][y].isConnected = TRUE;
            }
		}
	}

	// If we don't want to merge rooms, we're done
	if (disableRoomMerging) {
		return;
	}

	// If we do, we can try to merge some!
	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
            s32 chance = DungeonRandInt(100);

            // Conditions for merging a room:
            // - rolls for merge chance
            // - valid
            // - connected to another room
            // - not already merged
            // - not have a secondary structure
            // - is a room, not an anchor
            if (chance < GENERATION_CONSTANT_MERGE_ROOMS_CHANCE &&
            	!grid[x][y].isInvalid &&
            	grid[x][y].isConnected &&
            	!grid[x][y].isMerged &&
            	!grid[x][y].hasSecondaryStructure &&
            	grid[x][y].isRoom)
            {
            	s32 chanceTwo = DungeonRandInt(4);

            	// Verify the same for the target room
            	switch (chanceTwo) {
                    case 0:
                        if (x > 0 &&
                            grid[x - 1][y].isConnected &&
                            !grid[x - 1][y].isInvalid &&
                            grid[x - 1][y].isRoom &&
                            !grid[x - 1][y].hasSecondaryStructure &&
                            !grid[x - 1][y].isMerged)
                        {
                            // Merge with the room to the left
                            s32 curX, curY;
                            s32 srcX = grid[x - 1][y].start.x;
                            s32 srcY = min(grid[x - 1][y].start.y, grid[x][y].start.y);
                            s32 dstX = grid[x][y].end.x;
                            s32 dstY = max(grid[x - 1][y].end.y, grid[x][y].end.y);

                            // Use the original room's index
                            s32 mergeRoomIndex = GetTile(grid[x][y].start.x, grid[x][y].start.y)->room;

                            // Carve out the merged room
                            for (curX = srcX; curX < dstX; curX++) {
                                for (curY = srcY; curY < dstY; curY++) {
                                    Tile *tile = GetTileMut(curX, curY);

                                    SetTerrainNormal(tile);
                                    tile->room = mergeRoomIndex;
                                }
                            }

                            // Update room boundaries
                            grid[x - 1][y].start.x = srcX;
                            grid[x - 1][y].end.x = dstX;
                            grid[x - 1][y].start.y = srcY;
                            grid[x - 1][y].end.y = dstY;

                            // Mark merge flags on both rooms
                            grid[x][y].isMerged = TRUE;
                            grid[x - 1][y].isMerged = TRUE;
                            grid[x][y].isConnected = FALSE;
                            grid[x][y].hasBeenMerged = TRUE;
                        }
                        break;
                    case 1:
                        if (y >= 1 &&
                            grid[x][y - 1].isConnected &&
                            !grid[x][y - 1].isInvalid &&
                            grid[x][y - 1].isRoom &&
                            !grid[x][y - 1].hasSecondaryStructure &&
                            !grid[x][y - 1].isMerged)
                        {
                            // Merge with the room above
                            s32 curX, curY;
                            s32 srcX = min(grid[x][y - 1].start.x, grid[x][y].start.x);
                            s32 srcY = grid[x][y - 1].start.y;
                            s32 dstX = max(grid[x][y - 1].end.x, grid[x][y].end.x);
                            s32 dstY = grid[x][y].end.y;

                            // Use the original room's index
                            s32 mergeRoomIndex = GetTile(grid[x][y].start.x, grid[x][y].start.y)->room;

                            // Carve out the merged room
                            for (curX = srcX; curX < dstX; curX++) {
                                for (curY = srcY; curY < dstY; curY++) {
                                    Tile *tile = GetTileMut(curX, curY);

                                    SetTerrainNormal(tile);
                                    tile->room = mergeRoomIndex;
                                }
                            }

                            // Update room boundaries
                            grid[x][y - 1].start.x = srcX;
                            grid[x][y - 1].end.x = dstX;
                            grid[x][y - 1].start.y = srcY;
                            grid[x][y - 1].end.y = dstY;

                            // Mark merge flags on both rooms
                            grid[x][y].isMerged = TRUE;
                            grid[x][y - 1].isMerged = TRUE;
                            grid[x][y].isConnected = FALSE;
                            grid[x][y].hasBeenMerged = TRUE;
                        }
                        break;
                    case 2:
                        if (x <= gridSizeX - 2 &&
                            grid[x + 1][y].isConnected &&
                            !grid[x + 1][y].isInvalid &&
                             grid[x + 1][y].isRoom &&
                            !grid[x + 1][y].hasSecondaryStructure &&
                            !grid[x + 1][y].isMerged)
                        {
                            // Merge with the room to the right
                            s32 curX, curY;
                            s32 srcX = grid[x][y].start.x;
                            s32 srcY = min(grid[x][y].start.y, grid[x + 1][y].start.y);
                            s32 dstX = grid[x + 1][y].end.x;
                            s32 dstY = max(grid[x][y].end.y, grid[x + 1][y].end.y);

                            // Use the original room's index
                            s32 mergeRoomIndex = GetTile(grid[x][y].start.x, grid[x][y].start.y)->room;

                            // Carve out the merged room
                            for (curX = srcX; curX < dstX; curX++) {
                                for (curY = srcY; curY < dstY; curY++) {
                                    Tile *tile = GetTileMut(curX, curY);

                                    SetTerrainNormal(tile);
                                    tile->room = mergeRoomIndex;
                                }
                            }

                            // Update room boundaries
                            grid[x][y].start.x = srcX;
                            grid[x][y].end.x = dstX;
                            grid[x][y].start.y = srcY;
                            grid[x][y].end.y = dstY;

                            // Mark merge flags on both rooms
                            grid[x + 1][y].isMerged = TRUE;
                            grid[x][y].isMerged = TRUE;
                            grid[x + 1][y].isConnected = FALSE;
                            grid[x + 1][y].hasBeenMerged = TRUE;
                        }
                        break;
                    case 3:
                        if (y <= gridSizeY - 2 &&
                            grid[x][y + 1].isConnected &&
                            !grid[x][y + 1].isInvalid &&
                            grid[x][y + 1].isRoom &&
                            !grid[x][y + 1].hasSecondaryStructure &&
                            !grid[x][y + 1].isMerged)
                        {
                            // Merge with the room below
                            s32 curX, curY;
                            s32 srcX = min(grid[x][y].start.x, grid[x][y + 1].start.x);
                            s32 srcY = grid[x][y].start.y;
                            s32 dstX = max(grid[x][y].end.x, grid[x][y + 1].end.x);
                            s32 dstY = grid[x][y + 1].end.y;

                            // Use the original room's index
                            s32 mergeRoomIndex = GetTile(grid[x][y].start.x, grid[x][y].start.y)->room;

                            // Carve out the merged room
                            for (curX = srcX; curX < dstX; curX++) {
                                for (curY = srcY; curY < dstY; curY++) {
                                    Tile *tile = GetTileMut(curX, curY);

                                    SetTerrainNormal(tile);
                                    tile->room = mergeRoomIndex;
                                }
                            }

                            // Update room boundaries
                            grid[x][y].start.x = srcX;
                            grid[x][y].end.x = dstX;
                            grid[x][y].start.y = srcY;
                            grid[x][y].end.y = dstY;

                            // Mark merge flags on both rooms
                            grid[x][y + 1].isMerged = TRUE;
                            grid[x][y].isMerged = TRUE;
                            grid[x][y + 1].isConnected = FALSE;
                            grid[x][y + 1].hasBeenMerged = TRUE;
                        }
                        break;
            	}
            }
		}
	}
}

/*
 * GenerateRoomImperfections - Attempt to generate room imperfections for each room, if flagged to do so.
 *
 * Rooms are flagged for whether to allow imperfections in CreateRoomsAndAnchors.
 * Each qualifying flagged room has a 40% chance to generate imperfections in the room.
 *
 * Imperfections are generated by randomly growing walls of the room inwards
 * for a certain number of iterations, depending on the average length of the room.
 *
 * Each iteration will go in both a counterclockwise and clockwise generation movement (not necessarily for the same corner though)
 *
 * We pick a random corner, derive our direction from the movement being used, then seek up to 10 tiles for one to replace.
 * We avoid getting too close to hallways and ensure our cardinal neighbor tiles match what we expect for open terrain.
 */
static void GenerateRoomImperfections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY)
{
    s32 x, y;

	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
            s32 counter, length;
            // To have imperfections a room must:
            // - be valid
            // - not have been merged
            // - be a room
            // - be connected
            // - not have a secondary structure
            // - not be a maze room
            // - be flagged to be made imperfect
            if (grid[x][y].isInvalid)
                continue;
            if (grid[x][y].hasBeenMerged)
                continue;
            if (grid[x][y].isMerged)
                continue;
            if (!grid[x][y].isConnected)
                continue;
            if (!grid[x][y].isRoom)
                continue;
            if (grid[x][y].hasSecondaryStructure)
                continue;
            if (grid[x][y].isMazeRoom)
                continue;
            if (!grid[x][y].flagImperfect)
                continue;

            // Roll for imperfections
            // By default, is a 40% chance that the room will still have imperfections
            if (DungeonRandInt(100) < GENERATION_CONSTANT_NO_IMPERFECTIONS_CHANCE)
                continue;

            length = grid[x][y].end.x - grid[x][y].start.x + (grid[x][y].end.y - grid[x][y].start.y);
            length /= 4;
            if (length == 0)
                length = 1;

            // Shrink the room from its corners either in the x or y direction
            // Repeat the number of times equal to the average room length
            for (counter = 0; counter < length; counter++) {
                s32 i, v;
            	for (i = 0; i < 2; i++) {
            		// Start from one of four corners
            		// i == 0 => fill in walls counterclockwise
            		// i == 1 => fill in walls clockwise
            		s32 pt_x, pt_y;
            		s32 moveX, moveY;
            		s32 startingCorner = DungeonRandInt(4);

            		switch (startingCorner) {
            		    // Top-left corner
                        case 0:
                        default:
                            pt_x = grid[x][y].start.x;
                            pt_y = grid[x][y].start.y;
                            if (i != 0) {
                                moveX = 1;
                                moveY = 0;
                            }
                            else {
                                moveX = 0;
                                moveY = 1;
                            }
                            break;
                        // Top-right corner
                        case 1:
                            pt_x = grid[x][y].end.x - 1;
                            pt_y = grid[x][y].start.y;
                            if (i != 0) {
                                moveX = 0;
                                moveY = 1;
                            }
                            else {
                                moveX = -1;
                                moveY = 0;
                            }
                            break;
                        // Bottom-right corner
                        case 2:
                            pt_x = grid[x][y].end.x - 1;
                            pt_y = grid[x][y].end.y - 1;

                            if (i != 0) {
                                moveX = -1;
                                moveY = 0;
                            }
                            else {
                                moveX = 0;
                                moveY = -1;
                            }
                            break;
                        // Bottom-left corner
                        case 3:
                            pt_x = grid[x][y].start.x;
                            pt_y = grid[x][y].end.y - 1;

                            if (i != 0) {
                                moveX = 0;
                                moveY = -1;
                            }
                            else {
                                moveX = 1;
                                moveY = 0;
                            }
                            break;
            		}

            		// Search up to 10 tiles for a new tile to replace
            		// from the selected starting corner and direction
            		for (v = 0; v < 10; v++) {
                        // Make sure we're still in bounds
                        if (pt_x < grid[x][y].start.x || pt_x >= grid[x][y].end.x) break;
                        if (pt_y < grid[x][y].start.y || pt_y >= grid[x][y].end.y) break;

                        if (GetTerrainType(GetTile(pt_x, pt_y)) == TERRAIN_TYPE_NORMAL) {
                        	// Make sure there aren't any hallways within 2 spaces from the current tile
                        	// If there are, skip filling it in

                        	s32 direction = DIRECTION_SOUTH;
                        	while (direction < NUM_DIRECTIONS) {
                                s32 offsetX, offsetY;
                        		s32 nextX = pt_x + gAdjacentTileOffsets[direction].x;
                        		s32 nextY = pt_y + gAdjacentTileOffsets[direction].y;

                        		bool8 found = FALSE;
                        		for (offsetY = -1; offsetY <= 1; offsetY++) {
                                    for (offsetX = -1; offsetX <= 1; offsetX++) {
                                    	// Search for open terrain which is not a part of a room (a hallway)
                                    	const Tile *tile = GetTile(nextX + offsetX, nextY + offsetY);

                                    	if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
                                            continue;
                                        if (tile->room == CORRIDOR_ROOM) {
                                            found = TRUE;
                                        }

                                        if (found)
                                            break;
                                    }

                                    if (found)
                                        break;
                        		}

                        		if (found)
                                    break;

                        		direction++;
                        	}

                        	// If direction == NUM_DIRECTIONS, we didn't find any hallways and are good to proceed
                        	if (direction == NUM_DIRECTIONS) {
                        		// Check that our cardinal neighbors' terrain types match what we expect for generating new tiles in this direction
                        		// For example, if we're generating from the top-left corner, we should only expect tiles
                        		// below us or to our right to have open terrain. If another tile does, we should stop
                        		// because the resulting room may look strange otherwise

                        		direction = DIRECTION_SOUTH;
                        		while (direction < NUM_DIRECTIONS) {
                                    s32 nextX = gAdjacentTileOffsets[direction].x;
                                    s32 nextY = gAdjacentTileOffsets[direction].y;
                                    bool8 isOpen = (GetTerrainType(GetTile(pt_x + nextX, pt_y + nextY)) == TERRAIN_TYPE_NORMAL);

                                    if (gUnknown_80F6DD5[startingCorner][direction] != isOpen)
                                        break;

                                    // Advance by 2 to only check cardinal directions
                                    direction += 2;
                        		}

                        		// If direction == NUM_DIRECTIONS, the neighbors match what we expect
                        		if (direction == NUM_DIRECTIONS) {
                                    // Fill in the current open floor tile with a wall
                                    SetTerrainWall(GetTileMut(pt_x, pt_y));
                        		}
                        	}

                        	break;
                        }
                        else {
                        	// The terrain is filled or already a wall, move to the next tile
                        	pt_x += moveX;
                        	pt_y += moveY;
                        }
            		}
            	}
            }
		}
	}
}

/*
 * CreateHallway - Creates a hallway between two points.
 *
 *        |---------B
 *        |
 * A------|
 *
 * The hallway generated consists of two parallel paths connected by a perpendicular "kink" in the path
 * The "kink" in a path occurs along (turn_x, turnY), which in practice is the grid cell boundary
 * If the paths trace same line, no "kink" will be generated
 *
 * If generation runs into an existing open tile, creation stops prematurely (such as another hallway).
 *
 * The vertical flag specifies whether the hallway is being generated horizontally or vertically
 */
static void CreateHallway(s32 x, s32 y, s32 endX, s32 endY, bool8 vertical, s32 turnX_, s32 turnY_)
{
    s32 startX = x;
    s32 startY = y;
    s32 turnX = turnX_;
    s32 turnY = turnY_;
	s32 counter;

	if (vertical) {
        // Vertical hallway

        counter = 0;
		// Create the vertical line between the starting point and the grid cell boundary
		while (y != turnY) {
            if (counter++ >= DUNGEON_MAX_SIZE_X)
                return; // Sanity check!

            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL) {
            	SetTerrainNormal(GetTileMut(x, y));
            }
            else {
            	// If we find open floor, stop here
            	// The hall has connected up to an existing hall
            	if (x != startX || y != startY)
                    return;
            }

            if (y < turnY) {
            	y++;
            }
            else {
            	y--;
            }
		}

		counter = 0;
		// Create the horizontal line to connect the horizontal lines at two different x values
		while (x != endX) {
            if (counter++ >= DUNGEON_MAX_SIZE_X)
                return; // Sanity check!

            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL) {
            	SetTerrainNormal(GetTileMut(x, y));
            }
            else {
            	if (x != startX || y != startY)
                    return;
            }

            if (x < endX) {
            	x++;
            }
            else {
            	x--;
            }
		}

		counter = 0;
		// Create the vertical line between the end point and the grid cell
		while (y != endY) {
            if (counter++ >= DUNGEON_MAX_SIZE_X)
                return;

            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL) {
            	SetTerrainNormal(GetTileMut(x, y));
            }
            else {
            	if (x != startX || y != startY)
                    return;
            }

            if (y < endY) {
            	y++;
            }
            else {
            	y--;
            }
		}
	}
	else {
		// Horizontal hallway

		counter = 0;
		// Create the horizontal line between the starting point and the grid cell boundary
		while (x != turnX) {
            if (counter++ >= DUNGEON_MAX_SIZE_X)
                return; // Sanity check!

            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL) {
            	SetTerrainNormal(GetTileMut(x, y));
            }
            else {
            	// If we find open floor, stop here
            	// The hall has connected up to an existing hall
            	if (x != startX || y != startY)
                    return;
            }

            if (x < turnX) {
            	x++;
            }
            else {
            	x--;
            }
		}

		counter = 0;
		// Create the vertical line to connect the horizontal lines at two different y values
		while (y != endY) {
            if (counter++ >= DUNGEON_MAX_SIZE_X)
                return;

            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL) {
            	SetTerrainNormal(GetTileMut(x, y));
            }
            else {
            	if (x != startX || y != startY)
                    return;
            }

            if (y < endY) {
            	y++;
            }
            else {
            	y--;
            }
		}

		counter = 0;
		// Create the horizontal line between the end point and the grid cell
		while (x != endX) {
            if (counter++ >= DUNGEON_MAX_SIZE_X)
                return;

            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL) {
            	SetTerrainNormal(GetTileMut(x, y));
            }
            else {
            	if (x != startX || y != startY)
                    return;
            }

            if (x < endX) {
            	x++;
            }
            else {
            	x--;
            }
		}
	}
}

/*
 * EnsureConnectedGrid - Ensure the grid forms a connected graph (all valid cells are reachable) by adding hallways to unreachable cells
 *
 * If the unconnected cell is a hallway anchor, it will be ignored and filled in.
 * If the unconnected cell is a room, it will check all adjacent directions for a connected room, then add a hallway between if found.
 *
 * If no eligible room is found, the room will be removed and filled back in.
 */
static void EnsureConnectedGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY)
{
    s32 x, y;

    for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
            // If any of these is TRUE, this cell is fine and we don't need to worry about it
            if (grid[x][y].isInvalid)
                continue;
            if (grid[x][y].hasBeenMerged)
                continue;
            if (grid[x][y].isConnected)
                continue;

            if (grid[x][y].isRoom && !grid[x][y].hasSecondaryStructure) {
            	// Unconnected room
            	s32 pt_x, pt_y;
            	s32 rnd_x = DungeonRandRange(grid[x][y].start.x + 1, grid[x][y].end.x - 1);
            	s32 rnd_y = DungeonRandRange(grid[x][y].start.y + 1, grid[x][y].end.y - 1);

            	if (y > 0 && !grid[x][y - 1].isInvalid && !grid[x][y - 1].isMerged && grid[x][y - 1].isConnected) {
            		// Attempt to connect to the grid cell above if it's connected
            		if (grid[x][y - 1].isRoom) {
                        // Room, take random interior x coordinate
                        pt_x = DungeonRandRange(grid[x][y - 1].start.x + 1, grid[x][y - 1].end.x - 1);
                        pt_y = DungeonRandRange(grid[x][y - 1].start.y + 1, grid[x][y - 1].end.y - 1); // Unused
            		}
            		else {
                        // Anchor, take center x
                        pt_x = grid[x][y - 1].start.x;
                        pt_y = grid[x][y - 1].start.y; // Unused
            		}

            		CreateHallway(rnd_x, grid[x][y].start.y, pt_x, grid[x][y - 1].end.y - 1, TRUE, listX[x], listY[y]);

            		grid[x][y].isConnected = TRUE;
            		grid[x][y].connectedToTop = TRUE;
            		grid[x][y - 1].connectedToBottom = TRUE;
            	}
            	else if (y < gridSizeY - 1 && !grid[x][y + 1].isInvalid && !grid[x][y + 1].isMerged && grid[x][y + 1].isConnected) {
            		// Attempt to connect to the grid cell below if it's connected
            		if (grid[x][y + 1].isRoom) {
            		    // Room, take random interior x coordinate
                        pt_x = DungeonRandRange(grid[x][y + 1].start.x + 1, grid[x][y + 1].end.x - 1);
                        pt_y = DungeonRandRange(grid[x][y + 1].start.y + 1, grid[x][y + 1].end.y - 1); // Unused
            		}
            		else {
                        // Anchor, take center x
                        pt_x = grid[x][y + 1].start.x;
                        pt_y = grid[x][y + 1].start.y; // Unused
            		}

            		CreateHallway(rnd_x, grid[x][y].end.y - 1, pt_x, grid[x][y + 1].start.y, TRUE, listX[x], listY[y + 1] - 1);

            		grid[x][y].isConnected = TRUE;
            		grid[x][y].connectedToBottom = TRUE;
            		grid[x][y + 1].connectedToTop = TRUE;
            	}
            	else if (x > 0 && !grid[x - 1][y].isInvalid && !grid[x - 1][y].isMerged && grid[x - 1][y].isConnected) {
            		// Attempt to connect to the grid cell left if it's connected
            		if (grid[x - 1][y].isRoom) {
                        // Room, take random interior y coordinate
                        pt_x = DungeonRandRange(grid[x - 1][y].start.x + 1, grid[x - 1][y].end.x - 1); //Unused
                        pt_y = DungeonRandRange(grid[x - 1][y].start.y + 1, grid[x - 1][y].end.y - 1);
            		}
            		else {
                        // Anchor, take center y
                        pt_x = grid[x - 1][y].start.x; // Unused
                        pt_y = grid[x - 1][y].start.y;
            		}

            		// Typo? Would expect grid[x - 1][y].end.x - 1 for 3rd parameter
            		CreateHallway(grid[x][y].start.x, rnd_y, grid[x - 1][y].start.x - 1, pt_y, FALSE, listX[x], listY[y]);

            		grid[x][y].isConnected = TRUE;
            		grid[x][y].connectedToLeft = TRUE;
            		grid[x - 1][y].connectedToRight = TRUE;
            	}
            	else if (x < gridSizeX - 1 && !grid[x + 1][y].isInvalid && !grid[x + 1][y].isMerged && grid[x + 1][y].isConnected) {
            		// Attempt to connect to the grid cell right if it's connected
            		if (grid[x + 1][y].isRoom) {
                        // Room, take random interior y coordinate
                        pt_x = DungeonRandRange(grid[x + 1][y].start.x + 1, grid[x + 1][y].end.x - 1); // Unused
                        pt_y = DungeonRandRange(grid[x + 1][y].start.y + 1, grid[x + 1][y].end.y - 1);
            		}
                    else {
                        // Anchor, take center y
                        pt_x = grid[x + 1][y].start.x; // Unused
                        pt_y = grid[x + 1][y].start.y;
            		}

            		CreateHallway(grid[x][y].end.x - 1, rnd_y, grid[x + 1][y].start.x, pt_y, FALSE, listX[x + 1] - 1, listY[y]);

            		grid[x][y].isConnected = TRUE;
            		grid[x][y].connectedToRight = TRUE;
            		grid[x + 1][y].connectedToLeft = TRUE;
            	}
            }
            else {
            	// Unconnected anchor, don't bother trying.

            	// Just fill it in with wall tiles
                Tile *tile = GetTileMut(grid[x][y].start.x, grid[x][y].start.y);
                SetTerrainWall(tile);

            	// Also remove any spawn flags
            	tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_STAIRS);
            	tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
            	tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_TRAP);
            }
		}
	}

	// If any rooms are still unconnected (meaning attempts to connect failed)
	// Fill in the rooms
	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
		    s32 curX, curY;
            if (grid[x][y].isInvalid || grid[x][y].hasBeenMerged || grid[x][y].isConnected || grid[x][y].unk15)
                continue;

            for (curX = grid[x][y].start.x; curX < grid[x][y].end.x; curX++) {
            	for (curY = grid[x][y].start.y; curY < grid[x][y].end.y; curY++) {
            		Tile *tile = GetTileMut(curX, curY);
                    // Set it to wall terrain
            		SetTerrainWall(tile);

            		// Remove any spawn flags
            		tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
                    tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_STAIRS);
                    tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_TRAP);

            		// Set room index to 0xFF (not a room)
            		tile->room = CORRIDOR_ROOM;
            	}
            }
		}
	}
}

/*
 * SetTerrainObstacleChecked - Sets terrain on a specific tile as an obstacle (either a wall or secondary terrain)
 *
 * If secondary terrain is requested and the room indices match, secondary terrain (water/lava) will be placed for the tile.
 *
 * Otherwise, the tile will be a wall.
 */
static void SetTerrainObstacleChecked(Tile *tile, bool8 useSecondaryTerrain, u8 roomIndex)
{
    SetTerrainWall(tile);
    if (useSecondaryTerrain && tile->room == roomIndex) {
        SetTerrainSecondary(tile);
    }
}

/*
 * FinalizeJunctions - Finalizes junction tiles by setting the junction flag and verifying the tiles are open terrain
 *
 * Due to the nature of how this function iterates left-to-right / top-to-bottom, by identifying junctions as any
 * open, non-hallway tile (roomIndex !== 0xFF) adjacent to an open, hallway tile (roomIndex == 0xFF), the function
 * runs into issues handling hallway anchors (roomIndex == 0xFE). The room index of hallway anchors is set to 0xFF using
 * the same loop, which means a hallway anchor may or may not be considered a junction depending on how the connected
 * hallways are oriented.
 *
 * For example, in the configuration below, the "o" tile would be marked as a junction because the neighboring hallway tile
 * to its left comes earlier in iteration, while "o" still has the room index 0xFE, with the algorithm mistaking it for a
 * room tile.
 *
 * X X X X X
 * - - - o X
 * X X X | X
 * X X X | X
 *
 * Alternatively, in the configuration below, the "o" tile would not be marked as a junction because it comes earlier in
 * iteration than any of its neighboring hallway tiles, so its room index is set to 0xFF before it can be marked as a junction.
 * This configuration is actually the only one where a hallway anchor will not be marked as a junction.
 *
 * X X X X X
 * X o - - -
 * X | X X X
 * X | X X X
 */
static void FinalizeJunctions(void)
{
    s32 x, y;

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL)
                continue;

            // Not in a room
            if (GetTile(x, y)->room == CORRIDOR_ROOM) {
                // Tile to the left is in a room (or anchor), mark junction
                if (x > 0) {
                    Tile *tile = GetTileMut(x - 1, y);
                    if (tile->room != CORRIDOR_ROOM) {
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;

                        // If there's any water/lava on the junction tile, remove it
                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
                // Tile above is in a room
                if (y > 0) {
                    Tile *tile = GetTileMut(x, y - 1);
                    if (tile->room != CORRIDOR_ROOM) {
                        // Yes, these |= have to be duplicated in order to match. Either it's an error and they wanted to use a different flag, or just copy-pasted it twice.
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
                // Tile below is in a room
                if (y < DUNGEON_MAX_SIZE_Y - 1) {
                    Tile *tile = GetTileMut(x, y + 1);
                    if (tile->room != CORRIDOR_ROOM) {
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
                //Tile to the right is in a room
                if (x < DUNGEON_MAX_SIZE_X - 1) {
                    Tile *tile = GetTileMut(x + 1, y);
                    if (tile->room != CORRIDOR_ROOM) {
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
            }
            // Hallway Anchor
            else if (GetTile(x, y)->room == ROOM_0xFE) {
                GetTileMut(x, y)->room = CORRIDOR_ROOM;
            }
        }
    }
    sub_804EB30();
}

void sub_804EB30(void)
{
    s32 i;
    s32 x, y;
    Dungeon *dungeon = gDungeon;

    for (i = 0; i < MAX_ROOM_COUNT; i++) {
        dungeon->naturalJunctionListCounts[i] = 0;
    }

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            if (GetTile(x, y)->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION) {
                u32 roomIndex = GetTile(x, y)->room;
                if (roomIndex < MAX_ROOM_COUNT && dungeon->naturalJunctionListCounts[roomIndex] < MAX_ROOM_COUNT) {
                    dungeon->naturalJunctionList[roomIndex][dungeon->naturalJunctionListCounts[roomIndex]].x = x;
                    dungeon->naturalJunctionList[roomIndex][dungeon->naturalJunctionListCounts[roomIndex]].y = y;
                    dungeon->naturalJunctionListCounts[roomIndex]++;
                }
            }
        }
    }
}

/*
 * GenerateKecleonShop - Potentially generate a kecleon shop on the floor.
 *
 * To spawn a kecleon shop, the floor cannot have a monster house, must not be a rescue floor, and must roll
 * the percentage chance of kecleon_chance.
 *
 * Grid cells indices are shuffled, then each is checked to meet the conditions to spawn a kecleon shop in that cell:
 * The room must be valid, connected, have no other special features, and have dimensions of at least 5x4.
 *
 * Once the first room (if any) is found that meets these conditions, the room is assigned as a kecleon shop.
 * The kecleon shop will occupy the whole room interior, with a one tile margin from the room walls.
 * Kecleon shop tiles restrict monster and stair spawns.
 */
static void GenerateKecleonShop(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance)
{
    s16 listX[GRID_CELL_LEN];
    s16 listY[GRID_CELL_LEN];
    s32 x, y;
    s32 i, j;
    Dungeon *dungeon = gDungeon;

    sKecleonShopMiddlePos.x = -1;
    sKecleonShopMiddlePos.y = -1;

	if (sHasMonsterHouse || GetFloorType() == FLOOR_TYPE_RESCUE || chance == 0)
        return;
	if (chance <= DungeonRandInt(100))
        return;

	// All possible grid cells
	for (i = 0; i < GRID_CELL_LEN; i++) {
		listX[i] = i;
		listY[i] = i;
	}

	// Shuffle x indices
	for (i = 0; i < 200; i++) {
        s32 temp;
		s32 a = DungeonRandInt(GRID_CELL_LEN);
		s32 b = DungeonRandInt(GRID_CELL_LEN);

		SWAP(listX[a], listX[b], temp);
	}

	// Shuffle y indices
	for (i = 0; i < 200; i++) {
        s32 temp;
		s32 a = DungeonRandInt(GRID_CELL_LEN);
		s32 b = DungeonRandInt(GRID_CELL_LEN);

		SWAP(listY[a], listY[b], temp);
	}

	for (i = 0; i < GRID_CELL_LEN; i++) {
        x = listX[i];
		if (x >= gridSizeX)
            continue;

		for (j = 0; j < GRID_CELL_LEN; j++) {
            s32 curX, curY;

            y = listY[j];
            if (y >= gridSizeY)
                continue;

            // We've identified a random in-bounds grid cell
            // To support a kecleon shop it must be:
            // - valid
            // - not a merged room
            // - connected
            // - a room
            // - have no other special features (mazes/secondary structures)
            // - have dimensions of at least 5x4
            if (grid[x][y].isInvalid)
                continue;
            if (grid[x][y].hasBeenMerged)
                continue;
            if (grid[x][y].isMerged)
                continue;
            if (!grid[x][y].isConnected)
                continue;
            if (!grid[x][y].isRoom)
                continue;
            if (grid[x][y].hasSecondaryStructure)
                continue;
            if (grid[x][y].isMazeRoom)
                continue;
            if (grid[x][y].flagSecondaryStructure)
                continue;

            if (abs(grid[x][y].end.x - grid[x][y].start.x) < 5 || abs(grid[x][y].end.y - grid[x][y].start.y) < 4)
                continue;

            // This room can be a kecleon shop
            sHasKecleonShop = TRUE;
            grid[x][y].isKecleonShop = TRUE;

            // Make the shop span the whole room
            sKecleonShopPosition.minX = grid[x][y].start.x + 1;
            sKecleonShopPosition.maxX = grid[x][y].end.x - 1;
            sKecleonShopPosition.minY = grid[x][y].start.y + 1;
            sKecleonShopPosition.maxY = grid[x][y].end.y - 1;

            if (sKecleonShopPosition.maxY  - sKecleonShopPosition.minY < 3) {
            	// This should never happen?
            	sKecleonShopPosition.maxY++;
            }

            // Set to values that guarantee they'll be replaced later
            dungeon->kecleonShopPos.minX = DEFAULT_MAX_POSITION;
            dungeon->kecleonShopPos.minY = DEFAULT_MAX_POSITION;
            dungeon->kecleonShopPos.maxX = -DEFAULT_MAX_POSITION;
            dungeon->kecleonShopPos.maxY = -DEFAULT_MAX_POSITION;

            // Generate the actual shop on the interior, leaving
            // a 1-tile border from the room walls
            for (curX = sKecleonShopPosition.minX; curX < sKecleonShopPosition.maxX; curX++) {
            	for (curY = sKecleonShopPosition.minY; curY < sKecleonShopPosition.maxY; curY++) {
                    Tile *tile = GetTileMut(curX, curY);

                    tile->terrainType |= TERRAIN_TYPE_SHOP;

            		// Restrict monsters and stairs from spawning here
            		tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_MONSTER);
            		tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_STAIRS);

            		// Ensure the borders are assigned properly
            		if (dungeon->kecleonShopPos.minX > curX) {
                        dungeon->kecleonShopPos.minX = curX;
            		}

            		if (dungeon->kecleonShopPos.minY > curY) {
                        dungeon->kecleonShopPos.minY = curY;
            		}

            		if (dungeon->kecleonShopPos.maxX < curX) {
                        dungeon->kecleonShopPos.maxX = curX;
            		}

            		if (dungeon->kecleonShopPos.maxY < curY) {
                        dungeon->kecleonShopPos.maxY = curY;
            		}
            	}
            }

            // Sets an unknown spawn flag for all tiles in the room
            for (curX = grid[x][y].start.x; curX < grid[x][y].end.x; curX++) {
            	for (curY = grid[x][y].start.y; curY < grid[x][y].end.y; curY++) {
                    GetTileMut(curX, curY)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
            	}
            }

            curX = (sKecleonShopPosition.minX + sKecleonShopPosition.maxX) / 2;
            curY = (sKecleonShopPosition.minY + sKecleonShopPosition.maxY) / 2;
            sKecleonShopMiddlePos.x = curX;
            sKecleonShopMiddlePos.y = curY;

            return;
		}
	}
}

/*
 * GenerateMonsterHouse - Possibly generate a monster house on the floor.
 *
 * A Monster House will be generated with a probability determined by the Monster House spawn chance, and only
 * if the floor supports one (no kecleon shop, no non-MH outlaw missions, no special floor types)
 *
 * A Monster House will be generated in a random room that's valid, connected, not merged, not a maze room, and
 * is not a few unknown conditions.
 */
static void GenerateMonsterHouse(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance)
{
	// To spawn a monster house on this floor:
	// - It must meet the probability chance
	// - not have a kecleon shop
	// - Be an outlaw monster house floor or not be a special destination floor with a target
	// - Be a Normal Floor Type

	s32 i;
	bool8 values[256];
	s32 x, y;
	s32 numValid;
	Dungeon *dungeon = gDungeon;

	if (chance == 0 || chance <= DungeonRandInt(100))
        return;
	if (sHasKecleonShop)
        return;
	if (gDungeon->unk644.unk44 != 0)
        return;
    if (GetFloorType() != FLOOR_TYPE_NORMAL)
        return;

	numValid = 0;

	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
            // A grid cell can have a monster house if it:
            // - is valid
            // - is not a merged room
            // - is connected
            // - is a room
            // - is not a maze
            // - and some other unknown condition
            if (grid[x][y].isInvalid)
                continue;
            if (grid[x][y].hasBeenMerged)
                continue;
            if (!grid[x][y].isConnected)
                continue;
            if (!grid[x][y].isRoom)
                continue;
            if (grid[x][y].isKecleonShop)
                continue;
            if (grid[x][y].unk15)
                continue;
            if (grid[x][y].isMazeRoom)
                continue;
            if (grid[x][y].hasSecondaryStructure)
                continue;

            numValid++;
		}
	}

	if (numValid == 0)
        return;

	// Have a single 1, the rest as 0's
	for (i = 0; i < 256; i++) {
        values[i] = FALSE;
	}
	values[0] = TRUE;

	// Shuffle values
	for (i = 0; i < 64; i++) {
        s32 temp;
		s32 a = DungeonRandInt(numValid);
		s32 b = DungeonRandInt(numValid);

		SWAP(values[a], values[b], temp);
	}

    // Counter
	i = 0;
	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
            if (grid[x][y].isInvalid)
                continue;
            if (grid[x][y].hasBeenMerged)
                continue;
            if (!grid[x][y].isConnected)
                continue;
            if (!grid[x][y].isRoom)
                continue;
            if (grid[x][y].isKecleonShop)
                continue;
            if (grid[x][y].unk15)
                continue;
            if (grid[x][y].isMazeRoom)
                continue;
            if (grid[x][y].hasSecondaryStructure)
                continue;

            if (values[i]) {
                s32 curX, curY;
                // The selected room can support a monster house
                // Generate one!
                sHasMonsterHouse = TRUE;
                grid[x][y].isMonsterHouse = TRUE;

                for (curX = grid[x][y].start.x; curX < grid[x][y].end.x; curX++) {
                    for (curY = grid[x][y].start.y; curY < grid[x][y].end.y; curY++) {
                        GetTileMut(curX, curY)->terrainType |= TERRAIN_TYPE_IN_MONSTER_HOUSE;
                        dungeon->monsterHouseRoom = GetTile(curX, curY)->room;
                    }
                }
                return;
            }

            i++;
		}
	}
}

/*
 * GenerateMazeRoom - Determines and calls for whether to generate a maze room on the floor.
 *
 * A maze room can be generated by the probability specified in the maze_chance parameter, usually in vanilla
 * this parameter is set to either 0 or 1, giving a 0-1% chance for trying to spawn a maze room.
 *
 * Then, a strange check occurs for whether the floor_generation_attempts is < 0, which will always fail, resulting
 * in no maze rooms ever being generated under normal conditions.
 *
 * Candidate maze rooms have to be valid, connected, have odd dimensions, and not have any other features.
 * If any candidates are found, the game will select one of these rooms and call GenerateMaze.
 */
static void GenerateMazeRoom(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance)
{
    bool8 values[256];
    s32 i;
    s32 x, y;
    s32 numValid;
    Dungeon *dungeon = gDungeon;
	if (chance == 0) // No chance for maze, stop
        return;
	if (chance <= DungeonRandInt(100)) // Need to roll the probability chance (which is usually 0-1%...)
        return;
    if (dungeon->unk3A16 >= 0) // This bizarre check prevents maze rooms from ever being created
        return;

    // Count the number of rooms that can be mazified:
    // - Valid
    // - Not a Merged Room
    // - Connected
    // - Not a Monster House
    // - Both Dimensions are Odd

    numValid = 0;
    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            if (grid[x][y].isInvalid)
                continue;
            if (grid[x][y].hasBeenMerged)
                continue;
            if (!grid[x][y].isConnected)
                continue;
            if (!grid[x][y].isRoom)
                continue;
            if (grid[x][y].isKecleonShop)
                continue;
            if (grid[x][y].unk15)
                continue;
            if (grid[x][y].isMonsterHouse)
                continue;
            if (grid[x][y].hasSecondaryStructure)
                continue;

            if ((grid[x][y].end.x - grid[x][y].start.x) % 2 != 0 && (grid[x][y].end.y - grid[x][y].start.y) % 2 != 0) {
                numValid++;
            }
        }
    }

    if (numValid == 0)
        return;

    // Have a single 1, the rest as 0's
    for (i = 0; i < 256; i++) {
        values[i] = FALSE;
	}
	values[0] = TRUE;

	// Shuffle values
	for (i = 0; i < 64; i++) {
        s32 temp;
		s32 a = DungeonRandInt(numValid);
		s32 b = DungeonRandInt(numValid);

		SWAP(values[a], values[b], temp);
	}

	// Counter
    i = 0;
    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            if (grid[x][y].isInvalid)
                continue;
            if (grid[x][y].hasBeenMerged)
                continue;
            if (!grid[x][y].isConnected)
                continue;
            if (!grid[x][y].isRoom)
                continue;
            if (grid[x][y].isKecleonShop)
                continue;
            if (grid[x][y].unk15)
                continue;
            if (grid[x][y].isMonsterHouse)
                continue;
            if (grid[x][y].hasSecondaryStructure)
                continue;

            if ((grid[x][y].end.x - grid[x][y].start.x) % 2 != 0 && (grid[x][y].end.y - grid[x][y].start.y) % 2 != 0) {
                // This room can be mazified
                if (values[i]) {
                    GenerateMaze(&grid[x][y], FALSE);
                    return;
                }

                i++;
            }
        }
    }
}

/*
 * GenerateMaze - Generate a maze room within the given grid cell.
 *
 * A "maze" is generated using a series of random walks whiich place obstacle terrain (walls / secondary terrain)
 * in a maze-like arrangement. "Maze lines" (see: GenerateMazeLine) are generated using every other tile around the
 * room's border, and every other interior tile as a starting point, ensuring there are stripes of walkable open terrain
 * surrounded by striples of obstacles (maze walls).
 *
 */
static void GenerateMaze(struct GridCell *gridCell, bool8 useSecondaryTerrain)
{
    s32 curX, curY;
    u8 roomIndex;

	sHasMaze = TRUE;
	gridCell->isMazeRoom = TRUE;

    roomIndex = GetTile(gridCell->start.x, gridCell->start.y)->room;

	// Random walks from upper border
	for (curX = gridCell->start.x + 1; curX < gridCell->end.x - 1; curX += 2) {
		if (GetTerrainType(GetTile(curX, gridCell->start.y - 1)) != TERRAIN_TYPE_NORMAL) {
            GenerateMazeLine(curX,
            	gridCell->start.y - 1,
            	gridCell->start.x,
            	gridCell->start.y,
            	gridCell->end.x,
            	gridCell->end.y,
            	useSecondaryTerrain,
            	roomIndex
            );
		}
	}

	// Random walks from right border
	for (curY = gridCell->start.y + 1; curY < gridCell->end.y - 1; curY += 2) {
		if (GetTerrainType(GetTile(gridCell->end.x, curY)) != TERRAIN_TYPE_NORMAL) {
            GenerateMazeLine(gridCell->end.x, curY, gridCell->start.x, gridCell->start.y, gridCell->end.x, gridCell->end.y, useSecondaryTerrain, roomIndex);
		}
	}

	// Random walks from lower border
	for (curX = gridCell->start.x + 1; curX < gridCell->end.x - 1; curX += 2) {
		if (GetTerrainType(GetTile(curX, gridCell->end.y)) != TERRAIN_TYPE_NORMAL) {
            GenerateMazeLine(curX, gridCell->end.y, gridCell->start.x, gridCell->start.y, gridCell->end.x, gridCell->end.y, useSecondaryTerrain, roomIndex);
		}
	}

	// Random walks from left border
	for (curY = gridCell->start.y + 1; curY < gridCell->end.y - 1; curY += 2) {
		if (GetTerrainType(GetTile(gridCell->start.x - 1, curY)) != TERRAIN_TYPE_NORMAL) {
            GenerateMazeLine(gridCell->start.x - 1,
            	curY,
            	gridCell->start.x,
            	gridCell->start.y,
            	gridCell->end.x,
            	gridCell->end.y,
            	useSecondaryTerrain,
            	roomIndex);
		}
	}

	// Fill in all the inner tiles with a stride of 2
	for (curX = gridCell->start.x + 3; curX < gridCell->end.x - 3; curX += 2) {
		for (curY = gridCell->start.y + 3; curY < gridCell->end.y - 3; curY += 2) {
            if (GetTerrainType(GetTile(curX, curY)) == TERRAIN_TYPE_NORMAL) {
            	if (useSecondaryTerrain) {
                    SetTerrainSecondary(GetTileMut(curX - 1, curY));
            	}
            	else {
            		SetTerrainWall(GetTileMut(curX - 1, curY));
            	}

            	// More random walks
            	GenerateMazeLine(curX, curY, gridCell->start.x, gridCell->start.y, gridCell->end.x, gridCell->end.y, useSecondaryTerrain, roomIndex);
            }
		}
	}
}

/*
 * GenerateMazeLine - Generates a "maze line" from the given start point, within the given bounds.
 *
 * A "maze line" is a random walk starting from (x0, y0). The random walk moves in strides of 2
 * in a random direction, placing down obstacles as it goes.
 *
 * The walk will terminate when the random walk has no available open tiles it can walk to.
 *
 *  [ ^ ] [   ] [   ]      	[ o ] [ - ] [ > ]
 *  [ | ] [   ] [   ]   =>	[ W ] [   ] [   ]  => etc.
 *  [ o ] [   ] [ W ]		[ W ] [   ] [ W ]
 *
 * First, an obstacle is placed at the given DungeonPos (see: SetTerrainObstacleChecked)
 *
 * Then, a random direction is selected, searching for an open tile distance 2 away from (x0, y0).
 * Each direction is attempted rotating counter-clockwise until an open tile is found or all directions are exhausted.
 *
 * If an open tile is found, an obstacle is placed between the two tiles, and (x0, y0) moves to the new open tile.
 * This process continues until no valid open tile can be found.
 */
static void GenerateMazeLine(s32 x0, s32 y0, s32 xMin, s32 yMin, s32 xMax, s32 yMax, bool8 useSecondaryTerrain, u32 roomIndex)
{
	while (1) {
		s32 direction = DungeonRandInt(NUM_CARDINAL_DIRECTIONS);
        s32 i = 0;

		SetTerrainObstacleChecked(GetTileMut(x0, y0), useSecondaryTerrain, roomIndex);

        while (1) {
            s32 offsetX, offsetY;
            s32 posX, posY;

            // Offset from our current DungeonPos to look 2 tiles in a given direction
            switch (direction & CARDINAL_DIRECTION_MASK) {
                case CARDINAL_DIR_RIGHT:
                    offsetX = 2;
                    offsetY = 0;
                    break;
                case CARDINAL_DIR_UP:
                    offsetX = 0;
                    offsetY = -2;
                    break;
                case CARDINAL_DIR_LEFT:
                    offsetX = -2;
                    offsetY = 0;
                    break;
                default:
                case CARDINAL_DIR_DOWN:
                    offsetX = 0;
                    offsetY = 2;
                    break;
            }

            posX = x0 + offsetX;

            // Check that this DungeonPos is in-bounds
            if (xMin <= posX && xMax > posX) {
                posY = y0 + offsetY;
                if (yMin <= posY && yMax > posY) {
                    // Check that this tile is open ground
                	if (GetTerrainType(GetTile(posX, posY)) == TERRAIN_TYPE_NORMAL) {
                		// We found open ground, we're done!
                		break;
                	}
                }
            }

            // We didn't find any, try a different direction
            direction++;
            if (++i >= 4)
                return;
		}

		// If we found some open terrain, set an obstacle for the terrain in between those two,
		// then move to the open terrain we found.
		switch (direction & CARDINAL_DIRECTION_MASK) {
		    case CARDINAL_DIR_RIGHT:
                SetTerrainObstacleChecked(GetTileMut(x0 + 1, y0), useSecondaryTerrain, roomIndex);

            	x0 += 2;
                break;
            case CARDINAL_DIR_UP:
                SetTerrainObstacleChecked(GetTileMut(x0, y0 - 1), useSecondaryTerrain, roomIndex);

            	y0 -= 2;
                break;
            case CARDINAL_DIR_LEFT:
                SetTerrainObstacleChecked(GetTileMut(x0 - 1, y0), useSecondaryTerrain, roomIndex);

            	x0 -= 2;
                break;
            case CARDINAL_DIR_DOWN:
                SetTerrainObstacleChecked(GetTileMut(x0, y0 + 1), useSecondaryTerrain, roomIndex);

            	y0 += 2;
                break;
		}
	}
}

static void SetTerrainSecondaryWithFlag(Tile *tile, u32 additionalFlag)
{
    SetTerrainSecondary(tile);
    tile->terrainType |= additionalFlag;
}

/*
 * SetSpawnFlag5 - Sets unknown spawn flag 0x5 on all tiles in a room
 */
static void SetSpawnFlag5(struct GridCell *gridCell)
{
    s32 x, y;

	for (x = gridCell->start.x; x < gridCell->end.x; x++) {
		for (y = gridCell->start.y; y < gridCell->end.y; y++) {
            GetTileMut(x, y)->spawnOrVisibilityFlags |= SPAWN_FLAG_UNK5;
		}
	}
}

/*
 * IsNextToHallway - Checks if a tile DungeonPos is either in a hallway or next to one.
 */
static bool8 IsNextToHallway(s32 x, s32 y)
{
    s32 offsetX, offsetY;
    s32 posX, posY;

	for (offsetX = -1; offsetX <= 1; offsetX++) {
        posX = x + offsetX;
		if (posX < 0)
            continue;
		if (posX >= DUNGEON_MAX_SIZE_X)
            break;

		for (offsetY = -1; offsetY <= 1; offsetY++) {
            posY = y + offsetY;
            if (posY < 0)
                continue;
            if (posY >= DUNGEON_MAX_SIZE_Y)
                break;
            if (offsetX != 0 && offsetY != 0)
                continue;

            if (GetTerrainType(GetTile(posX, posY)) == TERRAIN_TYPE_NORMAL && GetTile(posX, posY)->room == CORRIDOR_ROOM)
            	return TRUE;
		}
	}

	return FALSE;
}

// See GenerateSecondaryStructures for more information.
static void GenerateSecondaryStructure(struct GridCell *gridCell)
{
    switch (DungeonRandInt(6)) {
        // Generate a "split room" with two sides separated by a line of water/lava
        case SECONDARY_STRUCTURE_DIVIDER:
            if (sSecondaryStructuresBudget != 0) {
                s32 i;

                sSecondaryStructuresBudget--;

            	SetSpawnFlag5(gridCell);
            	if (DungeonRandInt(2) != 0) {
            		// Split the room with a vertical line
                    s32 curX, curY;
            		bool8 invalid = FALSE;
            		s32 middleX = (gridCell->start.x + gridCell->end.x) / 2;

            		for (i = gridCell->start.y; i < gridCell->end.y; i++) {
                        if (IsNextToHallway(middleX, i)) {
                        	invalid = TRUE;
                        	break;
                        }
            		}

            		if (!invalid) {
                        for (i = gridCell->start.y; i < gridCell->end.y; i++) {
                            SetTerrainSecondaryWithFlag(GetTileMut(middleX, i), 0);
                        }

                        for (curX = gridCell->start.x; curX < middleX; curX++) {
                        	for (curY = gridCell->start.y; curY < gridCell->end.y; curY++) {
                                GetTileMut(curX, curY)->terrainType |= TERRAIN_TYPE_UNK_7;
                        	}
                        }

                        gridCell->hasSecondaryStructure = TRUE;
            		}
            	}
            	else {
                    // Split the room with a horizontal line
                    s32 curX, curY;
                    bool8 invalid = FALSE;
                    s32 middleY = (gridCell->start.y + gridCell->end.y) / 2;

            		for (i = gridCell->start.x; i < gridCell->end.x; i++) {
                        if (IsNextToHallway(i, middleY)) {
                        	invalid = TRUE;
                        	break;
                        }
            		}

            		if (!invalid) {
                        for (i = gridCell->start.x; i < gridCell->end.x; i++) {
                        	SetTerrainSecondaryWithFlag(GetTileMut(i, middleY), 0);
                        }

                        for (curY = gridCell->start.y; curY < middleY; curY++) {
                            for (curX = gridCell->start.x; curX < gridCell->end.x; curX++) {
                        		GetTileMut(curX, curY)->terrainType |= TERRAIN_TYPE_UNK_7;
                        	}
                        }

                        gridCell->hasSecondaryStructure = TRUE;
            		}
            	}
            }
            break;
        case SECONDARY_STRUCTURE_ISLAND:
            if ((gridCell->end.x - gridCell->start.x) >= 6 && (gridCell->end.y - gridCell->start.y) >= 6) {
                s32 middleX = (gridCell->start.x + gridCell->end.x) / 2;
                s32 middleY = (gridCell->start.y + gridCell->end.y) / 2;
                // Both dimensions are at least 6. Generate an "island" with lava, items, and a Warp Tile at the center
                if (sSecondaryStructuresBudget != 0) {
                    sSecondaryStructuresBudget--;

                    SetSpawnFlag5(gridCell);

                    // Water "Moat"
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX - 2, middleY - 2), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX - 1, middleY - 2), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX, middleY - 2), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX + 1, middleY - 2), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX - 2, middleY - 1), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX - 2, middleY), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX - 2, middleY + 1), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX - 2, middleY + 1), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX - 1, middleY + 1), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX, middleY + 1), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX + 1, middleY - 2), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX + 1, middleY - 1), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX + 1, middleY), TERRAIN_TYPE_CORNER_CUTTABLE);
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX + 1, middleY + 1), TERRAIN_TYPE_CORNER_CUTTABLE);

                    // Trap
                    GetTileMut(middleX - 1, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_TRAP;
                    // Warp Tile ?
                    GetTileMut(middleX - 1, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_UNK6;

                    // Items
                    GetTileMut(middleX, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
                    GetTileMut(middleX - 1, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
                    GetTileMut(middleX, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
                    GetTileMut(middleX - 1, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
                    GetTileMut(middleX, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
                    GetTileMut(middleX - 1, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
                    GetTileMut(middleX, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;

                    gridCell->hasSecondaryStructure = TRUE;
                }
            }
            break;
        case SECONDARY_STRUCTURE_POOL:
            if ((gridCell->end.x - gridCell->start.x) >= 5 && (gridCell->end.y - gridCell->start.y) >= 5) {
                s32 curX, curY;
                // Both dimensions are at least 5, generate a "pool" of water/lava

                s32 randX1 = DungeonRandRange(gridCell->start.x + 2, gridCell->end.x - 3);
                s32 randY1 = DungeonRandRange(gridCell->start.y + 2, gridCell->end.y - 3);
                s32 randX2 = DungeonRandRange(gridCell->start.x + 2, gridCell->end.x - 3);
                s32 randY2 = DungeonRandRange(gridCell->start.y + 2, gridCell->end.y - 3);

                if (sSecondaryStructuresBudget != 0) {
                    sSecondaryStructuresBudget--;

                    SetSpawnFlag5(gridCell);

                    if (randX1 > randX2) {
                        s32 temp;
                        SWAP(randX1, randX2, temp);
                    }

                    if (randY1 > randY2) {
                        s32 temp;
                        SWAP(randY1, randY2, temp);
                    }

                    for (curX = randX1; curX <= randX2; curX++) {
                        for (curY = randY1; curY <= randY2; curY++) {
                            SetTerrainSecondaryWithFlag(GetTileMut(curX, curY), 0);
                        }
                    }

                    gridCell->hasSecondaryStructure = TRUE;
                }
            }
            break;
        case SECONDARY_STRUCTURE_CHECKERBOARD:
            if ((gridCell->end.x - gridCell->start.x) % 2 != 0 && (gridCell->end.y - gridCell->start.y) % 2 != 0 && sSecondaryStructuresBudget != 0) {
                s32 i;
                // Dimensions are odd, generate diagonal stripes/checkerboard of water/lava
                sSecondaryStructuresBudget--;

                SetSpawnFlag5(gridCell);

                for (i = 0; i < 64; i++) {
                    s32 randX = DungeonRandInt(gridCell->end.x - gridCell->start.x);
                    s32 randY = DungeonRandInt(gridCell->end.y - gridCell->start.y);
                    if ((randX + randY) % 2 != 0) {
                        SetTerrainSecondaryWithFlag(GetTileMut(gridCell->start.x + randX, gridCell->start.y + randY), 0);
                    }
                }

                gridCell->hasSecondaryStructure = TRUE;
            }
            break;
        case SECONDARY_STRUCTURE_MAZE_PLUS_DOT:
            if (sSecondaryStructuresBudget != 0) {
                sSecondaryStructuresBudget--;

                // If the dimensions are odd, generate a maze room
            	if ((gridCell->end.x - gridCell->start.x) % 2 == 0 || (gridCell->end.y - gridCell->start.y) % 2 == 0) {
                    s32 middleX = (gridCell->start.x + gridCell->end.x) / 2;
                    s32 middleY = (gridCell->start.y + gridCell->end.y) / 2;
            		if ((gridCell->end.x - gridCell->start.x) >= 5 && (gridCell->end.y - gridCell->start.y) >= 5) {
                        // Both dimensions are at least 5, generate a water/lava cross in the center
                        SetTerrainSecondaryWithFlag(GetTileMut(middleX + 1, middleY), 0);
                        SetTerrainSecondaryWithFlag(GetTileMut(middleX, middleY + 1), 0);
                        SetTerrainSecondaryWithFlag(GetTileMut(middleX - 1, middleY), 0);
                        SetTerrainSecondaryWithFlag(GetTileMut(middleX, middleY - 1), 0);
            		}

                    // Generate a single water/lava spot in the center
                    SetTerrainSecondaryWithFlag(GetTileMut(middleX, middleY), 0);
            	}
            	else {
                    // Both dimensions are odd. Generate a maze room
            		SetSpawnFlag5(gridCell);
            		GenerateMaze(gridCell, TRUE);
            	}

            	gridCell->hasSecondaryStructure = TRUE;
            }
            break;
    }
}

/*
 * ResolveInvalidSpawns - Resolve any potentially invalid spawns on tiles.
 *
 * Obstacles can't spawn traps, impassable obstacles can't spawn items (you aren't able to reach them)
 *
 * A tile marked for the stairs must not have a trap there
 *
 * A tile marked for an item also must not have a trap there
 */
static void ResolveInvalidSpawns(void)
{
    s32 x, y;

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            Tile *tile = GetTileMut(x, y);
            if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL) {
                if (tile->terrainType & (TERRAIN_TYPE_UNBREAKABLE | TERRAIN_TYPE_IMPASSABLE_WALL)) {
                    // This tile is an impassable obstacle, make sure no items spawn here
                    tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
                }
                // This tile is an obstacle, make sure no traps spawn here
                tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_TRAP);
            }

            if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_STAIRS) {
                // This tile has the stairs, make sure the stairs bit is set and
            	// make sure no traps spawn here
                tile->terrainType |= TERRAIN_TYPE_STAIRS;
                tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_TRAP);
            }
            if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_ITEM) {
                //This tile is an item spawn, make sure no traps spawn here
                tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_TRAP);
            }
        }
    }
}

// Converts Secondary terrain to both secondary and normal. Possibly to note that it's a water tile?
static void sub_804FC74(void)
{
    s32 x, y;

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            if (GetTerrainType(GetTile(x, y)) == TERRAIN_TYPE_SECONDARY) {
                SetTerrainType(GetTileMut(x,y), TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
            }
        }
    }
}

/*
 * EnsureImpassableTilesAreWalls - Force all tiles with the impassable flag to be set as walls.
 */
static void EnsureImpassableTilesAreWalls(void)
{
    s32 x, y;

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            if (GetTile(x, y)->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) {
                SetTerrainWall(GetTileMut(x,y));
            }
        }
    }
}

static void ResetTile(Tile *tile)
{
    tile->terrainType = 0;
    tile->spawnOrVisibilityFlags = 0;
    tile->room = -1;
    tile->unk8 = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_REGULAR] = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_LIQUID] = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_CREVICE] = 0;
    tile->walkableNeighborFlags[CROSSABLE_TERRAIN_WALL] = 0;
    tile->unkE = 0;
    tile->monster = NULL;
    tile->object = NULL;
}

// PosIsOutOfBounds - Checks if a DungeonPos is out of bounds on the map.
static inline bool8 PosIsOutOfBounds(s32 x, s32 y)
{
    if (x < 0)
        return TRUE;
    if (y < 0)
        return TRUE;
    if (DUNGEON_MAX_SIZE_X <= x)
        return TRUE;
    if (DUNGEON_MAX_SIZE_Y <= y)
        return TRUE;
    return FALSE;
}

static void ResetFloor(void)
{
    s32 x, y;

    // Reset Room Tiles
    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            ResetTile(GetTileMut(x,y));

            if ((PosIsOutOfBounds(x,     y - 1)) ||
                (PosIsOutOfBounds(x + 1, y - 1)) ||
                (PosIsOutOfBounds(x + 1, y - 1)) ||
                (PosIsOutOfBounds(x + 1, y + 1)) ||
                (PosIsOutOfBounds(x,     y + 1)) ||
                (PosIsOutOfBounds(x - 1, y + 1)) ||
                (PosIsOutOfBounds(x - 1, y))     ||
                (PosIsOutOfBounds(x - 1, y - 1)))
            {
                GetTileMut(x,y)->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
            }
        }
    }

    // Reset Stairs DungeonPos
    gDungeon->stairsSpawn.x = -1;
    gDungeon->stairsSpawn.y = -1;

    // Reset Fixed Room Tiles
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            ResetTile(&gDungeon->unkE27C[x][y]);
        }
    }

    gDungeon->numItems = 0;

    // Reset Traps
    for (x = 0; x < DUNGEON_MAX_TRAPS; x++) {
        gDungeon->traps[x]->type = 0;
    }
}

struct PositionU8
{
    u8 x;
    u8 y;
};

/*
 * ShuffleSpawnPositions - Randomly shuffle an array of spawn positions
 */
static void ShuffleSpawnPositions(struct PositionU8 *spawns, s32 count)
{
    s32 i;
	// Do twice as many swaps as there are items in the array
	for (i = 0; i < count * 2; i++) {
        struct PositionU8 temp;
		s32 a = DungeonRandInt(count);
		s32 b = DungeonRandInt(count);

        SWAP(spawns[a], spawns[b], temp);
	}
}

/*
 * SpawnNonEnemies - Spawns all non-enemy entities: Stairs, Items, Traps, and the player.
 *
 * Most entities spawn randomly on a subset of the valid tiles for their type.
 *
 * These spawns are categorized into:
 * - Stairs (and hidden stairs in later gens)
 * - Normal Items
 * - Buried Items
 * - Monster House Items/Traps
 * - Normal Traps
 * - Player Spawn
 *
 * See below for specific conditions on each type of spawn.
 */
extern const s16 gUnknown_80F4DA0;
extern const s16 gUnknown_80F4DA4;
static void SpawnNonEnemies(FloorProperties *floorProps, bool8 isEmptyMonsterHouse)
{
    struct PositionU8 validSpawns[DUNGEON_MAX_SIZE_X * DUNGEON_MAX_SIZE_Y];
    s32 count;
    s32 randIndex;
    s32 i;
    s32 x, y;
    Dungeon *dungeon = gDungeon;
	// Spawn Stairs
	if (dungeon->stairsSpawn.x == -1 || dungeon->stairsSpawn.y == -1) {
        count = 0;
		for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            	// The stairs can spawn on tiles that are:
            	// - Open Terrain
            	// - In a room
            	// - Not in a Kecleon Shop
            	// - Not an enemy spawn
            	// - Not a special tile (flagged by kecleon shops, traps, and items)
            	// - Not a junction tile (next to a hallway)
            	// - Not a special tile that can't be broken by Absolute Mover

                const Tile *tile = GetTile(x, y);
            	if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
                    continue;
                if (tile->room == CORRIDOR_ROOM)
                    continue;
                if (tile->terrainType & TERRAIN_TYPE_SHOP)
                    continue;
                if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_MONSTER)
                    continue;
                if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_SPECIAL_TILE)
                    continue;
                if (tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
                    continue;
                if (tile->terrainType & TERRAIN_TYPE_UNBREAKABLE)
                    continue;

                validSpawns[count].x = x;
                validSpawns[count].y = y;
                count++;
            }
		}

		if (count != 0) {
            // Randomly select one of the valid tiles to spawn the stairs on
            s32 stairsIndex = DungeonRandInt(count);
            Tile *stairsTile = GetTileMut(validSpawns[stairsIndex].x, validSpawns[stairsIndex].y);

            stairsTile->spawnOrVisibilityFlags |= SPAWN_FLAG_STAIRS;
            stairsTile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
            sStairsRoomIndex = stairsTile->room;
            dungeon->stairsSpawn.x = validSpawns[stairsIndex].x;
            dungeon->stairsSpawn.y = validSpawns[stairsIndex].y;

            // If we're spawning normal stairs and this is a rescue floor, make the stairs room a Monster House
            if (GetFloorType() == FLOOR_TYPE_RESCUE) {
                u32 stairsRoomIndex = stairsTile->room;
                for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
                    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
                        Tile *tile = GetTileMut(x, y);
                        if (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL && tile->room == stairsRoomIndex) {
                            tile->terrainType |= TERRAIN_TYPE_IN_MONSTER_HOUSE;
                            dungeon->monsterHouseRoom = tile->room;
                        }
                    }
                }
            }
		}
	}

	// Spawn normal items

	count = 0;
	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            // Normal items can spawn on tiles that are:
            // - Open Terrain
            // - In a room
            // - Not in a Kecleon Shop
            // - Not in a Monster House
            // - Not a junction tile (next to a hallway)
            // - Not a special tile that can't be broken by Absolute Mover

            const Tile *tile = GetTile(x, y);
            if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
                continue;
            if (tile->room == CORRIDOR_ROOM)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_SHOP)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_UNBREAKABLE)
                continue;

            validSpawns[count].x = x;
            validSpawns[count].y = y;
            count++;
		}
	}

	if (count != 0) {
		s32 numItems = floorProps->itemDensity;
		if (numItems != 0) {
            // Add variation to the item count
            numItems = DungeonRandRange(numItems - 2, numItems + 2);
            if (numItems <= 0) {
                numItems = 1;
            }
		}

		if (numItems != 0) {
            // Randomly select among the valid item spawn spots
            ShuffleSpawnPositions(validSpawns, count);
            randIndex = DungeonRandInt(count);
            for (i = 0; i < numItems; i++) {
            	Tile *tile = GetTileMut(validSpawns[randIndex].x, validSpawns[randIndex].y);
                tile->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;

                randIndex++;
                if (randIndex == count) {
                    // Wrap around to the start
                    randIndex = 0;
                }
            }
		}
	}

	// Spawn Buried Items (in walls)

	count = 0;
	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            // Any wall tile is all buried items need
            if (GetTerrainType(GetTile(x, y)) == TERRAIN_TYPE_WALL) {
            	validSpawns[count].x = x;
                validSpawns[count].y = y;
                count++;
            }
		}
	}

	if (count != 0) {
		s32 numItems = floorProps->buriedItemDensity;

		if (numItems != 0) {
            // Add variation to the item count
            numItems = DungeonRandRange(numItems - 2, numItems + 2);
		}

		if (numItems > 0) {
            // Randomly select among the valid item spawn spots
            ShuffleSpawnPositions(validSpawns, count);
            randIndex = DungeonRandInt(count);
            for (i = 0; i < numItems; i++) {
            	Tile *tile = GetTileMut(validSpawns[randIndex].x, validSpawns[randIndex].y);
                tile->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;

                randIndex++;
                if (randIndex == count) {
                    // Wrap around to the start
                    randIndex = 0;
                }
            }
		}
	}

	// Spawn items/traps in a non-empty Monster House
    count = 0;
	if (!isEmptyMonsterHouse) {
		for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            	// Monster House items/traps can spawn on tiles that are:
            	// - not in a kecleon shop (how would they be?)
            	// - in a Monster House
            	// - not a junction (near a hallway)
            	const Tile *tile = GetTile(x, y);
                if (tile->terrainType & TERRAIN_TYPE_SHOP)
                    continue;
                if (!(tile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE))
                    continue;
                if (tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
                    continue;

                validSpawns[count].x = x;
                validSpawns[count].y = y;
                count++;
            }
		}
	}

    if (count != 0) {
        // Choose a subset of the available tiles to spawn stuff on
        s32 numItems = DungeonRandRange((count / 2), (count * 8) / 10);

        if (numItems < 6) {
            numItems = 6;
        }
        // Cap item spawns at 7 (normally)
        if (numItems >= gUnknown_80F4DA0) {
            numItems = gUnknown_80F4DA0;
        }

        // Randomly select among the valid item spawn spots
        ShuffleSpawnPositions(validSpawns, count);
        randIndex = DungeonRandInt(count);
        for (i = 0; i < numItems; i++) {
            Tile *tile = GetTileMut(validSpawns[randIndex].x, validSpawns[randIndex].y);

            // 50/50 chance of spawning an item or a trap
            if (DungeonRandInt(2) != 0) {
                // Spawn an item
                tile->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
            }
            else if (gDungeon->unk644.unk18) {
                tile->spawnOrVisibilityFlags |= SPAWN_FLAG_TRAP;
            }

            randIndex++;
            if (randIndex == count) {
                // Wrap around to the start
                randIndex = 0;
            }
        }
    }

	// Spawn Normal Traps
	count = 0;
	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            // Normal traps can spawn on tiles that are:
            // - Open Terrain
            // - In a room
            // - Not in a Kecleon Shop
            // - Don't already have an item spawn
            // - Not a junction tile (next to a hallway)
            // - Not a special tile that can't be broken by Absolute Mover

            const Tile *tile = GetTile(x, y);
            if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
                continue;
            if (tile->room == CORRIDOR_ROOM)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_SHOP)
                continue;
            if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_ITEM)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_UNBREAKABLE)
                continue;

            validSpawns[count].x = x;
            validSpawns[count].y = y;
            count++;
		}
	}

	if (count != 0) {
		s32 numTraps = DungeonRandRange(floorProps->trapDensity / 2, floorProps->trapDensity);

		if (numTraps > 0) {
            s32 trapIndex;
            if (numTraps >= 56) {
            	// Cap the number of traps at 56
            	numTraps = 56;
            }

            // Randomly select among the valid trap spawn spots
            ShuffleSpawnPositions(validSpawns, count);
            trapIndex = DungeonRandInt(count);
            for (i = 0; i < numTraps; i++) {
            	Tile *tile = GetTileMut(validSpawns[trapIndex].x, validSpawns[trapIndex].y);
                tile->spawnOrVisibilityFlags |= SPAWN_FLAG_TRAP;

                trapIndex++;
                if (trapIndex == count) {
                    // Wrap around to the start
                    trapIndex = 0;
                }
            }
		}
	}

	// Spawn the player
	if (dungeon->playerSpawn.x == -1 || dungeon->playerSpawn.y == -1) {
        count = 0;
		for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            	// The player can spawn on tiles that are:
            	// - Open Terrain
            	// - In a room
            	// - Not in a Kecleon Shop
            	// - Not a junction tile (next to a hallway)
            	// - Not a special tile that can't be broken by Absolute Mover
            	// - Not an item, enemy, or trap spawn

            	const Tile *tile = GetTile(x, y);
                if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
                    continue;
                if (tile->room == CORRIDOR_ROOM)
                    continue;
                if (tile->terrainType & TERRAIN_TYPE_SHOP)
                    continue;
                if (tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
                    continue;
                if (tile->terrainType & TERRAIN_TYPE_UNBREAKABLE)
                    continue;
                if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_ITEM)
                    continue;
                if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_MONSTER)
                    continue;
                if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_TRAP)
                    continue;

                validSpawns[count].x = x;
                validSpawns[count].y = y;
                count++;
            }
		}

		if (count != 0) {
            // Randomly select one of the valid tiles to spawn the player on
            s32 spawnIndex = DungeonRandInt(count);
            dungeon->playerSpawn.x = validSpawns[spawnIndex].x;
            dungeon->playerSpawn.y = validSpawns[spawnIndex].y;
		}
	}
}

/*
 * SpawnEnemies - Spawns all enemies, including those in forced monster houses
 */
static void SpawnEnemies(FloorProperties *floorProps, bool8 isEmptyMonsterHouse)
{
	struct PositionU8 validSpawns[DUNGEON_MAX_SIZE_X * DUNGEON_MAX_SIZE_Y];
    s32 count;
    s32 randIndex;
    s32 i;
    s32 x, y;
    Dungeon *dungeon = gDungeon;
    s32 numEnemies, numMonsterHouseEnemies;
    s32 enemyDensity = floorProps->enemyDensity;

	if (enemyDensity > 0) {
		// Positive means value with variance
		numEnemies = DungeonRandRange(enemyDensity / 2, enemyDensity);

		if (numEnemies < 1) {
            numEnemies = 1;
		}
	}
	else {
        // Negative means exact value.
		numEnemies = abs(enemyDensity);
	}

    count = 0;
	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            // Enemies can spawn on tiles that are:
            // - Open Terrain
            // - In a room
            // - Not in a Kecleon Shop
            // - Don't have stairs, an item
            // - Not a special tile that can't be broken by Absolute Mover
            // - Not where the player spawns
            const Tile *tile = GetTile(x, y);
            if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
                continue;
            if (tile->room == CORRIDOR_ROOM)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_SHOP)
                continue;
            if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_ITEM)
                continue;
            if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_STAIRS)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_UNBREAKABLE)
                continue;
            if (x == dungeon->playerSpawn.x && y == dungeon->playerSpawn.y)
                continue;

            validSpawns[count].x = x;
            validSpawns[count].y = y;
            count++;
		}
	}

	if (count != 0) {
        // ?
        if (gDungeon->unk644.unk44) {
            numEnemies++;
        }
        if (numEnemies != 0) {
            // Randomly select among the valid enemy spawn spots
            ShuffleSpawnPositions(validSpawns, count);
            randIndex = DungeonRandInt(count);

            for (i = 0; i < numEnemies; i++) {
                Tile *tile = GetTileMut(validSpawns[randIndex].x, validSpawns[randIndex].y);
                 // Spawn an enemy here
                tile->spawnOrVisibilityFlags |= SPAWN_FLAG_MONSTER;

                randIndex++;
                if (randIndex == count) {
                    // Wrap around to the start
                    randIndex = 0;
                }
            }
        }
	}

	if (!dungeon->forceMonsterHouse) {
		return;
	}

	// This floor was marked to force a monster house
	// Place extra enemy spawns in the Monster House room

	numMonsterHouseEnemies = gUnknown_80F4DA4;
    count = 0;
	if (isEmptyMonsterHouse) {
		// An "empty" monster house only spawns 3 enemies
		numMonsterHouseEnemies = 3;
	}

	numMonsterHouseEnemies = (numMonsterHouseEnemies * 3) / 2;

	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        s32 y;
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            // Monster House enemies can spawn on tiles that are:
            // - Open Terrain
            // - In a room
            // - Not in a Kecleon Shop
            // - Not a special tile that can't be broken by Absolute Mover
            // - Not where the player spawns
            // - In the monster house room

            const Tile *tile = GetTile(x, y);
            if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL)
                continue;
            if (tile->room == CORRIDOR_ROOM)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_SHOP)
                continue;
            if (tile->terrainType & TERRAIN_TYPE_UNBREAKABLE)
                continue;
            if (!(tile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE))
                continue;
            if (x == dungeon->playerSpawn.x && y == dungeon->playerSpawn.y)
                continue;

            validSpawns[count].x = x;
            validSpawns[count].y = y;
            count++;
		}
	}

	if (count != 0) {
		numEnemies = DungeonRandRange((7 * count) / 10, (8 * count) / 10);

        if (numEnemies == 0) {
            numEnemies = 1;
        }

		if (numEnemies >= numMonsterHouseEnemies) {
            // Don't spawn more enemies than the designated limit
            numEnemies = numMonsterHouseEnemies;
		}

		// Randomly select among the valid enemy spawn spots
        ShuffleSpawnPositions(validSpawns, count);
        randIndex = DungeonRandInt(count);

        for (i = 0; i < numEnemies; i++) {
            Tile *tile = GetTileMut(validSpawns[randIndex].x, validSpawns[randIndex].y);
             // Spawn an enemy here
            tile->spawnOrVisibilityFlags |= SPAWN_FLAG_MONSTER;

            randIndex++;
            if (randIndex == count) {
                // Wrap around to the start
                randIndex = 0;
            }
        }
	}
}

/*
 * SetSecondaryTerrainOnWall - Set a specific tile to have secondary terrain if the tile
 * is a passable wall.
 */
void SetSecondaryTerrainOnWall(Tile *tile)
{
    bool8 isWall = TRUE;
    if (GetTerrainType(tile) != TERRAIN_TYPE_WALL)
        isWall = FALSE;
    if (tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
        isWall = FALSE;

    if (isWall) {
        SetTerrainSecondary(tile);
    }
}

/*
 * GenerateSecondaryTerrainFormations - Generates secondary terrain (water/lava) formations
 *
 * This generation includes rivers, lakes along the river path, and standalone lakes.
 *
 * The river flows from top-to-bottom or bottom-to-top, using a random walk ending when the walk
 * goes out of bounds or finds existing secondary terrain. Because of this, rivers can end prematurely
 * when a lake is generated.
 *
 * Lakes are a large collection of secondary terrain generated around a central point.
 * Standalone lakes are generated based on secondary_terrain_density
 *
 * The formations will never cut into room tiles, but can pass through to the other side.
 */
extern const s32 gUnknown_80F6DF8[8];
// This function IS IMPOSSIBLE TO MATCH! Tried with 3 different compiler outputs and got nothing. Functionally it is the same, for the gba it's just a stack difference.
// https://decomp.me/scratch/9E4Uj - Red
// https://decomp.me/scratch/sA4YH - Blue
// https://decomp.me/scratch/SNyV8 - Sky
#ifdef NONMATCHING
static void GenerateSecondaryTerrainFormations(u32 flag, FloorProperties *floorProps)
{
    s32 densityN;
    s32 x, y;
    // Stack

    s32 numToGen;
    s32 numTilesFill;

	if (!(floorProps->roomFlags & flag))
        return;

	// Generate 1-3 "river+lake" formations
    for (numToGen = gUnknown_80F6DF8[DungeonRandInt(ARRAY_COUNT(gUnknown_80F6DF8))]; numToGen != 0; numToGen--) {
        s32 dirX, dirY;
        bool8 upwards;
        s32 stepsUntilLake;
        s32 j;
        s32 offsetX;
        s32 offsetY;

        // Randomly pick between starting from the bottom going up, or from the top going down
		if (DungeonRandInt(100) < 50) {
            upwards = TRUE;
            y = DUNGEON_MAX_SIZE_Y - 1;
            dirY = -1;
		}
		else {
		    upwards = FALSE;
            y = 0;
            dirY = 1;
		}

		stepsUntilLake = DungeonRandInt(50) + 10;

		// Pick a random column in the interior to start the river on
		x = DungeonRandRange(2, DUNGEON_MAX_SIZE_X - 2);
		dirX = 0;

		while (1) {
            // Fill in tiles in chunks of size 2-7 before changing the flow direction
            numTilesFill = DungeonRandInt(6) + 2;
            while (numTilesFill != 0) {
            	if (x >= 0 && x < DUNGEON_MAX_SIZE_X) {
            		if (GetTerrainType(GetTile(x, y)) == TERRAIN_TYPE_SECONDARY) {
                        goto LABEL;
            		}
                    if (!PosIsOutOfBounds(x, y)) {
                        // Fill in secondary terrain as we go
                        SetSecondaryTerrainOnWall(GetTileMut(x, y));
                    }
            	}
                numTilesFill--;

            	// Move to the next tile
            	x += dirX;
            	y += dirY;

            	// Vertically out of bounds, stop
            	if (y < 0 || y >= DUNGEON_MAX_SIZE_Y) {
                    break;
            	}

            	stepsUntilLake--;
            	if (stepsUntilLake != 0)
                    continue;

            	// After we go a certain number of steps, make a "lake"

            	// This loop will attempt to generate new lake tiles up to 64 times
            	// We select a random tile, check for space and nearby secondary terrain tiles,
            	// then if verified add a new lake tile.
            	for (j = 0; j < 64; j++) {
            		// Each tile is in a random location +-3 tiles from the current cursor in either direction
            		s32 offsetX = DungeonRandInt(7) - 3;
            		s32 offsetY = DungeonRandInt(7) - 3;

                    // Check that there's enough space for a lake within a 2 tile margin of the map bounds
                    if (offsetX + x < 2 || offsetX + x >= DUNGEON_MAX_SIZE_X - 2 || offsetY + y < 2 || offsetY + y >= DUNGEON_MAX_SIZE_Y - 2)
                        continue;

                    // Make secondary terrain here if it's within 2 tiles
                    // of a tile that's currently secondary terrain
                    // This results in a "cluster" akin to a lake
                    if (GetTerrainType(GetTile(offsetX + x + 1, offsetY + y + 1)) == TERRAIN_TYPE_SECONDARY ||
                        GetTerrainType(GetTile(offsetX + x + 1, offsetY + y + 0)) == TERRAIN_TYPE_SECONDARY ||
                        GetTerrainType(GetTile(offsetX + x + 1, offsetY + y - 1)) == TERRAIN_TYPE_SECONDARY ||
                        GetTerrainType(GetTile(offsetX + x + 0, offsetY + y + 1)) == TERRAIN_TYPE_SECONDARY ||
                        GetTerrainType(GetTile(offsetX + x + 0, offsetY + y - 1)) == TERRAIN_TYPE_SECONDARY ||
                        GetTerrainType(GetTile(offsetX + x - 1, offsetY + y + 1)) == TERRAIN_TYPE_SECONDARY ||
                        GetTerrainType(GetTile(offsetX + x - 1, offsetY + y + 0)) == TERRAIN_TYPE_SECONDARY ||
                        GetTerrainType(GetTile(offsetX + x - 1, offsetY + y - 1)) == TERRAIN_TYPE_SECONDARY)
                    {
                        if (!PosIsOutOfBounds(x + offsetX, y + offsetY)) {
                            SetSecondaryTerrainOnWall(GetTileMut(offsetX + x, offsetY + y));
                        }
                    }
            	}

            	// Finalization/gap-filling step because the random approach
            	// might leave weird gaps. Go through every tile and do an
            	// on line nearest-neighbor interpolation of secondary terrain
            	// tiles to smoothen out the "lake"
            	for (offsetX = -3; offsetX <= 3; offsetX++) {

            		for (offsetY = -3; offsetY <= 3; offsetY++) {
                        s32 numAdjacent = 0;
                        s32 xPlus1, yPlus1;

                        if (offsetX + x < 2 || offsetX + x >= DUNGEON_MAX_SIZE_X - 2 || offsetY + y < 2 || offsetY + y >= DUNGEON_MAX_SIZE_Y - 2)
                            continue;

                        // Count the number of secondary terrain tiles adjacent (all 8 directions)
                        xPlus1 = offsetX + x + 1;
                        yPlus1 = offsetY + y + 1;

                        if (GetTerrainType(GetTile(xPlus1, yPlus1)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;
                        if (GetTerrainType(GetTile(offsetX + x + 1, offsetY + y + 0)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;
                        if (GetTerrainType(GetTile(offsetX + x + 1, offsetY + y - 1)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;
                        if (GetTerrainType(GetTile(offsetX + x + 0, offsetY + y + 1)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;
                        if (GetTerrainType(GetTile(offsetX + x + 0, offsetY + y - 1)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;
                        if (GetTerrainType(GetTile(offsetX + x - 1, offsetY + y + 1)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;
                        if (GetTerrainType(GetTile(offsetX + x - 1, offsetY + y + 0)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;
                        if (GetTerrainType(GetTile(offsetX + x - 1, offsetY + y - 1)) == TERRAIN_TYPE_SECONDARY) numAdjacent++;

                        // If at least half are secondary terrain, make this tile secondary terrain as well
                        if (numAdjacent >= 4 && !PosIsOutOfBounds(x + offsetX , y + offsetY)) {
                            SetSecondaryTerrainOnWall(GetTileMut(offsetX + x , offsetY + y));
                        }
            		}
            	}
            }

            // Creating a lake doesn't mean we are done yet
            // but it's likely that the next iteration will hit the tile
            // stopping condition for secondary terrain, if not the river continues

            // Alternate between horizontal and vertical movement each iteration
            if (dirX != 0) {
                // The y direction never reverses, ensuring the river doesn't
                // double back on itself and cuts across the map only once
                if (upwards) {
                    dirY = -1;
                }
                else {
                    dirY = 1;
                }

                dirX = 0;
            }
            else {
                //Randomly pick between left and right
                if (DungeonRandInt(100) < 50) {
                    dirX = -1;
                }
                else {
                    dirX = 1;
                }

                dirY = 0;
            }

            if (y < 0 || y >= DUNGEON_MAX_SIZE_Y) {
                LABEL:
            	// Vertically out of bounds, stop
            	break;
            }
		}
    }

	// Generate standalone lakes secondary_terrain_density # of times
	for (densityN = 0; densityN < floorProps->unk15; densityN++) {
        s32 x, y;
        bool8 table[10][10];
		// Try to pick a random tile in the interior to seed the "lake"
		// Incredibly unlikely to fail
        s32 rndY = 0;
		s32 rndX = 0;
        s32 n = 0;

        // Up to 200 attempts
		while (n < 200) {
            rndX = DungeonRandRange(0, DUNGEON_MAX_SIZE_X);
            rndY = DungeonRandRange(0, DUNGEON_MAX_SIZE_Y);

            if (rndX >= 1 && rndX < DUNGEON_MAX_SIZE_X - 1 && rndY >= 1 && rndY < DUNGEON_MAX_SIZE_Y - 1)
                break;

            n++;
		}

		if (n == 200)
            continue;

		// Make a 10x10 grid with TRUE on the boundary and FALSE on the interior
		for (x = 0; x < 10; x++) {
            for (y = 0; y < 10; y++) {
            	if (x == 0 || x == 9 || y == 0 || y == 9) {
            		table[x][y] = TRUE;
            	}
            	else {
            		table[x][y] = FALSE;
            	}
            }
		}

		// Generate an "inverse lake" by spreading the TRUE values inwards
		for (n = 0; n < 80; n++) {
            // Pick a random interior point on the 10x10 grid
            x = DungeonRandInt(8) + 1;
            y = DungeonRandInt(8) + 1;

            if (table[x - 1][y] || table[x + 1][y] || table[x][y - 1] || table[x][y + 1]) {
            	table[x][y] = TRUE;
            }
		}

		// Iterate through the grid, any spaces which are still FALSE form the inverse-inverse lake
		// or as some may prefer to call it, just a regular lake!
		for (x = 0; x < 10; x++) {
            for (y = 0; y < 10; y++) {
            	if (!table[x][y]) {
            		// Shift the 0-10 random offset Position into +- 5 to center around the lake seed tile
                    SetSecondaryTerrainOnWall(GetTileMut(x + rndX - 5, y + rndY - 5));
            	}
            }
		}
	}

	// Clean up secondary terrain that got in places it shouldn't
	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            Tile *tile = GetTileMut(x, y);
            if (GetTerrainType(tile) != TERRAIN_TYPE_SECONDARY)
                continue;

            // Revert tiles back to open terrain if:
            // - in a kecleon shop
            // - in a monster house
            // - is an unbreakable tile
            // - on a stairs spawn point
            // This really shouldn't happen since we only place terrain on wall tiles to begin with,
            // but it provides additional safety

            if (tile->terrainType & (TERRAIN_TYPE_SHOP | TERRAIN_TYPE_IN_MONSTER_HOUSE | TERRAIN_TYPE_UNBREAKABLE) || (tile->spawnOrVisibilityFlags & SPAWN_FLAG_STAIRS)) {
                SetTerrainNormal(tile);
            }
            else {
                // Revert to wall tiles if they're on the soft/hard borders
                if (x <= 1 || x >= DUNGEON_MAX_SIZE_X - 1 || y <= 1 || y >= DUNGEON_MAX_SIZE_Y - 1) {
                    SetTerrainWall(tile);
                }
            }
		}
	}
}

#else
NAKED static void GenerateSecondaryTerrainFormations(u32 flag, FloorProperties *floorProps)
{
    asm_unified("\n"
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0xA4\n"
"	str r1, [sp, 0x64]\n"
"	ldrb r1, [r1, 0xD]\n"
"	ands r1, r0\n"
"	cmp r1, 0\n"
"	bne _08050708\n"
"	b _08050C20\n"
"_08050708:\n"
"	ldr r4, _08050738\n"
"	movs r0, 0x8\n"
"	bl DungeonRandInt\n"
"	lsls r0, 2\n"
"	adds r0, r4\n"
"	ldr r4, [r0]\n"
"	cmp r4, 0\n"
"	bne _0805071C\n"
"	b _08050A7C\n"
"_0805071C:\n"
"	movs r0, 0x64\n"
"	bl DungeonRandInt\n"
"	cmp r0, 0x31\n"
"	bgt _0805073C\n"
"	movs r0, 0x1\n"
"	str r0, [sp, 0x74]\n"
"	movs r1, 0x1F\n"
"	mov r10, r1\n"
"	movs r2, 0x1\n"
"	negs r2, r2\n"
"	str r2, [sp, 0x70]\n"
"	b _08050746\n"
"	.align 2, 0\n"
"_08050738: .4byte gUnknown_80F6DF8\n"
"_0805073C:\n"
"	movs r0, 0\n"
"	str r0, [sp, 0x74]\n"
"	mov r10, r0\n"
"	movs r1, 0x1\n"
"	str r1, [sp, 0x70]\n"
"_08050746:\n"
"	movs r0, 0x32\n"
"	bl DungeonRandInt\n"
"	adds r0, 0xA\n"
"	str r0, [sp, 0x78]\n"
"	movs r0, 0x2\n"
"	movs r1, 0x36\n"
"	bl DungeonRandRange\n"
"	mov r9, r0\n"
"	movs r2, 0\n"
"	str r2, [sp, 0x6C]\n"
"	subs r4, 0x1\n"
"	str r4, [sp, 0x98]\n"
"_08050762:\n"
"	movs r0, 0x6\n"
"	bl DungeonRandInt\n"
"	adds r0, 0x2\n"
"	str r0, [sp, 0x68]\n"
"	cmp r0, 0\n"
"	bne _08050772\n"
"	b _08050A38\n"
"_08050772:\n"
"	mov r0, r9\n"
"	cmp r0, 0x37\n"
"	bhi _080507B8\n"
"	mov r1, r10\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	movs r0, 0x3\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	bne _0805078A\n"
"	b _08050A74\n"
"_0805078A:\n"
"	mov r1, r9\n"
"	cmp r1, 0\n"
"	blt _080507A2\n"
"	mov r2, r10\n"
"	cmp r2, 0\n"
"	blt _080507A2\n"
"	mov r0, r9\n"
"	cmp r0, 0x37\n"
"	bgt _080507A2\n"
"	mov r1, r10\n"
"	cmp r1, 0x1F\n"
"	ble _080507A6\n"
"_080507A2:\n"
"	movs r0, 0x1\n"
"	b _080507A8\n"
"_080507A6:\n"
"	movs r0, 0\n"
"_080507A8:\n"
"	cmp r0, 0\n"
"	bne _080507B8\n"
"	mov r0, r9\n"
"	mov r1, r10\n"
"	bl GetTileMut\n"
"	bl SetSecondaryTerrainOnWall\n"
"_080507B8:\n"
"	ldr r2, [sp, 0x68]\n"
"	subs r2, 0x1\n"
"	str r2, [sp, 0x68]\n"
"	ldr r0, [sp, 0x6C]\n"
"	add r9, r0\n"
"	ldr r1, [sp, 0x70]\n"
"	add r10, r1\n"
"	mov r2, r10\n"
"	cmp r2, 0x1F\n"
"	bls _080507CE\n"
"	b _08050A38\n"
"_080507CE:\n"
"	ldr r0, [sp, 0x78]\n"
"	subs r0, 0x1\n"
"	str r0, [sp, 0x78]\n"
"	cmp r0, 0\n"
"	beq _080507DA\n"
"	b _08050A30\n"
"_080507DA:\n"
"	movs r1, 0x3F\n"
"	str r1, [sp, 0x7C]\n"
"_080507DE:\n"
"	movs r0, 0x7\n"
"	bl DungeonRandInt\n"
"	subs r0, 0x3\n"
"	str r0, [sp, 0x84]\n"
"	movs r0, 0x7\n"
"	bl DungeonRandInt\n"
"	subs r1, r0, 0x3\n"
"	ldr r6, [sp, 0x84]\n"
"	add r6, r9\n"
"	subs r0, r6, 0x2\n"
"	cmp r0, 0x33\n"
"	bhi _080508DA\n"
"	mov r2, r10\n"
"	adds r5, r1, r2\n"
"	cmp r5, 0x1\n"
"	ble _080508DA\n"
"	cmp r5, 0x1D\n"
"	bgt _080508DA\n"
"	adds r4, r6, 0x1\n"
"	adds r0, r5, 0x1\n"
"	mov r8, r0\n"
"	adds r0, r4, 0\n"
"	mov r1, r8\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	movs r2, 0x3\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	beq _080508B2\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	str r2, [sp, 0x9C]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	ldr r2, [sp, 0x9C]\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	beq _080508B2\n"
"	subs r7, r5, 0x1\n"
"	adds r0, r4, 0\n"
"	adds r1, r7, 0\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	ldr r2, [sp, 0x9C]\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	beq _080508B2\n"
"	adds r0, r6, 0\n"
"	mov r1, r8\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	ldr r2, [sp, 0x9C]\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	beq _080508B2\n"
"	adds r0, r6, 0\n"
"	adds r1, r7, 0\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	ldr r2, [sp, 0x9C]\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	beq _080508B2\n"
"	subs r4, r6, 0x1\n"
"	adds r0, r4, 0\n"
"	mov r1, r8\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	ldr r2, [sp, 0x9C]\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	beq _080508B2\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	ldr r2, [sp, 0x9C]\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	beq _080508B2\n"
"	adds r0, r4, 0\n"
"	adds r1, r7, 0\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	ldr r2, [sp, 0x9C]\n"
"	adds r0, r2, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	bne _080508DA\n"
"_080508B2:\n"
"	ldr r0, [sp, 0x84]\n"
"	add r0, r9\n"
"	cmp r0, 0\n"
"	blt _080508C6\n"
"	cmp r5, 0\n"
"	blt _080508C6\n"
"	cmp r0, 0x37\n"
"	bgt _080508C6\n"
"	cmp r5, 0x1F\n"
"	ble _080508CA\n"
"_080508C6:\n"
"	movs r1, 0x1\n"
"	b _080508CC\n"
"_080508CA:\n"
"	movs r1, 0\n"
"_080508CC:\n"
"	cmp r1, 0\n"
"	bne _080508DA\n"
"	adds r1, r5, 0\n"
"	bl GetTileMut\n"
"	bl SetSecondaryTerrainOnWall\n"
"_080508DA:\n"
"	ldr r1, [sp, 0x7C]\n"
"	subs r1, 0x1\n"
"	str r1, [sp, 0x7C]\n"
"	cmp r1, 0\n"
"	blt _080508E6\n"
"	b _080507DE\n"
"_080508E6:\n"
"	movs r0, 0x3\n"
"	negs r0, r0\n"
"_080508EA:\n"
"	movs r2, 0x3\n"
"	negs r2, r2\n"
"	str r2, [sp, 0x80]\n"
"	mov r1, r9\n"
"	adds r1, r0, r1\n"
"	str r1, [sp, 0x90]\n"
"	adds r0, 0x1\n"
"	str r0, [sp, 0x8C]\n"
"	adds r7, r1, 0\n"
"	mov r5, r10\n"
"	subs r5, 0x3\n"
"_08050900:\n"
"	movs r6, 0\n"
"	subs r0, r7, 0x2\n"
"	cmp r0, 0x33\n"
"	bls _0805090A\n"
"	b _08050A1A\n"
"_0805090A:\n"
"	str r5, [sp, 0x88]\n"
"	str r5, [sp, 0x94]\n"
"	cmp r5, 0x1\n"
"	bgt _08050914\n"
"	b _08050A1A\n"
"_08050914:\n"
"	cmp r5, 0x1D\n"
"	ble _0805091A\n"
"	b _08050A1A\n"
"_0805091A:\n"
"	adds r4, r7, 0x1\n"
"	adds r3, r5, 0x1\n"
"	adds r0, r4, 0\n"
"	adds r1, r3, 0\n"
"	str r3, [sp, 0xA0]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	movs r2, 0x3\n"
"	mov r8, r2\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	ldr r3, [sp, 0xA0]\n"
"	cmp r0, 0x2\n"
"	bne _0805093A\n"
"	movs r6, 0x1\n"
"_0805093A:\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	str r3, [sp, 0xA0]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	ldr r3, [sp, 0xA0]\n"
"	cmp r0, 0x2\n"
"	bne _08050952\n"
"	adds r6, 0x1\n"
"_08050952:\n"
"	subs r2, r5, 0x1\n"
"	adds r0, r4, 0\n"
"	adds r1, r2, 0\n"
"	str r2, [sp, 0x9C]\n"
"	str r3, [sp, 0xA0]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	ldr r2, [sp, 0x9C]\n"
"	ldr r3, [sp, 0xA0]\n"
"	cmp r0, 0x2\n"
"	bne _08050970\n"
"	adds r6, 0x1\n"
"_08050970:\n"
"	adds r0, r7, 0\n"
"	adds r1, r3, 0\n"
"	str r2, [sp, 0x9C]\n"
"	str r3, [sp, 0xA0]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	ldr r2, [sp, 0x9C]\n"
"	ldr r3, [sp, 0xA0]\n"
"	cmp r0, 0x2\n"
"	bne _0805098C\n"
"	adds r6, 0x1\n"
"_0805098C:\n"
"	adds r0, r7, 0\n"
"	adds r1, r2, 0\n"
"	str r2, [sp, 0x9C]\n"
"	str r3, [sp, 0xA0]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	ldr r2, [sp, 0x9C]\n"
"	ldr r3, [sp, 0xA0]\n"
"	cmp r0, 0x2\n"
"	bne _080509A8\n"
"	adds r6, 0x1\n"
"_080509A8:\n"
"	subs r4, r7, 0x1\n"
"	adds r0, r4, 0\n"
"	adds r1, r3, 0\n"
"	str r2, [sp, 0x9C]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	ldr r2, [sp, 0x9C]\n"
"	cmp r0, 0x2\n"
"	bne _080509C2\n"
"	adds r6, 0x1\n"
"_080509C2:\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	str r2, [sp, 0x9C]\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	ldr r2, [sp, 0x9C]\n"
"	cmp r0, 0x2\n"
"	bne _080509DA\n"
"	adds r6, 0x1\n"
"_080509DA:\n"
"	adds r0, r4, 0\n"
"	adds r1, r2, 0\n"
"	bl GetTile\n"
"	ldrh r1, [r0]\n"
"	mov r0, r8\n"
"	ands r0, r1\n"
"	cmp r0, 0x2\n"
"	bne _080509EE\n"
"	adds r6, 0x1\n"
"_080509EE:\n"
"	cmp r6, 0x3\n"
"	ble _08050A1A\n"
"	cmp r7, 0\n"
"	blt _08050A04\n"
"	cmp r5, 0\n"
"	blt _08050A04\n"
"	cmp r7, 0x37\n"
"	bgt _08050A04\n"
"	ldr r0, [sp, 0x88]\n"
"	cmp r0, 0x1F\n"
"	ble _08050A08\n"
"_08050A04:\n"
"	movs r0, 0x1\n"
"	b _08050A0A\n"
"_08050A08:\n"
"	movs r0, 0\n"
"_08050A0A:\n"
"	cmp r0, 0\n"
"	bne _08050A1A\n"
"	ldr r0, [sp, 0x90]\n"
"	ldr r1, [sp, 0x94]\n"
"	bl GetTileMut\n"
"	bl SetSecondaryTerrainOnWall\n"
"_08050A1A:\n"
"	adds r5, 0x1\n"
"	ldr r1, [sp, 0x80]\n"
"	adds r1, 0x1\n"
"	str r1, [sp, 0x80]\n"
"	cmp r1, 0x3\n"
"	bgt _08050A28\n"
"	b _08050900\n"
"_08050A28:\n"
"	ldr r0, [sp, 0x8C]\n"
"	cmp r0, 0x3\n"
"	bgt _08050A30\n"
"	b _080508EA\n"
"_08050A30:\n"
"	ldr r2, [sp, 0x68]\n"
"	cmp r2, 0\n"
"	beq _08050A38\n"
"	b _08050772\n"
"_08050A38:\n"
"	ldr r0, [sp, 0x6C]\n"
"	cmp r0, 0\n"
"	beq _08050A54\n"
"	movs r1, 0x1\n"
"	str r1, [sp, 0x70]\n"
"	ldr r2, [sp, 0x74]\n"
"	cmp r2, 0\n"
"	beq _08050A4E\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	str r0, [sp, 0x70]\n"
"_08050A4E:\n"
"	movs r1, 0\n"
"	str r1, [sp, 0x6C]\n"
"	b _08050A6C\n"
"_08050A54:\n"
"	movs r0, 0x64\n"
"	bl DungeonRandInt\n"
"	movs r2, 0x1\n"
"	str r2, [sp, 0x6C]\n"
"	cmp r0, 0x31\n"
"	bgt _08050A68\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	str r0, [sp, 0x6C]\n"
"_08050A68:\n"
"	movs r1, 0\n"
"	str r1, [sp, 0x70]\n"
"_08050A6C:\n"
"	mov r2, r10\n"
"	cmp r2, 0x1F\n"
"	bhi _08050A74\n"
"	b _08050762\n"
"_08050A74:\n"
"	ldr r4, [sp, 0x98]\n"
"	cmp r4, 0\n"
"	beq _08050A7C\n"
"	b _0805071C\n"
"_08050A7C:\n"
"	movs r0, 0\n"
"	ldr r1, [sp, 0x64]\n"
"	ldrb r1, [r1, 0x15]\n"
"	cmp r0, r1\n"
"	blt _08050A88\n"
"	b _08050BAE\n"
"_08050A88:\n"
"	movs r2, 0\n"
"	mov r8, r2\n"
"	mov r9, r2\n"
"	movs r5, 0\n"
"	adds r0, 0x1\n"
"	mov r10, r0\n"
"	b _08050A98\n"
"_08050A96:\n"
"	adds r5, 0x1\n"
"_08050A98:\n"
"	cmp r5, 0xC7\n"
"	bgt _08050AC2\n"
"	movs r0, 0\n"
"	movs r1, 0x38\n"
"	bl DungeonRandRange\n"
"	mov r9, r0\n"
"	movs r0, 0\n"
"	movs r1, 0x20\n"
"	bl DungeonRandRange\n"
"	mov r8, r0\n"
"	mov r0, r9\n"
"	subs r0, 0x1\n"
"	cmp r0, 0x35\n"
"	bhi _08050A96\n"
"	mov r0, r8\n"
"	cmp r0, 0\n"
"	ble _08050A96\n"
"	cmp r0, 0x1E\n"
"	bgt _08050A96\n"
"_08050AC2:\n"
"	cmp r5, 0xC8\n"
"	beq _08050BA2\n"
"	movs r7, 0\n"
"	movs r3, 0x1\n"
"	movs r1, 0\n"
"_08050ACC:\n"
"	movs r2, 0\n"
"	lsls r0, r7, 2\n"
"	adds r4, r7, 0x1\n"
"	adds r0, r7\n"
"	lsls r0, 1\n"
"	add r0, sp\n"
"_08050AD8:\n"
"	cmp r7, 0\n"
"	beq _08050AE8\n"
"	cmp r7, 0x9\n"
"	beq _08050AE8\n"
"	cmp r2, 0\n"
"	beq _08050AE8\n"
"	cmp r2, 0x9\n"
"	bne _08050AEC\n"
"_08050AE8:\n"
"	strb r3, [r0]\n"
"	b _08050AEE\n"
"_08050AEC:\n"
"	strb r1, [r0]\n"
"_08050AEE:\n"
"	adds r0, 0x1\n"
"	adds r2, 0x1\n"
"	cmp r2, 0x9\n"
"	ble _08050AD8\n"
"	adds r7, r4, 0\n"
"	cmp r7, 0x9\n"
"	ble _08050ACC\n"
"	movs r5, 0x4F\n"
"_08050AFE:\n"
"	movs r0, 0x8\n"
"	bl DungeonRandInt\n"
"	adds r4, r0, 0\n"
"	adds r7, r4, 0x1\n"
"	movs r0, 0x8\n"
"	bl DungeonRandInt\n"
"	adds r2, r0, 0x1\n"
"	lsls r0, r4, 2\n"
"	adds r0, r4\n"
"	lsls r0, 1\n"
"	adds r0, r2, r0\n"
"	add r0, sp\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _08050B50\n"
"	adds r1, r7, 0x1\n"
"	lsls r0, r1, 2\n"
"	adds r0, r1\n"
"	lsls r0, 1\n"
"	adds r0, r2, r0\n"
"	add r0, sp\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _08050B50\n"
"	lsls r0, r7, 2\n"
"	adds r0, r7\n"
"	lsls r1, r0, 1\n"
"	subs r0, r1, 0x1\n"
"	adds r0, r2, r0\n"
"	add r0, sp\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _08050B50\n"
"	adds r0, r1, 0x1\n"
"	adds r0, r2, r0\n"
"	add r0, sp\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	beq _08050B60\n"
"_08050B50:\n"
"	lsls r0, r7, 2\n"
"	adds r0, r7\n"
"	lsls r0, 1\n"
"	adds r0, r2, r0\n"
"	mov r2, sp\n"
"	adds r1, r2, r0\n"
"	movs r0, 0x1\n"
"	strb r0, [r1]\n"
"_08050B60:\n"
"	subs r5, 0x1\n"
"	cmp r5, 0\n"
"	bge _08050AFE\n"
"	movs r7, 0\n"
"_08050B68:\n"
"	lsls r0, r7, 2\n"
"	adds r4, r7, 0x1\n"
"	adds r0, r7\n"
"	lsls r0, 1\n"
"	mov r6, r8\n"
"	subs r6, 0x5\n"
"	mov r1, sp\n"
"	adds r5, r0, r1\n"
"	add r7, r9\n"
"	movs r2, 0x9\n"
"_08050B7C:\n"
"	ldrb r0, [r5]\n"
"	cmp r0, 0\n"
"	bne _08050B92\n"
"	subs r0, r7, 0x5\n"
"	adds r1, r6, 0\n"
"	str r2, [sp, 0x9C]\n"
"	bl GetTileMut\n"
"	bl SetSecondaryTerrainOnWall\n"
"	ldr r2, [sp, 0x9C]\n"
"_08050B92:\n"
"	adds r6, 0x1\n"
"	adds r5, 0x1\n"
"	subs r2, 0x1\n"
"	cmp r2, 0\n"
"	bge _08050B7C\n"
"	adds r7, r4, 0\n"
"	cmp r7, 0x9\n"
"	ble _08050B68\n"
"_08050BA2:\n"
"	mov r0, r10\n"
"	ldr r2, [sp, 0x64]\n"
"	ldrb r2, [r2, 0x15]\n"
"	cmp r0, r2\n"
"	bge _08050BAE\n"
"	b _08050A88\n"
"_08050BAE:\n"
"	movs r0, 0\n"
"	mov r9, r0\n"
"	movs r6, 0x1\n"
"	ldr r1, _08050BF4\n"
"	adds r5, r1, 0\n"
"_08050BB8:\n"
"	movs r2, 0\n"
"	mov r10, r2\n"
"	mov r4, r9\n"
"	adds r4, 0x1\n"
"_08050BC0:\n"
"	mov r0, r9\n"
"	mov r1, r10\n"
"	bl GetTileMut\n"
"	adds r2, r0, 0\n"
"	ldrh r3, [r2]\n"
"	movs r0, 0x3\n"
"	ands r0, r3\n"
"	cmp r0, 0x2\n"
"	bne _08050C10\n"
"	movs r1, 0xB0\n"
"	lsls r1, 1\n"
"	adds r0, r1, 0\n"
"	ands r0, r3\n"
"	cmp r0, 0\n"
"	bne _08050BEA\n"
"	ldrh r1, [r2, 0x4]\n"
"	adds r0, r6, 0\n"
"	ands r0, r1\n"
"	cmp r0, 0\n"
"	beq _08050BF8\n"
"_08050BEA:\n"
"	adds r0, r3, 0\n"
"	ands r0, r5\n"
"	orrs r0, r6\n"
"	b _08050C0E\n"
"	.align 2, 0\n"
"_08050BF4: .4byte 0x0000fffc\n"
"_08050BF8:\n"
"	mov r0, r9\n"
"	subs r0, 0x2\n"
"	cmp r0, 0x34\n"
"	bhi _08050C0A\n"
"	mov r0, r10\n"
"	cmp r0, 0x1\n"
"	ble _08050C0A\n"
"	cmp r0, 0x1E\n"
"	ble _08050C10\n"
"_08050C0A:\n"
"	ldrh r0, [r2]\n"
"	ands r0, r5\n"
"_08050C0E:\n"
"	strh r0, [r2]\n"
"_08050C10:\n"
"	movs r1, 0x1\n"
"	add r10, r1\n"
"	mov r2, r10\n"
"	cmp r2, 0x1F\n"
"	ble _08050BC0\n"
"	mov r9, r4\n"
"	cmp r4, 0x37\n"
"	ble _08050BB8\n"
"_08050C20:\n"
"	add sp, 0xA4\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n");
}
#endif // NONMATCHING

#define STAIRS_FLAG_CANNOT_CORNER_CUT 0x1 // Set to `true` for non-open terrain tiles which have `TERRAIN_TYPE_CORNER_CUTTABLE` in their [TerrainFlags]
#define STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT 0x2 // Set to `true` for secondary terrain tiles which have `TERRAIN_TYPE_CORNER_CUTTABLE` in their [TerrainFlags]
#define STAIRS_FLAG_UNKNOWN 0x4 // Not fully understood field. Is tested in relation to corners, but appears to never be set to `true`.
#define STAIRS_FLAG_STARTING_POINT 0x10 // Determines the starting point for graph traversal, set to `true` on the Stairs tile.
#define STAIRS_FLAG_IN_VISIT_QUEUE 0x40 // Set to `true` for tiles which are currently queued to be visited.
#define STAIRS_FLAG_VISITED 0x80 // Set to `true` for tiles which have been visit

/*
 * StairsAlwaysReachable - Checks that the stairs are always reachable from every walkable tile on the floor
 *
 * Uses a graph-traversal similar to Breadth-First Search (but with slightly different order due to how
 * iteration works))
 *
 * If any tile is walkable but wasn't reached, this function will return FALSE.
 * If every tile was reached, this function will return TRUE.
 */
bool8 StairsAlwaysReachable(s32 stairsX, s32 stairsY, bool8 markUnreachable)
{
    s32 x, y;
	u8 test[DUNGEON_MAX_SIZE_X][DUNGEON_MAX_SIZE_Y];

	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
		    Tile *tile = GetTileMut(x, y);
            u16 terrain = GetTerrainType(tile);

            test[x][y] = 0;
            if (markUnreachable) {
            	// Reset all unreachable flags on tiles, they'll be recomputed from scratch
            	tile->terrainType &= ~(TERRAIN_TYPE_UNREACHABLE_FROM_STAIRS);
            }

            if (terrain != TERRAIN_TYPE_NORMAL) {
            	if (!(tile->terrainType & TERRAIN_TYPE_CORNER_CUTTABLE)) {
            		test[x][y] |= STAIRS_FLAG_CANNOT_CORNER_CUT;
            	}
            }

            if (terrain == TERRAIN_TYPE_SECONDARY) {
            	if (!(tile->terrainType & TERRAIN_TYPE_CORNER_CUTTABLE)) {
            		test[x][y] |= STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT;
            	}
            }
		}
	}

	test[stairsX][stairsY] |= STAIRS_FLAG_STARTING_POINT | STAIRS_FLAG_IN_VISIT_QUEUE;

	if (gDungeon->stairsSpawn.x != stairsX || gDungeon->stairsSpawn.y != stairsY) {
		return FALSE;
	}

	sNumTilesReachableFromStairs = 0;

	// Uses a semi-BFS starting from the stairs until all reachable tiles
	// have been visited
	while (1) {
        s32 checked = 0;
		sNumTilesReachableFromStairs += 1;

		for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            	if (!(test[x][y] & STAIRS_FLAG_VISITED) && test[x][y] & STAIRS_FLAG_IN_VISIT_QUEUE) {
            		checked++;
            		test[x][y] &= ~(STAIRS_FLAG_IN_VISIT_QUEUE);
            		test[x][y] |= STAIRS_FLAG_VISITED;

            		// Queue up in cardinal directions of this tile

            		// Left
            		if (x > 0 && !(test[x - 1][y] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED))) {
                        test[x - 1][y] |= STAIRS_FLAG_IN_VISIT_QUEUE;
            		}

            		// Up
            		if (y > 0 && !(test[x][y - 1] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED))) {
                        test[x][y - 1] |= STAIRS_FLAG_IN_VISIT_QUEUE;
            		}

            		// Right
            		if (x < DUNGEON_MAX_SIZE_X - 1 && !(test[x + 1][y] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED))) {
                        test[x + 1][y] |= STAIRS_FLAG_IN_VISIT_QUEUE;
            		}

            		// Down
            		if (y < DUNGEON_MAX_SIZE_Y - 1 && !(test[x][y + 1] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED))) {
                        test[x][y + 1] |= STAIRS_FLAG_IN_VISIT_QUEUE;
            		}

            		// Up-left
            		if (x > 0 && y > 0
                        && !(test[x - 1][y - 1] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED | STAIRS_FLAG_UNKNOWN))
                        && !(test[x - 1][y] & STAIRS_FLAG_CANNOT_CORNER_CUT)
                        && !(test[x][y - 1] & STAIRS_FLAG_CANNOT_CORNER_CUT))
                    {
                        test[x - 1][y - 1] |= STAIRS_FLAG_IN_VISIT_QUEUE;
                    }

            		// Up-Right
            		if (x < DUNGEON_MAX_SIZE_X - 1 && y > 0
                        && !(test[x + 1][y - 1] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED | STAIRS_FLAG_UNKNOWN))
                        && !(test[x + 1][y] & STAIRS_FLAG_CANNOT_CORNER_CUT)
                        && !(test[x][y - 1] & STAIRS_FLAG_CANNOT_CORNER_CUT))
                    {
                        test[x + 1][y - 1] |= STAIRS_FLAG_IN_VISIT_QUEUE;
                    }

            		// Down-left
            		if (x > 0 && y < DUNGEON_MAX_SIZE_Y - 1
                        && !(test[x - 1][y + 1] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED | STAIRS_FLAG_UNKNOWN))
                        && !(test[x - 1][y] & STAIRS_FLAG_CANNOT_CORNER_CUT)
                        && !(test[x][y + 1] & STAIRS_FLAG_CANNOT_CORNER_CUT))
                    {
                        test[x - 1][y + 1] |= STAIRS_FLAG_IN_VISIT_QUEUE;
                    }

            		// Down-right
            		if (x < DUNGEON_MAX_SIZE_X - 1 && y < DUNGEON_MAX_SIZE_Y - 1
                        && !(test[x + 1][y + 1] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_VISITED | STAIRS_FLAG_UNKNOWN))
                        && !(test[x + 1][y] & STAIRS_FLAG_CANNOT_CORNER_CUT)
                        && !(test[x][y + 1] & STAIRS_FLAG_CANNOT_CORNER_CUT))
                    {
                        test[x + 1][y + 1] |= STAIRS_FLAG_IN_VISIT_QUEUE;
                    }
            	}
            }
		}

        if (checked == 0)
            break;
	}

	for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
		for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            Tile *tile = GetTileMut(x, y);

            if (!(test[x][y] & (STAIRS_FLAG_CANNOT_CORNER_CUT | STAIRS_FLAG_SECONDARY_TERRAIN_CANNOT_CORNER_CUT | STAIRS_FLAG_UNKNOWN | STAIRS_FLAG_VISITED))) {
                // This is an open tile that wasn't visited by BFS, which means it's unreachable from the starting stairs
                if (markUnreachable) {
                    tile->terrainType |= TERRAIN_TYPE_UNREACHABLE_FROM_STAIRS;
                }
                else {
                    // unbreakable tiles can't really be navigated onto anyways, so if
            		// we can ignore the tile (otherwise it's a problem!)
            		if (!(tile->terrainType & TERRAIN_TYPE_UNBREAKABLE)) {
                        return FALSE;
            		}
                }
            }
		}
	}

	return TRUE;
}

static void CreateRoomsAndAnchorsForFixedFloor(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, s32 a5, s32 fixedRoomSizeX, s32 fixedRoomSizeY)
{
    s32 roomNumber = 0;
    s32 var_48 = 0;
    s32 x, y;

	for (y = 0; y < gridSizeY; y++) {
		for (x = 0; x < gridSizeX; var_48++, x++) {
            s32 minX = listX[x] + 2;
            s32 minY = listY[y] + 2;
            s32 rangeX = listX[x + 1] - listX[x] - 4;
            s32 rangeY = listY[y + 1] - listY[y] - 4;
            s32 minRoomSizeX = 5;
            s32 minRoomSizeY = 5;

            if (gridSizeX <= 2) {
                minRoomSizeX = 10;
                rangeX = 14;
            }
            if (gridSizeY == 1) {
                minRoomSizeY = 16;
                rangeY = 24;
            }

            if (grid[x][y].isRoom) {
                // This cell is a room!
                s32 roomSizeX, roomSizeY;
                s32 startX, endX;
                s32 startY, endY;
                s32 roomX, roomY;

                if (var_48 != a5) {
                    roomSizeX = DungeonRandRange(minRoomSizeX, rangeX);
                    roomSizeY = DungeonRandRange(minRoomSizeY, rangeY);

                    // Force small rooms to have odd-numbered dimensions (?)
                    if ((roomSizeX | 1) < rangeX) {
                        roomSizeX |= 1;
                    }

                    if ((roomSizeY | 1) < rangeY) {
                        roomSizeY |= 1;
                    }

                    // Aspect ratio 2/3 < x/y < 3/2
                    if (roomSizeX > (roomSizeY * 3) / 2) {
                        roomSizeX = (roomSizeY * 3) / 2;
                    }

                    if (roomSizeY > (roomSizeX * 3) / 2) {
                        roomSizeY = (roomSizeX * 3) / 2;
                    }

                    startX = DungeonRandInt(rangeX - roomSizeX) + minX;
                    startY = DungeonRandInt(rangeY - roomSizeY) + minY;
                    endX = startX + roomSizeX;
                    endY = startY + roomSizeY;
                }
                else {
                    startX = minX;
                    startY = minY;
                    endX = startX + fixedRoomSizeX;
                    endY = startY + fixedRoomSizeY;
                }

            	// Create the room!
            	grid[x][y].start.x = startX;
                grid[x][y].end.x = endX;
            	grid[x][y].start.y = startY;
            	grid[x][y].end.y = endY;

            	for (roomX = startX; roomX < endX; roomX++) {
            		for (roomY = startY; roomY < endY; roomY++) {
                        SetTerrainNormal(GetTileMut(roomX, roomY));
                        GetTileMut(roomX, roomY)->room = roomNumber;
            		}
            	}

            	if (var_48 != a5) {
                    grid[x][y].flagSecondaryStructure = TRUE;
            	}

            	roomNumber++;
            }
            else {
                // This cell is not a room, create a 1x1 hallway anchor
                s32 pt_x, pt_y;
                s32 unk_x1 = 2;
                s32 unk_x2 = 4;
                s32 unk_y1 = 2;
                s32 unk_y2 = 4;

            	if (x == 0) {
            		unk_x1 = 1;
            	}
            	if (y == 0) {
            		unk_y1 = 1;
            	}

                if (x == gridSizeX - 1) {
            		unk_x2 = 2;
            	}
            	if (y == gridSizeY - 1) {
            		unk_y2 = 2;
            	}

                pt_x = DungeonRandRange(minX + unk_x1, minX + rangeX - unk_x2);
                pt_y = DungeonRandRange(minY + unk_y1, minY + rangeY - unk_y2);

            	grid[x][y].start.x = pt_x;
                grid[x][y].end.x = pt_x + 1;
            	grid[x][y].start.y = pt_y;
            	grid[x][y].end.y = pt_y + 1;

            	// Flag the tile as open to serve as a hallway anchor
            	SetTerrainNormal(GetTileMut(pt_x, pt_y));

            	// Set the room index to 0xFE for anchor
            	GetTileMut(pt_x, pt_y)->room = CORRIDOR_ROOM;
            }
		}
	}
}

static EWRAM_DATA u8 *gUnknown_202F1DC = NULL;
static EWRAM_DATA u8 gUnknown_202F1E0 = 0;
static EWRAM_DATA u8 gUnknown_202F1E1 = 0;
static UNUSED EWRAM_DATA s32 sUnusedEwram = 0;

static u8 sub_80511F0(void)
{
    if (gUnknown_202F1E1 != 0) {
        gUnknown_202F1E1--;
        return gUnknown_202F1E0;
    }

    gUnknown_202F1E0 = *gUnknown_202F1DC;
    gUnknown_202F1DC++;
    if (gUnknown_202F1E0 == 14) {
        gUnknown_202F1E0 = *gUnknown_202F1DC;
        gUnknown_202F1DC++;
    }
    else {
        gUnknown_202F1E1 = gUnknown_202F1E0 & 0xF;
        gUnknown_202F1E0 = (gUnknown_202F1E0 & 0xF0) >> 4;
    }
    return gUnknown_202F1E0;
}

static bool8 PlaceFixedRoomTile(Tile *tile, u8 a1, s32 x, s32 y, u8 a5);
static bool8 sub_805210C(u8 itemId);

static bool8 sub_805124C(Tile *tile, u8 a1, s32 x, s32 y, u8 a5)
{
    tile->terrainType |= TERRAIN_TYPE_UNBREAKABLE;
    tile->unkE = 0;
    return PlaceFixedRoomTile(tile, a1, x, y, a5);
}

static void sub_8051288(s32 fixedRoomNumber)
{
    s32 x, y;
    Dungeon *dungeon = gDungeon;
    s32 fixedRoomSizeX = ((struct FixedRoomsData **)(dungeon->unk13568->data))[fixedRoomNumber]->x;
    s32 fixedRoomSizeY = ((struct FixedRoomsData **)(dungeon->unk13568->data))[fixedRoomNumber]->y;

    dungeon->unkE260.unk0 = fixedRoomSizeX;
    dungeon->unkE260.unk2 = fixedRoomSizeY;
    gUnknown_202F1DC = ((struct FixedRoomsData **)(dungeon->unk13568->data))[fixedRoomNumber]->unk3;
    gUnknown_202F1E1 = 0;

    for (y = 5; y < fixedRoomSizeY + 5; y++) {
        for (x = 5; x < fixedRoomSizeX + 5; x++) {
            u8 unk = sub_80511F0();
            if (sub_805124C(GetTileMut(x, y), unk, x, y, 1)) {
                dungeon->stairsSpawn.x = x;
                dungeon->stairsSpawn.y = y;
            }
        }
    }

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            if (x <= 4 || x >= fixedRoomSizeX + 5 || y <= 4 || y >= fixedRoomSizeY + 5) {
                Tile *tile = GetTileMut(x, y);
                tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
                if (gUnknown_202F1A8) {
                    SetTerrainType(tile, TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
                }
                else {
                    SetTerrainWall(tile);
                }
            }
        }
    }

    if (fixedRoomNumber == 4) {
        for (y = 5; y < 17; y++) {
            for (x = 2; x < 5; x++) {
                Tile *tile = GetTileMut(x, y);
                tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
                SetTerrainWall(tile);
            }
        }
    }

    if (gDungeon->tileset >= 64) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
                Tile *tile = GetTileMut(x, y);
                if (GetTerrainType(tile) == TERRAIN_TYPE_WALL) {
                    tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
                }
            }
        }
    }

    FinalizeJunctions();
}

static void sub_8051438(struct GridCell *gridCell, s32 fixedRoomNumber)
{
    s32 x, y;
    Dungeon *dungeon = gDungeon;

    gUnknown_202F1DC = ((struct FixedRoomsData **)(dungeon->unk13568->data))[fixedRoomNumber]->unk3;
    gUnknown_202F1E1 = 0;

    if (((struct FixedRoomsData **)(dungeon->unk13568->data))[fixedRoomNumber]->unk2 & 1) {
        s32 yIndex;

        dungeon->unkE250.minX = gridCell->start.x;
        dungeon->unkE250.minY = gridCell->start.y;
        dungeon->unkE250.maxX = gridCell->end.x;
        dungeon->unkE250.maxY = gridCell->end.y;

        yIndex = 0;
        for (y = gridCell->start.y; y < gridCell->end.y; y++) {
            s32 xIndex = 0;
            for (x = gridCell->start.x; x < gridCell->end.x; x++) {
                u8 roomId;
                u8 unk = sub_80511F0();
                Tile *tile = GetTileMut(x, y);

                dungeon->unkE87C[xIndex][yIndex] = unk;
                sub_805124C(&dungeon->unkE27C[xIndex][yIndex], unk, x, y, 0);
                roomId = tile->room;
                *tile = dungeon->unkE27C[xIndex][yIndex];
                if (x >= gridCell->start.x + 2 && x < gridCell->end.x - 2 && y >= gridCell->start.y + 2 && y < gridCell->end.y - 2) {
                    tile->terrainType = TERRAIN_TYPE_IMPASSABLE_WALL | TERRAIN_TYPE_UNBREAKABLE;
                    tile->unkE = 0xE;
                }
                tile->room = roomId;
                dungeon->unkE8BC = roomId;
                xIndex++;
            }
            yIndex++;
        }
    }
    else {
        for (y = gridCell->start.y; y < gridCell->end.y; y++) {
            for (x = gridCell->start.x; x < gridCell->end.x; x++) {
                u8 unk = sub_80511F0();
                Tile *tile = GetTileMut(x, y);
                u8 roomId = tile->room;

                sub_805124C(tile, unk, x, y, 1);
                tile->room = roomId;
                dungeon->unkE8BC = roomId;
            }
        }
    }
}

extern const s16 gUnknown_80F57D4[][3][3];

static void sub_8051654(FloorProperties *floorProps)
{
    s32 i, n;
    s32 x, y;
    s32 middleX, middleY;
    s32 rangeX = 3, rangeY = 3;
    s32 xIndex, yIndex;
    s32 r10;

    // Note: These loops make no sense as the range is always at least 3 - which means the loop always breaks after the first iteration.
    // In fact, pmd red's compiler optimizes out these loops completely. These are however needed to match and were NOT optimized by blue's compiler which proves that's how it was written.
    for (n = 0; n < 20; n++) {
        rangeX = DungeonRandRange(3, (sKecleonShopPosition.maxX - sKecleonShopPosition.minX) - 2);
        if (rangeX < 3)
            rangeX = 3;
        if (rangeX >= 3)
            break;
    }

    for (n = 0; n < 20; n++) {
        rangeY = DungeonRandRange(3, (sKecleonShopPosition.maxY - sKecleonShopPosition.minY) - 2);
        if (rangeY < 3)
            rangeY = 3;
        if (rangeY >= 3)
            break;
    }

    r10 = DungeonRandRange(2, 4);
    for (i = 0; i < r10; i++) {
        if (sKecleonShopPosition.maxX - sKecleonShopPosition.minX <= rangeX)
            break;

        if (DungeonRandInt(100) < 50) {
            s32 y;
            for (y = sKecleonShopPosition.minY; y < sKecleonShopPosition.maxY; y++) {
                GetTileMut(sKecleonShopPosition.minX, y)->terrainType &= ~(TERRAIN_TYPE_SHOP);
            }
            sKecleonShopPosition.minX++;
        }
        else {
            s32 y;
            sKecleonShopPosition.maxX--;
            for (y = sKecleonShopPosition.minY; y < sKecleonShopPosition.maxY; y++) {
                GetTileMut(sKecleonShopPosition.maxX, y)->terrainType &= ~(TERRAIN_TYPE_SHOP);
            }
        }
    }

    for (i = 0; i < r10; i++) {
        if (sKecleonShopPosition.maxY - sKecleonShopPosition.minY <= rangeY)
            break;

        if (DungeonRandInt(100) < 50) {
            s32 x;
            for (x = sKecleonShopPosition.minX; x < sKecleonShopPosition.maxX; x++) {
                GetTileMut(x, sKecleonShopPosition.minY)->terrainType &= ~(TERRAIN_TYPE_SHOP);
            }
            sKecleonShopPosition.minY++;
        }
        else {
            s32 x;
            sKecleonShopPosition.maxY--;
            for (x = sKecleonShopPosition.minX; x < sKecleonShopPosition.maxX; x++) {
                GetTileMut(x, sKecleonShopPosition.maxY)->terrainType &= ~(TERRAIN_TYPE_SHOP);
            }
        }
    }

    for (x = sKecleonShopPosition.minX; x < sKecleonShopPosition.maxX; x++) {
        for (y = sKecleonShopPosition.minY; y < sKecleonShopPosition.maxY; y++) {
            Tile *tile = GetTileMut(x, y);
            if (!(tile->terrainType & TERRAIN_TYPE_SHOP))
                continue;
            if (!(tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION))
                continue;

            tile->terrainType &= ~(TERRAIN_TYPE_SHOP);
        }
    }

    middleX = (sKecleonShopPosition.minX + sKecleonShopPosition.maxX) / 2 - 1;
    middleY = (sKecleonShopPosition.minY + sKecleonShopPosition.maxY) / 2 - 1;
    xIndex = 0;
    for (x = middleX; x < middleX + 3; x++, xIndex++) {
        yIndex = 0;
        for (y = middleY; y < middleY + 3; y++, yIndex++) {
            Tile *tile = GetTileMut(x, y);
            if (!(tile->terrainType & TERRAIN_TYPE_SHOP))
                continue;
            if ((tile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE))
                continue;
            if ((tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION))
                continue;

            if (gUnknown_80F57D4[floorProps->unk18][yIndex][xIndex] > DungeonRandInt(100)) {
                tile->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
            }
        }
    }
}

/*
 * ResetInnerBoundaryTileRows - Resets inner boundary tile rows (y == 1 and y == 30)
 * to their initial state of all wall tiles, with impassable walls at the edges.
 *
 * This is needed because during generation these soft border walls may have been altered or breached.
 */
static void ResetInnerBoundaryTileRows(void)
{
    s32 x;

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        Tile *tile = GetTileMut(x, 1);
        ResetTile(tile);
        if (x == 0 || x == DUNGEON_MAX_SIZE_X - 1) {
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
        }

        tile = GetTileMut(x, 30);
        ResetTile(tile);
        if (x == 0 || x == DUNGEON_MAX_SIZE_X - 1) {
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
        }
    }
}

static void sub_805193C(u8 itemId, s32 x, s32 y, s32 quantity, u32 itemFlags)
{
    Item item;
    DungeonPos pos = {x, y};

    if (sub_805210C(itemId)) {
        xxx_init_itemslot_8090A8C(&item, ITEM_LINK_CABLE, 0);
    }
    else {
        xxx_init_itemslot_8090A8C(&item, itemId, 0);
    }

    item.flags |= itemFlags;
    if (quantity != 0) {
        item.quantity = quantity;
    }

    sub_80460F8(&pos, &item, 1);
}

// s16 species memes strike again. Will the fix ever be discovered?
static void sub_8051998(s16 species_, s32 x, s32 y, u32 unk2_, u32 UNUSED unused)
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
    u8 unk0;
    s16 unk2;
    u32 unk4;
    s16 unk8;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
};

extern const struct UnkStruct_80F6D20 gUnknown_80F6D20[];

// Used to spawn a single tile when generating a fixed room. The tile might contain an item or a monster.
static bool8 PlaceFixedRoomTile(Tile *tile, u8 fixedRoomActionId, s32 x, s32 y, bool8 a5)
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
            if (fixedRoomActionId > 15 && fixedRoomActionId < 220) {
                const struct UnkStruct_80F6D20 *ptr = &gUnknown_80F6D20[fixedRoomActionId];
                tile->room = ptr->unkC;
                if (ptr->unk0 != 0) {
                    if (a5) {
                        sub_805193C(ptr->unk0, x, y, ptr->unk2, ptr->unk4);
                    }
                    else {
                        gDungeon->unk644.unk47 = ptr->unk0;
                    }
                }
                else {
                    if (ptr->unk4 != 0) {
                        gDungeon->unkE220[ptr->unk4 - 1].x = x;
                        gDungeon->unkE220[ptr->unk4 - 1].y = y;
                    }
                }

                if (ptr->unk8 != 0) {
                    sub_8051998(ptr->unk8, x, y, ptr->unkA, fixedRoomActionId);
                }

                if (ptr->unkB != 20 && a5) {
                    SpawnEnemyTrapAtPos(ptr->unkB, x, y, ptr->unkD);
                }

                if (ptr->unkE != 0) {
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
