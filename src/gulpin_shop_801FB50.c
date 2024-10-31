#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "iq_skill_menu.h"
#include "code_801EE10.h"
#include "code_801EE10_mid.h"
#include "code_8023868.h"
#include "code_8024458.h"
#include "common_strings.h"
#include "felicity_bank.h"
#include "gulpin_shop.h"
#include "gulpin_shop_801FB50.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon_3.h"
#include "pokemon_mid.h"
#include "text1.h"
#include "text2.h"

EWRAM_DATA_2 unkStruct_203B27C *gUnknown_203B27C = {0};

extern u8 gSpeakerNameBuffer[];

#include "data/gulpin_shop_801FB50.h"

enum menuActions {
    CANCEL_ACTION = 1,
    PROCEED_ACTION,
    REMEMBER_ACTION,
    MOVES_ACTION,
    SET_ACTION,
    DESELECT_ACTION,
    LINK_ACTION = 8,
    DE_LINK_ACTION,
    FORGET_ACTION,
    INFO_ACTION,
    CHECK_IQ_ACTION,
    SETTING_MOVES_ACTION,
    LINKING_MOVES_ACTION,
    REMEMBERING_MOVES_ACTION,
    YES_ACTION,
    NO_ACTION,
};

static void CreateGulpinLinkMenu(void);
static void CreateGulpinShopMenu(void);

static void sub_801FDA8(s32);
static void sub_801FDC0(void);
static void sub_801FF28(void);
static void sub_80205D0(void);
static void sub_802069C(void);
static void sub_80208B0(void);
static void sub_8020900(void);
static void sub_8020950(void);
static void sub_80209AC(void);
static void sub_80209FC(void);
static void sub_8020A34(void);
static void sub_8020A80(void);
static void sub_8020B38(void);
static void sub_8020C2C(void);
static void sub_8020C48(void);
static void sub_8020C64(void);
static void sub_8020CC0(void);
static void sub_8020D74(void);
static void sub_8020D90(void);
static void sub_8020DCC(void);
static void sub_8020EB4(void);
static void sub_80210C8(void);
static void sub_80210E4(void);
static void sub_8021130(void);
static void sub_8021154(void);
static bool8 sub_8021178(void);

bool8 sub_801FB50(u32 mode)
{
    u8 *name;
    OpenedFile *faceFile;

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    gUnknown_203B27C = MemoryAlloc(sizeof(unkStruct_203B27C), 0x8);
    gUnknown_203B27C->menuAction2 = 0;
    gUnknown_203B27C->menuAction3 = 0;
    gUnknown_203B27C->menuAction4 = 0;
    gUnknown_203B27C->mode = mode;
    gUnknown_203B27C->unk15 = FALSE;
    CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_GULPIN);
    CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_GULPIN);
    name = GetMonSpecies(MONSTER_GULPIN);
    strcpy(gFormatBuffer_Monsters[6], name);
    PrintPokeNameToBuffer(gFormatBuffer_Monsters[4], GetPlayerPokemonStruct());

    if (gUnknown_203B27C->mode == GULPIN_SHOP_MODE_ASLEEP)
        gUnknown_203B27C->monPortraitPtr = NULL;
    else
        gUnknown_203B27C->monPortraitPtr = &gUnknown_203B27C->monPortrait;

    faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
    gUnknown_203B27C->monPortrait.faceFile = faceFile;
    gUnknown_203B27C->monPortrait.faceData = (void *) faceFile->data;
    gUnknown_203B27C->monPortrait.spriteId = 0;
    gUnknown_203B27C->monPortrait.flip = FALSE;
    gUnknown_203B27C->monPortrait.unkE = 0;
    gUnknown_203B27C->monPortrait.pos.x = 2;
    gUnknown_203B27C->monPortrait.pos.y = 8;
    sub_801FDA8(0);
    return TRUE;
}

