#include "global.h"
#include "constants/communication_error_codes.h"
#include "constants/monster.h"
#include "constants/wonder_mail.h"
#include "text.h"
#include "input.h"
#include "item.h"
#include "team_inventory.h"
#include "pokemon.h"
#include "friend_rescue.h"
#include "memory.h"
#include "save.h"
#include "menu.h"
#include "rescue_password_menu.h"
#include "menu_input.h"
#include "code_8094F88.h"


extern struct TeamInventory *gTeamInventory_203B460;
extern u8 *gUnknown_203B484;

extern void SetFriendRescueMenuState(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_802F2C0();
extern u32 sub_802F298();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern struct WonderMailStruct_203B33C *gUnknown_203B33C;

extern u8 sub_801CF14(u32);

extern u8 gUnknown_80E48A8[];
extern u8 gUnknown_80E49C4[];
extern u8 gUnknown_80E4704[];
extern u8 gUnknown_80E48E8[];
extern u8 gUnknown_80E4928[];
extern u8 gUnknown_80E4964[];
extern u8 gUnknown_80E499C[];
extern u8 gUnknown_80E460C[];
extern u8 gUnknown_80E31FC[];


extern u32 sub_80154F0();
extern void sub_80155F0();
extern void sub_80141B4(u8 *r0, u32, u32 *r1, u32);
extern void sub_8014248(const char *r0, u32, u32, struct MenuItem *r4, u32, u32, u32, u32 *r5, u32);

extern u32 sub_801CA08(u32);
extern void sub_801CBB8(void);
extern void sub_801CB5C(u32);
extern void sub_8035CC0(struct UnkTextStruct2 *, u32);
extern void sub_801B3C0(struct Item *);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
extern void sub_8035CF4(struct MenuStruct *, u32, u32);
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

extern u32 sub_8039068(u32, u8 *r1, struct unkStruct_203B480 *r0);
extern void sub_8095274(u32);
extern void sub_80951BC(struct unkStruct_203B480 *r0);
extern u8 sub_800D588(void);
extern s32 FindOpenMailSlot(void);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);

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
extern u8 gUnknown_80E25F4[];
extern u8 gUnknown_80E2D7C[];
extern u8 gUnknown_80E2E20[];
extern u8 gUnknown_80E319C[];
extern u8 gUnknown_80E311C[];
extern u8 gUnknown_80E32C4[];
extern u8 gUnknown_80E4314[];
extern u8 gUnknown_80E41DC[];
extern u8 gUnknown_80E2FEC[];
extern u8 gUnknown_80E2898[];
extern u8 gUnknown_80E2B54[];
extern u8 gUnknown_80E29D0[];
extern u8 gUnknown_80E3220[];
extern u8 gUnknown_80E2A0C[];
extern u8 gUnknown_80E2610[];
extern u8 gUnknown_80E2640[];
extern u8 gUnknown_80E2680[];
extern u8 gUnknown_80E26B0[];
extern u8 gUnknown_80E26F0[];
extern u8 gUnknown_80E2728[];
extern u8 gUnknown_80E3690[];
extern u8 gUnknown_80E3818[];
extern u8 gUnknown_80E3998[];
extern u8 gUnknown_80E3B1C[];
extern u8 gUnknown_80E367C[];
extern u8 gUnknown_80E3BF8[];
extern u8 gUnknown_80E3DE4[];
extern u8 gUnknown_80E4014[];
extern u8 gUnknown_80E3E98[];
extern u8 gUnknown_80E4130[];
extern u8 gUnknown_80E2E54[];
extern u8 gUnknown_80E2EB4[];
extern u8 gUnknown_80E2DD0[];
extern u8 gUnknown_80E2FA0[];
extern u8 gUnknown_80E2F14[];
extern u8 gUnknown_80E2F44[];
extern u8 gUnknown_80E30A4[];
extern u8 gUnknown_80E2F78[];
extern u8 gUnknown_80E360C[];
extern u8 gUnknown_80E3644[];
extern u8 gUnknown_80E35E8[];
extern u8 gUnknown_80E35AC[];
extern u8 gUnknown_80E355C[];
extern u8 gUnknown_80E352C[];
extern u8 gUnknown_80E34F0[];
extern u8 gUnknown_80E34B0[];
extern u8 gUnknown_80E3430[];
extern u8 gUnknown_80E33D8[];
extern u8 gUnknown_80E339C[];
extern u8 gUnknown_80E3378[];
extern u8 gUnknown_80E331C[];
extern u8 gUnknown_80E3288[];
extern u8 gUnknown_80E3248[];
extern u8 gUnknown_80E31FC[];
extern u8 gUnknown_80E276C[];
extern u8 gUnknown_80E27A4[];
extern u8 gUnknown_80E2CD4[];
extern u8 gUnknown_80E3030[];
extern u8 gUnknown_80E3078[];
extern u8 gUnknown_80E31D8[];
extern u8 gUnknown_80E2CE8[];
extern u8 gUnknown_80E2B90[];
extern u8 gUnknown_80E2AE4[];
extern u8 gUnknown_80E2A80[];
extern u8 gUnknown_80E2AA8[];
extern u8 gUnknown_80E2D60[];
extern u8 gUnknown_80E2BE0[];
extern u8 gUnknown_80E2C48[];
extern u8 gUnknown_80E29A0[];
extern u8 gUnknown_80E2A5C[];
extern u8 gUnknown_80E2904[];
extern u8 gUnknown_80E2C94[];
extern u8 gUnknown_80E2D30[];
extern u8 gUnknown_80E296C[];
extern u8 gUnknown_80E314C[];
extern u8 gUnknown_80E2A1C[];
extern u8 gUnknown_80E2840[];
extern u8 gUnknown_80E2874[];
extern u8 gUnknown_80E317C[];
extern u8 gUnknown_80E28D8[];
extern u8 gUnknown_80E2814[];
extern u8 gUnknown_80E30D0[];

