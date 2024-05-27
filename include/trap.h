#ifndef GUARD_TRAP_H
#define GUARD_TRAP_H

#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_position.h"

bool8 CanLayTrap(Position *pos);
bool8 LayTrap(Position *pos, u8 trapID, u8 param_3);
bool8 sub_807FD84(Entity *entity);
bool8 sub_807FE04(Position *pos, char param_2);
bool8 sub_807FE44(Position *pos, char param_2);
void GetTrapName(u8 *buffer, u8 trapIndex);
void sub_807FE9C(Entity *pokemon, Position *pos, int param_3, char param_4);
void HandleMudTrap(Entity *pokemon, Entity *target);
void HandleStickyTrap(Entity *pokemon, Entity *target);
void HandleGrimyTrap(Entity *pokemon, Entity *target);
void HandleSummonTrap(Entity *pokemon, Position *pos);
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

// code_807FCD4.s
extern void HandleSealTrap(Entity *pokemon, Entity *target);
extern void HandleWhirlwindTrap(Entity *entity, Entity *target);
extern void HandlePokemonTrap(Entity *pokemon, Position *pos);

// trap_1.c
void HandleTripTrap(Entity *pokemon, Entity *target);
void SetTrap(Tile *tile, u8 id);

#endif
