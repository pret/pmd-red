#include "global.h"
#include "constants/friend_area.h"
#include "file_system.h"
#include "menu.h"
#include "pokemon.h"
#include "input.h"
#include "team_inventory.h"
#include "text.h"
#include "memory.h"
#include "menu_input.h"
#include "friend_area.h"
#include "wigglytuff_shop.h"

struct unkStruct_8092638
{
    u32 unk0;
    bool8 hasFriendArea;
    u32 unk5;
};

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

extern u8 *gWigglytuffDialogue[2][20];
extern u8 *gWigglytuffCheck[];
extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 *gUnknown_80D4934[];
extern u8 *gUnknown_80D4970[];
extern u8 *gUnknown_80D4978[];


s32 sub_80144A4(s32 *);
u8 sub_8021700(u32);
void sub_8092578(u8 *buffer, u8 index, u8 r2);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u16 *, u32, u32,u8 *r5, u32);
extern void sub_80141B4(const u8 *, u32, u8*, u32);
extern void DrawTeamMoneyBox(u32);
extern void sub_80211AC(u32, u32);
extern void sub_8021354(u32);
extern void sub_8021494();
extern void sub_803AA34();
extern void sub_8021774(u8,u32, u32);
extern void sub_809249C(u8, u32);
extern void sub_8021830(void);
extern u32 sub_80217EC(void);
extern u8 sub_803ABC8(void);
extern u32 sub_8021274(u32);
extern u8 sub_802132C(void);
extern void sub_80213A0(void);
extern void sub_8022380(void);
extern void PlaySound(u32);
bool8 sub_8023144(s32 param_1, s32 index, struct UnkTextStruct2_sub *sub, u32 param_4);
void sub_8023354(u8 param_1);
extern bool8 sub_80023E4(u32);
extern void sub_8022420(void);
extern void sub_8092638(u8,struct unkStruct_8092638  *, u32, u32);
extern u8 sub_8099B94(void);
extern void sub_8099AFC(u32, u32, u32);
extern void sub_8099A5C(u32, u32, u32);

extern u32 sub_8023278(u32);
void sub_80233A0(void);
s16 sub_802331C(void);

void sub_8022460(void);
void sub_8022538(void);
void sub_80225C8(void);
void sub_80224D4(void);
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
        gWigglytuffShop->unkCC = (u8 *)&gWigglytuffShop->faceFile;
    }
    file = GetDialogueSpriteDataPtr(MONSTER_WIGGLYTUFF);
    gWigglytuffShop->faceFile = file;
    gWigglytuffShop->faceData = file->data;
    gWigglytuffShop->unkC8 = 0;
    gWigglytuffShop->unkC9 = 0;
    gWigglytuffShop->unkCA = 0;
    gWigglytuffShop->unkC4 = 2;
    gWigglytuffShop->unkC6 = 8;
    SetWigglytuffState(0);
    return TRUE;
}