extern struct MenuItem gUnknown_80E20B8;
extern struct MenuItem gUnknown_80E2108;
extern struct MenuItem gUnknown_80E20E0;
extern struct MenuItem gUnknown_80E2068;
extern struct MenuItem gUnknown_80E24F8;
extern struct MenuItem gUnknown_80E2554;
extern struct MenuItem gUnknown_80E22F0;
extern struct MenuItem gUnknown_80E236C;
extern struct MenuItem gUnknown_80E2440;
extern struct MenuItem gUnknown_80E2470;
extern struct MenuItem gUnknown_80E24B0;
extern struct MenuItem gUnknown_80E2130;
extern struct MenuItem gUnknown_80E2190;
extern struct MenuItem gUnknown_80E21B8;
extern struct MenuItem gUnknown_80E2268;
extern struct MenuItem gUnknown_80E2218;
extern struct MenuItem gUnknown_80E2240;
extern struct MenuItem gUnknown_80E2290;
extern struct MenuItem gUnknown_80E22D0;
extern struct MenuItem gUnknown_80E234C;
extern struct MenuItem gUnknown_80E24D8;
extern struct MenuItem gUnknown_80E2458;
extern struct MenuItem gUnknown_80E2408;
extern struct MenuItem gUnknown_80E23A8;
extern struct MenuItem gUnknown_80E22B4;

extern struct UnkTextStruct2 gUnknown_80E231C;
extern struct UnkTextStruct2 gUnknown_80E23F0;
extern struct UnkTextStruct2 gUnknown_80E2334;

extern struct MenuItem gUnknown_80E25B4;

extern void nullsub_40();
extern void sub_8032828();

