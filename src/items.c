#include "global.h"
#include "globaldata.h"
#include "code_8097DD0.h"
#include "constants/colors.h"
#include "constants/type.h"
#include "code_800D090.h"
#include "def_filearchives.h"
#include "items.h"
#include "moves.h"
#include "pokemon.h"
#include "random.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "pokemon_types.h"
#include "strings.h"
#include "dungeon_info.h"

extern const s32 gUnknown_810A3F0[100];
extern const s16 gTypeGummiIQBoost[NUM_TYPES][NUMBER_OF_GUMMIS];
extern u8 gInvalidItemIDs[0x10];

EWRAM_DATA OpenedFile *gItemParametersFile = {NULL};
EWRAM_DATA ItemDataEntry *gItemParametersData = {NULL}; // NDS=0213BEF0
EWRAM_DATA TeamInventory gTeamInventory = {0}; // NDS=0213BEF8
EWRAM_INIT TeamInventory *gTeamInventoryRef = {NULL}; // NDS=020EAF98

static void SortKecleonShopInventory(void);
static bool8 AddKecleonWareItem(u8 itemIndex);

static void sub_8090F58(u8 *, u8 *, Item *, const unkStruct_8090F58 *);

#define UNK_8108F64_ARR_COUNT 64

static const u8 gUnknown_8108F64[UNK_8108F64_ARR_COUNT][32] = {  // some sort of bit lookup table
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x2c, 0x01, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x0c, 0x21, 0x40, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x21, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x84, 0x0c, 0x21, 0x44, 0xff, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x11, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x08, 0x00, 0x02, 0x00, 0x80, 0x80, 0x0c, 0x21, 0xc4, 0x55, 0x1d, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x08, 0x02, 0x02, 0x00, 0x80, 0x00, 0x0c, 0x21, 0xc4, 0xfd, 0x25, 0x02, 0x00, 0x00, 0x66, 0x81, 0x83, 0x4d, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x21, 0xc0, 0xfe, 0x44, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x08, 0x00, 0x02, 0x00, 0x80, 0x80, 0x0c, 0x21, 0xc4, 0xfc, 0x45, 0x02, 0x00, 0x00, 0x66, 0x81, 0x83, 0x4d, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x80, 0x00, 0x18, 0x82, 0x00, 0x00, 0x80, 0x00, 0x0c, 0x21, 0xc4, 0xfd, 0x45, 0x02, 0x00, 0x00, 0x66, 0x81, 0x83, 0x4d, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x80, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x64, 0x02, 0x00, 0x00, 0x66, 0x81, 0x83, 0x4d, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x18, 0x80, 0x02, 0x00, 0x80, 0x00, 0x0c, 0x21, 0x44, 0xfd, 0x61, 0x02, 0x00, 0x00, 0x66, 0x81, 0x83, 0x4d, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x08, 0x20, 0x00, 0x09, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x84, 0x04, 0x38, 0x80, 0x02, 0x00, 0x80, 0x04, 0x0c, 0x21, 0x44, 0xfd, 0x7d, 0x02, 0x00, 0x00, 0x66, 0x83, 0x93, 0x4d, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x08, 0x20, 0x40, 0xfd, 0x45, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x8c, 0x14, 0x7e, 0xa2, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x64, 0x02, 0x00, 0x20, 0x66, 0x81, 0xd7, 0xcd, 0xf4, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x0c, 0x14, 0x7e, 0xa2, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xa8, 0x0c, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xef, 0xf4, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00},
    {0x00, 0x14, 0x7f, 0xa0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xef, 0xf4, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x3c, 0x7e, 0xc2, 0x08, 0x10, 0xa0, 0x20, 0xbe, 0x21, 0xc0, 0xff, 0x7f, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0x7f, 0xf0, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8c, 0x3c, 0x7e, 0xc2, 0x08, 0x10, 0xa0, 0x80, 0xbc, 0x20, 0x10, 0x01, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0x7f, 0xf0, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x08, 0x20, 0x40, 0xfd, 0x45, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x84, 0x3c, 0xe1, 0x03, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0x02, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x21, 0x9a, 0x21, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0x02, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x21, 0x9a, 0x21, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xbe, 0x7e, 0xe9, 0x4e, 0x3c, 0xa0, 0xa7, 0xbf, 0x39, 0x20, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xfc, 0x27, 0xfc, 0xff, 0xbb, 0x9f, 0x79, 0xec, 0x00, 0x01, 0x00, 0x00},
    {0x8e, 0xfe, 0x7e, 0xe9, 0x4e, 0x34, 0xa0, 0xa7, 0xbf, 0x39, 0x04, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xfc, 0x27, 0xfc, 0xff, 0xbb, 0x9f, 0x59, 0xec, 0x00, 0x01, 0x00, 0x00},
    {0x8c, 0x14, 0x7f, 0xe2, 0x00, 0x00, 0xa0, 0x84, 0x0f, 0x21, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00},
    {0x8c, 0x14, 0x7f, 0xe2, 0x00, 0x00, 0xa0, 0x84, 0x0f, 0x21, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00},
    {0x8e, 0xff, 0xff, 0xeb, 0xef, 0x77, 0xa0, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x04, 0x38, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x28, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0xc0, 0x03, 0x69, 0x46, 0x00, 0xa0, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x00, 0x02, 0x08, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xc0, 0x03, 0x69, 0x46, 0x10, 0xa0, 0xae, 0xbf, 0x39, 0x08, 0x00, 0x00, 0x02, 0x20, 0x60, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xc0, 0x03, 0x69, 0x46, 0x00, 0xa0, 0xae, 0xbf, 0xf9, 0x07, 0x00, 0x00, 0x02, 0x02, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xc0, 0x03, 0x69, 0x46, 0x00, 0xa0, 0xae, 0xbf, 0xf9, 0x07, 0x00, 0x00, 0x02, 0x04, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x82, 0x3c, 0x06, 0xc0, 0x0c, 0x30, 0xa0, 0x00, 0x0d, 0x21, 0x00, 0x00, 0x00, 0x82, 0x01, 0x28, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00},
    {0x8e, 0xc0, 0x03, 0x69, 0x46, 0x00, 0xa0, 0xae, 0xbf, 0xf9, 0x07, 0x00, 0x00, 0x12, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xfd, 0x7f, 0xe9, 0xcf, 0x37, 0xa0, 0x84, 0x3c, 0x21, 0x10, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xef, 0xf4, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xff, 0xff, 0xeb, 0xef, 0x77, 0xa0, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x35, 0x7b, 0xab, 0xc9, 0x01, 0x20, 0x28, 0x38, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0x7f, 0xf0, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x20, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x0c, 0x01, 0x04, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x08, 0x40, 0x06, 0x00, 0xa0, 0x80, 0x0c, 0x21, 0xc4, 0x55, 0x1d, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x08, 0x40, 0x06, 0x00, 0xa0, 0x80, 0x0c, 0x21, 0xc4, 0x55, 0x1d, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x35, 0xfb, 0xab, 0xc9, 0x01, 0x20, 0x28, 0x38, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x35, 0xfb, 0xab, 0xc9, 0x01, 0x20, 0x28, 0x38, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x0d, 0x21, 0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x0d, 0x21, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8c, 0x14, 0x7f, 0xe2, 0x00, 0x00, 0xa0, 0x84, 0x0f, 0x21, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xff, 0xff, 0xeb, 0xef, 0x77, 0xa0, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0x34, 0xfb, 0xab, 0xc9, 0x01, 0xa0, 0xad, 0xbf, 0x39, 0xfc, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x04, 0x8c, 0x21, 0xc4, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0xac, 0x1c, 0x19, 0x04, 0x56, 0x02, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00},
    {0x8e, 0xff, 0xff, 0xeb, 0xef, 0x77, 0xa0, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xff, 0xff, 0xeb, 0xef, 0x77, 0xa0, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x8c, 0x21, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xc5, 0x7f, 0x88, 0x8e, 0x1b, 0xa0, 0xad, 0xbf, 0xe5, 0x2b, 0x00, 0x00, 0x02, 0x00, 0x20, 0xef, 0xd3, 0xd7, 0xff, 0xfe, 0x07, 0xf4, 0xff, 0xb9, 0xff, 0xf9, 0xee, 0x00, 0x01, 0x00, 0x00},
    {0x80, 0x35, 0xfb, 0xab, 0xc9, 0x01, 0x20, 0x28, 0x38, 0x00, 0x00, 0x00, 0x00, 0x62, 0x00, 0x28, 0x67, 0x93, 0xd7, 0x7f, 0xf0, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x39, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xff, 0xff, 0xeb, 0xef, 0x77, 0xa0, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
    {0x8e, 0xfd, 0xff, 0xeb, 0xef, 0x3f, 0xa0, 0xfb, 0xbf, 0x3f, 0x1c, 0x00, 0x00, 0x02, 0x00, 0x20, 0xef, 0xd3, 0xd7, 0xff, 0xfe, 0x27, 0xfc, 0xff, 0xfb, 0xff, 0xf9, 0xee, 0x00, 0x01, 0x00, 0x00},
    {0x8e, 0xff, 0xff, 0xeb, 0xef, 0x7f, 0xa0, 0xfb, 0xbf, 0x3f, 0x1c, 0x00, 0x00, 0x02, 0x00, 0x20, 0x67, 0x93, 0xd7, 0xff, 0xf4, 0x07, 0xd0, 0xa1, 0x03, 0x37, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00},
};

