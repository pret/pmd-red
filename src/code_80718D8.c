#include "global.h"
#include "globaldata.h"
#include "constants/tactic.h"
#include "dungeon_config.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "code_8041AD0.h"
#include "code_8077274_1.h"
#include "constants/dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_misc.h"
#include "dungeon_random.h"
#include "dungeon_vram.h"
#include "dungeon_util.h"
#include "dungeon_spawns.h"
#include "dungeon_info.h"
#include "pokemon_3.h"
#include "code_805D8C8.h"
#include "structs/str_806B7F8.h"
#include "dungeon_logic.h"
#include "dungeon_strings.h"
#include "dungeon_menu_moves.h"
#include "code_806CD90.h"
#include "moves.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_pokemon.h"
#include "structs/str_806B7F8.h"
#include "dungeon_pos_data.h"

EWRAM_DATA s32 gUnknown_202F31C[2] = {0, 0};
EWRAM_DATA s32 gUnknown_202F324[2] = {0, 0};

extern void ResetMonEntityData(EntityInfo *, u32);
void sub_8042A44(Entity *r0);
void sub_8083D78(void);
void sub_8083D58(void);
void sub_8072778(Entity *, Entity *, u8, u8);
bool8 sub_80725A4(Entity *, Entity *);
void GetAvailTacticsforLvl_Bool(u8 *tacticsBuffer, s32 pokeLevel);
bool8 sub_80723D0(Entity *, Entity *, u8, u8);
void sub_807218C(Entity *);

extern void sub_8072B78(Entity *pokemon, Entity *target, s16 id);
extern s32 GetMovesLearnedAtLevel(u16* dst, s16 species, s32 level, s32 IQPoints);

void sub_8072B24(Entity *entity, Move *moves);

static const u8 gUnknown_8107010[8] = {0, 1, 1, 2, 1, 1, 0, 0};
static const u8 * const gUnknown_8107018[3] = {
    _(""),
    _("{WAIT_PRESS}\n"),
    _("\n"),
};

void sub_8071D4C(Entity *pokemon, Entity *target, s32 exp)
{
  s32 newExp;
  s32 expDiff;
  EntityInfo *info;

  info = GetEntInfo(target);
  if (info->level != 100) {
    if (!IsExperienceLocked(info->joinedAt.id)) {
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
    if (!EntityIsValid(entityPtr)) {
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
      if (!EntityIsValid(target))
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
              TryDisplayDungeonLoggableMessage3(entityPtr,target,gUnknown_80F9E64); // $m0 gained $d0 Exp Points
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
                if ((CanMonsterBeSpawnedHere(*id) != 0) && (GetSpriteData(*id) != NULL)) {
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
                TryDisplayDungeonLoggableMessage3(entityPtr,target,gUnknown_80FF730); // $i0 was added to $m0's list of usable tactics
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

    if (EntityIsValid(target)) {
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
        if (!IsExperienceLocked(info->joinedAt.id)) {
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
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FF730);
                }
            }
        }
        info->expGainedInTurn = 0;
        info->unk149 = 0;
        if ((flag == 0) && (param_4 != 0)) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80F9B74);
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
        if(info->joinedAt.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
        {
            r1 = 0x1A4;
        }
        else if(info->joinedAt.id == DUNGEON_RESCUE_TEAM_BASE)
        {
            r1 = 0x1A5;
        }
        else if(info->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            if(gDungeon->unk644.unk18 == 0)
                r3 = 1;
        }
        sub_806A3D4(buffer, r1, 3, r3);
    }
    else
    {
        strcpy(buffer, gUnknown_80FCF18);
    }
    DisplayDungeonMessage(0, buffer, 1);
    buffer[0] = 0;


    if(gFormatArgs[0]> 0)
    {
        strcat(buffer, gUnknown_80F9ACC);
        r6++;
    }

    if(gFormatArgs[1]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, gUnknown_80F9AEC);
        r6++;
    }
    if(gFormatArgs[2]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, gUnknown_80F9B10);
        r6++;
    }
    if(gFormatArgs[3]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, gUnknown_80F9B34);
        r6++;
    }
    if(gFormatArgs[4]> 0)
    {
        if(gUnknown_8107010[r6] != 0)
            strcat(buffer, gUnknown_8107018[gUnknown_8107010[r6]]);
        strcat(buffer, gUnknown_80F9B58);
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

    if(EntityIsValid(target))
    {
        flag = FALSE;
        info = GetEntInfo(target);
        if(!IsExperienceLocked(info->joinedAt.id))
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
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F9B94);
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

    if(!EntityIsValid(target)) return FALSE;
    info = GetEntInfo(target);
    id = info->id;
    exp = info->exp;


    if(IsExperienceLocked(info->joinedAt.id))
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
                DisplayDungeonLoggableMessage(target, gUnknown_80F9E80);
            }
            else
            {
                if(!flag)
                    sub_8083D58();
                gFormatArgs[0] = level;
                SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
                DisplayDungeonLoggableMessageTrue(target, gUnknown_80F9E80);
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

        gUnknown_202F31C[0] += leveldata.gainAtt[0];
        gUnknown_202F31C[1] += leveldata.gainAtt[1];
        gUnknown_202F324[0] += leveldata.gainDef[0];
        gUnknown_202F324[1] += leveldata.gainDef[1];

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


    if(!EntityIsValid(target)) return FALSE;
    info = GetEntInfo(target);
    id = info->id;
    exp = info->exp;
    oldLevel = info->level;


    if(IsExperienceLocked(info->joinedAt.id)) return FALSE;

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

            gUnknown_202F31C[0] -= leveldata.gainAtt[0];
            gUnknown_202F31C[1] -= leveldata.gainAtt[1];
            gUnknown_202F324[0] -= leveldata.gainDef[0];
            gUnknown_202F324[1] -= leveldata.gainDef[1];

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
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F9EC8); // $m0 dropped to Level $d0!
        return TRUE;
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F9EEC); // $m0's level didn't drop!
        return FALSE;
    }
}

