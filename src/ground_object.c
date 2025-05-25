#include "gba/types.h"
#include "global.h"
#include "structs/str_ground_script.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "memory.h"

// TODO: figure out if this is used anywhere else
struct GroundObjectSub {
    s32 a0[2];
};

typedef struct GroundObject {
    // size: 0x1C4
    u8 unk0[4];
    s16 unk4;
    s16 unk6; // kind
    s16 unk8; // scriptID / group
    s8 unkA; // sector
    u8 unkB;
    struct GroundObjectSub unkC;
    PixelPos unk14;
    //s32 unk18;
    u8 unk1C;
    PixelPos unk20;
    s32 unk28[2];
    s32 unk30[2];
    Action unk38;
    u32 flags;
    u8 unk120;
    PixelPos unk124;
    u32 unk12C;
    u32 unk130;
    PixelPos unk134;
    //u32 unk138;
    u8 unk13C;
    u16 unk13E;
    u16 unk140;
    struct UnkGroundSpriteStruct unk144;
} GroundObject;

IWRAM_INIT GroundObject *gGroundObjects = NULL;

void DeleteGroundObjects(void);
void GroundObject_Delete(s32);

extern DebugLocation gUnknown_81183E4;
extern u8 gUnknown_81183F0[];
extern u8 gUnknown_8118414[];
extern u8 gUnknown_811842C[];
extern u8 gUnknown_81184B0[];

const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
void sub_80A7658(struct UnkGroundSpriteStruct *);
extern bool8 GroundScriptNotify(Action*, s32);
extern bool8 GroundScript_Cancel(Action *r0);


s16 GroundObject_Add(s32 id, const GroundObjectData*, s32 group, s32 sector);

void AllocGroundObjects(void) 
{

    GroundObject *ptr;
    s32 index;

    gGroundObjects = MemoryAlloc(sizeof(GroundObject) * 0x10, 6);
   
    for(index = 0,  ptr = &gGroundObjects[index]; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        ptr->unk6 |= -1;
    }
    DeleteGroundObjects();
}

void DeleteGroundObjects(void)
{
    GroundObject *ptr;
    s32 index;
    
    ptr = &gGroundObjects[0];
    for(index = 0; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if(ptr->unk6 != -1)
            GroundObject_Delete(index);
    }
}

void FreeGroundObjects(void)
{
    DeleteGroundObjects();
    MemoryFree(gGroundObjects);
    gGroundObjects = NULL;
}

void GroundObject_Select(s32 scriptID, s32 group, s32 sector)
{
    const struct GroundScriptHeader *scriptPtr;
    const struct GroundScriptSector *sectorPtr;
    const struct GroundScriptGroup *groupPtr;

    s32 i;
    s32 size;
    const GroundObjectData *objectData;
    s32 sector_s32;
    s32 group_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    group_s32 = (s16)group;
    sector_s32 = (s8)sector;
    scriptPtr = GetGroundScript(scriptID_s32, &gUnknown_81183E4);
    Log('\0',gUnknown_81183F0, scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    objectData = sectorPtr->objects;

    size = sectorPtr->nObjects;
    for (i = 0; i < size; i++, objectData++)
    {
        GroundObject_Add(-1,objectData,group_s32,sector_s32);
    }
}

void GroundObject_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    GroundObject *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log('\0',gUnknown_8118414, scriptID_s32);

    index = 0;
    ptr = &gGroundObjects[0];
    for(; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk6 != -1) && (ptr->unk8 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unkA == sector_s32)
                GroundObject_Delete(index);
    }
}

void GroundObject_CancelBlank(void)
{
    s32 index;
    GroundObject *ptr;
    PixelPos stack;

    Log('\0',gUnknown_811842C);

    index = 0;
    ptr = &gGroundObjects[0];
    for(; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if(ptr->unk6 != -1)
        {
            stack.x = ptr->unk124.x + ptr->unk14.x;
            stack.y = ptr->unk124.y + ptr->unk14.y;
            if(!IsOnscreen_80A675C(&ptr->unk144, &stack))
                GroundObject_Delete(index);
        }
    }
}

