#ifndef GUARD_ITEMS_H
#define GUARD_ITEMS_H

#include "code_8092334.h"

struct Item
{
    /* 0x0 */ u8 *namePointer;
    /* 0x4 */ u32 buyPrice;
    /* 0x8 */ u32 sellPrice;
    /* 0xC */ u8 type;
    /* 0xD */ u8 icon;
    /* 0xE */ u16 fill;
    /* 0x10 */ u8 *descriptionPointer;
    /* 0x14 */ bool8 unkFood1[2];
    /* 0x16 */ u8 throwDmg;
    /* 0x17 */ u8 fill2;
    /* 0x18 */ s16 move;
    /* 0x1A */ u8 order; // Numbered order they are in storage
    /* 0x1B */ u8 unkThrow1B[2];
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 category;
    /* 0x1F */ u8 fill3;
};

struct ItemSlot
{
    u8 unk0;  // some sort of flags, bit 0 seems to indicate an empty slot
    u8 numItems;
    u8 itemIndex;
};

struct HeldItem {
  u8 itemIndex;
  u8 numItems;
};

struct unkStruct_80915F4
{
    u16 unk0;
    u16 unk2;
};

struct unkStruct_8090F58
{
    u32 unk0;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    u8 unk8;
};

enum ItemType
{
    ITEM_TYPE_THROWABLE,
    ITEM_TYPE_ROCK,
    ITEM_TYPE_BERRY_SEED,
    ITEM_TYPE_APPLE_GUMMI,
    ITEM_TYPE_HOLD_ITEM,
    ITEM_TYPE_TM,
    ITEM_TYPE_MONEY,
    ITEM_TYPE_UNUSED,
    ITEM_TYPE_MISC,
    ITEM_TYPE_ORB,
    ITEM_TYPE_LINK_BOX,
    ITEM_TYPE_USED_TM
};

enum ItemCategory
{
    ITEM_CATEGORY_NOTHING,
    ITEM_CATEGORY_THROWABLE,
    ITEM_CATEGORY_ROCKS,
    ITEM_CATEGORY_RIBBONS,
    ITEM_CATEGORY_FOOD,
    ITEM_CATEGORY_HEALING,
    ITEM_CATEGORY_CHESTNUT,
    ITEM_CATEGORY_MONEY_WISH_STONE,
    ITEM_CATEGORY_MISC,
    ITEM_CATEGORY_TM,
    ITEM_CATEGORY_LINK_BOX,
    ITEM_CATEGORY_SPECS,
    ITEM_CATEGORY_SCARFS,
    ITEM_CATEGORY_ORBS
};