void sub_8072778(Entity *pokemon, Entity *target, u8 param_2, u8 param_3)
{
    s32 i, j;
    u16 learnedMoves[16];
    Move localMoves[8];
    u8 text[0x64];
    s32 count;
    EntityInfo *info = GetEntInfo(target);
    bool8 sp_0xCC = FALSE;

    if (info->isNotTeamMember) {
        param_3 = 0;
        param_2 = 0;
    }

    count = GetMovesLearnedAtLevel(learnedMoves, info->id, info->level, info->IQ);
    unk_CopyMoves4To8AndClearFlag2Unk4(localMoves, info->moves.moves);

    if (count != 0) {
        s32 randIndex = DungeonRandInt(count);
        for (j = 0; j < 8; j++) {
            if(!MoveFlagExists(&localMoves[j])) {
                InitPokemonMove(&localMoves[j], learnedMoves[randIndex]);
                localMoves[j].moveFlags2 |= 4;
                break;
            }
        }
    }

    for (i = 0; i < 0x1E; i++) {
        count = 0;
        for (j = 0; j < 8; j++) {
            if (MoveFlagExists(&localMoves[j])) {
                count++;
            }
        }

        if (count <= MAX_MON_MOVES) {
            s32 i;
            bool8 r3 = FALSE;

            for (i = 0; i < count; i++) {
                info->moves.moves[i] = localMoves[i];
                if((info->moves.moves[i].moveFlags2 & 4))
                {
                    info->moves.moves[i].moveFlags2 &= 0xFB;
                    BufferMoveName(text, &info->moves.moves[i], 0);
                    r3 = TRUE;
                }
            }
            for (; i < MAX_MON_MOVES; i++) {
                ResetMoveFlags(&info->moves.moves[i]);
            }

            if (r3 && param_2) {
                SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
                strcpy(gFormatBuffer_Items[0], text);
                sub_80421C0(target, 312);
                DisplayDungeonLoggableMessage(target, gUnknown_80F9F04);
            }

            return;
        }

        if (!info->isNotTeamMember && param_3) {
            if (!sp_0xCC && param_2) {
                sub_803E708(0xA, 0x6);
                DisplayDungeonMessage(0, gUnknown_80F9FA4, 1);
            }
            sp_0xCC = 1;
            sub_8063E70(target, localMoves, 1, 0);
        }
        else {
            sub_8072B24(target, localMoves);
        }
    }
}

