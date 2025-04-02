#include "global.h"
#include "globaldata.h"
#include "dungeon_boss_dialogue.h"
#include "constants/monster.h"

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Look, {POKEMON_0}!\n{POKEMON_2}'s over there!")
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_2[] = {
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Hey! Are you all right?\nWe're here to rescue you!"),
    },
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Hey! Are you all right?\nWe've come to rescue you!"),
    },
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_DIGLETT,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...I...\nI'm scared."),
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SKARMORY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You!\nWhat do you think you're doing here?!"),
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_5[] = {
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" We came to rescue\n{POKEMON_2}!{EXTRA_MSG} Hey, {POKEMON_3}!\nQuit doing this, and release {POKEMON_2}!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" We're here to rescue\n{POKEMON_2}!{EXTRA_MSG} {POKEMON_3}!\nDon't do this! Release {POKEMON_2}!"),
    },
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SKARMORY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" How dare you!{WAIT_PRESS}\nIt's their fault!{EXTRA_MSG} I haven't slept in days\nbecause the earthquakes frighten me so!\nEvery night we had them!{EXTRA_MSG} Those earthquakes are\ncaused by this brat's ilk running wild\nunderground!"),
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_7[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Whoa, that's not true.{EXTRA_MSG} Sure there've been quakes\ngalore lately...{EXTRA_MSG} But it would take more than\n{POKEMON_2}'s family running wild under\nthe ground to set off a quake."),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" That's not true.{EXTRA_MSG}Well, it's true there have\nbeen many earthquakes lately, but...{EXTRA_MSG} It would take more than\n{POKEMON_2}'s family going wild under\nthe ground to cause earthquakes."),
    },
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_8 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SKARMORY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You be quiet!{EXTRA_MSG}We'll fight if you keep that up!"),
};

const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_9[] = {
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" It's useless.\n{POKEMON_3} is too steamed to talk\nreasonably.{EXTRA_MSG} We're going to have to\nfight!"),
    },
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" It's no good.\n{POKEMON_3} is too agitated to listen to\nreason.{EXTRA_MSG} We'll have to fight it out!"),
    },
};

const struct DungeonDialogueStruct gSkarmoryReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SKARMORY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You again?!\nPersistent pests!"),
};

const struct DungeonDialogueStruct gSkarmoryReFightDialogue_2 = {
    .type = 0,
    .spriteId = 3,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Let {POKEMON_2} go!\n{POKEMON_3}!"),
};

const struct DungeonDialogueStruct gSkarmoryReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SKARMORY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I absolutely refuse!{EXTRA_MSG} If you want to complain so\nmuch, I'll give you a fight!"),
};

const struct DungeonDialogueStruct gUnknown_8100D3C = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go any farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_1[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" We've come pretty far\ninto this forest.{EXTRA_MSG} I wonder if {POKEMON_2} is\nahead..."),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Wow, we came quite a ways\ninto this forest.{EXTRA_MSG} I wonder if {POKEMON_2} is\nahead..."),
    },
};

const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Hold it right there!"),
};

const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GENGAR,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Keke!\nYou know who's going to get to\n{POKEMON_2} first? We are!{EXTRA_MSG} So, for you to go ahead...{WAIT_PRESS}\nWell, we can't let that happen."),
};

const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_4[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Wh-what...?{EXTRA_MSG} Hey, {POKEMON_3}!{WAIT_PRESS}\nWhy do you always try to mess with us?"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" Wh-what!{EXTRA_MSG} Hey, {POKEMON_3}!{WAIT_PRESS}\nWhy do you always mess with us?"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Wh-what?!{EXTRA_MSG} Now, hold on, {POKEMON_3}!{WAIT_PRESS}\nWhy do you always interfere with us?"),
    },
};

const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 3,
    .spritePlacementId = 12,
    .speciesId = MONSTER_MEDICHAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Oh? Didn't we tell you?{WAIT_PRESS}\nOur aim is world domination〜♪ "),
};

const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 2,
    .spritePlacementId = 13,
    .speciesId = MONSTER_EKANS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" {POKEMON_4}'s mama will\ngive us a generous reward...{EXTRA_MSG} And {POKEMON_4} will join\nus too...{WAIT_PRESS}\nThat brings us closer to our goal."),
};

const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_7 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GENGAR,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Keke!\nAnd for that, your lot is in the way!{EXTRA_MSG} So sorry to say, but your\nparty's over right here and now!{EXTRA_MSG} Say good-bye, {POKEMON_1}!"),
};

const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_1[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Last time, this is where\n{POKEMON_3}'s gang appeared.{EXTRA_MSG} Did they find {POKEMON_2}\nalready, I wonder?"),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" This is where the {COLOR CYAN}Meanies{RESET}\nshowed up last time.{EXTRA_MSG} I wonder if {POKEMON_3}'s\nbunch already found {POKEMON_2}..."),
    },
};

const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_2[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Hah? It's {POKEMON_3}!{EXTRA_MSG} Why is {POKEMON_3}'s\ncrew coming after us?"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" Huh? It's {POKEMON_3}!{EXTRA_MSG} Why is the {POKEMON_3}\ngang following us?"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Huh? It's {POKEMON_3}!{EXTRA_MSG} Why is {POKEMON_3}'s gang\nfollowing us?"),
    },
};

const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_3 = {
    .type = 0,
    .spriteId = 3,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GENGAR,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Y-you be quiet!{EXTRA_MSG} Right after we beat you last\ntime...{EXTRA_MSG} We got careless and wiped\nout too!"),
};

const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_4 = {
    .type = 1,
    .spriteId = 3,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GENGAR,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Don't you laugh at me!{WAIT_PRESS}\nWhat makes you so high-and-mighty?{EXTRA_MSG} Whatever happens, we're\nnot going to lose to you amateurs!"),
};

const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_5 = {
    .type = 0,
    .spriteId = 2,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GENGAR,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This is it, {POKEMON_1}!\nYou're going down!"),
};

const struct DungeonDialogueStruct gUnknown_8101440 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}It's impossible to go any farther...{WAIT_PRESS}\n{CENTER_ALIGN}But there is nothing here.{EXTRA_MSG}{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gUnknown_81014B0[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" This is the mountain's peak..."),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" This is the summit..."),
    },
};

const struct DungeonDialogueStruct gUnknown_8101504[] = {
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Hey! {POKEMON_3}!\nWhere are you?!{EXTRA_MSG} We came to rescue\n{POKEMON_2}!\nShow yourself!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Hey! {POKEMON_3}!\nWhere are you?!{EXTRA_MSG} We came to rescue\n{POKEMON_2}!\nCome out!"),
    },
};

const struct DungeonDialogueStruct gUnknown_81015A0 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gyaoooooooooh!\n                     "),
};

