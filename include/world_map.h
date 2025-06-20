#ifndef GUARD_WORLD_MAP_H
#define GUARD_WORLD_MAP_H

#include "file_system.h"
#include "code_8004AA0.h"
#include "menu_input.h"
#include "structs/axdata.h"
#include "structs/str_position.h"
#include "structs/str_dungeon.h"
#include "structs/str_pokemon.h"
#include "structs/str_dungeon_setup.h"

#define UNK_WORLD_MAP_52E0_COUNT 1500

struct UnkStruct_Sub1
{
    u8 unk0;
    DungeonPos unk4;
    axdata unk8;
};

struct WorldMap
{
    struct UnkStruct_Sub1 unk0[64];
    OpenedFile *unk1100[5];
    u16 unk1114[64][64];
    u16 unk3114[64][64];
    axdata monAxSprite;
    unkStruct_202EE8C unk5150[16];
    s32 brightness;
    s32 unk52D4;
    DungeonPos bgPos;
    DungeonPos monSpritePos;
    // Both fields below are effectively unused. Could be NDS-only?
    u16 unk52E0[UNK_WORLD_MAP_52E0_COUNT];
    u8 unk5E98[UNK_WORLD_MAP_52E0_COUNT];
};

#define WORLD_MAP_UNK_6D_COUNT 63

struct WorldMapInfo
{
    DungeonLocation startLocation;
    DungeonSetupSubstruct unk4;
    Pokemon mon;
    u8 unk6C;
    u8 unk6D[WORLD_MAP_UNK_6D_COUNT];
};

struct WorldMapSetupStruct
{
    u8 fill0[4];
    struct WorldMapInfo info;
    struct WorldMap *worldMap;
    bool8 dungeonEntered; // Some dungeons have specific requirements, where it's not always possible to enter chosen dungeon.
};

void ShowWorldMap_Async(struct WorldMapSetupStruct *setupPtr);

#endif
