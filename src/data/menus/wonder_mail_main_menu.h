extern const char Cancel_80E7D24[];
extern const char Cancel_80E78B4[];
extern const char Yes_80E7D2C[];
extern const char Yes_80E7910[];
extern const char GameLinkCable_80E78C8[];
extern const char Password_80E78BC[];

extern const char Receive_80E7884[];
extern const char Send_80E788C[];

const struct MenuItem gSelectWonderMailModeMainMenuItems[3] =
{
    {Send_80E788C, WONDER_MAIL_MODE_SEND},
    {Receive_80E7884, WONDER_MAIL_MODE_RECEIVE},
    {NULL, 0}
};

ALIGNED(4) const char Receive_80E7884[] = "Receive";
ALIGNED(4) const char Send_80E788C[] = "Send";


const struct MenuItem gSendWonderMailMainMenuItems[4] =
{
    {GameLinkCable_80E78C8, WONDER_MAIL_GAME_LINK},
    {Password_80E78BC, -1},
    {Cancel_80E78B4, 8},
    {NULL, 0}

};

ALIGNED(4) const char Cancel_80E78B4[] = "Cancel";
ALIGNED(4) const char Password_80E78BC[] = "Password";
ALIGNED(4) const char GameLinkCable_80E78C8[] = "Game Link cable";

const struct MenuItem gReceiveWonderMailMainMenuItems[4] =
{
    {GameLinkCable_80E78C8, WONDER_MAIL_GAME_LINK},
    {Password_80E78BC, WONDER_MAIL_PASSWORD},
    {Cancel_80E78B4, 8},
    {NULL, 0}
};

const struct MenuItem gUnknown_80E78F8[3] =
{
    {Yes_80E7910, 6},
    {Cancel_80E78B4, 0},
    {NULL, 0}
};

ALIGNED(4) const char Yes_80E7910[] = "Yes";
