#ifndef GUARD_DUNGEON_BATTLE_DATA_H
#define GUARD_DUNGEON_BATTLE_DATA_H

#include "math.h"
#include "constants/weather.h"
#include "constants/type.h"

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
extern const s16 gUnknownDungeonChance;
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

#define BELLY_GO_DOWN_VALUES_COUNT 20
extern const s48_16 gBellyGoDownValues[BELLY_GO_DOWN_VALUES_COUNT];

#define WARP_SCARF_ACTIVATION_CHANCES_COUNT 20
extern const s16 gWarpScarfActivationChances[WARP_SCARF_ACTIVATION_CHANCES_COUNT];

#endif
