static const u8 sUnknown_80D54A4[];
static const u8 sUnknown_80D555C[];
static const u8 sUnknown_80D5590[];
static const u8 sUnknown_80D55C0[];
static const u8 sUnknown_80D55F4[];
static const u8 sUnknown_80D5630[];
static const u8 sUnknown_80D5670[];
static const u8 sUnknown_80D56AC[];
static const u8 sUnknown_80D56CC[];
static const u8 sUnknown_80D5710[];
static const u8 sUnknown_80D574C[];
static const u8 sUnknown_80D5774[];
static const u8 sUnknown_80D57C4[];
static const u8 sUnknown_80D57F4[];
static const u8 sUnknown_80D5844[];
static const u8 sUnknown_80D5884[];
static const u8 sUnknown_80D58B0[];
static const u8 sUnknown_80D5900[];
static const u8 sUnknown_80D5934[];
static const u8 sUnknown_80D5954[];
static const u8 sUnknown_80D5984[];
static const u8 sUnknown_80D5AF0[];
static const u8 sUnknown_80D5B24[];
static const u8 sUnknown_80D5B5C[];
static const u8 sUnknown_80D5BAC[];
static const u8 sUnknown_80D5BDC[];
static const u8 sUnknown_80D5C1C[];
static const u8 sUnknown_80D5C44[];
static const u8 sUnknown_80D5C74[];
static const u8 sUnknown_80D5CAC[];
static const u8 sUnknown_80D5CE4[];
static const u8 sUnknown_80D5D0C[];
static const u8 sUnknown_80D5D58[];
static const u8 sUnknown_80D5D8C[];
static const u8 sUnknown_80D5DBC[];
static const u8 sUnknown_80D5DE8[];
static const u8 sUnknown_80D5E10[];
static const u8 sUnknown_80D5E60[];
static const u8 sUnknown_80D5E84[];
static const u8 sUnknown_80D5E9C[];

ALIGNED(4) const u8* const gCommonKangStorage[KANG_MODE_COUNT][KANG_DLG_MAX] =
{
    [KANG_MODE_AWAKE] = {
        [KANG_DLG_WELCOME] = sUnknown_80D5E9C,
        [KANG_DLG_ANYTHING_ELSE] = sUnknown_80D5E84,
        [KANG_DLG_BYE] = sUnknown_80D5E60,
        [KANG_DLG_STORE_WHAT] = sUnknown_80D5E10,
        [KANG_DLG_STORE_MORE] = sUnknown_80D5DE8,
        [KANG_DLG_DEPOSIT_ONE_PROMPT] = sUnknown_80D5DBC,
        [KANG_DLG_DEPOSIT_MANY_PROMPT] = sUnknown_80D5D8C,
        [KANG_DLG_DEPOSIT_CONFIRMATION] = sUnknown_80D5D58,
        [KANG_DLG_TAKE_WHAT] = sUnknown_80D5D0C,
        [KANG_DLG_TAKE_MORE] = sUnknown_80D5CE4,
        [KANG_DLG_WITHDRAW_ONE_PROMPT] = sUnknown_80D5CAC,
        [KANG_DLG_WITHDRAW_MANY_PROMPT] = sUnknown_80D5C74,
        [KANG_DLG_WITHDRAW_CONFIRMATION] = sUnknown_80D5C44,
        [KANG_DLG_YOU_HAVE_NOTHING] = sUnknown_80D5C1C,
        [KANG_DLG_YOU_ARE_FULL] = sUnknown_80D5BDC,
        [KANG_DLG_STORAGE_HAS_NOTHING] = sUnknown_80D5BAC,
        [KANG_DLG_DEPOSIT__INVALID_ITEM] = sUnknown_80D5B5C,
        [KANG_DLG_DEPOSIT__TOO_MANY_OF_ITEM] = sUnknown_80D5B24,
        [KANG_DLG_STORAGE_FULL] = sUnknown_80D5AF0,
        [KANG_DLG_HOW_IT_WORKS] = sUnknown_80D5984
    },
    [KANG_MODE_ASLEEP] = {
        [KANG_DLG_WELCOME] = sUnknown_80D5954,
        [KANG_DLG_ANYTHING_ELSE] = sUnknown_80D5934,
        [KANG_DLG_BYE] = sUnknown_80D5900,
        [KANG_DLG_STORE_WHAT] = sUnknown_80D58B0,
        [KANG_DLG_STORE_MORE] = sUnknown_80D5884,
        [KANG_DLG_DEPOSIT_ONE_PROMPT] = sUnknown_80D5844,
        [KANG_DLG_DEPOSIT_MANY_PROMPT] = sUnknown_80D57F4,
        [KANG_DLG_DEPOSIT_CONFIRMATION] = sUnknown_80D57C4,
        [KANG_DLG_TAKE_WHAT] = sUnknown_80D5774,
        [KANG_DLG_TAKE_MORE] = sUnknown_80D574C,
        [KANG_DLG_WITHDRAW_ONE_PROMPT] = sUnknown_80D5710,
        [KANG_DLG_WITHDRAW_MANY_PROMPT] = sUnknown_80D56CC,
        [KANG_DLG_WITHDRAW_CONFIRMATION] = sUnknown_80D56AC,
        [KANG_DLG_YOU_HAVE_NOTHING] = sUnknown_80D5670,
        [KANG_DLG_YOU_ARE_FULL] = sUnknown_80D5630,
        [KANG_DLG_STORAGE_HAS_NOTHING] = sUnknown_80D55F4,
        [KANG_DLG_DEPOSIT__INVALID_ITEM] = sUnknown_80D55C0,
        [KANG_DLG_DEPOSIT__TOO_MANY_OF_ITEM] = sUnknown_80D5590,
        [KANG_DLG_STORAGE_FULL] = sUnknown_80D555C,
        [KANG_DLG_HOW_IT_WORKS] = sUnknown_80D54A4
    }
};

