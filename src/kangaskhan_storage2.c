#include "global.h"
#include "code_80130A8.h"
#include "code_801B3C0.h"
#include "code_801C8C4.h"
#include "code_8098BDC.h"
#include "common_strings.h"
#include "input.h"
#include "kangaskhan_storage2.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 unkStruct_203B20C *sUnknown_203B20C = {0};

#include "data/kangaskhan_storage2.h"

static void sub_8017F10(u32);
static void sub_8017F28(void);
static void sub_8018100(void);
static void sub_8018280(void);
static void sub_80182E4(void);
static void sub_801841C(void);
static void sub_80184D4(void);
static void sub_8018588(void);
static void sub_8018620(void);
static void sub_80186F8(void);
static void sub_8018854(void);
static void sub_8018904(void);
static void sub_80189C8(void);
static void sub_8018AC8(void);
static void sub_8018AE4(void);

bool8 sub_8017E1C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);
    sUnknown_203B20C = MemoryAlloc(sizeof(unkStruct_203B20C), 8);
    sUnknown_203B20C->menuAction1 = 0;
    sUnknown_203B20C->menuAction2 = 0;
    sUnknown_203B20C->menuAction3 = 0;
    sub_8017F10(0);
    return TRUE;
}

u32 sub_8017E54(void)
{
    switch (sUnknown_203B20C->state) {
        case 0:
            sub_8017F10(1);
            break;
        case 1:
            sub_8018588();
            break;
        case 4:
        case 5:
            sub_8018620();
            break;
        case 6:
            sub_8018904();
            break;
        case 7:
            sub_8018AC8();
            break;
        case 10:
        case 11:
            sub_80186F8();
            break;
        case 12:
            sub_8018854();
            break;
        case 13:
            sub_80189C8();
            break;
        case 14:
            sub_8018AE4();
            break;
        case 3:
            return 3;
    }
    return 0;
}

void sub_8017EF4(void)
{
    if (sUnknown_203B20C != NULL) {
        MemoryFree(sUnknown_203B20C);
        sUnknown_203B20C = NULL;
    }
}

static void sub_8017F10(u32 newState)
{
    sUnknown_203B20C->state = newState;
    sub_8017F28();
    sub_8018100();
}

static void sub_8017F28(void)
{
    s32 index;

    sub_8006518(sUnknown_203B20C->unkF0);

    switch (sUnknown_203B20C->state) {
        case 1:
            sUnknown_203B20C->unkF0[0] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[1] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[0] = sUnknown_80DB7B8;
            sub_80182E4();
            sUnknown_203B20C->unkF0[2] = sUnknown_80DB7D0;
            sub_8012CAC(&sUnknown_203B20C->unkF0[2], sUnknown_203B20C->unk20);
            break;
        case 4:
        case 5:
            sUnknown_203B20C->unkF0[0] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[1] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[2] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[0] = sUnknown_80DB7B8;
            break;
        case 10:
        case 11:
            sUnknown_203B20C->unkF0[0] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[1] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[2] = sUnknown_80DB7B8;
            sUnknown_203B20C->unkF0[0] = sUnknown_80DB800;
            break;
        case 12:
            sUnknown_203B20C->unkF0[1] = sUnknown_80DB818;
            break;
        case 6:
        case 13:
            sUnknown_203B20C->unkF0[2] = sUnknown_80DB7E8;
            break;
        default:
        case 0:
            for (index = 0; index < 4; index++)
                sUnknown_203B20C->unkF0[index] = sUnknown_80DB7B8;
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B20C->unkF0, TRUE, TRUE);
}

