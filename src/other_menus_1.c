#include "global.h"
#include "constants/communication_error_codes.h"
#include "dungeon_global_data.h"
#include "pokemon.h"
#include "code_8094F88.h"
#include "save.h"
#include "team_inventory.h"
#include "main_menu.h"

extern s32 gCommsTimeout; // Counts to 100 and then errors if other player hasn't connected
extern s32 sub_803815C(u32, void *, void*);
extern void sub_800D494(void);
extern s32 sub_800D33C(void);
extern void sub_800D520(void);
extern u8 sub_800D600(void);
extern void sub_80373C4(void);
extern void sub_800D59C(s32 *, u32);
extern void sub_800D570(void);
extern void sub_800D510(void);
extern s32 sub_8037DF0(void);
extern void sub_8037F9C(u32, u8 *, u8 *);

extern u8 sub_800D588(void);
extern struct UnkStruct_203B184 *gUnknown_203B184;

s32 sub_8038014(struct unkStruct_8035D94 *param_1,struct unkStruct_8035D94 *param_2)
{
  s32 linkStatus;
  s32 r2;
  struct unkStruct_8035D94 *r3;
  struct unkStruct_8035D94 *r4;

  if (sub_800D588() == 0) {
    r4 = param_2;
  }
  else
  {
    r4 = param_1;      
  }

  if (sub_800D588() == 0) {
    r3 = param_1;
  }
  else
  {
    r3 = param_2;      
  }
    
  if ((r4->itemIndex).itemIndex_u8 == (r3->itemIndex).itemIndex_u8) {
    r2 = gTeamInventory_203B460->teamStorage[r4->itemIndex.itemIndex_u8];
    r2 += r3->numItems;
    if (r2 > 999) {
        linkStatus = COMMS_NO_ROOM_STORAGE;
    }
    else
        linkStatus = COMMS_GOOD;
  }
  else {
    r2 = gTeamInventory_203B460->teamStorage[r3->itemIndex.itemIndex_u8];
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
