static const WindowTemplate sUnknown_80E1EFC =
{
    0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

static const WindowHeader sUnknown_80E1F14 = {1, 0, 8, 0};

static const WindowTemplate sUnknown_80E1F18 =
{
    0,
    6,
    2, 2,
    20, 4,
    4, 0,
    &sUnknown_80E1F14
};

ALIGNED(4) static const u8 sObjectives[] = "Objectives";
ALIGNED(4) static const u8 sFmt1[] = "%dF";
ALIGNED(4) static const u8 sFmtRescue[] = _("  Rescue {COLOR YELLOW}%s{RESET}");
ALIGNED(4) static const u8 sJustGo[] = "Just go!";
ALIGNED(4) static const u8 sFmtBring[] = _("  Bring {COLOR GREEN}%s{RESET}");
ALIGNED(4) static const u8 sFmtFind[] = _("  Find {COLOR GREEN}%s{RESET}");
ALIGNED(4) static const u8 sFmtEscort[] = _("  Escort to {COLOR YELLOW}%s{RESET}");
ALIGNED(4) static const u8 sRedQuestionMarks[] = _("{COLOR RED_W}???{RESET}");
