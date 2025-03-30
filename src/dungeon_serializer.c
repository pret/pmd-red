#include "global.h"
#include "globaldata.h"
#include "structs/str_dungeon.h"
#include "code_800F958.h"
#include "code_8045A00.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_serializer.h"
#include "dungeon_util.h"
#include "pokemon.h"

extern u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE];
extern u8 gUnknown_202EE76[DUNGEON_MAX_WILD_POKEMON_BODY_SIZE];

extern DungeonPos gPlayerDotMapPosition;
extern Entity *gLeaderPointer; // 203B450

#include "data/dungeon_serializer.h"

static void InitReader(DataSerializer *seri, u8 *buffer, u32 bufLen);
static void InitWriter(DataSerializer *seri, u8 *buffer, u32 bufLen);
static void FinishSerializer(DataSerializer *seri);

static u8 ReadAbility(DataSerializer *seri);
static void ReadActionContainer(DataSerializer *seri, ActionContainer *dst);
static void ReadAITarget(DataSerializer *seri, AITarget *dst);
static void ReadBelly(DataSerializer *seri, FixedPoint *dst);
static void ReadBlame(DataSerializer *seri, const u8 *expected);
static bool8 ReadBool8(DataSerializer *seri);
static void ReadBytes(DataSerializer *seri, void *dst, s32 numBytes);
static void ReadBideClassStatus(DataSerializer *seri, BideClassStatus *dst);
static u8 ReadMonsterBehavior(DataSerializer *seri);
static void ReadDungeonFloor(DataSerializer *seri);
static void ReadDungeonItems(DataSerializer *seri);
static void ReadDungeonMonsters(DataSerializer *seri);
static void ReadDungeonMusic(DataSerializer *seri);
static void ReadDungeonTraps(DataSerializer *seri);
static void ReadDungeonUnk644(DataSerializer *seri);
static void ReadDungeonkecleonShopPos(DataSerializer *seri, struct MinMaxPosition *dst);
static void ReadDungeonUnkE260(DataSerializer *seri, unkDungeonE260 *dst);
static void ReadDungeonVisibility(DataSerializer *seri);
static void ReadBlinkerClassStatus(DataSerializer *seri, BlinkerClassStatus *dst);
static s24_8 ReadF24_8(DataSerializer *seri);
static void ReadHiddenPower(DataSerializer *seri, HiddenPower *dst);
static void ReadFrozenClassStatus(DataSerializer *seri, FrozenClassStatus *dst);
static void ReadIQSkills(DataSerializer *seri, IqSkillFlags *dst);
static void ReadItem(DataSerializer *seri, Item *dst);
static void ReadLongTossClassStatus(DataSerializer *seri, LongTossClassStatus *dst);
static void ReadDungeonLocation(DataSerializer *seri, DungeonLocation *dst);
static void ReadLeechSeedClassStatus(DataSerializer *seri, LeechSeedClassStatus *dst);
static void ReadMonster(DataSerializer *seri, bool8 isTeamMember, s32 index);
static s16 ReadMonsterID(DataSerializer *seri);
static u8 ReadMonsterUnk64(DataSerializer *seri);
static u8 ReadMonsterUnkFF(DataSerializer *seri);
static void ReadMoves(DataSerializer *seri, Moves *dst);
static void ReadSureShotClassStatus(DataSerializer *seri, SureShotClassStatus *dst);
static void ReadMuzzled(DataSerializer *seri, Muzzled *dst);
static void ReadBurnClassStatus(DataSerializer *seri, BurnClassStatus *dst);
static void ReadReflectClassStatus(DataSerializer *seri, ReflectClassStatus *dst);
static s16 ReadS16(DataSerializer *seri);
static void ReadSleepClassStatus(DataSerializer *seri, SleepClassStatus *dst);
static void ReadSpeedCounters(DataSerializer *seri, u8 *dst, u32 numCounters);
static s32 ReadSpeedStage(DataSerializer *seri);
static u8 ReadTactic(DataSerializer *seri);
static u8 ReadDecoyAITracker(DataSerializer *seri);
static void ReadTile(DataSerializer *seri, Tile *dst);
static void ReadTilePos(DataSerializer *seri, DungeonPos *dst);
static void ReadInvisibleClassStatus(DataSerializer *seri, InvisibleClassStatus *dst);
static u8 ReadType(DataSerializer *seri);
static u16 ReadU16(DataSerializer *seri);
static u32 ReadU32(DataSerializer *seri);
static u8 ReadU8(DataSerializer *seri);
static void ReadCringeClassStatus(DataSerializer *seri, CringeClassStatus *dst);
static void ReadCurseClassStatus(DataSerializer *seri, CurseClassStatus *dst);
static void ReadWeather(DataSerializer *seri, Weather *dst);

static void WriteAbility(DataSerializer *seri, u8 value);
static void WriteActionContainer(DataSerializer *seri, ActionContainer *src);
static void WriteAITarget(DataSerializer *seri, AITarget* src);
static void WriteBelly(DataSerializer *seri, FixedPoint *src);
static void WriteBlame(DataSerializer *seri, const u8 *blame);
static void WriteBool8(DataSerializer *seri, bool8 value);
static void WriteBytes(DataSerializer *seri, void *src, s32 numBytes);
static void WriteBideClassStatus(DataSerializer *seri, BideClassStatus *src);
static void WriteMonsterBehavior(DataSerializer *seri, u8 value);
static void WriteDungeonFloor(DataSerializer *seri);
static void WriteDungeonItems(DataSerializer *seri);
static void WriteDungeonMonsters(DataSerializer *seri);
static void WriteDungeonMusic(DataSerializer *seri);
static void WriteDungeonTraps(DataSerializer *seri);
static void WriteDungeonUnk644(DataSerializer *seri);
static void WriteDungeonkecleonShopPos(DataSerializer *seri, struct MinMaxPosition *src);
static void WriteDungeonUnkE260(DataSerializer *seri, unkDungeonE260 *src);
static void WriteDungeonVisibility(DataSerializer *seri);
static void WriteBlinkerClassStatus(DataSerializer *seri, BlinkerClassStatus *src);
static void WriteF24_8(DataSerializer *seri, s24_8 value);
static void WriteHiddenPower(DataSerializer *seri, HiddenPower *src);
static void WriteFrozenClassStatus(DataSerializer *seri, FrozenClassStatus *src);
static void WriteIQSkills(DataSerializer *seri, IqSkillFlags *src);
static void WriteItem(DataSerializer *seri, Item *src);
static void WriteLongTossClassStatus(DataSerializer *seri, LongTossClassStatus *src);
static void WriteDungeonLocation(DataSerializer *seri, DungeonLocation *src);
static void WriteLeechSeedClassStatus(DataSerializer *seri, LeechSeedClassStatus *src);
static void WriteMonster(DataSerializer *seri, Entity *src);
static void WriteMonsterID(DataSerializer *seri, s16 value);
static void WriteMonsterUnk64(DataSerializer *seri, u8 value);
static void WriteMonsterUnkFF(DataSerializer *seri, u8 value);
static void WriteMoves(DataSerializer *seri, Moves *src);
static void WriteSureShotClassStatus(DataSerializer *seri, SureShotClassStatus* src);
static void WriteMuzzled(DataSerializer *seri, Muzzled *src);
static void WriteBurnClassStatus(DataSerializer *seri, BurnClassStatus *src);
static void WriteReflectClassStatus(DataSerializer *seri, ReflectClassStatus *src);
static void WriteTilePos(DataSerializer *seri, DungeonPos *src);
static void WriteS16(DataSerializer *seri, s16 value);
static void WriteSleepClassStatus(DataSerializer *seri, SleepClassStatus* src);
static void WriteSpeedCounters(DataSerializer *seri, u8 *src, u32 numCounters);
static void WriteSpeedStage(DataSerializer *seri, s32 value);
static void WriteTactic(DataSerializer *seri, u8 value);
static void WriteDecoyAITracker(DataSerializer *seri, u8 value);
static void WriteTile(DataSerializer *seri, Tile *src);
static void WriteInvisibleClassStatus(DataSerializer *seri, InvisibleClassStatus *src);
static void WriteType(DataSerializer *seri, u8 value);
static void WriteU16(DataSerializer *seri, u16 value);
static void WriteU32(DataSerializer *seri, u32 value);
static void WriteU8(DataSerializer *seri, u8 value);
static void WriteCringeClassStatus(DataSerializer *seri, CringeClassStatus *src);
static void WriteCurseClassStatus(DataSerializer *seri, CurseClassStatus *src);
static void WriteWeather(DataSerializer *seri, Weather *src);

