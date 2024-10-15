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
    /* 0xC */ const u8* argPtr;
} ScriptCommand;

typedef struct ScriptInfoSmall
{
    // size: 0xC (3 padding)
    /* 0x0 */ const ScriptCommand *ptr;
    /* 0x4 */ s16 state;
    /* 0x6 */ s16 group;
    /* 0x8 */ s8  sector;
} ScriptInfoSmall;

typedef struct ScriptInfo
{
    // size: 0xC (1 padding)
    /* 0x0 */ const ScriptCommand *ptr;
    /* 0x4 */ const ScriptCommand *ptr2;
    /* 0x8 */ s16 group;
    /* 0xA */ s8  sector;
} ScriptInfo;

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
    /* 0x1C */ const ScriptCommand *curPtr;
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
    /* 0x50 */ union {
        u8  buf[16];
        u32 val[4];
    } localVars;
} ScriptData;

typedef struct CallbackData
{
    // size: 0x54
    /* 0x00 */ u16 maybeId;
    // padding
    // All callbacks take the parentObject as first parameter
    /* 0x04 */ s16 (*getIndex)(void*); // id related
    /* 0x08 */ void (*getSize)(void*, Position32 *out);
    /* 0x0C */ void (*getHitboxCenter)(void*, Position32 *out);
    /* 0x10 */ void (*getPosHeightAndUnk)(void*, u32 *height, u32 *unk);
    /* 0x14 */ void (*getDirection)(void*, s8 *dir);
    /* 0x18 */ void (*getFlags)(void*, u32 *flags);
    /* 0x1C */ void (*setHitboxPos)(void*, Position32 *posOrNull);
    /* 0x20 */ void (*setPositionBounds)(void*, Position32 *from, Position32 *to);
    /* 0x24 */ bool8 (*moveReal)(void*, Position32*);
    /* 0x28 */ void (*setPosHeight)(void*, u32 height);
    /* 0x2C */ void (*setDirection)(void*, s8 dir); // direction must be signed char!
    /* 0x30 */ void (*setEventIndex)(void*, u16);
    /* 0x34 */ void (*livesOnlyNullsub)(void*, u16);
    /* 0x38 */ void (*func38)(void*, s16, u32);
    /* 0x3C */ void (*setFlags)(void*, u32 bits);
    /* 0x40 */ void (*clearFlags)(void*, u32 bits);
    /* 0x44 */ void (*func44_livesOnlySpriteRelated)(void*, u32);
    /* 0x48 */ void (*moveRelative)(void*, Position32*);
    /* 0x4C */ bool8 (*func4C_spriteRelatedCheck)(void*);
    /* 0x50 */ bool8 (*func50_spriteRelated)(void*);
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
    /* 0x14 */ const ScriptCommand *predefinedScripts[4];
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

typedef struct ScriptRef
{
    u16 id;
    s16 type;
    u8 *name;
    const ScriptCommand *script;
} ScriptRef;

extern const ScriptRef gFunctionScriptTable[];

struct CompactPos {
    u8 xTiles;
    u8 yTiles;
    u8 xFlags;
    u8 yFlags;
};
struct GroundLink {
    struct CompactPos pos;
    u8 width;
    u8 height;
    u8 ret;
    u8 unk7;
};
typedef struct GroundLivesData {
    u8 kind;
    u8 unk1;
    u8 width;
    u8 height;
    struct CompactPos pos;
    const ScriptCommand *scripts[4];
} GroundLivesData;
typedef struct GroundObjectData {
    u8 kind;
    u8 unk1;
    u8 width;
    u8 height;
    struct CompactPos pos;
    const ScriptCommand *scripts[4];
} GroundObjectData;
typedef struct GroundEffectData {
    u8 kind;
    u8 unk1;
    u8 width;
    u8 height;
    struct CompactPos pos;
    const ScriptCommand *script;
} GroundEffectData;
typedef struct GroundEventData {
    u8 kind;
    u8 unk1;
    u8 width;
    u8 height;
    struct CompactPos pos;
    const ScriptRef *script;
} GroundEventData;

struct GroundScriptSector {
    u32 nLives;
    const GroundLivesData *lives;
    u32 nObjects;
    const GroundObjectData *objects;
    u32 nEffects;
    const GroundEffectData *effects;
    u32 nEvents;
    const GroundEventData *events;
    u32 hasStation;
    const ScriptRef * const *station;
};
struct GroundScriptGroup {
    u32 nSectors;
    const struct GroundScriptSector *sectors;
};
struct GroundScriptHeader {
    u32 nGroups;
    const struct GroundScriptGroup *groups;
    const struct GroundLink *links;
};

#include "debug.h"

void InitScriptData(ScriptData *a0);
u8 GroundScriptCheckLockCondition(Action *param_1, s16 param_2);
void InitAction2(Action *action);
void GetFunctionScript(Action *param_1, ScriptInfoSmall *script, s16 index);
bool8 GroundScriptLockCond(Action *param_1, s16 index, u32 param_3);
bool8 ActionResetScriptData(Action *param_1, const DebugLocation *unused);
bool8 GroundScript_ExecutePP(Action *, s32 *, ScriptInfoSmall *, const DebugLocation *unused);
const ScriptCommand *FindLabel(Action *action, s32 r1);
const ScriptCommand *ResolveJump(Action *action, s32 r1);
void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s16 group, s8 sector);

#endif // GUARD_GROUND_SCRIPT_H
