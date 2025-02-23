static const Window sUnknown_80DD148 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

static const Window sUnknown_80DD160 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x04,
    0x08, 0x03,
    0x03, 0x00,
    NULL
};

static const Window sUnknown_80DD178 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x14, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

static const Window sUnknown_80DD190 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x02, 0x11,
    0x1A, 0x02,
    0x02, 0x00,
    NULL
};

ALIGNED(4) static const u8 sVisitWhoPrompt[] = "Whom would you like to visit?";

ALIGNED(4) static const u8 sItemHandedOver[] = _(
	"{CENTER_ALIGN}The {COLOR GREEN}{MOVE_ITEM_1}{RESET} was\n"
	"{CENTER_ALIGN}handed over. ");

ALIGNED(4) static const u8 sItemExchanged[] = _(
	"{CENTER_ALIGN}The {COLOR GREEN}{MOVE_ITEM_1}{RESET} was\n"
	"{CENTER_ALIGN}handed over.{EXTRA_MSG}"
	"{CENTER_ALIGN}The {COLOR GREEN}{MOVE_ITEM_0}{RESET} was\n"
	"{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) static const u8 sReturnedToToolbox[] = _(
	"{CENTER_ALIGN}The {COLOR GREEN}{MOVE_ITEM_0}{RESET} was\n"
	"{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) static const u8 sLeftOnStandby[] = _(
    "{CENTER_ALIGN}{POKEMON_1} left the team to remain\n"
    "{CENTER_ALIGN}on standby in the Friend Area.");

ALIGNED(4) static const u8 sGive[] = "Give";
ALIGNED(4) static const u8 sTake[] = "Take";
ALIGNED(4) static const u8 sStandBy[] = "Stand By";
ALIGNED(4) static const u8 sVisit[] = "Visit";
ALIGNED(4) static const u8 sName[] = "Name";
ALIGNED(4) static const u8 sSummary[] = "Summary";
ALIGNED(4) static const u8 sMoves[] = "Moves";
ALIGNED(4) static const u8 sCheckIQ[] = "Check IQ";
ALIGNED(4) static const u8 sItemBuffered[] = _("Item: {COLOR GREEN}{MOVE_ITEM_0}{RESET} ");