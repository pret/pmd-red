#include "global.h"
#include "file_system.h"
#include "tile_types.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "structs/str_dungeon.h"
#include "structs/map.h"

extern const u8 gUnknown_80F6DCC[];
extern struct FileArchive gDungeonFileArchive;

extern u8 gUnknown_202F1AA;
extern u8 gUnknown_202F1AB;
extern u8 gUnknown_202F1AC;
extern u8 gUnknown_202F1A8;
extern u8 gUnknown_202F1B4;
extern u8 gUnknown_202F1AE;
extern u8 gUnknown_202F1AD;
extern u8 gUnknown_202F1A9;
extern s16 gUnknown_202F1B0;
extern s16 gUnknown_202F1B2;
extern s32 gUnknown_202F1C8;
extern s32 gUnknown_202F1D0;
extern Position gUnknown_202F1D8;

struct UnkStruct_202F1B8
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern struct UnkStruct_202F1B8 gUnknown_202F1B8;

extern void sub_804FD30(void);
extern void sub_804FD30(void);
extern void sub_80518F0(void);
extern void sub_804FCCC(void);
extern void sub_804C918(void);
extern void sub_804FBE8(void);
extern void sub_804FC74(void);
extern void sub_804E9DC(void);
extern void sub_804C9D0(void);
extern u8 sub_8043D10();
extern bool8 sub_8050C30(s32 a0, s32 a1, u8 a2);
extern void sub_806C330(s32 a0, s32 a1, s16 a2, u8 a3);

void sub_804B534(s32 a0, s32 a1, s32 a2, s32 a3);
bool8 sub_804C70C(s32, UnkDungeonGlobal_unk1C574 *);
void sub_804B634(s32 a0, s32 a1, UnkDungeonGlobal_unk1C574 *a2);
void sub_804B72C(UnkDungeonGlobal_unk1C574 *a0);
void sub_804BC80(UnkDungeonGlobal_unk1C574 *a0);
void sub_804C0A8(UnkDungeonGlobal_unk1C574 *a0);
void sub_804C190(UnkDungeonGlobal_unk1C574 *a0);
void sub_804C2F4(UnkDungeonGlobal_unk1C574 *a0);
void sub_8051654(UnkDungeonGlobal_unk1C574 *a0);
void sub_80506F0(s32 a0, UnkDungeonGlobal_unk1C574 *a1);
void sub_804FF08(UnkDungeonGlobal_unk1C574 *a0, bool8 a1);
void sub_8050438(UnkDungeonGlobal_unk1C574 *a0, bool8 a1);

struct FileFixedmapPosStruct
{
    u8 x;
    u8 y;
};

