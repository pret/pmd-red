#include "global.h"
#include "code_80130A8.h"
#include "item.h"
#include "kangaskhan_storage.h"
#include "kecleon_bros.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "team_inventory.h"
#include "text1.h"
#include "text2.h"

extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];
EWRAM_DATA_2 struct KangaskhanStorageWork *gKangaskhanStorageWork = {0};
EWRAM_DATA_2 struct unkStruct_203B20C *gUnknown_203B20C = {0};

extern const u8 *gUnknown_80D4920[];
extern const u8 *gUnknown_80D4928[];
extern const u8 *gUnknown_80D4934[];
extern const u8 *gUnknown_80D4958[];
extern const u8 *gUnknown_80D4964[];
extern const u8 *gUnknown_80D4970[];
extern const u8 *gUnknown_80D4984[];
extern struct UnkTextStruct2 gUnknown_80DB748;
extern struct UnkTextStruct2 gUnknown_80DB760;
extern struct UnkTextStruct2 gUnknown_80DB778;
extern struct UnkTextStruct2 gUnknown_80DB790;
extern const u8 gUnknown_80DB7A8[]; // "Number?\0"
extern struct UnkTextStruct2 gUnknown_80DB7B8;
extern struct UnkTextStruct2 gUnknown_80DB7D0;
extern struct UnkTextStruct2 gUnknown_80DB7E8;
extern struct UnkTextStruct2 gUnknown_80DB800;
extern struct UnkTextStruct2 gUnknown_80DB818;
extern const u8 gUnknown_80DB830[]; // "Number?\0"

extern const u8 *gKangaskhanStorageDialogue[2][20];

// code_801B3C0.c
extern void sub_801B3C0(struct Item *);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
extern void sub_801BB20(void);
extern void sub_801BC24(void);
// code_801C620.c
extern void sub_801C8C4(u32, u32, u32, u32);
extern u32 sub_801CA08(u32);
extern u8 sub_801CB24(void);
extern void sub_801CB5C(u32);
extern void sub_801CBB8(void);
extern void sub_801CCD8(void);
extern bool8 sub_801CF14(u32);
extern bool8 sub_801CF50(u32);
extern void sub_801CF94(void);
extern u32 sub_801CFB8(void);
extern u32 sub_801CFE0(u8);
// code_8098BDC.s
extern void sub_8099690(u32);

void sub_8016E80(void);
void sub_8016FF8(void);
void sub_8017598(void);
void sub_80175FC(void);
void sub_80176B8(void);
void sub_8017758(void);
void sub_80177F8(void);
void sub_8017828(void);
void sub_80178D0(void);
void sub_8017928(void);
void sub_80179A8(void);
void sub_8017A1C(void);
void sub_8017AF8(void);
void sub_8017B88(void);
void sub_8017C28(void);
void sub_8017C7C(void);
void sub_8017D24(void);
void sub_8017DC0(void);
void sub_8017DDC(void);
void sub_8017F10(u32);
void sub_8017F28(void);
void sub_8018100(void);
void sub_8018280(void);
void sub_80182E4(void);
void sub_801841C(void);
void sub_80184D4(void);
void sub_8018588(void);
void sub_8018620(void);
void sub_80186F8(void);
void sub_8018854(void);
void sub_8018904(void);
void sub_80189C8(void);
void sub_8018AC8(void);
void sub_8018AE4(void);

void AdvanceToKangaskhanStorageFallbackState(void);
void UpdateKangaskhanStorageState(u32);

u32 CreateKangaskhanStorage(bool32 isAsleep)
{
    char *monName;
    struct OpenedFile *faceFile;
    
    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
    gKangaskhanStorageWork = MemoryAlloc(sizeof(struct KangaskhanStorageWork), 8);
    gKangaskhanStorageWork->menuAction1 = 0;
    gKangaskhanStorageWork->menuAction2 = 0;
    gKangaskhanStorageWork->menuAction3 = 0;
    gKangaskhanStorageWork->isAsleep = isAsleep;
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KANGASKHAN);
    CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KANGASKHAN);
    monName = GetMonSpecies(MONSTER_KANGASKHAN);
    strcpy(gUnknown_202E1C8 - 0x50, monName);

    if (gKangaskhanStorageWork->isAsleep == TRUE)
        gKangaskhanStorageWork->unkE8 = NULL;
    else
        gKangaskhanStorageWork->unkE8 = &gKangaskhanStorageWork->faceFile;

    faceFile = GetDialogueSpriteDataPtr(MONSTER_KANGASKHAN);
    gKangaskhanStorageWork->faceFile = faceFile;
    gKangaskhanStorageWork->faceData = faceFile->data;
    gKangaskhanStorageWork->unkE4 = 0;
    gKangaskhanStorageWork->unkE5 = 0;
    gKangaskhanStorageWork->unkE6 = 0;
    gKangaskhanStorageWork->unkE0 = 2;
    gKangaskhanStorageWork->unkE2 = 8;
    UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_INIT);
    return 1;
}

