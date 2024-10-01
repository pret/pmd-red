ALIGNED(4) static const u8 HardyQuest1Points[3][16] =
{
    { [HARDY] = 0x02, },
    { [RELAXED] = 0x02, },
    { [IMPISH] = 0x02, }
};

static const MenuItem HardyQuest1Answers[] =
{
    {"Study hard.", 0},
    {"At the last second.", 1},
    {"Ignore it and play.", 2},
    {NULL, -1},
};

static const u8 HardyQuest1Question[];
static const PersonalityQuestion HardyQuest1 = { HardyQuest1Question, HardyQuest1Answers, HardyQuest1Points };
ALIGNED(4) static const u8 HardyQuest1Question[] = _(
    "A test is coming up.\n"
    "How do you study for it?");

ALIGNED(4) static const u8 HardyQuest2Points[2][16] =
{
    { [HARDY] = 0x02, [DOCILE] = 0x01, },
    { [QUIRKY] = 0x02, }
};

static const MenuItem HardyQuest2Answers[] =
{
    {"Yes.", 0},
    {"No. ", 1},
    {NULL, -1},
};

static const u8 HardyQuest2Question[];
static const PersonalityQuestion HardyQuest2 = { HardyQuest2Question, HardyQuest2Answers, HardyQuest2Points };
ALIGNED(4) static const u8 HardyQuest2Question[] = _("Can you focus on something you like?");

ALIGNED(4) static const u8 HardyQuest3Points[2][16] =
{
    { [HARDY] = 0x02, [BRAVE] = 0x02, },
    { [SASSY] = 0x02, [QUIRKY] = 0x02, }
};

static const MenuItem HardyQuest3Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 HardyQuest3Question[];
static const PersonalityQuestion HardyQuest3 = { HardyQuest3Question, HardyQuest3Answers, HardyQuest3Points };
ALIGNED(4) static const u8 HardyQuest3Question[] = _(
    "When the going gets tough, do you get\n"
    "going?");

ALIGNED(4) static const u8 HardyQuest4Points[3][16] =
{
    { [HARDY] = 0x02, },
    { [CALM] = 0x02, },
    { [QUIRKY] = 0x02, }
};

static const MenuItem HardyQuest4Answers[] =
{
    {"Full.", 0},
    {"Half.", 1},
    {"A little.", 2},
    {NULL, -1},
};

static const u8 HardyQuest4Question[];
static const PersonalityQuestion HardyQuest4 = { HardyQuest4Question, HardyQuest4Answers, HardyQuest4Points };
ALIGNED(4) static const u8 HardyQuest4Question[] = _(
    "There is a bucket. If you put\n"
    "water in it, how high will you fill it?");

ALIGNED(4) static const u8 DocileQuest1Points[2][16] =
{
    { [DOCILE] = 0x02, [NAIVE] = 0x01, },
    { [TIMID] = 0x02, [CALM] = 0x01, }
};

static const MenuItem DocileQuest1Answers[] =
{
    {"Big box.", 0},
    {"Small box.", 1},
    {NULL, -1},
};

static const u8 DocileQuest1Question[];
static const PersonalityQuestion DocileQuest1 = { DocileQuest1Question, DocileQuest1Answers, DocileQuest1Points };
ALIGNED(4) static const u8 DocileQuest1Question[] = _(
    "You are offered a choice of two gifts.\n"
    "Which one will you take?");

ALIGNED(4) static const u8 DocileQuest2Points[2][16] =
{
    { [DOCILE] = 0x02, [HASTY] = 0x01, },
    { [NAIVE] = 0x02, [RELAXED] = 0x01, }
};

static const MenuItem DocileQuest2Answers[] =
{
    {"Open a window right away.", 0},
    {"Take a sniff first.", 1},
    {NULL, -1},
};

static const u8 DocileQuest2Question[];
static const PersonalityQuestion DocileQuest2 = { DocileQuest2Question, DocileQuest2Answers, DocileQuest2Points };
ALIGNED(4) static const u8 DocileQuest2Question[] = _(
    "You broke a rotten egg in your room!\n"
    "What will you do?");

ALIGNED(4) static const u8 DocileQuest3Points[3][16] =
{
    { [DOCILE] = 0x02, },
    { [NAIVE] = 0x01, [LONELY] = 0x01, },
    { [SASSY] = 0x02, }
};

static const u8 DocileQuest3_Regular[];
static const u8 DocileQuest3_Joke[];
static const u8 DocileQuest3_Cool[];
static const MenuItem DocileQuest3Answers[] =
{
    {DocileQuest3_Regular, 0},
    {DocileQuest3_Joke, 1},
    {DocileQuest3_Cool, 2},
    {NULL, -1},
};
ALIGNED(4) static const u8 DocileQuest3_Cool[] = _("Say thanks, but be cool.");
ALIGNED(4) static const u8 DocileQuest3_Joke[] = _("Say thanks with a joke.");
ALIGNED(4) static const u8 DocileQuest3_Regular[] = _("Say thank you regularly.");

static const u8 DocileQuest3Question[];
static const PersonalityQuestion DocileQuest3 = { DocileQuest3Question, DocileQuest3Answers, DocileQuest3Points };
ALIGNED(4) static const u8 DocileQuest3Question[] = _(
    "A friend brought over something you'd\n"
    "forgotten.{WAIT_PRESS}\n"
    "How do you thank your friend?");

ALIGNED(4) static const u8 DocileQuest4Points[3][16] =
{
    { [DOCILE] = 0x02, },
    { [NAIVE] = 0x02, },
    { [IMPISH] = 0x02, }
};

static const MenuItem DocileQuest4Answers[] =
{
    {"Turn it in to the police!", 0},
    {"Yay! Yay!", 1},
    {"Is anyone watching...?", 2},
    {NULL, -1},
};

static const u8 DocileQuest4Question[];
static const PersonalityQuestion DocileQuest4 = { DocileQuest4Question, DocileQuest4Answers, DocileQuest4Points };
ALIGNED(4) static const u8 DocileQuest4Question[] = _("There is a wallet at the side of a road.");

ALIGNED(4) static const u8 BraveQuest1Points[2][16] =
{
    { [BRAVE] = 0x03, [IMPISH] = 0x01, },
    { [DOCILE] = 0x02, [TIMID] = 0x01, }
};

static const MenuItem BraveQuest1Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 BraveQuest1Question[];
static const PersonalityQuestion BraveQuest1 = { BraveQuest1Question, BraveQuest1Answers, BraveQuest1Points };
ALIGNED(4) static const u8 BraveQuest1Question[] = _(
    "You're going bungee jumping for the first\n"
    "time.{EXTRA_MSG}Since it's scary, you decide to test the\n"
    "jump with a doll...{WAIT_PRESS}\n"
    "And the bungee cord snaps!{EXTRA_MSG}"
    "Will you still try to make a jump anyway?");

ALIGNED(4) static const u8 BraveQuest2APoints[3][16] =
{
    { },
    { [TIMID] = 0x02, },
    { [RELAXED] = 0x02, }
};

static const MenuItem BraveQuest2AAnswers[] =
{
    {"Fight.", 99},
    {"Run.", 1},
    {"Ignore it.", 2},
    {NULL, -1},
};

static const u8 BraveQuest2AQuestion[];
static const PersonalityQuestion BraveQuest2A = { BraveQuest2AQuestion, BraveQuest2AAnswers, BraveQuest2APoints };
ALIGNED(4) static const u8 BraveQuest2AQuestion[] = _(
    "There is an alien invasion!\n"
    "What will you do?");

ALIGNED(4) static const u8 BraveQuest2BPoints[2][16] =
{
    { [SASSY] = 0x01, [RELAXED] = 0x01, },
    { [BRAVE] = 0x04, }
};

static const MenuItem BraveQuest2BAnswers[] =
{
    {"Rule with the aliens.", 0},
    {"Refuse.", 1},
    {NULL, -1},
};

