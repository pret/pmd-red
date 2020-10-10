#include "global.h"
#include "pokemon.h"

extern struct gPokemon *gMonsterParameters;

u8 *GetCategoryString(s16 r0)
{
    return gMonsterParameters[r0].category;
}

u8 GetPokemonSize(s16 r0)
{
    return gMonsterParameters[r0].size;
}

u8 GetShadowSize(s16 r0)
{
    return gMonsterParameters[r0].shadow_size;
}

s32 GetMoveSpeed(s16 r0)
{
    return gMonsterParameters[r0].move_speed;
}

u8 GetWalkableTiles(s16 r0)
{
    return gMonsterParameters[r0].walkable_tiles;
}

u8 GetUnk1B(s16 r0)
{
    return ((u8)(gMonsterParameters[r0].unk1B) << 25) >> 24;
}

bool8 GetIsMoving(s16 r0)
{
    return gMonsterParameters[r0].isMoving;
}

u8 GetUnk1D(s16 r0)
{
    return gMonsterParameters[r0].unk1D;
}

u16 GetLowKickDmg(s16 r0)
{
    return gMonsterParameters[r0].lowkick_dmg;
}

u16 GetSizeOrbDmg(s16 r0)
{
    return gMonsterParameters[r0].sizeorb_dmg;
}

u8 GetFriendArea(s16 r0)
{
    return gMonsterParameters[r0].friend_area;
}

u16 GetBaseHP(s16 r0)
{
    return gMonsterParameters[r0].base_hp;
}

bool8 GetUnk33(s16 r0)
{
    return gMonsterParameters[r0].unk33;
}

u8 GetUnk12(s16 r0)
{
    return gMonsterParameters[r0].unk12;
}

s16 sub_808DC0C(s16 r0)
{
    return gMonsterParameters[r0].evolve_from;
}

// TODO fix calculation to match
//u32 sub_808DC28(s16 r0, u32 r1)
//{
//    return gMonsterParameters[r0].base_att + (r1 << 1);
//}
