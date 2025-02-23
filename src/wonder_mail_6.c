#include "global.h"
#include "globaldata.h"
#include "input.h"
#include "memory.h"
#include "text.h"
#include "pokemon.h"
#include "code_8094F88.h"
#include "menu_input.h"
#include "string_format.h"
#include "wonder_mail_4.h"
#include "wonder_mail_5.h"

struct unkStruct_203B328
{
    // size: 0x11C
    u32 state;
    u8 mailIndex;
    MenuStruct unk8;
    MenuStruct unk58;
    Windows unkA8;
    /* 0x108 */ struct MonPortraitMsg monPortrait;
    u32 wonderMailType;
};
static EWRAM_INIT struct unkStruct_203B328 *gUnknown_203B328 = {NULL};

extern unkStruct_203B480 *gUnknown_203B480;

enum MenuActions {
   CANCEL_ACTION = 1,
   YES_ACTION,
   NO_ACTION,
   DELETE_ACTION,
   INFO_ACTION,
   DELETE_ALL_MAIL_ACTION, // Unused
};

const MenuItem gUnknown_80E0948[] =
{
    {"Yes", YES_ACTION},
    {"No", NO_ACTION},
    {NULL, CANCEL_ACTION}
};

const MenuItem gUnknown_80E0968[] =
{
    {"Delete", DELETE_ACTION},
    {"Info", INFO_ACTION},
    {NULL, CANCEL_ACTION}
};

const Window gUnknown_80E0990 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
const Window gUnknown_80E09A8 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x0B,
    0x08, 0x03,
    0x03, 0x00,
    NULL
};
const Window gUnknown_80E09C0 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x11, 0x0F,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

ALIGNED(4) const u8 gUnknown_80E09D8[] = _(
        " ...Uh, no?\n"
        "You don't have any {COLOR CYAN_G}SOS Mail{RESET}.");

ALIGNED(4) const u8 gUnknown_80E0A0C[] = _(
        " ...Uh, no?\n"
        "You don't have any {COLOR CYAN_G}A-OK Mail{RESET}.");

static void sub_8031300(void);
static void HandleWonderMail6MainMenu(void);
static void HandleWonderMail6DeleteMailMenu(u32);
static void sub_8031498(void);
static void sub_80310FC();
static void sub_8031258();

enum States {
    INIT_STATE,
    MAIN_MENU,
    DELETE_SINGLE_MAIL_STATE,
    DELETE_ALL_MAIL_STATE,
    INFO_STATE,
};

bool8 sub_8030F58(u32 wonderMailType)
{
  OpenedFile *file;

  ResetUnusedInputStruct();
  ShowWindows(NULL, TRUE, TRUE);
  if (gUnknown_203B328 == NULL) {
    gUnknown_203B328 = MemoryAlloc(sizeof(struct unkStruct_203B328),8);
    MemoryFill8(gUnknown_203B328,0,sizeof(struct unkStruct_203B328));
  }
  gUnknown_203B328->wonderMailType = wonderMailType;
  file = GetDialogueSpriteDataPtr(MONSTER_PELIPPER);
  gUnknown_203B328->monPortrait.faceFile = file;
  gUnknown_203B328->monPortrait.faceData = (struct PortraitGfx *) file->data;
  gUnknown_203B328->monPortrait.spriteId = 0;
  gUnknown_203B328->monPortrait.flip = FALSE;
  gUnknown_203B328->monPortrait.unkE = 0;
  gUnknown_203B328->monPortrait.pos.x = 2;
  gUnknown_203B328->monPortrait.pos.y = 8;

  if (HasNoWonderMailType(wonderMailType)) {
    switch(wonderMailType)
    {
        case WONDER_MAIL_TYPE_SOS_1:
            // "You don't have any {COLOR CYAN_G}SOS Mail{RESET}.\0"
            CreateDialogueBoxAndPortrait(gUnknown_80E09D8,0,&gUnknown_203B328->monPortrait,0x101);
            break;
        case WONDER_MAIL_TYPE_AOK:
            // "You don't have any {COLOR CYAN_G}A-OK Mail{RESET}.\0"
            CreateDialogueBoxAndPortrait(gUnknown_80E0A0C,0,&gUnknown_203B328->monPortrait,0x101);
            break;
    }
    gUnknown_203B328->state = 5;
  }
  else {
    gUnknown_203B328->state = INIT_STATE;
    sub_80306A8(wonderMailType,0,0,8);
  }
  return TRUE;
}

s32 sub_8031050(void)
{
    switch(gUnknown_203B328->state)
    {
        case INIT_STATE:
            sub_8031300();
            break;
        case MAIN_MENU:
            HandleWonderMail6MainMenu();
            break;
        case DELETE_SINGLE_MAIL_STATE:
        case DELETE_ALL_MAIL_STATE:
            HandleWonderMail6DeleteMailMenu(gUnknown_203B328->state);
            break;
        case INFO_STATE:
            sub_8031498();
            break;
        case 5:
        case 6:
            return 3;
    }
    return 0;
}

void sub_80310B4(void)
{
    sub_803084C();
    if (gUnknown_203B328 != NULL) {
        CloseFile(gUnknown_203B328->monPortrait.faceFile);
        MemoryFree(gUnknown_203B328);
        gUnknown_203B328 = NULL;
    }
}

void sub_80310E4(u32 newState)
{
    gUnknown_203B328->state = newState;
    sub_80310FC();
    sub_8031258();
}

