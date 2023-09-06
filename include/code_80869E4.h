#ifndef GUARD_CODE_80869E4_H
#define GUARD_CODE_80869E4_H

#include "dungeon_entity.h"

struct unkStruct_202F3D0
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
};

void SpriteLookAroundEffect(Entity *);
void SpriteShockEffect(Entity *);

void sub_8086448(void);
void sub_8086500(void);
void sub_808654C(void);
void sub_8086598(void);
void sub_80865E8(void);
void sub_808663C(void);
void sub_8086690(void);
void sub_80866C4(const u8 *);
void sub_8086738(void);
void sub_8086764(void);
void sub_8086794(void);
void sub_80867F4(void);
void sub_808680C(void);
void sub_808682C(void);
void sub_8086838(u8, u8, u8);
void sub_8086848(u8, u8);
void sub_8086854(void);
void sub_80868F4(Entity *);
void sub_8086910(Entity *);
void sub_808692C(void);
void sub_80869E4(Entity *, s32, u8, s8);

#endif // GUARD_CODE_80869E4_H