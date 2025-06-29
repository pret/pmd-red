#include "global.h"
#include "globaldata.h"
#include "data_script.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "debug.h"
#include "memory.h"

void DeleteGroundEffects(void);

// size must be 0x1c4
// NOTE: exact structure as GroundEffect
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
    s16 unk0;
    u8 unk2;
    u8 unk3;
};


extern struct GroundEffectTypeData gGroundEffectTypes[];

extern DebugLocation gUnknown_8118610;
extern const u8 gUnknown_811861C[];
extern const u8 gUnknown_8118640[];
extern const u8 gUnknown_8118658[];
extern const u8 gUnknown_8118674[];
extern DebugLocation gUnknown_81186CC;
extern const u8 gUnknown_81186D8[];
extern const u8 gUnknown_81186F4[];
extern DebugLocation gUnknown_811872C;

extern bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s32 _index);


void GroundEffect_Delete(s32);
s32 GroundEffect_Add(s32 _id,const GroundEffectData *effectData,s32 _group,s32 _sector);

const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
bool8 GetCurrentDungeonBounds(PixelPos *, PixelPos *);
void sub_80A7688(struct UnkGroundSpriteStruct *ptr, s32 unused, s32 a2_, s32 a3);
extern void SetPredefinedScript(Action *param_1, s16 index, const ScriptCommand *param_3);
void sub_80A7714(struct UnkGroundSpriteStruct *);
void sub_80A6688(struct UnkGroundSpriteStruct *, s32);
extern bool8 GroundScriptNotify(Action*, s32);
extern bool8 GroundScript_Cancel(Action *r0);

extern s16 CallbackEffectGetIndex(void *ptr);
extern void CallbackEffectGetSize(void *effectPtr_, PixelPos *out);
extern void CallbackEffectSetHitboxPos(void *effectPtr_, PixelPos *posOrNull);
extern void CallbackEffectSetPositionBounds(void *effectPtr_, PixelPos *from, PixelPos *to);
extern void CallbackEffectGetHitboxCenter(void *effectPtr_, PixelPos *out);
extern s32 CallbackEffectMoveReal(void *effectPtr_, PixelPos *pos);
extern void CallbackEffectGetPosHeightAndUnk(void *effectPtr_, u32 *height, u32 *unk);
extern void CallbackEffectSetPosHeight(void *effectPtr_, u32 height);
extern void CallbackEffectGetDirection(void *effectPtr_, s8 *dir);
extern void CallbackEffectSetDirection(void *effectPtr_, s32 dir_);
extern void CallbackEffectSetEventIndex(void *effectPtr_, u16 a1);
extern void CallbackEffectSetUnk_80AD670(void *effectPtr_, s32 a1_, s32 a2);
extern bool8 CallbackEffectSpriteRelatedCheck_80AD690(void *effectPtr_);
extern bool8 CallbackEffectSpriteRelated_80AD6B4(void *effectPtr_);
extern void CallbackEffectGetFlags(void *effectPtr_, u32 *flags);
extern void CallbackEffectSetFlags(void *effectPtr_, u32 flags);
extern void CallbackEffectClearFlags(void *effectPtr_, u32 flags);
extern s32 CallbackEffectMoveRelative(void *effectPtr_, PixelPos *pos);

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

void AllocGroundEffects()
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
    scriptPtr = GetGroundScript(scriptID_s32, &gUnknown_8118610);
    Log('\0',gUnknown_811861C, scriptID_s32, group_s32, sector_s32);

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


    Log('\0',gUnknown_8118640, scriptID_s32);

    index = 0;
    ptr = &gGroundEffects[0];
    for(; index < NUM_GROUND_EFFECTS; index = (s16)(index + 1), ptr++)
    {
        if((ptr->kind != -1) && (ptr->group == scriptID_s32))
            if(sector_s32 < 0 || ptr->sector == sector_s32)
                GroundEffect_Delete(index);
    }
}