u32 KangaskhanStorageCallback(void)
{
    switch (gKangaskhanStorageWork->currState) {
        case KANGASKHAN_STORAGE_INIT:
        case KANGASKHAN_STORAGE_MAIN_MENU:
            sub_8017828();
            break;
        case 13:
        case 14:
            sub_8017AF8();
            break;
        case 15:
            sub_8017C7C();
            break;
        case 16:
            sub_8017DC0();
            break;
        case 17:
            sub_80178D0();
            break;
        case 18:
            sub_80179A8();
            break;
        case 22:
        case 23:
            sub_8017B88();
            break;
        case 24:
            sub_8017C28();
            break;
        case 25:
            sub_8017D24();
            break;
        case 26:
            sub_8017DDC();
            break;
        case 27:
            sub_8017928();
            break;
        case 28:
            sub_8017A1C();
            break;
        case KANGASKHAN_STORAGE_EXIT:
            return 3;
        default:
            AdvanceToKangaskhanStorageFallbackState();
            break;
    }
    return 0;
}

void DeleteKangaskhanStorage(void)
{
    if (gKangaskhanStorageWork != NULL) {
        CloseFile(gKangaskhanStorageWork->faceFile);
        MemoryFree(gKangaskhanStorageWork);
        gKangaskhanStorageWork = NULL;
    }
}

void UpdateKangaskhanStorageState(u32 newState)
{
    gKangaskhanStorageWork->currState = newState;
    sub_8016E80();
    sub_8016FF8();
}