static const u8 BraveQuest2BQuestion[];
static const PersonalityQuestion BraveQuest2B = { BraveQuest2BQuestion, BraveQuest2BAnswers, BraveQuest2BPoints };
ALIGNED(4) static const u8 BraveQuest2BQuestion[] = _(
    "You valiantly fight the aliens...{WAIT_PRESS}\n"
    "But, you are defeated...{EXTRA_MSG}An alien says to you...{EXTRA_MSG}“YOU HAVE IMPRESSED US.\n"
    "IT WAS A PLEASURE TO SEE.{EXTRA_MSG}JOIN US, AND TOGETHER WE SHALL\n"
    "RULE THE WORLD.”{WAIT_PRESS}\n"
    "What will you do?");

ALIGNED(4) static const u8 BraveQuest3Points[2][16] =
{
    { [HARDY] = 0x01, [BRAVE] = 0x02, },
    { [NAIVE] = 0x02, }
};

static const MenuItem BraveQuest3Answers[] =
{
    {"Yank open the door.", 0},
    {"Scream in unison.", 1},
    {NULL, -1},
};

static const u8 BraveQuest3Question[];
static const PersonalityQuestion BraveQuest3 = { BraveQuest3Question, BraveQuest3Answers, BraveQuest3Points };
ALIGNED(4) static const u8 BraveQuest3Question[] = _(
    "There is a scream from behind a door!{WAIT_PRESS}\n"
    "How will you react?");

ALIGNED(4) static const u8 BraveQuest4Points[4][16] =
{
    { [BRAVE] = 0x03, },
    { [HARDY] = 0x02, [BRAVE] = 0x02, },
    { [DOCILE] = 0x01, [TIMID] = 0x01, [RELAXED] = 0x01, },
    { [TIMID] = 0x02, }
};

static const u8 BraveQuest4_Hesitation[];
static const u8 BraveQuest4_Scared[];
static const u8 BraveQuest4_Police[];
static const u8 BraveQuest4_Nothing[];
static const MenuItem BraveQuest4Answers[] =
{
    {BraveQuest4_Hesitation, 0},
    {BraveQuest4_Scared, 1},
    {BraveQuest4_Police, 2},
    {BraveQuest4_Nothing, 3},
    {NULL, -1},
};
ALIGNED(4) static const u8 BraveQuest4_Nothing[] = _("Do nothing out of fear.");
ALIGNED(4) static const u8 BraveQuest4_Police[] = _("Call the police.");
ALIGNED(4) static const u8 BraveQuest4_Scared[] = _("Help, even if scared.");
ALIGNED(4) static const u8 BraveQuest4_Hesitation[] = _("Help without hesitation.");

static const u8 BraveQuest4Question[];
static const PersonalityQuestion BraveQuest4 = { BraveQuest4Question, BraveQuest4Answers, BraveQuest4Points };
ALIGNED(4) static const u8 BraveQuest4Question[] = _(
    "A delinquent is hassling a girl on\n"
    "a busy city street!{WAIT_PRESS}\n"
    "What will you do?");

ALIGNED(4) static const u8 JollyQuest1Points[2][16] =
{
    { [JOLLY] = 0x02, [NAIVE] = 0x01, },
    { [SASSY] = 0x01, [QUIRKY] = 0x01, }
};

static const MenuItem JollyQuest1Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 JollyQuest1Question[];
static const PersonalityQuestion JollyQuest1 = { JollyQuest1Question, JollyQuest1Answers, JollyQuest1Points };
ALIGNED(4) static const u8 JollyQuest1Question[] = _("Are you a cheerful personality?");

ALIGNED(4) static const u8 JollyQuest2Points[2][16] =
{
    { [JOLLY] = 0x02, [LONELY] = 0x01, },
    { [TIMID] = 0x01, }
};

static const MenuItem JollyQuest2Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 JollyQuest2Question[];
static const PersonalityQuestion JollyQuest2 = { JollyQuest2Question, JollyQuest2Answers, JollyQuest2Points };
ALIGNED(4) static const u8 JollyQuest2Question[] = _(
    "Do you like to noisily enjoy yourself\n"
    "with others?");

ALIGNED(4) static const u8 JollyQuest3Points[3][16] =
{
    { [JOLLY] = 0x02, },
    { [CALM] = 0x02, },
    { [QUIRKY] = 0x02, }
};

static const MenuItem JollyQuest3Answers[] =
{
    {"The beach!", 0},
    {"Spas.", 1},
    {"Anywhere.", 2},
    {NULL, -1},
};

static const u8 JollyQuest3Question[];
static const PersonalityQuestion JollyQuest3 = { JollyQuest3Question, JollyQuest3Answers, JollyQuest3Points };
ALIGNED(4) static const u8 JollyQuest3Question[] = _(
    "It's the summer holidays!\n"
    "Where would you like to go?");

ALIGNED(4) static const u8 JollyQuest4Points[3][16] =
{
    { [JOLLY] = 0x03, },
    { [HARDY] = 0x02, },
    { [TIMID] = 0x02, }
};

static const u8 JollyQuest4_Funny[];
static const u8 JollyQuest4_Again[];
static const u8 JollyQuest4_Go[];
static const MenuItem JollyQuest4Answers[] =
{
    {JollyQuest4_Funny, 0},
    {JollyQuest4_Again, 1},
    {JollyQuest4_Go, 2},
    {NULL, -1},
};
ALIGNED(4) static const u8 JollyQuest4_Go[] = _("Right... Well, I gotta go.");
ALIGNED(4) static const u8 JollyQuest4_Again[] = _("Um... Could you say that again?");
ALIGNED(4) static const u8 JollyQuest4_Funny[] = _("Haha! Yes. Very funny!");

static const u8 JollyQuest4Question[];
static const PersonalityQuestion JollyQuest4 = { JollyQuest4Question, JollyQuest4Answers, JollyQuest4Points };
ALIGNED(4) static const u8 JollyQuest4Question[] = _(
    "A foreign person has started up a\n"
    "conversation with you.{EXTRA_MSG}"
    "To be honest, you don't have a clue what\n"
    "this fellow is saying.{WAIT_PRESS}\n"
    "How do you reply?");

ALIGNED(4) static const u8 ImpishQuest1Points[2][16] =
{
    { [IMPISH] = 0x02, [LONELY] = 0x01, },
    { [CALM] = 0x02, }
};

static const MenuItem ImpishQuest1Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 ImpishQuest1Question[];
static const PersonalityQuestion ImpishQuest1 = { ImpishQuest1Question, ImpishQuest1Answers, ImpishQuest1Points };
ALIGNED(4) static const u8 ImpishQuest1Question[] = _("Have you ever made a pitfall trap?");

ALIGNED(4) static const u8 ImpishQuest2Points[2][16] =
{
    { [IMPISH] = 0x02, },
    { [DOCILE] = 0x01, [RELAXED] = 0x01, }
};

static const MenuItem ImpishQuest2Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 ImpishQuest2Question[];
static const PersonalityQuestion ImpishQuest2 = { ImpishQuest2Question, ImpishQuest2Answers, ImpishQuest2Points };
ALIGNED(4) static const u8 ImpishQuest2Question[] = _("Do you like pranks?");

ALIGNED(4) static const u8 ImpishQuest3Points[2][16] =
{
    { [HARDY] = 0x01, [IMPISH] = 0x02, },
    { [SASSY] = 0x01, [QUIRKY] = 0x02, }
};

static const MenuItem ImpishQuest3Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 ImpishQuest3Question[];
static const PersonalityQuestion ImpishQuest3 = { ImpishQuest3Question, ImpishQuest3Answers, ImpishQuest3Points };
ALIGNED(4) static const u8 ImpishQuest3Question[] = _("Are there many things that you would like\nto do?");

ALIGNED(4) static const u8 ImpishQuest4Points[3][16] =
{
    { [BRAVE] = 0x03, },
    { [TIMID] = 0x02, },
    { [IMPISH] = 0x02, }
};

