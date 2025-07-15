#include "global.h"
#include "globaldata.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "structs/dungeon_entity.h"
#include "structs/str_806B7F8.h"
#include "structs/str_dungeon.h"
#include "dungeon_vram.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "dungeon_config.h"
#include "run_dungeon.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_misc.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_message.h"
#include "dungeon_pokemon_sprites.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "file_system.h"
#include "move_effects_target.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "position_util.h"
#include "weather.h"
#include "dungeon_spawns.h"
#include "dungeon_pos_data.h"

extern void sub_8042900(Entity *r0);
extern void sub_8042968(Entity *r0);
extern void EndAbilityImmuneStatus(Entity *, Entity *);
void sub_8041BBC(Entity *r0);
extern bool8 sub_8045888(Entity *);
extern void sub_806A2BC(Entity *, u8);
extern void sub_804178C(u32);
extern void sub_803F508(Entity *);
extern void sub_8042B20(Entity *entity);
extern void sub_8042B0C(Entity *entity);
extern void sub_8072AC8(u16 *param_1, s32 species, s32 param_3);
extern bool8 sub_8083660(const DungeonPos *param_1);
extern Entity *gLeaderPointer;
extern DungeonPos gUnknown_202EE0C;
extern void sub_803F4A0(Entity *a0);
extern bool8 sub_80860A8(u8 id);
extern u8 gUnknown_202F32C;
extern u8 GetRandomFloorItem(s32 a0);
extern void sub_80429E8(Entity *r0);
extern Entity *sub_804550C(s16 a);
extern Entity *sub_80453AC(s16 id);
extern void sub_803F580(s32);
extern void ShowWholeRevealedDungeonMap(void);
extern void sub_806B678(void);
extern void EntityUpdateStatusSprites(Entity *);
extern Entity *sub_80696A8(Entity *a0);
extern s32 GetMonsterApparentID(Entity *pokemon, s32 _id);
extern void sub_806A898(Entity *entity, bool8 r7, bool8 showRunAwayEffect);
extern bool8 sub_806AA0C(s16 _species, bool32 _a1);
extern void sub_806A6E8(Entity *entity);

s32 sub_806C444(s32 species, s32 level);
s32 sub_806C488(s32 species, s32 level, s32 categoryIndex);
s32 sub_806C4D4(s32 species, s32 level, s32 categoryIndex);
bool8 sub_806B8CC(s16 _species, s32 x, s32 y, DungeonMon *monPtr, Entity **a4, bool32 _a5, u32 _a6);
void sub_806BC68(bool8 a0, Entity *entity, struct unkStruct_806B7F8 *structPtr, DungeonPos *pos);
void ResetMonEntityData(EntityInfo *, bool8 a1);
void sub_806C264(s32 teamIndex, EntityInfo *entInfo);

void sub_806AD3C(void)
{
    s32 r10;
    s32 i, j;
    SpawnPokemonData sp[64];
    unkDungeon2F3C *structPtr = gDungeon->unk2F3C;
    s32 var_24 = SetMonsterSpawnsArray(sp, 0);

    for (i = 0; i < var_24; structPtr++, i++) {
        structPtr->species = ExtractSpeciesIndex(&sp[i]);
        structPtr->level = ExtractLevel(&sp[i]);
        sub_8072AC8(structPtr->moves, structPtr->species, structPtr->level);
        if (structPtr->moves[0] == MOVE_NOTHING) {
            structPtr->moves[0] = MOVE_BLOWBACK;
        }
        structPtr->unkC = sub_806C444(structPtr->species, structPtr->level);

        for (j = 0; j < 2; j++) {
            structPtr->unkE[j]  = sub_806C488(structPtr->species, structPtr->level, j);
            structPtr->unk10[j] = sub_806C4D4(structPtr->species, structPtr->level, j);
        }
    }

    for (; i < 64; structPtr++, i++) {
        structPtr->species = 0;
    }

    for (i = 0; i < MONSTER_MAX; i++) {
        gDungeon->expYieldRankings[i] = 0;
    }

    r10 = 1;
    for (i = 0; i < var_24; i++) {
        s32 j;
        s32 expSpecies = -1;
        s32 expGain = -1;

        for (j = 0; j < var_24; j++) {
            s32 species = ExtractSpeciesIndex(&sp[j]);
            if (gDungeon->expYieldRankings[species] == 0) {
                s32 level = ExtractLevel(&sp[j]);
                s32 exp = CalculateEXPGain(species, level);
                if (expGain < exp) {
                    expGain = exp;
                    expSpecies = species;
                }
            }
        }

        if (expSpecies < 0)
            break;

        gDungeon->expYieldRankings[expSpecies] = r10;
        r10 += 2;
    }

    for (i = 0; i < MONSTER_MAX; i++) {
        if (gDungeon->expYieldRankings[i] == 0) {
            gDungeon->expYieldRankings[i] = 1;
        }
    }
}