void sub_8016E80(void)
{
    s32 index;

    sub_8006518(gKangaskhanStorageWork->unkEC);

    switch (gKangaskhanStorageWork->currState) {
        case 13:
        case 14:
            gKangaskhanStorageWork->unkEC[0] = gUnknown_80DB748;
            gKangaskhanStorageWork->unkEC[1] = gUnknown_80DB748;
            gKangaskhanStorageWork->unkEC[2] = gUnknown_80DB748;
            gKangaskhanStorageWork->unkEC[0] = gUnknown_80DB748;
            break;
        case 22:
        case 23:
            gKangaskhanStorageWork->unkEC[0] = gUnknown_80DB748;
            gKangaskhanStorageWork->unkEC[1] = gUnknown_80DB748;
            gKangaskhanStorageWork->unkEC[2] = gUnknown_80DB748;
            gKangaskhanStorageWork->unkEC[0] = gUnknown_80DB778;
            break;
        case 24:
            gKangaskhanStorageWork->unkEC[1] = gUnknown_80DB790;
            break;
        case 15:
        case 25:
            gKangaskhanStorageWork->unkEC[2] = gUnknown_80DB760;
            break;
        default:
            for (index = 0; index < 4; index++)
                gKangaskhanStorageWork->unkEC[index] = gUnknown_80DB748;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(gKangaskhanStorageWork->unkEC, 1, 1);
}

void sub_8016FF8(void)
{
    switch (gKangaskhanStorageWork->currState) {
        case KANGASKHAN_STORAGE_INIT:
            sub_80175FC();
            gKangaskhanStorageWork->unkE4 = 1;
            sub_8014248(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][0], 0, gKangaskhanStorageWork->menuAction1, gKangaskhanStorageWork->unk24,
                                    gKangaskhanStorageWork->unk4C, 4, 0, gKangaskhanStorageWork->unkE8, 12);
            break;
        case KANGASKHAN_STORAGE_MAIN_MENU:
            sub_80175FC();
            gKangaskhanStorageWork->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][1], 0, gKangaskhanStorageWork->menuAction1, gKangaskhanStorageWork->unk24,
                                    gKangaskhanStorageWork->unk4C, 4, 0, gKangaskhanStorageWork->unkE8, 12);
            break;
        case 2:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][19], 0, gKangaskhanStorageWork->unkE8, 0x10D);
            break;
        case 3:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_EXIT;
            gKangaskhanStorageWork->unkE4 = 1;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][2], 0, gKangaskhanStorageWork->unkE8, 0x30D);
            break;
        case KANGASKHAN_STORAGE_NO_INV_ITEMS:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][13], 0, gKangaskhanStorageWork->unkE8, 0x10D);
            break;
        case KANGASKHAN_STORAGE_TOO_MANY_ITEMS:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][14], 0, gKangaskhanStorageWork->unkE8, 0x10D);
            break;
        case 7:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][15], 0, gKangaskhanStorageWork->unkE8, 0x10D);
            break;
        case 8:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][18], 0, gKangaskhanStorageWork->unkE8, 0x10D);
            break;
        case KANGASKHAN_STORAGE_IS_MONEY_USED_TM:
            sub_8090E14(gUnknown_202DE58, &gKangaskhanStorageWork->storedItem, 0);
            gKangaskhanStorageWork->fallbackState = 14;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][16], 0, gKangaskhanStorageWork->unkE8, 0x30D);
            break;
        case 10:
            gKangaskhanStorageWork->fallbackState = 14;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][17], 0, gKangaskhanStorageWork->unkE8, 0x30D);
            break;
        case 0xb:
            gKangaskhanStorageWork->fallbackState = 13;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][3], 0, gKangaskhanStorageWork->unkE8, 0x30D);
            break;
        case 12:
            gKangaskhanStorageWork->fallbackState = 14;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][4], 0, gKangaskhanStorageWork->unkE8, 0x30D);
            break;
        case 13:
            sub_801A5D8(3, 3, 0, 10);
            break;
        case 14:
            sub_801A8D0(1);
            break;
        case 15:
            sub_801A9E0();
            sub_80176B8();
            sub_8012D60(&gKangaskhanStorageWork->unk58, gKangaskhanStorageWork->unk24, NULL, gKangaskhanStorageWork->unk4C, gKangaskhanStorageWork->menuAction2, 2);
            break;
        case 17:
            sub_80177F8();
            sub_8090E14(gUnknown_202DE58, &gKangaskhanStorageWork->storedItem, 0);
            gKangaskhanStorageWork->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][5], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->unkE8, 12);
            break;
        case 18:
            sub_80177F8();
            gKangaskhanStorageWork->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][6], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->unkE8, 12);
            break;
        case 19:
            if (GetNumberOfFilledInventorySlots() == 0) {
                sub_801A928();
                gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            }
            else
                gKangaskhanStorageWork->fallbackState = 12;

            gKangaskhanStorageWork->unkE4 = 1;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][7], 0, gKangaskhanStorageWork->unkE8, 0x10D);
            break;
        case 20:
            gKangaskhanStorageWork->fallbackState = 22;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][8], 0, gKangaskhanStorageWork->unkE8, 0x30D);
            break;
        case 21:
            gKangaskhanStorageWork->fallbackState = 23;
            gKangaskhanStorageWork->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][9], 0, gKangaskhanStorageWork->unkE8, 0x30D);
            break;
        case 22:
            sub_801C8C4(1, 3, 0, 10);
            sub_801AD34(0);
            break;
        case 23:
            sub_801CB5C(1);
            sub_801AD34(0);
            break;
        case 24:
            gKangaskhanStorageWork->unkB8 = 2;
            gKangaskhanStorageWork->unkB0 = 1;

            if (gTeamInventoryRef->teamStorage[gKangaskhanStorageWork->storedItem.id] >= 100)
                gKangaskhanStorageWork->unkB4 = 99;
            else
                gKangaskhanStorageWork->unkB4 = gTeamInventoryRef->teamStorage [gKangaskhanStorageWork->storedItem.id];

            gKangaskhanStorageWork->unkAC = gKangaskhanStorageWork->unkB4;
            gKangaskhanStorageWork->unkBC = 1;
            gKangaskhanStorageWork->unkC0 = &gKangaskhanStorageWork->unkEC[1];
            gKangaskhanStorageWork->unkC4 = 40;
            gKangaskhanStorageWork->unkC8 = 18;
            sub_8013AA0(&gKangaskhanStorageWork->unkA8);
            sub_8017598();
            break;
        case 25:
            sub_801CCD8();
            sub_801AD34(0);
            sub_8017758();
            sub_8012D60(&gKangaskhanStorageWork->unk58, gKangaskhanStorageWork->unk24, NULL, gKangaskhanStorageWork->unk4C, gKangaskhanStorageWork->menuAction3, 2);
            break;
        case 16:
        case 26:
            sub_801B3C0(&gKangaskhanStorageWork->storedItem);
            break;
        case 27:
            sub_80177F8();
            sub_8090E14(gUnknown_202DE58, &gKangaskhanStorageWork->storedItem, 0);
            gKangaskhanStorageWork->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][10], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->unkE8, 12);
            break;
        case 28:
            sub_80177F8();
            gKangaskhanStorageWork->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][11], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->unkE8, 12);
            break;
        case 29:
            if (sub_801CF14(1) || GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                sub_801CBB8();
                gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            }
            else
                gKangaskhanStorageWork->fallbackState = 21;

            gKangaskhanStorageWork->unkE4 = 1;
            sub_80141B4(gKangaskhanStorageDialogue[gKangaskhanStorageWork->isAsleep][12], 0, gKangaskhanStorageWork->unkE8, 0x10D);
            break;
    }
}

