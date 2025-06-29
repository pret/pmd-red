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

extern const s16 gUnknown_81185F2[];
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
//ALIGNED(4) const u8 gUnknown_81185D8[] = "../ground/ground_effect.c";


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

s16 sub_80AD3B4(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundEffect *parent = &gGroundEffects[index];

    sub_80AD3E0(parent, pos);
    
    return parent->kind;
}

NAKED
s32 sub_80AD3E0(GroundEffect *r0, PixelPos *r1)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r12, r0\n"
	"\tldr r3, [r1]\n"
	"\tldr r2, [r0, 0x14]\n"
	"\tsubs r6, r3, r2\n"
	"\tldr r1, [r1, 0x4]\n"
	"\tldr r0, [r0, 0x18]\n"
	"\tsubs r7, r1, r0\n"
	"\tadds r4, r3, r2\n"
	"\tadds r5, r1, r0\n"
	"\tmov r1, r12\n"
	"\tldr r0, [r1, 0x28]\n"
	"\tcmp r6, r0\n"
	"\tblt _080AD40E\n"
	"\tldr r0, [r1, 0x30]\n"
	"\tcmp r4, r0\n"
	"\tbge _080AD40E\n"
	"\tldr r0, [r1, 0x2C]\n"
	"\tcmp r7, r0\n"
	"\tblt _080AD40E\n"
	"\tldr r0, [r1, 0x34]\n"
	"\tcmp r5, r0\n"
	"\tblt _080AD412\n"
"_080AD40E:\n"
	"\tmovs r0, 0x1\n"
	"\tb _080AD428\n"
"_080AD412:\n"
	"\tmovs r0, 0x92\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tstr r6, [r0]\n"
	"\tstr r7, [r0, 0x4]\n"
	"\tmovs r0, 0x96\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tstr r4, [r0]\n"
	"\tstr r5, [r0, 0x4]\n"
	"\tmovs r0, 0\n"
"_080AD428:\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1");
}

NAKED
s32 sub_80AD430(GroundEffect *r0, PixelPos *r1)
{
    asm_unified(
	"\tpush {r4-r6,lr}\n"
	"\tmov r12, r0\n"
	"\tmovs r0, 0x92\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tldr r0, [r0]\n"
	"\tldr r2, [r1]\n"
	"\tadds r5, r0, r2\n"
	"\tmovs r0, 0x94\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tldr r0, [r0]\n"
	"\tldr r1, [r1, 0x4]\n"
	"\tadds r6, r0, r1\n"
	"\tmovs r0, 0x96\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tldr r0, [r0]\n"
	"\tadds r3, r0, r2\n"
	"\tmovs r0, 0x98\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tldr r0, [r0]\n"
	"\tadds r4, r0, r1\n"
	"\tmov r0, r12\n"
	"\tldr r1, [r0, 0x28]\n"
	"\tcmp r5, r1\n"
	"\tbge _080AD470\n"
	"\tadds r5, r1, 0\n"
	"\tldr r0, [r0, 0xC]\n"
	"\tadds r3, r1, r0\n"
	"\tb _080AD47E\n"
"_080AD470:\n"
	"\tmov r2, r12\n"
	"\tldr r1, [r2, 0x30]\n"
	"\tcmp r3, r1\n"
	"\tblt _080AD47E\n"
	"\tldr r0, [r2, 0xC]\n"
	"\tsubs r5, r1, r0\n"
	"\tadds r3, r1, 0\n"
"_080AD47E:\n"
	"\tmov r0, r12\n"
	"\tldr r1, [r0, 0x2C]\n"
	"\tcmp r6, r1\n"
	"\tbge _080AD48E\n"
	"\tadds r6, r1, 0\n"
	"\tldr r0, [r0, 0x10]\n"
	"\tadds r4, r1, r0\n"
	"\tb _080AD49C\n"
"_080AD48E:\n"
	"\tmov r2, r12\n"
	"\tldr r1, [r2, 0x34]\n"
	"\tcmp r4, r1\n"
	"\tblt _080AD49C\n"
	"\tldr r0, [r2, 0x10]\n"
	"\tsubs r6, r1, r0\n"
	"\tadds r4, r1, 0\n"
"_080AD49C:\n"
	"\tmovs r0, 0x92\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tstr r5, [r0]\n"
	"\tstr r6, [r0, 0x4]\n"
	"\tmovs r0, 0x96\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tstr r3, [r0]\n"
	"\tstr r4, [r0, 0x4]\n"
	"\tmovs r0, 0\n"
	"\tpop {r4-r6}\n"
	"\tpop {r1}\n"
	"\tbx r1");

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
        livesPtr->directionRelated = 1;
    }
    else if((livesPtr->unk13E & 0x1000))
        livesPtr->directionRelated = 1;
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

extern DebugLocation gUnknown_811874C;
extern DebugLocation gUnknown_8118758;
extern s16 HandleAction(Action *action, DebugLocation *debug);

void GroundEffect_Action(void)
{
    GroundEffect *objectPtr;
    s32 i;
    s32 ret;

    for (objectPtr = &gGroundEffects[0], i = 0; i < NUM_GROUND_EFFECTS; i = (s16)(i + 1), objectPtr++)
    {
        if (objectPtr->kind != -1) {
            ret = HandleAction(&objectPtr->action, &gUnknown_811874C);
            switch(ret)
            {
                case 4:
                    GroundEffect_Delete(i);
                    continue;
                case 0:
                    ExecutePredefinedScript(&objectPtr->action, NULL, 1, &gUnknown_8118758);
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
                objectPtr->directionRelated = 0;
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