extern u8 sub_800D588(void);
extern void sub_8011830(void);
extern u32 sub_8030894(void);
extern void sub_8031D70(u32, u32);
extern u32 sub_8023CE8(void);
extern void sub_80922B4(u8 *buffer, u8 *string, s32 size);
extern void sub_80306A8(u32, u32, u32, u32);
extern void sub_8023868(u32, u32, u32, u32);
extern u32 sub_801D008(void);
extern void sub_8023DA4(void);
extern void sub_8023C60(void);
extern s32 sub_8037B28(u32);
extern void sub_803092C(void);
extern void sub_801CCD8(void);
extern void sub_80151C0(u32, u8 *);
extern void sub_801C8C4(u32, u32, s32 * , u32);
extern void xxx_call_start_bg_music(void);
extern u32 GetDungeonTeamRankPts(struct DungeonLocation *, u32);
extern void sub_802F204(struct unkStruct_802F204 *, u32);
extern void nullsub_23(u32);
extern s32 sub_8037D64(u32, void *, void *);
extern s32 sub_80381F4(u32, void *, void *);
void sprintfStatic(char *buffer, const char *text, ...);

extern void SetFriendRescueMenuState(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_802F2C0();
extern u32 sub_802F298();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern struct WonderMailStruct_203B33C *gUnknown_203B33C;

extern u8 sub_8039880(void);

extern void sub_8035300(void);
extern void QueueNextFriendRescueState(u32);
extern void nullsub_41(void);
extern void nullsub_42(void);
extern void nullsub_43(void);
extern void nullsub_44(void);
extern void nullsub_45(void);
extern void nullsub_46(void);
extern void nullsub_47(void);
extern void nullsub_48(void);
extern void nullsub_49(void);
extern void nullsub_50(void);
extern void nullsub_51(void);
extern void sub_8035374(void);
extern void sub_80353BC(void);
extern void sub_8033A2C(void);
extern void sub_803477C(void);
extern void sub_80347AC(void);
extern void sub_80347C8(void);
extern void sub_80347E4(void);
extern void sub_8034804(void);
extern void sub_80344C0(void);
extern void sub_8034478(void);
extern void sub_80344A0(void);
extern void sub_803418C(void);
extern void sub_8034254(void);
extern void sub_8034310(void);
extern void sub_8034378(void);
extern void sub_80343C4(void);
extern void sub_8034404(void);
extern void sub_8034500(void);
extern void sub_8034590(void);
extern void sub_803464C(void);
extern void sub_80346A8(void);
extern void sub_80346D8(void);
extern void sub_8034700(void);
extern void sub_8034720(void);
extern void sub_803473C(void);
extern void sub_8033FB4(void);
extern void sub_8034074(void);
extern void sub_8034130(void);
extern void sub_8033FE4(void);
extern void sub_8033D74(void);
extern void sub_8033D94(void);
extern void sub_8033DBC(void);
extern void sub_8033F64(void);
extern void sub_8033C54(void);
extern void sub_8033CAC(void);
extern void sub_8033D48(void);
extern void sub_8035424(void);
extern void sub_8034970(void);
extern void sub_80351E0(void);
extern void sub_8034D74(void);
extern void sub_8034EF0(void);
extern void sub_8034F38(void);
extern void sub_80352A4(void);
extern void sub_8034EC8(void);
extern void sub_8033B8C(void);
extern void sub_80339C8(void);
extern void sub_80348C4(void);
extern void sub_803482C(void);
extern void sub_80349B0(void);
extern void sub_8034A70(void);
extern void sub_8034B2C(void);
extern void sub_80349E0(void);
extern void sub_8034B88(void);
extern void sub_8034C98(void);
extern void sub_8034C38(void);
extern void sub_8034D54(void);
extern void sub_8034F18(void);
extern void sub_8034F58(void);
extern void sub_8034F88(void);
extern void sub_8035018(void);
extern void sub_8035038(void);
extern void sub_8035094(void);
extern void sub_80350F4(void);
extern void sub_803517C(void);
extern void sub_8035210(void);
extern void sub_8035430(void);
extern void sub_8034848(void);

extern void sub_803084C(void);
extern void sub_8031E10(void);
extern void sub_8023C60(void);
extern void sub_80155F0(void);
extern void sub_801CBB8(void);
extern void sub_802F2C0(void);
extern void sub_8030DE4(void);
extern void sub_802453C(void);
extern void sub_801B450(void);


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
        case COMMS_GOOD:
            break;
        case COMMS_INCORRECT_NUM_SYSTEMS:
            sub_80141B4(gUnknown_80E44A4, 0, 0, 0x101);
            break;
        case COMMS_NO_RESPONSE:
            sub_80141B4(gUnknown_80E4500, 0, 0, 0x101);
            break;
        case COMMS_DIFFERENT_MODES:
            sub_80141B4(gUnknown_80E4550, 0, 0, 0x101);
            break;
        case COMMS_NO_ROOM_STORAGE:
            sub_80141B4(gUnknown_80E45B4, 0, 0, 0x101);
            break;
        case COMMS_DUPLICATE_MAIL:
            sub_80141B4(gUnknown_80E460C, 0, 0, 0x101);
            break;
        case COMMS_MAIL_SENT_ALREADY:
            sub_80141B4(gUnknown_80E4650, 0, 0, 0x101);
            break;
        case COMMS_NOT_ELIGIBLE_1:
            sub_80141B4(gUnknown_80E468C, 0, 0, 0x101);
            break;
        case COMMS_FRIEND_NOT_ELIGIBLE:
            sub_80141B4(gUnknown_80E46C8, 0, 0, 0x101);
            break;
        case COMMS_NOT_ELIGIBLE_2:
            sub_80141B4(gUnknown_80E4704, 0, 0, 0x101);
            break;
        case COMMS_FRIEND_NOT_ELIGIBLE_2:
            sub_80141B4(gUnknown_80E4744, 0, 0, 0x101);
            break;
        case 16:
            sub_80141B4(gUnknown_80E4788, 0, 0, 0x101);
            break;
        case COMMS_NO_ROOM_MAIL:
            sub_80141B4(gUnknown_80E47D8, 0, 0, 0x101);
            break;
        case 1:
        case 5:
        case 14:
            sub_80141B4(gUnknown_80E4480, 0, 0, 0x101);
            break;
        case COMMS_NOT_READY:
            sub_80141B4(gUnknown_80E482C, 0, 0, 0x101);
            break;
    }
}

