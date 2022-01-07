extern const u8 Confirm_80DED98[];
extern const u8 Info_80DED90[];
extern const u8 SendThankYou_Text[];
extern const u8 GetThankYou_Text[];
extern const u8 Cancel_80DEDD8[];
extern const u8 GameLinkCable_Text[];
extern const u8 Password_Text[];
extern const u8 Yes_80DEE5C[];
extern const u8 No_80DEE78[];
extern const u8 SendItem_Text[];
extern const u8 DontSendItem_Text[];
extern const u8 SendWOItem_Text[];

const struct MenuItem gUnknown_80DED78[3] =
{
    {Confirm_80DED98, 0xB},
    {Info_80DED90, 0xC},
    {NULL, 0x0},
};

ALIGNED(4) const u8 Info_80DED90[] = "Info";
ALIGNED(4) const u8 Confirm_80DED98[] = "Confirm";

// Unused
const struct UnkTextStruct2 gUnknown_80DEDA0 =
{
        0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00,
        NULL
};


const struct MenuItem gThankYouMailMainMenuItems[4] =
{
    {SendThankYou_Text, 0x1},
    {GetThankYou_Text, 0x2},
    {Cancel_80DEDD8, 0x0},
    {NULL, 0x0},
};

ALIGNED(4) const u8 Cancel_80DEDD8[] = "Cancel";
ALIGNED(4) const u8 GetThankYou_Text[] = "Get Thank-You Mail";
ALIGNED(4) const u8 SendThankYou_Text[] = "Send Thank-You Mail";

const struct MenuItem gUnknown_80DEE08[4] =
{
    {GameLinkCable_Text, WONDER_MAIL_GAME_LINK},
    {Password_Text, WONDER_MAIL_PASSWORD},
    {Cancel_80DEDD8, 0x0},
    {NULL, 0x0},
};

ALIGNED(4) const u8 Password_Text[] = "Password";
ALIGNED(4) const u8 GameLinkCable_Text[] = "Game Link cable";

const struct MenuItem gUnknown_80DEE44[3] =
{
    {Yes_80DEE5C, 0x7},
    {Cancel_80DEDD8, 0x0},
    {NULL, 0x0},
};

ALIGNED(4) const u8 Yes_80DEE5C[] = "Yes";


const struct MenuItem gUnknown_80DEE60[3] =
{
    {Yes_80DEE5C, 0x7},
    {No_80DEE78, 0x8},
    {NULL, 0x0},
};

ALIGNED(4) const u8 No_80DEE78[] = "No";

const struct MenuItem gUnknown_80DEE7C[4] =
{
    {SendItem_Text, 0x9},
    {DontSendItem_Text, 0xA},
    {Cancel_80DEDD8, 0x0},
    {NULL, 0x0},
};

ALIGNED(4) const u8 DontSendItem_Text[] =  _("Don{APOSTROPHE}t Send Item");
ALIGNED(4) const u8 SendItem_Text[] = "Send Item";

const struct MenuItem gUnknown_80DEEBC[3] =
{
    {SendWOItem_Text, 0xA},
    {Cancel_80DEDD8, 0x0},
    {NULL, 0x0},
};

ALIGNED(4) const u8 SendWOItem_Text[] = "Send w/o Item";

const struct MenuItem gUnknown_80DEEE4[4] =
{
    {Yes_80DEE5C, 0x7},
    {No_80DEE78, 0x8},
    {Cancel_80DEDD8, 0x0},
    {NULL, 0x0},
};