void sub_806AED8(Moves *moves, s16 *maxHPStat, u8 *atk, u8 *def, s16 _species, s32 level)
{
    s32 i;
    s32 moveCategory;
    s32 species = _species;
    unkDungeon2F3C *structPtr = gDungeon->unk2F3C;

    for (i = 0; i < 64; i++) {
        s16 loopSpecies;

        structPtr = &gDungeon->unk2F3C[i];
        loopSpecies = SpeciesId(structPtr->species);
        if (structPtr->species == 0)
            break;

        if (loopSpecies == species && structPtr->level == level) {
            s32 moveIndex;

            for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
                InitPokemonMoveOrNullObject(&moves->moves[moveIndex], structPtr->moves[moveIndex]);
            }
            *maxHPStat = structPtr->unkC;
            for (moveCategory = 0; moveCategory < 2; moveCategory++) {
                atk[moveCategory] = structPtr->unkE[moveCategory];
                def[moveCategory] = structPtr->unk10[moveCategory];
            }

            moves->struggleMoveFlags = 0;
            return;
        }
    }

    if (i == 64) {
        s32 moveIndex;
        u16 spMoves[MAX_MON_MOVES];

        sub_8072AC8(spMoves, species, level);
        for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
            InitPokemonMoveOrNullObject(&moves->moves[moveIndex], spMoves[moveIndex]);
        }
        *maxHPStat = sub_806C444(species, level);
        for (moveCategory = 0; moveCategory < 2; moveCategory++) {
            atk[moveCategory] = sub_806C488(species, level, moveCategory);
            def[moveCategory] = sub_806C4D4(species, level, moveCategory);
        }


    }
    else {
        s32 moveIndex;

        structPtr->species = species;
        structPtr->level = level;
        sub_8072AC8(structPtr->moves, species, level);
        structPtr->unkC = sub_806C444(structPtr->species, structPtr->level);
        for (moveCategory = 0; moveCategory < 2; moveCategory++) {
            structPtr->unkE[moveCategory]  = sub_806C488(structPtr->species, structPtr->level, moveCategory);
            structPtr->unk10[moveCategory] = sub_806C4D4(structPtr->species, structPtr->level, moveCategory);
        }
        for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
            InitPokemonMoveOrNullObject(&moves->moves[moveIndex], structPtr->moves[moveIndex]);
        }

        *maxHPStat = structPtr->unkC;
        for (moveCategory = 0; moveCategory < 2; moveCategory++) {
            atk[moveCategory] = structPtr->unkE[moveCategory];
            def[moveCategory] = structPtr->unk10[moveCategory];
        }
    }

    moves->struggleMoveFlags = 0;
}

UNUSED static s32 sub_806B09C(SpawnPokemonData *unkPtr, bool8 a1)
{
    s32 i, j;
    s32 count = 0;
    s16 *unk2Field;
    SpawnPokemonData *loopPtr;

    for (i = 0, unk2Field = unkPtr->randNum, loopPtr = unkPtr; i < MAX_TEAM_MEMBERS; i++) {
        DungeonMon *monStructPtr = &gRecruitedPokemonRef->dungeonTeam[i];

        if (DungeonMonExists(monStructPtr) && PokemonFlag2Struct2(monStructPtr))
        {
            for (j = 0; j < count; j++) {
                if (ExtractSpeciesIndex(&unkPtr[j]) == monStructPtr->speciesNum)
                    break;
            }

            if (j == count) {
                SetSpeciesLevelToExtract(loopPtr, 0, monStructPtr->speciesNum);
                unk2Field[0] = 0;
                unk2Field[1] = 0;
                unk2Field += sizeof(*unkPtr) / sizeof(unkPtr->randNum[0]); // Hacky solution, because loopPtr->unk2[0/1] = 0; doesn't match
                loopPtr++;
                count++;
            }
        }
    }

    count = SetMonsterSpawnsArray(unkPtr, count);
    if (a1) {
        SetSpeciesLevelToExtract(&unkPtr[count], 1, MONSTER_DECOY);
        unkPtr[count].randNum[0] = 0;
        unkPtr[count].randNum[1] = 0;
        count++;
    }

    return count;
}

extern const DungeonPos gUnknown_80F4598[];

