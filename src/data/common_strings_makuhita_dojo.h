static const u8 sUnknown_80DA018[];
static const u8 sUnknown_80DA0DC[];
static const u8 sUnknown_80DA100[];
static const u8 sUnknown_80DA204[];
static const u8 sUnknown_80DA248[];
static const u8 sUnknown_80DA290[];
static const u8 sUnknown_80DA2B4[];
static const u8 sUnknown_80DA2D4[];
static const u8 sUnknown_80DA2F0[];
static const u8 sUnknown_80DA30C[];
static const u8 sUnknown_80DA338[];
static const u8 sUnknown_80DA62C[];
static const u8 sUnknown_80DA688[];
static const u8 sUnknown_80DA844[];
static const u8 sUnknown_80DA908[];
static const u8 sUnknown_80DA998[];
static const u8 sUnknown_80DA9D4[];
static const u8 sUnknown_80DA9F4[];
static const u8 sUnknown_80DAA2C[];
static const u8 sUnknown_80DAA44[];

ALIGNED(4) const u8* const gCommonMakuhita[MAKUHITA_DOJO_MODE_COUNT][MAKUHITA_DLG_MAX] =
{
    [MAKUHITA_DOJO_MODE_AWAKE] = {
        [MAKUHITA_DLG_0] = sUnknown_80DAA44,
        [MAKUHITA_DLG_1] = sUnknown_80DAA2C,
        [MAKUHITA_DLG_2] = sUnknown_80DA9F4,
        [MAKUHITA_DLG_3] = sUnknown_80DA9D4,
        [MAKUHITA_DLG_4] = sUnknown_80DA998,
        [MAKUHITA_DLG_5] = sUnknown_80DA908,
        [MAKUHITA_DLG_6] = sUnknown_80DA844,
        [MAKUHITA_DLG_7] = sUnknown_80DA688,
        [MAKUHITA_DLG_8] = sUnknown_80DA62C,
        [MAKUHITA_DLG_9] = sUnknown_80DA338
    },
    [MAKUHITA_DOJO_MODE_ASLEEP] = {
        [MAKUHITA_DLG_0] = sUnknown_80DA30C,
        [MAKUHITA_DLG_1] = sUnknown_80DA2F0,
        [MAKUHITA_DLG_2] = sUnknown_80DA2D4,
        [MAKUHITA_DLG_3] = sUnknown_80DA2B4,
        [MAKUHITA_DLG_4] = sUnknown_80DA290,
        [MAKUHITA_DLG_5] = sUnknown_80DA248,
        [MAKUHITA_DLG_6] = sUnknown_80DA204,
        [MAKUHITA_DLG_7] = sUnknown_80DA100,
        [MAKUHITA_DLG_8] = sUnknown_80DA0DC,
        [MAKUHITA_DLG_9] = sUnknown_80DA018
    }
};

ALIGNED(4) static const u8 sUnknown_80DA018[] = _(
    " Zzznarr... Zzz...\n"
    "This dojo...\n"
    "Help rescue teams...{EXTRA_MSG}"
    " Zzznarr... Urr...\n"
    "Train in different rooms to level up...{EXTRA_MSG}"
    " Zzznarr... Urr!\n"
    "Make stronger rescue team...{EXTRA_MSG}"
    " Urr... Zzznarr!\n"
    "Don't let up!");

ALIGNED(4) static const u8 sUnknown_80DA0DC[] = _(
    " Zzznarr... Zzz...!\n"
    "Keep working...");

ALIGNED(4) static const u8 sUnknown_80DA100[] = _(
    " Ah... Zzznarr...\n"
    "Cleared it...{EXTRA_MSG}"
    " Zzzznarr... Urr...\n"
    "Good going... Keep going...{WAIT_PRESS}\n"
    "Hunh...{WAIT_PRESS} ...{EXTRA_MSG}"
    " Gwoh?{WAIT_PRESS}\n"
    "Gwogwogwoh?{EXTRA_MSG}"
    " Mugawah?\n"
    "Cleared everything?{EXTRA_MSG}"
    " Zzznarr!\n"
    "Congrazzz...{EXTRA_MSG}"
    " Zzznarr... Zzznarr...\n"
    "Your reward...\n"
    "Promised...{EXTRA_MSG}"
    " Zzz... Urr!\n"
    "{COLOR_1 GREEN_2}Bonsly Doll{END_COLOR_TEXT_1}...");

ALIGNED(4) static const u8 sUnknown_80DA204[] = _(
    " Ah... Zzznarr...\n"
    "Cleared it...{EXTRA_MSG}"
    " Congrazzz...\n"
    "Keep going... Zzz...");

ALIGNED(4) static const u8 sUnknown_80DA248[] = _(
    " Aiyah... Zzznarr...\n"
    "Didn't finish...{EXTRA_MSG}"
    " Zzz... Urr?\n"
    "No giving up...");

ALIGNED(4) static const u8 sUnknown_80DA290[] = _(
    " Zzz... Narr...\n"
    "{ARG_POKEMON_0}? 'K, go...");

