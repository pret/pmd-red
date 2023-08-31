#include "global.h"
#include "constants/input.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "wonder_mail.h"
#include "pokemon.h"
#include "rescue_team_info.h"
#include "friend_area.h"
#include "item.h"
#include "menu_input.h"
#include "code_802C39C.h"
#include "code_80130A8.h"
#include "code_80118A4.h"

struct unkStruct_803B344
{
    // size: 0xB4
    struct WonderMail mail;
    u8* unk14;
    u8* unk18;
    u8 fill1C[0x3C - 0x1C];
    u8 unk3C[0x78];
};

extern struct unkStruct_803B344 *sub_803B344(u8);

struct unkStruct_203B30C
{
    // size: 0x150
    s32 state;
    u8 unk4;
    struct unkStruct_802C39C unk8;
    struct MenuStruct unk60;
    struct MenuItem unkB0[8];
    struct UnkTextStruct2 unkF0[4];
};
extern struct unkStruct_203B30C *gUnknown_203B30C;

struct unkStruct_203B310
{
    // size: 0x84
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 nextState;
    /* 0x8 */ bool8 displayClientDialogueSprite; // true to display the dialogue sprite for the client
    /* 0x9 */ u8 currTeamRank; // team rank
    /* 0xC */ s32 itemRewardIndex;
    struct unkStruct_802F204 *unk10;
    /* 0x14 */ struct OpenedFile *faceFile;
    /* 0x18 */ u8 *faceData;
    s16 unk1C;
    s16 unk1E;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    struct UnkTextStruct2 unk24[4];
};
extern struct unkStruct_203B310 *gUnknown_203B310;

struct unkStruct_203B314
{
    // size: 0x15C
    s16 unk0[2];
    u8 fill4[0x5C - 0x4];
    u8 unk5C[2];
    u8 fill5E[0x8A - 0x5E];
    u8 unk8A[2];
    u8 unk8C[0xB8 - 0x8C];
    u8 unkB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    struct MenuInputStruct input;
    u32 unkF0;
    struct UnkTextStruct2 *unkF4;
    struct UnkTextStruct2 unkF8[4];
    u8 unk158[4];
};

extern struct unkStruct_203B314 *gUnknown_203B314;


enum FriendRewardStates {
    PREP_MONEY_REWARD = 0,
    MONEY_REWARD = 1,
    PREP_FRIEND_AREA_REWARD = 2,
    UNLOCK_FRIEND_AREA = 3,
    PREP_ITEM_REWARD = 4,
    GIVE_ITEM_REWARD = 5,
    NEXT_ITEM = 6,
    TEAM_PNTS_REWARD = 7,
    NEW_TEAM_RANK = 8,
    REWARD_EXIT = 9,
};

extern u8 sub_802FCF0(u32);
extern void sub_802F9C0(void);
extern void sub_802FA50(void);
extern s32 sub_802FBF4(void);

extern void SetRewardSceneState(u32);
extern void sub_802EFEC(u32);
extern void sub_802F148(void);
extern void sub_802F184(void);
extern void sub_802F1E8(void);
extern void sub_802F004();
extern void sub_802F088();
extern void sub_801B72C(void);
extern u32 sub_801B6AC(void);
extern void sub_802F108(void);
extern void sub_803B35C(struct WonderMail*, struct unkStruct_802C39C *);
extern void sub_802DE84(struct unkStruct_802C39C *);
extern void sub_802CDD4(u32);
extern void sub_802CED8(u32);
extern void sub_802CFD0(void);
extern u8 sub_802CEBC(void);
extern u32 sub_802CE5C(u32);
extern void sub_802CF14(void);
extern u32 sub_802DEE0(void);
extern void sub_802DF24(void);
extern void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void sub_802F6FC(void);
extern void ProceedToNextRewardSceneState(void);
extern void sub_802F300(void);
extern s32 sub_808D544(u32);
extern u32 sub_801B60C(u32, u8, u8);
void HandleMissionReward(void);
const u8 *sub_80974A0(s16 index);

const struct UnkTextStruct2 gUnknown_80E03C4 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E03DC = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x03,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E03F4 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x06,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const u8 gUnknown_80E040C[] = "Send";
static const u8 wonder_mail_fill[] = "pksdir0";
const struct UnkTextStruct2 gUnknown_80E041C = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

ALIGNED(4) const u8 gUnknown_80E0434[] = _(
        " Here{APOSTROPHE}s your reward!\n"
        "{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}!");

ALIGNED(4) const u8 gUnknown_80E045C[] = _(
        "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1} received\n"
        "{CENTER_ALIGN}{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.");

