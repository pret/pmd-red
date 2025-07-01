#include "global.h"
#include "file_system.h"
#include "decompress_sir.h"

#define MONSTER_FILES_COUNT 497

extern const File gMonsterFiles[MONSTER_FILES_COUNT];

const FileArchive gMonsterFileArchive = {
    .magic = "pksdir0",
    .count = MONSTER_FILES_COUNT,
    .entries = gMonsterFiles,
};

UNUSED static const char sPksDir2[] = "pksdir0";

// Todo: create a directory/file for the mon sprites
extern const SiroArchive gAxBulbasaur;
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
extern const u8 gAxMonsPalette[];

const File gMonsterFiles[MONSTER_FILES_COUNT] = {
    [0] = { "ax001", &gAxBulbasaur,},
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
    [496] = { "palet", gAxMonsPalette,},
};

UNUSED ALIGNED(4) static const char sPksDir3[] = "pksdir0";

#define ST_OAM_SIZE_0   0
#define ST_OAM_SIZE_1   1
#define ST_OAM_SIZE_2   2
#define ST_OAM_SIZE_3   3

#include "structs/axdata.h"
#include "structs/sprite_oam.h"

#define AX_POSE(spriteId, f1, f2, f3){ .sprite = spriteId, .unk2 = {0, 0}, .flags1 = f1, .flags2 = f2, .flags3 = f3 }
#define AX_POSE_TERMINATOR { .sprite = -1, .unk2 = {-1, -1}, .flags1 = 0xFFFF, .flags2 = 0xFFFF, .flags3 = 0xFFFF }

// The unk flag is unused(it's copied to SpriteOAM's unk6 field), but it's actually not part of OAM flags1.
#define OAM1(y, shape, unk)((y & 0xFF) | ((shape & SPRITEOAM_MAX_SHAPE) << SPRITEOAM_SHIFT_SHAPE) | (unk << 8) )
// unk1 and unk2 are not part of oam flags2.
#define OAM2(x, size, flip, unk1, unk2)(((x & SPRITEOAM_MAX_X) << SPRITEOAM_SHIFT_X) | ((size & SPRITEOAM_MAX_SIZE) << SPRITEOAM_SHIFT_SIZE) | (flip << (SPRITEOAM_SHIFT_MATRIXNUM + SPRITEOAM_SHIFT_H_FLIP_MATRIXNUM)) | (unk1 << 9) | (unk2 << 8))
#define FLIP(h, v)((0 | ((h) ? 1 : 0) | ((v) ? 2 : 0)))

// It seems priority is always 3, palNum is the same as the overworld palette field in the monster data. Tilenum is 0 for normal sprites, and other values for stitched together sprites.
#define OAM3(tileNum, prio, palNum)(((tileNum & SPRITEOAM_MAX_TILENUM) << SPRITEOAM_SHIFT_TILENUM) | ((prio & SPRITEOAM_MAX_PRIORITY) << SPRITEOAM_SHIFT_PRIORITY) | ((palNum & SPRITEOAM_MAX_PALETTENUM) << SPRITEOAM_SHIFT_PALETTENUM))

