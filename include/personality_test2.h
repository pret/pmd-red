#ifndef GUARD_PERSONALITY_TEST2_H
#define GUARD_PERSONALITY_TEST2_H

#include "constants/personality_test.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "text_3.h"

// Size: 0xB8
struct PersonalityStruct_203B404
{
    /* 0x0 */ s16 StarterID;
    /* 0x2 */ s16 PartnerArray[NUM_PARTNERS];
    u8 unk16;
    /* 0x18 */ MenuHeaderWindow s18;
};

void CreatePartnerSelectionMenu(s16 starterID);
u16 HandlePartnerSelectionInput(void);

void sub_803CE6C(void);

#endif // GUARD_PERSONALITY_TEST2_H
