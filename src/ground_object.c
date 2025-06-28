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
} GroundObject;

IWRAM_INIT GroundObject *gGroundObjects = NULL;
#define NUM_GROUND_OBJECTS 0x10

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
static void CallbackObjectGetPosHeightAndUnk(void *objectPtr_, u32 *height, u32 *unk);
static void CallbackObjectSetPosHeight(void *objectPtr_, u32 height);
static void CallbackObjectGetDirection(void *objectPtr_, s8 *dir);
static void CallbackObjectSetDirection(void *objectPtr_, s32 dir_);
static void CallbackObjectSetEventIndex(void *objectPtr_, u16 a1);
static void CallbackObjectSetUnk_80AC998(void *objectPtr_, s32 a1_, s32 a2);
static bool8 CallbackObjectSpriteRelatedCheck_80AC9B8(void *objectPtr_);
static bool8 CallbackObjectSpriteRelated_80AC9DC(void *objectPtr_);
static void CallbackObjectGetFlags(void *objectPtr_, u32 *flags);
static void CallbackObjectSetFlags(void *objectPtr_, u32 flags);
static void CallbackObjectClearFlags(void *objectPtr_, u32 flags);
static s32 CallbackObjectMoveRelative(void *objectPtr_, PixelPos *pos);


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
const u8 gGroundObjectFileName[];
#define FAKE_FILENAME gGroundObjectFileName
 















































static const struct ScriptCommand gUnknown_81182F4[] = {
    DEBUGINFO, // Needs to be line 159
    LABEL(0),
    WAIT(0x78),
    JUMP_LABEL(0),
};
ALIGNED(4) const u8 gGroundObjectFileName[] = "../ground/ground_object.c";
static const struct ScriptCommand gUnknown_8118350[] = {
    DEBUGINFO, // Needs to be line 166
    { 0x54, 0, 1, 0, 0, NULL },
    LABEL(0),
    WAIT(0x78),
    JUMP_LABEL(0),
};

const s16 gUnknown_81183A0[] = {
-1,  
0x800, 
0x801,  
0x1000, 
0x1001,  
0x1002,
0x1003,
0x800, 
0x801,  
0x802, 
0x803,
0x804, 
0x805,  
0x806, 
0x807,
0x808, 
0x809,  
0x80A, 
0x80B,  
0x80C, 
0x80D,  
0x80E, 
0x80F,  
0};

void AllocGroundObjects(void) 
{

    GroundObject *ptr;
    s32 index;

    gGroundObjects = MemoryAlloc(sizeof(GroundObject) * NUM_GROUND_OBJECTS, 6);
   
    for(index = 0,  ptr = &gGroundObjects[index]; index < NUM_GROUND_OBJECTS; index = (s16)(index + 1), ptr++)
    {
        ptr->kind |= -1;
    }
    DeleteGroundObjects();
}

