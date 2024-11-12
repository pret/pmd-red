#include "global.h"
#include "dungeon_generation.h"
#include "file_system.h"
#include "tile_types.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "constants/direction.h"
#include "structs/str_dungeon.h"
#include "structs/map.h"

extern const u8 gUnknown_80F6DCC[];
extern struct FileArchive gDungeonFileArchive;

extern bool8 gUnknown_202F1AA;
extern u8 gUnknown_202F1AB;
extern bool8 gUnknown_202F1AC;
extern u8 gUnknown_202F1A8;
extern u8 gUnknown_202F1B4;
extern u8 gUnknown_202F1AE;
extern u8 gUnknown_202F1AD;
extern u8 gUnknown_202F1A9;
extern s16 gUnknown_202F1B0;
extern s16 gUnknown_202F1B2;
extern s32 gUnknown_202F1C8;
extern s32 gUnknown_202F1D0;
extern s32 gUnknown_202F1CC;
extern Position gUnknown_202F1D8;

extern struct MinMaxPosition gUnknown_202F1B8;

extern void sub_804FD30(void);
extern void sub_804FD30(void);
extern void sub_80518F0(void);
extern void sub_804FCCC(void);
extern void GenerateOneRoomMonsterHouseFloor(void);
extern void ResolveInvalidSpawns(void);
extern void sub_804FC74(void);
void sub_804EB30(void);
void sub_804E9DC(void);
extern void GenerateTwoRoomsWithMonsterHouseFloor(void);
extern u8 GetFloorType();
extern bool8 sub_8050C30(s32 a0, s32 a1, u8 a2);
extern void sub_806C330(s32 a0, s32 a1, s16 a2, u8 a3);

extern const Position gAdjacentTileOffsets[];
extern const bool8 gUnknown_80F6DD5[][NUM_DIRECTIONS];

void sub_804B534(s32 a0, s32 a1, s32 a2, s32 a3);
bool8 sub_804C70C(s32, UnkDungeonGlobal_unk1C574 *);
void GenerateStandardFloor(s32 a0, s32 a1, UnkDungeonGlobal_unk1C574 *a2);
void GenerateOuterRingFloor(UnkDungeonGlobal_unk1C574 *a0);
void GenerateCrossroadsFloor(UnkDungeonGlobal_unk1C574 *a0);
void GenerateLineFloor(UnkDungeonGlobal_unk1C574 *a0);
void GenerateCrossFloor(UnkDungeonGlobal_unk1C574 *a0);
void GenerateBeetleFloor(UnkDungeonGlobal_unk1C574 *a0);
void GenerateOuterRoomsFloor(s32 gridSizeX_, s32 gridSizeY_, UnkDungeonGlobal_unk1C574 *unkPtr);
void sub_8051654(UnkDungeonGlobal_unk1C574 *a0);
void sub_80506F0(s32 a0, UnkDungeonGlobal_unk1C574 *a1);
void sub_804FF08(UnkDungeonGlobal_unk1C574 *a0, bool8 a1);
void sub_8050438(UnkDungeonGlobal_unk1C574 *a0, bool8 a1);

struct FileFixedmapPosStruct
{
    u8 x;
    u8 y;
};

// Helper functions for terrain flags
static inline void SetTerrainType(Tile *tile, u32 terrainType)
{
    tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    tile->terrainType |= terrainType;
}

static inline void SetTerrainNormal(Tile *tile)
{
    SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
}

static inline void SetTerrainSecondary(Tile *tile)
{
    SetTerrainType(tile, TERRAIN_TYPE_SECONDARY);
}

static inline void SetTerrainWall(Tile *tile)
{
    SetTerrainType(tile, TERRAIN_TYPE_WALL);
}

static inline u32 GetTerrainType(Tile *tile)
{
    return tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
}

