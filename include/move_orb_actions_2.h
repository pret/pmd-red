#ifndef GUARD_MOVE_ORB_ACTIONS_2_H
#define GUARD_MOVE_ORB_ACTIONS_2_H

#include "structs/dungeon_entity.h"
#include "structs/str_stat_index.h"

bool8 SkyAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BasicIceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MeteorMashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ScaryFaceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_8058E5C(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 LickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FissureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ExtrasensoryMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 AbsorbMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SkillSwapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HeadbuttMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 DoubleEdgeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_8059528(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SmogMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SacredFireMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_80595EC(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MuddyWaterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TwisterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TwineedleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_8059A2C(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SupersonicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TauntMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HornDrillMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ThundershockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ThunderWaveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BlockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PoisonGasMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ToxicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PoisonFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 EarthquakeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 UproarMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SandstormMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 Conversion2MoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PsychUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ConversionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SketchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 NaturePowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HelpingHandMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 EndureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 DamageLowerDefMoveAction(Entity *pokemon, Entity *target, Move *move, struct StatIndex stat, u32 param_5);
bool8 SonicboomMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SelfDestructMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ExplosionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ChargeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 WaterSpoutMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 StockpileMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 StunSporeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_8058C00(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_8059CD8(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ThunderboltMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ZapCannonMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MinimizeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SwordsDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 GrowthMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PsychoBoostMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SafeguardMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MistMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MoonlightMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SolarBeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_80599EC(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_8058EE0(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PsywaveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 WarpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FlyMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 DiveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);

#endif /* ifndef GUARD_MOVE_ORB_ACTIONS_2_H */

