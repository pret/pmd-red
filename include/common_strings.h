#ifndef GUARD_COMMON_STRINGS_H
#define GUARD_COMMON_STRINGS_H

enum FelicityBankMode
{
    FELICITY_BANK_MODE_AWAKE,
    FELICITY_BANK_MODE_ASLEEP,
    FELICITY_BANK_MODE_COUNT
};
enum KangaskhanStorageMode
{
    KANGASKHAN_STORAGE_MODE_AWAKE,
    KANGASKHAN_STORAGE_MODE_ASLEEP,
    KANGASKHAN_STORAGE_MODE_COUNT
};
enum KecleonBrosMode
{
    KECLEON_BROS_MODE_ITEMS_AWAKE,
    KECLEON_BROS_MODE_ITEMS_ASLEEP,
    KECLEON_BROS_MODE_WARES_AWAKE,
    KECLEON_BROS_MODE_WARES_ASLEEP,
    KECLEON_BROS_MODE_COUNT
};
enum WigglytuffShopMode
{
    WIGGLYTUFF_SHOP_MODE_AWAKE,
    WIGGLYTUFF_SHOP_MODE_ASLEEP,
    WIGGLYTUFF_SHOP_MODE_COUNT
};
enum GulpinShopMode
{
    GULPIN_SHOP_MODE_AWAKE,
    GULPIN_SHOP_MODE_ASLEEP,
    GULPIN_SHOP_MODE_COUNT
};
enum MakuhitaDojoMode
{
    MAKUHITA_DOJO_MODE_AWAKE,
    MAKUHITA_DOJO_MODE_ASLEEP,
    MAKUHITA_DOJO_MODE_COUNT
};

#define MAX_HINTS 5

// size: 0x8
typedef struct Hints
{
    const u8 *heading;
    const u8 *body;
} Hints;

extern const u8* const gCommonYes[];
extern const u8* const gCommonNo[];
extern const u8* const gCommonCancel[];
extern const u8* const gCommonTrash[];
extern const u8* const gCommonDelete[];
extern const u8* const gCommonStore[];
extern const u8* const gCommonTake[];
extern const u8* const gCommonInfo[];
extern const u8* const gCommonBuy[];
extern const u8* const gCommonSell[];
extern const u8* const gCommonAccept[];
extern const u8* const gCommonCheck[];
extern const u8* const gCommonFriend[];
extern const u8* const gCommonExit[];
extern const u8* const gCommonTripleQuestionMark[];
extern const u8* const gCommonDepositPrompt[];
extern const u8* const gCommonWithdrawPrompt[];

extern const u8 *gCommonFelicity[FELICITY_BANK_MODE_COUNT][15]; // 80D49E0
extern const u8 *gCommonKangaskhanStorage[KANGASKHAN_STORAGE_MODE_COUNT][20]; // 80D5404
extern const u8 *gCommonKecleonBros[KECLEON_BROS_MODE_COUNT][23]; // 80D5EC8
extern const u8 *gCommonWigglytuff[WIGGLYTUFF_SHOP_MODE_COUNT][20]; // 80D79A4
extern const u8 *gCommonGulpin[GULPIN_SHOP_MODE_COUNT][25]; // 80D8888
extern const u8 *gCommonMakuhita[MAKUHITA_DOJO_MODE_COUNT][10]; // 80D9FC8
extern const Hints gCommonHints[MAX_HINTS]; // 80DAA98

#endif // GUARD_COMMON_STRINGS_H