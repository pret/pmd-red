#include "global.h"
#include "save.h"
#include "pokemon.h"
#include "file_system.h"
#include "item.h"
#include "sub_8095228.h"
#include "wonder_mail.h"
#include "memory.h"
#include "menu.h"
#include "text.h"
#include "team_inventory.h"

extern struct WonderMailStruct_203B2C0 *gUnknown_203B2C0;
extern struct TeamInventory *gTeamInventory_203B460;

extern u32 sub_80144A4(s32 *r0);
extern void sub_8011C28(u32);
extern void sub_8095240(u8);

extern void sub_809927C(u8);
extern u8 sub_8030C20(u32);
extern u32 sub_8031050();
extern void sub_80310B4();
extern u32 sub_8095350();
extern u8 sub_80A2824(u8);

#include "data/wonder_mail_1.h"

extern u8 sub_809539C(u32, u32);

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];
extern struct MenuItem gUnknown_80DDA48[];

extern s32 sub_8095190(void);
extern u32 sub_8095324(u32);
extern void sub_80141B4(const char *r0, u32, u32 *r1, u32);
extern void nullsub_130(void);
extern void sub_8028348(void);
extern void ResetUnusedInputStruct();
extern void sub_803084C();
extern u32 sub_8030768(u32);
extern s8 sub_80307EC();
extern void sub_8030D40(u8, u32);
extern u8 sub_8012FD8(u32 *r0);
extern void sub_8030810(u32);
extern void sub_8035CC0(struct UnkTextStruct2 *r0, u32);
extern void sub_8035CF4(u32 *r0, u32, u32);
extern u32 sub_8030DA0(void);
extern void sub_8030DE4(void);
extern void sub_803092C(void);

extern u32 sub_80154F0();
extern u32 sub_8039068(u32, u8 *r1, u8 *r0);
extern void sub_8014248(const char *r0, u32, u32, struct MenuItem *r4, u32, u32, u32, u32 *r5, u32);
extern void sub_8095274(u32);
extern void sub_80155F0();
extern void sub_80951BC(u8 *r0);
extern void sub_8013114(u32 *r0, s32 *r1);
extern void sub_8023C60();
extern u32 sub_8023A94(u32);
extern void sub_8024458(s16, u32);
extern u16 sub_8023B44();
extern void sub_8023B7C(u32);
extern u32 sub_80244E4();
extern void sub_802452C();
extern void sub_802453C();
extern u8 sub_8024108(u32);
extern u32 sub_8031DCC();
extern void sub_8031E10();
extern void sub_8031E00();
extern u16 gUnknown_80E5990[];
extern s32 sub_8001658(u32, u32);
extern u32 gUnknown_80E4A40[];
extern u8 sub_8099B94();

extern void sub_8099A5C(u32, u32, u32*);
extern void sub_8099AFC(u32, u32, u32*);
extern void ResetUnusedInputStruct();
extern void sub_8099690(u32);


extern void sub_8031E10(void);
extern void sub_803084C(void);
extern void sub_8030DE4();


void sub_8028B04(u32 r0)
{
    gUnknown_203B2C0->state = r0;
    nullsub_130();
    sub_8028348();
}