// arm9.bin::020610C0
void LoadItemParameters(void)
{
    gTeamInventoryRef = &gTeamInventory;
    gItemParametersFile = OpenFileAndGetFileDataPtr("itempara", &gSystemFileArchive);
    gItemParametersData = (ItemDataEntry *) gItemParametersFile->data;
    // More in NDS including loading to vram and UnusedGetSir0Ptr()
}

// arm9.bin::020610b4
TeamInventory *GetMoneyItemsInfo(void)
{
    return &gTeamInventory;
}

// arm9.bin::02061034
void InitializeMoneyItems(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++)
        gTeamInventoryRef->teamItems[i].flags = 0;

    for (i = 0; i < STORAGE_SIZE; i++)
        gTeamInventoryRef->teamStorage[i] = 0;

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++)
        InitKecleonShopItem(i);

    gTeamInventoryRef->teamMoney = 0;
    gTeamInventoryRef->teamSavings = 0;
}

// arm9.bin::02060FE4
s32 GetNumberOfFilledInventorySlots(void)
{
  s32 i;
  s32 count;

  count = 0;
  for(i = 0; i < INVENTORY_SIZE; i++)
  {
    if ((gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_EXISTS) != 0) {
      count++;
    }
  }
  return count;
}

// arm9.bin::02060FB0
bool8 IsThrowableItem(u8 id)
{
  if ((GetItemCategory(id) != CATEGORY_THROWN_LINE) && (GetItemCategory(id) != CATEGORY_THROWN_ARC))
    return FALSE;
  else
    return TRUE;
}

// arm9.bin::02060F04
void ItemIdToItem(Item *item, u8 id, bool8 makeSticky)
{
    if (id != ITEM_NOTHING) {
        item->flags = ITEM_FLAG_EXISTS;
        item->id = id;
        if (IsThrowableItem(id)) {
            s32 min = GetSpawnAmountRange(id, MIN_SPAWN_AMOUNT);
            s32 max = GetSpawnAmountRange(id, MAX_SPAWN_AMOUNT);
            item->quantity = RandRange(min, max);
        }
        else if (GetItemCategory(id) == CATEGORY_POKE) {
            item->quantity = 1;
        }
        else {
            item->quantity  = 0;
        }

        if (makeSticky) {
            item->flags |= ITEM_FLAG_STICKY;
        }
    }
    else {
        item->flags = 0;
        item->id = ITEM_NOTHING;
        item->quantity  = 0;
    }
}

// arm9.bin::02060E80
void ItemIdToBulkItem(BulkItem *dst, u8 id)
{
    if (id != ITEM_NOTHING) {
        dst->id = id;
        if (IsThrowableItem(id)) {
            s32 min = GetSpawnAmountRange(id, MIN_SPAWN_AMOUNT);
            s32 max = GetSpawnAmountRange(id, MAX_SPAWN_AMOUNT);
            dst->quantity = RandRange(min, max);
        }
        else if (GetItemCategory(id) == CATEGORY_POKE)
            dst->quantity = 1;
        else
            dst->quantity = 0;
    }
    else {
        dst->id = ITEM_NOTHING;
        dst->quantity = 0;
    }
}

