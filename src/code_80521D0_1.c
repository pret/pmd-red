#include "global.h"
#include "constants/species.h"

extern s16 *sub_8085480(void);
extern u32 sub_8085680(u32);
extern char gUnknown_202E038[0x50];
extern u8* gUnknown_203B418;

extern u32 gUnknown_8106778;
extern u32 gUnknown_81067BC;
extern u32 gUnknown_81067E0;
extern u32 gUnknown_8106834;
extern u32 gUnknown_810688C;
extern u32 gUnknown_81068D0;
extern u32 gUnknown_8106918;
extern u32 gUnknown_8106934;

extern void sub_8086A3C(void);
extern void CopySpeciesNametoBuffer(char *r0, u32 r1);
extern void sub_8083E88(u32);
extern void sub_80854D4(void);
extern void sub_80855E4(void *);
extern void sub_8085930(u32);
extern void sub_8068FE0(u32, u32, u32);
extern void sub_8085860(s16 r0, u32 r1);

extern void sub_803E708(u32, u32);
extern void sub_8052910(u32 *r0);
extern void sub_8086448(void);
extern void sub_8086598(void);
extern void sub_808696C();
extern void sub_80862BC(u32);
extern void sub_8083E38(u32);
extern void sub_806CDD4(u32, u32, u32);
extern void sub_80869E4(u32, u32, u32, u32);
extern void sub_806CE68(u32, u32);
extern void sub_804539C(u32, u32, u32);
extern void sub_803E46C(u32);
extern void sub_8042B0C(u32);
extern void sub_8085918(u32, u32);

void sub_808C9C4(void)
{
    s16 *array;
    u32 temp_2;

    array = sub_8085480();
    temp_2 = sub_8085680(7);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(0x4);
    sub_80855E4(sub_8086A3C);
    sub_8085918(temp_2, 0);
    sub_8085860(array[2], array[3] - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_MEDICHAM);
}

void sub_808CA1C(void)
{
    u32 temp;
    s32 counter;

    temp = sub_8085680(7);
    sub_808696C();
    sub_803E708(0xA, 0x46);
    sub_8052910(&gUnknown_8106778);
    sub_803E708(0xA, 0x46);
    sub_80869E4(temp, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    sub_8052910(&gUnknown_81067BC);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    sub_80862BC(temp);
    sub_803E708(0x20, 0x46);
    sub_80869E4(temp, 4, 2, 0);
    sub_8052910(&gUnknown_81067E0);
    sub_803E708(0xA, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    sub_806CE68(temp, 0);
    sub_803E708(0x4, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    sub_8052910(&gUnknown_8106834);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(temp, 0, 0);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(temp, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(temp, 0);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(temp);
    sub_8068FE0(temp, 0x87 << 2, 0);
    gUnknown_203B418[4] = 1;
    gUnknown_203B418[0x11] = 4;
}

void sub_808CB5C(void)
{
    s16 *array;
    u32 temp_2;

    array = sub_8085480();
    temp_2 = sub_8085680(7);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(0x4);
    sub_8068FE0(temp_2, 0x87 << 2, 0);
    sub_8085860(array[2], array[3]);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_MEDICHAM);
}

void nullsub_101(void)
{
}

void sub_808CBB0(void)
{
    s16 *array;
    u32 temp_2;

    array = sub_8085480();
    temp_2 = sub_8085680(0x1F);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(4);
    sub_80855E4(sub_8086A3C);
    sub_8085918(temp_2, 0);
    sub_8085860(array[2], array[3] - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SMEARGLE);
}

void sub_808CC04(void)
{
    u32 temp;
    s32 counter;

    temp = sub_8085680(0x1F);
    sub_808696C();
    sub_803E708(0xA, 0x46);
    sub_8052910(&gUnknown_810688C);
    sub_803E708(0xA, 0x46);
    sub_80869E4(temp, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    sub_8052910(&gUnknown_81068D0);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    sub_80862BC(temp);
    sub_803E708(0x20, 0x46);
    sub_80869E4(temp, 4, 2, 0);
    sub_8052910(&gUnknown_8106918);
    sub_803E708(0xA, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    sub_806CE68(temp, 0);
    sub_803E708(0x4, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    sub_8052910(&gUnknown_8106934);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(temp, 0, 0);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(temp, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(temp, 0);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(temp);
    sub_8068FE0(temp, 0x87 << 2, 0);
    gUnknown_203B418[4] = 1;
    gUnknown_203B418[0x11] = 4;

}

void sub_808CD44(void)
{
    s16 *array;
    u32 temp_2;

    array = sub_8085480();
    temp_2 = sub_8085680(0x1F);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(0x4);
    sub_80855E4(sub_8086A3C);
    sub_8068FE0(temp_2, 0x87 << 2, 0);
    sub_8085860(array[2], array[3] - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SMEARGLE);
}

