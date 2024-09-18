#ifndef GUARD_CODE_8069D4C_H
#define GUARD_CODE_8069D4C_H

struct unkStruct_8069D4C
{
    s16 id;
    Position pos;
    s16 HP;
    u8 atk;
    u8 spAtk;
    u8 def;
    u8 spDef;
    u16 level;
    u32 exp;
    FixedPoint belly;
    FixedPoint maxBelly;
    Item heldItem;
    Move moves[MAX_MON_MOVES];
    u32 unk40; // strugglemoveFlags?
    HiddenPower hiddenPower;
};

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target);

#endif
