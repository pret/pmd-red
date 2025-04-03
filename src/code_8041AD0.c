#include "global.h"
#include "globaldata.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "constants/type.h"
#include "structs/dungeon_entity.h"
#include "structs/sprite_oam.h"
#include "structs/str_dungeon.h"
#include "code_800558C.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "code_800ED38.h"
#include "code_803E46C.h"
#include "code_803E724.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_806CD90.h"
#include "dungeon_config.h"
#include "dungeon_logic.h"
#include "dungeon_util.h"
#include "items.h"
#include "math.h"
#include "sprite.h"
#include "code_803E668.h"
#include "dungeon.h"
#include "run_dungeon.h"
#include "dungeon_leader.h"
#include "dungeon_map.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "memory.h"
#include "random.h"
#include "dungeon_util_1.h"
#include "code_800E9E4.h"

// Unknown dungeon file. File split is correct.

extern const u8 *gPtrFeralFoundItemMessage[];

extern void sub_803ED30(u8, Entity *pokemon, u8, u8);
extern u32 sub_806F62C(u32);
extern u32 sub_800DC9C(s32 a0);
extern void PlaySoundEffect(u32);

void EntityUpdateStatusSprites(Entity *entity);

extern s32 gDungeonBrightness;

extern void sub_800DBBC(void);
extern void sub_803EA10(void);
extern void sub_8042E98(void);
extern void sub_800EF28(u8);
extern u32 sub_800E448(u8, DungeonPos *);
extern void sub_80429A0(Entity *);
void sub_8042B34(s32 a0, s32 a1, s32 a2);
extern bool8 sub_8042CC0(void);
extern void sub_8042D7C(void);
extern u8 GetFloorType(void);
extern bool8 sub_8045888(Entity *);
extern s32 sub_80416E0(PixelPos*, u32, bool8);
extern u32 sub_8041764(unkStruct_80416E0 *, bool8);
extern u32 sub_800E49C();
extern void sub_800F15C(s32);
extern void sub_800EF40(u8 r0, u8 r1);
extern s32 sub_800E6D8(s32);
extern void sub_800EB24(s32 param_1, DungeonPos *param_2, DungeonPos *param_3, s32 param_4, s32 param_5);

u32 sub_8041764(unkStruct_80416E0 *param_1, bool8 param_2);
s32 sub_80416E0(PixelPos *pos, u32 param_2, bool8 param_3);
s32 sub_8041550(Entity *entity, s32 a1, u8 a2, u8 a3, s32 a4, u8 a5);
s32 sub_804151C(Entity *entity, s32 r1, u8 r2);
void sub_804178C(u8 param_1);

struct UnkStruct_80F6624
{
    s16 unk0;
    s32 unk4;
};

static const struct UnkStruct_80F6624 gUnknown_80F6624[][3] = {
    {{0x178, 3}, {0x179, 1}, {0, 0}},
    {{0x17A, 1}, {0x17B, 2}, {0x17C, 3}},
    {{0x17D, 1}, {0x17E, 2}, {0, 0}},
    {{0x17F, 2}, {0, 0}, {0, 0}},
    {{0x1B9, 1}, {0x1BA, 2}, {0x1BB, 3}},
};

static const u32 sStatusSpriteMasks_SleepClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_SLEEP] = STATUS_SPRITE_SLEEP,
    [STATUS_SLEEPLESS] = STATUS_SPRITE_SLEEPLESS,
    [STATUS_NIGHTMARE] = STATUS_SPRITE_SLEEP,
    [STATUS_YAWNING] = 0,
    [STATUS_NAPPING] = STATUS_SPRITE_SLEEP,
};

static const u32 sStatusSpriteMasks_BurnClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_BURN] = STATUS_SPRITE_BURNED,
    [STATUS_POISONED] = STATUS_SPRITE_POISONED,
    [STATUS_BADLY_POISONED] = STATUS_SPRITE_BADLY_POISONED,
    [STATUS_PARALYSIS] = 0,
};

static const u32 sStatusSpriteMasks_FrozenClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_FROZEN] = STATUS_SPRITE_FROZEN,
    [STATUS_SHADOW_HOLD] = 0,
    [STATUS_WRAP] = 0,
    [STATUS_WRAPPED] = 0,
    [STATUS_INGRAIN] = 0,
    [STATUS_PETRIFIED] = 0,
    [STATUS_CONSTRICTION] = 0,
};

static const u32 sStatusSpriteMasks_CringeClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_CRINGE] = 0,
    [STATUS_CONFUSED] = STATUS_SPRITE_CONFUSED,
    [STATUS_PAUSED] = 0,
    [STATUS_COWERING] = STATUS_SPRITE_COWERING,
    [STATUS_TAUNTED] = STATUS_SPRITE_TAUNTED,
    [STATUS_ENCORE] = STATUS_SPRITE_ENCORE,
    [STATUS_INFATUATED] = 0,
};