// Some weird-ass regswap prevents the function from being matched - https://decomp.me/scratch/9SUV3
#ifdef NONMATCHING
void sub_804AFAC(void)
{
    s32 x, y;
    s32 i, j, k;
    bool8 r10 = FALSE;
    UnkDungeonGlobal_unk1C574 *unkPtr = &gDungeon->unk1C574;

    gDungeon->unk13568 = OpenFileAndGetFileDataPtr(gUnknown_80F6DCC, &gDungeonFileArchive);
    gUnknown_202F1AA = 0;
    gUnknown_202F1AB = 0;
    gUnknown_202F1AC = 0;
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
                        sub_804B634(4, y, unkPtr);
                        r10 = TRUE;
                        break;
                    case 11:
                        y = DungeonRandInt(2) + 2;
                        gUnknown_202F1AE = 2;
                        sub_804B634(4, y, unkPtr);
                        r10 = TRUE;
                        break;
                    case 0:
                    default:
                        sub_804B634(x, y, unkPtr);
                        r10 = TRUE;
                        break;
                    case 2:
                        sub_804C918();
                        gDungeon->unk3A08 = 1;
                        break;
                    case 3:
                        sub_804B72C(unkPtr);
                        r10 = TRUE;
                        break;
                    case 4:
                        sub_804BC80(unkPtr);
                        r10 = TRUE;
                        break;
                    case 5:
                        sub_804C9D0();
                        gDungeon->unk3A08 = 1;
                        break;
                    case 6:
                        sub_804C0A8(unkPtr);
                        r10 = TRUE;
                        break;
                    case 7:
                        sub_804C190(unkPtr);
                        break;
                    case 9:
                        sub_804C2F4(unkPtr);
                        break;
                    case 10:
                        sub_804B634(x, y, unkPtr);
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
            sub_804C918();
            gDungeon->unk3A08 = 1;
        }
        sub_804E9DC();
        if (r10) {
            sub_80506F0(1, unkPtr);
        }
        r4 = (DungeonRandInt(100) < unkPtr->unk19);
        sub_804FF08(unkPtr, r4);
        sub_8050438(unkPtr, r4);
        sub_804FBE8();
        if (gDungeon->unkE218.x != -1 && gDungeon->unkE218.y != -1)
        {
            if (sub_8043D10() == 1)
                break;
            if (gDungeon->unkE21C.x != -1 && gDungeon->unkE21C.y != -1 && sub_8050C30(gDungeon->unkE21C.x, gDungeon->unkE21C.y, 0))
                break;
        }
    }

    if (i == 10) {
        gUnknown_202F1D8.x = -1;
        gUnknown_202F1D8.y = -1;
        sub_804FD30();
        sub_804C918();
        gDungeon->unk3A08 = 1;
        sub_804E9DC();
        sub_804FF08(unkPtr, FALSE);
        sub_8050438(unkPtr, FALSE);
        sub_804FBE8();
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
"	bl sub_804B634\n"
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
"	bl sub_804B634\n"
"	movs r6, 0x1\n"
"	mov r10, r6\n"
"	b _0804B2F6\n"
"	.align 2, 0\n"
"_0804B270: .4byte gUnknown_202F1AE\n"
"_0804B274:\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	mov r2, r8\n"
"	bl sub_804B634\n"
"	b _0804B2D2\n"
"_0804B280:\n"
"	bl sub_804C918\n"
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
"	bl sub_804B72C\n"
"	movs r2, 0x1\n"
"	mov r10, r2\n"
"	b _0804B2F6\n"
"_0804B2A4:\n"
"	mov r0, r8\n"
"	bl sub_804BC80\n"
"_0804B2AA:\n"
"	movs r3, 0x1\n"
"	mov r10, r3\n"
"	b _0804B2F6\n"
"_0804B2B0:\n"
"	bl sub_804C9D0\n"
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
"	bl sub_804C0A8\n"
"_0804B2D2:\n"
"	movs r0, 0x1\n"
"	mov r10, r0\n"
"	b _0804B2F6\n"
"_0804B2D8:\n"
"	mov r0, r8\n"
"	bl sub_804C190\n"
"	b _0804B2F6\n"
"_0804B2E0:\n"
"	mov r0, r8\n"
"	bl sub_804C2F4\n"
"	b _0804B2F6\n"
"_0804B2E8:\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	mov r2, r8\n"
"	bl sub_804C53C\n"
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
"	bl sub_804C918\n"
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
"	bl sub_804FBE8\n"
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
"	bl sub_8043D10\n"
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
"	bl sub_804C918\n"
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
"	bl sub_804FBE8\n"
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
            if (tile->room == CORRIDOR_ROOM && ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL)) {
                if (x > 0 && ((GetTile(x - 1, y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL))
                    unkCount++;
                if (y > 0 && ((GetTile(x, y - 1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL))
                    unkCount++;
                if (x < DUNGEON_MAX_SIZE_X - 2 && ((GetTile(x + 1, y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL))
                    unkCount++;
                // BUG: It should check for y and not x. Not sure if it has any effect, because this function is called only once with maxY equal to DUNGEON_MAX_SIZE_Y
                if (x < DUNGEON_MAX_SIZE_Y - 2 && ((GetTile(x, y + 1)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL))
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
    Position unk0;
    Position unk4;
    u8 unk8;
    u8 unk9;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk30;
    u8 unk31;
};

#define GRID_CELL_LEN 15

void sub_804D024(s32 *a0, s32 *a1, s32 x, s32 y);
void sub_804D084(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y);
void sub_804E03C(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y);
void sub_804D534(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y);
void sub_804D154(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 a3);
void sub_804D2D0(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 *a3, s32 *a4, s32 a5);
void sub_804D8C8(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 *a3, s32 *a4, s32 a5);
void sub_804E590(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 *a3, s32 *a4);
void sub_804D5B0(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, UnkDungeonGlobal_unk1C574 *unkPtr);
void sub_804F0D0(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 a3);
void sub_804EBC8(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 a3);
void sub_804EEE4(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 a3);
void sub_804CBEC(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 a3);
void sub_804C43C(s32 a0, s32 a1, s32 a2, struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN]);

void sub_804B634(s32 x, s32 y, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 unk7200[GRID_CELL_LEN];
    s32 unk7260[GRID_CELL_LEN];

    sub_804D024(unk7200, unk7260, x, y);
    sub_804D084(grid, x, y);
    sub_804D154(grid, x, y, unkPtr->unk1);
    sub_804D2D0(grid, x, y, unk7200, unk7260, unkPtr->unkD);
    sub_804D5B0(grid, x, y, unkPtr);
    sub_804D8C8(grid, x, y, unk7200, unk7260, 0);
    sub_804E590(grid, x, y, unk7200, unk7260);
    sub_804F0D0(grid, x, y, unkPtr->unk9);
    sub_804EBC8(grid, x, y, gUnknown_202F1B0);
    sub_804EEE4(grid, x, y, gUnknown_202F1B2);
    sub_804CBEC(grid, x, y, unkPtr->unk13);
    sub_804E03C(grid, x, y);
    sub_804D534(grid, x, y);
}

// Decompile once data structure is better understood

#ifdef NONMATCHING
void sub_804B72C(UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct GridCell grid[15][15];

    sp.unk7200[0] = 0;
    sp.unk7200[1] = 5;
    sp.unk7200[3] = 28;
    sp.unk7200[5] = 51
    sp.unk7200[6] = 56;
    sp.unk7200[2] = 16;
    sp.unk7200[4] = 29;

    sp.unk7260[0] = 2;
    sp.unk7260[1] = 7;
    sp.unk7260[2] = 16;
    sp.unk7260[3] = 25;
    sp.unk7260[4] = 30;

    sub_804D084(grid, 6, 4);
}
#else
NAKED void sub_804B72C(UnkDungeonGlobal_unk1C574 *unkPtr)
{
    asm_unified("push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	ldr r4, _0804B9AC\n"
"	add sp, r4\n"
"	movs r1, 0xE5\n"
"	lsls r1, 5\n"
"	add r1, sp\n"
"	str r0, [r1]\n"
"	movs r5, 0\n"
"	movs r6, 0x1\n"
"	ldr r1, _0804B9B0\n"
"	add r1, sp\n"
"	str r5, [r1]\n"
"	movs r0, 0x5\n"
"	str r0, [r1, 0x4]\n"
"	movs r0, 0x1C\n"
"	str r0, [r1, 0xC]\n"
"	movs r0, 0x33\n"
"	str r0, [r1, 0x14]\n"
"	movs r0, 0x38\n"
"	str r0, [r1, 0x18]\n"
"	movs r2, 0x10\n"
"	str r2, [r1, 0x8]\n"
"	movs r0, 0x27\n"
"	str r0, [r1, 0x10]\n"
"	ldr r1, _0804B9B4\n"
"	add r1, sp\n"
"	movs r0, 0x2\n"
"	str r0, [r1]\n"
"	movs r0, 0x7\n"
"	str r0, [r1, 0x4]\n"
"	str r2, [r1, 0x8]\n"
"	movs r0, 0x19\n"
"	str r0, [r1, 0xC]\n"
"	movs r0, 0x1E\n"
"	str r0, [r1, 0x10]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	bl sub_804D084\n"
"	mov r2, sp\n"
"	adds r2, 0x3B\n"
"	ldr r3, _0804B9B8\n"
"	add r3, sp\n"
"	str r2, [r3]\n"
"	mov r4, sp\n"
"	adds r4, 0x3C\n"
"	ldr r0, _0804B9BC\n"
"	add r0, sp\n"
"	str r4, [r0]\n"
"	mov r1, sp\n"
"	adds r1, 0x5B\n"
"	ldr r2, _0804B9C0\n"
"	add r2, sp\n"
"	str r1, [r2]\n"
"	mov r3, sp\n"
"	adds r3, 0x5C\n"
"	movs r4, 0xE6\n"
"	lsls r4, 5\n"
"	add r4, sp\n"
"	str r3, [r4]\n"
"	mov r0, sp\n"
"	adds r0, 0x7B\n"
"	ldr r1, _0804B9C4\n"
"	add r1, sp\n"
"	str r0, [r1]\n"
"	mov r2, sp\n"
"	adds r2, 0x7E\n"
"	ldr r3, _0804B9C8\n"
"	add r3, sp\n"
"	str r2, [r3]\n"
"	add r1, sp, 0x68\n"
"	add r0, sp, 0x8\n"
"	movs r2, 0xF0\n"
"	lsls r2, 1\n"
"	movs r4, 0x6\n"
"_0804B7CC:\n"
"	strb r5, [r0, 0xA]\n"
"	strb r5, [r1, 0xA]\n"
"	adds r1, r2\n"
"	adds r0, r2\n"
"	subs r4, 0x1\n"
"	cmp r4, 0\n"
"	bne _0804B7CC\n"
"	movs r2, 0x6\n"
"	subs r2, 0x1\n"
"	movs r4, 0x4\n"
"	cmp r4, 0\n"
"	beq _0804B80C\n"
"	lsls r0, r2, 4\n"
"	subs r0, r2\n"
"	lsls r0, 5\n"
"	add r0, sp\n"
"	adds r0, 0x8\n"
"	add r1, sp, 0x8\n"
"	ldr r3, _0804B9CC\n"
"	add r3, sp\n"
"	str r4, [r3]\n"
"_0804B7F6:\n"
"	strb r5, [r1, 0xA]\n"
"	strb r5, [r0, 0xA]\n"
"	adds r0, 0x20\n"
"	adds r1, 0x20\n"
"	ldr r3, _0804B9CC\n"
"	add r3, sp\n"
"	ldr r4, [r3]\n"
"	subs r4, 0x1\n"
"	str r4, [r3]\n"
"	cmp r4, 0\n"
"	bne _0804B7F6\n"
"_0804B80C:\n"
"	movs r4, 0x1\n"
"	cmp r4, r2\n"
"	bge _0804B848\n"
"	movs r1, 0x3\n"
"_0804B814:\n"
"	adds r5, r4, 0x1\n"
"	mov r8, r5\n"
"	cmp r1, 0x1\n"
"	ble _0804B842\n"
"	lsls r0, r4, 4\n"
"	subs r0, r4\n"
"	lsls r0, 5\n"
"	add r0, sp\n"
"	adds r0, 0x8\n"
"	adds r0, 0x20\n"
"	subs r3, r1, 0x1\n"
"	ldr r4, _0804B9CC\n"
"	add r4, sp\n"
"	str r3, [r4]\n"
"_0804B830:\n"
"	strb r6, [r0, 0xA]\n"
"	adds r0, 0x20\n"
"	ldr r3, _0804B9CC\n"
"	add r3, sp\n"
"	ldr r5, [r3]\n"
"	subs r5, 0x1\n"
"	str r5, [r3]\n"
"	cmp r5, 0\n"
"	bne _0804B830\n"
"_0804B842:\n"
"	mov r4, r8\n"
"	cmp r4, r2\n"
"	blt _0804B814\n"
"_0804B848:\n"
"	movs r4, 0\n"
"	ldr r5, _0804B9D0\n"
"	add r5, sp\n"
"	str r4, [r5]\n"
"	ldr r0, _0804B9CC\n"
"	add r0, sp\n"
"	str r4, [r0]\n"
"	cmp r4, 0x4\n"
"	blt _0804B85C\n"
"	b _0804BA8C\n"
"_0804B85C:\n"
"	movs r4, 0\n"
"	ldr r2, _0804B9CC\n"
"	add r2, sp\n"
"	ldr r1, [r2]\n"
"	adds r1, 0x1\n"
"	ldr r2, _0804B9D4\n"
"	add r2, sp\n"
"	str r1, [r2]\n"
"	cmp r4, 0x6\n"
"	blt _0804B872\n"
"	b _0804BA7A\n"
"_0804B872:\n"
"	ldr r3, _0804B9B0\n"
"	add r3, sp\n"
"	ldr r5, _0804B9D8\n"
"	add r5, sp\n"
"	str r3, [r5]\n"
"	ldr r0, _0804B9B4\n"
"	add r0, sp\n"
"	ldr r1, _0804B9DC\n"
"	add r1, sp\n"
"	str r0, [r1]\n"
"	ldr r2, _0804B9CC\n"
"	add r2, sp\n"
"	ldr r2, [r2]\n"
"	lsls r0, r2, 2\n"
"	ldr r3, [r1]\n"
"	adds r0, r3, r0\n"
"	ldr r3, _0804B9E0\n"
"	add r3, sp\n"
"	str r0, [r3]\n"
"_0804B898:\n"
"	lsls r0, r4, 4\n"
"	subs r0, r4\n"
"	ldr r5, _0804B9CC\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	adds r0, r5\n"
"	lsls r0, 5\n"
"	mov r7, sp\n"
"	adds r7, r0\n"
"	adds r7, 0x8\n"
"	ldrb r0, [r7, 0xA]\n"
"	cmp r0, 0\n"
"	bne _0804B8B4\n"
"	b _0804B9F4\n"
"_0804B8B4:\n"
"	lsls r0, r4, 2\n"
"	ldr r1, _0804B9D8\n"
"	add r1, sp\n"
"	ldr r1, [r1]\n"
"	adds r0, r1, r0\n"
"	ldr r1, [r0]\n"
"	adds r2, r1, 0x2\n"
"	mov r10, r2\n"
"	ldr r3, _0804B9E0\n"
"	add r3, sp\n"
"	ldr r3, [r3]\n"
"	ldr r2, [r3]\n"
"	adds r5, r2, 0x2\n"
"	ldr r0, _0804B9E4\n"
"	add r0, sp\n"
"	str r5, [r0]\n"
"	adds r4, 0x1\n"
"	mov r9, r4\n"
"	lsls r0, r4, 2\n"
"	ldr r3, _0804B9D8\n"
"	add r3, sp\n"
"	ldr r3, [r3]\n"
"	adds r0, r3, r0\n"
"	ldr r4, [r0]\n"
"	subs r4, r1\n"
"	subs r4, 0x3\n"
"	ldr r5, _0804B9D4\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	lsls r0, r5, 2\n"
"	ldr r1, _0804B9DC\n"
"	add r1, sp\n"
"	ldr r1, [r1]\n"
"	adds r0, r1, r0\n"
"	ldr r5, [r0]\n"
"	subs r5, r2\n"
"	subs r5, 0x3\n"
"	movs r0, 0x5\n"
"	adds r1, r4, 0\n"
"	bl DungeonRandRange\n"
"	mov r8, r0\n"
"	movs r0, 0x4\n"
"	adds r1, r5, 0\n"
"	bl DungeonRandRange\n"
"	adds r6, r0, 0\n"
"	mov r2, r8\n"
"	subs r4, r2\n"
"	adds r0, r4, 0\n"
"	bl DungeonRandInt\n"
"	adds r4, r0, 0\n"
"	add r4, r10\n"
"	subs r5, r6\n"
"	adds r0, r5, 0\n"
"	bl DungeonRandInt\n"
"	ldr r5, _0804B9E4\n"
"	add r5, sp\n"
"	ldr r3, [r5]\n"
"	adds r3, r0\n"
"	mov r10, r3\n"
"	mov r0, r8\n"
"	adds r3, r4, r0\n"
"	add r6, r10\n"
"	strh r4, [r7]\n"
"	strh r3, [r7, 0x4]\n"
"	mov r1, r10\n"
"	strh r1, [r7, 0x2]\n"
"	strh r6, [r7, 0x6]\n"
"	mov r8, r9\n"
"	ldr r5, _0804B9D0\n"
"	add r5, sp\n"
"	ldr r2, [r5]\n"
"	adds r2, 0x1\n"
"	ldr r5, _0804B9E8\n"
"	add r5, sp\n"
"	str r2, [r5]\n"
"	cmp r4, r3\n"
"	bge _0804B99E\n"
"_0804B956:\n"
"	mov r5, r10\n"
"	adds r7, r4, 0x1\n"
"	cmp r5, r6\n"
"	bge _0804B998\n"
"	ldr r0, _0804B9EC\n"
"	mov r9, r0\n"
"_0804B962:\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	ldr r2, _0804B9F0\n"
"	add r2, sp\n"
"	str r3, [r2]\n"
"	bl GetTileSafe\n"
"	ldrh r1, [r0]\n"
"	mov r2, r9\n"
"	ands r1, r2\n"
"	movs r2, 0x1\n"
"	orrs r1, r2\n"
"	strh r1, [r0]\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	bl GetTileSafe\n"
"	ldr r1, _0804B9D0\n"
"	add r1, sp\n"
"	ldrb r1, [r1]\n"
"	strb r1, [r0, 0x9]\n"
"	adds r5, 0x1\n"
"	ldr r2, _0804B9F0\n"
"	add r2, sp\n"
"	ldr r3, [r2]\n"
"	cmp r5, r6\n"
"	blt _0804B962\n"
"_0804B998:\n"
"	adds r4, r7, 0\n"
"	cmp r4, r3\n"
"	blt _0804B956\n"
"_0804B99E:\n"
"	ldr r3, _0804B9E8\n"
"	add r3, sp\n"
"	ldr r3, [r3]\n"
"	ldr r4, _0804B9D0\n"
"	add r4, sp\n"
"	str r3, [r4]\n"
"	b _0804BA72\n"
"	.align 2, 0\n"
"_0804B9AC: .4byte 0xffffe320\n"
"_0804B9B0: .4byte 0x00001c28\n"
"_0804B9B4: .4byte 0x00001c64\n"
"_0804B9B8: .4byte 0x00001cd4\n"
"_0804B9BC: .4byte 0x00001cd8\n"
"_0804B9C0: .4byte 0x00001cbc\n"
"_0804B9C4: .4byte 0x00001cc4\n"
"_0804B9C8: .4byte 0x00001cc8\n"
"_0804B9CC: .4byte 0x00001ca4\n"
"_0804B9D0: .4byte 0x00001ca8\n"
"_0804B9D4: .4byte 0x00001ccc\n"
"_0804B9D8: .4byte 0x00001cac\n"
"_0804B9DC: .4byte 0x00001cb4\n"
"_0804B9E0: .4byte 0x00001cb8\n"
"_0804B9E4: .4byte 0x00001cb0\n"
"_0804B9E8: .4byte 0x00001cd0\n"
"_0804B9EC: .4byte 0x0000fffc\n"
"_0804B9F0: .4byte 0x00001cdc\n"
"_0804B9F4:\n"
"	lsls r0, r4, 2\n"
"	ldr r5, _0804BBE8\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	adds r0, r5, r0\n"
"	ldr r2, [r0]\n"
"	adds r0, r2, 0x1\n"
"	ldr r1, _0804BBEC\n"
"	add r1, sp\n"
"	ldr r1, [r1]\n"
"	ldr r3, [r1]\n"
"	adds r6, r3, 0x1\n"
"	adds r4, 0x1\n"
"	mov r8, r4\n"
"	lsls r1, r4, 2\n"
"	adds r1, r5, r1\n"
"	ldr r1, [r1]\n"
"	subs r1, r2\n"
"	subs r1, 0x3\n"
"	ldr r5, _0804BBF0\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	lsls r2, r5, 2\n"
"	ldr r4, _0804BBF4\n"
"	add r4, sp\n"
"	ldr r4, [r4]\n"
"	adds r2, r4, r2\n"
"	ldr r4, [r2]\n"
"	subs r4, r3\n"
"	subs r4, 0x3\n"
"	adds r1, r0, r1\n"
"	bl DungeonRandRange\n"
"	adds r5, r0, 0\n"
"	adds r4, r6, r4\n"
"	adds r0, r6, 0\n"
"	adds r1, r4, 0\n"
"	bl DungeonRandRange\n"
"	adds r4, r0, 0\n"
"	strh r5, [r7]\n"
"	adds r0, r5, 0x1\n"
"	strh r0, [r7, 0x4]\n"
"	strh r4, [r7, 0x2]\n"
"	adds r0, r4, 0x1\n"
"	strh r0, [r7, 0x6]\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	bl GetTileSafe\n"
"	ldrh r1, [r0]\n"
"	ldr r3, _0804BBF8\n"
"	adds r2, r3, 0\n"
"	ands r1, r2\n"
"	movs r2, 0x1\n"
"	orrs r1, r2\n"
"	strh r1, [r0]\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	bl GetTileSafe\n"
"	movs r1, 0xFF\n"
"	strb r1, [r0, 0x9]\n"
"_0804BA72:\n"
"	mov r4, r8\n"
"	cmp r4, 0x6\n"
"	bge _0804BA7A\n"
"	b _0804B898\n"
"_0804BA7A:\n"
"	ldr r4, _0804BBF0\n"
"	add r4, sp\n"
"	ldr r4, [r4]\n"
"	ldr r5, _0804BBFC\n"
"	add r5, sp\n"
"	str r4, [r5]\n"
"	cmp r4, 0x4\n"
"	bge _0804BA8C\n"
"	b _0804B85C\n"
"_0804BA8C:\n"
"	add r1, sp, 0x8\n"
"	movs r6, 0\n"
"	movs r0, 0x1\n"
"	strb r0, [r1, 0x16]\n"
"	ldr r1, _0804BC00\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	movs r1, 0xFF\n"
"	lsls r1, 1\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC04\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC08\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC0C\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC10\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC14\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC18\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC1C\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	add r1, sp, 0x8\n"
"	strb r0, [r1, 0x14]\n"
"	ldr r5, _0804BC20\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	strb r0, [r5]\n"
"	ldr r1, _0804BC24\n"
"	add r1, sp\n"
"	ldr r1, [r1]\n"
"	strb r0, [r1]\n"
"	ldr r2, _0804BC28\n"
"	add r2, sp\n"
"	ldr r2, [r2]\n"
"	strb r0, [r2]\n"
"	movs r3, 0xE6\n"
"	lsls r3, 5\n"
"	add r3, sp\n"
"	ldr r3, [r3]\n"
"	strb r0, [r3]\n"
"	ldr r4, _0804BC2C\n"
"	add r4, sp\n"
"	ldr r4, [r4]\n"
"	strb r0, [r4]\n"
"	ldr r5, _0804BC30\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	strb r0, [r5]\n"
"	ldr r1, _0804BC34\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC38\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC3C\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC40\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC44\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC48\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC4C\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC50\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC54\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC58\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC5C\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC60\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC64\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC68\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	ldr r1, _0804BC6C\n"
"	add r1, sp\n"
"	strb r0, [r1]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	movs r4, 0xE5\n"
"	lsls r4, 5\n"
"	add r4, sp\n"
"	ldr r3, [r4]\n"
"	bl sub_804D5B0\n"
"	ldr r5, _0804BC70\n"
"	add r5, sp\n"
"	ldr r4, _0804BC74\n"
"	add r4, sp\n"
"	str r4, [sp]\n"
"	str r6, [sp, 0x4]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	adds r3, r5, 0\n"
"	bl sub_804D8C8\n"
"	str r4, [sp]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	adds r3, r5, 0\n"
"	bl sub_804E590\n"
"	ldr r0, _0804BC78\n"
"	movs r5, 0\n"
"	ldrsh r3, [r0, r5]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	bl sub_804EBC8\n"
"	ldr r0, _0804BC7C\n"
"	movs r1, 0\n"
"	ldrsh r3, [r0, r1]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	bl sub_804EEE4\n"
"	movs r2, 0xE5\n"
"	lsls r2, 5\n"
"	add r2, sp\n"
"	ldr r2, [r2]\n"
"	ldrb r3, [r2, 0x13]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	bl sub_804CBEC\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x6\n"
"	movs r2, 0x4\n"
"	bl sub_804E03C\n"
"	movs r3, 0xE7\n"
"	lsls r3, 5\n"
"	add sp, r3\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0804BBE8: .4byte 0x00001cac\n"
"_0804BBEC: .4byte 0x00001cb8\n"
"_0804BBF0: .4byte 0x00001ccc\n"
"_0804BBF4: .4byte 0x00001cb4\n"
"_0804BBF8: .4byte 0x0000fffc\n"
"_0804BBFC: .4byte 0x00001ca4\n"
"_0804BC00: .4byte 0x000001fd\n"
"_0804BC04: .4byte 0x000003dd\n"
"_0804BC08: .4byte 0x000003de\n"
"_0804BC0C: .4byte 0x000005bd\n"
"_0804BC10: .4byte 0x000005be\n"
"_0804BC14: .4byte 0x0000079d\n"
"_0804BC18: .4byte 0x0000079e\n"
"_0804BC1C: .4byte 0x0000097d\n"
"_0804BC20: .4byte 0x00001cd4\n"
"_0804BC24: .4byte 0x00001cd8\n"
"_0804BC28: .4byte 0x00001cbc\n"
"_0804BC2C: .4byte 0x00001cc4\n"
"_0804BC30: .4byte 0x00001cc8\n"
"_0804BC34: .4byte 0x0000025d\n"
"_0804BC38: .4byte 0x0000025e\n"
"_0804BC3C: .4byte 0x0000043d\n"
"_0804BC40: .4byte 0x0000043e\n"
"_0804BC44: .4byte 0x0000061d\n"
"_0804BC48: .4byte 0x0000061e\n"
"_0804BC4C: .4byte 0x000007fd\n"
"_0804BC50: .4byte 0x000007fe\n"
"_0804BC54: .4byte 0x000009dd\n"
"_0804BC58: .4byte 0x0000097c\n"
"_0804BC5C: .4byte 0x0000099b\n"
"_0804BC60: .4byte 0x0000099c\n"
"_0804BC64: .4byte 0x000009bb\n"
"_0804BC68: .4byte 0x000009bc\n"
"_0804BC6C: .4byte 0x000009db\n"
"_0804BC70: .4byte 0x00001c28\n"
"_0804BC74: .4byte 0x00001c64\n"
"_0804BC78: .4byte gUnknown_202F1B0\n"
"_0804BC7C: .4byte gUnknown_202F1B2");
}
#endif // NONMATCHING

#ifdef NONMATCHING
void sub_804BC80(UnkDungeonGlobal_unk1C574 *a0)
{

}
#else
NAKED void sub_804BC80(UnkDungeonGlobal_unk1C574 *a0)
{
    asm_unified("push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	ldr r4, _0804BED0\n"
"	add sp, r4\n"
"	movs r1, 0xE5\n"
"	lsls r1, 5\n"
"	add r1, sp\n"
"	str r0, [r1]\n"
"	movs r4, 0x1\n"
"	movs r5, 0\n"
"	ldr r1, _0804BED4\n"
"	add r1, sp\n"
"	str r5, [r1]\n"
"	movs r0, 0xB\n"
"	str r0, [r1, 0x4]\n"
"	movs r0, 0x16\n"
"	str r0, [r1, 0x8]\n"
"	movs r0, 0x21\n"
"	str r0, [r1, 0xC]\n"
"	movs r0, 0x2C\n"
"	str r0, [r1, 0x10]\n"
"	movs r0, 0x38\n"
"	str r0, [r1, 0x14]\n"
"	ldr r1, _0804BED8\n"
"	add r1, sp\n"
"	str r4, [r1]\n"
"	movs r0, 0x9\n"
"	str r0, [r1, 0x4]\n"
"	movs r0, 0x10\n"
"	str r0, [r1, 0x8]\n"
"	movs r0, 0x17\n"
"	str r0, [r1, 0xC]\n"
"	movs r0, 0x1F\n"
"	str r0, [r1, 0x10]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x5\n"
"	movs r2, 0x4\n"
"	bl sub_804D084\n"
"	add r6, sp, 0x70\n"
"	add r1, sp, 0x68\n"
"	add r0, sp, 0x8\n"
"	movs r3, 0xF0\n"
"	lsls r3, 1\n"
"	movs r2, 0x5\n"
"_0804BCE0:\n"
"	strb r4, [r0, 0xA]\n"
"	strb r4, [r1, 0xA]\n"
"	adds r1, r3\n"
"	adds r0, r3\n"
"	subs r2, 0x1\n"
"	cmp r2, 0\n"
"	bne _0804BCE0\n"
"	movs r3, 0x5\n"
"	subs r3, 0x1\n"
"	movs r2, 0x4\n"
"	cmp r2, 0\n"
"	beq _0804BD1A\n"
"	lsls r0, r3, 4\n"
"	subs r0, r3\n"
"	lsls r0, 5\n"
"	add r0, sp\n"
"	adds r0, 0x8\n"
"	add r1, sp, 0x8\n"
"	mov r10, r2\n"
"_0804BD06:\n"
"	strb r4, [r1, 0xA]\n"
"	strb r4, [r0, 0xA]\n"
"	adds r0, 0x20\n"
"	adds r1, 0x20\n"
"	movs r2, 0x1\n"
"	negs r2, r2\n"
"	add r10, r2\n"
"	mov r2, r10\n"
"	cmp r2, 0\n"
"	bne _0804BD06\n"
"_0804BD1A:\n"
"	movs r2, 0x1\n"
"	cmp r2, r3\n"
"	bge _0804BD58\n"
"	movs r1, 0x3\n"
"_0804BD22:\n"
"	adds r4, r2, 0x1\n"
"	ldr r0, _0804BEDC\n"
"	add r0, sp\n"
"	str r4, [r0]\n"
"	cmp r1, 0x1\n"
"	ble _0804BD4E\n"
"	lsls r0, r2, 4\n"
"	subs r0, r2\n"
"	lsls r0, 5\n"
"	add r0, sp\n"
"	adds r0, 0x8\n"
"	adds r0, 0x20\n"
"	subs r2, r1, 0x1\n"
"	mov r10, r2\n"
"_0804BD3E:\n"
"	strb r5, [r0, 0xA]\n"
"	adds r0, 0x20\n"
"	movs r4, 0x1\n"
"	negs r4, r4\n"
"	add r10, r4\n"
"	mov r2, r10\n"
"	cmp r2, 0\n"
"	bne _0804BD3E\n"
"_0804BD4E:\n"
"	ldr r4, _0804BEDC\n"
"	add r4, sp\n"
"	ldr r2, [r4]\n"
"	cmp r2, r3\n"
"	blt _0804BD22\n"
"_0804BD58:\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x1\n"
"	strb r1, [r0, 0x8]\n"
"	movs r0, 0xF2\n"
"	lsls r0, 3\n"
"	add r0, sp\n"
"	strb r1, [r0]\n"
"	strb r1, [r6]\n"
"	movs r0, 0xFE\n"
"	lsls r0, 3\n"
"	add r0, sp\n"
"	strb r1, [r0]\n"
"	movs r5, 0\n"
"	ldr r6, _0804BEE0\n"
"	add r6, sp\n"
"	str r5, [r6]\n"
"	mov r10, r5\n"
"	cmp r5, 0x4\n"
"	blt _0804BD80\n"
"	b _0804BFAC\n"
"_0804BD80:\n"
"	movs r0, 0x4\n"
"	movs r1, 0xE6\n"
"	lsls r1, 5\n"
"	add r1, sp\n"
"	str r0, [r1]\n"
"_0804BD8A:\n"
"	movs r2, 0\n"
"	cmp r2, 0x5\n"
"	blt _0804BD92\n"
"	b _0804BF94\n"
"_0804BD92:\n"
"	ldr r3, _0804BED4\n"
"	add r3, sp\n"
"	ldr r4, _0804BEE4\n"
"	add r4, sp\n"
"	str r3, [r4]\n"
"	ldr r5, _0804BED8\n"
"	add r5, sp\n"
"	ldr r6, _0804BEE8\n"
"	add r6, sp\n"
"	str r5, [r6]\n"
"	mov r1, r10\n"
"	lsls r0, r1, 2\n"
"	adds r0, r5, r0\n"
"	ldr r3, _0804BEEC\n"
"	add r3, sp\n"
"	str r0, [r3]\n"
"_0804BDB2:\n"
"	lsls r0, r2, 4\n"
"	subs r0, r2\n"
"	add r0, r10\n"
"	lsls r0, 5\n"
"	mov r7, sp\n"
"	adds r7, r0\n"
"	adds r7, 0x8\n"
"	ldrb r0, [r7, 0x8]\n"
"	adds r4, r2, 0x1\n"
"	ldr r5, _0804BEDC\n"
"	add r5, sp\n"
"	str r4, [r5]\n"
"	cmp r0, 0\n"
"	beq _0804BDD0\n"
"	b _0804BF88\n"
"_0804BDD0:\n"
"	ldrb r0, [r7, 0xA]\n"
"	cmp r0, 0\n"
"	bne _0804BDD8\n"
"	b _0804BF00\n"
"_0804BDD8:\n"
"	lsls r0, r2, 2\n"
"	ldr r6, _0804BEE4\n"
"	add r6, sp\n"
"	ldr r6, [r6]\n"
"	adds r0, r6, r0\n"
"	ldr r1, [r0]\n"
"	adds r0, r1, 0x2\n"
"	mov r9, r0\n"
"	ldr r3, _0804BEEC\n"
"	add r3, sp\n"
"	ldr r3, [r3]\n"
"	ldr r2, [r3]\n"
"	adds r4, r2, 0x2\n"
"	ldr r5, _0804BEF0\n"
"	add r5, sp\n"
"	str r4, [r5]\n"
"	ldr r6, _0804BEDC\n"
"	add r6, sp\n"
"	ldr r6, [r6]\n"
"	lsls r0, r6, 2\n"
"	ldr r3, _0804BEE4\n"
"	add r3, sp\n"
"	ldr r3, [r3]\n"
"	adds r0, r3, r0\n"
"	ldr r4, [r0]\n"
"	subs r4, r1\n"
"	subs r4, 0x3\n"
"	ldr r5, _0804BEE8\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	movs r6, 0xE6\n"
"	lsls r6, 5\n"
"	add r6, sp\n"
"	ldr r6, [r6]\n"
"	adds r0, r5, r6\n"
"	ldr r5, [r0]\n"
"	subs r5, r2\n"
"	subs r5, 0x3\n"
"	movs r0, 0x5\n"
"	adds r1, r4, 0\n"
"	bl DungeonRandRange\n"
"	mov r8, r0\n"
"	movs r0, 0x4\n"
"	adds r1, r5, 0\n"
"	bl DungeonRandRange\n"
"	adds r6, r0, 0\n"
"	mov r0, r8\n"
"	subs r4, r0\n"
"	adds r0, r4, 0\n"
"	bl DungeonRandInt\n"
"	adds r4, r0, 0\n"
"	add r4, r9\n"
"	subs r5, r6\n"
"	adds r0, r5, 0\n"
"	bl DungeonRandInt\n"
"	ldr r2, _0804BEF0\n"
"	add r2, sp\n"
"	ldr r1, [r2]\n"
"	adds r1, r0\n"
"	mov r9, r1\n"
"	mov r5, r8\n"
"	adds r3, r4, r5\n"
"	add r6, r9\n"
"	strh r4, [r7]\n"
"	strh r3, [r7, 0x4]\n"
"	strh r1, [r7, 0x2]\n"
"	strh r6, [r7, 0x6]\n"
"	ldr r1, _0804BEE0\n"
"	add r1, sp\n"
"	ldr r0, [r1]\n"
"	adds r0, 0x1\n"
"	ldr r1, _0804BEF4\n"
"	add r1, sp\n"
"	str r0, [r1]\n"
"	cmp r4, r3\n"
"	bge _0804BEC0\n"
"_0804BE78:\n"
"	mov r5, r9\n"
"	adds r7, r4, 0x1\n"
"	cmp r5, r6\n"
"	bge _0804BEBA\n"
"	ldr r2, _0804BEF8\n"
"	mov r8, r2\n"
"_0804BE84:\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	ldr r2, _0804BEFC\n"
"	add r2, sp\n"
"	str r3, [r2]\n"
"	bl GetTileSafe\n"
"	ldrh r1, [r0]\n"
"	mov r2, r8\n"
"	ands r1, r2\n"
"	movs r2, 0x1\n"
"	orrs r1, r2\n"
"	strh r1, [r0]\n"
"	adds r0, r4, 0\n"
"	adds r1, r5, 0\n"
"	bl GetTileSafe\n"
"	ldr r1, _0804BEE0\n"
"	add r1, sp\n"
"	ldrb r1, [r1]\n"
"	strb r1, [r0, 0x9]\n"
"	adds r5, 0x1\n"
"	ldr r2, _0804BEFC\n"
"	add r2, sp\n"
"	ldr r3, [r2]\n"
"	cmp r5, r6\n"
"	blt _0804BE84\n"
"_0804BEBA:\n"
"	adds r4, r7, 0\n"
"	cmp r4, r3\n"
"	blt _0804BE78\n"
"_0804BEC0:\n"
"	ldr r3, _0804BEF4\n"
"	add r3, sp\n"
"	ldr r3, [r3]\n"
"	ldr r4, _0804BEE0\n"
"	add r4, sp\n"
"	str r3, [r4]\n"
"	b _0804BF88\n"
"	.align 2, 0\n"
"_0804BED0: .4byte 0xffffe338\n"
"_0804BED4: .4byte 0x00001c28\n"
"_0804BED8: .4byte 0x00001c64\n"
"_0804BEDC: .4byte 0x00001cb8\n"
"_0804BEE0: .4byte 0x00001ca4\n"
"_0804BEE4: .4byte 0x00001ca8\n"
"_0804BEE8: .4byte 0x00001cb0\n"
"_0804BEEC: .4byte 0x00001cb4\n"
"_0804BEF0: .4byte 0x00001cac\n"
"_0804BEF4: .4byte 0x00001cbc\n"
"_0804BEF8: .4byte 0x0000fffc\n"
"_0804BEFC: .4byte 0x00001cc4\n"
"_0804BF00:\n"
"	lsls r0, r2, 2\n"
"	ldr r4, _0804C080\n"
"	add r4, sp\n"
"	ldr r4, [r4]\n"
"	adds r0, r4, r0\n"
"	ldr r2, [r0]\n"
"	adds r0, r2, 0x1\n"
"	ldr r5, _0804C084\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	ldr r3, [r5]\n"
"	adds r6, r3, 0x1\n"
"	mov r8, r6\n"
"	ldr r4, _0804C088\n"
"	add r4, sp\n"
"	ldr r4, [r4]\n"
"	lsls r1, r4, 2\n"
"	ldr r5, _0804C080\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	adds r1, r5, r1\n"
"	ldr r1, [r1]\n"
"	subs r1, r2\n"
"	subs r1, 0x3\n"
"	ldr r6, _0804C08C\n"
"	add r6, sp\n"
"	ldr r6, [r6]\n"
"	movs r4, 0xE6\n"
"	lsls r4, 5\n"
"	add r4, sp\n"
"	ldr r4, [r4]\n"
"	adds r2, r6, r4\n"
"	ldr r4, [r2]\n"
"	subs r4, r3\n"
"	subs r4, 0x3\n"
"	adds r1, r0, r1\n"
"	bl DungeonRandRange\n"
"	adds r5, r0, 0\n"
"	add r4, r8\n"
"	mov r0, r8\n"
"	adds r1, r4, 0\n"
"	bl DungeonRandRange\n"
"	adds r4, r0, 0\n"
"	strh r5, [r7]\n"
"	adds r0, r5, 0x1\n"
"	strh r0, [r7, 0x4]\n"
"	strh r4, [r7, 0x2]\n"
"	adds r0, r4, 0x1\n"
"	strh r0, [r7, 0x6]\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	bl GetTileSafe\n"
"	ldrh r1, [r0]\n"
"	ldr r6, _0804C090\n"
"	adds r2, r6, 0\n"
"	ands r1, r2\n"
"	movs r2, 0x1\n"
"	orrs r1, r2\n"
"	strh r1, [r0]\n"
"	adds r0, r5, 0\n"
"	adds r1, r4, 0\n"
"	bl GetTileSafe\n"
"	movs r1, 0xFF\n"
"	strb r1, [r0, 0x9]\n"
"_0804BF88:\n"
"	ldr r0, _0804C088\n"
"	add r0, sp\n"
"	ldr r2, [r0]\n"
"	cmp r2, 0x5\n"
"	bge _0804BF94\n"
"	b _0804BDB2\n"
"_0804BF94:\n"
"	movs r2, 0xE6\n"
"	lsls r2, 5\n"
"	add r2, sp\n"
"	ldr r1, [r2]\n"
"	adds r1, 0x4\n"
"	str r1, [r2]\n"
"	movs r3, 0x1\n"
"	add r10, r3\n"
"	mov r4, r10\n"
"	cmp r4, 0x4\n"
"	bge _0804BFAC\n"
"	b _0804BD8A\n"
"_0804BFAC:\n"
"	movs r2, 0x1\n"
"	movs r1, 0x1\n"
"	movs r3, 0xF\n"
"	add r4, sp, 0x1C\n"
"_0804BFB4:\n"
"	movs r5, 0\n"
"	mov r10, r5\n"
"	lsls r0, r3, 5\n"
"	adds r0, r4\n"
"_0804BFBC:\n"
"	strb r1, [r0]\n"
"	strb r1, [r0, 0x1F]\n"
"	adds r0, 0x20\n"
"	movs r6, 0x1\n"
"	add r10, r6\n"
"	mov r5, r10\n"
"	cmp r5, 0x2\n"
"	ble _0804BFBC\n"
"	movs r0, 0xF0\n"
"	lsls r0, 1\n"
"	adds r3, 0xF\n"
"	adds r2, 0x1\n"
"	cmp r2, 0x3\n"
"	ble _0804BFB4\n"
"	mov r10, r6\n"
"	movs r5, 0x1\n"
"	adds r4, r0, 0\n"
"	mov r6, sp\n"
"	adds r6, r4\n"
"	adds r6, 0x8\n"
"_0804BFE4:\n"
"	movs r2, 0\n"
"	mov r1, r10\n"
"	lsls r0, r1, 5\n"
"	mov r3, r10\n"
"	adds r3, 0x1\n"
"	adds r1, r0, r6\n"
"	add r0, sp\n"
"	adds r0, 0x8\n"
"_0804BFF4:\n"
"	strb r5, [r0, 0x16]\n"
"	strb r5, [r1, 0x15]\n"
"	adds r1, r4\n"
"	adds r0, r4\n"
"	adds r2, 0x1\n"
"	cmp r2, 0x3\n"
"	ble _0804BFF4\n"
"	mov r10, r3\n"
"	cmp r3, 0x2\n"
"	ble _0804BFE4\n"
"	ldr r5, _0804C094\n"
"	add r5, sp\n"
"	ldr r4, _0804C098\n"
"	add r4, sp\n"
"	str r4, [sp]\n"
"	movs r0, 0x1\n"
"	str r0, [sp, 0x4]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x5\n"
"	movs r2, 0x4\n"
"	adds r3, r5, 0\n"
"	bl sub_804D8C8\n"
"	str r4, [sp]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x5\n"
"	movs r2, 0x4\n"
"	adds r3, r5, 0\n"
"	bl sub_804E590\n"
"	ldr r0, _0804C09C\n"
"	movs r2, 0\n"
"	ldrsh r3, [r0, r2]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x5\n"
"	movs r2, 0x4\n"
"	bl sub_804EBC8\n"
"	ldr r0, _0804C0A0\n"
"	movs r4, 0\n"
"	ldrsh r3, [r0, r4]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x5\n"
"	movs r2, 0x4\n"
"	bl sub_804EEE4\n"
"	movs r5, 0xE5\n"
"	lsls r5, 5\n"
"	add r5, sp\n"
"	ldr r5, [r5]\n"
"	ldrb r3, [r5, 0x13]\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x5\n"
"	movs r2, 0x4\n"
"	bl sub_804CBEC\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0x5\n"
"	movs r2, 0x4\n"
"	bl sub_804E03C\n"
"	ldr r3, _0804C0A4\n"
"	add sp, r3\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0804C080: .4byte 0x00001ca8\n"
"_0804C084: .4byte 0x00001cb4\n"
"_0804C088: .4byte 0x00001cb8\n"
"_0804C08C: .4byte 0x00001cb0\n"
"_0804C090: .4byte 0x0000fffc\n"
"_0804C094: .4byte 0x00001c28\n"
"_0804C098: .4byte 0x00001c64\n"
"_0804C09C: .4byte gUnknown_202F1B0\n"
"_0804C0A0: .4byte gUnknown_202F1B2\n"
"_0804C0A4: .4byte 0x00001cc8");
}
#endif // NONMATCHING

void sub_804C0A8(UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 unk7200[GRID_CELL_LEN];
    s32 unk7260[GRID_CELL_LEN];
    s32 x, y, unk;

    unk7200[0] = 0;
    unk7200[1] = 11;
    unk7200[2] = 22;
    unk7200[3] = 33;
    unk7200[4] = 44;
    unk7200[5] = 56;

    unk7260[0] = 4;
    unk7260[1] = 15;

    unk = 1;
    x = 5, y = 1;
    sub_804D084(grid, x, y);
    sub_804D154(grid, x, y, unkPtr->unk1);
    sub_804D2D0(grid, x, y, unk7200, unk7260, unkPtr->unkD);
    sub_804D5B0(grid, x, y, unkPtr);
    sub_804D8C8(grid, x, y, unk7200, unk7260, unk);
    sub_804E590(grid, x, y, unk7200, unk7260);
    sub_804EBC8(grid, x, y, gUnknown_202F1B0);
    sub_804EEE4(grid, x, y, gUnknown_202F1B2);
    sub_804CBEC(grid, x, y, unkPtr->unk13);
    sub_804E03C(grid, x, y);
}

void sub_804C190(UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 unk7200[GRID_CELL_LEN];
    s32 unk7260[GRID_CELL_LEN];
    s32 i, j, x, y;

    unk7200[0] = 11;
    unk7200[1] = 22;
    unk7200[2] = 33;
    unk7200[3] = 44;

    unk7260[0] = 2;
    unk7260[1] = 11;
    unk7260[2] = 20;
    unk7260[3] = 30;

    x = 3, y = 3;
    sub_804D084(grid, x, y);
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            grid[i][j].unk10 = 1;
        }
    }
    grid[0][0].unk8 = 1;
    grid[2][0].unk8 = 1;
    grid[0][2].unk8 = 1;
    grid[2][2].unk8 = 1;

    sub_804D2D0(grid, x, y, unk7200, unk7260, unkPtr->unkD);

    grid[0][1].unk22 = 1;
    grid[1][1].unk21 = 1;
    grid[1][1].unk22 = 1;
    grid[2][1].unk21 = 1;
    grid[1][0].unk20 = 1;
    grid[1][1].unk19 = 1;
    grid[1][1].unk20 = 1;
    grid[1][2].unk19 = 1;
    sub_804D8C8(grid, x, y, unk7200, unk7260, 1);
    sub_804E590(grid, x, y, unk7200, unk7260);
    sub_804EBC8(grid, x, y, gUnknown_202F1B0);
    sub_804EEE4(grid, x, y, gUnknown_202F1B2);
    sub_804CBEC(grid, x, y, unkPtr->unk13);
    sub_804E03C(grid, x, y);
}

void sub_804C2F4(UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 unk7200[GRID_CELL_LEN];
    s32 unk7260[GRID_CELL_LEN];
    s32 i, j, x, y;

    unk7200[0] = 5;
    unk7200[1] = 15;
    unk7200[2] = 35;
    unk7200[3] = 50;

    unk7260[0] = 2;
    unk7260[1] = 11;
    unk7260[2] = 20;
    unk7260[3] = 30;

    x = 3, y = 3;
    sub_804D084(grid, x, y);
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            grid[i][j].unk10 = 1;
        }
    }

    sub_804D2D0(grid, x, y, unk7200, unk7260, unkPtr->unkD);
    for (j = 0; j < 3; j++) {
        grid[0][j].unk22 = 1;
        grid[1][j].unk21 = 1;
        grid[1][j].unk22 = 1;
        grid[2][j].unk21 = 1;
    }
    sub_804D8C8(grid, x, y, unk7200, unk7260, 1);
    sub_804C43C(1, 0, 1, grid);
    sub_804C43C(1, 0, 2, grid);
    sub_804E590(grid, x, y, unk7200, unk7260);
    sub_804EBC8(grid, x, y, gUnknown_202F1B0);
    sub_804EEE4(grid, x, y, gUnknown_202F1B2);
    sub_804CBEC(grid, x, y, unkPtr->unk13);
    sub_804E03C(grid, x, y);
}

void sub_804C43C(s32 a0, s32 a1, s32 a2, struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN])
{
    s32 x, y;
    s32 xStart = (grid[a0][a1].unk0.x < grid[a0][a1+a2].unk0.x) ? grid[a0][a1].unk0.x : grid[a0][a1+a2].unk0.x;
    s32 yStart = grid[a0][a1].unk0.y;
    s32 xMax = (grid[a0][a1].unk4.x > grid[a0][a1+a2].unk4.x) ? grid[a0][a1].unk4.x : grid[a0][a1+a2].unk4.x;
    s32 yMax = grid[a0][a1 + a2].unk4.y;
    u8 room = GetTile(grid[a0][a1].unk0.x, grid[a0][a1].unk0.y)->room;

    for (x = xStart; x < xMax; x++) {
        for (y = yStart; y < yMax; y++) {
            Tile *tile = GetTileSafe(x, y);
            tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
            tile->terrainType |= TERRAIN_TYPE_NORMAL;
            tile->room = room;
        }
    }

    grid[a0][a1].unk0.x = xStart;
    grid[a0][a1].unk4.x = xMax;
    grid[a0][a1].unk0.y = yStart;
    grid[a0][a1].unk4.y = yMax;
    grid[a0][a1 + a2].unk18 = 1;
    grid[a0][a1].unk18 = 1;
    grid[a0][a1 + a2].unk11 = 0;
    grid[a0][a1 + a2].unk17 = 1;
}

void sub_804C53C(s32 x_, s32 y_, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 unk7200[GRID_CELL_LEN];
    s32 unk7260[GRID_CELL_LEN];
    s32 i, j;
    s32 x = x_;
    s32 y = y_;

    sub_804D024(unk7200, unk7260, x, y);
    sub_804D084(grid, x, y);
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            grid[i][j].unk10 = 1;
        }
    }

    for (i = 1; i < x - 1; i++) {
        for (j = 1; j < y - 1; j++) {
            grid[i][j].unk8 = 1;
        }
    }

    sub_804D2D0(grid, x, y, unk7200, unk7260, unkPtr->unkD);
    for (i = 0; i < x - 1; i++) {
        if (i != 0) {
            grid[i][0].unk22 = 1;
            grid[i][y-1].unk22 = 1;
        }
        if (i < x - 2) {
            grid[i+1][0].unk21 = 1;
            grid[i+1][y-1].unk21 = 1;
        }
    }

    for (j = 0; j < y - 1; j++) {
        if (j != 0) {
            grid[0][j].unk19 = 1;
            grid[x-1][j].unk19 = 1;
        }
        if (j < y - 2) {
            grid[0][j].unk20 = 1;
            grid[x-1][j].unk20 = 1;
        }
    }

    sub_804D8C8(grid, x, y, unk7200, unk7260, 0);
    sub_804E590(grid, x, y, unk7200, unk7260);
    sub_804F0D0(grid, x, y, unkPtr->unk9);
    sub_804EBC8(grid, x, y, gUnknown_202F1B0);
    sub_804EEE4(grid, x, y, gUnknown_202F1B2);
    sub_804CBEC(grid, x, y, unkPtr->unk13);
    sub_804E03C(grid, x, y);
    sub_804D534(grid, x, y);
}