void sub_8017598(void)
{
    sub_8008C54(gKangaskhanStorageWork->unkBC);
    sub_80073B8(gKangaskhanStorageWork->unkBC);
    xxx_call_draw_string(4, 0, gUnknown_80DB7A8, gKangaskhanStorageWork->unkBC, 0);
    sub_8013C68(&gKangaskhanStorageWork->unkA8);
    sub_80073E0(gKangaskhanStorageWork->unkBC);
    sub_801CCD8();
    sub_801AD34(0);
    sub_8012EA4(&gKangaskhanStorageWork->unk58, 0);
}

void sub_80175FC(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKangaskhanStorageWork->unk4C,0, sizeof(gKangaskhanStorageWork->unk4C));
    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4958;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 2;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4964;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 3;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4970;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 6;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4934;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 1;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            if (gKangaskhanStorageWork->unk24[index].menuAction == gKangaskhanStorageWork->menuAction1)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            gKangaskhanStorageWork->menuAction1 = gKangaskhanStorageWork->unk24[index].menuAction;
            break;
        }
    }
}

void sub_80176B8(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKangaskhanStorageWork->unk4C, 0, sizeof(gKangaskhanStorageWork->unk4C));
    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4958;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 2;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4970;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 6;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            if (gKangaskhanStorageWork->unk24[index].menuAction == gKangaskhanStorageWork->menuAction2)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            gKangaskhanStorageWork->menuAction2 = gKangaskhanStorageWork->unk24[index].menuAction;
            break;
        }
    }
}

void sub_8017758(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKangaskhanStorageWork->unk4C, 0, sizeof(gKangaskhanStorageWork->unk4C));
    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4964;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 3;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4970;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 6;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            if (gKangaskhanStorageWork->unk24[index].menuAction == gKangaskhanStorageWork->menuAction3)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            gKangaskhanStorageWork->menuAction3 = gKangaskhanStorageWork->unk24[index].menuAction;
            break;
        }
    }
}

void sub_80177F8(void)
{
    s32 loopMax;

    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4920;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 4;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = *gUnknown_80D4928;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 5;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = 1;
}

void sub_8017828(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    if (menuAction != 1)
        gKangaskhanStorageWork->menuAction1 = menuAction;

    switch (menuAction) {
        case 2:
            if (GetNumberOfFilledInventorySlots() == 0)
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_NO_INV_ITEMS);
            else if (sub_801CF50(0))
                UpdateKangaskhanStorageState(8);
            else
                UpdateKangaskhanStorageState(11);
            break;
        case 3:
            if (sub_801CF14(1))
                UpdateKangaskhanStorageState(7);
            else if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_TOO_MANY_ITEMS);
            else
                UpdateKangaskhanStorageState(20);
            break;
        case 6:
            UpdateKangaskhanStorageState(2);
            break;
        case 1:
            UpdateKangaskhanStorageState(3);
            break;
    }
}

void sub_80178D0(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    switch (menuAction) {
        case 4:
            MoveToStorage(&gKangaskhanStorageWork->storedItem);
            ShiftItemsDownFrom(gKangaskhanStorageWork->itemIndex);
            FillInventoryGaps();
            UpdateKangaskhanStorageState(19);
            break;
        case 1:
        case 5:
            UpdateKangaskhanStorageState(14);
            break;
    }
}

