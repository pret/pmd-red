#include "global.h"
#include "globaldata.h"
#include "code_80130A8.h"
#include "code_80118A4.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "sprite.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "text1.h"
#include "text2.h"

extern u8 gAvailablePokemonNames[];

// TODO: UNIFY WITH struct_Sub80095E4
struct unkStruct_203B278
{
    /* 0x0 */ s32 state;
    /* 0x4 */ u16 *moveIDs;
    /* 0x8 */ u16 selectedMoveID;
    s32 unkC;
    s32 unk10;
    struct subStruct_203B240 *unk14[4];
    u32 unk24;
    MenuInputStruct unk28;
    u32 unk5C;
    UnkTextStruct2 *unk60;
    UnkTextStruct2 unk64[4];
    UnkTextStruct2_sub2 unkC4;
    MenuInputStructSub unkC8;
};

extern struct unkStruct_203B278 *gUnknown_203B278;

static const UnkTextStruct2 sUnknown_80DC2F8 = {
    0, 0, 0, 0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};

const u8 gUnknown_80DC310[] = _("{ARG_POKEMON_0}");

extern void sub_801F918(s32);
extern void sub_801FA58(void);
extern void sub_801FAD4(void);
extern void sub_801F930(void);
extern void sub_801F9A4(void);

bool8 sub_801F808(u16 *moveIDs)
{
    s32 index;

    ResetSprites(TRUE);
    gUnknown_203B278 = MemoryAlloc(sizeof(struct unkStruct_203B278), 8);
    gUnknown_203B278->unk5C = 0;
    gUnknown_203B278->unk60 = gUnknown_203B278->unk64;
    sub_80140B4(gUnknown_203B278->unk64);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B278->unk64, TRUE, TRUE);
    gUnknown_203B278->moveIDs = moveIDs;

    for(index = 4; index > 1; index--)
    {
        if(gUnknown_203B278->moveIDs[index - 1] != 0) break;
    }
    sub_8013818(&gUnknown_203B278->unk28,index,1,gUnknown_203B278->unk5C);
    sub_801317C(&gUnknown_203B278->unkC8);
    sub_801F918(0);
    return 1;
}

u32 sub_801F890(void)
{
    switch (gUnknown_203B278->state) {
        case 0:
            sub_801FA58();
            break;
        case 1:
            sub_801FAD4();
            break;
        case 3:
            return 3;
        default:
        case 2:
            return 2;
    }
    return 0;
}

void sub_801F8D0(void)
{
    if(gUnknown_203B278)
    {
        gUnknown_203B278->unk64[gUnknown_203B278->unk5C] = sUnknown_80DC2F8;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B278->unk64, TRUE, TRUE);
        MemoryFree(gUnknown_203B278);
        gUnknown_203B278 = NULL;
    }
}

void sub_801F918(s32 newState)
{
    gUnknown_203B278->state = newState;
    sub_801F930();
    sub_801F9A4();
}

void sub_801F930(void)
{
    sub_80140B4(gUnknown_203B278->unk64);
    switch(gUnknown_203B278->state)
    {
        case 0:
            gUnknown_203B278->unk60->unk14 = &gUnknown_203B278->unkC4;
            gUnknown_203B278->unkC4.f0 = gUnknown_203B278->unk28.unk20;
            gUnknown_203B278->unkC4.f1 = gUnknown_203B278->unk28.unk1E;
            gUnknown_203B278->unkC4.f2 = 0x10;
            gUnknown_203B278->unkC4.f3 = 0;
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B278->unk64, TRUE, TRUE);
            break;
        case 1:
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B278->unk64, TRUE, TRUE);
            break;
        default:
            break;
    }
}

void sub_801F9A4(void)
{
    u8 **name;

    switch (gUnknown_203B278->state) {
        case 0:
            sub_8008C54(gUnknown_203B278->unk5C);
            gUnknown_203B278->selectedMoveID = gUnknown_203B278->moveIDs[gUnknown_203B278->unk28.unk1E];
            gUnknown_203B278->unk10 = unk_MoveIDPrintMoveDescription(gUnknown_203B278->unk28.unk1E,gUnknown_203B278->selectedMoveID,gUnknown_203B278->unk5C,gUnknown_203B278->unk14);
            gUnknown_203B278->unk24 = 0;
            break;
        case 1:
            sub_8008C54(gUnknown_203B278->unk5C);
            sub_80073B8(gUnknown_203B278->unk5C);
            name = &(gUnknown_203B278->unk14[gUnknown_203B278->unkC]->pokeName);
            strcpy(gAvailablePokemonNames, *name);
            xxx_format_and_draw(0x10,0,gUnknown_80DC310,gUnknown_203B278->unk5C,0); // $m0
            xxx_format_and_draw(4,0x10,gUnknown_203B278->unk14[gUnknown_203B278->unkC]->unk4,gUnknown_203B278->unk5C,0);
            sub_80073E0(gUnknown_203B278->unk5C);
            break;
        case 2:
            break;
    }
}

void sub_801FA58(void)
{
    if(gUnknown_203B278->unk10 != 0)
    {
        if(gUnknown_203B278->unk24 & 8)
        {
            sub_8013F84();
        }
        gUnknown_203B278->unk24++;
    }
    switch(sub_8012A64(&gUnknown_203B278->unkC8, gUnknown_203B278->unk5C))
    {
        case 1:
            PlayMenuSoundEffect(0);
            if(gUnknown_203B278->unk10 != 0)
            {
                gUnknown_203B278->unkC = 0;
                sub_801F918(1);
            }
            else
            {
                sub_801F918(3);
            }
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801F918(2);
            break;
        default:
            if(sub_8013938(&gUnknown_203B278->unk28))
            {
                sub_801F918(0);
            }
    }
}

void sub_801FAD4(void)
{
    if(gUnknown_203B278->unkC < gUnknown_203B278->unk10 - 1)
    {
        if(gUnknown_203B278->unk24 & 8)
        {
            sub_8013F84();
        }
        gUnknown_203B278->unk24++;
    }
    switch(sub_8012A64(&gUnknown_203B278->unkC8, gUnknown_203B278->unk5C))
    {
        case 1:
            PlayMenuSoundEffect(0);
            gUnknown_203B278->unkC++;
            if(gUnknown_203B278->unkC < gUnknown_203B278->unk10)
            {
                sub_801F918(1);
            }
            else {
                sub_801F918(0);
            }
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801F918(2);
            break;
    }
}