// Some weird-ass regswap prevents the function from being matched - https://decomp.me/scratch/9SUV3
#ifdef NONMATCHING
void sub_804AFAC(void)
{
    s32 x, y;
    s32 i, j, k;
    bool8 r10 = FALSE;
    UnkDungeonGlobal_unk1C574 *unkPtr = &gDungeon->unk1C574;

    gDungeon->unk13568 = OpenFileAndGetFileDataPtr(gUnknown_80F6DCC, &gDungeonFileArchive);
    gUnknown_202F1AA = FALSE;
    gUnknown_202F1AB = 0;
    gUnknown_202F1AC = FALSE;
    gUnknown_202F1A8 = (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_WATER);
    gUnknown_202F1B4 = 0xFF;
    gUnknown_202F1AE = 0;
    gUnknown_202F1B0 = unkPtr->unk7;
    gUnknown_202F1B2 = unkPtr->unk8;
    gUnknown_202F1AD = 1;
    gUnknown_202F1B8.unk0 = -1;
    gUnknown_202F1B8.unk8 = -1;
    gUnknown_202F1B8.unk4 = -1;
    gUnknown_202F1B8.unkC = -1;

    sub_804FD30();

    gDungeon->unk664 = unkPtr->unk6;

    gDungeon->unk3A09 = 0;
    gDungeon->unk3A0A = 0;

    gUnknown_202F1C8 = unkPtr->unkC;

    for (i = 0; i < 10; i++) {
        bool32 r4 = 0;

        gDungeon->unkE218.x = -1;
        gDungeon->unkE218.y = -1;
        gDungeon->unkE21C.x = -1;
        gDungeon->unkE21C.y = -1;
        for (j = 0; j < 10; j++) {
            gDungeon->unk3A16 = j;
            if (j > 0) {
                gUnknown_202F1C8 = 0;
            }
            gUnknown_202F1A9 = 0;
            gUnknown_202F1D8.x = -1;
            gUnknown_202F1D8.y = -1;
            sub_804FD30();
            gDungeon->unkE218.x = -1;
            gDungeon->unkE218.y = -1;
            gDungeon->unk3A08 = 0;
            if (gDungeon->bossBattleIndex != 0) {
                if (sub_804C70C(gDungeon->bossBattleIndex, unkPtr)) {
                    break;
                }
            }
            else {
                u8 r7 = unkPtr->unk0;

                k = 32;
                while (1) {
                    if (r7 != 8) {
                        x = DungeonRandRange(2, 9);
                        y = DungeonRandRange(2, 8);
                    }
                    else {
                        x = DungeonRandRange(2, 5);
                        y = DungeonRandRange(2, 4);
                    }

                    if (x <= 6 && y <= 4) {
                        break;
                    }
                    if (--k == 0) {
                        x = 4;
                        y = 4;
                        break;
                    }
                }

                if (DUNGEON_MAX_SIZE_X / x < 8) {
                    x = 1;
                }
                if (DUNGEON_MAX_SIZE_Y / y < 8) {
                    y = 1;
                }

                gDungeon->unk3A08 = 0;
                gDungeon->unk3A0C = 0xFF;
                gUnknown_202F1D0 = r7;
                switch (r7 & 0xF) {
                    case 1:
                        y = DungeonRandInt(2) + 2;
                        gUnknown_202F1AE = 1;
                        GenerateStandardFloor(4, y, unkPtr);
                        r10 = TRUE;
                        break;
                    case 11:
                        y = DungeonRandInt(2) + 2;
                        gUnknown_202F1AE = 2;
                        GenerateStandardFloor(4, y, unkPtr);
                        r10 = TRUE;
                        break;
                    case 0:
                    default:
                        GenerateStandardFloor(x, y, unkPtr);
                        r10 = TRUE;
                        break;
                    case 2:
                        GenerateOneRoomMonsterHouseFloor();
                        gDungeon->unk3A08 = 1;
                        break;
                    case 3:
                        GenerateOuterRingFloor(unkPtr);
                        r10 = TRUE;
                        break;
                    case 4:
                        GenerateCrossroadsFloor(unkPtr);
                        r10 = TRUE;
                        break;
                    case 5:
                        GenerateTwoRoomsWithMonsterHouseFloor();
                        gDungeon->unk3A08 = 1;
                        break;
                    case 6:
                        GenerateLineFloor(unkPtr);
                        r10 = TRUE;
                        break;
                    case 7:
                        GenerateCrossFloor(unkPtr);
                        break;
                    case 9:
                        GenerateBeetleFloor(unkPtr);
                        break;
                    case 10:
                        GenerateOuterRoomsFloor(x, y, unkPtr);
                        r10 = TRUE;
                        break;
                }
            }

            sub_80518F0();
            sub_804FCCC();
            if (gUnknown_202F1A9 == 0) {
                s32 countSp = 0;
                u8 spArray[64];
                s32 countRooms = 0;

                for (k = 0; k < 64; k++) {
                    spArray[k] = 0;
                }

                for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
                    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
                        Tile *tile = GetTile(x, y);
                        if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL && tile->room <= 240) {
                            countRooms++;
                            if (tile->room < 64) {
                                spArray[tile->room] = 1;
                            }
                        }
                    }
                }

                countSp = 0;
                // In order to match, 'y' had to be re-used as an iterator var
                for (y = 0; y < 64; y++) {
                    if (spArray[y]) {
                        countSp++;
                    }
                }

                if (countRooms >= 30 && countSp > 1) {
                    break;
                }
            }
        }

        if (j == 10) {
            gUnknown_202F1D8.x = -1;
            gUnknown_202F1D8.y = -1;
            GenerateOneRoomMonsterHouseFloor();
            gDungeon->unk3A08 = 1;
        }
        sub_804E9DC();
        if (r10) {
            sub_80506F0(1, unkPtr);
        }
        r4 = (DungeonRandInt(100) < unkPtr->connectedToTop);
        sub_804FF08(unkPtr, r4);
        sub_8050438(unkPtr, r4);
        ResolveInvalidSpawns();
        if (gDungeon->unkE218.x != -1 && gDungeon->unkE218.y != -1)
        {
            if (GetFloorType() == 1)
                break;
            if (gDungeon->unkE21C.x != -1 && gDungeon->unkE21C.y != -1 && sub_8050C30(gDungeon->unkE21C.x, gDungeon->unkE21C.y, 0))
                break;
        }
    }

    if (i == 10) {
        gUnknown_202F1D8.x = -1;
        gUnknown_202F1D8.y = -1;
        sub_804FD30();
        GenerateOneRoomMonsterHouseFloor();
        gDungeon->unk3A08 = 1;
        sub_804E9DC();
        sub_804FF08(unkPtr, FALSE);
        sub_8050438(unkPtr, FALSE);
        ResolveInvalidSpawns();
    }

    if (gUnknown_202F1D8.x >= 0 && gUnknown_202F1D8.y >= 0) {
        sub_806C330(gUnknown_202F1D8.x, gUnknown_202F1D8.y, 380, 0);
    }

    if (gUnknown_202F1B8.unk0 >= 0) {
        sub_8051654(unkPtr);
        gDungeon->unk3A0A = 1;
    }
    else {
        gDungeon->unk3A0A = 0;
    }

    sub_804B534(0, 0, DUNGEON_MAX_SIZE_X, DUNGEON_MAX_SIZE_Y);
    if (gUnknown_202F1A8 != 0) {
        sub_804FC74();
    }

    CloseFile(gDungeon->unk13568);
}
#else
void NAKED sub_804AFAC(void)
{
    asm_unified("	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x44\n"
"	movs r0, 0\n"
"	mov r10, r0\n"
"	ldr r4, _0804B0E8\n"
"	ldr r0, [r4]\n"
"	ldr r1, _0804B0EC\n"
"	adds r1, r0\n"
"	mov r8, r1\n"
"	ldr r0, _0804B0F0\n"
"	ldr r1, _0804B0F4\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	ldr r2, [r4]\n"
"	ldr r3, _0804B0F8\n"
"	adds r1, r2, r3\n"
"	str r0, [r1]\n"
"	ldr r0, _0804B0FC\n"
"	mov r6, r10\n"
"	strb r6, [r0]\n"
"	ldr r0, _0804B100\n"
"	strb r6, [r0]\n"
"	ldr r0, _0804B104\n"
"	strb r6, [r0]\n"
"	ldr r5, _0804B108\n"
"	movs r3, 0\n"
"	ldr r1, _0804B10C\n"
"	ldr r0, _0804B110\n"
"	adds r2, r0\n"
"	movs r6, 0\n"
"	ldrsh r0, [r2, r6]\n"
"	adds r0, r1\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0x2\n"
"	bne _0804AFFC\n"
"	movs r3, 0x1\n"
"_0804AFFC:\n"
"	strb r3, [r5]\n"
"	ldr r1, _0804B114\n"
"	movs r0, 0xFF\n"
"	strb r0, [r1]\n"
"	ldr r0, _0804B118\n"
"	mov r1, r10\n"
"	strb r1, [r0]\n"
"	ldr r1, _0804B11C\n"
"	mov r2, r8\n"
"	ldrb r0, [r2, 0x7]\n"
"	strh r0, [r1]\n"
"	ldr r1, _0804B120\n"
"	ldrb r0, [r2, 0x8]\n"
"	strh r0, [r1]\n"
"	ldr r1, _0804B124\n"
"	movs r0, 0x1\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804B128\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	str r0, [r1]\n"
"	str r0, [r1, 0x8]\n"
"	str r0, [r1, 0x4]\n"
"	str r0, [r1, 0xC]\n"
"	bl sub_804FD30\n"
"	ldr r3, [r4]\n"
"	mov r6, r8\n"
"	ldrb r2, [r6, 0x6]\n"
"	ldr r1, _0804B12C\n"
"	adds r0, r3, r1\n"
"	movs r1, 0\n"
"	strh r2, [r0]\n"
"	ldr r2, _0804B130\n"
"	adds r0, r3, r2\n"
"	strb r1, [r0]\n"
"	ldr r0, [r4]\n"
"	ldr r3, _0804B134\n"
"	adds r0, r3\n"
"	strb r1, [r0]\n"
"	ldr r1, _0804B138\n"
"	mov r6, r8\n"
"	ldrb r0, [r6, 0xC]\n"
"	str r0, [r1]\n"
"	movs r0, 0\n"
"	str r0, [sp, 0x40]\n"
"_0804B058:\n"
"	ldr r0, _0804B0E8\n"
"	ldr r2, [r0]\n"
"	ldr r3, _0804B13C\n"
"	adds r1, r2, r3\n"
"	ldr r0, _0804B140\n"
"	strh r0, [r1]\n"
"	ldr r6, _0804B144\n"
"	adds r1, r2, r6\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	strh r0, [r1]\n"
"	ldr r0, _0804B148\n"
"	adds r1, r2, r0\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	strh r0, [r1]\n"
"	ldr r1, _0804B14C\n"
"	adds r2, r1\n"
"	strh r0, [r2]\n"
"	movs r2, 0\n"
"	mov r9, r2\n"
"_0804B082:\n"
"	ldr r4, _0804B0E8\n"
"	ldr r0, [r4]\n"
"	ldr r3, _0804B150\n"
"	adds r0, r3\n"
"	movs r5, 0\n"
"	movs r1, 0\n"
"	mov r6, r9\n"
"	strh r6, [r0]\n"
"	mov r0, r9\n"
"	cmp r0, 0\n"
"	ble _0804B09C\n"
"	ldr r0, _0804B138\n"
"	str r1, [r0]\n"
"_0804B09C:\n"
"	ldr r0, _0804B154\n"
"	strb r5, [r0]\n"
"	ldr r1, _0804B158\n"
"	ldr r0, _0804B140\n"
"	strh r0, [r1]\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	strh r0, [r1, 0x2]\n"
"	bl sub_804FD30\n"
"	ldr r1, [r4]\n"
"	ldr r3, _0804B13C\n"
"	adds r2, r1, r3\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	strh r0, [r2]\n"
"	ldr r6, _0804B144\n"
"	adds r2, r1, r6\n"
"	strh r0, [r2]\n"
"	ldr r0, _0804B15C\n"
"	adds r1, r0\n"
"	strb r5, [r1]\n"
"	ldr r0, [r4]\n"
"	ldr r2, _0804B160\n"
"	adds r1, r0, r2\n"
"	movs r3, 0\n"
"	ldrsh r0, [r1, r3]\n"
"	cmp r0, 0\n"
"	beq _0804B164\n"
"	mov r1, r8\n"
"	bl sub_804C70C\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0804B0E4\n"
"	b _0804B376\n"
"_0804B0E4:\n"
"	b _0804B2F6\n"
"	.align 2, 0\n"
"_0804B0E8: .4byte gDungeon\n"
"_0804B0EC: .4byte 0x0001c574\n"
"_0804B0F0: .4byte gUnknown_80F6DCC\n"
"_0804B0F4: .4byte gDungeonFileArchive\n"
"_0804B0F8: .4byte 0x00013568\n"
"_0804B0FC: .4byte gUnknown_202F1AA\n"
"_0804B100: .4byte gUnknown_202F1AB\n"
"_0804B104: .4byte gUnknown_202F1AC\n"
"_0804B108: .4byte gUnknown_202F1A8\n"
"_0804B10C: .4byte gDungeonWaterType\n"
"_0804B110: .4byte 0x00003a0e\n"
"_0804B114: .4byte gUnknown_202F1B4\n"
"_0804B118: .4byte gUnknown_202F1AE\n"
"_0804B11C: .4byte gUnknown_202F1B0\n"
"_0804B120: .4byte gUnknown_202F1B2\n"
"_0804B124: .4byte gUnknown_202F1AD\n"
"_0804B128: .4byte gUnknown_202F1B8\n"
"_0804B12C: .4byte 0x00000664\n"
"_0804B130: .4byte 0x00003a09\n"
"_0804B134: .4byte 0x00003a0a\n"
"_0804B138: .4byte gUnknown_202F1C8\n"
"_0804B13C: .4byte 0x0000e218\n"
"_0804B140: .4byte 0x0000ffff\n"
"_0804B144: .4byte 0x0000e21a\n"
"_0804B148: .4byte 0x0000e21c\n"
"_0804B14C: .4byte 0x0000e21e\n"
"_0804B150: .4byte 0x00003a16\n"
"_0804B154: .4byte gUnknown_202F1A9\n"
"_0804B158: .4byte gUnknown_202F1D8\n"
"_0804B15C: .4byte 0x00003a08\n"
"_0804B160: .4byte 0x00003a14\n"
"_0804B164:\n"
"	mov r0, r8\n"
"	ldrb r7, [r0]\n"
"	movs r6, 0x20\n"
"_0804B16A:\n"
"	cmp r7, 0x8\n"
"	beq _0804B17E\n"
"	movs r0, 0x2\n"
"	movs r1, 0x9\n"
"	bl DungeonRandRange\n"
"	adds r5, r0, 0\n"
"	movs r0, 0x2\n"
"	movs r1, 0x8\n"
"	b _0804B18C\n"
"_0804B17E:\n"
"	movs r0, 0x2\n"
"	movs r1, 0x5\n"
"	bl DungeonRandRange\n"
"	adds r5, r0, 0\n"
"	movs r0, 0x2\n"
"	movs r1, 0x4\n"
"_0804B18C:\n"
"	bl DungeonRandRange\n"
"	adds r4, r0, 0\n"
"	cmp r5, 0x6\n"
"	bgt _0804B19A\n"
"	cmp r4, 0x4\n"
"	ble _0804B1A4\n"
"_0804B19A:\n"
"	subs r6, 0x1\n"
"	cmp r6, 0\n"
"	bne _0804B16A\n"
"	movs r5, 0x4\n"
"	movs r4, 0x4\n"
"_0804B1A4:\n"
"	movs r0, 0x38\n"
"	adds r1, r5, 0\n"
"	bl __divsi3\n"
"	cmp r0, 0x7\n"
"	bgt _0804B1B2\n"
"	movs r5, 0x1\n"
"_0804B1B2:\n"
"	movs r0, 0x20\n"
"	adds r1, r4, 0\n"
"	bl __divsi3\n"
"	cmp r0, 0x7\n"
"	bgt _0804B1C0\n"
"	movs r4, 0x1\n"
"_0804B1C0:\n"
"	ldr r2, _0804B1EC\n"
"	ldr r0, [r2]\n"
"	ldr r1, _0804B1F0\n"
"	adds r0, r1\n"
"	movs r1, 0\n"
"	strb r1, [r0]\n"
"	ldr r0, [r2]\n"
"	ldr r2, _0804B1F4\n"
"	adds r0, r2\n"
"	movs r1, 0xFF\n"
"	strb r1, [r0]\n"
"	ldr r0, _0804B1F8\n"
"	str r7, [r0]\n"
"	movs r0, 0xF\n"
"	ands r0, r7\n"
"	cmp r0, 0xB\n"
"	bhi _0804B274\n"
"	lsls r0, 2\n"
"	ldr r1, _0804B1FC\n"
"	adds r0, r1\n"
"	ldr r0, [r0]\n"
"	mov pc, r0\n"
"	.align 2, 0\n"
"_0804B1EC: .4byte gDungeon\n"
"_0804B1F0: .4byte 0x00003a08\n"
"_0804B1F4: .4byte 0x00003a0c\n"
"_0804B1F8: .4byte gUnknown_202F1D0\n"
"_0804B1FC: .4byte _0804B200\n"
"	.align 2, 0\n"
"_0804B200:\n"
"	.4byte _0804B274\n"
"	.4byte _0804B230\n"
"	.4byte _0804B280\n"
"	.4byte _0804B298\n"
"	.4byte _0804B2A4\n"
"	.4byte _0804B2B0\n"
"	.4byte _0804B2CC\n"
"	.4byte _0804B2D8\n"
"	.4byte _0804B274\n"
"	.4byte _0804B2E0\n"
"	.4byte _0804B2E8\n"
"	.4byte _0804B250\n"
"_0804B230:\n"
"	movs r0, 0x2\n"
"	bl DungeonRandInt\n"
"	adds r4, r0, 0x2\n"
"	ldr r1, _0804B24C\n"
"	movs r0, 0x1\n"
"	strb r0, [r1]\n"
"	movs r0, 0x4\n"
"	adds r1, r4, 0\n"
"	mov r2, r8\n"
"	bl GenerateStandardFloor\n"
"	b _0804B2AA\n"
"	.align 2, 0\n"
"_0804B24C: .4byte gUnknown_202F1AE\n"
"_0804B250:\n"
"	movs r0, 0x2\n"
"	bl DungeonRandInt\n"
"	adds r4, r0, 0x2\n"
"	ldr r1, _0804B270\n"
"	movs r0, 0x2\n"
"	strb r0, [r1]\n"
"	movs r0, 0x4\n"
"	adds r1, r4, 0\n"
"	mov r2, r8\n"
"	bl GenerateStandardFloor\n"
"	movs r6, 0x1\n"
"	mov r10, r6\n"
"	b _0804B2F6\n"
"	.align 2, 0\n"
"_0804B270: .4byte gUnknown_202F1AE\n"
"_0804B274:\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	mov r2, r8\n"
"	bl GenerateStandardFloor\n"
"	b _0804B2D2\n"
"_0804B280:\n"
"	bl GenerateOneRoomMonsterHouseFloor\n"
"	ldr r0, _0804B290\n"
"	ldr r0, [r0]\n"
"	ldr r1, _0804B294\n"
"	adds r0, r1\n"
"	b _0804B2BC\n"
"	.align 2, 0\n"
"_0804B290: .4byte gDungeon\n"
"_0804B294: .4byte 0x00003a08\n"
"_0804B298:\n"
"	mov r0, r8\n"
"	bl GenerateOuterRingFloor\n"
"	movs r2, 0x1\n"
"	mov r10, r2\n"
"	b _0804B2F6\n"
"_0804B2A4:\n"
"	mov r0, r8\n"
"	bl GenerateCrossroadsFloor\n"
"_0804B2AA:\n"
"	movs r3, 0x1\n"
"	mov r10, r3\n"
"	b _0804B2F6\n"
"_0804B2B0:\n"
"	bl GenerateTwoRoomsWithMonsterHouseFloor\n"
"	ldr r0, _0804B2C4\n"
"	ldr r0, [r0]\n"
"	ldr r6, _0804B2C8\n"
"	adds r0, r6\n"
"_0804B2BC:\n"
"	movs r1, 0x1\n"
"	strb r1, [r0]\n"
"	b _0804B2F6\n"
"	.align 2, 0\n"
"_0804B2C4: .4byte gDungeon\n"
"_0804B2C8: .4byte 0x00003a08\n"
"_0804B2CC:\n"
"	mov r0, r8\n"
"	bl GenerateLineFloor\n"
"_0804B2D2:\n"
"	movs r0, 0x1\n"
"	mov r10, r0\n"
"	b _0804B2F6\n"
"_0804B2D8:\n"
"	mov r0, r8\n"
"	bl GenerateCrossFloor\n"
"	b _0804B2F6\n"
"_0804B2E0:\n"
"	mov r0, r8\n"
"	bl GenerateBeetleFloor\n"
"	b _0804B2F6\n"
"_0804B2E8:\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	mov r2, r8\n"
"	bl GenerateOuterRoomsFloor\n"
"	movs r1, 0x1\n"
"	mov r10, r1\n"
"_0804B2F6:\n"
"	bl sub_80518F0\n"
"	bl sub_804FCCC\n"
"	ldr r0, _0804B4B4\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _0804B36A\n"
"	movs r7, 0\n"
"	movs r1, 0\n"
"	mov r0, sp\n"
"	adds r0, 0x3F\n"
"_0804B30E:\n"
"	strb r1, [r0]\n"
"	subs r0, 0x1\n"
"	cmp r0, sp\n"
"	bge _0804B30E\n"
"	movs r5, 0\n"
"_0804B318:\n"
"	movs r4, 0\n"
"	adds r6, r5, 0x1\n"
"_0804B31C:\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	bl GetTile\n"
"	adds r1, r0, 0\n"
"	ldrh r0, [r1]\n"
"	movs r2, 0x3\n"
"	ands r2, r0\n"
"	cmp r2, 0x1\n"
"	bne _0804B340\n"
"	ldrb r0, [r1, 0x9]\n"
"	cmp r0, 0xF0\n"
"	bhi _0804B340\n"
"	adds r7, 0x1\n"
"	cmp r0, 0x3F\n"
"	bhi _0804B340\n"
"	add r0, sp\n"
"	strb r2, [r0]\n"
"_0804B340:\n"
"	adds r4, 0x1\n"
"	cmp r4, 0x1F\n"
"	ble _0804B31C\n"
"	adds r5, r6, 0\n"
"	cmp r5, 0x37\n"
"	ble _0804B318\n"
"	movs r1, 0\n"
"	movs r4, 0\n"
"_0804B350:\n"
"	mov r2, sp\n"
"	adds r0, r2, r4\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	beq _0804B35C\n"
"	adds r1, 0x1\n"
"_0804B35C:\n"
"	adds r4, 0x1\n"
"	cmp r4, 0x3F\n"
"	ble _0804B350\n"
"	cmp r7, 0x1D\n"
"	ble _0804B36A\n"
"	cmp r1, 0x1\n"
"	bgt _0804B376\n"
"_0804B36A:\n"
"	movs r3, 0x1\n"
"	add r9, r3\n"
"	mov r6, r9\n"
"	cmp r6, 0x9\n"
"	bgt _0804B376\n"
"	b _0804B082\n"
"_0804B376:\n"
"	mov r0, r9\n"
"	cmp r0, 0xA\n"
"	bne _0804B398\n"
"	ldr r1, _0804B4B8\n"
"	ldr r0, _0804B4BC\n"
"	strh r0, [r1]\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	strh r0, [r1, 0x2]\n"
"	bl GenerateOneRoomMonsterHouseFloor\n"
"	ldr r0, _0804B4C0\n"
"	ldr r0, [r0]\n"
"	ldr r1, _0804B4C4\n"
"	adds r0, r1\n"
"	movs r1, 0x1\n"
"	strb r1, [r0]\n"
"_0804B398:\n"
"	bl sub_804E9DC\n"
"	mov r2, r10\n"
"	cmp r2, 0\n"
"	beq _0804B3AA\n"
"	movs r0, 0x1\n"
"	mov r1, r8\n"
"	bl sub_80506F0\n"
"_0804B3AA:\n"
"	movs r0, 0x64\n"
"	bl DungeonRandInt\n"
"	movs r4, 0\n"
"	mov r3, r8\n"
"	ldrb r3, [r3, 0x19]\n"
"	cmp r0, r3\n"
"	bge _0804B3BC\n"
"	movs r4, 0x1\n"
"_0804B3BC:\n"
"	mov r0, r8\n"
"	adds r1, r4, 0\n"
"	bl sub_804FF08\n"
"	mov r0, r8\n"
"	adds r1, r4, 0\n"
"	bl sub_8050438\n"
"	bl ResolveInvalidSpawns\n"
"	ldr r5, _0804B4C0\n"
"	ldr r1, [r5]\n"
"	ldr r6, _0804B4C8\n"
"	adds r0, r1, r6\n"
"	movs r2, 0\n"
"	ldrsh r0, [r0, r2]\n"
"	movs r4, 0x1\n"
"	negs r4, r4\n"
"	cmp r0, r4\n"
"	beq _0804B42A\n"
"	ldr r3, _0804B4CC\n"
"	adds r0, r1, r3\n"
"	movs r6, 0\n"
"	ldrsh r0, [r0, r6]\n"
"	cmp r0, r4\n"
"	beq _0804B42A\n"
"	bl GetFloorType\n"
"	lsls r0, 24\n"
"	lsrs r0, 24\n"
"	cmp r0, 0x1\n"
"	beq _0804B436\n"
"	ldr r1, [r5]\n"
"	ldr r0, _0804B4D0\n"
"	adds r2, r1, r0\n"
"	movs r3, 0\n"
"	ldrsh r0, [r2, r3]\n"
"	cmp r0, r4\n"
"	beq _0804B42A\n"
"	ldr r6, _0804B4D4\n"
"	adds r1, r6\n"
"	movs r3, 0\n"
"	ldrsh r0, [r1, r3]\n"
"	cmp r0, r4\n"
"	beq _0804B42A\n"
"	movs r6, 0\n"
"	ldrsh r0, [r2, r6]\n"
"	movs r2, 0\n"
"	ldrsh r1, [r1, r2]\n"
"	movs r2, 0\n"
"	bl sub_8050C30\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _0804B436\n"
"_0804B42A:\n"
"	ldr r3, [sp, 0x40]\n"
"	adds r3, 0x1\n"
"	str r3, [sp, 0x40]\n"
"	cmp r3, 0x9\n"
"	bgt _0804B436\n"
"	b _0804B058\n"
"_0804B436:\n"
"	ldr r6, [sp, 0x40]\n"
"	cmp r6, 0xA\n"
"	bne _0804B474\n"
"	ldr r1, _0804B4B8\n"
"	ldr r0, _0804B4BC\n"
"	strh r0, [r1]\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	strh r0, [r1, 0x2]\n"
"	bl sub_804FD30\n"
"	bl GenerateOneRoomMonsterHouseFloor\n"
"	ldr r0, _0804B4C0\n"
"	ldr r0, [r0]\n"
"	ldr r1, _0804B4C4\n"
"	adds r0, r1\n"
"	movs r1, 0x1\n"
"	strb r1, [r0]\n"
"	bl sub_804E9DC\n"
"	mov r0, r8\n"
"	movs r1, 0\n"
"	bl sub_804FF08\n"
"	mov r0, r8\n"
"	movs r1, 0\n"
"	bl sub_8050438\n"
"	bl ResolveInvalidSpawns\n"
"_0804B474:\n"
"	ldr r1, _0804B4B8\n"
"	movs r2, 0\n"
"	ldrsh r0, [r1, r2]\n"
"	cmp r0, 0\n"
"	blt _0804B498\n"
"	movs r3, 0x2\n"
"	ldrsh r0, [r1, r3]\n"
"	cmp r0, 0\n"
"	blt _0804B498\n"
"	movs r6, 0\n"
"	ldrsh r0, [r1, r6]\n"
"	movs r2, 0x2\n"
"	ldrsh r1, [r1, r2]\n"
"	movs r2, 0xBE\n"
"	lsls r2, 1\n"
"	movs r3, 0\n"
"	bl sub_806C330\n"
"_0804B498:\n"
"	ldr r0, _0804B4D8\n"
"	ldr r0, [r0]\n"
"	cmp r0, 0\n"
"	blt _0804B4E0\n"
"	mov r0, r8\n"
"	bl sub_8051654\n"
"	ldr r0, _0804B4C0\n"
"	ldr r0, [r0]\n"
"	ldr r3, _0804B4DC\n"
"	adds r0, r3\n"
"	movs r1, 0x1\n"
"	b _0804B4EA\n"
"	.align 2, 0\n"
"_0804B4B4: .4byte gUnknown_202F1A9\n"
"_0804B4B8: .4byte gUnknown_202F1D8\n"
"_0804B4BC: .4byte 0x0000ffff\n"
"_0804B4C0: .4byte gDungeon\n"
"_0804B4C4: .4byte 0x00003a08\n"
"_0804B4C8: .4byte 0x0000e218\n"
"_0804B4CC: .4byte 0x0000e21a\n"
"_0804B4D0: .4byte 0x0000e21c\n"
"_0804B4D4: .4byte 0x0000e21e\n"
"_0804B4D8: .4byte gUnknown_202F1B8\n"
"_0804B4DC: .4byte 0x00003a0a\n"
"_0804B4E0:\n"
"	ldr r0, _0804B524\n"
"	ldr r0, [r0]\n"
"	ldr r6, _0804B528\n"
"	adds r0, r6\n"
"	movs r1, 0\n"
"_0804B4EA:\n"
"	strb r1, [r0]\n"
"	movs r0, 0\n"
"	movs r1, 0\n"
"	movs r2, 0x38\n"
"	movs r3, 0x20\n"
"	bl sub_804B534\n"
"	ldr r0, _0804B52C\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	beq _0804B504\n"
"	bl sub_804FC74\n"
"_0804B504:\n"
"	ldr r0, _0804B524\n"
"	ldr r0, [r0]\n"
"	ldr r1, _0804B530\n"
"	adds r0, r1\n"
"	ldr r0, [r0]\n"
"	bl CloseFile\n"
"	add sp, 0x44\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0804B524: .4byte gDungeon\n"
"_0804B528: .4byte 0x00003a0a\n"
"_0804B52C: .4byte gUnknown_202F1A8\n"
"_0804B530: .4byte 0x00013568\n");
}
#endif // NONMATCHING

