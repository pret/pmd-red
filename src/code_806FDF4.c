#include "global.h"
#include "structs/str_pokemon.h"
#include "structs/struct_8069D4C.h"
#include "code_80118A4.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "code_80521D0.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_8097670.h"
#include "dungeon_util.h"
#include "friend_area.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "pokemon_mid.h"
#include "position_util.h"
#include "text_util.h"
#include "dungeon_util_1.h"

extern u8 gUnknown_202E628[];
extern u8 gUnknown_202E088[];
extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE];

extern u8 *gUnknown_80FA0F0[];
extern u8 *gUnknown_80FA058[];
extern u8 *gUnknown_80FA030[];
extern u8 *gUnknown_80F9FE8[];
extern u8 *gUnknown_80FA004[];
extern u8 *gUnknown_80FA0C8[];
extern u8 gUnknown_202E088[];
extern u8 *gUnknown_80FA120[];
extern u8 *gUnknown_80FA090[];

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target);
void sub_8068FE0(Entity *, u32, Entity *);
u8 sub_806B8CC();
bool8 sub_805FBE8(u8 *a0);
extern s32 sub_8052B8C(u32, const u8 *, u32);
extern void PrintFieldMessage(u32, const u8 *, u32);
void sub_8083D88();
u8 sub_808529C(s32);
extern u8 GetBodySize(s16 index);
void sub_806F910();

void nullsub_96(Entity *pokemon,Entity *target)
{}

void sub_806F910(void)
{
    u8 size;
    s32 counter;
    Entity *entity;
    int totalSize;
    int index;
    s32 sVar6;

    totalSize = 0;

    for(index = 0, sVar6 = 0x40; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if (EntityExists(entity)) {
            size = GetBodySize(entity->info->apparentID);
            entity->unk68 = sVar6;
            entity->info->unk167 = index;
            entity->info->unk168 = size;
            for (counter = 0; counter < size; counter++) {
                if (totalSize < MAX_TEAM_BODY_SIZE) {
                    gUnknown_202EE70[totalSize] = 1;
                    sVar6 += 0x10;
                    totalSize++;
                }
            }
            sub_806CCB4(entity,sub_806CEBC(entity));
        }
    }
    for (; totalSize < MAX_TEAM_BODY_SIZE; totalSize++) {
        gUnknown_202EE70[totalSize] = 0;
    }
}

bool8 sub_806F9BC(s16 species)
{
    u8 friendArea;
    s32 id;
    unkStruct_8092638 auStack_18;

    id = species;
    if (((gDungeon->fill655[3] == 0) || (sub_808529C(id) == 0)) ||
        ((id == MONSTER_MEW && (gDungeon->unk678 == 1)))) {
        return FALSE;
    }
    else if (id == MONSTER_LATIAS)
    {
        return FALSE;
    }
    else if (id == MONSTER_LATIOS)
    {
        return FALSE;
    }
    else if (id == MONSTER_DEOXYS_ATTACK)
    {
        return FALSE;
    }
    else if (id == MONSTER_DEOXYS_DEFENSE)
    {
        return FALSE;
    }
    else if (id == MONSTER_DEOXYS_SPEED)
    {
        return FALSE;
    }
    else {
        if (GetUnk12(id) == 0) {
            friendArea = GetFriendArea(id);
            sub_8092638(friendArea, &auStack_18, FALSE, FALSE);
            if (auStack_18.hasFriendArea == FALSE)
                return FALSE;
        }
        return TRUE;
    }
}

