#include "global.h"
#include "globaldata.h"
#include "code_802F204.h"
#include "pokemon.h"
#include "pokemon_mid.h"
#include "rescue_team_info.h"
#include "friend_area.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "code_80130A8.h"
#include "code_80118A4.h"
#include "code_801B60C.h"
#include "text1.h"
#include "text2.h"

struct unkStruct_203B310
{
    // size: 0x84
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 nextState;
    /* 0x8 */ bool8 displayClientDialogueSprite; // true to display the dialogue sprite for the client
    /* 0x9 */ u8 currTeamRank; // team rank
    /* 0xC */ s32 itemRewardIndex;
    unkStruct_802F204 *unk10;
    /* 0x14 */ struct MonPortraitMsg monPortrait;
    UnkTextStruct2 unk24[4];
};

EWRAM_DATA_2 struct unkStruct_203B310 *gUnknown_203B310 = {0};

extern u8 gUnknown_202E038[];
extern u8 gUnknown_202E628[];
extern u8 gUnknown_202DEA8[];
extern u8 gUnknown_202E5D8[];
extern u8 gAvailablePokemonNames[];
extern u32 gFormatData_202DE30;

enum FriendRewardStates
{
    PREP_MONEY_REWARD,
    MONEY_REWARD,
    PREP_FRIEND_AREA_REWARD,
    UNLOCK_FRIEND_AREA,
    PREP_ITEM_REWARD,
    GIVE_ITEM_REWARD,
    NEXT_ITEM,
    TEAM_PNTS_REWARD,
    NEW_TEAM_RANK,
    REWARD_EXIT,
};

const UnkTextStruct2 gUnknown_80E041C = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

ALIGNED(4) const u8 gUnknown_80E0434[] = _(
        " Here's your reward!\n"
        "{COLOR CYAN}{VALUE_0}{RESET} {POKE}!");

ALIGNED(4) const u8 gUnknown_80E045C[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET} received\n"
        "{CENTER_ALIGN}{COLOR CYAN}{VALUE_0}{RESET} {POKE}.");

ALIGNED(4) const u8 gUnknown_80E0484[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET}'s team received\n"
        "{CENTER_ALIGN}{COLOR CYAN}{VALUE_0}{RESET} {POKE}.");

ALIGNED(4) const u8 gUnknown_80E04B4[]= _(
        " As your reward, you can\n"
        "now go to the Friend Area\n"
        "{COLOR GREEN}{FRIEND_AREA}{RESET}!");

ALIGNED(4) const u8 gUnknown_80E04F4[] = _(
        "{CENTER_ALIGN}...Oh, wait, sorry.{EXTRA_MSG}"
        "{CENTER_ALIGN}You already have the \n"
        "{CENTER_ALIGN}{COLOR GREEN}{FRIEND_AREA} Friend Area{RESET}.{EXTRA_MSG}"
        "{CENTER_ALIGN}I'm sorry that my reward is\n"
        "{CENTER_ALIGN}something you already have.{EXTRA_MSG}"
        "{CENTER_ALIGN}In its place, {COLOR YELLOW_N}{POKEMON_0}{RESET},\n"
        "{CENTER_ALIGN}you can have {COLOR CYAN_G}1,000{RESET} {POKE}.");

ALIGNED(4) const u8 gUnknown_80E05C0[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET} gained access\n"
        "{CENTER_ALIGN}to the Friend Area\n"
        "{CENTER_ALIGN}{COLOR GREEN}{FRIEND_AREA}{RESET}.");

ALIGNED(4) const u8 gUnknown_80E05FC[] = _(
        "{CENTER_ALIGN}{COLOR YELLOW_N}{POKEMON_0}{RESET}'s team gained access\n"
        "{CENTER_ALIGN}to the Friend Area\n"
        "{CENTER_ALIGN}{COLOR GREEN}{FRIEND_AREA}{RESET}.");

ALIGNED(4) const u8 gUnknown_80E0640[] = _(
        " Here's your reward!\n"
        "The promised {COLOR GREEN}{MOVE_ITEM_1}{RESET}!");

ALIGNED(4) const u8 gUnknown_80E0670[] = _(
        "{CENTER_ALIGN}Rescue Team {COLOR CYAN_G}$t{RESET}\n"
        "{CENTER_ALIGN}gained {COLOR CYAN}{VALUE_0}{RESET} rescue points.");

ALIGNED(4) const u8 gUnknown_80E06A8[] = _(
        "{CENTER_ALIGN}Congratulations!{EXTRA_MSG}"
        "{CENTER_ALIGN}{COLOR CYAN_G}$t{RESET} went up in rank\n"
        "{CENTER_ALIGN}from the {POKEMON_2}\n"
        "{CENTER_ALIGN}to the {POKEMON_3}!");


void SetRewardSceneState(u32);
void sub_802F6FC(void);
void ProceedToNextRewardSceneState(void);
void sub_802F300(void);
void HandleMissionReward(void);

