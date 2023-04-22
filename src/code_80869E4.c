#include "global.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "random.h"
#include "constants/direction.h"

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

s8 sub_8002984(s8, u8);
void sub_803E708(u32, u32);
void sub_80869E4(struct Entity *entity, u32, u8, s8);
extern void sub_80859F0(u32);
extern void sub_803E46C(u32);
extern void sub_803E9D0(void);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);
extern void PlaySoundEffect(u32);
extern struct Entity *xxx_call_GetLeader(void);
void SpriteLookAroundEffect(struct Entity *entity);
extern void DisplayDungeonDialogue(u32);
void sub_8086494();

extern u32 gUnknown_8107314[];
extern u32 gUnknown_202EDC8;


extern void sub_8085EB0(void);
extern void sub_803E748(void);
extern void sub_80855E4(void *);
extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F878(u32, u32);
extern void sub_8086384(struct Entity *entity);
extern void sub_8085930(u32);
extern void IncreaseEntityPixelPos(struct Entity *, u32, u32);
extern void sub_806CE68(struct Entity *, u32);
extern void sub_806CDD4(struct Entity *, u8, u32);
extern void sub_804535C(struct Entity *, struct Position32 *);
extern void sub_8086A54(struct Entity *);
extern void sub_8086A3C(struct Entity *);
extern void PlaySoundEffect(u32);
extern void sub_80861F8(u32, struct Entity *, u32);

void SpriteShockEffect(struct Entity *entity)
{
    PlaySoundEffect(0xE8 << 1);
    sub_80861F8(0x143, entity, 0);
}

void sub_80862DC(struct Entity *entity)
{
    struct Position32 pos;
    pos.x = entity->pixelPos.x;
    pos.y = entity->pixelPos.y + (0xE0 << 6);

    sub_804535C(entity, &pos);
    sub_806CDD4(entity, 0, DIRECTION_NORTH);
    sub_8086A54(entity);
}

void sub_8086310(struct Entity *entity)
{
    struct Position32 pos;
    pos.x = entity->pixelPos.x;
    pos.y = entity->pixelPos.y + (0x90 << 8);

    sub_804535C(entity, &pos);
    sub_806CE68(entity, DIRECTION_SOUTH);
    sub_8086A3C(entity);
    entity->isVisible = 0;
}

void sub_8086348(struct Entity *entity)
{
    struct Position32 pos;
    pos.x = entity->pixelPos.x + (0xF0 << 7);
    pos.y = entity->pixelPos.y + 0xffffe000;

    sub_804535C(entity, &pos);
    sub_806CDD4(entity, 0, DIRECTION_WEST);
    sub_8086A54(entity);
}

void sub_8086384(struct Entity *entity)
{
    struct Position32 pos;
    pos.x = entity->pixelPos.x + (0xF0 << 7);
    pos.y = entity->pixelPos.y;

    sub_804535C(entity, &pos);
    sub_806CDD4(entity, 0, DIRECTION_WEST);
    sub_8086A54(entity);
}

void sub_80863B8(struct Entity *entity)
{
    sub_806CDD4(entity, 0, DIRECTION_NORTH);
}

void sub_80863C8(struct Entity *entity)
{
    sub_806CDD4(entity, 0, DIRECTION_SOUTH);
}

void sub_80863D8(struct Entity *entity)
{
    sub_806CDD4(entity, 0, DIRECTION_WEST);
}

void sub_80863E8(struct Entity *entity)
{
    sub_806CDD4(entity, 6, DIRECTION_NORTH);
}

void sub_80863F8(struct Entity *entity)
{
    sub_806CE68(entity, DIRECTION_NORTH);
}

void sub_8086404(struct Entity *entity)
{
    sub_806CE68(entity, DIRECTION_WEST);
}

void sub_8086410(struct Entity *entity)
{
    IncreaseEntityPixelPos(entity, 0, 0xffffff00);
}

void sub_8086424(struct Entity *entity)
{
    IncreaseEntityPixelPos(entity, 0, 0x80 << 1);
}

void sub_8086434(struct Entity *entity)
{
    IncreaseEntityPixelPos(entity, 0xffffff00, 0);
}

void sub_8086448(void)
{
    s32 iVar1;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80862DC);

    for(iVar1 = 0; iVar1 < 0x38; iVar1++)
    {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        YPos += (0x80 << 1);
        sub_803F878(XPos, YPos);
        sub_80855E4(sub_8086410);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_80863F8);
}

