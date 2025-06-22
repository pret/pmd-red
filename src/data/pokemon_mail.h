#include "rescue_team_info.h"

static const u8 * const sUnknown_80E8B94[7] = {
    _("　"),
    _("{ENVELOPE_CLOSED}"),
    _("{ICON_BLANK}"),
    _("{ENVELOPE_OPEN}"),
    _("{THANK_YOU_MAIL}"),
    _("{ICON_GO}"),
    _("{ICON_NEWS}"),
};

static const u8 * const sUnknown_80E8BCC[4] = {
    _("　"),
    _("Suspend"),
    _("Take Job"),
    _("Done"),
};

// Used in sub_803C1F0 for some reason
const u8 * const gMissionRankText[MAX_TEAM_RANKS] = {
    _("{COLOR DEFAULT}E{RESET}"),
    _("{COLOR GREEN}D{RESET}"),
    _("{COLOR GREEN}C{RESET}"),
    _("{COLOR CYAN}B{RESET}"),
    _("{COLOR CYAN}A{RESET}"),
    _("{COLOR RED}S{RESET}"),
    _("{STAR_BULLET}"),
};

static const u8 * const gMissionRewardText[6] = {
    _("%d {POKE}"),
    _("%d {POKE} + ?"),
    _("{COLOR GREEN}%s{RESET}"),
    _("{COLOR GREEN}%s{RESET} + ?"),
    _("Friend Area"),
    _("???"),
};

static const u8 * const gUnknown_80E8C98[15] = {
    _("Help!"),
    _("I can't get out!"),
    _("I'm in trouble..."),
    _("I'm scared!"),
    _("I can't seem to get out."),
    _("I'm lost."),
    _("I was attacked!"),
    _("I fainted..."),
    _("I'm not a fighter..."),
    _("I'm too tired to move."),
    _("I was KO'd..."),
    _("Where am I?"),
    _("I'm sad and lonely."),
    _("I can't get home!"),
    _("Help me!"),
};

static const u8 * const gUnknown_80E8DE4[13] = {
    _("I don't know how I did it, but I can't exit!"),
    _("I was attacked when I was sitting still!"),
    _("I'm simply no good at fighting."),
    _("I got lost in this dungeon!"),
    _("This dungeon is scary!"),
    _("Fighting the tough foe was a mistake..."),
    _("I've reached my limit..."),
    _("I'm close to fainting..."),
    _("I lost in a battle..."),
    _("I was done in..."),
    _("Whoa! It's too rough here..."),
    _("I can't move another step."),
    _("I'm famished..."),
};

static const u8 * const gUnknown_80E8FB0[13] = {
    _("Please, I need help!"),
    _("Someone!"),
    _("Someone, help!"),
    _("I feel faint... Please help..."),
    _("Why? Why is everyone attacking me?"),
    _("Where am I? Help!"),
    _("Wroooooaaar! Someone!"),
    _("My consciousness is slipping... Help..."),
    _("Rescue is requested!"),
    _("Someone, please help!"),
    _("Help!"),
    _("...Gasp! Waaaaaaaah!"),
    _("Aiyeeeeeeeeh!"),
};

static const u8 * const gUnknown_80E910C[10] = {
    _("Please help {COLOR YELLOW}%s{RESET}!"),
    _("{COLOR YELLOW}%s{RESET} needs help!"),
    _("Hurry, save {COLOR YELLOW}%s{RESET}!"),
    _("Failed to return."),
    _("Help!"),
    _("Somebody!"),
    _("I'm worried."),
    _("Hasn't come back."),
    _("Hurry!"),
    _("Disappearance!"),
};

static const u8 * const gUnknown_80E91D4[45] = {
    _("{COLOR YELLOW}%s{RESET} passed out from the heat!"),
    _("{COLOR YELLOW}%s{RESET} may be endangered!"),
    _("{COLOR YELLOW}%s{RESET} is still missing."),
    _("{COLOR YELLOW}%s{RESET} hasn't been heard from!"),
    _("{COLOR YELLOW}%s{RESET} can't swim!"),
    _("{COLOR YELLOW}%s{RESET} hasn't come back!"),
    _("{COLOR YELLOW}%s{RESET} might be unable to return."),
    _("{COLOR YELLOW}%s{RESET} may be facing danger!"),
    _("{COLOR YELLOW}%s{RESET} appears to be injured!"),
    _("{COLOR YELLOW}%s{RESET} went missing this morning!"),
    _("{COLOR YELLOW}%s{RESET} is too scared to move!"),
    _("{COLOR YELLOW}%s{RESET} may be confused!"),
    _("{COLOR YELLOW}%s{RESET} appears to be freezing!"),
    _("Trouble may have found {COLOR YELLOW}%s{RESET}!"),
    _("{COLOR YELLOW}%s{RESET} was paralyzed!"),
    _("{COLOR YELLOW}%s{RESET}'s whereabouts are unknown!"),
    _("I'm worried about {COLOR YELLOW}%s{RESET}!"),
    _("{COLOR YELLOW}%s{RESET} has been cornered!"),
    _("{COLOR YELLOW}%s{RESET}'s been gone a long time!"),
    _("{COLOR YELLOW}%s{RESET} is about to faint!"),
    _("{COLOR YELLOW}%s{RESET} may have fainted already!"),
    _("It appears as if {COLOR YELLOW}%s{RESET} can't escape!"),
    _("{COLOR YELLOW}%s{RESET} was attacked by assailants!"),
    _("{COLOR YELLOW}%s{RESET} hasn't reemerged!"),
    _("{COLOR YELLOW}%s{RESET} appears to be helpless!"),
    _("{COLOR YELLOW}%s{RESET} is stuck in a cave!"),
    _("{COLOR YELLOW}%s{RESET} appears to be trapped!"),
    _("Something happened to {COLOR YELLOW}%s{RESET}!"),
    _("{COLOR YELLOW}%s{RESET} was attacked, maybe!"),
    _("{COLOR YELLOW}%s{RESET} is running out of time!"),
    _("I got separated from {COLOR YELLOW}%s{RESET}."),
    _("Hurry, bring back {COLOR YELLOW}%s{RESET}."),
    _("{COLOR YELLOW}%s{RESET} is too hungry to move!"),
    _("{COLOR YELLOW}%s{RESET} is fighting all alone!"),
    _("I'm worried for {COLOR YELLOW}%s{RESET}'s safety!"),
    _("{COLOR YELLOW}%s{RESET} may have had an accident!"),
    _("{COLOR YELLOW}%s{RESET} appears to be lost!"),
    _("{COLOR YELLOW}%s{RESET} appears to be stuck!"),
    _("{COLOR YELLOW}%s{RESET} is lost!"),
    _("{COLOR YELLOW}%s{RESET} went the wrong way!"),
    _("{COLOR YELLOW}%s{RESET}'s been missing three days!"),
    _("{COLOR YELLOW}%s{RESET} can't walk anymore!"),
    _("I can't contact {COLOR YELLOW}%s{RESET}!"),
    _("I lost contact with {COLOR YELLOW}%s{RESET}!"),
    _("{COLOR YELLOW}%s{RESET} fell into a trap!"),
};

static const u8 * const gUnknown_80E9820[10] = {
    _("Please! Someone help!"),
    _("Please! I need help!"),
    _("Someone! Anyone?"),
    _("I don't care who it is! Please help!"),
    _("Help me!"),
    _("I'm pleading for help!"),
    _("Someone, help!"),
    _("Please send a rescue team!"),
    _("A rescue is urgently needed!"),
    _("Reward upon rescue!"),
};

static const u8 sUnknown_80E99C8[];
static const u8 sUnknown_80E9A0C[];
static const u8 sUnknown_80E9A54[];
static const u8 sUnknown_80E9A94[];
static const u8 sUnknown_80E9ACC[];
static const u8 sUnknown_80E9B18[];
static const u8 sUnknown_80E9B58[];
static const u8 sUnknown_80E9BAC[];
static const u8 sUnknown_80E9BFC[];
static const u8 sUnknown_80E9C38[];
static const u8 sUnknown_80E9C80[];
static const u8 sUnknown_80E9CC4[];
static const u8 sUnknown_80E9D04[];
static const u8 sUnknown_80E9D50[];
static const u8 sUnknown_80E9DA4[];
static const u8 sUnknown_80E9DFC[];
static const u8 sUnknown_80E9E40[];
static const u8 sUnknown_80E9E80[];
static const u8 sUnknown_80E9ED8[];
static const u8 sUnknown_80E9F24[];
static const u8 sUnknown_80E9F5C[];

// Also used in sub_803B600 and sub_803C3E0
const unkStruct_80E9920 gUnknown_80E9920[21] = {
    { MONSTER_BEEDRILL, MONSTER_WEEDLE, sUnknown_80E9F5C },
    { MONSTER_PIDGEOT, MONSTER_PIDGEY, sUnknown_80E9F24 },
    { MONSTER_RATICATE, MONSTER_RATTATA, sUnknown_80E9ED8 },
    { MONSTER_RAICHU, MONSTER_PICHU, sUnknown_80E9E80 },
    { MONSTER_CLEFABLE, MONSTER_CLEFFA, sUnknown_80E9E40 },
    { MONSTER_WIGGLYTUFF, MONSTER_IGGLYBUFF, sUnknown_80E9DFC },
    { MONSTER_CROBAT, MONSTER_ZUBAT, sUnknown_80E9DA4 },
    { MONSTER_VILEPLUME, MONSTER_ODDISH, sUnknown_80E9D50 },
    { MONSTER_POLIWRATH, MONSTER_POLIWAG, sUnknown_80E9D04 },
    { MONSTER_TOGETIC, MONSTER_TOGEPI, sUnknown_80E9CC4 },
    { MONSTER_AZUMARILL, MONSTER_AZURILL, sUnknown_80E9C80 },
    { MONSTER_URSARING, MONSTER_TEDDIURSA, sUnknown_80E9C38 },
    { MONSTER_DONPHAN, MONSTER_PHANPY, sUnknown_80E9BFC },
    { MONSTER_ELECTABUZZ, MONSTER_ELEKID, sUnknown_80E9BAC },
    { MONSTER_MAGMAR, MONSTER_MAGBY, sUnknown_80E9B58 },
    { MONSTER_TYRANITAR, MONSTER_LARVITAR, sUnknown_80E9B18 },
    { MONSTER_BEAUTIFLY, MONSTER_WURMPLE, sUnknown_80E9ACC },
    { MONSTER_AGGRON, MONSTER_ARON, sUnknown_80E9A94 },
    { MONSTER_FLYGON, MONSTER_TRAPINCH, sUnknown_80E9A54 },
    { MONSTER_WALREIN, MONSTER_SPHEAL, sUnknown_80E9A0C },
    { MONSTER_SWELLOW, MONSTER_TAILLOW, sUnknown_80E99C8 }
};

