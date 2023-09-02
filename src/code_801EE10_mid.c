#include "global.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "pokemon.h"
#include "code_800D090.h"
#include "moves.h"
#include "code_801EE10.h"
#include "menu_input.h"
#include "subStruct_203B240.h"
#include "sprite.h"
#include "code_80130A8.h"
#include "code_801EE10_mid.h"
#include "code_80118A4.h"

extern unkStruct_203B270 *gUnknown_203B270;

struct unkStruct_203B274
{
    // size: 0x3e8
    PokemonStruct1 *pokeStruct;
    unkStruct_808E218_arg *unk4;
    unkStruct_808E218_arg unk8;
    MenuInputStruct input;
    s32 unk37C;
    UnkTextStruct2 *unk380;
    UnkTextStruct2 unk384[4];
    u8 unk3E4[4];
};
extern struct unkStruct_203B274 *gUnknown_203B274;

struct unkStruct_203B278
{
    s32 state;
    u16 *moveIDs;
    u16 unk8;
    u16 fillA;
    s32 unkC;
    s32 unk10;
    struct subStruct_203B240 *unk14[4];
    u32 unk24;
    MenuInputStruct unk28;
    u32 unk5C;
    UnkTextStruct2 *unk60;
    UnkTextStruct2 unk64[4];
    u8 unkC4[4];
    MenuInputStructSub unkC8;
};

extern struct unkStruct_203B278 *gUnknown_203B278;

extern UnkTextStruct2 gUnknown_80DC2C4;
extern UnkTextStruct2 gUnknown_80DC2AC;
extern UnkTextStruct2 gUnknown_80DC2F8;

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_80DC310[];
extern u8 gUnknown_80DC2DC[];

extern void sub_80140B4(UnkTextStruct2 *);
extern void sub_801F918(s32);
extern void sub_801FA58(void);
extern void sub_801FAD4(void);
extern void sub_801F930(void);
extern void sub_801F9A4(void);
void sub_8013F84(void);


u32 sub_801F7E4(void);
void sub_801F690(void);
void sub_801F700(void);

s32 sub_801F3F8(void)
{
  struct Move *move;
  int index;
  s32 counter;

  counter = 0;
  for(index = 0; index < 8; index++)
  {
    move = &gUnknown_203B270->moves[index];
    if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
      counter++;
    }
  }
  return counter;
}

bool8 sub_801F428(s16 index, s32 param_2) {

    s32 index_s32 = index;
    gUnknown_203B274 = MemoryAlloc(sizeof(struct unkStruct_203B274), 0x8);
    gUnknown_203B274->pokeStruct = &gRecruitedPokemonRef->pokemon[index_s32];
    gUnknown_203B274->unk4 = &gUnknown_203B274->unk8;
    gUnknown_203B274->unk37C = param_2;
    gUnknown_203B274->unk380 = &gUnknown_203B274->unk384[gUnknown_203B274->unk37C];
    sub_8006518(gUnknown_203B274->unk384);
    gUnknown_203B274->unk384[gUnknown_203B274->unk37C] = gUnknown_80DC2C4;
    gUnknown_203B274->unk380->unk14 = gUnknown_203B274->unk3E4;
    gUnknown_203B274->unk3E4[0] = 1;
    gUnknown_203B274->unk3E4[1] = 0;
    gUnknown_203B274->unk3E4[2] = 0xC;
    gUnknown_203B274->unk3E4[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B274->unk384, TRUE, TRUE);
    sub_8013818(&gUnknown_203B274->input, sub_801F7E4(), 4, param_2);
    sub_801F690();
    sub_801F700();
    return TRUE;
}

u32 sub_801F520(u8 param_1)
{
    if (param_1 == 0) {
        sub_8013660(&gUnknown_203B274->input);
        return 0;
    }
    else {
        switch(GetKeyPress(&gUnknown_203B274->input))
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
        if (sub_80138B8(&gUnknown_203B274->input,1) != 0) {
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
    return gUnknown_203B274->unk4->unk0[gUnknown_203B274->input.unk1E * gUnknown_203B274->input.unk1C + gUnknown_203B274->input.menuIndex];
}

void sub_801F5F0(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B274->unk384, FALSE, FALSE);
    sub_8013984(&gUnknown_203B274->input);
    sub_801F690();
    sub_801F700();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B274->input);
}