void sub_804B534(s32 xStart, s32 yStart, s32 maxX, s32 maxY)
{
    s32 x, y;
    for (x = xStart; x < maxX; x++) {
        for (y = yStart; y < maxY; y++) {
            s32 unkCount = 0;
            Tile *tile = GetTileSafe(x, y);

            tile->terrainType &= ~(TERRAIN_TYPE_UNK_2);
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

struct GridCell
{
    Position start;
    Position end;
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

void sub_804C790(s32 gridSizeX, s32 gridSizeY, s32 x2, s32 y2, s32 a4, UnkDungeonGlobal_unk1C574 *unkPtr);
void sub_8050F90(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, s32 a5, s32 x2, s32 y2);
void sub_8051438(struct GridCell *gridCell, s32 a1);
extern void sub_8051288(s32 a0);
void GetGridPositions(s32 *listX, s32 *listY, s32 gridSizeX, s32 gridSizeY);
void InitDungeonGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY);
void GenerateRoomImperfections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY);
void GenerateSecondaryStructure(struct GridCell *gridCell);
void GenerateSecondaryStructures(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY);
void AssignRooms(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 roomsNumber);
void CreateRoomsAndAnchors(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, u32 roomFlags);
void CreateGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, bool8 disableRoomMerging);
void EnsureConnectedGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY);
static void AssignRandomGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, UnkDungeonGlobal_unk1C574 *unkPtr);
void AssignGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 cursorX, s32 cursorY, UnkDungeonGlobal_unk1C574 *unkPtr);
void GenerateMazeRoom(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance);
void GenerateMaze(struct GridCell *gridCell, bool8 useSecondaryTerrain);
void GenerateMazeLine(s32 x0, s32 y0, s32 xMin, s32 yMin, s32 xMax, s32 yMax, bool8 useSecondaryTerrain, u32 roomIndex);
void GenerateKecleonShop(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance);
void GenerateMonsterHouse(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance);
void GenerateExtraHallways(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 numExtraHallways);
static void MergeRoomsVertically(s32 roomX, s32 roomY1, s32 room_dy, struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN]);
void CreateHallway(s32 startX, s32 startY, s32 endX, s32 endY, bool8 vertical, s32 turnX, s32 turnY);

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
void GenerateStandardFloor(s32 gridSizeX, s32 gridSizeY, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];

    GetGridPositions(listX, listY, gridSizeX, gridSizeY);

    InitDungeonGrid(grid, gridSizeX, gridSizeY);

    AssignRooms(grid, gridSizeX, gridSizeY, unkPtr->unk1);

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, unkPtr->unkD);

    AssignRandomGridCellConnections(grid, gridSizeX, gridSizeY, unkPtr);
    CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, FALSE);

    EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

    GenerateMazeRoom(grid, gridSizeX, gridSizeY, unkPtr->unk9);
    GenerateKecleonShop(grid, gridSizeX, gridSizeY, gUnknown_202F1B0);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, gUnknown_202F1B2);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, unkPtr->unk13);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
    GenerateSecondaryStructures(grid, gridSizeX, gridSizeY);
}