void sub_80339C8(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        gUnknown_203B33C->speciesNum = -1;
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_EXIT);
                break;
        }
    }
}

void sub_8033A2C(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        gUnknown_203B33C->unk40 = 8;
        switch(menuAction)
        {
            case 0x11:
                gUnknown_203B33C->unk40 = 2;
                gUnknown_203B33C->unk528 = 0x11;
                if(CountMailType(WONDER_MAIL_TYPE_SOS) != 0)
                    SetFriendRescueMenuState(0x31);
                else
                    SetFriendRescueMenuState(0x22);
                break;
            case 3:
                gUnknown_203B33C->unk40 = 3;
                gUnknown_203B33C->unk528 = 3;
                if(FindOpenMailSlot() == -1)
                    SetFriendRescueMenuState(0xF);
                else
                    SetFriendRescueMenuState(0xE);
                break;
            case 4:
                gUnknown_203B33C->unk40 = 4;
                gUnknown_203B33C->unk528 = 4;
                if(CountMailType(WONDER_MAIL_TYPE_AOK) != 0)
                    SetFriendRescueMenuState(0x1C);
                else
                    SetFriendRescueMenuState(0x22);
                break;
            case 0x12:
                gUnknown_203B33C->unk40 = 5;
                gUnknown_203B33C->unk528 = 0x12;
                if(CountMailType(5) != 0)
                    SetFriendRescueMenuState(0x3D);
                else
                    SetFriendRescueMenuState(0xE);
                break;
            case 0x13:
                gUnknown_203B33C->unk40 = 6;
                gUnknown_203B33C->unk528 = 0x13;
                if(CountMailType(5) == 0)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
        }
    }
}

void sub_8033B8C(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
        }
    }
}