u32 sub_801FC40(void)
{
    switch (gUnknown_203B27C->state) {
        case 0:
        case 1:
            sub_8021154();
            break;
        case 2:
            sub_80209AC();
            break;
        case 7:
            sub_80209FC();
            break;
        case 8:
            sub_8020A34();
            break;
        case 0xf:
        case 0x10:
            sub_8020A80();
            break;
        case 0x11:
            sub_8020B38();
            break;
        case 0x12:
            sub_8020C2C();
            break;
        case 0x13:
            sub_8020C48();
            break;
        case 0x15:
        case 0x16:
            sub_8020C64();
            break;
        case 0x17:
            sub_8020CC0();
            break;
        case 0x18:
            sub_8020D74();
            break;
        case 0x1d:
            sub_8020D90();
            break;
        case 0x1e:
        case 0x1f:
            sub_8020DCC();
            break;
        case 0x20:
            sub_8020EB4();
            break;
        case 0x21:
            sub_80210C8();
            break;
        case 0x22:
            sub_80210E4();
            break;
        case 0xd:
            if (gUnknown_203B27C->unk15 == TRUE)
                gTeamInventoryRef->teamMoney -= 150;
            return 3;
        default:
            sub_8021130();
            break;
    }
    return 0;
}

void sub_801FD7C(void)
{
    if (gUnknown_203B27C) {
        CloseFile(gUnknown_203B27C->monPortrait.faceFile);
        MemoryFree(gUnknown_203B27C);
        gUnknown_203B27C = NULL;
    }
}

static void sub_801FDA8(s32 newState)
{
    gUnknown_203B27C->state = newState;
    sub_801FDC0();
    sub_801FF28();
}

static void sub_801FDC0(void)
{
    s32 index;

    RestoreUnkTextStruct_8006518(gUnknown_203B27C->unk180);

    switch (gUnknown_203B27C->state) {
        case 0x2:
            gUnknown_203B27C->unk180[0].unk0 = 0x80;
            gUnknown_203B27C->unk180[1].unk0 = 0x80;
            gUnknown_203B27C->unk180[2].unk0 = 0x80;
            gUnknown_203B27C->unk180[3] = gUnknown_80DC37C;
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B27C->unk180, TRUE, FALSE);
            break;
        case 0x11:
            sub_80205D0();
            gUnknown_203B27C->unk180[2] = gUnknown_80DC334;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
        case 0x17:
            sub_802069C();
            gUnknown_203B27C->unk180[2] = gUnknown_80DC334;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
        case 0x20:
            CreateGulpinLinkMenu();
            gUnknown_203B27C->unk180[1] = gUnknown_80DC31C;
            gUnknown_203B27C->unk180[2] = gUnknown_80DC34C;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
        default:
            for (index = 0; index < 4; index++)
                gUnknown_203B27C->unk180[index] = gUnknown_80DC31C;

            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
    }
}

