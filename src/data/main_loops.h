static const unkTalkTable sBaseKindTable[17] = {
    [0] = { .unk0 = 0, .species = MONSTER_PIKACHU },
    [1] = { .unk0 = 1, .species = MONSTER_MEOWTH },
    [2] = { .unk0 = 2, .species = MONSTER_EEVEE },
    [3] = { .unk0 = 3, .species = MONSTER_SKITTY },
    [4] = { .unk0 = 4, .species = MONSTER_SQUIRTLE },
    [5] = { .unk0 = 5, .species = MONSTER_TOTODILE },
    [6] = { .unk0 = 6, .species = MONSTER_MUDKIP },
    [7] = { .unk0 = 7, .species = MONSTER_PSYDUCK },
    [8] = { .unk0 = 8, .species = MONSTER_CHARMANDER },
    [9] = { .unk0 = 9, .species = MONSTER_TORCHIC },
    [10] = { .unk0 = 10, .species = MONSTER_CYNDAQUIL },
    [11] = { .unk0 = 11, .species = MONSTER_CUBONE },
    [12] = { .unk0 = 12, .species = MONSTER_MACHOP },
    [13] = { .unk0 = 13, .species = MONSTER_BULBASAUR },
    [14] = { .unk0 = 14, .species = MONSTER_CHIKORITA },
    [15] = { .unk0 = 15, .species = MONSTER_TREECKO },
    [16] = { .unk0 = 0, .species = MONSTER_NONE },
};

static const unkTalkTable sTalkKindTable[5] = {
    [0] = { .unk0 = 1, .species = MONSTER_SQUIRTLE },
    [1] = { .unk0 = 1, .species = MONSTER_TOTODILE },
    [2] = { .unk0 = 3, .species = MONSTER_TORCHIC },
    [3] = { .unk0 = 3, .species = MONSTER_CHIKORITA },
    [4] = { .unk0 = 2, .species = MONSTER_NONE },
};

ALIGNED(4) static const u8 sPMDBuildVersion[] = _("PKDi ver 1.0 [Apr 28 2006] 16:37:54");

ALIGNED(4) static const u8 sTitlen0[] = _("titlen0");
ALIGNED(4) static const u8 sTitlen1[] = _("titlen1");
ALIGNED(4) static const u8 sTitlen2[] = _("titlen2");
/* static */ // TODO: Uncomment
ALIGNED(4) const u8* const sLoadScreenBackgroundFileNames[3] = { sTitlen0, sTitlen1, sTitlen2 };

ALIGNED(4) static const u8 sTitlen0p[] = _("titlen0p");
ALIGNED(4) static const u8 sTitlen1p[] = _("titlen1p");
ALIGNED(4) static const u8 sTitlen2p[] = _("titlen2p");
/* static */ // TODO: Uncomment
ALIGNED(4) const u8* const sLoadScreenBackgroundPaletteFileNames[3] = { sTitlen0p, sTitlen1p, sTitlen2p };

ALIGNED(4) static const u8 sSaveTextQuicksaving[] = _(
    "{CENTER_ALIGN}Quicksaving your adventure...\n"
    "{CENTER_ALIGN}Please don't turn off the power.");

ALIGNED(4) static const u8 sSaveTextYourAdventureHasBeenSaved[] = _("{CENTER_ALIGN}Your adventure has been saved.");

ALIGNED(4) static const u8 sSaveTextYourAdventureHasBeenSavedLong[] = _(
    "{CENTER_ALIGN}Your adventure has been saved.\n"
    "{CENTER_ALIGN}When you are in a dungeon, quicksave\n"
    "{CENTER_ALIGN}your progress before ending the game.");

ALIGNED(4) static const u8 sSaveTextTheDataCouldNotBeWritten[] = _(
    "{CENTER_ALIGN}The data could not be written.\n"
    "{CENTER_ALIGN}Please turn off the power and remove\n"
    "{CENTER_ALIGN}and reinsert the DS Card.");

ALIGNED(4) static const u8 sSaveTextFailed[] = _("{CENTER_ALIGN}Save failed.");

ALIGNED(4) static const u8 sSaveTextError[] = _(
    "{CENTER_ALIGN}Error reading data.\n"
    "{CENTER_ALIGN}Please turn off the power and reinsert\n"
    "{CENTER_ALIGN}the DS Game Card.");

ALIGNED(4) static const u8 sSaveTextCantResume[] = _(
    "{CENTER_ALIGN}Your data was not properly saved,\n"
    "{CENTER_ALIGN}so your game cannot be resumed\n"
    "{CENTER_ALIGN}from your last spot.{EXTRA_MSG}"
    "{CENTER_ALIGN}Your last outing is considered a defeat.\n"
    "{CENTER_ALIGN}Before shutting down, save in your\n"
    "{CENTER_ALIGN}team base, or quicksave in a dungeon.");

ALIGNED(4) static const u8 sSaveTextMayNotResume[] = _(
    "{CENTER_ALIGN}You may not resume your dungeon\n"
    "{CENTER_ALIGN}adventure using this saved data.\n"
    "{CENTER_ALIGN}Your last outing is considered a defeat.");