static const MenuItem ImpishQuest4Answers[] =
{
    {"Face up to the bully.", 0},
    {"Caution the bully from afar.", 1},
    {"Heckle the bully from behind.", 2},
    {NULL, -1},
};

static const u8 ImpishQuest4Question[];
static const PersonalityQuestion ImpishQuest4 = { ImpishQuest4Question, ImpishQuest4Answers, ImpishQuest4Points };
ALIGNED(4) static const u8 ImpishQuest4Question[] = _(
    "Your friend is being bullied!\n"
    "What do you do?");

ALIGNED(4) static const u8 NaiveQuest1Points[3][16] =
{
    { [IMPISH] = 0x01, [NAIVE] = 0x03, },
    { [JOLLY] = 0x02, },
    { [SASSY] = 0x02, }
};

static const MenuItem NaiveQuest1Answers[] =
{
    {"Love them!", 0},
    {"A little.", 1},
    {"Spare me.", 2},
    {NULL, -1},
};

static const u8 NaiveQuest1Question[];
static const PersonalityQuestion NaiveQuest1 = { NaiveQuest1Question, NaiveQuest1Answers, NaiveQuest1Points };
ALIGNED(4) static const u8 NaiveQuest1Question[] = _("Do you like groan-inducing puns?");

ALIGNED(4) static const u8 NaiveQuest2Points[2][16] =
{
    { [DOCILE] = 0x01, [NAIVE] = 0x02, },
    { [QUIRKY] = 0x02, }
};

static const MenuItem NaiveQuest2Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 NaiveQuest2Question[];
static const PersonalityQuestion NaiveQuest2 = { NaiveQuest2Question, NaiveQuest2Answers, NaiveQuest2Points };
ALIGNED(4) static const u8 NaiveQuest2Question[] = _("Do you tend to laugh a lot?");

ALIGNED(4) static const u8 NaiveQuest3Points[2][16] =
{
    { [JOLLY] = 0x01, [NAIVE] = 0x02, },
    { [CALM] = 0x02, }
};

static const MenuItem NaiveQuest3Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 NaiveQuest3Question[];
static const PersonalityQuestion NaiveQuest3 = { NaiveQuest3Question, NaiveQuest3Answers, NaiveQuest3Points };
ALIGNED(4) static const u8 NaiveQuest3Question[] = _("Do others often call you childish?");

ALIGNED(4) static const u8 NaiveQuest4Points[2][16] =
{
    { [NAIVE] = 0x02, },
    { [HASTY] = 0x02, }
};

static const MenuItem NaiveQuest4Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 NaiveQuest4Question[];
static const PersonalityQuestion NaiveQuest4 = { NaiveQuest4Question, NaiveQuest4Answers, NaiveQuest4Points };
ALIGNED(4) static const u8 NaiveQuest4Question[] = _(
    "Do you like to imagine things for your\n"
    "amusement?");

ALIGNED(4) static const u8 TimidQuest1Points[3][16] =
{
    { [TIMID] = 0x02, },
    { [HARDY] = 0x01, [CALM] = 0x02, },
    { [BRAVE] = 0x02, [IMPISH] = 0x01, [NAIVE] = 0x01, }
};

static const MenuItem TimidQuest1Answers[] =
{
    {"Scream and run.", 0},
    {"Close the lid without a word.", 1},
    {"Shake hands with it.", 2},
    {NULL, -1},
};

static const u8 TimidQuest1Question[];
static const PersonalityQuestion TimidQuest1 = { TimidQuest1Question, TimidQuest1Answers, TimidQuest1Points };
ALIGNED(4) static const u8 TimidQuest1Question[] = _(
    "A human hand extends out of a toilet!\n"
    "What would you do?");

ALIGNED(4) static const u8 TimidQuest2Points[5][16] =
{
    { [TIMID] = 0x02, },
    { [HASTY] = 0x02, },
    { [JOLLY] = 0x02, },
    { [SASSY] = 0x02, },
    { [LONELY] = 0x02, }
};

static const MenuItem TimidQuest2Answers[] =
{
    {"Thumb.", 0},
    {"Index finger.", 1},
    {"Middle finger.", 2},
    {"Ring finger.", 3},
    {"Little finger.", 4},
    {NULL, -1},
};

static const u8 TimidQuest2Question[];
static const PersonalityQuestion TimidQuest2 = { TimidQuest2Question, TimidQuest2Answers, TimidQuest2Points };
ALIGNED(4) static const u8 TimidQuest2Question[] = _(
    "Grab any digit on your left hand with your\n"
    "right hand.{WAIT_PRESS}\n"
    "Which digit did you grab?");

ALIGNED(4) static const u8 TimidQuest3Points[3][16] =
{
    { [TIMID] = 0x02, },
    { [LONELY] = 0x02, },
    { [IMPISH] = 0x02, [QUIRKY] = 0x01, }
};

static const MenuItem TimidQuest3Answers[] =
{
    {"Kick the door.", 0},
    {"Cry.", 1},
    {"Clean it.", 2},
    {NULL, -1},
};

static const u8 TimidQuest3Question[];
static const PersonalityQuestion TimidQuest3 = { TimidQuest3Question, TimidQuest3Answers, TimidQuest3Points };
ALIGNED(4) static const u8 TimidQuest3Question[] = _(
    "You are suddenly locked inside a\n"
    "pitch-black room!{WAIT_PRESS}\n"
    "What do you do?");

ALIGNED(4) static const u8 TimidQuest4Points[3][16] =
{
    { [BRAVE] = 0x03, },
    { [TIMID] = 0x02, },
    { [SASSY] = 0x02, }
};

static const MenuItem TimidQuest4Answers[] =
{
    {"No problem!", 0},
    {"Uh... N-no...", 1},
    {"With someone I like.", 2},
    {NULL, -1},
};

static const u8 TimidQuest4Question[];
static const PersonalityQuestion TimidQuest4 = { TimidQuest4Question, TimidQuest4Answers, TimidQuest4Points };
ALIGNED(4) static const u8 TimidQuest4Question[] = _("Can you go into a haunted house?");

ALIGNED(4) static const u8 HastyQuest1Points[3][16] =
{
    { [HASTY] = 0x02, },
    { [CALM] = 0x02, },
    { [TIMID] = 0x02, }
};

static const MenuItem HastyQuest1Answers[] =
{
    {"Open it now.", 0},
    {"Open it later.", 1},
    {"Get someone to open it.", 2},
    {NULL, -1},
};

static const u8 HastyQuest1Question[];
static const PersonalityQuestion HastyQuest1 = { HastyQuest1Question, HastyQuest1Answers, HastyQuest1Points };
ALIGNED(4) static const u8 HastyQuest1Question[] = _(
    "You receive a gift!{WAIT_PRESS}\n"
    "But you don't know what's in it.{WAIT_PRESS}\n"
    "You're curious, so what do you do?");

ALIGNED(4) static const u8 HastyQuest2Points[3][16] =
{
    { [JOLLY] = 0x02, [HASTY] = 0x01, },
    { [HARDY] = 0x01, [CALM] = 0x01, },
    { [BRAVE] = 0x02, [QUIRKY] = 0x02, }
};

static const MenuItem HastyQuest2Answers[] =
{
    {"Spend it now.", 0},
    {"Save it.", 1},
    {"Give it away.", 2},
    {NULL, -1},
};

static const u8 HastyQuest2Question[];
static const PersonalityQuestion HastyQuest2 = { HastyQuest2Question, HastyQuest2Answers, HastyQuest2Points };
ALIGNED(4) static const u8 HastyQuest2Question[] = _(
    "You win a lottery!{WAIT_PRESS}\n"
    "What do you do with the money?");

ALIGNED(4) static const u8 HastyQuest3Points[3][16] =
{
    { [HASTY] = 0x02, },
    { [TIMID] = 0x02, },
    { [SASSY] = 0x02, }
};

