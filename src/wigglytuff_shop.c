#include "global.h"
#include "constants/friend_area.h"
#include "pokemon.h"
#include "team_inventory.h"
#include "text1.h"
#include "text2.h"
#include "memory.h"
#include "menu_input.h"
#include "friend_area.h"
#include "wigglytuff_shop.h"
#include "felicity_bank.h"
#include "code_80130A8.h"
#include "code_8021774_pre.h"
#include "code_801EE10_mid.h"
#include "code_8021774.h"
#include "code_80118A4.h"

extern struct UnkTextStruct2 gUnknown_80DC534;
extern struct UnkTextStruct2 gUnknown_80DC564;
extern struct UnkTextStruct2 gUnknown_80DC54C;
extern struct UnkTextStruct2 gUnknown_80DC534;

EWRAM_DATA_2 struct WigglytuffShop *gWigglytuffShop = {0};

extern u8 gUnknown_202E628[];
extern u32 gUnknown_202DE30[2];
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];
extern u8 gAvailablePokemonNames[];

extern const u8 *gWigglytuffDialogue[2][20];
extern const u8 *gWigglytuffCheck[];
extern const u8 *gUnknown_80D4920[];
extern const u8 *gUnknown_80D4928[];
extern const u8 *gUnknown_80D4934[];
extern const u8 *gUnknown_80D4970[];
extern const u8 *gUnknown_80D4978[];

u8 sub_8021700(u32);
void sub_8092578(u8 *buffer, u8 index, u8 r2);
extern void sub_8022380(void);
bool8 sub_8023144(s32 param_1, s32 index, struct UnkTextStruct2_sub *sub, u32 param_4);
void sub_8023354(u8 param_1);
extern bool8 sub_80023E4(u32);
extern void CreateWigglytuffConfirmFriendAreaMenu(void);
extern u8 sub_8099B94(void);
extern void sub_8099AFC(u32, u32, u32);
extern void sub_8099A5C(u32, u32, u32);

extern u32 sub_8023278(u32);
void sub_80233A0(void);
s16 sub_802331C(void);

void sub_8022460(void);
void sub_8022538(void);
void sub_80225C8(void);
void HandleWigglytuffConfirmFriendAreaMenu(void);
void sub_80226F0(void);
void sub_8022790(void);
void sub_8022668(void);
void sub_8022684(void);
void sub_80226CC(void);
void sub_80222C8(void);
void SetWigglytuffState(s32);
void sub_8021D5C(void);
void UpdateWigglytuffDialogue(void);

bool8 CreateWigglytuffShop(bool32 isAsleep)
{
    char *string;
    struct OpenedFile *file;

    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
    gWigglytuffShop = MemoryAlloc(sizeof(struct WigglytuffShop), 8);
    gWigglytuffShop->menuAction1 = 0;
    gWigglytuffShop->menuAction2 = 0;
    gWigglytuffShop->isAsleep = isAsleep;
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8,MONSTER_WIGGLYTUFF);
    CopyYellowMonsterNametoBuffer(gUnknown_202E1C8,MONSTER_WIGGLYTUFF);
    string = GetMonSpecies(MONSTER_WIGGLYTUFF);
    strcpy(gUnknown_202E1C8 - 0x50, string);
    if (gWigglytuffShop->isAsleep == TRUE) {
        gWigglytuffShop->unkCC = NULL;
    }
    else {
        gWigglytuffShop->unkCC = &gWigglytuffShop->faceFile;
    }
    file = GetDialogueSpriteDataPtr(MONSTER_WIGGLYTUFF);
    gWigglytuffShop->faceFile = file;
    gWigglytuffShop->faceData = file->data;
    gWigglytuffShop->unkC8 = 0;
    gWigglytuffShop->unkC9 = 0;
    gWigglytuffShop->unkCA = 0;
    gWigglytuffShop->unkC4 = 2;
    gWigglytuffShop->unkC6 = 8;
    SetWigglytuffState(WIGGLYTUFF_INIT);
    return TRUE;
}

u32 sub_8021C5C(void)
{
    switch(gWigglytuffShop->state)
    {
        case WIGGLYTUFF_INIT:
        case WIGGLYTUFF_MAIN_MENU:
            sub_8022460();
            break;
        case WIGGLYTUFF_UNK9:
        case WIGGLYTUFF_UNKA:
            sub_8022538();
            break;
        case WIGGLYTUFF_UNKB:
            sub_80225C8();
            break;
        case BUY_FRIEND_AREA:
            HandleWigglytuffConfirmFriendAreaMenu();
            break;
        case WIGGLYTUFF_UNKD:
            sub_80226F0();
            break;
        case WIGGLYTUFF_UNKE:
            sub_8022790();
            break;
        case FRIEND_AREA_INFO:
            sub_8022668();
            break;
        case WIGGLYTUFF_UNK16:
        case WIGGLYTUFF_UNK17:
            sub_8022684();
            break;
        case WIGGLYTUFF_EXIT:
            return 3;
        default:
            sub_80226CC();
            break;
    }
    return 0;
}

