#include "global.h"
#include "globaldata.h"
#include "constants/type.h"
#include "structs/str_pokemon.h"
#include "dungeon_main.h"
#include "dungeon_misc.h"
#include "music_util.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_8097670.h"
#include "dungeon_info.h"
#include "dungeon_items.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_vram.h"
#include "dungeon_util.h"
#include "friend_area.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "position_util.h"
#include "text_util.h"
#include "dungeon_util_1.h"
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "string_format.h"

extern u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE];

u8 sub_806B8CC();
void sub_8083D88();
u8 sub_808529C(s32);
void nullsub_96(Entity *pokemon,Entity *target);
u8 sub_8097900(s16);
void sub_806F910(void);
u8 sub_806F9BC(s16);

bool8 sub_806F660(Entity *pokemon, Entity *target)
{
    s32 i;
    s32 rand;
    s32 recruitRate;
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 foundIndex = -1;
    s32 size = GetBodySize(targetInfo->apparentID);

    if (gDungeon->fixedRoomNumber != 5 && gDungeon->fixedRoomNumber != 4 && gDungeon->fixedRoomNumber != 9 && gDungeon->fixedRoomNumber != 0xf) {
        if ((gDungeon->fixedRoomNumber >= 0x2c && gDungeon->fixedRoomNumber <= 0x30)) {
            if (gDungeon->unk644.unk18 == 0)
                return FALSE;
        }
        else if (gDungeon->fixedRoomNumber == 0x31) {
            if (gDungeon->unk644.unk15 == 0)
                return FALSE;
            if (!sub_8097900(MONSTER_DEOXYS_NORMAL))
                return FALSE;
        }
        else if (!IsRecruitingEnabled(gDungeon->unk644.dungeonLocation.id)) {
            return FALSE;
        }
    }

    if (gDungeon->unk644.unk19 != 0)
        return FALSE;

    // Legendaries can only be recruited once.
    if ((targetInfo->id == MONSTER_ARTICUNO ||
         targetInfo->id == MONSTER_ZAPDOS ||
         targetInfo->id == MONSTER_MOLTRES ||
         targetInfo->id == MONSTER_ENTEI ||
         targetInfo->id == MONSTER_RAIKOU ||
         targetInfo->id == MONSTER_SUICUNE ||
         targetInfo->id == MONSTER_LATIAS ||
         targetInfo->id == MONSTER_LATIOS ||
         targetInfo->id == MONSTER_JIRACHI ||
         targetInfo->id == MONSTER_RAYQUAZA ||
         targetInfo->id == MONSTER_DEOXYS_NORMAL ||
         targetInfo->id == MONSTER_REGIROCK ||
         targetInfo->id == MONSTER_REGICE ||
         targetInfo->id == MONSTER_REGISTEEL)
        && HasRecruitedMon(targetInfo->id))
    {
        return FALSE;
    }

    if (!sub_806F9BC(targetInfo->id))
        return FALSE;
    if (abs((pokemon->pos).x - (target->pos).x) >= 2 || abs((pokemon->pos).y - (target->pos).y) >= 2)
        return FALSE;
    if (targetInfo->joinedAt.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
        return FALSE;
    if (targetInfo->monsterBehavior == 1)
        return FALSE;
    if (!CanSeeTarget(target,pokemon))
        return FALSE;

    sub_806F910();
    rand = DungeonRandInt(1000);
    recruitRate = GetRecruitRate(targetInfo->id);
    if (recruitRate == -999)
        return FALSE;

    if (HasHeldItem(pokemon, ITEM_FRIEND_BOW)) {
        recruitRate += gFriendBowRecruitRateUpValue;
    }
    recruitRate += gRecruitRateByLevel[pokemonInfo->level];
    if (rand >= recruitRate)
        return FALSE;

    for (i = 0; i <= (6 - size); i++) {
        s32 j;
        for (j = 0; j < size; j++) {
            if (gUnknown_202EE70[i + j] != 0)
                break;
        }

        if (j == size) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        nullsub_96(pokemon, target);
        return FALSE;
    }

    for (i = 0; i < 4; i++) {
        if (!DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[i]))
            break;
    }
    if (i == 4) {
        nullsub_96(pokemon, target);
        return FALSE;
    }

    for (i = 0; i < 4; i++) {
        if (!EntityIsValid(gDungeon->teamPokemon[i]))
            break;
    }
    if (i == 4) {
        nullsub_96(pokemon, target);
        return FALSE;
    }

    return TRUE;
}

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
        if (EntityIsValid(entity)) {
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
    FriendAreaCapacity auStack_18;

    id = species;
    if (!gDungeon->unk644.canRecruit) {
        return FALSE;
    }
    else if (sub_808529C(id) == 0) {
        return FALSE;
    }
    else if (id == MONSTER_MEW && gDungeon->unk644.unk34 == 1) {
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
            GetFriendAreaCapacity2(friendArea, &auStack_18, FALSE, FALSE);
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
    DungeonMon *pokeStruct2;
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

    if (DisplayDungeonYesNoMessage(0,gUnknown_80F9FE8,1) == 0) {
        if (param_3->id != MONSTER_JIRACHI) {
            LogMessageByIdWithPopupCheckUser(entity1,gUnknown_80FA004);
        }
        return 0;
    }
    else
    {
        for(pokeIndex = 0; pokeIndex < MAX_TEAM_MEMBERS; pokeIndex++)
        {
            if (!(DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[pokeIndex])))
                break;
        }

        if (pokeIndex == MAX_TEAM_MEMBERS) {
            LogMessageByIdWithPopupCheckUser(entity1,gUnknown_80FA030);
            return FALSE;
        }
        else {
            if (GetFriendAreaStatus(friendArea) == 0) {
                UnlockFriendArea(friendArea);
                flag = TRUE;
            }
            HandleFaint(entity2,500,entity1);
            pokeStruct2 = &gRecruitedPokemonRef->dungeonTeam[pokeIndex];
            pokeStruct2->flags = 3;
            pokeStruct2->isTeamLeader = FALSE;
            pokeStruct2->level = param_3->level;
            pokeStruct2->IQ = 1;
            SetDefaultIQSkills(&pokeStruct2->IQSkills,FALSE);
            pokeStruct2->hiddenPower = param_3->hiddenPower;
            pokeStruct2->tacticIndex = 0;
            pokeStruct2->recruitedPokemonId = -1;
            pokeStruct2->unkC = pokeIndex;
            pokeStruct2->speciesNum = param_3->id;
            (pokeStruct2->dungeonLocation) = gDungeon->unk644.dungeonLocation;
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

            IncrementAdventureNumJoined();

            if (sub_806B8CC(param_3->id,param_3->pos.x,param_3->pos.y,pokeStruct2,&local_2c,0,1) == 0) {
                LogMessageByIdWithPopupCheckUser(entity1,gUnknown_80FA058);
                pokeStruct2->flags = 0;
            }
            else {
                sub_8083D88();
                sub_803E708(0xa0,0x46);
                if (DisplayDungeonYesNoMessage(0,gUnknown_80FA090,1) == 1) {
                    while (DungeonGiveNameToRecruitedMon(pokeStruct2->name) == 0) {
                        DisplayDungeonMessage(0,gUnknown_80FA0C8,1);
                    }
                }
                sub_808D9DC(gFormatBuffer_Monsters[0],pokeStruct2,0);
                LogMessageByIdWithPopupCheckUser(entity1,gUnknown_80FA0F0);
                if (flag) {
                    leader = xxx_call_GetLeader();
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
                    sub_8092558(gFormatBuffer_FriendArea,friendArea);
                    PlaySound(0xce);
                    DisplayDungeonMessage(0,gUnknown_80FA120,1);
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

bool8 sub_806FD18(Entity *param_1)
{
    s32 i, j;

    EntityInfo *info = GetEntInfo(param_1);
    s32 validIndex = -1;
    s32 size = GetBodySize(info->apparentID);
    if (!sub_806F9BC(info->id))
        return FALSE;

    sub_806F910();
    for (i = 0; i <= (6 - size); i++) {
        for (j = 0; j < size; j++){
            if (gUnknown_202EE70[i + j] != 0)
                break;
        }
        if (j == size) {
            validIndex = i;
            break;
        }
    }
    if (validIndex == -1)
        return FALSE;


    for (i = 0; i < 4; i++) {
        if (!(DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[i])))
            break;
    }

    if (i == 4)
        return FALSE;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if(!EntityIsValid(gDungeon->teamPokemon[i]))
            break;
    }
    if (i == MAX_TEAM_MEMBERS)
        return FALSE;

    return TRUE;
}

bool8 sub_806FDF4(Entity *entity1,Entity *entity2,Entity **entityPtr)
{
  u8 friendArea;
  bool8 flag;
  Entity *leader;
  DungeonMon *pokeStruct2;
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
    if (!DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[index])) break;
  }

  if (index == MAX_TEAM_MEMBERS) {
    return FALSE;
  }
  else {
    friendArea = GetFriendArea(local_74.id);
    pokeStruct2 = &gRecruitedPokemonRef->dungeonTeam[index];
    pokeStruct2->flags = 3;
    pokeStruct2->isTeamLeader = FALSE;
    pokeStruct2->level = local_74.level;
    pokeStruct2->IQ = 1;
    SetDefaultIQSkills(&pokeStruct2->IQSkills,FALSE);
    pokeStruct2->hiddenPower = local_74.hiddenPower;
    pokeStruct2->tacticIndex = 0;
    pokeStruct2->recruitedPokemonId = -1;
    pokeStruct2->unkC = index;
    pokeStruct2->speciesNum = local_74.id;
    pokeStruct2->dungeonLocation = gDungeon->unk644.dungeonLocation;
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
    IncrementAdventureNumJoined();
    HandleFaint(entity2,500,entity1);
    if (sub_806B8CC(local_74.id,local_74.pos.x,local_74.pos.y,pokeStruct2,&local_2c,0,0) == 0) {
      pokeStruct2->flags = 0;
    }
    else {
      if (DisplayDungeonYesNoMessage(0,gUnknown_80FA090,1) == 1) {
        while (!DungeonGiveNameToRecruitedMon(buffer)) {
          DisplayDungeonMessage(0,gUnknown_80FA0C8,1);
        }
      }
      if (flag) {
        leader = xxx_call_GetLeader();
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
        sub_8092558(gFormatBuffer_FriendArea,friendArea);
        PlaySound(0xce);
        DisplayDungeonMessage(0,gUnknown_80FA120,1);
      }
      sub_808D9DC(gFormatBuffer_Monsters[3],pokeStruct2,0);
      *entityPtr = local_2c;
    }
   return TRUE;
  }
}
