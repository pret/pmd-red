#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "music_util.h"
#include "input.h"
#include "iq_skill_list_menu.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT struct IQSkillListMenu *sIQSkillListMenu = {NULL};

#include "data/iq_skill_list_menu.h"

static void sub_801C440(void);

bool8 CreateIQSkillListMenu(s16 species, u32 index, u32 a2)
{
    s32 species_s32 = SpeciesId(species);

    if (HasNoAvailIQSkills(species))
        return FALSE;

    if (sIQSkillListMenu == NULL)
        sIQSkillListMenu = MemoryAlloc(sizeof(struct IQSkillListMenu), MEMALLOC_GROUP_8);

    sIQSkillListMenu->species = species_s32;
    sIQSkillListMenu->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    sIQSkillListMenu->numIQSkills = GetNumAvailableIQSkills(sIQSkillListMenu->iqSkills, sIQSkillListMenu->pokeStruct->IQ);
    sIQSkillListMenu->s24.m.menuWinId = index;
    sIQSkillListMenu->s24.m.menuWindow = &sIQSkillListMenu->s24.m.windows.id[index];
    RestoreSavedWindows(&sIQSkillListMenu->s24.m.windows);
    sIQSkillListMenu->s24.m.windows.id[sIQSkillListMenu->s24.m.menuWinId] = sUnknown_80DBDF0;
    sIQSkillListMenu->s24.m.menuWindow->header = &sIQSkillListMenu->s24.header;
    sub_8012D08(sIQSkillListMenu->s24.m.menuWindow, a2);
    ResetUnusedInputStruct();
    ShowWindows(&sIQSkillListMenu->s24.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sIQSkillListMenu->s24.m.input, sIQSkillListMenu->numIQSkills, a2, index);
    sub_801C440();
    BuildIQSkillList();
    return TRUE;
}

u32 HandleIQSkillListMenuInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sIQSkillListMenu->s24.m.input);
        return 0;
    }

    switch (GetKeyPress(&sIQSkillListMenu->s24.m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_INFO);
            return 4;
        default:
            if (MenuCursorUpdate(&sIQSkillListMenu->s24.m.input, 1) != 0) {
                sub_801C440();
                BuildIQSkillList();
                return 1;
            }
            return 0;
    }
}

s32 GetIQSkillSelection(void)
{
    return GET_CURRENT_MENU_ENTRY(sIQSkillListMenu->s24.m.input);
}

void RedrawIQSkillListMenu(bool8 addCursor)
{
    ResetUnusedInputStruct();
    ShowWindows(&sIQSkillListMenu->s24.m.windows, FALSE, FALSE);
    sIQSkillListMenu->s24.m.input.totalEntriesCount = sIQSkillListMenu->numIQSkills;
    MenuUpdatePagesData(&sIQSkillListMenu->s24.m.input);
    sub_801C440();
    BuildIQSkillList();

    if (addCursor)
       AddMenuCursorSprite(&sIQSkillListMenu->s24.m.input);
}

void CleanIQSkillListMenu(void)
{
    if (sIQSkillListMenu != NULL) {
        sIQSkillListMenu->s24.m.windows.id[sIQSkillListMenu->s24.m.menuWinId] = sUnknown_80DBDD8;
        ResetUnusedInputStruct();
        ShowWindows(&sIQSkillListMenu->s24.m.windows, TRUE, TRUE);
        MemoryFree(sIQSkillListMenu);
        sIQSkillListMenu = NULL;
    }
}

static void sub_801C440(void)
{
    sIQSkillListMenu->s24.header.count = sIQSkillListMenu->s24.m.input.pagesCount;
    sIQSkillListMenu->s24.header.currId = sIQSkillListMenu->s24.m.input.currPage;
    sIQSkillListMenu->s24.header.width = 10;
    sIQSkillListMenu->s24.header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&sIQSkillListMenu->s24.m.windows, TRUE, TRUE);
    UPDATE_MENU_WINDOW_HEIGHT_2(sIQSkillListMenu->s24.m);
}

void BuildIQSkillList(void)
{
    u32 y;
    s32 x;
    s32 x2;
    u32 skillIndex;
    s32 counter;

    CallPrepareTextbox_8008C54(sIQSkillListMenu->s24.m.menuWinId);
    sub_80073B8(sIQSkillListMenu->s24.m.menuWinId);
    x = sIQSkillListMenu->s24.m.input.currPage * 8;
    x2 = x;
    x2 += 10;
    PrintStringOnWindow(x2, 0, sIQSkills, sIQSkillListMenu->s24.m.menuWinId, 0);

    x += 4;
    x2 = x + sIQSkillListMenu->s24.header.width * 8;
    PrintNumOnWindow(x2, 0, sIQSkillListMenu->s24.m.input.currPage + 1, 1, 7, sIQSkillListMenu->s24.m.menuWinId);

    for (counter = 0; counter < sIQSkillListMenu->s24.m.input.currPageEntries; counter++) {
        skillIndex = sIQSkillListMenu->iqSkills[(sIQSkillListMenu->s24.m.input.currPage * sIQSkillListMenu->s24.m.input.entriesPerPage) + counter];

        y = GetMenuEntryYCoord(&sIQSkillListMenu->s24.m.input, counter);
        strncpy(gFormatBuffer_Items[1], GetIQSkillName(skillIndex), 80);

        if (IsIQSkillSet(&sIQSkillListMenu->pokeStruct->IQSkills, 1 << skillIndex))
            strcpy(gFormatBuffer_Items[1] - 80, sStarBullet);
        else
            strcpy(gFormatBuffer_Items[1] - 80, sUnknown_80DBE18);

        PrintFormattedStringOnWindow(12, y, sFmt01, sIQSkillListMenu->s24.m.menuWinId, 0);
    }

    sub_80073E0(sIQSkillListMenu->s24.m.menuWinId);
}

bool8 HasNoAvailIQSkills(s16 species)
{
    s32 species_s32;
    u8 iqSkillBuffer[NUM_IQ_SKILLS];
    Pokemon *pokeStruct;

    species_s32 = species;
    pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];

    if (GetNumAvailableIQSkills(iqSkillBuffer, pokeStruct->IQ) == 0)
        return TRUE;

    return FALSE;
}
