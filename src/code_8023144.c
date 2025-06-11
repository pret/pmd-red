#include "global.h"
#include "globaldata.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "code_800D090.h"
#include "music_util.h"
#include "code_8023144.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text_1.h"
#include "text_2.h"

EWRAM_INIT static u32 gUnknown_203B298 = {1};
EWRAM_INIT static u16 gUnknown_203B29C = {0};
EWRAM_INIT static u16 gUnknown_203B29E = {0};
EWRAM_INIT s32 gUnknown_203B2A0 = 2;
EWRAM_INIT s32 gUnknown_203B2A4 = 1;
EWRAM_INIT u16 gUnknown_203B2A8 = 0;
EWRAM_INIT u16 gUnknown_203B2AA = 0;

static IWRAM_INIT unkStruct_3001B5C *gUnknown_3001B5C = {NULL};

#include "data/code_8023144.h"

static void sub_8023420(void);
static void sub_80234BC(void);
static u32 sub_80236A4(void);
static bool8 sub_8023704(u8 unused);
static void sub_8023730(void);
static void sub_8023758(void);
static void sub_80237E0(void);

bool8 sub_8023144(s32 a0, s32 index, DungeonPos *sub, u32 a3)
{
    u8 param_1_u8 = a0;

    if (sub_8023704(param_1_u8))
        return FALSE;

    if (gUnknown_3001B5C == NULL)
        gUnknown_3001B5C = MemoryAlloc(sizeof(unkStruct_3001B5C), 8);

    gUnknown_3001B5C->unk0 = param_1_u8;
    gUnknown_3001B5C->unk4 = gUnknown_203B298;

    gUnknown_3001B5C->s35C.s0.winId = index;
    gUnknown_3001B5C->s35C.s0.unk38 = &gUnknown_3001B5C->s35C.s0.windows.id[index];
    RestoreSavedWindows(&gUnknown_3001B5C->s35C.s0.windows);
    gUnknown_3001B5C->s35C.s0.windows.id[gUnknown_3001B5C->s35C.s0.winId] = sUnknown_80DC91C;

    gUnknown_3001B5C->s35C.s0.unk38->header = &gUnknown_3001B5C->s35C.header;

    if (sub != NULL)
        gUnknown_3001B5C->s35C.s0.windows.id[gUnknown_3001B5C->s35C.s0.winId].pos = *sub;

    sub_8012D08(gUnknown_3001B5C->s35C.s0.unk38, a3);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_3001B5C->s35C.s0.windows, TRUE, TRUE);
    sub_8013818(&gUnknown_3001B5C->s35C.s0.input, sub_80236A4(), a3, index);
    gUnknown_3001B5C->s35C.s0.input.menuIndex = gUnknown_203B29C;
    gUnknown_3001B5C->s35C.s0.input.unk1E = gUnknown_203B29E;
    sub_8013984(&gUnknown_3001B5C->s35C.s0.input);
    sub_8023420();
    sub_80234BC();
    return TRUE;
}

u32 sub_8023278(bool8 a0)
{
    s32 iVar3;
    u32 temp;

    if (!a0) {
        sub_8013660(&gUnknown_3001B5C->s35C.s0.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_3001B5C->s35C.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_SELECT_BUTTON:
            PlayMenuSoundEffect(5);
            if (temp = gUnknown_3001B5C->unk4, iVar3 = 1, temp < 2)
                iVar3 = temp + 1;

            gUnknown_3001B5C->unk4 = iVar3;
            sub_80236A4();
            break;
        default:
            if (sub_80138B8(&gUnknown_3001B5C->s35C.s0.input, 1) == 0)
                return 0;
            break;
    }

    sub_8023420();
    sub_80234BC();
    return 1;
}

s16 sub_802331C(void)
{
    return gUnknown_3001B5C->unkC[(gUnknown_3001B5C->s35C.s0.input.unk1E * gUnknown_3001B5C->s35C.s0.input.unk1C) + gUnknown_3001B5C->s35C.s0.input.menuIndex];
}

void sub_8023354(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_3001B5C->s35C.s0.windows, FALSE, FALSE);
    sub_8013984(&gUnknown_3001B5C->s35C.s0.input);
    sub_8023420();
    sub_80234BC();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_3001B5C->s35C.s0.input);
}

void sub_80233A0(void)
{
    if (gUnknown_3001B5C != NULL) {
        gUnknown_203B298 = gUnknown_3001B5C->unk4;
        gUnknown_203B29C = gUnknown_3001B5C->s35C.s0.input.menuIndex;
        gUnknown_203B29E = gUnknown_3001B5C->s35C.s0.input.unk1E;
        gUnknown_3001B5C->s35C.s0.windows.id[gUnknown_3001B5C->s35C.s0.winId] = sUnknown_80DC904;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_3001B5C->s35C.s0.windows, TRUE, TRUE);
        MemoryFree(gUnknown_3001B5C);
        gUnknown_3001B5C = NULL;
    }
}

