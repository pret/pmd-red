#ifndef GUARD_STATUS_ACTIONS_H
#define GUARD_STATUS_ACTIONS_H

#include "constants/move.h"
#include "dungeon_entity.h"

bool8 sub_805B668(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805B734(Entity *pokemon, Entity *target);
bool8 RecycleMoveAction(Entity *pokemon, Entity *target);
bool8 ReflectMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805B808(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805B884(Entity *pokemon, Entity *target);
bool8 SkullBashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805B910(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805B968(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 RockSmashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805BA44(Entity *pokemon, Entity *target);
bool8 sub_805BA50(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805BB64(Entity *pokemon, Entity *target);
bool8 sub_805BB74(Entity *pokemon, Entity *target);
bool8 sub_805BB98(Entity *pokemon, Entity *target);
bool8 CleanseOrbAction(Entity *pokemon,Entity *target);
bool8 sub_805BC70(Entity *pokemon, Entity *target);
bool8 sub_805BC98(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 SilenceOrbAction(Entity *pokemon,Entity *target);
bool8 ScannerOrbAction(Entity *pokemon, Entity *target);
bool8 RadarOrbAction(Entity *pokemon, Entity *target);
bool8 TransferOrbAction(Entity *pokemon,Entity *target);
bool8 sub_805BE90(Entity *pokemon, Entity *target);
bool8 LuminousOrbAction(Entity *pokemon,Entity *target);
bool8 sub_805BEAC(Entity *pokemon, Entity *target);
bool8 sub_805BEB8(Entity *pokemon, Entity *target);
bool8 sub_805BEC8(Entity *pokemon, Entity *target);
bool8 EscapeOrbAction(Entity *pokemon,Entity *target);
bool8 sub_805BF34(Entity *pokemon, Entity *target);
bool8 TrapbustOrbAction(Entity *pokemon,Entity *target);
bool8 sub_805C080(Entity *pokemon, Entity *target);
bool8 sub_805C128(Entity *pokemon, Entity *target);
bool8 sub_805C138(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 IdentifyOrbAction(Entity *pokemon, Entity *target);
bool8 sub_805C1BC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
bool8 sub_805C1E4(Entity *pokemon, Entity *target);
bool8 ShockerOrbAction(Entity *pokemon, Entity *target);
bool8 sub_805C208(Entity *pokemon, Entity *target, Move *move, u32 param_4);
bool8 sub_805C288(Entity *pokemon, Entity *target);
bool8 sub_805C2A0(Entity *pokemon, Entity *target);
bool8 FillInOrbAction(Entity *pokemon,Entity *target);
bool8 sub_805C3DC(Entity *pokemon, Entity *target);
bool8 sub_805C3F8(Entity *pokemon, Entity *target);
bool8 sub_805C45C(Entity *pokemon, Entity *target);
bool8 MobileOrbAction(Entity *pokemon, Entity *target);
bool8 StairsOrbAction(Entity *pokemon, Entity *target);
bool8 LongtossOrbAction(Entity *pokemon, Entity *target);
bool8 PierceOrbAction(Entity *pokemon, Entity *target);

#endif