// arm9.bin::02060DF0
void BulkItemToItem(Item *dst, BulkItem *src)
{
    u8 is_throwable;

    if (src->id != ITEM_NOTHING) {
        dst->flags = ITEM_FLAG_EXISTS;
        dst->id = src->id;
        is_throwable = IsThrowableItem(dst->id);
        if (is_throwable != 0 || GetItemCategory(dst->id) == CATEGORY_POKE)
            dst->quantity = src->quantity;
        else if (dst->id == ITEM_TM_USED_TM)
            dst->quantity = src->quantity;
        else
            dst->quantity = 0;
    }
    else {
        ZeroOutItem(dst);
    }
}

// arm9.bin::02060DC0
void ItemToBulkItem(BulkItem *dst, Item *src)
{
    if (ItemExists(src)) {
        dst->id = src->id;
        dst->quantity = src->quantity;
    }
    else {
        dst->id = ITEM_NOTHING;
    }
}

// arm9.bin::02060DA8
u8 GetItemCategory(u8 index)
{
    return gItemParametersData[index].category;
}

// arm9.bin::02060D44
s32 GetStackBuyValue(Item *param_1)
{
    if (param_1->id == ITEM_POKE)
        return GetMoneyValue(param_1);
    else if (IsThrowableItem(param_1->id))
        return gItemParametersData[param_1->id].buyPrice * param_1->quantity;
    else
        return gItemParametersData[param_1->id].buyPrice;
}

// arm9.bin::02060CE0
s32 GetStackSellValue(Item *param_1)
{
    if (param_1->id == ITEM_POKE)
        return GetMoneyValue(param_1);
    else if (IsThrowableItem(param_1->id))
        return gItemParametersData[param_1->id].sellPrice * param_1->quantity;
    else
        return gItemParametersData[param_1->id].sellPrice;
}

// arm9.bin::02060C7C
s32 GetStackBuyPrice(Item *param_1)
{
    if (!CanSellItem(param_1->id))
        return 0;
    else if (IsThrowableItem(param_1->id))
        return gItemParametersData[param_1->id].buyPrice * param_1->quantity;
    else
        return gItemParametersData[param_1->id].buyPrice;
}

// arm9.bin::02060C18
s32 GetStackSellPrice(Item *param_1)
{
    if (!CanSellItem(param_1->id))
        return 0;
    else if (IsThrowableItem(param_1->id))
        return gItemParametersData[param_1->id].sellPrice * param_1->quantity;
    else
        return gItemParametersData[param_1->id].sellPrice;
}

// arm9.bin::02060C00
s32 GetItemBuyPrice(u8 id)
{
    return gItemParametersData[id].buyPrice;
}

// arm9.bin::02060BE8
s32 GetItemSellPrice(u8 id)
{
    return gItemParametersData[id].sellPrice;
}

// arm9.bin::02060BD0
s32 GetItemOrder(u8 id)
{
    return gItemParametersData[id].order;
}

// arm9.bin::02060BB8
s32 GetItemPalette(u8 id)
{
    return gItemParametersData[id].palette;
}

// arm9.bin::02060BA0
u32 GetItemActionType(u8 id)
{
    return gItemParametersData[id].actionType;
}

// arm9.bin::02060B84
u32 GetSpawnAmountRange(u8 id, u32 rangeIndex)
{
    return gItemParametersData[id].spawnAmountRange[rangeIndex];
}

// arm9.bin::02060B6C
u8 *GetItemDescription(u8 id)
{
    return gItemParametersData[id].description;
}

// arm9.bin::02060B50
bool8 TestItemAIFlag(u8 id, u32 aiFlag)
{
    return gItemParametersData[id].aiFlags[aiFlag];
}

// a2 is always NULL
// This func probably appends the quantity of 1, but I haven't checked
// If it appends quantity, we can rename the func
// arm9.bin::02060AEC
void BufferItemName(u8* dest, u8 id, struct unkStruct_8090F58* a2)
{
    u8 acStack104[80]; // 85 in NDS
    Item unkItem;

    strncpy(acStack104, gItemParametersData[id].name, 80);
    ItemIdToItem(&unkItem, id, 0);
    unkItem.quantity = 1;
    sub_8090F58(dest, acStack104, &unkItem, a2);
}

// arm9.bin::020608CC
void sub_8090E14(u8* ext_buffer, Item* slot, const struct unkStruct_8090F58* a3)
{
  s32 unk8 = 0;
  u8 buffer[80]; // 84 in NDS

  if (a3)
    unk8 = a3->unk8 != 0;

  if (GetItemCategory(slot->id) == CATEGORY_THROWN_LINE) {
    // I feel like these labels might actually be there...
    if (unk8) {
      sprintfStatic(buffer, "%s %d", gItemParametersData[slot->id].name, slot->quantity);
    }
    else {
      sprintfStatic(buffer, "%s", gItemParametersData[slot->id].name);
    }
  }
  else if (GetItemCategory(slot->id) == CATEGORY_THROWN_ARC) {
    if (unk8) {
      sprintfStatic(buffer, "%s %d", gItemParametersData[slot->id].name, slot->quantity);
    }
    else {
      sprintfStatic(buffer, "%s", gItemParametersData[slot->id].name);
    }
  }
  else if (slot->id == ITEM_POKE) {
    sprintfStatic(buffer, _("%d {POKE}"), GetMoneyValue(slot));
  }
  else {
    strncpy(buffer, gItemParametersData[slot->id].name, 80);
  }

  if (slot->flags & ITEM_FLAG_STICKY) {
    sprintfStatic(ext_buffer, _("{ICON_STICKY}%s"), buffer);
    strncpy(buffer, ext_buffer, 80);
  }

  if (a3) {
    if (a3->unk4 && (slot->flags & ITEM_FLAG_SET)) {
      sprintfStatic(ext_buffer, _("{ICON_SET}%s"), buffer);
      strncpy(buffer, ext_buffer, 80);
    }
    if ((*(u32*)a3 == 1) || (*(u32*)a3 == 3)) {
        if (slot->flags & ITEM_FLAG_IN_SHOP) {
          sub_8090F58(ext_buffer, buffer, slot, a3);
          return;
        }
      strncpy(ext_buffer, buffer, 80);
      return;
    }
  }
  else {
    strncpy(ext_buffer, buffer, 80);
    return;
  }

  sub_8090F58(ext_buffer, buffer, slot, a3);
  return;
}

