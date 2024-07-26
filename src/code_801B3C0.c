#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801B3C0.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "sprite.h"
#include "text1.h"
#include "text2.h"

extern u8 gAvailablePokemonNames[]; // 202DF98

static EWRAM_DATA_2 unkStruct_203B230 *sUnknown_203B230 = {0};

#include "data/code_801B3C0.h" // 80DBA4C

static void sub_801B46C(u32);
static void sub_801B480(void);
static void sub_801B51C(void);
static void sub_801B590(void);

bool8 sub_801B3C0(Item *item)
{
    ResetSprites(TRUE);
    sUnknown_203B230 = MemoryAlloc(sizeof(unkStruct_203B230),8);
    sUnknown_203B230->item = *item;
    sub_801317C(&sUnknown_203B230->unk88);
    sUnknown_203B230->unk24 = 0;
    sub_80140B4(sUnknown_203B230->unk28);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B230->unk28, TRUE, TRUE);
    sub_801B46C(0);
    return TRUE;
}

u32 sub_801B410(void)
{
    switch (sUnknown_203B230->state) {
        case 0:
            sub_801B51C();
            break;
        case 1:
            sub_801B590();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;
    }

    return 0;
}

void sub_801B450(void)
{
    if (sUnknown_203B230 != NULL) {
        MemoryFree(sUnknown_203B230);
        sUnknown_203B230 = NULL;
    }
}

static void sub_801B46C(u32 newState)
{
    sUnknown_203B230->state = newState;
    sub_801B480();
}

static void sub_801B480(void)
{
    struct subStruct_203B240 *preload;

    switch (sUnknown_203B230->state) {
        case 0:
            sub_8008C54(sUnknown_203B230->unk24);
            sUnknown_203B230->unkC = sub_80913E0(&sUnknown_203B230->item, sUnknown_203B230->unk24, sUnknown_203B230->unk10);
            sUnknown_203B230->unk20 = 0;
            break;
        case 1:
            sub_8008C54(sUnknown_203B230->unk24);
            sub_80073B8(sUnknown_203B230->unk24);
            preload = sUnknown_203B230->unk10[sUnknown_203B230->unk8];
            strcpy(gAvailablePokemonNames, preload->pokeName);
            PrintFormatStringOnWindow(16, 0, sFmtPkmn0, sUnknown_203B230->unk24, 0); // {ARG_POKEMON_0}
            PrintFormatStringOnWindow(4, 16, sUnknown_203B230->unk10[sUnknown_203B230->unk8]->unk4, sUnknown_203B230->unk24, 0);
            sub_80073E0(sUnknown_203B230->unk24);
            break;
        case 2:
        default:
            break;
    }
}

static void sub_801B51C(void)
{
    if (sUnknown_203B230->unkC != 0) {
        if (sUnknown_203B230->unk20 & 8)
            sub_8013F84();

        sUnknown_203B230->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B230->unk88, sUnknown_203B230->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);

            if (sUnknown_203B230->unkC != 0) {
                sUnknown_203B230->unk8 = 0;
                sub_801B46C(1);
            }
            else
                sub_801B46C(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801B46C(2);
            break;
        default:
            break;
    }
}

static void sub_801B590(void)
{
    if (sUnknown_203B230->unk8 < (sUnknown_203B230->unkC - 1)) {
        if (sUnknown_203B230->unk20 & 8)
            sub_8013F84();

        sUnknown_203B230->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B230->unk88,sUnknown_203B230->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);

            sUnknown_203B230->unk8++;
            if (sUnknown_203B230->unk8 < sUnknown_203B230->unkC)
                sub_801B46C(1);
            else
                sub_801B46C(0);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801B46C(2);
            break;
    }
}