static const u8 HastyQuest3_Open[];
static const u8 HastyQuest3_Trap[];
static const u8 HastyQuest3_Empty[];
static const MenuItem HastyQuest3Answers[] =
{
    {HastyQuest3_Open, 0},
    {HastyQuest3_Trap, 1},
    {HastyQuest3_Empty, 2},
    {NULL, -1},
};
ALIGNED(4) static const u8 HastyQuest3_Empty[] = _("It's going to be empty...");
ALIGNED(4) static const u8 HastyQuest3_Trap[] = _("No... Could be a trap...");
ALIGNED(4) static const u8 HastyQuest3_Open[] = _("Open it right away!");

static const u8 HastyQuest3Question[];
static const PersonalityQuestion HastyQuest3 = { HastyQuest3Question, HastyQuest3Answers, HastyQuest3Points };
ALIGNED(4) static const u8 HastyQuest3Question[] = _(
    "You come across a treasure chest!\n"
    "What do you do?");

ALIGNED(4) static const u8 HastyQuest4Points[3][16] =
{
    { [DOCILE] = 0x01, [HASTY] = 0x02, },
    { [RELAXED] = 0x02, },
    { [HASTY] = 0x03, }
};

static const MenuItem HastyQuest4Answers[] =
{
    {"Become irritated.", 0},
    {"Wait patiently.", 1},
    {"Get angry and bail.", 2},
    {NULL, -1},
};

static const u8 HastyQuest4Question[];
static const PersonalityQuestion HastyQuest4 = { HastyQuest4Question, HastyQuest4Answers, HastyQuest4Points };
ALIGNED(4) static const u8 HastyQuest4Question[] = _(
    "Your friend fails to show up for a meeting\n"
    "at the promised time.\n"
    "What do you do?");

ALIGNED(4) static const u8 SassyQuest1Points[3][16] =
{
    { [HARDY] = 0x02, },
    { [DOCILE] = 0x02, },
    { [SASSY] = 0x02, }
};

static const MenuItem SassyQuest1Answers[] =
{
    {"Speak calmly.", 0},
    {"Speak nervously.", 1},
    {"WHATEVER!!", 2},
    {NULL, -1},
};

static const u8 SassyQuest1Question[];
static const PersonalityQuestion SassyQuest1 = { SassyQuest1Question, SassyQuest1Answers, SassyQuest1Points };
ALIGNED(4) static const u8 SassyQuest1Question[] = _(
    "Your country's leader is in front of you.\n"
    "How do you speak to him or her?");

ALIGNED(4) static const u8 SassyQuest2Points[2][16] =
{
    { [IMPISH] = 0x01, [SASSY] = 0x02, },
    { [CALM] = 0x02, }
};

static const MenuItem SassyQuest2Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 SassyQuest2Question[];
static const PersonalityQuestion SassyQuest2 = { SassyQuest2Question, SassyQuest2Answers, SassyQuest2Points };
ALIGNED(4) static const u8 SassyQuest2Question[] = _("Do others tell you to watch what you say?");

ALIGNED(4) static const u8 SassyQuest3Points[2][16] =
{
    { [SASSY] = 0x02, },
    { [RELAXED] = 0x02, }
};

static const MenuItem SassyQuest3Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 SassyQuest3Question[];
static const PersonalityQuestion SassyQuest3 = { SassyQuest3Question, SassyQuest3Answers, SassyQuest3Points };
ALIGNED(4) static const u8 SassyQuest3Question[] = _(
    "Do you think you are cool?\n"
    "Be honest.");

ALIGNED(4) static const u8 SassyQuest4Points[2][16] =
{
    { [DOCILE] = 0x02, [CALM] = 0x01, },
    { [SASSY] = 0x02, [QUIRKY] = 0x01, }
};

static const MenuItem SassyQuest4Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 SassyQuest4Question[];
static const PersonalityQuestion SassyQuest4 = { SassyQuest4Question, SassyQuest4Answers, SassyQuest4Points };
ALIGNED(4) static const u8 SassyQuest4Question[] = _(
    "Can you sincerely thank someone when you\n"
    "feel grateful?");

ALIGNED(4) static const u8 CalmQuest1Points[2][16] =
{
    { [CALM] = 0x02, [LONELY] = 0x01, },
    { [HARDY] = 0x02, }
};

static const MenuItem CalmQuest1Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 CalmQuest1Question[];
static const PersonalityQuestion CalmQuest1 = { CalmQuest1Question, CalmQuest1Answers, CalmQuest1Points };
ALIGNED(4) static const u8 CalmQuest1Question[] = _(
    "Do you occasionally consider yourself\n"
    "dull and overly cautious?");

ALIGNED(4) static const u8 CalmQuest2Points[2][16] =
{
    { [CALM] = 0x02, },
    { [IMPISH] = 0x02, }
};

static const MenuItem CalmQuest2Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 CalmQuest2Question[];
static const PersonalityQuestion CalmQuest2 = { CalmQuest2Question, CalmQuest2Answers, CalmQuest2Points };
ALIGNED(4) static const u8 CalmQuest2Question[] = _(
    "Do you dream of lounging around idly\n"
    "without much excitement?");

ALIGNED(4) static const u8 CalmQuest3Points[2][16] =
{
    { [IMPISH] = 0x01, [TIMID] = 0x02, },
    { [CALM] = 0x02, [LONELY] = 0x01, }
};

static const MenuItem CalmQuest3Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 CalmQuest3Question[];
static const PersonalityQuestion CalmQuest3 = { CalmQuest3Question, CalmQuest3Answers, CalmQuest3Points };
ALIGNED(4) static const u8 CalmQuest3Question[] = _("Do you like to fight?");

ALIGNED(4) static const u8 CalmQuest4Points[2][16] =
{
    { [CALM] = 0x02, [RELAXED] = 0x01, },
    { [HARDY] = 0x01, [HASTY] = 0x02, }
};

static const MenuItem CalmQuest4Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 CalmQuest4Question[];
static const PersonalityQuestion CalmQuest4 = { CalmQuest4Question, CalmQuest4Answers, CalmQuest4Points };
ALIGNED(4) static const u8 CalmQuest4Question[] = _("Do you often yawn?");

ALIGNED(4) static const u8 RelaxedQuest1Points[2][16] =
{
    { [SASSY] = 0x01, [RELAXED] = 0x02, },
    { [HARDY] = 0x02, [HASTY] = 0x01, }
};

static const MenuItem RelaxedQuest1Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 RelaxedQuest1Question[];
static const PersonalityQuestion RelaxedQuest1 = { RelaxedQuest1Question, RelaxedQuest1Answers, RelaxedQuest1Points };
ALIGNED(4) static const u8 RelaxedQuest1Question[] = _("Are you often late for school or meetings?");

ALIGNED(4) static const u8 RelaxedQuest2Points[2][16] =
{
    { [RELAXED] = 0x02, },
    { [IMPISH] = 0x01, [HASTY] = 0x02, }
};

static const MenuItem RelaxedQuest2Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 RelaxedQuest2Question[];
static const PersonalityQuestion RelaxedQuest2 = { RelaxedQuest2Question, RelaxedQuest2Answers, RelaxedQuest2Points };
ALIGNED(4) static const u8 RelaxedQuest2Question[] = _(
    "Do you get the feeling that you've slowed\n"
    "down lately?");

ALIGNED(4) static const u8 RelaxedQuest3Points[3][16] =
{
    { [JOLLY] = 0x02, },
    { [RELAXED] = 0x02, },
    { [HASTY] = 0x02, }
};

static const MenuItem RelaxedQuest3Answers[] =
{
    {"This feels great!", 0},
    {"Snore...", 1},
    {"I want to go home soon!", 2},
    {NULL, -1},
};

