static const u8 gUnknown_80D7A44[];
static const u8 gUnknown_80D7C94[];
static const u8 gUnknown_80D7CE8[];
static const u8 gUnknown_80D7D64[];
static const u8 gUnknown_80D7DA0[];
static const u8 gUnknown_80D7DE0[];
static const u8 gUnknown_80D7E04[];
static const u8 gUnknown_80D7E2C[];
static const u8 gUnknown_80D7E58[];
static const u8 gUnknown_80D7E9C[];
static const u8 gUnknown_80D7ED0[];
static const u8 gUnknown_80D7F10[];
static const u8 gUnknown_80D7F7C[];
static const u8 gUnknown_80D8000[];
static const u8 gUnknown_80D8030[];
static const u8 gUnknown_80D8054[];
static const u8 gUnknown_80D8080[];
static const u8 gUnknown_80D80B0[];
static const u8 gUnknown_80D80D4[];
static const u8 gUnknown_80D8104[];
static const u8 gUnknown_80D8420[];
static const u8 gUnknown_80D8468[];
static const u8 gUnknown_80D84F8[];
static const u8 gUnknown_80D8528[];
static const u8 gUnknown_80D8550[];
static const u8 gUnknown_80D8584[];
static const u8 gUnknown_80D85AC[];
static const u8 gUnknown_80D85E4[];
static const u8 gUnknown_80D8620[];
static const u8 gUnknown_80D8644[];
static const u8 gUnknown_80D8674[];
static const u8 gUnknown_80D86E4[];
static const u8 gUnknown_80D8738[];
static const u8 gUnknown_80D876C[];
static const u8 gUnknown_80D8798[];
static const u8 gUnknown_80D87E0[];
static const u8 gUnknown_80D8818[];
static const u8 gUnknown_80D883C[];

ALIGNED(4) const u8* const gCommonWigglytuff[WIGGLYTUFF_SHOP_MODE_COUNT][WIGGLY_DLG_MAX] =
{
    [WIGGLYTUFF_SHOP_MODE_AWAKE] = {
        [WIGGLY_DLG_00] = gUnknown_80D883C,
        [WIGGLY_DLG_01] = gUnknown_80D8818,
        [WIGGLY_DLG_02] = gUnknown_80D87E0,
        [WIGGLY_DLG_03] = gUnknown_80D8798,
        [WIGGLY_DLG_04] = gUnknown_80D876C,
        [WIGGLY_DLG_05] = gUnknown_80D8738,
        [WIGGLY_DLG_06] = gUnknown_80D86E4,
        [WIGGLY_DLG_07] = gUnknown_80D8674,
        [WIGGLY_DLG_08] = gUnknown_80D8644,
        [WIGGLY_DLG_09] = gUnknown_80D8620,
        [WIGGLY_DLG_10] = gUnknown_80D85E4,
        [WIGGLY_DLG_11] = gUnknown_80D85AC,
        [WIGGLY_DLG_12] = gUnknown_80D8584,
        [WIGGLY_DLG_13] = gUnknown_80D8550,
        [WIGGLY_DLG_14] = gUnknown_80D8528,
        [WIGGLY_DLG_15] = gUnknown_80D84F8,
        [WIGGLY_DLG_16] = gUnknown_80D8468,
        [WIGGLY_DLG_17] = gUnknown_80D8420,
        [WIGGLY_DLG_18] = gUnknown_80D8420,
        [WIGGLY_DLG_19] = gUnknown_80D8104
    },
    [WIGGLYTUFF_SHOP_MODE_ASLEEP] = {
        [WIGGLY_DLG_00] = gUnknown_80D80D4,
        [WIGGLY_DLG_01] = gUnknown_80D80B0,
        [WIGGLY_DLG_02] = gUnknown_80D8080,
        [WIGGLY_DLG_03] = gUnknown_80D8054,
        [WIGGLY_DLG_04] = gUnknown_80D8030,
        [WIGGLY_DLG_05] = gUnknown_80D8000,
        [WIGGLY_DLG_06] = gUnknown_80D7F7C,
        [WIGGLY_DLG_07] = gUnknown_80D7F10,
        [WIGGLY_DLG_08] = gUnknown_80D7ED0,
        [WIGGLY_DLG_09] = gUnknown_80D7E9C,
        [WIGGLY_DLG_10] = gUnknown_80D7E58,
        [WIGGLY_DLG_11] = gUnknown_80D7E2C,
        [WIGGLY_DLG_12] = gUnknown_80D7E04,
        [WIGGLY_DLG_13] = gUnknown_80D7DE0,
        [WIGGLY_DLG_14] = gUnknown_80D7DA0,
        [WIGGLY_DLG_15] = gUnknown_80D7D64,
        [WIGGLY_DLG_16] = gUnknown_80D7CE8,
        [WIGGLY_DLG_17] = gUnknown_80D7C94,
        [WIGGLY_DLG_18] = gUnknown_80D7C94,
        [WIGGLY_DLG_19] = gUnknown_80D7A44
    }
};

