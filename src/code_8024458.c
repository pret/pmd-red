#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_8024458.h"
#include "constants/input.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B2AC *sUnknown_203B2AC = {0};

#include "data/code_8024458.h"

static void sub_8024588(void);
static void sub_80245D0(void);
static void sub_8024604(void);

bool8 sub_8024458(s16 speciesNum, s32 a1)
{
    s32 speciesNum_s32 = speciesNum;

    sUnknown_203B2AC = MemoryAlloc(sizeof(struct unkStruct_203B2AC), 8);
    sUnknown_203B2AC->speciesNum = speciesNum_s32;
    sUnknown_203B2AC->unkE0 = a1;
    sUnknown_203B2AC->unkE4 = &sUnknown_203B2AC->unkE8[a1];
    RestoreUnkTextStruct_8006518(sUnknown_203B2AC->unkE8);
    sUnknown_203B2AC->unkE8[sUnknown_203B2AC->unkE0] = sUnknown_80DC9C8;
    sUnknown_203B2AC->unkE4->unk14 = &sUnknown_203B2AC->unk148;
    sUnknown_203B2AC->unk148.f2 = 10;
    sub_8024604();
    sub_802452C();
    sub_8013984(&sUnknown_203B2AC->input);
    return TRUE;
}

u32 sub_80244E4(void)
{
    switch (GetKeyPress(&sUnknown_203B2AC->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (sub_8013938(&sUnknown_203B2AC->input)) {
                sub_802452C();
                return 1;
            }
            return 0;
    }
}

void sub_802452C(void)
{
    sub_8024588();
    sub_80245D0();
}

void sub_802453C(void)
{
    if (sUnknown_203B2AC != NULL) {
        sUnknown_203B2AC->unkE8[sUnknown_203B2AC->unkE0] = sUnknown_80DC9B0;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sUnknown_203B2AC->unkE8, TRUE, TRUE);
        MemoryFree(sUnknown_203B2AC);
        sUnknown_203B2AC = NULL;
    }
}

static void sub_8024588(void)
{
    sUnknown_203B2AC->unk148.f0 = sUnknown_203B2AC->input.unk20;
    sUnknown_203B2AC->unk148.f1 = sUnknown_203B2AC->input.unk1E;
    sUnknown_203B2AC->unk148.f3 = 0;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sUnknown_203B2AC->unkE8, TRUE, TRUE);
}

static void sub_80245D0(void)
{
    CreatePokemonInfoTabScreen(sUnknown_203B2AC->unk34[sUnknown_203B2AC->input.unk1E], sUnknown_203B2AC->input.unk1E, &sUnknown_203B2AC->unk4C, &sUnknown_203B2AC->unkB0, sUnknown_203B2AC->unkE0);
}

static void sub_8024604(void)
{
    PokemonStruct1 *pokeStruct;
    u32 *iVar3;

    sUnknown_203B2AC->unk34[0] = 2;
    sUnknown_203B2AC->unk34[1] = 3;
    sUnknown_203B2AC->unk34[2] = 5;

    sub_8013818(&sUnknown_203B2AC->input, 3, 1, sUnknown_203B2AC->unkE0);
    iVar3 = &sUnknown_203B2AC->unk4C;
    pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B2AC->speciesNum];
    sub_808FF20(iVar3, pokeStruct, sub_80023E4(7));
}
