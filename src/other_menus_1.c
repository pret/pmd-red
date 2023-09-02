#include "global.h"
#include "constants/communication_error_codes.h"
#include "constants/dungeon.h"
#include "dungeon_global_data.h"
#include "pokemon.h"
#include "code_8094F88.h"
#include "save.h"

#include "main_menu.h"
#include "memory.h"

extern s32 gCommsTimeout; // Counts to 100 and then errors if other player hasn't connected
extern s32 gUnknown_202EC48;
extern u32 gUnknown_202EC40[2];

extern void sub_800D494(void);
extern s32 sub_800D33C(void);
extern void sub_800D520(void);
extern u8 sub_800D600(void);
extern void sub_80373C4(void);
extern void sub_800D59C(s32 *, u32);
extern void sub_800D570(void);
extern void sub_800D510(void);
extern u8 sub_800D588(void);
extern struct UnkStruct_203B184 *gUnknown_203B184;
extern void sub_800D670(u32, s32 *, u32);
extern void sub_800D68C(u32);

u32 sub_8037C10(u8 param_1)
{
    u32 ret;

    if (param_1 != 0)
    {
        if (sub_800D588())
        {
            ret = gUnknown_202EC40[0];
        }
        else
        {
            ret = gUnknown_202EC40[1];
        }
    }
    else if (sub_800D588())
    {
        ret = gUnknown_202EC40[1];
    }
    else
    {
        ret =  gUnknown_202EC40[0];
    }
    return ret;
}

void sub_8037C44(s32 mode, void *data)
{
    s32 index;

    for(index = 0; index < 2; index++)
    {
        sub_800D68C(index);
    }
    switch(mode) {
        case 0:
        case 1:
            sub_800D59C(data, sizeof(struct unkStruct_8035D94));
            break;
        case 2:
        case 3:
        case 6:
        case 7:
            sub_800D59C(data, sizeof(struct unkStruct_203B480));
            break;
        case 4:
        case 5:
            sub_800D59C(data, sizeof(struct WonderMailStruct_203B2C0_sub));
            break;
        case 9:
        case 10:
            sub_800D59C(data, 0xb4);
            break;
    }
}

void sub_8037CC4(s32 mode, void *param_2, void *param_3)
{
    switch(mode)
    {
        case 0:
        case 1:
            sub_800D670(0, param_2, sizeof(struct unkStruct_8035D94));
            sub_800D670(1, param_3, sizeof(struct unkStruct_8035D94));
            break;
        case 2:
        case 3:
        case 6:
        case 7:
            sub_800D670(0, param_2, sizeof(struct unkStruct_203B480));
            sub_800D670(1, param_3, sizeof(struct unkStruct_203B480));
            break;
        case 4:
        case 5:
            sub_800D670(0, param_2, sizeof(struct WonderMailStruct_203B2C0_sub));
            sub_800D670(1, param_3, sizeof(struct WonderMailStruct_203B2C0_sub));
            break;
        case 9:
        case 10:
            sub_800D670(0, param_2, 0xb4);
            sub_800D670(1, param_3, 0xb4);
            break;
    }
}

// TODO: same as sub_80381F4
s32 sub_8037D64(u32 mode, void * param_2, void * param_3)
{
    u32 iVar2;
    s32 linkStatus;

    iVar2 = 0;
    linkStatus = COMMS_GOOD;
    gUnknown_202EC48 = 0;
    sub_800D494();
    sub_8037C44(mode, param_2);
    goto _first;
_start:
    while (iVar2 - 3 > 2) {
        if (99 < gUnknown_202EC48) {
            sub_800D520();
            sub_800D510();
            return COMMS_NOT_READY;
        }
        gUnknown_202EC48++;
    _first:
        sub_80373C4();
        iVar2 = sub_800D33C();
        sub_800D570();
        if (iVar2 == 2) {
            if (sub_800D600() == 0) {
                sub_800D520();
                sub_800D510();
                linkStatus = 5;
            }
            else {
                linkStatus = COMMS_GOOD;
            }
            goto _end;
        }
        else
            goto _start;
    }
    sub_800D520();
    sub_800D510();
    return 1;
_end:
    sub_8037CC4(mode, param_2, param_3);
    return linkStatus;
}

s32 sub_8037DF0(void)
{
    s32 linkStatus;
    s32 iStack_10;
    s32 iStack_c;

    linkStatus = COMMS_GOOD;
    sub_800D670(0,&iStack_10,4);
    sub_800D670(1,&iStack_c,4);
    if ((iStack_10 != 0) || (iStack_c != 0)) {
        linkStatus = (!sub_800D588()) ? iStack_c : iStack_10;
        if (linkStatus == COMMS_GOOD) {
            linkStatus = 0xe;
        }
    }
    return linkStatus;
}

