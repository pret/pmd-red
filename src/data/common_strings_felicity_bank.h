// TODO: The strings are in reverse-order if you insert them in-line with the array creation.
// Our preprocessor doesn't ALIGNED(4) for _("") strings. It does ALIGNED(1). This is why we do it this way for now until that's fixed

static const u8 sUnknown_80D4A58[];
static const u8 sUnknown_80D4C14[];
static const u8 sUnknown_80D4C50[];
static const u8 sUnknown_80D4CC0[];
static const u8 sUnknown_80D4D20[];
static const u8 sUnknown_80D4D44[];
static const u8 sUnknown_80D4D8C[];
static const u8 sUnknown_80D4E28[];
static const u8 sUnknown_80D4E84[];
static const u8 sUnknown_80D4EB0[];
static const u8 sUnknown_80D4EDC[];
static const u8 sUnknown_80D4F08[];
static const u8 sUnknown_80D4F24[];
static const u8 sUnknown_80D4F74[];
static const u8 sUnknown_80D4F94[];
static const u8 sUnknown_80D4FC8[];
static const u8 sUnknown_80D5158[];
static const u8 sUnknown_80D5184[];
static const u8 sUnknown_80D51DC[];
static const u8 sUnknown_80D5224[];
static const u8 sUnknown_80D5244[];
static const u8 sUnknown_80D527C[];
static const u8 sUnknown_80D52F8[];
static const u8 sUnknown_80D5340[];
static const u8 sUnknown_80D5364[];
static const u8 sUnknown_80D5380[];
static const u8 sUnknown_80D538C[];
static const u8 sUnknown_80D53C8[];
static const u8 sUnknown_80D53E0[];

ALIGNED(4) const u8* const gCommonFelicity[FEL_MODE_COUNT][FEL_DLG_MAX] =
{
    [FEL_MODE_AWAKE] = {
        [FEL_DLG_WELCOME] = sUnknown_80D53E0,
        [FEL_DLG_HOW_MAY_I_SERVE__NO_MONEY] = sUnknown_80D53C8,
        [FEL_DLG_HOW_MAY_I_SERVE__HAS_MONEY] = sUnknown_80D538C,
        [FEL_DLG_VERY_WELL] = sUnknown_80D5380,
        [FEL_DLG_BYE__NO_MONEY] = sUnknown_80D5364,
        [FEL_DLG_BYE__HAS_MONEY] = sUnknown_80D5364,
        [FEL_DLG_DEPOSIT__HOW_MUCH] = sUnknown_80D5340,
        [FEL_DLG_DEPOSIT__NO_MONEY] = sUnknown_80D52F8,
        [FEL_DLG_DEPOSIT__BANK_FULL] = sUnknown_80D527C,
        [FEL_DLG_DEPOSIT__RECEIPT] = sUnknown_80D5244,
        [FEL_DLG_WITHDRAW__HOW_MUCH] = sUnknown_80D5224,
        [FEL_DLG_WITHDRAW__NO_MONEY] = sUnknown_80D51DC,
        [FEL_DLG_WITHDRAW__WALLET_FULL] = sUnknown_80D5184,
        [FEL_DLG_WITHDRAW__RECEIPT] = sUnknown_80D5158,
        [FEL_DLG_HOW_IT_WORKS] = sUnknown_80D4FC8
    },
    [FEL_MODE_ASLEEP] = {
        [FEL_DLG_WELCOME] = sUnknown_80D4F94,
        [FEL_DLG_HOW_MAY_I_SERVE__NO_MONEY] = sUnknown_80D4F74,
        [FEL_DLG_HOW_MAY_I_SERVE__HAS_MONEY] = sUnknown_80D4F24,
        [FEL_DLG_VERY_WELL] = sUnknown_80D4F08,
        [FEL_DLG_BYE__NO_MONEY] = sUnknown_80D4EDC,
        [FEL_DLG_BYE__HAS_MONEY] = sUnknown_80D4EB0,
        [FEL_DLG_DEPOSIT__HOW_MUCH] = sUnknown_80D4E84,
        [FEL_DLG_DEPOSIT__NO_MONEY] = sUnknown_80D4E28,
        [FEL_DLG_DEPOSIT__BANK_FULL] = sUnknown_80D4D8C,
        [FEL_DLG_DEPOSIT__RECEIPT] = sUnknown_80D4D44,
        [FEL_DLG_WITHDRAW__HOW_MUCH] = sUnknown_80D4D20,
        [FEL_DLG_WITHDRAW__NO_MONEY] = sUnknown_80D4CC0,
        [FEL_DLG_WITHDRAW__WALLET_FULL] = sUnknown_80D4C50,
        [FEL_DLG_WITHDRAW__RECEIPT] = sUnknown_80D4C14,
        [FEL_DLG_HOW_IT_WORKS] = sUnknown_80D4A58
    }
};

ALIGNED(4) static const u8 sUnknown_80D4A58[] = _(
    " Sssnore...\n"
    "Ah, you wish to know how the bank\n"
    "operates... Very well...{EXTRA_MSG}"
    " Zzz...\n"
    "If you're defeated in a dungeon,\n"
    "you'll lose all your money. Did you know?{EXTRA_MSG}"
    " Purr...\n"
    "But, you've nothing to fear if you leave\n"
    "your money with Felicity Bank...{EXTRA_MSG}"
    " Meow... Even if you\n"
    "return defeated from a dungeon, your\n"
    "money will be safe with me...{EXTRA_MSG}"
    " Sssnore...\n"
    "I assure you, my bank will keep your\n"
    "money safe...{EXTRA_MSG}"
    " Zzz...\n"
    "Simple, isn't it...?");