ALIGNED(4) static const u8 sUnknown_80D54A4[] = _(
    " Zzz... Snork!\n"
    "I can store items that you\n"
    "found in dungeons...{EXTRA_MSG}"
    " Snarfle...\n"
    "Things in storage don't get lost...{EXTRA_MSG}"
    " Zzz... Zzz...\n"
    "That's why...\n"
    "Keep important items in storage...");

ALIGNED(4) static const u8 sUnknown_80D555C[] = _(
    " Zzz... Zzz... No...\n"
    "The storage space is full...");

ALIGNED(4) static const u8 sUnknown_80D5590[] = _(
    " Zzz... No...\n"
    "Can't store any more of that...");

ALIGNED(4) static const u8 sUnknown_80D55C0[] = _(
    " Zzz... Zzz...\n"
    "That {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}...\n"
    "Can't store it...");

ALIGNED(4) static const u8 sUnknown_80D55F4[] = _(
    " Snarfle? Hunh...?{WAIT_PRESS}\n"
    "Zzz... Your storage space... Empty...");

ALIGNED(4) static const u8 sUnknown_80D5630[] = _(
    " Snarfle? Hunh...?{WAIT_PRESS}\n"
    "Zzz...\n"
    "You don't have enough space...");

ALIGNED(4) static const u8 sUnknown_80D5670[] = _(
    " Snarfle? Hunh...?{WAIT_PRESS}\n"
    "Zzz...\n"
    "You don't have anything...?");

ALIGNED(4) static const u8 sUnknown_80D56AC[] = _(
    " Zzz... Snork!\n"
    "There you go...");

ALIGNED(4) static const u8 sUnknown_80D56CC[] = _(
    " Zzz... Zzz... Hunh...?\n"
    "You want those things from storage...\n"
    "OK?");

ALIGNED(4) static const u8 sUnknown_80D5710[] = _(
    " Hunh...? Taking...?\n"
    "Oh... You want your {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}...\n"
    "OK?");

ALIGNED(4) static const u8 sUnknown_80D574C[] = _(
    " Snork! Zzz...\n"
    "Taking anything else?");

ALIGNED(4) static const u8 sUnknown_80D5774[] = _(
    " What...? Take out...?\n"
    "Uh-huh... Choose more than one using\n"
    "{L_BUTTON} or {R_BUTTON}... Zzz...");

ALIGNED(4) static const u8 sUnknown_80D57C4[] = _(
    " Zzz... Zzz...\n"
    "Yup, I did... Stored away...");

ALIGNED(4) static const u8 sUnknown_80D57F4[] = _(
    " Hunh, wha--? Storage...?\n"
    "I'll put away the things you chose...\n"
    "That OK?");

ALIGNED(4) static const u8 sUnknown_80D5844[] = _(
    " Zzz... Store something?\n"
    "Gonna put {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} in storage...\n"
    "OK?");

