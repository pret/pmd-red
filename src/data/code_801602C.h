enum
{
    MENU_ACTION_DEFAULT = 1,
    MENU_ACTION_YES,
    MENU_ACTION_NO,
};

UNUSED static const WindowTemplate sUnknown_80DB670 =
{
    0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

ALIGNED(4) static const u8 sIsNameOKPrompt[] = _("Is the name {COLOR CYAN}{POKEMON_0}{RESET} OK?");
ALIGNED(4) static const u8 sNameTooLong[] = _("This name is too long.");
ALIGNED(4) static const u8 sEnterAName[] = _("Please enter a name.");
