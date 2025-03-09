static const WindowTemplate sUnknown_80DBE7C = {
    0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

static const WindowHeader sUnknown_80DBE94 = {1, 0, 7, 0};
static const WindowTemplate sUnknown_80DBE98 = {
    0,
    6,
    2, 2,
    9, 6,
    6, 0,
    &sUnknown_80DBE94
};

static const WindowTemplate sUnknown_80DBEB0[MAX_WINDOWS] =
{
    {
        0,
        3,
        2, 3,
        8, 6,
        6, 0,
        NULL
    },
    {
        0,
        3,
        12, 4,
        16, 2,
        2, 0,
        NULL
    },
    {
        0,
        3,
        2, 14,
        26, 4,
        4, 0,
        NULL
    },
    {
        0,
        3,
        0, 0,
        0, 0,
        0, 0,
        NULL
    }
};

ALIGNED(4) static const u8 sItems[] = _("Items");
ALIGNED(4) static const u8 sTeam[] = _("Team");
ALIGNED(4) static const u8 sJobList[] = _("Job List");
ALIGNED(4) static const u8 sOthers[] = _("Others");
ALIGNED(4) static const u8 sTripleQuestionMark[] = _("？？？");
ALIGNED(4) static const u8 sFmtPointsCyan[] = _("%s {COLOR CYAN}%d{RESET} Pts.");
ALIGNED(4) static const u8 sFmtMoneyCyan[] = _("Money: {COLOR CYAN}%d{RESET} {POKE}");
ALIGNED(4) static const u8 sTeamRankBadgeFileName[] = _("tmrkpat");
