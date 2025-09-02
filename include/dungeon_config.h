#ifndef GUARD_DUNGEON_CONFIG_H
#define GUARD_DUNGEON_CONFIG_H

#include "math.h"
#include "constants/weather.h"
#include "constants/type.h"
#include "constants/dungeon_action.h"
#include "structs/str_dungeon.h"
#include "structs/dungeon_entity.h"
#include "structs/str_moves.h"

extern const s16 gMonsterHouseMaxItemsTraps;
extern const s16 gMonsterHouseMinMons;
extern const s16 gMonsterHouseMaxMons;
extern const s16 gUnknown_80F4DA6;
extern const s16 gUnknown_80F4DA8;
extern const s16 gUnknown_80F4DAA;
extern const s16 gUnknown_80F4DAC;
extern const s16 gCritOddsScopeLensPatsyBand;
extern const s16 gCritOddsIqAdvantageMaster;
extern const s16 gAIConfusedAttackChance;
extern const s16 gIronTailSecondaryChance;
extern const s16 gBubbleSecondaryChance;
extern const s16 gFlameWheelSecondaryChance;
extern const s16 gFireMoveBurnSecondaryChance;
extern const s16 gIceMoveFreezeSecondaryChance;
extern const s16 gPoisonStingSecondaryChance;
extern const s16 gPsychicSecondaryChance;
extern const s16 gShadowBallSecondaryChance;
extern const s16 gSmogSecondaryChance;
extern const s16 gPoisonTailSecondaryChance;
extern const s16 gTwineedleSecondaryChance;
extern const s16 gPoisonFangSecondaryChance;
extern const s16 gBounceSecondaryChance;
extern const s16 gMetalClawSecondaryChance;
extern const s16 gMeteorMashSecondaryChance;
extern const s16 gSteelWingSecondaryChance;
extern const s16 gConstrictBubblebeamSecondaryChance;
extern const s16 gAncientPowerSecondaryChance;
extern const s16 gMistBallSecondaryChance;
extern const s16 gCrushClawSecondaryChance;
extern const s16 gLusterPurgeSecondaryChance;
extern const s16 gSacredFireSecondaryChance;
extern const s16 gThundershockSecondaryChance;
extern const s16 gLickSecondaryChance;
extern const s16 gThunderSecondaryChance;
extern const s16 gThunderboltSecondaryChance;
extern const s16 gExtrasensorySecondaryChance;
extern const s16 gTwisterSecondaryChance;
extern const s16 gBiteSecondaryChance;
extern const s16 gHeadbuttSecondaryChance;
extern const s16 gFakeOutSecondaryChance;
extern const s16 gSkyAttackSecondaryChance;
extern const s16 gRockSlideSecondaryChance;
extern const s16 gMovesConfusionSecondaryChance;
extern const s16 gDizzyPunchSecondaryChance;
extern const s16 gTriAttackSecondaryChance;
extern const s16 gBlazeKickSecondaryChance;
extern const s16 gMuddyWaterAccLowerChance;
extern const s16 gOctazookaAccLowerChance;
extern const s16 gAuroraBeamAtkLowerChance;
extern const s16 gSecretPowerSecondaryEffectChance;
extern const s16 gMovesConstrictionChance;
extern const s16 gSnoreSecondaryChance;

extern const s16 gShedSkinActivateChance;
extern const s16 gGrimyTrapActivateChance;
extern const s16 gArenaTrapActivateChance;
extern const s16 gShadowTagActivateChance;
extern const s16 gMagnetPullActivateChance;
extern const s16 gStaticActivateChance;
extern const s16 gPoisonPointActivateChance;
extern const s16 gEffectSproreActivateChance;
extern const s16 gFlameBodyActivateChance;
extern const s16 gCuteCharmActivateChance;
extern const s16 gStenchActivateChance;

extern const s16 gAiRegularAttackWeights[5];

