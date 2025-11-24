#include "global.h"
#include "globaldata.h"
#include "ground_script.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/item.h"
#include "constants/monster.h"
#include "constants/move_id.h"
#include "direction_util.h"
#include "pixelpos_math.h"
#include "music_util.h"
#include "code_8099360.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "rescue_scenario.h"
#include "adventure_info.h"
#include "code_80A26CC.h"
#include "debug.h"
#include "dungeon_info.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "ground_link.h"
#include "ground_lives.h"
#include "ground_main.h"
#include "ground_map.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "input.h"
#include "items.h"
#include "main_loops.h"
#include "math.h"
#include "music.h"
#include "other_random.h"
#include "random.h"
#include "rescue_team_info.h"
#include "save.h"
#include "string_format.h"
#include "text_util.h"
#include "pokemon.h"
#include "wigglytuff_shop1.h"
#include "wonder_mail.h"
#include "palette_util.h"
#include "pokemon_3.h"
#include "memory.h"
#include "script_item.h"
#include "ground_lives_helper.h"
#include "friend_area_dialogue.h"
#include "structs/str_dungeon_setup.h"
#include "ground_map_conversion_table.h"
#include "unk_ds_only_feature.h"
#include "textbox.h"
#include "ground_event.h"
#include "ground_effect.h"
#include "ground_object.h"
#include "ground_weather.h"
#include "code_809D148.h"
#include "training_maze.h"
#include "dungeon_list_menu.h"

// Beware of the declarations without specified arguments, returning u32 or s32, these were quickly hacked in to get the code to compile and link
// The return values are almost certainly NOT correct and will need to be rechecked when moving to header files
bool8 sub_8099B94(void);
bool8 sub_80961D8(void);
void ResetMailbox(void);
void sub_80963FC(void);
void sub_8096488(void);
bool8 sub_80964B4(void);
u8 sub_80964E4();

// For gScriptLocks, gScriptLockConds, gUnlockBranchLabels
#define SCRIPT_LOCKS_ARR_COUNT 129

static EWRAM_DATA s16 gCurrentMap = 0;
static EWRAM_DATA s16 gUnknown_2039A32 = 0; // See enum "GroundMapID"
static EWRAM_DATA s16 gUnknown_2039A34 = 0; // See enum "GroundMapID"
static EWRAM_DATA u8 gAnyScriptLocked = 0;
// Hard to say why the arrays are larger than SCRIPT_LOCKS_ARR_COUNT. Could be unused EWRAM variables or special case indexes.
static ALIGNED(4) EWRAM_DATA u8 gScriptLocks[SCRIPT_LOCKS_ARR_COUNT + 7] = {0};
static ALIGNED(4) EWRAM_DATA u8 gScriptLockConds[SCRIPT_LOCKS_ARR_COUNT + 7] = {0};
static EWRAM_DATA u32 gUnlockBranchLabels[SCRIPT_LOCKS_ARR_COUNT + 1] = {0};
static EWRAM_DATA MenuItem gChoices[9] = {0};
static EWRAM_DATA char sPokeNameBuffer[POKEMON_NAME_LENGTH + 2] = {0};
static EWRAM_DATA u32 gUnknown_2039DA4 = 0;
static EWRAM_DATA u16 gUnknown_2039DA8 = 0;

static EWRAM_INIT int sNumChoices = 0;
static EWRAM_INIT u8 *gUnknown_203B4B0 = NULL;

static const CallbackData sNullCallbackData = {
    .maybeId = 4,
    .getIndex = NULL,
    .getSize = NULL,
    .getHitboxCenter = NULL,
    .getPosHeightAndUnk = NULL,
    .getDirection = NULL,
    .getFlags = NULL,
    .setHitboxPos = NULL,
    .setPositionBounds = NULL,
    .moveReal = NULL,
    .setPosHeight = NULL,
    .setDirection = NULL,
    .setEventIndex = NULL,
    .livesOnlyNullsub = NULL,
    .func38 = NULL,
    .setFlags = NULL,
    .clearFlags = NULL,
    .func44_livesOnlySpriteRelated = NULL,
    .moveRelative = NULL,
    .func4C_spriteRelatedCheck = NULL,
    .func50_spriteRelated = NULL,
};

static const PixelPos sPixelPosZero = {0, 0};

static const ScriptCommand gUnknown_81164E4[] = {
    {0xF6, 0, 0xC5, 0, 0, "../ground/ground_script.c"},
    {0xEF, 0, 0,    0, 0, NULL},
};

static s32 ExecuteScriptCommand(Action *action);
static s32 sub_80A14E8(Action *action, u8 idx, u32 r2, s32 r3);
static const ScriptCommand *FindLabel(Action *action, s32 labelNum);
static const ScriptCommand *ResolveJump(Action *action, s32 r1);
static void sub_80A2500(s32 param_1, ActionUnkIds *param_2);
static void sub_80A252C(s32 param_1, ActionUnkIds *param_2);
static void sub_80A2558(s32 param_1, ActionUnkIds *param_2);
static void sub_80A2584(s16 r0, s16 r1);
static void sub_80A2598(s16 r0, s16 r1);
static u32 sub_80A25AC(u16 param_1);

void sub_809D490(void)
{
    UNUSED void *oldPtr = gUnknown_203B4B0; // Needed to match
    gUnknown_203B4B0 = MemoryAlloc(0x400, 6);
    sub_809D4B0();
}

void sub_809D4B0(void)
{
    s32 i;

    gCurrentMap = -1;
    gUnknown_2039A32 = -1;
    gUnknown_2039A34 = -1;
    gAnyScriptLocked = 0;
    for (i = 0; i < SCRIPT_LOCKS_ARR_COUNT; i++) {
        gScriptLocks[i] = 0;
        gScriptLockConds[i] = 0;
        gUnlockBranchLabels[i] = 0;
    }
}

void sub_809D508(void)
{
    FREE_AND_SET_NULL(gUnknown_203B4B0);
}

static void sub_809D520(ActionUnkIds *a0)
{
    a0->unk0 = -1;
}

static Action *sub_809D52C(ActionUnkIds *a0)
{
    switch (a0->unk0) {
        case 0: return 0;
        case 1: return sub_80A882C(a0->unk2);
        case 2: return GroundObject_GetAction(a0->unk2);
        case 3: return sub_80AD158(a0->unk2);
    }
    return NULL;
}

static void InitScriptData(ScriptData *a0)
{
    s32 i;

    a0->state = -1;
    a0->savedState = 0;
    a0->script.ptr2 = 0;
    a0->script.ptr = 0;
    a0->savedScript.ptr2 = 0;
    a0->savedScript.ptr = 0;
    a0->curScriptOp = CMD_BYTE_00;
    a0->curPtr = 0;
    a0->unk22 = -1;
    a0->unk24 = 0;
    a0->unk26 = 0xFF;
    a0->branchDiscriminant = 0;
    a0->unk2A = 0;
    a0->unk2C = 0;
    a0->unk30 = 0;
    for (i = 0; i < 4; i++) {
        a0->localVars.val[i] = 0;
    }
}

static void InitAction(Action *a0)
{
    s32 i;

    a0->callbacks = NULL;
    a0->parentObject = NULL;
    a0->group = -1;
    a0->sector = 0xFF;
    sub_809D520(&a0->unkC);

    for (i = 0; i < 4; i++) {
        a0->predefinedScripts[i] = NULL;
    }

    InitScriptData(&a0->scriptData);
    InitScriptData(&a0->scriptData2);
}

void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s32 group, s32 sector)
{
    s32 group_s32 = (s16) group;
    s32 sector_s32 = (s8) sector;

    InitAction(action);

    action->callbacks = callbacks;
    action->parentObject = parent;
    action->group = group_s32;
    action->sector = sector_s32;
    action->unk8.unk0 = callbacks->maybeId;

    if (callbacks->getIndex)
        action->unk8.unk2 = callbacks->getIndex(parent);
    else
        action->unk8.unk2 = 0;
}

void InitAction2(Action *action)
{
    InitAction(action);
}

UNUSED static s16 sub_809D654(Action *action)
{
    return action->scriptData.savedState;
}

UNUSED static s16 sub_809D65C(Action *action)
{
    if(action->scriptData.savedState != 0)
        return action->scriptData.state;
    else
        return -1;
}

bool8 sub_809D678(Action *action)
{
    return action->scriptData.savedState == 0 ? FALSE : TRUE;
}

bool8 sub_809D684(Action *action, ScriptInfoSmall *scriptInfo)
{
    if(action->scriptData.savedState != 0)
    {
        if(action->scriptData.savedScript.ptr != 0)
        {
            if(action->scriptData.savedScript.ptr2 == scriptInfo->ptr) return 1;
        }
        else
        {
            if(action->scriptData.script.ptr2 == scriptInfo->ptr) return 1;
        }
    }
    if(action->scriptData2.savedState != 0)
    {
        if(action->scriptData2.savedScript.ptr != 0)
        {
            if(action->scriptData2.savedScript.ptr2 == scriptInfo->ptr) return 1;
        }
        else
        {
            if(action->scriptData2.script.ptr2 == scriptInfo->ptr) return 1;
        }
    }
    return 0;
}

void SetPredefinedScript(Action *param_1, s16 index, const ScriptCommand *param_3)
{
    param_1->predefinedScripts[index] = param_3;
}

bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s32 _index)
{
    const ScriptCommand *scriptPtr;
    s32 index = (s16) _index;

    scriptPtr = param_1->predefinedScripts[index];
    script->ptr = scriptPtr;
    script->state = index;
    script->group = param_1->group;
    script->sector = param_1->sector;
    return scriptPtr != NULL;
}

void GetFunctionScript(Action *param_1, ScriptInfoSmall *script, s16 scriptID)
{
    s32 index_s32 = scriptID;
    script->ptr = gFunctionScriptTable[index_s32].script;
    script->state = 2;
    if (param_1 != NULL) {
        script->group = param_1->group;
        script->sector = param_1->sector;
    }
    else {
        script->group = -1;
        script->sector = -1;
    }
}

bool8 ActionResetScriptData(Action *param_1, const DebugLocation *unused)
{
    InitScriptData(&param_1->scriptData);
    InitScriptData(&param_1->scriptData2);
    return TRUE;
}

static bool8 ActionResetScriptDataForDeletion(Action *param_1, const DebugLocation *unused)
{
    InitScriptData(&param_1->scriptData);
    InitScriptData(&param_1->scriptData2);
    param_1->scriptData.savedState = 4;
    return TRUE;
}

bool8 GroundScript_ExecutePP(Action *action, ActionUnkIds *param_2, ScriptInfoSmall *param_3, const DebugLocation *unused)
{
    if ((param_3 == NULL) || (param_3->ptr == NULL)) {
        return FALSE;
    }
    switch(param_3->state) {
        case 2:
        case 3:
            if (action->scriptData.state == 1) {
                action->scriptData2 = action->scriptData;
                break;
            }
            if (action->scriptData.state == 5) {
                InitScriptData(&action->scriptData2);
            }
            break;
        case 5:
            if (action->scriptData.state != 2) {
                FATAL_ERROR_ARGS("../ground/ground_script.c", 688, "execute script type error B");
            }
            if (action->scriptData2.state != -1) {
                FATAL_ERROR_ARGS("../ground/ground_script.c", 689, "execute script type error C");
            }
            action->scriptData2 = action->scriptData;
            break;
        case 0:
            if (action->scriptData.state != 1) {
                InitScriptData(&action->scriptData2);
            }
            else {
                action->scriptData2 = action->scriptData;
            }
            break;
        case 1:
            InitScriptData(&action->scriptData2);
            break;
        default:
            FATAL_ERROR_ARGS("../ground/ground_script.c", 708, "execute script type error %d", param_3->state);
    }
    InitScriptData(&action->scriptData);
    if (param_2 != NULL) {
        action->unkC = *param_2;
    }
    else {
        sub_809D520(&action->unkC);
    }
    action->scriptData.state = param_3->state;
    action->scriptData.savedState = 3;
    action->scriptData.script.group = param_3->group;
    action->scriptData.script.sector = param_3->sector;
    action->scriptData.script.ptr = param_3->ptr;
    action->scriptData.script.ptr2 = param_3->ptr;
    action->scriptData.savedScript.ptr = 0;
    action->scriptData.savedScript.ptr2 = NULL;

    if (action->callbacks->getDirection != 0) {
        action->callbacks->getDirection(action->parentObject, &action->scriptData.unk26);
    }
    return TRUE;
}

bool8 ExecutePredefinedScript(Action *param_1, ActionUnkIds *param_2, s16 index, const DebugLocation *debug)
{
    ScriptInfoSmall auStack28;

    GetPredefinedScript(param_1,&auStack28,index);
    return GroundScript_ExecutePP(param_1, param_2, &auStack28, debug);
}

static bool8 GroundScriptCheckLockCondition(Action *param_1, s16 param_2)
{
    s32 param_2_s32;

    param_2_s32 = param_2;

    if ((param_2 == 0) && (IsTextboxOpen_809A750() == 0)) {
        param_1->scriptData.script.ptr = ResolveJump(param_1, 0);
        return FALSE;
    }
    else {
        param_1->scriptData.unk22 = param_2_s32;
        param_1->scriptData.savedState = 2;
        gAnyScriptLocked = 1;
        return TRUE;
    }
}

bool8 GroundScript_Cancel(Action *r0)
{
    // NOTE: Will always return TRUE
    return ActionResetScriptDataForDeletion(r0, DEBUG_LOC_PTR("../ground/ground_script.c", 821, "GroundScript_Cancel"));
}

static u8 GroundCancelAllEntities(void)
{
    u8 ret;

    ret = GroundLivesCancelAll();
    ret |= GroundObjectsCancelAll();
    ret |= GroundEffectsCancelAll();
    return ret;
}

bool8 GroundScriptNotify(Action *param_1, s32 param_2)
{
    s16 sVar1;
    s16 sVar2;
    bool8 ret;

    s32 param_2_s16 = (s16) param_2;

    ret = FALSE;
    sVar1 = param_1->scriptData.unk22;
    if ((sVar1 != -1) && (sVar1 == param_2_s16)) {
        param_1->scriptData.unk22 = -1;
        ret = TRUE;
    }
    sVar2 = param_1->scriptData2.unk22;
    if ((sVar2 != -1) && (sVar2 == param_2_s16)) {
        param_1->scriptData2.unk22 = -1;
        ret = TRUE;
    }
    return ret;
}

void GroundScriptLockJumpZero(s16 index)
{
    s32 index_s16 = index;
    gScriptLocks[index_s16] = 1;
    gUnlockBranchLabels[index_s16] = 0;
    gAnyScriptLocked = 1;
}

void GroundScriptLock(s16 index, s32 r1)
{
    s32 index_s16 = index;
    gScriptLocks[index_s16] = 1;
    gUnlockBranchLabels[index_s16] = r1;
    gAnyScriptLocked = 1;
}

static bool8 GroundScriptLockCond(Action *param_1, s16 index, s32 param_3)
{
    s32 index_s32 = index;
    gUnlockBranchLabels[index_s32] = param_3;
    if (index_s32 == 0) {
        if (IsTextboxOpen_809A750() == 0) {
            return FALSE;
        }
        param_1->scriptData.unk22 = index_s32;
    }
    else {
        param_1->scriptData.unk22 = index_s32 | 0x80;
        gScriptLocks[index_s32] = 1;
        gScriptLockConds[index_s32] = 1;
    }
    param_1->scriptData.savedState = 2;
    gAnyScriptLocked = 1;
    return TRUE;
}