ALIGNED(4) static const u8 sUnknown_80E99C8[] = _(
    "Please look for Taillow!\n"
    "My baby is very timid, so I'm worried!");

ALIGNED(4) static const u8 sUnknown_80E9A0C[] = _(
    "Save my baby Spheal! My baby is easy to\n"
    "spot because she likes to roll!");

ALIGNED(4) static const u8 sUnknown_80E9A54[] = _(
    "Please find my little Trapinch!\n"
    "My baby is probably lying low!");

ALIGNED(4) static const u8 sUnknown_80E9A94[] = _(
    "Please find my Aron!\n"
    "He's my only child! Please help!");

ALIGNED(4) static const u8 sUnknown_80E9ACC[] = _(
    "My Wurmple went missing! Please look\n"
    "for the cute spikes on his rear end!");

ALIGNED(4) static const u8 sUnknown_80E9B18[] = _(
    "Please search for Larvitar!\n"
    "He loves to eat dirt! I need help!");

ALIGNED(4) static const u8 sUnknown_80E9B58[] = _(
    "My baby Magby is lost. I'm worried sick.\n"
    "She's a cheerful child who loves fire.");

ALIGNED(4) static const u8 sUnknown_80E9BAC[] = _(
    "My son can be wild with thunderbolts,\n"
    "but he's kindhearted. Please help!");

ALIGNED(4) static const u8 sUnknown_80E9BFC[] = _(
    "Please look for Phanpy!\n"
    "My son has a distinctive long nose!");

ALIGNED(4) static const u8 sUnknown_80E9C38[] = _(
    "Please find Teddiursa! My baby's head\n"
    "has a cute crescent mark! Help!");

ALIGNED(4) static const u8 sUnknown_80E9C80[] = _(
    "Please save my adorable Azurill!\n"
    "Watch for a round and bouncy tail!");

ALIGNED(4) static const u8 sUnknown_80E9CC4[] = _(
    "Help! Togepi's just a baby!\n"
    "I'm worried sick! Please help!");

ALIGNED(4) static const u8 sUnknown_80E9D04[] = _(
    "My baby Poliwag! He wandered off...\n"
    "He only just learned how to walk! Help!");

ALIGNED(4) static const u8 sUnknown_80E9D50[] = _(
    "Oddish disappeared from sight! She may be\n"
    "buried somewhere! Someone, please help!");

ALIGNED(4) static const u8 sUnknown_80E9DA4[] = _(
    "Please rescue Zubat! He's so young he\n"
    "can't even hang from cavern ceilings well!");

ALIGNED(4) static const u8 sUnknown_80E9DFC[] = _(
    "Please find Igglybuff! Oh, where did that\n"
    "child roll off to?! Oh!");

ALIGNED(4) static const u8 sUnknown_80E9E40[] = _(
    "Cleffa disappeared! Please let me know\n"
    "if you find my child!");

ALIGNED(4) static const u8 sUnknown_80E9E80[] = _(
    "Please rescue Pichu! He's a little cutie\n"
    "who can't charge power well yet. Please!");

ALIGNED(4) static const u8 sUnknown_80E9ED8[] = _(
    "Rattata is missing! My precious child!\n"
    "Please, won't someone help me?");

ALIGNED(4) static const u8 sUnknown_80E9F24[] = _(
    "Oh, my cute little Pidgey!\n"
    "Please, someone help!");

ALIGNED(4) static const u8 sUnknown_80E9F5C[] = _(
    "Please rescue Weedle!\n"
    "He's my son! Please!");

static const u8 sUnknown_80EA1A8[];
static const u8 sUnknown_80EA1FC[];
static const u8 sUnknown_80EA214[];
static const u8 sUnknown_80EA26C[];
static const u8 sUnknown_80EA2BC[];
static const u8 sUnknown_80EA30C[];
static const u8 sUnknown_80EA33C[];
static const u8 sUnknown_80EA384[];
static const u8 sUnknown_80EA398[];
static const u8 sUnknown_80EA3DC[];
static const u8 sUnknown_80EA41C[];
static const u8 sUnknown_80EA45C[];
static const u8 sUnknown_80EA4A0[];
static const u8 sUnknown_80EA4E4[];
static const u8 sUnknown_80EA51C[];
static const u8 sUnknown_80EA534[];
static const u8 sUnknown_80EA57C[];
static const u8 sUnknown_80EA5C4[];
static const u8 sUnknown_80EA614[];
static const u8 sUnknown_80EA650[];
static const u8 sUnknown_80EA698[];
static const u8 sUnknown_80EA6E4[];
static const u8 sUnknown_80EA730[];
static const u8 sUnknown_80EA784[];
static const u8 sUnknown_80EA7A8[];
static const u8 sUnknown_80EA7FC[];
static const u8 sUnknown_80EA84C[];
static const u8 sUnknown_80EA880[];
static const u8 sUnknown_80EA8D0[];
static const u8 sUnknown_80EA914[];
static const u8 sUnknown_80EA968[];
static const u8 sUnknown_80EA9A4[];
static const u8 sUnknown_80EA9F8[];
static const u8 sUnknown_80EAA34[];
static const u8 sUnknown_80EAA84[];
static const u8 sUnknown_80EAAC8[];
static const u8 sUnknown_80EAB10[];
static const u8 sUnknown_80EAB68[];
static const u8 sUnknown_80EABA8[];
static const u8 sUnknown_80EABE8[];
static const u8 sUnknown_80EAC38[];
static const u8 sUnknown_80EAC88[];
static const u8 sUnknown_80EACD4[];
static const u8 sUnknown_80EAD20[];
static const u8 sUnknown_80EAD50[];
static const u8 sUnknown_80EAD94[];
static const u8 sUnknown_80EADD0[];
static const u8 sUnknown_80EADFC[];
static const u8 sUnknown_80EAE44[];

