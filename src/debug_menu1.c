#include "global.h"
#include "code_8097670.h"
#include "constants/friend_area.h"
#include "constants/main_menu.h"
#include "debug_menu1.h"
#include "friend_area.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "save.h"
#include "text_util.h"
#include "text1.h"

enum DebugMenuOptions
{
    MENU_DEBUG_MENU_DUNGEONS,
    MENU_DEBUG_MENU_FIELD,
    MENU_DEBUG_MENU_FIELD_MAP,
    MENU_DEBUG_MENU_FIELD_SCRIPT,
    MENU_DEBUG_MENU_DEBUG_MENU,
    MENU_DEBUG_MENU_UNKNOWN_1,
    MENU_DEBUG_MENU_STORAGE,
    //
    MENU_DEBUG_MENU_H_OPEN = 9,
};

static EWRAM_DATA_2 struct DebugMenu *sDebugMenu = {0};

#include "data/debug_menu1.h"

static void SetDebugMenuItems(void);

static void sub_803A3A0(void);
static void sub_803A3BC(void);

void CreateDebugMenu(void)
{
    s32 i;

    if (sDebugMenu == NULL) {
        sDebugMenu = MemoryAlloc(sizeof(struct DebugMenu), 8);
        MemoryFill8((u8 *)sDebugMenu, 0, sizeof(struct DebugMenu));
    }

    for (i = 0; i < 4; i++)
        sDebugMenu->unk140[i] = sUnknown_80E7D40;

    ResetUnusedInputStruct();
    sub_800641C(sDebugMenu->unk140, TRUE, TRUE);
    SetDebugMenuItems();
}

void DeleteDebugMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);
    if (sDebugMenu != NULL) {
        MemoryFree(sDebugMenu);
        sDebugMenu = NULL;
    }
}

u32 UpdateDebugMenu(void)
{
    u32 nextMenu;
    s32 counter;
    s32 debugMenuAction;

    nextMenu = MENU_NO_SCREEN_CHANGE;
    debugMenuAction = 11;

    if (sub_8012FD8(&sDebugMenu->unk0[0]) == 0)
        sub_8013114(&sDebugMenu->unk0[0], &debugMenuAction);

    switch (debugMenuAction) {
        case MENU_DEBUG_MENU_DUNGEONS:
            nextMenu = MENU_DEBUG_DUNGEON;
            break;
        case MENU_DEBUG_MENU_FIELD:
            nextMenu = MENU_DEBUG_FIELD;
            break;
        case MENU_DEBUG_MENU_FIELD_MAP:
            nextMenu = MENU_DEBUG_FIELD_MAP;
            break;
        case MENU_DEBUG_MENU_FIELD_SCRIPT:
            nextMenu = MENU_DEBUG_FIELD_SCRIPT;
            break;
        case MENU_DEBUG_MENU_DEBUG_MENU:
            nextMenu = MENU_DEBUG_DEBUG_MENU;
            break;
        case MENU_DEBUG_MENU_UNKNOWN_1: // No option that correponds to this one
            nextMenu = MENU_DEBUG_UNKNOWN_1;
            break;
        case MENU_DEBUG_MENU_STORAGE:
            sub_803A3BC();
            nextMenu = MENU_MAIN_SCREEN;
            break;
        case MENU_DEBUG_MENU_H_OPEN:
            for (counter = 0; counter < 0x20; counter++)
                sub_80976F8(counter);

            nextMenu = MENU_MAIN_SCREEN;
            break;
        case 10:
            sub_803A3A0();
            nextMenu = MENU_MAIN_SCREEN;
            break;
        case 11:
            nextMenu = MENU_NO_SCREEN_CHANGE;
            break;
    }
    return nextMenu;
}

static void SetDebugMenuItems(void)
{
    SetMenuItems(sDebugMenu->unk0, sDebugMenu->unk140, 0, &sUnknown_80E7D58, sDebugMenuItems, TRUE, 13, FALSE);
    sub_8035CF4(sDebugMenu->unk0, 0, 1);
}

static void sub_803A3A0(void)
{
    sub_8035CC0(sDebugMenu->unk140, 0);
}

static void sub_803A3BC(void)
{
    s32 speciesIndex;
    u8 sp_0x8[88];
    u16 r7 [4]; // r7
    u8 buffer[20]; // r6
    u32 sp_0x7C;
    s32 sp_0x80;

    #ifndef NONMATCHING
    register s32 index asm("r5");
    register u32 r9 asm("r9");
    #else
    s32 index;
    u32 r9;
    #endif

    index = 1;
    do {
        UnlockFriendArea(index);
        index++;
    } while (index < NUM_FRIEND_AREAS);

    index = 0;
    do {
        r9 = 0;
        sp_0x7C = 0x1006;
        index++;
        speciesIndex = index * 0x10000 >> 0x10; // TODO: dumb way to force s16. Temp var may fix the regswap
        memset(r7, 0, 8);
        r7[0] = 0x27;
        CopyMonsterNametoBuffer(buffer, speciesIndex);
        CopyStringtoBuffer(buffer, buffer);
        buffer[0] = 0x40;
        sub_808CFD0(sp_0x8, speciesIndex, buffer, 0x43, &sp_0x7C, r7);
        sub_808D1DC(sp_0x8);
    } while (index < 300);

    sp_0x80 = r9;
    WriteSavetoPak(&sp_0x80, 1);
}