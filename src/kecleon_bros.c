#include "global.h"
#include "code_800D090.h"
#include "constants/input.h"
#include "felicity_bank.h"
#include "kecleon_bros.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "team_inventory.h"

extern struct KecleonBrosWork *gKecleonBrosWork;
extern struct unkStruct_203B214 *gUnknown_203B214;
extern u16 gUnknown_203B218;
extern struct unkStruct_203B214 *gUnknown_203B21C;
extern u16 gUnknown_203B220;
extern struct unkStruct_203B224 *gUnknown_203B224;
extern u16 gUnknown_203B228;
extern u16 gUnknown_203B22A;
extern u32 gUnknown_202DE30;
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];

extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 *gUnknown_80D4934[];
extern u8 *gUnknown_80D4970[];
extern u8 * gUnknown_80D4978[];
extern u8 *gUnknown_80D4984[];
extern struct UnkTextStruct2 gUnknown_80DB840;
extern struct UnkTextStruct2 gUnknown_80DB858;
extern struct UnkTextStruct2 gUnknown_80DB870;
extern struct UnkTextStruct2 gUnknown_80DB888;
extern u8 gUnknown_80DB8A0[];
extern struct UnkTextStruct2 gUnknown_80DB8B4;
extern struct UnkTextStruct2 gUnknown_80DB8CC;
extern u8 gUnknown_80DB8E4[];
extern u8 gUnknown_80DB8EC[];
extern struct UnkTextStruct2 gUnknown_80DB8FC;
extern const struct UnkTextStruct2 gUnknown_80DB914;
extern u8 gUnknown_80DB92C[];
extern u8 gUnknown_80DB934[];
extern struct UnkTextStruct2 gUnknown_80DB944;
extern struct UnkTextStruct2 gUnknown_80DB95C;
extern u8 gUnknown_80DB994[];
extern u8 gUnknown_80DB9A0[];
extern u8 gUnknown_80DB9A8[];
extern u8 gUnknown_80DB9B0[];

extern const u8 *gKecleonShopDialogue[KECLEON_BROS_MODE_COUNT][23];
extern const u8 gTeamToolboxA[];
extern const u8 gTeamToolboxB[];

// text.s
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void sub_8007B7C(s32, s32, s32, s32, s32);
extern void sub_8008C54(u32);
// code_80130A8.s
extern void sub_80141B4(const u8 *, u32, struct OpenedFile **, u32);
extern void sub_8014248(const u8 *, u32, u32, const struct MenuItem *, void *, u32, u32, struct OpenedFile **, u32);
extern s32 sub_80144A4(s32 *);
// code_801B3C0.c
extern u32 sub_801B3C0(struct Item *);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
// code_8098BDC.s
extern void sub_8099690(u32);

// code_80118A4.c
extern void PlayMenuSoundEffect(u32);
extern void PlaySound(u16 songIndex);
// code_80130A8.s
extern void xxx_format_and_draw(u32, u32, u8 *, u32, u32);

void sub_8018D30(void);
void sub_80194F8(void);
void sub_80195C0(void);
void sub_8019660(void);
void sub_8019700(void);
void sub_8019730(void);
void sub_8019850(void);
void sub_80198E8(void);
void sub_8019944(void);
void sub_80199CC(void);
void sub_8019B08(void);
void sub_8019BBC(void);
void sub_8019C78(void);
void sub_8019D30(void);
void sub_8019D4C(void);
void sub_8019D68(void);
void sub_8019DAC(void);
void sub_8019E04(bool32);
u32 sub_8019E40(u32);
u32 sub_8019EDC(u8);
u8 sub_8019FB0(void);
void sub_8019FCC(u8);
void sub_801A010(void);
void sub_801A064(void);
void sub_801A0D8(void);
u32 sub_801A20C(u32);
u32 sub_801A2A8(u8);
u8 sub_801A37C(void);
void sub_801A398(u8);
void sub_801A3DC(void);
void sub_801A430(void);
void sub_801A4A4(void);
void sub_801A998(void);
s32 sub_801AE24(u32);

u32 CountKecleonItems(void);
void Kecleon_SortItems(void);
void KecleonBros_SetState(u32);
void UpdateKecleonStoreDialogue(void);

u32 KecleonBros_New(u32 mode)
{
    char *monName;
    struct OpenedFile *faceFile;

    gKecleonBrosWork = MemoryAlloc(sizeof(struct KecleonBrosWork), 8);
    gKecleonBrosWork->menuAction1 = 0;
    gKecleonBrosWork->menuAction2 = 0;
    gKecleonBrosWork->menuAction3 = 0;
    gKecleonBrosWork->mode = mode;

    switch (mode) {
        case KECLEON_BROS_MODE_ITEMS_AWAKE:
            gKecleonBrosWork->isKecleonItemShop = TRUE;
            gKecleonBrosWork->unkE4 = &gKecleonBrosWork->faceFile;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_BROS_MODE_ITEMS_ASLEEP:
            gKecleonBrosWork->isKecleonItemShop = TRUE;
            gKecleonBrosWork->unkE4 = NULL;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_BROS_MODE_WARES_AWAKE:
            gKecleonBrosWork->isKecleonItemShop = FALSE;
            gKecleonBrosWork->unkE4 = &gKecleonBrosWork->faceFile;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_BROS_MODE_WARES_ASLEEP:
            gKecleonBrosWork->isKecleonItemShop = FALSE;
            gKecleonBrosWork->unkE4 = NULL;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        default:
            break;
    }

    faceFile = GetDialogueSpriteDataPtr(MONSTER_KECLEON);
    gKecleonBrosWork->faceFile = faceFile;
    gKecleonBrosWork->faceData = faceFile->data;
    gKecleonBrosWork->unkE0 = 0;
    gKecleonBrosWork->unkE1 = 0;
    gKecleonBrosWork->unkE2 = 0;
    gKecleonBrosWork->unkDC = 2;
    gKecleonBrosWork->unkDE = 8;
    KecleonBros_SetState(KECLEON_STORE_INIT);
    return 1;
}

u32 KecleonBros_Callback(void)
{
    switch (gKecleonBrosWork->currState) {
        case KECLEON_STORE_INIT:
        case KECLEON_STORE_MAIN_MENU:
            sub_8019730();
            break;
        case 0x12:
        case 0x13:
            sub_80199CC();
            break;
        case 0x1a:
        case 0x1b:
            sub_8019B08();
            break;
        case 0x14:
            sub_8019BBC();
            break;
        case 0x1c:
            sub_8019C78();
            break;
        case 0x16:
            sub_8019850();
            break;
        case 0x1e:
            sub_80198E8();
            break;
        case 0x1f:
            sub_8019944();
            break;
        case 0x15:
            sub_8019D30();
            break;
        case 0x1d:
            sub_8019D4C();
            break;
        case KECLEON_STORE_EXIT:
            return 3;
        default:
            sub_8019D68();
            break;
    }
    return 0;
}

