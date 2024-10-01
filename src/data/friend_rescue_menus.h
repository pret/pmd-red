extern const u8 GoRescue_80E20AC[];
extern const u8 GetHelp_80E20A0[];
extern const u8 Info_80E2098[];
extern const u8 Exit_80E2090[];

const MenuItem gUnknown_80E2068[5] = {
    {GoRescue_80E20AC, 0x0},
    {GetHelp_80E20A0, 0x1},
    {Info_80E2098, 0x17},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

const u8 Exit_80E2090[] = "Exit";
const u8 Info_80E2098[] = "Info";
const u8 GetHelp_80E20A0[] = "Get Help";
const u8 GoRescue_80E20AC[] = "Go Rescue";

const MenuItem gUnknown_80E20B8[5] = {
    {GoRescue_80E20AC, 0x0},
    {GetHelp_80E20A0, -1},
    {Info_80E2098, 0x17},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

const MenuItem gUnknown_80E20E0[5] = {
    {GoRescue_80E20AC, -1},
    {GetHelp_80E20A0, 1},
    {Info_80E2098, 0x17},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};
const MenuItem gUnknown_80E2108[5] = {
    {GoRescue_80E20AC, -1},
    {GetHelp_80E20A0, -1},
    {Info_80E2098, 0x17},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

extern const u8 ReceiveSOSMail_80E217C[];
extern const u8 SendAOKMail_80E216C[];
extern const u8 GetThankYouMail_80E2158[];

const MenuItem gUnknown_80E2130[5] = {
    {ReceiveSOSMail_80E217C, 3},
    {SendAOKMail_80E216C, 4},
    {GetThankYouMail_80E2158, 0x14},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

const u8 GetThankYouMail_80E2158[] = "Get Thank-You Mail";
const u8 SendAOKMail_80E216C[] = "Send A-OK Mail";
const u8 ReceiveSOSMail_80E217C[] = "Receive SOS Mail";

const MenuItem gUnknown_80E2190[5] = {
    {ReceiveSOSMail_80E217C, 3},
    {SendAOKMail_80E216C, -1},
    {GetThankYouMail_80E2158, 0x14},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

extern const u8 SendSOS_80E2208[];
extern const u8 ReceiveAOK_80E21F4[];
extern const u8 SendThankYou_80E21E0[];


const MenuItem gUnknown_80E21B8[5] = {
    {SendSOS_80E2208, 0x11},
    {ReceiveAOK_80E21F4, 0x12},
    {SendThankYou_80E21E0, 0x13},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

const u8 SendThankYou_80E21E0[] = "Send Thank-You Mail";
const u8 ReceiveAOK_80E21F4[] = "Receive A-OK Mail";
const u8 SendSOS_80E2208[] = "Send SOS Mail";

const MenuItem gUnknown_80E2218[5] = {
    {SendSOS_80E2208, -1},
    {ReceiveAOK_80E21F4, -1},
    {SendThankYou_80E21E0, 0x13},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

const MenuItem gUnknown_80E2240[5] = {
    {SendSOS_80E2208, 0x11},
    {ReceiveAOK_80E21F4, 0x12},
    {SendThankYou_80E21E0, -1},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

const MenuItem gUnknown_80E2268[5] = {
    {SendSOS_80E2208, -1},
    {ReceiveAOK_80E21F4, -1},
    {SendThankYou_80E21E0, -1},
    {Exit_80E2090, 0x8},
    {NULL, 0x8},
};

extern const u8 Yes_80E22B0[];
extern const u8 Cancel_80E22A8[];


const MenuItem gUnknown_80E2290[3] = {
    {Yes_80E22B0, 6},
    {Cancel_80E22A8, 0x8},
    {NULL, 0x8},
};

const u8 Cancel_80E22A8[] = "Cancel";
const u8 Yes_80E22B0[] = "Yes";


extern const u8 No_80E22CC[];

const MenuItem gUnknown_80E22B4[3] = {
    {Yes_80E22B0, 6},
    {No_80E22CC, 7},
    {NULL, 0x8},
};

const u8 No_80E22CC[] = "No";

const MenuItem gUnknown_80E22D0[4] = {
    {Yes_80E22B0, 6},
    {No_80E22CC, 7},
    {Cancel_80E22A8, 8},
    {NULL, 0x8},
};

extern const u8 SendPokemon_80E2308[];

const MenuItem gUnknown_80E22F0[3] = {
    {SendPokemon_80E2308, 0x10},
    {Cancel_80E22A8, 8},
    {NULL, 0x8},
};

const u8 SendPokemon_80E2308[] = _("Send w/o Pokémon");

const UnkTextStruct2 gUnknown_80E231C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x07,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80E2334 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x06,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

extern const u8 Confirm_80E2364[];

const MenuItem gUnknown_80E234C[3] = {
    {Confirm_80E2364, 9},
    {Info_80E2098, 10},
    {NULL, 0x8},
};

const u8 Confirm_80E2364[] = "Confirm";

extern const u8 GameLinkCable_80E2398[];
extern const u8 Password_80E238C[];

const MenuItem gUnknown_80E236C[4] = {
    {GameLinkCable_80E2398, 0xB},
    {Password_80E238C, 0xD},
    {Cancel_80E22A8, 8},
    {NULL, 0x8},
};

const u8 Password_80E238C[] = "Password";
const u8 GameLinkCable_80E2398[] = "Game Link cable";

extern const u8 SendPokemon_80E23E0[];
extern const u8 DontSendPokemon_80E23C8[];

const MenuItem gUnknown_80E23A8[4] = {
    {SendPokemon_80E23E0, 0xF},
    {DontSendPokemon_80E23C8, 0x10},
    {Cancel_80E22A8, 8},
    {NULL, 0x8},
};

ALIGNED(4) const u8 DontSendPokemon_80E23C8[] = _("Don't Send Pokémon");
ALIGNED(4) const u8 SendPokemon_80E23E0[] = _("Send Pokémon");

const UnkTextStruct2 gUnknown_80E23F0 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x04,
    0x06, 0x05,
    0x05, 0x00,
    NULL
};

const MenuItem gUnknown_80E2408[4] = {
    {Confirm_80E2364, 0x9},
    {Info_80E2098, 0xA},
    {Cancel_80E22A8, 5},
    {NULL, 0x8},
};

UNUSED static const UnkTextStruct2 unused_text =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const MenuItem gUnknown_80E2440[3] = {
    {Yes_80E22B0, 6},
    {Cancel_80E22A8, 0x8},
    {NULL, 0x8},
};

const MenuItem gUnknown_80E2458[3] = {
    {Yes_80E22B0, 6},
    {No_80E22CC, 0x7},
    {NULL, 0x8},
};

extern const u8 SendItem_80E24A4[];
extern const u8 DontSendItem_80E2490[];

const MenuItem gUnknown_80E2470[4] = {
    {SendItem_80E24A4, 0x15},
    {DontSendItem_80E2490, 0x16},
    {Cancel_80E22A8, 8},
    {NULL, 0x8},
};

const u8 DontSendItem_80E2490[] = _("Don't Send Item");
const u8 SendItem_80E24A4[] = "Send Item";

extern const u8 SendwoItem_80E24C8[];

const MenuItem gUnknown_80E24B0[3] = {
    {SendwoItem_80E24C8, 0x16},
    {Cancel_80E22A8, 8},
    {NULL, 0x8},
};

const u8 SendwoItem_80E24C8[] = "Send w/o Item";

const MenuItem gUnknown_80E24D8[4] = {
    {Yes_80E22B0, 6},
    {No_80E22CC, 0x7},
    {Cancel_80E22A8, 0x8},
    {NULL, 0x8},
};

extern const u8 RescueInfo_80E2540[];
extern const u8 GoRescue_80E530[];
extern const u8 GetHelp_80E2520[];

const MenuItem gUnknown_80E24F8[5] = {
    {RescueInfo_80E2540, 0x1A},
    {GoRescue_80E530, 0x1B},
    {GetHelp_80E2520, 0x1C},
    {Cancel_80E22A8, 0x19},
    {NULL, 0x19},
};

ALIGNED(4) const u8 GetHelp_80E2520[] = _("{COLOR_1 YELLOW}Get help{END_COLOR_TEXT_1} ");
ALIGNED(4) const u8 GoRescue_80E530[] = _("{COLOR_1 YELLOW}Go rescue{END_COLOR_TEXT_1} ");
const u8 RescueInfo_80E2540[] = "Friend Rescue Info";

extern const u8 RescueProcedures_80E25A0[];
extern const u8 LeaveForRescue_80E258C[];

const MenuItem gUnknown_80E2554[7] = {
    {RescueProcedures_80E25A0, 0x1E},
    {ReceiveSOSMail_80E217C, 0x1F},
    {LeaveForRescue_80E258C, 0x20},
    {SendAOKMail_80E216C, 0x21},
    {GetThankYouMail_80E2158, 0x22},
    {Exit_80E2090, 0x19},
    {NULL, 0x19},
};

const u8 LeaveForRescue_80E258C[] = "Leave for Rescue";
const u8 RescueProcedures_80E25A0[] = "Rescue Procedures";

extern const u8 GettingHelp_80E25E4[];

const MenuItem gUnknown_80E25B4[6] = {
    {GettingHelp_80E25E4, 0x23},
    {SendSOS_80E2208, 0x24},
    {ReceiveAOK_80E21F4, 0x25},
    {SendThankYou_80E21E0, 0x26},
    {Exit_80E2090, 0x19},
    {NULL, 0x19},
};

const u8 GettingHelp_80E25E4[] = "Getting Help";
