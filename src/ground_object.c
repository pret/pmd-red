#include "global.h"
#include "globaldata.h"
#include "structs/str_ground_script.h"
#include "debug.h"
#include "data_script.h"
#include "event_flag.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "memory.h"

typedef struct GroundObject {
    // size: 0x1C4
    u8 unk0[4];
    s16 unk4;
    s16 unk6; // kind
    s16 unk8; // scriptID / group
    s8 unkA; // sector
    u8 unkB;
    PixelPos unkC;
    PixelPos unk14;
    s8 unk1C;
    PixelPos unk20;
    PixelPos unk28;
    PixelPos unk30;
    Action unk38;
    u32 flags;
    s8 unk120;
    PixelPos unk124;
    PixelPos unk12C;
    PixelPos unk134;
    u8 unk13C;
    u16 unk13E;
    u16 unk140;
    struct UnkGroundSpriteStruct unk144;
} GroundObject;

IWRAM_INIT GroundObject *gGroundObjects = NULL;

struct GroundObjectTypeData
{
    s16 unk0;
    u8 unk2;
    u8 unk3;
};

extern struct GroundObjectTypeData gGroundObjectTypes[];

void DeleteGroundObjects(void);
void GroundObject_Delete(s32);

const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
void sub_80A7658(struct UnkGroundSpriteStruct *);
extern bool8 GroundScriptNotify(Action*, s32);
extern bool8 GroundScript_Cancel(Action *r0);
void SetPredefinedScript(Action *param_1, s16 index, const ScriptCommand *param_3);

extern bool8 GetCurrentDungeonBounds(PixelPos *a0, PixelPos *a1);
void sub_80A75CC(void *, s32, s32, s32);
bool8 SpriteHasPokemonSize_80A66A4(struct UnkGroundSpriteStruct *ptr);


s32 GroundObject_Add(s32 id_,const GroundObjectData *objectData,s32 group_,s32 sector_);

static s16 CallbackObjectGetIndex(void *ptr);
static void CallbackObjectGetSize(void *objectPtr_, PixelPos *out);
static void CallbackObjectSetHitboxPos(void *objectPtr_, PixelPos *posOrNull);
static void CallbackObjectSetPositionBounds(void *objectPtr_, PixelPos *from, PixelPos *to);
static void CallbackObjectGetHitboxCenter(void *objectPtr_, PixelPos *out);
static s32 CallbackObjectMoveReal(void *objectPtr_, PixelPos *pos);
extern void CallbackObjectGetPosHeightAndUnk(void *objectPtr_, u32 *height, u32 *unk);
extern void CallbackObjectSetPosHeight(void *objectPtr_, u32 height);
extern void CallbackObjectGetDirection(void *objectPtr_, s8 *dir);
extern void CallbackObjectSetDirection(void *objectPtr_, s32 dir_);
extern void CallbackObjectSetEventIndex(void *objectPtr_, u16 a1);
extern void CallbackObjectSetUnk_80AC998(void *objectPtr_, s32 a1_, s32 a2);
extern bool8 CallbackObjectSpriteRelatedCheck_80AC9B8(void *objectPtr_);
extern bool8 CallbackObjectSpriteRelated_80AC9DC(void *objectPtr_);
extern void CallbackObjectGetFlags(void *objectPtr_, u32 *flags);
extern void CallbackObjectSetFlags(void *objectPtr_, u32 flags);
extern void CallbackObjectClearFlags(void *objectPtr_, u32 flags);
extern s32 CallbackObjectMoveRelative(void *objectPtr_, PixelPos *pos);


static const CallbackData gGroundObjectCallbacks = {
    .maybeId = 2,
    .getIndex = CallbackObjectGetIndex,
    .getSize = CallbackObjectGetSize,
    .getHitboxCenter = CallbackObjectGetHitboxCenter,
    .getPosHeightAndUnk = CallbackObjectGetPosHeightAndUnk,
    .getDirection = CallbackObjectGetDirection,
    .getFlags = CallbackObjectGetFlags,
    .setHitboxPos = CallbackObjectSetHitboxPos,
    .setPositionBounds = CallbackObjectSetPositionBounds,
    .moveReal = CallbackObjectMoveReal,
    .setPosHeight = CallbackObjectSetPosHeight,
    .setDirection = CallbackObjectSetDirection,
    .setEventIndex = CallbackObjectSetEventIndex,
    .livesOnlyNullsub = NULL,
    .func38 = CallbackObjectSetUnk_80AC998,
    .setFlags = CallbackObjectSetFlags,
    .clearFlags = CallbackObjectClearFlags,
    .func44_livesOnlySpriteRelated = NULL,
    .moveRelative = CallbackObjectMoveRelative,
    .func4C_spriteRelatedCheck = CallbackObjectSpriteRelatedCheck_80AC9B8,
    .func50_spriteRelated = CallbackObjectSpriteRelated_80AC9DC,
};
const u8 gUnknown_8118334[];
#define FAKE_FILENAME gUnknown_8118334 
 

















































