#include "global.h"
#include "globaldata.h"
#include "code_801B60C.h"
#include "friend_area.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "mission_reward.h"
#include "music_util.h"
#include "pokemon.h"
#include "rescue_team_info.h"
#include "string_format.h"
#include "text_1.h"

enum MR_State
{
    MR_STATE_PREP_MONEY_REWARD,
    MR_STATE_MONEY_REWARD,
    MR_STATE_PREP_FRIEND_AREA_REWARD,
    MR_STATE_UNLOCK_FRIEND_AREA,
    MR_STATE_PREP_ITEM_REWARD,
    MR_STATE_GIVE_ITEM_REWARD,
    MR_STATE_NEXT_ITEM,
    MR_STATE_TEAM_PNTS_REWARD,
    MR_STATE_NEW_TEAM_RANK,
    MR_STATE_REWARD_EXIT,
};

// Size: 0x84
typedef struct MR_Work
{
    /* 0x0 */ u32 state; // See enum "MR_State"
    /* 0x4 */ u32 nextState; // See enum "MR_State"
    /* 0x8 */ bool8 displayClientDialogueSprite;
    /* 0x9 */ u8 currTeamRank;
    /* 0xC */ s32 itemRewardIndex;
    /* 0x10 */ MissionRewards *rewards;
    /* 0x14 */ MonPortraitMsg monPortrait;
    /* 0x24 */ WindowTemplates windows;
} MR_Work;

EWRAM_INIT MR_Work *sMRWork = { NULL };

static const WindowTemplate sWinTemplateDummy = WIN_TEMPLATE_DUMMY;

ALIGNED(4) static const u8 gUnknown_80E0434[] = _(
        " Here's your reward!\n"
        "{COLOR CYAN}{VALUE_0}{RESET} {POKE}!");

ALIGNED(4) static const u8 gUnknown_80E045C[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET} received\n"
        "{CENTER_ALIGN}{COLOR CYAN}{VALUE_0}{RESET} {POKE}.");

ALIGNED(4) static const u8 gUnknown_80E0484[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET}'s team received\n"
        "{CENTER_ALIGN}{COLOR CYAN}{VALUE_0}{RESET} {POKE}.");

ALIGNED(4) static const u8 gUnknown_80E04B4[]= _(
        " As your reward, you can\n"
        "now go to the Friend Area\n"
        "{COLOR GREEN}{FRIEND_AREA}{RESET}!");

ALIGNED(4) static const u8 gUnknown_80E04F4[] = _(
        "{CENTER_ALIGN}...Oh, wait, sorry.{EXTRA_MSG}"
        "{CENTER_ALIGN}You already have the \n"
        "{CENTER_ALIGN}{COLOR GREEN}{FRIEND_AREA} Friend Area{RESET}.{EXTRA_MSG}"
        "{CENTER_ALIGN}I'm sorry that my reward is\n"
        "{CENTER_ALIGN}something you already have.{EXTRA_MSG}"
        "{CENTER_ALIGN}In its place, {COLOR YELLOW_N}{POKEMON_0}{RESET},\n"
        "{CENTER_ALIGN}you can have {COLOR CYAN_G}1,000{RESET} {POKE}.");

ALIGNED(4) static const u8 gUnknown_80E05C0[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET} gained access\n"
        "{CENTER_ALIGN}to the Friend Area\n"
        "{CENTER_ALIGN}{COLOR GREEN}{FRIEND_AREA}{RESET}.");

ALIGNED(4) static const u8 gUnknown_80E05FC[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET}'s team gained access\n"
        "{CENTER_ALIGN}to the Friend Area\n"
        "{CENTER_ALIGN}{COLOR GREEN}{FRIEND_AREA}{RESET}.");

ALIGNED(4) static const u8 gUnknown_80E0640[] = _(
        " Here's your reward!\n"
        "The promised {COLOR GREEN}{MOVE_ITEM_1}{RESET}!");

ALIGNED(4) static const u8 gUnknown_80E0670[] = _(
        "{CENTER_ALIGN}Rescue Team {COLOR CYAN_G}$t{RESET}\n"
        "{CENTER_ALIGN}gained {COLOR CYAN}{VALUE_0}{RESET} rescue points.");

ALIGNED(4) static const u8 gUnknown_80E06A8[] = _(
        "{CENTER_ALIGN}Congratulations!{EXTRA_MSG}"
        "{CENTER_ALIGN}{COLOR CYAN_G}$t{RESET} went up in rank\n"
        "{CENTER_ALIGN}from the {POKEMON_2}\n"
        "{CENTER_ALIGN}to the {POKEMON_3}!");

static void MR_InitStateDialogue(void);
static void MR_InitStateWindows(void);
static void MR_SetState(u32 state);
static void MR_ProceedToNextState(void);
static void sub_802F6FC(void);

