#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_8023868.h"
#include "code_8024458.h"
#include "code_8094F88.h"
#include "code_80A26CC.h"
#include "constants/communication_error_codes.h"
#include "cpu.h"
#include "input.h"
#include "items.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus2.h"
#include "pokemon.h"
#include "rescue_password_menu.h"
#include "save.h"
#include "save_write.h"
#include "text1.h"
#include "text2.h"
#include "wonder_mail.h"

static EWRAM_DATA_2 WonderMailStruct_203B2C0 *sUnknown_203B2C0 = {0};

extern void sub_8011C28(u32);

extern void sub_809927C(u8);
extern bool8 HasNoWonderMailType(u32);
extern u32 sub_8031050();
extern void sub_80310B4();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern void nullsub_130(void);
extern void sub_8028348(void);
extern void sub_803084C();
extern u32 sub_8030768(u32);
extern s8 sub_80307EC();
extern void sub_8030D40(u8, u32);
extern void sub_8030810(u32);
extern u32 sub_8030DA0(void);
extern void sub_8030DE4(void);
extern void sub_803092C(void);

extern u32 sub_8039068(u32, u8 *r1, unkStruct_203B480 *r0);
extern void sub_8095274(u32);
extern u32 sub_8031DCC();
extern void sub_8031E10();
extern void sub_8031E00();
extern void sub_8031E10(void);
extern void sub_803084C(void);
extern void sub_8030DE4();
extern void sub_80306A8(u32, u32, u32, u32);
extern s32 sub_8037B28(u32);
extern void sub_8031D70(u8, u32);
extern u32 sub_8023CE8(void);
extern u32 sub_8030894(void);
extern void sub_8030F58(u32);
extern void sub_8029B34(void);
extern void sub_8029AD8(void);
extern void sub_8029AF4(void);
extern void sub_8029A88(void);
extern void sub_8029AB0(void);
extern void sub_80297B8(void);
extern void sub_80297D4(void);
extern void sub_8029884(void);
extern void sub_8029944(void);
extern void sub_80299AC(void);
extern void sub_80299D8(void);
extern void sub_8029A6C(void);
extern void ExitFriendRescueCounterMenu(void);
extern void sub_8028BF0(void);
extern void sub_8029A18(void);
extern void sub_80295A8(void);
extern void sub_8029668(void);
extern void sub_8029684(void);
extern void sub_8029740(void);
extern void sub_80295D8(void);
extern void sub_802979C(void);
extern void sub_8029358(void);
extern void sub_8029374(void);
extern void sub_802939C(void);
extern void sub_8028F58(void);
extern void sub_8028F30(void);
extern void sub_8028F04(void);
extern void sub_8028ED4(void);
extern void sub_80293D8(void);
extern void sub_80293F4(void);
extern void sub_8028DE8(u32);
extern void sub_8028EAC(void);
extern void sub_802955C(void);
extern void sub_80292A4(void);
extern void sub_80292EC(void);
extern void sub_802933C(void);
extern void sub_802958C(void);
extern void sub_8029208(void);
extern void sub_8028E84(void);
extern void sub_8028F80(void);
extern void sub_8028FC0(void);
extern void sub_8028FDC(void);
extern void sub_8028E54(void);
extern void sub_8028E24(void);
extern void sub_8028E08(void);
extern void sub_80290D4(void);
extern void sub_80290F0(void);
extern void sub_80291AC(void);
extern void sub_8029044(void);
extern void sub_8028CFC(void);
extern void sub_8028D4C(void);
extern void sub_8031E10(void);
extern void sub_803084C(void);
extern void sub_80310B4(void);
extern void sub_8030DE4(void);

extern const u8 DontSendPokemon_80DDB80[];
extern const u8 SendPokemon_80DDB98[];
extern const u8 SendWOPokemon[];

enum FriendRescueStates
{
    INITIALIZE_FRIEND_RESCUE = 0,
    FRIEND_RESCUE_MAIN = 1,
    FRIEND_RESCUE_EXIT_PRE = 2,
    FRIEND_RESCUE_COUNTER_EXIT = 3,
    // 4
    FRIEND_RESCUE_COMMUNICATING_PRE = 5,
    FRIEND_RESCUE_COMMUNICATING = 6,
    FRIEND_RESCUE_ERROR = 7,
    // 8
    NO_MAIL_ROOM = 9,
    // 10 - 11
    NO_SOS_MAIL = 12,
    // 13
    NO_AOK_MAIL = 14,
    // 15
    NO_MAIL = 16,
    // 17
    PROMPT_DELETE_ALL_MAIL = 18,
    CONFIRM_DELETE_ALL_MAIL_1,
    CONFIRM_DELETE_ALL_MAIL_2,
    DELETE_ALL_MAIL_SAVE_PRE,
    // 22 - 25
    NO_SOS_MAIL_TO_SEND = 26,
    // 27
    CANT_GO_TO_DUNGEON = 28,
    FRIEND_RESCUE_FAILED,
    PROMPT_CHOOSE_SOS_MAIL,
    // 31 - 34
    RECEIVED_FRIEND_SOS_MAIL = 35,
    RECEIVED_FRIEND_SOS_MAIL_SAVE_PRE,
    RECEIVED_FRIEND_SOS_MAIL_SAVE_COMPLETE,
    PROMPT_SOS_MAIL_PASSWORD,
    // 39 - 40
    PROMPT_CHOOSE_AOK_MAIL = 41,
    // 42 - 46
    NO_AOK_MAIL_TO_SEND = 47,
    // 48
    NO_POKEMON_IN_FRIEND_AREA = 49,
    PROMPT_SELECT_HELPER_POKEMON,
    SELECT_HELPER_POKEMON,
    // 52 - 53
    CONFIRM_SEND_HELPER_POKEMON = 54,
    SENT_AOK_MAIL,
    SENT_AOK_MAIL_SAVE_PRE,
    SENT_AOK_MAIL_SAVE_COMPLETE,
    AOK_PASSWORD_DISPLAY,
    // 59 - 60
    DEFAULT_FALLBACK_STATE = 61
};