static const struct ScriptCommand gUnknown_81182F4[] = {
    DEBUGINFO, // Needs to be line 159
    LABEL(0),
    WAIT(0x78),
    JUMP_LABEL(0),
};
ALIGNED(4) const u8 gUnknown_8118334[] = "../ground/ground_object.c";
static const struct ScriptCommand gUnknown_8118350[] = {
    DEBUGINFO, // Needs to be line 166
    { 0x54, 0, 1, 0, 0, NULL },
    LABEL(0),
    WAIT(0x78),
    JUMP_LABEL(0),
};

const u8 gUnknown_81183A0[] = {
0xFF, 0xFF,  0x0,  0x8, 0x1,  0x8,  0x0, 0x10, 0x1, 0x10,  0x2, 0x10, 0x3, 0x10,  0x0,  0x8, 0x1,  0x8,  0x2,  0x8, 0x3,  0x8,  0x4,  0x8, 0x5,  0x8,  0x6,  0x8, 0x7,  0x8,  0x8,  0x8, 0x9,  0x8,  0xA,  0x8, 0xB,  0x8,  0xC,  0x8, 0xD,  0x8,  0xE,  0x8, 0xF,  0x8,  0x0,  0x0};

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
    scriptPtr = GetGroundScript(scriptID_s32, DEBUG_LOC_PTR(gUnknown_8118334, 0x126, "GroundObject_Select"));
    Log(0,"GroundObject Select %3d  %3d  %3d", scriptID_s32, group_s32, sector_s32);

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


    Log(0,"GroundObject Cancel %3d", scriptID_s32);

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

    Log(0,"GroundObject CancelBlank");

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

