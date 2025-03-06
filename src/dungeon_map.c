#include "global.h"
#include "dungeon_map.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_music.h"
#include "file_system.h"
#include "cpu.h"
#include "dungeon.h"
#include "game_options.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "code_800E9E4.h"
#include "dungeon_generation.h"
#include "dungeon_util.h"
#include "trap.h"
#include "text.h"
#include "constants/dungeon.h"

extern const char gUnknown_80F6604; // "zmappat"
extern struct FileArchive gDungeonFileArchive;
extern DungeonPos gUnknown_203B410;
extern s32 gUnknown_202EDD0;

extern void nullsub_11(SpriteOAM *, s32, UnkSpriteMem *, unkStruct_2039DB0 *);
extern u8 GetFloorType(void);
extern bool8 sub_8094C48(void);
extern bool8 sub_8045804(Entity *ent);
extern bool8 DoesNotHaveShadedMap(void);

extern const u8 gUnknown_80F65F0[];

struct UnkStruct1
{
    u32 **unk0;
};

struct DungeonMapGfx
{
    struct UnkStruct1 *gfx;
    RGB *pal;
};

EWRAM_DATA bool8 gUnknown_202EE00 = FALSE;
EWRAM_DATA bool8 gShowDungeonMap = FALSE;
EWRAM_DATA static u8 sPlayerDotFrames = 0;
EWRAM_DATA static OpenedFile *sDungeonMapGfxFile = NULL;
EWRAM_DATA static void *gUnknown_202EE08 = NULL;

void SetDungeonMapToNotShown(void)
{
    gShowDungeonMap = FALSE;
}

void OpenDungeonMapFile(void)
{
    sDungeonMapGfxFile = OpenFileAndGetFileDataPtr(&gUnknown_80F6604, &gDungeonFileArchive);
}

