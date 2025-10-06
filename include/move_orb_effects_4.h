#ifndef GUARD_MOVE_ORB_EFFECTS_4_H
#define GUARD_MOVE_ORB_EFFECTS_4_H

#include "structs/dungeon_entity.h"

void CounterStatusTarget(Entity * pokemon, Entity * target, u8 newStatus);
void SafeguardStatusTarget(Entity * pokemon, Entity * target);
void MistStatusTarget(Entity * pokemon, Entity * target);
void WishStatusTarget(Entity * pokemon, Entity * target);
void MagicCoatStatusTarget(Entity * pokemon, Entity * target);
void LightScreenStatusTarget(Entity * pokemon, Entity * target);
void ReflectStatusTarget(Entity * pokemon, Entity * target);
void ProtectStatusTarget(Entity * pokemon, Entity * target);
void MirrorCoatStatusTarget(Entity * pokemon, Entity * target);
void EndureStatusTarget(Entity * pokemon, Entity * target);
void MirrorMoveStatusTarget(Entity * pokemon, Entity * target);
void Conversion2StatusTarget(Entity * pokemon, Entity * target);
void VitalThrowStatusTarget(Entity * pokemon, Entity * target);
void sub_8079E34(Entity * pokemon, Entity * target, bool8 param_3);

#endif

