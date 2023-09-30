enum
{
    MENU_ACTION_DEFAULT = 1,
    MENU_ACTION_YES,
    MENU_ACTION_NO,
};

UNUSED static const UnkTextStruct2 sUnknown_80DB670 =
{
    0, 0, 0, 0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

ALIGNED(4) static const u8 sIsNameOKPrompt[] = _("Is the name {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1} OK?");
ALIGNED(4) static const u8 sNameTooLong[] = _("This name is too long.");
ALIGNED(4) static const u8 sEnterAName[] = _("Please enter a name.");