const struct DungeonDialogueStruct gUnknown_81015D4 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Waah!"),
};

const struct DungeonDialogueStruct gUnknown_81015E8 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I warned you!\nI have no mercy for meddlers!"),
};

const struct DungeonDialogueStruct gUnknown_8101624 = {
    .type = 0,
    .spriteId = 2,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Not scared...{WAIT_PRESS}\nYou don't frighten me!"),
};

const struct DungeonDialogueStruct gUnknown_810165C[] = {
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Hey, {POKEMON_3}!\nLet {POKEMON_2} go!{EXTRA_MSG} A Pokémon rescue team!\nThat's what we are!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" Hey, {POKEMON_3}!\nRelease {POKEMON_2}!{EXTRA_MSG} We're a Pokémon rescue\nteam!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Hey, {POKEMON_3}!\nWe demand you release {POKEMON_2}!{EXTRA_MSG} We're a Pokémon rescue\nteam!"),
    },
};

const struct DungeonDialogueStruct gUnknown_8101750 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You must be determined,\nto utter such words."),
};

const struct DungeonDialogueStruct gUnknown_810178C = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Then you shall answer..."),
};

const struct DungeonDialogueStruct gUnknown_81017B4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" To my great and righteous\nfury!"),
};

const struct DungeonDialogueStruct gZapdosReFightDialogue_1[] = {
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Hey, {POKEMON_3}!\nGuess who's back?!{EXTRA_MSG} Show yourself!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" Hey, {POKEMON_3}!\nWe're back!{EXTRA_MSG} Come out!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Hey, {POKEMON_3}!\nWe're here again!{EXTRA_MSG} Show yourself!"),
    },
};

const struct DungeonDialogueStruct gZapdosReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" However often you may\nreturn...\nThe result will always be the same!"),
};

const struct DungeonDialogueStruct gZapdosReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You have no hope of\nwinning!"),
};

const struct DungeonDialogueStruct gZapdosReFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Prepare yourselves!"),
};

const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_1 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gyaoooooooooooh!\n                     "),
};

const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" So, you're back!"),
};

const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Since we last met, how\nmuch more have you furthered your team?"),
};

const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" How much stronger?"),
};

const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ZAPDOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Your power...{WAIT_PRESS}\nDemonstrate it for me!"),
};

const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_6 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The mountain's summit...{WAIT_PRESS}\n{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Is this it?\nIs this Mt. Blaze's summit?"),
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_2[] = {
    {
        .type = 0,
        .spriteId = 2,
        .spritePlacementId = 13,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" This is one incredible place.{WAIT_PRESS}\nI know this is a volcano, but the amount\nof lava is way more than usual.{EXTRA_MSG} This might also be a part of\nthe natural disasters..."),
    },
    {
        .type = 0,
        .spriteId = 2,
        .spritePlacementId = 13,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Wow. This is incredible.{WAIT_PRESS}\nI know it's a volcano, but the lava flow\nis much higher than normal.{EXTRA_MSG} This might also have a link\nto the natural calamities..."),
    },
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_3[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 13,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Yowch! It's wicked hot!{WAIT_PRESS}\nI feel like I'm burning up."),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 13,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Oogh! It's like a furnace!{WAIT_PRESS}\nI'm getting roasted!"),
    },
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_4[] = {
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 18,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" I don't want to be in a place\nthis wickedly bad.{EXTRA_MSG} Let's get through here quick."),
    },
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 18,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" I don't want to spend any\ntime in a place this dangerous.{EXTRA_MSG} Let's get through this quick."),
    },
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Halt!"),
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_6[] = {
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Wh-what the...?!{EXTRA_MSG} Why did it turn dark like\nthat?!"),
    },
    {
        .type = 0,
        .spriteId = 4,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Huh, what?!{EXTRA_MSG} It suddenly turned dark!"),
    },
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_7 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I can hear the mountain's screams...{EXTRA_MSG} It is shrieking in pain...{EXTRA_MSG} Someone is causing Mt. Blaze to\nwrithe in agony!\nIs it you?!"),
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_8[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Hah?!{WAIT_PRESS}\nWe don't know what you mean!\nWe're not doing anything!{EXTRA_MSG} We just happened to be\ntraveling through here!{EXTRA_MSG} Who are you, anyway?{WAIT_PRESS}\nCome out!"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" Huh?!{WAIT_PRESS}\nYou've got it wrong!\nIt's not us!{EXTRA_MSG} We just happened to be\npassing through here!{EXTRA_MSG} Who are you, anyway?{WAIT_PRESS}\nShow yourself!\n "),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Huh?!{WAIT_PRESS}\nThat's wrong!\nWe're innocent!{EXTRA_MSG} We were just passing\nthrough!{EXTRA_MSG} Who are you, anyway?{WAIT_PRESS}\nShow yourself!"),
    },
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_9 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gyaaaaaaaaaaaa!\n                     "),
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_10 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" The mountain's rage is my rage!"),
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_11 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!\nThe warrior of fire am I!"),
};

const struct DungeonDialogueStruct gMoltresPreFightDialogue_12 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" There is no forgiving \nthose who befoul the mountain!\nEn garde!"),
};

const struct DungeonDialogueStruct gMoltresReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ............{WAIT_PRESS}\nMaybe {POKEMON_2} isn't around..."),
};

const struct DungeonDialogueStruct gMoltresReFightDialogue_2[] = {
    {
        .type = 0,
        .spriteId = 1,
        .spritePlacementId = 18,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Let's sneak through while\nwe can."),
    },
    {
        .type = 0,
        .spriteId = 1,
        .spritePlacementId = 18,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Let's slip by here while\nwe have the chance."),
    },
};

const struct DungeonDialogueStruct gMoltresReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You again!{EXTRA_MSG} There is no forgiving \nthose who torment the mountain!"),
};

const struct DungeonDialogueStruct gMoltresReFightDialogue_4[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" You've got us wrong!{WAIT_PRESS}\nWe're just..."),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" You don't understand!{WAIT_PRESS}\nWe're only..."),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Won't you listen?!{WAIT_PRESS}\nWe're only..."),
    },
};

const struct DungeonDialogueStruct gMoltresReFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Your words are\nmeaningless!\nEn garde!"),
};

const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Halt!{EXTRA_MSG} This is Mt. Blaze!{EXTRA_MSG} For you to venture to its\npeak, there can be but one reason!"),
};

const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You've come to challenge\nme!"),
};

const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" So be it!{WAIT_PRESS}\nI am the warrior of fire, {POKEMON_2}!"),
};

const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Have you what it takes to\ndefeat me when I am holding back nothing?"),
};

const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MOLTRES,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Show me!"),
};