#define AX_ANIM_TERMINATOR {0}
/*
static const axmain sAxMainBulbasaur;
const SiroArchive gAxBulbasaur = {"SIRO", &sAxMainBulbasaur};

static const ax_pose sBulbasaurPose1[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose2[] = {
	AX_POSE(1, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose3[] = {
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose4[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose5[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose6[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose7[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose8[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose9[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose10[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose11[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose12[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose13[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose14[] = {
	AX_POSE(13, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose15[] = {
	AX_POSE(14, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose16[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose17[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose18[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose19[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose20[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose21[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose22[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose23[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose24[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose25[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose26[] = {
	AX_POSE(1, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose27[] = {
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose28[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose29[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose30[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose31[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose32[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose33[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose34[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose35[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose36[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose37[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose38[] = {
	AX_POSE(13, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose39[] = {
	AX_POSE(14, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose40[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose41[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose42[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose43[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose44[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose45[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose46[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose47[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose48[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose49[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose50[] = {
	AX_POSE(1, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose51[] = {
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose52[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose53[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose54[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose55[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose56[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose57[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose58[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose59[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose60[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose61[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose62[] = {
	AX_POSE(13, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose63[] = {
	AX_POSE(14, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose64[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose65[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose66[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose67[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose68[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose69[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose70[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose71[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose72[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose73[] = {
	AX_POSE(15, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose74[] = {
	AX_POSE(16, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose75[] = {
	AX_POSE(17, OAM1(237, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose76[] = {
	AX_POSE(18, OAM1(237, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose77[] = {
	AX_POSE(19, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose78[] = {
	AX_POSE(20, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose79[] = {
	AX_POSE(21, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose80[] = {
	AX_POSE(22, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose81[] = {
	AX_POSE(23, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose82[] = {
	AX_POSE(24, OAM1(235, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose83[] = {
	AX_POSE(21, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose84[] = {
	AX_POSE(22, OAM1(233, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose85[] = {
	AX_POSE(19, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose86[] = {
	AX_POSE(20, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose87[] = {
	AX_POSE(17, OAM1(237, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose88[] = {
	AX_POSE(18, OAM1(237, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose89[] = {
	AX_POSE(25, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose90[] = {
	AX_POSE(26, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose91[] = {
	AX_POSE(27, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose92[] = {
	AX_POSE(28, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose93[] = {
	AX_POSE(29, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose94[] = {
	AX_POSE(30, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose95[] = {
	AX_POSE(31, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose96[] = {
	AX_POSE(32, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose97[] = {
	AX_POSE(33, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose98[] = {
	AX_POSE(34, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose99[] = {
	AX_POSE(31, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose100[] = {
	AX_POSE(32, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose101[] = {
	AX_POSE(29, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose102[] = {
	AX_POSE(30, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose103[] = {
	AX_POSE(27, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose104[] = {
	AX_POSE(28, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose105[] = {
	AX_POSE(35, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose106[] = {
	AX_POSE(36, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose107[] = {
	AX_POSE(37, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose108[] = {
	AX_POSE(38, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose109[] = {
	AX_POSE(39, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose110[] = {
	AX_POSE(40, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose111[] = {
	AX_POSE(41, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose112[] = {
	AX_POSE(40, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose113[] = {
	AX_POSE(39, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose114[] = {
	AX_POSE(38, OAM1(230, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose115[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose116[] = {
	AX_POSE(1, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose117[] = {
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose118[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose119[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose120[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose121[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose122[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose123[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose124[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose125[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose126[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose127[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose128[] = {
	AX_POSE(13, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose129[] = {
	AX_POSE(14, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose130[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose131[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose132[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose133[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose134[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose135[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose136[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose137[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose138[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose139[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose140[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose141[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose142[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose143[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose144[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose145[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose146[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose147[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose148[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose149[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose150[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose151[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose152[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose153[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose154[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose155[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose156[] = {
	AX_POSE(1, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose157[] = {
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose158[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose159[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose160[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose161[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose162[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose163[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose164[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose165[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose166[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose167[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose168[] = {
	AX_POSE(13, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose169[] = {
	AX_POSE(14, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose170[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose171[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose172[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose173[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose174[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose175[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose176[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose177[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose178[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose179[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose180[] = {
	AX_POSE(1, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose181[] = {
	AX_POSE(2, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose182[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose183[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose184[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose185[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose186[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose187[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose188[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose189[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose190[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose191[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose192[] = {
	AX_POSE(13, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose193[] = {
	AX_POSE(14, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose194[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose195[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose196[] = {
	AX_POSE(11, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose197[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose198[] = {
	AX_POSE(7, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose199[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose200[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose201[] = {
	AX_POSE(4, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose202[] = {
	AX_POSE(5, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose203[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose204[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose205[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose206[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose207[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose208[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose209[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose210[] = {
	AX_POSE(3, OAM1(238, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose211[] = {
	AX_POSE(42, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose212[] = {
	AX_POSE(43, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose213[] = {
	AX_POSE(42, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose214[] = {
	AX_POSE(43, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose215[] = {
	AX_POSE(42, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose216[] = {
	AX_POSE(44, OAM1(237, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose217[] = {
	AX_POSE(45, OAM1(237, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose218[] = {
	AX_POSE(46, OAM1(237, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose219[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose220[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose221[] = {
	AX_POSE(47, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose222[] = {
	AX_POSE(48, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose223[] = {
	AX_POSE(49, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose224[] = {
	AX_POSE(50, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose225[] = {
	AX_POSE(51, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose226[] = {
	AX_POSE(50, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose227[] = {
	AX_POSE(52, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose228[] = {
	AX_POSE(53, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose229[] = {
	AX_POSE(54, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose230[] = {
	AX_POSE(55, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose231[] = {
	AX_POSE(56, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose232[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose233[] = {
	AX_POSE(57, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose234[] = {
	AX_POSE(58, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(238, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose235[] = {
	AX_POSE(12, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose236[] = {
	AX_POSE(59, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose237[] = {
	AX_POSE(60, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose238[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose239[] = {
	AX_POSE(61, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose240[] = {
	AX_POSE(62, OAM1(234, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose241[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose242[] = {
	AX_POSE(63, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose243[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose244[] = {
	AX_POSE(63, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose245[] = {
	AX_POSE(64, OAM1(231, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose246[] = {
	AX_POSE(65, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose247[] = {
	AX_POSE(66, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose248[] = {
	AX_POSE(67, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose249[] = {
	AX_POSE(68, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose250[] = {
	AX_POSE(69, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose251[] = {
	AX_POSE(65, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose252[] = {
	AX_POSE(66, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose253[] = {
	AX_POSE(67, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose254[] = {
	AX_POSE(68, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose255[] = {
	AX_POSE(69, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(239, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose256[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose257[] = {
	AX_POSE(70, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose258[] = {
	AX_POSE(9, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose259[] = {
	AX_POSE(70, OAM1(232, ST_OAM_SQUARE     , 1), OAM2(237, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose260[] = {
	AX_POSE(42, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose261[] = {
	AX_POSE(43, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose262[] = {
	AX_POSE(42, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose263[] = {
	AX_POSE(43, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose264[] = {
	AX_POSE(42, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose265[] = {
	AX_POSE(43, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose266[] = {
	AX_POSE(42, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sBulbasaurPose267[] = {
	AX_POSE(43, OAM1(239, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, -2}, .shadow = {0, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, -3}, .shadow = {0, 3} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, -1}, .shadow = {0, 4} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 2}, .shadow = {0, 2} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_2[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {2, -1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {3, -2}, .shadow = {2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {4, -3}, .shadow = {3, 3} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {5, 1}, .shadow = {4, 4} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {5, 2}, .shadow = {5, 2} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_3[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 6, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 7, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 7, .offset = {1, -2}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 8, .offset = {2, -4}, .shadow = {2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 8, .offset = {3, -1}, .shadow = {3, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 6, .offset = {4, 0}, .shadow = {4, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_4[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 9, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 10, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 10, .offset = {3, -4}, .shadow = {3, -3} },
	{ .frames = 4, .unkFlags = 0, .poseId = 11, .offset = {3, -3}, .shadow = {4, -4} },
	{ .frames = 4, .unkFlags = 0, .poseId = 11, .offset = {4, -2}, .shadow = {5, -5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 9, .offset = {5, -3}, .shadow = {5, -5} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_5[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 12, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 13, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 13, .offset = {0, -3}, .shadow = {0, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 14, .offset = {0, -4}, .shadow = {0, -3} },
	{ .frames = 4, .unkFlags = 0, .poseId = 14, .offset = {0, -2}, .shadow = {0, -4} },
	{ .frames = 4, .unkFlags = 0, .poseId = 12, .offset = {0, -2}, .shadow = {0, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_6[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 15, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 16, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 16, .offset = {-3, -4}, .shadow = {-3, -3} },
	{ .frames = 4, .unkFlags = 0, .poseId = 17, .offset = {-3, -3}, .shadow = {-4, -4} },
	{ .frames = 4, .unkFlags = 0, .poseId = 17, .offset = {-4, -2}, .shadow = {-5, -5} },
	{ .frames = 4, .unkFlags = 0, .poseId = 15, .offset = {-5, -3}, .shadow = {-5, -5} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_7[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 18, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 19, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 19, .offset = {-1, -2}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 20, .offset = {-2, -4}, .shadow = {-2, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 20, .offset = {-3, -1}, .shadow = {-3, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 18, .offset = {-4, 0}, .shadow = {-4, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_1_8[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 21, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 22, .offset = {-2, -1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 22, .offset = {-3, -2}, .shadow = {-2, 2} },
	{ .frames = 4, .unkFlags = 0, .poseId = 23, .offset = {-4, -3}, .shadow = {-3, 3} },
	{ .frames = 4, .unkFlags = 0, .poseId = 23, .offset = {-5, 1}, .shadow = {-4, 4} },
	{ .frames = 4, .unkFlags = 0, .poseId = 21, .offset = {-5, 2}, .shadow = {-5, 2} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 24, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 24, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 24, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 25, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 25, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 26, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 26, .offset = {0, 18}, .shadow = {0, 18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 26, .offset = {1, 18}, .shadow = {1, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 26, .offset = {0, 18}, .shadow = {0, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 26, .offset = {1, 18}, .shadow = {1, 18} },
	{ .frames = 4, .unkFlags = 0, .poseId = 24, .offset = {0, 6}, .shadow = {0, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_2[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 27, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 27, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 27, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 28, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 28, .offset = {4, 2}, .shadow = {4, 4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 28, .offset = {10, 9}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 29, .offset = {18, 18}, .shadow = {18, 18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 29, .offset = {19, 17}, .shadow = {19, 17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 29, .offset = {18, 18}, .shadow = {18, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 29, .offset = {19, 17}, .shadow = {19, 17} },
	{ .frames = 4, .unkFlags = 0, .poseId = 27, .offset = {8, 8}, .shadow = {6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_3[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 30, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 30, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 30, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 31, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 31, .offset = {4, -1}, .shadow = {4, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 31, .offset = {10, -1}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 32, .offset = {18, -1}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 32, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 32, .offset = {18, -1}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 32, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 30, .offset = {6, 0}, .shadow = {6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_4[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 33, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 33, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 33, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 34, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 34, .offset = {4, -6}, .shadow = {4, -4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 34, .offset = {10, -11}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 35, .offset = {18, -18}, .shadow = {18, -18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 35, .offset = {19, -17}, .shadow = {19, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 35, .offset = {18, -18}, .shadow = {18, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 35, .offset = {19, -17}, .shadow = {19, -17} },
	{ .frames = 4, .unkFlags = 0, .poseId = 33, .offset = {6, -6}, .shadow = {6, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_5[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 36, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 36, .offset = {0, 1}, .shadow = {0, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 36, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 37, .offset = {0, -4}, .shadow = {0, -4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 37, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 38, .offset = {0, -18}, .shadow = {0, -18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 38, .offset = {1, -18}, .shadow = {1, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 38, .offset = {0, -18}, .shadow = {0, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 38, .offset = {1, -18}, .shadow = {1, -18} },
	{ .frames = 4, .unkFlags = 0, .poseId = 36, .offset = {0, -6}, .shadow = {0, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_6[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 39, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 39, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 39, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 40, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 40, .offset = {-4, -6}, .shadow = {-4, -4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 40, .offset = {-10, -11}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 41, .offset = {-18, -18}, .shadow = {-18, -18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 41, .offset = {-19, -17}, .shadow = {-19, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 41, .offset = {-18, -18}, .shadow = {-18, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 41, .offset = {-19, -17}, .shadow = {-19, -17} },
	{ .frames = 4, .unkFlags = 0, .poseId = 39, .offset = {-6, -6}, .shadow = {-6, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_7[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 42, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 42, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 42, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 43, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 43, .offset = {-4, -1}, .shadow = {-4, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 43, .offset = {-10, -1}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 44, .offset = {-18, -1}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 44, .offset = {-18, 0}, .shadow = {-18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 44, .offset = {-18, -1}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 44, .offset = {-18, 0}, .shadow = {-18, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 42, .offset = {-6, 0}, .shadow = {-6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_2_8[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 45, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 45, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 45, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 46, .offset = {-4, 2}, .shadow = {-4, 4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 46, .offset = {-10, 9}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 47, .offset = {-18, 18}, .shadow = {-18, 18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 47, .offset = {-17, 19}, .shadow = {-17, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 47, .offset = {-18, 18}, .shadow = {-18, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 47, .offset = {-17, 19}, .shadow = {-17, 19} },
	{ .frames = 4, .unkFlags = 0, .poseId = 45, .offset = {-6, 6}, .shadow = {-6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 48, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 48, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 48, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 49, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 49, .offset = {0, 4}, .shadow = {0, 4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 50, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 50, .offset = {0, 18}, .shadow = {0, 18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 50, .offset = {1, 18}, .shadow = {1, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 50, .offset = {0, 18}, .shadow = {0, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 50, .offset = {1, 18}, .shadow = {1, 18} },
	{ .frames = 4, .unkFlags = 0, .poseId = 48, .offset = {0, 6}, .shadow = {0, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_2[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 51, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 51, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 51, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 52, .offset = {4, 2}, .shadow = {4, 4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 52, .offset = {10, 9}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 53, .offset = {18, 18}, .shadow = {18, 18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 53, .offset = {19, 17}, .shadow = {19, 17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 53, .offset = {18, 18}, .shadow = {18, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 53, .offset = {19, 17}, .shadow = {19, 17} },
	{ .frames = 4, .unkFlags = 0, .poseId = 51, .offset = {8, 8}, .shadow = {6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_3[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 54, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 54, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 54, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 55, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 55, .offset = {4, -1}, .shadow = {4, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 55, .offset = {10, -1}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 56, .offset = {18, -1}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 56, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 56, .offset = {18, -1}, .shadow = {18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 56, .offset = {18, 0}, .shadow = {18, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 54, .offset = {6, 0}, .shadow = {6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_4[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 57, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 57, .offset = {-1, 1}, .shadow = {-1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 57, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 58, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 58, .offset = {4, -6}, .shadow = {4, -4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 58, .offset = {10, -11}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 59, .offset = {18, -18}, .shadow = {18, -18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 59, .offset = {19, -17}, .shadow = {19, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 59, .offset = {18, -18}, .shadow = {18, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 59, .offset = {19, -17}, .shadow = {19, -17} },
	{ .frames = 4, .unkFlags = 0, .poseId = 57, .offset = {6, -6}, .shadow = {6, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_5[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 60, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 60, .offset = {0, 1}, .shadow = {0, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 60, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 61, .offset = {0, -4}, .shadow = {0, -4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 61, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 62, .offset = {0, -18}, .shadow = {0, -18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 62, .offset = {1, -18}, .shadow = {1, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 62, .offset = {0, -18}, .shadow = {0, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 62, .offset = {1, -18}, .shadow = {1, -18} },
	{ .frames = 4, .unkFlags = 0, .poseId = 60, .offset = {0, -6}, .shadow = {0, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_6[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 63, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 63, .offset = {1, 1}, .shadow = {1, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 63, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 64, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 64, .offset = {-4, -6}, .shadow = {-4, -4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 64, .offset = {-10, -11}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 65, .offset = {-18, -18}, .shadow = {-18, -18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 65, .offset = {-19, -17}, .shadow = {-19, -17} },
	{ .frames = 2, .unkFlags = 0, .poseId = 65, .offset = {-18, -18}, .shadow = {-18, -18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 65, .offset = {-19, -17}, .shadow = {-19, -17} },
	{ .frames = 4, .unkFlags = 0, .poseId = 63, .offset = {-6, -6}, .shadow = {-6, -6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_7[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 66, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 66, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 66, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 67, .offset = {-4, -1}, .shadow = {-4, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 67, .offset = {-10, -1}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 68, .offset = {-18, -1}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 68, .offset = {-18, 0}, .shadow = {-18, 1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 68, .offset = {-18, -1}, .shadow = {-18, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 68, .offset = {-18, 0}, .shadow = {-18, 1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 66, .offset = {-6, 0}, .shadow = {-6, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_3_8[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 69, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 69, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 4, .unkFlags = 0, .poseId = 69, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 2, .unkFlags = 0, .poseId = 70, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 70, .offset = {-4, 2}, .shadow = {-4, 4} },
	{ .frames = 2, .unkFlags = 2, .poseId = 70, .offset = {-10, 9}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 71, .offset = {-18, 18}, .shadow = {-18, 18} },
	{ .frames = 2, .unkFlags = 1, .poseId = 71, .offset = {-17, 19}, .shadow = {-17, 19} },
	{ .frames = 2, .unkFlags = 0, .poseId = 71, .offset = {-18, 18}, .shadow = {-18, 18} },
	{ .frames = 2, .unkFlags = 0, .poseId = 71, .offset = {-17, 19}, .shadow = {-17, 19} },
	{ .frames = 4, .unkFlags = 0, .poseId = 69, .offset = {-6, 6}, .shadow = {-6, 6} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_1[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 73, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 73, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 72, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_2[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 75, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 74, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_3[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 77, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 77, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 76, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_4[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 79, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 79, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 78, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_5[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 81, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 80, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_6[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 83, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 83, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 82, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_7[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 85, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 85, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 84, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_4_8[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 2, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 87, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 86, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_1[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 88, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 89, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 88, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 89, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 88, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 89, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_2[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 91, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 91, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 90, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 91, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_3[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 92, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 93, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_4[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 94, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 95, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 94, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 95, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 94, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 95, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_5[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 96, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 97, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 96, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 97, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 96, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 97, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_6[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 98, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 99, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 98, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 99, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 98, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 99, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_7[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 100, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 101, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 100, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 101, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 100, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 101, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_5_8[] = {
	{ .frames = 6, .unkFlags = 2, .poseId = 102, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 103, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 102, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 103, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 1, .poseId = 102, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 103, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_6_1[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 104, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 105, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 106, .offset = {0, -2}, .shadow = {0, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 106, .offset = {0, -3}, .shadow = {0, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 107, .offset = {-2, -2}, .shadow = {-2, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 107, .offset = {-3, -3}, .shadow = {-3, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 108, .offset = {-2, 0}, .shadow = {-2, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 108, .offset = {-3, 0}, .shadow = {-3, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 109, .offset = {-2, 2}, .shadow = {-2, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 109, .offset = {-3, 3}, .shadow = {-3, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 110, .offset = {0, 2}, .shadow = {0, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 110, .offset = {0, 3}, .shadow = {0, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 111, .offset = {2, 2}, .shadow = {2, 2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 111, .offset = {3, 3}, .shadow = {3, 3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 112, .offset = {2, 0}, .shadow = {2, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 112, .offset = {3, 0}, .shadow = {3, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_7_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 113, .offset = {2, -2}, .shadow = {2, -2} },
	{ .frames = 8, .unkFlags = 0, .poseId = 113, .offset = {3, -3}, .shadow = {3, -3} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_1[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 114, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 115, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 116, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_2[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 117, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 118, .offset = {1, -4}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 119, .offset = {0, -3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_3[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 120, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 121, .offset = {1, -3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 122, .offset = {1, -3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_4[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 123, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 124, .offset = {1, -2}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 125, .offset = {1, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_5[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 126, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 127, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 128, .offset = {0, -3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_6[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 129, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 130, .offset = {-1, -2}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 131, .offset = {-1, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_7[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 132, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 133, .offset = {-1, -3}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 134, .offset = {-1, -3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_8_8[] = {
	{ .frames = 40, .unkFlags = 0, .poseId = 135, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 136, .offset = {-1, -4}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 137, .offset = {0, -3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 139, .offset = {6, 4}, .shadow = {6, 4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 140, .offset = {8, 9}, .shadow = {8, 9} },
	{ .frames = 2, .unkFlags = 0, .poseId = 141, .offset = {7, 13}, .shadow = {7, 13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 142, .offset = {1, 16}, .shadow = {1, 16} },
	{ .frames = 2, .unkFlags = 3, .poseId = 143, .offset = {-4, 14}, .shadow = {-4, 14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 144, .offset = {-5, 8}, .shadow = {-5, 8} },
	{ .frames = 1, .unkFlags = 0, .poseId = 145, .offset = {-4, 4}, .shadow = {-4, 4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 138, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 145, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 138, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 139, .offset = {17, 3}, .shadow = {17, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 140, .offset = {24, 9}, .shadow = {24, 9} },
	{ .frames = 3, .unkFlags = 0, .poseId = 141, .offset = {23, 16}, .shadow = {23, 16} },
	{ .frames = 2, .unkFlags = 3, .poseId = 142, .offset = {11, 16}, .shadow = {11, 16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 143, .offset = {4, 12}, .shadow = {4, 12} },
	{ .frames = 1, .unkFlags = 0, .poseId = 144, .offset = {3, 7}, .shadow = {3, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 145, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 144, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 145, .offset = {3, -4}, .shadow = {3, -4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {11, -6}, .shadow = {11, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 139, .offset = {17, -4}, .shadow = {17, -4} },
	{ .frames = 3, .unkFlags = 0, .poseId = 140, .offset = {20, 1}, .shadow = {20, 1} },
	{ .frames = 2, .unkFlags = 3, .poseId = 141, .offset = {17, 5}, .shadow = {17, 5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 142, .offset = {12, 7}, .shadow = {12, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 143, .offset = {4, 5}, .shadow = {4, 5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 144, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 143, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 144, .offset = {1, -6}, .shadow = {1, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 145, .offset = {4, -16}, .shadow = {4, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {11, -20}, .shadow = {11, -20} },
	{ .frames = 3, .unkFlags = 0, .poseId = 139, .offset = {16, -20}, .shadow = {16, -20} },
	{ .frames = 2, .unkFlags = 3, .poseId = 140, .offset = {16, -15}, .shadow = {16, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 141, .offset = {14, -6}, .shadow = {14, -6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 142, .offset = {7, -1}, .shadow = {7, -1} },
	{ .frames = 1, .unkFlags = 0, .poseId = 143, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 142, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 143, .offset = {-6, -4}, .shadow = {-6, -4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 144, .offset = {-8, -9}, .shadow = {-8, -9} },
	{ .frames = 2, .unkFlags = 0, .poseId = 145, .offset = {-7, -13}, .shadow = {-7, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 138, .offset = {-1, -16}, .shadow = {-1, -16} },
	{ .frames = 2, .unkFlags = 3, .poseId = 139, .offset = {4, -14}, .shadow = {4, -14} },
	{ .frames = 2, .unkFlags = 0, .poseId = 140, .offset = {5, -8}, .shadow = {5, -8} },
	{ .frames = 1, .unkFlags = 0, .poseId = 141, .offset = {4, -4}, .shadow = {4, -4} },
	{ .frames = 1, .unkFlags = 0, .poseId = 142, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 141, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 140, .offset = {-1, -6}, .shadow = {-1, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 139, .offset = {-4, -16}, .shadow = {-4, -16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {-11, -20}, .shadow = {-11, -20} },
	{ .frames = 3, .unkFlags = 0, .poseId = 145, .offset = {-16, -20}, .shadow = {-16, -20} },
	{ .frames = 2, .unkFlags = 3, .poseId = 144, .offset = {-16, -15}, .shadow = {-16, -15} },
	{ .frames = 2, .unkFlags = 0, .poseId = 143, .offset = {-14, -6}, .shadow = {-14, -6} },
	{ .frames = 1, .unkFlags = 0, .poseId = 142, .offset = {-7, -1}, .shadow = {-7, -1} },
	{ .frames = 1, .unkFlags = 0, .poseId = 141, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 140, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 139, .offset = {-3, -4}, .shadow = {-3, -4} },
	{ .frames = 2, .unkFlags = 0, .poseId = 138, .offset = {-11, -6}, .shadow = {-11, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 145, .offset = {-17, -4}, .shadow = {-17, -4} },
	{ .frames = 3, .unkFlags = 0, .poseId = 144, .offset = {-20, 1}, .shadow = {-20, 1} },
	{ .frames = 2, .unkFlags = 3, .poseId = 143, .offset = {-17, 5}, .shadow = {-17, 5} },
	{ .frames = 2, .unkFlags = 0, .poseId = 142, .offset = {-12, 7}, .shadow = {-12, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 141, .offset = {-4, 5}, .shadow = {-4, 5} },
	{ .frames = 1, .unkFlags = 0, .poseId = 140, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_9_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 139, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 138, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 145, .offset = {-17, 3}, .shadow = {-17, 3} },
	{ .frames = 2, .unkFlags = 0, .poseId = 144, .offset = {-24, 9}, .shadow = {-24, 9} },
	{ .frames = 3, .unkFlags = 0, .poseId = 143, .offset = {-23, 16}, .shadow = {-23, 16} },
	{ .frames = 2, .unkFlags = 3, .poseId = 142, .offset = {-11, 16}, .shadow = {-11, 16} },
	{ .frames = 2, .unkFlags = 0, .poseId = 141, .offset = {-4, 12}, .shadow = {-4, 12} },
	{ .frames = 1, .unkFlags = 0, .poseId = 140, .offset = {-3, 7}, .shadow = {-3, 7} },
	{ .frames = 1, .unkFlags = 0, .poseId = 139, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 146, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 146, .offset = {13, 0}, .shadow = {13, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 146, .offset = {-13, 0}, .shadow = {-13, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 146, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 146, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {13, -13}, .shadow = {13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {-13, 13}, .shadow = {-13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 147, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 147, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 148, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 148, .offset = {0, -13}, .shadow = {0, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 148, .offset = {0, 13}, .shadow = {0, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 148, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 148, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 149, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 149, .offset = {-13, -13}, .shadow = {-13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 149, .offset = {13, 13}, .shadow = {13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 149, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 149, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 150, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 150, .offset = {13, 0}, .shadow = {13, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 150, .offset = {-13, 0}, .shadow = {-13, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {12, 0}, .shadow = {12, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 150, .offset = {-12, 0}, .shadow = {-12, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {10, 0}, .shadow = {10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {-10, 0}, .shadow = {-10, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {6, 0}, .shadow = {6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {-6, 0}, .shadow = {-6, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 150, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {13, -13}, .shadow = {13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {-13, 13}, .shadow = {-13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {12, -12}, .shadow = {12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 151, .offset = {-12, 12}, .shadow = {-12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {10, -10}, .shadow = {10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {-10, 10}, .shadow = {-10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {6, -6}, .shadow = {6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {-6, 6}, .shadow = {-6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 151, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 152, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 152, .offset = {0, -13}, .shadow = {0, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 152, .offset = {0, 13}, .shadow = {0, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, -12}, .shadow = {0, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 152, .offset = {0, 12}, .shadow = {0, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, -10}, .shadow = {0, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, 10}, .shadow = {0, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, -6}, .shadow = {0, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, 6}, .shadow = {0, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 152, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_10_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 153, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 153, .offset = {-13, -13}, .shadow = {-13, -13} },
	{ .frames = 3, .unkFlags = 0, .poseId = 153, .offset = {13, 13}, .shadow = {13, 13} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {-12, -12}, .shadow = {-12, -12} },
	{ .frames = 3, .unkFlags = 0, .poseId = 153, .offset = {12, 12}, .shadow = {12, 12} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {-10, -10}, .shadow = {-10, -10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {10, 10}, .shadow = {10, 10} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {-6, -6}, .shadow = {-6, -6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {6, 6}, .shadow = {6, 6} },
	{ .frames = 2, .unkFlags = 0, .poseId = 153, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 154, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 155, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 155, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 155, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 155, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 156, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 156, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 156, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 156, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 154, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 157, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 158, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 158, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 158, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 158, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 159, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 159, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 159, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 159, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 157, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 160, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 161, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 161, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 161, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 161, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 162, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 162, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 162, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 162, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 160, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 163, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 164, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 164, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 164, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 164, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 165, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 165, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 165, .offset = {0, -17}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 165, .offset = {0, -11}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 163, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 166, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 167, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 167, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 167, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 167, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 168, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 168, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 168, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 168, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 166, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 169, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 170, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 170, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 170, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 170, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 171, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 171, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 171, .offset = {0, -17}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 171, .offset = {0, -11}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 169, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 172, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 173, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 173, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 173, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 173, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 174, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 174, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 174, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 174, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 172, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_11_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 175, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 176, .offset = {0, -10}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 176, .offset = {0, -16}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 176, .offset = {0, -20}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 176, .offset = {0, -21}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 177, .offset = {0, -23}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 177, .offset = {0, -22}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 177, .offset = {0, -18}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 177, .offset = {0, -12}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 175, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 179, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 179, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {1, -1}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {1, -1}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {1, -1}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {1, -1}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 182, .offset = {1, -1}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 182, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 185, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 185, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 185, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 188, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 188, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 191, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 1, .poseId = 191, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 194, .offset = {1, -1}, .shadow = {1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 194, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 197, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 197, .offset = {0, -1}, .shadow = {0, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 197, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_12_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 2, .poseId = 200, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 200, .offset = {-1, -1}, .shadow = {-1, -1} },
	{ .frames = 2, .unkFlags = 1, .poseId = 200, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_13_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 204, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 205, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 206, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 207, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 208, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 209, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 202, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 2, .poseId = 203, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_1[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_2[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_3[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_4[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_5[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_6[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_7[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_14_8[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 210, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 35, .unkFlags = 0, .poseId = 211, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_1[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_2[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_3[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_4[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_5[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_6[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_15_8[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 214, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 216, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 215, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 217, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 218, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_1[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_2[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_3[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_4[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_5[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_6[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_16_8[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 219, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 220, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 221, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_1[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_2[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_3[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_4[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_5[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_6[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_7[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_17_8[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 223, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 222, .offset = {-1, 0}, .shadow = {-1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_1[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 224, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 225, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_2[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 224, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 225, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_3[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 224, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 225, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_4[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 224, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 225, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_5[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 226, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 227, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 227, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 227, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 227, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_6[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 224, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 225, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 224, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 225, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_18_8[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 224, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 225, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 225, .offset = {0, -3}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 225, .offset = {0, -1}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 225, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_1[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_2[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_3[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_4[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_5[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_6[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_19_8[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 229, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 228, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 230, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 1}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 1}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 1}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 1}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_2[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_3[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_4[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_5[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_6[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_7[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_20_8[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 231, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 232, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, -4}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 233, .offset = {0, -2}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 233, .offset = {1, 0}, .shadow = {1, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_1[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_2[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_3[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_4[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_5[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_6[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_21_8[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 234, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 235, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 236, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_1[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_2[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_3[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_4[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_5[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_6[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_7[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_22_8[] = {
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 30, .unkFlags = 0, .poseId = 238, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 34, .unkFlags = 0, .poseId = 239, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 237, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_1[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_2[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_3[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 242, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 243, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 242, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 243, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 242, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_4[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_5[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_6[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_7[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_23_8[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 241, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 240, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_2[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_3[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_4[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_5[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_6[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_7[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_24_8[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 244, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_1[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_2[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_3[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_4[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_5[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_6[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 251, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 252, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 250, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 253, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 254, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_7[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 245, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 246, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 247, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 245, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 248, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 249, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_25_8[] = {
	{ .frames = 10, .unkFlags = 0, .poseId = 245, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 246, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 247, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 10, .unkFlags = 0, .poseId = 245, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 8, .unkFlags = 0, .poseId = 248, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 249, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_1[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_2[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_3[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_4[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_5[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_6[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_7[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_26_8[] = {
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 258, .offset = {1, 1}, .shadow = {1, 1} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_27_1[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 259, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 259, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 16, .unkFlags = 0, .poseId = 259, .offset = {-1, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 259, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 12, .unkFlags = 0, .poseId = 259, .offset = {1, 0}, .shadow = {0, 0} },
	{ .frames = 16, .unkFlags = 0, .poseId = 259, .offset = {2, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_1[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_2[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_3[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 265, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_4[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_5[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_6[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_7[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sBulbasaurAnims_28_8[] = {
	{ .frames = 12, .unkFlags = 0, .poseId = 263, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};

static const u8 sBulbasaurGfx1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_1.4bpp");
static const ax_sprite sBulbasaurSprites1[] = {
	{sBulbasaurGfx1, ARRAY_COUNT(sBulbasaurGfx1)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_2.4bpp");
static const ax_sprite sBulbasaurSprites2[] = {
	{sBulbasaurGfx2, ARRAY_COUNT(sBulbasaurGfx2)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx3[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_3.4bpp");
static const ax_sprite sBulbasaurSprites3[] = {
	{sBulbasaurGfx3, ARRAY_COUNT(sBulbasaurGfx3)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx4[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_4.4bpp");
static const ax_sprite sBulbasaurSprites4[] = {
	{sBulbasaurGfx4, ARRAY_COUNT(sBulbasaurGfx4)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx5[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_5.4bpp");
static const ax_sprite sBulbasaurSprites5[] = {
	{sBulbasaurGfx5, ARRAY_COUNT(sBulbasaurGfx5)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx6[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_6.4bpp");
static const ax_sprite sBulbasaurSprites6[] = {
	{sBulbasaurGfx6, ARRAY_COUNT(sBulbasaurGfx6)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx7[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_7.4bpp");
static const ax_sprite sBulbasaurSprites7[] = {
	{sBulbasaurGfx7, ARRAY_COUNT(sBulbasaurGfx7)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx8[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_8.4bpp");
static const ax_sprite sBulbasaurSprites8[] = {
	{sBulbasaurGfx8, ARRAY_COUNT(sBulbasaurGfx8)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx9[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_9.4bpp");
static const ax_sprite sBulbasaurSprites9[] = {
	{sBulbasaurGfx9, ARRAY_COUNT(sBulbasaurGfx9)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx10[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_10.4bpp");
static const ax_sprite sBulbasaurSprites10[] = {
	{sBulbasaurGfx10, ARRAY_COUNT(sBulbasaurGfx10)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx11[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_11.4bpp");
static const ax_sprite sBulbasaurSprites11[] = {
	{sBulbasaurGfx11, ARRAY_COUNT(sBulbasaurGfx11)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx12[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_12.4bpp");
static const ax_sprite sBulbasaurSprites12[] = {
	{sBulbasaurGfx12, ARRAY_COUNT(sBulbasaurGfx12)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx13[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_13.4bpp");
static const ax_sprite sBulbasaurSprites13[] = {
	{sBulbasaurGfx13, ARRAY_COUNT(sBulbasaurGfx13)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx14[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_14.4bpp");
static const ax_sprite sBulbasaurSprites14[] = {
	{sBulbasaurGfx14, ARRAY_COUNT(sBulbasaurGfx14)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx15[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_15.4bpp");
static const ax_sprite sBulbasaurSprites15[] = {
	{sBulbasaurGfx15, ARRAY_COUNT(sBulbasaurGfx15)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx16[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_16.4bpp");
static const u8 sBulbasaurGfx16_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_16_1.4bpp");
static const u8 sBulbasaurGfx16_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_16_2.4bpp");
static const ax_sprite sBulbasaurSprites16[] = {
	{NULL, 32},
	{sBulbasaurGfx16, ARRAY_COUNT(sBulbasaurGfx16)},
	{NULL, 32},
	{sBulbasaurGfx16_1, ARRAY_COUNT(sBulbasaurGfx16_1)},
	{NULL, 64},
	{sBulbasaurGfx16_2, ARRAY_COUNT(sBulbasaurGfx16_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx17[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_17.4bpp");
static const u8 sBulbasaurGfx17_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_17_1.4bpp");
static const u8 sBulbasaurGfx17_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_17_2.4bpp");
static const ax_sprite sBulbasaurSprites17[] = {
	{NULL, 32},
	{sBulbasaurGfx17, ARRAY_COUNT(sBulbasaurGfx17)},
	{NULL, 32},
	{sBulbasaurGfx17_1, ARRAY_COUNT(sBulbasaurGfx17_1)},
	{NULL, 64},
	{sBulbasaurGfx17_2, ARRAY_COUNT(sBulbasaurGfx17_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx18[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_18.4bpp");
static const u8 sBulbasaurGfx18_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_18_1.4bpp");
static const u8 sBulbasaurGfx18_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_18_2.4bpp");
static const ax_sprite sBulbasaurSprites18[] = {
	{NULL, 32},
	{sBulbasaurGfx18, ARRAY_COUNT(sBulbasaurGfx18)},
	{NULL, 32},
	{sBulbasaurGfx18_1, ARRAY_COUNT(sBulbasaurGfx18_1)},
	{NULL, 32},
	{sBulbasaurGfx18_2, ARRAY_COUNT(sBulbasaurGfx18_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx19[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_19.4bpp");
static const u8 sBulbasaurGfx19_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_19_1.4bpp");
static const u8 sBulbasaurGfx19_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_19_2.4bpp");
static const ax_sprite sBulbasaurSprites19[] = {
	{NULL, 32},
	{sBulbasaurGfx19, ARRAY_COUNT(sBulbasaurGfx19)},
	{NULL, 32},
	{sBulbasaurGfx19_1, ARRAY_COUNT(sBulbasaurGfx19_1)},
	{NULL, 32},
	{sBulbasaurGfx19_2, ARRAY_COUNT(sBulbasaurGfx19_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx20[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_20.4bpp");
static const u8 sBulbasaurGfx20_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_20_1.4bpp");
static const u8 sBulbasaurGfx20_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_20_2.4bpp");
static const ax_sprite sBulbasaurSprites20[] = {
	{NULL, 32},
	{sBulbasaurGfx20, ARRAY_COUNT(sBulbasaurGfx20)},
	{NULL, 32},
	{sBulbasaurGfx20_1, ARRAY_COUNT(sBulbasaurGfx20_1)},
	{NULL, 32},
	{sBulbasaurGfx20_2, ARRAY_COUNT(sBulbasaurGfx20_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx21[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_21.4bpp");
static const u8 sBulbasaurGfx21_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_21_1.4bpp");
static const u8 sBulbasaurGfx21_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_21_2.4bpp");
static const ax_sprite sBulbasaurSprites21[] = {
	{NULL, 32},
	{sBulbasaurGfx21, ARRAY_COUNT(sBulbasaurGfx21)},
	{NULL, 32},
	{sBulbasaurGfx21_1, ARRAY_COUNT(sBulbasaurGfx21_1)},
	{NULL, 32},
	{sBulbasaurGfx21_2, ARRAY_COUNT(sBulbasaurGfx21_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx22[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_22.4bpp");
static const u8 sBulbasaurGfx22_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_22_1.4bpp");
static const u8 sBulbasaurGfx22_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_22_2.4bpp");
static const ax_sprite sBulbasaurSprites22[] = {
	{NULL, 32},
	{sBulbasaurGfx22, ARRAY_COUNT(sBulbasaurGfx22)},
	{NULL, 32},
	{sBulbasaurGfx22_1, ARRAY_COUNT(sBulbasaurGfx22_1)},
	{NULL, 32},
	{sBulbasaurGfx22_2, ARRAY_COUNT(sBulbasaurGfx22_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx23[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_23.4bpp");
static const u8 sBulbasaurGfx23_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_23_1.4bpp");
static const u8 sBulbasaurGfx23_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_23_2.4bpp");
static const ax_sprite sBulbasaurSprites23[] = {
	{NULL, 32},
	{sBulbasaurGfx23, ARRAY_COUNT(sBulbasaurGfx23)},
	{NULL, 32},
	{sBulbasaurGfx23_1, ARRAY_COUNT(sBulbasaurGfx23_1)},
	{NULL, 32},
	{sBulbasaurGfx23_2, ARRAY_COUNT(sBulbasaurGfx23_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx24[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_24.4bpp");
static const u8 sBulbasaurGfx24_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_24_1.4bpp");
static const u8 sBulbasaurGfx24_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_24_2.4bpp");
static const ax_sprite sBulbasaurSprites24[] = {
	{NULL, 32},
	{sBulbasaurGfx24, ARRAY_COUNT(sBulbasaurGfx24)},
	{NULL, 32},
	{sBulbasaurGfx24_1, ARRAY_COUNT(sBulbasaurGfx24_1)},
	{NULL, 32},
	{sBulbasaurGfx24_2, ARRAY_COUNT(sBulbasaurGfx24_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx25[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_25.4bpp");
static const u8 sBulbasaurGfx25_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_25_1.4bpp");
static const u8 sBulbasaurGfx25_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_25_2.4bpp");
static const ax_sprite sBulbasaurSprites25[] = {
	{NULL, 32},
	{sBulbasaurGfx25, ARRAY_COUNT(sBulbasaurGfx25)},
	{NULL, 32},
	{sBulbasaurGfx25_1, ARRAY_COUNT(sBulbasaurGfx25_1)},
	{NULL, 32},
	{sBulbasaurGfx25_2, ARRAY_COUNT(sBulbasaurGfx25_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx26[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_26.4bpp");
static const u8 sBulbasaurGfx26_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_26_1.4bpp");
static const u8 sBulbasaurGfx26_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_26_2.4bpp");
static const ax_sprite sBulbasaurSprites26[] = {
	{NULL, 32},
	{sBulbasaurGfx26, ARRAY_COUNT(sBulbasaurGfx26)},
	{NULL, 32},
	{sBulbasaurGfx26_1, ARRAY_COUNT(sBulbasaurGfx26_1)},
	{NULL, 32},
	{sBulbasaurGfx26_2, ARRAY_COUNT(sBulbasaurGfx26_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx27[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_27.4bpp");
static const u8 sBulbasaurGfx27_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_27_1.4bpp");
static const u8 sBulbasaurGfx27_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_27_2.4bpp");
static const ax_sprite sBulbasaurSprites27[] = {
	{NULL, 32},
	{sBulbasaurGfx27, ARRAY_COUNT(sBulbasaurGfx27)},
	{NULL, 64},
	{sBulbasaurGfx27_1, ARRAY_COUNT(sBulbasaurGfx27_1)},
	{NULL, 64},
	{sBulbasaurGfx27_2, ARRAY_COUNT(sBulbasaurGfx27_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx28[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_28.4bpp");
static const u8 sBulbasaurGfx28_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_28_1.4bpp");
static const u8 sBulbasaurGfx28_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_28_2.4bpp");
static const ax_sprite sBulbasaurSprites28[] = {
	{sBulbasaurGfx28, ARRAY_COUNT(sBulbasaurGfx28)},
	{NULL, 32},
	{sBulbasaurGfx28_1, ARRAY_COUNT(sBulbasaurGfx28_1)},
	{NULL, 32},
	{sBulbasaurGfx28_2, ARRAY_COUNT(sBulbasaurGfx28_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx29[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_29.4bpp");
static const u8 sBulbasaurGfx29_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_29_1.4bpp");
static const u8 sBulbasaurGfx29_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_29_2.4bpp");
static const ax_sprite sBulbasaurSprites29[] = {
	{sBulbasaurGfx29, ARRAY_COUNT(sBulbasaurGfx29)},
	{NULL, 32},
	{sBulbasaurGfx29_1, ARRAY_COUNT(sBulbasaurGfx29_1)},
	{NULL, 32},
	{sBulbasaurGfx29_2, ARRAY_COUNT(sBulbasaurGfx29_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx30[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_30.4bpp");
static const u8 sBulbasaurGfx30_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_30_1.4bpp");
static const u8 sBulbasaurGfx30_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_30_2.4bpp");
static const ax_sprite sBulbasaurSprites30[] = {
	{sBulbasaurGfx30, ARRAY_COUNT(sBulbasaurGfx30)},
	{NULL, 32},
	{sBulbasaurGfx30_1, ARRAY_COUNT(sBulbasaurGfx30_1)},
	{NULL, 32},
	{sBulbasaurGfx30_2, ARRAY_COUNT(sBulbasaurGfx30_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx31[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_31.4bpp");
static const u8 sBulbasaurGfx31_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_31_1.4bpp");
static const u8 sBulbasaurGfx31_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_31_2.4bpp");
static const ax_sprite sBulbasaurSprites31[] = {
	{sBulbasaurGfx31, ARRAY_COUNT(sBulbasaurGfx31)},
	{NULL, 32},
	{sBulbasaurGfx31_1, ARRAY_COUNT(sBulbasaurGfx31_1)},
	{NULL, 32},
	{sBulbasaurGfx31_2, ARRAY_COUNT(sBulbasaurGfx31_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx32[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_32.4bpp");
static const u8 sBulbasaurGfx32_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_32_1.4bpp");
static const u8 sBulbasaurGfx32_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_32_2.4bpp");
static const ax_sprite sBulbasaurSprites32[] = {
	{sBulbasaurGfx32, ARRAY_COUNT(sBulbasaurGfx32)},
	{NULL, 32},
	{sBulbasaurGfx32_1, ARRAY_COUNT(sBulbasaurGfx32_1)},
	{NULL, 32},
	{sBulbasaurGfx32_2, ARRAY_COUNT(sBulbasaurGfx32_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx33[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_33.4bpp");
static const u8 sBulbasaurGfx33_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_33_1.4bpp");
static const u8 sBulbasaurGfx33_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_33_2.4bpp");
static const ax_sprite sBulbasaurSprites33[] = {
	{sBulbasaurGfx33, ARRAY_COUNT(sBulbasaurGfx33)},
	{NULL, 32},
	{sBulbasaurGfx33_1, ARRAY_COUNT(sBulbasaurGfx33_1)},
	{NULL, 32},
	{sBulbasaurGfx33_2, ARRAY_COUNT(sBulbasaurGfx33_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx34[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_34.4bpp");
static const u8 sBulbasaurGfx34_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_34_1.4bpp");
static const u8 sBulbasaurGfx34_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_34_2.4bpp");
static const ax_sprite sBulbasaurSprites34[] = {
	{NULL, 32},
	{sBulbasaurGfx34, ARRAY_COUNT(sBulbasaurGfx34)},
	{NULL, 32},
	{sBulbasaurGfx34_1, ARRAY_COUNT(sBulbasaurGfx34_1)},
	{NULL, 32},
	{sBulbasaurGfx34_2, ARRAY_COUNT(sBulbasaurGfx34_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx35[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_35.4bpp");
static const u8 sBulbasaurGfx35_1[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_35_1.4bpp");
static const u8 sBulbasaurGfx35_2[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_35_2.4bpp");
static const ax_sprite sBulbasaurSprites35[] = {
	{NULL, 32},
	{sBulbasaurGfx35, ARRAY_COUNT(sBulbasaurGfx35)},
	{NULL, 32},
	{sBulbasaurGfx35_1, ARRAY_COUNT(sBulbasaurGfx35_1)},
	{NULL, 32},
	{sBulbasaurGfx35_2, ARRAY_COUNT(sBulbasaurGfx35_2)},
	{NULL, 160},
	{NULL, 0}
};
static const u8 sBulbasaurGfx36[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_36.4bpp");
static const ax_sprite sBulbasaurSprites36[] = {
	{sBulbasaurGfx36, ARRAY_COUNT(sBulbasaurGfx36)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx37[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_37.4bpp");
static const ax_sprite sBulbasaurSprites37[] = {
	{sBulbasaurGfx37, ARRAY_COUNT(sBulbasaurGfx37)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx38[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_38.4bpp");
static const ax_sprite sBulbasaurSprites38[] = {
	{sBulbasaurGfx38, ARRAY_COUNT(sBulbasaurGfx38)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx39[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_39.4bpp");
static const ax_sprite sBulbasaurSprites39[] = {
	{sBulbasaurGfx39, ARRAY_COUNT(sBulbasaurGfx39)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx40[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_40.4bpp");
static const ax_sprite sBulbasaurSprites40[] = {
	{sBulbasaurGfx40, ARRAY_COUNT(sBulbasaurGfx40)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx41[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_41.4bpp");
static const ax_sprite sBulbasaurSprites41[] = {
	{sBulbasaurGfx41, ARRAY_COUNT(sBulbasaurGfx41)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx42[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_42.4bpp");
static const ax_sprite sBulbasaurSprites42[] = {
	{sBulbasaurGfx42, ARRAY_COUNT(sBulbasaurGfx42)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx43[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_43.4bpp");
static const ax_sprite sBulbasaurSprites43[] = {
	{sBulbasaurGfx43, ARRAY_COUNT(sBulbasaurGfx43)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx44[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_44.4bpp");
static const ax_sprite sBulbasaurSprites44[] = {
	{sBulbasaurGfx44, ARRAY_COUNT(sBulbasaurGfx44)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx45[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_45.4bpp");
static const ax_sprite sBulbasaurSprites45[] = {
	{sBulbasaurGfx45, ARRAY_COUNT(sBulbasaurGfx45)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx46[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_46.4bpp");
static const ax_sprite sBulbasaurSprites46[] = {
	{sBulbasaurGfx46, ARRAY_COUNT(sBulbasaurGfx46)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx47[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_47.4bpp");
static const ax_sprite sBulbasaurSprites47[] = {
	{sBulbasaurGfx47, ARRAY_COUNT(sBulbasaurGfx47)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx48[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_48.4bpp");
static const ax_sprite sBulbasaurSprites48[] = {
	{sBulbasaurGfx48, ARRAY_COUNT(sBulbasaurGfx48)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx49[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_49.4bpp");
static const ax_sprite sBulbasaurSprites49[] = {
	{sBulbasaurGfx49, ARRAY_COUNT(sBulbasaurGfx49)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx50[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_50.4bpp");
static const ax_sprite sBulbasaurSprites50[] = {
	{sBulbasaurGfx50, ARRAY_COUNT(sBulbasaurGfx50)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx51[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_51.4bpp");
static const ax_sprite sBulbasaurSprites51[] = {
	{sBulbasaurGfx51, ARRAY_COUNT(sBulbasaurGfx51)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx52[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_52.4bpp");
static const ax_sprite sBulbasaurSprites52[] = {
	{sBulbasaurGfx52, ARRAY_COUNT(sBulbasaurGfx52)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx53[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_53.4bpp");
static const ax_sprite sBulbasaurSprites53[] = {
	{sBulbasaurGfx53, ARRAY_COUNT(sBulbasaurGfx53)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx54[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_54.4bpp");
static const ax_sprite sBulbasaurSprites54[] = {
	{sBulbasaurGfx54, ARRAY_COUNT(sBulbasaurGfx54)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx55[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_55.4bpp");
static const ax_sprite sBulbasaurSprites55[] = {
	{sBulbasaurGfx55, ARRAY_COUNT(sBulbasaurGfx55)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx56[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_56.4bpp");
static const ax_sprite sBulbasaurSprites56[] = {
	{sBulbasaurGfx56, ARRAY_COUNT(sBulbasaurGfx56)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx57[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_57.4bpp");
static const ax_sprite sBulbasaurSprites57[] = {
	{sBulbasaurGfx57, ARRAY_COUNT(sBulbasaurGfx57)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx58[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_58.4bpp");
static const ax_sprite sBulbasaurSprites58[] = {
	{sBulbasaurGfx58, ARRAY_COUNT(sBulbasaurGfx58)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx59[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_59.4bpp");
static const ax_sprite sBulbasaurSprites59[] = {
	{sBulbasaurGfx59, ARRAY_COUNT(sBulbasaurGfx59)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx60[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_60.4bpp");
static const ax_sprite sBulbasaurSprites60[] = {
	{sBulbasaurGfx60, ARRAY_COUNT(sBulbasaurGfx60)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx61[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_61.4bpp");
static const ax_sprite sBulbasaurSprites61[] = {
	{sBulbasaurGfx61, ARRAY_COUNT(sBulbasaurGfx61)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx62[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_62.4bpp");
static const ax_sprite sBulbasaurSprites62[] = {
	{sBulbasaurGfx62, ARRAY_COUNT(sBulbasaurGfx62)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx63[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_63.4bpp");
static const ax_sprite sBulbasaurSprites63[] = {
	{sBulbasaurGfx63, ARRAY_COUNT(sBulbasaurGfx63)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx64[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_64.4bpp");
static const ax_sprite sBulbasaurSprites64[] = {
	{sBulbasaurGfx64, ARRAY_COUNT(sBulbasaurGfx64)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx65[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_65.4bpp");
static const ax_sprite sBulbasaurSprites65[] = {
	{sBulbasaurGfx65, ARRAY_COUNT(sBulbasaurGfx65)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx66[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_66.4bpp");
static const ax_sprite sBulbasaurSprites66[] = {
	{sBulbasaurGfx66, ARRAY_COUNT(sBulbasaurGfx66)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx67[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_67.4bpp");
static const ax_sprite sBulbasaurSprites67[] = {
	{sBulbasaurGfx67, ARRAY_COUNT(sBulbasaurGfx67)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx68[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_68.4bpp");
static const ax_sprite sBulbasaurSprites68[] = {
	{sBulbasaurGfx68, ARRAY_COUNT(sBulbasaurGfx68)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx69[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_69.4bpp");
static const ax_sprite sBulbasaurSprites69[] = {
	{sBulbasaurGfx69, ARRAY_COUNT(sBulbasaurGfx69)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx70[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_70.4bpp");
static const ax_sprite sBulbasaurSprites70[] = {
	{sBulbasaurGfx70, ARRAY_COUNT(sBulbasaurGfx70)},
	{NULL, 0}
};
static const u8 sBulbasaurGfx71[] = INCBIN_U8("graphics/ax/mon/bulbasaur/sprite_71.4bpp");
static const ax_sprite sBulbasaurSprites71[] = {
	{sBulbasaurGfx71, ARRAY_COUNT(sBulbasaurGfx71)},
	{NULL, 0}
};

static const ax_pose *const sAxPosesBulbasaur[] = {
	sBulbasaurPose1,
	sBulbasaurPose2,
	sBulbasaurPose3,
	sBulbasaurPose4,
	sBulbasaurPose5,
	sBulbasaurPose6,
	sBulbasaurPose7,
	sBulbasaurPose8,
	sBulbasaurPose9,
	sBulbasaurPose10,
	sBulbasaurPose11,
	sBulbasaurPose12,
	sBulbasaurPose13,
	sBulbasaurPose14,
	sBulbasaurPose15,
	sBulbasaurPose16,
	sBulbasaurPose17,
	sBulbasaurPose18,
	sBulbasaurPose19,
	sBulbasaurPose20,
	sBulbasaurPose21,
	sBulbasaurPose22,
	sBulbasaurPose23,
	sBulbasaurPose24,
	sBulbasaurPose25,
	sBulbasaurPose26,
	sBulbasaurPose27,
	sBulbasaurPose28,
	sBulbasaurPose29,
	sBulbasaurPose30,
	sBulbasaurPose31,
	sBulbasaurPose32,
	sBulbasaurPose33,
	sBulbasaurPose34,
	sBulbasaurPose35,
	sBulbasaurPose36,
	sBulbasaurPose37,
	sBulbasaurPose38,
	sBulbasaurPose39,
	sBulbasaurPose40,
	sBulbasaurPose41,
	sBulbasaurPose42,
	sBulbasaurPose43,
	sBulbasaurPose44,
	sBulbasaurPose45,
	sBulbasaurPose46,
	sBulbasaurPose47,
	sBulbasaurPose48,
	sBulbasaurPose49,
	sBulbasaurPose50,
	sBulbasaurPose51,
	sBulbasaurPose52,
	sBulbasaurPose53,
	sBulbasaurPose54,
	sBulbasaurPose55,
	sBulbasaurPose56,
	sBulbasaurPose57,
	sBulbasaurPose58,
	sBulbasaurPose59,
	sBulbasaurPose60,
	sBulbasaurPose61,
	sBulbasaurPose62,
	sBulbasaurPose63,
	sBulbasaurPose64,
	sBulbasaurPose65,
	sBulbasaurPose66,
	sBulbasaurPose67,
	sBulbasaurPose68,
	sBulbasaurPose69,
	sBulbasaurPose70,
	sBulbasaurPose71,
	sBulbasaurPose72,
	sBulbasaurPose73,
	sBulbasaurPose74,
	sBulbasaurPose75,
	sBulbasaurPose76,
	sBulbasaurPose77,
	sBulbasaurPose78,
	sBulbasaurPose79,
	sBulbasaurPose80,
	sBulbasaurPose81,
	sBulbasaurPose82,
	sBulbasaurPose83,
	sBulbasaurPose84,
	sBulbasaurPose85,
	sBulbasaurPose86,
	sBulbasaurPose87,
	sBulbasaurPose88,
	sBulbasaurPose89,
	sBulbasaurPose90,
	sBulbasaurPose91,
	sBulbasaurPose92,
	sBulbasaurPose93,
	sBulbasaurPose94,
	sBulbasaurPose95,
	sBulbasaurPose96,
	sBulbasaurPose97,
	sBulbasaurPose98,
	sBulbasaurPose99,
	sBulbasaurPose100,
	sBulbasaurPose101,
	sBulbasaurPose102,
	sBulbasaurPose103,
	sBulbasaurPose104,
	sBulbasaurPose105,
	sBulbasaurPose106,
	sBulbasaurPose107,
	sBulbasaurPose108,
	sBulbasaurPose109,
	sBulbasaurPose110,
	sBulbasaurPose111,
	sBulbasaurPose112,
	sBulbasaurPose113,
	sBulbasaurPose114,
	sBulbasaurPose115,
	sBulbasaurPose116,
	sBulbasaurPose117,
	sBulbasaurPose118,
	sBulbasaurPose119,
	sBulbasaurPose120,
	sBulbasaurPose121,
	sBulbasaurPose122,
	sBulbasaurPose123,
	sBulbasaurPose124,
	sBulbasaurPose125,
	sBulbasaurPose126,
	sBulbasaurPose127,
	sBulbasaurPose128,
	sBulbasaurPose129,
	sBulbasaurPose130,
	sBulbasaurPose131,
	sBulbasaurPose132,
	sBulbasaurPose133,
	sBulbasaurPose134,
	sBulbasaurPose135,
	sBulbasaurPose136,
	sBulbasaurPose137,
	sBulbasaurPose138,
	sBulbasaurPose139,
	sBulbasaurPose140,
	sBulbasaurPose141,
	sBulbasaurPose142,
	sBulbasaurPose143,
	sBulbasaurPose144,
	sBulbasaurPose145,
	sBulbasaurPose146,
	sBulbasaurPose147,
	sBulbasaurPose148,
	sBulbasaurPose149,
	sBulbasaurPose150,
	sBulbasaurPose151,
	sBulbasaurPose152,
	sBulbasaurPose153,
	sBulbasaurPose154,
	sBulbasaurPose155,
	sBulbasaurPose156,
	sBulbasaurPose157,
	sBulbasaurPose158,
	sBulbasaurPose159,
	sBulbasaurPose160,
	sBulbasaurPose161,
	sBulbasaurPose162,
	sBulbasaurPose163,
	sBulbasaurPose164,
	sBulbasaurPose165,
	sBulbasaurPose166,
	sBulbasaurPose167,
	sBulbasaurPose168,
	sBulbasaurPose169,
	sBulbasaurPose170,
	sBulbasaurPose171,
	sBulbasaurPose172,
	sBulbasaurPose173,
	sBulbasaurPose174,
	sBulbasaurPose175,
	sBulbasaurPose176,
	sBulbasaurPose177,
	sBulbasaurPose178,
	sBulbasaurPose179,
	sBulbasaurPose180,
	sBulbasaurPose181,
	sBulbasaurPose182,
	sBulbasaurPose183,
	sBulbasaurPose184,
	sBulbasaurPose185,
	sBulbasaurPose186,
	sBulbasaurPose187,
	sBulbasaurPose188,
	sBulbasaurPose189,
	sBulbasaurPose190,
	sBulbasaurPose191,
	sBulbasaurPose192,
	sBulbasaurPose193,
	sBulbasaurPose194,
	sBulbasaurPose195,
	sBulbasaurPose196,
	sBulbasaurPose197,
	sBulbasaurPose198,
	sBulbasaurPose199,
	sBulbasaurPose200,
	sBulbasaurPose201,
	sBulbasaurPose202,
	sBulbasaurPose203,
	sBulbasaurPose204,
	sBulbasaurPose205,
	sBulbasaurPose206,
	sBulbasaurPose207,
	sBulbasaurPose208,
	sBulbasaurPose209,
	sBulbasaurPose210,
	sBulbasaurPose211,
	sBulbasaurPose212,
	sBulbasaurPose213,
	sBulbasaurPose214,
	sBulbasaurPose215,
	sBulbasaurPose216,
	sBulbasaurPose217,
	sBulbasaurPose218,
	sBulbasaurPose219,
	sBulbasaurPose220,
	sBulbasaurPose221,
	sBulbasaurPose222,
	sBulbasaurPose223,
	sBulbasaurPose224,
	sBulbasaurPose225,
	sBulbasaurPose226,
	sBulbasaurPose227,
	sBulbasaurPose228,
	sBulbasaurPose229,
	sBulbasaurPose230,
	sBulbasaurPose231,
	sBulbasaurPose232,
	sBulbasaurPose233,
	sBulbasaurPose234,
	sBulbasaurPose235,
	sBulbasaurPose236,
	sBulbasaurPose237,
	sBulbasaurPose238,
	sBulbasaurPose239,
	sBulbasaurPose240,
	sBulbasaurPose241,
	sBulbasaurPose242,
	sBulbasaurPose243,
	sBulbasaurPose244,
	sBulbasaurPose245,
	sBulbasaurPose246,
	sBulbasaurPose247,
	sBulbasaurPose248,
	sBulbasaurPose249,
	sBulbasaurPose250,
	sBulbasaurPose251,
	sBulbasaurPose252,
	sBulbasaurPose253,
	sBulbasaurPose254,
	sBulbasaurPose255,
	sBulbasaurPose256,
	sBulbasaurPose257,
	sBulbasaurPose258,
	sBulbasaurPose259,
	sBulbasaurPose260,
	sBulbasaurPose261,
	sBulbasaurPose262,
	sBulbasaurPose263,
	sBulbasaurPose264,
	sBulbasaurPose265,
	sBulbasaurPose266,
	sBulbasaurPose267,
};

static const struct PositionSets sAxPositionsBulbasaur[] = {
	[0] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[1] = { .set = { {-1, -7}, {-8, -7}, {6, -7}, {-1, -8} } },
	[2] = { .set = { {-1, 1}, {-7, 4}, {5, 4}, {-1, -4} } },
	[3] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[4] = { .set = { {6, -6}, {10, -7}, {1, -2}, {-1, -8} } },
	[5] = { .set = { {7, -1}, {7, -4}, {-2, 3}, {-2, -6} } },
	[6] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[7] = { .set = { {8, -9}, {5, -7}, {6, -4}, {-2, -7} } },
	[8] = { .set = { {9, -4}, {3, -2}, {1, 2}, {-2, -6} } },
	[9] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[10] = { .set = { {6, -16}, {-1, -13}, {8, -9}, {-2, -9} } },
	[11] = { .set = { {8, -15}, {1, -11}, {7, -5}, {0, -10} } },
	[12] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[13] = { .set = { {-1, -18}, {6, -15}, {-8, -15}, {-1, -10} } },
	[14] = { .set = { {-1, -13}, {4, -8}, {-6, -8}, {-1, -9} } },
	[15] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[16] = { .set = { {-8, -16}, {-1, -13}, {-10, -9}, {0, -9} } },
	[17] = { .set = { {-10, -15}, {-3, -11}, {-9, -5}, {-2, -10} } },
	[18] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[19] = { .set = { {-10, -9}, {-7, -7}, {-8, -4}, {0, -7} } },
	[20] = { .set = { {-11, -4}, {-5, -2}, {-3, 2}, {0, -6} } },
	[21] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[22] = { .set = { {-8, -6}, {-12, -7}, {-3, -2}, {-1, -8} } },
	[23] = { .set = { {-9, -1}, {-9, -4}, {0, 3}, {0, -6} } },
	[24] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[25] = { .set = { {-1, -7}, {-8, -7}, {6, -7}, {-1, -8} } },
	[26] = { .set = { {-1, 1}, {-7, 4}, {5, 4}, {-1, -4} } },
	[27] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[28] = { .set = { {6, -6}, {10, -7}, {1, -2}, {-1, -8} } },
	[29] = { .set = { {7, -1}, {7, -4}, {-2, 3}, {-2, -6} } },
	[30] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[31] = { .set = { {8, -9}, {5, -7}, {6, -4}, {-2, -7} } },
	[32] = { .set = { {9, -4}, {3, -2}, {1, 2}, {-2, -6} } },
	[33] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[34] = { .set = { {6, -16}, {-1, -13}, {8, -9}, {-2, -9} } },
	[35] = { .set = { {8, -15}, {1, -11}, {7, -5}, {0, -10} } },
	[36] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[37] = { .set = { {-1, -18}, {6, -15}, {-8, -15}, {-1, -10} } },
	[38] = { .set = { {-1, -13}, {4, -8}, {-6, -8}, {-1, -9} } },
	[39] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[40] = { .set = { {-8, -16}, {-1, -13}, {-10, -9}, {0, -9} } },
	[41] = { .set = { {-10, -15}, {-3, -11}, {-9, -5}, {-2, -10} } },
	[42] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[43] = { .set = { {-10, -9}, {-7, -7}, {-8, -4}, {0, -7} } },
	[44] = { .set = { {-11, -4}, {-5, -2}, {-3, 2}, {0, -6} } },
	[45] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[46] = { .set = { {-8, -6}, {-12, -7}, {-3, -2}, {-1, -8} } },
	[47] = { .set = { {-9, -1}, {-9, -4}, {0, 3}, {0, -6} } },
	[48] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[49] = { .set = { {-1, -7}, {-8, -7}, {6, -7}, {-1, -8} } },
	[50] = { .set = { {-1, 1}, {-7, 4}, {5, 4}, {-1, -4} } },
	[51] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[52] = { .set = { {6, -6}, {10, -7}, {1, -2}, {-1, -8} } },
	[53] = { .set = { {7, -1}, {7, -4}, {-2, 3}, {-2, -6} } },
	[54] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[55] = { .set = { {8, -9}, {5, -7}, {6, -4}, {-2, -7} } },
	[56] = { .set = { {9, -4}, {3, -2}, {1, 2}, {-2, -6} } },
	[57] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[58] = { .set = { {6, -16}, {-1, -13}, {8, -9}, {-2, -9} } },
	[59] = { .set = { {8, -15}, {1, -11}, {7, -5}, {0, -10} } },
	[60] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[61] = { .set = { {-1, -18}, {6, -15}, {-8, -15}, {-1, -10} } },
	[62] = { .set = { {-1, -13}, {4, -8}, {-6, -8}, {-1, -9} } },
	[63] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[64] = { .set = { {-8, -16}, {-1, -13}, {-10, -9}, {0, -9} } },
	[65] = { .set = { {-10, -15}, {-3, -11}, {-9, -5}, {-2, -10} } },
	[66] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[67] = { .set = { {-10, -9}, {-7, -7}, {-8, -4}, {0, -7} } },
	[68] = { .set = { {-11, -4}, {-5, -2}, {-3, 2}, {0, -6} } },
	[69] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[70] = { .set = { {-8, -6}, {-12, -7}, {-3, -2}, {-1, -8} } },
	[71] = { .set = { {-9, -1}, {-9, -4}, {0, 3}, {0, -6} } },
	[72] = { .set = { {-1, -11}, {-7, 0}, {5, 0}, {-1, -6} } },
	[73] = { .set = { {-1, -14}, {-7, 0}, {5, 0}, {-1, -7} } },
	[74] = { .set = { {2, -13}, {7, -3}, {-2, 1}, {2, -7} } },
	[75] = { .set = { {1, -15}, {6, -2}, {-2, 1}, {0, -7} } },
	[76] = { .set = { {5, -16}, {6, -8}, {1, 0}, {3, -7} } },
	[77] = { .set = { {4, -16}, {4, -7}, {1, 0}, {2, -7} } },
	[78] = { .set = { {3, -16}, {-4, -11}, {7, -3}, {2, -11} } },
	[79] = { .set = { {2, -16}, {-4, -10}, {7, -2}, {1, -10} } },
	[80] = { .set = { {-1, -17}, {4, -8}, {-6, -8}, {-1, -10} } },
	[81] = { .set = { {-1, -16}, {4, -8}, {-6, -7}, {-1, -9} } },
	[82] = { .set = { {-5, -16}, {2, -11}, {-9, -3}, {-4, -11} } },
	[83] = { .set = { {-3, -16}, {3, -10}, {-8, -2}, {-2, -10} } },
	[84] = { .set = { {-6, -16}, {-7, -8}, {-2, 0}, {-4, -7} } },
	[85] = { .set = { {-5, -16}, {-5, -7}, {-2, 0}, {-3, -7} } },
	[86] = { .set = { {-4, -13}, {-9, -3}, {0, 1}, {-4, -7} } },
	[87] = { .set = { {-3, -15}, {-8, -2}, {0, 1}, {-2, -7} } },
	[88] = { .set = { {-3, -12}, {-7, 0}, {5, 0}, {-2, -6} } },
	[89] = { .set = { {1, -12}, {-7, 0}, {5, 0}, {0, -7} } },
	[90] = { .set = { {-3, -12}, {6, -5}, {-3, 0}, {-2, -9} } },
	[91] = { .set = { {-5, -11}, {4, -5}, {-3, 0}, {-3, -9} } },
	[92] = { .set = { {-4, -10}, {0, -8}, {-1, 0}, {-2, -7} } },
	[93] = { .set = { {-4, -8}, {0, -7}, {-1, 0}, {-1, -6} } },
	[94] = { .set = { {-4, -11}, {-8, -7}, {6, -3}, {-1, -8} } },
	[95] = { .set = { {0, -10}, {-8, -7}, {6, -3}, {0, -7} } },
	[96] = { .set = { {1, -10}, {5, -7}, {-7, -7}, {0, -6} } },
	[97] = { .set = { {-2, -10}, {5, -7}, {-7, -8}, {-2, -6} } },
	[98] = { .set = { {2, -11}, {6, -7}, {-8, -3}, {-1, -8} } },
	[99] = { .set = { {-2, -10}, {6, -7}, {-8, -3}, {-2, -7} } },
	[100] = { .set = { {2, -10}, {-2, -8}, {-1, 0}, {0, -7} } },
	[101] = { .set = { {2, -8}, {-2, -7}, {-1, 0}, {-1, -6} } },
	[102] = { .set = { {1, -12}, {-8, -5}, {1, 0}, {0, -9} } },
	[103] = { .set = { {3, -11}, {-6, -5}, {1, 0}, {1, -9} } },
	[104] = { .set = { {-8, -2}, {-8, -5}, {-2, 2}, {0, -6} } },
	[105] = { .set = { {-8, -1}, {-8, -4}, {-2, 2}, {0, -6} } },
	[106] = { .set = { {-1, 0}, {-8, 1}, {6, 1}, {-1, -8} } },
	[107] = { .set = { {8, -2}, {7, -7}, {2, 1}, {-1, -8} } },
	[108] = { .set = { {10, -4}, {7, -8}, {5, 1}, {1, -7} } },
	[109] = { .set = { {9, -11}, {0, -13}, {8, -3}, {-1, -8} } },
	[110] = { .set = { {-1, -15}, {4, -9}, {-6, -8}, {-1, -9} } },
	[111] = { .set = { {-10, -11}, {-1, -13}, {-9, -3}, {0, -8} } },
	[112] = { .set = { {-11, -4}, {-8, -8}, {-6, 1}, {-2, -7} } },
	[113] = { .set = { {-9, -2}, {-8, -7}, {-3, 1}, {0, -8} } },
	[114] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[115] = { .set = { {-1, -7}, {-8, -7}, {6, -7}, {-1, -8} } },
	[116] = { .set = { {-1, 1}, {-7, 4}, {5, 4}, {-1, -4} } },
	[117] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[118] = { .set = { {6, -6}, {10, -7}, {1, -2}, {-1, -8} } },
	[119] = { .set = { {7, -1}, {7, -4}, {-2, 3}, {-2, -6} } },
	[120] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[121] = { .set = { {8, -9}, {5, -7}, {6, -4}, {-2, -7} } },
	[122] = { .set = { {9, -4}, {3, -2}, {1, 2}, {-2, -6} } },
	[123] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[124] = { .set = { {6, -16}, {-1, -13}, {8, -9}, {-2, -9} } },
	[125] = { .set = { {8, -15}, {1, -11}, {7, -5}, {0, -10} } },
	[126] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[127] = { .set = { {-1, -18}, {6, -15}, {-8, -15}, {-1, -10} } },
	[128] = { .set = { {-1, -13}, {4, -8}, {-6, -8}, {-1, -9} } },
	[129] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[130] = { .set = { {-8, -16}, {-1, -13}, {-10, -9}, {0, -9} } },
	[131] = { .set = { {-10, -15}, {-3, -11}, {-9, -5}, {-2, -10} } },
	[132] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[133] = { .set = { {-10, -9}, {-7, -7}, {-8, -4}, {0, -7} } },
	[134] = { .set = { {-11, -4}, {-5, -2}, {-3, 2}, {0, -6} } },
	[135] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[136] = { .set = { {-8, -6}, {-12, -7}, {-3, -2}, {-1, -8} } },
	[137] = { .set = { {-9, -1}, {-9, -4}, {0, 3}, {0, -6} } },
	[138] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[139] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[140] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[141] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[142] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[143] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[144] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[145] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[146] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[147] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[148] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[149] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[150] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[151] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[152] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[153] = { .set = { {-7, -4}, {-5, -5}, {2, 0}, {1, -6} } },
	[154] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[155] = { .set = { {-1, -7}, {-8, -7}, {6, -7}, {-1, -8} } },
	[156] = { .set = { {-1, 1}, {-7, 4}, {5, 4}, {-1, -4} } },
	[157] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[158] = { .set = { {6, -6}, {10, -7}, {1, -2}, {-1, -8} } },
	[159] = { .set = { {7, -1}, {7, -4}, {-2, 3}, {-2, -6} } },
	[160] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[161] = { .set = { {8, -9}, {5, -7}, {6, -4}, {-2, -7} } },
	[162] = { .set = { {9, -4}, {3, -2}, {1, 2}, {-2, -6} } },
	[163] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[164] = { .set = { {6, -16}, {-1, -13}, {8, -9}, {-2, -9} } },
	[165] = { .set = { {8, -15}, {1, -11}, {7, -5}, {0, -10} } },
	[166] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[167] = { .set = { {-1, -18}, {6, -15}, {-8, -15}, {-1, -10} } },
	[168] = { .set = { {-1, -13}, {4, -8}, {-6, -8}, {-1, -9} } },
	[169] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[170] = { .set = { {-8, -16}, {-1, -13}, {-10, -9}, {0, -9} } },
	[171] = { .set = { {-10, -15}, {-3, -11}, {-9, -5}, {-2, -10} } },
	[172] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[173] = { .set = { {-10, -9}, {-7, -7}, {-8, -4}, {0, -7} } },
	[174] = { .set = { {-11, -4}, {-5, -2}, {-3, 2}, {0, -6} } },
	[175] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[176] = { .set = { {-8, -6}, {-12, -7}, {-3, -2}, {-1, -8} } },
	[177] = { .set = { {-9, -1}, {-9, -4}, {0, 3}, {0, -6} } },
	[178] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[179] = { .set = { {-1, -7}, {-8, -7}, {6, -7}, {-1, -8} } },
	[180] = { .set = { {-1, 1}, {-7, 4}, {5, 4}, {-1, -4} } },
	[181] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[182] = { .set = { {6, -6}, {10, -7}, {1, -2}, {-1, -8} } },
	[183] = { .set = { {7, -1}, {7, -4}, {-2, 3}, {-2, -6} } },
	[184] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[185] = { .set = { {8, -9}, {5, -7}, {6, -4}, {-2, -7} } },
	[186] = { .set = { {9, -4}, {3, -2}, {1, 2}, {-2, -6} } },
	[187] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[188] = { .set = { {6, -16}, {-1, -13}, {8, -9}, {-2, -9} } },
	[189] = { .set = { {8, -15}, {1, -11}, {7, -5}, {0, -10} } },
	[190] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[191] = { .set = { {-1, -18}, {6, -15}, {-8, -15}, {-1, -10} } },
	[192] = { .set = { {-1, -13}, {4, -8}, {-6, -8}, {-1, -9} } },
	[193] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[194] = { .set = { {-8, -16}, {-1, -13}, {-10, -9}, {0, -9} } },
	[195] = { .set = { {-10, -15}, {-3, -11}, {-9, -5}, {-2, -10} } },
	[196] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[197] = { .set = { {-10, -9}, {-7, -7}, {-8, -4}, {0, -7} } },
	[198] = { .set = { {-11, -4}, {-5, -2}, {-3, 2}, {0, -6} } },
	[199] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[200] = { .set = { {-8, -6}, {-12, -7}, {-3, -2}, {-1, -8} } },
	[201] = { .set = { {-9, -1}, {-9, -4}, {0, 3}, {0, -6} } },
	[202] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[203] = { .set = { {-8, -4}, {-6, -5}, {1, 0}, {0, -6} } },
	[204] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[205] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[206] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[207] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[208] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[209] = { .set = { {6, -4}, {4, -5}, {-3, 0}, {-2, -6} } },
	[210] = { .set = { {-9, -2}, {-8, -3}, {-6, 0}, {-1, -6} } },
	[211] = { .set = { {-9, -1}, {-8, -2}, {-6, 0}, {-1, -6} } },
	[212] = { .set = { {8, -2}, {7, -3}, {5, 0}, {0, -6} } },
	[213] = { .set = { {8, -1}, {7, -2}, {5, 0}, {0, -6} } },
	[214] = { .set = { {-9, -2}, {-8, -3}, {-6, 0}, {-1, -6} } },
	[215] = { .set = { {-6, -4}, {-6, -2}, {-5, 0}, {0, -6} } },
	[216] = { .set = { {-6, -5}, {-6, -2}, {-5, 0}, {0, -6} } },
	[217] = { .set = { {-9, -2}, {-7, -2}, {-6, 0}, {0, -6} } },
	[218] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[219] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[220] = { .set = { {-1, -9}, {5, -7}, {-7, -7}, {-1, -8} } },
	[221] = { .set = { {-1, -8}, {5, -8}, {-7, -8}, {-1, -9} } },
	[222] = { .set = { {-1, 3}, {-8, 2}, {6, 2}, {-1, -6} } },
	[223] = { .set = { {-1, -2}, {-8, 2}, {6, 2}, {-1, -6} } },
	[224] = { .set = { {-1, 3}, {-8, 2}, {6, 2}, {-1, -5} } },
	[225] = { .set = { {-1, -2}, {-8, 2}, {6, 2}, {-1, -6} } },
	[226] = { .set = { {-1, -6}, {7, -6}, {-9, -6}, {-1, -3} } },
	[227] = { .set = { {-1, -8}, {7, -6}, {-9, -6}, {-1, -3} } },
	[228] = { .set = { {-1, -4}, {-8, -6}, {6, -6}, {-1, -7} } },
	[229] = { .set = { {-1, -3}, {-8, -5}, {6, -5}, {-1, -6} } },
	[230] = { .set = { {-1, -3}, {-8, -5}, {6, -5}, {-1, -6} } },
	[231] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[232] = { .set = { {-8, -6}, {-9, -5}, {0, -6}, {-2, -7} } },
	[233] = { .set = { {-5, -7}, {-8, -4}, {-1, -11}, {-1, -7} } },
	[234] = { .set = { {-1, -15}, {5, -12}, {-7, -12}, {-1, -8} } },
	[235] = { .set = { {-1, -9}, {6, -7}, {-8, -7}, {-1, -7} } },
	[236] = { .set = { {-1, -6}, {7, -5}, {-9, -5}, {-1, -5} } },
	[237] = { .set = { {-1, -1}, {-6, 0}, {4, 0}, {-1, -6} } },
	[238] = { .set = { {-1, -5}, {-7, 0}, {5, 0}, {-1, -7} } },
	[239] = { .set = { {-1, 4}, {-8, 0}, {6, 0}, {-1, -5} } },
	[240] = { .set = { {-10, -6}, {-4, -5}, {-1, 0}, {0, -5} } },
	[241] = { .set = { {-8, -1}, {-4, -3}, {-1, -1}, {-2, -6} } },
	[242] = { .set = { {8, -6}, {2, -5}, {-1, 0}, {-2, -5} } },
	[243] = { .set = { {6, -1}, {2, -3}, {-1, -1}, {0, -6} } },
	[244] = { .set = { {-1, -11}, {7, -9}, {-9, -9}, {-1, -7} } },
	[245] = { .set = { {-7, -1}, {-6, -3}, {-2, -1}, {-1, -7} } },
	[246] = { .set = { {-6, -2}, {-12, -7}, {-1, -1}, {-2, -7} } },
	[247] = { .set = { {-7, 0}, {-13, -3}, {0, 1}, {-2, -6} } },
	[248] = { .set = { {-8, -2}, {-8, -4}, {-5, -2}, {-1, -7} } },
	[249] = { .set = { {-9, 0}, {-8, -2}, {-6, 1}, {-1, -5} } },
	[250] = { .set = { {5, -1}, {4, -3}, {0, -1}, {-1, -7} } },
	[251] = { .set = { {4, -2}, {10, -7}, {-1, -1}, {0, -7} } },
	[252] = { .set = { {5, 0}, {11, -3}, {-2, 1}, {0, -6} } },
	[253] = { .set = { {6, -2}, {6, -4}, {3, -2}, {-1, -7} } },
	[254] = { .set = { {7, 0}, {6, -2}, {4, 1}, {-1, -5} } },
	[255] = { .set = { {-8, -13}, {-2, -8}, {-8, -3}, {-1, -6} } },
	[256] = { .set = { {-4, -9}, {1, -10}, {-8, -7}, {1, -7} } },
	[257] = { .set = { {6, -13}, {0, -8}, {6, -3}, {-1, -6} } },
	[258] = { .set = { {2, -9}, {-3, -10}, {6, -7}, {-3, -7} } },
	[259] = { .set = { {-9, -2}, {-8, -3}, {-6, 0}, {-1, -6} } },
	[260] = { .set = { {-9, -1}, {-8, -2}, {-6, 0}, {-1, -6} } },
	[261] = { .set = { {8, -2}, {7, -3}, {5, 0}, {0, -6} } },
	[262] = { .set = { {8, -1}, {7, -2}, {5, 0}, {0, -6} } },
	[263] = { .set = { {-9, -2}, {-8, -3}, {-6, 0}, {-1, -6} } },
	[264] = { .set = { {-9, -1}, {-8, -2}, {-6, 0}, {-1, -6} } },
	[265] = { .set = { {8, -2}, {7, -3}, {5, 0}, {0, -6} } },
	[266] = { .set = { {8, -1}, {7, -2}, {5, 0}, {0, -6} } },
};

static const ax_anim *const sBulbasaurAnimTable1[] = {
	sBulbasaurAnims_1_1,
	sBulbasaurAnims_1_2,
	sBulbasaurAnims_1_3,
	sBulbasaurAnims_1_4,
	sBulbasaurAnims_1_5,
	sBulbasaurAnims_1_6,
	sBulbasaurAnims_1_7,
	sBulbasaurAnims_1_8,
};

static const ax_anim *const sBulbasaurAnimTable2[] = {
	sBulbasaurAnims_2_1,
	sBulbasaurAnims_2_2,
	sBulbasaurAnims_2_3,
	sBulbasaurAnims_2_4,
	sBulbasaurAnims_2_5,
	sBulbasaurAnims_2_6,
	sBulbasaurAnims_2_7,
	sBulbasaurAnims_2_8,
};

static const ax_anim *const sBulbasaurAnimTable3[] = {
	sBulbasaurAnims_3_1,
	sBulbasaurAnims_3_2,
	sBulbasaurAnims_3_3,
	sBulbasaurAnims_3_4,
	sBulbasaurAnims_3_5,
	sBulbasaurAnims_3_6,
	sBulbasaurAnims_3_7,
	sBulbasaurAnims_3_8,
};

static const ax_anim *const sBulbasaurAnimTable4[] = {
	sBulbasaurAnims_4_1,
	sBulbasaurAnims_4_2,
	sBulbasaurAnims_4_3,
	sBulbasaurAnims_4_4,
	sBulbasaurAnims_4_5,
	sBulbasaurAnims_4_6,
	sBulbasaurAnims_4_7,
	sBulbasaurAnims_4_8,
};

static const ax_anim *const sBulbasaurAnimTable5[] = {
	sBulbasaurAnims_5_1,
	sBulbasaurAnims_5_2,
	sBulbasaurAnims_5_3,
	sBulbasaurAnims_5_4,
	sBulbasaurAnims_5_5,
	sBulbasaurAnims_5_6,
	sBulbasaurAnims_5_7,
	sBulbasaurAnims_5_8,
};

static const ax_anim *const sBulbasaurAnimTable6[] = {
	sBulbasaurAnims_6_1,
	sBulbasaurAnims_6_1,
	sBulbasaurAnims_6_1,
	sBulbasaurAnims_6_1,
	sBulbasaurAnims_6_1,
	sBulbasaurAnims_6_1,
	sBulbasaurAnims_6_1,
	sBulbasaurAnims_6_1,
};

static const ax_anim *const sBulbasaurAnimTable7[] = {
	sBulbasaurAnims_7_1,
	sBulbasaurAnims_7_2,
	sBulbasaurAnims_7_3,
	sBulbasaurAnims_7_4,
	sBulbasaurAnims_7_5,
	sBulbasaurAnims_7_6,
	sBulbasaurAnims_7_7,
	sBulbasaurAnims_7_8,
};

static const ax_anim *const sBulbasaurAnimTable8[] = {
	sBulbasaurAnims_8_1,
	sBulbasaurAnims_8_2,
	sBulbasaurAnims_8_3,
	sBulbasaurAnims_8_4,
	sBulbasaurAnims_8_5,
	sBulbasaurAnims_8_6,
	sBulbasaurAnims_8_7,
	sBulbasaurAnims_8_8,
};

static const ax_anim *const sBulbasaurAnimTable9[] = {
	sBulbasaurAnims_9_1,
	sBulbasaurAnims_9_2,
	sBulbasaurAnims_9_3,
	sBulbasaurAnims_9_4,
	sBulbasaurAnims_9_5,
	sBulbasaurAnims_9_6,
	sBulbasaurAnims_9_7,
	sBulbasaurAnims_9_8,
};

static const ax_anim *const sBulbasaurAnimTable10[] = {
	sBulbasaurAnims_10_1,
	sBulbasaurAnims_10_2,
	sBulbasaurAnims_10_3,
	sBulbasaurAnims_10_4,
	sBulbasaurAnims_10_5,
	sBulbasaurAnims_10_6,
	sBulbasaurAnims_10_7,
	sBulbasaurAnims_10_8,
};

static const ax_anim *const sBulbasaurAnimTable11[] = {
	sBulbasaurAnims_11_1,
	sBulbasaurAnims_11_2,
	sBulbasaurAnims_11_3,
	sBulbasaurAnims_11_4,
	sBulbasaurAnims_11_5,
	sBulbasaurAnims_11_6,
	sBulbasaurAnims_11_7,
	sBulbasaurAnims_11_8,
};

static const ax_anim *const sBulbasaurAnimTable12[] = {
	sBulbasaurAnims_12_1,
	sBulbasaurAnims_12_2,
	sBulbasaurAnims_12_3,
	sBulbasaurAnims_12_4,
	sBulbasaurAnims_12_5,
	sBulbasaurAnims_12_6,
	sBulbasaurAnims_12_7,
	sBulbasaurAnims_12_8,
};

static const ax_anim *const sBulbasaurAnimTable13[] = {
	sBulbasaurAnims_13_1,
	sBulbasaurAnims_13_2,
	sBulbasaurAnims_13_3,
	sBulbasaurAnims_13_4,
	sBulbasaurAnims_13_5,
	sBulbasaurAnims_13_6,
	sBulbasaurAnims_13_7,
	sBulbasaurAnims_13_8,
};

static const ax_anim *const sBulbasaurAnimTable14[] = {
	sBulbasaurAnims_14_1,
	sBulbasaurAnims_14_2,
	sBulbasaurAnims_14_3,
	sBulbasaurAnims_14_4,
	sBulbasaurAnims_14_5,
	sBulbasaurAnims_14_6,
	sBulbasaurAnims_14_7,
	sBulbasaurAnims_14_8,
};

static const ax_anim *const sBulbasaurAnimTable15[] = {
	sBulbasaurAnims_15_1,
	sBulbasaurAnims_15_2,
	sBulbasaurAnims_15_3,
	sBulbasaurAnims_15_4,
	sBulbasaurAnims_15_5,
	sBulbasaurAnims_15_6,
	sBulbasaurAnims_15_7,
	sBulbasaurAnims_15_8,
};

static const ax_anim *const sBulbasaurAnimTable16[] = {
	sBulbasaurAnims_16_1,
	sBulbasaurAnims_16_2,
	sBulbasaurAnims_16_3,
	sBulbasaurAnims_16_4,
	sBulbasaurAnims_16_5,
	sBulbasaurAnims_16_6,
	sBulbasaurAnims_16_7,
	sBulbasaurAnims_16_8,
};

static const ax_anim *const sBulbasaurAnimTable17[] = {
	sBulbasaurAnims_17_1,
	sBulbasaurAnims_17_2,
	sBulbasaurAnims_17_3,
	sBulbasaurAnims_17_4,
	sBulbasaurAnims_17_5,
	sBulbasaurAnims_17_6,
	sBulbasaurAnims_17_7,
	sBulbasaurAnims_17_8,
};

static const ax_anim *const sBulbasaurAnimTable18[] = {
	sBulbasaurAnims_18_1,
	sBulbasaurAnims_18_2,
	sBulbasaurAnims_18_3,
	sBulbasaurAnims_18_4,
	sBulbasaurAnims_18_5,
	sBulbasaurAnims_18_6,
	sBulbasaurAnims_18_7,
	sBulbasaurAnims_18_8,
};

static const ax_anim *const sBulbasaurAnimTable19[] = {
	sBulbasaurAnims_19_1,
	sBulbasaurAnims_19_2,
	sBulbasaurAnims_19_3,
	sBulbasaurAnims_19_4,
	sBulbasaurAnims_19_5,
	sBulbasaurAnims_19_6,
	sBulbasaurAnims_19_7,
	sBulbasaurAnims_19_8,
};

static const ax_anim *const sBulbasaurAnimTable20[] = {
	sBulbasaurAnims_20_1,
	sBulbasaurAnims_20_2,
	sBulbasaurAnims_20_3,
	sBulbasaurAnims_20_4,
	sBulbasaurAnims_20_5,
	sBulbasaurAnims_20_6,
	sBulbasaurAnims_20_7,
	sBulbasaurAnims_20_8,
};

static const ax_anim *const sBulbasaurAnimTable21[] = {
	sBulbasaurAnims_21_1,
	sBulbasaurAnims_21_2,
	sBulbasaurAnims_21_3,
	sBulbasaurAnims_21_4,
	sBulbasaurAnims_21_5,
	sBulbasaurAnims_21_6,
	sBulbasaurAnims_21_7,
	sBulbasaurAnims_21_8,
};

static const ax_anim *const sBulbasaurAnimTable22[] = {
	sBulbasaurAnims_22_1,
	sBulbasaurAnims_22_2,
	sBulbasaurAnims_22_3,
	sBulbasaurAnims_22_4,
	sBulbasaurAnims_22_5,
	sBulbasaurAnims_22_6,
	sBulbasaurAnims_22_7,
	sBulbasaurAnims_22_8,
};

static const ax_anim *const sBulbasaurAnimTable23[] = {
	sBulbasaurAnims_23_1,
	sBulbasaurAnims_23_2,
	sBulbasaurAnims_23_3,
	sBulbasaurAnims_23_4,
	sBulbasaurAnims_23_5,
	sBulbasaurAnims_23_6,
	sBulbasaurAnims_23_7,
	sBulbasaurAnims_23_8,
};

static const ax_anim *const sBulbasaurAnimTable24[] = {
	sBulbasaurAnims_24_1,
	sBulbasaurAnims_24_2,
	sBulbasaurAnims_24_3,
	sBulbasaurAnims_24_4,
	sBulbasaurAnims_24_5,
	sBulbasaurAnims_24_6,
	sBulbasaurAnims_24_7,
	sBulbasaurAnims_24_8,
};

static const ax_anim *const sBulbasaurAnimTable25[] = {
	sBulbasaurAnims_25_1,
	sBulbasaurAnims_25_2,
	sBulbasaurAnims_25_3,
	sBulbasaurAnims_25_4,
	sBulbasaurAnims_25_5,
	sBulbasaurAnims_25_6,
	sBulbasaurAnims_25_7,
	sBulbasaurAnims_25_8,
};

static const ax_anim *const sBulbasaurAnimTable26[] = {
	sBulbasaurAnims_26_1,
	sBulbasaurAnims_26_2,
	sBulbasaurAnims_26_3,
	sBulbasaurAnims_26_4,
	sBulbasaurAnims_26_5,
	sBulbasaurAnims_26_6,
	sBulbasaurAnims_26_7,
	sBulbasaurAnims_26_8,
};

static const ax_anim *const sBulbasaurAnimTable27[] = {
	sBulbasaurAnims_27_1,
	sBulbasaurAnims_27_1,
	sBulbasaurAnims_27_1,
	sBulbasaurAnims_27_1,
	sBulbasaurAnims_27_1,
	sBulbasaurAnims_27_1,
	sBulbasaurAnims_27_1,
	sBulbasaurAnims_27_1,
};

static const ax_anim *const sBulbasaurAnimTable28[] = {
	sBulbasaurAnims_28_1,
	sBulbasaurAnims_28_2,
	sBulbasaurAnims_28_3,
	sBulbasaurAnims_28_4,
	sBulbasaurAnims_28_5,
	sBulbasaurAnims_28_6,
	sBulbasaurAnims_28_7,
	sBulbasaurAnims_28_8,
};

static const ax_anim *const *const sAxAnimationsBulbasaur[] = {
	sBulbasaurAnimTable1,
	sBulbasaurAnimTable2,
	sBulbasaurAnimTable3,
	sBulbasaurAnimTable4,
	sBulbasaurAnimTable5,
	sBulbasaurAnimTable6,
	sBulbasaurAnimTable7,
	sBulbasaurAnimTable8,
	sBulbasaurAnimTable9,
	sBulbasaurAnimTable10,
	sBulbasaurAnimTable11,
	sBulbasaurAnimTable12,
	sBulbasaurAnimTable13,
	sBulbasaurAnimTable14,
	sBulbasaurAnimTable15,
	sBulbasaurAnimTable16,
	sBulbasaurAnimTable17,
	sBulbasaurAnimTable18,
	sBulbasaurAnimTable19,
	sBulbasaurAnimTable20,
	sBulbasaurAnimTable21,
	sBulbasaurAnimTable22,
	sBulbasaurAnimTable23,
	sBulbasaurAnimTable24,
	sBulbasaurAnimTable25,
	sBulbasaurAnimTable26,
	sBulbasaurAnimTable27,
	sBulbasaurAnimTable28,
};

static const ax_sprite *const sAxSpritesBulbasaur[] = {
	sBulbasaurSprites1,
	sBulbasaurSprites2,
	sBulbasaurSprites3,
	sBulbasaurSprites4,
	sBulbasaurSprites5,
	sBulbasaurSprites6,
	sBulbasaurSprites7,
	sBulbasaurSprites8,
	sBulbasaurSprites9,
	sBulbasaurSprites10,
	sBulbasaurSprites11,
	sBulbasaurSprites12,
	sBulbasaurSprites13,
	sBulbasaurSprites14,
	sBulbasaurSprites15,
	sBulbasaurSprites16,
	sBulbasaurSprites17,
	sBulbasaurSprites18,
	sBulbasaurSprites19,
	sBulbasaurSprites20,
	sBulbasaurSprites21,
	sBulbasaurSprites22,
	sBulbasaurSprites23,
	sBulbasaurSprites24,
	sBulbasaurSprites25,
	sBulbasaurSprites26,
	sBulbasaurSprites27,
	sBulbasaurSprites28,
	sBulbasaurSprites29,
	sBulbasaurSprites30,
	sBulbasaurSprites31,
	sBulbasaurSprites32,
	sBulbasaurSprites33,
	sBulbasaurSprites34,
	sBulbasaurSprites35,
	sBulbasaurSprites36,
	sBulbasaurSprites37,
	sBulbasaurSprites38,
	sBulbasaurSprites39,
	sBulbasaurSprites40,
	sBulbasaurSprites41,
	sBulbasaurSprites42,
	sBulbasaurSprites43,
	sBulbasaurSprites44,
	sBulbasaurSprites45,
	sBulbasaurSprites46,
	sBulbasaurSprites47,
	sBulbasaurSprites48,
	sBulbasaurSprites49,
	sBulbasaurSprites50,
	sBulbasaurSprites51,
	sBulbasaurSprites52,
	sBulbasaurSprites53,
	sBulbasaurSprites54,
	sBulbasaurSprites55,
	sBulbasaurSprites56,
	sBulbasaurSprites57,
	sBulbasaurSprites58,
	sBulbasaurSprites59,
	sBulbasaurSprites60,
	sBulbasaurSprites61,
	sBulbasaurSprites62,
	sBulbasaurSprites63,
	sBulbasaurSprites64,
	sBulbasaurSprites65,
	sBulbasaurSprites66,
	sBulbasaurSprites67,
	sBulbasaurSprites68,
	sBulbasaurSprites69,
	sBulbasaurSprites70,
	sBulbasaurSprites71,
};

static const axmain sAxMainBulbasaur = {
	.poses = sAxPosesBulbasaur,
	.animations = sAxAnimationsBulbasaur,
	.animCount = ARRAY_COUNT(sAxAnimationsBulbasaur),
	.spriteData = sAxSpritesBulbasaur,
	.positions = sAxPositionsBulbasaur,
};
*/
