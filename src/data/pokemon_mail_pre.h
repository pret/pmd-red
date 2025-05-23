// TODO: Make things static once the code is moved out of asm

const s32 gUnknown_80E80A0[16] = {
    1,
    5,
    10,
    20,
    40,
    60,
    80,
    100,
    150,
    200,
    300,
    500,
    700,
    1000,
    1500,
    2000
};

// A list of Pokémon that are banned from appearing in rescue mail regardless of game progress
const s16 gUnknown_80E80E0[35] = {
    MONSTER_UNOWN_A,
    MONSTER_CASTFORM,
    MONSTER_KECLEON,
    MONSTER_SILCOON,
    MONSTER_CASCOON,
    MONSTER_KAKUNA,
    MONSTER_MAGNEMITE,
    MONSTER_MAGNETON,
    MONSTER_GARDEVOIR,
    MONSTER_GENGAR,
    MONSTER_ZAPDOS,
    MONSTER_MOLTRES,
    MONSTER_ARTICUNO,
    MONSTER_RAYQUAZA,
    MONSTER_ENTEI,
    MONSTER_RAIKOU,
    MONSTER_SUICUNE,
    MONSTER_HO_OH,
    MONSTER_MEWTWO,
    MONSTER_LATIOS,
    MONSTER_LATIAS,
    MONSTER_JIRACHI,
    MONSTER_LUGIA,
    MONSTER_CELEBI,
    MONSTER_REGIROCK,
    MONSTER_REGICE,
    MONSTER_REGISTEEL,
    MONSTER_MEW,
    MONSTER_GROUDON,
    MONSTER_KYOGRE,
    MONSTER_DEOXYS_NORMAL,
    MONSTER_MUNCHLAX,
    MONSTER_DECOY,
    MONSTER_STATUE,
    MONSTER_NONE
};

// A list of Pokémon that are banned from appearing in rescue mail before the post-game
const s16 gUnknown_80E8126[33] = {
    MONSTER_KECLEON,
    MONSTER_PERSIAN,
    MONSTER_WIGGLYTUFF,
    MONSTER_KANGASKHAN,
    MONSTER_GULPIN,
    MONSTER_PELIPPER,
    MONSTER_LOMBRE,
    MONSTER_BELLSPROUT,
    MONSTER_SNUBBULL,
    MONSTER_WHISCASH,
    MONSTER_ABSOL,
    MONSTER_CATERPIE,
    MONSTER_METAPOD,
    MONSTER_BUTTERFREE,
    MONSTER_DUGTRIO,
    MONSTER_DIGLETT,
    MONSTER_SKARMORY,
    MONSTER_JUMPLUFF,
    MONSTER_SHIFTRY,
    MONSTER_ALAKAZAM,
    MONSTER_CHARIZARD,
    MONSTER_TYRANITAR,
    MONSTER_EKANS,
    MONSTER_MEDICHAM,
    MONSTER_XATU,
    MONSTER_NINETALES,
    MONSTER_BLASTOISE,
    MONSTER_OCTILLERY,
    MONSTER_GOLEM,
    MONSTER_WYNAUT,
    MONSTER_WOBBUFFET,
    MONSTER_MANKEY,
    MONSTER_NONE
};

const struct PokemonPair gUnknown_80E8168[6] = {
    { MONSTER_NIDORAN_M, MONSTER_NIDORAN_F },
    { MONSTER_NIDORINO, MONSTER_NIDORINA },
    { MONSTER_NIDOKING, MONSTER_NIDOQUEEN },
    { MONSTER_TAUROS, MONSTER_MILTANK },
    { MONSTER_VOLBEAT, MONSTER_ILLUMISE },
    { MONSTER_MINUN, MONSTER_PLUSLE }
};

const struct PokemonItem gUnknown_80E8180[21] = {
    { MONSTER_GLOOM, ITEM_LEAF_STONE },
    { MONSTER_WEEPINBELL, ITEM_LEAF_STONE },
    { MONSTER_EXEGGCUTE, ITEM_LEAF_STONE },
    { MONSTER_NUZLEAF, ITEM_LEAF_STONE },
    { MONSTER_GLOOM, ITEM_SUN_STONE },
    { MONSTER_SUNKERN, ITEM_SUN_STONE },
    { MONSTER_PIKACHU, ITEM_THUNDERSTONE },
    { MONSTER_EEVEE, ITEM_THUNDERSTONE },
    { MONSTER_VULPIX, ITEM_FIRE_STONE },
    { MONSTER_GROWLITHE, ITEM_FIRE_STONE },
    { MONSTER_EEVEE, ITEM_FIRE_STONE },
    { MONSTER_POLIWHIRL, ITEM_WATER_STONE },
    { MONSTER_SHELLDER, ITEM_WATER_STONE },
    { MONSTER_STARYU, ITEM_WATER_STONE },
    { MONSTER_EEVEE, ITEM_WATER_STONE },
    { MONSTER_LOMBRE, ITEM_WATER_STONE },
    { MONSTER_NIDORINA, ITEM_MOON_STONE },
    { MONSTER_NIDORINO, ITEM_MOON_STONE },
    { MONSTER_CLEFAIRY, ITEM_MOON_STONE },
    { MONSTER_JIGGLYPUFF, ITEM_MOON_STONE },
    { MONSTER_SKITTY, ITEM_MOON_STONE }
};

