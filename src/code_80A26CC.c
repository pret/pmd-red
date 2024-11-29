#include "global.h"
#include "code_80972F4.h"
#include "code_80A26CC.h"
#include "event_flag.h"
#include "ground_main.h"

// data_8115F5C.s
extern const DungeonInfo gUnknown_81168A8[];
extern const s16 gUnknown_8116F24[];
extern const s16 gUnknown_8116F9A[];
extern const u8 *gUnknown_8117000[];

// code_80972F4.h (read comment)
extern bool8 sub_8097384(s16);
extern bool8 RescueScenarioConquered(s16);

// code_8098BDC.s
extern void sub_809AB4C(s32, s32);
extern void sub_809ABB4(s32, s32);
extern void sub_809AC18(s32, s32);

s16 sub_80A8BBC(s16);

void sub_80A2500(s32 param_1, s16 *param_2)
{
    s16 temp;
    if (*param_2 == 1) {
        temp = param_1;
        sub_809AB4C(temp, sub_80A8BBC(param_2[1]));
    }
}

void sub_80A252C(s32 param_1, s16 *param_2)
{
    s16 temp;
    if (*param_2 == 1) {
        temp = param_1;
        sub_809ABB4(temp, sub_80A8BBC(param_2[1]));
    }
}

void sub_80A2558(s32 param_1, s16 *param_2)
{
    s16 temp;
    if (*param_2 == 1) {
        temp = param_1;
        sub_809AC18(temp, sub_80A8BBC(param_2[1]));
    }
}

void sub_80A2584(s16 r0, s16 r1)
{
    s32 iVar2 = r1;
    s32 iVar1 = r0;
    sub_809ABB4(iVar1, iVar2);
}

void sub_80A2598(s16 r0, s16 r1)
{
    s32 iVar2 = r1;
    s32 iVar1 = r0;
    sub_809AC18(iVar1, iVar2);
}

u32 sub_80A25AC(u16 param_1)
{
    if (sub_8098F88())
        return param_1;
    if (param_1 == 50)
        return 50;
    if (!sub_80023E4(12))
        return 999;
    if (sub_80023E4(13))
        return 19;
    if (param_1 != 1)
        return param_1;
    GetScriptVarValue(NULL, BASE_LEVEL); // wut???
    return 1;
}

const DungeonInfo *GetDungeonInfo_80A2608(s32 _index)
{
    s32 index = (s16) _index;
    return &gUnknown_81168A8[index];
}

const DungeonInfo *sub_80A2620(s16 index)
{
    u32 temp;
    temp = sub_80A26B8(index);
    return &gUnknown_81168A8[temp];
}

UNUSED static s16 sub_80A2644(u32 index)
{
    return gUnknown_8116F24[index];
}

s16 sub_80A2654(s16 index)
{
    const DungeonInfo *temp;

    temp = GetDungeonInfo_80A2608(index);
    return temp->unkE;
}

// This is very ugly
s16 sub_80A2668(u32 r0)
{
    u32 temp;
    temp = 0xFFC90000 + (r0 << 16);
    if (temp >> 16 < 0x19)
        return ((s32)temp >> 16);

    return -1;
}

s16 sub_80A2688(u8 r0)
{
    u32 uVar1;

    uVar1 = r0 - 75;

    // u8 cast is needed for only this compare
    if ((u8)uVar1 < 23)
        return uVar1;
    if (r0 == 47)
        return 23;
    if (r0 == 48)
        return 24;
    return -1;
}

s16 sub_80A26B8(s16 r0)
{
    // Useless cast that forces correct ordering
    s32 temp;

    temp = r0;

    return gUnknown_8116F9A[r0];
}

s16 sub_80A26CC(s16 r0)
{
    return 55 + r0;
}

UNUSED static s16 sub_80A26D8(u8 index)
{
    s32 i;
    s16 counter2;
    const DungeonInfo *temp;

    for (i = 0; i < 83; i++) {
        counter2 = i;
        temp = GetDungeonInfo_80A2608(counter2);

        if (temp->unk11 != 0) {
            if (temp->dungeonIndex == index)
                return counter2;
        }
    }
    return -1;
}

u8 sub_80A270C(s16 index)
{
    const DungeonInfo *temp;
    s32 index_s32;

    index_s32 = index; // forcing a shift before addressing
    temp = GetDungeonInfo_80A2608(gUnknown_8116F9A[index_s32]);
    return temp->dungeonIndex;
}

u8 sub_80A2728(s16 index)
{
    const DungeonInfo *temp;

    s16 temp_number = 55 + index;
    temp = GetDungeonInfo_80A2608(temp_number);
    return temp->dungeonIndex;
}

u8 sub_80A2740(s32 index)
{
    const DungeonInfo *temp;

    temp = GetDungeonInfo_80A2608((s16) index);
    return temp->dungeonIndex;
}

s16 sub_80A2750(s16 r0)
{
    const DungeonInfo *temp;
    s32 temp_32;
    s32 temp_2;

    // so dumb but it matches
    temp_32 = r0;
    temp_2 = temp_32;

    if (r0 == 80)
        return 3;
    if (r0 == 81)
        return 2;
    if (r0 == 82)
        return 4;
    if ((u16)(r0 - 40) <= 14)
        return 2;
    if ((u16)(r0 - 55) <= 24)
        return 4;

    temp = GetDungeonInfo_80A2608(temp_2);
    if (temp->unkE == -1)
        return 1;
    if (sub_80023E4(5))
        return 1;
    if (!RescueScenarioConquered(temp->unkE))
        return 1;
    if (!sub_80023E4(1))
        return 1;
    return 2;
}