ALIGNED(4) static const u8 gUnknown_80D7A44[] = _(
    " Zzz...\n"
    "Want more friends?{EXTRA_MSG}"
    " Zzz... Kwoo...\n"
    "You need Friend Areas for friends...{EXTRA_MSG}"
    " Zzz... Zzz...\n"
    "A Pokémon becomes your pal when it{APOSTROPHE}s in\n"
    "the right Friend Area...{EXTRA_MSG}"
    " Zzz... Dwee...\n"
    "That{APOSTROPHE}s why you should get more Friend\n"
    "Areas...{EXTRA_MSG}"
    " Zzz... Pokémon can only\n"
    "live in the right Friend Area for\n"
    "their species...{EXTRA_MSG}"
    " Kwoo... Sssnore...\n"
    "See what Pokémon can live there by\n"
    "checking {COLOR_1 YELLOW}Info{END_COLOR_TEXT_1}...{EXTRA_MSG}"
    " Zzz...\n"
    "I don{APOSTROPHE}t sell some Friend Areas...{EXTRA_MSG}"
    " Kwoo...\n"
    "Some rescue missions reward you with\n"
    "Friend Areas...{EXTRA_MSG}"
    " Zzz... Dwee...\n"
    "Check the Pelipper Post Office{APOSTROPHE}s Bulletin\n"
    "Board or your Mailbox for missions...");

ALIGNED(4) static const u8 gUnknown_80D7C94[] = _(
    " Sssnore...\n"
    "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...?\n"
    "I can{APOSTROPHE}t get that Friend Area...{EXTRA_MSG}"
    " Zzz... Zzz...\n"
    "Sorry...");

ALIGNED(4) static const u8 gUnknown_80D7CE8[] = _(
    " Zzz... Hunh...?\n"
    "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...?\n"
    "I don{APOSTROPHE}t know... I{APOSTROPHE}ll check...{EXTRA_MSG}"
    " Sssnore...\n"
    "I{APOSTROPHE}ll have it for sale...\n"
    "When I find out...");

ALIGNED(4) static const u8 gUnknown_80D7D64[] = _(
    " Sssnore...\n"
    "You can already go...\n"
    "Friend Area {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...");

ALIGNED(4) static const u8 gUnknown_80D7DA0[] = _(
    " Dwee... Kwoo...\n"
    "{COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s Friend Area...\n"
    "Zzz... {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...");

ALIGNED(4) static const u8 gUnknown_80D7DE0[] = _(
    " Another Pokémon...\n"
    "Zzz... Check?");

ALIGNED(4) static const u8 gUnknown_80D7E04[] = _(
    " Zzz... Kwoo...\n"
    "Check which Pokémon?");

ALIGNED(4) static const u8 gUnknown_80D7E2C[] = _(
    " Zzz... Dwee...? Oops?{WAIT_PRESS}\n"
    "Not enough money?");