void sub_801F63C(void)
{
    if(gUnknown_203B274 != NULL)
    {
        gUnknown_203B274->unk384[gUnknown_203B274->unk37C] = gUnknown_80DC2AC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B274->unk384, TRUE, TRUE);
        MemoryFree(gUnknown_203B274);
        gUnknown_203B274 = NULL;
    }
}

NAKED
void sub_801F690(void)
{
    asm_unified(
	"\tpush {r4,r5,lr}\n"
	"\tldr r5, _0801F6F4\n"
	"\tldr r0, [r5]\n"
	"\tldr r1, _0801F6F8\n"
	"\tadds r0, r1\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r0, r2]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r3, [r5]\n"
	"\tmovs r1, 0xDF\n"
	"\tlsls r1, 2\n"
	"\tadds r4, r3, r1\n"
	"\tldr r2, [r4]\n"
	"\tlsls r1, r2, 1\n"
	"\tadds r1, r2\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r3, r1\n"
	"\tldr r2, _0801F6FC\n"
	"\tadds r1, r2\n"
	"\tasrs r2, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r4]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r3, r0\n"
	"\tadds r2, 0x2\n"
	"\tmovs r0, 0xE5\n"
	"\tlsls r0, 2\n"
	"\tadds r3, r0\n"
	"\tstrh r2, [r3]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r5]\n"
	"\tmovs r1, 0xE1\n"
	"\tlsls r1, 2\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801F6F4: .4byte gUnknown_203B274\n"
"_0801F6F8: .4byte 0x00000362\n"
"_0801F6FC: .4byte 0x00000392");
}

void sub_801F700(void)
{
    u32 y;
    int index;
    u8 buffer2 [48];
    u8 buffer1 [128];

    sub_8008C54(gUnknown_203B274->unk37C);
    sub_80073B8(gUnknown_203B274->unk37C);
    sprintfStatic(buffer1,gUnknown_80DC2DC,gUnknown_203B274->input.unk1E + 1,gUnknown_203B274->input.unk20); // Moves Page: %d/%d 
    xxx_call_draw_string(0x10,0,buffer1,gUnknown_203B274->unk37C,0);
    for(index = 0; index < gUnknown_203B274->input.unk1A; index++)
    {
        sub_8092C84(buffer2,gUnknown_203B274->unk4->unk0[gUnknown_203B274->input.unk1E * gUnknown_203B274->input.unk1C + index]);
        y = sub_8013800(&gUnknown_203B274->input, index);
        xxx_call_draw_string(8,y,buffer2,gUnknown_203B274->unk37C,0);
    }
    sub_80073E0(gUnknown_203B274->unk37C);
}

u32 sub_801F7E4(void)
{
    sub_808E218(gUnknown_203B274->unk4, gUnknown_203B274->pokeStruct);
    return gUnknown_203B274->unk4->count;
}

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

s32 sub_801F890(void)
{
    switch(gUnknown_203B278->state)
    {
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
        gUnknown_203B278->unk64[gUnknown_203B278->unk5C] = gUnknown_80DC2F8;
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
            gUnknown_203B278->unk60->unk14 = gUnknown_203B278->unkC4;
            gUnknown_203B278->unkC4[0] = gUnknown_203B278->unk28.unk20;
            gUnknown_203B278->unkC4[1] = gUnknown_203B278->unk28.unk1E;
            gUnknown_203B278->unkC4[2] = 0x10;
            gUnknown_203B278->unkC4[3] = 0;
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
    char **name;
    switch(gUnknown_203B278->state)
    {
        case 0:
            sub_8008C54(gUnknown_203B278->unk5C);
            gUnknown_203B278->unk8 = gUnknown_203B278->moveIDs[gUnknown_203B278->unk28.unk1E];
            gUnknown_203B278->unk10 = unk_MoveIDPrintMoveDescription(gUnknown_203B278->unk28.unk1E,gUnknown_203B278->unk8,gUnknown_203B278->unk5C,gUnknown_203B278->unk14);
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