void sub_8017928(void)
{
    s32 menuAction;
    struct BulkItem item;

    if (sub_80144A4(&menuAction) != 0)
        return;

    switch (menuAction) {
        case 4:
            gTeamInventoryRef->teamStorage[gKangaskhanStorageWork->storedItem.id] -= gKangaskhanStorageWork->storedItem.quantity;
            item.id = gKangaskhanStorageWork->storedItem.id;
            item.quantity = gKangaskhanStorageWork->storedItem.quantity;
            AddHeldItemToInventory(&item);
            UpdateKangaskhanStorageState(29);
            break;
        case 1:
        case 5:
            UpdateKangaskhanStorageState(23);
            break;
    }
}

void sub_80179A8(void)
{
    s32 index;
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    switch (menuAction) {
        case 4:
            for (index = 0; index < INVENTORY_SIZE; index++) {
                if (sub_801AED0(index) != 0) {
                    MoveToStorage(&gTeamInventoryRef->teamItems[index]);
                    gTeamInventoryRef->teamItems[index].id = 0;
                    gTeamInventoryRef->teamItems[index].flags = 0;
                }
            }

            FillInventoryGaps();
            sub_801AE84();
            UpdateKangaskhanStorageState(19);
            break;
        case 1:
        case 5:
            UpdateKangaskhanStorageState(14);
            break;
    }
}

void sub_8017A1C(void)
{
    s32 itemID;
    int menuAction;
    struct BulkItem item;

    if (sub_80144A4(&menuAction) != 0)
        return;

    switch (menuAction) {
        case 4:
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
            UpdateKangaskhanStorageState(29);
            break;
        case 1:
        case 5:
            UpdateKangaskhanStorageState(23);
            break;
    }
}

void sub_8017AF8(void)
{
    switch (sub_801A6E8(TRUE)) {
        case 3:
            if (sub_801AEA8() != 0) {
                sub_8099690(0);
                UpdateKangaskhanStorageState(18);
            }
            else {
                gKangaskhanStorageWork->itemIndex = sub_801A8AC();
                gKangaskhanStorageWork->storedItem = gTeamInventoryRef->teamItems[gKangaskhanStorageWork->itemIndex];
                UpdateKangaskhanStorageState(15);
            }
            break;
        case 4:
            gKangaskhanStorageWork->itemIndex = sub_801A8AC();
            gKangaskhanStorageWork->storedItem = gTeamInventoryRef->teamItems[gKangaskhanStorageWork->itemIndex];
            UpdateKangaskhanStorageState(16);
            break;
        case 2:
            sub_801A928();
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_MAIN_MENU);
            break;
    }
}

void sub_8017B88(void)
{
    switch (sub_801CA08(1)) {
        case 3:
            if (sub_801CFB8() != 0)
                UpdateKangaskhanStorageState(28);
            else {
                gKangaskhanStorageWork->id = sub_801CB24();
                xxx_init_itemslot_8090A8C(&gKangaskhanStorageWork->storedItem, gKangaskhanStorageWork->id, 0);
                gKangaskhanStorageWork->storedItem.quantity = 1;
                UpdateKangaskhanStorageState(25);
            }
            break;
        case 4:
            gKangaskhanStorageWork->id = sub_801CB24();
            xxx_init_itemslot_8090A8C(&gKangaskhanStorageWork->storedItem, gKangaskhanStorageWork->id, 0);
            gKangaskhanStorageWork->storedItem.quantity = 1;
            UpdateKangaskhanStorageState(26);
            break;
        case 2:
            sub_801CBB8();
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_MAIN_MENU);
            break;
        case 1:
            sub_801AD34(0);
            break;
    }
}

void sub_8017C28(void)
{
    sub_801CA08(0);
    sub_8012FD8(&gKangaskhanStorageWork->unk58);

    switch (sub_8013BBC(&gKangaskhanStorageWork->unkA8)) {
        case 1:
            sub_8017598();
            break;
        case 3:
            gKangaskhanStorageWork->storedItem.quantity = gKangaskhanStorageWork->unkA8;
            UpdateKangaskhanStorageState(27);
            break;
        case 2:
            UpdateKangaskhanStorageState(23);
            break;
        case 0:
        default:
            break;
    }
}

void sub_8017C7C(void)
{
    s32 menuAction;
    menuAction = 0;

    sub_801A6E8(FALSE);
    if (sub_8012FD8(&gKangaskhanStorageWork->unk58) == 0) {
        sub_8013114(&gKangaskhanStorageWork->unk58, &menuAction);
        if (menuAction != 1)
            gKangaskhanStorageWork->menuAction2 = menuAction;
    }

    switch (menuAction) {
        case 2:
            sub_8099690(0);
            if (!IsNotMoneyOrUsedTMItem(gKangaskhanStorageWork->storedItem.id))
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_IS_MONEY_USED_TM);
            else if(!sub_801ADA0(gKangaskhanStorageWork->itemIndex))
                UpdateKangaskhanStorageState(10);
            else
                UpdateKangaskhanStorageState(17);
        break;
        case 6:
            sub_8099690(0);
            UpdateKangaskhanStorageState(16);
            break;
        case 1:
            UpdateKangaskhanStorageState(14);
            break;
    }
}

