#include "global.h"
#include "dungeon_battle_data.h"
#include "math.h"
#include "constants/weather.h"

const s16 gFreezeTurnRange[2] = {3, 5};
const s16 gBurnTurnRange[2] = {0x7F, 0x7F};
const s16 gPoisonTurnRange[2] = {0x7F, 0x7F};
const s16 gBadPoisonTurnRange[2] = {0x7F, 0x7F};
const s16 gCringeTurnRange[2] = {1, 1};
const s16 gSpeedRaiseTurnRange[2] = {8, 10};
UNUSED static const s16 sUnusedTurnRange1[2] = {3, 4};
const s16 gSpeedLowerTurnRange[2] = {6, 8};
const s16 gConfusionTurnRange[2] = {6, 12};
const s16 gParalysisTurnRange[2] = {1, 2};
const s16 gShadowHoldTurnRange[2] = {2, 5};
const s16 gConstrictionTurnRange[2] = {3, 6};
const s16 gWrapTurnRange[2] = {2, 5};
const s16 gIngrainTurnRange[2] = {15, 30};
UNUSED static const s16 sUnusedTurnRange2[2] = {2, 3};
UNUSED static const s16 sUnusedTurnRange3[2] = {2, 6};
UNUSED static const s16 sUnusedTurnRange4[2] = {10, 10};
const s16 gPauseTurnRange[2] = {1, 1};
const s16 gSleepTurnRange[2] = {3, 7};
const s16 gNightmareTurnRange[2] = {4, 8};
const s16 gSleeplessTurnRange[2] = {10, 12};
const s16 gReflectTurnRange[2] = {10, 12};
const s16 gLightScreenTurnRange[2] = {10, 12};
const s16 gSafeguardTurnRange[2] = {15, 20};
const s16 gMistTurnRange[2] = {10, 14};
const s16 gMagicCoatTurnRange[2] = {10, 12};
const s16 gNappingTurnRange[2] = {2, 4};
const s16 gCounterTurnRange[2] = {6, 12};
const s16 gBideTurnRange[2] = {3, 5};
const s16 gEnragedTurnRange[2] = {4, 10};
const s16 gCurseTurnRange[2] = {3, 5};
const s16 gSnatchTurnRange[2] = {3, 5};
const s16 gMudWaterSportTurnRange[2] = {10, 12};
const s16 gLeechSeedTurnRange[2] = {10, 12};
const s16 gWishTurnRange[2] = {10, 12};
const s16 gSureShotTurnRange[2] = {10, 12};
const s16 gPetrifiedLeaderTurnRange[2] = {20, 30};
const s16 gPetrifiedTurnRange[2] = {0x7F, 0x7F};
const s16 gSetDamageTurnRange[2] = {2, 4};
const s16 gFocusEnergyTurnRange[2] = {2, 4};
const s16 gCowerTurnRange[2] = {10, 12};
const s16 gDecoyTurnRange[2] = {20, 50};
const s16 gProtectTurnRange[2] = {2, 6};
const s16 gTauntTurnRange[2] = {10, 12};
const s16 gWhifferTurnRange[2] = {1, 6};
const s16 gObserverOrbPausedTurnRange[2] = {10, 12};
const s16 gInvisibleTurnRange[2] = {10, 20};
const s16 gMirrorCoatTurnRange[2] = {10, 12};
const s16 gPerishSongTurnRange[2] = {3, 3};
const s16 gDestinyBondTurnRange[2] = {10, 10};
const s16 gEncoreTurnRange[2] = {10, 10};
const s16 gEnduringTurnRange[2] = {3, 5};
const s16 gTransformedTurnRange[2] = {0x7F, 0x7F};
const s16 gInfatuatedTurnRange[2] = {4, 6};
const s16 gMobileTurnRange[2] = {0x7F, 0x7F};
const s16 gBlinkerTurnRange[2] = {10, 10};
const s16 gCrossEyedTurnRange[2] = {10, 10};
const s16 gEyedropsTurnRange[2] = {0x7F, 0x7F};
UNUSED static const s16 sUnusedTurnRange5[2] = {10, 10};
const s16 gMirrorMoveTurnRange[2] = {2, 5};
const s16 gMuzzledTurnRange[2] = {10, 10};
const s16 gConversion2TurnRange[2] = {10, 10};
const s16 gVitalThrowTurnRange[2] = {15, 20};
const s16 gYawnTurnRange[2] = {2, 2};
const s16 gSleepFromYawnTurnRange[2] = {4, 8};