bool8 sub_806FA5C(Entity *entity1, Entity *entity2, struct unkStruct_8069D4C *param_3)
{
    u8 friendArea;
    bool8 flag;
    Entity *leader;
    PokemonStruct2 *pokeStruct2;
    int pokeIndex;
    Entity *local_2c;
    s32 iVar2;
    u32 direction;


    direction = GetDirectionTowardsPosition(&entity2->pos,&entity1->pos);
    flag = FALSE;
    friendArea = GetFriendArea(param_3->id);
    entity2->unk22 = 0;
    sub_807A0CC(entity1, entity2);
    sub_806CE68(entity2, direction);
    CopyCyanMonsterNametoBuffer(gAvailablePokemonNames,param_3->id);

    if (sub_8052B8C(0,*gUnknown_80F9FE8,1) == 0) {
        if (param_3->id != MONSTER_JIRACHI) {
            SendMessage(entity1,*gUnknown_80FA004);  
        }
        return 0;
    }
    else
    {
        for(pokeIndex = 0; pokeIndex < MAX_TEAM_MEMBERS; pokeIndex++)
        {
            if (((u8)(pokeIndex[gRecruitedPokemonRef->pokemon2].unk0) & 1) == 0) 
                break;
        }

        if (pokeIndex == MAX_TEAM_MEMBERS) {
            SendMessage(entity1,*gUnknown_80FA030);
            return FALSE;
        }
        else {
            if (GetFriendAreaStatus(friendArea) == 0) {
                UnlockFriendArea(friendArea);
                flag = TRUE;
            }
            sub_8068FE0(entity2,500,entity1);
            pokeStruct2 = &gRecruitedPokemonRef->pokemon2[pokeIndex];
            pokeStruct2->unk0 = 3;
            pokeStruct2->isTeamLeader = FALSE;
            pokeStruct2->level = param_3->level;
            pokeStruct2->IQ = 1;
            SetDefaultIQSkills((u8 *)&(pokeStruct2->IQSkills),0);
            pokeStruct2->hiddenPower = param_3->hiddenPower;
            pokeStruct2->tacticIndex = 0;
            pokeStruct2->unkA = -1;
            pokeStruct2->unkC = pokeIndex;
            pokeStruct2->speciesNum = param_3->id;
            (pokeStruct2->dungeonLocation) = gDungeon->dungeonLocation;
            pokeStruct2->unk10 = param_3->HP;
            pokeStruct2->unk12 = param_3->HP;
            pokeStruct2->belly = param_3->belly;
            pokeStruct2->maxBelly = param_3->maxBelly;

            for(iVar2 = 0; iVar2 < 2; iVar2++)
            {
                pokeStruct2->offense.att[iVar2] = param_3->att[iVar2];
                pokeStruct2->offense.def[iVar2] = param_3->def[iVar2];
            }

            pokeStruct2->currExp = param_3->exp;
            pokeStruct2->moves = param_3->moves;

            pokeStruct2->itemSlot = param_3->heldItem;
            BoundedCopyStringtoBuffer(pokeStruct2->name,GetMonSpecies(param_3->id),10);

            sub_8097848();

            if (sub_806B8CC(param_3->id,param_3->pos.x,param_3->pos.y,pokeStruct2,&local_2c,0,1) == 0) {
                SendMessage(entity1,*gUnknown_80FA058);
                pokeStruct2->unk0 = 0;
            }
            else {
                sub_8083D88();
                sub_803E708(0xa0,0x46);
                if (sub_8052B8C(0,*gUnknown_80FA090,1) == 1) {
                    while (sub_805FBE8(pokeStruct2->name) == 0) {
                        PrintFieldMessage(0,*gUnknown_80FA0C8,1);
                    }
                }
                sub_808D9DC(gAvailablePokemonNames,pokeStruct2,0);
                SendMessage(entity1,*gUnknown_80FA0F0);
                if (flag != '\0') {
                    leader = xxx_call_GetLeader();
                    SetMessageArgument(gAvailablePokemonNames,leader,0);
                    sub_8092558(gUnknown_202E628,friendArea);
                    PlaySound(0xce);
                    PrintFieldMessage(0,*gUnknown_80FA120,1);
                }
                if (param_3->id == MONSTER_MEW) {
                    gDungeon->unk4 = 1;
                    gDungeon->unk11 = 3;
                }
            }
            return TRUE;
        }     
    }
}

// https://decomp.me/scratch/LByEy (93.86% matching - Seth) 