bool8 MR_Create(MissionRewards *rewards, bool8 displayClientSprite)
{
    MR_Work *preload;

    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
    sMRWork = MemoryAlloc(sizeof(MR_Work), MEMALLOC_GROUP_8);
    sMRWork->rewards = rewards;
    sMRWork->itemRewardIndex = 0;
    sMRWork->displayClientDialogueSprite = displayClientSprite;

    // NOTE: dumb var to get correct ordering
    preload = sMRWork;
    strcpy(gSpeakerNameBuffer, preload->rewards->clientName);
    PrintPokeNameToBuffer(gFormatBuffer_Monsters[0], GetLeaderMon1());

    sMRWork->monPortrait.faceFile = GetDialogueSpriteDataPtr(sMRWork->rewards->clientSpecies);
    sMRWork->monPortrait.faceData = NULL;

    sMRWork->monPortrait.spriteId = 0;
    sMRWork->monPortrait.flip = FALSE;
    sMRWork->monPortrait.unkE = 0;
    sMRWork->monPortrait.pos.x = 2;
    sMRWork->monPortrait.pos.y = 8;

    if (sMRWork->monPortrait.faceFile != NULL)
        sMRWork->monPortrait.faceData = (PortraitGfx *)sMRWork->monPortrait.faceFile->data;

    MR_SetState(MR_STATE_PREP_MONEY_REWARD);
    return TRUE;
}

u32 MR_Update(void)
{
    switch (sMRWork->state) {
        case MR_STATE_REWARD_EXIT: {
            return 3;
        }
        case MR_STATE_GIVE_ITEM_REWARD: {
            sub_802F6FC();
            return 0;
        }
        default: {
            MR_ProceedToNextState();
            return 0;
        }
    }
}

void MR_Destroy(void)
{
    if (sMRWork != NULL) {
        TRY_CLOSE_FILE(sMRWork->monPortrait.faceFile);
        FREE_AND_SET_NULL(sMRWork);
    }
}

static void MR_SetState(u32 state)
{
    sMRWork->state = state;
    MR_InitStateWindows();
    MR_InitStateDialogue();
}

static void MR_InitStateWindows(void)
{
    switch (sMRWork->state) {
        case MR_STATE_PREP_MONEY_REWARD: {
            s32 i;

            RestoreSavedWindows(&sMRWork->windows);

            for (i = 0; i < MAX_WINDOWS; i++) {
                sMRWork->windows.id[i] = sWinTemplateDummy;
            }

            ResetUnusedInputStruct();
            ShowWindows(&sMRWork->windows, TRUE, TRUE);
            break;
        }
        default: {
            break;
        }
    }
}