// Also used in sub_803B628 and sub_803C45C
const unkStruct_80E9F8C gUnknown_80E9F8C[45] = {
    // Save my friend
    { MONSTER_EXEGGUTOR, MONSTER_DODRIO, sUnknown_80EAE44, sUnknown_80EADFC },
    { MONSTER_FEAROW, MONSTER_RHYDON, sUnknown_80EAE44, sUnknown_80EADD0 },
    { MONSTER_SHELLDER, MONSTER_CLAMPERL, sUnknown_80EAE44, sUnknown_80EAD94 },
    { MONSTER_MUK, MONSTER_SWALOT, sUnknown_80EAE44, sUnknown_80EAD50 },
    { MONSTER_MEOWTH, MONSTER_SKITTY, sUnknown_80EAE44, sUnknown_80EAD20 },
    { MONSTER_MAGIKARP, MONSTER_FEEBAS, sUnknown_80EAE44, sUnknown_80EACD4 },
    { MONSTER_WEEDLE, MONSTER_WURMPLE, sUnknown_80EAE44, sUnknown_80EAC88 },
    { MONSTER_CASCOON, MONSTER_SILCOON, sUnknown_80EAE44, sUnknown_80EAC38 },
    { MONSTER_TAILLOW, MONSTER_PIDGEY, sUnknown_80EAE44, sUnknown_80EABE8 },
    { MONSTER_VULPIX, MONSTER_NUMEL, sUnknown_80EAE44, sUnknown_80EABA8 },
    { MONSTER_IGGLYBUFF, MONSTER_CLEFFA, sUnknown_80EAE44, sUnknown_80EAB68 },
    { MONSTER_VENOMOTH, MONSTER_DUSTOX, sUnknown_80EAE44, sUnknown_80EAB10 },
    { MONSTER_VIGOROTH, MONSTER_PRIMEAPE, sUnknown_80EAE44, sUnknown_80EAAC8 },
    { MONSTER_POOCHYENA, MONSTER_GROWLITHE, sUnknown_80EAE44, sUnknown_80EAA84 },
    { MONSTER_BELLSPROUT, MONSTER_SHUCKLE, sUnknown_80EAE44, sUnknown_80EAA34 },
    { MONSTER_SEEL, MONSTER_SEALEO, sUnknown_80EAE44, sUnknown_80EA9F8 },
    { MONSTER_HYPNO, MONSTER_MR_MIME, sUnknown_80EAE44, sUnknown_80EA9A4 },
    { MONSTER_KRABBY, MONSTER_CORPHISH, sUnknown_80EAE44, sUnknown_80EA968 },
    { MONSTER_SNORLAX, MONSTER_SLAKING, sUnknown_80EAE44, sUnknown_80EA914 },
    { MONSTER_PINSIR, MONSTER_HERACROSS, sUnknown_80EAE44, sUnknown_80EA8D0 },
    { MONSTER_SNEASEL, MONSTER_ZANGOOSE, sUnknown_80EAE44, sUnknown_80EA880 },
    { MONSTER_AZURILL, MONSTER_TOGEPI, sUnknown_80EAE44, sUnknown_80EA84C },
    { MONSTER_DITTO, MONSTER_SUDOWOODO, sUnknown_80EAE44, sUnknown_80EA7FC },
    { MONSTER_TEDDIURSA, MONSTER_SPINDA, sUnknown_80EAE44, sUnknown_80EA7A8 },
    { MONSTER_SLOWPOKE, MONSTER_SLAKOTH, sUnknown_80EAE44, sUnknown_80EA784 },
    { MONSTER_NOCTOWL, MONSTER_MURKROW, sUnknown_80EAE44, sUnknown_80EA730 },
    { MONSTER_ROSELIA, MONSTER_BELLOSSOM, sUnknown_80EAE44, sUnknown_80EA6E4 },
    { MONSTER_DELIBIRD, MONSTER_PELIPPER, sUnknown_80EAE44, sUnknown_80EA698 },
    { MONSTER_RELICANTH, MONSTER_NINETALES, sUnknown_80EAE44, sUnknown_80EA650 },
    { MONSTER_HOPPIP, MONSTER_CHIMECHO, sUnknown_80EAE44, sUnknown_80EA614 },
    { MONSTER_MISDREAVUS, MONSTER_SHUPPET, sUnknown_80EAE44, sUnknown_80EA5C4 },
    { MONSTER_CORSOLA, MONSTER_LUVDISC, sUnknown_80EAE44, sUnknown_80EA57C },
    { MONSTER_TOGETIC, MONSTER_BLISSEY, sUnknown_80EAE44, sUnknown_80EA534 },
    // Save my love
    { MONSTER_NIDORAN_M, MONSTER_NIDORAN_F, sUnknown_80EA51C, sUnknown_80EA4E4 },
    { MONSTER_NIDORINO, MONSTER_NIDORINA, sUnknown_80EA51C, sUnknown_80EA4A0 },
    { MONSTER_NIDOKING, MONSTER_NIDOQUEEN, sUnknown_80EA51C, sUnknown_80EA45C },
    { MONSTER_TAUROS, MONSTER_MILTANK, sUnknown_80EA51C, sUnknown_80EA41C },
    { MONSTER_VOLBEAT, MONSTER_ILLUMISE, sUnknown_80EA51C, sUnknown_80EA3DC },
    { MONSTER_MINUN, MONSTER_PLUSLE, sUnknown_80EA51C, sUnknown_80EA398 },
    // Rescue my rival
    { MONSTER_ZANGOOSE, MONSTER_SEVIPER, sUnknown_80EA384, sUnknown_80EA33C },
    { MONSTER_HITMONLEE, MONSTER_HITMONCHAN, sUnknown_80EA384, sUnknown_80EA30C },
    { MONSTER_LUNATONE, MONSTER_SOLROCK, sUnknown_80EA384, sUnknown_80EA2BC },
    { MONSTER_OMANYTE, MONSTER_KABUTO, sUnknown_80EA384, sUnknown_80EA26C },
    { MONSTER_LILEEP, MONSTER_ANORITH, sUnknown_80EA384, sUnknown_80EA214 },
    // Help my brother
    { MONSTER_PICHU, MONSTER_PICHU, sUnknown_80EA1FC, sUnknown_80EA1A8 }
};

ALIGNED(4) static const u8 sUnknown_80EA1A8[] = _(
    "My little brother Pichu disappeared!\n"
    "I'm really worried! Someone, please help!");

ALIGNED(4) static const u8 sUnknown_80EA1FC[] = _("Please help my brother!");

ALIGNED(4) static const u8 sUnknown_80EA214[] = _(
    "We've been rivals with {COLOR YELLOW}%s{RESET} for\n"
    "generations. It can't suddenly end like this!");

ALIGNED(4) static const u8 sUnknown_80EA26C[] = _(
    "{COLOR YELLOW}%s{RESET} has been a rival since my\n"
    "ancestors' time. The rivalry can't end!");

ALIGNED(4) static const u8 sUnknown_80EA2BC[] = _(
    "{COLOR YELLOW}%s{RESET} can't leave without settling\n"
    "which one of us is better. Please help!");

ALIGNED(4) static const u8 sUnknown_80EA30C[] = _(
    "Please save {COLOR YELLOW}%s{RESET}.\n"
    "We owe each other a game!");

ALIGNED(4) static const u8 sUnknown_80EA33C[] = _(
    "Please rescue {COLOR YELLOW}%s{RESET}! We detest\n"
    "each other, but we need each other!");

ALIGNED(4) static const u8 sUnknown_80EA384[] = _("Rescue my rival!");

ALIGNED(4) static const u8 sUnknown_80EA398[] = _(
    "I can't live without {COLOR YELLOW}%s{RESET}!\n"
    "My heart is breaking! Please! Help!");

ALIGNED(4) static const u8 sUnknown_80EA3DC[] = _(
    "Please save {COLOR YELLOW}%s{RESET}!\n"
    "We're no good if we're not together!");

ALIGNED(4) static const u8 sUnknown_80EA41C[] = _(
    "Please save my {COLOR YELLOW}%s{RESET}! Now I\n"
    "know what {COLOR YELLOW}%s{RESET} means to me...");

ALIGNED(4) static const u8 sUnknown_80EA45C[] = _(
    "Please rescue {COLOR YELLOW}%s{RESET}! We\n"
    "promised our futures together! Please!");

ALIGNED(4) static const u8 sUnknown_80EA4A0[] = _(
    "Please rescue my precious {COLOR YELLOW}%s{RESET}!\n"
    "We're in love! Please help!");

ALIGNED(4) static const u8 sUnknown_80EA4E4[] = _(
    "Please! Please rescue {COLOR YELLOW}%s{RESET}!\n"
    "We're madly in love!");

ALIGNED(4) static const u8 sUnknown_80EA51C[] = _("Please save my love!");

ALIGNED(4) static const u8 sUnknown_80EA534[] = _(
    "We make each other happy--it's in our\n"
    "nature. Please save {COLOR YELLOW}%s{RESET}!");

ALIGNED(4) static const u8 sUnknown_80EA57C[] = _(
    "Please rescue {COLOR YELLOW}%s{RESET}! The beach\n"
    "feels empty without my usual friend...");

ALIGNED(4) static const u8 sUnknown_80EA5C4[] = _(
    "I feel lonely without {COLOR YELLOW}%s{RESET} to pull\n"
    "pranks and mess around with. Please help!");

ALIGNED(4) static const u8 sUnknown_80EA614[] = _(
    "Help {COLOR YELLOW}%s{RESET}, please!\n"
    "We often took strolls on the wind!");

ALIGNED(4) static const u8 sUnknown_80EA650[] = _(
    "Please save {COLOR YELLOW}%s{RESET}! We're both\n"
    "old-timers who are longtime friends!");

ALIGNED(4) static const u8 sUnknown_80EA698[] = _(
    "Please save {COLOR YELLOW}%s{RESET}. We've been in\n"
    "the delivery business for many years!");

ALIGNED(4) static const u8 sUnknown_80EA6E4[] = _(
    "I'm sad without {COLOR YELLOW}%s{RESET}'s company.\n"
    "We showed flowers to each other...");

ALIGNED(4) static const u8 sUnknown_80EA730[] = _(
    "Without {COLOR YELLOW}%s{RESET}, there's no one for\n"
    "me to play with in the dark! Please help!");

ALIGNED(4) static const u8 sUnknown_80EA784[] = _(
    "...Help... Please...\n"
    "Who was it?");

ALIGNED(4) static const u8 sUnknown_80EA7A8[] = _(
    "Please save {COLOR YELLOW}%s{RESET}. We're both alike\n"
    "in being kind of vacant and unpredictable!");

ALIGNED(4) static const u8 sUnknown_80EA7FC[] = _(
    "Without {COLOR YELLOW}%s{RESET} around, there's no\n"
    "one to heckle! Please break my boredom!");

ALIGNED(4) static const u8 sUnknown_80EA84C[] = _(
    "Please help {COLOR YELLOW}%s{RESET}!\n"
    "My tiny and round best friend!");

ALIGNED(4) static const u8 sUnknown_80EA880[] = _(
    "We promised to show each other how\n"
    "sharp our claws could be... Someone, help!");

ALIGNED(4) static const u8 sUnknown_80EA8D0[] = _(
    "I lock horns with {COLOR YELLOW}%s{RESET} for fun.\n"
    "I terribly miss doing that...");

ALIGNED(4) static const u8 sUnknown_80EA914[] = _(
    "Please help {COLOR YELLOW}%s{RESET}! We're both lazy,\n"
    "so we're comfortable around each other!");

ALIGNED(4) static const u8 sUnknown_80EA968[] = _(
    "I want to help {COLOR YELLOW}%s{RESET}!\n"
    "We both have a thing for pincers!");

ALIGNED(4) static const u8 sUnknown_80EA9A4[] = _(
    "We promised each other to perform magic\n"
    "and hypnosis shows together. Please help!");

ALIGNED(4) static const u8 sUnknown_80EA9F8[] = _(
    "Someone save {COLOR YELLOW}%s{RESET}--my friend\n"
    "and rival at ball juggling!");

ALIGNED(4) static const u8 sUnknown_80EAA34[] = _(
    "Please help {COLOR YELLOW}%s{RESET}! Our cries are\n"
    "identical! We can tell each other anything!");

ALIGNED(4) static const u8 sUnknown_80EAA84[] = _(
    "I can't play the biting game without my pal\n"
    "{COLOR YELLOW}%s{RESET}! Please help!");

ALIGNED(4) static const u8 sUnknown_80EAAC8[] = _(
    "{COLOR YELLOW}%s{RESET} is really noisy.\n"
    "But it's lonely without the racket... Sob...");

ALIGNED(4) static const u8 sUnknown_80EAB10[] = _(
    "Without {COLOR YELLOW}%s{RESET}, it's no fun playing\n"
    "with toxic powders! Someone, please help!");