void sub_806B168(void)
{
    s32 count;
    DungeonMon *monPtrs[MAX_TEAM_MEMBERS];
    DungeonMon *monPtrs2[MAX_TEAM_MEMBERS]; // Leader and partner?
    u8 playerSpawnRoomId = GetTile(gDungeon->playerSpawn.x, gDungeon->playerSpawn.y)->room;
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonMon *currMonPtr = &gRecruitedPokemonRef->dungeonTeam[i];
        currMonPtr->unkC = i;
    }

    // Populate monPtrs
    count = 0;
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonMon *currMonPtr = &gRecruitedPokemonRef->dungeonTeam[i];
        if (DungeonMonExists(currMonPtr) && PokemonFlag2Struct2(currMonPtr)) {
            monPtrs[count++] = currMonPtr;
        }
    }
    for (; count < MAX_TEAM_MEMBERS; count++) {
        monPtrs[count] = NULL;
    }

    // Populate monPtrs2
    count = 0;
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonMon *currMonPtr = monPtrs[i];
        if (currMonPtr != NULL && currMonPtr->isTeamLeader) {
            monPtrs[i] = NULL;
            monPtrs2[count++] = currMonPtr;
        }
    }

    if (gDungeon->unk644.unk18 == 0) {
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            DungeonMon *currMonPtr = monPtrs[i];
            if (currMonPtr != NULL && currMonPtr->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER) {
                monPtrs[i] = NULL;
                monPtrs2[count++] = currMonPtr;
            }
        }
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonMon *currMonPtr = monPtrs[i];
        if (monPtrs[i] != NULL) {
            monPtrs[i] = NULL;
            monPtrs2[count++] = currMonPtr;
        }
    }
    for (; count < MAX_TEAM_MEMBERS; count++) {
        monPtrs2[count] = NULL;
    }

    // Do something else
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonMon *currMonPtr = monPtrs2[i];

        if (currMonPtr != NULL) {
            DungeonPos unkPosition;
            s32 j;
            const Tile *tile;
            bool8 skipSecondLoop;

            if (currMonPtr->speciesNum == MONSTER_CASTFORM_SNOWY || currMonPtr->speciesNum == MONSTER_CASTFORM_RAINY || currMonPtr->speciesNum == MONSTER_CASTFORM_SUNNY) {
                currMonPtr->speciesNum = MONSTER_CASTFORM;
            }

            skipSecondLoop = FALSE;
            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y);
                if (tile->room == playerSpawnRoomId && !sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y, currMonPtr, NULL, TRUE, 0);
                    skipSecondLoop = TRUE;
                    break;
                }
                j++;
            }

            if (skipSecondLoop)
                continue;

            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y);
                if (!sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y, currMonPtr, NULL, TRUE, 0);
                    break;
                }
                j++;
            }
        }
    }

    sub_806B678();
}

void sub_806B404(void)
{
    Entity *leader;
    s32 i;
    DungeonMon *monPtrs[MAX_TEAM_MEMBERS];
    u8 roomId;
    DungeonPos pos;
    s32 count = 0;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonMon *currMonPtr = &gRecruitedPokemonRef->dungeonTeam[i];
        if (DungeonMonExists(currMonPtr) && PokemonFlag2Struct2(currMonPtr) && currMonPtr->recruitedPokemonId == UNK_RECRUITED_POKEMON_ID_55AA) {
            monPtrs[count++] = currMonPtr;
            break;
        }
    }
    for (; count < MAX_TEAM_MEMBERS; count++) {
        monPtrs[count] = NULL;
    }

    gLeaderPointer = NULL;
    leader = GetLeader();
    if (EntityIsValid(leader)) {
        pos.x = leader->pos.x;
        pos.y = leader->pos.y;
    }
    else {
        pos.x = gDungeon->playerSpawn.x;
        pos.y = gDungeon->playerSpawn.y;
    }

    roomId = GetTile(pos.x, pos.y)->room;
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonPos unkPosition;
        bool8 skipNextLoop;
        const Tile *tile;
        s32 j;
        DungeonMon *currMonPtr = monPtrs[i];

        if (currMonPtr != NULL && DungeonMonExists(currMonPtr) && PokemonFlag2Struct2(currMonPtr) && currMonPtr->recruitedPokemonId == UNK_RECRUITED_POKEMON_ID_55AA) {
            currMonPtr->recruitedPokemonId = UNK_RECRUITED_POKEMON_ID_5AA5;
            skipNextLoop = FALSE;
            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + pos.x, unkPosition.y + pos.y);
                if (tile->room == roomId && !sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + pos.x, unkPosition.y + pos.y, currMonPtr, NULL, TRUE, 0);
                    skipNextLoop = TRUE;
                    break;
                }
                j++;
            }

            if (skipNextLoop)
                continue;

            skipNextLoop = FALSE;
            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + pos.x, unkPosition.y + pos.y);
                if (!sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + pos.x, unkPosition.y + pos.y, currMonPtr, NULL, TRUE, 0);
                    skipNextLoop = TRUE;
                    break;
                }
                j++;
            }

            if (skipNextLoop)
                continue;

            for (j = 0; j <= 99; j++) {
                if (sub_8083660(&unkPosition)) {
                    const Tile *tile = GetTile(unkPosition.x, unkPosition.y);
                    if (!sub_807034C(currMonPtr->speciesNum, tile)) {
                        sub_806B8CC(currMonPtr->speciesNum, unkPosition.x, unkPosition.y, currMonPtr, NULL, TRUE, 0);
                        break;
                    }
                }
            }
        }
    }
}

