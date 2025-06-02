#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_802DE84.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "code_80A26CC.h"
#include "common_strings.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "wonder_mail_802C4C8.h"
#include "wonder_mail_802C860.h"

static EWRAM_INIT struct unkStruct_203B2F0 *sUnknown_203B2F0 = {NULL};

#include "data/wonder_mail_802C860.h"

static void SetJobListState(u32 newState);

static void sub_802C928(void);
static void sub_802C9D8(void);
static void sub_802CAA4(void);
static void sub_802CBAC(void);
static void sub_802CC00(void);
static void sub_802CC70(void);
static void sub_802CD38(void);
static void sub_802CDB8(void);

bool8 InitializeJobListMenu(u32 a0)
{
    if (HasNoAcceptedJobs())
        return FALSE;

    sUnknown_203B2F0 = MemoryAlloc(sizeof(struct unkStruct_203B2F0), 8);
    sUnknown_203B2F0->menuAction = 0;
    sUnknown_203B2F0->unk0 = a0;
    SetJobListState(0);
    return TRUE;
}

u32 sub_802C898(void)
{
    switch (sUnknown_203B2F0->state) {
        case 0:
        case 1:
            sub_802CC00();
            break;
        case 2:
            sub_802CC70();
            break;
        case 3:
            sub_802CD38();
            break;
        case 4:
            sub_802CDB8();
            break;
        case 5:
        default:
            return 3;
    }
    return 0;
}

void sub_802C8F4(void)
{
    if (sUnknown_203B2F0 != NULL) {
        MemoryFree(sUnknown_203B2F0);
        sUnknown_203B2F0 = NULL;
    }
}

static void SetJobListState(u32 newState)
{
    sUnknown_203B2F0->state = newState;
    sub_802C928();
    sub_802C9D8();
}

static void sub_802C928(void)
{
    s32 i;

    RestoreSavedWindows(&sUnknown_203B2F0->unk19C);

    switch (sUnknown_203B2F0->state) {
        case 2:
            sub_802CAA4();
            sUnknown_203B2F0->unk19C.id[2] = sUnknown_80DFD40;
            sub_8012CAC(&sUnknown_203B2F0->unk19C.id[2], sUnknown_203B2F0->unk10C);
            break;
        case 3:
            sUnknown_203B2F0->unk19C.id[3] = sUnknown_80DFD58;
            break;
        default:
            for (i = 0; i < 4; i++)
                sUnknown_203B2F0->unk19C.id[i] = sUnknown_80DFD28;
            break;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2F0->unk19C, TRUE, TRUE);
}

static void sub_802C9D8(void)
{
    switch (sUnknown_203B2F0->state) {
        case 0:
            sub_802C4C8(0, NULL, 4);
            break;
        case 1:
            sub_802C640(TRUE);
            break;
        case 2:
            DrawJobListMenu();
            sub_8012D60(&sUnknown_203B2F0->unk6C, sUnknown_203B2F0->unk10C, 0, 0, sUnknown_203B2F0->menuAction, 2);
            break;
        case 3:
            sub_802CBAC();
            DrawJobListMenu();
            sub_8012EA4(&sUnknown_203B2F0->unk6C, 0);
            sub_8012D60(&sUnknown_203B2F0->unkBC, sUnknown_203B2F0->unk14C, 0, 0, 6, 3);
            break;
        case 4:
            sub_803B35C(GetJobSlotInfo(sUnknown_203B2F0->unkC), &sUnknown_203B2F0->unk10);
            sUnknown_203B2F0->unk10.unk0[0] = 3;
            sub_802DE84(&sUnknown_203B2F0->unk10);
            break;
        case 5:
        default:
            break;
    }
}

