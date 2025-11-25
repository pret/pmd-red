#include "global.h"
#include "globaldata.h"
#include "constants/item.h"
#include "constants/wonder_mail.h"
#include "code_800D090.h"
#include "code_802F204.h"
#include "code_8094F88.h"
#include "adventure_info.h"
#include "code_8099360.h"
#include "event_flag.h"
#include "game_options.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "rescue_team_info.h"
#include "save.h"
#include "save_write.h"
#include "string_format.h"
#include "text_1.h"
#include "ground_main.h"
#include "code_803C1B4.h"

struct unkStruct_203B2C8
{
    // size: 0x140
    /* 0x0 */ u8 currState;
    /* 0x1 */ u8 unk1;
    /* 0x4 */ MonPortraitMsg monPortrait;
    /* 0x14 */ u8 teamName[4]; // Figure out size of this buffer
    u8 fill18[0x114 - 0x18];
    unkStruct_802F204 unk114;
    u32 fill13C;
};

enum States {
    INIT_STATE,
    EXIT_STATE = 5
};

static EWRAM_INIT struct unkStruct_203B2C8 *sUnknown_203B2C8 = {NULL};

extern void sub_802B548(u32);

extern void sub_802B560(void);
extern void sub_802B57C(void);
extern void sub_802B5B8(void);
extern void sub_802B5FC(void);
extern void sub_802B624(void);

ALIGNED(4) const char gRescueTeamNamePlaceholder[] = "????";

ALIGNED(4) const char gUnknown_80DF9F8[] = _(
	" Oh, hello!\n"
	"Your rescue mission went well, didn't it?\n"
	"I wouldn't expect any less, {COLOR CYAN_G}%s{RESET}!{EXTRA_MSG}"
	" Well, well!\n"
	"Here is your reward from the Pokémon\n"
	"Rescue Organization!");

ALIGNED(4) const char gUnknown_80DFAA8[] = _(
	" I hope you will keep on\n"
	"rescuing your friends in\n"
	"dire straits.{EXTRA_MSG}"
	" And now, I must save\n"
	"your adventure.");

ALIGNED(4) const char gUnknown_80DFB14[] = _(
	" Oh, yes, that's right.\n"
	"Please don't forget to send an {COLOR CYAN_G}A-OK Mail{RESET}\n"
	"to the friend you just rescued.{EXTRA_MSG}"
	" Please give me a shout if\n"
	"you would like to send {COLOR CYAN_G}A-OK Mail{RESET}.");

u8 sub_802B2D4(void)
{
  OpenedFile *faceFile;

  ResetUnusedInputStruct();
  ShowWindows(NULL, TRUE, TRUE);
  sUnknown_203B2C8 = MemoryAlloc(sizeof(struct unkStruct_203B2C8),8);
  MemoryFill8(sUnknown_203B2C8,0,sizeof(struct unkStruct_203B2C8));
  sUnknown_203B2C8->unk1 = -1;
  CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_PELIPPER);
  faceFile = GetDialogueSpriteDataPtr(MONSTER_PELIPPER);
  sUnknown_203B2C8->monPortrait.faceFile = faceFile;
  sUnknown_203B2C8->monPortrait.faceData = (PortraitGfx *) faceFile->data;
  sUnknown_203B2C8->monPortrait.spriteId = 0;
  sUnknown_203B2C8->monPortrait.flip = FALSE;
  sUnknown_203B2C8->monPortrait.unkE = 0;
  sUnknown_203B2C8->monPortrait.pos.x = 2;
  sUnknown_203B2C8->monPortrait.pos.y = 8;
  if (sub_8099394(&sUnknown_203B2C8->unk1) != 1) {
    return 0;
  }
  else
  {
    sub_802B548(INIT_STATE);
    return 1;
  }
}

u32 sub_802B358(void)
{
  switch(sUnknown_203B2C8->currState) {
    case INIT_STATE:
        sub_802B560();
        break;
    case 1:
        sub_802B57C();
        break;
    case 2:
        sub_802B5B8();
        break;
    case 3:
        sub_802B5FC();
        break;
    case 4:
        sub_802B624();
        break;
    case EXIT_STATE:
        return 3;
  }
  return 0;
}