// Wonder Mail Linking...
void sub_8028B1C(u32 r0)
{
    switch(r0)
    {
        case 0:
            break;
        case 1:
        case 2:
            sub_80141B4(gWonderMailErrorText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 3:
            sub_80141B4(gWonderMailNumGBAsText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 4:
            sub_80141B4(gWonderMailWrongModeText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 5:
            sub_80141B4(gWonderMailErrorText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 6:
            sub_80141B4(gWonderMailStorageFullText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 7:
            sub_80141B4(gWonderMailDuplicateText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 8:
            break;
        case 9:
            sub_80141B4(gWonderMailNotEligibleReceiveText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 10:
            break;
        case 11:
            sub_80141B4(gWonderMailNotEligibleReceiveText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 12:
            break;
        case 13:
            sub_80141B4(gWonderMailNoRoomText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 14:
            sub_80141B4(gWonderMailErrorText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 15:
            sub_80141B4(gWonderMailFriendErrorText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
            break;
        default:
            break;
    }
}

void sub_8028BF0(void)
{
    u32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    gUnknown_203B2C0->unk40 = 8;
    gUnknown_203B2C0->unk544 = -1;
    switch(temp)
    {
        case 0:
            gUnknown_203B2C0->unk40 = 3;
            gUnknown_203B2C0->unk538 = 0;
            if(sub_8095190() != -1)
            {
                sub_8028B04(8);
            }
            else
            {
                sub_8028B04(9);
            }
            break;
        case 1:
            if(sub_8095324(2) != 0)
            {
                sub_8028B04(30);
            }
            else
            {
                sub_8028B04(26);
            }
            break;
        case 2:
            gUnknown_203B2C0->unk40 = 4;
            gUnknown_203B2C0->unk538 = 2;
            if(sub_8095324(4) != 0)
            {
                sub_8028B04(41);
            }
            else
            {
                sub_8028B04(47);
            }
            break;
        case 3:
            sub_8028B04(11);
            break;
        case 10:
            sub_8028B04(2);
            break;
        default:
            break;
    }
}


void sub_8028CE0()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(3);
}

void sub_8028CFC()
{
    s32 temp;
    u32 temp2;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(sub_8031050())
    {
        case 2:
        case 3:
            temp2 = sub_8095350();
            sub_80310B4();
            if(temp2 != gUnknown_203B2C0->unk540)
            {
                sub_8028B04(23);
            }
            else
            {
                sub_8028B04(25);
            }
            break;
        default:
            break;
    }
}

void sub_8028D4C()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    gUnknown_203B2C0->unk538 = temp;
    switch(gUnknown_203B2C0->unk538)
    {
        case 5:
            if(sub_8030C20(2) != 0)
            {
                sub_8028B04(12);
            }
            else
            {
                sub_8028B04(13);
            }
            break;
        case 6:
            if(sub_8030C20(4) != 0)
            {
                sub_8028B04(14);
            }
            else
            {
                sub_8028B04(15);
            }
            break;
        case 7:
            if(sub_8030C20(0) != 0)
            {
                sub_8028B04(16);
            }
            else
            {
                sub_8028B04(17);
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028DE8(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(r0);
}

void sub_8028E08()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(18);
}

void sub_8028E24()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(19);
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E54()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(20);
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E84()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(24);
    sub_8011C28(1);
    PrepareSavePakWrite(SPECIES_NONE);
}

void sub_8028EAC()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        FinishWriteSavePak();
        sub_8028B04(25);
    }
}

void sub_8028ED4()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp){
        case 8:
            sub_8028B04(11);
            break;
        case 9:
        case 10:
            sub_8028B04(2);
            break;
        default:
            break;
    }
}

void sub_8028F04()
{
    s32 temp;
    s32 counter;

    if(sub_80144A4(&temp) == 0)
    {
        for(counter = 0; counter <= 31; counter++)
        {
            sub_8095240(counter);
        }
        sub_8028B04(21);
    }
}

void sub_8028F30()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(22);
    sub_8011C28(1);
    PrepareSavePakWrite(SPECIES_NONE);
}

void sub_8028F58()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        FinishWriteSavePak();
        sub_8028B04(2);
    }
}

void sub_8028F80()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_809927C(gUnknown_203B2C0->unk218);
    gUnknown_203B2C0->unk53C = 1;
    sub_8028B04(3);
}

void sub_8028FC0()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8028FDC(void)
{
    s32 temp;
    struct unkStruct_8095228 *return_var;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            return_var = sub_8095228(gUnknown_203B2C0->unk218);
            if(sub_80A2824(return_var->unk4) == 0)
            {
                sub_8028B04(0x1C);
            }
            else
            {
                if(return_var->unk2C <= 0)
                {
                    sub_8028B04(0x1D);
                }
                else
                {
                    sub_8028B04(0x1B);
                }
            }
            break;
        case 9:
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8029044(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            sub_8028B04(1);
            break;
        case 3:
            gUnknown_203B2C0->unk218 = sub_80307EC();
            sub_8028B04(32);
            break;
        case 4:
            gUnknown_203B2C0->unk0 = 0x1F;
            gUnknown_203B2C0->unk218 = sub_80307EC();
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->unk218, 0);
            sub_8028B04(33);
            break;
    }
}

void sub_80290D4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(31);
}

