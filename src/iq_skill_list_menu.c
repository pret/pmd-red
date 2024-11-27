#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "iq_skill_list_menu.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct IQSkillListMenu *sIQSkillListMenu = {0};

#include "data/iq_skill_list_menu.h"

static void sub_801C440(void);

bool8 CreateIQSkillListMenu(s16 species, u32 index, u32 a2)
{
    s32 species_s32 = SpeciesId(species);

    if (HasNoAvailIQSkills(species))
        return FALSE;

    if (sIQSkillListMenu == NULL)
        sIQSkillListMenu = MemoryAlloc(sizeof(struct IQSkillListMenu), 8);

    sIQSkillListMenu->species = species_s32;
    sIQSkillListMenu->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    sIQSkillListMenu->numIQSkills = GetNumAvailableIQSkills(sIQSkillListMenu->iqSkills, sIQSkillListMenu->pokeStruct->IQ);
    sIQSkillListMenu->s24.s0.unk34 = index;
    sIQSkillListMenu->s24.s0.unk38 = &sIQSkillListMenu->s24.s0.unk3C[index];
    RestoreUnkTextStruct_8006518(sIQSkillListMenu->s24.s0.unk3C);
    sIQSkillListMenu->s24.s0.unk3C[sIQSkillListMenu->s24.s0.unk34] = sUnknown_80DBDF0;
    sIQSkillListMenu->s24.s0.unk38->unk14 = &sIQSkillListMenu->s24.unk9C;
    sub_8012D08(sIQSkillListMenu->s24.s0.unk38, a2);
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sIQSkillListMenu->s24.s0.unk3C, TRUE, TRUE);
    sub_8013818(&sIQSkillListMenu->s24.s0.input, sIQSkillListMenu->numIQSkills, a2, index);
    sub_801C440();
    BuildIQSkillList();
    return TRUE;
}

u32 HandleIQSkillListMenuInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sIQSkillListMenu->s24.s0.input);
        return 0;
    }

    switch (GetKeyPress(&sIQSkillListMenu->s24.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&sIQSkillListMenu->s24.s0.input, 1) != 0) {
                sub_801C440();
                BuildIQSkillList();
                return 1;
            }
            return 0;
    }
}

s32 GetIQSkillSelection(void)
{
    return (sIQSkillListMenu->s24.s0.input.unk1E * sIQSkillListMenu->s24.s0.input.unk1C) + sIQSkillListMenu->s24.s0.input.menuIndex;
}

void RedrawIQSkillListMenu(bool8 addCursor)
{
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sIQSkillListMenu->s24.s0.unk3C, FALSE, FALSE);
    sIQSkillListMenu->s24.s0.input.unk22 = sIQSkillListMenu->numIQSkills;
    sub_8013984(&sIQSkillListMenu->s24.s0.input);
    sub_801C440();
    BuildIQSkillList();

    if (addCursor)
       AddMenuCursorSprite(&sIQSkillListMenu->s24.s0.input);
}

void CleanIQSkillListMenu(void)
{
    if (sIQSkillListMenu != NULL) {
        sIQSkillListMenu->s24.s0.unk3C[sIQSkillListMenu->s24.s0.unk34] = sUnknown_80DBDD8;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sIQSkillListMenu->s24.s0.unk3C, TRUE, TRUE);
        MemoryFree(sIQSkillListMenu);
        sIQSkillListMenu = NULL;
    }
}

static void sub_801C440(void)
{
    sIQSkillListMenu->s24.unk9C.f0 = sIQSkillListMenu->s24.s0.input.unk20;
    sIQSkillListMenu->s24.unk9C.f1 = sIQSkillListMenu->s24.s0.input.unk1E;
    sIQSkillListMenu->s24.unk9C.f2 = 10;
    sIQSkillListMenu->s24.unk9C.f3 = 0;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sIQSkillListMenu->s24.s0.unk3C, TRUE, TRUE);
    SUB_80095E4_CALL_2(sIQSkillListMenu->s24.s0);
}

void BuildIQSkillList(void)
{
    u32 y;
    s32 x;
    s32 x2;
    u32 skillIndex;
    s32 counter;

    CallPrepareTextbox_8008C54(sIQSkillListMenu->s24.s0.unk34);
    sub_80073B8(sIQSkillListMenu->s24.s0.unk34);
    x = sIQSkillListMenu->s24.s0.input.unk1E * 8;
    x2 = x;
    x2 += 10;
    PrintStringOnWindow(x2, 0, sIQSkills, sIQSkillListMenu->s24.s0.unk34, 0);

    x += 4;
    x2 = x + sIQSkillListMenu->s24.unk9C.f2 * 8;
    sub_8012BC4(x2, 0, sIQSkillListMenu->s24.s0.input.unk1E + 1, 1, 7, sIQSkillListMenu->s24.s0.unk34);

    for (counter = 0; counter < sIQSkillListMenu->s24.s0.input.unk1A; counter++) {
        skillIndex = sIQSkillListMenu->iqSkills[(sIQSkillListMenu->s24.s0.input.unk1E * sIQSkillListMenu->s24.s0.input.unk1C) + counter];

        y = sub_8013800(&sIQSkillListMenu->s24.s0.input, counter);
        strncpy(gFormatBuffer_Items[1], GetIQSkillName(skillIndex), 80);

        if (IsIQSkillSet(&sIQSkillListMenu->pokeStruct->IQSkills, 1 << skillIndex))
            strcpy(gFormatBuffer_Items[1] - 80, sStarBullet);
        else
            strcpy(gFormatBuffer_Items[1] - 80, sUnknown_80DBE18);

        PrintFormattedStringOnWindow(12, y, sFmt01, sIQSkillListMenu->s24.s0.unk34, 0);
    }

    sub_80073E0(sIQSkillListMenu->s24.s0.unk34);
}

bool8 HasNoAvailIQSkills(s16 species)
{
    s32 species_s32;
    u8 iqSkillBuffer[NUM_IQ_SKILLS];
    PokemonStruct1 *pokeStruct;

    species_s32 = species;
    pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];

    if (GetNumAvailableIQSkills(iqSkillBuffer, pokeStruct->IQ) == 0)
        return TRUE;

    return FALSE;
}