// arm9.bin::020607E4
static void sub_8090F58(u8* a1, u8 *a2, Item *slot, const struct unkStruct_8090F58* a4)
{
  u32 unk0;
  s32 value;
  u8 buffer[40]; // 44 in NDS

  if (!a4) {
    strncpy(a1, a2, 80);
    return;
  }
  else {
    unk0 = a4->unk0;
    switch (unk0) {
      case 1:
      case 2:
        value = GetStackBuyValue(slot);
        break;
      case 3:
      case 4:
        value = GetStackSellValue(slot);
        break;
      default:
        value = 0;
        break;
    }

    if (!value) {
      strncpy(a1, a2, 80);
      return;
    }
  }

  if (a4->unk6) {
    WriteHighDecimal(value, buffer, 1);
    sprintfStatic(a1, _("%s{MOVE_X_POSITION}%c{COLOR GREEN_RAW}%s{RESET}"), a2, a4->unk6, buffer);
  }
  else {
    WriteHighDecimal(value, buffer, 0);
    sprintfStatic(a1, _("%s{COLOR GREEN_RAW}%s{RESET}"), a2, buffer);
  }
}

static const s32 sPowersOfTen[] = {100000, 10000, 1000, 100, 10};
static const u8 sHighDigits[][2] = {
    {0x83, 0x9F},
    {0x83, 0xA0},
    {0x83, 0xA1},
    {0x83, 0xA2},
    {0x83, 0xA3},
    {0x83, 0xA4},
    {0x83, 0xA5},
    {0x83, 0xA6},
    {0x83, 0xA7},
    {0x83, 0xA8},
    {0, 0},
};

UNUSED static const u8 *const sHighDigitsPtr = sHighDigits[0];

// arm9.bin::020606E0
s32 WriteHighDecimal(s32 a1, u8 *strbuf, u8 a3)
{
    s32 i, count;
    s32 cond = 0;

    count = 0;
    for (i = 0; i < 5; i++) {
        s32 div;

        div = 0;
        while (a1 >= sPowersOfTen[i]) {
            a1 -= sPowersOfTen[i];
            div++;
        }

        if (div > 9) {
            div = 9;
        }

        if (div) {
            cond = 1;
            *strbuf++ = sHighDigits[div][0];
            *strbuf++ = sHighDigits[div][1];
            count++;
        }
        else if (cond) {
            *strbuf++ = sHighDigits[0][0];
            *strbuf++ = sHighDigits[0][1];
            count++;
        }
        else if (a3) {
            *strbuf++ = 96;  // ` character?
        }
    }

    *strbuf++ = sHighDigits[a1][0];
    *strbuf   = sHighDigits[a1][1];
    count += 1;
    strbuf[1] = '\0';  // null termination
    return count;
}

// arm9.bin::02060614
void FillInventoryGaps(void)
{
  // fill inventory gaps
  s32 slot_checking = 0;
  s32 last_filled = 0;

  do {
    while (slot_checking < INVENTORY_SIZE) {
      if (slot_checking[gTeamInventoryRef->teamItems].flags & ITEM_FLAG_EXISTS) {
        break;
      }
      // find next empty slot
      slot_checking++;
    }

    if (slot_checking == INVENTORY_SIZE) {
      break;
    }

    if (slot_checking > last_filled) {
      // shift it down
      gTeamInventoryRef->teamItems[last_filled] = gTeamInventoryRef->teamItems[slot_checking];
    }
    slot_checking++;
    last_filled++;
  } while (1);

  // clear out the rest of the slots
  for (; last_filled < INVENTORY_SIZE; last_filled++) {
      ZeroOutItem(&gTeamInventoryRef->teamItems[last_filled]);
  }
}

// arm9.bin::020605A4
s32 FindItemInInventory(u8 id)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if ((gTeamInventoryRef->teamItems[i].flags & ITEM_FLAG_EXISTS)
            && gTeamInventoryRef->teamItems[i].id == id) {
            return i;
        }
    }

    return -1;
}

// arm9.bin::02060540
s32 GetItemCountInInventory(u8 id)
{
    s32 i;
    s32 count = 0;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (ItemExists(&gTeamInventoryRef->teamItems[i])
            && gTeamInventoryRef->teamItems[i].id == id) {
            count++;
        }
    }

    return count;
}

// arm9.bin::0206049C
s32 GetItemPossessionCount(u8 id)
{
    s32 count = GetItemCountInInventory(id);
    s32 i = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        Pokemon *mon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonExists(mon)
        && PokemonFlag2(mon)
        && (mon->heldItem.id != ITEM_NOTHING)
        && (mon->heldItem.id == id))
        {
            count++;
        }
    }
    return count;
}

// arm9.bin::0206042C
void ShiftItemsDownFrom(s32 start)
{
    s32 i, j;

    for (i = start, j = start + 1; i < INVENTORY_SIZE - 1; i++, j++)
        gTeamInventoryRef->teamItems[i] = gTeamInventoryRef->teamItems[j];

    gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].id = ITEM_NOTHING;
    gTeamInventoryRef->teamItems[INVENTORY_SIZE - 1].flags = 0;
}

// arm9.bin::02060400
void ClearItemSlotAt(u32 index)
{
    gTeamInventoryRef->teamItems[index].id = ITEM_NOTHING;
    gTeamInventoryRef->teamItems[index].flags = 0;
}

// arm9.bin::020603D4
bool8 sub_809124C(u8 id, u8 param_3)
{
    Item temp;

    ItemIdToItem(&temp, id, param_3);
    return AddItemToInventory(&temp);
}

// arm9.bin::020603B0
bool8 AddHeldItemToInventory(BulkItem* slot)
{
    Item temp;

    BulkItemToItem(&temp, slot);
    return AddItemToInventory(&temp);
}

