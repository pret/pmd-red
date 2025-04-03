#include "global.h"
#include "constants/dungeon.h"
#include "structs/str_202ED28.h"
#include "structs/str_202EDE8.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "code_800D090.h"
#include "code_803D110.h"
#include "code_803E46C.h"
#include "cpu.h"
#include "def_filearchives.h"
#include "dungeon.h"
#include "dungeon_random.h"
#include "file_system.h"
#include "game_options.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text_1.h"
#include "text_3.h"
#include "dungeon_config.h"

extern s32 sub_80902C8(u8 dungeon);
extern void sub_808E9C4(UnkDungeonGlobal_unk1CD98 *r0, s16 r1);

extern const char gUnknown_80F4D8C[]; // "mapparam"

struct UnkDungeonFileData
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6[5];
};

struct UnkDataFileStruct
{
    struct UnkDungeonFileData **unk0;
    FloorProperties *unk4;
    u16 **unk8;
    UnkDungeonGlobal_unk1CD98 **unkC;
    u16 **unk10;
};

void sub_803D4AC(void)
{
    gDungeon->unk1C570.id = 0x63;
    gDungeon->unk1C570.floor = 0xFF;
}

void sub_803D4D0(void)
{
    s16 spArray[NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS];
    s32 i, j, k;
    OpenedFile *file;
    struct UnkDungeonFileData *strPtr;

    sub_80901D8(&gDungeon->unk644.dungeonLocation2, &gDungeon->unk644.dungeonLocation);
    if (gDungeon->unk1C570.id == gDungeon->unk644.dungeonLocation2.id && gDungeon->unk1C570.floor == gDungeon->unk644.dungeonLocation2.floor)
        return;

    gDungeon->unk1C570 = gDungeon->unk644.dungeonLocation2;
    file = OpenFileAndGetFileDataPtr(gUnknown_80F4D8C, &gDungeonFileArchive);
    strPtr = &((struct UnkDataFileStruct *)(file->data))->unk0[gDungeon->unk1C570.id][gDungeon->unk1C570.floor];

    gDungeon->unk1CEC8 = GetDungeonFloorCount(gDungeon->unk644.dungeonLocation.id);
    gDungeon->unk14 = sub_80902C8(gDungeon->unk644.dungeonLocation.id);

    gDungeon->floorProperties = ((struct UnkDataFileStruct *)(file->data))->unk4[strPtr->unk0];

    for (i = 0; i < 20; i++) {
        gDungeon->unk1CD70[i] = ((struct UnkDataFileStruct *)(file->data))->unk10[strPtr->unk4][i];
    }
    for (i = 0; i < 31; i++) {
        gDungeon->unk1CD98[i] = ((struct UnkDataFileStruct *)(file->data))->unkC[strPtr->unk2][i];
        if (ExtractSpeciesIndex(&gDungeon->unk1CD98[i]) == 0)
            break;
    }
    while (i <= 31) {
        sub_808E9C4(&gDungeon->unk1CD98[i], 0);
        i++;
    }

    for (i = 0; i < 4; i++)
    {
        u16 *src = ((struct UnkDataFileStruct *)(file->data))->unk8[strPtr->unk6[i]];
        s32 arrId = 0;

        for (j = 0; j < NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS; ) {
            if (src[arrId] >= 30000) {
                for (k = src[arrId] - 30000; k != 0; k--) {
                    spArray[j++] = 0;
                }
            }
            else {
                spArray[j++] = src[arrId];
            }
            arrId++;
        }

        arrId = 0;
        for (j = 0; j < NUM_ITEM_CATEGORIES; j++) {
            gDungeon->itemSpawns[i].categoryValues[arrId] = spArray[arrId];
            arrId++;
        }

        for (j = 0; j < NUMBER_OF_ITEM_IDS; j++) {
            gDungeon->itemSpawns[i].itemValues[j] = spArray[arrId];
            arrId++;
        }
    }

    CloseFile(file);
}

u8 sub_803D6FC(void)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);
    for (i = 0; i < 20; i++) {
        if (gDungeon->unk1CD70[i] != 0 && gDungeon->unk1CD70[i] >= rand)
            return i;
    }

    return 16;
}

u8 GetRandomFloorItem(s32 spawnType)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);
    u8 category = NUM_ITEM_CATEGORIES;
    for (i = 0; i < NUM_ITEM_CATEGORIES; i++) {
        if (gDungeon->itemSpawns[spawnType].categoryValues[i] != 0 && gDungeon->itemSpawns[spawnType].categoryValues[i] >= rand) {
            category = i;
            break;
        }
    }
    if (category == NUM_ITEM_CATEGORIES)
        return ITEM_POKE;

    rand = DungeonRandInt(10000);
    for (i = 0; i < NUMBER_OF_ITEM_IDS; i++) {
        if (gDungeon->itemSpawns[spawnType].itemValues[i] != 0 && GetItemCategory(i) == category && gDungeon->itemSpawns[spawnType].itemValues[i] >= rand) {
            return i;
        }
    }

    return ITEM_POKE;
}

s32 sub_803D808(UnkDungeonGlobal_unk1CD98 *strPtr, s32 id)
{
    s32 i;

    for (i = 0; i < 32; i++) {
        if (ExtractSpeciesIndex(&gDungeon->unk1CD98[i]) == 0)
            break;
        strPtr[id] = gDungeon->unk1CD98[i];
        id++;
    }

    return id;
}

s32 sub_803D870(UnkDungeonGlobal_unk1CD98 *strPtr, s32 id)
{
    s32 i;

    for (i = 0; i < 32; i++) {
        s16 species = ExtractSpeciesIndex(&gDungeon->unk1CD98[i]);
        if (species == 0)
            break;
        if (GetBodySize(species) < 2 && gDungeon->unk1CD98[i].unk2[0] != 0) {
            strPtr[id] = gDungeon->unk1CD98[i];
            id++;
        }
    }

    return id;
}

void sub_803D8F0(void)
{
    if (gDungeon->unk37EC == 0) {
        gDungeon->unk37EC = 1;
        gDungeon->unk37E4 = sub_803D808(gDungeon->unk343C, 0);
    }
}

bool8 sub_803D930(s16 speciesToFind)
{
    s32 i;
    s32 id = SpeciesId(speciesToFind);

    for (i = 0; i < 32; i++) {
        s16 species = ExtractSpeciesIndex(&gDungeon->unk1CD98[i]);
        if (species == 0)
            break;
        if (species == id)
            return TRUE;
    }
    return FALSE;
}

s16 sub_803D970(s32 arrId)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);

    for (i = 0; i < gDungeon->unk37E4; i++) {
        if (gDungeon->unk343C[i].unk2[arrId] != 0 && gDungeon->unk343C[i].unk2[arrId] >= rand) {
            return ExtractSpeciesIndex(&gDungeon->unk343C[i]);
        }
    }
    for (i = 0; i < gDungeon->unk37E4; i++) {
        if (gDungeon->unk343C[i].unk2[arrId] != 0) {
            return ExtractSpeciesIndex(&gDungeon->unk343C[i]);
        }
    }

    return MONSTER_KECLEON;
}

s32 sub_803DA20(s32 species)
{
    s32 i;
    s32 speciesId = SpeciesId(species);

    for (i = 0; i < gDungeon->unk37E4; i++) {
        if (ExtractSpeciesIndex(&gDungeon->unk343C[i]) == speciesId)
            return ExtractLevel(&gDungeon->unk343C[i]);
    }
    return 1;
}
