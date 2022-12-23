#include "global.h"
#include "dungeon.h"
#include "memory.h"
#include "pokemon.h"
#include "random.h"
#include "save.h"
#include "text_util.h"
#include "code_8094F88.h"

extern struct unkStruct_203B484 *gUnknown_203B484;
extern struct unkStruct_203B480 *gUnknown_203B480;
extern struct unkStruct_203B48C *gUnknown_203B48C;

extern void SaveDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void xxx_save_poke_sub_c_808F41C(struct unkStruct_8094924* a1, struct unkPokeSubStruct_C* unkC);
extern void xxx_restore_poke_sub_c_808F410(struct unkStruct_8094924*, struct unkPokeSubStruct_C*);
extern void SavePokemonMoves(struct unkStruct_8094924 *r0, struct PokemonMove *moveSet);
extern void RestorePokemonMoves(struct unkStruct_8094924 *r0, struct PokemonMove *moveSet);

void sub_8095824(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b);
void sub_8095774(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b);
s32 CountMailType(u8);

extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern s32 sub_8094E4C(void);
extern void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);
extern void sub_8094D28(s32);

struct unkStruct_809542C
{
    struct DungeonLocation unk0;
    u32 unk4;
};

bool8 sub_80951FC(struct unkStruct_203B480 *param_1)
{
  bool8 bVar1 = gUnknown_203B480[1].mailType != 0;
  gUnknown_203B480[1] = *param_1;
  return bVar1;
}

struct unkStruct_203B480 * sub_8095228(u8 index)
{
  struct unkStruct_203B480 *ptr;

  ptr = &gUnknown_203B480[index];
  return ptr;
}

void sub_8095240(u8 index)
{
  struct unkStruct_203B480 *unused;

  MemoryFill8((u8*)&gUnknown_203B480[index],0,sizeof(struct unkStruct_203B480));
  unused = &gUnknown_203B480[index];
  gUnknown_203B480[index].mailType = 0;
  unused = &gUnknown_203B480[index];
  gUnknown_203B480[index].unk20.itemIndex = 0;
}

void sub_8095274(u32 param_1)
{
  s32 iVar2;
  s32 iVar3;
  
  gUnknown_203B48C->unk4[gUnknown_203B48C->unk0] = param_1;
  iVar2 = gUnknown_203B48C->unk0;
  iVar3 = 0;
  if (iVar2 < 0x1f) {
    iVar3 = iVar2 + 1;
  }
  gUnknown_203B48C->unk0 = iVar3;
}

bool8 sub_8095298(s32 param_1)
{
  s32 index;
  
  for(index = 0; index < 0x20; index++)
  {
    if(gUnknown_203B48C->unk4[index] == param_1) return TRUE;
  }
  return FALSE;
}

void sub_80952C4(void)
{
  s32 index;
  
  gUnknown_203B48C->unk0 = 0;
  for(index = 0; index < 0x20; index++)
  {
    gUnknown_203B48C->unk4[index] = -1;
  }
}

bool8 sub_80952F0(u8 mailType, u32 param_2)
{
  struct unkStruct_203B480 *ptr;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if ((ptr->mailType == mailType) && (ptr->unk10 == param_2)) return TRUE;
  }
  return FALSE;
}

s32 CountMailType(u8 mailType)
{
  struct unkStruct_203B480 *ptr;
  s32 total = 0;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if (ptr->mailType == mailType) total++;
  }
  return total;
}

u32 sub_8095350(void)
{
  struct unkStruct_203B480 *ptr;
  u32 total = 0;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if (ptr->mailType != 0) total++;
  }
  return total;
}

s32 sub_8095374(void)
{
  struct unkStruct_203B480 *ptr;
  s32 retvar = -1;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if (ptr->mailType == 1) retvar = index;
  }
  return retvar;
}

s32 sub_809539C(u8 mailType, u32 param_2)
{
  struct unkStruct_203B480 *ptr;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if ((ptr->mailType == mailType) && (ptr->unk10 == param_2)) return index;
  }
  return -1;
}

s32 sub_80953D4(u8 mailType)
{
  struct unkStruct_203B480 *ptr;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if (ptr->mailType == mailType) return index;
  }
  return -1;
}