u32 sub_8021C5C(void)
{
    switch(gWigglytuffShop->state)
    {
        case 0:
        case 1:
            sub_8022460();
            break;
        case 9:
        case 10:
            sub_8022538();
            break;
        case 0xb:
            sub_80225C8();
            break;
        case 0x11:
            sub_80224D4();
            break;
        case 0xd:
            sub_80226F0();
            break;
        case 0xe:
            sub_8022790();
            break;
        case 0x10:
            sub_8022668();
            break;
        case 0x16:
        case 0x17:
            sub_8022684();
            break;
        case 4:
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
        case 0x9:
        case 0xA:
            gWigglytuffShop->unkD0[0] = gUnknown_80DC534;
            gWigglytuffShop->unkD0[2] = gUnknown_80DC534;
            gWigglytuffShop->unkD0[1] = gUnknown_80DC564;
            break;
        case 0xB:
            gWigglytuffShop->unkD0[2] = gUnknown_80DC54C;
            break;
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
        case 0:
            sub_80222C8();
            sub_8014248(gWigglytuffDialogue[gWigglytuffShop->isAsleep][0],0,gWigglytuffShop->menuAction1,gWigglytuffShop->unk1C,gWigglytuffShop->unk5C,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case 1:
            sub_80222C8();
            sub_8014248(gWigglytuffDialogue[gWigglytuffShop->isAsleep][1],0,gWigglytuffShop->menuAction1,gWigglytuffShop->unk1C,gWigglytuffShop->unk5C,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case 7:
            gWigglytuffShop->fallbackState = 9;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][3],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 8:
            gWigglytuffShop->fallbackState = 10;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][4],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 2:
            gWigglytuffShop->fallbackState = 1;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][19],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 3:
            gWigglytuffShop->fallbackState = 4;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][2],0,gWigglytuffShop->unkCC,0x30d);
            break;
        default:
            break;
        case 5:
            gWigglytuffShop->fallbackState = 3;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][8],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 6:
            gWigglytuffShop->fallbackState = 10;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][9],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 0x12:
            gWigglytuffShop->fallbackState = 3;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][10],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 0x13:
            gWigglytuffShop->fallbackState = 10;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][11],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 9:
            sub_80211AC(2,3);
            DrawTeamMoneyBox(1);
            break;
        case 10:
            sub_8021354(1);
            DrawTeamMoneyBox(1);
            break;
        case 0xb:
            sub_8021494();
            DrawTeamMoneyBox(1);
            sub_8022380();
            sub_8012D60(&gWigglytuffShop->unk6C,gWigglytuffShop->unk1C,0,gWigglytuffShop->unk5C, gWigglytuffShop->menuAction2,2);
            break;
        case 0x11:
            sub_8022420();
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,0);
            gUnknown_202DE30[0] = gWigglytuffShop->friendAreaPrice;
            sub_8014248(gWigglytuffDialogue[gWigglytuffShop->isAsleep][5],0,5,gWigglytuffShop->unk1C,0,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case 0x10:
            sub_8021774(gWigglytuffShop->chosenFriendArea,0,2);
            break;
        case 0xc:
            gWigglytuffShop->fallbackState = 0xd;
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,0);
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][6],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 0xd:
            gWigglytuffShop->fallbackState = 0xe;
            PlaySound(0x25b);
            gWigglytuffShop->unk130 = 1;
            break;
        case 0xe:
            gWigglytuffShop->fallbackState = 0xf;
            gWigglytuffShop->unk134 = 0x1e;
            break;
        case 0xf:
            if (sub_8021700(2) != 0) {
                sub_80213A0();
                gWigglytuffShop->fallbackState = 0x12;
            }
            else {
                gWigglytuffShop->fallbackState = 8;
            }
            PlaySound(0xce);
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][7],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case 0x14:
            gWigglytuffShop->fallbackState = 0x16;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][12],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 0x15:
            gWigglytuffShop->fallbackState = 0x17;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][13],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case 0x16:
            sub_8023144(0,3,0,10);
            break;
        case 0x17:
            sub_8023354(1);
            break;
        case 0x18:
            sub_8092638(gWigglytuffShop->chosenFriendArea,&uStack_14,0,0);
            if (uStack_14.hasFriendArea) {
                gWigglytuffShop->fallbackState = 0x19;
            }
            else
            {
                switch(GetFriendAreaUnlockCondition(gWigglytuffShop->chosenFriendArea))
                {
                    case UNLOCK_SHOP_POST_GAME:
                        if (sub_80023E4(6) != 0) {
                            gWigglytuffShop->fallbackState = 0x15;
                        }
                        else {
                            gWigglytuffShop->fallbackState = 0x1a;
                        }
                        break;
                    case UNLOCK_WONDER_MAIL:
                        gWigglytuffShop->fallbackState = 0x1b;
                        break;
                    case UNLOCK_LEGENDARY_REQUEST:
                        gWigglytuffShop->fallbackState = 0x1c;
                        break;
                    default:
                        gWigglytuffShop->fallbackState = 0x15;
                        break;
                }
            }
            string = GetMonSpecies(gWigglytuffShop->chosenSpecies);
            strcpy(gAvailablePokemonNames,string);
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,0);
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][14],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case 0x19:
            gWigglytuffShop->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][15],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case 0x1a:
            gWigglytuffShop->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][16],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case 0x1b:
            gWigglytuffShop->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][17],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case 0x1c:
            gWigglytuffShop->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gWigglytuffShop->isAsleep][18],0,gWigglytuffShop->unkCC,0x10d);
            break;
    }
}