const struct DungeonDialogueStruct gUnknown_810246C = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The mountain's summit...{WAIT_PRESS}\n{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_1[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" We've come pretty far into\nthe forest.{EXTRA_MSG} I think we'll be out if we\ncan get through this part.{WAIT_PRESS}\nIt shouldn't be long. Hang in there."),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" We sure have traveled far\ninto this forest.{EXTRA_MSG} I think we'll be out if we\ncan get through this part.{WAIT_PRESS}\nIt shouldn't be far. Let's keep going."),
    },
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ..............."),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 4,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...Huh?{WAIT_PRESS}\n{POKEMON_0}, did you just say something?"),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_4[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" ...I didn't think so.{EXTRA_MSG} A voice...?{WAIT_PRESS}\nI must've imagined it."),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" ...I didn't think so...{EXTRA_MSG} I thought I heard a voice...{WAIT_PRESS}\nI must have imagined it."),
    },
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ..................{EXTRA_MSG} ...Turn back.{EXTRA_MSG}You may not pass..."),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Who's there?!"),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_7 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You are forbidden to pass...{EXTRA_MSG} ...If you persist in trying to pass...{EXTRA_MSG} Then, so be it...{EXTRA_MSG} But only after you have defeated me!"),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_8 = {
    .type = 0,
    .spriteId = 2,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Ow! It's too bright!{EXTRA_MSG} The ice around us is\nreflecting this light!"),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_9 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gyaaaaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_10 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nThe warder of ice!"),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_11 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Those that enter the forest\nI shall destroy with all my might!"),
};

const struct DungeonDialogueStruct gArticunoPreFightDialogue_12 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Let us begin!"),
};

const struct DungeonDialogueStruct gArticunoReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You may try all you like.\nBut you shall never pass!"),
};

const struct DungeonDialogueStruct gArticunoReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" If you so badly hope to\npass..."),
};

const struct DungeonDialogueStruct gArticunoReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Do so only if you can snatch\nvictory from me!"),
};

const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_1 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gyaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Your arrival in this frozen\nforest means only one thing...{EXTRA_MSG} You mean to challenge me!"),
};

const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nThe warder of ice!"),
};

const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Those that enter\nthe forest...\nI shall destroy with all my might!"),
};

const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ARTICUNO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" No matter who it may be!"),
};

const struct DungeonDialogueStruct gUnknown_8102A9C = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}This is the deepest part of the forest...{WAIT_PRESS}\n{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gUnknown_8102B10 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The mountain's summit...{WAIT_PRESS}\n{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_1 = {
    .type = 0,
    .spriteId = 4,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Let's see...{WAIT_PRESS}\n...I wonder where we are?"),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_2[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" I know we've come pretty\nfar..."),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" I'm certain we've come quite\nfar already..."),
    },
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_3 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Waaah!\nQu-quake!"),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_4[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" ...Whew!\nIt settled down."),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" ...Whew!\nIt's over."),
    },
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_5 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Hey! {POKEMON_0}!\nOver there!"),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_6[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Hey!\nSnap out of it!"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Hey!\nAre you OK?!"),
    },
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_7 = {
    .type = 0,
    .spriteId = 3,
    .spritePlacementId = 14,
    .speciesId = MONSTER_CHARIZARD,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Urrrrgh..."),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_8[] = {
    {
        .type = 0,
        .spriteId = 5,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" What happened here?"),
    },
    {
        .type = 0,
        .spriteId = 5,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" What happened to you?"),
    },
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_9 = {
    .type = 0,
    .spriteId = 3,
    .spritePlacementId = 14,
    .speciesId = MONSTER_CHARIZARD,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" We challenged...\n{POKEMON_2}...{WAIT_PRESS}\nAnd wiped out...\n"),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_10 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" G-{POKEMON_2}?!"),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_11 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 15,
    .speciesId = MONSTER_TYRANITAR,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Grrgh...{WAIT_PRESS}\nWe... It crushed us..."),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_12[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Wait...{WAIT_PRESS}\nWhat about {POKEMON_3}?\nWhere did {POKEMON_3} go?"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" That's right.{WAIT_PRESS}\nWhat happened to {POKEMON_3}?\nWhere is {POKEMON_3}?"),
    },
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_13 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 15,
    .speciesId = MONSTER_TYRANITAR,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" {POKEMON_3} is...{WAIT_PRESS}\nStill battling {POKEMON_2}..."),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_14 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" {POKEMON_0}!\nWe've got to hurry!"),
};

const struct DungeonDialogueStruct MagmaCavernMidDialogue_15 = {
    .type = 0,
    .spriteId = 3,
    .spritePlacementId = 14,
    .speciesId = MONSTER_CHARIZARD,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...Be careful!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_1[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Oh! {POKEMON_3}!\nAre you OK?!"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" It's {POKEMON_3}!\nAre you OK?!"),
    },
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 15,
    .speciesId = MONSTER_ALAKAZAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Hm!{WAIT_PRESS}\nSo it's you!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 15,
    .speciesId = MONSTER_ALAKAZAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Stay back!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 15,
    .speciesId = MONSTER_ALAKAZAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This opponent...{WAIT_PRESS}\nis no laughing matter!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_5 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Grgaaaaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 15,
    .speciesId = MONSTER_ALAKAZAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" H-here it comes!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_7 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Coming...?{WAIT_PRESS}\nWh-where?!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_8 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 15,
    .speciesId = MONSTER_ALAKAZAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Wraaaaaah!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_9 = {
    .type = 0,
    .spriteId = 12,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" A-{POKEMON_3}!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_10[] = {
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" {POKEMON_3}'s gone!{EXTRA_MSG} Was he maybe...{WAIT_PRESS}\nknocked out?!"),
    },
    {
        .type = 0,
        .spriteId = 12,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" {POKEMON_3} is gone!{EXTRA_MSG} Maybe...{WAIT_PRESS}\nWas he defeated?!"),
    },
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_11[] = {
    {
        .type = 0,
        .spriteId = 2,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Darn it!\nIt's our turn next."),
    },
    {
        .type = 0,
        .spriteId = 2,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" Urgh...\nIt's our turn next."),
    },
    {
        .type = 0,
        .spriteId = 2,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Ohh...\nIt's our turn next."),
    },
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_12 = {
    .type = 0,
    .spriteId = 2,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" But I'm not going down\nwithout a fight!"),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_13 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Grgaaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct GroudonPreFightDialogue_14[] = {
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" {POKEMON_0}!\nHang tough!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" {POKEMON_0}!\nLet's do our best!"),
    },
};

