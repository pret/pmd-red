#ifndef GUARD_COMMON_STRINGS_H
#define GUARD_COMMON_STRINGS_H

enum KecleonBrosMode
{
    KECLEON_BROS_MODE_ITEMS_AWAKE,
    KECLEON_BROS_MODE_ITEMS_ASLEEP,
    KECLEON_BROS_MODE_WARES_AWAKE,
    KECLEON_BROS_MODE_WARES_ASLEEP,
    KECLEON_BROS_MODE_COUNT
};

#define MAX_HINTS 5

// size: 0x8
typedef struct Hints
{
    const u8 *heading;
    const u8 *body;
} Hints;

extern const u8 *gCommonYes[]; // 80D4920
extern const u8 *gCommonNo[]; // 80D4928
extern const u8 *gCommonCancel[]; // 80D4934
extern const u8 *gCommonTrash[]; // 80D4940
extern const u8 *gCommonDelete[]; // 80D494C
extern const u8 *gCommonStore[]; // 80D4958
extern const u8 *gCommonTake[]; // 80D4964
extern const u8 *gCommonInfo[]; // 80D4970
extern const u8 *gCommonBuy[]; // 80D4978
extern const u8 *gCommonSell[]; // 80D4984
extern const u8 *gCommonAccept[]; // 80D4990
extern const u8 *gCommonCheck[]; // 80D499C
extern const u8 *gCommonFriend[]; // 80D49A8
extern const u8 *gCommonExit[]; // 80D49B4
extern const u8 *gCommonTripleQuestionMark[]; // 80D49BC
extern const u8 *gCommonDepositPrompt[]; // 80D49CC
extern const u8 *gCommonWithdrawPrompt[]; // 80D49DC

extern const u8 *gCommonFelicity[2][15]; // 80D49E0
extern const u8 *gCommonKangaskhanStorage[2][20]; // 80D5404
extern const u8 *gCommonKecleonBros[KECLEON_BROS_MODE_COUNT][23]; // 80D5EC8
extern const u8 *gCommonWigglytuff[2][20]; // 80D79A4
extern const u8 *gCommonGulpin[2][25]; // 80D8888
extern const u8 *gCommonMakuhita[2][10]; // 80D9FC8
extern const Hints gCommonHints[MAX_HINTS]; // 80DAA98

#endif // GUARD_COMMON_STRINGS_H