void sub_804C790(s32 x1, s32 y1, s32 x2, s32 y2, s32 a4, UnkDungeonGlobal_unk1C574 *unkPtr);
extern void sub_8051288(s32 a0);

bool8 sub_804C70C(s32 a0, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    struct FileFixedmapPosStruct **fileData = (void *) gDungeon->unk13568->data;
    s32 x1 = fileData[a0]->x;
    s32 y1 = fileData[a0]->y;
    s32 x2, y2;

    if (x1 == 0 || y1 == 0) {
        sub_804C918();
        return FALSE;
    }
    else if (a0 < 50) {
        sub_8051288(a0);
        return TRUE;
    }
    else {
        x2 = DUNGEON_MAX_SIZE_X / (x1 + 4);
        if (x2 <= 1)
            x2 = 1;
        y2 = DUNGEON_MAX_SIZE_Y / (y1 + 4);
        if (y2 <= 1)
            y2 = 1;
        sub_804C790(x2, y2, x1, y1, a0, unkPtr);
        return FALSE;
    }
}

void sub_8050F90(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x1, s32 y1, s32 *a3, s32 *a4, s32 a5, s32 x2, s32 y2);
void sub_804D5F0(struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN], s32 x, s32 y, s32 x2, s32 y2, UnkDungeonGlobal_unk1C574 *unkPtr);
void sub_8051438(struct GridCell *cell, s32 a1);