static Entity* sub_80828E0(s16 id, s16 apparentID, s32 index);
static Entity* sub_8082A08(s32 id, s32 apparentID, s32 index);

void SaveDungeonState(u8 *buffer, u32 bufLen)
{
    DataSerializer seri;

    InitWriter(&seri, buffer, bufLen);

    seri.unkC = 0;
    WriteBytes(&seri, &seri.unkC, 4);

    WriteDungeonUnk644(&seri);
    WriteDungeonFloor(&seri);
    WriteDungeonVisibility(&seri);
    WriteDungeonMusic(&seri);
    WriteDungeonItems(&seri);
    WriteDungeonTraps(&seri);
    WriteDungeonMonsters(&seri);

    WriteBlame(&seri, sYayoiSan);
    FinishSerializer(&seri);
}

static void WriteDungeonUnk644(DataSerializer *seri)
{
    WriteBlame(seri, sMisakiSan);
    WriteBytes(seri, &gDungeon->unk644, sizeof(unkDungeon644));
}

static void WriteDungeonItems(DataSerializer *seri)
{
    bool8 notEmpty;
    Item *item;
    Entity *entity;
    s32 i;
    u8 emptyItem[5];

    for (i = 0; i < 5; i++)
        emptyItem[i] = 0;

    WriteBlame(seri, sMisakiSan);

    for (i = 0; i < DUNGEON_MAX_ITEMS; i++) {
        entity = gDungeon->items[i];
        notEmpty = FALSE;

        if (entity != NULL && GetEntityType(entity) == ENTITY_ITEM) {
            item = GetItemData(entity);
            WriteItem(seri, item); // 3 bytes
            WriteBytes(seri, &entity->pos.x, 1); // 1 byte
            WriteBytes(seri, &entity->pos.y, 1); // 1 byte
            notEmpty = TRUE;
        }

        if (!notEmpty)
            WriteBytes(seri, emptyItem, 5);
    }
}

static void WriteDungeonTraps(DataSerializer *seri)
{
    bool8 notEmpty;
    Trap *trap;
    Entity *entity;
    s32 i;
    u8 emptyTrap[5];

    for (i = 0; i < 5; i++)
        emptyTrap[i] = -1;

    WriteBlame(seri, sMisakiSan);

    for (i = 0; i < DUNGEON_MAX_TRAPS; i++) {
        entity = gDungeon->traps[i];
        notEmpty = FALSE;

        if (entity != NULL && GetEntityType(entity) == ENTITY_TRAP) {
            trap = GetTrapData(entity);
            WriteBytes(seri, &trap->id, 1);
            WriteBytes(seri, &trap->unk1, 1);
            WriteBytes(seri, &entity->isVisible, 1);
            WriteBytes(seri, &entity->pos.x, 1);
            WriteBytes(seri, &entity->pos.y, 1);
            notEmpty = TRUE;
        }

        if (!notEmpty)
            WriteBytes(seri, emptyTrap, 5);
    }
}

static void WriteDungeonMonsters(DataSerializer *seri)
{
    s32 i;

    WriteBlame(seri, sMisakiSan);
    WriteU32(seri, gDungeon->unk37F0);
    WriteU32(seri, gDungeon->unk37F4);
    WriteBool8(seri, gDungeon->plusIsActive[0]);
    WriteBool8(seri, gDungeon->plusIsActive[1]);
    WriteBool8(seri, gDungeon->minusIsActive[0]);
    WriteBool8(seri, gDungeon->minusIsActive[1]);
    WriteBool8(seri, gDungeon->decoyIsActive);
    WriteBool8(seri, gDungeon->unk37FD);
    WriteBool8(seri, gDungeon->deoxysDefeat);
    WriteBool8(seri, gDungeon->unk37FF);
    WriteU16(seri, gDungeon->deoxysForm); // Should be S16

    for (i = 0; i < MAX_TEAM_MEMBERS; i++)
        WriteMonster(seri, gDungeon->teamPokemon[i]);

    for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++)
        WriteMonster(seri, gDungeon->wildPokemon[i]);
}