static void sub_801FF28(void)
{
    s32 index;

    switch(gUnknown_203B27C->state)
    {
        case 0:
            gUnknown_203B27C->menuAction1 = 2;
            CreateGulpinShopMenu();
            gUnknown_203B27C->fallbackState = 2;
            CreateMenuDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_00],0,gUnknown_203B27C->menuAction1,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,gUnknown_203B27C->monPortraitPtr,0xc);
            break;
        case 1:
            CreateGulpinShopMenu();
            gUnknown_203B27C->fallbackState = 2;
            CreateMenuDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_01],0,gUnknown_203B27C->menuAction1,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,gUnknown_203B27C->monPortraitPtr,0xc);
            break;
        case 2:
            DrawTeamMoneyBox(3);
            break;
        case 3:
            gUnknown_203B27C->fallbackState = 0x1f;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_02],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 4:
            gUnknown_203B27C->fallbackState = 0x1f;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_03],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 5:
            gUnknown_203B27C->fallbackState = 0x1f;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_04],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 6:
            gUnknown_203B27C->fallbackState = 0x1f;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_05],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 7:
            sub_8020900();
            CreateMenuDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_06],0,0x10,
                        gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                        gUnknown_203B27C->monPortraitPtr,0xc);
            break;
        case 8:
            sub_8020950();
            CreateMenuDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_21],0,0xd,
                        gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                        gUnknown_203B27C->monPortraitPtr,0xc);
            break;
        case 9:
            gUnknown_203B27C->fallbackState = 1;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_22],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 10:
            gUnknown_203B27C->fallbackState = 1;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_23],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 0xb:
            gUnknown_203B27C->fallbackState = 1;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_24],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 0xc:
            gUnknown_203B27C->fallbackState = 0xd;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_07],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 0xe:
            gUnknown_203B27C->fallbackState = 0xf;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_08],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 0xf:
            sub_8023868(2,0,0,10);
            break;
        case 0x10:
            sub_8023B7C(1);
            break;
        case 0x11:
            sub_8023DA4();
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->menuAction2,2);
            break;
        case 0x12:
            sub_8024458(gUnknown_203B27C->speciesNum,2);
            break;
        case 0x13:
            CreateIQSkillMenu(gUnknown_203B27C->speciesNum);
            break;
        case 0x14:
            gUnknown_203B27C->fallbackState = 0x15;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_09],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 0x15:
            sub_801F428(gUnknown_203B27C->speciesNum,0);
            break;
        case 0x16:
            sub_801F5F0(TRUE);
            break;
        case 0x17:
            sub_801F700();
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->menuAction3,2);
            break;
        case 0x18:
            gUnknown_203B27C->sequenceMoveIDs[0] = gUnknown_203B27C->unk1C;
            for(index = 1; index < 4; index++)
            {
                gUnknown_203B27C->sequenceMoveIDs[index] = 0;
            }
            sub_801F808(gUnknown_203B27C->sequenceMoveIDs);
            break;
        case 0x19:
            sub_8094060(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            gUnknown_203B27C->fallbackState = 0x10;
            sub_8092C84(gFormatBuffer_Monsters[0],gUnknown_203B27C->unk1E);
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_10],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 0x1a:
            sub_8094060(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            gUnknown_203B27C->fallbackState = 0x10;
            if (gUnknown_203B27C->isNextMoveLinked) {
                CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_14],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            }
            else
        {
                CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_13],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            }
            break;
        case 0x1d:
            if (gUnknown_203B27C->mode == GULPIN_SHOP_MODE_AWAKE) {
                CreateGulpinShop(FALSE,gUnknown_203B27C->speciesNum,gUnknown_203B27C->moves);
            }
            else {
                CreateGulpinShop(TRUE,gUnknown_203B27C->speciesNum,gUnknown_203B27C->moves);
            }
            break;
        case 0x1b:
            gUnknown_203B27C->fallbackState = 0x10;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_15],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;
        case 0x1c:
            gUnknown_203B27C->fallbackState = 0x10;
            CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_16],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            break;

        case 0x1e:
            unk_CopyMoves4To8(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            sub_801EE10(1,gUnknown_203B27C->speciesNum,gUnknown_203B27C->moves,gUnknown_203B27C->unk15,gUnknown_80DC394,0);
            break;
        case 0x1f:
            sub_801F1B0(TRUE, gUnknown_203B27C->unk15);
            break;
        case 0x20:
            sub_801F280(0);
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->menuAction4,2);
            break;
        case 0x21:
            GetLinkedSequence(gUnknown_203B27C->moveIndex,gUnknown_203B27C->moves,gUnknown_203B27C->sequenceMoveIDs);
            sub_801F808(gUnknown_203B27C->sequenceMoveIDs);
            break;
        case 0x22:
            sub_80208B0();
            sub_8092C84(gFormatBuffer_Monsters[1],gUnknown_203B27C->unk20);
            if (gUnknown_203B27C->isNextMoveLinked) {
                CreateMenuDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_18],0,0x11,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                            gUnknown_203B27C->monPortraitPtr,0xc);
            }
            else {
                CreateMenuDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_17],0,0x11,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                            gUnknown_203B27C->monPortraitPtr,0xc);
            }
            break;
        case 0x23:
            gUnknown_203B27C->fallbackState = 0x1f;
            sub_8092C84(gFormatBuffer_Monsters[1],gUnknown_203B27C->unk20);
            if (gUnknown_203B27C->isNextMoveLinked)
            {
                CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_20],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            }
            else
        {
                CreateDialogueBoxAndPortrait(gCommonGulpin[gUnknown_203B27C->mode][GULPIN_DLG_19],0,gUnknown_203B27C->monPortraitPtr,0x10d);
            }
            break;
    }
}

static void CreateGulpinShopMenu(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinProceed;
    gUnknown_203B27C->unk7C[loopMax].menuAction = PROCEED_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinInfo;
    gUnknown_203B27C->unk7C[loopMax].menuAction = INFO_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gCommonCancel[0];
    gUnknown_203B27C->unk7C[loopMax].menuAction = CANCEL_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = 0x0;
    gUnknown_203B27C->unk7C[loopMax].menuAction = CANCEL_ACTION;
}