// GenerateOuterRingFloor - Generates on a 6x4 grid, with the outer border of grid cells being hallways and the inner 4x2 grid being rooms.
void GenerateOuterRingFloor(UnkDungeonGlobal_unk1C574 *unkPtr)
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
						SetTerrainNormal(GetTileSafe(curX, curY));
                        GetTileSafe(curX, curY)->room = currRoomIndex;
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

				SetTerrainNormal(GetTileSafe(startX, startY));
				GetTileSafe(startX, startY)->room = CORRIDOR_ROOM;
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

	AssignRandomGridCellConnections(grid, gridSizeX, gridSizeY, unkPtr);
	CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, FALSE);

	EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

	GenerateKecleonShop(grid, gridSizeX, gridSizeY, gUnknown_202F1B0);
	GenerateMonsterHouse(grid, gridSizeX, gridSizeY, gUnknown_202F1B2);

	GenerateExtraHallways(grid, gridSizeX, gridSizeY, unkPtr->unk13);
	GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

/*
 * GenerateCrossroadsFloor - Generates a floor layout with hallways on the inside and rooms on the outside, with empty corners.
 * Also nicknamed "Ladder Layout" by some.
 */
void GenerateCrossroadsFloor(UnkDungeonGlobal_unk1C574 *unkPtr)
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
                        SetTerrainNormal(GetTileSafe(curX, curY));
                        GetTileSafe(curX, curY)->room = currRoomIndex;
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

				SetTerrainNormal(GetTileSafe(startX, startY));
				GetTileSafe(startX, startY)->room = CORRIDOR_ROOM;
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
	GenerateKecleonShop(grid, gridSizeX, gridSizeY, gUnknown_202F1B0);
	GenerateMonsterHouse(grid, gridSizeX, gridSizeY, gUnknown_202F1B2);

	GenerateExtraHallways(grid, gridSizeX, gridSizeY, unkPtr->unk13);
	GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

