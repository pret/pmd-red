#include "global.h"
#include "globaldata.h"
#include "music_util.h"
#include "code_802DE84.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "text_1.h"

static EWRAM_INIT struct unkStruct_203B300 *sUnknown_203B300 = {NULL};

#include "data/code_802DE84.h"

static void sub_802DF14(void);
static void sub_802DF6C(void);
static void sub_802DF88(void);

bool8 sub_802DE84(unkStruct_802C39C *mail)
{
    sUnknown_203B300 = MemoryAlloc(sizeof(struct unkStruct_203B300), 8);
    sUnknown_203B300->mail = mail;
    ResetTouchScreenMenuInput(&sUnknown_203B300->unk0);
    sUnknown_203B300->unk10 = sUnknown_203B300->mail->unk0[0];
    sUnknown_203B300->unk14 = &sUnknown_203B300->unk18.id[sUnknown_203B300->unk10];
    RestoreSavedWindows(&sUnknown_203B300->unk18);
    sUnknown_203B300->unk18.id[sUnknown_203B300->unk10] = sUnknown_80E0264;
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
        sUnknown_203B300->unk18.id[sUnknown_203B300->unk10] = sUnknown_80E0248;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B300->unk18, TRUE, TRUE);
        MemoryFree(sUnknown_203B300);
        sUnknown_203B300 = NULL;
    }
}

static void sub_802DF6C(void)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B300->unk18, TRUE, TRUE);
}

static void sub_802DF88(void)
{
    sub_80073B8(sUnknown_203B300->unk10);
    CreateRescueDescription(sUnknown_203B300->mail);
    sub_80073E0(sUnknown_203B300->unk10);
}