bool8 sub_8072938(Entity *target, u16 moveId)
{
    s32 i, j;
    Move localMoves[8];
    u8 text[0x64];
    s32 count;
    EntityInfo *info = GetEntInfo(target);
    bool8 r10 = FALSE;

    unk_CopyMoves4To8AndClearFlag2Unk4(localMoves, info->moves.moves);
    for (j = 0; j < 8; j++) {
        if(!(MoveFlagExists(&localMoves[j]))) {
            InitPokemonMove(&localMoves[j], moveId);
            localMoves[j].moveFlags2 |= 4;
            break;
        }
    }

    for (i = 0; i < 0x1E; i++) {
        count = 0;
        for (j = 0; j < 8; j++) {
            if (MoveFlagExists(&localMoves[j])) {
                count++;
            }
        }

        if (count <= MAX_MON_MOVES) {
            s32 i;

            for (i = 0; i < count; i++) {
                info->moves.moves[i] = localMoves[i];
                if((info->moves.moves[i].moveFlags2 & 4))
                {
                    info->moves.moves[i].moveFlags2 &= 0xFB;
                    BufferMoveName(text, &info->moves.moves[i], 0);
                    r10 = TRUE;
                }
            }
            for (; i < MAX_MON_MOVES; i++) {
                ResetMoveFlags(&info->moves.moves[i]);
            }

            if (r10) {
                if (!info->isNotTeamMember) {
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
                    strcpy(gFormatBuffer_Items[0], text);
                    sub_80421C0(target, 312);
                    DisplayDungeonLoggableMessage(target, gUnknown_80F9F04);
                }
            }

            break;
        }

        r10 = FALSE;

        if (!info->isNotTeamMember) {
            DisplayDungeonMessage(0, gUnknown_80FDF40, 1);
            if (!sub_8063E70(target, localMoves, TRUE, TRUE)) {
                return FALSE;
            }
        }
    }

    if (!r10 && !info->isNotTeamMember) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
        DisplayDungeonLoggableMessage(target, gUnknown_80F9F2C);
    }
    return TRUE;
}

void sub_8072AC8(s16 *param_1, s16 species, s32 param_3)
{
  const u8 *levelUpMoves;
  s32 arrIndex;
  s32 counter;
  u16 moveIDs [2];
  s32 species_s32;
  s32 index;

  species_s32 = species;

  for(index = 0; index < MAX_MON_MOVES; index++) {
    param_1[index] = MOVE_NOTHING;
  }

  counter = 0;
  levelUpMoves = GetLevelUpMoves(species_s32);

  while( 1 ) {
    if (*levelUpMoves == 0) {
      return;
    }
    levelUpMoves = DecompressMoveID(levelUpMoves,moveIDs);
    if (*levelUpMoves++ > param_3) break;
    if (counter == MAX_MON_MOVES) {
      arrIndex = DungeonRandInt(MAX_MON_MOVES);
      counter = MAX_MON_MOVES;
    }
    else {
      arrIndex = counter;
      counter++;
    }
    param_1[arrIndex] = moveIDs[0];
  }
}

void sub_8072B24(Entity *entity, Move *moves)
{
    int index;
    int count;

    count = 0;
    for(index = 0; index < 8; index++)
    {
        if (moves[index].moveFlags & MOVE_FLAG_EXISTS) {
            moves[index].moveFlags &= 0xfd;
            count++;
        }
    }
    index = DungeonRandInt(count);
    for (; index < 7; index++) {
        moves[index] = moves[index + 1];
    }
    moves[7].moveFlags = 0;
}

static inline void fu(EntityInfo *entityInfo, s16 id)
{
  ++id; --id;
  entityInfo->apparentID = id;
  entityInfo->id = id;
}

void sub_8072B78(Entity *pokemon, Entity *target, s16 id)
{
  OpenedFile *file;
  const Tile *tile;
  int index;
  s32 id_s32;
  EntityInfo *entityInfo;
  LevelData levelData;
  struct unkStruct_806B7F8 local_2c;

  id_s32 = id;
  entityInfo = GetEntInfo(target);
  SetMessageArgument_2(gFormatBuffer_Monsters[0],entityInfo,0);
  CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[1],id_s32);
  file = GetSpriteData(id_s32);
  fu(entityInfo, id_s32);
  GetPokemonLevelData(&levelData,id_s32,entityInfo->level);
  entityInfo->exp = levelData.expRequired;
  target->axObj.spriteFile = file;
  ResetMonEntityData(entityInfo,0);
  sub_8069E0C(target);
  sub_806CCB4(target,7);
  TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE2EC);
  sub_8042A44(target);
  sub_8083D78();
  if (id_s32 == MONSTER_NINJASK) {
    for (index = 0; index < 8; index++) {
      tile = GetTile(gAdjacentTileOffsets[index].x + target->pos.x,gAdjacentTileOffsets[index].y + target->pos.y);
      if (sub_807034C(MONSTER_SHEDINJA,tile) == 0) break;
    }
    if (CanMonsterBeSpawnedHere(MONSTER_SHEDINJA)) {
      local_2c.species = MONSTER_SHEDINJA;
      local_2c.level = entityInfo->level;
      local_2c.unk2 = 0;
      local_2c.pos.x = gAdjacentTileOffsets[index].x + target->pos.x;
      local_2c.pos.y = gAdjacentTileOffsets[index].y + target->pos.y;
      local_2c.unk4 = 0;
      local_2c.unk10 = 0;
      sub_806B7F8(&local_2c, TRUE);
    }
  }
}
