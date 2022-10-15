#include "global.h"
#include "constants/colors.h"
#include "code_800D090.h"
#include "dungeon.h"
#include "text.h"

struct unkStruct_203B31C
{
    // Size: 0xD0
    s16 unk0[0x17];
    u32 unk30;
    u8 fill34[0x48 - 0x34];
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    u16 unk50;
    u16 unk52;
    u8 fill54[0x64 - 0x54];    
    u32 unk64;
    struct UnkTextStruct2 *unk68;
    struct UnkTextStruct2 unk6C[4];
    u8 unkCC[4];
};

extern struct unkStruct_203B31C *gUnknown_203B31C;


extern bool8 sub_8097504(s16);
extern s16 sub_80A26CC(s16 r0);
extern u8 gUnknown_80E081C[];
extern u8 gUnknown_80E0824[];
extern u8 gUnknown_80E0828[];
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern u8 sub_80A2740(s32 r0);
extern s16 sub_80A2668(u32 r0);
extern s32 sub_8013800(void *, u32);
extern bool8 IsMazeCompleted(s32);

void DrawDojoCourseList(void)
{
  u8 dungeonIndex;
  s32 sVar3;
  s32 y;
  s32 iVar6;
  u32 color;
  s32 index;
  u8 buffer [256];
  
  sub_8008C54(gUnknown_203B31C->unk64);
  sub_80073B8(gUnknown_203B31C->unk64);
  xxx_call_draw_string(10,0,gUnknown_80E081C,gUnknown_203B31C->unk64,0); // Courses
  sub_8012BC4(gUnknown_203B31C->unkCC[2] * 8 + 4,0,
            gUnknown_203B31C->unk4E + 1,2,7,gUnknown_203B31C->unk64);
  index = 0;
  if (index < gUnknown_203B31C->unk4A) {
    do {
      iVar6 = gUnknown_203B31C->unk0[gUnknown_203B31C->unk4E * gUnknown_203B31C->unk4C + index];
      dungeonIndex = sub_80A2740(iVar6);

      sVar3 = sub_80A2668(iVar6);

      y = sub_8013800(&gUnknown_203B31C->unk30, index);
      color = 7; // COLOR_WHITE again?
      if (IsMazeCompleted(sVar3)) {
        xxx_call_draw_string(8,y,gUnknown_80E0824,gUnknown_203B31C->unk64,0); // Draw Star symbol
        color = COLOR_GREEN;
      }
      sprintf_2(buffer,gUnknown_80E0828,color,GetDungeonName1(dungeonIndex)); // "#c%c%s#r"
      xxx_call_draw_string(0x10,y,buffer,gUnknown_203B31C->unk64,0);
      index++;
    } while (index < gUnknown_203B31C->unk4A);
  }
  sub_80073E0(gUnknown_203B31C->unk64);
}

s32 sub_8030668(void)
{
  s32 index;
  s32 counter;
  
  counter = 0;

  for(index = 0; index < 0x17; index++)
  {
    if (sub_8097504(index)) {
      gUnknown_203B31C->unk0[counter] = sub_80A26CC(index);
      counter++;
    }
  }
  return counter;
}

s32 sub_80306A4(void)
{
    return 0;
}

