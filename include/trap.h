#ifndef GUARD_TRAP_H
#define GUARD_TRAP_H

#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_position.h"

void sub_807FA9C(void);
void sub_807FC3C(DungeonPos *pos, u32 trapID, u32 param_3);
bool8 CanLayTrap(DungeonPos *pos);
bool8 LayTrap(DungeonPos *pos, u8 trapID, u8 param_3);
bool8 sub_807FD84(Entity *entity);
bool8 sub_807FE04(DungeonPos *pos, char param_2);
bool8 sub_807FE44(DungeonPos *pos, char param_2);
void GetTrapName(u8 *buffer, u8 trapIndex);
void TryTriggerTrap(Entity *pokemon, DungeonPos *pos, int param_3, char param_4);
void HandleMudTrap(Entity *pokemon, Entity *target);
void HandleStickyTrap(Entity *pokemon, Entity *target);
void HandleGrimyTrap(Entity *pokemon, Entity *target);
void HandleSummonTrap(Entity *pokemon, DungeonPos *pos);
void HandlePitfallTrap(Entity *pokemon,Entity *target,Tile *tile);
void HandleWarpTrap(Entity *pokemon, Entity *target);
void HandleSpinTrap(Entity *pokemon, Entity *target);
void HandleSlumberTrap(Entity *pokemon, Entity *target);
void HandleSlowTrap(Entity *pokemon, Entity *target);
void HandlePoisonTrap(Entity *pokemon, Entity *target);
void HandleSelfdestructTrap(Entity *pokemon, Entity *target);
void HandleExplosionTrap(Entity *pokemon, Entity *target);
void HandlePPZeroTrap(Entity *pokemon, Entity *target);
void HandleWonderTile(Entity *pokemon, Entity *target);
void HandleSealTrap(Entity *pokemon, Entity *target);
void HandleWhirlwindTrap(Entity *entity, Entity *target);
void HandlePokemonTrap(Entity *pokemon, DungeonPos *pos);
void HandleTripTrap(Entity *pokemon, Entity *target);
void SetTrap(Tile *tile, u8 id);

#endif
