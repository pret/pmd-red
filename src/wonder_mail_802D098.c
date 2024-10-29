#include "global.h"
#include "globaldata.h"
#include "string_format.h"
#include "code_802DE84.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "code_80972F4.h"
#include "code_8099360.h"
#include "code_8099328.h"
#include "common_strings.h"
#include "constants/dungeon.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "save.h"
#include "text1.h"
#include "text2.h"
#include "wonder_mail_802C4C8.h"
#include "wonder_mail_802D098.h"

enum WonderMailRescueStates
{
    INITIAL_WONDER_MAIL_CHECK = 0,
    // 1
    WONDER_MAIL_EXIT = 2,
    DUPLICATE_WONDER_MAIL,
    DUPLICATE_WONDER_MAIL_1,
    // 5 - 7
    RECEIVE_WONDER_MAIL = 8,
    // 9
    JOB_LIST_FULL = 10,
    DRAW_JOB_LIST,
    DRAW_JOB_LIST_1,
    // 13 - 16
};

enum menuActions {
    CANCEL_ACTION = 1,
    DELETE_ACTION,
    YES_ACTION,
    NO_ACTION,
    INFO_ACTION,
    NEW_MAIL_ACTION,
    OLD_MAIL_ACTION
};

static EWRAM_DATA_2 unkStruct_203B2F8 *sUnknown_203B2F8 = {0};

#include "data/wonder_mail_802D098.h"

static void AdvancetoFallbackWonderMailRescueState(void);

static void sub_802D1A0(u32 newState);
static void sub_802D1B8(void);
static void sub_802D2A8(void);
static void sub_802D5A4(void);
static void sub_802D63C(void);
static void sub_802D690(void);
static void sub_802D73C(void);
static void sub_802D7D0(void);
static void sub_802D82C(void);
static void sub_802D8CC(void);
static void sub_802D940(void);
static void sub_802D9F0(void);
static void sub_802DA60(void);
static bool8 sub_802DAA8(void);
static bool8 sub_802DADC(void);

bool8 sub_802D098(unkSubStruct_203B2F8 *mail)
{
    sUnknown_203B2F8 = MemoryAlloc(sizeof(unkStruct_203B2F8), 8);
    sUnknown_203B2F8->menuAction1 = 0;
    sUnknown_203B2F8->menuAction2 = 0;
    sUnknown_203B2F8->menuAction3 = 0;
    sUnknown_203B2F8->mail = mail;
    sUnknown_203B2F8->wonderMailAccepted = FALSE;
    sUnknown_203B2F8->unk9 = sub_8099328(&sUnknown_203B2F8->dungeonID);

    if (sub_8011C1C() != 2)
        sUnknown_203B2F8->unk9 = FALSE;

    sub_802D1A0(INITIAL_WONDER_MAIL_CHECK);
    return TRUE;
}

u32 sub_802D0E0(void)
{
    switch (sUnknown_203B2F8->state) {
        case INITIAL_WONDER_MAIL_CHECK:
            break;
        case 1:
            sub_802D7D0();
            break;
        case DRAW_JOB_LIST:
        case DRAW_JOB_LIST_1:
            sub_802D8CC();
            break;
        case 13:
            sub_802D940();
            break;
        case 14:
            sub_802D9F0();
            break;
        case 15:
        case 16:
            sub_802DA60();
            break;
        case 9:
            sub_802D82C();
            break;
        case WONDER_MAIL_EXIT:
            return 3;
        default:
            AdvancetoFallbackWonderMailRescueState();
            break;
    }
    return 0;
}

bool8 GetWonderMailAccepted(void)
{
    return sUnknown_203B2F8->wonderMailAccepted;
}

void sub_802D184(void)
{
    if (sUnknown_203B2F8 != NULL) {
        MemoryFree(sUnknown_203B2F8);
        sUnknown_203B2F8 = NULL;
    }
}

static void sub_802D1A0(u32 newState)
{
    sUnknown_203B2F8->state = newState;
    sub_802D1B8();
    sub_802D2A8();
}