static const u32 sStatusSpriteMasks_BideClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_BIDE] = 0,
    [STATUS_SOLARBEAM] = 0,
    [STATUS_SKY_ATTACK] = 0,
    [STATUS_RAZOR_WIND] = 0,
    [STATUS_FOCUS_PUNCH] = 0,
    [STATUS_SKULL_BASH] = 0,
    [STATUS_FLYING] = 0,
    [STATUS_BOUNCING] = 0,
    [STATUS_DIVING] = 0,
    [STATUS_DIGGING] = 0,
    [STATUS_CHARGING] = 0,
    [STATUS_ENRAGED] = 0,
};

static const u32 sStatusSpriteMasks_ReflectClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_REFLECT] = STATUS_SPRITE_SHIELD_BLUE,
    [STATUS_SAFEGUARD] = STATUS_SPRITE_SHIELD_RED,
    [STATUS_LIGHT_SCREEN] = STATUS_SPRITE_SHIELD_YELLOW,
    [STATUS_COUNTER] = STATUS_SPRITE_SHIELD_BLUE,
    [STATUS_MAGIC_COAT] = STATUS_SPRITE_SHIELD_YELLOW,
    [STATUS_WISH] = 0,
    [STATUS_PROTECT] = STATUS_SPRITE_SHIELD_GREEN,
    [STATUS_MIRROR_COAT] = STATUS_SPRITE_SHIELD_RED,
    [STATUS_ENDURING] = STATUS_SPRITE_ENDURE,
    [STATUS_MINI_COUNTER] = STATUS_SPRITE_SHIELD_BLUE,
    [STATUS_MIRROR_MOVE] = STATUS_SPRITE_SHIELD_GREEN,
    [STATUS_CONVERSION2] = 0,
    [STATUS_VITAL_THROW] = STATUS_SPRITE_SHIELD_GREEN,
    [STATUS_MIST] = STATUS_SPRITE_SHIELD_BLUE,
};

static const u32 sStatusSpriteMasks_CurseClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_CURSED] = STATUS_SPRITE_CURSED,
    [STATUS_DECOY] = 0,
    [STATUS_SNATCH] = STATUS_SPRITE_SNATCH,
};

static const u32 sStatusSpriteMasks_LeechSeedClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_LEECH_SEED] = 0,
    [STATUS_DESTINY_BOND] = 0,
};

static const u32 sStatusSpriteMasks_SureShotClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_SURE_SHOT] = STATUS_SPRITE_SURE_SHOT,
    [STATUS_WHIFFER] = STATUS_SPRITE_WHIFFER,
    [STATUS_SET_DAMAGE] = STATUS_SPRITE_SET_DAMAGE,
    [STATUS_FOCUS_ENERGY] = STATUS_SPRITE_FOCUS_ENERGY,
};

static const u32 sStatusSpriteMasks_LongTossClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_LONG_TOSS] = 0,
    [STATUS_PIERCE] = 0,
};

static const u32 sStatusSpriteMasks_InvisibleClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_INVISIBLE] = 0,
    [STATUS_TRANSFORMED] = 0,
    [STATUS_MOBILE] = 0,
};

static const u32 sStatusSpriteMasks_BlinkerClassStatus[] = {
    [STATUS_NONE] = 0,
    [STATUS_BLINKER] = STATUS_SPRITE_BLINKER,
    [STATUS_CROSS_EYED] = STATUS_SPRITE_CROSS_EYED,
    [STATUS_EYEDROPS] = STATUS_SPRITE_EYEDROPS,
};

static const u32 sStatusSpriteMasks_MuzzledStatus[] = {
    [STATUS_NONE] = 0,
    /*STATUS_MUZZLED not defined*/[1] = STATUS_SPRITE_MUZZLED,
};

s32 sub_804151C(Entity *entity, s32 r1, u8 r2)
{
    u8 r3 = sub_800DC9C(r1);
    return sub_8041550(entity, r1, r2, r3, 2, 0);
}