void KecleonBros_Delete(void)
{
    if (gKecleonBrosWork != NULL) {
        CloseFile(gKecleonBrosWork->faceFile);
        MemoryFree(gKecleonBrosWork);
        gKecleonBrosWork = NULL;
    }
}

void KecleonBros_SetState(u32 newState)
{
    gKecleonBrosWork->currState = newState;
    sub_8018D30();
    UpdateKecleonStoreDialogue();
}

void sub_8018D30(void)
{
    s32 index;
    sub_8006518(gKecleonBrosWork->unkE8);

    switch (gKecleonBrosWork->currState) {
        case 0x12:
        case 0x13:
            gKecleonBrosWork->unkE8[0] = gUnknown_80DB840;
            gKecleonBrosWork->unkE8[2] = gUnknown_80DB840;
            gKecleonBrosWork->unkE8[0] = gUnknown_80DB870;
            gKecleonBrosWork->unkE8[1] = gUnknown_80DB888;
            break;
        case 0x1A:
        case 0x1B:
            gKecleonBrosWork->unkE8[0] = gUnknown_80DB840;
            gKecleonBrosWork->unkE8[1] = gUnknown_80DB840;
            gKecleonBrosWork->unkE8[2] = gUnknown_80DB840;
            gKecleonBrosWork->unkE8[1] = gUnknown_80DB888;
            break;
        case 0x14:
        case 0x1C:
            gKecleonBrosWork->unkE8[2] = gUnknown_80DB858;
            break;
        default:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
            for(index = 0; index < 4; index++)
                gKecleonBrosWork->unkE8[index] = gUnknown_80DB840;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(gKecleonBrosWork->unkE8, 1, 1);
}

void UpdateKecleonStoreDialogue(void)
{
    switch (gKecleonBrosWork->currState) {
        case 0:
            sub_8019DAC();
            sub_80194F8();
            sub_8019E04(FALSE);
            sub_8014248(gKecleonShopDialogue[gKecleonBrosWork->mode][0], 0, gKecleonBrosWork->menuAction1,
                gKecleonBrosWork->menuItems, gKecleonBrosWork->unk74, 4, 0, gKecleonBrosWork->unkE4, 12);
            break;
        case 1:
            sub_8019DAC();
            sub_80194F8();
            sub_8019E04(FALSE);
            sub_8014248(gKecleonShopDialogue[gKecleonBrosWork->mode][1], 0, gKecleonBrosWork->menuAction1,
                gKecleonBrosWork->menuItems, gKecleonBrosWork->unk74, 4, 0, gKecleonBrosWork->unkE4, 12);
            break;
        case 2:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][22], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 3:         
            gKecleonBrosWork->fallbackState = 4;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][2], 0, gKecleonBrosWork->unkE4, 0x30D);
            break;
        case 5:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][12], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 6:
            gKecleonBrosWork->fallbackState = 16;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][13], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 7:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][14], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 8:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][15], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 9:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][16], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 10:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][17], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 11:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][18], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 12:
            gKecleonBrosWork->fallbackState = 16;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][19], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 13:
            sub_8090E14(gUnknown_202DE58, &gKecleonBrosWork->soldItem, NULL);
            gKecleonBrosWork->fallbackState = 24;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][20], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 14:
            gKecleonBrosWork->fallbackState = 24;
            sub_8019E04(TRUE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][21], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 15:
            gKecleonBrosWork->fallbackState = 18;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][3], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 16:
            gKecleonBrosWork->fallbackState = 19;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][4], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 18:
            if (gKecleonBrosWork->isKecleonItemShop != FALSE)
                sub_8019E40(3);
            else
                sub_801A20C(3);

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
        case 19:
            if (gKecleonBrosWork->isKecleonItemShop != FALSE)
                sub_8019FCC(1);
            else
                sub_801A398(1);

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
        case 20:
            if (gKecleonBrosWork->isKecleonItemShop != FALSE)
                sub_801A0D8();
            else
                sub_801A4A4();

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            sub_80195C0();
            sub_8012D60(&gKecleonBrosWork->menu, gKecleonBrosWork->menuItems, 0, gKecleonBrosWork->unk74, gKecleonBrosWork->menuAction3, 2);
            break;
        case 22:
            sub_8019700();
            sub_8090E14(gUnknown_202DE58, &gKecleonBrosWork->soldItem, 0);
            gUnknown_202DE30 = gKecleonBrosWork->itemSellPrice;
            sub_8019E04(FALSE);
            sub_8014248(gKecleonShopDialogue[gKecleonBrosWork->mode][5], 0, 5,gKecleonBrosWork->menuItems, NULL, 4, 0, gKecleonBrosWork->unkE4, 12);
            break;
        case 17:
            if (CountKecleonItems() == 0) {
                if (gKecleonBrosWork->isKecleonItemShop != FALSE)
                    sub_801A010();
                else
                    sub_801A3DC();
                gKecleonBrosWork->fallbackState = 11;
            }
            else {
                if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                    if (gKecleonBrosWork->isKecleonItemShop != FALSE)
                        sub_801A010();
                    else
                        sub_801A3DC();
                    gKecleonBrosWork->fallbackState = 1;
                }
                else
                    gKecleonBrosWork->fallbackState = 16;
            }
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][6], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 23:
            gKecleonBrosWork->fallbackState = 26;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][7], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 24:
            gKecleonBrosWork->fallbackState = 27;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][8], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 26:
            sub_801A5D8(4, 3, NULL, 10);
            DrawTeamMoneyBox(1);
            break;
        case 27:
            sub_801A8D0(1);
            DrawTeamMoneyBox(1);
            break;
        case 28:
            sub_801A9E0();
            DrawTeamMoneyBox(1);
            sub_8019660();
            sub_8012D60(&gKecleonBrosWork->menu, gKecleonBrosWork->menuItems, 0, gKecleonBrosWork->unk74, gKecleonBrosWork->menuAction2, 2);
            break;
        case 30:
            sub_8019700();
            sub_8090E14(gUnknown_202DE58, &gKecleonBrosWork->soldItem, NULL);
            gUnknown_202DE30 = gKecleonBrosWork->itemSellPrice;
            sub_8019E04(FALSE);
            sub_8014248(gKecleonShopDialogue[gKecleonBrosWork->mode][9], 0, 5, gKecleonBrosWork->menuItems, NULL, 4, 0, gKecleonBrosWork->unkE4, 12);
            break;
        case 21:
        case 29:
            sub_801B3C0(&gKecleonBrosWork->soldItem);
            break;
        case 25:
            if (GetNumberOfFilledInventorySlots() == 0 || gTeamInventory_203B460->teamMoney >= MAX_TEAM_MONEY) {
                sub_801A928();
                gKecleonBrosWork->fallbackState = 1;
            }
            else
                gKecleonBrosWork->fallbackState = 24;

            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][11], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
        case 31:
            sub_8019700();
            gUnknown_202DE30 = gKecleonBrosWork->inventoryItemSellPrice;
            sub_8019E04(FALSE);
            sub_8014248(gKecleonShopDialogue[gKecleonBrosWork->mode][10], 0, 5, gKecleonBrosWork->menuItems, NULL, 4, 0, gKecleonBrosWork->unkE4, 12);
            break;
        case 32:
            gKecleonBrosWork->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gKecleonShopDialogue[gKecleonBrosWork->mode][11], 0, gKecleonBrosWork->unkE4, 0x10D);
            break;
    }
}