static void sub_80310FC(void)
{
    RestoreUnkTextStruct_8006518(&gUnknown_203B328->unkA8);
    switch(gUnknown_203B328->state)
    {
        case INIT_STATE:
            gUnknown_203B328->unkA8.id[1] = gUnknown_80E0990;
            gUnknown_203B328->unkA8.id[2] = gUnknown_80E0990;
            gUnknown_203B328->unkA8.id[3] = gUnknown_80E0990;
            break;
        case MAIN_MENU:
            gUnknown_203B328->unkA8.id[1] = gUnknown_80E09A8;
            gUnknown_203B328->unkA8.id[2] = gUnknown_80E0990;
            gUnknown_203B328->unkA8.id[3] = gUnknown_80E0990;
            sub_8012CAC(&gUnknown_203B328->unkA8.id[1], gUnknown_80E0968);
            break;
        case DELETE_SINGLE_MAIL_STATE:
        case DELETE_ALL_MAIL_STATE:
            gUnknown_203B328->unkA8.id[2] = gUnknown_80E09C0;
            sub_8012CAC(&gUnknown_203B328->unkA8.id[2], gUnknown_80E0948);
            break;
        case INFO_STATE:
            gUnknown_203B328->unkA8.id[0] = gUnknown_80E0990;
            gUnknown_203B328->unkA8.id[1] = gUnknown_80E0990;
            gUnknown_203B328->unkA8.id[2] = gUnknown_80E0990;
            gUnknown_203B328->unkA8.id[3] = gUnknown_80E0990;
            break;
        case 5:
        case 6:
        default:
            ResetUnusedInputStruct();
            ShowWindows(NULL, TRUE, TRUE);
            break;
    }
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B328->unkA8, TRUE, TRUE);
}

static void sub_8031258(void)
{
    switch(gUnknown_203B328->state)
    {
        case INIT_STATE:
            sub_8030810(1);
            break;
        case MAIN_MENU:
            sub_803092C();
            sub_8012D60(&gUnknown_203B328->unk8, gUnknown_80E0968, NULL, NULL, DELETE_ACTION, 1);
            break;
        case DELETE_SINGLE_MAIL_STATE:
        case DELETE_ALL_MAIL_STATE:
            sub_803092C();
            sub_8012EA4(&gUnknown_203B328->unk8, 0);
            sub_8012D60(&gUnknown_203B328->unk58, gUnknown_80E0948, NULL, NULL, NO_ACTION, 2);
            break;
        case INFO_STATE:
            sub_8030D40(gUnknown_203B328->mailIndex, 3);
            break;
        case 5:
        case 6:
        default:
            break;
    }
}

static void sub_8031300(void)
{
    switch(sub_8030768(1))
    {
        case 3:
            gUnknown_203B328->mailIndex = sub_80307EC();
            sub_80310E4(MAIN_MENU);
            break;
        case 4:
            gUnknown_203B328->mailIndex = sub_80307EC();
            sub_80310E4(INFO_STATE);
            break;
        case 2:
            sub_80310E4(6);
            break;
        case 0:
        case 1:
            break;
    }
}

static void HandleWonderMail6MainMenu(void)
{
  s32 menuAction;

  menuAction = 0;
  sub_8030768(0);
  if (!sub_8012FD8(&gUnknown_203B328->unk8)) {
    sub_8013114(&gUnknown_203B328->unk8,&menuAction);
  }

  switch(menuAction)
  {
    case CANCEL_ACTION:
        sub_80310E4(INIT_STATE);
        break;
    case DELETE_ALL_MAIL_ACTION:
        sub_80310E4(DELETE_ALL_MAIL_STATE);
        break;
    case DELETE_ACTION:
        sub_80310E4(DELETE_SINGLE_MAIL_STATE);
        break;
    case INFO_ACTION:
        sub_80310E4(INFO_STATE);
        break;

  }
}

static void HandleWonderMail6DeleteMailMenu(u32 state)
{
  s32 index;
  s32 menuAction;
  unkStruct_203B480 *unused;

  menuAction = 0;
  sub_8030768(0);
  sub_8012FD8(&gUnknown_203B328->unk8);
  if (!sub_8012FD8(&gUnknown_203B328->unk58)) {
    sub_8013114(&gUnknown_203B328->unk58,&menuAction);
  }

  switch(menuAction)
  {
    case CANCEL_ACTION:
    case NO_ACTION:
        sub_80310E4(INIT_STATE);
        break;
    case YES_ACTION:
        switch(state)
        {
            case DELETE_SINGLE_MAIL_STATE:
                DeleteMailAtIndex(gUnknown_203B328->mailIndex);
                break;
            case DELETE_ALL_MAIL_STATE:
                for(index = 0; index < 0x20; index++)
                {
                    unused = &gUnknown_203B480[index];
                    gUnknown_203B480[index].mailType = 0;
                    unused = &gUnknown_203B480[index];
                    gUnknown_203B480[index].item.id = ITEM_NOTHING;
                }
                break;
        }
        if ((gUnknown_203B328->wonderMailType == WONDER_MAIL_TYPE_SOS_1) || (gUnknown_203B328->wonderMailType == WONDER_MAIL_TYPE_AOK)) {
            if (HasNoWonderMailType(gUnknown_203B328->wonderMailType)) {
                sub_80310E4(5);
            }
            else {
                sub_80310E4(INIT_STATE);
            }
        }
        break;
  }
}

static void sub_8031498(void)
{
    switch(sub_8030DA0())
    {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
            sub_8030DE4();
            sub_80310E4(INIT_STATE);
            break;
    }
}

