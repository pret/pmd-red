#include "global.h"
#include "ground_map.h"
#include "ground_map_2.h"
#include "ground_script.h"

extern GroundMapAction *gGroundMapAction;
extern DebugLocation gUnknown_8117770;

extern s16 HandleAction(Action *action, DebugLocation *debug);
extern void sub_80A4740(void *, s32, s32 *, u32);
extern u32 sub_80A4720(void *, s32, s32 *);
extern u8 sub_80A46C0(unkStruct_3001B70 *, u32, s32, s32);
extern u8 sub_80A4660(unkStruct_3001B70 *, u32, s32, s32);

u8 sub_80A5934(s32 param_1, s32 param_2, s32 param_3)
{
    u32 param_1_u32 = (u8)param_1;
    return sub_80A4660(gGroundMapDungeon_3001B70, param_1_u32, param_2, param_3);
}

u8 sub_80A595C(s32 param_1, s32 param_2, s32 param_3)
{
    u32 param_1_u32 = (u8)param_1;
    return sub_80A46C0(gGroundMapDungeon_3001B70, param_1_u32, param_2, param_3);
}

u16 sub_80A5984(s32 param_1, s32 *param_2)
{
    return sub_80A4720(gGroundMapDungeon_3001B70, param_1, param_2);
}

void sub_80A59A0(s32 param_1, s32 *param_2, u32 param_3)
{
    u32 param_3_u32 = (u16)param_3;
    sub_80A4740(gGroundMapDungeon_3001B70, param_1, param_2, param_3_u32);
}

void GroundMap_Action(void)
{
    nullsub_123(); 
    HandleAction((Action *)gGroundMapAction, &gUnknown_8117770);
}
