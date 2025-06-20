#include "global.h"
#include "globaldata.h"
#include "map_script_table.h"

static EWRAM_DATA s16 sScriptFileId = {0};

static void ResetCurrentScriptFile(void);

void sub_80A7744(void)
{
    sScriptFileId = -1;
}

void sub_80A7754(void)
{
    sScriptFileId = -1;
}

void SetCurrentScriptFile(s16 a0)
{
    s32 temp = a0;

    ResetCurrentScriptFile();

    if (temp != -1)
        sScriptFileId = temp;
}

void ResetCurrentScriptFile(void)
{
    if (sScriptFileId != -1)
        sScriptFileId = -1;
}

bool8 ChangeScriptFile(s16 a0)
{
    s32 temp;
    s32 temp2;
    temp = a0;
    temp2 = temp;
    if (sScriptFileId != temp) {
        if (temp < 0)
            ResetCurrentScriptFile();
        else
            SetCurrentScriptFile(temp2);
        return TRUE;
    }
    return FALSE;
}

static const struct GroundScriptHeader sNullGroundScript = {0};

const struct GroundScriptHeader *GetGroundScript(s16 mapId)
{
    if (mapId != -1)
        return gMapScriptTable[mapId];
    else
        return &sNullGroundScript;
}