ALIGNED(4) static const u8 sUnknown_80D4C14[] = _(
    " {POKE}... Purr...\n"
    "Very well, {COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}.\n"
    "Here you are.");

ALIGNED(4) static const u8 sUnknown_80D4C50[] = _(
    " Fnarf? Hunh...?{EXTRA_MSG}"
    " Purr... I so do apologize,\n"
    "but you couldn't possibly carry any more\n"
    "money with you...");

ALIGNED(4) static const u8 sUnknown_80D4CC0[] = _(
    " Fnarf? Meow...?{EXTRA_MSG}"
    " Purr...\n"
    "I so hate to disappoint, but you have no\n"
    "money saved with me...");

ALIGNED(4) static const u8 sUnknown_80D4D20[] = _(
    " Zzz...\n"
    "How much will you withdraw?");

ALIGNED(4) static const u8 sUnknown_80D4D44[] = _(
    " Zzz...\n"
    "{COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}... Very well...{WAIT_PRESS}\n"
    "I will guard it jealously...");

ALIGNED(4) static const u8 sUnknown_80D4D8C[] = _(
    " Fnarf? Purr...\n"
    "Meow! All this money...{WAIT_PRESS}\n"
    "Our safe is about to burst...{EXTRA_MSG}"
    " Purr...\n"
    "I am so sorry to say, but I can't accept\n"
    "any more of your money...");

ALIGNED(4) static const u8 sUnknown_80D4E28[] = _(
    " Sssnore... Hmm?{EXTRA_MSG}"
    " Zzz...\n"
    "I'm so sorry to say, but you appear not\n"
    "to have any money...");

ALIGNED(4) static const u8 sUnknown_80D4E84[] = _(
    " Purr...\n"
    "How much do you wish to deposit?");

ALIGNED(4) static const u8 sUnknown_80D4EB0[] = _(
    " Zzz... Meow...\n"
    "I await your next visit...");

ALIGNED(4) static const u8 sUnknown_80D4EDC[] = _(
    " Zzz... Purr...\n"
    "I await your next visit...");

ALIGNED(4) static const u8 sUnknown_80D4F08[] = _(
    " Sssnore...\n"
    "Very well...");

ALIGNED(4) static const u8 sUnknown_80D4F24[] = _(
    " Sssnore... Purr...\n"
    "Your account contains {COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}...\n"
    "How may I serve you?");

ALIGNED(4) static const u8 sUnknown_80D4F74[] = _(
    " Zzz...\n"
    "How may I serve you?");

ALIGNED(4) static const u8 sUnknown_80D4F94[] = _(
    " Ssssnore... Welcome...\n"
    "This is Felicity Bank...");

ALIGNED(4) static const u8 sUnknown_80D4FC8[] = _(
    " Ah, you wish to know how\n"
    "the bank operates. Very well.{EXTRA_MSG}"
    " If you are defeated\n"
    "in a dungeon, you'll lose all your money.\n"
    "Did you know that?{EXTRA_MSG}"
    " But you can avoid that!{WAIT_PRESS}\n"
    "You've nothing to fear if you leave your\n"
    "money with Felicity Bank.{EXTRA_MSG}"
    " Even if you return\n"
    "defeated from a dungeon, your money will\n"
    "be safe with me!{EXTRA_MSG}"
    " I assure you, my bank\n"
    "will keep your money safe.{EXTRA_MSG}"
    " Simple, isn't it?");

ALIGNED(4) static const u8 sUnknown_80D5158[] = _(
    " Very well, {COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}.\n"
    "Here you are.");

ALIGNED(4) static const u8 sUnknown_80D5184[] = _(
    " Oh?{WAIT_PRESS} I do so apologize,\n"
    "but you couldn't possibly carry any more\n"
    "money with you.");

ALIGNED(4) static const u8 sUnknown_80D51DC[] = _(
    " Oh?{WAIT_PRESS} I so hate to disappoint,\n"
    "but you have no money saved with me.");

ALIGNED(4) static const u8 sUnknown_80D5224[] = _(
    " How much will you\n"
    "withdraw?");

ALIGNED(4) static const u8 sUnknown_80D5244[] = _(
    " {COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}. Very well.{WAIT_PRESS}\n"
    "I will guard it jealously.");

ALIGNED(4) static const u8 sUnknown_80D527C[] = _(
    " Meow! All this money!{WAIT_PRESS}\n"
    "Our safe is about to burst!{EXTRA_MSG}"
    " I am so sorry to say, but\n"
    "I can't accept any more of your money!");

ALIGNED(4) static const u8 sUnknown_80D52F8[] = _(
    " Oh?{WAIT_PRESS} I'm so sorry to say,\n"
    "but you appear not to have any money.");

ALIGNED(4) static const u8 sUnknown_80D5340[] = _(
    " How much do you wish to\n"
    "deposit?");

ALIGNED(4) static const u8 sUnknown_80D5364[] = _(" I await your next visit.");

ALIGNED(4) static const u8 sUnknown_80D5380[] = _(" Very well.");

ALIGNED(4) static const u8 sUnknown_80D538C[] = _(
    " Your account contains\n"
    "{COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}.\n"
    "How may I serve you?");

ALIGNED(4) static const u8 sUnknown_80D53C8[] = _(" How may I serve you?");

ALIGNED(4) static const u8 sUnknown_80D53E0[] = _(
    " Welcome.\n"
    "This is Felicity Bank.");