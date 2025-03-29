#include "global.h"
#include "globaldata.h"
#include "dungeon_generation_fixed.h"
#include "dungeon_generation.h"
#include "dungeon_map_access.h"
#include "items.h"
#include "pokemon.h"
#include "code_80450F8.h"
#include "dungeon_util.h"
#include "dungeon_items.h"
#include "dungeon_message.h"
#include "code_803E668.h"
#include "structs/str_806B7F8.h"
#include "constants/monster.h"
#include "constants/trap.h"
#include "constants/item.h"

extern s32 sub_803DA20(s16 species);
extern void sub_80429FC(DungeonPos *r0);

static bool8 sub_805210C(u8 itemId);

static void SpawnItemAtPos(u8 itemId, s32 x, s32 y, s32 quantity, u32 itemFlags)
{
    Item item;
    DungeonPos pos = {x, y};

    if (sub_805210C(itemId)) {
        ItemIdToSlot(&item, ITEM_LINK_CABLE, 0);
    }
    else {
        ItemIdToSlot(&item, itemId, 0);
    }

    item.flags |= itemFlags;
    if (quantity != 0) {
        item.quantity = quantity;
    }

    AddItemToDungeonAt(&pos, &item, 1);
}

// s16 species memes strike again. Will the fix ever be discovered?
static void SpawnSpeciesAtPos(s16 species_, s32 x, s32 y, u32 monsterBehav_, u32 UNUSED unused)
{
    struct unkStruct_806B7F8 unkStruct;
    s32 species = SpeciesId(species_);
    u8 monsterBehav = monsterBehav_;

    if (species_ == MONSTER_DECOY) {
        unkStruct.species = MONSTER_POLIWAG;
        unkStruct.level = sub_803DA20(MONSTER_POLIWAG);
        unkStruct.unk2 = monsterBehav;
        unkStruct.unk4 = 0;
        unkStruct.unk10 = 0;
        unkStruct.pos.x = x;
        unkStruct.pos.y = y;
        sub_806B7F8(&unkStruct, TRUE);
    }
    else if (species != MONSTER_NONE) {
        unkStruct.species = species;
        unkStruct.level = sub_803DA20(species);
        unkStruct.unk2 = monsterBehav;
        unkStruct.unk4 = 0;
        unkStruct.unk10 = 0;
        unkStruct.pos.x = x;
        unkStruct.pos.y = y;
        sub_806B7F8(&unkStruct, TRUE);
    }
}

static void SpawnEnemyTrapAtPos(u8 trapId, s32 x, s32 y, bool8 isVisible)
{
    DungeonPos pos;
    Entity *trapEntity;
    Tile *tile = GetTileMut(x, y);

    pos.x = x;
    pos.y = y;
    trapEntity = SpawnTrap(trapId, &pos, 0);
    if (trapEntity != NULL) {
        tile->object = trapEntity;
        trapEntity->isVisible = isVisible;
    }
}

struct FixedRoomEntitiesInfo
{
    u8 itemId;
    s16 itemQuantity;
    u32 unk4;
    s16 speciesId;
    u8 monsterBehavior;
    u8 trapId;
    u8 roomId;
    bool8 trapVisible;
    bool8 setTerrainToSecondary;
};

