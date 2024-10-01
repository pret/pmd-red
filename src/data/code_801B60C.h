static const UnkTextStruct2 sUnknown_80DBA58 = {
    0, 0, 0, 0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

static const UnkTextStruct2 sUnknown_80DBA70 = {
    0, 0, 0, 0,
    3,
    20, 4,
    6, 3,
    3, 0,
    NULL
};

static const UnkTextStruct2 sUnknown_80DBA88 = {
    0, 0, 0, 0,
    3,
    20, 14,
    6, 3,
    3, 0,
    NULL
};

ALIGNED(4) static const u8 sFmtReceivedThePromised[] = _(
    "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1} received\n"
    "{CENTER_ALIGN}the promised {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}. ");

ALIGNED(4) static const u8 sFmtTeamReceivedThePromised[] = _(
    "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1}'s team received\n"
    "{CENTER_ALIGN}the promised {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sFmtTeamAlsoReceived[] = _(
    "{CENTER_ALIGN}The team also received\n"
    "{CENTER_ALIGN}the item {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sFmtReceivedStatue[] = _(
    "{CENTER_ALIGN}Received the {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}!{EXTRA_MSG}{CENTER_ALIGN}A very rare statue. It has been placed\n"
    "{CENTER_ALIGN}outside your rescue team base.");

ALIGNED(4) static const u8 sFmtReceive1000Instead[] = _(
    "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}...\n"
    "{CENTER_ALIGN}You've already acquired it.{EXTRA_MSG}{CENTER_ALIGN}Sorry to see that...{EXTRA_MSG}{CENTER_ALIGN}In its place, {COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1},\n"
    "{CENTER_ALIGN}you can have {COLOR_1 LIGHT_BLUE}1,000{END_COLOR_TEXT_1} {POKE}.");

ALIGNED(4) static const u8 sFmtFullSoSentToStorage[] = _(
    "{CENTER_ALIGN}Your Toolbox is full.\n"
    "{CENTER_ALIGN}The item was sent to storage.");

ALIGNED(4) static const u8 sFmtFullSoPrompt[] = _(
    "{CENTER_ALIGN}Your Toolbox is full.\n"
    "{CENTER_ALIGN}What would you like to do?");

ALIGNED(4) static const u8 sFmtConfirmThrowAway[] = _(
    "{CENTER_ALIGN}Is it OK to throw away\n"
    "{CENTER_ALIGN}this {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}?");

ALIGNED(4) static const u8 sFmtThrownAway[] = _(
    "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN}was thrown away.");

ALIGNED(4) static const u8 sFmtPutInStorageForReceive[] = _(
    "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1} was put in\n"
    "{CENTER_ALIGN}storage to get the {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sFmtDiscardedForReceive[] = _(
    "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1} was discarded\n"
    "{CENTER_ALIGN}to get the {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 sTrashToolboxItem[] = _("Trash Toolbox Item");
ALIGNED(4) static const u8 sTrashReceivedItem[] = _("Trash Received Item");
ALIGNED(4) static const u8 sStorage[] = _("Storage");
ALIGNED(4) static const u8 sTrash[] = _("Trash");