// arm9.bin::02060330
bool8 AddItemToInventory(const Item* slot)
{
    s32 i;

    // try to add item to inventory, return 1 if failed
    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (!ItemExists(&gTeamInventoryRef->teamItems[i])) {
            gTeamInventoryRef->teamItems[i] = *slot;
            return FALSE;
        }
    }
    return TRUE;
}

// arm9.bin::02060178
void ConvertMoneyItemToMoney(void)
{
    s32 i, j;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item *item = &gTeamInventoryRef->teamItems[i];
        if (ItemExists(item) && item->id == ITEM_POKE) {
            AddToTeamMoney(GetMoneyValue(item));
            ZeroOutItem(item);
        }
    }
    FillInventoryGaps();

    for (i = 0; i < INVENTORY_SIZE; i++) {
        s32 lowestIndex = -1;

        if (ItemExists(&gTeamInventoryRef->teamItems[i])) {
            s32 lowestOrder = GetItemOrder(gTeamInventoryRef->teamItems[i].id);

            for (j = i + 1; j < INVENTORY_SIZE; j++) {
                if (ItemExists(&gTeamInventoryRef->teamItems[j]) && lowestOrder > GetItemOrder(gTeamInventoryRef->teamItems[j].id)) {
                    lowestIndex = j;
                    lowestOrder = GetItemOrder(gTeamInventoryRef->teamItems[j].id);
                }
            }

            if (lowestIndex >= 0) {
                // swap the slots
                Item temp = gTeamInventoryRef->teamItems[i];
                gTeamInventoryRef->teamItems[i] = gTeamInventoryRef->teamItems[lowestIndex];
                gTeamInventoryRef->teamItems[lowestIndex] = temp;
            }
        }
    }
    FillInventoryGaps();
}

// arm9.bin::02060134
void AddToTeamMoney(s32 amount)
{
    s32 clamped_money;

    gTeamInventoryRef->teamMoney += amount;

    // clamp money
    clamped_money = MAX_TEAM_MONEY;

    if (gTeamInventoryRef->teamMoney <= MAX_TEAM_MONEY) {
        if (gTeamInventoryRef->teamMoney >= 0)
            return;

        clamped_money = 0;
    }

    gTeamInventoryRef->teamMoney = clamped_money;
}

// arm9.bin::0206011C
u16 GetItemMoveID(u8 index)
{
    return gItemParametersData[index].moveID;
}

// arm9.bin::0205FFA0
u32 sub_80913E0(Item* slot, u32 windowId, STATUSTEXTS(statuses))
{
    u8 buffer88[88]; // some struct

    GetItemDescription(slot->id);
    BufferItemName(buffer88, slot->id, NULL);

    if (slot->id == ITEM_TM_USED_TM) {
        // empty TM
        BufferItemName(gFormatBuffer_Items[0], (u8)(slot->quantity + 125), NULL);
    }

    sub_80073B8(windowId);
    PrintFormattedStringOnWindow(16, 0, buffer88, windowId, 0);
    PrintFormattedStringOnWindow(8, 24, GetItemDescription(slot->id), windowId, 0);

    if (GetItemCategory(slot->id) == CATEGORY_TMS_HMS) {
        Move *buffer8 = (Move*) (buffer88 + 80); // field in struct
        u16 move = GetItemMoveID(slot->id);
        u8 moves_data;
        const u8* typestring;
        u32 result;

        InitPokemonMove(buffer8, move);
        AddDoubleUnderScoreHighlight(windowId, 4, 82, 200, COLOR_WHITE_2);
        PrintFormattedStringOnWindow(4, 84, gTextType, windowId, 0);
        moves_data = GetMoveType(buffer8);
        typestring = GetUnformattedTypeString(moves_data);
        PrintFormattedStringOnWindow(64, 84, typestring, windowId, 0);
        result = GetMoveBasePP(buffer8);
        gFormatArgs[0] = result;
        PrintFormattedStringOnWindow(128, 84, gText_PP_Value0, windowId, 0);
    }

    sub_80073E0(windowId);
    return PrepareStatusStringArrays(GetItemDescription(slot->id), statuses);
}

// arm9.bin::0205FF28
bool8 CanSellItem(u32 id)
{
    u8 id_;
    id = (u8)id;
    id_ = id;

    if (id != ITEM_NOTHING
        && id != ITEM_POKE
        && id != ITEM_ROCK_PART
        && id != ITEM_ICE_PART
        && id != ITEM_STEEL_PART
        && id != ITEM_MUSIC_BOX
        && GetItemSellPrice(id_)
        && GetItemBuyPrice(id_))
        return TRUE;

    return FALSE;
}

// arm9.bin::0205FEFC
bool8 IsNotMoneyOrUsedTMItem(u8 id)
{
    if (id == ITEM_NOTHING)
        return FALSE;
    if (id == ITEM_POKE)
        return FALSE;
    if (id == ITEM_TM_USED_TM)
        return FALSE;
    return TRUE;
}

// arm9.bin::0205FEAC
bool8 IsNotSpecialItem(u8 id)
{
    if (id == ITEM_NOTHING)
        return FALSE;
    if (id == ITEM_POKE)
        return FALSE;
    if (id == ITEM_ROCK_PART)
        return FALSE;
    if (id == ITEM_ICE_PART)
        return FALSE;
    if (id == ITEM_STEEL_PART)
        return FALSE;
    if (id == ITEM_MUSIC_BOX)
        return FALSE;
    return TRUE;
}

// arm9.bin::0205FE78
bool8 IsEdibleItem(u8 id)
{
    if (!(GetItemCategory(id) == CATEGORY_BERRIES_SEEDS_VITAMINS
        || GetItemCategory(id) == CATEGORY_FOOD_GUMMIES)) {
        return FALSE;
    }
    return TRUE;
}

// arm9.bin::0205FE10
bool8 IsHMItem(u8 id)
{
    if (id == ITEM_HM_CUT)
        return TRUE;
    if (id == ITEM_HM_FLY)
        return TRUE;
    if (id == ITEM_HM_SURF)
        return TRUE;
    if (id == ITEM_HM_STRENGTH)
        return TRUE;
    if (id == ITEM_HM_FLASH)
        return TRUE;
    if (id == ITEM_HM_ROCK_SMASH)
        return TRUE;
    if (id == ITEM_HM_WATERFALL)
        return TRUE;
    if (id == ITEM_HM_DIVE)
        return TRUE;
    return FALSE;
}