void sub_80194F8(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKecleonBrosWork->unk74, 0, sizeof(gKecleonBrosWork->unk74));

    loopMax = 0;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4978;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 2;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4984;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 3;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = gUnknown_80DB8A0;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 4;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4970;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 7;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4934;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 1;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = NULL;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gKecleonBrosWork->unk74[index] == 0) {
            if (gKecleonBrosWork->menuItems[index].menuAction == gKecleonBrosWork->menuAction1)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKecleonBrosWork->unk74[index] == 0) {
            gKecleonBrosWork->menuAction1 =  gKecleonBrosWork->menuItems[index].menuAction;
            break;
        }
    }
}

void sub_80195C0(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKecleonBrosWork->unk74, 0, sizeof(gKecleonBrosWork->unk74));

    loopMax = 0;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4978;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 2;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4970;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 7;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = NULL;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gKecleonBrosWork->unk74[index] == 0) {
            if (gKecleonBrosWork->menuItems[index].menuAction == gKecleonBrosWork->menuAction3)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKecleonBrosWork->unk74[index] == 0) {
            gKecleonBrosWork->menuAction3 = gKecleonBrosWork->menuItems[index].menuAction;
            break;
        }
    }
}

void sub_8019660(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKecleonBrosWork->unk74, 0, sizeof(gKecleonBrosWork->unk74));

    loopMax = 0;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4984;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 3;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4970;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 7;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = NULL;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 1;

    for (index = 0; index < loopMax; index++) {
        if (gKecleonBrosWork->unk74[index] == 0) {
            if (gKecleonBrosWork->menuItems[index].menuAction == gKecleonBrosWork->menuAction2)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKecleonBrosWork->unk74[index] == 0) {
            gKecleonBrosWork->menuAction2 =  gKecleonBrosWork->menuItems[index].menuAction;
            break;
        }
    }
}

void sub_8019700(void)
{
    s32 loopMax = 0;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4920;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 5;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = *gUnknown_80D4928;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 6;

    loopMax += 1;
    gKecleonBrosWork->menuItems[loopMax].text = NULL;
    gKecleonBrosWork->menuItems[loopMax].menuAction = 1;
}

void sub_8019730(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    if (menuAction != 1)
        gKecleonBrosWork->menuAction1 = menuAction;

    switch (menuAction) {
        case 2:
            if (CountKecleonItems() == 0)
                KecleonBros_SetState(KECLEON_STORE_NO_STORE_ITEMS);
            else if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                KecleonBros_SetState(KECLEON_STORE_TOO_MANY_ITEMS);
            else
                KecleonBros_SetState(15);
            break;
        case 3:
            if (GetNumberOfFilledInventorySlots() == 0)
                KecleonBros_SetState(KECLEON_STORE_NO_ITEMS_TO_SELL);
            else if (gKecleonBrosWork->numInventoryItemToSell == 0)
                KecleonBros_SetState(8);
            else if (gTeamInventory_203B460->teamMoney < MAX_TEAM_MONEY)
                KecleonBros_SetState(23);
            else
                KecleonBros_SetState(7);
            break;
        case 4:
            if (GetNumberOfFilledInventorySlots() == 0)
                KecleonBros_SetState(KECLEON_STORE_NO_ITEMS_TO_SELL);
            else if (gKecleonBrosWork->numInventoryItemToSell == 0)
                KecleonBros_SetState(8);
            else if (gKecleonBrosWork->inventoryItemSellPrice + gTeamInventory_203B460->teamMoney > MAX_TEAM_MONEY)
                KecleonBros_SetState(7);
            else
                KecleonBros_SetState(31);
            break;
        case 7:
            KecleonBros_SetState(2);
            break;
        case 1:
            KecleonBros_SetState(3);
            break;
    }
}

void sub_8019850(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case 5:
                AddToTeamMoney(-gKecleonBrosWork->itemSellPrice);

                if (gKecleonBrosWork->isKecleonItemShop) {
                    AddHeldItemToInventory(GetKecleonShopItem(gKecleonBrosWork->itemShopItemIndex));
                    InitKecleonShopItem(gKecleonBrosWork->itemShopItemIndex);
                    FillKecleonShopGaps();
                }
                else {
                    AddHeldItemToInventory(GetKecleonWareItem(gKecleonBrosWork->wareShopItemIndex));
                    InitKecleonWareItem(gKecleonBrosWork->wareShopItemIndex);
                    FillKecleonWareGaps();
                }

                PlaySound(0x14c);
                KecleonBros_SetState(17);
                break;
            case 6:
            case 1:
                KecleonBros_SetState(16);
                break;
        }
    }
}

void sub_80198E8(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case 5:
                AddToTeamMoney(gKecleonBrosWork->itemSellPrice);
                ShiftItemsDownFrom(gKecleonBrosWork->soldItemInventoryIndex);
                PlaySound(0x14c);
                KecleonBros_SetState(25);
                break;
            case 6:
            case 1:
                KecleonBros_SetState(24);
                break;
        }
    }
}

void sub_8019944(void)
{
    s32 slotIndex;
    s32 menuAction;
    struct Item *item;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case 5:
                for (slotIndex = 0; slotIndex < INVENTORY_SIZE; slotIndex++) {
                    item = &gTeamInventory_203B460->teamItems[slotIndex];

                    if ((item->flags & ITEM_FLAG_EXISTS) && CanSellItem(item->id))
                        ClearItemSlotAt(slotIndex);
                }

                FillInventoryGaps();
                AddToTeamMoney(gKecleonBrosWork->inventoryItemSellPrice);
                PlaySound(0x14c);
                KecleonBros_SetState(32);
                break;
            case 1:
            case 6:
                KecleonBros_SetState(KECLEON_STORE_MAIN_MENU);
                break;
        }
    }
}

