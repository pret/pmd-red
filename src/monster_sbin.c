#include "global.h"
#include "file_system.h"

#define MONSTER_FILES_COUNT 497

extern const File gMonsterFiles[MONSTER_FILES_COUNT];

const FileArchive gMonsterFileArchive = {
    .magic = "pksdir0",
    .count = MONSTER_FILES_COUNT,
    .entries = gMonsterFiles,
};

UNUSED static const char sPksDir2[] = "pksdir0";

// Todo: create a directory/file for the mon sprites
extern const u8 gAxBulbasaur[];
extern const u8 gAxIvysaur[];
extern const u8 gAxVenusaur[];
extern const u8 gAxCharmander[];
extern const u8 gAxCharmeleon[];
extern const u8 gAxCharizard[];
extern const u8 gAxSquirtle[];
extern const u8 gAxWartortle[];
extern const u8 gAxBlastoise[];
extern const u8 gAxCaterpie[];
extern const u8 gAxMetapod[];
extern const u8 gAxButterfree[];
extern const u8 gAxWeedle[];
extern const u8 gAxKakuna[];
extern const u8 gAxBeedrill[];
extern const u8 gAxPidgey[];
extern const u8 gAxPidgeotto[];
extern const u8 gAxPidgeot[];
extern const u8 gAxRattata[];
extern const u8 gAxRaticate[];
extern const u8 gAxSpearow[];
extern const u8 gAxFearow[];
extern const u8 gAxEkans[];
extern const u8 gAxArbok[];
extern const u8 gAxPikachu[];
extern const u8 gAxRaichu[];
extern const u8 gAxSandshrew[];
extern const u8 gAxSandslash[];
extern const u8 gAxNidoranF[];
extern const u8 gAxNidorina[];
extern const u8 gAxNidoqueen[];
extern const u8 gAxNidoranM[];
extern const u8 gAxNidorino[];
extern const u8 gAxNidoking[];
extern const u8 gAxClefairy[];
extern const u8 gAxClefable[];
extern const u8 gAxVulpix[];
extern const u8 gAxNinetales[];
extern const u8 gAxJigglypuff[];
extern const u8 gAxWigglytuff[];
extern const u8 gAxZubat[];
extern const u8 gAxGolbat[];
extern const u8 gAxOddish[];
extern const u8 gAxGloom[];
extern const u8 gAxVileplume[];
extern const u8 gAxParas[];
extern const u8 gAxParasect[];
extern const u8 gAxVenonat[];
extern const u8 gAxVenomoth[];
extern const u8 gAxDiglett[];
extern const u8 gAxDugtrio[];
extern const u8 gAxMeowth[];
extern const u8 gAxPersian[];
extern const u8 gAxPsyduck[];
extern const u8 gAxGolduck[];
extern const u8 gAxMankey[];
extern const u8 gAxPrimeape[];
extern const u8 gAxGrowlithe[];
extern const u8 gAxArcanine[];
extern const u8 gAxPoliwag[];
extern const u8 gAxPoliwhirl[];
extern const u8 gAxPoliwrath[];
extern const u8 gAxAbra[];
extern const u8 gAxKadabra[];
extern const u8 gAxAlakazam[];
extern const u8 gAxMachop[];
extern const u8 gAxMachoke[];
extern const u8 gAxMachamp[];
extern const u8 gAxBellsprout[];
extern const u8 gAxWeepinbell[];
extern const u8 gAxVictreebel[];
extern const u8 gAxTentacool[];
extern const u8 gAxTentacruel[];
extern const u8 gAxGeodude[];
extern const u8 gAxGraveler[];
extern const u8 gAxGolem[];
extern const u8 gAxPonyta[];
extern const u8 gAxRapidash[];
extern const u8 gAxSlowpoke[];
extern const u8 gAxSlowbro[];
extern const u8 gAxMagnemite[];
extern const u8 gAxMagneton[];
extern const u8 gAxFarfetchd[];
extern const u8 gAxDoduo[];
extern const u8 gAxDodrio[];
extern const u8 gAxSeel[];
extern const u8 gAxDewgong[];
extern const u8 gAxGrimer[];
extern const u8 gAxMuk[];
extern const u8 gAxShellder[];
extern const u8 gAxCloyster[];
extern const u8 gAxGastly[];
extern const u8 gAxHaunter[];
extern const u8 gAxGengar[];
extern const u8 gAxOnix[];
extern const u8 gAxDrowzee[];
extern const u8 gAxHypno[];
extern const u8 gAxKrabby[];
extern const u8 gAxKingler[];
extern const u8 gAxVoltorb[];
extern const u8 gAxElectrode[];
extern const u8 gAxExeggcute[];
extern const u8 gAxExeggutor[];
extern const u8 gAxCubone[];
extern const u8 gAxMarowak[];
extern const u8 gAxHitmonlee[];
extern const u8 gAxHitmonchan[];
extern const u8 gAxLickitung[];
extern const u8 gAxKoffing[];
extern const u8 gAxWeezing[];
extern const u8 gAxRhyhorn[];
extern const u8 gAxRhydon[];
extern const u8 gAxChansey[];
extern const u8 gAxTangela[];
extern const u8 gAxKangaskhan[];
extern const u8 gAxHorsea[];
extern const u8 gAxSeadra[];
extern const u8 gAxGoldeen[];
extern const u8 gAxSeaking[];
extern const u8 gAxStaryu[];
extern const u8 gAxStarmie[];
extern const u8 gAxMrMime[];
extern const u8 gAxScyther[];
extern const u8 gAxJynx[];
extern const u8 gAxElectabuzz[];
extern const u8 gAxMagmar[];
extern const u8 gAxPinsir[];
extern const u8 gAxTauros[];
extern const u8 gAxMagikarp[];
extern const u8 gAxGyarados[];
extern const u8 gAxLapras[];
extern const u8 gAxDitto[];
extern const u8 gAxEevee[];
extern const u8 gAxVaporeon[];
extern const u8 gAxJolteon[];
extern const u8 gAxFlareon[];
extern const u8 gAxPorygon[];
extern const u8 gAxOmanyte[];
extern const u8 gAxOmastar[];
extern const u8 gAxKabuto[];
extern const u8 gAxKabutops[];
extern const u8 gAxAerodactyl[];
extern const u8 gAxSnorlax[];
extern const u8 gAxArticuno[];
extern const u8 gAxZapdos[];
extern const u8 gAxMoltres[];
extern const u8 gAxDratini[];
extern const u8 gAxDragonair[];
extern const u8 gAxDragonite[];
extern const u8 gAxMewtwo[];
extern const u8 gAxMew[];
extern const u8 gAxChikorita[];
extern const u8 gAxBayleef[];
extern const u8 gAxMeganium[];
extern const u8 gAxCyndaquil[];
extern const u8 gAxQuilava[];
extern const u8 gAxTyphlosion[];
extern const u8 gAxTotodile[];
extern const u8 gAxCroconaw[];
extern const u8 gAxFeraligatr[];
extern const u8 gAxSentret[];
extern const u8 gAxFurret[];
extern const u8 gAxHoothoot[];
extern const u8 gAxNoctowl[];
extern const u8 gAxLedyba[];
extern const u8 gAxLedian[];
extern const u8 gAxSpinarak[];
extern const u8 gAxAriados[];
extern const u8 gAxCrobat[];
extern const u8 gAxChinchou[];
extern const u8 gAxLanturn[];
extern const u8 gAxPichu[];
extern const u8 gAxCleffa[];
extern const u8 gAxIgglybuff[];
extern const u8 gAxTogepi[];
extern const u8 gAxTogetic[];
extern const u8 gAxNatu[];
extern const u8 gAxXatu[];
extern const u8 gAxMareep[];
extern const u8 gAxFlaaffy[];
extern const u8 gAxAmpharos[];
extern const u8 gAxBellossom[];
extern const u8 gAxMarill[];
extern const u8 gAxAzumarill[];
extern const u8 gAxSudowoodo[];
extern const u8 gAxPolitoed[];
extern const u8 gAxHoppip[];
extern const u8 gAxSkiploom[];
extern const u8 gAxJumpluff[];
extern const u8 gAxAipom[];
extern const u8 gAxSunkern[];
extern const u8 gAxSunflora[];
extern const u8 gAxYanma[];
extern const u8 gAxWooper[];
extern const u8 gAxQuagsire[];
extern const u8 gAxEspeon[];
extern const u8 gAxUmbreon[];
extern const u8 gAxMurkrow[];
extern const u8 gAxSlowking[];
extern const u8 gAxMisdreavus[];
extern const u8 gAxUnownA[];
extern const u8 gAxUnownB[];
extern const u8 gAxUnownC[];
extern const u8 gAxUnownD[];
extern const u8 gAxUnownE[];
extern const u8 gAxUnownF[];
extern const u8 gAxUnownG[];
extern const u8 gAxUnownH[];
extern const u8 gAxUnownI[];
extern const u8 gAxUnownJ[];
extern const u8 gAxUnownK[];
extern const u8 gAxUnownL[];
extern const u8 gAxUnownM[];
extern const u8 gAxUnownN[];
extern const u8 gAxUnownO[];
extern const u8 gAxUnownP[];
extern const u8 gAxUnownQ[];
extern const u8 gAxUnownR[];
extern const u8 gAxUnownS[];
extern const u8 gAxUnownT[];
extern const u8 gAxUnownU[];
extern const u8 gAxUnownV[];
extern const u8 gAxUnownW[];
extern const u8 gAxUnownX[];
extern const u8 gAxUnownY[];
extern const u8 gAxUnownZ[];
extern const u8 gAxWobbuffet[];
extern const u8 gAxGirafarig[];
extern const u8 gAxPineco[];
extern const u8 gAxForretress[];
extern const u8 gAxDunsparce[];
extern const u8 gAxGligar[];
extern const u8 gAxSteelix[];
extern const u8 gAxSnubbull[];
extern const u8 gAxGranbull[];
extern const u8 gAxQwilfish[];
extern const u8 gAxScizor[];
extern const u8 gAxShuckle[];
extern const u8 gAxHeracross[];
extern const u8 gAxSneasel[];
extern const u8 gAxTeddiursa[];
extern const u8 gAxUrsaring[];
extern const u8 gAxSlugma[];
extern const u8 gAxMagcargo[];
extern const u8 gAxSwinub[];
extern const u8 gAxPiloswine[];
extern const u8 gAxCorsola[];
extern const u8 gAxRemoraid[];
extern const u8 gAxOctillery[];
extern const u8 gAxDelibird[];
extern const u8 gAxMantine[];
extern const u8 gAxSkarmory[];
extern const u8 gAxHoundour[];
extern const u8 gAxHoundoom[];
extern const u8 gAxKingdra[];
extern const u8 gAxPhanpy[];
extern const u8 gAxDonphan[];
extern const u8 gAxPorygon2[];
extern const u8 gAxStantler[];
extern const u8 gAxSmeargle[];
extern const u8 gAxTyrogue[];
extern const u8 gAxHitmontop[];
extern const u8 gAxSmoochum[];
extern const u8 gAxElekid[];
extern const u8 gAxMagby[];
extern const u8 gAxMiltank[];
extern const u8 gAxBlissey[];
extern const u8 gAxRaikou[];
extern const u8 gAxEntei[];
extern const u8 gAxSuicune[];
extern const u8 gAxLarvitar[];
extern const u8 gAxPupitar[];
extern const u8 gAxTyranitar[];
extern const u8 gAxLugia[];
extern const u8 gAxHoOh[];
extern const u8 gAxCelebi[];
extern const u8 gAxTreecko[];
extern const u8 gAxGrovyle[];
extern const u8 gAxSceptile[];
extern const u8 gAxTorchic[];
extern const u8 gAxCombusken[];
extern const u8 gAxBlaziken[];
extern const u8 gAxMudkip[];
extern const u8 gAxMarshtomp[];
extern const u8 gAxSwampert[];
extern const u8 gAxPoochyena[];
extern const u8 gAxMightyena[];
extern const u8 gAxZigzagoon[];
extern const u8 gAxLinoone[];
extern const u8 gAxWurmple[];
extern const u8 gAxSilcoon[];
extern const u8 gAxBeautifly[];
extern const u8 gAxCascoon[];
extern const u8 gAxDustox[];
extern const u8 gAxLotad[];
extern const u8 gAxLombre[];
extern const u8 gAxLudicolo[];
extern const u8 gAxSeedot[];
extern const u8 gAxNuzleaf[];
extern const u8 gAxShiftry[];
extern const u8 gAxTaillow[];
extern const u8 gAxSwellow[];
extern const u8 gAxWingull[];
extern const u8 gAxPelipper[];
extern const u8 gAxRalts[];
extern const u8 gAxKirlia[];
extern const u8 gAxGardevoir[];
extern const u8 gAxSurskit[];
extern const u8 gAxMasquerain[];
extern const u8 gAxShroomish[];
extern const u8 gAxBreloom[];
extern const u8 gAxSlakoth[];
extern const u8 gAxVigoroth[];
extern const u8 gAxSlaking[];
extern const u8 gAxNincada[];
extern const u8 gAxNinjask[];
extern const u8 gAxShedinja[];
extern const u8 gAxWhismur[];
extern const u8 gAxLoudred[];
extern const u8 gAxExploud[];
extern const u8 gAxMakuhita[];
extern const u8 gAxHariyama[];
extern const u8 gAxAzurill[];
extern const u8 gAxNosepass[];
extern const u8 gAxSkitty[];
extern const u8 gAxDelcatty[];
extern const u8 gAxSableye[];
extern const u8 gAxMawile[];
extern const u8 gAxAron[];
extern const u8 gAxLairon[];
extern const u8 gAxAggron[];
extern const u8 gAxMeditite[];
extern const u8 gAxMedicham[];
extern const u8 gAxElectrike[];
extern const u8 gAxManectric[];
extern const u8 gAxPlusle[];
extern const u8 gAxMinun[];
extern const u8 gAxVolbeat[];
extern const u8 gAxIllumise[];
extern const u8 gAxRoselia[];
extern const u8 gAxGulpin[];
extern const u8 gAxSwalot[];
extern const u8 gAxCarvanha[];
extern const u8 gAxSharpedo[];
extern const u8 gAxWailmer[];
extern const u8 gAxWailord[];
extern const u8 gAxNumel[];
extern const u8 gAxCamerupt[];
extern const u8 gAxTorkoal[];
extern const u8 gAxSpoink[];
extern const u8 gAxGrumpig[];
extern const u8 gAxSpinda[];
extern const u8 gAxTrapinch[];
extern const u8 gAxVibrava[];
extern const u8 gAxFlygon[];
extern const u8 gAxCacnea[];
extern const u8 gAxCacturne[];
extern const u8 gAxSwablu[];
extern const u8 gAxAltaria[];
extern const u8 gAxZangoose[];
extern const u8 gAxSeviper[];
extern const u8 gAxLunatone[];
extern const u8 gAxSolrock[];
extern const u8 gAxBarboach[];
extern const u8 gAxWhiscash[];
extern const u8 gAxCorphish[];
extern const u8 gAxCrawdaunt[];
extern const u8 gAxBaltoy[];
extern const u8 gAxClaydol[];
extern const u8 gAxLileep[];
extern const u8 gAxCradily[];
extern const u8 gAxAnorith[];
extern const u8 gAxArmaldo[];
extern const u8 gAxFeebas[];
extern const u8 gAxMilotic[];
extern const u8 gAxCastform[];
extern const u8 gAxCastformSnowy[];
extern const u8 gAxCastformSunny[];
extern const u8 gAxCastformRainy[];
extern const u8 gAxKecleon[];
extern const u8 gAxShuppet[];
extern const u8 gAxBanette[];
extern const u8 gAxDuskull[];
extern const u8 gAxDusclops[];
extern const u8 gAxTropius[];
extern const u8 gAxChimecho[];
extern const u8 gAxAbsol[];
extern const u8 gAxWynaut[];
extern const u8 gAxSnorunt[];
extern const u8 gAxGlalie[];
extern const u8 gAxSpheal[];
extern const u8 gAxSealeo[];
extern const u8 gAxWalrein[];
extern const u8 gAxClamperl[];
extern const u8 gAxHuntail[];
extern const u8 gAxGorebyss[];
extern const u8 gAxRelicanth[];
extern const u8 gAxLuvdisc[];
extern const u8 gAxBagon[];
extern const u8 gAxShelgon[];
extern const u8 gAxSalamence[];
extern const u8 gAxBeldum[];
extern const u8 gAxMetang[];
extern const u8 gAxMetagross[];
extern const u8 gAxRegirock[];
extern const u8 gAxRegice[];
extern const u8 gAxRegisteel[];
extern const u8 gAxLatias[];
extern const u8 gAxLatios[];
extern const u8 gAxKyogre[];
extern const u8 gAxGroudon[];
extern const u8 gAxRayquaza[];
extern const u8 gAxJirachi[];
extern const u8 gAxDeoxysNormal[];
extern const u8 gAxUnownEmark[];
extern const u8 gAxUnownQmark[];
extern const u8 gAxDeoxysAttack[];
extern const u8 gAxDeoxysDefense[];
extern const u8 gAxDeoxysSpeed[];
extern const u8 gAxMunchlax[];
extern const u8 gAxDecoy[];
extern const u8 gAxStatue[];
extern const u8 gAxRayquazaCutscene[];
extern const u8 gKaoBulbasaur[];
extern const u8 gKaoCharmander[];
extern const u8 gKaoCharizard[];
extern const u8 gKaoSquirtle[];
extern const u8 gKaoBlastoise[];
extern const u8 gKaoCaterpie[];
extern const u8 gKaoMetapod[];
extern const u8 gKaoButterfree[];
extern const u8 gKaoEkans[];
extern const u8 gKaoPikachu[];
extern const u8 gKaoNinetales[];
extern const u8 gKaoWigglytuff[];
extern const u8 gKaoDiglett[];
extern const u8 gKaoDugtrio[];
extern const u8 gKaoMeowth[];
extern const u8 gKaoPersian[];
extern const u8 gKaoPsyduck[];
extern const u8 gKaoMankey[];
extern const u8 gKaoAlakazam[];
extern const u8 gKaoMachop[];
extern const u8 gKaoBellsprout[];
extern const u8 gKaoGolem[];
extern const u8 gKaoMagnemite[];
extern const u8 gKaoGengar[];
extern const u8 gKaoCubone[];
extern const u8 gKaoKangaskhan[];
extern const u8 gKaoEevee[];
extern const u8 gKaoArticuno[];
extern const u8 gKaoZapdos[];
extern const u8 gKaoMoltres[];
extern const u8 gKaoMewtwo[];
extern const u8 gKaoChikorita[];
extern const u8 gKaoCyndaquil[];
extern const u8 gKaoTotodile[];
extern const u8 gKaoXatu[];
extern const u8 gKaoJumpluff[];
extern const u8 gKaoWobbuffet[];
extern const u8 gKaoSnubbull[];
extern const u8 gKaoGranbull[];
extern const u8 gKaoOctillery[];
extern const u8 gKaoSkarmory[];
extern const u8 gKaoSmeargle[];
extern const u8 gKaoRaikou[];
extern const u8 gKaoEntei[];
extern const u8 gKaoSuicune[];
extern const u8 gKaoTyranitar[];
extern const u8 gKaoLugia[];
extern const u8 gKaoHoOh[];
extern const u8 gKaoTreecko[];
extern const u8 gKaoTorchic[];
extern const u8 gKaoMudkip[];
extern const u8 gKaoLombre[];
extern const u8 gKaoShiftry[];
extern const u8 gKaoPelipper[];
extern const u8 gKaoGardevoir[];
extern const u8 gKaoMakuhita[];
extern const u8 gKaoSkitty[];
extern const u8 gKaoMedicham[];
extern const u8 gKaoGulpin[];
extern const u8 gKaoSpinda[];
extern const u8 gKaoWhiscash[];
extern const u8 gKaoKecleon[];
extern const u8 gKaoAbsol[];
extern const u8 gKaoWynaut[];
extern const u8 gKaoLatias[];
extern const u8 gKaoLatios[];
extern const u8 gKaoKyogre[];
extern const u8 gKaoGroudon[];
extern const u8 gKaoRayquaza[];
extern const u8 gKaoJirachi[];
extern const u8 gKaoDeoxysNormal[];
extern const u8 gKaoMunchlax[];
extern const u8 gKaoRayquazaCutscene[];
extern const u8 gPaletFile[];

