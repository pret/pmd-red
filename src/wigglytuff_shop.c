#include "global.h"
#include "constants/friend_area.h"
#include "pokemon.h"
#include "constants/input.h"
#include "file_system.h"
#include "menu.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "input.h"
#include "text1.h"
#include "text2.h"
#include "memory.h"
#include "menu_input.h"
#include "friend_area.h"
#include "wigglytuff_shop.h"
#include "felicity_bank.h"
#include "code_80130A8.h"
#include "code_801EE10_mid.h"
#include "code_8021774.h"
#include "code_80118A4.h"
#include "code_800D090.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"

// TODO: This file was originally 3 files. Split properly
// 4 files if you count code_8023144.s

// split1

struct unkStruct_203B280
{
    /* 0x0 */ u8 friendAreas[NUM_FRIEND_AREAS];
    /* 0x3C */ u32 mode;
    MenuInputStruct unk40;
    s32 unk74;
    UnkTextStruct2 *unk78;
    UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
};
EWRAM_DATA_2 struct unkStruct_203B280 *gUnknown_203B280 = {0};
EWRAM_DATA_2 u32 gUnknown_203B284 = {0};
EWRAM_DATA_2 u16 gUnknown_203B288 = {0};
EWRAM_DATA_2 u16 gUnknown_203B28A = {0};

// split2

struct unkStruct_203B28C
{
    MenuInputStructSub unk0;
    /* 0xC */ u8 friendArea;
    bool8 unkD;
    s16 unkE[0x10];
    u32 unk30[0x10];
    /* 0x70 */ s32 numPokemoninFriendArea;
    s32 unk74;
    UnkTextStruct2 *unk78;
    UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
};
EWRAM_DATA_2 struct unkStruct_203B28C *gUnknown_203B28C = {0};

// split3

EWRAM_DATA_2 WigglytuffShop *gWigglytuffShop = {0};

// other stuff

extern u8 *gFriendAreas;
extern u32 gUnknown_202DE30[2];
extern u8 gAvailablePokemonNames[]; // 202DF98
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E628[];

// common_strings.s
extern const u8 *gCommonYes[];
extern const u8 *gCommonNo[];
extern const u8 *gCommonCancel[];
extern const u8 *gCommonInfo[];
extern const u8 *gCommonBuy[];
extern const u8 *gCommonCheck[]; // 80D499C
extern const u8 *gCommonTripleQuestionMark[];
extern const u8 *gCommonWigglytuff[2][20]; // 80D79A4

// split1
extern const UnkTextStruct2 gUnknown_80DC464;
extern const UnkTextStruct2 gUnknown_80DC47C;
extern const u8 gUnknown_80DC494[];
extern const u8 gUnknown_80DC4A4[];
extern const u8 gUnknown_80DC4AC[];
// split2
extern const UnkTextStruct2 gUnknown_80DC4BC;
extern const UnkTextStruct2 gUnknown_80DC4D8;
extern const u8 gUnknown_80DC4F0[];
extern const u8 gUnknown_80DC518[];
extern const u8 gUnknown_80DC524[];
// split3
extern const UnkTextStruct2 gUnknown_80DC534;
extern const UnkTextStruct2 gUnknown_80DC54C;
extern const UnkTextStruct2 gUnknown_80DC564;

u8 sub_8021700(u32);
void sub_8092578(u8 *buffer, u8 index, u8 r2);
extern void sub_803AA34();
extern u8 sub_803ABC8(void);
extern u8 sub_802132C(void);
extern void sub_8022380(void);
bool8 sub_8023144(s32 param_1, s32 index, UnkTextStruct2_sub *sub, u32 param_4);
void sub_8023354(u8 param_1);
extern void CreateWigglytuffConfirmFriendAreaMenu(void);
extern u8 sub_8099B94(void);
extern void sub_8099AFC(u32, u32, u32);
extern void sub_8099A5C(u32, u32, u32);

extern u32 sub_8023278(u32);
void sub_80233A0(void);
s16 sub_802331C(void);

void sub_8022460(void);
void sub_8022538(void);
void sub_80225C8(void);
void HandleWigglytuffConfirmFriendAreaMenu(void);
void sub_80226F0(void);
void sub_8022790(void);
void sub_8022668(void);
void sub_8022684(void);
void sub_80226CC(void);
void sub_80222C8(void);
void SetWigglytuffState(s32);
void sub_8021D5C(void);
void UpdateWigglytuffDialogue(void);