s32 sub_8041550(Entity *entity, s32 a1, u8 a2, u8 a3, s32 a4, u8 a5)
{
    s32 i;
    EntityInfo *entInfo;
    DungeonPos pos;
    unkStruct_80416E0 sp;
    PixelPos pixelPos;
    s32 var;
    s32 r4;

    if (!EntityIsValid(entity))
        return -1;
    entInfo = GetEntInfo(entity);
    if (!sub_8042768(entity))
        return -1;
    if (!a5 && entInfo->unkFF == 2)
        return -1;

    if (a4 != 0) {
        sub_804178C(a4 == 2);
    }

    sub_800569C(&pos, &entity->axObj, a3);
    if (pos.x != 99 && pos.y != 99) {
        pixelPos.x = entity->pixelPos.x + (pos.x << 8);
        pixelPos.y = (entity->pixelPos.y + (pos.y << 8)) - entInfo->unk174.raw;
    }
    else {
        pixelPos.x = entity->pixelPos.x;
        pixelPos.y = entity->pixelPos.y - entInfo->unk174.raw;
    }

    var = entity->pixelPos.y / 256;
    var -= gDungeon->unk181e8.cameraPixelPos.y;
    var /= 2;
    var++;

    sp.unk0 = a1;
    sp.unk4 = 0;
    sp.dir = -1;
    sp.x = pixelPos.x / 256;
    sp.y = pixelPos.y / 256;
    sp.unk14 = -1;
    sp.unk10 = 0;
    sp.unk12 = 0;
    sp.unk18 = var;

    sub_8004E8C(&sp.unk1C);
    r4 = sub_8041764(&sp, FALSE);
    if (a2) {
        for (i = 0; i < 100; i++) {
            if (!sub_800E9A8(r4)) {
                break;
            }
            DungeonRunFrameActions(0x42);
        }
        r4 = -1;
    }
    return r4;
}

s32 sub_80416A4(DungeonPos *pos_1, u32 param_2, bool8 param_3)
{
  PixelPos pos;

  pos.x = X_POS_TO_PIXELPOS(pos_1->x);
  pos.y = Y_POS_TO_PIXELPOS(pos_1->y);
  return sub_80416E0(&pos, param_2, param_3);
}

s32 sub_80416E0(PixelPos *pos, u32 param_2, bool8 param_3)
{
  int counter;
  s32 ret;
  unkStruct_80416E0 auStack_10;

  auStack_10.unk0 = param_2;
  auStack_10.unk4 = 0;
  auStack_10.dir = -1;

  auStack_10.x = pos->x / 256;
  auStack_10.y = pos->y / 256;

  auStack_10.unk14 = -1;
  auStack_10.unk10 = 0;
  auStack_10.unk12 = 0;
  auStack_10.unk18 = 0xffff;
  sub_8004E8C(&auStack_10.unk1C);
  ret = sub_8041764(&auStack_10, FALSE);
  if (param_3) {
    counter = 0;
    while ((counter < 100 && (sub_800E9A8(ret)))) {
      DungeonRunFrameActions(0x42);
      counter++;
    }
    ret = -1;
  }
  return ret;
}

u32 sub_8041764(unkStruct_80416E0 *param_1, bool8 param_2)
{
    sub_800EE5C(param_1->unk0);
    sub_800EF64();
    if(param_2)
        DungeonRunFrameActions(0x42);
    return sub_800E890(param_1);
}

void sub_804178C(u8 param_1)
{
  u32 temp;
  s32 counter;

  counter = 0;
  gDungeon->unk181e8.unk18204 = 0;
  if (sub_800E9FC(param_1) != 0) {
    while ((counter < 1000 && (sub_800E9FC(param_1) != 0))) {
      DungeonRunFrameActions(0x4a);
      counter++;
    }
    DungeonRunFrameActions(0x4a);
    DungeonRunFrameActions(0x4a);
  }
  if ((counter == 1000) || (param_1 != 0)) {
    sub_800DBBC();
  }
  if (gDungeonBrightness < 0x1f) {
    temp = gUnknown_203B40D;
    gUnknown_203B40D = 1;
    for(counter = 0; counter < 1000; counter++)
    {
      if (gDungeonBrightness < 0x1f) {
        gDungeonBrightness += 4;
        if (gUnknown_2026E4E != 0x808) {
          gUnknown_2026E4E -= 0x101;
        }
      }
      else {
        gDungeonBrightness = 0x1f;
      }
      sub_803EA10();
      DungeonRunFrameActions(0x4a);
      if(gDungeonBrightness == 0x1f) break;
    };
    gUnknown_2026E4E = 0x808;
    gUnknown_203B40D = temp;
  }
  sub_8042E98();
}

u32 EntityGetStatusSprites(Entity *entity)
{
    return GetEntInfo(entity)->statusIcons;
}

void sub_8041888(u8 param_1)
{
    s32 index;
    Entity *entity;
    EntityInfo *entityInfo;
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if(EntityIsValid(entity))
        {
            entityInfo = GetEntInfo(entity);
            if(param_1)
            {
                entityInfo->unk14C = 1;
            }
            EntityUpdateStatusSprites(entity);
        }
    }
}

