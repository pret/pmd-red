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

static const MenuItem sPostOfficeHelpStartMenu[] = {
    {_("Post Office"), POST_OFFICE},
    {_("Bulletin Board"), BULLETIN_BOARD},
    {_("Delivery"), DELIVERY},
    {_("{COLOR YELLOW}Friend Rescue{RESET} "), FRIEND_RESCUE},
    {_("Cancel"), CANCEL},
    {NULL, EXIT}
};

static const MenuItem gPostOfficeHelpFriendRescueMenu[] =
{
    {_("Friend Rescue Info"), FRIEND_RESCUE_INFO},
    {_("{COLOR YELLOW}Go rescue{RESET} "), GO_RESCUE},
    {_("{COLOR YELLOW}Get help{RESET} "), GET_HELP_MENU},
    {_("Deleting Mail Info"), DELETING_MAIL},
    {_("Exit"), EXIT},
    {NULL, EXIT}
};

static const MenuItem sPostOfficeHelpGoRescueMenu[] =
{
    {_("Rescue Procedures"), RESCUE_PROCEDURES},
    {_("Receive SOS Mail"), RECEIVE_SOS_MAIL},
    {_("Leave for Rescue"), LEAVE_FOR_RESCUE},
    {_("Send A-OK Mail"), SEND_AOK_MAIL},
    {_("Get Thank-You Mail"), GET_THANK_YOU_MAIL},
    {_("Exit"), EXIT},
    {NULL, EXIT}
};

static const MenuItem sPostOfficeHelpGetHelpMenu[] =
{
    {_("Getting Help"), GETTING_HELP},
    {_("Send SOS Mail"), SEND_SOS_MAIL},
    {_("Receive A-OK Mail"), RECEIVE_AOK_MAIL},
    {_("Send Thank-You Mail"), SEND_THANK_YOU_MAIL},
    {_("Exit"), EXIT},
    {NULL, EXIT}
};

ALIGNED(4) static const u8 sWhatdYouWantToKnow[] =
    _(" So, what'd you want to\n"
    "know?");

ALIGNED(4) static const u8 sGettingHelpExplanation[] =
    _(" If you need to call for\n"
    "help, first send your friend\n"
    "an {COLOR CYAN_G}SOS Mail{RESET}.{EXTRA_MSG}"
    " Once you send that mail,\n"
    "wait until your friend sends you back\n"
    "an {COLOR CYAN_G}A-OK Mail{RESET}.{EXTRA_MSG}"
    " When you get that\n"
    "{COLOR CYAN_G}A-OK Mail{RESET} back, your team\n"
    "can continue from where it went down.{EXTRA_MSG}"
    " Make sure you send your\n"
    "friend a {COLOR CYAN_G}Thank-You Mail{RESET}.\n"
    "That's if you get revived, of course.");

ALIGNED(4) static const u8 sSendSOSMailExplanation[] =
    _(" If your team gets defeated\n"
    "in a dungeon, you can send an {COLOR CYAN_G}SOS Mail{RESET}\n"
    "to a friend willing to help.{EXTRA_MSG}"
    " But I have to warn you.\n"
    "You can't get anyone to rescue you\n"
    "in certain places.{EXTRA_MSG}"
    " If you need to send\n"
    "an {COLOR CYAN_G}SOS Mail{RESET}, you send it from the\n"
    "{COLOR CYAN_G}main menu{RESET}.");

ALIGNED(4) static const u8 sReceiveAOKMailExplanation[] =
    _(" If your friend manages to\n"
    "rescue your team, you need to receive\n"
    "an {COLOR CYAN_G}A-OK Mail{RESET} from your friend.{EXTRA_MSG}"
    " See, once you get that\n"
    "{COLOR CYAN_G}A-OK Mail{RESET}, your team can continue from\n"
    "where it went down in the dungeon.{EXTRA_MSG}"
    " And, if you use\n"
    "a {COLOR CYAN_G}Game Link cable{RESET}, your friend can\n"
    "even send you a {COLOR CYAN_G}helper Pokémon{RESET}.{EXTRA_MSG}"
    " There's just one thing.\n"
    "A {COLOR CYAN_G}helper Pokémon{RESET} can't bring\n"
    "any item it happens to be holding.{EXTRA_MSG}"
    " You can receive that\n"
    "team-saving {COLOR CYAN_G}A-OK Mail{RESET} on the {COLOR CYAN_G}main menu{RESET},\n"
    "all right?");

