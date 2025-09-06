#include "global.h"
#include "globaldata.h"
#include "dungeon_cleared_window.h"
#include "dungeon_info.h"
#include "dungeon_strings.h"
#include "dungeon_vram.h"
#include "input.h"
#include "text_1.h"
#include "run_dungeon.h"
#include "dungeon_run_end.h"
#include "dungeon_music.h"
#include "game_options.h"

void ShowDungeonClearedWindow(void)
{
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {4, 3},
                .width = 22,
                .height = 14,
                .unk10 = 14,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    header.count = 1;
    header.currId = 0;
    header.width = 14;
    header.f3 = 0;
    windows.id[0].pos.y = 20;
    DungeonShowWindows(&windows, TRUE);
    if (gDungeon->exitSummary.exitReason > 549) {
        PlayDungeonCompleteBGM();
    }
    else {
        PlayDungeonFailBGM();
    }
    PrintOnDungeonFinishedWindow(0, gText_TheLastOuting,&gDungeon->exitSummary);
    while(1) {
        sub_803E668(0x36);
        UpdateDungeonMusic();
        if (windows.id[0].pos.y >= 4){
            windows.id[0].pos.y--;
            windows.id[0].unk0 = 0xa0;
            DungeonShowWindows(&windows, TRUE);
            continue;
        }
        if (sub_8094D14())
            break;
        if (gRealInputs.pressed & A_BUTTON)
            break;
    }
    PlayDungeonConfirmationSE();
}
