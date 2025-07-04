#include "global.h"
#include "globaldata.h"
#include "data_script.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "debug.h"
#include "memory.h"

typedef struct GroundEffect {
    // size: 0x1C4
    u8 unk0[4];
    s16 id;
    s16 kind; // kind
    s16 group; // scriptID / group
    s8 sector; // sector
    u8 unused;
    PixelPos unkC;
    PixelPos unk14;
    s8 direction1;
    PixelPos unk20;
    PixelPos unk28;
    PixelPos unk30;
    Action action;
    u32 flags;
    s8 direction;
    PixelPos unk124;
    PixelPos unk12C;
    PixelPos unk134;
    u8 directionRelated;
    s16 unk13E;
    s16 unk140;
    struct UnkGroundSpriteStruct unk144;
} GroundEffect;


IWRAM_INIT GroundEffect* gGroundEffects = NULL;  // size 16 array
#define NUM_GROUND_EFFECTS 0x10


struct GroundEffectTypeData
{
    s16 type;
    u8 unk2;
    u8 unk3;
};


extern struct GroundEffectTypeData gGroundEffectTypes[];

extern bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s32 _index);

void GroundEffect_Delete(s32);
void DeleteGroundEffects(void);
s32 GroundEffect_Add(s32 _id,const GroundEffectData *effectData,s32 _group,s32 _sector);

const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
bool8 GetCurrentDungeonBounds(PixelPos *, PixelPos *);
void sub_80A7688(struct UnkGroundSpriteStruct *ptr, s32 unused, s32 a2_, s32 a3);
extern void SetPredefinedScript(Action *param_1, s16 index, const ScriptCommand *param_3);
void sub_80A7714(struct UnkGroundSpriteStruct *);
void sub_80A6688(struct UnkGroundSpriteStruct *, s32);
extern bool8 GroundScriptNotify(Action*, s32);
extern bool8 GroundScript_Cancel(Action *r0);
s32 sub_80AD3E0(GroundEffect *, PixelPos *);
extern bool8 sub_80A66F8(struct UnkGroundSpriteStruct *ptr);
extern bool8 sub_80A671C(struct UnkGroundSpriteStruct *ptr);
bool8 sub_80A66D4(struct UnkGroundSpriteStruct *ptr);
void sub_80A7720(struct UnkGroundSpriteStruct *ptr, PixelPos *pixelPos, s32 a2);


static s16 CallbackEffectGetIndex(void *ptr);
static void CallbackEffectGetSize(void *effectPtr_, PixelPos *out);
static void CallbackEffectSetHitboxPos(void *effectPtr_, PixelPos *posOrNull);
static void CallbackEffectSetPositionBounds(void *effectPtr_, PixelPos *from, PixelPos *to);
static void CallbackEffectGetHitboxCenter(void *effectPtr_, PixelPos *out);
static s32 CallbackEffectMoveReal(void *effectPtr_, PixelPos *pos);
static void CallbackEffectGetPosHeightAndUnk(void *effectPtr_, u32 *height, u32 *unk);
static void CallbackEffectSetPosHeight(void *effectPtr_, u32 height);
static void CallbackEffectGetDirection(void *effectPtr_, s8 *dir);
static void CallbackEffectSetDirection(void *effectPtr_, s32 dir_);
static void CallbackEffectSetEventIndex(void *effectPtr_, u16 a1);
static void CallbackEffectSetUnk_80AD670(void *effectPtr_, s32 a1_, s32 a2);
static bool8 CallbackEffectSpriteRelatedCheck_80AD690(void *effectPtr_);
static bool8 CallbackEffectSpriteRelated_80AD6B4(void *effectPtr_);
static void CallbackEffectGetFlags(void *effectPtr_, u32 *flags);
static void CallbackEffectSetFlags(void *effectPtr_, u32 flags);
static void CallbackEffectClearFlags(void *effectPtr_, u32 flags);
static s32 CallbackEffectMoveRelative(void *effectPtr_, PixelPos *pos);

