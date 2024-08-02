#include "global.h"
#include "constants/direction.h"
#include "code_80861A8.h"

#include "code_806CD90.h"

static void sub_80861EC(Entity *);

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
