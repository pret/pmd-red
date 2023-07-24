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

struct unkStruct_8092638
{
    u32 unk0;
    u8 unk4;
    u32 unk5;
};
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

extern struct UnkTextStruct2 gUnknown_80DC534;
extern struct UnkTextStruct2 gUnknown_80DC564;
extern struct UnkTextStruct2 gUnknown_80DC54C;
extern struct UnkTextStruct2 gUnknown_80DC534;

s32 sub_80144A4(s32 *);
u8 sub_8021700(u32);
void sub_8092578(u8 *buffer, u8 index, u8 r2);
void sub_80222C8(void);
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

extern u32 sub_8023278(u32);
void sub_80233A0(void);
s16 sub_802331C(void);
extern void sub_8022460(void);
extern void sub_8022538(void);
extern void sub_80225C8(void);
extern void sub_80224D4(void);
extern void sub_80226F0(void);
extern void sub_8022790(void);
extern void sub_8022668(void);
extern void sub_8022684(void);
extern void sub_80226CC(void);

void UpdateWigglytuffState(s32);
void sub_8021D5C(void);
void UpdateWigglytuffDialogue(void);

struct unkStruct_203B290 
{
    // size: 0x138
    bool32 isAsleep;
    s32 state;
    s32 fallbackState;
    s32 friendAreaPrice;
    u8 chosenFriendArea;
    s16 chosenSpecies;
    u32 menuAction1;
    u32 menuAction2;
    struct MenuItem unk1C[8];
    u16 unk5C[0x8];
    struct MenuStruct unk6C;
    /* 0xBC */ struct OpenedFile *faceFile;
    /* 0xC0 */ u8 *faceData;
    u16 unkC4;
    u16 unkC6;
    u8 unkC8;
    u8 unkC9;
    u8 unkCA;
    u8 fillCB;
    u8 *unkCC;
    struct UnkTextStruct2 unkD0[4];
    u32 unk130;
    u32 unk134;
};

extern struct unkStruct_203B290 *gUnknown_203B290;

bool8 CreateWigglytuffShop(bool32 isAsleep)
{
    char *string;
    struct OpenedFile *file;

    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
    gUnknown_203B290 = MemoryAlloc(sizeof(struct unkStruct_203B290), 8);
    gUnknown_203B290->menuAction1 = 0;
    gUnknown_203B290->menuAction2 = 0;
    gUnknown_203B290->isAsleep = isAsleep;
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8,MONSTER_WIGGLYTUFF);
    CopyYellowMonsterNametoBuffer(gUnknown_202E1C8,MONSTER_WIGGLYTUFF);
    string = GetMonSpecies(MONSTER_WIGGLYTUFF);
    strcpy(gUnknown_202E1C8 - 0x50, string);
    if (gUnknown_203B290->isAsleep == TRUE) {
        gUnknown_203B290->unkCC = NULL;
    }
    else {
        gUnknown_203B290->unkCC = (u8 *)&gUnknown_203B290->faceFile;
    }
    file = GetDialogueSpriteDataPtr(MONSTER_WIGGLYTUFF);
    gUnknown_203B290->faceFile = file;
    gUnknown_203B290->faceData = file->data;
    gUnknown_203B290->unkC8 = 0;
    gUnknown_203B290->unkC9 = 0;
    gUnknown_203B290->unkCA = 0;
    gUnknown_203B290->unkC4 = 2;
    gUnknown_203B290->unkC6 = 8;
    UpdateWigglytuffState(0);
    return TRUE;
}

u32 sub_8021C5C(void)
{
    switch(gUnknown_203B290->state)
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
    if(gUnknown_203B290)
    {
        CloseFile(gUnknown_203B290->faceFile);
        MemoryFree(gUnknown_203B290);
        gUnknown_203B290 = NULL;
    }
}

void UpdateWigglytuffState(s32 newState)
{
    gUnknown_203B290->state = newState;
    sub_8021D5C();
    UpdateWigglytuffDialogue();
}