// see https://bulbapedia.bulbagarden.net/wiki/List_of_items_by_index_number_(Rescue_Team)
enum ItemID {
    ITEM_ID_NOTHING,
    ITEM_ID_STICK,
    ITEM_ID_IRON_THORN,
    ITEM_ID_SILVER_SPIKE,
    ITEM_ID_GOLD_FANG,
    ITEM_ID_CACNEA_SPIKE,
    ITEM_ID_CORSOLA_TWIG,
    ITEM_ID_GRAVELEROCK,
    ITEM_ID_GEO_PEBBLE,
    ITEM_ID_MOBILE_SCARF,
    ITEM_ID_HEAL_RIBBON,
    ITEM_ID_TWIST_BAND,
    ITEM_ID_SCOPE_LENS,
    ITEM_ID_PATSY_BAND,
    ITEM_ID_NOSTICK_CAP,
    ITEM_ID_PIERCE_BAND,
    ITEM_ID_JOY_RIBBON,
    ITEM_ID_X_RAY_SPECS,
    ITEM_ID_PERSIM_BAND,
    ITEM_ID_POWER_BAND,
    ITEM_ID_PECHA_SCARF,
    ITEM_ID_INSOMNISCOPE,
    ITEM_ID_WARP_SCARF,
    ITEM_ID_TIGHT_BELT,
    ITEM_ID_SNEAK_SCARF,
    ITEM_ID_GOLD_RIBBON,
    ITEM_ID_GOGGLE_SPECS,
    ITEM_ID_DIET_RIBBON,
    ITEM_ID_TRAP_SCARF,
    ITEM_ID_RACKET_BAND,
    ITEM_ID_DEF_SCARF,
    ITEM_ID_STAMINA_BAND,
    ITEM_ID_PLAIN_RIBBON,
    ITEM_ID_SPECIAL_BAND,
    ITEM_ID_ZINC_BAND,
    ITEM_ID_DETECT_BAND,
    ITEM_ID_ALERT_SPECS,
    ITEM_ID_DODGE_SCARF,
    ITEM_ID_BOUNCE_BAND,
    ITEM_ID_CURVE_BAND,
    ITEM_ID_WHIFF_SPECS,
    ITEM_ID_NO_AIM_SCOPE,
    ITEM_ID_LOCKON_SPECS,
    ITEM_ID_MUNCH_BELT,
    ITEM_ID_PASS_SCARF,
    ITEM_ID_WEATHER_BAND,
    ITEM_ID_FRIEND_BOW,
    ITEM_ID_BEAUTY_SCARF,
    ITEM_ID_SUN_RIBBON,
    ITEM_ID_LUNAR_RIBBON,
    ITEM_ID_RING_D,
    ITEM_ID_RING_E,
    ITEM_ID_RING_F,
    ITEM_ID_HEAL_SEED,
    ITEM_ID_WISH_STONE,
    ITEM_ID_ORAN_BERRY,
    ITEM_ID_SITRUS_BERRY,
    ITEM_ID_EYEDROP_SEED,
    ITEM_ID_REVIVER_SEED,
    ITEM_ID_BLINKER_SEED,
    ITEM_ID_DOOM_SEED,
    ITEM_ID_ALLURE_SEED,
    ITEM_ID_LIFE_SEED,
    ITEM_ID_RAWST_BERRY,
    ITEM_ID_HUNGER_SEED,
    ITEM_ID_QUICK_SEED,
    ITEM_ID_PECHA_BERRY,
    ITEM_ID_CHERI_BERRY,
    ITEM_ID_TOTTER_SEED,
    ITEM_ID_SLEEP_SEED,
    ITEM_ID_PLAIN_SEED,
    ITEM_ID_WARP_SEED,
    ITEM_ID_BLAST_SEED,
    ITEM_ID_GINSENG,
    ITEM_ID_JOY_SEED,
    ITEM_ID_CHESTO_BERRY,
    ITEM_ID_STUN_SEED,
    ITEM_ID_MAX_ELIXIR,
    ITEM_ID_PROTEIN,
    ITEM_ID_CALCIUM,
    ITEM_ID_IRON,
    ITEM_ID_ZINC,
    ITEM_ID_APPLE,
    ITEM_ID_BIG_APPLE,
    ITEM_ID_GRIMY_FOOD,
    ITEM_ID_HUGE_APPLE,
    ITEM_ID_WHITE_GUMMI,
    ITEM_ID_RED_GUMMI,
    ITEM_ID_BLUE_GUMMI,
    ITEM_ID_GRASS_GUMMI,
    ITEM_ID_YELLOW_GUMMI,
    ITEM_ID_CLEAR_GUMMI,
    ITEM_ID_ORANGE_GUMMI,
    ITEM_ID_PINK_GUMMI,
    ITEM_ID_BROWN_GUMMI,
    ITEM_ID_SKY_GUMMI,
    ITEM_ID_GOLD_GUMMI,
    ITEM_ID_GREEN_GUMMI,
    ITEM_ID_GRAY_GUMMI,
    ITEM_ID_PURPLE_GUMMI,
    ITEM_ID_ROYAL_GUMMI,
    ITEM_ID_BLACK_GUMMI,
    ITEM_ID_SILVER_GUMMI,
    ITEM_ID_BANANA,
    ITEM_ID_CHESTNUT,
    ITEM_ID_POKE,  // 105 (0x69)
    ITEM_ID_UPGRADE,
    ITEM_ID_KINGS_ROCK,
    ITEM_ID_THUNDERSTONE,
    ITEM_ID_DEEPSEASCALE,
    ITEM_ID_DEEPSEATOOTH,
    ITEM_ID_SUN_STONE,
    ITEM_ID_MOON_STONE,
    ITEM_ID_FIRE_STONE,
    ITEM_ID_WATER_STONE,
    ITEM_ID_METAL_COAT,
    ITEM_ID_LEAF_STONE,
    ITEM_ID_DRAGON_SCALE,
    ITEM_ID_LINK_CABLE,
    ITEM_ID_ICE_PART,
    ITEM_ID_STEEL_PART,
    ITEM_ID_ROCK_PART,
    ITEM_ID_MUSIC_BOX,
    ITEM_ID_KEY,
    ITEM_ID_USED_TM,
    ITEM_ID_FOCUS_PUNCH,
    ITEM_ID_DRAGON_CLAW,
    ITEM_ID_WATER_PULSE,
    ITEM_ID_CALM_MIND,
    ITEM_ID_ROAR,
    ITEM_ID_TOXIC,
    ITEM_ID_HAIL_ORB,
    ITEM_ID_BULK_UP,
    ITEM_ID_BULLET_SEED,
    ITEM_ID_HIDDEN_POWER,
    ITEM_ID_SUNNY_ORB,
    ITEM_ID_TAUNT,
    ITEM_ID_ICE_BEAM,
    ITEM_ID_BLIZZARD,
    ITEM_ID_HYPER_BEAM,
    ITEM_ID_LIGHT_SCREEN,
    ITEM_ID_PROTECT,
    ITEM_ID_RAINY_ORB,
    ITEM_ID_GIGA_DRAIN,
    ITEM_ID_SAFEGUARD,
    ITEM_ID_FRUSTRATION,
    ITEM_ID_SOLARBEAM,
    ITEM_ID_IRON_TAIL,
    ITEM_ID_THUNDERBOLT,
    ITEM_ID_THUNDER,
    ITEM_ID_EARTHQUAKE,
    ITEM_ID_RETURN,
    ITEM_ID_DIG,
    ITEM_ID_PSYCHIC,
    ITEM_ID_SHADOW_BALL,
    ITEM_ID_BRICK_BREAK,
    ITEM_ID_EVASION_ORB,
    ITEM_ID_REFLECT,
    ITEM_ID_SHOCK_WAVE,
    ITEM_ID_FLAMETHROWER,
    ITEM_ID_SLUDGE_BOMB,
    ITEM_ID_SANDY_ORB,
    ITEM_ID_FIRE_BLAST,
    ITEM_ID_ROCKY_ORB,
    ITEM_ID_AERIAL_ACE,
    ITEM_ID_TORMENT,
    ITEM_ID_FACADE,
    ITEM_ID_SECRET_POWER,
    ITEM_ID_REST,
    ITEM_ID_ATTRACT,
    ITEM_ID_THIEF,
    ITEM_ID_STEEL_WING,
    ITEM_ID_SKILL_SWAP,
    ITEM_ID_SNATCH_ORB,
    ITEM_ID_OVERHEAT,
    ITEM_ID_WIDE_SLASH,
    ITEM_ID_EXCAVATE,
    ITEM_ID_SPIN_SLASH,
    ITEM_ID_SEE_TRAP_ORB,
    ITEM_ID_MUG_ORB,
    ITEM_ID_REBOUND_ORB,
    ITEM_ID_LOB_ORB,
    ITEM_ID_SWITCHER_ORB,
    ITEM_ID_BLOWBACK_ORB,
    ITEM_ID_WARP_ORB,
    ITEM_ID_TRANSFER_ORB,
    ITEM_ID_SLOW_ORB,
    ITEM_ID_QUICK_ORB,
    ITEM_ID_LUMINOUS_ORB,
    ITEM_ID_PETRIFY_ORB,
    ITEM_ID_STAYAWAY_ORB,
    ITEM_ID_POUNCE_ORB,
    ITEM_ID_TRAWL_ORB,
    ITEM_ID_CLEANSE_ORB,
    ITEM_ID_OBSERVER_ORB,
    ITEM_ID_DECOY_ORB,
    ITEM_ID_SLUMBER_ORB,
    ITEM_ID_TOTTER_ORB,
    ITEM_ID_TWO_EDGE_ORB,
    ITEM_ID_SILENCE_ORB,
    ITEM_ID_ESCAPE_ORB,
    ITEM_ID_SCANNER_ORB,
    ITEM_ID_RADAR_ORB,
    ITEM_ID_DROUGHT_ORB,
    ITEM_ID_TRAPBUST_ORB,
    ITEM_ID_ROLLCALL_ORB,
    ITEM_ID_INVISIFY_ORB,
    ITEM_ID_ONE_SHOT_ORB,
    ITEM_ID_IDENTIFY_ORB,
    ITEM_ID_VACUUM_CUT,
    ITEM_ID_REVIVER_ORB,
    ITEM_ID_SHOCKER_ORB,
    ITEM_ID_SIZEBUST_ORB,
    ITEM_ID_ONE_ROOM_ORB,
    ITEM_ID_FILL_IN_ORB,
    ITEM_ID_TRAPPER_ORB,
    ITEM_ID_POSSESS_ORB,
    ITEM_ID_ITEMIZER_ORB,
    ITEM_ID_HURL_ORB,
    ITEM_ID_MOBILE_ORB,
    ITEM_ID_TOSS_ORB,
    ITEM_ID_STAIRS_ORB,
    ITEM_ID_LONGTOSS_ORB,
    ITEM_ID_PIERCE_ORB,
    ITEM_ID_CUT,
    ITEM_ID_FLY,
    ITEM_ID_SURF,
    ITEM_ID_STRENGTH,
    ITEM_ID_FLASH,
    ITEM_ID_ROCK_SMASH,
    ITEM_ID_WATERFALL,
    ITEM_ID_DIVE,
    ITEM_ID_LINK_BOX,
    ITEM_ID_SWITCH_BOX,
    ITEM_ID_WEAVILE_FIG,
    ITEM_ID_MIME_JR_FIG,
    ITEM_ID_BEATUP_ORB,
    ITEM_ID_G_MACHINE_6,
    ITEM_ID_G_MACHINE_7,
    ITEM_ID_G_MACHINE_8,
    NUMBER_OF_ITEM_IDS
};