static const u8 RelaxedQuest3Question[];
static const PersonalityQuestion RelaxedQuest3 = { RelaxedQuest3Question, RelaxedQuest3Answers, RelaxedQuest3Points };
ALIGNED(4) static const u8 RelaxedQuest3Question[] = _(
    "It is a pleasant day at the beach.\n"
    "How do you feel?");

ALIGNED(4) static const u8 RelaxedQuest4Points[2][16] =
{
    { [CALM] = 0x01, [RELAXED] = 0x02, },
    { [HARDY] = 0x02, }
};

static const MenuItem RelaxedQuest4Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 RelaxedQuest4Question[];
static const PersonalityQuestion RelaxedQuest4 = { RelaxedQuest4Question, RelaxedQuest4Answers, RelaxedQuest4Points };
ALIGNED(4) static const u8 RelaxedQuest4Question[] = _("Do you fall asleep without noticing?");

ALIGNED(4) static const u8 LonelyQuest1Points[2][16] =
{
    { [TIMID] = 0x01, [LONELY] = 0x02, },
    { [SASSY] = 0x02, }
};

static const MenuItem LonelyQuest1Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 LonelyQuest1Question[];
static const PersonalityQuestion LonelyQuest1 = { LonelyQuest1Question, LonelyQuest1Answers, LonelyQuest1Points };
ALIGNED(4) static const u8 LonelyQuest1Question[] = _("Do you feel lonesome when you are alone?");

ALIGNED(4) static const u8 LonelyQuest2Points[2][16] =
{
    { [TIMID] = 0x01, [LONELY] = 0x02, },
    { [BRAVE] = 0x03, [RELAXED] = 0x01, }
};

static const MenuItem LonelyQuest2Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 LonelyQuest2Question[];
static const PersonalityQuestion LonelyQuest2 = { LonelyQuest2Question, LonelyQuest2Answers, LonelyQuest2Points };
ALIGNED(4) static const u8 LonelyQuest2Question[] = _(
    "Do you hate to be the last person to leave\n"
    "class at the end of a school day?");

ALIGNED(4) static const u8 LonelyQuest3Points[2][16] =
{
    { [TIMID] = 0x01, [LONELY] = 0x02, },
    { [CALM] = 0x02, }
};

static const MenuItem LonelyQuest3Answers[] =
{
    {"Leave it on.", 0},
    {"Turn it off.", 1},
    {NULL, -1},
};

static const u8 LonelyQuest3Question[];
static const PersonalityQuestion LonelyQuest3 = { LonelyQuest3Question, LonelyQuest3Answers, LonelyQuest3Points };
ALIGNED(4) static const u8 LonelyQuest3Question[] = _(
    "What do you do with your room's light\n"
    "when you're going to bed at night?");

ALIGNED(4) static const u8 LonelyQuest4Points[3][16] =
{
    { [JOLLY] = 0x01, [LONELY] = 0x01, },
    { [CALM] = 0x01, [RELAXED] = 0x02, },
    { [TIMID] = 0x01, [LONELY] = 0x03, }
};

static const MenuItem LonelyQuest4Answers[] =
{
    {"Go on a trip.", 0},
    {"Hang around vacantly.", 1},
    {"Huddle in a corner.", 2},
    {NULL, -1},
};

static const u8 LonelyQuest4Question[];
static const PersonalityQuestion LonelyQuest4 = { LonelyQuest4Question, LonelyQuest4Answers, LonelyQuest4Points };
ALIGNED(4) static const u8 LonelyQuest4Question[] = _(
    "It's a weekend, but no one will play\n"
    "with you...\n"
    "What do you do?");

ALIGNED(4) static const u8 QuirkyQuest1Points[2][16] =
{
    { [QUIRKY] = 0x02, },
    { [HARDY] = 0x02, }
};

static const MenuItem QuirkyQuest1Answers[] =
{
    {"Yes.", 0},
    {"No.", 1},
    {NULL, -1},
};

static const u8 QuirkyQuest1Question[];
static const PersonalityQuestion QuirkyQuest1 = { QuirkyQuest1Question, QuirkyQuest1Answers, QuirkyQuest1Points };
ALIGNED(4) static const u8 QuirkyQuest1Question[] = _(
    "Do you sometimes run out of things to do\n"
    "all of a sudden?");

ALIGNED(4) static const u8 QuirkyQuest2Points[3][16] =
{
    { [HARDY] = 0x01, [HASTY] = 0x01, },
    { [QUIRKY] = 0x02, },
    { [SASSY] = 0x02, }
};

static const u8 QuirkyQuest2_Reply[];
static const u8 QuirkyQuest2_MayMayNot[];
static const u8 QuirkyQuest2_Trouble[];
static const MenuItem QuirkyQuest2Answers[] =
{
    {QuirkyQuest2_Reply, 0},
    {QuirkyQuest2_MayMayNot, 1},
    {QuirkyQuest2_Trouble, 2},
    {NULL, -1},
};
ALIGNED(4) static const u8 QuirkyQuest2_Trouble[] = _("Too much trouble.");
ALIGNED(4) static const u8 QuirkyQuest2_MayMayNot[] = _("May reply, may not.");
ALIGNED(4) static const u8 QuirkyQuest2_Reply[] = _("Reply right away.");

static const u8 QuirkyQuest2Question[];
static const PersonalityQuestion QuirkyQuest2 = { QuirkyQuest2Question, QuirkyQuest2Answers, QuirkyQuest2Points };
ALIGNED(4) static const u8 QuirkyQuest2Question[] = _("How quickly do you respond to an e-mail?");

ALIGNED(4) static const u8 QuirkyQuest3Points[4][16] =
{
    { [HARDY] = 0x01, [BRAVE] = 0x03, },
    { [QUIRKY] = 0x02, },
    { [IMPISH] = 0x02, },
    { [TIMID] = 0x02, }
};

static const MenuItem QuirkyQuest3Answers[] =
{
    {"Bravely declare my love.", 0},
    {"Might say hello...", 1},
    {"Pull a prank to get attention.", 2},
    {"Look from afar.", 3},
    {NULL, -1},
};

static const u8 QuirkyQuest3Question[];
static const PersonalityQuestion QuirkyQuest3 = { QuirkyQuest3Question, QuirkyQuest3Answers, QuirkyQuest3Points };
ALIGNED(4) static const u8 QuirkyQuest3Question[] = _(
    "There is a person you like...{WAIT_PRESS}\n"
    "But there's no opportunity to get close.\n"
    "What do you do?");

ALIGNED(4) static const u8 QuirkyQuest4Points[3][16] =
{
    { [DOCILE] = 0x02, },
    { [SASSY] = 0x02, },
    { [QUIRKY] = 0x02, }
};

static const u8 QuirkyQuest4_GoRight[];
static const u8 QuirkyQuest4_GoLeft[];
static const u8 QuirkyQuest4_EitherSide[];
static const MenuItem QuirkyQuest4Answers[] =
{
    {QuirkyQuest4_GoRight, 0},
    {QuirkyQuest4_GoLeft, 1},
    {QuirkyQuest4_EitherSide, 2},
    {NULL, -1},
};
ALIGNED(4) static const u8 QuirkyQuest4_EitherSide[] = _("Choose either side.");
ALIGNED(4) static const u8 QuirkyQuest4_GoLeft[] = _("It's a trap! Go left.");
ALIGNED(4) static const u8 QuirkyQuest4_GoRight[] = _("Instantly go right.");

static const u8 QuirkyQuest4Question[];
static const PersonalityQuestion QuirkyQuest4 = { QuirkyQuest4Question, QuirkyQuest4Answers, QuirkyQuest4Points };
ALIGNED(4) static const u8 QuirkyQuest4Question[] = _(
    "The road forks to the right and left.\n"
    "You are told there is a treasure on the\n"
    "right side. What do you do?");

ALIGNED(4) static const u8 MiscQuest1Points[2][16] =
{
    { [HASTY] = 0x01, [QUIRKY] = 0x01, },
    { [JOLLY] = 0x01, [LONELY] = 0x01, }
};

