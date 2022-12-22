#include "global.h"
#include "dungeon.h"

u32 sub_803C1B4(struct DungeonLocation *dungeon, u8 r1)
{
    s32 temp;
    temp = sub_80908D8(dungeon);
    if(r1 == 2)
    {
        temp += 2;
    }
    if(temp > 0xF)
        temp = 0xF;
    return temp;
}