ALIGNED(4) static const u8 sUnknown_80EAB68[] = _(
    "Please rescue {COLOR YELLOW}%s{RESET}!\n"
    "We've been friends since we were eggs!");

ALIGNED(4) static const u8 sUnknown_80EABA8[] = _(
    "Please help {COLOR YELLOW}%s{RESET}--a good\n"
    "friend who shares my love of fire!");

ALIGNED(4) static const u8 sUnknown_80EABE8[] = _(
    "{COLOR YELLOW}%s{RESET} and I are of the same height.\n"
    "We're lifelong friends! Please help!");

ALIGNED(4) static const u8 sUnknown_80EAC38[] = _(
    "We identify with each other because we\n"
    "both evolved from Wurmple. Please help!");

ALIGNED(4) static const u8 sUnknown_80EAC88[] = _(
    "Help! I'm friends with {COLOR YELLOW}%s{RESET}\n"
    "because we both evolve fast! Please help!");

ALIGNED(4) static const u8 sUnknown_80EACD4[] = _(
    "Help! {COLOR YELLOW}%s{RESET} isn't much now, but\n"
    "my friend is amazing after evolution!");

ALIGNED(4) static const u8 sUnknown_80EAD20[] = _(
    "Please rescue {COLOR YELLOW}%s{RESET}!\n"
    "We always play together!");

ALIGNED(4) static const u8 sUnknown_80EAD50[] = _(
    "Please rescue {COLOR YELLOW}%s{RESET}.\n"
    "I can't stand to see a sludge buddy hurt!");

ALIGNED(4) static const u8 sUnknown_80EAD94[] = _(
    "Please save my best friend {COLOR YELLOW}%s{RESET}!\n"
    "We're both bivalves!");

ALIGNED(4) static const u8 sUnknown_80EADD0[] = _(
    "Please save {COLOR YELLOW}%s{RESET},\n"
    "my drilling buddy!");

ALIGNED(4) static const u8 sUnknown_80EADFC[] = _(
    "This precious friend can chat separately\n"
    "with three heads. Please help!");

ALIGNED(4) static const u8 sUnknown_80EAE44[] = _("Please save my friend!");

// Escort Mission Text
static const u8 * const gUnknown_80EAE5C[4] = {
    _("Take me!"),
    _("I want to see {COLOR YELLOW}%s{RESET}."),
    _("Please take me with you!"),
    _("Escort me!"),
};

static const u8 * const gUnknown_80EAEB8[20] = {
    _("{COLOR YELLOW}%s{RESET} is waiting for me!"),
    _("We promised to meet in the dungeon!"),
    _("I want to meet with {COLOR YELLOW}%s{RESET}."),
    _("I'm worried about {COLOR YELLOW}%s{RESET}..."),
    _("I can't go by myself..."),
    _("I can't go on my own power..."),
    _("I'm too weak. It's not possible."),
    _("{COLOR YELLOW}%s{RESET} is waiting in the dungeon."),
    _("{COLOR YELLOW}%s{RESET} has been waiting forever..."),
    _("Hurry, {COLOR YELLOW}%s{RESET} is in trouble..."),
    _("I want to help {COLOR YELLOW}%s{RESET}!"),
    _("{COLOR YELLOW}%s{RESET} hasn't returned!"),
    _("{COLOR YELLOW}%s{RESET} may have fainted inside..."),
    _("I'm sick with worry..."),
    _("We haven't seen each other in a long time."),
    _("I have to go!"),
    _("We have to meet--whatever it takes!"),
    _("I don't care how--we must meet!"),
    _("I want to apologize to {COLOR YELLOW}%s{RESET}."),
    _("I'm close friends with {COLOR YELLOW}%s{RESET}!"),
};

static const u8 * const gUnknown_80EB198[4] = {
    _("Please take me to see {COLOR YELLOW}%s{RESET}!"),
    _("Please take me there with you!"),
    _("Please escort me there!"),
    _("Someone, please escort me!"),
};


static const u8 * const gUnknown_80EB220[6] = {
    _("Please! Take me to meet {COLOR YELLOW}%s{RESET}!"),
    _("Please escort me to my {COLOR YELLOW}%s{RESET}!"),
    _("Help me meet {COLOR YELLOW}%s{RESET}!"),
    _("I really want to meet {COLOR YELLOW}%s{RESET}!"),
    _("I'm so worried about {COLOR YELLOW}%s{RESET}..."),
    _("Without {COLOR YELLOW}%s{RESET}, I..."),
};

static const u8 * const gUnknown_80EB2F0[6] = {
    _("We're in love! Please, take me there!"),
    _("We belong together! Please escort me!"),
    _("We've promised our futures together."),
    _("This means everything to me!"),
    _("It's no good if we're not together!"),
    _("I'm very lonely! Please take me with you!"),
};

// Item Delivery Mission Text
static const u8 * const gUnknown_80EB3F8[22] = {
    _("Having one {COLOR GREEN}%s{RESET} is reassuring."),
    _("{COLOR GREEN}%s{RESET}--it's convenient to have."),
    _("{COLOR GREEN}%s{RESET} wanted after long search."),
    _("{COLOR GREEN}%s{RESET} wanted for exploration."),
    _("{COLOR GREEN}%s{RESET}--I'd love to utilize one!"),
    _("{COLOR GREEN}%s{RESET}--I can't leave without it."),
    _("{COLOR GREEN}%s{RESET} wanted as a charm."),
    _("{COLOR GREEN}%s{RESET}! Seeking in quantity!"),
    _("Help this {COLOR GREEN}%s{RESET} collector!"),
    _("I can't find one more {COLOR GREEN}%s{RESET}."),
    _("Hard-to-find {COLOR GREEN}%s{RESET} sought."),
    _("{COLOR GREEN}%s{RESET}--I get scared without it!"),
    _("I can't sleep without it: {COLOR GREEN}%s{RESET}."),
    _("{COLOR GREEN}%s{RESET} makes me strong."),
    _("{COLOR GREEN}%s{RESET}--it's my mom's favorite."),
    _("{COLOR GREEN}%s{RESET}'s texture is comforting."),
    _("{COLOR GREEN}%s{RESET} wanted to test effects."),
    _("{COLOR GREEN}%s{RESET} wanted for nostalgia."),
    _("I lost my {COLOR GREEN}%s{RESET}."),
    _("Wanted: my own {COLOR GREEN}%s{RESET}."),
    _("The item {COLOR GREEN}%s{RESET} is the in thing!"),
    _("Is it true about the {COLOR GREEN}%s{RESET}?"),
};


static const u8 * const gUnknown_80EB72C[22] = {
    _("Please! May I have one?"),
    _("Please trade me one!"),
    _("Please find one for me!"),
    _("Please give me one!"),
    _("Please share one with me!"),
    _("Please! I must have one delivered!"),
    _("Please help! Reward offered!"),
    _("Please! I'm offering a generous reward!"),
    _("I'm looking forward to your help!"),
    _("Please let me know if you find one!"),
    _("Please search for it!"),
    _("Please help! I'm counting on you!"),
    _("Please! I need your help!"),
    _("Please help! You're my only hope!"),
    _("Please share a little bit!"),
    _("Please share one with me!"),
    _("Please! I need some cooperation!"),
    _("Please help me out!"),
    _("Please! Please help me!"),
    _("Please help! I'm offering a reward!"),
    _("Please help! I'll make it worth your time!"),
    _("Please contact me if you find it!"),
};

static const u8 sNewFriendAreasText[];
static const u8 sNewFriendAreasHeadline[];
static const u8 sLucarioRankText[];
static const u8 sLucarioRankHeadline[];
static const u8 sBuriedRelicText[];
static const u8 sBuriedRelicHeadline[];
static const u8 sNewsText2[];
static const u8 sNewsHeadline2[];
static const u8 sNewsText1[];
static const u8 sNewsHeadline1[];
static const u8 sPelipperText[];
static const u8 sPelipperHeadline[];
static const u8 sLinkedProText2[];
static const u8 sLinkedProHeadline2[];
static const u8 sLinkedProText1[];
static const u8 sLinkedProHeadline1[];
static const u8 sSlakothText[];
static const u8 sSlakothHeadline[];
static const u8 sPitfallText[];
static const u8 sPitfallHeadline[];
static const u8 sSeaRescueText[];
static const u8 sSeaRescueHeadline[];
static const u8 sVileplumeText[];
static const u8 sVileplumeHeadline[];
static const u8 sRawstText[];
static const u8 sRawstHeadline[];
static const u8 sClubText[];
static const u8 sClubHeadline[];
static const u8 sChanseyText[];
static const u8 sChanseyHeadline[];
static const u8 sKabutoText[];
static const u8 sKabutoHeadline[];
static const u8 sSmeargleText[];
static const u8 sSmeargleHeadline[];
static const u8 sCastformText[];
static const u8 sCastformHeadline[];
static const u8 sGasText[];
static const u8 sGasHeadline[];
static const u8 sKeyItemText2[];
static const u8 sKeyItemHeadline2[];
static const u8 sKeyItemText1[];
static const u8 sKeyItemHeadline1[];
static const u8 sSwitchText[];
static const u8 sSwitchHeadline[];
static const u8 sKecleonText[];
static const u8 sKecleonHeadline[];
static const u8 sWeatherText2[];
static const u8 sWeatherHeadline2[];
static const u8 sWobbuffetText[];
static const u8 sWobbuffetHeadline[];
static const u8 sPechaText[];
static const u8 sPechaHeadline[];
static const u8 sWeatherText1[];
static const u8 sWeatherHeadline1[];
static const u8 sAzurillText[];
static const u8 sAzurillHeadline[];
static const u8 sKeyText[];
static const u8 sKeyHeadline[];
static const u8 sSweetText[];
static const u8 sSweetHeadline[];
static const u8 sRangeText[];
static const u8 sRangeHeadline[];
static const u8 sIQText[];
static const u8 sIQHeadline[];
static const u8 sTrapTileText[];
static const u8 sTrapTileHeadline[];
static const u8 sMakuhitaText[];
static const u8 sMakuhitaHeadline[];
static const u8 sMachineText[];
static const u8 sMachineHeadline[];
static const u8 sUltimateText[];
static const u8 sUltimateHeadline[];
static const u8 sGummiText[];
static const u8 sGummiHeadline[];
static const u8 sMoveTipsText[];
static const u8 sMoveTipsHeadline[];
static const u8 sAddMembersText[];
static const u8 sAddMembersHeadline[];
static const u8 sTeamMoveText[];
static const u8 sTeamMoveHeadline[];
static const u8 sWondersText[];
static const u8 sWondersHeadline[];
static const u8 sPollText[];
static const u8 sPollHeadline[];
static const u8 sLinkedEntryText3[];
static const u8 sLinkedEntryHeadline3[];
static const u8 sLinkedEntryText2[];
static const u8 sLinkedEntryHeadline2[];
static const u8 sLinkedEntryText1[];
static const u8 sLinkedEntryHeadline1[];
static const u8 sTypeText[];
static const u8 sTypeHeadline[];
static const u8 sDungeonText[];
static const u8 sDungeonHeadline[];
static const u8 sWonderText[];
static const u8 sWonderHeadline[];
static const u8 sMoveText[];
static const u8 sMoveHeadline[];
static const u8 sOptionsText[];
static const u8 sOptionsHeadline[];
static const u8 sDisasterText[];
static const u8 sDisasterHeadline[];
static const u8 sSeedText[];
static const u8 sSeedHeadline[];
static const u8 sHungerText[];
static const u8 sHungerHeadline[];
static const u8 sJobText[];
static const u8 sJobHeadline[];
static const u8 sBasicsText[];
static const u8 sBasicsHeadline[];
static const u8 sWelcomeText[];
static const u8 sWelcomeHeadline[];