#ifdef NONMATCHING
bool8 sub_806FD18(Entity *param_1)
{
  s32 size;
  s32 uVar3;
  int iVar4;
  EntityInfo *info;
  int index;
  
  info = param_1->info;
  iVar4 = -1;
  size = GetBodySize((int)info->apparentID);
  if (sub_806F9BC((int)info->id) != 0) {
    sub_806F910();
    for (index = 0; index <= (6 - size); index++) {
      for(uVar3 = 0; uVar3 < size; uVar3++)
      {
          if (gUnknown_202EE70[index] != 0) break;
            iVar4 = index;
      }
      if (uVar3 == size) break;
    }
    if (iVar4 != -1) {

        for(index = 0; index < 4; index++)
        {
            if (((u8)(index[gRecruitedPokemonRef->pokemon2].unk0) & 1) == 0) break;
        }
            
      if (index != 4) {
        for(index = 0; index < 4; index++)
        {
            if(!EntityExists(gDungeon->teamPokemon[index])) break;
        }
        if (index != 4) {
          return 1;
        }
      }
    }
  }
  return 0;
}
#else
NAKED
bool8 sub_806FD18(Entity *param_1)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tldr r4, [r0, 0x70]\n"
	"\tmovs r6, 0x1\n"
	"\tnegs r6, r6\n"
	"\tmovs r1, 0x4\n"
	"\tldrsh r0, [r4, r1]\n"
	"\tbl GetBodySize\n"
	"\tlsls r0, 24\n"
	"\tlsrs r5, r0, 24\n"
	"\tmovs r2, 0x2\n"
	"\tldrsh r0, [r4, r2]\n"
	"\tbl sub_806F9BC\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806FDEC\n"
	"\tbl sub_806F910\n"
	"\tmovs r4, 0\n"
	"\tmovs r0, 0x6\n"
	"\tsubs r3, r0, r5\n"
	"\tldr r7, _0806FD48\n"
	"\tb _0806FD4E\n"
	"\t.align 2, 0\n"
"_0806FD48: .4byte gUnknown_202EE70\n"
"_0806FD4C:\n"
	"\tadds r4, 0x1\n"
"_0806FD4E:\n"
	"\tcmp r4, r3\n"
	"\tbgt _0806FD70\n"
	"\tmovs r2, 0\n"
	"\tcmp r2, r5\n"
	"\tbge _0806FD6A\n"
	"\tadds r1, r4, r7\n"
	"\tb _0806FD64\n"
"_0806FD5C:\n"
	"\tadds r1, 0x1\n"
	"\tadds r2, 0x1\n"
	"\tcmp r2, r5\n"
	"\tbge _0806FD6A\n"
"_0806FD64:\n"
	"\tldrb r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806FD5C\n"
"_0806FD6A:\n"
	"\tcmp r2, r5\n"
	"\tbne _0806FD4C\n"
	"\tadds r6, r4, 0\n"
"_0806FD70:\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r6, r0\n"
	"\tbeq _0806FDEC\n"
	"\tmovs r4, 0\n"
	"\tldr r3, _0806FDB4\n"
	"\tldr r0, [r3]\n"
	"\tldr r2, _0806FDB8\n"
	"\tadds r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806FDAC\n"
	"\tadds r6, r3, 0\n"
	"\tadds r5, r2, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
"_0806FD94:\n"
	"\tadds r2, 0x64\n"
	"\tadds r4, 0x1\n"
	"\tcmp r4, 0x3\n"
	"\tbgt _0806FDAC\n"
	"\tldr r0, [r6]\n"
	"\tadds r0, r2, r0\n"
	"\tadds r0, r5\n"
	"\tldrb r1, [r0]\n"
	"\tadds r0, r3, 0\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbne _0806FD94\n"
"_0806FDAC:\n"
	"\tcmp r4, 0x4\n"
	"\tbeq _0806FDEC\n"
	"\tmovs r4, 0\n"
	"\tb _0806FDBE\n"
	"\t.align 2, 0\n"
"_0806FDB4: .4byte gRecruitedPokemonRef\n"
"_0806FDB8: .4byte 0x00008df8\n"
"_0806FDBC:\n"
	"\tadds r4, 0x1\n"
