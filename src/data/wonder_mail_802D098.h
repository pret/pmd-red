static const Window sUnknown_80DFDD4 = {
    0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

UNUSED static const Window sUnknown_80DFDEC = {
    0,
    3,
    3, 3,
    7, 3,
    3, 0,
    NULL
};

static const Window sUnknown_80DFE04 = {
    0,
    3,
    21, 6,
    7, 3,
    3, 0,
    NULL
};

static const Window sUnknown_80DFE1C = {
    0,
    3,
    21, 15,
    7, 3,
    3, 0,
    NULL
};

UNUSED static const Window sUnknown_80DFE34 = {
    0,
    3,
    21, 15,
    6, 3,
    3, 0,
    NULL
};

ALIGNED(4) static const u8 sReplaceOldMailPrompt[] = _(
    "Are you sure you want to replace the\n"
    "old  {COLOR CYAN_G}Wonder Mail{RESET} with the new one?");

ALIGNED(4) static const u8 sMailAlreadyReceived[] = _(
    "This {COLOR CYAN_G}Wonder Mail{RESET} has already been\n"
    "received.");

ALIGNED(4) static const u8 sMailAlreadyReceivedMayNotReceiveAgain[] = _(
    "This {COLOR CYAN_G}Wonder Mail{RESET} has already been\n"
    "received.\n"
    "You may not receive the same one again.");

ALIGNED(4) static const u8 sOnlyOneMailCanBeHeldPleaseCompleteFirst[] = _(
    "Only {COLOR CYAN_G}one piece{RESET} of {COLOR CYAN_G}Wonder Mail{RESET} can be held.\n"
    "Please receive it after completing any\n"
    "rescue mission in progress.");

ALIGNED(4) static const u8 sTeamQuicksavedCompleteFirst[] = _(
    "The rescue team has quicksaved in\n"
    "a dungeon with a mission in progress.\n"
    "Please complete the mission first.");

ALIGNED(4) static const u8 sTeamQuicksavedCannotDelete[] = _(
    "The rescue team has quicksaved in\n"
    "a dungeon with a mission in progress.\n"
    "Mail cannot be deleted now.");

ALIGNED(4) static const u8 sReceivedWonderMail[] = _("Received the {COLOR CYAN_G}Wonder Mail{RESET}!");

ALIGNED(4) static const u8 sOnlyOneMailCanBeHeldSoReplacePrompt[] = _(
    "Only {COLOR CYAN_G}one piece{RESET} of {COLOR CYAN_G}Wonder Mail{RESET} can be held.\n"
    "Is it OK to replace the old {COLOR CYAN_G}Wonder Mail{RESET}\n"
    "with the new one?");

ALIGNED(4) static const u8 sJobListFullPleaseDelete[] = _(
    "Your {COLOR CYAN_G}Job List{RESET} is full.\n"
    "Please select and delete unwanted mail.");

ALIGNED(4) static const u8 sNewMail[] = _("New Mail");
ALIGNED(4) static const u8 sOldMail[] = _("Old Mail");
