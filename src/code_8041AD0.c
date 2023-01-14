#include "global.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "item.h"

struct unkStruct_80420E8
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

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


extern void sub_803ED30(u8, struct DungeonEntity *pokemon, u8, u8);
extern void sub_804151C(struct DungeonEntity *pokemon, u32 r1, u8 r2);
extern void sub_80416E0(struct DungeonEntity *pokemon, u32, u32);
extern u8 sub_8042768(struct DungeonEntity *pokemon);
extern void sub_806CDD4(struct DungeonEntity *pokemon, u8, u32);
extern u32 sub_806F62C(u32);
extern void PlaySoundEffect(u32);
extern u8 sub_803F428(struct DungeonEntity *pokemon);
extern void sub_8041550(struct DungeonEntity *pokemon, u32, u32, u32, u32, u32);


void sub_80421C0(struct DungeonEntity *pokemon, u16 r1);
void DungeonEntityUpdateStatusSprites(struct DungeonEntity *entity);


extern s32 gUnknown_202EDC8;
extern u8 gUnknown_203B40D;
extern s16 gUnknown_2026E4E;

extern u8 sub_800E9FC(u8);
extern void sub_800DBBC(void);
extern void sub_803EA10(void);
extern void sub_8042E98(void);
extern void sub_803E46C(u32);
extern void sub_800EE5C(u32);
extern u32 sub_800E890(u32 *);
extern void sub_800EF64(void);

u32 sub_8041764(u32 *param_1, u8 param_2)
{
    sub_800EE5C(*param_1);
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
  gDungeonGlobalData->unk18204 = 0;
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

u32 EntityGetStatusSprites(struct DungeonEntity *entity)
{
    return entity->entityData->statusSprites;
}

void sub_8041888(u8 param_1)
{
    s32 index;
    struct DungeonEntity *entity;
    struct DungeonEntityData *entityData;
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeonGlobalData->allPokemon[index];
        if(EntityExists(entity))
        {
            entityData = entity->entityData;
            if(param_1)
            {
                entityData->unk14C = 1;
            }
            DungeonEntityUpdateStatusSprites(entity);
        }
    }
}

void DungeonEntityUpdateStatusSprites(struct DungeonEntity *entity)
{
  bool32 flag;
  s32 HP;
  struct DungeonEntityData *entityData;
  u32 spriteStatus;
  u8 temp;
  
  if (EntityExists(entity)) {
    entityData = entity->entityData;
    spriteStatus = 0;
    flag = TRUE;

    if (entityData->entityID == 0xb9) {
      // NOTE: clean this up sometime
      temp = entityData->sleepStatusTurnsLeft; 
      flag = 0x7f;
      temp ^= flag;
      flag = (temp) != 0;
    }
    if (flag) {
      spriteStatus = gStatusSpriteMasks_SleepStatus[entityData->sleepStatus];
    }
    spriteStatus = spriteStatus | 
            gStatusSpriteMasks_NonVolatileStatus[entityData->nonVolatileStatus] |
            gStatusSpriteMasks_ImmobilizeStatus[entityData->immobilizeStatus] |
            gStatusSpriteMasks_VolatileStatus[entityData->volatileStatus] |
            gStatusSpriteMasks_ChargingStatus[entityData->chargingStatus] |
            gStatusSpriteMasks_ProtectionStatus[entityData->protectionStatus] |
            gStatusSpriteMasks_WaitingStatus[entityData->waitingStatus] |
            gStatusSpriteMasks_LinkedStatus[entityData->linkedStatus] |
            gStatusSpriteMasks_MoveStatus[entityData->moveStatus] |
            gStatusSpriteMasks_ItemStatus[entityData->itemStatus] |
            gStatusSpriteMasks_TransformStatus[entityData->transformStatus] |
            gStatusSpriteMasks_EyesightStatus[entityData->eyesightStatus] |
            gStatusSpriteMasks_MuzzledStatus[entityData->muzzledStatus];

    if (entityData->grudgeStatus) {
      spriteStatus = spriteStatus | STATUS_SPRITE_GRUDGE;
    }
    if (entityData->exposedStatus) {
      spriteStatus = spriteStatus | STATUS_SPRITE_EXPOSED;
    }
    if (!entityData->isEnemy) {
      HP = entityData->maxHP;
      if (HP < 0) {
        HP += 3;
      }
      HP >>= 2;
      if (HP > entityData->HP) {
        spriteStatus = spriteStatus | STATUS_SPRITE_LOWHP;
      }
    }
    if ((gDungeonGlobalData->itemHoldersIdentified) && (entityData->heldItem.itemFlags & ITEM_FLAG_EXISTS)) {
      spriteStatus = spriteStatus | STATUS_SPRITE_LOWHP;
    }
    if ( (entityData->attackMultipliers[0] < DEFAULT_STAT_MULTIPLIER) || 
        (entityData->attackMultipliers[1] < DEFAULT_STAT_MULTIPLIER) ||
        (entityData->defenseMultipliers[0] < DEFAULT_STAT_MULTIPLIER) ||
        (entityData->defenseMultipliers[1] < DEFAULT_STAT_MULTIPLIER) ||
        (entityData->attackStages[0] < DEFAULT_STAT_STAGE) ||
        (entityData->attackStages[1] < DEFAULT_STAT_STAGE) ||
        (entityData->defenseStages[0] < DEFAULT_STAT_STAGE) || 
        (entityData->defenseStages[1] < DEFAULT_STAT_STAGE) ||
        (entityData->accuracyStages[0]) < DEFAULT_STAT_STAGE || 
        (entityData->accuracyStages[1] < DEFAULT_STAT_STAGE)) {
        spriteStatus = spriteStatus | STATUS_SPRITE_STAT_DOWN;
    }
    entityData->statusSprites = spriteStatus;
  }
}