void EntityUpdateStatusSprites(Entity *entity)
{
  bool32 flag;
  s32 HP;
  EntityInfo *entityInfo;
  u32 spriteStatus;
  u8 temp;

  if (EntityIsValid(entity)) {
    entityInfo = GetEntInfo(entity);
    spriteStatus = 0;
    flag = TRUE;

    if (entityInfo->id == 0xb9) {
      // NOTE: clean this up sometime
      temp = entityInfo->sleepClassStatus.turns;
      flag = 0x7f;
      temp ^= flag;
      flag = (temp) != 0;
    }
    if (flag) {
      spriteStatus = sStatusSpriteMasks_SleepClassStatus[entityInfo->sleepClassStatus.status];
    }
    spriteStatus = spriteStatus |
            sStatusSpriteMasks_BurnClassStatus[entityInfo->burnClassStatus.status] |
            sStatusSpriteMasks_FrozenClassStatus[entityInfo->frozenClassStatus.status] |
            sStatusSpriteMasks_CringeClassStatus[entityInfo->cringeClassStatus.status] |
            sStatusSpriteMasks_BideClassStatus[entityInfo->bideClassStatus.status] |
            sStatusSpriteMasks_ReflectClassStatus[entityInfo->reflectClassStatus.status] |
            sStatusSpriteMasks_CurseClassStatus[entityInfo->curseClassStatus.status] |
            sStatusSpriteMasks_LeechSeedClassStatus[entityInfo->leechSeedClassStatus.status] |
            sStatusSpriteMasks_SureShotClassStatus[entityInfo->sureShotClassStatus.status] |
            sStatusSpriteMasks_LongTossClassStatus[entityInfo->longTossClassStatus.status] |
            sStatusSpriteMasks_InvisibleClassStatus[entityInfo->invisibleClassStatus.status] |
            sStatusSpriteMasks_BlinkerClassStatus[entityInfo->blinkerClassStatus.status] |
            sStatusSpriteMasks_MuzzledStatus[entityInfo->muzzled.muzzled];

    if (entityInfo->grudge) {
      spriteStatus = spriteStatus | STATUS_SPRITE_GRUDGE;
    }
    if (entityInfo->exposed) {
      spriteStatus = spriteStatus | STATUS_SPRITE_EXPOSED;
    }
    if (!entityInfo->isNotTeamMember) {
      HP = entityInfo->maxHPStat;
      if (HP < 0) {
        HP += 3;
      }
      HP >>= 2;
      if (HP > entityInfo->HP) {
        spriteStatus = spriteStatus | STATUS_SPRITE_LOWHP;
      }
    }
    if ((gDungeon->unk644.itemHoldersIdentified) && (entityInfo->heldItem.flags & ITEM_FLAG_EXISTS)) {
      spriteStatus = spriteStatus | STATUS_SPRITE_LOWHP;
    }
    if ((F248LessThanInt(entityInfo->offensiveMultipliers[0], 1)) ||
        (F248LessThanInt(entityInfo->offensiveMultipliers[1], 1)) ||
        (F248LessThanInt(entityInfo->defensiveMultipliers[0], 1)) ||
        (F248LessThanInt(entityInfo->defensiveMultipliers[1], 1)) ||
        (entityInfo->offensiveStages[0] < DEFAULT_STAT_STAGE) ||
        (entityInfo->offensiveStages[1] < DEFAULT_STAT_STAGE) ||
        (entityInfo->defensiveStages[0] < DEFAULT_STAT_STAGE) ||
        (entityInfo->defensiveStages[1] < DEFAULT_STAT_STAGE) ||
        (entityInfo->hitChanceStages[0]) < DEFAULT_STAT_STAGE ||
        (entityInfo->hitChanceStages[1] < DEFAULT_STAT_STAGE)) {
        spriteStatus = spriteStatus | STATUS_SPRITE_STAT_DOWN;
    }
    entityInfo->statusIcons = spriteStatus;
  }
}

void sub_8041AD0(Entity *pokemon)
{
    sub_804151C(pokemon, 324, 1);
}

void sub_8041AE0(Entity *pokemon)
{
    sub_804151C(pokemon, 323, 1);
}

void sub_8041AF4(Entity *pokemon)
{
    sub_804151C(pokemon, 37, 1);
    sub_80421C0(pokemon, 407);
}

void nullsub_57(void)
{
}

void sub_8041B18(Entity *pokemon)
{
    sub_804151C(pokemon, 321, 1);
}

void nullsub_58(void)
{
}

void nullsub_59(void)
{
}

void sub_8041B34(Entity *pokemon)
{
    sub_804151C(pokemon, 7, 1);
}

void nullsub_60(void)
{
}

void sub_8041B48(Entity *pokemon)
{
    sub_804151C(pokemon, 4, 0);
}

