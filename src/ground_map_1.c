#include "global.h"
#include "ground_map.h"
#include "ground_map_2.h"
#include "ground_script.h"

extern GroundMapAction *gGroundMapAction;
extern DebugLocation gUnknown_8117770;

extern s16 HandleAction(Action *action, DebugLocation *debug);
extern void sub_80A4740(void *, s32, s32 *, u32);
extern u32 sub_80A4720(void *, s32, s32 *);
extern u8 sub_80A46C0(GroundBg *, u32, s32, s32);
extern u8 sub_80A4660(GroundBg *, u32, s32, s32);

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

extern u8 sub_809D248(PixelPos *r0);
extern void sub_80A4580(GroundBg *, u32, PixelPos *);
extern void sub_80A456C(GroundBg *, u32, const PixelPos *);
extern void sub_80A4764(GroundBg *);

extern GroundMapAction *gGroundMapAction;

void sub_80A59DC(void)
{
    if (gGroundMapDungeon_3001B70 != NULL) {
        PixelPos pixPos;

        if (sub_809D248(&pixPos) == 0) {
            pixPos.x = 0;
            pixPos.y = 0;
        }

        switch (gGroundMapAction->groundMapId) {
            case 0xA2:
            case 0xA3:
            case 0xDF: {
                PixelPos pixPos2;

                gGroundMapAction->unkF4 += 2;
                gGroundMapAction->unkF8.y += gGroundMapAction->unkF4 / 4;
                gGroundMapAction->unkF4 &= 3;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x, pixPos.y + gGroundMapAction->unkF8.y };
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos2);
                pixPos2.x = pixPos.x;
                pixPos2.y = pixPos.y - gGroundMapAction->unkF8.y;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case 0xA8:
            case 0xAA: {
                PixelPos pixPos2;

                gGroundMapAction->unkF0 += gGroundMapAction->unkE8;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y };
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case 0xAE: {
                PixelPos pixPos2;

                gGroundMapAction->unkF0 += gGroundMapAction->unkE8;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y };
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case 0xAB: {
                PixelPos pixPos2 = pixPos;

                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case 0xAF: {
                PixelPos pixPos2;

                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos);
                gGroundMapAction->unkF0 += gGroundMapAction->unkE8;
                gGroundMapAction->unkF4 += gGroundMapAction->unkEC;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF8.y += gGroundMapAction->unkF4 / 8;
                gGroundMapAction->unkF0 %= 8;
                gGroundMapAction->unkF4 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y + gGroundMapAction->unkF8.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case 0xB0: {
                PixelPos pixPos2;

                gGroundMapAction->unkF0 += gGroundMapAction->unkE8;
                gGroundMapAction->unkF4 += gGroundMapAction->unkEC;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF8.y += gGroundMapAction->unkF4 / 8;
                gGroundMapAction->unkF0 %= 8;
                gGroundMapAction->unkF4 %= 8;
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y + gGroundMapAction->unkF8.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case 0xBA: {
                PixelPos pixPos2;

                sub_80A456C(gGroundMapDungeon_3001B70, 1, &pixPos);
                gGroundMapAction->unkF0++;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 4;
                gGroundMapAction->unkF0 &= 3;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 0, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos2);
                break;
            }
            case 4: {
                PixelPos pixPos2;

                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos);
                gGroundMapAction->unkF0++;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 &= 7;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { pixPos.x + gGroundMapAction->unkF8.x, pixPos.y};
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &pixPos2);
                sub_80A456C(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case 0xE0: {
                PixelPos pixPos2;

                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos);
                gGroundMapAction->unkF0++;
                gGroundMapAction->unkF8.x += gGroundMapAction->unkF0 / 8;
                gGroundMapAction->unkF0 &= 7;
                sub_80A4580(gGroundMapDungeon_3001B70, 1, &gGroundMapAction->unkF8);
                pixPos2 = (PixelPos) { gGroundMapAction->unkF8.x, pixPos.y};
                sub_80A456C(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            case 0xA1: {
                PixelPos pixPos2;

                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos);
                pixPos2 = (PixelPos) {0, 0};
                sub_80A456C(gGroundMapDungeon_3001B70, 1, &pixPos2);
                break;
            }
            default:
                sub_80A456C(gGroundMapDungeon_3001B70, 0, &pixPos);
                break;
        }

        sub_80A4764(gGroundMapDungeon_3001B70);
    }

    sub_80A60D8();
}
