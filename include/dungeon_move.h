#ifndef GUARD_DUNGEON_MOVE_H
#define GUARD_DUNGEON_MOVE_H

#define MAX_MOVE_TARGETS 64

#include "number_util.h"
#include "structs/str_moves.h"
#include "structs/dungeon_entity.h"

extern s32 gUnknown_202F208;
extern s32 gUnknown_202F20C;
extern s32 gUnknown_202F210;
extern s32 gUnknown_202F214;
extern u8 gUnknown_202F218;
extern u8 gUnknown_202F219;
extern u8 gUnknown_202F21A;
extern s32 gUnknown_202F21C;
extern u8 gUnknown_202F220;
extern u8 gUnknown_202F221;
extern u8 gUnknown_202F222;
extern s32 gUnknown_202F224;
extern s32 gMetronomeCalledArrayId;

void UseMoveAgainstTargets(Entity **targetsArray, Entity *attacker, Move *move, s32 itemId, bool32 isLinkedMove);
bool32 HandleRegularDamagingMove(Entity *attacker, Entity *target, Move *move, s32 itemId);
s32 HandleDamagingMove(Entity *attacker, Entity *target, Move *move, s24_8 modifier, s32 itemId);
s32 sub_80556BC(Entity *attacker, Entity *target, u8 moveType, Move *move, s24_8 modifier, s32 itemId);
s32 sub_8055864(Entity *attacker, Entity *target, Move *move, s32 param_4, s32 itemId);
bool8 sub_8055988(Entity *r2, Entity *r4);
void sub_80559DC(Entity *entity1, Entity *entity2);

#endif // GUARD_DUNGEON_MOVE_H
