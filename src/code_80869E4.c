#include "global.h"
#include "dungeon_entity.h"
#include "gUnknown_203B418.h"
#include "random.h"

struct unkStruct_202F3D0
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
};

EWRAM_DATA struct unkStruct_202F3D0 gUnknown_202F3D0;
extern struct unkStruct_203B418 *gUnknown_203B418;

s8 sub_8002984(s8, u8);
void sub_803E708(u32, u32);
void sub_80869E4(struct DungeonEntity *r0, u32, u8, s8);
extern void sub_80859F0(u32);
extern void sub_803E46C(u32);
extern void sub_803E9D0(void);
extern void sub_8085C54(u32, u32, u32, u32, u32);
extern void PlaySoundEffect(u32);
extern struct DungeonEntity *sub_8085480(void);
void SpriteLookAroundEffect(struct DungeonEntity *r0);
extern void sub_8052910(u32);
void sub_8086494();

extern u32 gUnknown_8107314[];
extern u32 gUnknown_202EDC8;


extern void sub_8085EB0(void);
extern void sub_803E748(void);
extern void sub_80855E4(void *);
extern u32 sub_803F994(void);
extern u32 sub_803F9B0(void);
extern void sub_803F878(u32, u32);
extern void sub_8086384(struct DungeonEntity *r0);
extern void sub_8085930(u32);
extern void sub_804539C(struct DungeonEntity *, u32, u32);
extern void sub_806CE68(struct DungeonEntity *, u32);
extern void sub_806CDD4(struct DungeonEntity *, u8, u32);
extern void sub_804535C(struct DungeonEntity *, u32 *);
extern void sub_8086A54(struct DungeonEntity *);
extern void sub_8086A3C(struct DungeonEntity *);
extern void PlaySoundEffect(u32);
extern void sub_80861F8(u32, struct DungeonEntity *, u32);

void sub_80862BC(struct DungeonEntity *r0)
{
    PlaySoundEffect(0xE8 << 1);
    sub_80861F8(0x143, r0, 0);
}

void sub_80862DC(struct DungeonEntity *r0)
{
    u32 array[2];
    array[0] = r0->posPixelX;
    array[1] = r0->posPixelY + (0xE0 << 6);

    sub_804535C(r0, array);
    sub_806CDD4(r0, 0, 4);
    sub_8086A54(r0);
}

void sub_8086310(struct DungeonEntity *r0)
{
    u32 array[2];
    array[0] = r0->posPixelX;
    array[1] = r0->posPixelY + (0x90 << 8);

    sub_804535C(r0, array);
    sub_806CE68(r0, 0);
    sub_8086A3C(r0);
    r0->active = 0;
}

void sub_8086348(struct DungeonEntity *r0)
{
    u32 array[2];
    array[0] = r0->posPixelX + (0xF0 << 7);
    array[1] = r0->posPixelY + 0xffffe000;

    sub_804535C(r0, array);
    sub_806CDD4(r0, 0, 6);
    sub_8086A54(r0);
}

void sub_8086384(struct DungeonEntity *r0)
{
    u32 array[2];
    array[0] = r0->posPixelX + (0xF0 << 7);
    array[1] = r0->posPixelY;

    sub_804535C(r0, array);
    sub_806CDD4(r0, 0, 6);
    sub_8086A54(r0);
}

void sub_80863B8(struct DungeonEntity *r0)
{
    sub_806CDD4(r0, 0, 4);
}

void sub_80863C8(struct DungeonEntity *r0)
{
    sub_806CDD4(r0, 0, 0);
}

void sub_80863D8(struct DungeonEntity *r0)
{
    sub_806CDD4(r0, 0, 6);
}

void sub_80863E8(struct DungeonEntity *r0)
{
    sub_806CDD4(r0, 6, 4);
}

void sub_80863F8(struct DungeonEntity *r0)
{
    sub_806CE68(r0, 4);
}

void sub_8086404(struct DungeonEntity *r0)
{
    sub_806CE68(r0, 6);
}

void sub_8086410(struct DungeonEntity *r0)
{
    sub_804539C(r0, 0, 0xffffff00);
}

void sub_8086424(struct DungeonEntity *r0)
{
    sub_804539C(r0, 0, 0x80 << 1);
}

void sub_8086434(struct DungeonEntity *r0)
{
    sub_804539C(r0, 0xffffff00, 0);
}

