

const MenuItem gUnknown_80DD970[] =
{
    {"Receive SOS Mail", 0x0},
    {"Leave for Rescue", 0x1},
    {"Send A-OK Mail", 0x2},
    {"Delete Mail", 0x3},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DD9EC[] =
{
    {"Delete SOS Mail", 0x5},
    {"Delete A-OK Mail", 0x6},
    {"Delete All Mail", 0x7},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDA48[] =
{
    {"Yes", 0x8},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDA64[] =
{
    {"Yes", 0x8},
    {"No", 0x9},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDA80[] =
{
    {"Yes", 0x8},
    {"No", 0x9},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDAA0[] =
{
    {SendWOPokemon, 0x12},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 SendWOPokemon[] = _("Send w/o Pokémon");

const UnkTextStruct2 gUnknown_80DDACC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x07,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80DDAE4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x06,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const MenuItem gUnknown_80DDAFC[] =
{
    {"Confirm", 0xB},
    {"Info", 0xC},
    {NULL, 0xA},
};

const MenuItem gUnknown_80DDB24[] =
{
    {"Game Link cable", 0xD},
    {"Password", 0xF},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

const MenuItem gUnknown_80DDB60[] =
{
    {SendPokemon_80DDB98, 0x11},
    {DontSendPokemon_80DDB80, 0x12},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 DontSendPokemon_80DDB80[] = _("Don't Send Pokémon");
ALIGNED(4) const u8 SendPokemon_80DDB98[] = _("Send Pokémon");

ALIGNED(4) const char gUnknown_80DDBA8[] = _(
	" What you need to do is\n"
	"tell your friend--the one you rescued--\n"
	"this here password.");

ALIGNED(4) const char gUnknown_80DDBFC[] = _(
	" All righty!\n"
	"Here's your {COLOR_1 LIGHT_BLUE}A-OK Mail password{END_COLOR_TEXT_1}.");

ALIGNED(4) const char gUnknown_80DDC30[] = _(
	" Okeydoke! That's all done.\n"
	"Come around whenever you need.");

ALIGNED(4) const char gUnknown_80DDC70[] = _(
	" Okeydoke! I sent off your\n"
	"{COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
	" Let me save your adventure.");

ALIGNED(4) const char gUnknown_80DDCBC[] = _(
	"{CENTER_ALIGN}Please choose the Pokémon you want to\n"
	"{CENTER_ALIGN}send as a helper to your friend.\n"
	"{CENTER_ALIGN}(Its hold item will not be sent.)");

ALIGNED(4) const char gUnknown_80DDD2C[] = _(
	" ...Uh, no?\n"
	"There appear to be no Pokémon in your\n"
	"Friend Areas. What do you want to do?");

ALIGNED(4) const char gUnknown_80DDD88[] = _(
	" You're sure you want to\n"
	"send this here Pokémon?");

ALIGNED(4) const char gUnknown_80DDDBC[] = _(
	" You're sure about this?");

ALIGNED(4) const char gUnknown_80DDDD8[] = _(
	" All righty. I need you to\n"
	"pick the {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} you want to send.");

ALIGNED(4) const char gUnknown_80DDE20[] = _(
	" ...Uh, no?\n"
	"I don't see any {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} here.");

ALIGNED(4) const char gUnknown_80DDE58[] = _(
	" Did you know? If you use\n"
	"a {COLOR_1 LIGHT_BLUE}Game Link cable{END_COLOR_TEXT_1}, you can send\n"
	"a {COLOR_1 LIGHT_BLUE}helper Pokémon{END_COLOR_TEXT_1} to your friend.");

ALIGNED(4) const char gUnknown_80DDEC0[] = _(
	" Don't you worry. Sending\n"
	"a Pokémon doesn't mean it will go away.\n"
	"So! Want to send one to your friend?");

ALIGNED(4) const char gUnknown_80DDF2C[] = _(
	" ...Uh, no?\n"
	"There's no space at all to receive\n"
	"any more mail.{EXTRA_MSG}"
	" Delete some old mail,\n"
	"and then come to me to receive\n"
	"your mail, OK?");

ALIGNED(4) const char gUnknown_80DDFB8[] = _(
	 " All righty! Connect up\n"
	 "the {COLOR_1 LIGHT_BLUE}Game Link cable{END_COLOR_TEXT_1}, if you'd please.\n"
	 "Your friend ready, too?");

ALIGNED(4) const char gUnknown_80DE01C[] = _(
	"{CENTER_ALIGN}Communicating...\n"
	"{CENTER_ALIGN}Please wait with the power on.\n"
	"{CENTER_ALIGN}To cancel, press {B_BUTTON}.");

ALIGNED(4) const char gUnknown_80DE06C[] = _(
	" Okeydoke!\n"
	"I received your friend's {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
	" Let me save your adventure.");

ALIGNED(4) const char gUnknown_80DE0C0[] = _(
	" Okeydoke! You're good to go.\n"
	"Just give me a shout when you'd like\n"
	"to go rescue your friend.");

ALIGNED(4) const char gUnknown_80DE124[] = _(
	" OK, I need you to enter\n"
	"the {COLOR_1 LIGHT_BLUE}SOS Mail password{END_COLOR_TEXT_1} that your\n"
	"friend gave you.");

ALIGNED(4) const char gUnknown_80DE178[] = _(
	" How do you want to receive\n"
	"your friend's {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const char gUnknown_80DE1B4[] = _(
	" How do you want to send\n"
	"your {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const char gUnknown_80DE1E4[] = _(
	" ...Uh, no?\n"
	"You don't have an {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
	" You'll need to arrange\n"
	"to receive your friend's {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1} first.\n"
	"That's what you need to do.");

ALIGNED(4) const char gUnknown_80DE280[] = _(
	" Okeydoke!\n"
	"Let me show you to the rescue site.");

ALIGNED(4) const char gUnknown_80DE2B0[] = _(
	" ...Uh, no?\n"
	"Doesn't look like you can go to the dungeon\n"
	"named in this {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
	" Come see me about doing\n"
	"this rescue when you can actually go\n"
	"to that dungeon, all right?");

ALIGNED(4) const char gUnknown_80DE368[] = _(
	" ...Uh, no?\n"
	"You've blown this rescue mission too\n"
	"often. Your friend's team is beyond help.{EXTRA_MSG}"
	" I'm sorry to say this,\n"
	"but you'll have to tell your friend that\n"
	"your rescue attempts failed.");

ALIGNED(4) const char gUnknown_80DE430[] = _(
	" Okeydoke.\n"
	"I'll need you to choose the {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}\n"
	"for you to go on a rescue mission.");

ALIGNED(4) const char gUnknown_80DE48C[] = _(
	" What kind of mail do you\n"
	"want to delete?");

ALIGNED(4) const char gUnknown_80DE4B8[] = _(
	" All righty. Choose\n"
	"the {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1} you don't need.");

ALIGNED(4) const char gUnknown_80DE4F0[] = _(
	" ...Uh, no?\n"
	"You don't have any {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.");

ALIGNED(4) const char gUnknown_80DE524[] = _(
	" If you want a reward, {COLOR_1 RED}don't\n"
	"delete an A-OK Mail{END_COLOR_TEXT_1} before getting a\n"
	"{COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1} back for it.{EXTRA_MSG}"
	" {COLOR_1 RED}Be careful{END_COLOR_TEXT_1} if you're going\n"
	"to delete any {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}.{EXTRA_MSG}"
	" Okeydoke.\n"
	"Choose an {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}\n"
	"you don't need anymore.");

ALIGNED(4) const char gUnknown_80DE614[] = _(
	" ...Uh, no?\n"
	"You don't have any {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}.");

ALIGNED(4) const char gUnknown_80DE648[] = _(
	" Uh, OK.\n"
	"So, you want me to delete every piece\n"
	"of mail that you have.");

ALIGNED(4) const char gUnknown_80DE694[] = _(
	" ...Uh, no?\n"
	"You don't have a single piece of\n"
	"mail on you!");

ALIGNED(4) const char gUnknown_80DE6D4[] = _(
	" So, delete all your {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1},\n"
	"{COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}, and your {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1}?\n"
	"You're absolutely, positively sure?");

ALIGNED(4) const char gUnknown_80DE754[] = _(
	" If I delete any mail, it's\n"
	"gone forever and ever. Bye-bye.\n"
	"You're really, really sure now?");

ALIGNED(4) const char gUnknown_80DE7B8[] = _(
	" OK, then.\n"
	"Let me save your adventure now.");

ALIGNED(4) const char gUnknown_80DE7E8[] = _(
	" Okeydoke. That's all done.");

ALIGNED(4) const char gUnknown_80DE808[] = _(
	" Do you want to delete\n"
	"any other mail?");

ALIGNED(4) const char gUnknown_80DE830[] = _(
	" Okeydoke.\n"
	"I'll delete {COLOR_1 LIGHT_BLUE}every piece of mail{END_COLOR_TEXT_1}.");

ALIGNED(4) const char gUnknown_80DE864[] = _(
	" Okeydoke.\n"
	"Every bit of mail has been deleted.{EXTRA_MSG}"
	" Let me save your adventure.");

ALIGNED(4) const char gUnknown_80DE8B4[] = _(
	" Well, hello, there!\n"
	"This is the {COLOR_1 LIGHT_BLUE}Friend Rescue{END_COLOR_TEXT_1} counter.\n"
	"What can I help you with today?");

ALIGNED(4) const char gUnknown_80DE918[] = _(
        " Help you with anything\n"
        "else today?");

ALIGNED(4) const char gUnknown_80DE93C[] = _(
        " Come again anytime!");

ALIGNED(4) const char gWonderMailErrorText[] = _(
	" ...Uh, no?\n"
	"Something's not working right here...");

ALIGNED(4) const char gWonderMailNumGBAsText[] = _(
	" ...Uh, no?\n"
	"The number of GBA systems isn't right.\n"
	"You'd better try this again from the top.");

ALIGNED(4) const char gWonderMailWrongModeText[] = _(
	" ...Uh, no? You're not in the\n"
	"same mode as your friend.\n"
	"You'd better try this again from the top.");

ALIGNED(4) const char gWonderMailStorageFullText[] = _(
	" ...Uh, no?\n"
	"Your storage space is stuffed full.\n"
	"You'd better make room and try again.");

ALIGNED(4) const char gWonderMailDuplicateText[] = _(
	" ...Uh, no? It looks like\n"
	"you received this mail before.\n"
	"You can't get the same mail twice. ");

ALIGNED(4) const char gWonderMailNotEligibleReceiveText[] = _(
	" ...Uh, no?\n"
	"You're not eligible to receive this mail.");

ALIGNED(4) const char gWonderMailNoRoomText[] = _(
	" ...Uh, no?\n"
	"There's no room for you to \n"
	"receive any more mail.{EXTRA_MSG}"
	" You'd better delete some\n"
	"mail and make room before you come see\n"
	"me again about receiving new mail.");

ALIGNED(4) const char gWonderMailFriendErrorText[] = _(
	" ...Uh, no? Looks like your\n"
	"friend didn't do what needed doing.\n"
	"You'd better do this again from the top.");

ALIGNED(4) const char gWonderMailPasswordIncorrectText[] = _(
	" ...Uh, no?\n"
	"This here password looks wrong.\n"
	"Do you want to try that again?");

ALIGNED(4) const char gWonderMailSOSPasswordIncorrectText[] = _(
	" ...Uh, no? This password's\n"
	"not for any {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.");

ALIGNED(4) const char gWonderMailAOKMailReceivedText[] = _(
	 ": I received the {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}.\n"
	 "Your adventure will be saved.");