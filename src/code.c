#include "global.h"

extern void xxx_dungeon_8042F6C(u32 r0);
extern void NDS_LoadOverlay_GroundMain();
extern u32 xxx_script_related_8098468(u32);

void NDS_LoadOverlay_GroundMain()
{

}

void nullsub_2(u32 r0)
{

}

u32 xxx_script_related_8001334(u32 r0)
{
    return xxx_script_related_8098468(r0);
}

void xxx_dungeon_8001340(u32 r0)
{
    nullsub_2(r0);
    xxx_dungeon_8042F6C(r0);
    NDS_LoadOverlay_GroundMain();
}

void nullsub_3(void)
{

}
