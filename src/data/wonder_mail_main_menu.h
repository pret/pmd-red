const MenuItem gSelectWonderMailModeMainMenuItems[] = {
    {_("Send"), WONDER_MAIL_MODE_SEND},
    {_("Receive"), WONDER_MAIL_MODE_RECEIVE},
    {NULL, 0}
};

const MenuItem gSendWonderMailMainMenuItems[] = {
    {_("Game Link cable"), WONDER_MAIL_GAME_LINK},
    {_("Password"), -1},
    {_("Cancel"), 8},
    {NULL, 0}

};

const MenuItem gReceiveWonderMailMainMenuItems[] = {
    {_("Game Link cable"), WONDER_MAIL_GAME_LINK},
    {_("Password"), WONDER_MAIL_PASSWORD},
    {_("Cancel"), 8},
    {NULL, 0}
};

const MenuItem gUnknown_80E78F8[] = {
    {_("Yes"), 6},
    {_("Cancel"), 0},
    {NULL, 0}
};



ALIGNED(4) const char gUnknown_80E7914[] = "There was a communication error.";

ALIGNED(4) const char gUnknown_80E7938[] = "An incorrect number of GBA systems are\n"
                                           "connected.\n"
                                           "Please redo this process from the start.";

ALIGNED(4) const char gUnknown_80E7994[] = "There is no response from your friend.\n"
                                           "Please redo this process from the start.";

ALIGNED(4) const char gUnknown_80E79E4[] = "The sender and receiver appear to be\n"
                                           "in different modes.\n"
                                           "Please redo the process from the start.";

ALIGNED(4) const char gUnknown_80E7A48[] =  _("There is no response from your friend.\n"
                                              "Please make sure the sender and receiver\n"
                                              "are ready, then redo this from the start.");

ALIGNED(4) const char gUnknown_80E7AC4[] = "What would you like to do?";

ALIGNED(4) const char gUnknown_80E7AE0[] = _("How would you like to send your\n"
                                           "{COLOR CYAN_G}Wonder Mail{RESET}?");

ALIGNED(4) const char gUnknown_80E7B14[] = _("How would you like to receive the\n"
                                           "{COLOR CYAN_G}Wonder Mail{RESET}?");

ALIGNED(4) const char gUnknown_80E7B48[] = "Your adventure will be saved.";

ALIGNED(4) const char gUnknown_80E7B68[] = _("Your {COLOR CYAN_G}Wonder Mail{RESET} was sent.");

ALIGNED(4) const char gUnknown_80E7B88[] = _("The received {COLOR CYAN_G}Wonder Mail{RESET} was\n"
                                             "added to the {COLOR CYAN_G}Job List{RESET}.");

ALIGNED(4) const char gUnknown_80E7BC8[] = _("The {COLOR CYAN_G}Wonder Mail{RESET} was refused.");

ALIGNED(4) const char gUnknown_80E7BEC[] = _("Connect a {COLOR CYAN_G}Game Link cable{RESET}.\n"
                                             "When you and your friend are ready,\n"
                                             "you may communicate. ");

ALIGNED(4) const char gUnknown_80E7C48[] = _("{CENTER_ALIGN}In communication...\n"
                                             "{CENTER_ALIGN}Please wait with the power on.\n"
                                             "{CENTER_ALIGN}To cancel, press {B_BUTTON}.");

ALIGNED(4) const char gUnknown_80E7C98[] = _("Please enter the\n"
                                             "{COLOR CYAN_G}Wonder Mail password{RESET}.");

ALIGNED(4) const char gUnknown_80E7CC4[] = "This password is incorrect.\n"
                                           "Would you like to enter it again?";

// UNUSED DEBUG MENU DUMMY A:

ALIGNED(4) const char wonder_mail_main_fill0[] = "pksdir0";

extern const char Cancel_80E7D24[];
extern const char Yes_80E7D2C[];

const MenuItem WonderMailMainUnused[3] =
{
    {Yes_80E7D2C, 1},
    {Cancel_80E7D24, 0},
    {NULL, 0},
};

ALIGNED(4) const char Cancel_80E7D24[] = "Cancel";
ALIGNED(4) const char Yes_80E7D2C[] = "Yes";

// UNUSED DEBUG MENU DUMMY B:

ALIGNED(4) const char wonder_mail_main_fill1[] = "pksdir0";