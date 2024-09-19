#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801B3C0.h"
#include "code_801C8C4.h"
#include "code_8023868.h"
#include "code_8024458.h"
#include "code_802F204.h"
#include "code_8094F88.h"
#include "constants/communication_error_codes.h"
#include "constants/monster.h"
#include "constants/wonder_mail.h"
#include "cpu.h"
#include "friend_rescue.h"
#include "input.h"
#include "items.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus2.h"
#include "pokemon.h"
#include "save_write.h"
#include "rescue_password_menu.h"
#include "text_util.h"
#include "text1.h"
#include "text2.h"
#include "wonder_mail_4.h"
#include "wonder_mail_5.h"

extern void SetFriendRescueMenuState(u32);

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];
extern TeamInventory *gTeamInventoryRef;


// NOTE: MenuItems and UnkTextStruct2 defined in here..
#include "data/friend_rescue_menus.h"

const u8 gUnknown_80E25F4[] = "What would you like to do?";

ALIGNED(4) const u8 gUnknown_80E2610[] = _(
        "How would you like to send your\n"
        "{COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const u8 gUnknown_80E2640[] = _(
        "How would you like to receive your\n"
        "friend{APOSTROPHE}s {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const u8 gUnknown_80E2680[] = _(
        "How would you like to send your\n"
        "{COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const u8 gUnknown_80E26B0[] = _(
        "How would you like to receive your\n"
        "friend{APOSTROPHE}s {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const u8 gUnknown_80E26F0[] = _(
        "How would you like to send your\n"
        "{COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const u8 gUnknown_80E2728[] = _(
        "How would you like to receive your\n"
        "friend{APOSTROPHE}s {COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1}?");

ALIGNED(4) const u8 gUnknown_80E276C[] = _(
        "The GBA Game Pak does not have\n"
        "an {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} on it.");

ALIGNED(4) const u8 gUnknown_80E27A4[] = _(
        "If you accept an {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1}{COMMA} the\n"
        "{COLOR_1 LIGHT_BLUE}Thank-You Mail{END_COLOR_TEXT_1} you received before\n"
        "will be overwritten. Is that OK?");

ALIGNED(4) const u8 gUnknown_80E2814[] = _(
        "Please enter the {COLOR_1 LIGHT_BLUE}A-OK Mail password{END_COLOR_TEXT_1}.");

ALIGNED(4) const u8 gUnknown_80E2840[] = _(
        "The {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} will be received and\n"
        "processed.");

ALIGNED(4) const u8 gUnknown_80E2874[] = _(
        "A {COLOR_1 LIGHT_BLUE}helper Pokémon{END_COLOR_TEXT_1} also arrived!");

ALIGNED(4) const u8 gUnknown_80E2898[] = _(
        "An {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} was received.\n"
        "Your adventure will be saved.");

ALIGNED(4) const u8 gUnknown_80E28D8[] = _(
        "Resume your game using {COLOR_1 LIGHT_BLUE}Revive Team{END_COLOR_TEXT_1}.");

ALIGNED(4) const u8 gUnknown_80E2904[] = _(
        "Your friend{APOSTROPHE}s Mailbox is full.\n"
        "This piece of mail cannot be sent.\n"
        "The recipient must delete old mail.");

ALIGNED(4) const u8 gUnknown_80E296C[] = _(
        "Please choose the {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1} you want\n"
        "to send.");

ALIGNED(4) const u8 gUnknown_80E29A0[] = _(
        "This {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1} will be sent.\n"
        "Is that OK?");

ALIGNED(4) const u8 gUnknown_80E29D0[] = _(
        "Your {COLOR_1 LIGHT_BLUE}SOS Mail{END_COLOR_TEXT_1} was sent.\n"
        "Your adventure will be saved.");

ALIGNED(4) const u8 gUnknown_80E2A0C[] = "Save completed.";

ALIGNED(4) const u8 gUnknown_80E2A1C[] = _(
        "Please give this password to the friend\n"
        "coming to your rescue.");

ALIGNED(4) const u8 gUnknown_80E2A5C[] = _(
        "Here is the {COLOR_1 LIGHT_BLUE}SOS Mail password{END_COLOR_TEXT_1}.");

ALIGNED(4) const u8 gUnknown_80E2A80[] = _(
        "Here is the {COLOR_1 LIGHT_BLUE}A-OK Mail password{END_COLOR_TEXT_1}.");

ALIGNED(4) const u8 gUnknown_80E2AA8[] = _(
"Please give this password to the friend\n"
"that you rescued.");

ALIGNED(4) const u8 gUnknown_80E2AE4[] = _(
"Please connect a {COLOR_1 LIGHT_BLUE}Link Cable{END_COLOR_TEXT_1}.\n"
"When your friend{APOSTROPHE}s side is ready{COMMA} you may\n"
"communicate and exchange data.");

ALIGNED(4) const u8 gUnknown_80E2B54[] = _(
"Your {COLOR_1 LIGHT_BLUE}A-OK Mail{END_COLOR_TEXT_1} was sent.\n"
"Your adventure will be saved.");

ALIGNED(4) const u8 gUnknown_80E2B90[] = _(
"Using a {COLOR_1 LIGHT_BLUE}Game Link cable{END_COLOR_TEXT_1}{COMMA}\n"
"you can send a {COLOR_1 LIGHT_BLUE}helper Pokémon{END_COLOR_TEXT_1} to\n"
"a friend.");