static const CallbackData gGroundEffectCallbacks = {
    .maybeId = 3,
    .getIndex = CallbackEffectGetIndex,
    .getSize = CallbackEffectGetSize,
    .getHitboxCenter = CallbackEffectGetHitboxCenter,
    .getPosHeightAndUnk = CallbackEffectGetPosHeightAndUnk,
    .getDirection = CallbackEffectGetDirection,
    .getFlags = CallbackEffectGetFlags,
    .setHitboxPos = CallbackEffectSetHitboxPos,
    .setPositionBounds = CallbackEffectSetPositionBounds,
    .moveReal = CallbackEffectMoveReal,
    .setPosHeight = CallbackEffectSetPosHeight,
    .setDirection = CallbackEffectSetDirection,
    .setEventIndex = CallbackEffectSetEventIndex,
    .livesOnlyNullsub = NULL,
    .func38 = CallbackEffectSetUnk_80AD670,
    .setFlags = CallbackEffectSetFlags,
    .clearFlags = CallbackEffectClearFlags,
    .func44_livesOnlySpriteRelated = NULL,
    .moveRelative = CallbackEffectMoveRelative,
    .func4C_spriteRelatedCheck = CallbackEffectSpriteRelatedCheck_80AD690,
    .func50_spriteRelated = CallbackEffectSpriteRelated_80AD6B4,
};
extern const u8 gUnknown_81185D8[];
#define FAKE_FILENAME gUnknown_81185D8
 






































static const struct ScriptCommand gUnusedScript[] = {
    DEBUGINFO, // Needs to be line 155
    LABEL(0),
    WAIT(0x78),
    JUMP_LABEL(0),
};
const u8 gUnknown_81185D8[] = "../ground/ground_effect.c";

const s16 gUnknown_81185F2[] = { -1, 0x800, 0x801, 0x1000, 0};

void AllocGroundEffects(void)
{
    s32 index;
    GroundEffect* current;
    
    gGroundEffects = MemoryAlloc(NUM_GROUND_EFFECTS * sizeof(GroundEffect), 6);
    current = gGroundEffects;
    for (index = 0; index < NUM_GROUND_EFFECTS; index = (s16) (index + 0x1), current++) {    
        current->kind = -1;
    }
    DeleteGroundEffects();
}


void DeleteGroundEffects(void)
{
    s32 index;
    GroundEffect* current;
    
    current = gGroundEffects;
    for (index = 0; index < NUM_GROUND_EFFECTS; index = (s16) (index + 0x1), current++) {    
        if(current->kind != -1)
            GroundEffect_Delete(index);
    }
}

void FreeGroundEffects(void)
{
    DeleteGroundEffects();
    MemoryFree(gGroundEffects);
    gGroundEffects = NULL;
}

void GroundEffect_Select(s32 scriptID, s32 group, s32 sector)
{
    const struct GroundScriptHeader *scriptPtr;
    const struct GroundScriptSector *sectorPtr;
    const struct GroundScriptGroup *groupPtr;

    s32 i;
    s32 size;
    const GroundEffectData *effectData;
    s32 sector_s32;
    s32 group_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    group_s32 = (s16)group;
    sector_s32 = (s8)sector;
    scriptPtr = GetGroundScript(scriptID_s32, DEBUG_LOC_PTR(gUnknown_81185D8, 0x106, "GroundEffect_Select"));
    Log(0,"GroundEffect Select %3d  %3d  %3d", scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    effectData = sectorPtr->effects;

    size = sectorPtr->nEffects;
    for (i = 0; i < size; i++, effectData++)
    {
        GroundEffect_Add(-1,effectData,group_s32,sector_s32);
    }
}

void GroundEffect_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    GroundEffect *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log(0,"GroundEffect Cancel %3d", scriptID_s32);

    index = 0;
    ptr = &gGroundEffects[0];
    for(; index < NUM_GROUND_EFFECTS; index = (s16)(index + 1), ptr++)
    {
        if((ptr->kind != -1) && (ptr->group == scriptID_s32))
            if(sector_s32 < 0 || ptr->sector == sector_s32)
                GroundEffect_Delete(index);
    }
}

void GroundEffect_CancelBlank(void)
{
    s32 index;
    GroundEffect *ptr;
    PixelPos pos;

    Log(0, "GroundEffect CancelBlank");

    index = 0;
    ptr = &gGroundEffects[0];
    for (; index < NUM_GROUND_EFFECTS; index = (s16)(index + 1), ptr++)
    {
        if (ptr->kind != -1)
        {
            pos.x = ptr->unk124.x + ptr->unk14.x;
            pos.y = ptr->unk124.y + ptr->unk14.y;
            if (!IsOnscreen_80A675C(&ptr->unk144, &pos))
            {
                GroundEffect_Delete(index);
            }
        }
    }
}

