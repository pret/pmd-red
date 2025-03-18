#include "global.h"
#include "code_800DAC0.h"
#include "code_800ED38.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "code_806CD90.h"
#include "dungeon.h"
#include "dungeon_engine.h"
#include "dungeon_map.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "items.h"
#include "structs/str_dungeon.h"

extern const u16 gUnknown_80F67DC[4];
extern const u16 gUnknown_80F67E4[4];
extern const s32 gUnknown_80F67EC[8];
extern const u32 gUnknown_80F680C[8];
extern const u16 gUnknown_80F682C[8];
extern const u8 *gPtrFeralFoundItemMessage[];

extern void sub_804151C(Entity *pokemon, u32 r1, u8 r2);
extern void sub_804178C(u32);
extern void sub_80416A4(DungeonPos *r0, u32 r1, bool8 r2);
extern void sub_80429A0(Entity *);
extern void sub_8042B34(u32, u32, u32);
extern bool8 sub_8042CC0(void);
extern void sub_8042D7C(void);
extern u8 GetFloorType(void);
extern bool8 sub_8045888(Entity *);
extern s32 sub_80416E0(PixelPos*, u32, bool8);
extern u32 sub_8041764(unkStruct_80416E0 *, bool8);
extern void sub_8005700(DungeonPos *a0, struct axObject *a1);
extern u32 sub_800E49C();
extern void sub_800EF40(u8 r0, u8 r1);

void sub_8042390(Entity *entity, Item *item)
{
    s32 sVar1;
    s32 counter;
    u8 id;
    u32 uVar6;
    DungeonPos asStack_24[4];
    DungeonPos local_14;

    if (sub_8042768(entity)) {
        id = !ItemSticky(item) ? item->id : ITEM_NOTHING;
        sub_800EF40(id, 0);
        sub_800EF64();
        sub_803E708(4,0x42);
        local_14.x = (entity->pixelPos).x / 256;
        local_14.y = (entity->pixelPos).y / 256;

        sVar1 = (local_14.y - gDungeon->unk181e8.cameraPixelPos.y) / 2 + 1;
        sub_8005700(asStack_24,&entity->axObj);
        uVar6 = sub_800E49C(id,&local_14,asStack_24,0,sVar1);
        for (counter = 0; counter < 1000; counter++) {
            DungeonRunFrameActions(0x42);
            if (!sub_800E9A8(uVar6)) {
                break;
            }
        }
    }
}

void sub_804245C(Entity *entity, Item *item)
{
    s32 sVar1;
    s32 counter;
    u8 id;
    u32 uVar6;
    DungeonPos asStack_24[4];
    DungeonPos local_14;

    if (sub_8042768(entity)) {
        id = !ItemSticky(item) ? item->id : ITEM_NOTHING;
        sub_800EF64();
        sub_803E708(4,0x42);
        local_14.x = (entity->pixelPos).x / 256;
        local_14.y = (entity->pixelPos).y / 256;

        sVar1 = (local_14.y - gDungeon->unk181e8.cameraPixelPos.y) / 2 + 1;
        sub_8005700(asStack_24,&entity->axObj);
        uVar6 = sub_800E49C(id,&local_14,asStack_24,1,sVar1);
        for (counter = 0; counter < 1000; counter++) {
            DungeonRunFrameActions(0x42);
            if (!sub_800E9A8(uVar6)) {
                break;
            }
        }
    }
}


s32 sub_8042520(Entity *a0)
{
    s32 i;
    s32 uVar4;
    DungeonPos pos;
    u32 dir;
    s32 iVar8;
    unkStruct_80416E0 local_58;
    unkStruct_2039DB0 u203; // Unused
    PixelPos local_2c;

    if (sub_8045888(a0)) {
        dir = GetEntInfo(a0)->action.direction;
        pos.x = a0->pixelPos.x / 0x100;
        pos.y = a0->pixelPos.y / 0x100;

        iVar8 = (pos.y - gDungeon->unk181e8.cameraPixelPos.y) / 2;
        local_58.unk0 = 357;
        local_58.unk4 = 0;
        local_58.dir = dir;
        local_58.x = pos.x;
        local_58.y = pos.y;
        local_58.unk10 = 0;
        local_58.unk12 = 0;
        local_58.unk14 = -1;
        local_58.unk18 = iVar8;
        sub_8004E8C(&u203);
        uVar4 = sub_8041764(&local_58, 0);

        for (i = 0; i < 6; i++) {
            sub_800E8AC(uVar4, &pos, 0, iVar8, 0);
            DungeonRunFrameActions(66);
            pos.x += gAdjacentTileOffsets[dir].x * 4;
            pos.y += gAdjacentTileOffsets[dir].y * 4;
            iVar8 = (pos.y - gDungeon->unk181e8.cameraPixelPos.y) / 2;
        }

        sub_800DBBC();
        local_2c.x = pos.x * 0x100;
        local_2c.y = pos.y * 0x100;
        uVar4 = sub_80416E0(&local_2c, 416, TRUE);
    }
    else
    {
        uVar4 = -1;
    }
    return uVar4;
}

// This func plays the appropriate ascend/descend SFX for stairs depending on the direction
void PlayStairsSound(void)
{
    u32 songIndex;

    songIndex = 997;

    switch (GetFloorType()) {
        case 0:
        default:
            songIndex = IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id) ? 340 : 341;
            break;
        case 1:
        case 2:
            break;
    }

    PlaySoundEffect(songIndex);
}

void sub_80426C8(u32 a0, u32 a1)
{
    if (a1 == 3)
        DungeonStartNewBGM(0);

    if (a0 != 4)
        PlaySoundEffect(gUnknown_80F67DC[a1]);
    else
        PlaySoundEffect(gUnknown_80F67E4[a1]);

    sub_8042B34(a0, a1, 0x80);

    while (sub_8042CC0())
        DungeonRunFrameActions(0x46);

    sub_8042D7C();
    LoadDungeonMapPalette();
    sub_8052210(1);
}

