#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801C620.h"
#include "code_8097DD0.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "sprite.h"
#include "text1.h"
#include "text2.h"

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[]; // 202DF98

static EWRAM_DATA_2 struct unkStruct_203B240 *sUnknown_203B240 = {0};

#include "data/code_801C620.h"

static void sub_801C6D0(s32 newState);
static void sub_801C6E4(void);
static void sub_801C7D4(void);
static void sub_801C848(void);

bool8 sub_801C620(u8 iqSkill)
{
    ResetSprites(TRUE);

    sUnknown_203B240 = MemoryAlloc(sizeof(struct unkStruct_203B240), 8);
    sUnknown_203B240->chosenIQSkill = iqSkill;
    sub_801317C(&sUnknown_203B240->unk88);
    sUnknown_203B240->unk24 = 0;
    sub_80140B4(sUnknown_203B240->unk28);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B240->unk28, TRUE, TRUE);
    sub_801C6D0(0);
    return TRUE;
}

u32 sub_801C674(void)
{
    switch (sUnknown_203B240->state) {
        case 0:
            sub_801C7D4();
            break;
        case 1:
            sub_801C848();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;
    }
    return 0;
}

void sub_801C6B4(void)
{
    if (sUnknown_203B240 != NULL) {
        MemoryFree(sUnknown_203B240);
        sUnknown_203B240 = NULL;
    }
}

static void sub_801C6D0(s32 newState)
{
    sUnknown_203B240->state = newState;
    sub_801C6E4();
}

static void sub_801C6E4(void)
{
    u8 *skillName;
    struct subStruct_203B240 *preload;

    switch (sUnknown_203B240->state) {
        case 0:
            sub_8008C54(sUnknown_203B240->unk24);
            sub_80073B8(sUnknown_203B240->unk24);
            skillName = GetIQSkillName(sUnknown_203B240->chosenIQSkill);
            strcpy(gUnknown_202DE58, skillName);
            xxx_format_and_draw(16, 0, sFmtMoveItem0, 0, 0); // {ARG_MOVE_ITEM_0}
            xxx_call_draw_string(8, 16, GetIQSkillDescription(sUnknown_203B240->chosenIQSkill), sUnknown_203B240->unk24, 0);
            sub_80073E0(sUnknown_203B240->unk24);
            sUnknown_203B240->unkC = sub_8097DF0(GetIQSkillDescription(sUnknown_203B240->chosenIQSkill), sUnknown_203B240->unk10);
            sUnknown_203B240->unk20 = 0;
            break;
        case 1:
            sub_8008C54(sUnknown_203B240->unk24);
            sub_80073B8(sUnknown_203B240->unk24);
            preload = sUnknown_203B240->unk10[sUnknown_203B240->unk8];
            strcpy(gAvailablePokemonNames, preload->pokeName);
            xxx_format_and_draw(16, 0, sFmtPkmn0, sUnknown_203B240->unk24, 0); // {ARG_POKEMON_0}
            xxx_format_and_draw(4, 16, sUnknown_203B240->unk10[sUnknown_203B240->unk8]->unk4, sUnknown_203B240->unk24, 0);
            sub_80073E0(sUnknown_203B240->unk24);
            break;
        case 2:
        case 3:
            break;
    }
}

static void sub_801C7D4(void)
{
    if (sUnknown_203B240->unkC != 0) {
        if (sUnknown_203B240->unk20 & 8)
            sub_8013F84();

        sUnknown_203B240->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B240->unk88, sUnknown_203B240->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);

            if (sUnknown_203B240->unkC != 0) {
                sUnknown_203B240->unk8 = 0;
                sub_801C6D0(1);
            }
            else
                sub_801C6D0(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801C6D0(2);
            break;
    }
}

static void sub_801C848(void)
{
    if (sUnknown_203B240->unk8 < sUnknown_203B240->unkC - 1) {
        if (sUnknown_203B240->unk20 & 8)
            sub_8013F84();

        sUnknown_203B240->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B240->unk88, sUnknown_203B240->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);
            sUnknown_203B240->unk8++;

            if (sUnknown_203B240->unk8 < sUnknown_203B240->unkC)
                sub_801C6D0(1);
            else
                sub_801C6D0(0);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801C6D0(2);
            break;
    }
}