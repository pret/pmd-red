#include "global.h"
#include "text.h"
#include "pokemon.h"
#include "save.h"
#include "memory.h"
#include "input.h"
#include "team_inventory.h"
#include "friend_rescue.h"
#include "sub_8095228.h"
#include "item.h"

extern struct TeamInventory *gTeamInventory_203B460;
extern u8 *gUnknown_203B484;

extern void SetFriendRescueMenuState(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_802F2C0();
extern u8 sub_809539C(u32, u32);
extern void sub_8095240(u8);
extern u32 sub_802F298();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern struct WonderMailStruct_203B33C *gUnknown_203B33C;

extern u8 sub_80953D4(u32);
extern u8 sub_801CF14(u32);

extern u8 gUnknown_80E48A8[];
extern struct MenuItem gUnknown_80E2440[];
extern u8 gUnknown_80E49C4[];
extern u8 gUnknown_80E4704[];
extern u8 gUnknown_80E48E8[];
extern u8 gUnknown_80E4928[];
extern u8 gUnknown_80E4964[];
extern u8 gUnknown_80E499C[];
extern u8 gUnknown_80E460C[];
extern struct MenuItem gUnknown_80E2290[];
extern u8 gUnknown_80E31FC[];


extern u32 sub_80154F0();
extern void sub_80155F0();
struct unkStruct_8095228 *sub_8095228(u8);
extern void sub_80141B4(u8 *r0, u32, u32 *r1, u32);
extern void sub_8014248(const char *r0, u32, u32, struct MenuItem *r4, u32, u32, u32, u32 *r5, u32);

extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, s32 *);
extern u32 sub_801CA08(u32);
extern void sub_801CBB8(void);
extern void sub_801CB5C(u32);
extern void sub_8035CC0(u32 *, u32);
extern void sub_801B3C0(struct ItemSlot *);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
extern void sub_8035CF4(u32 *, u32, u32);
extern u8 sub_801CB24(void);
extern u32 sub_8030DA0(void);
extern void sub_8030DE4(void);
extern void sub_803092C(void);
extern u32 sub_8030768(u32);
extern void sub_803084C(void);
extern void sub_8030D40(u8, u32);
extern void sub_8030810(u32);
extern u8 sub_80307EC(void);

extern u32 sub_8031DCC(void);
extern void sub_8031E10(void);
extern void sub_8031E00(void);
extern u8 sub_8024108(u32);
extern void sub_802452C(void);
extern u32 sub_80244E4(void);
extern void sub_802453C(void);
extern void sub_8023B7C(u32);
extern u32 sub_8023A94(u32);
extern void sub_8023C60(void);
extern void sub_8024458(s16, u32);
extern void sub_8023DA4(void);
extern void sub_8035D1C(void);
extern u16 sub_8023B44(void);

extern u32 sub_8039068(u32, u8 *r1, u8 *r0);
extern void sub_8095274(u32);
extern void sub_80951BC(u8 *r0);
extern void sub_80951FC(u8 *r0);
extern u8 sub_809539C(u32, u32);
extern u8 sub_800D588(void);
extern u32 sub_8095324(u32);
extern s32 sub_8095190(void);

extern u8 gUnknown_80E44A4[];
extern u8 gUnknown_80E4500[];
extern u8 gUnknown_80E4550[];
extern u8 gUnknown_80E45B4[];
extern u8 gUnknown_80E460C[];
extern u8 gUnknown_80E4650[];
extern u8 gUnknown_80E468C[];
extern u8 gUnknown_80E46C8[];
extern u8 gUnknown_80E4704[];
extern u8 gUnknown_80E4744[];
extern u8 gUnknown_80E4788[];
extern u8 gUnknown_80E47D8[]; 
extern u8 gUnknown_80E4480[];
extern u8 gUnknown_80E482C[];


extern void nullsub_40();
extern void sub_8032828();

void SetFriendRescueMenuState(u32 newState)
{
    gUnknown_203B33C->state = newState;
    nullsub_40();
    sub_8032828();
}

