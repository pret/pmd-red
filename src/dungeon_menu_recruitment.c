#include "global.h"
#include "globaldata.h"
#include "dungeon_menu_recruitment.h"
#include "dungeon.h"
#include "text.h"
#include "menu_input.h"
#include "input.h"
#include "dungeon_message.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "sprite.h"
#include "exclusive_pokemon.h"

extern void PlayDungeonStartButtonSE(void);
extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);
extern void PlayDungeonCursorSE(u8 param_1);
extern void sub_803EAF0(u32, u8 *);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern void DungeonRunFrameActions(u32 a0);
extern void DungeonShowWindows(const WindowTemplates *a0, bool8 a1);
extern void AddActionToDungeonSubMenu(u16 actionId, u8 param_2);
extern u16 GetLeaderActionId(void);
extern u32 sub_8014140(s32 a0, const void *a1);
extern void sprintfStatic(char *buffer, const char *text, ...);
extern u8 sub_806F9BC(s32);
extern bool8 sub_80860A8(u8 id);
extern bool8 sub_806A564(s32 r0);

extern MenuInputStruct gDungeonMenu;
extern s32 gDungeonFramesCounter;

struct MonRecruitList
{
    s16 speciesIds[MONSTER_MAX];
    u8 monColor[MONSTER_MAX];
    s32 count;
};

static void PrintAvailableMons(struct MonRecruitList *tabData, s32 tabId);
static bool8 TryScrollUp(struct MonRecruitList *tabData, s32 a1);
static bool8 TryScrollDown(struct MonRecruitList *tabData, s32 a1);
static void CreateScrollingArrow(bool8 upArrow, s32 y);
static void SetRecruitableMons(struct MonRecruitList *tabsData);

extern const u8 *const gUnknown_80FA61C;
extern const u8 *const gUnknown_80FA5F4;
extern const u8 *const gUnknown_80FEA68;
extern const u8 *const gUnknown_80FEA80;
extern const u8 *const gUnknown_80FEA8C;

EWRAM_DATA static s32 sScrollId = 0;
EWRAM_DATA static u8 sScrollFlags = 0;
EWRAM_DATA static SpriteOAM sScrollingArrowOAM = {0};
EWRAM_INIT static WindowHeader sRecruitmentWindowHeader = {2, 0, 13, 0};

enum {
    TAB_POTENTIAL_RECRUITS,
    TAB_RECRUITED_MONS,
    TABS_COUNT
};


static const WindowTemplates sRecruitmentSearchWindows = {
    .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 14,
                .unk10 = 18,
                .unk12 = 2,
                .header = &sRecruitmentWindowHeader,
            },
            [1] = WINDOW_DUMMY,
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
};

static const u8 gUnknown_8106D68[] = {1, 0, 56, 0, 0, 0, 24, 0, 24, 0, 0, 0, 2, 0, 56, 0, 104, 0, 24, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void ShowRecruitmentSearchMenu(void)
{
    s32 currTabId = 0;

    if (!IsRecruitingEnabled(gDungeon->unk644.dungeonLocation.id)) {
        DisplayDungeonMessage(NULL, gUnknown_80FA5F4, TRUE);
    }
    else if (gDungeon->unk644.unk19) {
        DisplayDungeonMessage(NULL, gUnknown_80FA61C, TRUE);
    }
    else {
        struct MonRecruitList tabsData[2];

        SetRecruitableMons(tabsData);
        while (1) {
            bool8 closeWindow = FALSE;
            struct MonRecruitList *currTabData = &tabsData[currTabId];

            sRecruitmentWindowHeader.currId = currTabId;
            DungeonShowWindows(&sRecruitmentSearchWindows, TRUE);
            gDungeonMenu.unk1A = 0;
            gDungeonMenu.menuIndex = 0;
            gDungeonMenu.unk1C = 0;
            gDungeonMenu.unk1E = currTabId;
            gDungeonMenu.unk20 = 2;
            gDungeonMenu.unk4 = 0;
            gDungeonMenu.firstEntryY = 16;
            gDungeonMenu.unk14.x = 0;
            gDungeonMenu.unk0 = 0;
            sub_801317C(&gDungeonMenu.unk28);
            sScrollId = 0;
            sScrollFlags = 0;
            PrintAvailableMons(currTabData, currTabId);
            gDungeonMenu.unkC = (gWindows[0].x + 16) * 8;
            gDungeonMenu.unkE = ((gWindows[0].y + 1) * 8) - 2;

            while (1) {
                s32 unkVar;
                bool8 scroll = FALSE;

                sScrollFlags = 0;
                unkVar = sub_8014140(0, gUnknown_8106D68);
                if (TryScrollUp(currTabData, unkVar)) {
                    scroll = TRUE;
                }
                if (TryScrollDown(currTabData, unkVar)) {
                    scroll = TRUE;
                }

                if (!scroll) {
                    AddMenuCursorSprite(&gDungeonMenu);
                    DungeonRunFrameActions(0x45);
                }

                if (sScrollFlags & FLAG_CAN_SCROLL_UP) {
                    CreateScrollingArrow(TRUE, 8);
                }
                if (sScrollFlags & FLAG_CAN_SCROLL_DOWN) {
                    CreateScrollingArrow(FALSE, 0x70);
                }

                if ((gRealInputs.pressed & (DPAD_LEFT | DPAD_RIGHT)) || gDungeonMenu.unk28.dpad_left || gDungeonMenu.unk28.dpad_right) {
                    PlayDungeonCursorSE(FALSE);
                    currTabId = (currTabId == 0) ? 1 : 0;
                    break;
                }

                if (sub_80048C8())
                    continue;
                if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                    PlayDungeonCancelSE();
                    closeWindow = TRUE;
                    break;
                }
                if ((gRealInputs.pressed & (SELECT_BUTTON | START_BUTTON))) {
                    PlayDungeonConfirmationSE();
                    closeWindow = TRUE;
                    break;
                }
            }

            if (closeWindow)
                break;
        }

        sub_803EAF0(0, NULL);
    }
}

