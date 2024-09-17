#ifndef GUARD_STR_DAMAGE_H
#define GUARD_STR_DAMAGE_H

struct DamageStruct
{
    s32 dmg;
    s32 residualDmgType;
    u32 typeEffectiveness;
    u8 type;
    bool8 isCrit;
    u8 unkE;
    u8 unkF;
};

#endif