s32 sub_80ABD48(s32 r0)
{
    s32 index;
    GroundObject *ptr;

    s32 r0_s32 = (s16)r0;

    index = 0;
    ptr = &gGroundObjects[0];
    for(; index < 0x10; index = (s16)(index + 1), ptr++)
    {
        if(ptr->unk6 == r0_s32) return index;
    }

    return -1;
}

NAKED
s16 GroundObject_Add(s32 id, const GroundObjectData *objectData, s32 group, s32 sector)
{
    asm_unified(
"	push {r4-r7,lr}               \n"
"	mov r7, r10                   \n"
"	mov r6, r9                    \n"
"	mov r5, r8                    \n"
"	push {r5-r7}                  \n"
"	sub sp, 0x14                  \n"
"	mov r8, r1                    \n"
"	lsls r0, 16                   \n"
"	asrs r7, r0, 16               \n"
"	lsls r2, 16                   \n"
"	asrs r2, 16                   \n"
"	mov r10, r2                   \n"
"	lsls r3, 24                   \n"
"	asrs r3, 24                   \n"
"	mov r9, r3                    \n"
"	ldrb r4, [r1]                 \n"
"	cmp r4, 0x1A                  \n"
"	bne _080ABDDA                 \n"
"	movs r0, 0                    \n"
"	movs r1, 0x28                 \n"
"	bl GetScriptVarValue          \n"
"	cmp r0, 0x1                   \n"
"	bgt _080ABDBC                 \n"
"	movs r4, 0x1B                 \n"
"	b _080ABDDA                   \n"
"_080ABDBC:                        \n"
"	movs r0, 0                    \n"
"	movs r1, 0x29                 \n"
"	bl GetScriptVarValue          \n"
"	cmp r0, 0                     \n"
"	bne _080ABDD4                 \n"
"	movs r0, 0                    \n"
"	movs r1, 0x27                 \n"
"	bl GetScriptVarValue          \n"
"	adds r0, 0x1C                 \n"
"	b _080ABDD6                   \n"
"_080ABDD4:                        \n"
"	adds r0, 0x2B                 \n"
"_080ABDD6:                        \n"
"	lsls r0, 16                   \n"
"	asrs r4, r0, 16               \n"
"_080ABDDA:                        \n"
"	lsls r1, r4, 2                \n"
"	ldr r0, _080ABE10             \n"
"	adds r6, r1, r0               \n"
"	cmp r7, 0                     \n"
"	bge _080ABE40                 \n"
"	cmp r4, 0xE                   \n"
"	bgt _080ABDF4                 \n"
"	cmp r4, 0xD                   \n"
"	blt _080ABDF4                 \n"
"	adds r0, r4, 0                \n"
"	bl sub_80ABD48                \n"
"	adds r7, r0, 0                \n"
"_080ABDF4:                        \n"
"	cmp r7, 0                     \n"
"	bge _080ABE40                 \n"
"	movs r3, 0                    \n"
"	ldr r0, _080ABE14             \n"
"	ldr r5, [r0]                  \n"
"	movs r0, 0x6                  \n"
"	ldrsh r1, [r5, r0]            \n"
"	movs r0, 0x1                  \n"
"	negs r0, r0                   \n"
"	cmp r1, r0                    \n"
"	bne _080ABE18                 \n"
"	movs r7, 0                    \n"
"	b _080ABE40                   \n"
"	.align 2, 0                   \n"
"_080ABE10: .4byte gGroundObjectTypes\n"
"_080ABE14: .4byte gGroundObjects  \n"
"_080ABE18:                        \n"
"	adds r0, r3, 0x1              \n"
"	lsls r0, 16                   \n"
"	asrs r3, r0, 16               \n"
"	movs r1, 0xE2                 \n"
"	lsls r1, 1                    \n"
"	adds r5, r1                   \n"
"	cmp r3, 0xF                   \n"
"	bgt _080ABE36                 \n"
"	movs r2, 0x6                  \n"
"	ldrsh r1, [r5, r2]            \n"
"	movs r0, 0x1                  \n"
"	negs r0, r0                   \n"
"	cmp r1, r0                    \n"
"	bne _080ABE18                 \n"
"	adds r7, r3, 0                \n"
"_080ABE36:                        \n"
"	cmp r7, 0                     \n"
"	bge _080ABE40                 \n"
"	movs r0, 0x1                  \n"
"	negs r0, r0                   \n"
"	b _080AC142                   \n"
"_080ABE40:                        \n"
"	ldr r1, _080ABEA8             \n"
"	lsls r0, r7, 3                \n"
"	subs r0, r7                   \n"
"	lsls r0, 4                    \n"
"	adds r0, r7                   \n"
"	lsls r0, 2                    \n"
"	ldr r1, [r1]                  \n"
"	adds r5, r1, r0               \n"
"	ldr r1, _080ABEAC             \n"
"	mov r3, r8                    \n"
"	ldrb r0, [r3]                 \n"
"	str r0, [sp]                  \n"
"	movs r2, 0                    \n"
"	ldrsh r0, [r6, r2]            \n"
"	str r0, [sp, 0x4]             \n"
"	mov r3, r10                   \n"
"	str r3, [sp, 0x8]             \n"
"	mov r0, r9                    \n"
"	str r0, [sp, 0xC]             \n"
"	movs r0, 0                    \n"
"	adds r2, r7, 0                \n"
"	adds r3, r4, 0                \n"
"	bl Log                        \n"
"	movs r2, 0                    \n"
"	movs r3, 0x6                  \n"
"	ldrsh r1, [r5, r3]            \n"
"	movs r0, 0x1                  \n"
"	negs r0, r0                   \n"
"	cmp r1, r0                    \n"
"	bne _080ABE80                 \n"
"	movs r2, 0x1                  \n"
"_080ABE80:                        \n"
"	str r2, [sp, 0x10]            \n"
"	strh r7, [r5, 0x4]            \n"
"	strh r4, [r5, 0x6]            \n"
"	mov r0, r10                   \n"
"	strh r0, [r5, 0x8]            \n"
"	mov r1, r9                    \n"
"	strb r1, [r5, 0xA]            \n"
"	ldrh r0, [r6]                 \n"
"	subs r0, 0x1                  \n"
"	lsls r0, 16                   \n"
"	asrs r0, 16                   \n"
"	cmp r0, 0xE                   \n"
"	bls _080ABE9C                 \n"
"	b _080ABF8C                   \n"
"_080ABE9C:                        \n"
"	lsls r0, 2                    \n"
"	ldr r1, _080ABEB0             \n"
"	adds r0, r1                   \n"
"	ldr r0, [r0]                  \n"
"	mov pc, r0                    \n"
"	.align 2, 0                   \n"
"_080ABEA8: .4byte gGroundObjects  \n"
"_080ABEAC: .4byte gUnknown_8118448\n"
"_080ABEB0: .4byte _080ABEB4       \n"
"	.align 2, 0                   \n"
"_080ABEB4:                        \n"
"	.4byte _080ABEF0              \n"
"	.4byte _080ABF7C              \n"
"	.4byte _080ABF46              \n"
"	.4byte _080ABF54              \n"
"	.4byte _080ABF54              \n"
"	.4byte _080ABF5E              \n"
"	.4byte _080ABF68              \n"
"	.4byte _080ABF72              \n"
"	.4byte _080ABF3C              \n"
"	.4byte _080ABEFA              \n"
"	.4byte _080ABEF0              \n"
"	.4byte _080ABF06              \n"
"	.4byte _080ABF2C              \n"
"	.4byte _080ABF1E              \n"
"	.4byte _080ABF12              \n"
"_080ABEF0:                        \n"
"	movs r2, 0x8E                 \n"
"	lsls r2, 1                    \n"
"	adds r1, r5, r2               \n"
"	movs r0, 0                    \n"
"	b _080ABF94                   \n"
"_080ABEFA:                        \n"
"	movs r3, 0x8E                 \n"
"	lsls r3, 1                    \n"
"	adds r1, r5, r3               \n"
"	movs r0, 0x80                 \n"
"	lsls r0, 10                   \n"
"	b _080ABF94                   \n"
"_080ABF06:                        \n"
"	movs r0, 0x8E                 \n"
"	lsls r0, 1                    \n"
"	adds r1, r5, r0               \n"
"	movs r0, 0x80                 \n"
"	lsls r0, 11                   \n"
"	b _080ABF94                   \n"
"_080ABF12:                        \n"
"	movs r2, 0x8E                 \n"
"	lsls r2, 1                    \n"
"	adds r1, r5, r2               \n"
"	movs r0, 0x83                 \n"
"	lsls r0, 18                   \n"
"	b _080ABF94                   \n"
"_080ABF1E:                        \n"
"	movs r3, 0x8E                 \n"
"	lsls r3, 1                    \n"
"	adds r1, r5, r3               \n"
"	ldr r0, _080ABF28             \n"
"	b _080ABF94                   \n"
"	.align 2, 0                   \n"
"_080ABF28: .4byte 0x220c0000      \n"
"_080ABF2C:                        \n"
"	movs r0, 0x8E                 \n"
"	lsls r0, 1                    \n"
"	adds r1, r5, r0               \n"
"	ldr r0, _080ABF38             \n"
"	b _080ABF94                   \n"
"	.align 2, 0                   \n"
"_080ABF38: .4byte 0x20010000      \n"
"_080ABF3C:                        \n"
"	movs r2, 0x8E                 \n"
"	lsls r2, 1                    \n"
"	adds r1, r5, r2               \n"
"	movs r0, 0x5                  \n"
"	b _080ABF94                   \n"
"_080ABF46:                        \n"
"	movs r3, 0x8E                 \n"
"	lsls r3, 1                    \n"
"	adds r1, r5, r3               \n"
"	ldr r0, _080ABF50             \n"
"	b _080ABF94                   \n"
"	.align 2, 0                   \n"
"_080ABF50: .4byte 0x22000184      \n"
"_080ABF54:                        \n"
"	movs r0, 0x8E                 \n"
"	lsls r0, 1                    \n"
"	adds r1, r5, r0               \n"
"	adds r0, 0x68                 \n"
"	b _080ABF94                   \n"
"_080ABF5E:                        \n"
"	movs r2, 0x8E                 \n"
"	lsls r2, 1                    \n"
"	adds r1, r5, r2               \n"
"	movs r0, 0x44                 \n"
"	b _080ABF94                   \n"
"_080ABF68:                        \n"
"	movs r3, 0x8E                 \n"
"	lsls r3, 1                    \n"
"	adds r1, r5, r3               \n"
"	movs r0, 0x84                 \n"
"	b _080ABF94                   \n"
"_080ABF72:                        \n"
"	movs r0, 0x8E                 \n"
"	lsls r0, 1                    \n"
"	adds r1, r5, r0               \n"
"	adds r0, 0x64                 \n"
"	b _080ABF94                   \n"
"_080ABF7C:                        \n"
"	movs r2, 0x8E                 \n"
"	lsls r2, 1                    \n"
"	adds r1, r5, r2               \n"
"	ldr r0, _080ABF88             \n"
"	b _080ABF94                   \n"
"	.align 2, 0                   \n"
"_080ABF88: .4byte 0x020000c4      \n"
"_080ABF8C:                        \n"
"	movs r3, 0x8E                 \n"
"	lsls r3, 1                    \n"
"	adds r1, r5, r3               \n"
"	ldr r0, _080ABFA8             \n"
"_080ABF94:                        \n"
"	str r0, [r1]                  \n"
"	ldrb r0, [r6, 0x2]            \n"
"	cmp r0, 0                     \n"
"	bne _080ABFAC                 \n"
"	mov r1, r8                    \n"
"	ldrb r0, [r1, 0x2]            \n"
"	lsls r0, 11                   \n"
"	str r0, [r5, 0xC]             \n"
"	ldrb r0, [r1, 0x3]            \n"
"	b _080ABFB4                   \n"
"	.align 2, 0                   \n"
"_080ABFA8: .4byte 0x02000185      \n"
"_080ABFAC:                        \n"
"	ldrb r0, [r6, 0x2]            \n"
"	lsls r0, 11                   \n"
"	str r0, [r5, 0xC]             \n"
"	ldrb r0, [r6, 0x3]            \n"
"_080ABFB4:                        \n"
"	lsls r0, 11                   \n"
"	str r0, [r5, 0x10]            \n"
"	ldr r0, [r5, 0xC]             \n"
"	lsrs r1, r0, 31               \n"
"	adds r0, r1                   \n"
"	asrs r0, 1                    \n"
"	str r0, [r5, 0x14]            \n"
"	ldr r0, [r5, 0x10]            \n"
"	lsrs r1, r0, 31               \n"
"	adds r0, r1                   \n"
"	asrs r0, 1                    \n"
"	str r0, [r5, 0x18]            \n"
"	mov r2, r8                    \n"
"	ldrb r0, [r2, 0x1]            \n"
"	strb r0, [r5, 0x1C]           \n"
"	adds r2, 0x4                  \n"
"	adds r4, r5, 0                \n"
"	adds r4, 0x20                 \n"
"	ldrb r1, [r2, 0x2]            \n"
"	movs r0, 0x4                  \n"
"	ands r0, r1                   \n"
"	cmp r0, 0                     \n"
"	bne _080ABFFC                 \n"
"	mov r3, r8                    \n"
"	ldrb r0, [r3, 0x4]            \n"
"	lsls r3, r0, 11               \n"
"	str r3, [r5, 0x20]            \n"
"	ldrb r1, [r2, 0x2]            \n"
"	movs r0, 0x2                  \n"
"	ands r0, r1                   \n"
"	cmp r0, 0                     \n"
"	beq _080ABFFC                 \n"
"	movs r1, 0x80                 \n"
"	lsls r1, 3                    \n"
"	adds r0, r3, r1               \n"
"	str r0, [r5, 0x20]            \n"
"_080ABFFC:                        \n"
"	ldrb r1, [r2, 0x3]            \n"
"	movs r0, 0x4                  \n"
"	ands r0, r1                   \n"
"	cmp r0, 0                     \n"
"	bne _080AC01E                 \n"
"	ldrb r0, [r2, 0x1]            \n"
"	lsls r3, r0, 11               \n"
"	str r3, [r4, 0x4]             \n"
"	ldrb r1, [r2, 0x3]            \n"
"	movs r0, 0x2                  \n"
"	ands r0, r1                   \n"
"	cmp r0, 0                     \n"
"	beq _080AC01E                 \n"
"	movs r2, 0x80                 \n"
"	lsls r2, 3                    \n"
"	adds r0, r3, r2               \n"
"	str r0, [r4, 0x4]             \n"
"_080AC01E:                        \n"
"	ldr r3, [sp, 0x10]            \n"
"	cmp r3, 0                     \n"
"	beq _080AC076                 \n"
"	ldrb r1, [r5, 0x1C]           \n"
"	movs r2, 0x90                 \n"
"	lsls r2, 1                    \n"
"	adds r0, r5, r2               \n"
"	movs r3, 0                    \n"
"	strb r1, [r0]                 \n"
"	movs r0, 0x92                 \n"
"	lsls r0, 1                    \n"
"	adds r2, r5, r0               \n"
"	ldr r0, [r5, 0x20]            \n"
"	ldr r1, [r5, 0x14]            \n"
"	subs r0, r1                   \n"
"	str r0, [r2]                  \n"
"	movs r1, 0x96                 \n"
"	lsls r1, 1                    \n"
"	adds r2, r5, r1               \n"
"	ldr r0, [r5, 0x20]            \n"
"	ldr r1, [r5, 0x14]            \n"
"	adds r0, r1                   \n"
"	str r0, [r2]                  \n"
"	movs r0, 0x94                 \n"
"	lsls r0, 1                    \n"
"	adds r2, r5, r0               \n"
"	ldr r0, [r5, 0x24]            \n"
"	ldr r1, [r5, 0x18]            \n"
"	subs r0, r1                   \n"
"	str r0, [r2]                  \n"
"	movs r1, 0x98                 \n"
"	lsls r1, 1                    \n"
"	adds r2, r5, r1               \n"
"	ldr r0, [r5, 0x24]            \n"
"	ldr r1, [r5, 0x18]            \n"
"	adds r0, r1                   \n"
"	str r0, [r2]                  \n"
"	movs r2, 0x9A                 \n"
"	lsls r2, 1                    \n"
"	adds r1, r5, r2               \n"
"	adds r2, 0x4                  \n"
"	adds r0, r5, r2               \n"
"	str r3, [r0]                  \n"
"	str r3, [r1]                  \n"
"_080AC076:                        \n"
"	adds r0, r5, 0                \n"
"	adds r0, 0x28                 \n"
"	adds r1, r5, 0                \n"
"	adds r1, 0x30                 \n"
"	bl GetCurrentDungeonBounds    \n"
"	ldr r3, [sp, 0x10]            \n"
"	cmp r3, 0                     \n"
"	beq _080AC0C0                 \n"
"	movs r0, 0x9F                 \n"
"	lsls r0, 1                    \n"
"	adds r1, r5, r0               \n"
"	movs r2, 0                    \n"
"	movs r0, 0x80                 \n"
"	lsls r0, 4                    \n"
"	strh r0, [r1]                 \n"
"	movs r3, 0x9E                 \n"
"	lsls r3, 1                    \n"
"	adds r1, r5, r3               \n"
"	movs r0, 0x1                  \n"
"	strb r0, [r1]                 \n"
"	movs r1, 0xA0                 \n"
"	lsls r1, 1                    \n"
"	adds r0, r5, r1               \n"
"	strh r2, [r0]                 \n"
"	movs r2, 0xA2                 \n"
"	lsls r2, 1                    \n"
"	adds r0, r5, r2               \n"
"	movs r3, 0x6                  \n"
"	ldrsh r2, [r5, r3]            \n"
"	movs r3, 0x8E                 \n"
"	lsls r3, 1                    \n"
"	adds r1, r5, r3               \n"
"	ldr r3, [r1]                  \n"
"	adds r1, r7, 0                \n"
"	bl sub_80A75CC                \n"
"_080AC0C0:                        \n"
"	adds r4, r5, 0                \n"
"	adds r4, 0x38                 \n"
"	ldr r1, _080AC154             \n"
"	mov r0, r9                    \n"
"	str r0, [sp]                  \n"
"	adds r0, r4, 0                \n"
"	adds r2, r5, 0                \n"
"	mov r3, r10                   \n"
"	bl InitActionWithParams       \n"
"	adds r6, r4, 0                \n"
"	mov r1, r8                    \n"
"	ldr r2, [r1, 0xC]             \n"
"	cmp r2, 0                     \n"
"	bne _080AC0F2                 \n"
"	movs r2, 0xA2                 \n"
"	lsls r2, 1                    \n"
"	adds r0, r5, r2               \n"
"	bl SpriteHasPokemonSize_80A66A4\n"
"	lsls r0, 24                   \n"
"	ldr r2, _080AC158             \n"
"	cmp r0, 0                     \n"
"	beq _080AC0F2                 \n"
"	ldr r2, _080AC15C             \n"
"_080AC0F2:                        \n"
"	adds r0, r6, 0                \n"
"	movs r1, 0x1                  \n"
"	bl SetPredefinedScript        \n"
"	adds r1, r4, 0                \n"
"	mov r3, r8                    \n"
"	ldr r2, [r3, 0x10]            \n"
"	cmp r2, 0                     \n"
"	bne _080AC108                 \n"
"	ldr r0, _080AC160             \n"
"	ldr r2, [r0, 0x38]            \n"
"_080AC108:                        \n"
"	adds r0, r1, 0                \n"
"	movs r1, 0x2                  \n"
"	bl SetPredefinedScript        \n"
"	mov r0, r8                    \n"
"	ldr r2, [r0, 0x14]            \n"
"	cmp r2, 0                     \n"
"	bne _080AC11C                 \n"
"	ldr r0, _080AC160             \n"
"	ldr r2, [r0, 0x68]            \n"
"_080AC11C:                        \n"
"	adds r0, r4, 0                \n"
"	movs r1, 0x3                  \n"
"	bl SetPredefinedScript        \n"
"	mov r1, r8                    \n"
"	ldr r2, [r1, 0x8]             \n"
"	cmp r2, 0                     \n"
"	beq _080AC140                 \n"
"	adds r0, r4, 0                \n"
"	movs r1, 0                    \n"
"	bl SetPredefinedScript        \n"
"	ldr r3, _080AC164             \n"
"	adds r0, r4, 0                \n"
"	movs r1, 0                    \n"
"	movs r2, 0                    \n"
"	bl ExecutePredefinedScript    \n"
"_080AC140:                        \n"
"	adds r0, r7, 0                \n"
"_080AC142:                        \n"
"	add sp, 0x14                  \n"
"	pop {r3-r5}                   \n"
"	mov r8, r3                    \n"
"	mov r9, r4                    \n"
"	mov r10, r5                   \n"
"	pop {r4-r7}                   \n"
"	pop {r1}                      \n"
"	bx r1                         \n"
"	.align 2, 0                   \n"
"_080AC154: .4byte gGroundObjectCallbacks\n"
"_080AC158: .4byte gUnknown_81182F4\n"
"_080AC15C: .4byte gUnknown_8118350\n"
"_080AC160: .4byte gFunctionScriptTable\n"
"_080AC164: .4byte gUnknown_81184A4");
}