extern void sub_8008C54(u32);

void sub_8021878(void);
void sub_8021894(void);
void sub_8021820(void);
void sub_8021A60(void);
s32 sub_8021664(void);
void sub_8021410(void);
s32 sub_8021B58(s16 species);

extern void PlayMenuSoundEffect(u32);

// split1

bool8 sub_80211AC(u32 mode, u32 param_2)
{
    if (sub_8021700(mode))
        return FALSE;

    gUnknown_203B280 = MemoryAlloc(sizeof(struct unkStruct_203B280), 8);
    gUnknown_203B280->mode = mode;
    gUnknown_203B280->unk74 = param_2;
    gUnknown_203B280->unk78 = &gUnknown_203B280->unk7C[gUnknown_203B280->unk74];
    sub_8006518(gUnknown_203B280->unk7C);
    gUnknown_203B280->unk7C[gUnknown_203B280->unk74] = gUnknown_80DC47C;
    gUnknown_203B280->unk78->unk14 = gUnknown_203B280->unkDC;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B280->unk7C, TRUE, TRUE);
    sub_8013818(&gUnknown_203B280->unk40, sub_8021664(), 10, param_2);

    if (gUnknown_203B284 == gUnknown_203B280->mode) {
        gUnknown_203B280->unk40.menuIndex = gUnknown_203B288;
        gUnknown_203B280->unk40.unk1E = gUnknown_203B28A;
        sub_8013984(&gUnknown_203B280->unk40);
    }

    sub_8021410();
    sub_8021494();
    return TRUE;
}

u32 sub_8021274(bool8 param_1)
{
    if (!param_1) {
        sub_8013660(&gUnknown_203B280->unk40);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B280->unk40)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            if (gUnknown_203B280->mode == 2 && GetFriendAreaPrice(sub_802132C()) > gTeamInventoryRef->teamMoney)
                PlayMenuSoundEffect(2);
            else
                PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B280->unk40, 1) != 0) {
                sub_8021410();
                sub_8021494();
                return 1;
            }
            return 0;
    }
}

u8 sub_802132C(void)
{
    return gUnknown_203B280->friendAreas[gUnknown_203B280->unk40.unk1E * gUnknown_203B280->unk40.unk1C + gUnknown_203B280->unk40.menuIndex];
}

void sub_8021354(bool8 a0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B280->unk7C, FALSE, FALSE);
    gUnknown_203B280->unk40.unk22 = sub_8021664();
    sub_8013984(&gUnknown_203B280->unk40);
    sub_8021410();
    sub_8021494();
    if (a0)
        AddMenuCursorSprite(&gUnknown_203B280->unk40);
}

void sub_80213A0(void)
{
    if (gUnknown_203B280) {
        gUnknown_203B284 = gUnknown_203B280->mode;
        gUnknown_203B288 = gUnknown_203B280->unk40.menuIndex;
        gUnknown_203B28A = gUnknown_203B280->unk40.unk1E;
        gUnknown_203B280->unk7C[gUnknown_203B280->unk74] = gUnknown_80DC464;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B280->unk7C, TRUE, TRUE);
        MemoryFree(gUnknown_203B280);
        gUnknown_203B280 = NULL;
    }
}

NAKED // sub_80095E4 memes
void sub_8021410(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _08021490\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xDC\n"
	"\tmovs r2, 0\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xDD\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xDE\n"
	"\tmovs r1, 0xC\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xDF\n"
	"\tstrb r2, [r0]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x7C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x5A\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x74]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x8A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x74]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x8C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x7C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08021490: .4byte gUnknown_203B280");
}