void sub_8086494(void)
{
    s32 iVar1;

    sub_8085930(DIRECTION_NORTHEAST);
    sub_803E708(4, 0x46);

    sub_8085930(DIRECTION_EAST);
    sub_803E708(4, 0x46);

    sub_8085930(DIRECTION_SOUTHEAST);
    sub_803E708(4, 0x46);

    sub_8085930(DIRECTION_SOUTH);
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
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_8086348);

    for(iVar1 = 0; iVar1 < 0x48; iVar1++)
    {
        XPos = GetCameraXPos();
        XPos += (0x80 << 1);
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos);
        sub_80855E4(sub_8086434);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_8086404);
}

void sub_808654C(void)
{
    s32 iVar1;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_8086384);

    for(iVar1 = 0; iVar1 < 0x78; iVar1++)
    {
        XPos = GetCameraXPos();
        XPos += (0x80 << 1);
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos);
        sub_80855E4(sub_8086434);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_8086404);
}

void sub_8086598(void)
{
    s32 iVar1;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80863B8);

    for(iVar1 = 0; iVar1 < 0x18; iVar1++)
    {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos + (0xffffff00));
        sub_80855E4(sub_8086410);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_80863F8);
}

void sub_80865E8(void)
{
    s32 iVar1;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80863E8);

    for(iVar1 = 0; iVar1 < 0xC; iVar1++)
    {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos + (0x80 << 2));
        sub_80855E4(sub_8086424);
        sub_80855E4(sub_8086424);
        sub_803E46C(0x46);
    }
    sub_80855E4(sub_80863F8);
}

void sub_808663C(void)
{
    s32 iVar1;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80863E8);

    for(iVar1 = 0; iVar1 < 0x10; iVar1++)
    {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos + (0x80 << 2));
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


void sub_80866C4(u32 entity)
{

    SpriteLookAroundEffect(xxx_call_GetLeader());
    sub_803E708(0xA, 0x46);
    DisplayDungeonDialogue(entity);
    sub_803E708(0xA, 0x46);
    sub_8086494();
    gDungeon->unk2 = 1;
}

void sub_80866FC(void)
{
    s32 iVar1;

    for(iVar1 = 0; iVar1 >= -0xFA; iVar1 -= 0xA)
    {
        SetDungeonBGColorRGB(iVar1, iVar1, iVar1, 1, 0);
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
        SetDungeonBGColorRGB(iVar1, iVar1, iVar1, 1, 0);
        sub_803E46C(0x46);
    }
}

void sub_8086764(void)
{
    s32 iVar1;

    for(iVar1 = 0xFA; iVar1 >= 0; iVar1 -= 5)
    {
        SetDungeonBGColorRGB(iVar1, iVar1, iVar1, 1, 0);
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
        SetDungeonBGColorRGB(0, 0, 0, 1, 0);
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
    gDungeon->unk7 = 0;
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

void sub_808682C(u8 entity)
{
    gUnknown_202F3D0.unk0 = 0;
}

void sub_8086838(u8 entity, u8 r1, u8 r2)
{
    gUnknown_202F3D0.unk1 = entity;
    gUnknown_202F3D0.unk2 = r1;
    gUnknown_202F3D0.unk3 = r2;
}

void sub_8086848(u8 entity, u8 r1)
{
    gUnknown_202F3D0.unk4 = entity;
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
                gUnknown_202F3D0.unk4 = RandInt(0x6) + 2;
                gUnknown_202F3D0.unk5 = RandInt(0x6) + 2;
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
        gDungeon->unk181FC = gUnknown_8107314[gUnknown_202F3D0.unk5];
    }
    else
    {
        gDungeon->unk181FC = 0;
    }
}

void sub_80868F4(struct Entity *entity)
{
    entity->info->unk15C = 1;
    entity->info->unk15D = 1;
}

void sub_8086910(struct Entity *entity)
{
    entity->info->unk15C = 0;
    entity->info->unk15D = 0;
}

void sub_808692C(void)
{
    sub_80859F0(DIRECTION_NORTHWEST);
    sub_803E708(0x4, 0x46);

    sub_80859F0(DIRECTION_WEST);
    sub_803E708(0x4, 0x46);

    sub_80859F0(DIRECTION_SOUTHWEST);
    sub_803E708(0x4, 0x46);

    sub_80859F0(DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
}

void SpriteLookAroundEffect(struct Entity *entity)
{
    s8 r4;
    s8 r3;

    r4 = sub_8002984(entity->info->action.direction, 4);

    sub_80869E4(entity, 4, 2, r4);

    sub_803E708(0xF, 0x46);

    r4 = sub_8002984(r4, 5);

    sub_80869E4(entity, 4, 1, r4);

    sub_803E708(0xF, 0x46);

    r3 = sub_8002984(r4, 4);

    sub_80869E4(entity, 4, 2, r3);

    sub_803E708(0xF, 0x46);
}
