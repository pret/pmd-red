#include "global.h"
#include "pokemon.h"
#include "kecleon_items.h"
#include "memory.h"
#include "team_inventory.h"

extern struct unkStruct_203B210 *gUnknown_203B210;
extern u32 gUnknown_202DE30;
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];

extern struct UnkTextStruct2 gUnknown_80DB840;
extern struct UnkTextStruct2 gUnknown_80DB870;
extern struct UnkTextStruct2 gUnknown_80DB888;
extern struct UnkTextStruct2 gUnknown_80DB858;
extern const u8 *gKecleonShopDialogue[4][23];

extern void sub_8012D60(struct MenuStruct *, const struct MenuItem *, u32 *, u16 *, s32, s32);
extern void sub_80141B4(const u8 *, u32, struct OpenedFile **, u32);
extern void sub_8014248(const u8 *, u32, u32, const struct MenuItem *, void *, u32, u32, struct OpenedFile **, u32);
extern void sub_8018D30(void);
extern void sub_80194F8(void);
extern void sub_80195C0(void);
extern void sub_8019660(void);
extern void sub_8019700(void);
extern void sub_8019730(void);
extern void sub_8019850(void);
extern void sub_80198E8(void);
extern void sub_8019944(void);
extern void sub_80199CC(void);
extern void sub_8019B08(void);
extern void sub_8019BBC(void);
extern void sub_8019C78(void);
extern void sub_8019D30(void);
extern void sub_8019D4C(void);
extern void sub_8019D68(void);
extern void sub_8019DAC(void);
extern void sub_8019E04(s32);
extern u32 sub_8019E40(u32);
extern void sub_8019FCC(u8);
extern void sub_801A010(void);
extern void sub_801A0D8(void);
extern u32 sub_801A20C(u32);
extern void sub_801A398(u8);
extern void sub_801A3DC(void);
extern void sub_801A4A4(void);
extern u32 sub_801A5D8(u32, s32, struct UnkTextStruct2_sub *, u32);
extern void sub_801A8D0(u8);
extern void sub_801A928(void);
extern void sub_801A9E0(void);
extern void sub_801AD34(u32);
extern u32 sub_801B3C0(struct Item *);
extern void sub_8090E14(u8 *, struct Item *, struct unkStruct_8090F58 *);

extern u32 CountKecleonItems(void);
extern void DrawTeamMoneyBox(u32);

void UpdateKecleonStoreDialogue(void);
void UpdateKecleonStoreState(u32);

u32 DisplayKeckleonDialogueSprite(u32 mode)
{
    char *monName;
    struct OpenedFile *faceFile;

    gUnknown_203B210 = MemoryAlloc(sizeof(struct unkStruct_203B210), 8);
    gUnknown_203B210->menuAction1 = 0;
    gUnknown_203B210->menuAction2 = 0;
    gUnknown_203B210->menuAction3 = 0;
    gUnknown_203B210->mode = mode;

    switch (mode) {
        case KECLEON_SHOP_MODE_ITEMS_AWAKE:
            gUnknown_203B210->isKecleonItemShop = TRUE;
            gUnknown_203B210->unkE4 = &gUnknown_203B210->faceFile;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_SHOP_MODE_ITEMS_ASLEEP:
            gUnknown_203B210->isKecleonItemShop = TRUE;
            gUnknown_203B210->unkE4 = NULL;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_SHOP_MODE_WARES_AWAKE:
            gUnknown_203B210->isKecleonItemShop = FALSE;
            gUnknown_203B210->unkE4 = &gUnknown_203B210->faceFile;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_SHOP_MODE_WARES_ASLEEP:
            gUnknown_203B210->isKecleonItemShop = FALSE;
            gUnknown_203B210->unkE4 = NULL;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        default:
            break;
    }

    faceFile = GetDialogueSpriteDataPtr(MONSTER_KECLEON);
    gUnknown_203B210->faceFile = faceFile;
    gUnknown_203B210->faceData = faceFile->data;
    gUnknown_203B210->unkE0 = 0;
    gUnknown_203B210->unkE1 = 0;
    gUnknown_203B210->unkE2 = 0;
    gUnknown_203B210->unkDC = 2;
    gUnknown_203B210->unkDE = 8;
    UpdateKecleonStoreState(KECLEON_STORE_INIT);
    return 1;
}