// GenerateLineFloor - Generates a floor layout with 5 grid cells in a horizontal line.
void GenerateLineFloor(UnkDungeonGlobal_unk1C574 *unkPtr)
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

    AssignRooms(grid, gridSizeX, gridSizeY, unkPtr->unk1);
    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, unkPtr->unkD);

    AssignRandomGridCellConnections(grid, gridSizeX, gridSizeY, unkPtr);
    CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, disableRoomMerging);

    EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);

    GenerateKecleonShop(grid, gridSizeX, gridSizeY, gUnknown_202F1B0);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, gUnknown_202F1B2);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, unkPtr->unk13);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

// GenerateCrossFloor - Generates a floor layout with 5 rooms arranged in a "plus" or "cross" configuration.
void GenerateCrossFloor(UnkDungeonGlobal_unk1C574 *unkPtr)
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

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, unkPtr->unkD);

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

    GenerateKecleonShop(grid, gridSizeX, gridSizeY, gUnknown_202F1B0);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, gUnknown_202F1B2);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, unkPtr->unk13);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
}

// GenerateBeetleFloor - Generates a floor layout in a "beetle" shape, with a
// 3x3 grid of rooms, a merged center column, and hallways along each row
void GenerateBeetleFloor(UnkDungeonGlobal_unk1C574 *unkPtr)
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

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, unkPtr->unkD);

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

    GenerateKecleonShop(grid, gridSizeX, gridSizeY, gUnknown_202F1B0);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, gUnknown_202F1B2);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, unkPtr->unk13);
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
            Tile *tile = GetTileSafe(x, y);
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
void GenerateOuterRoomsFloor(s32 gridSizeX_, s32 gridSizeY_, UnkDungeonGlobal_unk1C574 *unkPtr)
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

    CreateRoomsAndAnchors(grid, gridSizeX, gridSizeY, listX, listY, unkPtr->unkD);

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

    GenerateMazeRoom(grid, gridSizeX, gridSizeY, unkPtr->unk9);
    GenerateKecleonShop(grid, gridSizeX, gridSizeY, gUnknown_202F1B0);
    GenerateMonsterHouse(grid, gridSizeX, gridSizeY, gUnknown_202F1B2);

    GenerateExtraHallways(grid, gridSizeX, gridSizeY, unkPtr->unk13);
    GenerateRoomImperfections(grid, gridSizeX, gridSizeY);
    GenerateSecondaryStructures(grid, gridSizeX, gridSizeY);
}