void sub_8021D5C(void) 
{
    s32 index;
    
    sub_8006518(gUnknown_203B290->unkD0);
    switch(gUnknown_203B290->state)
    {
        case 0x9:
        case 0xA:
            gUnknown_203B290->unkD0[0] = gUnknown_80DC534;
            gUnknown_203B290->unkD0[2] = gUnknown_80DC534;
            gUnknown_203B290->unkD0[1] = gUnknown_80DC564;
            break;
        case 0xB:
            gUnknown_203B290->unkD0[2] = gUnknown_80DC54C;
            break;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B290->unkD0[index] = gUnknown_80DC534;
            }
            break;
    
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B290->unkD0, 1, 1);
}

void UpdateWigglytuffDialogue(void)
{
    char *string;
    struct unkStruct_8092638 uStack_14;

    switch(gUnknown_203B290->state) 
    {
        case 0:
            sub_80222C8();
            sub_8014248(gWigglytuffDialogue[gUnknown_203B290->isAsleep][0],0,gUnknown_203B290->menuAction1,gUnknown_203B290->unk1C,gUnknown_203B290->unk5C,4,0,gUnknown_203B290->unkCC,0xc);
            break;
        case 1:
            sub_80222C8();
            sub_8014248(gWigglytuffDialogue[gUnknown_203B290->isAsleep][1],0,gUnknown_203B290->menuAction1,gUnknown_203B290->unk1C,gUnknown_203B290->unk5C,4,0,gUnknown_203B290->unkCC,0xc);
            break;
        case 7:
            gUnknown_203B290->fallbackState = 9;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][3],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 8:
            gUnknown_203B290->fallbackState = 10;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][4],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 2:
            gUnknown_203B290->fallbackState = 1;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][19],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 3:
            gUnknown_203B290->fallbackState = 4;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][2],0,gUnknown_203B290->unkCC,0x30d);
            break;
        default:
            break;
        case 5:
            gUnknown_203B290->fallbackState = 3;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][8],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 6:
            gUnknown_203B290->fallbackState = 10;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][9],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 0x12:
            gUnknown_203B290->fallbackState = 3;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][10],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 0x13:
            gUnknown_203B290->fallbackState = 10;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][11],0,gUnknown_203B290->unkCC,0x10d); 
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
            sub_8012D60(&gUnknown_203B290->unk6C,gUnknown_203B290->unk1C,0,gUnknown_203B290->unk5C, gUnknown_203B290->menuAction2,2);
            break;
        case 0x11:
            sub_8022420();
            sub_8092578(gUnknown_202E628,gUnknown_203B290->chosenFriendArea,0);
            gUnknown_202DE30[0] = gUnknown_203B290->friendAreaPrice;
            sub_8014248(gWigglytuffDialogue[gUnknown_203B290->isAsleep][5],0,5,gUnknown_203B290->unk1C,0,4,0,gUnknown_203B290->unkCC,0xc);
            break;
        case 0x10:
            sub_8021774(gUnknown_203B290->chosenFriendArea,0,2);
            break;
        case 0xc:
            gUnknown_203B290->fallbackState = 0xd;
            sub_8092578(gUnknown_202E628,gUnknown_203B290->chosenFriendArea,0);
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][6],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 0xd:
            gUnknown_203B290->fallbackState = 0xe;
            PlaySound(0x25b);
            gUnknown_203B290->unk130 = 1;
            break;
        case 0xe:
            gUnknown_203B290->fallbackState = 0xf;
            gUnknown_203B290->unk134 = 0x1e;
            break;
        case 0xf:
            if (sub_8021700(2) != 0) {
                sub_80213A0();
                gUnknown_203B290->fallbackState = 0x12;
            }
            else {
                gUnknown_203B290->fallbackState = 8;
            }
            PlaySound(0xce);
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][7],0,gUnknown_203B290->unkCC,0x10d);
            break;
        case 0x14:
            gUnknown_203B290->fallbackState = 0x16;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][12],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 0x15:
            gUnknown_203B290->fallbackState = 0x17;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][13],0,gUnknown_203B290->unkCC,0x10d); 
            break;
        case 0x16:
            sub_8023144(0,3,0,10);
            break;
        case 0x17:
            sub_8023354(1);
            break;
        case 0x18:
            sub_8092638(gUnknown_203B290->chosenFriendArea,&uStack_14,0,0);
            if (uStack_14.unk4 != 0) {
                gUnknown_203B290->fallbackState = 0x19;
            }
            else
            {
                switch(GetFriendAreaUnlockCondition(gUnknown_203B290->chosenFriendArea))
                {
                    case UNLOCK_SHOP_POST_GAME:
                        if (sub_80023E4(6) != 0) {
                            gUnknown_203B290->fallbackState = 0x15;
                        }
                        else {
                            gUnknown_203B290->fallbackState = 0x1a;
                        }
                        break;
                    case UNLOCK_WONDER_MAIL:
                        gUnknown_203B290->fallbackState = 0x1b;
                        break;
                    case UNLOCK_LEGENDARY_REQUEST:
                        gUnknown_203B290->fallbackState = 0x1c;
                        break;
                    default:
                        gUnknown_203B290->fallbackState = 0x15;
                        break;
                }
            }
            string = GetMonSpecies(gUnknown_203B290->chosenSpecies);
            strcpy(gAvailablePokemonNames,string);
            sub_8092578(gUnknown_202E628,gUnknown_203B290->chosenFriendArea,0);
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][14],0,gUnknown_203B290->unkCC,0x10d);
            break;
        case 0x19:
            gUnknown_203B290->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][15],0,gUnknown_203B290->unkCC,0x10d);
            break;
        case 0x1a:
            gUnknown_203B290->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][16],0,gUnknown_203B290->unkCC,0x10d);
            break;
        case 0x1b:
            gUnknown_203B290->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][17],0,gUnknown_203B290->unkCC,0x10d);
            break;
        case 0x1c:
            gUnknown_203B290->fallbackState = 0x15;
            sub_80141B4(gWigglytuffDialogue[gUnknown_203B290->isAsleep][18],0,gUnknown_203B290->unkCC,0x10d);
            break;
    }
}

