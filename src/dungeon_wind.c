#include "global.h"
#include "globaldata.h"
#include "dungeon_wind.h"
#include "dungeon_misc.h"
#include "code_804267C.h"
#include "dungeon_message.h"
#include "constants/ability.h"
#include "constants/dungeon_exit.h"
#include "constants/type.h"
#include "dungeon_ai.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_util.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "dungeon_main.h"
#include "dungeon_misc.h"
#include "move_util.h"
#include "moves.h"
#include "structs/str_dungeon.h"
#include "dungeon_engine.h"
#include "dungeon_entity_movement.h"

void UpdateWindTurns(void)
{
    Entity *leader = GetLeader();

    if (!EntityIsValid(leader))
        return;

    if (gDungeon->unk644.windTurns <= 0 || --gDungeon->unk644.windTurns < 1) {
        gDungeon->unk644.windPhase = 3;
    }

    if (gDungeon->unk644.windPhase == 0) {
        if (gDungeon->unk644.windTurns < 0xfa) {
            sub_805E804();
            TryPointCameraToMonster(leader,1);
            DisplayActions(leader);
            if (!IsFloorOver()) {
                LogMessageByIdWithPopupCheckUser(leader,gText_SomethingStirring);
                sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],0);
                gDungeon->unk644.windPhase = 1;
            }
        }
    }
    else if (gDungeon->unk644.windPhase == 1) {
        if (gDungeon->unk644.windTurns < 0x96) {
            sub_805E804();
            TryPointCameraToMonster(leader,1);
            DisplayActions(leader);
            if (!IsFloorOver()) {
                LogMessageByIdWithPopupCheckUser(leader,gText_SomethingApproaching);
                sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],1);
                gDungeon->unk644.windPhase = 2;
            }
        }
    }
    else if (gDungeon->unk644.windPhase == 2) {
        if (gDungeon->unk644.windTurns < 0x32) {
            sub_805E804();
            TryPointCameraToMonster(leader,1);
            DisplayActions(leader);
            if (!IsFloorOver()) {
                LogMessageByIdWithPopupCheckUser(leader,gText_ItsGettingCloser);
                sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],2);
                gDungeon->unk644.windPhase = 3;
            }
        }
    }
    else {
        if (gDungeon->unk644.windTurns < 1) {
            sub_805E804();
            TryPointCameraToMonster(leader,1);
            DisplayActions(leader);
            if (!IsFloorOver()) {
                LogMessageByIdWithPopupCheckUser(leader,gText_ItsRightNearbyGustingHard);
                sub_80426C8(gUnknown_80F5FAC[gDungeon->tileset],3);
                gDungeon->unk644.windPhase = 4;
                HandleFaint(leader,DUNGEON_EXIT_BLOWN_OUT_UNSEEN_FORCE,leader);
            }
        }
    }
}
