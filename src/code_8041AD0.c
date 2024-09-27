#include "global.h"
#include "code_800E9A8.h"
#include "code_803E46C.h"
#include "code_804267C.h"
#include "code_806CD90.h"
#include "code_8041AD0.h"
#include "type_chart.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "items.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"

// size: 0x1C
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


extern u32 gStatusSpriteMasks_SleepStatus[];
extern u32 gStatusSpriteMasks_NonVolatileStatus[];
extern u32 gStatusSpriteMasks_ImmobilizeStatus[];
extern u32 gStatusSpriteMasks_VolatileStatus[];
extern u32 gStatusSpriteMasks_ChargingStatus[];
extern u32 gStatusSpriteMasks_ProtectionStatus[];
extern u32 gStatusSpriteMasks_WaitingStatus[];
extern u32 gStatusSpriteMasks_LinkedStatus[];
extern u32 gStatusSpriteMasks_MoveStatus[];
extern u32 gStatusSpriteMasks_ItemStatus[];
extern u32 gStatusSpriteMasks_TransformStatus[];
extern u32 gStatusSpriteMasks_EyesightStatus[];
extern u32 gStatusSpriteMasks_MuzzledStatus[];


extern void sub_803ED30(u8, Entity *pokemon, u8, u8);
extern void sub_804151C(Entity *pokemon, u32 r1, u8 r2);
extern u32 sub_806F62C(u32);
extern void PlaySoundEffect(u32);
extern u8 sub_803F428(Position *pos);
extern void sub_8041550(Entity *pokemon, u32, u32, u32, u32, u32);

void sub_80421C0(Entity *pokemon, u16 r1);
void EntityUpdateStatusSprites(Entity *entity);

extern s32 gUnknown_202EDC8;
extern u8 gUnknown_203B40D;
extern s16 gUnknown_2026E4E;

extern void sub_800DBBC(void);
extern void sub_803EA10(void);
extern void sub_8042E98(void);
extern void sub_800EE5C(u32);
extern void sub_800EF64(void);
extern u32 sub_800E890(unkStruct_80416E0 *);

u32 sub_8041764(unkStruct_80416E0 *param_1, bool8 param_2);
s32 sub_80416E0(Position32 *pos, u32 param_2, bool8 param_3);

s32 sub_80416A4(Position *pos_1, u32 param_2, bool8 param_3)
{
  Position32 pos;

  pos.x = pos_1->x * 0x1800 + 0xc00;
  pos.y = pos_1->y * 0x1800 + 0x1000;
  return sub_80416E0(&pos, param_2, param_3);
}

s32 sub_80416E0(Position32 *pos, u32 param_2, bool8 param_3)
{
  int counter;
  s32 ret;
  unkStruct_80416E0 auStack_10;
  unkStruct_2039DB0 auStack_18; // Size: 0xC

  auStack_10.unk0 = param_2;
  auStack_10.unk4 = 0;
  auStack_10.unk8 = -1;

  auStack_10.x = pos->x / 256;
  auStack_10.y = pos->y / 256;

  auStack_10.unk14 = -1;
  auStack_10.unk10 = 0;
  auStack_10.unk12 = 0;
  auStack_10.unk18 = 0xffff;
  sub_8004E8C(&auStack_18);
  ret = sub_8041764(&auStack_10, FALSE);
  if (param_3) {
    counter = 0;
    while ((counter < 100 && (sub_800E9A8(ret)))) {
      sub_803E46C(0x42);
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
        sub_803E46C(0x42);
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
      sub_803E46C(0x4a);
      counter++;
    }
    sub_803E46C(0x4a);
    sub_803E46C(0x4a);
  }
  if ((counter == 1000) || (param_1 != 0)) {
    sub_800DBBC();
  }
  if (gUnknown_202EDC8 < 0x1f) {
    temp = gUnknown_203B40D;
    gUnknown_203B40D = 1;
    for(counter = 0; counter < 1000; counter++)
    {
      if (gUnknown_202EDC8 < 0x1f) {
        gUnknown_202EDC8 += 4;
        if (gUnknown_2026E4E != 0x808) {
          gUnknown_2026E4E -= 0x101;
        }
      }
      else {
        gUnknown_202EDC8 = 0x1f;
      }
      sub_803EA10();
      sub_803E46C(0x4a);
      if(gUnknown_202EDC8 == 0x1f) break;
    };
    gUnknown_2026E4E = 0x808;
    gUnknown_203B40D = temp;
  }
  sub_8042E98();
}