const File gMonsterFiles[MONSTER_FILES_COUNT] = {
    [0] = { "ax001", gAxBulbasaur,},
    [1] = { "ax002", gAxIvysaur,},
    [2] = { "ax003", gAxVenusaur,},
    [3] = { "ax004", gAxCharmander,},
    [4] = { "ax005", gAxCharmeleon,},
    [5] = { "ax006", gAxCharizard,},
    [6] = { "ax007", gAxSquirtle,},
    [7] = { "ax008", gAxWartortle,},
    [8] = { "ax009", gAxBlastoise,},
    [9] = { "ax010", gAxCaterpie,},
    [10] = { "ax011", gAxMetapod,},
    [11] = { "ax012", gAxButterfree,},
    [12] = { "ax013", gAxWeedle,},
    [13] = { "ax014", gAxKakuna,},
    [14] = { "ax015", gAxBeedrill,},
    [15] = { "ax016", gAxPidgey,},
    [16] = { "ax017", gAxPidgeotto,},
    [17] = { "ax018", gAxPidgeot,},
    [18] = { "ax019", gAxRattata,},
    [19] = { "ax020", gAxRaticate,},
    [20] = { "ax021", gAxSpearow,},
    [21] = { "ax022", gAxFearow,},
    [22] = { "ax023", gAxEkans,},
    [23] = { "ax024", gAxArbok,},
    [24] = { "ax025", gAxPikachu,},
    [25] = { "ax026", gAxRaichu,},
    [26] = { "ax027", gAxSandshrew,},
    [27] = { "ax028", gAxSandslash,},
    [28] = { "ax029", gAxNidoranF,},
    [29] = { "ax030", gAxNidorina,},
    [30] = { "ax031", gAxNidoqueen,},
    [31] = { "ax032", gAxNidoranM,},
    [32] = { "ax033", gAxNidorino,},
    [33] = { "ax034", gAxNidoking,},
    [34] = { "ax035", gAxClefairy,},
    [35] = { "ax036", gAxClefable,},
    [36] = { "ax037", gAxVulpix,},
    [37] = { "ax038", gAxNinetales,},
    [38] = { "ax039", gAxJigglypuff,},
    [39] = { "ax040", gAxWigglytuff,},
    [40] = { "ax041", gAxZubat,},
    [41] = { "ax042", gAxGolbat,},
    [42] = { "ax043", gAxOddish,},
    [43] = { "ax044", gAxGloom,},
    [44] = { "ax045", gAxVileplume,},
    [45] = { "ax046", gAxParas,},
    [46] = { "ax047", gAxParasect,},
    [47] = { "ax048", gAxVenonat,},
    [48] = { "ax049", gAxVenomoth,},
    [49] = { "ax050", gAxDiglett,},
    [50] = { "ax051", gAxDugtrio,},
    [51] = { "ax052", gAxMeowth,},
    [52] = { "ax053", gAxPersian,},
    [53] = { "ax054", gAxPsyduck,},
    [54] = { "ax055", gAxGolduck,},
    [55] = { "ax056", gAxMankey,},
    [56] = { "ax057", gAxPrimeape,},
    [57] = { "ax058", gAxGrowlithe,},
    [58] = { "ax059", gAxArcanine,},
    [59] = { "ax060", gAxPoliwag,},
    [60] = { "ax061", gAxPoliwhirl,},
    [61] = { "ax062", gAxPoliwrath,},
    [62] = { "ax063", gAxAbra,},
    [63] = { "ax064", gAxKadabra,},
    [64] = { "ax065", gAxAlakazam,},
    [65] = { "ax066", gAxMachop,},
    [66] = { "ax067", gAxMachoke,},
    [67] = { "ax068", gAxMachamp,},
    [68] = { "ax069", gAxBellsprout,},
    [69] = { "ax070", gAxWeepinbell,},
    [70] = { "ax071", gAxVictreebel,},
    [71] = { "ax072", gAxTentacool,},
    [72] = { "ax073", gAxTentacruel,},
    [73] = { "ax074", gAxGeodude,},
    [74] = { "ax075", gAxGraveler,},
    [75] = { "ax076", gAxGolem,},
    [76] = { "ax077", gAxPonyta,},
    [77] = { "ax078", gAxRapidash,},
    [78] = { "ax079", gAxSlowpoke,},
    [79] = { "ax080", gAxSlowbro,},
    [80] = { "ax081", gAxMagnemite,},
    [81] = { "ax082", gAxMagneton,},
    [82] = { "ax083", gAxFarfetchd,},
    [83] = { "ax084", gAxDoduo,},
    [84] = { "ax085", gAxDodrio,},
    [85] = { "ax086", gAxSeel,},
    [86] = { "ax087", gAxDewgong,},
    [87] = { "ax088", gAxGrimer,},
    [88] = { "ax089", gAxMuk,},
    [89] = { "ax090", gAxShellder,},
    [90] = { "ax091", gAxCloyster,},
    [91] = { "ax092", gAxGastly,},
    [92] = { "ax093", gAxHaunter,},
    [93] = { "ax094", gAxGengar,},
    [94] = { "ax095", gAxOnix,},
    [95] = { "ax096", gAxDrowzee,},
    [96] = { "ax097", gAxHypno,},
    [97] = { "ax098", gAxKrabby,},
    [98] = { "ax099", gAxKingler,},
    [99] = { "ax100", gAxVoltorb,},
    [100] = { "ax101", gAxElectrode,},
    [101] = { "ax102", gAxExeggcute,},
    [102] = { "ax103", gAxExeggutor,},
    [103] = { "ax104", gAxCubone,},
    [104] = { "ax105", gAxMarowak,},
    [105] = { "ax106", gAxHitmonlee,},
    [106] = { "ax107", gAxHitmonchan,},
    [107] = { "ax108", gAxLickitung,},
    [108] = { "ax109", gAxKoffing,},
    [109] = { "ax110", gAxWeezing,},
    [110] = { "ax111", gAxRhyhorn,},
    [111] = { "ax112", gAxRhydon,},
    [112] = { "ax113", gAxChansey,},
    [113] = { "ax114", gAxTangela,},
    [114] = { "ax115", gAxKangaskhan,},
    [115] = { "ax116", gAxHorsea,},
    [116] = { "ax117", gAxSeadra,},
    [117] = { "ax118", gAxGoldeen,},
    [118] = { "ax119", gAxSeaking,},
    [119] = { "ax120", gAxStaryu,},
    [120] = { "ax121", gAxStarmie,},
    [121] = { "ax122", gAxMrMime,},
    [122] = { "ax123", gAxScyther,},
    [123] = { "ax124", gAxJynx,},
    [124] = { "ax125", gAxElectabuzz,},
    [125] = { "ax126", gAxMagmar,},
    [126] = { "ax127", gAxPinsir,},
    [127] = { "ax128", gAxTauros,},
    [128] = { "ax129", gAxMagikarp,},
    [129] = { "ax130", gAxGyarados,},
    [130] = { "ax131", gAxLapras,},
    [131] = { "ax132", gAxDitto,},
    [132] = { "ax133", gAxEevee,},
    [133] = { "ax134", gAxVaporeon,},
    [134] = { "ax135", gAxJolteon,},
    [135] = { "ax136", gAxFlareon,},
    [136] = { "ax137", gAxPorygon,},
    [137] = { "ax138", gAxOmanyte,},
    [138] = { "ax139", gAxOmastar,},
    [139] = { "ax140", gAxKabuto,},
    [140] = { "ax141", gAxKabutops,},
    [141] = { "ax142", gAxAerodactyl,},
    [142] = { "ax143", gAxSnorlax,},
    [143] = { "ax144", gAxArticuno,},
    [144] = { "ax145", gAxZapdos,},
    [145] = { "ax146", gAxMoltres,},
    [146] = { "ax147", gAxDratini,},
    [147] = { "ax148", gAxDragonair,},
    [148] = { "ax149", gAxDragonite,},
    [149] = { "ax150", gAxMewtwo,},
    [150] = { "ax151", gAxMew,},
    [151] = { "ax152", gAxChikorita,},
    [152] = { "ax153", gAxBayleef,},
    [153] = { "ax154", gAxMeganium,},
    [154] = { "ax155", gAxCyndaquil,},
    [155] = { "ax156", gAxQuilava,},
    [156] = { "ax157", gAxTyphlosion,},
    [157] = { "ax158", gAxTotodile,},
    [158] = { "ax159", gAxCroconaw,},
    [159] = { "ax160", gAxFeraligatr,},
    [160] = { "ax161", gAxSentret,},
    [161] = { "ax162", gAxFurret,},
    [162] = { "ax163", gAxHoothoot,},
    [163] = { "ax164", gAxNoctowl,},
    [164] = { "ax165", gAxLedyba,},
    [165] = { "ax166", gAxLedian,},
    [166] = { "ax167", gAxSpinarak,},
    [167] = { "ax168", gAxAriados,},
    [168] = { "ax169", gAxCrobat,},
    [169] = { "ax170", gAxChinchou,},
    [170] = { "ax171", gAxLanturn,},
    [171] = { "ax172", gAxPichu,},
    [172] = { "ax173", gAxCleffa,},
    [173] = { "ax174", gAxIgglybuff,},
    [174] = { "ax175", gAxTogepi,},
    [175] = { "ax176", gAxTogetic,},
    [176] = { "ax177", gAxNatu,},
    [177] = { "ax178", gAxXatu,},
    [178] = { "ax179", gAxMareep,},
    [179] = { "ax180", gAxFlaaffy,},
    [180] = { "ax181", gAxAmpharos,},
    [181] = { "ax182", gAxBellossom,},
    [182] = { "ax183", gAxMarill,},
    [183] = { "ax184", gAxAzumarill,},
    [184] = { "ax185", gAxSudowoodo,},
    [185] = { "ax186", gAxPolitoed,},
    [186] = { "ax187", gAxHoppip,},
    [187] = { "ax188", gAxSkiploom,},
    [188] = { "ax189", gAxJumpluff,},
    [189] = { "ax190", gAxAipom,},
    [190] = { "ax191", gAxSunkern,},
    [191] = { "ax192", gAxSunflora,},
    [192] = { "ax193", gAxYanma,},
    [193] = { "ax194", gAxWooper,},
    [194] = { "ax195", gAxQuagsire,},
    [195] = { "ax196", gAxEspeon,},
    [196] = { "ax197", gAxUmbreon,},
    [197] = { "ax198", gAxMurkrow,},
    [198] = { "ax199", gAxSlowking,},
    [199] = { "ax200", gAxMisdreavus,},
    [200] = { "ax201", gAxUnownA,},
    [201] = { "ax202", gAxUnownB,},
    [202] = { "ax203", gAxUnownC,},
    [203] = { "ax204", gAxUnownD,},
    [204] = { "ax205", gAxUnownE,},
    [205] = { "ax206", gAxUnownF,},
    [206] = { "ax207", gAxUnownG,},
    [207] = { "ax208", gAxUnownH,},
    [208] = { "ax209", gAxUnownI,},
    [209] = { "ax210", gAxUnownJ,},
    [210] = { "ax211", gAxUnownK,},
    [211] = { "ax212", gAxUnownL,},
    [212] = { "ax213", gAxUnownM,},
    [213] = { "ax214", gAxUnownN,},
    [214] = { "ax215", gAxUnownO,},
    [215] = { "ax216", gAxUnownP,},
    [216] = { "ax217", gAxUnownQ,},
    [217] = { "ax218", gAxUnownR,},
    [218] = { "ax219", gAxUnownS,},
    [219] = { "ax220", gAxUnownT,},
    [220] = { "ax221", gAxUnownU,},
    [221] = { "ax222", gAxUnownV,},
    [222] = { "ax223", gAxUnownW,},
    [223] = { "ax224", gAxUnownX,},
    [224] = { "ax225", gAxUnownY,},
    [225] = { "ax226", gAxUnownZ,},
    [226] = { "ax227", gAxWobbuffet,},
    [227] = { "ax228", gAxGirafarig,},
    [228] = { "ax229", gAxPineco,},
    [229] = { "ax230", gAxForretress,},
    [230] = { "ax231", gAxDunsparce,},
    [231] = { "ax232", gAxGligar,},
    [232] = { "ax233", gAxSteelix,},
    [233] = { "ax234", gAxSnubbull,},
    [234] = { "ax235", gAxGranbull,},
    [235] = { "ax236", gAxQwilfish,},
    [236] = { "ax237", gAxScizor,},
    [237] = { "ax238", gAxShuckle,},
    [238] = { "ax239", gAxHeracross,},
    [239] = { "ax240", gAxSneasel,},
    [240] = { "ax241", gAxTeddiursa,},
    [241] = { "ax242", gAxUrsaring,},
    [242] = { "ax243", gAxSlugma,},
    [243] = { "ax244", gAxMagcargo,},
    [244] = { "ax245", gAxSwinub,},
    [245] = { "ax246", gAxPiloswine,},
    [246] = { "ax247", gAxCorsola,},
    [247] = { "ax248", gAxRemoraid,},
    [248] = { "ax249", gAxOctillery,},
    [249] = { "ax250", gAxDelibird,},
    [250] = { "ax251", gAxMantine,},
    [251] = { "ax252", gAxSkarmory,},
    [252] = { "ax253", gAxHoundour,},
    [253] = { "ax254", gAxHoundoom,},
    [254] = { "ax255", gAxKingdra,},
    [255] = { "ax256", gAxPhanpy,},
    [256] = { "ax257", gAxDonphan,},
    [257] = { "ax258", gAxPorygon2,},
    [258] = { "ax259", gAxStantler,},
    [259] = { "ax260", gAxSmeargle,},
    [260] = { "ax261", gAxTyrogue,},
    [261] = { "ax262", gAxHitmontop,},
    [262] = { "ax263", gAxSmoochum,},
    [263] = { "ax264", gAxElekid,},
    [264] = { "ax265", gAxMagby,},
    [265] = { "ax266", gAxMiltank,},
    [266] = { "ax267", gAxBlissey,},
    [267] = { "ax268", gAxRaikou,},
    [268] = { "ax269", gAxEntei,},
    [269] = { "ax270", gAxSuicune,},
    [270] = { "ax271", gAxLarvitar,},
    [271] = { "ax272", gAxPupitar,},
    [272] = { "ax273", gAxTyranitar,},
    [273] = { "ax274", gAxLugia,},
    [274] = { "ax275", gAxHoOh,},
    [275] = { "ax276", gAxCelebi,},
    [276] = { "ax277", gAxTreecko,},
    [277] = { "ax278", gAxGrovyle,},
    [278] = { "ax279", gAxSceptile,},
    [279] = { "ax280", gAxTorchic,},
    [280] = { "ax281", gAxCombusken,},
    [281] = { "ax282", gAxBlaziken,},
    [282] = { "ax283", gAxMudkip,},
    [283] = { "ax284", gAxMarshtomp,},
    [284] = { "ax285", gAxSwampert,},
    [285] = { "ax286", gAxPoochyena,},
    [286] = { "ax287", gAxMightyena,},
    [287] = { "ax288", gAxZigzagoon,},
    [288] = { "ax289", gAxLinoone,},
    [289] = { "ax290", gAxWurmple,},
    [290] = { "ax291", gAxSilcoon,},
    [291] = { "ax292", gAxBeautifly,},
    [292] = { "ax293", gAxCascoon,},
    [293] = { "ax294", gAxDustox,},
    [294] = { "ax295", gAxLotad,},
    [295] = { "ax296", gAxLombre,},
    [296] = { "ax297", gAxLudicolo,},
    [297] = { "ax298", gAxSeedot,},
    [298] = { "ax299", gAxNuzleaf,},
    [299] = { "ax300", gAxShiftry,},
    [300] = { "ax301", gAxTaillow,},
    [301] = { "ax302", gAxSwellow,},
    [302] = { "ax303", gAxWingull,},
    [303] = { "ax304", gAxPelipper,},
    [304] = { "ax305", gAxRalts,},
    [305] = { "ax306", gAxKirlia,},
    [306] = { "ax307", gAxGardevoir,},
    [307] = { "ax308", gAxSurskit,},
    [308] = { "ax309", gAxMasquerain,},
    [309] = { "ax310", gAxShroomish,},
    [310] = { "ax311", gAxBreloom,},
    [311] = { "ax312", gAxSlakoth,},
    [312] = { "ax313", gAxVigoroth,},
    [313] = { "ax314", gAxSlaking,},
    [314] = { "ax315", gAxNincada,},
    [315] = { "ax316", gAxNinjask,},
    [316] = { "ax317", gAxShedinja,},
    [317] = { "ax318", gAxWhismur,},
    [318] = { "ax319", gAxLoudred,},
    [319] = { "ax320", gAxExploud,},
    [320] = { "ax321", gAxMakuhita,},
    [321] = { "ax322", gAxHariyama,},
    [322] = { "ax323", gAxAzurill,},
    [323] = { "ax324", gAxNosepass,},
    [324] = { "ax325", gAxSkitty,},
    [325] = { "ax326", gAxDelcatty,},
    [326] = { "ax327", gAxSableye,},
    [327] = { "ax328", gAxMawile,},
    [328] = { "ax329", gAxAron,},
    [329] = { "ax330", gAxLairon,},
    [330] = { "ax331", gAxAggron,},
    [331] = { "ax332", gAxMeditite,},
    [332] = { "ax333", gAxMedicham,},
    [333] = { "ax334", gAxElectrike,},
    [334] = { "ax335", gAxManectric,},
    [335] = { "ax336", gAxPlusle,},
    [336] = { "ax337", gAxMinun,},
    [337] = { "ax338", gAxVolbeat,},
    [338] = { "ax339", gAxIllumise,},
    [339] = { "ax340", gAxRoselia,},
    [340] = { "ax341", gAxGulpin,},
    [341] = { "ax342", gAxSwalot,},
    [342] = { "ax343", gAxCarvanha,},
    [343] = { "ax344", gAxSharpedo,},
    [344] = { "ax345", gAxWailmer,},
    [345] = { "ax346", gAxWailord,},
    [346] = { "ax347", gAxNumel,},
    [347] = { "ax348", gAxCamerupt,},
    [348] = { "ax349", gAxTorkoal,},
    [349] = { "ax350", gAxSpoink,},
    [350] = { "ax351", gAxGrumpig,},
    [351] = { "ax352", gAxSpinda,},
    [352] = { "ax353", gAxTrapinch,},
    [353] = { "ax354", gAxVibrava,},
    [354] = { "ax355", gAxFlygon,},
    [355] = { "ax356", gAxCacnea,},
    [356] = { "ax357", gAxCacturne,},
    [357] = { "ax358", gAxSwablu,},
    [358] = { "ax359", gAxAltaria,},
    [359] = { "ax360", gAxZangoose,},
    [360] = { "ax361", gAxSeviper,},
    [361] = { "ax362", gAxLunatone,},
    [362] = { "ax363", gAxSolrock,},
    [363] = { "ax364", gAxBarboach,},
    [364] = { "ax365", gAxWhiscash,},
    [365] = { "ax366", gAxCorphish,},
    [366] = { "ax367", gAxCrawdaunt,},
    [367] = { "ax368", gAxBaltoy,},
    [368] = { "ax369", gAxClaydol,},
    [369] = { "ax370", gAxLileep,},
    [370] = { "ax371", gAxCradily,},
    [371] = { "ax372", gAxAnorith,},
    [372] = { "ax373", gAxArmaldo,},
    [373] = { "ax374", gAxFeebas,},
    [374] = { "ax375", gAxMilotic,},
    [375] = { "ax376", gAxCastform,},
    [376] = { "ax377", gAxCastformSnowy,},
    [377] = { "ax378", gAxCastformSunny,},
    [378] = { "ax379", gAxCastformRainy,},
    [379] = { "ax380", gAxKecleon,},
    [380] = { "ax381", gAxShuppet,},
    [381] = { "ax382", gAxBanette,},
    [382] = { "ax383", gAxDuskull,},
    [383] = { "ax384", gAxDusclops,},
    [384] = { "ax385", gAxTropius,},
    [385] = { "ax386", gAxChimecho,},
    [386] = { "ax387", gAxAbsol,},
    [387] = { "ax388", gAxWynaut,},
    [388] = { "ax389", gAxSnorunt,},
    [389] = { "ax390", gAxGlalie,},
    [390] = { "ax391", gAxSpheal,},
    [391] = { "ax392", gAxSealeo,},
    [392] = { "ax393", gAxWalrein,},
    [393] = { "ax394", gAxClamperl,},
    [394] = { "ax395", gAxHuntail,},
    [395] = { "ax396", gAxGorebyss,},
    [396] = { "ax397", gAxRelicanth,},
    [397] = { "ax398", gAxLuvdisc,},
    [398] = { "ax399", gAxBagon,},
    [399] = { "ax400", gAxShelgon,},
    [400] = { "ax401", gAxSalamence,},
    [401] = { "ax402", gAxBeldum,},
    [402] = { "ax403", gAxMetang,},
    [403] = { "ax404", gAxMetagross,},
    [404] = { "ax405", gAxRegirock,},
    [405] = { "ax406", gAxRegice,},
    [406] = { "ax407", gAxRegisteel,},
    [407] = { "ax408", gAxLatias,},
    [408] = { "ax409", gAxLatios,},
    [409] = { "ax410", gAxKyogre,},
    [410] = { "ax411", gAxGroudon,},
    [411] = { "ax412", gAxRayquaza,},
    [412] = { "ax413", gAxJirachi,},
    [413] = { "ax414", gAxDeoxysNormal,},
    [414] = { "ax415", gAxUnownEmark,},
    [415] = { "ax416", gAxUnownQmark,},
    [416] = { "ax417", gAxDeoxysAttack,},
    [417] = { "ax418", gAxDeoxysDefense,},
    [418] = { "ax419", gAxDeoxysSpeed,},
    [419] = { "ax420", gAxMunchlax,},
    [420] = { "ax421", gAxDecoy,},
    [421] = { "ax422", gAxStatue,},
    [422] = { "ax423", gAxRayquazaCutscene,},
    [423] = { "kao001", gKaoBulbasaur,},
    [424] = { "kao004", gKaoCharmander,},
    [425] = { "kao006", gKaoCharizard,},
    [426] = { "kao007", gKaoSquirtle,},
    [427] = { "kao009", gKaoBlastoise,},
    [428] = { "kao010", gKaoCaterpie,},
    [429] = { "kao011", gKaoMetapod,},
    [430] = { "kao012", gKaoButterfree,},
    [431] = { "kao023", gKaoEkans,},
    [432] = { "kao025", gKaoPikachu,},
    [433] = { "kao038", gKaoNinetales,},
    [434] = { "kao040", gKaoWigglytuff,},
    [435] = { "kao050", gKaoDiglett,},
    [436] = { "kao051", gKaoDugtrio,},
    [437] = { "kao052", gKaoMeowth,},
    [438] = { "kao053", gKaoPersian,},
    [439] = { "kao054", gKaoPsyduck,},
    [440] = { "kao056", gKaoMankey,},
    [441] = { "kao065", gKaoAlakazam,},
    [442] = { "kao066", gKaoMachop,},
    [443] = { "kao069", gKaoBellsprout,},
    [444] = { "kao076", gKaoGolem,},
    [445] = { "kao081", gKaoMagnemite,},
    [446] = { "kao094", gKaoGengar,},
    [447] = { "kao104", gKaoCubone,},
    [448] = { "kao115", gKaoKangaskhan,},
    [449] = { "kao133", gKaoEevee,},
    [450] = { "kao144", gKaoArticuno,},
    [451] = { "kao145", gKaoZapdos,},
    [452] = { "kao146", gKaoMoltres,},
    [453] = { "kao150", gKaoMewtwo,},
    [454] = { "kao152", gKaoChikorita,},
    [455] = { "kao155", gKaoCyndaquil,},
    [456] = { "kao158", gKaoTotodile,},
    [457] = { "kao178", gKaoXatu,},
    [458] = { "kao189", gKaoJumpluff,},
    [459] = { "kao227", gKaoWobbuffet,},
    [460] = { "kao234", gKaoSnubbull,},
    [461] = { "kao235", gKaoGranbull,},
    [462] = { "kao249", gKaoOctillery,},
    [463] = { "kao252", gKaoSkarmory,},
    [464] = { "kao260", gKaoSmeargle,},
    [465] = { "kao268", gKaoRaikou,},
    [466] = { "kao269", gKaoEntei,},
    [467] = { "kao270", gKaoSuicune,},
    [468] = { "kao273", gKaoTyranitar,},
    [469] = { "kao274", gKaoLugia,},
    [470] = { "kao275", gKaoHoOh,},
    [471] = { "kao277", gKaoTreecko,},
    [472] = { "kao280", gKaoTorchic,},
    [473] = { "kao283", gKaoMudkip,},
    [474] = { "kao296", gKaoLombre,},
    [475] = { "kao300", gKaoShiftry,},
    [476] = { "kao304", gKaoPelipper,},
    [477] = { "kao307", gKaoGardevoir,},
    [478] = { "kao321", gKaoMakuhita,},
    [479] = { "kao325", gKaoSkitty,},
    [480] = { "kao333", gKaoMedicham,},
    [481] = { "kao341", gKaoGulpin,},
    [482] = { "kao352", gKaoSpinda,},
    [483] = { "kao365", gKaoWhiscash,},
    [484] = { "kao380", gKaoKecleon,},
    [485] = { "kao387", gKaoAbsol,},
    [486] = { "kao388", gKaoWynaut,},
    [487] = { "kao408", gKaoLatias,},
    [488] = { "kao409", gKaoLatios,},
    [489] = { "kao410", gKaoKyogre,},
    [490] = { "kao411", gKaoGroudon,},
    [491] = { "kao412", gKaoRayquaza,},
    [492] = { "kao413", gKaoJirachi,},
    [493] = { "kao414", gKaoDeoxysNormal,},
    [494] = { "kao420", gKaoMunchlax,},
    [495] = { "kao423", gKaoRayquazaCutscene,},
    [496] = { "palet", gPaletFile,},
};

UNUSED ALIGNED(4) static const char sPksDir3[] = "pksdir0";