// arm9.bin::0205FDFC
u32 GetMoneyValue(Item* slot)
{
    return gUnknown_810A3F0[slot->quantity];
}

// arm9.bin::0205FDE8
u32 GetMoneyValueHeld(BulkItem* slot)
{
    // potentially different slot type (used for held item)
    return gUnknown_810A3F0[slot->quantity];
}

static const u16 sGummiStatBoostsFlags[] = {1, 2, 4, 8};

// arm9.bin::0205FC30
void GetGummiItemStatBoost(Pokemon* pokemon, u8 id, bool8 checkBoostFlags, Gummi *gummi)
{
  // item stat buff?
  s8 result;

  gummi->boostAmount = (u16)-1;
  gummi->flags = 0;
  result = IsGummiItem(id);
  if (result) {
    u8 pokemon_type_0 = GetPokemonType(pokemon->speciesNum, 0);
    u8 pokemon_type_1 = GetPokemonType(pokemon->speciesNum, 1);
    u32 gummi_index = id - ITEM_WHITE_GUMMI + 1;
    s32 value0;
    s32 value1;
    s32 diff;
    u16 boost_amount;

    value0 = gTypeGummiIQBoost[pokemon_type_0][gummi_index];
    value1 = gTypeGummiIQBoost[pokemon_type_1][gummi_index];
    diff  = pokemon->IQ;

    pokemon->IQ += value0 + value1;
    diff = pokemon->IQ - diff;
    if (pokemon->IQ <= 0) {
      pokemon->IQ = 1;
    }
    if (pokemon->IQ > 999) {
      pokemon->IQ = 999;
    }

    boost_amount = 0;
    if (diff <= 8) {
      boost_amount = 1;
      if (diff <= 4) {
        boost_amount = 3;
        if (diff > 2) {
          boost_amount = 2;
        }
      }
    }
    gummi->boostAmount = boost_amount;
    if (!checkBoostFlags) {
      u16 boost_flags;
      if (!boost_amount && RandInt(16) == 10) {
        // supa gummi (all stats boost)
        boost_flags = 0xf;
      }
      else {
        s32 random_index = RandInt(4);
        boost_flags = sGummiStatBoostsFlags[random_index];
      }

      gummi->flags = boost_flags;
      boost_flags = gummi->flags;
      if (gummi->flags & 1) {
        if (pokemon->offense.att[OFFENSE_NRM] < 255) {
          pokemon->offense.att[OFFENSE_NRM]++;
        }
        else {
          // fix operand order
          u16 unk2 = gummi->flags;
          unk2 &= ~1;
          gummi->flags &= unk2;
        }
      }
      if (gummi->flags & 2) {
        if (pokemon->offense.att[OFFENSE_SP] < 255) {
          pokemon->offense.att[OFFENSE_SP]++;
        }
        else {
          gummi->flags &= ~2;
        }
      }
      if (gummi->flags & 4) {
        if (pokemon->offense.def[OFFENSE_NRM] < 255) {
          pokemon->offense.def[OFFENSE_NRM]++;
        }
        else {
          gummi->flags &= ~4;
        }
      }
      if (gummi->flags & 8) {
        if (pokemon->offense.def[OFFENSE_SP] < 255) {
          pokemon->offense.def[OFFENSE_SP] ++;
        }
        else {
          gummi->flags &= ~8;
        }
      }
    }
  }
}

// arm9.bin::0205FC10
bool8 IsGummiItem(u8 id)
{
    if (id < ITEM_WHITE_GUMMI)
        return FALSE;
    if (id > ITEM_SILVER_GUMMI)
        return FALSE;
    return TRUE;
}

// arm9.bin::0205FBA4
bool8 HasGummiItem(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (ItemExists(&gTeamInventoryRef->teamItems[i])
            && IsGummiItem(gTeamInventoryRef->teamItems[i].id)) {
            return TRUE;
        }
    }

    return FALSE;
}

// arm9.bin::0205FB18
void MoveToStorage(Item* slot)
{
    if (IsThrowableItem(slot->id))
        gTeamInventoryRef->teamStorage[slot->id] += slot->quantity;
    else
        gTeamInventoryRef->teamStorage[slot->id]++;

    if (gTeamInventoryRef->teamStorage[slot->id] > 999)
        gTeamInventoryRef->teamStorage[slot->id] = 999;
}

// arm9.bin::0205FAE4
s32 CountKecleonShopItems(void)
{
    s32 i;
    s32 counter = 0;

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
        if (gTeamInventoryRef->kecleonShopItems[i].id)
            counter++;
    }

    return counter;
}

// arm9.bin::0205FAC0
void InitKecleonShopItem(u8 index)
{
    BulkItem* shopItem;

    shopItem = &gTeamInventoryRef->kecleonShopItems[index];
    shopItem->id = ITEM_NOTHING;
    shopItem->quantity = 0;
}

// arm9.bin::0205FAA8
BulkItem* GetKecleonShopItem(u8 i)
{
    return &gTeamInventoryRef->kecleonShopItems[i];
}

// arm9.bin::0205FA20
void FillKecleonShopGaps(void)
{
    s32 slot_checking = 0;
    s32 last_filled = 0;

    do {
        while (slot_checking < MAX_KECLEON_ITEM_SHOP_ITEMS) {
            if (gTeamInventoryRef->kecleonShopItems[slot_checking].id)
                break;

            // find next empty slot
            slot_checking++;
        }

        if (slot_checking == MAX_KECLEON_ITEM_SHOP_ITEMS)
            break;

        if (slot_checking > last_filled) {
            // shift it down
            gTeamInventoryRef->kecleonShopItems[last_filled] = gTeamInventoryRef->kecleonShopItems[slot_checking];
        }
        slot_checking++;
        last_filled++;
    } while (TRUE);

    // clear out the rest of the slots
    for (; last_filled < MAX_KECLEON_ITEM_SHOP_ITEMS; last_filled++)
        InitKecleonShopItem(last_filled);
}