static void sub_802D1B8(void)
{
    s32 i;

    RestoreUnkTextStruct_8006518(sUnknown_203B2F8->unk1A8);

    switch (sUnknown_203B2F8->state) {
        case 13:
           sub_802D5A4();
           sUnknown_203B2F8->unk1A8[2] = sUnknown_80DFE04;
           sub_8012CAC(&sUnknown_203B2F8->unk1A8[2], sUnknown_203B2F8->unk118);
           sUnknown_203B2F8->unk1A8[2].unkC = 6;
           break;
        case 14:
           sub_802D63C();
           sUnknown_203B2F8->unk1A8[3] = sUnknown_80DFE1C;
           sub_8012CAC(&sUnknown_203B2F8->unk1A8[3], sUnknown_203B2F8->unk158);
           sUnknown_203B2F8->unk1A8[3].unkC = 6;
           break;
        default:
           for (i = 0; i < 4; i++)
               sUnknown_203B2F8->unk1A8[i] = sUnknown_80DFDD4;
           break;
        case WONDER_MAIL_EXIT:
           break;
    }

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sUnknown_203B2F8->unk1A8, TRUE, TRUE);
}

static void sub_802D2A8(void)
{
    switch (sUnknown_203B2F8->state) {
        case INITIAL_WONDER_MAIL_CHECK:
            if (IsMailinJobSlot(&sUnknown_203B2F8->mail->wonderMail))
                sub_802D1A0(DUPLICATE_WONDER_MAIL);
            else if (sub_8096F50(&sUnknown_203B2F8->mail->wonderMail))
                sub_802D1A0(DUPLICATE_WONDER_MAIL_1);
            else if (sUnknown_203B2F8->mail->wonderMail.unk2 == 4 && sub_8096C08(&sUnknown_203B2F8->jobSlotIndex)) {
                if (sub_802DAA8())
                    sub_802D1A0(9);
                else
                    sub_802D1A0(5);
            }
            else if (GetNumAcceptedJobs() >= MAX_ACCEPTED_JOBS) {
                if (sub_802DADC())
                    sub_802D1A0(JOB_LIST_FULL);
                else
                    sub_802D1A0(6);
            }
            else
                sub_802D1A0(RECEIVE_WONDER_MAIL);
            break;
        case 1:
            sub_802D73C();
            CreateMenuDialogueBoxAndPortrait(sReplaceOldMailPrompt, 0, sUnknown_203B2F8->menuAction2, sUnknown_203B2F8->unk158, 0, 4, 0, NULL, 0);
            break;
        case DUPLICATE_WONDER_MAIL:
            sUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
            CreateDialogueBoxAndPortrait(sMailAlreadyReceived, 0, NULL, 0x101);
            break;
        case DUPLICATE_WONDER_MAIL_1:
            sUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
            CreateDialogueBoxAndPortrait(sMailAlreadyReceivedMayNotReceiveAgain, 0, NULL, 0x101);
            break;
        case 5:
            sUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
            CreateDialogueBoxAndPortrait(sOnlyOneMailCanBeHeldPleaseCompleteFirst, 0, NULL, 0x101);
            break;
        case 6:
            sUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
            CreateDialogueBoxAndPortrait(sTeamQuicksavedCompleteFirst, 0, NULL, 0x101);
            break;
        case 7:
            sUnknown_203B2F8->fallbackState = DRAW_JOB_LIST_1;
            CreateDialogueBoxAndPortrait(sTeamQuicksavedCannotDelete, 0, NULL, 0x101);
            break;
        case RECEIVE_WONDER_MAIL:
            sUnknown_203B2F8->wonderMailAccepted = TRUE;
            AcceptJob(&sUnknown_203B2F8->mail->wonderMail);
            ShiftJobSlotsDown();
            SortJobSlots();

            if (sUnknown_203B2F8->mail->wonderMail.unk2 == 4) {
                MemoryCopy8(sub_8096DD8(), sUnknown_203B2F8->mail->unk14, sizeof(gUnknown_203B490->unk190));
                MemoryCopy8(sub_8096DE8(), sUnknown_203B2F8->mail->unk18, sizeof(gUnknown_203B490->unk1B8));
            }

            switch (sUnknown_203B2F8->mail->wonderMail.unk4.dungeon.id) {
                case DUNGEON_ODDITY_CAVE:
                    sub_8097418(DUNGEON_ODDITY_CAVE - 1, 1);
                    break;
                case DUNGEON_REMAINS_ISLAND:
                    sub_8097418(DUNGEON_REMAINS_ISLAND - 1, 1);
                    break;
                case DUNGEON_MARVELOUS_SEA:
                    sub_8097418(DUNGEON_MARVELOUS_SEA - 1, 1);
                    break;
                case DUNGEON_FANTASY_STRAIT:
                    sub_8097418(DUNGEON_FANTASY_STRAIT - 1, 1);
                    break;
            }

            sUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
            CreateDialogueBoxAndPortrait(sReceivedWonderMail, 0, NULL, 0x101);
            break;
        case 9:
            sub_802D690();
            CreateMenuDialogueBoxAndPortrait(sOnlyOneMailCanBeHeldSoReplacePrompt,0,sUnknown_203B2F8->menuAction3,sUnknown_203B2F8->unk158,0,4,0,0,0);
            break;
        case JOB_LIST_FULL:
            sUnknown_203B2F8->fallbackState = DRAW_JOB_LIST;
            CreateDialogueBoxAndPortrait(sJobListFullPleaseDelete, 0, NULL, 0x101);
            break;
        case DRAW_JOB_LIST:
            sub_802C4C8(0, NULL, 4);
            break;
        case DRAW_JOB_LIST_1:
            sub_802C640(TRUE);
            break;
        case 0xd:
            DrawJobListMenu();
            sub_8012D60(&sUnknown_203B2F8->unk78, sUnknown_203B2F8->unk118, NULL, sUnknown_203B2F8->unk198, sUnknown_203B2F8->menuAction1, 2);
            break;
        case 0xe:
            DrawJobListMenu();
            sub_8012EA4(&sUnknown_203B2F8->unk78, 0);
            sub_8012D60(&sUnknown_203B2F8->unkC8, sUnknown_203B2F8->unk158, NULL, NULL, 4, 3);
            break;
        case 0xf:
            sub_803B35C(GetJobSlotInfo(sUnknown_203B2F8->jobSlotIndex), &sUnknown_203B2F8->unk14);
            sUnknown_203B2F8->unk14.unk0[0] = 3;
            sub_802DE84(&sUnknown_203B2F8->unk14);
            break;
        case 0x10:
            sub_803B35C(&sUnknown_203B2F8->mail->wonderMail, &sUnknown_203B2F8->unk14);
            sUnknown_203B2F8->unk14.unk0[0] = 3;
            sUnknown_203B2F8->unk14.mailStatus = MAIL_STATUS_SUSPENDED;
            sUnknown_203B2F8->unk14.unk50 = sUnknown_203B2F8->mail->unk18;
            sub_802DE84(&sUnknown_203B2F8->unk14);
            break;
    }
}