static void PrintAvailableMons(struct MonRecruitList *tabData, s32 tabId)
{
    u8 text[64];
    s32 i;
    s32 menuMonId = sScrollId;
    s32 y = 32;

    sub_80073B8(0);
    if (tabId == TAB_POTENTIAL_RECRUITS) {
        PrintStringOnWindow(12, 0, gUnknown_80FEA68, 0, '\0');
    }
    else {
        PrintStringOnWindow(20, 0, gUnknown_80FEA80, 0, '\0');
    }

    if (tabData->count != 0) {
        for (i = 0; i < 8; i++, menuMonId++, y += 12) {
            if (menuMonId >= 0 && menuMonId < tabData->count) {
                sprintfStatic(text, _("{color}%d{POKEMON_0}"), tabData->monColor[menuMonId]);
                sub_808D930(gFormatBuffer_Monsters[0], tabData->speciesIds[menuMonId]);
                PrintFormattedStringOnWindow(8, y, text, 0, '\0');
            }
        }
    }
    else {
        PrintStringOnWindow(8, y, gUnknown_80FEA8C, 0, '\0');
    }
    sub_80073E0(0);
}

static bool8 TryScrollUp(struct MonRecruitList *tabData, s32 a1)
{
    s32 i;
    u8 text[64];
    s32 menuMonId = sScrollId;
    if (menuMonId == 0)
        return FALSE;

    menuMonId--;
    sScrollFlags |= FLAG_CAN_SCROLL_UP;
    if (!(gRealInputs.repeated & DPAD_UP) && a1 != 1) {
        return FALSE;
    }
    else {
        PlayDungeonCursorSE(FALSE);
        sub_80073B8(0);
        sub_80087EC(0, 0, 16, 144, 16);
        sprintfStatic(text, _("{color}%d{POKEMON_0}"), tabData->monColor[menuMonId]);
        sub_808D930(gFormatBuffer_Monsters[0], tabData->speciesIds[menuMonId]);
        PrintFormattedStringOnWindow(8, 20, text, 0, '\0');
        sub_80073E0(0);
        DungeonRunFrameActions(0x45);
        for (i = 0; i < 6; i++) {
            ScrollUpWindowFunc(0);
            DungeonRunFrameActions(0x45);
        }
        sScrollId--;
        return TRUE;
    }
}

static bool8 TryScrollDown(struct MonRecruitList *tabData, s32 a1)
{
    s32 i;
    u8 text[64];
    s32 menuMonId = sScrollId + 8;
    s32 y = 128;
    if (tabData->count <= menuMonId)
        return FALSE;

    sScrollFlags |= FLAG_CAN_SCROLL_DOWN;
    if (!(gRealInputs.repeated & DPAD_DOWN) && a1 != 2) {
        return FALSE;
    }
    else {
        PlayDungeonCursorSE(FALSE);
        sub_80073B8(0);
        sub_80087EC(0, 0, y, 72, 16);
        sprintfStatic(text, _("{color}%d{POKEMON_0}"), tabData->monColor[menuMonId]);
        sub_808D930(gFormatBuffer_Monsters[0], tabData->speciesIds[menuMonId]);
        PrintFormattedStringOnWindow(8, y, text, 0, '\0');
        sub_80073E0(0);
        DungeonRunFrameActions(13);
        for (i = 0; i < 6; i++) {
            ScrollDownWindowFunc(0);
            DungeonRunFrameActions(13);
        }
        sScrollId++;
        return TRUE;
    }
}