void sub_8021494(void)
{
    u8 friendAreaIndex;
    s32 index;
    u8 buffer1[80];
    u8 buffer2[80];

    sub_8008C54(gUnknown_203B280->unk74);
    sub_80073B8(gUnknown_203B280->unk74);
    xxx_call_draw_string(10,0,gUnknown_80DC494,gUnknown_203B280->unk74,0); // Friend Areas
    sub_8012BC4(gUnknown_203B280->unkDC[2] * 8 + 4,0,(gUnknown_203B280->unk40).unk1E + 1,1,7,gUnknown_203B280->unk74);

    for (index = 0; index < (gUnknown_203B280->unk40).unk1A; index++) {
        friendAreaIndex = gUnknown_203B280->friendAreas[(gUnknown_203B280->unk40).unk1E * (gUnknown_203B280->unk40).unk1C + index];

        if (gUnknown_203B280->mode == 2) {
            sub_8092578(buffer1,friendAreaIndex,TRUE);

            if (GetFriendAreaPrice(friendAreaIndex) <= gTeamInventoryRef->teamMoney) {
                xxx_call_draw_string(8,sub_8013800(&gUnknown_203B280->unk40,index),buffer1,gUnknown_203B280->unk74,0);
            }
            else {
                sprintfStatic(buffer2,gUnknown_80DC4A4,buffer1); // {RED} %s {END}
                xxx_call_draw_string(8,sub_8013800(&gUnknown_203B280->unk40,index),buffer2,gUnknown_203B280->unk74,0);
            }
        }
        else if (gUnknown_203B280->mode == 0) {
            if (gFriendAreas[friendAreaIndex] == 1) {
                xxx_call_draw_string(8,sub_8013800(&gUnknown_203B280->unk40,index),GetFriendAreaName(friendAreaIndex),gUnknown_203B280->unk74,0);
            }
            else
            {
                sprintfStatic(buffer2,gUnknown_80DC4AC,GetFriendAreaName(friendAreaIndex)); // {GREEN} %s {END}
                xxx_call_draw_string(8,sub_8013800(&gUnknown_203B280->unk40,index),buffer2,gUnknown_203B280->unk74,0);
            }
        }
        else {
            xxx_call_draw_string(8,sub_8013800(&gUnknown_203B280->unk40,index),GetFriendAreaName(friendAreaIndex),gUnknown_203B280->unk74,0);
        }
    }
    sub_80073E0(gUnknown_203B280->unk74);
}

s32 sub_8021664(void)
{
    s32 index;
    s32 counter;

    counter = 0;
    switch(gUnknown_203B280->mode)
    {
        case 0:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                gUnknown_203B280->friendAreas[counter] = index;
                counter++;
            }
            break;
        case 1:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if(gFriendAreas[index])
                {
                    gUnknown_203B280->friendAreas[counter] = index;
                    counter++;
                }
            }
            break;
        case 2:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if (gFriendAreas[index] == 0) {
                    switch(GetFriendAreaUnlockCondition(index))
                    {
                        case UNLOCK_SHOP_STORY:
                            gUnknown_203B280->friendAreas[counter] = index;
                            counter++;
                            break;
                        case UNLOCK_SHOP_POST_GAME:
                            if(sub_80023E4(6) != 0) {
                                gUnknown_203B280->friendAreas[counter] = index;
                                counter++;
                            }
                            break;
                    }
                }
            }
            break;
    }
    return counter;
}

u8 sub_8021700(u32 mode)
{
    s32 index;

    switch(mode)
    {
        case 0:
            return FALSE;
        case 1:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if (gFriendAreas[index] != 0) {
                    return FALSE;
                }
            }
            break;
        case 2:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if (gFriendAreas[index] == 0) {
                    switch(GetFriendAreaUnlockCondition(index))
                    {
                        case UNLOCK_SHOP_STORY:
                            return FALSE;
                        case UNLOCK_SHOP_POST_GAME:
                            if(sub_80023E4(6) != 0) {
                                return FALSE;
                            }
                            break;
                    }
                }
            }
            break;
    }
    return TRUE;
}

// split2

bool8 sub_8021774(u8 friendArea, bool8 param_2, s32 param_3)
{
    gUnknown_203B28C = MemoryAlloc(sizeof(struct unkStruct_203B28C), 8);
    gUnknown_203B28C->friendArea = friendArea;
    gUnknown_203B28C->unkD = param_2;
    sub_801317C(&gUnknown_203B28C->unk0);
    sub_8021A60();
    gUnknown_203B28C->unk74 = param_3;
    gUnknown_203B28C->unk78 = &gUnknown_203B28C->unk7C[param_3];
    sub_8006518(gUnknown_203B28C->unk7C);
    gUnknown_203B28C->unk7C[gUnknown_203B28C->unk74] = gUnknown_80DC4D8;
    sub_8021820();
    return TRUE;
}

u32 sub_80217EC(void)
{
    switch(sub_8012A64(&gUnknown_203B28C->unk0, gUnknown_203B28C->unk74))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            return 0;
    }
}

void sub_8021820(void)
{
    sub_8021878();
    sub_8021894();
}

