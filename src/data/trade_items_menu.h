ALIGNED(4) static const u8 sFill[] = _("pksdir0");

static const MenuItem sUnknown_80E60A0[3] = {
    {"Send item", 1},
    {"Receive item", 2},
    {NULL, 0},
};

static const MenuItem sUnknown_80E60D4[3] = {
    {"Send item", -1},
    {"Receive item", 2},
    {NULL, 0},
};

static const UnkTextStruct2 sUnknown_80E60EC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x04,
    0x06, 0x05,
    0x05, 0x00,
    NULL
};

static const MenuItem sUnknown_80E6104[4] = {
    {"Confirm", 3},
    {"Info", 4},
    {"Cancel", 7},
    {NULL, 0},
};

static const UnkTextStruct2 unused =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x09,
    0x05, 0x03,
    0x03, 0x00,
    NULL
};

static const MenuItem sUnknown_80E6154[3] = {
    {"Yes", 5},
    {"No", 6},
    {NULL, 0},
};

static const UnkTextStruct2 sUnknown_80E6174 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x0D,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

static const MenuItem sUnknown_80E618C[3] = {
    {"Yes", 5},
    {"Cancel", 0},
    {NULL, 0},
};

ALIGNED(4) static const u8 sUnknown_80E61A4[] = "What would you like to do? ";
ALIGNED(4) static const u8 sUnknown_80E61C0[] = "Please choose the item to be sent.";
ALIGNED(4) static const u8 sUnknown_80E61E4[] = _(
    "{COLOR_1 LIGHT_BLUE}$d0{END_COLOR_TEXT_1} {COLOR_1 GREEN_2}{ARG_MOVE_ITEM_0}(s){END_COLOR_TEXT_1}\n"
    "will be sent.\n"
    "Is that OK?");

ALIGNED(4) static const u8 sUnknown_80E6214[] = _(
    "Your friend will send you an item.\n"
    "When you are both ready{COMMA} you\n"
    "may communicate.");

ALIGNED(4) static const u8 sUnknown_80E6268[] = _(
    "Preparing to send an item to your\n"
    "friend. When you are both ready{COMMA}\n"
    "you may communicate.");

ALIGNED(4) static const u8 sUnknown_80E62C4[] = _(
    "{CENTER_ALIGN}In communication...\n"
    "{CENTER_ALIGN}Please wait with the power on.\n"
    "{CENTER_ALIGN}To cancel{COMMA} press {B_BUTTON}.");

ALIGNED(4) static const u8 sUnknown_80E6314[] = _(
    "You received\n"
    "{COLOR_1 LIGHT_BLUE}$d0{END_COLOR_TEXT_1} {COLOR_1 GREEN_2}{ARG_MOVE_ITEM_0}(s){END_COLOR_TEXT_1}.\n"
    "Your adventure will be saved.");

ALIGNED(4) static const u8 sUnknown_80E6358[] = _("You sent {COLOR_1 LIGHT_BLUE}$d0{END_COLOR_TEXT_1} {COLOR_1 GREEN_2}{ARG_MOVE_ITEM_0}(s){END_COLOR_TEXT_1}.");

// Trade Items Menu Link Error Messages
ALIGNED(4) static const u8 sTradeItemsCommunicationError[] = "There was a communication error.";
ALIGNED(4) static const u8 sUnknown_80E639C[] =
    "An incorrect number of GBA systems are\n"
    "connected.\n"
    "Please redo this process from the start.";

ALIGNED(4) static const u8 sUnknown_80E63F8[] =
    "There is no response from your friend.\n"
    "Please redo this process from the start.";

ALIGNED(4) static const u8 sUnknown_80E6448[] =
    "The sender and receiver appear to be\n"
    "in different modes.\n"
    "Please redo the process from the start.";

ALIGNED(4) static const u8 sUnknown_80E64AC[] = _(
    "There is no response from your friend.\n"
    "Please make sure the sender and receiver\n"
    "are ready{COMMA} then redo this from the start.");

ALIGNED(4) static const u8 sHowMany[] = "How many?";