extern const s16 gFreezeTurnRange[2];
extern const s16 gBurnTurnRange[2];
extern const s16 gPoisonTurnRange[2];
extern const s16 gBadPoisonTurnRange[2];
extern const s16 gCringeTurnRange[2];
extern const s16 gSpeedRaiseTurnRange[2];
extern const s16 gSpeedLowerTurnRange[2];
extern const s16 gConfusionTurnRange[2];
extern const s16 gParalysisTurnRange[2];
extern const s16 gShadowHoldTurnRange[2];
extern const s16 gConstrictionTurnRange[2];
extern const s16 gWrapTurnRange[2];
extern const s16 gIngrainTurnRange[2];
extern const s16 gPauseTurnRange[2];
extern const s16 gSleepTurnRange[2];
extern const s16 gNightmareTurnRange[2];
extern const s16 gSleeplessTurnRange[2];
extern const s16 gReflectTurnRange[2];
extern const s16 gLightScreenTurnRange[2];
extern const s16 gSafeguardTurnRange[2];
extern const s16 gMistTurnRange[2];
extern const s16 gMagicCoatTurnRange[2];
extern const s16 gNappingTurnRange[2];
extern const s16 gCounterTurnRange[2];
extern const s16 gBideTurnRange[2];
extern const s16 gEnragedTurnRange[2];
extern const s16 gCurseTurnRange[2];
extern const s16 gSnatchTurnRange[2];
extern const s16 gMudWaterSportTurnRange[2];
extern const s16 gLeechSeedTurnRange[2];
extern const s16 gWishTurnRange[2];
extern const s16 gSureShotTurnRange[2];
extern const s16 gPetrifiedLeaderTurnRange[2];
extern const s16 gPetrifiedTurnRange[2];
extern const s16 gSetDamageTurnRange[2];
extern const s16 gFocusEnergyTurnRange[2];
extern const s16 gCowerTurnRange[2];
extern const s16 gDecoyTurnRange[2];
extern const s16 gProtectTurnRange[2];
extern const s16 gTauntTurnRange[2];
extern const s16 gWhifferTurnRange[2];
extern const s16 gObserverOrbPausedTurnRange[2];
extern const s16 gInvisibleTurnRange[2];
extern const s16 gMirrorCoatTurnRange[2];
extern const s16 gPerishSongTurnRange[2];
extern const s16 gDestinyBondTurnRange[2];
extern const s16 gEncoreTurnRange[2];
extern const s16 gEnduringTurnRange[2];
extern const s16 gTransformedTurnRange[2];
extern const s16 gInfatuatedTurnRange[2];
extern const s16 gMobileTurnRange[2];
extern const s16 gBlinkerTurnRange[2];
extern const s16 gCrossEyedTurnRange[2];
extern const s16 gEyedropsTurnRange[2];
extern const s16 gMirrorMoveTurnRange[2];
extern const s16 gMuzzledTurnRange[2];
extern const s16 gConversion2TurnRange[2];
extern const s16 gVitalThrowTurnRange[2];
extern const s16 gYawnTurnRange[2];
extern const s16 gSleepFromYawnTurnRange[2];

extern const s16 gSpeedBoostActivationFrame;

extern const s16 gBurnDmgCountdown;
extern const s16 gPoisonDmgCountdown;
extern const s16 gBadPoisonDmgCountdown;
extern const s16 gConstrictionDmgCountdown;
extern const s16 gWrapDmgCountdown;
extern const s16 gIngrainHealCountdown;
extern const s16 gCurseDmgCountdown;
extern const s16 gLeechSeedDmgCountdown;

extern const s16 gMoveWeatherDuration;
extern const s16 gGinsengPlus3BoostChance;
extern const s24_8 gSolarBeamModifier;
extern const s24_8 gSkyAttackModifier;
extern const s24_8 gRazorWindModifier;
extern const s24_8 gFocusPunchModifier;
extern const s24_8 gSkullBashModifier;
extern const s24_8 gFlyModifier;
extern const s24_8 gBounceModifier;
extern const s24_8 gDiveModifier;
extern const s24_8 gDigModifier;
extern const s24_8 gFacadeModifier;