UNUSED s32 GroundEffect_Find(s32 a0_) {
    s32 index;
    s32 a0;
    GroundEffect *ptr;

    a0 = (s16)a0_;
    index = 0;
    ptr = &gGroundEffects[0];
    for (; index < NUM_GROUND_EFFECTS; index = (s16)(index + 1), ptr++)
    {
        if (ptr->kind == a0)
        {
            return index;
        }
    }
    return -1;
}

s32 GroundEffect_Add(s32 _id, const GroundEffectData *effectData,s32 _group,s32 _sector)
{
    struct GroundEffectTypeData *puVar4;
    s32 group;
    const ScriptCommand *script;
    s32 sector;
    GroundEffect *parent;
    s32 id;
    bool8 bVar10;
    s32 index;

    id = (short)_id;
    group = (short)_group;
    sector = (s8)_sector;

    puVar4 = &gGroundEffectTypes[effectData->kind];

    if (id < 0) {
        for(index = 0, parent = gGroundEffects; index < 0x10; index = (s16)(index + 1), parent++)
        {
            if(parent->kind == -1)
            {
                id = index;
                break;
            }
        }

    }
    if (id < 0) {
        return -1;
    }  

    parent = &gGroundEffects[id];
    Log(0,"GroundEffect Add id %3d  kind %3d  type %3d  group %3d  sector %3d",id,effectData->kind,puVar4->type,group,sector);
    bVar10 = parent->kind == -1;
    parent->id = id;
    parent->kind = effectData->kind;
    parent->group = group;
    parent->sector = sector;
    switch(puVar4->type) {
        case 1:
            parent->flags = 0x20400000;
            break;
        case 2:
            parent->flags = 0x220c0000;
            break;
        case 3:
            parent->flags = 0x020c0000;
            break;
        case 4:
            parent->flags = 0x22000000;
            break;
        case 5:
            parent->flags = 0x22020000;
            break;
        default:
            parent->flags = 0x220c0000;
            break;
    }
    if (puVar4->unk2 == '\0') {
        parent->unkC.x = effectData->width << 0xb;
        parent->unkC.y = effectData->height << 0xB;
    }
    else {
        parent->unkC.x = puVar4->unk2 << 0xb;
        parent->unkC.y = puVar4->unk3 << 0xb;
    }
    parent->unk14.x = parent->unkC.x / 2;
    parent->unk14.y = parent->unkC.y / 2;
    parent->direction1 = effectData->unk1;

    SetUnkInGroundEvent(&effectData->pos, &parent->unk20);

    if (bVar10) {
        parent->direction = parent->direction1;
        parent->unk124.x = parent->unk20.x - parent->unk14.x;
        parent->unk12C.x = parent->unk20.x + parent->unk14.x;
        parent->unk124.y = parent->unk20.y - parent->unk14.y;
        parent->unk12C.y = parent->unk20.y + parent->unk14.y;
        parent->unk134.x = parent->unk134.y = 0;
    }
    GetCurrentDungeonBounds(&parent->unk28,&parent->unk30);
    if (bVar10) {
        parent->unk13E = 0x800;
        parent->directionRelated = TRUE;
        parent->unk140 = 0;
        sub_80A7688(&parent->unk144,id,parent->kind,parent->flags);
    }

    InitActionWithParams(&parent->action,&gGroundEffectCallbacks,parent,group,sector);
    script = effectData->script;
    if (script == NULL) {
        if (puVar4->type == 1) {
            script = gFunctionScriptTable[58].script;
        }
        if (script == NULL) 
            return id;
    }
    SetPredefinedScript(&parent->action,0,script);
    ExecutePredefinedScript(&parent->action,NULL,0,DEBUG_LOC_PTR(gUnknown_81185D8, 0x210, "GroundEffect_Add"));

    return id;
}

void GroundEffect_Delete(s32 _id)
{
    s32 id = (s16)_id;
    GroundEffect *parent = &gGroundEffects[id];

    Log(0, "GroundEffect Delete id %3d", id);
    sub_80A7714(&parent->unk144);

    InitAction2(&parent->action);
    parent->kind = -1;
}

void sub_80AD0C8(s32 _id, s32 flags)
{
    s32 id = (s16)_id;
    GroundEffect *parent = &gGroundEffects[id];

    if(parent->kind != -1)
    {
        parent->flags |= flags;   
        sub_80A6688(&parent->unk144, parent->flags);
    }
}