void sub_80222C8(void)
{
    s32 i;
    s32 index = 0;
    MemoryFill16(gUnknown_203B290->unk5C, 0, sizeof(gUnknown_203B290->unk5C));
    gUnknown_203B290->unk1C[index].text = *gUnknown_80D4978;
    gUnknown_203B290->unk1C[index].menuAction = 2;
    index++;
    gUnknown_203B290->unk1C[index].text = *gWigglytuffCheck;
    gUnknown_203B290->unk1C[index].menuAction = 3;
    index++;
    gUnknown_203B290->unk1C[index].text = *gUnknown_80D4970;
    gUnknown_203B290->unk1C[index].menuAction = 4;
    index++;
    gUnknown_203B290->unk1C[index].text = *gUnknown_80D4934;
    gUnknown_203B290->unk1C[index].menuAction = 1;
    index++;
    gUnknown_203B290->unk1C[index].text = NULL;
    gUnknown_203B290->unk1C[index].menuAction = 1;

    for(i = 0; i < index; i++)
    {
        if(gUnknown_203B290->unk5C[i] == 0 && gUnknown_203B290->unk1C[i].menuAction == gUnknown_203B290->menuAction1)
            return;
    }
    for(i = 0; i < index; i++)
    {
        if(gUnknown_203B290->unk5C[i] == 0)
        {
            gUnknown_203B290->menuAction1 = gUnknown_203B290->unk1C[i].menuAction;
            break;
        }
    }
}