static const PokemonMail sPokemonMail[NUM_POKEMON_MAIL] =
{
    [0] = { sWelcomeHeadline, sWelcomeText },
    [1] = { sBasicsHeadline, sBasicsText },
    [2] = { sJobHeadline, sJobText },
    [3] = { sHungerHeadline, sHungerText },
    [4] = { sSeedHeadline, sSeedText },
    [5] = { sDisasterHeadline, sDisasterText },
    [6] = { sOptionsHeadline, sOptionsText },
    [7] = { sMoveHeadline, sMoveText },
    [8] = { sWonderHeadline, sWonderText },
    [9] = { sDungeonHeadline, sDungeonText },
    [10] = { sTypeHeadline, sTypeText },
    [11] = { sLinkedEntryHeadline1, sLinkedEntryText1 },
    [12] = { sLinkedEntryHeadline2, sLinkedEntryText2 },
    [13] = { sLinkedEntryHeadline3, sLinkedEntryText3 },
    [14] = { sPollHeadline, sPollText },
    [15] = { sWondersHeadline, sWondersText },
    [16] = { sTeamMoveHeadline, sTeamMoveText },
    [17] = { sAddMembersHeadline, sAddMembersText },
    [18] = { sMoveTipsHeadline, sMoveTipsText },
    [19] = { sGummiHeadline, sGummiText },
    [20] = { sUltimateHeadline, sUltimateText },
    [21] = { sMachineHeadline, sMachineText },
    [22] = { sMakuhitaHeadline, sMakuhitaText },
    [23] = { sTrapTileHeadline, sTrapTileText },
    [24] = { sIQHeadline, sIQText },
    [25] = { sRangeHeadline, sRangeText },
    [26] = { sSweetHeadline, sSweetText },
    [27] = { sKeyHeadline, sKeyText },
    [28] = { sAzurillHeadline, sAzurillText },
    [29] = { sWeatherHeadline1, sWeatherText1 },
    [30] = { sPechaHeadline, sPechaText },
    [31] = { sWobbuffetHeadline, sWobbuffetText },
    [32] = { sWeatherHeadline2, sWeatherText2 },
    [33] = { sKecleonHeadline, sKecleonText },
    [34] = { sSwitchHeadline, sSwitchText },
    [35] = { sKeyItemHeadline1, sKeyItemText1 },
    [36] = { sKeyItemHeadline2, sKeyItemText2 },
    [37] = { sGasHeadline, sGasText },
    [38] = { sCastformHeadline, sCastformText },
    [39] = { sSmeargleHeadline, sSmeargleText },
    [40] = { sKabutoHeadline, sKabutoText },
    [41] = { sChanseyHeadline, sChanseyText },
    [42] = { sClubHeadline, sClubText },
    [43] = { sRawstHeadline, sRawstText },
    [44] = { sVileplumeHeadline, sVileplumeText },
    [45] = { sSeaRescueHeadline, sSeaRescueText },
    [46] = { sPitfallHeadline, sPitfallText },
    [47] = { sSlakothHeadline, sSlakothText },
    [48] = { sLinkedProHeadline1, sLinkedProText1 },
    [49] = { sLinkedProHeadline2, sLinkedProText2 },
    [50] = { sPelipperHeadline, sPelipperText },
    [51] = { sNewsHeadline1, sNewsText1 },
    [52] = { sNewsHeadline2, sNewsText2 },
    [53] = { sBuriedRelicHeadline, sBuriedRelicText },
    [54] = { sLucarioRankHeadline, sLucarioRankText },
    [55] = { sNewFriendAreasHeadline, sNewFriendAreasText }
};

ALIGNED(4) static const u8 sNewFriendAreasText[] = _(
     "The Wigglytuff Club has added new Friend\n"
     "Areas for sale!\n"
     "Rescue Teams are urged to check with\n"
     "Wigglytuff for what is available.\n"
     "By adding to your Friend Areas, you can\n"
     "recruit Pokémon that wouldn't join your\n"
     "rescue team before!");

ALIGNED(4) static const u8 sNewFriendAreasHeadline[] = _("New Friend Areas!");

ALIGNED(4) static const u8 sLucarioRankText[] = _(
    "Congratulations! Your team has attained\n"
    "the Lucario Rank--the top rank among\n"
    "rescue teams! In commemoration of your\n"
    "fantastic achievement, we award you the\n"
    "Lucario Statue, crafted after the legendary\n"
    "rescue team leader.\n"
    "Keep working for world peace!\n"
    "   - Pokémon Rescue Organization -");

ALIGNED(4) static const u8 sLucarioRankHeadline[] = _("Congratulations - Lucario Rank!");

ALIGNED(4) static const u8 sBuriedRelicText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Mystery Ruin Found Underground!{RESET}\n"
    "Its site had been hidden by the crater of a\n"
    "meteor strike in ancient times. The Buried\n"
    "Relic is thought to date back beyond\n"
    "recorded history. There are rumors of\n"
    "treasures... And perhaps even Pokémon\n"
    "that lived in ancient times. The Buried\n"
    "Relic is the main topic in Pokémon Square.");

ALIGNED(4) static const u8 sBuriedRelicHeadline[] = _("Buried Relic Discovered!");

ALIGNED(4) static const u8 sNewsText2[] = _(
    "{CENTER_ALIGN}{COLOR CYAN}{POKEMON_0} Innocent! Part 2{RESET}\n"
    "{COLOR GREEN}Quote from Charizard on the scene:{RESET}\n"
    "“That's what I thought right from\n"
    "the start, hahaha!”\n"
    "{COLOR GREEN}Quote from Tyranitar on the scene:{RESET}\n"
    "“That muckraking Gengar...\n"
    "He's not getting away with this!\n"
    "He'd better be ready for it!”");

ALIGNED(4) static const u8 sNewsHeadline2[] = _("Pokémon News Extra 2");

ALIGNED(4) static const u8 sNewsText1[] = _(
    "{CENTER_ALIGN}{COLOR CYAN}{POKEMON_0} Innocent! Part 1{RESET}\n"
    "{POKEMON_1} met with Ninetales on {COLOR RED}Mt. Freeze{RESET}.\n"
    "Ninetales testified that {POKEMON_0} was\n"
    "not the human that appeared in the legend.\n"
    "As a result, Gengar's claims were found to\n"
    "be malicious lies.\n"
    "{COLOR GREEN}The clearly dismayed Gengar's quote:{RESET}\n"
    "“Ugegegegegegegegegegegeh!”");

ALIGNED(4) static const u8 sNewsHeadline1[] = _("Pokémon News Extra 1");

ALIGNED(4) static const u8 sPelipperText[] = _(
    "Yo! Amigo! It's awesome you're back!\n"
    "I'll be delivering mail to you again!\n"
    "I've been looking forward to this with\n"
    "my bill outstretched!\n"
    "I'll deliver tons of mail, so you'd better\n"
    "be ready, amigo!\n\n"
    " - The wandering postal carrier, Pelipper -");

ALIGNED(4) static const u8 sPelipperHeadline[] =_("A Letter from Pelipper");

ALIGNED(4) static const u8 sLinkedProText2[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Try These Linked Moves to KO Foes!{RESET}\n\n"
    "Psyduck\n"
    "{COLOR GREEN}Confusion{RESET} + {COLOR GREEN}Disable{RESET}\n"
    "Totodile\n"
    "{COLOR GREEN}Bite{RESET} + {COLOR GREEN}Scary Face{RESET}\n"
    "Cyndaquil\n"
    "{COLOR GREEN}Flame Wheel{RESET} + {COLOR GREEN}Smokescreen{RESET}{EXTRA_MSG}"
    "Pikachu\n"
    "{COLOR GREEN}Thunderbolt{RESET} + {COLOR GREEN}Double Team{RESET}\n"
    "Skitty\n"
    "{COLOR GREEN}Tail Whip{RESET} + {COLOR GREEN}Doubleslap{RESET}");

