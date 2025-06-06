#include "global.h"
#include "globaldata.h"
#include "ground_map.h"
#include "text_1.h"
#include "memory.h"
#include "file_system.h"
#include "code_8002774.h"
#include "code_801D9E4.h"
#include "code_8004AA0.h"
#include "code_8009804.h"
#include "debug.h"
#include "bg_control.h"
#include "unk_dungeon_load.h"
#include "constants/dungeon.h"

extern const struct unkStruct_81188F0 gUnknown_81188F0[10];
extern const FileArchive gGroundFileArchive;

void sub_80A456C(unkStruct_3001B70 *mapPtr, s32 id, const PixelPos *srcPos);
static void sub_80A2DD4(unkStruct_3001B70 *mapPtr);
void sub_80A3BB0(unkStruct_3001B70 *mapPtr, s32 a0);
static void sub_80A3EB0(SubStruct_488 *map488);
static const u8 *sub_80A3908(u16 **dstArray, const void *src_, SubStruct_52C *a2, SubStruct_448 *a3);
static void sub_80A37C4(void *vramDst, const u16 *src_, SubStruct_52C *a2, SubStruct_545 *a3);
static void _UncompressCell(void * a0, u16 *a1, const void * a2, SubStruct_52C *a3, SubStruct_545 *a4);
static void sub_80A3D40(SubStruct_488 *map488, unkStruct_3001B70 *mapPtr, s32 a2, s32 a3, bool8 a4);
static void sub_80A3E14(SubStruct_488 *map488, PixelPos *a1);
static void sub_80A3EBC(SubStruct_488 *map488);
static void sub_80A3EF4(SubStruct_488 *map488);
static void sub_80A4088(SubStruct_488 *map488);
static void sub_80A41C4(SubStruct_488 *map488);
static void sub_80A3ED4(SubStruct_488 *map488);
static void sub_80A3F94(SubStruct_488 *map488);
static void sub_80A4358(SubStruct_488 *map488);

extern void sub_8003810(u16 param_1, struct S param_2);
extern void sub_809971C(u16 a0, const void *a1, int a2);

static const PixelPos sPositionZero = {0, 0};

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
    mapPtr->unk448.unk0 = 0;
    mapPtr->unk448.unk1 = 0;
    mapPtr->unk448.unk2 = 0;
    mapPtr->unk448.unk3 = 0;
    mapPtr->unk448.unk4 = 0;
    mapPtr->unk448.unk5 = 0;
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
        unkPtr->unk14 = 0;
        unkPtr->unk10 = 0;
        unkPtr->unk1C = 0;
        unkPtr->unk18 = 0;
        unkPtr->unk20 = 0;
        unkPtr->unk24 = 0;
    }

    for (i = 0; i < 2; i++) {
        sub_80A456C(mapPtr, i, &sPositionZero);
    }
}

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

void sub_80A2E64(unkStruct_3001B70 *mapPtr)
{
    u16 r6;
    s32 i, j;
    SubStruct_0 *unk0Ptr;
    s32 unk0Id, unk3E0Id;

    sub_80A2DD4(mapPtr);
    mapPtr->unk444 = -1;
    mapPtr->unk528 = 0;
    mapPtr->unk448.unk0 = 0;
    mapPtr->unk448.unk1 = 0;
    mapPtr->unk448.unk2 = 0;
    mapPtr->unk448.unk3 = 0;
    mapPtr->unk448.unk4 = 0;
    mapPtr->unk448.unk5 = 0;
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
        unkPtr->unk14 = 0;
        unkPtr->unk10 = 0;
        unkPtr->unk1C = 0;
        unkPtr->unk18 = 0;
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
    sub_80A3EB0(mapPtr->unk488);
    mapPtr->unk52A = 1;
}