static void sub_802CAA4(void)
{
    s32 loopMax;
    WonderMail *mail;
    s32 i;

    loopMax = 0;
    mail = GetJobSlotInfo(sUnknown_203B2F0->unkC);

    if (sUnknown_203B2F0->unk0 == 0) {
        switch (mail->mailType) {
            case 5:
                sUnknown_203B2F0->unk10C[loopMax].text = sTakeJob;

                if (sub_809693C(mail) || !sub_80A2824(mail->dungeonSeed.location.id))
                    sUnknown_203B2F0->unk10C[loopMax].menuAction = -1;
                else
                    sUnknown_203B2F0->unk10C[loopMax].menuAction = 2;

                loopMax++;
                break;
            case 6:
                sUnknown_203B2F0->unk10C[loopMax].text = sSuspend;
                sUnknown_203B2F0->unk10C[loopMax].menuAction = 3;
                loopMax++;
                break;
        }
    }

    sUnknown_203B2F0->unk10C[loopMax].text = gCommonDelete[0];
    sUnknown_203B2F0->unk10C[loopMax].menuAction = 4;

    loopMax++;
    sUnknown_203B2F0->unk10C[loopMax].text = gCommonInfo[0];
    sUnknown_203B2F0->unk10C[loopMax].menuAction = 7;

    loopMax++;
    sUnknown_203B2F0->unk10C[loopMax].text = NULL;
    sUnknown_203B2F0->unk10C[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B2F0->unk10C[i].menuAction != -1) {
            if (sUnknown_203B2F0->unk10C[i].menuAction == sUnknown_203B2F0->menuAction)
                return;
        }
    }

    sUnknown_203B2F0->menuAction = 7;
}

static void sub_802CBAC(void)
{
    s32 loopMax;

    loopMax = 0;
    sUnknown_203B2F0->unk14C[loopMax].text = gCommonYes[0];
    sUnknown_203B2F0->unk14C[loopMax].menuAction = 5;

    loopMax++;
    sUnknown_203B2F0->unk14C[loopMax].text = gCommonNo[0];
    sUnknown_203B2F0->unk14C[loopMax].menuAction = 6;

    loopMax++;
    sUnknown_203B2F0->unk14C[loopMax].text = NULL;
    sUnknown_203B2F0->unk14C[loopMax].menuAction = 1;
}

static void sub_802CC00(void)
{
    switch (sub_802C598(TRUE)) {
        case 3:
            sUnknown_203B2F0->unkC = GetPelipperBoardSlotIndex();
            SetJobListState(2);
            break;
        case 4:
            sUnknown_203B2F0->unkC = GetPelipperBoardSlotIndex();
            SetJobListState(4);
            break;
        case 0:
        case 1:
            break;
        case 2:
            sub_802C688();
            SetJobListState(5);
            break;
    }
}

static void sub_802CC70(void)
{
    s32 menuAction;
    WonderMail *mail;
    WonderMail *mail2;

    menuAction = 0;

    sub_802C598(FALSE);

    if (!sub_8012FD8(&sUnknown_203B2F0->unk6C)) {
        sub_8013114(&sUnknown_203B2F0->unk6C, &menuAction);

        if (menuAction != 1)
            sUnknown_203B2F0->menuAction = menuAction;
    }

    switch (menuAction) {
        case 2:
            PlaySound(307);
            mail = GetJobSlotInfo(sUnknown_203B2F0->unkC);
            mail->mailType = MAIL_TYPE_TAKEN_JOB;
            SetJobListState(1);
            break;
        case 3:
            PlaySound(307);
            mail2 = GetJobSlotInfo(sUnknown_203B2F0->unkC);
            mail2->mailType = MAIL_TYPE_SUSPENDED_JOB;
            SetJobListState(1);
            break;
        case 4:
            SetJobListState(3);
            break;
        case 7:
            SetJobListState(4);
            break;
        case 1:
            SetJobListState(1);
            break;
    }
}

static void sub_802CD38(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_802C598(FALSE);
    sub_8012FD8(&sUnknown_203B2F0->unk6C);

    if (!sub_8012FD8(&sUnknown_203B2F0->unkBC))
        sub_8013114(&sUnknown_203B2F0->unkBC, &menuAction);

    switch (menuAction) {
        case 1:
        case 6:
            SetJobListState(1);
            break;
        case 5:
            ResetJobSlot(sUnknown_203B2F0->unkC);
            ShiftJobSlotsDown();

            if (HasNoAcceptedJobs()) {
                sub_802C688();
                SetJobListState(5);
            }
            else
                SetJobListState(1);
            break;
    }
}

static void sub_802CDB8(void)
{
    switch (sub_802DEE0()) {
        case 2:
        case 3:
            sub_802DF24();
            SetJobListState(1);
            break;
        case 0:
        case 1:
            break;
    }
}