ALIGNED(4) static const u8 sLinkedProHeadline2[] =_("#50 Linked Moves Pro Level 2");

ALIGNED(4) static const u8 sLinkedProText1[] = _(
    "{CENTER_ALIGN COLOR YELLOW}These Linked Move Combinations{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}Can Be Devastating!{RESET}\n\n"
    "Bulbasaur\n"
    "{COLOR GREEN}Razor Leaf{RESET} + {COLOR GREEN}Sleep Powder{RESET}\n"
    "Chikorita\n"
    "{COLOR GREEN}Body Slam{RESET} + {COLOR GREEN}Reflect{RESET}{EXTRA_MSG}"
    "Treecko\n"
    "{COLOR GREEN}Screech{RESET} + {COLOR GREEN}Pound{RESET}\n"
    "Machop\n"
    "{COLOR GREEN}Focus Energy{RESET} + {COLOR GREEN}Karate Chop{RESET}\n"
    "Cubone\n"
    "{COLOR GREEN}Tail Whip{RESET} + {COLOR GREEN}Bonemerang{RESET}");

ALIGNED(4) static const u8 sLinkedProHeadline1[] = _("#49 Linked Moves Pro Level 1");

ALIGNED(4) static const u8 sSlakothText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Relief for Delicate Souls Who Can't{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}Sleep with Different Pillows!{RESET}\n"
    "Insomniacs rejoiced over the announcement\n"
    "of the Slakoth Pillow, which is said to\n"
    "induce sleepiness just by seeing it.\n"
    "Already the inventor is swamped with\n"
    "inquiries from all over. However,\n"
    "production is said to be not yet ready.");

ALIGNED(4) static const u8 sSlakothHeadline[] = _("#48 Slakoth Pillows for Insomnia!");

ALIGNED(4) static const u8 sPitfallText[] = _(
    "As a result of the natural disasters,\n"
    "there have been many reports of Pitfall\n"
    "Traps appearing in dungeons.\n"
    "However, there also appear to be pitfalls\n"
    "made by Pokémon that are not harmful.\n"
    "The latter are thought to be made by\n"
    "foraging Swinub. Some even turn out to\n"
    "be hot springs that erupt occasionally.");

ALIGNED(4) static const u8 sPitfallHeadline[] = _("#47 Beware of Pitfalls");

ALIGNED(4) static const u8 sSeaRescueText[] = _(
    "A high-seas rescue in the {COLOR RED}Stormy Sea{RESET} by\n"
    "{COLOR CYAN}Team Sea Dragons{RESET} ended yesterday with\n"
    "the successful recovery of Tentacool.\n"
    "The client, Corsola, is said to be delighted\n"
    "by the outcome.\n"
    "Tentacool stated, “I didn't realize how far\n"
    "I'd been washed out to sea.”\n"
    "The {COLOR RED}Stormy Sea{RESET} is unforgiving!");

ALIGNED(4) static const u8 sSeaRescueHeadline[] = _("#46 Sea Rescue a Success!");

ALIGNED(4) static const u8 sVileplumeText[] = _(
    "Vileplume are widely recognized for \n"
    "their massive flower. However, few dare\n"
    "to approach Vileplume because they\n"
    "scatter clouds of allergy-inducing\n"
    "pollen. Vileplume complain that they tire\n"
    "very easily because the flower's weight\n"
    "makes their head heavy.");

ALIGNED(4) static const u8 sVileplumeHeadline[] = _("#45 Vileplume's Weighty Problem");

ALIGNED(4) static const u8 sRawstText[] = _(
    "Research has revealed that {COLOR GREEN}Rawst Berries{RESET}\n"
    "found in dungeons are usually unripened\n"
    "and colored green. When ripe, they turn a\n"
    "sky blue color. An unripened one is easier\n"
    "to eat, however, because it has not yet\n"
    "turned bitter. It is known to heal all\n"
    "burns.");

ALIGNED(4) static const u8 sRawstHeadline[] = _("#44 Rawst Berry's Effect");

ALIGNED(4) static const u8 sClubText[] = _(
    "We proudly announce the foundation of\n"
    "the Red & Blue Fan Club, an organization\n"
    "for supporting Pokémon rescue teams.\n"
    "We are currently recruiting new members.\n"
    "Won't you join and throw your support\n"
    "behind our hard-working rescue heroes?\n\n"
    "  - Plusle and Minun -");

ALIGNED(4) static const u8 sClubHeadline[] = _("#43 Fan Club Seeks Members!");

ALIGNED(4) static const u8 sChanseyText[] = _(
    "As a special treat, I'll share a simple\n"
    "way to tell fortunes with you!\n"
    "The key is the first thing you find in the\n"
    "day's first dungeon.\n"
    "If it's money, you'll be sure to make more.\n"
    "If it's a Berry, your health luck is good.\n"
    "If it's an Apple, you're super lucky!\n"
    "  - Chansey -");

ALIGNED(4) static const u8 sChanseyHeadline[] = _("#42 Chansey's Fortune-Telling");

ALIGNED(4) static const u8 sKabutoText[] = _(
    "One of our oldest residents claims to feel\n"
    "rejuvenated. Kabuto reportedly had an\n"
    "encounter with Relicanth in which both\n"
    "parties reminisced about the “old days.”\n"
    "However, even Kabuto could not keep up\n"
    "with Relicanth's tales from a hundred\n"
    "million years ago. Kabuto stated, “It\n"
    "made me feel young talking to Relicanth.”");

ALIGNED(4) static const u8 sKabutoHeadline[] = _("#41 Kabuto Feels Young Again!");

ALIGNED(4) static const u8 sSmeargleText[] = _(
    "Smeargle, the artist known for his unique\n"
    "artistic vision, had a windfall day as one\n"
    "of his paintings was auctioned for 300\n"
    "million {POKE} yesterday. The auctioned\n"
    "artwork was one of Smeargle's signature\n"
    "works from early in his career.");

ALIGNED(4) static const u8 sSmeargleHeadline[] = _("#40 Smeargle Painting Auctioned!");

ALIGNED(4) static const u8 sCastformText[] = _(
    "Today, the weather over Pokémon\n"
    "Square promises to be clear with no\n"
    "chance of showers.\n"
    "Other regions can expect showers followed\n"
    "by clouds. There may be sun breaks\n"
    "depending on the day's moods.");

ALIGNED(4) static const u8 sCastformHeadline[] = _("#39 Castform's Daily Weather");

ALIGNED(4) static const u8 sGasText[] = _(
    "Reports of a noxious gas leak caused\n"
    "widespread chaos in the {COLOR YELLOW_D}Sinister Woods{RESET}.\n"
    "Specialists speculate that the recent\n"
    "natural disasters are to blame. However,\n"
    "some also blame {COLOR CYAN}Team Koffing{RESET}'s training\n"
    "in the area for the foul-smelling gas.\n"
    "The answer, apparently, is blowing in the\n"
    "wind.");

ALIGNED(4) static const u8 sGasHeadline[] = _("#38 Noxious Gas Leak?!");

ALIGNED(4) static const u8 sKeyItemText2[] = _(
    "{CENTER_ALIGN COLOR YELLOW}When Used Somewhere Special...{RESET}\n"
    "Eevee and Water Stone, Fire Stone,\n"
    "Thunderstone, or...\n"
    "Exeggcute and Leaf Stone...\n"
    "Onix, Metal Coat, and Link Cable...\n"
    "There appear to be many others!");

ALIGNED(4) static const u8 sKeyItemHeadline2[] = _("#37 Key Items for Pokémon 2");

ALIGNED(4) static const u8 sKeyItemText1[] = _(
    "{CENTER_ALIGN COLOR YELLOW}When Used Somewhere Special...{RESET}\n"
    "Sunkern and Sun Stone...\n"
    "Skitty and Moon Stone...\n"
    "Growlithe and Fire Stone...\n"
    "Shellder and Water Stone...\n"
    "Clamperl and Deepseatooth...\n"
    "There appear to be many others!");

ALIGNED(4) static const u8 sKeyItemHeadline1[] = _("#36 Key Items for Pokémon 1");

ALIGNED(4) static const u8 sSwitchText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Power Up Combination Attacks!{RESET}\n"
    "Some dungeons allow rescue teams to\n"
    "switch leaders on the spot for doing\n"
    "combination attacks and so on.\n"
    "When you enter a dungeon, open the menu,\n"
    "choose the Pokémon you want as the\n"
    "leader under {COLOR YELLOW}Team{RESET}, then select the\n"
    "command {COLOR YELLOW}Leader{RESET}.");

ALIGNED(4) static const u8 sSwitchHeadline[] = _("#35 Switching Leaders");

ALIGNED(4) static const u8 sKecleonText[] = _(
    "There have been numerous reports that\n"
    "the older of the Kecleon merchants in\n"
    "Pokémon Square occasionally goes\n"
    "missing. Some residents claim, “He's\n"
    "greedy. He must be off doing business\n"
    "somewhere.” His younger brother denies\n"
    "such claims: “He wouldn't get free items\n"
    "in dungeons and try to sell them...”");

ALIGNED(4) static const u8 sKecleonHeadline[] = _("#34 Where Is Kecleon?");

ALIGNED(4) static const u8 sWeatherText2[] = _(
    "Clear: Pleasant weather.\n"
    "Hail: Regularly inflicts damage,\n"
    "except on the Ice type.\n"
    "Fog: Turns the status of all Pokémon on\n"
    "the floor to Mud Sport.\n"
    "Blizzard: Boosts the movement speed of\n"
    "Ice-type Pokémon by one level.");

ALIGNED(4) static const u8 sWeatherHeadline2[] = _("#33 Dungeons and Weather 2");

