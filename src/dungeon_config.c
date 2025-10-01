#include "global.h"
#include "globaldata.h"
#include "dungeon_config.h"
#include "math.h"
#include "constants/weather.h"
#include "constants/type.h"
#include "constants/monster.h"
#include "constants/dungeon_action.h"
#include "constants/move_id.h"
#include "dungeon_move.h"
#include "move_orb_actions_1.h"
#include "move_orb_actions_2.h"
#include "move_orb_actions_3.h"
#include "move_orb_actions_4.h"

// Huge list of various config variables for dungeon moves/music/abilities/items/etc. All in one file, because these are scattered all around the codebase with only one pksdir present.

// Monster House config
const s16 gMonsterHouseMaxItemsTraps = 7; // Items and traps are included together
const s16 gMonsterHouseMinMons = 8;
const s16 gMonsterHouseMaxMons = 12;
// ? See sub_8071B48
const s16 gUnknown_80F4DA6 = 10;
const s16 gUnknown_80F4DA8 = 4;
const s16 gUnknown_80F4DAA = 36;
const s16 gUnknown_80F4DAC = 5;
const s16 gCritOddsScopeLensPatsyBand = 40;
const s16 gCritOddsIqAdvantageMaster = 40;

const s16 gAIConfusedAttackChance = 70;
// Various moves' secondary effect percent chance
const s16 gIronTailSecondaryChance = 30;
const s16 gBubbleSecondaryChance = 10;
const s16 gFlameWheelSecondaryChance = 10;
const s16 gFireMoveBurnSecondaryChance = 10;
const s16 gIceMoveFreezeSecondaryChance = 10;
const s16 gPoisonStingSecondaryChance = 18;
const s16 gPsychicSecondaryChance = 10;
const s16 gShadowBallSecondaryChance = 20;
const s16 gSmogSecondaryChance = 40;
const s16 gPoisonTailSecondaryChance = 10;
const s16 gTwineedleSecondaryChance = 20;
const s16 gPoisonFangSecondaryChance = 30;
const s16 gBounceSecondaryChance = 30;
const s16 gMetalClawSecondaryChance = 10;
const s16 gMeteorMashSecondaryChance = 20;
const s16 gSteelWingSecondaryChance = 10;
const s16 gConstrictBubblebeamSecondaryChance = 10;
const s16 gAncientPowerSecondaryChance = 10;
const s16 gMistBallSecondaryChance = 50;
const s16 gCrushClawSecondaryChance = 50;
const s16 gLusterPurgeSecondaryChance = 50;
UNUSED static const s16 sUnusedConfig5 = 50;
const s16 gSacredFireSecondaryChance = 50;
const s16 gThundershockSecondaryChance = 10;
const s16 gLickSecondaryChance = 15;
const s16 gThunderSecondaryChance = 20;
const s16 gThunderboltSecondaryChance = 10;
const s16 gExtrasensorySecondaryChance = 10;
const s16 gTwisterSecondaryChance = 15;
const s16 gBiteSecondaryChance = 20;
const s16 gHeadbuttSecondaryChance = 25;
const s16 gFakeOutSecondaryChance = 35;
const s16 gSkyAttackSecondaryChance = 25;
const s16 gRockSlideSecondaryChance = 30;
const s16 gMovesConfusionSecondaryChance = 10;
const s16 gDizzyPunchSecondaryChance = 30;
const s16 gTriAttackSecondaryChance = 20;
const s16 gBlazeKickSecondaryChance = 10;
const s16 gMuddyWaterAccLowerChance = 40;
const s16 gOctazookaAccLowerChance = 60;
const s16 gAuroraBeamAtkLowerChance = 60;
const s16 gSecretPowerSecondaryEffectChance = 30;
const s16 gMovesConstrictionChance = 10; // Fire Spin, Whirlpool, Clamp, Bind, Sand Tomb
const s16 gSnoreSecondaryChance = 30;
// Activation chance of abilities/traps
const s16 gShedSkinActivateChance = 50;
const s16 gGrimyTrapActivateChance = 30;
// Target ability - activation chance
const s16 gArenaTrapActivateChance = 12;
const s16 gShadowTagActivateChance = 12;
const s16 gMagnetPullActivateChance = 12;
const s16 gStaticActivateChance = 12;
const s16 gPoisonPointActivateChance = 12;
const s16 gEffectSproreActivateChance = 12;
const s16 gFlameBodyActivateChance = 12;
const s16 gCuteCharmActivateChance = 12;
const s16 gStenchActivateChance = 12;

