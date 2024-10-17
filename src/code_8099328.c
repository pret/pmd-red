#include "global.h"
#include "code_80A26CC.h"
#include "event_flag.h"

bool8 sub_8099328(u8 *dungeonId) {
    s16 script_disc;
    DungeonInfo* dungeonInfo;

    script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 0x51) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX); 
        dungeonInfo = (DungeonInfo *)GetDungeonInfo_80A2608(script_disc);
        if(dungeonInfo->dungeonIndex < 0x3f) {
            *dungeonId = dungeonInfo->dungeonIndex;
            return TRUE;
        }
    } 
    return FALSE;
}
