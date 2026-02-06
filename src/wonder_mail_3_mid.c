#include "global.h"
#include "globaldata.h"
#include "structs/str_802C39C.h"
#include "code_802DE84.h"
#include "code_803B050.h"
#include "common_strings.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_3.h"
#include "wonder_mail_3_mid.h"
#include "wonder_mail_802CDD4.h"

enum MenuActions
{
    CANCEL_ACTION = 1,
    SEND_ACTION,
    INFO_ACTION
};

// Size: 0x150
struct unkStruct_203B30C
{
    s32 state;
    u8 unk4;
    unkStruct_802C39C unk8;
    MenuStruct unk60;
    MenuItem unkB0[8];
    WindowTemplates unkF0;
};

static EWRAM_INIT struct unkStruct_203B30C *gUnknown_203B30C = { NULL };

const WindowTemplate gUnknown_80E03C4 = WIN_TEMPLATE_DUMMY;
const WindowTemplate gUnknown_80E03DC = {
    0,
    0x03,
    0x03, 0x03,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};
const WindowTemplate gUnknown_80E03F4 = {
    0,
    0x03,
    0x15, 0x06,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const u8 gUnknown_80E040C[] = "Send";

static void sub_802EFEC(u32);
static void sub_802F148(void);
static void sub_802F184(void);
static void sub_802F1E8(void);
static void sub_802F004();
static void sub_802F088();
static void sub_802F108(void);

u32 sub_802EF48(void)
{
    gUnknown_203B30C = MemoryAlloc(sizeof(struct unkStruct_203B30C), MEMALLOC_GROUP_8);
    sub_802EFEC(0);
    return 1;
}

UNUSED static u32 sub_802EF6C(void)
{
    switch(gUnknown_203B30C->state)
    {
        case 0:
        case 1:
            sub_802F148();
            break;
        case 2:
            sub_802F184();
            break;
        case 3:
            sub_802F1E8();
            break;
        case 4:
            return 3;
        case 5:
        default:
            return 2;
    }
    return 0;
}

UNUSED static u8 sub_802EFC4(void)
{
    return gUnknown_203B30C->unk4;
}

UNUSED static void sub_802EFD0(void)
{
    if (gUnknown_203B30C != NULL) {
        MemoryFree(gUnknown_203B30C);
        gUnknown_203B30C = NULL;
    }
}

static void sub_802EFEC(u32 newState)
{
    gUnknown_203B30C->state = newState;
    sub_802F004();
    sub_802F088();
}

static void sub_802F004(void)
{
    s32 index;

    RestoreSavedWindows(&gUnknown_203B30C->unkF0);
    switch(gUnknown_203B30C->state)
    {
        case 2:
            sub_802F108();
            gUnknown_203B30C->unkF0.id[2] = gUnknown_80E03F4;
            sub_8012CAC(&gUnknown_203B30C->unkF0.id[2], gUnknown_203B30C->unkB0);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B30C->unkF0.id[index] = gUnknown_80E03C4;
            }
    }
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B30C->unkF0, TRUE, TRUE);
}

static void sub_802F088(void)
{
    unkStruct_803B344 *temp;

    switch(gUnknown_203B30C->state)
    {
        case 0:
            sub_802CDD4(0);
            break;
        case 1:
            sub_802CED8(TRUE);
            break;
        case 2:
            sub_802CFD0();
            sub_8012D60(&gUnknown_203B30C->unk60, gUnknown_203B30C->unkB0, 0, 0, 3, 2);
            break;
        case 3:
            temp = sub_803B344(gUnknown_203B30C->unk4);
            sub_803B35C(&temp->mail, &gUnknown_203B30C->unk8);
            gUnknown_203B30C->unk8.unk0[0] = 3;
            gUnknown_203B30C->unk8.mailStatus = MAIL_STATUS_SUSPENDED;
            gUnknown_203B30C->unk8.unk50 = temp->unk18;
            sub_802DE84(&gUnknown_203B30C->unk8);
    }
}

static void sub_802F108(void)
{
    s32 loopMax = 0;

    gUnknown_203B30C->unkB0[loopMax].text = gUnknown_80E040C;
    gUnknown_203B30C->unkB0[loopMax].menuAction = SEND_ACTION;
    loopMax += 1;
    gUnknown_203B30C->unkB0[loopMax].text = gCommonInfo[0];
    gUnknown_203B30C->unkB0[loopMax].menuAction = INFO_ACTION;
    loopMax += 1;
    gUnknown_203B30C->unkB0[loopMax].text = NULL;
    gUnknown_203B30C->unkB0[loopMax].menuAction = CANCEL_ACTION;
}

static void sub_802F148(void)
{
    switch(sub_802CE5C(TRUE))
    {
        case 0:
        case 1:
            break;
        case 3:
            gUnknown_203B30C->unk4 = sub_802CEBC();
            sub_802EFEC(2);
            break;
        case 2:
            sub_802CF14();
            sub_802EFEC(5);
            break;
    }
}

static void sub_802F184(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_802CE5C(FALSE);

    if (sub_8012FD8(&gUnknown_203B30C->unk60) == 0) {
        sub_8013114(&gUnknown_203B30C->unk60, &menuAction);
    }

    switch(menuAction)
    {
        case SEND_ACTION:
            sub_802CF14();
            sub_802EFEC(4);
            break;
        case INFO_ACTION:
            sub_802EFEC(3);
            break;
        case CANCEL_ACTION:
            sub_802EFEC(1);
            break;
    }
}

static void sub_802F1E8(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            sub_802EFEC(1);
            break;
        case 0:
        case 1:
            break;
    }
}
