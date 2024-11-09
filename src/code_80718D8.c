#include "global.h"
#include "constants/tactic.h"
#include "dungeon_capabilities.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "code_8045A00.h"
#include "code_8077274_1.h"
#include "constants/dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon.h"
#include "pokemon_3.h"
#include "status_checks_1.h"

struct unkStruct_806B7F8
{
    s16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    u8 fillA[2];
    struct Position pos;
    u8 unk10;
};

EWRAM_DATA s32 gUnknown_202F31C[2] = {0, 0};
EWRAM_DATA s32 gUnknown_202F324[2] = {0, 0};

extern s16 gUnknown_80F4DA6;
extern s16 gUnknown_80F4DA8;
extern s16 gUnknown_80F4DAA;
extern s16 gUnknown_80F4DAC;

extern u8 *gUnknown_80F9ACC[];
extern u8 *gUnknown_80F9AEC[];
extern u8 *gUnknown_80F9B10[];
extern u8 *gUnknown_80F9B34[];
extern u8 *gUnknown_80F9B58[];
extern u8 *gUnknown_80F9B74[];
extern u8 *gUnknown_80F9B94[];
extern u8 *gUnknown_80F9E64[];
extern u8 *gUnknown_80F9E80[];
extern u8 *gUnknown_80F9EC8[];
extern u8 *gUnknown_80F9EEC[];
extern u8 *gUnknown_80FCF18[];
extern u8 *gUnknown_80FED68[];
extern u8 *gUnknown_80FF730[];
extern u8 gUnknown_8107010[8];
extern u8 *gUnknown_8107018[3];

extern void sub_80421C0(Entity *pokemon, u16 r1);
void sub_8083D58(void);
void sub_8072778(Entity *, Entity *, u8, u8);
bool8 sub_80725A4(Entity *, Entity *);
void GetAvailTacticsforLvl_Bool(u8 *tacticsBuffer, s32 pokeLevel);
bool8 sub_80723D0(Entity *, Entity *, u8, u8);
void sub_807218C(Entity *);
void sub_806A2BC(Entity *, u32);
void sub_806A3D4(u8 *, s32, s32, s32);
extern Entity* sub_806B7F8(struct unkStruct_806B7F8 *, bool8);
extern void sub_8042920(struct Entity *r0);
extern s16 sub_803D970(u32);
extern s32 sub_803DA20(s32 param_1);
extern bool8 sub_806AA0C(s32, u32);
extern bool8 sub_8083660(struct Position *param_1);
void GetPokemonLevelData(LevelData* a1, s32 _id, s32 level); // TODO: change to s32

void sub_8071B48(void)
{
  struct Tile *tile;
  struct Entity *entity2;
  struct Entity *entity;
  int index;
  int index1;
  int counter;
  struct Entity *entityPtr;
  s32 level;
  struct Dungeon *dungeon; // feels like a hack
  struct unkStruct_806B7F8 local_2c;

  entityPtr = NULL;
  dungeon = gDungeon;
  if ((dungeon->unk644.unk20 != 0) &&
     ((dungeon->unk644.dungeonLocation.id != DUNGEON_METEOR_CAVE || (dungeon->unk37FD == 0)))) {
    dungeon->unk644.unk1E++;
    if (dungeon->unk644.unk2A == 0) {
      if ( dungeon->unk644.unk1E < gUnknown_80F4DAA) {
        return;
      }
    }
    else {
      if ( dungeon->unk644.unk1E < gUnknown_80F4DAC) {
        return;
      }
    }

    if (dungeon->unk644.unk1E > 900) {
      entity2 = dungeon->unk17B34;
      if ((EntityExists(entity2)) && (entity2->spawnGenID == dungeon->unk17B40)) {
        SetMessageArgument(gFormatBuffer_Monsters[0],entity2,0);
        entityPtr = entity2;
      }
    }

      dungeon->unk644.unk1E = 0;
      dungeon->unk17B34 = NULL;

      counter = 0;
      for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
      {
        entity = dungeon->wildPokemon[index];
        if ((EntityExists(entity)) &&
           (tile = GetTile((entity->pos).x, (entity->pos).y),
           (tile->terrainType & 0x100) == 0)) {
          counter++;
        }
      }
      if (dungeon->unk644.unk2A == 0) {
        if (gDungeon->unk3A0C == 0xff) {
            if (counter >= gUnknown_80F4DA6) {
              return;
            }
        }
        else
        {
            if (counter >= gUnknown_80F4DA8) {
              return;
            }
        }

      }
      if (entityPtr != NULL) {
        DisplayDungeonLoggableMessageTrue(0,*gUnknown_80FED68);
        sub_8042920(entityPtr);
      }
      if (dungeon->unk644.unk2A != 0) {
        index1 = 0x17c;
      }
      else {
        index1 = sub_803D970(0);
      }

      level = sub_803DA20(index1);
      if (level == 0) {
        level = 1;
      }
      if ((sub_806AA0C(index1, 0)) && (sub_8083660(&local_2c.pos))) {
        local_2c.species = index1;
        local_2c.level = level;
        local_2c.unk2 = 0;
        if(DungeonRandInt(100) < GetRandomMovementChance(gDungeon->unk644.dungeonLocation.id))
        {
            local_2c.unk4 = 1;
        }
        else
        {
            local_2c.unk4 = 0;
        }
        local_2c.unk10 = 0;
        sub_806B7F8(&local_2c, FALSE);
      }
  }
}