void sub_802B3B8(void)
{
    if (sUnknown_203B2C8 != NULL) {
        CloseFile(sUnknown_203B2C8->monPortrait.faceFile);
        FREE_AND_SET_NULL(sUnknown_203B2C8);
    }
}

void nullsub_132(void)
{
}

void sub_802B3E0(void)
{
  unkStruct_203B480 *mail;
  char *monName;
  char teamNameBuffer[40];

  switch(sUnknown_203B2C8->currState) {
      case INIT_STATE:
        if (CheckQuest(QUEST_SET_TEAM_NAME)) {
            // Copy Team Name to buffer
            sub_80920D8(teamNameBuffer);
        }
        else {
            // Copy "????" to buffer
            strcpy(teamNameBuffer,gRescueTeamNamePlaceholder);
        }
        // Print and expand placeholders?
        sprintfStatic(sUnknown_203B2C8->teamName,gUnknown_80DF9F8,teamNameBuffer);
        // Display to screen with Pelipper face
        CreateDialogueBoxAndPortrait(sUnknown_203B2C8->teamName, 0, &sUnknown_203B2C8->monPortrait, 0x10d);
        break;
      case 1:
        monName = GetMonSpecies(MONSTER_PELIPPER);
        strcpy(sUnknown_203B2C8->unk114.clientName, monName);
        sUnknown_203B2C8->unk114.clientSpecies = MONSTER_PELIPPER;
        sUnknown_203B2C8->unk114.rewardType = 2;
        sUnknown_203B2C8->unk114.moneyReward = 0;
        IncrementFriendRescueSuccesses();
        mail = GetMailatIndex(sUnknown_203B2C8->unk1);
        sub_803C37C(&mail->dungeonSeed.location, 0, sUnknown_203B2C8->unk114.itemRewards);
        sUnknown_203B2C8->unk114.teamRankPtsReward = GetDungeonTeamRankPts(&mail->dungeonSeed.location, 0);
        sUnknown_203B2C8->unk114.itemRewards[1] = ITEM_NOTHING;
        sUnknown_203B2C8->unk114.itemRewards[2] = ITEM_NOTHING;
        sUnknown_203B2C8->unk114.quantity = 10;
        sUnknown_203B2C8->unk114.friendAreaReward = 0;
        sub_802F204(&sUnknown_203B2C8->unk114, FALSE);
        break;
      case 2:
        // I hope you will keep on rescuing your friends
        // I must save your adventure
        CreateDialogueBoxAndPortrait(gUnknown_80DFAA8, 0, &sUnknown_203B2C8->monPortrait, 0x10d);
        break;
      case 4:
        // Oh yes, that's right. Please don't forget to send an A-OK Mail
        // to the friend you just rescued
        CreateDialogueBoxAndPortrait(gUnknown_80DFB14, 0, &sUnknown_203B2C8->monPortrait, 0x10d);
      case 3:
      case 5:
        break;
  }
}

void sub_802B548(u32 newState)
{
    sUnknown_203B2C8->currState = newState;
    nullsub_132();
    sub_802B3E0();
}

void sub_802B560(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B548(1);
    }
}

void sub_802B57C(void)
{
  char *monName;

  if (sub_802F298() == 3) {
    sub_802F2C0();
    CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_PELIPPER);
    monName = GetMonSpecies(MONSTER_PELIPPER);
    strcpy(gFormatBuffer_Monsters[0], monName);
    sub_802B548(2);
  }
}

void sub_802B5B8(void)
{
  u32 uVar2;
  unkStruct_203B480 *mail;
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    uVar2 = sub_8011C34();
    mail = GetMailatIndex(sUnknown_203B2C8->unk1);
    mail->mailType = WONDER_MAIL_TYPE_AOK;
    mail->unk28 = uVar2;
    sub_802B548(3);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
  }
}

void sub_802B5FC(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    if (!WriteSavePak()) {
      FinishWriteSavePak();
      sub_802B548(4);
    }
  }
}


void sub_802B624(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    sub_802B548(EXIT_STATE);
  }
}