s32 sub_8095400(u32 param_1)
{
  u32 *ptr;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0].unk10; index < 0x20; ptr += 0xC, index++)
  {  
    if (*ptr == param_1) return index;
  }
  return -1;
}

void sub_809542C(struct unkStruct_809542C *param_1)
{
  u32 uVar4;

#ifndef NONMATCHING
  register struct unkStruct_203B480 *preload asm("r2");
#else
  struct unkStruct_203B480 *preload;
#endif

  u8 buffer [20];
  
  gUnknown_203B480->mailType = 1;
  preload = gUnknown_203B480;
  uVar4 = param_1->unk4;
  preload->dungeon = param_1->unk0;
  preload->unk8 = uVar4;
  sub_8094D28(Random());
  gUnknown_203B480->unk10 = sub_8094E4C();
  gUnknown_203B480->clientSpecies = GetPlayerPokemonStruct()->speciesNum;
  PrintPokeNameToBuffer(buffer, GetPlayerPokemonStruct());
  CopyStringtoBuffer(gUnknown_203B480->playerName, buffer);
  gUnknown_203B480->unk24 = sub_8011C34();
  gUnknown_203B480->unk2C = GetUnk3(gUnknown_203B480->dungeon.dungeonIndex);
}

void sub_8095494(struct unkStruct_809542C *param_1, u8 index)
{
  u32 uVar1;
  struct DungeonLocation temp;
  struct unkStruct_203B480 *mail;
  
  mail = gUnknown_203B480;
  mail += index;

  temp = mail->dungeon;
  uVar1 = mail->unk8;
  param_1->unk0 = temp;
  param_1->unk4 = uVar1;
}

u32 sub_80954B4(void)
{
    if(CountMailType(3) != 0)
        return 1;
    else
        return 0;
}