s16 HandleAction(Action *action, const DebugLocation *debug)
{
    ScriptCommand cmd;

    if (action->scriptData.savedState) {
        bool8 loopContinue = TRUE;
        while (loopContinue) {
            switch (action->scriptData.savedState) {
                case 2: {
                    switch (action->scriptData.curScriptOp) {
                        // handled cases (all hex)
                        // 03, 04, 05, 06, 07, 22..28, 2c, 30..38, 39, 3a, 3b, 3c, 3d, 3e, 3f,
                        // 58..5b, 5d, 5e, 60, 61..67, 68, 69..6f, 70, 71..76, 77..7c, 7d..82, 83..88,
                        // 89, 8a, 8b..90, 91..95, 98, 99, 9b..a3, cf, d2..d8, da, db, dc, dd, de, df,
                        // e0, e1, e2, e3, e5
                        // other cases up to 0xf1 immediately break (which breaks again and loops for ExScrCmd)
                        case CMD_BYTE_58:
                        case CMD_BYTE_59:
                        case CMD_BYTE_5A:
                        case CMD_BYTE_5B:
                        case CMD_BYTE_5D:
                        case CMD_BYTE_5E:
                        case CMD_BYTE_60:
                        case CMD_BYTE_8B:
                        case CMD_BYTE_8C:
                        case CMD_BYTE_8D:
                        case CMD_BYTE_8E:
                        case CMD_BYTE_8F:
                        case CMD_BYTE_90:
                        case CMD_BYTE_98:
                        case CMD_BYTE_99:
                        case CMD_BYTE_DB:
                        case CMD_BYTE_DC: {
                            if (action->scriptData.unk2A > 0) {
                                action->scriptData.unk2A--;
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case CMD_BYTE_DD: {
                            if (action->callbacks->func4C_spriteRelatedCheck(action->parentObject))
                                loopContinue = FALSE;
                            else
                                action->scriptData.savedState = 3;

                            break;
                        }
                        case CMD_BYTE_DE: {
                            if (action->callbacks->func50_spriteRelated(action->parentObject))
                                loopContinue = FALSE;
                            else
                                action->scriptData.savedState = 3;

                            break;
                        }
                        case CMD_BYTE_22:
                        case CMD_BYTE_23:
                        case CMD_BYTE_24:
                        case CMD_BYTE_25:
                        case CMD_BYTE_26:
                        case CMD_BYTE_27:
                        case CMD_BYTE_28:
                        case CMD_BYTE_DF: {
                            if (sub_8099B94())
                                loopContinue = FALSE;
                            else
                                action->scriptData.savedState = 3;

                            break;
                        }
                        case CMD_BYTE_E0: {
                            cmd = *action->scriptData.curPtr;
                            if (IsEqualtoBGTrack(cmd.argShort)) {
                                if (action->scriptData.unk2C++ < 10800)
                                    loopContinue = FALSE;
                                else
                                    action->scriptData.savedState = 3;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case CMD_BYTE_E1: // WAIT_FANFARE1
                        case CMD_BYTE_E2: { // WAIT_FANFARE2
                            cmd = *action->scriptData.curPtr;
                            if (IsSoundPlaying(cmd.argShort)) {
                                if (action->scriptData.unk2C++ < 3600)
                                    loopContinue = FALSE;
                                else
                                    action->scriptData.savedState = 3;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case CMD_BYTE_61:
                        case CMD_BYTE_62:
                        case CMD_BYTE_63:
                        case CMD_BYTE_64:
                        case CMD_BYTE_65:
                        case CMD_BYTE_66:
                        case CMD_BYTE_67: {
                            PixelPos pos, pos2;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos);
                            pos2.x = action->scriptData.pos2.x - pos.x;
                            pos2.y = action->scriptData.pos2.y - pos.y;
                            ClampPixelPos(&pos2, action->scriptData.unk30);

                            if (pos2.x == 0 && pos2.y == 0) {
                                action->scriptData.savedState = 3;
                                break;
                            }

                            if (action->callbacks->moveRelative(action->parentObject, &pos2) & 9) {
                                action->scriptData.savedState = 3;
                                break;
                            }

                            action->callbacks->setEventIndex(action->parentObject, 0x1000);

                            if (action->scriptData.unk2A >= 0) {
                                if (action->scriptData.unk2A > 0) {
                                    action->scriptData.unk2A--;
                                    loopContinue = FALSE;
                                }
                                else {
                                    action->scriptData.savedState = 3;
                                }
                            }
                            else {
                                loopContinue = FALSE;
                            }
                            break;
                        }
                        case CMD_BYTE_69:
                        case CMD_BYTE_6A:
                        case CMD_BYTE_6B:
                        case CMD_BYTE_6C:
                        case CMD_BYTE_6D:
                        case CMD_BYTE_6E:
                        case CMD_BYTE_6F: {
                            PixelPos pos, pos2;
                            s32 res;
                            s32 dir;
                            UNUSED s32 dirBefore;
                            s8 dirS8;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos);
                            pos2.x = action->scriptData.pos2.x - pos.x;
                            pos2.y = action->scriptData.pos2.y - pos.y;
                            ClampPixelPos(&pos2, action->scriptData.unk30);
                            if (pos2.x == 0 && pos2.y == 0) {
                                action->scriptData.savedState = 3;
                                break;
                            }
                            res = action->callbacks->moveRelative(action->parentObject, &pos2);
                            dir = (s8) VecDirection8Radial(&pos2);
                            dirBefore = action->scriptData.unk26;
                            dirS8 = dir;
                            action->scriptData.unk26 = dirS8;
                            action->callbacks->setDirection(action->parentObject, dir);
                            if (res & 9) {
                                action->scriptData.savedState = 3;
                                break;
                            }
                            action->callbacks->setEventIndex(action->parentObject, 0x1000);

                            if (action->scriptData.unk2A >= 0) {
                                if (action->scriptData.unk2A > 0) {
                                    action->scriptData.unk2A--;
                                    loopContinue = FALSE;
                                }
                                else {
                                    action->scriptData.savedState = 3;
                                }
                            }
                            else {
                                loopContinue = FALSE;
                            }
                            break;
                        }
                        case CMD_BYTE_71:
                        case CMD_BYTE_72:
                        case CMD_BYTE_73:
                        case CMD_BYTE_74:
                        case CMD_BYTE_75:
                        case CMD_BYTE_76:
                        case CMD_BYTE_7D:
                        case CMD_BYTE_7E:
                        case CMD_BYTE_7F:
                        case CMD_BYTE_80:
                        case CMD_BYTE_81:
                        case CMD_BYTE_82: {
                            if (action->scriptData.unk2A > 0) {
                                PixelPos pos;
                                InterpolatePixelPos(&pos, &action->scriptData.pos1, &action->scriptData.pos2, action->scriptData.unk2A, action->scriptData.unk2C);
                                action->callbacks->moveReal(action->parentObject, &pos);
                                action->callbacks->setEventIndex(action->parentObject, 0x1000);
                                action->scriptData.unk2A--;
                                action->scriptData.unk2C++;
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case CMD_BYTE_77:
                        case CMD_BYTE_78:
                        case CMD_BYTE_79:
                        case CMD_BYTE_7A:
                        case CMD_BYTE_7B:
                        case CMD_BYTE_7C:
                        case CMD_BYTE_83:
                        case CMD_BYTE_84:
                        case CMD_BYTE_85:
                        case CMD_BYTE_86:
                        case CMD_BYTE_87:
                        case CMD_BYTE_88: {
                            if (action->scriptData.unk2A > 0) {
                                PixelPos pos1, pos2, pos3;
                                s32 dir;
                                UNUSED s32 dirBefore;
                                s8 dirS8;

                                action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                                InterpolatePixelPos(&pos2, &action->scriptData.pos1, &action->scriptData.pos2, action->scriptData.unk2A, action->scriptData.unk2C);
                                pos3.x = pos2.x - pos1.x;
                                pos3.y = pos2.y - pos1.y;
                                dir = (s8) VecDirection8Radial(&pos3);
                                dirBefore = action->scriptData.unk26;
                                dirS8 = dir;
                                action->scriptData.unk26 = dirS8;
                                action->callbacks->setDirection(action->parentObject, dir);
                                action->callbacks->moveReal(action->parentObject, &pos2);
                                action->callbacks->setEventIndex(action->parentObject, 0x1000);
                                action->scriptData.unk2A--;
                                action->scriptData.unk2C++;
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case CMD_BYTE_68:
                        case CMD_BYTE_70: {
                            s32 height, unk;
                            s32 delta;
                            action->callbacks->getPosHeightAndUnk(action->parentObject, &height, &unk);
                            delta = action->scriptData.unk48 - height;
                            if (delta == 0) {
                                action->scriptData.savedState = 3;
                                break;
                            }
                            // oh wow, cmn instruction
                            height += (delta < -action->scriptData.unk30) ? -action->scriptData.unk30 :
                                      (delta > action->scriptData.unk30) ? action->scriptData.unk30 : delta;
                            action->callbacks->setPosHeight(action->parentObject, height);
                            loopContinue = FALSE;
                            break;
                        }
                        case CMD_BYTE_89:
                        case CMD_BYTE_8A: {
                            PixelPos pos;
                            s8 dir;
                            action->callbacks->getDirection(action->parentObject, &dir);
                            pos = SetVecFromDirectionSpeed(dir, action->scriptData.unk30);

                            if (action->callbacks->moveRelative(action->parentObject, &pos) & 9) {
                                action->scriptData.savedState = 3;
                                break;
                            }
                            action->callbacks->setEventIndex(action->parentObject, 0x1000);

                            if (action->scriptData.unk2A > 0) {
                                action->scriptData.unk2A--;
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case CMD_BYTE_91: // ROTATE_TO
                        case CMD_BYTE_92: // CMD_UNK_92
                        case CMD_BYTE_93: // CMD_UNK_93
                        case CMD_BYTE_94: // CMD_UNK_94
                        case CMD_BYTE_95: { // CMD_UNK_95
                            if (action->scriptData.unk2A > 0) {
                                action->scriptData.unk2A--;
                                loopContinue = FALSE;
                            }
                            else {
                                PixelPos pos1, pos2, pos3, pos4;
                                UNUSED s32 tmp1;
                                s32 tmp2;
                                s8 dir;
                                bool8 flag;
                                cmd = *action->scriptData.curPtr;
                                tmp1 = -1;
                                tmp2 = -1;
                                flag = FALSE;
                                action->callbacks->getDirection(action->parentObject, &dir);
                                // arg1h synthetic
                                switch (cmd.op) {
                                    case CMD_BYTE_91: // ROTATE_TO
                                    case CMD_BYTE_92: { // CMD_UNK_92
                                        tmp2 = (s8) action->scriptData.unk4D;
                                        break;
                                    }
                                    case CMD_BYTE_93: { // CMD_UNK_93
                                        s16 res;
                                        res = sub_80A7AE8((s16)cmd.arg1);
                                        if (res >= 0) {
                                            flag = TRUE;
                                            sub_80A8FD8(res, &pos1);
                                            sub_80A8F9C(res, &pos2);
                                        }
                                        break;
                                    }
                                    case CMD_BYTE_94: { // CMD_UNK_94
                                        s32 res;
                                        res = (s16)sub_80A7AE8((s16)cmd.arg1);
                                        if (res >= 0) {
                                            flag = TRUE;
                                            sub_80A8FD8(res, &pos1);
                                            pos2 = sPixelPosZero;
                                        }
                                        break;
                                    }
                                    case CMD_BYTE_95: { // CMD_UNK_95
                                        flag = TRUE;
                                        action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                                        action->callbacks->getSize(action->parentObject, &pos2);
                                        GroundLink_GetPos((s16)cmd.arg1, &pos1);
                                        break;
                                    }
                                }
                                if (flag) {
                                    action->callbacks->getHitboxCenter(action->parentObject, &pos3);
                                    action->callbacks->getSize(action->parentObject, &pos4);
                                    tmp2 = SizedDeltaDirection8(&pos3, &pos4, &pos1, &pos2);
                                    if (tmp2 == -1) {
                                        tmp2 = SizedDeltaDirection4(&pos3, &sPixelPosZero, &pos1, &sPixelPosZero);
                                    }
                                }
                                if (tmp2 == -1 || tmp2 == dir) {
                                    action->scriptData.savedState = 3;
                                    break;
                                }

                                ASM_MATCH_TRICK(dir);
                                action->scriptData.unk26 = TransformDirection2(dir, tmp2, (u8)cmd.argShort);
                                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                                action->scriptData.unk2A = cmd.argByte;
                            }
                            break;
                        }
                        case CMD_BYTE_9B:
                        case CMD_BYTE_9C:
                        case CMD_BYTE_9D:
                        case CMD_BYTE_9E:
                        case CMD_BYTE_9F:
                        case CMD_BYTE_A0:
                        case CMD_BYTE_A1:
                        case CMD_BYTE_A2:
                        case CMD_BYTE_A3: {
                            if (sub_809D234())
                                loopContinue = FALSE;
                            else
                                action->scriptData.savedState = 3;

                            break;
                        }
                        case CMD_BYTE_E3:
                        case CMD_BYTE_E5: { // CMD_UNK_E5
                            if (action->scriptData.unk22 != -1) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.script.ptr = ResolveJump(action, gUnlockBranchLabels[action->scriptData.branchDiscriminant]);
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case CMD_BYTE_2C:
                        case CMD_BYTE_30:
                        case CMD_BYTE_31:
                        case CMD_BYTE_32:
                        case CMD_BYTE_33:
                        case CMD_BYTE_34:
                        case CMD_BYTE_35:
                        case CMD_BYTE_36:
                        case CMD_BYTE_37:
                        case CMD_BYTE_38: {
                            if (action->scriptData.unk22 != -1) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                                sub_80A87AC(0, 0);
                            }
                            break;
                        }
                        case CMD_BYTE_39: {
                            if (action->scriptData.unk22 != -1) {
                                loopContinue = FALSE;
                            }
                            else if (sub_8099B94()) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                                sub_80A87AC(0, 0);
                            }
                            break;
                        }
                        case CMD_BYTE_3B: {
                            s32 tmp;
                            cmd = *action->scriptData.curPtr;
                            tmp = sub_80A14E8(action, cmd.argByte, cmd.argShort, cmd.arg1);
                            if (tmp < 0) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                                action->scriptData.script.ptr = ResolveJump(action, tmp);
                            }
                            break;
                        }
                        case CMD_BYTE_3C: {
                            s32 val;
                            if (!sub_809B260(&val)) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.script.ptr = ResolveJump(action, val);
                                action->scriptData.savedState = 3;
                                sub_80A87AC(0, 0);
                            }
                            break;
                        }
                        case CMD_BYTE_03: {
                            s32 val;
                            if (!sub_809B260(&val)) {
                                loopContinue = FALSE;
                                break;
                            }
                            if (val >= 0) {
                                cmd = *action->scriptData.curPtr;
                                GroundMainGroundRequest((s16)FriendAreaIdToMapId((u8)val), 0, cmd.argShort);
                            }
                            action->scriptData.script.ptr = ResolveJump(action, val);
                            action->scriptData.savedState = 3;
                            sub_80A87AC(0, 0);
                            break;
                        }
                        case CMD_BYTE_04: {
                            if (action->scriptData.branchDiscriminant == 0) {
                                s32 val;
                                if (!sub_809B260(&val)) {
                                    loopContinue = FALSE;
                                    break;
                                }
                                if (val >= 0) {
                                    SetScriptVarValue(NULL, 18, RescueDungeonToScriptDungeonId(val));
                                    action->scriptData.branchDiscriminant = 1;
                                } else {
                                    action->scriptData.branchDiscriminant = -1;
                                }
                                sub_80A87AC(0, 0);
                                break;
                            }
                            if (action->scriptData.branchDiscriminant == 1) {
                                s32 dungeonSelect;
                                s32 dungeonEnterElt;
                                cmd = *action->scriptData.curPtr;
                                dungeonSelect = (s16) GetScriptVarValue(NULL, 18);
                                dungeonEnterElt = GetScriptVarArrayValue(NULL, 48, (u16) dungeonSelect);
                                if (dungeonSelect != 19 || dungeonEnterElt != 0) {
                                    sub_8098DCC(cmd.argShort);
                                    action->scriptData.script.ptr = ResolveJump(action, 0);
                                    sub_80A87AC(0, 0);
                                    action->scriptData.savedState = 3;
                                    break;
                                }
                                SetScriptVarValue(NULL, 19, 19);
                            }
                            // fallthrough
                        }
                        case CMD_BYTE_06: {
                            if (action->scriptData.branchDiscriminant == 0) {
                                s32 val;
                                s16 disc;
                                if (!sub_809B260(&val)) {
                                    loopContinue = FALSE;
                                    break;
                                }
                                if (val >= 0) {
                                    SetScriptVarValue(NULL, 19, action->scriptData.curScriptOp == CMD_BYTE_04 ? RescueDungeonToScriptDungeonId(val) : (s16)val);
                                    disc = 1;
                                } else {
                                    disc = -1;
                                }
                                action->scriptData.branchDiscriminant = disc;
                                sub_80A87AC(0, 0);
                                break;
                            }
                            // fallthrough
                        }
                        case CMD_BYTE_07: {
                            if (action->scriptData.branchDiscriminant == 1) {
                                s32 dungeonEnter;
                                u32 res;
                                struct DungeonSetupInfo unkStruct;
                                dungeonEnter = (s16)GetScriptVarValue(NULL, 19);
                                if (sub_80990EC(&unkStruct, dungeonEnter)) {
                                    s32 val;
                                    sub_8099220(&unkStruct, dungeonEnter);
                                    val = CheckQuest(QUEST_REACHED_POSTGAME);
                                    res = BufferDungeonRequirementsText(unkStruct.sub0.unk0.id, 0, gUnknown_203B4B0, val, FALSE);
                                    gUnknown_2039DA4 = res;
                                    switch (res) {
                                        case 2: {
                                            action->scriptData.branchDiscriminant = 2;
                                            ScriptSpecialTextHandler2(SPECIAL_TEXT_YES_NO_WITH_LARGE_BOX, 1, STR_TO_MONORSTRPTR(gUnknown_203B4B0));
                                            if (GroundScriptCheckLockCondition(action, 1)) {
                                                sub_80A87AC(0, 11);
                                            }
                                            break;
                                        }
                                        case 0: {
                                            action->scriptData.branchDiscriminant = 3;
                                            break;
                                        }
                                        case 1: {
                                            action->scriptData.branchDiscriminant = 4;
                                            ScriptSpecialTextHandler2(SPECIAL_TEXT_LARGE_TEXT_BOX, 1, STR_TO_MONORSTRPTR(gUnknown_203B4B0));
                                            if (GroundScriptCheckLockCondition(action, 1)) {
                                                sub_80A87AC(0, 11);
                                            }
                                            break;
                                        }
                                        default: {
                                            action->scriptData.branchDiscriminant = -1;
                                            break;
                                        }
                                    }
                                    break;
                                }
                                else {
                                    action->scriptData.branchDiscriminant = 3;
                                    break;
                                }
                            }
                        case CMD_BYTE_05:
                            if (action->scriptData.branchDiscriminant == 1) {
                                unkStruct_203B480 *ret;
                                s32 val;
                                u32 res;
                                ret = GetMailatIndex(GetScriptVarValue(NULL, 20));
                                val = CheckQuest(QUEST_REACHED_POSTGAME);
                                res = BufferDungeonRequirementsText(ret->dungeonSeed.location.id, 0, gUnknown_203B4B0, val, TRUE);
                                gUnknown_2039DA4 = res;
                                switch (res) {
                                    case 2: {
                                        action->scriptData.branchDiscriminant = 2;
                                        ScriptSpecialTextHandler2(SPECIAL_TEXT_YES_NO_WITH_LARGE_BOX, 1, STR_TO_MONORSTRPTR(gUnknown_203B4B0));
                                        if (GroundScriptCheckLockCondition(action, 1)) {
                                            sub_80A87AC(0, 11);
                                        }
                                        break;
                                    }
                                    case 0: {
                                        action->scriptData.branchDiscriminant = 3;
                                        break;
                                    }
                                    case 1: {
                                        action->scriptData.branchDiscriminant = 4;
                                        ScriptSpecialTextHandler2(SPECIAL_TEXT_LARGE_TEXT_BOX, 1, STR_TO_MONORSTRPTR(gUnknown_203B4B0));
                                        if (GroundScriptCheckLockCondition(action, 1)) {
                                            sub_80A87AC(0, 11);
                                        }
                                        break;
                                    }
                                    default: {
                                        action->scriptData.branchDiscriminant = -1;
                                        break;
                                    }
                                }
                                break;
                            }
                            if (action->scriptData.branchDiscriminant == 2) {
                                u32 val;
                                if (!sub_809B260(&val)) {
                                    loopContinue = FALSE;
                                    break;
                                }

                                if (val != 0) {
                                    action->scriptData.branchDiscriminant = 3;
                                    sub_80A87AC(0, 0);
                                    ScriptClearTextbox();
                                    break;
                                }
                                else {
                                    action->scriptData.branchDiscriminant = -1;
                                    sub_80A87AC(0, 0);
                                    ScriptClearTextbox();
                                    break;
                                }
                            }
                            if (action->scriptData.branchDiscriminant == 3) {
                                cmd = *action->scriptData.curPtr;
                                action->scriptData.savedState = 3;
                                sub_80999FC(cmd.argShort);
                                GroundMap_ExecuteEvent(EVENT_RESCUE, FALSE);
                                if (action->unk8.unk0 == 0) continue;
                                action->scriptData.script.ptr = ResolveJump(action, 1);
                                break;
                            }
                            if (action->scriptData.branchDiscriminant == 4) {
                                u32 val;
                                if (!sub_809B260(&val)) {
                                    loopContinue = FALSE;
                                    break;
                                }
                                action->scriptData.branchDiscriminant = -1;
                                sub_80A87AC(0, 0);
                                ScriptClearTextbox();
                                break;
                            }

                            sub_8099220(0, 0);
                            SetScriptVarValue(NULL, 19, -1);
                            action->scriptData.script.ptr = ResolveJump(action, -1);
                            action->scriptData.savedState = 3;
                            break;
                        }
                        case CMD_BYTE_3D: {
                            s32 val;
                            cmd = *action->scriptData.curPtr;
                            if (!sub_809B260(&val)) {
                                loopContinue = FALSE;
                                break;
                            }
                            if (val == 1) {
                                s32 id = (s16)cmd.arg1;
                                if (id != -1) {
                                    Pokemon *mon = sub_80A8D54((s16) id);
                                    s32 i;
                                    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
                                        mon->name[i] = sPokeNameBuffer[i];
                                    }
                                }
                            }
                            action->scriptData.script.ptr = ResolveJump(action, val);
                            action->scriptData.savedState = 3;
                            sub_80A87AC(0, 0);
                            break;
                        }
                        case CMD_BYTE_3E: {
                            s32 val;
                            if (!sub_809B260(&val)) {
                                loopContinue = FALSE;
                                break;
                            }
                            if (val == 1) {
                                SetRescueTeamName(sPokeNameBuffer);
                            }
                            action->scriptData.script.ptr = ResolveJump(action, val);
                            action->scriptData.savedState = 3;
                            sub_80A87AC(0, 0);
                            break;
                        }
                        case CMD_BYTE_3F: {
                            s32 val;
                            const u8 *ptr;
                            cmd = *action->scriptData.curPtr;
                            ptr = cmd.argPtr;
                            if (sub_809B260(&val)) {
                                if (val == 1) {
                                    s32 i;
                                    u8 name[16];
                                    for (i = 0; i < 16; i++) {
                                        name[i] = '\0';
                                    }

                                    CopyStringtoBuffer(sPokeNameBuffer, name);
                                    for (i = 0; i < 16; i++) {
                                        if (name[i] != ptr[i]) {
                                            val = 2;
                                            break;
                                        }
                                        if (name[i] == '\0')
                                            break;
                                    }
                                }
                                action->scriptData.script.ptr = ResolveJump(action, val);
                                action->scriptData.savedState = 3;
                                sub_80A87AC(0, 0);
                            }
                            else {
                                loopContinue = FALSE;
                            }
                            break;
                        }
                        case CMD_BYTE_3A: {
                            if (action->scriptData.unk2C == 0) {
                                if (action->scriptData.unk22 != -1) {
                                    loopContinue = FALSE;
                                }
                                else {
                                    action->scriptData.unk2C++;
                                }
                            }
                            else {
                                bool8 c;
                                if (sub_809AFFC(&c)) {
                                    if (c) {
                                        cmd = *action->scriptData.curPtr;
                                        action->scriptData.script.ptr = FindLabel(action, cmd.argShort);
                                    }
                                    action->scriptData.savedState = 3;
                                    sub_80A87AC(0, 0);
                                }
                                else {
                                    loopContinue = FALSE;
                                }
                            }
                            break;
                        }
                        case CMD_BYTE_CF: {
                            cmd = *action->scriptData.curPtr;
                            if (action->scriptData.unk2C == 0) {
                                bool8 flag = FALSE;
                                if (action->scriptData.branchDiscriminant < 0) {
                                    if (action->scriptData.script.ptr->op != CMD_BYTE_D1) {
                                        action->scriptData.savedState = 3;
                                        break;
                                    }
                                }
                                else {
                                    while (action->scriptData.script.ptr->op == CMD_BYTE_D0) {
                                        if (action->scriptData.script.ptr->argShort == action->scriptData.branchDiscriminant) {
                                            flag = TRUE;
                                            break;
                                        }
                                        action->scriptData.script.ptr++;
                                    }
                                    if (!flag) {
                                        while (action->scriptData.script.ptr->op == CMD_BYTE_D1) {
                                            action->scriptData.script.ptr++;
                                        }
                                        action->scriptData.savedState = 3;
                                        break;
                                    }
                                }
                                if (ScriptPrintText(cmd.argByte, (s16)cmd.arg1, action->scriptData.script.ptr->argPtr)) {
                                    sub_80A87AC(0, 10);
                                    if (GroundScriptCheckLockCondition(action, 0)) {
                                        action->scriptData.unk2C = 1;
                                    }
                                }
                                action->scriptData.script.ptr++;
                            }
                            else {
                                if (action->scriptData.unk22 != -1) {
                                    loopContinue = FALSE;
                                }
                                else {
                                    action->scriptData.unk2C = 0;
                                    sub_80A87AC(0, 0);
                                }
                            }
                            break;
                        }
                        case CMD_BYTE_D2:
                        case CMD_BYTE_D3:
                        case CMD_BYTE_D4:
                        case CMD_BYTE_D5:
                        case CMD_BYTE_D6:
                        case CMD_BYTE_D7:
                        case CMD_BYTE_D8: {
                            s32 tmp;
                            if (action->scriptData.unk2C == 0) {
                                if (action->scriptData.unk22 != -1) {
                                    loopContinue = FALSE;
                                }
                                else {
                                    action->scriptData.unk2C++;
                                }
                            }
                            else if (sub_809B18C(&tmp)) {
                                if (tmp > 0) {
                                    cmd = *(action->scriptData.curPtr + action->scriptData.branchDiscriminant + tmp);
                                    action->scriptData.script.ptr = FindLabel(action, cmd.argShort);
                                }
                                action->scriptData.savedState = 3;
                                sub_80A87AC(0, 0);
                            }
                            else {
                                loopContinue = FALSE;
                            }
                            break;
                        }
                        case CMD_BYTE_DA: {
                            if (action->scriptData.unk22 != -1) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.script.ptr = ResolveJump(action, gUnlockBranchLabels[1]);
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        default:
                        case CMD_BYTE_08:
                        case CMD_BYTE_09:
                        case CMD_BYTE_0A:
                        case CMD_BYTE_0B:
                        case CMD_BYTE_0C:
                        case CMD_BYTE_0D:
                        case CMD_BYTE_0E:
                        case CMD_BYTE_0F:
                        case CMD_BYTE_10:
                        case CMD_BYTE_11:
                        case CMD_BYTE_12:
                        case CMD_BYTE_13:
                        case CMD_BYTE_14:
                        case CMD_BYTE_15:
                        case CMD_BYTE_16:
                        case CMD_BYTE_17:
                        case CMD_BYTE_18:
                        case CMD_BYTE_19:
                        case CMD_BYTE_1A:
                        case CMD_BYTE_1B:
                        case CMD_BYTE_1C:
                        case CMD_BYTE_1D:
                        case CMD_BYTE_1E:
                        case CMD_BYTE_1F:
                        case CMD_BYTE_20:
                        case CMD_BYTE_21:
                        case CMD_BYTE_29:
                        case CMD_BYTE_2A:
                        case CMD_BYTE_2B:
                        case CMD_BYTE_2D:
                        case CMD_BYTE_2E:
                        case CMD_BYTE_2F:
                        case CMD_BYTE_40:
                        case CMD_BYTE_41:
                        case CMD_BYTE_42:
                        case CMD_BYTE_43:
                        case CMD_BYTE_44:
                        case CMD_BYTE_45:
                        case CMD_BYTE_46:
                        case CMD_BYTE_47:
                        case CMD_BYTE_48:
                        case CMD_BYTE_49:
                        case CMD_BYTE_4A:
                        case CMD_BYTE_4B:
                        case CMD_BYTE_4C:
                        case CMD_BYTE_4D:
                        case CMD_BYTE_4E:
                        case CMD_BYTE_4F:
                        case CMD_BYTE_50:
                        case CMD_BYTE_51:
                        case CMD_BYTE_52:
                        case CMD_BYTE_53:
                        case CMD_BYTE_54:
                        case CMD_BYTE_55:
                        case CMD_BYTE_56:
                        case CMD_BYTE_57:
                        case CMD_BYTE_5C:
                        case CMD_BYTE_5F:
                        case CMD_BYTE_96:
                        case CMD_BYTE_97:
                        case CMD_BYTE_9A:
                        case CMD_BYTE_A4:
                        case CMD_BYTE_A5:
                        case CMD_BYTE_A6:
                        case CMD_BYTE_A7:
                        case CMD_BYTE_A8:
                        case CMD_BYTE_A9:
                        case CMD_BYTE_AA:
                        case CMD_BYTE_AB:
                        case CMD_BYTE_AC:
                        case CMD_BYTE_AD:
                        case CMD_BYTE_AE:
                        case CMD_BYTE_AF:
                        case CMD_BYTE_B0:
                        case CMD_BYTE_B1:
                        case CMD_BYTE_B2:
                        case CMD_BYTE_B3:
                        case CMD_BYTE_B4:
                        case CMD_BYTE_B5:
                        case CMD_BYTE_B6:
                        case CMD_BYTE_B7:
                        case CMD_BYTE_B8:
                        case CMD_BYTE_B9:
                        case CMD_BYTE_BA:
                        case CMD_BYTE_BB:
                        case CMD_BYTE_BC:
                        case CMD_BYTE_BD:
                        case CMD_BYTE_BE:
                        case CMD_BYTE_BF:
                        case CMD_BYTE_C0:
                        case CMD_BYTE_C1:
                        case CMD_BYTE_C2:
                        case CMD_BYTE_C3:
                        case CMD_BYTE_C4:
                        case CMD_BYTE_C5:
                        case CMD_BYTE_C6:
                        case CMD_BYTE_C7:
                        case CMD_BYTE_C8:
                        case CMD_BYTE_C9:
                        case CMD_BYTE_CA:
                        case CMD_BYTE_CB:
                        case CMD_BYTE_CC:
                        case CMD_BYTE_CD:
                        case CMD_BYTE_CE:
                        case CMD_BYTE_D0:
                        case CMD_BYTE_D1:
                        case CMD_BYTE_D9:
                        case CMD_BYTE_E4:
                        case CMD_BYTE_E6:
                        case CMD_BYTE_E7:
                        case CMD_BYTE_E8:
                        case CMD_BYTE_E9:
                        case CMD_BYTE_EA:
                        case CMD_BYTE_EB:
                        case CMD_BYTE_EC:
                        case CMD_BYTE_ED:
                        case CMD_BYTE_EE:
                        case CMD_BYTE_EF:
                        case CMD_BYTE_F0: {
                            loopContinue = FALSE;
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    s32 state = ExecuteScriptCommand(action);
                    action->scriptData.savedState = state;
                    switch ((s16)state) {
                        case 0: {
                            if (action->scriptData2.savedState) {
                                action->scriptData = action->scriptData2;
                                if (action->callbacks->setDirection && action->scriptData.unk26 != -1) {
                                    u32 tmp;
                                    action->callbacks->getFlags(action->parentObject, &tmp);
                                    if (tmp & 0x400) {
                                        action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                                    }
                                }
                                if (action->callbacks->setEventIndex) {
                                    action->callbacks->setEventIndex(action->parentObject, action->scriptData.unk24);
                                }
                                InitScriptData(&action->scriptData2);
                            }
                            else {
                                InitScriptData(&action->scriptData);
                            }
                            return 3;
                        }
                        case 3: return 3;
                        case 4: return 4;
                        case 1: return 1;
                        case 2: default: {
                            action->scriptData.unk2C = 0;
                            break;
                        }
                    }
                    break;
                }
                case 0:
                case 1:
                case 4: {
                    return action->scriptData.savedState;
                }
            }
        }
        return 3;
    }

    return 0;
}

// overlay_0000.bin::021497FC
// Return values:
// This function returns what's likely an enum, which controls the state of the script engine state machine, and possibly provides information to code calling the engine.
// The enum is shared at least with HandleAction.
// This value is saved into the state field of the Action when returned from this function.
// - Value 0 indicates a RET on script engine level, HandleAction copies action->scriptData2 onto action->scriptData, and reinitializes scriptData2.
//     If there is no active scriptData2 it clears and reinits scriptData.
//     Ultimately returns code 3 to the script engine caller.
//     Caveat: If the scripting engine is in state 0, HandleAction will immediately return 0 without performing any work.
// - Value 1 is a terminal state (script success? error?), no further scripting progress will happen. This code is always returned to the caller from now on.
// - Value 2 gives control back to the HandleAction function (entry point into the scripting engine state machine)
//     This is the only return value that does not return to the script engine caller
// - Value 3 returns to the caller, but will give control back to ExecuteScriptCommand when reentering the script ("script not finished")
// - Value 4 is some kind of fatal error state, no further scripting progress will happen. This code is always returned to the caller from now on.
static s32 ExecuteScriptCommand(Action *action)
{
    ScriptCommand curCmd;
    ScriptData *scriptData = &action->scriptData;

    while (TRUE) {
        scriptData->curPtr = scriptData->script.ptr;
        curCmd = *scriptData->script.ptr++;
        switch (scriptData->curScriptOp = curCmd.op) {
            case CMD_BYTE_01: {
                u32 arg = (s16)curCmd.arg1;
                u32 argCopy = arg;
                u32 byte = (u8)curCmd.argByte;
                if (ScriptLoggingEnabled(TRUE)) {
                    Log(1, "    ground select %3d[%s] %3d", arg, gGroundMapConversionTable[arg].text, byte);
                }
                GroundMainGroundRequest(argCopy, byte, curCmd.argShort);
                break;
            }
            case CMD_BYTE_02: {
                s32 dungeonId = (s16)curCmd.arg1;
                if (dungeonId == -1) dungeonId = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER);
                if (ScriptLoggingEnabled(TRUE)) {
                    Log(1, "    dungeon select %3d", dungeonId);
                }
                if (dungeonId != -1) {
                    GroundMainRescueRequest(dungeonId, curCmd.argShort);
                    action->scriptData.script.ptr = ResolveJump(action, 1);
                } else {
                    action->scriptData.script.ptr = ResolveJump(action, 0);
                }
                break;
            }
            case CMD_BYTE_03: {
                if (sub_8021700(curCmd.arg1)) {
                    action->scriptData.script.ptr = ResolveJump(action, -1);
                } else {
                    sub_8098D80(curCmd.argShort);
                    action->scriptData.script.ptr = ResolveJump(action, 0);
                }
                break;
            }
            case CMD_BYTE_04: {
                if (curCmd.arg1 == -1) {
                    if (!HasZeroAvailableDungeons() && ScriptSpecialTextHandler2(SPECIAL_TEXT_DUNGEON_LIST, 0, NULL_MONORSTRPTR)) {
                        sub_80A87AC(0, 11);
                        action->scriptData.branchDiscriminant = 0;
                    } else {
                        action->scriptData.branchDiscriminant = -1;
                    }
                    return 2; // do action
                } else {
                    SetScriptVarValue(NULL, DUNGEON_SELECT, RescueDungeonToScriptDungeonId((s16)curCmd.arg1));
                    action->scriptData.branchDiscriminant = 1;
                    return 2; // do action
                }
                break;
            }
            case CMD_BYTE_06: {
                if (curCmd.arg1 == -1) {
                    if (ScriptSpecialTextHandler2(SPECIAL_TEXT_DOJO_ENTER, 0, NULL_MONORSTRPTR)) {
                        sub_80A87AC(0, 11);
                        action->scriptData.branchDiscriminant = 0;
                        return 2;
                    } else {
                        action->scriptData.branchDiscriminant = -1;
                        return 2;
                    }
                } else {
                    SetScriptVarValue(NULL, DUNGEON_ENTER, curCmd.arg1);
                    action->scriptData.branchDiscriminant = 1;
                    return 2;
                }
            }
            case CMD_BYTE_05: {
                action->scriptData.branchDiscriminant = 1;
                return 2;
            }
            case CMD_BYTE_07: {
                s32 tmp = (s16)curCmd.arg1;
                if (tmp == -1) {
                    tmp = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER);
                } else {
                    SetScriptVarValue(NULL, DUNGEON_ENTER, tmp);
                }
                if (ScriptLoggingEnabled(TRUE)) {
                    Log(1, "    dungeon enter check %3d", tmp);
                }
                if (tmp != -1) {
                    action->scriptData.branchDiscriminant = 1;
                    return 2;
                } else {
                    action->scriptData.branchDiscriminant = -1;
                    return 2;
                }
            }
            case CMD_BYTE_08: // SELECT_MAP
            case CMD_BYTE_09: { // SELECT_GROUND
                if (curCmd.op == CMD_BYTE_08) { // SELECT_MAP
                    gCurrentMap = curCmd.arg1;
                    gUnknown_2039A32 = GetAdjustedGroundMap((s16)curCmd.arg1);
                    gUnknown_2039A34 = gUnknown_2039A32;

                    if (ScriptLoggingEnabled(TRUE))
                        Log(1,"    map select %3d %3d[%s]", gCurrentMap, gUnknown_2039A32, gGroundMapConversionTable[gCurrentMap].text);
                } else { // SELECT_GROUND
                    gUnknown_2039A32 = gCurrentMap = curCmd.arg1;
                    gUnknown_2039A34 = curCmd.arg1;

                    if (ScriptLoggingEnabled(TRUE))
                        Log(1,"    ground select %3d %3d[%s]", gCurrentMap, gUnknown_2039A32, gGroundMapConversionTable[gCurrentMap].text);
                }

                SetScriptVarValue(NULL,GROUND_MAP,gCurrentMap);
                SetScriptVarValue(NULL,GROUND_PLACE,gGroundMapConversionTable[gCurrentMap].groundPlaceId);
                GroundSprite_Reset(gUnknown_2039A32);
                sub_809D0BC();
                DeleteGroundEvents();
                DeleteGroundLives();
                DeleteGroundObjects();
                DeleteGroundEffects();
                sub_809C770(gCurrentMap, gGroundMapConversionTable[gCurrentMap].groundPlaceId);
                GroundMap_Select(gUnknown_2039A32);
                GroundLink_Select(gUnknown_2039A32);
                GroundLives_Select(gUnknown_2039A32,0,0);
                GroundObject_Select(gUnknown_2039A32,0,0);
                break;
            }
            case CMD_BYTE_0A: {
                const DungeonInfo *tmp;
                DungeonLocation loc;
                tmp = GetScriptDungeonInfo((s16)curCmd.arg1);
                gUnknown_2039A34 = gUnknown_2039A32 = gCurrentMap = (s16)curCmd.arg2;
                if (ScriptLoggingEnabled(TRUE)) {
                    Log(1, "    dungeon select %3d %3d[%s]", gCurrentMap,gUnknown_2039A32,
                        gGroundMapConversionTable[gCurrentMap].text);
                }
                GroundSprite_Reset(gUnknown_2039A32);
                sub_809D0BC();
                DeleteGroundEvents();
                DeleteGroundLives();
                DeleteGroundObjects();
                DeleteGroundEffects();
                loc.id = tmp->dungeonID;
                loc.floor = curCmd.argShort;
                GroundMap_SelectDungeon(gUnknown_2039A32, &loc, curCmd.argByte);
                GroundLink_Select(gUnknown_2039A32);
                GroundLives_Select(gUnknown_2039A32,0,0);
                GroundObject_Select(gUnknown_2039A32,0,0);
                break;
            }
            case CMD_BYTE_0B: {
                GroundWeather_Select((s16)curCmd.arg1);
                break;
            }
            case CMD_BYTE_0C: // SELECT_ENTITIES
            case CMD_BYTE_0D:
            case CMD_BYTE_0E:
            case CMD_BYTE_0F:
            case CMD_BYTE_10:
            case CMD_BYTE_11:
            case CMD_BYTE_12:
            case CMD_BYTE_13:
            case CMD_BYTE_14:
            case CMD_BYTE_15: {
                s32 group;
                s32 sector;
                {
                    s32 tmp = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    group = tmp;
                }
                {
                    s32 tmp = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    sector = tmp;
                }
                switch (curCmd.op) {
                    case CMD_BYTE_0C: { // SELECT_ENTITIES
                        GroundLives_Select(gUnknown_2039A32, group, sector);
                        GroundObject_Select(gUnknown_2039A32, group, sector);
                        GroundEffect_Select(gUnknown_2039A32, group, sector);
                        GroundEvent_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case CMD_BYTE_0D: {
                        GroundLives_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case CMD_BYTE_0E: {
                        GroundObject_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case CMD_BYTE_0F: {
                        GroundEffect_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case CMD_BYTE_10: {
                        GroundEvent_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case CMD_BYTE_11: {
                        GroundLives_Cancel(group, sector);
                        GroundObject_Cancel(group, sector);
                        GroundEffect_Cancel(group, sector);
                        GroundEvent_Cancel(group, sector);
                        break;
                    }
                    case CMD_BYTE_12: {
                        GroundLives_Cancel(group, sector);
                        break;
                    }
                    case CMD_BYTE_13: {
                        GroundObject_Cancel(group, sector);
                        break;
                    }
                    case CMD_BYTE_14: {
                        GroundEffect_Cancel(group, sector);
                        break;
                    }
                    case CMD_BYTE_15: {
                        GroundEvent_Cancel(group, sector);
                        break;
                    }
                }
                break;
            }
            case CMD_BYTE_16: {
                GroundLives_CancelBlank_1();
                break;
            }
            case CMD_BYTE_17: {
                GroundObject_CancelBlank();
                break;
            }
            case CMD_BYTE_18: {
                GroundEffect_CancelBlank();
                break;
            }
            case CMD_BYTE_19: {
                s8 unk[4];
                GroundObjectData *obj;
                PixelPos pos;
                s16 res;
                s32 group;
                s32 sector;
                action->callbacks->getDirection(action->parentObject, unk);
                obj = ({ GroundObjectData obj = {
                    .unk1 = *unk,
                    .width = 1,
                    .height = 1,
                    .pos = {},
                    .kind = curCmd.arg2,
                    .scripts = { [3] = gFunctionScriptTable[curCmd.arg1].script },
                    };
                    group = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    sector = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    &obj;
                });
                res = GroundObject_Add(-1, obj, group, sector);
                if (res >= 0) {
                    action->callbacks->getHitboxCenter(action->parentObject, &pos);
                    sub_80AC49C(res, &pos);
                }
                break;
            }
            case CMD_BYTE_1A: {
                s8 unk;
                GroundEffectData *eff;
                PixelPos pos;
                s16 res;
                s32 group;
                s32 sector;
                action->callbacks->getDirection(action->parentObject, &unk);
                eff = ({ GroundEffectData eff = {
                    .unk1 = unk,
                    .width = 1,
                    .height = 1,
                    .pos = {},
                    .kind = curCmd.arg2,
                    .script = gFunctionScriptTable[curCmd.arg1].script,
                    };
                    group = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    sector = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    &eff;
                });
                res = (s16) GroundEffect_Add(-1, eff, (s16) group, (s8) sector);
                if (res >= 0) {
                    action->callbacks->getHitboxCenter(action->parentObject, &pos);
                    sub_80AD3B4(res, &pos);
                }
                break;
            }
            case CMD_BYTE_1C: { // EXECUTE_SUBROUTINE
                GroundMap_ExecuteEvent(curCmd.argShort, TRUE);
                break;
            }
            case CMD_BYTE_1B: { // EXECUTE_FUNCTION
                GroundMap_ExecuteEvent(curCmd.argShort, FALSE);
                break;
            }
            case CMD_BYTE_1D: // EXECUTE_STATION
            case CMD_BYTE_1E: { // EXECUTE_SUBSTATION
                s32 map;
                s32 group, sector;
                bool8 isSubStation;
                {
                    s32 tmp = curCmd.arg1 != -1 ? (s16)curCmd.arg1 : gCurrentMap;
                    map = tmp;
                }
                {
                    s32 tmp = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    group = tmp;
                }
                {
                    s32 tmp = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    sector = tmp;
                }
                map = GetAdjustedGroundMap(map);
                isSubStation = curCmd.op == CMD_BYTE_1E;
                GroundMap_ExecuteStation(map, group, sector, isSubStation);
                if (gUnknown_2039A34 != map) {
                    gUnknown_2039A34 = map;
                    GroundCancelAllEntities();
                    if (action->unk8.unk0 != 0)
                        return 4; // Fatal?
                }
                break;
            }
            case CMD_BYTE_1F: { // RESCUE_SELECT
                s32 a = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER);
                const DungeonInfo *ret1 = GetScriptDungeonInfo(a);
                s32 scriptIndex = GetScriptVarArrayValue(NULL, DUNGEON_ENTER_LIST, (u16)a) == 0 ? ret1->scriptID1 : ret1->scriptID2;
                // fakematch: this is almost certainly a range check of the form 0x37 <= a && a < 0x48
                // but that loses the s32 -> u16 cast. Inlines, macros, or other shenanigans are likely involved
                if (!((u16)(a - 0x37) < 0x11) && (s16)sub_80A2750(a) == 1) {
                    if (scriptIndex == -1) {
                        if (ScriptLoggingEnabled(TRUE))
                            Log(1, "    dungeon rescue select %3d", a);

                        GroundMainRescueRequest(a, -1);
                    } else {
                        GroundMap_ExecuteEvent(scriptIndex, FALSE);
                        break;
                    }
                } else {
                    GroundMainRescueRequest(a, -1);
                }
                break;
            }
            case CMD_BYTE_20: {
                switch (action->unkC.unk0) {
                    case 0: {
                        GroundMap_ExecuteEvent(curCmd.argShort, FALSE);
                        break;
                    }
                    case 1: {
                        ScriptInfoSmall info1;
                        GetFunctionScript(action, &info1, curCmd.argShort);
                        GroundLives_ExecuteScript(action->unkC.unk2, &action->unk8, &info1);
                        break;
                    }
                    case 2: {
                        ScriptInfoSmall info2;
                        GetFunctionScript(action, &info2, curCmd.argShort);
                        GroundObject_ExecuteScript(action->unkC.unk2, &action->unk8, &info2);
                        break;
                    }
                    case 3: {
                        ScriptInfoSmall info3;
                        GetFunctionScript(action, &info3, curCmd.argShort);
                        GroundEffect_ExecuteScript(action->unkC.unk2, &action->unk8, &info3);
                        break;
                    }
                }
                break;
            }
            case CMD_BYTE_21: {
                s32 ret;
                u32 unk;
                PixelPos pos1;
                PixelPos pos2;
                PixelPos pos3;
                PixelPos pos4;
                s32 tmp;
                ret = (s16)sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    sub_80A8BD8(ret, &unk);
                    if (unk & 0x200) {
                        action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                        action->callbacks->getSize(action->parentObject, &pos2);
                        sub_80A8FD8(ret, &pos3);
                        sub_80A8F9C(ret, &pos4);
                        if ((tmp = SizedDeltaDirection8(&pos3, &pos4, &pos1, &pos2)) != -1 ||
                            (tmp = SizedDeltaDirection4(&pos1, &sPixelPosZero, &pos3, &sPixelPosZero)) != -1) {
                            sub_80A9090(ret, tmp);
                        }
                    }
                    GroundLives_ExecutePlayerScriptActionLives(action->unk8.unk2, ret);
                    return 3;
                }
                break;
            }
            case CMD_BYTE_22: {
                sub_80999E8(curCmd.argShort);
                if (curCmd.argByte != 0)
                    return 2;
                break;
            }
            case CMD_BYTE_23: {
                sub_80999FC(curCmd.argShort);
                if (curCmd.argByte != 0)
                    return 2;
                break;
            }
            case CMD_BYTE_24: {
                sub_8099A10(curCmd.argShort, curCmd.arg1, curCmd.arg2);
                if (curCmd.argByte != 0)
                    return 2;
                break;
            }
            case CMD_BYTE_25: {
                sub_8099A34(curCmd.argShort);
                if (curCmd.argByte != 0)
                    return 2;
                break;
            }
            case CMD_BYTE_26: {
                sub_8099A48(curCmd.argShort);
                if (curCmd.argByte != 0)
                    return 2;
                break;
            }
            case CMD_BYTE_27:
            case CMD_BYTE_28: {
                RGB_Array color = { curCmd.arg2 >> 16, curCmd.arg2 >> 8, curCmd.arg2, 0 };
                switch (curCmd.op) {
                    case CMD_BYTE_27:
                        sub_8099A5C(curCmd.argShort, curCmd.arg1, color);
                        break;
                    case CMD_BYTE_28:
                        sub_8099AFC(curCmd.argShort, curCmd.arg1, color);
                        break;
                }
                if (curCmd.argByte != 0)
                    return 2;
                break;
            }
            case CMD_BYTE_29: {
                sub_809A6E4((u16)curCmd.argShort);
                break;
            }
            case CMD_BYTE_2A: {
                sub_809A6F8((u16)curCmd.argShort);
                break;
            }
            case CMD_BYTE_2B: {
                SetAutoPressTextboxMidEndMsgFrames(curCmd.arg1, curCmd.arg2);
                break;
            }
            case CMD_BYTE_2C: {
                if (!sub_809A768())
                    break;
                sub_80A87AC(0, 10);
                if (GroundScriptCheckLockCondition(action, 0))
                    return 2;
                break;
            }
            case CMD_BYTE_30: {
                ScriptClearTextbox();
                break;
            }
            case CMD_BYTE_31: {
                ScriptClearTextbox2();
                break;
            }
            case CMD_BYTE_2D: {
                switch ((u8)curCmd.argByte) {
                    case 0: {
                        ResetTextboxPortrait(curCmd.argShort);
                        break;
                    }
                    case 1: {
                        sub_80A2500(curCmd.argShort, &action->unk8);
                        break;
                    }
                    case 2: {
                        sub_80A2500(curCmd.argShort, &action->unkC);
                        break;
                    }
                    case 3: {
                        ActionUnkIds unk;
                        unk.unk2 = sub_80A7AE8((s16)curCmd.arg1);
                        unk.unk0 = 1;
                        sub_80A2500(curCmd.argShort, &unk);
                        break;
                    }
                    case 4: {
                        sub_80A252C(curCmd.argShort, &action->unk8);
                        break;
                    }
                    case 5: {
                        sub_80A252C(curCmd.argShort, &action->unkC);
                        break;
                    }
                    case 6: {
                        ActionUnkIds unk;
                        s16 res = sub_80A7AE8((s16)curCmd.arg1);
                        unk.unk2 = res;
                        if (unk.unk2 >= 0) {
                            unk.unk0 = 1;
                            sub_80A252C(curCmd.argShort, (void*)&unk);
                        } else {
                            sub_80A2584(curCmd.argShort, (s16)curCmd.arg1);
                        }
                        break;
                    }
                    case 7: {
                        sub_80A2558(curCmd.argShort, &action->unk8);
                        break;
                    }
                    case 8: {
                        sub_80A2558(curCmd.argShort, &action->unkC);
                        break;
                    }
                    case 9: {
                        ActionUnkIds unk;
                        s16 res = sub_80A7AE8((s16)curCmd.arg1);
                        unk.unk2 = res;
                        if (unk.unk2 >= 0) {
                            unk.unk0 = 1;
                            sub_80A2558(curCmd.argShort, (void*)&unk);
                        } else {
                            sub_80A2598(curCmd.argShort, (s16)curCmd.arg1);
                        }
                        break;
                    }
                    case 10: {
                        u8 a = ScriptDungeonIdToDungeonId((s16)curCmd.arg1);
                        s32 o = 0;
                        switch ((s16)curCmd.arg1) {
                            case 0: o = 1; break;
                            case 2: o = -1; break;
                        }
                        gFormatArgs[curCmd.argShort] = GetDungeonFloorCount(a) + o;
                        break;
                    }
                }
                break;
            }
            case CMD_BYTE_2E: {
                ScriptSetPortraitInfo(curCmd.argShort, (s8)curCmd.arg1, (u8)curCmd.argByte);
                break;
            }
            case CMD_BYTE_2F: {
                PixelPos pos;
                pos.x = curCmd.arg1;
                pos.y = curCmd.arg2;
                ScriptSetPortraitPosDelta(curCmd.argShort, &pos);
                break;
            }
            case CMD_BYTE_32:
            case CMD_BYTE_33:
            case CMD_BYTE_34:
            case CMD_BYTE_35:
            case CMD_BYTE_36:
            case CMD_BYTE_37:
            case CMD_BYTE_38: {
                s8 ret = FALSE;
                switch (scriptData->curScriptOp) {
                    case CMD_BYTE_32: ret = ScriptPrintText(SCRIPT_TEXT_TYPE_INSTANT, curCmd.argShort, curCmd.argPtr); break;
                    case CMD_BYTE_33: ret = ScriptPrintText(SCRIPT_TEXT_TYPE_PLAYER, curCmd.argShort, curCmd.argPtr); break;
                    case CMD_BYTE_34: ret = ScriptPrintText(SCRIPT_TEXT_TYPE_NPC, curCmd.argShort, curCmd.argPtr); break;
                    case CMD_BYTE_35: ret = ScriptPrintText(SCRIPT_TEXT_TYPE_LETTER, curCmd.argShort, curCmd.argPtr); break;
                    case CMD_BYTE_36: ret = ScriptPrintText(SCRIPT_TEXT_TYPE_4, curCmd.argShort, curCmd.argPtr); break;
                    case CMD_BYTE_37: ret = ScriptPrintTextOnBg(curCmd.argPtr); break;
                    case CMD_BYTE_38: ret = ScriptPrintTextOnBg2(curCmd.argPtr); break;
                }
                if (ret) {
                    sub_80A87AC(0, 10);
                    if (GroundScriptCheckLockCondition(action, 0))
                        return 2;
                }
                break;
            }
            case CMD_BYTE_39: {
                if ((s8)ScriptPrintTextOnBgAuto(curCmd.argShort, curCmd.argPtr) && curCmd.argShort >= 0) {
                    sub_80A87AC(0, 10);
                    if (GroundScriptCheckLockCondition(action, 0))
                        return 2;
                }
                break;
            }
            case CMD_BYTE_3A: {
                sub_809AFC8((u8)curCmd.argByte > 0, curCmd.arg1, (s16)curCmd.arg2, curCmd.argPtr);
                if (GroundScriptCheckLockCondition(action, 1)) {
                    sub_80A87AC(0, 11);
                    return 2;
                }
                break;
            }
            case CMD_BYTE_3C: { // SPECIAL_TEXT
                ScriptSpecialTextHandler(curCmd.argByte, curCmd.arg1, curCmd.arg2, STR_TO_MONORSTRPTR((u8*)curCmd.argPtr));
                sub_80A87AC(0, 11);
                return 2;
            }
            case CMD_BYTE_3B: {
                scriptData->unk2A = 0;
                return 2;
            }
            case CMD_BYTE_3D: {
                s32 i;
                if ((s16)curCmd.arg1 != -1) {
                    Pokemon *mon = sub_80A8D54((s16) curCmd.arg1);
                    if (mon != NULL) {
                        for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
                            sPokeNameBuffer[i] = mon->name[i];
                        }
                        sPokeNameBuffer[POKEMON_NAME_LENGTH] = 0;
                        ScriptSpecialTextHandler2(SPECIAL_TEXT_PLAYER_NAME_INPUT, 0, STR_TO_MONORSTRPTR(sPokeNameBuffer));
                        sub_80A87AC(0, 11);
                        return 2;
                    }
                    break;
                } else {
                    ScriptSpecialTextHandler2(SPECIAL_TEXT_PLAYER_NAME_INPUT, 1, STR_TO_MONORSTRPTR(sPokeNameBuffer));
                    sub_80A87AC(0, 11);
                    return 2;
                }
            }
            case CMD_BYTE_3E: {
                sub_80920B8(sPokeNameBuffer);
                sPokeNameBuffer[10] = '\0';
                ScriptSpecialTextHandler2(SPECIAL_TEXT_TEAM_NAME_INPUT, 0, STR_TO_MONORSTRPTR(sPokeNameBuffer));
                sub_80A87AC(0, 11);
                return 2;
            }
            case CMD_BYTE_3F: {
                s32 i;
                for (i = 0; i < ARRAY_COUNT_INT(sPokeNameBuffer); i++)
                    sPokeNameBuffer[i] = '\0';

                ScriptSpecialTextHandler2(SPECIAL_TEXT_PASSWORD_INPUT, (u8)curCmd.argByte, STR_TO_MONORSTRPTR(sPokeNameBuffer));
                sub_80A87AC(0, 11);
                return 2;
            }
            case CMD_BYTE_42: {
                StopAllMusic_1();
                break;
            }
            case CMD_BYTE_43: {
                FadeOutAllMusic(curCmd.argShort < 0 ? 30 : curCmd.argShort);
                break;
            }
            case CMD_BYTE_44: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999)
                    StartNewBGM_(id);
                else
                    StopBGMusic();

                break;
            }
            case CMD_BYTE_45: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999)
                    FadeInNewBGM_(id, curCmd.argShort);
                else
                    StopBGMusic();

                break;
            }
            case CMD_BYTE_46: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999)
                    QueueBGM_((u16)id);

                break;
            }
            case CMD_BYTE_47: {
                StopBGMusic();
                break;
            }
            case CMD_BYTE_48: {
                FadeOutBGM_(curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case CMD_BYTE_49:
            case CMD_BYTE_4C: {
                PlaySoundWithVolume((u16)curCmd.arg1, 256);
                break;
            }
            case CMD_BYTE_4A:
            case CMD_BYTE_4D: {
                StopSound((u16)curCmd.arg1);
                break;
            }
            case CMD_BYTE_4B:
            case CMD_BYTE_4E: {
                FadeOutSound((u16)curCmd.arg1, curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case CMD_BYTE_4F: {
                if (action->scriptData2.state == 1)
                    InitScriptData(&action->scriptData2);

                action->callbacks->setHitboxPos(action->parentObject, 0);
                break;
            }
            case CMD_BYTE_50: {
                Action *ptr;
                PixelPos pos;
                s8 c;
                {
                    Action *tmp = sub_809D52C(&action->unkC);
                    ptr = tmp;
                }
                if (ptr != NULL) {
                    ptr->callbacks->getHitboxCenter(action->parentObject, &pos);
                    ptr->callbacks->getDirection(action->parentObject, &c);
                    action->callbacks->moveReal(action->parentObject, &pos);
                    action->scriptData.unk26 = c;
                    action->callbacks->setDirection(action->parentObject, c);
                }
                break;
            }
            case CMD_BYTE_51: {
                PixelPos posIn;
                PixelPos posOut1;
                PixelPos posOut2;

                action->callbacks->getHitboxCenter(action->parentObject, &posIn);
                GroundLink_GetArea(curCmd.argShort, &posOut1, &posOut2, &posIn);
                action->callbacks->setPositionBounds(action->parentObject, &posOut1, &posOut2);
                break;
            }
            case CMD_BYTE_52: {
                action->callbacks->setFlags(action->parentObject, curCmd.arg1);
                break;
            }
            case CMD_BYTE_53: {
                if (curCmd.arg1 & 0x400 && action->scriptData2.state == 1)
                    InitScriptData(&action->scriptData2);

                action->callbacks->clearFlags(action->parentObject, curCmd.arg1);
                break;
            }
            case CMD_BYTE_54: {
                action->callbacks->getDirection(action->parentObject, &action->scriptData.unk26);
                if (curCmd.argShort != 0)
                    action->scriptData.unk24 = curCmd.argShort;

                action->callbacks->setEventIndex(action->parentObject, (u16)curCmd.argShort);
                break;
            }
            case CMD_BYTE_55: {
                action->callbacks->livesOnlyNullsub(action->parentObject, (u16)curCmd.argShort);
                break;
            }
            case CMD_BYTE_56: {
                action->callbacks->func38(action->parentObject, (s16)curCmd.arg1, curCmd.argShort);
                break;
            }
            case CMD_BYTE_57: {
                action->callbacks->func44_livesOnlySpriteRelated(action->parentObject, curCmd.argShort);
                break;
            }
            case CMD_BYTE_58: {
                PixelPos unk;
                unk.x = curCmd.arg1 << 8;
                unk.y = curCmd.arg2 << 8;
                action->callbacks->moveReal(action->parentObject, &unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_59: {
                PixelPos unk;
                unk.x = curCmd.argShort << 8;
                unk.y = curCmd.arg1 << 8;
                action->callbacks->moveRelative(action->parentObject, &unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_5A: {
                PixelPos unk;
                unk.x = OtherRandInt(curCmd.argShort) << 8;
                unk.y = OtherRandInt(curCmd.arg1) << 8;
                action->callbacks->moveRelative(action->parentObject, &unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_5B: {
                PixelPos unk;
                action->callbacks->getHitboxCenter(action->parentObject, &unk);
                GroundLink_GetPos((s16)curCmd.arg1, &unk);
                action->callbacks->moveReal(action->parentObject, &unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_5C: {
                PixelPos pos, pos1, pos2;
                action->callbacks->getHitboxCenter(action->parentObject, &pos);
                GroundLink_GetArea((s16)curCmd.arg1, &pos1, &pos2, &pos);
                pos.x = pos1.x + OtherRandInt(pos2.x - pos1.x);
                pos.y = pos1.y + OtherRandInt(pos2.y - pos1.y);
                action->callbacks->moveReal(action->parentObject, &pos);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_5D: {
                PixelPos unk;
                s16 res = sub_80A7AE8((s16)curCmd.arg1);
                if (res >= 0) {
                    sub_80A8FD8(res, &unk);
                    action->callbacks->moveReal(action->parentObject, &unk);
                    scriptData->unk2A = (u8)curCmd.argByte;
                    return 2;
                }
                break;
            }
            case CMD_BYTE_5E: {
                PixelPos pos;
                s32 height;
                s32 dir;
                pos.x = GetScriptVarArrayValue(NULL, POSITION_X, (u16)curCmd.arg1);
                pos.y = GetScriptVarArrayValue(NULL, POSITION_Y, (u16)curCmd.arg1);
                height = GetScriptVarArrayValue(NULL, POSITION_HEIGHT, (u16)curCmd.arg1);
                dir = (s8)GetScriptVarArrayValue(NULL, POSITION_DIRECTION, (u16)curCmd.arg1);
                action->callbacks->moveReal(action->parentObject, &pos);
                action->callbacks->setPosHeight(action->parentObject, height);
                action->scriptData.unk26 = dir;
                action->callbacks->setDirection(action->parentObject, dir);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_5F: {
                PixelPos pos;
                u32 height;
                u32 wat;
                s8 dir;
                action->callbacks->getHitboxCenter(action->parentObject, &pos);
                action->callbacks->getPosHeightAndUnk(action->parentObject, &height, &wat);
                action->callbacks->getDirection(action->parentObject, &dir);
                SetScriptVarArrayValue(NULL, POSITION_X, (u16)curCmd.arg1, pos.x);
                SetScriptVarArrayValue(NULL, POSITION_Y, (u16)curCmd.arg1, pos.y);
                SetScriptVarArrayValue(NULL, POSITION_HEIGHT, (u16)curCmd.arg1, height);
                SetScriptVarArrayValue(NULL, POSITION_DIRECTION, (u16)curCmd.arg1, dir);
                break;
            }
            case CMD_BYTE_60: {
                action->callbacks->setPosHeight(action->parentObject, curCmd.arg1 << 8);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_61:
            case CMD_BYTE_69: {
                scriptData->pos2.x = curCmd.arg1 << 8;
                scriptData->pos2.y = curCmd.arg2 << 8;
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case CMD_BYTE_62:
            case CMD_BYTE_6A: {
                PixelPos pos;
                action->callbacks->getHitboxCenter(action->parentObject, &pos);
                scriptData->pos2.x = pos.x + (curCmd.arg1 << 8);
                scriptData->pos2.y = pos.y + (curCmd.arg2 << 8);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case CMD_BYTE_63:
            case CMD_BYTE_6B: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case CMD_BYTE_64:
            case CMD_BYTE_6C: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_65:
            case CMD_BYTE_6D: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = OtherRandInt((u8)curCmd.argByte);
                return 2;
            }
            case CMD_BYTE_66:
            case CMD_BYTE_67:
            case CMD_BYTE_6E:
            case CMD_BYTE_6F: {
                s16 ret = sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    sub_80A8FD8(ret, &scriptData->pos2);
                    scriptData->unk30 = curCmd.argShort;
                    scriptData->unk2A = (u8)curCmd.argByte;
                    return 2;
                }
                break;
            }
            case CMD_BYTE_71:
            case CMD_BYTE_77:
            case CMD_BYTE_7D:
            case CMD_BYTE_83: {

#define HYPOT (FP24_8_Hypot((s24_8){scriptData->pos2.x - scriptData->pos1.x}, (s24_8){scriptData->pos2.y - scriptData->pos1.y}) / curCmd.argShort)

                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = curCmd.arg1 << 8;
                scriptData->pos2.y = curCmd.arg2 << 8;
                if (curCmd.op == CMD_BYTE_7D || curCmd.op == CMD_BYTE_83) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0)
                        scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case CMD_BYTE_72:
            case CMD_BYTE_78:
            case CMD_BYTE_7E:
            case CMD_BYTE_84: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = scriptData->pos1.x + (curCmd.arg1 << 8);
                scriptData->pos2.y = scriptData->pos1.y + (curCmd.arg2 << 8);
                if (curCmd.op == CMD_BYTE_7E || curCmd.op == CMD_BYTE_84) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0)
                        scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case CMD_BYTE_73:
            case CMD_BYTE_79:
            case CMD_BYTE_7F:
            case CMD_BYTE_85: {
                // BUG: (or two): these lines use the wrong script command arguments to calculate the position offset
                // making the target position nonsense. But even if they were correct,
                // the way the cap is calculated would make the random offset biased off-center.
                // This doesn't affect the released version because these script commands are never used.
#ifndef BUGFIX
                s32 cap1 = curCmd.arg1 * 2 - 1;
                s32 cap2 = curCmd.arg2 * 2 - 1;

                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = scriptData->pos1.x + ((OtherRandInt(cap1) - curCmd.argShort) << 8);
                scriptData->pos2.y = scriptData->pos1.y + ((OtherRandInt(cap2) - curCmd.arg1) << 8);
#else
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = scriptData->pos1.x + ((OtherRandInt(curCmd.arg1 * 2 + 1) - curCmd.arg1) << 8);
                scriptData->pos2.y = scriptData->pos1.y + ((OtherRandInt(curCmd.arg2 * 2 + 1) - curCmd.arg2) << 8);
#endif
                if (curCmd.op == CMD_BYTE_7F || curCmd.op == CMD_BYTE_85) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0)
                        scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case CMD_BYTE_74:
            case CMD_BYTE_7A:
            case CMD_BYTE_80:
            case CMD_BYTE_86: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2 = scriptData->pos1;
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                if (curCmd.op == CMD_BYTE_80 || curCmd.op == CMD_BYTE_86) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0)
                        scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case CMD_BYTE_75:
            case CMD_BYTE_7B:
            case CMD_BYTE_81:
            case CMD_BYTE_87: {
                s32 cap = curCmd.arg1 * 2 - 1;
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg2, &scriptData->pos2);
                scriptData->pos2.x = scriptData->pos2.x + ((OtherRandInt(cap) - curCmd.argShort) << 8);
                scriptData->pos2.y = scriptData->pos2.y + ((OtherRandInt(cap) - curCmd.argShort) << 8);
                if (curCmd.op == CMD_BYTE_81 || curCmd.op == CMD_BYTE_87) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0)
                        scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case CMD_BYTE_76:
            case CMD_BYTE_7C:
            case CMD_BYTE_82:
            case CMD_BYTE_88: {
                s16 ret = sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                    sub_80A8FD8(ret, &scriptData->pos2);
                    if (curCmd.op == CMD_BYTE_82 || curCmd.op == CMD_BYTE_88) {
                        scriptData->unk2A = HYPOT;
                        if (scriptData->unk2A <= 0)
                            scriptData->unk2A = 1;
                    } else {
                        scriptData->unk2A = curCmd.argShort;
                    }
                    return 2;
                }
                break;
            }
            case CMD_BYTE_68:
            case CMD_BYTE_70: {
                scriptData->unk48 = curCmd.arg1 << 8;
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case CMD_BYTE_89: {
                action->scriptData.unk26 = curCmd.arg1;
                action->callbacks->setDirection(action->parentObject, (s8) curCmd.arg1);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_8A: { // CMD_UNK_8A
                s8 dir;
                action->callbacks->getDirection(action->parentObject, &dir);
                action->scriptData.unk26 = TransformDirection1(dir, (u8)curCmd.arg1);
                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_8B: {
                action->scriptData.unk26 = curCmd.argShort;
                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_8C: { // CMD_UNK_8C
                s32 ret = (s16)sub_80A7AE8((s16)curCmd.arg1);
                s8 dir;
                if (ret >= 0) {
                    sub_80A9050(ret, &dir);
                    action->scriptData.unk26 = TransformDirection1(dir, (u8)curCmd.argShort);
                    action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                }
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_8D: { // CMD_UNK_8D
                s8 dir;
                action->callbacks->getDirection(action->parentObject, &dir);
                action->scriptData.unk26 = TransformDirection1(dir, (u8)curCmd.argShort);
                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_8E: // CMD_UNK_8E
            case CMD_BYTE_8F: // CMD_UNK_8F
            case CMD_BYTE_90: { // CMD_UNK_90
                bool8 flag = FALSE;
                s8 dir;
                PixelPos pos1, pos2, pos3, pos4;
                switch (curCmd.op) {
                    case CMD_BYTE_8E: { // CMD_UNK_8E
                        s32 val = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (val >= 0) {
                            flag = TRUE;
                            sub_80A8FD8(val, &pos1);
                            sub_80A8F9C(val, &pos2);
                        }
                        break;
                    }
                    case CMD_BYTE_8F: { // CMD_UNK_8F
                        s32 val = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (val >= 0) {
                            flag = TRUE;
                            sub_80A8FD8(val, &pos1);
                            pos2 = sPixelPosZero;
                        }
                        break;
                    }
                    case CMD_BYTE_90: { // CMD_UNK_90
                        flag = TRUE;
                        action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                        action->callbacks->getSize(action->parentObject, &pos2);
                        GroundLink_GetPos((s16)curCmd.arg1, &pos1);
                        break;
                    }
                }
                if (flag) {
                    s8 ret;
                    s32 tmp;
                    action->callbacks->getHitboxCenter(action->parentObject, &pos3);
                    action->callbacks->getSize(action->parentObject, &pos4);
                    ret = SizedDeltaDirection8(&pos3, &pos4, &pos1, &pos2); // wtf
                    *&dir = ret;

                    tmp = -1;
                    if (dir == tmp) {
                        dir = SizedDeltaDirection4(&pos3, &sPixelPosZero, &pos1, &sPixelPosZero);
                    }
                    if (dir == tmp) {
                        action->callbacks->getDirection(action->parentObject, &dir);
                    }
                    action->scriptData.unk26 = TransformDirection1(dir, (u8)curCmd.argShort);
                    action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                }
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case CMD_BYTE_93: // CMD_UNK_93
            case CMD_BYTE_94: // CMD_UNK_94
            case CMD_BYTE_95: { // CMD_UNK_95
                scriptData->unk2A = 0;
                return 2;
            }
            case CMD_BYTE_91: { // ROTATE_TO
                action->scriptData.unk4D = (s8)curCmd.arg1;
                scriptData->unk2A = 0;
                return 2;
            }
            case CMD_BYTE_92: { // CMD_UNK_92
                s8 unk;
                action->callbacks->getDirection(action->parentObject, &unk);
                action->scriptData.unk4D = TransformDirection1(unk, (u8)curCmd.arg1);
                scriptData->unk2A = 0;
                return 2;
            }
            case CMD_BYTE_97: {
                sub_809D124(curCmd.argShort, curCmd.arg1, curCmd.arg2);
                break;
            }
            case CMD_BYTE_98: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                switch (action->unk8.unk0) {
                    case 1:
                        sub_809D170(1, id);
                        break;
                    case 2:
                        sub_809D170(2, id);
                        break;
                    case 3:
                        sub_809D170(3, id);
                        break;
                }
                break;
            }
            case CMD_BYTE_99: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch (action->unk8.unk0) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D158(0, &unk);
                        break;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D158(0, &unk);
                        break;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D158(0, &unk);
                        break;
                }
                break;
            }
            case CMD_BYTE_9A: {
                sub_809D170(1, 0);
                break;
            }
            case CMD_BYTE_9B: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                if (id < 0)
                    break;
                switch (action->unk8.unk0) {
                    case 1:
                        sub_809D1A8(1, id, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_809D1A8(2, id, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_809D1A8(3, id, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case CMD_BYTE_9C: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch (action->unk8.unk0) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D190(0, &unk, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D190(0, &unk, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D190(0, &unk, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case CMD_BYTE_9D: {
                sub_809D1A8(1, 0, curCmd.argShort);
                return 2;
            }
            case CMD_BYTE_9E: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                if (id < 0)
                    break;
                switch (action->unk8.unk0) {
                    case 1:
                        sub_809D1E4(1, id, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_809D1E4(2, id, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_809D1E4(3, id, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case CMD_BYTE_9F: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch (action->unk8.unk0) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D1CC(0, &unk, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D1CC(0, &unk, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D1CC(0, &unk, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case CMD_BYTE_A0: {
                sub_809D1E4(1, 0, curCmd.argShort);
                return 2;
            }
            case CMD_BYTE_A1: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                if (id < 0)
                    break;
                switch (action->unk8.unk0) {
                    case 1:
                        sub_809D220(1, id, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_809D220(2, id, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_809D220(3, id, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case CMD_BYTE_A2: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch (action->unk8.unk0) {
                    case 1:
                        sub_80A8FD8(id, &unk);
                        sub_809D208(0, &unk, curCmd.argShort);
                        return 2;
                    case 2:
                        sub_80AC448(id, &unk);
                        sub_809D208(0, &unk, curCmd.argShort);
                        return 2;
                    case 3:
                        sub_80AD360(id, &unk);
                        sub_809D208(0, &unk, curCmd.argShort);
                        return 2;
                }
                break;
            }
            case CMD_BYTE_A3: {
                sub_809D220(1, 0, curCmd.argShort);
                return 2;
            }
            case CMD_BYTE_A4: {
                ResetScriptVarArray(scriptData->localVars.buf, curCmd.argShort);
                break;
            }
            case CMD_BYTE_A5: {
                ClearScriptVarArray(scriptData->localVars.buf, curCmd.argShort);
                break;
            }
            case CMD_BYTE_A6: {
                UpdateScriptVarWithImmediate(scriptData->localVars.buf, curCmd.argShort, curCmd.arg1, curCmd.argByte);
                break;
            }
            case CMD_BYTE_A7: {
                UpdateScriptVarWithVar(scriptData->localVars.buf, curCmd.argShort, (s16)curCmd.arg1, curCmd.argByte);
                break;
            }
            case CMD_BYTE_A8: { // SET_ARRAYVAL
                SetScriptVarArrayValue(scriptData->localVars.buf, curCmd.argShort, (u16)curCmd.arg1, curCmd.arg2);
                break;
            }
            case CMD_BYTE_A9: { // SCENARIO_CALC
                ScenarioCalc(curCmd.argShort, curCmd.arg1, curCmd.arg2);
                break;
            }
            case CMD_BYTE_AA: { // SCENARIO_ADVANCE
                s32 a, b;
                GetScriptVarScenario(curCmd.argShort, &a, &b);
                ScenarioCalc(curCmd.argShort, a, b + 1);
                break;
            }
            case CMD_BYTE_AB: { // SET_DUNGEON_RES
                SetScriptVarValue(NULL, DUNGEON_ENTER, curCmd.arg1);
                SetScriptVarValue(NULL, DUNGEON_RESULT, curCmd.argShort);
                break;
            }
            case CMD_BYTE_AC: { // SET_PLAYER_KIND
                SetScriptVarValue(NULL, PLAYER_KIND, curCmd.argShort);
                break;
            }
            case CMD_BYTE_AD: { // UNLOCK_FRIEND_AREA
                ScriptUnlockFriendArea(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case CMD_BYTE_AE: { // CMD_UNK_AE
                sub_809733C(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case CMD_BYTE_AF: { // CMD_UNK_AF
                sub_80973A8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case CMD_BYTE_B0: { // SET_RESCUE_CONQUERED
                SetRescueScenarioConquered(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case CMD_BYTE_B1: {
                sub_80975A8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case CMD_BYTE_B2: {
                SetAdventureAchievement(curCmd.argShort);
                break;
            }
            case CMD_BYTE_B3: {
                if (JudgeVarWithImmediate(NULL, curCmd.argShort, curCmd.arg1, JUDGE_EQ))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_B4: {
                if (JudgeVarWithImmediate(scriptData->localVars.buf, (s16)curCmd.arg1, curCmd.arg2, (u8)curCmd.argByte))
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);

                break;
            }
            case CMD_BYTE_B5: {
                if (JudgeVarWithVar(scriptData->localVars.buf, (s16)curCmd.arg1, (s16)curCmd.arg2, (u8)curCmd.argByte))
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);

                break;
            }
            case CMD_BYTE_B6: {
                if (GetScriptVarArrayValue(scriptData->localVars.buf, (s16)curCmd.arg1, (u16)curCmd.arg2))
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);

                break;
            }
            case CMD_BYTE_B7: {
                if (FlagJudge(GetScriptVarArraySum(scriptData->localVars.buf, (s16)curCmd.arg1), curCmd.arg2, (u8)curCmd.argByte))
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);

                break;
            }
            case CMD_BYTE_B8: {
                if (ScriptVarScenarioBefore(curCmd.argShort, curCmd.arg1, curCmd.arg2))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_B9: {
                if (ScriptVarScenarioEqual(curCmd.argShort, curCmd.arg1, curCmd.arg2))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_BA: { // JUMPIF_SCENE_GT
                if (ScriptVarScenarioAfter(curCmd.argShort, curCmd.arg1, curCmd.arg2))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_BB: { // JUMPIF_SCENARIOCHECK
                if (CheckQuest(curCmd.argShort))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_BC: { // JUMPIF_CUTSCENE_FLAG
                if (GetCutsceneFlag(curCmd.argShort))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_BD: {
                if (sub_80026CC(curCmd.arg1))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_BF: {
                if (HasItemInInventory(curCmd.argShort) > 0)
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_BE: {
                if (action->unk8.unk0 == 1 && GroundLives_IsStarterMon(action->unk8.unk2))
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);

                break;
            }
            case CMD_BYTE_41: {
                s32 val = FindItemInInventory(curCmd.argShort);
                if (val >= 0)
                    ShiftItemsDownFrom(val);
                break;
            }
            case CMD_BYTE_C0:
            case CMD_BYTE_C1:
            case CMD_BYTE_C2:
            case CMD_BYTE_C3:
            case CMD_BYTE_C4:
            case CMD_BYTE_C5:
            case CMD_BYTE_C6:
            case CMD_BYTE_C7:
            case CMD_BYTE_C8:
            case CMD_BYTE_C9:
            case CMD_BYTE_CA:
            case CMD_BYTE_CB: {
                s32 val;
                PixelPos pos, pos2, pos3;
                switch (curCmd.op) {
                    case CMD_BYTE_C0: {
                        val = GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort);
                        break;
                    }
                    case CMD_BYTE_C1: {
                        val = FlagCalc(GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort), curCmd.arg1, (u8)curCmd.argByte);
                        break;
                    }
                    case CMD_BYTE_C2: {
                        val = FlagCalc(GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort), GetScriptVarValue(scriptData->localVars.buf, (s16)curCmd.arg1), (u8)curCmd.argByte);
                        break;
                    }
                    case CMD_BYTE_C3: {
                        val = OtherRandInt(curCmd.argShort);
                        break;
                    }
                    case CMD_BYTE_C4: {
                        val = GetScriptVarArrayValue(NULL, curCmd.argShort, 0);
                        break;
                    }
                    case CMD_BYTE_C5: {
                        val = GetScriptVarArrayValue(NULL, curCmd.argShort, 1);
                        break;
                    }
                    case CMD_BYTE_C6: { // CJUMP_UNK_C6
                        val = (s16)sub_80A8C2C((s16)curCmd.arg1);
                        break;
                    }
                    case CMD_BYTE_C7: {
                        s8 dir;
                        action->callbacks->getDirection(action->parentObject, &dir);
                        val = dir;
                        break;
                    }
                    case CMD_BYTE_CA: {
                        action->callbacks->getHitboxCenter(action->parentObject, &pos);
                        pos2 = pos;
                        GroundLink_GetPos((s16)curCmd.arg1, &pos2);
                        pos3.x = pos2.x - pos.x;
                        pos3.y = pos2.y - pos.y;
                        val = (s8) VecDirection8Radial(&pos3);
                        break;
                    }
                    case CMD_BYTE_C8: {
                        s16 tmp = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (tmp >= 0) {
                            PixelPos pos1, pos2, pos3, pos4;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                            action->callbacks->getSize(action->parentObject, &pos2);
                            sub_80A8FD8(tmp, &pos3);
                            sub_80A8F9C(tmp, &pos4);
                            val = SizedDeltaDirection8(&pos1, &pos2, &pos3, &pos4);
                            if (val == -1)
                                val = SizedDeltaDirection4(&pos1, &sPixelPosZero, &pos3, &sPixelPosZero);
                        } else {
                            val = -1;
                        }
                        break;
                    }
                    case CMD_BYTE_C9: {
                        s16 tmp = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (tmp >= 0) {
                            PixelPos pos1, pos2, pos3;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                            action->callbacks->getSize(action->parentObject, &pos2);
                            sub_80A8FD8(tmp, &pos3);
                            val = SizedDeltaDirection8(&pos1, &pos2, &pos3, &sPixelPosZero);
                            if (val == -1)
                                val = SizedDeltaDirection4(&pos1, &sPixelPosZero, &pos3, &sPixelPosZero);
                        } else {
                            val = -1;
                        }
                        break;
                    }
                    case CMD_BYTE_CB: {
                        val = CheckScriptItemSpace(curCmd.argShort);
                        break;
                    }
                    default: {
                        // The locdata says this is part of an inlined function... :/
                        FATAL_ERROR_ARGS2("../ground/ground_script.c", 4222, "_AnalyzeProcess", "switch type error %d", curCmd.op);
                    }
                }
                scriptData->script.ptr = ResolveJump(action, val);
                break;
            }
            case CMD_BYTE_CF: {
                scriptData->branchDiscriminant = GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort);
                while (scriptData->script.ptr->op == CMD_BYTE_D0) {
                    if (scriptData->script.ptr->argShort == scriptData->branchDiscriminant)
                        return 2;
                    scriptData->script.ptr++;
                }
                if (scriptData->script.ptr->op == CMD_BYTE_D1) {
                    scriptData->branchDiscriminant = -1;
                    return 2;
                }
                break;
            }
            case CMD_BYTE_D2:
            case CMD_BYTE_D3:
            case CMD_BYTE_D4:
            case CMD_BYTE_D5:
            case CMD_BYTE_D6:
            case CMD_BYTE_D7:
            case CMD_BYTE_D8: {
                // DS: Assert(TRUE, "Script command call error SWITCH MENY") [sic]
                const u8 *out = curCmd.argPtr;
                sNumChoices = 0;
                scriptData->branchDiscriminant = 0;

                switch (curCmd.op) {
                    case CMD_BYTE_D6:
                    case CMD_BYTE_D7:
                    case CMD_BYTE_D8: {
                        s32 disc = GetScriptVarValue(scriptData->localVars.buf, (s16)curCmd.arg2);
                        for (; scriptData->script.ptr->op == CMD_BYTE_D0; scriptData->script.ptr++, scriptData->branchDiscriminant++) {
                            if (scriptData->script.ptr->argShort == disc)
                                out = scriptData->script.ptr->argPtr;
                        }
                        for (; scriptData->script.ptr->op == CMD_BYTE_D1; scriptData->script.ptr++, scriptData->branchDiscriminant++) {
                            if (out == NULL)
                                out = scriptData->script.ptr->argPtr;
                        }
                    }
                }
                if (out == NULL)
                    out = "";
                for (; scriptData->script.ptr->op == CMD_BYTE_D9; scriptData->script.ptr++) {
                    gChoices[sNumChoices].text = scriptData->script.ptr->argPtr;
                    gChoices[sNumChoices].menuAction = sNumChoices + 1;
                    sNumChoices++;
                }
                if (sNumChoices <= 0)
                    break;
                gChoices[sNumChoices].text = NULL;
                gChoices[sNumChoices].menuAction = curCmd.argShort;
                switch (curCmd.op) {
                    case CMD_BYTE_D2:
                    case CMD_BYTE_D3:
                    case CMD_BYTE_D6: {
                        sub_809B028(gChoices, (u8)curCmd.argByte > 0, -1, 0, (s16)curCmd.arg1, out);
                        break;
                    }
                    case CMD_BYTE_D4:
                    case CMD_BYTE_D7: {
                        sub_809B028(gChoices, (u8)curCmd.argByte > 0, -1, 1, (s16)curCmd.arg1, out);
                        break;
                    }
                    case CMD_BYTE_D5:
                    case CMD_BYTE_D8: {
                        sub_809B028(gChoices, (u8)curCmd.argByte > 0, -1, 2, (s16)curCmd.arg1, out);
                        break;
                    }
                }
                if (GroundScriptCheckLockCondition(action, 1)) {
                    sub_80A87AC(0, 11);
                    return 2;
                }
                break;
            }
            case CMD_BYTE_DA: {
                if (GroundScriptCheckLockCondition(action, 1))
                    return 2;

                break;
            }
            case CMD_BYTE_DB: { // WAIT
                scriptData->unk2A = curCmd.argShort;
                return 2;
            }
            case CMD_BYTE_DC: {
                scriptData->unk2A = curCmd.argShort + OtherRandInt(curCmd.arg1 - curCmd.argShort);
                return 2;
            }
            case CMD_BYTE_DD:
            case CMD_BYTE_DE:
            case CMD_BYTE_DF:
            case CMD_BYTE_E0:
            case CMD_BYTE_E1: // WAIT_FANFARE1
            case CMD_BYTE_E2: { // WAIT_FANFARE2
                return 2;
            }
            case CMD_BYTE_E3: {
                scriptData->branchDiscriminant = curCmd.argShort;

                if (GroundScriptCheckLockCondition(action, curCmd.argShort))
                    return 2;

                break;
            }
            case CMD_BYTE_E4: { // ALERT_CUE
                GroundScriptLockJumpZero(curCmd.argShort);
                break;
            }
            case CMD_BYTE_E5: { // CMD_UNK_E5
                scriptData->branchDiscriminant = curCmd.argShort;

                if (GroundScriptLockCond(action, curCmd.argShort, curCmd.argByte))
                    return 2;

                break;
            }
            case CMD_BYTE_E6: { // CALL_LABEL
                scriptData->savedScript = scriptData->script;
                // Fallthrough
            }
            case CMD_BYTE_E7: { // JUMP_LABEL
                scriptData->script.ptr = FindLabel(action, curCmd.argShort);
                break;
            }
            case CMD_BYTE_E8: { // CALL_SCRIPT
                scriptData->savedScript = scriptData->script;
                // Fallthrough
            }
            case CMD_BYTE_E9: { // JUMP_SCRIPT
                scriptData->script.ptr2 = scriptData->script.ptr = gFunctionScriptTable[curCmd.argShort].script;
                break;
            }
            case CMD_BYTE_EA: { // CALL_STATION
                scriptData->savedScript = scriptData->script;
                // Fallthrough
            }
            case CMD_BYTE_EB: { // JUMP_STATION
                ScriptInfoSmall info;
                u32 group, sector;
                u32 tmp = gUnknown_2039A34;
                {
                    s32 tmp = curCmd.argShort < 0 ? scriptData->script.group : curCmd.argShort;
                    group = tmp;
                }
                {
                    s32 tmp = (s8)curCmd.argByte < 0 ? scriptData->script.sector : (s8)curCmd.argByte;
                    sector = tmp;
                }
                GroundMap_GetStationScript(&info, tmp, group, sector);
                scriptData->script.ptr = info.ptr;
                scriptData->script.ptr2 = info.ptr;
                scriptData->script.group = group;
                scriptData->script.sector = sector;
                break;
            }
            case CMD_BYTE_EC: { // EXECUTE_MAP_VAR
                gUnknown_2039A34 = GetAdjustedGroundMap((s16)GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort));
                GroundCancelAllEntities();
                GroundMap_ExecuteEnter(gUnknown_2039A34);
                break;
            }
            case CMD_BYTE_ED: { // RESET_CALLER
                // DS: if (scriptData->savedScript.ptr == NULL) Assert(FALSE, "Script flash stack error");
                scriptData->savedScript.ptr = NULL;
                scriptData->savedScript.ptr2 = NULL;
                break;
            }
            case CMD_BYTE_EE: { // RET_DIRECT
                if (scriptData->savedScript.ptr == NULL) {
                    // DS: Assert(FALSE, "Script return stack error");
                    return 0;
                }

                scriptData->script = scriptData->savedScript;
                scriptData->savedScript.ptr = NULL;
                scriptData->savedScript.ptr2 = NULL;
                break;
            }
            case CMD_BYTE_EF: // RET
                // DS: if (scriptData->savedScript.ptr != NULL) Assert(FALSE, "Script end stack error");
                return 0;
            case CMD_BYTE_F0: // HALT
                return 1;
            case CMD_BYTE_F1: // END_DELETE
                return 4; // fatal error?
            case CMD_BYTE_F2: // CMD_F2
            case CMD_BYTE_F3: // CMD_F3
            case CMD_BYTE_F4: // LABEL
            case CMD_BYTE_F5: // CMD_F5
            case CMD_BYTE_F6: { // DEBUGINFO
                // Debug, not in release ROM
                break;
            }
        }
    }
}

UNUSED static u32 sub_80A1440(s32 r0, s32 r1, s32 r2)
{
   return sub_80A14E8(NULL, r0, r1, r2);
}

UNUSED static bool8 GroundScript_ExecuteTrigger(s16 scriptID)
{
    s32 ret;
    ScriptInfoSmall scriptInfo;
    Action action;
    const ScriptRef *ptr;

    ptr = &gFunctionScriptTable[scriptID];

    if (ptr->type != 11)
        return FALSE;

    InitActionWithParams(&action, &sNullCallbackData, NULL, 0, 0);
    GetFunctionScript(NULL, &scriptInfo, scriptID);
    GroundScript_ExecutePP(&action, NULL, &scriptInfo, DEBUG_LOC_PTR("../ground/ground_script.c", 4553, "GroundScript_ExecuteTrigger"));

    action.scriptData.savedScript = action.scriptData.script;
    action.scriptData.savedScript.ptr = gUnknown_81164E4;
    action.scriptData.savedScript.ptr2 = gUnknown_81164E4;
    ret = HandleAction(&action, DEBUG_LOC_PTR("../ground/ground_script.c", 4558, "GroundScript_ExecuteTrigger"));
    InitAction2(&action);

    if (ret == 0)
        return TRUE;

    return FALSE;
}

static s32 sub_80A14E8(Action *action, u8 idx, u32 r2, s32 r3)
{
    switch(idx)
    {
        case 1:
            sub_8098C58();
            return 0;
        case 2:
            if(sub_8011C34() == -1)
                sub_8011C40(Rand32Bit());
            sub_8011C28(1);
            sub_8001064();
            sub_809965C();
            return 0;
        case 3:
            sub_8098CC8();
            return 0;
        case 4:
            return sub_80961D8() == 0 ? 0 : 1;
        case 5:
            ResetMailbox();
            return 0;
        case 6:
            sub_80963FC();
            return 0;
        case 7:
            sub_8096488();
            return 0;
        case 8:
            return sub_80964B4() == 0 ? 0 : 1;
        case 9:
            {
                u8 var;
                if (CheckQuest(QUEST_CAN_CHANGE_LEADER) == 0) {
                    var = sub_808D4B0();
                }
                else {
                    var =  sub_808D500();
                }
                nullsub_104();
                return var != 0;
            }
            break;
        case 0xA:
            {
                if ((action->unkC).unk0 == 1)
                {
                    u8 text[0x100];
                    DungeonLocation dungLocation;
                    s32 ret = (s16) sub_80A8C4C(action->unkC.unk2, &dungLocation);
                    if (ret != 0)
                    {
                        s32 dialogueId;
                        if (dungLocation.id == DUNGEON_HOWLING_FOREST_2 && ret == 0x104) {
                            return 2;
                        }

                        dialogueId = GetFriendAreaDialogueId(action->unkC.unk2);
                        InlineStrcpy(text, gFriendAreaDialogue[dialogueId]);
                        if (ScriptPrintText(0, 1, text) != 0)
                            return 1;
                    }
                }
            }
            return 0;
        case 0xB:
            return (CountJobsinDungeon(ScriptDungeonIdToDungeonId(GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX))) > 0);
        case 0xC:
            {
                u8 sp_104;
                if(sub_8099394(&sp_104) != 0)
                {
                    unkStruct_203B480 *p = gUnknown_203B480;
                    p += sp_104;
                    if(p->rescuesAllowed > 0)
                        return 1;
                }
            }
            return 0;
        case 0xD:
            return sub_8097640() ? 1 : 0;
            break;
        case 0xE:
            {
                s32 index;
                for(index = 0x11; index < NUM_DUNGEON_MAZE; index++)
                {
                    if (IsMazeCompleted((s16) index)) {
                        if (!GetScriptVarArrayValue(0, TRAINING_PRESENT_LIST, (u16) index)) {
                            SetScriptVarArrayValue(NULL, TRAINING_PRESENT_LIST, (u16) index, 1);
                            return index - 0x10;
                        }
                    }
                }
                return 0;
            }
        case 0xF:
            return sub_80964E4() == 0 ? 0 : 1;
        case 0x10:
            if(action->unk8.unk0 == 1)
                if(action->unk8.unk2 == 0)
                    if(action->unkC.unk0 == 1)
                    {
                        if(sub_80A87E0(action->unk8.unk2, sub_80A8E9C(action->unkC.unk2)) != 0)
                            return 1;
                    }
            return 0;
        case 0x11:
            return sub_80A8D20() != FALSE;
        case 0x12:
            {
                s32 held = gRealInputs.held;
                if((held & (R_BUTTON | L_BUTTON)))
                    return 1;
                else
                    return 0;
            }

        case 0x13:
            {
                Pokemon *ptr = sub_80A8D54((s16) r2);
                if (ptr)
                    return PokemonFlag2(ptr);
            }
            return 0;
        case 0x14:
            if(action->unk8.unk0 == 1)  {
                if(GetCanMoveFlag(sub_80A8BFC(action->unk8.unk2)))
                    return 1;
            }
            return 0;
        case 0x15:
            {
                s32 r4;
                PixelPos sp_318;
                PixelPos sp_320;
                s32 r5 = (s16) sub_80A7AE8(r2);
                if(r5 >= 0) {
                    r4 = (r3 << 8);
                    action->callbacks->getHitboxCenter(action->parentObject, &sp_318);
                    sub_80A8FD8(r5, &sp_320);

                    if(sp_318.x - r4 <= sp_320.x
                        && sp_318.x + r4 >= sp_320.x
                        && sp_318.y - r4 <= sp_320.y
                        && sp_318.y + r4 >= sp_320.y)
                    {
                        return 1;
                    }
                }
            }
            return 0;
        case 0x16:
            {
                s32 index;
                Pokemon *ptr; ptr = sub_80A8D54(1);
                if(ptr)
                {
                    for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                    {
                        ptr->name[index] = 0;
                    }
                    return 1;
                }
            }
            return 0;
        case 0x17:
            UnlockFriendArea(WILD_PLAINS);
            UnlockFriendArea(MIST_RISE_FOREST);
            return 0;
        case 0x18:
            sub_80A8F50(sPokeNameBuffer, 0x3C, POKEMON_NAME_LENGTH);
            return 0;
        case 0x19:
            UnlockFriendArea(GetFriendArea(MONSTER_MAGNEMITE));
            {
                struct StoryMonData magnemiteData = {
                    .name = sPokeNameBuffer,
                    .speciesNum = MONSTER_MAGNEMITE,
                    .itemID = ITEM_NOTHING,
                    .dungeonLocation = {.id = DUNGEON_POKEMON_SQUARE_2, .floor = 0},
                    .moveID = {MOVE_METAL_SOUND, MOVE_TACKLE, MOVE_THUNDERSHOCK, MOVE_NOTHING},
                    .pokeHP = 38,
                    .level = 6,
                    .IQ = 1,
                    .offenseAtk = {20, 18},
                    .offenseDef = {20, 18},
                    .currExp = 4560,
                };
                Pokemon magnemiteMon;
                Pokemon *recruitPtr;
                s32 index;

                ConvertStoryMonToPokemon(&magnemiteMon, &magnemiteData);
                recruitPtr = TryAddPokemonToRecruited(&magnemiteMon);
                if (recruitPtr == NULL)
                    return 1;
                for (index = 0; index < POKEMON_NAME_LENGTH; index++) {
                    recruitPtr->name[index] = sPokeNameBuffer[index];
                }
                StrncpyCustom(gFormatBuffer_Names[r2], sPokeNameBuffer, POKEMON_NAME_LENGTH);
                IncrementAdventureNumJoined();
                return 0;
            }
            break;
        case 0x1A:
            sub_80A8F50(sPokeNameBuffer, 0x53, POKEMON_NAME_LENGTH);
            return 0;
        case 0x1B:
             UnlockFriendArea(GetFriendArea(MONSTER_ABSOL));
             {
                Pokemon *recruitPtr;
                struct StoryMonData absolData = {
                    .name = sPokeNameBuffer,
                    .speciesNum = MONSTER_ABSOL,
                    .itemID = ITEM_NOTHING,
                    .dungeonLocation = {.id = DUNGEON_FROSTY_GROTTO_2, .floor = 0},
                    .moveID = {MOVE_SCRATCH, MOVE_LEER, MOVE_TAUNT, MOVE_QUICK_ATTACK},
                    .pokeHP = 80,
                    .level = 20,
                    .IQ = 1,
                    .offenseAtk = {33, 32},
                    .offenseDef = {31, 32},
                    .currExp = 43000,
                };
                Pokemon absolMon;

                ConvertStoryMonToPokemon(&absolMon, &absolData);
                recruitPtr = TryAddPokemonToRecruited(&absolMon);
                if (recruitPtr == NULL)
                    return 1;
                IncrementAdventureNumJoined();
                recruitPtr->flags |= POKEMON_FLAG_ON_TEAM;
                return 0;
             }
        case 0x1C:
            {
                Pokemon *pokemon = GetRecruitedMonBySpecies(MONSTER_ABSOL, 0);
                if (pokemon == NULL)
                    return 1;
                pokemon->flags |= POKEMON_FLAG_ON_TEAM;
                return 0;
            }
        case 0x1D:
            {
                if( sub_808D278(MONSTER_SMEARGLE) == 0)
                    return 1;
                else
                    return 0;
            }
        case 0x1E:
             sub_80A8F50(sPokeNameBuffer, 124, POKEMON_NAME_LENGTH);
             return 0;

        case 0x1F:
            {
                Pokemon *recruitPtr;
                s32 index;
                struct StoryMonData smeargleData = {
                    .name = sPokeNameBuffer,
                    .speciesNum = MONSTER_SMEARGLE,
                    .itemID = ITEM_NOTHING,
                    .dungeonLocation = {.id = DUNGEON_HOWLING_FOREST_2, .floor = 0},
                    .moveID = {MOVE_SKETCH, MOVE_NOTHING, MOVE_NOTHING, MOVE_NOTHING},
                    .pokeHP = 47,
                    .level = 5,
                    .IQ = 1,
                    .offenseAtk = {16, 20},
                    .offenseDef = {20, 16},
                    .currExp = 1600,
                };
                Pokemon smeargleMon;

                ConvertStoryMonToPokemon(&smeargleMon, &smeargleData);
                recruitPtr = TryAddPokemonToRecruited(&smeargleMon);
                if (!recruitPtr)
                    return 1;
                for (index = 0; index < POKEMON_NAME_LENGTH; index++) {
                    recruitPtr->name[index] = sPokeNameBuffer[index];
                }
                StrncpyCustom(gFormatBuffer_Names[r2], sPokeNameBuffer, POKEMON_NAME_LENGTH);
                IncrementAdventureNumJoined();
                return 0;
            }
            break;
        case 0x20:
            ScriptUnlockFriendArea(MAP_FRIEND_AREA_LEGENDARY_ISLAND, TRUE);
            if (GetRecruitedMonBySpecies(MONSTER_ZAPDOS, 0) == NULL) {
                static const DungeonLocation zapdosLoc = {.id = DUNGEON_MT_THUNDER_PEAK, .floor = 99};
                if (TryAddLevel1PokemonToRecruited(MONSTER_ZAPDOS, NULL, ITEM_NOTHING, &zapdosLoc, NULL))
                    IncrementAdventureNumJoined();
            }
            if (GetRecruitedMonBySpecies(MONSTER_MOLTRES, 0) == NULL) {
                static const DungeonLocation moltresLoc = {.id = DUNGEON_MT_BLAZE_PEAK, .floor = 99};
                if (TryAddLevel1PokemonToRecruited(MONSTER_MOLTRES, NULL, ITEM_NOTHING, &moltresLoc, NULL))
                    IncrementAdventureNumJoined();
            }
            if (GetRecruitedMonBySpecies(MONSTER_ARTICUNO, 0) == NULL) {
                static const DungeonLocation articunoLoc = {.id = DUNGEON_FROSTY_GROTTO, .floor = 99};
                if (TryAddLevel1PokemonToRecruited(MONSTER_ARTICUNO, NULL, ITEM_NOTHING, &articunoLoc, NULL))
                    IncrementAdventureNumJoined();
            }
            return 0;
        case 0x21:
            if (HasRecruitedMon(MONSTER_ARTICUNO) && HasRecruitedMon(MONSTER_ZAPDOS) && HasRecruitedMon(MONSTER_MOLTRES))
                return 1;
            return 0;
        case 0x22:
            {
                Pokemon *pokemon = GetLeaderMon1();

                if (pokemon->speciesNum != MONSTER_ARTICUNO && pokemon->speciesNum != MONSTER_ZAPDOS && pokemon->speciesNum != MONSTER_MOLTRES)
                    return 1;
            }
            return 0;
         case 0x23:
            {
                Pokemon *pokemon;
                pokemon = GetLeaderMon1();
                if (pokemon != NULL && pokemon->speciesNum == MONSTER_HO_OH)
                    return 2;
                else if (GetMonSeenFlag(MONSTER_HO_OH))
                    return 1;
            }
            return 0;
        case 0x24:
            sub_80A8F50(sPokeNameBuffer, 0x79, POKEMON_NAME_LENGTH);
            return 0;

        case 0x25:
            if (!GetFriendAreaStatus(GetFriendArea(MONSTER_LATIOS)))
                UnlockFriendArea(GetFriendArea(MONSTER_LATIOS));
            {
                Pokemon *recruitPtr;
                s32 index;
                struct StoryMonData latiosData = {
                    .name = sPokeNameBuffer,
                    .speciesNum = MONSTER_LATIOS,
                    .itemID = ITEM_NOTHING,
                    .dungeonLocation = {.id = DUNGEON_POKEMON_SQUARE, .floor = 0},
                    .moveID = {MOVE_PSYWAVE, MOVE_MEMENTO, MOVE_HELPING_HAND, MOVE_SAFEGUARD},
                    .pokeHP = 125,
                    .level = 30,
                    .IQ = 1,
                    .offenseAtk = {60, 59},
                    .offenseDef = {42, 44},
                    .currExp = 273400,
                };
                Pokemon latiosMon;

                ConvertStoryMonToPokemon(&latiosMon, &latiosData);
                recruitPtr = TryAddPokemonToRecruited(&latiosMon);
                if (recruitPtr == NULL)
                    return 1;
                for (index = 0; index < POKEMON_NAME_LENGTH; index++) {
                    recruitPtr->name[index] = sPokeNameBuffer[index];
                }
                IncrementAdventureNumJoined();
                return 0;
            }

            break;
        case 0x26:
            sub_80A8F50(sPokeNameBuffer, 0x7A, POKEMON_NAME_LENGTH);
            return 0;
        case 0x27:
            {
                Pokemon *recruitPtr;
                s32 index;
                struct StoryMonData latiasData = {
                    .name = sPokeNameBuffer,
                    .speciesNum = MONSTER_LATIAS,
                    .itemID = ITEM_NOTHING,
                    .dungeonLocation = {.id = DUNGEON_POKEMON_SQUARE, .floor = 0},
                    .moveID = {MOVE_PSYWAVE, MOVE_WISH, MOVE_HELPING_HAND, MOVE_SAFEGUARD},
                    .pokeHP = 120,
                    .level = 28,
                    .IQ = 1,
                    .offenseAtk = {58, 57},
                    .offenseDef = {40, 43},
                    .currExp = 245400,
                };
                Pokemon latiasMon;

                ConvertStoryMonToPokemon(&latiasMon, &latiasData);
                recruitPtr = TryAddPokemonToRecruited(&latiasMon);
                if (recruitPtr == NULL)
                    return 1;
                for (index = 0; index < POKEMON_NAME_LENGTH; index++) {
                    recruitPtr->name[index] = sPokeNameBuffer[index];
                }
                IncrementAdventureNumJoined();
                return 0;
            }
            break;

        case 0x28:
            {
                static const Item item = {.flags = 0, .quantity = 0, .id = ITEM_WISH_STONE};
                if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                    if (IsNotMoneyOrUsedTMItem(item.id) && gTeamInventoryRef->teamStorage[item.id] < 999)
                        gTeamInventoryRef->teamStorage[item.id] += 1;

                }
                else {
                    AddItemIdToInventory(item.id, FALSE);
                    FillInventoryGaps();
                }
                return 0;
            }
        case 0x29:
            {
                s32 index = (s16)(RandInt(0x1A2) + 1);
                s32 r4 = RandInt(0x20);
                s32 r7 = 0x1A4;
                s32 r6 = 0;

                while (1)
                {
                    s16 indexS16;
                    index = (s16)(index + 1);
                    if (index >= 0x1a4) {
                        index = 1;
                    }
                    if (--r7 < 0) {
                        if (r6 == 0) {
                            SetScriptVarValue(NULL, NEW_FRIEND_KIND, 0);
                            return 0;
                        }
                        if (r4 >= r6) {
                            r4 = RandInt(r6);
                            r7 = 0x1A4;
                        }
                    }
                    // S16 memes AGAIN...
                    indexS16 = index;
                    index = indexS16;
                    if (indexS16 == MONSTER_ARTICUNO || indexS16 == MONSTER_ZAPDOS || indexS16 == MONSTER_MOLTRES
                        || indexS16 == MONSTER_GROUDON
                        || indexS16 == MONSTER_RAYQUAZA
                        || indexS16 == MONSTER_RAYQUAZA_CUTSCENE
                        || indexS16 == MONSTER_KYOGRE
                        || indexS16 == MONSTER_LUGIA
                        || indexS16 == MONSTER_CASTFORM_SNOWY
                        || indexS16 == MONSTER_CASTFORM_SUNNY
                        || indexS16 == MONSTER_CASTFORM_RAINY
                        || indexS16 == MONSTER_DEOXYS_NORMAL
                        || indexS16 == MONSTER_DEOXYS_ATTACK
                        || indexS16 == MONSTER_DEOXYS_DEFENSE
                        || indexS16 == MONSTER_DEOXYS_SPEED
                        || indexS16 == MONSTER_MEWTWO
                        || indexS16 == MONSTER_JIRACHI
                        || indexS16 == MONSTER_MEW
                        || indexS16 == MONSTER_LATIAS
                        || indexS16 == MONSTER_LATIOS
                        || indexS16 == MONSTER_ENTEI
                        || indexS16 == MONSTER_RAIKOU
                        || indexS16 == MONSTER_SUICUNE
                        || indexS16 == MONSTER_HO_OH
                        || indexS16 == MONSTER_REGIROCK
                        || indexS16 == MONSTER_REGICE
                        || indexS16 == MONSTER_REGISTEEL
                        || indexS16 == MONSTER_CELEBI
                        )
                        continue;
                    if(!IsExclusivePokemonUnlocked(index)) continue;
                    if(GetFriendAreaStatus(GetFriendArea(index))) {
                        if(HasRecruitedMon(index)) continue;
                        if(sub_808D278(index) == 0) continue;
                    }

                    r6++;
                    r4--;
                    if (r4 < 0)
                        break;
                }

                SetScriptVarValue(NULL, NEW_FRIEND_KIND, index);
                WriteFriendAreaName(gFormatBuffer_FriendArea, GetFriendArea(index), FALSE);
                if (GetFriendAreaStatus(GetFriendArea(index)) != 0)
                    return 1;
                else
                    return 2;
            }
        case 0x2A:
            {
                s32 id = (s16) GetScriptVarValue(NULL, NEW_FRIEND_KIND);
                WriteFriendAreaName(gFormatBuffer_FriendArea,(GetFriendArea(id)), FALSE);
                if (id == 0)
                    return 0;
                else if(GetFriendAreaStatus(GetFriendArea(id)) != 0)
                   return 1;
                else
                   return 2;
            }
            break;
        case 0x2B:
            sub_80A8F50(sPokeNameBuffer, 0x20, POKEMON_NAME_LENGTH);
            return 0;
        case 0x2C:
            {
                Pokemon *recruitPtr;
                s32 index;
                if (r2 != 0) {
                    static const DungeonLocation dungLoc = {.id = DUNGEON_RESCUE_TEAM_BASE_2, .floor = 0};
                    s32 id = (s16) GetScriptVarValue(NULL, NEW_FRIEND_KIND);
                    s32 id_ = id;
                    WriteFriendAreaName(gFormatBuffer_FriendArea,(GetFriendArea((s16)id)), FALSE);
                    if (id == 0)
                        return 0;

                    if (!GetFriendAreaStatus(GetFriendArea(id)))
                        UnlockFriendArea(GetFriendArea(id));

                    recruitPtr = TryAddLevel1PokemonToRecruited(id_, NULL ,ITEM_NOTHING, &dungLoc, MOVE_NOTHING);
                    if (recruitPtr == NULL)
                        return 0;

                    for (index = 0; index < POKEMON_NAME_LENGTH; index++)
                        recruitPtr->name[index] = sPokeNameBuffer[index];
                    IncrementAdventureNumJoined();
                    return 1;
                }
                else {
                    SetScriptVarValue(NULL, NEW_FRIEND_KIND, 0);
                    return 0;
                }
            }

        case 0x2D:
            if(GetPtsToNextRank() > 0)
                return 1;
            else
                return 0;
        case 0x2E:
            {
                s32 rankBefore = GetRescueTeamRank();
                s32 points = GetPtsToNextRank();
                if (points > 0) {
                    s32 rankAfter;
                    AddToTeamRankPts(points);
                    rankAfter = GetRescueTeamRank();
                    InlineStrcpy(gFormatBuffer_Items[0], GetTeamRankString(rankBefore));
                    InlineStrcpy(gFormatBuffer_Items[1], GetTeamRankString(rankAfter));
                    if (ScriptPrintText(0, -1, _("{CENTER_ALIGN}The rescue rank went up from\n{CENTER_ALIGN}{MOVE_ITEM_0} to {MOVE_ITEM_1}!")) != 0)
                        return 1;
                }
                else {
                    return 0;
                }
            }
        // breakthrough
        case 0x2F:
            AddToTeamMoney(10000);
            return 0;
        case 0x30: { // Checks if Gardevoir can join the party (if it has space in its friend area)
            if (sub_808D278(MONSTER_GARDEVOIR) == NULL)
                return 1;
            return 0;
        }
        case 0x31: { // Sets Gardevoir's name
            sub_80A8F50(sPokeNameBuffer, 82, POKEMON_NAME_LENGTH);
            return 0;
        }
        case 0x32: { // Tries to recruit Gardevoir
            struct StoryMonData gardevoirData = {
                .name = sPokeNameBuffer,
                .speciesNum = MONSTER_GARDEVOIR,
                .itemID = ITEM_NOTHING,
                .dungeonLocation = {.id = DUNGEON_RESCUE_TEAM_BASE_2, .floor = 0},
                .moveID = {MOVE_CONFUSION, MOVE_DOUBLE_TEAM, MOVE_TELEPORT, MOVE_GROWL},
                .pokeHP = 53,
                .level = 5,
                .IQ = 1,
                .offenseAtk = {18, 18},
                .offenseDef = {11, 10},
                .currExp = 2800,
            };
            Pokemon gardevoirMon;

            ConvertStoryMonToPokemon(&gardevoirMon, &gardevoirData);
            if (TryAddPokemonToRecruited(&gardevoirMon) == NULL)
                return 1;

            IncrementAdventureNumJoined();
            return 0;
        }
        case 0x33:
            if (ScriptVarScenarioAfter(SCENARIO_MAIN, 0x12, -1)
               && GetScriptVarValue(NULL, GROUND_GETOUT) != 4
               && GetScriptVarArrayValue(0, EVENT_GONBE, 0) <= 0)
            {
                if (OtherRandInt(0x100) == 0) {
                    SetScriptVarArrayValue(NULL, EVENT_GONBE, 0, 4);
                    return 1;
                }
                else {
                    SetScriptVarArrayValue(NULL, EVENT_GONBE, 0, 1);
                }
            }
            return 0;
        case 0x34:
            {
                s32 i;
                static const Item appleItem = {.flags = 0, .quantity = 0, .id = ITEM_APPLE};
                for (i = 0; i < 3; i++) {
                    if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                        if (IsNotMoneyOrUsedTMItem(appleItem.id) && gTeamInventoryRef->teamStorage[appleItem.id] < 999)
                            gTeamInventoryRef->teamStorage[appleItem.id] += 1;

                    }
                    else {
                        AddItemIdToInventory(appleItem.id, 0);
                        FillInventoryGaps();
                    }
                }
            }
            return 0;
        case 0x35:
            {
                Pokemon *pokemon = GetLeaderMon1();
                if(pokemon != NULL && pokemon->speciesNum == MONSTER_CHANSEY)
                    return 2;
                else
                    if(GetMonSeenFlag(MONSTER_CHANSEY))
                        return 1;
                    else
                        return 0;
            }
            break;

        case 0x38:
            sub_80A56A0(0, 1);
            return 0;
        case 0x36: {
            PixelPos sp_328;
            sp_328.x = r2;
            sp_328.y = r3;
            sub_80A56F0(&sp_328);
            return 0;
        }
        case 0x37: {
            PixelPos sp_330;
            sp_330.x = r2;
            sp_330.y = r3;
            sub_80A5704(&sp_330);
            return 0;
        }
        case 0x39:
            sub_809C6CC(r2);
            return 0;
        case 0x3A:
            sub_809C6EC();
            return 0;
        case 0x3B:
            sub_809C760();
            return 0;
        case 0x3C:
            {
                s32 index;
                for (index = 0; index < 0x18; index = (s16)(index + 1)) {
                    sub_80A86C8(index, 0x400000);
                }
                for (index = 0; index < 0x10; index = (s16)(index + 1)) {
                    sub_80AC1B0(index, 0x400000);
                }
                for (index = 0; index < 0x10; index = (s16)(index + 1)) {
                    sub_80AD0C8(index, 0x400000);
                }
            }
            return 0;
        case 0x3D: {
            PixelPos sp_338 = {r2, r3};

            sub_80A59A0(0, &sp_338, sub_80A5984(1, &sp_338));
            return 0;
        }
        case 0x3E:
            {
                s32 ret;
                Action *r7;
                GroundEffectData sp_308;
                PixelPos sp_340;
                PixelPos sp_348;
                PixelPos sp_350;
                PixelPos sp_358;

                sp_308.kind = 1;
                sp_308.unk1 = 0;
                sp_308.width = 1;
                sp_308.height = 1;
                sp_308.pos = (CompactPos) {0};
                sp_308.script = gFunctionScriptTable[MOVE_DEBUG_CAMERA].script;
                ret = (s16) GroundEffect_Add(-1, &sp_308, (s16) r2, (s8) r3);
                if(ret < 0) break;
                r7 = sub_80AD158(ret);
                sub_80A579C(&sp_340, &sp_348);
                sp_340.y += 0xC00;
                sp_348.y += 0xC00;
                action->callbacks->getHitboxCenter(action->parentObject, &sp_350);
                if(sp_350.x < sp_340.x)
                    sp_350.x = sp_340.x;
                else if (sp_350.x >= sp_348.x)
                    sp_350.x = sp_348.x - 1;
                if(sp_350.y < sp_340.y)
                    sp_350.y = sp_340.y;
                else if (sp_350.y >= sp_348.y)
                    sp_350.y = sp_348.y - 1;

                sp_340.x -= 1024;
                sp_340.y -= 1024;
                sp_348.x += 1024;
                sp_348.y += 1024;

                r7->callbacks->setPositionBounds(r7->parentObject, &sp_340, &sp_348);
                r7->callbacks->moveReal(r7->parentObject, &sp_350);
                sp_358 = (PixelPos) {0};
                r7->callbacks->moveRelative(r7->parentObject, &sp_358);
                return 1;
            }
            break;

        case 0x3F:
            {
                s32 index;
                s32 held = gRealInputs.held;
                s32 pressed = gRealInputs.pressed;
                if(!(pressed & (START_BUTTON | SELECT_BUTTON)))
                {
                    PixelPos sp_368;
                    s32 dir = DpadToDirection(held);
                    if((s8)dir != -1)
                    {
                        s32 to;
                        sp_368 = SetVecFromDirectionSpeed((s8) dir,0x100);

                        to = 2;
                        if(held & B_BUTTON) {
                            to = 4;
                        }

                        for(index = 0; index < to; index++)
                        {
                            if(action->callbacks->moveRelative(action->parentObject, &sp_368) != 0)
                            {
                                PixelPos pixelPos = {0, sp_368.y};
                                if(action->callbacks->moveRelative(action->parentObject, &pixelPos) != 0)
                                {
                                    PixelPos pixelPos = {sp_368.x, 0};
                                    action->callbacks->moveRelative(action->parentObject, &pixelPos);
                                }
                            }
                        }
                    }
                    return -1;
                }
            }
            break;

        case 0x40:
            sub_80993C0(r2 == 0 ? 0 : 1);
            return 0;
        case 0x42:
            sub_8011C28(1);
            GroundMainGameEndRequest(r2);
            FadeOutAllMusic(r2);
            return 0;
        case 0x41:
            GroundMainGameEndRequest(r2);
            FadeOutAllMusic(r2);
            return 0;
        case 0x43:
            gUnknown_2039DA8 = GetCurrentBGSong();
            if(gUnknown_2039DA8 != STOP_BGM)
                return 1;
            return 0;
        case 0x44:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                StartNewBGM_(gUnknown_2039DA8);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x45:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                FadeInNewBGM_(gUnknown_2039DA8, r2);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x46:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                QueueBGM_(gUnknown_2039DA8);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x47:
            sub_80997F4(r2, r3);
            return 0;
        case 0x48:
            sub_80997F4(30, r2);
            return 0;
        case 0x49:
            GroundSprite_ExtendPaletteAdd(0, r2);
            return 0;
        case 0x4A:
            GroundSprite_ExtendPaletteDelete(0);
            return 0;
    }

    return 0;
}

void GroundScript_Unlock(void)
{
    s32 index;
    bool8 cond;

    if (gAnyScriptLocked == 0) return;

    gAnyScriptLocked = 0;
    index = 0;
    for (index = 0; index < SCRIPT_LOCKS_ARR_COUNT; index++) {
        if (gScriptLocks[index] != 0) {
            Log(1, "GroundScript unlock %3d", index);
            cond  = GroundMapNotifyAll((s16) index);
            cond |= GroundLivesNotifyAll((s16) index);
            cond |= GroundObjectsNotifyAll((s16) index);
            cond |= GroundEffectsNotifyAll((s16) index);

            if (gScriptLockConds[index] != 0) {
               if (cond) {
                    GroundMapNotifyAll((s16) (index | 0x80));
                    GroundLivesNotifyAll((s16) (index | 0x80));
                    GroundObjectsNotifyAll((s16) (index | 0x80));
                    GroundEffectsNotifyAll((s16) (index | 0x80));
                    gScriptLocks[index] = gScriptLockConds[index] = 0;
               }
            }
            else {
               gScriptLocks[index] = 0;
            }
        }
    }
}

static const ScriptCommand *FindLabel(Action *action, s32 labelNum)
{
    ScriptCommand script;
    const ScriptCommand *scriptPtr2;
    const ScriptCommand *scriptPtr;

    scriptPtr2 = action->scriptData.script.ptr2;
    scriptPtr = scriptPtr2 + 1;

    while (TRUE) {
        script = *scriptPtr;
        scriptPtr++;

        if (script.op == CMD_BYTE_F4 && labelNum == script.argShort)
            break;

        {
            UNUSED static const u8 maybeFuncName[] = "_SearchScriptLabel";
            UNUSED static const DebugLocation unusedDebugLoc = {"../ground/ground_script.c", 5822, maybeFuncName};
            UNUSED static const u8 scrLabelError[] = "Script label search error %d";
        }
        // DS: Assert(script.op != CMD_BYTE_00, "script search label error %d", label)
        // DS: Assert(script.op != CMD_BYTE_F6, "script search label error %d", label)
    }

    return scriptPtr;
}

static const ScriptCommand *ResolveJump(Action *action, s32 r1)
{
    ScriptCommand script;
    const ScriptCommand *scriptPtr;
    s32 temp;

    scriptPtr = action->scriptData.script.ptr;

    while (TRUE) {
        script = *scriptPtr;

        if (script.op == CMD_BYTE_CC) {
            if (FlagJudge(r1, script.arg1, JUDGE_EQ))
                return FindLabel(action, script.argShort);
        }
        else if (script.op == CMD_BYTE_CD) {
            if (FlagJudge(r1, script.arg1, script.argByte))
                return FindLabel(action, script.argShort);
        }
        else if (script.op == CMD_BYTE_CE) {
            temp = GetScriptVarValue(action->scriptData.localVars.buf, (s16)script.arg1);
            if (FlagJudge(r1, temp, script.argByte))
                return FindLabel(action, script.argShort);
        }
        else {
            return scriptPtr;
        }

        scriptPtr++;
    }
}

static void sub_80A2500(s32 param_1, ActionUnkIds *param_2)
{
    if (param_2->unk0 == 1) {
        sub_809AB4C((s16) param_1, (s16) sub_80A8BBC(param_2->unk2));
    }
}

static void sub_80A252C(s32 param_1, ActionUnkIds *param_2)
{
    if (param_2->unk0 == 1) {
        sub_809ABB4((s16) param_1, (s16) sub_80A8BBC(param_2->unk2));
    }
}

static void sub_80A2558(s32 param_1, ActionUnkIds *param_2)
{
    if (param_2->unk0 == 1) {
        sub_809AC18((s16) param_1, (s16) sub_80A8BBC(param_2->unk2));
    }
}

static void sub_80A2584(s16 r0, s16 r1)
{
    s32 iVar2 = r1;
    s32 iVar1 = r0;
    sub_809ABB4(iVar1, iVar2);
}

static void sub_80A2598(s16 r0, s16 r1)
{
    s32 iVar2 = r1;
    s32 iVar1 = r0;
    sub_809AC18(iVar1, iVar2);
}

static u32 sub_80A25AC(u16 param_1)
{
    if (sub_8098F88())
        return param_1;
    if (param_1 == 50)
        return 50;
    if (!CheckQuest(QUEST_UNK12))
        return 999;
    if (CheckQuest(QUEST_IN_WORLD_CALAMITY))
        return 19;
    if (param_1 != 1)
        return param_1;
    GetScriptVarValue(NULL, BASE_LEVEL); // wut???
    return 1;
}