void sub_80A2FBC(unkStruct_3001B70 *mapPtr, s32 a1_)
{
    SubStruct_0 *sub0Ptr;
    u16 r5;
    s32 i, j, k;
    const struct unkStruct_81188F0 *dataPtr;
    s16 *mapPtr_464;
    SubStruct_545 *mapPtr_454;
    const u16 *file_434;
    const void *file_438;
    const void *file_430;
    SubStruct_448 *mapPtr_448;
    struct S str2;
    struct S str1;
    const void *r7;
    s32 unk0Id;
    s32 id;
    void *vramPtr;
    s32 sum;
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
    file_430 = mapPtr->unk430->data;
    file_434 = mapPtr->unk434->data;
    file_438 = mapPtr->unk438->data;
    mapPtr_464 = mapPtr->unk464;
    mapPtr_454 = &mapPtr->unk454;
    mapPtr_448 = &mapPtr->unk448;

    mapPtr_464[0] = *(u8 *)(file_430); file_430 += 2;
    mapPtr_464[1] = *(u8 *)(file_430); file_430 += 2;

    mapPtr_454->unk0 = *file_434++;
    mapPtr_454->unk2 = *file_434++;
    mapPtr_454->unk4 = *file_434++;

    sum = mapPtr_454->unk4;
    for (k = 0; k < UNK_545_UNK6_ARR_COUNT; k++) {
        mapPtr_454->unk6[k] = *file_434++;
        sum += mapPtr_454->unk6[k];
    }
    mapPtr_454->unkE = *file_434++;

    mapPtr_448->unk0 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk1 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk2 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk3 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk4 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk5 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk6 = *(u8 *)(file_438); file_438 += 2;
    mapPtr_448->unk8 = *(u8 *)(file_438); file_438 += 2;
    mapPtr_448->unkA = *(u8 *)(file_438); file_438 += 2;

    r7 = file_430;
    r5 = mapPtr->unk52C.unk0 * 16;
    str2 = (struct S) {0};
    str1.x0.x0[0] = 0xff;
    str1.x0.x0[1] = 0xff;
    str1.x0.x0[2] = 0xff;
    str1.x0.x0[3] = 0;
    for (i = 0; i < mapPtr_464[0] && i < mapPtr->unk52C.unk2; i++) {
        sub_8003810(r5++, str2);
        sub_809971C(r5, r7, 15);
        r5 += 15;
        r7 += 60;
    }
    for (; i < mapPtr->unk52C.unk2; i++) {
        sub_8003810(r5++, str2);
        for (j = 0; j < 15; j++) {
            sub_8003810(r5++, str1);
        }
    }

    sub_80A37C4((void *)(VRAM + 0x8000 + mapPtr->unk52C.unk4 * 32), file_434, &mapPtr->unk52C, &mapPtr->unk454);
    _UncompressCell(mapPtr->unk548, &mapPtr->unk528, file_434 + ((mapPtr_454->unk4 - 1) * 16), &mapPtr->unk52C, &mapPtr->unk454);
    file_438 = sub_80A3908(mapPtr->unk54C, file_438, &mapPtr->unk52C, &mapPtr->unk448);
    mapPtr->unk468 = file_438;
    if (mapPtr->unk544 != NULL) {
        mapPtr->unk52C.unk14(mapPtr->unk544, file_438, mapPtr_448, mapPtr->unk52C.unkE);
    }

    sub0Ptr = mapPtr->unk0;
    unk0Id = 0;
    if (mapPtr_464[1] != 0) {
        const s16 *r3 = file_430 + (mapPtr_464[0] * 60);
        const void *r6 = &r3[mapPtr_464[0] * 2];

        mapPtr->unk46C = r3;
        mapPtr->unk470 = 1;
        mapPtr->unk471 = 1;
        for (; unk0Id < mapPtr_464[0] && unk0Id < mapPtr->unk52C.unk2; unk0Id++, sub0Ptr++, r3 += 2) {
            if (r3[1] > 0) {
                sub0Ptr->unk4 = r6;
                r6 += r3[1] * 60;
            }
            else {
                sub0Ptr->unk4 = NULL;
            }
            sub0Ptr->unk0 = 0;
            sub0Ptr->unk2 = 0;
            sub0Ptr->unk8 = 0;
        }
    }
    else {
        mapPtr->unk46C = NULL;
        mapPtr->unk470 = 0;
        mapPtr->unk471 = 0;
    }

    for (; unk0Id < UNK_0_ARR_COUNT; unk0Id++, sub0Ptr++) {
        sub0Ptr->unk0 = 0;
        sub0Ptr->unk2 = 0;
        sub0Ptr->unk4 = sub0Ptr->unk8 = 0;
    }

    vramPtr = (void *)(VRAM + 0x8000 + (mapPtr->unk52C.unk4 + mapPtr_454->unk4) * 32);
    for (id = 0; id < 2; id++) {
        SubStruct_3E0 *sub3E0 = &mapPtr->unk3E0[id];
        if (dataPtr->text4[id] != NULL) {
            const struct UnkFileStruct *fileStr;
            const void *r1, *r0;

            sub3E0->unk8 = OpenFileAndGetFileDataPtr(dataPtr->text4[id], &gGroundFileArchive);
            sub3E0->unk0 = 1;
            sub3E0->unk1 = 1;
            fileStr = sub3E0->unk8->data;
            sub3E0->unkC = fileStr;
            r1 = &fileStr->unk4;
            r0 = r1 + fileStr->unk2 * 4;
            sub3E0->unk10 = sub3E0->unk14 = r1;
            sub3E0->unk18 = sub3E0->unk1C = r0;
            sub3E0->unk2 = 0;
            sub3E0->unk4 = (u32) fileStr->unk4[0]; // ?
            sub3E0->unk20 = vramPtr;
            sub3E0->unk24 = mapPtr_454->unk6[id] * 32;

            vramPtr += mapPtr_454->unk6[id] * 32;
        }
        else {
            sub3E0->unk0 = 0;
            sub3E0->unk1 = 0;
            sub3E0->unk4 = 0;
            sub3E0->unk2 = 0;
            sub3E0->unk8 = NULL;
            sub3E0->unkC = 0;
            sub3E0->unk14 = 0;
            sub3E0->unk10 = 0;
            sub3E0->unk1C = 0;
            sub3E0->unk18 = 0;
            sub3E0->unk20 = 0;
            sub3E0->unk24 = 0;
        }
    }
    for (; id < 4; id++) {
        if (dataPtr->text4[id] != NULL) {
            s32 n;
            OpenedFile *file = OpenFileAndGetFileDataPtr(dataPtr->text4[id], &gGroundFileArchive);
            const struct UnkFileStruct *fileStr = file->data;
            u16 *r1 = (void *) fileStr->unk4;
            r1 += fileStr->unk2 * 2;

            n = mapPtr_454->unk6[id] * 16;
            for (k = 0; k < n; k++) {
                *(u16 *)(vramPtr) = *r1;
                r1++;
                vramPtr += 2;
            }
            CloseFile(file);
        }
    }

    sub_80A3BB0(mapPtr, 0);
    sub_80A3EB0(mapPtr->unk488);
    mapPtr->unk52A = 1;
}

