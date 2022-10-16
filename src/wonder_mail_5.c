#include "global.h"
#include "memory.h"
#include "text.h"
#include "input.h"

struct unkStruct_203B324
{
    // size: 0x78
    u8 fill0[0xC];
    u8 unkC;
    u32 unk10;
    struct UnkTextStruct2 *unk14;
    struct UnkTextStruct2 unk18[4];
};
extern struct unkStruct_203B324 *gUnknown_203B324;


extern const struct UnkTextStruct2 gUnknown_80E091C;
extern const struct UnkTextStruct2 gUnknown_80E0900;
extern void sub_8030DD4(void);
extern void sub_801317C(void *);
extern void PlayMenuSoundEffect(u32);
extern u32 sub_8012A64(void *, u32);

void sub_8030E2C(void);
void sub_8030E48(void);

bool8 sub_8030D40(u8 param_1, s32 param_2)
{ 
  gUnknown_203B324 = MemoryAlloc(sizeof(struct unkStruct_203B324), 8);
  gUnknown_203B324->unkC = param_1;
  sub_801317C(gUnknown_203B324);
  gUnknown_203B324->unk10 = param_2;
  gUnknown_203B324->unk14 = &gUnknown_203B324->unk18[param_2];
  sub_8006518(gUnknown_203B324->unk18);
  gUnknown_203B324->unk18[gUnknown_203B324->unk10] = gUnknown_80E091C;
  sub_8030DD4();
  return TRUE;
}

u8 sub_8030DA0(void)
{ 
  switch(sub_8012A64(gUnknown_203B324, gUnknown_203B324->unk10))
  {
    case 2:
        PlayMenuSoundEffect(1);
        return 2;
    case 1:
        PlayMenuSoundEffect(0);
        return 3;
    default:
        return 0;
  }
}

void sub_8030DD4(void)
{
    sub_8030E2C();
    sub_8030E48();
}

void sub_8030DE4(void)
{ 
  if(gUnknown_203B324 != NULL)
  {
      gUnknown_203B324->unk18[gUnknown_203B324->unk10] = gUnknown_80E0900;
      ResetUnusedInputStruct();
      sub_800641C(gUnknown_203B324->unk18, 1, 1);
      MemoryFree(gUnknown_203B324);
      gUnknown_203B324 = NULL;
  }
}

void sub_8030E2C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B324->unk18, 1, 1);
}