bool8 sub_804C70C(s32 a0, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct FileFixedmapPosStruct **fileData = (void *) gDungeon->unk13568->data;
    s32 x1 = fileData[a0]->x;
    s32 y1 = fileData[a0]->y;
    s32 gridSizeX, gridSizeY;

    if (x1 == 0 || y1 == 0) {
        GenerateOneRoomMonsterHouseFloor();
        return FALSE;
    }
    else if (a0 < 50) {
        sub_8051288(a0);
        return TRUE;
    }
    else {
        gridSizeX = DUNGEON_MAX_SIZE_X / (x1 + 4);
        if (gridSizeX <= 1)
            gridSizeX = 1;
        gridSizeY = DUNGEON_MAX_SIZE_Y / (y1 + 4);
        if (gridSizeY <= 1)
            gridSizeY = 1;
        sub_804C790(gridSizeX, gridSizeY, x1, y1, a0, unkPtr);
        return FALSE;
    }
}

void sub_804C790(s32 gridSizeX, s32 gridSizeY, s32 x2, s32 y2, s32 a4, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    s32 tries;
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 r10 = 0;
    s32 cursorX = 0, cursorY = 0;

    GetGridPositions(listX, listY, gridSizeX, gridSizeY);
    InitDungeonGrid(grid, gridSizeX, gridSizeY);
    AssignRooms(grid, gridSizeX, gridSizeY, unkPtr->unk1);
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
    sub_8050F90(grid, gridSizeX, gridSizeY, listX, listY, r10, x2, y2);
    if (gridSizeX != 1 || gridSizeY != 1) {
        AssignGridCellConnections(grid, gridSizeX, gridSizeY, cursorX, cursorY, unkPtr);
        CreateGridCellConnections(grid, gridSizeX, gridSizeY, listX, listY, TRUE);
        EnsureConnectedGrid(grid, gridSizeX, gridSizeY, listX, listY);
    }
    sub_8051438(&grid[cursorX][cursorY], a4);
}

/*
 * GenerateOneRoomMonsterHouseFloor - Generates a floor layout with just one large room which is a Monster House.
 * This generator is used as a fallback if the event generation fails too many times.
 */
void GenerateOneRoomMonsterHouseFloor(void)
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
            SetTerrainNormal(GetTileSafe(x, y));
            GetTileSafe(x, y)->room = 0;
        }
    }
    GenerateMonsterHouse(grid, 1, 1, 999);
}

// GenerateTwoRoomsWithMonsterHouseFloor - Generates a floor layout with two rooms (left and right), with one being a Monster House.
void GenerateTwoRoomsWithMonsterHouseFloor(void)
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
                    SetTerrainNormal(GetTileSafe(currX, currY));
                    GetTileSafe(currX, currY)->room = currRoomId;
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
void GenerateExtraHallways(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 numExtraHallways)
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
                SetTerrainNormal(GetTileSafe(currX, currY));
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
				if (currX >= 32 && gUnknown_202F1AE == 1 && direction == DIRECTION_EAST) break;
				if (currX >= 48 && gUnknown_202F1AE == 2 && direction == DIRECTION_EAST) break;
			}

			// Move in the current direction
			currX += gAdjacentTileOffsets[direction].x;
			currY += gAdjacentTileOffsets[direction].y;
		}
	}
}

