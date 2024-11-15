

#include "locale/personality_test1_usa.h"


ALIGNED(4) static const PersonalityEffects HardyQuest1Points[] = {
    { [HARDY] = 2, },
    { [RELAXED] = 2, },
    { [IMPISH] = 2, },
};
static const MenuItem HardyQuest1Answers[] = {
    { HARDY_Q1_A0, 0 },
    { HARDY_Q1_A1, 1 },
    { HARDY_Q1_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion HardyQuest1 = { HARDY_Q1, HardyQuest1Answers, HardyQuest1Points };

ALIGNED(4) static const PersonalityEffects HardyQuest2Points[] = {
    { [HARDY] = 2, [DOCILE] = 1, },
    { [QUIRKY] = 2, },
};
static const MenuItem HardyQuest2Answers[] = {
    { HARDY_Q2_A0, 0 },
    { HARDY_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion HardyQuest2 = { HARDY_Q2, HardyQuest2Answers, HardyQuest2Points };

ALIGNED(4) static const PersonalityEffects HardyQuest3Points[] = {
    { [HARDY] = 2, [BRAVE] = 2, },
    { [SASSY] = 2, [QUIRKY] = 2, },
};
static const MenuItem HardyQuest3Answers[] = {
    { HARDY_Q3_A0, 0 },
    { HARDY_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion HardyQuest3 = { HARDY_Q3, HardyQuest3Answers, HardyQuest3Points };

ALIGNED(4) static const PersonalityEffects HardyQuest4Points[] = {
    { [HARDY] = 2, },
    { [CALM] = 2, },
    { [QUIRKY] = 2, },
};
static const MenuItem HardyQuest4Answers[] = {
    { HARDY_Q4_A0, 0 },
    { HARDY_Q4_A1, 1 },
    { HARDY_Q4_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion HardyQuest4 = { HARDY_Q4, HardyQuest4Answers, HardyQuest4Points };



ALIGNED(4) static const PersonalityEffects DocileQuest1Points[] = {
    { [DOCILE] = 2, [NAIVE] = 1, },
    { [TIMID] = 2, [CALM] = 1, },
};
static const MenuItem DocileQuest1Answers[] = {
    { DOCILE_Q1_A0, 0 },
    { DOCILE_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion DocileQuest1 = { DOCILE_Q1, DocileQuest1Answers, DocileQuest1Points };

ALIGNED(4) static const PersonalityEffects DocileQuest2Points[] = {
    { [DOCILE] = 2, [HASTY] = 1, },
    { [NAIVE] = 2, [RELAXED] = 1, },
};
static const MenuItem DocileQuest2Answers[] = {
    { DOCILE_Q2_A0, 0 },
    { DOCILE_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion DocileQuest2 = { DOCILE_Q2, DocileQuest2Answers, DocileQuest2Points };

ALIGNED(4) static const PersonalityEffects DocileQuest3Points[] = {
    { [DOCILE] = 2, },
    { [NAIVE] = 1, [LONELY] = 1, },
    { [SASSY] = 2, },
};
static const MenuItem DocileQuest3Answers[] = {
    { DOCILE_Q3_A0, 0 },
    { DOCILE_Q3_A1, 1 },
    { DOCILE_Q3_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion DocileQuest3 = { DOCILE_Q3, DocileQuest3Answers, DocileQuest3Points };

ALIGNED(4) static const PersonalityEffects DocileQuest4Points[] = {
    { [DOCILE] = 2, },
    { [NAIVE] = 2, },
    { [IMPISH] = 2, },
};
static const MenuItem DocileQuest4Answers[] = {
    { DOCILE_Q4_A0, 0 },
    { DOCILE_Q4_A1, 1 },
    { DOCILE_Q4_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion DocileQuest4 = { DOCILE_Q4, DocileQuest4Answers, DocileQuest4Points };



ALIGNED(4) static const PersonalityEffects BraveQuest1Points[] = {
    { [BRAVE] = 3, [IMPISH] = 1, },
    { [DOCILE] = 2, [TIMID] = 1, },
};
static const MenuItem BraveQuest1Answers[] = {
    { BRAVE_Q1_A0, 0 },
    { BRAVE_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion BraveQuest1 = { BRAVE_Q1, BraveQuest1Answers, BraveQuest1Points };

ALIGNED(4) static const PersonalityEffects BraveQuest2APoints[] = {
    { /* Empty */ },
    { [TIMID] = 2, },
    { [RELAXED] = 2, },
};
static const MenuItem BraveQuest2AAnswers[] = {
    { BRAVE_Q2A_A0, 99 },
    { BRAVE_Q2A_A1, 1 },
    { BRAVE_Q2A_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion BraveQuest2A = { BRAVE_Q2A, BraveQuest2AAnswers, BraveQuest2APoints };

ALIGNED(4) static const PersonalityEffects BraveQuest2BPoints[] = {
    { [SASSY] = 1, [RELAXED] = 1, },
    { [BRAVE] = 4, },
};
static const MenuItem BraveQuest2BAnswers[] = {
    { BRAVE_Q2B_A0, 0 },
    { BRAVE_Q2B_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion BraveQuest2B = { BRAVE_Q2B, BraveQuest2BAnswers, BraveQuest2BPoints };

ALIGNED(4) static const PersonalityEffects BraveQuest3Points[] = {
    { [HARDY] = 1, [BRAVE] = 2, },
    { [NAIVE] = 2, },
};
static const MenuItem BraveQuest3Answers[] = {
    { BRAVE_Q3_A0, 0 },
    { BRAVE_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion BraveQuest3 = { BRAVE_Q3, BraveQuest3Answers, BraveQuest3Points };

ALIGNED(4) static const PersonalityEffects BraveQuest4Points[] = {
    { [BRAVE] = 3, },
    { [HARDY] = 2, [BRAVE] = 2, },
    { [DOCILE] = 1, [TIMID] = 1, [RELAXED] = 1, },
    { [TIMID] = 2, },
};
static const MenuItem BraveQuest4Answers[] =
{
    { BRAVE_Q4_A0, 0 },
    { BRAVE_Q4_A1, 1 },
    { BRAVE_Q4_A2, 2 },
    { BRAVE_Q4_A3, 3 },
    { NULL, -1 },
};
static const PersonalityQuestion BraveQuest4 = { BRAVE_Q4, BraveQuest4Answers, BraveQuest4Points };



ALIGNED(4) static const PersonalityEffects JollyQuest1Points[] = {
    { [JOLLY] = 2, [NAIVE] = 1, },
    { [SASSY] = 1, [QUIRKY] = 1, },
};
static const MenuItem JollyQuest1Answers[] = {
    { JOLLY_Q1_A0, 0 },
    { JOLLY_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion JollyQuest1 = { JOLLY_Q1, JollyQuest1Answers, JollyQuest1Points };

ALIGNED(4) static const PersonalityEffects JollyQuest2Points[] = {
    { [JOLLY] = 2, [LONELY] = 1, },
    { [TIMID] = 1, },
};
static const MenuItem JollyQuest2Answers[] = {
    { JOLLY_Q2_A0, 0 },
    { JOLLY_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion JollyQuest2 = { JOLLY_Q2, JollyQuest2Answers, JollyQuest2Points };

ALIGNED(4) static const PersonalityEffects JollyQuest3Points[] = {
    { [JOLLY] = 2, },
    { [CALM] = 2, },
    { [QUIRKY] = 2, },
};
static const MenuItem JollyQuest3Answers[] = {
    { JOLLY_Q3_A0, 0 },
    { JOLLY_Q3_A1, 1 },
    { JOLLY_Q3_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion JollyQuest3 = { JOLLY_Q3, JollyQuest3Answers, JollyQuest3Points };

ALIGNED(4) static const PersonalityEffects JollyQuest4Points[] = {
    { [JOLLY] = 3, },
    { [HARDY] = 2, },
    { [TIMID] = 2, },
};
static const MenuItem JollyQuest4Answers[] = {
    { JOLLY_Q4_A0, 0 },
    { JOLLY_Q4_A1, 1 },
    { JOLLY_Q4_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion JollyQuest4 = { JOLLY_Q4, JollyQuest4Answers, JollyQuest4Points };



ALIGNED(4) static const PersonalityEffects ImpishQuest1Points[] = {
    { [IMPISH] = 2, [LONELY] = 1, },
    { [CALM] = 2, },
};
static const MenuItem ImpishQuest1Answers[] = {
    { IMPISH_Q1_A0, 0 },
    { IMPISH_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion ImpishQuest1 = { IMPISH_Q1, ImpishQuest1Answers, ImpishQuest1Points };

ALIGNED(4) static const PersonalityEffects ImpishQuest2Points[] = {
    { [IMPISH] = 2, },
    { [DOCILE] = 1, [RELAXED] = 1, },
};
static const MenuItem ImpishQuest2Answers[] = {
    { IMPISH_Q2_A0, 0 },
    { IMPISH_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion ImpishQuest2 = { IMPISH_Q2, ImpishQuest2Answers, ImpishQuest2Points };

ALIGNED(4) static const PersonalityEffects ImpishQuest3Points[] = {
    { [HARDY] = 1, [IMPISH] = 2, },
    { [SASSY] = 1, [QUIRKY] = 2, },
};
static const MenuItem ImpishQuest3Answers[] = {
    { IMPISH_Q3_A0, 0 },
    { IMPISH_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion ImpishQuest3 = { IMPISH_Q3, ImpishQuest3Answers, ImpishQuest3Points };

ALIGNED(4) static const PersonalityEffects ImpishQuest4Points[] = {
    { [BRAVE] = 3, },
    { [TIMID] = 2, },
    { [IMPISH] = 2, },
};
static const MenuItem ImpishQuest4Answers[] = {
    { IMPISH_Q4_A0, 0 },
    { IMPISH_Q4_A1, 1 },
    { IMPISH_Q4_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion ImpishQuest4 = { IMPISH_Q4, ImpishQuest4Answers, ImpishQuest4Points };



ALIGNED(4) static const PersonalityEffects NaiveQuest1Points[] = {
    { [IMPISH] = 1, [NAIVE] = 3, },
    { [JOLLY] = 2, },
    { [SASSY] = 2, },
};
static const MenuItem NaiveQuest1Answers[] = {
    { NAIVE_Q1_A0, 0 },
    { NAIVE_Q1_A1, 1 },
    { NAIVE_Q1_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion NaiveQuest1 = { NAIVE_Q1, NaiveQuest1Answers, NaiveQuest1Points };

ALIGNED(4) static const PersonalityEffects NaiveQuest2Points[] = {
    { [DOCILE] = 1, [NAIVE] = 2, },
    { [QUIRKY] = 2, },
};
static const MenuItem NaiveQuest2Answers[] = {
    { NAIVE_Q2_A0, 0 },
    { NAIVE_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion NaiveQuest2 = { NAIVE_Q2, NaiveQuest2Answers, NaiveQuest2Points };

ALIGNED(4) static const PersonalityEffects NaiveQuest3Points[] = {
    { [JOLLY] = 1, [NAIVE] = 2, },
    { [CALM] = 2, },
};
static const MenuItem NaiveQuest3Answers[] = {
    { NAIVE_Q3_A0, 0 },
    { NAIVE_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion NaiveQuest3 = { NAIVE_Q3, NaiveQuest3Answers, NaiveQuest3Points };

ALIGNED(4) static const PersonalityEffects NaiveQuest4Points[] = {
    { [NAIVE] = 2, },
    { [HASTY] = 2, },
};
static const MenuItem NaiveQuest4Answers[] = {
    { NAIVE_Q4_A0, 0 },
    { NAIVE_Q4_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion NaiveQuest4 = { NAIVE_Q4, NaiveQuest4Answers, NaiveQuest4Points };



ALIGNED(4) static const PersonalityEffects TimidQuest1Points[] = {
    { [TIMID] = 2, },
    { [HARDY] = 1, [CALM] = 2, },
    { [BRAVE] = 2, [IMPISH] = 1, [NAIVE] = 1, },
};
static const MenuItem TimidQuest1Answers[] = {
    { TIMID_Q1_A0, 0 },
    { TIMID_Q1_A1, 1 },
    { TIMID_Q1_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion TimidQuest1 = { TIMID_Q1, TimidQuest1Answers, TimidQuest1Points };

ALIGNED(4) static const PersonalityEffects TimidQuest2Points[] = {
    { [TIMID] = 2, },
    { [HASTY] = 2, },
    { [JOLLY] = 2, },
    { [SASSY] = 2, },
    { [LONELY] = 2, },
};
static const MenuItem TimidQuest2Answers[] = {
    { TIMID_Q2_A0, 0 },
    { TIMID_Q2_A1, 1 },
    { TIMID_Q2_A2, 2 },
    { TIMID_Q2_A3, 3 },
    { TIMID_Q2_A4, 4 },
    { NULL, -1 },
};
static const PersonalityQuestion TimidQuest2 = { TIMID_Q2, TimidQuest2Answers, TimidQuest2Points };

ALIGNED(4) static const PersonalityEffects TimidQuest3Points[] = {
    { [TIMID] = 2, },
    { [LONELY] = 2, },
    { [IMPISH] = 2, [QUIRKY] = 1, },
};
static const MenuItem TimidQuest3Answers[] = {
    { TIMID_Q3_A0, 0 },
    { TIMID_Q3_A1, 1 },
    { TIMID_Q3_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion TimidQuest3 = { TIMID_Q3, TimidQuest3Answers, TimidQuest3Points };

ALIGNED(4) static const PersonalityEffects TimidQuest4Points[] = {
    { [BRAVE] = 3, },
    { [TIMID] = 2, },
    { [SASSY] = 2, },
};
static const MenuItem TimidQuest4Answers[] = {
    { TIMID_Q4_A0, 0 },
    { TIMID_Q4_A1, 1 },
    { TIMID_Q4_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion TimidQuest4 = { TIMID_Q4, TimidQuest4Answers, TimidQuest4Points };



ALIGNED(4) static const PersonalityEffects HastyQuest1Points[] = {
    { [HASTY] = 2, },
    { [CALM] = 2, },
    { [TIMID] = 2, },
};
static const MenuItem HastyQuest1Answers[] = {
    { HASTY_Q1_A0, 0 },
    { HASTY_Q1_A1, 1 },
    { HASTY_Q1_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion HastyQuest1 = { HASTY_Q1, HastyQuest1Answers, HastyQuest1Points };

ALIGNED(4) static const PersonalityEffects HastyQuest2Points[] = {
    { [JOLLY] = 2, [HASTY] = 1, },
    { [HARDY] = 1, [CALM] = 1, },
    { [BRAVE] = 2, [QUIRKY] = 2, },
};
static const MenuItem HastyQuest2Answers[] = {
    { HASTY_Q2_A0, 0 },
    { HASTY_Q2_A1, 1 },
    { HASTY_Q2_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion HastyQuest2 = { HASTY_Q2, HastyQuest2Answers, HastyQuest2Points };

ALIGNED(4) static const PersonalityEffects HastyQuest3Points[] = {
    { [HASTY] = 2, },
    { [TIMID] = 2, },
    { [SASSY] = 2, },
};
static const MenuItem HastyQuest3Answers[] = {
    { HASTY_Q3_A0, 0 },
    { HASTY_Q3_A1, 1 },
    { HASTY_Q3_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion HastyQuest3 = { HASTY_Q3, HastyQuest3Answers, HastyQuest3Points };

ALIGNED(4) static const PersonalityEffects HastyQuest4Points[] = {
    { [DOCILE] = 1, [HASTY] = 2, },
    { [RELAXED] = 2, },
    { [HASTY] = 3, },
};
static const MenuItem HastyQuest4Answers[] = {
    { HASTY_Q4_A0, 0 },
    { HASTY_Q4_A1, 1 },
    { HASTY_Q4_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion HastyQuest4 = { HASTY_Q4, HastyQuest4Answers, HastyQuest4Points };



ALIGNED(4) static const PersonalityEffects SassyQuest1Points[] = {
    { [HARDY] = 2, },
    { [DOCILE] = 2, },
    { [SASSY] = 2, },
};
static const MenuItem SassyQuest1Answers[] = {
    { SASSY_Q1_A0, 0 },
    { SASSY_Q1_A1, 1 },
    { SASSY_Q1_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion SassyQuest1 = { SASSY_Q1, SassyQuest1Answers, SassyQuest1Points };

ALIGNED(4) static const PersonalityEffects SassyQuest2Points[] = {
    { [IMPISH] = 1, [SASSY] = 2, },
    { [CALM] = 2, },
};
static const MenuItem SassyQuest2Answers[] = {
    { SASSY_Q2_A0, 0 },
    { SASSY_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion SassyQuest2 = { SASSY_Q2, SassyQuest2Answers, SassyQuest2Points };

ALIGNED(4) static const PersonalityEffects SassyQuest3Points[] = {
    { [SASSY] = 2, },
    { [RELAXED] = 2, },
};
static const MenuItem SassyQuest3Answers[] = {
    { SASSY_Q3_A0, 0 },
    { SASSY_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion SassyQuest3 = { SASSY_Q3, SassyQuest3Answers, SassyQuest3Points };

ALIGNED(4) static const PersonalityEffects SassyQuest4Points[] = {
    { [DOCILE] = 2, [CALM] = 1, },
    { [SASSY] = 2, [QUIRKY] = 1, },
};
static const MenuItem SassyQuest4Answers[] = {
    { SASSY_Q4_A0, 0 },
    { SASSY_Q4_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion SassyQuest4 = { SASSY_Q4, SassyQuest4Answers, SassyQuest4Points };



ALIGNED(4) static const PersonalityEffects CalmQuest1Points[] = {
    { [CALM] = 2, [LONELY] = 1, },
    { [HARDY] = 2, },
};
static const MenuItem CalmQuest1Answers[] = {
    { CALM_Q1_A0, 0 },
    { CALM_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion CalmQuest1 = { CALM_Q1, CalmQuest1Answers, CalmQuest1Points };

ALIGNED(4) static const PersonalityEffects CalmQuest2Points[] = {
    { [CALM] = 2, },
    { [IMPISH] = 2, },
};
static const MenuItem CalmQuest2Answers[] = {
    { CALM_Q2_A0, 0 },
    { CALM_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion CalmQuest2 = { CALM_Q2, CalmQuest2Answers, CalmQuest2Points };

ALIGNED(4) static const PersonalityEffects CalmQuest3Points[] = {
    { [IMPISH] = 1, [TIMID] = 2, },
    { [CALM] = 2, [LONELY] = 1, },
};
static const MenuItem CalmQuest3Answers[] = {
    { CALM_Q3_A0, 0 },
    { CALM_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion CalmQuest3 = { CALM_Q3, CalmQuest3Answers, CalmQuest3Points };

ALIGNED(4) static const PersonalityEffects CalmQuest4Points[] = {
    { [CALM] = 2, [RELAXED] = 1, },
    { [HARDY] = 1, [HASTY] = 2, },
};
static const MenuItem CalmQuest4Answers[] = {
    { CALM_Q4_A0, 0 },
    { CALM_Q4_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion CalmQuest4 = { CALM_Q4, CalmQuest4Answers, CalmQuest4Points };



ALIGNED(4) static const PersonalityEffects RelaxedQuest1Points[] = {
    { [SASSY] = 1, [RELAXED] = 2, },
    { [HARDY] = 2, [HASTY] = 1, },
};
static const MenuItem RelaxedQuest1Answers[] = {
    { RELAXED_Q1_A0, 0 },
    { RELAXED_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion RelaxedQuest1 = { RELAXED_Q1, RelaxedQuest1Answers, RelaxedQuest1Points };

ALIGNED(4) static const PersonalityEffects RelaxedQuest2Points[] = {
    { [RELAXED] = 2, },
    { [IMPISH] = 1, [HASTY] = 2, },
};
static const MenuItem RelaxedQuest2Answers[] = {
    { RELAXED_Q2_A0, 0 },
    { RELAXED_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion RelaxedQuest2 = { RELAXED_Q2, RelaxedQuest2Answers, RelaxedQuest2Points };

ALIGNED(4) static const PersonalityEffects RelaxedQuest3Points[] = {
    { [JOLLY] = 2, },
    { [RELAXED] = 2, },
    { [HASTY] = 2, },
};
static const MenuItem RelaxedQuest3Answers[] = {
    { RELAXED_Q3_A0, 0 },
    { RELAXED_Q3_A1, 1 },
    { RELAXED_Q3_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion RelaxedQuest3 = { RELAXED_Q3, RelaxedQuest3Answers, RelaxedQuest3Points };

ALIGNED(4) static const PersonalityEffects RelaxedQuest4Points[] = {
    { [CALM] = 1, [RELAXED] = 2, },
    { [HARDY] = 2, },
};
static const MenuItem RelaxedQuest4Answers[] = {
    { RELAXED_Q4_A0, 0 },
    { RELAXED_Q4_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion RelaxedQuest4 = { RELAXED_Q4, RelaxedQuest4Answers, RelaxedQuest4Points };



ALIGNED(4) static const PersonalityEffects LonelyQuest1Points[] = {
    { [TIMID] = 1, [LONELY] = 2, },
    { [SASSY] = 2, },
};
static const MenuItem LonelyQuest1Answers[] = {
    { LONELY_Q1_A0, 0 },
    { LONELY_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion LonelyQuest1 = { LONELY_Q1, LonelyQuest1Answers, LonelyQuest1Points };

ALIGNED(4) static const PersonalityEffects LonelyQuest2Points[] = {
    { [TIMID] = 1, [LONELY] = 2, },
    { [BRAVE] = 3, [RELAXED] = 1, },
};
static const MenuItem LonelyQuest2Answers[] = {
    { LONELY_Q2_A0, 0 },
    { LONELY_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion LonelyQuest2 = { LONELY_Q2, LonelyQuest2Answers, LonelyQuest2Points };

ALIGNED(4) static const PersonalityEffects LonelyQuest3Points[] = {
    { [TIMID] = 1, [LONELY] = 2, },
    { [CALM] = 2, },
};
static const MenuItem LonelyQuest3Answers[] = {
    { LONELY_Q3_A0, 0 },
    { LONELY_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion LonelyQuest3 = { LONELY_Q3, LonelyQuest3Answers, LonelyQuest3Points };

ALIGNED(4) static const PersonalityEffects LonelyQuest4Points[] = {
    { [JOLLY] = 1, [LONELY] = 1, },
    { [CALM] = 1, [RELAXED] = 2, },
    { [TIMID] = 1, [LONELY] = 3, },
};
static const MenuItem LonelyQuest4Answers[] = {
    { LONELY_Q4_A0, 0 },
    { LONELY_Q4_A1, 1 },
    { LONELY_Q4_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion LonelyQuest4 = { LONELY_Q4, LonelyQuest4Answers, LonelyQuest4Points };



ALIGNED(4) static const PersonalityEffects QuirkyQuest1Points[] = {
    { [QUIRKY] = 2, },
    { [HARDY] = 2, },
};
static const MenuItem QuirkyQuest1Answers[] = {
    { QUIRKY_Q1_A0, 0 },
    { QUIRKY_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion QuirkyQuest1 = { QUIRKY_Q1, QuirkyQuest1Answers, QuirkyQuest1Points };

ALIGNED(4) static const PersonalityEffects QuirkyQuest2Points[] = {
    { [HARDY] = 1, [HASTY] = 1, },
    { [QUIRKY] = 2, },
    { [SASSY] = 2, },
};
static const MenuItem QuirkyQuest2Answers[] = {
    { QUIRKY_Q2_A0, 0 },
    { QUIRKY_Q2_A1, 1 },
    { QUIRKY_Q2_A2, 2 },
    { NULL, -1 },
};
static const PersonalityQuestion QuirkyQuest2 = { QUIRKY_Q2, QuirkyQuest2Answers, QuirkyQuest2Points };

ALIGNED(4) static const PersonalityEffects QuirkyQuest3Points[] = {
    { [HARDY] = 1, [BRAVE] = 3, },
    { [QUIRKY] = 2, },
    { [IMPISH] = 2, },
    { [TIMID] = 2, },
};
static const MenuItem QuirkyQuest3Answers[] = {
    { QUIRKY_Q3_A0, 0 },
    { QUIRKY_Q3_A1, 1 },
    { QUIRKY_Q3_A2, 2 },
    { QUIRKY_Q3_A3, 3 },
    { NULL, -1 },
};
static const PersonalityQuestion QuirkyQuest3 = { QUIRKY_Q3, QuirkyQuest3Answers, QuirkyQuest3Points };

ALIGNED(4) static const PersonalityEffects QuirkyQuest4Points[] = {
    { [DOCILE] = 2, },
    { [SASSY] = 2, },
    { [QUIRKY] = 2, },
};
static const MenuItem QuirkyQuest4Answers[] = {
    {QUIRKY_Q4_A0, 0},
    {QUIRKY_Q4_A1, 1},
    {QUIRKY_Q4_A2, 2},
    {NULL, -1},
};
static const PersonalityQuestion QuirkyQuest4 = { QUIRKY_Q4, QuirkyQuest4Answers, QuirkyQuest4Points };



ALIGNED(4) static const PersonalityEffects MiscQuest1Points[] = {
    { [HASTY] = 1, [QUIRKY] = 1, },
    { [JOLLY] = 1, [LONELY] = 1, },
};
static const MenuItem MiscQuest1Answers[] = {
    { MISC_Q1_A0, 0 },
    { MISC_Q1_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion MiscQuest1 = { MISC_Q1, MiscQuest1Answers, MiscQuest1Points };

ALIGNED(4) static const PersonalityEffects MiscQuest2Points[] = {
    { [JOLLY] = 2, },
    { [SASSY] = 1, [QUIRKY] = 1, },
};
static const MenuItem MiscQuest2Answers[] = {
    { MISC_Q2_A0, 0 },
    { MISC_Q2_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion MiscQuest2 = { MISC_Q2, MiscQuest2Answers, MiscQuest2Points };

ALIGNED(4) static const PersonalityEffects MiscQuest3Points[] = {
    { [NAIVE] = 1, [LONELY] = 1, },
    { [HASTY] = 1, [SASSY] = 1, },
};
static const MenuItem MiscQuest3Answers[] = {
    { MISC_Q3_A0, 0 },
    { MISC_Q3_A1, 1 },
    { NULL, -1 },
};
static const PersonalityQuestion MiscQuest3 = { MISC_Q3, MiscQuest3Answers, MiscQuest3Points };



static const PersonalityQuestion* const gPersonalityQuestionPointerTable[NUM_QUIZ_QUESTIONS + 1] = {
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
static const u8 gNatureQuestionTable[NUM_QUIZ_QUESTIONS + 1] = {
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



ALIGNED(4) static const u8 sGender0[] = GENDER_Q;
UNUSED ALIGNED(4) static const u8* const gGenderTextPtr[] = { sGender0 };

static const MenuItem gGenderMenu[] = {
    { GENDER_A0, 0 },
    { GENDER_A1, 1 },
    { NULL, -1 },
};



UNUSED static const u8 unknownPersonality[NUM_PERSONALITIES] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
};

static const s16 gStarters[NUM_PERSONALITIES][2] = {
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



ALIGNED(4) static const u8 gStarterReveal[] = STARTER_REVEAL;
UNUSED ALIGNED(4) static const u8* const gStarterRevealPtr[] = { gStarterReveal };

ALIGNED(4) static const u8 gPartnerPrompt[] = PARTNER_PROMPT;
UNUSED ALIGNED(4) static const u8* const gPartnerPromptPtr = gPartnerPrompt;

ALIGNED(4) static const u8 gPartnerNickPrompt[] = PARTNER_NICK_PROMPT;
UNUSED ALIGNED(4) static const u8* const gPartnerNickPromptPtr[] = { gPartnerNickPrompt };

ALIGNED(4) static const u8 gEndIntroText[] = END_TEXT;
UNUSED ALIGNED(4) static const u8* const gEndIntroTextPtr[] = { gEndIntroText };



static const u8* const sPersonalityTypeDescriptionTable[NUM_PERSONALITIES] = {
    [HARDY] = DESC_HARDY,
    [DOCILE] = DESC_DOCILE,
    [BRAVE] = DESC_BRAVE,
    [JOLLY] = DESC_JOLLY,
    [IMPISH] = DESC_IMPISH,
    [NAIVE] = DESC_NAIVE,
    [TIMID] = DESC_TIMID,
    [HASTY] = DESC_HASTY,
    [SASSY] = DESC_SASSY,
    [CALM] = DESC_CALM,
    [RELAXED] = DESC_RELAXED,
    [LONELY] = DESC_LONELY,
    [QUIRKY] = DESC_QUIRKY
};

static const UnkTextStruct2 sUnknown_80F4244 = {
    0, 0, 0, 0,
    5,
    12, 6,
    5, 5,
    5, 0,
    NULL
};