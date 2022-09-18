#ifndef GUARD_RESCUE_PASSWORD_MENU_H
#define GUARD_RESCUE_PASSWORD_MENU_H

struct unkSprite
{
    u16 unk208;
    u16 unk20A;
    u16 unk20C;
    u16 unk20E;
};

struct RescuePasswordMenu
{
    // size: 0x214
    u32 currMenu;
    u32 state;
    u32 unk8;
    u8 fillC[0x148 - 0xC];
    struct UnkTextStruct2 unk148[4];
    struct UnkTextStruct2 unk1A8[4];

    struct unkSprite unk208;

    u32 unk210;
};


#define PASSWORD_ENTRY_DUPLICATE_SOS_MAIL 0x7
#define PASSWORD_ENTRY_DUPLICATE_AOK_MAIL 0x9
#define PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL 0xB

#define PASSWORD_ENTRY_INCORRECT_PASSWORD 0x11

#define PASSWORD_ENTRY_NOT_SOS_MAIL 0x12
#define PASSWORD_ENTRY_NOT_AOK_MAIL 0x13
#define PASSWORD_ENTRY_NOT_THANK_YOU_MAIL 0x14

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