static void sub_8023420(void)
{
    gUnknown_3001B5C->s35C.header.count = 1;
    gUnknown_3001B5C->s35C.header.currId = 0;
    gUnknown_3001B5C->s35C.header.width = 12;
    gUnknown_3001B5C->s35C.header.f3 = 0;

    SUB_80095E4_CALL_2(gUnknown_3001B5C->s35C.s0);
}

static void sub_80234BC(void)
{
    u8 cVar2;
    u32 y;
    s32 uVar3;
    s32 iVar4;
    s32 species;
    u32 color;
    s32 i;
    u8 buffer2[256];
    u8 buffer1[100];
    FriendAreaCapacity auStack_2c;

    CallPrepareTextbox_8008C54(gUnknown_3001B5C->s35C.s0.winId);
    sub_80073B8(gUnknown_3001B5C->s35C.s0.winId);
    PrintStringOnWindow(10, 0, sPokemon, gUnknown_3001B5C->s35C.s0.winId, 0);

    sub_8012BC4((gUnknown_3001B5C->s35C.header.width * 8) + 4, 0, gUnknown_3001B5C->s35C.s0.input.unk1E + 1, 2, 7, gUnknown_3001B5C->s35C.s0.winId);

    for (i = 0; i < gUnknown_3001B5C->s35C.s0.input.unk1A; i++) {
        y = GetMenuEntryYCoord(&gUnknown_3001B5C->s35C.s0.input, i);
        species = gUnknown_3001B5C->unkC[(gUnknown_3001B5C->s35C.s0.input.unk1E * gUnknown_3001B5C->s35C.s0.input.unk1C) + i];
        GetFriendAreaCapacity2(GetFriendArea(species), &auStack_2c, FALSE, FALSE);
        color = COLOR_WHITE_2;
        if (auStack_2c.hasFriendArea)
            color = HasRecruitedMon(species) ? COLOR_CYAN : COLOR_GREEN;

        iVar4 = GetDexInternalNo(species, 0);
        cVar2 = (iVar4 % 10) + 48;
        DrawCharOnWindowWidth12(20, y, cVar2, color, gUnknown_3001B5C->s35C.s0.winId);

        if (9 < iVar4) {
            iVar4 /= 10;
            cVar2 = (iVar4 % 10) + 48;
            DrawCharOnWindowWidth12(13, y, cVar2, color, gUnknown_3001B5C->s35C.s0.winId);

            if (9 < iVar4) {
                uVar3 = iVar4 / 10;
                cVar2 = (uVar3 % 10) + 48;
                DrawCharOnWindowWidth12(6, y, cVar2, color, gUnknown_3001B5C->s35C.s0.winId);
            }
        }

        sub_808D930(buffer1,species);
        sprintfStatic(buffer2, sFmtColoredString, color, buffer1);
        PrintStringOnWindow(36, y, buffer2, gUnknown_3001B5C->s35C.s0.winId, 0);
    }

    sub_80073E0(gUnknown_3001B5C->s35C.s0.winId);
}

static u32 sub_80236A4(void)
{
    s32 index;

    gUnknown_3001B5C->unk8 = 0;

    for (index = 0; index < MONSTER_MAX; index++) {
        if (sub_8098134(index) && (s16)index == GetBaseSpeciesNoUnown(index))
            gUnknown_3001B5C->unkC[gUnknown_3001B5C->unk8++] = index;
    }

    sub_8023730();
    return gUnknown_3001B5C->unk8;
}

static bool8 sub_8023704(u8 unused)
{
    s32 index;

    for (index = 0; index < MONSTER_MAX; index++) {
        if (sub_8098134(index))
            return FALSE;
    }

    return TRUE;
}

static void sub_8023730(void)
{
    switch (gUnknown_3001B5C->unk4) {
        case 1:
            sub_8023758();
            break;
        case 2:
            sub_80237E0();
            break;
    }
}

void sub_8023758(void)
{
    s32 temp;
    s32 i, j;
    s16 *r9 = &gUnknown_3001B5C->unkC[gUnknown_3001B5C->unk8 - 1];

    for (i = 0; i < gUnknown_3001B5C->unk8 - 1; i++) {
        s16 *r5 = r9;
        for (j = gUnknown_3001B5C->unk8 - 1; j > i; j--) {
            s16 *r6 = r5 - 1;
            if (GetAlphabetParentNo(*r6, 1) > GetAlphabetParentNo(*r5, 1)) {
                SWAP(*r5, *r6, temp);
            }
            r5--;
        }
    }
}

void sub_80237E0(void)
{
    s32 temp;
    s32 i, j;
    s16 *r9 = &gUnknown_3001B5C->unkC[gUnknown_3001B5C->unk8 - 1];

    for (i = 0; i < gUnknown_3001B5C->unk8 - 1; i++) {
        s16 *r5 = r9;
        for (j = gUnknown_3001B5C->unk8 - 1; j > i; j--) {
            s16 *r6 = r5 - 1;
            if (GetAlphabetParentNo(*r6, 0) > GetAlphabetParentNo(*r5, 0)) {
                SWAP(*r5, *r6, temp);
            }
            r5--;
        }
    }
}
