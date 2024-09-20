#ifndef GUARD_CODE_8069D4C_H
#define GUARD_CODE_8069D4C_H

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
    FixedPoint belly;
    FixedPoint maxBelly;
    Item heldItem;
    Moves moves;
    HiddenPower hiddenPower;
};

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target);

#endif