void sub_8086448(void)
{
    s32 iVar1;
    u32 retVar;
    u32 retVar2;

    sub_80855E4(sub_80862DC);

    for(iVar1 = 0; iVar1 < 0x38; iVar1++)
    {
        retVar = sub_803F994();
        retVar2 = sub_803F9B0();
        retVar2 += (0x80 << 1);
        sub_803F878(retVar, retVar2);
        sub_80855E4(sub_8086410);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_80863F8);
}

void sub_8086494(void)
{
    s32 iVar1;

    sub_8085930(3);
    sub_803E708(4, 0x46);

    sub_8085930(2);
    sub_803E708(4, 0x46);

    sub_8085930(1);
    sub_803E708(4, 0x46);

    sub_8085930(0);
    sub_803E708(4, 0x46);

    sub_80855E4(sub_80863C8);
    for(iVar1 = 0; iVar1 < 0x90; iVar1++)
    {
        sub_80855E4(sub_8086424);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_8086310);
}

void sub_8086500(void)
{
    s32 iVar1;
    u32 retVar;
    u32 retVar2;

    sub_80855E4(sub_8086348);

    for(iVar1 = 0; iVar1 < 0x48; iVar1++)
    {
        retVar = sub_803F994();
        retVar += (0x80 << 1);
        retVar2 = sub_803F9B0();
        sub_803F878(retVar, retVar2);
        sub_80855E4(sub_8086434);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_8086404);
}

void sub_808654C(void)
{
    s32 iVar1;
    u32 retVar;
    u32 retVar2;

    sub_80855E4(sub_8086384);

    for(iVar1 = 0; iVar1 < 0x78; iVar1++)
    {
        retVar = sub_803F994();
        retVar += (0x80 << 1);
        retVar2 = sub_803F9B0();
        sub_803F878(retVar, retVar2);
        sub_80855E4(sub_8086434);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_8086404);
}

void sub_8086598(void)
{
    s32 iVar1;
    u32 retVar;
    u32 retVar2;

    sub_80855E4(sub_80863B8);

    for(iVar1 = 0; iVar1 < 0x18; iVar1++)
    {
        retVar = sub_803F994();
        retVar2 = sub_803F9B0();
        sub_803F878(retVar, retVar2 + (0xffffff00));
        sub_80855E4(sub_8086410);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_80863F8);
}

void sub_80865E8(void)
{
    s32 iVar1;
    u32 retVar;
    u32 retVar2;

    sub_80855E4(sub_80863E8);

    for(iVar1 = 0; iVar1 < 0xC; iVar1++)
    {
        retVar = sub_803F994();
        retVar2 = sub_803F9B0();
        sub_803F878(retVar, retVar2 + (0x80 << 2));
        sub_80855E4(sub_8086424);
        sub_80855E4(sub_8086424);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_80863F8);
}

void sub_808663C(void)
{
    s32 iVar1;
    u32 retVar;
    u32 retVar2;

    sub_80855E4(sub_80863E8);

    for(iVar1 = 0; iVar1 < 0x10; iVar1++)
    {
        retVar = sub_803F994();
        retVar2 = sub_803F9B0();
        sub_803F878(retVar, retVar2 + (0x80 << 2));
        sub_80855E4(sub_8086424);
        sub_80855E4(sub_8086424);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_80863F8);
}


void sub_8086690(void)
{
    s32 iVar1;

    sub_80855E4(sub_80863D8);

    for(iVar1 = 0; iVar1 < 0x30; iVar1++)
    {
        sub_80855E4(sub_8086434);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_8086404);
}


void sub_80866C4(u32 r0)
{

    SpriteLookAroundEffect(sub_8085480());
    sub_803E708(0xA, 0x46);
    sub_8052910(r0);
    sub_803E708(0xA, 0x46);
    sub_8086494();
    gUnknown_203B418->unk2 = 1;
}

void sub_80866FC(void)
{
    s32 iVar1;

    for(iVar1 = 0; iVar1 >= -0xFA; iVar1 -= 0xA)
    {
        sub_8085C54(iVar1, iVar1, iVar1, 1, 0);
        sub_803E46C(0x46);
    }
}

void sub_808627C(void)
{
    sub_803E748();
}

void sub_8086738(void)
{
    s32 iVar1;

    for(iVar1 = 0; iVar1 < 0xFA; iVar1 += 0xA)
    {
        sub_8085C54(iVar1, iVar1, iVar1, 1, 0);
        sub_803E46C(0x46);
    }
}