static void WriteMonster(DataSerializer *seri, Entity *src)
{
    EntityInfo *info;
    s32 i;
    EntityInfo blankInfo;
    u32 one;
    u32 zero;

    zero = 0;
    one = 1;

    WriteU8(seri, 0xAA);
    WriteU8(seri, 0x55);

    if (EntityIsValid(src)) {
        info = GetEntInfo(src);
        WriteBytes(seri, &one, 1);
        WriteBytes(seri, &src->pos.x, 1);
        WriteBytes(seri, &src->pos.y, 1);
        WriteBytes(seri, &src->isVisible, 1);
        WriteBytes(seri, &src->spawnGenID, 2);
    }
    else {
        memset(&blankInfo, 0, sizeof(EntityInfo));

        info = &blankInfo;
        WriteBytes(seri, &zero, 1);
        WriteBytes(seri, &zero, 1);
        WriteBytes(seri, &zero, 1);
        WriteBytes(seri, &zero, 1);
        WriteBytes(seri, &zero, 2);
    }

    WriteU16(seri, info->flags);
    WriteMonsterID(seri, info->apparentID);
    WriteMonsterID(seri, info->id);
    WriteBool8(seri, info->isNotTeamMember);
    WriteBool8(seri, info->isTeamLeader);
    WriteU8(seri, info->shopkeeper);
    WriteU8(seri, info->level);
    WriteU8(seri, info->teamIndex);
    WriteDungeonLocation(seri, &info->joinedAt);
    WriteS16(seri, info->IQ);
    WriteS16(seri, info->HP);
    WriteS16(seri, info->maxHPStat);
    WriteS16(seri, info->originalHP);
    WriteU8(seri, info->atk[0]);
    WriteU8(seri, info->atk[1]);
    WriteU8(seri, info->def[0]);
    WriteU8(seri, info->def[1]);
    WriteU32(seri, info->exp);
    WriteS16(seri, info->offensiveStages[0]);
    WriteS16(seri, info->offensiveStages[1]);
    WriteS16(seri, info->defensiveStages[0]);
    WriteS16(seri, info->defensiveStages[1]);
    WriteS16(seri, info->hitChanceStages[0]);
    WriteS16(seri, info->hitChanceStages[1]);
    WriteS16(seri, info->flashFireBoost);
    WriteF24_8(seri, info->offensiveMultipliers[0]);
    WriteF24_8(seri, info->offensiveMultipliers[1]);
    WriteF24_8(seri, info->defensiveMultipliers[0]);
    WriteF24_8(seri, info->defensiveMultipliers[1]);
    WriteActionContainer(seri, &info->action);
    WriteType(seri, info->types[0]);
    WriteType(seri, info->types[1]);
    WriteAbility(seri, info->abilities[0]);
    WriteAbility(seri, info->abilities[1]);
    WriteItem(seri, &info->heldItem);
    WriteMonsterUnk64(seri, info->unk64);

    for (i = 0; i < NUM_PREV_POS; i++)
        WriteTilePos(seri, &info->prevPos[i]);

    WriteAITarget(seri, &info->aiTarget);
    WriteIQSkills(seri, &info->IQSkillMenuFlags);
    WriteIQSkills(seri, &info->IQSkillFlags);
    WriteTactic(seri, info->tactic);
    WriteHiddenPower(seri, &info->hiddenPower);
    WriteU32(seri, info->unk98);
    WriteU32(seri, info->unk9C);
    WriteU32(seri, info->unkA0);
    WriteSleepClassStatus(seri, &info->sleepClassStatus);
    WriteBurnClassStatus(seri, &info->burnClassStatus);
    WriteFrozenClassStatus(seri, &info->frozenClassStatus);
    WriteCringeClassStatus(seri, &info->cringeClassStatus);
    WriteBideClassStatus(seri, &info->bideClassStatus);
    WriteReflectClassStatus(seri, &info->reflectClassStatus);
    WriteCurseClassStatus(seri, &info->curseClassStatus);
    WriteLeechSeedClassStatus(seri, &info->leechSeedClassStatus);
    WriteSureShotClassStatus(seri, &info->sureShotClassStatus);
    WriteLongTossClassStatus(seri, &info->longTossClassStatus);
    WriteInvisibleClassStatus(seri, &info->invisibleClassStatus);
    WriteBlinkerClassStatus(seri, &info->blinkerClassStatus);
    WriteMuzzled(seri, &info->muzzled);
    WriteBool8(seri, info->powerEars);
    WriteBool8(seri, info->scanning);
    WriteBool8(seri, info->stairSpotter);
    WriteBool8(seri, info->unkF3);
    WriteBool8(seri, info->grudge);
    WriteU8(seri, info->expMultiplier);
    WriteBool8(seri, info->exposed);
    WriteBool8(seri, info->isColorChanged);
    WriteBool8(seri, info->bossFlag);
    WriteU8(seri, info->terrifiedTurns);
    WriteBool8(seri, info->useHeldItem);
    WriteU8(seri, info->perishSongTurns);
    WriteU8(seri, info->unkFE);
    WriteMonsterUnkFF(seri, info->unkFF);
    WriteDecoyAITracker(seri, info->decoyAITracker);
    WriteSpeedStage(seri, info->speedStage);
    WriteSpeedCounters(seri, info->speedUpCounters, NUM_SPEED_COUNTERS);
    WriteSpeedCounters(seri, info->speedDownCounters, NUM_SPEED_COUNTERS);
    WriteU8(seri, info->stockpileStage);
    WriteU8(seri, info->speedBoostFrames);
    WriteU8(seri, info->moveRandomly);
    WriteMoves(seri, &info->moves);
    WriteBelly(seri, &info->belly);
    WriteBelly(seri, &info->maxBelly);
    WriteBool8(seri, info->aiAllySkip);
    WriteBool8(seri, info->recalculateFollow);
    WriteBool8(seri, info->waiting);
    WriteBool8(seri, info->unk146);
    WriteBool8(seri, info->attacking);
    WriteBool8(seri, info->unk149);
    WriteBool8(seri, info->unk14A);
    WriteBool8(seri, info->unk14B);
    WriteBool8(seri, info->unk14C);
    WriteU16(seri, info->visualFlags);
    WriteU16(seri, info->previousVisualFlags);
    WriteBool8(seri, info->unk152);
    WriteU8(seri, info->unk153);
    WriteBool8(seri, info->unk154);
    WriteBool8(seri, info->unk155);
    WriteBool8(seri, info->unk156);
    WriteU8(seri, info->unk164);
    WriteU8(seri, info->unk165);
    WriteU8(seri, info->unk166);
    WriteU8(seri, info->unk167);
    WriteU8(seri, info->unk168);
    WriteU8(seri, info->turnsSinceWarpScarfActivation);
    WriteTilePos(seri, &info->targetPos);
    WriteF24_8(seri, info->unk174);
    WriteU16(seri, info->abilityEffectFlags);
    WriteS16(seri, info->unk1F8);
    WriteS16(seri, info->mobileTurnTimer);
    WriteU32(seri, info->expGainedInTurn);
    WriteMonsterBehavior(seri, info->monsterBehavior);
}

static void WriteDungeonFloor(DataSerializer *seri)
{
    s32 x;
    s32 y;
    s32 i;

    WriteBlame(seri, sMisakiSan);
    WriteBool8(seri, gDungeon->forceMonsterHouse);
    WriteBool8(seri, gDungeon->unk3A09);
    WriteBool8(seri, gDungeon->unk3A0A);
    WriteBool8(seri, gDungeon->unk3A0B);
    WriteU8(seri, gDungeon->monsterHouseRoom);
    WriteU8(seri, gDungeon->unk3A0D);
    WriteS16(seri, gDungeon->tileset);
    WriteS16(seri,gDungeon->unk3A10);
    WriteS16(seri, gDungeon->unk3A12);
    WriteS16(seri, gDungeon->fixedRoomNumber);
    WriteS16(seri, gDungeon->unk3A16);

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            WriteTile(seri, &gDungeon->tiles[y][x]);
        }
    }

    WriteTilePos(seri, &gDungeon->playerSpawn);
    WriteTilePos(seri, &gDungeon->stairsSpawn);

    for (i = 0; i < 8; i++)
        WriteTilePos(seri, &gDungeon->unkE220[i]);

    WriteDungeonkecleonShopPos(seri, &gDungeon->kecleonShopPos);
    WriteDungeonkecleonShopPos(seri, &gDungeon->unkE250);
    WriteDungeonUnkE260(seri, &gDungeon->unkE260);

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            WriteTile(seri, &gDungeon->unkE27C[y][x]);
            WriteU8(seri, gDungeon->unkE87C[y][x]);
        }
    }

    WriteWeather(seri, &gDungeon->weather);
}

static void WriteDungeonVisibility(DataSerializer *seri)
{
    WriteBlame(seri, sMisakiSan);

    WriteU8(seri, gDungeon->unk181e8.priority);
    WriteU8(seri, gDungeon->unk181e8.visibilityRange);
    WriteBool8(seri, gDungeon->unk181e8.blinded);
    WriteBool8(seri, gDungeon->unk181e8.allTilesRevealed);
    WriteBool8(seri, gDungeon->unk181e8.unk1820C);
    WriteBool8(seri, gDungeon->unk181e8.unk1820D);
    WriteBool8(seri, gDungeon->unk181e8.showAllFloorItems);
    WriteBool8(seri, gDungeon->unk181e8.showInvisibleTrapsMonsters);
    WriteBool8(seri, gDungeon->unk181e8.hallucinating);
    WriteBool8(seri, gDungeon->unk181e8.unk18211);
    WriteBool8(seri, gDungeon->unk181e8.unk18213);
}

static void WriteDungeonMusic(DataSerializer *seri)
{
    WriteS16(seri, gDungeon->musPlayer.songIndex);
    WriteS16(seri, gDungeon->musPlayer.pastSongIndex);
    WriteS16(seri, gDungeon->musPlayer.queuedSongIndex);
}

static void WriteItem(DataSerializer *seri, Item *src)
{
    WriteBytes(seri, &src->flags, 1);
    WriteBytes(seri, &src->quantity, 1);
    WriteBytes(seri, &src->id, 1);
}

