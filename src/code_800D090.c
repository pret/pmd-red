#include "global.h"

extern void SoundBiasReset(void);
extern void SoundBiasSet(void);

void Hang(void)
{
    while(1)
    {
        asm("swi 0x2");
    }
}


// Unused
void sub_800D098(void)
{
    u32 dispcnt_save;
    u32 ie_store;

    while(REG_VCOUNT <= 159)
        ;

    // Save DISPCNT and set to 0
    dispcnt_save = REG_DISPCNT;
    REG_DISPCNT = 0;

    *(u16 *)BG_PLTT = 0xefff;

    while(REG_KEYINPUT != 0x3ff) // 0011 1111 1111 (all buttons)
        ;


    REG_IME = 0;

    // Save IE Register
    ie_store = REG_IE;
    REG_IE = INTR_FLAG_KEYPAD | INTR_FLAG_GAMEPAK;

    REG_KEYCNT = 0xC304; // TODO 1100 0011 0000 0100
    // Select:
    // * Select button
    // * L/R Button
    // Enable IRQ
    // Logical AND
    // So do something when all buttons above are pressed

    REG_IME = 1;

    SoundBiasReset();
    asm("swi 0x3");
    SoundBiasSet();

    REG_IME = 0;

    REG_IE = ie_store; // restore IE
    REG_KEYCNT = 0; // reset KEYCNT

    REG_IME = 1;

    // Good after here
    while(REG_VCOUNT <= 159){}
    REG_DISPCNT = dispcnt_save; // restore DISPCNT
    while(REG_KEYINPUT != 0x3ff){} // All buttons
}