void sub_8021830(void)
{
    if(gUnknown_203B28C)
    {
        gUnknown_203B28C->unk7C[gUnknown_203B28C->unk74] = gUnknown_80DC4BC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B28C->unk7C, TRUE, TRUE);
        MemoryFree(gUnknown_203B28C);
        gUnknown_203B28C = NULL;
    }
}

void sub_8021878(void)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B28C->unk7C, TRUE, TRUE);
}

void sub_8021894(void)
{
    const u8 *string;
    u32 y;
    u32 x;
    s32 index;
    u8 buffer1 [256];
    u8 buffer2 [100];

    sub_80073B8(gUnknown_203B28C->unk74);
    sub_8092578(buffer1,gUnknown_203B28C->friendArea,FALSE);
    xxx_call_draw_string(0x14,0,buffer1,gUnknown_203B28C->unk74,0);
    string = GetFriendAreaDescription(gUnknown_203B28C->friendArea);
    xxx_call_draw_string(10,0x14,string,gUnknown_203B28C->unk74,0);
    if (gUnknown_203B28C->unkD != 0) {
        xxx_call_draw_string(0x20,0x3c,gUnknown_80DC4F0,gUnknown_203B28C->unk74,0);
    }
    else {
        xxx_call_draw_string(0x20,0x3c,gUnknown_80DC518,gUnknown_203B28C->unk74,0); // Inhabitants
    }
    sub_800792C(gUnknown_203B28C->unk74,4,0x40,0x14,4);
    if (gUnknown_203B28C->unkD != 0) {
        sub_800792C(gUnknown_203B28C->unk74,0xb8,0x40,0x14,4);
    }
    else {
        sub_800792C(gUnknown_203B28C->unk74,0x5e,0x40,0x6e,4);
    }
    sub_800792C(gUnknown_203B28C->unk74,4,0x82,200,4);
    sub_8007A78(gUnknown_203B28C->unk74,3,0x40,0x43,4);
    sub_8007A78(gUnknown_203B28C->unk74,0xcc,0x40,0x43,4);
    for(index = 0; index < gUnknown_203B28C->numPokemoninFriendArea; index++)
    {
        x = (index % 3) * 63 + 7;
        y = (index / 3) * 12 + 0x47;
        sub_808D930(buffer2, gUnknown_203B28C->unkE[index]);
        switch(gUnknown_203B28C->unk30[index])
        {
            case 0: // Not recruited/seen
                xxx_call_draw_string(x,y,*gCommonTripleQuestionMark,gUnknown_203B28C->unk74,0);
                break;
            case 1: // Seen but not recruited
                xxx_call_draw_string(x,y,buffer2,gUnknown_203B28C->unk74,0); // %s
                break;
            case 2:
                sprintfStatic(buffer1,gUnknown_80DC524,buffer2); // {CYAN} %s {END_COLOR}
                xxx_call_draw_string(x,y,buffer1,gUnknown_203B28C->unk74,0);
                break;
        }
    }
    sub_80073E0(gUnknown_203B28C->unk74);
}

void sub_8021A60(void)
{
    s32 sVar4;
    s32 iVar6;
    s32 index;
    PokemonStruct1 *pokeStruct;

    gUnknown_203B28C->numPokemoninFriendArea = 0;
    for(index = 0; index < 0x10; index++)
    {
        gUnknown_203B28C->unkE[index] = 0;
        gUnknown_203B28C->unk30[index] = 0;
    }
    for(index = 0; index < 0x1A8; index++)
    {
        s32 index2 = (s16)index;
        if ((gUnknown_203B28C->friendArea == GetFriendArea(index2)) &&
            (index2 == GetBaseSpeciesNoUnown(index2))) {
            iVar6 = gUnknown_203B28C->numPokemoninFriendArea;
            gUnknown_203B28C->unkE[iVar6] = index2;
            gUnknown_203B28C->numPokemoninFriendArea = iVar6 + 1;
        }
    }
    for(index = 0; index < 0x1A8; index++)
    {
        if ((sub_8098134(index)) && (sVar4 = sub_8021B58(index), sVar4 != -1)) {
            gUnknown_203B28C->unk30[sVar4] = 1;
        }
    }
    for(index = 0; index < NUM_MONSTERS; index++)
    {
        pokeStruct = &gRecruitedPokemonRef->pokemon[index];
        if (((u8)pokeStruct->unk0 & 1) &&
            (sVar4 = sub_8021B58(pokeStruct->speciesNum), sVar4 != -1)) {
            gUnknown_203B28C->unk30[sVar4] = 2;
        }
    }
}