s32 GroundObject_Add(s32 id_,const GroundObjectData *objectData,s32 group_,s32 sector_)
{
      s32 sVar3;
      s32 sVar4;
    
      int index;
      s32 kind;
      GroundObject *parent;
      register s32 id;
      register s32 group;
      register s32 sector;
      bool8 bVar12;
      struct GroundObjectTypeData *typeDataPtr;
      
      id = (s16)id_;
      group = (s16)group_;
      sector = (s8)sector_;

    
        
      kind = objectData->kind;
      if (kind == 0x1a) {
        if (GetScriptVarValue(NULL,BASE_LEVEL) < 2) {
          kind = 0x1b;
        }
        else {
          sVar4 = GetScriptVarValue(NULL,FLAG_KIND);
          if (sVar4 == 0) {
            sVar3 = GetScriptVarValue(NULL,BASE_KIND) + 0x1c;
          }
          else {
            sVar3 = sVar4 + 0x2b;
          }
          kind = (s16)sVar3;
        }
      }
    
      typeDataPtr = &gGroundObjectTypes[kind];
 
      if (id < 0) {
    
          switch(kind)
          {
              case 0xD:
              case 0xE:
                   id = sub_80ABD48(kind);
                    break;
                  
          }
            
        if (id < 0) {
            for(index = 0, parent = gGroundObjects; index < 0x10; index = (s16)(index + 1), parent++)
            {
                if(parent->unk6 == -1)
                {
                  id = index;
                  break;
                }
            }
      
        }
        if (id < 0) {
                return -1;
        }  
      }
      parent = &gGroundObjects[id];
      Log(0,"GroundObject Add id %3d  kind %3d[%3d]  type %3d  group %3d  sector %3d",id,kind,objectData->kind,typeDataPtr->unk0,group,sector);
      bVar12 = (parent->unk6 == -1);
      parent->unk4 = id;
      parent->unk6 = kind;
      parent->unk8 = group;
      parent->unkA = sector;
      switch(typeDataPtr->unk0) {
          case 1:
          case 0xB:
              parent->flags = 0;
            break;
          case 0xA:
             parent->flags = 0x20000;
            break;
          case 0xC:
             parent->flags = 0x40000;
            break;
          case 0xF:
             parent->flags = 0x20C0000;
            break;
          case 0xE:
             parent->flags = 0x220C0000;
            break;
          case 0xD:
             parent->flags = 0x20010000;
            break;
          case 9:
             parent->flags = 5;
            break;
          case 3:
             parent->flags = 0x22000184;
            break;
          case 4:
          case 5:
             parent->flags = 0x184;
            break;
          case 6:
             parent->flags = 0x44;
            break;
          case 7:
             parent->flags = 0x84;
            break;
          case 0x8:
             parent->flags =  0x180;
            break;
          case 0x2:
             parent->flags = 0x20000C4;
            break;
          default:
             parent->flags = 0x2000185;
          break;
      }
      
      if (typeDataPtr->unk2  == '\0') {
          parent->unkC.x = objectData->width << 0xb;
          parent->unkC.y = objectData->height << 0xb;
      }
      else {
          parent->unkC.x = typeDataPtr->unk2 << 0xb;
          parent->unkC.y = typeDataPtr->unk3 << 0xb;
      }
      
      parent->unk14.x = parent->unkC.x / 2;
      parent->unk14.y = parent->unkC.y / 2;
      parent->unk1C = objectData->unk1;
    
      SetUnkInGroundEvent(&objectData->pos, &parent->unk20);
    
      if (bVar12) {
        parent->unk120 = parent->unk1C;
        parent->unk124.x = parent->unk20.x - parent->unk14.x;
        parent->unk12C.x = parent->unk20.x + parent->unk14.x;
        parent->unk124.y = parent->unk20.y - parent->unk14.y;
        parent->unk12C.y = parent->unk20.y + parent->unk14.y;
        parent->unk134.x =  parent->unk134.y = 0;
      }
      GetCurrentDungeonBounds(&parent->unk28,&parent->unk30);
      if (bVar12) {
        parent->unk13E = 0x800;
        parent->unk13C = 1;
        parent->unk140 = 0;
        sub_80A75CC(&(parent->unk144),id,parent->unk6, parent->flags);
      }
    
      InitActionWithParams(&parent->unk38,&gGroundObjectCallbacks,parent,group,sector);
        
       // What an ugly way of coding that...
      SetPredefinedScript(&parent->unk38,1, (objectData->scripts[1] != NULL) ? objectData->scripts[1] 
          : (SpriteHasPokemonSize_80A66A4(&parent->unk144)) ? gUnknown_8118350 : gUnknown_81182F4);
      SetPredefinedScript(&parent->unk38,2,(objectData->scripts[2] != NULL) ? objectData->scripts[2] 
          : gFunctionScriptTable[4].script);
      SetPredefinedScript(&parent->unk38,3,(objectData->scripts[3] != NULL) ? objectData->scripts[3] 
          : gFunctionScriptTable[8].script);
        
      if (objectData->scripts[0] != NULL) {
        SetPredefinedScript(&parent->unk38,0,objectData->scripts[0]);
        ExecutePredefinedScript(&parent->unk38,NULL,0,DEBUG_LOC_PTR(gUnknown_8118334, 0x283, "GroundObject_Add"));
      }
      return id;
}


void sub_80A6688(struct UnkGroundSpriteStruct *, s32);

void GroundObject_Delete(s32 index_) { 
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];    
    
    Log(0, "GroundObject Delete id %3d", index);
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

extern DebugLocation gUnknown_8118504;

