#include "global.h"
#include "globaldata.h"
#include "palette_util.h"
#include "bg_palette_buffer.h"

extern void sub_80039B8(void);
extern void TransferBGPaletteBuffer(void);
extern void sub_80037C8(u16, u32, unkStruct_3000400);
extern void sub_8003664(u16 param_1, u16 param_2);
extern void sub_80036AC(u16, u32, unkStruct_3000400);
extern void sub_80036F4(u16, u32, unkStruct_3000400);
extern void sub_8003780(u16, u32, unkStruct_3000400);

struct UnkStruct_2039958
{
    s32 unk0;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
};

struct UnkStruct_2039978
{
    u32 unk0;
    unkStruct_3000400 unk4;
    struct UnkStruct_2039958 unk8;
};

static EWRAM_DATA struct UnkStruct_2039958 gUnknown_2039958 = {0};
static EWRAM_DATA struct UnkStruct_2039958 gUnknown_2039968 = {0};
static EWRAM_DATA struct UnkStruct_2039978 gUnknown_2039978 = {0};
static EWRAM_DATA u8 gUnknown_2039990 = FALSE;
static EWRAM_DATA s16 gUnknown_2039992 = 0;
UNUSED static EWRAM_DATA s32 sUnused = 0;
#define ARR_COUNT_2039998 33
static EWRAM_DATA u16 gUnknown_2039998[ARR_COUNT_2039998] = {0};

static void sub_8099838(struct UnkStruct_2039958 *a0);
static void sub_8099848(struct UnkStruct_2039958 *a0);
static void sub_8099DD0(u16 a0);
static void sub_8099E58(u16 a0);
static void sub_8099E80(u16 a0, unkStruct_3000400 a1);

void sub_8099744(void)
{
    sub_80039B8();
}

void sub_8099750(void)
{
    TransferBGPaletteBuffer();
}

void sub_809975C(void)
{
    sub_809977C();
}

void sub_8099768(void)
{
    sub_809977C();
    sub_8099744();
    sub_8099750();
}

void sub_809977C(void)
{
    s32 i;

    gUnknown_2039990 = FALSE;
    gUnknown_2039992 = 0;
    sub_8099838(&gUnknown_2039958);
    sub_8099838(&gUnknown_2039968);
    sub_8099838(&gUnknown_2039978.unk8);
    gUnknown_2039978.unk0 = 0;
    gUnknown_2039978.unk8.unkC = 0x100;
    gUnknown_2039958.unkC = 0;
    sub_8099DD0(0);
    gUnknown_2039968.unkC = 0x100;
    sub_8099E58(0x100);
    for (i = 0; i < ARR_COUNT_2039998; i++) {
        gUnknown_2039998[i] = 0;
    }
}

void sub_80997F4(u16 a0, u16 a1)
{
    gUnknown_2039998[a0] = a1;
    sub_8099848(&gUnknown_2039958);
    sub_8099848(&gUnknown_2039968);
    sub_8099848(&gUnknown_2039978.unk8);
}

UNUSED static u32 sub_8099828(u16 a0)
{
    return gUnknown_2039998[a0];
}

static void sub_8099838(struct UnkStruct_2039958 *a0)
{
    a0->unk0 = 1;
    a0->unkC = 0;
    a0->unk4 = 0;
    a0->unk6 = 0;
}

static void sub_8099848(struct UnkStruct_2039958 *a0)
{
    if (a0->unk0 == 0) {
        a0->unk0 = 1;
    }
}

