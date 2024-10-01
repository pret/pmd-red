static const UnkTextStruct2 gUnknown_80DC11C = {
    0, 0, 0, 0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

static const UnkTextStruct2 gUnknown_80DC134 = {
    0, 0, 0, 0,
    3,
    22, 4,
    6, 3,
    3, 0,
    NULL
};

UNUSED static const UnkTextStruct2 gUnknown_80DC14C = {
    0, 0, 0, 0,
    3,
    22, 14,
    6, 3,
    3, 0,
    NULL
};

ALIGNED(4) static const u8 sWillAMoveBeForgotten[] = _(
    "Only four moves may be learned!\n"
    "Will a move be forgotten?");

ALIGNED(4) static const u8 sForgetMoveAndLinkedOnes[] = _(
    "{CENTER_ALIGN}Forget the move {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and\n"
    "{CENTER_ALIGN}any moves linked to it, and learn the move\n"
    "{CENTER_ALIGN}{COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}?");

ALIGNED(4) static const u8 sForgetMoveOnly[] = _(
    "{CENTER_ALIGN}Forget the move {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN}and learn {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}?");

ALIGNED(4) static const u8 sForget[] = _("Forget");