u32 sub_802F204(unkStruct_802F204 *r0, bool8 displayClientSprite)
{
    struct unkStruct_203B310 *preload;

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    gUnknown_203B310 = MemoryAlloc(sizeof(struct unkStruct_203B310), 8);
    gUnknown_203B310->unk10 = r0;
    gUnknown_203B310->itemRewardIndex = 0;
    gUnknown_203B310->displayClientDialogueSprite = displayClientSprite;

    // NOTE: dumb var to get correct ordering
    preload = gUnknown_203B310;
    strcpy(gUnknown_202E5D8, preload->unk10->clientName);
    PrintPokeNameToBuffer(gAvailablePokemonNames, GetPlayerPokemonStruct());

    gUnknown_203B310->monPortrait.faceFile = GetDialogueSpriteDataPtr(gUnknown_203B310->unk10->clientSpecies);
    gUnknown_203B310->monPortrait.faceData = NULL;

    gUnknown_203B310->monPortrait.spriteId = 0;
    gUnknown_203B310->monPortrait.flip = FALSE;
    gUnknown_203B310->monPortrait.unkE = 0;
    gUnknown_203B310->monPortrait.pos.x = 2;
    gUnknown_203B310->monPortrait.pos.y = 8;

    if(gUnknown_203B310->monPortrait.faceFile != NULL)
    {
        gUnknown_203B310->monPortrait.faceData = (void *) gUnknown_203B310->monPortrait.faceFile->data;
    }

    SetRewardSceneState(PREP_MONEY_REWARD);
    return 1;
}

u32 sub_802F298(void)
{
    switch(gUnknown_203B310->state)
    {
        case REWARD_EXIT:
            return 3;
        case GIVE_ITEM_REWARD:
            sub_802F6FC();
            return 0;
        default:
            ProceedToNextRewardSceneState();
            return 0;
    }
}

void sub_802F2C0(void)
{
    if(gUnknown_203B310 != NULL)
    {
        if(gUnknown_203B310->monPortrait.faceFile != 0)
            CloseFile(gUnknown_203B310->monPortrait.faceFile);
        MemoryFree(gUnknown_203B310);
        gUnknown_203B310 = NULL;
    }
}

void SetRewardSceneState(u32 newState)
{
    gUnknown_203B310->state = newState;
    sub_802F300();
    HandleMissionReward();
}

void sub_802F300(void)
{
    s32 index;
    switch(gUnknown_203B310->state)
    {
        case PREP_MONEY_REWARD:
            RestoreUnkTextStruct_8006518(gUnknown_203B310->unk24);
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B310->unk24[index] = gUnknown_80E041C;
            }
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B310->unk24, TRUE, TRUE);
        default:
            break;
    }
}