static const MenuItem MiscQuest1Answers[] =
{
    {"Go alone.", 0},
    {"Go with others.", 1},
    {NULL, -1},
};

static const u8 MiscQuest1Question[];
static const PersonalityQuestion MiscQuest1 = { MiscQuest1Question, MiscQuest1Answers, MiscQuest1Points };
ALIGNED(4) static const u8 MiscQuest1Question[] = _("On vacation outings, you want to...");

ALIGNED(4) static const u8 MiscQuest2Points[2][16] =
{
    { [JOLLY] = 0x02, },
    { [SASSY] = 0x01, [QUIRKY] = 0x01, }
};

static const u8 MiscQuest2_DontCare[];
static const MenuItem MiscQuest2Answers[] =
{
    {"Love them!", 0},
    {MiscQuest2_DontCare, 1},
    {NULL, -1},
};
ALIGNED(4) static const u8 MiscQuest2_DontCare[] = _("Don't care.");

static const u8 MiscQuest2Question[];
static const PersonalityQuestion MiscQuest2 = { MiscQuest2Question, MiscQuest2Answers, MiscQuest2Points };
ALIGNED(4) static const u8 MiscQuest2Question[] = _(
    "It's the summer festival!\n"
    "Do you like carnivals?");

ALIGNED(4) static const u8 MiscQuest3Points[2][16] =
{
    { [NAIVE] = 0x01, [LONELY] = 0x01, },
    { [HASTY] = 0x01, [SASSY] = 0x01, }
};

static const MenuItem MiscQuest3Answers[] =
{
    {"Happy!", 0},
    {"Not happy.", 1},
    {NULL, -1},
};

static const u8 MiscQuest3Question[];
static const PersonalityQuestion MiscQuest3 = { MiscQuest3Question, MiscQuest3Answers, MiscQuest3Points };
ALIGNED(4) static const u8 MiscQuest3Question[] = _(
    "Somebody calls you “weird but funny.”\n"
    "How does that make you feel?");

static const PersonalityQuestion* const gPersonalityQuestionPointerTable[NUM_QUIZ_QUESTIONS + 1] =
{
    &HardyQuest1, &HardyQuest2, &HardyQuest3, &HardyQuest4,
    &DocileQuest1, &DocileQuest2, &DocileQuest3, &DocileQuest4,
    &BraveQuest1, &BraveQuest2A, &BraveQuest3, &BraveQuest4,
    &JollyQuest1, &JollyQuest2, &JollyQuest3, &JollyQuest4,
    &ImpishQuest1, &ImpishQuest2, &ImpishQuest3, &ImpishQuest4,
    &NaiveQuest1, &NaiveQuest2, &NaiveQuest3, &NaiveQuest4,
    &TimidQuest1, &TimidQuest2, &TimidQuest3, &TimidQuest4,
    &HastyQuest1, &HastyQuest2, &HastyQuest3, &HastyQuest4,
    &SassyQuest1, &SassyQuest2, &SassyQuest3, &SassyQuest4,
    &CalmQuest1, &CalmQuest2, &CalmQuest3, &CalmQuest4,
    &RelaxedQuest1, &RelaxedQuest2, &RelaxedQuest3, &RelaxedQuest4,
    &LonelyQuest1, &LonelyQuest2, &LonelyQuest3, &LonelyQuest4,
    &QuirkyQuest1, &QuirkyQuest2, &QuirkyQuest3, &QuirkyQuest4,
    &MiscQuest1, &MiscQuest2, &MiscQuest3,
    &BraveQuest2B
};

// NOTE: 2nd Part of Brave is included at the end so it isn't actually chosen
static const u8 gNatureQuestionTable[NUM_QUIZ_QUESTIONS + 1] =
{
    HARDY, HARDY, HARDY, HARDY,
    DOCILE, DOCILE, DOCILE, DOCILE,
    BRAVE, BRAVE, BRAVE, BRAVE,
    JOLLY, JOLLY, JOLLY, JOLLY,
    IMPISH, IMPISH, IMPISH, IMPISH,
    NAIVE, NAIVE, NAIVE, NAIVE,
    TIMID, TIMID, TIMID, TIMID,
    HASTY, HASTY, HASTY, HASTY,
    SASSY, SASSY, SASSY, SASSY,
    CALM, CALM, CALM, CALM,
    RELAXED, RELAXED, RELAXED, RELAXED,
    LONELY, LONELY, LONELY, LONELY,
    QUIRKY, QUIRKY, QUIRKY, QUIRKY,
    MISC, MISC, MISC,
    BRAVE
};

ALIGNED(4) static const u8 gGenderText[] = _("Are you a boy or a girl?");
UNUSED ALIGNED(4) static const u8* const gGenderTextPtr[] = { gGenderText };

static const MenuItem gGenderMenu[] =
{
    {"Boy.", 0},
    {"Girl.", 1},
    {NULL, -1},
};

UNUSED static const u8 unknownPersonality[13] =
{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
};

static const s16 gStarters[NUM_PERSONALITIES][2] =
{
    //          MALE / FEMALE
    [HARDY]   = {MONSTER_CHARMANDER, MONSTER_PIKACHU},
    [DOCILE]  = {MONSTER_BULBASAUR, MONSTER_CHIKORITA},
    [BRAVE]   = {MONSTER_MACHOP, MONSTER_CHARMANDER},
    [JOLLY]   = {MONSTER_SQUIRTLE, MONSTER_TOTODILE},
    [IMPISH]  = {MONSTER_PIKACHU, MONSTER_CUBONE},
    [NAIVE]   = {MONSTER_TOTODILE, MONSTER_EEVEE},
    [TIMID]   = {MONSTER_CYNDAQUIL, MONSTER_MUDKIP},
    [HASTY]   = {MONSTER_TORCHIC, MONSTER_SKITTY},
    [SASSY]   = {MONSTER_TREECKO, MONSTER_TORCHIC},
    [CALM]    = {MONSTER_MUDKIP, MONSTER_BULBASAUR},
    [RELAXED] = {MONSTER_PSYDUCK, MONSTER_SQUIRTLE},
    [LONELY]  = {MONSTER_CUBONE, MONSTER_PSYDUCK},
    [QUIRKY]  = {MONSTER_MEOWTH, MONSTER_TREECKO}
};

ALIGNED(4) static const u8 gStarterReveal[] = _(
    "\n"
    "{CENTER_ALIGN}The Pokémon {ARG_POKEMON_0}!");
UNUSED ALIGNED(4) static const u8* const gStarterRevealPtr[] = { gStarterReveal };

ALIGNED(4) static const u8 gPartnerPrompt[] = _(
        "{CENTER_ALIGN}This is the final step.{WAIT_PRESS}\n"
        "{CENTER_ALIGN}Who would you like to have as a partner?{EXTRA_MSG}"
        "{CENTER_ALIGN}Choose the Pokémon you want\n"
        "{CENTER_ALIGN}as your partner from this group.");
UNUSED ALIGNED(4) static const u8* const gPartnerPromptPtr = gPartnerPrompt;

ALIGNED(4) static const u8 gPartnerNickPrompt[] = _("{CENTER_ALIGN}What is your partner's nickname?");
UNUSED ALIGNED(4) static const u8* const gPartnerNickPromptPtr[] = { gPartnerNickPrompt };

ALIGNED(4) static const u8 gEndIntroText[] = _(
    "{CENTER_ALIGN}OK! We're all set!{EXTRA_MSG}"
    "{CENTER_ALIGN}Let's get you into the\n"
    "{CENTER_ALIGN}world of Pokémon!{EXTRA_MSG}"
    "{CENTER_ALIGN}Go for it!");
UNUSED ALIGNED(4) static const u8* const gEndIntroTextPtr[] = { gEndIntroText };