void sub_806B678(void)
{
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *mon = gDungeon->teamPokemon[i];
        if (EntityIsValid(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            if (monInfo->isTeamLeader) {
                sub_803F4A0(mon);
                gUnknown_202EE0C = mon->pos;
                break;
            }
        }
    }
}
/*    s16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    DungeonPos pos;
    u8 unk10;*/

void sub_806B6C4(void)
{
    struct unkStruct_806B7F8 spStruct;
    s32 i, j;
    s32 x, y;
    bool8 r8 = (gDungeon->unk644.unk44 != 0);

    if (sub_80860A8(ITEM_MUSIC_BOX) && !HasRecruitedMon(MONSTER_MEW)) {
        gDungeon->unk37FF = FALSE;
    }
    else {
        gDungeon->unk37FF = TRUE;
    }

    x = DungeonRandInt(DUNGEON_MAX_SIZE_X);
    y = DungeonRandInt(DUNGEON_MAX_SIZE_Y);

    for (j = 0; j < DUNGEON_MAX_SIZE_Y; j++) {
        y++;
        if (y == DUNGEON_MAX_SIZE_Y) {y = 0;}

        for (i = 0; i < DUNGEON_MAX_SIZE_X; i++) {
            x++;
            if (x == DUNGEON_MAX_SIZE_X) {x = 0;}

            if (GetTile(x, y)->spawnOrVisibilityFlags & 8) {
                bool8 r6 = FALSE;

                if (r8) {
                    spStruct.species = gDungeon->unk644.unk44;
                    spStruct.level = 1;
                    spStruct.unk2 = 1;
                    r6 = TRUE;
                }
                else {
                    spStruct.species = GetRandomFloorMonsterId(0);
                    spStruct.level = 0;
                    spStruct.unk2 = 0;
                }

                spStruct.unk4 = 0;
                spStruct.unk10 = 0;
                spStruct.pos.x = x;
                spStruct.pos.y = y;
                if (r6 || sub_806AA0C(spStruct.species, TRUE)) {
                    if (sub_806B7F8(&spStruct, FALSE)) {
                        r8 = FALSE;
                    }
                }
            }
        }
    }

    if (r8) {
        gDungeon->unkA = 1;
    }
}

Entity* sub_806B7F8(struct unkStruct_806B7F8 *structPtr, bool8 a1)
{
    Entity *entity;
    EntityInfo *entityInfo;
    const Tile *tile = GetTile(structPtr->pos.x, structPtr->pos.y);

    if (sub_807034C(structPtr->species, tile))
        return FALSE;

    entity = sub_804550C(structPtr->species);
    if (entity == NULL)
        return FALSE;

    sub_806BC68(FALSE, entity, structPtr, &gUnknown_202EE0C);
    entityInfo = GetEntInfo(entity);
    entityInfo->isNotTeamMember = TRUE;
    sub_806AED8(&entityInfo->moves, &entityInfo->maxHPStat, entityInfo->atk, entityInfo->def, entityInfo->id, entityInfo->level);
    entityInfo->HP = entityInfo->maxHPStat;
    entityInfo->moveRandomly = structPtr->unk4;
    if (!structPtr->unk2 && !a1 && !structPtr->unk10) {
        s32 rand = DungeonRandInt(100);
        if (GetChanceAsleep(structPtr->species) > rand) {
            sub_8075BF4(entity, 0x7F);
            sub_806CE68(entity, NUM_DIRECTIONS);
        }
    }

    return entity;
}

