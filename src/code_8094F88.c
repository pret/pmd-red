#include "global.h"
#include "memory.h"

struct unkStruct_203B480
{
    //size of 48
    u8 unk0;
    u8 fill1[0x22 - 1];
    u8 unk22;
    u8 fill23[0x2D - 0x23];
    u8 unk2D;
};

struct unkStruct_203B48C
{
    s32 unk0;
    s32 unk4[0x20];
};

extern struct unkStruct_203B480 gUnknown_2038C88;
extern u8 gUnknown_2039288;
extern u32 gUnknown_20392E8;
extern struct unkStruct_203B48C gUnknown_20393C0;
extern u8 *gUnknown_203B484;
extern u32 *gUnknown_203B488;


extern struct unkStruct_203B480 *gUnknown_203B480;

extern struct unkStruct_203B48C *gUnknown_203B48C; // def a pointer


void sub_80950BC(void)
{
    gUnknown_203B480 = &gUnknown_2038C88;
    gUnknown_203B484 = &gUnknown_2039288;
    gUnknown_203B488 = &gUnknown_20392E8;
    gUnknown_203B48C = &gUnknown_20393C0;
}

struct unkStruct_203B480 *sub_80950F8(void)
{
    return &gUnknown_2038C88;
}

u8 *sub_8095100(void)
{
    return &gUnknown_2039288;
}

u32 *sub_8095108(void)
{
    return &gUnknown_20392E8;
}

struct unkStruct_203B48C *sub_8095110(void)
{
    return &gUnknown_20393C0;
}


#ifdef NONMATCHING
void sub_8095118(void)
{
  int iVar1;
  
  MemoryFill8((u8*)gUnknown_203B480,0,0x600);
  MemoryFill8(gUnknown_203B484,0,0x5c);
  for(iVar1 = 0; iVar1 < 0x20; iVar1++){
      // NOTE: when it adds the index regs flip
      // Instead of add r0, r0, r1 -> add r0, r1, r0
      // Everything else matches...
    gUnknown_203B480[iVar1].unk0 = 0;
    gUnknown_203B480[iVar1].unk22 = 0;
    gUnknown_203B480[iVar1].unk2D = 0;
  }
  gUnknown_203B48C->unk0 = 0;
  for(iVar1 = 0; iVar1 < 0x20; iVar1++){
    gUnknown_203B48C->unk4[iVar1] = -1;
  }
}
#else
NAKED
void sub_8095118(void)
{
	asm_unified("\tpush {r4,lr}\n"
	"\tldr r4, _0809517C\n"
	"\tldr r0, [r4]\n"
	"\tmovs r2, 0xC0\n"
	"\tlsls r2, 3\n"
	"\tmovs r1, 0\n"
	"\tbl MemoryFill8\n"
	"\tldr r0, _08095180\n"
	"\tldr r0, [r0]\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0x5C\n"
	"\tbl MemoryFill8\n"
	"\tmovs r2, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r3, 0x1F\n"
"_0809513A:\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, r1\n"
	"\tadds r0, 0x22\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, r1\n"
	"\tadds r0, 0x2D\n"
	"\tstrb r2, [r0]\n"
	"\tadds r1, 0x30\n"
	"\tsubs r3, 0x1\n"
	"\tcmp r3, 0\n"
	"\tbge _0809513A\n"
	"\tldr r2, _08095184\n"
	"\tldr r1, [r2]\n"
	"\tmovs r0, 0\n"
	"\tstr r0, [r1]\n"
	"\tmovs r3, 0\n"
	"\tmovs r4, 0x1\n"
	"\tnegs r4, r4\n"
"_08095166:\n"
	"\tldr r0, [r2]\n"
	"\tlsls r1, r3, 2\n"
	"\tadds r0, 0x4\n"
	"\tadds r0, r1\n"
	"\tstr r4, [r0]\n"
	"\tadds r3, 0x1\n"
	"\tcmp r3, 0x1F\n"
	"\tble _08095166\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0809517C: .4byte gUnknown_203B480\n"
"_08095180: .4byte gUnknown_203B484\n"
"_08095184: .4byte gUnknown_203B48C");
}
#endif

void nullsub_206(void)
{
}

void nullsub_207(void)
{
}

s32 sub_8095190(void)
{
  int index;
  
  for(index = 2; index < 0x20; index++){
    if(gUnknown_203B480[index].unk0 == 0)
        return index;
  }
  return -1;
}
