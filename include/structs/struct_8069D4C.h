#ifndef GUARD_STRUCT_8069D4C_H
#define GUARD_STRUCT_8069D4C_H

#include "structs/dungeon_entity.h"
#include "structs/str_items.h"
#include "structs/str_pokemon.h"
#include "structs/str_position.h"

struct unkStruct_8069D4C 
{
    s16 id;
    Position pos;
    s16 HP;
    // NOTE: cannot re-use offense struct as it pads.
    u8 att[2]; // Atk, SpAtk
    u8 def[2]; // Def, SpDef
    u16 level;
    u32 exp;
    u32 belly;
    u32 maxBelly;
    Item heldItem;
    unkStruct_8094184 moves;
    HiddenPower hiddenPower;
};

#endif // GUARD_STRUCT_8069D4C_H

