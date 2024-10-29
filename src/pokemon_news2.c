#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "game_options.h"
#include "input.h"
#include "pokemon_mail.h"
#include "pokemon_mid.h"
#include "pokemon_news2.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B2D4 *sUnknown_203B2D4 = {0};

#include "data/pokemon_news2.h"

static void sub_802BB14(u32 newState);
static void sub_802BB28(void);
static void sub_802BB98(void);
static void sub_802BC08(void);
static void sub_802BCC4(void);

bool8 sub_802B9FC(u8 mailIndex)
{
    sUnknown_203B2D4 = MemoryAlloc(sizeof(struct unkStruct_203B2D4), 8);
    sUnknown_203B2D4->currMailIndex = mailIndex;
    sub_801317C(&sUnknown_203B2D4->unk88);
    sUnknown_203B2D4->unk24 = 0;
    sUnknown_203B2D4->unk28[0] = sUnknown_80DFC34;
    sUnknown_203B2D4->unk28[1] = sUnknown_80DFC18;
    sUnknown_203B2D4->unk28[2] = sUnknown_80DFC18;
    sUnknown_203B2D4->unk28[3] = sUnknown_80DFC18;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sUnknown_203B2D4->unk28, TRUE, TRUE);
    sUnknown_203B2D4->unk8 = 0;
    sub_802BCC4();
    sub_802BC7C();
    sub_802BB14(0);
    return TRUE;
}

u32 sub_802BA8C(void)
{
    switch (sUnknown_203B2D4->state) {
        case 0:
            sub_802BB98();
            break;
        case 1:
            sub_802BC08();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;

    }
    return 0;
}

void sub_802BACC(void)
{
    if (sUnknown_203B2D4 != NULL) {
        sUnknown_203B2D4->unk28[sUnknown_203B2D4->unk24] = sUnknown_80DFC18;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sUnknown_203B2D4->unk28, TRUE, TRUE);
        MemoryFree(sUnknown_203B2D4);
        sUnknown_203B2D4 = NULL;
    }
}

static void sub_802BB14(u32 newState)
{
    sUnknown_203B2D4->state = newState;
    sub_802BB28();
}

static void sub_802BB28(void)
{
    switch (sUnknown_203B2D4->state) {
        case 0:
        case 1:
            CallPrepareTextbox_8008C54(sUnknown_203B2D4->unk24);
            sub_80073B8(sUnknown_203B2D4->unk24);
            PrintFormatStringOnWindow(10, 0, GetPokemonMailHeadline(sUnknown_203B2D4->currMailIndex), sUnknown_203B2D4->unk24, 0);
            PrintFormatStringOnWindow(6, 20, sUnknown_203B2D4->unk10[sUnknown_203B2D4->unk8], sUnknown_203B2D4->unk24, 0);
            sub_80073E0(sUnknown_203B2D4->unk24);
            sUnknown_203B2D4->unk8++;
            break;
        case 2:
        case 3:
            break;
    }
}

static void sub_802BB98(void)
{
    if (sUnknown_203B2D4->unkC != 0) {
        if (sUnknown_203B2D4->unk20 & 8)
            sub_8013E54();
        sUnknown_203B2D4->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B2D4->unk88, sUnknown_203B2D4->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);
            if (sUnknown_203B2D4->unkC != 0)
                sub_802BB14(1);
            else
                sub_802BB14(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_802BB14(2);
            break;
    }
}

static void sub_802BC08(void)
{
    if (sUnknown_203B2D4->unk8 < sUnknown_203B2D4->unkC) {
        if (sUnknown_203B2D4->unk20 & 8)
            sub_8013E54();
        sUnknown_203B2D4->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B2D4->unk88, sUnknown_203B2D4->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);
            if (sUnknown_203B2D4->unk8 < sUnknown_203B2D4->unkC)
                sub_802BB14(1);
            else
                sub_802BB14(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_802BB14(2);
            break;
    }
}

void sub_802BC7C(void)
{
    PrintPokeNameToBuffer(gAvailablePokemonNames[0], sub_808D3BC());

    if (gGameOptionsRef->playerGender == FEMALE)
        strcpy(gAvailablePokemonNames[1], sShe);
    else
        strcpy(gAvailablePokemonNames[1], sHe);
}

static void sub_802BCC4(void)
{
    const u8 *mailTextPtr;

    mailTextPtr = GetPokemonMailText(sUnknown_203B2D4->currMailIndex);
    sUnknown_203B2D4->unkC = 0;
    sUnknown_203B2D4->unk10[0] = mailTextPtr;

    // Count all the {EXTRA_MSG}'s
    while (*mailTextPtr != '\0') {
        if (*mailTextPtr == '#') {
            if (mailTextPtr[1] == 'P' || mailTextPtr[1] == 'p') {
                sUnknown_203B2D4->unkC++;
                sUnknown_203B2D4->unk10[sUnknown_203B2D4->unkC] = mailTextPtr + 2;
            }
            mailTextPtr += 2;
        }
        else
            mailTextPtr++;
    }
}