void sub_80A3440(unkStruct_3001B70 *mapPtr, s32 a1_, DungeonLocation *dungLoc, s32 a3)
{
    SubStruct_0 *sub0Ptr;
    s32 i;
    SubStruct_545 *mapPtr_454;
    const u16 *file_434;
    const void *file_438;
    const void *file_430;
    SubStruct_448 *mapPtr_448;
    s32 unk0Id, sub3E0Id;
    const struct unkStruct_81188F0 *dataPtr;
    s16 *mapPtr_464;
    u16 *unkPtrArray[2];
    s32 a1 = (s16) a1_;

    if (a1 == -1 || dungLoc->id == DUNGEON_INVALID) {
        sub_80A2E64(mapPtr);
        return;
    }

    sub_80A2FBC(mapPtr, a1);
    sub_80A2DD4(mapPtr);
    mapPtr->unk444 = a1;
    dataPtr = &gUnknown_81188F0[a1];
    mapPtr->unk430 = OpenFileAndGetFileDataPtr(dataPtr->text1, &gGroundFileArchive);
    mapPtr->unk434 = OpenFileAndGetFileDataPtr(dataPtr->text2, &gGroundFileArchive);
    mapPtr->unk438 = OpenFileAndGetFileDataPtr(dataPtr->text3, &gGroundFileArchive);
    file_430 = mapPtr->unk430->data;
    file_434 = mapPtr->unk434->data;
    file_438 = mapPtr->unk438->data;
    mapPtr_464 = mapPtr->unk464;
    mapPtr_454 = &mapPtr->unk454;
    mapPtr_448 = &mapPtr->unk448;

    mapPtr_464[0] = *(u8 *)(file_430); file_430 += 2;
    mapPtr_464[1] = *(u8 *)(file_430); file_430 += 2;

    mapPtr_454->unk0 = *file_434++;
    mapPtr_454->unk2 = *file_434++;
    mapPtr_454->unk4 = *file_434++;

    for (i = 0; i < UNK_545_UNK6_ARR_COUNT; i++) {
        mapPtr_454->unk6[i] = *file_434++;
    }
    mapPtr_454->unkE = *file_434++;

    mapPtr_448->unk0 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk1 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk2 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk3 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk4 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk5 = *(u8 *)(file_438); file_438 += 1;
    mapPtr_448->unk6 = *(u8 *)(file_438); file_438 += 2;
    mapPtr_448->unk8 = *(u8 *)(file_438); file_438 += 2;
    mapPtr_448->unkA = *(u8 *)(file_438); file_438 += 2;

    unkPtrArray[0] = mapPtr->unk544;
    unkPtrArray[1] = NULL;
    file_438 = sub_80A3908(unkPtrArray, file_438, &mapPtr->unk52C, &mapPtr->unk448);
    mapPtr->unk468 = file_438;
    sub_80ADD9C(&mapPtr->unk43C, &mapPtr->unk440, (void *)(VRAM + 0x8000), mapPtr->unk548, mapPtr->unk54C[0], dungLoc, a3, 0x40, mapPtr_448->unk5, mapPtr->unk544, 0);
    // Unused return values
    GetFileDataPtr(mapPtr->unk43C, 0);
    GetFileDataPtr(mapPtr->unk440, 0);

    mapPtr->unk52C.unk14(mapPtr->unk544, file_438, mapPtr_448, mapPtr->unk52C.unkE);
    mapPtr_454->unk4 = 0x200;
    for (i = 0; i < UNK_545_UNK6_ARR_COUNT; i++) {
        mapPtr_454->unk6[i] = 0;
    }

    mapPtr_454->unkE = 250;
    mapPtr->unk464[0] = 12;
    mapPtr->unk464[1] = 0;
    if (mapPtr->unk43C != NULL) {
        s32 i, j;
        const struct S *strPtr = mapPtr->unk43C->data;
        u16 r7 = 0;
        struct S str0 = {0};
        struct S str1;

        str1.x0.x0[0] = 0xff;
        str1.x0.x0[1] = 0xff;
        str1.x0.x0[2] = 0xff;
        str1.x0.x0[3] = 0;

        for (i = 0; i < 12 && i < mapPtr->unk52C.unk2; i++) {
            sub_8003810(r7++, str0);
            strPtr++;
            for (j = 0; j < 15; j++) {
                struct S str2 = {strPtr->x0.x0[0], strPtr->x0.x0[1], strPtr->x0.x0[2], strPtr->x0.x0[3]};
                sub_8003810(r7++, str2);
                strPtr++;
            }
        }
        for (; i < mapPtr->unk52C.unk2; i++) {
            sub_8003810(r7++, str0);
            for (j = 0; j < 15; j++) {
                sub_8003810(r7++, str1);
            }
        }
    }

    sub0Ptr = mapPtr->unk0;
    if (mapPtr->unk440 != NULL) {
        sub_8004AA4(mapPtr->unkE0, mapPtr->unk440, UNK_E0_ARR_COUNT);
    }
    mapPtr->unk46C = NULL;
    mapPtr->unk470 = 0;
    mapPtr->unk471 = 0;

    for (unk0Id = 0; unk0Id < UNK_0_ARR_COUNT; unk0Id++, sub0Ptr++) {
        sub0Ptr->unk0 = 0;
        sub0Ptr->unk2 = 0;
        sub0Ptr->unk4 = sub0Ptr->unk8 = 0;
    }

    for (sub3E0Id = 0; sub3E0Id < UNK_3E0_ARR_COUNT; sub3E0Id++) {
        SubStruct_3E0 *sub3E0 = &mapPtr->unk3E0[sub3E0Id];
        sub3E0->unk0 = 0;
        sub3E0->unk1 = 0;
        sub3E0->unk4 = 0;
        sub3E0->unk2 = 0;
        sub3E0->unk8 = NULL;
        sub3E0->unkC = 0;
        sub3E0->unk14 = 0;
        sub3E0->unk10 = 0;
        sub3E0->unk1C = 0;
        sub3E0->unk18 = 0;
        sub3E0->unk20 = 0;
        sub3E0->unk24 = 0;
    }
    sub_80A3BB0(mapPtr, 0);
    sub_80A3EB0(mapPtr->unk488);
    mapPtr->unk52A = 1;
    // bad sp alloc for compiler generated variables...
    ASM_MATCH_TRICK(mapPtr_454->unk6[0]);
}

