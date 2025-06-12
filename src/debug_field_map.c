#include "global.h"
#include "globaldata.h"
#include "music_util.h"
#include "code_800558C.h"
#include "code_801D9E4.h"
#include "code_8099360.h"
#include "code_800C9CC.h"
#include "graphics_memory.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "ground_map.h"
#include "ground_map_2.h"
#include "palette_util.h"
#include "string_format.h"
#include "sprite.h"
#include "game_options.h"
#include "input.h"
#include "structs/str_position.h"

extern void sub_809D0AC(void);
extern void sub_8012A18(s32 unused);
extern void sub_809D0BC(void);
extern bool8 sub_80A579C(PixelPos *a0, PixelPos *a1);
extern void GroundMap_Select(s16);
extern void sub_80999E8(s32 a0);
extern void nullsub_120(void);
extern void sub_80A59DC(void);
extern void sub_809D25C(void);
extern s32 sub_809CFE8(u16 param_1);
extern PixelPos SetVecFromDirectionSpeed(s8 r1, u32 r2);
extern void sub_809D158(s32, PixelPos*);

UNUSED static void sub_80993F0(void)
{
    PixelPos currPos;
    s32 r10 = 0;

    ResetSoundEffectCounters();
    FadeOutAllMusic(16);
    gUnknown_2026E4E = 0x808;
    UpdateFadeInTile(0);
    sub_80095CC(0, 0x14);
    ShowWindows(NULL, TRUE, TRUE); // TODO: Create a Hide/Reset Windows macro/static inline
    sub_8009408(0, 20);
    sub_8099648();
    sub_809975C();
    sub_809D0AC();
    sub_8014144();
    sub_8005838(NULL, 0);
    AllocGroundMapAction();
    while (1) {
        bool8 quitMapView;
        PixelPos pixPos1, pixPos2;
        PixelPos pixPos3;

        if (sub_801D9E4()) {
            sub_801DA58(r10);
            while (1) {
                sub_8005838(NULL, 0);
                sub_8012A18(0);
                switch (sub_801DA78()) {
                    case 3:
                        r10 = sub_801DAC0();
                        break;
                    case 2:
                        r10 = -1;
                        break;
                    default:
                        continue;
                }
                break;
            }
        }
        else {
            r10 = -1;
        }

        sub_801DB0C();
        if (r10 == -1)
            break;

        ShowWindows(NULL, TRUE, TRUE);
        GroundMap_Reset();
        sub_809D0BC();
        GroundMap_Select(r10);
        sub_80A579C(&pixPos1, &pixPos2);
        pixPos1.y += 0xC00;
        pixPos2.y += 0xC00;
        pixPos1.x -= 0x400;
        pixPos1.y -= 0x400;
        pixPos2.x += 0x400;
        pixPos2.y += 0x400;
        pixPos3.x = pixPos2.x - pixPos1.x;
        pixPos3.y = pixPos2.y - pixPos1.y;
        currPos.x = 0;
        currPos.y = 0;
        sub_80999E8(4);
        quitMapView = FALSE;
        while (1) {
            xxx_call_update_bg_sound_input();
            ResetSprites(FALSE);
            if (quitMapView && !sub_8099B94())
                break;
            if (!quitMapView) {
                u32 pressed = gRealInputs.pressed;
                u32 held = gRealInputs.held;
                if (pressed & SELECT_BUTTON) {
                    sub_80999FC(4);
                    quitMapView = TRUE;
                }
                else {
                    PixelPos pixPos4;
                    s8 dir = sub_809CFE8(held);
                    if (dir != -1) {
                        PixelPos vecPos = SetVecFromDirectionSpeed(dir, 256);
                        s32 spdMultiplier = (held & B_BUTTON) ? 4 : 2;

                        currPos.x += vecPos.x * spdMultiplier;
                        currPos.y += vecPos.y * spdMultiplier;
                        if (currPos.x < 0) {
                            currPos.x = 0;
                        }
                        else if (currPos.x >= pixPos3.x) {
                            currPos.x = pixPos3.x - 1;
                        }

                        if (currPos.y < 0) {
                            currPos.y = 0;
                        }
                        else if (currPos.y >= pixPos3.y) {
                            currPos.y = pixPos3.y - 1;
                        }
                    }
                    pixPos4.x = pixPos1.x + currPos.x;
                    pixPos4.y = pixPos1.y + currPos.y;
                    sub_809D158(0, &pixPos4);
                }
            }

            sub_809D25C();
            sub_80A59DC();
            DrawDialogueBoxString();
            sub_8005838(NULL, 0);
            sub_80060EC();
            nullsub_8(gGameOptionsRef->unkA);
            sub_8005180();
            sub_8099BE4();
            sub_8099744();
            UpdateSoundEffectCounters();
            WaitForNextFrameAndAdvanceRNG();
            LoadBufferedInputs();
            nullsub_120();
            sub_80A5E70();
            xxx_call_update_bg_vram();
            CopySpritesToOam();
            sub_8005304();
            sub_8099750();
            DoScheduledMemCopies();
        }
    }

    FadeOutAllMusic(16);
    FreeGroundMapAction();
    sub_8099768();
    nullsub_103();
}