void sub_8071D4C(Entity *pokemon, Entity *target, s32 exp)
{
  s32 newExp;
  s32 expDiff;
  EntityInfo *info;

  info = GetEntInfo(target);
  if (info->level != 100) {
    if (!IsClientOrTeamBase(info->joinedAt.joinedAt)) {
      newExp = info->exp + exp;
      if (9999998 < newExp) {
        newExp = 9999999;
      }
      expDiff = newExp - info->exp;
      if (expDiff != 0) {
        info->expGainedInTurn += expDiff;
        gDungeon->unkD = 1;
      }
    }
  }
}

// https://decomp.me/scratch/Wcmvb - (98.45% matching - Seth)
NAKED
void sub_8071DA4(Entity *entity)
{
    asm_unified(
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0xD4\n"
"	str r0, [sp, 0xB4]\n"
"	ldr r2, _08071E44\n"
"	ldr r1, [r2]\n"
"	ldrb r0, [r1, 0xD]\n"
"	cmp r0, 0\n"
"	bne _08071DBE\n"
"	b _08071FE2\n"
"_08071DBE:\n"
"	movs r0, 0\n"
"	strb r0, [r1, 0xD]\n"
"	ldr r0, [r2]\n"
"	ldrb r0, [r0, 0x10]\n"
"	cmp r0, 0\n"
"	beq _08071DCC\n"
"	b _08071FE2\n"
"_08071DCC:\n"
"	ldr r0, [sp, 0xB4]\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _08071DE2\n"
"	mov r0, sp\n"
"	bl sub_80457DC\n"
"	mov r0, sp\n"
"	str r0, [sp, 0xB4]\n"
"_08071DE2:\n"
"	movs r4, 0\n"
"_08071DE4:\n"
"	movs r5, 0\n"
"	ldr r0, _08071E44\n"
"	ldr r0, [r0]\n"
"	lsls r1, r4, 2\n"
"	ldr r2, _08071E48\n"
"	adds r0, r2\n"
"	adds r0, r1\n"
"	ldr r0, [r0]\n"
"	mov r8, r0\n"
"	movs r0, 0\n"
"	str r0, [sp, 0xB8]\n"
"	movs r1, 0\n"
"	movs r2, 0\n"
"	str r1, [sp, 0xBC]\n"
"	str r2, [sp, 0xC0]\n"
"	movs r0, 0\n"
"	movs r1, 0\n"
"	str r0, [sp, 0xC4]\n"
"	str r1, [sp, 0xC8]\n"
"	adds r1, r4, 0x1\n"
"	str r1, [sp, 0xCC]\n"
"	mov r2, r8\n"
"	cmp r2, 0\n"
"	bne _08071E16\n"
"	b _08071FDA\n"
"_08071E16:\n"
"	mov r0, r8\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _08071E24\n"
"	b _08071FDA\n"
"_08071E24:\n"
"	mov r0, r8\n"
"	ldr r6, [r0, 0x70]\n"
"	movs r1, 0xE\n"
"	ldrsh r0, [r6, r1]\n"
"	cmp r0, 0\n"
"	bne _08071E32\n"
"	b _08071FDA\n"
"_08071E32:\n"
"	adds r1, r6, 0\n"
"	adds r1, 0xF9\n"
"	ldrb r0, [r1]\n"
"	cmp r0, 0\n"
"	beq _08071E4C\n"
"	add r2, sp, 0xB8\n"
"	ldrb r2, [r2]\n"
"	strb r2, [r1]\n"
"	b _08071FCA\n"
"	.align 2, 0\n"
"_08071E44: .4byte gDungeon\n"
"_08071E48: .4byte 0x000135cc\n"
"_08071E4C:\n"
"	movs r1, 254\n"
"	lsls r1, 1\n"
"	adds r0, r6, r1\n"
"	ldr r0, [r0]\n"
"	mov r10, r0\n"
"	cmp r0, 0\n"
"	beq _08071EB6\n"
"	ldrb r0, [r6, 0x7]\n"
"	cmp r0, 0\n"
"	beq _08071E68\n"
"	ldrb r1, [r6, 0x9]\n"
"	add r0, sp, 0x74\n"
"	bl GetAvailTacticsforLvl_Bool\n"
"_08071E68:\n"
"	movs r0, 0x10\n"
"	ldrsh r2, [r6, r0]\n"
"	str r2, [sp, 0xB8]\n"
"	ldrb r1, [r6, 0x14]\n"
"	str r1, [sp, 0xBC]\n"
"	ldrb r2, [r6, 0x15]\n"
"	str r2, [sp, 0xC0]\n"
"	ldrb r0, [r6, 0x16]\n"
"	str r0, [sp, 0xC4]\n"
"	ldrb r1, [r6, 0x17]\n"
"	str r1, [sp, 0xC8]\n"
"	ldrb r0, [r6, 0x9]\n"
"	cmp r0, 0x64\n"
"	beq _08071EB6\n"
"	ldr r0, [r6, 0x18]\n"
"	add r0, r10\n"
"	str r0, [r6, 0x18]\n"
"	mov r2, r10\n"
"	ldr r0, _08071EE8\n"
"	str r2, [r0]\n"
"	ldr r0, _08071EEC\n"
"	adds r1, r6, 0\n"
"	movs r2, 0\n"
"	bl SetMessageArgument_2\n"
"	ldr r0, _08071EF0\n"
"	ldr r2, [r0]\n"
"	ldr r0, [sp, 0xB4]\n"
"	mov r1, r8\n"
"	bl TryDisplayDungeonLoggableMessage3\n"
"	ldr r0, [sp, 0xB4]\n"
"	mov r1, r8\n"
"	movs r2, 0x1\n"
"	movs r3, 0x1\n"
"	bl sub_80723D0\n"
"	lsls r0, 24\n"
"	lsrs r5, r0, 24\n"
"_08071EB6:\n"
"	ldr r1, _08071EF4\n"
"	adds r0, r6, r1\n"
"	ldrb r0, [r0]\n"
"	adds r4, 0x1\n"
"	str r4, [sp, 0xCC]\n"
"	cmp r0, 0\n"
"	beq _08071F3A\n"
"	movs r2, 0x2\n"
"	ldrsh r0, [r6, r2]\n"
"	add r1, sp, 0x8C\n"
"	movs r2, 0\n"
"	movs r3, 0\n"
"	bl sub_808E400\n"
"	adds r7, r0, 0\n"
"	add r0, sp, 0x8C\n"
"	mov r9, r0\n"
"	cmp r7, 0\n"
"	beq _08071F38\n"
"	adds r0, r7, 0\n"
"	bl DungeonRandInt\n"
"	adds r4, r0, 0\n"
"	movs r1, 0\n"
"	b _08071F02\n"
"	.align 2, 0\n"
"_08071EE8: .4byte gFormatArgs\n"
"_08071EEC: .4byte gFormatBuffer_Monsters\n"
"_08071EF0: .4byte gUnknown_80F9E64\n"
"_08071EF4: .4byte 0x00000149\n"
"_08071EF8:\n"
"	adds r4, 0x1\n"
"	cmp r4, r7\n"
"	blt _08071F00\n"
"	movs r4, 0\n"
"_08071F00:\n"
"	adds r1, 0x1\n"
"_08071F02:\n"
"	cmp r1, r7\n"
"	bge _08071F38\n"
"	lsls r0, r4, 1\n"
"	mov r2, r9\n"
"	adds r5, r2, r0\n"
"	movs r2, 0\n"
"	ldrsh r0, [r5, r2]\n"
"	str r1, [sp, 0xD0]\n"
"	bl sub_803D930\n"
"	lsls r0, 24\n"
"	ldr r1, [sp, 0xD0]\n"
"	cmp r0, 0\n"
"	beq _08071EF8\n"
"	movs r2, 0\n"
"	ldrsh r0, [r5, r2]\n"
"	bl GetSpriteData\n"
"	ldr r1, [sp, 0xD0]\n"
"	cmp r0, 0\n"
"	beq _08071EF8\n"
"	movs r0, 0\n"
"	ldrsh r2, [r5, r0]\n"
"	ldr r0, [sp, 0xB4]\n"
"	mov r1, r8\n"
"	bl sub_8072B78\n"
"_08071F38:\n"
"	movs r5, 0\n"
"_08071F3A:\n"
"	cmp r5, 0\n"
"	beq _08071F7A\n"
"	ldrb r0, [r6, 0x6]\n"
"	cmp r0, 0\n"
"	bne _08071F7A\n"
"	movs r1, 0x10\n"
"	ldrsh r0, [r6, r1]\n"
"	ldr r2, [sp, 0xB8]\n"
"	subs r0, r2\n"
"	ldr r1, _08071FF4\n"
"	str r0, [r1]\n"
"	ldrb r0, [r6, 0x14]\n"
"	ldr r2, [sp, 0xBC]\n"
"	subs r0, r2\n"
"	str r0, [r1, 0x4]\n"
"	ldrb r0, [r6, 0x16]\n"
"	ldr r1, [sp, 0xC4]\n"
"	subs r0, r1\n"
"	ldr r2, _08071FF4\n"
"	str r0, [r2, 0x8]\n"
"	ldrb r0, [r6, 0x15]\n"
"	ldr r1, [sp, 0xC0]\n"
"	subs r0, r1\n"
"	str r0, [r2, 0xC]\n"
"	ldrb r0, [r6, 0x17]\n"
"	ldr r2, [sp, 0xC8]\n"
"	subs r0, r2\n"
"	ldr r1, _08071FF4\n"
"	str r0, [r1, 0x10]\n"
"	mov r0, r8\n"
"	bl sub_807218C\n"
"_08071F7A:\n"
"	mov r2, r10\n"
"	cmp r2, 0\n"
"	beq _08071FCA\n"
"	ldrb r0, [r6, 0x7]\n"
"	cmp r0, 0\n"
"	beq _08071FCA\n"
"	ldrb r1, [r6, 0x9]\n"
"	add r0, sp, 0x80\n"
"	bl GetAvailTacticsforLvl_Bool\n"
"	movs r4, 0\n"
"	add r7, sp, 0x74\n"
"	add r5, sp, 0x80\n"
"_08071F94:\n"
"	adds r0, r7, r4\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _08071FC4\n"
"	adds r0, r5, r4\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0x1\n"
"	bne _08071FC4\n"
"	ldr r0, _08071FF8\n"
"	mov r1, r8\n"
"	movs r2, 0\n"
"	bl SetMessageArgument\n"
"	lsls r1, r4, 24\n"
"	lsrs r1, 24\n"
"	ldr r0, _08071FFC\n"
"	bl CopyTacticsNameToBuffer\n"
"	ldr r0, _08072000\n"
"	ldr r2, [r0]\n"
"	ldr r0, [sp, 0xB4]\n"
"	mov r1, r8\n"
"	bl TryDisplayDungeonLoggableMessage3\n"
"_08071FC4:\n"
"	adds r4, 0x1\n"
"	cmp r4, 0xB\n"
"	ble _08071F94\n"
"_08071FCA:\n"
"	movs r1, 254\n"
"	lsls r1, 1\n"
"	adds r0, r6, r1\n"
"	movs r1, 0\n"
"	str r1, [r0]\n"
"	ldr r2, _08072004\n"
"	adds r0, r6, r2\n"
"	strb r1, [r0]\n"
"_08071FDA:\n"
"	ldr r4, [sp, 0xCC]\n"
"	cmp r4, 0x13\n"
"	bgt _08071FE2\n"
"	b _08071DE4\n"
"_08071FE2:\n"
"	add sp, 0xD4\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_08071FF4: .4byte gFormatArgs\n"
"_08071FF8: .4byte gFormatBuffer_Monsters\n"
"_08071FFC: .4byte gFormatBuffer_Items\n"
"_08072000: .4byte gUnknown_80FF730\n"
"_08072004: .4byte 0x00000149");
}