s32 sub_8021B58(s16 species)
{
  s32 baseSpecies;
  int index;
  
  baseSpecies = GetBaseSpeciesNoUnown(species);
  for(index = 0; index < gUnknown_203B28C->numPokemoninFriendArea; index++)
  {
    if (baseSpecies == gUnknown_203B28C->unkE[index]) return index;
  }
  return -1;
}

// split3

bool8 CreateWigglytuffShop(bool32 isAsleep)
{
    u8 *string;
    OpenedFile *file;

    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);
    gWigglytuffShop = MemoryAlloc(sizeof(WigglytuffShop), 8);
    gWigglytuffShop->menuAction1 = 0;
    gWigglytuffShop->menuAction2 = 0;
    gWigglytuffShop->isAsleep = isAsleep;
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8,MONSTER_WIGGLYTUFF);
    CopyYellowMonsterNametoBuffer(gUnknown_202E1C8,MONSTER_WIGGLYTUFF);
    string = GetMonSpecies(MONSTER_WIGGLYTUFF);
    strcpy(gUnknown_202E1C8 - 0x50, string);
    if (gWigglytuffShop->isAsleep == TRUE) {
        gWigglytuffShop->unkCC = NULL;
    }
    else {
        gWigglytuffShop->unkCC = &gWigglytuffShop->faceFile;
    }
    file = GetDialogueSpriteDataPtr(MONSTER_WIGGLYTUFF);
    gWigglytuffShop->faceFile = file;
    gWigglytuffShop->faceData = file->data;
    gWigglytuffShop->unkC8 = 0;
    gWigglytuffShop->unkC9 = 0;
    gWigglytuffShop->unkCA = 0;
    gWigglytuffShop->unkC4 = 2;
    gWigglytuffShop->unkC6 = 8;
    SetWigglytuffState(WIGGLYTUFF_INIT);
    return TRUE;
}

u32 sub_8021C5C(void)
{
    switch(gWigglytuffShop->state)
    {
        case WIGGLYTUFF_INIT:
        case WIGGLYTUFF_MAIN_MENU:
            sub_8022460();
            break;
        case WIGGLYTUFF_UNK9:
        case WIGGLYTUFF_UNKA:
            sub_8022538();
            break;
        case WIGGLYTUFF_UNKB:
            sub_80225C8();
            break;
        case BUY_FRIEND_AREA:
            HandleWigglytuffConfirmFriendAreaMenu();
            break;
        case WIGGLYTUFF_UNKD:
            sub_80226F0();
            break;
        case WIGGLYTUFF_UNKE:
            sub_8022790();
            break;
        case FRIEND_AREA_INFO:
            sub_8022668();
            break;
        case WIGGLYTUFF_UNK16:
        case WIGGLYTUFF_UNK17:
            sub_8022684();
            break;
        case WIGGLYTUFF_EXIT:
            return 3;
        default:
            sub_80226CC();
            break;
    }
    return 0;
}

void sub_8021D1C(void)
{
    if(gWigglytuffShop)
    {
        CloseFile(gWigglytuffShop->faceFile);
        MemoryFree(gWigglytuffShop);
        gWigglytuffShop = NULL;
    }
}

void SetWigglytuffState(s32 newState)
{
    gWigglytuffShop->state = newState;
    sub_8021D5C();
    UpdateWigglytuffDialogue();
}

void sub_8021D5C(void) 
{
    s32 index;
    
    sub_8006518(gWigglytuffShop->unkD0);
    switch(gWigglytuffShop->state)
    {
        case WIGGLYTUFF_UNK9:
        case WIGGLYTUFF_UNKA:
            gWigglytuffShop->unkD0[0] = gUnknown_80DC534;
            gWigglytuffShop->unkD0[2] = gUnknown_80DC534;
            gWigglytuffShop->unkD0[1] = gUnknown_80DC564;
            break;
        case WIGGLYTUFF_UNKB:
            gWigglytuffShop->unkD0[2] = gUnknown_80DC54C;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gWigglytuffShop->unkD0[index] = gUnknown_80DC534;
            }
            break;
    
    }
    ResetUnusedInputStruct();
    sub_800641C(gWigglytuffShop->unkD0, TRUE, TRUE);
}