const struct DungeonDialogueStruct gGroudonReFightDialogue_1[] = {
    {
        .type = 0,
        .spriteId = 2,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Here it comes!\n{POKEMON_0}!{EXTRA_MSG} We've got to settle\n{POKEMON_2} down this time!"),
    },
    {
        .type = 0,
        .spriteId = 2,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Here it comes!\n{POKEMON_0}!{EXTRA_MSG} Let's make sure we subdue\n{POKEMON_2} this time!"),
    },
};

const struct DungeonDialogueStruct gGroudonReFightDialogue_2[] = {
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" Don't get psyched out!{EXTRA_MSG} Be brave and keep slugging!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_MOST,
        .str = _(" Don't be intimidated!{EXTRA_MSG} We need to be brave to\nface this thing!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" Don't be intimidated!{EXTRA_MSG} We have to fight it with\nall our courage!"),
    },
};

const struct DungeonDialogueStruct gGroudonReFightDialogue_3 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Grgaaaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct gGroudonReFightDialogue_4[] = {
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" {POKEMON_0}!\nLet's give it what we've got!"),
    },
    {
        .type = 0,
        .spriteId = 3,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" {POKEMON_0}!\nLet's give it our all!"),
    },
};

const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_1 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Grgaaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GROUDON,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Why have you returned?!{WAIT_PRESS}\nHow dare you disturb me in my sleep?!{EXTRA_MSG} I let rage run wild before...{WAIT_PRESS}\nBut I won't allow that again!"),
};

const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GROUDON,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Those that disturb my\nsleep...{WAIT_PRESS}\nShall be crushed!"),
};

const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_GROUDON,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" No matter who it may be!"),
};

const struct DungeonDialogueStruct gUnknown_8103488 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}This appears to be the deepest level.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go any farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Is this...{WAIT_PRESS}\nThe top floor?"),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Who goes there?!{WAIT_PRESS}\nWho dares to trespass upon my\nairspace?!"),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_3[] = {
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ONLY_SQUIRTLE_TOTODILE,
        .str = _(" That voice...{WAIT_PRESS}\nIs that {POKEMON_2}?"),
    },
    {
        .type = 0,
        .spriteId = 0,
        .spritePlacementId = 2,
        .speciesId = DIALOGUE_MONSTER_PARTNER,
        .allowType = DIALOGUE_ALLOW_ALL,
        .str = _(" That voice...{WAIT_PRESS}\nCould it be {POKEMON_2}?"),
    },
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 128,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Indeed I am.{WAIT_PRESS}\nThe sky is my domain.{EXTRA_MSG} Depart at once!"),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 4,
    .spritePlacementId = 2,
    .speciesId = DIALOGUE_MONSTER_PARTNER,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" But...\nWe don't have the time to argue.{EXTRA_MSG} We came here because we\nneed your help..."),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 128,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Never!"),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_7 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gyaaaaaaaaaaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_8 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am a being of the sky,\nand you are but denizens of the ground.{EXTRA_MSG} To each, there is a world\ndestined as their own!{EXTRA_MSG} For hundreds of millions of\nyears, never once have I descended to\nthe ground!"),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_9 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" And the opposite shall also\nhold true!"),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_10 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Let there be no mercy for\nthose that defy the laws of nature!"),
};

const struct DungeonDialogueStruct gRayquazaPreFightDialogue_11 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Prepare for the end!"),
};

const struct DungeonDialogueStruct gRayquazaReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You return, but for no\npurpose!"),
};

const struct DungeonDialogueStruct gRayquazaReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This is no place for the\nlikes of you!"),
};

const struct DungeonDialogueStruct gRayquazaReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Let there be no mercy for\nthose that trespass upon my airspace!"),
};

const struct DungeonDialogueStruct gRayquazaReFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Prepare for the end!"),
};

const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_1 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gyaaaaaaaaaaaah!\n                     "),
};

const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" So it is you who dares to\ntrespass upon my airspace!{EXTRA_MSG} You scaled the Sky Tower...{EXTRA_MSG} Now, you wish to challenge\nme to a battle?!{EXTRA_MSG} ............{WAIT_PRESS}\nIn destroying the falling star, I sustained\ninjuries upon my body and my pride...{EXTRA_MSG} To better protect my\ndomain, I have made myself stronger.{EXTRA_MSG} And so that I may draw\nout my newly gained power..."),
};

const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am now...{WAIT_PRESS}\nUnleashing every bit of my might!"),
};

const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" My power shall overwhelm...{WAIT_PRESS}\nBut you dare to stand up to it?"),
};

const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAYQUAZA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I commend your courage!"),
};

const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_6 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}This appears to be\n{CENTER_ALIGN}the top of the Sky Tower...{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gUnknown_8103BD8 = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Hunh? What is it, you?"),
};

const struct DungeonDialogueStruct gUnknown_8103C00 = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 12,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" We don't like to brag or\nnothing, but..."),
};

const struct DungeonDialogueStruct gUnknown_8103C3C = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" We get furious real easy.\nYou know that?!"),
};

const struct DungeonDialogueStruct gUnknown_8103C74 = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 12,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" What really irritates us is\nwhen we see some dim-witted face..."),
};

const struct DungeonDialogueStruct gUnknown_8103CC4 = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ............{WAIT_PRESS}\nWroooooooar!{WAIT_PRESS}\nThat vacant expression..."),
};

const struct DungeonDialogueStruct gUnknown_8103D0C = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 12,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Gwooooh!\nIt's ticking me off!{WAIT_PRESS}\nI'm seeing red!"),
};

const struct DungeonDialogueStruct gUnknown_8103D50 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Mukkkeeeeeh!\nGet 'em! It's frenzy time!"),
};

const struct DungeonDialogueStruct gUnknown_8103D8C = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Hunh? What is it, you?"),
};

const struct DungeonDialogueStruct gUnknown_8103D98 = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 12,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Are you looking at me...?{WAIT_PRESS}\nAre you mocking me?"),
};

const struct DungeonDialogueStruct gUnknown_8103DD8 = {
    .type = 1,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Gwoooooh!\nIt's ticking me off!{WAIT_PRESS}\nI'm about to blow my fuse!"),
};

const struct DungeonDialogueStruct gUnknown_8103E28 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 12,
    .speciesId = MONSTER_MANKEY,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Mukkkeeeeeh!\nGet 'em! It's frenzy time!"),
};

const struct DungeonDialogueStruct gUnknown_8103E34 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gMewtwoPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ............{WAIT_PRESS}\nWas it you...?{EXTRA_MSG} ...Who...disturbed...me...in my...\nsleep...?{WAIT_PRESS}\nWas it you?"),
};

const struct DungeonDialogueStruct gMewtwoPreFightDialogue_2 = {
    .type = 3,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEWTWO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" My name is {POKEMON_2}.{WAIT_PRESS}\nI came into being only to fight."),
};

