#include "global.h"
#include "code_8094F88.h"
#include "constants/wonder_mail.h"
#include "memory.h"
#include "moves.h"
#include "dungeon.h"
#include "random.h"
#include "save.h"
#include "text_util.h"

EWRAM_DATA_2 struct unkStruct_203B480 *gUnknown_203B480 = {0};
EWRAM_DATA_2 struct unkStruct_203B484 *gUnknown_203B484 = {0};
EWRAM_DATA_2 u32 *gUnknown_203B488 = {0};
EWRAM_DATA_2 struct unkStruct_203B48C *gUnknown_203B48C = {0};

EWRAM_DATA struct unkStruct_203B480 gUnknown_2038C88[0x20] = {0};
EWRAM_DATA struct unkStruct_203B484 gUnknown_2039288 = {0};
EWRAM_DATA UNUSED static u32 fill0 = {0}; // 203B484 is size 0x5C and I need to fill a gap of 0x4
EWRAM_DATA u32 gUnknown_20392E8[0x36] = {0};
EWRAM_DATA struct unkStruct_203B48C gUnknown_20393C0 = {0};

extern void SaveDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void xxx_save_poke_sub_c_808F41C(struct unkStruct_8094924* a1, struct unkPokeSubStruct_C* unkC);
extern void xxx_restore_poke_sub_c_808F410(struct unkStruct_8094924*, struct unkPokeSubStruct_C*);

extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern s32 sub_8094E4C(void);
extern void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);
extern void sub_8094D28(s32);

void sub_80950BC(void)
{
    gUnknown_203B480 = gUnknown_2038C88;
    gUnknown_203B484 = &gUnknown_2039288;
    gUnknown_203B488 = gUnknown_20392E8;
    gUnknown_203B48C = &gUnknown_20393C0;
}

struct unkStruct_203B480 *sub_80950F8(void)
{
    return gUnknown_2038C88;
}

struct unkStruct_203B484 *sub_8095100(void)
{
    return &gUnknown_2039288;
}

u32 *sub_8095108(void)
{
    return gUnknown_20392E8;
}

struct unkStruct_203B48C *sub_8095110(void)
{
    return &gUnknown_20393C0;
}


void sub_8095118(void)
{
  s32 index;
  struct unkStruct_203B480 *unused;
  
  MemoryFill8((u8*)gUnknown_203B480,0, 0x20 * sizeof(struct unkStruct_203B480));
  MemoryFill8((u8*)gUnknown_203B484,0, sizeof(struct unkStruct_203B484));
  for(index = 0; index < 0x20; index++){

    // NOTE: we use a temp variable here to force the match
    unused = &gUnknown_203B480[index];
    gUnknown_203B480[index].mailType = WONDER_MAIL_TYPE_NONE;
    unused = &gUnknown_203B480[index];
    gUnknown_203B480[index].item.id = ITEM_NOTHING;
    unused = &gUnknown_203B480[index];
    gUnknown_203B480[index].unk2D = 0;
  }
  gUnknown_203B48C->unk0 = 0;
  for(index = 0; index < 0x20; index++){
    gUnknown_203B48C->unk4[index] = -1;
  }
}

void nullsub_206(void)
{
}

void nullsub_207(void)
{
}

s32 FindOpenMailSlot(void)
{
  s32 index;
  
  for(index = 2; index < 0x20; index++){
    if(gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_NONE)
        return index;
  }
  return -1;
}

// Fakematch
bool8 sub_80951BC(struct unkStruct_203B480 *mail)
{
    s32 index;
    struct unkStruct_203B480 *preload;
    struct unkStruct_203B480 *preload2;

    index = FindOpenMailSlot();

    if(index == -1)
    {
        return 0;
    }
    else
    {
        preload = gUnknown_203B480;
        preload2 = &preload[index];
        *preload2 = *mail;
        return 1;
    }
}

bool8 sub_80951FC(struct unkStruct_203B480 *param_1)
{
  bool8 bVar1 = gUnknown_203B480[1].mailType != 0;
  gUnknown_203B480[1] = *param_1;
  return bVar1;
}

struct unkStruct_203B480 * GetMailatIndex(u8 index)
{
  struct unkStruct_203B480 *ptr;

  ptr = &gUnknown_203B480[index];
  return ptr;
}

