#include "global.h"
#include "code_80118A4.h"
#include "code_802DE84.h"
#include "code_803B050.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B300 *sUnknown_203B300 = {0};

#include "data/code_802DE84.h"

static void sub_802DF14(void);
static void sub_802DF6C(void);
static void sub_802DF88(void);

bool8 sub_802DE84(unkStruct_802C39C *mail)
{
    sUnknown_203B300 = MemoryAlloc(sizeof(struct unkStruct_203B300), 8);
    sUnknown_203B300->mail = mail;
    sub_801317C(&sUnknown_203B300->unk0);
    sUnknown_203B300->unk10 = sUnknown_203B300->mail->unk0[0];
    sUnknown_203B300->unk14 = &sUnknown_203B300->unk18[sUnknown_203B300->unk10];
    sub_8006518(sUnknown_203B300->unk18);
    sUnknown_203B300->unk18[sUnknown_203B300->unk10] = sUnknown_80E0264;
    sub_802DF14();
    return TRUE;
}

u32 sub_802DEE0(void)
{
    switch (sub_8012A64(&sUnknown_203B300->unk0, sUnknown_203B300->unk10)) {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            return 0;
    }
}

static void sub_802DF14(void)
{
    sub_802DF6C();
    sub_802DF88();
}

void sub_802DF24(void)
{
    if (sUnknown_203B300 != NULL) {
        sUnknown_203B300->unk18[sUnknown_203B300->unk10] = sUnknown_80E0248;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B300->unk18, TRUE, TRUE);
        MemoryFree(sUnknown_203B300);
        sUnknown_203B300 = NULL;
    }
}

static void sub_802DF6C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B300->unk18, TRUE, TRUE);
}

static void sub_802DF88(void)
{
    sub_80073B8(sUnknown_203B300->unk10);
    CreateRescueDescription(sUnknown_203B300->mail);
    sub_80073E0(sUnknown_203B300->unk10);
}