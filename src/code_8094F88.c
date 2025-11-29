#include "global.h"
#include "globaldata.h"
#include "random_mersenne_twister.h"
#include "code_8094F88.h"
#include "constants/wonder_mail.h"
#include "dungeon_info.h"
#include "memory.h"
#include "moves.h"
#include "pokemon.h"
#include "random.h"
#include "save.h"
#include "text_util.h"
#include "pokemon_3.h"

EWRAM_INIT unkStruct_203B480 *gUnknown_203B480 = {NULL};
EWRAM_INIT unkStruct_203B484 *gUnknown_203B484 = {NULL};
EWRAM_INIT u32 *gUnknown_203B488 = {NULL};
EWRAM_INIT unkStruct_203B48C *gUnknown_203B48C = {NULL};

EWRAM_DATA unkStruct_203B480 gUnknown_2038C88[0x20] = {0};
EWRAM_DATA unkStruct_203B484 gUnknown_2039288 = {0};
EWRAM_DATA UNUSED static u32 fill0 = {0}; // 203B484 is size 0x5C and I need to fill a gap of 0x4
EWRAM_DATA u32 gUnknown_20392E8[0x36] = {0};
EWRAM_DATA unkStruct_203B48C gUnknown_20393C0 = {0};

void sub_80950BC(void)
{
    gUnknown_203B480 = gUnknown_2038C88;
    gUnknown_203B484 = &gUnknown_2039288;
    gUnknown_203B488 = gUnknown_20392E8;
    gUnknown_203B48C = &gUnknown_20393C0;
}

unkStruct_203B480 *sub_80950F8(void)
{
    return gUnknown_2038C88;
}

unkStruct_203B484 *sub_8095100(void)
{
    return &gUnknown_2039288;
}

u32 *sub_8095108(void)
{
    return gUnknown_20392E8;
}

unkStruct_203B48C *sub_8095110(void)
{
    return &gUnknown_20393C0;
}