void InitDungeonMap(bool8 a0)
{
    s32 i, j;

    for (i = 0; i < UNK1822C_ARR_COUNT; i++) {
        for (j = 0; j < UNK1822C_ARR_COUNT_2; j++) {
            CpuClear(&gDungeon->dungeonMap.dungeonMap[i][j], sizeof(struct UnkDungeonGlobal_1822C_Sub));
            gDungeon->dungeonMap.unk1BA2C[i][j] = FALSE;
        }
    }

    if (!a0) {
        gUnknown_203B410.x = 100;
        gUnknown_203B410.y = 100;
    }

    gDungeon->dungeonMap.unk1BDCC = 0;
    gDungeon->dungeonMap.unk1BDD0 = 1;
    gDungeon->dungeonMap.unk1BDD2 = 0;
    gUnknown_202EE00 = 1;
    gUnknown_202EE08 = (void *) VRAM + 0x1700;
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

// Used in Pmd's Blue version. Stores different Vram address in gUnknown_202EE08(maybe?), depending on TOP_MAP_AND_TEAM_NO_BOTTOM map option.
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

void sub_80402AC(s32 x, s32 y)
{
    s32 yAdd = 0;
    const Tile *tile;
    Dungeon *dungeon;
    bool8 blinded;
    u32 terrainType;
    bool8 hallucinating;
    bool8 var_2C;
    bool8 var_28;
    bool8 r0;
    bool8 var_24;
    bool8 r7;
    s32 r6;
    s32 xDiv2, yDiv2;
    u32 *src, *dst;
    bool8 r10;
    s32 r3, yMinus;

    dungeon = gDungeon;
    r10 = TRUE;

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
    var_28 = gDungeon->unk181e8.unk1820F;
    var_2C = gDungeon->unk181e8.unk1820E;
    r0 = gDungeon->unk181e8.unk1820B;
    if (blinded) {
        r7 = tile->spawnOrVisibilityFlags & 1;
        var_24 = FALSE;
    }
    else {
        if (r0) {
            r7 = TRUE;
        }
        else {
            r7 = tile->spawnOrVisibilityFlags & 1;
        }

        if (GetFloorType() == FLOOR_TYPE_NORMAL) {
            var_24 = gDungeon->unk181e8.unk18211;
        }
        else {
            var_24 = FALSE;
        }
    }

    if (sub_8094C48() && !gDungeon->unk1356C) {
        r6 = 0;
        if (!blinded) {
            Entity *entity = tile->monster;
            if (entity != NULL) {
                s32 entType = GetEntityType(entity);
                if (gUnknown_202EE00 && entType == ENTITY_MONSTER && sub_8045804(entity)) {
                    EntityInfo *entInfo = GetEntInfo(entity);
                    if (IsExperienceLocked(entInfo->joinedAt.id) || entInfo->monsterBehavior == 1 || entInfo->monsterBehavior == 4) {
                        r6 = 10;
                    }
                    else {
                        if (entInfo->isNotTeamMember) {
                            r6 = 2;
                        }
                        else if (entInfo->isTeamLeader) {
                            gUnknown_203B410.x = x;
                            gUnknown_203B410.y = y;
                            if (gDungeon->unk181e8.unk18214) {
                                r6 = 8;
                            }
                        }
                        else {
                            r6 = 10;
                        }
                    }
                    r10 = FALSE;
                }
            }
        }
        if (r10 && !blinded) {
            Entity *entity = tile->object;
            if (entity != NULL) {
                s32 entType = GetEntityType(entity);
                if (!r7) {
                    r6 = 0;
                    if (entType == ENTITY_ITEM) {
                        if ((var_2C || (tile->spawnOrVisibilityFlags & 2)) && terrainType != TERRAIN_TYPE_WALL) {
                            r6 = 3;
                        }
                    }
                    r10 = FALSE;
                }
                else {
                    if (entType == ENTITY_TRAP) {
                        if (entity->isVisible || var_28) {
                            Trap *trap = GetTrapData(entity);
                            r6 = gUnknown_80F65F0[trap->id];
                            r10 = FALSE;
                        }
                    }
                }

                if (r10) {
                    if (entType == ENTITY_ITEM) {
                        if ((var_2C || (tile->spawnOrVisibilityFlags & 2)) && terrainType != TERRAIN_TYPE_WALL) {
                            r6 = 3;
                            r10 = FALSE;
                        }
                    }
                }
                if (r10) {
                    if (terrainType != TERRAIN_TYPE_NORMAL) {
                        r6 = 0;
                        r10 = FALSE;
                    }
                }
            }
            else {
                if (!r7) {
                    if (var_24 && (tile->terrainType & TERRAIN_TYPE_STAIRS)) {
                        if (GetFloorType() == FLOOR_TYPE_NORMAL) {
                            r6 = 6;
                        }
                        else {
                            r6 = 5;
                        }
                        r10 = FALSE;
                    }
                }
                else {
                    if ((tile->terrainType & TERRAIN_TYPE_STAIRS)) {
                        if (GetFloorType() == FLOOR_TYPE_NORMAL) {
                            r6 = 6;
                        }
                        else {
                            r6 = 5;
                        }
                        r10 = FALSE;
                    }
                }
            }
        }
        if (!r10) {
            if (hallucinating) {
                if (r6 != 0) {
                    r6 = 11;
                }
            }
        }
        if (r6 == 0) {
            if (!r7) {
                r6 = 1;
            }
            else if (terrainType != TERRAIN_TYPE_NORMAL) {
                r6 = 1;
            }
            else {
                s32 r4 = 1 | 2 | 4 | 8;
                if (y < DUNGEON_MAX_SIZE_Y - 1) {
                    const Tile *adjacentTile = GetTile(x, y + 1);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        r4 &= ~(1);
                    }
                }
                if (y >= 1) {
                    const Tile *adjacentTile = GetTile(x, y - 1);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        r4 &= ~(4);
                    }
                }
                if (x < DUNGEON_MAX_SIZE_X - 1) {
                    const Tile *adjacentTile = GetTile(x + 1, y);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        r4 &= ~(2);
                    }
                }
                if (x >= 1) {
                    const Tile *adjacentTile = GetTile(x - 1, y);
                    if (GetTerrainType(adjacentTile) == TERRAIN_TYPE_NORMAL) {
                        r4 &= ~(8);
                    }
                }

                r6 = (s16) r4;
                if (tile->spawnOrVisibilityFlags & 2) {
                    r6 = (s16) (r6 + 16);
                }
                else {
                    r6 = (s16) (r6 + 32);
                }
            }
        }

        // Not possible on GBA.
        if (gGameOptionsRef->mapOption == TOP_MAP_AND_TEAM_NO_BOTTOM) {
            r6 = (s16) (r6 + 128);
        }
        else if (DoesNotHaveShadedMap() == TRUE) {
            r6 = (s16) (r6 + 64);
        }
    }
    else {
        r6 = 1;
        gUnknown_203B410.x = 100;
    }

    xDiv2 = x / 2;
    yMinus = (y - 2) + yAdd;
    yDiv2 = (yMinus / 2);
    r3 = x - (xDiv2 * 2);
    r3 += (yMinus - (yDiv2 * 2)) * 2;
    dst = dungeon->dungeonMap.dungeonMap[yDiv2][xDiv2].arr;
    {
        struct DungeonMapGfx *ptr = ((struct DungeonMapGfx *)(&sDungeonMapGfxFile->data));
        src = ptr->gfx->unk0[r6 * 4 + r3];
    }

    dst[0] = (dst[0] & src[0]) | src[1];
    dst[1] = (dst[1] & src[2]) | src[3];
    dst[2] = (dst[2] & src[4]) | src[5];
    dst[3] = (dst[3] & src[6]) | src[7];
    dst[4] = (dst[4] & src[8]) | src[9];
    dst[5] = (dst[5] & src[10]) | src[11];
    dst[6] = (dst[6] & src[12]) | src[13];
    dst[7] = (dst[7] & src[14]) | src[15];

    if (!dungeon->dungeonMap.unk1BDD1 && !dungeon->dungeonMap.unk1BA2C[yDiv2][xDiv2]) {
        s32 id;

        dungeon->dungeonMap.unk1BA2C[yDiv2][xDiv2] = TRUE;
        id = dungeon->dungeonMap.unk1BDCC;
        if (id < 40) {
            dungeon->dungeonMap.unk1BBEC[id].ptr1 = gUnknown_202EE08 + ((xDiv2 + yDiv2 * 28) * 32);
            dungeon->dungeonMap.unk1BBEC[id].ptr2 = dst;
            dungeon->dungeonMap.unk1BBEC[id].boolPtr = &dungeon->dungeonMap.unk1BA2C[yDiv2][xDiv2];
            dungeon->dungeonMap.unk1BDCC++;
        }
        else {
            dungeon->dungeonMap.unk1BDD1 = 1;
        }
    }
}