void sub_8086764(void)
{
    s32 iVar1;

    for(iVar1 = 0xFA; iVar1 >= 0; iVar1 -= 5)
    {
        sub_8085C54(iVar1, iVar1, iVar1, 1, 0);
        sub_803E46C(0x46);
    }
    sub_8085EB0();
}

void sub_8086794(void)
{
    s32 iVar1;

    gUnknown_202EDC8 = 0;

    for(iVar1 = 0; iVar1 < 0xC8; iVar1++)
    {
        sub_8085C54(0, 0, 0, 1, 0);
        sub_803E9D0();
        sub_803E46C(0x46);
        if((iVar1 & 3) == 0)
        {
            gUnknown_202EDC8++;
            if(gUnknown_202EDC8 == 0x1F)
                break;
        }
    }
    sub_803E46C(0x46);
    gUnknown_203B418->unk7 = 0;
}

void sub_80867F4(void)
{
    gUnknown_202F3D0.unk0 = 0;
    gUnknown_202F3D0.unk1 = 0;
    gUnknown_202F3D0.unk2 = 0;
    gUnknown_202F3D0.unk3 = 0;
    gUnknown_202F3D0.unk4 = 0;
    gUnknown_202F3D0.unk5 = 0;
}

void sub_808680C(void)
{
    gUnknown_202F3D0.unk0 = 1;
    if(gUnknown_202F3D0.unk3 != 0)
        PlaySoundEffect(0x1F9);
}

void sub_808682C(u8 r0)
{
    gUnknown_202F3D0.unk0 = 0;
}

void sub_8086838(u8 r0, u8 r1, u8 r2)
{
    gUnknown_202F3D0.unk1 = r0;
    gUnknown_202F3D0.unk2 = r1;
    gUnknown_202F3D0.unk3 = r2;
}

void sub_8086848(u8 r0, u8 r1)
{
    gUnknown_202F3D0.unk4 = r0;
    gUnknown_202F3D0.unk5 = r1;
}

void sub_8086854(void)
{
    if(gUnknown_202F3D0.unk0 != 0)
    {
        if(gUnknown_202F3D0.unk4 == 0)
        {
            if(gUnknown_202F3D0.unk1 != 0)
            {
                gUnknown_202F3D0.unk4 = 0x50;
                gUnknown_202F3D0.unk5 = 0x10;
            }
            else
            {
                gUnknown_202F3D0.unk4 = RandomCapped(0x6) + 2;
                gUnknown_202F3D0.unk5 = RandomCapped(0x6) + 2;
            }
            if(gUnknown_202F3D0.unk3 != 0)
                PlaySoundEffect(0x1F9);
        }
        else
        {
            gUnknown_202F3D0.unk4--;
        }
        if(gUnknown_202F3D0.unk5 != 0)
            gUnknown_202F3D0.unk5--;
        gUnknown_203B418->unk181FC = gUnknown_8107314[gUnknown_202F3D0.unk5];
    }
    else
    {
        gUnknown_203B418->unk181FC = 0;
    }
}

void sub_80868F4(struct DungeonEntity *r0)
{
    r0->unk70->unk15C = 1;
    r0->unk70->unk15D = 1;
}

void sub_8086910(struct DungeonEntity *r0)
{
    r0->unk70->unk15C = 0;
    r0->unk70->unk15D = 0;
}

void sub_808692C(void)
{
    sub_80859F0(5);
    sub_803E708(0x4, 0x46);

    sub_80859F0(6);
    sub_803E708(0x4, 0x46);

    sub_80859F0(7);
    sub_803E708(0x4, 0x46);

    sub_80859F0(0);
    sub_803E708(0x4, 0x46);
}

void SpriteLookAroundEffect(struct DungeonEntity *r0)
{
    s8 r4;
    s8 r3;

    r4 = sub_8002984(r0->unk70->facingDir, 4);

    sub_80869E4(r0, 4, 2, r4);

    sub_803E708(0xF, 0x46);

    r4 = sub_8002984(r4, 5);

    sub_80869E4(r0, 4, 1, r4);

    sub_803E708(0xF, 0x46);

    r3 = sub_8002984(r4, 4);

    sub_80869E4(r0, 4, 2, r3);

    sub_803E708(0xF, 0x46);
}