void nullsub_61(void)
{
}

void sub_8041B5C(Entity *pokemon)
{
    sub_804151C(pokemon, 369, 1);
}

void nullsub_62(Entity *pokemon)
{
}

void sub_8041B74(Entity *pokemon)
{
    sub_804151C(pokemon, 369, 0);
}

void nullsub_63(void)
{
}

void nullsub_64(void)
{
}

void sub_8041B90(Entity *pokemon)
{
    sub_804151C(pokemon, 428, 0);
}

void nullsub_65(void)
{
}

void nullsub_66(void)
{
}

void sub_8041BA8(Entity *pokemon)
{
    sub_804151C(pokemon, 4, 1);
}

void nullsub_67(void)
{
}

void sub_8041BBC(Entity *pokemon)
{
    sub_804151C(pokemon, 424, 1);
}

void nullsub_68(void)
{
}

void sub_8041BD0(Entity *pokemon, u8 r1)
{
    if(r1 == 0)
    {
        return;
    }
    sub_80421C0(pokemon, 421);
}

void sub_8041BE8(Entity *pokemon)
{
    sub_80421C0(pokemon, 406);
}

void sub_8041BF8(Entity *pokemon)
{
    sub_806CDD4(pokemon, 0xA, NUM_DIRECTIONS);
}

void sub_8041C08(Entity *pokemon)
{
    sub_804151C(pokemon, 423, 1);
}

void sub_8041C1C(Entity *pokemon)
{
    sub_804151C(pokemon, 423, 1);
}

void nullsub_69(void)
{
}

void sub_8041C34(Entity *pokemon)
{
    sub_804151C(pokemon, 0x4C, 1);
}

void nullsub_70(void)
{
}

void nullsub_71(void)
{
}

void sub_8041C4C(Entity *pokemon, u32 r1)
{
    sub_804151C(pokemon, r1, 1);
}

void sub_8041C58(Entity *pokemon)
{
    sub_804151C(pokemon, 0x1a9, 1);
}

void sub_8041C6C(Entity *pokemon)
{
    sub_804151C(pokemon, 0x9D << 1, 1);
}

void sub_8041C7C(Entity *pokemon)
{
    sub_804151C(pokemon, 0x9D << 1, 1);
}

void nullsub_72(void)
{
}

void nullsub_73(void)
{
}

void sub_8041C94(Entity *pokemon)
{
    sub_804151C(pokemon, 0x171, 1);
}

void sub_8041CA8(Entity *pokemon)
{
    sub_804151C(pokemon, 7, 1);
}

void sub_8041CB8(Entity *pokemon)
{
    sub_804151C(pokemon, 0x18b, 1);
}

void sub_8041CCC(Entity *pokemon)
{
    sub_804151C(pokemon, 0xC5 << 1, 1);
}

void sub_8041CDC(Entity *pokemon)
{
    sub_804151C(pokemon, 5, 1);
}

void sub_8041CEC(Entity *pokemon)
{
    sub_80421C0(pokemon, 0x19d);
}

void nullsub_74(void)
{
}

void sub_8041D00(Entity *pokemon, Entity *target)
{
    sub_804151C(target, 0x2F, 1);
    sub_804151C(pokemon, 0x30, 1);
}

void nullsub_75(Entity *pokemon)
{
}

void nullsub_76(Entity *pokemon)
{
}

void nullsub_77(Entity *pokemon)
{
}

void nullsub_78(Entity *pokemon)
{
}

void nullsub_79(Entity *pokemon)
{
}

void nullsub_80(Entity *pokemon)
{
}

void sub_8041D38(Entity * pokemon)
{
    sub_804151C(pokemon, 0x21, 1);
}

void sub_8041D48(Entity * pokemon)
{
    sub_80421C0(pokemon, 0x191);
}

void nullsub_81(void)
{
}

void sub_8041D5C(Entity *pokemon)
{
    if (!sub_8042768(pokemon))
        return;

    sub_803ED30(GetEntInfo(pokemon)->stockpileStage, pokemon, 1, 11);
}

void sub_8041D84(Entity *pokemon)
{
    sub_80421C0(pokemon, 0x19f);
}

void nullsub_82(void)
{
}

void nullsub_83(void)
{
}

void sub_8041D9C(Entity *pokemon)
{
    sub_804151C(pokemon, 0x131, 1);
}

void sub_8041DB0(Entity *pokemon)
{
    sub_804151C(pokemon, 0x30, 1);
}

void nullsub_84(void)
{
}

void nullsub_85(void)
{
}

void nullsub_204(void)
{
}

void nullsub_86(void)
{
}

void nullsub_87(void)
{
}

void nullsub_88(void)
{
}