bool8 sub_806B8CC(s16 _species, s32 x, s32 y, DungeonMon *monPtr, Entity **a4, bool32 _a5, u32 _a6)
{
    s32 i;
    DungeonPos unkPosition;
    struct unkStruct_806B7F8 spStruct;
    // s16 memes
    s32 species = SpeciesId(_species);
    bool8 a5 = _a5;
    u8 a6 = _a6;

    Entity *entity;
    EntityInfo *entityInfo;
    bool8 isTeamLeader = (monPtr->isTeamLeader != FALSE);

    if (a4 != NULL) {
        *a4 = NULL;
    }

    if (GetBaseSpecies(species) == MONSTER_DEOXYS_NORMAL) {
        if (a5) {
            species = gDungeon->deoxysForm;
        }
        else {
            species = MONSTER_DEOXYS_NORMAL;
        }
    }

    if (sub_807034C(species, GetTile(x, y)))
        return FALSE;

    entity = sub_80453AC(species);
    if (entity == NULL)
        return FALSE;

    spStruct.pos.x = x;
    spStruct.pos.y = y;
    spStruct.species = species;
    spStruct.level = monPtr->level;
    spStruct.unk2 = 0;
    spStruct.unk4 = 0;
    spStruct.unk10 = 0;

    unkPosition.x = gAdjacentTileOffsets[gUnknown_202F32C].x + x;
    unkPosition.y = gAdjacentTileOffsets[gUnknown_202F32C].y + y;
    sub_806BC68(TRUE, entity, &spStruct, (isTeamLeader ? &unkPosition : &gUnknown_202EE0C));

    entityInfo = GetEntInfo(entity);
    entityInfo->isNotTeamMember = FALSE;
    entityInfo->shopkeeper = 0;
    entityInfo->isTeamLeader = isTeamLeader;
    entityInfo->unkF9 = a6;

    gLeaderPointer = NULL;
    if (isTeamLeader) {
        gUnknown_202EE0C.x = x;
        gUnknown_202EE0C.y = y;
    }

    entityInfo->HP = monPtr->unk10;
    entityInfo->maxHPStat = monPtr->unk12;
    entityInfo->exp = monPtr->currExp;

    for (i = 0; i < 2; i++) {
        entityInfo->atk[i] = monPtr->offense.att[i];
        entityInfo->def[i] = monPtr->offense.def[i];
    }

    entityInfo->moves = monPtr->moves;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entityInfo->moves.moves[i];
        if (MoveFlagExists(move)) {
            move->moveFlags &= ~(MOVE_FLAG_LAST_USED);
            move->moveFlags &= ~(MOVE_FLAG_REPLACE);
        }
    }
    entityInfo->moves.struggleMoveFlags &= ~(MOVE_FLAG_LAST_USED);
    entityInfo->moves.struggleMoveFlags &= ~(MOVE_FLAG_REPLACE);

    entityInfo->level = monPtr->level;
    entityInfo->IQ = monPtr->IQ;
    entityInfo->tactic = monPtr->tacticIndex;
    entityInfo->IQSkillMenuFlags = monPtr->IQSkills;
    entityInfo->hiddenPower = monPtr->hiddenPower;
    entityInfo->joinedAt = monPtr->dungeonLocation;
    entityInfo->belly = monPtr->belly;
    entityInfo->maxBelly = monPtr->maxBelly;
    entityInfo->teamIndex = monPtr->unkC;
    entityInfo->heldItem = monPtr->itemSlot;
    entityInfo->unkF3 = 0;
    entityInfo->unk64 = 0;

    // Pickup Check
    if (gDungeon->unk644.dungeonLocation.id != DUNGEON_TINY_WOODS
        && !IsBossFight()
        && (entityInfo->abilities[0] == ABILITY_PICKUP || entityInfo->abilities[1] == ABILITY_PICKUP)
        && !ItemExists(&entityInfo->heldItem))
    {
        u32 pickUpItem = GetRandomFloorItem(0);
        if (pickUpItem != ITEM_POKE) {
            ItemIdToItem(&entityInfo->heldItem, pickUpItem, 0);
            entityInfo->unkF3 = TRUE;
        }
    }

    sub_806A6E8(entity);
    LoadIQSkills(entity);
    if (a4) {
        *a4 = entity;
    }

    return TRUE;
}

void sub_806BB6C(Entity *entity, s32 _species)
{
    s32 species = (s16) _species;
    s16 speciesMatch;
    struct unkStruct_806B7F8 spStruct;
    EntityInfo *entInfo = GetEntInfo(entity);

    DeletePokemonDungeonSprite(entInfo->dungeonSpriteId);
    // s16 memes...
    spStruct.species = 0;
    speciesMatch = species;
    ASM_MATCH_TRICK(species);
    spStruct.species = speciesMatch;

    spStruct.level = 0;
    spStruct.unk2 = 0;
    spStruct.pos = entity->pos;
    spStruct.unk4 = 0;
{
    s16 apparentSpeciesMatch;
    s32 apparentSpecies = (s16) (GetMonsterApparentID(NULL, species));
    UNUSED EntityInfo *entInfo;

    entity->unk22 = 0;
    entInfo = GetEntInfo(entity);
    apparentSpeciesMatch = apparentSpecies;
    GetEntInfo(entity)->apparentID = (s16) (apparentSpeciesMatch);
    GetEntInfo(entity)->id =  speciesMatch;
    entity->axObj.spriteFile = GetSpriteData(apparentSpecies);
}

    entity->axObj.unk42_animId1 = 7;
    entity->axObj.unk44_direction1 = 0;
    entity->axObj.unk43_animId2 = 0xFF;
    entity->axObj.unk45_orientation = 1;
    entity->axObj.unk47 = 1;
    entity->unk1C = IntToF248_2(0);

    if (entInfo->frozenClassStatus.status == STATUS_WRAP || entInfo->frozenClassStatus.status == STATUS_WRAPPED) {
        sub_8076CB4(entInfo->unk9C);
    }

    sub_806BC68((entInfo->isNotTeamMember == FALSE), entity, &spStruct, NULL);
    sub_806AED8(&entInfo->moves, &entInfo->maxHPStat, entInfo->atk, entInfo->def, entInfo->id, entInfo->level);
    entInfo->HP = entInfo->maxHPStat;
    entInfo->shopkeeper = 0;
    sub_80429E8(entity);
    EntityUpdateStatusSprites(entity);
}

