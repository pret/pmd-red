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
    u16 unk52E0[1500];
    u8 unk5E98[1500];
};

struct UnkStruct_sub_8010494
{
    DungeonLocation unk0;
    DungeonSetupSubstruct unk4;
    PokemonStruct1 mon;
    u8 unk6C;
    u8 unk6D[63];
};

struct UnkStruct_sub_8010268
{
    u8 fill0[4];
    struct UnkStruct_sub_8010494 unk4;
    struct WorldMap *unkB0;
    u8 unkB4;
};

void ShowWorldMap_Async(struct UnkStruct_sub_8010268 *r5);

#endif