void sub_8021D1C(void)
{
    if(gWigglytuffShop)
    {
        CloseFile(gWigglytuffShop->faceFile);
        MemoryFree(gWigglytuffShop);
        gWigglytuffShop = NULL;
    }
}

void SetWigglytuffState(s32 newState)
{
    gWigglytuffShop->state = newState;
    sub_8021D5C();
    UpdateWigglytuffDialogue();
}

void sub_8021D5C(void) 
{
    s32 index;
    
    sub_8006518(gWigglytuffShop->unkD0);
    switch(gWigglytuffShop->state)
    {
        case WIGGLYTUFF_UNK9:
        case WIGGLYTUFF_UNKA:
            gWigglytuffShop->unkD0[0] = gUnknown_80DC534;
            gWigglytuffShop->unkD0[2] = gUnknown_80DC534;
            gWigglytuffShop->unkD0[1] = gUnknown_80DC564;
            break;
        case WIGGLYTUFF_UNKB:
            gWigglytuffShop->unkD0[2] = gUnknown_80DC54C;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gWigglytuffShop->unkD0[index] = gUnknown_80DC534;
            }
            break;
    
    }
    ResetUnusedInputStruct();
    sub_800641C(gWigglytuffShop->unkD0, 1, 1);
}

void UpdateWigglytuffDialogue(void)
{
    char *string;
    struct unkStruct_8092638 uStack_14;

    switch(gWigglytuffShop->state) 
    {
        case WIGGLYTUFF_INIT:
            sub_80222C8();
            sub_8014248(gWigglytuffDialogue[gWigglytuffShop->isAsleep][0],0,gWigglytuffShop->menuAction1,gWigglytuffShop->unk1C,gWigglytuffShop->unk5C,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case WIGGLYTUFF_MAIN_MENU:
            sub_80222C8();
            sub_8014248(gWigglytuffDialogue[gWigglytuffShop->isAsleep][1],0,gWigglytuffShop->menuAction1,gWigglytuffShop->unk1C,gWigglytuffShop->unk5C,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case FRIEND_AREA_SELECT_BUY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNK9;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][3],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case FRIEND_AREA_SELECT_BUY_AGAIN:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][4],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_INFO:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_MAIN_MENU;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][19],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_PRE_EXIT:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_EXIT;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][2],0,gWigglytuffShop->unkCC,0x30d);
            break;
        default:
            break;
        case WIGGLYTUFF_CANT_ADD_FRIEND_AREA:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_PRE_EXIT;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][8],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case NO_MONEY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][9],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case NO_FRIEND_AREAS:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_PRE_EXIT;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][10],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case NOT_ENOUGH_MONEY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][11],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_UNK9:
            sub_80211AC(2,3);
            DrawTeamMoneyBox(1);
            break;
        case WIGGLYTUFF_UNKA:
            sub_8021354(TRUE);
            DrawTeamMoneyBox(1);
            break;
        case WIGGLYTUFF_UNKB:
            sub_8021494();
            DrawTeamMoneyBox(1);
            sub_8022380();
            sub_8012D60(&gWigglytuffShop->unk6C,gWigglytuffShop->unk1C,0,gWigglytuffShop->unk5C, gWigglytuffShop->menuAction2,2);
            break;
        case BUY_FRIEND_AREA:
            CreateWigglytuffConfirmFriendAreaMenu();
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,0);
            gUnknown_202DE30[0] = gWigglytuffShop->friendAreaPrice;
            sub_8014248(gWigglytuffDialogue[gWigglytuffShop->isAsleep][5],0,5,gWigglytuffShop->unk1C,0,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case FRIEND_AREA_INFO:
            sub_8021774(gWigglytuffShop->chosenFriendArea,0,2);
            break;
        case CONFIRM_BUY_FRIEND_AREA:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKD;
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,0);
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][6],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_UNKD:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKE;
            PlaySound(0x25b);
            gWigglytuffShop->unk130 = 1;
            break;
        case WIGGLYTUFF_UNKE:
            gWigglytuffShop->fallbackState = FRIEND_AREA_UNLOCKED;
            gWigglytuffShop->unk134 = 30;
            break;
        case FRIEND_AREA_UNLOCKED:
            if (sub_8021700(2) != 0) {
                sub_80213A0();
                gWigglytuffShop->fallbackState = NO_FRIEND_AREAS;
            }
            else {
                gWigglytuffShop->fallbackState = FRIEND_AREA_SELECT_BUY_AGAIN;
            }
            PlaySound(0xce);
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][7],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNK16;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][12],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_CHECK_AGAIN:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNK17;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][13],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_UNK16:
            sub_8023144(0,3,0,10);
            break;
        case WIGGLYTUFF_UNK17:
            sub_8023354(1);
            break;
        case DISPLAY_POKEMON_FRIEND_AREA_INFO:
            sub_8092638(gWigglytuffShop->chosenFriendArea,&uStack_14,0,0);
            if (uStack_14.hasFriendArea) {
                gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_HAS_FRIEND_AREA;
            }
            else
            {
                switch(GetFriendAreaUnlockCondition(gWigglytuffShop->chosenFriendArea))
                {
                    case UNLOCK_SHOP_POST_GAME:
                        if (sub_80023E4(6) != 0) {
                            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
                        }
                        else {
                            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_POST_GAME;
                        }
                        break;
                    case UNLOCK_WONDER_MAIL:
                        gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_WONDER_MAIL;
                        break;
                    case UNLOCK_LEGENDARY_REQUEST:
                        gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_LEGENDARY;
                        break;
                    default:
                        gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
                        break;
                }
            }
            string = GetMonSpecies(gWigglytuffShop->chosenSpecies);
            strcpy(gAvailablePokemonNames,string);
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,0);
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][14],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_HAS_FRIEND_AREA:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][15],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_POST_GAME:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][16],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_WONDER_MAIL:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][17],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_LEGENDARY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][18],0,gWigglytuffShop->unkCC,0x10d);
            break;
    }
}

