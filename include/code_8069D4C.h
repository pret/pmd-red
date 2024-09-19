#ifndef GUARD_CODE_8069D4C_H
#define GUARD_CODE_8069D4C_H

struct unkStruct_8069D4C
{
    s16 id;
    Position pos;
    s16 HP;
    /* 0x0 */ u8 att[2]; // Atk, SpAtk
    /* 0x2 */ u8 def[2]; // Def, SpDef
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