void sub_8017D24(void)
{
    s32 menuAction;
    menuAction = 0;

    sub_801CA08(0);
    if (sub_8012FD8(&gKangaskhanStorageWork->unk58) == 0) {
        sub_8013114(&gKangaskhanStorageWork->unk58, &menuAction);
        if (menuAction != 1)
            gKangaskhanStorageWork->menuAction3 = menuAction;
    }

    switch (menuAction) {
        case 3:
            if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                sub_801CBB8();
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_TOO_MANY_ITEMS);
            }
            else if (IsThrowableItem(gKangaskhanStorageWork->storedItem.id))
                UpdateKangaskhanStorageState(24);
            else
                UpdateKangaskhanStorageState(27);
            break;
        case 6:
            UpdateKangaskhanStorageState(26);
            break;
        case 1:
            UpdateKangaskhanStorageState(23);
            break;
    }
}

void sub_8017DC0(void)
{
    switch (sub_801B410()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(14);
            break;
    }
}

void sub_8017DDC(void)
{
    switch (sub_801B410()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(23);
            break;
    }
}

void AdvanceToKangaskhanStorageFallbackState(void)
{
    s32 temp;
    if (sub_80144A4(&temp) == 0)
        UpdateKangaskhanStorageState(gKangaskhanStorageWork->fallbackState);
}

u32 sub_8017E1C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    gUnknown_203B20C = MemoryAlloc(sizeof(struct unkStruct_203B20C), 8);
    gUnknown_203B20C->menuAction1 = 0;
    gUnknown_203B20C->menuAction2 = 0;
    gUnknown_203B20C->menuAction3 = 0;
    sub_8017F10(0);
    return 1;
}

