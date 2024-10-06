#ifndef GUARD_CODE_8069D4C_H
#define GUARD_CODE_8069D4C_H

#include "structs/dungeon_entity.h"

// NOTE: basically Offense struct but packed to match
struct unkStruct_8069D4C_sub
{

    u8 att[2]; // Atk, SpAtk
    u8 def[2]; // Def, SpDef
} __attribute__((packed));

struct unkStruct_8069D4C
{
    s16 id;
    Position pos;
    s16 HP;
    struct unkStruct_8069D4C_sub offense;
    u16 level;
    u32 exp;
    FixedPoint belly;
    FixedPoint maxBelly;
    Item heldItem;
    Moves moves;
    HiddenPower hiddenPower;
};

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target);

#endif
