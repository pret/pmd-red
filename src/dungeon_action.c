#include "global.h"
#include "dungeon_action.h"

#include "constants/dungeon_action.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "dungeon_pokemon_attributes.h"
#include "pokemon.h"
#include "item.h"

extern u8 *gUnknown_80F91EC[];
extern u8 *gUnknown_80F7C50[];
extern u8 gUnknown_80F697C[];
extern s16 gSpeedTurns[2][0x19];

struct ItemText
{
    u8 *desc;
    u8 *useText;
};
extern const struct ItemText gActions[];

extern void sub_8071B48(void);
extern void sub_8043ED0(u32);
extern u8 sub_8043D10(void);
extern bool8 sub_8044B28(void);
extern void sub_8086AC0(void);
extern void sub_8043ED0(u32);
extern void sub_807EAA0(u32, u32);
extern void UseAttack(u32);

#ifdef NONMATCHING
void CheckElectricAbilities(void)
{
  struct DungeonEntityData * entityData;
  struct DungeonEntityData * entityData2;
  struct DungeonEntity *entity;
  u32 isNotEnemy;
  s32 index;
  
  if (gSpeedTurns[1][gDungeonGlobalData->speedTurnCounter] != 0) {
    sub_8071B48();
    gDungeonGlobalData->hasPlus[0] = FALSE;
    gDungeonGlobalData->hasPlus[1] = FALSE;
    gDungeonGlobalData->hasMinus[0] = FALSE;
    gDungeonGlobalData->hasMinus[1] = FALSE;
    gDungeonGlobalData->lightningRodPokemon = NULL;
    gDungeonGlobalData->unk17B38 = 2;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeonGlobalData->allPokemon[index];
        if (EntityExists(entity)) {
            entityData = entity->entityData;
            entityData2 = entityData;
            entityData->attacking = FALSE;

            // should be  isNotEnemy = (entityData->isEnemy != '\0');
            // gets a neg/orr/lsr instead of cmp/beq
            isNotEnemy = (entityData->isEnemy == 0);

            if (HasAbility(entity, 0x32)) { // ABILITY_LIGHTNINGROD
                gDungeonGlobalData->lightningRodPokemon = entity;
                gDungeonGlobalData->unk17B38 = entityData2->unk98;
            }
            if (HasAbility(entity, 0x3f)) { // ABILITY_MINUS
                gDungeonGlobalData->hasMinus[isNotEnemy] = TRUE;
            }  
            if (HasAbility(entity, 0x38)) { // ABILITY_PLUS
                gDungeonGlobalData->hasPlus[isNotEnemy] = TRUE;
            }
        }
    }
    sub_8043ED0(0);
  }
}
#else
NAKED
void CheckElectricAbilities(void)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tldr r1, _08044A94\n"
	"\tldr r4, _08044A98\n"
	"\tldr r0, [r4]\n"
	"\tmovs r2, 0xCC\n"
	"\tlsls r2, 3\n"
	"\tadds r0, r2\n"
	"\tmovs r3, 0\n"
	"\tldrsh r0, [r0, r3]\n"
	"\tlsls r0, 1\n"
	"\tadds r1, 0x32\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tcmp r0, 0\n"
	"\tbeq _08044A8A\n"
	"\tbl sub_8071B48\n"
	"\tldr r0, [r4]\n"
	"\tldr r2, _08044A9C\n"
	"\tadds r0, r2\n"
	"\tmovs r2, 0\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r3, _08044AA0\n"
	"\tadds r0, r3\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, _08044AA4\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r3, 0x2\n"
	"\tadds r0, r3\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r3, _08044AA8\n"
	"\tadds r1, r0, r3\n"
	"\tstr r2, [r1]\n"
	"\tldr r1, _08044AAC\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0x2\n"
	"\tstr r1, [r0]\n"
	"\tmov r8, r2\n"
	"\tadds r7, r4, 0\n"
"_080449F2:\n"
	"\tldr r0, [r7]\n"
	"\tmov r2, r8\n"
	"\tlsls r1, r2, 2\n"
	"\tldr r3, _08044AB0\n"
	"\tadds r0, r3\n"
	"\tadds r0, r1\n"
	"\tldr r5, [r0]\n"
	"\tadds r0, r5, 0\n"
	"\tbl EntityExists\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08044A7A\n"
	"\tldr r0, [r5, 0x70]\n"
	"\tadds r4, r0, 0\n"
	"\tmovs r0, 0xA4\n"
	"\tlsls r0, 1\n"
	"\tadds r1, r4, r0\n"
	"\tmovs r0, 0\n"
	"\tstrb r0, [r1]\n"
	"\tldrb r0, [r4, 0x6]\n"
	"\tmovs r6, 0x1\n"
	"\tcmp r0, 0\n"
	"\tbeq _08044A24\n"
	"\tmovs r6, 0\n"