void sub_80A6688(struct UnkGroundSpriteStruct *, s32);

void GroundObject_Delete(s32 index_) { 
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];    
    
    Log(0, gUnknown_81184B0, index);
    sub_80A7658(&parent->unk144);
    InitAction2(&parent->unk38);
    parent->unk6 = -1;
}

void sub_80AC1B0(s32 index_, s32 flag)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->unk6 != -1)
    {
        parent->flags |= flag;
        sub_80A6688(&parent->unk144, parent->flags);
    }
}

void sub_80AC1F4(s32 index_, s32 flag)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->unk6 != -1)
    {
        parent->flags &= (0x337fffff ^ flag);
        sub_80A6688(&parent->unk144, parent->flags);
    }
}

Action *sub_80AC240(s32 index_)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->unk6 != -1)
        return &parent->unk38;
    else
        return NULL;
}

extern bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s32 _index);


bool8 sub_80AC274(s32 index_, ScriptInfoSmall *scriptInfo, s32 a2_)
{
    s32 index = (s16)index_;
    s32 a2 = (s16)a2_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->unk6 != -1)
        return GetPredefinedScript(&parent->unk38, scriptInfo, a2);
    else
        return FALSE;
}

extern u8 gUnknown_81184CC[];
extern DebugLocation gUnknown_8118504;