void UpdateWigglytuffDialogue(void)
{
    char *string;
    unkStruct_8092638 uStack_14;

    switch(gWigglytuffShop->state) 
    {
        case WIGGLYTUFF_INIT:
            sub_80222C8();
            sub_8014248(gCommonWigglytuff[gWigglytuffShop->isAsleep][0],0,gWigglytuffShop->menuAction1,gWigglytuffShop->unk1C,gWigglytuffShop->unk5C,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case WIGGLYTUFF_MAIN_MENU:
            sub_80222C8();
            sub_8014248(gCommonWigglytuff[gWigglytuffShop->isAsleep][1],0,gWigglytuffShop->menuAction1,gWigglytuffShop->unk1C,gWigglytuffShop->unk5C,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case FRIEND_AREA_SELECT_BUY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNK9;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][3],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case FRIEND_AREA_SELECT_BUY_AGAIN:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][4],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_INFO:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_MAIN_MENU;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][19],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_PRE_EXIT:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_EXIT;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][2],0,gWigglytuffShop->unkCC,0x30d);
            break;
        default:
            break;
        case WIGGLYTUFF_CANT_ADD_FRIEND_AREA:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_PRE_EXIT;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][8],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case NO_MONEY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][9],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case NO_FRIEND_AREAS:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_PRE_EXIT;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][10],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case NOT_ENOUGH_MONEY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][11],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_UNK9:
            sub_80211AC(2,3);
            DrawTeamMoneyBox(1);
            break;
        case WIGGLYTUFF_UNKA:
            sub_8021354(TRUE);
            DrawTeamMoneyBox(1);
            break;
        case WIGGLYTUFF_UNKB:
            sub_8021494();
            DrawTeamMoneyBox(1);
            sub_8022380();
            sub_8012D60(&gWigglytuffShop->unk6C,gWigglytuffShop->unk1C,0,gWigglytuffShop->unk5C, gWigglytuffShop->menuAction2,2);
            break;
        case BUY_FRIEND_AREA:
            CreateWigglytuffConfirmFriendAreaMenu();
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,FALSE);
            gUnknown_202DE30[0] = gWigglytuffShop->friendAreaPrice;
            sub_8014248(gCommonWigglytuff[gWigglytuffShop->isAsleep][5],0,5,gWigglytuffShop->unk1C,0,4,0,gWigglytuffShop->unkCC,0xc);
            break;
        case FRIEND_AREA_INFO:
            sub_8021774(gWigglytuffShop->chosenFriendArea,FALSE,2);
            break;
        case CONFIRM_BUY_FRIEND_AREA:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKD;
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,FALSE);
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][6],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_UNKD:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNKE;
            PlaySound(0x25b);
            gWigglytuffShop->unk130 = 1;
            break;
        case WIGGLYTUFF_UNKE:
            gWigglytuffShop->fallbackState = FRIEND_AREA_UNLOCKED;
            gWigglytuffShop->unk134 = 30;
            break;
        case FRIEND_AREA_UNLOCKED:
            if (sub_8021700(2) != 0) {
                sub_80213A0();
                gWigglytuffShop->fallbackState = NO_FRIEND_AREAS;
            }
            else {
                gWigglytuffShop->fallbackState = FRIEND_AREA_SELECT_BUY_AGAIN;
            }
            PlaySound(0xce);
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][7],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNK16;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][12],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_CHECK_AGAIN:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_UNK17;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][13],0,gWigglytuffShop->unkCC,0x10d); 
            break;
        case WIGGLYTUFF_UNK16:
            sub_8023144(0,3,0,10);
            break;
        case WIGGLYTUFF_UNK17:
            sub_8023354(1);
            break;
        case DISPLAY_POKEMON_FRIEND_AREA_INFO:
            sub_8092638(gWigglytuffShop->chosenFriendArea,&uStack_14,FALSE,FALSE);
            if (uStack_14.hasFriendArea) {
                gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_HAS_FRIEND_AREA;
            }
            else
            {
                switch(GetFriendAreaUnlockCondition(gWigglytuffShop->chosenFriendArea))
                {
                    case UNLOCK_SHOP_POST_GAME:
                        if (sub_80023E4(6) != 0) {
                            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
                        }
                        else {
                            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_POST_GAME;
                        }
                        break;
                    case UNLOCK_WONDER_MAIL:
                        gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_WONDER_MAIL;
                        break;
                    case UNLOCK_LEGENDARY_REQUEST:
                        gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_LEGENDARY;
                        break;
                    default:
                        gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
                        break;
                }
            }
            string = GetMonSpecies(gWigglytuffShop->chosenSpecies);
            strcpy(gAvailablePokemonNames,string);
            sub_8092578(gUnknown_202E628,gWigglytuffShop->chosenFriendArea,FALSE);
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][14],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_HAS_FRIEND_AREA:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][15],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_POST_GAME:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][16],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_WONDER_MAIL:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][17],0,gWigglytuffShop->unkCC,0x10d);
            break;
        case WIGGLYTUFF_CHECK_LEGENDARY:
            gWigglytuffShop->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[gWigglytuffShop->isAsleep][18],0,gWigglytuffShop->unkCC,0x10d);
            break;
    }
}

