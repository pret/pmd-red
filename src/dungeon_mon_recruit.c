#include "global.h"
#include "globaldata.h"
#include "dungeon_mon_recruit.h"
#include "constants/dungeon_exit.h"
#include "constants/fixed_rooms.h"
#include "constants/type.h"
#include "structs/str_pokemon.h"
#include "dungeon_main.h"
#include "dungeon_misc.h"
#include "music_util.h"
#include "dungeon_message.h"
#include "dungeon_mon_sprite_render.h"
#include "adventure_info.h"
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
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "dungeon_music.h"
#include "dungeon_cutscene.h"
#include "string_format.h"
#include "dungeon_mon_spawn.h"
#include "move_orb_effects_5.h"
#include "adventure_info.h"

static void nullsub_96(Entity *pokemon,Entity *target);
static void sub_806F910(void);

bool8 TryRecruitMonster(Entity *attacker, Entity *target)
{
    s32 i;
    s32 rand;
    s32 recruitRate;
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 foundIndex = -1;
    s32 size = GetBodySize(targetInfo->apparentID);

    if (gDungeon->fixedRoomNumber != FIXED_ROOM_FROSTY_GROTTO_ARTICUNO
        && gDungeon->fixedRoomNumber != FIXED_ROOM_MT_BLAZE_PEAK_MOLTRES
        && gDungeon->fixedRoomNumber != FIXED_ROOM_WESTERN_CAVE_MEWTWO
        && gDungeon->fixedRoomNumber != FIXED_ROOM_MT_FARAWAY_HO_OH
    ) {
        if (gDungeon->fixedRoomNumber >= FIXED_ROOM_TEAM_SHIFTY_BOSS
            && gDungeon->fixedRoomNumber <= FIXED_ROOM_RESCUE_TEAM_2_BOSS
        ) {
            if (gDungeon->unk644.unk18 == 0)
                return FALSE;
        }
        else if (gDungeon->fixedRoomNumber == FIXED_ROOM_RESCUE_TEAM_MAZE_BOSS) {
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

    if (!IsMonsterRecruitable(targetInfo->id))
        return FALSE;
    if (abs((attacker->pos).x - (target->pos).x) >= 2 || abs((attacker->pos).y - (target->pos).y) >= 2)
        return FALSE;
    if (targetInfo->joinedAt.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
        return FALSE;
    if (targetInfo->monsterBehavior == 1)
        return FALSE;
    if (!CanSeeTarget(target,attacker))
        return FALSE;

    sub_806F910();
    rand = DungeonRandInt(1000);
    recruitRate = GetRecruitRate(targetInfo->id);
    if (recruitRate == -999)
        return FALSE;

    if (HasHeldItem(attacker, ITEM_FRIEND_BOW)) {
        recruitRate += gFriendBowRecruitRateUpValue;
    }
    recruitRate += gRecruitRateByLevel[attackerInfo->level];
    if (rand >= recruitRate)
        return FALSE;

    for (i = 0; i <= (MAX_TEAM_BODY_SIZE - size); i++) {
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
        nullsub_96(attacker, target);
        return FALSE;
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if (!DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[i]))
            break;
    }
    if (i == MAX_TEAM_MEMBERS) {
        nullsub_96(attacker, target);
        return FALSE;
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if (!EntityIsValid(gDungeon->teamPokemon[i]))
            break;
    }
    if (i == MAX_TEAM_MEMBERS) {
        nullsub_96(attacker, target);
        return FALSE;
    }

    return TRUE;
}

static void nullsub_96(Entity *pokemon,Entity *target)
{}

static void sub_806F910(void)
{
    s32 i, j;
    int totalSize;
    s32 unkMaybeTimer;

    totalSize = 0;
    for (i = 0, unkMaybeTimer = 0x40; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            s32 size = GetBodySize(GetEntInfo(entity)->apparentID);
            entity->axObj.unk40_maybeAnimTimer = unkMaybeTimer;
            GetEntInfo(entity)->unk167 = i;
            GetEntInfo(entity)->unk168 = size;
            for (j = 0; j < size; j++) {
                if (totalSize < MAX_TEAM_BODY_SIZE) {
                    gUnknown_202EE70[totalSize] = 1;
                    unkMaybeTimer += 0x10;
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

bool8 IsMonsterRecruitable(s32 species)
{
    s32 id = (s16) species;
    if (!gDungeon->unk644.canRecruit) {
        return FALSE;
    }
    else if (!sub_808529C(id)) {
        return FALSE;
    }
    else if (id == MONSTER_MEW && gDungeon->unk644.unk34 == 1) {
        return FALSE;
    }
    else if (id == MONSTER_LATIAS) {
        return FALSE;
    }
    else if (id == MONSTER_LATIOS) {
        return FALSE;
    }
    else if (id == MONSTER_DEOXYS_ATTACK) {
        return FALSE;
    }
    else if (id == MONSTER_DEOXYS_DEFENSE) {
        return FALSE;
    }
    else if (id == MONSTER_DEOXYS_SPEED) {
        return FALSE;
    }
    else {
        if (GetUnk12(id) == 0) {
            FriendAreaCapacity friendAreaCapacity;
            u8 friendArea = GetFriendArea(id);

            GetFriendAreaCapacity2(friendArea, &friendAreaCapacity, FALSE, FALSE);
            if (friendAreaCapacity.hasFriendArea == FALSE)
                return FALSE;
        }
        return TRUE;
    }
}

bool8 HandleMonsterJoinSequence(Entity *entity1, Entity *entity2, struct unkStruct_8069D4C *param_3)
{
    DungeonMon *dungeonMon;
    int pokeIndex;
    Entity *local_2c;
    s32 i;

    s32 direction = GetDirectionTowardsPosition(&entity2->pos,&entity1->pos);
    bool8 unlockedFriendArea = FALSE;
    u8 friendArea = GetFriendArea(param_3->id);

    entity2->unk22 = 0;
    sub_807A0CC(entity1, entity2);
    sub_806CE68(entity2, direction);
    CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[0],param_3->id);

    if (DisplayDungeonYesNoMessage(0,gUnknown_80F9FE8,1) == 0) {
        if (param_3->id != MONSTER_JIRACHI) {
            LogMessageByIdWithPopupCheckUser(entity1,gText_Pokemon0WentAway);
        }
        return FALSE;
    }

    for (pokeIndex = 0; pokeIndex < MAX_TEAM_MEMBERS; pokeIndex++) {
        if (!(DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[pokeIndex])))
            break;
    }

    if (pokeIndex == MAX_TEAM_MEMBERS) {
        LogMessageByIdWithPopupCheckUser(entity1,gText_ThePokemonCouldntJoinTeam);
        return FALSE;
    }

    if (GetFriendAreaStatus(friendArea) == 0) {
        UnlockFriendArea(friendArea);
        unlockedFriendArea = TRUE;
    }
    HandleFaint(entity2,DUNGEON_EXIT_TRANSFORMED_INTO_FRIEND,entity1);
    dungeonMon = &gRecruitedPokemonRef->dungeonTeam[pokeIndex];
    dungeonMon->flags = POKEMON_FLAG_EXISTS | POKEMON_FLAG_ON_TEAM;
    dungeonMon->isTeamLeader = FALSE;
    dungeonMon->level = param_3->level;
    dungeonMon->IQ = 1;
    SetDefaultIQSkills(&dungeonMon->IQSkills,FALSE);
    dungeonMon->hiddenPower = param_3->hiddenPower;
    dungeonMon->tacticIndex = 0;
    dungeonMon->recruitedPokemonId = -1;
    dungeonMon->unkC = pokeIndex;
    dungeonMon->speciesNum = param_3->id;
    dungeonMon->dungeonLocation = gDungeon->unk644.dungeonLocation;
    dungeonMon->unk10 = param_3->HP;
    dungeonMon->unk12 = param_3->HP;
    dungeonMon->belly = param_3->belly;
    dungeonMon->maxBelly = param_3->maxBelly;

    for (i = 0; i < 2; i++) {
        dungeonMon->offense.att[i] = param_3->att[i];
        dungeonMon->offense.def[i] = param_3->def[i];
    }

    dungeonMon->currExp = param_3->exp;
    dungeonMon->moves = param_3->moves;

    dungeonMon->itemSlot = param_3->heldItem;
    BoundedCopyStringtoBuffer(dungeonMon->name,GetMonSpecies(param_3->id),10);

    IncrementAdventureNumJoined();

    if (SpawnTeamMember(param_3->id,param_3->pos.x,param_3->pos.y,dungeonMon,&local_2c,0,1) == 0) {
        LogMessageByIdWithPopupCheckUser(entity1,gText_ButItCouldntJoinTheTeam);
        dungeonMon->flags = 0;
    }
    else {
        sub_8083D88();
        sub_803E708(0xa0,0x46);
        if (DisplayDungeonYesNoMessage(0,gText_NewMemberJoinedGiveItNickname,TRUE) == 1) {
            while (DungeonGiveNameToRecruitedMon(dungeonMon->name) == 0) {
                DisplayDungeonMessage(0,gText_PleaseGiveNicknameNewMember,TRUE);
            }
        }
        sub_808D9DC(gFormatBuffer_Monsters[0],dungeonMon,0);
        LogMessageByIdWithPopupCheckUser(entity1,gText_Pokemon0JoinedToGoOnAdventures);
        if (unlockedFriendArea) {
            Entity *leader = CutsceneGetLeader();
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
            sub_8092558(gFormatBuffer_FriendArea, friendArea);
            PlaySound(0xce);
            DisplayDungeonMessage(0,gText_Pokemon0GainedAccessToFriendArea,1);
        }
        if (param_3->id == MONSTER_MEW) {
            gDungeon->unk4 = 1;
            gDungeon->unk11 = 3;
        }
    }

    return TRUE;
}

bool8 CanEntityBeRecruited(Entity *param_1)
{
    s32 i, j;

    EntityInfo *info = GetEntInfo(param_1);
    s32 validIndex = -1;
    s32 size = GetBodySize(info->apparentID);
    if (!IsMonsterRecruitable(info->id))
        return FALSE;

    sub_806F910();
    for (i = 0; i <= (MAX_TEAM_BODY_SIZE - size); i++) {
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


    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if (!(DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[i])))
            break;
    }

    if (i == MAX_TEAM_MEMBERS)
        return FALSE;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        if(!EntityIsValid(gDungeon->teamPokemon[i]))
            break;
    }
    if (i == MAX_TEAM_MEMBERS)
        return FALSE;

    return TRUE;
}

bool8 HandleSpecialEntityJoinSequence(Entity *entity1,Entity *entity2,Entity **entityPtr)
{
    u8 friendArea;
    DungeonMon *dungeonMon;
    int index;
    struct unkStruct_8069D4C local_74;
    Entity *local_2c;
    s32 i;
    bool8 unlockedFriendArea = FALSE;

    *entityPtr = NULL;
    sub_8069D4C(&local_74,entity2);
    for (index = 0; index < MAX_TEAM_MEMBERS; index++) {
        if (!DungeonMonExists(&gRecruitedPokemonRef->dungeonTeam[index]))
            break;
    }

    if (index == MAX_TEAM_MEMBERS) {
        return FALSE;
    }

    friendArea = GetFriendArea(local_74.id);
    dungeonMon = &gRecruitedPokemonRef->dungeonTeam[index];
    dungeonMon->flags = POKEMON_FLAG_EXISTS | POKEMON_FLAG_ON_TEAM;
    dungeonMon->isTeamLeader = FALSE;
    dungeonMon->level = local_74.level;
    dungeonMon->IQ = 1;
    SetDefaultIQSkills(&dungeonMon->IQSkills,FALSE);
    dungeonMon->hiddenPower = local_74.hiddenPower;
    dungeonMon->tacticIndex = 0;
    dungeonMon->recruitedPokemonId = -1;
    dungeonMon->unkC = index;
    dungeonMon->speciesNum = local_74.id;
    dungeonMon->dungeonLocation = gDungeon->unk644.dungeonLocation;
    dungeonMon->unk10 = local_74.HP;
    dungeonMon->unk12 = local_74.HP;
    dungeonMon->belly = local_74.belly;
    dungeonMon->maxBelly = local_74.maxBelly;

    for (i = 0; i < 2; i++) {
        dungeonMon->offense.att[i] = local_74.att[i];
        dungeonMon->offense.def[i] = local_74.def[i];
    }

    dungeonMon->currExp = local_74.exp;
    dungeonMon->moves = local_74.moves;
    dungeonMon->itemSlot = local_74.heldItem;
    BoundedCopyStringtoBuffer(dungeonMon->name,GetMonSpecies(local_74.id), POKEMON_NAME_LENGTH);
    if (GetFriendAreaStatus(friendArea) == 0) {
        UnlockFriendArea(friendArea);
        unlockedFriendArea = TRUE;
    }
    IncrementAdventureNumJoined();
    HandleFaint(entity2,DUNGEON_EXIT_TRANSFORMED_INTO_FRIEND,entity1);
    if (SpawnTeamMember(local_74.id,local_74.pos.x,local_74.pos.y,dungeonMon,&local_2c,0,0) == 0) {
        dungeonMon->flags = 0;
    }
    else {
        if (DisplayDungeonYesNoMessage(0,gText_NewMemberJoinedGiveItNickname,TRUE) == 1) {
            while (!DungeonGiveNameToRecruitedMon(dungeonMon->name)) {
                DisplayDungeonMessage(0,gText_PleaseGiveNicknameNewMember,TRUE);
            }
        }
        if (unlockedFriendArea) {
            Entity *leader = CutsceneGetLeader();
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leader,0);
            sub_8092558(gFormatBuffer_FriendArea, friendArea);
            PlaySound(0xce);
            DisplayDungeonMessage(0,gText_Pokemon0GainedAccessToFriendArea,1);
        }
        sub_808D9DC(gFormatBuffer_Monsters[3],dungeonMon,0);
        *entityPtr = local_2c;
    }

    return TRUE;
}