bool8 GroundObject_ExecuteScript(s32 index_, void *a1, ScriptInfoSmall *script)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    Log(0, gUnknown_81184CC, index);

    if(parent->unk6 != -1)
    {
        GroundScript_ExecutePP(&parent->unk38, (ActionUnkIds *)a1, script, &gUnknown_8118504);
        parent->unk13C = 1;
        return 1;
    }
    else {
        return 0;
    }
}

bool8 GroundObjectsNotifyAll(s32 index_)
{
    s32 index = (s16)index_;
    s32 counter;
    GroundObject *parent = &gGroundObjects[0];
    bool8 flag = FALSE;
    
    for(counter = 0; counter < 0x10; counter = (s16)(counter + 1), parent++)
    {
        if(parent->unk6 != -1)
            flag |= GroundScriptNotify(&parent->unk38, index);
    }

    return flag;
}

bool8 GroundObjectsCancelAll(void)
{
    s32 counter;
    GroundObject *parent = &gGroundObjects[0];
    bool8 flag = FALSE;
    
    for(counter = 0; counter < 0x10; counter = (s16)(counter + 1), parent++)
    {
        if(parent->unk6 != -1)
            flag |= GroundScript_Cancel(&parent->unk38);
    }

    return flag;
}

static UNUSED s16 sub_80AC3C0(s32 index_)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];
    return parent->unk6;
}

s16 sub_80AC3E0(s32 index_, s32 *a1)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];
    *a1 = parent->flags;
    return parent->unk6;
}

static UNUSED s16 sub_80AC408(s32 index_, struct GroundObjectSub *a1)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];
    if(parent->unk6 == -1)
    {
        a1->a0[0] = 0;
        a1->a0[1] = 0;
    }
    else
    {
        *a1 = parent->unkC;
    }
    return parent->unk6;
}

s16 sub_80AC448(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->unk6 == -1)
    {
        pos->x = 0;
        pos->y = 0;
    }
    else {
       pos->x = parent->unk124.x + parent->unk14.x; 
       pos->y = parent->unk124.y + parent->unk14.y; 
    }

    return parent->unk6;
}

extern void TryMoveObjectRelative_80AC6AC(void *, PixelPos *);


s16 sub_80AC49C(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    TryMoveObjectRelative_80AC6AC(parent, pos);
    
    return parent->unk6;
}
