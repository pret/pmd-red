#include "global.h"
#include "globaldata.h"
#include "unk_dungeon_load.h"
#include "memory.h"
#include "dungeon.h"
#include "decompress_at.h"
#include "def_filearchives.h"
#include "file_system.h"
#include "constants/dungeon.h"
#include "structs/dungeon_mapparam.h"

extern bool8 IsWaterDungeon(u32 r0);

extern const u8 gUnknown_8108EC0[];

static s32 sub_80ADFB8(s32 a0, s32 a1, s32 a2, s32 a3, u16 *a4, s32 a5, u8 *a6, s32 a7);

// This function is called when loading a transition between a dungeon and its summit, where the player can continue, save, or go back.
void sub_80ADD9C(OpenedFile **a0, OpenedFile **a1, u32 *a2, u32 *a3, u16 *a4, DungeonLocation *a5, s32 a6, s32 a7, s32 a8, u16 *a9, s32 unused)
{
    OpenedFile *file;
    s32 r8;
    s32 i, j;
    u8 name[12];
    DungeonLocation dungLoc;
    u8 dungId;
    s32 dungFloor;
    struct DungeonMapParam1 *strPtr;
    void *r10 = MemoryAlloc(0x930, 7);
    OpenedFile *mapParamFile = OpenFileAndGetFileDataPtr("mapparam", &gDungeonFileArchive);

    sub_80901D8(&dungLoc, a5);
    dungId = dungLoc.id;
    dungFloor = dungLoc.floor;
    if (dungId > 62) {
        dungId = 62;
    }

    if (dungFloor <= 0) {
        dungFloor = 1;
    }
    if (dungFloor >= GetDungeonFloorCount(dungId)) {
        dungFloor = GetDungeonFloorCount(dungId) - 1;
    }

    strPtr = &((struct DungeonMapParam2 *)(mapParamFile->data))->unk0[dungId][dungFloor];
    r8 = ((struct DungeonMapParam2 *)(mapParamFile->data))->unk4[strPtr->unk0].unk2;

    CloseFile(mapParamFile);

    sprintf(name, "b%02dfon", gUnknown_8108EC0[r8]);
    file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
    DecompressATGlobalFile(a2, 0, file);
    CloseFile(file);

    sprintf(name, "b%02dpal", r8);
    *a0 = OpenFile(name, &gDungeonFileArchive);

    sprintf(name, "b%02dcel", gUnknown_8108EC0[r8]);
    file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
    DecompressATFile(a3, 0x1194, file);
    CloseFile(file);

    if (r8 < 64) {
        sprintf(name, "b%02dcex", gUnknown_8108EC0[r8]);
        file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
        DecompressATFile(r10, 0x930, file);
        CloseFile(file);
    }
    else {
        sprintf(name, "b%02demap%01d", r8, a6);
        file = OpenFileAndGetFileDataPtr(name, &gDungeonFileArchive);
        DecompressATFile(r10, 0x240, file);
        CloseFile(file);
    }

    for (i = 0; i < a8; i++) {
        s32 r7 = !IsWaterDungeon(r8) ? 0 : 3;
        for (j = 0; j < a7; j++) {
            a4[(i * a7) + j] = sub_80ADFB8(j, i, a7, a8, a9, r7, r10, r8);
        }
    }

    sprintf(name, "b%02dcanm", r8);
    *a1 = OpenFile(name, &gDungeonFileArchive);
    MemoryFree(r10);
}

static s32 sub_80ADF8C(s32 a0, s32 a1, s32 a2, s32 a3, u16 *a4, s32 a5)
{
    s32 ret = a5;
    if (a0 >= 0 && a1 >= 0 && a0 < a2 && a1 < a3) {
        ret = a4[a0 + (a1 * a2)];
    }
    return ret;
}

static s32 sub_80ADFB8(s32 a0, s32 a1, s32 a2, s32 a3, u16 *a4, s32 a5, u8 *a6, s32 a7)
{
    s32 id;
    s32 offsets[8];
    u32 mask = 0;
    s32 baseResult = sub_80ADF8C(a0, a1, a2, a3, a4, a5);

    if (a7 >= 64) {
        if (a0 < 24 && a1 < 24) {
            id = a0 + (a1 * 24);
            return a6[id];
        }
        else {
            return a5;
        }
    }

    offsets[0] = sub_80ADF8C(a0 + 0, a1 + 1, a2, a3, a4, a5);
    offsets[1] = sub_80ADF8C(a0 + 1, a1 + 1, a2, a3, a4, a5);
    offsets[2] = sub_80ADF8C(a0 + 1, a1 + 0, a2, a3, a4, a5);
    offsets[3] = sub_80ADF8C(a0 + 1, a1 - 1, a2, a3, a4, a5);
    offsets[4] = sub_80ADF8C(a0 + 0, a1 - 1, a2, a3, a4, a5);
    offsets[5] = sub_80ADF8C(a0 - 1, a1 - 1, a2, a3, a4, a5);
    offsets[6] = sub_80ADF8C(a0 - 1, a1 + 0, a2, a3, a4, a5);
    offsets[7] = sub_80ADF8C(a0 - 1, a1 + 1, a2, a3, a4, a5);
    if (baseResult == 1) {
        mask = 0xFF;
        if (offsets[0] == 0) mask &= ~0x01;
        if (offsets[1] == 0) mask &= ~0x02;
        if (offsets[2] == 0) mask &= ~0x04;
        if (offsets[3] == 0) mask &= ~0x08;
        if (offsets[4] == 0) mask &= ~0x10;
        if (offsets[5] == 0) mask &= ~0x20;
        if (offsets[6] == 0) mask &= ~0x40;
        if (offsets[7] == 0) mask &= ~0x80;
        mask |= 0x200;
    }
    else if (baseResult == 2) {
        mask = 0xFF;
        if (offsets[0] != 2) mask &= ~0x01;
        if (offsets[1] != 2) mask &= ~0x02;
        if (offsets[2] != 2) mask &= ~0x04;
        if (offsets[3] != 2) mask &= ~0x08;
        if (offsets[4] != 2) mask &= ~0x10;
        if (offsets[5] != 2) mask &= ~0x20;
        if (offsets[6] != 2) mask &= ~0x40;
        if (offsets[7] != 2) mask &= ~0x80;
        mask |= 0x100;
    }
    else if (baseResult == 3) {
        mask = 0xFF;
        if (offsets[0] != 3) mask &= ~0x01;
        if (offsets[1] != 3) mask &= ~0x02;
        if (offsets[2] != 3) mask &= ~0x04;
        if (offsets[3] != 3) mask &= ~0x08;
        if (offsets[4] != 3) mask &= ~0x10;
        if (offsets[5] != 3) mask &= ~0x20;
        if (offsets[6] != 3) mask &= ~0x40;
        if (offsets[7] != 3) mask &= ~0x80;
        mask |= 0x100;
    }
    else {
        mask = 0;
        if (offsets[0] == 0) mask |= 0x01;
        if (offsets[1] == 0) mask |= 0x02;
        if (offsets[2] == 0) mask |= 0x04;
        if (offsets[3] == 0) mask |= 0x08;
        if (offsets[4] == 0) mask |= 0x10;
        if (offsets[5] == 0) mask |= 0x20;
        if (offsets[6] == 0) mask |= 0x40;
        if (offsets[7] == 0) mask |= 0x80;
    }

    id = mask * 3;
    return a6[id];
}