ALIGNED(4) const u8 gUnknown_80E0484[] = _(
        "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s team received\n"
        "{CENTER_ALIGN}{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.");

ALIGNED(4) const u8 gUnknown_80E04B4[]= _(
        " As your reward{COMMA} you can\n"
        "now go to the Friend Area\n"
        "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}!");

ALIGNED(4) const u8 gUnknown_80E04F4[] = _(
        "{CENTER_ALIGN}...Oh{COMMA} wait{COMMA} sorry.{EXTRA_MSG}"
        "{CENTER_ALIGN}You already have the \n"
        "{CENTER_ALIGN}{COLOR_1 GREEN}{ARG_FRIEND_AREA} Friend Area{END_COLOR_TEXT_1}.{EXTRA_MSG}"
        "{CENTER_ALIGN}I{APOSTROPHE}m sorry that my reward is\n"
        "{CENTER_ALIGN}something you already have.{EXTRA_MSG}"
        "{CENTER_ALIGN}In its place{COMMA} {COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{COMMA}\n"
        "{CENTER_ALIGN}you can have {COLOR_1 LIGHT_BLUE}1{COMMA}000{END_COLOR_TEXT_1} {POKE}.");

ALIGNED(4) const u8 gUnknown_80E05C0[] = _(
        "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1} gained access\n"
        "{CENTER_ALIGN}to the Friend Area\n"
        "{CENTER_ALIGN}{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.");

ALIGNED(4) const u8 gUnknown_80E05FC[] = _(
        "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s team gained access\n"
        "{CENTER_ALIGN}to the Friend Area\n"
        "{CENTER_ALIGN}{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.");

ALIGNED(4) const u8 gUnknown_80E0640[] = _(
        " Here{APOSTROPHE}s your reward!\n"
        "The promised {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1}!");

ALIGNED(4) const u8 gUnknown_80E0670[] = _(
        "{CENTER_ALIGN}Rescue Team {COLOR_1 LIGHT_BLUE}$t{END_COLOR_TEXT_1}\n"
        "{CENTER_ALIGN}gained {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} rescue points.");

ALIGNED(4) const u8 gUnknown_80E06A8[] = _(
        "{CENTER_ALIGN}Congratulations!{EXTRA_MSG}"
        "{CENTER_ALIGN}{COLOR_1 LIGHT_BLUE}$t{END_COLOR_TEXT_1} went up in rank\n"
        "{CENTER_ALIGN}from the {ARG_POKEMON_2}\n"
        "{CENTER_ALIGN}to the {ARG_POKEMON_3}!");

static const u8 wonder_mail_fill2[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80E06FC = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0714 = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x0E, 0x0E,
    0x0E, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E072C = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x10, 0x10,
    0x10, 0x00,
    NULL
};

extern u8 gUnknown_202E038[];
extern u8 gUnknown_202E088[];
extern u8 gUnknown_202E628[];
extern u8 gUnknown_202DEA8[];
extern u8 gUnknown_202E5D8[];
extern u8 gAvailablePokemonNames[];
extern u32 gUnknown_202DE30;
extern const u8 *gUnknown_80D4970[];
extern u8 gUnknown_80E0744[];
extern u8 gUnknown_80E0754[];
extern u8 gUnknown_80E0750[];

u32 sub_802EF48(void)
{
    gUnknown_203B30C = MemoryAlloc(sizeof(struct unkStruct_203B30C), 8);
    sub_802EFEC(0);
    return 1;
}

u32 sub_802EF6C(void)
{
    switch(gUnknown_203B30C->state)
    {
        case 0:
        case 1:
            sub_802F148();
            break;
        case 2:
            sub_802F184();
            break;
        case 3:
            sub_802F1E8();
            break;
        case 4:
            return 3;
        case 5:
        default:
            return 2;
    }
    return 0;
}

u8 sub_802EFC4(void)
{
    return gUnknown_203B30C->unk4;
}

void sub_802EFD0(void)
{
    if(gUnknown_203B30C != NULL)
    {
        MemoryFree(gUnknown_203B30C);
        gUnknown_203B30C = NULL;
    }
}

void sub_802EFEC(u32 newState)
{
    gUnknown_203B30C->state = newState;
    sub_802F004();
    sub_802F088();
}

