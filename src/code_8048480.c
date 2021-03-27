#include "global.h"
#include "code_8041D5C.h"

extern u32 gUnknown_80F89F4;
extern u8 gAvailablePokemonNames[0x58];
extern u32 gUnknown_80FB580;
extern s16 gUnknown_80F4FB6;
extern s16 gUnknown_80F4FB8;
extern s16 gUnknown_80F4FBA;
extern s16 gUnknown_80F4FBC;
extern s16 gUnknown_80F4FBE;

extern void sub_807D148(u32 r0, struct unkDungeon_8041D5C *r1, u32 r2, u32 r3);
extern void sub_8075FCC(u32 r0, struct unkDungeon_8041D5C *r1);
extern void sub_8077AE4(u32 r0, struct unkDungeon_8041D5C *r1, u32 r2);
extern void sub_8072008(u32 r0, struct unkDungeon_8041D5C *r1, u32 r2, u8 r3, u32);
extern void sub_8076D10(u32 r0, struct unkDungeon_8041D5C *r1);
extern void sub_807232C(u32 r0, struct unkDungeon_8041D5C *r1, u32 r2);

extern void sub_8045B94(u8 *r0, struct unkDungeon_8041D5C *r1, u32);
extern void sub_807A290(u32, struct unkDungeon_8041D5C *r1);
extern void sub_80522F4(u32 r0, struct unkDungeon_8041D5C *r1, u32);
extern void sub_8079270(u32 r0, struct unkDungeon_8041D5C *r1);
extern void sub_8077910(u32, struct unkDungeon_8041D5C *r1, u32, u32);
extern void sub_80791D8(u32, struct unkDungeon_8041D5C *r1);
extern void sub_8079140(u32, struct unkDungeon_8041D5C *r1);
extern void sub_8077C44(u32, struct unkDungeon_8041D5C *r1, s16, s16, u32);
extern void sub_80792F8(u32, struct unkDungeon_8041D5C *r1, u32);
extern void sub_8079F20(u32, struct unkDungeon_8041D5C *r1, u32, u8);
extern void sub_806F370(u32, struct unkDungeon_8041D5C *r1, u32, u32, u32, u32, u32, u32, u32, u32);

void sub_8048340(u32 r0, struct unkDungeon_8041D5C *r1, u32 r2)
{
    sub_806F370(r0, r1, r2, 1, 0, 0, 528, 0, 0, 0);
}

void sub_8048364(u32 r0, struct unkDungeon_8041D5C *r1, u8 r2)
{
    sub_8079F20(r0, r1, 1, r2);
}

void sub_8048374(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8077C44(r0, r1, gUnknown_80F4FB6, gUnknown_80F4FB8, 1);
}


void sub_804839C(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8077C44(r0, r1, gUnknown_80F4FBA, gUnknown_80F4FBC, 1);
}

void sub_80483C4(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_80792F8(r0, r1, 999);
}

void sub_80483D4(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8077C44(r0, r1, 0, gUnknown_80F4FBE, 1);
}

void sub_80483F4(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8079140(r0, r1);
}

void sub_8048400(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_80791D8(r0, r1);
}

void sub_804840C(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8077910(r0, r1, 0, 1);
}

void sub_804841C(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8079270(r0, r1);
}

void sub_8048428(u32 r0, struct unkDungeon_8041D5C *r1)
{
    if(r1->unk70->unkAC == 4)
        sub_807A290(r0, r1);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_8048450(u32 r0, struct unkDungeon_8041D5C *r1)
{
    if((u8)(r1->unk70->unkAC - 2) <= 1)
        sub_807A290(r0, r1);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_8048480(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_807D148(r0, r1, 0, 0);
}

void sub_8048490(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8075FCC(r0, r1);
}

void sub_804849C(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8077AE4(r0, r1, 1);
}

void sub_80484A8(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8072008(r0, r1, 1, 1, 1);
}

void sub_80484BC(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_8076D10(r0, r1);
}

void sub_80484C8(u32 r0, struct unkDungeon_8041D5C *r1)
{
    // Pointer to "But nothing happened!"
    sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_80484DC(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_807232C(r0, r1, 1);
}

void sub_80484E8(u32 r0, struct unkDungeon_8041D5C *r1)
{
    if(r1->unk70->unkAC == 1)
        sub_807A290(r0, r1);
    else
    {
        sub_8045B94(gAvailablePokemonNames, r1, 0);
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, gUnknown_80FB580);
    }
}