"_0806FDBE:\n"
	"\tcmp r4, 0x3\n"
	"\tbgt _0806FDDA\n"
	"\tldr r0, _0806FDE4\n"
	"\tldr r0, [r0]\n"
	"\tlsls r1, r4, 2\n"
	"\tldr r2, _0806FDE8\n"
	"\tadds r0, r2\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tbl EntityExists\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0806FDBC\n"
"_0806FDDA:\n"
	"\tcmp r4, 0x4\n"
	"\tbeq _0806FDEC\n"
	"\tmovs r0, 0x1\n"
	"\tb _0806FDEE\n"
	"\t.align 2, 0\n"
"_0806FDE4: .4byte gDungeon\n"
"_0806FDE8: .4byte 0x0001357c\n"
"_0806FDEC:\n"
	"\tmovs r0, 0\n"
"_0806FDEE:\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1"
    );
}

#endif


bool8 sub_806FDF4(Entity *entity1,Entity *entity2,Entity **entityPtr)
{
  u8 friendArea;
  bool8 flag;
  Entity *leader;
  PokemonStruct2 *pokeStruct2;
  int index;
  struct unkStruct_8069D4C local_74;
  Entity *local_2c;
  u8 *buffer;
  s32 index2;

   flag = 0;
  *entityPtr = NULL;

  sub_8069D4C(&local_74,entity2);

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    if (((u8)(index[gRecruitedPokemonRef->pokemon2].unk0) & 1) == 0) break;
  }
    
  if (index == MAX_TEAM_MEMBERS) {
    return FALSE;
  }
  else {
    friendArea = GetFriendArea(local_74.id);
    pokeStruct2 = &gRecruitedPokemonRef->pokemon2[index];
    pokeStruct2->unk0 = 3;
    pokeStruct2->isTeamLeader = FALSE;
    pokeStruct2->level = local_74.level;
    pokeStruct2->IQ = 1;
    SetDefaultIQSkills((u8 *)&(pokeStruct2->IQSkills),FALSE);
    pokeStruct2->hiddenPower = local_74.hiddenPower;
    pokeStruct2->tacticIndex = 0;
    pokeStruct2->unkA = -1;
    pokeStruct2->unkC = index;
    pokeStruct2->speciesNum = local_74.id;
    pokeStruct2->dungeonLocation = gDungeon->dungeonLocation;
    pokeStruct2->unk10 = local_74.HP;
    pokeStruct2->unk12 = local_74.HP;
    pokeStruct2->belly = local_74.belly;
    pokeStruct2->maxBelly = local_74.maxBelly;

    for(index2 = 0; index2 < 2; index2++)
    {
      pokeStruct2->offense.att[index2] = local_74.att[index2];
      pokeStruct2->offense.def[index2] = local_74.def[index2];
    }
      
    pokeStruct2->currExp = local_74.exp;
    pokeStruct2->moves = local_74.moves;
      
    pokeStruct2->itemSlot = local_74.heldItem;
    buffer = pokeStruct2->name;
    BoundedCopyStringtoBuffer(buffer,GetMonSpecies(local_74.id), POKEMON_NAME_LENGTH);
    if (GetFriendAreaStatus(friendArea) == 0) {
      UnlockFriendArea(friendArea);
      flag = TRUE;
    }
    sub_8097848();
    sub_8068FE0(entity2,500,entity1);
    if (sub_806B8CC(local_74.id,local_74.pos.x,local_74.pos.y,pokeStruct2,&local_2c,0,0) == 0) {
      pokeStruct2->unk0 = 0;
    }
    else {
      if (sub_8052B8C(0,*gUnknown_80FA090,1) == 1) {
        while (!sub_805FBE8(buffer)) {
          PrintFieldMessage(0,*gUnknown_80FA0C8,1);
        }
      }
      if (flag) {
        leader = xxx_call_GetLeader();
        SetMessageArgument(gAvailablePokemonNames,leader,0);
        sub_8092558(gUnknown_202E628,friendArea);
        PlaySound(0xce);
        PrintFieldMessage(0,*gUnknown_80FA120,1);
      }
      sub_808D9DC(gUnknown_202E088,pokeStruct2,0);
      *entityPtr = local_2c;
    }
   return TRUE;
  }
}
