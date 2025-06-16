#ifndef GUARD_SCRIPT_VARS_INFO_H
#define GUARD_SCRIPT_VARS_INFO_H

#include "constants/event_flag.h"

enum {
    SCRIPT_VAR_TYPE_0, // 0
    SCRIPT_VAR_TYPE_BIT, // 1
    SCRIPT_VAR_TYPE_U8, // 2
    SCRIPT_VAR_TYPE_S8, // 3
    SCRIPT_VAR_TYPE_U16, // 4
    SCRIPT_VAR_TYPE_S16, // 5
    SCRIPT_VAR_TYPE_S32, // 6
    SCRIPT_VAR_TYPE_U8_2, // 7 Unused
    SCRIPT_VAR_TYPE_SPECIAL, // 8
};

// size: 0x10
struct ScriptVarInfo {
    s16 type;
    s16 unk2;
    s16 bufOffset;
    s16 bitOffset;
    s16 arrayLen;
    s16 defaultValue;
    const char *name;
};

extern const struct ScriptVarInfo gScriptVarInfo[SCRIPT_VARS_COUNT];

#endif // GUARD_SCRIPT_VARS_INFO_H