u32 sub_80954CC(u8 *a, u32 b)
{
    struct unkStruct_8094924 backup;
    struct PokemonStruct *temp;
    s32 index;

    xxx_init_struct_8094924_restore_809485C(&backup, a, b);
    for(index = 0; index < 0x20; index++)
    {
        sub_8095774(&backup, &gUnknown_203B480[index]);
    }
    RestoreIntegerBits(&backup, &gUnknown_203B484->unk0, 0x20);
    temp  = &gUnknown_203B484->unk4;
    memset(temp, 0, sizeof(struct PokemonStruct));
    RestoreIntegerBits(&backup, &temp->unk0, 2);
    RestoreIntegerBits(&backup, &temp->isLeader, 1);
    RestoreIntegerBits(&backup, &temp->unkHasNextStage, 7);
    RestoreDungeonLocation(&backup, &temp->dungeonLocation);
    RestoreIntegerBits(&backup, &temp->speciesNum, 9);
    xxx_restore_poke_sub_c_808F410(&backup, &temp->unkC[0]);
    xxx_restore_poke_sub_c_808F410(&backup, &temp->unkC[1]);
    RestoreIntegerBits(&backup, &temp->IQ, 0xA);
    RestoreIntegerBits(&backup, &temp->pokeHP, 0xA);
    RestoreIntegerBits(&backup, &temp->offense.att[0], 8);
    RestoreIntegerBits(&backup, &temp->offense.att[1], 8);
    RestoreIntegerBits(&backup, &temp->offense.def[0], 8);
    RestoreIntegerBits(&backup, &temp->offense.def[1], 8);
    RestoreIntegerBits(&backup, &temp->unk1C, 0x18);
    RestoreIntegerBits(&backup, &temp->IQSkills, 0x18);
    RestoreIntegerBits(&backup, &temp->unk24, 4);
    RestoreHeldItem(&backup, &temp->heldItem);
    RestorePokemonMoves(&backup, temp->moves);
    RestoreIntegerBits(&backup, temp->name, 0x50);

    RestoreIntegerBits(&backup, &gUnknown_203B48C->unk0, 0x20);
    for(index = 0; index < 0x20; index++)
    {
        RestoreIntegerBits(&backup, &gUnknown_203B48C->unk4[index], 0x20);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

u32 sub_8095624(u8 *a, u32 b)
{
    struct unkStruct_8094924 backup;
    struct PokemonStruct *temp;
    s32 index;

    xxx_init_struct_8094924_save_809486C(&backup, a, b);
    for(index = 0; index < 0x20; index++)
    {
        sub_8095824(&backup, &gUnknown_203B480[index]);
    }
    SaveIntegerBits(&backup, &gUnknown_203B484->unk0, 0x20);
    temp  = &gUnknown_203B484->unk4;
    SaveIntegerBits(&backup, &temp->unk0, 2);
    SaveIntegerBits(&backup, &temp->isLeader, 1);
    SaveIntegerBits(&backup, &temp->unkHasNextStage, 7);
    SaveDungeonLocation(&backup, &temp->dungeonLocation);
    SaveIntegerBits(&backup, &temp->speciesNum, 9);
    xxx_save_poke_sub_c_808F41C(&backup, &temp->unkC[0]);
    xxx_save_poke_sub_c_808F41C(&backup, &temp->unkC[1]);
    SaveIntegerBits(&backup, &temp->IQ, 0xA);
    SaveIntegerBits(&backup, &temp->pokeHP, 0xA);
    SaveIntegerBits(&backup, &temp->offense.att[0], 8);
    SaveIntegerBits(&backup, &temp->offense.att[1], 8);
    SaveIntegerBits(&backup, &temp->offense.def[0], 8);
    SaveIntegerBits(&backup, &temp->offense.def[1], 8);
    SaveIntegerBits(&backup, &temp->unk1C, 0x18);
    SaveIntegerBits(&backup, &temp->IQSkills, 0x18);
    SaveIntegerBits(&backup, &temp->unk24, 4);
    SaveHeldItem(&backup, &temp->heldItem);
    SavePokemonMoves(&backup, temp->moves);
    SaveIntegerBits(&backup, temp->name, 0x50);

    SaveIntegerBits(&backup, &gUnknown_203B48C->unk0, 0x20);
    for(index = 0; index < 0x20; index++)
    {
        SaveIntegerBits(&backup, &gUnknown_203B48C->unk4[index], 0x20);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

void sub_8095774(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b)
{
    u8 temp;

    RestoreIntegerBits(a, &b->mailType, 4);
    RestoreDungeonLocation(a, &b->dungeon);
    RestoreIntegerBits(a, &b->unk8, 0x18);
    RestoreIntegerBits(a, &b->clientSpecies, 0x9);
    RestoreIntegerBits(a, &b->unk10, 0x20);
    RestoreIntegerBits(a, &b->playerName, 0x50);
    RestoreIntegerBits(a, &b->unk20.itemFlags, 0x8);
    RestoreIntegerBits(a, &b->unk20.numItems, 0x8);
    RestoreIntegerBits(a, &b->unk20.itemIndex, 0x8);
    RestoreIntegerBits(a, &b->unk24, 0x20);
    RestoreIntegerBits(a, &b->unk28, 0x20);
    RestoreIntegerBits(a, &b->unk2C, 0x8);

    RestoreIntegerBits(a, &temp, 1);
    b->unk2D = temp & 1;
}

void sub_8095824(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b)
{
    u8 neg1;
    u8 zero;
    u8 *puVar2;
    neg1 = -1;
    zero = 0;

    SaveIntegerBits(a, &b->mailType, 4);
    SaveDungeonLocation(a, &b->dungeon);
    SaveIntegerBits(a, &b->unk8, 0x18);
    SaveIntegerBits(a, &b->clientSpecies, 0x9);
    SaveIntegerBits(a, &b->unk10, 0x20);
    SaveIntegerBits(a, &b->playerName, 0x50);
    SaveIntegerBits(a, &b->unk20.itemFlags, 0x8);
    SaveIntegerBits(a, &b->unk20.numItems, 0x8);
    SaveIntegerBits(a, &b->unk20.itemIndex, 0x8);
    SaveIntegerBits(a, &b->unk24, 0x20);
    SaveIntegerBits(a, &b->unk28, 0x20);
    SaveIntegerBits(a, &b->unk2C, 0x8);

    if(b->unk2D != 0)
        puVar2 = &neg1;
    else
        puVar2 = &zero;
    SaveIntegerBits(a, puVar2, 1);
}

void sub_80958E4(u32 *a, u32 b)
{
    *a = b;
}