bool8 sub_80A27CC(s16 r0)
{
    s32 temp;
    s32 temp2;
    const DungeonInfo *t;

    // Same dumbness as above to get a match
    temp2 = r0;
    temp = temp2;

    t = sub_80A2620(r0);
    if (t->unk0 == -1)
        return FALSE;
    if (sub_80023E4(5))
        return FALSE;
    if (sub_8097384(r0))
        return TRUE;
    if (!sub_80023E4(1))
        return FALSE;
    if (!RescueScenarioConquered(temp))
        return FALSE;
    return TRUE;
}

bool8 sub_80A2824(u8 index)
{
    s32 i;
    const DungeonInfo *temp;

    if (sub_80023E4(5))
        return FALSE;

    if (sub_80023E4(1)) {
        for (i = 0; i < 46; i++) {
            temp = sub_80A2620(i);

            if (temp->unk11 != 0) {
                if (temp->dungeonIndex == index) {
                    if (sub_8097384(i))
                        return TRUE;
                    if (RescueScenarioConquered(i))
                        return TRUE;
                }
            }
        }
    }
    else {
        for (i = 0; i < 46; i++) {
            temp = sub_80A2620(i);

            if (temp->unk11 != 0)
                if (temp->dungeonIndex == index)
                    if (sub_8097384(i))
                        return TRUE;
        }
    }

    return FALSE;
}

UNUSED static bool8 sub_80A28B4(s16 r0)
{
    const DungeonInfo *temp;

    temp = sub_80A2620(r0);

    if (temp->unk0 != -1) {
        if (!sub_8097384(r0) && !RescueScenarioConquered(r0))
            return FALSE;
        else
            return TRUE;
    }

    return FALSE;
}

bool8 sub_80A28F0(u8 index)
{
    s32 counter;
    const DungeonInfo *temp;

    for (counter = 0; counter < 0x2E; counter++) {
        temp = sub_80A2620(counter);

        if (temp->unk11 != 0) {
            if (temp->dungeonIndex == index) {
                if (sub_8097384(counter))
                    return TRUE;
                if (RescueScenarioConquered(counter))
                    return TRUE;
            }
        }
    }

    return FALSE;
}

UNUSED static s32 sub_80A293C(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 local_68[64];
    u8 zero;

    counter = 0;
    zero = 0;

    pcVar2 = &local_68[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((int)pcVar2 >= (int)local_68);


    for (index = 0; index < 46; index++) {
        iVar3 = sub_80A2620(index);
        if (iVar3->unk11 != 0 && sub_8097384(index))
            local_68[iVar3->dungeonIndex] = 1;
    }

    for (index = 0; index < 63; index++) {
        if (local_68[index] != 0) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}

s32 sub_80A29B0(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 *local1;
    u8 *local2;
    u8 *local3;
    u8 *local4;
    u8 local_68[0x40];
    u8 zero;

    counter = 0;
    local1 = &local_68[43];
    local2 = &local_68[44];
    local3 = &local_68[45];
    local4 = &local_68[46];
    zero = 0;

    pcVar2 = &local_68[62];
    do {
        *pcVar2 = zero;
        pcVar2 = pcVar2 + -1;
    } while ((int)pcVar2 >= (int)local_68);


    if (sub_80023E4(1)) {
        for (index = 0; index < 46; index++) {
            iVar3 = sub_80A2620(index);

            if (iVar3->unk11 != 0 && RescueScenarioConquered(index))
                local_68[iVar3->dungeonIndex] = 1;
        }
    }

    *local1 = 0;
    *local2 = 0;
    *local3 = 0;
    *local4 = 0;

    for (index = 0; index < 63; index++) {
        if (local_68[index] != 0) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}

UNUSED static s32 sub_80A2A5C(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 local_58[0x40];
    u8 zero;

    counter = 0;
    zero = 0;

    pcVar2 = &local_58[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((s32)pcVar2 >= (s32)local_58);

    if (sub_80023E4(1)) {
        for (index = 0; index < 46; index++) {
            iVar3 = sub_80A2620(index);

            if (iVar3->unk11 != 0 && (sub_8097384(index) || RescueScenarioConquered(index)))
                local_58[iVar3->dungeonIndex] = 1;
        }
    }
    else {
        for (index = 0; index < 46; index++) {
            iVar3 = sub_80A2620(index);

            if (iVar3->unk11 != 0 && sub_8097384(index))
                local_58[iVar3->dungeonIndex] = 1;
        }
    }

    for (index = 0; index < 63; index++) {
        if (local_58[index] != 0) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}

// Returns Location string for the pause menu
const u8 *sub_80A2B18(s16 param_1)
{
    s32 param_1_s32 = param_1;
    return gUnknown_8117000[param_1_s32];
}

UNUSED static const u8 *sub_80A2B28(u16 r0)
{
    return sub_80A2B18(GetScriptVarValue(NULL, GROUND_PLACE));
}
