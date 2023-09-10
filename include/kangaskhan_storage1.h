#ifndef GUARD_KANGASKHAN_STORAGE1_H
#define GUARD_KANGASKHAN_STORAGE1_H

#include "file_system.h"
#include "items.h"
#include "menu.h"
#include "text.h"

enum KangaskhanStorageStates
{
    KANGASKHAN_STORAGE_INIT = 0,
    KANGASKHAN_STORAGE_MAIN_MENU = 1,
    KANGASKHAN_STORAGE_EXIT = 4,
    KANGASKHAN_STORAGE_NO_INV_ITEMS = 5,
    KANGASKHAN_STORAGE_TOO_MANY_ITEMS = 6,
    KANGASKHAN_STORAGE_IS_MONEY_USED_TM = 9,
};

// size: 0x14C
struct KangaskhanStorageWork
{
    /* 0x0 */ bool32 isAsleep;
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
    u32 unkA8;
    u32 unkAC;
    u32 unkB0;
    u32 unkB4;
    u32 unkB8;
    u32 unkBC;
    UnkTextStruct2 *unkC0;
    u32 unkC4;
    u32 unkC8;
    u8 unkCC[0xD4 - 0xCC];
    u32 unkD4;
    /* 0xD8 */ OpenedFile *faceFile;
    /* 0xDC */ u8 *faceData;
    u16 unkE0;
    u16 unkE2;
    u8 unkE4;
    u8 unkE5;
    u8 unkE6;
    u8 unkE7;
    OpenedFile **unkE8;
    UnkTextStruct2 unkEC[4];
};

bool8 CreateKangaskhanStorage(u32 mode);
void DeleteKangaskhanStorage(void);
u32 KangaskhanStorageCallback(void);

#endif // GUARD_KANGASKHAN_STORAGE1_H