const s16 gAiRegularAttackWeights[5] = {100, 20, 30, 40, 50};

// Status turn ranges
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
// Move modifiers
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

// Fixed damage/heal values
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
const s16 gProjectileHitChance = 90;
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

// Projectile values
const s16 gStickPPValue = 1;
const s16 gIronThornPPValue = 5;
const s16 gSilverSpikePPValue = 6;
const s16 gGoldFangPPValue = 7;
const s16 gCacneaSpikePPValue = 8;
const s16 gCorsolaTwigPPValue = 9;
const s16 gGravelerockThrownDmgValue = 20;
const s16 gGeoPebbleThrownDmgValue = 15;
UNUSED static const s16 sUnusedConfig3 = 0;

// Stat stage multipliers
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

const s32 gDetectBandAccuracyDebuffValue = 30; // For attacking mon, which effectively raises target's evasion
const s32 gIqQuickDodgerAccuracyDebuffValue = 30; // For attacking mon, which effectively raises target's evasion
// Move modifiers again
const s24_8 gReversalModifiers[4] = {IntToF248_2(8), IntToF248_2(4), IntToF248_2(2), IntToF248_2(1)}; // Based on hp/max HP ratio
const s24_8 gWaterSpoutModifiers[4] = {IntToF248_2(0.1), IntToF248_2(0.2), IntToF248_2(0.5), IntToF248_2(1)}; // Based on hp/max HP ratio
const s24_8 gEruptionModifiers[4] = {IntToF248_2(0.1), IntToF248_2(0.2), IntToF248_2(0.5), IntToF248_2(1)}; // Based on hp/max HP ratio
const s32 gStockpileHealHpValues[4] = {0, 20, 40, 80};

// Castform related
const u8 gWeatherBallTypes[WEATHER_COUNT] =
{
    [WEATHER_CLEAR] = TYPE_NORMAL,
    [WEATHER_SUNNY] = TYPE_FIRE,
    [WEATHER_SANDSTORM] = TYPE_ROCK,
    [WEATHER_CLOUDY] = TYPE_NORMAL,
    [WEATHER_RAIN] = TYPE_WATER,
    [WEATHER_HAIL] = TYPE_ICE,
    [WEATHER_FOG] = TYPE_WATER,
    [WEATHER_SNOW] = TYPE_ICE,
};
const s24_8 gWeatherBallModifiers[WEATHER_COUNT] =
{
    [WEATHER_CLEAR] = IntToF248_2(1.0),
    [WEATHER_SUNNY] = IntToF248_2(2.0),
    [WEATHER_SANDSTORM] = IntToF248_2(2.0),
    [WEATHER_CLOUDY] = IntToF248_2(1.0),
    [WEATHER_RAIN] = IntToF248_2(2.0),
    [WEATHER_HAIL] = IntToF248_2(2.0),
    [WEATHER_FOG] = IntToF248_2(2.0),
    [WEATHER_SNOW] = IntToF248_2(2.0),
};

const struct CastformWeatherData gCastformByWeather[WEATHER_COUNT] =
{
    [WEATHER_CLEAR] = {
        .type = TYPE_NORMAL,
        .monsterId = MONSTER_CASTFORM
    },
    [WEATHER_SUNNY] = {
        .type = TYPE_FIRE,
        .monsterId = MONSTER_CASTFORM_SUNNY
    },
    [WEATHER_SANDSTORM] = {
        .type = TYPE_NORMAL,
        .monsterId = MONSTER_CASTFORM
    },
    [WEATHER_CLOUDY] = {
        .type = TYPE_NORMAL,
        .monsterId = MONSTER_CASTFORM
    },
    [WEATHER_RAIN] = {
        .type = TYPE_WATER,
        .monsterId = MONSTER_CASTFORM_RAINY
    },
    [WEATHER_HAIL] = {
        .type = TYPE_ICE,
        .monsterId = MONSTER_CASTFORM_SNOWY
    },
    [WEATHER_FOG] = {
        .type = TYPE_WATER,
        .monsterId = MONSTER_CASTFORM_RAINY
    },
    [WEATHER_SNOW] = {
        .type = TYPE_ICE,
        .monsterId = MONSTER_CASTFORM_SNOWY
    },
};