ALIGNED(4) static const u8 sUnknown_80D5884[] = _(
    " Do you... Snork...\n"
    "Store anything else?");

ALIGNED(4) static const u8 sUnknown_80D58B0[] = _(
    " Hunh, wha--? Store what...?\n"
    "You can choose more than one using\n"
    "{L_BUTTON} or {R_BUTTON}...");

ALIGNED(4) static const u8 sUnknown_80D5900[] = _(
    " Snuffle... Mutter...\n"
    "Thank you...\n"
    "Come again...");

ALIGNED(4) static const u8 sUnknown_80D5934[] = _(
    " Zzz... Snork...\n"
    "Anything else?");

ALIGNED(4) static const u8 sUnknown_80D5954[] = _(
    " Zzz... Zzz...\n"
    "Hello, there...\n"
    "{ARG_POKEMON_6} Storage...");

ALIGNED(4) static const u8 sUnknown_80D5984[] = _(
    " I can store items that you\n"
    "found in dungeons, or that you\n"
    "bought from shops.{EXTRA_MSG}"
    " If you faint in\n"
    "a dungeon, your items will be lost...{WAIT_PRESS}\n"
    "But what's in storage will be safe.{EXTRA_MSG}"
    " I keep guard over the\n"
    "storage space, so anything you leave\n"
    "with me won't ever disappear!{EXTRA_MSG}"
    " If you have any items that\n"
    "you can't bear to lose, be sure to leave\n"
    "them with me!");

ALIGNED(4) static const u8 sUnknown_80D5AF0[] = _(
    " Sorry, dear.\n"
    "I've run out of storage space.");

ALIGNED(4) static const u8 sUnknown_80D5B24[] = _(
    " Sorry, dear.\n"
    "I can't take any more of that item.");

ALIGNED(4) static const u8 sUnknown_80D5B5C[] = _(
    " Oh, dear, sorry.{WAIT_PRESS}\n"
    "That {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} is an item you\n"
    "can't put in storage.");

ALIGNED(4) static const u8 sUnknown_80D5BAC[] = _(
    " Oh?\n"
    "You don't have anything stored, dear.");

ALIGNED(4) static const u8 sUnknown_80D5BDC[] = _(
    " Oh? You don't have the room\n"
    "to carry any more items, dear.");

ALIGNED(4) static const u8 sUnknown_80D5C1C[] = _(
    " Oh?\n"
    "You don't seem to have anything?");

ALIGNED(4) static const u8 sUnknown_80D5C44[] = _(
    " There you go!\n"
    "Just like you asked, sweetie!");

ALIGNED(4) static const u8 sUnknown_80D5C74[] = _(
    " I'll take the items you\n"
    "chose out of storage. OK?");

ALIGNED(4) static const u8 sUnknown_80D5CAC[] = _(
    " Fine, I'll take your\n"
    "{COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} out of storage. OK?");

ALIGNED(4) static const u8 sUnknown_80D5CE4[] = _(
    " Would you like to take\n"
    "anything else?");

ALIGNED(4) static const u8 sUnknown_80D5D0C[] = _(
    " What will you take out?\n"
    "You can choose more than one item using\n"
    "{L_BUTTON} or {R_BUTTON}.");

ALIGNED(4) static const u8 sUnknown_80D5D58[] = _(
    " OK, stored away!\n"
    "You can count on me, honey.");

ALIGNED(4) static const u8 sUnknown_80D5D8C[] = _(
    " I'll put the items you chose\n"
    "in storage. OK?");

ALIGNED(4) static const u8 sUnknown_80D5DBC[] = _(
    " I'll put your\n"
    "{COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} in storage. OK?");

ALIGNED(4) static const u8 sUnknown_80D5DE8[] = _(
    " Do you want to store\n"
    "anything else?");

ALIGNED(4) static const u8 sUnknown_80D5E10[] = _(
    " What do you want to store?\n"
    "You can choose more than one item using\n"
    "{L_BUTTON} or {R_BUTTON}.");

ALIGNED(4) static const u8 sUnknown_80D5E60[] = _(
    " Thank you, sweetie.\n"
    "Come again!");

ALIGNED(4) static const u8 sUnknown_80D5E84[] = _(" Anything else, dear?");

ALIGNED(4) static const u8 sUnknown_80D5E9C[] = _(
    " Hello, there!\n"
    "Welcome to {ARG_POKEMON_6} Storage.");