const struct DungeonDialogueStruct gMewtwoPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEWTWO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I...{WAIT_PRESS}\nhave secluded myself here in suspended\nanimation.{EXTRA_MSG} Would you like to know\nwhy?{WAIT_PRESS}\nIt's quite simple..."),
};

const struct DungeonDialogueStruct gMewtwoPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEWTWO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" If anyone--such as you--\nwere to come along..."),
};

const struct DungeonDialogueStruct gMewtwoPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEWTWO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I could defeat them at full\npower!\nCome on!"),
};

const struct DungeonDialogueStruct gMewtwoReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ............{WAIT_PRESS}\nWas it you...?{EXTRA_MSG} ...Who...disturbed...me...in my...\nsleep...?{WAIT_PRESS}\nWas it you?"),
};

const struct DungeonDialogueStruct gMewtwoReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEWTWO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I...{WAIT_PRESS}\nhave secluded myself here in suspended\nanimation...{EXTRA_MSG} Lying in wait...{WAIT_PRESS}\nFor someone like you to come."),
};

const struct DungeonDialogueStruct gMewtwoReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEWTWO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}.{WAIT_PRESS}\nA Pokémon created only to fight...{WAIT_PRESS}\nAnd..."),
};

const struct DungeonDialogueStruct gMewtwoReFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEWTWO,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" The most powerful Pokémon\nof all!"),
};

const struct DungeonDialogueStruct gMewtwoReFightDialogue_5 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gEnteiPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" What compelled you to come?{EXTRA_MSG} The likes of you have no business\nbeing here!"),
};

const struct DungeonDialogueStruct gEnteiPreFightDialogue_2 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nI live surrounded by the fiery lava of\nvolcanoes!"),
};

const struct DungeonDialogueStruct gEnteiPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" If you refuse to leave...{WAIT_PRESS}\nI shall forcefully expel you!"),
};

const struct DungeonDialogueStruct gEnteiReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Did I not say to never\nreturn?{EXTRA_MSG} This is the {COLOR YELLOW_D}Fiery Field{RESET}!{WAIT_PRESS}\nIt is no place for your kind!"),
};

const struct DungeonDialogueStruct gEnteiReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nI live surrounded by the fiery lava of\nvolcanoes!"),
};

const struct DungeonDialogueStruct gEnteiReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Since you fail to heed my\nwords...{WAIT_PRESS}\nI've no choice but to defeat you!"),
};

const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This is the {COLOR YELLOW_D}Fiery Field{RESET}!{WAIT_PRESS}\nIt is no place for your kind!{EXTRA_MSG} I am {POKEMON_2}!{WAIT_PRESS}\nI live surrounded by the fiery lava of\nvolcanoes!"),
};

const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Depart from here..."),
};

const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_ENTEI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Immediately!"),
};

const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_4 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gRaikouPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Why...{WAIT_PRESS}\nWhy have you come...?{EXTRA_MSG} This is {COLOR YELLOW_D}Lightning Field{RESET}.{WAIT_PRESS}\nIt is my...{WAIT_PRESS}domain!"),
};

const struct DungeonDialogueStruct gRaikouPreFightDialogue_2 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nOne who races with lightning!{EXTRA_MSG} A body like roiling rain\nclouds!"),
};

const struct DungeonDialogueStruct gRaikouPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" A roar that echoes thunder!"),
};

const struct DungeonDialogueStruct gRaikouPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Many have trespassed upon\nmy domain..."),
};

const struct DungeonDialogueStruct gRaikouPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" But what became of them?{WAIT_PRESS}\nLet me demonstrate..."),
};

const struct DungeonDialogueStruct gRaikouPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" And you, too, shall\nexperience the pain they suffered!"),
};

const struct DungeonDialogueStruct gRaikouReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Snicker... You again.{WAIT_PRESS}\nYou don't give up easily.{EXTRA_MSG} If you so wish to taste\ndefeat again, I shall oblige!"),
};

const struct DungeonDialogueStruct gRaikouReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" With my electric bolts...{WAIT_PRESS}"),
};

const struct DungeonDialogueStruct gRaikouReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I will devastate you again!"),
};

const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This is {COLOR YELLOW_D}Lightning Field{RESET}!{WAIT_PRESS}\nMy domain!{EXTRA_MSG} All those who enter...{WAIT_PRESS}\nI show no mercy, no matter what!"),
};

const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" With my electric bolts..."),
};

const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_RAIKOU,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I will devastate you again!"),
};

const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_4 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gSuicunePreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Halt!"),
};

const struct DungeonDialogueStruct gSuicunePreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Why are you here?!"),
};

const struct DungeonDialogueStruct gSuicunePreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Clear and bracing air...{WAIT_PRESS}\nCrystalline, pure water...{EXTRA_MSG} To stand guard over this beautiful and\nuntainted land...{WAIT_PRESS}\nThat is why I am here."),
};

const struct DungeonDialogueStruct gSuicunePreFightDialogue_4 = {
    .type = 3,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nOne who runs with the north wind!"),
};

const struct DungeonDialogueStruct gSuicunePreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Intruders foul the air\nwith their outside ills."),
};

const struct DungeonDialogueStruct gSuicunePreFightDialogue_6 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" There is but one solution\nfor invaders: expulsion by force!"),
};

const struct DungeonDialogueStruct gSuicunePreFightDialogue_7 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Here I come!"),
};

const struct DungeonDialogueStruct gSuicuneReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This is no place for you!{EXTRA_MSG} Leave immediately!{EXTRA_MSG} If you refuse..."),
};

const struct DungeonDialogueStruct gSuicuneReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I will..."),
};

const struct DungeonDialogueStruct gSuicuneReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" With all my furious power...{WAIT_PRESS}\nDestroy you!"),
};

const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You mean to challenge me?{EXTRA_MSG} I find little satisfaction in\nfighting...{WAIT_PRESS}\nHowever!{EXTRA_MSG} If you refuse my\ndemands that you leave...{EXTRA_MSG} I will accept your challenge."),
};

const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Experience it."),
};

const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SUICUNE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" My true power...{WAIT_PRESS}\nUnleashed!"),
};

const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_4 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gHoOhPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Excellent!{EXTRA_MSG} You have done well to come this far.{EXTRA_MSG} You have overcome countless\nchallenges...{EXTRA_MSG} Fought through many dangerous\nsituations...{EXTRA_MSG} and finally ascended to the very peak\nof {COLOR YELLOW_D}Mt. Faraway{RESET}!{EXTRA_MSG} Truly, only the chosen have reached\nthe summit.{EXTRA_MSG} However!"),
};

const struct DungeonDialogueStruct gHoOhPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This is not the end!"),
};