void DeleteMailAtIndex(u8 index)
{
  struct unkStruct_203B480 *unused;

  MemoryFill8((u8*)&gUnknown_203B480[index],0,sizeof(struct unkStruct_203B480));
  unused = &gUnknown_203B480[index];
  gUnknown_203B480[index].mailType = 0;
  unused = &gUnknown_203B480[index];
  gUnknown_203B480[index].item.id = 0;
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

bool8 HasMail(u8 mailType, u32 param_2)
{
  struct unkStruct_203B480 *ptr;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if ((ptr->mailType == mailType) && (ptr->unk10.unk10 == param_2)) return TRUE;
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

u32 CountAllMail(void)
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

/* With mailType and (additonal data??), search mail and return exact index */
s32 GetMailIndex(u8 mailType, u32 param_2)
{
  struct unkStruct_203B480 *ptr;
  s32 index;
  
  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {  
    if ((ptr->mailType == mailType) && (ptr->unk10.unk10 == param_2)) return index;
  }
  return -1;
}

/* Return the index of the first mail of the requested type */
s32 GetFirstIndexofMailType(u8 mailType)
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
  
  for(index = 0, ptr = &gUnknown_203B480[0].unk10.unk10; index < 0x20; ptr += 0xC, index++)
  {  
    if (*ptr == param_1) return index;
  }
  return -1;
}

void sub_809542C(struct WonderMailSub *param_1)
{
  u32 seed;

#ifndef NONMATCHING
  register struct unkStruct_203B480 *preload asm("r2");
#else
  struct unkStruct_203B480 *preload;
#endif

  u8 buffer [20];
  
  gUnknown_203B480->mailType = 1;
  preload = gUnknown_203B480;
  seed = param_1->seed;
  preload->unk4.dungeon = param_1->dungeon;
  preload->unk4.seed = seed;
  sub_8094D28(Rand32Bit());
  gUnknown_203B480->unk10.unk10 = sub_8094E4C();
  gUnknown_203B480->clientSpecies = GetPlayerPokemonStruct()->speciesNum;
  PrintPokeNameToBuffer(buffer, GetPlayerPokemonStruct());
  CopyStringtoBuffer(gUnknown_203B480->playerName, buffer);
  gUnknown_203B480->unk24 = sub_8011C34();
  gUnknown_203B480->rescuesAllowed = GetRescuesAllowed(gUnknown_203B480->unk4.dungeon.id);
}

void sub_8095494(struct WonderMailSub *param_1, u8 index)
{
  u32 seed;
  struct DungeonLocation dungeon;
  struct unkStruct_203B480 *mail;
  
  mail = gUnknown_203B480;
  mail += index;

  dungeon = mail->unk4.dungeon;
  seed = mail->unk4.seed;
  param_1->dungeon = dungeon;
  param_1->seed = seed;
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
    RestoreIntegerBits(&backup, &temp->isTeamLeader, 1);
    RestoreIntegerBits(&backup, &temp->level, 7);
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
    RestoreIntegerBits(&backup, &temp->currExp, 0x18);
    RestoreIntegerBits(&backup, &temp->IQSkills, 0x18);
    RestoreIntegerBits(&backup, &temp->tacticIndex, 4);
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
    SaveIntegerBits(&backup, &temp->isTeamLeader, 1);
    SaveIntegerBits(&backup, &temp->level, 7);
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
    SaveIntegerBits(&backup, &temp->currExp, 0x18);
    SaveIntegerBits(&backup, &temp->IQSkills, 0x18);
    SaveIntegerBits(&backup, &temp->tacticIndex, 4);
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
    RestoreDungeonLocation(a, &b->unk4.dungeon);
    RestoreIntegerBits(a, &b->unk4.seed, 0x18);
    RestoreIntegerBits(a, &b->clientSpecies, 0x9);
    RestoreIntegerBits(a, &b->unk10.unk10, 0x20);
    RestoreIntegerBits(a, &b->playerName, 0x50);
    RestoreIntegerBits(a, &b->item.flags, 0x8);
    RestoreIntegerBits(a, &b->item.quantity, 0x8);
    RestoreIntegerBits(a, &b->item.id, 0x8);
    RestoreIntegerBits(a, &b->unk24, 0x20);
    RestoreIntegerBits(a, &b->unk28, 0x20);
    RestoreIntegerBits(a, &b->rescuesAllowed, 0x8);

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
    SaveDungeonLocation(a, &b->unk4.dungeon);
    SaveIntegerBits(a, &b->unk4.seed, 0x18);
    SaveIntegerBits(a, &b->clientSpecies, 0x9);
    SaveIntegerBits(a, &b->unk10.unk10, 0x20);
    SaveIntegerBits(a, &b->playerName, 0x50);
    SaveIntegerBits(a, &b->item.flags, 0x8);
    SaveIntegerBits(a, &b->item.quantity, 0x8);
    SaveIntegerBits(a, &b->item.id, 0x8);
    SaveIntegerBits(a, &b->unk24, 0x20);
    SaveIntegerBits(a, &b->unk28, 0x20);
    SaveIntegerBits(a, &b->rescuesAllowed, 0x8);

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