ALIGNED(4) static const u8 sSendThankYouMailExplanation[] =
    _(" If your team gets rescued,\n"
    "be sure to send your friend\n"
    "a {COLOR CYAN_G}Thank-You Mail{RESET}.{EXTRA_MSG}"
    " You do that by going to\n"
    "the {COLOR CYAN_G}right counter{RESET}, or\n"
    "by selecting it from the {COLOR CYAN_G}main menu{RESET}.{EXTRA_MSG}"
    " You can attach an item in\n"
    "storage to your {COLOR CYAN_G}Thank-You Mail{RESET}\n"
    "as a {COLOR CYAN_G}reward item{RESET}.{EXTRA_MSG}"
    " You don't want to ever\n"
    "forget to express your thanks.");

ALIGNED(4) static const u8 sRescueProceduresExplanation[] =
    _(" If you want to go and\n"
    "rescue your friend's KO'd team,\n"
    "you need to receive an {COLOR CYAN_G}SOS Mail{RESET}.{EXTRA_MSG}"
    " When you get that mail,\n"
    "you can rescue your friend at\n"
    "the {COLOR CYAN_G}left counter{RESET} over there.{EXTRA_MSG}"
    " If you do manage to rescue\n"
    "the team, you send your friend\n"
    "an {COLOR CYAN_G}A-OK Mail{RESET}.{EXTRA_MSG}"
    " After you do that, your\n"
    "friend can send back to you\n"
    "a {COLOR CYAN_G}Thank-You Mail{RESET}.");

ALIGNED(4) static const u8 sReceiveSOSMailExplanation[] =
    _(" To go off on a rescue,\n"
    "you first need to receive your friend's\n"
    "{COLOR CYAN_G}SOS Mail{RESET}.{EXTRA_MSG}"
    " You do that at\n"
    "the {COLOR CYAN_G}left counter{RESET} over there,\n"
    "or by selecting it from the {COLOR CYAN_G}main menu{RESET}.");

ALIGNED(4) static const u8 sSendAOKMailExplanation[] =
    _(" If you succeed in rescuing\n"
    "that team, you send your friend an\n"
    "{COLOR CYAN_G}A-OK Mail{RESET}.{EXTRA_MSG}"
    " You do that by going to\n"
    "the {COLOR CYAN_G}left counter{RESET},\n"
    "or from the {COLOR CYAN_G}main menu{RESET}.{EXTRA_MSG}"
    " You can send your friend\n"
    "a Pokémon as a helper from your Friend\n"
    "Areas using a {COLOR CYAN_G}Game Link cable{RESET}.{EXTRA_MSG}"
    " This Pokémon won't\n"
    "disappear from its Friend Area, so\n"
    "don't you worry any.");

ALIGNED(4) static const u8 sLeaveForRescueExplanation[] =
    _(" If you get an {COLOR CYAN_G}SOS Mail{RESET},\n"
    "you head off on the rescue from\n"
    "the {COLOR CYAN_G}left counter{RESET}.{EXTRA_MSG}"
    " But, I have to warn you.\n"
    "You can't go off to rescue in a dungeon\n"
    "if you can't get into it.{EXTRA_MSG}"
    " You'll be able to get\n"
    "there when you go farther in your\n"
    "adventure, so it won't do to fret.");

ALIGNED(4) static const u8 sGetThankYouMailExplanation[] =
    _(" If you send your friend\n"
    "an {COLOR CYAN_G}A-OK Mail{RESET}, you can look forward\n"
    "to getting a {COLOR CYAN_G}Thank-You Mail{RESET} back.{EXTRA_MSG}"
    " You can receive it at\n"
    "the {COLOR CYAN_G}right counter{RESET}\n"
    "or on the {COLOR CYAN_G}main menu{RESET}.{EXTRA_MSG}"
    " But you need to {COLOR RED}be careful{RESET}.\n"
    "You {COLOR RED}must not delete the A-OK Mail{RESET}\n"
    "before you get the {COLOR CYAN_G}Thank-You Mail{RESET} back.");

