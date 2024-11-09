#include "global.h"
#include "constants/type.h"
#include "structs/str_pokemon.h"
#include "code_8069D4C.h"
#include "code_80118A4.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_8097670.h"
#include "dungeon.h"
#include "dungeon_items.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "friend_area.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "pokemon_mid.h"
#include "position_util.h"
#include "text_util.h"
#include "dungeon_util_1.h"
#include "type_chart.h"

extern u8 gFormatBuffer_FriendArea[];
extern u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE];
extern s16 gUnknown_80F5008;
extern s16 gUnknown_80F5700[];
extern s32 gUnknown_8106F7C[];

extern u8 *gUnknown_80FA0F0[];
extern u8 *gUnknown_80FA058[];
extern u8 *gUnknown_80FA030[];
extern u8 *gUnknown_80F9FE8[];
extern u8 *gUnknown_80FA004[];
extern u8 *gUnknown_80FA0C8[];
extern u8 *gUnknown_80FA120[];
extern u8 *gUnknown_80FA090[];

void sub_8068FE0(Entity *, u32, Entity *);
u8 sub_806B8CC();
bool8 sub_805FBE8(u8 *a0);
void sub_8083D88();
u8 sub_808529C(s32);
extern u8 GetBodySize(s16 index);
void nullsub_96(Entity *pokemon,Entity *target);
u8 sub_8097900(s16);
void sub_806F910(void);
u8 sub_806F9BC(s16);
extern void sub_803F508(Entity *);

void SetShopkeeperAggression(Entity *pokemon, Entity *target)
{
    EntityInfo *info;

    info = GetEntInfo(target);

    if(info->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        if(GetEntityType(pokemon) == ENTITY_MONSTER)
        {
            if(GetEntInfo(pokemon)->isNotTeamMember)
            {
                info->shopkeeper = SHOPKEEPER_MODE_ATTACK_ENEMIES;
            }
            else
            {
                info->shopkeeper = SHOPKEEPER_MODE_ATTACK_TEAM;
            }
        }
    }
}

void sub_806F480(Entity *pokemon, u8 r1)
{
    EntityInfo *info;

    info = GetEntInfo(pokemon);

    if(info->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        if(r1)
        {
            info->shopkeeper = SHOPKEEPER_MODE_ATTACK_ENEMIES;
        }
        else
        {
            info->shopkeeper = SHOPKEEPER_MODE_ATTACK_TEAM;
        }
    }
}

u8 sub_806F4A4(Entity *pokemon, u8 type) {

    EntityInfo *info = GetEntInfo(pokemon);
    s32 index;

    if(MonsterIsType(pokemon, TYPE_GHOST))
    {
        if(type == TYPE_NORMAL || type == TYPE_FIGHTING)
            if(!info->exposed)
                return FALSE;
    }
    for(index = 0; index < 2; index++)
    {
        if(gTypeEffectivenessChart[type][info->types[index]] == EFFECTIVENESS_IMMUNE)
            return FALSE;
    }
    return TRUE;
}

void sub_806F500(void)
{
    struct unkStruct_Dungeon134_sub *temp;

    temp = &gDungeon->unk134;

    temp->unk134 = 0;
    temp->unk138 = 0;
    temp->unk13C[0] = 0;
    temp->unk13C[1] = 0;
    temp->unk13E[0] = 0xA;
    temp->unk13E[1] = 0xA;
    temp->unk140[0] = 1;
    temp->unk140[1] = 1;
    temp->unk140[2] = 0;
    temp->unk140[4] = 0;
    temp->unk140[3] = 0;
    temp->unk140[5] = 0;
    temp->unk140[6] = 0;
    temp->unk150 = 0;
    temp->unk158 = 0;
    temp->unk15C = 0;
    temp->unk160 = 0;
    temp->unk161 = 0;
    temp->unk162 = 0;
    temp->unk163 = 0;
    temp->unk164 = 0;
    temp->unk165 = 0;
    temp->unk166 = 0;
    temp->unk167 = 0;
    temp->unk168 = 0;
    temp->unk169 = 0;
    temp->unk16A = 0;
    temp->unk16C = 0;
    temp->unk16B = 0;
    temp->unk16D = 0;
    temp->fill16E[0] = 0;
    temp->fill16E[1] = 0;
    temp->fill16E[2] = 0;
    temp->fill16E[3] = 0;
    temp->fill16E[4] = 0;
    temp->fill16E[5] = 0;
    temp->fill16E[6] = 0;
    temp->fill16E[7] = 0;
    temp->fill16E[8] = 0;
    temp->fill16E[9] = 0;
    temp->fill16E[10] = 0;
    temp->pokemonExposed = FALSE;
    temp->unk17A = 0;
}