void PrintFriendRescueError(u32 status)
{
    switch(status)
    {
        case 0:
            break;
        case 3:
            sub_80141B4(gUnknown_80E44A4, 0, 0, 0x101);
            break;
        case 2:
            sub_80141B4(gUnknown_80E4500, 0, 0, 0x101);
            break;
        case 4:
            sub_80141B4(gUnknown_80E4550, 0, 0, 0x101);
            break;
        case 6:
            sub_80141B4(gUnknown_80E45B4, 0, 0, 0x101);
            break;
        case 7:
            sub_80141B4(gUnknown_80E460C, 0, 0, 0x101);
            break;
        case 8:
            sub_80141B4(gUnknown_80E4650, 0, 0, 0x101);
            break;
        case 9:
            sub_80141B4(gUnknown_80E468C, 0, 0, 0x101);
            break;
        case 10:
            sub_80141B4(gUnknown_80E46C8, 0, 0, 0x101);
            break;
        case 11:
            sub_80141B4(gUnknown_80E4704, 0, 0, 0x101);
            break;
        case 12:
            sub_80141B4(gUnknown_80E4744, 0, 0, 0x101);
            break;
        case 16:
            sub_80141B4(gUnknown_80E4788, 0, 0, 0x101);
            break;
        case 13:
            sub_80141B4(gUnknown_80E47D8, 0, 0, 0x101);
            break;
        case 1:
        case 5:
        case 14:
            sub_80141B4(gUnknown_80E4480, 0, 0, 0x101);
            break;
        case 15:
            sub_80141B4(gUnknown_80E482C, 0, 0, 0x101);
            break;
    }
}

void sub_80339C8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        gUnknown_203B33C->unk538 = -1;
        switch(temp)
        {
            case 0:
                SetFriendRescueMenuState(3);
                break;
            case 1:
                SetFriendRescueMenuState(4);
                break;
            case 0x17:
                SetFriendRescueMenuState(0x78);
                break;
            case 0x8:
                SetFriendRescueMenuState(2);
                break;
        }
    }
}

void sub_8033A2C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        gUnknown_203B33C->unk40 = 8;
        switch(temp)
        {
            case 0x11:
                gUnknown_203B33C->unk40 = 2;
                gUnknown_203B33C->unk528 = 0x11;
                if(sub_8095324(1) != 0)
                    SetFriendRescueMenuState(0x31);
                else
                    SetFriendRescueMenuState(0x22);
                break;
            case 3:
                gUnknown_203B33C->unk40 = 3;
                gUnknown_203B33C->unk528 = 3;
                if(sub_8095190() == -1)
                    SetFriendRescueMenuState(0xF);
                else
                    SetFriendRescueMenuState(0xE);
                break;
            case 4:
                gUnknown_203B33C->unk40 = 4;
                gUnknown_203B33C->unk528 = 4;
                if(sub_8095324(4) != 0)
                    SetFriendRescueMenuState(0x1C);
                else
                    SetFriendRescueMenuState(0x22);
                break;
            case 0x12:
                gUnknown_203B33C->unk40 = 5;
                gUnknown_203B33C->unk528 = 0x12;
                if(sub_8095324(5) != 0)
                    SetFriendRescueMenuState(0x3D);
                else
                    SetFriendRescueMenuState(0xE);
                break;
            case 0x13:
                gUnknown_203B33C->unk40 = 6;
                gUnknown_203B33C->unk528 = 0x13;
                if(sub_8095324(5) == 0)
                    SetFriendRescueMenuState(0x51);
                else
                    SetFriendRescueMenuState(0x5B);
                break;
            case 0x14:
                gUnknown_203B33C->unk40 = 7;
                gUnknown_203B33C->unk528 = 0x14;
                SetFriendRescueMenuState(0x52);
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
        }
    }
}

