#include "global.h"

extern u8 gUnknown_2026E38;
extern u32 gUnknown_2026E3C;
extern u16 gUnknown_2026E4E;
extern bool32 gUnknown_2026E50;
extern bool32 gUnknown_2026E54;
extern u32 gUnknown_2026E58;
extern u8 gUnknown_2026E4C;
extern u32 gUnknown_203B078;

extern void SetBGPaletteBufferColorRGB(s32 index, u8 *RGBArray, s32 a1, u8 *a2);
void sub_8005770(s32 param_1, u8 *RGBArray, s32 a1, u8 *a2);

void sub_8005764(s32 param_1, u8 *RGBArrays[], s32 a1, u8 *a2)
{
    sub_8005770(param_1,RGBArrays[1],a1,a2);
}

void sub_8005770(s32 param_1, u8 *RGBArray, s32 a1, u8 *a2)
{
  s32 i;
  
  for(i = 0; i < 16; i++)
  {
    SetBGPaletteBufferColorRGB((param_1 + 0x10) * 0x10 + i,&RGBArray[i * 4],a1,a2);
  }
}

void nullsub_7(void)
{}

void nullsub_8(void)
{}

void nullsub_9(void)
{}

void nullsub_10(void)
{}

void nullsub_144(void)
{}

void nullsub_11(void)
{}

void nullsub_12(void)
{}

void nullsub_13(void)
{}

void nullsub_145(void)
{}

void nullsub_14(void)
{}

void nullsub_146(void)
{}

void nullsub_147(void)
{}

void nullsub_148(void)
{}

void nullsub_149(void)
{}

u32 sub_80057D8(void)
{
    return 0;
}

u32 sub_80057DC(void)
{
    return 0;
}

void nullsub_150(void)
{}

void nullsub_151(void)
{}


void sub_80057E8(void)
{
  gUnknown_2026E4C = 1;
  gUnknown_2026E54 = 0;
  gUnknown_2026E50 = 1;
  gUnknown_2026E58 = 0;
  gUnknown_2026E3C = 0;
  gUnknown_2026E38 = 0;
  gUnknown_2026E4E = 0x60c;
  gUnknown_203B078 = 0;
}