const struct DungeonDialogueStruct gHoOhPreFightDialogue_3 = {
    .type = 3,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_HO_OH,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nThe builder of rainbows across the sky!"),
};

const struct DungeonDialogueStruct gHoOhPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_HO_OH,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Only when you overcome\nme in battle...{WAIT_PRESS}\nThat is when this mountain is conquered!"),
};

const struct DungeonDialogueStruct gHoOhPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_HO_OH,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" This is the final challenge!"),
};

const struct DungeonDialogueStruct gHoOhPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_HO_OH,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Here I come!"),
};

const struct DungeonDialogueStruct HoOhReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Very good!{EXTRA_MSG} You have done well to come this far.{EXTRA_MSG} Truly, only the chosen have reached\nthe summit."),
};

const struct DungeonDialogueStruct HoOhReFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_HO_OH,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Your very arrival is\nevidence of a truly powerful warrior!{WAIT_PRESS}\nAnd...{EXTRA_MSG} It is also your right to\nchallenge me!"),
};

const struct DungeonDialogueStruct HoOhReFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_HO_OH,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Surpass your own\nlimitations..."),
};

const struct DungeonDialogueStruct HoOhReFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_HO_OH,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" And show me your power in\nits unbridled entirety!\nCome on!"),
};

const struct DungeonDialogueStruct HoOhReFightDialogue_5 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gLatiosPreFightDialogue_1 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LATIOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Oh!{WAIT_PRESS}\nWho are you?!{EXTRA_MSG} ............{WAIT_PRESS}\nI see. You're trying to get your TMs back.{EXTRA_MSG} But!{EXTRA_MSG} Nobody can stop me!{EXTRA_MSG} I'm the Eon Pokémon {POKEMON_2}!"),
};

const struct DungeonDialogueStruct gLatiosPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LATIOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" If you really want your\nTMs back..."),
};

const struct DungeonDialogueStruct gLatiosPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LATIOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You'll have to take them\nfrom me!"),
};

const struct DungeonDialogueStruct gLatiosReFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LATIOS,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You're back?{EXTRA_MSG} But!{EXTRA_MSG} It doesn't matter how often\nyou come!{WAIT_PRESS}\nNobody can stop me!"),
};

const struct DungeonDialogueStruct gUnknown_8104FC8 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go any farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gRegirockPreFightDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}{CENTER_ALIGN}EXTERMINATE!{EXTRA_MSG}{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}{CENTER_ALIGN}EXTERMINATE!"),
};

const struct DungeonDialogueStruct gRegicePreFightDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}{CENTER_ALIGN}EXTERMINATE!{EXTRA_MSG}{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}{CENTER_ALIGN}EXTERMINATE!"),
};

const struct DungeonDialogueStruct gRegisteelPreFightDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}{CENTER_ALIGN}EXTERMINATE!{EXTRA_MSG}{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}{CENTER_ALIGN}EXTERMINATE!"),
};

const struct DungeonDialogueStruct gRegirockPostFightDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}Something fell from\n{CENTER_ALIGN}{COLOR CYAN_M}Regirock{RESET}'s body.{EXTRA_MSG}{CENTER_ALIGN}{COLOR CYAN_M}Regirock{RESET} was apparently\n{CENTER_ALIGN}guarding this item."),
};

const struct DungeonDialogueStruct gRegirockPostFightDialogue_2 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_0} obtained\n{CENTER_ALIGN}the {COLOR GREEN_I}Rock Part{RESET}...{EXTRA_MSG}{CENTER_ALIGN}that {COLOR CYAN_M}Regirock{RESET} was guarding!"),
};

const struct DungeonDialogueStruct gRegicePostFightDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}Something fell from\n{CENTER_ALIGN}{COLOR CYAN_M}Regice{RESET}'s body.{EXTRA_MSG}{CENTER_ALIGN}{COLOR CYAN_M}Regice{RESET} was apparently\n{CENTER_ALIGN}guarding this item."),
};

const struct DungeonDialogueStruct gRegicePostFightDialogue_2 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_0} obtained\n{CENTER_ALIGN}the {COLOR GREEN_I}Ice Part{RESET}...{EXTRA_MSG}{CENTER_ALIGN}that {COLOR CYAN_M}Regice{RESET} was guarding!"),
};

const struct DungeonDialogueStruct gRegisteelPostFightDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}Something fell from\n{CENTER_ALIGN}{COLOR CYAN_M}Registeel{RESET}'s body.{EXTRA_MSG}{CENTER_ALIGN}{COLOR CYAN_M}Registeel{RESET} was apparently\n{CENTER_ALIGN}guarding this item."),
};

const struct DungeonDialogueStruct gRegisteelPostFightDialogue_2 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_0} obtained\n{CENTER_ALIGN}the {COLOR GREEN_I}Steel Part{RESET}...{EXTRA_MSG}{CENTER_ALIGN}that {COLOR CYAN_M}Registeel{RESET} was guarding!"),
};

const u8 *const gUnknown_810531C =_("{CENTER_ALIGN}That means...{EXTRA_MSG}{CENTER_ALIGN}By finding the {COLOR GREEN_I}Rock Part{RESET},\n{CENTER_ALIGN}{COLOR GREEN_I}Ice Part{RESET}, and {COLOR GREEN_I}Steel Part{RESET}...{EXTRA_MSG}{CENTER_ALIGN}All three parts are yours!");
const u8 *const gUnknown_8105360 =_("{CENTER_ALIGN}Oh? The three parts...{WAIT_PRESS}\n{CENTER_ALIGN}They're reacting to each other?");
const u8 *const gUnknown_81053A8 =_("{CENTER_ALIGN}The three parts\n{CENTER_ALIGN}fit together...{EXTRA_MSG}{CENTER_ALIGN}and became a {COLOR GREEN_I}Music Box{RESET}!");
const u8 *const gUnknown_8105434 =_("{CENTER_ALIGN}{POKEMON_0} obtained\n{CENTER_ALIGN}the {COLOR GREEN_I}Music Box{RESET}!{EXTRA_MSG}{CENTER_ALIGN}The {COLOR GREEN_I}Music Box{RESET} only needs\n{CENTER_ALIGN}to be in the Toolbox for it to\n{CENTER_ALIGN}attract a special something!");
const struct DungeonDialogueStruct gJirachiPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ........................{EXTRA_MSG} ......Fwaaaaaaaahhh......{EXTRA_MSG} I'm still sleepy...\nFnyumnyum..."),
};

const struct DungeonDialogueStruct gJirachiPreFightDialogue_2 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...Who is it?{EXTRA_MSG} Who is that over there?\nFnyumnyum..."),
};

const struct DungeonDialogueStruct gJirachiPreFightDialogue_3 = {
    .type = 2,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I'm {POKEMON_2}.\nWho are you?"),
};