ALIGNED(4) static const u8 gUnknown_80D7E58[] = _(
    " Zzz... Hunh?{WAIT_PRESS}\n"
    "Sssnore... Sorry...\n"
    "Fresh out of Friend Areas...");

ALIGNED(4) static const u8 gUnknown_80D7E9C[] = _(
    " Hunh...?{WAIT_PRESS}\n"
    "You don{APOSTROPHE}t have any money...\n"
    "Zzzzzz...");

ALIGNED(4) static const u8 gUnknown_80D7ED0[] = _(
    " Zzz... Zzz?{WAIT_PRESS}\n"
    "Hunh...?\n"
    "You can{APOSTROPHE}t add to your Friend Areas...");

ALIGNED(4) static const u8 gUnknown_80D7F10[] = _(
    " Grats... Zzz...{WAIT_PRESS}\n"
    "You can go to {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...{EXTRA_MSG}"
    " Dwee... Sssnore...\n"
    "Make friends with Pokémon in...\n"
    "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...");

ALIGNED(4) static const u8 gUnknown_80D7F7C[] = _(
    " Zzz... Dwee... Gotcha...{WAIT_PRESS}\n"
    "Zzz... Let{APOSTROPHE}s do it...{EXTRA_MSG}"
    " Sssnore♪ Sssnore♪\n"
    "{ARG_POKEMON_6}〜♪ {ARG_POKEMON_6}〜♪\n"
    "Let{APOSTROPHE}s be friends...{EXTRA_MSG}"
    " Kwoo!\n"
    "Taaaaaaah!");

ALIGNED(4) static const u8 gUnknown_80D8000[] = _(
    " Kwoo? {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    "That{APOSTROPHE}s {COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}...\n"
    "OK?");

ALIGNED(4) static const u8 gUnknown_80D8030[] = _(
    " Zzz... Wha--?\n"
    "More Friend Areas?");

ALIGNED(4) static const u8 gUnknown_80D8054[] = _(
    " Dwee... Hunh?\n"
    "Friend Areas...?\n"
    "Which one?");

ALIGNED(4) static const u8 gUnknown_80D8080[] = _(
    " Thank... Zzz... You...\n"
    "Friends{COMMA} friend...");

ALIGNED(4) static const u8 gUnknown_80D80B0[] = _(
    " Anything? Kwoo...\n"
    "Anything else?");

ALIGNED(4) static const u8 gUnknown_80D80D4[] = _(
    " Friends... Zzz...\n"
    "Welcome to the {ARG_POKEMON_6} Club...");

ALIGNED(4) static const u8 gUnknown_80D8104[] = _(
    " Would you like to get more\n"
    "friends...{WAIT_PRESS}\n"
    "...More members for your team?{EXTRA_MSG}"
    " To add new friends{COMMA} what\n"
    "you need are Friend Areas.{EXTRA_MSG}"
    " A Pokémon can join your\n"
    "rescue team only after it settles in\n"
    "the right Friend Area.{EXTRA_MSG}"
    " So{COMMA} if you want to recruit\n"
    "new members{COMMA} you should add to your\n"
    "Friend Areas.{EXTRA_MSG}"
    " Oh{COMMA} yes{COMMA} Pokémon can\n"
    "only live in the right Friend Area for\n"
    "their species.{EXTRA_MSG}"
    " If you{APOSTROPHE}re buying a Friend\n"
    "Area{COMMA} you should confirm what Pokémon\n"
    "can live there by checking {COLOR_1 YELLOW}Info{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    " Also{COMMA} there are some Friend\n"
    "Areas that I don{APOSTROPHE}t sell.{EXTRA_MSG}"
    " I think there are some\n"
    "rescue missions that give you access\n"
    "to Friend Areas{COMMA} too.{EXTRA_MSG}"
    " You should check the\n"
    "Pelipper Post Office{APOSTROPHE}s Bulletin Board or\n"
    "your Mailbox for rescue requests.{EXTRA_MSG}"
    " You know{COMMA} it makes me\n"
    "delighted when you make new friends!");

