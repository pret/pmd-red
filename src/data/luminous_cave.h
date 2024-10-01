static const UnkTextStruct2 sUnknown_80DC9E8 = {
    0, 0, 0, 0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

static const UnkTextStruct2 sUnknown_80DCA00 = {
    0, 0, 0, 0,
    3,
    20, 4,
    6, 3,
    3, 0,
    NULL
};

ALIGNED(4) static const u8 sEvolve0[] = _("Evolve");
UNUSED ALIGNED(4) const u8* const sEvolve[] = { sEvolve0 };

ALIGNED(4) static const u8 sNo0[] = _("No");
UNUSED ALIGNED(4) const u8* const sNo[] = { sNo0 };

ALIGNED(4) static const u8 sYes0[] = _("Yes");
UNUSED ALIGNED(4) const u8* const sYes[] = { sYes0 };

ALIGNED(4) static const u8 sSeekEvolutionIntro[] = _(
    "{CENTER_ALIGN}...{WAIT_PRESS}A voice emanates from somewhere...{EXTRA_MSG}"
    "{CENTER_ALIGN}...Ye who seek awakening...{EXTRA_MSG}"
    "{CENTER_ALIGN}This is Luminous Cave.{WAIT_PRESS}\n"
    "{CENTER_ALIGN}Do ye seek a new evolution?");

ALIGNED(4) static const u8 sSeekEvolutionPrompt[] = _(
    "{CENTER_ALIGN}Do ye seek evolution?");

ALIGNED(4) static const u8 sEvolveInfo[] = _(
    "{CENTER_ALIGN}There are those among Pokémon\n"
    "{CENTER_ALIGN}that can evolve.{EXTRA_MSG}"
    "{CENTER_ALIGN}Such Pokémon can evolve at this very\n"
    "{CENTER_ALIGN}spot if they satisfy certain conditions.{EXTRA_MSG}"
    "{CENTER_ALIGN}Evolution brings about changes\n"
    "{CENTER_ALIGN}in appearance and abilities.{EXTRA_MSG}"
    "{CENTER_ALIGN}Not only that, some Pokémon even change\n"
    "{CENTER_ALIGN}type and learn different moves.{EXTRA_MSG}"
    "{CENTER_ALIGN}However...{WAIT_PRESS} The requirements for\n"
    "{CENTER_ALIGN}evolution differ among Pokémon.{EXTRA_MSG}"
    "{CENTER_ALIGN}Some become ready for evolution\n"
    "{CENTER_ALIGN}merely by leveling up.{EXTRA_MSG}"
    "{CENTER_ALIGN}Still others may need special items\n"
    "{CENTER_ALIGN}to attain evolution.{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye must also be aware of this:{EXTRA_MSG}"
    "{CENTER_ALIGN}Once it has evolved, a Pokémon\n"
    "{CENTER_ALIGN}can never regain its previous form.{EXTRA_MSG}"
    "{CENTER_ALIGN}That is why ye must think carefully\n"
    "{CENTER_ALIGN}before committing to evolution.");

ALIGNED(4) static const u8 sYeShallReturn[] = _(
    "{CENTER_ALIGN}Ye shall return if evolution\n"
    "{CENTER_ALIGN}is what ye seek...");

ALIGNED(4) static const u8 sGiveItemPrompt[] = _(
    "{CENTER_ALIGN}Will ye give an item for evolution?");

ALIGNED(4) static const u8 sGiveAnotherItemPrompt[] = _(
    "{CENTER_ALIGN}Will ye give yet another item?");

ALIGNED(4) static const u8 sLackWhatIsNeeded[] = _(
    "{CENTER_ALIGN}Alas, ye seem to lack what is needed\n"
    "{CENTER_ALIGN}for evolution.");

ALIGNED(4) static const u8 sOnlyOneItem[] = _(
    "{CENTER_ALIGN}Ye seem to have but one item.");

ALIGNED(4) static const u8 sLetUsBegin[] = _(
    "{CENTER_ALIGN}...Ye who seek awakening...\n"
    "{CENTER_ALIGN}Let us begin.");

ALIGNED(4) static const u8 sFmtChangedAppearance[] = _(
    "{CENTER_ALIGN}...{WAIT_PRESS}{ARG_NICKNAME_0} is undergoing changes...{EXTRA_MSG}"
    "{CENTER_ALIGN}{ARG_NICKNAME_0}'s appearance changed...{EXTRA_MSG}");

ALIGNED(4) static const u8 sFmtEvolved[] = _(
    "{CENTER_ALIGN}It evolved from {COLOR_1 GREEN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN}to {COLOR_1 YELLOW}{ARG_POKEMON_1}{END_COLOR_TEXT_1}!");

ALIGNED(4) static const u8 sComeAlone[] = _(
    "{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}One cannot evolve if one\n"
    "{CENTER_ALIGN}is in the company of others.{EXTRA_MSG}"
    "{CENTER_ALIGN}Come alone if ye wish to evolve.");

ALIGNED(4) static const u8 sLackLevel[] = _(
    "{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye have not high enough a level.");

ALIGNED(4) static const u8 sNoMoreEvolutions[] = _(
    "{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye cannot evolve anymore.");

ALIGNED(4) static const u8 sLackFriendArea[] = _(
    "{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye need your Friend Area to evolve.");

ALIGNED(4) static const u8 sLackFriendAreaRoom[] = _(
    "{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
    "{CENTER_ALIGN}The Friend Area to which ye shall go\n"
    "{CENTER_ALIGN}has no room for ye.");

ALIGNED(4) static const u8 sLackIQ[] = _(
    "{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye seem to lack the IQ to evolve.");

ALIGNED(4) static const u8 sLackItem[] = _(
    "{CENTER_ALIGN}{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye seem to lack an item to evolve.");

ALIGNED(4) static const u8 sCannotEvolveYet[] = _(
    "{CENTER_ALIGN}{CENTER_ALIGN}...{EXTRA_MSG}"
    "{CENTER_ALIGN}Ye cannot evolve yet. ");

ALIGNED(4) static const u8 sMustGiveName[] = _(
    "{CENTER_ALIGN}Ye must give a name to\n"
    "{CENTER_ALIGN}the evolved Pokémon. ");

// TODO: This for a file after which had no data
ALIGNED(4) static const u8 sFill1[] = _("pksdir0");