void sub_8033B8C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
                case 0xB:
                case 0xC:
                    gUnknown_203B33C->unk524 = 0xB;
                    switch(gUnknown_203B33C->unk528)
                    {
                        case 3:
                        case 0x11:
                        case 0x12:
                            SetFriendRescueMenuState(5);
                            break;
                        case 4:
                            SetFriendRescueMenuState(0x23);
                            break;
                        default:
                            break;
                    }
                break;
            case 0xD:
                gUnknown_203B33C->unk524 = 0xD;
                switch(gUnknown_203B33C->unk528)
                {
                    case 3:
                        SetFriendRescueMenuState(0x19);
                        break;
                    case 0x11:
                        SetFriendRescueMenuState(0x39);
                        break;
                    case 0x12:
                        SetFriendRescueMenuState(0x43);
                        break;
                    case 4:
                        SetFriendRescueMenuState(0x2D);
                        break;
                    default:
                        break;
                }
                break;
            case 8:
                SetFriendRescueMenuState(1);
                break;
        }
    }
}

void sub_8033C54(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                switch(gUnknown_203B33C->unk528)
                {
                    // NOTE: Each case has to be defined to match
                    case 3:
                        SetFriendRescueMenuState(0xD);
                        break;
                    case 4:
                        SetFriendRescueMenuState(0xD);
                        break;
                    case 0x11:
                        SetFriendRescueMenuState(0xD);
                        break;
                    case 0x12:
                        SetFriendRescueMenuState(0xD);
                        break;
                    default:
                        break;
                }
                break;
            case 8:
                SetFriendRescueMenuState(1);
                break;
        }
    }
}

void nullsub_41(void)
{
}

void sub_8033CAC(void)
{
    s32 temp;
    u32 test_var;
    if(sub_80144A4(&temp) == 0)
    {
        if(gUnknown_203B33C->status == 0)
        {
            switch(gUnknown_203B33C->unk528)
            {
                case 3:
                    SetFriendRescueMenuState(0x16);
                    break;
                case 0x11:
                    SetFriendRescueMenuState(0x37);
                    break;
                case 0x12:
                    if(sub_800D588() != 0)
                        test_var = gUnknown_203B33C->unk168;
                    else
                        test_var = gUnknown_203B33C->unkE0;
                    if(test_var != 0)
                        SetFriendRescueMenuState(0x3F);
                    else
                        SetFriendRescueMenuState(0x40);
                    break;
                case 4:
                    SetFriendRescueMenuState(0x2B);
                    break;

            }
        }
        else
        {
            PrintFriendRescueError(gUnknown_203B33C->status);
            SetFriendRescueMenuState(8);
        }
    }
}

void sub_8033D48(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(1);
    }
}

void nullsub_42(void)
{
}

void nullsub_43(void)
{
}

void nullsub_44(void)
{
}

void nullsub_45(void)
{
}

void sub_8033D74(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x17);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8033D94(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetFriendRescueMenuState(0x18);
        }
    }
}

void sub_8033DBC(void)
{
    u32 return_var;
    u32 input_var;
    struct unkStruct_8095228 temp;
    struct unkStruct_8095228 *temp2;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&temp, 0, sizeof(struct unkStruct_8095228));
    switch(return_var)
    {
        case 3:
                input_var = 0xffdc;
                switch(gUnknown_203B33C->unk528)
                {
                    case 3:
                        input_var = 0x1C;
                        break;
                    case 0x12:
                        input_var = 0x1E;
                        break;
                    default:
                        break;
                }
                switch(sub_8039068(input_var, gUnknown_203B33C->passwordBuffer, &temp.unk0))
                {
                    case 17:
                        sub_8014248(gUnknown_80E48A8, 0, 6, gUnknown_80E2290, 0, 4, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x1B);
                        break;
                    case 18:
                        sub_80141B4(gUnknown_80E48E8, 0, 0, 0x101);
                        SetFriendRescueMenuState(8);
                        break;
                    case 7:
                        sub_80141B4(gUnknown_80E460C, 0, 0, 0x101);
                        SetFriendRescueMenuState(8);
                        break;
                    case 22:
                        sub_8095274(temp.unk10);
                        temp.unk0 = 2; // Some sort of Ack?
                        sub_80951BC(&temp.unk0);
                        sub_80141B4(gUnknown_80E4928, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x16);
                        break;
                    case 19:
                        sub_80141B4(gUnknown_80E4964, 0, 0, 0x101);
                        SetFriendRescueMenuState(8);
                        break;
                    case 9:
                        sub_80141B4(gUnknown_80E499C, 0, 0, 0x101);
                        SetFriendRescueMenuState(8);
                        break;
                    case 23:
                        temp.unk0 = 5; // Some sort of Ack?
                        sub_80951FC(&temp.unk0);
                        temp2 = sub_8095228(sub_809539C(1, temp.unk10));
                        temp2->unk0 = 7;
                        MemoryFill8((u8 *)gUnknown_203B484, 0, 0x5C);
                        SetFriendRescueMenuState(0x40);
                        break;
                    case 24:
                    default:
                        break;
                }
            sub_80155F0();
            break;
        case 2:
            sub_80155F0();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            SetFriendRescueMenuState(1);
            break;
        default:
            break;
    }
}