void sub_802F004(void)
{
    s32 index;

    sub_8006518(gUnknown_203B30C->unkF0);
    switch(gUnknown_203B30C->state)
    {
        case 2:
            sub_802F108();
            gUnknown_203B30C->unkF0[2] = gUnknown_80E03F4;
            sub_8012CAC(&gUnknown_203B30C->unkF0[2], gUnknown_203B30C->unkB0);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B30C->unkF0[index] = gUnknown_80E03C4;
            }
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B30C->unkF0, 1, 1);
}

void sub_802F088(void)
{
    struct unkStruct_803B344 *temp;

    switch(gUnknown_203B30C->state)
    {
        case 0:
            sub_802CDD4(0);
            break;
        case 1:
            sub_802CED8(1);
            break;
        case 2:
            sub_802CFD0();
            sub_8012D60(&gUnknown_203B30C->unk60, gUnknown_203B30C->unkB0, 0, 0, 3, 2);
            break;
        case 3:
            temp = sub_803B344(gUnknown_203B30C->unk4);
            sub_803B35C(&temp->mail, &gUnknown_203B30C->unk8);
            gUnknown_203B30C->unk8.unk0[0] = 3;
            gUnknown_203B30C->unk8.mailStatus = MAIL_STATUS_SUSPENDED;
            gUnknown_203B30C->unk8.unk50 = temp->unk18;
            sub_802DE84(&gUnknown_203B30C->unk8);
    }
}