extern const s16 gBurnDmgValue;
extern const s16 gPoisonDmgValue;
extern const s16 gConstrictionDmgValue;
extern const s16 gWrapDmgValue;
extern const s16 gNightmareDmgValue;
extern const s16 gNappingHpHealValue;
extern const s16 gSonicboomDmgValue;
extern const s16 gDragonRageDmgValue;
extern const s16 gVacuumCutDmgValue;
extern const s16 gSplashDmgValue;
extern const s16 gSpikeTrapDmgValue;
extern const s16 gChestnutTrapDmgValue;
extern const s16 gPitfallTrapDmgValue;
extern const s16 gSetDamageDmgValue;
extern const s16 gHailSandstormDmgValue;
extern const s16 gBlowAwayDmgValue;
extern const s16 gHurlOrbDmgValue;
extern const s16 gMagnitudeDmgValues[7];
extern const s16 gProjectileHitChance;
extern const s16 gBlastSeedThrownDmgValue;
extern const s16 gBlastSeedEatenDmgValue;
extern const s16 gBlastSeedThrownBossDmgValue;
extern const s16 gBlastSeedEatenBossDmgValue;
extern const s16 gUnknown_80F4FAC;
extern const s16 gUnknown_80F4FAE;
extern const s16 gIngrainHealValue;
extern const s16 gLeechSeedHealValue;
extern const s16 gOranBerryHealValue;
extern const s16 gOranBerryMaxHpRiseValue;
extern const s16 gSitrusBerryHealValue;
extern const s16 gSitrusBerryMaxHpRiseValue;
extern const s16 gLifeSeedMaxHpRiseValue;
extern const s16 gWishRegenValue;
extern const s16 gRainDishRegenValue;
extern const s16 gHealRibbonRegenValue;
extern const s16 gFamishBellyDownValue;
#define BAD_POISON_DMG_TURN_VALUES_COUNT 30
extern const s16 gBadPoisonDmgValuesByTurn[BAD_POISON_DMG_TURN_VALUES_COUNT];
extern const s16 gStenchTerrifiedTurnsNo;
extern const s16 gPassScarfBellyDownValue;
extern const s16 gFriendBowRecruitRateUpValue;
extern const s16 gSynthesisHealValueByWeather[WEATHER_COUNT];
extern const s16 gMoonlightHealValueByWeather[WEATHER_COUNT];
extern const s16 gMorningSunHealValueByWeather[WEATHER_COUNT];
extern const s16 gStickPPValue;
extern const s16 gIronThornPPValue;
extern const s16 gSilverSpikePPValue;
extern const s16 gGoldFangPPValue;
extern const s16 gCacneaSpikePPValue;
extern const s16 gCorsolaTwigPPValue;
extern const s16 gGravelerockThrownDmgValue;
extern const s16 gGeoPebbleThrownDmgValue;
extern const s24_8 gAtkStatStageMultipliers[21];
extern const s24_8 gDefStatStageMultipliers[21];
extern const s24_8 gAccEvsStatStageMultipliers[2][21];
extern const s32 gDetectBandAccuracyDebuffValue;
extern const s32 gIqQuickDodgerAccuracyDebuffValue;
extern const s24_8 gReversalModifiers[4];
extern const s24_8 gWaterSpoutModifiers[4];
extern const s24_8 gEruptionModifiers[4];
extern const s32 gStockpileHealHpValues[4];

extern const u8 gWeatherBallTypes[WEATHER_COUNT];
extern const s24_8 gWeatherBallModifiers[WEATHER_COUNT];

struct CastformWeatherData
{
    u8 type;
    s16 monsterId;
};

extern const struct CastformWeatherData gCastformByWeather[WEATHER_COUNT];

#define NUM_EFFECTIVENESS 4