void sub_80A37C4(void *vramDst, const u16 *src_, SubStruct_52C *a2, SubStruct_545 *a3)
{
    const u16 *src = src_;
    u16 *dst = vramDst;
    s32 id, i;

    for (i = 0; i < 16; i++) {
        *dst++ = 0;
    }
    for (id = 1; id < a3->unk4; id++) {
        for (i = 0; i < 16; i++) {
            *dst++ = *src++;
        }
    }
    for (; id < a2->unk6; id++) {
        for (i = 0; i < 16; i++) {
            *dst++ = 0xFFFF;
        }
    }
}

static void _UncompressCell(void *dst_, u16 *a1, const void *src_, SubStruct_52C *a3, SubStruct_545 *a4)
{
    s32 id, i;
    s32 n;

    const u16 *src = src_;
    u16 *dst = dst_;
    u16 r6 = (a3->unk0 << 12) | a3->unk4;

    if (a4->unk0 == 2 && a4->unk2 == 2) {
        *a1 = 1;
        n = 4;
    }
    else if (a4->unk0 == 3 && a4->unk2 == 3) {
        *a1 = 2;
        n = 9;
    }
    else {
        *a1 = 0;
        FatalError(DEBUG_LOC_PTR("../ground/ground_bg.c", 1184, "_UncompressCell"), _("GroundBg cell type　error %d %d"), a4->unk0, a4->unk2);
    }

    for (i = 0; i < 9; i++) {
        *dst++ = 0;
    }
    for (id = 1; id < a4->unkE; id++) {
        for (i = 0; i < n; i++) {
            *dst++ = *src++ + r6;
        }
        for (; i < 9; i++) {
            *dst++ = 0;
        }
    }
    for (; id < a3->unk8; id++) {
        for (i = 0; i < 9; i++) {
            *dst++ = 0;
        }
    }
}

// Tilemap decompression algorhitm?
static const u8 *sub_80A3908(u16 **dstArray, const void *src_, SubStruct_52C *a2, SubStruct_448 *a3)
{
    s32 i, j, k, l;
    const u8 *src = src_;

    for (i = 0; i < a2->unkC; i++) {
        u16 *dst = dstArray[i];

        for (j = 0; j < a3->unk5; j++) {
            k = 0;
            if (j == 0) {
                while (k < a3->unk4) {
                    s32 val = *src++;
                    if (val > 191) {
                        for (l = 191; l < val; l++) {
                            s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                            *dst++ = dstVal & 0xFFF;
                            *dst++ = (dstVal >> 12) & 0xFFF;
                        }
                        k += (val - 191) * 2;
                    }
                    else if (val > 127) {
                        s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                        for (l = 127; l < val; l++) {
                            *dst++ = dstVal & 0xFFF;
                            *dst++ = (dstVal >> 12) & 0xFFF;
                        }
                        k += (val - 127) * 2;
                    }
                    else {
                        for (l = 0; l <= val; l++) {
                            *dst++ = 0;
                            *dst++ = 0;
                        }
                        k += (val + 1) * 2;
                    }
                }
            }
            else {
                u16 *ptrVal = dst - 64;
                while (k < a3->unk4) {
                    s32 val = *src++;
                    if (val > 191) {
                        for (l = 191; l < val; l++) {
                            s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                            *dst++ = (dstVal & 0xFFF) ^ *ptrVal++;
                            *dst++ = ((dstVal >> 12) & 0xFFF) ^ *ptrVal++;
                        }
                        k += (val - 191) * 2;
                    }
                    else if (val > 127) {
                        s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                        for (l = 127; l < val; l++) {
                            *dst++ = (dstVal & 0xFFF) ^ *ptrVal++;
                            *dst++ = ((dstVal >> 12) & 0xFFF) ^ *ptrVal++;
                        }
                        k += (val - 127) * 2;
                    }
                    else {
                        for (l = 0; l <= val; l++) {
                            *dst++ = *ptrVal++;
                            *dst++ = *ptrVal++;
                        }
                        k += (val + 1) * 2;
                    }
                }
            }

            for (; k < 64; k++) {
                *dst++ = 0;
            }
        }
        for (; j < a2->unk10; j++) {
            for (k = 0; k < 64; k++) {
                *dst++ = 0;
            }
        }
    }

    return src;
}

void sub_80A3B80(unkStruct_3001B70 *mapPtr, u8 a1, u8 a2)
{
    if (mapPtr->unk46C != NULL) {
        mapPtr->unk470 = a1;
        mapPtr->unk471 = a2;
    }
}

static const PixelPos sUnknownPosition = {96, 24};

void sub_80A3BB0(unkStruct_3001B70 *mapPtr, s32 a0_)
{
    s32 i;
    // s16 memes strike yet again
    s32 a0Match = (s16) a0_;
    s32 a0 = a0Match;

    SubStruct_488 *map488 = mapPtr->unk488;

    switch (a0) {
        default:
        case 0:
        case 1:
            mapPtr->unk474 = 1;
            sub_80A3D40(&map488[0], mapPtr, 0, mapPtr->unk52C.unkC, (a0 == 1));
            break;
        case 2:
        case 3:
        case 4:
            mapPtr->unk474 = 2;
            sub_80A3D40(&map488[0], mapPtr, 0, mapPtr->unk52C.unkC - 1, (a0 == 4));
            sub_80A3D40(&map488[1], mapPtr, mapPtr->unk52C.unkC - 1, 1, (a0 != 2));
            break;
    }

    for (i = 0; i < mapPtr->unk474; i++) {
        sub_80A456C(mapPtr, i, &sUnknownPosition);
        switch (map488[i].unk4) {
            default:
            case 1:
                switch (map488[i].unk0) {
                    default:
                    case 0:
                        map488[i].unk18 = sub_80A3EBC;
                        break;
                    case 1:
                        map488[i].unk18 = sub_80A3EF4;
                        break;
                    case 2:
                        map488[i].unk18 = (map488[i].unk6 != FALSE) ? sub_80A41C4 : sub_80A4088;
                        break;
                }
                break;
            case 2:
                switch (map488[i].unk0) {
                    default:
                    case 0:
                        map488[i].unk18 = sub_80A3ED4;
                        break;
                    case 1:
                        map488[i].unk18 = sub_80A3F94;
                        break;
                    case 2:
                        map488[i].unk18 = sub_80A4358;
                        break;
                }
                break;
        }
        sub_80A3E14(&map488[i], &mapPtr->unk478[i]);
    }
    for (i = mapPtr->unk474; i < UNK_54C_ARR_COUNT; i++) {
        sub_80A456C(mapPtr, i, &sUnknownPosition);
        sub_80A3D40(&map488[i], mapPtr, 0, 0, FALSE);
    }
}