static void sub_802D5A4(void)
{
    s32 loopMax;
    s32 i;

    loopMax = 0;
    MemoryFill16(sUnknown_203B2F8->unk198, 0, sizeof(sUnknown_203B2F8->unk198));
    sUnknown_203B2F8->unk118[loopMax].text = gCommonDelete[0];
    sUnknown_203B2F8->unk118[loopMax].menuAction = DELETE_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk118[loopMax].text = gCommonInfo[0];
    sUnknown_203B2F8->unk118[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk118[loopMax].text = NULL;
    sUnknown_203B2F8->unk118[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B2F8->unk198[i] == 0) {
            if (sUnknown_203B2F8->unk118[i].menuAction == sUnknown_203B2F8->menuAction1)
                return;
        }
    }

    sUnknown_203B2F8->menuAction1 = DELETE_ACTION;
}

static void sub_802D63C(void)
{
    s32 loopMax;

    loopMax = 0;
    sUnknown_203B2F8->unk158[loopMax].text = gCommonYes[0];
    sUnknown_203B2F8->unk158[loopMax].menuAction = YES_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = gCommonNo[0];
    sUnknown_203B2F8->unk158[loopMax].menuAction = NO_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = NULL;
    sUnknown_203B2F8->unk158[loopMax].menuAction = CANCEL_ACTION;
}

