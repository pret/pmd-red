#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "iq_skill_info_menu.h"
#include "code_8097DD0.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "sprite.h"
#include "text1.h"
#include "text2.h"

extern u8 gFormatItems[];
extern u8 gAvailablePokemonNames[]; // 202DF98

static EWRAM_DATA_2 struct IQSkillInfoMenu *sIQSkillInfoMenu = {0};

#include "data/iq_skill_info_menu.h"

static void SetIQSkillInfoMenuState(s32 newState);
static void sub_801C6E4(void);
static void sub_801C7D4(void);
static void sub_801C848(void);

enum IQSkillInfoMenuState
{
    IQ_SKILL_INFO_MENU_INIT,
    IQ_SKILL_INFO_MENU_EXIT = 3
};

bool8 CreateIQSkillInfoMenu(u8 iqSkill)
{
    ResetSprites(TRUE);

    sIQSkillInfoMenu = MemoryAlloc(sizeof(struct IQSkillInfoMenu), 8);
    sIQSkillInfoMenu->chosenIQSkill = iqSkill;
    sub_801317C(&sIQSkillInfoMenu->unk88);
    sIQSkillInfoMenu->unk24 = 0;
    sub_80140B4(sIQSkillInfoMenu->unk28);
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sIQSkillInfoMenu->unk28, TRUE, TRUE);
    SetIQSkillInfoMenuState(IQ_SKILL_INFO_MENU_INIT);
    return TRUE;
}

u32 HandleIQSkillInfoMenuState(void)
{
    switch (sIQSkillInfoMenu->state) {
        case IQ_SKILL_INFO_MENU_INIT:
            sub_801C7D4();
            break;
        case 1:
            sub_801C848();
            break;
        case IQ_SKILL_INFO_MENU_EXIT:
            return 3;
        case 2:
        default:
            return 2;
    }
    return 0;
}

void CleanIQSkillInfoMenu(void)
{
    if (sIQSkillInfoMenu != NULL) {
        MemoryFree(sIQSkillInfoMenu);
        sIQSkillInfoMenu = NULL;
    }
}

static void SetIQSkillInfoMenuState(s32 newState)
{
    sIQSkillInfoMenu->state = newState;
    sub_801C6E4();
}

static void sub_801C6E4(void)
{
    u8 *skillName;
    struct subStruct_203B240 *preload;

    switch (sIQSkillInfoMenu->state) {
        case IQ_SKILL_INFO_MENU_INIT:
            CallPrepareTextbox_8008C54(sIQSkillInfoMenu->unk24);
            sub_80073B8(sIQSkillInfoMenu->unk24);
            skillName = GetIQSkillName(sIQSkillInfoMenu->chosenIQSkill);
            strcpy(gFormatItems, skillName);
            PrintFormatStringOnWindow(16, 0, sFmtMoveItem0, 0, 0); // {ARG_MOVE_ITEM_0}
            PrintStringOnWindow(8, 16, GetIQSkillDescription(sIQSkillInfoMenu->chosenIQSkill), sIQSkillInfoMenu->unk24, 0);
            sub_80073E0(sIQSkillInfoMenu->unk24);
            sIQSkillInfoMenu->unkC = sub_8097DF0(GetIQSkillDescription(sIQSkillInfoMenu->chosenIQSkill), sIQSkillInfoMenu->unk10);
            sIQSkillInfoMenu->unk20 = 0;
            break;
        case 1:
            CallPrepareTextbox_8008C54(sIQSkillInfoMenu->unk24);
            sub_80073B8(sIQSkillInfoMenu->unk24);
            preload = sIQSkillInfoMenu->unk10[sIQSkillInfoMenu->unk8];
            strcpy(gAvailablePokemonNames, preload->pokeName);
            PrintFormatStringOnWindow(16, 0, sFmtPkmn0, sIQSkillInfoMenu->unk24, 0); // {ARG_POKEMON_0}
            PrintFormatStringOnWindow(4, 16, sIQSkillInfoMenu->unk10[sIQSkillInfoMenu->unk8]->unk4, sIQSkillInfoMenu->unk24, 0);
            sub_80073E0(sIQSkillInfoMenu->unk24);
            break;
        case 2:
        case IQ_SKILL_INFO_MENU_EXIT:
            break;
    }
}

static void sub_801C7D4(void)
{
    if (sIQSkillInfoMenu->unkC != 0) {
        if (sIQSkillInfoMenu->unk20 & 8)
            sub_8013F84();

        sIQSkillInfoMenu->unk20++;
    }

    switch (sub_8012A64(&sIQSkillInfoMenu->unk88, sIQSkillInfoMenu->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);

            if (sIQSkillInfoMenu->unkC != 0) {
                sIQSkillInfoMenu->unk8 = 0;
                SetIQSkillInfoMenuState(1);
            }
            else
                SetIQSkillInfoMenuState(IQ_SKILL_INFO_MENU_EXIT);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            SetIQSkillInfoMenuState(2);
            break;
    }
}

static void sub_801C848(void)
{
    if (sIQSkillInfoMenu->unk8 < sIQSkillInfoMenu->unkC - 1) {
        if (sIQSkillInfoMenu->unk20 & 8)
            sub_8013F84();

        sIQSkillInfoMenu->unk20++;
    }

    switch (sub_8012A64(&sIQSkillInfoMenu->unk88, sIQSkillInfoMenu->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);
            sIQSkillInfoMenu->unk8++;

            if (sIQSkillInfoMenu->unk8 < sIQSkillInfoMenu->unkC)
                SetIQSkillInfoMenuState(1);
            else
                SetIQSkillInfoMenuState(IQ_SKILL_INFO_MENU_INIT);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            SetIQSkillInfoMenuState(2);
            break;
    }
}