static void sub_80A3D40(SubStruct_488 *map488, unkStruct_3001B70 *mapPtr, s32 a2, s32 a3, bool8 a4)
{
    s32 i, j;

    map488->unk0 = mapPtr->unk528;
    map488->unk2 = a2;
    map488->unk4 = a3;
    map488->unk6 = a4;
    map488->unk8 = mapPtr->unk448.unk4;
    map488->unkC = mapPtr->unk448.unk5;
    map488->unk10.x = mapPtr->unk448.unk0 * 8;
    map488->unk10.y = mapPtr->unk448.unk1 * 8;
    map488->unk1C = mapPtr->unk548;

    for (i = 0, j = a2; i < a3 && j < mapPtr->unk52C.unkC; i++, j++) {
        map488->unk20[i] = mapPtr->unk54C[j];
        map488->unk28[i] = mapPtr->unk554[j];
    }
    for (; i < UNK_54C_ARR_COUNT; i++) {
        map488->unk20[i] = NULL;
        map488->unk28[i] = NULL;
    }

    sub_80A3E14(map488, &mapPtr->unk478[0]);
}

void sub_80A3E14(SubStruct_488 *map488, PixelPos *a1)
{
    map488->unk30.x = a1->x;
    map488->unk38.x = map488->unk30.x / 8;
    map488->unk30.y = a1->y;
    map488->unk38.y = map488->unk30.y / 8;

    switch (map488->unk0) {
        case 0:
            map488->unk40.x = 0;
            map488->unk40.y = 0;
            map488->bgRegOffsets.x = 0;
            map488->bgRegOffsets.y = 0;
            break;
        case 1:
            map488->unk40.x = map488->unk38.x / 2;
            map488->unk40.y = map488->unk38.y / 2;
            map488->bgRegOffsets.x = map488->unk30.x % 16;
            map488->bgRegOffsets.y = map488->unk30.y % 16;
            break;
        case 2:
            map488->unk40.x = map488->unk38.x / 3;
            map488->unk40.y = map488->unk38.y / 3;
            map488->bgRegOffsets.x = map488->unk30.x % 8;
            map488->bgRegOffsets.y = map488->unk30.y % 24;
            break;
    }
}

static void sub_80A3EB0(SubStruct_488 *map488)
{
    map488->unk18(map488);
}

static void sub_80A3EBC(SubStruct_488 *map488)
{
    s32 i;
    u16 *dst = map488->unk28[0];

    for (i = 0; i < 1024; i++) {
        *dst++ = 0;
    }
}

static void sub_80A3ED4(SubStruct_488 *map488)
{
    s32 i;
    u16 *dst1 = map488->unk28[0];
    u16 *dst2 = map488->unk28[1];

    for (i = 0; i < 1024; i++) {
        *dst1++ = 0;
        *dst2++ = 0;
    }
}

static void sub_80A3EF4(SubStruct_488 *map488)
{
    s32 arrPtrId;
    s32 i, j;
    u16 *arrPtrs[2];
    u16 *ptr = &map488->unk20[0][(map488->unk40.y * 64) + map488->unk40.x];
    s32 unk28Id = 0;

    for (i = 0; i < 11; ptr += 64, i++) {
        u16 *currPtr = ptr;

        for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
            arrPtrs[arrPtrId] = &map488->unk28[0][unk28Id];
            unk28Id += 32;
        }

        for (j = 0; j < 16; j++) {
            u16 *currSrc = &map488->unk1C[*currPtr++ * 9];
            for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
                u16 *currDst = arrPtrs[arrPtrId];
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                arrPtrs[arrPtrId] = currDst;
            }
        }
    }
}

static void sub_80A3F94(SubStruct_488 *map488)
{
    s32 arrPtrId;
    u16 *ptr1, *ptr2;
    u16 *arrPtrs1[2];
    u16 *arrPtrs2[2];
    s32 unk28Id;
    s32 i, j;

    ptr1 = &map488->unk20[0][(map488->unk40.y * 64) + map488->unk40.x];
    ptr2 = &map488->unk20[1][(map488->unk40.y * 64) + map488->unk40.x];
    unk28Id = 0;
    for (i = 0; i < 11; ptr1 += 64, ptr2 += 64, i++) {
        u16 *currPtr1 = ptr1;
        u16 *currPtr2 = ptr2;

        for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
            arrPtrs1[arrPtrId] = &map488->unk28[0][unk28Id];
            arrPtrs2[arrPtrId] = &map488->unk28[1][unk28Id];
            unk28Id += 32;
        }

        for (j = 0; j < 16; j++) {
            u16 *currSrc1 = &map488->unk1C[*currPtr1++ * 9];
            u16 *currSrc2 = &map488->unk1C[*currPtr2++ * 9];
            for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
                u16 *currDst1 = arrPtrs1[arrPtrId];
                u16 *currDst2 = arrPtrs2[arrPtrId];
                *currDst1++ = *currSrc1++;
                *currDst1++ = *currSrc1++;
                *currDst2++ = *currSrc2++;
                *currDst2++ = *currSrc2++;
                arrPtrs1[arrPtrId] = currDst1;
                arrPtrs2[arrPtrId] = currDst2;
            }
        }
    }
}