static void sub_802D690(void)
{
    s32 loopMax;
    s32 i;

    loopMax = 0;
    sUnknown_203B2F8->unk158[loopMax].text = gCommonYes[0];
    sUnknown_203B2F8->unk158[loopMax].menuAction = YES_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = gCommonNo[0];
    sUnknown_203B2F8->unk158[loopMax].menuAction = NO_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = sNewMail;
    sUnknown_203B2F8->unk158[loopMax].menuAction = NEW_MAIL_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = sOldMail;
    sUnknown_203B2F8->unk158[loopMax].menuAction = OLD_MAIL_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = NULL;
    sUnknown_203B2F8->unk158[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B2F8->unk158[i].menuAction == sUnknown_203B2F8->menuAction3)
            return;
    }

    sUnknown_203B2F8->menuAction3 = NO_ACTION;
}

static void sub_802D73C(void)
{
    s32 loopMax;
    s32 i;

    loopMax = 0;
    sUnknown_203B2F8->unk158[loopMax].text = gCommonYes[0];
    sUnknown_203B2F8->unk158[loopMax].menuAction = YES_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = gCommonNo[0];
    sUnknown_203B2F8->unk158[loopMax].menuAction = NO_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = sNewMail;
    sUnknown_203B2F8->unk158[loopMax].menuAction = NEW_MAIL_ACTION;

    loopMax++;
    sUnknown_203B2F8->unk158[loopMax].text = NULL;
    sUnknown_203B2F8->unk158[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B2F8->unk158[i].menuAction == sUnknown_203B2F8->menuAction2)
            return;
    }

    sUnknown_203B2F8->menuAction2 = NO_ACTION;
}

static void sub_802D7D0(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    if (menuAction != CANCEL_ACTION)
        sUnknown_203B2F8->menuAction2 = menuAction;

    switch (menuAction) {
        case YES_ACTION:
            sub_802D1A0(WONDER_MAIL_EXIT);
            break;
        case NEW_MAIL_ACTION:
            sUnknown_203B2F8->fallbackState = 1;
            sub_802D1A0(0x10);
            break;
        case NO_ACTION:
        case DELETE_ACTION:
        default:
            sub_802D1A0(INITIAL_WONDER_MAIL_CHECK);
            break;
    }
}

static void sub_802D82C(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    if (menuAction != CANCEL_ACTION)
        sUnknown_203B2F8->menuAction3 = menuAction;

    switch (menuAction) {
        case YES_ACTION:
            ResetJobSlot(sUnknown_203B2F8->jobSlotIndex);
            ShiftJobSlotsDown();
            sub_802D1A0(RECEIVE_WONDER_MAIL);
            break;
        case NEW_MAIL_ACTION:
            sUnknown_203B2F8->fallbackState = 9;
            sub_802D1A0(16);
            break;
        case OLD_MAIL_ACTION:
            sUnknown_203B2F8->fallbackState = 9;
            sub_802D1A0(15);
            break;
        default:
        case CANCEL_ACTION:
        case DELETE_ACTION:
        case NO_ACTION:
            sub_802D1A0(1);
            break;
    }
}