void sub_8041DD8(Entity *pokemon, s16 r1)
{
    u32 temp;
    temp = r1;

    if(MonsterIsType(pokemon, TYPE_GHOST) != 0)
        sub_804151C(pokemon, temp, 1);
    else
        sub_804151C(pokemon, TYPE_GHOST, 1);
}

void nullsub_89(void)
{
}

void sub_8041E0C(Entity *pokemon)
{
    sub_804151C(pokemon, 0x41, 1);
}

void sub_8041E1C(Entity *pokemon)
{
    sub_804151C(pokemon, 0x8F << 1, 1);
    sub_80421C0(pokemon, 0xCE << 1);
}

void sub_8041E3C(Entity *pokemon)
{
    sub_804151C(pokemon, 0xD7 << 1, 1);
}

void sub_8041E4C(Entity *pokemon)
{
    sub_804151C(pokemon, 0x1b1, 1);
}

void sub_8041E60(Entity *pokemon)
{
    sub_804151C(pokemon, 0x1a9, 1);
}

void sub_8041E74(Entity *pokemon)
{
    sub_804151C(pokemon, 0xC9 << 1, 1);
}

void sub_8041E84(Entity *pokemon)
{
    sub_804151C(pokemon, 0xC7 << 1, 1);
}

void sub_8041E94(Entity *pokemon)
{
    sub_804151C(pokemon, 0xC8 << 1, 1);
}

void sub_8041EA4(Entity *pokemon)
{
    sub_804151C(pokemon, 0x15, 1);
}

void sub_8041EB4(Entity *pokemon)
{
    sub_804151C(pokemon, 0x171, 1);
}

void sub_8041EC8(Entity *pokemon)
{
    sub_80421C0(pokemon, 0x197);
}

void sub_8041ED8(Entity *pokemon)
{
    sub_80421C0(pokemon, 0x197);
}

void sub_8041EE8(Entity *pokemon)
{
    sub_804151C(pokemon, 0x15, 1);
}

void sub_8041EF8(Entity *pokemon)
{
    sub_804151C(pokemon, 0xF, 1);
}

void sub_8041F08(Entity *pokemon)
{
    sub_8041550(pokemon, 0x15, 1, 3, 2, 0);
}

void nullsub_90(void)
{
}

void sub_8041F28(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0xCA << 1, 1);
    }
    else
    {
        sub_804151C(pokemon, 0x193, 1);
    }
}

void sub_8041F4C(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0x18f, 1);
    }
    else
    {
        sub_804151C(pokemon, 0x191, 1);
    }
}

void sub_8041F70(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0x1a9, 1);
    }
    else
    {
        sub_804151C(pokemon, 0xC9 << 1, 1);
    }
}

void sub_8041F94(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0xC7 << 1, 1);
    }
    else
    {
        sub_804151C(pokemon, 0xC8 << 1, 1);
    }
}

void sub_8041FB4(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0x1a9, 1);
    }
    else
    {
        sub_804151C(pokemon, 0xC9 << 1, 1);
    }
}

void sub_8041FD8(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0xCA << 1, 1);
    }
    else
    {
        sub_804151C(pokemon, 0x193, 1);
    }
}

void sub_8041FFC(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0xC7 << 1, 1);
    }
    else
    {
        sub_804151C(pokemon, 0xC8 << 1, 1);
    }
}

void sub_804201C(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0x18f, 1);
    }
    else
    {
        sub_804151C(pokemon, 0x191, 1);
    }
}

void sub_8042040(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0xC6 << 1, 1);
    }
    else
    {
        sub_804151C(pokemon, 0xD, 1);
    }
}

void sub_8042060(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0x18d, 1);
    }
    else
    {
        sub_804151C(pokemon, 0xE, 1);
    }
}

void sub_8042080(Entity *pokemon, u32 r1)
{
    if(r1 == 0)
    {
        sub_804151C(pokemon, 0xC6 << 1, 1);
    }
    else
    {
        sub_804151C(pokemon, 0xD, 1);
    }
}

void sub_80420A0(Entity *pokemon, u32 r1)
{
    sub_804151C(pokemon, 0x143, 1);
}

void nullsub_91(void)
{
}

void sub_80420B8(Entity *pokemon, u32 r1)
{
    sub_804151C(pokemon, 0x19, 1);
}

void sub_80420C8(Entity *pokemon)
{
    sub_8041550(pokemon, 0x15, 1, 3, 2, 0);
}

void nullsub_92(Entity *pokemon)
{
}

