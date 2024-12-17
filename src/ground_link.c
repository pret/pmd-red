#include "global.h"
#include "ground_link.h"
#include "debug.h"
#include "ground_script.h"
#include "number_util.h"

EWRAM_INIT const struct GroundLink *gCurrentGroundLink = NULL;
extern DebugLocation gUnknown_8118798;
extern const struct GroundScriptHeader *GetGroundScript(s16 r0, DebugLocation *r1);

void sub_80AD868(void)
{
    gCurrentGroundLink = NULL;
}

void sub_80AD874(void)
{
    gCurrentGroundLink = NULL;
}

void GroundLink_Select(s16 r0)
{
    const struct GroundScriptHeader *gs = GetGroundScript(r0, &gUnknown_8118798);
    gCurrentGroundLink = gs->links;
}

const struct GroundLink *GetCurrentGroundLink(s16 r0)
{
    u32 a = r0;
    return &gCurrentGroundLink[a];
}

s32 GroundLink_GetPos(s32 _arg0, PixelPos *pos)
{
    s32 arg0 = (s16)(_arg0);
    const struct GroundLink *ptr = &gCurrentGroundLink[arg0];

    if (!(ptr->pos.xFlags & 4)) {
        s32 xAdd = IntToF248(4).raw;

        pos->x = IntToF248(ptr->pos.xTiles * 8).raw;
        if (ptr->pos.xFlags & 2) {
            pos->x += xAdd;
        }
    }

    if (!(ptr->pos.yFlags & 4)) {
        s32 yAdd = IntToF248(4).raw;

        pos->y = IntToF248(ptr->pos.yTiles * 8).raw;
        if (ptr->pos.yFlags & 2) {
            pos->y += yAdd;
        }
    }

    return ptr->ret;
}

s32 GroundLink_GetArea(s32 _arg0, PixelPos *arg1, PixelPos *arg2, PixelPos *arg3)
{
    s32 arg0 = (s16) _arg0;
    const struct GroundLink *ptr = &gCurrentGroundLink[arg0];

    *arg1 = *arg3;
    if (!(ptr->pos.xFlags & 4))
    {
        s32 xAdd = IntToF248(4).raw;

        arg1->x = IntToF248(ptr->pos.xTiles * 8).raw;
        if (ptr->pos.xFlags & 2)
            arg1->x += xAdd;
    }

    if (!(ptr->pos.yFlags & 4))
    {
        s32 yAdd = IntToF248(4).raw;

        arg1->y = IntToF248(ptr->pos.yTiles * 8).raw;
        if (ptr->pos.yFlags & 2) {
            arg1->y += yAdd;
        }
    }

    arg2->x = arg1->x + IntToF248(ptr->width * 8).raw;
    arg2->y = arg1->y + IntToF248(ptr->height * 8).raw;
    return ptr->ret;
}
