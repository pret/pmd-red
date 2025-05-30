#include "gba/types.h"
#include "global.h"
#include "structs/str_ground_script.h"
#include "ground_script.h"
#include "event_flag.h"
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
    u8 unk1C;
    PixelPos unk20;
    PixelPos unk28;
    PixelPos unk30;
    Action unk38;
    u32 flags;
    u8 unk120;
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

extern CallbackData gGroundObjectCallbacks[];

void DeleteGroundObjects(void);
void GroundObject_Delete(s32);

extern DebugLocation gUnknown_81183E4;
extern u8 gUnknown_81183F0[];
extern u8 gUnknown_8118414[];
extern u8 gUnknown_811842C[];
extern u8 gUnknown_81184B0[];
extern DebugLocation gUnknown_81184A4;
extern ScriptCommand gUnknown_8118350;
extern ScriptCommand gUnknown_81182F4;
extern u8 gUnknown_8118448[];

const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
void sub_80A7658(struct UnkGroundSpriteStruct *);
extern bool8 GroundScriptNotify(Action*, s32);
extern bool8 GroundScript_Cancel(Action *r0);
void SetPredefinedScript(Action *param_1, s16 index, const ScriptCommand *param_3);
bool8 ExecutePredefinedScript(Action *param_1, s32 *param_2, s16 index, DebugLocation *debug);

extern bool8 GetCurrentDungeonBounds(PixelPos *a0, PixelPos *a1);
void sub_80A75CC(void *, s32, s32, s32);
bool8 SpriteHasPokemonSize_80A66A4(struct UnkGroundSpriteStruct *ptr);


s32 GroundObject_Add(s32 id_,const GroundObjectData *objectData,s32 group_,s32 sector_);

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
        if (GetScriptVarValue(NULL,0x28) < 2) { // BASE_LEVEL
          kind = 0x1b;
        }
        else {
          sVar4 = GetScriptVarValue(NULL,0x29); // FLAG_KIND
          if (sVar4 == 0) {
            sVar3 = GetScriptVarValue(NULL,0x27) + 0x1c; // BASE_KIND
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
      Log('\0',gUnknown_8118448,id,kind,objectData->kind,typeDataPtr->unk0,group,sector);
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
    
      InitActionWithParams(&parent->unk38,gGroundObjectCallbacks,parent,group,sector);
        
       // What an ugly way of coding that...
      SetPredefinedScript(&parent->unk38,1, (objectData->scripts[1] != NULL) ? objectData->scripts[1] 
          : (SpriteHasPokemonSize_80A66A4(&parent->unk144)) ? &gUnknown_8118350 : &gUnknown_81182F4);
      SetPredefinedScript(&parent->unk38,2,(objectData->scripts[2] != NULL) ? objectData->scripts[2] 
          : gFunctionScriptTable[4].script);
      SetPredefinedScript(&parent->unk38,3,(objectData->scripts[3] != NULL) ? objectData->scripts[3] 
          : gFunctionScriptTable[8].script);
        
      if (objectData->scripts[0] != NULL) {
        SetPredefinedScript(&parent->unk38,0,objectData->scripts[0]);
        ExecutePredefinedScript(&parent->unk38,NULL,0,&gUnknown_81184A4);
      }
      return id;
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

extern void TryMoveObjectRelative_80AC6AC(void *, PixelPos *);


s16 sub_80AC49C(s32 index_, PixelPos *pos)
{
    s32 index = (s16)index_;
    GroundObject *parent = &gGroundObjects[index];

    TryMoveObjectRelative_80AC6AC(parent, pos);
    
    return parent->unk6;
}