void sub_8022380(void)
{
    s32 i;
    s32 index = 0;
    MemoryFill16(gUnknown_203B290->unk5C, 0, sizeof(gUnknown_203B290->unk5C));
    gUnknown_203B290->unk1C[index].text = *gUnknown_80D4978;
    gUnknown_203B290->unk1C[index].menuAction = 2;
    index++;
    gUnknown_203B290->unk1C[index].text = *gUnknown_80D4970;
    gUnknown_203B290->unk1C[index].menuAction = 4;
    index++;
    gUnknown_203B290->unk1C[index].text = NULL;
    gUnknown_203B290->unk1C[index].menuAction = 1;

    for(i = 0; i < index; i++)
    {
        if(gUnknown_203B290->unk5C[i] == 0 && gUnknown_203B290->unk1C[i].menuAction == gUnknown_203B290->menuAction2)
            return;
    }
    for(i = 0; i < index; i++)
    {
        if(gUnknown_203B290->unk5C[i] == 0)
        {
            gUnknown_203B290->menuAction2 = gUnknown_203B290->unk1C[i].menuAction;
            break;
        }
    }
}

void sub_8022420(void)
{
    s32 index = 0;
    MemoryFill16(gUnknown_203B290->unk5C, 0, sizeof(gUnknown_203B290->unk5C));
    gUnknown_203B290->unk1C[index].text = *gUnknown_80D4920;
    gUnknown_203B290->unk1C[index].menuAction = 5;
    index++;
    gUnknown_203B290->unk1C[index].text = *gUnknown_80D4928;
    gUnknown_203B290->unk1C[index].menuAction = 6;
    index++;
    gUnknown_203B290->unk1C[index].text = NULL;
    gUnknown_203B290->unk1C[index].menuAction = 1;
}

void sub_8022460(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0)
    {
        if (menuAction != 1) {
            gUnknown_203B290->menuAction1 = menuAction;
        }
        switch(menuAction)
        {
            case 2:
                if (sub_8021700(2) != 0) {
                    UpdateWigglytuffState(5);
                }
                else {
                    UpdateWigglytuffState(7);
                }
                break;
            case 3:
                UpdateWigglytuffState(0x14);
                break;
            case 4:
                UpdateWigglytuffState(2);
                break;
            case 1:
                UpdateWigglytuffState(3);
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
                gTeamInventory_203B460->teamMoney -= gUnknown_203B290->friendAreaPrice;
                UnlockFriendArea(gUnknown_203B290->chosenFriendArea);
                PlaySound(0x14C);
                UpdateWigglytuffState(0xC);
                break;
            case 1:
            case 6:
                UpdateWigglytuffState(0xA);
                break;
        }
    }
}

void sub_8022538(void)
{
    switch(sub_8021274(1))
    {
        case 3:
            gUnknown_203B290->chosenFriendArea = sub_802132C();
            gUnknown_203B290->friendAreaPrice = GetFriendAreaPrice(gUnknown_203B290->chosenFriendArea);
            UpdateWigglytuffState(0xB);
            break;
        case 4:
            gUnknown_203B290->chosenFriendArea = sub_802132C();
            gUnknown_203B290->friendAreaPrice = GetFriendAreaPrice(gUnknown_203B290->chosenFriendArea);
            UpdateWigglytuffState(0x10);
            break;
        case 0:
            break;
        case 2:
            sub_80213A0();
            UpdateWigglytuffState(1);
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
    if(sub_8012FD8(&gUnknown_203B290->unk6C) == 0)
    {
        sub_8013114(&gUnknown_203B290->unk6C, &menuAction);
        if(menuAction != 1) gUnknown_203B290->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        case 2:
            if(gTeamInventory_203B460->teamMoney == 0)
            {
                UpdateWigglytuffState(6);
            }
            else if(gUnknown_203B290->friendAreaPrice > gTeamInventory_203B460->teamMoney)
            {
                UpdateWigglytuffState(0x13);
            }
            else
            {
                UpdateWigglytuffState(0x11);
            }
            break;
        case 4:
            UpdateWigglytuffState(0x10);
            break;
        case 1:
            UpdateWigglytuffState(10);
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
            UpdateWigglytuffState(0xA);
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
            gUnknown_203B290->chosenSpecies = sub_802331C();
            gUnknown_203B290->chosenFriendArea = GetFriendArea(gUnknown_203B290->chosenSpecies);
            UpdateWigglytuffState(0x18);
            break;
        case 2:
            sub_80233A0();
            UpdateWigglytuffState(1);
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
        UpdateWigglytuffState(gUnknown_203B290->fallbackState);
    }
}