void sub_80420E8(Entity *pokemon, struct DamageStruct *dmgStruct)
{
    u32 typeEffectiveness;
    u32 arg;
    typeEffectiveness = dmgStruct->typeEffectiveness;
    if(gDungeon->unk134.unk16D != 0)
        typeEffectiveness = sub_806F62C(dmgStruct->typeEffectiveness);
    switch(typeEffectiveness)
    {
        default:
        case EFFECTIVENESS_IMMUNE:
            arg = 8;
            break;
        case EFFECTIVENESS_RESIST:
            arg = 9;
            break;
        case EFFECTIVENESS_NEUTRAL:
            arg = 10;
            break;
        case EFFECTIVENESS_SUPER:
            arg = 11;
            break;
    }
    sub_8041550(pokemon, arg, 1, 3, 0, 1);
}

void sub_8042148(Entity *pokemon)
{
    sub_80421C0(pokemon, 0x1a7);
    sub_804151C(pokemon, 0x9F << 1, 1);
}

void nullsub_93()
{
}

void sub_804216C(Entity *pokemon, Entity *target, u32 r2)
{
    if(r2 == 1)
        sub_804151C(target, 0xF8, 1);
    else
        sub_804151C(target, 0xF9, 1);
}

void sub_804218C(Entity *pokemon, Entity *target)
{
    sub_804151C(target, 0x2A, 1);
}

void sub_804219C(PixelPos *pos)
{
    sub_80416E0(pos, 0x90, TRUE);
}

void sub_80421AC(Entity *pokemon, Entity * target)
{
    sub_804151C(target, 0x167, 1);
}

void sub_80421C0(Entity *pokemon, u16 r1)
{
    if (pokemon == NULL)
        PlaySoundEffect(r1);
    else if (sub_8042768(pokemon))
            PlaySoundEffect(r1);
}

void sub_80421EC(DungeonPos *pos, u16 r1)
{
    if(sub_803F428(pos))
        PlaySoundEffect(r1);
}

void sub_8042208(Entity *pokemon, u8 r1)
{
    if(r1 == 0)
        PlaySoundEffect(0x152);
    else if(r1 == 1)
        PlaySoundEffect(0x151);
    else
        PlaySoundEffect(0x150);
}

void sub_8042238(Entity *pokemon, Entity *target)
{
    if(GetEntInfo(target)->isNotTeamMember)
        PlaySoundEffect(0x157);
    else
        PlaySoundEffect(0x156);
}

void sub_804225C(Entity *entity, DungeonPos *pos, u8 trapId)
{
    s32 uVar6;
    DungeonPos newPos;
    s32 i, x, y;

    if (trapId == TRAP_WONDER_TILE)
        return;
    if (!sub_803F428(pos))
        return;

    sub_800EF28(trapId);
    sub_800EF64();
    sub_803E708(4,0x42);

    x = X_POS_TO_PIXELPOS(pos->x);
    newPos.x = x / 256;

    y = Y_POS_TO_PIXELPOS(pos->y);
    newPos.y = y / 256;

    uVar6 = sub_800E448(trapId,&newPos);
    if (trapId == TRAP_SUMMON_TRAP) {
        sub_80421C0(0,0x193);
        sub_803E708(0x28,0x33);
    }
    else if (trapId == TRAP_SPIN_TRAP) {
        EntityInfo *info = GetEntInfo(entity);
        s32 direction = info->action.direction;
        for (i = 0; i < 1000; i += 2) {
            direction--;
            direction &= DIRECTION_MASK;
            sub_806CDD4(entity,0,direction);
            sub_803E708(2,0x33);
            if (!sub_800E9A8(uVar6))
                break;
        }
        info->action.direction = direction & DIRECTION_MASK;
    }
    else {
        sub_803E708(0x28,0x33);
    }

    for (i = 0; i < 1000; i++) {
        DungeonRunFrameActions(0x42);
        if (!sub_800E9A8(uVar6))
            break;
    }
}

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
        sub_8004E8C(&local_58.unk1C);
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

static const u16 gUnknown_80F67DC[4] = {
    0xD8, 0xD9, 0xD9, 0x173
};
static const u16 gUnknown_80F67E4[4] = {
    0xDA, 0xDB, 0xDB, 0x174
};

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

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
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

static const s32 gUnknown_80F67EC[8] = {
    -1, 331, 239, -1, 16, 20, -1, 223
};
static const s32 gUnknown_80F680C[8] = {
    -1, 331, 239, -1, 440, 20, -1, 223
};
static const u16 gUnknown_80F682C[8] = {
    997, 997, 997, 425, 997, 997, 426, 997
};

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

static const unkStruct_2039DB0 gUnknown_80F683C = {0xFFFF, 0xFFFF, 0xFFFF, 0, 0, 0};

