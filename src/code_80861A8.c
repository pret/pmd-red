#include "global.h"
#include "constants/direction.h"
#include "code_80861A8.h"

#include "code_803E668.h"
#include "code_806CD90.h"
#include "dungeon_music.h"

typedef struct unkStruct_80416E0
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 x;
    u16 y;
    u16 unk10;
    u16 unk12;
    s32 unk14;
    u32 unk18;
} unkStruct_80416E0;
extern s32 sub_800E890(unkStruct_80416E0 *);

struct unkStruct_8107380
{
    u8 unk0[12];
};
extern struct unkStruct_8107380 gUnknown_8107380;

extern const u8 *gUnknown_810665C[];
extern const u8 *gUnknown_810668C[];
extern const u8 *gUnknown_81066D4[];
extern const u8 *gUnknown_81066F0[];
extern const u8 *gUnknown_810671C[];

static void sub_80861EC(Entity *);

void sub_800EE5C(s32);
void sub_800EF64();
void sub_803E46C(s32);
s32 sub_800E700(s32);
void sub_800569C(Position *, axdata *, u8);
void sub_8085F44(void);

void sub_8052FB8(const u8 *); 

void sub_8086124(Entity *entity, u8 param_2)
{
    entity->axObj.info->unk160 = param_2;
}

void sub_8086130(void)
{
    DungeonFadeOutBGM(0x3c);
    sub_803E708(0x3c,0x46);
    sub_8052FB8(*gUnknown_810665C);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_810668C);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_81066D4);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_81066F0);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_810671C);
    sub_803E708(0x1e,0x46);
}

void sub_80861A8(Entity *a0)
{
    sub_806CDD4(a0, 0, NUM_DIRECTIONS);
}

void sub_80861B8(Entity *a0, u8 r1, s32 direction)
{
    EntityInfo *info;

    info = a0->axObj.info;

    sub_806CDD4(a0, r1, direction);
    info->unkFE = r1;
}

void sub_80861D4(Entity *a0, u8 r1, s32 direction)
{
    sub_806CDD4(a0, r1, direction);
    sub_80861EC(a0);
}

void sub_80861EC(Entity *a0)
{
    a0->axObj.info->unkFE = 0x63;
}

s32 sub_80861F8(s16 param_1,Entity *param_2,bool32 param_3)
{
  EntityInfo *info;
  s32 uVar2;
  s32 uStack_38;
  Position pos;
  unkStruct_80416E0 stack;
  struct unkStruct_8107380 stack4;

#ifdef NONMATCHING
  s32 param_1_s32 = param_1;
#else
  register s32 param_1_s32 asm("r5") = param_1;
#endif

  u8 param_3_bool32 = param_3;
    
  sub_800EE5C(param_1);
  sub_800EF64();
  sub_803E46C(0x46);
  info = param_2->axObj.info;
  pos.x = 0;
  pos.y = 0;
  uStack_38 = sub_800E700(param_1_s32);
  if (uStack_38 != -1) {
    sub_800569C(&pos,&param_2->axObj.axdata,
                uStack_38);
  }
  stack.unk0 = param_1_s32;
  stack.unk4 = 0;
  stack.unk8 = (u32)(info->action).direction;
  stack.x = (param_2->pixelPos).x / 256;
  stack.y = (param_2->pixelPos).y / 256;
    
  stack.unk10 = pos.x;
  stack.unk12 = pos.y;
  stack.unk14 = uStack_38;
  stack.unk18 = 0xffff;
  stack4 = gUnknown_8107380;

  uVar2 = sub_800E890(&stack);
  if (param_3_bool32 != '\0') {
    sub_8085F44();
    uVar2 = -1;
  }
  return uVar2;
}