void sub_8033F64(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                switch(gUnknown_203B33C->unk528)
                {
                    case 3:
                        SetFriendRescueMenuState(0x19);
                        break;
                    case 0x12:
                        SetFriendRescueMenuState(0x43);
                        break;
                }
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_8033FB4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                SetFriendRescueMenuState(0xE);
                break;
            case 7:
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_8033FE4(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            SetFriendRescueMenuState(1);
            break;
        case 3:
            gUnknown_203B33C->unk218 = sub_80307EC();
            SetFriendRescueMenuState(0x1E);
            break;
        case 4:
            gUnknown_203B33C->unk4 = 0x1D;
            gUnknown_203B33C->unk218 = sub_80307EC();
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x1F);
            break;
    }
}

void sub_8034074(void)
{
    s32 temp;

    temp = -1;
    sub_8030768(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk30C))
        sub_8013114(&gUnknown_203B33C->unk30C, &temp);
    switch(temp)
    {
        case 9:
            sub_803084C();
            SetFriendRescueMenuState(0x20);
            break;
        case 10:
            gUnknown_203B33C->unk4 = 0x7E;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x1F);
            break;
        case 5:
        case 8:
            sub_8035CC0(&gUnknown_203B33C->unk35C, 2);
            sub_8030810(0x1);
            SetFriendRescueMenuState(0x1D);
            break;
    }
}

void sub_8034130(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            sub_803092C();
            if(gUnknown_203B33C->unk4 == 0x7E)
            {
                sub_8035CF4(&gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x1E);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->unk4);
            break;
        default:
            break;
    }
}

void sub_803418C(void)
{
    switch(sub_8023A94(1))
    {
        case 2:
            sub_8023C60();
            SetFriendRescueMenuState(1);
            sub_8035D1C();
            gUnknown_203B33C->unk538 = -1;
            break;
        case 3:
            gUnknown_203B33C->unk538 = sub_8023B44();
            if(gUnknown_203B33C->unk524 == 0xE)
                SetFriendRescueMenuState(9);
            else
                SetFriendRescueMenuState(0x27);
            break;
        case 4:
            gUnknown_203B33C->unk4 = 0x26;
            gUnknown_203B33C->unk538 = sub_8023B44();
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B33C->unk538, 0);
            SetFriendRescueMenuState(0x28);
            break;
    }
}

void sub_8034254(void)
{
    s32 temp;
    temp = -1;

    sub_8023A94(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk30C))
        sub_8013114(&gUnknown_203B33C->unk30C, &temp);
    switch(temp)
    {
        case 9:
            sub_8023C60();
            SetFriendRescueMenuState(0x29);
            break;
        case 10:
            gUnknown_203B33C->unk4 = 0x7E;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B33C->unk538, 0);
            SetFriendRescueMenuState(0x28);
            break;
        case 5:
        case 8:
            sub_8035CC0(&gUnknown_203B33C->unk35C, 3);
            sub_8023DA4();
            SetFriendRescueMenuState(0x26);
            break;
    }
}

void sub_8034310(void)
{
    switch(sub_80244E4())
    {
        case 1:
            sub_802452C();
            break;
        case 2:
        case 3:
            sub_802453C();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            sub_8023B7C(1);
            if(gUnknown_203B33C->unk4 == 0x7E)
            {
                sub_8035CF4(&gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x27);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->unk4);
            break;
        default:
            break;
    }
}

