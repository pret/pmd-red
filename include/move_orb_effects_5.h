#ifndef GUARD_MOVE_ORB_EFFECTS_5_H
#define GUARD_MOVE_ORB_EFFECTS_5_H

#include "structs/dungeon_entity.h"

void sub_8079F20(Entity * pokemon, Entity * target, u8 param_3, u8 param_4);
void sub_807A0CC(Entity * pokemon, Entity * target);
void EndSleepClassStatus(Entity * pokemon, Entity * target, bool8 param_3, bool8 param_4);
void EndBurnClassStatus(Entity * pokemon, Entity * target);
void EndFrozenClassStatus(Entity * pokemon, Entity *target);
void EndCringeClassStatus(Entity * pokemon, Entity *target);
void EndReflectClassStatus(Entity * pokemon, Entity *target);
void EndCurseClassStatus(Entity * pokemon, Entity * target, u8 curseClassStatus);
void EndLeechSeedClassStatus(Entity * pokemon, Entity * target);
void SendMoveEndMessage(Entity * pokemon, Entity * target);
void SendTransformEndMessage(Entity * pokemon, Entity *target);
void SendEyesightEndMessage(Entity * pokemon,Entity * target);
void SendMuzzledEndMessage(Entity * pokemon, Entity * target);
bool8 TrySendImmobilizeSleepEndMsg(Entity *pokemon, Entity *target);
void WakeUpPokemon(Entity * pokemon);
void SendThawedMessage(Entity *pokemon, Entity *target);

#endif

