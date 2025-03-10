static const MenuItem sUnknown_80E60A0[] = {
    {_("Send item"), 1},
    {_("Receive item"), 2},
    {NULL, 0},
};

static const MenuItem sUnknown_80E60D4[] = {
    {_("Send item"), -1},
    {_("Receive item"), 2},
    {NULL, 0},
};

static const WindowTemplate sUnknown_80E60EC =
{
    0,
    3,
    21, 4,
    6, 5,
    5, 0,
    NULL
};

static const MenuItem sUnknown_80E6104[] = {
    {_("Confirm"), 3},
    {_("Info"), 4},
    {_("Cancel"), 7},
    {NULL, 0},
};

static const WindowTemplate unused =
{
    0,
    3,
    22, 9,
    5, 3,
    3, 0,
    NULL
};

static const MenuItem sUnknown_80E6154[] = {
    {_("Yes"), 5},
    {_("No"), 6},
    {NULL, 0},
};

static const WindowTemplate sUnknown_80E6174 =
{
    0,
    3,
    21, 13,
    6, 4,
    4, 0,
    NULL
};

static const MenuItem sUnknown_80E618C[] = {
    {_("Yes"), 5},
    {_("Cancel"), 0},
    {NULL, 0},
};

ALIGNED(4) static const u8 sWhatDoPrompt[] = "What would you like to do? ";
ALIGNED(4) static const u8 sPleaseChooseItem[] = "Please choose the item to be sent.";
ALIGNED(4) static const u8 sFmtWillBeSentPrompt[] = _(
    "{COLOR CYAN_G}{VALUE_0}{RESET} {COLOR GREEN_I}{MOVE_ITEM_0}(s){RESET}\n"
    "will be sent.\n"
    "Is that OK?");

ALIGNED(4) static const u8 sFriendWillSendAnItem[] = _(
    "Your friend will send you an item.\n"
    "When you are both ready, you\n"
    "may communicate.");

ALIGNED(4) static const u8 sPreparingToSendItem[] = _(
    "Preparing to send an item to your\n"
    "friend. When you are both ready,\n"
    "you may communicate.");

ALIGNED(4) static const u8 sInCommunication[] = _(
    "{CENTER_ALIGN}In communication...\n"
    "{CENTER_ALIGN}Please wait with the power on.\n"
    "{CENTER_ALIGN}To cancel, press {B_BUTTON}.");

ALIGNED(4) static const u8 sFmtYouReceived[] = _(
    "You received\n"
    "{COLOR CYAN_G}{VALUE_0}{RESET} {COLOR GREEN_I}{MOVE_ITEM_0}(s){RESET}.\n"
    "Your adventure will be saved.");

ALIGNED(4) static const u8 sFmtYouSent[] = _("You sent {COLOR CYAN_G}{VALUE_0}{RESET} {COLOR GREEN_I}{MOVE_ITEM_0}(s){RESET}.");

// Trade Items Menu Link Error Messages
ALIGNED(4) static const u8 sCommunicationError[] = "There was a communication error.";
ALIGNED(4) static const u8 sInvalidGBACount[] =
    "An incorrect number of GBA systems are\n"
    "connected.\n"
    "Please redo this process from the start.";

ALIGNED(4) static const u8 sNoResponseSoRedo[] =
    "There is no response from your friend.\n"
    "Please redo this process from the start.";

ALIGNED(4) static const u8 sUnequalModes[] =
    "The sender and receiver appear to be\n"
    "in different modes.\n"
    "Please redo the process from the start.";

ALIGNED(4) static const u8 sNoResponseCheckSenderReceiver[] = _(
    "There is no response from your friend.\n"
    "Please make sure the sender and receiver\n"
    "are ready, then redo this from the start.");

ALIGNED(4) static const u8 sHowMany[] = "How many?";