static const u8 gHardyDescription[];
static const u8 gDocileDescription[];
static const u8 gBraveDescription[];
static const u8 gJollyDescription[];
static const u8 gImpishDescription[];
static const u8 gNaiveDescription[];
static const u8 gTimidDescription[];
static const u8 gHastyDescription[];
static const u8 gSassyDescription[];
static const u8 gCalmDescription[];
static const u8 gRelaxedDescription[];
static const u8 gLonelyDescription[];
static const u8 gQuirkyDescription[];

static const u8* const sPersonalityTypeDescriptionTable[NUM_PERSONALITIES] =
{
    [HARDY] = gHardyDescription,
    [DOCILE] = gDocileDescription,
    [BRAVE] = gBraveDescription,
    [JOLLY] = gJollyDescription,
    [IMPISH] = gImpishDescription,
    [NAIVE] = gNaiveDescription,
    [TIMID] = gTimidDescription,
    [HASTY] = gHastyDescription,
    [SASSY] = gSassyDescription,
    [CALM] = gCalmDescription,
    [RELAXED] = gRelaxedDescription,
    [LONELY] = gLonelyDescription,
    [QUIRKY] = gQuirkyDescription
};

ALIGNED(4) static const u8 gQuirkyDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The quirky type.{EXTRA_MSG}"
    "{CENTER_ALIGN}People consider you an eccentric\n"
    "{CENTER_ALIGN}who does things at your own pace.{EXTRA_MSG}"
    "{CENTER_ALIGN}You never break tempo.{EXTRA_MSG}"
    "{CENTER_ALIGN}Your carefree nature makes you\n"
    "{CENTER_ALIGN}attractive. But you also happen\n"
    "{CENTER_ALIGN}to be somewhat childish...{EXTRA_MSG}"
    "{CENTER_ALIGN}You are fickle and cause problems for the\n"
    "{CENTER_ALIGN}people who have to go along with you.{EXTRA_MSG}"
    "{CENTER_ALIGN}Maybe people are even upset\n"
    "{CENTER_ALIGN}with you for being so fickle?{EXTRA_MSG}"
    "{CENTER_ALIGN}If you realize how selfishly\n"
    "{CENTER_ALIGN}you're behaving, try to think\n"
    "{CENTER_ALIGN}before you do anything rash.{EXTRA_MSG}"
    "{CENTER_ALIGN}A quirky person like you should be...");

ALIGNED(4) static const u8 gLonelyDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The lonely type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You always act cheerful and\n"
    "{CENTER_ALIGN}jocular around other people.{EXTRA_MSG}"
    "{CENTER_ALIGN}But that's only because\n"
    "{CENTER_ALIGN}you are with other people.{EXTRA_MSG}"
    "{CENTER_ALIGN}However, when you get alone...{EXTRA_MSG}"
    "{CENTER_ALIGN}Do you find yourself\n"
    "{CENTER_ALIGN}feeling oddly depressed?{EXTRA_MSG}"
    "{CENTER_ALIGN}That's why you always\n"
    "{CENTER_ALIGN}want to be with others.{EXTRA_MSG}"
    "{CENTER_ALIGN}But if you go around feeling\n"
    "{CENTER_ALIGN}depressed too much...{EXTRA_MSG}"
    "{CENTER_ALIGN}Your nutritional balance goes out\n"
    "{CENTER_ALIGN}of wack. Eat more vegetables!{EXTRA_MSG}"
    "{CENTER_ALIGN}However...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}It's not a bad thing\n"
    "{CENTER_ALIGN}to feel lonely.{EXTRA_MSG}"
    "{CENTER_ALIGN}You know what it's like when you aren't\n"
    "{CENTER_ALIGN}alone, so that's why you feel lonesome.{EXTRA_MSG}"
    "{CENTER_ALIGN}And that's why you aren't really alone.{EXTRA_MSG}"
    "{CENTER_ALIGN}A lonely person like you should be...");

ALIGNED(4) static const u8 gRelaxedDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The relaxed type.{EXTRA_MSG}"
    "{CENTER_ALIGN}Do you occasionally\n"
    "{CENTER_ALIGN}zone out and miss a bus?{EXTRA_MSG}"
    "{CENTER_ALIGN}Or do you find yourself dozing off?{EXTRA_MSG}"
    "{CENTER_ALIGN}Or is your reaction time\n"
    "{CENTER_ALIGN}a little slower than others?{EXTRA_MSG}"
    "{CENTER_ALIGN}But that's not necessarily\n"
    "{CENTER_ALIGN}a bad thing.{EXTRA_MSG}"
    "{CENTER_ALIGN}You can do things at your own\n"
    "{CENTER_ALIGN}tempo without feeling pressured.{EXTRA_MSG}"
    "{CENTER_ALIGN}You can live in a relaxed and\n"
    "{CENTER_ALIGN}unhurried manner without worries.{EXTRA_MSG}"
    "{CENTER_ALIGN}I think that's a happy\n"
    "{CENTER_ALIGN}lifestyle to be envied, even.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're also surprisingly popular.{EXTRA_MSG}"
    "{CENTER_ALIGN}The way you vacantly stare\n"
    "{CENTER_ALIGN}off into the distance...{EXTRA_MSG}"
    "{CENTER_ALIGN}It should make that someone\n"
    "{CENTER_ALIGN}special's pulse race.{EXTRA_MSG}"
    "{CENTER_ALIGN}A relaxed person like you should be...");

ALIGNED(4) static const u8 gCalmDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The calm type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're capable of giving advice\n"
    "{CENTER_ALIGN}to friends with worries.{EXTRA_MSG}"
    "{CENTER_ALIGN}You don't like to fight.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're a warm, kindhearted\n"
    "{CENTER_ALIGN}person who cares.{EXTRA_MSG}"
    "{CENTER_ALIGN}You must have many friends\n"
    "{CENTER_ALIGN}who look up to you.{EXTRA_MSG}"
    "{CENTER_ALIGN}However...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}You may also be somewhat gullible...{EXTRA_MSG}"
    "{CENTER_ALIGN}As well as a little careless...{EXTRA_MSG}"
    "{CENTER_ALIGN}And even a little sloppy.{EXTRA_MSG}"
    "{CENTER_ALIGN}You might want to keep\n"
    "{CENTER_ALIGN}those points in mind.{EXTRA_MSG}"
    "{CENTER_ALIGN}A calm person like you should be...");

ALIGNED(4) static const u8 gSassyDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The sassy type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You tend to be somewhat cynical.{EXTRA_MSG}"
    "{CENTER_ALIGN}Despite that, there is something\n"
    "{CENTER_ALIGN}appealing and lovable about you.{EXTRA_MSG}"
    "{CENTER_ALIGN}But do you occasionally say something\n"
    "{CENTER_ALIGN}arrogant that angers others?{EXTRA_MSG}"
    "{CENTER_ALIGN}Do you make that mistake?{EXTRA_MSG}"
    "{CENTER_ALIGN}Or have people called you\n"
    "{CENTER_ALIGN}conceited, vain, or selfish?{EXTRA_MSG}"
    "{CENTER_ALIGN}Have people said that about you?{EXTRA_MSG}"
    "{CENTER_ALIGN}Huh?{WAIT_PRESS} You're telling me to get lost?{EXTRA_MSG}"
    "{CENTER_ALIGN}Why, you... Come here and say that!{WAIT_PRESS}\n"
    "{CENTER_ALIGN}......Gasp!{EXTRA_MSG}"
    "{CENTER_ALIGN}...I'm sorry.\n"
    "{CENTER_ALIGN}I let my feelings run away.\n"
    "{CENTER_ALIGN}I truly regret this, really.{EXTRA_MSG}"
    "{CENTER_ALIGN}Anyway, your cool and aloof\n"
    "{CENTER_ALIGN}attitude is what defines you.{EXTRA_MSG}"
    "{CENTER_ALIGN}It makes you exasperating and\n"
    "{CENTER_ALIGN}appealing at the same time.{EXTRA_MSG}"
    "{CENTER_ALIGN}A sassy person like you should be...");