static void sub_80AD10C(s32 index_, s32 flag)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];

    if(parent->kind != -1)
    {
        parent->flags &= (0x337fffff ^ flag);
        sub_80A6688(&parent->unk144, parent->flags);
    }
}

Action *sub_80AD158(s32 index_)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];

    if(parent->kind != -1)
        return &parent->action;
    else
        return NULL;
}

UNUSED static bool8 sub_80AD18C(s32 index_, ScriptInfoSmall *scriptInfo, s32 a2_)
{
    s32 index = (s16)index_;
    s32 a2 = (s16)a2_;
    GroundEffect *parent = &gGroundEffects[index];

    if(parent->kind != -1)
        return GetPredefinedScript(&parent->action, scriptInfo, a2);
    else
        return FALSE;
}

bool8 GroundEffect_ExecuteScript(s32 index_, void *a1, ScriptInfoSmall *script)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];

    Log(0, "GroundEffect Execute %3d  ", index);

    if(parent->kind != -1)
    {
        GroundScript_ExecutePP(&parent->action, (ActionUnkIds *)a1, script, DEBUG_LOC_PTR(gUnknown_81185D8, 0x290, "GroundEffect_ExecuteScript"));
        parent->directionRelated = TRUE;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 GroundEffectsNotifyAll(s32 index_)
{
    s32 index = (s16)index_;
    s32 counter;
    GroundEffect *parent = &gGroundEffects[0];
    bool8 flag = FALSE;
    
    for(counter = 0; counter < NUM_GROUND_EFFECTS; counter = (s16)(counter + 1), parent++)
    {
        if(parent->kind != -1)
            flag |= GroundScriptNotify(&parent->action, index);
    }

    return flag;
}

bool8 GroundEffectsCancelAll(void)
{
    s32 counter;
    GroundEffect *parent = &gGroundEffects[0];
    bool8 flag = FALSE;
    
    for(counter = 0; counter < NUM_GROUND_EFFECTS; counter = (s16)(counter + 1), parent++)
    {
        if(parent->kind != -1)
            flag |= GroundScript_Cancel(&parent->action);
    }

    return flag;
}

static UNUSED s16 sub_80AD2D8(s32 index_)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];
    return parent->kind;
}

static UNUSED s16 GroundEffect_GetFlags(s32 index_, s32 *flags)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];
    *flags = parent->flags;
    return parent->kind;
}

static UNUSED s16 sub_80AD320(s32 index_, PixelPos *a1)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];
    if(parent->kind == -1)
    {
        a1->x = 0;
        a1->y = 0;
    }
    else
    {
        *a1 = parent->unkC;
    }
    return parent->kind;
}

s16 sub_80AD360(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];

    if(parent->kind == -1)
    {
        pos->x = 0;
        pos->y = 0;
    }
    else {
       pos->x = parent->unk124.x + parent->unk14.x; 
       pos->y = parent->unk124.y + parent->unk14.y; 
    }

    return parent->kind;
}

s16 sub_80AD3B4(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];

    sub_80AD3E0(parent, pos);
    
    return parent->kind;
}

s32 sub_80AD3E0(GroundEffect *param_1,PixelPos *param_2)
{
    PixelPos local_1c = {param_2->x - param_1->unk14.x, param_2->y - param_1->unk14.y};
    PixelPos local_14 = {param_2->x + param_1->unk14.x, param_2->y + param_1->unk14.y};

    if ((local_1c.x < param_1->unk28.x) || (local_14.x >= param_1->unk30.x) ||
        (local_1c.y < param_1->unk28.y) || (local_14.y >= param_1->unk30.y)) {
        return 1;
    }
    else {
        param_1->unk124 = local_1c;
        param_1->unk12C = local_14; 
        return 0;
    }
}