ALIGNED(4) static const u8 gUnknown_80D8420[] = _(
    " {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    "I can{APOSTROPHE}t get that Friend Area for you.{WAIT_PRESS}\n"
    "I{APOSTROPHE}m really sorry.");

ALIGNED(4) static const u8 gUnknown_80D8468[] = _(
    " {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    "I don{APOSTROPHE}t know much about it at all.{WAIT_PRESS}\n"
    "I{APOSTROPHE}ll check up on it.{EXTRA_MSG}"
    " I{APOSTROPHE}ll add it to the Friend\n"
    "Areas you can buy when I find out more.");

ALIGNED(4) static const u8 gUnknown_80D84F8[] = _(
    " You can already go to the\n"
    "Friend Area {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 gUnknown_80D8528[] = _(
    " {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s Friend Area\n"
    "is {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 gUnknown_80D8550[] = _(
    " Is there another Pokémon\n"
    "you{APOSTROPHE}d like to check?");

ALIGNED(4) static const u8 gUnknown_80D8584[] = _(
    " Which Pokémon would you\n"
    "like to check?");

ALIGNED(4) static const u8 gUnknown_80D85AC[] = _(
    " Oops?{WAIT_PRESS}\n"
    "It doesn{APOSTROPHE}t look like you have enough\n"
    "money!");

ALIGNED(4) static const u8 gUnknown_80D85E4[] = _(
    " Oops?{WAIT_PRESS}\n"
    "Oh{COMMA} too bad.{WAIT_PRESS}\n"
    "I{APOSTROPHE}m fresh out of Friend Areas.");

ALIGNED(4) static const u8 gUnknown_80D8620[] = _(
    " Um?{WAIT_PRESS}\n"
    "You don{APOSTROPHE}t have any money.");

ALIGNED(4) static const u8 gUnknown_80D8644[] = _(
    " Oops!{WAIT_PRESS}\n"
    "You can{APOSTROPHE}t add to your Friend Areas.");

ALIGNED(4) static const u8 gUnknown_80D8674[] = _(
    " Congratulations!{WAIT_PRESS}\n"
    "You can go to {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1} now!{EXTRA_MSG}"
    " You can recruit\n"
    "Pokémon that live in the Friend Area\n"
    "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.");

ALIGNED(4) static const u8 gUnknown_80D86E4[] = _(
    " Gotcha! Let{APOSTROPHE}s do it!{WAIT_PRESS}\n"
    "{ARG_POKEMON_6}〜♪ {ARG_POKEMON_6}〜♪{WAIT_PRESS}\n"
    "Let{APOSTROPHE}s be friends... Yoomtaaaaaaah!");

ALIGNED(4) static const u8 gUnknown_80D8738[] = _(
    " {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    "That will be {COLOR_1 CYAN}{ARG_VALUE_0}{END_COLOR_TEXT_1} {POKE}.\n"
    "Is that OK?");

ALIGNED(4) static const u8 gUnknown_80D876C[] = _(
    " Would you like to add\n"
    "other Friend Areas?");

ALIGNED(4) static const u8 gUnknown_80D8798[] = _(
    " You{APOSTROPHE}d like to add to your\n"
    "Friend Areas?\n"
    "Which one would you like?");

ALIGNED(4) static const u8 gUnknown_80D87E0[] = _(
    " Thank you! Come again!\n"
    "We{APOSTROPHE}re all friends{COMMA} friend!");

ALIGNED(4) static const u8 gUnknown_80D8818[] = _(
    " Anything else I can do for\n"
    "you?");

ALIGNED(4) static const u8 gUnknown_80D883C[] = _(
    " Friends are my treasures!\n"
    "Welcome to the {ARG_POKEMON_6} Club--\n"
    "a circle of friends! ");