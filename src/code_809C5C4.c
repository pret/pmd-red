#include "global.h"
#include "memory.h"
#include "game_options.h"
#include "ground_main.h"

struct unkStruct_3001B68  
{ 
     u32 unk0;
     u32 unk4;     
     u16 unk8;     
     u16 unkA;     
     u8  unkC;                   
     u8  unkD;
     u8  unkE;     
     u32 unk10;   
     u16 unk14;   
     u16 unk16;   
     u8  unk18;
     u8  unk19;   
     u32 unk1C;   
     u8  unk20;   
};

extern struct unkStruct_3001B68 *gUnknown_3001B68;

void sub_809C63C();
u8 sub_809C740(void);
void nullsub_107();
void nullsub_108();
void nullsub_109();
void nullsub_110();
void nullsub_111();
void nullsub_112();
void nullsub_113();
void nullsub_114();
void nullsub_115();
void nullsub_116();

void sub_809C5C4(void)
{
    gUnknown_3001B68 = MemoryAlloc(sizeof(struct unkStruct_3001B68), 6);
    gUnknown_3001B68->unk0 = 0;
    gUnknown_3001B68->unk4 = 0;
    gUnknown_3001B68->unk8 = 0;
    gUnknown_3001B68->unkA = 0;
    gUnknown_3001B68->unkD = 0;
    gUnknown_3001B68->unkE = 0;
    gUnknown_3001B68->unk10 = 0;
    gUnknown_3001B68->unk14 = 0xffff;
    gUnknown_3001B68->unk16 = 0x23;
    gUnknown_3001B68->unk18 = 0;
    gUnknown_3001B68->unk19 = 0x3f;
    gUnknown_3001B68->unk1C = 0;
    gUnknown_3001B68->unk20 = 0;
    nullsub_107();
    sub_809C63C();
}

void sub_809C618(void)
{
    sub_809C63C();
    nullsub_107();
    nullsub_108();
    MemoryFree(gUnknown_3001B68);
    gUnknown_3001B68 = NULL;
}

void sub_809C63C(void)
{
    nullsub_108();
    gUnknown_3001B68->unk1C = 0;
    gUnknown_3001B68->unk20 = 0;
}

void sub_809C658(void)
{
    switch(gUnknown_3001B68->unkA) {
        case 3:
            nullsub_111();
            nullsub_112();
            nullsub_113();
            break;
        case 4:
            nullsub_114();
            nullsub_115();
            nullsub_116();
            break;
        case 2:
            nullsub_109();
            nullsub_110();
            break;
        case 5:
            nullsub_107();
            nullsub_108();
            break;
        case 0:
        case 1:
            nullsub_107();
            nullsub_108();
            break;
    }
}

void sub_809C6CC(u16 param_1)
{
    if(gUnknown_3001B68->unk8 != param_1)
    {
        gUnknown_3001B68->unk8 = param_1;
        gUnknown_3001B68->unkE = 0;
    }
}

void sub_809C6EC(void)
{
    if (sub_8098F88() == 0) {
        if (gGameOptionsRef->unkC == 0) {
            sub_809C6CC(4);
        }
        else {
            sub_809C6CC(3);
        }
    }
    else {
        sub_809C6CC(5);
    }
}

u16 sub_809C724(void)
{
    return gUnknown_3001B68->unk8;
}

u8 sub_809C730(void)
{
   return sub_809C740();
}

u8 sub_809C740(void)
{
  if(gUnknown_3001B68->unk0 == 0)
        return 1;
  else
        return 0;
}

void nullsub_104(void)
{ }

void sub_809C760(void)
{
    gUnknown_3001B68->unkE = 1;
}