void sub_804C790(s32 x1, s32 y1, s32 x2, s32 y2, s32 a4, UnkDungeonGlobal_unk1C574 *unkPtr)
{
    s32 tries;
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 unk7200[GRID_CELL_LEN];
    s32 unk7260[GRID_CELL_LEN];
    s32 r10 = 0;
    s32 x3 = 0, y3 = 0;

    sub_804D024(unk7200, unk7260, x1, y1);
    sub_804D084(grid, x1, y1);
    sub_804D154(grid, x1, y1, unkPtr->unk1);
    for (x3 = 0; x3 < x1; x3++) {
        for (y3 = 0; y3 < y1; y3++) {
            grid[x3][y3].unk27 = 1;
        }
    }

    for (tries = 0; tries < 64; tries++) {
        x3 = DungeonRandInt(x1);
        y3 = DungeonRandInt(y1);
        r10 = y3 * x1 + x3;
        if (grid[x3][y3].unk10)
            break;
    }
    sub_8050F90(grid, x1, y1, unk7200, unk7260, r10, x2, y2);
    if (x1 != 1 || y1 != 1) {
        sub_804D5F0(grid, x1, y1, x3, y3, unkPtr);
        sub_804D8C8(grid, x1, y1, unk7200, unk7260, 1);
        sub_804E590(grid, x1, y1, unk7200, unk7260);
    }
    sub_8051438(&grid[x3][y3], a4);
}

