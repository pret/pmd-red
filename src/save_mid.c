#include "global.h"
#include "save.h"

extern struct UnkStruct_203B184 *gUnknown_203B184;
extern struct unkTimeStruct *gUnknown_203B47C;

struct unk_203B188
{
    u32 unk0;
    u32 unk4;
};

extern struct unk_203B188 *gUnknown_203B188;

extern u32 gUnknown_203B460;
extern u32 gUnknown_203B45C;
extern u32 gUnknown_203B480;
extern u32 gUnknown_203B484;
extern u32 gUnknown_203B488;
extern u32 gUnknown_203B48C;
extern u32 gUnknown_203B490;
extern u32 gUnknown_203B464;
extern u32 gUnknown_203B494;
extern u32 gUnknown_203B498;
extern u32 gUnknown_203B468;
extern u32 gUnknown_203B46C;

extern void sub_800135C(void);
extern u32 sub_808CE00(void);
extern void sub_808CE08(void);
extern u32 sub_80909D0(void);
extern void sub_80909D8(void);
extern u32 sub_809208C(void);
extern void sub_8092094(void);
extern u32 sub_80923B0(void);
extern void sub_80923B8(void);
extern u32 sub_8094990(void);
extern void sub_8094998(u8 r0);
extern u32 sub_80950F8(void);
extern u32 sub_8095100(void);
extern u32 sub_8095108(void);
extern u32 sub_8095110(void);
extern void sub_8095118(void);
extern u32 sub_80958F8(void);
extern void sub_8095900(void);
extern u32 sub_8097680(void);
extern void sub_80972F4(void);
extern void sub_80974E8(void);
extern u32 sub_8097F6C(void);
extern void sub_8097F74(void);

extern void sub_8011C28(u32 r0);
extern void sub_8011C40(s32 r0);
extern void sub_8097748(void);
extern void sub_8012240();


extern void sub_8094FA8(struct unkTimeStruct *Time); // defined in src/code_8094F88.c
extern struct unkTimeStruct *sub_8094FA0(void);

extern void* MemoryAlloc(u32 a, u32 b);

void sub_80122D0();
void sub_80122F4();
void sub_8012300();
void sub_80976A8();
void sub_80122A8();

void sub_8012284(void)
{
    sub_80122D0();
    sub_80122F4();
    sub_8012300();
}

void sub_8012298(void)
{
    sub_80976A8();
    sub_80122A8();
}

void sub_80122A8(void)
{
    sub_80122D0();
    sub_80122F4();
    sub_8012300();
    sub_8012240();

}

void nullsub_33(void)
{
}

void sub_80122C4(void)
{
    sub_80122A8();
}

void sub_80122D0(void)
{
    sub_8011C28(0);
    sub_8011C40(-1);
    sub_8097748();
    sub_8094FA8(gUnknown_203B47C);
}

void sub_80122F4(void)
{
    sub_800135C();
}

void sub_8012300(void)
{
    sub_80923B8();
    sub_808CE08();
    sub_80909D8();
    sub_8092094();
    sub_80972F4();
    sub_8095118();
    sub_8095900();
    sub_80974E8();
    sub_8094998(1);
    sub_8097F74();
}


// Unused
void nullsub_200(u32 r0)
{
}

// Unused
void sub_8012334(struct UnkStruct_203B184 *r0)
{
    gUnknown_203B184 = r0;
    if(r0 != NULL)
    {
       gUnknown_203B460 = r0->unk0;
       gUnknown_203B45C = r0->unk4;
       gUnknown_203B480 = r0->unk8;
       gUnknown_203B484 = r0->unkC;
       gUnknown_203B488 = r0->unk10;
       gUnknown_203B48C = r0->unk14;
       gUnknown_203B490 = r0->unk18;
       gUnknown_203B464 = r0->unk1C;
       gUnknown_203B494 = r0->unk20;
       gUnknown_203B498 = r0->unk24;
       gUnknown_203B468 = r0->unk28;
       gUnknown_203B46C = r0->unk2C;
       gUnknown_203B47C = r0->unk30;
       return;
    }
       gUnknown_203B460 = sub_80909D0();
       gUnknown_203B45C = sub_808CE00();
       gUnknown_203B480 = sub_80950F8();
       gUnknown_203B484 = sub_8095100();
       gUnknown_203B488 = sub_8095108();
       gUnknown_203B48C = sub_8095110();
       gUnknown_203B490 = sub_80958F8();
       gUnknown_203B464 = sub_809208C();
       gUnknown_203B494 = sub_8097680();
       gUnknown_203B498 = sub_8097F6C();
       gUnknown_203B468 = sub_80923B0();
       gUnknown_203B46C = sub_8094990();
       gUnknown_203B47C = sub_8094FA0();

}

void sub_8012468(void)
{
    gUnknown_203B188 = MemoryAlloc(sizeof(struct unk_203B188), 5);
    gUnknown_203B188->unk0 = 1;

}
