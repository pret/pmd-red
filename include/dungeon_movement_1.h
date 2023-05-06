#ifndef GUARD_DUNGEON_MOVEMENT_1_H
#define GUARD_DUNGEON_MOVEMENT_1_H

#include "dungeon_entity.h"

u8 sub_80703A0(struct Entity *pokemon, struct Position *pos);
bool8 CanCrossWalls(struct Entity *pokemon);
bool8 sub_807049C(struct Entity *pokemon, struct Position *pos);
bool8 sub_8070564(struct Entity *pokemon, struct Position *pos);
bool8 sub_80705F0(struct Entity *pokemon, struct Position *pos);
bool8 sub_80706A4(struct Entity *pokemon, struct Position *pos);
s32 CalcSpeedStage(struct Entity *pokemon);

#endif
