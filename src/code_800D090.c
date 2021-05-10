#include <stdarg.h>
#include <stdio.h>
#include "gba/gba.h"
#include "config.h"
#include "global.h"


extern void SoundBiasReset(void);
extern void SoundBiasSet(void);

struct unkStruct_202DB60
{
    u32 unk0;
    u32 unk4;
};

extern struct unkStruct_202DB60 gUnknown_202DB60;

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

    while(REG_VCOUNT < 160)
        ;

    // Save DISPCNT and set to 0
    dispcnt_save = REG_DISPCNT;
    REG_DISPCNT = 0;

    *(u16 *)BG_PLTT = 0xefff;

    while(REG_KEYINPUT != KEYS_MASK)
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

    while(REG_VCOUNT < 160){}
    REG_DISPCNT = dispcnt_save; // restore DISPCNT
    while(REG_KEYINPUT != KEYS_MASK){} // All buttons
}

void sub_800D158(u8 *buffer, const char *text, ...)
{
    va_list vArgv;
    va_start(vArgv, text);
    vsprintf(buffer, text, vArgv);
    va_end(vArgv);
}

// Unused
void sub_800D16C(const char *text, ...)
{
    char buffer[1024];
    va_list vArgv;
    va_start(vArgv, text);
    vsprintf(buffer, text, vArgv);
    va_end(vArgv);
}

// Unused
void sub_800D10A(const char *r0, u32 r1, u32 r2, u32 r3, ...)
{
}

void nullsub_183(void)
{
}

void nullsub_188(void)
{
}

void nullsub_184(void)
{
}

u32 sub_800D1B4(void)
{
    return 0;
}

u32 sub_800D1B8(u32 r0, u32 r1, u32 r2)
{
    return r2;
}

void nullsub_187(void)
{
}

u32 sub_800D1C0(void)
{
    if(gUnknown_202DB60.unk0 != 2)
        return 0;
    if(gUnknown_202DB60.unk4 != 2)
        return 0;
    return 1;
}
