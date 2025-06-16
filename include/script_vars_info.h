#ifndef GUARD_SCRIPT_VARS_INFO_H
#define GUARD_SCRIPT_VARS_INFO_H

#include "constants/event_flag.h"

// size: 0x10
struct ScriptVarInfo {
    s16 type;
    s16 unk2;
    s16 bufOffset;
    s16 bitOffset;
    s16 arrayLen;
    s16 defaultValue;
    char *name;
};

extern const struct ScriptVarInfo gScriptVarInfo[SCRIPT_VARS_COUNT];

#endif // GUARD_SCRIPT_VARS_INFO_H