s32 sub_806F62C(int param_1)
{
    return gUnknown_8106F7C[param_1];
}

void sub_806F63C(Entity *param_1)
{
    UnkDungeonGlobal_unk181E8_sub *temp;

    temp = &gDungeon->unk181e8;

    if (temp->cameraTarget == param_1) {
        sub_803F508(temp->cameraTarget);
    }
}

// https://decomp.me/scratch/2la6b - (96.72% matching - Seth)
#ifdef NONMATCHING
bool8 sub_806F660(Entity *pokemon,Entity *target)
{
  EntityInfo *pokemonInfo;
  EntityInfo *targetInfo;
  s32 size;
  int iVar4;
  s32 iVar5;
  s32 uVar6;

  int recruitRate;
  s32 iVar8;
  s32 index;
  pokemonInfo = pokemon->info;
  targetInfo = target->info;
  iVar8 = -1;
  size = GetBodySize(targetInfo->apparentID);
  if ((1 < ((u16)(gDungeon->bossBattleIndex - 4))) && (gDungeon->bossBattleIndex != 9) && (gDungeon->bossBattleIndex != 0xf)) {
    if ((u16)(gDungeon->bossBattleIndex - 0x2cU) < 5) {
      if (gDungeon->unk65C == 0) {
          return FALSE;
      }
    }
    else if (gDungeon->bossBattleIndex == 0x31) {
      if (gDungeon->fill655[4] == 0) {
        return FALSE;
      }
      if (sub_8097900(0x19e) == 0) {
          return FALSE;
      }

    }
    else {
      if (IsRecruitingEnabled((gDungeon->dungeonLocation).id) == 0) {
          return FALSE;
      }
    }
  }
  if (gDungeon->unk65D == 0)
  {
    if (((
    (2 < (u16)(targetInfo->id - 0x90)) &&
    (targetInfo->id != MONSTER_RAIKOU) &&
    (targetInfo->id != MONSTER_ENTEI) &&
    (targetInfo->id != MONSTER_SUICUNE) &&
    (targetInfo->id != MONSTER_LATIAS) &&
    (targetInfo->id != MONSTER_LATIOS) &&
    (targetInfo->id != MONSTER_JIRACHI) &&
    (targetInfo->id != MONSTER_RAYQUAZA) &&
    (targetInfo->id != MONSTER_DEOXYS_NORMAL) &&
    (targetInfo->id != 0MONSTER_REGIROCK &&
    (targetInfo->id != MONSTER_REGICE) &&
    (targetInfo->id != MONSTER_REGISTEEL)) || (HasRecruitedMon(targetInfo->id) == 0)) &&
     (sub_806F9BC(targetInfo->id) != 0)) {
    iVar5 = (pokemon->pos).x - (target->pos).x;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    if (iVar5 < 2) {
      iVar5 = (pokemon->pos).y - (target->pos).y;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      if (((iVar5 < 2) && (targetInfo->joinedAt.joinedAt != 0x4A)) &&
         (targetInfo->clientType != 1 && (CanSeeTarget(target,pokemon))
          )) {
        sub_806F910();
        iVar4 = DungeonRandInt(1000);
        recruitRate = GetRecruitRate(targetInfo->id);
        if (recruitRate != -999) {
          if (HasHeldItem(pokemon, ITEM_FRIEND_BOW)) { // FRIEND_BOW
            recruitRate += gUnknown_80F5008;
          }
          recruitRate += gUnknown_80F5700[pokemonInfo->level];
          if (iVar4 < recruitRate) {
            for (index = 0; index <= (6 - size); index++)
            {
              for(uVar6 = 0; uVar6 < size; uVar6++)
              {
                  if (gUnknown_202EE70[index + uVar6] != 0) break;
              }
              iVar8 = index;
              if (uVar6 == size)
                  break;
            }
            if (iVar8 != -1) {
              for(index = 0; index < 4; index++)
              {
                    if (((u8)(index[gRecruitedPokemonRef->pokemon2].unk0) & 1) == 0) break;
              }
              if (index != 4) {

                for(index = 0; index < 4; index++)
                {
                    if (EntityExists(gDungeon->teamPokemon[index]) == 0) break;
                }
                if (index != 4) {
                  return TRUE;
                }
              }
            }
            nullsub_96(pokemon,target);
          }
        }
      }
    }
    }
  }
  return FALSE;
}
#else
NAKED
bool8 sub_806F660(Entity *pokemon,Entity *target)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r10\n"
	"\tmov r6, r9\n"
	"\tmov r5, r8\n"
	"\tpush {r5-r7}\n"
	"\tadds r6, r0, 0\n"
	"\tmov r8, r1\n"
	"\tldr r0, [r6, 0x70]\n"
	"\tmov r10, r0\n"
	"\tldr r4, [r1, 0x70]\n"
	"\tmovs r1, 0x1\n"
	"\tnegs r1, r1\n"
	"\tmov r9, r1\n"
	"\tmovs r2, 0x4\n"
	"\tldrsh r0, [r4, r2]\n"
	"\tbl GetBodySize\n"
	"\tlsls r0, 24\n"
	"\tlsrs r5, r0, 24\n"
	"\tldr r0, _0806F6C0\n"
	"\tldr r3, [r0]\n"
	"\tldr r1, _0806F6C4\n"
	"\tadds r0, r3, r1\n"
	"\tldrh r2, [r0]\n"
	"\tsubs r0, r2, 0x4\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x1\n"
	"\tbls _0806F702\n"
	"\tlsls r0, r2, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tcmp r1, 0x9\n"
	"\tbeq _0806F702\n"
	"\tcmp r1, 0xF\n"
	"\tbeq _0806F702\n"
	"\tadds r0, r2, 0\n"
	"\tsubs r0, 0x2C\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x4\n"
	"\tbhi _0806F6CC\n"
	"\tldr r2, _0806F6C8\n"
	"\tadds r0, r3, r2\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F702\n"
	"\tb _0806F8FC\n"
	"\t.align 2, 0\n"
"_0806F6C0: .4byte gDungeon\n"
"_0806F6C4: .4byte 0x00003a14\n"
"_0806F6C8: .4byte 0x0000065c\n"
"_0806F6CC:\n"
	"\tcmp r1, 0x31\n"
	"\tbne _0806F6F0\n"
	"\tldr r1, _0806F6EC\n"
	"\tadds r0, r3, r1\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F6DC\n"
	"\tb _0806F8FC\n"
"_0806F6DC:\n"
	"\tmovs r0, 0xCF\n"
	"\tlsls r0, 1\n"
	"\tbl sub_8097900\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F702\n"
	"\tb _0806F8FC\n"
	"\t.align 2, 0\n"
"_0806F6EC: .4byte 0x00000659\n"
"_0806F6F0:\n"
	"\tldr r2, _0806F834\n"
	"\tadds r0, r3, r2\n"
	"\tldrb r0, [r0]\n"
	"\tbl IsRecruitingEnabled\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F702\n"
	"\tb _0806F8FC\n"
"_0806F702:\n"
	"\tldr r0, _0806F838\n"
	"\tldr r0, [r0]\n"
	"\tldr r3, _0806F83C\n"
	"\tadds r0, r3\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806F712\n"
	"\tb _0806F8FC\n"
"_0806F712:\n"
	"\tldrh r1, [r4, 0x2]\n"
	"\tadds r0, r1, 0\n"
	"\tsubs r0, 0x90\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x2\n"
	"\tbls _0806F766\n"
	"\tlsls r0, r1, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tldr r0, _0806F840\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tsubs r0, 0x1\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tadds r0, 0x2\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tadds r0, 0x8A\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tadds r0, 0x1\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tadds r0, 0x4\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tsubs r0, 0x1\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tadds r0, 0x2\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tsubs r0, 0x9\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tadds r0, 0x1\n"
	"\tcmp r1, r0\n"
	"\tbeq _0806F766\n"
	"\tadds r0, 0x1\n"
	"\tcmp r1, r0\n"
	"\tbne _0806F776\n"
"_0806F766:\n"
	"\tmovs r1, 0x2\n"
	"\tldrsh r0, [r4, r1]\n"
	"\tbl HasRecruitedMon\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806F776\n"
	"\tb _0806F8FC\n"
"_0806F776:\n"
	"\tmovs r2, 0x2\n"
	"\tldrsh r0, [r4, r2]\n"
	"\tbl sub_806F9BC\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F786\n"
	"\tb _0806F8FC\n"
"_0806F786:\n"
	"\tmovs r3, 0x4\n"
	"\tldrsh r1, [r6, r3]\n"
	"\tmov r2, r8\n"
	"\tmovs r3, 0x4\n"
	"\tldrsh r0, [r2, r3]\n"
	"\tsubs r1, r0\n"
	"\tcmp r1, 0\n"
	"\tbge _0806F798\n"
	"\tnegs r1, r1\n"
"_0806F798:\n"
	"\tcmp r1, 0x1\n"
	"\tble _0806F79E\n"
	"\tb _0806F8FC\n"
"_0806F79E:\n"
	"\tmovs r0, 0x6\n"
	"\tldrsh r1, [r6, r0]\n"
	"\tmov r2, r8\n"
	"\tmovs r3, 0x6\n"
	"\tldrsh r0, [r2, r3]\n"
	"\tsubs r1, r0\n"
	"\tcmp r1, 0\n"
	"\tbge _0806F7B0\n"
	"\tnegs r1, r1\n"
"_0806F7B0:\n"
	"\tcmp r1, 0x1\n"
	"\tble _0806F7B6\n"
	"\tb _0806F8FC\n"
"_0806F7B6:\n"
	"\tadds r0, r4, 0\n"
	"\tadds r0, 0x40\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0x4A\n"
	"\tbne _0806F7C2\n"
	"\tb _0806F8FC\n"
"_0806F7C2:\n"
	"\tadds r0, r4, 0\n"
	"\tadds r0, 0xA4\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0x1\n"
	"\tbne _0806F7CE\n"
	"\tb _0806F8FC\n"
"_0806F7CE:\n"
	"\tmov r0, r8\n"
	"\tadds r1, r6, 0\n"
	"\tbl CanSeeTarget\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F7DE\n"
	"\tb _0806F8FC\n"
"_0806F7DE:\n"
	"\tbl sub_806F910\n"
	"\tmovs r0, 0xFA\n"
	"\tlsls r0, 2\n"
	"\tbl DungeonRandInt\n"
	"\tadds r7, r0, 0\n"
	"\tmovs r1, 0x2\n"
	"\tldrsh r0, [r4, r1]\n"
	"\tbl GetRecruitRate\n"
	"\tlsls r0, 16\n"
	"\tasrs r4, r0, 16\n"
	"\tldr r0, _0806F844\n"
	"\tcmp r4, r0\n"
	"\tbne _0806F800\n"
	"\tb _0806F8FC\n"
"_0806F800:\n"
	"\tadds r0, r6, 0\n"
	"\tmovs r1, 0x2E\n"
	"\tbl HasHeldItem\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806F816\n"
	"\tldr r0, _0806F848\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r0, r2]\n"
	"\tadds r4, r0\n"
"_0806F816:\n"
	"\tldr r0, _0806F84C\n"
	"\tmov r3, r10\n"
	"\tldrb r1, [r3, 0x9]\n"
	"\tlsls r1, 1\n"
	"\tadds r1, r0\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r1, r2]\n"
	"\tadds r4, r0\n"
	"\tcmp r7, r4\n"
	"\tbge _0806F8FC\n"
	"\tmovs r4, 0\n"
	"\tmovs r0, 0x6\n"
	"\tsubs r3, r0, r5\n"
	"\tldr r7, _0806F850\n"
	"\tb _0806F856\n"
	"\t.align 2, 0\n"
"_0806F834: .4byte 0x00000644\n"
"_0806F838: .4byte gDungeon\n"
"_0806F83C: .4byte 0x0000065d\n"
"_0806F840: .4byte 0x0000010d\n"
"_0806F844: .4byte 0xfffffc19\n"
"_0806F848: .4byte gUnknown_80F5008\n"
"_0806F84C: .4byte gUnknown_80F5700\n"
"_0806F850: .4byte gUnknown_202EE70\n"
"_0806F854:\n"
	"\tadds r4, 0x1\n"
"_0806F856:\n"
	"\tcmp r4, r3\n"
	"\tbgt _0806F878\n"
	"\tmovs r2, 0\n"
	"\tcmp r2, r5\n"
	"\tbge _0806F872\n"
	"\tadds r1, r4, r7\n"
	"\tb _0806F86C\n"
"_0806F864:\n"
	"\tadds r1, 0x1\n"
	"\tadds r2, 0x1\n"
	"\tcmp r2, r5\n"
	"\tbge _0806F872\n"
"_0806F86C:\n"
	"\tldrb r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806F864\n"
"_0806F872:\n"
	"\tcmp r2, r5\n"
	"\tbne _0806F854\n"
	"\tmov r9, r4\n"
"_0806F878:\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r9, r0\n"
	"\tbeq _0806F8F4\n"
	"\tmovs r4, 0\n"
	"\tldr r3, _0806F8BC\n"
	"\tldr r0, [r3]\n"
	"\tldr r2, _0806F8C0\n"
	"\tadds r0, r2\n"
	"\tldrb r1, [r0]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _0806F8B4\n"
	"\tadds r7, r3, 0\n"
	"\tadds r5, r2, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
"_0806F89C:\n"
	"\tadds r2, 0x64\n"
	"\tadds r4, 0x1\n"
	"\tcmp r4, 0x3\n"
	"\tbgt _0806F8B4\n"
	"\tldr r0, [r7]\n"
	"\tadds r0, r2, r0\n"
	"\tadds r0, r5\n"
	"\tldrb r1, [r0]\n"
	"\tadds r0, r3, 0\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F89C\n"
"_0806F8B4:\n"
	"\tcmp r4, 0x4\n"
	"\tbeq _0806F8F4\n"
	"\tmovs r4, 0\n"
	"\tb _0806F8C6\n"
	"\t.align 2, 0\n"
"_0806F8BC: .4byte gRecruitedPokemonRef\n"
"_0806F8C0: .4byte 0x00008df8\n"
"_0806F8C4:\n"
	"\tadds r4, 0x1\n"
"_0806F8C6:\n"
	"\tcmp r4, 0x3\n"
	"\tbgt _0806F8E2\n"
	"\tldr r0, _0806F8EC\n"
	"\tldr r0, [r0]\n"
	"\tlsls r1, r4, 2\n"
	"\tldr r3, _0806F8F0\n"
	"\tadds r0, r3\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tbl EntityExists\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0806F8C4\n"
"_0806F8E2:\n"
	"\tcmp r4, 0x4\n"
	"\tbeq _0806F8F4\n"
	"\tmovs r0, 0x1\n"
	"\tb _0806F8FE\n"
	"\t.align 2, 0\n"
"_0806F8EC: .4byte gDungeon\n"
"_0806F8F0: .4byte 0x0001357c\n"
"_0806F8F4:\n"
	"\tadds r0, r6, 0\n"
	"\tmov r1, r8\n"
	"\tbl nullsub_96\n"
"_0806F8FC:\n"
	"\tmovs r0, 0\n"
"_0806F8FE:\n"
	"\tpop {r3-r5}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tmov r10, r5\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1");
}
#endif

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
            size = GetBodySize(GetEntInfo(entity)->apparentID);
            entity->axObj.unk40_maybeAnimTimer = sVar6;
            GetEntInfo(entity)->unk167 = index;
            GetEntInfo(entity)->unk168 = size;
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
    if (((gDungeon->unk658 == 0) || (sub_808529C(id) == 0)) ||
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
    CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[0],param_3->id);

    if (DisplayDungeonYesNoMessage(0,*gUnknown_80F9FE8,1) == 0) {
        if (param_3->id != MONSTER_JIRACHI) {
            TryDisplayDungeonLoggableMessage(entity1,*gUnknown_80FA004);
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
            TryDisplayDungeonLoggableMessage(entity1,*gUnknown_80FA030);
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
            SetDefaultIQSkills((u8 *)&(pokeStruct2->IQSkills),FALSE);
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
                pokeStruct2->offense.att[iVar2] = param_3->offense.att[iVar2];
                pokeStruct2->offense.def[iVar2] = param_3->offense.def[iVar2];
            }

            pokeStruct2->currExp = param_3->exp;
            pokeStruct2->moves = param_3->moves;

            pokeStruct2->itemSlot = param_3->heldItem;
            BoundedCopyStringtoBuffer(pokeStruct2->name,GetMonSpecies(param_3->id),10);

            IncrementAdventureNumJoined();

            if (sub_806B8CC(param_3->id,param_3->pos.x,param_3->pos.y,pokeStruct2,&local_2c,0,1) == 0) {
                TryDisplayDungeonLoggableMessage(entity1,*gUnknown_80FA058);
                pokeStruct2->unk0 = 0;
            }
            else {
                sub_8083D88();
                sub_803E708(0xa0,0x46);
                if (DisplayDungeonYesNoMessage(0,*gUnknown_80FA090,1) == 1) {
                    while (sub_805FBE8(pokeStruct2->name) == 0) {
                        DisplayDungeonMessage(0,*gUnknown_80FA0C8,1);
                    }
                }
                sub_808D9DC(gFormatBuffer_Monsters[0],pokeStruct2,0);
                TryDisplayDungeonLoggableMessage(entity1,*gUnknown_80FA0F0);
                if (flag) {
                    leader = xxx_call_GetLeader();
                    SetMessageArgument(gFormatBuffer_Monsters[0],leader,0);
                    sub_8092558(gFormatBuffer_FriendArea,friendArea);
                    PlaySound(0xce);
                    DisplayDungeonMessage(0,*gUnknown_80FA120,1);
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

  info = GetEntInfo(param_1);
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
      pokeStruct2->offense.att[index2] = local_74.offense.att[index2];
      pokeStruct2->offense.def[index2] = local_74.offense.def[index2];
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
    IncrementAdventureNumJoined();
    sub_8068FE0(entity2,500,entity1);
    if (sub_806B8CC(local_74.id,local_74.pos.x,local_74.pos.y,pokeStruct2,&local_2c,0,0) == 0) {
      pokeStruct2->unk0 = 0;
    }
    else {
      if (DisplayDungeonYesNoMessage(0,*gUnknown_80FA090,1) == 1) {
        while (!sub_805FBE8(buffer)) {
          DisplayDungeonMessage(0,*gUnknown_80FA0C8,1);
        }
      }
      if (flag) {
        leader = xxx_call_GetLeader();
        SetMessageArgument(gFormatBuffer_Monsters[0],leader,0);
        sub_8092558(gFormatBuffer_FriendArea,friendArea);
        PlaySound(0xce);
        DisplayDungeonMessage(0,*gUnknown_80FA120,1);
      }
      sub_808D9DC(gFormatBuffer_Monsters[3],pokeStruct2,0);
      *entityPtr = local_2c;
    }
   return TRUE;
  }
}
