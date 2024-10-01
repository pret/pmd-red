static const UnkTextStruct2 sUnknown_80DD6EC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

static const UnkTextStruct2 sUnknown_80DD704 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x04,
    0x09, 0x03,
    0x03, 0x00,
    NULL
};

static const UnkTextStruct2 sUnknown_80DD71C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x14, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

static const UnkTextStruct2 sUnknown_80DD734 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

static const UnkTextStruct2 sUnknown_80DD74C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x02, 0x11,
    0x1A, 0x02,
    0x02, 0x00,
    NULL
};

ALIGNED(4) static const u8 sSayFarewellPrompt[] = _(
         "You have chosen to say farewell\n"
         "to this Pokémon.{EXTRA_MSG}"
         "The Pokémon will leave its Friend Area.\n"
         "It will no longer be available for\n"
         "adventures. Is that OK?");

ALIGNED(4) static const u8 sSayFarewellConfirm[] = _(
         "If you say farewell to this\n"
         "Pokémon, it will be gone forever.{EXTRA_MSG}"
         "You will never be able to get another one\n"
         "like it to join your team.\n"
         "Will you release it anyway?");

ALIGNED(4) static const u8 sReturnedToToolbox[] = _(
         "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
         "{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) static const u8 sSentToStorage[] = _(
         "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n{CENTER_ALIGN}sent to storage.");

ALIGNED(4) static const u8 sStandBy[] = "Stand By";
ALIGNED(4) static const u8 sMakeLeader[] = "Make Leader";
ALIGNED(4) static const u8 sJoinTeam[] = "Join Team";
ALIGNED(4) static const u8 sSayFarewell[] = "Say Farewell";
ALIGNED(4) static const u8 sGive[] = "Give";
ALIGNED(4) static const u8 sTake[] = "Take";
ALIGNED(4) static const u8 sSummary[] = "Summary";
ALIGNED(4) static const u8 sMoves[] = "Moves";
ALIGNED(4) static const u8 sCheckIQ[] = "Check IQ";

ALIGNED(4) static const u8 sItemBuffered[] = _("Item: {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} ");