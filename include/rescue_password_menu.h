#ifndef GUARD_RESCUE_PASSWORD_MENU_H
#define GUARD_RESCUE_PASSWORD_MENU_H

#include "structs/menu.h"
#include "sprite.h"
#include "structs/str_text.h"

// Similar to unkStruct_203B360
struct RescuePasswordMenu
{
    // size: 0x214
    u32 currMenu;
    u32 state;
    MenuStruct unk8[4];
    WindowTemplates unk148;
    WindowTemplates unk1A8;
    SpriteOAM unk208;
    u32 unk210;
};


#define PASSWORD_ENTRY_DUPLICATE_SOS_MAIL 0x7
#define PASSWORD_ENTRY_DUPLICATE_AOK_MAIL 0x9
#define PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL 0xB

#define PASSWORD_ENTRY_NO_SPACE 0xD

#define PASSWORD_ENTRY_INCORRECT_PASSWORD 0x11

#define PASSWORD_ENTRY_NOT_SOS_MAIL 0x12
#define PASSWORD_ENTRY_NOT_AOK_MAIL 0x13
#define PASSWORD_ENTRY_NOT_THANK_YOU_MAIL 0x14
#define PASSWORD_ENTRY_NOT_WONDER_MAIL 0x15

#define PASSWORD_ENTRY_SOS_MAIL_SUCCESS 0x16
#define PASSWORD_ENTRY_AOK_MAIL_SUCCESS 0x17
#define PASSWORD_ENTRY_THANK_YOU_MAIL_SUCCESS 0x18

#define PASSWORD_ENTRY_SOS_MAIL_MODE 0x1C
#define PASSWORD_ENTRY_AOK_MAIL_MODE 0x1E
#define PASSWORD_ENTRY_THANK_YOU_MAIL_MODE 0x20


void CreateRescuePasswordMenu(u32 currMenu);
s32 UpdateRescuePasswordMenu(void);
void CleanRescuePasswordMenu(void);

#endif
