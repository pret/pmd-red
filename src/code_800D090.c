#include "global.h"
#include "music.h"
#include "memory.h"
#include "cpu.h"

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

bool8 sub_800D1C0(u32 unused)
{
    if(gUnknown_202DB60[0] != 2)
        return FALSE;
    if(gUnknown_202DB60[1] != 2)
        return FALSE;
    return TRUE;
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

extern u32 gUnknown_202DB58[2];
extern u32 gUnknown_202DB74;
extern u32 gUnknown_202DB50;
extern u16 gUnknown_202DB208[];
extern u16 gUnknown_202D808[132];
extern u16 gUnknown_202D910[2][132];
extern u16 gUnknown_202DB30[2][8];
extern u16 gUnknown_202DB20[8];

void sub_800D224(s32 a0)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        if (((a0 >> i) & 1) && gUnknown_202DB60[i] == 1) {
            u32 j;
            u16 *ptr = gUnknown_202D910[i];

            for (j = 0; j < 8; j++) {
                if (gUnknown_202DB58[i] + j >= gUnknown_202DB74 / 2) {
                    gUnknown_202DB60[i] = 2;
                    break;
                }
                ptr[gUnknown_202DB58[i] + j] = gUnknown_202DB30[i][j];
            }

            gUnknown_202DB58[i] += 8;
        }
    }
}

void sub_800D2EC(u32 unused)
{
    u32 i;
    u16 *ptr = gUnknown_202D808;

    for (i = 0; i < 8; i++) {
        if (gUnknown_202DB50 < (gUnknown_202DB74 / 2)) {
            gUnknown_202DB20[i] = ptr[gUnknown_202DB50++];
        }
        else {
            gUnknown_202DB20[i] = 0xFCFC;
        }
    }
}

extern u32 gUnknown_202DB68;
extern s32 gUnknown_202DB6C;
extern u8 gUnknown_202DB70;

u32 sub_800D820(u16 *a0, u16 *a1);

s32 sub_800D33C(void)
{
    s32 ret = 0;

    gUnknown_202DB6C = gUnknown_202DB68;
    gUnknown_202DB68 = sub_800D820(gUnknown_202DB20, gUnknown_202DB30[0]);
    if (gUnknown_202DB70 == 0) {
        if (gUnknown_202DB68 & 0x100) {
            gUnknown_202DB70 = 1;
        }
        return 0;
    }
    else if (gUnknown_202DB68 & 0x1000) {
        return 3;
    }
    else if (gUnknown_202DB68 & 0x2000) {
        return 4;
    }
    else if (gUnknown_202DB68 & 0x8000) {
        u32 bits1, bits2;

        bits1 = gUnknown_202DB68 << 28;
        bits1 >>= 28;

        bits2 = gUnknown_202DB68 << 20;
        bits2 >>= 28;
        if (bits1 != bits2)
            return 5;
    }

    if (((gUnknown_202DB68 | gUnknown_202DB6C) & 0xE)) {
        u32 si0Cnt = (*(vu32 *)REG_ADDR_SIOCNT);
        si0Cnt <<= 26;
        si0Cnt >>= 30;
        if ((gUnknown_202DB68 & (1 << si0Cnt))) {
            sub_800D1E0();
            sub_800D224(gUnknown_202DB68);
            if (sub_800D1C0(gUnknown_202DB68)) {
                return 2;
            }
            sub_800D2EC(gUnknown_202DB68);
            ret = 1;
        }
    }

    return ret;
}

void sub_800D6AC(void);
void sub_800D7D0(void);
void sub_800D7B8(void);

static inline void ClearUnkMemory(void)
{
    gUnknown_202DB68 = 0;
    gUnknown_202DB6C = 0;
    gUnknown_202DB70 = 0;
    gUnknown_202DB74 = 0;
    gUnknown_202DB60[0] = 0;
    gUnknown_202DB60[1] = 0;
    MemoryClear16(gUnknown_202DB20, sizeof(gUnknown_202DB20));
    MemoryClear16(gUnknown_202DB30[0], sizeof(gUnknown_202DB30));
    gUnknown_202DB50 = 0;
    gUnknown_202DB58[0] = 0;
    gUnknown_202DB58[1] = 0;
    MemoryClear16(gUnknown_202D808, sizeof(gUnknown_202D808));
    MemoryClear16(gUnknown_202D910[0], sizeof(gUnknown_202D910));
}

// These two are the same, except sub_800D414 calls an additional func
void sub_800D414(void)
{
    ClearUnkMemory();
    sub_800D6AC();
}

void sub_800D494(void)
{
    ClearUnkMemory();
}

void sub_800D510(void)
{
    REG_RCNT = 0x8000;
}

void sub_800D520(void)
{
    vu16 var = 1; // Has to be u16, not s16
    u8 si0Cnt = (*(vu8 *)REG_ADDR_SIOCNT); // First 8 bits

    if (!(si0Cnt & 0x30)) {
        while (--var != (u16) -1) {
            VBlankIntrWait();
        }
    }
    sub_800D7D0();
}

void sub_800D570()
{
    sub_800D7B8();
}

UNUSED static u8 sub_800D57C(void)
{
    return gUnknown_202DB70;
}

u8 sub_800D588(void)
{
    return (gUnknown_202DB68 & 0x80);
}

void sub_800D59C(u16 *src, u32 size)
{
    u32 i;
    u16 bits;
    s32 count = 0;
    u16 *dst = gUnknown_202D808;

    gUnknown_202DB74 = ((size + 1) & ~(1)) + 8;
    CpuCopy(&dst[2], src, size);
    bits = 0xFDFD;
    dst[0] = bits;
    dst[1] = 0;
    for (i = 0; i < (gUnknown_202DB74 / 2) - 2; i++) {
        count += dst[i];
    }

    gUnknown_202D808[1] = ~count - (gUnknown_202DB74 / 2);
}
