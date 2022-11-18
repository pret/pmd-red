#include "global.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"

extern void sub_804151C(struct DungeonEntity *r0, u32 r1, u8 r2);
extern void sub_803E708(u32 r0, u32 r1);
extern void sub_80416A4(struct DungeonEntity *r0, u32 r1, u32 r2);
extern void sub_80421C0(struct DungeonEntity *r0, u16 r1);
extern u8 sub_8042768(struct DungeonEntity *pokemon);
extern void sub_804178C(u32);
extern void sub_804151C(struct DungeonEntity *pokemon, u32 r1, u8 r2);
extern void sub_803E46C(u32);

void sub_80428A0(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x29, 1);
}

void sub_80428B0(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}


void sub_80428C4(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}


void sub_80428D8(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_80428EC(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_8042900(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0xD4 << 1, 0);
}

void ShowVisualFlags(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x29, 0);
}

void sub_8042920(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x48, 0);
}

void sub_8042930(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0xD3 << 1, 1);
}

void sub_8042940(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0xC7 << 1, 0);
}

void sub_8042950(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0xD8 << 1, 1);
    sub_803E708(0xA, 0x42);
}

void sub_8042968(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0xD4 << 1, 0);
}

void sub_8042978(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_804298C(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_80429A0(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x199, 0);
}

void sub_80429B4(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x1ab, 0);
}

void sub_80429C8(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x4, 1);
}

void sub_80429D8(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x8F << 1, 1);
}

void sub_80429E8(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x11d, 1);
}

void sub_80429FC(struct DungeonEntity *r0)
{
    sub_80416A4(r0, 0xCF << 1, 1);
    sub_80421C0(NULL, 0xD4);
}

void sub_8042A14(struct DungeonEntity *r0)
{
    sub_80416A4(r0, 0x36, 1);
}

void sub_8042A24(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8042A34(struct DungeonEntity *r0)
{
    sub_80416A4(r0, 0x9F << 1, 0);
}

void sub_8042A44(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0xDA << 1, 1);
}

void sub_8042A54(struct DungeonEntity *r0)
{
    sub_80416A4(r0, 0x37, 1);
}

void sub_8042A64(struct DungeonEntity *r0)
{
    sub_80416A4(r0, 0x29, 1);
}

void sub_8042A74(struct DungeonEntity *r0)
{
    sub_804151C(r0, 0x18, 1);
}

void sub_8042A84(s16 param_1, struct DungeonEntity *entity, u32 param_3)
{
  s32 iVar2;
  s32 iVar3;
  s32 r6;
  s32 param_1_s16;

  param_1_s16 = param_1;
  
  r6 = 0x200;
  if (sub_8042768(entity) != 0) {
    sub_804151C(entity,param_1_s16,0);
    sub_803E708(param_3,0x42);
    do {
      if (0xc7ff < entity->unk1C) break;
      sub_803E46C(0x42);
      iVar2 = entity->unk1C + r6;
      entity->unk1C = iVar2;
      r6 += 0x100;
      iVar3 = entity->posPixel.y - iVar2;
      if (iVar3 < 0) {
        iVar3 += 0xff;
      }
    } while (-8 <= (iVar3 >> 8) - gDungeonGlobalData->posScreenPixel.y);
    entity->visible = 0;
    sub_804178C(0);
  }
}

void sub_8042B0C(struct DungeonEntity *entity)
{
    sub_8042A84(0x13e, entity, 5);
}

void sub_8042B20(struct DungeonEntity *entity)
{
    sub_8042A84(0x1BC, entity, 0xE);
}
