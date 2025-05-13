#ifndef GUARD_DUNGEON_MAPPARAM_H
#define GUARD_DUNGEON_MAPPARAM_H

#include "dungeon.h"

struct DungeonMapParam1
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6[5];
};

struct DungeonMapParam2
{
    struct DungeonMapParam1 **unk0;
    FloorProperties *unk4;
    u16 **unk8;
    UnkDungeonGlobal_unk1CD98 **unkC;
    u16 **unk10;
};

#endif
