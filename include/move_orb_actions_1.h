#ifndef GUARD_MOVE_ORB_ACTIONS_1_H
#define GUARD_MOVE_ORB_ACTIONS_1_H

#include "structs/dungeon_entity.h"
#include "structs/str_stat_index.h"

bool8 IronTailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_805768C(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 YawnMoveAction(Entity * pokemon, Entity *target, Move *move, s32 itemId);
bool8 BasicSleepMoveAction(Entity * pokemon, Entity *target, Move *move, s32 itemId);
bool8 NightmareMoveAction(Entity * pokemon, Entity *target, Move *move, s32 itemId);
bool8 MorningSunMoveAction(Entity * pokemon,Entity * target, Move *move, s32 itemId);
bool8 VitalThrowMoveAction(Entity * pokemon, Entity * target, Move *move, s32 itemId);
bool8 DigMoveAction(Entity * pokemon, Entity * target, Move *move, s32 itemId);
bool8 SweetScentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 CharmMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RainDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_80578EC(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BubbleMoveAction(Entity *pokemon, Entity *target, Move * move, s32 itemId);
bool8 EncoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SuperFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 PainSplitMoveAction(Entity *attacker, Entity *target, Move *move, s32 itemId);
bool8 TormentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 StringShotMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SwaggerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SnoreMoveAction(Entity *pokemon, Entity *target, Move * move, s32 itemId);
bool8 ScreechMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RockSlideMoveAction(Entity *pokemon, Entity *target, Move * move, s32 itemId);
bool8 WeatherBallMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId);
bool8 WhirlpoolMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId);
bool8 FakeTearsMoveAction(Entity * pokemon, Entity * target, Move *move, s32 itemId);
bool8 SpiteMoveAction(Entity * pokemon, Entity * target, Move *move, s32 itemId);
bool8 FocusEnergyMoveAction(Entity * pokemon, Entity * target, Move *move, s32 itemId);
bool8 SmokescreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MirrorMoveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 OverheatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 AuroraBeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 MementoMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 OctazookaMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FlatterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 WillOWispMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ReturnMoveAction(Entity * pokemon,Entity * target,Move * move,s32 itemId);
bool8 GrudgeMoveAction(Entity *pokemon, Entity * target, Move *move, s32 itemId);
bool8 CounterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FlameWheelMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BasicFireMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ExposeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 DoubleTeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 GustMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BasicRaiseDefenseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 DisableMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BasicRaiseAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RazorWindMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId);
bool8 BideMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 Bide2MoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ShadowBallMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BiteMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 ThunderMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 EndeavorMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FacadeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_8058580(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 BrickBreakMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RockTombMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 FocusPunchMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId);
bool8 GigaDrainMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId);
bool8 ReversalMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId);
bool8 SmellingSaltMoveAction(Entity * pokemon, Entity * target, Move * move, s32 itemId);
bool8 MetalSoundMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 TickleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 sub_805889C(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 HazeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 OutrageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 LowKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 AncientPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SynthesisMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 AgilityMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 RapidSpinMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 SureShotMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);
bool8 CosmicPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 itemId);

extern const struct StatIndex gStatIndexAtkDef;
extern const struct StatIndex gStatIndexSpecial;

#endif /* ifndef GUARD_MOVE_ORB_ACTIONS_1_H */