void sub_80222C8(void)
{
    s32 i;
    s32 index = 0;
    MemoryFill16(gWigglytuffShop->unk5C, 0, sizeof(gWigglytuffShop->unk5C));
    gWigglytuffShop->unk1C[index].text = *gCommonBuy;
    gWigglytuffShop->unk1C[index].menuAction = 2;
    index++;
    gWigglytuffShop->unk1C[index].text = *gCommonCheck;
    gWigglytuffShop->unk1C[index].menuAction = 3;
    index++;
    gWigglytuffShop->unk1C[index].text = *gCommonInfo;
    gWigglytuffShop->unk1C[index].menuAction = 4;
    index++;
    gWigglytuffShop->unk1C[index].text = *gCommonCancel;
    gWigglytuffShop->unk1C[index].menuAction = 1;
    index++;
    gWigglytuffShop->unk1C[index].text = NULL;
    gWigglytuffShop->unk1C[index].menuAction = 1;

    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0 && gWigglytuffShop->unk1C[i].menuAction == gWigglytuffShop->menuAction1)
            return;
    }
    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0)
        {
            gWigglytuffShop->menuAction1 = gWigglytuffShop->unk1C[i].menuAction;
            break;
        }
    }
}

void sub_8022380(void)
{
    s32 i;
    s32 index = 0;
    MemoryFill16(gWigglytuffShop->unk5C, 0, sizeof(gWigglytuffShop->unk5C));
    gWigglytuffShop->unk1C[index].text = *gCommonBuy;
    gWigglytuffShop->unk1C[index].menuAction = 2;
    index++;
    gWigglytuffShop->unk1C[index].text = *gCommonInfo;
    gWigglytuffShop->unk1C[index].menuAction = 4;
    index++;
    gWigglytuffShop->unk1C[index].text = NULL;
    gWigglytuffShop->unk1C[index].menuAction = 1;

    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0 && gWigglytuffShop->unk1C[i].menuAction == gWigglytuffShop->menuAction2)
            return;
    }
    for(i = 0; i < index; i++)
    {
        if(gWigglytuffShop->unk5C[i] == 0)
        {
            gWigglytuffShop->menuAction2 = gWigglytuffShop->unk1C[i].menuAction;
            break;
        }
    }
}

void CreateWigglytuffConfirmFriendAreaMenu(void)
{
    s32 index = 0;
    MemoryFill16(gWigglytuffShop->unk5C, 0, sizeof(gWigglytuffShop->unk5C));
    gWigglytuffShop->unk1C[index].text = *gCommonYes;
    gWigglytuffShop->unk1C[index].menuAction = 5;
    index++;
    gWigglytuffShop->unk1C[index].text = *gCommonNo;
    gWigglytuffShop->unk1C[index].menuAction = 6;
    index++;
    gWigglytuffShop->unk1C[index].text = NULL;
    gWigglytuffShop->unk1C[index].menuAction = 1;
}

void sub_8022460(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0)
    {
        if (menuAction != 1) {
            gWigglytuffShop->menuAction1 = menuAction;
        }
        switch(menuAction)
        {
            case 2:
                if (sub_8021700(2) != 0) {
                    SetWigglytuffState(WIGGLYTUFF_CANT_ADD_FRIEND_AREA);
                }
                else {
                    SetWigglytuffState(FRIEND_AREA_SELECT_BUY);
                }
                break;
            case 3:
                SetWigglytuffState(WIGGLYTUFF_CHECK);
                break;
            case 4:
                SetWigglytuffState(WIGGLYTUFF_INFO);
                break;
            case 1:
                SetWigglytuffState(WIGGLYTUFF_PRE_EXIT);
                break;
        }
    }
}

void HandleWigglytuffConfirmFriendAreaMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch(menuAction)
        {
            case 5:
                gTeamInventoryRef->teamMoney -= gWigglytuffShop->friendAreaPrice;
                UnlockFriendArea(gWigglytuffShop->chosenFriendArea);
                PlaySound(0x14C);
                SetWigglytuffState(CONFIRM_BUY_FRIEND_AREA);
                break;
            case 1:
            case 6:
                SetWigglytuffState(WIGGLYTUFF_UNKA);
                break;
        }
    }
}

void sub_8022538(void)
{
    switch(sub_8021274(TRUE))
    {
        case 3:
            gWigglytuffShop->chosenFriendArea = sub_802132C();
            gWigglytuffShop->friendAreaPrice = GetFriendAreaPrice(gWigglytuffShop->chosenFriendArea);
            SetWigglytuffState(WIGGLYTUFF_UNKB);
            break;
        case 4:
            gWigglytuffShop->chosenFriendArea = sub_802132C();
            gWigglytuffShop->friendAreaPrice = GetFriendAreaPrice(gWigglytuffShop->chosenFriendArea);
            SetWigglytuffState(FRIEND_AREA_INFO);
            break;
        case 0:
            break;
        case 2:
            sub_80213A0();
            SetWigglytuffState(WIGGLYTUFF_MAIN_MENU);
            break;
        case 1:
        default:
            DrawTeamMoneyBox(1);
            break;
    }
}

void sub_80225C8(void)
{
    s32 menuAction = 0;
    sub_8021274(FALSE);
    if(sub_8012FD8(&gWigglytuffShop->unk6C) == 0)
    {
        sub_8013114(&gWigglytuffShop->unk6C, &menuAction);
        if(menuAction != 1) gWigglytuffShop->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        case 2:
            if(gTeamInventoryRef->teamMoney == 0)
            {
                SetWigglytuffState(NO_MONEY);
            }
            else if(gWigglytuffShop->friendAreaPrice > gTeamInventoryRef->teamMoney)
            {
                SetWigglytuffState(NOT_ENOUGH_MONEY);
            }
            else
            {
                SetWigglytuffState(BUY_FRIEND_AREA);
            }
            break;
        case 4:
            SetWigglytuffState(FRIEND_AREA_INFO);
            break;
        case 1:
            SetWigglytuffState(WIGGLYTUFF_UNKA);
            break;
    }
}

void sub_8022668(void)
{
    switch(sub_80217EC())
    {
        case 2:
        case 3:
            sub_8021830();
            SetWigglytuffState(WIGGLYTUFF_UNKA);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8022684(void)
{
    switch(sub_8023278(1))
    {
        case 3:
            gWigglytuffShop->chosenSpecies = sub_802331C();
            gWigglytuffShop->chosenFriendArea = GetFriendArea(gWigglytuffShop->chosenSpecies);
            SetWigglytuffState(DISPLAY_POKEMON_FRIEND_AREA_INFO);
            break;
        case 2:
            sub_80233A0();
            SetWigglytuffState(WIGGLYTUFF_MAIN_MENU);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_80226CC(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        SetWigglytuffState(gWigglytuffShop->fallbackState);
}

void sub_80226F0(void)
{
    union {
        vu32 a;
        vu8 b[4];
    } temp;
    vu8 *ptr = temp.b;
    u32 r2 = 0;
    ptr[0] = 0x80;
    ptr[1] = 0x80;
    ptr[2] = 0x10;
    ptr[3] = r2;
    if(sub_8099B94() == 0)
    {
        switch(gWigglytuffShop->unk130)
        {
            case 1:
            case 3:
                sub_8099AFC(5, 2, temp.a);
                break;
            case 2:
            case 4:
                sub_8099A5C(5, 2, temp.a);
                break;
            case 0:
            default:
                SetWigglytuffState(gWigglytuffShop->fallbackState);
                gWigglytuffShop->unk130 = 0;
                break;
        }
        gWigglytuffShop->unk130++;
    }
}

void sub_8022790(void)
{
    if (gWigglytuffShop->unk134 != 0)
        gWigglytuffShop->unk134--;
    else
        SetWigglytuffState(gWigglytuffShop->fallbackState);
}