extern u8 gUnknown_80E2BE0[];
extern u8 gUnknown_80E2C48[];
extern u8 gUnknown_80E2C94[];
extern u8 gUnknown_80E2CD4[];
extern u8 gUnknown_80E2CE8[];
extern u8 gUnknown_80E2D30[];
extern u8 gUnknown_80E2D60[];
extern u8 gUnknown_80E2D7C[];
extern u8 gUnknown_80E2DD0[];
extern u8 gUnknown_80E2E20[];
extern u8 gUnknown_80E2E54[];
extern u8 gUnknown_80E2EB4[];
extern u8 gUnknown_80E2F14[];
extern u8 gUnknown_80E2F44[];
extern u8 gUnknown_80E2F78[];
extern u8 gUnknown_80E2FA0[];
extern u8 gUnknown_80E2FEC[];
extern u8 gUnknown_80E3030[];
extern u8 gUnknown_80E3078[];
extern u8 gUnknown_80E30A4[];
extern u8 gUnknown_80E30D0[];
extern u8 gUnknown_80E311C[];
extern u8 gUnknown_80E314C[];
extern u8 gUnknown_80E317C[];
extern u8 gUnknown_80E319C[];
extern u8 gUnknown_80E31D8[];
extern u8 gUnknown_80E31FC[];
extern u8 gUnknown_80E31FC[];
extern u8 gUnknown_80E3220[];
extern u8 gUnknown_80E3248[];
extern u8 gUnknown_80E3288[];
extern u8 gUnknown_80E32C4[];
extern u8 gUnknown_80E331C[];
extern u8 gUnknown_80E3378[];
extern u8 gUnknown_80E339C[];
extern u8 gUnknown_80E33D8[];
extern u8 gUnknown_80E3430[];
extern u8 gUnknown_80E34B0[];
extern u8 gUnknown_80E34F0[];
extern u8 gUnknown_80E352C[];
extern u8 gUnknown_80E355C[];
extern u8 gUnknown_80E35AC[];
extern u8 gUnknown_80E35E8[];
extern u8 gUnknown_80E360C[];
extern u8 gUnknown_80E3644[];
extern u8 gUnknown_80E367C[];
extern u8 gUnknown_80E3690[];
extern u8 gUnknown_80E3818[];
extern u8 gUnknown_80E3998[];
extern u8 gUnknown_80E3B1C[];
extern u8 gUnknown_80E3BF8[];
extern u8 gUnknown_80E3DE4[];
extern u8 gUnknown_80E3E98[];
extern u8 gUnknown_80E4014[];
extern u8 gUnknown_80E4130[];
extern u8 gUnknown_80E41DC[];
extern u8 gUnknown_80E4314[];
extern u8 gUnknown_80E4480[];
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
extern u8 gUnknown_80E482C[];
extern u8 gUnknown_80E48A8[];
extern u8 gUnknown_80E48E8[];
extern u8 gUnknown_80E4928[];
extern u8 gUnknown_80E4964[];
extern u8 gUnknown_80E499C[];
extern u8 gUnknown_80E49C4[];

EWRAM_DATA_2 WonderMailStruct_203B33C *gUnknown_203B33C = {0};

extern u8 sub_8039880(void);

void sub_8035300(void);
void QueueNextFriendRescueState(u32);
void nullsub_41(void);
void nullsub_42(void);
void nullsub_43(void);
void nullsub_44(void);
void nullsub_45(void);
void nullsub_46(void);
void nullsub_47(void);
void nullsub_48(void);
void nullsub_49(void);
void nullsub_50(void);
void nullsub_51(void);
void sub_80339C8(void);
void sub_8033A2C(void);
void sub_8033B8C(void);
void sub_8033C54(void);
void sub_8033CAC(void);
void sub_8033D48(void);
void sub_8033D74(void);
void sub_8033D94(void);
void sub_8033DBC(void);
void sub_8033F64(void);
void sub_8033FB4(void);
void sub_8033FE4(void);
void sub_8034074(void);
void sub_8034130(void);
void sub_803418C(void);
void sub_8034254(void);
void sub_8034310(void);
void sub_8034378(void);
void sub_80343C4(void);
void sub_8034404(void);
void sub_8034478(void);
void sub_80344A0(void);
void sub_80344C0(void);
void sub_8034500(void);
void sub_8034590(void);
void sub_803464C(void);
void sub_80346A8(void);
void sub_80346D8(void);
void sub_8034700(void);
void sub_8034720(void);
void sub_803473C(void);
void sub_803477C(void);
void sub_80347AC(void);
void sub_80347C8(void);
void sub_80347E4(void);
void sub_8034804(void);
void sub_803482C(void);
void sub_8034848(void);
void sub_80348C4(void);
void sub_8034970(void);
void sub_80349B0(void);
void sub_80349E0(void);
void sub_8034A70(void);
void sub_8034B2C(void);
void sub_8034B88(void);
void sub_8034C38(void);
void sub_8034C98(void);
void sub_8034D54(void);
void sub_8034D74(void);
void sub_8034EC8(void);
void sub_8034EF0(void);
void sub_8034F18(void);
void sub_8034F38(void);
void sub_8034F58(void);
void sub_8034F88(void);
void sub_8035018(void);
void sub_8035038(void);
void sub_8035094(void);
void sub_80350F4(void);
void sub_803517C(void);
void sub_80351E0(void);
void sub_8035210(void);
void sub_80352A4(void);
void sub_8035374(void);
void sub_80353BC(void);
void sub_8035424(void);
void sub_8035430(void);

extern u32 sub_8031DCC(void);
extern void sub_8031E00(void);
extern u32 sub_8039068(u32, u8 *passwordBuffer, unkStruct_203B480 *r0);

extern void sub_8031E10(void);
extern u8 sub_800D588(void);
extern u32 sub_8023CE8(void);
extern bool8 sub_8031D70(u32 mailIndex, s32);
extern s32 sub_8037B28(u32);

extern u32 GetDungeonTeamRankPts(DungeonLocation *, u32);
extern void sprintfStatic(char *buffer, const char *text, ...);

u32 CreateFriendRescueMenu(void)
{
  char *monName;
  int counter;

  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
  gUnknown_203B33C = MemoryAlloc(sizeof(WonderMailStruct_203B33C), 8);
  MemoryFill8((u8 *) gUnknown_203B33C, 0, sizeof(WonderMailStruct_203B33C));
  gUnknown_203B33C->unk530 = 0;
  gUnknown_203B33C->unk218 = -1;
  gUnknown_203B33C->speciesNum = -1;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PELIPPER);
  monName = GetMonSpecies(MONSTER_PELIPPER);
  strcpy(gAvailablePokemonNames,monName);
  for(counter = 0; counter < 0x36; counter++){
    gUnknown_203B33C->passwordBuffer[counter] = 0;
  }
  gUnknown_203B33C->fallbackState = FRIEND_RESCUE_MENU_DEFAULT_FALLBACK;
  gUnknown_203B33C->unk52C = sub_8039880();
  gUnknown_203B33C->unk52D = gUnknown_203B33C->unk52C;
  SetFriendRescueMenuState(FRIEND_RESCUE_MENU_INIT);
  return 1;
}

