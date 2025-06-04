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

u8 sub_80A2740(s16 index)
{
    const DungeonInfo *temp;
    s32 index_s32;

    index_s32 = index;

    temp = GetDungeonInfo_80A2608(index_s32);
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
    if (!RescueScenarioConquered((s16) temp->unkE))
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
    if (!RescueScenarioConquered((s16) temp))
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
                    if (sub_8097384((s16) i))
                        return TRUE;
                    if (RescueScenarioConquered((s16) i))
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
                    if (sub_8097384((s16) i))
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
                if (sub_8097384((s16) counter))
                    return TRUE;
                if (RescueScenarioConquered((s16) counter))
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
        if (iVar3->unk11 != 0 && sub_8097384((s16) index))
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

            if (iVar3->unk11 != 0 && RescueScenarioConquered((s16) index))
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

            if (iVar3->unk11 != 0 && (sub_8097384((s16) index) || RescueScenarioConquered((s16) index)))
                local_58[iVar3->dungeonIndex] = 1;
        }
    }
    else {
        for (index = 0; index < 46; index++) {
            iVar3 = sub_80A2620(index);

            if (iVar3->unk11 != 0 && sub_8097384((s16) index))
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

// TODO: Figure out if a new file starts here

#include "ground_map.h"
#include "text_1.h"
#include "memory.h"
#include "file_system.h"
#include "code_8002774.h"
#include "code_801D9E4.h"

extern void sub_80A456C(unkStruct_3001B70 *, u32, const PixelPos *);
extern const PixelPos gUnknown_81172B8;

void sub_80A2B40(unkStruct_3001B70 *mapPtr, const SubStruct_52C *a1)
{
    SubStruct_0 *unk0Ptr;
    s32 id, unk0Id, unk3E0Id;
    s32 i;

    mapPtr->unk52C = *a1;
    mapPtr->unk548 = MemoryAlloc(mapPtr->unk52C.unk8 * 18, 6);
    for (id = 0; id < mapPtr->unk52C.unkC; id++) {
        mapPtr->unk554[id] = &gBgTilemaps[2 + mapPtr->unk52C.unkA + id][0][0];
        mapPtr->unk54C[id] = MemoryAlloc(mapPtr->unk52C.unk10 * 128, 6);
    }
    for (; id < UNK_54C_ARR_COUNT; id++) {
        mapPtr->unk554[id] = NULL;
        mapPtr->unk54C[id] = NULL;
    }

    if (mapPtr->unk52C.unk14 != NULL) {
        mapPtr->unk544 = MemoryAlloc(mapPtr->unk52C.unkE * 256, 6);
    }
    else {
        mapPtr->unk544 = NULL;
    }

    mapPtr->unk430 = NULL;
    mapPtr->unk434 = NULL;
    mapPtr->unk438 = NULL;
    mapPtr->unk43C = NULL;
    mapPtr->unk440 = NULL;
    mapPtr->unk52A = 0;
    mapPtr->unk444 = -1;
    mapPtr->unk468 = 0;
    mapPtr->unk448 = 0;
    mapPtr->unk449 = 0;
    mapPtr->unk44A = 0;
    mapPtr->unk44B = 0;
    mapPtr->unk44C = 0;
    mapPtr->unk44D = 0;
    unk0Ptr = &mapPtr->unk0[0];
    mapPtr->unk46C = 0;
    mapPtr->unk470 = 0;
    mapPtr->unk471 = 0;

    for (unk0Id = 0; unk0Id < UNK_0_ARR_COUNT; unk0Id++, unk0Ptr++) {
        unk0Ptr->unk0 = 0;
        unk0Ptr->unk2 = 0;
        unk0Ptr->unk8 = 0;
        unk0Ptr->unk4 = 0;
    }

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *unkPtr = &mapPtr->unk3E0[unk3E0Id];
        unkPtr->unk0 = 0;
        unkPtr->unk1 = 0;
        unkPtr->unk2 = 0;
        unkPtr->unk4 = 0;
        unkPtr->unk8 = NULL;
        unkPtr->unkC = 0;
        unkPtr->unk12 = 0;
        unkPtr->unk10 = 0;
        unkPtr->unk1C = 0;
        unkPtr->unk14 = 0;
        unkPtr->unk20 = 0;
        unkPtr->unk24 = 0;
    }

    for (i = 0; i < 2; i++) {
        sub_80A456C(mapPtr, i, &gUnknown_81172B8);
    }
}

void sub_80A2DD4(unkStruct_3001B70 *mapPtr);
void sub_80A3BB0(unkStruct_3001B70 *mapPtr, s32 a0);
void sub_80A3EB0(SubStruct_488 *mapSubstructPtr);

void sub_80A2D00(unkStruct_3001B70 *mapPtr)
{
    s32 i;

    sub_80A2DD4(mapPtr);
    TRY_FREE_AND_SET_NULL(mapPtr->unk544);
    FREE_AND_SET_NULL(mapPtr->unk548);

    for (i = 0; i < UNK_54C_ARR_COUNT; i++) {
        if (mapPtr->unk554[i] != NULL) {
            mapPtr->unk554[i] = NULL;
        }
        TRY_FREE_AND_SET_NULL(mapPtr->unk54C[i]);
    }
}

void sub_80A2D68(unkStruct_3001B70 *mapPtr)
{
    TRY_FREE_AND_SET_NULL(mapPtr->unk544);
}

void sub_80A2D88(unkStruct_3001B70 *mapPtr)
{
    if (mapPtr->unk52C.unk14 != NULL) {
        void *unk448 = &mapPtr->unk448;
        mapPtr->unk544 = MemoryAlloc(mapPtr->unk52C.unkE * 256, 6);
        mapPtr->unk52C.unk14(mapPtr->unk544, mapPtr->unk468, unk448, mapPtr->unk52C.unkE);
    }
}

void sub_80A2DD4(unkStruct_3001B70 *mapPtr)
{
    s32 i;

    for (i = 0; i < UNK_3E0_ARR_COUNT; i++) {
        SubStruct_3E0 *unkPtr = &mapPtr->unk3E0[i];
        TRY_CLOSE_FILE_AND_SET_NULL(unkPtr->unk8);
    }
    TRY_CLOSE_FILE_AND_SET_NULL(mapPtr->unk43C);
    TRY_CLOSE_FILE_AND_SET_NULL(mapPtr->unk440);
    TRY_CLOSE_FILE_AND_SET_NULL(mapPtr->unk430);
    TRY_CLOSE_FILE_AND_SET_NULL(mapPtr->unk434);
    TRY_CLOSE_FILE_AND_SET_NULL(mapPtr->unk438);
}

extern void sub_8003810(u32 param_1, struct S param_2);

void sub_80A2E64(unkStruct_3001B70 *mapPtr)
{
    u16 r6;
    s32 i, j;
    SubStruct_0 *unk0Ptr;
    s32 unk0Id, unk3E0Id;

    sub_80A2DD4(mapPtr);
    mapPtr->unk444 = -1;
    mapPtr->unk528 = 0;
    mapPtr->unk448 = 0;
    mapPtr->unk449 = 0;
    mapPtr->unk44A = 0;
    mapPtr->unk44B = 0;
    mapPtr->unk44C = 0;
    mapPtr->unk44D = 0;
    unk0Ptr = &mapPtr->unk0[0];
    mapPtr->unk46C = 0;
    mapPtr->unk470 = 0;
    mapPtr->unk471 = 0;

    for (unk0Id = 0; unk0Id < UNK_0_ARR_COUNT; unk0Id++, unk0Ptr++) {
        unk0Ptr->unk0 = 0;
        unk0Ptr->unk2 = 0;
        unk0Ptr->unk8 = 0;
        unk0Ptr->unk4 = 0;
    }

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *unkPtr = &mapPtr->unk3E0[unk3E0Id];
        unkPtr->unk0 = 0;
        unkPtr->unk1 = 0;
        unkPtr->unk2 = 0;
        unkPtr->unk4 = 0;
        unkPtr->unk8 = NULL;
        unkPtr->unkC = 0;
        unkPtr->unk12 = 0;
        unkPtr->unk10 = 0;
        unkPtr->unk1C = 0;
        unkPtr->unk14 = 0;
        unkPtr->unk20 = 0;
        unkPtr->unk24 = 0;
    }

    r6 = mapPtr->unk52C.unk0 * 16;
    for (i = 0; i < mapPtr->unk52C.unk2; i++) {
        struct S str1 = {0};
        struct S str2 = {0xFF, 0xFF, 0xFF, 0};

        sub_8003810(r6++, str1);
        for (j = 0; j < 15; j++) {
            sub_8003810(r6++, str2);
        }
    }

    sub_80A3BB0(mapPtr, 0);
    sub_80A3EB0(&mapPtr->unk488);
    mapPtr->unk52A = 1;
}

extern const struct unkStruct_81188F0 gUnknown_81188F0[10];
extern const FileArchive gGroundFileArchive;

/*
void sub_80A2FBC(unkStruct_3001B70 *mapPtr, s32 a1_)
{
    const struct unkStruct_81188F0 *dataPtr;
    s32 a1 = (s16) a1_;

    if (a1 == -1) {
        sub_80A2E64(mapPtr);
        return;
    }

    sub_80A2DD4(mapPtr);
    mapPtr->unk444 = a1;
    dataPtr = &gUnknown_81188F0[a1];
    mapPtr->unk430 = OpenFileAndGetFileDataPtr(dataPtr->text1, &gGroundFileArchive);
    mapPtr->unk434 = OpenFileAndGetFileDataPtr(dataPtr->text2, &gGroundFileArchive);
    mapPtr->unk438 = OpenFileAndGetFileDataPtr(dataPtr->text3, &gGroundFileArchive);
}
*/

//