u32 sub_8018C04(void)
{
    switch (gUnknown_203B210->currState) {
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

void sub_8018CF0(void)
{
    if (gUnknown_203B210 != NULL) {
        CloseFile(gUnknown_203B210->faceFile);
        MemoryFree(gUnknown_203B210);
        gUnknown_203B210 = NULL;
    }
}

void UpdateKecleonStoreState(u32 newState)
{
    gUnknown_203B210->currState = newState;
    sub_8018D30();
    UpdateKecleonStoreDialogue();
}

void sub_8018D30(void)
{
    s32 index;
    sub_8006518(gUnknown_203B210->unkE8);

    switch (gUnknown_203B210->currState) {
        case 0x12:
        case 0x13:
            gUnknown_203B210->unkE8[0] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[2] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[0] = gUnknown_80DB870;
            gUnknown_203B210->unkE8[1] = gUnknown_80DB888;
            break;
        case 0x1A:
        case 0x1B:
            gUnknown_203B210->unkE8[0] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[1] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[2] = gUnknown_80DB840;
            gUnknown_203B210->unkE8[1] = gUnknown_80DB888;
            break;
        case 0x14:
        case 0x1C:
            gUnknown_203B210->unkE8[2] = gUnknown_80DB858;
            break;
        default:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
            for(index = 0; index < 4; index++)
                gUnknown_203B210->unkE8[index] = gUnknown_80DB840;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B210->unkE8, 1, 1);
}

void UpdateKecleonStoreDialogue(void)
{
    switch (gUnknown_203B210->currState) {
        case 0:
            sub_8019DAC();
            sub_80194F8();
            sub_8019E04(0);
            sub_8014248(gKecleonShopDialogue[gUnknown_203B210->mode][0], 0, gUnknown_203B210->menuAction1,
                gUnknown_203B210->menuItems, gUnknown_203B210->unk74, 4, 0, gUnknown_203B210->unkE4, 12);
            break;
        case 1:
            sub_8019DAC();
            sub_80194F8();
            sub_8019E04(0);
            sub_8014248(gKecleonShopDialogue[gUnknown_203B210->mode][1], 0, gUnknown_203B210->menuAction1,
                gUnknown_203B210->menuItems, gUnknown_203B210->unk74, 4, 0, gUnknown_203B210->unkE4, 12);
            break;
        case 2:
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][22], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 3:         
            gUnknown_203B210->fallbackState = 4;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][2], 0, gUnknown_203B210->unkE4, 0x30D);
            break;
        case 5:
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][12], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 6:
            gUnknown_203B210->fallbackState = 16;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][13], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 7:
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][14], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 8:
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][15], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 9:
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][16], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 10:
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][17], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 11:
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][18], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 12:
            gUnknown_203B210->fallbackState = 16;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][19], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 13:
            sub_8090E14(gUnknown_202DE58, &gUnknown_203B210->soldItem, NULL);
            gUnknown_203B210->fallbackState = 24;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][20], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 14:
            gUnknown_203B210->fallbackState = 24;
            sub_8019E04(1);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][21], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 15:
            gUnknown_203B210->fallbackState = 18;
            sub_8019E04(0); // These are probably bool
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][3], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 16:
            gUnknown_203B210->fallbackState = 19;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][4], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 18:
            if (gUnknown_203B210->isKecleonItemShop != FALSE)
                sub_8019E40(3);
            else
                sub_801A20C(3);

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
        case 19:
            if (gUnknown_203B210->isKecleonItemShop != FALSE)
                sub_8019FCC(1);
            else
                sub_801A398(1);

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
        case 20:
            if (gUnknown_203B210->isKecleonItemShop != FALSE)
                sub_801A0D8();
            else
                sub_801A4A4();

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            sub_80195C0();
            sub_8012D60(&gUnknown_203B210->menu, gUnknown_203B210->menuItems, 0, gUnknown_203B210->unk74, gUnknown_203B210->menuAction3, 2);
            break;
        case 22:
            sub_8019700();
            sub_8090E14(gUnknown_202DE58, &gUnknown_203B210->soldItem, 0);
            gUnknown_202DE30 = gUnknown_203B210->itemSellPrice;
            sub_8019E04(0);  
            sub_8014248(gKecleonShopDialogue[gUnknown_203B210->mode][5], 0, 5,gUnknown_203B210->menuItems, NULL, 4, 0, gUnknown_203B210->unkE4, 12);
            break;
        case 17:
            if (CountKecleonItems() == 0) {
                if (gUnknown_203B210->isKecleonItemShop != FALSE)
                    sub_801A010();
                else
                    sub_801A3DC();
                gUnknown_203B210->fallbackState = 11;
            }
            else {
                if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                    if (gUnknown_203B210->isKecleonItemShop != FALSE)
                        sub_801A010();
                    else
                        sub_801A3DC();
                    gUnknown_203B210->fallbackState = 1;
                }
                else
                    gUnknown_203B210->fallbackState = 16;
            }
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][6], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 23:
            gUnknown_203B210->fallbackState = 26;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][7], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 24:
            gUnknown_203B210->fallbackState = 27;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][8], 0, gUnknown_203B210->unkE4, 0x10D);
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
            sub_8012D60(&gUnknown_203B210->menu, gUnknown_203B210->menuItems, 0, gUnknown_203B210->unk74, gUnknown_203B210->menuAction2, 2);
            break;
        case 30:
            sub_8019700();
            sub_8090E14(gUnknown_202DE58, &gUnknown_203B210->soldItem, NULL);
            gUnknown_202DE30 = gUnknown_203B210->itemSellPrice;
            sub_8019E04(0);
            sub_8014248(gKecleonShopDialogue[gUnknown_203B210->mode][9], 0, 5, gUnknown_203B210->menuItems, NULL, 4, 0, gUnknown_203B210->unkE4, 12);
            break;
        case 21:
        case 29:
            sub_801B3C0(&gUnknown_203B210->soldItem);
            break;
        case 25:
            if (GetNumberOfFilledInventorySlots() == 0 || gTeamInventory_203B460->teamMoney >= MAX_TEAM_MONEY) {
                sub_801A928();
                gUnknown_203B210->fallbackState = 1;
            }
            else
                gUnknown_203B210->fallbackState = 24;

            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][11], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
        case 31:            
            sub_8019700();
            gUnknown_202DE30 = gUnknown_203B210->inventoryItemSellPrice;
            sub_8019E04(0);
            sub_8014248(gKecleonShopDialogue[gUnknown_203B210->mode][10], 0, 5, gUnknown_203B210->menuItems, NULL, 4, 0, gUnknown_203B210->unkE4, 12);
            break;
        case 32:            
            gUnknown_203B210->fallbackState = 1;
            sub_8019E04(0);
            sub_80141B4(gKecleonShopDialogue[gUnknown_203B210->mode][11], 0, gUnknown_203B210->unkE4, 0x10D);
            break;
    }
}