#define EFFECTIVENESS_IMMUNE 0
#define EFFECTIVENESS_RESIST 1
#define EFFECTIVENESS_NEUTRAL 2
#define EFFECTIVENESS_SUPER 3

extern const s16 gTypeEffectivenessChart[NUM_TYPES][NUM_TYPES];
extern const s32 gEffectivenessChart[NUM_EFFECTIVENESS][NUM_EFFECTIVENESS];

#define RESIDUAL_DAMAGE_REGULAR 0
#define RESIDUAL_DAMAGE_BURN 1
#define RESIDUAL_DAMAGE_CONSTRICT 2
#define RESIDUAL_DAMAGE_POISON 3
#define RESIDUAL_DAMAGE_UNUSED_4 4
#define RESIDUAL_DAMAGE_WRAP 5
#define RESIDUAL_DAMAGE_COUNTERATTACK 6
#define RESIDUAL_DAMAGE_CURSE 7
#define RESIDUAL_DAMAGE_NIGHTMARE 8
#define RESIDUAL_DAMAGE_LEECH_SEED 9
#define RESIDUAL_DAMAGE_SPIKES 10
#define RESIDUAL_DAMAGE_PERISH_SONG 11
#define RESIDUAL_DAMAGE_DESTINY_BOND 12
#define RESIDUAL_DAMAGE_LIQUID_OOZE 13
#define RESIDUAL_DAMAGE_HUNGER 14
#define RESIDUAL_DAMAGE_CHESTNUT_TRAP 15
#define RESIDUAL_DAMAGE_UNUSED_16 16
#define RESIDUAL_DAMAGE_PITFALL 17
#define RESIDUAL_DAMAGE_BAD_WEATHER 18
#define RESIDUAL_DAMAGE_MOVE_FAIL 19
#define RESIDUAL_DAMAGE_RECOIL 20

#define BELLY_GO_DOWN_VALUES_COUNT 20
extern const s48_16 gBellyGoDownValues[BELLY_GO_DOWN_VALUES_COUNT];

#define EMPTY_BELLY_ALERT_YOUR_BELLYS_EMPTY 1
#define EMPTY_BELLY_ALERT_HURRY_EAT_SOMETHING 2
#define EMPTY_BELLY_ALERT_YOULL_FAINT 3

#define WARP_SCARF_ACTIVATION_CHANCES_COUNT 20
extern const s16 gWarpScarfActivationChances[WARP_SCARF_ACTIVATION_CHANCES_COUNT];

struct ReturnDmgData
{
    s16 minIq;
    s16 dmgVal;
};

extern const struct ReturnDmgData gReturnDmgData[];
extern const struct ReturnDmgData gFrustrationDmgData[];

extern const u8 gDungeonCamouflageTypes[76];

extern const s16 gDungeonMusic[76];
extern const s16 gRecruitRateByLevel[101];

extern const s16 gRayquazaConfigLevel;
extern const s16 gZapdosConfigLevel;
extern const s16 gMoltresConfigLevel;
extern const s16 gArticunoConfigLevel;
extern const s16 gGroudonConfigLevel;

extern const s16 sKecleonShopItemSpawnChances[16][3][3];

extern const bool8 gUnknown_80F58F4[NUM_DUNGEON_ACTIONS][2];

extern const u8 gSecretPowerTable[76];
extern const s16 gIqItemMasterMinWildLevel;

typedef bool8 (*MoveCallback)(Entity *pokemon, Entity *target, Move *move, s32 param_4);
struct CalledMove
{
    u16 moveID;
    MoveCallback callback;
};

#define METRONOME_AVAILABLE_CALLED_MOVES 105
extern const struct CalledMove gMetronomeCalledMoves[METRONOME_AVAILABLE_CALLED_MOVES];
extern const struct CalledMove gNaturePowerCalledMoves[];

extern const u16 gUnknown_80F5F70[UNK12A18_ARR_COUNT];
extern const s32 gUnknown_80F5FAC[76];
extern const s32 gLinkedMovesBellyGoDownValues[5];

#endif
