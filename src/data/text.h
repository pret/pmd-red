const u32 gUnknown_80B853C[16] =
{
    0x66666666,
    0x00000000,
    0x11111111,
    0x22222222,
    0x33333333,
    0x44444444,
    0x55555555,
    0x66666666,
    0x77777777,
    0x88888888,
    0x99999999,
    0xAAAAAAAA,
    0xBBBBBBBB,
    0xCCCCCCCC,
    0xDDDDDDDD,
    0xEEEEEEEE,
};

static const WindowTemplates sDummyWindows =
{
    .id = {
        [0] = WIN_TEMPLATE_DUMMY,
        [1] = WIN_TEMPLATE_DUMMY,
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

const unkShiftData gCharMasksOffsets[8] =
{
    [0] = {.bytesA = 0xFFFFFFFF, .bytesB = 0x00000000, .shift_left = 0x00, .shift_right = 0x20},
    [1] = {.bytesA = 0x0FFFFFFF, .bytesB = 0xF0000000, .shift_left = 0x04, .shift_right = 0x1C},
    [2] = {.bytesA = 0x00FFFFFF, .bytesB = 0xFF000000, .shift_left = 0x08, .shift_right = 0x18},
    [3] = {.bytesA = 0x000FFFFF, .bytesB = 0xFFF00000, .shift_left = 0x0C, .shift_right = 0x14},
    [4] = {.bytesA = 0x0000FFFF, .bytesB = 0xFFFF0000, .shift_left = 0x10, .shift_right = 0x10},
    [5] = {.bytesA = 0x00000FFF, .bytesB = 0xFFFFF000, .shift_left = 0x14, .shift_right = 0x0C},
    [6] = {.bytesA = 0x000000FF, .bytesB = 0xFFFFFF00, .shift_left = 0x18, .shift_right = 0x08},
    [7] = {.bytesA = 0x0000000F, .bytesB = 0xFFFFFFF0, .shift_left = 0x1C, .shift_right = 0x04},
};

static const u16 sUnknown_80B865C[] =
{
    0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF,
    0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF,
    0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF,
    0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF,
    0xFF, 0, 0, 0, 0, 0, 0
};

// Fallback character with bitmap?
const unkChar gUnknown_80B86A4 =
{
    .unk0 = sUnknown_80B865C,
    .unk4 = 0x81A1,
    .unk6 = 7,
    .unk8 = 10,
    .fill9 = 0,
    .unkA = 0,
    .fillB = 0,
};

// Very weird...
UNUSED static const u8 sByte8 = 8;

const u32 gUnknown_80B86B4[][32] = INCBIN_U32("graphics/warning.4bpp");

static const u8 sKanjiA_file_string[] = "kanji_a";
static const u8 sKanjiB_file_string[] = "kanji_b";

static const u32 sFadeInNone[8] = {0};
static const u32 sFadeInDungeon[8] = {0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888};

static const u32 sUnknown_80B8804[4] = {0, 1, 2, 3};
static const u32 sUnknown_80B8814[4] = {1, 2, 3, 0};