u32 sub_8017E54(void)
{
    switch (gUnknown_203B20C->state) {
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
    if (gUnknown_203B20C != NULL) {
        MemoryFree(gUnknown_203B20C);
        gUnknown_203B20C = NULL;
    }
}

void sub_8017F10(u32 newState)
{
    gUnknown_203B20C->state = newState;
    sub_8017F28();
    sub_8018100();
}

void sub_8017F28(void)
{
    s32 index;

    sub_8006518(gUnknown_203B20C->unkF0);

    switch (gUnknown_203B20C->state) {
        case 1:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            sub_80182E4();
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7D0;
            sub_8012CAC(&gUnknown_203B20C->unkF0[2], gUnknown_203B20C->unk20);
            break;
        case 4:
        case 5:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            break;
        case 10:
        case 11:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB800;
            break;
        case 12:
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB818;
            break;
        case 6:
        case 13:
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7E8;
            break;
        default:
        case 0:
            for (index = 0; index < 4; index++)
                gUnknown_203B20C->unkF0[index] = gUnknown_80DB7B8;
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B20C->unkF0, 1, 1);
}

void sub_8018100(void)
{
    switch (gUnknown_203B20C->state) {
        case 1:
            sub_8012D60(&gUnknown_203B20C->unk70, gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->menuAction1, 2);
            break;
        case 4:
            sub_801A5D8(3, 3, 0, 10);
            break;
        case 5:
            sub_801A8D0(1);
            break;
        case 6:
            sub_801A9E0();
            sub_801841C();
            sub_8012D60(&gUnknown_203B20C->unk70, gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->menuAction2, 2);
            break;
        case 7:
            sub_801B3C0(&gUnknown_203B20C->item);
            break;
        case 10:
            sub_801C8C4(1, 3, 0, 10);
            sub_801AD34(0);
            break;
        case 11:
            sub_801CB5C(1);
            sub_801AD34(0);
            break;
        case 12:
            gUnknown_203B20C->unkD0 = 2;
            gUnknown_203B20C->unkC8 = 1;

            if (gTeamInventoryRef->teamStorage[gUnknown_203B20C->item.id] > 99)
                gUnknown_203B20C->unkCC = 99;
            else
                gUnknown_203B20C->unkCC = gTeamInventoryRef->teamStorage[gUnknown_203B20C->item.id];

            gUnknown_203B20C->unkC4 = gUnknown_203B20C->unkCC;
            gUnknown_203B20C->unkD4 = 1;
            gUnknown_203B20C->unkD8 = &gUnknown_203B20C->unkF0[1];
            gUnknown_203B20C->unkDC = 40;
            gUnknown_203B20C->unkE0 = 18;
            sub_8013AA0(&gUnknown_203B20C->unkC0);
            sub_8018280();
            break;
        case 13:
            sub_801CCD8();
            sub_801AD34(0);
            sub_80184D4();
            sub_8012D60(&gUnknown_203B20C->unk70, gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->menuAction3, 2);
            break;
        case 14:
            sub_801B3C0(&gUnknown_203B20C->item);
            break;
        case 0:
        default:
            break;
    }
}

void sub_8018280(void)
{
    sub_8008C54(gUnknown_203B20C->unkD4);
    sub_80073B8(gUnknown_203B20C->unkD4);
    xxx_call_draw_string(4, 0, gUnknown_80DB830, gUnknown_203B20C->unkD4, 0);
    sub_8013C68(&gUnknown_203B20C->unkC0);
    sub_80073E0(gUnknown_203B20C->unkD4);
    sub_801CCD8();
    sub_801AD34(0);
    sub_8012EA4(&gUnknown_203B20C->unk70, 0);
}

void sub_80182E4(void)
{
    int index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B20C->unk60, 0, sizeof(gUnknown_203B20C->unk60));
    gUnknown_203B20C->unk20[0].text = *gUnknown_80D4958;
    gUnknown_203B20C->unk20[0].menuAction = 2;

    if (GetNumberOfFilledInventorySlots() == 0 || sub_801CF50(0))
        gUnknown_203B20C->unk60[0] = 1;

    loopMax += 1;
    gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4964;
    gUnknown_203B20C->unk20[loopMax].menuAction = 3;

    if (sub_801CF14(1) || INVENTORY_SIZE <=  GetNumberOfFilledInventorySlots())
        gUnknown_203B20C->unk60[loopMax] = 1;

    loopMax += 1;
    gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4934;
    gUnknown_203B20C->unk20[loopMax].menuAction = 1;

    loopMax += 1;
    gUnknown_203B20C->unk20[loopMax].text = NULL;
    gUnknown_203B20C->unk20[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gUnknown_203B20C->unk60[index] == 0) {
            if (gUnknown_203B20C->unk20[index].menuAction == gUnknown_203B20C->menuAction1)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gUnknown_203B20C->unk60[index] == 0) {
            gUnknown_203B20C->menuAction1 = gUnknown_203B20C->unk20[index].menuAction;
            break;
        }
    }
}

void sub_801841C(void)
{
    int index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B20C->unk60,0,sizeof(gUnknown_203B20C->unk60));
    gUnknown_203B20C->unk20[0].text = *gUnknown_80D4958;
    gUnknown_203B20C->unk20[0].menuAction = 2;
    if (!sub_801ADA0(gUnknown_203B20C->itemIndex))
        gUnknown_203B20C->unk60[0] = 1;

    loopMax += 1;
    gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B20C->unk20[loopMax].menuAction = 4;

    loopMax += 1;
    gUnknown_203B20C->unk20[loopMax].text = NULL;
    gUnknown_203B20C->unk20[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gUnknown_203B20C->unk60[index] == 0) {
            if (gUnknown_203B20C->unk20[index].menuAction == gUnknown_203B20C->menuAction2)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gUnknown_203B20C->unk60[index] == 0) {
            gUnknown_203B20C->menuAction2 = gUnknown_203B20C->unk20[index].menuAction;
            break;
        }
    }
}

void sub_80184D4(void)
{
    int index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B20C->unk60, 0, sizeof(gUnknown_203B20C->unk60));
    gUnknown_203B20C->unk20[0].text = *gUnknown_80D4964;
    gUnknown_203B20C->unk20[0].menuAction = 3;

    if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
        gUnknown_203B20C->unk60[0] = 1;

    loopMax += 1;
    gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B20C->unk20[loopMax].menuAction = 4;

    loopMax += 1;
    gUnknown_203B20C->unk20[loopMax].text = NULL;
    gUnknown_203B20C->unk20[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gUnknown_203B20C->unk60[index] == 0) {
            if (gUnknown_203B20C->unk20[index].menuAction == gUnknown_203B20C->menuAction3)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gUnknown_203B20C->unk60[index] == 0) {
            gUnknown_203B20C->menuAction3 = gUnknown_203B20C->unk20[index].menuAction;
            break;
        }
    }
}

