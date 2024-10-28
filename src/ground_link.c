#include "global.h"
#include "debug.h"
#include "ground_script.h"

EWRAM_DATA_2 const struct GroundLink *gCurrentGroundLink = NULL;
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