void sub_8034378(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0x10:
                if(gUnknown_203B33C->unk524 == 0xE)
                    SetFriendRescueMenuState(0x9);
                else
                    SetFriendRescueMenuState(0x5);
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_80343C4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                SetFriendRescueMenuState(0x5);
                break;
            case 7:
                SetFriendRescueMenuState(0x25);
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_8034404(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0xF:
                if(sub_8024108(3))
                    SetFriendRescueMenuState(0x24);
                else
                    SetFriendRescueMenuState(0x25);
                break;
            case 0x10:
                if(gUnknown_203B33C->unk524 == 0xE)
                    SetFriendRescueMenuState(0x9);
                else
                    SetFriendRescueMenuState(0x5);
                break;
            case 0x8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_8034478(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetFriendRescueMenuState(0x2);
        }
    }
}

void sub_80344A0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x2C);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_80344C0(void)
{
    switch(sub_8031DCC())
    {
        case 2:
        case 3:
            sub_8031E10();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            SetFriendRescueMenuState(0x2F);
            break;
        case 1:
            sub_8031E00();
            break;
        case 0:
            break;
    }
}

void sub_8034500(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            SetFriendRescueMenuState(1);
            break;
        case 3:
            gUnknown_203B33C->unk218 = sub_80307EC();
            SetFriendRescueMenuState(0x33);
            break;
        case 4:
            gUnknown_203B33C->unk4 = 0x32;
            gUnknown_203B33C->unk218 = sub_80307EC();
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x34);
            break;
    }
}

void sub_8034590(void)
{
    s32 temp;
    temp = -1;

    sub_8030768(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk30C))
        sub_8013114(&gUnknown_203B33C->unk30C, &temp);
    switch(temp)
    {
        case 9:
            sub_803084C();
            SetFriendRescueMenuState(0x35);
            break;
        case 10:
            gUnknown_203B33C->unk4 = 0x7E;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x34);
            break;
        case 5:
        case 8:
            sub_8035CC0(&gUnknown_203B33C->unk35C, 2);
            sub_8030810(0x1);
            SetFriendRescueMenuState(0x32);
            break;
    }
}

void sub_803464C(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            sub_803092C();
            if(gUnknown_203B33C->unk4 == 0x7E)
            {
                sub_8035CF4(&gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x33);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->unk4);
            break;
        default:
            break;
    }
}

void sub_80346A8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                SetFriendRescueMenuState(0xE);
                break;
            case 7:
            case 8:
                SetFriendRescueMenuState(1);
                break;
        }
    }
}

void sub_80346D8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetFriendRescueMenuState(0x2);
        }
    }
}

void sub_8034700(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x38);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034720(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x3A);
    }
}

void sub_803473C(void)
{
    switch(sub_8031DCC())
    {
        case 2:
        case 3:
            sub_8031E10();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            SetFriendRescueMenuState(0x3B);
            break;
        case 1:
            sub_8031E00();
            break;
        case 0:
            break;
    }
}

void sub_803477C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                SetFriendRescueMenuState(0xE);
                break;
            case 7:
            case 8:
                SetFriendRescueMenuState(1);
                break;
        }
    }
}

void sub_80347AC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0xD);
    }
}

void sub_80347C8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x40);
    }
}

void sub_80347E4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x41);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034804(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetFriendRescueMenuState(0x42);
        }
    }
}

void sub_803482C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(1);
    }
}


void sub_8034848(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        MemoryFill8((u8 *)&gUnknown_203B33C->unk41C, 0 , 4);
        gUnknown_203B33C->unk41C.itemIndex = ITEM_ID_NOTHING;
        gUnknown_203B33C->unk41C.numItems = 1;
        gUnknown_203B33C->unk41C.unk0 = 0;

        if(gUnknown_203B33C->status == 0)
        {
            switch(gUnknown_203B33C->unk40)
            {
                case 7:
                    SetFriendRescueMenuState(0x6D);
                    break;
                case 6:
                    SetFriendRescueMenuState(0x50);
                    break;
            }
        }
        else
        {
            PrintFriendRescueError(gUnknown_203B33C->status);
            SetFriendRescueMenuState(0x6B);
        }
    }
}