// Type chart
#define IMMUNE EFFECTIVENESS_IMMUNE
#define RESIST EFFECTIVENESS_RESIST
#define NEUTRAL EFFECTIVENESS_NEUTRAL
#define SUPER EFFECTIVENESS_SUPER

const s16 gTypeEffectivenessChart[NUM_TYPES][NUM_TYPES] = {
    //                  NONE       NORMAL    FIRE    WATER    GRASS   ELECTRIC  ICE     FIGHTING  POISON  GROUND   FLYING   PSYCHIC   BUG      ROCK     GHOST    DRAGON   DARK     STEEL
    [TYPE_NONE] =       {NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL},
    [TYPE_NORMAL] =     {NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, RESIST},
    [TYPE_FIRE] =       {NEUTRAL, NEUTRAL, RESIST,  RESIST,  SUPER,   NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   RESIST,  NEUTRAL, RESIST,  NEUTRAL, SUPER},
    [TYPE_WATER] =      {NEUTRAL, NEUTRAL, SUPER,   RESIST,  RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, RESIST,  NEUTRAL, NEUTRAL},
    [TYPE_GRASS] =      {NEUTRAL, NEUTRAL, RESIST,  SUPER,   RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, RESIST,  SUPER,   RESIST,  NEUTRAL, RESIST,  SUPER,   NEUTRAL, RESIST,  NEUTRAL, RESIST},
    [TYPE_ELECTRIC] =   {NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   RESIST,  RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, IMMUNE,  SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, RESIST,  NEUTRAL, NEUTRAL},
    [TYPE_ICE] =        {NEUTRAL, NEUTRAL, RESIST,  RESIST,  SUPER,   NEUTRAL, RESIST,  NEUTRAL, NEUTRAL, SUPER,   SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, RESIST},
    [TYPE_FIGHTING] =   {NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, RESIST,  NEUTRAL, RESIST,  RESIST,  RESIST,  SUPER,   NEUTRAL, NEUTRAL, SUPER,   SUPER},
    [TYPE_POISON] =     {NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, RESIST,  RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, RESIST,  RESIST,  NEUTRAL, NEUTRAL, IMMUNE},
    [TYPE_GROUND] =     {NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, RESIST,  SUPER,   NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, IMMUNE,  NEUTRAL, RESIST,  SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, SUPER},
    [TYPE_FLYING] =     {NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   RESIST,  NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, RESIST},
    [TYPE_PSYCHIC] =    {NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   SUPER,   NEUTRAL, NEUTRAL, RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, IMMUNE,  RESIST},
    [TYPE_BUG] =        {NEUTRAL, NEUTRAL, RESIST,  NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, RESIST,  RESIST,  NEUTRAL, RESIST,  SUPER,   NEUTRAL, NEUTRAL, RESIST,  NEUTRAL, SUPER,   RESIST},
    [TYPE_ROCK] =       {NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   RESIST,  NEUTRAL, RESIST,  SUPER,   NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, RESIST},
    [TYPE_GHOST] =      {NEUTRAL, IMMUNE,  NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, RESIST,  RESIST},
    [TYPE_DRAGON] =     {NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, RESIST},
    [TYPE_DARK] =       {NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, RESIST,  NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, RESIST,  RESIST},
    [TYPE_STEEL] =      {NEUTRAL, NEUTRAL, RESIST,  RESIST,  NEUTRAL, RESIST,  SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, NEUTRAL, SUPER,   NEUTRAL, NEUTRAL, NEUTRAL, RESIST}
};

const s32 gEffectivenessChart[NUM_EFFECTIVENESS][NUM_EFFECTIVENESS] = {
    [IMMUNE] = {
        [IMMUNE] = IMMUNE,
        [RESIST] = IMMUNE,
        [NEUTRAL] = IMMUNE,
        [SUPER] = RESIST,
    },
    [RESIST] = {
        [IMMUNE] = IMMUNE,
        [RESIST] = RESIST,
        [NEUTRAL] = RESIST,
        [SUPER] = NEUTRAL,
    },
    [NEUTRAL] = {
        [IMMUNE] = IMMUNE,
        [RESIST] = RESIST,
        [NEUTRAL] = NEUTRAL,
        [SUPER] = SUPER,
    },
    [SUPER] = {
        [IMMUNE] = RESIST,
        [RESIST] = NEUTRAL,
        [NEUTRAL] = SUPER,
        [SUPER] = SUPER,
    },
};