ALIGNED(4) static const u8 sImYourGuide[] =
    _(" I'm your guide to what you\n"
    "can expect at the Pelipper Post Office.\n"
    "If you have any questions, just ask away!");

ALIGNED(4) static const u8 sAnythingElse[] =
    _(" Did you want to ask about\n"
    "anything else?");

ALIGNED(4) static const u8 sPostOfficeExplanation[] =
    _(" {COLOR CYAN_G}The Pelipper Post Office{RESET}\n"
    "keeps track of information from\n"
    "around the world.{EXTRA_MSG}"
    " We inform folks\n"
    "about everything from gossip to calls\n"
    "for help from fellow Pokémon.{EXTRA_MSG}"
    " For the latest news, check\n"
    "{COLOR CYAN_G}your Mailbox{RESET} or the {COLOR CYAN_G}Bulletin Board{RESET}\n"
    "outside, all right?{EXTRA_MSG}"
    " Oh, that's not all.\n"
    "You can arrange for {COLOR CYAN_G}Friend Rescue{RESET}\n"
    "missions at that counter there.{EXTRA_MSG}"
    " The {COLOR CYAN_G}left counter{RESET} is\n"
    "for rescues, and the {COLOR CYAN_G}right counter{RESET}\n"
    "is for Thank-You Mail.");

ALIGNED(4) static const u8 sBulletinBoardExplanation[] =
    _(" The {COLOR CYAN_G}Bulletin Board{RESET} outside\n"
    "here lists rescue requests.{EXTRA_MSG}"
    " Take on rescue jobs from\n"
    "the Bulletin Board. Be a hero and handle\n"
    "the jobs for fellow Pokémon in need!");

ALIGNED(4) static const u8 sDeliveryExplanation[] =
    _(" If your rescue team\n"
    "becomes famous for doing lots of rescues,\n"
    "expect to get rescue requests directly.{EXTRA_MSG}"
    " Our delivery {POKEMON_0}\n"
    "will take those jobs straight to your\n"
    "{COLOR CYAN_G}Mailbox{RESET}.");

ALIGNED(4) static const u8 sFriendRescueExplanation[] =
    _(" Friend Rescue is what we\n"
    "call rescue missions between friends using\n"
    "a {COLOR CYAN_G}Game Link cable{RESET}, {COLOR CYAN_G}passwords{RESET}, etc.{EXTRA_MSG}"
    " For instance, you can send\n"
    "out for help saying your team wiped out\n"
    "in a dungeon at such and such a place.{EXTRA_MSG}"
    " Your friend could play\n"
    "the hero and come to your team's rescue.\n"
    "Or it can be the other way around, too.{EXTRA_MSG}"
    " If you use {COLOR CYAN_G}passwords{RESET},\n"
    "you can do rescues with friends in\n"
    "far-away places.{EXTRA_MSG}"
    " You can apply for Friend\n"
    "Rescue jobs at the {COLOR CYAN_G}left counter{RESET} of\n"
    "that counter there.");

ALIGNED(4) static const u8 sDeletingMailExplanation[] =
    _(" Deleting mail just means\n"
    "getting rid of old mail that you don't\n"
    "need anymore.{EXTRA_MSG}"
    " If you do lots of Friend\n"
    "Rescues, you'll find {COLOR CYAN_G}SOS Mail{RESET} and\n"
    "{COLOR CYAN_G}A-OK Mail{RESET} piling up.{EXTRA_MSG}"
    " Once you get {COLOR CYAN_G}30 pieces{RESET},\n"
    "you won't be able to receive more mail.\n"
    "That's why you'll need to delete old mail.{EXTRA_MSG}"
    " You can look through old\n"
    "mail at the {COLOR CYAN_G}left counter{RESET} over there.");