void sub_8037E38(struct unkStruct_8035D94 *param_1,struct unkStruct_8035D94 *param_2)
{
    struct unkStruct_8035D94 *r3;
    struct unkStruct_8035D94 *r4;
    u32 load;

    r4 = sub_800D588() == 0 ? param_2 : param_1;
    r3 = sub_800D588() == 0 ? param_1 : param_2;

    if ((r4->itemIndex).itemIndex_u8 == (r3->itemIndex).itemIndex_u8) {
         load = gTeamInventoryRef->teamStorage[r4->itemIndex.itemIndex_u8];
         load += r3->numItems;
         gTeamInventoryRef->teamStorage[r4->itemIndex.itemIndex_u8] = load;
    }
    else {
        load = gTeamInventoryRef->teamStorage[r3->itemIndex.itemIndex_u8];
        load += r3->numItems;
        gTeamInventoryRef->teamStorage[r3->itemIndex.itemIndex_u8] = load;
    }
}

void sub_8037E90(struct unkStruct_203B480 *param_1, struct unkStruct_203B480 *param_2)
{
    if(sub_800D588() == 0)
    {
        param_2 = param_1;
    }
    param_2->mailType = 2;
    sub_80951BC(param_2);
    sub_8095274(param_2->unk10.unk10);
}

void nullsub_53(void *param_1, void *param_2)
{}

void sub_8037EBC(struct WonderMailStruct_203B2C0_sub  *param_1, struct WonderMailStruct_203B2C0_sub *param_2) {
    struct unkStruct_203B480 *mail;
    struct WonderMailStruct_203B2C0_sub *puVar2;
    
    if(sub_800D588() == 0)
    {
        puVar2 = param_1;
    }
    else
    {
        puVar2 = param_2;
    }
    mail = GetMailatIndex(GetMailIndex(1, (puVar2->mail).unk10.unk10));
    *mail = (*puVar2).mail;
    mail->mailType = 5;
    sub_80951FC(mail);
    mail->mailType = 7;

    if(puVar2->pokemon.speciesNum != MONSTER_NONE)
    {
        gUnknown_203B484->unk0 = puVar2->mail.unk10.unk10;
        gUnknown_203B484->unk4 = puVar2->pokemon;
        gUnknown_203B484->unk4.dungeonLocation.id = DUNGEON_UNKNOWN_WORLD;
        gUnknown_203B484->unk4.dungeonLocation.floor = 1;
    }
    else
    {
        MemoryFill8((u8 *)gUnknown_203B484, 0, sizeof(struct unkStruct_203B484));
        gUnknown_203B484->unk4.speciesNum = MONSTER_NONE;
    }
}

void sub_8037F4C(struct unkStruct_203B480 *param_1, struct unkStruct_203B480 *param_2)
{
    struct unkStruct_203B480 *mail;
    struct MainMenu *mainMenu;
    
    if(sub_800D588() == 0)
    {
        param_2 = param_1;
    }
    mail = GetMailatIndex(GetMailIndex(4, param_2->unk10.unk10));
    *mail = *param_2;
    mail->mailType = 6;
    mainMenu = GetMainMenu();
    if(mainMenu)
    {
        mainMenu->unk3A = 1;
    }
}

void sub_8037F9C(u32 mode, void *param_2, void *param_3)
{
    switch(mode)
    {
        case 0:
        case 1:
            sub_8037E38(param_2, param_3);
            break;
        case 7:
            sub_8037F4C(param_2, param_3);
            break;
        case 3:
            sub_8037E90(param_2, param_3);
            break;
        case 5:
            sub_8037EBC(param_2, param_3);
            break;
        case 10:
            nullsub_53(param_2, param_3);
            break;
    }
}

s32 sub_8038014(struct unkStruct_8035D94 *param_1,struct unkStruct_8035D94 *param_2)
{
    s32 linkStatus;
    s32 r2;
    struct unkStruct_8035D94 *r3;
    struct unkStruct_8035D94 *r4;

    r4 = sub_800D588() == 0 ? param_2 : param_1;
    r3 = sub_800D588() == 0 ? param_1 : param_2;

    if ((r4->itemIndex).itemIndex_u8 == (r3->itemIndex).itemIndex_u8) {
        r2 = gTeamInventoryRef->teamStorage[r4->itemIndex.itemIndex_u8];
        r2 += r3->numItems;
        if (r2 > 999) {
            linkStatus = COMMS_NO_ROOM_STORAGE;
        }
        else
            linkStatus = COMMS_GOOD;
    }
    else {
        r2 = gTeamInventoryRef->teamStorage[r3->itemIndex.itemIndex_u8];
        r2 += r3->numItems;
        if (r2 > 999) {
            linkStatus = COMMS_NO_ROOM_STORAGE;
        }
        else
            linkStatus = COMMS_GOOD;

    }
    return linkStatus;
}