const struct DungeonDialogueStruct gJirachiPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ......Fwaaaaahhhh......\nI'm still...sleepy..."),
};

const struct DungeonDialogueStruct gUnknown_810554C = {
    .type = 1,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ......Fwaaaaahhhh......\nI'm still...sleepy..."),
};

const struct DungeonDialogueStruct gUnknown_8105558 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...I think I had a dream,\nand I was fighting in it...{WAIT_PRESS}\nDid I imagine it?{EXTRA_MSG} ...I'm sleepy, so I'm going\nback to sleep...\nGood night..."),
};

const struct DungeonDialogueStruct gUnknown_81055F4 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{COLOR CYAN_M}{POKEMON_2}{RESET} fell\n{CENTER_ALIGN}back into a deep sleep...{EXTRA_MSG}{CENTER_ALIGN}Apparently, {COLOR CYAN_M}{POKEMON_2}{RESET}\n{CENTER_ALIGN}was fighting in its sleep..."),
};

const struct DungeonDialogueStruct gUnknown_8105668 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ......Fwaaaaahhhh......\nI'm still...sleepy..."),
};

const struct DungeonDialogueStruct gUnknown_8105674 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...Oh, oh?!\nI hear singing...{EXTRA_MSG} A song of purity..."),
};

const struct DungeonDialogueStruct gUnknown_81056B8 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Ha!{WAIT_PRESS}\nEyes wide open!"),
};

const struct DungeonDialogueStruct gUnknown_81056DC = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I don't know why, but I'm\nwide awake!{EXTRA_MSG} I'm {POKEMON_2}.{EXTRA_MSG} When I awaken, I grant\na wish.\nI have to.{EXTRA_MSG} Er-hem...{WAIT_PRESS}\nThen...{WAIT_PRESS} I ask you this."),
};

const u8 *const gUnknown_8105798 =_("{COLOR YELLOW_N}{POKEMON_2}{RESET}: What is your \nwish?");
const MenuItem gUnknown_810579C[] = {
    {_("Lots of money."), 1},
    {_("Lots of items."), 2},
    {_("A Friend Area."), 3},
    {_("More strength."), 4},
    {_("Something good!"), 5},
    {NULL, -1},
};
const struct DungeonDialogueStruct gUnknown_810581C = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You want lots of money?{EXTRA_MSG} As you wish.{WAIT_PRESS}\nI'll gather all the money in the dungeon and\nbring it here.{EXTRA_MSG} Now...{WAIT_PRESS}\nHere goes!"),
};

const struct DungeonDialogueStruct gUnknown_81058A8 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Nnnnnnnnnn!"),
};

const struct DungeonDialogueStruct gUnknown_81058C4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Taaaaaaaah!"),
};

const struct DungeonDialogueStruct gUnknown_81058E0 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...Fwaaaaaaaahhh...{EXTRA_MSG} Using that power...\nMade me sleepy...{WAIT_PRESS}\nGood night..."),
};

const struct DungeonDialogueStruct gUnknown_810593C = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{COLOR CYAN_M}{POKEMON_2}{RESET} fell\n{CENTER_ALIGN}back into a deep sleep..."),
};

const struct DungeonDialogueStruct gUnknown_8105974 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You want lots of items?{EXTRA_MSG} As you wish.{WAIT_PRESS}\nI'll gather all the good items in the dungeon\nand bring them here.{EXTRA_MSG} Now...{WAIT_PRESS}\nHere goes!"),
};

const struct DungeonDialogueStruct gUnknown_8105A08 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You want a Friend Area?{EXTRA_MSG} ...But...{WAIT_PRESS}\nDon't you already have many Friend\nAreas?{EXTRA_MSG} I can't grant you that wish,\nso can you choose another one?{EXTRA_MSG} Er-hem...{WAIT_PRESS}\nThen...{WAIT_PRESS} I ask you again."),
};

const struct DungeonDialogueStruct gUnknown_8105AD4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You want a Friend Area?{EXTRA_MSG} As you wish.{WAIT_PRESS}\nNow...{WAIT_PRESS}\nHere goes!"),
};

const struct DungeonDialogueStruct gUnknown_8105B20 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I opened a new Friend Area\nfor you. It's yours to use!"),
};

const struct DungeonDialogueStruct gUnknown_8105B68 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{COLOR CYAN_M}{POKEMON_0}{RESET} obtained\n{CENTER_ALIGN}the Friend Area\n{CENTER_ALIGN}{COLOR GREEN_H}{MOVE_ITEM_0}{RESET}!"),
};

const struct DungeonDialogueStruct gUnknown_8105BA8 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" You want to be stronger?{EXTRA_MSG} As you wish.{WAIT_PRESS}\nNow...{WAIT_PRESS}\nHere goes!"),
};

const struct DungeonDialogueStruct gUnknown_8105BF4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I gathered up items from\nall over the dungeon that may make you \nstronger.{EXTRA_MSG} But don't use them now.{WAIT_PRESS}\nWhen you leave the {COLOR YELLOW_D}Wish Cave{RESET}, your\npowers go back to their original state.{EXTRA_MSG} So, you should only use\nthose items after you take them back.{EXTRA_MSG} I hope you keep working to\nbecome stronger!"),
};

const struct DungeonDialogueStruct gUnknown_8105D2C = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Something good?{WAIT_PRESS}\nThat's not very easy...{EXTRA_MSG} But I'll do my best!"),
};

const struct DungeonDialogueStruct gUnknown_8105D80 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" It's done..."),
};

const struct DungeonDialogueStruct gUnknown_8105D9C = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_JIRACHI,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" If you can get home safely,\nI think there will be something good\nwaiting for you.{WAIT_PRESS} Maybe.{WAIT_PRESS} Definitely."),
};

const struct DungeonDialogueStruct gJirachiReFightDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The master of this area isn't here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Why...{WAIT_PRESS}\nWhy have you come here...?{EXTRA_MSG} This is...{WAIT_PRESS}the {COLOR YELLOW_D}Silver Trench{RESET}.{WAIT_PRESS}\nThis is my territory!"),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_2 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LUGIA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" My name is {POKEMON_2}!{WAIT_PRESS}\nI am the guardian of the seas!"),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LUGIA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" To protect this sea,\nI have settled here..."),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LUGIA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" If you dare to challenge\nme..."),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_5 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LUGIA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" So be it!\nI will rise to your challenge!"),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_6 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_LUGIA,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Cast aside all thoughts!{WAIT_PRESS}\nUnleash every bit of your power!"),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_7 = {
    .type = 6,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}With your life at stake...{WAIT_PRESS}\n{CENTER_ALIGN}Bring it on!{WAIT_PRESS}\n{CENTER_ALIGN} {WAIT_PRESS}  "),
};