static void WriteMonsterUnk64(DataSerializer *seri, u8 value)
{
    u8 stack;

    stack = value;

    WriteBytes(seri, &stack, 1);
}

static void WriteActionContainer(DataSerializer *seri, ActionContainer *src)
{
    WriteBytes(seri, &src->direction, 1);
    WriteBytes(seri, &src->itemTargetPosition.x, 1);
    WriteBytes(seri, &src->itemTargetPosition.y, 1);
}

static void WriteMonsterID(DataSerializer *seri, s16 value)
{
    s16 stack;

    stack = value;

    WriteBytes(seri, &stack, 2);
}

static void WriteType(DataSerializer *seri, u8 value)
{
    u8 stack;

    stack = value;

    WriteBytes(seri, &stack, 1);
}

static void WriteAbility(DataSerializer *seri, u8 value)
{
    u8 stack;

    stack = value;

    WriteBytes(seri, &stack, 1);
}

static void WriteMonsterUnkFF(DataSerializer *seri, u8 value)
{
    u8 stack;

    stack = value;

    WriteBytes(seri, &stack, 1);
}

static void WriteDecoyAITracker(DataSerializer *seri, u8 value)
{
    u8 stack;

    stack = value;

    WriteBytes(seri, &stack, 1);
}

static void WriteSpeedStage(DataSerializer *seri, s32 value)
{
    WriteBytes(seri, &value, 4);
}

static void WriteTactic(DataSerializer *seri, u8 value)
{
    WriteBytes(seri, &value, 1);
}

static void WriteHiddenPower(DataSerializer *seri, HiddenPower *src)
{
    WriteS16(seri, src->hiddenPowerBasePower);
    WriteType(seri, src->hiddenPowerType);
}

static void WriteMonsterBehavior(DataSerializer *seri, u8 value)
{
    WriteU8(seri, value);
}

static void WriteDungeonLocation(DataSerializer *seri, DungeonLocation *src)
{
    WriteU8(seri, src->id);
    WriteU8(seri, src->floor);
}

static void WriteAITarget(DataSerializer *seri, AITarget* src)
{
    WriteBytes(seri, &src->aiObjective, 1);
    WriteBool8(seri, src->aiNotNextToTarget);
    WriteBool8(seri, src->aiTargetingEnemy);
    WriteBool8(seri, src->aiTurningAround);
    WriteU16(seri, src->aiTargetSpawnGenID);
    WriteTilePos(seri, &src->aiTargetPos);
}

static void WriteSleepClassStatus(DataSerializer *seri, SleepClassStatus* src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
}

static void WriteBurnClassStatus(DataSerializer *seri, BurnClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
    WriteU8(seri, src->damageCountdown);
    WriteU8(seri, src->unk4);
}

static void WriteFrozenClassStatus(DataSerializer *seri, FrozenClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
    WriteU8(seri, src->damageCountdown);
    WriteU32(seri, src->unk4);
}

static void WriteCringeClassStatus(DataSerializer *seri, CringeClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
}

static void WriteBideClassStatus(DataSerializer *seri, BideClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
    WriteU8(seri, src->moveSlot);
}

static void WriteReflectClassStatus(DataSerializer *seri, ReflectClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
}

static void WriteCurseClassStatus(DataSerializer *seri, CurseClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteBool8(seri, src->applierNonTeamMemberFlag);
    WriteBool8(seri, src->unk2);
    WriteU8(seri, src->turns);
    WriteU8(seri, src->damageCountdown);
}

static void WriteLeechSeedClassStatus(DataSerializer *seri, LeechSeedClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU32(seri, src->unk4);
    WriteU8(seri, src->unk8);
    WriteU8(seri, src->turns);
    WriteU8(seri, src->damageCountdown);
}

static void WriteSureShotClassStatus(DataSerializer *seri, SureShotClassStatus* src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
}

static void WriteLongTossClassStatus(DataSerializer *seri, LongTossClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
}

static void WriteInvisibleClassStatus(DataSerializer *seri, InvisibleClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
}

static void WriteBlinkerClassStatus(DataSerializer *seri, BlinkerClassStatus *src)
{
    WriteBytes(seri, &src->status, 1);
    WriteU8(seri, src->turns);
}

static void WriteMuzzled(DataSerializer *seri, Muzzled *src)
{
    WriteBytes(seri, &src->muzzled, 1);
    WriteU8(seri, src->turns);
}

static void WriteMove(DataSerializer *seri, Move *src)
{
    WriteU8(seri, src->moveFlags);
    WriteU8(seri, src->moveFlags2);
    WriteBytes(seri, &src->id, 2);
    WriteU8(seri, src->PP);
    WriteU8(seri, src->ginseng);
}

static void WriteMoves(DataSerializer *seri, Moves *src)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        WriteMove(seri, &src->moves[i]);

    WriteU8(seri, src->struggleMoveFlags);
}

static void WriteBelly(DataSerializer *seri, FixedPoint *src)
{
    WriteS16(seri, src->unk0);
    WriteS16(seri, src->unk2);
}

static void WriteIQSkills(DataSerializer *seri, IqSkillFlags *src)
{
    WriteBytes(seri, src, NUM_PICKED_IQ_SKILLS);
}

static void WriteTile(DataSerializer *seri, Tile *src)
{
    WriteU16(seri, src->terrainType);
    WriteU16(seri, src->spawnOrVisibilityFlags);
    WriteBytes(seri, &src->room, 1);
    WriteBytes(seri, &src->unkE, 1);
}

static void WriteWeather(DataSerializer *seri, Weather *src)
{
    s32 i;

    WriteBytes(seri, &src->weather, 1);
    WriteBytes(seri, &src->unkE265, 1);

    for (i = 0; i < 8; i++) {
        WriteU8(seri, src->unkE267[i]);
        WriteU8(seri, src->naturalWeather[i]);
    }

    WriteU8(seri, src->weatherDamageCounter);
    WriteU8(seri, src->mudSportTurns);
    WriteU8(seri, src->waterSportTurns);
    WriteBool8(seri, src->nullifyWeather);
}







// Read funcs










void ReadDungeonState(u8 *buffer, u32 bufLen)
{
    DataSerializer seri;

    InitReader(&seri, buffer, bufLen);

    ReadBytes(&seri, &seri.unkC, 4);

    ReadDungeonUnk644(&seri);
    ReadDungeonFloor(&seri);
    ReadDungeonVisibility(&seri);
    ReadDungeonMusic(&seri);
    ReadDungeonItems(&seri);
    ReadDungeonTraps(&seri);
    ReadDungeonMonsters(&seri);

    ReadBlame(&seri, sYayoiSan);
    FinishSerializer(&seri);
}

static void ReadDungeonUnk644(DataSerializer *seri)
{
    ReadBlame(seri, sMisakiSan);
    ReadBytes(seri, &gDungeon->unk644, sizeof(unkDungeon644));
}