static void sub_80A4088(SubStruct_488 *map488)
{
    s32 arrPtrId;
    s32 i, j;
    u16 *arrPtrs[3];
    s32 mod3 = map488->unk38.x % 3;
    u16 *ptr = &map488->unk20[0][(map488->unk40.y * 64) + map488->unk40.x];
    s32 unk28Id = 0;

    for (i = 0; i < 8; ptr += 64, i++) {
        u16 *currPtr = ptr;

        for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
            arrPtrs[arrPtrId] = &map488->unk28[0][unk28Id];
            unk28Id += 32;
        }

        if (mod3 != 0) {
            u16 *currSrc = &map488->unk1C[*currPtr++ * 9];

            if (mod3 == 1) {
                currSrc++;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = arrPtrs[arrPtrId];
                    *currDst++ = currSrc[0];
                    *currDst++ = currSrc[1];
                    arrPtrs[arrPtrId] = currDst;
                    currSrc += 3;
                }
            }
            else {
                currSrc += 2;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = arrPtrs[arrPtrId];
                    *currDst++ = currSrc[0];
                    arrPtrs[arrPtrId] = currDst;
                    currSrc += 3;
                }
            }
        }

        for (j = 0; j < 10; j++) {
            u16 *currSrc = &map488->unk1C[*currPtr++ * 9];
            for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                u16 *currDst = arrPtrs[arrPtrId];
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                arrPtrs[arrPtrId] = currDst;
            }
        }

        if (mod3 != 1) {
            u16 *currSrc = &map488->unk1C[*currPtr++ * 9];
            if (mod3 == 0) {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = arrPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currDst[1] = currSrc[1];
                    currSrc += 3;
                }
            }
            else {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = arrPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currSrc += 3;
                }
            }
        }
    }
}

static void sub_80A41C4(SubStruct_488 *map488)
{
    s32 mod3;
    s32 arrPtrId;
    u16 *ptr;
    u16 *arrPtrs[3];
    s32 unk28Id;
    s32 i, j;
    s32 sub1, sub2;

    // Screw you agbcc...
    ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);

    mod3 = map488->unk38.x % 3;
    ptr = &map488->unk20[0][(map488->unk40.y * 64) + map488->unk40.x];
    unk28Id = 0;
    sub1 = map488->unkC - map488->unk40.y;
    sub2 = map488->unk8 - map488->unk40.x;

    for (i = 0; i < 8; ptr += 64, i++) {
        u16 *currPtr;
        s32 currSub2 = sub2;

        if (sub1 > 0) {
            sub1--;
            currPtr = ptr;
        }
        else {
            sub1 = map488->unkC;
            ptr = &map488->unk20[0][map488->unk40.x];
            currPtr = ptr;
        }

        for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
            arrPtrs[arrPtrId] = &map488->unk28[0][unk28Id];
            unk28Id += 32;
        }

        if (mod3 != 0) {
            u16 *currSrc = &map488->unk1C[*currPtr++ * 9];

            if (mod3 == 1) {
                currSrc++;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = arrPtrs[arrPtrId];
                    *currDst++ = currSrc[0];
                    *currDst++ = currSrc[1];
                    arrPtrs[arrPtrId] = currDst;
                    currSrc += 3;
                }
            }
            else {
                currSrc += 2;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    *arrPtrs[arrPtrId]++ = *currSrc;
                    currSrc += 3;
                }
            }

            currSub2--;
            if (currSub2 <= 0) {
                currSub2 = map488->unk8;
                currPtr -= currSub2;
            }
        }

        for (j = 0; j < 10; j++) {
            u16 *currSrc = &map488->unk1C[*currPtr++ * 9];

            for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                u16 *currDst = arrPtrs[arrPtrId];
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                arrPtrs[arrPtrId] = currDst;
            }

            if (--currSub2 <= 0) {
                currSub2 = map488->unk8;
                currPtr -= currSub2;
            }
        }

        // Interestingly enough this part is NOT present in Blue...
        if (mod3 != 1) {
            u16 *currSrc = &map488->unk1C[*currPtr++ * 9];
            if (mod3 == 0) {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = arrPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currDst[1] = currSrc[1];
                    currSrc += 3;
                }
            }
            else {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = arrPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currSrc += 3;
                }
            }
        }
    }
}

