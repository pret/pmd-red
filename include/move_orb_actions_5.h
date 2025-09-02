#ifndef GUARD_MOVE_ORB_ACTIONS_5_H
#define GUARD_MOVE_ORB_ACTIONS_5_H

#include "structs/dungeon_entity.h"

bool8 FillInOrbAction(Entity *pokemon,Entity *target, Move *move, s32 itemId);
bool8 ItemizeOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HurlOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MobileOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 StairsOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 LongtossOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PierceOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TrapperOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);

#endif /* ifndef MOVE_ORB_ACTIONS_5_H */
