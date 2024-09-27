#include "global.h"
#include "code_804267C.h"

#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "code_806CD90.h"
#include "dungeon.h"
#include "dungeon_engine.h"
#include "dungeon_leader.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "structs/str_dungeon.h"

extern u8 gAvailablePokemonNames[]; // 202DF98

extern const u16 gUnknown_80F67DC[4];
extern const u16 gUnknown_80F67E4[4];
extern const s32 gUnknown_80F67EC[8];
extern const u32 gUnknown_80F680C[8];
extern const u16 gUnknown_80F682C[8];
extern const u8 *gPtrFeralFoundItemMessage[];

extern void sub_8040238(void);
extern void sub_804151C(Entity *pokemon, u32 r1, u8 r2);
extern void sub_804178C(u32);
extern void sub_80416A4(Position *r0, u32 r1, bool8 r2);
extern void sub_80421C0(Entity *pokemon, u16 r1);
extern void sub_80429A0(Entity *);
extern void sub_8042B34(u32, u32, u32);
extern bool8 sub_8042CC0(void);
extern void sub_8042D7C(void);
extern u8 sub_8043D10(void);
extern bool8 sub_8045888(Entity *);
extern void sub_8052210(u32);
extern void sub_805239C(Entity *, const u8 *);

// This func plays the appropriate ascend/descend SFX for stairs depending on the direction
void PlayStairsSound(void)
{
    u32 songIndex;

    songIndex = 997;

    switch (sub_8043D10()) {
        case 0:
        default:
            songIndex = IsStairDirectionUp(gDungeon->dungeonLocation.id) ? 340 : 341;
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
        sub_803E46C(0x46);

    sub_8042D7C();
    sub_8040238();
    sub_8052210(1);
}

void sub_8042730(Entity *a0, void *unused)
{
    s32 i;

    sub_806CDD4(a0, 8, 8);
    for (i = 0; i < 100; i++) {
        sub_803E46C(0x51);
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
        entity = gDungeon->allPokemon[i];
        if (EntityExists(entity)) {
            enInfo = entity->axObj.info;
            if (enInfo->unkF3) {
                enInfo->unkF3 = FALSE;
                sub_80429A0(entity);
                if (!enInfo->isNotTeamMember) {
                    SetMessageArgument(gAvailablePokemonNames, entity, 0);
                    sub_805239C(entity, *gPtrFeralFoundItemMessage);
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

void sub_80429FC(Position *r0)
{
    sub_80416A4(r0, 0x19E, TRUE);
    sub_80421C0(NULL, 0xD4);
}

void sub_8042A14(Position *r0)
{
    sub_80416A4(r0, 0x36, TRUE);
}

void sub_8042A24(Entity *r0)
{
    sub_804151C(r0, 0x15, 1);
}

void sub_8042A34(Position *r0)
{
    sub_80416A4(r0, 0x13E, FALSE);
}

void sub_8042A44(Entity *r0)
{
    sub_804151C(r0, 0xDA << 1, 1);
}

void sub_8042A54(Position *r0)
{
    sub_80416A4(r0, 0x37, TRUE);
}

void sub_8042A64(Position *r0)
{
    sub_80416A4(r0, 0x29, TRUE);
}

void sub_8042A74(Entity *r0)
{
    sub_804151C(r0, 0x18, 1);
}

void sub_8042A84(s16 param_1, Entity *entity, u32 param_3)
{
  s32 iVar2;
  s32 iVar3;
  s32 r6;
  s32 param_1_s16;

  param_1_s16 = param_1;

  r6 = 0x200;
  if (sub_8042768(entity)) {
    sub_804151C(entity,param_1_s16,0);
    sub_803E708(param_3,0x42);
    do {
      if (0xc7ff < entity->unk1C) break;
      sub_803E46C(0x42);
      iVar2 = entity->unk1C + r6;
      entity->unk1C = iVar2;
      r6 += 0x100;
      iVar3 = entity->pixelPos.y - iVar2;
      if (iVar3 < 0) {
        iVar3 += 0xff;
      }
    } while (-8 <= (iVar3 >> 8) - gDungeon->unk181e8.cameraPixelPos.y);
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
