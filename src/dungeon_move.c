#include "global.h"
#include "globaldata.h"
#include "dungeon_move.h"
#include "dungeon_move_util.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "structs/str_damage.h"
#include "dungeon_move_util.h"
#include "code_800DAC0.h"
#include "code_800E9E4.h"
#include "code_800ED38.h"
#include "dungeon_vram.h"
#include "code_803E668.h"
#include "code_803E724.h"
#include "code_8041AD0.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "dungeon_logic.h"
#include "dungeon_config.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "move_util.h"
#include "moves.h"
#include "position_util.h"
#include "sprite.h"
#include "status.h"
#include "status_actions.h"
#include "weather.h"
#include "targeting_flags.h"
#include "text_util.h"

extern void sub_80429C8(Entity *r0);
extern bool8 sub_8045888(Entity *r0);
extern void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4, bool32 arg8, s32 argC);
extern void CalcDamage(Entity *, Entity *, u8, u32, u32, struct DamageStruct *dmgStruct, s24_8, u16, u32);
extern s16 sub_8057600(Move *move, s32 itemID);
extern void sub_803ED30(s32, Entity *r0, u8, s32);
extern void sub_8042238(Entity *pokemon, Entity *target);
extern void sub_806A1E8(Entity *pokemon);
extern bool8 sub_8044B28(void);
extern void sub_804178C(u32);
extern void sub_8071DA4(Entity *);
extern void sub_80428A0(Entity *r0);
extern bool8 sub_8040BB0(Entity *entity, Move *move, bool8);
extern void sub_8040DA0(Entity *entity, Move *move);
extern u16 sub_80412E0(u16 moveId, u8 weather, u8 a2);
extern void sub_800EF10(u16 r0);
extern s32 sub_800E710(s16 a0, u16 a1);
extern void sub_800E3AC(s32 a0, DungeonPos *pos, s32 a2);
extern void sub_8041168(Entity *entity, Entity *entity2, Move *,DungeonPos *);
extern Entity *sub_80696A8(Entity *a0);
extern Entity *GetMonsterAtPos(DungeonPos *pos);
extern Entity *sub_80696FC(Entity *);
extern Entity *sub_806977C(Entity *);
extern void sub_806F2BC(Entity *attacker, Entity *target, u8 moveType, s32 a2, struct DamageStruct *dmgStruct);
extern void MarkLastUsedMonMove(Entity *entity, Move *move);
extern s32 sub_8057070(Move *move);
extern bool8 MoveRequiresCharging(Entity* pokemon,u16 param_2);
extern s32 sub_800ED20(u16 param_1);
extern bool32 EarthquakeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern void sub_8042930(Entity *r0);
extern void sub_8041B48(Entity *pokemon);
extern void sub_8041BA8(Entity *pokemon);
extern void sub_8042950(Entity *r0);
extern void sub_80421C0(Entity *pokemon, u16 r1);
extern bool8 IronTailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 YawnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 NightmareMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CharmMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EncoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SuperFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PainSplitMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TormentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SwaggerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RockSlideMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WhirlpoolMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SurfMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805889C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FakeTearsMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SpiteMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmokescreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FlatterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WillOWispMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ReturnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FlameWheelMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BasicFireMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4);
extern bool8 BasicIceMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4);
extern bool8 GustMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DisableMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ShadowBallMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BiteMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThunderMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EndeavorMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FacadeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058580(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BrickBreakMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RockTombMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GigaDrainMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ReversalMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmellingSaltMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MetalSoundMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TickleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 OutrageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LowKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AncientPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058C00(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RapidSpinMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ScaryFaceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058E5C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FissureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ExtrasensoryMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AbsorbMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SkillSwapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HeadbuttMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DoubleEdgeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059528(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmogMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SacredFireMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80595EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 OneShotOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MuddyWaterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TwisterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TwineedleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059A2C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SupersonicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TauntMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HornDrillMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThundershockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThunderWaveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BlockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonGasMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ToxicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonStingMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TriAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TrickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TripleKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MudSlapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThiefMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RolePlayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LeerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PayDayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CurseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A568(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FocusEnergyMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SuperpowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DynamicPunchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 KnockOffMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SecretPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AC90(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ObserverOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FeatherDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BeatUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BlastBurnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CrushClawMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BlazeKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PresentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EruptionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GlareMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonTailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RoarMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B17C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WrapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MagnitudeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MistBallMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DestinyBondMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FalseSwipeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HiddenPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AttractMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MimicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FrustrationMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LeechSeedMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DreamEaterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LusterPurgeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DragonRageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FakeOutMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 StunSporeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HiJumpKickMoveAction(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5);
extern bool8 JumpKickMoveAction(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5);
extern void SetShopkeeperAggression(Entity *, Entity *);
extern bool8 MoveCausesPaused(Move *move);
extern void sub_8069F9C(Entity *pokemon,Entity * target,Move *move);
extern void sub_806A120(Entity *pokemon,Entity * target,Move *move);
extern bool8 sub_8058C98(Entity *pokemon, Entity *target, Move *move, u32 param_4, u32 param_5);
extern bool8 MetalClawMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4, u32 param_5);
extern bool8 SteelWingMoveAction(Entity *pokemon, Entity *target, Move *move, u32 param_4, u32 param_5);
extern bool8 MeteorMashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SonicboomMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BasicSleepMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThunderboltMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ZapCannonMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TailGlowMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MinimizeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BulkUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BasicRaiseAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SwordsDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CalmMindMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GrowthMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AmnesiaMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DefenseCurlMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059CD8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CosmicPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 OctazookaMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AuroraBeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PsychoBoostMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GrowlMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ScreechMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SolarBeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SkyAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 UproarMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SandstormMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SafeguardMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MistMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LightScreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805768C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MementoMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80599EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SynthesisMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MoonlightMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RestMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058EE0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AgilityMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CounterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BideMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 Bide2MoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TrapperOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A450(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RazorWindMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FocusPunchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MagicCoatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MorningSunMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MudWaterSportMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 IngrainMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PsywaveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SpikesMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80578EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HazeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WishMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 OverheatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WarpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BasicRaiseDefenseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SureShotMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 VitalThrowMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FlyMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BounceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DiveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DigMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SweetScentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DoubleTeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GrudgeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AssistMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AAD0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B314(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ProtectMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SelfDestructMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ExplosionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ChargeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WaterSpoutMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 StockpileMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SpitUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SwallowMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RainDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 InvisifyOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MirrorCoatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PerishSongMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WeatherBallMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SunnyDayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EndureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HelpingHandMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BellyDrumMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BubbleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 StringShotMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TransformMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ExposeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SplashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ReboundOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 NaturePowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SketchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MirrorMoveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ConversionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SnatchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HandleColorChange(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PsychUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SnoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MetronomeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 Conversion2MoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);

extern const s32 gUnknown_8106A50;
extern const s32 gUnknown_8106A4C;

static s32 TryHitTarget(Entity *attacker, Entity *target, Move *move, struct DamageStruct *dmgStruct, s16 unk_);

EWRAM_DATA s32 gUnknown_202F208 = 0;
EWRAM_DATA s32 gUnknown_202F20C = 0;
EWRAM_DATA s32 gUnknown_202F210 = 0;
EWRAM_DATA s32 gUnknown_202F214 = 0;
EWRAM_DATA u8 gUnknown_202F218 = 0;
EWRAM_DATA u8 gUnknown_202F219 = 0;
EWRAM_DATA u8 gUnknown_202F21A = 0;
EWRAM_DATA s32 gUnknown_202F21C = 0;
EWRAM_DATA u8 gUnknown_202F220 = 0;
EWRAM_DATA u8 gUnknown_202F221 = 0;
EWRAM_DATA u8 gUnknown_202F222 = 0;
EWRAM_DATA s32 gUnknown_202F224 = 0;
EWRAM_DATA s32 gMetronomeCalledArrayId = 0;

void UseMoveAgainstTargets(Entity **targetsArray, Entity *attacker, Move *move, s32 itemId, bool32 isLinkedMove)
{
    s32 i = 0;
    u16 moveId;
    Entity *originalAttacker;
    Entity *currTargetSaved;
    Entity *currTarget;
    EntityInfo *targetInfo;
    bool32 moveHits;
    bool32 lightRodRedirect;
    bool32 moveRedirected;

    moveId = move->id;
    for (i = 0; i < MAX_MOVE_TARGETS; i++) {
        currTargetSaved = NULL; // Only for Pass Scarf
        currTarget = targetsArray[i];
        moveHits = TRUE;
        lightRodRedirect = FALSE;
        moveRedirected = FALSE;
        if (currTarget == NULL)
            break;
        if (!EntityIsValid(attacker))
            break;
        if (EntityIsValid(currTarget)) {
            bool32 r4;
            bool8 moveHadEffect;

            originalAttacker = attacker;
            targetInfo = GetEntInfo(currTarget);
            targetInfo->unk15A = 0;
            if (CanBeSnatched(moveId) && gDungeon->snatchPokemon != NULL) {
                Entity *snatchMon = gDungeon->snatchPokemon;
                if (GetEntityType(snatchMon) == ENTITY_MONSTER
                    && snatchMon != attacker
                    &&  GetEntInfo(snatchMon)->unk98 == gDungeon->unk17B3C
                    && targetInfo->unkFF == 0)
                {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FCD28); // The move was snatched.
                    currTarget = snatchMon;
                }
            }
            else if (GetMoveTypeForMonster(attacker, move) == TYPE_ELECTRIC && gDungeon->lightningRodPokemon != NULL) {
                Entity *lightRodMon = gDungeon->lightningRodPokemon;
                if (GetEntityType(lightRodMon) == ENTITY_MONSTER) {
                    EntityInfo *lightRodInfo = GetEntInfo(lightRodMon);
                    if (lightRodInfo->unk98 == gDungeon->unk17B38
                        && GetTreatmentBetweenMonsters(lightRodMon, attacker, TRUE, FALSE) == 1
                        && ((targetInfo->unkFF == 0 && lightRodInfo->unkFF == 0) || currTarget == lightRodMon))
                    {
                        sub_8042930(lightRodMon);
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FCD0C); // A Lightningrod took the move
                        currTarget = lightRodMon;
                        lightRodRedirect = TRUE;
                    }
                }
            }
            else if (HasHeldItem(currTarget, ITEM_PASS_SCARF)) {
                if (!CannotAttack(currTarget, FALSE)
                    && (GetMoveTargetAndRangeForPokemon(attacker, move, FALSE) & 0xF0) == 0
                    && FixedPointToInt(targetInfo->belly) >= gPassScarfBellyDownValue
                    && targetInfo->unkFF == 0)
                {
                    s32 direction1 = targetInfo->action.direction;
                    s32 direction2 = targetInfo->action.direction;
                    if (IsBossFight()) {
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDD88); // A mysterious force prevents moves from being passed off!
                    }
                    else {
                        s32 j;
                        Entity *tileEntity;

                        for (j = 0; j < 8; j++) {
                            direction2++;
                            direction2 &= DIRECTION_MASK;
                            tileEntity = GetTile(currTarget->pos.x + gAdjacentTileOffsets[direction2].x, currTarget->pos.y + gAdjacentTileOffsets[direction2].y)->monster;
                            if (EntityIsValid(tileEntity) && GetEntityType(tileEntity) == ENTITY_MONSTER) {
                                if (sub_8045888(currTarget)) {
                                    s32 k;
                                    for (k = 0; k < 24; k++) {
                                        sub_806CE68(currTarget, direction1);
                                        sub_803E708(2, 0x43);
                                        direction1++;
                                        direction1 &= DIRECTION_MASK;
                                    }
                                    while (direction1 != direction2) {
                                        sub_806CE68(currTarget, direction1);
                                        sub_803E708(2, 0x43);
                                        direction1++;
                                        direction1 &= DIRECTION_MASK;
                                    }
                                    sub_806CE68(currTarget, direction1);
                                    sub_803E708(2, 0x43);
                                }
                                targetInfo->belly = FixedPoint_Subtract(targetInfo->belly, IntToFixedPoint(gPassScarfBellyDownValue));
                                if (move->id == MOVE_REGULAR_ATTACK) {
                                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDDA8); // Attack was passed off
                                }
                                else {
                                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDD20); // Move was passed off
                                }
                                currTargetSaved = currTarget;
                                currTarget = tileEntity;
                                break;
                            }
                        }
                        if (j == 8) {
                            if (move->id == MOVE_REGULAR_ATTACK) {
                                TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDDAC); // There's no one to pass off to!
                            }
                            else {
                                TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDD48); //There's no one to pass off to!
                            }
                        }
                    }
                }
            }

            gUnknown_202F208++;
            gUnknown_202F20C++;
            targetInfo = GetEntInfo(currTarget); // currTarget could've been changed, hence info pointers needs to be reloaded
            targetInfo->unk15A = 0;
            if (targetInfo->isNotTeamMember) {
                targetInfo->targetPos = attacker->pos;
            }
            sub_806A1E8(currTarget);
            TrySendImmobilizeSleepEndMsg(attacker, currTarget);
            r4 = FALSE;
            if (!MoveMatchesBideClassStatus(attacker, move)) {
                r4 = (MoveRequiresCharging(attacker, move->id) != 0);
            }

            if (!lightRodRedirect) {
                if (targetInfo->reflectClassStatus.status == STATUS_MAGIC_COAT) {
                    if (IsReflectedByMagicCoat(moveId) && sub_8055988(attacker, currTarget)) {
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FC52C); // The target~27s Magic Coat bounced it back!
                        sub_8041B48(currTarget);
                        sub_80559DC(currTarget, attacker);
                        currTarget = attacker;
                        targetInfo = GetEntInfo(attacker);
                        targetInfo->unk15A = 0;
                        moveRedirected = TRUE;
                    }
                }
                else if (targetInfo->reflectClassStatus.status == STATUS_MIRROR_MOVE) {
                    s32 target = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
                    if (moveId != MOVE_REGULAR_ATTACK
                        && moveId != MOVE_PROJECTILE
                        && !r4
                        && ((target & 0xF) == 0 || (target & 0xF) == 4 || (target & 0xF) == 5 || (target & 0xF) == 2)
                        && sub_8055988(attacker, currTarget))
                    {
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FC558); // The target~27s Mirror Move returned it!
                        sub_8041BA8(currTarget);
                        sub_80559DC(currTarget, attacker);
                        currTarget = attacker;
                        targetInfo = GetEntInfo(attacker);
                        targetInfo->unk15A = 0;
                        moveRedirected = TRUE;
                    }
                }
            }
            if (!lightRodRedirect) {
                if (targetInfo->reflectClassStatus.status == STATUS_PROTECT) {
                    s16 targetFlags = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
                    s32 targetFlagsAnd = targetFlags & 0xF;
                    if ((targetFlagsAnd == 0 || targetFlagsAnd == 4 || targetFlagsAnd == 5 || targetFlagsAnd == 2) && !r4) {
                        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], currTarget, 0);
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FC574); // protected itself!
                        moveHits = FALSE;
                    }
                }
            }

            if (sub_80571F0(currTarget, move)) {
                moveHits = FALSE;
            }

            if (moveHits) {
                if (AbilityIsActive(currTarget, ABILITY_SOUNDPROOF) && IsSoundMove(move)) {
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], currTarget, 0);
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_8100524); // Soundproof suppressed the sound move!
                    moveHits = FALSE;
                }
            }
            if (moveHits) {
                bool8 selfAlwaysHits = (moveRedirected == FALSE);
                if (move->id == MOVE_ENDURE || move->id == MOVE_DETECT || move->id == MOVE_PROTECT) {
                    selfAlwaysHits = FALSE;
                }
                if (!AccuracyCalc(attacker, currTarget, move, ACCURACY_1, selfAlwaysHits)) {
                    moveHits = FALSE;
                }
            }

            if (moveHits && lightRodRedirect) {
                moveHits = FALSE;
            }

            if (sub_8045888(currTarget)) {
                sub_803E708(4, 0x4A);
                sub_8041168(attacker, currTarget, move, NULL);
            }

            if (!moveHits) {
                if (GetEntInfo(attacker)->isTeamLeader) {
                    sub_80421C0(attacker, 0x156);
                }
                else {
                    sub_80421C0(attacker, 0x157);
                }
                SetMessageArgument_2(gFormatBuffer_Monsters[1], GetEntInfo(currTarget), 0);
                // Interesting that these 3 strings are the same. Curious if that's the case in Blue/Europe versions.
                if (attacker == currTarget) {
                    TryDisplayDungeonLoggableMessage3(attacker, attacker, gUnknown_80F9380); // The move missed
                }
                else if (GetTreatmentBetweenMonsters(attacker, currTarget, TRUE, FALSE) == 0) {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80F9384); // The move missed
                }
                else if (lightRodRedirect) {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80F93A4); // The move missed
                }
                else {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80F9364); // is unaffected!
                }

                if (sub_8045888(currTarget)) {
                    sub_803ED30(9999, currTarget, 1, -1);
                }

                switch (moveId) {
                    case MOVE_HI_JUMP_KICK:
                        HiJumpKickMoveAction(attacker, currTarget, move, itemId, 1);
                        break;
                    case MOVE_JUMP_KICK:
                        JumpKickMoveAction(attacker, currTarget, move, itemId, 1);
                        break;
                }

                if (sub_8044B28())
                    break; // breaks out of the loop
            }
            else {
                s32 expMultiplierBeforeMove = targetInfo->expMultiplier;
                if (targetInfo->isNotTeamMember) {
                    if (move->id != MOVE_REGULAR_ATTACK && itemId == 0 && expMultiplierBeforeMove == EXP_HALVED) {
                        targetInfo->expMultiplier = EXP_REGULAR;
                    }
                    if (isLinkedMove == TRUE) {
                        targetInfo->expMultiplier = EXP_BOOSTED;
                    }
                }

                if (targetInfo->unk164 == 0xFF && sub_80717A4(currTarget, MOVE_SLEEP_TALK)) {
                    targetInfo->unk164 = GetDirectionTowardsPosition(&currTarget->pos, &attacker->pos);
                }
                if (targetInfo->unk165 == 0xFF && sub_80717A4(currTarget, MOVE_SNORE)) {
                    targetInfo->unk165 = GetDirectionTowardsPosition(&currTarget->pos, &attacker->pos);
                }

                if (AbilityIsActive(currTarget, ABILITY_PRESSURE)
                    && GetTreatmentBetweenMonsters(attacker, currTarget, TRUE, FALSE) == 1
                    && move->id != MOVE_REGULAR_ATTACK
                    && move->id != MOVE_STRUGGLE
                    && itemId == 0
                    && move->PP != 0)
                {
                    if (!(move->moveFlags2 & MOVE_FLAG2_x10)) {
                        sub_8042950(attacker);
                    }
                    move->moveFlags2 |= MOVE_FLAG2_x10;
                }

                if ((GetMoveTargetAndRangeForPokemon(attacker, move, FALSE) & 0xF) == 0) {
                    SetShopkeeperAggression(attacker, currTarget);
                }
                targetInfo->unk158 = 1;

                // They really must've had a soft spot for all these giant switches
                switch (moveId) {
                    case MOVE_THRASH:
                    case MOVE_CUT:
                    case MOVE_ROCK_THROW:
                    case MOVE_DOUBLESLAP:
                    case MOVE_SHADOW_PUNCH:
                    case MOVE_EXTREMESPEED:
                    case MOVE_SKY_UPPERCUT:
                    case MOVE_SWIFT:
                    case MOVE_TACKLE:
                    case MOVE_WATERFALL:
                    case MOVE_SLAM:
                    case MOVE_BULLET_SEED:
                    case MOVE_EGG_BOMB:
                    case MOVE_FAINT_ATTACK:
                    case MOVE_BARRAGE:
                    case MOVE_PECK:
                    case MOVE_ARM_THRUST:
                    case MOVE_HORN_ATTACK:
                    case MOVE_WING_ATTACK:
                    case MOVE_AERIAL_ACE:
                    case MOVE_ICICLE_SPEAR:
                    case MOVE_VINE_WHIP:
                    case MOVE_SHOCK_WAVE:
                    case MOVE_QUICK_ATTACK:
                    case MOVE_SPIKE_CANNON:
                    case MOVE_DRAGON_CLAW:
                    case MOVE_DRILL_PECK:
                    case MOVE_DOUBLE_KICK:
                    case MOVE_HYDRO_PUMP:
                    case MOVE_HYPER_VOICE:
                    case MOVE_VICEGRIP:
                    case MOVE_POUND:
                    case MOVE_SCRATCH:
                    case MOVE_BONE_RUSH:
                    case MOVE_BONEMERANG:
                    case MOVE_MAGICAL_LEAF:
                    case MOVE_MACH_PUNCH:
                    case MOVE_PIN_MISSILE:
                    case MOVE_WATER_GUN:
                    case MOVE_FURY_ATTACK:
                    case MOVE_FURY_SWIPES:
                    case MOVE_MEGA_KICK:
                    case MOVE_MEGA_PUNCH:
                    case MOVE_MEGAHORN:
                    case MOVE_FURY_CUTTER:
                    case MOVE_COMET_PUNCH:
                    case MOVE_ROCK_BLAST:
                    case MOVE_AEROBLAST:
                    case MOVE_WIDE_SLASH:
                    case MOVE_SPIN_SLASH:
                    case MOVE_BLOOP_SLASH:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, IntToF248_2(1), itemId) != 0);
                        break;
                    case MOVE_REGULAR_ATTACK:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, IntToF248_2(0.5), itemId) != 0);
                        break;
                    case MOVE_NOTHING:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, IntToF248_2(0), itemId) != 0);
                        break;
                    case MOVE_EARTHQUAKE:
                        moveHadEffect = EarthquakeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_GUST:
                        moveHadEffect = GustMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_STRUGGLE:
                        moveHadEffect = StruggleMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FLAME_WHEEL:
                        moveHadEffect = FlameWheelMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FLAMETHROWER:
                    case MOVE_FIRE_BLAST:
                    case MOVE_HEAT_WAVE:
                    case MOVE_EMBER:
                    case MOVE_FIRE_PUNCH:
                        moveHadEffect = BasicFireMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_POWDER_SNOW:
                    case MOVE_BLIZZARD:
                    case MOVE_ICE_PUNCH:
                    case MOVE_ICE_BEAM:
                        moveHadEffect = BasicIceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FRENZY_PLANT:
                    case MOVE_HYDRO_CANNON:
                    case MOVE_HYPER_BEAM:
                        moveHadEffect = sub_805A568(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FOCUS_ENERGY:
                        moveHadEffect = FocusEnergyMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_AIR_CUTTER:
                    case MOVE_KARATE_CHOP:
                    case MOVE_SLASH:
                    case MOVE_CRABHAMMER:
                    case MOVE_CROSS_CHOP:
                    case MOVE_RAZOR_LEAF:
                    case MOVE_LEAF_BLADE:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, IntToF248_2(1), itemId) != 0);
                        break;
                    case MOVE_FISSURE:
                        moveHadEffect = FissureMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SHEER_COLD:
                    case MOVE_GUILLOTINE:
                        moveHadEffect = sub_80595EC(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ONE_SHOT:
                        moveHadEffect = OneShotOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CLAMP:
                    case MOVE_BIND:
                    case MOVE_SAND_TOMB:
                    case MOVE_FIRE_SPIN:
                        moveHadEffect = sub_805B17C(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WHIRLPOOL:
                        moveHadEffect = WhirlpoolMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SURF:
                        moveHadEffect = SurfMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SPIDER_WEB:
                    case MOVE_MEAN_LOOK:
                        moveHadEffect = sub_805889C(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_POISON_STING:
                    case MOVE_SLUDGE:
                    case MOVE_SLUDGE_BOMB:
                        moveHadEffect = PoisonStingMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PSYCHIC:
                        moveHadEffect = sub_8058C98(attacker, currTarget, move, gUnknown_8106A50, itemId);
                        break;
                    case MOVE_ACID:
                        moveHadEffect = sub_8058C98(attacker, currTarget, move, gUnknown_8106A4C, itemId);
                        break;
                    case MOVE_METAL_CLAW:
                        moveHadEffect = MetalClawMoveAction(attacker, currTarget, move, gUnknown_8106A4C, itemId);
                        break;
                    case MOVE_STEEL_WING:
                        moveHadEffect = SteelWingMoveAction(attacker, currTarget, move, gUnknown_8106A4C, itemId);
                        break;
                    case MOVE_POISON_TAIL:
                        moveHadEffect = PoisonTailMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TWISTER:
                        moveHadEffect = TwisterMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CONSTRICT:
                    case MOVE_BUBBLEBEAM:
                        moveHadEffect = sub_8058580(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SILVER_WIND:
                    case MOVE_ANCIENTPOWER:
                        moveHadEffect = AncientPowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PSYBEAM:
                    case MOVE_SIGNAL_BEAM:
                    case MOVE_CONFUSION:
                        moveHadEffect = sub_8058C00(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MIST_BALL:
                        moveHadEffect = MistBallMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_LUSTER_PURGE:
                        moveHadEffect = LusterPurgeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CRUSH_CLAW:
                        moveHadEffect = CrushClawMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SMOG:
                        moveHadEffect = SmogMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SACRED_FIRE:
                        moveHadEffect = SacredFireMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_THUNDERSHOCK:
                        moveHadEffect = ThundershockMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_LICK:
                    case MOVE_SPARK:
                    case MOVE_BODY_SLAM:
                    case MOVE_DRAGONBREATH:
                        moveHadEffect = LickMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_EXTRASENSORY:
                    case MOVE_HYPER_FANG:
                    case MOVE_BONE_CLUB:
                        moveHadEffect = ExtrasensoryMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BITE:
                    case MOVE_NEEDLE_ARM:
                    case MOVE_STOMP:
                    case MOVE_ROLLING_KICK:
                        moveHadEffect = BiteMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HEADBUTT:
                        moveHadEffect = HeadbuttMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ROCK_SLIDE:
                    case MOVE_ASTONISH:
                        moveHadEffect = RockSlideMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CRUNCH:
                    case MOVE_SHADOW_BALL:
                        moveHadEffect = ShadowBallMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DIZZY_PUNCH:
                    case MOVE_WATER_PULSE:
                        moveHadEffect = sub_805AC90(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRI_ATTACK:
                        moveHadEffect = TriAttackMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_METEOR_MASH:
                        moveHadEffect = MeteorMashMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BLAZE_KICK:
                        moveHadEffect = BlazeKickMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ATTRACT:
                        moveHadEffect = AttractMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DISABLE:
                        moveHadEffect = DisableMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FAKE_OUT:
                        moveHadEffect = FakeOutMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SONICBOOM:
                        moveHadEffect = SonicboomMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DRAGON_RAGE:
                        moveHadEffect = DragonRageMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_STUN_SPORE:
                        moveHadEffect = StunSporeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_THUNDER:
                    case MOVE_THUNDERPUNCH:
                        moveHadEffect = ThunderMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_LOVELY_KISS:
                    case MOVE_SING:
                    case MOVE_SPORE:
                    case MOVE_GRASSWHISTLE:
                    case MOVE_HYPNOSIS:
                    case MOVE_SLEEP_POWDER:
                        moveHadEffect = BasicSleepMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_YAWN:
                        moveHadEffect = YawnMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_THUNDERBOLT:
                        moveHadEffect = ThunderboltMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BLOCK:
                        moveHadEffect = BlockMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HORN_DRILL:
                        moveHadEffect = HornDrillMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CONFUSE_RAY:
                    case MOVE_SUPERSONIC:
                    case MOVE_SWEET_KISS:
                    case MOVE_TEETER_DANCE:
                    case MOVE_TOTTER:
                        moveHadEffect = SupersonicMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_POISON_GAS:
                    case MOVE_POISONPOWDER:
                        moveHadEffect = PoisonGasMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_THUNDER_WAVE:
                        moveHadEffect = ThunderWaveMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_GLARE:
                        moveHadEffect = GlareMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ZAP_CANNON:
                        moveHadEffect = ZapCannonMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SUPERPOWER:
                        moveHadEffect = SuperpowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ROCK_TOMB:
                    case MOVE_ICY_WIND:
                    case MOVE_MUD_SHOT:
                        moveHadEffect = RockTombMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DYNAMICPUNCH:
                        moveHadEffect = DynamicPunchMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FAKE_TEARS:
                        moveHadEffect = FakeTearsMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WHIRLWIND:
                    case MOVE_ROAR:
                    case MOVE_BLOWBACK:
                        moveHadEffect = RoarMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PAIN_SPLIT:
                        moveHadEffect = PainSplitMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TAIL_GLOW:
                        moveHadEffect = TailGlowMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MINIMIZE:
                        moveHadEffect = MinimizeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DRAGON_DANCE:
                        moveHadEffect = DragonDanceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BULK_UP:
                        moveHadEffect = BulkUpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SHARPEN:
                    case MOVE_HOWL:
                    case MOVE_MEDITATE:
                        moveHadEffect = BasicRaiseAttackMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_RAGE:
                        moveHadEffect = RageMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SWORDS_DANCE:
                        moveHadEffect = SwordsDanceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CALM_MIND:
                        moveHadEffect = CalmMindMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_GROWTH:
                        moveHadEffect = GrowthMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_AMNESIA:
                        moveHadEffect = AmnesiaMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DEFENSE_CURL:
                        moveHadEffect = DefenseCurlMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_IRON_DEFENSE:
                    case MOVE_ACID_ARMOR:
                    case MOVE_BARRIER:
                        moveHadEffect = sub_8059CD8(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_COSMIC_POWER:
                        moveHadEffect = CosmicPowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MUDDY_WATER:
                        moveHadEffect = MuddyWaterMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_OCTAZOOKA:
                        moveHadEffect = OctazookaMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_AURORA_BEAM:
                        moveHadEffect = AuroraBeamMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PSYCHO_BOOST:
                        moveHadEffect = PsychoBoostMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SCARY_FACE:
                    case MOVE_COTTON_SPORE:
                        moveHadEffect = ScaryFaceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_GROWL:
                        moveHadEffect = GrowlMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FEATHERDANCE:
                        moveHadEffect = FeatherDanceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SCREECH:
                        moveHadEffect = ScreechMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SEISMIC_TOSS:
                    case MOVE_NIGHT_SHADE:
                        moveHadEffect = sub_8059A2C(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_GIGA_DRAIN:
                    case MOVE_LEECH_LIFE:
                    case MOVE_MEGA_DRAIN:
                        moveHadEffect = GigaDrainMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DOUBLE_EDGE:
                        moveHadEffect = DoubleEdgeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SUBMISSION:
                    case MOVE_TAKE_DOWN:
                    case MOVE_VOLT_TACKLE:
                        moveHadEffect = sub_8058E5C(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ABSORB:
                        moveHadEffect = AbsorbMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SWAGGER:
                        moveHadEffect = SwaggerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRIPLE_KICK:
                        moveHadEffect = TripleKickMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TWINEEDLE:
                        moveHadEffect = TwineedleMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SOLARBEAM:
                        moveHadEffect = SolarBeamMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SKY_ATTACK:
                        moveHadEffect = SkyAttackMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SLOW_DOWN:
                        moveHadEffect = SlowDownMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_OUTRAGE:
                    case MOVE_PETAL_DANCE:
                        moveHadEffect = OutrageMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WRAP:
                        moveHadEffect = WrapMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_UPROAR:
                        moveHadEffect = UproarMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_POISON_FANG:
                        moveHadEffect = PoisonFangMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PRESENT:
                        moveHadEffect = PresentMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_REFLECT:
                        moveHadEffect = ReflectMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SANDSTORM:
                        moveHadEffect = SandstormMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SAFEGUARD:
                        moveHadEffect = SafeguardMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MIST:
                        moveHadEffect = MistMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_LIGHT_SCREEN:
                        moveHadEffect = LightScreenMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ICE_BALL:
                    case MOVE_ROLLOUT:
                        moveHadEffect = sub_805768C(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MEMENTO:
                        moveHadEffect = MementoMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SOFTBOILED:
                    case MOVE_MILK_DRINK:
                        moveHadEffect = sub_80599EC(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SYNTHESIS:
                        moveHadEffect = SynthesisMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MOONLIGHT:
                        moveHadEffect = MoonlightMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_REST:
                        moveHadEffect = RestMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_RECOVER:
                    case MOVE_SLACK_OFF:
                        moveHadEffect = sub_8058EE0(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SCAN:
                        moveHadEffect = ScannerOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRICK:
                        moveHadEffect = TrickMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TAKEAWAY:
                        moveHadEffect = ThiefAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_THIEF:
                    case MOVE_COVET:
                        moveHadEffect = ThiefMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_AGILITY:
                    case MOVE_SPEED_BOOST:
                        moveHadEffect = AgilityMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PURSUIT:
                    case MOVE_COUNTER:
                        moveHadEffect = CounterMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BIDE:
                    case MOVE_REVENGE:
                        moveHadEffect = BideMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BIDE_2:
                        moveHadEffect = Bide2MoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRAPPER:
                        moveHadEffect = TrapperOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SLEEP_TALK:
                        moveHadEffect = sub_805A450(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CURSE:
                        moveHadEffect = CurseMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HI_JUMP_KICK:
                        moveHadEffect = HiJumpKickMoveAction(attacker, currTarget, move, itemId, 0);
                        break;
                    case MOVE_BLAST_BURN:
                        moveHadEffect = BlastBurnMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HIDDEN_POWER:
                        moveHadEffect = HiddenPowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_RAZOR_WIND:
                        moveHadEffect = RazorWindMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FOCUS_PUNCH:
                        moveHadEffect = FocusPunchMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MAGIC_COAT:
                        moveHadEffect = MagicCoatMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_NIGHTMARE:
                        moveHadEffect = NightmareMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MORNING_SUN:
                        moveHadEffect = MorningSunMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_VACUUM_CUT:
                        moveHadEffect = VacuumCutMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MUD_SPORT:
                    case MOVE_WATER_SPORT:
                        moveHadEffect = MudWaterSportMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_IRON_TAIL:
                        moveHadEffect = IronTailMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TAIL_WHIP:
                    case MOVE_LEER:
                        moveHadEffect = LeerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WILL_O_WISP:
                        moveHadEffect = WillOWispMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_INGRAIN:
                        moveHadEffect = IngrainMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PSYWAVE:
                        moveHadEffect = PsywaveMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_LEECH_SEED:
                        moveHadEffect = LeechSeedMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SPIKES:
                        moveHadEffect = SpikesMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_AROMATHERAPY:
                    case MOVE_HEAL_BELL:
                    case MOVE_REFRESH:
                        moveHadEffect = sub_80578EC(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HAZE:
                        moveHadEffect = HazeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_POWER_EARS:
                        moveHadEffect = RadarOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SIESTA:
                        moveHadEffect = SlumberOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SMELLINGSALT:
                        moveHadEffect = SmellingSaltMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MAGNITUDE:
                        moveHadEffect = MagnitudeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SKULL_BASH:
                        moveHadEffect = SkullBashMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WISH:
                        moveHadEffect = WishMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FLATTER:
                        moveHadEffect = FlatterMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MUD_SLAP:
                        moveHadEffect = MudSlapMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SAND_ATTACK:
                    case MOVE_KINESIS:
                    case MOVE_FLASH:
                        moveHadEffect = sub_8059528(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_OVERHEAT:
                        moveHadEffect = OverheatMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TOXIC:
                        moveHadEffect = ToxicMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_METAL_SOUND:
                        moveHadEffect = MetalSoundMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TORMENT:
                        moveHadEffect = TormentMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SUPER_FANG:
                        moveHadEffect = SuperFangMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FALSE_SWIPE:
                        moveHadEffect = FalseSwipeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TWO_EDGE:
                        moveHadEffect = TwoEdgeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ENDEAVOR:
                        moveHadEffect = EndeavorMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BATON_PASS:
                    case MOVE_SWITCHER:
                        moveHadEffect = SwitcherOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DREAM_EATER:
                        moveHadEffect = DreamEaterMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SEARCHLIGHT:
                        moveHadEffect = LuminousOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FILL_IN:
                        moveHadEffect = FillInOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TELEPORT:
                    case MOVE_WARP:
                        moveHadEffect = WarpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DROUGHT:
                        moveHadEffect = DroughtOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SEE_STAIRS:
                        moveHadEffect = StairsOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BRICK_BREAK:
                        moveHadEffect = BrickBreakMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HARDEN:
                    case MOVE_WITHDRAW:
                        moveHadEffect = BasicRaiseDefenseMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MIND_READER:
                    case MOVE_LOCK_ON:
                        moveHadEffect = SureShotMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_VITAL_THROW:
                        moveHadEffect = VitalThrowMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FLY:
                        moveHadEffect = FlyMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BOUNCE:
                        moveHadEffect = BounceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DIVE:
                        moveHadEffect = DiveMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DIG:
                        moveHadEffect = DigMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SWEET_SCENT:
                        moveHadEffect = SweetScentMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DOUBLE_TEAM:
                        moveHadEffect = DoubleTeamMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_KNOCK_OFF:
                        moveHadEffect = KnockOffMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRAP_BUSTER:
                        moveHadEffect = TrapbustOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_LONG_TOSS:
                        moveHadEffect = LongtossOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PIERCE:
                        moveHadEffect = PierceOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_GRUDGE:
                        moveHadEffect = GrudgeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PETRIFY:
                        moveHadEffect = PetrifyOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ASSIST:
                        moveHadEffect = AssistMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DOOM_DESIRE:
                    case MOVE_FUTURE_SIGHT:
                        moveHadEffect = sub_805AAD0(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SHOCKER:
                        moveHadEffect = ShockerOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FOLLOW_ME:
                    case MOVE_SUBSTITUTE:
                    case MOVE_DECOY_MAKER:
                        moveHadEffect = sub_805B314(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_JUMP_KICK:
                        moveHadEffect = JumpKickMoveAction(attacker, currTarget, move, itemId, 0);
                        break;
                    case MOVE_PROTECT:
                    case MOVE_DETECT:
                        moveHadEffect = ProtectMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TAUNT:
                        moveHadEffect = TauntMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TICKLE:
                        moveHadEffect = TickleMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_REVERSAL:
                    case MOVE_FLAIL:
                        moveHadEffect = ReversalMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SELFDESTRUCT:
                        moveHadEffect = SelfDestructMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_EXPLOSION:
                        moveHadEffect = ExplosionMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CHARGE:
                        moveHadEffect = ChargeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FACADE:
                        moveHadEffect = FacadeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_LOW_KICK:
                        moveHadEffect = LowKickMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WATER_SPOUT:
                        moveHadEffect = WaterSpoutMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ERUPTION:
                        moveHadEffect = EruptionMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SMOKESCREEN:
                        moveHadEffect = SmokescreenMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SEE_TRAP:
                        moveHadEffect = sub_805BA44(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_STOCKPILE:
                        moveHadEffect = StockpileMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SPIT_UP:
                        moveHadEffect = SpitUpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SWALLOW:
                        moveHadEffect = SwallowMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_RAIN_DANCE:
                        moveHadEffect = RainDanceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SPITE:
                        moveHadEffect = SpiteMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_INVISIFY:
                        moveHadEffect = InvisifyOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MIRROR_COAT:
                        moveHadEffect = MirrorCoatMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PERISH_SONG:
                        moveHadEffect = PerishSongMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_RAPID_SPIN:
                        moveHadEffect = RapidSpinMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_DESTINY_BOND:
                        moveHadEffect = DestinyBondMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ENCORE:
                        moveHadEffect = EncoreMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WEATHER_BALL:
                        moveHadEffect = WeatherBallMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SUNNY_DAY:
                        moveHadEffect = SunnyDayMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PAY_DAY:
                        moveHadEffect = PayDayMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ONE_ROOM:
                        moveHadEffect = OneRoomOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ENDURE:
                        moveHadEffect = EndureMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HELPING_HAND:
                        moveHadEffect = HelpingHandMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BELLY_DRUM:
                        moveHadEffect = BellyDrumMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FAMISH:
                        moveHadEffect = sub_805C288(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CHARM:
                        moveHadEffect = CharmMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BUBBLE:
                        moveHadEffect = BubbleMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_STRING_SHOT:
                        moveHadEffect = StringShotMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ROCK_SMASH:
                    case MOVE_EXCAVATE:
                        moveHadEffect = RockSmashMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRANSFORM:
                        moveHadEffect = TransformMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HAIL:
                        moveHadEffect = HailMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MOBILE:
                        moveHadEffect = MobileOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ODOR_SLEUTH:
                    case MOVE_FORESIGHT:
                        moveHadEffect = ExposeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SPLASH:
                        moveHadEffect = SplashMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRANSFER:
                        moveHadEffect = TransferOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_STAY_AWAY:
                        moveHadEffect = StayawayOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_BEAT_UP:
                        moveHadEffect = BeatUpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_REBOUND:
                        moveHadEffect = ReboundOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_IMPRISON:
                    case MOVE_OBSERVER:
                        moveHadEffect = ObserverOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WILD_CALL:
                        moveHadEffect = RollcallOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_REVIVER:
                        moveHadEffect = ReviverOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ESCAPE:
                        moveHadEffect = EscapeOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SECRET_POWER:
                        moveHadEffect = SecretPowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_NATURE_POWER:
                        moveHadEffect = NaturePowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ITEMIZE:
                        moveHadEffect = ItemizeOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SKETCH:
                        moveHadEffect = SketchMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MIRROR_MOVE:
                        moveHadEffect = MirrorMoveMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ROLE_PLAY:
                        moveHadEffect = RolePlayMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SKILL_SWAP:
                        moveHadEffect = SkillSwapMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CONVERSION:
                        moveHadEffect = ConversionMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CLEANSE:
                        moveHadEffect = CleanseOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_RETURN:
                        moveHadEffect = ReturnMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SNATCH:
                        moveHadEffect = SnatchMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CAMOUFLAGE:
                        moveHadEffect = HandleColorChange(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FRUSTRATION:
                        moveHadEffect = FrustrationMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PSYCH_UP:
                        moveHadEffect = PsychUpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SNORE:
                        moveHadEffect = SnoreMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_RECYCLE:
                        moveHadEffect = RecycleMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_NO_MOVE:
                        moveHadEffect = SilenceOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_METRONOME:
                        moveHadEffect = MetronomeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_HP_GAUGE:
                        moveHadEffect = IdentifyOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_CONVERSION_2:
                        moveHadEffect = Conversion2MoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_POUNCE:
                        moveHadEffect = PounceOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRAWL:
                        moveHadEffect = TrawlOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_MIMIC:
                        moveHadEffect = MimicMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_STRENGTH:
                    case MOVE_HURL:
                        moveHadEffect = HurlOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_ECHO:
                        moveHadEffect = sub_805C208(attacker, currTarget, move, itemId);
                        break;
                    default:
                        moveHadEffect = FALSE;
                        break;
                }

                if (sub_8044B28()) {
                    break;
                }

                if (EntityIsValid(currTargetSaved)) {
                    sub_806CE68(currTargetSaved, GetEntInfo(currTargetSaved)->action.direction);
                }

                if (!moveHadEffect) {
                    if (EntityIsValid(attacker) && EntityIsValid(currTarget) && targetInfo->isNotTeamMember) {
                        targetInfo->expMultiplier = expMultiplierBeforeMove;
                    }
                }
                else {
                    if (MoveCausesPaused(move) && RollSecondaryEffect(attacker, 0)) {
                        gUnknown_202F222 = 1;
                    }
                }

                if (EntityIsValid(currTarget)) {
                    targetInfo->unk158 = 1;
                }

                if (moveId != MOVE_SKILL_SWAP) {
                    TriggerTargetAbilityEffect(attacker);
                    sub_8069F9C(attacker, currTarget, move);
                    sub_806A120(attacker, currTarget, move);
                }
            }

            attacker = originalAttacker;
        }
    }

    if (!sub_8044B28()) {
        if (EntityIsValid(attacker) && GetEntInfo(attacker)->unk154 != 0) {
            GetEntInfo(attacker)->unk154 = 0;
            WarpTarget(attacker, attacker, 0, NULL);
        }
        if (EntityIsValid(attacker) && GetEntInfo(attacker)->unk155 != 0) {
            GetEntInfo(attacker)->unk155 = 0;
            LowerAttackStageTarget(attacker, attacker, gUnknown_8106A50, 2, 0, FALSE);
        }
    }
}

bool32 HandleRegularDamagingMove(Entity *attacker, Entity *target, Move *move, s32 itemId)
{
    return (HandleDamagingMove(attacker, target, move, IntToF248_2(1), itemId) != 0);
}

s32 HandleDamagingMove(Entity *attacker, Entity *target, Move *move, s24_8 modifier, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s16 unk;
    s32 moveType = GetMoveTypeForMonster(attacker, move);
    s32 movePower = GetMovePower(attacker, move);
    s32 critChance = GetMoveCritChance(move);

    CalcDamage(attacker, target, moveType, movePower, critChance, &dmgStruct, modifier, move->id, 1);
    unk = sub_8057600(move, itemId);
    return TryHitTarget(attacker, target, move, &dmgStruct, unk);
}

s32 sub_80556BC(Entity *attacker, Entity *target, u8 moveType, Move *move, s24_8 modifier, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s16 unk;
    s32 movePower = GetMovePower(attacker, move);
    s32 critChance = GetMoveCritChance(move);

    CalcDamage(attacker, target, moveType, movePower, critChance, &dmgStruct, modifier, move->id, 1);
    unk = sub_8057600(move, itemId);
    return TryHitTarget(attacker, target, move, &dmgStruct, unk);
}

static s32 TryHitTarget(Entity *attacker, Entity *target, Move *move, struct DamageStruct *dmgStruct, s16 unk_)
{
    s32 unk = unk_; // It's happening again...
    if (AccuracyCalc(attacker, target, move, ACCURACY_2, TRUE)) { // Move hits
        bool32 isFalseSwipe = (move->id == MOVE_FALSE_SWIPE);

        if (AbilityIsActive(target, ABILITY_ILLUMINATE)) {
            gDungeon->unk644.unk1E = 999;
            gDungeon->unk17B34 = target;
            gDungeon->unk17B40 = target->spawnGenID;
        }

        HandleDealingDamage(attacker, target, dmgStruct, isFalseSwipe, TRUE, unk, TRUE, 0);
    }
    else {
        SetMessageArgument_2(gFormatBuffer_Monsters[1], GetEntInfo(target), 0);
        if (sub_8045888(attacker) && sub_8045888(target)) {
            sub_803ED30(9999, target, 1, -1);
            TryDisplayDungeonLoggableMessage4(attacker, target, gUnknown_80F9688); // It took no damage!
            sub_8042238(attacker, target);
        }
        else {
            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9688); // It took no damage!
        }
        dmgStruct->tookNoDamage = TRUE;
    }

    if (dmgStruct->tookNoDamage) {
        return 0;
    }

    if (EntityIsValid(target)) {
        GetEntInfo(target)->unk15A = 1;
    }

    return dmgStruct->dmg;
}

s32 sub_8055864(Entity *attacker, Entity *target, Move *move, s32 param_4, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s32 moveType = GetMoveTypeForMonster(attacker, move);

    sub_806F2BC(attacker, target, moveType, param_4, &dmgStruct);
    HandleDealingDamage(attacker, target, &dmgStruct, FALSE, TRUE, sub_8057600(move, itemId), TRUE, 0);
    if (dmgStruct.tookNoDamage) {
        return 0;
    }

    if (EntityIsValid(target)) {
        GetEntInfo(target)->unk15A = 1;
    }
    return dmgStruct.dmg;
}

// This unused function returns FALSE if target's typing makes it immune to move's type.
static UNUSED bool32 TargetNotImmuneTo(Move *move, Entity *target)
{
    s32 i;
    s32 dmg = 1;
    bool32 ghostImmunity = FALSE;
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 moveType = GetMoveType(move);

    if (moveType == TYPE_NORMAL || moveType == TYPE_FIGHTING) {
        ghostImmunity = TRUE;
    }

    for (i = 0; i < 2; i++) {
        s32 multiplier[4] = {0, 1, 1, 1}; // EFFECTIVENESS_IMMUNE is 0, others are 1
        s32 effectiveness;

        if (ghostImmunity && targetInfo->types[i] == TYPE_GHOST && !targetInfo->exposed) {
            effectiveness = EFFECTIVENESS_IMMUNE;
        }
        else {
            effectiveness = gTypeEffectivenessChart[moveType][targetInfo->types[i]];
        }

        dmg *= multiplier[effectiveness];
        if (dmg == 0)
            break;
    }

    return (dmg != 0);
}

bool8 sub_8055988(Entity *r2, Entity *r4)
{
    if (r2 != r4
        && abs(r2->pos.x - r4->pos.x) <= 1 && abs(r2->pos.y - r4->pos.y) <= 1
        && CanAttackInDirection(r4, GetDirectionTowardsPosition(&r4->pos, &r2->pos)))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_80559DC(Entity *entity1, Entity *entity2)
{
    EntityInfo *entInfo = GetEntInfo(entity1);
    s32 direction = GetDirectionTowardsPosition(&entity1->pos, &entity2->pos);

    entInfo->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(entity1, direction);
}