void DeleteGroundObjects(void)
{
    GroundObject *ptr;
    s32 index;
    
    ptr = &gGroundObjects[0];
    for(index = 0; index < NUM_GROUND_OBJECTS; index = (s16)(index + 1), ptr++)
    {
        if(ptr->kind != -1)
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
    scriptPtr = GetGroundScript(scriptID_s32, DEBUG_LOC_PTR(gGroundObjectFileName, 0x126, "GroundObject_Select"));
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
    for(; index < NUM_GROUND_OBJECTS; index = (s16)(index + 1), ptr++)
    {
        if((ptr->kind != -1) && (ptr->group == scriptID_s32))
            if(sector_s32 < 0 || ptr->sector == sector_s32)
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
    for(; index < NUM_GROUND_OBJECTS; index = (s16)(index + 1), ptr++)
    {
        if(ptr->kind != -1)
        {
            stack.x = ptr->unk124.x + ptr->unk14.x;
            stack.y = ptr->unk124.y + ptr->unk14.y;
            if(!IsOnscreen_80A675C(&ptr->unk144, &stack))
                GroundObject_Delete(index);
        }
    }
}

static s32 GroundObject_Find(s32 kind)
{
    s32 index;
    GroundObject *ptr;

    s32 kind_s32 = (s16)kind;

    index = 0;
    ptr = &gGroundObjects[0];
    for(; index < NUM_GROUND_OBJECTS; index = (s16)(index + 1), ptr++)
    {
        if(ptr->kind == kind_s32) return index;
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
                   id = GroundObject_Find(kind);
                    break;
                  
          }
            
        if (id < 0) {
            for(index = 0, parent = gGroundObjects; index < NUM_GROUND_OBJECTS; index = (s16)(index + 1), parent++)
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
      }
      parent = &gGroundObjects[id];
      Log(0,"GroundObject Add id %3d  kind %3d[%3d]  type %3d  group %3d  sector %3d",id,kind,objectData->kind,typeDataPtr->unk0,group,sector);
      bVar12 = (parent->kind == -1);
      parent->id = id;
      parent->kind = kind;
      parent->group = group;
      parent->sector = sector;
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
      parent->direction1 = objectData->unk1;
    
      SetUnkInGroundEvent(&objectData->pos, &parent->unk20);
    
      if (bVar12) {
        parent->direction = parent->direction1;
        parent->unk124.x = parent->unk20.x - parent->unk14.x;
        parent->unk12C.x = parent->unk20.x + parent->unk14.x;
        parent->unk124.y = parent->unk20.y - parent->unk14.y;
        parent->unk12C.y = parent->unk20.y + parent->unk14.y;
        parent->unk134.x =  parent->unk134.y = 0;
      }
      GetCurrentDungeonBounds(&parent->unk28,&parent->unk30);
      if (bVar12) {
        parent->unk13E = 0x800;
        parent->directionRelated = 1;
        parent->unk140 = 0;
        sub_80A75CC(&(parent->unk144),id,parent->kind, parent->flags);
      }
    
      InitActionWithParams(&parent->action,&gGroundObjectCallbacks,parent,group,sector);
        
       // What an ugly way of coding that...
      SetPredefinedScript(&parent->action,1, (objectData->scripts[1] != NULL) ? objectData->scripts[1] 
          : (SpriteHasPokemonSize_80A66A4(&parent->unk144)) ? gUnknown_8118350 : gUnknown_81182F4);
      SetPredefinedScript(&parent->action,2,(objectData->scripts[2] != NULL) ? objectData->scripts[2] 
          : gFunctionScriptTable[4].script);
      SetPredefinedScript(&parent->action,3,(objectData->scripts[3] != NULL) ? objectData->scripts[3] 
          : gFunctionScriptTable[8].script);
        
      if (objectData->scripts[0] != NULL) {
        SetPredefinedScript(&parent->action,0,objectData->scripts[0]);
        ExecutePredefinedScript(&parent->action,NULL,0,DEBUG_LOC_PTR(gGroundObjectFileName, 0x283, "GroundObject_Add"));
      }
      return id;
}


void sub_80A6688(struct UnkGroundSpriteStruct *, s32);

void GroundObject_Delete(s32 index_) { 
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];    
    
    Log(0, "GroundObject Delete id %3d", index);
    sub_80A7658(&parent->unk144);
    InitAction2(&parent->action);
    parent->kind = -1;
}

void sub_80AC1B0(s32 index_, s32 flag)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->kind != -1)
    {
        parent->flags |= flag;
        sub_80A6688(&parent->unk144, parent->flags);
    }
}

void sub_80AC1F4(s32 index_, s32 flag)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->kind != -1)
    {
        parent->flags &= (0x337fffff ^ flag);
        sub_80A6688(&parent->unk144, parent->flags);
    }
}

Action *GroundObject_GetAction(s32 index_)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->kind != -1)
        return &parent->action;
    else
        return NULL;
}

extern bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s32 _index);


bool8 GroundObject_GetScript(s32 index_, ScriptInfoSmall *scriptInfo, s32 a2_)
{
    s32 index = (s16)index_;
    s32 a2 = (s16)a2_;
    GroundObject *parent = &gGroundObjects[index];

    if(parent->kind != -1)
        return GetPredefinedScript(&parent->action, scriptInfo, a2);
    else
        return FALSE;
}