static void sub_8018100(void)
{
    switch (sUnknown_203B20C->state) {
        case 1:
            sub_8012D60(&sUnknown_203B20C->unk70, sUnknown_203B20C->unk20, 0, sUnknown_203B20C->unk60, sUnknown_203B20C->menuAction1, 2);
            break;
        case 4:
            sub_801A5D8(3, 3, NULL, 10);
            break;
        case 5:
            sub_801A8D0(TRUE);
            break;
        case 6:
            sub_801A9E0();
            sub_801841C();
            sub_8012D60(&sUnknown_203B20C->unk70, sUnknown_203B20C->unk20, 0, sUnknown_203B20C->unk60, sUnknown_203B20C->menuAction2, 2);
            break;
        case 7:
            sub_801B3C0(&sUnknown_203B20C->item);
            break;
        case 10:
            sub_801C8C4(1, 3, 0, 10);
            sub_801AD34(0);
            break;
        case 11:
            sub_801CB5C(TRUE);
            sub_801AD34(0);
            break;
        case 12:
            sUnknown_203B20C->unkC0.unk10 = 2;
            sUnknown_203B20C->unkC0.unk8 = 1;

            if (gTeamInventoryRef->teamStorage[sUnknown_203B20C->item.id] > 99)
                sUnknown_203B20C->unkC0.unkC = 99;
            else
                sUnknown_203B20C->unkC0.unkC = gTeamInventoryRef->teamStorage[sUnknown_203B20C->item.id];

            sUnknown_203B20C->unkC0.unk4 = sUnknown_203B20C->unkC0.unkC;
            sUnknown_203B20C->unkC0.unk14 = 1;
            sUnknown_203B20C->unkC0.unk18 = &sUnknown_203B20C->unkF0[1];
            sUnknown_203B20C->unkC0.unk1C = 40;
            sUnknown_203B20C->unkC0.unk20 = 18;
            sub_8013AA0(&sUnknown_203B20C->unkC0);
            sub_8018280();
            break;
        case 13:
            sub_801CCD8();
            sub_801AD34(0);
            sub_80184D4();
            sub_8012D60(&sUnknown_203B20C->unk70, sUnknown_203B20C->unk20, 0, sUnknown_203B20C->unk60, sUnknown_203B20C->menuAction3, 2);
            break;
        case 14:
            sub_801B3C0(&sUnknown_203B20C->item);
            break;
        case 0:
        default:
            break;
    }
}

static void sub_8018280(void)
{
    sub_8008C54(sUnknown_203B20C->unkC0.unk14);
    sub_80073B8(sUnknown_203B20C->unkC0.unk14);
    xxx_call_draw_string(4, 0, sNumber, sUnknown_203B20C->unkC0.unk14, 0);
    sub_8013C68(&sUnknown_203B20C->unkC0);
    sub_80073E0(sUnknown_203B20C->unkC0.unk14);
    sub_801CCD8();
    sub_801AD34(0);
    sub_8012EA4(&sUnknown_203B20C->unk70, 0);
}

static void sub_80182E4(void)
{
    int index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(sUnknown_203B20C->unk60, 0, sizeof(sUnknown_203B20C->unk60));
    sUnknown_203B20C->unk20[0].text = gCommonStore[0];
    sUnknown_203B20C->unk20[0].menuAction = 2;

    if (GetNumberOfFilledInventorySlots() == 0 || sub_801CF50(0))
        sUnknown_203B20C->unk60[0] = 1;

    loopMax += 1;
    sUnknown_203B20C->unk20[loopMax].text = gCommonTake[0];
    sUnknown_203B20C->unk20[loopMax].menuAction = 3;

    if (sub_801CF14(1) || INVENTORY_SIZE <=  GetNumberOfFilledInventorySlots())
        sUnknown_203B20C->unk60[loopMax] = 1;

    loopMax += 1;
    sUnknown_203B20C->unk20[loopMax].text = gCommonCancel[0];
    sUnknown_203B20C->unk20[loopMax].menuAction = 1;

    loopMax += 1;
    sUnknown_203B20C->unk20[loopMax].text = NULL;
    sUnknown_203B20C->unk20[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B20C->unk60[index] == 0) {
            if (sUnknown_203B20C->unk20[index].menuAction == sUnknown_203B20C->menuAction1)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B20C->unk60[index] == 0) {
            sUnknown_203B20C->menuAction1 = sUnknown_203B20C->unk20[index].menuAction;
            break;
        }
    }
}

static void sub_801841C(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(sUnknown_203B20C->unk60,0,sizeof(sUnknown_203B20C->unk60));
    sUnknown_203B20C->unk20[0].text = gCommonStore[0];
    sUnknown_203B20C->unk20[0].menuAction = 2;
    if (!sub_801ADA0(sUnknown_203B20C->itemIndex))
        sUnknown_203B20C->unk60[0] = 1;

    loopMax += 1;
    sUnknown_203B20C->unk20[loopMax].text = gCommonInfo[0];
    sUnknown_203B20C->unk20[loopMax].menuAction = 4;

    loopMax += 1;
    sUnknown_203B20C->unk20[loopMax].text = NULL;
    sUnknown_203B20C->unk20[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B20C->unk60[index] == 0) {
            if (sUnknown_203B20C->unk20[index].menuAction == sUnknown_203B20C->menuAction2)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B20C->unk60[index] == 0) {
            sUnknown_203B20C->menuAction2 = sUnknown_203B20C->unk20[index].menuAction;
            break;
        }
    }
}

