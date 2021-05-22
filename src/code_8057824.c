#include "global.h"
#include "gUnknown_203B418.h"
#include "code_8041D5C.h"

extern struct unkStruct_203B418 *gUnknown_203B418;

extern u32 gUnknown_80FCF74;
extern u32 gUnknown_80FCF80;
extern u16 gUnknown_80F4F42;

extern u32 gUnknown_8106A50;
extern u32 gUnknown_8106A4C;
extern s16 gUnknown_80F4DB6;
extern u32 gUnknown_80FAC88;

extern void sub_80775DC(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1, u32, u32);
extern void sub_80772C0(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1, u32, u32, u32);
extern u8 sub_807EAA0(u32, u32);
extern void sub_80522F4(struct unkDungeon_8041D5C *r1, struct unkDungeon_8041D5C *r2, u32);
extern void sub_8079F20(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1, u32, u32);

extern u8 sub_805727C(struct unkDungeon_8041D5C *, struct unkDungeon_8041D5C *, s16);
extern u32 sub_8055640(struct unkDungeon_8041D5C *, struct unkDungeon_8041D5C *, u32, u32, u32); 
extern void sub_80779F0(struct unkDungeon_8041D5C *, struct unkDungeon_8041D5C *, u32, u32);
extern void sub_8078968(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1);
extern void sub_8079618(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1, u32, u32, u32);

extern void sub_806F370(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);



extern u32 gUnknown_80FD018;
extern s16 sub_8057600(u32, u32);
extern u32 sub_8092B00(u32);

bool32 sub_8057824(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2)
{
    // Lower evasion?
  sub_80775DC(param_1,param_2,gUnknown_8106A50,1);
  return TRUE;
}

bool32 sub_805783C(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2)
{
    // Lower attack?
  sub_80772C0(param_1,param_2,gUnknown_8106A4C,0x80,1);
  return TRUE;
}

bool32 sub_805785C(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2)
{
  gUnknown_203B418->unkE26B = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == '\0') {
    // The weather remains unchanged
    sub_80522F4(param_1,param_2,gUnknown_80FCF74);
  }
  return TRUE;
}

bool32 sub_80578A4(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2)
{
  gUnknown_203B418->unkE26C = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == '\0') {
    // The weather remains unchanged
    sub_80522F4(param_1,param_2,gUnknown_80FCF80);
  }
  return TRUE;
}

bool32 sub_80578EC(struct unkDungeon_8041D5C *r0, struct unkDungeon_8041D5C *r1)
{
    sub_8079F20(r0, r1, 1, 0);
    return TRUE;
}

bool32 sub_80578FC(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2, u32 param_3, u32 param_4)
{
  bool32 uVar3;

  uVar3 = 0;
  if (sub_8055640(param_1, param_2, param_3, 0x80 << 1, param_4) != 0) {
    uVar3 = TRUE;
    if (sub_805727C(param_1,param_2, gUnknown_80F4DB6) != '\0') {
      sub_80779F0(param_1, param_2, 1, 0);
    }
  }
  return uVar3;
}

bool32 sub_8057948(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2)
{
    sub_8078968(param_1, param_2);
    return TRUE;
}

bool32 sub_8057954(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2, u32 param_3)
{
  // $m0 is enraged
  sub_8079618(param_1,param_2,0xc,param_3,gUnknown_80FAC88);
  return TRUE;
}

bool32 sub_8057974(struct unkDungeon_8041D5C *param_1, struct unkDungeon_8041D5C *param_2, u32 param_3, u32 param_4)
{
  s32 newHP;
  u8 local_24;

  newHP = param_2->unk70->HP / 2;
  local_24 = 0;
  if (newHP != 0) {
    sub_806F370(param_1,param_2,newHP,1,&local_24,sub_8092B00(param_3),sub_8057600(param_3,param_4),0,1,0);
    local_24 = local_24 == 0;
  }
  else
  {
    // The target's HP can't be halved anymore
    sub_80522F4(param_1,param_2,gUnknown_80FD018);
  }
  return local_24;
}
