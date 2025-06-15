#include "global.h"
#include "globaldata.h"
#include "music_util.h"
#include "common_strings.h"
#include "input.h"
#include "iq_skill_menu.h"
#include "iq_skill_list_menu.h"
#include "iq_skill_info_menu.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text_1.h"

static EWRAM_INIT struct IQSkillMenu *sIQSkillMenu = {NULL};

#include "data/iq_skill_menu.h"

static void SetIQSkillMenuState(s32 newState);
static void sub_801BFCC(void);
static void HandleIQSkillMenuState(void);
static void BuildIQSkillMenuActions(void);
static void HandleIQSkillMenuMain(void);
static void HandleIQSkillMenuAction(void);
static void HandleIQSkillMenuInfo(void);

bool8 CreateIQSkillMenu(s16 species)
{
    s32 species_s32 = species;

    if (HasNoAvailIQSkills(species_s32))
        return FALSE;

    sIQSkillMenu = MemoryAlloc(sizeof(struct IQSkillMenu), 8);
    sIQSkillMenu->menuAction = 0;
    sIQSkillMenu->species = species_s32;
    sIQSkillMenu->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    sIQSkillMenu->numIQSkills = GetNumAvailableIQSkills(sIQSkillMenu->iqSkills, sIQSkillMenu->pokeStruct->IQ);
    SetIQSkillMenuState(IQ_SKILL_MENU_STATE_INIT);
    return TRUE;
}

u32 sub_801BF48(void)
{
    switch (sIQSkillMenu->state) {
        case IQ_SKILL_MENU_STATE_EXIT:
            return 3;
        case IQ_SKILL_MENU_STATE_INIT:
        case IQ_SKILL_MENU_STATE_MAIN:
            HandleIQSkillMenuMain();
            break;
        case 2:
            HandleIQSkillMenuAction();
            break;
        case IQ_SKILL_MENU_STATE_INFO:
            HandleIQSkillMenuInfo();
            break;
    }
    return 0;
}

void CleanIQSkillMenu(void)
{
    if (sIQSkillMenu != NULL) {
        MemoryFree(sIQSkillMenu);
        sIQSkillMenu = NULL;
    }
}

static void SetIQSkillMenuState(s32 newState)
{
    sIQSkillMenu->state = newState;
    sub_801BFCC();
    HandleIQSkillMenuState();
}

static void sub_801BFCC(void)
{
    s32 i;

    RestoreSavedWindows(&sIQSkillMenu->unkC4);

    if (sIQSkillMenu->state == 2)
        sIQSkillMenu->unkC4.id[2] = sUnknown_80DBDB0;
    else {
        for (i = 0; i < 4; i++)
            sIQSkillMenu->unkC4.id[i] = sUnknown_80DBD98;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sIQSkillMenu->unkC4, TRUE, TRUE);
}

static void HandleIQSkillMenuState(void)
{
    switch (sIQSkillMenu->state) {
        case IQ_SKILL_MENU_STATE_INIT:
            CreateIQSkillListMenu(sIQSkillMenu->species, 0, 8);
            break;
        case IQ_SKILL_MENU_STATE_MAIN:
            RedrawIQSkillListMenu(TRUE);
            break;
        case 2:
            BuildIQSkillList();
            BuildIQSkillMenuActions();
            sub_8012D60(&sIQSkillMenu->unk74, sIQSkillMenu->unk34, NULL, NULL, sIQSkillMenu->menuAction, 2);
            break;
        case IQ_SKILL_MENU_STATE_INFO:
            CreateIQSkillInfoMenu(sIQSkillMenu->iqSkillIndex);
            break;
        case IQ_SKILL_MENU_STATE_EXIT:
            break;
    }
}

static void BuildIQSkillMenuActions(void)
{
    struct IQSkillMenu *puVar1;
    s32 i;
    u8 *nullText;
    u32 menuAction;
    s32 max;

    puVar1 = sIQSkillMenu;
    nullText = NULL;

    sIQSkillMenu->unk34[0].text = sSwitch;
    puVar1->unk34[0].menuAction = IQ_SKILL_MENU_SWITCH;

    menuAction = IQ_SKILL_MENU_NULL;
    puVar1->unk34[1].text = gCommonInfo[0];
    puVar1->unk34[1].menuAction = IQ_SKILL_MENU_INFO;

    max = 2;
    puVar1->unk34[2].text = nullText;
    puVar1->unk34[2].menuAction = menuAction;

    for (i = 0; i < max; i++) {
        if (sIQSkillMenu->unk34[i].menuAction == sIQSkillMenu->menuAction)
            return;
    }

    sIQSkillMenu->menuAction = IQ_SKILL_MENU_SWITCH;
}

static void HandleIQSkillMenuMain(void)
{
    switch (HandleIQSkillListMenuInput(TRUE)) {
        case 3:
            sIQSkillMenu->menuIndex = GetIQSkillSelection();
            sIQSkillMenu->iqSkillIndex = sIQSkillMenu->iqSkills[sIQSkillMenu->menuIndex];
            SetIQSkillMenuState(2);
            break;
        case 4:
            sIQSkillMenu->menuIndex = GetIQSkillSelection();
            sIQSkillMenu->iqSkillIndex = sIQSkillMenu->iqSkills[sIQSkillMenu->menuIndex];
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

static void HandleIQSkillMenuAction(void)
{
    s32 menuAction;

    menuAction = 0;
    HandleIQSkillListMenuInput(FALSE);

    if (!sub_8012FD8(&sIQSkillMenu->unk74)) {
        sub_8013114(&sIQSkillMenu->unk74, &menuAction);

        if (menuAction != IQ_SKILL_MENU_NULL)
            sIQSkillMenu->menuAction = menuAction;
    }

    switch (menuAction) {
        case IQ_SKILL_MENU_SWITCH: // Switch
            PlaySound(307);
            ToggleIQSkill(&sIQSkillMenu->pokeStruct->IQSkills, sIQSkillMenu->iqSkillIndex);
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