#define NUMBER_OF_GUMMIS 18
#define INVENTORY_SIZE 20

void LoadItemParameters(void);
struct TeamInventory *GetMoneyItemsInfo(void);
void InitializeMoneyItems(void);
u8 GetItemType(u8 index);
s32 GetItemBuyPrice(u8 itemIndex);
s32 GetItemSellPrice(u8 itemIndex);
s32 GetItemOrder(u8 itemIndex);
u8 GetItemPalette(u8 itemIndex);
u8 GetItemCategory(u8 itemIndex);
u32 GetItemUnkThrow(u8 itemIndex, u32 r1);
u8 *GetItemDescription(u8 itemIndex);
u32 GetItemUnkFood(u8 itemIndex, u32 r1);
s32 GetNumberOfFilledInventorySlots(void);
bool8 IsThrowableItem(u8 itemIndex);
void xxx_init_itemslot_8090A8C(struct ItemSlot *param_1,u8 itemIndex,u8 param_3);
void xxx_init_helditem_8090B08(struct HeldItem *param_1,u8 itemIndex);
void HeldItemToSlot(struct ItemSlot *param_1, struct HeldItem *param_2);
void sub_8090DC4(void* param_1,u8 itemIndex, struct unkStruct_8090F58* param_3);
bool8 AddItemToInventory(const struct ItemSlot* slot);
void ConvertMoneyItemToMoney();
void AddToTeamMoney(s32 amount);
u32 GetMoneyValue(struct ItemSlot* slot);
u16 GetItemMove(u8 index);
bool8 CanSellItem(u32 id);
bool8 IsGummiItem(u8);
void xxx_init_unk230_substruct(u8);
bool8 xxx_insert_unk230_80919FC(u8);
u32 xxx_count_non_empty_inv_unk250_8091A48();
void sub_8091BB4(u8);
void sub_8090F58(void*, u8 *, struct ItemSlot *, struct unkStruct_8090F58*);

// some sort of weird memcpy's?
// not sure what the second argument should be typed as
void sub_8091DC0(struct unkStruct_8094924 *r0, u8*);
void sub_8091DE0(struct unkStruct_8094924 *a1, u8 *a2);
void sub_8091E00(struct unkStruct_8094924 *a1, u8 *a2);
void sub_8091E28(struct unkStruct_8094924 *a1, u8 *a2);

#endif