void sub_802F108(void)
{
    s32 loopMax = 0;

    gUnknown_203B30C->unkB0[loopMax].text = gUnknown_80E040C;
    gUnknown_203B30C->unkB0[loopMax].menuAction = 2;
    loopMax += 1;
    gUnknown_203B30C->unkB0[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B30C->unkB0[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B30C->unkB0[loopMax].text = NULL;
    gUnknown_203B30C->unkB0[loopMax].menuAction = 1;
}

void sub_802F148(void)
{
    switch(sub_802CE5C(1))
    {
        case 0:
        case 1:
            break;
        case 3:
            gUnknown_203B30C->unk4 = sub_802CEBC();
            sub_802EFEC(2);
            break;
        case 2:
            sub_802CF14();
            sub_802EFEC(5);
            break;
    }
}

void sub_802F184(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_802CE5C(0);

    if (sub_8012FD8(&gUnknown_203B30C->unk60) == 0) {
        sub_8013114(&gUnknown_203B30C->unk60, &menuAction);
    }

    switch(menuAction)
    {
        case 2:
            sub_802CF14();
            sub_802EFEC(4);
            break;
        case 3:
            sub_802EFEC(3);
            break;
        case 1:
            sub_802EFEC(1);
            break;
    }
}

void sub_802F1E8(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            sub_802EFEC(1);
            break;
        case 0:
        case 1:
            break;
    }
}



u32 sub_802F204(struct unkStruct_802F204 *r0, bool8 displayClientSprite)
{
    struct unkStruct_203B310 *preload;

    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
    gUnknown_203B310 = MemoryAlloc(sizeof(struct unkStruct_203B310), 8);
    gUnknown_203B310->unk10 = r0;
    gUnknown_203B310->itemRewardIndex = 0;
    gUnknown_203B310->displayClientDialogueSprite = displayClientSprite;

    // NOTE: dumb var to get correct ordering
    preload = gUnknown_203B310;
    strcpy(gUnknown_202E5D8, preload->unk10->clientName);
    PrintPokeNameToBuffer(gAvailablePokemonNames, GetPlayerPokemonStruct());

    gUnknown_203B310->faceFile = GetDialogueSpriteDataPtr(gUnknown_203B310->unk10->clientSpecies);
    gUnknown_203B310->faceData = NULL;

    gUnknown_203B310->unk20 = 0;
    gUnknown_203B310->unk21 = 0;
    gUnknown_203B310->unk22 = 0;
    gUnknown_203B310->unk1C = 2;
    gUnknown_203B310->unk1E = 8;

    if(gUnknown_203B310->faceFile != NULL)
    {
        gUnknown_203B310->faceData = gUnknown_203B310->faceFile->data;
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
        if(gUnknown_203B310->faceFile != 0)
            CloseFile(gUnknown_203B310->faceFile);
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
            sub_8006518(gUnknown_203B310->unk24);
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B310->unk24[index] = gUnknown_80E041C;
            }
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B310->unk24, 1, 1);
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
  struct Item item;
  
  switch(gUnknown_203B310->state) {
    case PREP_MONEY_REWARD:
        moneyReward = gUnknown_203B310->unk10->moneyReward;
        if (moneyReward == 0) {
            SetRewardSceneState(PREP_FRIEND_AREA_REWARD);
        }
        else {
            gUnknown_202DE30 = moneyReward;
            if (gUnknown_203B310->displayClientDialogueSprite) {
                sub_80141B4(gUnknown_80E0434,0,&gUnknown_203B310->faceFile,0x10d);
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
        if (sub_808D544(0) < 2) {
            sub_80141B4(gUnknown_80E045C,0,0,0x101);
        }
        else {
            sub_80141B4(gUnknown_80E0484,0,0,0x101);
        }
        gUnknown_203B310->nextState = PREP_FRIEND_AREA_REWARD;
        break;
    case PREP_FRIEND_AREA_REWARD:
        if (gUnknown_203B310->unk10->friendAreaReward == 0) {
            SetRewardSceneState(PREP_ITEM_REWARD);
        }
        else {
            sub_8092578(gUnknown_202E628,gUnknown_203B310->unk10->friendAreaReward,FALSE);
            if (gUnknown_203B310->displayClientDialogueSprite) {
                sub_80141B4(gUnknown_80E04B4,0,&gUnknown_203B310->faceFile,0x10d);
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
            sub_80141B4(gUnknown_80E04F4,0,0,0x101);
        }
        else
        {
            if (sub_808D544(0) < 2) {
                UnlockFriendArea(gUnknown_203B310->unk10->friendAreaReward);
                PlaySound(0xce);
                sub_80141B4(gUnknown_80E05C0,0,0,0x101);
            }
            else
            {
                UnlockFriendArea(gUnknown_203B310->unk10->friendAreaReward);
                PlaySound(0xce);
                sub_80141B4(gUnknown_80E05FC,0,0,0x101);
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
                    sub_80141B4(gUnknown_80E0640,0,&gUnknown_203B310->faceFile,0x10d);
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
            gUnknown_202DE30 = gUnknown_203B310->unk10->teamRankPtsReward;
            sub_80141B4(gUnknown_80E0670,0,0,0x101);
        }
        break;
    case NEW_TEAM_RANK:
        PlaySound(0xc9);
        gUnknown_203B310->nextState = REWARD_EXIT;
        rankString = GetTeamRankString(gUnknown_203B310->currTeamRank);
        strcpy(gUnknown_202E038,rankString);
        rankString = GetTeamRankString(GetRescueTeamRank());
        strcpy(gUnknown_202E038 + 0x50,rankString);
        sub_80141B4(gUnknown_80E06A8,0,0,0x101);
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

u32 sub_802F73C(u32 r0, struct UnkTextStruct2_sub *r1, u32 r2, u8 r3)
{
    if (sub_802FCF0(r0))
        return 0;

    if (gUnknown_203B314 == NULL)
        gUnknown_203B314 = MemoryAlloc(sizeof(struct unkStruct_203B314), 8);

    gUnknown_203B314->unkB8 = r3;
    gUnknown_203B314->unkF0 = r0;
    gUnknown_203B314->unkF4 = &gUnknown_203B314->unkF8[gUnknown_203B314->unkF0];
    sub_8006518(gUnknown_203B314->unkF8);

    if (r3 != 0)
        gUnknown_203B314->unkF8[gUnknown_203B314->unkF0] = gUnknown_80E072C;
    else
        gUnknown_203B314->unkF8[gUnknown_203B314->unkF0] = gUnknown_80E0714;

    gUnknown_203B314->unkF4->unk14 = gUnknown_203B314->unk158;

    if (r1 != 0)
        gUnknown_203B314->unkF8[gUnknown_203B314->unkF0].unk8 = *r1;

    sub_8012D08(gUnknown_203B314->unkF4, r2);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B314->unkF8, 1, 1);
    sub_8013818(&gUnknown_203B314->input, sub_802FBF4(), r2, r0);
    sub_802F9C0();
    sub_802FA50();
    return 1;
}

u32 sub_802F848(s16 param_1)
{
    int index;
    s32 param_1_32;

    param_1_32 = param_1; // cast needed

    for( index = 0; index < gUnknown_203B314->input.unk22; index++ ) {
        if (gUnknown_203B314->unk0[index] == param_1_32) {
            sub_8013878(&gUnknown_203B314->input,index);
            sub_802F9C0();
            sub_802FA50();
            return 1;
        }
    }
    sub_8013878(&gUnknown_203B314->input,0);
    return 0;
}

u32 sub_802F8A0(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B314->input);
        return 0;
    }
    else
    {
        switch(GetKeyPress(&gUnknown_203B314->input))
        {
            case INPUT_B_BUTTON:
                PlayMenuSoundEffect(1);
                return 2;
            case INPUT_A_BUTTON:
                PlayMenuSoundEffect(0);
                return 3;
            default:
                if(sub_80138B8(&gUnknown_203B314->input, 1) != 0)
                {
                    sub_802F9C0();
                    sub_802FA50();
                    return 1;
                }
                else
                {
                    return 0;
                }
        }
    }
}

s16 sub_802F90C(void)
{
    return gUnknown_203B314->unk0[(gUnknown_203B314->input.unk1E * gUnknown_203B314->input.unk1C) + gUnknown_203B314->input.menuIndex];
}

void sub_802F938(u8 r0)
{
    gUnknown_203B314->input.unk22 = sub_802FBF4();
    sub_8013984(&gUnknown_203B314->input);
    sub_802F9C0();
    sub_802FA50();

    if(r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B314->input);
}

void sub_802F974(void)
{
    if(gUnknown_203B314 != NULL)
    {
        gUnknown_203B314->unkF8[gUnknown_203B314->unkF0] = gUnknown_80E06FC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B314->unkF8, 1, 1);
        MemoryFree(gUnknown_203B314);
        gUnknown_203B314 = NULL;
    }
}

NAKED
void sub_802F9C0(void)
{
    asm_unified(
	"\tpush {r4,r5,lr}\n"
	"\tldr r4, _0802FA44\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0xAC\n"
	"\tlsls r1, 1\n"
	"\tadds r0, r1\n"
	"\tmovs r2, 0\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r3, _0802FA48\n"
	"\tadds r0, r3\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r3, 0x1\n"
	"\tadds r1, r0, r3\n"
	"\tmovs r0, 0x8\n"
	"\tstrb r0, [r1]\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, _0802FA4C\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xD6\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r0, r2]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r3, [r4]\n"
	"\tadds r5, r3, 0\n"
	"\tadds r5, 0xF0\n"
	"\tldr r2, [r5]\n"
	"\tlsls r1, r2, 1\n"
	"\tadds r1, r2\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r3, r1\n"
	"\tmovs r2, 0x83\n"
	"\tlsls r2, 1\n"
	"\tadds r1, r2\n"
	"\tasrs r2, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r5]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r3, r0\n"
	"\tadds r2, 0x2\n"
	"\tmovs r0, 0x84\n"
	"\tlsls r0, 1\n"
	"\tadds r3, r0\n"
	"\tstrh r2, [r3]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xF8\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0802FA44: .4byte gUnknown_203B314\n"
"_0802FA48: .4byte 0x00000159\n"
"_0802FA4C: .4byte 0x0000015b");
}

void sub_802FA50(void)
{
  s32 sVar1;
  const u8 *text;
  u32 y;
  u32 y2;
  int index;
  int counter;
  
  sub_8008C54(gUnknown_203B314->unkF0);
  sub_80073B8(gUnknown_203B314->unkF0);
  xxx_call_draw_string(10,0,gUnknown_80E0744,gUnknown_203B314->unkF0,0);
  sub_8012BC4(gUnknown_203B314->unk158[2] * 8 + 4,0,gUnknown_203B314->input.unk1E + 1,2,7,gUnknown_203B314->unkF0);
  if (gUnknown_203B314->unkB8 != 0) {
    for(counter = 0; counter < gUnknown_203B314->input.unk1A; counter++)
    {
        y = sub_8013800(&gUnknown_203B314->input,counter);
        index = gUnknown_203B314->input.unk1E * gUnknown_203B314->input.unk1C + counter;
        sVar1 = gUnknown_203B314->unk0[index];
        if (gUnknown_203B314->unk5C[index] != 0) {
            xxx_call_draw_string(10,y,gUnknown_80E0750,gUnknown_203B314->unkF0,0);
        }
        else if (gUnknown_203B314->unk8A[index] != 0) {
            xxx_call_draw_string(10,y,gUnknown_80E0754,gUnknown_203B314->unkF0,0);
        }
        xxx_call_draw_string(0x18,y,sub_80974A0(sVar1),gUnknown_203B314->unkF0,0);
    }
  }
  else {
    for(counter = 0; counter < gUnknown_203B314->input.unk1A; counter++)
    {
        y2 = sub_8013800(&gUnknown_203B314->input,counter);
        text = sub_80974A0(gUnknown_203B314->unk0[gUnknown_203B314->input.unk1E * gUnknown_203B314->input.unk1C + counter]);
        xxx_call_draw_string(8,y2,text,gUnknown_203B314->unkF0,0);
    }
  }
  sub_80073E0(gUnknown_203B314->unkF0);
}