void sub_806BC68(bool8 a0, Entity *entity, struct unkStruct_806B7F8 *structPtr, DungeonPos *pos)
{
    DungeonPos entityPos;
    EntityInfo *entInfo;

    gDungeon->unkC = 1;
    entInfo = GetEntInfo(entity);
    ResetMonEntityData(entInfo, TRUE);
    entInfo->monsterBehavior = structPtr->unk2;
    entity->isVisible = TRUE;
    entity->unk22 = 0;
    entity->prevPos.x = -1;
    entity->prevPos.y = -1;
    entity->pos.x = -2;
    entity->pos.y = -2;

    sub_80694C0(entity, structPtr->pos.x, structPtr->pos.y, 1);
    sub_804535C(entity, NULL);

    if (!a0) {
        if (structPtr->species == MONSTER_KECLEON
            && !gDungeon->unk644.unk2A
            && gDungeon->unk3A0A
            && !structPtr->unk2)
        {
            entInfo->shopkeeper = 1;
        }
        else {
            entInfo->shopkeeper = 0;
        }

        if (GetBaseSpecies(entInfo->id) == MONSTER_DEOXYS_NORMAL) {
            gDungeon->unk37FD = TRUE;
        }
        if (GetBaseSpecies(entInfo->id) == MONSTER_MEW) {
            gDungeon->unk37FF = TRUE;
        }
    }

    entInfo->dungeonSpriteId = gDungeon->unk37F0;
    gDungeon->unk37F0++;
    entInfo->unk9C = 0;
    if (structPtr->level == 0) {
        entInfo->level = GetSpawnedMonsterLevel(structPtr->species);
    }
    else {
        entInfo->level = structPtr->level;
    }

    entInfo->moveRandomly = structPtr->unk4;
    entInfo->IQ = 1;
    SetDefaultIQSkills(&entInfo->IQSkillMenuFlags, FALSE);
    GenerateHiddenPower(&entInfo->hiddenPower);
    entInfo->maxHPStat = 1;
    entInfo->HP = 1;
    entInfo->belly = IntToFixedPoint(100);
    entInfo->maxBelly = IntToFixedPoint(100);

    if (pos != NULL) {
        entInfo->targetPos = *pos;
    }
    else {
        entInfo->targetPos.x = 0;
        entInfo->targetPos.y = 0;
    }

    entInfo->flags = 0;
    entInfo->aiAllySkip = FALSE;
    entInfo->recalculateFollow = FALSE;
    entInfo->numMoveTiles = 0;
    entInfo->notMoving = 0;
    entInfo->aiTarget.aiObjective = 0;
    entInfo->aiTarget.aiTargetPos = entity->pos;
    entInfo->aiTarget.aiTarget = NULL;
    entInfo->aiTarget.unkC = 0;
    entInfo->aiTarget.aiTargetSpawnGenID = 0;
    entInfo->unkFF = 0;
    entInfo->unk174.raw = 0;
    entInfo->decoyAITracker = 0;
    ResetMonEntityData(entInfo, TRUE);
    ZeroOutItem(&entInfo->heldItem);
    entInfo->unk64 = 0;
    entInfo->statusIcons = 0;
    entInfo->unk164 = 0xFF;
    entInfo->unk165 = 0xFF;
    entInfo->expGainedInTurn = 0;
    entInfo->waiting = 0;
    entInfo->unk146 = 0;
    entInfo->unk166 = 0;
    entInfo->unk1F8 = 0;
    entInfo->mobileTurnTimer = 0;
    entInfo->attacking = FALSE;
    entInfo->unk149 = FALSE;
    entInfo->abilityEffectFlags = FALSE;
    entInfo->terrifiedTurns = 0;
    entInfo->useHeldItem = 0;
    entInfo->unk14B = 0;
    entInfo->unk14C = 1;
    entInfo->visualFlags = 0;
    entInfo->previousVisualFlags = 0;
    entInfo->unk152 = 0;
    entInfo->unk153 = 0;
    entInfo->unk154 = 0;
    entInfo->unk155 = 0;
    entInfo->turnsSinceWarpScarfActivation = 0;
    entInfo->perishSongTurns = 0;
    entInfo->unkFE = 99;
    entInfo->unk158 = 0;
    entInfo->unk159 = 0;
    entInfo->unk15A = 0;
    CalcSpeedStage(entity);
    entInfo->unk156 = 1;
    entInfo->unk15C = 0;
    entInfo->unk15E = 0;
    entInfo->unk15D = 0;
    entInfo->unk15F = 0;
    entInfo->unk160 = 0;
    if (entInfo->apparentID == MONSTER_DIGLETT || entInfo->apparentID == MONSTER_DUGTRIO) {
        entInfo->unk156 = 0;
    }

    entityPos.x = entity->pos.x;
    entityPos.y = entity->pos.y;
    AddPokemonDungeonSprite(entInfo->dungeonSpriteId, entInfo->apparentID, &entityPos, gDungeon->unk181e8.priority);
    LoadIQSkills(entity);
    sub_806A898(entity, FALSE, FALSE);
}

