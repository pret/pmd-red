#include "global.h"
#include "pokemon.h"

extern struct gPokemon *gMonsterParameters;

u8 *sub_808DAB4(s16 r0)
{
    return gMonsterParameters[r0].category;
}

u8 sub_808DACC(s16 r0)
{
    return gMonsterParameters[r0].size;
}

u8 sub_808DAE4(s16 r0)
{
    return gMonsterParameters[r0].shadow_size;
}

s32 sub_808DAFC(s16 r0)
{
    return gMonsterParameters[r0].move_speed;
}

u8 sub_808DB14(s16 r0)
{
    return gMonsterParameters[r0].walkable_tiles;
}

u8 sub_808DB2C(s16 r0)
{
    return ((u8)(gMonsterParameters[r0].unk1B) << 25) >> 24;
}


bool8 sub_808DB48(s16 r0)
{
    return gMonsterParameters[r0].isMoving;
}

u8 sub_808DB60(s16 r0)
{
    return gMonsterParameters[r0].unk1D;
}

u16 sub_808DB78(s16 r0)
{
    return gMonsterParameters[r0].lowkick_dmg;
}

u16 sub_808DB90(s16 r0)
{
    return gMonsterParameters[r0].sizeorb_dmg;
}

u8 sub_808DBA8(s16 r0)
{
    return gMonsterParameters[r0].friend_area;
}

u16 sub_808DBC0(s16 r0)
{
    return gMonsterParameters[r0].base_hp;
}

bool8 sub_808DBD8(s16 r0)
{
    return gMonsterParameters[r0].unk33;
}

u8 sub_808DBF4(s16 r0)
{
    return gMonsterParameters[r0].unk12;
}

s16 sub_808DC0C(s16 r0)
{
    return gMonsterParameters[r0].evolve_from;
}