static void sub_80205D0(void)
{
    s32 loopMax;
    s32 i;
    loopMax = 0;

    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));

    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3D8;
    gUnknown_203B27C->unk7C[loopMax].menuAction = MOVES_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3E0;
    gUnknown_203B27C->unk7C[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3E8;
    gUnknown_203B27C->unk7C[loopMax].menuAction = CHECK_IQ_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3F4;
    gUnknown_203B27C->unk7C[loopMax].menuAction = REMEMBER_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->menuAction2)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->menuAction2 = gUnknown_203B27C->unk7C[i].menuAction;
            break;
        }
    }
}

static void sub_802069C(void)
{
    s32 loopMax;
    s32 i;
    loopMax = 0;

    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));

    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3F4;
    gUnknown_203B27C->unk7C[loopMax].menuAction = REMEMBER_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gCommonInfo[0];
    gUnknown_203B27C->unk7C[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->menuAction3)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->menuAction3 = gUnknown_203B27C->unk7C[i].menuAction;
            break;
        }
    }
}

static void CreateGulpinLinkMenu(void)
{
    s32 loopMax;
    s32 i;
    loopMax = 0;

    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));

    if(gUnknown_203B27C->isTeamLeader)
    {
        if(IsMoveSet(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinDeselect;
            gUnknown_203B27C->unk7C[loopMax].menuAction = DESELECT_ACTION;
        }
        else
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinSet;
            gUnknown_203B27C->unk7C[loopMax].menuAction = SET_ACTION;
        }
    }
    else
    {
        if(IsMoveEnabled(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinDeselect;
        }
        else
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinSet;
        }
        gUnknown_203B27C->unk7C[loopMax].menuAction = 7;
    }

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinLink;
    gUnknown_203B27C->unk7C[loopMax].menuAction = LINK_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinDelink;
    gUnknown_203B27C->unk7C[loopMax].menuAction = DE_LINK_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinForget;
    gUnknown_203B27C->unk7C[loopMax].menuAction = FORGET_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gCommonInfo[0];
    gUnknown_203B27C->unk7C[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->menuAction4)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->menuAction4 = gUnknown_203B27C->unk7C[i].menuAction;
            break;
        }
    }
}

static void sub_80208B0(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    gUnknown_203B27C->unk7C[loopMax].text = gCommonYes[0];
    gUnknown_203B27C->unk7C[loopMax].menuAction = YES_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gCommonNo[0];
    gUnknown_203B27C->unk7C[loopMax].menuAction = NO_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = CANCEL_ACTION;
}

static void sub_8020900(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    gUnknown_203B27C->unk7C[loopMax].text = gCommonYes[0];
    gUnknown_203B27C->unk7C[loopMax].menuAction = YES_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gCommonNo[0];
    gUnknown_203B27C->unk7C[loopMax].menuAction = NO_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = -1;
}

static void sub_8020950(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));

    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC428;
    gUnknown_203B27C->unk7C[loopMax].menuAction = SETTING_MOVES_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC438;
    gUnknown_203B27C->unk7C[loopMax].menuAction = LINKING_MOVES_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC448;
    gUnknown_203B27C->unk7C[loopMax].menuAction = REMEMBERING_MOVES_ACTION;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = CANCEL_ACTION;
}

static void sub_80209AC(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        gUnknown_203B27C->menuAction1 = menuAction;
        switch(menuAction)
        {
            case PROCEED_ACTION:
                sub_801FDA8(0xe);
                break;
            case INFO_ACTION:
                sub_801FDA8(0x8);
                break;
            case CANCEL_ACTION:
                sub_801FDA8(0xC);
                break;
        }
    }
}

static void sub_80209FC(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case YES_ACTION:
                sub_801FDA8(0xe);
                break;
            case NO_ACTION:
            case CANCEL_ACTION:
                sub_801FDA8(0xC);
                break;
        }
    }
}

static void sub_8020A34(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case SETTING_MOVES_ACTION:
                sub_801FDA8(0x9);
                break;
            case LINKING_MOVES_ACTION:
                sub_801FDA8(10);
                break;
            case REMEMBERING_MOVES_ACTION:
                sub_801FDA8(0xb);
                break;
            case CANCEL_ACTION:
                sub_801FDA8(0x1);
                break;
        }
    }
}