u32 EntityGetStatusSprites(Entity *entity)
{
    return entity->axObj.info->statusIcons;
}

void sub_8041888(u8 param_1)
{
    s32 index;
    Entity *entity;
    EntityInfo *entityInfo;
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if(EntityExists(entity))
        {
            entityInfo = entity->axObj.info;
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

  if (EntityExists(entity)) {
    entityInfo = entity->axObj.info;
    spriteStatus = 0;
    flag = TRUE;

    if (entityInfo->id == 0xb9) {
      // NOTE: clean this up sometime
      temp = entityInfo->sleep.sleepTurns;
      flag = 0x7f;
      temp ^= flag;
      flag = (temp) != 0;
    }
    if (flag) {
      spriteStatus = gStatusSpriteMasks_SleepStatus[entityInfo->sleep.sleep];
    }
    spriteStatus = spriteStatus |
            gStatusSpriteMasks_NonVolatileStatus[entityInfo->nonVolatile.nonVolatileStatus] |
            gStatusSpriteMasks_ImmobilizeStatus[entityInfo->immobilize.immobilizeStatus] |
            gStatusSpriteMasks_VolatileStatus[entityInfo->volatileStatus.volatileStatus] |
            gStatusSpriteMasks_ChargingStatus[entityInfo->charging.chargingStatus] |
            gStatusSpriteMasks_ProtectionStatus[entityInfo->protection.protectionStatus] |
            gStatusSpriteMasks_WaitingStatus[entityInfo->waitingStruct.waitingStatus] |
            gStatusSpriteMasks_LinkedStatus[entityInfo->linked.linkedStatus] |
            gStatusSpriteMasks_MoveStatus[entityInfo->moveStatus.moveStatus] |
            gStatusSpriteMasks_ItemStatus[entityInfo->itemStatus.itemStatus] |
            gStatusSpriteMasks_TransformStatus[entityInfo->transformStatus.transformStatus] |
            gStatusSpriteMasks_EyesightStatus[entityInfo->eyesightStatus.eyesightStatus] |
            gStatusSpriteMasks_MuzzledStatus[entityInfo->muzzled.muzzled];

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
    if ((gDungeon->itemHoldersIdentified) && (entityInfo->heldItem.flags & ITEM_FLAG_EXISTS)) {
      spriteStatus = spriteStatus | STATUS_SPRITE_LOWHP;
    }
    if ( (entityInfo->offensiveMultipliers[0] < DEFAULT_STAT_MULTIPLIER) ||
        (entityInfo->offensiveMultipliers[1] < DEFAULT_STAT_MULTIPLIER) ||
        (entityInfo->defensiveMultipliers[0] < DEFAULT_STAT_MULTIPLIER) ||
        (entityInfo->defensiveMultipliers[1] < DEFAULT_STAT_MULTIPLIER) ||
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

    sub_803ED30(pokemon->axObj.info->stockpileStage, pokemon, 1, 11);
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
    if(gDungeon->unk16D != 0)
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

void sub_804219C(Position32 *pos)
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

void sub_80421EC(Position *pos, u16 r1)
{
    if(sub_803F428(pos) != 0)
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
    if(target->axObj.info->isNotTeamMember)
        PlaySoundEffect(0x157);
    else
        PlaySoundEffect(0x156);
}