void sub_8072008(Entity *pokemon, Entity *target, s32 level, u8 param_4, u8 param_5)
{
    bool8 flag;
    s32 newLevel;
    EntityInfo *info;
    s32 tacticIndex;
    LevelData leveldata;
    u8 tacticsBuffer1 [NUM_TACTICS];
    u8 tacticsBuffer2 [NUM_TACTICS];
    s32 maxHP;
    u32 atk[2];
    u32 def[2];

    if (EntityExists(target)) {
        flag = 0;
        info = GetEntInfo(target);
        if (info->isTeamLeader) {
            GetAvailTacticsforLvl_Bool(tacticsBuffer1,info->level);
        }
        maxHP = info->maxHPStat;
        atk[0] = info->atk[0];
        atk[1] = info->atk[1];
        def[0] = info->def[0];
        def[1] = info->def[1];
        if (!IsClientOrTeamBase(info->joinedAt.joinedAt)) {
            newLevel = info->level + level;
            if (99 < newLevel) {
                newLevel = 100;
            }
            if (newLevel != info->level) {
                GetPokemonLevelData(&leveldata,info->id,newLevel);
                info->exp = leveldata.expRequired;
                flag |= (sub_80723D0(pokemon,target,param_4,param_5));
                if ((flag != 0) && (!info->isNotTeamMember)) {
                    gFormatArgs[0] = info->maxHPStat - maxHP;
                    gFormatArgs[1] = info->atk[0] - atk[0];
                    gFormatArgs[2] = info->def[0] - def[0];
                    gFormatArgs[3] = info->atk[1] - atk[1];
                    gFormatArgs[4] = info->def[1] - def[1];
                    if (param_4 != 0) {
                        sub_807218C(target);
                    }
                }
            }
        }
        if (info->isTeamLeader) {
            GetAvailTacticsforLvl_Bool(tacticsBuffer2,info->level);
            for(tacticIndex = 0; tacticIndex < NUM_TACTICS; tacticIndex++)
            {
                if ((tacticsBuffer1[tacticIndex] == 0) && (tacticsBuffer2[tacticIndex] == 1)) {
                    SetMessageArgument(gFormatBuffer_Monsters[0],target,0);
                    CopyTacticsNameToBuffer(gFormatBuffer_Items[0],tacticIndex);
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FF730);
                }
            }
        }
        info->expGainedInTurn = 0;
        info->unk149 = 0;
        if ((flag == 0) && (param_4 != 0)) {
            SetMessageArgument(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80F9B74);
        }
    }
}

