#include "global.h"
#include "constants/tactic.h"
#include "dungeon_capabilities.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "code_8041AD0.h"
#include "code_80450F8.h"
#include "code_8045A00.h"
#include "code_8077274_1.h"
#include "constants/dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon.h"
#include "pokemon_3.h"
#include "status_checks_1.h"
#include "code_805D8C8.h"

struct unkStruct_806B7F8
{
    s16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    u8 fillA[2];
    DungeonPos pos;
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
extern bool8 sub_8083660(DungeonPos *param_1);
extern bool8 sub_803D930(u32);
extern void sub_8072B78(Entity *pokemon, Entity *target, s16 id);
extern s32 sub_808E400(s32 _species, s16* _a2, bool32 bodySizeCheck, bool32 shedinjaCheck);
void GetPokemonLevelData(LevelData* a1, s32 _id, s32 level); // TODO: change to s32

void sub_8071B48(void)
{
  const Tile *tile;
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
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity2,0);
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

void sub_8071DA4(Entity *entity)
{
  int counter;
  s16 *id;
  Entity EStack_f4;
  u8 tacticsBuffer1[NUM_TACTICS];
  u8 tacticsBuffer2[NUM_TACTICS];
  s16 idStack [20];
  Entity *entityPtr; // 0xB4
  s32 index;

  entityPtr = entity;
  if ((gDungeon->unkD != 0) && (gDungeon->unkD = 0, gDungeon->unk10 == 0)) {
    if (!EntityExists(entityPtr)) {
      sub_80457DC(&EStack_f4);
      entityPtr = &EStack_f4;
    }
    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      EntityInfo *info;
      bool8 flag = FALSE;
      Entity *target = gDungeon->activePokemon[index];
      s32 maxHP = 0;
      u32 atk[2] = {0, 0};
      u32 def[2] = {0, 0};

      if (target == NULL)
        continue;
      if (!EntityExists(target))
        continue;

      info = GetEntInfo(target);
      if (info->HP != 0) {
        if (info->unkF9 != 0) {
            info->unkF9 = 0;
        }
        else
        {
          s32 expGained = info->expGainedInTurn;
          if (expGained != 0) {
            if (info->isTeamLeader) {
              GetAvailTacticsforLvl_Bool(tacticsBuffer1, info->level);
            }
            maxHP = info->maxHPStat;
            atk[0] = info->atk[0];
            atk[1] = info->atk[1];
            def[0] = info->def[0];
            def[1] = info->def[1];
            if (info->level != 100) {
              info->exp += expGained;
              gFormatArgs[0] = expGained;
              SetMessageArgument_2(gFormatBuffer_Monsters[0],info,0);
              TryDisplayDungeonLoggableMessage3(entityPtr,target,*gUnknown_80F9E64); // $m0 gained $d0 Exp Points
              flag = sub_80723D0(entityPtr,target,1,1);
            }
          }
          if (info->unk149 != 0) {
            s32 numMons = sub_808E400(info->id, idStack, FALSE, FALSE);
            if (numMons != 0) {
              s32 randIndex = DungeonRandInt(numMons);
              for(counter = 0; counter < numMons; counter++)
              {
                id = &idStack[randIndex];
                if ((sub_803D930(*id) != 0) && (GetSpriteData(*id) != NULL)) {
                  sub_8072B78(entityPtr,target,*id);
                  break;
                }
                randIndex++;
                if (randIndex >= numMons) {
                  randIndex = 0;
                }
              }
            }
            flag = FALSE;
          }
          if (flag && (!info->isNotTeamMember)) {
            gFormatArgs[0] = info->maxHPStat - maxHP;
            gFormatArgs[1] = info->atk[0] - atk[0];
            gFormatArgs[2] = info->def[0] - def[0];
            gFormatArgs[3] = info->atk[1] - atk[1];
            gFormatArgs[4] = info->def[1] - def[1];
            sub_807218C(target);
          }
          if ((expGained != 0) && (info->isTeamLeader)) {
            s32 tacticIndex;

            GetAvailTacticsforLvl_Bool(tacticsBuffer2,info->level);
            for(tacticIndex = 0; tacticIndex < NUM_TACTICS; tacticIndex++)
            {
              if ((tacticsBuffer1[tacticIndex] == 0) && (tacticsBuffer2[tacticIndex] == 1)) {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
                CopyTacticsNameToBuffer(gFormatBuffer_Items[0],tacticIndex);
                TryDisplayDungeonLoggableMessage3(entityPtr,target,*gUnknown_80FF730); // $i0 was added to $m0's list of usable tactics
              }
            }
          }
        }
        info->expGainedInTurn = 0;
        info->unk149 = 0;
      }
    }
  }
  return;
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
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
                    CopyTacticsNameToBuffer(gFormatBuffer_Items[0],tacticIndex);
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FF730);
                }
            }
        }
        info->expGainedInTurn = 0;
        info->unk149 = 0;
        if ((flag == 0) && (param_4 != 0)) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
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
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
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