void HandleMissionReward(void)
{
  int moneyReward;
  const u8 *rankString;
  u8 itemID;
  struct unkStruct_8090F58 local_20;
  Item item;

  switch(gUnknown_203B310->state) {
    case PREP_MONEY_REWARD:
        moneyReward = gUnknown_203B310->unk10->moneyReward;
        if (moneyReward == 0) {
            SetRewardSceneState(PREP_FRIEND_AREA_REWARD);
        }
        else {
            gFormatData_202DE30 = moneyReward;
            if (gUnknown_203B310->displayClientDialogueSprite) {
                CreateDialogueBoxAndPortrait(gUnknown_80E0434,0,&gUnknown_203B310->monPortrait,0x10d);
                gUnknown_203B310->nextState = MONEY_REWARD;
            }
            else {
                SetRewardSceneState(MONEY_REWARD);
            }
        }
        break;
    case MONEY_REWARD:
        PlaySound(0xcb);
        AddToTeamMoney(gUnknown_203B310->unk10->moneyReward);
        if (GetUnitSum_808D544(0) < 2) {
            CreateDialogueBoxAndPortrait(gUnknown_80E045C,0,0,0x101);
        }
        else {
            CreateDialogueBoxAndPortrait(gUnknown_80E0484,0,0,0x101);
        }
        gUnknown_203B310->nextState = PREP_FRIEND_AREA_REWARD;
        break;
    case PREP_FRIEND_AREA_REWARD:
        if (gUnknown_203B310->unk10->friendAreaReward == 0) {
            SetRewardSceneState(PREP_ITEM_REWARD);
        }
        else {
            WriteFriendAreaName(gUnknown_202E628,gUnknown_203B310->unk10->friendAreaReward,FALSE);
            if (gUnknown_203B310->displayClientDialogueSprite) {
                CreateDialogueBoxAndPortrait(gUnknown_80E04B4,0,&gUnknown_203B310->monPortrait,0x10d);
                gUnknown_203B310->nextState = UNLOCK_FRIEND_AREA;
            }
            else {
                SetRewardSceneState(UNLOCK_FRIEND_AREA);
            }
        }
        break;
    case UNLOCK_FRIEND_AREA:
        if (GetFriendAreaStatus(gUnknown_203B310->unk10->friendAreaReward)) {
            // We already have the friend area
            AddToTeamMoney(1000);
            CreateDialogueBoxAndPortrait(gUnknown_80E04F4,0,0,0x101);
        }
        else
        {
            if (GetUnitSum_808D544(0) < 2) {
                UnlockFriendArea(gUnknown_203B310->unk10->friendAreaReward);
                PlaySound(0xce);
                CreateDialogueBoxAndPortrait(gUnknown_80E05C0,0,0,0x101);
            }
            else
            {
                UnlockFriendArea(gUnknown_203B310->unk10->friendAreaReward);
                PlaySound(0xce);
                CreateDialogueBoxAndPortrait(gUnknown_80E05FC,0,0,0x101);
            }
        }
        gUnknown_203B310->nextState = PREP_ITEM_REWARD;
        break;
    case PREP_ITEM_REWARD:
        itemID = gUnknown_203B310->unk10->itemRewards[0];
        if (itemID != ITEM_NOTHING)
        {
            if (gUnknown_203B310->unk10->moneyReward == 0) {
                item.id = itemID;
                if (IsThrowableItem(item.id)) {
                    item.quantity = gUnknown_203B310->unk10->quantity;
                }
                else {
                    item.quantity = 0;
                }
                item.flags = ITEM_FLAG_EXISTS;
                local_20.unk0 = 0;
                local_20.unk4 = 0;
                local_20.unk8 = 1;
                sub_8090E14(gUnknown_202DEA8,&item,&local_20);
                if (gUnknown_203B310->displayClientDialogueSprite) {
                    CreateDialogueBoxAndPortrait(gUnknown_80E0640,0,&gUnknown_203B310->monPortrait,0x10d);
                    gUnknown_203B310->nextState = GIVE_ITEM_REWARD;
                }
                else
                {
                    SetRewardSceneState(GIVE_ITEM_REWARD);
                }
            }
            else
            {
                SetRewardSceneState(GIVE_ITEM_REWARD);
            }
        }
        else
            SetRewardSceneState(TEAM_PNTS_REWARD);
        break;
    case GIVE_ITEM_REWARD:
        if ((gUnknown_203B310->unk10->itemRewards[gUnknown_203B310->itemRewardIndex]) == 0) {
            SetRewardSceneState(NEXT_ITEM);
        }
        else {
            if ((gUnknown_203B310->itemRewardIndex == 0) && (gUnknown_203B310->unk10->moneyReward == 0)) {
                sub_801B60C(0,gUnknown_203B310->unk10->itemRewards[0],gUnknown_203B310->unk10->quantity);
            }
            else {
                sub_801B60C(1,gUnknown_203B310->unk10->itemRewards[gUnknown_203B310->itemRewardIndex],gUnknown_203B310->unk10->quantity);
            }
        }
        break;
    case NEXT_ITEM:
        gUnknown_203B310->itemRewardIndex++;
        if(gUnknown_203B310->itemRewardIndex < MAX_ITEM_REWARDS)
            SetRewardSceneState(GIVE_ITEM_REWARD);
        else
            SetRewardSceneState(TEAM_PNTS_REWARD);
        break;
    case TEAM_PNTS_REWARD:
        if (gUnknown_203B310->unk10->teamRankPtsReward == 0) {
            SetRewardSceneState(REWARD_EXIT);
        }
        else {
            gUnknown_203B310->currTeamRank = GetRescueTeamRank();
            AddToTeamRankPts(gUnknown_203B310->unk10->teamRankPtsReward);
            PlaySound(0xcb);
            if (gUnknown_203B310->currTeamRank != GetRescueTeamRank()) {
                gUnknown_203B310->nextState = NEW_TEAM_RANK;
            }
            else {
                gUnknown_203B310->nextState = REWARD_EXIT;
            }
            gFormatData_202DE30 = gUnknown_203B310->unk10->teamRankPtsReward;
            CreateDialogueBoxAndPortrait(gUnknown_80E0670,0,0,0x101);
        }
        break;
    case NEW_TEAM_RANK:
        PlaySound(0xc9);
        gUnknown_203B310->nextState = REWARD_EXIT;
        rankString = GetTeamRankString(gUnknown_203B310->currTeamRank);
        strcpy(gUnknown_202E038,rankString);
        rankString = GetTeamRankString(GetRescueTeamRank());
        strcpy(gUnknown_202E038 + 0x50,rankString);
        CreateDialogueBoxAndPortrait(gUnknown_80E06A8,0,0,0x101);
        break;
    case REWARD_EXIT:
        break;
  }
}

void sub_802F6FC(void)
{
    switch(sub_801B6AC())
    {
        case 2:
        case 3:
            sub_801B72C();
            SetRewardSceneState(NEXT_ITEM);
            break;
        case 0:
        case 1:
            break;
    }
}

void ProceedToNextRewardSceneState(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0) {
        SetRewardSceneState(gUnknown_203B310->nextState);
    }
}