void ResetMonEntityData(EntityInfo *entInfo, bool8 setStatsToOne)
{
    s32 i;
    bool8 hasForecast;

    entInfo->sleepClassStatus.status = 0;
    entInfo->sleepClassStatus.turns = 0;
    entInfo->burnClassStatus.status = 0;
    entInfo->burnClassStatus.turns = 0;
    entInfo->burnClassStatus.damageCountdown = 0;
    entInfo->burnClassStatus.badlyPoisonedDamageCount = 0;
    entInfo->frozenClassStatus.status = 0;
    entInfo->frozenClassStatus.turns = 0;
    entInfo->frozenClassStatus.damageCountdown = 0;
    entInfo->frozenClassStatus.unk4 = 34;
    entInfo->cringeClassStatus.status = 0;
    entInfo->cringeClassStatus.turns = 0;
    entInfo->bideClassStatus.status = 0;
    entInfo->reflectClassStatus.status = 0;
    entInfo->reflectClassStatus.turns = 0;
    entInfo->curseClassStatus.status = 0;
    entInfo->curseClassStatus.turns = 0;
    entInfo->curseClassStatus.damageCountdown = 0;
    entInfo->leechSeedClassStatus.status = 0;
    entInfo->leechSeedClassStatus.turns = 0;
    entInfo->leechSeedClassStatus.damageCountdown = 0;
    entInfo->sureShotClassStatus.status = 0;
    entInfo->sureShotClassStatus.turns = 0;
    entInfo->longTossClassStatus.status = 0;
    entInfo->invisibleClassStatus.status = 0;
    entInfo->invisibleClassStatus.turns = 0;
    entInfo->blinkerClassStatus.status = 0;
    entInfo->blinkerClassStatus.turns = 0;
    entInfo->muzzled.muzzled = FALSE;
    entInfo->muzzled.turns = 0;
    entInfo->powerEars = FALSE;
    entInfo->scanning = FALSE;
    entInfo->stairSpotter = FALSE;
    entInfo->stairSpotter = FALSE;
    entInfo->unk164 = 0xFF;
    entInfo->unk165 = 0xFF;

    for (i = 0; i < NUM_SPEED_COUNTERS; i++) {
        entInfo->speedUpCounters[i] = 0;
        entInfo->speedDownCounters[i] = 0;
    }

    hasForecast = FALSE;
    for (i = 0; i < 2; i++) {
        entInfo->abilities[i] = GetPokemonAbility(entInfo->id, i);
        if (entInfo->abilities[i] == ABILITY_FORECAST) {
            hasForecast = TRUE;
        }
        if (setStatsToOne) {
            entInfo->atk[i] = 1;
            entInfo->def[i] = 1;
        }

        entInfo->offensiveStages[i] = 10;
        entInfo->defensiveStages[i] = 10;
        entInfo->hitChanceStages[i] = 10;
        entInfo->offensiveMultipliers[i].raw = IntToF248_2(1).raw;
        entInfo->defensiveMultipliers[i].raw = IntToF248_2(1).raw;
    }

    if (hasForecast) {
        entInfo->types[0] = gCastformByWeather[GetApparentWeather(NULL)].type;
        entInfo->types[1] = TYPE_NONE;
    }
    else {
        for (i = 0; i < 2; i++) {
            entInfo->types[i] = GetPokemonType(entInfo->id, i);
        }
    }

    gDungeon->unkC = 1;
    entInfo->flashFireBoost = 0;
    entInfo->stockpileStage = 0;
    entInfo->perishSongTurns = 0;
    entInfo->speedBoostFrames = 0;
    entInfo->grudge = 0;
    entInfo->expMultiplier = EXP_HALVED;
    entInfo->exposed = FALSE;
    entInfo->isColorChanged = 0;
    entInfo->bossFlag = 0;
    entInfo->unkFF = 0;
}

void sub_806C1D8(void)
{
    s32 i, j;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            EntityInfo *entInfo = GetEntInfo(entity);
            s32 teamIndex = entInfo->teamIndex;
            if (teamIndex >= 0) {
                for (j = 0; j < MAX_MON_MOVES; j++) {
                    if (MoveFlagExists(&entInfo->moves.moves[j])) {
                        entInfo->moves.moves[j].moveFlags2 &= ~(1);
                    }
                }
                sub_806C264(teamIndex, entInfo);
            }
        }
    }
}