void sub_80199CC(void)
{
    u32 menuAction;
    struct BulkItem *item;

    if (gKecleonBrosWork->isKecleonItemShop)
        menuAction = sub_8019EDC(1);
    else
        menuAction = sub_801A2A8(1);

    switch (menuAction) {
        case 3:
            if (gKecleonBrosWork->isKecleonItemShop) {
                gKecleonBrosWork->itemShopItemIndex = sub_8019FB0();
                item = GetKecleonShopItem(gKecleonBrosWork->itemShopItemIndex);
            }
            else {
                gKecleonBrosWork->wareShopItemIndex = sub_801A37C();
                item = GetKecleonWareItem(gKecleonBrosWork->wareShopItemIndex);
            }

            xxx_init_itemslot_8090A8C(&gKecleonBrosWork->soldItem, item->id, 0);
            gKecleonBrosWork->soldItem.quantity = item->quantity;
            gKecleonBrosWork->itemSellPrice = GetStackBuyPrice(&gKecleonBrosWork->soldItem);
            KecleonBros_SetState(20);
            break;
        case 4:
            if (gKecleonBrosWork->isKecleonItemShop) {
                gKecleonBrosWork->itemShopItemIndex = sub_8019FB0();
                item = GetKecleonShopItem(gKecleonBrosWork->itemShopItemIndex);
            }
            else {
                gKecleonBrosWork->wareShopItemIndex = sub_801A37C();
                item = GetKecleonWareItem(gKecleonBrosWork->wareShopItemIndex);
            }

            xxx_init_itemslot_8090A8C(&gKecleonBrosWork->soldItem, item->id, 0);
            gKecleonBrosWork->soldItem.quantity = item->quantity;
            gKecleonBrosWork->itemSellPrice = GetStackBuyPrice(&gKecleonBrosWork->soldItem);
            KecleonBros_SetState(21);
            break;
        case 2:
            if (gKecleonBrosWork->isKecleonItemShop)
                sub_801A010();
            else
                sub_801A3DC();

            KecleonBros_SetState(KECLEON_STORE_MAIN_MENU);
            break;
        case 1:
            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
    }
}

void sub_8019B08(void)
{
    switch (sub_801A6E8(TRUE)) {
        case 0:
            break;
        case 3:
            gKecleonBrosWork->soldItemInventoryIndex = sub_801A8AC();
            gKecleonBrosWork->soldItem = gTeamInventory_203B460->teamItems[gKecleonBrosWork->soldItemInventoryIndex];
            gKecleonBrosWork->itemSellPrice = GetStackSellPrice(&gKecleonBrosWork->soldItem);
            KecleonBros_SetState(28);
            break;
        case 4:
            gKecleonBrosWork->soldItemInventoryIndex = sub_801A8AC();
            gKecleonBrosWork->soldItem = gTeamInventory_203B460->teamItems[gKecleonBrosWork->soldItemInventoryIndex];
            gKecleonBrosWork->itemSellPrice = GetStackSellPrice(&gKecleonBrosWork->soldItem);
            sub_8099690(0);
            KecleonBros_SetState(29);
            break;
        case 2:
            sub_801A928();
            KecleonBros_SetState(KECLEON_STORE_MAIN_MENU);
            break;
        case 1:
        default:
            DrawTeamMoneyBox(1);
            break;
    }
}

void sub_8019BBC(void)
{
    s32 menuAction;

    menuAction = 0;

    if (gKecleonBrosWork->isKecleonItemShop)
        sub_8019EDC(0);
    else
        sub_801A2A8(0);

    if (sub_8012FD8(&gKecleonBrosWork->menu) == 0 && (sub_8013114(&gKecleonBrosWork->menu, &menuAction), menuAction != 1))
        gKecleonBrosWork->menuAction3 = menuAction;

    switch (menuAction) {
        case 2:
            if (gTeamInventory_203B460->teamMoney == 0)
                KecleonBros_SetState(KECLEON_STORE_NO_MONEY);
            else if (gKecleonBrosWork->itemSellPrice > gTeamInventory_203B460->teamMoney)
                KecleonBros_SetState(KECLEON_STORE_NOT_ENOUGH_MONEY);
            else
                KecleonBros_SetState(22);
            break;
        case 7:
            KecleonBros_SetState(21);
            break;
        case 1:
            KecleonBros_SetState(19);
            break;
    }
}

void sub_8019C78(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801A6E8(FALSE);

    if (sub_8012FD8(&gKecleonBrosWork->menu) == FALSE && (sub_8013114(&gKecleonBrosWork->menu, &menuAction), menuAction != 1))
        gKecleonBrosWork->menuAction2 = menuAction;

    switch (menuAction) {
        case 3:
            sub_8099690(0);

            if (!CanSellItem(gKecleonBrosWork->soldItem.id))
                KecleonBros_SetState(KECLEON_STORE_CANT_SELL_ITEM);
            else if (gKecleonBrosWork->itemSellPrice + gTeamInventory_203B460->teamMoney > MAX_TEAM_MONEY)
                KecleonBros_SetState(14);
            else
                KecleonBros_SetState(30);
            break;
        case 7:
            sub_8099690(0);
            KecleonBros_SetState(29);
            break;
        case 1:
            KecleonBros_SetState(27);
            break;
    }
}

void sub_8019D30(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            sub_801B450();
            KecleonBros_SetState(19);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8019D4C(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            sub_801B450();
            KecleonBros_SetState(27);
            break;
        case 0:
        case 1:
            break;
    }
}


void sub_8019D68(void)
{
    s32 temp;
    if (sub_80144A4(&temp) == 0)
        KecleonBros_SetState(gKecleonBrosWork->fallbackState);
}

u32 CountKecleonItems(void)
{
    if (gKecleonBrosWork->isKecleonItemShop)
        return CountKecleonShopItems();
    else
        return CountKecleonWareItems();
}

void sub_8019DAC(void)
{
    s32 sellPrice;
    struct Item *item;
    s32 index;

    gKecleonBrosWork->numInventoryItemToSell = 0;
    gKecleonBrosWork->inventoryItemSellPrice = 0;
    for (index = 0; index < INVENTORY_SIZE; index++) {
        item = &gTeamInventory_203B460->teamItems[index];

        if ((item->flags & ITEM_FLAG_EXISTS) != 0 && CanSellItem(item->id)) {
            sellPrice = GetStackSellPrice(item);
            gKecleonBrosWork->inventoryItemSellPrice += sellPrice;
            gKecleonBrosWork->numInventoryItemToSell++;
        }
    }
}