void sub_80348C4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        MemoryFill8((u8 *)&gUnknown_203B33C->unk41C, 0 , 4);
        gUnknown_203B33C->unk41C.itemIndex = ITEM_ID_NOTHING;
        gUnknown_203B33C->unk41C.numItems = 1;
        gUnknown_203B33C->unk41C.unk0 = 0;

        if(gUnknown_203B33C->status == 0)
        {
            switch(gUnknown_203B33C->unk40)
            {
                case 6:
                    switch((u32)gUnknown_203B33C->unk524)
                    {
                        case 0xB:
                        case 0xD:
                        case 0xE:
                            sub_80141B4(gUnknown_80E31FC, 0, 0, 0x101);
                            SetFriendRescueMenuState(0x77);
                            break;
                        case 0xC:
                        default:
                            SetFriendRescueMenuState(0x77);
                            break;
                    }
                break;
            case 7:
                SetFriendRescueMenuState(0x6D);
                break;
            }
        }
        else
        {
            PrintFriendRescueError(gUnknown_203B33C->status);
            SetFriendRescueMenuState(0x6B);
        }
    }
}

void sub_8034970(void)
{
    switch(sub_8031DCC())
    {
        case 2:
        case 3:
            sub_8031E10();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            SetFriendRescueMenuState(0x68);
            break;
        case 1:
            sub_8031E00();
            break;
        case 0:
            break;
    }
}

void sub_80349B0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                SetFriendRescueMenuState(0x52);
                break;
            case 7:
            case 8:
                SetFriendRescueMenuState(1);
                break;
        }
    }
}

void sub_80349E0(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            SetFriendRescueMenuState(1);
            break;
        case 3:
            gUnknown_203B33C->unk218 = sub_80307EC();
            SetFriendRescueMenuState(0x5D);
            break;
        case 4:
            gUnknown_203B33C->unk4 = 0x5C;
            gUnknown_203B33C->unk218 = sub_80307EC();
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x5E);
            break;
    }
}

void sub_8034A70(void)
{
    s32 temp;

    temp = -1;
    sub_8030768(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk30C))
        sub_8013114(&gUnknown_203B33C->unk30C, &temp);
    switch(temp)
    {
        case 9:
            sub_803084C();
            SetFriendRescueMenuState(0x5A);
            break;
        case 10:
            gUnknown_203B33C->unk4 = 0x7E;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x5E);
            break;
        case 5:
        case 8:
            sub_8035CC0(&gUnknown_203B33C->unk35C, 2);
            sub_8030810(0x1);
            SetFriendRescueMenuState(0x5C);
            break;
    }
}

void sub_8034B2C(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            sub_803092C();
            if(gUnknown_203B33C->unk4 == 0x7E)
            {
                sub_8035CF4(&gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x5D);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->unk4);
            break;
        default:
            break;
    }
}

void sub_8034B88(void)
{
    gUnknown_203B33C->unk41C.itemIndex = ITEM_ID_NOTHING;
    gUnknown_203B33C->unk41C.numItems = 1;
    gUnknown_203B33C->unk41C.unk0 = 0;
    switch(sub_801CA08(1))
    {
        case 2:
            sub_801CBB8();
            SetFriendRescueMenuState(1);
            break;
        case 3:
            gUnknown_203B33C->unk41C.itemIndex = sub_801CB24();
            SetFriendRescueMenuState(0x60);
            break;
        case 4:
            gUnknown_203B33C->unk4 = 0x5F;
            gUnknown_203B33C->unk41C.itemIndex = sub_801CB24();
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_801B3C0(&gUnknown_203B33C->unk41C);
            SetFriendRescueMenuState(0x61);
            break;
    }
}

void sub_8034C38(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            sub_801CB5C(1);
            if(gUnknown_203B33C->unk4 == 0x7E)
            {
                sub_8035CF4(&gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x60);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->unk4);
            break;
        default:
        case 1:
            break;
    }
}

