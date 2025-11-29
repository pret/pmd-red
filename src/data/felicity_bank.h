static const WindowTemplate sUnknown_80DB6DC = WIN_TEMPLATE_DUMMY;

static const WindowTemplate sUnknown_80DB6F4 = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_NORMAL,
    .pos = { 2, 3 },
    .width = 26,
    .height = 2,
    .totalHeight = 2,
    .unk12 = 0,
    .header = NULL
};

static const WindowTemplate sUnknown_80DB70C = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_NORMAL,
    .pos = { 17, 8 },
    .width = 11,
    .height = 4,
    .totalHeight = 4,
    .unk12 = 0,
    .header = NULL
};

ALIGNED(4) static const u8 sDisplayMoney[] = _("Money: ");
ALIGNED(4) static const u8 sDisplaySavings[] = _("Savings: ");
ALIGNED(4) static const u8 sMoney[] = _("Money");
