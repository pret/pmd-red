enum PostOfficeMenuActions
{
    POST_OFFICE,
    BULLETIN_BOARD,
    DELIVERY,
    FRIEND_RESCUE,
    CANCEL,
    EXIT,
    FRIEND_RESCUE_INFO,
    GO_RESCUE,
    GET_HELP_MENU,
    DELETING_MAIL,
    RESCUE_PROCEDURES,
    RECEIVE_SOS_MAIL,
    LEAVE_FOR_RESCUE,
    SEND_AOK_MAIL,
    GET_THANK_YOU_MAIL,
    GETTING_HELP,
    SEND_SOS_MAIL,
    RECEIVE_AOK_MAIL,
    SEND_THANK_YOU_MAIL
};

static const u8 sPostOffice[];
static const u8 sBulletinBoard[];
static const u8 sDelivery[];
static const u8 sFriendRescue[];
static const u8 sCancel[];

static const MenuItem sPostOfficeHelpStartMenu[] =
{
    {sPostOffice, POST_OFFICE},
    {sBulletinBoard, BULLETIN_BOARD},
    {sDelivery, DELIVERY},
    {sFriendRescue, FRIEND_RESCUE},
    {sCancel, CANCEL},
    {NULL, EXIT}
};

ALIGNED(4) static const u8 sCancel[] = _("Cancel");
ALIGNED(4) static const u8 sFriendRescue[] = _("{COLOR_1 YELLOW}Friend Rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) static const u8 sDelivery[] = _("Delivery");
ALIGNED(4) static const u8 sBulletinBoard[] = _("Bulletin Board");
ALIGNED(4) static const u8 sPostOffice[] = _("Post Office");

static const u8 sFriendRescueInfo[];
static const u8 sGoRescue[];
static const u8 sGetHelp[];
static const u8 sDeletingMailInfo[];
static const u8 sExit[];

static const MenuItem gPostOfficeHelpFriendRescueMenu[] =
{
    {sFriendRescueInfo, FRIEND_RESCUE_INFO},
    {sGoRescue, GO_RESCUE},
    {sGetHelp, GET_HELP_MENU},
    {sDeletingMailInfo, DELETING_MAIL},
    {sExit, EXIT},
    {NULL, EXIT}
};

ALIGNED(4) static const u8 sExit[] = _("Exit");
ALIGNED(4) static const u8 sDeletingMailInfo[] = _("Deleting Mail Info");
ALIGNED(4) static const u8 sGetHelp[] = _("{COLOR_1 YELLOW}Get help{END_COLOR_TEXT_1} ");
ALIGNED(4) static const u8 sGoRescue[] = _("{COLOR_1 YELLOW}Go rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) static const u8 sFriendRescueInfo[] = _("Friend Rescue Info");

static const MenuItem sPostOfficeHelpGoRescueMenu[] =
{
    {"Rescue Procedures", RESCUE_PROCEDURES},
    {"Receive SOS Mail", RECEIVE_SOS_MAIL},
    {"Leave for Rescue", LEAVE_FOR_RESCUE},
    {"Send A-OK Mail", SEND_AOK_MAIL},
    {"Get Thank-You Mail", GET_THANK_YOU_MAIL},
    {sExit, EXIT}, // Typing "Exit" as a literal will automatically point to the previous one also
    {NULL, EXIT}
};

static const MenuItem sPostOfficeHelpGetHelpMenu[] =
{
    {"Getting Help", GETTING_HELP},
    {"Send SOS Mail", SEND_SOS_MAIL},
    {"Receive A-OK Mail", RECEIVE_AOK_MAIL},
    {"Send Thank-You Mail", SEND_THANK_YOU_MAIL},
    {sExit, EXIT}, // Typing "Exit" as a literal will automatically point to the previous one also
    {NULL, EXIT}
};

ALIGNED(4) static const u8 sWhatdYouWantToKnow[] =
    _(" So, what'd you want to\n"
    "know?");

ALIGNED(4) static const u8 sGettingHelpExplanation[] =
    _(" If you need to call for\n"
    "help, first send your friend\n"
    "an {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " Once you send that mail,\n"
    "wait until your friend sends you back\n"
    "an {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " When you get that\n"
    "{COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} back, your team\n"
    "can continue from where it went down.{EXTRA_MSG}"
    " Make sure you send your\n"
    "friend a {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1}.\n"
    "That's if you get revived, of course.");

ALIGNED(4) static const u8 sSendSOSMailExplanation[] =
    _(" If your team gets defeated\n"
    "in a dungeon, you can send an {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}\n"
    "to a friend willing to help.{EXTRA_MSG}"
    " But I have to warn you.\n"
    "You can't get anyone to rescue you\n"
    "in certain places.{EXTRA_MSG}"
    " If you need to send\n"
    "an {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}, you send it from the\n"
    "{COLOR_1 LIGHT_BLUE}main menu{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sReceiveAOKMailExplanation[] =
    _(" If your friend manages to\n"
    "rescue your team, you need to receive\n"
    "an {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} from your friend.{EXTRA_MSG}"
    " See, once you get that\n"
    "{COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}, your team can continue from\n"
    "where it went down in the dungeon.{EXTRA_MSG}"
    " And, if you use\n"
    "a {COLOR_1 LIGHT_BLUE}Game Link cable{END_COLOR_TEXT_1}, your friend can\n"
    "even send you a {COLOR_1 LIGHT_BLUE}helper Pokémon{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " There's just one thing.\n"
    "A {COLOR_1 LIGHT_BLUE}helper Pokémon{END_COLOR_TEXT_1} can't bring\n"
    "any item it happens to be holding.{EXTRA_MSG}"
    " You can receive that\n"
    "team-saving {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} on the {COLOR_1 LIGHT_BLUE}main menu{END_COLOR_TEXT_1},\n"
    "all right?");

ALIGNED(4) static const u8 sSendThankYouMailExplanation[] =
    _(" If your team gets rescued,\n"
    "be sure to send your friend\n"
    "a {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " You do that by going to\n"
    "the {COLOR_1 LIGHT_BLUE}right counter{END_COLOR_TEXT_1}, or\n"
    "by selecting it from the {COLOR_1 LIGHT_BLUE}main menu{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " You can attach an item in\n"
    "storage to your {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1}\n"
    "as a {COLOR_1 LIGHT_BLUE}reward item{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " You don't want to ever\n"
    "forget to express your thanks.");

ALIGNED(4) static const u8 sRescueProceduresExplanation[] =
    _(" If you want to go and\n"
    "rescue your friend's KO'd team,\n"
    "you need to receive an {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " When you get that mail,\n"
    "you can rescue your friend at\n"
    "the {COLOR_1 LIGHT_BLUE}left counter{END_COLOR_TEXT_1} over there.{EXTRA_MSG}"
    " If you do manage to rescue\n"
    "the team, you send your friend\n"
    "an {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " After you do that, your\n"
    "friend can send back to you\n"
    "a {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sReceiveSOSMailExplanation[] =
    _(" To go off on a rescue,\n"
    "you first need to receive your friend's\n"
    "{COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " You do that at\n"
    "the {COLOR_1 LIGHT_BLUE}left counter{END_COLOR_TEXT_1} over there,\n"
    "or by selecting it from the {COLOR_1 LIGHT_BLUE}main menu{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sSendAOKMailExplanation[] =
    _(" If you succeed in rescuing\n"
    "that team, you send your friend an\n"
    "{COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " You do that by going to\n"
    "the {COLOR_1 LIGHT_BLUE}left counter{END_COLOR_TEXT_1},\n"
    "or from the {COLOR_1 LIGHT_BLUE}main menu{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " You can send your friend\n"
    "a Pokémon as a helper from your Friend\n"
    "Areas using a {COLOR_1 LIGHT_BLUE}Game Link cable{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " This Pokémon won't\n"
    "disappear from its Friend Area, so\n"
    "don't you worry any.");

ALIGNED(4) static const u8 sLeaveForRescueExplanation[] =
    _(" If you get an {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1},\n"
    "you head off on the rescue from\n"
    "the {COLOR_1 LIGHT_BLUE}left counter{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " But, I have to warn you.\n"
    "You can't go off to rescue in a dungeon\n"
    "if you can't get into it.{EXTRA_MSG}"
    " You'll be able to get\n"
    "there when you go farther in your\n"
    "adventure, so it won't do to fret.");

ALIGNED(4) static const u8 sGetThankYouMailExplanation[] =
    _(" If you send your friend\n"
    "an {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}, you can look forward\n"
    "to getting a {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1} back.{EXTRA_MSG}"
    " You can receive it at\n"
    "the {COLOR_1 LIGHT_BLUE}right counter{END_COLOR_TEXT_1}\n"
    "or on the {COLOR_1 LIGHT_BLUE}main menu{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " But you need to {COLOR_1 RED}be careful{END_COLOR_TEXT_1}.\n"
    "You {COLOR_1 RED}must not delete the A-OK Mail{END_COLOR_TEXT_1}\n"
    "before you get the {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1} back.");

ALIGNED(4) static const u8 sImYourGuide[] =
    _(" I'm your guide to what you\n"
    "can expect at the Pelipper Post Office.\n"
    "If you have any questions, just ask away!");

ALIGNED(4) static const u8 sAnythingElse[] =
    _(" Did you want to ask about\n"
    "anything else?");

ALIGNED(4) static const u8 sPostOfficeExplanation[] =
    _(" {COLOR_1 LIGHT_BLUE}The Pelipper Post Office{END_COLOR_TEXT_1}\n"
    "keeps track of information from\n"
    "around the world.{EXTRA_MSG}"
    " We inform folks\n"
    "about everything from gossip to calls\n"
    "for help from fellow Pokémon.{EXTRA_MSG}"
    " For the latest news, check\n"
    "{COLOR_1 LIGHT_BLUE}your Mailbox{END_COLOR_TEXT_1} or the {COLOR_1 LIGHT_BLUE}Bulletin Board{END_COLOR_TEXT_1}\n"
    "outside, all right?{EXTRA_MSG}"
    " Oh, that's not all.\n"
    "You can arrange for {COLOR_1 LIGHT_BLUE}Friend Rescue{END_COLOR_TEXT_1}\n"
    "missions at that counter there.{EXTRA_MSG}"
    " The {COLOR_1 LIGHT_BLUE}left counter{END_COLOR_TEXT_1} is\n"
    "for rescues, and the {COLOR_1 LIGHT_BLUE}right counter{END_COLOR_TEXT_1}\n"
    "is for Thank-You Mail.");

ALIGNED(4) static const u8 sBulletinBoardExplanation[] =
    _(" The {COLOR_1 LIGHT_BLUE}Bulletin Board{END_COLOR_TEXT_1} outside\n"
    "here lists rescue requests.{EXTRA_MSG}"
    " Take on rescue jobs from\n"
    "the Bulletin Board. Be a hero and handle\n"
    "the jobs for fellow Pokémon in need!");

ALIGNED(4) static const u8 sDeliveryExplanation[] =
    _(" If your rescue team\n"
    "becomes famous for doing lots of rescues,\n"
    "expect to get rescue requests directly.{EXTRA_MSG}"
    " Our delivery {ARG_POKEMON_0}\n"
    "will take those jobs straight to your\n"
    "{COLOR_1 LIGHT_BLUE}Mailbox{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sFriendRescueExplanation[] =
    _(" Friend Rescue is what we\n"
    "call rescue missions between friends using\n"
    "a {COLOR_1 LIGHT_BLUE}Game Link cable{END_COLOR_TEXT_1}, {COLOR_1 LIGHT_BLUE}passwords{END_COLOR_TEXT_1}, etc.{EXTRA_MSG}"
    " For instance, you can send\n"
    "out for help saying your team wiped out\n"
    "in a dungeon at such and such a place.{EXTRA_MSG}"
    " Your friend could play\n"
    "the hero and come to your team's rescue.\n"
    "Or it can be the other way around, too.{EXTRA_MSG}"
    " If you use {COLOR_1 LIGHT_BLUE}passwords{END_COLOR_TEXT_1},\n"
    "you can do rescues with friends in\n"
    "far-away places.{EXTRA_MSG}"
    " You can apply for Friend\n"
    "Rescue jobs at the {COLOR_1 LIGHT_BLUE}left counter{END_COLOR_TEXT_1} of\n"
    "that counter there.");

ALIGNED(4) static const u8 sDeletingMailExplanation[] =
    _(" Deleting mail just means\n"
    "getting rid of old mail that you don't\n"
    "need anymore.{EXTRA_MSG}"
    " If you do lots of Friend\n"
    "Rescues, you'll find {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1} and\n"
    "{COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} piling up.{EXTRA_MSG}"
    " Once you get {COLOR_1 LIGHT_BLUE}30 pieces{END_COLOR_TEXT_1},\n"
    "you won't be able to receive more mail.\n"
    "That's why you'll need to delete old mail.{EXTRA_MSG}"
    " You can look through old\n"
    "mail at the {COLOR_1 LIGHT_BLUE}left counter{END_COLOR_TEXT_1} over there.");