static const struct FixedRoomEntitiesInfo sFixedRoomEntities[204] = {
    [0] = {
        .speciesId = MONSTER_SKARMORY,
        .monsterBehavior = BEHAVIOR_SKARMORY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [1] = {
        .speciesId = MONSTER_DIGLETT,
        .monsterBehavior = BEHAVIOR_DIGLETT,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [2] = {
        .speciesId = MONSTER_GENGAR,
        .monsterBehavior = BEHAVIOR_GENGAR,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [3] = {
        .speciesId = MONSTER_EKANS,
        .monsterBehavior = BEHAVIOR_EKANS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [4] = {
        .speciesId = MONSTER_MEDICHAM,
        .monsterBehavior = BEHAVIOR_MEDICHAM,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [5] = {
        .speciesId = MONSTER_ZAPDOS,
        .monsterBehavior = BEHAVIOR_ZAPDOS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [6] = {
        .unk4 = 1,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [7] = {
        .unk4 = 2,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [8] = {
        .unk4 = 3,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [9] = {
        .unk4 = 4,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [10] = {
        .unk4 = 5,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [11] = {
        .unk4 = 6,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [12] = {
        .unk4 = 7,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [13] = {
        .unk4 = 8,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [14] = {
        .speciesId = MONSTER_MOLTRES,
        .monsterBehavior = BEHAVIOR_MOLTRES,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [15] = {
        .speciesId = MONSTER_ALAKAZAM,
        .monsterBehavior = BEHAVIOR_ALAKAZAM_1,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [16] = {
        .speciesId = MONSTER_TYRANITAR,
        .monsterBehavior = BEHAVIOR_GROUDON_1,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [17] = {
        .speciesId = MONSTER_CHARIZARD,
        .monsterBehavior = BEHAVIOR_ALAKAZAM_2,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [18] = {
        .speciesId = MONSTER_ARTICUNO,
        .monsterBehavior = BEHAVIOR_ARTICUNO,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [19] = {
        .speciesId = MONSTER_GROUDON,
        .monsterBehavior = BEHAVIOR_GROUDON_2,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [20] = {
        .speciesId = MONSTER_RAYQUAZA,
        .monsterBehavior = BEHAVIOR_RAYQUAZA,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [21] = {
        .speciesId = MONSTER_MANKEY,
        .monsterBehavior = BEHAVIOR_MANKEY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [22] = {
        .speciesId = MONSTER_MEWTWO,
        .monsterBehavior = BEHAVIOR_MEWTWO,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [23] = {
        .speciesId = MONSTER_ENTEI,
        .monsterBehavior = BEHAVIOR_ENTEI,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [24] = {
        .speciesId = MONSTER_RAIKOU,
        .monsterBehavior = BEHAVIOR_RAIKOU,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [25] = {
        .speciesId = MONSTER_SUICUNE,
        .monsterBehavior = BEHAVIOR_SUICUNE,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [26] = {
        .speciesId = MONSTER_HO_OH,
        .monsterBehavior = BEHAVIOR_HO_OH,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [27] = {
        .speciesId = MONSTER_LATIOS,
        .monsterBehavior = BEHAVIOR_LATIOS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [28] = {
        .speciesId = MONSTER_REGIROCK,
        .monsterBehavior = BEHAVIOR_REGIROCK,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [29] = {
        .speciesId = MONSTER_REGICE,
        .monsterBehavior = BEHAVIOR_REGICE,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [30] = {
        .speciesId = MONSTER_REGISTEEL,
        .monsterBehavior = BEHAVIOR_REGISTEEL,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [31] = {
        .speciesId = MONSTER_JIRACHI,
        .monsterBehavior = BEHAVIOR_JIRACHI,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [32] = {
        .speciesId = MONSTER_LUGIA,
        .monsterBehavior = BEHAVIOR_LUGIA,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [33] = {
        .speciesId = MONSTER_KYOGRE,
        .monsterBehavior = BEHAVIOR_KYOGRE,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [34] = {
        .speciesId = MONSTER_DEOXYS_NORMAL,
        .monsterBehavior = BEHAVIOR_29,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [35] = {
        .speciesId = MONSTER_DEOXYS_ATTACK,
        .monsterBehavior = BEHAVIOR_FIXED_ENEMY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [36] = {
        .speciesId = MONSTER_DEOXYS_DEFENSE,
        .monsterBehavior = BEHAVIOR_FIXED_ENEMY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [37] = {
        .speciesId = MONSTER_DEOXYS_SPEED,
        .monsterBehavior = BEHAVIOR_FIXED_ENEMY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [38] = {
        .itemId = ITEM_ORAN_BERRY,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [39] = {
        .itemId = ITEM_STICK,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [40] = {
        .speciesId = MONSTER_TORCHIC,
        .monsterBehavior = BEHAVIOR_FIXED_ENEMY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [41] = {
        .speciesId = MONSTER_IVYSAUR,
        .monsterBehavior = BEHAVIOR_FIXED_ENEMY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [42] = {
        .speciesId = MONSTER_MUDKIP,
        .monsterBehavior = BEHAVIOR_FIXED_ENEMY,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [43] = {
        .speciesId = MONSTER_SMEARGLE,
        .monsterBehavior = BEHAVIOR_SMEARGLE,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [44] = {
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [45] = {
        .trapId = NUM_TRAPS,
        .roomId = 1,
    },
    [46] = {
        .trapId = NUM_TRAPS,
        .roomId = 2,
    },
    [47] = {
        .trapId = NUM_TRAPS,
        .roomId = 3,
    },
    [48] = {
        .trapId = NUM_TRAPS,
        .roomId = 4,
    },
    [49] = {
        .trapId = NUM_TRAPS,
        .roomId = 5,
    },
    [50] = {
        .trapId = NUM_TRAPS,
        .roomId = 0,
        .setTerrainToSecondary = TRUE,
    },
    [51] = {
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [52] = {
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [53] = {
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [54] = {
        .itemId = ITEM_HM_FLY,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [55] = {
        .itemId = ITEM_HM_SURF,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [56] = {
        .itemId = ITEM_HM_DIVE,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [57] = {
        .itemId = ITEM_HM_WATERFALL,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [58] = {
        .itemId = ITEM_BEAUTY_SCARF,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [59] = {
        .speciesId = MONSTER_CELEBI,
        .monsterBehavior = BEHAVIOR_CELEBI,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [60] = {
        .itemId = ITEM_FRIEND_BOW,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [61] = {
        .itemId = ITEM_TM_WIDE_SLASH,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [62] = {
        .itemId = ITEM_VACUUM_CUT,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [63] = {
        .itemId = ITEM_SUN_RIBBON,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [64] = {
        .itemId = ITEM_LUNAR_RIBBON,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [65] = {
        .itemId = ITEM_LUNAR_RIBBON,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [66] = {
        .itemId = ITEM_HM_CUT,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [67] = {
        .itemId = ITEM_HM_STRENGTH,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [68] = {
        .itemId = ITEM_HM_FLASH,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [69] = {
        .itemId = ITEM_HM_ROCK_SMASH,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [70] = {
        .itemId = ITEM_DEEPSEASCALE,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [71] = {
        .itemId = ITEM_WISH_STONE,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [72] = {
        .itemId = ITEM_DEEPSEATOOTH,
        .itemQuantity = 0,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [73] = {
        .speciesId = MONSTER_ZIGZAGOON,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [74] = {
        .speciesId = MONSTER_FURRET,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [75] = {
        .speciesId = MONSTER_FARFETCHD,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [76] = {
        .speciesId = MONSTER_RATICATE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [77] = {
        .speciesId = MONSTER_PONYTA,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [78] = {
        .speciesId = MONSTER_SLUGMA,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [79] = {
        .speciesId = MONSTER_MAGBY,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [80] = {
        .speciesId = MONSTER_POLIWAG,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [81] = {
        .speciesId = MONSTER_EXEGGCUTE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [82] = {
        .speciesId = MONSTER_SUNKERN,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [83] = {
        .speciesId = MONSTER_SHROOMISH,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [84] = {
        .speciesId = MONSTER_CACNEA,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [85] = {
        .speciesId = MONSTER_ELECTRIKE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [86] = {
        .speciesId = MONSTER_VOLTORB,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [87] = {
        .speciesId = MONSTER_SWINUB,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [88] = {
        .speciesId = MONSTER_PILOSWINE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [89] = {
        .speciesId = MONSTER_SNORUNT,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [90] = {
        .speciesId = MONSTER_MEDITITE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [91] = {
        .speciesId = MONSTER_TYROGUE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [92] = {
        .speciesId = MONSTER_HITMONLEE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [93] = {
        .speciesId = MONSTER_PHANPY,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [94] = {
        .speciesId = MONSTER_DIGLETT,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [95] = {
        .speciesId = MONSTER_DODUO,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [96] = {
        .speciesId = MONSTER_FARFETCHD,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [97] = {
        .speciesId = MONSTER_PIDGEY,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [98] = {
        .speciesId = MONSTER_WOBBUFFET,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [99] = {
        .speciesId = MONSTER_NIDORAN_F,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [100] = {
        .speciesId = MONSTER_NIDORAN_M,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [101] = {
        .speciesId = MONSTER_PINSIR,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [102] = {
        .speciesId = MONSTER_BEEDRILL,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [103] = {
        .speciesId = MONSTER_WEEDLE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [104] = {
        .speciesId = MONSTER_PUPITAR,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [105] = {
        .speciesId = MONSTER_SUDOWOODO,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [106] = {
        .speciesId = MONSTER_GEODUDE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [107] = {
        .speciesId = MONSTER_GASTLY,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [108] = {
        .speciesId = MONSTER_BAGON,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [109] = {
        .speciesId = MONSTER_SHELGON,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [110] = {
        .speciesId = MONSTER_POOCHYENA,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [111] = {
        .speciesId = MONSTER_MURKROW,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [112] = {
        .speciesId = MONSTER_ARON,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [113] = {
        .speciesId = MONSTER_BELDUM,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [114] = {
        .speciesId = MONSTER_OCTILLERY,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [115] = {
        .speciesId = MONSTER_TENTACRUEL,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [116] = {
        .speciesId = MONSTER_CRADILY,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [117] = {
        .speciesId = MONSTER_BLASTOISE,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [118] = {
        .speciesId = MONSTER_FERALIGATR,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [119] = {
        .speciesId = MONSTER_SWAMPERT,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [120] = {
        .speciesId = MONSTER_GOLEM,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [121] = {
        .speciesId = MONSTER_GRAVELER,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [122] = {
        .speciesId = MONSTER_MUDKIP,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [123] = {
        .speciesId = MONSTER_SHIFTRY,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [124] = {
        .speciesId = MONSTER_NUZLEAF,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [125] = {
        .speciesId = MONSTER_POLIWAG,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [126] = {
        .speciesId = MONSTER_POLIWAG,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [127] = {
        .speciesId = MONSTER_POLIWAG,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
    [128] = {
        .speciesId = MONSTER_POLIWAG,
        .monsterBehavior = BEHAVIOR_MAZE_BOSS,
        .trapId = NUM_TRAPS,
        .roomId = 0,
    },
};

// Used to spawn a single tile when generating a fixed room. The tile might contain an item or a monster.
bool8 PlaceFixedRoomTile(Tile *tile, u8 fixedRoomActionId, s32 x, s32 y, bool8 spawnTrapOrItem)
{
    if (fixedRoomActionId > 0xF) {
        SetTerrainNormal(tile);
    }

    switch (fixedRoomActionId) {
        case 69:
            gDungeon->unk644.unk40 = x;
            gDungeon->unk644.unk42 = y;
            SpawnEnemyTrapAtPos(TRAP_SEAL_TRAP, x, y, FALSE);
            // fall through
        case 0:
            SetTerrainNormal(tile);
            tile->room = 0;
            break;
        case 1:
            SetTerrainWall(tile);
            tile->terrainType &= ~(TERRAIN_TYPE_UNBREAKABLE);
            tile->room = CORRIDOR_ROOM;
            break;
        case 4:
            SetTerrainNormal(tile);
            gDungeon->playerSpawn.x = x;
            gDungeon->playerSpawn.y = y;
            tile->room = 0;
            break;
        case 5:
            SetTerrainSecondary(tile);
            tile->room = 0;
            break;
        case 6:
            SetTerrainType(tile, TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL);
            tile->room = CORRIDOR_ROOM;
            break;
        case 7:
            gUnknown_202F1A8 = 1;
            sub_8049840();
            // fall through
        case 10:
            SetTerrainType(tile, TERRAIN_TYPE_SECONDARY | TERRAIN_TYPE_NORMAL);
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
            tile->room = CORRIDOR_ROOM;
            break;
        case 8:
        case 67:
            SetTerrainNormal(tile);
            tile->spawnOrVisibilityFlags |= SPAWN_FLAG_STAIRS;
            tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
            tile->room = 0;
            gDungeon->stairsSpawn.x = x;
            gDungeon->stairsSpawn.y = y;
            break;
        case 68:
            tile->terrainType |= TERRAIN_TYPE_UNK_x800;
            SetTerrainNormal(tile);
            tile->spawnOrVisibilityFlags &= ~(SPAWN_FLAG_ITEM);
            tile->room = 0;
            break;
        case 9:
            SetTerrainNormal(tile);
            tile->room = CORRIDOR_ROOM;
            break;
        case 11:
            SetTerrainNormal(tile);
            tile->terrainType |= TERRAIN_TYPE_UNK_x800;
            tile->room = 0;
            break;
        case 12:
            SetTerrainNormal(tile);
            tile->terrainType |= TERRAIN_TYPE_UNK_x1000;
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
            tile->terrainType |= TERRAIN_TYPE_UNK_x800;
            tile->room = 0;
            break;
        case 2:
        case 13:
        case 14:
            SetTerrainWall(tile);
            tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
            tile->room = CORRIDOR_ROOM;
            break;
        default:
            if (fixedRoomActionId >= 16 && fixedRoomActionId <= 219) {
                const struct FixedRoomEntitiesInfo *ptr = &sFixedRoomEntities[fixedRoomActionId - 16];
                tile->room = ptr->roomId;
                if (ptr->itemId != 0) {
                    if (spawnTrapOrItem) {
                        SpawnItemAtPos(ptr->itemId, x, y, ptr->itemQuantity, ptr->unk4);
                    }
                    else {
                        gDungeon->unk644.unk47 = ptr->itemId;
                    }
                }
                else {
                    if (ptr->unk4 != 0) {
                        gDungeon->unkE220[ptr->unk4 - 1].x = x;
                        gDungeon->unkE220[ptr->unk4 - 1].y = y;
                    }
                }

                if (ptr->speciesId != 0) {
                    SpawnSpeciesAtPos(ptr->speciesId, x, y, ptr->monsterBehavior, fixedRoomActionId);
                }

                if (ptr->trapId != NUM_TRAPS && spawnTrapOrItem) {
                    SpawnEnemyTrapAtPos(ptr->trapId, x, y, ptr->trapVisible);
                }

                if (ptr->setTerrainToSecondary) {
                    SetTerrainSecondary(tile);
                }
            }
            break;
        case 3:
        case 15:
            break;
    }

    return FALSE;
}

void sub_8051E3C(void)
{
    s32 x, y;

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            Tile *tile = GetTileMut(x, y);
            if (tile->unkE > 0xF) {
                PlaceFixedRoomTile(tile, tile->unkE, x, y, FALSE);
            }
        }
    }
}

extern const u8 *const gUnknown_80FDDF0;
extern const u8 *const gUnknown_80FDDD0;

void sub_8051E7C(Entity *pokemon)
{
    Tile *tile = GetTileMut(pokemon->pos.x, pokemon->pos.y - 1);

    if (!(tile->terrainType & TERRAIN_TYPE_UNK_x1000)) {
        LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FDDF0); // It can't be used here!
    }
    else if (!gDungeon->unk3A09) {
        s32 x, y;
        DungeonPos pos = {pokemon->pos.x, pokemon->pos.y - 1};
        u32 roomId = GetEntityRoom(pokemon);

        for (y = pokemon->pos.y - 21; y <= pokemon->pos.y + 19; y++) {
            for (x = pokemon->pos.x -20; x <= pokemon->pos.x + 20; x++) {
                Tile *loopTile;
                s32 xDiff = x - gDungeon->unkE250.minX;
                s32 yDiff = y - gDungeon->unkE250.minY;

                if (xDiff < 0 || yDiff < 0)
                    continue;
                if (xDiff >= 8 || yDiff >= 8)
                    continue;
                if (x < gDungeon->unkE250.minX + 1 || y < gDungeon->unkE250.minY + 1)
                    continue;
                if (x >= gDungeon->unkE250.maxX - 1 || y >= gDungeon->unkE250.maxY - 1)
                    continue;

                loopTile = GetTileMut(x, y);
                if (loopTile->terrainType & TERRAIN_TYPE_UNBREAKABLE) {
                    loopTile->terrainType = gDungeon->unkE27C[xDiff][yDiff].terrainType;
                    loopTile->spawnOrVisibilityFlags = gDungeon->unkE27C[xDiff][yDiff].spawnOrVisibilityFlags;
                }

                PlaceFixedRoomTile(loopTile, gDungeon->unkE87C[xDiff][yDiff], x, y, TRUE);
                loopTile->spawnOrVisibilityFlags |= 3;
                if (roomId != CORRIDOR_ROOM) {
                    loopTile->room = roomId;
                }
            }
        }

        for (y = pokemon->pos.y - 21; y <= pokemon->pos.y + 19; y++) {
            for (x = pokemon->pos.x -20; x <= pokemon->pos.x + 20; x++) {
                s32 xDiff = x - gDungeon->unkE250.minX;
                s32 yDiff = y - gDungeon->unkE250.minY;

                if (xDiff < 0 || yDiff < 0)
                    continue;
                if (xDiff >= 8 || yDiff >= 8)
                    continue;
                if (x < gDungeon->unkE250.minX + 1 || y < gDungeon->unkE250.minY + 1)
                    continue;
                if (x >= gDungeon->unkE250.maxX - 1 || y >= gDungeon->unkE250.maxY - 1)
                    continue;

                sub_80498A8(x, y);
            }
        }

        gDungeon->unk3A09 = TRUE;
        tile->terrainType &= ~(TERRAIN_TYPE_IMPASSABLE_WALL | TERRAIN_TYPE_UNK_x1000);
        sub_80498A8(pokemon->pos.x, pokemon->pos.y - 1);
        sub_8049B8C();
        sub_8049ED4();
        sub_80429FC(&pos);
        LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FDDD0); // The closed corridor was opened!
        sub_803E708(0x14, 0x3C);
    }
    else {
        LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FDDF0); // It can't be used here!
    }
}

static inline bool8 MonHasItem(PokemonStruct1 *mon)
{
    return (mon->heldItem.id != 0);
}

static bool8 sub_805210C(u8 itemId)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (ItemExists(&gTeamInventoryRef->teamItems[i])) {
            if (gTeamInventoryRef->teamItems[i].id == itemId)
                return TRUE;
        }
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if (PokemonFlag1Struct2(&gRecruitedPokemonRef->pokemon2[i]) && ItemExists(&gRecruitedPokemonRef->pokemon2[i].itemSlot)) {
            if (gRecruitedPokemonRef->pokemon2[i].itemSlot.id == itemId)
                return TRUE;
        }
    }

    for (i = 0; i < NUM_MONSTERS; i++) {
        if (PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])) {
            if (MonHasItem(&gRecruitedPokemonRef->pokemon[i]) && gRecruitedPokemonRef->pokemon[i].heldItem.id == itemId)
                return TRUE;
        }
    }

    if (gTeamInventoryRef->teamStorage[itemId] != 0)
        return TRUE;

    return FALSE;
}