bool8 GroundObject_ExecuteScript(s32 index_, void *a1, ScriptInfoSmall *script)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    Log(0, "GroundObject Execute %3d  ", index);

    if(parent->unk6 != -1)
    {
        GroundScript_ExecutePP(&parent->unk38, (ActionUnkIds *)a1, script, DEBUG_LOC_PTR(gUnknown_8118334, 0x303, "GroundObject_ExecuteScript"));
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

static UNUSED s16 sub_80AC408(s32 index_, PixelPos *a1)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];
    if(parent->unk6 == -1)
    {
        a1->x = 0;
        a1->y = 0;
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

extern s32 TryMoveObjectRelative_80AC6AC(GroundObject *, PixelPos *);


s16 sub_80AC49C(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    TryMoveObjectRelative_80AC6AC(parent, pos);
    
    return parent->unk6;
}

s32 sub_80AC4C8(s32 index, PixelPos *a0, PixelPos *a1) {
    GroundObject *parent = &gGroundObjects[0];
    s32 counter;

    for(counter = 0; counter < 0x10; counter = (s16)(counter + 1), parent++)
    {
        if(parent->unk6 != -1)
        {
            if(parent->flags & index)
            {
                if((parent->unk124.x < a1->x) && (parent->unk12C.x > a0->x))
                {
                     if((parent->unk124.y < a1->y) && (parent->unk12C.y > a0->y))
                        return counter;
                }
            }
        }
    }

    return -1;
}


// https://decomp.me/scratch/VEJ5Z (96.09% matched)
NAKED
s32 sub_80AC554(s32 flag, PixelPos *param_2, PixelPos *param_3) {
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r10\n"
	"\tmov r6, r9\n"
	"\tmov r5, r8\n"
	"\tpush {r5-r7}\n"
	"\tmov r8, r0\n"
	"\tmov r10, r1\n"
	"\tadds r4, r2, 0\n"
	"\tldr r0, _080AC5C8\n"
	"\tldr r0, [r0]\n"
	"\tmov r12, r0\n"
	"\tmovs r6, 0\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tmov r9, r0\n"
	"\tmovs r7, 0x80\n"
	"\tlsls r7, 9\n"
"_080AC576:\n"
	"\tmov r1, r12\n"
	"\tmovs r2, 0x6\n"
	"\tldrsh r0, [r1, r2]\n"
	"\tcmp r0, r9\n"
	"\tbeq _080AC5CC\n"
	"\tmovs r0, 0x8E\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tldr r0, [r0]\n"
	"\tmov r5, r8\n"
	"\tands r0, r5\n"
	"\tcmp r0, 0\n"
	"\tbeq _080AC5CC\n"
	"\tmovs r0, 0x92\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tldr r1, [r0]\n"
	"\tmov r5, r12\n"
	"\tldr r0, [r5, 0x14]\n"
	"\tadds r2, r1, r0\n"
	"\tmovs r0, 0x94\n"
	"\tlsls r0, 1\n"
	"\tadd r0, r12\n"
	"\tldr r1, [r0]\n"
	"\tldr r0, [r5, 0x18]\n"
	"\tadds r3, r1, r0\n"
	"\tldr r0, [r4]\n"
	"\tcmp r2, r0\n"
	"\tbge _080AC5CC\n"
	"\tmov r1, r10\n"
	"\tldr r0, [r1]\n"
	"\tcmp r2, r0\n"
	"\tble _080AC5CC\n"
	"\tldr r0, [r4, 0x4]\n"
	"\tcmp r3, r0\n"
	"\tbge _080AC5CC\n"
	"\tldr r0, [r1, 0x4]\n"
	"\tcmp r3, r0\n"
	"\tble _080AC5CC\n"
	"\tadds r0, r6, 0\n"
	"\tb _080AC5E4\n"
	"\t.align 2, 0\n"
"_080AC5C8: .4byte gGroundObjects\n"
"_080AC5CC:\n"
	"\tadds r0, r7, 0\n"
	"\tmovs r2, 0x80\n"
	"\tlsls r2, 9\n"
	"\tadds r7, r2\n"
	"\tasrs r6, r0, 16\n"
	"\tmovs r5, 0xE2\n"
	"\tlsls r5, 1\n"
	"\tadd r12, r5\n"
	"\tcmp r6, 0xF\n"
	"\tble _080AC576\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
"_080AC5E4:\n"
	"\tpop {r3-r5}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tmov r10, r5\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1");
}

bool8 CheckMapCollision_80A585C(PixelPos *, PixelPos *);
s32 GetLivesCollision_80A92A0(s32 id, u32 flags, PixelPos *, PixelPos *);

s32 GetObjectCollision_80AC5F4(GroundObject *param_1, PixelPos *param_2, PixelPos *param_3)
{
    PixelPos local_28 = { param_2->x / 2048 , param_2->y / 2048 };
    PixelPos iVar1 = { (param_3->x - 1) / 2048, (param_3->y - 1) / 2048 };
    PixelPos local_20 = { (iVar1.x - local_28.x) + 1, (iVar1.y - local_28.y) + 1 };

    if (param_1->flags & 1)
    {
        if(CheckMapCollision_80A585C(&local_28,&local_20))
            return 1;
    }
    if (((param_1->flags & 4))) {
        if(((s16)GetLivesCollision_80A92A0(-1,4,param_2,param_3) >= 0))
            return 4;
    }
    return 0;
}

