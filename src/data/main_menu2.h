static const UnkTextStruct2 sUnknown_80E59C8 = {
    0, 0, 0, 0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

static const UnkTextStruct2 sUnknown_80E59E0 = {
    0, 0, 0, 0,
    3,
    2, 2,
    10, 3,
    3, 0,
    NULL
};

static const MenuItem sUnknown_80E59F8[] =
{
    {"New Game", MENU_NEW_GAME},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {NULL, 0xffdd},
};

UNUSED static const UnkTextStruct2 sUnknown_80E5A29 = {
    0, 0, 0, 0,
    3,
    2, 2,
    10, 2,
    2, 0,
    NULL
};

UNUSED static const MenuItem sUnknown_80E5A44[] =
{
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

static const UnkTextStruct2 sUnknown_80E5A60 = {
    0, 0, 0, 0,
    3,
    2, 2,
    10, 8,
    8, 0,
    NULL
};

static const UnkTextStruct2 sUnknown_80E5A78 = {
    0, 0, 0, 0,
    3,
    2, 2,
    11, 9,
    9, 0,
    NULL
};

static const MenuItem sUnknown_80E5A90[] =
{
    {"Continue", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

static const MenuItem sUnknown_80E5AFC[] =
{
    {"Continue", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

static const UnkTextStruct2 sUnknown_80E5B34 = {
    0, 0, 0, 0,
    3,
    2, 2,
    10, 8,
    8, 0,
    NULL
};

static const MenuItem sUnknown_80E5B4C[] =
{
    {"Awaiting Rescue", MENU_AWAITING_RESCUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

static const MenuItem sUnknown_80E5B8C[] =
{
    {"Awaiting Rescue", MENU_AWAITING_RESCUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

static const UnkTextStruct2 sUnknown_80E5BC4 = {
    0, 0, 0, 0,
    3,
    2, 2,
    10, 8,
    8, 0,
    NULL
};

static const MenuItem sUnknown_80E5BDC[] =
{
    {"Revive Team", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

static const MenuItem sUnknown_80E5C18[] =
{
    {"Revive Team", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

UNUSED static const UnkTextStruct2 sUnknown_80E5C50 = {
    0, 0, 0, 0,
    3,
    2, 2,
    10, 3,
    3, 0,
    NULL
};

UNUSED static const MenuItem sUnknown_80E5C68[] =
{
    {"Send Items", MENU_SEND_ITEMS},
    {"Receive Items", MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

UNUSED static const MenuItem sUnknown_80E5C9C[] =
{
    {"Send Items", -1},
    {"Receive Items", MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

static const UnkTextStruct2 sUnknown_80E5CB4 = {
    0, 0, 0, 0,
    3,
    2, 15,
    26, 3,
    3, 0,
    NULL
};

static const u8 sUnknown_80E5CE4[];
static const u8 sUnknown_80E5CE8[];
static const MenuItem sUnknown_80E5CCC[] =
{
    {sUnknown_80E5CE8, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};
ALIGNED(4) static const u8 sUnknown_80E5CE4[] = _("  ");
ALIGNED(4) static const u8 sUnknown_80E5CE8[] = _("Start an entirely new adventure.");

static const u8 sUnknown_80E5D24[];
static const MenuItem sUnknown_80E5D0C[] =
{
    {sUnknown_80E5D24, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};
ALIGNED(4) static const u8 sUnknown_80E5D24[] = _("Check your career as an adventurer.");

static const u8 sUnknown_80E5D60[];
static const u8 sUnknown_80E5D88[];
static const MenuItem sUnknown_80E5D48[] =
{
    {sUnknown_80E5D88, 0xffde},
    {sUnknown_80E5D60, 0xffde},
    {NULL, 0xffdd},
};
ALIGNED(4) static const u8 sUnknown_80E5D60[] = _("It won't be in the release version.");
ALIGNED(4) static const u8 sUnknown_80E5D88[] = _("This is the Debug Mode.");

static const u8 sUnknown_80E5DB8[];
static const u8 sUnknown_80E5DCC[];
static const MenuItem sUnknown_80E5DA0[] =
{
    {sUnknown_80E5DCC, 0xffde},
    {sUnknown_80E5DB8, 0xffde},
    {NULL, 0xffdd},
};
ALIGNED(4) static const u8 sUnknown_80E5DB8[] = _("you last saved.  ");
ALIGNED(4) static const u8 sUnknown_80E5DCC[] = _("Resume your adventure from where");

static const u8 sUnknown_80E5E08[];
static const u8 sUnknown_80E5E34[];
static const MenuItem sUnknown_80E5DF0[] =
{
    {sUnknown_80E5E34, 0xFFDE},
    {sUnknown_80E5E08, 0xFFDE},
    {0, 0xFFDD}
};
ALIGNED(4) static const u8 sUnknown_80E5E08[] = _("{COLOR_1 RED}Beware{END_COLOR_TEXT_1}! This will delete it forever!");
ALIGNED(4) static const u8 sUnknown_80E5E34[] = _("This will delete your saved game data.");

static const u8 sUnknown_80E5E74[];
static const u8 sUnknown_80E5EA0[];
static const MenuItem sUnknown_80E5E5C[] =
{
    {sUnknown_80E5EA0, 0xFFDE},
    {sUnknown_80E5E74, 0xFFDE},
    {0, 0xFFDD}
};
ALIGNED(4) static const u8 sUnknown_80E5E74[] = _("passwords, friends may rescue each other.");
ALIGNED(4) static const u8 sUnknown_80E5EA0[] = _("Using a Game Link cable or");

static const u8 sUnknown_80E5ED4[];
static const u8 sUnknown_80E5EF8[];
static const MenuItem sUnknown_80E5EBC[] =
{
    {sUnknown_80E5EF8, 0xFFDE},
    {sUnknown_80E5ED4, 0xFFDE},
    {0, 0xFFDD}
};
ALIGNED(4) static const u8 sUnknown_80E5ED4[] = _("trade stored items with a friend.");
ALIGNED(4) static const u8 sUnknown_80E5EF8[] = _("Using a Game Link cable, you can");

static const u8 sUnknown_80E5F34[];
static const u8 sUnknown_80E5F58[];
static const MenuItem sUnknown_80E5F1C[] =
{
    {sUnknown_80E5F58, 0xFFDE},
    {sUnknown_80E5F34, 0xFFDE},
    {0, 0xFFDD}
};
ALIGNED(4) static const u8 sUnknown_80E5F34[] = _("You can give up waiting for rescue.");
ALIGNED(4) static const u8 sUnknown_80E5F58[] = _("You are awaiting rescue by a friend.");

static const u8 sUnknown_80E5F98[];
static const u8 sUnknown_80E5FB0[];
static const MenuItem sUnknown_80E5F80[] =
{
    {sUnknown_80E5FB0, 0xFFDE},
    {sUnknown_80E5F98, 0xFFDE},
    {0, 0xFFDD}
};
ALIGNED(4) static const u8 sUnknown_80E5F98[] = _("receive Wonder Mail.");
ALIGNED(4) static const u8 sUnknown_80E5FB0[] = _("Using passwords, you can");

static const u8 sUnknown_80E5FE4[];
static const u8 sUnknown_80E6008[];
static const MenuItem sUnknown_80E5FCC[] =
{
    {sUnknown_80E6008, 0xFFDE},
    {sUnknown_80E5FE4, 0xFFDE},
    {NULL, 0xFFDD}
};
ALIGNED(4) static const u8 sUnknown_80E5FE4[] = _("receive teams from your friends.");
ALIGNED(4) static const u8 sUnknown_80E6008[] = _("Using the Dual Slot function, you can");

static const u8 sUnknown_80E6048[];
static const u8 sUnknown_80E6070[];
static const MenuItem sUnknown_80E6030[] =
{
    {sUnknown_80E6070, 0xFFDE},
    {sUnknown_80E6048, 0xFFDE},
    {NULL, 0xFFDD}
};
ALIGNED(4) static const u8 sUnknown_80E6048[] = _("go on an adventure to unknown worlds.");
ALIGNED(4) static const u8 sUnknown_80E6070[] = _("Using wireless communication, you can");