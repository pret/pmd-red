#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_800D090.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon.h"
#include "text.h"
#include "structs/struct_sub80095e4.h"

struct unkStruct_203B274
{
    // size: 0x3e8
    PokemonStruct1 *pokeStruct;
    unkStruct_808E218_arg *unk4;
    unkStruct_808E218_arg unk8;
    struct_Sub80095E4_2 s348;
};
EWRAM_INIT struct unkStruct_203B274 *gUnknown_203B274 = {NULL};

static const Window sUnknown_80DC2AC = {
    0, 0, 0, 0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};
static const Window sUnknown_80DC2C4 = {
    0, 0, 0, 0,
    6,
    2, 2,
    0xF, 4,
    6, 0,
    NULL
};


ALIGNED(4) const u8 gUnknown_80DC2DC[] = _("Moves Page: %d/%d ");

u32 sub_801F7E4(void);
void sub_801F690(void);
void sub_801F700(void);


bool8 sub_801F428(s16 index, s32 param_2)
{
    s32 index_s32 = index;
    gUnknown_203B274 = MemoryAlloc(sizeof(struct unkStruct_203B274), 0x8);
    gUnknown_203B274->pokeStruct = &gRecruitedPokemonRef->pokemon[index_s32];
    gUnknown_203B274->unk4 = &gUnknown_203B274->unk8;
    gUnknown_203B274->s348.s0.unk34 = param_2;
    gUnknown_203B274->s348.s0.unk38 = &gUnknown_203B274->s348.s0.unk3C.a0[gUnknown_203B274->s348.s0.unk34];
    RestoreUnkTextStruct_8006518(&gUnknown_203B274->s348.s0.unk3C);
    gUnknown_203B274->s348.s0.unk3C.a0[gUnknown_203B274->s348.s0.unk34] = sUnknown_80DC2C4;
    gUnknown_203B274->s348.s0.unk38->unk14 = &gUnknown_203B274->s348.unk9C;
    gUnknown_203B274->s348.unk9C.f0 = 1;
    gUnknown_203B274->s348.unk9C.f1 = 0;
    gUnknown_203B274->s348.unk9C.f2 = 0xC;
    gUnknown_203B274->s348.unk9C.f3 = 0;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(&gUnknown_203B274->s348.s0.unk3C, TRUE, TRUE);
    sub_8013818(&gUnknown_203B274->s348.s0.input, sub_801F7E4(), 4, param_2);
    sub_801F690();
    sub_801F700();
    return TRUE;
}

u32 sub_801F520(u8 param_1)
{
    if (param_1 == 0) {
        sub_8013660(&gUnknown_203B274->s348.s0.input);
        return 0;
    }
    else {
        switch(GetKeyPress(&gUnknown_203B274->s348.s0.input))
        {
            case 2:
                PlayMenuSoundEffect(1);
                return 2;
            case 1:
                PlayMenuSoundEffect(0);
                return 3;
            case 4:
                PlayMenuSoundEffect(4);
                return 4;
            default:
                break;
        }
        if (sub_80138B8(&gUnknown_203B274->s348.s0.input,1) != 0) {
            sub_801F690();
            sub_801F700();
            return 1;
        }
        else {
            return 0;
        }
    }
}

u16 sub_801F5B4(void)
{
    return gUnknown_203B274->unk4->unk0[gUnknown_203B274->s348.s0.input.unk1E * gUnknown_203B274->s348.s0.input.unk1C + gUnknown_203B274->s348.s0.input.menuIndex];
}

void sub_801F5F0(bool8 r0)
{
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(&gUnknown_203B274->s348.s0.unk3C, FALSE, FALSE);
    sub_8013984(&gUnknown_203B274->s348.s0.input);
    sub_801F690();
    sub_801F700();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B274->s348.s0.input);
}

void sub_801F63C(void)
{
    if(gUnknown_203B274 != NULL)
    {
        gUnknown_203B274->s348.s0.unk3C.a0[gUnknown_203B274->s348.s0.unk34] = sUnknown_80DC2AC;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(&gUnknown_203B274->s348.s0.unk3C, TRUE, TRUE);
        MemoryFree(gUnknown_203B274);
        gUnknown_203B274 = NULL;
    }
}

void sub_801F690(void)
{
    SUB_80095E4_CALL(gUnknown_203B274->s348.s0);
}

void sub_801F700(void)
{
    u32 y;
    int index;
    u8 buffer2 [48];
    u8 buffer1 [128];

    CallPrepareTextbox_8008C54(gUnknown_203B274->s348.s0.unk34);
    sub_80073B8(gUnknown_203B274->s348.s0.unk34);
    sprintfStatic(buffer1,gUnknown_80DC2DC,gUnknown_203B274->s348.s0.input.unk1E + 1,gUnknown_203B274->s348.s0.input.unk20); // Moves Page: %d/%d
    PrintStringOnWindow(0x10,0,buffer1,gUnknown_203B274->s348.s0.unk34,0);
    for(index = 0; index < gUnknown_203B274->s348.s0.input.unk1A; index++)
    {
        sub_8092C84(buffer2,gUnknown_203B274->unk4->unk0[gUnknown_203B274->s348.s0.input.unk1E * gUnknown_203B274->s348.s0.input.unk1C + index]);
        y = sub_8013800(&gUnknown_203B274->s348.s0.input, index);
        PrintStringOnWindow(8,y,buffer2,gUnknown_203B274->s348.s0.unk34,0);
    }
    sub_80073E0(gUnknown_203B274->s348.s0.unk34);
}

u32 sub_801F7E4(void)
{
    sub_808E218(gUnknown_203B274->unk4, gUnknown_203B274->pokeStruct);
    return gUnknown_203B274->unk4->count;
}

