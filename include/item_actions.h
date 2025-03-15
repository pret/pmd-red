#ifndef INCLUDE_ITEM_ACTIONS_H
#define INCLUDE_ITEM_ACTIONS_H

#include "structs/dungeon_entity.h"
void StunSeedItemAction(Entity *pokemon, Entity *target);
void MaxElixirAction(Entity *pokemon, Entity *target);
void ProteinItemAction(Entity *pokemon, Entity *target);
void CalciumItemAction(Entity *pokemon, Entity *target);
void IronItemAction(Entity *pokemon, Entity *target);
void ZincItemAction(Entity *pokemon, Entity *target);
void sub_80487CC(Entity *pokemon, Entity *target, u32 param_3, u32 param_4);
void GrimyFoodItemAction(Entity *pokemon, Entity *target);
void HandleGummiItemAction(Entity *pokemon, Entity *target, u8 r2);
void IcePartItemAction(Entity *pokemon, Entity *target, u8 r2);
void SteelPartItemAction(Entity *pokemon, Entity *target, u8 r2);
void RockPartItemAction(Entity *pokemon, Entity *target, u8 r2);
void MusicBoxItemAction(Entity *pokemon, Entity *target, u8 r2);
void nullsub_94(Entity *pokemon, Entity *target, u8 r2);
void KeyItemAction(Entity *pokemon, Entity *target, u8 r2);
void sub_8048340(Entity *pokemon, Entity *target, u32 r2);
void HealSeedItemAction(Entity *pokemon, Entity *target, u8 r2);
void WishStoneItemAction(Entity *pokemon, Entity *target, u8 r2);
void OranBerryItemAction(Entity *pokemon, Entity *target);
void ChestoBerryItemAction(Entity *pokemon, Entity *target);
void JoySeedItemAction(Entity *pokemon, Entity *target);
void GinsengItemAction(Entity *pokemon, Entity *target);
void BlastSeedItemAction(Entity *pokemon, Entity *target, u8 r2);
void SitrusBerryItemAction(Entity *pokemon, Entity *target);
void WarpSeedItemAction(Entity *pokemon, Entity *target);
void PlainSeedItemAction(Entity *pokemon, Entity *target);
void SleepSeedItemAction(Entity *pokemon, Entity *target);
void TotterSeedItemAction(Entity *pokemon, Entity *target);
void CheriBerryItemAction(Entity *pokemon, Entity *target);
void PechaBerryItemAction(Entity *pokemon, Entity *target);
void QuickSeedItemAction(Entity *pokemon, Entity *target);
void HungerSeedItemAction(Entity *pokemon, Entity *target);
void RawstBerryItemAction(Entity *pokemon, Entity *target);
void LifeSeedItemAction(Entity *pokemon, Entity *target);
void AllureSeedItemAction(Entity *pokemon, Entity *target);
void EyedropSeedItemAction(Entity *pokemon, Entity *target);
void BlinkerSeedItemAction(Entity *pokemon, Entity *target);
void DoomSeedItemAction(Entity *pokemon, Entity *target);
void sub_80482FC(Entity *pokemon, Entity *target, u32 pp, u8 param_4);


#endif /* ifndef INCLUDE_ITEM_ACTIONS_H */