static void sub_809985C(struct UnkStruct_2039958 *a0, s32 a1)
{
    if (a1 >= 0) {
        if (a1 == 0) {
            a0->unkC = 0x100;
            a0->unk0 = 1;
        }
        else {
            a0->unk0 = 2;
        }
    }
    else {
        a1 = 30;
        a0->unk0 = 2;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
}

static void sub_8099880(struct UnkStruct_2039958 *a0, s32 a1)
{
    if (a1 >= 0) {
        if (a1 == 0) {
            a0->unkC = a1;
            a0->unk0 = 1;
        }
        else {
            a0->unk0 = 3;
        }
    }
    else {
        a1 = 30;
        a0->unk0 = 3;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
}

static void sub_80998A0(struct UnkStruct_2039958 *a0, s32 a1, u16 a2, u16 a3)
{
    if (a1 < 0) a1 = 30;

    if (a2 > a3) {
        a0->unk0 = 5;
        a0->unkA = a2 - a3;
    }
    else if (a2 < a3) {
        a0->unk0 = 4;
        a0->unkA = a3 - a2;
    }
    else {
        a0->unk0 = 1;
        a0->unkA = 0;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
    a0->unkC = a2;
    a0->unk8 = a3;
}

static bool8 sub_80998E0(struct UnkStruct_2039958 *a0)
{
    switch (a0->unk0) {
        case 0:
            break;
        case 1:
            a0->unk0 = 0;
            return TRUE;
        case 2:
            if (--a0->unk4 > 0) {
                u16 var = 0x100 - ((a0->unk4 << 8) / a0->unk6);
                if (a0->unkC < var) {
                    a0->unkC = var;
                }
            }
            else {
                a0->unkC = 0x100;
                a0->unk0 = 0;
            }
            return TRUE;
        case 3:
            if (--a0->unk4 > 0) {
                u16 var = (a0->unk4 << 8) / a0->unk6;
                if (a0->unkC > var) {
                    a0->unkC = var;
                }
            }
            else {
                a0->unkC = 0;
                a0->unk0 = 0;
            }
            return TRUE;
        case 4:
            if (--a0->unk4 > 0) {
                a0->unkC = a0->unk8 - ((a0->unk4 * a0->unkA) / a0->unk6);
            }
            else {
                a0->unkC = a0->unk8;
                a0->unk0 = 0;
            }
            return TRUE;
        case 5:
            if (--a0->unk4 > 0) {
                a0->unkC = a0->unk8 + ((a0->unk4 * a0->unkA) / a0->unk6);
            }
            else {
                a0->unkC = a0->unk8;
                a0->unk0 = 0;
            }
            return TRUE;
    }

    return FALSE;
}

void sub_80999D4(s32 a0)
{
    gUnknown_2039990 = TRUE;
    gUnknown_2039992 = a0;
}

void sub_80999E8(s32 a0)
{
    sub_809985C(&gUnknown_2039958, a0);
}

void sub_80999FC(s32 a0)
{
    sub_8099880(&gUnknown_2039958, a0);
}

void sub_8099A10(s32 a1, u16 a2, u16 a3)
{
    sub_80998A0(&gUnknown_2039958, a1, a2, a3);
}

void sub_8099A34(s32 a0)
{
    sub_809985C(&gUnknown_2039968, a0);
}

void sub_8099A48(s32 a0)
{
    sub_8099880(&gUnknown_2039968, a0);
}

void sub_8099A5C(s32 a0, s32 a1, unkStruct_3000400 a2)
{
    gUnknown_2039978.unk0 = a0;
    gUnknown_2039978.unk4 = a2;
    gUnknown_2039978.unk8.unkC = 0;
    sub_809985C(&gUnknown_2039978.unk8, a1);

    switch (a0) {
        case 1:
        case 3:
            gUnknown_2039968.unkC = 0x100;
            gUnknown_2039958.unkC = 0x100;
            break;
        case 9:
        case 11:
            gUnknown_2039968.unkC = 0x100;
            break;
        case 5:
        case 7:
        case 13:
        case 14:
            gUnknown_2039958.unkC = 0x100;
            break;
    }
}

void sub_8099AFC(s32 a0, s32 a1, unkStruct_3000400 a2)
{
    gUnknown_2039978.unk0 = a0;
    gUnknown_2039978.unk4 = a2;
    gUnknown_2039978.unk8.unkC = 0x100;
    sub_8099880(&gUnknown_2039978.unk8, a1);

    switch (a0) {
        case 2:
        case 4:
            gUnknown_2039968.unkC = 0;
            gUnknown_2039958.unkC = 0;
            break;
        case 10:
        case 12:
            gUnknown_2039968.unkC = 0;
            break;
        case 6:
        case 8:
        case 13:
        case 14:
            gUnknown_2039958.unkC = 0;
            break;
    }
}

bool8 sub_8099B94(void)
{
    if (gUnknown_2039990)
        return TRUE;
    if (gUnknown_2039978.unk0 != 0) {
        return (gUnknown_2039978.unk8.unk0 != 0);
    }
    return (gUnknown_2039958.unk0 != 0 || gUnknown_2039968.unk0 != 0);
}

void sub_8099BE4(void)
{
    if (gUnknown_2039978.unk0 != 0 || gUnknown_2039978.unk8.unk0 != 0) {
        if (sub_80998E0(&gUnknown_2039978.unk8)) {
            sub_8099E80(gUnknown_2039978.unk8.unkC, gUnknown_2039978.unk4);
        }
        else if (gUnknown_2039978.unk8.unk0 == 0) {
            switch (gUnknown_2039978.unk0) {
                case 0:
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 9:
                case 11:
                    if (gUnknown_2039978.unk8.unkC >= 256) {
                        gUnknown_2039978.unk0 = 0;
                    }
                    else if (gUnknown_2039990) {
                        s32 var = 0;
                        switch (gUnknown_2039978.unk0) {
                            case 1: var = 2; break;
                            case 3: var = 4; break;
                            case 5: var = 6; break;
                            case 7: var = 8; break;
                        }

                        if (var != 0) {
                            sub_8099AFC(var, gUnknown_2039992, gUnknown_2039978.unk4);
                        }
                        else {
                            gUnknown_2039978.unk0 = 0;
                        }
                    }
                    break;
                case 2:
                case 4:
                case 6:
                case 8:
                case 10:
                case 12:
                case 13:
                case 14:
                    if (gUnknown_2039978.unk8.unkC == 0) {
                        gUnknown_2039978.unk0 = 0;
                    }
                    else if (gUnknown_2039990) {
                        sub_8099AFC(gUnknown_2039978.unk0, gUnknown_2039992, gUnknown_2039978.unk4);
                    }
                    break;
            }
        }
    }
    else if (gUnknown_2039990) {
        bool8 r5 = TRUE;
        if (gUnknown_2039958.unkC != 0 || gUnknown_2039958.unk0 != 0) {
            r5 = FALSE;
            if (gUnknown_2039958.unk0 != 3) {
                sub_8099880(&gUnknown_2039958, gUnknown_2039992);
            }
            if (sub_80998E0(&gUnknown_2039958)) {
                sub_8099DD0(gUnknown_2039958.unkC);
            }
        }
        if (gUnknown_2039968.unkC != 0 || gUnknown_2039968.unk0 != 0) {
            r5 = FALSE;
            if (gUnknown_2039968.unk0 != 3) {
                sub_8099880(&gUnknown_2039968, gUnknown_2039992);
            }
            if (sub_80998E0(&gUnknown_2039968)) {
                sub_8099E58(gUnknown_2039968.unkC);
            }
        }

        if (r5) {
            gUnknown_2039990 = FALSE;
        }
    }
    else {
        if (sub_80998E0(&gUnknown_2039958)) {
            sub_8099DD0(gUnknown_2039958.unkC);
        }
        if (sub_80998E0(&gUnknown_2039968)) {
            sub_8099E58(gUnknown_2039968.unkC);
        }
    }
}

static void sub_8099DD0(u16 a0)
{
    s32 i;

    for (i = 0; i < 14; i++) {
        if (gUnknown_2039998[i] & 1) {
            sub_8003664(i, 0x100);
        }
        else {
            sub_8003664(i, a0);
        }
    }

    for (i = 16; i < 31; i++) {
        if (gUnknown_2039998[i] & 1) {
            sub_8003664(i, 0x100);
        }
        else {
            sub_8003664(i, a0);
        }
    }

    sub_8003664(32, a0);
}

static void sub_8099E58(u16 a0)
{
    sub_8003664(15, a0);
    sub_8003664(14, a0);
    sub_8003664(31, a0);
}

static void sub_8099E80(u16 param_1,unkStruct_3000400 param_2)
{
    s32 i;

    switch (gUnknown_2039978.unk0) {
        case 0:
            break;
        case 1:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }
            break;
        case 9:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }
            break;
         case 5:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }
            break;
        case 2:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }
            break;
        case 10:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }
            break;
        case 6:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }
            break;
        case 3:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }
            break;
        case 11:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }
            break;
        case 7:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }
            break;
         case 4:
            for (i = 0; i < 16; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }
            break;
        case 12:
            for (i = 14; i < 16; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }
            break;
        case 13:
        case 14:
            switch (gUnknown_2039978.unk0) {
                case 13:
                    param_2.unk0[0] = 0x90;
                    param_2.unk0[1] = 0x90;
                    param_2.unk0[2] = 0xFF;
                    param_2.unk0[3] = 0xFF;
                    break;
                case 14:
                    param_2.unk0[0] = 0xFF;
                    param_2.unk0[1] = 0xC0;
                    param_2.unk0[2] = 0x80;
                    param_2.unk0[3] = 0xFF;
                    break;
            }
        // NOTE: fallthrough needed here
        case 8:
            for (i = 0; i < 14; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }
            break;
    }
}
