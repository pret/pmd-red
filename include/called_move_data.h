#ifndef GUARD_CALLED_MOVE_DATA_H
#define GUARD_CALLED_MOVE_DATA_H

#include "structs/dungeon_entity.h"
#include "structs/str_moves.h"

typedef bool8 (*MoveCallback)(Entity *pokemon, Entity *target, Move *move, s32 param_4);
struct CalledMove
{
    u16 moveID;
    MoveCallback callback;
};

#define METRONOME_AVAILABLE_CALLED_MOVES 105
extern const struct CalledMove gMetronomeCalledMoves[METRONOME_AVAILABLE_CALLED_MOVES];
extern const struct CalledMove gNaturePowerCalledMoves[];

#endif
