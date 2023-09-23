#include "global.h"
#include "common_strings.h"

ALIGNED(4) static const u8 sFill[] = _("pksdir0");

// Probably had many entries per ptr because of languages, but USA release is english-only. Check other roms

ALIGNED(4) static const u8 sYes0[] = _("Yes");
ALIGNED(4) const u8* const gCommonYes[] = { sYes0 };

ALIGNED(4) static const u8 sNo0[] = _("No");
ALIGNED(4) const u8* const gCommonNo[] = { sNo0 };

ALIGNED(4) static const u8 sCancel0[] = _("Cancel");
ALIGNED(4) const u8* const gCommonCancel[] = { sCancel0 };

ALIGNED(4) static const u8 sTrash0[] = _("Trash ");
ALIGNED(4) const u8* const gCommonTrash[] = { sTrash0 };

ALIGNED(4) static const u8 sDelete0[] = _("Delete");
ALIGNED(4) const u8* const gCommonDelete[] = { sDelete0 };

ALIGNED(4) static const u8 sStore0[] = _("Store");
ALIGNED(4) const u8* const gCommonStore[] = { sStore0 };

ALIGNED(4) static const u8 sTake0[] = _("Take");
ALIGNED(4) const u8* const gCommonTake[] = { sTake0 };

ALIGNED(4) static const u8 sInfo0[] = _("Info");
ALIGNED(4) const u8* const gCommonInfo[] = { sInfo0 };

ALIGNED(4) static const u8 sBuy0[] = _("Buy");
ALIGNED(4) const u8* const gCommonBuy[] = { sBuy0 };

ALIGNED(4) static const u8 sSell0[] = _("Sell ");
ALIGNED(4) const u8* const gCommonSell[] = { sSell0 };

ALIGNED(4) static const u8 sAccept0[] = _("Accept");
ALIGNED(4) const u8* const gCommonAccept[] = { sAccept0 };

ALIGNED(4) static const u8 sCheck0[] = _("Check");
ALIGNED(4) const u8* const gCommonCheck[] = { sCheck0 };

ALIGNED(4) static const u8 sFriend0[] = _("Friend");
ALIGNED(4) const u8* const gCommonFriend[] = { sFriend0 };

ALIGNED(4) static const u8 sExit0[] = _("Exit");
ALIGNED(4) const u8* const gCommonExit[] = { sExit0 };

ALIGNED(4) static const u8 sTripleQuestionMark0[] = _("???");
ALIGNED(4) const u8* const gCommonTripleQuestionMark[] = { sTripleQuestionMark0 };

ALIGNED(4) static const u8 sDepositPrompt0[] = _("Deposit?");
ALIGNED(4) const u8* const gCommonDepositPrompt[] = { sDepositPrompt0 };

ALIGNED(4) static const u8 sWithdrawPrompt0[] = _("Withdraw?");
ALIGNED(4) const u8* const gCommonWithdrawPrompt[] = { sWithdrawPrompt0 };

// TODO: Move remaining strings/arrays from common_strings.s

#include "data/common_strings_felicity_bank.h"
#include "data/common_strings_kangaskhan_storage.h"
#include "data/common_strings_kecleon_bros.h"
#include "data/common_strings_wigglytuff_shop.h"