"_08044A24:\n"
	"\tadds r0, r5, 0\n"
	"\tmovs r1, 0x32\n"
	"\tbl HasAbility\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08044A46\n"
	"\tldr r1, [r7]\n"
	"\tldr r2, _08044AA8\n"
	"\tadds r0, r1, r2\n"
	"\tstr r5, [r0]\n"
	"\tldr r3, _08044AAC\n"
	"\tadds r1, r3\n"
	"\tadds r0, r4, 0\n"
	"\tadds r0, 0x98\n"
	"\tldr r0, [r0]\n"
	"\tstr r0, [r1]\n"
"_08044A46:\n"
	"\tadds r0, r5, 0\n"
	"\tmovs r1, 0x3F\n"
	"\tbl HasAbility\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08044A60\n"
	"\tldr r0, [r7]\n"
	"\tldr r1, _08044AA4\n"
	"\tadds r0, r1\n"
	"\tadds r0, r6\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
"_08044A60:\n"
	"\tadds r0, r5, 0\n"
	"\tmovs r1, 0x38\n"
	"\tbl HasAbility\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08044A7A\n"
	"\tldr r0, [r7]\n"
	"\tldr r2, _08044A9C\n"
	"\tadds r0, r2\n"
	"\tadds r0, r6\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
"_08044A7A:\n"
	"\tmovs r3, 0x1\n"
	"\tadd r8, r3\n"
	"\tmov r0, r8\n"
	"\tcmp r0, 0x13\n"
	"\tble _080449F2\n"
	"\tmovs r0, 0\n"
	"\tbl sub_8043ED0\n"
"_08044A8A:\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08044A94: .4byte gSpeedTurns\n"
"_08044A98: .4byte gDungeonGlobalData\n"
"_08044A9C: .4byte 0x000037f8\n"
"_08044AA0: .4byte 0x000037f9\n"
"_08044AA4: .4byte 0x000037fa\n"
"_08044AA8: .4byte 0x00017b2c\n"
"_08044AAC: .4byte 0x00017b38\n"
"_08044AB0: .4byte 0x000135cc");
}
#endif

void sub_8044AB4(void)
{
  s32 index;
  
  if (gSpeedTurns[1][gDungeonGlobalData->speedTurnCounter + 1] != 0) {
    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
      if (EntityExists(gDungeonGlobalData->allPokemon[index])) {
        UseAttack(0);
        break;
      }
    }
    sub_807EAA0(1,0);
    sub_8086AC0();
    sub_8043ED0(0);
  }
}

bool8 sub_8044B28(void)
{
    if (gDungeonGlobalData->unk4 == 0) {
        if (GetLeaderEntity() == NULL) {
            gDungeonGlobalData->unk654 = 1;
        }
        else if (gDungeonGlobalData->unk2 == 1) {
            gDungeonGlobalData->unk654 = 2;
        }
        else if (gDungeonGlobalData->unk2 != 2) {
            return FALSE;
        }
        else {
            gDungeonGlobalData->unk654 = 2;
        }
    }
    return TRUE;
}
 
bool8 sub_8044B84(void)
{
    if(gDungeonGlobalData->unk10 != 0)
    {
        return TRUE;
    }
    else {
        return sub_8044B28();
    }
}

u8 *sub_8044BA8(u16 param_1, u8 itemIndex)
{
  u32 uVar3;
  u32 uVar4;
  
  if ((param_1 == 0x26) && (sub_8043D10() == 2)) {
    return *gUnknown_80F91EC;
  }
  else {
    uVar3 = uVar4 = strcmp(gUnknown_80F7C50[param_1 << 1], gUnknown_80F697C);
    if (uVar3 != 0) {
      uVar4 = 1;
    }
    if ((u8)(uVar4) == 0) {
        return gActions[GetItemCategory(itemIndex)].useText;
    }
    else
    {
        return gUnknown_80F7C50[param_1 << 1];
    }
  }
}

void sub_8044C10(u8 param_1)
{
    struct DungeonEntityData * entityData = GetLeaderEntityData();

    entityData->action.action = DUNGEON_ACTION_NONE;

    if(param_1)
    {
        entityData->action.actionUseIndex = 0;
        entityData->action.unkC = 0;
        entityData->action.itemTargetPosition.x = -1;
        entityData->action.itemTargetPosition.y = -1;
    }
}

void sub_8044C50(u16 action)
{
    struct DungeonEntityData * entityData = GetLeaderEntityData();

    entityData->action.action = action;
    entityData->action.actionUseIndex = 0;
    entityData->action.unkC = 0;
    entityData->action.itemTargetPosition.x = -1;
    entityData->action.itemTargetPosition.y = -1;
}

void ResetAction(struct DungeonActionContainer *actionPointer)
{
    actionPointer->action = DUNGEON_ACTION_NONE;
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}

void SetAction(struct DungeonActionContainer *actionPointer, u16 action)
{
    actionPointer->action = action;
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}

void SetWalkAction(struct DungeonActionContainer *actionPointer, s16 species)
{
    if (GetIsMoving(species))
    {
        actionPointer->action = DUNGEON_ACTION_WALK;
    }
    else
    {
        actionPointer->action = DUNGEON_ACTION_WAIT;
    }
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}