void sub_806C264(s32 teamIndex, EntityInfo *entInfo)
{
    s32 i;
    DungeonMon *monPtr = &gRecruitedPokemonRef->dungeonTeam[teamIndex];

    monPtr->unk10 = entInfo->HP;
    monPtr->unk12 = entInfo->maxHPStat;
    monPtr->currExp = entInfo->exp;
    for (i = 0; i < 2; i++) {
        monPtr->offense.att[i] = entInfo->atk[i];
        monPtr->offense.def[i] = entInfo->def[i];
    }

    if (IS_CASTFORM_FORM_MONSTER(entInfo->apparentID)) {
        monPtr->speciesNum = MONSTER_CASTFORM;
    }

    monPtr->moves = entInfo->moves;
    monPtr->level = entInfo->level;
    monPtr->IQ = entInfo->IQ;
    monPtr->IQSkills = entInfo->IQSkillMenuFlags;
    monPtr->tacticIndex = entInfo->tactic;
    monPtr->hiddenPower = entInfo->hiddenPower;
    monPtr->belly = entInfo->belly;
    monPtr->maxBelly = entInfo->maxBelly;
    monPtr->itemSlot = entInfo->heldItem;
    if (monPtr->recruitedPokemonId == UNK_RECRUITED_POKEMON_ID_55AA) {
        monPtr->recruitedPokemonId = UNK_RECRUITED_POKEMON_ID_5AA5;
    }
}

// s16 species memes again
void sub_806C330(s32 _x, s32 _y, s16 _species, u32 _a3)
{
    s32 i;
    s32 x = _x;
    s32 y = _y;
    s32 species = (_species);
    u8 a3 = _a3;
    unkDungeon57C *strPtr = &gDungeon->unk57C;

    for (i = 0; i < strPtr->unk40; i++) {
        if (strPtr->unkArray[i].unk3 && strPtr->unkArray[i].unk4 == x && strPtr->unkArray[i].unk5 == y) {
            s16 speciesMatchMe = SpeciesId(_species);
            strPtr->unkArray[i].unk0 = speciesMatchMe;
            strPtr->unkArray[i].unk2 = a3;
            return;
        }
    }

    if (strPtr->unk40 < UNK_DUNGEON57C_ARRAY_COUNT) {
        strPtr->unkArray[strPtr->unk40].unk3 = TRUE;
        strPtr->unkArray[strPtr->unk40].unk4 = x;
        strPtr->unkArray[strPtr->unk40].unk5 = y;
        strPtr->unkArray[strPtr->unk40].unk0 = species;
        strPtr->unkArray[strPtr->unk40].unk2 = a3;

        strPtr->unk40++;
    }
}

void sub_806C3C0(void)
{
    s32 i;
    struct unkStruct_806B7F8 spStruct;
    unkDungeon57C *strPtr = &gDungeon->unk57C;

    for (i = 0; i < strPtr->unk40; i++) {
        if (strPtr->unkArray[i].unk3) {
            spStruct.species = strPtr->unkArray[i].unk0;
            spStruct.level = 0;
            spStruct.pos.x = strPtr->unkArray[i].unk4;
            spStruct.pos.y = strPtr->unkArray[i].unk5;
            spStruct.unk2 = strPtr->unkArray[i].unk2;
            spStruct.unk4 = 0;
            spStruct.unk10 = 0;
            sub_806B7F8(&spStruct, TRUE);
        }
    }
}

void sub_806C42C(void)
{
    unkDungeon57C *strPtr = &gDungeon->unk57C;
    strPtr->unk40 = 0;
}

s32 sub_806C444(s32 _species, s32 level)
{
    LevelData levelData;
    s32 i;
    s32 species = SpeciesId(_species);
    s32 hpCount = GetBaseHP(species);

    for (i = 2; i <= level; i++) {
        GetPokemonLevelData(&levelData, species, i);
        hpCount += levelData.gainHP;
    }

    return hpCount;
}

s32 sub_806C488(s32 _species, s32 level, s32 categoryIndex)
{
    LevelData levelData;
    s32 i;
    s32 species = SpeciesId(_species);
    s32 offensiveCount = GetBaseOffensiveStat(species, categoryIndex);

    for (i = 2; i <= level; i++) {
        GetPokemonLevelData(&levelData, species, i);
        offensiveCount += levelData.gainAtt[categoryIndex];
    }

    return offensiveCount;
}

s32 sub_806C4D4(s32 _species, s32 level, s32 categoryIndex)
{
    LevelData levelData;
    s32 i;
    s32 species = SpeciesId(_species);
    s32 defensiveCount = GetBaseDefensiveStat(species, categoryIndex);

    for (i = 2; i <= level; i++) {
        GetPokemonLevelData(&levelData, species, i);
        defensiveCount += levelData.gainDef[categoryIndex];
    }

    return defensiveCount;
}
