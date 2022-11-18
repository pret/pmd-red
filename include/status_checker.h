#ifndef GUARD_STATUS_CHECKER_H
#define GUARD_STATUS_CHECKER_H

#include "constants/move.h"
#include "dungeon_entity.h"

bool8 sub_805B668(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805B734(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 RecycleMoveAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 ReflectMoveAction(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805B808(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805B884(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 SkullBashMoveAction(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805B910(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805B968(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 RockSmashMoveAction(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805BA44(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805BA50(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805BB64(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805BB74(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805BB98(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 CleanseOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target);
bool8 sub_805BC70(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805BC98(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 SilenceOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target);
bool8 ScannerOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 RadarOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 TransferOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target);
bool8 sub_805BE90(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 LuminousOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target);
bool8 sub_805BEAC(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805BEB8(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805BEC8(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 EscapeOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target);
bool8 sub_805BF34(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 TrapbustOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target);
bool8 sub_805C080(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805C128(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805C138(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 IdentifyOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
u32 sub_805C1BC(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4);
bool8 sub_805C1E4(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 ShockerOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805C208(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, u32 param_4);
bool8 sub_805C288(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805C2A0(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 FillInOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target);
bool8 sub_805C3DC(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805C3F8(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805C45C(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 sub_805C468(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 StairsOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 LongtossOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 PierceOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target);
bool8 CanUseOnSelfWithStatusChecker(struct DungeonEntity *pokemon, struct PokemonMove *move);
bool8 CanUseOnTargetWithStatusChecker(struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move);
bool8 HasDisabledMove(struct PokemonMove *moves);
bool8 LastUsedMoveOutOfPP(struct PokemonMove *moves);
bool8 HasLastUsedMove(struct PokemonMove *moves);

#endif