ALIGNED(4) static const u8 sWobbuffetText[] = _(
    "Earlier today, Wobbuffet reportedly\n"
    "wobbled the wrong way and wandered off.\n"
    "It had to be rescued by the famous\n"
    "{COLOR CYAN}Team Hydro{RESET}.\n"
    "Fortunately, the wayward wanderer\n"
    "Wobbuffet was only wobbly and otherwise\n"
    "unharmed.");

ALIGNED(4) static const u8 sWobbuffetHeadline[] = _("#32 Wobbly Wobbuffet Wanders!");

ALIGNED(4) static const u8 sPechaText[] = _(
    "Among rescue teams, there is growing\n"
    "demand for equipment that is not only\n"
    "practical, but also fashionably appealing.\n"
    "The pink {COLOR GREEN}Pecha Scarf{RESET} is especially popular.\n"
    "Even the {COLOR CYAN}Kecleon Shop{RESET} is having trouble\n"
    "keeping it in stock.\n"
    "If you're lucky enough to spot one, make a\n"
    "beeline for it!");

ALIGNED(4) static const u8 sPechaHeadline[] = _("#31 Pecha Scarf--Top Popularity!");

ALIGNED(4) static const u8 sWeatherText1[] = _(
    "Sunny: Boosts Fire-type moves, and\n"
    "weakens Water-type moves.\n"
    "Sandstorm: Regularly inflicts damage\n"
    "except on Ground, Rock, and Steel types.\n"
    "Cloudy: All moves and attacks, excluding\n"
    "the Normal type, are weakened.\n"
    "Rain: Boosts Water-type moves, and\n"
    "weakens Fire. Prevents explosions.");

ALIGNED(4) static const u8 sWeatherHeadline1[] = _("#30 Dungeons and Weather 1");

ALIGNED(4) static const u8 sAzurillText[] = _(
    "With a simple act of courage, Azurill\n"
    "became a hero despite being small in size.\n"
    "Azurill came across Slowpoke, who had\n"
    "fallen into a pond. Our hero's tail, thrown\n"
    "at the struggling Slowpoke, saved a sure\n"
    "drowning! Slowpoke claimed to have\n"
    "entirely forgotten having the ability to\n"
    "swim capably.");

ALIGNED(4) static const u8 sAzurillHeadline[] = _("#29 Azurill--the Little Hero!");

ALIGNED(4) static const u8 sKeyText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Head Out to the Desert Region!{RESET}\n"
    "If you've been wondering what lies behind\n"
    "the mysterious locked doors of the {COLOR YELLOW_D}Solar\n"
    "Cave{RESET}, there's been a breakthrough!\n"
    "Reports indicate the door keys are easily\n"
    "found in the {COLOR YELLOW_D}Desert Region{RESET}. Explorers are\n"
    "advised to compose teams with Pokémon\n"
    "adapted to the desert environment.");

ALIGNED(4) static const u8 sKeyHeadline[] = _("#28 The Key");

ALIGNED(4) static const u8 sSweetText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Feel a Little Envious?{RESET}\n"
    "Teddiursa is often seen licking its paws\n"
    "that have soaked up sweet honey. While it\n"
    "may be sticky shaking paws with\n"
    "Teddiursa, one can't help but feel a\n"
    "twinge of envy.");

ALIGNED(4) static const u8 sSweetHeadline[] = _("#27 Sweet Hands!");

ALIGNED(4) static const u8 sRangeText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}All Moves Have Effective Ranges{RESET}\n"
    "Moves that affect an entire room have a\n"
    "range of two tiles in a corridor. The move\n"
    "{COLOR GREEN}Growl{RESET}, which lowers the Attack stat of\n"
    "foes in a room, will reach two tiles away\n"
    "in a corridor, for example. If, however,\n"
    "the visibility is limited to just one tile,\n"
    "the range of moves will also be limited.");

ALIGNED(4) static const u8 sRangeHeadline[] = _("#26 The Range of Moves");

ALIGNED(4) static const u8 sIQText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Make Your Explorations Easier by{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}Boosting the IQ of Team Members!{RESET}\n"
    "Eating Gummis boosts the IQ of Pokémon.\n"
    "Upon reaching certain IQ levels, a Pokémon\n"
    "learns IQ Skills that can be very helpful\n"
    "(for example, learning to seek out foes\n"
    "with type disadvantages). Check\n"
    "the IQ Skills of your team members!");

ALIGNED(4) static const u8 sIQHeadline[] = _("#25 IQ");

ALIGNED(4) static const u8 sTrapTileText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}New Types of Floor Tiles?{RESET}\n"
    "There have been numerous reports of new\n"
    "floor tiles other than Wonder Tiles.\n"
    "Believed to have been made by the recent\n"
    "natural disasters, these floor tiles remain\n"
    "hidden until they are stepped on. They then\n"
    "trigger a variety of traps. Rescue teams\n"
    "are urged to use extreme caution.");

ALIGNED(4) static const u8 sTrapTileHeadline[] = _("#24 New Floor Tiles?");

ALIGNED(4) static const u8 sMakuhitaText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Study Type Matchups{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}at the Makuhita Dojo!{RESET}\n"
    "At the Makuhita Dojo, one can learn how\n"
    "Pokémon type matchups affect battles.\n"
    "It's because the dojo's training rooms are\n"
    "divided by type. For example, in the {COLOR YELLOW_D}Fire\n"
    "Maze{RESET}, there are only Fire-type Pokémon.\n"
    "Try move types to see what works best!");

ALIGNED(4) static const u8 sMakuhitaHeadline[] = _("#23 Train at the Makuhita Dojo!");

ALIGNED(4) static const u8 sMachineText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}New Types of Machines Discovered?{RESET}\n"
    "In a recently discovered cave, explorers\n"
    "found unique types of Technical Machines.\n"
    "They apparently do not break after a single\n"
    "use. Further studies are said to be under\n"
    "consideration by the authorities.\n"
    "In related news, the cave is to be named\n"
    "the {COLOR YELLOW_D}Solar Cave{RESET}.");

ALIGNED(4) static const u8 sMachineHeadline[] = _("#22 New Types of Machines?");

ALIGNED(4) static const u8 sUltimateText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}The Ultimate Dungeon{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}Challenges You to Do Your Best!{RESET}\n"
    "Somewhere in the world, there supposedly\n"
    "is an incredibly tough dungeon. One must\n"
    "enter alone at Level 1, and without any\n"
    "items. No one has ever completed the\n"
    "challenge. It is considered a test not of\n"
    "power, but of intelligence and wits.");

ALIGNED(4) static const u8 sUltimateHeadline[] = _("#21 The Ultimate Dungeon");

ALIGNED(4) static const u8 sGummiText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Gummis That Make You Smart{RESET}\n"
    "Research has revealed that popular Gummi\n"
    "treats not only enhance intelligence, they\n"
    "also have different effects depending on\n"
    "type. Share Gummis with your friends and\n"
    "get smarter for your adventures! In\n"
    "dungeons, throw them at your friends.\n"
    "Use them in Friend Areas and...?");

ALIGNED(4) static const u8 sGummiHeadline[] = _("#20 Secrets of the Gummi");

ALIGNED(4) static const u8 sMoveTipsText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Moving Diagonally{RESET}\n"
    "Move diagonally to avoid foes!\n"
    "Keeping {R_BUTTON}"
    " pressed, use\n"
    "{DPAD} to move diagonally.\n"
    "{CENTER_ALIGN COLOR YELLOW}Changing Direction{RESET}\n"
    "It's also very important to change\n"
    "directions without moving. Check Hints to\n"
    "see how you can do this maneuver!");

ALIGNED(4) static const u8 sMoveTipsHeadline[] = _("#19 Important Moving Tips");

ALIGNED(4) static const u8 sAddMembersText[] = _(
    "If you want to enlarge your rescue team,\n"
    "you must first get Friend Areas. When\n"
    "a Pokémon that can live in an obtained\n"
    "Friend Area is defeated, it may ask to\n"
    "join your rescue team. Add to your\n"
    "Friend Areas so you can recruit more\n"
    "members! Incidentally, you may take no\n"
    "more than three friends into a dungeon.");

ALIGNED(4) static const u8 sAddMembersHeadline[] = _("#18 Adding Team Members");

ALIGNED(4) static const u8 sTeamMoveText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Use Team Members Effectively!{RESET}\n"
    "When you're fighting in a dungeon, it's\n"
    "important to use your team members. If\n"
    "attacked from the side, move horizontally.\n"
    "If attacked from above or below, move\n"
    "vertically. That way, you can have several\n"
    "Pokémon fighting a single foe. Change\n"
    "Tactics if members don't move properly.");

ALIGNED(4) static const u8 sTeamMoveHeadline[] = _("#17 Moving as a Team");

ALIGNED(4) static const u8 sWondersText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}The Seven Wonders of Pokémon?{RESET}\n"
    "The mysterious feet of Diglett.\n"
    "What is inside Forretress's shell.\n"
    "The intelligence of Girafarig's tail.\n"
    "Arbok's variety of patterns.\n"
    "We await submissions from readers on\n"
    "other Pokémon mysteries!\n"
    "  - Mystery Hunter Team -");

ALIGNED(4) static const u8 sWondersHeadline[] = _("#16 Seven Wonders of Pokémon");

ALIGNED(4) static const u8 sPollText[] = _(
    "{COLOR YELLOW}First{MOVE_X_POSITION}{50}Gravelerock{RESET}\n"
    "{COLOR YELLOW}Second{MOVE_X_POSITION}{50}Oran Berry{RESET}\n"
    "In a nationwide survey involving rescue\n"
    "teams, the most popular item was found to\n"
    "be {COLOR GREEN}Gravelerocks{RESET}. According to Sudowoodo\n"
    "of {COLOR CYAN}Team Fakers{RESET}, “It lets you attack\n"
    "from far away. It's invaluable.” The next\n"
    "most popular item was {COLOR GREEN}Oran Berries{RESET}.");