void sub_8033C54(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
    u32 speciesNum;
    if(sub_80144A4(&temp) == 0)
    {
        if(gUnknown_203B33C->status == COMMS_GOOD)
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
                        speciesNum = gUnknown_203B33C->unk130.pokemon.speciesNum;
                    else
                        speciesNum = gUnknown_203B33C->unkA8.pokemon.speciesNum;
                    if(speciesNum != MONSTER_NONE)
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
        }
    }
}

void sub_8033D48(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
        PrepareSavePakWrite(MONSTER_NONE);
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
    u32 mailMode;
    struct unkStruct_203B480 mail;
    struct unkStruct_203B480 *mail2;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&mail, 0, sizeof(struct unkStruct_203B480));
    switch(return_var)
    {
        case 3:
                mailMode = 0xffdc;
                switch(gUnknown_203B33C->unk528)
                {
                    case 3:
                        mailMode = PASSWORD_ENTRY_SOS_MAIL_MODE;
                        break;
                    case 0x12:
                        mailMode = PASSWORD_ENTRY_AOK_MAIL_MODE;
                        break;
                    default:
                        break;
                }
                switch(sub_8039068(mailMode, gUnknown_203B33C->passwordBuffer, &mail))
                {
                    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                        sub_8014248(gUnknown_80E48A8, 0, 6, &gUnknown_80E2290, 0, 4, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x1B);
                        break;
                    case PASSWORD_ENTRY_NOT_SOS_MAIL:
                        sub_80141B4(gUnknown_80E48E8, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_SOS_MAIL:
                        sub_80141B4(gUnknown_80E460C, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_SOS_MAIL_SUCCESS:
                        sub_8095274(mail.unk10.unk10);
                        mail.mailType = 2;
                        sub_80951BC(&mail);
                        sub_80141B4(gUnknown_80E4928, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x16);
                        break;
                    case PASSWORD_ENTRY_NOT_AOK_MAIL:
                        sub_80141B4(gUnknown_80E4964, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_AOK_MAIL:
                        sub_80141B4(gUnknown_80E499C, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_AOK_MAIL_SUCCESS:
                        mail.mailType = 5;
                        sub_80951FC(&mail);
                        mail2 = sub_8095228(GetMailIndex(1, mail.unk10.unk10));
                        mail2->mailType = 7;
                        MemoryFill8((u8 *)gUnknown_203B484, 0, sizeof(struct unkStruct_203B484));
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
            break;
        default:
            break;
    }
}

void sub_8033F64(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
            break;
        case 3:
            gUnknown_203B33C->unk218 = sub_80307EC();
            SetFriendRescueMenuState(0x1E);
            break;
        case 4:
            gUnknown_203B33C->fallbackState = 0x1D;
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
    s32 menuAction;

    menuAction = -1;
    sub_8030768(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk21C[3]))
        sub_8013114(&gUnknown_203B33C->unk21C[3], &menuAction);
    switch(menuAction)
    {
        case 9:
            sub_803084C();
            SetFriendRescueMenuState(0x20);
            break;
        case 10:
            gUnknown_203B33C->fallbackState = FRIEND_RESCUE_MENU_DEFAULT_FALLBACK;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x1F);
            break;
        case 5:
        case 8:
            sub_8035CC0(gUnknown_203B33C->unk35C, 2);
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
            if(gUnknown_203B33C->fallbackState == FRIEND_RESCUE_MENU_DEFAULT_FALLBACK)
            {
                sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x1E);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->fallbackState);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
            sub_8035D1C();
            gUnknown_203B33C->speciesNum = -1;
            break;
        case 3:
            gUnknown_203B33C->speciesNum = sub_8023B44();
            if(gUnknown_203B33C->unk524 == 0xE)
                SetFriendRescueMenuState(9);
            else
                SetFriendRescueMenuState(0x27);
            break;
        case 4:
            gUnknown_203B33C->fallbackState = 0x26;
            gUnknown_203B33C->speciesNum = sub_8023B44();
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B33C->speciesNum, 0);
            SetFriendRescueMenuState(0x28);
            break;
    }
}

