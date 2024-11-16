#ifndef GUARD_DUNGEON_UTIL_1_H
#define GUARD_DUNGEON_UTIL_1_H

#include "structs/dungeon_entity.h"

typedef void (*DungeonCallback)(Entity *);
typedef struct struct_8085B80 {
    u8 unk0;
    Entity *unk4;
    s32 unk8;
    s16 *unkC;
} struct_8085B80;

Entity *xxx_call_GetLeader(void);
Entity *GetPartnerEntity(void);
void sub_80854D4(void);
void sub_80855E4(DungeonCallback func);
void sub_808563C(DungeonCallback func);
Entity *GetEntityFromMonsterBehavior(u8 entityType);
void sub_80856C8(Entity * pokemon, s32 x, s32 y);
void sub_80856E0(Entity * pokemon, s32 direction);
void sub_8085764(void);
void sub_8085860(s32 x, s32 y);
void sub_8085890(s32 x, s32 y);
void ShiftCameraToPosition(PixelPos *posStruct, s32 cameraSteps);
void SetFacingDirection(Entity *pokemon, s32 direction);
void sub_8085930(s32 direction);
void sub_80859F0(s32 direction);
bool8 ShouldRunMonsterAI(Entity *entity);
void sub_8085B0C(Entity *pokemon);
void sub_8085B4C(struct_8085B80 a0[], s16 *a1[], Entity *a2[], s32 a3);
void sub_80857B8(void);

#endif