// List of preferred gummis
const struct PokemonItem gUnknown_80E81D4[386] = {
    { MONSTER_EKANS, ITEM_PINK_GUMMI },
    { MONSTER_ARBOK, ITEM_PINK_GUMMI },
    { MONSTER_ARMALDO, ITEM_GRAY_GUMMI },
    { MONSTER_BEAUTIFLY, ITEM_GREEN_GUMMI },
    { MONSTER_MEDITITE, ITEM_ORANGE_GUMMI },
    { MONSTER_SEAKING, ITEM_BLUE_GUMMI },
    { MONSTER_TORCHIC, ITEM_RED_GUMMI },
    { MONSTER_ANORITH, ITEM_GRAY_GUMMI },
    { MONSTER_ABSOL, ITEM_BLACK_GUMMI },
    { MONSTER_SURSKIT, ITEM_GREEN_GUMMI },
    { MONSTER_MASQUERAIN, ITEM_GREEN_GUMMI },
    { MONSTER_ARIADOS, ITEM_GREEN_GUMMI },
    { MONSTER_CROCONAW, ITEM_BLUE_GUMMI },
    { MONSTER_UNOWN_QMARK, ITEM_GOLD_GUMMI },
    { MONSTER_EEVEE, ITEM_WHITE_GUMMI },
    { MONSTER_GEODUDE, ITEM_GRAY_GUMMI },
    { MONSTER_SPINARAK, ITEM_GREEN_GUMMI },
    { MONSTER_PILOSWINE, ITEM_CLEAR_GUMMI },
    { MONSTER_ILLUMISE, ITEM_GREEN_GUMMI },
    { MONSTER_ONIX, ITEM_GRAY_GUMMI },
    { MONSTER_ARCANINE, ITEM_RED_GUMMI },
    { MONSTER_SUDOWOODO, ITEM_GRAY_GUMMI },
    { MONSTER_WEEPINBELL, ITEM_GRASS_GUMMI },
    { MONSTER_VICTREEBEL, ITEM_GRASS_GUMMI },
    { MONSTER_WOOPER, ITEM_BLUE_GUMMI },
    { MONSTER_SWINUB, ITEM_CLEAR_GUMMI },
    { MONSTER_SKARMORY, ITEM_SILVER_GUMMI },
    { MONSTER_AIPOM, ITEM_WHITE_GUMMI },
    { MONSTER_ESPEON, ITEM_GOLD_GUMMI },
    { MONSTER_SKITTY, ITEM_WHITE_GUMMI },
    { MONSTER_DELCATTY, ITEM_WHITE_GUMMI },
    { MONSTER_HITMONCHAN, ITEM_ORANGE_GUMMI },
    { MONSTER_ELEKID, ITEM_YELLOW_GUMMI },
    { MONSTER_ELECTABUZZ, ITEM_YELLOW_GUMMI },
    { MONSTER_ENTEI, ITEM_RED_GUMMI },
    { MONSTER_SWELLOW, ITEM_WHITE_GUMMI },
    { MONSTER_FERALIGATR, ITEM_BLUE_GUMMI },
    { MONSTER_FURRET, ITEM_WHITE_GUMMI },
    { MONSTER_OCTILLERY, ITEM_BLUE_GUMMI },
    { MONSTER_PRIMEAPE, ITEM_ORANGE_GUMMI },
    { MONSTER_SENTRET, ITEM_WHITE_GUMMI },
    { MONSTER_STANTLER, ITEM_WHITE_GUMMI },
    { MONSTER_GLALIE, ITEM_CLEAR_GUMMI },
    { MONSTER_SPEAROW, ITEM_WHITE_GUMMI },
    { MONSTER_FEAROW, ITEM_WHITE_GUMMI },
    { MONSTER_OMASTAR, ITEM_GRAY_GUMMI },
    { MONSTER_OMANYTE, ITEM_GRAY_GUMMI },
    { MONSTER_GROWLITHE, ITEM_RED_GUMMI },
    { MONSTER_KYOGRE, ITEM_BLUE_GUMMI },
    { MONSTER_MACHAMP, ITEM_ORANGE_GUMMI },
    { MONSTER_DRAGONITE, ITEM_ROYAL_GUMMI },
    { MONSTER_PINSIR, ITEM_GREEN_GUMMI },
    { MONSTER_KECLEON, ITEM_WHITE_GUMMI },
    { MONSTER_SHUPPET, ITEM_PURPLE_GUMMI },
    { MONSTER_SNORLAX, ITEM_WHITE_GUMMI },
    { MONSTER_KABUTO, ITEM_GRAY_GUMMI },
    { MONSTER_KABUTOPS, ITEM_GRAY_GUMMI },
    { MONSTER_HITMONTOP, ITEM_ORANGE_GUMMI },
    { MONSTER_WARTORTLE, ITEM_BLUE_GUMMI },
    { MONSTER_BLASTOISE, ITEM_BLUE_GUMMI },
    { MONSTER_FARFETCHD, ITEM_WHITE_GUMMI },
    { MONSTER_CUBONE, ITEM_BROWN_GUMMI },
    { MONSTER_MAROWAK, ITEM_BROWN_GUMMI },
    { MONSTER_SILCOON, ITEM_GREEN_GUMMI },
    { MONSTER_KANGASKHAN, ITEM_WHITE_GUMMI },
    { MONSTER_BRELOOM, ITEM_GRASS_GUMMI },
    { MONSTER_SHROOMISH, ITEM_GRASS_GUMMI },
    { MONSTER_CARVANHA, ITEM_BLUE_GUMMI },
    { MONSTER_SUNFLORA, ITEM_GRASS_GUMMI },
    { MONSTER_TREECKO, ITEM_GRASS_GUMMI },
    { MONSTER_CATERPIE, ITEM_GREEN_GUMMI },
    { MONSTER_WINGULL, ITEM_BLUE_GUMMI },
    { MONSTER_GYARADOS, ITEM_BLUE_GUMMI },
    { MONSTER_RAPIDASH, ITEM_RED_GUMMI },
    { MONSTER_NINETALES, ITEM_RED_GUMMI },
    { MONSTER_GIRAFARIG, ITEM_WHITE_GUMMI },
    { MONSTER_KIRLIA, ITEM_GOLD_GUMMI },
    { MONSTER_BELLOSSOM, ITEM_GRASS_GUMMI },
    { MONSTER_KINGDRA, ITEM_BLUE_GUMMI },
    { MONSTER_KINGLER, ITEM_BLUE_GUMMI },
    { MONSTER_GLOOM, ITEM_GRASS_GUMMI },
    { MONSTER_MAWILE, ITEM_SILVER_GUMMI },
    { MONSTER_PINECO, ITEM_GREEN_GUMMI },
    { MONSTER_GROUDON, ITEM_BROWN_GUMMI },
    { MONSTER_GLIGAR, ITEM_BROWN_GUMMI },
    { MONSTER_MIGHTYENA, ITEM_BLACK_GUMMI },
    { MONSTER_KRABBY, ITEM_BLUE_GUMMI },
    { MONSTER_GRANBULL, ITEM_WHITE_GUMMI },
    { MONSTER_CROBAT, ITEM_PINK_GUMMI },
    { MONSTER_ABRA, ITEM_GOLD_GUMMI },
    { MONSTER_SLAKING, ITEM_WHITE_GUMMI },
    { MONSTER_WURMPLE, ITEM_GREEN_GUMMI },
    { MONSTER_GENGAR, ITEM_PURPLE_GUMMI },
    { MONSTER_TAUROS, ITEM_WHITE_GUMMI },
    { MONSTER_MAGIKARP, ITEM_BLUE_GUMMI },
    { MONSTER_MAGNEMITE, ITEM_YELLOW_GUMMI },
    { MONSTER_GASTLY, ITEM_PURPLE_GUMMI },
    { MONSTER_HAUNTER, ITEM_PURPLE_GUMMI },
    { MONSTER_TORKOAL, ITEM_RED_GUMMI },
    { MONSTER_MACHOKE, ITEM_ORANGE_GUMMI },
    { MONSTER_KAKUNA, ITEM_GREEN_GUMMI },
    { MONSTER_GULPIN, ITEM_PINK_GUMMI },
    { MONSTER_ARON, ITEM_SILVER_GUMMI },
    { MONSTER_PSYDUCK, ITEM_BLUE_GUMMI },
    { MONSTER_LAIRON, ITEM_SILVER_GUMMI },
    { MONSTER_WHISMUR, ITEM_WHITE_GUMMI },
    { MONSTER_NUZLEAF, ITEM_GRASS_GUMMI },
    { MONSTER_PHANPY, ITEM_BROWN_GUMMI },
    { MONSTER_SHELGON, ITEM_ROYAL_GUMMI },
    { MONSTER_RATTATA, ITEM_WHITE_GUMMI },
    { MONSTER_GOLDUCK, ITEM_BLUE_GUMMI },
    { MONSTER_GOLBAT, ITEM_PINK_GUMMI },
    { MONSTER_GOLEM, ITEM_GRAY_GUMMI },
    { MONSTER_GRAVELER, ITEM_GRAY_GUMMI },
    { MONSTER_VENONAT, ITEM_GREEN_GUMMI },
    { MONSTER_GARDEVOIR, ITEM_GOLD_GUMMI },
    { MONSTER_RHYDON, ITEM_BROWN_GUMMI },
    { MONSTER_RHYHORN, ITEM_BROWN_GUMMI },
    { MONSTER_GOREBYSS, ITEM_BLUE_GUMMI },
    { MONSTER_PUPITAR, ITEM_GRAY_GUMMI },
    { MONSTER_CORSOLA, ITEM_BLUE_GUMMI },
    { MONSTER_CACNEA, ITEM_GRASS_GUMMI },
    { MONSTER_DUSCLOPS, ITEM_PURPLE_GUMMI },
    { MONSTER_SHARPEDO, ITEM_BLUE_GUMMI },
    { MONSTER_HITMONLEE, ITEM_ORANGE_GUMMI },
    { MONSTER_ZANGOOSE, ITEM_WHITE_GUMMI },
    { MONSTER_ZAPDOS, ITEM_YELLOW_GUMMI },
    { MONSTER_JOLTEON, ITEM_YELLOW_GUMMI },
    { MONSTER_SANDSHREW, ITEM_BROWN_GUMMI },
    { MONSTER_SANDSLASH, ITEM_BROWN_GUMMI },
    { MONSTER_SEADRA, ITEM_BLUE_GUMMI },
    { MONSTER_RELICANTH, ITEM_BLUE_GUMMI },
    { MONSTER_SHELLDER, ITEM_BLUE_GUMMI },
    { MONSTER_ZIGZAGOON, ITEM_WHITE_GUMMI },
    { MONSTER_CRAWDAUNT, ITEM_BLUE_GUMMI },
    { MONSTER_VAPOREON, ITEM_BLUE_GUMMI },
    { MONSTER_SCEPTILE, ITEM_GRASS_GUMMI },
    { MONSTER_DEWGONG, ITEM_BLUE_GUMMI },
    { MONSTER_GROVYLE, ITEM_GRASS_GUMMI },
    { MONSTER_BANETTE, ITEM_PURPLE_GUMMI },
    { MONSTER_JIRACHI, ITEM_SILVER_GUMMI },
    { MONSTER_SUICUNE, ITEM_BLUE_GUMMI },
    { MONSTER_STARMIE, ITEM_BLUE_GUMMI },
    { MONSTER_SCYTHER, ITEM_GREEN_GUMMI },
    { MONSTER_ZUBAT, ITEM_PINK_GUMMI },
    { MONSTER_TAILLOW, ITEM_WHITE_GUMMI },
    { MONSTER_BEEDRILL, ITEM_GREEN_GUMMI },
    { MONSTER_HYPNO, ITEM_GOLD_GUMMI },
    { MONSTER_DROWZEE, ITEM_GOLD_GUMMI },
    { MONSTER_SQUIRTLE, ITEM_BLUE_GUMMI },
    { MONSTER_CELEBI, ITEM_GOLD_GUMMI },
    { MONSTER_WYNAUT, ITEM_GOLD_GUMMI },
    { MONSTER_WOBBUFFET, ITEM_GOLD_GUMMI },
    { MONSTER_SOLROCK, ITEM_GRAY_GUMMI },
    { MONSTER_SHIFTRY, ITEM_GRASS_GUMMI },
    { MONSTER_DUGTRIO, ITEM_BROWN_GUMMI },
    { MONSTER_HORSEA, ITEM_BLUE_GUMMI },
    { MONSTER_BAGON, ITEM_ROYAL_GUMMI },
    { MONSTER_SEEDOT, ITEM_GRASS_GUMMI },
    { MONSTER_SPHEAL, ITEM_CLEAR_GUMMI },
    { MONSTER_EXEGGCUTE, ITEM_GRASS_GUMMI },
    { MONSTER_BELDUM, ITEM_SILVER_GUMMI },
    { MONSTER_CHIKORITA, ITEM_GRASS_GUMMI },
    { MONSTER_MEDICHAM, ITEM_ORANGE_GUMMI },
    { MONSTER_CHINCHOU, ITEM_BLUE_GUMMI },
    { MONSTER_CHIMECHO, ITEM_GOLD_GUMMI },
    { MONSTER_ALTARIA, ITEM_ROYAL_GUMMI },
    { MONSTER_SWABLU, ITEM_WHITE_GUMMI },
    { MONSTER_NINCADA, ITEM_GREEN_GUMMI },
    { MONSTER_SHUCKLE, ITEM_GREEN_GUMMI },
    { MONSTER_DIGLETT, ITEM_BROWN_GUMMI },
    { MONSTER_DEOXYS_SPEED, ITEM_GOLD_GUMMI },
    { MONSTER_NINJASK, ITEM_GREEN_GUMMI },
    { MONSTER_REMORAID, ITEM_BLUE_GUMMI },
    { MONSTER_DELIBIRD, ITEM_CLEAR_GUMMI },
    { MONSTER_HOUNDOUR, ITEM_BLACK_GUMMI },
    { MONSTER_AMPHAROS, ITEM_YELLOW_GUMMI },
    { MONSTER_DODUO, ITEM_WHITE_GUMMI },
    { MONSTER_DODRIO, ITEM_WHITE_GUMMI },
    { MONSTER_SMEARGLE, ITEM_WHITE_GUMMI },
    { MONSTER_KOFFING, ITEM_PINK_GUMMI },
    { MONSTER_TENTACRUEL, ITEM_BLUE_GUMMI },
    { MONSTER_DUSTOX, ITEM_GREEN_GUMMI },
    { MONSTER_TOGETIC, ITEM_WHITE_GUMMI },
    { MONSTER_TOGEPI, ITEM_WHITE_GUMMI },
    { MONSTER_LOUDRED, ITEM_WHITE_GUMMI },
    { MONSTER_GOLDEEN, ITEM_BLUE_GUMMI },
    { MONSTER_BARBOACH, ITEM_BLUE_GUMMI },
    { MONSTER_SEALEO, ITEM_CLEAR_GUMMI },
    { MONSTER_WALREIN, ITEM_CLEAR_GUMMI },
    { MONSTER_METAPOD, ITEM_GREEN_GUMMI },
    { MONSTER_TROPIUS, ITEM_GRASS_GUMMI },
    { MONSTER_DONPHAN, ITEM_BROWN_GUMMI },
    { MONSTER_NUMEL, ITEM_RED_GUMMI },
    { MONSTER_ODDISH, ITEM_GRASS_GUMMI },
    { MONSTER_TRAPINCH, ITEM_BROWN_GUMMI },
    { MONSTER_EXEGGUTOR, ITEM_GRASS_GUMMI },
    { MONSTER_SLAKOTH, ITEM_WHITE_GUMMI },
    { MONSTER_WHISCASH, ITEM_BLUE_GUMMI },
    { MONSTER_NIDOKING, ITEM_PINK_GUMMI },
    { MONSTER_NIDOQUEEN, ITEM_PINK_GUMMI },
    { MONSTER_NIDORAN_F, ITEM_PINK_GUMMI },
    { MONSTER_NIDORAN_M, ITEM_PINK_GUMMI },
    { MONSTER_NIDORINA, ITEM_PINK_GUMMI },
    { MONSTER_NIDORINO, ITEM_PINK_GUMMI },
    { MONSTER_MEOWTH, ITEM_WHITE_GUMMI },
    { MONSTER_SNEASEL, ITEM_BLACK_GUMMI },
    { MONSTER_POLIWHIRL, ITEM_BLUE_GUMMI },
    { MONSTER_POLITOED, ITEM_BLUE_GUMMI },
    { MONSTER_POLIWRATH, ITEM_BLUE_GUMMI },
    { MONSTER_POLIWAG, ITEM_BLUE_GUMMI },
    { MONSTER_QUAGSIRE, ITEM_BLUE_GUMMI },
    { MONSTER_SHEDINJA, ITEM_GREEN_GUMMI },
    { MONSTER_MARSHTOMP, ITEM_BLUE_GUMMI },
    { MONSTER_NATU, ITEM_GOLD_GUMMI },
    { MONSTER_XATU, ITEM_GOLD_GUMMI },
    { MONSTER_CLAYDOL, ITEM_BROWN_GUMMI },
    { MONSTER_CACTURNE, ITEM_GRASS_GUMMI },
    { MONSTER_DUNSPARCE, ITEM_WHITE_GUMMI },
    { MONSTER_NOSEPASS, ITEM_GRAY_GUMMI },
    { MONSTER_CLAMPERL, ITEM_BLUE_GUMMI },
    { MONSTER_SEEL, ITEM_BLUE_GUMMI },
    { MONSTER_STEELIX, ITEM_SILVER_GUMMI },
    { MONSTER_CAMERUPT, ITEM_RED_GUMMI },
    { MONSTER_EXPLOUD, ITEM_WHITE_GUMMI },
    { MONSTER_TYPHLOSION, ITEM_RED_GUMMI },
    { MONSTER_DRAGONAIR, ITEM_ROYAL_GUMMI },
    { MONSTER_BLAZIKEN, ITEM_RED_GUMMI },
    { MONSTER_LOMBRE, ITEM_BLUE_GUMMI },
    { MONSTER_LOTAD, ITEM_BLUE_GUMMI },
    { MONSTER_BUTTERFREE, ITEM_GREEN_GUMMI },
    { MONSTER_SCIZOR, ITEM_GREEN_GUMMI },
    { MONSTER_SPINDA, ITEM_WHITE_GUMMI },
    { MONSTER_HOPPIP, ITEM_GRASS_GUMMI },
    { MONSTER_SPOINK, ITEM_GOLD_GUMMI },
    { MONSTER_BLISSEY, ITEM_WHITE_GUMMI },
    { MONSTER_SEVIPER, ITEM_PINK_GUMMI },
    { MONSTER_PARAS, ITEM_GREEN_GUMMI },
    { MONSTER_PARASECT, ITEM_GREEN_GUMMI },
    { MONSTER_QWILFISH, ITEM_BLUE_GUMMI },
    { MONSTER_HARIYAMA, ITEM_ORANGE_GUMMI },
    { MONSTER_MR_MIME, ITEM_GOLD_GUMMI },
    { MONSTER_TYROGUE, ITEM_ORANGE_GUMMI },
    { MONSTER_CLOYSTER, ITEM_BLUE_GUMMI },
    { MONSTER_VOLBEAT, ITEM_GREEN_GUMMI },
    { MONSTER_TYRANITAR, ITEM_GRAY_GUMMI },
    { MONSTER_HUNTAIL, ITEM_BLUE_GUMMI },
    { MONSTER_CLEFFA, ITEM_WHITE_GUMMI },
    { MONSTER_WEEDLE, ITEM_GREEN_GUMMI },
    { MONSTER_PIKACHU, ITEM_YELLOW_GUMMI },
    { MONSTER_CLEFABLE, ITEM_WHITE_GUMMI },
    { MONSTER_PIDGEOT, ITEM_WHITE_GUMMI },
    { MONSTER_PIDGEOTTO, ITEM_WHITE_GUMMI },
    { MONSTER_PICHU, ITEM_YELLOW_GUMMI },
    { MONSTER_CLEFAIRY, ITEM_WHITE_GUMMI },
    { MONSTER_CHARMANDER, ITEM_RED_GUMMI },
    { MONSTER_STARYU, ITEM_BLUE_GUMMI },
    { MONSTER_CYNDAQUIL, ITEM_RED_GUMMI },
    { MONSTER_VIBRAVA, ITEM_BROWN_GUMMI },
    { MONSTER_SUNKERN, ITEM_GRASS_GUMMI },
    { MONSTER_TEDDIURSA, ITEM_WHITE_GUMMI },
    { MONSTER_VOLTORB, ITEM_YELLOW_GUMMI },
    { MONSTER_FEEBAS, ITEM_BLUE_GUMMI },
    { MONSTER_MOLTRES, ITEM_RED_GUMMI },
    { MONSTER_FLAREON, ITEM_RED_GUMMI },
    { MONSTER_ALAKAZAM, ITEM_GOLD_GUMMI },
    { MONSTER_MAGMAR, ITEM_RED_GUMMI },
    { MONSTER_GRUMPIG, ITEM_GOLD_GUMMI },
    { MONSTER_FORRETRESS, ITEM_GREEN_GUMMI },
    { MONSTER_WIGGLYTUFF, ITEM_WHITE_GUMMI },
    { MONSTER_IVYSAUR, ITEM_GRASS_GUMMI },
    { MONSTER_BULBASAUR, ITEM_GRASS_GUMMI },
    { MONSTER_VENUSAUR, ITEM_GRASS_GUMMI },
    { MONSTER_AERODACTYL, ITEM_GRAY_GUMMI },
    { MONSTER_MAGBY, ITEM_RED_GUMMI },
    { MONSTER_IGGLYBUFF, ITEM_WHITE_GUMMI },
    { MONSTER_FLYGON, ITEM_BROWN_GUMMI },
    { MONSTER_PLUSLE, ITEM_YELLOW_GUMMI },
    { MONSTER_UMBREON, ITEM_BLACK_GUMMI },
    { MONSTER_ARTICUNO, ITEM_CLEAR_GUMMI },
    { MONSTER_JIGGLYPUFF, ITEM_WHITE_GUMMI },
    { MONSTER_SNUBBULL, ITEM_WHITE_GUMMI },
    { MONSTER_CORPHISH, ITEM_BLUE_GUMMI },
    { MONSTER_BAYLEEF, ITEM_GRASS_GUMMI },
    { MONSTER_GRIMER, ITEM_PINK_GUMMI },
    { MONSTER_MUK, ITEM_PINK_GUMMI },
    { MONSTER_HERACROSS, ITEM_GREEN_GUMMI },
    { MONSTER_PELIPPER, ITEM_BLUE_GUMMI },
    { MONSTER_HOUNDOOM, ITEM_BLACK_GUMMI },
    { MONSTER_PERSIAN, ITEM_WHITE_GUMMI },
    { MONSTER_LICKITUNG, ITEM_WHITE_GUMMI },
    { MONSTER_HO_OH, ITEM_RED_GUMMI },
    { MONSTER_WAILORD, ITEM_BLUE_GUMMI },
    { MONSTER_WAILMER, ITEM_BLUE_GUMMI },
    { MONSTER_HOOTHOOT, ITEM_WHITE_GUMMI },
    { MONSTER_SALAMENCE, ITEM_ROYAL_GUMMI },
    { MONSTER_AGGRON, ITEM_SILVER_GUMMI },
    { MONSTER_POOCHYENA, ITEM_BLACK_GUMMI },
    { MONSTER_PIDGEY, ITEM_WHITE_GUMMI },
    { MONSTER_PONYTA, ITEM_RED_GUMMI },
    { MONSTER_SKIPLOOM, ITEM_GRASS_GUMMI },
    { MONSTER_PORYGON, ITEM_WHITE_GUMMI },
    { MONSTER_PORYGON2, ITEM_WHITE_GUMMI },
    { MONSTER_CASTFORM_RAINY, ITEM_WHITE_GUMMI },
    { MONSTER_MINUN, ITEM_YELLOW_GUMMI },
    { MONSTER_MAGCARGO, ITEM_RED_GUMMI },
    { MONSTER_MAKUHITA, ITEM_ORANGE_GUMMI },
    { MONSTER_SLUGMA, ITEM_RED_GUMMI },
    { MONSTER_QUILAVA, ITEM_RED_GUMMI },
    { MONSTER_BELLSPROUT, ITEM_GRASS_GUMMI },
    { MONSTER_WEEZING, ITEM_PINK_GUMMI },
    { MONSTER_LINOONE, ITEM_WHITE_GUMMI },
    { MONSTER_CASCOON, ITEM_GREEN_GUMMI },
    { MONSTER_MARILL, ITEM_BLUE_GUMMI },
    { MONSTER_AZUMARILL, ITEM_BLUE_GUMMI },
    { MONSTER_SWALOT, ITEM_PINK_GUMMI },
    { MONSTER_ELECTRODE, ITEM_YELLOW_GUMMI },
    { MONSTER_MANKEY, ITEM_ORANGE_GUMMI },
    { MONSTER_MANTINE, ITEM_BLUE_GUMMI },
    { MONSTER_MUDKIP, ITEM_BLUE_GUMMI },
    { MONSTER_DRATINI, ITEM_ROYAL_GUMMI },
    { MONSTER_MEW, ITEM_GOLD_GUMMI },
    { MONSTER_MEWTWO, ITEM_GOLD_GUMMI },
    { MONSTER_MILTANK, ITEM_WHITE_GUMMI },
    { MONSTER_MILOTIC, ITEM_BLUE_GUMMI },
    { MONSTER_MISDREAVUS, ITEM_PURPLE_GUMMI },
    { MONSTER_SMOOCHUM, ITEM_CLEAR_GUMMI },
    { MONSTER_MEGANIUM, ITEM_GRASS_GUMMI },
    { MONSTER_METAGROSS, ITEM_SILVER_GUMMI },
    { MONSTER_DITTO, ITEM_WHITE_GUMMI },
    { MONSTER_METANG, ITEM_SILVER_GUMMI },
    { MONSTER_TENTACOOL, ITEM_BLUE_GUMMI },
    { MONSTER_MAREEP, ITEM_YELLOW_GUMMI },
    { MONSTER_FLAAFFY, ITEM_YELLOW_GUMMI },
    { MONSTER_VENOMOTH, ITEM_GREEN_GUMMI },
    { MONSTER_TANGELA, ITEM_GRASS_GUMMI },
    { MONSTER_BALTOY, ITEM_BROWN_GUMMI },
    { MONSTER_SLOWKING, ITEM_BLUE_GUMMI },
    { MONSTER_SLOWBRO, ITEM_BLUE_GUMMI },
    { MONSTER_SLOWPOKE, ITEM_BLUE_GUMMI },
    { MONSTER_MURKROW, ITEM_BLACK_GUMMI },
    { MONSTER_SABLEYE, ITEM_BLACK_GUMMI },
    { MONSTER_VIGOROTH, ITEM_WHITE_GUMMI },
    { MONSTER_YANMA, ITEM_GREEN_GUMMI },
    { MONSTER_SNORUNT, ITEM_CLEAR_GUMMI },
    { MONSTER_CRADILY, ITEM_GRAY_GUMMI },
    { MONSTER_KADABRA, ITEM_GOLD_GUMMI },
    { MONSTER_LARVITAR, ITEM_GRAY_GUMMI },
    { MONSTER_DUSKULL, ITEM_PURPLE_GUMMI },
    { MONSTER_NOCTOWL, ITEM_WHITE_GUMMI },
    { MONSTER_RAIKOU, ITEM_YELLOW_GUMMI },
    { MONSTER_RAICHU, ITEM_YELLOW_GUMMI },
    { MONSTER_MANECTRIC, ITEM_YELLOW_GUMMI },
    { MONSTER_SWAMPERT, ITEM_BLUE_GUMMI },
    { MONSTER_ELECTRIKE, ITEM_YELLOW_GUMMI },
    { MONSTER_CHANSEY, ITEM_WHITE_GUMMI },
    { MONSTER_RATICATE, ITEM_WHITE_GUMMI },
    { MONSTER_LATIAS, ITEM_ROYAL_GUMMI },
    { MONSTER_LATIOS, ITEM_ROYAL_GUMMI },
    { MONSTER_LUVDISC, ITEM_BLUE_GUMMI },
    { MONSTER_LAPRAS, ITEM_BLUE_GUMMI },
    { MONSTER_VILEPLUME, ITEM_GRASS_GUMMI },
    { MONSTER_RALTS, ITEM_GOLD_GUMMI },
    { MONSTER_LANTURN, ITEM_BLUE_GUMMI },
    { MONSTER_CHARMELEON, ITEM_RED_GUMMI },
    { MONSTER_CHARIZARD, ITEM_RED_GUMMI },
    { MONSTER_LILEEP, ITEM_GRAY_GUMMI },
    { MONSTER_URSARING, ITEM_WHITE_GUMMI },
    { MONSTER_JYNX, ITEM_CLEAR_GUMMI },
    { MONSTER_LUGIA, ITEM_GOLD_GUMMI },
    { MONSTER_LUNATONE, ITEM_GRAY_GUMMI },
    { MONSTER_AZURILL, ITEM_WHITE_GUMMI },
    { MONSTER_LUDICOLO, ITEM_BLUE_GUMMI },
    { MONSTER_MAGNETON, ITEM_YELLOW_GUMMI },
    { MONSTER_REGICE, ITEM_CLEAR_GUMMI },
    { MONSTER_REGISTEEL, ITEM_SILVER_GUMMI },
    { MONSTER_REGIROCK, ITEM_GRAY_GUMMI },
    { MONSTER_RAYQUAZA, ITEM_ROYAL_GUMMI },
    { MONSTER_LEDIAN, ITEM_GREEN_GUMMI },
    { MONSTER_LEDYBA, ITEM_GREEN_GUMMI },
    { MONSTER_VULPIX, ITEM_RED_GUMMI },
    { MONSTER_ROSELIA, ITEM_GRASS_GUMMI },
    { MONSTER_COMBUSKEN, ITEM_RED_GUMMI },
    { MONSTER_JUMPLUFF, ITEM_GRASS_GUMMI },
    { MONSTER_TOTODILE, ITEM_BLUE_GUMMI },
    { MONSTER_MACHOP, ITEM_ORANGE_GUMMI }
};