extern DebugLocation gUnknown_8118504;

bool8 GroundObject_ExecuteScript(s32 index_, void *a1, ScriptInfoSmall *script)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    Log(0, "GroundObject Execute %3d  ", index);

    if(parent->kind != -1)
    {
        GroundScript_ExecutePP(&parent->action, (ActionUnkIds *)a1, script, DEBUG_LOC_PTR(gGroundObjectFileName, 0x303, "GroundObject_ExecuteScript"));
        parent->directionRelated = 1;
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
    
    for(counter = 0; counter < NUM_GROUND_OBJECTS; counter = (s16)(counter + 1), parent++)
    {
        if(parent->kind != -1)
            flag |= GroundScriptNotify(&parent->action, index);
    }

    return flag;
}

bool8 GroundObjectsCancelAll(void)
{
    s32 counter;
    GroundObject *parent = &gGroundObjects[0];
    bool8 flag = FALSE;
    
    for(counter = 0; counter < NUM_GROUND_OBJECTS; counter = (s16)(counter + 1), parent++)
    {
        if(parent->kind != -1)
            flag |= GroundScript_Cancel(&parent->action);
    }

    return flag;
}

static UNUSED s16 sub_80AC3C0(s32 index_)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];
    return parent->kind;
}

s16 GroundObject_GetFlags(s32 index_, s32 *flags)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];
    *flags = parent->flags;
    return parent->kind;
}

static UNUSED s16 sub_80AC408(s32 index_, PixelPos *a1)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];
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