void sub_807218C(Entity *pokemon)
{
    EntityInfo *info;
    u8 buffer [400];
    s32 r1;
    s32 r6;
    s32 r3;

    r6 = 0;
    info = GetEntInfo(pokemon);

    sub_806A2BC(pokemon, 0);
    SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
    if(sub_8070BC0(pokemon))
    {
        r3 = 0;
        r1 = info->id;
        if(info->joinedAt.joinedAt == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
        {
            r1 = 0x1A4;
        }
        else if(info->joinedAt.joinedAt == DUNGEON_RESCUE_TEAM_BASE)
        {
            r1 = 0x1A5;
        }
        else if(info->joinedAt.joinedAt == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            if(gDungeon->unk644.unk18 == 0)
                r3 = 1;
        }
        sub_806A3D4(buffer, r1, 3, r3);
    }
    else
    {
        strcpy(buffer, *gUnknown_80FCF18);
    }
    DisplayDungeonMessage(0, buffer, 1);
    buffer[0] = 0;


    if(gFormatArgs[0]> 0)
    {
        strcat(buffer, *gUnknown_80F9ACC);
        r6++;
    }

    if(gFormatArgs[1]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, *gUnknown_80F9AEC);
        r6++;
    }
    if(gFormatArgs[2]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, *gUnknown_80F9B10);
        r6++;
    }
    if(gFormatArgs[3]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, *gUnknown_80F9B34);
        r6++;
    }
    if(gFormatArgs[4]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, *gUnknown_80F9B58);
    }

    if(buffer[0])
        DisplayDungeonMessage(0, buffer, 1);

    sub_806A2BC(GetLeader(), 0);
}

