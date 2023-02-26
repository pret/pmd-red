#include "global.h"
#include "constants/input.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "wonder_mail.h"
#include "menu.h"
#include "pokemon.h"
#include "rescue_team_info.h"
#include "friend_area.h"
#include "item.h"
#include "menu_input.h"

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
    u8 unk5[3];
    u32 unk8;
    u8 fillC[0x4C - 0xC];
    u8 unk4C;
    u8 fill4D[0x58 - 0x4D];
    u8 *unk58;
    u32 unk5C;
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
    u8 unkA;
    u8 unkB;
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

// TODO: port to ItemSlot
struct Item_Alt
{
    union temp {
        struct Item norm;
        u32 full_bits;
    } temp;
};

struct unkStruct_203B314
{
    // size: 0x15C
    s16 unk0[2];
    u8 fill4[0xB8 - 0x4];
    u8 unkB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    u32 unkBC;
    u8 fillC0[0xD4 - 0xC0];
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    s16 unkDA;
    s16 unkDC;
    s16 unkDE;
    u8 fillDF[0xF0 - 0xE0];
    u32 unkF0;
    struct UnkTextStruct2 *unkF4;
    struct UnkTextStruct2 unkF8[4];
    u8 unk158[4];
};

extern struct unkStruct_203B314 *gUnknown_203B314;

extern u8 sub_802FCF0(u32);
extern void sub_802F9C0(void);
extern void sub_802FA50(void);
extern void sub_8013818(u32 *, u32, u32, u32);
extern u32 sub_802FBF4(void);
extern void sub_8013878(u32 *, s32);

extern void AddMenuCursorSprite(u32 *);
extern void sub_8013984(u32 *);
extern void sub_802F2E8(u32);
extern void sub_802EFEC(u32);
extern void sub_802F148(void);
extern void sub_802F184(void);
extern void sub_802F1E8(void);
extern void sub_802F004();
extern void sub_802F088();
extern void sub_801B72C(void);
extern u32 sub_801B6AC(void);
extern void sub_802F108(void);
extern s32 sub_80144A4(s32 *);
extern void sub_803B35C(struct WonderMail*, u32 *);
extern void sub_802DE84(u32 *);
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
extern void sub_802F718(void);
extern u8 sub_80138B8(u32 *, u32);
extern void sub_8013660(u32 *);
extern u32 GetKeyPress(u32 *);
extern void PlayMenuSoundEffect(u32);
extern void sub_802F300(void);
extern void PlaySound(u32);
extern s32 sub_808D544(u32);
extern void sub_80141B4(const u8 *, u32, struct OpenedFile **, u32);
extern u32 sub_801B60C(u32, u8, u8);
extern void sub_8092578(u8 *buffer, u8 index, u8 r2);
void HandleMissionReward(void);

const struct UnkTextStruct2 gUnknown_80E03C4 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E03DC = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x00, 0x03, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E03F4 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x00, 0x06, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const u8 gUnknown_80E040C[] = "Send";
static const u8 wonder_mail_fill[] = "pksdir0";
const struct UnkTextStruct2 gUnknown_80E041C = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
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
        "{CENTER_ALIGN}you can have {COLOR_1 LIGHT_BLUE_2}1{COMMA}000{END_COLOR_TEXT_1} {POKE}.");

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
        "{CENTER_ALIGN}Rescue Team {COLOR_1 LIGHT_BLUE_2}$t{END_COLOR_TEXT_1}\n"
        "{CENTER_ALIGN}gained {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} rescue points.");

ALIGNED(4) const u8 gUnknown_80E06A8[] = _(
        "{CENTER_ALIGN}Congratulations!{EXTRA_MSG}"
        "{CENTER_ALIGN}{COLOR_1 LIGHT_BLUE_2}$t{END_COLOR_TEXT_1} went up in rank\n"
        "{CENTER_ALIGN}from the {ARG_POKEMON_2}\n"
        "{CENTER_ALIGN}to the {ARG_POKEMON_3}!");