void sub_80222C8(void)
{
    s32 i;
    s32 index = 0;
    MemoryFill16(gWigglytuffShop->unk5C, 0, sizeof(gWigglytuffShop->unk5C));
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4978; // Buy
    gWigglytuffShop->unk1C[index].menuAction = 2;
    index++;
    gWigglytuffShop->unk1C[index].text = *gWigglytuffCheck; // Check
    gWigglytuffShop->unk1C[index].menuAction = 3;
    index++;
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4970; // Info
    gWigglytuffShop->unk1C[index].menuAction = 4;
    index++;
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4934; // Cancel
    gWigglytuffShop->unk1C[index].menuAction = 1;
    index++;
    gWigglytuffShop->unk1C[index].text = NULL;
    gWigglytuffShop->unk1C[index].menuAction = 1;

    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0 && gWigglytuffShop->unk1C[i].menuAction == gWigglytuffShop->menuAction1)
            return;
    }
    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0)
        {
            gWigglytuffShop->menuAction1 = gWigglytuffShop->unk1C[i].menuAction;
            break;
        }
    }
}

void sub_8022380(void)
{
    s32 i;
    s32 index = 0;
    MemoryFill16(gWigglytuffShop->unk5C, 0, sizeof(gWigglytuffShop->unk5C));
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4978; // Buy
    gWigglytuffShop->unk1C[index].menuAction = 2;
    index++;
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4970; // Info
    gWigglytuffShop->unk1C[index].menuAction = 4;
    index++;
    gWigglytuffShop->unk1C[index].text = NULL;
    gWigglytuffShop->unk1C[index].menuAction = 1;

    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0 && gWigglytuffShop->unk1C[i].menuAction == gWigglytuffShop->menuAction2)
            return;
    }
    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0)
        {
            gWigglytuffShop->menuAction2 = gWigglytuffShop->unk1C[i].menuAction;
            break;
        }
    }
}

void CreateWigglytuffConfirmFriendAreaMenu(void)
{
    s32 index = 0;
    MemoryFill16(gWigglytuffShop->unk5C, 0, sizeof(gWigglytuffShop->unk5C));
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4920;
    gWigglytuffShop->unk1C[index].menuAction = 5;
    index++;
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4928;
    gWigglytuffShop->unk1C[index].menuAction = 6;
    index++;
    gWigglytuffShop->unk1C[index].text = NULL;
    gWigglytuffShop->unk1C[index].menuAction = 1;
}

