#include "global.h"
#include "globaldata.h"
#include "string_format.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text.h"
#include "sprite.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_803D0D8.h"
#include "text.h"

struct  unkStruct_203B1F8
{
    // size: 0x4B4
    u32 menuAction;
    MenuStruct unk4;
    UnkTextStruct2 unk54[4];
    u8 buffer[0x400];
};

EWRAM_INIT struct unkStruct_203B1F8 *gUnknown_203B1F8 = {NULL};

const UnkTextStruct2 gUnknown_80DAF70 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const UnkTextStruct2 gUnknown_80DAF88 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x1A, 0x0c,
   0x0c, 0x00,
   NULL
};

const UnkTextStruct2 gUnknown_80DAFA0 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x16, 0x0F,
   0x06, 0x03,
   0x03, 0x00,
   NULL
};

bool8 sub_8015080(u8 *buffer, const MenuItem *menuItems)
{
    s32 index;

    gUnknown_203B1F8 = MemoryAlloc(sizeof(struct unkStruct_203B1F8), 8);
    gUnknown_203B1F8->menuAction = 0;

    for(index = 0; index < 4; index++)
    {
        gUnknown_203B1F8->unk54[index] = gUnknown_80DAF70;
    }

    gUnknown_203B1F8->unk54[0] = gUnknown_80DAF88;
    gUnknown_203B1F8->unk54[2] = gUnknown_80DAFA0;
    sub_8012CAC(&gUnknown_203B1F8->unk54[2], menuItems);
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_203B1F8->unk54, 1, 1);
    sub_80073B8(0);
    FormatString(buffer, gUnknown_203B1F8->buffer, gUnknown_203B1F8->buffer + 0x400, 0);
    PrintStringOnWindow(4, 4, gUnknown_203B1F8->buffer, 0, 0);
    sub_80073E0(0);
    sub_8012D60(&gUnknown_203B1F8->unk4, menuItems, 0, 0, -1, 2);
    return TRUE;
}

u32 sub_801516C(void)
{
    if(!sub_8012FD8(&gUnknown_203B1F8->unk4)) {
        sub_8013114(&gUnknown_203B1F8->unk4, &gUnknown_203B1F8->menuAction);
        return 3;
    }
    else {
        return 0;
    }
}

u32 sub_8015198(void)
{
    return gUnknown_203B1F8->menuAction;
}

void sub_80151A4(void)
{
    if(gUnknown_203B1F8) {
        MemoryFree(gUnknown_203B1F8);
        gUnknown_203B1F8 = NULL;
    }
}

struct unkStruct_203B1FC
{
    // size: 0x198
    u32 unk0;
    u8 unk4;
    // Note: These had to be declared like these, because SpriteOAM is aligned by 4 and these aren't. Makes you think if SpriteOAM is actually a struct, and not just an array of 4 u16s.
    u16 sprite1Attribs[4];
    u16 sprite2Attribs[4];
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u16 unk1E[(0x8A - 0x1E) / 2];
    s16 unk8A[2];
    u8 fill8E[0xF8 - 0x8E];
    u8 *unkF8;
    u8 unkFC[56];
    u8 *unk134;
    UnkTextStruct2 unk138[4];
};
extern struct unkStruct_203B1FC *gUnknown_203B1FC;

extern UnkTextStruct2 gUnknown_80DB550;
extern UnkTextStruct2 gUnknown_80DB568;
extern UnkTextStruct2 gUnknown_80DB580;
extern UnkTextStruct2 gUnknown_80DB538;
s32 sub_8015F44(void);
void sub_8015A08(u32);
void sub_8015C1C(void);
void sub_8015F84();
void sub_80157D8(void);
void sub_80158BC(void);
void sub_8015E10(u8 *a0, s32 a1, s32 _a2);
void sub_8015EB4(u8 *a0, s32 a1, s32 _a2);
s32 sub_8016028(void);
s32 sub_8015FEC(u8 *buffer, s32 size);
u32 sub_801560C(void);
bool8 sub_8015748(void);

