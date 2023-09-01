#include "global.h"
#include "code_8012A18_1.h"
#include "code_80130A8.h"
#include "code_801EE10_1.h"
#include "debug_menu4.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

EWRAM_DATA_2 static struct unkStruct_203B3F8 *sUnknown_203B3F8 = {0};

static const struct UnkTextStruct2 sUnknown_80E7ED4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
static const struct UnkTextStruct2 sUnknown_80E7EEC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x04,
    0x09, 0x03,
    0x03, 0x00,
    NULL
};
static const struct UnkTextStruct2 sUnknown_80E7F04 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x0e,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};
ALIGNED(4) static const u8 sNumberPrompt[] = "Number?";
ALIGNED(4) static const u8 sLevel[] = "LEVEL";
ALIGNED(4) static const u8 sName[] = "Name";
static const u8 sFill[] = "pksdir0";

void sub_803ACD0(u32);
void sub_803ACE8(void);
void sub_803AD88(void);
void sub_803AE58(void);
void sub_803AEB0(void);
void sub_803AF38(void);
void sub_803AF88(void);
void sub_803AFE8(void);
void sub_803B034(void);

// Unused
u32 sub_803AC24(void)
{
    sUnknown_203B3F8 = MemoryAlloc(sizeof(struct unkStruct_203B3F8), 8);
    sub_803ACD0(0);
    return 1;
}

// Unused
u32 sub_803AC48(void)
{
    switch (sUnknown_203B3F8->state) {
        case 0:
            sub_803ACD0(1);
            break;
        case 1:
        case 2:
            sub_803AF38();
            break;
        case 3:
            sub_803AF88();
            break;
        case 5:
            sub_803AFE8();
            break;
        case 6:
            sub_803B034();
            break;
        case 4:
        case 7:
        default:
            return 3;
    }
    return 0;
}

// Unused
void sub_803ACB4(void)
{
    if (sUnknown_203B3F8 != NULL) {
        MemoryFree(sUnknown_203B3F8);
        sUnknown_203B3F8 = NULL;
    }
}

void sub_803ACD0(u32 newState)
{
    sUnknown_203B3F8->state = newState;
    sub_803ACE8();
    sub_803AD88();
}

void sub_803ACE8(void)
{
    s32 i;

    sub_8006518(sUnknown_203B3F8->unkE0);

    switch (sUnknown_203B3F8->state) {
        case 3:
            sub_803AEB0();
            sUnknown_203B3F8->unkE0[2] = sUnknown_80E7EEC;
            sub_8012CAC(&sUnknown_203B3F8->unkE0[2], sUnknown_203B3F8->unk90);
            break;
        case 5:
            sUnknown_203B3F8->unkE0[3] = sUnknown_80E7F04;
            break;
        default:
            for (i = 0; i < 4; i++)
                sUnknown_203B3F8->unkE0[i] = sUnknown_80E7ED4;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B3F8->unkE0, TRUE, TRUE);
}

void sub_803AD88(void)
{
    switch (sUnknown_203B3F8->state) {
        case 1:
            sub_8023868(1, 0, 0, 10);
            break;
        case 2:
            sub_8023B7C(1);
            break;
        case 3:
            sub_8023DA4();
            sub_8012D60(&sUnknown_203B3F8->unk10, sUnknown_203B3F8->unk90, 0, sUnknown_203B3F8->unkD0, sUnknown_203B3F8->menuAction, 2);
            break;
        case 5:
            sUnknown_203B3F8->unk70 = 3;
            sUnknown_203B3F8->unk68 = 1;
            sUnknown_203B3F8->unk6C = 100;
            sUnknown_203B3F8->unk64 = sUnknown_203B3F8->pokemon->level;
            sUnknown_203B3F8->unk74 = 3;
            sUnknown_203B3F8->unk78 = &sUnknown_203B3F8->unkE0[3];
            sUnknown_203B3F8->unk7C = 44;
            sUnknown_203B3F8->unk80 = 18;
            sub_8013AA0(&sUnknown_203B3F8->unk60);
            sub_803AE58();
            break;
        case 6:
            sub_801602C(2, sUnknown_203B3F8->pokemon->name);
        case 0:
        case 4:
        case 7:
        default:
            break;

    }
}

void sub_803AE58(void)
{
    sub_8008C54(sUnknown_203B3F8->unk74);
    sub_80073B8(sUnknown_203B3F8->unk74);
    xxx_call_draw_string(4, 0, sNumberPrompt, sUnknown_203B3F8->unk74, 0);
    sub_8013C68(&sUnknown_203B3F8->unk60);
    sub_80073E0(sUnknown_203B3F8->unk74);
    sub_8023DA4();
    sub_8012EA4(&sUnknown_203B3F8->unk10, 0);
}

void sub_803AEB0(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sUnknown_203B3F8->unkD0, 0, sizeof(sUnknown_203B3F8->unkD0));

    loopMax = 0;
    sUnknown_203B3F8->unk90[loopMax].text = sLevel;
    sUnknown_203B3F8->unk90[loopMax].menuAction = 4;

    loopMax++;
    sUnknown_203B3F8->unk90[loopMax].text = sName;
    sUnknown_203B3F8->unk90[loopMax].menuAction = 5;

    loopMax++;
    sUnknown_203B3F8->unk90[loopMax].text = NULL;
    sUnknown_203B3F8->unk90[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B3F8->unkD0[i] == 0) {
            sUnknown_203B3F8->menuAction = sUnknown_203B3F8->unk90[i].menuAction;
            break;
        }
    }
}

void sub_803AF38(void)
{
    switch (sub_8023A94(TRUE)) {
        case 3:
            sUnknown_203B3F8->unk4 = sub_8023B44();
            sUnknown_203B3F8->pokemon = &gRecruitedPokemonRef->pokemon[sUnknown_203B3F8->unk4];
            sub_803ACD0(3);
            break;
        case 2:
            sub_8023C60();
            sub_803ACD0(7);
            break;
        case 1:
        case 0:
            break;
    }
}

void sub_803AF88(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_8023A94(FALSE);

    if (sub_8012FD8(&sUnknown_203B3F8->unk10) == 0)
        sub_8013114(&sUnknown_203B3F8->unk10, &menuAction);

    switch (menuAction) {
        case 4:
            sub_803ACD0(5);
            break;
        case 5:
            sub_803ACD0(6);
            break;
        case 1:
            sub_803ACD0(2);
            break;
        default:
            break;
    }
}

void sub_803AFE8(void)
{
    sub_8023A94(FALSE);
    sub_8012FD8(&sUnknown_203B3F8->unk10);

    switch (sub_8013BBC(&sUnknown_203B3F8->unk60)) {
        default:
            break;
        case 3:
            sUnknown_203B3F8->pokemon->level = sUnknown_203B3F8->unk60;
            // Fallthrough is needed to match
        case 2:
            sub_803ACD0(2);
            break;
        case 1:
            sub_803AE58();
            break;
    }
}

void sub_803B034(void)
{
    switch (sub_8016080()) {
        case 2:
        case 3:
            sub_80160D8();
            sub_803ACD0(2);
            break;
    }
}