// arm9.bin::0205F94C
static void SortKecleonShopInventory(void)
{
    s32 i;

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS - 1; i++) {
        s32 j;

        for (j = i + 1; j < MAX_KECLEON_ITEM_SHOP_ITEMS; j++) {
            s32 order_i = GetItemOrder(gTeamInventoryRef->kecleonShopItems[i].id);
            s32 order_j = GetItemOrder(gTeamInventoryRef->kecleonShopItems[j].id);

            if (order_i > order_j || (order_i == order_j && gTeamInventoryRef->kecleonShopItems[i].quantity < gTeamInventoryRef->kecleonShopItems[j].quantity)) {
                BulkItem str_i = gTeamInventoryRef->kecleonShopItems[i];
                gTeamInventoryRef->kecleonShopItems[i] = gTeamInventoryRef->kecleonShopItems[j];
                gTeamInventoryRef->kecleonShopItems[j] = str_i;
            }
        }
    }
}

// arm9.bin::0205F8B8
void ChooseKecleonShopInventory(u8 index)
{
    s32 setIds[] = {RANDOM_ITEMS_SET_KECLEON_SHOP_1, RANDOM_ITEMS_SET_KECLEON_SHOP_2, RANDOM_ITEMS_SET_KECLEON_SHOP_3, RANDOM_ITEMS_SET_KECLEON_SHOP_4};
    s32 i;

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++)
        InitKecleonShopItem(i);

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
        s32 rand_1 = RandInt(9999);
        s32 rand_2 = RandInt(9999);

        AddKecleonShopItem(GetRandomItemForSet(setIds[index], rand_1, rand_2));
    }

    SortKecleonShopInventory();
    ChooseKecleonWareInventory(index);
}

// arm9.bin::0205F850
bool8 AddKecleonShopItem(u8 itemIndex)
{
    BulkItem held;
    s32 i;

    ItemIdToBulkItem(&held, itemIndex); // initialize

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++) {
        if (!gTeamInventoryRef->kecleonShopItems[i].id) {
            gTeamInventoryRef->kecleonShopItems[i] = held;
            return FALSE;
        }
    }

    return TRUE;
}

// arm9.bin::0205f81C
u32 CountKecleonWareItems(void)
{
    s32 i;
    u32 count = 0;

    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
        if (gTeamInventoryRef->kecleonWareItems[i].id)
            count++;
    }

    return count;
}

// arm9.bin::0205F7F8
void InitKecleonWareItem(u8 index)
{
    BulkItem* wareItem = &gTeamInventoryRef->kecleonWareItems[index];
    wareItem->id = ITEM_NOTHING;
    wareItem->quantity = 0;
}

// arm9.bin::0205F7E0
BulkItem* GetKecleonWareItem(u8 index)
{
    return &gTeamInventoryRef->kecleonWareItems[index];
}

// arm9.bin::0205F758
void FillKecleonWareGaps(void)
{
    s32 slot_checking = 0;
    s32 last_filled = 0;

    do {
        while (slot_checking < MAX_KECLEON_WARE_SHOP_ITEMS) {
            if (gTeamInventoryRef->kecleonWareItems[slot_checking].id != ITEM_NOTHING)
                break;

            slot_checking++;
        }

        if (slot_checking == MAX_KECLEON_WARE_SHOP_ITEMS)
            break;

        if (slot_checking > last_filled) {
            // shift it down
            gTeamInventoryRef->kecleonWareItems[last_filled] = gTeamInventoryRef->kecleonWareItems[slot_checking];
        }
        slot_checking++;
        last_filled++;
    } while (TRUE);

    // clear out the rest of the slots
    for (; last_filled < MAX_KECLEON_WARE_SHOP_ITEMS; last_filled++)
        InitKecleonWareItem(last_filled);
}

// arm9.bin::0205F684
void SortKecleonWareInventory(void)
{
    s32 i;

    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS - 1; i++) {
        s32 j;

        for (j = i + 1; j < MAX_KECLEON_WARE_SHOP_ITEMS; j++) {
            s32 order_i = GetItemOrder(gTeamInventoryRef->kecleonWareItems[i].id);
            s32 order_j = GetItemOrder(gTeamInventoryRef->kecleonWareItems[j].id);

            if (order_i > order_j || (order_i == order_j && gTeamInventoryRef->kecleonWareItems[i].quantity < gTeamInventoryRef->kecleonWareItems[j].quantity)) {
                BulkItem str_i = gTeamInventoryRef->kecleonWareItems[i];
                gTeamInventoryRef->kecleonWareItems[i] = gTeamInventoryRef->kecleonWareItems[j];
                gTeamInventoryRef->kecleonWareItems[j] = str_i;
            }
        }
    }
}

// arm9.bin::0205F5F8
void ChooseKecleonWareInventory(u8 index)
{
    s32 setIds[] = {RANDOM_ITEMS_SET_KECLEON_WARES_1, RANDOM_ITEMS_SET_KECLEON_WARES_2, RANDOM_ITEMS_SET_KECLEON_WARES_3, RANDOM_ITEMS_SET_KECLEON_WARES_4};
    s32 i;

    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++)
        InitKecleonWareItem(i);

    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
        s32 rand_1 = RandInt(ITEM_SETS_RANDOM_CAP);
        s32 rand_2 = RandInt(ITEM_SETS_RANDOM_CAP);

        AddKecleonWareItem(GetRandomItemForSet(setIds[index], rand_1, rand_2));
    }

    SortKecleonWareInventory();
}

// arm9.bin::0205F590
static bool8 AddKecleonWareItem(u8 itemIndex)
{
    BulkItem held;
    s32 i;

    ItemIdToBulkItem(&held, itemIndex); // initialize

    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++) {
        if (!gTeamInventoryRef->kecleonWareItems[i].id) {
            gTeamInventoryRef->kecleonWareItems[i] = held;
            return FALSE;
        }
    }

    return TRUE;
}

// arm9.bin::0205F474
s32 SaveTeamInventory(u8* unk0, u32 size)
{
    DataSerializer seri;
    s32 i;

    InitBitWriter(&seri, unk0, size);

    for (i = 0; i < INVENTORY_SIZE; i++)
        WriteItemSlotBits(&seri, &gTeamInventoryRef->teamItems[i]);

    for (i = 0; i < STORAGE_SIZE; i++)
        WriteBits(&seri, &gTeamInventoryRef->teamStorage[i], 10);

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++)
        WriteHeldItemBits(&seri, &gTeamInventoryRef->kecleonShopItems[i]);

    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++)
        WriteHeldItemBits(&seri, &gTeamInventoryRef->kecleonWareItems[i]);

    WriteBits(&seri, &gTeamInventoryRef->teamMoney, 24);
    WriteBits(&seri, &gTeamInventoryRef->teamSavings, 24);

    FinishBitSerializer(&seri);
    return seri.count;
}