void sub_8019E04(bool32 param_1)
{
    if (gKecleonBrosWork->isKecleonItemShop) {
        if (param_1 == TRUE)
            gKecleonBrosWork->unkE0 = 1;
        else
            gKecleonBrosWork->unkE0 = 0;
    }
    else {
        if (param_1 == TRUE)
            gKecleonBrosWork->unkE0 = 7;
        else
            gKecleonBrosWork->unkE0  = 6;
    }
}

bool32 sub_8019E40(u32 r0)
{
    if (CountKecleonShopItems() == 0)
        return FALSE;

    gUnknown_203B214 = MemoryAlloc(sizeof(struct unkStruct_203B214), 8);
    gUnknown_203B214->unk34 = r0;
    gUnknown_203B214->unk38 = &gUnknown_203B214->unk3C[gUnknown_203B214->unk34];
    sub_8006518(gUnknown_203B214->unk3C);
    gUnknown_203B214->unk3C[gUnknown_203B214->unk34] = gUnknown_80DB8CC;
    gUnknown_203B214->unk38->unk14 = gUnknown_203B214->unk9C;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, 1, 1);
    sub_8013818(&gUnknown_203B214->input, CountKecleonShopItems(), 10, r0);
    gUnknown_203B214->input.menuIndex = gUnknown_203B218;
    sub_8013984(&gUnknown_203B214->input);
    sub_801A064();
    sub_801A0D8();
    return TRUE;
}

u32 sub_8019EDC(u8 r0)
{
    struct Item slot;
    struct BulkItem *item;

    if (r0 == 0) {
        sub_8013660(&gUnknown_203B214->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B214->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            item = GetKecleonShopItem(sub_8019FB0());
            slot.id = item->id;
            slot.quantity = item->quantity;

            if (GetStackBuyPrice(&slot) > gTeamInventory_203B460->teamMoney)
                PlayMenuSoundEffect(2);
            else
                PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B214->input, 1) != FALSE) {
                sub_801A064();
                sub_801A0D8();
                return 1;
            }
            return 0;
    }
}

u8 sub_8019FB0(void)
{
    return (gUnknown_203B214->input.unk1E * gUnknown_203B214->input.unk1C) + (u8)gUnknown_203B214->input.menuIndex;
}

void sub_8019FCC(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, 0, 0);
    gUnknown_203B214->input.unk22 = CountKecleonShopItems();
    sub_8013984(&gUnknown_203B214->input);
    sub_801A064();
    sub_801A0D8();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B214->input);
}

void sub_801A010(void)
{
    if (gUnknown_203B214 != NULL) {
        gUnknown_203B218 = gUnknown_203B214->input.menuIndex;
        gUnknown_203B214->unk3C[gUnknown_203B214->unk34] = gUnknown_80DB8B4;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B214->unk3C, 1, 1);
        MemoryFree(gUnknown_203B214);
        gUnknown_203B214 = NULL;
    }
}

#if NONMATCHING // https://decomp.me/scratch/VjeuO
void sub_801A064(void)
{
    s16 val;

    gUnknown_203B214->unk9C[0] = gUnknown_203B214->input.unk20;
    gUnknown_203B214->unk9C[1] = gUnknown_203B214->input.unk1E;
    gUnknown_203B214->unk9C[2] = 10;
    gUnknown_203B214->unk9C[3] = 0;

    val = sub_80095E4(gUnknown_203B214->input.unk1A, 12) + 2;
    gUnknown_203B214->unk3C[gUnknown_203B214->unk34].unkE = val;
    gUnknown_203B214->unk3C[gUnknown_203B214->unk34].unk10 = val + 2;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, 1, 1);
}
#else
NAKED
void sub_801A064(void)
{
    asm_unified(
            "\tpush {r4,lr}\n"
            "\tldr r4, _0801A0D4\n"
            "\tldr r0, [r4]\n"
            "\tldrh r1, [r0, 0x20]\n"
            "\tadds r0, 0x9C\n"
            "\tmovs r2, 0\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tldrh r1, [r0, 0x1E]\n"
            "\tadds r0, 0x9D\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x9E\n"
            "\tmovs r1, 0xA\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x9F\n"
            "\tstrb r2, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tmovs r1, 0x1A\n"
            "\tldrsh r0, [r0, r1]\n"
            "\tmovs r1, 0xC\n"
            "\tbl sub_80095E4\n"
            "\tadds r0, 0x2\n"
            "\tlsls r0, 16\n"
            "\tldr r2, [r4]\n"
            "\tldr r3, [r2, 0x34]\n"
            "\tlsls r1, r3, 1\n"
            "\tadds r1, r3\n"
            "\tlsls r1, 3\n"
            "\tadds r1, r2, r1\n"
            "\tadds r1, 0x4A\n"
            "\tasrs r3, r0, 16\n"
            "\tlsrs r0, 16\n"
            "\tstrh r0, [r1]\n"
            "\tldr r1, [r2, 0x34]\n"
            "\tlsls r0, r1, 1\n"
            "\tadds r0, r1\n"
            "\tlsls r0, 3\n"
            "\tadds r2, r0\n"
            "\tadds r3, 0x2\n"
            "\tadds r2, 0x4C\n"
            "\tstrh r3, [r2]\n"
            "\tbl ResetUnusedInputStruct\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x3C\n"
            "\tmovs r1, 0x1\n"
            "\tmovs r2, 0x1\n"
            "\tbl sub_800641C\n"
            "\tpop {r4}\n"
            "\tpop {r0}\n"
            "\tbx r0\n"
            "\t.align 2, 0\n"
    "_0801A0D4: .4byte gUnknown_203B214");
}
#endif // NONMATCHING

void sub_801A0D8(void)
{
    struct BulkItem *heldItem;
    s32 buyPrice;
    s32 y;
    s32 index;
    u8 auStack204 [80];
    struct unkStruct_8090F58 local_7c;
    u8 auStack112 [80];
    struct Item item;
    u8 temp_calc;

    sub_8008C54(gUnknown_203B214->unk34);
    sub_80073B8(gUnknown_203B214->unk34);
    xxx_call_draw_string((gUnknown_203B214->input.unk1E * 8) + 10, 0, gUnknown_80DB8E4, gUnknown_203B214->unk34, 0);

    for (index = 0; index < gUnknown_203B214->input.unk1A; index++) {
        temp_calc = (gUnknown_203B214->input.unk1E * gUnknown_203B214->input.unk1C) + index;
        heldItem = GetKecleonShopItem(temp_calc);
        item.id = heldItem->id;
        item.quantity = heldItem->quantity;
        item.flags = (ITEM_FLAG_EXISTS | ITEM_FLAG_IN_SHOP);
        local_7c.unk0 = 1;
        local_7c.unk4 = 0;
        local_7c.unk6 = 88;
        local_7c.unk8 = 1;
        sub_8090E14(auStack204, &item, &local_7c);
        buyPrice = GetStackBuyPrice(&item);

        if (buyPrice <= gTeamInventory_203B460->teamMoney) {
            y = sub_8013800(&gUnknown_203B214->input, index);
            xxx_call_draw_string(8, y, auStack204, gUnknown_203B214->unk34, 0);
        }
        else {
            sprintfStatic(auStack112, gUnknown_80DB8EC, auStack204);
            y = sub_8013800(&gUnknown_203B214->input, index);
            xxx_call_draw_string(8, y, auStack112, gUnknown_203B214->unk34, 0);
        }
    }

    sub_80073E0(gUnknown_203B214->unk34);
}