void GroundEffect_CancelBlank()
{
    s32 index;
    GroundEffect *ptr;
    PixelPos pos;

    Log(0, gUnknown_8118658); // "GroundEffect CancelBlank"

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

// Unused
s32 GroundEffect_Find(s32 a0_) {
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

// https://decomp.me/scratch/3VqaG  - 99.68% matched (Seth)
NAKED
s32 GroundEffect_Add(s32 _id, const GroundEffectData *effectData,s32 _group,s32 _sector)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r10\n"
	"\tmov r6, r9\n"
	"\tmov r5, r8\n"
	"\tpush {r5-r7}\n"
	"\tsub sp, 0x10\n"
	"\tadds r7, r1, 0\n"
	"\tlsls r0, 16\n"
	"\tasrs r6, r0, 16\n"
	"\tlsls r2, 16\n"
	"\tasrs r2, 16\n"
	"\tmov r10, r2\n"
	"\tlsls r3, 24\n"
	"\tasrs r3, 24\n"
	"\tmov r9, r3\n"
	"\tldrb r0, [r7]\n"
	"\tlsls r0, 2\n"
	"\tldr r1, _080ACE08\n"
	"\tadds r0, r1\n"
	"\tmov r8, r0\n"
	"\tldr r3, _080ACE0C\n"
	"\tcmp r6, 0\n"
	"\tbge _080ACE38\n"
	"\tmovs r2, 0\n"
	"\tldr r5, [r3]\n"
	"\tmovs r0, 0x6\n"
	"\tldrsh r1, [r5, r0]\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r1, r0\n"
	"\tbne _080ACE10\n"
	"\tmovs r6, 0\n"
	"\tb _080ACE38\n"
	"\t.align 2, 0\n"
"_080ACE08: .4byte gGroundEffectTypes\n"
"_080ACE0C: .4byte gGroundEffects\n"
"_080ACE10:\n"
	"\tadds r0, r2, 0x1\n"
	"\tlsls r0, 16\n"
	"\tasrs r2, r0, 16\n"
	"\tmovs r1, 0xE2\n"
	"\tlsls r1, 1\n"
	"\tadds r5, r1\n"
	"\tcmp r2, 0xF\n"
	"\tbgt _080ACE2E\n"
	"\tmovs r4, 0x6\n"
	"\tldrsh r1, [r5, r4]\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r1, r0\n"
	"\tbne _080ACE10\n"
	"\tadds r6, r2, 0\n"
"_080ACE2E:\n"
	"\tcmp r6, 0\n"
	"\tbge _080ACE38\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tb _080AD062\n"
"_080ACE38:\n"
	"\tlsls r0, r6, 3\n"
	"\tsubs r0, r6\n"
	"\tlsls r0, 4\n"
	"\tadds r0, r6\n"
	"\tlsls r0, 2\n"
	"\tldr r1, [r3]\n"
	"\tadds r5, r1, r0\n"
	"\tldr r1, _080ACE9C\n"
	"\tldrb r3, [r7]\n"
	"\tmov r2, r8\n"
	"\tmovs r4, 0\n"
	"\tldrsh r0, [r2, r4]\n"
	"\tstr r0, [sp]\n"
	"\tmov r0, r10\n"
	"\tstr r0, [sp, 0x4]\n"
	"\tmov r2, r9\n"
	"\tstr r2, [sp, 0x8]\n"
	"\tmovs r0, 0\n"
	"\tadds r2, r6, 0\n"
	"\tbl Log\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x6\n"
	"\tldrsh r1, [r5, r3]\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r1, r0\n"
	"\tbne _080ACE72\n"
	"\tmovs r2, 0x1\n"
"_080ACE72:\n"
	"\tstr r2, [sp, 0xC]\n"
	"\tstrh r6, [r5, 0x4]\n"
	"\tldrb r0, [r7]\n"
	"\tstrh r0, [r5, 0x6]\n"
	"\tmov r4, r10\n"
	"\tstrh r4, [r5, 0x8]\n"
	"\tmov r0, r9\n"
	"\tstrb r0, [r5, 0xA]\n"
	"\tmov r1, r8\n"
	"\tldrh r0, [r1]\n"
	"\tsubs r0, 0x1\n"
	"\tlsls r0, 16\n"
	"\tasrs r0, 16\n"
	"\tcmp r0, 0x4\n"
	"\tbhi _080ACEEC\n"
	"\tlsls r0, 2\n"
	"\tldr r1, _080ACEA0\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\t.align 2, 0\n"
"_080ACE9C: .4byte gUnknown_8118674\n"
"_080ACEA0: .4byte _080ACEA4\n"
	"\t.align 2, 0\n"
"_080ACEA4:\n"
	"\t.4byte _080ACEB8\n"
	"\t.4byte _080ACEEC\n"
	"\t.4byte _080ACEC4\n"
	"\t.4byte _080ACED0\n"
	"\t.4byte _080ACEDC\n"
"_080ACEB8:\n"
	"\tmovs r2, 0x8E\n"
	"\tlsls r2, 1\n"
	"\tadds r1, r5, r2\n"
	"\tmovs r0, 0x81\n"
	"\tlsls r0, 22\n"
	"\tb _080ACEF4\n"
"_080ACEC4:\n"
	"\tmovs r4, 0x8E\n"
	"\tlsls r4, 1\n"
	"\tadds r1, r5, r4\n"
	"\tmovs r0, 0x83\n"
	"\tlsls r0, 18\n"
	"\tb _080ACEF4\n"
"_080ACED0:\n"
	"\tmovs r0, 0x8E\n"
	"\tlsls r0, 1\n"
	"\tadds r1, r5, r0\n"
	"\tmovs r0, 0x88\n"
	"\tlsls r0, 22\n"
	"\tb _080ACEF4\n"
"_080ACEDC:\n"
	"\tmovs r2, 0x8E\n"
	"\tlsls r2, 1\n"
	"\tadds r1, r5, r2\n"
	"\tldr r0, _080ACEE8\n"
	"\tb _080ACEF4\n"
	"\t.align 2, 0\n"
"_080ACEE8: .4byte 0x22020000\n"
"_080ACEEC:\n"
	"\tmovs r3, 0x8E\n"
	"\tlsls r3, 1\n"
	"\tadds r1, r5, r3\n"
	"\tldr r0, _080ACF08\n"
"_080ACEF4:\n"
	"\tstr r0, [r1]\n"
	"\tmov r4, r8\n"
	"\tldrb r0, [r4, 0x2]\n"
	"\tcmp r0, 0\n"
	"\tbne _080ACF0C\n"
	"\tldrb r0, [r7, 0x2]\n"
	"\tlsls r0, 11\n"
	"\tstr r0, [r5, 0xC]\n"
	"\tldrb r0, [r7, 0x3]\n"
	"\tb _080ACF16\n"
	"\t.align 2, 0\n"
"_080ACF08: .4byte 0x220c0000\n"
"_080ACF0C:\n"
	"\tmov r1, r8\n"
	"\tldrb r0, [r1, 0x2]\n"
	"\tlsls r0, 11\n"
	"\tstr r0, [r5, 0xC]\n"
	"\tldrb r0, [r1, 0x3]\n"
"_080ACF16:\n"
	"\tlsls r0, 11\n"
	"\tstr r0, [r5, 0x10]\n"
	"\tldr r0, [r5, 0xC]\n"
	"\tlsrs r1, r0, 31\n"
	"\tadds r0, r1\n"
	"\tasrs r0, 1\n"
	"\tstr r0, [r5, 0x14]\n"
	"\tldr r0, [r5, 0x10]\n"
	"\tlsrs r1, r0, 31\n"
	"\tadds r0, r1\n"
	"\tasrs r0, 1\n"
	"\tstr r0, [r5, 0x18]\n"
	"\tldrb r0, [r7, 0x1]\n"
	"\tstrb r0, [r5, 0x1C]\n"
	"\tadds r2, r7, 0x4\n"
	"\tadds r4, r5, 0\n"
	"\tadds r4, 0x20\n"
	"\tldrb r1, [r2, 0x2]\n"
	"\tmovs r0, 0x4\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbne _080ACF5A\n"
	"\tldrb r0, [r7, 0x4]\n"
	"\tlsls r3, r0, 11\n"
	"\tstr r3, [r5, 0x20]\n"
	"\tldrb r1, [r2, 0x2]\n"
	"\tmovs r0, 0x2\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _080ACF5A\n"
	"\tmovs r1, 0x80\n"
	"\tlsls r1, 3\n"
	"\tadds r0, r3, r1\n"
	"\tstr r0, [r5, 0x20]\n"
"_080ACF5A:\n"
	"\tldrb r1, [r2, 0x3]\n"
	"\tmovs r0, 0x4\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbne _080ACF7C\n"
	"\tldrb r0, [r2, 0x1]\n"
	"\tlsls r3, r0, 11\n"
	"\tstr r3, [r4, 0x4]\n"
	"\tldrb r1, [r2, 0x3]\n"
	"\tmovs r0, 0x2\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _080ACF7C\n"
	"\tmovs r2, 0x80\n"
	"\tlsls r2, 3\n"
	"\tadds r0, r3, r2\n"
	"\tstr r0, [r4, 0x4]\n"
"_080ACF7C:\n"
	"\tldr r3, [sp, 0xC]\n"
	"\tcmp r3, 0\n"
	"\tbeq _080ACFD2\n"
	"\tldrb r1, [r5, 0x1C]\n"
	"\tmovs r4, 0x90\n"
	"\tlsls r4, 1\n"
	"\tadds r0, r5, r4\n"
	"\tmovs r3, 0\n"
	"\tstrb r1, [r0]\n"
	"\tmovs r0, 0x92\n"
	"\tlsls r0, 1\n"
	"\tadds r2, r5, r0\n"
	"\tldr r0, [r5, 0x20]\n"
	"\tldr r1, [r5, 0x14]\n"
	"\tsubs r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tmovs r1, 0x96\n"
	"\tlsls r1, 1\n"
	"\tadds r2, r5, r1\n"
	"\tldr r0, [r5, 0x20]\n"
	"\tldr r1, [r5, 0x14]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tadds r4, 0x8\n"
	"\tadds r2, r5, r4\n"
	"\tldr r0, [r5, 0x24]\n"
	"\tldr r1, [r5, 0x18]\n"
	"\tsubs r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tmovs r0, 0x98\n"
	"\tlsls r0, 1\n"
	"\tadds r2, r5, r0\n"
	"\tldr r0, [r5, 0x24]\n"
	"\tldr r1, [r5, 0x18]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tmovs r2, 0x9A\n"
	"\tlsls r2, 1\n"
	"\tadds r1, r5, r2\n"
	"\tadds r4, 0x10\n"
	"\tadds r0, r5, r4\n"
	"\tstr r3, [r0]\n"
	"\tstr r3, [r1]\n"
"_080ACFD2:\n"
	"\tadds r0, r5, 0\n"
	"\tadds r0, 0x28\n"
	"\tadds r1, r5, 0\n"
	"\tadds r1, 0x30\n"
	"\tbl GetCurrentDungeonBounds\n"
	"\tldr r0, [sp, 0xC]\n"
	"\tcmp r0, 0\n"
	"\tbeq _080AD01A\n"
	"\tmovs r2, 0x9F\n"
	"\tlsls r2, 1\n"
	"\tadds r1, r5, r2\n"
	"\tmovs r2, 0\n"
	"\tmovs r0, 0x80\n"
	"\tlsls r0, 4\n"
	"\tstrh r0, [r1]\n"
	"\tmovs r3, 0x9E\n"
	"\tlsls r3, 1\n"
	"\tadds r1, r5, r3\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1]\n"
	"\tmovs r4, 0xA0\n"
	"\tlsls r4, 1\n"
	"\tadds r0, r5, r4\n"
	"\tstrh r2, [r0]\n"
	"\tmovs r1, 0xA2\n"
	"\tlsls r1, 1\n"
	"\tadds r0, r5, r1\n"
	"\tmovs r3, 0x6\n"
	"\tldrsh r2, [r5, r3]\n"
	"\tsubs r4, 0x24\n"
	"\tadds r1, r5, r4\n"
	"\tldr r3, [r1]\n"
	"\tadds r1, r6, 0\n"
	"\tbl sub_80A7688\n"
"_080AD01A:\n"
	"\tadds r4, r5, 0\n"
	"\tadds r4, 0x38\n"
	"\tldr r1, _080AD074\n"
	"\tmov r0, r9\n"
	"\tstr r0, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tadds r2, r5, 0\n"
	"\tmov r3, r10\n"
	"\tbl InitActionWithParams\n"
	"\tldr r2, [r7, 0x8]\n"
	"\tcmp r2, 0\n"
	"\tbne _080AD04C\n"
	"\tmov r1, r8\n"
	"\tmovs r3, 0\n"
	"\tldrsh r0, [r1, r3]\n"
	"\tcmp r0, 0x1\n"
	"\tbne _080AD048\n"
	"\tldr r0, _080AD078\n"
	"\tmovs r1, 0xB0\n"
	"\tlsls r1, 2\n"
	"\tadds r0, r1\n"
	"\tldr r2, [r0]\n"
"_080AD048:\n"
	"\tcmp r2, 0\n"
	"\tbeq _080AD060\n"
"_080AD04C:\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tbl SetPredefinedScript\n"
	"\tldr r3, _080AD07C\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tbl ExecutePredefinedScript\n"
"_080AD060:\n"
	"\tadds r0, r6, 0\n"
"_080AD062:\n"
	"\tadd sp, 0x10\n"
	"\tpop {r3-r5}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tmov r10, r5\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_080AD074: .4byte gGroundEffectCallbacks\n"
"_080AD078: .4byte gFunctionScriptTable\n"
"_080AD07C: .4byte gUnknown_81186CC");
}

void GroundEffect_Delete(s32 _id)
{
    s32 id = (s16)_id;
    GroundEffect *parent = &gGroundEffects[id];

    Log(0, gUnknown_81186D8, id);
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

void sub_80AD10C(s32 index_, s32 flag)
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

bool8 sub_80AD18C(s32 index_, ScriptInfoSmall *scriptInfo, s32 a2_)
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

    Log(0, gUnknown_81186F4, index);

    if(parent->kind != -1)
    {
        GroundScript_ExecutePP(&parent->action, (ActionUnkIds *)a1, script, &gUnknown_811872C);
        parent->directionRelated = 1;
        return 1;
    }
    else {
        return 0;
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

extern s32 sub_80AD3E0(GroundEffect *, PixelPos *);


s16 sub_80AD3B4(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];

    sub_80AD3E0(parent, pos);
    
    return parent->kind;
}