void sub_8034C98(void)
{
    s32 temp;

    temp = -1;
    sub_801CA08(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk30C))
        sub_8013114(&gUnknown_203B33C->unk30C, &temp);
    switch(temp)
    {
        case 9:
            sub_801CBB8();
            SetFriendRescueMenuState(0x58);
            break;
        case 10:
            gUnknown_203B33C->unk4 = 0x7E;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_801B3C0(&gUnknown_203B33C->unk41C);
            SetFriendRescueMenuState(0x61);
            break;
        case 5:
        case 8:
            sub_8035CC0(&gUnknown_203B33C->unk35C, 3);
            sub_801CB5C(0x1);
            SetFriendRescueMenuState(0x5F);
            break;
    }
}

void sub_8034D54(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x65);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034D74(void)
{
    u32 return_var;
    struct unkStruct_8095228 temp;
    struct unkStruct_8095228 *temp2;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&temp, 0, sizeof(struct unkStruct_8095228));
    switch(return_var)
    {
        case 3:
                switch(sub_8039068(0x20, gUnknown_203B33C->passwordBuffer, &temp.unk0))
                {
                    case 17:
                        sub_8014248(gUnknown_80E48A8, 0, 6, gUnknown_80E2440, 0, 4, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x74);
                        break;
                    case 20:
                        sub_80141B4(gUnknown_80E49C4, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x6B);
                        break;
                    case 11:
                        sub_80141B4(gUnknown_80E4704, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x6B);
                        break;
                    case 24:
                        temp2 = sub_8095228(sub_809539C(4, temp.unk10));
                        *temp2 = temp;
                        temp2->unk0 = 6; // Some sort of Ack?
                        gUnknown_203B33C->unk420 = temp.unk10;
                        SetFriendRescueMenuState(0x6D);
                        break;
                    case 7:
                    default:
                        break;
                }
            sub_80155F0();
            break;
        case 2:
            sub_80155F0();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            SetFriendRescueMenuState(1);
            break;
        default:
            break;
    }
}

void sub_8034EC8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetFriendRescueMenuState(2);
        }
    }
}

void sub_8034EF0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetFriendRescueMenuState(2);
        }
    }
}

void sub_8034F18(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x65);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034F38(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x71);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034F58(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                SetFriendRescueMenuState(0x62);
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
        }
    }
}

void sub_8034F88(void)
{
    s32 temp;
    struct unkStruct_8095228 *temp2;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                temp2 = sub_8095228(gUnknown_203B33C->unk218);
                if(gUnknown_203B33C->unk41C.itemIndex != ITEM_ID_NOTHING)
                    temp2->unk20 = gUnknown_203B33C->unk41C;
                gTeamInventory_203B460->teamStorage[gUnknown_203B33C->unk41C.itemIndex]--;
                SetFriendRescueMenuState(0x75);
                break;
            case 7:
                SetFriendRescueMenuState(0x57);
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
        }
    }
}

void sub_8035018(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x76);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8035038(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak()){
            FinishWriteSavePak();
            // Dumb cast to get unsigned switch
            switch((u32)gUnknown_203B33C->unk524)
            {
                default:
                    break;
                case 0xB:
                case 0xC:
                    SetFriendRescueMenuState(0x69);
                    break;
                case 0xD:
                    SetFriendRescueMenuState(0x66);
                    break;
                case 0xE:
                    SetFriendRescueMenuState(0x4B);
                    break;
            }
        }
    }
}

