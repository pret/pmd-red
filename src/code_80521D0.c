#include "global.h"
#include "dungeon.h"
#include "structs/dungeon_entity.h"
#include "code_80521D0.h"
#include "code_803E46C.h"
#include "code_80130A8.h"
#include "code_800E9E4.h"
#include "text2.h"

extern void sub_80526D0(u8 r0);
extern bool8 sub_8045888(Entity *r0);
void sub_80523A8(Entity *r0, const char *str, u8 r2);
extern u8 sub_8052DC0(Entity *);
extern u8 sub_803F428(Position *);

void sub_805229C(void)
{
    return sub_80526D0(0x50);
}

void SendMessage(Entity *pokemon, const char message[])
{
    if (sub_8045888(pokemon)){
        sub_80523A8(pokemon, message, 1);
    }
}

void sub_80522C8(Entity *r0, const char *str)
{
    if (sub_8045888(r0)){
        sub_80523A8(r0, str, 0);
    }
}

void sub_80522E8(Entity *r0, const char *str)
{
    sub_80523A8(r0, str, 0);
}

void sub_80522F4(Entity *r0, Entity *r1, const char *str)
{
    u8 flag;
    flag = sub_8045888(r0) ? TRUE : FALSE;
    if(sub_8052DC0(r1) != 0)
    {
        flag = TRUE;
    }
    if(flag)
    {
        sub_80523A8(r0, str, 1);
    }
}

void sub_805232C(Entity *r0, Entity *r1, const char *str)
{
    u8 flag;
    flag = sub_8045888(r0) ? TRUE : FALSE;
    if(sub_8052DC0(r1) != 0)
    {
        flag = TRUE;
    }
    if(flag)
    {
        sub_80523A8(r0, str, 0);
    }
}

void sub_8052364(Entity *r0, Position *pos, const char *str)
{
    u8 flag;
    flag = sub_8045888(r0) ? TRUE : FALSE;
    if(sub_803F428(pos) != 0)
    {
        flag = TRUE;
    }
    if(flag)
    {
        sub_80523A8(r0, str, 1);
    }
}

void sub_805239C(Entity *r0, const char *str)
{
    sub_80523A8(r0, str, 1);
}

void sub_8053210(u8 *txt, u32 a1, u32 a2);

extern Entity *gUnknown_202F1E8;
extern u8 gUnknown_203B434;

extern void sub_805E804(void);

void sub_80523A8(Entity *r0, const char *str, bool8 r2)
{
    u8 txt[64];
    u32 r7;
    bool32 r8, r9;

    if (gUnknown_202F1E8 != r0) {
        r7 = 1;
    }
    else {
        r7 = gUnknown_203B434;
    }

    r8 = 1;
    gUnknown_202F1E8 = r0;
    gUnknown_203B434 = 0;
    r9 = FALSE;
    while (1) {
        while (1) {
            s32 val = gDungeon->unk1BDD4.unk1C060;
            if (++val == UNK_1BBD4_STR_COUNT) {
                val = 0;
            }

            if (val != gDungeon->unk1BDD4.unk1C062) {
                break;
            }
            sub_803E46C(0);
        }

        if (*str == '\0')
            break;

        gDungeon->unk1BDD4.unk1C054[gDungeon->unk1BDD4.unk1C060] = r7;
        str = xxx_format_string(str, txt, txt + 62, 128);
        if (*str == '\r') str++;
        if (*str == '\n') str++;
        sub_8053210(txt, r7, r8);
        r7 = 0;
        r8 = 0;
        if (r2) {
            u8 *dst;

            r9 = TRUE;
            dst = gDungeon->unk1BDD4.unk0[gDungeon->unk1BDD4.unk1C060];
            dst++;dst--; // TODO: use ASM_MATCH_TRICK
            strncpy(dst, txt, 64);
            if (++gDungeon->unk1BDD4.unk1C060 == UNK_1BBD4_STR_COUNT) {
                gDungeon->unk1BDD4.unk1C060 = 0;
            }
        }
    }

    if (r9) {
        gDungeon->unk1BDD4.unk1C064 = 0xF0;
        if (gDungeon->unk1BDD4.unk1C06C == 0) {
            gDungeon->unk1BDD4.unk1C06C = 1;
        }
        sub_805E804();
    }
}

extern void (*gUnknown_203B08C)(s32);

extern void sub_803EAF0(s32, s32);
extern void sub_8052210(u32);

void xxx_draw_string_80524F0(void)
{
    struct UnkStructDungeon1BDD4 *strPtr = &gDungeon->unk1BDD4;

    switch (strPtr->unk1C06C) {
        case 0:
            break;
        case 1:
            if (sub_800EC74())
                break;
            sub_803EAF0(3, 0);
        // fall through
        case 2: {
            struct UnkDrawStringStruct sp;
            s32 id = strPtr->unk1C062;
            if (id == strPtr->unk1C060) {
                strPtr->unk1C06C = 0;
            }
            else {
                const u8 *txtPtr = strPtr->unk0[id];

                sp.unk0 = 4;
                sp.unk2 = strPtr->unk1C066;
                sp.unk10 = 7;
                sub_80073B8(0);
                if (strPtr->unk1C054[id] != 0 && strPtr->unk1C066 >= 8) {
                    sub_80078A4(0, 0, strPtr->unk1C066 - 1, 0xE0, 7);
                }

                while (1) {
                    txtPtr = xxx_handle_format_global(txtPtr, &sp);
                    if (*txtPtr == '\0' || *txtPtr == '\r' || *txtPtr == '\n')
                        break;
                    txtPtr = xxx_get_next_char_from_string(txtPtr, &sp.unk34);
                    if (sp.unk34 == 96) {
                        sp.unk0 += 6;
                    }
                    else {
                        sp.unk0 += xxx_call_draw_char(sp.unk0, sp.unk2, sp.unk34, sp.unk10, 0);
                    }
                }
                sub_80073E0(0);
                strPtr->unk1C064 = 240;
                if (++id == UNK_1BBD4_STR_COUNT) {
                    id = 0;
                }
                strPtr->unk1C062 = id;
                strPtr->unk1C066 += 11;
                if (strPtr->unk1C066 >= 48) {
                    strPtr->unk1C066 = 37;
                    strPtr->unk1C068 = 0;
                    strPtr->unk1C06C = 3;
                }
            }
            break;
        }
    case 3:
        strPtr->unk1C068++;
        gUnknown_203B08C(0);
        if (strPtr->unk1C068 > 10) {
            strPtr->unk1C06C = 2;
        }
        break;
    }

    if (strPtr->unk1C05E == 0 && strPtr->unk1C064 != 0 && --strPtr->unk1C064 == 0) {
        strPtr->unk1C06C = 0;
        sub_803EAF0(0, 0);
        sub_8052210(0);
    }
}