ALIGNED(4) const u8 gMankeyMission[] = _("Punish bad {COLOR YELLOW}Mankey{RESET}!");
ALIGNED(4) const u8 gSmeargleMission[] = _("{COLOR YELLOW}Smeargle{RESET}'s desperate plea!");
ALIGNED(4) const u8 gMedichamMission[] = _("{COLOR YELLOW}Medicham{RESET}: Help me!");
ALIGNED(4) const u8 gUnknown_80E8830[] = _("Deliver one {COLOR GREEN}%s{RESET}.");
ALIGNED(4) const u8 gUnknown_80E8848[] = _("One {COLOR GREEN}%s{RESET} wanted!");
ALIGNED(4) const u8 gUnknown_80E885C[] = _("Save my child!");
ALIGNED(4) const u8 gUnknown_80E886C[] = _("Escort me to my love!");
ALIGNED(4) const u8 gUnknown_80E8884[] = _("Near %s");
ALIGNED(4) const u8 gUnknown_80E888C[] = _("Rescue Description");
ALIGNED(4) const u8 gMankeyMissionDescription[] = _("Please punish bad {COLOR YELLOW}Mankey{RESET}'s gang.");

ALIGNED(4) const u8 gSmeargleMissionDescription[] = _(
    "I didn't want to become a grown-up, so I\n"
    "fled, but now I've lost my way! Help!");

