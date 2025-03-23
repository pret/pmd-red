#include "global.h"
#include "music.h"

extern u32 gUnknown_202DB60[2];
extern u16 gUnknown_202DB30[2][8];

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

// arm9.bin::02007FF8
void sprintfStatic(char *buffer, const char *text, ...)
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
    if(gUnknown_202DB60[0] != 2)
        return 0;
    if(gUnknown_202DB60[1] != 2)
        return 0;
    return 1;
}

void sub_800D1E0(void)
{
    s32 iVar1;
    u32 iVar2;
    for(iVar1 = 0; iVar1 < 2; iVar1++)
    {
        for(iVar2 = 0; iVar2 < 8; iVar2++)
        {
            if(gUnknown_202DB30[iVar1][iVar2] == 0xfdfd)
            {
                gUnknown_202DB60[iVar1] = 1;
            }
        }
    }
}