ALIGNED(4) static const u8 sPollHeadline[] = _("#15 Poll: Top Two Items");

ALIGNED(4) static const u8 sLinkedEntryText3[] = _(
    "{CENTER_ALIGN COLOR YELLOW}These Are the Final Linked Moves{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}We Recommend in the Entry Level!{RESET}\n"
    "{COLOR RED}Electric and Water Types{RESET}\n"
    "Pikachu\n"
    "{COLOR GREEN}Thundershock{RESET} + {COLOR GREEN}Growl{RESET}\n"
    "Squirtle\n"
    "{COLOR GREEN}Tail Whip{RESET} + {COLOR GREEN}Tackle{RESET}{EXTRA_MSG}Totodile\n"
    "{COLOR GREEN}Leer{RESET} + {COLOR GREEN}Scratch{RESET}\n"
    "Mudkip\n"
    "{COLOR GREEN}Water Gun{RESET} + {COLOR GREEN}Mud-Slap{RESET}\n"
    "Psyduck\n"
    "{COLOR GREEN}Tail Whip{RESET} + {COLOR GREEN}Scratch{RESET}");

ALIGNED(4) static const u8 sLinkedEntryHeadline3[] = _("#14 Linked Moves Entry Level 3");

ALIGNED(4) static const u8 sLinkedEntryText2[] = _(
    "{COLOR RED}Fire and Normal Types{RESET}\n"
    "Charmander\n"
    "{COLOR GREEN}Ember{RESET} + {COLOR GREEN}Growl{RESET}\n"
    "Cyndaquil\n"
    "{COLOR GREEN}Leer{RESET} + {COLOR GREEN}Tackle{RESET}\n"
    "Torchic\n"
    "{COLOR GREEN}Ember{RESET} + {COLOR GREEN}Growl{RESET}{EXTRA_MSG}Eevee\n"
    "{COLOR GREEN}Tail Whip{RESET} + {COLOR GREEN}Tackle{RESET}\n"
    "Meowth\n"
    "{COLOR GREEN}Scratch{RESET} + {COLOR GREEN}Growl{RESET}\n"
    "Skitty\n"
    "{COLOR GREEN}Tail Whip{RESET} + {COLOR GREEN}Tackle{RESET}");

ALIGNED(4) static const u8 sLinkedEntryHeadline2[] = _("#13 Linked Moves Entry Level 2");

ALIGNED(4) static const u8 sLinkedEntryText1[] = _(
    "{CENTER_ALIGN COLOR YELLOW}These Are the Recommended{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}Linked Moves for Beginners!{RESET}\n"
    "{COLOR RED}Grass, Fighting, and Ground Types{RESET}\n"
    "Bulbasaur\n"
    "{COLOR GREEN}Vine Whip{RESET} + {COLOR GREEN}Growl{RESET}\n"
    "Chikorita\n"
    "{COLOR GREEN}Razor Leaf{RESET} + {COLOR GREEN}Growl{RESET}{EXTRA_MSG}Treecko\n"
    "{COLOR GREEN}Leer{RESET} + {COLOR GREEN}Pound{RESET}\n"
    "Machop\n"
    "{COLOR GREEN}Leer{RESET} + {COLOR GREEN}Low Kick{RESET}\n"
    "Cubone\n"
    "{COLOR GREEN}Tail Whip{RESET} + {COLOR GREEN}Bone Club{RESET}");

ALIGNED(4) static const u8 sLinkedEntryHeadline1[] = _("#12 Linked Moves Entry Level 1");

ALIGNED(4) static const u8 sTypeText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Learn How Types Match Up!{RESET}\n"
    "All Pokémon are of certain types, such as\n"
    "{COLOR RED}Fire{RESET} and {COLOR CYAN}Water{RESET}. In a battle, the damage\n"
    "inflicted depends on how the Pokémon's\n"
    "type matches up with the move's type.\n"
    "For example, a {COLOR RED}Fire{RESET}-type Pokémon is\n"
    "weak against {COLOR CYAN}Water{RESET}-type moves.\n"
    "Exploit type matchups to win battles!");

ALIGNED(4) static const u8 sTypeHeadline[] = _("#11 Types and Matchups");

ALIGNED(4) static const u8 sDungeonText[] = _(
    "If your rescue team is defeated in a\n"
    "dungeon, you lose several items and\n"
    "all the money you are carrying.\n"
    "Beware of what you're carrying before\n"
    "you go off on a rescue or an outing.\n"
    "Use {COLOR CYAN}Kangaskhan Storage{RESET} to keep\n"
    "invaluable items safely stored.\n"
    "   - Pokémon Rescue Organization -");

ALIGNED(4) static const u8 sDungeonHeadline[] = _("#10 Mysterious Dungeons?");

ALIGNED(4) static const u8 sWonderText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Wonder Tiles Reset Attack and Defense!{RESET}\n"
    "If your Attack is lowered by a foe's\n"
    "{COLOR GREEN}Growl{RESET}, or your Defense is lowered\n"
    "by a foe's {COLOR GREEN}Tail Whip{RESET}, for example, the\n"
    "affected stat can be reset to normal by\n"
    "stepping on a Wonder Tile or going to the\n"
    "next floor. Beware, enhanced stats are\n"
    "also reset to normal!");

ALIGNED(4) static const u8 sWonderHeadline[] = _("#9 Wonder Tiles");

ALIGNED(4) static const u8 sMoveText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}The Benefits of Using Moves{RESET}\n"
    "If a move is used on a foe, when it is\n"
    "defeated, {COLOR CYAN}you earn more Exp. Points{RESET}!\n"
    "A move only has to be used once on the\n"
    "foe: after that it can be defeated using a\n"
    "regular attack to earn more Exp. Points.\n"
    "Moves are also more likely to become\n"
    "{COLOR CYAN}critical hits{RESET}! Don't overuse them, though!");

ALIGNED(4) static const u8 sMoveHeadline[] = _("#8 Let's Use Moves!");

ALIGNED(4) static const u8 sOptionsText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Change Your Option Settings{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}to Suit Your Play Style!{RESET}\n"
    "Press {B_BUTTON} to open the menu, then\n"
    "choose {COLOR YELLOW}Others{RESET} and {COLOR YELLOW}Game Options{RESET}.\n"
    "You can change settings to suit the way\n"
    "you play.");

ALIGNED(4) static const u8 sOptionsHeadline[] = _("#7 Game Options");

ALIGNED(4) static const u8 sDisasterText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Investigations Under Way into{RESET}\n"
    "{CENTER_ALIGN COLOR YELLOW}Recent Rash of Natural Disasters{RESET}\n"
    "Pokémon in affected areas attack any\n"
    "outsider without hesitation. Some believe\n"
    "a mysterious force is behind their\n"
    "behavior. One source blamed Diglett\n"
    "for triggering earthquakes, but the\n"
    "investigative team is skeptical.");

ALIGNED(4) static const u8 sDisasterHeadline[] = _("#6 Recent Natural Disasters");

ALIGNED(4) static const u8 sSeedText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Seeds Can Be Thrown, Too!{RESET}\n"
    "Seeds are usually meant to be eaten.\n"
    "But did you know? They can also be thrown\n"
    "at other Pokémon to unlock their effects.\n"
    "Toss seeds you don't want to eat at foes!\n"
    "Throw good seeds at friends!\n"
    "Don't be afraid to throw your seeds!");

ALIGNED(4) static const u8 sSeedHeadline[] = _("#5 Throw Seeds!");

ALIGNED(4) static const u8 sHungerText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Eat Something When You Get Hungry!{RESET}\n"
    "While you're exploring a dungeon, you will\n"
    "get progressively hungry (your Belly goes\n"
    "down). If you become famished, you will\n"
    "eventually lose HP and even faint.\n"
    "That's why you should eat something to fill\n"
    "your Belly! You can always buy food at the\n"
    "{COLOR CYAN}Kecleon Shop{RESET}.");

ALIGNED(4) static const u8 sHungerHeadline[] = _("#4 Getting Hungry");

ALIGNED(4) static const u8 sJobText[] = _(
    "If you want to go on a rescue job listed\n"
    "on the Bulletin Board at the Pelipper Post\n"
    "Office, or one that's delivered to your\n"
    "Mailbox, you first need to {COLOR YELLOW}Accept{RESET} the job,\n"
    "then choose {COLOR YELLOW}Take Job{RESET}. Only then will you\n"
    "be able to handle that job.\n"
    "Try to do accepted jobs quickly!\n"
    "   - Pokémon Rescue Organization -");

ALIGNED(4) static const u8 sJobHeadline[] = _("#3 Accepting Rescue Jobs");

ALIGNED(4) static const u8 sBasicsText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}Saving Your Adventure and Pokémon News{RESET}\n"
    "You can save your adventure by going to\n"
    "your bed. Get in the habit of saving often.\n"
    "You should also store old Pokémon News.\n"
    "If your Mailbox is full, you won't get the\n"
    "latest issue of the news or any job mail.\n"
    "Check the Mailbox and store old news!\n"
    "   - Pokémon Rescue Organization -");

ALIGNED(4) static const u8 sBasicsHeadline[] = _("#2 Rescue Team Basics");

ALIGNED(4) static const u8 sWelcomeText[] = _(
    "{CENTER_ALIGN COLOR YELLOW}To All New Members!{RESET}\n"
    "Your badge has the power to send back\n"
    "to town any Pokémon you've rescued. Just\n"
    "hold the badge up, and it does the rest.\n"
    "By completing rescue jobs, you will be\n"
    "awarded points that raise your team's\n"
    "ranking. Aim for the Bronze Rank for now!\n"
    "   - Pokémon Rescue Organization -");

ALIGNED(4) static const u8 sWelcomeHeadline[] = _("#1 Welcome to a Rescue Team!");