void LevelDownTarget(Entity *pokemon, Entity *target, u32 level)
{
    EntityInfo *info;
    u8 flag;
    s32 newLevel;
    LevelData leveldata;

    if(EntityExists(target))
    {
        flag = FALSE;
        info = GetEntInfo(target);
        if(!IsClientOrTeamBase(info->joinedAt.joinedAt))
        {
            newLevel = info->level - level;
            if(newLevel <= 0)
                newLevel = 1;

            if(newLevel != info->level)
            {
                GetPokemonLevelData(&leveldata, info->id, newLevel);
                info->exp = leveldata.expRequired;
                flag |= sub_80725A4(pokemon, target);
            }
        }
        info->expGainedInTurn = 0;
        info->unk149 = 0;

        if(!flag)
        {
            SetMessageArgument(gFormatBuffer_Monsters[0], target, 0);
            TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80F9B94);
        }
    }
}

bool8 sub_80723D0(Entity *pokemon, Entity *target, u8 param_3, u8 param_4)
{
    EntityInfo *info;
    LevelData leveldata;
    bool8 flag = FALSE;
    s32 id;
    s32 level;
    s32 exp;

    if(!EntityExists(target)) return FALSE;
    info = GetEntInfo(target);
    id = info->id;
    exp = info->exp;


    if(IsClientOrTeamBase(info->joinedAt.joinedAt))
        return FALSE;

    for(level = info->level + 1; level <= 100; level++)
    {
        GetPokemonLevelData(&leveldata, id, level);
        if(leveldata.expRequired > exp) break;

        info->level = level;
        info->exp = exp;

        if(param_3)
        {
            if(!info->isNotTeamMember)
            {
                sub_806A2BC(target, 0);
                if(!flag)
                    sub_8083D58();
                gFormatArgs[0] = level;

                SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
                DisplayDungeonLoggableMessage(target, *gUnknown_80F9E80);
            }
            else
            {
                if(!flag)
                    sub_8083D58();
                gFormatArgs[0] = level;
                SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
                DisplayDungeonLoggableMessageTrue(target, *gUnknown_80F9E80);
            }
        }
        flag = TRUE;

        info->maxHPStat += leveldata.gainHP;
        info->HP += leveldata.gainHP;

        if(info->maxHPStat > 998)
            info->maxHPStat = 999;

        if(info->HP >= info->maxHPStat)
        {
            info->HP = info->maxHPStat;
        }

        gUnknown_202F31C[0] = info->atk[0];
        gUnknown_202F31C[1] = info->atk[1];
        gUnknown_202F324[0] = info->def[0];
        gUnknown_202F324[1] = info->def[1];

        gUnknown_202F31C[0] += leveldata.gainAtt;
        gUnknown_202F31C[1] += leveldata.gainSPAtt;
        gUnknown_202F324[0] += leveldata.gainDef;
        gUnknown_202F324[1] += leveldata.gainSPDef;

        if(gUnknown_202F31C[0] > 254)
            gUnknown_202F31C[0] = 255;
        if(gUnknown_202F31C[1] > 254)
            gUnknown_202F31C[1] = 255;
        if(gUnknown_202F324[0] > 254)
            gUnknown_202F324[0] = 255;
        if(gUnknown_202F324[1] > 254)
            gUnknown_202F324[1] = 255;


        LoadIQSkills(target);
        sub_8079764(target);

        info->atk[0] = gUnknown_202F31C[0];
        info->atk[1] = gUnknown_202F31C[1];
        info->def[0] = gUnknown_202F324[0];
        info->def[1] = gUnknown_202F324[1];

        sub_8072778(pokemon, target, param_3, param_4);
    }

    return flag;
}

