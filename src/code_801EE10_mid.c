#include "global.h"
#include "memory.h"
#include "text.h"
#include "pokemon.h"
#include "input.h"
#include "code_800D090.h"
#include "moves.h"
#include "code_801EE10.h"

extern struct unkStruct_203B270 *gUnknown_203B270;

struct unkStruct_203B274
{
    // size: 0x3e8
    struct PokemonStruct *pokeStruct;
    struct unkStruct_808E218_arg *unk4;
    struct unkStruct_808E218_arg unk8;
    u32 unk348;
    u8 fill34C[0x360 - 0x34C];
    s16 unk360;
    s16 unk362;
    s16 unk364;
    s16 unk366;
    s16 unk368;
    u8 fill36A[0x37C - 0x36A];
    s32 unk37C;
    struct UnkTextStruct2 *unk380;
    struct UnkTextStruct2 unk384[4];
    u8 unk3E4[4];
};
extern struct unkStruct_203B274 *gUnknown_203B274;
extern struct UnkTextStruct2 gUnknown_80DC2C4;
extern struct UnkTextStruct2 gUnknown_80DC2AC;

extern u8 gUnknown_80DC2DC[];

extern void sub_8013818(u32 *, u32, u32, u32);
extern s32 GetKeyPress(void *);
extern void sub_8013660(void *);
extern void AddMenuCursorSprite(void *);
extern u8 sub_80138B8(u32 *, u32);
extern void PlayMenuSoundEffect(u32);
extern void sub_8013984(void *);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern s32 sub_8013800(u32 *, s32);
extern void xxx_call_draw_string(s32, s32, u8 *, s32, s32);

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
    sub_800641C(gUnknown_203B274->unk384, 1, 1);
    sub_8013818(&gUnknown_203B274->unk348, sub_801F7E4(), 4, param_2);
    sub_801F690();
    sub_801F700();
    return 1;
}

u32 sub_801F520(u8 param_1)
{
    if (param_1 == 0) {
        sub_8013660(&gUnknown_203B274->unk348);
        return 0;
    }
    else {
        switch(GetKeyPress(&gUnknown_203B274->unk348))
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
        if (sub_80138B8(&gUnknown_203B274->unk348,1) != 0) {
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
    return gUnknown_203B274->unk4->unk0[gUnknown_203B274->unk366 * gUnknown_203B274->unk364 + gUnknown_203B274->unk360];
}

void sub_801F5F0(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B274->unk384, 0, 0);
    sub_8013984(&gUnknown_203B274->unk348);
    sub_801F690();
    sub_801F700();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B274->unk348);
}

void sub_801F63C(void)
{
    if(gUnknown_203B274 != NULL)
    {
        gUnknown_203B274->unk384[gUnknown_203B274->unk37C] = gUnknown_80DC2AC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B274->unk384, 1, 1);
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
    sprintfStatic(buffer1,gUnknown_80DC2DC,gUnknown_203B274->unk366 + 1,gUnknown_203B274->unk368); // Moves Page: %d/%d 
    xxx_call_draw_string(0x10,0,buffer1,gUnknown_203B274->unk37C,0);
    for(index = 0; index < gUnknown_203B274->unk362; index++)
    {
        sub_8092C84(buffer2,gUnknown_203B274->unk4->unk0[gUnknown_203B274->unk366 * gUnknown_203B274->unk364 + index]);
        y = sub_8013800(&gUnknown_203B274->unk348, index);
        xxx_call_draw_string(8,y,buffer2,gUnknown_203B274->unk37C,0);
    }
    sub_80073E0(gUnknown_203B274->unk37C);
}

u32 sub_801F7E4(void)
{
    sub_808E218(gUnknown_203B274->unk4, gUnknown_203B274->pokeStruct);
    return gUnknown_203B274->unk4->count;
}