// arm9.bin::0205F358
s32 RestoreTeamInventory(u8 *unk0, u32 size)
{
    DataSerializer seri;
    s32 i;

    InitBitReader(&seri, unk0, size);

    for (i = 0; i < INVENTORY_SIZE; i++)
        ReadItemSlotBits(&seri, &gTeamInventoryRef->teamItems[i]);

    for (i = 0; i < STORAGE_SIZE; i++)
        ReadBits(&seri, &gTeamInventoryRef->teamStorage[i], 10);

    for (i = 0; i < MAX_KECLEON_ITEM_SHOP_ITEMS; i++)
        ReadHeldItemBits(&seri, &gTeamInventoryRef->kecleonShopItems[i]);

    for (i = 0; i < MAX_KECLEON_WARE_SHOP_ITEMS; i++)
        ReadHeldItemBits(&seri, &gTeamInventoryRef->kecleonWareItems[i]);

    ReadBits(&seri, &gTeamInventoryRef->teamMoney, 24);
    ReadBits(&seri, &gTeamInventoryRef->teamSavings, 24);

    FinishBitSerializer(&seri);
    return seri.count;
}

// arm9.bin::0205F328
void ReadHeldItemBits(DataSerializer *a1, BulkItem *item)
{
    ReadBits(a1, &item->id, 8);
    ReadBits(a1, &item->quantity, 7);
}

// arm9.bin::0205F2F8
void WriteHeldItemBits(DataSerializer *a1, BulkItem *item)
{
    WriteBits(a1, &item->id, 8);
    WriteBits(a1, &item->quantity, 7);
}

// arm9.bin::0205F2B8
void ReadItemSlotBits(DataSerializer *a1, Item *slot)
{
    ReadBits(a1, &slot->flags, 8);
    ReadBits(a1, &slot->quantity, 7);
    ReadBits(a1, &slot->id, 8);
}

// arm9.bin::0205F278
void WriteItemSlotBits(DataSerializer *a1, Item *slot)
{
    WriteBits(a1, &slot->flags, 8);
    WriteBits(a1, &slot->quantity, 7);
    WriteBits(a1, &slot->id, 8);
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static const u8 *sub_8091E50(u8 index)
{
  return gUnknown_810AF50[index];
}
#endif

// arm9.bin::0205F240
u8 xxx_bit_lut_lookup_8091E50(u8 i0, u8 i1)
{
    if (i0 >= UNK_8108F64_ARR_COUNT - 1)
        return 0;
    return (gUnknown_8108F64[i0][i1 >> 3] >> (i1 & 7)) & 1;
}

// arm9.bin::0205F0C8
u8 GetRandomItemForSet(s32 setId, s32 rndValCategory, s32 rndValItem)
{
    s32 id, i, arrId;
    u8 foundCategory, ret;
    struct ItemSpawns data;
    s16 rawArray[NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS];
    const u16 *ptr = gRandomItemsSets[setId - 1];

    id = 0;
    arrId = 0;
    while (id < NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS) {
        if (ptr[arrId] >= ITEM_SETS_SKIP_NUMBER) {
            s32 a = ptr[arrId] - ITEM_SETS_SKIP_NUMBER;

            while (a != 0) {
                rawArray[id++] = 0;
                a--;
            }
        }
        else {
            rawArray[id++] = ptr[arrId];
        }
        arrId++;
    }

    arrId = 0;
    for (id = 0; id < NUM_ITEM_CATEGORIES; id++) {
        data.categoryValues[arrId] = rawArray[arrId];
        arrId++;
    }

    for (id = 0; id < NUMBER_OF_ITEM_IDS; id++) {
        data.itemValues[id] = rawArray[arrId];
        arrId++;
    }

    foundCategory = NUM_ITEM_CATEGORIES;
    for (i = 0; i < NUM_ITEM_CATEGORIES; i++) {
        if (data.categoryValues[i] != 0 && data.categoryValues[i] >= rndValCategory) {
            foundCategory = i;
            break;
        }
    }

    ret = ITEM_PLAIN_SEED;
    if (foundCategory != NUM_ITEM_CATEGORIES) {
        for (i = 0; i < NUMBER_OF_ITEM_IDS; i++) {
            if (data.itemValues[i] != 0 && GetItemCategory(i) == foundCategory && data.itemValues[i] >= rndValItem) {
                ret = i;
                break;
            }
        }
    }

    return ret;
}

// arm9.bin::0205EFAC
void ClearAllItems_8091FB4(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item* slot = &gTeamInventoryRef->teamItems[i];
        if (ItemExists(slot)) {
            slot->flags &= ~(ITEM_FLAG_STICKY);
            if (slot->id == ITEM_POKE) {
                AddToTeamMoney(GetMoneyValue(slot));
                ZeroOutItem(slot);
            }
        }
    }
    FillInventoryGaps();
    for (i = 0; i < NUM_MONSTERS; i++) {
        if (PokemonExists(&gRecruitedPokemonRef->pokemon[i])) {
            Pokemon *pokemon = &gRecruitedPokemonRef->pokemon[i];
            if (pokemon->heldItem.id) {
                if (pokemon->heldItem.id == ITEM_POKE) {
                    AddToTeamMoney(GetMoneyValueHeld(&pokemon->heldItem));
                    pokemon->heldItem.id = ITEM_NOTHING;
                }
            }
        }
    }
}

// arm9.bin::0205EF6C
bool8 IsInvalidItemReward(u8 itemID)
{
    if (itemID >= NUMBER_OF_ITEM_IDS)
        return TRUE;
    else {
        s32 index = 0;

        while (gInvalidItemIDs[index] != NUMBER_OF_ITEM_IDS) {
            if (gInvalidItemIDs[index] == itemID)
                return TRUE;
            index++;
        }
        return FALSE;
    }
}