u32 UpdateFriendRescueMenu(void)
{
  switch(gUnknown_203B33C->state)
  {
    case 0x78:
        sub_8035300();
        break;
    case 0x79:
        QueueNextFriendRescueState(0x78);
        break;
    case 0x7A:
        sub_8035374();
        break;
    case 0x7B:
        QueueNextFriendRescueState(0x7a);
        break;
    case 0x7C:
        sub_80353BC();
        break;
    case 0x7D:
        QueueNextFriendRescueState(0x7c);
        break;
    case 3:
    case 4:
        sub_8033A2C();
        break;
    case 0x3D:
        sub_803477C();
        break;
    case 0x3E:
        sub_80347AC();
        break;
    case 0x3F:
        sub_80347C8();
        break;
    case 0x40:
        sub_80347E4();
        break;
    case 0x41:
        sub_8034804();
        break;
    case 0x2D:
        QueueNextFriendRescueState(0x2e);
        break;
    case 0x2E:
        sub_80344C0();
        break;
    case 0x2A:
        QueueNextFriendRescueState(0xd);
        break;
    case 0x2C:
        sub_8034478();
        break;
    case 0x2B:
        sub_80344A0();
        break;
    case 0x25:
        QueueNextFriendRescueState(0x26);
        break;
    case 0x26:
        sub_803418C();
        break;
    case 0x27:
        sub_8034254();
        break;
    case 0x28:
        sub_8034310();
        break;
    case 0x24:
        sub_8034378();
        break;
    case 0x29:
        sub_80343C4();
        break;
    case 0x23:
        QueueNextFriendRescueState(0x21);
        break;
    case 0x21:
        sub_8034404();
        break;
    case 0x31:
        QueueNextFriendRescueState(0x32);
        break;
    case 0x32:
        sub_8034500();
        break;
    case 0x33:
        sub_8034590();
        break;
    case 0x34:
        sub_803464C();
        break;
    case 0x35:
        sub_80346A8();
        break;
    case 0x38:
        sub_80346D8();
        break;
    case 0x37:
        sub_8034700();
        break;
    case 0x39:
        sub_8034720();
        break;
    case 0x3A:
        sub_803473C();
        break;
    case 0x20:
        sub_8033FB4();
        break;
    case 0x1C:
        QueueNextFriendRescueState(0x1d);
        break;
    case 0x1E:
        sub_8034074();
        break;
    case 0x1F:
        sub_8034130();
        break;
    case 0x1D:
        sub_8033FE4();
        break;
    case 0x11:
        QueueNextFriendRescueState(0x12);
        break;
    case 0x12:
        nullsub_42();
        break;
    case 0x13:
        nullsub_43();
        break;
    case 0x14:
        nullsub_44();
        break;
    case 0x15:
        nullsub_45();
        break;
    case 0x16:
        sub_8033D74();
        break;
    case 0x17:
        sub_8033D94();
        break;
    case 0x19:
    case 0x43:
        QueueNextFriendRescueState(0x1a);
        break;
    case 0x1A:
        sub_8033DBC();
        break;
    case 0x1B:
        sub_8033F64();
        break;
    case 5:
        sub_8033C54();
        break;
    case 6:
        nullsub_41();
        break;
    case 7:
        sub_8033CAC();
        break;
    case FRIEND_RESCUE_MENU_ERROR:
        sub_8033D48();
        break;
    case 9:
        sub_8035424();
        break;
    case 10:
        nullsub_50();
        break;
    case 0xB:
    case 0xC:
        QueueNextFriendRescueState(6);
        break;
    case 0xD:
        QueueNextFriendRescueState(7);
        break;
    case 0xE:
        sub_8033B8C();
        break;
    case FRIEND_RESCUE_MENU_INIT:
    case FRIEND_RESCUE_MENU_MAIN:
        sub_80339C8();
        break;
    case FRIEND_RESCUE_MENU_EXIT:
        return 3;
    case 0x6A:
        sub_80348C4();
        break;
    case FRIEND_RESCUE_MENU_ERROR_2:
        sub_803482C();
        break;
    case 0x5A:
        sub_80349B0();
        break;
    case 0x5B:
        QueueNextFriendRescueState(0x5c);
        break;
    case 0x5D:
        sub_8034A70();
        break;
    case 0x5E:
        sub_8034B2C();
        break;
    case 0x5C:
        sub_80349E0();
        break;
    case 0x5F:
        sub_8034B88();
        break;
    case 0x60:
        sub_8034C98();
        break;
    case 0x61:
        sub_8034C38();
        break;
    case 0x68:
        sub_8034D54();
        break;
    case 0x66:
        QueueNextFriendRescueState(0x67);
        break;
    case 0x67:
        sub_8034970();
        break;
    case 0x74:
        sub_80351E0();
        break;
    case 0x72:
        QueueNextFriendRescueState(0x73);
        break;
    case 0x73:
        sub_8034D74();
        break;
    case 0x71:
        sub_8034EF0();
        break;
    case 0x70:
        sub_8034F38();
        break;
    case 0x50:
    case 0x6D:
        QueueNextFriendRescueState(0x6e);
        break;
    case 0x6E:
        sub_80352A4();
        break;
    case 0x62:
        QueueNextFriendRescueState(0x6a);
        break;
    case 0x65:
        sub_8034EC8();
        break;
    case 0x64:
        sub_8034F18();
        break;
    case 0x63:
    case 0x6F:
        QueueNextFriendRescueState(0x62);
        break;
    case 0x69:
        sub_8034F58();
        break;
    case 0x58:
        sub_8034F88();
        break;
    case 0x75:
        sub_8035018();
        break;
    case 0x76:
        sub_8035038();
        break;
    case 0x18:
    case 0x2F:
    case 0x3B:
    case 0x42:
    case 0x59:
    case 0x6C:
    case 0x77:
        QueueNextFriendRescueState(FRIEND_RESCUE_MENU_EXIT);
        break;
    case 0x57:
        QueueNextFriendRescueState(0x5f);
        break;
    case 0x56:
        sub_8035094();
        break;
    case 0x55:
        sub_80350F4();
        break;
    case 0x53:
        QueueNextFriendRescueState(0x54);
        break;
    case 0x54:
        sub_803517C();
        break;
    case 0x52:
        sub_8035210();
        break;
    case 0x46:
        QueueNextFriendRescueState(0x47);
        break;
    case 0x47:
        nullsub_46();
        break;
    case 0x48:
        nullsub_47();
        break;
    case 0x49:
        nullsub_48();
        break;
    case 0x4A:
        nullsub_49();
        break;
    case 0x4B:
        sub_8035430();
        break;
    case 0x4C:
        nullsub_51();
        break;
    case 0x4D:
    case 0x4E:
        QueueNextFriendRescueState(0x4f);
        break;
    case 0x4F:
        sub_8034848();
        break;
    case 0xF:
    case 0x10:
    case 0x22:
    case 0x30:
    case 0x3C:
    case 0x44:
    case 0x45:
        QueueNextFriendRescueState(FRIEND_RESCUE_MENU_MAIN);
        break;
    case 0x51:
        QueueNextFriendRescueState(FRIEND_RESCUE_MENU_MAIN);
        break;
    case 0x36:
        break;
  }
  return 0;
}

void CleanFriendRescueMenu(void)
{
  if (gUnknown_203B33C != NULL) {
    MemoryFree(gUnknown_203B33C);
    gUnknown_203B33C = NULL;
    sub_803084C();
    sub_8031E10();
    sub_8023C60();
    sub_80155F0();
    sub_801CBB8();
    sub_802F2C0();
    sub_8030DE4();
    sub_802453C();
    sub_801B450();
  }
}

