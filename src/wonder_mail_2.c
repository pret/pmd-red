#include "global.h"
#include "globaldata.h"
#include "constants/item.h"
#include "constants/wonder_mail.h"
#include "adventure_info.h"
#include "code_800D090.h"
#include "code_803C1B4.h"
#include "code_8094F88.h"
#include "code_8099360.h"
#include "event_flag.h"
#include "game_options.h"
#include "ground_main.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "mission_reward.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "rescue_team_info.h"
#include "save.h"
#include "save_write.h"
#include "string_format.h"
#include "text_1.h"
#include "wonder_mail_2.h"

// This file appears to be for the rescue mission success reward

enum WM2State
{
    WM2STATE_WELCOMEBACK,
    WM2STATE_REWARD,
    WM2STATE_MUSTSAVE,
    WM2STATE_SAVING,
    WM2STATE_SEEYA,
    WM2STATE_DONE,
};

// Size: R=0x140 | B=?
typedef struct WonderMail2Work
{
    /* 0x0 */ u8 state; // See enum "WM2State"
    /* 0x1 */ u8 unk1;
    /* 0x4 */ MonPortraitMsg monPortrait;
    /* 0x14 */ u8 teamName[0x100];
    /* 0x114 */ MissionRewards rewards;
    /* 0x13C */ u32 unused13C;
} WonderMail2Work;

static EWRAM_INIT WonderMail2Work *sWM2Work = { NULL };

static ALIGNED(4) const u8 sTeamNamePlaceholder[] = _("????");

static ALIGNED(4) const u8 sWelcomeBackText[] = _(
	" Oh, hello!\n"
	"Your rescue mission went well, didn't it?\n"
	"I wouldn't expect any less, {COLOR CYAN_G}%s{RESET}!{EXTRA_MSG}"
	" Well, well!\n"
	"Here is your reward from the Pokémon\n"
	"Rescue Organization!");

static ALIGNED(4) const u8 sMustSaveText[] = _(
	" I hope you will keep on\n"
	"rescuing your friends in\n"
	"dire straits.{EXTRA_MSG}"
	" And now, I must save\n"
	"your adventure.");

static ALIGNED(4) const u8 sSeeyaText[] = _(
	" Oh, yes, that's right.\n"
	"Please don't forget to send an {COLOR CYAN_G}A-OK Mail{RESET}\n"
	"to the friend you just rescued.{EXTRA_MSG}"
	" Please give me a shout if\n"
	"you would like to send {COLOR CYAN_G}A-OK Mail{RESET}.");

static void WM2_SetState(u32 state);
static void WM2_Update_WelcomeBack(void);
static void WM2_Update_Reward(void);
static void WM2_Update_MustSave(void);
static void WM2_Update_Saving(void);
static void WM2_Update_Seeya(void);

bool8 WM2_Create(void)
{
    OpenedFile *faceFile;

    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);

    sWM2Work = MemoryAlloc(sizeof(WonderMail2Work), MEMALLOC_GROUP_8);
    MemoryFill8(sWM2Work, 0, sizeof(WonderMail2Work));

    sWM2Work->unk1 = -1;
    CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_PELIPPER);

    faceFile = GetDialogueSpriteDataPtr(MONSTER_PELIPPER);
    sWM2Work->monPortrait.faceFile = faceFile;
    sWM2Work->monPortrait.faceData = (PortraitGfx *)faceFile->data;
    sWM2Work->monPortrait.spriteId = 0;
    sWM2Work->monPortrait.flip = FALSE;
    sWM2Work->monPortrait.unkE = 0;
    sWM2Work->monPortrait.pos.x = 2;
    sWM2Work->monPortrait.pos.y = 8;

    if (sub_8099394(&sWM2Work->unk1) != TRUE)
        return FALSE;

    WM2_SetState(WM2STATE_WELCOMEBACK);
    return TRUE;
}

u32 WM2_Update(void)
{
    switch (sWM2Work->state) {
        case WM2STATE_WELCOMEBACK: {
            WM2_Update_WelcomeBack();
            break;
        }
        case WM2STATE_REWARD: {
            WM2_Update_Reward();
            break;
        }
        case WM2STATE_MUSTSAVE: {
            WM2_Update_MustSave();
            break;
        }
        case WM2STATE_SAVING: {
            WM2_Update_Saving();
            break;
        }
        case WM2STATE_SEEYA: {
            WM2_Update_Seeya();
            break;
        }
        case WM2STATE_DONE: {
            return 3;
        }
    }

    return 0;
}