void sub_8042B34(s32 a0, s32 a1, s32 a2)
{
    unkStruct_80416E0 spStruct;
    s32 i;
    s32 r8 = 0;
    Entity *leader = xxx_call_GetLeader();
    gUnknown_203B414 = MemoryAlloc(sizeof(*gUnknown_203B414), 7);

    gUnknown_203B414->unk0 = a0;
    gUnknown_203B414->unk8 = (a1 + 1) * 4;
    sub_800EE5C(gUnknown_80F6624[a0][0].unk0);
    sub_800EF64();
    DungeonRunFrameActions(0x46);
    gUnknown_203B414->unk4 = a2;
    for (i = 0; i < gUnknown_203B414->unk8; i++) {
        s32 rnd;

        spStruct.unk0 = gUnknown_80F6624[gUnknown_203B414->unk0][r8].unk0;
        spStruct.unk4 = i;
        spStruct.dir = 0;
        spStruct.x = leader->pixelPos.x / 256;
        spStruct.y = leader->pixelPos.y / 256;

        rnd = RandInt(2);
        gUnknown_203B414->unk4C[i] = (gUnknown_80F6624[gUnknown_203B414->unk0][r8].unk4 * 2) + rnd;
        gUnknown_203B414->unk8C[i].x = RandInt(240) + 152;
        gUnknown_203B414->unk8C[i].y = RandInt(8 + (i * 2)) - (((i - (i / 4 * 4)) * 40) - 24);

        spStruct.unk10 = gUnknown_203B414->unk8C[i].x;
        spStruct.unk12 = gUnknown_203B414->unk8C[i].y;
        spStruct.unk14 = 4;
        spStruct.unk18 = 0xFFFF;
        spStruct.unk1C = gUnknown_80F683C;
        gUnknown_203B414->unkC[i] = sub_800E890(&spStruct);

        r8++;
        if (r8 >= 3 || gUnknown_80F6624[gUnknown_203B414->unk0][r8].unk0 == 0) {
            r8 = 0;
        }

        sub_800F15C(sub_800ECA4(spStruct.unk0)->effectId);
    }
}

bool8 sub_8042CC0(void)
{
    s32 i;
    bool8 ret = FALSE;

    if (gUnknown_203B414->unk4 != 0) {
        ret = TRUE;
        gUnknown_203B414->unk4--;
    }

    for (i = 0; i < gUnknown_203B414->unk8; i++) {
       gUnknown_203B414->unk8C[i].x -= gUnknown_203B414->unk4C[i];
       if (gUnknown_203B414->unk8C[i].x <= -152) {
            if (gUnknown_203B414->unk4 > 0) {
                gUnknown_203B414->unk8C[i].x = 152;
            }
            else {
                gUnknown_203B414->unk8C[i].x = -152;
            }
       }
       else {
            ret = TRUE;
       }
       sub_800E8AC(gUnknown_203B414->unkC[i], NULL, &gUnknown_203B414->unk8C[i], 0, NULL);
    }

    sub_800E90C(&gDungeon->unk181e8.cameraPixelPos);
    return ret;
}

void sub_8042D7C(void)
{
    s32 i;

    if (gUnknown_203B414 == NULL)
        return;

    for (i = 0; i < gUnknown_203B414->unk8; i++) {
        if (sub_800E9A8(gUnknown_203B414->unkC[i])) {
            sub_800DC14(gUnknown_203B414->unkC[i]);
        }
    }
    sub_800DBBC();
    MemoryFree(gUnknown_203B414);
    gUnknown_203B414 = NULL;
}

void sub_8042DD4(s32 a0, Entity *a1, s32 a2)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 == -1) {
            strPtr->unk0 = a0;
            strPtr->unkC = a1;
            strPtr->unk4 = a2;
            strPtr->unk8 = sub_800E6D8(a0);
            return;
        }
    }
}

static UNUSED bool32 sub_8042E1C(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 != -1 && sub_800E9A8(strPtr->unk0)) {
            return TRUE;
        }
    }

    return FALSE;
}

void sub_8042E5C(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 >= 0 && !sub_800E9A8(strPtr->unk0)) {
            strPtr->unk0 = -1;
            strPtr->unkC = NULL;
        }
    }
}

void sub_8042E98(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        strPtr->unk0 = -1;
        strPtr->unk4 = 0;
        strPtr->unkC = NULL;
    }
}

void sub_8042EC8(Entity *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 >= 0 && strPtr->unkC == a0) {
            DungeonPos sp8 = {a0->pixelPos.x / 256, a0->pixelPos.y / 256};
            DungeonPos sp4 = {0};
            EntityInfo *entInfo = GetEntInfo(a0);

            if (strPtr->unk8 != -1) {
                sub_800569C(&sp4,
                            &a0->axObj,
                            strPtr->unk8);
            }

            sub_800EB24(strPtr->unk0, &sp8, &sp4,a1, entInfo->action.direction);
        }
    }
}