static void sub_802D8CC(void)
{
    switch (sub_802C598(TRUE)) {
        case 0:
        case 1:
            break;
        case 3:
            sUnknown_203B2F8->jobSlotIndex = GetPelipperBoardSlotIndex();
            sub_802D1A0(13);
            break;
        case 4:
            sUnknown_203B2F8->jobSlotIndex = GetPelipperBoardSlotIndex();
            sUnknown_203B2F8->fallbackState = DRAW_JOB_LIST_1;
            sub_802D1A0(15);
            break;
        case 2:
            sub_802C688();
            sub_802D1A0(1);
            break;
    }
}

static void sub_802D940(void)
{
    WonderMail *mail;
    s32 menuAction;

    menuAction = 0;
    sub_802C598(FALSE);

    if (!sub_8012FD8(&sUnknown_203B2F8->unk78)) {
        sub_8013114(&sUnknown_203B2F8->unk78, &menuAction);
        if (menuAction != CANCEL_ACTION)
            sUnknown_203B2F8->menuAction1 = menuAction;
    }

    switch (menuAction) {
        case DELETE_ACTION:
            if (sUnknown_203B2F8->unk9) {
                mail = &gUnknown_203B490->jobSlots[sUnknown_203B2F8->jobSlotIndex];
                if (mail->mailType > MAIL_TYPE_SUSPENDED_JOB && sUnknown_203B2F8->dungeonID == mail->unk4.dungeon.id) {
                    sub_802D1A0(7);
                    break;
                }
            }

            sub_802D1A0(14);
            break;
        case INFO_ACTION:
            sUnknown_203B2F8->fallbackState = DRAW_JOB_LIST_1;
            sub_802D1A0(15);
            break;
        case CANCEL_ACTION:
            sub_802D1A0(DRAW_JOB_LIST_1);
            break;
    }
}

static void sub_802D9F0(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_802C598(FALSE);
    sub_8012FD8(&sUnknown_203B2F8->unk78);
    if (!sub_8012FD8(&sUnknown_203B2F8->unkC8))
        sub_8013114(&sUnknown_203B2F8->unkC8, &menuAction);

    switch (menuAction) {
        case CANCEL_ACTION:
        case NO_ACTION:
            sub_802D1A0(DRAW_JOB_LIST_1);
            break;
       
        case YES_ACTION:
            sub_802C688();
            ResetJobSlot(sUnknown_203B2F8->jobSlotIndex);
            ShiftJobSlotsDown();
            sub_802D1A0(RECEIVE_WONDER_MAIL);
            break;
    }
}

static void sub_802DA60(void)
{
    switch (sub_802DEE0()) {
        case 2:
        case 3:
            sub_802DF24();
            sub_802D1A0(sUnknown_203B2F8->fallbackState);
            break;
        case 0:
        case 1:
            break;
    }
}

static void AdvancetoFallbackWonderMailRescueState(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sub_802D1A0(sUnknown_203B2F8->fallbackState);
}

static bool8 sub_802DAA8(void)
{
    WonderMail *mail;

    mail = GetJobSlotInfo(sUnknown_203B2F8->jobSlotIndex);

    if (!sUnknown_203B2F8->unk9)
        return TRUE;

    if (mail->mailType != WONDER_MAIL_TYPE_THANK_YOU && sUnknown_203B2F8->dungeonID == mail->unk4.dungeon.id)
        return FALSE;
    return TRUE;
}

static bool8 sub_802DADC(void)
{
    u8 mailType;
    WonderMail *mail;
    s32 i;

    if (!sUnknown_203B2F8->unk9)
        return TRUE;

    for (mail = &gUnknown_203B490->jobSlots[0], i = 0; i < MAX_ACCEPTED_JOBS; mail++, i++) {
        mailType = mail->mailType;
        if (mailType == 0)
            return TRUE;
        if (mailType == WONDER_MAIL_TYPE_THANK_YOU)
            return TRUE;
        if (WONDER_MAIL_TYPE_THANK_YOU < mailType && sUnknown_203B2F8->dungeonID != mail->unk4.dungeon.id)
            return TRUE;
    }

    return FALSE;
}
