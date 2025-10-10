#ifndef GUARD_MOVE_ORB_EFFECTS_2_H
#define GUARD_MOVE_ORB_EFFECTS_2_H

#include "structs/dungeon_entity.h"

void ConfuseStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void CowerStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void HealTargetHP(Entity *pokemon, Entity *target, s32 param_3, s32 param_4, bool32 displayMessage);
void HandleScannerOrb(Entity* pokemon, Entity* target);
void HandleStairsOrb(Entity* pokemon, Entity* target);
void HandleRadarOrb(Entity* pokemon, Entity* target);
void HandleLeechSeed(Entity * pokemon, Entity * target, bool8 displayMessage);
void sub_8078084(Entity * pokemon);
void DestinyBondStatusTarget(Entity * pokemon, Entity * target);
void SureShotStatusTarget(Entity *pokemon, Entity * target, s32 turns);
void WhifferStatusTarget(Entity *pokemon, Entity * target, s32 turns);
void FixedDamageStatusTarget(Entity *pokemon, Entity * target);
void FocusEnergyStatusTarget(Entity *pokemon, Entity * target);
void sub_80783C4(Entity * pokemon, Entity * target, bool8 param_3);
void CurseStatusTarget(Entity *pokemon, Entity * target);
void SnatchStatusTarget(Entity * pokemon, Entity * target);
void TauntStatusTarget(Entity * pokemon, Entity * target);
void HandleStockpile(Entity * pokemon, Entity * target);
void InvisibleStatusTarget(Entity * pokemon, Entity * target);
void PerishSongTarget(Entity * pokemon, Entity * target);
void EncoreStatusTarget(Entity * pokemon, Entity * target);
void sub_8078A58(struct Entity *pokemon, struct Entity *target, s32 param_3, s32 param_4);
void sub_8078B5C(Entity *pokemon, Entity *target, u32 bellyIncrement, s32 maxBellyIncrement, bool8 displayMessage);
void MuzzleTarget(Entity *pokemon, Entity *target);
void TransformStatusTarget(Entity * pokemon, Entity * target);
void MobileStatusTarget(Entity * pokemon, Entity * target);
void ExposeStatusTarget(Entity * pokemon, Entity * target, s16 param_3);
void IdentityItemHolders(Entity *pokemon, Entity *target);
void BlindTarget(Entity *pokemon, Entity *target);
void CrossEyeVisionTarget(Entity *pokemon, Entity *target);
void RestoreVisionTarget(Entity *pokemon, Entity *target);
void RestorePPTarget(Entity * pokemon,Entity * target, s32 param_3);
void RaiseAtkStatTarget(Entity * pokemon,Entity * target, s32 increment);
void RaiseSpAtkStatTarget(Entity * pokemon,Entity * target, s32 increment);
void RaiseDefStatTarget(Entity * pokemon,Entity * target, s32 increment);
void RaiseSpDefStatTarget(Entity * pokemon,Entity * target, s32 increment);
void LongTossStatusTarget(Entity * pokemon,Entity * target);
void PierceStatusTarget(Entity * pokemon,Entity * target);

#endif