s16 sub_80AC448(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

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

extern s32 TryMoveObjectRelative_80AC6AC(GroundObject *, PixelPos *);


s16 sub_80AC49C(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    TryMoveObjectRelative_80AC6AC(parent, pos);
    
    return parent->kind;
}

s32 sub_80AC4C8(s32 index, PixelPos *a0, PixelPos *a1) {
    GroundObject *parent = &gGroundObjects[0];
    s32 counter;

    for(counter = 0; counter < NUM_GROUND_OBJECTS; counter = (s16)(counter + 1), parent++)
    {
        if(parent->kind != -1)
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

s32 sub_80AC554(s32 flag, PixelPos *param_2,PixelPos *param_3)
{
  s32 i;
  GroundObject *parent;
  
  parent = &gGroundObjects[0];
  for(i = 0; i < NUM_GROUND_OBJECTS; i = (s16)(i + 1), parent++) {
    if ((parent->kind != -1))
    {
        if((parent->flags & flag)) {
            PixelPos pos = {(parent->unk124).x + (parent->unk14).x, (parent->unk124).y + (parent->unk14).y};
          if ((pos.x < param_3->x) && (((pos.x > param_2->x))))
              if(((pos.y < param_3->y)) && (pos.y > param_2->y)) {
                return i;
          }
        }
    }

  }
    return -1;
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
    return groundObject->id;
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
        if (objectPtr->direction != objectPtr->direction1) {
            objectPtr->directionRelated = TRUE;
        }
        objectPtr->direction = objectPtr->direction1;
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

static void CallbackObjectGetPosHeightAndUnk(void *objectPtr_, u32 *height, u32 *unk)
{
    struct GroundObject *objectPtr = objectPtr_;

    *height = objectPtr->unk134.x;
    *unk= objectPtr->unk134.y;
}

static void CallbackObjectSetPosHeight(void *objectPtr_, u32 height)
{
    struct GroundObject *objectPtr = objectPtr_;
    objectPtr->unk134.x = height;

}

static void CallbackObjectGetDirection(void *objectPtr_, s8 *dir)
{
    struct GroundObject *objectPtr = objectPtr_;
    *dir = objectPtr->direction;

}

static void CallbackObjectSetDirection(void *livesPtr_, s32 direction)
{
    struct GroundObject *livesPtr = livesPtr_;
    s32 dir = (s8) direction;

    if (dir != -1) {
        livesPtr->direction = dir;
    }
}

static void CallbackObjectSetEventIndex(void *livesPtr_, u16 a1) {
    struct GroundObject *livesPtr = livesPtr_;

    u32 r1;
    u16 f1 = a1 & 0xFF;

    if (f1 != 0)
    {
        r1 = gUnknown_81183A0[f1];
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


static void CallbackObjectSetUnk_80AC998(void *objectPtr_, s32 a1_, s32 a2) {
    struct GroundObject *livesPtr = objectPtr_;

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

extern bool8 sub_80A66F8(struct UnkGroundSpriteStruct *ptr);
extern bool8 sub_80A671C(struct UnkGroundSpriteStruct *ptr);

static bool8 CallbackObjectSpriteRelatedCheck_80AC9B8(void *objectPtr_)
{
    struct GroundObject *livesPtr = objectPtr_;

    if (livesPtr->directionRelated) {
        return TRUE;
    }
    else {
        return sub_80A66F8(&livesPtr->unk144);
    }
}

static bool8 CallbackObjectSpriteRelated_80AC9DC(void *objectPtr_)
{
    struct GroundObject *livesPtr = objectPtr_;

    if (livesPtr->unk140 != 0) {
        return TRUE;
    }
    else {
        return sub_80A671C(&livesPtr->unk144);
    }
}

static void CallbackObjectGetFlags(void *livesPtr_, u32 *flags)
{
    struct GroundObject *livesPtr = livesPtr_;

    *flags = livesPtr->flags;
}

static void CallbackObjectSetFlags(void *livesPtr_, u32 flags)
{
    struct GroundObject *livesPtr = livesPtr_;

    sub_80AC1B0(livesPtr->id, flags);
}

static void CallbackObjectClearFlags(void *livesPtr_, u32 flags)
{
    struct GroundObject *livesPtr = livesPtr_;

    sub_80AC1F4(livesPtr->id, flags);
}

static s32 CallbackObjectMoveRelative(void *livesPtr_, PixelPos *pos)
{
    struct GroundObject *livesPtr = livesPtr_;

    return TryMoveRelative_80AC720(livesPtr, pos);
}

extern s16 HandleAction(Action *action, DebugLocation *debug);

void GroundObject_Action(void)
{
    GroundObject *objectPtr;
    s32 i;
    s32 ret;

    for (objectPtr = &gGroundObjects[0], i = 0; i < NUM_GROUND_OBJECTS; i = (s16)(i + 1), objectPtr++)
    {
        if (objectPtr->kind != -1) {
            ret = HandleAction(&objectPtr->action, DEBUG_LOC_PTR(gGroundObjectFileName, 0x60D, "GroundObject_Action"));
            switch(ret)
            {
                case 4:
                    GroundObject_Delete(i);
                    continue;
                case 0:
                    ExecutePredefinedScript(&objectPtr->action, NULL, 1, DEBUG_LOC_PTR(gGroundObjectFileName, 0x617, "GroundObject_Action"));
                    break;
            }

            if (objectPtr->directionRelated) {
                objectPtr->directionRelated = FALSE;
                sub_80A6EFC(&objectPtr->unk144,objectPtr->unk13E & 0x1f00,(s8)objectPtr->unk13E);
            }
        }
    }
}

void sub_80A7664(struct UnkGroundSpriteStruct *ptr, PixelPos *pixelPos, s32 a2);
extern bool8 sub_80A66D4(struct UnkGroundSpriteStruct *ptr);

void sub_80ACAD4(void) 
{
    GroundObject *objectPtr;
    int i;
    // s16 memes
    s32 minus1;

    for (objectPtr = &gGroundObjects[0], i = 0, minus1 = -1; i < NUM_GROUND_OBJECTS; i = (s16)(i + 1), objectPtr++) {
        minus1 = (s16) minus1;
        if (objectPtr->kind != (s16) minus1) {
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
            sub_80A7664(&objectPtr->unk144,&pos,num);
        }
    }
}
