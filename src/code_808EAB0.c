#include "global.h"

extern u32 gIQSkillNames[];
extern u32 gIQSkillDescriptions[];
extern u32 gTacticsDescriptions[];
extern u8 *gTactics[];
extern u8 gUnknown_810A36B[];

extern s16 gUnknown_810A378[];
extern s32 gUnknown_810A390[];

u32 sub_808EAB0(u8 r0)
{
    return gIQSkillNames[r0];
}

void sub_808EAC0(char *r0, u8 r1)
{
    strncpy(r0, gTactics[r1], 0x14);
}

u32 sub_808EADC(u8 r0)
{
    return gIQSkillDescriptions[r0];
}

u32 sub_808EAEC(u8 r0)
{
    return gTacticsDescriptions[r0];
}

u8 sub_808EAFC(u8 r0)
{
    return gUnknown_810A36B[r0];
}

void sub_808EB0C(u8 *r0, s32 r1)
{
    s32 counter;
    s32 storage;
    u32 index;
    storage = 0;
    index = 0;
    for(counter = 0; counter <= 0xB; counter++)
    {
        if(gUnknown_810A378[index] <= r1)
        {
            r0[storage] = counter;
            storage++;
        }
        index++;
    }
    if(storage > 0xB)
    {
        return;
    }
    while(storage <= 0xB)
    {
        r0[storage] = 0xB;
        storage++;
    }
}

#ifndef NONMATCHING
NAKED
#endif
void sub_808EB48(u8 *r0, s32 r1)
{
#ifdef NONMATCHING
    // TODO array access and counter are mixed up in the regs.. so close
    s32 counter;
    u32 index;

    index = 0;
    counter = 0xB;
    while(counter >= 0)
    {
        if(gUnknown_810A378[index] <= r1)
        {
            r0[index] = TRUE;
        }
        else
        {
            r0[index] = FALSE;
        }
        index++;
        counter--;
    }
#else
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tadds r4, r1, 0\n"
	"\tmovs r6, 0x1\n"
	"\tmovs r5, 0\n"
	"\tadds r2, r0, 0\n"
	"\tldr r1, _0808EB64\n"
	"\tmovs r3, 0xB\n"
"_0808EB56:\n"
	"\tmovs r7, 0\n"
	"\tldrsh r0, [r1, r7]\n"
	"\tcmp r0, r4\n"
	"\tbgt _0808EB68\n"
	"\tstrb r6, [r2]\n"
	"\tb _0808EB6A\n"
	"\t.align 2, 0\n"
"_0808EB64: .4byte gUnknown_810A378\n"
"_0808EB68:\n"
	"\tstrb r5, [r2]\n"
"_0808EB6A:\n"
	"\tadds r2, 0x1\n"
	"\tadds r1, 0x2\n"
	"\tsubs r3, 0x1\n"
	"\tcmp r3, 0\n"
	"\tbge _0808EB56\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0");
#endif
}

bool8 sub_808EB7C(s32 r0, u8 r1)
{
    u8 return_var;
    if(r1 == 0)
    {
        return FALSE;
    }

    return_var = FALSE;
    if(gUnknown_810A390[r1] <= r0)
    {
        return_var = TRUE;
    }
    return return_var;
}