void sub_8018588(void)
{
    s32 menuAction;
    menuAction = 0;

    if (sub_8012FD8(&gUnknown_203B20C->unk70) == 0) {
        sub_8013114(&gUnknown_203B20C->unk70, &menuAction);
        if (menuAction != 1)
            gUnknown_203B20C->menuAction1 = menuAction;
    }

    switch (menuAction) {
        case 2:
            if (GetNumberOfFilledInventorySlots() != 0 && !sub_801CF50(0))
                sub_8017F10(4);
            else
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);
            break;
        case 3:
            if (sub_801CF14(1))
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);
            else
                sub_8017F10(10);
            break;
        case 1:
            sub_8017F10(3);
            break;
    }
}

void sub_8018620(void)
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
                gUnknown_203B20C->itemIndex = sub_801A8AC();
                gUnknown_203B20C->item = gTeamInventoryRef->teamItems[gUnknown_203B20C->itemIndex];
                sub_8017F10(6);
            }
            break;
        case 4:
            gUnknown_203B20C->itemIndex = sub_801A8AC();
            gUnknown_203B20C->item = gTeamInventoryRef->teamItems[gUnknown_203B20C->itemIndex];
            sub_8017F10(7);
            break;
        case 2:
            sub_801A928();
            sub_8017F10(1);
            break;
    }
}

void sub_80186F8(void)
{
    struct BulkItem item;
    s32 itemID;

    switch (sub_801CA08(1)) {
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
                gUnknown_203B20C->id = sub_801CB24();
                xxx_init_itemslot_8090A8C(&gUnknown_203B20C->item, gUnknown_203B20C->id, 0);
                gUnknown_203B20C->item.quantity = 1;
                sub_8017F10(13);
            }
            break;
        case 4:
            gUnknown_203B20C->id = sub_801CB24();
            xxx_init_itemslot_8090A8C(&gUnknown_203B20C->item, gUnknown_203B20C->id, 0);
            gUnknown_203B20C->item.quantity = 1;
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

void sub_8018854(void)
{
    struct BulkItem item;

    sub_801CA08(0);
    sub_8012FD8(&gUnknown_203B20C->unk70);

    switch (sub_8013BBC(&gUnknown_203B20C->unkC0)) {
        case 3:
            gUnknown_203B20C->item.quantity = gUnknown_203B20C->unkC0;
            gTeamInventoryRef->teamStorage[gUnknown_203B20C->item.id] -= gUnknown_203B20C->item.quantity;
            item.id = gUnknown_203B20C->item.id;
            item.quantity = gUnknown_203B20C->item.quantity;
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

void sub_8018904(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_801A6E8(FALSE);
    if (sub_8012FD8(&gUnknown_203B20C->unk70) == 0) {
        sub_8013114(&gUnknown_203B20C->unk70, &menuAction);
        if (menuAction != 1)
            gUnknown_203B20C->menuAction2 = menuAction;
    }

    switch (menuAction) {
        case 2:
            if (IsNotMoneyOrUsedTMItem(gUnknown_203B20C->item.id)) {
                if (sub_801ADA0(gUnknown_203B20C->itemIndex) == 0) {
                error:
                    sub_8012EA4(&gUnknown_203B20C->unk70, 1);
                }
                else {
                    MoveToStorage(&gUnknown_203B20C->item);
                    ShiftItemsDownFrom(gUnknown_203B20C->itemIndex);
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

void sub_80189C8(void)
{
    struct BulkItem item;
    s32 menuAction;

    menuAction = 0;

    sub_801CA08(0);
    if (sub_8012FD8(&gUnknown_203B20C->unk70) == 0) {
        sub_8013114(&gUnknown_203B20C->unk70, &menuAction);
        if (menuAction != 1)
            gUnknown_203B20C->menuAction3 = menuAction;
    }

    switch (menuAction) {
        case 3:
            if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);
            else if (IsThrowableItem(gUnknown_203B20C->item.id))
                sub_8017F10(12);
            else {
                gTeamInventoryRef->teamStorage[gUnknown_203B20C->item.id] -= gUnknown_203B20C->item.quantity;
                item.id = gUnknown_203B20C->item.id;
                item.quantity = gUnknown_203B20C->item.quantity;
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

void sub_8018AC8(void)
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

void sub_8018AE4(void)
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