void sub_8035094(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0x16:
                // Dumb cast to get unsigned switch
                switch((u32)gUnknown_203B33C->unk524)
                {
                    default:
                        break;
                    case 0xB:
                    case 0xC:
                        SetFriendRescueMenuState(0x69);
                        break;
                    case 0xD:
                        SetFriendRescueMenuState(0x66);
                        break;
                    case 0xE:
                        SetFriendRescueMenuState(0x4B);
                        break;
                }
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_80350F4(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0x15:
                if(sub_801CF14(0) != 0)
                    SetFriendRescueMenuState(0x56);
                else
                    SetFriendRescueMenuState(0x57);
                break;
            case 0x16:
                // Dumb cast to get unsigned switch
                switch((u32)gUnknown_203B33C->unk524)
                {
                    default:
                        break;
                    case 0xB:
                    case 0xC:
                        SetFriendRescueMenuState(0x69);
                        break;
                    case 0xD:
                        SetFriendRescueMenuState(0x66);
                        break;
                    case 0xE:
                        SetFriendRescueMenuState(0x4B);
                        break;
                }
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_803517C(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                // Dumb cast to get unsigned switch
                switch((u32)gUnknown_203B33C->unk524)
                {
                    default:
                        break;
                    case 0xB:
                    case 0xC:
                        SetFriendRescueMenuState(0x69);
                        break;
                    case 0xD:
                        SetFriendRescueMenuState(0x66);
                        break;
                    case 0xE:
                        SetFriendRescueMenuState(0x4B);
                        break;
                }
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_80351E0(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                SetFriendRescueMenuState(0x72);
                break;
            case 8:
                SetFriendRescueMenuState(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_8035210(void)
{
    s32 temp;
    struct unkStruct_8095228 *temp2;

    if(sub_80144A4(&temp) == 0)
    {
        // NOTE: this is why unk524 can't be changed to u32..
        gUnknown_203B33C->unk524 = temp;
        switch(gUnknown_203B33C->unk524)
        {
            case 0xB:
            case 0xC:
            case 0xD:
                if(gUnknown_203B33C->unk528 == 0x13)
                {
                    temp2 = sub_8095228(sub_80953D4(5));
                    if(temp2->unk20.itemIndex != ITEM_ID_NOTHING)
                        SetFriendRescueMenuState(0x53);
                    else
                        SetFriendRescueMenuState(0x55);
                }
                else if(gUnknown_203B33C->unk524 != 0xD)
                    SetFriendRescueMenuState(0x69);
                else
                    SetFriendRescueMenuState(0x72);
                break;
            case 8:
                SetFriendRescueMenuState(1);
                break;
            case 0xE:
            default:
                break;
        }
    }
}

void nullsub_46(void)
{
}

void nullsub_47(void)
{
}

void nullsub_48(void)
{
}

void nullsub_49(void)
{
}

void sub_80352A4(void)
{
  u8 uVar1;
  char *monName;

  if ( sub_802F298() == 3) {
    sub_802F2C0();
    CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_PELIPPER);
    monName = GetMonSpecies(SPECIES_PELIPPER);
    strcpy(gAvailablePokemonNames, monName);
    uVar1 = sub_809539C(6, gUnknown_203B33C->unk420);
    sub_8095240(uVar1);
    SetFriendRescueMenuState(0x70);
  }
}

void sub_8035300(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            SetFriendRescueMenuState(1);
            break;
        case 0x1B:
            SetFriendRescueMenuState(0x7A);
            break;
        case 0x1C:
            SetFriendRescueMenuState(0x7C);
            break;
        case 0x1A:
        case 0x1D:
            gUnknown_203B33C->unk564 = temp;
            SetFriendRescueMenuState(0x79);
            break;
    }
}

void sub_8035374(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            SetFriendRescueMenuState(0x78);
            break;
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
            gUnknown_203B33C->unk564 = temp;
            SetFriendRescueMenuState(0x7B);
            break;
    }
}

void sub_80353BC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            SetFriendRescueMenuState(0x78);
            break;
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
            gUnknown_203B33C->unk564 = temp;
            SetFriendRescueMenuState(0x7D);
            break;
    }
}

void sub_8035404(u32 param_1)
{
  s32 iVar1;

  if(sub_80144A4(&iVar1) == 0){
    SetFriendRescueMenuState(param_1);
  }
}

void sub_8035424(void)
{
    SetFriendRescueMenuState(6);
}

void sub_8035430(void)
{
    SetFriendRescueMenuState(0x4F);
}

void nullsub_50(void)
{
}

void nullsub_51(void)
{
}
