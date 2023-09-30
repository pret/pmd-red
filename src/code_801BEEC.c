#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_801BEEC.h"
#include "code_801C244.h"
#include "code_801C620.h"
#include "common_strings.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B238 *sUnknown_203B238 = {0};

#include "data/code_801BEEC.h"

static void sub_801BFB4(s32 newState);
static void sub_801BFCC(void);
static void sub_801C03C(void);
static void sub_801C0C8(void);
static void sub_801C118(void);
static void sub_801C1A0(void);
static void sub_801C228(void);

bool8 sub_801BEEC(s16 species)
{
    s32 species_s32 = species;

    if (HasNoAvailIQSkills(species_s32))
        return FALSE;

    sUnknown_203B238 = MemoryAlloc(sizeof(struct unkStruct_203B238), 8);
    sUnknown_203B238->menuAction = 0;
    sUnknown_203B238->species = species_s32;
    sUnknown_203B238->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    sUnknown_203B238->numIQSkills = GetNumAvailableIQSkills(sUnknown_203B238->iqSkills, sUnknown_203B238->pokeStruct->IQ);
    sub_801BFB4(0);
    return TRUE;
}

u32 sub_801BF48(void)
{
    switch (sUnknown_203B238->state) {
        case 4:
            return 3;
        case 0:
        case 1:
            sub_801C118();
            break;
        case 2:
            sub_801C1A0();
            break;
        case 3:
            sub_801C228();
            break;
    }
    return 0;
}

void sub_801BF98(void)
{
    if (sUnknown_203B238 != NULL) {
        MemoryFree(sUnknown_203B238);
        sUnknown_203B238 = NULL;
    }
}

static void sub_801BFB4(s32 newState)
{
    sUnknown_203B238->state = newState;
    sub_801BFCC();
    sub_801C03C();
}

static void sub_801BFCC(void)
{
    s32 i;

    sub_8006518(sUnknown_203B238->unkC4);

    if (sUnknown_203B238->state == 2)
        sUnknown_203B238->unkC4[2] = sUnknown_80DBDB0;
    else {
        for (i = 0; i < 4; i++)
            sUnknown_203B238->unkC4[i] = sUnknown_80DBD98;
    }

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B238->unkC4, TRUE, TRUE);
}

static void sub_801C03C(void)
{
    switch (sUnknown_203B238->state) {
        case 0:
            sub_801C244(sUnknown_203B238->species, 0, 8);
            break;
        case 1:
            sub_801C3B0(TRUE);
            break;
        case 2:
            sub_801C4C8();
            sub_801C0C8();
            sub_8012D60(&sUnknown_203B238->unk74, sUnknown_203B238->unk34, 0, 0, sUnknown_203B238->menuAction, 2);
            break;
        case 3:
            sub_801C620(sUnknown_203B238->iqSkillIndex);
            break;
        case 4:
            break;
    }
}

static void sub_801C0C8(void)
{
    struct unkStruct_203B238 *puVar1;
    s32 i;
    u8 *nullText;
    u32 menuAction;
    s32 max;

    puVar1 = sUnknown_203B238;
    nullText = NULL;

    sUnknown_203B238->unk34[0].text = sSwitch;
    puVar1->unk34[0].menuAction = 2;

    menuAction = 1;
    puVar1->unk34[1].text = gCommonInfo[0];
    puVar1->unk34[1].menuAction = 3;

    max = 2;
    puVar1->unk34[2].text = nullText;
    puVar1->unk34[2].menuAction = menuAction;

    for (i = 0; i < max; i++) {
        if (sUnknown_203B238->unk34[i].menuAction == sUnknown_203B238->menuAction)
            return;
    }

    sUnknown_203B238->menuAction = 2;
}

static void sub_801C118(void)
{
    switch (sub_801C308(TRUE)) {
        case 3:
            sUnknown_203B238->unk24 = sub_801C390();
            sUnknown_203B238->iqSkillIndex = sUnknown_203B238->iqSkills[sUnknown_203B238->unk24];
            sub_801BFB4(2);
            break;
        case 4:
            sUnknown_203B238->unk24 = sub_801C390();
            sUnknown_203B238->iqSkillIndex = sUnknown_203B238->iqSkills[sUnknown_203B238->unk24];
            sub_801BFB4(3);
            break;
        case 2:
            sub_801C3F8();
            sub_801BFB4(4);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_801C1A0(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801C308(FALSE);

    if (!sub_8012FD8(&sUnknown_203B238->unk74)) {
        sub_8013114(&sUnknown_203B238->unk74, &menuAction);

        if (menuAction != 1)
            sUnknown_203B238->menuAction = menuAction;
    }

    switch (menuAction) {
        case 2:
            PlaySound(307);
            ToggleIQSkill((u8 *)&sUnknown_203B238->pokeStruct->IQSkills, sUnknown_203B238->iqSkillIndex);
            sub_801BFB4(1);
            break;
        case 3:
            sub_801BFB4(3);
            break;
        case 1:
            sub_801BFB4(1);
            break;
    }
}

static void sub_801C228(void)
{
    switch (sub_801C674()) {
        case 2:
        case 3:
            sub_801C6B4();
            sub_801BFB4(1);
        case 0:
        case 1:
            break;
    }
}