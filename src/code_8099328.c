#include "global.h"
#include "code_8099328.h"
#include "code_80A26CC.h"
#include "event_flag.h"

bool8 sub_80992E0(s16 *param_1, s16 *param_2)
{
    s32 sVar2;

    sVar2 = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER);
    if ((((sVar2 != -1) && (sVar2 != 0x50)) && (sVar2 != 0x51)) && (sVar2 != 0x52)) {
        *param_1 = sVar2;
        *param_2 = GetScriptVarValue(NULL,DUNGEON_ENTER_INDEX);
        return TRUE;
    }
    else {
        *param_1 = -1;
        *param_2 = -1;
        return FALSE;
    }
}

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