void sub_8034254(void)
{
    s32 menuAction;
    menuAction = -1;

    sub_8023A94(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk21C[3]))
        sub_8013114(&gUnknown_203B33C->unk21C[3], &menuAction);
    switch(menuAction)
    {
        case 9:
            sub_8023C60();
            SetFriendRescueMenuState(0x29);
            break;
        case 10:
            gUnknown_203B33C->fallbackState = FRIEND_RESCUE_MENU_DEFAULT_FALLBACK;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8024458(gUnknown_203B33C->speciesNum, 0);
            SetFriendRescueMenuState(0x28);
            break;
        case 5:
        case 8:
            sub_8035CC0(gUnknown_203B33C->unk35C, 3);
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
            if(gUnknown_203B33C->fallbackState == FRIEND_RESCUE_MENU_DEFAULT_FALLBACK)
            {
                sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x27);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->fallbackState);
            break;
        default:
            break;
    }
}

void sub_8034378(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 0x10:
                if(gUnknown_203B33C->unk524 == 0xE)
                    SetFriendRescueMenuState(0x9);
                else
                    SetFriendRescueMenuState(0x5);
                break;
            case 8:
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
            default:
                break;
        }
    }
}

void sub_80343C4(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 6:
                SetFriendRescueMenuState(0x5);
                break;
            case 7:
                SetFriendRescueMenuState(0x25);
                break;
            case 8:
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
            default:
                break;
        }
    }
}

void sub_8034404(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_EXIT);
        }
    }
}

void sub_80344A0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x2C);
        PrepareSavePakWrite(MONSTER_NONE);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
            break;
        case 3:
            gUnknown_203B33C->unk218 = sub_80307EC();
            SetFriendRescueMenuState(0x33);
            break;
        case 4:
            gUnknown_203B33C->fallbackState = 0x32;
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
    s32 menuAction;
    menuAction = -1;

    sub_8030768(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk21C[3]))
        sub_8013114(&gUnknown_203B33C->unk21C[3], &menuAction);
    switch(menuAction)
    {
        case 9:
            sub_803084C();
            SetFriendRescueMenuState(0x35);
            break;
        case 10:
            gUnknown_203B33C->fallbackState = FRIEND_RESCUE_MENU_DEFAULT_FALLBACK;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x34);
            break;
        case 5:
        case 8:
            sub_8035CC0(gUnknown_203B33C->unk35C, 2);
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
            if(gUnknown_203B33C->fallbackState == FRIEND_RESCUE_MENU_DEFAULT_FALLBACK)
            {
                sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x33);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->fallbackState);
            break;
        default:
            break;
    }
}

void sub_80346A8(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 6:
                SetFriendRescueMenuState(0xE);
                break;
            case 7:
            case 8:
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_EXIT);
        }
    }
}

void sub_8034700(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x38);
        PrepareSavePakWrite(MONSTER_NONE);
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
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 6:
                SetFriendRescueMenuState(0xE);
                break;
            case 7:
            case 8:
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
        PrepareSavePakWrite(MONSTER_NONE);
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
        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
    }
}


void sub_8034848(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        MemoryFill8((u8 *)&gUnknown_203B33C->item, 0 , sizeof(struct Item));
        gUnknown_203B33C->item.id = ITEM_NOTHING;
        gUnknown_203B33C->item.quantity = 1;
        gUnknown_203B33C->item.flags = 0;

        if(gUnknown_203B33C->status == COMMS_GOOD)
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR_2);
        }
    }
}