const s48_16 gBellyGoDownValues[BELLY_GO_DOWN_VALUES_COUNT] =
{
    S48_16(0.0),
    S48_16(0.0),
    S48_16(0.0),
    S48_16(0.0),
    S48_16(0.0),
    S48_16(0.0),
    S48_16(0.10001),
    S48_16(0.25),
    S48_16(0.5),
    S48_16(0.75),
    S48_16(1.0),
    S48_16(2.0),
    S48_16(4.0),
    S48_16(8.0),
    S48_16(16.0),
    S48_16(32.0),
    S48_16(64.0),
    S48_16(128.0),
    S48_16(128.0),
    S48_16(128.0)
};

const s16 gWarpScarfActivationChances[WARP_SCARF_ACTIVATION_CHANCES_COUNT] = {0, 6, 12, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 270, 290, 310, 999, 0};

// Return and frustration
// Min iq -> dmg value -1 is table's end
const struct ReturnDmgData gReturnDmgData[] =
{
    {50, 5},
    {100, 10},
    {200, 15},
    {300, 20},
    {400, 25},
    {500, 30},
    {600, 35},
    {700, 40},
    {800, 45},
    {1000, 45},
    {10000, 9999}, // Unreachable in normal gameplay
    {-1, 1},
};

const struct ReturnDmgData gFrustrationDmgData[] =
{
    {0, 9999},
    {50, 45},
    {100, 40},
    {200, 35},
    {300, 30},
    {400, 25},
    {500, 20},
    {600, 15},
    {700, 10},
    {1000, 5},
    {10000, 1}, // Unreachable in normal gameplay
    {-1, 1},
};

// Array indices correspond to the current dungeon tileset.
const u8 gDungeonCamouflageTypes[76] = {
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_GRASS,
    TYPE_ICE,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_ICE,
    TYPE_ICE,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GROUND,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_ICE,
    TYPE_ROCK,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_WATER,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_WATER,
    TYPE_WATER,
    TYPE_ROCK
};

// Todo: Use music song constants
const s16 gDungeonMusic[76] = {
    114, 125, 14, 120, 15, 113, 111, 20, 102, 25, 104,
    115, 108, 22, 125, 125, 125, 125, 13, 21, 15, 126,
    33, 39, 123, 124, 23, 125, 125, 125, 125, 125, 125,
    125, 125, 125, 125, 125, 125, 125, 26, 110, 110, 125,
    125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
    125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 26,
    127, 35, 35, 35, 125, 125, 125, 125, 125, 125
};

const s16 gRecruitRateByLevel[101] = {
    [0  ... 29] = 0,
    [30 ... 39] = 50,
    [40 ... 49] = 75,
    [50 ... 59] = 100,
    [60 ... 69] = 125,
    [70 ... 79] = 150,
    [80 ... 89] = 175,
    [90 ... 100] = 240,
};

// Not sure what this level corresponds to exactly
const s16 gRayquazaConfigLevel = 10;
const s16 gZapdosConfigLevel = 20;
const s16 gMoltresConfigLevel = 20;
const s16 gArticunoConfigLevel = 20;
const s16 gGroudonConfigLevel = 10;

// Dimensions are [floorProperty kecleonShopLayout][y][x] See sub_8051654
const s16 sKecleonShopItemSpawnChances[16][3][3] = {
    [0] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [1] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [2] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [3] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [4] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [5] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [6] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [7] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [8] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [9] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [10] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [11] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [12] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [13] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [14] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
    [15] = {
        {57, 57, 57},
        {100, 57, 100},
        {57, 57, 57},
    },
};

