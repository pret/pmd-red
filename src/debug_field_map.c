#include "global.h"
#include "globaldata.h"
#include "debug_field_map_window.h"
#include "music_util.h"
#include "code_800558C.h"
#include "code_8099360.h"
#include "code_800C9CC.h"
#include "graphics_memory.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "ground_map.h"
#include "palette_util.h"
#include "string_format.h"
#include "sprite.h"
#include "game_options.h"
#include "ground_lives_helper.h"
#include "input.h"
#include "structs/str_position.h"
#include "code_809D148.h"
#include "direction_util.h"
#include "menu_input.h"
#include "constants/input.h"

UNUSED static void DebugMapViewer(void)
{
    PixelPos currPos;
    s32 mapId = 0;

    ResetSoundEffectCounters();
    FadeOutAllMusic(16);
    gUnknown_2026E4E = 0x808;
    UpdateFadeInTile(0);
    sub_80095CC(0, 0x14);
    ShowWindows(NULL, TRUE, TRUE);
    sub_8009408(0, 20);
    sub_8099648();
    sub_809975C();
    sub_809D0AC();
    ResetDialogueBox();
    sub_8005838(NULL, 0);
    AllocGroundMapAction();
    while (1) {
        bool8 quitMapView;
        PixelPos pixPos1, pixPos2;
        PixelPos boundary;

        if (DebugFieldMapWindow_Init()) {
            DebugFieldMapWindow_MoveMenuTo(mapId);
            while (1) {
                sub_8005838(NULL, 0);
                sub_8012A18(0);
                switch (DebugFieldMapWindow_GetInput()) {
                    case MENU_INPUT_A_PRESS:
                        mapId = DebugFieldMapWindow_GetCurrentIndex();
                        break;
                    case MENU_INPUT_B_PRESS:
                        mapId = -1;
                        break;
                    default:
                        continue;
                }
                break;
            }
        }
        else {
            mapId = -1;
        }

        DebugFieldMapWindow_Free();
        if (mapId == -1)
            break;

        ShowWindows(NULL, TRUE, TRUE);
        GroundMap_Reset();
        sub_809D0BC();
        GroundMap_Select(mapId);
        sub_80A579C(&pixPos1, &pixPos2);
        pixPos1.y += 0xC00;
        pixPos2.y += 0xC00;
        pixPos1.x -= 0x400;
        pixPos1.y -= 0x400;
        pixPos2.x += 0x400;
        pixPos2.y += 0x400;
        boundary.x = pixPos2.x - pixPos1.x;
        boundary.y = pixPos2.y - pixPos1.y;
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
                    s8 dir = DpadToDirection(held);
                    if (dir != -1) {
                        PixelPos vecPos = SetVecFromDirectionSpeed(dir, 256);
                        s32 spdMultiplier = (held & B_BUTTON) ? 4 : 2;

                        currPos.x += vecPos.x * spdMultiplier;
                        currPos.y += vecPos.y * spdMultiplier;
                        if (currPos.x < 0) {
                            currPos.x = 0;
                        }
                        else if (currPos.x >= boundary.x) {
                            currPos.x = boundary.x - 1;
                        }

                        if (currPos.y < 0) {
                            currPos.y = 0;
                        }
                        else if (currPos.y >= boundary.y) {
                            currPos.y = boundary.y - 1;
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
            nullsub_8(gGameOptionsRef->touchScreen);
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