void sub_80290F0(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8030768(0);
    if(sub_8012FD8(&(gUnknown_203B2C0->unk30C)) == 0)
    {
        sub_8013114(&(gUnknown_203B2C0->unk30C), &menuAction);
    }
    switch(menuAction)
    {
        case 11:
            sub_803084C();
            sub_8028B04(34);
            break;
        case 12:
            gUnknown_203B2C0->unk0 = 0x3D;
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->unk218, 0);
            sub_8028B04(33);
            break;
        case 4:
        case 10:
            sub_8035CC0(gUnknown_203B2C0->unk35C, 2);
            sub_8030810(1);
            sub_8028B04(31);
            break;
        default:
            break;
    }
}

void sub_80291AC(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_803092C();
            if(gUnknown_203B2C0->unk0 == 0x3D)
            {
                sub_8035CF4(&(gUnknown_203B2C0->unk21C), 3, 1);
                sub_8028B04(0x20);
            }
            else
            {
                sub_8028B04(gUnknown_203B2C0->unk0);
            }
        default:
            break;
    }
}

void sub_8029208(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {

        case 13:
        case 14:
            gUnknown_203B2C0->unk534 = 13;
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8028B04(4);
                    break;
                case 2:
                    sub_8028B04(0x30);
                    break;
                default:
                    return;
            }
            break;
        case 15:
            gUnknown_203B2C0->unk534 = 15;
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8028B04(0x26);
                    break;
                case 2:
                    sub_8028B04(0x3A);
                    break;
                default:
                    return;
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_80292A4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                case 2:
                    sub_8028B04(5);
                    break;
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_80292EC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(gUnknown_203B2C0->linkError == 0)
    {
        switch(gUnknown_203B2C0->unk538)
        {
            case 0:
                sub_8028B04(0x23);
                break;
            case 2:
                sub_8028B04(0x37);
                break;
        }
    }
    else
    {
        sub_8028B1C(gUnknown_203B2C0->linkError);
        sub_8028B04(0x7);
    }
}

void sub_802933C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8029358(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8029374(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x24);
    sub_8011C28(1);
    PrepareSavePakWrite(SPECIES_NONE);
}

void sub_802939C(void)
{
    s32 temp;
    u32 saveStatus;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        saveStatus = GetSavePakStatus();
        FinishWriteSavePak();
        if(saveStatus == SAVE_COMPLETED)
        {
            sub_8028B04(0x25);
        }
        else
        {
            sub_8028B04(0x2);
        }
    }
}

void sub_80293D8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x27);
}

// TODO: pls look into this later - Sese
void sub_80293F4(void)
{
    u32 return_var;
    struct unkStruct_8095228 temp;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&temp, 0, sizeof(struct unkStruct_8095228));
    switch(return_var)
    {
        case 3:
                switch(sub_8039068(0x1C, (gUnknown_203B2C0->passwordBuffer), &temp.unk0))
                {
                    case 17:
                        sub_8014248(gWonderMailPasswordIncorrectText, 0, 8, gUnknown_80DDA48, 0, 4, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0xC);
                        sub_8028B04(40);
                        break;
                    case 18:
                        sub_80141B4(gWonderMailSOSPasswordIncorrectText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
                        sub_8028B04(7);
                        break;
                    case 7:
                        sub_80141B4(gWonderMailDuplicateText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x10d);
                        sub_8028B04(7);
                        break;
                    case 22:
                        sub_8095274(temp.unk10);
                        temp.unk0 = 2; // Some sort of Ack?
                        sub_80951BC(&temp.unk0);
                        sub_80141B4(gWonderMailAOKMailReceivedText, 0, (u32 *)&gUnknown_203B2C0->faceFile, 0x101);
                        sub_8028B04(35);
                        break;
                    case 23:
                    case 24:
                    default:
                        break;
                }
            sub_80155F0();
            break;
        case 2:
            sub_80155F0();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_802955C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(0x26);
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_802958C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(6);
}

void sub_80295A8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(0x8);
            break;
        case 9:
        case 10:
            sub_8028B04(1);
            break;

    }
}

void sub_80295D8(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            sub_8028B04(1);
            break;
        case 3:
            gUnknown_203B2C0->unk218 = sub_80307EC();
            sub_8028B04(0x2B);
            break;
        case 4:
            gUnknown_203B2C0->unk0 = 0x2A;
            gUnknown_203B2C0->unk218 = sub_80307EC();
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->unk218, 0);
            sub_8028B04(0x2C);
            break;
    }
}

