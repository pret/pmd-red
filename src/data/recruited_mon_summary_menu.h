static const WindowTemplate sDummyWinTemplate = WIN_TEMPLATE_DUMMY;

static const WindowTemplate sSummaryWinTemplate =
{
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = { .x = 2, .y = 2 },
    .width = 18,
    .height = 14,
    .totalHeight = 18,
    .unk12 = 2,
    .header = NULL
};