s32 sub_80AD430(GroundEffect *param_1,PixelPos *param_2)
{
    PixelPos iVar2 = {param_1->unk124.x + param_2->x, param_1->unk124.y + param_2->y};
    PixelPos uVar4 = {param_1->unk12C.x + param_2->x, param_1->unk12C.y + param_2->y};

    if (iVar2.x < param_1->unk28.x) {
        iVar2.x = param_1->unk28.x;
        uVar4.x = param_1->unk28.x + param_1->unkC.x;
    }
    else if (uVar4.x >= param_1->unk30.x) {
        iVar2.x = param_1->unk30.x - param_1->unkC.x;
        uVar4.x = param_1->unk30.x;
    }

    if (iVar2.y < param_1->unk28.y) {
        iVar2.y = param_1->unk28.y;
        uVar4.y = param_1->unk28.y + param_1->unkC.y;
    }
    else if (uVar4.y >= param_1->unk30.y){
        iVar2.y = param_1->unk30.y - param_1->unkC.y;
        uVar4.y = param_1->unk30.y;
    }

    param_1->unk124 = iVar2;
    param_1->unk12C = uVar4;
    return 0;
}

static s16 CallbackEffectGetIndex(void *ptr) 
{
    struct GroundEffect *groundObject = ptr;
    return groundObject->id;
}

static void CallbackEffectGetSize(void *objectPtr_, PixelPos *out)
{
    struct GroundEffect *objectPtr = objectPtr_;
    *out = objectPtr->unkC;
}

static void CallbackEffectSetHitboxPos(void *objectPtr_, PixelPos *posOrNull)
{
    struct GroundEffect *objectPtr = objectPtr_;

    if (posOrNull != NULL) {
        objectPtr->unk124.x = posOrNull->x - objectPtr->unk14.x;
        objectPtr->unk12C.x = posOrNull->x + objectPtr->unk14.x;
        objectPtr->unk124.y = posOrNull->y - objectPtr->unk14.y;
        objectPtr->unk12C.y = posOrNull->y + objectPtr->unk14.y;
    }
    else {
        objectPtr->unk124.x = objectPtr->unk20.x - objectPtr->unk14.x;
        objectPtr->unk12C.x = objectPtr->unk20.x + objectPtr->unk14.x;
        objectPtr->unk124.y = objectPtr->unk20.y - objectPtr->unk14.y;
        objectPtr->unk12C.y = objectPtr->unk20.y + objectPtr->unk14.y;
        objectPtr->unk134.x = objectPtr->unk134.y = 0;
        if (objectPtr->direction != objectPtr->direction1) {
            objectPtr->directionRelated = TRUE;
        }
        objectPtr->direction = objectPtr->direction1;
    }
}

static void CallbackEffectSetPositionBounds(void *objectPtr_, PixelPos *from, PixelPos *to)
{
    struct GroundEffect *objectPtr = objectPtr_;

    objectPtr->unk28 = *from;
    objectPtr->unk30 = *to;
}

static void CallbackEffectGetHitboxCenter(void *objectPtr_, PixelPos *out)
{
    struct GroundEffect *objectPtr = objectPtr_;

    out->x = objectPtr->unk124.x + objectPtr->unk14.x;
    out->y = objectPtr->unk124.y + objectPtr->unk14.y;
}

static s32 CallbackEffectMoveReal(void *objectPtr_, PixelPos *pos)
{
    struct GroundEffect *objectPtr = objectPtr_;
    return sub_80AD3E0(objectPtr, pos);
}

static void CallbackEffectGetPosHeightAndUnk(void *objectPtr_, u32 *height, u32 *unk)
{
    struct GroundEffect *objectPtr = objectPtr_;

    *height = objectPtr->unk134.x;
    *unk= objectPtr->unk134.y;
}

static void CallbackEffectSetPosHeight(void *objectPtr_, u32 height)
{
    struct GroundEffect *objectPtr = objectPtr_;
    objectPtr->unk134.x = height;

}

static void CallbackEffectGetDirection(void *objectPtr_, s8 *dir)
{
    struct GroundEffect *objectPtr = objectPtr_;
    *dir = objectPtr->direction;

}

static void CallbackEffectSetDirection(void *livesPtr_, s32 direction)
{
    struct GroundEffect *livesPtr = livesPtr_;
    s32 dir = (s8) direction;

    if (dir != -1) {
        livesPtr->direction = dir;
    }
}

static void CallbackEffectSetEventIndex(void *livesPtr_, u16 a1) {
    struct GroundEffect *livesPtr = livesPtr_;

    u32 r1;
    u16 f1 = a1 & 0xFF;

    if (f1 != 0)
    {
        r1 = gUnknown_81185F2[f1];
    }
    else
    {
         r1 = livesPtr->unk13E;
    }

    if(livesPtr->unk13E != (s16) r1)
    {
        livesPtr->unk13E = r1;
        livesPtr->directionRelated = TRUE;
    }
    else if((livesPtr->unk13E & 0x1000))
        livesPtr->directionRelated = TRUE;
}