static void sub_80184D4(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(sUnknown_203B20C->unk60, 0, sizeof(sUnknown_203B20C->unk60));
    sUnknown_203B20C->unk20[0].text = gCommonTake[0];
    sUnknown_203B20C->unk20[0].menuAction = 3;

    if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
        sUnknown_203B20C->unk60[0] = 1;

    loopMax += 1;
    sUnknown_203B20C->unk20[loopMax].text = gCommonInfo[0];
    sUnknown_203B20C->unk20[loopMax].menuAction = 4;

    loopMax += 1;
    sUnknown_203B20C->unk20[loopMax].text = NULL;
    sUnknown_203B20C->unk20[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B20C->unk60[index] == 0) {
            if (sUnknown_203B20C->unk20[index].menuAction == sUnknown_203B20C->menuAction3)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (sUnknown_203B20C->unk60[index] == 0) {
            sUnknown_203B20C->menuAction3 = sUnknown_203B20C->unk20[index].menuAction;
            break;
        }
    }
}

static void sub_8018588(void)
{
    s32 menuAction;
    menuAction = 0;

    if (sub_8012FD8(&sUnknown_203B20C->unk70) == 0) {
        sub_8013114(&sUnknown_203B20C->unk70, &menuAction);
        if (menuAction != 1)
            sUnknown_203B20C->menuAction1 = menuAction;
    }

    switch (menuAction) {
        case 2:
            if (GetNumberOfFilledInventorySlots() != 0 && !sub_801CF50(0))
                sub_8017F10(4);
            else
                sub_8012EA4(&sUnknown_203B20C->unk70, 1);
            break;
        case 3:
            if (sub_801CF14(1))
                sub_8012EA4(&sUnknown_203B20C->unk70, 1);
            else
                sub_8017F10(10);
            break;
        case 1:
            sub_8017F10(3);
            break;
    }
}

static void sub_8018620(void)
{
    s32 index;

    switch (sub_801A6E8(TRUE)) {
        case 3:
            if (sub_801AEA8() != 0) {
                for (index = 0; index < INVENTORY_SIZE; index++) {
                    if (sub_801AED0(index) != 0) {
                        MoveToStorage(&gTeamInventoryRef->teamItems[index]);
                        gTeamInventoryRef->teamItems[index].id = 0;
                        gTeamInventoryRef->teamItems[index].flags = 0;
                    }
                }

                FillInventoryGaps();
                sub_801AE84();

                if (GetNumberOfFilledInventorySlots() == 0) {
                    sub_801A928();
                    sub_8017F10(1);
                }
                else
                    sub_8017F10(5);
            }
            else {
                sUnknown_203B20C->itemIndex = sub_801A8AC();
                sUnknown_203B20C->item = gTeamInventoryRef->teamItems[sUnknown_203B20C->itemIndex];
                sub_8017F10(6);
            }
            break;
        case 4:
            sUnknown_203B20C->itemIndex = sub_801A8AC();
            sUnknown_203B20C->item = gTeamInventoryRef->teamItems[sUnknown_203B20C->itemIndex];
            sub_8017F10(7);
            break;
        case 2:
            sub_801A928();
            sub_8017F10(1);
            break;
    }
}

static void sub_80186F8(void)
{
    BulkItem item;
    s32 itemID;

    switch (sub_801CA08(TRUE)) {
        case 3:
            if (sub_801CFB8() != 0) {
                for (itemID = 0; itemID < NUMBER_OF_ITEM_IDS; itemID++) {
                    if (sub_801CFE0(itemID) != 0) {
                        item.id = itemID;

                        if (IsThrowableItem(item.id)) {
                            if (gTeamInventoryRef->teamStorage[item.id] > 99)
                                item.quantity = 99;
                            else
                                item.quantity = gTeamInventoryRef->teamStorage[item.id];
                        }
                        else
                            item.quantity = 1;

                        gTeamInventoryRef->teamStorage[item.id] -= item.quantity;
                        AddHeldItemToInventory(&item);
                    }
                }

                FillInventoryGaps();
                sub_801CF94();

                if (!sub_801CF14(1) && GetNumberOfFilledInventorySlots() < INVENTORY_SIZE)
                    sub_8017F10(11);
                else {
                    sub_801CBB8();
                    sub_8017F10(1);
                }
            }
            else {
                sUnknown_203B20C->id = sub_801CB24();
                xxx_init_itemslot_8090A8C(&sUnknown_203B20C->item, sUnknown_203B20C->id, 0);
                sUnknown_203B20C->item.quantity = 1;
                sub_8017F10(13);
            }
            break;
        case 4:
            sUnknown_203B20C->id = sub_801CB24();
            xxx_init_itemslot_8090A8C(&sUnknown_203B20C->item, sUnknown_203B20C->id, 0);
            sUnknown_203B20C->item.quantity = 1;
            sub_8017F10(14);
            break;
        case 2:
            sub_801CBB8();
            sub_8017F10(1);
            break;
        case 1:
            sub_801AD34(0);
            break;
    }
}