const s16 gSpeedBoostActivationFrame = 250;

const s16 gBurnDmgCountdown = 20;
const s16 gPoisonDmgCountdown = 10;
const s16 gBadPoisonDmgCountdown = 2;
const s16 gConstrictionDmgCountdown = 2;
const s16 gWrapDmgCountdown = 2;
const s16 gIngrainHealCountdown = 5;
const s16 gCurseDmgCountdown = 10;
const s16 gLeechSeedDmgCountdown = 2;

const s16 gMoveWeatherDuration = 20;

UNUSED static const s16 sUnusedConfig1 = 95;

const s16 gGinsengPlus3BoostChance = 12;
const s24_8 gSolarBeamModifier = IntToF248_2(2.0);
const s24_8 gSkyAttackModifier = IntToF248_2(2.0);
const s24_8 gRazorWindModifier = IntToF248_2(2.0);
const s24_8 gFocusPunchModifier = IntToF248_2(2.0);
const s24_8 gSkullBashModifier = IntToF248_2(2.0);
const s24_8 gFlyModifier = IntToF248_2(2.0);
const s24_8 gBounceModifier = IntToF248_2(2.0);
const s24_8 gDiveModifier = IntToF248_2(2.0);
const s24_8 gDigModifier = IntToF248_2(2.0);
const s24_8 gFacadeModifier = IntToF248_2(2.0);

