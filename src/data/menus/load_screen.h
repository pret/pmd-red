extern const u8 Deleted_80E7700[];
extern const u8 Deleted_80E7718[];
extern const u8 Deleted_80E7748[];
extern const u8 Deleted_80E7768[];
extern const u8 QuitAwaitingRescue_80E76D0[];
extern const u8 IsThatOK_80E765C[];
extern const u8 ResumeAdventure_80E769C[];
extern const u8 ResumeQuicksave_80E7668[];
extern const char No_80E77B4[];
extern const char Yes_80E77B8[];

const struct UnkTextStruct2 gUnknown_80E75F8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const struct UnkTextStruct2 gUnknown_80E7610 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x1A, 0x0B,
   0x0B, 0x00,
   NULL
};

const u8 gUnkData_80E7628[] = {0x20, 0x00, 0x00, 0x00};

const struct UnkTextStruct2 gUnknown_80E762C = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x0F, 0x00,
   0x13, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gResumeQuicksaveMenuItems[3] =
{
    {ResumeQuicksave_80E7668, 5},
    {IsThatOK_80E765C, 5},
    {NULL, 3},
};

ALIGNED(4) static const u8 IsThatOK_80E765C[] = "Is that OK?";
ALIGNED(4) static const u8 ResumeQuicksave_80E7668[] = "Resuming from quicksave.";

const struct MenuItem gResumeAdventureMenuItems[3] =
{
    {ResumeAdventure_80E769C, 5},
    {IsThatOK_80E765C, 5},
    {NULL, 3},
};

ALIGNED(4) static const u8 ResumeAdventure_80E769C[] = "Resuming saved adventure.";

const struct MenuItem gQuitWaitingRescueMenuItems[3] =
{
    {QuitAwaitingRescue_80E76D0, 5},
    {IsThatOK_80E765C, 5},
    {NULL, 3},
};

ALIGNED(4) static const u8 QuitAwaitingRescue_80E76D0[] = "Quit awaiting rescue?";

const struct MenuItem gDeleteSavePromptMenuItems[3] =
{
    {Deleted_80E7718, 5},
    {Deleted_80E7700, 5},
    {NULL, 3},
};

ALIGNED(4) static const u8 Deleted_80E7700[] = "deleted. Is that OK?";
ALIGNED(4) static const u8 Deleted_80E7718[] = "Your saved data will be";

const struct MenuItem gDeleteSaveConfirmMenuItems[3] =
{
    {Deleted_80E7768, 5},
    {Deleted_80E7748, 5},
    {NULL, 3},
};

ALIGNED(4) static const u8 Deleted_80E7748[] = "delete all of your saved data?";
ALIGNED(4) static const u8 Deleted_80E7768[] = "Are you sure you want to";

const struct UnkTextStruct2 gUnknown_80E7784 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
    0x17, 0x00, 0x0F, 0x00,
    0x05, 0x03,
    0x03, 0x00,
    NULL
};

const struct MenuItem gLoadScreenYesNoMenu[3] =
{
    {Yes_80E77B8, 1},
    {No_80E77B4, 2},
    {NULL, 3},
};

ALIGNED(4) static const char No_80E77B4[] = "No";
ALIGNED(4) static const char Yes_80E77B8[] = "Yes";
