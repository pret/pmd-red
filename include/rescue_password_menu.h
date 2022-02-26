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
    u8 fill8[0x148 - 8];
    struct UnkTextStruct2 unk148[4];
    u8 fill1A8[0x208 - 0x1A8];

    struct unkSprite unk208;

    u32 unk210;
};

void CreateRescuePasswordMenu(u32 currMenu);
s32 UpdateRescuePasswordMenu(void);
void CleanRescuePasswordMenu(void);

#endif