void sub_8029668(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x2A);
}

void sub_8029684(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8030768(0);
    if(sub_8012FD8(&(gUnknown_203B2C0->unk30C)) == 0)
    {
        sub_8013114(&(gUnknown_203B2C0->unk30C), &menuAction);
    }
    switch(menuAction)
    {
        case 0xB:
            sub_803084C();
            sub_8028B04(0x2D);
            break;
        case 0xC:
            gUnknown_203B2C0->unk0 = 0x3D;
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->unk218, 0);
            sub_8028B04(0x2C);
            break;
        case 0x4:
        case 0xA:
            sub_8035CC0(gUnknown_203B2C0->unk35C,2);
            sub_8030810(1);
            sub_8028B04(0x2A);
            break;
    }
}

void sub_8029740(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_803092C();
            if(gUnknown_203B2C0->unk0 == 0x3D)
            {
                sub_8035CF4(&(gUnknown_203B2C0->unk21C), 3, 1);
                sub_8028B04(0x2B);
            }
            else
            {
                sub_8028B04(gUnknown_203B2C0->unk0);
            }
            break;
    }
}

void sub_802979C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_80297B8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x33);
}

void sub_80297D4(void)
{
    switch(sub_8023A94(1))
    {
        case 2:
            sub_8023C60();
            sub_8028B04(1);
            gUnknown_203B2C0->unk544 = -1;
            break;
        case 3:
            gUnknown_203B2C0->unk544 = sub_8023B44();
            sub_8028B04(0x34);
            break;
        case 4:
            gUnknown_203B2C0->unk0 = 0x33;
            gUnknown_203B2C0->unk544 = sub_8023B44();
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B2C0->unk544, 0);
            sub_8028B04(0x35);
            break;
    }
}

void sub_8029884(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8023A94(0);
    if(sub_8012FD8(&(gUnknown_203B2C0->unk30C)) == 0)
    {
        sub_8013114(&(gUnknown_203B2C0->unk30C), &menuAction);
    }
    switch(menuAction)
    {
        case 0xB:
            sub_8023C60();
            sub_8028B04(4);
            break;
        case 0xC:
            gUnknown_203B2C0->unk0 = 0x3D;
            sub_8006518(gUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B2C0->unk544, 0);
            sub_8028B04(0x35);
            break;
        case 0x4:
        case 0xA:
            sub_8035CC0(gUnknown_203B2C0->unk35C, 3);
            sub_8023B7C(1);
            sub_8028B04(0x33);
            break;
    }
}

void sub_8029944(void)
{
    u32 temp;
    temp = sub_80244E4();
    if(temp == 1)
    {
            sub_802452C();
            return;
    }
    switch(temp)
    {
        case 1:
            break;
        case 2:
        case 3:
            sub_802453C();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_8023B7C(1);
            if(gUnknown_203B2C0->unk0 == 0x3D)
            {
                sub_8035CF4(&(gUnknown_203B2C0->unk21C), 3, 1);
                sub_8028B04(0x34);
            }
            else
            {
                sub_8028B04(gUnknown_203B2C0->unk0);
            }

    }
}

void sub_80299AC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 0x12:
            sub_8028B04(4);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_80299D8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {

        case 8:
            sub_8028B04(4);
            break;
        case 9:
            sub_8028B04(0x32);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
    }
}

void sub_8029A18(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 0x11:
            if(sub_8024108(3) != 0)
            {
                sub_8028B04(0x31);
            }
            else
            {
                sub_8028B04(0x32);
            }
            break;
        case 0x12:
            sub_8028B04(0x4);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
    }
}

void sub_8029A6C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x2E);
}

void sub_8029A88(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(!WriteSavePak())
    {
        FinishWriteSavePak();
        sub_8028B04(0x39);
    }
}

void sub_8029AB0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x38);
    sub_8011C28(1);
    PrepareSavePakWrite(SPECIES_NONE);
}

void sub_8029AD8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x3B);
}

void sub_8029AF4(void)
{
    switch(sub_8031DCC())
    {

        case 2:
        case 3:
            sub_8031E10();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B2C0->unk3BC, 1, 1);
            sub_8028B04(0x3C);
            break;
        case 1:
            sub_8031E00();
            break;
    }
}

void sub_8029B34(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(3);
}