static void sub_8020A80(void)
{
    switch(sub_8023A94(TRUE))
    {
        case 3:
            gUnknown_203B27C->speciesNum = sub_8023B44();
            gUnknown_203B27C->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B27C->speciesNum];
            gUnknown_203B27C->isTeamLeader = gUnknown_203B27C->pokeStruct->isTeamLeader;
            PrintPokeNameToBuffer(gFormatBuffer_Monsters[5], gUnknown_203B27C->pokeStruct);
            sub_801FDA8(0x11);
            break;
        case 4:
            gUnknown_203B27C->speciesNum = sub_8023B44();
            gUnknown_203B27C->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B27C->speciesNum];
            gUnknown_203B27C->isTeamLeader = gUnknown_203B27C->pokeStruct->isTeamLeader;
            PrintPokeNameToBuffer(gFormatBuffer_Monsters[5], gUnknown_203B27C->pokeStruct);
            sub_801FDA8(0x12);
            break;
        case 0:
        case 1:
            break;
        case 2:
            sub_8023C60();
            sub_801FDA8(7);
            break;
    }
}

static void sub_8020B38(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_8023A94(FALSE);
    if (!sub_8012FD8(&gUnknown_203B27C->unkCC)) {
        sub_8013114(&gUnknown_203B27C->unkCC,&menuAction);
        if (menuAction != CANCEL_ACTION) {
            gUnknown_203B27C->menuAction2 = menuAction;
        }
    }

    switch(menuAction)
    {
        case CANCEL_ACTION:
        case NO_ACTION:
            sub_801FDA8(0x10);
            break;
        case REMEMBER_ACTION:
            if(GetBaseSpeciesNoUnown(gUnknown_203B27C->pokeStruct->speciesNum) == MONSTER_DEOXYS_NORMAL)
            {
                sub_801FDA8(0x1C);
            }
            else if(sub_8021178())
            {
                sub_801FDA8(0x1b);
            }
            else
            {
                sub_801FDA8(0x14);
            }
            break;
        case MOVES_ACTION:
            sub_801FDA8(0x1e);
            break;
        case INFO_ACTION:
            sub_801FDA8(0x12);
            break;
        case CHECK_IQ_ACTION:
            sub_801FDA8(0x13);
            break;
    }
}