u32 sub_80151C0(u32 r0, u8 *buffer)
{
    SpriteOAM *sprite;
    s32 index;
    s32 i;

    gUnknown_203B1FC = MemoryAlloc(sizeof(*gUnknown_203B1FC), 8);
    gUnknown_203B1FC->unk0 = r0;
    gUnknown_203B1FC->unk19 = 0;
    gUnknown_203B1FC->unk18 = 0;
    gUnknown_203B1FC->unk4 = 0;

    switch(gUnknown_203B1FC->unk0) {
        case 4:
            gUnknown_203B1FC->unk1A = 9;
            gUnknown_203B1FC->unk4 = 1;
            gUnknown_203B1FC->unk1B = 0x36;
            break;
        case 5:
            gUnknown_203B1FC->unk1A = 9;
            gUnknown_203B1FC->unk4 = 1;
            gUnknown_203B1FC->unk1B = 0x18;
            break;
        case 0:
        case 1:
        case 3:
        default:
            gUnknown_203B1FC->unk1A = 6;
            gUnknown_203B1FC->unk1B = 0xA;
            break;
    }

    gUnknown_203B1FC->unk134 = buffer;
    gUnknown_203B1FC->unkF8 =  gUnknown_203B1FC->unkFC;

    for (i = 0; i < 0x36; i++) {
        gUnknown_203B1FC->unkF8[i] = 0;
    }
    MemoryCopy8(gUnknown_203B1FC->unkF8, gUnknown_203B1FC->unk134, gUnknown_203B1FC->unk1B);

    for (i = 0; i < gUnknown_203B1FC->unk1B; i++) {
        if (gUnknown_203B1FC->unkF8[i] == 0) {
            break;
        }
    }
    for (; i < gUnknown_203B1FC->unk1B; i++) {
        gUnknown_203B1FC->unkF8[i] = 0;
    }

    gUnknown_203B1FC->unk1C = sub_8015F44();
    if (gUnknown_203B1FC->unk1C == gUnknown_203B1FC->unk1B) {
        gUnknown_203B1FC->unk1C--;
    }

    SpriteSetAffine1((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
    SpriteSetAffine2((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
    SpriteSetObjMode((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
    SpriteSetMosaic((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
    SpriteSetBpp((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
    SpriteSetPriority((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
    SpriteSetPalNum((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 15);
    SpriteSetX((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, DISPLAY_WIDTH);
    SpriteSetY((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, DISPLAY_WIDTH);

    if (gUnknown_203B1FC->unk4 != 0) {
        SpriteSetMatrixNum((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
        SpriteSetTileNum((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0x3F6);
        SpriteSetSize((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
        SpriteSetShape((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 1);
    }
    else {
        SpriteSetMatrixNum((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 16);
        SpriteSetTileNum((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0x3F0);
        SpriteSetSize((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0);
        SpriteSetShape((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 1);
    }

    gUnknown_203B1FC->unk16 = 4;

    sprite = (SpriteOAM *) &gUnknown_203B1FC->sprite2Attribs;

    SpriteSetAffine1(sprite, 0);
    SpriteSetAffine2(sprite, 0);
    SpriteSetObjMode(sprite, 0);
    SpriteSetMosaic(sprite, 0);
    SpriteSetBpp(sprite, 0);
    SpriteSetShape(sprite, 0);
    SpriteSetTileNum(sprite, 0x3F4);
    SpriteSetPriority(sprite, 0);
    SpriteSetPalNum(sprite, 15);
    SpriteSetMatrixNum(sprite, 0);
    SpriteSetSize(sprite, 0);
    SpriteSetX(sprite, DISPLAY_WIDTH);
    SpriteSetY(sprite, DISPLAY_WIDTH);

    gUnknown_203B1FC->unk17 = 0;

    for (index = 0; index < 4; index++) {
        gUnknown_203B1FC->unk138[index] = gUnknown_80DB538;
    }

    if(gUnknown_203B1FC->unk4 != 0) {
        gUnknown_203B1FC->unk138[1] = gUnknown_80DB580;
    }
    else {
        gUnknown_203B1FC->unk138[1] = gUnknown_80DB568;
    }
    gUnknown_203B1FC->unk138[0] = gUnknown_80DB550;

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_203B1FC->unk138, 1, 1);

    sub_8015A08(1);
    sub_8015C1C();
    sub_8015F84();
    return 1;
}

u32 sub_80154F0(void)
{
    gUnknown_203B1FC->unk16++;
    sub_80157D8();
    if (gUnknown_203B1FC->unk16 & 8) {
        AddSprite((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, 0x100, NULL, NULL);
    }

    gUnknown_203B1FC->unk17++;
    sub_80158BC();
    if (gUnknown_203B1FC->unk17 & 8) {
        AddSprite((SpriteOAM *) &gUnknown_203B1FC->sprite2Attribs, 0x100, NULL, NULL);
    }

    switch (sub_8012AE8()) {
        case 5:
            if (gUnknown_203B1FC->unk1C == 0) {
                PlayMenuSoundEffect(2);
            }
            else {
                gUnknown_203B1FC->unk1C--;
                PlayMenuSoundEffect(3);
            }
            break;
        case 6:
            if (gUnknown_203B1FC->unk1C != gUnknown_203B1FC->unk1B - 1 && gUnknown_203B1FC->unk1C < sub_8015F44()) {
                gUnknown_203B1FC->unk1C++;
                PlayMenuSoundEffect(3);
            }
            else {
                PlayMenuSoundEffect(2);
            }
            break;
        case 1:
            return sub_801560C();
        case 2:
            if (sub_8015748()) {
                return 2;
            }
            break;
        case 4:
            PlayMenuSoundEffect(3);
            gUnknown_203B1FC->unk1A = 5;
            break;
    }

    return 0;
}

void sub_80155F0(void)
{
    if (gUnknown_203B1FC != NULL) {
        MemoryFree(gUnknown_203B1FC);
        gUnknown_203B1FC = NULL;
    }
}

struct Struct80DB0F8
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s32 unk8;
};

extern const struct Struct80DB0F8 gUnknown_80DB0F8[][85];
extern const DungeonPos gUnknown_80DB098[];
extern const DungeonPos gUnknown_80DAFC0[];
extern const u8 gUnknown_80DB598[];
extern const u8 gUnknown_80DB5A4[];
extern const u8 gUnknown_80DB5B0[];
extern const u8 gUnknown_80DB5B8[];
extern const u8 gUnknown_80DB5C0[];
extern const u8 gUnknown_80DB5D4[];
extern const u8 gUnknown_80DB5F8[];
extern const u8 gUnknown_80DB61C[];
extern const u8 gUnknown_80DB638[];
extern const u8 gUnknown_80DB654[];
extern const u8 gUnknown_80DB65C[];
extern const u8 gUnknown_80DB664[];
extern const u8 *const gUnknown_80DB4F4[];

u32 sub_801560C(void)
{
    s32 var = gUnknown_80DB0F8[gUnknown_203B1FC->unk19][gUnknown_203B1FC->unk1A].unk8;

    switch (var) {
        case 0x107:
            gUnknown_203B1FC->unk18 = (gUnknown_203B1FC->unk18 == 0);
            PlayMenuSoundEffect(4);
            sub_8015A08(0);
            break;
        case 0x105:
            if (sub_8015748()) {
                return 2;
            }
            break;
        case 0x106:
            if (sub_8015F44() == 0 || (gUnknown_203B1FC->unk4 != 0 && sub_8015F44() != gUnknown_203B1FC->unk1B)) {
                PlayMenuSoundEffect(2);
            }
            else {
                PlayMenuSoundEffect(0);
                MemoryCopy8(gUnknown_203B1FC->unk134, gUnknown_203B1FC->unkF8, gUnknown_203B1FC->unk1B);
                return 3;
            }
            break;
        default:
            if (gUnknown_203B1FC->unk4 != 0 && sub_803D0F0(var) == 0xFF) {
                PlayMenuSoundEffect(2);
            }
            else {
                if (gUnknown_203B1FC->unk18 == 1) {
                    s32 i;
                    for (i = gUnknown_203B1FC->unk1B - 2; i >= gUnknown_203B1FC->unk1C; i--) {
                        u8 *ptr = &gUnknown_203B1FC->unkF8[i];
                        ptr[1] = ptr[0];
                    }
                }

                gUnknown_203B1FC->unkF8[gUnknown_203B1FC->unk1C] = var;
                if (gUnknown_203B1FC->unk1C < gUnknown_203B1FC->unk1B - 1) {
                    gUnknown_203B1FC->unk1C++;
                }
                else {
                    gUnknown_203B1FC->unk1A = 5;
                }

                PlayMenuSoundEffect(0);
                sub_8015C1C();
                sub_8015F84();
            }
            break;
    }

    return 0;
}

bool8 sub_8015748(void)
{
    u32 val = gUnknown_203B1FC->unkF8[gUnknown_203B1FC->unk1C];

    if (val == 0) {
        if (gUnknown_203B1FC->unk1C == 0) {
            PlayMenuSoundEffect(2);
            return TRUE;
        }
        else {
            gUnknown_203B1FC->unk1C--;
            gUnknown_203B1FC->unkF8[gUnknown_203B1FC->unk1C] = val;
            PlayMenuSoundEffect(1);
            sub_8015C1C();
            sub_8015F84();
        }
    }
    else {
        s32 i, n;

        n = sub_8015F44() - 1;
        for (i = gUnknown_203B1FC->unk1C; i < n; i++) {
            u8 *ptr = &gUnknown_203B1FC->unkF8[i];
            ptr[0] = ptr[1];
        }
        gUnknown_203B1FC->unkF8[n] = 0;
        PlayMenuSoundEffect(1);
        sub_8015C1C();
        sub_8015F84();
    }

    return FALSE;
}

void sub_80157D8(void)
{
    UnkTextStruct1 *txtPtr = &gUnknown_2027370[1];

    // Note: for cases 4 and 5, the code is identical except for different position structs.
    if (gUnknown_203B1FC->unk0 == 4) {
        s32 x, y;

        x = gUnknown_80DAFC0[gUnknown_203B1FC->unk1C].x + (txtPtr->unk0 * 8);
        SpriteSetX((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, x);

        y = gUnknown_80DAFC0[gUnknown_203B1FC->unk1C].y + (txtPtr->unk2 * 8) + 5;
        SpriteSetY((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, y);
    }
    else if (gUnknown_203B1FC->unk0 == 5) {
        s32 x, y;

        x = gUnknown_80DB098[gUnknown_203B1FC->unk1C].x + (txtPtr->unk0 * 8);
        SpriteSetX((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, x);

        y = gUnknown_80DB098[gUnknown_203B1FC->unk1C].y + (txtPtr->unk2 * 8) + 5;
        SpriteSetY((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, y);
    }
    else {
        s32 x, y;

        x = gUnknown_203B1FC->unk1E[gUnknown_203B1FC->unk1C] + (gUnknown_203B1FC->unk8A[gUnknown_203B1FC->unk1C] / 2) + 30 + (txtPtr->unk0 * 8);
        SpriteSetX((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, (u16) x);

        y = (txtPtr->unk2 * 8) + 34;
        SpriteSetY((SpriteOAM *) &gUnknown_203B1FC->sprite1Attribs, y);
    }
}

void sub_80158BC(void)
{
    s32 x, y;
    UnkTextStruct1 *txtPtr = &gUnknown_2027370[0];
    u32 var;

    switch (sub_8012AE8()) {
        case 7:
            var = gUnknown_80DB0F8[gUnknown_203B1FC->unk19][gUnknown_203B1FC->unk1A].unk0;
            break;
        case 8:
            var = gUnknown_80DB0F8[gUnknown_203B1FC->unk19][gUnknown_203B1FC->unk1A].unk1;
            break;
        case 9:
            var = gUnknown_80DB0F8[gUnknown_203B1FC->unk19][gUnknown_203B1FC->unk1A].unk2;
            break;
        case 10:
            var = gUnknown_80DB0F8[gUnknown_203B1FC->unk19][gUnknown_203B1FC->unk1A].unk3;
            break;
        default:
            var = gUnknown_203B1FC->unk1A;
            break;
    }

    if (var != gUnknown_203B1FC->unk1A) {
        gUnknown_203B1FC->unk1A = var;
        PlayMenuSoundEffect(3);
        gUnknown_203B1FC->unk17 = 8;
    }

    x =  gUnknown_80DB0F8[gUnknown_203B1FC->unk19][gUnknown_203B1FC->unk1A].unk4 + (txtPtr->unk0 * 8) - 5;
    y =  gUnknown_80DB0F8[gUnknown_203B1FC->unk19][gUnknown_203B1FC->unk1A].unk5 + (txtPtr->unk2 * 8) + 1;
    SpriteSetX((SpriteOAM *) &gUnknown_203B1FC->sprite2Attribs, x);
    SpriteSetY((SpriteOAM *) &gUnknown_203B1FC->sprite2Attribs, y);
}

void sub_8015A08(u32 unused)
{
    s32 r4;
    s32 i;
    u8 text1[16];
    u8 text2[16];

    CallPrepareTextbox_8008C54(0);
    sub_80073B8(0);

    for (i = 0; (r4 = gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk8) != 0x109; i++) {
        s32 r5;

        switch (gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk6) {
            case 1:
                r5 = 5;
                break;
            case 2:
                r5 = 2;
                break;
            case 3:
                r5 = 7;
                break;
            default:
                r5 = 7;
                if (gUnknown_203B1FC->unk4 != 0) {
                    if (r4 <= 0xFF) {
                        if (sub_803D0F0(r4) == 0xFF) {
                            r5 = 2;
                        }
                    }
                    else if (r4 < 0x102) {
                        r5 = 2;
                    }
                }
                break;
        }

        if (r4 != 0x108) {
            if (r4 == 0x107) {
                if (gUnknown_203B1FC->unk18 == 0) {
                    PrintStringOnWindow(gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk4 + 3, gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk5, gUnknown_80DB598, 0, '\0');
                }
                else {
                    PrintStringOnWindow(gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk4 + 3, gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk5, gUnknown_80DB5A4, 0, '\0');
                }
            }
            else if (r4 == 0x20) {
                sprintfStatic(text1, gUnknown_80DB5B0, r5);
                PrintStringOnWindow(gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk4 + 1, gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk5, text1, 0, '\0');
            }
            else if (r4 > 0xFF) {
                sprintfStatic(text2, gUnknown_80DB5B8, r5, gUnknown_80DB4F4[r4 & 0xFF]);
                PrintStringOnWindow(gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk4 + 3, gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk5, text2, 0, '\0');
            }
            else {
                sub_8012C60(gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk4, gUnknown_80DB0F8[gUnknown_203B1FC->unk19][i].unk5, (u8) r4, r5, 0);
            }
        }
    }

    sub_800792C(0, 0, 0, 0xE0, 0xE);
    sub_800792C(0, 0, 0x47, 0xE0, 0xE);
    sub_8007A78(0, 0, 0, 0x48, 0xE);
    sub_8007A78(0, 0xDF, 0, 0x48, 0xE);
    sub_80073E0(0);
}

void sub_8015C1C(void)
{
    u8 text[80];

    CallPrepareTextbox_8008C54(1);
    sub_80073B8(1);
    if (gUnknown_203B1FC->unk4 != 0) {
        sub_800792C(1, 0, 0, 0xE0, 0xE);
        sub_800792C(1, 0, 0x37, 0xE0, 0xE);
        sub_8007A78(1, 0, 0, 0x38, 0xE);
        sub_8007A78(1, 0xDF, 0, 0x38, 0xE);
    }
    else {
        sub_800792C(1, 0, 0, 0xB0, 0xE);
        sub_800792C(1, 0, 0x27, 0xB0, 0xE);
        sub_8007A78(1, 0, 0, 0x28, 0xE);
        sub_8007A78(1, 0xAF, 0, 0x28, 0xE);
    }

    switch (gUnknown_203B1FC->unk0) {
        case 0:
            PrintStringOnWindow(8, 5, gUnknown_80DB5C0, 1, '\0');
            break;
        case 2:
            PrintStringOnWindow(8, 5, gUnknown_80DB5D4, 1, '\0');
            break;
        case 3:
            PrintStringOnWindow(8, 5, gUnknown_80DB5F8, 1, '\0');
            break;
        case 1:
            PrintStringOnWindow(8, 5, gUnknown_80DB61C, 1, '\0');
            break;
        case 4:
            PrintStringOnWindow(54, 2, gUnknown_80DB638, 1, '\0');
            break;
        case 5:
            PrintStringOnWindow(48, 4, gUnknown_80DB638, 1, '\0');
            break;
    }

    switch (gUnknown_203B1FC->unk0) {
        case 4:
            sub_8015E10(gUnknown_203B1FC->unkF8, 1, 0);
            break;
        case 5:
            sub_8015EB4(gUnknown_203B1FC->unkF8, 1, 0);
            break;
        case 0:
        case 1:
        case 2:
        case 3:
            sub_80078A4(1, 38, 33, sub_8016028(), 4);
            if (sub_8015FEC(gUnknown_203B1FC->unkF8, gUnknown_203B1FC->unk1B) > sub_8016028()) {
                sprintfStatic(text, gUnknown_80DB654, gUnknown_203B1FC->unkF8);
            }
            else if (sub_8015F44() == gUnknown_203B1FC->unk1B) {
                sprintfStatic(text, gUnknown_80DB65C, gUnknown_203B1FC->unkF8);
            }
            else {
                sprintfStatic(text, gUnknown_80DB664, gUnknown_203B1FC->unkF8);
            }
            PrintStringOnWindow(38, 22, text, 1, '\0');
            break;
    }

    sub_80073E0(1);
}

void sub_8015E10(u8 *a0, s32 a1, s32 _a2)
{
    s32 i;
    s32 a2 = (s16) _a2;

    for (i = 0; i < 54; i++) {
        sub_80078A4(a1, gUnknown_80DAFC0[i].x, gUnknown_80DAFC0[i].y + 11 + a2, 11, 5);
    }

    for (i = 0; i < 54 && a0[i] != 0; i++) {
        s32 arg3;

        if (i <= 4) arg3 = 7;
        else if (i <= 12) arg3 = 6;
        else if (i <= 17) arg3 = 7;
        else if (i <= 22) arg3 = 7;
        else if (i <= 30) arg3 = 6;
        else if (i <= 35) arg3 = 7;
        else if (i <= 40) arg3 = 7;
        else if (i <= 48) arg3 = 6;
        else arg3 = 7;

        sub_8012C60(gUnknown_80DAFC0[i].x, gUnknown_80DAFC0[i].y + a2, a0[i], arg3, a1);
    }
}

void sub_8015EB4(u8 *a0, s32 a1, s32 _a2)
{
    s32 i;
    s32 a2 = (s16) _a2;

    for (i = 0; i < 24; i++) {
        sub_80078A4(a1, gUnknown_80DB098[i].x, gUnknown_80DB098[i].y + 11 + a2, 12, 5);
    }

    for (i = 0; i < 24 && a0[i] != 0; i++) {
        s32 arg3;

        if (i <= 3) arg3 = 7;
        else if (i <= 7) arg3 = 6;
        else if (i <= 15) arg3 = 7;
        else if (i <= 19) arg3 = 6;
        else arg3 = 7;

        sub_8012C60(gUnknown_80DB098[i].x, gUnknown_80DB098[i].y + a2, a0[i], arg3, a1);
    }
}