static void sub_8018854(void)
{
    BulkItem item;

    sub_801CA08(FALSE);
    sub_8012FD8(&sUnknown_203B20C->unk70);

    switch (sub_8013BBC(&sUnknown_203B20C->unkC0)) {
        case 3:
            sUnknown_203B20C->item.quantity = sUnknown_203B20C->unkC0.unk0;
            gTeamInventoryRef->teamStorage[sUnknown_203B20C->item.id] -= sUnknown_203B20C->item.quantity;
            item.id = sUnknown_203B20C->item.id;
            item.quantity = sUnknown_203B20C->item.quantity;
            AddHeldItemToInventory(&item);

            if (!sub_801CF14(1)) {
                if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                error:
                    sub_801CBB8();
                    sub_8017F10(1);
                }
                else
                    sub_8017F10(11);
            }
            else
                goto error;
            break;
        case 2:
            sub_8017F10(11);
            break;
        case 1:
            sub_8018280();
            break;
        case 0:
            break;
    }
}

static void sub_8018904(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_801A6E8(FALSE);
    if (sub_8012FD8(&sUnknown_203B20C->unk70) == 0) {
        sub_8013114(&sUnknown_203B20C->unk70, &menuAction);
        if (menuAction != 1)
            sUnknown_203B20C->menuAction2 = menuAction;
    }

    switch (menuAction) {
        case 2:
            if (IsNotMoneyOrUsedTMItem(sUnknown_203B20C->item.id)) {
                if (!sub_801ADA0(sUnknown_203B20C->itemIndex)) {
                error:
                    sub_8012EA4(&sUnknown_203B20C->unk70, 1);
                }
                else {
                    MoveToStorage(&sUnknown_203B20C->item);
                    ShiftItemsDownFrom(sUnknown_203B20C->itemIndex);
                    FillInventoryGaps();

                    if (GetNumberOfFilledInventorySlots() == 0) {
                        sub_801A928();
                        sub_8017F10(1);
                    }
                    else
                        sub_8017F10(5);
                }
            }
            else
                goto error;
            break;
        case 4:
            sub_8099690(0);
            sub_8017F10(7);
            break;
        case 1:
            sub_8017F10(5);
            break;
    }
}

static void sub_80189C8(void)
{
    BulkItem item;
    s32 menuAction;

    menuAction = 0;

    sub_801CA08(FALSE);
    if (sub_8012FD8(&sUnknown_203B20C->unk70) == 0) {
        sub_8013114(&sUnknown_203B20C->unk70, &menuAction);
        if (menuAction != 1)
            sUnknown_203B20C->menuAction3 = menuAction;
    }

    switch (menuAction) {
        case 3:
            if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                sub_8012EA4(&sUnknown_203B20C->unk70, 1);
            else if (IsThrowableItem(sUnknown_203B20C->item.id))
                sub_8017F10(12);
            else {
                gTeamInventoryRef->teamStorage[sUnknown_203B20C->item.id] -= sUnknown_203B20C->item.quantity;
                item.id = sUnknown_203B20C->item.id;
                item.quantity = sUnknown_203B20C->item.quantity;
                AddHeldItemToInventory(&item);

                if (!sub_801CF14(1)) {
                    if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                    {
                    error:
                        sub_801CBB8();
                        sub_8017F10(1);
                    }
                    else
                        sub_8017F10(11);
                }
                else
                    goto error;
            }
            break;
        case 4:
            sub_8017F10(14);
            break;
        case 1:
            sub_8017F10(11);
            break;
    }
}

static void sub_8018AC8(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(5);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}

static void sub_8018AE4(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(11);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}