void sub_80348C4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        MemoryFill8((u8 *)&gUnknown_203B33C->item, 0 , sizeof(struct Item));
        gUnknown_203B33C->item.id = ITEM_NOTHING;
        gUnknown_203B33C->item.quantity = 1;
        gUnknown_203B33C->item.flags = 0;

        if(gUnknown_203B33C->status == COMMS_GOOD)
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR_2);
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
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 6:
                SetFriendRescueMenuState(0x52);
                break;
            case 7:
            case 8:
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
            break;
        case 3:
            gUnknown_203B33C->unk218 = sub_80307EC();
            SetFriendRescueMenuState(0x5D);
            break;
        case 4:
            gUnknown_203B33C->fallbackState = 0x5C;
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
    s32 menuAction;

    menuAction = -1;
    sub_8030768(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk21C[3]))
        sub_8013114(&gUnknown_203B33C->unk21C[3], &menuAction);
    switch(menuAction)
    {
        case 9:
            sub_803084C();
            SetFriendRescueMenuState(0x5A);
            break;
        case 10:
            gUnknown_203B33C->fallbackState = FRIEND_RESCUE_MENU_DEFAULT_FALLBACK;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B33C->unk218, 0);
            SetFriendRescueMenuState(0x5E);
            break;
        case 5:
        case 8:
            sub_8035CC0(gUnknown_203B33C->unk35C, 2);
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
            if(gUnknown_203B33C->fallbackState == FRIEND_RESCUE_MENU_DEFAULT_FALLBACK)
            {
                sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x5D);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->fallbackState);
            break;
        default:
            break;
    }
}

void sub_8034B88(void)
{
    gUnknown_203B33C->item.id = ITEM_NOTHING;
    gUnknown_203B33C->item.quantity = 1;
    gUnknown_203B33C->item.flags = 0;
    switch(sub_801CA08(1))
    {
        case 2:
            sub_801CBB8();
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
            break;
        case 3:
            gUnknown_203B33C->item.id = sub_801CB24();
            SetFriendRescueMenuState(0x60);
            break;
        case 4:
            gUnknown_203B33C->fallbackState = 0x5F;
            gUnknown_203B33C->item.id = sub_801CB24();
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_801B3C0(&gUnknown_203B33C->item);
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
            if(gUnknown_203B33C->fallbackState == FRIEND_RESCUE_MENU_DEFAULT_FALLBACK)
            {
                sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
                SetFriendRescueMenuState(0x60);
            }
            else
                SetFriendRescueMenuState(gUnknown_203B33C->fallbackState);
            break;
        default:
        case 1:
            break;
    }
}

void sub_8034C98(void)
{
    s32 menuAction;

    menuAction = -1;
    sub_801CA08(0);
    if(!sub_8012FD8(&gUnknown_203B33C->unk21C[3]))
        sub_8013114(&gUnknown_203B33C->unk21C[3], &menuAction);
    switch(menuAction)
    {
        case 9:
            sub_801CBB8();
            SetFriendRescueMenuState(0x58);
            break;
        case 10:
            gUnknown_203B33C->fallbackState = FRIEND_RESCUE_MENU_DEFAULT_FALLBACK;
            sub_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0, 1, 1);
            sub_801B3C0(&gUnknown_203B33C->item);
            SetFriendRescueMenuState(0x61);
            break;
        case 5:
        case 8:
            sub_8035CC0(gUnknown_203B33C->unk35C, 3);
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
        PrepareSavePakWrite(MONSTER_NONE);
    }
}

void sub_8034D74(void)
{
    u32 return_var;
    struct unkStruct_203B480 mail;
    struct unkStruct_203B480 *mail2;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&mail, 0, sizeof(struct unkStruct_203B480));
    switch(return_var)
    {
        case 3:
                switch(sub_8039068(PASSWORD_ENTRY_THANK_YOU_MAIL_MODE, gUnknown_203B33C->passwordBuffer, &mail))
                {
                    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                        sub_8014248(gUnknown_80E48A8, 0, 6, &gUnknown_80E2440, 0, 4, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x74);
                        break;
                    case PASSWORD_ENTRY_NOT_THANK_YOU_MAIL:
                        sub_80141B4(gUnknown_80E49C4, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR_2);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL:
                        sub_80141B4(gUnknown_80E4704, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR_2);
                        break;
                    case PASSWORD_ENTRY_THANK_YOU_MAIL_SUCCESS:
                        mail2 = sub_8095228(GetMailIndex(4, mail.unk10.unk10));
                        *mail2 = mail;
                        mail2->mailType = 6;
                        gUnknown_203B33C->unk420 = mail.unk10.unk10;
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_EXIT);
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
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_EXIT);
        }
    }
}

