static const char NewGame_80E5A20[];
static const char AdventureLog_80E5A10[];
static const char WonderMail_80E5A54[];
static const char Continue_80E5AF0[];
static const char DeleteSaveData_80E5ADC[];
static const char FriendRescue_80E5ACC[];
static const char TradeItems_80E5AC0[];
static const char ReviveTeam_80E5C0C[];
static const char SendItems_80E5C90[];
static const char ReceiveItems_80E5C80[];
static const char AwaitingRescue_80E5B7C[];
static const u8 sUnknown_80E5CE4[];
static const u8 sUnknown_80E5CE8[];
static const u8 sUnknown_80E5D24[];
static const u8 sUnknown_80E5D60[];
static const u8 sUnknown_80E5D88[];
static const u8 sUnknown_80E5DB8[];
static const u8 sUnknown_80E5DCC[];
static const u8 sUnknown_80E5E08[];
static const u8 sUnknown_80E5E34[];
static const u8 sUnknown_80E5EA0[];
static const u8 sUnknown_80E5E74[];
static const u8 sUnknown_80E5EF8[];
static const u8 sUnknown_80E5ED4[];
static const u8 sUnknown_80E5F58[];
static const u8 sUnknown_80E5F34[];
static const u8 sUnknown_80E5FB0[];
static const u8 sUnknown_80E5F98[];
static const u8 sUnknown_80E5FE4[];
static const u8 sUnknown_80E6008[];
static const u8 sUnknown_80E6048[];
static const u8 sUnknown_80E6070[];

const struct UnkTextStruct2 gUnknown_80E59A8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

static const char main_menu_fill[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80E59C8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const struct UnkTextStruct2 gUnknown_80E59E0 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E59F8[] =
{
    {NewGame_80E5A20, MENU_NEW_GAME},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {NULL, 0xffdd},
};

static const char AdventureLog_80E5A10[] = "Adventure Log";
static const char NewGame_80E5A20[] = "New Game";

const struct UnkTextStruct2 gUnknown_80E5A29 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x02,
   0x02, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5A44[] =
{
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

static const char WonderMail_80E5A54[] = "Wonder Mail";

const struct UnkTextStruct2 gUnknown_80E5A60 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const struct UnkTextStruct2 gUnknown_80E5A78 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0B, 0x09,
   0x09, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5A90[] = 
{
    {Continue_80E5AF0, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

static const char TradeItems_80E5AC0[] = "Trade Items";
static const char FriendRescue_80E5ACC[] = "Friend Rescue";
static const char DeleteSaveData_80E5ADC[] = "Delete Save Data";
static const char Continue_80E5AF0[] = "Continue";

const struct MenuItem gUnknown_80E5AFC[] =
{
    {Continue_80E5AF0, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5B34 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5B4C[] =
{
    {AwaitingRescue_80E5B7C, MENU_AWAITING_RESCUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};
static const char AwaitingRescue_80E5B7C[] = "Awaiting Rescue";

const struct MenuItem gUnknown_80E5B8C[] = 
{
    {AwaitingRescue_80E5B7C, MENU_AWAITING_RESCUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5BC4 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5BDC[] =
{
    {ReviveTeam_80E5C0C, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};
static const char ReviveTeam_80E5C0C[] = "Revive Team";

const struct MenuItem gUnknown_80E5C18[] =
{
    {ReviveTeam_80E5C0C, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5C50 = { 
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5C68[] = 
{
    {SendItems_80E5C90, MENU_SEND_ITEMS},
    {ReceiveItems_80E5C80, MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

static const char ReceiveItems_80E5C80[] = "Receive Items";
static const char SendItems_80E5C90[] = "Send Items";

const struct MenuItem gUnknown_80E5C9C[] = 
{
    {SendItems_80E5C90, -1},
    {ReceiveItems_80E5C80, MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5CB4 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x0F, 0x00,
   0x1A, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5CCC[] = 
{
    {sUnknown_80E5CE8, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5CE4[] = "  ";
static const u8 sUnknown_80E5CE8[] = "Start an entirely new adventure.";

const struct MenuItem gUnknown_80E5D0C[] = 
{
    {sUnknown_80E5D24, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5D24[] = "Check your career as an adventurer.";

const struct MenuItem gUnknown_80E5D48[] = 
{
    {sUnknown_80E5D88, 0xffde},
    {sUnknown_80E5D60, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5D60[] = _("It won{APOSTROPHE}t be in the release version.");
static const u8 sUnknown_80E5D88[] = "This is the Debug Mode.";

const struct MenuItem gUnknown_80E5DA0[] = 
{
    {sUnknown_80E5DCC, 0xffde},
    {sUnknown_80E5DB8, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5DB8[] = "you last saved.  ";
static const u8 sUnknown_80E5DCC[] = "Resume your adventure from where";

const struct MenuItem gUnknown_80E5DF0[] = {
    {sUnknown_80E5E34, 0xFFDE},
    {sUnknown_80E5E08, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5E08[] = _("#C2Beware#R! This will delete it forever!");
static const u8 sUnknown_80E5E34[] = "This will delete your saved game data.";

const struct MenuItem gUnknown_80E5E5C[] = {
    {sUnknown_80E5EA0, 0xFFDE},
    {sUnknown_80E5E74, 0xFFDE},
    {0, 0xFFDD}
};

ALIGNED(4) static const u8 sUnknown_80E5E74[] = _("passwords{COMMA} friends may rescue each other.");
static const u8 sUnknown_80E5EA0[] = "Using a Game Link cable or";

const struct MenuItem gUnknown_80E5EBC[] = {
    {sUnknown_80E5EF8, 0xFFDE},
    {sUnknown_80E5ED4, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5ED4[] = "trade stored items with a friend.";
ALIGNED(4) static const u8 sUnknown_80E5EF8[] = _("Using a Game Link cable{COMMA} you can");

const struct MenuItem gUnknown_80E5F1C[] = {
    {sUnknown_80E5F58, 0xFFDE},
    {sUnknown_80E5F34, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5F34[] = "You can give up waiting for rescue.";
static const u8 sUnknown_80E5F58[] = "You are awaiting rescue by a friend.";

const struct MenuItem gUnknown_80E5F80[] = {
    {sUnknown_80E5FB0, 0xFFDE},
    {sUnknown_80E5F98, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5F98[] = "receive Wonder Mail.";
ALIGNED(4) static const u8 sUnknown_80E5FB0[] = _("Using passwords{COMMA} you can");

const struct MenuItem gUnknown_80E5FCC[] = {
    {sUnknown_80E6008, 0xFFDE},
    {sUnknown_80E5FE4, 0xFFDE},
    {NULL, 0xFFDD}
};

static const u8 sUnknown_80E5FE4[] = "receive teams from your friends.";
ALIGNED(4) static const u8 sUnknown_80E6008[] = _("Using the Dual Slot function{COMMA} you can");

const struct MenuItem gUnknown_80E6030[] = {
    {sUnknown_80E6070, 0xFFDE},
    {sUnknown_80E6048, 0xFFDE},
    {NULL, 0xFFDD}
};

static const u8 sUnknown_80E6048[] = "go on an adventure to unknown worlds.";
ALIGNED(4) static const u8 sUnknown_80E6070[] = _("Using wireless communication{COMMA} you can");
static const u8 sMainMenu_fill0[] = "pksdir0";