// Almost identical to CreateMessageLogArrow
static void CreateScrollingArrow(bool8 upArrow, s32 y)
{
    struct Window *window = &gWindows[0];
    if (!(gDungeonFramesCounter & 8)) {
        SpriteSetAffine1(&sScrollingArrowOAM, 0);
        SpriteSetAffine2(&sScrollingArrowOAM, 0);
        SpriteSetObjMode(&sScrollingArrowOAM, 0);
        SpriteSetMosaic(&sScrollingArrowOAM, 0);
        SpriteSetBpp(&sScrollingArrowOAM, 0);
        SpriteSetMatrixNum(&sScrollingArrowOAM, (upArrow != FALSE) ? (16) : 0);
        SpriteSetPalNum(&sScrollingArrowOAM, 15);
        SpriteSetY(&sScrollingArrowOAM, (window->y * 8) + y);
        SpriteSetX(&sScrollingArrowOAM, (window->x * 8) + 64);
        SpriteSetShape(&sScrollingArrowOAM, 1);
        SpriteSetSize(&sScrollingArrowOAM, 0);
        SpriteSetPriority(&sScrollingArrowOAM, 0);
        SpriteSetPalNum(&sScrollingArrowOAM, 15);
        SpriteSetTileNum(&sScrollingArrowOAM, 0x3f0);

        AddSprite(&sScrollingArrowOAM, 127, NULL, NULL);
    }
}

static void SetRecruitableMons(struct MonRecruitList *tabsData)
{
    s32 i, id, dummy;
    u8 spArray[MONSTER_MAX];

    for (i = 0; i < MONSTER_MAX; i++) {
        spArray[i] = 0;
    }

    for (id = 0; id < gDungeon->unk37E4; id++) {
        u8 byte = 1;
        s32 val1 = gDungeon->unk343C[id].unk2[0];
        s32 val2 = gDungeon->unk343C[id].unk2[1];
        if (val1 == 0) {
            if (val2 == 0)
                continue;
            byte = 2;
        }
        spArray[ExtractSpeciesIndex(&gDungeon->unk343C[id])] = byte;
    }

    if (gDungeon->unk644.unk2A) {
        spArray[MONSTER_KECLEON] = 1;
    }

    // ???
    for (dummy = 0; dummy < 6; dummy++) {;}

    for (i = 0; i < TABS_COUNT; i++) {
        s32 count = 0;
        s32 j;
        // Line below is only to trick compiler into generating matching stack pattern.
        dummy = tabsData[i].count;
        for (j = 1; j < MONSTER_MUNCHLAX; j++) {
            s32 k;
            s32 speciesId = (s16) j;
            s32 monNameColor = 7;
            bool8 monIsRecruited = FALSE;


            if (spArray[speciesId] == 0)
                continue;

            if (i == TAB_POTENTIAL_RECRUITS) {
                u32 recruitRate, unrecruitableRate;
                if (!sub_806F9BC(speciesId))
                    continue;
                if (!IsExclusivePokemonUnlocked(speciesId))
                    continue;
                // Weird casting needed to match...
                recruitRate = (u16) GetRecruitRate(speciesId);
                unrecruitableRate = (u16) -999;
                if (recruitRate == unrecruitableRate)
                    continue;
                if (speciesId == MONSTER_MEW && !sub_80860A8(122))
                    continue;
            }
            else {
                for (k = 0; k < NUM_MONSTERS; k++) {
                    if (PokemonFlag1(&gRecruitedPokemonRef->pokemon[k]) && gRecruitedPokemonRef->pokemon[k].speciesNum == speciesId)
                        break;
                }
                if (k != NUM_MONSTERS) {
                    monIsRecruited = TRUE;
                }

                if (!monIsRecruited) {
                    for (k = 0; k < 4; k++) {
                        PokemonStruct2 *mon = &gRecruitedPokemonRef->pokemon2[k];
                        if (PokemonFlag1Struct2(mon) && !sub_806A564(mon->unkA) && mon->speciesNum == speciesId)
                            break;
                    }
                    if (k != 4) {
                        monIsRecruited = TRUE;
                        monNameColor = 6;
                    }
                }
            }

            if (i == TAB_POTENTIAL_RECRUITS) {
                if (spArray[speciesId] == 2) {
                    monNameColor = 2;
                }
                tabsData[TAB_POTENTIAL_RECRUITS].speciesIds[count] = speciesId;
                tabsData[TAB_POTENTIAL_RECRUITS].monColor[count] = monNameColor;
                count++;
            }
            else if (monIsRecruited) {
                tabsData[i].speciesIds[count] = speciesId;
                tabsData[i].monColor[count] = monNameColor;
                count++;
            }
        }
        tabsData[i].count = count;
    }
}
