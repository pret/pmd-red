static const u8 sUnknown_80DAAC0[];
static const u8 sUnknown_80DABD8[];
static const u8 sUnknown_80DABE8[];
static const u8 sUnknown_80DAD28[];
static const u8 sUnknown_80DAD40[];
static const u8 sUnknown_80DADCC[];
static const u8 sUnknown_80DADD4[];
static const u8 sUnknown_80DAECC[];
static const u8 sUnknown_80DAEE0[];
static const u8 sUnknown_80DAF54[];

ALIGNED(4) const Hints gCommonHints[NUM_HINTS] =
{
    {sUnknown_80DAF54, sUnknown_80DAEE0},
    {sUnknown_80DAECC, sUnknown_80DADD4},
    {sUnknown_80DADCC, sUnknown_80DAD40},
    {sUnknown_80DAD28, sUnknown_80DABE8},
    {sUnknown_80DABD8, sUnknown_80DAAC0}
};

ALIGNED(4) static const u8 sUnknown_80DAAC0[] = _(
    "Before leaving on an adventure, go visit\n"
    "friends in their Friend Areas and pick\n"
    "your mission members.\n"
    "The team can include members up to\n"
    "a total body size of 6{STAR_BULLET}. The body size\n"
    "data is under the Info section.\n"
    "Dungeons may also limit how many\n"
    "members are allowed to go inside.");
ALIGNED(4) static const u8 sUnknown_80DABD8[] = _("Building a Team");

ALIGNED(4) static const u8 sUnknown_80DABE8[] = _(
    "If new recruits join you, try to return to\n"
    "your base without letting them faint.\n"
    "If you get them out safely, they'll wait\n"
    "for you in their Friend Areas.\n"
    "Once you get them out, they'll always\n"
    "return home if they faint in a dungeon.\n"
    "If you faint in a dungeon, you lose all your\n"
    "money and some items, too.");
ALIGNED(4) static const u8 sUnknown_80DAD28[] = _("Adventures with Friends");

ALIGNED(4) static const u8 sUnknown_80DAD40[] = _(
    "You can save your adventure by\n"
    "hopping onto your bed in your base.\n"
    "Get in the habit of saving regularly as\n"
    "you progress in your adventure.");
ALIGNED(4) static const u8 sUnknown_80DADCC[] = _("Saving");

ALIGNED(4) static const u8 sUnknown_80DADD4[] = _(
    "Selecting multiple items in storage:\n"
    "  Select an item, then press {L_BUTTON} or {R_BUTTON}.\n"
    "Moving to the Friend Area Map:\n"
    "  Move out from the town's west side\n"
    "  while pressing {L_BUTTON} or {R_BUTTON}.\n"
    "Moving diagonally on the Friend Area Map:\n"
    "  {DPAD} while keeping {R_BUTTON} pressed.");
ALIGNED(4) static const u8 sUnknown_80DAECC[] = _("Controls in Town 2");

ALIGNED(4) static const u8 sUnknown_80DAEE0[] = _(
    "Talk: {A_BUTTON}\n"
    "Move: {DPAD}\n"
    "Window: {B_BUTTON} lightly\n"
    "Message scroll: {A_BUTTON} or {B_BUTTON}\n"
    "Cancel: {B_BUTTON}\n"
    "Description: Choose item or move, {START_BUTTON}");
ALIGNED(4) static const u8 sUnknown_80DAF54[] = _("Controls in Town 1");