ALIGNED(4) static const u8 gHastyDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The hasty type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You like to take charge\n"
    "{CENTER_ALIGN}and get things done.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're a real go-getter.{EXTRA_MSG}"
    "{CENTER_ALIGN}But are you also stressed out?{EXTRA_MSG}"
    "{CENTER_ALIGN}You get irritated when your\n"
    "{CENTER_ALIGN}friends don't show up on time.{EXTRA_MSG}"
    "{CENTER_ALIGN}You get frustrated when things\n"
    "{CENTER_ALIGN}don't turn out the way you expect.{EXTRA_MSG}"
    "{CENTER_ALIGN}Maybe you jab the elevator button\n"
    "{CENTER_ALIGN}if the elevator is slow to arrive.{EXTRA_MSG}"
    "{CENTER_ALIGN}...Maybe you're already jabbing\n"
    "{CENTER_ALIGN}the A Button repeatedly now.{EXTRA_MSG}"
    "{CENTER_ALIGN}Beware--getting too easily irritated\n"
    "{CENTER_ALIGN}just isn't good for your well-being.{EXTRA_MSG}"
    "{CENTER_ALIGN}A hasty person like you should be...");

ALIGNED(4) static const u8 gTimidDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The timid type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You may find it hard to go\n"
    "{CENTER_ALIGN}to the washroom at night.{EXTRA_MSG}"
    "{CENTER_ALIGN}You may also find it too frightening\n"
    "{CENTER_ALIGN}to go back to school to get something\n"
    "{CENTER_ALIGN}you left behind in class.{EXTRA_MSG}"
    "{CENTER_ALIGN}If you're ever walking on a dark\n"
    "{CENTER_ALIGN}street at night, you probably turn\n"
    "{CENTER_ALIGN}around often to check behind you.{EXTRA_MSG}"
    "{CENTER_ALIGN}But your timid nature is\n"
    "{CENTER_ALIGN}also your good point!{EXTRA_MSG}"
    "{CENTER_ALIGN}Because those who know fear are\n"
    "{CENTER_ALIGN}those who know true courage.{EXTRA_MSG}"
    "{CENTER_ALIGN}A timid person like you should be...");

ALIGNED(4) static const u8 gNaiveDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The naive type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You are highly curious,\n"
    "{CENTER_ALIGN}and you love rare things.{EXTRA_MSG}"
    "{CENTER_ALIGN}Your cheerful and carefree\n"
    "{CENTER_ALIGN}attitude should make things fun\n"
    "{CENTER_ALIGN}for the people around you.{EXTRA_MSG}"
    "{CENTER_ALIGN}But you do have one flaw.\n"
    "{CENTER_ALIGN}You can be childish.{EXTRA_MSG}"
    "{CENTER_ALIGN}You can never sit still.\n"
    "{CENTER_ALIGN}You're always on the move.{EXTRA_MSG}"
    "{CENTER_ALIGN}You can also be selfish,\n"
    "{CENTER_ALIGN}so you should watch yourself.{EXTRA_MSG}"
    "{CENTER_ALIGN}A naive person like you should be...");

ALIGNED(4) static const u8 gImpishDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The impish type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're playful, cheerful,\n"
    "{CENTER_ALIGN}and you love pranks.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're also kindhearted.{EXTRA_MSG}"
    "{CENTER_ALIGN}That's why the people around\n"
    "{CENTER_ALIGN}you find you so irresistible.{EXTRA_MSG}"
    "{CENTER_ALIGN}You must be the most\n"
    "{CENTER_ALIGN}popular person around!{EXTRA_MSG}"
    "{CENTER_ALIGN}Oh?{WAIT_PRESS} You're not that popular?{WAIT_PRESS}\n"
    "{CENTER_ALIGN}You're either being modest...\n"
    "{CENTER_ALIGN}or you just don't notice it.{EXTRA_MSG}"
    "{CENTER_ALIGN}I bet people are just too shy\n"
    "{CENTER_ALIGN}to let their feelings be known.{EXTRA_MSG}"
    "{CENTER_ALIGN}There's someone out there who's\n"
    "{CENTER_ALIGN}afraid to declare their love for you!{EXTRA_MSG}"
    "{CENTER_ALIGN}An impish person like you should be...");

ALIGNED(4) static const u8 gJollyDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The jolly type.{EXTRA_MSG}"
    "{CENTER_ALIGN}Always laughing and smiling,\n"
    "{CENTER_ALIGN}you uplift everyone around you.{EXTRA_MSG}"
    "{CENTER_ALIGN}You love jokes!{EXTRA_MSG}"
    "{CENTER_ALIGN}You have lots of friends, and\n"
    "{CENTER_ALIGN}you're popular wherever you go.{EXTRA_MSG}"
    "{CENTER_ALIGN}But sometimes you get carried away\n"
    "{CENTER_ALIGN}and say things that get you in trouble.{EXTRA_MSG}"
    "{CENTER_ALIGN}You should learn to think before\n"
    "{CENTER_ALIGN}saying or doing anything.{EXTRA_MSG}"
    "{CENTER_ALIGN}A jolly person like you should be...");

ALIGNED(4) static const u8 gBraveDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The brave type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You have a strong sense of justice.{WAIT_PRESS}\n"
    "{CENTER_ALIGN}You hate evil.{WAIT_PRESS}\n"
    "{CENTER_ALIGN}You will take on any opponent.{EXTRA_MSG}"
    "{CENTER_ALIGN}You are truly a hero!{EXTRA_MSG}"
    "{CENTER_ALIGN}Go forth!{EXTRA_MSG}"
    "{CENTER_ALIGN}For justice...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}For peace on earth...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}Fight the forces of evil!{EXTRA_MSG}"
    "{CENTER_ALIGN}......{WAIT_PRESS}If I'm wrong...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}Work at becoming a true hero!{EXTRA_MSG}"
    "{CENTER_ALIGN}A brave person like you should be...");

ALIGNED(4) static const u8 gDocileDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The docile type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're very kindhearted.{WAIT_PRESS}\n"
    "{CENTER_ALIGN}Very helpful.{WAIT_PRESS}\n"
    "{CENTER_ALIGN}You can make friends with anyone.{EXTRA_MSG}"
    "{CENTER_ALIGN}You're a wonderful person.{EXTRA_MSG}"
    "{CENTER_ALIGN}......{WAIT_PRESS}Is that going overboard?{WAIT_PRESS}\n"
    "{CENTER_ALIGN}I don't think so.{EXTRA_MSG}"
    "{CENTER_ALIGN}You yourself should be\n"
    "{CENTER_ALIGN}the best judge of that.{EXTRA_MSG}"
    "{CENTER_ALIGN}A docile person like you should be...");

ALIGNED(4) static const u8 gHardyDescription[] = _(
    "{CENTER_ALIGN}You appear to be...{WAIT_PRESS}\n"
    "{CENTER_ALIGN}The hardy type.{EXTRA_MSG}"
    "{CENTER_ALIGN}You do your homework diligently,\n"
    "{CENTER_ALIGN}and you know to eat properly.{EXTRA_MSG}"
    "{CENTER_ALIGN}You have strong willpower that lets\n"
    "{CENTER_ALIGN}you complete tasks, however tough.{EXTRA_MSG}"
    "{CENTER_ALIGN}But, you can also be stubborn to the\n"
    "{CENTER_ALIGN}point of even feuding with friends...{EXTRA_MSG}"
    "{CENTER_ALIGN}Nothing will go right for you when you're\n"
    "{CENTER_ALIGN}irritated, so learn to laugh it off.{EXTRA_MSG}"
    "{CENTER_ALIGN}A hardy person like you should be...");

static const UnkTextStruct2 sUnknown_80F4244 =
{
    0, 0, 0, 0,
    5,
    12, 6,
    5, 5,
    5, 0,
    NULL
};
