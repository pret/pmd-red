#ifndef GUARD_COMMON_STRINGS_H
#define GUARD_COMMON_STRINGS_H

#include "constants/common_strings_felicity_bank.h"
#include "constants/common_strings_kangaskhan_storage.h"
#include "constants/common_strings_kecleon_bros.h"
#include "constants/common_strings_wigglytuff_shop.h"
#include "constants/common_strings_gulpin_shop.h"
#include "constants/common_strings_makuhita_dojo.h"
#include "constants/common_strings_hints.h"

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

extern const u8* const gCommonFelicity[FEL_MODE_COUNT][FEL_DLG_MAX];
extern const u8* const gCommonKangStorage[KANG_MODE_COUNT][KANG_DLG_MAX];
extern const u8* const gCommonKecleonBros[KECLEON_BROS_MODE_COUNT][KECLEON_DLG_MAX];
extern const u8* const gCommonWigglytuff[WIGGLYTUFF_SHOP_MODE_COUNT][WIGGLY_DLG_MAX];
extern const u8* const gCommonGulpin[GULPIN_SHOP_MODE_DIALOGUE_COUNT][GULPIN_DLG_MAX];
extern const u8* const gCommonMakuhita[MAKUHITA_DOJO_MODE_COUNT][MAKUHITA_DLG_MAX];
extern const Hints gCommonHints[HINT_MAX];

#endif // GUARD_COMMON_STRINGS_H