u32 sub_801A20C(u32 r0)
{
    if (CountKecleonWareItems() == 0)
        return 0;

    gUnknown_203B21C = MemoryAlloc(sizeof(struct unkStruct_203B214), 8);
    gUnknown_203B21C->unk34 = r0;
    gUnknown_203B21C->unk38 = &gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34];
    sub_8006518(gUnknown_203B21C->unk3C);
    gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34] = gUnknown_80DB914;
    gUnknown_203B21C->unk38->unk14 = gUnknown_203B21C->unk9C;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B21C->unk3C, 1, 1);
    sub_8013818(&gUnknown_203B21C->input, CountKecleonWareItems(), 10, r0);
    gUnknown_203B21C->input.menuIndex = gUnknown_203B220;
    sub_8013984(&gUnknown_203B21C->input);
    sub_801A430();
    sub_801A4A4();
    return 1;
}

u32 sub_801A2A8(u8 r0)
{
    struct Item slot;
    struct BulkItem *item;

    if (r0 == 0) {
        sub_8013660(&gUnknown_203B21C->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B21C->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            item = GetKecleonWareItem(sub_801A37C());

            slot.id = item->id;
            slot.quantity = item->quantity;

            if (GetStackBuyPrice(&slot) > gTeamInventory_203B460->teamMoney)
                PlayMenuSoundEffect(2);
            else
                PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B21C->input, 1) != 0) {
                sub_801A430();
                sub_801A4A4();
                return 1;
            }
            return 0;
    }
}

u8 sub_801A37C(void)
{
    return (gUnknown_203B21C->input.unk1E * gUnknown_203B21C->input.unk1C) + gUnknown_203B21C->input.menuIndex;
}

void sub_801A398(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B21C->unk3C, 0, 0);
    gUnknown_203B21C->input.unk22 = CountKecleonWareItems();
    sub_8013984(&gUnknown_203B21C->input);
    sub_801A430();
    sub_801A4A4();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B21C->input);
}

void sub_801A3DC(void)
{
    if (gUnknown_203B21C != NULL) {
        gUnknown_203B220 = gUnknown_203B21C->input.menuIndex;
        gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34] = gUnknown_80DB8FC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B21C->unk3C, 1, 1);
        MemoryFree(gUnknown_203B21C);
        gUnknown_203B21C = NULL;
    }
}

#if NONMATCHING // https://decomp.me/scratch/L78xC
void sub_801A430(void)
{
    s16 val;

    gUnknown_203B21C->unk9C[0] = gUnknown_203B21C->input.unk20;
    gUnknown_203B21C->unk9C[1] = gUnknown_203B21C->input.unk1E;
    gUnknown_203B21C->unk9C[2] = 10;
    gUnknown_203B21C->unk9C[3] = 0;

    val = sub_80095E4(gUnknown_203B21C->input.unk1A, 12) + 2;
    gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34].unkE = val;
    gUnknown_203B21C->unk3C[gUnknown_203B21C->unk34].unk10 = val + 2;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B21C->unk3C, 1, 1);
}
#else
NAKED
void sub_801A430(void)
{
	asm_unified("\tpush {r4,lr}\n"
	"\tldr r4, _0801A4A0\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x20]\n"
	"\tadds r0, 0x9C\n"
	"\tmovs r2, 0\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x1E]\n"
	"\tadds r0, 0x9D\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9E\n"
	"\tmovs r1, 0xA\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9F\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x1A\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x34]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x4A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x34]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x4C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801A4A0: .4byte gUnknown_203B21C");
}
#endif // NONMATCHING

void sub_801A4A4(void)
{
    struct BulkItem *heldItem;
    s32 buyPrice;
    s32 y;
    s32 index;
    u8 buffer1 [80];
    struct unkStruct_8090F58 local_7c;
    u8 buffer2 [80];
    struct Item item;
    u8 temp_calc;

    sub_8008C54(gUnknown_203B21C->unk34);
    sub_80073B8(gUnknown_203B21C->unk34);
    xxx_call_draw_string(gUnknown_203B21C->input.unk1E * 8 + 10, 0, gUnknown_80DB92C, gUnknown_203B21C->unk34, 0);

    for (index = 0; index < gUnknown_203B21C->input.unk1A; index++) {
        temp_calc = (gUnknown_203B21C->input.unk1E * gUnknown_203B21C->input.unk1C) + index;
        heldItem = GetKecleonWareItem(temp_calc);
        item.id = heldItem->id;
        item.quantity = heldItem->quantity;
        item.flags = (ITEM_FLAG_EXISTS | ITEM_FLAG_IN_SHOP);
        local_7c.unk0 = 1;
        local_7c.unk4 = 0;
        local_7c.unk6 = 88;
        local_7c.unk8 = 1;
        sub_8090E14(buffer1, &item, &local_7c);
        buyPrice = GetStackBuyPrice(&item);

        if (buyPrice <= gTeamInventory_203B460->teamMoney) {
            y = sub_8013800(&gUnknown_203B21C->input, index);
            xxx_call_draw_string(8, y, buffer1, gUnknown_203B21C->unk34, 0);
        }
        else {
            sprintfStatic(buffer2, gUnknown_80DB934, buffer1);
            y = sub_8013800(&gUnknown_203B21C->input, index);
            xxx_call_draw_string(8, y, buffer2, gUnknown_203B21C->unk34, 0);
        }
    }
    sub_80073E0(gUnknown_203B21C->unk34);
}