// GetGridPositions - Determines the starting positions of grid cells based on the given floor grid dimensions
void GetGridPositions(s32 *listX, s32 *listY, s32 gridSizeX, s32 gridSizeY)
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
void InitDungeonGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY)
{
    s32 x, y;

    for (x = 0; x < gridSizeX; x++) {
        for (y = 0; y < gridSizeY; y++) {
            if (gUnknown_202F1AE == 1 && x >= gridSizeX / 2) {
                grid[x][y].isInvalid = TRUE;
            }
            else if (gUnknown_202F1AE == 2 && x >= (gridSizeX * 3) / 4) {
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
void AssignRooms(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 roomsNumber)
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
    gUnknown_202F1CC = 0;
	for (x = 0; x < gridSizeX; x++) {
		for (y = 0; y < gridSizeY; y++) {
			if (grid[x][y].isInvalid)
                continue;

			// There are too many rooms, remove
			if (gUnknown_202F1CC >= MAX_ROOM_COUNT) {
				grid[x][y].isRoom = FALSE;
			}

			// Using the randomly shuffled bits, create or remove the room
			if (randomRoomBits[i]) {
				grid[x][y].isRoom = TRUE;
				gUnknown_202F1CC++;

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
	if (gUnknown_202F1CC >= 2)
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

	gUnknown_202F1AD = FALSE;
}

/*
 * CreateRoomsAndAnchors - Creates the rectangle regions of open terrain for each room
 * leaving a margin relative to the border
 *
 * If the room is an anchor, a single tile is placed with a hallway indicator for later.
 */
void CreateRoomsAndAnchors(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, u32 roomFlags)
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
                        SetTerrainNormal(GetTileSafe(roomX, roomY));
                        GetTileSafe(roomX, roomY)->room = roomNumber;
					}
				}

                flagImperfect = TRUE;
				// Randomly flag the room for a secondary structure
                flagSecondary = DungeonRandInt(100) < GENERATION_CONSTANT_SECONDARY_STRUCTURE_FLAG_CHANCE;
				if (gUnknown_202F1C8 == 0) {
					flagSecondary = FALSE;
				}

				// Flag for imperfections if needed
                if (!(roomFlags & 4)) {
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
				SetTerrainNormal(GetTileSafe(pt_x, pt_y));

				// Set the room index to 0xFE for anchor
				GetTileSafe(pt_x, pt_y)->room = ROOM_0xFE;
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
void GenerateSecondaryStructures(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY)
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

static void AssignRandomGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    s32 cursorX = DungeonRandInt(gridSizeX);
    s32 cursorY = DungeonRandInt(gridSizeY);

    AssignGridCellConnections(grid, gridSizeX, gridSizeY, cursorX, cursorY, unkPtr);
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

enum CardinalDirection
{
	CARDINAL_DIR_RIGHT,
	CARDINAL_DIR_UP,
	CARDINAL_DIR_LEFT,
	CARDINAL_DIR_DOWN,
	NUM_CARDINAL_DIRECTIONS
};

#define CARDINAL_DIRECTION_MASK 3

void AssignGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 cursorX, s32 cursorY, UnkDungeonGlobal_unk1C574 *unkPtr)
{
	s32 i;
    s32 x = cursorX;
    s32 y = cursorY;
	s32 floorConnectivity = unkPtr->unk5;
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

	if (unkPtr->unkB)
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
void CreateGridCellConnections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY, bool8 disableRoomMerging)
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
                                    Tile *tile = GetTileSafe(curX, curY);

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
                                    Tile *tile = GetTileSafe(curX, curY);

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
                                    Tile *tile = GetTileSafe(curX, curY);

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
                                    Tile *tile = GetTileSafe(curX, curY);

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
void GenerateRoomImperfections(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY)
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
                        if (pt_x < grid[x][y].start.x || pt_x >= grid[x][y].end.x)
                            break;
                        if (pt_y < grid[x][y].start.y || pt_y >= grid[x][y].end.y)
                            break;

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
										Tile *tile = GetTile(nextX + offsetX, nextY + offsetY);

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
									SetTerrainWall(GetTileSafe(pt_x, pt_y));
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
void CreateHallway(s32 x, s32 y, s32 endX, s32 endY, bool8 vertical, s32 turnX_, s32 turnY_)
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
				SetTerrainNormal(GetTileSafe(x, y));
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
				SetTerrainNormal(GetTileSafe(x, y));
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
				SetTerrainNormal(GetTileSafe(x, y));
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
				SetTerrainNormal(GetTileSafe(x, y));
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
				SetTerrainNormal(GetTileSafe(x, y));
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
				SetTerrainNormal(GetTileSafe(x, y));
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
void EnsureConnectedGrid(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 *listX, s32 *listY)
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
                Tile *tile = GetTileSafe(grid[x][y].start.x, grid[x][y].start.y);
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
					Tile *tile = GetTileSafe(curX, curY);
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
void SetTerrainObstacleChecked(Tile *tile, bool8 useSecondaryTerrain, u8 roomIndex)
{
    SetTerrainWall(tile);
    if (useSecondaryTerrain && tile->room == roomIndex) {
        SetTerrainSecondary(tile);
    }
}

void sub_804E9DC(void)
{
    s32 x, y;

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            if (GetTerrainType(GetTile(x, y)) != TERRAIN_TYPE_NORMAL)
                continue;

            if (GetTile(x, y)->room == CORRIDOR_ROOM) {
                if (x > 0) {
                    Tile *tile = GetTileSafe(x - 1, y);
                    if (tile->room != CORRIDOR_ROOM) {
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;

                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
                if (y > 0) {
                    Tile *tile = GetTileSafe(x, y - 1);
                    if (tile->room != CORRIDOR_ROOM) {
                        // Yes, these |= have to be duplicated in order to match. Either it's an error and they wanted to use a different flag, or just copy-pasted it twice.
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
                if (y < DUNGEON_MAX_SIZE_Y - 1) {
                    Tile *tile = GetTileSafe(x, y + 1);
                    if (tile->room != CORRIDOR_ROOM) {
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
                if (x < DUNGEON_MAX_SIZE_X - 1) {
                    Tile *tile = GetTileSafe(x + 1, y);
                    if (tile->room != CORRIDOR_ROOM) {
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        tile->terrainType |= TERRAIN_TYPE_NATURAL_JUNCTION;
                        if (GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY) {
                            SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
                        }
                    }
                }
            }
            else if (GetTile(x, y)->room == ROOM_0xFE) {
                GetTileSafe(x, y)->room = CORRIDOR_ROOM;
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
void GenerateKecleonShop(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance)
{
    s16 listX[GRID_CELL_LEN];
    s16 listY[GRID_CELL_LEN];
    s32 x, y;
    s32 i, j;
    Dungeon *dungeon = gDungeon;

    gUnknown_202F1D8.x = -1;
    gUnknown_202F1D8.y = -1;

	if (gUnknown_202F1AB || GetFloorType() == FLOOR_TYPE_RESCUE || chance == 0)
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
			gUnknown_202F1AA = TRUE;
			grid[x][y].isKecleonShop = TRUE;

			// Make the shop span the whole room
			gUnknown_202F1B8.minX = grid[x][y].start.x + 1;
            gUnknown_202F1B8.maxX = grid[x][y].end.x - 1;
            gUnknown_202F1B8.minY = grid[x][y].start.y + 1;
			gUnknown_202F1B8.maxY = grid[x][y].end.y - 1;

			if (gUnknown_202F1B8.maxY  - gUnknown_202F1B8.minY < 3) {
				// This should never happen?
				gUnknown_202F1B8.maxY++;
			}

			// Set to values that guarantee they'll be replaced later
			dungeon->kecleonShopPos.minX = DEFAULT_MAX_POSITION;
			dungeon->kecleonShopPos.minY = DEFAULT_MAX_POSITION;
			dungeon->kecleonShopPos.maxX = -DEFAULT_MAX_POSITION;
			dungeon->kecleonShopPos.maxY = -DEFAULT_MAX_POSITION;

			// Generate the actual shop on the interior, leaving
			// a 1-tile border from the room walls
			for (curX = gUnknown_202F1B8.minX; curX < gUnknown_202F1B8.maxX; curX++) {
				for (curY = gUnknown_202F1B8.minY; curY < gUnknown_202F1B8.maxY; curY++) {
                    Tile *tile = GetTileSafe(curX, curY);

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
                    GetTileSafe(curX, curY)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
				}
			}

            curX = (gUnknown_202F1B8.minX + gUnknown_202F1B8.maxX) / 2;
            curY = (gUnknown_202F1B8.minY + gUnknown_202F1B8.maxY) / 2;
			gUnknown_202F1D8.x = curX;
			gUnknown_202F1D8.y = curY;

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
void GenerateMonsterHouse(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance)
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
	if (gUnknown_202F1AA)
        return;
	if (gDungeon->unk688 != 0)
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
                gUnknown_202F1AB = TRUE;
                grid[x][y].isMonsterHouse = TRUE;

                for (curX = grid[x][y].start.x; curX < grid[x][y].end.x; curX++) {
                    for (curY = grid[x][y].start.y; curY < grid[x][y].end.y; curY++) {
                        GetTileSafe(curX, curY)->terrainType |= TERRAIN_TYPE_IN_MONSTER_HOUSE;
                        dungeon->unk3A0C = GetTile(curX, curY)->room;
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
void GenerateMazeRoom(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 gridSizeX, s32 gridSizeY, s32 chance)
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
void GenerateMaze(struct GridCell *gridCell, bool8 useSecondaryTerrain)
{
    s32 curX, curY;
    u8 roomIndex;

	gUnknown_202F1AC = TRUE;
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
                    SetTerrainSecondary(GetTileSafe(curX - 1, curY));
				}
				else {
					SetTerrainWall(GetTileSafe(curX - 1, curY));
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
 * First, an obstacle is placed at the given position (see: SetTerrainObstacleChecked)
 *
 * Then, a random direction is selected, searching for an open tile distance 2 away from (x0, y0).
 * Each direction is attempted rotating counter-clockwise until an open tile is found or all directions are exhausted.
 *
 * If an open tile is found, an obstacle is placed between the two tiles, and (x0, y0) moves to the new open tile.
 * This process continues until no valid open tile can be found.
 */
void GenerateMazeLine(s32 x0, s32 y0, s32 xMin, s32 yMin, s32 xMax, s32 yMax, bool8 useSecondaryTerrain, u32 roomIndex)
{
	while (1) {
		s32 direction = DungeonRandInt(NUM_CARDINAL_DIRECTIONS);
        s32 i = 0;

		SetTerrainObstacleChecked(GetTileSafe(x0, y0), useSecondaryTerrain, roomIndex);

        while (1) {
			s32 offsetX, offsetY;
			s32 posX, posY;

			// Offset from our current position to look 2 tiles in a given direction
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

			// Check that this position is in-bounds
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
                SetTerrainObstacleChecked(GetTileSafe(x0 + 1, y0), useSecondaryTerrain, roomIndex);

				x0 += 2;
                break;
            case CARDINAL_DIR_UP:
                SetTerrainObstacleChecked(GetTileSafe(x0, y0 - 1), useSecondaryTerrain, roomIndex);

				y0 -= 2;
                break;
            case CARDINAL_DIR_LEFT:
                SetTerrainObstacleChecked(GetTileSafe(x0 - 1, y0), useSecondaryTerrain, roomIndex);

				x0 -= 2;
                break;
            case CARDINAL_DIR_DOWN:
                SetTerrainObstacleChecked(GetTileSafe(x0, y0 + 1), useSecondaryTerrain, roomIndex);

				y0 += 2;
                break;
		}
	}
}

void SetTerrainSecondaryWithFlag(Tile *tile, u32 additionalFlag)
{
    SetTerrainSecondary(tile);
    tile->terrainType |= additionalFlag;
}

/*
 * SetSpawnFlag5 - Sets unknown spawn flag 0x5 on all tiles in a room
 */
void SetSpawnFlag5(struct GridCell *gridCell)
{
    s32 x, y;

	for (x = gridCell->start.x; x < gridCell->end.x; x++) {
		for (y = gridCell->start.y; y < gridCell->end.y; y++) {
            GetTileSafe(x, y)->spawnOrVisibilityFlags |= SPAWN_FLAG_UNK5;
		}
	}
}

/*
 * IsNextToHallway - Checks if a tile position is either in a hallway or next to one.
 */
bool8 IsNextToHallway(s32 x, s32 y)
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
void GenerateSecondaryStructure(struct GridCell *gridCell)
{
    switch (DungeonRandInt(6)) {
        // Generate a "split room" with two sides separated by a line of water/lava
        case SECONDARY_STRUCTURE_DIVIDER:
            if (gUnknown_202F1C8 != 0) {
                s32 i;

                gUnknown_202F1C8--;

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
                            SetTerrainSecondaryWithFlag(GetTileSafe(middleX, i), 0);
						}

						for (curX = gridCell->start.x; curX < middleX; curX++) {
							for (curY = gridCell->start.y; curY < gridCell->end.y; curY++) {
                                GetTileSafe(curX, curY)->terrainType |= TERRAIN_TYPE_UNK_7;
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
							SetTerrainSecondaryWithFlag(GetTileSafe(i, middleY), 0);
						}

						for (curY = gridCell->start.y; curY < middleY; curY++) {
                            for (curX = gridCell->start.x; curX < gridCell->end.x; curX++) {
								GetTileSafe(curX, curY)->terrainType |= TERRAIN_TYPE_UNK_7;
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
                if (gUnknown_202F1C8 != 0) {
                    gUnknown_202F1C8--;

                    SetSpawnFlag5(gridCell);

                    // Water "Moat"
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 2, middleY - 2), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 1, middleY - 2), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX, middleY - 2), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX + 1, middleY - 2), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 2, middleY - 1), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 2, middleY), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 2, middleY + 1), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 2, middleY + 1), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 1, middleY + 1), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX, middleY + 1), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX + 1, middleY - 2), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX + 1, middleY - 1), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX + 1, middleY), TERRAIN_TYPE_UNK_2);
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX + 1, middleY + 1), TERRAIN_TYPE_UNK_2);

                    // Trap
                    GetTileSafe(middleX - 1, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_TRAP;
                    // Warp Tile ?
                    GetTileSafe(middleX - 1, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_UNK6;

                    // Items
                    GetTileSafe(middleX, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
                    GetTileSafe(middleX - 1, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
                    GetTileSafe(middleX, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_ITEM;
                    GetTileSafe(middleX - 1, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
                    GetTileSafe(middleX, middleY - 1)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
                    GetTileSafe(middleX - 1, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;
                    GetTileSafe(middleX, middleY)->spawnOrVisibilityFlags |= SPAWN_FLAG_SPECIAL_TILE;

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

                if (gUnknown_202F1C8 != 0) {
                    gUnknown_202F1C8--;

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
                            SetTerrainSecondaryWithFlag(GetTileSafe(curX, curY), 0);
                        }
                    }

                    gridCell->hasSecondaryStructure = TRUE;
                }
            }
            break;
        case SECONDARY_STRUCTURE_CHECKERBOARD:
            if ((gridCell->end.x - gridCell->start.x) % 2 != 0 && (gridCell->end.y - gridCell->start.y) % 2 != 0 && gUnknown_202F1C8 != 0) {
                s32 i;
                // Dimensions are odd, generate diagonal stripes/checkerboard of water/lava
                gUnknown_202F1C8--;

                SetSpawnFlag5(gridCell);

                for (i = 0; i < 64; i++) {
                    s32 randX = DungeonRandInt(gridCell->end.x - gridCell->start.x);
                    s32 randY = DungeonRandInt(gridCell->end.y - gridCell->start.y);
                    if ((randX + randY) % 2 != 0) {
                        SetTerrainSecondaryWithFlag(GetTileSafe(gridCell->start.x + randX, gridCell->start.y + randY), 0);
                    }
                }

                gridCell->hasSecondaryStructure = TRUE;
            }
            break;
        case SECONDARY_STRUCTURE_MAZE_PLUS_DOT:
            if (gUnknown_202F1C8 != 0) {
                gUnknown_202F1C8--;

                // If the dimensions are odd, generate a maze room
				if ((gridCell->end.x - gridCell->start.x) % 2 == 0 || (gridCell->end.y - gridCell->start.y) % 2 == 0) {
                    s32 middleX = (gridCell->start.x + gridCell->end.x) / 2;
                    s32 middleY = (gridCell->start.y + gridCell->end.y) / 2;
					if ((gridCell->end.x - gridCell->start.x) >= 5 && (gridCell->end.y - gridCell->start.y) >= 5) {
						// Both dimensions are at least 5, generate a water/lava cross in the center
						SetTerrainSecondaryWithFlag(GetTileSafe(middleX + 1, middleY), 0);
						SetTerrainSecondaryWithFlag(GetTileSafe(middleX, middleY + 1), 0);
						SetTerrainSecondaryWithFlag(GetTileSafe(middleX - 1, middleY), 0);
						SetTerrainSecondaryWithFlag(GetTileSafe(middleX, middleY - 1), 0);
					}

                    // Generate a single water/lava spot in the center
                    SetTerrainSecondaryWithFlag(GetTileSafe(middleX, middleY), 0);
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
void ResolveInvalidSpawns(void)
{
    s32 x, y;

    for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            Tile *tile = GetTileSafe(x, y);
            if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL) {
                if (tile->terrainType & (TERRAIN_TYPE_UNK_8 | TERRAIN_TYPE_IMPASSABLE_WALL)) {
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

//