const MenuItem gUnknown_80DD970[] =
{
    {"Receive SOS Mail", 0x0},
    {"Leave for Rescue", 0x1},
    {"Send A-OK Mail", 0x2},
    {"Delete Mail", 0x3},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DD9EC[] =
{
    {"Delete SOS Mail", 0x5},
    {"Delete A-OK Mail", 0x6},
    {"Delete All Mail", 0x7},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDA48[] =
{
    {"Yes", 0x8},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDA64[] =
{
    {"Yes", 0x8},
    {"No", 0x9},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDA80[] =
{
    {"Yes", 0x8},
    {"No", 0x9},
    {"Cancel", 0xA},
    {NULL, 0xA}
};

const MenuItem gUnknown_80DDAA0[] =
{
    {SendWOPokemon, 0x12},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 SendWOPokemon[] = _("Send w/o Pokémon");

const UnkTextStruct2 gUnknown_80DDACC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x07,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80DDAE4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x06,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};

const MenuItem gUnknown_80DDAFC[] =
{
    {"Confirm", 0xB},
    {"Info", 0xC},
    {NULL, 0xA},
};

const MenuItem gUnknown_80DDB24[] =
{
    {"Game Link cable", 0xD},
    {"Password", 0xF},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

const MenuItem gUnknown_80DDB60[] =
{
    {SendPokemon_80DDB98, 0x11},
    {DontSendPokemon_80DDB80, 0x12},
    {"Cancel", 0xA},
    {NULL, 0xA},
};

ALIGNED(4) const u8 DontSendPokemon_80DDB80[] = _("Don{APOSTROPHE}t Send Pokémon");
ALIGNED(4) const u8 SendPokemon_80DDB98[] = _("Send Pokémon");

#include "data/wonder_mail_1.h"


void SetFriendRescueCounterState(u32 r0);

u32 sub_8027F88(void)
{
  char *monName;
  OpenedFile *faceFile;
  s32 counter;

  ResetUnusedInputStruct();
  sub_800641C(NULL, TRUE, TRUE);
  sUnknown_203B2C0 = MemoryAlloc(sizeof(WonderMailStruct_203B2C0), 8);
  MemoryFill8((u8 *)sUnknown_203B2C0, 0, sizeof(WonderMailStruct_203B2C0));
  sUnknown_203B2C0->unk53C = 0;
  sUnknown_203B2C0->mailIndex = -1;
  sUnknown_203B2C0->speciesNum = -1;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PELIPPER);
  monName = GetMonSpecies(MONSTER_PELIPPER);
  strcpy(gAvailablePokemonNames, monName);
  faceFile = GetDialogueSpriteDataPtr(MONSTER_PELIPPER);
  sUnknown_203B2C0->faceFile = faceFile;
  sUnknown_203B2C0->faceData = faceFile->data;
  sUnknown_203B2C0->unk42C = 0;
  sUnknown_203B2C0->unk42D = 0;
  sUnknown_203B2C0->unk42E = 0;
  sUnknown_203B2C0->unk428 = 2;
  sUnknown_203B2C0->unk42A = 8;
  for(counter = 0; counter < PASSWORD_BUFFER_SIZE; counter++){
    sUnknown_203B2C0->passwordBuffer[counter] = 0;
  }
  sUnknown_203B2C0->fallbackState = DEFAULT_FALLBACK_STATE;
  SetFriendRescueCounterState(INITIALIZE_FRIEND_RESCUE);
  return 1;
}

u32 sub_8028078(void)
{
  
  switch(sUnknown_203B2C0->state) {
    case 0x3c:
        sub_8029B34();
        break;
    case 0x3a:
        sub_8029AD8();
        break;
    case 0x3b:
        sub_8029AF4();
        break;
    case SENT_AOK_MAIL_SAVE_PRE:
        sub_8029A88();
        break;
    case SENT_AOK_MAIL:
        sub_8029AB0();
        break;
    case PROMPT_SELECT_HELPER_POKEMON:
        sub_80297B8();
        break;
    case SELECT_HELPER_POKEMON:
        sub_80297D4();
        break;
    case 0x34:
        sub_8029884();
        break;
    case 0x35:
        sub_8029944();
        break;
    case NO_POKEMON_IN_FRIEND_AREA:
        sub_80299AC();
        break;
    case CONFIRM_SEND_HELPER_POKEMON:
        sub_80299D8();
        break;
    case 0x30:
        sub_8029A6C();
        break;
    case 0x2e:
        sub_8029A18();
        break;
    case 0x2d:
        sub_80295A8();
        break;
    case PROMPT_CHOOSE_AOK_MAIL:
        sub_8029668();
        break;
    case 0x2b:
        sub_8029684();
        break;
    case 0x2c:
        sub_8029740();
        break;
    case 0x2a:
        sub_80295D8();
        break;
    case 0x2f:
        sub_802979C();
        break;
    case NO_MAIL_ROOM:
        sub_8029358();
        break;
    case RECEIVED_FRIEND_SOS_MAIL:
        sub_8029374();
        break;
    case RECEIVED_FRIEND_SOS_MAIL_SAVE_PRE:
        sub_802939C();
        break;
    case PROMPT_SOS_MAIL_PASSWORD:
        sub_80293D8();
        break;
    case 0x27:
        sub_80293F4();
        break;
    case 0x28:
        sub_802955C();
        break;
    case 4:
        sub_80292A4();
        break;
    case FRIEND_RESCUE_COMMUNICATING:
        sub_80292EC();
        break;
    case FRIEND_RESCUE_ERROR:
        sub_802933C();
        break;
    case FRIEND_RESCUE_COMMUNICATING_PRE:
        sub_802958C();
        break;
    case 8:
        sub_8029208();
        break;
    case NO_SOS_MAIL_TO_SEND:
        sub_8028DE8(FRIEND_RESCUE_MAIN);
        break;
    case 0x1b:
        sub_8028F80();
        break;
    case CANT_GO_TO_DUNGEON:
    case FRIEND_RESCUE_FAILED:
        sub_8028FC0();
        break;
    case 0x22:
        sub_8028FDC();
        break;
    case PROMPT_CHOOSE_SOS_MAIL:
        sub_80290D4();
        break;
    case 0x20:
        sub_80290F0();
        break;
    case 0x21:
        sub_80291AC();
        break;
    case 0x1f:
        sub_8029044();
        break;
    case 10:
        sub_8028CFC();
        break;
    case 0xb:
        sub_8028D4C();
        break;
    case 0xd:
    case 0xf:
        sub_8028DE8(0xA);
        break;
    case 0x11:
        sub_8028E08();
        break;
    case NO_SOS_MAIL:
    case NO_AOK_MAIL:
    case NO_MAIL:
        sub_8028DE8(0x19);
        break;
    case PROMPT_DELETE_ALL_MAIL:
        sub_8028E24();
        break;
    case CONFIRM_DELETE_ALL_MAIL_1:
        sub_8028E54();
        break;
    case 0x17:
        sub_8028E84();
        break;
    case 0x18:
        sub_8028EAC();
        break;
    case 0x19:
        sub_8028ED4();
        break;
    case CONFIRM_DELETE_ALL_MAIL_2:
        sub_8028F04();
        break;
    case DELETE_ALL_MAIL_SAVE_PRE:
        sub_8028F30();
        break;
    case 0x16:
        sub_8028F58();
        break;
    case INITIALIZE_FRIEND_RESCUE:
    case FRIEND_RESCUE_MAIN:
        sub_8028BF0();
        break;
    case FRIEND_RESCUE_EXIT_PRE:
    case RECEIVED_FRIEND_SOS_MAIL_SAVE_COMPLETE:
    case SENT_AOK_MAIL_SAVE_COMPLETE:
        ExitFriendRescueCounterMenu();
        break;
    case FRIEND_RESCUE_COUNTER_EXIT:
        return 3;
  }
  return 0;
}

s32 sub_80282DC(u8 *r0)
{
    *r0 = sUnknown_203B2C0->mailIndex;
    return sUnknown_203B2C0->unk53C;
}

void sub_80282FC(void)
{
  if (sUnknown_203B2C0 != NULL) {
    CloseFile(sUnknown_203B2C0->faceFile);
    MemoryFree(sUnknown_203B2C0);
    sUnknown_203B2C0 = NULL;
    sub_8031E10();
    sub_8023C60();
    sub_803084C();
    sub_80155F0();
    sub_80310B4();
    sub_8030DE4();
    sub_802453C();
  }
}

void nullsub_130(void)
{
}

void sub_8028348(void)
{
    s32 linkError;
    switch(sUnknown_203B2C0->state)
    {
        case 0x3B:
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_8031D70(sUnknown_203B2C0->mailIndex, 0);
            break;
        case 0x3C:
            sub_80141B4(gUnknown_80DDBA8, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case AOK_PASSWORD_DISPLAY:
            sub_80141B4(gUnknown_80DDBFC, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x38:
            sub_80141B4(gUnknown_80DDC30, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case SENT_AOK_MAIL:
            switch(sUnknown_203B2C0->unk534)
            {
                // 0x0 - 0x9 included here too...
                case 0x10:
                case 0xF:
                case 0xD:
                    sub_80141B4(gUnknown_80DDC70, 0, &sUnknown_203B2C0->faceFile,0x10d);
                    break;
                case 0xE:
                    break;
            }
            break;
        case SENT_AOK_MAIL_SAVE_COMPLETE:
            sub_80141B4(gUnknown_80DDC30, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case PROMPT_SELECT_HELPER_POKEMON:
            sub_80141B4(gUnknown_80DDCBC, 0, 0,0x101);
            break;
        case SELECT_HELPER_POKEMON:
            if(sub_8023CE8() == 0)
            {
                ResetUnusedInputStruct();
                sub_800641C(NULL, TRUE, TRUE);
                sub_8023868(3, 0, 0, 9);
            }
            break;
        case 0x34:
            sub_8006518(sUnknown_203B2C0->unk35C);
            SetMenuItems(sUnknown_203B2C0->unk21C, sUnknown_203B2C0->unk35C, 3, &gUnknown_80DDAE4, gUnknown_80DDAFC, TRUE, 0, FALSE);
            sub_8023DA4();
            sub_8035CF4(sUnknown_203B2C0->unk21C, 3, TRUE);
            break;
        case NO_POKEMON_IN_FRIEND_AREA:
            sub_8014248(gUnknown_80DDD2C, 0, 0xA, gUnknown_80DDAA0, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case CONFIRM_SEND_HELPER_POKEMON:
            sub_8014248(gUnknown_80DDD88, 0, 8, gUnknown_80DDA80, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x2D:
            sub_8014248(gUnknown_80DDDBC, 0, 8, gUnknown_80DDA64, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case PROMPT_CHOOSE_AOK_MAIL:
            sub_80141B4(gUnknown_80DDDD8, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x2A:
            if(sub_8030894() == 0)
            {
                ResetUnusedInputStruct();
                sub_800641C(NULL, TRUE, TRUE);
                sub_80306A8(WONDER_MAIL_TYPE_AOK, 0, 0, 6);
            }
            break;
        case NO_AOK_MAIL_TO_SEND:
            sub_80141B4(gUnknown_80DDE20, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x30:
            sub_80141B4(gUnknown_80DDE58, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x2E:
            sub_8014248(gUnknown_80DDEC0, 0, 0x11, gUnknown_80DDB60, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case NO_MAIL_ROOM:
            sub_80141B4(gUnknown_80DDF2C, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 4:
            sub_8014248(gUnknown_80DDFB8, 0, 8, gUnknown_80DDA48, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case FRIEND_RESCUE_COMMUNICATING_PRE:
            nullsub_23(FALSE);
            sub_80141B4(gUnknown_80DE01C, 0 , 0, 0);
            break;
        case FRIEND_RESCUE_COMMUNICATING:
            sUnknown_203B2C0->linkError = COMMS_GOOD;
            sub_8011830();
            linkError = sub_8037B28(sUnknown_203B2C0->unk40);
            sUnknown_203B2C0->linkError = linkError;
            if(linkError == COMMS_GOOD)
            {
                switch(sUnknown_203B2C0->unk40)
                {
                    case 3:
                        MemoryFill8((u8 *)&sUnknown_203B2C0->unk48, 0, sizeof(unkStruct_203B480));
                        MemoryFill8((u8 *)&sUnknown_203B2C0->unk78, 0, sizeof(unkStruct_203B480));
                        sUnknown_203B2C0->linkError = sub_8037D64(sUnknown_203B2C0->unk40, &sUnknown_203B2C0->unk48, &sUnknown_203B2C0->unk78);
                        break;
                    case 4:
                        MemoryFill8((u8 *)&sUnknown_203B2C0->unkA8, 0, sizeof(WonderMailStruct_203B2C0_sub));
                        MemoryFill8((u8 *)&sUnknown_203B2C0->unk130, 0, sizeof(WonderMailStruct_203B2C0_sub));
                        sUnknown_203B2C0->unkA8.pokemon.speciesNum = 0;
                        sUnknown_203B2C0->unk130.pokemon.speciesNum = 0;
                        sUnknown_203B2C0->unkA8.mail = *GetMailatIndex(sUnknown_203B2C0->mailIndex);
                        if(sUnknown_203B2C0->speciesNum != -1)
                        {
                            sUnknown_203B2C0->unkA8.pokemon = gRecruitedPokemonRef->pokemon[sUnknown_203B2C0->speciesNum];
                        }
                        sUnknown_203B2C0->linkError = sub_8037D64(sUnknown_203B2C0->unk40, &sUnknown_203B2C0->unkA8, &sUnknown_203B2C0->unk130);
                        break;
                }
                if(sUnknown_203B2C0->linkError == COMMS_GOOD)
                {   
                    switch(sUnknown_203B2C0->unk40)
                    {
                        case 3:
                            sUnknown_203B2C0->linkError = sub_80381F4(3, &sUnknown_203B2C0->unk48, &sUnknown_203B2C0->unk78);
                            break;
                        case 4:
                            sUnknown_203B2C0->linkError = sub_80381F4(4, &sUnknown_203B2C0->unkA8, &sUnknown_203B2C0->unk130);
                            break;
                    }
                }
                xxx_call_start_bg_music();
            }
            else
            {
                xxx_call_start_bg_music();
            }
            break;
        case RECEIVED_FRIEND_SOS_MAIL:
            switch(sUnknown_203B2C0->unk534)
            {
                // 0x0 - 0x9 included here too...
                case 0x10:
                case 0xF:
                case 0xD:
                    sub_80141B4(gUnknown_80DE06C, 0, &sUnknown_203B2C0->faceFile,0x10d);
                    break;
                case 0xE:
                    break;
            }
            break;
        case RECEIVED_FRIEND_SOS_MAIL_SAVE_COMPLETE:
            sub_80141B4(gUnknown_80DE0C0, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case PROMPT_SOS_MAIL_PASSWORD:
            sub_80141B4(gUnknown_80DE124, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x27:
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_80151C0(4, sUnknown_203B2C0->passwordBuffer);
            break;
        case 8:
            switch(sUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8014248(gUnknown_80DE178, 0, 0xD, gUnknown_80DDB24, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
                    break;
                case 2:
                    sub_8014248(gUnknown_80DE1B4, 0, 0xD, gUnknown_80DDB24, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
                    break;
            }
            break;
        case NO_SOS_MAIL_TO_SEND:
            sub_80141B4(gUnknown_80DE1E4, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x1B:
            sub_80141B4(gUnknown_80DE280, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case CANT_GO_TO_DUNGEON:
            sub_80141B4(gUnknown_80DE2B0, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case FRIEND_RESCUE_FAILED:
            sub_80141B4(gUnknown_80DE368, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x22:
            sub_8014248(gUnknown_80DDDBC, 0, 8, gUnknown_80DDA64, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case PROMPT_CHOOSE_SOS_MAIL:
            sub_80141B4(gUnknown_80DE430, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x1F:
            if(sub_8030894() == 0)
            {
                ResetUnusedInputStruct();
                sub_800641C(NULL, TRUE, TRUE);
                // SOS Mail
                sub_80306A8(2, 0, 0, 6);
            }
            break;
        case 0x20:
        case 0x2B:
            sub_8006518(sUnknown_203B2C0->unk35C);
            SetMenuItems(sUnknown_203B2C0->unk21C, sUnknown_203B2C0->unk35C, 3, &gUnknown_80DDACC, gUnknown_80DDAFC, TRUE, 0, FALSE);
            sub_803092C();
            sub_8035CF4(sUnknown_203B2C0->unk21C, 3, TRUE);
            break;
        case 0xA:
            sUnknown_203B2C0->mailCount = CountAllMail();
            switch((u32)sUnknown_203B2C0->unk538)
            {
                case 5:
                    sub_8030F58(2);
                    break;
                case 6:
                    sub_8030F58(4);
                    break;
                default:
                case 7:
                    break;
            }
            break;
        case 0xB:
            sub_8014248(gUnknown_80DE48C, 0, 5, gUnknown_80DD9EC, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case 0xD:
            sub_80141B4(gUnknown_80DE4B8, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case NO_SOS_MAIL:
            sub_80141B4(gUnknown_80DE4F0, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0xF:
            sub_80141B4(gUnknown_80DE524, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case NO_AOK_MAIL:
            sub_80141B4(gUnknown_80DE614, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x11:
            sub_80141B4(gUnknown_80DE648, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case NO_MAIL:
            sub_80141B4(gUnknown_80DE694, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case PROMPT_DELETE_ALL_MAIL:
            sub_8014248(gUnknown_80DE6D4, 0, 8, gUnknown_80DDA48, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case CONFIRM_DELETE_ALL_MAIL_1:
            sub_8014248(gUnknown_80DE754, 0, 8, gUnknown_80DDA48, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case 0x17:
            sub_80141B4(gUnknown_80DE7B8, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x18:
            sub_80141B4(gUnknown_80DE7E8, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x19:
            sub_8014248(gUnknown_80DE808, 0, 8, gUnknown_80DDA64, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case CONFIRM_DELETE_ALL_MAIL_2:
            sub_80141B4(gUnknown_80DE830, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case DELETE_ALL_MAIL_SAVE_PRE:
            sub_80141B4(gUnknown_80DE864, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case 0x16:
            sub_80141B4(gUnknown_80DE7E8, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case INITIALIZE_FRIEND_RESCUE:
            sub_8014248(gUnknown_80DE8B4, 0, 0, gUnknown_80DD970, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case FRIEND_RESCUE_MAIN:
            sub_8014248(gUnknown_80DE918, 0, 0, gUnknown_80DD970, 0, 4, 0, &sUnknown_203B2C0->faceFile,0xC);
            break;
        case 2:
            sub_80141B4(gUnknown_80DE93C, 0, &sUnknown_203B2C0->faceFile,0x10d);
            break;
        case FRIEND_RESCUE_COUNTER_EXIT:
            break;
    }
}


void SetFriendRescueCounterState(u32 state)
{
    sUnknown_203B2C0->state = state;
    nullsub_130();
    sub_8028348();
}

// Wonder Mail Linking...
void PrintFriendRescueCounterError(u32 errorCode)
{
    switch(errorCode)
    {
        case COMMS_GOOD:
            break;
        case 1:
        case COMMS_NO_RESPONSE:
            sub_80141B4(gWonderMailErrorText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_INCORRECT_NUM_SYSTEMS:
            sub_80141B4(gWonderMailNumGBAsText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_DIFFERENT_MODES:
            sub_80141B4(gWonderMailWrongModeText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 5:
            sub_80141B4(gWonderMailErrorText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NO_ROOM_STORAGE:
            sub_80141B4(gWonderMailStorageFullText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_DUPLICATE_MAIL:
            sub_80141B4(gWonderMailDuplicateText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NOT_ELIGIBLE_1:
            sub_80141B4(gWonderMailNotEligibleReceiveText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NOT_ELIGIBLE_2:
            sub_80141B4(gWonderMailNotEligibleReceiveText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NO_ROOM_MAIL:
            sub_80141B4(gWonderMailNoRoomText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case 14:
            sub_80141B4(gWonderMailErrorText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        case COMMS_NOT_READY:
            sub_80141B4(gWonderMailFriendErrorText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
            break;
        default:
            break;
    }
}

void sub_8028BF0(void)
{
    u32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    sUnknown_203B2C0->unk40 = 8;
    sUnknown_203B2C0->speciesNum = -1;
    switch(menuChoice)
    {
        case 0:
            sUnknown_203B2C0->unk40 = 3;
            sUnknown_203B2C0->unk538 = 0;
            if(FindOpenMailSlot() != -1)
            {
                SetFriendRescueCounterState(8);
            }
            else
            {
                SetFriendRescueCounterState(NO_MAIL_ROOM);
            }
            break;
        case 1:
            if(CountMailType(2) != 0)
            {
                SetFriendRescueCounterState(PROMPT_CHOOSE_SOS_MAIL);
            }
            else
            {
                SetFriendRescueCounterState(NO_SOS_MAIL_TO_SEND);
            }
            break;
        case 2:
            sUnknown_203B2C0->unk40 = 4;
            sUnknown_203B2C0->unk538 = 2;
            if(CountMailType(WONDER_MAIL_TYPE_AOK) != 0)
            {
                SetFriendRescueCounterState(PROMPT_CHOOSE_AOK_MAIL);
            }
            else
            {
                SetFriendRescueCounterState(NO_AOK_MAIL_TO_SEND);
            }
            break;
        case 3:
            SetFriendRescueCounterState(11);
            break;
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_EXIT_PRE);
            break;
        default:
            break;
    }
}


void ExitFriendRescueCounterMenu()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(FRIEND_RESCUE_COUNTER_EXIT);
}

void sub_8028CFC()
{
    s32 temp;
    u32 newMailCount;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(sub_8031050())
    {
        case 2:
        case 3:
            newMailCount = CountAllMail();
            sub_80310B4();
            if(newMailCount != sUnknown_203B2C0->mailCount)
            {
                SetFriendRescueCounterState(0x17);
            }
            else
            {
                SetFriendRescueCounterState(0x19);
            }
            break;
        default:
            break;
    }
}

void sub_8028D4C()
{
    s32 menuChoice;

    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    sUnknown_203B2C0->unk538 = menuChoice;
    switch(sUnknown_203B2C0->unk538)
    {
        case 5:
            if(HasNoWonderMailType(2))
                SetFriendRescueCounterState(NO_SOS_MAIL);
            else
                SetFriendRescueCounterState(0xD);
            break;
        case 6:
            if(HasNoWonderMailType(WONDER_MAIL_TYPE_AOK))
                SetFriendRescueCounterState(NO_AOK_MAIL);
            else
                SetFriendRescueCounterState(0xF);
            break;
        case 7:
            if(HasNoWonderMailType(WONDER_MAIL_TYPE_NONE))
                SetFriendRescueCounterState(NO_MAIL);
            else
                SetFriendRescueCounterState(0x11);
            break;
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
        default:
            break;
    }
}

void sub_8028DE8(u32 newState)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(newState);
}

void sub_8028E08()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(PROMPT_DELETE_ALL_MAIL);
}

void sub_8028E24()
{
    s32 menuChoice;

    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 8:
            SetFriendRescueCounterState(CONFIRM_DELETE_ALL_MAIL_1);
            break;
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
        default:
            break;
    }
}

void sub_8028E54()
{
    s32 menuChoice;

    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 8:
            SetFriendRescueCounterState(CONFIRM_DELETE_ALL_MAIL_2);
            break;
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
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
    SetFriendRescueCounterState(0x18);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
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
        SetFriendRescueCounterState(0x19);
    }
}

void sub_8028ED4()
{
    s32 menuChoice;

    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice){
        case 8:
            SetFriendRescueCounterState(0xB);
            break;
        case 9:
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_EXIT_PRE);
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
            DeleteMailAtIndex(counter);
        }
        SetFriendRescueCounterState(DELETE_ALL_MAIL_SAVE_PRE);
    }
}

void sub_8028F30()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(0x16);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
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
        SetFriendRescueCounterState(FRIEND_RESCUE_EXIT_PRE);
    }
}

void sub_8028F80()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_809927C(sUnknown_203B2C0->mailIndex);
    sUnknown_203B2C0->unk53C = 1;
    SetFriendRescueCounterState(FRIEND_RESCUE_COUNTER_EXIT);
}

void sub_8028FC0()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
}

void sub_8028FDC(void)
{
    s32 menuChoice;
    unkStruct_203B480 *mail;

    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 8:
            mail = GetMailatIndex(sUnknown_203B2C0->mailIndex);
            if(!sub_80A2824(mail->unk4.dungeon.id))
            {
                SetFriendRescueCounterState(CANT_GO_TO_DUNGEON);
            }
            else if(mail->rescuesAllowed <= 0)
            {
                SetFriendRescueCounterState(FRIEND_RESCUE_FAILED);
            }
            else
            {
                SetFriendRescueCounterState(0x1B);
            }
            break;
        case 9:
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
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
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
        case 3:
            sUnknown_203B2C0->mailIndex = sub_80307EC();
            SetFriendRescueCounterState(0x20);
            break;
        case 4:
            sUnknown_203B2C0->fallbackState = 0x1F;
            sUnknown_203B2C0->mailIndex = sub_80307EC();
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_8030D40(sUnknown_203B2C0->mailIndex, 0);
            SetFriendRescueCounterState(0x21);
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
    SetFriendRescueCounterState(0x1F);
}

void sub_80290F0(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8030768(0);
    if(sub_8012FD8(&(sUnknown_203B2C0->unk21C[3])) == 0)
    {
        sub_8013114(&(sUnknown_203B2C0->unk21C[3]), &menuAction);
    }
    switch(menuAction)
    {
        case 11:
            sub_803084C();
            SetFriendRescueCounterState(0x22);
            break;
        case 12:
            sUnknown_203B2C0->fallbackState = DEFAULT_FALLBACK_STATE;
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_8030D40(sUnknown_203B2C0->mailIndex, 0);
            SetFriendRescueCounterState(0x21);
            break;
        case 4:
        case 10:
            sub_8035CC0(sUnknown_203B2C0->unk35C, 2);
            sub_8030810(1);
            SetFriendRescueCounterState(0x1F);
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
            sub_800641C(sUnknown_203B2C0->unk3BC, TRUE, TRUE);
            sub_803092C();
            if(sUnknown_203B2C0->fallbackState == DEFAULT_FALLBACK_STATE)
            {
                sub_8035CF4(sUnknown_203B2C0->unk21C, 3, TRUE);
                SetFriendRescueCounterState(0x20);
            }
            else
            {
                SetFriendRescueCounterState(sUnknown_203B2C0->fallbackState);
            }
        default:
            break;
    }
}

void sub_8029208(void)
{
    s32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {

        case 13:
        case 14:
            sUnknown_203B2C0->unk534 = 13;
            switch(sUnknown_203B2C0->unk538)
            {
                case 0:
                    SetFriendRescueCounterState(4);
                    break;
                case 2:
                    SetFriendRescueCounterState(0x30);
                    break;
                default:
                    return;
            }
            break;
        case 15:
            sUnknown_203B2C0->unk534 = 15;
            switch(sUnknown_203B2C0->unk538)
            {
                case 0:
                    SetFriendRescueCounterState(PROMPT_SOS_MAIL_PASSWORD);
                    break;
                case 2:
                    SetFriendRescueCounterState(AOK_PASSWORD_DISPLAY);
                    break;
                default:
                    return;
            }
            break;
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
    }
}

void sub_80292A4(void)
{
    s32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 8:
            switch(sUnknown_203B2C0->unk538)
            {
                case 0:
                case 2:
                    SetFriendRescueCounterState(FRIEND_RESCUE_COMMUNICATING_PRE);
                    break;
            }
            break;
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
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
    if(sUnknown_203B2C0->linkError == COMMS_GOOD)
    {
        switch(sUnknown_203B2C0->unk538)
        {
            case 0:
                SetFriendRescueCounterState(RECEIVED_FRIEND_SOS_MAIL);
                break;
            case 2:
                SetFriendRescueCounterState(SENT_AOK_MAIL);
                break;
        }
    }
    else
    {
        PrintFriendRescueCounterError(sUnknown_203B2C0->linkError);
        SetFriendRescueCounterState(FRIEND_RESCUE_ERROR);
    }
}

void sub_802933C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
}

void sub_8029358(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
}

void sub_8029374(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(RECEIVED_FRIEND_SOS_MAIL_SAVE_PRE);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
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
            SetFriendRescueCounterState(RECEIVED_FRIEND_SOS_MAIL_SAVE_COMPLETE);
        }
        else
        {
            SetFriendRescueCounterState(0x2);
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
    SetFriendRescueCounterState(0x27);
}

void sub_80293F4(void)
{
    u32 return_var;
    unkStruct_203B480 mail;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&mail, 0, sizeof(unkStruct_203B480));
    switch(return_var)
    {
        case 3:
                switch(sub_8039068(PASSWORD_ENTRY_SOS_MAIL_MODE, (sUnknown_203B2C0->passwordBuffer), &mail))
                {
                    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                        sub_8014248(gWonderMailPasswordIncorrectText, 0, 8, gUnknown_80DDA48, 0, 4, 0, &sUnknown_203B2C0->faceFile, 0xC);
                        SetFriendRescueCounterState(0x28);
                        break;
                    case PASSWORD_ENTRY_NOT_SOS_MAIL:
                        sub_80141B4(gWonderMailSOSPasswordIncorrectText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
                        SetFriendRescueCounterState(FRIEND_RESCUE_ERROR);
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_SOS_MAIL:
                        sub_80141B4(gWonderMailDuplicateText, 0, &sUnknown_203B2C0->faceFile, 0x10d);
                        SetFriendRescueCounterState(FRIEND_RESCUE_ERROR);
                        break;
                    case PASSWORD_ENTRY_SOS_MAIL_SUCCESS:
                        sub_8095274(mail.unk10.unk10);
                        mail.mailType = 2;
                        sub_80951BC(&mail);
                        sub_80141B4(gWonderMailAOKMailReceivedText, 0, &sUnknown_203B2C0->faceFile, 0x101);
                        SetFriendRescueCounterState(0x23);
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
            sub_800641C(sUnknown_203B2C0->unk3BC, TRUE, TRUE);
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
        default:
            break;
    }
}

void sub_802955C(void)
{
    s32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 8:
            SetFriendRescueCounterState(PROMPT_SOS_MAIL_PASSWORD);
            break;
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
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
    SetFriendRescueCounterState(FRIEND_RESCUE_COMMUNICATING);
}

void sub_80295A8(void)
{
    s32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 8:
            SetFriendRescueCounterState(0x8);
            break;
        case 9:
        case 10:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;

    }
}

void sub_80295D8(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
        case 3:
            sUnknown_203B2C0->mailIndex = sub_80307EC();
            SetFriendRescueCounterState(0x2B);
            break;
        case 4:
            sUnknown_203B2C0->fallbackState = 0x2A;
            sUnknown_203B2C0->mailIndex = sub_80307EC();
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_8030D40(sUnknown_203B2C0->mailIndex, 0);
            SetFriendRescueCounterState(0x2C);
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
    SetFriendRescueCounterState(0x2A);
}

void sub_8029684(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8030768(0);
    if(sub_8012FD8(&(sUnknown_203B2C0->unk21C[3])) == 0)
    {
        sub_8013114(&(sUnknown_203B2C0->unk21C[3]), &menuAction);
    }
    switch(menuAction)
    {
        case 0xB:
            sub_803084C();
            SetFriendRescueCounterState(0x2D);
            break;
        case 0xC:
            sUnknown_203B2C0->fallbackState = DEFAULT_FALLBACK_STATE;
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_8030D40(sUnknown_203B2C0->mailIndex, 0);
            SetFriendRescueCounterState(0x2C);
            break;
        case 0x4:
        case 0xA:
            sub_8035CC0(sUnknown_203B2C0->unk35C,2);
            sub_8030810(1);
            SetFriendRescueCounterState(0x2A);
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
            sub_800641C(sUnknown_203B2C0->unk3BC, TRUE, TRUE);
            sub_803092C();
            if(sUnknown_203B2C0->fallbackState == DEFAULT_FALLBACK_STATE)
            {
                sub_8035CF4(sUnknown_203B2C0->unk21C, 3, TRUE);
                SetFriendRescueCounterState(0x2B);
            }
            else
            {
                SetFriendRescueCounterState(sUnknown_203B2C0->fallbackState);
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
    SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
}

void sub_80297B8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(SELECT_HELPER_POKEMON);
}

void sub_80297D4(void)
{
    switch(sub_8023A94(TRUE))
    {
        case 2:
            sub_8023C60();
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            sUnknown_203B2C0->speciesNum = -1;
            break;
        case 3:
            sUnknown_203B2C0->speciesNum = sub_8023B44();
            SetFriendRescueCounterState(0x34);
            break;
        case 4:
            sUnknown_203B2C0->fallbackState = SELECT_HELPER_POKEMON;
            sUnknown_203B2C0->speciesNum = sub_8023B44();
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_8024458(sUnknown_203B2C0->speciesNum, 0);
            SetFriendRescueCounterState(0x35);
            break;
    }
}

void sub_8029884(void)
{
    s32 menuAction;
    menuAction = -1;
    sub_8023A94(FALSE);
    if(sub_8012FD8(&(sUnknown_203B2C0->unk21C[3])) == 0)
    {
        sub_8013114(&(sUnknown_203B2C0->unk21C[3]), &menuAction);
    }
    switch(menuAction)
    {
        case 0xB:
            sub_8023C60();
            SetFriendRescueCounterState(4);
            break;
        case 0xC:
            sUnknown_203B2C0->fallbackState = DEFAULT_FALLBACK_STATE;
            sub_8006518(sUnknown_203B2C0->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(NULL, TRUE, TRUE);
            sub_8024458(sUnknown_203B2C0->speciesNum, 0);
            SetFriendRescueCounterState(0x35);
            break;
        case 0x4:
        case 0xA:
            sub_8035CC0(sUnknown_203B2C0->unk35C, 3);
            sub_8023B7C(1);
            SetFriendRescueCounterState(SELECT_HELPER_POKEMON);
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
            sub_800641C(sUnknown_203B2C0->unk3BC, TRUE, TRUE);
            sub_8023B7C(1);
            if(sUnknown_203B2C0->fallbackState == DEFAULT_FALLBACK_STATE)
            {
                sub_8035CF4(sUnknown_203B2C0->unk21C, 3, TRUE);
                SetFriendRescueCounterState(0x34);
            }
            else
            {
                SetFriendRescueCounterState(sUnknown_203B2C0->fallbackState);
            }

    }
}

void sub_80299AC(void)
{
    s32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 0x12:
            SetFriendRescueCounterState(4);
            break;
        case 0xA:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
        default:
            break;
    }
}

void sub_80299D8(void)
{
    s32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {

        case 8:
            SetFriendRescueCounterState(4);
            break;
        case 9:
            SetFriendRescueCounterState(PROMPT_SELECT_HELPER_POKEMON);
            break;
        case 0xA:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
            break;
    }
}

void sub_8029A18(void)
{
    s32 menuChoice;
    if(sub_80144A4(&menuChoice) != 0)
    {
        return;
    }
    switch(menuChoice)
    {
        case 0x11:
            if(sub_8024108(3) != 0)
            {
                SetFriendRescueCounterState(NO_POKEMON_IN_FRIEND_AREA);
            }
            else
            {
                SetFriendRescueCounterState(PROMPT_SELECT_HELPER_POKEMON);
            }
            break;
        case 0x12:
            SetFriendRescueCounterState(0x4);
            break;
        case 0xA:
            SetFriendRescueCounterState(FRIEND_RESCUE_MAIN);
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
    SetFriendRescueCounterState(0x2E);
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
        SetFriendRescueCounterState(SENT_AOK_MAIL_SAVE_COMPLETE);
    }
}

void sub_8029AB0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(SENT_AOK_MAIL_SAVE_PRE);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
}

void sub_8029AD8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    SetFriendRescueCounterState(0x3B);
}

void sub_8029AF4(void)
{
    switch(sub_8031DCC())
    {

        case 2:
        case 3:
            sub_8031E10();
            ResetUnusedInputStruct();
            sub_800641C(sUnknown_203B2C0->unk3BC, TRUE, TRUE);
            SetFriendRescueCounterState(0x3C);
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
    SetFriendRescueCounterState(FRIEND_RESCUE_COUNTER_EXIT);
}