s32 sub_8038078(struct unkStruct_203B480 *param_1,struct unkStruct_203B480 *param_2)
{
    u32 uVar2;
    u32 uVar3;

    if (sub_800D588() == 0) {
        param_2 = param_1;
    }
    uVar3 = (param_2->unk10).unk10;
    if (gUnknown_203B184 != NULL) {
        uVar2 = gUnknown_203B184->unk050;
    }
    else {
        uVar2 = sub_8011C34();
    }
    if (HasMail(4,uVar3) && (param_2->unk28 == uVar2)) {
        return COMMS_GOOD;
    }
    else {
        return COMMS_NOT_ELIGIBLE_2;
    }
}

s32 sub_80380C4(struct unkStruct_203B480 *param_1,struct unkStruct_203B480 *param_2)
{
    u32 uVar2;
    struct unkStruct_203B480 *mail;

    if (sub_800D588() == 0) {
        mail = param_1;
    }
    else
        mail = param_2;

    uVar2 = mail->unk10.unk10;
    if (HasMail(2,uVar2) || HasMail(4,uVar2) || HasMail(6,uVar2))
    {
        return COMMS_DUPLICATE_MAIL;
    }
    if(sub_8095298(mail->unk10.unk10))
    {
        return COMMS_DUPLICATE_MAIL;
    }
    else if (FindOpenMailSlot() == -1)
    {
        return COMMS_NO_ROOM_MAIL;
    }
    else
    {
        return COMMS_GOOD;
    }
}

s32 sub_803812C(struct unkStruct_203B480 *param_1, struct unkStruct_203B480 *param_2)
{
    if (sub_800D588() == 0) {
        param_2 = param_1;
    }
    if (HasMail(1, (param_2->unk10).unk10)) {
        return COMMS_GOOD;
    }
    else {
        return COMMS_NOT_ELIGIBLE_1;
    }
}

s32 sub_8038158(void *param_1, void *param_2)
{
    return COMMS_GOOD;
}

s32 sub_803815C(u32 mode, void *param_2, void *param_3)
{
    s32 linkStatus;

    linkStatus = COMMS_GOOD;
    switch(mode) {
        case 0:
        case 1:
            linkStatus = sub_8038014(param_2, param_3);
            break;
        case 7:
            linkStatus = sub_8038078(param_2, param_3);
            break;
        case 3:
            linkStatus = sub_80380C4(param_2, param_3);
            break;
        case 5:
            linkStatus = sub_803812C(param_2, param_3);
            break;
        case 10:
            linkStatus = sub_8038158(param_2, param_3);
            break;
    }
    return linkStatus;
}

void sub_80381DC(u32 mode, void * param_2, void * param_3)
{
    sub_8037F9C(mode, param_2, param_3);
}

s32 sub_80381E8(u32 mode, void * param_2, void * param_3)
{
    return sub_803815C(mode, param_2, param_3);
}

// TODO: clean this up
s32 sub_80381F4(u32 mode, void * param_2, void * param_3)
{
    u32 iVar2;
    s32 linkStatus;

    iVar2 = 0;
    linkStatus = sub_803815C(mode, param_2, param_3);
    gCommsTimeout = 0;
    sub_800D494();
    sub_800D59C(&linkStatus, 4);
    goto _first;
_start:
    while (iVar2 - 3 > 2) {
        if (99 < gCommsTimeout) {
            sub_800D520();
            sub_800D510();
            return COMMS_NOT_READY;
        }
        gCommsTimeout++;
    _first:
        sub_80373C4();
        iVar2 = sub_800D33C();
        sub_800D570();
        if (iVar2 == 2) {
            if (sub_800D600() != 0) {
                linkStatus = sub_8037DF0();
            }
            else {
                sub_800D520();
                sub_800D510();
                linkStatus = 5;
            }
            if (linkStatus != COMMS_GOOD) {
                sub_800D520();
                sub_800D510();
            }
            else {
                sub_8037F9C(mode, param_2, param_3);
            }
            goto _end;
        }
        else
            goto _start;
    }
    sub_800D520();
    sub_800D510();
    return 1;
_end:
    sub_800D520();
    return linkStatus;
}
