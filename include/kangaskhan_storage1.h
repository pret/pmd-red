#ifndef GUARD_KANGASKHAN_STORAGE1_H
#define GUARD_KANGASKHAN_STORAGE1_H

#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_items.h"
#include "structs/str_text.h"

enum KangaskhanStorageStates
{
    KANGASKHAN_STORAGE_INIT,
    KANGASKHAN_STORAGE_MAIN_MENU,
    // 2 - 3
    KANGASKHAN_STORAGE_EXIT = 4,
    KANGASKHAN_STORAGE_NO_INV_ITEMS,
    KANGASKHAN_STORAGE_TOO_MANY_ITEMS,
    // 7 - 8
    KANGASKHAN_STORAGE_IS_MONEY_USED_TM = 9,
};

enum KangaskhanStorageMenuActions
{
    MENU_CANCEL = 1,
    MENU_STORE = 2,
    MENU_TAKE = 3,
    MENU_YES = 4,
    MENU_NO = 5,
    MENU_INFO = 6,

};

// size: 0x14C
struct KangaskhanStorageWork
{
    /* 0x0 */ u32 mode; // Corresponds to the enum: KangaskhanStorageMode
    /* 0x4 */ u32 currState;
    /* 0x8 */ u32 fallbackState;
    /* 0xC */ Item storedItem;
    /* 0x10 */ u32 itemIndex;
    /* 0x14 */ u8 id; // another id?
    /* 0x18 */ u32 menuAction1;
    /* 0x1C */ u32 menuAction2;
    /* 0x20 */ u32 menuAction3;
    MenuItem unk24[5];
    u16 unk4C[5];
    MenuStruct unk58;
    unkStructFor8013AA0 unkA8;
    /* 0xD8 */ struct MonPortraitMsg monPortrait;
    struct MonPortraitMsg *monPortraitPtr;
    WindowTemplates unkEC;
};

bool8 CreateKangaskhanStorage(u32 mode);
void DeleteKangaskhanStorage(void);
u32 KangaskhanStorageCallback(void);

#endif // GUARD_KANGASKHAN_STORAGE1_H