void sub_804C918(void)
{
    s32 i, j;
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];

    sub_804D084(grid, 1, 1);
    grid[0][0].unk0.x = 2;
    grid[0][0].unk4.x = DUNGEON_MAX_SIZE_X - 2;
    grid[0][0].unk0.y = 2;
    grid[0][0].unk4.y = DUNGEON_MAX_SIZE_Y - 2;
    grid[0][0].unk10 = 1;
    grid[0][0].unk11 = 1;
    grid[0][0].unk8 = 0;
    for (i = grid[0][0].unk0.x; i < grid[0][0].unk4.x; i++) {
        for (j = grid[0][0].unk0.y; j < grid[0][0].unk4.y; j++) {
            Tile *tile = GetTileSafe(i, j);
            tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
            tile->terrainType |= TERRAIN_TYPE_NORMAL;
            // Unnecessary call again
            GetTileSafe(i, j)->room = 0;
        }
    }
    sub_804EEE4(grid, 1, 1, 999);
}

void sub_804C9D0(void)
{
    struct GridCell grid[GRID_CELL_LEN][GRID_CELL_LEN];
    s32 listX[GRID_CELL_LEN];
    s32 listY[GRID_CELL_LEN];
    s32 currRoomId = 0;
    s32 x, y;

    listX[0] = 2;
    listX[1] = 28;
    listX[2] = 54;
    listY[0] = 2;
    listY[1] = 30;
    sub_804D084(grid, 2, 1);

    for (y = 0; y < 1; y++) {
        for (x = 0; x < 2; x++) {
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

            grid[x][y].unk10 = 1;
            grid[x][y].unk0.x = startX;
            grid[x][y].unk4.x = endX;
            grid[x][y].unk0.y = startY;
            grid[x][y].unk4.y = endY;

            for (currX = startX; currX < endX; currX++) {
                for (currY = startY; currY < endY; currY++) {
                    Tile *tile = GetTileSafe(currX, currY);
                    tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
                    tile->terrainType |= TERRAIN_TYPE_NORMAL;
                    // Unnecessary call again
                    GetTileSafe(currX, currY)->room = currRoomId;
                }
            }
            currRoomId++;
        }
    }

    grid[0][0].unk22 = 1;
	grid[1][0].unk21 = 1;
	sub_804D8C8(grid, 2, 1, listX, listY, 0);
	sub_804EEE4(grid, 2, 1, 999);
}

//