static void ReadDungeonFloor(DataSerializer *seri)
{
    s32 x;
    s32 y;
    s32 i;

    ReadBlame(seri, sMisakiSan);

    gDungeon->forceMonsterHouse = ReadBool8(seri);
    gDungeon->unk3A09 = ReadBool8(seri);
    gDungeon->unk3A0A = ReadBool8(seri);
    gDungeon->unk3A0B = ReadBool8(seri);
    gDungeon->monsterHouseRoom = ReadU8(seri);
    gDungeon->unk3A0D = ReadU8(seri);
    gDungeon->tileset = ReadS16(seri);
    gDungeon->unk3A10 = ReadS16(seri);
    gDungeon->unk3A12 = ReadS16(seri);
    gDungeon->fixedRoomNumber = ReadS16(seri);
    gDungeon->unk3A16 = ReadS16(seri);

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            ReadTile(seri, &gDungeon->tiles[y][x]);
        }
    }

    ReadTilePos(seri, &gDungeon->playerSpawn);
    ReadTilePos(seri, &gDungeon->stairsSpawn);

    for (i = 0; i < 8; i++)
        ReadTilePos(seri, &gDungeon->unkE220[i]);

    ReadDungeonkecleonShopPos(seri, &gDungeon->kecleonShopPos);
    ReadDungeonkecleonShopPos(seri, &gDungeon->unkE250);
    ReadDungeonUnkE260(seri, &gDungeon->unkE260);

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            ReadTile(seri,&gDungeon->unkE27C[y][x]);
            gDungeon->unkE87C[y][x] = ReadU8(seri);
        }
    }

    ReadWeather(seri, &gDungeon->weather);
}

static void ReadTile(DataSerializer *seri, Tile *dst)
{
    memset(dst, 0, sizeof(Tile));

    dst->terrainType = ReadU16(seri);
    dst->spawnOrVisibilityFlags = ReadU16(seri);

    ReadBytes(seri, &dst->room, 1);
    ReadBytes(seri, &dst->unkE, 1);

    dst->monster = NULL;
    dst->object = NULL;
}

static void ReadWeather(DataSerializer *seri, Weather *dst)
{
    s32 i;

    memset(dst, 0, sizeof(Weather));

    ReadBytes(seri, &dst->weather, 1);
    ReadBytes(seri, &dst->unkE265, 1);

    for (i = 0; i < 8; i++) {
        dst->unkE267[i] = ReadU8(seri);
        dst->naturalWeather[i] = ReadU8(seri);
    }

    dst->weatherDamageCounter = ReadU8(seri);
    dst->mudSportTurns = ReadU8(seri);
    dst->waterSportTurns = ReadU8(seri);
    dst->nullifyWeather = ReadBool8(seri);
}

static void ReadDungeonVisibility(DataSerializer *seri)
{
    ReadBlame(seri, sMisakiSan);

    gDungeon->unk181e8.cameraTarget = NULL;
    gDungeon->unk181e8.priority = ReadU8(seri);
    gDungeon->unk181e8.visibilityRange = ReadU8(seri);
    gDungeon->unk181e8.blinded = ReadBool8(seri);
    gDungeon->unk181e8.allTilesRevealed = ReadBool8(seri);
    gDungeon->unk181e8.unk1820C = ReadBool8(seri);
    gDungeon->unk181e8.unk1820D = ReadBool8(seri);
    gDungeon->unk181e8.showAllFloorItems = ReadBool8(seri);
    gDungeon->unk181e8.showInvisibleTrapsMonsters = ReadBool8(seri);
    gDungeon->unk181e8.hallucinating = ReadBool8(seri);
    gDungeon->unk181e8.unk18211 = ReadBool8(seri);
    gDungeon->unk181e8.unk18213 = ReadBool8(seri);
}

static void ReadDungeonMusic(DataSerializer *seri)
{
    gDungeon->musPlayer.songIndex = ReadS16(seri);
    gDungeon->musPlayer.pastSongIndex = ReadS16(seri);
    gDungeon->musPlayer.queuedSongIndex = ReadS16(seri);
}

static void ReadDungeonItems(DataSerializer *seri)
{
    s32 i;
    Item item;
    DungeonPos pos;

    ReadBlame(seri, sMisakiSan);

    for (i = 0; i < DUNGEON_MAX_ITEMS; i++) {
        ReadItem(seri, &item);
        ReadTilePos(seri, &pos);

        if (item.flags & ITEM_FLAG_EXISTS)
            AddItemToDungeonAt(&pos, &item, 0);
    }
}

static void ReadItem(DataSerializer *seri, Item *dst)
{
    memset(dst, 0, sizeof(Item));
    ReadBytes(seri, &dst->flags, 1);
    ReadBytes(seri, &dst->quantity, 1);
    ReadBytes(seri, &dst->id, 1);
}

static void ReadDungeonTraps(DataSerializer *seri)
{
    s32 counter;
    Tile *tile;
    Entity *entity;
    DungeonPos pos;
    u8 isVisible;
    u8 unk1;
    u8 trapID;

    ReadBlame(seri, sMisakiSan);

    for (counter = 0; counter < DUNGEON_MAX_TRAPS; counter++) {
        trapID = TRAP_WARP_TRAP;
        unk1 = 0;
        ReadBytes(seri, &trapID, 1);
        ReadBytes(seri, &unk1, 1);
        isVisible = ReadBool8(seri);
        ReadTilePos(seri, &pos);

        if (trapID != 0xFF) {
            tile = GetTileMut(pos.x, pos.y);
            entity = SpawnTrap(trapID, &pos, unk1);
            if (entity) {
                tile->object = entity;
                entity->isVisible = isVisible;
            }
        }
    }
}

static void ReadDungeonMonsters(DataSerializer *seri)
{
    s32 i;

    ReadBlame(seri, sMisakiSan);

    gDungeon->unk37F0 = ReadU32(seri);
    gDungeon->unk37F4 = ReadU32(seri);
    gDungeon->plusIsActive[0] = ReadBool8(seri);
    gDungeon->plusIsActive[1] = ReadBool8(seri);
    gDungeon->minusIsActive[0] = ReadBool8(seri);
    gDungeon->minusIsActive[1] = ReadBool8(seri);
    gDungeon->decoyIsActive = ReadBool8(seri);
    gDungeon->unk37FD = ReadBool8(seri);
    gDungeon->deoxysDefeat = ReadBool8(seri);
    gDungeon->unk37FF = ReadBool8(seri);
    gDungeon->deoxysForm = ReadU16(seri); // Should be S16

    for (i = 0; i < MAX_TEAM_MEMBERS; i++)
        ReadMonster(seri, TRUE, i);

    for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++)
        ReadMonster(seri, FALSE, i);
}