void sub_8041AD0(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xA2 << 1, 1);
}

void sub_8041AE0(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x143, 1);
}

void sub_8041AF4(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x25, 1);
    sub_80421C0(pokemon, 0x197);
}

void nullsub_57(void)
{
}

void sub_8041B18(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x141, 1);
}

void nullsub_58(void)
{
}

void nullsub_59(void)
{
}

void sub_8041B34(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 7, 1);
}

void nullsub_60(void)
{
}

void sub_8041B48(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 4, 0);
}

void nullsub_61(void)
{
}

void sub_8041B5C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x171, 1);
}

void nullsub_62(struct DungeonEntity *pokemon)
{
}

void sub_8041B74(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x171, 0);
}

void nullsub_63(void)
{
}

void nullsub_64(void)
{
}

void sub_8041B90(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xD6 << 1, 0);
}

void nullsub_65(void)
{
}

void nullsub_66(void)
{
}

void sub_8041BA8(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 4, 1);
}

void nullsub_67(void)
{
}

void sub_8041BBC(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xD4 << 1, 1);
}

void nullsub_68(void)
{
}

void sub_8041BD0(struct DungeonEntity *pokemon, u8 r1)
{
    if(r1 == 0)
    {
        return;
    }
    sub_80421C0(pokemon, 0x1a5);
}

void sub_8041BE8(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0xCB << 1);
}

void sub_8041BF8(struct DungeonEntity *pokemon)
{
    sub_806CDD4(pokemon, 0xA, NUM_DIRECTIONS);
}

void sub_8041C08(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x1a7, 1);
}

void sub_8041C1C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x1a7, 1);
}

void nullsub_69(void)
{
}

void sub_8041C34(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x4C, 1);
}

void nullsub_70(void)
{
}

void nullsub_71(void)
{
}

void sub_8041C4C(struct DungeonEntity *pokemon, u32 r1)
{
    sub_804151C(pokemon, r1, 1);
}

void sub_8041C58(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x1a9, 1);
}

void sub_8041C6C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x9D << 1, 1);
}

void sub_8041C7C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x9D << 1, 1);
}

void nullsub_72(void)
{
}

void nullsub_73(void)
{
}

void sub_8041C94(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x171, 1);
}

void sub_8041CA8(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 7, 1);
}

void sub_8041CB8(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x18b, 1);
}

void sub_8041CCC(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xC5 << 1, 1);
}

void sub_8041CDC(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 5, 1);
}

void sub_8041CEC(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0x19d);
}

void nullsub_74(void)
{
}

void sub_8041D00(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_804151C(target, 0x2F, 1);
    sub_804151C(pokemon, 0x30, 1);
}

void nullsub_75(struct DungeonEntity *pokemon)
{
}

void nullsub_76(struct DungeonEntity *pokemon)
{
}

void nullsub_77(struct DungeonEntity *pokemon)
{
}

void nullsub_78(struct DungeonEntity *pokemon)
{
}

void nullsub_79(struct DungeonEntity *pokemon)
{
}

void nullsub_80(struct DungeonEntity *pokemon)
{
}

void sub_8041D38(struct DungeonEntity * pokemon)
{
    sub_804151C(pokemon, 0x21, 1);
}

void sub_8041D48(struct DungeonEntity * pokemon)
{
    sub_80421C0(pokemon, 0x191);
}

void nullsub_81(void)
{
}

void sub_8041D5C(struct DungeonEntity *pokemon)
{
    if(sub_8042768(pokemon) == 0)
    {
        return;
    }
    sub_803ED30(pokemon->entityData->stockpileCount, pokemon, 1, 0xB);
}

