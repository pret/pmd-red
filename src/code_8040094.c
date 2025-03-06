#include "global.h"
#include "code_800558C.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "dungeon_message.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_music.h"
#include "file_system.h"
#include "play_time.h"
#include "cpu.h"
#include "dungeon.h"
#include "game_options.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "code_800E9E4.h"
#include "dungeon_generation.h"
#include "dungeon_util.h"
#include "trap.h"
#include "constants/dungeon.h"

extern s32 gUnknown_80F6568[];
extern u8 gUnknown_202EE01;
extern const char gUnknown_80F6604; // "zmappat"
extern struct FileArchive gDungeonFileArchive;
extern OpenedFile *gUnknown_202EE04;

extern void sub_803F7BC(void);

extern void sub_803F580(u32);
extern void sub_8040A84();

extern const char *gUnknown_80FD040; // It became brighter on the floor

// Luminous Orb???
void HandleLuminousOrbAction(Entity *pokemon)
{
  int XCoord;
  int YCoord;

  gDungeon->unk181e8.unk1820B = 1;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++)
    {
      Tile *mapTile = GetTileMut(XCoord, YCoord);
      mapTile->spawnOrVisibilityFlags |= 1;
    }
  }
  sub_803F580(0);
  sub_8049ED4();
  sub_8040A84();
  LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD040);
}

void sub_8040094(u8 r0)
{
    gDungeon->unk181e8.unk18217 = r0;
    sub_803F7BC();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    xxx_call_update_bg_sound_input();
    UpdateDungeonMusic();
    sub_8011860();
}

void sub_80400D4(void)
{
    s32 temp;
    temp = gDungeon->unk181e8.unk18200;
    if(temp == 0)
        return;
    if(temp > 0x1E)
        temp = 0x1F;
    gDungeon->unk181e8.unk181FC = gUnknown_80F6568[temp];
    gDungeon->unk181e8.unk18200--;
    if(gDungeon->unk181e8.unk18200 == 0)
        gDungeon->unk181e8.unk18200 = gDungeon->unk181e8.unk18204;
}

void sub_8040124(void)
{
    gUnknown_202EE01 = 0;
}

void sub_8040130(void)
{
    gUnknown_202EE04 = OpenFileAndGetFileDataPtr(&gUnknown_80F6604, &gDungeonFileArchive);
}

extern DungeonPos gUnknown_203B410;
extern u8 gUnknown_202EE00;
extern void *gUnknown_202EE08;

void sub_8040238(void);

void sub_8040150(bool8 a0)
{
    s32 i, j;

    for (i = 0; i < UNK1822C_ARR_COUNT; i++) {
        for (j = 0; j < UNK1822C_ARR_COUNT_2; j++) {
            CpuClear(&gDungeon->unk1822C.unk1822C[i][j], sizeof(struct UnkDungeonGlobal_1822C_Sub));
            gDungeon->unk1822C.unk1BA2C[i][j] = 0;
        }
    }

    if (!a0) {
        gUnknown_203B410.x = 100;
        gUnknown_203B410.y = 100;
    }

    gDungeon->unk1822C.unk1BDCC = 0;
    gDungeon->unk1822C.unk1BDD0 = 1;
    gDungeon->unk1822C.unk1BDD2 = 0;
    gUnknown_202EE00 = 1;
    gUnknown_202EE08 = (void *) VRAM + 0x1700;
    gUnknown_202EE01 = 1;
    sub_8040238();
}

void sub_8040218(void)
{
    if (gUnknown_202EE04 != NULL) {
        CloseFile(gUnknown_202EE04);
    }
    sub_8040124();
}

UNUSED static void nullsub_203(void)
{

}

struct UnkStruct1
{
    u32 **unk0;
};

struct UnkPaletteFileData
{
    struct UnkStruct1 *unk0;
    RGB *pal;
};

void sub_8040238(void)
{
    s32 i;

    if (gUnknown_202EE04 == NULL)
        return;
    if (!gUnknown_202EE01)
        return;

    for (i = 0; i < 16; i++) {
        if (i == 14) {
            SetBGPaletteBufferColorArray(238, &gFontPalette[1]);
            nullsub_5(238, &gFontPalette[1]);
        }
        else {
            SetBGPaletteBufferColorArray(i + 224, &((struct UnkPaletteFileData *)(gUnknown_202EE04->data))->pal[i]);
            nullsub_5(i + 224, &((struct UnkPaletteFileData *)(gUnknown_202EE04->data))->pal[i]);
        }
    }
}

extern u8 GetFloorType(void);
extern bool8 sub_8094C48(void);
extern bool8 sub_8045804(Entity *ent);
extern const u8 gUnknown_80F65F0[];
extern bool8 DoesNotHaveShadedMap(void);

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

    if (gUnknown_202EE04 == NULL)
        return;
    if (!gUnknown_202EE01)
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
    dst = dungeon->unk1822C.unk1822C[yDiv2][xDiv2].arr;
    {
        struct UnkPaletteFileData *ptr = ((struct UnkPaletteFileData *)(&gUnknown_202EE04->data));
        src = ptr->unk0->unk0[r6 * 4 + r3];
    }

    dst[0] = (dst[0] & src[0]) | src[1];
    dst[1] = (dst[1] & src[2]) | src[3];
    dst[2] = (dst[2] & src[4]) | src[5];
    dst[3] = (dst[3] & src[6]) | src[7];
    dst[4] = (dst[4] & src[8]) | src[9];
    dst[5] = (dst[5] & src[10]) | src[11];
    dst[6] = (dst[6] & src[12]) | src[13];
    dst[7] = (dst[7] & src[14]) | src[15];

    if (!dungeon->unk1822C.unk1BDD1 && !dungeon->unk1822C.unk1BA2C[yDiv2][xDiv2]) {
        s32 id;

        dungeon->unk1822C.unk1BA2C[yDiv2][xDiv2] = 1;
        id = dungeon->unk1822C.unk1BDCC;
        if (id < 40) {
            dungeon->unk1822C.unk1BBEC[id][0] = gUnknown_202EE08 + ((xDiv2 + yDiv2 * 28) * 32);
            dungeon->unk1822C.unk1BBEC[id][1] = dst;
            dungeon->unk1822C.unk1BBEC[id][2] = &dungeon->unk1822C.unk1BA2C[yDiv2][xDiv2];
            dungeon->unk1822C.unk1BDCC++;
        }
        else {
            dungeon->unk1822C.unk1BDD1 = 1;
        }
    }
}

//