const s16 gBurnDmgValue = 5;
const s16 gPoisonDmgValue = 4;
const s16 gConstrictionDmgValue = 5;
const s16 gWrapDmgValue = 6;
const s16 gNightmareDmgValue = 8;
const s16 gNappingHpHealValue = 999;
const s16 gSonicboomDmgValue = 55;
const s16 gDragonRageDmgValue = 65;
const s16 gVacuumCutDmgValue = 35;
const s16 gSplashDmgValue = 5;
const s16 gSpikeTrapDmgValue = 20;
const s16 gChestnutTrapDmgValue = 10;
UNUSED static const s16 sMaybeUnusedTrapDmgValue = 15;
const s16 gPitfallTrapDmgValue = 5;
const s16 gSetDamageDmgValue = 35;
const s16 gHailSandstormDmgValue = 5;
const s16 gBlowAwayDmgValue = 5;
const s16 gHurlOrbDmgValue = 10;
const s16 gMagnitudeDmgValues[7] = {5, 10, 15, 25, 30, 35, 40};
const s16 gUnknownDungeonChance = 90; // See sub_8047930
const s16 gBlastSeedThrownDmgValue = 20;
const s16 gBlastSeedEatenDmgValue = 45;
const s16 gBlastSeedThrownBossDmgValue = 15;
const s16 gBlastSeedEatenBossDmgValue = 30;
const s16 gUnknown_80F4FAC = 1;
const s16 gUnknown_80F4FAE = 2;
UNUSED static const s16 sUnusedConfig2 = 25;
const s16 gIngrainHealValue = 10;
const s16 gLeechSeedHealValue = 10;
const s16 gOranBerryHealValue = 100;
const s16 gOranBerryMaxHpRiseValue = 0;
const s16 gSitrusBerryHealValue = 100;
const s16 gSitrusBerryMaxHpRiseValue = 2;
const s16 gLifeSeedMaxHpRiseValue = 3;
const s16 gWishRegenValue = -220;
const s16 gRainDishRegenValue = -150;
const s16 gHealRibbonRegenValue = -100;
const s16 gFamishBellyDownValue = 10;
const s16 gBadPoisonDmgValuesByTurn[BAD_POISON_DMG_TURN_VALUES_COUNT] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 }; // Always damages the player by 6 hp, but given this exists it's possible they planned the damage to become worse each turn, but later decided to go against it.
const s16 gStenchTerrifiedTurnsNo = 3;
const s16 gPassScarfBellyDownValue = 2;
const s16 gFriendBowRecruitRateUpValue = 100;
const s16 gSynthesisHealValueByWeather[WEATHER_COUNT] =
{
    [WEATHER_CLEAR] = 50,
    [WEATHER_SUNNY] = 80,
    [WEATHER_SANDSTORM] = 30,
    [WEATHER_CLOUDY] = 40,
    [WEATHER_RAIN] = 10,
    [WEATHER_HAIL] = 10,
    [WEATHER_FOG] = 1,
    [WEATHER_SNOW] = 1,
};
const s16 gMoonlightHealValueByWeather[WEATHER_COUNT] = // Identical to Synthesis
{
    [WEATHER_CLEAR] = 50,
    [WEATHER_SUNNY] = 80,
    [WEATHER_SANDSTORM] = 30,
    [WEATHER_CLOUDY] = 40,
    [WEATHER_RAIN] = 10,
    [WEATHER_HAIL] = 10,
    [WEATHER_FOG] = 1,
    [WEATHER_SNOW] = 1,
};
const s16 gMorningSunHealValueByWeather[WEATHER_COUNT] = // Identical to Synthesis
{
    [WEATHER_CLEAR] = 50,
    [WEATHER_SUNNY] = 80,
    [WEATHER_SANDSTORM] = 30,
    [WEATHER_CLOUDY] = 40,
    [WEATHER_RAIN] = 10,
    [WEATHER_HAIL] = 10,
    [WEATHER_FOG] = 1,
    [WEATHER_SNOW] = 1,
};
const s16 gStickPPValue = 1;
const s16 gIronThornPPValue = 5;
const s16 gSilverSpikePPValue = 6;
const s16 gGoldFangPPValue = 7;
const s16 gCacneaSpikePPValue = 8;
const s16 gCorsolaTwigPPValue = 9;
const s16 gGravelerockThrownDmgValue = 20;
const s16 gGeoPebbleThrownDmgValue = 15;
UNUSED static const s16 sUnusedConfig3 = 0;
const s24_8 gAtkStatStageMultipliers[21] =
{
    IntToF248_2(0.2500), IntToF248_2(0.2696), IntToF248_2(0.2892), IntToF248_2(0.3087), IntToF248_2(0.3282), IntToF248_2(0.3478),
    IntToF248_2(0.3985), IntToF248_2(0.4493), IntToF248_2(0.5000), IntToF248_2(0.6993), IntToF248_2(1.0000), IntToF248_2(1.2969),
    IntToF248_2(1.5000), IntToF248_2(1.5978), IntToF248_2(1.6485), IntToF248_2(1.6993), IntToF248_2(1.7500), IntToF248_2(1.7969),
    IntToF248_2(1.8478), IntToF248_2(1.8985), IntToF248_2(2.0000)
};
const s24_8 gDefStatStageMultipliers[21] =
{
    IntToF248_2(0.2500), IntToF248_2(0.2696), IntToF248_2(0.2892), IntToF248_2(0.3087), IntToF248_2(0.3282), IntToF248_2(0.3478),
    IntToF248_2(0.3985), IntToF248_2(0.5469), IntToF248_2(0.6993), IntToF248_2(0.8672), IntToF248_2(1.0000), IntToF248_2(1.2969),
    IntToF248_2(1.5000), IntToF248_2(1.5978), IntToF248_2(1.6485), IntToF248_2(1.6993), IntToF248_2(1.7500), IntToF248_2(1.7969),
    IntToF248_2(1.8478), IntToF248_2(1.8985), IntToF248_2(2.0000)
};
const s24_8 gAccEvsStatStageMultipliers[2][21] =
{
    // Accuracy
    {
        IntToF248_2(0.3282), IntToF248_2(0.3478), IntToF248_2(0.3672), IntToF248_2(0.3985), IntToF248_2(0.4297), IntToF248_2(0.4493),
        IntToF248_2(0.5469), IntToF248_2(0.5977), IntToF248_2(0.6993), IntToF248_2(0.7969), IntToF248_2(1.0000), IntToF248_2(1.2500),
        IntToF248_2(1.5000), IntToF248_2(1.5978), IntToF248_2(1.6485), IntToF248_2(1.6993), IntToF248_2(1.7500), IntToF248_2(1.7969),
        IntToF248_2(1.8478), IntToF248_2(1.8985), IntToF248_2(2.0000)
    },
    // Evasion
    {
        IntToF248_2(2.0000), IntToF248_2(1.8985), IntToF248_2(1.8478), IntToF248_2(1.7969), IntToF248_2(1.7500), IntToF248_2(1.6993),
        IntToF248_2(1.6485), IntToF248_2(1.5978), IntToF248_2(1.5000), IntToF248_2(1.3515), IntToF248_2(1.0000), IntToF248_2(0.7969),
        IntToF248_2(0.6993), IntToF248_2(0.5977), IntToF248_2(0.5000), IntToF248_2(0.3985), IntToF248_2(0.3477), IntToF248_2(0.2969),
        IntToF248_2(0.2500), IntToF248_2(0.1993), IntToF248_2(0.1485)
    },
};