void sub_8041D84(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0x19f);
}

void nullsub_82(void)
{
}

void nullsub_83(void)
{
}

void sub_8041D9C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x131, 1);
}

void sub_8041DB0(struct DungeonEntity *pokemon)
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

void sub_8041DD8(struct DungeonEntity *pokemon, s16 r1)
{
    u32 temp;
    temp = r1;

    if(HasType(pokemon, TYPE_GHOST) != 0)
        sub_804151C(pokemon, temp, 1);
    else
        sub_804151C(pokemon, TYPE_GHOST, 1);
}

void nullsub_89(void)
{
}

void sub_8041E0C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x41, 1);
}

void sub_8041E1C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x8F << 1, 1);
    sub_80421C0(pokemon, 0xCE << 1);
}

void sub_8041E3C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xD7 << 1, 1);
}

void sub_8041E4C(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x1b1, 1);
}

void sub_8041E60(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x1a9, 1);
}

void sub_8041E74(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xC9 << 1, 1);
}

void sub_8041E84(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xC7 << 1, 1);
}

void sub_8041E94(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xC8 << 1, 1);
}

void sub_8041EA4(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x15, 1);
}

void sub_8041EB4(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x171, 1);
}

void sub_8041EC8(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0x197);
}

void sub_8041ED8(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0x197);
}

void sub_8041EE8(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0x15, 1);
}

void sub_8041EF8(struct DungeonEntity *pokemon)
{
    sub_804151C(pokemon, 0xF, 1);
}

void sub_8041F08(struct DungeonEntity *pokemon)
{
    sub_8041550(pokemon, 0x15, 1, 3, 2, 0);
}

void nullsub_90(void)
{
}

void sub_8041F28(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8041F4C(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8041F70(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8041F94(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8041FB4(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8041FD8(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8041FFC(struct DungeonEntity *pokemon, u32 r1)
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

void sub_804201C(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8042040(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8042060(struct DungeonEntity *pokemon, u32 r1)
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

void sub_8042080(struct DungeonEntity *pokemon, u32 r1)
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

void sub_80420A0(struct DungeonEntity *pokemon, u32 r1)
{
    sub_804151C(pokemon, 0x143, 1);
}

void nullsub_91(void)
{
}

void sub_80420B8(struct DungeonEntity *pokemon, u32 r1)
{
    sub_804151C(pokemon, 0x19, 1);
}

void sub_80420C8(struct DungeonEntity *pokemon)
{
    sub_8041550(pokemon, 0x15, 1, 3, 2, 0);
}

void nullsub_92(struct DungeonEntity *pokemon)
{
}

void sub_80420E8(struct DungeonEntity *pokemon, struct unkStruct_80420E8 *r1)
{
    u32 temp;
    u32 arg;
    temp = r1->unk8;
    if(gDungeonGlobalData->unk16D != 0)
        temp = sub_806F62C(r1->unk8);
    switch(temp)
    {
        default:
        case 0:
            arg = 8;
            break;
        case 1:
            arg = 9;
            break;
        case 2:
            arg = 10;
            break;
        case 3:
            arg = 11;
            break;
    }
    sub_8041550(pokemon, arg, 1, 3, 0, 1);
}

void sub_8042148(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0x1a7);
    sub_804151C(pokemon, 0x9F << 1, 1);
}

void nullsub_93()
{
}

void sub_804216C(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32 r2)
{
    if(r2 == 1)
        sub_804151C(target, 0xF8, 1);
    else
        sub_804151C(target, 0xF9, 1);
}

void sub_804218C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_804151C(target, 0x2A, 1);
}

void sub_804219C(struct DungeonEntity *pokemon)
{
    sub_80416E0(pokemon, 0x90, 1);
}

void sub_80421AC(struct DungeonEntity *pokemon, struct DungeonEntity * target)
{
    sub_804151C(target, 0x167, 1);
}

void sub_80421C0(struct DungeonEntity *pokemon, u16 r1)
{
    if(pokemon == NULL)
        PlaySoundEffect(r1);
    else
        if(sub_8042768(pokemon) != 0)
            PlaySoundEffect(r1);
}

void sub_80421EC(struct DungeonEntity *pokemon, u16 r1)
{
    if(sub_803F428(pokemon) != 0)
        PlaySoundEffect(r1);
}

void sub_8042208(struct DungeonEntity *pokemon, u8 r1)
{
    if(r1 == 0)
        PlaySoundEffect(0x152);
    else if(r1 == 1)
        PlaySoundEffect(0x151);
    else
        PlaySoundEffect(0x150);
}

void sub_8042238(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    if(target->entityData->isEnemy)
        PlaySoundEffect(0x157);
    else
        PlaySoundEffect(0x156);
}
