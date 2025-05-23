#include "global.h"
#include "ground_script.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/item.h"
#include "constants/monster.h"
#include "constants/move_id.h"
#include "code_8002774.h"
#include "code_80118A4.h"
#include "code_8099360.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_80972F4.h"
#include "code_8097670.h"
#include "code_80A26CC.h"
#include "debug.h"
#include "dungeon.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "ground_link.h"
#include "ground_lives.h"
#include "ground_main.h"
#include "ground_map.h"
#include "ground_map_1.h"
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


void GroundMap_Select(s16);
void GroundMap_SelectDungeon(s32, DungeonLocation*, u32);
void GroundMap_GetStationScript(ScriptInfoSmall *out, s16, s32, s32);
void GroundLives_ExecuteScript(s32, s16 *, ScriptInfoSmall *);
void GroundObject_ExecuteScript(s32, s16 *, ScriptInfoSmall *);
void GroundEffect_ExecuteScript(s32, s16 *, ScriptInfoSmall *);
void GroundLives_Select(s32, s32 group, s32 sector);
void GroundObject_Select(s32, s32 group, s32 sector);
void GroundEffect_Select(s32, s32 group, s32 sector);
void GroundEvent_Select(s32, s32 group, s32 sector);
void GroundLives_Cancel(s32 group, s32 sector);
void GroundObject_Cancel(s32 group, s32 sector);
void GroundEffect_Cancel(s32 group, s32 sector);
void GroundEvent_Cancel(s32 group, s32 sector);
void GroundLives_CancelBlank_1(void);
void GroundObject_CancelBlank(void);
void GroundEffect_CancelBlank(void);
void GroundWeather_Select(s16);
u32 GroundLives_ExecutePlayerScriptActionLives();
s16 GroundObject_Add(s16 id, GroundObjectData*, s16 group, s8 sector);
s16 GroundEffect_Add(s16 id, GroundEffectData*, s16 group, s8 sector);

// Beware of the declarations without specified arguments, returning u32 or s32, these were quickly hacked in to get the code to compile and link
// The return values are almost certainly NOT correct and will need to be rechecked when moving to header files
char sub_8002984(s32, u8);
bool8 sub_802FCF0(void);


void sub_809733C(s16, bool8);
void sub_80973A8(s16, bool8);
void sub_80975A8(s16, bool8);
u32 sub_80999E8();
void sub_80999FC(s32);
u32 sub_8099A10();
u32 sub_8099A34();
u32 sub_8099A48();
u32 sub_809A6E4();
u32 sub_809A6F8();
u32 sub_809A738();
u32 sub_809A768();
bool8 ScriptPrintNullTextbox(void);
bool8 ScriptPrintEmptyTextbox(void);
void sub_809A83C(s16);
u32 sub_809AC7C();
u32 sub_809ADD8();
bool8 ScriptPrintText(s32, s16, const char*);
bool8 sub_809AEEC(const char*);
bool8 sub_809AF2C(const char*);
bool8 sub_809AF6C(s16, const char*);
void sub_809AFC8(bool8, s32, s32, const char*);
u32 sub_809B028(const MenuItem *, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text);
bool8 sub_809B1C0(s32, s32, char[12]);
void sub_809B1D4(u8, s32, s32, const char*);
void sub_809C770(s16, s16);
s32 HasItemInInventory(u8);
u32 sub_809CC90();
void sub_809D0BC(void);
void sub_809D124(s32, s32, s32);
void sub_809D158(s32, PixelPos*);
void sub_809D170(s32, s32);
void sub_809D190(s32, PixelPos*, s32);
void sub_809D1A8(s32, s32, s32);
void sub_809D1CC(s32, PixelPos*, s32);
void sub_809D1E4(s32, s32, s32);
void sub_809D208(s32, PixelPos*, s32);
void sub_809D220(s32, s32, s32);
void GroundScriptLockJumpZero(s16);
s16 GetAdjustedGroundMap(s32);
void sub_80A87AC(s32, s32);
void sub_80A8BD8(s16, s32*);
u32 sub_80A8C2C();
u32 GroundLives_IsStarterMon();
PokemonStruct1 *sub_80A8D54(s16);
s16 sub_80A8F9C(s32, PixelPos*);
u32 sub_80A9050();
u32 sub_80A9090();
s16 sub_80AC448(s16, PixelPos*);
s32 sub_80AC49C(s16, PixelPos*);
s16 sub_80AD360(s16, PixelPos*);
s16 sub_80AD3B4(s16, PixelPos*);
void DeleteGroundEvents(void);
void DeleteGroundLives(void);
void DeleteGroundObjects(void);
void DeleteGroundEffects(void);
s32 ExecuteScriptCommand(Action *action);
bool8 IsFanfareSEPlaying_1(u16 songIndex);
bool8 IsEqualtoBGTrack(u16 songIndex);
bool8 sub_8099B94(void);
PixelPos SetVecFromDirectionSpeed(s8, s32);
bool8 sub_8098DCC(u32 speed);
extern const PixelPos gUnknown_81164DC;
extern u32 gUnknown_2039DA4;
extern char *gUnknown_203B4B0;
extern char gUnknown_2039D98[10];
void sub_8099220(void *param_1, s32 param_2);
extern u32 gUnlockBranchLabels[];
s16 sub_8002694(u8 param_1); // value -> GroundEnter lookup
bool8 sub_809B260(void *dst);
bool8 sub_809B18C(s32 *sp);
bool8 sub_809AFFC(u8 *);
bool8 sub_809D234(void);
s32 sub_80A14E8(Action *, u8, u32, s32);
u8 sub_80990EC(struct unkStruct_20398C8 *param_1, s32 param_2);

extern s16 gCurrentMap;
extern s16 gUnknown_2039A32;
extern s16 gUnknown_2039A34;

extern MenuItem gChoices[9];

extern char gUnknown_81165D4[];
extern char gUnknown_81165F4[];
extern char gUnknown_811660C[];
extern char gUnknown_8116628[];
extern char gUnknown_8116644[];
extern char gUnknown_8116664[];
extern char gUnknown_8116684[];
extern char gUnknown_81166C0[];
extern char gUnknown_81166D8[];

extern const CallbackData gGroundScriptTriggerCallbacks;
extern DebugLocation gUnknown_81166B4;
extern DebugLocation gUnknown_81166F8;
extern DebugLocation gUnknown_8116704;
extern ScriptCommand gUnknown_81164E4;

extern u8 gAnyScriptLocked;
extern u8 gScriptLocks[];
extern u8 gScriptLockConds[];

extern const DebugLocation gUnknown_8116588;
extern const DebugLocation gUnknown_8116538;
extern const DebugLocation gUnknown_8116560;
extern u8 gUnknown_8116594[];
extern u8 gUnknown_8116544[];
extern u8 gUnknown_811656C[];

extern DebugLocation gUnknown_81165C8;

extern void sub_809D520(void *);
extern u8 GroundObjectsCancellAll(void);
extern u8 GroundEffectsCancelAll(void);
extern u8 GroundLivesCancelAll(void);
extern u8 IsTextboxOpen_809A750(void);
extern Action *sub_80A882C(s16);
extern Action *sub_80AC240(s16);
extern Action *sub_80AD158(s16);

extern u8 gUnknown_8116848[];

bool8 GroundLivesNotifyAll(s16);
bool8 GroundObjectsNotifyAll(s16);
bool8 GroundEffectsNotifyAll(s16);

void sub_8098C58(void);
void sub_8098CC8(void);
bool8 sub_80961D8(void);
void ResetMailbox(void);
void sub_80963FC(void);
void sub_8096488(void);
bool8 sub_80964B4(void);
extern void nullsub_104(void);
s16 sub_80A8C4C();
s16 sub_80A90C8();
bool8 sub_8097640();
u8 sub_80964E4();
s32 sub_80A8E9C();
u8 sub_80A8D20();
bool8 sub_80A87E0();
s16 sub_80A8BFC(s16);
void sub_80A8F50(const u8 *buffer, s32, s32 size);

extern const u8 *gFriendAreaDialogue[];
extern struct unkStruct_808D144 gUnknown_8116710;
extern struct unkStruct_808D144 gUnknown_8116760;
extern struct unkStruct_808D144 gUnknown_8116794;
extern struct unkStruct_808D144 gUnknown_81167BC;
extern struct unkStruct_808D144 gUnknown_8116738;
extern struct unkStruct_808D144 gUnknown_811681C;
extern DungeonLocation gUnknown_81167E8;
extern DungeonLocation gUnknown_8116788;
extern DungeonLocation gUnknown_811678C;
extern DungeonLocation gUnknown_8116790;
extern u16 gUnknown_2039DA8;

PokemonStruct1 *sub_808D2E8(s32 species, u8 *name, u32 _itemID, DungeonLocation *location, u16 *moveID);
bool8 HasRecruitedMon(s32 species);
extern Item gUnknown_8116844;
extern Item gUnknown_81167E4;
bool8 sub_809124C(u8 id, u8 param_3);
extern const u8 gUnknown_81167EC[];
void sub_80A56A0(s32, s32);
void sub_80A56F0(s32 *);
void sub_80A5704(s32 *);
void sub_809C760(void);
void sub_809C6EC(void);
void sub_809C6CC(u16 param_1);
void sub_80A86C8(s16, s32);
void sub_80AC1B0(s16, s32);
void sub_80AD0C8(s16, s32);
s32 sub_80A5984();
void sub_80A59A0(s32, s32 *, u16);
extern void sub_80997F4(u16, u16);
s32 sub_809CFE8(u16 param_1);
extern bool8 sub_80A579C(PixelPos *a0, PixelPos *a1);

EWRAM_INIT static int sNumChoices = 0;

// -1 didn't match
void sub_809D520(void *a0)
{
    u16 *ptr = a0;
    u16 v = 0xFFFF;
    *ptr = v;
}

Action *sub_809D52C(void *a0)
{
    s16 *ptr = a0;

    switch (ptr[0])
    {
    case 0: return 0;
    case 1: return sub_80A882C(ptr[1]);
    case 2: return sub_80AC240(ptr[1]);
    case 3: return sub_80AD158(ptr[1]);
    }
    return 0;
}

void InitScriptData(ScriptData *a0)
{
    s32 i;

    a0->state = -1;
    a0->savedState = 0;
    a0->script.ptr2 = 0;
    a0->script.ptr = 0;
    a0->savedScript.ptr2 = 0;
    a0->savedScript.ptr = 0;
    a0->curScriptOp = 0;
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

void InitAction(Action *a0)
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
    action->unk8[0] = callbacks->maybeId;

    if(callbacks->getIndex)
        action->unk8[1] = callbacks->getIndex(parent);
    else
        action->unk8[1] = 0;
}

void InitAction2(Action *action)
{
    InitAction(action);
}

UNUSED s16 sub_809D654(Action *action)
{
    return action->scriptData.savedState;
}

UNUSED s16 sub_809D65C(Action *action)
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

void SetPredefinedScript(Action *param_1, s16 index, ScriptCommand *param_3)
{
    param_1->predefinedScripts[index] = param_3;
}

bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s16 _index)
{
    const ScriptCommand *scriptPtr;
    s32 index = _index;

    scriptPtr = param_1->predefinedScripts[index];
    script->ptr = scriptPtr;
    script->state = index;
    script->group = param_1->group;
    script->sector = param_1->sector;
    return scriptPtr != NULL;
}

void GetFunctionScript(Action *param_1, ScriptInfoSmall *script, s16 index)
{
    s32 index_s32 = index;
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

bool8 ActionResetScriptDataForDeletion(Action *param_1, DebugLocation *unused)
{
    InitScriptData(&param_1->scriptData);
    InitScriptData(&param_1->scriptData2);
    param_1->scriptData.savedState = 4;
    return TRUE;
}

bool8 GroundScript_ExecutePP(Action *action, s32 *param_2, ScriptInfoSmall *param_3, const DebugLocation *unused)
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
                // "execute script type error B" at ../ground/ground_script.c:688
                FatalError(&gUnknown_8116538, gUnknown_8116544);
            }
            if (action->scriptData2.state != -1) {
                // "execute script type error C" at ../ground/ground_script.c:689
                FatalError(&gUnknown_8116560, gUnknown_811656C);
            }
            action->scriptData2 = action->scriptData;
            break;
        case 0:
            if (action->scriptData.state != 1) goto _0809D84A;
            action->scriptData2 = action->scriptData;
            break;
        case 1:
        _0809D84A:
            InitScriptData(&action->scriptData2);
            break;
        default:
            // "execute script type error %d" at ../ground/ground_script.c:708
            FatalError(&gUnknown_8116588, gUnknown_8116594, param_3->state);
    }
    InitScriptData(&action->scriptData);
    if (param_2 != NULL) {
        action->unkC.raw = param_2[0];
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

bool8 ExecutePredefinedScript(Action *param_1, s32 *param_2, s16 index, DebugLocation *debug)
{
    ScriptInfoSmall auStack28;

    GetPredefinedScript(param_1,&auStack28,index);
    return GroundScript_ExecutePP(param_1, param_2, &auStack28, debug);
}

u8 GroundScriptCheckLockCondition(Action *param_1, s16 param_2)
{
    s32 param_2_s32;

    param_2_s32 = param_2;

    if ((param_2 == 0) && (IsTextboxOpen_809A750() == 0)) {
        param_1->scriptData.script.ptr = ResolveJump(param_1, 0);
        return 0;
    }
    else {
        param_1->scriptData.unk22 = param_2_s32;
        param_1->scriptData.savedState = 2;
        gAnyScriptLocked = 1;
        return 1;
    }
}

bool8 GroundScript_Cancel(Action *r0)
{
    // NOTE: Will always return TRUE
    return ActionResetScriptDataForDeletion(r0, &gUnknown_81165C8);
}

u8 GroundCancelAllEntities(void)
{
    u8 ret;

    ret = GroundLivesCancelAll();
    ret |= GroundObjectsCancellAll();
    ret |= GroundEffectsCancelAll();
    return ret;
}

bool8 GroundScriptNotify(Action *param_1, s16 param_2)
{
    s16 sVar1;
    s16 sVar2;
    bool8 ret;

    s32 param_2_s16 = param_2;

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

bool8 GroundScriptLockCond(Action *param_1, s16 index, s32 param_3)
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

s16 HandleAction(Action *action, DebugLocation *debug)
{
    ScriptCommand cmd;

    if (action->scriptData.savedState) {
        bool8 loopContinue = TRUE;
        while (loopContinue) {
            switch (action->scriptData.savedState) {
                case 2: {
                    switch (action->scriptData.curScriptOp) {
                        // handled cases (all hex)
                        // 3, 4, 5, 6, 7, 22..28, 2c, 30..38, 39, 3a, 3b, 3c, 3d, 3e, 3f,
                        // 58..5b, 5d, 5e, 60, 61..67, 68, 69..6f, 70, 71..76, 77..7c, 7d..82, 83..88,
                        // 89, 8a, 8b..90, 91..95, 98, 99, 9b..a3, cf, d2..d8, da, db, dc, dd, de, df,
                        // e0, e1, e2, e3, e5
                        // other cases up to 0xf1 immediately break (which breaks again and loops for ExScrCmd)
                        case 0x58 ... 0x5b: case 0x5d: case 0x5e: case 0x60:
                        case 0x8b ... 0x90: case 0x98: case 0x99:
                        case 0xdb: case 0xdc: {
                            if (action->scriptData.unk2A > 0) {
                                action->scriptData.unk2A--;
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0xdd: {
                            if (action->callbacks->func4C_spriteRelatedCheck(action->parentObject)) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0xde: {
                            if (action->callbacks->func50_spriteRelated(action->parentObject)) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0x22 ... 0x28:
                        case 0xdf: {
                            if (sub_8099B94()) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0xe0: {
                            cmd = *action->scriptData.curPtr;
                            if (IsEqualtoBGTrack(cmd.argShort)) {
                                if (action->scriptData.unk2C++ < 10800) {
                                    loopContinue = FALSE;
                                }
                                else {
                                    action->scriptData.savedState = 3;
                                }
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0xe1: case 0xe2: {
                            cmd = *action->scriptData.curPtr;
                            if (IsFanfareSEPlaying_1(cmd.argShort)) {
                                if (action->scriptData.unk2C++ < 3600) {
                                    loopContinue = FALSE;
                                }
                                else {
                                    action->scriptData.savedState = 3;
                                }
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0x61 ... 0x67: {
                            PixelPos pos, pos2;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos);
                            pos2.x = action->scriptData.pos2.x - pos.x;
                            pos2.y = action->scriptData.pos2.y - pos.y;
                            sub_800290C(&pos2, action->scriptData.unk30);
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
                        case 0x69 ... 0x6f: {
                            PixelPos pos, pos2;
                            s32 res;
                            s32 dir, dirBefore;
                            s8 dirS8;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos);
                            pos2.x = action->scriptData.pos2.x - pos.x;
                            pos2.y = action->scriptData.pos2.y - pos.y;
                            sub_800290C(&pos2, action->scriptData.unk30);
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
                        case 0x71 ... 0x76:
                        case 0x7d ... 0x82: {
                            if (action->scriptData.unk2A > 0) {
                                PixelPos pos;
                                sub_8002934(&pos, &action->scriptData.pos1, &action->scriptData.pos2, action->scriptData.unk2A, action->scriptData.unk2C);
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
                        case 0x77 ... 0x7c:
                        case 0x83 ... 0x88: {
                            if (action->scriptData.unk2A > 0) {
                                PixelPos pos1, pos2, pos3;
                                s32 dir, dirBefore;
                                s8 dirS8;

                                action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                                sub_8002934(&pos2, &action->scriptData.pos1, &action->scriptData.pos2, action->scriptData.unk2A, action->scriptData.unk2C);
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
                        case 0x68: case 0x70: {
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
                        case 0x89: case 0x8a: {
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
                        case 0x91 ... 0x95: {
                            if (action->scriptData.unk2A > 0) {
                                action->scriptData.unk2A--;
                                loopContinue = FALSE;
                            }
                            else {
                                PixelPos pos1, pos2, pos3, pos4;
                                s32 tmp1, tmp2;
                                s8 dir;
                                bool8 flag;
                                cmd = *action->scriptData.curPtr;
                                tmp1 = -1;
                                tmp2 = -1;
                                flag = FALSE;
                                action->callbacks->getDirection(action->parentObject, &dir);
                                // arg1h synthetic
                                switch (cmd.op) {
                                    case 0x91: case 0x92: {
                                        tmp2 = (s8) action->scriptData.unk4D;
                                        break;
                                    }
                                    case 0x93: {
                                        s16 res;
                                        res = sub_80A7AE8((s16)cmd.arg1);
                                        if (res >= 0) {
                                            flag = TRUE;
                                            sub_80A8FD8(res, &pos1);
                                            sub_80A8F9C(res, &pos2);
                                        }
                                        break;
                                    }
                                    case 0x94: {
                                        s32 res;
                                        res = (s16)sub_80A7AE8((s16)cmd.arg1);
                                        if (res >= 0) {
                                            flag = TRUE;
                                            sub_80A8FD8(res, &pos1);
                                            pos2 = gUnknown_81164DC;
                                        }
                                        break;
                                    }
                                    case 0x95: {
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
                                        tmp2 = SizedDeltaDirection4(&pos3, &gUnknown_81164DC, &pos1, &gUnknown_81164DC);
                                    }
                                }
                                if (tmp2 == -1 || tmp2 == dir) {
                                    action->scriptData.savedState = 3;
                                    break;
                                }

                                ASM_MATCH_TRICK(dir);
                                action->scriptData.unk26 = sub_8002A70(dir, tmp2, (u8)cmd.argShort);
                                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                                action->scriptData.unk2A = cmd.argByte;
                            }
                            break;
                        }
                        case 0x9b ... 0xa3: {
                            if (sub_809D234()) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0xe3: case 0xe5: {
                            if (action->scriptData.unk22 != -1) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.script.ptr = ResolveJump(action, gUnlockBranchLabels[action->scriptData.branchDiscriminant]);
                                action->scriptData.savedState = 3;
                            }
                            break;
                        }
                        case 0x2c: case 0x30 ... 0x38: {
                            if (action->scriptData.unk22 != -1) {
                                loopContinue = FALSE;
                            }
                            else {
                                action->scriptData.savedState = 3;
                                sub_80A87AC(0, 0);
                            }
                            break;
                        }
                        case 0x39: {
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
                        case 0x3b: {
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
                        case 0x3c: {
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
                        case 0x03: {
                            s32 val;
                            if (!sub_809B260(&val)) {
                                loopContinue = FALSE;
                                break;
                            }
                            if (val >= 0) {
                                cmd = *action->scriptData.curPtr;
                                GroundMainGroundRequest((s16)sub_8002694((u8)val), 0, cmd.argShort);
                            }
                            action->scriptData.script.ptr = ResolveJump(action, val);
                            action->scriptData.savedState = 3;
                            sub_80A87AC(0, 0);
                            break;
                        }
                        case 0x04: {
                            if (action->scriptData.branchDiscriminant == 0) {
                                s32 val;
                                if (!sub_809B260(&val)) {
                                    loopContinue = FALSE;
                                    break;
                                }
                                if (val >= 0) {
                                    SetScriptVarValue(NULL, 18, sub_80A26B8(val));
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
                        case 0x06: {
                            if (action->scriptData.branchDiscriminant == 0) {
                                s32 val;
                                s16 disc;
                                if (!sub_809B260(&val)) {
                                    loopContinue = FALSE;
                                    break;
                                }
                                if (val >= 0) {
                                    SetScriptVarValue(NULL, 19, action->scriptData.curScriptOp == 4 ? sub_80A26B8(val) : (s16)val);
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
                        case 0x07: {
                            if (action->scriptData.branchDiscriminant == 1) {
                                s32 dungeonEnter;
                                u32 res;
                                struct unkStruct_20398C8 unkStruct;
                                dungeonEnter = (s16)GetScriptVarValue(NULL, 19);
                                if (sub_80990EC(&unkStruct, dungeonEnter)) {
                                    s32 val;
                                    sub_8099220(&unkStruct, dungeonEnter);
                                    val = sub_80023E4(6);
                                    res = sub_809034C(unkStruct.unk0, 0, gUnknown_203B4B0, val, 0);
                                    gUnknown_2039DA4 = res;
                                    switch (res) {
                                        case 2: {
                                            action->scriptData.branchDiscriminant = 2;
                                            sub_809B1C0(9, 1, gUnknown_203B4B0);
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
                                            sub_809B1C0(10, 1, gUnknown_203B4B0);
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
                        case 0x05:
                            if (action->scriptData.branchDiscriminant == 1) {
                                unkStruct_203B480 *ret;
                                s32 val;
                                u32 res;
                                ret = GetMailatIndex(GetScriptVarValue(NULL, 20));
                                val = sub_80023E4(6);
                                res = sub_809034C(ret->unk4.dungeon.id, 0, gUnknown_203B4B0, val, 1);
                                gUnknown_2039DA4 = res;
                                switch (res) {
                                    case 2: {
                                        action->scriptData.branchDiscriminant = 2;
                                        sub_809B1C0(9, 1, gUnknown_203B4B0);
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
                                        sub_809B1C0(10, 1, gUnknown_203B4B0);
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
                                    ScriptPrintNullTextbox();
                                    break;
                                }
                                else {
                                    action->scriptData.branchDiscriminant = -1;
                                    sub_80A87AC(0, 0);
                                    ScriptPrintNullTextbox();
                                    break;
                                }
                            }
                            if (action->scriptData.branchDiscriminant == 3) {
                                cmd = *action->scriptData.curPtr;
                                action->scriptData.savedState = 3;
                                sub_80999FC(cmd.argShort);
                                GroundMap_ExecuteEvent(0x70, 0);
                                if (action->unk8[0] == 0) continue;
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
                                ScriptPrintNullTextbox();
                                break;
                            }

                            sub_8099220(0, 0);
                            SetScriptVarValue(NULL, 19, -1);
                            action->scriptData.script.ptr = ResolveJump(action, -1);
                            action->scriptData.savedState = 3;
                            break;
                        }
                        case 0x3d: {
                            s32 val;
                            cmd = *action->scriptData.curPtr;
                            if (!sub_809B260(&val)) {
                                loopContinue = FALSE;
                                break;
                            }
                            if (val == 1) {
                                s32 id = (s16)cmd.arg1;
                                if (id != -1) {
                                    PokemonStruct1 *mon = sub_80A8D54(id);
                                    s32 i;
                                    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
                                        mon->name[i] = gUnknown_2039D98[i];
                                    }
                                }
                            }
                            action->scriptData.script.ptr = ResolveJump(action, val);
                            action->scriptData.savedState = 3;
                            sub_80A87AC(0, 0);
                            break;
                        }
                        case 0x3e: {
                            s32 val;
                            if (!sub_809B260(&val)) {
                                loopContinue = FALSE;
                                break;
                            }
                            if (val == 1) {
                                SetRescueTeamName(gUnknown_2039D98);
                            }
                            action->scriptData.script.ptr = ResolveJump(action, val);
                            action->scriptData.savedState = 3;
                            sub_80A87AC(0, 0);
                            break;
                        }
                        case 0x3f: {
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

                                    CopyStringtoBuffer(gUnknown_2039D98, name);
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
                        case 0x3a: {
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
                        case 0xcf: {
                            cmd = *action->scriptData.curPtr;
                            if (action->scriptData.unk2C == 0) {
                                bool8 flag = FALSE;
                                if (action->scriptData.branchDiscriminant < 0) {
                                    if (action->scriptData.script.ptr->op != 0xd1) {
                                        action->scriptData.savedState = 3;
                                        break;
                                    }
                                }
                                else {
                                    while (action->scriptData.script.ptr->op == 0xd0) {
                                        if (action->scriptData.script.ptr->argShort == action->scriptData.branchDiscriminant) {
                                            flag = TRUE;
                                            break;
                                        }
                                        action->scriptData.script.ptr++;
                                    }
                                    if (!flag) {
                                        while (action->scriptData.script.ptr->op == 0xd1) {
                                            action->scriptData.script.ptr++;
                                        }
                                        action->scriptData.savedState = 3;
                                        break;
                                    }
                                }
                                if (ScriptPrintText(cmd.argByte, (s16) cmd.arg1, action->scriptData.script.ptr->argPtr)) {
                                    sub_80A87AC(0,10);
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
                        case 0xd2 ... 0xd8: {
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
                        case 0xda: {
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
                        case 0x08 ... 0x21: case 0x29 ... 0x2b: case 0x2d ... 0x2f: case 0x40 ... 0x57: case 0x5c: case 0x5f:
                        case 0x96: case 0x97: case 0x9a: case 0xa4 ... 0xce: case 0xd0: case 0xd1: case 0xd9: case 0xe4: case 0xe6 ... 0xf0: {
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
                case 0: case 1: case 4: {
                    return action->scriptData.savedState;
                }
            }
        }
        return 3;
    }
    else {
        return 0;
    }
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
s32 ExecuteScriptCommand(Action *action)
{
    ScriptCommand curCmd;
    ScriptData *scriptData = &action->scriptData;

    while (1) {
        scriptData->curPtr = scriptData->script.ptr;
        curCmd = *scriptData->script.ptr++;
        switch (scriptData->curScriptOp = curCmd.op) {
            case 0x01: {
                u32 arg = (s16)curCmd.arg1;
                u32 argCopy = arg;
                u32 byte = (u8)curCmd.argByte;
                if (ScriptLoggingEnabled(TRUE)) {
                    // "    ground select %3d[%s] %3d"
                    Log(1, gUnknown_81165D4, arg, gGroundConversion_811BAF4[arg].text, byte);
                }
                GroundMainGroundRequest(argCopy, byte, curCmd.argShort);
                break;
            }
            case 0x02: {
                s32 arg = (s16)curCmd.arg1;
                if (arg == -1) arg = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER);
                if (ScriptLoggingEnabled(TRUE)) {
                    // "    dungeon select %3d"
                    Log(1, gUnknown_81165F4, arg);
                }
                if (arg != -1) {
                    GroundMainRescueRequest(arg, curCmd.argShort);
                    action->scriptData.script.ptr = ResolveJump(action, 1);
                } else {
                    action->scriptData.script.ptr = ResolveJump(action, 0);
                }
                break;
            }
            case 0x03: {
                if (sub_8021700(curCmd.arg1)) {
                    action->scriptData.script.ptr = ResolveJump(action, -1);
                } else {
                    sub_8098D80(curCmd.argShort);
                    action->scriptData.script.ptr = ResolveJump(action, 0);
                }
                break;
            }
            case 0x04: {
                if (curCmd.arg1 == -1) {
                    if (!(u8)sub_802FCF0() && (u8)sub_809B1C0(12,0,0)) {
                        sub_80A87AC(0, 11);
                        action->scriptData.branchDiscriminant = 0;
                    } else {
                        action->scriptData.branchDiscriminant = -1;
                    }
                    return 2; // do action
                } else {
                    SetScriptVarValue(NULL, DUNGEON_SELECT, sub_80A26B8((s16)curCmd.arg1));
                    action->scriptData.branchDiscriminant = 1;
                    return 2; // do action
                }
                break;
            }
            case 0x06: {
                if (curCmd.arg1 == -1) {
                    if ((s8)sub_809B1C0(36, 0, 0)) {
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
            case 0x05: {
                action->scriptData.branchDiscriminant = 1;
                return 2;
            }
            case 0x07: {
                s32 tmp = (s16)curCmd.arg1;
                if (tmp == -1) {
                    tmp = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER);
                } else {
                    SetScriptVarValue(NULL, DUNGEON_ENTER, tmp);
                }
                if (ScriptLoggingEnabled(TRUE)) {
                    Log(1, gUnknown_811660C, tmp);
                }
                if (tmp != -1) {
                    action->scriptData.branchDiscriminant = 1;
                    return 2;
                } else {
                    action->scriptData.branchDiscriminant = -1;
                    return 2;
                }
            }
            case 0x08: case 0x09: {
                if (curCmd.op == 0x08) {
                    gCurrentMap = curCmd.arg1;
                    gUnknown_2039A32 = GetAdjustedGroundMap((s16)curCmd.arg1);
                    gUnknown_2039A34 = gUnknown_2039A32;
                    if (ScriptLoggingEnabled(TRUE)) {
                        // "    map select %3d %3d[%s]"
                        Log(1,gUnknown_8116628,gCurrentMap,gUnknown_2039A32,
                            gGroundConversion_811BAF4[gCurrentMap].text);
                    }
                } else {
                    gUnknown_2039A32 = gCurrentMap = curCmd.arg1;
                    gUnknown_2039A34 = curCmd.arg1;
                    if (ScriptLoggingEnabled(TRUE)) {
                        // "    ground select %3d %3d[%s]"
                        Log(1,gUnknown_8116644,gCurrentMap,gUnknown_2039A32,
                            gGroundConversion_811BAF4[gCurrentMap].text);
                    }
                }
                SetScriptVarValue(NULL,GROUND_MAP,gCurrentMap);
                SetScriptVarValue(NULL,GROUND_PLACE,gGroundConversion_811BAF4[gCurrentMap].unk2);
                GroundSprite_Reset(gUnknown_2039A32);
                sub_809D0BC();
                DeleteGroundEvents();
                DeleteGroundLives();
                DeleteGroundObjects();
                DeleteGroundEffects();
                sub_809C770(gCurrentMap, gGroundConversion_811BAF4[gCurrentMap].unk2);
                GroundMap_Select(gUnknown_2039A32);
                GroundLink_Select(gUnknown_2039A32);
                GroundLives_Select(gUnknown_2039A32,0,0);
                GroundObject_Select(gUnknown_2039A32,0,0);
                break;
            }
            case 0x0a: {
                const DungeonInfo *tmp;
                DungeonLocation loc;
                tmp = GetDungeonInfo_80A2608((s16)curCmd.arg1);
                gUnknown_2039A34 = gUnknown_2039A32 = gCurrentMap = (s16)curCmd.arg2;
                if (ScriptLoggingEnabled(TRUE)) {
                    // "    dungeon select %3d %3d[%s]"
                    Log(1, gUnknown_8116664, gCurrentMap,gUnknown_2039A32,
                        gGroundConversion_811BAF4[gCurrentMap].text);
                }
                GroundSprite_Reset(gUnknown_2039A32);
                sub_809D0BC();
                DeleteGroundEvents();
                DeleteGroundLives();
                DeleteGroundObjects();
                DeleteGroundEffects();
                loc.id = tmp->dungeonIndex;
                loc.floor = curCmd.argShort;
                GroundMap_SelectDungeon(gUnknown_2039A32, &loc, curCmd.argByte);
                GroundLink_Select(gUnknown_2039A32);
                GroundLives_Select(gUnknown_2039A32,0,0);
                GroundObject_Select(gUnknown_2039A32,0,0);
                break;
            }
            case 0x0b: {
                GroundWeather_Select((s16)curCmd.arg1);
                break;
            }
            case 0x0c ... 0x15: {
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
                    case 0x0c: {
                        GroundLives_Select(gUnknown_2039A32, group, sector);
                        GroundObject_Select(gUnknown_2039A32, group, sector);
                        GroundEffect_Select(gUnknown_2039A32, group, sector);
                        GroundEvent_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x0d: {
                        GroundLives_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x0e: {
                        GroundObject_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x0f: {
                        GroundEffect_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x10: {
                        GroundEvent_Select(gUnknown_2039A32, group, sector);
                        break;
                    }
                    case 0x11: {
                        GroundLives_Cancel(group, sector);
                        GroundObject_Cancel(group, sector);
                        GroundEffect_Cancel(group, sector);
                        GroundEvent_Cancel(group, sector);
                        break;
                    }
                    case 0x12: {
                        GroundLives_Cancel(group, sector);
                        break;
                    }
                    case 0x13: {
                        GroundObject_Cancel(group, sector);
                        break;
                    }
                    case 0x14: {
                        GroundEffect_Cancel(group, sector);
                        break;
                    }
                    case 0x15: {
                        GroundEvent_Cancel(group, sector);
                        break;
                    }
                }
                break;
            }
            case 0x16: {
                GroundLives_CancelBlank_1();
                break;
            }
            case 0x17: {
                GroundObject_CancelBlank();
                break;
            }
            case 0x18: {
                GroundEffect_CancelBlank();
                break;
            }
            case 0x19: {
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
            case 0x1a: {
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
                res = GroundEffect_Add(-1, eff, group, sector);
                if (res >= 0) {
                    action->callbacks->getHitboxCenter(action->parentObject, &pos);
                    sub_80AD3B4(res, &pos);
                }
                break;
            }
            case 0x1c: {
                GroundMap_ExecuteEvent(curCmd.argShort, 1);
                break;
            }
            case 0x1b: {
                GroundMap_ExecuteEvent(curCmd.argShort, 0);
                break;
            }
            case 0x1d: case 0x1e: {
                s32 map;
                s32 group, sector;
                bool8 res;
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
                res = curCmd.op == 0x1e;
                GroundMap_ExecuteStation(map, group, sector, res);
                if (gUnknown_2039A34 != map) {
                    gUnknown_2039A34 = map;
                    GroundCancelAllEntities();
                    if (action->unk8[0] != 0)
                        return 4; // Fatal?
                }
                break;
            }
            case 0x1f: {
                s32 a = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER);
                const DungeonInfo *ret1 = GetDungeonInfo_80A2608(a);
                s32 thing = GetScriptVarArrayValue(NULL, DUNGEON_ENTER_LIST, (u16) a) == 0 ? ret1->unk6 : ret1->unk8;
                // fakematch: this is almost certainly a range check of the form 0x37 <= a && a < 0x48
                // but that loses the s32 -> u16 cast. Inlines, macros, or other schenanigans are likely involved
                if (!((u16)(a - 0x37) < 0x11) && (s16)sub_80A2750(a) == 1) {
                    if (thing == -1) {
                        if (ScriptLoggingEnabled(TRUE)) {
                            // "    dungeon rescue select %3d"
                            Log(1, gUnknown_8116684, a);
                        }
                        GroundMainRescueRequest(a, -1);
                    } else {
                        GroundMap_ExecuteEvent(thing, 0);
                        break;
                    }
                } else {
                    GroundMainRescueRequest(a, -1);
                }
                break;
            }
            case 0x20: {
                switch (action->unkC.arr[0]) {
                    case 0:
                        GroundMap_ExecuteEvent(curCmd.argShort, 0);
                        break;
                    case 1: {
                        ScriptInfoSmall info1;
                        GetFunctionScript(action, &info1, curCmd.argShort);
                        GroundLives_ExecuteScript(action->unkC.arr[1], action->unk8, &info1);
                        break;
                    }
                    case 2: {
                        ScriptInfoSmall info2;
                        GetFunctionScript(action, &info2, curCmd.argShort);
                        GroundObject_ExecuteScript(action->unkC.arr[1], action->unk8, &info2);
                        break;
                    }
                    case 3: {
                        ScriptInfoSmall info3;
                        GetFunctionScript(action, &info3, curCmd.argShort);
                        GroundEffect_ExecuteScript(action->unkC.arr[1], action->unk8, &info3);
                        break;
                    }
                }
                break;
            }
            case 0x21: {
                s32 ret;
                s32 unk;
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
                            (tmp = SizedDeltaDirection4(&pos1, &gUnknown_81164DC, &pos3, &gUnknown_81164DC)) != -1) {
                            sub_80A9090(ret, tmp);
                        }
                    }
                    GroundLives_ExecutePlayerScriptActionLives(action->unk8[1], ret);
                    return 3;
                }
                break;
            }
            case 0x22: {
                sub_80999E8(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x23: {
                sub_80999FC(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x24: {
                sub_8099A10(curCmd.argShort, (u16)curCmd.arg1, (u16)curCmd.arg2);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x25: {
                sub_8099A34(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x26: {
                sub_8099A48(curCmd.argShort);
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x27: case 0x28: {
                // THANK YOU pidgey, only an array *inside* a struct works
                // TODO: Define this struct globally, so it can be passed to sub_8099A5C and sub_8099AFC
                // This kind of hackiness is used at all callsites (or they load from a global)
                s32 color = ({
                    struct color { u8 arr[4]; } color = {{
                        curCmd.arg2 >> 16,
                        curCmd.arg2 >> 8,
                        curCmd.arg2,
                        0,
                    }};
                    *(s32*)&color;
                });
                switch (curCmd.op) {
                    case 0x27:
                        sub_8099A5C(curCmd.argShort, curCmd.arg1, color);
                        break;
                    case 0x28:
                        sub_8099AFC(curCmd.argShort, curCmd.arg1, color);
                        break;
                }
                if (curCmd.argByte) return 2;
                break;
            }
            case 0x29: {
                sub_809A6E4((u16)curCmd.argShort);
                break;
            }
            case 0x2a: {
                sub_809A6F8((u16)curCmd.argShort);
                break;
            }
            case 0x2b: {
                sub_809A738(curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0x2c: {
                if (!(s8)sub_809A768()) break;
                sub_80A87AC(0, 10);
                if (GroundScriptCheckLockCondition(action, 0)) return 2;
                break;
            }
            case 0x30: {
                ScriptPrintNullTextbox();
                break;
            }
            case 0x31: {
                ScriptPrintEmptyTextbox();
                break;
            }
            case 0x2d: {
                switch ((u8)curCmd.argByte) {
                    case 0: {
                        sub_809A83C(curCmd.argShort);
                        break;
                    }
                    case 1: {
                        sub_80A2500(curCmd.argShort, action->unk8);
                        break;
                    }
                    case 2: {
                        sub_80A2500(curCmd.argShort, action->unkC.arr);
                        break;
                    }
                    case 3: {
                        struct {s16 unk0; s16 unk2;} unk;
                        unk.unk2 = sub_80A7AE8((s16)curCmd.arg1);
                        unk.unk0 = 1;
                        sub_80A2500(curCmd.argShort, (void*)&unk);
                        break;
                    }
                    case 4: {
                        sub_80A252C(curCmd.argShort, action->unk8);
                        break;
                    }
                    case 5: {
                        sub_80A252C(curCmd.argShort, action->unkC.arr);
                        break;
                    }
                    case 6: {
                        struct {s16 unk0; s16 unk2;} unk;
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
                        sub_80A2558(curCmd.argShort, action->unk8);
                        break;
                    }
                    case 8: {
                        sub_80A2558(curCmd.argShort, action->unkC.arr);
                        break;
                    }
                    case 9: {
                        struct {s16 unk0; s16 unk2;} unk;
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
                        u8 a = sub_80A2740((s16)curCmd.arg1);
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
            case 0x2e: {
                sub_809AC7C(curCmd.argShort, (s8)curCmd.arg1, (u8)curCmd.argByte);
                break;
            }
            case 0x2f: {
                s32 unk[2];
                unk[0] = curCmd.arg1;
                unk[1] = curCmd.arg2;
                sub_809ADD8(curCmd.argShort, unk);
                break;
            }
            case 0x32 ... 0x38: {
                s8 ret = 0;
                switch (scriptData->curScriptOp) {
                    case 0x32: ret = ScriptPrintText(0, curCmd.argShort, curCmd.argPtr); break;
                    case 0x33: ret = ScriptPrintText(1, curCmd.argShort, curCmd.argPtr); break;
                    case 0x34: ret = ScriptPrintText(2, curCmd.argShort, curCmd.argPtr); break;
                    case 0x35: ret = ScriptPrintText(3, curCmd.argShort, curCmd.argPtr); break;
                    case 0x36: ret = ScriptPrintText(4, curCmd.argShort, curCmd.argPtr); break;
                    case 0x37: ret = sub_809AEEC(curCmd.argPtr); break;
                    case 0x38: ret = sub_809AF2C(curCmd.argPtr); break;
                }
                if (ret) {
                    sub_80A87AC(0, 10);
                    if (GroundScriptCheckLockCondition(action, 0)) return 2;
                }
                break;
            }
            case 0x39: {
                if ((s8)sub_809AF6C(curCmd.argShort, curCmd.argPtr) && curCmd.argShort >= 0) {
                    sub_80A87AC(0, 10);
                    if (GroundScriptCheckLockCondition(action, 0)) return 2;
                }
                break;
            }
            case 0x3a: {
                sub_809AFC8((u8)curCmd.argByte > 0, curCmd.arg1, (s16)curCmd.arg2, curCmd.argPtr);
                if (GroundScriptCheckLockCondition(action, 1)) {
                    sub_80A87AC(0, 11);
                    return 2;
                }
                break;
            }
            case 0x3c: {
                sub_809B1D4(curCmd.argByte, curCmd.arg1, curCmd.arg2, curCmd.argPtr);
                sub_80A87AC(0, 11);
                return 2;
            }
            case 0x3b: {
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x3d: {
                int i;
                if ((s16)curCmd.arg1 != -1) {
                    PokemonStruct1 *mon = sub_80A8D54(curCmd.arg1);
                    if (mon != NULL) {
                        for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
                            gUnknown_2039D98[i] = mon->name[i];
                        }
                        gUnknown_2039D98[POKEMON_NAME_LENGTH] = 0;
                        sub_809B1C0(4, 0, gUnknown_2039D98);
                        sub_80A87AC(0, 11);
                        return 2;
                    }
                    break;
                } else {
                    sub_809B1C0(4, 1, gUnknown_2039D98);
                    sub_80A87AC(0, 11);
                    return 2;
                }
            }
            case 0x3e: {
                sub_80920B8(gUnknown_2039D98);
                gUnknown_2039D98[10] = 0;
                sub_809B1C0(5, 0, gUnknown_2039D98);
                sub_80A87AC(0, 11);
                return 2;
            }
            case 0x3f: {
                int i;
                for (i = 0; i < 12; i++) {
                    gUnknown_2039D98[i] = 0;
                }
                sub_809B1C0(6, (u8)curCmd.argByte, gUnknown_2039D98);
                sub_80A87AC(0, 11);
                return 2;
            }
            case 0x42: {
                StopAllMusic_1();
                break;
            }
            case 0x43: {
                FadeOutAllMusic(curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case 0x44: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999) {
                    xxx_call_start_new_bgm((u16)id);
                } else {
                    xxx_call_stop_bgm();
                }
                break;
            }
            case 0x45: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999) {
                    xxx_call_fade_in_new_bgm((u16)id, (u16)curCmd.argShort); //sub_8011900
                } else {
                    xxx_call_stop_bgm();
                }
                break;
            }
            case 0x46: {
                u16 id = curCmd.argByte == 0 ? sub_80A25AC((u16)curCmd.arg1) : curCmd.arg1;
                if (id != 999) {
                    xxx_call_queue_bgm((u16)id);
                }
                break;
            }
            case 0x47: {
                xxx_call_stop_bgm();
                break;
            }
            case 0x48: {
                xxx_call_fade_out_bgm(curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case 0x49: case 0x4c: {
                xxx_call_play_fanfare_se((u16)curCmd.arg1, 256);
                break;
            }
            case 0x4a: case 0x4d: {
                xxx_call_stop_fanfare_se((u16)curCmd.arg1);
                break;
            }
            case 0x4b: case 0x4e: {
                xxx_call_fade_out_fanfare_se((u16)curCmd.arg1, curCmd.argShort < 0 ? 30 : (u16)curCmd.argShort);
                break;
            }
            case 0x4f: {
                if (action->scriptData2.state == 1) {
                    InitScriptData(&action->scriptData2);
                }
                action->callbacks->setHitboxPos(action->parentObject, 0);
                break;
            }
            case 0x50: {
                Action *ptr;
                PixelPos pos;
                s8 c;
                {
                    Action *tmp = (Action*)sub_809D52C(action->unkC.arr);
                    ptr = tmp;
                }
                if (ptr) {
                    ptr->callbacks->getHitboxCenter(action->parentObject, &pos);
                    ptr->callbacks->getDirection(action->parentObject, &c);
                    action->callbacks->moveReal(action->parentObject, &pos);
                    action->scriptData.unk26 = c;
                    action->callbacks->setDirection(action->parentObject, c);
                }
                break;
            }
            case 0x51: {
                PixelPos posIn;
                PixelPos posOut1;
                PixelPos posOut2;
                action->callbacks->getHitboxCenter(action->parentObject, &posIn);
                GroundLink_GetArea(curCmd.argShort, &posOut1, &posOut2, &posIn);
                action->callbacks->setPositionBounds(action->parentObject, &posOut1, &posOut2);
                break;
            }
            case 0x52: {
                action->callbacks->setFlags(action->parentObject, curCmd.arg1);
                break;
            }
            case 0x53: {
                if (curCmd.arg1 & 0x400 && action->scriptData2.state == 1) {
                    InitScriptData(&action->scriptData2);
                }
                action->callbacks->clearFlags(action->parentObject, curCmd.arg1);
                break;
            }
            case 0x54: {
                action->callbacks->getDirection(action->parentObject, &action->scriptData.unk26);
                if (curCmd.argShort) {
                    action->scriptData.unk24 = curCmd.argShort;
                }
                action->callbacks->setEventIndex(action->parentObject, (u16)curCmd.argShort);
                break;
            }
            case 0x55: {
                action->callbacks->livesOnlyNullsub(action->parentObject, (u16)curCmd.argShort);
                break;
            }
            case 0x56: {
                action->callbacks->func38(action->parentObject, (s16)curCmd.arg1, curCmd.argShort);
                break;
            }
            case 0x57: {
                action->callbacks->func44_livesOnlySpriteRelated(action->parentObject, curCmd.argShort);
                break;
            }
            case 0x58: {
                PixelPos unk;
                unk.x = curCmd.arg1 << 8;
                unk.y = curCmd.arg2 << 8;
                action->callbacks->moveReal(action->parentObject, &unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x59: {
                PixelPos unk;
                unk.x = curCmd.argShort << 8;
                unk.y = curCmd.arg1 << 8;
                action->callbacks->moveRelative(action->parentObject, &unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5a: {
                u32 unk[2];
                unk[0] = OtherRandInt(curCmd.argShort) << 8;
                unk[1] = OtherRandInt(curCmd.arg1) << 8;
                action->callbacks->moveRelative(action->parentObject,
                                                (PixelPos*)unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5b: {
                PixelPos unk;
                action->callbacks->getHitboxCenter(action->parentObject, &unk);
                GroundLink_GetPos((s16)curCmd.arg1, &unk);
                action->callbacks->moveReal(action->parentObject, &unk);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5c: {
                PixelPos pos, pos1, pos2;
                action->callbacks->getHitboxCenter(action->parentObject, &pos);
                GroundLink_GetArea((s16)curCmd.arg1, &pos1, &pos2, &pos);
                pos.x = pos1.x + OtherRandInt(pos2.x - pos1.x);
                pos.y = pos1.y + OtherRandInt(pos2.y - pos1.y);
                action->callbacks->moveReal(action->parentObject, &pos);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x5d: {
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
            case 0x5e: {
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
            case 0x5f: {
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
            case 0x60: {
                action->callbacks->setPosHeight(action->parentObject, curCmd.arg1 << 8);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x61: case 0x69: {
                scriptData->pos2.x = curCmd.arg1 << 8;
                scriptData->pos2.y = curCmd.arg2 << 8;
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x62: case 0x6a: {
                PixelPos pos;
                action->callbacks->getHitboxCenter(action->parentObject, &pos);
                scriptData->pos2.x = pos.x + (curCmd.arg1 << 8);
                scriptData->pos2.y = pos.y + (curCmd.arg2 << 8);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x63: case 0x6b: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x64: case 0x6c: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x65: case 0x6d: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = OtherRandInt((u8)curCmd.argByte);
                return 2;
            }
            case 0x66: case 0x67: case 0x6e: case 0x6f: {
                s16 ret = sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    sub_80A8FD8(ret, &scriptData->pos2);
                    scriptData->unk30 = curCmd.argShort;
                    scriptData->unk2A = (u8)curCmd.argByte;
                    return 2;
                }
                break;
            }
            case 0x71: case 0x77: case 0x7d: case 0x83: {
#define HYPOT FP24_8_Hypot((s24_8){scriptData->pos2.x - scriptData->pos1.x}, (s24_8){scriptData->pos2.y - scriptData->pos1.y}).raw / curCmd.argShort
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = curCmd.arg1 << 8;
                scriptData->pos2.y = curCmd.arg2 << 8;
                if (curCmd.op == 0x7d || curCmd.op == 0x83) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x72: case 0x78: case 0x7e: case 0x84: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2.x = scriptData->pos1.x + (curCmd.arg1 << 8);
                scriptData->pos2.y = scriptData->pos1.y + (curCmd.arg2 << 8);
                if (curCmd.op == 0x7e || curCmd.op == 0x84) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x73: case 0x79: case 0x7f: case 0x85: {
                s32 cap1 = curCmd.arg1 * 2 - 1;
                s32 cap2 = curCmd.arg2 * 2 - 1;
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                // BUG: (or two): these lines use the wrong script command arguments to calculate the position offset
                // making the target position nonsense. But even if they were correct,
                // the way the cap is calculated would make the random offset biased off-center.
                // This doesn't affect the released version because these script commands are never used.
#ifndef BUGFIX
                scriptData->pos2.x = scriptData->pos1.x + ((OtherRandInt(cap1) - curCmd.argShort) << 8);
                scriptData->pos2.y = scriptData->pos1.y + ((OtherRandInt(cap2) - curCmd.arg1) << 8);
#else
                scriptData->pos2.x = scriptData->pos1.x + ((OtherRandInt(curCmd.arg1 * 2 + 1) - curCmd.arg1) << 8);
                scriptData->pos2.y = scriptData->pos1.y + ((OtherRandInt(curCmd.arg2 * 2 + 1) - curCmd.arg2) << 8);
#endif
                if (curCmd.op == 0x7f || curCmd.op == 0x85) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x74: case 0x7a: case 0x80: case 0x86: {
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                scriptData->pos2 = scriptData->pos1;
                GroundLink_GetPos((s16)curCmd.arg1, &scriptData->pos2);
                if (curCmd.op == 0x80 || curCmd.op == 0x86) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x75: case 0x7b: case 0x81: case 0x87: {
                s32 cap = curCmd.arg1 * 2 - 1;
                action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos2);
                GroundLink_GetPos((s16)curCmd.arg2, &scriptData->pos2);
                scriptData->pos2.x = scriptData->pos2.x + ((OtherRandInt(cap) - curCmd.argShort) << 8);
                scriptData->pos2.y = scriptData->pos2.y + ((OtherRandInt(cap) - curCmd.argShort) << 8);
                if (curCmd.op == 0x81 || curCmd.op == 0x87) {
                    scriptData->unk2A = HYPOT;
                    if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                } else {
                    scriptData->unk2A = curCmd.argShort;
                }
                return 2;
            }
            case 0x76: case 0x7c: case 0x82: case 0x88: {
                s16 ret = sub_80A7AE8((s16)curCmd.arg1);
                if (ret >= 0) {
                    action->callbacks->getHitboxCenter(action->parentObject, &scriptData->pos1);
                    sub_80A8FD8(ret, &scriptData->pos2);
                    if (curCmd.op == 0x82 || curCmd.op == 0x88) {
                        scriptData->unk2A = HYPOT;
                        if (scriptData->unk2A <= 0) scriptData->unk2A = 1;
                    } else {
                        scriptData->unk2A = curCmd.argShort;
                    }
                    return 2;
                }
                break;
            }
            case 0x68: case 0x70: {
                scriptData->unk48 = curCmd.arg1 << 8;
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = -1;
                return 2;
            }
            case 0x89: {
                action->scriptData.unk26 = curCmd.arg1;
                action->callbacks->setDirection(action->parentObject, (s8) curCmd.arg1);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8a: {
                s8 dir;
                action->callbacks->getDirection(action->parentObject, &dir);
                action->scriptData.unk26 = sub_8002984(dir, (s8)curCmd.arg1);
                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                scriptData->unk30 = curCmd.argShort;
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8b: {
                action->scriptData.unk26 = curCmd.argShort;
                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8c: {
                int ret = (s16)sub_80A7AE8((s16)curCmd.arg1);
                s8 dir;
                if (ret >= 0) {
                    sub_80A9050(ret, &dir);
                    action->scriptData.unk26 = sub_8002984(dir, curCmd.argShort);
                    action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                }
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8d: {
                s8 dir;
                action->callbacks->getDirection(action->parentObject, &dir);
                action->scriptData.unk26 = sub_8002984(dir, curCmd.argShort);
                action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x8e: case 0x8f: case 0x90: {
                bool8 flag = FALSE;
                s8 dir;
                PixelPos pos1, pos2, pos3, pos4;
                switch (curCmd.op) {
                    case 0x8e: {
                        s32 val = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (val >= 0) {
                            flag = TRUE;
                            sub_80A8FD8(val, &pos1);
                            sub_80A8F9C(val, &pos2);
                        }
                        break;
                    }
                    case 0x8f: {
                        s32 val = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (val >= 0) {
                            flag = TRUE;
                            sub_80A8FD8(val, &pos1);
                            pos2 = gUnknown_81164DC;
                        }
                        break;
                    }
                    case 0x90: {
                        flag = TRUE;
                        action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                        action->callbacks->getSize(action->parentObject, &pos2);
                        GroundLink_GetPos((s16)curCmd.arg1, &pos1);
                        break;
                    }
                }
                if (flag) {
                    s8 ret;
                    int tmp;
                    action->callbacks->getHitboxCenter(action->parentObject, &pos3);
                    action->callbacks->getSize(action->parentObject, &pos4);
                    ret = SizedDeltaDirection8(&pos3, &pos4, &pos1, &pos2); // wtf
                    *&dir = ret;

                    tmp = -1;
                    if (dir == tmp) {
                        dir = SizedDeltaDirection4(&pos3, &gUnknown_81164DC, &pos1, &gUnknown_81164DC);
                    }
                    if (dir == tmp) {
                        action->callbacks->getDirection(action->parentObject, &dir);
                    }
                    action->scriptData.unk26 = sub_8002984(dir, (s8)curCmd.argShort);
                    action->callbacks->setDirection(action->parentObject, action->scriptData.unk26);
                }
                scriptData->unk2A = (u8)curCmd.argByte;
                return 2;
            }
            case 0x93: case 0x94: case 0x95: {
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x91: {
                action->scriptData.unk4D = (s8)curCmd.arg1;
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x92: {
                s8 unk;
                action->callbacks->getDirection(action->parentObject, &unk);
                action->scriptData.unk4D = sub_8002984(unk, (s8)curCmd.arg1);
                scriptData->unk2A = 0;
                return 2;
            }
            case 0x97: {
                sub_809D124(curCmd.argShort, curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0x98: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                switch(action->unk8[0]) {
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
            case 0x99: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch(action->unk8[0]) {
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
            case 0x9a: {
                sub_809D170(1, 0);
                break;
            }
            case 0x9b: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                if (id < 0) break;
                switch(action->unk8[0]) {
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
            case 0x9c: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch(action->unk8[0]) {
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
            case 0x9d: {
                sub_809D1A8(1, 0, curCmd.argShort);
                return 2;
            }
            case 0x9e: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                if (id < 0) break;
                switch(action->unk8[0]) {
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
            case 0x9f: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch(action->unk8[0]) {
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
            case 0xa0: {
                sub_809D1E4(1, 0, curCmd.argShort);
                return 2;
            }
            case 0xa1: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                if (id < 0) break;
                switch(action->unk8[0]) {
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
            case 0xa2: {
                s32 id = action->callbacks->getIndex(action->parentObject);
                PixelPos unk;
                switch(action->unk8[0]) {
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
            case 0xa3: {
                sub_809D220(1, 0, curCmd.argShort);
                return 2;
            }
            case 0xa4: {
                ResetScriptVarArray(scriptData->localVars.buf, curCmd.argShort);
                break;
            }
            case 0xa5: {
                ClearScriptVarArray(scriptData->localVars.buf, curCmd.argShort);
                break;
            }
            case 0xa6: {
                UpdateScriptVarWithImmediate(scriptData->localVars.buf, curCmd.argShort, curCmd.arg1, curCmd.argByte);
                break;
            }
            case 0xa7: {
                UpdateScriptVarWithVar(scriptData->localVars.buf, curCmd.argShort, (s16)curCmd.arg1, curCmd.argByte);
                break;
            }
            case 0xa8: {
                SetScriptVarArrayValue(scriptData->localVars.buf, curCmd.argShort, (u16)curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0xa9: {
                ScenarioCalc(curCmd.argShort, curCmd.arg1, curCmd.arg2);
                break;
            }
            case 0xaa: {
                s32 a, b;
                GetScriptVarScenario(curCmd.argShort, &a, &b);
                ScenarioCalc(curCmd.argShort, a, b+1);
                break;
            }
            case 0xab: {
                SetScriptVarValue(NULL, DUNGEON_ENTER, curCmd.arg1);
                SetScriptVarValue(NULL, DUNGEON_RESULT, curCmd.argShort);
                break;
            }
            case 0xac: {
                SetScriptVarValue(NULL, PLAYER_KIND, curCmd.argShort);
                break;
            }
            case 0xad: {
                sub_80026E8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xae: {
                sub_809733C(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xaf: {
                sub_80973A8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xb0: {
                sub_8097418(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xb1: {
                sub_80975A8(curCmd.argShort, (u8)curCmd.argByte > 0);
                break;
            }
            case 0xb2: {
                SetAdventureAchievement(curCmd.argShort);
                break;
            }
            case 0xb3: {
                if (JudgeVarWithImmediate(NULL, curCmd.argShort, curCmd.arg1, JUDGE_EQ)) {
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xb4: {
                if (JudgeVarWithImmediate(scriptData->localVars.buf, (s16)curCmd.arg1, curCmd.arg2, (u8)curCmd.argByte)) {
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);
                }
                break;
            }
            case 0xb5: {
                if (JudgeVarWithVar(scriptData->localVars.buf, (s16)curCmd.arg1, (s16)curCmd.arg2, (u8)curCmd.argByte)) {
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);
                }
                break;
            }
            case 0xb6: {
                if (GetScriptVarArrayValue(scriptData->localVars.buf, (s16)curCmd.arg1, (u16)curCmd.arg2)) {
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);
                }
                break;
            }
            case 0xb7: {
                if (FlagJudge(GetScriptVarArraySum(scriptData->localVars.buf, (s16)curCmd.arg1), curCmd.arg2, (u8)curCmd.argByte)) {
                    scriptData->script.ptr = FindLabel(action, curCmd.argShort);
                }
                break;
            }
            case 0xb8: {
                if (ScriptVarScenarioBefore(curCmd.argShort, curCmd.arg1, curCmd.arg2)) {
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xb9: {
                if (ScriptVarScenarioEqual(curCmd.argShort, curCmd.arg1, curCmd.arg2)) {
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xba: {
                if (ScriptVarScenarioAfter(curCmd.argShort, curCmd.arg1, curCmd.arg2)) {
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbb: {
                if (sub_80023E4(curCmd.argShort)) {
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbc: {
                if (sub_8098100(curCmd.argShort)) {
                    scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbd: {
                if (sub_80026CC(curCmd.arg1)) {
                        scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbf: {
                if (HasItemInInventory(curCmd.argShort) > 0) {
                        scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                }
                break;
            }
            case 0xbe: {
                if (action->unk8[0] == 1) {
                    if ((s8)GroundLives_IsStarterMon(action->unk8[1])) {
                        scriptData->script.ptr = FindLabel(action, (u8)curCmd.argByte);
                    }
                }
                break;
            }
            case 0x41: {
                s32 val;
                val = FindItemInInventory(curCmd.argShort);
                if ( val >= 0) ShiftItemsDownFrom(val);
                break;
            }
            case 0xc0 ... 0xcb: {
                s32 val;
                PixelPos pos, pos2, pos3;
                switch (curCmd.op) {
                    case 0xc0: {
                        val = GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort);
                        break;
                    }
                    case 0xc1: {
                        val = FlagCalc(
                            GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort),
                            curCmd.arg1,
                            (u8)curCmd.argByte);
                        break;
                    }
                    case 0xc2: {
                        val = FlagCalc(
                            GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort),
                            GetScriptVarValue(scriptData->localVars.buf, (s16)curCmd.arg1),
                            (u8)curCmd.argByte);
                        break;
                    }
                    case 0xc3: {
                        val = OtherRandInt(curCmd.argShort);
                        break;
                    }
                    case 0xc4: {
                        val = GetScriptVarArrayValue(NULL, curCmd.argShort, 0);
                        break;
                    }
                    case 0xc5: {
                        val = GetScriptVarArrayValue(NULL, curCmd.argShort, 1);
                        break;
                    }
                    case 0xc6: {
                        val = (s16)sub_80A8C2C((s16)curCmd.arg1);
                        break;
                    }
                    case 0xc7: {
                        s8 dir;
                        action->callbacks->getDirection(action->parentObject, &dir);
                        val = dir;
                        break;
                    }
                    case 0xca: {
                        action->callbacks->getHitboxCenter(action->parentObject, &pos);
                        pos2 = pos;
                        GroundLink_GetPos((s16)curCmd.arg1, &pos2);
                        pos3.x = pos2.x - pos.x;
                        pos3.y = pos2.y - pos.y;
                        val = (s8) VecDirection8Radial(&pos3);
                        break;
                    }
                    case 0xc8: {
                        s16 tmp = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (tmp >= 0) {
                            PixelPos pos1, pos2, pos3, pos4;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                            action->callbacks->getSize(action->parentObject, &pos2);
                            sub_80A8FD8(tmp, &pos3);
                            sub_80A8F9C(tmp, &pos4);
                            val = SizedDeltaDirection8(&pos1, &pos2, &pos3, &pos4);
                            if (val == -1) {
                                val = SizedDeltaDirection4(&pos1, &gUnknown_81164DC, &pos3, &gUnknown_81164DC);
                            }
                        } else {
                            val = -1;
                        }
                        break;
                    }
                    case 0xc9: {
                        s16 tmp = (s16)sub_80A7AE8((s16)curCmd.arg1);
                        if (tmp >= 0) {
                            PixelPos pos1, pos2, pos3;
                            action->callbacks->getHitboxCenter(action->parentObject, &pos1);
                            action->callbacks->getSize(action->parentObject, &pos2);
                            sub_80A8FD8(tmp, &pos3);
                            val = SizedDeltaDirection8(&pos1, &pos2, &pos3, &gUnknown_81164DC);
                            if (val == -1) {
                                val = SizedDeltaDirection4(&pos1, &gUnknown_81164DC, &pos3, &gUnknown_81164DC);
                            }
                        } else {
                            val = -1;
                        }
                        break;
                    }
                    case 0xcb: {
                        val = sub_809CC90(curCmd.argShort);
                        break;
                    }
                    default: {
                        // The locdata says this is part of an inlined function... :/
                        // "switch type error %d"
                        FatalError(&gUnknown_81166B4, gUnknown_81166C0, curCmd.op);
                    }
                }
                scriptData->script.ptr = ResolveJump(action, val);
                break;
            }
            case 0xcf: {
                scriptData->branchDiscriminant = GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort);
                while (scriptData->script.ptr->op == 0xd0) {
                    if (scriptData->script.ptr->argShort == scriptData->branchDiscriminant)
                        return 2;
                    scriptData->script.ptr++;
                }
                if (scriptData->script.ptr->op == 0xd1) {
                    scriptData->branchDiscriminant = -1;
                    return 2;
                }
                break;
            }
            case 0xd2 ... 0xd8: {
                // DS: Assert(TRUE, "Script command call error SWITCH MENY") [sic]
                const char *out = curCmd.argPtr;
                sNumChoices = 0;
                scriptData->branchDiscriminant = 0;
                switch(curCmd.op) {
                    case 0xd6: case 0xd7: case 0xd8: {
                        s32 disc = GetScriptVarValue(scriptData->localVars.buf, (s16)curCmd.arg2);
                        for (; scriptData->script.ptr->op == 0xd0; scriptData->script.ptr++, scriptData->branchDiscriminant++) {
                            if (scriptData->script.ptr->argShort == disc)
                                out = scriptData->script.ptr->argPtr;
                        }
                        for (; scriptData->script.ptr->op == 0xd1; scriptData->script.ptr++, scriptData->branchDiscriminant++) {
                            if (!out) out = scriptData->script.ptr->argPtr;
                        }
                    }
                }
                if (!out) out = gUnknown_81166D8; // ""
                for (; scriptData->script.ptr->op == 0xd9; scriptData->script.ptr++) {
                    gChoices[sNumChoices].text = scriptData->script.ptr->argPtr;
                    gChoices[sNumChoices].menuAction = sNumChoices + 1;
                    sNumChoices++;
                }
                if (sNumChoices <= 0) break;
                gChoices[sNumChoices].text = NULL;
                gChoices[sNumChoices].menuAction = curCmd.argShort;
                switch (curCmd.op) {
                    case 0xd2: case 0xd3: case 0xd6: {
                        sub_809B028(gChoices, (u8)curCmd.argByte > 0, -1, 0, (s16)curCmd.arg1, out);
                        break;
                    }
                    case 0xd4: case 0xd7: {
                        sub_809B028(gChoices, (u8)curCmd.argByte > 0, -1, 1, (s16)curCmd.arg1, out);
                        break;
                    }
                    case 0xd5: case 0xd8: {
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
            case 0xda: {
                if (GroundScriptCheckLockCondition(action, 1)) {
                    return 2;
                }
                break;
            }
            case 0xdb: {
                scriptData->unk2A = curCmd.argShort;
                return 2;
            }
            case 0xdc: {
                scriptData->unk2A = curCmd.argShort + OtherRandInt(curCmd.arg1 - curCmd.argShort);
                return 2;
            }
            case 0xdd ... 0xe2: {
                return 2; // do action
            }
            case 0xe3: {
                scriptData->branchDiscriminant = curCmd.argShort;
                if (GroundScriptCheckLockCondition(action, curCmd.argShort)) {
                    return 2;
                }
                break;
            }
            case 0xe4: {
                GroundScriptLockJumpZero(curCmd.argShort);
                break;
            }
            case 0xe5: {
                scriptData->branchDiscriminant = curCmd.argShort;
                if (GroundScriptLockCond(action, curCmd.argShort, curCmd.argByte)) {
                    return 2;
                }
                break;
            }
            case 0xe6: {
                scriptData->savedScript = scriptData->script;
            } //fallthrough
            case 0xe7: {
                scriptData->script.ptr = FindLabel(action, curCmd.argShort);
                break;
            }
            case 0xe8: {
                scriptData->savedScript = scriptData->script;
            } // fallthrough
            case 0xe9: {
                scriptData->script.ptr2 = scriptData->script.ptr = gFunctionScriptTable[curCmd.argShort].script;
                break;
            }
            case 0xea: {
                scriptData->savedScript = scriptData->script;
            } // fallthrough
            case 0xeb: {
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
            case 0xec: {
                gUnknown_2039A34 = GetAdjustedGroundMap((s16)GetScriptVarValue(scriptData->localVars.buf, curCmd.argShort));
                GroundCancelAllEntities();
                GroundMap_ExecuteEnter(gUnknown_2039A34);
                break;
            }
            case 0xed: {
                // DS: if (scriptData->savedScript.ptr == NULL) Assert(FALSE, "Script flash stack error");
                scriptData->savedScript.ptr = NULL;
                scriptData->savedScript.ptr2 = NULL;
                break;
            }
            case 0xee: {
                if (scriptData->savedScript.ptr == NULL) {
                    // DS: Assert(FALSE, "Script return stack error");
                    return 0;
                }
                scriptData->script = scriptData->savedScript;
                scriptData->savedScript.ptr = NULL;
                scriptData->savedScript.ptr2 = NULL;
                break;
            }
            case 0xef:
                // DS: if (scriptData->savedScript.ptr != NULL) Assert(FALSE, "Script end stack error");
                return 0;
            case 0xf0:
                return 1;
            case 0xf1:
                return 4; // fatal error?
            case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: {
                // Debug, not in release ROM
                break;
            }
        }
    }
}

UNUSED u32 sub_80A1440(s32 r0, s32 r1, s32 r2)
{
   return sub_80A14E8(NULL, r0, r1, r2);
}

UNUSED bool8 GroundScript_ExecuteTrigger(s16 r0)
{
    s32 ret;
    ScriptInfoSmall scriptInfo;
    Action action;
    const ScriptRef *ptr;

    ptr = &gFunctionScriptTable[r0];

    if(ptr->type != 0xB)
        return FALSE;
    InitActionWithParams(&action, &gGroundScriptTriggerCallbacks, NULL, 0, 0);
    GetFunctionScript(NULL, &scriptInfo, r0);
    GroundScript_ExecutePP(&action, NULL, &scriptInfo, &gUnknown_81166F8);

    action.scriptData.savedScript = action.scriptData.script;
    action.scriptData.savedScript.ptr = &gUnknown_81164E4;
    action.scriptData.savedScript.ptr2 = &gUnknown_81164E4;
    ret = HandleAction(&action, &gUnknown_8116704);
    InitAction2(&action);
    if(ret == 0)
        return TRUE;
    else
        return FALSE;
}

s32 sub_80A14E8(Action *action, u8 idx, u32 r2, s32 r3)
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
                if (sub_80023E4(8) == 0) {
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
                s32 ret;
                s32 ret2;
                if ((action->unkC).arr[0] == 1)
                {
                    u8 text[0x100];
                    DungeonLocation dungLocation;
                    ret = sub_80A8C4C((action->unkC).arr[1], &dungLocation);
                    if(ret != 0)
                    {
                        if (dungLocation.id == DUNGEON_HOWLING_FOREST_2 && ret == 0x104) {
                            return 2;
                        }

                        ret2 = sub_80A90C8((action->unkC).arr[1]);
                        InlineStrcpy(text, gFriendAreaDialogue[ret2]);
                        if (ScriptPrintText(0, 1, text) != 0)
                            return 1;
                    }
                }
            }
            return 0;
        case 0xB:
            return (CountJobsinDungeon(sub_80A2740(GetScriptVarValue(0, DUNGEON_ENTER_INDEX))) > 0);
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
                            SetScriptVarArrayValue(0, TRAINING_PRESENT_LIST, (u16) index, 1);
                            return index - 0x10;
                        }
                    }
                }
                return 0;
            }
        case 0xF:
            return sub_80964E4() == 0 ? 0 : 1;
        case 0x10:
            if(action->unk8[0] == 1)
                if(action->unk8[1] == 0)
                    if(action->unkC.arr[0] == 1)
                    {
                        if(sub_80A87E0(action->unk8[1], sub_80A8E9C(action->unkC.arr[1])) != 0)
                            return 1;
                    }
            return 0;
        case 0x11:
            return sub_80A8D20() == 0 ? 0 : 1;
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
                PokemonStruct1 *ptr;

                ptr = sub_80A8D54(r2);
                if(ptr)
                    return PokemonFlag2(ptr);
            }
            return 0;
        case 0x14:
            if(action->unk8[0] == 1)  {
                if(GetCanMoveFlag(sub_80A8BFC(action->unk8[1])))
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
                PokemonStruct1 *ptr; ptr = sub_80A8D54(1);
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
            sub_80A8F50(gUnknown_2039D98, 0x3C, POKEMON_NAME_LENGTH);
            return 0;
        case 0x19:
            {
                struct unkStruct_808D144 sp_4;
                PokemonStruct1 sp_2c;
                PokemonStruct1 *ptr;
                s32 index;


                UnlockFriendArea(GetFriendArea(MONSTER_MAGNEMITE));
                sp_4 = gUnknown_8116710;
                sub_808D144(&sp_2c, &sp_4);
                ptr = sub_808D1DC(&sp_2c);
                if (ptr == NULL) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    ptr->name[index] = gUnknown_2039D98[index];
                }
                sub_80922B4(gFormatBuffer_Names[r2], gUnknown_2039D98, POKEMON_NAME_LENGTH);
                IncrementAdventureNumJoined();
                return 0;
            }
            break;

        case 0x1A:
            sub_80A8F50(gUnknown_2039D98, 0x53, POKEMON_NAME_LENGTH);
            return 0;

         case 0x1B:
             {
                PokemonStruct1 *pokemon;
                 struct unkStruct_808D144 sp_84;
                 PokemonStruct1 sp_ac;

                UnlockFriendArea(GetFriendArea(MONSTER_ABSOL));
                sp_84 = gUnknown_8116738;
                sub_808D144(&sp_ac, &sp_84);
                pokemon = sub_808D1DC(&sp_ac);
                if(pokemon == NULL) return 1;
                IncrementAdventureNumJoined();
                pokemon->unk0 |= FLAG_ON_TEAM;
                return 0;
             }
        case 0x1C:
            {
                PokemonStruct1 *pokemon = sub_808D434(MONSTER_ABSOL, 0);
                if(pokemon == NULL) return 1;
                pokemon->unk0 |= FLAG_ON_TEAM;
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
             sub_80A8F50(gUnknown_2039D98, 0x7C, POKEMON_NAME_LENGTH);
             return 0;

        case 0x1F:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                struct unkStruct_808D144 sp_108;
                PokemonStruct1 sp_130;

                sp_108 = gUnknown_8116760;
                sub_808D144(&sp_130, &sp_108);
                pokemon = sub_808D1DC(&sp_130);
                if(!pokemon) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    pokemon->name[index] = gUnknown_2039D98[index];
                }
                sub_80922B4(gFormatBuffer_Names[r2], gUnknown_2039D98, POKEMON_NAME_LENGTH);
                IncrementAdventureNumJoined();
                return 0;

            }
            break;

        case 0x20:
            {
                sub_80026E8(0x9E, 0x1);
                if(sub_808D434(MONSTER_ZAPDOS, 0) == NULL)
                {
                    if(sub_808D2E8(MONSTER_ZAPDOS, NULL, ITEM_NOTHING, &gUnknown_8116788, NULL))
                        IncrementAdventureNumJoined();
                }
                if(sub_808D434(MONSTER_MOLTRES, 0) == NULL)
                {
                    if(sub_808D2E8(MONSTER_MOLTRES, NULL, ITEM_NOTHING, &gUnknown_811678C, NULL))
                        IncrementAdventureNumJoined();
                }
                if(sub_808D434(MONSTER_ARTICUNO, 0) == NULL)
                {
                    if(sub_808D2E8(MONSTER_ARTICUNO, NULL, ITEM_NOTHING, &gUnknown_8116790, NULL))
                        IncrementAdventureNumJoined();
                }
                return 0;
            }
            break;


        case 0x21:
            if(HasRecruitedMon(MONSTER_ARTICUNO))
                if(HasRecruitedMon(MONSTER_ZAPDOS))
                    if(HasRecruitedMon(MONSTER_MOLTRES))
                        return 1;
            return 0;
        case 0x22:
            {
                PokemonStruct1 *pokemon = GetPlayerPokemonStruct();

                if(pokemon->speciesNum != MONSTER_ARTICUNO && pokemon->speciesNum != MONSTER_ZAPDOS && pokemon->speciesNum != MONSTER_MOLTRES)
                    return 1;
            }
            return 0;
         case 0x23:
            {
                PokemonStruct1 *pokemon;
                pokemon = GetPlayerPokemonStruct();
                if (pokemon != NULL && pokemon->speciesNum == MONSTER_HO_OH)
                    return 2;
                else if (sub_8098134(MONSTER_HO_OH) != 0)
                    return 1;
            }
            return 0;
        case 0x24:
            sub_80A8F50(gUnknown_2039D98, 0x79, POKEMON_NAME_LENGTH);
            return 0;

        case 0x25:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                struct unkStruct_808D144 sp_188;
                PokemonStruct1 sp_1b0;

                if(!GetFriendAreaStatus(GetFriendArea(MONSTER_LATIOS)))
                    UnlockFriendArea(GetFriendArea(MONSTER_LATIOS));
                sp_188 = gUnknown_8116794;
                sub_808D144(&sp_1b0, &sp_188);
                pokemon = sub_808D1DC(&sp_1b0);
                if(pokemon == NULL) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    pokemon->name[index] = gUnknown_2039D98[index];
                }
                IncrementAdventureNumJoined();
                return 0;
            }

            break;
        case 0x26:
            sub_80A8F50(gUnknown_2039D98, 0x7A, POKEMON_NAME_LENGTH);
            return 0;
        case 0x27:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                struct unkStruct_808D144 sp_208;
                PokemonStruct1 sp_230;

                sp_208 = gUnknown_81167BC;
                sub_808D144(&sp_230, &sp_208);
                pokemon = sub_808D1DC(&sp_230);
                if(pokemon == NULL) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    pokemon->name[index] = gUnknown_2039D98[index];
                }
                IncrementAdventureNumJoined();
                return 0;
            }
            break;

        case 0x28:
            {
                if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                {
                    Item *item = &gUnknown_81167E4;
                    s32 id = item->id;
                    if(IsNotMoneyOrUsedTMItem(id))
                        if(gTeamInventoryRef->teamStorage[id] < 999)
                            gTeamInventoryRef->teamStorage[id] += 1;

                }
                else
                {
                    Item *item = &gUnknown_81167E4;
                    sub_809124C(item->id, 0);
                    FillInventoryGaps();
                }
            }
            return 0;

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
                s32 id = (s16) GetScriptVarValue(0, NEW_FRIEND_KIND);
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
            sub_80A8F50(gUnknown_2039D98, 0x20, POKEMON_NAME_LENGTH);
            return 0;
        case 0x2C:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                  if(r2 != 0)
                  {
                    s32 id = (s16) GetScriptVarValue(0, NEW_FRIEND_KIND);
                      s32 matchMe = id;
                     WriteFriendAreaName(gFormatBuffer_FriendArea,(GetFriendArea((s16) id)), FALSE);
                    if(id == 0)
                        return 0;

                    if(!GetFriendAreaStatus(GetFriendArea(id)))
                        UnlockFriendArea(GetFriendArea(id));
                    pokemon = sub_808D2E8(matchMe, NULL ,ITEM_NOTHING, &gUnknown_81167E8, MOVE_NOTHING);
                    if(pokemon == NULL)
                        return 0;

                    for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                        pokemon->name[index] = gUnknown_2039D98[index];
                    IncrementAdventureNumJoined();
                    return 1;
                  }
                  else
                  {
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
                if(points > 0) {
                    s32 rankAfter;
                    AddToTeamRankPts(points);
                    rankAfter = GetRescueTeamRank();
                    InlineStrcpy(gFormatBuffer_Items[0], GetTeamRankString(rankBefore));
                    InlineStrcpy(gFormatBuffer_Items[1], GetTeamRankString(rankAfter));
                    if(ScriptPrintText(0, -1, gUnknown_81167EC) != 0)
                        return 1;
                }
                else {
                    return 0;
                }
            }
        // breakthrough
        case 0x2F:
            AddToTeamMoney(0x2710);
            return 0;
        case 0x30:
            {
                if(sub_808D278(MONSTER_GARDEVOIR) == 0)
                    return 1;
                else
                    return 0;
            }
            break;
        case 0x31:
            sub_80A8F50(gUnknown_2039D98, 0x52, POKEMON_NAME_LENGTH);
            return 0;

        case 0x32:
            {
                struct unkStruct_808D144 sp_288;
                PokemonStruct1 sp_2b0;
                sp_288 = gUnknown_811681C;
                sub_808D144(&sp_2b0, &sp_288);
                if(sub_808D1DC(&sp_2b0) == 0) {
                    return 1;
                }
                else {
                    IncrementAdventureNumJoined();
                    return 0;
                }
            }
        case 0x33:
            if(ScriptVarScenarioAfter(SCENARIO_MAIN, 0x12, -1))
            {
                if(GetScriptVarValue(0, GROUND_GETOUT) != 4)
                {
                    if (GetScriptVarArrayValue(0, EVENT_GONBE, 0) <= 0)
                    {
                        if(OtherRandInt(0x100) == 0)
                        {
                            SetScriptVarArrayValue(0, EVENT_GONBE, 0, 4);
                            return 1;
                        }
                        else
                            SetScriptVarArrayValue(0, EVENT_GONBE, 0, 1);
                    }
                }
            }
            return 0;

        case 0x34:
            {
                s32 index;
                s32 id;
                Item *item = &gUnknown_8116844;
                for(index = 0; index < 3; index++)
                {
                    if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                    {
                        id = item->id;
                        if(IsNotMoneyOrUsedTMItem(id))
                            if(gTeamInventoryRef->teamStorage[id] < 999)
                                gTeamInventoryRef->teamStorage[id] += 1;

                    }
                    else
                    {
                        sub_809124C(item->id, 0);
                        FillInventoryGaps();
                    }
                }
            }
            return 0;
        case 0x35:
            {
                PokemonStruct1 *pokemon = GetPlayerPokemonStruct();
                if(pokemon != NULL && pokemon->speciesNum == MONSTER_CHANSEY)
                    return 2;
                else
                    if(sub_8098134(MONSTER_CHANSEY) != 0)
                        return 1;
                    else
                        return 0;
            }
            break;

        case 0x38:
            sub_80A56A0(0, 1);
            return 0;
        case 0x36: {
            s32 sp_328[2];
            sp_328[0] = r2;
            sp_328[1] = r3;
            sub_80A56F0(sp_328);
            return 0;
        }
        case 0x37: {
            s32 sp_330[2];
            sp_330[0] = r2;
            sp_330[1] = r3;
            sub_80A5704(sp_330);
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
                index = 0;
                for(index = 0; index < 0x18; index = (s16)(index + 1))
                {
                    sub_80A86C8(index, 0x400000);
                }
                for (index = 0; index < 0x10; index = (s16)(index + 1))
                {
                    sub_80AC1B0(index, 0x400000);
                }
                for (index = 0; index < 0x10; index = (s16)(index + 1))
                {
                    sub_80AD0C8(index, 0x400000);
                }
            }
            return 0;
        case 0x3D: {
            s32 sp_338[2];
            sp_338[0] = r2;
            sp_338[1] = r3;
            sub_80A59A0(0, sp_338, sub_80A5984(1, sp_338));
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
                sp_308.script = gFunctionScriptTable[406].script; // MOVE_DEBUG_CAMERA
                ret = GroundEffect_Add(-1, &sp_308, r2, r3);
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
                s32 ret;
                s32 held = gRealInputs.held;
                s32 pressed = gRealInputs.pressed;
                if(!(pressed & (START_BUTTON | SELECT_BUTTON)))
                {
                    PixelPos sp_368;
                    ret = sub_809CFE8(held);
                    if((s8)ret != -1)
                    {
                        s32 to;
                        sp_368 = SetVecFromDirectionSpeed(ret,0x100);

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
                xxx_call_start_new_bgm(gUnknown_2039DA8);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x45:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                xxx_call_fade_in_new_bgm(gUnknown_2039DA8, r2);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x46:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                xxx_call_queue_bgm(gUnknown_2039DA8);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x47:
            sub_80997F4(r2, r3);
            return 0;
        case 0x48:
            sub_80997F4(0x1E, r2);
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

    if(gAnyScriptLocked == 0) return;

    gAnyScriptLocked = 0;
    index = 0;
    for (index = 0; index <= 0x80; index++) {
        if(gScriptLocks[index] != 0) {
            Log(1, gUnknown_8116848, index);
            cond  = GroundMapNotifyAll(index);
            cond |= GroundLivesNotifyAll(index);
            cond |= GroundObjectsNotifyAll(index);
            cond |= GroundEffectsNotifyAll(index);

            if(gScriptLockConds[index] != 0) {
               if (cond) {
                    GroundMapNotifyAll(index | 0x80);
                    GroundLivesNotifyAll(index | 0x80);
                    GroundObjectsNotifyAll(index | 0x80);
                    GroundEffectsNotifyAll(index | 0x80);
                    gScriptLocks[index] = gScriptLockConds[index] = 0;
               }
            } else {
               gScriptLocks[index] = 0;
            }
        }
    }
}

const ScriptCommand *FindLabel(Action *action, s32 r1)
{
    ScriptCommand script;
    const ScriptCommand *scriptPtr2;
    const ScriptCommand *scriptPtr;

    scriptPtr2 = action->scriptData.script.ptr2;
    scriptPtr = scriptPtr2 + 1;

    while(1) {
        script = *scriptPtr;
        scriptPtr++;

        if(script.op == 0xF4 && r1 == script.argShort) break;

        // DS: Assert(script.op != 0, "script search label error %d", label)
        // DS: Assert(script.op != 0xF6, "script search label error %d", label)
    }
    return scriptPtr;
}

const ScriptCommand *ResolveJump(Action *action, s32 r1)
{
    ScriptCommand script;
    const ScriptCommand *scriptPtr;
    s32 temp;

    scriptPtr = action->scriptData.script.ptr;

    while(1) {
        script = *scriptPtr;

        if (script.op == 0xCC)
        {
            if(FlagJudge(r1, script.arg1, JUDGE_EQ))
                return FindLabel(action, script.argShort);
        }
        else if (script.op == 0xCD)
        {
            if(FlagJudge(r1, script.arg1, script.argByte))
                return FindLabel(action, script.argShort);
        }
        else if (script.op == 0xCE)
        {
            temp = GetScriptVarValue(action->scriptData.localVars.buf, (s16)script.arg1);
            if(FlagJudge(r1, temp, script.argByte))
                return FindLabel(action, script.argShort);
        }
        else
        {
            return scriptPtr;
        }
        scriptPtr++;
    }
}