void sub_8022460(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0)
    {
        if (menuAction != 1) {
            gWigglytuffShop->menuAction1 = menuAction;
        }
        switch(menuAction)
        {
            case 2:
                if (sub_8021700(2) != 0) {
                    SetWigglytuffState(WIGGLYTUFF_CANT_ADD_FRIEND_AREA);
                }
                else {
                    SetWigglytuffState(FRIEND_AREA_SELECT_BUY);
                }
                break;
            case 3:
                SetWigglytuffState(WIGGLYTUFF_CHECK);
                break;
            case 4:
                SetWigglytuffState(WIGGLYTUFF_INFO);
                break;
            case 1:
                SetWigglytuffState(WIGGLYTUFF_PRE_EXIT);
                break;
        }
    }
}

void HandleWigglytuffConfirmFriendAreaMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch(menuAction)
        {
            case 5:
                gTeamInventoryRef->teamMoney -= gWigglytuffShop->friendAreaPrice;
                UnlockFriendArea(gWigglytuffShop->chosenFriendArea);
                PlaySound(0x14C);
                SetWigglytuffState(CONFIRM_BUY_FRIEND_AREA);
                break;
            case 1:
            case 6:
                SetWigglytuffState(WIGGLYTUFF_UNKA);
                break;
        }
    }
}

void sub_8022538(void)
{
    switch(sub_8021274(TRUE))
    {
        case 3:
            gWigglytuffShop->chosenFriendArea = sub_802132C();
            gWigglytuffShop->friendAreaPrice = GetFriendAreaPrice(gWigglytuffShop->chosenFriendArea);
            SetWigglytuffState(WIGGLYTUFF_UNKB);
            break;
        case 4:
            gWigglytuffShop->chosenFriendArea = sub_802132C();
            gWigglytuffShop->friendAreaPrice = GetFriendAreaPrice(gWigglytuffShop->chosenFriendArea);
            SetWigglytuffState(FRIEND_AREA_INFO);
            break;
        case 0:
            break;
        case 2:
            sub_80213A0();
            SetWigglytuffState(WIGGLYTUFF_MAIN_MENU);
            break;
        case 1:
        default:
            DrawTeamMoneyBox(1);
            break;
    }
}

void sub_80225C8(void)
{
    s32 menuAction = 0;
    sub_8021274(FALSE);
    if(sub_8012FD8(&gWigglytuffShop->unk6C) == 0)
    {
        sub_8013114(&gWigglytuffShop->unk6C, &menuAction);
        if(menuAction != 1) gWigglytuffShop->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        case 2:
            if(gTeamInventoryRef->teamMoney == 0)
            {
                SetWigglytuffState(NO_MONEY);
            }
            else if(gWigglytuffShop->friendAreaPrice > gTeamInventoryRef->teamMoney)
            {
                SetWigglytuffState(NOT_ENOUGH_MONEY);
            }
            else
            {
                SetWigglytuffState(BUY_FRIEND_AREA);
            }
            break;
        case 4:
            SetWigglytuffState(FRIEND_AREA_INFO);
            break;
        case 1:
            SetWigglytuffState(WIGGLYTUFF_UNKA);
            break;
    }
}

void sub_8022668(void)
{
    switch(sub_80217EC())
    {
        case 2:
        case 3:
            sub_8021830();
            SetWigglytuffState(WIGGLYTUFF_UNKA);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8022684(void)
{
    switch(sub_8023278(1))
    {
        case 3:
            gWigglytuffShop->chosenSpecies = sub_802331C();
            gWigglytuffShop->chosenFriendArea = GetFriendArea(gWigglytuffShop->chosenSpecies);
            SetWigglytuffState(DISPLAY_POKEMON_FRIEND_AREA_INFO);
            break;
        case 2:
            sub_80233A0();
            SetWigglytuffState(WIGGLYTUFF_MAIN_MENU);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_80226CC(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        SetWigglytuffState(gWigglytuffShop->fallbackState);
}

void sub_80226F0(void)
{
    union {
        vu32 a;
        vu8 b[4];
    } temp;
    vu8 *ptr = temp.b;
    u32 r2 = 0;
    ptr[0] = 0x80;
    ptr[1] = 0x80;
    ptr[2] = 0x10;
    ptr[3] = r2;
    if(sub_8099B94() == 0)
    {
        switch(gWigglytuffShop->unk130)
        {
            case 1:
            case 3:
                sub_8099AFC(5, 2, temp.a);
                break;
            case 2:
            case 4:
                sub_8099A5C(5, 2, temp.a);
                break;
            case 0:
            default:
                SetWigglytuffState(gWigglytuffShop->fallbackState);
                gWigglytuffShop->unk130 = 0;
                break;
        }
        gWigglytuffShop->unk130++;
    }
}

void sub_8022790(void)
{
    if (gWigglytuffShop->unk134 != 0)
        gWigglytuffShop->unk134--;
    else
        SetWigglytuffState(gWigglytuffShop->fallbackState);
}