void sub_8095118(void)
{
  s32 index;
  UNUSED unkStruct_203B480 *unused;

  MemoryFill8(gUnknown_203B480, 0, 0x20 * sizeof(unkStruct_203B480));
  MemoryFill8(gUnknown_203B484, 0, sizeof(unkStruct_203B484));
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

UNUSED static void nullsub_206(void)
{
}

UNUSED static void nullsub_207(void)
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
bool8 sub_80951BC(unkStruct_203B480 *mail)
{
    s32 index;
    unkStruct_203B480 *preload;
    unkStruct_203B480 *preload2;

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

bool8 sub_80951FC(unkStruct_203B480 *param_1)
{
  bool8 bVar1 = gUnknown_203B480[1].mailType != 0;
  gUnknown_203B480[1] = *param_1;
  return bVar1;
}

unkStruct_203B480 * GetMailatIndex(u8 index)
{
  unkStruct_203B480 *ptr;

  ptr = &gUnknown_203B480[index];
  return ptr;
}

void DeleteMailAtIndex(u8 index)
{
  UNUSED unkStruct_203B480 *unused;

  MemoryFill8(&gUnknown_203B480[index], 0, sizeof(unkStruct_203B480));
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
  unkStruct_203B480 *ptr;
  s32 index;

  for(index = 0, ptr = &gUnknown_203B480[0]; index < 0x20; ptr++, index++)
  {
    if ((ptr->mailType == mailType) && (ptr->unk10.unk10 == param_2)) return TRUE;
  }
  return FALSE;
}

s32 CountMailType(u8 mailType)
{
  unkStruct_203B480 *ptr;
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
  unkStruct_203B480 *ptr;
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
  unkStruct_203B480 *ptr;
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
  unkStruct_203B480 *ptr;
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
  unkStruct_203B480 *ptr;
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

void sub_809542C(DungeonMailSeed *param_1)
{
  u8 buffer[20];

  gUnknown_203B480->mailType = 1;
  gUnknown_203B480->dungeonSeed = *param_1;
  MersenneTwister_InitializeState(Rand32Bit());
  gUnknown_203B480->unk10.unk10 = Random32MersenneTwister();
  gUnknown_203B480->clientSpecies = GetLeaderMon1()->speciesNum;
  PrintPokeNameToBuffer(buffer, GetLeaderMon1());
  CopyStringtoBuffer(gUnknown_203B480->playerName, buffer);
  gUnknown_203B480->unk24 = sub_8011C34();
  gUnknown_203B480->rescuesAllowed = GetRescuesAllowed(gUnknown_203B480->dungeonSeed.location.id);
}

void sub_8095494(DungeonMailSeed *param_1, u8 index)
{
  u32 seed;
  DungeonLocation dungeon;
  unkStruct_203B480 *mail;

  mail = gUnknown_203B480;
  mail += index;

  dungeon = mail->dungeonSeed.location;
  seed = mail->dungeonSeed.seed;
  param_1->location = dungeon;
  param_1->seed = seed;
}

u32 sub_80954B4(void)
{
    if(CountMailType(3) != 0)
        return 1;
    else
        return 0;
}






// New file?









u32 sub_80954CC(u8 *buffer, u32 size)
{
    DataSerializer backup;
    Pokemon *mon;
    s32 i;

    InitBitReader(&backup, buffer, size);

    for (i = 0; i < 32; i++) {
        sub_8095774(&backup, &gUnknown_203B480[i]);
    }

    ReadBits(&backup, &gUnknown_203B484->unk0, 32);

    mon = &gUnknown_203B484->unk4;
    memset(mon, 0, sizeof(Pokemon));

    ReadBits(&backup, &mon->flags, 2);
    ReadBits(&backup, &mon->isTeamLeader, 1);
    ReadBits(&backup, &mon->level, 7);
    ReadDungeonLocationBits(&backup, &mon->dungeonLocation);
    ReadBits(&backup, &mon->speciesNum, 9);
    ReadPoke1LevelBits(&backup, &mon->unkC[0]);
    ReadPoke1LevelBits(&backup, &mon->unkC[1]);
    ReadBits(&backup, &mon->IQ, 10);
    ReadBits(&backup, &mon->pokeHP, 10);
    ReadBits(&backup, &mon->offense.att[0], 8);
    ReadBits(&backup, &mon->offense.att[1], 8);
    ReadBits(&backup, &mon->offense.def[0], 8);
    ReadBits(&backup, &mon->offense.def[1], 8);
    ReadBits(&backup, &mon->currExp, 24);
    ReadBits(&backup, &mon->IQSkills, 24);
    ReadBits(&backup, &mon->tacticIndex, 4);
    ReadHeldItemBits(&backup, &mon->heldItem);
    ReadPoke1MovesBits(&backup, mon->moves);
    ReadBits(&backup, mon->name, 10 * 8);

    ReadBits(&backup, &gUnknown_203B48C->unk0, 32);
    for (i = 0; i < 32; i++) {
        ReadBits(&backup, &gUnknown_203B48C->unk4[i], 32);
    }

    FinishBitSerializer(&backup);
    return backup.count;
}

u32 sub_8095624(u8 *buffer, u32 b)
{
    DataSerializer backup;
    Pokemon *mon;
    s32 i;

    InitBitWriter(&backup, buffer, b);

    for (i = 0; i < 32; i++) {
        sub_8095824(&backup, &gUnknown_203B480[i]);
    }

    WriteBits(&backup, &gUnknown_203B484->unk0, 32);

    mon = &gUnknown_203B484->unk4;

    WriteBits(&backup, &mon->flags, 2);
    WriteBits(&backup, &mon->isTeamLeader, 1);
    WriteBits(&backup, &mon->level, 7);
    WriteDungeonLocationBits(&backup, &mon->dungeonLocation);
    WriteBits(&backup, &mon->speciesNum, 9);
    WritePoke1LevelBits(&backup, &mon->unkC[0]);
    WritePoke1LevelBits(&backup, &mon->unkC[1]);
    WriteBits(&backup, &mon->IQ, 10);
    WriteBits(&backup, &mon->pokeHP, 10);
    WriteBits(&backup, &mon->offense.att[0], 8);
    WriteBits(&backup, &mon->offense.att[1], 8);
    WriteBits(&backup, &mon->offense.def[0], 8);
    WriteBits(&backup, &mon->offense.def[1], 8);
    WriteBits(&backup, &mon->currExp, 24);
    WriteBits(&backup, &mon->IQSkills, 24);
    WriteBits(&backup, &mon->tacticIndex, 4);
    WriteHeldItemBits(&backup, &mon->heldItem);
    WritePoke1MovesBits(&backup, mon->moves);
    WriteBits(&backup, mon->name, 10 * 8);

    WriteBits(&backup, &gUnknown_203B48C->unk0, 32);

    for (i = 0; i < 32; i++) {
        WriteBits(&backup, &gUnknown_203B48C->unk4[i], 32);
    }

    FinishBitSerializer(&backup);
    return backup.count;
}

void sub_8095774(DataSerializer * a, unkStruct_203B480 *b)
{
    u8 temp;

    ReadBits(a, &b->mailType, 4);
    ReadDungeonLocationBits(a, &b->dungeonSeed.location);
    ReadBits(a, &b->dungeonSeed.seed, 24);
    ReadBits(a, &b->clientSpecies, 9);
    ReadBits(a, &b->unk10.unk10, 32);
    ReadBits(a, &b->playerName, 10 * 8);
    ReadBits(a, &b->item.flags, 8);
    ReadBits(a, &b->item.quantity, 8);
    ReadBits(a, &b->item.id, 8);
    ReadBits(a, &b->unk24, 32);
    ReadBits(a, &b->unk28, 32);
    ReadBits(a, &b->rescuesAllowed, 8);

    ReadBits(a, &temp, 1);
    b->unk2D = temp & 1;
}

void sub_8095824(DataSerializer * a, unkStruct_203B480 *b)
{
    u8 neg1;
    u8 zero;
    u8 *ptr;

    neg1 = -1;
    zero = 0;

    WriteBits(a, &b->mailType, 4);
    WriteDungeonLocationBits(a, &b->dungeonSeed.location);
    WriteBits(a, &b->dungeonSeed.seed, 24);
    WriteBits(a, &b->clientSpecies, 9);
    WriteBits(a, &b->unk10.unk10, 32);
    WriteBits(a, &b->playerName, 10 * 8);
    WriteBits(a, &b->item.flags, 8);
    WriteBits(a, &b->item.quantity, 8);
    WriteBits(a, &b->item.id, 8);
    WriteBits(a, &b->unk24, 32);
    WriteBits(a, &b->unk28, 32);
    WriteBits(a, &b->rescuesAllowed, 8);

    if (b->unk2D != 0)
        ptr = &neg1;
    else
        ptr = &zero;
    WriteBits(a, ptr, 1);
}

void sub_80958E4(u32 *a, u32 b)
{
    *a = b;
}