bool32 sub_801A5D8(u32 param_1, s32 param_2, struct UnkTextStruct2_sub *param_3, u32 param_4)
{
    if (GetNumberOfFilledInventorySlots() == 0)
        return FALSE;

    if (gUnknown_203B224 == NULL)
        gUnknown_203B224 = MemoryAlloc(sizeof(struct unkStruct_203B224), 8);

    gUnknown_203B224->unk0 = param_1;
    FillInventoryGaps();
    sub_801AE84();
    gUnknown_203B224->unk88 = param_2;
    gUnknown_203B224->unk8C = &gUnknown_203B224->unk90[param_2];
    sub_8006518(gUnknown_203B224->unk90);
    gUnknown_203B224->unk90[gUnknown_203B224->unk88] = gUnknown_80DB95C;
    gUnknown_203B224->unk8C->unk14 = gUnknown_203B224->unkF0;

    if (param_3 != NULL)
        gUnknown_203B224->unk90[gUnknown_203B224->unk88].unk8 = *param_3;

    sub_8012D08(gUnknown_203B224->unk8C, param_4);
    sub_8099690(1);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, 1, 1);
    sub_8013818(&gUnknown_203B224->input, GetNumberOfFilledInventorySlots(), param_4, param_2);
    gUnknown_203B224->input.menuIndex = gUnknown_203B228;
    gUnknown_203B224->input.unk1E = gUnknown_203B22A;
    sub_8013984(&gUnknown_203B224->input);
    sub_801A998();
    sub_801A9E0();
    return TRUE;
}

u32 sub_801A6E8(bool8 param_1)
{
    s32 index;
    struct Item item;

    if (param_1 == FALSE) {
        sub_8013660(&gUnknown_203B224->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B224->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            switch (gUnknown_203B224->unk0) {
                case 0:
                case 1:
                case 2:
                    if (gUnknown_203B224->unk4[sub_801A8AC()] != 0)
                        PlayMenuSoundEffect(2);
                    else
                        PlayMenuSoundEffect(0);
                    break;
                case 3:
                    if (sub_801AEA8() != 0 || sub_801ADA0(sub_801A8AC()))
                        PlayMenuSoundEffect(0);
                    else
                        PlayMenuSoundEffect(2);
                    break;
                case 4:
                    item = gTeamInventory_203B460->teamItems[sub_801A8AC()];

                    if (CanSellItem(item.id) && GetStackSellPrice(&item) + gTeamInventory_203B460->teamMoney <= MAX_TEAM_MONEY)
                        PlayMenuSoundEffect(0);
                    else
                        PlayMenuSoundEffect(2);
                    break;
                case 5:
                    PlayMenuSoundEffect(0);
                    break;
            }
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        case INPUT_L_BUTTON:
        case INPUT_R_BUTTON:
            if (gUnknown_203B224->unk0 != 3)
                goto _0801A87C;

            index = sub_801A8AC();
            if (gUnknown_203B224->unk4[index] != 0 || sub_801ADA0(index)) {
                PlayMenuSoundEffect(6);
                gUnknown_203B224->unk4[index] ^= 1;
                sub_80138B8(&gUnknown_203B224->input, 0);
                sub_801A9E0();
                return 1;
            }

            PlayMenuSoundEffect(2);
            goto _0801A87C;
        case INPUT_SELECT_BUTTON:
            if (gUnknown_203B224->unk0 != 2) {
                PlayMenuSoundEffect(5);
                Kecleon_SortItems();
                sub_801A9E0();
            }
            // NOTE: fallthrough needed here
        default:
            _0801A87C:
            if (sub_80138B8(&gUnknown_203B224->input, 1) != FALSE) {
                sub_801A998();
                sub_801A9E0();
                return 1;
            }
            else
                return 0;
            break;
    }
}

s32 sub_801A8AC(void)
{
    return (gUnknown_203B224->input.unk1E * gUnknown_203B224->input.unk1C) + gUnknown_203B224->input.menuIndex;
}

void sub_801A8D0(u8 r0)
{
    sub_8099690(1);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, 0, 0);
    FillInventoryGaps();
    gUnknown_203B224->input.unk22 = GetNumberOfFilledInventorySlots();
    sub_8013984(&gUnknown_203B224->input);
    sub_801A998();
    sub_801A9E0();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B224->input);
}

void sub_801A928(void)
{
    if (gUnknown_203B224 != NULL) {
        gUnknown_203B228 = gUnknown_203B224->input.menuIndex;
        gUnknown_203B22A = gUnknown_203B224->input.unk1E;
        gUnknown_203B224->unk90[gUnknown_203B224->unk88] = gUnknown_80DB944;
        sub_8099690(0);
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B224->unk90, 1, 1);
        MemoryFree(gUnknown_203B224);
        gUnknown_203B224 = NULL;
    }
}

void sub_801A998(void)
{
    gUnknown_203B224->unkF0[0] = gUnknown_203B224->input.unk20;
    gUnknown_203B224->unkF0[1] = gUnknown_203B224->input.unk1E;
    gUnknown_203B224->unkF0[2] = 11;
    gUnknown_203B224->unkF0[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, 1, 1);
}