static void CallbackEffectSetUnk_80AD670(void *objectPtr_, s32 a1_, s32 a2) {
    struct GroundEffect *livesPtr = objectPtr_;

    s32 a1Match = (s16) a1_;
    #ifndef NONMATCHING
    register s16 a1 asm("r2") = a1Match;
    #else
    s32 a1 = a1Match;
    #endif

    if (a1Match == 0) {
        a1 = 448;
    }

    livesPtr->unk140 = a1;
}

static bool8 CallbackEffectSpriteRelatedCheck_80AD690(void *objectPtr_)
{
    struct GroundEffect *livesPtr = objectPtr_;

    if (livesPtr->directionRelated) {
        return TRUE;
    }
    else {
        return sub_80A66F8(&livesPtr->unk144);
    }
}

static bool8 CallbackEffectSpriteRelated_80AD6B4(void *objectPtr_)
{
    struct GroundEffect *livesPtr = objectPtr_;

    if (livesPtr->unk140 != 0) {
        return TRUE;
    }
    else {
        return sub_80A671C(&livesPtr->unk144);
    }
}

static void CallbackEffectGetFlags(void *livesPtr_, u32 *flags)
{
    struct GroundEffect *livesPtr = livesPtr_;

    *flags = livesPtr->flags;
}

static void CallbackEffectSetFlags(void *livesPtr_, u32 flags)
{
    struct GroundEffect *livesPtr = livesPtr_;

    sub_80AD0C8(livesPtr->id, flags);
}

static void CallbackEffectClearFlags(void *livesPtr_, u32 flags)
{
    struct GroundEffect *livesPtr = livesPtr_;

    sub_80AD10C(livesPtr->id, flags);
}

static s32 CallbackEffectMoveRelative(void *livesPtr_, PixelPos *pos)
{
    struct GroundEffect *livesPtr = livesPtr_;

    return sub_80AD430(livesPtr, pos);
}

extern s16 HandleAction(Action *action, DebugLocation *debug);

void GroundEffect_Action(void)
{
    GroundEffect *objectPtr;
    s32 i;
    s32 ret;

    for (objectPtr = &gGroundEffects[0], i = 0; i < NUM_GROUND_EFFECTS; i = (s16)(i + 1), objectPtr++)
    {
        if (objectPtr->kind != -1) {
            ret = HandleAction(&objectPtr->action, DEBUG_LOC_PTR(gUnknown_81185D8, 0x560, "GroundEffect_Action"));
            switch(ret)
            {
                case 4:
                    GroundEffect_Delete(i);
                    continue;
                case 0:
                    ExecutePredefinedScript(&objectPtr->action, NULL, 1, DEBUG_LOC_PTR(gUnknown_81185D8, 0x56A, "GroundEffect_Action"));
                    break;
            }

            if (objectPtr->directionRelated) {
                objectPtr->directionRelated = FALSE;
                sub_80A6EFC(&objectPtr->unk144,objectPtr->unk13E & 0x1f00,(s8)objectPtr->unk13E);
            }
        }
    }
}

void sub_80AD7AC(void)
{
    GroundEffect *objectPtr;
    s32 i;
    s32 minus1;


    for (objectPtr = &gGroundEffects[0], i = 0, minus1 = -1; i < NUM_GROUND_EFFECTS; i = (s16)(i + 1), objectPtr++)
    {
        minus1 = (s16)minus1;
        if (objectPtr->kind != (s16)minus1) {

            PixelPos pos = {objectPtr->unk124.x + (objectPtr->unk14).x, objectPtr->unk124.y + (objectPtr->unk14).y};
            s32 num = objectPtr->unk134.x + objectPtr->unk134.y;        

            if ((sub_80A66D4(&objectPtr->unk144))) {
                objectPtr->directionRelated = FALSE;
                sub_80A6EFC(&objectPtr->unk144,objectPtr->unk13E & 0x1f00,(s8)objectPtr->unk13E);
            }
            if (objectPtr->unk140 != 0) {
                sub_80A7040(&objectPtr->unk144,objectPtr->unk140,objectPtr->direction,0);
                objectPtr->unk140 = 0;
            }
            sub_80A7720(&objectPtr->unk144, &pos, num);
        }
    }
}
