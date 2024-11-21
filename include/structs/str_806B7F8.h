#ifndef GUARD_STR_806B7F8_H
#define GUARD_STR_806B7F8_H

#include "structs/dungeon_entity.h"

struct unkStruct_806B7F8
{
    s16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    DungeonPos pos;
    u8 unk10;
};

Entity* sub_806B7F8(struct unkStruct_806B7F8 *, bool8);

#endif
