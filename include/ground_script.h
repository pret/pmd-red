#ifndef GUARD_GROUND_SCRIPT_H
#define GUARD_GROUND_SCRIPT_H

#include "structs/str_position.h"

typedef struct ScriptCommand {
    // size: 0x10
    /* 0x0 */ u8  op;
    /* 0x1 */ u8  argByte;
    /* 0x2 */ s16 argShort;
    /* 0x4 */ s32 arg1;
    /* 0x8 */ s32 arg2;
    /* 0xC */ u8* argPtr;
} ScriptCommand;

typedef struct ScriptInfoSmall
{
    // size: 0xC (3 padding)
    /* 0x0 */ ScriptCommand *ptr;
    /* 0x4 */ s16 state;
    /* 0x6 */ s16 group;
    /* 0x8 */ s8  sector;
} ScriptInfoSmall;

typedef struct ScriptInfo
{
    // size: 0xC (1 padding)
    /* 0x0 */ ScriptCommand *ptr;
    /* 0x4 */ ScriptCommand *ptr2;
    /* 0x8 */ s16 group;
    /* 0xA */ s8  sector;
} ScriptInfo;

typedef union ScriptUnion832 {
    s32 raw;
    s8  arr[4];
} ScriptUnion832;

typedef union ScriptUnion1632 {
    s32 raw;
    s16 arr[2];
} ScriptUnion1632;

typedef struct ScriptData
{
    // size: 0x60
    /* 0x00 */ s16 state;
    /* 0x02 */ s16 savedState;
    /* 0x04 */ ScriptInfo script;
    // padding
    /* 0x10 */ ScriptInfo savedScript;
    // padding
    /* 0x1C */ ScriptCommand *curPtr;
    /* 0x20 */ u8  curScriptOp;
    // padding
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ s8  unk26;
    // padding
    /* 0x28 */ s16 branchDiscriminant;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u16 unk2C;
    // padding
    /* 0x30 */ s32 unk30;
    /* 0x34 */ Position32 pos1;
    /* 0x3C */ Position32 pos2;
    /* 0x44 */ u8  unk44[4];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ u8  unk4C;
    /* 0x4D */ u8  unk4D;
    // padding
    // ultimately accessed as ldrb, doesn't work as array of u32-sized structs, needs union
    /* 0x50 */ ScriptUnion832 unk50[4];
} ScriptData;

typedef struct CallbackData
{
    // size: 0x54
    /* 0x00 */ u16 maybeId;
    // padding
    // (almost?) all callbacks take the parentObject as first parameter
    /* 0x04 */ s16 (*getIndex)(void*); // id related
    /* 0x08 */ u32 (*getSize)();
    /* 0x0C */ u32 (*getHitboxCenter)();
    /* 0x10 */ u32 (*getPosHeightAndUnk)();
    /* 0x14 */ u32 (*getDirection)();
    /* 0x18 */ u32 (*getFlags)();
    /* 0x1C */ u32 (*setHitboxPos)();
    /* 0x20 */ u32 (*setPositionBounds)();
    /* 0x24 */ u32 (*moveReal)();
    /* 0x28 */ u32 (*setPosHeight)();
    /* 0x2C */ u32 (*setDirection)();
    /* 0x30 */ u32 (*setEventIndex)();
    /* 0x34 */ u32 (*livesOnlyNullsub)();
    /* 0x38 */ u32 (*func38)();
    /* 0x3C */ u32 (*setFlags)();
    /* 0x40 */ u32 (*clearFlags)();
    /* 0x44 */ u32 (*func44_livesOnlySpriteRelated)();
    /* 0x48 */ u32 (*moveRelative)();
    /* 0x4C */ u32 (*func4C_spriteRelatedCheck)();
    /* 0x50 */ u32 (*func50_spriteRelated)();
} CallbackData;

typedef struct Action
{
    // size: 0xE4
    /* 0x00 */ const struct CallbackData *callbacks;
    /* 0x04 */ void *parentObject; // struct GroundObject *
    /* 0x08 */ s16 unk8[2]; // id?
    /* 0x0C */ ScriptUnion1632 unkC;
    /* 0x10 */ s16 group;
    /* 0x12 */ s8  sector;
    // padding
    /* 0x14 */ ScriptCommand *predefinedScripts[4];
    /* 0x24 */ ScriptData scriptData;
    /* 0x84 */ ScriptData scriptData2;
} Action;

// Only used when accessing gGroundMapAction (3001B6C), basically everything else just uses Action
// probably worth moving to ground_map.h together with the main GroundMap struct
// oh well, TODO later I guess
typedef struct GroundMapAction
{
    // size: 0x110
    /* 0x00 */ Action action;
    /* 0xE4 */ u16 groundMapId;
    /* .... */ u8  fillE8[0x110 - 0xE6];
} GroundMapAction;

typedef struct FunctionScript
{
    u16 unk0;
    s16 unk2;
    u8 *funcName;
    ScriptCommand *script;
} FunctionScript;

extern FunctionScript gFunctionScriptTable[];

#include "debug.h"

void InitScriptData(ScriptData *a0);
u8 GroundScriptCheckLockCondition(Action *param_1, s16 param_2);
void InitAction2(Action *action);
void GetFunctionScript(Action *param_1, ScriptInfoSmall *script, s16 index);
bool8 GroundScriptLockCond(Action *param_1, s16 index, u32 param_3);
bool8 ActionResetScriptData(Action *param_1, const DebugLocation *unused);
bool8 GroundScript_ExecutePP(Action *, s32 *, ScriptInfoSmall *, const DebugLocation *unused);
ScriptCommand *FindLabel(Action *action, s32 r1);
ScriptCommand *ResolveJump(Action *action, s32 r1);
void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s16 group, s8 sector);

#endif // GUARD_GROUND_SCRIPT_H