static void sub_80A4358(SubStruct_488 *map488)
{
    s32 arrPtrId;
    s32 i, j;
    u16 *arrPtrs1[3];
    u16 *arrPtrs2[3];
    s32 mod3 = map488->unk38.x % 3;
    u16 *ptr1 = &map488->unk20[0][(map488->unk40.y * 64) + map488->unk40.x];
    u16 *ptr2 = &map488->unk20[1][(map488->unk40.y * 64) + map488->unk40.x];
    s32 unk28Id = 0;

    // Stack memes again...
    ASM_MATCH_TRICK(ptr2);ASM_MATCH_TRICK(ptr2);ASM_MATCH_TRICK(ptr2);

    for (i = 0; i < 8; ptr1 += 64, ptr2 += 64, i++) {
        u16 *currPtr1 = ptr1;
        u16 *currPtr2 = ptr2;

        for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
            arrPtrs1[arrPtrId] = &map488->unk28[0][unk28Id];
            arrPtrs2[arrPtrId] = &map488->unk28[1][unk28Id];
            unk28Id += 32;
        }

        if (mod3 != 0) {
            u16 *currSrc1 = &map488->unk1C[*currPtr1++ * 9];
            u16 *currSrc2 = &map488->unk1C[*currPtr2++ * 9];

            if (mod3 == 1) {
                currSrc1++;
                currSrc2++;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst1, *currDst2;
                    currDst1 = arrPtrs1[arrPtrId];
                    currDst2 = arrPtrs2[arrPtrId];
                    *currDst1++ = currSrc1[0];
                    *currDst1++ = currSrc1[1];
                    *currDst2++ = currSrc2[0];
                    *currDst2++ = currSrc2[1];
                    arrPtrs1[arrPtrId] = currDst1;
                    arrPtrs2[arrPtrId] = currDst2;
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
            else {
                currSrc1 += 2;
                currSrc2 += 2;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    *arrPtrs1[arrPtrId]++ = currSrc1[0];
                    *arrPtrs2[arrPtrId]++ = currSrc2[0];
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
        }

        for (j = 0; j < 10; j++) {
            u16 *currSrc1 = &map488->unk1C[*currPtr1++ * 9];
            u16 *currSrc2 = &map488->unk1C[*currPtr2++ * 9];
            for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                u16 *currDst1 = arrPtrs1[arrPtrId];
                u16 *currDst2 = arrPtrs2[arrPtrId];
                *currDst1++ = *currSrc1++;
                *currDst1++ = *currSrc1++;
                *currDst1++ = *currSrc1++;
                *currDst2++ = *currSrc2++;
                *currDst2++ = *currSrc2++;
                *currDst2++ = *currSrc2++;
                arrPtrs1[arrPtrId] = currDst1;
                arrPtrs2[arrPtrId] = currDst2;
            }
        }

        if (mod3 != 1) {
            u16 *currSrc1 = &map488->unk1C[*currPtr1++ * 9];
            u16 *currSrc2 = &map488->unk1C[*currPtr2++ * 9];
            if (mod3 == 0) {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst1 = arrPtrs1[arrPtrId];
                    u16 *currDst2 = arrPtrs2[arrPtrId];
                    currDst1[0] = currSrc1[0];
                    currDst1[1] = currSrc1[1];
                    currDst2[0] = currSrc2[0];
                    currDst2[1] = currSrc2[1];
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
            else {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst1, *currDst2;

                    currDst1 = arrPtrs1[arrPtrId];
                    currDst1[0] = currSrc1[0];
                    currDst2 = arrPtrs2[arrPtrId];
                    currDst2[0] = currSrc2[0];
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
        }
    }
}

void sub_80A4558(unkStruct_3001B70 *mapPtr, s32 id, PixelPos *dstPos)
{
    *dstPos = mapPtr->unk478[id];
}

void sub_80A456C(unkStruct_3001B70 *mapPtr, s32 id, const PixelPos *srcPos)
{
    mapPtr->unk478[id] = *srcPos;
}

void sub_80A4580(unkStruct_3001B70 *mapPtr, s32 id, PixelPos *pixPos)
{
    SubStruct_488 *map488 = &mapPtr->unk488[id];

    if (pixPos->x < 0) {
        if (map488->unk6) {
            do {
                pixPos->x += map488->unk10.x;
            } while (pixPos->x < 0);
        }
        else {
            pixPos->x = 0;
        }
    }
    else if (pixPos->x >= map488->unk10.x) {
        if (map488->unk6) {
            do {
                pixPos->x -= map488->unk10.x;
            } while (pixPos->x >= map488->unk10.x);
        }
        else {
            pixPos->x = map488->unk10.x - 1;
        }
    }

    if (pixPos->y < 0) {
        if (map488->unk6) {
            do {
                pixPos->y += map488->unk10.y;
            } while (pixPos->y < 0);
        }
        else {
            pixPos->y = 0;
        }
    }
    else if (pixPos->y >= map488->unk10.y) {
        if (map488->unk6) {
            do {
                pixPos->y -= map488->unk10.y;
            } while (pixPos->y >= map488->unk10.y);
        }
        else {
            pixPos->y = map488->unk10.y - 1;
        }
    }
}

void sub_80A4608(unkStruct_3001B70 *mapPtr, PixelPos *dstPos)
{
    dstPos->x = mapPtr->unk448.unk0;
    dstPos->y = mapPtr->unk448.unk1;
}

UNUSED static void sub_80A4620(unkStruct_3001B70 *mapPtr, PixelPos *dstPos)
{
    dstPos->x = mapPtr->unk448.unk0 * 8;
    dstPos->y = mapPtr->unk448.unk1 * 8;
}

void GetDungeonBounds(unkStruct_3001B70 *mapPtr, PixelPos *dstPos1, PixelPos *dstPos2)
{
    dstPos1->x = 0;
    dstPos1->y = 0;
    dstPos2->x = mapPtr->unk448.unk0 << 11;
    dstPos2->y = mapPtr->unk448.unk1 << 11;
}

u8 sub_80A4660(unkStruct_3001B70 *mapPtr, u8 bits, PixelPos *pixPos1, PixelPos *boundary)
{
    s32 i, j;
    u8 *currPtr;
    void *ptr = mapPtr->unk544;

    if (ptr == NULL)
        return 0;

    ptr += ((pixPos1->y * 256) + pixPos1->x + 0x405);
    for (i = boundary->y; i > 0; i--) {
        for (j = boundary->x, currPtr = ptr; j > 0; j--) {
            u8 ret = *currPtr++ & bits;
            if (ret)
                return ret;
        }
        ptr += 256;
    }

    return 0;
}

u8 sub_80A46C0(unkStruct_3001B70 *mapPtr, u8 bits, PixelPos *pixPos1, PixelPos *boundary)
{
    s32 i, j;
    u8 *currPtr;
    void *ptr = mapPtr->unk544;

    if (ptr == NULL)
        return 0;

    ptr += ((pixPos1->y * 256) + pixPos1->x + 0x405);
    for (i = boundary->y; i > 0; i--) {
        for (j = boundary->x, currPtr = ptr; j > 0; j--) {
            u8 ret = *currPtr++ & bits;
            if (ret != bits)
                return 0;
        }
        ptr += 256;
    }

    return 1;
}

u16 sub_80A4720(unkStruct_3001B70 *mapPtr, s32 id, PixelPos *pixPos)
{
    u16 *ptr = mapPtr->unk54C[id] + (pixPos->y * 64);
    ptr += pixPos->x;
    return *ptr;
}

void sub_80A4740(unkStruct_3001B70 *mapPtr, s32 id, PixelPos *pixPos, u32 dstVal)
{
    u16 *ptr = mapPtr->unk54C[id] + (pixPos->y * 64);
    ptr += pixPos->x;
    *ptr = dstVal;
}

void sub_80A4764(unkStruct_3001B70 *mapPtr)
{
    s32 i, j;
    s32 unk3E0Id;
    SubStruct_488 *map488;
    PixelPos *map478;

    if (mapPtr->unk444 == -1)
        return;

    if (mapPtr->unk464[1] != 0) {
        s32 i;
        SubStruct_0 *sub0Ptr = mapPtr->unk0;
        const u16 *ptr = mapPtr->unk46C;
        u16 r6 = mapPtr->unk52C.unk0 * 16;

        for (i = 0; i < mapPtr->unk464[0]; i++, sub0Ptr++, ptr += 2, r6 += 16) {
            if (sub0Ptr->unk4 != NULL && --sub0Ptr->unk2 <= 0) {
                if (--sub0Ptr->unk0 <= 0) {
                    if (mapPtr->unk471) {
                        sub0Ptr->unk2 = ptr[0];
                        sub0Ptr->unk0 = ptr[1];
                        sub0Ptr->unk8 = sub0Ptr->unk4;
                    }
                    else {
                        sub0Ptr->unk0 = 0;
                        sub0Ptr->unk2 = 0;
                        sub0Ptr->unk8 = NULL;
                    }
                }
                else {
                    sub0Ptr->unk2 = ptr[0];
                }

                if (sub0Ptr->unk8 != NULL) {
                    struct S empty = {0};
                    sub_8003810(r6, empty);
                    sub_809971C(r6 + 1, sub0Ptr->unk8, 15);
                    sub0Ptr->unk8 += 60;
                }
            }
        }

        mapPtr->unk471 = mapPtr->unk470;
    }
    else if (mapPtr->unk440 != NULL) {
        s32 i;
        unkStruct_202EE8C *unkE0Ptr = mapPtr->unkE0;
        s32 r6 = 160;

        for (i = 0; i < 32; i++, unkE0Ptr++, r6++) {
            struct S color;

            if (sub_8004D14(unkE0Ptr, 1) && !sub_8004D40(unkE0Ptr, 1) && --unkE0Ptr->unk6 <= 0) {
                unkE0Ptr->unk6 = unkE0Ptr->unk4;
                if (unkE0Ptr->unkC >= unkE0Ptr->unk10) {
                    unkE0Ptr->unkC = unkE0Ptr->unk8;
                }
                unkE0Ptr->unk14 = *unkE0Ptr->unkC++;
                color = (struct S) {unkE0Ptr->unk14.r, unkE0Ptr->unk14.g, unkE0Ptr->unk14.b, unkE0Ptr->unk14.unk4};
                sub_8003810(r6, color);
            }
        }
    }

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *sub3E0Ptr = &mapPtr->unk3E0[unk3E0Id];

        if (sub3E0Ptr->unk0 && sub3E0Ptr->unk4-- <= 0) {
            sub3E0Ptr->unk14 += 4;
            sub3E0Ptr->unk1C += (sub3E0Ptr->unk24 / 2) * 2;
            if (++sub3E0Ptr->unk2 >= sub3E0Ptr->unkC->unk2) {
                sub3E0Ptr->unk14 = sub3E0Ptr->unk10;
                sub3E0Ptr->unk1C = sub3E0Ptr->unk18;
                sub3E0Ptr->unk2 = 0;
            }
            sub3E0Ptr->unk1 = 1;
            sub3E0Ptr->unk4 = *(u32 *)(sub3E0Ptr->unk14);
        }
    }

    map488 = mapPtr->unk488;
    map478 = mapPtr->unk478;
    for (i = 0; i < mapPtr->unk474; i++, map488++, map478++) {
        s32 unk;

        sub_80A3E14(map488, map478);
        sub_80A3EB0(map488);
        for (j = 0, unk = map488->unk2 + mapPtr->unk52C.unkA; j < map488->unk4; j++, unk++) {
            switch (unk) {
                case 0:
                    SetBG2RegOffsets(map488->bgRegOffsets.x, map488->bgRegOffsets.y);
                    break;
                case 1:
                    SetBG3RegOffsets(map488->bgRegOffsets.x, map488->bgRegOffsets.y);
                    break;
            }
        }
    }

    mapPtr->unk52A = 1;
}

void sub_80A49E8(unkStruct_3001B70 *mapPtr)
{
    s32 i;
    s32 unk3E0Id;

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *sub3E0Ptr = &mapPtr->unk3E0[unk3E0Id];

        if (sub3E0Ptr->unk1) {
            MemoryCopy32(sub3E0Ptr->unk20, sub3E0Ptr->unk1C, sub3E0Ptr->unk24);
            sub3E0Ptr->unk1 = FALSE;
            mapPtr->unk52A = 1;
        }
    }

    if (mapPtr->unk52A) {
        s32 unk;
        for (i = 0, unk = mapPtr->unk52C.unkA; i < mapPtr->unk52C.unkC; i++, unk++) {
            sub_80098F8(unk + 2);
        }
        mapPtr->unk52A = 0;
    }
}