ALIGNED(4) static const u8 sUnknown_80DA2B4[] = _(
    " Zzznarr... Zzz...\n"
    "Train where?");

ALIGNED(4) static const u8 sUnknown_80DA2D4[] = _(
    " Urr... Narr...\n"
    "See you...");

ALIGNED(4) static const u8 sUnknown_80DA2F0[] = _(
    " Zzznarr... Urr?\n"
    "What else?");

ALIGNED(4) static const u8 sUnknown_80DA30C[] = _(
    " Zzznarr... Zzznarr...\n"
    "Makuhita... Dojo...");

ALIGNED(4) static const u8 sUnknown_80DA338[] = _(
    " This dojo was founded to\n"
    "support the efforts of rescue teams.{EXTRA_MSG}"
    " Train in different rooms to\n"
    "level up...{WAIT_PRESS}\n"
    "And toughen up your rescue team.{EXTRA_MSG}"
    " Also...{WAIT_PRESS}\n"
    "In the {COLOR_1 YELLOW_4}Fire Maze{END_COLOR_TEXT_1} you will find only\n"
    "Fire-type Pokémon.{EXTRA_MSG}"
    " In the {COLOR_1 YELLOW_4}Water Maze{END_COLOR_TEXT_1} there\n"
    "will only be Water-type Pokémon.{EXTRA_MSG}"
    " In such ways, only one type\n"
    "of Pokémon will be in a given room.\n"
    "Study how types match up in battle.{EXTRA_MSG}"
    " The Pokémon in this dojo,\n"
    "by the way, are all volunteers.{EXTRA_MSG}"
    " They are participating\n"
    "because they want to see rescue teams\n"
    "succeed.{EXTRA_MSG}"
    " The only thanks they expect\n"
    "is to see you become stronger.\n"
    "Don't let them down!{EXTRA_MSG}"
    " There's more.{WAIT_PRESS}\n"
    "For a rescue team that successfully\n"
    "completes all training courses...{EXTRA_MSG}"
    " I have a special reward!{EXTRA_MSG}"
    " Let that compel you to train\n"
    "harder!");

ALIGNED(4) static const u8 sUnknown_80DA62C[] = _(
    " Don't let up on your training!\n"
    "Keep bettering yourself!{EXTRA_MSG}"
    " May you never lose your\n"
    "drive!");

ALIGNED(4) static const u8 sUnknown_80DA688[] = _(
    " Ah...\n"
    "You have succeeded in your training!{EXTRA_MSG}"
    " You've shown your worth!{WAIT_PRESS}\n"
    "Without a doubt, you have grown more\n"
    "powerful from your training!{WAIT_PRESS} Wait...{WAIT_PRESS} ...{EXTRA_MSG}"
    " Wuh?{WAIT_PRESS}\n"
    "What, what, what?!{EXTRA_MSG}"
    " Did you maybe...{WAIT_PRESS}\n"
    "Conquer all the training courses?{EXTRA_MSG}"
    " That's...{WAIT_PRESS} Amazing! You!{WAIT_PRESS}\n"
    "Congratulations!{EXTRA_MSG}"
    " I promised!{WAIT_PRESS}\n"
    "I promised you a reward for completing\n"
    "the training courses!{EXTRA_MSG}"
    " So... Here it is!{WAIT_PRESS}\n"
    "My {COLOR_1 GREEN_2}Bonsly Doll{END_COLOR_TEXT_1}!{EXTRA_MSG}"
    " Isn't it smashing? Hey?!");

ALIGNED(4) static const u8 sUnknown_80DA844[] = _(
    " Ah...\n"
    "You have succeeded in your training!{EXTRA_MSG}"
    " You've shown your worth!{WAIT_PRESS}\n"
    "Without a doubt, you have grown more\n"
    "powerful from your training!{EXTRA_MSG}"
    " May this success drive\n"
    "you to train even harder!");

ALIGNED(4) static const u8 sUnknown_80DA908[] = _(
    " Aiyah...{WAIT_PRESS}\n"
    "You failed to reach the end...{WAIT_PRESS}\n"
    "More training is what you need.{EXTRA_MSG}"
    " But effort is never wasted!{EXTRA_MSG}"
    " Learn from this and move\n"
    "forward!");

ALIGNED(4) static const u8 sUnknown_80DA998[] = _(
    " The {ARG_POKEMON_0}?{WAIT_PRESS}\n"
    "Your decision stands!{WAIT_PRESS}\n"
    "Let the training begin!");

ALIGNED(4) static const u8 sUnknown_80DA9D4[] = _(" Where do you wish to train?");

ALIGNED(4) static const u8 sUnknown_80DA9F4[] = _(
    " Fine, farewell.\n"
    "Return if you seek more training.");

ALIGNED(4) static const u8 sUnknown_80DAA2C[] = _(" What else do you seek?");

ALIGNED(4) static const u8 sUnknown_80DAA44[] = _(
    " This is the Makuhita Dojo!{WAIT_PRESS}\n"
    "Through rigorous training, one begets\n"
    "true power.");