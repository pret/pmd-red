extern const u8 DontSendPokemon_80DDB80[];
extern const u8 SendPokemon_80DDB98[];
extern const u8 gWonderMailYes[];
extern const u8 gWonderMailNo[];
extern const u8 gWonderMailCancel[];
extern const u8 Password_80DDB44[];
extern const u8 GameLinkCable_80DDB50[];
extern const u8 Confirm_80DDB1C[];
extern const u8 Info_80DDB14[];
extern const u8 SendWOPokemon[];
extern const u8 gWonderMailDeleteAllMail[];
extern const u8 gWonderMailDeleteAOKMail[];
extern const u8 gWonderMailDeleteSOSMail[];
extern const u8 gWonderMailCancel[];
extern const u8 gWonderMailDeleteMail[];
extern const u8 gWonderMailSendAOKMail[];
extern const u8 gWonderMailLeaveForRescue[];
extern const u8 gWonderMailReceiveSOSMail[];

const struct MenuItem gUnknown_80DD970[] =
{
    {gWonderMailReceiveSOSMail, 0x0},
    {gWonderMailLeaveForRescue, 0x1},
    {gWonderMailSendAOKMail, 0x2},
    {gWonderMailDeleteMail, 0x3},
    {gWonderMailCancel, 0xA},
    {NULL, 0xA}
};

ALIGNED(4) const u8 gWonderMailCancel[] = "Cancel";
ALIGNED(4) const u8 gWonderMailDeleteMail[] = "Delete Mail";
ALIGNED(4) const u8 gWonderMailSendAOKMail[] = "Send A-OK Mail";
ALIGNED(4) const u8 gWonderMailLeaveForRescue[] = "Leave for Rescue";
ALIGNED(4) const u8 gWonderMailReceiveSOSMail[] = "Receive SOS Mail";

const struct MenuItem gUnknown_80DD9EC[] =
{
    {gWonderMailDeleteSOSMail, 0x5},
    {gWonderMailDeleteAOKMail, 0x6},
    {gWonderMailDeleteAllMail, 0x7},
    {gWonderMailCancel, 0xA},
    {NULL, 0xA}
};

ALIGNED(4) const u8 gWonderMailDeleteAllMail[] = "Delete All Mail";
ALIGNED(4) const u8 gWonderMailDeleteAOKMail[] = "Delete A-OK Mail";
ALIGNED(4) const u8 gWonderMailDeleteSOSMail[] = "Delete SOS Mail";


const struct MenuItem gUnknown_80DDA48[] =
{
    {gWonderMailYes, 0x8},
    {gWonderMailCancel, 0xA},
    {NULL, 0xA}
};

ALIGNED(4) const u8 gWonderMailYes[] = "Yes";

const struct MenuItem gUnknown_80DDA64[] =
{
    {gWonderMailYes, 0x8},
    {gWonderMailNo, 0x9},
    {NULL, 0xA}
};

ALIGNED(4) const u8 gWonderMailNo[] = "No";

const struct MenuItem gUnknown_80DDA80[] =
{
    {gWonderMailYes, 0x8},
    {gWonderMailNo, 0x9},
    {gWonderMailCancel, 0xA},
    {NULL, 0xA}
};

const struct MenuItem gUnknown_80DDAA0[] =
{
    {SendWOPokemon, 0x12},
    {gWonderMailCancel, 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 SendWOPokemon[] = _("Send w/o Pokémon");

const struct UnkTextStruct2 gUnknown_80DDACC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
    0x16, 0x00, 0x07, 0x00,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DDAE4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
    0x16, 0x00, 0x06, 0x00,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const struct MenuItem gUnknown_80DDAFC[] =
{
    {Confirm_80DDB1C, 0xB},
    {Info_80DDB14, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 Info_80DDB14[] = "Info";
ALIGNED(4) const u8 Confirm_80DDB1C[] = "Confirm";

const struct MenuItem gUnknown_80DDB24[] =
{
    {GameLinkCable_80DDB50, 0xD},
    {Password_80DDB44, 0xF},
    {gWonderMailCancel, 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 Password_80DDB44[] = "Password";
ALIGNED(4) const u8 GameLinkCable_80DDB50[] = "Game Link cable";

const struct MenuItem gUnknown_80DDB60[] =
{
    {SendPokemon_80DDB98, 0x11},
    {DontSendPokemon_80DDB80, 0x12},
    {gWonderMailCancel, 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 DontSendPokemon_80DDB80[] = _("Don{APOSTROPHE}t Send Pokémon");
ALIGNED(4) const u8 SendPokemon_80DDB98[] = _("Send Pokémon");