static void sub_8020C2C(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            sub_801FDA8(0x10);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8020C48(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            CleanIQSkillMenu();
            sub_801FDA8(0x10);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8020C64(void)
{
    switch(sub_801F520(1))
    {
        case 3:
            gUnknown_203B27C->unk1E = gUnknown_203B27C->unk1C = sub_801F5B4();
            sub_801FDA8(0x17);
            break;
        case 4:
            gUnknown_203B27C->unk1E = gUnknown_203B27C->unk1C = sub_801F5B4();
            sub_801FDA8(0x18);
            break;
        case 2:
            sub_801F63C();
            sub_801FDA8(0x10);
            break;
    }
}

static void sub_8020CC0(void)
{
    s32 menuAction;
    s32 index;
    Move *move;

    menuAction = 0;
    sub_801F520(0);
    if (!sub_8012FD8(&gUnknown_203B27C->unkCC)) {
        sub_8013114(&gUnknown_203B27C->unkCC,&menuAction);
        if (menuAction != CANCEL_ACTION) {
            gUnknown_203B27C->menuAction3 = menuAction;
        }
    }

    switch(menuAction)
    {
        case CANCEL_ACTION:
        case NO_ACTION:
            sub_801FDA8(0x16);
            break;
        case REMEMBER_ACTION:
            sub_801F63C();
            unk_CopyMoves4To8(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            for(index = 0; index < MAX_MON_MOVES * 2; index++)
            {
                move = &gUnknown_203B27C->moves[index];
                if(!(move->moveFlags & MOVE_FLAG_EXISTS))
                {
                    InitZeroedPPPokemonMove(move,gUnknown_203B27C->unk1E);
                    break;
                }
            }
            if(index >= MAX_MON_MOVES)
            {
                sub_801FDA8(0x1d);
            }
            else
            {
                sub_801FDA8(0x19);
            }
            break;
        case INFO_ACTION:
            sub_801FDA8(0x18);
            break;
    }
}

static void sub_8020D74(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            sub_801FDA8(0x16);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8020D90(void)
{
    switch(sub_801E8C0())
    {
        case 3:
            gUnknown_203B27C->isNextMoveLinked = GulpinIsNextMoveLinked();
            DestroyGulpinShop();
            sub_801FDA8(0x1A);
            break;
        case 2:
            DestroyGulpinShop();
            sub_801FDA8(0x10);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8020DCC(void)
{
  switch(sub_801EF38(1)) {
      case 3:
        if (sub_801F1A4()) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        gUnknown_203B27C->moveIndex = sub_801F194();
        gUnknown_203B27C->unk1C = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        gUnknown_203B27C->unk20 = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        sub_801FDA8(0x20);
        break;
      case 4:
        if (sub_801F1A4()) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        gUnknown_203B27C->moveIndex = sub_801F194();
        gUnknown_203B27C->unk1C = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        gUnknown_203B27C->unk20 = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        sub_801FDA8(0x21);
        break;
      case 2:
        if (sub_801F1A4()) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        sub_801F214();
        sub_8094060(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
        sub_801FDA8(0x10);
        break;
      case 1:
        if (sub_801F1A4()) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        break;
      case 0:
          break;
  }
}

static void sub_8020EB4(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801EF38(0);
    if (!sub_8012FD8(&gUnknown_203B27C->unkCC)) {
        sub_8013114(&gUnknown_203B27C->unkCC,&menuAction);
        if (menuAction != CANCEL_ACTION) {
            gUnknown_203B27C->menuAction4 = menuAction;
        }
    }

    switch(menuAction)
    {
        case SET_ACTION:
            if(ToggleSetMove(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlaySound(0x133);
                sub_801FDA8(0x1F);
            }
            else
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x1F);
            }
            break;
        case DESELECT_ACTION:
            PlaySound(0x133);
            UnSetMove(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves);
            sub_801FDA8(0x1F);
            break;
        case 7:
            if(ToggleMoveEnabled(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlaySound(0x133);
                asm("");
            }
            else
            {
                PlayMenuSoundEffect(2);
            }
            sub_801FDA8(0x1F);
            break;
        case LINK_ACTION:
            if(gTeamInventoryRef->teamMoney < 150)
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x3);
            }
            else if(!sub_8093318(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x4);
            }
            else
            {
                if(!gUnknown_203B27C->unk15)
                {
                    gUnknown_203B27C->unk15 = TRUE;
                    PlaySound(0x14c);
                }
                else
                {
                    PlaySound(0x133);
                }
                TryLinkMovesAfter(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves);
                sub_801FDA8(0x1F);
            }
            break;
        case DE_LINK_ACTION:
            if(!sub_809333C(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x5);
            }
            else
            {
                PlaySound(0x133);
                UnlinkMovesAfter(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves);
                sub_801FDA8(0x1F);
            }
            break;
        case CANCEL_ACTION:
        case NO_ACTION:
            sub_801FDA8(0x1F);
            break;
        case FORGET_ACTION:
            if(!IsAnyMoveLinked(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x6);
            }
            else
            {
                PlaySound(0x133);
                gUnknown_203B27C->isNextMoveLinked = IsNextMoveLinked(gUnknown_203B27C->moveIndex,gUnknown_203B27C->moves);
                sub_801FDA8(0x22);
            }
            break;
        case INFO_ACTION:
            sub_801FDA8(33);
            break;
        case CHECK_IQ_ACTION ... REMEMBERING_MOVES_ACTION:
            break;
    }
}

static void sub_80210C8(void)
{
    switch (sub_801F890()) {
        case 2:
        case 3:
            sub_801F8D0();
            sub_801FDA8(31);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_80210E4(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case YES_ACTION:
                RemoveLinkSequenceFromMoves8(gUnknown_203B27C->moves, gUnknown_203B27C->moveIndex);
                sub_801FDA8(35);
                break;
            case CANCEL_ACTION:
            case NO_ACTION:
                sub_801FDA8(31);
                break;
        }
    }
}

static void sub_8021130(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sub_801FDA8(gUnknown_203B27C->fallbackState);
}

static void sub_8021154(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 4)
        sub_801FDA8(gUnknown_203B27C->fallbackState);
}

static bool8 sub_8021178(void)
{
    s32 count;
    unkStruct_808E218_arg local;

    count = sub_808E218(&local, gUnknown_203B27C->pokeStruct);
    if (count == 0)
        return TRUE;
    else return FALSE;
}