const struct DungeonDialogueStruct gLugiaPreFightDialogue_8 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_1 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gwoooooooooooh..................\n                         "),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ...My power...{WAIT_PRESS}\nis bursting...{EXTRA_MSG} My infinite...{WAIT_PRESS}\npower!"),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_3 = {
    .type = 5,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("Gwwwwwoooooooooooh!\n                         "),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" My duels against {POKEMON_3} left\nus both exhausted...{WAIT_PRESS}\nI took to a long and deep sleep...{EXTRA_MSG} All the time, I waited.\nWaited for my power to recover.{EXTRA_MSG} And now!{WAIT_PRESS}\nI am on the verge of regaining my power!"),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_5 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_KYOGRE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I am {POKEMON_2}!{WAIT_PRESS}\nThe lord of the sea!"),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_6 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_KYOGRE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Witness the destructive\nforce of my waves!"),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_7 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_KYOGRE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Marvel at my awesome\npower!"),
};

const struct DungeonDialogueStruct gKyogrePreFightDialogue_8 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gDeoxysPreFightDialogue_1 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = DIALOGUE_MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" ............{EXTRA_MSG} Where...{WAIT_PRESS}\nWhere am I?"),
};

const struct DungeonDialogueStruct gDeoxysPreFightDialogue_2 = {
    .type = 2,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_DEOXYS_NORMAL,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" There was a sudden explosion...{WAIT_PRESS}\nAnd I awakened to this...{EXTRA_MSG} What is this place?{EXTRA_MSG} I am {POKEMON_2}.{WAIT_PRESS}\nI came from space."),
};

const struct DungeonDialogueStruct gDeoxysPreFightDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_DEOXYS_NORMAL,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" If you know, tell me."),
};

const struct DungeonDialogueStruct gDeoxysPreFightDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_DEOXYS_NORMAL,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I must know...{WAIT_PRESS}\nwhat happened here!"),
};

const struct DungeonDialogueStruct gDeoxysPreFightDialogue_5 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_1 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}Oh?{WAIT_PRESS}\n{CENTER_ALIGN}There's someone there."),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_2 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}It's...{WAIT_PRESS}\n{CENTER_ALIGN}The Time Travel Pokémon {POKEMON_2}!"),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_3 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_2} wants to join the team."),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_4 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_2} joined the team! "),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_5 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_3} appears to\n{CENTER_ALIGN}be very happy!"),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_6 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}It's delighted to have\n{CENTER_ALIGN}joined the rescue team!"),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_7 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_0} turned down\n{CENTER_ALIGN}the offer to join."),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_8 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}Celebi is very disappointed."),
};

const struct DungeonDialogueStruct gCelebiJoinDialogue_9 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}{POKEMON_2} left\n{CENTER_ALIGN}dejectedly..."),
};

const u8 *const gPtrPurityForestAllowCelebiToJoinText =_("{CENTER_ALIGN}Allow {POKEMON_2}\n{CENTER_ALIGN}to join the team?");
const MenuItem gPurityForestAllowCelebiToJoinPrompt[] = {
    {_("Yes."), 1},
    {_("No."), 2},
    {NULL, -1},
};
const u8 *const gPtrPurityForestRefuseCelebiConfirmText =_("{CENTER_ALIGN}Are you sure?{WAIT_PRESS}\n{CENTER_ALIGN}You're sure you won't accept it?");
const MenuItem gPurityForestRefuseCelebiConfirmPrompt[] = {
    {_("Reconsider."), 1},
    {_("Refuse."), 2},
    {NULL, -1},
};
const struct DungeonDialogueStruct gCelebiJoinDialogue_10 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};

const u8 *const gUnknown_810665C =_("{CENTER_ALIGN}...............");
const u8 *const gUnknown_810668C =_("{CENTER_ALIGN}Someone has intruded\n{CENTER_ALIGN}upon the forest...");
const u8 *const gUnknown_81066D4 =_("{CENTER_ALIGN}The enfeebled flow of icy winds...\n{CENTER_ALIGN}Is the intrusion to blame?");
const u8 *const gUnknown_81066F0 =_("{CENTER_ALIGN}It must be stopped.");
const u8 *const gUnknown_810671C =_("{CENTER_ALIGN}For it is to protect the forest...");
const struct DungeonDialogueStruct gUnknown_8106720 = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}Defeat the opposing team to win!\n{CENTER_ALIGN}Be careful--your opponents are tough!"),
};

const struct DungeonDialogueStruct gMedichamRescueDialogue_1 = {
    .type = 0,
    .spriteId = 4,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEDICHAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Oh, my, my...\nI can't seem to find a way out..."),
};

const struct DungeonDialogueStruct gMedichamRescueDialogue_2 = {
    .type = 0,
    .spriteId = 4,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEDICHAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" What am I to do...?"),
};

const struct DungeonDialogueStruct gMedichamRescueDialogue_3 = {
    .type = 0,
    .spriteId = 2,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEDICHAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Oh!\nYou?!{EXTRA_MSG} ............{WAIT_PRESS}\nPerhaps...{EXTRA_MSG} You have come to rescue\nme?"),
};

const struct DungeonDialogueStruct gMedichamRescueDialogue_4 = {
    .type = 0,
    .spriteId = 1,
    .spritePlacementId = 13,
    .speciesId = MONSTER_MEDICHAM,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Yes, yes!\nI am so lucky!"),
};

const struct DungeonDialogueStruct gUnknown_810685C = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here."),
};

const struct DungeonDialogueStruct gSmeargleRescueDialogue_1 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SMEARGLE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Ohhh...\nI've lost my bearings...{WAIT_PRESS}\nWhere is this?"),
};

const struct DungeonDialogueStruct gSmeargleRescueDialogue_2 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SMEARGLE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" I can't get out...\nI'm hungry...{WAIT_PRESS}\nI'm in trouble..."),
};

const struct DungeonDialogueStruct gSmeargleRescueDialogue_3 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SMEARGLE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Oh!\nYou are?!"),
};

const struct DungeonDialogueStruct gSmeargleRescueDialogue_4 = {
    .type = 0,
    .spriteId = 0,
    .spritePlacementId = 13,
    .speciesId = MONSTER_SMEARGLE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _(" Did you maybe come to\nrescue me?{WAIT_PRESS}\nAm I glad to see you!"),
};

const struct DungeonDialogueStruct gUnknown_810697C = {
    .type = 4,
    .spriteId = 0,
    .spritePlacementId = 0,
    .speciesId = MONSTER_NONE,
    .allowType = DIALOGUE_ALLOW_ALL,
    .str = _("{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n{CENTER_ALIGN}It's time to go back."),
};