void nullsub_40(void)
{
}

void sub_8032828(void)
{

    unkStruct_203B480 *mail;
    u32 temp;
    u8 buffer [80];
    PokemonStruct1 *pokeStruct1;
    PokemonStruct1 *pokeStruct2;
    char *monName;

    switch (gUnknown_203B33C->state) {
        case 0x0:
            if (CountMailType(WONDER_MAIL_TYPE_SOS) == 0 && CountMailType(WONDER_MAIL_TYPE_THANK_YOU) == 0) {
                if (gUnknown_203B33C->unk52C != 0)
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E2108, NULL, 4, 0, NULL, 0x101);
                else
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E20B8, NULL, 4, 0, NULL, 0x101);
            }
            else {
                if (gUnknown_203B33C->unk52C != 0)
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E20E0, NULL, 4, 0, NULL, 0x101);
                else
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E2068, NULL, 4, 0, NULL, 0x101);
            }
            break;
        case 0x1:
            if (CountMailType(WONDER_MAIL_TYPE_SOS) == 0 && CountMailType(WONDER_MAIL_TYPE_THANK_YOU) == 0) {
                if (gUnknown_203B33C->unk52C != 0)
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E2108, NULL, 4, 0, NULL, 0x101);
                else
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E20B8, NULL, 4, 0, NULL, 0x101);
            }
            else {
                if (gUnknown_203B33C->unk52C != 0)
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E20E0, NULL, 4, 0, NULL, 0x101);
                else
                    sub_8014248(&gUnknown_80E25F4[0], 0, 0, gUnknown_80E2068, NULL, 4, 0, NULL, 0x101);
             }
            break;
        case 0x3:
            if (CountMailType(WONDER_MAIL_TYPE_AOK) != 0)
                sub_8014248(&gUnknown_80E25F4[0], 0, 3, gUnknown_80E2130, NULL, 4, 0, NULL, 0x101);
            else
                sub_8014248(&gUnknown_80E25F4[0], 0, 3, gUnknown_80E2190, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x4:
            if (CountMailType(WONDER_MAIL_TYPE_SOS) == 0) {
                if (CountMailType(WONDER_MAIL_TYPE_THANK_YOU) == 0)
                    sub_8014248(&gUnknown_80E25F4[0], 0, 17, gUnknown_80E2268, NULL, 4, 0, NULL, 0x101);
                else
                    sub_8014248(&gUnknown_80E25F4[0], 0, 17, gUnknown_80E2218, NULL, 4, 0, NULL, 0x101);
            }
            else {
                if (CountMailType(WONDER_MAIL_TYPE_THANK_YOU) == 0)
                    sub_8014248(&gUnknown_80E25F4[0], 0, 17, gUnknown_80E2240, NULL, 4, 0, NULL, 0x101);
                else
                    sub_8014248(&gUnknown_80E25F4[0], 0, 17, gUnknown_80E21B8, NULL, 4, 0, NULL, 0x101);
            }
            break;
        case 0xE:
            switch(gUnknown_203B33C->unk528) {
                case 0x11:
                    sub_8014248(&gUnknown_80E2610[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
                    break;
                case 0x3:
                    sub_8014248(&gUnknown_80E2640[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
                    break;
                case 0x4:
                    sub_8014248(&gUnknown_80E2680[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
                    break;
                case 0x12:
                    sub_8014248(&gUnknown_80E26B0[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
                    break;
                case 0x13:
                    sub_8014248(&gUnknown_80E26F0[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
                    break;
                case 0x14:
                    sub_8014248(&gUnknown_80E2728[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
                    break;
            }
            break;
        case 0x3C:
            xxx_info_box_80141B4(&gUnknown_80E276C[0], 0, 0, 0x101);
            break;
        case 0x3D:
            sub_8014248(&gUnknown_80E27A4[0], 0, 6, gUnknown_80E2458, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x43:
            xxx_info_box_80141B4(&gUnknown_80E2814[0], 0, 0, 0x101);
            break;
        case 0x3E:
            xxx_info_box_80141B4(&gUnknown_80E2840[0], 0, 0, 0x101);
            break;
        case 0x3F:
            xxx_info_box_80141B4(&gUnknown_80E2874[0], 0, 0, 0x101);
            break;
        case 0x40:
            switch ((u32)gUnknown_203B33C->unk524) {
                case 0xB:
                case 0xD:
                case 0xE:
                    xxx_info_box_80141B4(&gUnknown_80E2898[0], 0, 0, 0x101);
                    break;
                case 0xC:
                    break;
            }
            break;
        case 0x42:
            xxx_info_box_80141B4(&gUnknown_80E28D8[0], 0, 0, 0x101);
            break;
        case 0x30:
            xxx_info_box_80141B4(&gUnknown_80E2904[0], 0, 0, 0x101);
            break;
        case 0x31:
            xxx_info_box_80141B4(&gUnknown_80E296C[0], 0, 0, 0x101);
            break;
        case 0x32:
            if (sub_8030894() == 0) {
                ResetUnusedInputStruct();
                xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
                sub_80306A8(WONDER_MAIL_TYPE_SOS, 0, NULL, 6);
            }
            break;
        case 0x35:
            sub_8014248(&gUnknown_80E29A0[0], 0, 6, gUnknown_80E22B4, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x37:
            switch ((u32)gUnknown_203B33C->unk524) {
                case 0xC:
                    break;
                case 0xB:
                case 0xD:
                case 0xE:
                    xxx_info_box_80141B4(&gUnknown_80E29D0[0], 0, 0, 0x101);
                    break;
            }
            break;
        case 0x38:
            xxx_info_box_80141B4(&gUnknown_80E2A0C[0], 0, 0, 0x101);
            break;
        case 0x3A:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_8031D70(gUnknown_203B33C->unk218, 0);
            break;
        case 0x3B:
            xxx_info_box_80141B4(&gUnknown_80E2A1C[0], 0, 0, 0x101);
            break;
        case 0x39:
            xxx_info_box_80141B4(&gUnknown_80E2A5C[0], 0, 0, 0x101);
            break;
        case 0x2D:
            xxx_info_box_80141B4(&gUnknown_80E2A80[0], 0, 0, 0x101);
            break;
        case 0x2F:
            xxx_info_box_80141B4(&gUnknown_80E2AA8[0], 0, 0, 0x101);
            break;
        case 0x2A:
            xxx_info_box_80141B4(&gUnknown_80E2AE4[0], 0, 0, 0x101);
            break;
        case 0x2B:
        #ifndef NONMATCHING
            gUnknown_203B33C->unk52C = gUnknown_203B33C->unk52C;
            gUnknown_80E2BE0[0] = gUnknown_80E2BE0[0];
        #endif //NONMATCHING
            switch ((u32)gUnknown_203B33C->unk524) {
                case 0xC:
                    break;
                case 0xB:
                case 0xD:
                case 0xE:
                    #ifndef NONMATCHING
                    gUnknown_80E2BE0[0] = gUnknown_80E2BE0[0];
                    #endif //NONMATCHING
                    xxx_info_box_80141B4(&gUnknown_80E2B54[0], 0, 0, 0x101);
                    break;
            }
            break;
        case 0x2C:
            xxx_info_box_80141B4(&gUnknown_80E2A0C[0], 0, 0, 0x101);
            break;
        case 0x23:
            xxx_info_box_80141B4(&gUnknown_80E2B90[0], 0, 0, 0x101);
            break;
        case 0x21:
            sub_8014248(&gUnknown_80E2BE0[0], 0, 15, gUnknown_80E23A8, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x25:
            xxx_info_box_80141B4(&gUnknown_80E2C48[0], 0, 0, 0x101);
            break;
        case 0x26:
            if (sub_8023CE8() != 0)
                sub_8023C60();
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_8023868(3, 0, 0, 9);
            break;
        case 0x27:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk35C);
            SetMenuItems(gUnknown_203B33C->unk21C, gUnknown_203B33C->unk35C, 3, &gUnknown_80E2334, gUnknown_80E234C, TRUE, 0, FALSE);
            sub_8023DA4();
            sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
            break;
        case 0x24:
            sub_8014248(&gUnknown_80E2C94[0], 0, 16, gUnknown_80E22F0, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x29:
            sub_8014248(&gUnknown_80E2CD4[0], 0, 6, gUnknown_80E22D0, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x1C:
            xxx_info_box_80141B4(&gUnknown_80E2CE8[0], 0, 0, 0x101);
            break;
        case 0x1D:
            if (sub_8030894() == 0) {
                ResetUnusedInputStruct();
                xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
                sub_80306A8(WONDER_MAIL_TYPE_AOK, 0, NULL, 6);
            }
            break;
        case 0x20:
            sub_8014248(&gUnknown_80E2D30[0], 0, 6, gUnknown_80E22B4, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x22:
            xxx_info_box_80141B4(&gUnknown_80E2D60[0], 0, 0, 0x101);
            break;
        case 0x5:
            sub_8014248(&gUnknown_80E2D7C[0], 0, 6, gUnknown_80E2290, NULL, 4, 0, NULL, 0x101);
            break;
        case 0xA:
        case 0x4C:
            sub_8014248(&gUnknown_80E2E20[0], 0, 6, gUnknown_80E2290, NULL, 4, 0, NULL, 0x101);
            break;
        case 0xB:
        case 0x4D:
            xxx_info_box_80141B4(&gUnknown_80E2E54[0], 0, NULL, 0);
            break;
        case 0xC:
        case 0x4E:
            xxx_info_box_80141B4(&gUnknown_80E2EB4[0], 0, NULL, 0);
            break;
        case 0x7:
            gUnknown_203B33C->status = 0;
            sub_8011830();
            gUnknown_203B33C->status = sub_8037B28(gUnknown_203B33C->unk40);
            if (gUnknown_203B33C->status == 0) {
                #ifndef NONMATCHING
                u8 *u8ptr;
                #endif //NONMATCHING
                switch (gUnknown_203B33C->unk40) {
                    case 0x3:
                        MemoryFill8((u8*)&gUnknown_203B33C->unk48, 0, sizeof(unkStruct_203B480));
                        MemoryFill8((u8*)&gUnknown_203B33C->unk78, 0, sizeof(unkStruct_203B480));
                        gUnknown_203B33C->status = sub_8037D64(gUnknown_203B33C->unk40, &gUnknown_203B33C->unk48, &gUnknown_203B33C->unk78);
                        break;
                    case 0x2:
                        MemoryFill8((u8*)&gUnknown_203B33C->unk48, 0, sizeof(unkStruct_203B480));
                        MemoryFill8((u8*)&gUnknown_203B33C->unk78, 0, sizeof(unkStruct_203B480));
                        #ifdef NONMATCHING
                        // Regswaps
                        gUnknown_203B33C->unk48 = *GetMailatIndex(gUnknown_203B33C->unk218);
                        #else
                        gUnknown_80E2BE0[0] = gUnknown_80E2BE0[0];
                        u8ptr = &gUnknown_203B33C->unk218;
                        gUnknown_80E2BE0[0] = gUnknown_80E2BE0[0];
                        gUnknown_203B33C->unk48 = *GetMailatIndex(*u8ptr);
                        #endif //NONMATCHING
                        gUnknown_203B33C->status = sub_8037D64(gUnknown_203B33C->unk40, &gUnknown_203B33C->unk48, &gUnknown_203B33C->unk78);
                        break;
                    case 0x5:
                        MemoryFill8((u8*)&gUnknown_203B33C->unkA8, 0, sizeof(WonderMailStruct_203B2C0_sub));
                        MemoryFill8((u8*)&gUnknown_203B33C->unk130, 0, sizeof(WonderMailStruct_203B2C0_sub));
                        gUnknown_203B33C->status = sub_8037D64(gUnknown_203B33C->unk40, &gUnknown_203B33C->unkA8, &gUnknown_203B33C->unk130);
                        break;
                    case 0x4:
                        MemoryFill8((u8*)&gUnknown_203B33C->unkA8, 0, sizeof(WonderMailStruct_203B2C0_sub));
                        MemoryFill8((u8*)&gUnknown_203B33C->unk130, 0, sizeof(WonderMailStruct_203B2C0_sub));
                        gUnknown_203B33C->unkA8.pokemon.speciesNum = 0;
                        gUnknown_203B33C->unk130.pokemon.speciesNum = 0;
                        gUnknown_203B33C->unkA8.mail = *GetMailatIndex(gUnknown_203B33C->unk218);
                        if (gUnknown_203B33C->speciesNum != -1) {
                            pokeStruct1 = &gUnknown_203B33C->unkA8.pokemon;
                            pokeStruct2 = gRecruitedPokemonRef->pokemon;
                            pokeStruct2 += gUnknown_203B33C->speciesNum;
                            memcpy(pokeStruct1, pokeStruct2, sizeof(PokemonStruct1));
                        }
                        gUnknown_203B33C->status = sub_8037D64(gUnknown_203B33C->unk40, &gUnknown_203B33C->unkA8, &gUnknown_203B33C->unk130);
                        break;
                }

                if (gUnknown_203B33C->status == 0) {
                    switch (gUnknown_203B33C->unk40) {
                        case 2:
                        case 3:
                            gUnknown_203B33C->status = sub_80381F4(gUnknown_203B33C->unk40, &gUnknown_203B33C->unk48, &gUnknown_203B33C->unk78);
                            if (sub_800D588() != 0)
                                gUnknown_203B33C->unk420 = gUnknown_203B33C->unk78.unk10.unk10;
                            else
                                gUnknown_203B33C->unk420 = gUnknown_203B33C->unk48.unk10.unk10;
                            break;
                        case 4:
                        case 5:
                            gUnknown_203B33C->status = sub_80381F4(gUnknown_203B33C->unk40, &gUnknown_203B33C->unkA8, &gUnknown_203B33C->unk130);
                            if (sub_800D588() != 0)
                                gUnknown_203B33C->unk420 = gUnknown_203B33C->unk130.mail.unk10.unk10;
                            else
                                gUnknown_203B33C->unk420 = gUnknown_203B33C->unkA8.mail.unk10.unk10;
                            break;
                    }
                }
            }
            xxx_call_start_bg_music();
            break;
        case 0x10:
            xxx_info_box_80141B4(&gUnknown_80E2F14[0], 0, 0, 0x101);
            break;
        case 0x11:
            xxx_info_box_80141B4(&gUnknown_80E2F44[0], 0, 0, 0x101);
            break;
        case 0x12:
            if (sub_8030894() != 0)
                break;
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_80306A8(WONDER_MAIL_TYPE_SOS, 0, NULL, 6);
            break;
        case 0x15:
            sub_8014248(&gUnknown_80E2F78[0], 0, 6, gUnknown_80E2290, NULL, 4, 0, NULL, 0x101);
            break;
        case 0xF:
            xxx_info_box_80141B4(&gUnknown_80E2FA0[0], 0, 0, 0x101);
            break;
        case 0x16:
            switch ((u32)gUnknown_203B33C->unk524) {
                case 0xC:
                    break;
                case 0xB:
                case 0xD:
                case 0xE:
                    xxx_info_box_80141B4(&gUnknown_80E2FEC[0], 0, 0, 0x101);
                    break;
            }
            break;
        case 0x18:
            xxx_info_box_80141B4(&gUnknown_80E3030[0], 0, 0, 0x101);
            break;
        case 0x19:
            xxx_info_box_80141B4(&gUnknown_80E3078[0], 0, 0, 0x101);
            break;
        case 0x1A:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_80151C0(4, gUnknown_203B33C->passwordBuffer);
            break;
        case 0x5A:
            sub_8014248(&gUnknown_80E30A4[0], 0, 6, gUnknown_80E2458, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x5B:
            xxx_info_box_80141B4(gUnknown_80E30D0, 0, 0, 0x101);
            break;
        case 0x5D:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk35C);
            SetMenuItems(gUnknown_203B33C->unk21C, gUnknown_203B33C->unk35C, 3, &gUnknown_80E231C, gUnknown_80E2408, TRUE, 0, FALSE);
            sub_803092C();
            sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
            break;
        case 0x5F:
            if (sub_801D008() == NULL) {
                ResetUnusedInputStruct();
                xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
                {
                UnkTextStruct2_sub local_x = {3, 2};
                sub_801C8C4(0, 1, &local_x, 9);
                }
            }
            break;
        case 0x60:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk35C);
            SetMenuItems(gUnknown_203B33C->unk21C, gUnknown_203B33C->unk35C, 3, &gUnknown_80E23F0, gUnknown_80E2408, TRUE, 0, FALSE);
            sub_801CCD8();
            sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
            break;
        case 0x6A:
            gUnknown_203B33C->status = 0;
            sub_8011830();
            gUnknown_203B33C->status = sub_8037B28(gUnknown_203B33C->unk40);
            if (gUnknown_203B33C->status == 0) {
                switch (gUnknown_203B33C->unk40) {
                    case 0x6:
                        MemoryFill8((u8*)&gUnknown_203B33C->unk1B8, 0, 0x30);
                        gUnknown_203B33C->unk1B8 = *GetMailatIndex(gUnknown_203B33C->unk218);
                        gUnknown_203B33C->status = sub_8037D64(gUnknown_203B33C->unk40, &gUnknown_203B33C->unk1B8, &gUnknown_203B33C->unk1E8);
                        break;
                    case 0x7:
                        MemoryFill8((u8*)&gUnknown_203B33C->unk1B8, 0, 0x30);
                        MemoryFill8((u8*)&gUnknown_203B33C->unk1E8, 0, 0x30);
                        gUnknown_203B33C->status = sub_8037D64(gUnknown_203B33C->unk40, &gUnknown_203B33C->unk1B8, &gUnknown_203B33C->unk1E8);
                        break;
                }
                temp = 6;
                if (gUnknown_203B33C->status == 0 && gUnknown_203B33C->unk40 <= 7 && gUnknown_203B33C->unk40 >= temp) {
                    gUnknown_203B33C->status = sub_80381F4(gUnknown_203B33C->unk40, &gUnknown_203B33C->unk1B8, &gUnknown_203B33C->unk1E8);
                    if (sub_800D588() != 0)
                        gUnknown_203B33C->unk420 = gUnknown_203B33C->unk1E8.unk10.unk10;
                    else
                        gUnknown_203B33C->unk420 = gUnknown_203B33C->unk1B8.unk10.unk10;
                }
            }
            xxx_call_start_bg_music();
            break;
        case 0x72:
            xxx_info_box_80141B4(gUnknown_80E311C, 0, 0, 0x101);
            break;
        case 0x73:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_80151C0(4, gUnknown_203B33C->passwordBuffer);
            break;
        case 0x66:
            xxx_info_box_80141B4(gUnknown_80E314C, 0, 0, 0x101);
            break;
        case 0x67:
        case 0x2E:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_8031D70(gUnknown_203B33C->unk218, 0);
            break;
        case 0x68:
            xxx_info_box_80141B4(gUnknown_80E317C, 0, 0, 0x101);
            break;
        case 0x6F:
            xxx_info_box_80141B4(gUnknown_80E319C, 0, 0, 0x101);
            break;
        case 0x70: // Yes we need duplicates in order to match :) - Kermalis
            xxx_info_box_80141B4(gUnknown_80E317C, 0, 0, 0x101);
            break;
        case 0x6C:
            xxx_info_box_80141B4(gUnknown_80E31D8, 0, 0, 0x101);
            break;
        case 0x50:
            xxx_info_box_80141B4(&gUnknown_80E31FC[0], 0, 0, 0x101);
            break;
        case 0x6D:
            switch ((u32)gUnknown_203B33C->unk524) {
                case 0xC:
                    break;
                case 0xB:
                case 0xD:
                case 0xE:
                    xxx_info_box_80141B4(&gUnknown_80E3220[0], 0, 0, 0x101);
                    break;
            }
            break;
        case 0x6E:
            monName = GetMonSpecies(MONSTER_PELIPPER);
            strcpy(gUnknown_203B33C->unk53C.clientName, monName);
            gUnknown_203B33C->unk53C.clientSpecies = 0;
            gUnknown_203B33C->unk53C.unk16 = 2;
            gUnknown_203B33C->unk53C.moneyReward = 0;
            mail = GetMailatIndex(GetMailIndex(6, gUnknown_203B33C->unk420));
            // ABSOLUTELY GENIUS
            if (mail->item.id != ITEM_NOTHING)
                gUnknown_203B33C->unk53C.itemRewards[0] = mail->item.id;
            else
                gUnknown_203B33C->unk53C.itemRewards[0] = ITEM_NOTHING;
            gUnknown_203B33C->unk53C.quantity = 1;
            gUnknown_203B33C->unk53C.teamRankPtsReward = GetDungeonTeamRankPts(&mail->unk4.dungeon, 0);
            gUnknown_203B33C->unk53C.itemRewards[1] = 0;
            gUnknown_203B33C->unk53C.itemRewards[2] = 0;
            gUnknown_203B33C->unk53C.friendAreaReward = 0;
            sub_802F204(&gUnknown_203B33C->unk53C, 0);
            break;
        case 0xD:
        case 0x62:
            nullsub_23(FALSE);
            xxx_info_box_80141B4(&gUnknown_80E2DD0[0], 0, NULL, 0);
            break;
        case 0x64:
            switch ((u32)gUnknown_203B33C->unk524) {
                case 0xC:
                    break;
                case 0xB:
                case 0xD:
                case 0xE:
                    xxx_info_box_80141B4(gUnknown_80E3248, 0, 0, 0x101);
                    break;
            }
            break;
        case 0x63:
            xxx_info_box_80141B4(gUnknown_80E3288, 0, 0, 0x101);
            break;
        case 0x69:
            sub_8014248(&gUnknown_80E2D7C[0], 0, 6, gUnknown_80E2290, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x59:
            sub_80922B4(buffer, GetPlayerPokemonStruct()->name, POKEMON_NAME_LENGTH);
            sprintfStatic(gUnknown_203B33C->unk424, gUnknown_80E32C4, buffer);
            xxx_info_box_80141B4(gUnknown_203B33C->unk424, 0, 0, 0x101);
            break;
        case 0x58:
            sub_8014248(&gUnknown_80E331C[0], 0, 6, gUnknown_80E24D8, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x75:
            xxx_info_box_80141B4(gUnknown_80E317C, 0, 0, 0x101);
            break;
        case 0x76:
            xxx_info_box_80141B4(gUnknown_80E2A0C, 0, 0, 0x101);
            break;
        case 0x57:
            xxx_info_box_80141B4(&gUnknown_80E3378[0], 0, 0, 0x101);
            break;
        case 0x56:
            sub_8014248(&gUnknown_80E339C[0], 0, 22, gUnknown_80E24B0, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x55:
            sub_8014248(&gUnknown_80E33D8[0], 0, 21, gUnknown_80E2470, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x53:
            xxx_info_box_80141B4(&gUnknown_80E3430[0], 0, 0, 0x101);
            break;
        case 0x54:
            sub_8014248(&gUnknown_80E34B0[0], 0, 6, gUnknown_80E2440, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x46:
            xxx_info_box_80141B4(&gUnknown_80E34F0[0], 0, 0, 0x101);
            break;
        case 0x47:
        case 0x5C:
            if (sub_8030894() == 0) {
                ResetUnusedInputStruct();
                xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
                sub_80306A8(5, 0, 0, 6);
            }
            break;
        case 0x48:
        case 0x13:
        case 0x1E:
        case 0x33:
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk35C);
            SetMenuItems(gUnknown_203B33C->unk21C, gUnknown_203B33C->unk35C, 3, &gUnknown_80E231C, gUnknown_80E234C, TRUE, 0, FALSE);
            sub_803092C();
            sub_8035CF4(gUnknown_203B33C->unk21C, 3, 1);
            break;
        case 0x4A:
            sub_8014248(&gUnknown_80E352C[0], 0, 6, gUnknown_80E2290, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x44:
            xxx_info_box_80141B4(&gUnknown_80E355C[0], 0, 0, 0x101);
            break;
        case 0x45:
            xxx_info_box_80141B4(&gUnknown_80E35AC[0], 0, 0, 0x101);
            break;
        case 0x51:
            xxx_info_box_80141B4(&gUnknown_80E35E8[0], 0, 0, 0x101);
            break;
        case 0x52:
            if (gUnknown_203B33C->unk40 == 6)
                sub_8014248(&gUnknown_80E360C[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
            else
                sub_8014248(&gUnknown_80E3644[0], 0, 11, gUnknown_80E236C, NULL, 4, 0, NULL, 0x101);
            break;
        case 0x7C:
            sub_8014248(&gUnknown_80E367C[0], 0, gUnknown_203B33C->unk564, gUnknown_80E25B4, 0, 4, 0, 0, 0x101);
            break;
        case 0x7D:
            switch (gUnknown_203B33C->unk564) {
                case 0x23:
                    xxx_info_box_80141B4(&gUnknown_80E3690[0], 0, 0, 0x101);
                    break;
                case 0x24:
                    xxx_info_box_80141B4(&gUnknown_80E3818[0], 0, 0, 0x101);
                    break;
                case 0x25:
                    xxx_info_box_80141B4(&gUnknown_80E3998[0], 0, 0, 0x101);
                    break;
                case 0x26:
                    xxx_info_box_80141B4(&gUnknown_80E3B1C[0], 0, 0, 0x101);
                    break;
            }
            break;
        case 0x7A:
            sub_8014248(&gUnknown_80E367C[0], 0, gUnknown_203B33C->unk564, gUnknown_80E2554, 0, 4, 0, 0, 0x101);
            break;
        case 0x7B:
            switch (gUnknown_203B33C->unk564) {
                case 0x1E:
                    xxx_info_box_80141B4(&gUnknown_80E3BF8[0], 0, 0, 0x101);
                    break;
                case 0x1F:
                    xxx_info_box_80141B4(&gUnknown_80E3DE4[0], 0, 0, 0x101);
                    break;
                case 0x21:
                    xxx_info_box_80141B4(&gUnknown_80E3E98[0], 0, 0, 0x101);
                    break;
                case 0x20:
                    xxx_info_box_80141B4(&gUnknown_80E4014[0], 0, 0, 0x101);
                    break;
                case 0x22:
                    xxx_info_box_80141B4(&gUnknown_80E4130[0], 0, 0, 0x101);
                    break;
            }
            break;
        case 0x78:
            sub_8014248(&gUnknown_80E367C[0], 0, gUnknown_203B33C->unk564, gUnknown_80E24F8, 0, 4, 0, 0, 0x101);
            break;
        case 0x79:
            switch (gUnknown_203B33C->unk564) {
                case 0x1D:
                    xxx_info_box_80141B4(&gUnknown_80E41DC[0], 0, 0, 0x101);
                    break;
                case 0x1A:
                    xxx_info_box_80141B4(&gUnknown_80E4314[0], 0, 0, 0x101);
                    break;
            }
            break;
    }
}


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
            xxx_info_box_80141B4(gUnknown_80E44A4, 0, 0, 0x101);
            break;
        case COMMS_NO_RESPONSE:
            xxx_info_box_80141B4(gUnknown_80E4500, 0, 0, 0x101);
            break;
        case COMMS_DIFFERENT_MODES:
            xxx_info_box_80141B4(gUnknown_80E4550, 0, 0, 0x101);
            break;
        case COMMS_NO_ROOM_STORAGE:
            xxx_info_box_80141B4(gUnknown_80E45B4, 0, 0, 0x101);
            break;
        case COMMS_DUPLICATE_MAIL:
            xxx_info_box_80141B4(gUnknown_80E460C, 0, 0, 0x101);
            break;
        case COMMS_MAIL_SENT_ALREADY:
            xxx_info_box_80141B4(gUnknown_80E4650, 0, 0, 0x101);
            break;
        case COMMS_NOT_ELIGIBLE_1:
            xxx_info_box_80141B4(gUnknown_80E468C, 0, 0, 0x101);
            break;
        case COMMS_FRIEND_NOT_ELIGIBLE:
            xxx_info_box_80141B4(gUnknown_80E46C8, 0, 0, 0x101);
            break;
        case COMMS_NOT_ELIGIBLE_2:
            xxx_info_box_80141B4(gUnknown_80E4704, 0, 0, 0x101);
            break;
        case COMMS_FRIEND_NOT_ELIGIBLE_2:
            xxx_info_box_80141B4(gUnknown_80E4744, 0, 0, 0x101);
            break;
        case 16:
            xxx_info_box_80141B4(gUnknown_80E4788, 0, 0, 0x101);
            break;
        case COMMS_NO_ROOM_MAIL:
            xxx_info_box_80141B4(gUnknown_80E47D8, 0, 0, 0x101);
            break;
        case 1:
        case 5:
        case 14:
            xxx_info_box_80141B4(gUnknown_80E4480, 0, 0, 0x101);
            break;
        case COMMS_NOT_READY:
            xxx_info_box_80141B4(gUnknown_80E482C, 0, 0, 0x101);
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
    unkStruct_203B480 mail;
    unkStruct_203B480 *mail2;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&mail, 0, sizeof(unkStruct_203B480));
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
                        sub_8014248(gUnknown_80E48A8, 0, 6, gUnknown_80E2290, 0, 4, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x1B);
                        break;
                    case PASSWORD_ENTRY_NOT_SOS_MAIL:
                        xxx_info_box_80141B4(gUnknown_80E48E8, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_SOS_MAIL:
                        xxx_info_box_80141B4(gUnknown_80E460C, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_SOS_MAIL_SUCCESS:
                        sub_8095274(mail.unk10.unk10);
                        mail.mailType = 2;
                        sub_80951BC(&mail);
                        xxx_info_box_80141B4(gUnknown_80E4928, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x16);
                        break;
                    case PASSWORD_ENTRY_NOT_AOK_MAIL:
                        xxx_info_box_80141B4(gUnknown_80E4964, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_AOK_MAIL:
                        xxx_info_box_80141B4(gUnknown_80E499C, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR);
                        break;
                    case PASSWORD_ENTRY_AOK_MAIL_SUCCESS:
                        mail.mailType = 5;
                        sub_80951FC(&mail);
                        mail2 = GetMailatIndex(GetMailIndex(1, mail.unk10.unk10));
                        mail2->mailType = 7;
                        MemoryFill8((u8 *)gUnknown_203B484, 0, sizeof(unkStruct_203B484));
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
    switch(sub_8023A94(TRUE))
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_8024458(gUnknown_203B33C->speciesNum, 0);
            SetFriendRescueMenuState(0x28);
            break;
    }
}

void sub_8034254(void)
{
    s32 menuAction;
    menuAction = -1;

    sub_8023A94(FALSE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
        MemoryFill8((u8 *)&gUnknown_203B33C->item, 0 , sizeof(Item));
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
        MemoryFill8((u8 *)&gUnknown_203B33C->item, 0 , sizeof(Item));
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
                            xxx_info_box_80141B4(gUnknown_80E31FC, 0, 0, 0x101);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
    switch(sub_801CA08(TRUE))
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
            sub_801CB5C(TRUE);
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
    sub_801CA08(FALSE);
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
            RestoreUnkTextStruct_8006518(gUnknown_203B33C->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_801B3C0(&gUnknown_203B33C->item);
            SetFriendRescueMenuState(0x61);
            break;
        case 5:
        case 8:
            sub_8035CC0(gUnknown_203B33C->unk35C, 3);
            sub_801CB5C(TRUE);
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
    unkStruct_203B480 mail;
    unkStruct_203B480 *mail2;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&mail, 0, sizeof(unkStruct_203B480));
    switch(return_var)
    {
        case 3:
                switch(sub_8039068(PASSWORD_ENTRY_THANK_YOU_MAIL_MODE, gUnknown_203B33C->passwordBuffer, &mail))
                {
                    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                        sub_8014248(gUnknown_80E48A8, 0, 6, gUnknown_80E2440, 0, 4, 0, 0, 0x101);
                        SetFriendRescueMenuState(0x74);
                        break;
                    case PASSWORD_ENTRY_NOT_THANK_YOU_MAIL:
                        xxx_info_box_80141B4(gUnknown_80E49C4, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR_2);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL:
                        xxx_info_box_80141B4(gUnknown_80E4704, 0, 0, 0x101);
                        SetFriendRescueMenuState(FRIEND_RESCUE_MENU_ERROR_2);
                        break;
                    case PASSWORD_ENTRY_THANK_YOU_MAIL_SUCCESS:
                        mail2 = GetMailatIndex(GetMailIndex(4, mail.unk10.unk10));
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
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B33C->unk3BC, TRUE, TRUE);
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
    unkStruct_203B480 *mail;

    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 6:
                mail = GetMailatIndex(gUnknown_203B33C->unk218);
                if(gUnknown_203B33C->item.id != ITEM_NOTHING)
                    mail->item = gUnknown_203B33C->item;
                gTeamInventoryRef->teamStorage[gUnknown_203B33C->item.id]--;
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
                if(sub_801CF14(0))
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
    unkStruct_203B480 *mail;

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
                    mail = GetMailatIndex(GetFirstIndexofMailType(5));
                    if(mail->item.id != ITEM_NOTHING)
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