static void ReadMonster(DataSerializer *seri, bool8 isTeamMember, s32 index)
{
    Entity *mon;
    Tile *tile;
    s32 i;
    EntityInfo *monEntInfo;
    EntityInfo entInfo = {0};
    DungeonPos monPos;
    bool8 shouldSpawnMon;
    u32 monIsVisible;
    u32 spawnGenID;

    ReadU8(seri); // 0xAA
    ReadU8(seri); // 0x55
    shouldSpawnMon = ReadU8(seri);
    ReadTilePos(seri, &monPos);
    monIsVisible = ReadBool8(seri);
    spawnGenID = ReadU16(seri);
    gLeaderPointer = NULL;

    entInfo.flags = ReadU16(seri);
    entInfo.apparentID = ReadMonsterID(seri);
    entInfo.id = ReadMonsterID(seri);
    entInfo.isNotTeamMember = ReadBool8(seri);
    entInfo.isTeamLeader = ReadBool8(seri);
    entInfo.shopkeeper = ReadU8(seri);
    entInfo.level = ReadU8(seri);
    entInfo.teamIndex = ReadU8(seri);
    ReadDungeonLocation(seri, &entInfo.joinedAt);
    entInfo.IQ = ReadS16(seri);
    entInfo.HP = ReadS16(seri);
    entInfo.maxHPStat = ReadS16(seri);
    entInfo.originalHP = ReadS16(seri);
    entInfo.atk[0] = ReadU8(seri);
    entInfo.atk[1] = ReadU8(seri);
    entInfo.def[0] = ReadU8(seri);
    entInfo.def[1] = ReadU8(seri);
    entInfo.exp = ReadU32(seri);
    entInfo.offensiveStages[0] = ReadS16(seri);
    entInfo.offensiveStages[1] = ReadS16(seri);
    entInfo.defensiveStages[0] = ReadS16(seri);
    entInfo.defensiveStages[1] = ReadS16(seri);
    entInfo.hitChanceStages[0] = ReadS16(seri);
    entInfo.hitChanceStages[1] = ReadS16(seri);
    entInfo.flashFireBoost = ReadS16(seri);
    entInfo.offensiveMultipliers[0] = ReadF24_8(seri);
    entInfo.offensiveMultipliers[1] = ReadF24_8(seri);
    entInfo.defensiveMultipliers[0] = ReadF24_8(seri);
    entInfo.defensiveMultipliers[1] = ReadF24_8(seri);
    ReadActionContainer(seri, &entInfo.action);
    entInfo.types[0] = ReadType(seri);
    entInfo.types[1] = ReadType(seri);
    entInfo.abilities[0] = ReadAbility(seri);
    entInfo.abilities[1] = ReadAbility(seri);
    ReadItem(seri, &entInfo.heldItem);
    entInfo.unk64 = ReadMonsterUnk64(seri);

    for (i = 0; i < NUM_PREV_POS; i++)
        ReadTilePos(seri, &entInfo.prevPos[i]);

    ReadAITarget(seri, &entInfo.aiTarget);
    ReadIQSkills(seri, &entInfo.IQSkillMenuFlags);
    ReadIQSkills(seri, &entInfo.IQSkillFlags);
    entInfo.tactic = ReadTactic(seri);
    ReadHiddenPower(seri, &entInfo.hiddenPower);
    entInfo.unk98 = ReadU32(seri);
    entInfo.unk9C = ReadU32(seri);
    entInfo.unkA0 = ReadU32(seri);
    ReadSleepClassStatus(seri, &entInfo.sleepClassStatus);
    ReadBurnClassStatus(seri,&entInfo. burnClassStatus);
    ReadFrozenClassStatus(seri, &entInfo.frozenClassStatus);
    ReadCringeClassStatus(seri, &entInfo.cringeClassStatus);
    ReadBideClassStatus(seri, &entInfo.bideClassStatus);
    ReadReflectClassStatus(seri, &entInfo.reflectClassStatus);
    ReadCurseClassStatus(seri, &entInfo.curseClassStatus);
    ReadLeechSeedClassStatus(seri, &entInfo.leechSeedClassStatus);
    ReadSureShotClassStatus(seri, &entInfo.sureShotClassStatus);
    ReadLongTossClassStatus(seri, &entInfo.longTossClassStatus);
    ReadInvisibleClassStatus(seri, &entInfo.invisibleClassStatus);
    ReadBlinkerClassStatus(seri, &entInfo.blinkerClassStatus);
    ReadMuzzled(seri, &entInfo.muzzled);
    entInfo.powerEars = ReadBool8(seri);
    entInfo.scanning = ReadBool8(seri);
    entInfo.stairSpotter = ReadBool8(seri);
    entInfo.unkF3 = ReadBool8(seri);
    entInfo.grudge = ReadBool8(seri);
    entInfo.expMultiplier = ReadU8(seri);
    entInfo.exposed = ReadBool8(seri);
    entInfo.isColorChanged = ReadBool8(seri);
    entInfo.bossFlag = ReadBool8(seri);
    entInfo.terrifiedTurns = ReadU8(seri);
    entInfo.useHeldItem = ReadBool8(seri);
    entInfo.perishSongTurns = ReadU8(seri);
    entInfo.unkFE = ReadU8(seri);
    entInfo.unkFF = ReadMonsterUnkFF(seri);

    entInfo.decoyAITracker = ReadDecoyAITracker(seri);
    entInfo.speedStage = ReadSpeedStage(seri);
    ReadSpeedCounters(seri, entInfo.speedUpCounters, NUM_SPEED_COUNTERS);
    ReadSpeedCounters(seri, entInfo.speedDownCounters, NUM_SPEED_COUNTERS);
    entInfo.stockpileStage = ReadU8(seri);
    entInfo.speedBoostFrames = ReadU8(seri);
    entInfo.moveRandomly = ReadU8(seri);
    ReadMoves(seri, &entInfo.moves);
    ReadBelly(seri, &entInfo.belly);
    ReadBelly(seri, &entInfo.maxBelly);
    entInfo.aiAllySkip = ReadBool8(seri);
    entInfo.recalculateFollow = ReadBool8(seri);
    entInfo.waiting = ReadBool8(seri);
    entInfo.unk146 = ReadBool8(seri);
    entInfo.attacking = ReadBool8(seri);
    entInfo.unk149 = ReadBool8(seri);
    entInfo.unk14A = ReadBool8(seri);
    entInfo.unk14B = ReadBool8(seri);
    entInfo.unk14C = ReadBool8(seri);
    entInfo.visualFlags = ReadU16(seri);
    entInfo.previousVisualFlags = ReadU16(seri);
    entInfo.unk152 = ReadBool8(seri);
    entInfo.unk153 = ReadU8(seri);
    entInfo.unk154 = ReadBool8(seri);
    entInfo.unk155 = ReadBool8(seri);
    entInfo.unk156 = ReadBool8(seri);
    entInfo.unk164 = ReadU8(seri);
    entInfo.unk165 = ReadU8(seri);
    entInfo.unk166 = ReadU8(seri);
    entInfo.unk167 = ReadU8(seri);
    entInfo.unk168 = ReadU8(seri);
    entInfo.turnsSinceWarpScarfActivation = ReadU8(seri);
    ReadTilePos(seri, &entInfo.targetPos);
    entInfo.unk174 = ReadF24_8(seri);
    entInfo.abilityEffectFlags = ReadU16(seri);
    entInfo.unk1F8 = ReadS16(seri);
    entInfo.mobileTurnTimer = ReadS16(seri);
    entInfo.expGainedInTurn = ReadU32(seri);
    entInfo.monsterBehavior = ReadMonsterBehavior(seri);

    gLeaderPointer = NULL;
    if (shouldSpawnMon) {
        if (isTeamMember)
            mon = sub_80828E0(entInfo.id, entInfo.apparentID, index);
        else
            mon = sub_8082A08(entInfo.id, entInfo.apparentID, index);

        if (mon != NULL) {
            monEntInfo = GetEntInfo(mon);
            tile = GetTileMut(monPos.x, monPos.y);
            mon->prevPos = monPos;
            mon->pos = monPos;
            tile->monster = mon;
            mon->isVisible = monIsVisible;
            mon->spawnGenID = spawnGenID;
            memcpy(monEntInfo, &entInfo, sizeof(EntityInfo));
            gLeaderPointer = NULL;

            if (monEntInfo->isTeamLeader) {
                gPlayerDotMapPosition.x = mon->pos.x;
                gPlayerDotMapPosition.y = mon->pos.y;
            }

            LoadIQSkills(mon);
            sub_804535C(mon, NULL);
        }
    }
}