bool8 sub_80725A4(Entity *pokemon, Entity *target)
{
    EntityInfo *info;
    LevelData leveldata;
    s32 level;
    s32 levelMax;
    s32 id;
    s32 exp;
    s32 oldLevel;


    if(!EntityExists(target)) return FALSE;
    info = GetEntInfo(target);
    id = info->id;
    exp = info->exp;
    oldLevel = info->level;


    if(IsClientOrTeamBase(info->joinedAt.joinedAt)) return FALSE;

    for(level = 1; level < info->level; level++)
    {
        GetPokemonLevelData(&leveldata, id, level);
        if(leveldata.expRequired >= exp) break;
    }

    levelMax = level - 1;

    for(level = info->level; level > levelMax; level--)
    {
        if(level < 100)
        {
            GetPokemonLevelData(&leveldata, id, level + 1);
            info->exp = leveldata.expRequired - 1;
        }
        else
        {
            info->exp = exp;
        }

        if(oldLevel > level)
        {
            GetPokemonLevelData(&leveldata, id, level + 1);

            info->level = level;

            info->maxHPStat -= leveldata.gainHP;
            info->HP -= leveldata.gainHP;

            if(info->HP <= 1)
                info->HP = 1;

            if(info->maxHPStat <= 1)
                info->maxHPStat = 1;

            if(info->HP >= info->maxHPStat)
            {
                info->HP = info->maxHPStat;
            }

            gUnknown_202F31C[0] = info->atk[0];
            gUnknown_202F31C[1] = info->atk[1];
            gUnknown_202F324[0] = info->def[0];
            gUnknown_202F324[1] = info->def[1];

            gUnknown_202F31C[0] -= leveldata.gainAtt;
            gUnknown_202F31C[1] -= leveldata.gainSPAtt;
            gUnknown_202F324[0] -= leveldata.gainDef;
            gUnknown_202F324[1] -= leveldata.gainSPDef;

            if(gUnknown_202F31C[0] <= 1)
                gUnknown_202F31C[0] = 1;
            if(gUnknown_202F31C[1] <= 1)
                gUnknown_202F31C[1] = 1;
            if(gUnknown_202F324[0] <= 1)
                gUnknown_202F324[0] = 1;
            if(gUnknown_202F324[1] <= 1)
                gUnknown_202F324[1] = 1;


            LoadIQSkills(target);
            sub_8079764(target);

            info->atk[0] = gUnknown_202F31C[0];
            info->atk[1] = gUnknown_202F31C[1];
            info->def[0] = gUnknown_202F324[0];
            info->def[1] = gUnknown_202F324[1];
        }
    }


    SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);

    if(info->level != oldLevel)
    {
        gFormatArgs[0] = info->level;
        sub_80421C0(target, 0xD3 << 1);
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80F9EC8); // $m0 dropped to Level $d0!
        return TRUE;
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80F9EEC); // $m0's level didn't drop!
        return FALSE;
    }
}
