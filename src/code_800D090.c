#include "global.h"
#include "code_800D090.h"
#include "cpu.h"
#include "memory.h"
#include "music.h"

void Hang(void)
{
    while (TRUE)
    {
        asm("swi 0x2");
    }
}

UNUSED static void sub_800D098(void)
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

UNUSED static void sub_800D16C(const char *text, ...)
{
    char buffer[1024];
    va_list vArgv;
    va_start(vArgv, text);
    vsprintf(buffer, text, vArgv);
    va_end(vArgv);
}

UNUSED static void sub_800D10A(const char *r0, u32 r1, u32 r2, u32 r3, ...)
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

// New file?
union PtrU16U8
{
    u16 *asU16;
    u8 *asU8;
};

// Important note: This struct is used in arm_funcs.s, which means the offsets of this struct's memebers CANNOT be changed, unless sub_80001E8 and sub_8000228 are accordingly changed.
struct UnkStruct_202DCF8
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 fillC[0x14-0xC];
    s32 unk14;
    s32 unk18[4];
    union PtrU16U8 unk28;
    u16 *unk2C;
    u16 *unk30[4];
    u16 *unk40[4];
    u16 *unk50[4];
    u16 unk60[12];
    u16 unk78[12];
    u16 unk90[2][3][12];
};

EWRAM_DATA static u16 gUnknown_202D808[132] = {0};
EWRAM_DATA static u16 gUnknown_202D910[2][132] = {0};
EWRAM_DATA static u16 gUnknown_202DB20[8] = {0};
EWRAM_DATA static u16 gUnknown_202DB30[2][8] = {0};
EWRAM_DATA static u32 gUnknown_202DB50[2] = {0}; // Only first index used
EWRAM_DATA static u32 gUnknown_202DB58[2] = {0};
EWRAM_DATA static u32 gUnknown_202DB60[2] = {0};
EWRAM_DATA static u32 gUnknown_202DB68 = 0;
EWRAM_DATA static s32 gUnknown_202DB6C = 0;
EWRAM_DATA static u8 gUnknown_202DB70 = 0;
EWRAM_DATA static u32 gUnknown_202DB74 = 0;
// These should not be in EWRAM, but in IWRAM...
EWRAM_DATA u32 gUnknown_202DB78[16] = {0};
EWRAM_DATA u32 gUnknown_202DBB8[80] = {0};

EWRAM_DATA struct UnkStruct_202DCF8 gUnknown_202DCF8 = {0};

// arm_funcs.s
extern u32 sub_80001E8(void);
extern void sub_8000228(void);

static u32 sub_800D820(u16 *a0, u16 a1[2][8]);
static void sub_800D7B8(void);
static void sub_800D944(u16 *a0);
static u32 sub_800D9B8(u16 dst[2][8]);

bool8 sub_800D1C0(u32 unused)
{
    if(gUnknown_202DB60[0] != 2)
        return FALSE;
    if(gUnknown_202DB60[1] != 2)
        return FALSE;
    return TRUE;
}

static void sub_800D1E0(void)
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

static void sub_800D224(s32 a0)
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

static void sub_800D2EC(u32 unused)
{
    u32 i;
    u16 *ptr = gUnknown_202D808;

    for (i = 0; i < 8; i++) {
        if (gUnknown_202DB50[0] < (gUnknown_202DB74 / 2)) {
            gUnknown_202DB20[i] = ptr[gUnknown_202DB50[0]++];
        }
        else {
            gUnknown_202DB20[i] = 0xFCFC;
        }
    }
}