void WM2_Destroy(void)
{
    if (sWM2Work != NULL) {
        CloseFile(sWM2Work->monPortrait.faceFile);
        FREE_AND_SET_NULL(sWM2Work);
    }
}

static void WM2_InitStateWindows(void)
{
}

static void WM2_InitStateDialogue(void)
{
    switch (sWM2Work->state) {
        case WM2STATE_WELCOMEBACK: {
            u8 teamNameBuffer[40];

            if (CheckQuest(QUEST_SET_TEAM_NAME))
                StrncpyTeamName(teamNameBuffer);
            else
                strcpy(teamNameBuffer, sTeamNamePlaceholder);

            sprintfStatic(sWM2Work->teamName, sWelcomeBackText, teamNameBuffer);
            CreateDialogueBoxAndPortrait(sWM2Work->teamName, 0, &sWM2Work->monPortrait, 0x10D);
            break;
        }
        case WM2STATE_REWARD: {
            unkStruct_203B480 *mail;
            u8 *monName = GetMonSpecies(MONSTER_PELIPPER);

            strcpy(sWM2Work->rewards.clientName, monName);
            sWM2Work->rewards.clientSpecies = MONSTER_PELIPPER;
            sWM2Work->rewards.rewardType = 2;
            sWM2Work->rewards.moneyReward = 0;
            IncrementFriendRescueSuccesses();

            mail = GetMailatIndex(sWM2Work->unk1);
            sub_803C37C(&mail->dungeonSeed.location, 0, sWM2Work->rewards.itemRewards);
            sWM2Work->rewards.teamRankPtsReward = GetDungeonTeamRankPts(&mail->dungeonSeed.location, 0);
            sWM2Work->rewards.itemRewards[1] = ITEM_NOTHING;
            sWM2Work->rewards.itemRewards[2] = ITEM_NOTHING;
            sWM2Work->rewards.quantity = 10;
            sWM2Work->rewards.friendAreaReward = 0;
            MR_Create(&sWM2Work->rewards, FALSE);
            break;
        }
        case WM2STATE_MUSTSAVE: {
            CreateDialogueBoxAndPortrait(sMustSaveText, 0, &sWM2Work->monPortrait, 0x10D);
            break;
        }
        case WM2STATE_SEEYA: {
            CreateDialogueBoxAndPortrait(sSeeyaText, 0, &sWM2Work->monPortrait, 0x10D);
            break;
        }
        case WM2STATE_SAVING:
        case WM2STATE_DONE: {
            break;
        }
    }
}

// state: See enum "WM2State"
static void WM2_SetState(u32 state)
{
    sWM2Work->state = state;
    WM2_InitStateWindows();
    WM2_InitStateDialogue();
}

static void WM2_Update_WelcomeBack(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        WM2_SetState(WM2STATE_REWARD);
}

static void WM2_Update_Reward(void)
{
    if (MR_Update() == 3) {
        u8 *monName;

        MR_Destroy();
        CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_PELIPPER);
        monName = GetMonSpecies(MONSTER_PELIPPER);
        strcpy(gFormatBuffer_Monsters[0], monName);

        WM2_SetState(WM2STATE_MUSTSAVE);
    }
}

static void WM2_Update_MustSave(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0) {
        s32 u = sub_8011C34();
        unkStruct_203B480 *mail = GetMailatIndex(sWM2Work->unk1);

        mail->mailType = WONDER_MAIL_TYPE_AOK;
        mail->unk28 = u;

        WM2_SetState(WM2STATE_SAVING);
        sub_8011C28(1);
        PrepareSavePakWrite(MONSTER_NONE);
    }
}

static void WM2_Update_Saving(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0) {
        if (!WriteSavePak()) {
            FinishWriteSavePak();
            WM2_SetState(WM2STATE_SEEYA);
        }
    }
}

static void WM2_Update_Seeya(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        WM2_SetState(WM2STATE_DONE);
}