// Related to sub_80453AC
static Entity* sub_80828E0(s16 id, s16 apparentID, s32 index)
{
    s32 r1;
    s32 r2;
    s32 r3;
    s32 r4;
    u8 apparentBodySize;
    Entity *entity;
    s32 appID;
    s32 id_;

    id_ = id; // SpeciesId() ?
    appID = apparentID; // SpeciesId() ?
    r4 = -1;
    apparentBodySize = GetBodySize(appID);

    for (r3 = 0; r3 <= MAX_TEAM_BODY_SIZE - apparentBodySize; r3++) {
        for (r2 = 0; r2 < apparentBodySize; r2++) {
            if (gUnknown_202EE70[r3 + r2] != 0)
                break;
        }

        if (r2 == apparentBodySize) {
            r4 = r3;
            break;
        }
    }

    if (r4 == -1)
        return NULL;

    entity = gDungeon->teamPokemon[index];
    entity->type = ENTITY_MONSTER;
    entity->unk24 = index;
    entity->axObj.info.monster = &gDungeon->unk69C[index];
    entity->axObj.info.monster->id = id_;
    entity->axObj.info.monster->apparentID = appID;
    entity->axObj.info.monster->isNotTeamMember = FALSE;

    entity->axObj.spriteFile = GetSpriteData(appID);
    entity->axObj.unk40_maybeAnimTimer = (r4 * 0x10) + 0x40;
    entity->axObj.unk42_animId1 = 7;
    entity->axObj.unk44_direction1 = 0;
    entity->axObj.unk43_animId2 = 0xFF;
    entity->axObj.unk45_orientation = 1;
    entity->axObj.unk47 = 1;

    entity->unk1C = IntToF248(0);
    sub_8045ACC();
    entity->axObj.info.monster->unk167 = r4;
    entity->axObj.info.monster->unk168 = apparentBodySize;

    for (r1 = 0; r1 < apparentBodySize; r1++) {
        gUnknown_202EE70[r4] = 1;
        r4++;
    }

    return entity;
}

// Related to sub_804550C
Entity* sub_8082A08(s32 _species, s32 _apparentSpecies, s32 index)
{
    s32 i, j;
    Entity *entity;
    s32 species = (s16) _species;
    s32 apparentSpecies = (s16) _apparentSpecies;
    s32 validId = -1;
    s32 apparentBodySize = GetBodySize((s16)apparentSpecies);

    for (i = 0; i <= DUNGEON_MAX_WILD_POKEMON_BODY_SIZE - apparentBodySize; i++) {
        s32 j;
        for (j = 0; j < apparentBodySize; j++) {
            if (gUnknown_202EE76[i + j] != 0)
                break;
        }

        if (j == apparentBodySize) {
            validId = i;
            break;
        }
    }

    if (validId == -1)
        return NULL;

    entity = gDungeon->wildPokemon[index];
    entity->type = ENTITY_MONSTER;
    entity->unk24 = index;
    entity->unk22 = 0;
    entity->axObj.info.monster = &gDungeon->unkEBC[index];
    entity->axObj.info.monster->id = species;
    entity->axObj.info.monster->apparentID = apparentSpecies;
    entity->axObj.info.monster->isNotTeamMember = TRUE;

    entity->axObj.spriteFile = GetSpriteData(apparentSpecies);
    entity->axObj.unk40_maybeAnimTimer = ((validId + 6) * 16) + 0x40;
    entity->axObj.unk42_animId1 = 7;
    entity->axObj.unk44_direction1 = 0;
    entity->axObj.unk43_animId2 = 0xFF;
    entity->axObj.unk45_orientation = 1;
    entity->axObj.unk47 = 1;

    entity->unk1C = IntToF248(0);
    entity->axObj.info.monster->unk167 = validId;
    entity->axObj.info.monster->unk168 = apparentBodySize;

    for (j = 0; j < apparentBodySize; j++) {
        gUnknown_202EE76[validId] = 1;
        validId++;
    }

    sub_8045ACC();

    return entity;
}

void sub_8082B40(void)
{
    EntityInfo *info;
    Entity *entity;
    s32 i;
    DungeonPos pos;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];
        if (EntityIsValid(entity)) {
            info = GetEntInfo(entity);
            entity->axObj.spriteFile = GetSpriteData(info->apparentID);
            sub_806CCB4(entity, sub_806CEBC(entity));
            pos = entity->pos;
            AddPokemonDungeonSprite(info->unk98, info->apparentID, &pos, 3);
            entity->room = GetTileMut(entity->pos.x, entity->pos.y)->room;
        }
    }
}

static s16 ReadMonsterID(DataSerializer *seri)
{
    s16 temp[2];

    temp[0] = 0;

    ReadBytes(seri, temp, 2);
    return temp[0];
}

static u8 ReadMonsterUnk64(DataSerializer *seri)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(seri, temp, 1);
    return temp[0];
}

static u8 ReadType(DataSerializer *seri)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(seri, temp, 1);
    return temp[0];
}

static u8 ReadAbility(DataSerializer *seri)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(seri, temp, 1);
    return temp[0];
}

static u8 ReadMonsterUnkFF(DataSerializer *seri)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(seri, temp, 1);
    return temp[0];
}

static u8 ReadDecoyAITracker(DataSerializer *seri)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(seri, temp, 1);
    return temp[0];
}

static s32 ReadSpeedStage(DataSerializer *seri)
{
    s32 temp;

    temp = 0;

    ReadBytes(seri, &temp, 4);
    return temp;
}

static u8 ReadTactic(DataSerializer *seri)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(seri, temp, 1);
    return temp[0];
}

static u8 ReadMonsterBehavior(DataSerializer *seri)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(seri, temp, 1);
    return temp[0];
}

static void ReadActionContainer(DataSerializer *seri, ActionContainer *dst)
{
    dst->action = ACTION_NOTHING;
    ReadBytes(seri, &dst->direction, 1);
    dst->unk3 = 7;
    ReadTilePos(seri, &dst->itemTargetPosition);
}

static void ReadAITarget(DataSerializer *seri, AITarget *dst)
{
    ReadBytes(seri, &dst->aiObjective, 1);
    dst->aiNotNextToTarget = ReadBool8(seri);
    dst->aiTargetingEnemy = ReadBool8(seri);
    dst->aiTurningAround = ReadBool8(seri);
    dst->aiTargetSpawnGenID = ReadU16(seri);
    dst->aiTarget = NULL;
    dst->unkC = 0;
    ReadTilePos(seri, &dst->aiTargetPos);
}

static void ReadIQSkills(DataSerializer *seri, IqSkillFlags *dst)
{
    ReadBytes(seri, dst, NUM_PICKED_IQ_SKILLS);
}

static void ReadSleepClassStatus(DataSerializer *seri, SleepClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
}

static void ReadBurnClassStatus(DataSerializer *seri, BurnClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
    dst->damageCountdown = ReadU8(seri);
    dst->unk4 = ReadU8(seri);
}

static void ReadFrozenClassStatus(DataSerializer *seri, FrozenClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
    dst->damageCountdown = ReadU8(seri);
    dst->unk4 = ReadU32(seri);
}

static void ReadCringeClassStatus(DataSerializer *seri, CringeClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
}

static void ReadBideClassStatus(DataSerializer *seri, BideClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
    dst->moveSlot = ReadU8(seri);
}

static void ReadReflectClassStatus(DataSerializer *seri, ReflectClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
}

static void ReadCurseClassStatus(DataSerializer *seri, CurseClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->applierNonTeamMemberFlag = ReadBool8(seri);
    dst->unk2 = ReadBool8(seri);
    dst->turns = ReadU8(seri);
    dst->damageCountdown = ReadU8(seri);
}

static void ReadLeechSeedClassStatus(DataSerializer *seri, LeechSeedClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->unk4 = ReadU32(seri);
    dst->unk8 = ReadU8(seri);
    dst->turns = ReadU8(seri);
    dst->damageCountdown = ReadU8(seri);
}

static void ReadSureShotClassStatus(DataSerializer *seri, SureShotClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
}