ALIGNED(4) const u8 gMedichamMissionDescription[] = _(
    "This is {COLOR YELLOW}Medicham{RESET}. Rescue me, please!\n"
    "The reward is a secret〜♪ ");

ALIGNED(4) const u8 gUnknown_80E8968[] = _(
    "With the item {COLOR GREEN}%s{RESET}, I can\n"
    "evolve! I'm yearning to evolve! Help!");

ALIGNED(4) const u8 gUnknown_80E89B0[] = _(
    "The {COLOR GREEN}%s{RESET}! What I love to eat\n"
    "and can't live without! Please get one!");

ALIGNED(4) const u8 gUnknown_80E89FC[] = _(
    "This is a rescue through communication.\n"
    "Get a friend to help you!");

ALIGNED(4) const u8 gUnknown_80E8A40[] = _(
    "This is a rescue through communication.\n"
    "Rescue a friend!");

ALIGNED(4) const u8 gUnknown_80E8A7C[] = _(
    "This is a rescue through communication.\n"
    "Send your thanks to your friend!");

ALIGNED(4) const u8 gUnknown_80E8AC8[] = _("Client:");
ALIGNED(4) const u8 gUnknown_80E8AD0[] = _("%s{COLOR GREEN}（%s）{RESET}");
ALIGNED(4) const u8 gUnknown_80E8AE0[] = _("Objective:");
ALIGNED(4) const u8 gUnknown_80E8AEC[] = _("Friend Rescue");
ALIGNED(4) const u8 gUnknown_80E8AFC[] = _("Deliver {COLOR GREEN}%s{RESET}.");
ALIGNED(4) const u8 gUnknown_80E8B10[] = _("Find {COLOR GREEN}%s{RESET}.");
ALIGNED(4) const u8 gUnknown_80E8B20[] = _("Help me.");
ALIGNED(4) const u8 gUnknown_80E8B2C[] = _("Escort to {COLOR YELLOW}%s{RESET}.");
ALIGNED(4) const u8 gUnknown_80E8B40[] = _("Find {COLOR YELLOW}%s{RESET}.");
ALIGNED(4) const u8 gSpecialMissionText[] = _("Special mission");
ALIGNED(4) const u8 gPlaceText[] = _("Place:");
ALIGNED(4) const u8 gDifficultyText[] = _("Difficulty:");
ALIGNED(4) const u8 gRewardText[] = _("Reward:");
ALIGNED(4) const u8 gUnknown_80E8B7C[] = _("Wonder Mail:");