static const u8 wonder_mail_fill2[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80E06FC = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0714 = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x00, 0x02, 0x00,
    0x0E, 0x0E,
    0x0E, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E072C = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x00, 0x02, 0x00,
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
    s32 iVar3;

    sub_8006518(gUnknown_203B30C->unkF0);
    switch(gUnknown_203B30C->state)
    {
        case 2:
            sub_802F108();
            gUnknown_203B30C->unkF0[2] = gUnknown_80E03F4;
            sub_8012CAC(&gUnknown_203B30C->unkF0[2], gUnknown_203B30C->unkB0);
            break;
        default:
            for(iVar3 = 0; iVar3 < 4; iVar3++)
            {
                gUnknown_203B30C->unkF0[iVar3] = gUnknown_80E03C4;
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
            gUnknown_203B30C->unk8 = 3;
            gUnknown_203B30C->unk4C = 0;
            gUnknown_203B30C->unk58 = temp->unk18;
            sub_802DE84(&gUnknown_203B30C->unk8);
    }
}

void sub_802F108(void)
{
    struct unkStruct_203B30C *preload;
    const u8 *blankText;
    s32 action_1;

    preload = gUnknown_203B30C;
    blankText = NULL;
    preload->unkB0[0].text = gUnknown_80E040C;
    preload->unkB0[0].menuAction = 2;
    action_1 = 1;
    preload->unkB0[1].text = *gUnknown_80D4970;
    preload->unkB0[1].menuAction = 3;
    preload->unkB0[2].text = blankText;
    preload->unkB0[2].menuAction = action_1;
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



u32 sub_802F204(struct unkStruct_802F204 *r0, bool8 r1)
{
    struct unkStruct_203B310 *preload;

    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
    gUnknown_203B310 = MemoryAlloc(sizeof(struct unkStruct_203B310), 8);
    gUnknown_203B310->unk10 = r0;
    gUnknown_203B310->itemRewardIndex = 0;
    gUnknown_203B310->displayClientDialogueSprite = r1;

    // NOTE: dumb var to get correct ordering
    preload = gUnknown_203B310;
    strcpy(gUnknown_202E5D8, preload->unk10->clientName);
    PrintPokeNameToBuffer(gAvailablePokemonNames, GetPlayerPokemonStruct());

    gUnknown_203B310->faceFile = GetDialogueSpriteDataPtr(gUnknown_203B310->unk10->unk14);
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

    sub_802F2E8(0);
    return 1;
}

u32 sub_802F298(void)
{
    switch(gUnknown_203B310->state)
    {
        case 9:
            return 3;
        case 5:
            sub_802F6FC();
            return 0;
        default:
            sub_802F718();
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

void sub_802F2E8(u32 newState)
{
    gUnknown_203B310->state = newState;
    sub_802F300();
    HandleMissionReward();
}

void sub_802F300(void)
{
    s32 iVar3;
    switch(gUnknown_203B310->state)
    {
        case 0:
            sub_8006518(gUnknown_203B310->unk24);
            for(iVar3 = 0; iVar3 < 4; iVar3++)
            {
                gUnknown_203B310->unk24[iVar3] = gUnknown_80E041C;
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
    case 0:
    // Reward intro..
        moneyReward = gUnknown_203B310->unk10->moneyReward;
        if (moneyReward == 0) {
            sub_802F2E8(2);
        }
        else {
            gUnknown_202DE30 = moneyReward;
            if (gUnknown_203B310->displayClientDialogueSprite) {
                sub_80141B4(gUnknown_80E0434,0,&gUnknown_203B310->faceFile,0x10d);
                gUnknown_203B310->nextState = 1;
            }
            else {
                sub_802F2E8(1);
            }
        }
        break;
    case 1:
        PlaySound(0xcb);
        AddToTeamMoney(gUnknown_203B310->unk10->moneyReward);
        if (sub_808D544(0) < 2) {
            sub_80141B4(gUnknown_80E045C,0,0,0x101);
        }
        else {
            sub_80141B4(gUnknown_80E0484,0,0,0x101);
        }
        gUnknown_203B310->nextState = 2;
        break;
    case 2:
        if (gUnknown_203B310->unk10->friendAreaReward == '\0') {
            // No friend area reward.. go to item reward
            sub_802F2E8(4);
        }
        else {
            sub_8092578(gUnknown_202E628,gUnknown_203B310->unk10->friendAreaReward,0);
            if (gUnknown_203B310->displayClientDialogueSprite) {
                sub_80141B4(gUnknown_80E04B4,0,&gUnknown_203B310->faceFile,0x10d);
                gUnknown_203B310->nextState = 3;
            }
            else {
                sub_802F2E8(3);
            }
        }
        break;
    case 3:
        // Friend area reward
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
        gUnknown_203B310->nextState = 4;
        break;
    case 4:
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
                    gUnknown_203B310->nextState = 5;
                }
                else
                {
                     sub_802F2E8(5);
                }
            }
            else
            {
                sub_802F2E8(5);
            }
        }
        else
            sub_802F2E8(7);
        break;
    case 5:
    // Item reward
        if ((gUnknown_203B310->unk10->itemRewards[gUnknown_203B310->itemRewardIndex]) == 0) {
            // No item in this reward slot
            sub_802F2E8(6);
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
    case 6:
        // Increase item reward slot index
        gUnknown_203B310->itemRewardIndex++;
        if(gUnknown_203B310->itemRewardIndex < MAX_ITEM_REWARDS)
            sub_802F2E8(5);
        else
            // No more items to check... move to give points
            sub_802F2E8(7);
        break;
    case 7:
        if (gUnknown_203B310->unk10->teamRankPtsReward == 0) {
            // No pnts to reward
            sub_802F2E8(9);
        }
        else {
            gUnknown_203B310->currTeamRank = GetRescueTeamRank();
            AddToTeamRankPts(gUnknown_203B310->unk10->teamRankPtsReward);
            PlaySound(0xcb);
            if (gUnknown_203B310->currTeamRank != GetRescueTeamRank()) {
                // Rank up time
                gUnknown_203B310->nextState = 8;
            }
            else {
                // No rank up.. close out
                gUnknown_203B310->nextState = 9;
            }
            gUnknown_202DE30 = gUnknown_203B310->unk10->teamRankPtsReward;
            sub_80141B4(gUnknown_80E0670,0,0,0x101);
        }
        break;
    case 8:
        // Rank up
        PlaySound(0xc9);
        gUnknown_203B310->nextState = 9;
        rankString = GetTeamRankString(gUnknown_203B310->currTeamRank);
        strcpy(gUnknown_202E038,rankString);
        rankString = GetTeamRankString(GetRescueTeamRank());
        strcpy(gUnknown_202E038 + 0x50,rankString);
        sub_80141B4(gUnknown_80E06A8,0,0,0x101);
        break;
    case 9:
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
            sub_802F2E8(6);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_802F718(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0) {
        sub_802F2E8(gUnknown_203B310->nextState);
    }
}

u32 sub_802F73C(u32 r0, struct UnkTextStruct2_sub *r1, u32 r2, u8 r3)
{
    if(sub_802FCF0(r0))
    {
        return 0;
    }
    else
    {
        if(gUnknown_203B314 == NULL)
            gUnknown_203B314 = MemoryAlloc(sizeof(struct unkStruct_203B314), 0x8);
        gUnknown_203B314->unkB8 = r3;
        gUnknown_203B314->unkF0 = r0;
        gUnknown_203B314->unkF4 = &gUnknown_203B314->unkF8[gUnknown_203B314->unkF0];
        sub_8006518(gUnknown_203B314->unkF8);
        if(r3 != 0)
        {
            gUnknown_203B314->unkF8[gUnknown_203B314->unkF0] = gUnknown_80E072C;
        }
        else
        {
            gUnknown_203B314->unkF8[gUnknown_203B314->unkF0] = gUnknown_80E0714;
        }

        gUnknown_203B314->unkF4->unk14 = gUnknown_203B314->unk158;
        if(r1 != 0)
        {
             gUnknown_203B314->unkF8[gUnknown_203B314->unkF0].unk08 = *r1;
        }

        sub_8012D08(gUnknown_203B314->unkF4, r2);
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B314->unkF8, 1, 1);
        sub_8013818(&gUnknown_203B314->unkBC, sub_802FBF4(), r2, r0);
        sub_802F9C0();
        sub_802FA50();
        return 1;
    }
}

u32 sub_802F848(s16 param_1)
{
    int iVar2;
    s32 param_1_32;

    param_1_32 = param_1; // cast needed

    for( iVar2 = 0; iVar2 < gUnknown_203B314->unkDE; iVar2++ ) {
        if (gUnknown_203B314->unk0[iVar2] == param_1_32) {
            sub_8013878(&gUnknown_203B314->unkBC,iVar2);
            sub_802F9C0();
            sub_802FA50();
            return 1;
        }
    }
    sub_8013878(&gUnknown_203B314->unkBC,0);
    return 0;
}

u32 sub_802F8A0(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B314->unkBC);
        return 0;
    }
    else
    {
        switch(GetKeyPress(&gUnknown_203B314->unkBC))
        {
            case INPUT_B_BUTTON:
                PlayMenuSoundEffect(1);
                return 2;
            case INPUT_A_BUTTON:
                PlayMenuSoundEffect(0);
                return 3;
            default:
                if(sub_80138B8(&gUnknown_203B314->unkBC, 1) != 0)
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
    return gUnknown_203B314->unk0[(gUnknown_203B314->unkDA * gUnknown_203B314->unkD8) + gUnknown_203B314->unkD4];
}

void sub_802F938(u8 r0)
{
    gUnknown_203B314->unkDE = sub_802FBF4();
    sub_8013984(&gUnknown_203B314->unkBC);
    sub_802F9C0();
    sub_802FA50();

    if(r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B314->unkBC);
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