static void ReadLongTossClassStatus(DataSerializer *seri, LongTossClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
}

static void ReadInvisibleClassStatus(DataSerializer *seri, InvisibleClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
}

static void ReadBlinkerClassStatus(DataSerializer *seri, BlinkerClassStatus *dst)
{
    ReadBytes(seri, &dst->status, 1);
    dst->turns = ReadU8(seri);
}

static void ReadMuzzled(DataSerializer *seri, Muzzled *dst)
{
    ReadBytes(seri, &dst->muzzled, 1);
    dst->turns = ReadU8(seri);
}

static void ReadMove(DataSerializer *seri, Move *dst)
{
    dst->moveFlags = ReadU8(seri);
    dst->moveFlags2 = ReadU8(seri);
    ReadBytes(seri, &dst->id, 2);
    dst->PP = ReadU8(seri);
    dst->ginseng = ReadU8(seri);
}

static void ReadMoves(DataSerializer *seri, Moves *dst)
{
    s32 i;
    Move *move;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        move = &dst->moves[i];
        ReadMove(seri, move);
    }

    dst->struggleMoveFlags = ReadU8(seri);
}

static void ReadBelly(DataSerializer *seri, FixedPoint *dst)
{
    dst->unk0 = ReadS16(seri);
    dst->unk2 = ReadS16(seri);
}

static void ReadDungeonLocation(DataSerializer *seri, DungeonLocation *dst)
{
    dst->id = ReadU8(seri);
    dst->floor = ReadU8(seri);
}

static void ReadHiddenPower(DataSerializer *seri, HiddenPower *dst)
{
    dst->hiddenPowerBasePower = ReadS16(seri);
    dst->hiddenPowerType = ReadType(seri);
}

static void InitWriter(DataSerializer *seri, u8 *buffer, u32 bufLen)
{
    seri->stream = buffer;
    seri->count = 0;
    seri->end = buffer + bufLen;
}

static void WriteBytes(DataSerializer *seri, void *src, s32 numBytes)
{
    u8 *curByte;

    curByte = src;

    while (numBytes != 0) {
        *seri->stream = *curByte;
        seri->stream++;
        curByte++;
        numBytes--;
        seri->count++;
    }
}

static void InitReader(DataSerializer *seri, u8 *buffer, u32 bufLen)
{
    seri->stream = buffer;
    seri->count = 0;
    seri->end = buffer + bufLen;
}

static void ReadBytes(DataSerializer *seri, void *dst, s32 numBytes)
{
    u8 *curByte;

    curByte = dst;

    while (numBytes != 0) {
        *curByte = *seri->stream;
        seri->stream++;
        curByte++;
        numBytes--;
        seri->count++;
    }
}

static void FinishSerializer(DataSerializer *seri)
{
}

static void WriteBlame(DataSerializer *seri, const u8 *blame)
{
    WriteBytes(seri, (u8 *)blame, BLAME_SIZE);
}

static void ReadBlame(DataSerializer *seri, const u8 *expected)
{
    u8 auStack_10[BLAME_STACK_SIZE];

    ReadBytes(seri, auStack_10, BLAME_SIZE);
    auStack_10[BLAME_SIZE] = 0;
}

static void WriteU16(DataSerializer *seri, u16 value)
{
    u16 uStack_8;

    uStack_8 = value;

    WriteBytes(seri, &uStack_8, 2);
}

static void WriteS16(DataSerializer *seri, s16 value)
{
    s16 uStack_8;

    uStack_8 = value;

    WriteBytes(seri, &uStack_8, 2);
}

static void WriteU8(DataSerializer *seri, u8 value)
{
    u8 uStack_8;

    uStack_8 = value;

    WriteBytes(seri, &uStack_8, 1);
}

static void WriteU32(DataSerializer *seri, u32 value)
{
    u32 uStack_8;

    uStack_8 = value;

    WriteBytes(seri, &uStack_8, 4);
}

UNUSED static void WriteS32(DataSerializer *seri, s32 value)
{
    s32 uStack_8;

    uStack_8 = value;

    WriteBytes(seri, &uStack_8, 4);
}

static void WriteF24_8(DataSerializer *seri, s24_8 value)
{
    s24_8 uStack_8;

    uStack_8 = value;

    WriteBytes(seri, &uStack_8, 4);
}

static void WriteBool8(DataSerializer *seri, bool8 value)
{
    u8 local_8;

    local_8 = value ? -1 : 0;

    WriteBytes(seri, &local_8, 1);
}

static void WriteTilePos(DataSerializer *seri, DungeonPos *src)
{
    WriteBytes(seri, &src->x, 1);
    WriteBytes(seri, &src->y, 1);
}

static void WriteDungeonkecleonShopPos(DataSerializer *seri, struct MinMaxPosition *src)
{
    WriteBytes(seri, &src->minX, 1);
    WriteBytes(seri, &src->minY, 1);
    WriteBytes(seri, &src->maxX, 1);
    WriteBytes(seri, &src->maxY, 1);
}

static void WriteDungeonUnkE260(DataSerializer *seri, unkDungeonE260 *src)
{
    WriteBytes(seri, &src->unk0, 1);
    WriteBytes(seri, &src->unk2, 1);
}

static void WriteSpeedCounters(DataSerializer *seri, u8 *src, u32 numCounters)
{
    WriteBytes(seri, src, numCounters);
}

static u16 ReadU16(DataSerializer *seri)
{
    u16 local_8;

    ReadBytes(seri, &local_8, 2);
    return local_8;
}

static s16 ReadS16(DataSerializer *seri)
{
    s16 local_8;

    ReadBytes(seri, &local_8, 2);
    return local_8;
}

static u8 ReadU8(DataSerializer *seri)
{
    u8 local_8;

    ReadBytes(seri, &local_8, 1);
    return local_8;
}

static u32 ReadU32(DataSerializer *seri)
{
    u32 local_8;

    ReadBytes(seri, &local_8, 4);
    return local_8;
}

UNUSED static s32 ReadS32(DataSerializer *seri)
{
    s32 local_8;

    ReadBytes(seri, &local_8, 4);
    return local_8;
}

static s24_8 ReadF24_8(DataSerializer *seri)
{
    s24_8 local_8;

    ReadBytes(seri, &local_8, 4);
    return local_8;
}

static bool8 ReadBool8(DataSerializer *seri)
{
    u8 local_8;

    ReadBytes(seri, &local_8, 1);
    return local_8 != 0;
}

static void ReadTilePos(DataSerializer *seri, DungeonPos *dst)
{
    dst->x = 0;
    dst->y = 0;
    ReadBytes(seri, &dst->x, 1);
    ReadBytes(seri, &dst->y, 1);
}

static void ReadDungeonkecleonShopPos(DataSerializer *seri, struct MinMaxPosition *dst)
{
    dst->minX = 0;
    dst->minY = 0;
    dst->maxX = 0;
    dst->maxY = 0;
    ReadBytes(seri, &dst->minX, 1);
    ReadBytes(seri, &dst->minY, 1);
    ReadBytes(seri, &dst->maxX, 1);
    ReadBytes(seri, &dst->maxY, 1);
}

static void ReadDungeonUnkE260(DataSerializer *seri, unkDungeonE260 *dst)
{
    dst->unk0 = 0;
    dst->unk2 = 0;
    ReadBytes(seri, &dst->unk0, 1);
    ReadBytes(seri, &dst->unk2, 1);
}

static void ReadSpeedCounters(DataSerializer *seri, u8 *dst, u32 numCounters)
{
    ReadBytes(seri, dst, numCounters);
}
