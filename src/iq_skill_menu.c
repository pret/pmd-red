#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "iq_skill_menu.h"
#include "iq_skill_list_menu.h"
#include "code_801C620.h"
#include "common_strings.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B238 *sUnknown_203B238 = {0};

#include "data/iq_skill_menu.h"

static void SetIQSkillMenuState(s32 newState);
static void sub_801BFCC(void);
static void HandleIQSkillMenuState(void);
static void BuildIQSkillMenuActions(void);
static void sub_801C118(void);
static void sub_801C1A0(void);
static void HandleIQSkillMenuInfo(void);

bool8 CreateIQSkillMenu(s16 species)
{
    s32 species_s32 = species;

    if (HasNoAvailIQSkills(species_s32))
        return FALSE;

    sUnknown_203B238 = MemoryAlloc(sizeof(struct unkStruct_203B238), 8);
    sUnknown_203B238->menuAction = 0;
    sUnknown_203B238->species = species_s32;
    sUnknown_203B238->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    sUnknown_203B238->numIQSkills = GetNumAvailableIQSkills(sUnknown_203B238->iqSkills, sUnknown_203B238->pokeStruct->IQ);
    SetIQSkillMenuState(IQ_SKILL_MENU_STATE_INIT);
    return TRUE;
}

u32 sub_801BF48(void)
{
    switch (sUnknown_203B238->state) {
        case IQ_SKILL_MENU_STATE_EXIT:
            return 3;
        case IQ_SKILL_MENU_STATE_INIT:
        case IQ_SKILL_MENU_STATE_MAIN:
            sub_801C118();
            break;
        case 2:
            sub_801C1A0();
            break;
        case IQ_SKILL_MENU_STATE_INFO:
            HandleIQSkillMenuInfo();
            break;
    }
    return 0;
}

void CleanIQSkillMenu(void)
{
    if (sUnknown_203B238 != NULL) {
        MemoryFree(sUnknown_203B238);
        sUnknown_203B238 = NULL;
    }
}

static void SetIQSkillMenuState(s32 newState)
{
    sUnknown_203B238->state = newState;
    sub_801BFCC();
    HandleIQSkillMenuState();
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

static void HandleIQSkillMenuState(void)
{
    switch (sUnknown_203B238->state) {
        case IQ_SKILL_MENU_STATE_INIT:
            CreateIQSkillListMenu(sUnknown_203B238->species, 0, 8);
            break;
        case IQ_SKILL_MENU_STATE_MAIN:
            sub_801C3B0(TRUE);
            break;
        case 2:
            BuildIQSkillList(); // Build list of IQ Skills
            BuildIQSkillMenuActions();
            sub_8012D60(&sUnknown_203B238->unk74, sUnknown_203B238->unk34, NULL, NULL, sUnknown_203B238->menuAction, 2);
            break;
        case IQ_SKILL_MENU_STATE_INFO:
            CreateIQSkillInfoMenu(sUnknown_203B238->iqSkillIndex);
            break;
        case IQ_SKILL_MENU_STATE_EXIT:
            break;
    }
}

static void BuildIQSkillMenuActions(void)
{
    struct unkStruct_203B238 *puVar1;
    s32 i;
    u8 *nullText;
    u32 menuAction;
    s32 max;

    puVar1 = sUnknown_203B238;
    nullText = NULL;

    sUnknown_203B238->unk34[0].text = sSwitch;
    puVar1->unk34[0].menuAction = IQ_SKILL_MENU_SWITCH;

    menuAction = IQ_SKILL_MENU_NULL;
    puVar1->unk34[1].text = gCommonInfo[0];
    puVar1->unk34[1].menuAction = IQ_SKILL_MENU_INFO;

    max = 2;
    puVar1->unk34[2].text = nullText;
    puVar1->unk34[2].menuAction = menuAction;

    for (i = 0; i < max; i++) {
        if (sUnknown_203B238->unk34[i].menuAction == sUnknown_203B238->menuAction)
            return;
    }

    sUnknown_203B238->menuAction = IQ_SKILL_MENU_SWITCH;
}

static void sub_801C118(void)
{
    switch (HandleIQSkillListMenuInput(TRUE)) {
        case 3:
            sUnknown_203B238->menuIndex = GetIQSkillSelection();
            sUnknown_203B238->iqSkillIndex = sUnknown_203B238->iqSkills[sUnknown_203B238->menuIndex];
            SetIQSkillMenuState(2);
            break;
        case 4:
            sUnknown_203B238->menuIndex = GetIQSkillSelection();
            sUnknown_203B238->iqSkillIndex = sUnknown_203B238->iqSkills[sUnknown_203B238->menuIndex];
            SetIQSkillMenuState(IQ_SKILL_MENU_STATE_INFO);
            break;
        case 2:
            CleanIQSkillListMenu();
            SetIQSkillMenuState(IQ_SKILL_MENU_STATE_EXIT);
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
    HandleIQSkillListMenuInput(FALSE);

    if (!sub_8012FD8(&sUnknown_203B238->unk74)) {
        sub_8013114(&sUnknown_203B238->unk74, &menuAction);

        if (menuAction != IQ_SKILL_MENU_NULL)
            sUnknown_203B238->menuAction = menuAction;
    }

    switch (menuAction) {
        case IQ_SKILL_MENU_SWITCH: // Switch
            PlaySound(307);
            ToggleIQSkill((u8 *)&sUnknown_203B238->pokeStruct->IQSkills, sUnknown_203B238->iqSkillIndex);
            SetIQSkillMenuState(IQ_SKILL_MENU_STATE_MAIN);
            break;
        case IQ_SKILL_MENU_INFO: // Info
            SetIQSkillMenuState(IQ_SKILL_MENU_STATE_INFO);
            break;
        case IQ_SKILL_MENU_NULL:
            SetIQSkillMenuState(IQ_SKILL_MENU_STATE_MAIN);
            break;
    }
}

static void HandleIQSkillMenuInfo(void)
{
    switch (HandleIQSkillInfoMenuState()) {
        case 2:
        case 3:
            CleanIQSkillInfoMenu();
            SetIQSkillMenuState(IQ_SKILL_MENU_STATE_MAIN);
        case 0:
        case 1:
            break;
    }
}
