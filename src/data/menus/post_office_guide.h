const struct MenuItem gPostOfficeHelpStartMenu[] =
{
    {PostOffice_Text, POST_OFFICE},
    {BulletinBoard_Text, BULLETIN_BOARD},
    {Delivery_Text, DELIVERY},
    {FriendRescue_80E0A80, FRIEND_RESCUE},
    {Cancel_80E0A78, CANCEL},
    {NULL, EXIT}
};

ALIGNED(4) const char Cancel_80E0A78[] = _("Cancel");
ALIGNED(4) const char FriendRescue_80E0A80[] = _("{COLOR_1 YELLOW}Friend Rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) const char Delivery_Text[] = _("Delivery");
ALIGNED(4) const char BulletinBoard_Text[] = _("Bulletin Board");
ALIGNED(4) const char PostOffice_Text[] = _("Post Office");

const struct MenuItem gPostOfficeHelpFriendRescueMenu[] =
{
    {FriendRescueInfo_Text, FRIEND_RESCUE_INFO},
    {GoRescue_Text, GO_RESCUE},
    {GetHelp_Text, GET_HELP_MENU},
    {DeletingMailInfo_Text, DELETING_MAIL},
    {Exit_80EA0EC, EXIT},
    {NULL, EXIT}
};

ALIGNED(4) const char Exit_80EA0EC[] = _("Exit");
ALIGNED(4) const char DeletingMailInfo_Text[] = _("Deleting Mail Info");
ALIGNED(4) const char GetHelp_Text[] = _("{COLOR_1 YELLOW}Get help{END_COLOR_TEXT_1} ");
ALIGNED(4) const char GoRescue_Text[] = _("{COLOR_1 YELLOW}Go rescue{END_COLOR_TEXT_1} ");
ALIGNED(4) const char FriendRescueInfo_Text[] = _("Friend Rescue Info");


const struct MenuItem gPostOfficeHelpGoRescueMenu[] =
{
    {RescueProcedures_Text, RESCUE_PROCEDURES},
    {ReceiveSOSMail_Text, RECEIVE_SOS_MAIL},
    {LeaveForRescue_Text, LEAVE_FOR_RESCUE},
    {SendAOKMail_Text, SEND_AOK_MAIL},
    {GetThankYouMail_Text, GET_THANK_YOU_MAIL},
    {Exit_80EA0EC, EXIT},
    {NULL, EXIT}
};

ALIGNED(4) const char GetThankYouMail_Text[] = _("Get Thank-You Mail");
ALIGNED(4) const char SendAOKMail_Text[] = _("Send A-OK Mail");
ALIGNED(4) const char LeaveForRescue_Text[] = _("Leave for Rescue");
ALIGNED(4) const char ReceiveSOSMail_Text[] = _("Receive SOS Mail");
ALIGNED(4) const char RescueProcedures_Text[] = _("Rescue Procedures");


const struct MenuItem gPostOfficeHelpGetHelpMenu[] =
{
    {GettingHelp_Text, GETTING_HELP},
    {SendSOSMail_Text, SEND_SOS_MAIL},
    {ReceiveAOKMail_Text, RECEIVE_AOK_MAIL},
    {SendThankYouMail_Text, SEND_THANK_YOU_MAIL},
    {Exit_80EA0EC, EXIT},
    {NULL, EXIT}
};

ALIGNED(4) const char SendThankYouMail_Text[] = _("Send Thank-You Mail");
ALIGNED(4) const char ReceiveAOKMail_Text[] = _("Receive A-OK Mail");
ALIGNED(4) const char SendSOSMail_Text[] = _("Send SOS Mail");
ALIGNED(4) const char GettingHelp_Text[] = _("Getting Help");