static void MR_InitStateDialogue(void)
{
    switch (sMRWork->state) {
        case MR_STATE_PREP_MONEY_REWARD: {
            s32 moneyReward = sMRWork->rewards->moneyReward;

            if (moneyReward == 0) {
                MR_SetState(MR_STATE_PREP_FRIEND_AREA_REWARD);
            }
            else {
                gFormatArgs[0] = moneyReward;

                if (sMRWork->displayClientDialogueSprite) {
                    CreateDialogueBoxAndPortrait(gUnknown_80E0434, 0, &sMRWork->monPortrait, 0x10d);
                    sMRWork->nextState = MR_STATE_MONEY_REWARD;
                }
                else {
                    MR_SetState(MR_STATE_MONEY_REWARD);
                }
            }
            break;
        }
        case MR_STATE_MONEY_REWARD: {
            PlaySound(203);
            AddToTeamMoney(sMRWork->rewards->moneyReward);

            if (GetUnitSum_808D544(0) < 2)
                CreateDialogueBoxAndPortrait(gUnknown_80E045C, 0, 0, 0x101);
            else
                CreateDialogueBoxAndPortrait(gUnknown_80E0484, 0, 0, 0x101);

            sMRWork->nextState = MR_STATE_PREP_FRIEND_AREA_REWARD;
            break;
        }
        case MR_STATE_PREP_FRIEND_AREA_REWARD: {
            if (sMRWork->rewards->friendAreaReward == 0) {
                MR_SetState(MR_STATE_PREP_ITEM_REWARD);
            }
            else {
                WriteFriendAreaName(gFormatBuffer_FriendArea, sMRWork->rewards->friendAreaReward, FALSE);

                if (sMRWork->displayClientDialogueSprite) {
                    CreateDialogueBoxAndPortrait(gUnknown_80E04B4, 0, &sMRWork->monPortrait, 0x10d);
                    sMRWork->nextState = MR_STATE_UNLOCK_FRIEND_AREA;
                }
                else {
                    MR_SetState(MR_STATE_UNLOCK_FRIEND_AREA);
                }
            }
            break;
        }
        case MR_STATE_UNLOCK_FRIEND_AREA: {
            if (GetFriendAreaStatus(sMRWork->rewards->friendAreaReward)) {
                // We already have the friend area
                AddToTeamMoney(1000);
                CreateDialogueBoxAndPortrait(gUnknown_80E04F4, 0, 0, 0x101);
            }
            else
            {
                if (GetUnitSum_808D544(0) < 2) {
                    UnlockFriendArea(sMRWork->rewards->friendAreaReward);
                    PlaySound(0xce);
                    CreateDialogueBoxAndPortrait(gUnknown_80E05C0, 0, 0, 0x101);
                }
                else
                {
                    UnlockFriendArea(sMRWork->rewards->friendAreaReward);
                    PlaySound(0xce);
                    CreateDialogueBoxAndPortrait(gUnknown_80E05FC, 0, 0, 0x101);
                }
            }
            sMRWork->nextState = MR_STATE_PREP_ITEM_REWARD;
            break;
        }
        case MR_STATE_PREP_ITEM_REWARD: {
            u8 itemID = sMRWork->rewards->itemRewards[0];

            if (itemID != ITEM_NOTHING) {
                if (sMRWork->rewards->moneyReward == 0) {
                    struct unkStruct_8090F58 local_20;
                    Item item;

                    item.id = itemID;
                    if (IsThrownItem(item.id))
                        item.quantity = sMRWork->rewards->quantity;
                    else
                        item.quantity = 0;

                    item.flags = ITEM_FLAG_EXISTS;
                    local_20.unk0 = 0;
                    local_20.unk4 = 0;
                    local_20.unk8 = 1;
                    sub_8090E14(gFormatBuffer_Items[1], &item, &local_20);

                    if (sMRWork->displayClientDialogueSprite) {
                        CreateDialogueBoxAndPortrait(gUnknown_80E0640, 0, &sMRWork->monPortrait, 0x10d);
                        sMRWork->nextState = MR_STATE_GIVE_ITEM_REWARD;
                    }
                    else {
                        MR_SetState(MR_STATE_GIVE_ITEM_REWARD);
                    }
                }
                else {
                    MR_SetState(MR_STATE_GIVE_ITEM_REWARD);
                }
            }
            else {
                MR_SetState(MR_STATE_TEAM_PNTS_REWARD);
            }
            break;
        }
        case MR_STATE_GIVE_ITEM_REWARD: {
            if (sMRWork->rewards->itemRewards[sMRWork->itemRewardIndex] == ITEM_NOTHING) {
                MR_SetState(MR_STATE_NEXT_ITEM);
            }
            else if (sMRWork->itemRewardIndex == 0 && sMRWork->rewards->moneyReward == 0) {
                sub_801B60C(0, sMRWork->rewards->itemRewards[0], sMRWork->rewards->quantity);
            }
            else {
                sub_801B60C(1, sMRWork->rewards->itemRewards[sMRWork->itemRewardIndex], sMRWork->rewards->quantity);
            }
            break;
        }
        case MR_STATE_NEXT_ITEM: {
            sMRWork->itemRewardIndex++;

            if (sMRWork->itemRewardIndex < MAX_ITEM_REWARDS)
                MR_SetState(MR_STATE_GIVE_ITEM_REWARD);
            else
                MR_SetState(MR_STATE_TEAM_PNTS_REWARD);
            break;
        }
        case MR_STATE_TEAM_PNTS_REWARD: {
            if (sMRWork->rewards->teamRankPtsReward == 0) {
                MR_SetState(MR_STATE_REWARD_EXIT);
            }
            else {
                sMRWork->currTeamRank = GetRescueTeamRank();
                AddToTeamRankPts(sMRWork->rewards->teamRankPtsReward);
                PlaySound(203);

                if (sMRWork->currTeamRank != GetRescueTeamRank())
                    sMRWork->nextState = MR_STATE_NEW_TEAM_RANK;
                else
                    sMRWork->nextState = MR_STATE_REWARD_EXIT;

                gFormatArgs[0] = sMRWork->rewards->teamRankPtsReward;
                CreateDialogueBoxAndPortrait(gUnknown_80E0670, 0, 0, 0x101);
            }
            break;
        }
        case MR_STATE_NEW_TEAM_RANK: {
            const u8 *rankString;

            PlaySound(201);
            sMRWork->nextState = MR_STATE_REWARD_EXIT;

            rankString = GetTeamRankString(sMRWork->currTeamRank);
            strcpy(gFormatBuffer_Monsters[2], rankString);

            rankString = GetTeamRankString(GetRescueTeamRank());
            strcpy(gFormatBuffer_Monsters[3], rankString);

            CreateDialogueBoxAndPortrait(gUnknown_80E06A8, 0, 0, 0x101);
            break;
        }
        case MR_STATE_REWARD_EXIT: {
            break;
        }
    }
}

static void sub_802F6FC(void)
{
    switch (sub_801B6AC()) {
        case 2:
        case 3: {
            sub_801B72C();
            MR_SetState(MR_STATE_NEXT_ITEM);
            break;
        }
        case 0:
        case 1: {
            break;
        }
    }
}

static void MR_ProceedToNextState(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        MR_SetState(sMRWork->nextState);
}

