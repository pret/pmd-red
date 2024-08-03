#include "global.h"
#include "constants/direction.h"
#include "code_80861A8.h"

#include "code_803E668.h"
#include "code_806CD90.h"
#include "dungeon_music.h"

extern const u8 *gUnknown_810665C[];
extern const u8 *gUnknown_810668C[];
extern const u8 *gUnknown_81066D4[];
extern const u8 *gUnknown_81066F0[];
extern const u8 *gUnknown_810671C[];


static void sub_80861EC(Entity *);

void sub_8052FB8(const u8 *); 

void sub_8086124(Entity *entity, u8 param_2)
{
    entity->info->unk160 = param_2;
}

void sub_8086130(void)
{
    DungeonFadeOutBGM(0x3c);
    sub_803E708(0x3c,0x46);
    sub_8052FB8(*gUnknown_810665C);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_810668C);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_81066D4);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_81066F0);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_810671C);
    sub_803E708(0x1e,0x46);
}

void sub_80861A8(Entity *a0)
{
    sub_806CDD4(a0, 0, NUM_DIRECTIONS);
}

void sub_80861B8(Entity *a0, u8 r1, s32 direction)
{
    EntityInfo *info;

    info = a0->info;

    sub_806CDD4(a0, r1, direction);
    info->unkFE = r1;
}

void sub_80861D4(Entity *a0, u8 r1, s32 direction)
{
    sub_806CDD4(a0, r1, direction);
    sub_80861EC(a0);
}

void sub_80861EC(Entity *a0)
{
    a0->info->unkFE = 0x63;
}