void sub_8040788(void)
{
    s32 i;
    Dungeon *dungeon = gDungeon;
    if (dungeon == NULL)
        return;
    if (!dungeon->dungeonMap.unk1BDD0)
        return;
    if (sub_800EC74())
        return;

    if (!dungeon->dungeonMap.unk1BDD1) {
        for (i = 0; i < dungeon->dungeonMap.unk1BDCC; i++) {
            struct UnkDungeonGlobal_unk1BBEC *ptr = &dungeon->dungeonMap.unk1BBEC[i];
            u32 *src = ptr->ptr2;
            u32 *dst = ptr->ptr1;

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

        dungeon->dungeonMap.unk1BDD1 = FALSE;
        dst = gUnknown_202EE08;
        src = dungeon->dungeonMap.dungeonMap[0][0].arr;

        for (i = 0; i < DUNGEON_MAX_SIZE_X * 8; i += 8) {
            if (gUnknown_202EDD0 == 0 || gUnknown_202EDD0 == 3) {
                CpuCopy(dst, src, 0x100);
            }
            dst += 0x100;
            src += 0x100;
        }
        dungeon->dungeonMap.unk1BDD2 = 1;
    }
    dungeon->dungeonMap.unk1BDCC = 0;
}

void ShowPlayerDotOnMap(void)
{
    if (gDungeon->unk181e8.unk18214)
        return;
    if (!gDungeon->unk181e8.unk18219)
        return;
    if (gUnknown_203B410.x >= 100)
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
            SpriteSetX(&sprite, (gUnknown_203B410.x * 4) + 16);
            SpriteSetY(&sprite, (gUnknown_203B410.y + 1) * 4);
            nullsub_11(&sprite,0x100,NULL,NULL);
        }
        else {
            SpriteSetX(&sprite, (gUnknown_203B410.x * 4) + 8);
            SpriteSetY(&sprite, (gUnknown_203B410.y) * 4);
            AddSprite(&sprite,0x100,NULL,NULL);
        }
    }
}

void ResetMapPlayerDotFrames(void)
{
    sPlayerDotFrames = 0;
}

void sub_8040A84(void)
{
    s32 x, y;

    gDungeon->dungeonMap.unk1BDD1 = TRUE;

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            sub_80402AC(x, y);
        }
    }
}

void sub_8040ABC(bool8 a0)
{
    s32 id, count1, count2;
    s32 i, j;
    u16 val;

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

    val = 0xE0B8;
    id = 1;
    for (i = 0; i < count1; i++) {
        u16 *ptr = &gUnknown_202B038[0][id][1];
        for (j = 0; j < 28; j++) {
            *ptr++ = val++;
        }
        id++;
    }

    for (i = 0; i < count2; i++) {
        u16 *ptr = &gUnknown_202B038[0][id][1];
        for (j = 0; j < 28; j++) {
            *ptr++ = 0xE000;
        }
        id++;
    }
}

// BUG: Overflowing into unk1BBEC. They forgot that the array size is max X/Y divided by two...
void sub_8040B60(void)
{
    s32 x, y;
    Dungeon *dungeon = gDungeon;
    if (dungeon->dungeonMap.unk1BDD2) {
        #ifdef BUGFIX
        for (y = 0; y < UNK1822C_ARR_COUNT; y++) {
            for (x = 0; x < UNK1822C_ARR_COUNT_2; x++) {
                dungeon->dungeonMap.unk1BA2C[y][x] = FALSE;
            }
        }
        #else
        for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
            for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
                dungeon->dungeonMap.unk1BA2C[y][x] = FALSE;
            }
        }
        #endif // BUGFIX
        dungeon->dungeonMap.unk1BDD2 = FALSE;
    }
}