void sub_8034F18(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x65);
        PrepareSavePakWrite(MONSTER_NONE);
    }
}

void sub_8034F38(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        SetFriendRescueMenuState(0x71);
        PrepareSavePakWrite(MONSTER_NONE);
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
        }
    }
}

void sub_8034F88(void)
{
    s32 menuAction;
    struct unkStruct_203B480 *mail;

    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 6:
                mail = sub_8095228(gUnknown_203B33C->unk218);
                if(gUnknown_203B33C->item.id != ITEM_NOTHING)
                    mail->unk20 = gUnknown_203B33C->item;
                gTeamInventory_203B460->teamStorage[gUnknown_203B33C->item.id]--;
                SetFriendRescueMenuState(0x75);
                break;
            case 7:
                SetFriendRescueMenuState(0x57);
                break;
            case 8:
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
        PrepareSavePakWrite(MONSTER_NONE);
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
    s32 menuAction;

    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
            default:
                break;
        }
    }
}

void sub_80350F4(void)
{
    s32 menuAction;

    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
            default:
                break;
        }
    }
}

void sub_803517C(void)
{
    s32 menuAction;

    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
            default:
                break;
        }
    }
}

void sub_80351E0(void)
{
    s32 menuAction;

    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 6:
                SetFriendRescueMenuState(0x72);
                break;
            case 8:
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
                break;
            default:
                break;
        }
    }
}

void sub_8035210(void)
{
    s32 menuAction;
    struct unkStruct_203B480 *mail;

    if(sub_80144A4(&menuAction) == 0)
    {
        // NOTE: this is why unk524 can't be changed to u32..
        gUnknown_203B33C->unk524 = menuAction;
        switch(gUnknown_203B33C->unk524)
        {
            case 0xB:
            case 0xC:
            case 0xD:
                if(gUnknown_203B33C->unk528 == 0x13)
                {
                    mail = sub_8095228(GetFirstIndexofMailType(5));
                    if(mail->unk20.id != ITEM_NOTHING)
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
                SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
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
  u8 mailIndex;
  char *monName;

  if ( sub_802F298() == 3) {
    sub_802F2C0();
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PELIPPER);
    monName = GetMonSpecies(MONSTER_PELIPPER);
    strcpy(gAvailablePokemonNames, monName);
    mailIndex = GetMailIndex(6, gUnknown_203B33C->unk420);
    DeleteMailAtIndex(mailIndex);
    SetFriendRescueMenuState(0x70);
  }
}

void sub_8035300(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) != 0)
        return;
    switch(menuAction)
    {
        case 0x19:
            SetFriendRescueMenuState(FRIEND_RESCUE_MENU_MAIN);
            break;
        case 0x1B:
            SetFriendRescueMenuState(0x7A);
            break;
        case 0x1C:
            SetFriendRescueMenuState(0x7C);
            break;
        case 0x1A:
        case 0x1D:
            gUnknown_203B33C->unk564 = menuAction;
            SetFriendRescueMenuState(0x79);
            break;
    }
}

void sub_8035374(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) != 0)
        return;
    switch(menuAction)
    {
        case 0x19:
            SetFriendRescueMenuState(0x78);
            break;
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
            gUnknown_203B33C->unk564 = menuAction;
            SetFriendRescueMenuState(0x7B);
            break;
    }
}

void sub_80353BC(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) != 0)
        return;
    switch(menuAction)
    {
        case 0x19:
            SetFriendRescueMenuState(0x78);
            break;
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
            gUnknown_203B33C->unk564 = menuAction;
            SetFriendRescueMenuState(0x7D);
            break;
    }
}

void QueueNextFriendRescueState(u32 nextState)
{
  s32 iVar1;

  if(sub_80144A4(&iVar1) == 0){
    SetFriendRescueMenuState(nextState);
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