void sub_80222C8(void)
{
    s32 i;
    s32 index = 0;
    MemoryFill16(gWigglytuffShop->unk5C, 0, sizeof(gWigglytuffShop->unk5C));
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4978;
    gWigglytuffShop->unk1C[index].menuAction = 2;
    index++;
    gWigglytuffShop->unk1C[index].text = *gWigglytuffCheck;
    gWigglytuffShop->unk1C[index].menuAction = 3;
    index++;
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4970;
    gWigglytuffShop->unk1C[index].menuAction = 4;
    index++;
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4934;
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
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4978;
    gWigglytuffShop->unk1C[index].menuAction = 2;
    index++;
    gWigglytuffShop->unk1C[index].text = *gUnknown_80D4970;
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

void sub_8022420(void)
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
                    SetWigglytuffState(5);
                }
                else {
                    SetWigglytuffState(7);
                }
                break;
            case 3:
                SetWigglytuffState(0x14);
                break;
            case 4:
                SetWigglytuffState(2);
                break;
            case 1:
                SetWigglytuffState(3);
                break;
        }
    }
}

void sub_80224D4(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch(menuAction)
        {
            case 5:
                gTeamInventory_203B460->teamMoney -= gWigglytuffShop->friendAreaPrice;
                UnlockFriendArea(gWigglytuffShop->chosenFriendArea);
                PlaySound(0x14C);
                SetWigglytuffState(0xC);
                break;
            case 1:
            case 6:
                SetWigglytuffState(0xA);
                break;
        }
    }
}

void sub_8022538(void)
{
    switch(sub_8021274(1))
    {
        case 3:
            gWigglytuffShop->chosenFriendArea = sub_802132C();
            gWigglytuffShop->friendAreaPrice = GetFriendAreaPrice(gWigglytuffShop->chosenFriendArea);
            SetWigglytuffState(0xB);
            break;
        case 4:
            gWigglytuffShop->chosenFriendArea = sub_802132C();
            gWigglytuffShop->friendAreaPrice = GetFriendAreaPrice(gWigglytuffShop->chosenFriendArea);
            SetWigglytuffState(0x10);
            break;
        case 0:
            break;
        case 2:
            sub_80213A0();
            SetWigglytuffState(1);
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
    sub_8021274(0);
    if(sub_8012FD8(&gWigglytuffShop->unk6C) == 0)
    {
        sub_8013114(&gWigglytuffShop->unk6C, &menuAction);
        if(menuAction != 1) gWigglytuffShop->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        case 2:
            if(gTeamInventory_203B460->teamMoney == 0)
            {
                SetWigglytuffState(6);
            }
            else if(gWigglytuffShop->friendAreaPrice > gTeamInventory_203B460->teamMoney)
            {
                SetWigglytuffState(0x13);
            }
            else
            {
                SetWigglytuffState(0x11);
            }
            break;
        case 4:
            SetWigglytuffState(0x10);
            break;
        case 1:
            SetWigglytuffState(10);
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
            SetWigglytuffState(0xA);
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
            SetWigglytuffState(0x18);
            break;
        case 2:
            sub_80233A0();
            SetWigglytuffState(1);
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
    {
        SetWigglytuffState(gWigglytuffShop->fallbackState);
    }
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
    if(gWigglytuffShop->unk134 != 0)
    {
        gWigglytuffShop->unk134--;
    }
    else {
        SetWigglytuffState(gWigglytuffShop->fallbackState);
    }
}