// TODO: use action constants
const bool8 gUnknown_80F58F4[NUM_DUNGEON_ACTIONS][2] =
{
    {FALSE, FALSE},
    {FALSE, FALSE},
    {TRUE, FALSE},
    {TRUE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {TRUE, TRUE},
    {TRUE, TRUE},
    {TRUE, TRUE},
    {TRUE, TRUE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {TRUE, FALSE},
    {TRUE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {TRUE, TRUE},
    {TRUE, TRUE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {TRUE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
    {FALSE, FALSE},
};

// Per dungeon's tileset
// TODO: use defines for these effects
const u8 gSecretPowerTable[76] = {
    3,
	0,
	6,
	7,
	7,
	6,
	6,
	7,
	8,
	6,
	0,
	5,
	8,
	8,
	0,
	8,
	8,
	7,
	7,
	7,
	0,
	5,
	6,
	8,
	6,
	0,
	0,
	8,
	6,
	1,
	7,
	7,
	1,
	1,
	6,
	8,
	8,
	7,
	6,
	6,
	6,
	0,
	6,
	6,
	5,
	8,
	6,
	6,
	6,
	3,
	0,
	0,
	5,
	2,
	7,
	6,
	0,
	8,
	8,
	6,
	0,
	7,
	0,
	0,
	6,
	1,
	6,
	6,
	8,
	8,
	6,
	8,
	8,
	3,
	3,
	6
};

const s16 gIqItemMasterMinWildLevel = 16;

// These are random
const struct CalledMove gMetronomeCalledMoves[METRONOME_AVAILABLE_CALLED_MOVES] =
{
    {MOVE_IRON_TAIL, IronTailMoveAction},
    {MOVE_YAWN, YawnMoveAction},
    {MOVE_NIGHTMARE, NightmareMoveAction},
    {MOVE_CHARM, CharmMoveAction},
    {MOVE_ENCORE, EncoreMoveAction},
    {MOVE_SUPER_FANG, SuperFangMoveAction},
    {MOVE_PAIN_SPLIT, PainSplitMoveAction},
    {MOVE_TORMENT, TormentMoveAction},
    {MOVE_SWAGGER, SwaggerMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_WHIRLPOOL, WhirlpoolMoveAction},
    {MOVE_FAKE_TEARS, FakeTearsMoveAction},
    {MOVE_SPITE, SpiteMoveAction},
    {MOVE_SMOKESCREEN, SmokescreenMoveAction},
    {MOVE_FLATTER, FlatterMoveAction},
    {MOVE_WILL_O_WISP, WillOWispMoveAction},
    {MOVE_RETURN, ReturnMoveAction},
    {MOVE_FLAME_WHEEL, FlameWheelMoveAction},
    {MOVE_GUST, GustMoveAction},
    {MOVE_DISABLE, DisableMoveAction},
    {MOVE_CRUNCH, ShadowBallMoveAction},
    {MOVE_BITE, BiteMoveAction},
    {MOVE_THUNDER, ThunderMoveAction},
    {MOVE_ENDEAVOR, EndeavorMoveAction},
    {MOVE_FACADE, FacadeMoveAction},
    {MOVE_CONSTRICT, sub_8058580},
    {MOVE_BRICK_BREAK, BrickBreakMoveAction},
    {MOVE_ROCK_TOMB, RockTombMoveAction},
    {MOVE_GIGA_DRAIN, GigaDrainMoveAction},
    {MOVE_REVERSAL, ReversalMoveAction},
    {MOVE_SMELLINGSALT, SmellingSaltMoveAction},
    {MOVE_METAL_SOUND, MetalSoundMoveAction},
    {MOVE_TICKLE, TickleMoveAction},
    {MOVE_OUTRAGE, OutrageMoveAction},
    {MOVE_LOW_KICK, LowKickMoveAction},
    {MOVE_ANCIENTPOWER, AncientPowerMoveAction},
    {MOVE_RAPID_SPIN, RapidSpinMoveAction},
    {MOVE_SCARY_FACE, ScaryFaceMoveAction},
    {MOVE_SUBMISSION, sub_8058E5C},
    {MOVE_LICK, LickMoveAction},
    {MOVE_FISSURE, FissureMoveAction},
    {MOVE_EXTRASENSORY, ExtrasensoryMoveAction},
    {MOVE_ABSORB, AbsorbMoveAction},
    {MOVE_SKILL_SWAP, SkillSwapMoveAction},
    {MOVE_HEADBUTT, HeadbuttMoveAction},
    {MOVE_DOUBLE_EDGE, DoubleEdgeMoveAction},
    {MOVE_SAND_ATTACK, sub_8059528},
    {MOVE_SMOG, SmogMoveAction},
    {MOVE_SACRED_FIRE, SacredFireMoveAction},
    {MOVE_SHEER_COLD, sub_80595EC},
    {MOVE_MUDDY_WATER, MuddyWaterMoveAction},
    {MOVE_TWISTER, TwisterMoveAction},
    {MOVE_TWINEEDLE, TwineedleMoveAction},
    {MOVE_SEISMIC_TOSS, sub_8059A2C},
    {MOVE_SUPERSONIC, SupersonicMoveAction},
    {MOVE_TAUNT, TauntMoveAction},
    {MOVE_HORN_DRILL, HornDrillMoveAction},
    {MOVE_THUNDERSHOCK, ThundershockMoveAction},
    {MOVE_THUNDER_WAVE, ThunderWaveMoveAction},
    {MOVE_BLOCK, BlockMoveAction},
    {MOVE_POISON_GAS, PoisonGasMoveAction},
    {MOVE_TOXIC, ToxicMoveAction},
    {MOVE_POISON_FANG, PoisonFangMoveAction},
    {MOVE_POISON_STING, PoisonStingMoveAction},
    {MOVE_TRI_ATTACK, TriAttackMoveAction},
    {MOVE_TRICK, TrickMoveAction},
    {MOVE_TRIPLE_KICK, TripleKickMoveAction},
    {MOVE_MUD_SLAP, MudSlapMoveAction},
    {MOVE_THIEF, ThiefMoveAction},
    {MOVE_ROLE_PLAY, RolePlayMoveAction},
    {MOVE_LEER, LeerMoveAction},
    {MOVE_PAY_DAY, PayDayMoveAction},
    {MOVE_CURSE, CurseMoveAction},
    {MOVE_FRENZY_PLANT, sub_805A568},
    {MOVE_SUPERPOWER, SuperpowerMoveAction},
    {MOVE_DYNAMICPUNCH, DynamicPunchMoveAction},
    {MOVE_KNOCK_OFF, KnockOffMoveAction},
    {MOVE_SECRET_POWER, SecretPowerMoveAction},
    {MOVE_DIZZY_PUNCH, sub_805AC90},
    {MOVE_IMPRISON, ObserverOrbAction},
    {MOVE_FEATHERDANCE, FeatherDanceMoveAction},
    {MOVE_BEAT_UP, BeatUpMoveAction},
    {MOVE_BLAST_BURN, BlastBurnMoveAction},
    {MOVE_CRUSH_CLAW, CrushClawMoveAction},
    {MOVE_BLAZE_KICK, BlazeKickMoveAction},
    {MOVE_PRESENT, PresentMoveAction},
    {MOVE_ERUPTION, EruptionMoveAction},
    {MOVE_GLARE, GlareMoveAction},
    {MOVE_POISON_TAIL, PoisonTailMoveAction},
    {MOVE_ROAR, RoarMoveAction},
    {MOVE_FIRE_SPIN, sub_805B17C},
    {MOVE_WRAP, WrapMoveAction},
    {MOVE_MAGNITUDE, MagnitudeMoveAction},
    {MOVE_MIST_BALL, MistBallMoveAction},
    {MOVE_DESTINY_BOND, DestinyBondMoveAction},
    {MOVE_FALSE_SWIPE, FalseSwipeMoveAction},
    {MOVE_HIDDEN_POWER, HiddenPowerMoveAction},
    {MOVE_ATTRACT, AttractMoveAction},
    {MOVE_MIMIC, MimicMoveAction},
    {MOVE_FRUSTRATION, FrustrationMoveAction},
    {MOVE_LEECH_SEED, LeechSeedMoveAction},
    {MOVE_DREAM_EATER, DreamEaterMoveAction},
    {MOVE_LUSTER_PURGE, LusterPurgeMoveAction},
    {MOVE_DRAGON_RAGE, DragonRageMoveAction},
    {MOVE_FAKE_OUT, FakeOutMoveAction},
};

// These correspond to dungeon's tileset id
const struct CalledMove gNaturePowerCalledMoves[] =
{
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_BUBBLEBEAM, sub_8058580},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SHADOW_BALL, ShadowBallMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, HandleRegularDamagingMove},
};

const u16 gUnknown_80F5F70[UNK12A18_ARR_COUNT] = {12, 12, 12, 12, 12, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 12};
const s32 gUnknown_80F5FAC[76] = {
    4, 0, 3, 3, 0, 3, 0, 3, 3, 1, 0, 0, 0, 3, 0, 1, 4,
    0, 1, 1, 0, 3, 3, 0, 1, 3, 0, 0, 3, 3, 0, 3, 4, 4,
    1, 1, 1, 3, 3, 3, 0, 0, 0, 0, 0, 4, 2, 1, 2, 4, 0,
    0, 0, 0, 4, 1, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 3, 2,
    1, 1, 2, 1, 1, 4, 4, 1
};

// belly will go down by this amount after using linked moves
// value depends on number of moves that are linked
const s32 gLinkedMovesBellyGoDownValues[5] = {
    1, // 0 moves
    1, // 1 move
    1, // 2 moves
    2, // 3 moves
    4  // 4 moves
};