void sub_801A9E0(void)
{
    s32 teamItemIndex;
    s32 r7;
    s32 x;
    char buffer1 [0x50]; // sp 0x4
    struct unkStruct_8090F58 stack; // sp 0x54
    struct unkStruct_8090F58 stack1; // sp 0x60
    struct unkStruct_8090F58 stack2; // sp 0x6C
    struct unkStruct_8090F58 stack3; // sp 0x78
    // NOTE: this var is unused but makes sure we get correct stack size
    // This is also why we need special build flag for this file
    u8 local_6c[0x44]; // sp 0x78 ?? (why is this at same location..)
    struct Item item; // sp 0xC8

    sub_8008C54(gUnknown_203B224->unk88);
    sub_80073B8(gUnknown_203B224->unk88);
    x = gUnknown_203B224->input.unk1E * 8 + 10;

    if (gUnknown_203B224->input.unk1E == 0)
        xxx_call_draw_string(x, 0, gTeamToolboxA, gUnknown_203B224->unk88, 0);
    else
        xxx_call_draw_string(x, 0, gTeamToolboxB, gUnknown_203B224->unk88, 0);

    for (r7 = 0; r7 < gUnknown_203B224->input.unk1A; r7++) {
        teamItemIndex = (gUnknown_203B224->input.unk1E * gUnknown_203B224->input.unk1C) + r7;
        item = gTeamInventory_203B460->teamItems[teamItemIndex];

        switch (gUnknown_203B224->unk0) {
            case 0:
                sub_8090E14(buffer1, &item, 0);
                xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buffer1, gUnknown_203B224->unk88, 0);
                break;
            case 1:
            case 2:
                stack.unk0 = 0;
                stack.unk4 = 0;
                stack.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buffer1, &item, &stack);
                xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buffer1, gUnknown_203B224->unk88, 0);
                break;
            case 3:
                stack1.unk0 = 0;
                stack1.unk4 = 0;
                stack1.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buffer1, &item, &stack1);

                if (gUnknown_203B224->unk4[teamItemIndex] != 0 || sub_801ADA0(teamItemIndex))
                    xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->input,r7),buffer1,gUnknown_203B224->unk88, 0);
                else {
                    strncpy(gUnknown_202DE58, buffer1, 0x50);
                    xxx_format_and_draw(8, sub_8013800(&gUnknown_203B224->input, r7), gUnknown_80DB994, gUnknown_203B224->unk88, 0);
                }
                break;
            case 4:
                if (CanSellItem(item.id)) {
                    stack2.unk0 = 3;
                    stack2.unk4 = 0;
                    stack2.unk6 = 0x58;
                    stack2.unk8 = 1;
                    item.flags = 3;
                    sub_8090E14(buffer1, &item, &stack2);

                    if (GetStackSellPrice(&item) + gTeamInventory_203B460->teamMoney > MAX_TEAM_MONEY) {
                        // very dumb but this matches...
                        sprintfStatic((char *)&stack3, gUnknown_80DB9A0, buffer1);
                        xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), (u8 *)&stack3, gUnknown_203B224->unk88, 0);
                    }
                    else
                        xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buffer1, gUnknown_203B224->unk88, 0);
                }
                else {
                    sub_8090E14(buffer1, &item, 0);
                    strncpy(gUnknown_202DE58, buffer1, 0x50);
                    xxx_format_and_draw(8, sub_8013800(&gUnknown_203B224->input, r7), gUnknown_80DB994, gUnknown_203B224->unk88, 0);
                }
                break;
            case 5:
                stack3.unk0 = 0;
                stack3.unk4 = 0;
                stack3.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buffer1, &item, &stack3);

                if (IsGummiItem(item.id))
                    xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buffer1, gUnknown_203B224->unk88, 0);
                else {
                    strncpy(gUnknown_202DE58, buffer1, 0x50);
                    xxx_format_and_draw(8, sub_8013800(&gUnknown_203B224->input, r7), gUnknown_80DB994, gUnknown_203B224->unk88, 0);
                }
                break;
        }

        if ((sub_801AED0(teamItemIndex) & 1) != 0)
            sub_8007B7C(gUnknown_203B224->unk88, 8, sub_8013800(&gUnknown_203B224->input, r7), (gUnknown_203B224->unk8C->unkC - 2) * 8, 10);
    }

    sub_80073E0(gUnknown_203B224->unk88);
}

void sub_801AD34(u32 param_1)
{ 
    sub_8008C54(param_1);
    sub_80073B8(param_1);
    xxx_call_draw_string(6, 0, gUnknown_80DB9A8, param_1, 0);
    sub_8012BC4(18, 13, GetNumberOfFilledInventorySlots(), 2, 7, param_1);
    xxx_call_draw_string(22, 13, gUnknown_80DB9B0, param_1, 0);
    sub_8012BC4(43, 13, INVENTORY_SIZE, 2, 7, param_1);
    sub_80073E0(param_1);
}

bool8 sub_801ADA0(s32 param_1)
{
    u16 uVar2;
    u32 uVar2_32;

    u16 uVar3;
    u32 uVar3_32;
    s32 sum1;
    s32 sum2;
    struct Item item;

    item = gTeamInventory_203B460->teamItems[param_1];
    if (!IsNotMoneyOrUsedTMItem(item.id))
        return FALSE;

    if (IsThrowableItem(item.id)) {
        uVar3_32 = sub_801AE24(item.id);
        sum1 = gTeamInventory_203B460->teamStorage[item.id];
        uVar3 = uVar3_32;
        sum1 += uVar3;
        sum1 += (item.quantity);
        if (sum1 > 999)
            return FALSE;
    }
    else {
        uVar2_32 = sub_801AE24(item.id);
        sum2 = gTeamInventory_203B460->teamStorage[item.id];
        uVar2 = uVar2_32;
        sum2 += uVar2;
        if (sum2 > 998)
            return FALSE;
    }
    return 1;
}

s32 sub_801AE24(u32 itemID)
{
    struct Item item;
    u16 count;
    s32 invIndex;

    count = 0;
    for (invIndex = 0; invIndex < GetNumberOfFilledInventorySlots(); invIndex++) {
        if (gUnknown_203B224->unk4[invIndex] != 0) {
            item = gTeamInventory_203B460->teamItems[invIndex];

            if (item.id == itemID) {
                if (IsThrowableItem(item.id))
                    count += item.quantity;
                else
                    count++;
            }
        }
    }
    return count;
}

void sub_801AE84(void)
{
    s32 index;

    for (index = 0; index < INVENTORY_SIZE; index++)
        gUnknown_203B224->unk4[index] = 0;
}

s32 sub_801AEA8(void)
{
    s32 index;
    s32 count;

    count = 0;
    for (index = 0; index < INVENTORY_SIZE; index++) {
        if (gUnknown_203B224->unk4[index] != 0)
            count++;
    }
    return count;
}

s32 sub_801AED0(s32 index)
{
    return gUnknown_203B224->unk4[index];
}

void sub_801AEE4(s32 index, s32 value)
{
    gUnknown_203B224->unk4[index] = value ;
}

void Kecleon_SortItems(void)
{
    struct Item *itemSlotR;
    u32 *itemIDR;
    u32 *base;
    s32 orderL;
    s32 orderR;
    u32 itemIDL;
    struct Item itemSlotL;
    s32 itemR;
    s32 itemL;

    for (itemL = 0; itemL < GetNumberOfFilledInventorySlots() - 1; itemL++) {
        for (itemR = itemL + 1; itemR < GetNumberOfFilledInventorySlots(); itemR++) {
            orderL = GetItemOrder(gTeamInventory_203B460->teamItems[itemL].id);
            orderR = GetItemOrder(gTeamInventory_203B460->teamItems[itemR].id);

            if (orderL > orderR
                         || (orderL == orderR && gTeamInventory_203B460->teamItems[itemL].quantity < gTeamInventory_203B460->teamItems[itemR].quantity)) {
                itemSlotL = gTeamInventory_203B460->teamItems[itemL];
                itemSlotR = &gTeamInventory_203B460->teamItems[itemR];
                gTeamInventory_203B460->teamItems[itemL] = *itemSlotR;
                *itemSlotR = itemSlotL;

                base = gUnknown_203B224->unk4;
                itemIDL = gUnknown_203B224->unk4[itemL];
                itemIDR = &base[itemR];
                base[itemL] = *itemIDR;
                *itemIDR = itemIDL;
            }
        }
    }
}

struct unkStruct_203B224 *sub_801AF98(void)
{
    return gUnknown_203B224;
}