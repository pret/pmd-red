#ifndef GUARD_DEBUG_MENU_H
#define GUARD_DEBUG_MENU_H

#include "text.h"
#include "menu.h"

enum DebugMenuOptions
{
    MENU_DEBUG_MENU_DUNGEONS = 0,
    MENU_DEBUG_MENU_FIELD,
    MENU_DEBUG_MENU_FIELD_MAP,
    MENU_DEBUG_MENU_FIELD_SCRIPT,
    MENU_DEBUG_MENU_DEBUG_MENU,
    MENU_DEBUG_MENU_UNKNOWN_1,
    MENU_DEBUG_MENU_STORAGE,
    MENU_DEBUG_MENU_H_OPEN = 9,
};

struct DebugMenu
{
    // size: 0x1A4
    struct MenuStruct unk0[4];
    /* 0x140 */ struct UnkTextStruct2 unk140[4];
    u32 fill1A0;
};


struct unkStruct_203B3F8
{
    // size: 0x140
    u32 state;
    s16 unk4;
    u16 unk6;
    struct PokemonStruct *pokemon;
    u32 unkC;
    struct MenuStruct unk10;
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    struct UnkTextStruct2 *unk78;
    u32 unk7C;
    u32 unk80;
    u8 fill84[0x90 - 0x84];
    struct MenuItem unk90[8];
    u16 unkD0[8];
    struct UnkTextStruct2 unkE0[4];
};


void CreateDebugMenu(void);
void DeleteDebugMenu(void);
u32 UpdateDebugMenu(void);
void SetDebugMenuItems(void);
void sub_803A3A0(void);

#endif