s32 TryMoveObjectRelative_80AC6AC(GroundObject *param_1,PixelPos *param_2)
{
  PixelPos local_1c;
  PixelPos local_14;

  local_1c.x = param_2->x - (param_1->unk14).x;
  local_1c.y = param_2->y - (param_1->unk14).y;
  local_14.x = param_2->x + (param_1->unk14).x;
  local_14.y = param_2->y + (param_1->unk14).y;
  if ((((local_1c.x < param_1->unk28.x) || (local_14.x >= param_1->unk30.x)) ||
      (local_1c.y < param_1->unk28.y)) || (local_14.y >= param_1->unk30.y)) {
    return 1;
  }
  else {
    s32 ret = GetObjectCollision_80AC5F4(param_1,&local_1c,&local_14);
    if (ret == 0) {
      (param_1->unk124) = local_1c;
      param_1->unk12C = local_14; 
      return 0;
    }
    return ret;
  }
}

s32 TryMoveRelative_80AC720(GroundObject *param_1,PixelPos *param_2)
{
  s32 ret;
  bool8 bVar1;
  PixelPos iVar2;
  PixelPos uVar4;
  
  iVar2.x = (param_1->unk124).x + param_2->x;
  iVar2.y = (param_1->unk124).y + param_2->y;
  uVar4.x = param_1->unk12C.x + param_2->x;
  uVar4.y = param_1->unk12C.y + param_2->y;
    
  bVar1 = 0;
    

  if (iVar2.x < param_1->unk28.x) {
    iVar2.x = param_1->unk28.x;
    uVar4.x = param_1->unk28.x + param_1->unkC.x;
    bVar1 = 1;
  }
  else {
    if (uVar4.x >= param_1->unk30.x) {
       iVar2.x = param_1->unk30.x - param_1->unkC.x;
       uVar4.x = param_1->unk30.x;
       bVar1 = 1;
    }
  }

  if (iVar2.y < param_1->unk28.y) {
    iVar2.y = param_1->unk28.y;
    uVar4.y = param_1->unk28.y + param_1->unkC.y;
    bVar1 = 1;
  }
  else {
    if (uVar4.y >= param_1->unk30.y){
        iVar2.y = param_1->unk30.y - param_1->unkC.y;
        uVar4.y = param_1->unk30.y;
        bVar1 = 1;
    }
  }

  ret = GetObjectCollision_80AC5F4(param_1,&iVar2,&uVar4);
  if (ret == 0) {
    (param_1->unk124) = iVar2;
    param_1->unk12C = uVar4;
    if (!bVar1) {
      return 0;
    }
    else {
      return 1;
    }
  }
  return ret;
}

static s16 CallbackObjectGetIndex(void *ptr) 
{
    struct GroundObject *groundObject = ptr;
    return groundObject->unk4;
}

static void CallbackObjectGetSize(void *objectPtr_, PixelPos *out)
{
    struct GroundObject *objectPtr = objectPtr_;
    *out = objectPtr->unkC;
}

static void CallbackObjectSetHitboxPos(void *objectPtr_, PixelPos *posOrNull)
{
    struct GroundObject *objectPtr = objectPtr_;

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
        if (objectPtr->unk120 != objectPtr->unk1C) {
            objectPtr->unk13C = TRUE;
        }
        objectPtr->unk120 = objectPtr->unk1C;
    }
}

static void CallbackObjectSetPositionBounds(void *objectPtr_, PixelPos *from, PixelPos *to)
{
    struct GroundObject *objectPtr = objectPtr_;

    objectPtr->unk28 = *from;
    objectPtr->unk30 = *to;
}

static void CallbackObjectGetHitboxCenter(void *objectPtr_, PixelPos *out)
{
    struct GroundObject *objectPtr = objectPtr_;

    out->x = objectPtr->unk124.x + objectPtr->unk14.x;
    out->y = objectPtr->unk124.y + objectPtr->unk14.y;
}

static s32 CallbackObjectMoveReal(void *objectPtr_, PixelPos *pos)
{
    struct GroundObject *objectPtr = objectPtr_;
    return TryMoveObjectRelative_80AC6AC(objectPtr, pos);
}
