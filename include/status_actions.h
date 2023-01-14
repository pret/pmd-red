#ifndef GUARD_STATUS_ACTIONS_H
#define GUARD_STATUS_ACTIONS_H

#include "constants/move.h"
#include "dungeon_entity.h"

bool8 sub_805B668(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805B734(struct Entity *pokemon, struct Entity *target);
bool8 RecycleMoveAction(struct Entity *pokemon, struct Entity *target);
bool8 ReflectMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805B808(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805B884(struct Entity *pokemon, struct Entity *target);
bool8 SkullBashMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805B910(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805B968(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 RockSmashMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805BA44(struct Entity *pokemon, struct Entity *target);
bool8 sub_805BA50(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805BB64(struct Entity *pokemon, struct Entity *target);
bool8 sub_805BB74(struct Entity *pokemon, struct Entity *target);
bool8 sub_805BB98(struct Entity *pokemon, struct Entity *target);
bool8 CleanseOrbAction(struct Entity *pokemon,struct Entity *target);
bool8 sub_805BC70(struct Entity *pokemon, struct Entity *target);
bool8 sub_805BC98(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 SilenceOrbAction(struct Entity *pokemon,struct Entity *target);
bool8 ScannerOrbAction(struct Entity *pokemon, struct Entity *target);
bool8 RadarOrbAction(struct Entity *pokemon, struct Entity *target);
bool8 TransferOrbAction(struct Entity *pokemon,struct Entity *target);
bool8 sub_805BE90(struct Entity *pokemon, struct Entity *target);
bool8 LuminousOrbAction(struct Entity *pokemon,struct Entity *target);
bool8 sub_805BEAC(struct Entity *pokemon, struct Entity *target);
bool8 sub_805BEB8(struct Entity *pokemon, struct Entity *target);
bool8 sub_805BEC8(struct Entity *pokemon, struct Entity *target);
bool8 EscapeOrbAction(struct Entity *pokemon,struct Entity *target);
bool8 sub_805BF34(struct Entity *pokemon, struct Entity *target);
bool8 TrapbustOrbAction(struct Entity *pokemon,struct Entity *target);
bool8 sub_805C080(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C128(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C138(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 IdentifyOrbAction(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C1BC(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
bool8 sub_805C1E4(struct Entity *pokemon, struct Entity *target);
bool8 ShockerOrbAction(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C208(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4);
bool8 sub_805C288(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C2A0(struct Entity *pokemon, struct Entity *target);
bool8 FillInOrbAction(struct Entity *pokemon,struct Entity *target);
bool8 sub_805C3DC(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C3F8(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C45C(struct Entity *pokemon, struct Entity *target);
bool8 sub_805C468(struct Entity *pokemon, struct Entity *target);
bool8 StairsOrbAction(struct Entity *pokemon, struct Entity *target);
bool8 LongtossOrbAction(struct Entity *pokemon, struct Entity *target);
bool8 PierceOrbAction(struct Entity *pokemon, struct Entity *target);

#endif
