#ifndef GUARD_MOVE_ORB_ACTIONS_3_H
#define GUARD_MOVE_ORB_ACTIONS_3_H

#include "structs/dungeon_entity.h"
#include "structs/str_stat_index.h"

bool8 PoisonStingMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TriAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TrickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TripleKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MudSlapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ThiefMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RolePlayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 LeerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PayDayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 CurseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_805A568(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SuperpowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 DynamicPunchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 KnockOffMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SecretPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_805AC90(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ObserverOrbAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FeatherDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BeatUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BlastBurnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 CrushClawMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BlazeKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PresentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 EruptionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 GlareMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PoisonTailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RoarMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_805B17C(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 WrapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MagnitudeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FakeOutMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TailGlowMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SurfMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PerishSongMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SunnyDayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BellyDrumMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HiJumpKickMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId,u8 param_5);
bool8 JumpKickMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId,u8 param_5);
bool8 SteelWingMoveAction(Entity *pokemon, Entity *target, Move *move, struct StatIndex stat, u32 param_5);
bool8 BulkUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 AmnesiaMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HandleColorChange(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TransformMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SplashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SpitUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SwallowMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 GrowlMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 LightScreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RestMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_805A450(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MudWaterSportMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 IngrainMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MagicCoatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SpikesMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 WishMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BounceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 AssistMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_805AAD0(Entity *pokemon, Entity *target, Move *move, s32 itemId);

#endif /* ifndef GUARD_MOVE_ORB_ACTIONS_3_H */