s32 sub_800D33C(void)
{
    s32 ret = 0;

    gUnknown_202DB6C = gUnknown_202DB68;
    gUnknown_202DB68 = sub_800D820(gUnknown_202DB20, gUnknown_202DB30);
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
    gUnknown_202DB50[0] = 0;
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

void sub_800D570(void)
{
    sub_800D7B8();
}

UNUSED static u8 sub_800D57C(void)
{
    return gUnknown_202DB70;
}

bool8 sub_800D588(void)
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

bool8 sub_800D600(void)
{
    u32 i, j;

    for (i = 0; i < 2; i++) {
        s32 count = 0;
        u16 *ptr = gUnknown_202D910[i];

        for (j = 0; j < (gUnknown_202DB74 / 2) - 2; j++) {
            count += ptr[j];
        }

        // Interesting casts and arithmetics here.
        if ((s16) count != (s16) (-1 - (gUnknown_202DB74 / 2)))
            return FALSE;
    }

    return TRUE;
}

void sub_800D670(u32 id, void *dst, u32 size)
{
    CpuCopy(dst, &gUnknown_202D910[id][2], size);
}

void sub_800D68C(u32 id)
{
    MemoryFill8(gUnknown_202D910[id], 0, sizeof(gUnknown_202D910[0]));
}

void sub_800D6AC(void)
{
    s32 i;

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    REG_RCNT = 0;
    (*(vu32 *)REG_ADDR_SIOCNT) = 0x2000;
    REG_SIOCNT |= 0x4003;
    CpuFill32(0, &gUnknown_202DCF8, 0x120);
    CpuCopy32(sub_80001E8, gUnknown_202DB78, sizeof(gUnknown_202DB78));
    CpuCopy32(sub_8000228, gUnknown_202DBB8, sizeof(gUnknown_202DBB8));
    gUnknown_202DCF8.unk14 = -1;
    gUnknown_202DCF8.unk28.asU16 = gUnknown_202DCF8.unk60;
    gUnknown_202DCF8.unk2C = gUnknown_202DCF8.unk78;

    for (i = 0; i < 2; i++) {
        gUnknown_202DCF8.unk30[i] = gUnknown_202DCF8.unk90[i][0];
        gUnknown_202DCF8.unk40[i] = gUnknown_202DCF8.unk90[i][1];
        gUnknown_202DCF8.unk50[i] = gUnknown_202DCF8.unk90[i][2];
    }

    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

static void sub_800D7B8(void)
{
    if (gUnknown_202DCF8.unk0 != 0) {
        gUnknown_202DCF8.unk8 = 1;
    }
}

void sub_800D7D0(void)
{
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    REG_SIOCNT = 0x2003;
    REG_TM3CNT = 0xB1FC;
    REG_IF = 0xC0;
    gUnknown_202DCF8.unk8 = 0;
}

static u32 sub_800D820(u16 *a0, u16 a1[2][8])
{
    u32 ret, var;
    u32 bits1, bits2, b;
    u32 r3, r2;
    u32 si0cnt = (*(vu32 *)REG_ADDR_SIOCNT);

    switch (gUnknown_202DCF8.unk1) {
        case 0:
            if (gUnknown_202DCF8.unk14 == -1) {
                u16 bits = si0cnt & 0x88;
                if (bits != 8)
                    break;
                if (!((u8)(si0cnt & 0x4))) {
                    vu8 *sioPtru8;
                    u32 sioBits;

                    REG_IME = 0;
                    REG_IE &= 0xFF7F;
                    REG_IE |= 0x40;
                    REG_IME = 1;
                    sioPtru8 = ((vu8 *)REG_ADDR_SIOCNT);
                    sioBits = sioPtru8[1] & ~0x40;
                    sioPtru8[1] = sioBits;
                    REG_IF = 0xC0;
                    REG_TM3CNT = 0xB1FC;
                    gUnknown_202DCF8.unk0 = 8;
                }
            }
            gUnknown_202DCF8.unk1 = 1;
        // fallthrough
        case 1:
            if (gUnknown_202DCF8.unk2 != 0) {
                if (gUnknown_202DCF8.unkA < 8) {
                    gUnknown_202DCF8.unkA++;
                }
                else {
                    gUnknown_202DCF8.unk1 = 2;
                }
            }
        // fallthrough
        case 2:
            sub_800D9B8(a1);
            sub_800D944(a0);
            break;
    }

    gUnknown_202DCF8.unkB++;
    r3 = gUnknown_202DCF8.unk3;
    r2 = gUnknown_202DCF8.unk2 << 8;
    b = ((gUnknown_202DCF8.unk0 == 8) ? 0x80 : 0) | r3 | r2;
    var = b;
    if (gUnknown_202DCF8.unk9 != 0) {
        var |= 0x1000;
    }

    bits1 = (gUnknown_202DCF8.unkA >> 3) << 15;
    bits2 = (si0cnt << 26) >> 30;
    if (bits2 >= 2) {
        ret = 0x2000 | var | bits1;
    }
    else {
        ret = var | bits1;
    }
    return ret;
}

static void sub_800D944(u16 *src)
{
    u32 i;
    s32 count = 0;

    gUnknown_202DCF8.unk28.asU8[0] = gUnknown_202DCF8.unkB;
    gUnknown_202DCF8.unk28.asU8[1] = gUnknown_202DCF8.unk2 ^ gUnknown_202DCF8.unk3;
    gUnknown_202DCF8.unk28.asU16[1] = 0;
    CpuCopy32(src, &gUnknown_202DCF8.unk28.asU16[2], 0x10);
    for (i = 0; i < 10; i++) {
        count += gUnknown_202DCF8.unk28.asU16[i];
    }

    gUnknown_202DCF8.unk28.asU16[1] = ~count - 12;
    if (gUnknown_202DCF8.unk0 != 0) {
        REG_TM3CNT_H = 0;
    }
    gUnknown_202DCF8.unk14 = -1;
    if (gUnknown_202DCF8.unk0 != 0 && gUnknown_202DCF8.unk8 != 0) {
        REG_TM3CNT_H = 0xC0;
    }
}

static u32 sub_800D9B8(u16 dst[2][8])
{
    s32 i;
    u8 sp0[4];
    u32 (*func)(void) = (void *)gUnknown_202DB78;
    u32 *spAsU32 = (u32 *)sp0;

    *spAsU32 = func();
    gUnknown_202DCF8.unk3 = 0;
    for (i = 0; i < 2; i++) {
        u32 j;
        s32 count = 0;

        for (j = 0; j < 10; j++) {
            count += gUnknown_202DCF8.unk50[i][j];
        }

        if (sp0[i] != 0 && (s16)(count) == (s16)(-13)) {
            CpuCopy32(&gUnknown_202DCF8.unk50[i][2], dst[i], 0x10);
            gUnknown_202DCF8.unk3 |= (1 << i);
        }
        CpuFill32(0, &gUnknown_202DCF8.unk50[i][2], 0x10);
    }
    gUnknown_202DCF8.unk2 |= gUnknown_202DCF8.unk3;
    return gUnknown_202DCF8.unk3;
}