void sub_8042730(Entity *a0, void *unused)
{
    s32 i;

    sub_806CDD4(a0, 8, 8);
    for (i = 0; i < 100; i++) {
        DungeonRunFrameActions(0x51);
        if ((a0->axObj.axdata.sub1.unk10 & 3) != 0 || a0->axObj.unk43_animId2 != 8)
            break;
    }
}

bool8 sub_8042768(Entity* pokemon)
{
    if (!pokemon->isVisible)
        return FALSE;
    if (gDungeon->unk181e8.blinded) {
        if (gDungeon->unk181e8.cameraTarget == pokemon)
            return TRUE;
        else
            return FALSE;
    }
    return sub_8045888(pokemon);
}

void sub_80427AC(void)
{
    Entity *entity;
    EntityInfo *enInfo;
    s32 i;

    for (i = 0; i < 20; i++) {
        entity = gDungeon->activePokemon[i];
        if (EntityIsValid(entity)) {
            enInfo = GetEntInfo(entity);
            if (enInfo->unkF3) {
                enInfo->unkF3 = FALSE;
                sub_80429A0(entity);
                if (!enInfo->isNotTeamMember) {
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
                    DisplayDungeonLoggableMessageTrue(entity, *gPtrFeralFoundItemMessage);
                }
            }
        }
    }
}

void sub_8042818(u8 a0, bool8 a1)
{
    Entity *en;

    en = gDungeon->unk181e8.cameraTarget;
    if (en == NULL)
        en = GetLeader();

    if (gUnknown_80F682C[a0] != 997)
        sub_80421C0(en, gUnknown_80F682C[a0]);

    if (gUnknown_80F67EC[a0] < 0)
        return;

    if (a1 && !IsBossFight())
        sub_804151C(en, gUnknown_80F67EC[a0], 0);
    else
        sub_804151C(en, gUnknown_80F680C[a0], 0);
}

void sub_80428A0(Entity *r0)
{
    sub_804151C(r0, 0x29, 1);
}

void sub_80428B0(Entity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}


void sub_80428C4(Entity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}


void sub_80428D8(Entity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_80428EC(Entity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_8042900(Entity *r0)
{
    sub_804151C(r0, 0xD4 << 1, 0);
}

void ShowVisualFlags(Entity *r0)
{
    sub_804151C(r0, 0x29, 0);
}

void sub_8042920(Entity *r0)
{
    sub_804151C(r0, 0x48, 0);
}

void sub_8042930(Entity *r0)
{
    sub_804151C(r0, 0xD3 << 1, 1);
}

void sub_8042940(Entity *r0)
{
    sub_804151C(r0, 0xC7 << 1, 0);
}

void sub_8042950(Entity *r0)
{
    sub_804151C(r0, 0xD8 << 1, 1);
    sub_803E708(0xA, 0x42);
}

void sub_8042968(Entity *r0)
{
    sub_804151C(r0, 0xD4 << 1, 0);
}

void sub_8042978(Entity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_804298C(Entity *r0)
{
    sub_804151C(r0, 0x1a9, 0);
}

void sub_80429A0(Entity *r0)
{
    sub_804151C(r0, 0x199, 0);
}

void sub_80429B4(Entity *r0)
{
    sub_804151C(r0, 0x1ab, 0);
}

void sub_80429C8(Entity *r0)
{
    sub_804151C(r0, 0x4, 1);
}

void sub_80429D8(Entity *r0)
{
    sub_804151C(r0, 0x8F << 1, 1);
}

void sub_80429E8(Entity *r0)
{
    sub_804151C(r0, 0x11d, 1);
}

void sub_80429FC(DungeonPos *r0)
{
    sub_80416A4(r0, 0x19E, TRUE);
    sub_80421C0(NULL, 0xD4);
}

void sub_8042A14(DungeonPos *r0)
{
    sub_80416A4(r0, 0x36, TRUE);
}

void sub_8042A24(Entity *r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8042A34(DungeonPos *r0)
{
    sub_80416A4(r0, 0x13E, FALSE);
}

void sub_8042A44(Entity *r0)
{
    sub_804151C(r0, 0xDA << 1, 1);
}

void sub_8042A54(DungeonPos *r0)
{
    sub_80416A4(r0, 0x37, TRUE);
}

void sub_8042A64(DungeonPos *r0)
{
    sub_80416A4(r0, 0x29, TRUE);
}

void sub_8042A74(Entity *r0)
{
    sub_804151C(r0, 0x18, 1);
}

void sub_8042A84(s16 param_1, Entity *entity, u32 param_3)
{
  s32 iVar3;
  s32 r6;
  s32 param_1_s16;

  param_1_s16 = param_1;

  r6 = IntToF248_2(2).raw;
  if (sub_8042768(entity)) {
    sub_804151C(entity,param_1_s16,0);
    sub_803E708(param_3,0x42);
    do {
      if (entity->unk1C.raw > IntToF248_2(199.999).raw) break;
      DungeonRunFrameActions(0x42);
      entity->unk1C.raw += + r6;
      r6 += IntToF248_2(1).raw;
      iVar3 = (entity->pixelPos.y - entity->unk1C.raw) / 256;
    } while (-8 <= iVar3 - gDungeon->unk181e8.cameraPixelPos.y);
    entity->isVisible = 0;
    sub_804178C(0);
  }
}

void sub_8042B0C(Entity *entity)
{
    sub_8042A84(0x13e, entity, 5);
}

void sub_8042B20(Entity *entity)
{
    sub_8042A84(0x1BC, entity, 0xE);
}
