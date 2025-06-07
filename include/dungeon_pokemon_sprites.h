#ifndef GUARD_DUNGEON_POKEMON_SPRITES_H
#define GUARD_DUNGEON_POKEMON_SPRITES_H

#include "structs/str_position.h"

void InitDungeonPokemonSprites(void);
void FreeDungeonPokemonSprites(void);
void UpdateDungeonPokemonSprite(s32 dungeonSpriteId, s32 species_, s32 status, u32 visible_);
void FrameUpdateDungeonStatusSprites(DungeonPos *screenPos);
void AddPokemonDungeonSprite(s32 dungeonSpriteId, s32 species_, DungeonPos *pos, u32 priority);
void DeletePokemonDungeonSprite(s32 dungeonSpriteId);
void UpdateDungeonPokemonSprite2(s32 dungeonSpriteId, DungeonPos *pos, DungeonPos *statusOffsets, u32 priority);

#endif // GUARD_DUNGEON_POKEMON_SPRITES_H
