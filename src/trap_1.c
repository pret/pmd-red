#include "global.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "trap.h"
#include "code_803E668.h"
#include "code_806CD90.h"
#include "code_8092334.h"
#include "dungeon_map_access.h"
#include "items.h"
#include "dungeon_util.h"
#include "structs/str_dungeon.h"
#include "structs/str_traps.h"

extern u8 gMisakiSan[];
extern u8 gYayoiSan[];

extern void WriteBytes(DataSerializer *, void *, s32);

static void WriteDungeonTile(DataSerializer *r0, Tile *tile);
void sub_80830F8(void * , u32*);
void sub_808312C(void *, u16 *);
static void WriteDungeonWeather(DataSerializer *r0, Weather *weather);
void WriteU32(void *, u32);
void WriteBool8(void *, u8);
void WriteU16(void *, u16);
void SaveEntity(DataSerializer *param_1, Entity *);
void Write8Bytes(DataSerializer *param_1, u8 *);
void WriteDungeonItem(DataSerializer *param_1, Item *param_2);
void sub_8080B90(DataSerializer *param_1);
void WriteDungeonItems(DataSerializer *param_1);
void sub_8081454(DataSerializer *param_1);
void sub_808165C(DataSerializer *param_1);
void SaveDungeonMusic(DataSerializer *param_1);
void SaveTrapData(DataSerializer *param_1);
void sub_8080CF0(DataSerializer *param_1);
void nullsub_98(DataSerializer *param_1);
void InitByteWriter(DataSerializer *param_1, u8*, u32);
void sub_8049ED4(void);
void WriteU8(DataSerializer *param_1, u32);
void sub_80817F4(DataSerializer *param_1, u32 param_2);
void WriteS32(DataSerializer *param_1, u32);
void sub_808180C(DataSerializer *param_1, u32 param_2);
void WriteS16(DataSerializer *param_1, u32);
static void WriteJoinedAt(DataSerializer *param_1, JoinedAt *param_2);
void SaveActionContainer(DataSerializer *param_1, ActionContainer *param_2);
void sub_8081B34(DataSerializer *r0, s16 *r1);
void SaveEntityMoves(DataSerializer *r0, Moves *move);
void sub_8081824(DataSerializer *param_1, u32 param_2);
void sub_80817B0(DataSerializer *param_1, u32 param_2);
void WritePosition8(void*, Position *);
void SaveAITargetStatus(DataSerializer *param_1, AITarget* param_2);
void SaveIQFlags(DataSerializer *r0, u8 *r1);
void SaveSpeedStage(DataSerializer *param_1, s32 param_2);
void sub_8081854(DataSerializer *param_1, s32 param_2);
void sub_808183C(DataSerializer *param_1, s32 param_2);
void SaveMuzzledStatus(DataSerializer *param_1, Muzzled *param_2);
void SaveEyesightStatus(DataSerializer *param_1, EyesightStatus *param_2);
void SaveTransformStatus(DataSerializer *param_1, TransformStatus *param_2);
void SaveItemStatus(DataSerializer *param_1, ItemStatus *param_2);
void SaveMoveStatus(DataSerializer *param_1, MoveStatus* param_2);
void SaveLinkedStatus(DataSerializer *param_1, Linked *param_2);
void SaveVolatileStatus(DataSerializer *param_1, Volatile *param_2);
void SaveImmobilizeStatus(DataSerializer *param_1, Immobilize *param_2);
void SaveNonVolatileStatus(DataSerializer *param_1, NonVolatile *param_2);
void SaveEntitySleep(DataSerializer *param_1, Sleep* param_2);
void SaveTactic(DataSerializer *param_1, u8 param_2);
void SaveDungeonHiddenPower(DataSerializer *param_1, HiddenPower *param_2);
void SaveChargingStatus(DataSerializer *param_1, Charging *param_2);
void SaveProtectionStatus(DataSerializer *param_1, Protection *param_2);
void SaveWaitingStatus(DataSerializer *param_1, Waiting *param_2);
void xxx_WriteBytes(DataSerializer *param_1, u8 *speedCounters, u32 numCounters);
void SaveClientType(DataSerializer *param_1, u8 param_2);
void sub_80421C0(Entity *, u16);
void sub_804687C(Entity *, Position *, Position *, Item *, u32);
extern void sub_8083018(DataSerializer *, u8 *);
extern void sub_8081C50(DataSerializer *);
extern void sub_8081C7C(DataSerializer *);
extern void sub_8081F2C(DataSerializer *);
extern void RestoreDungeonMusic(DataSerializer *);
extern void RestoreItemData(DataSerializer *);
extern void RestoreTrapData(DataSerializer *);
extern void sub_808217C(DataSerializer *);
extern void InitByteReader(DataSerializer *param_1, u8 *r1, u32 r2);
extern void ReadBytes(DataSerializer *, void *, u32);
u8 ReadBool8(DataSerializer *r0);
u8 ReadU8(DataSerializer *r0);
s16 ReadS16(DataSerializer *r0);
void ReadPosition8(DataSerializer *r0, Position *);
void RestoreDungeonWeather(DataSerializer *r0, Weather *);
void sub_8083220(DataSerializer *r0, u32 *);
void sub_8083260(DataSerializer *r0, u16 *);
void RestoreTile(DataSerializer *r0, Tile *);
extern u16 ReadU16(DataSerializer *param_1);
void sub_80820A8(DataSerializer *r0, Item *);
void sub_80460F8(Position *, Item *, u32);
Entity *sub_8045684(u8, Position *, u8);
u32 sub_80831A0(DataSerializer *param_1);
void RestoreDungeonEntity(DataSerializer *param_1,bool8 isTeamMember,s32 index);

extern u8 gYayoiSan[];

void HandleTripTrap(Entity *pokemon, Entity *target)
{
    u32 direction;
    EntityInfo *info;
    Position pos;
    Item item;

    if (target != NULL) {
        sub_806CDD4(target, 6, NUM_DIRECTIONS);
        sub_803E708(0x10, 0x55);
        sub_806CE68(target, NUM_DIRECTIONS);
        info = GetEntInfo(target);
        if ((info->heldItem).flags & ITEM_FLAG_EXISTS) {
            item =  (info->heldItem);
            (info->heldItem).flags = 0;
            FillInventoryGaps();
            sub_80421C0(target, 400);
            direction = (info->action).direction & DIRECTION_MASK;
            pos.x = (target->pos).x + gAdjacentTileOffsets[direction].x;
            pos.y =  (target->pos).y + gAdjacentTileOffsets[direction].y;
            sub_804687C(pokemon, &target->pos, &pos, &item, 1);
        }
    }
}

void SetTrap(Tile *tile, u8 id)
{
    Trap *trapData;
    Entity *entity;

    entity = tile->object;
    if (EntityExists(entity)) {
        if (GetEntityType(entity) == ENTITY_TRAP) {
            trapData = GetTrapData(entity);
            trapData->id = id;
        }
        sub_8049ED4();
    }
}





// TODO: New file here





void WriteDungeonState(u8 *buffer, u32 bufLen)
{
    DataSerializer seri;

    InitByteWriter(&seri, buffer, bufLen);

    seri.unkC = 0;
    WriteBytes(&seri, &seri.unkC, 4);

    sub_8080B90(&seri);
    sub_8081454(&seri);
    sub_808165C(&seri);
    SaveDungeonMusic(&seri);
    WriteDungeonItems(&seri);
    SaveTrapData(&seri);
    sub_8080CF0(&seri);

    Write8Bytes(&seri, gYayoiSan);
    nullsub_98(&seri);
}

void sub_8080B90(DataSerializer *param_1)
{
    Write8Bytes(param_1, gMisakiSan);
    WriteBytes(param_1, &gDungeon->dungeonLocation, 0x58);
}

void WriteDungeonItems(DataSerializer *param_1)
{
    bool8 notEmpty;
    Item *item;
    Entity *entity;
    int counter;
    u8 emptyItem [5];

    for (counter = 0; counter < 5; counter++)
        emptyItem[counter] = 0;

    Write8Bytes(param_1, gMisakiSan);

    for (counter = 0; counter < DUNGEON_MAX_ITEMS; counter++) {
        entity = gDungeon->items[counter];
        notEmpty = FALSE;

        if (entity != NULL && GetEntityType(entity) == ENTITY_ITEM) {
            item = GetItemData(entity);
            WriteDungeonItem(param_1, item); // 3 bytes
            WriteBytes(param_1, &entity->pos.x, 1); // 1 byte
            WriteBytes(param_1, &entity->pos.y, 1); // 1 byte
            notEmpty = TRUE;
        }

        if (!notEmpty)
            WriteBytes(param_1, emptyItem, 5);
    }
}

void SaveTrapData(DataSerializer *param_1)
{
    bool8 flag;
    Trap *trap;
    Entity *entity;
    int counter;
    u8 local_1c [5];

    for(counter = 0; counter < 5; counter++)
    {
        local_1c[counter] = -1;
    }
    Write8Bytes(param_1,gMisakiSan);

    for(counter = 0; counter < DUNGEON_MAX_TRAPS; counter++)
    {
        entity = gDungeon->traps[counter];
        flag = FALSE;
        if ((entity != NULL) && (GetEntityType(entity) == ENTITY_TRAP)) {
            trap = GetTrapData(entity);
            WriteBytes(param_1,&trap->id,1);
            WriteBytes(param_1,&trap->unk1,1);
            WriteBytes(param_1,&entity->isVisible,1);
            WriteBytes(param_1,&entity->pos.x,1);
            WriteBytes(param_1,&entity->pos.y,1);
            flag = TRUE;
        }
        if (!flag) {
            WriteBytes(param_1,local_1c,5);
        }
    }
}

void sub_8080CF0(DataSerializer *param_1)
{
    s32 counter;

    Write8Bytes(param_1,gMisakiSan);
    WriteU32(param_1,gDungeon->unk37F0);
    WriteU32(param_1,gDungeon->unk37F4);
    WriteBool8(param_1,gDungeon->plusIsActive[0]);
    WriteBool8(param_1,gDungeon->plusIsActive[1]);
    WriteBool8(param_1,gDungeon->minusIsActive[0]);
    WriteBool8(param_1,gDungeon->minusIsActive[1]);
    WriteBool8(param_1,gDungeon->decoyActive);
    WriteBool8(param_1,gDungeon->unk37FD);
    WriteBool8(param_1,gDungeon->deoxysDefeat);
    WriteBool8(param_1,gDungeon->unk37FF);
    WriteU16(param_1,gDungeon->unk3800);
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        SaveEntity(param_1,gDungeon->teamPokemon[counter]);
    }
    for(counter = 0; counter < DUNGEON_MAX_WILD_POKEMON; counter++)
    {
        SaveEntity(param_1,gDungeon->wildPokemon[counter]);
    }
}

void SaveEntity(DataSerializer *param_1, Entity *param_2)
{
    Position *pos;
    EntityInfo *info;
    int counter;
    EntityInfo info2;
    u32 uStack_ac;
    u32 uStack_a8;
    HiddenPower *psStack_a4;
    u8 *temp1;
    u8 *temp2;
    AITarget *temp3;
    u8 *puStack_a0;
    u32 *puStack_9c;
    u32 *puStack_98;
    u32 *puStack_94;
    u8 *puStack_90;
    Sleep *puStack_8c;
    NonVolatile *puStack_88;
    Immobilize *puStack_84;
    Volatile *puStack_80;
    Charging *puStack_7c;
    Protection *puStack_78;
    Waiting *puStack_74;
    Linked *puStack_70;
    MoveStatus *puStack_6c;
    ItemStatus *puStack_68;
    TransformStatus *puStack_64;
    EyesightStatus *puStack_60;
    Muzzled *pbStack_5c;
    bool8 *pbStack_58;
    bool8 *pbStack_54;
    bool8 *pbStack_50;
    bool8 *puStack_4c;
    bool8 *pbStack_48;
    bool8 *pbStack_44;
    bool8 *pbStack_40;
    bool8 *pbStack_3c;
    u8 *puStack_38;
    u8 *puStack_34;
    bool8 *pbStack_30;
    u8 *puStack_2c;
    u8 *puStack_28;
    u8 *puStack_24;


    uStack_a8 = 0;
    uStack_ac = 1;
    WriteU8(param_1,0xaa);
    WriteU8(param_1,0x55);
    if (EntityExists(param_2)) {
        info = GetEntInfo(param_2);
        WriteBytes(param_1,&uStack_ac,1);
        WriteBytes(param_1,&param_2->pos.x,1);
        WriteBytes(param_1,&param_2->pos.y,1);
        WriteBytes(param_1,&param_2->isVisible,1);
        WriteBytes(param_1,&param_2->spawnGenID,2);
    }
    else {
        memset(&info2,0,sizeof(EntityInfo));
        info = &info2;
        WriteBytes(param_1,&uStack_a8,1);
        WriteBytes(param_1,&uStack_a8,1);
        WriteBytes(param_1,&uStack_a8,1);
        WriteBytes(param_1,&uStack_a8,1);
        WriteBytes(param_1,&uStack_a8,2);
    }
    WriteU16(param_1,info->flags);
    sub_80817F4(param_1,info->apparentID);
    sub_80817F4(param_1,info->id);
    WriteBool8(param_1,info->isNotTeamMember);
    WriteBool8(param_1,info->isTeamLeader);
    WriteU8(param_1,info->shopkeeper);
    WriteU8(param_1,info->level);
    WriteU8(param_1,info->teamIndex);
    WriteJoinedAt(param_1,&info->joinedAt);
    WriteS16(param_1,info->IQ);
    WriteS16(param_1,info->HP);
    WriteS16(param_1,info->maxHPStat);
    WriteS16(param_1,info->originalHP);
    WriteU8(param_1,info->atk[0]);
    WriteU8(param_1,info->atk[1]);
    WriteU8(param_1,info->def[0]);
    WriteU8(param_1,info->def[1]);
    WriteU32(param_1,info->exp);
    WriteS16(param_1,info->offensiveStages[0]);
    WriteS16(param_1,info->offensiveStages[1]);
    WriteS16(param_1,info->defensiveStages[0]);
    WriteS16(param_1,info->defensiveStages[1]);
    WriteS16(param_1,info->hitChanceStages[0]);
    WriteS16(param_1,info->hitChanceStages[1]);
    WriteS16(param_1,info->flashFireBoost);
    WriteS32(param_1,info->offensiveMultipliers[0]);
    WriteS32(param_1,info->offensiveMultipliers[1]);
    WriteS32(param_1,info->defensiveMultipliers[0]);
    WriteS32(param_1,info->defensiveMultipliers[1]);
    SaveActionContainer(param_1,&info->action);
    sub_808180C(param_1,info->types[0]);
    sub_808180C(param_1,info->types[1]);
    sub_8081824(param_1,info->abilities[0]);
    sub_8081824(param_1,info->abilities[1]);
    WriteDungeonItem(param_1,&info->heldItem);
    sub_80817B0(param_1,info->unk64);
    temp3 = &info->aiTarget;
    temp2 = info->IQSkillMenuFlags;
    temp1 = info->IQSkillFlags;
    puStack_a0 = &info->tactic;
    psStack_a4 = &info->hiddenPower;
    puStack_9c = &info->unk98;
    puStack_98 = &info->unk9C;
    puStack_94 = &info->unkA0;
    puStack_8c = &info->sleep;
    puStack_88 = &info->nonVolatile;
    puStack_84 = &info->immobilize;
    puStack_80 = &info->volatileStatus;
    puStack_7c = &info->charging;
    puStack_78 = &info->protection;
    puStack_74 = &info->waitingStruct;
    puStack_70 = &info->linked;
    puStack_6c = &info->moveStatus;
    puStack_68 = &info->itemStatus;
    puStack_64 = &info->transformStatus;
    puStack_60 = &info->eyesightStatus;
    pbStack_5c = &info->muzzled;
    pbStack_58 = &info->powerEars;
    pbStack_54 = &info->scanning;
    pbStack_50 = &info->stairSpotter;
    puStack_4c = &info->unkF3;
    pbStack_48 = &info->grudge;
    puStack_34 = &info->expMultiplier;
    pbStack_44 = &info->exposed;
    pbStack_40 = &info->isColorChanged;
    pbStack_3c = &info->bossFlag;
    puStack_38 = &info->terrifiedTurns;
    pbStack_30 = &info->useHeldItem;
    puStack_2c = &info->perishSongTurns;
    puStack_28 = &info->unkFE;
    puStack_24 = &info->unkFF;
    puStack_90 = &info->clientType;

    pos = info->prevPos;
    for(counter = 0; counter < NUM_PREV_POS; counter++)
    {
        WritePosition8(param_1,pos);
        pos++;
    }

    SaveAITargetStatus(param_1,temp3);
    SaveIQFlags(param_1,temp2);
    SaveIQFlags(param_1,temp1);
    SaveTactic(param_1,*puStack_a0);
    SaveDungeonHiddenPower(param_1,psStack_a4);
    WriteU32(param_1,*puStack_9c);
    WriteU32(param_1,*puStack_98);
    WriteU32(param_1,*puStack_94);
    SaveEntitySleep(param_1,puStack_8c);
    SaveNonVolatileStatus(param_1,puStack_88);
    SaveImmobilizeStatus(param_1,puStack_84);
    SaveVolatileStatus(param_1,puStack_80);
    SaveChargingStatus(param_1,puStack_7c);
    SaveProtectionStatus(param_1,puStack_78);
    SaveWaitingStatus(param_1,puStack_74);
    SaveLinkedStatus(param_1,puStack_70);
    SaveMoveStatus(param_1,puStack_6c);
    SaveItemStatus(param_1,puStack_68);
    SaveTransformStatus(param_1,puStack_64);
    SaveEyesightStatus(param_1,puStack_60);
    SaveMuzzledStatus(param_1,pbStack_5c);
    WriteBool8(param_1,*pbStack_58);
    WriteBool8(param_1,*pbStack_54);
    WriteBool8(param_1,*pbStack_50);
    WriteBool8(param_1,*puStack_4c);
    WriteBool8(param_1,*pbStack_48);
    WriteU8(param_1,*puStack_34);
    WriteBool8(param_1,*pbStack_44);
    WriteBool8(param_1,*pbStack_40);
    WriteBool8(param_1,*pbStack_3c);
    WriteU8(param_1,*puStack_38);
    WriteBool8(param_1,*pbStack_30);
    WriteU8(param_1,*puStack_2c);
    WriteU8(param_1,*puStack_28);
    sub_808183C(param_1,*puStack_24);
    sub_8081854(param_1,info->targetingDecoy);
    SaveSpeedStage(param_1,info->speedStage);
    xxx_WriteBytes(param_1,info->speedUpCounters,NUM_SPEED_COUNTERS);
    xxx_WriteBytes(param_1,info->speedDownCounters,NUM_SPEED_COUNTERS);
    WriteU8(param_1,info->stockpileStage);
    WriteU8(param_1,info->unk113);
    WriteU8(param_1,(u8)info->moveRandomly);
    SaveEntityMoves(param_1,&info->moves);
    sub_8081B34(param_1,(s16 *)&info->belly);
    sub_8081B34(param_1,(s16 *)&info->maxBelly);
    WriteBool8(param_1,info->aiNextToTarget);
    WriteBool8(param_1,info->recalculateFollow);
    WriteBool8(param_1,info->waiting);
    WriteBool8(param_1,info->unk146);
    WriteBool8(param_1,info->attacking);
    WriteBool8(param_1,info->unk149);
    WriteBool8(param_1,info->unk14A);
    WriteBool8(param_1,info->unk14B);
    WriteBool8(param_1,info->unk14C);
    WriteU16(param_1,info->visualFlags);
    WriteU16(param_1,info->previousVisualFlags);
    WriteBool8(param_1,info->unk152);
    WriteU8(param_1,info->unk153);
    WriteBool8(param_1,info->unk154);
    WriteBool8(param_1,info->unk155);
    WriteBool8(param_1,info->unk156);
    WriteU8(param_1,info->unk164);
    WriteU8(param_1,info->unk165);
    WriteU8(param_1,info->unk166);
    WriteU8(param_1,info->unk167);
    WriteU8(param_1,info->unk168);
    WriteU8(param_1,info->turnsSinceWarpScarfActivation);
    WritePosition8(param_1,&(info->targetPos));
    WriteS32(param_1,info->unk174);
    WriteU16(param_1,info->abilityEffectFlags);
    WriteS16(param_1,info->unk1F8);
    WriteS16(param_1,info->mobileTurnTimer);
    WriteU32(param_1,info->expGainedInTurn);
    SaveClientType(param_1,*puStack_90);
}

void sub_8081454(DataSerializer *param_1)
{
    int iVar1;
    int iVar2;
    int iVar4;

    Write8Bytes(param_1,gMisakiSan);
    WriteBool8(param_1, gDungeon->unk3A08);
    WriteBool8(param_1, gDungeon->unk3A09);
    WriteBool8(param_1, gDungeon->unk3A0A);
    WriteBool8(param_1, gDungeon->unk3A0B);
    WriteU8(param_1, gDungeon->unk3A0C);
    WriteU8(param_1, gDungeon->unk3A0D);
    WriteS16(param_1, gDungeon->tileset);
    WriteS16(param_1,gDungeon->unk3A10);
    WriteS16(param_1, gDungeon->unk3A12);
    WriteS16(param_1, gDungeon->bossBattleIndex);
    WriteS16(param_1, gDungeon->unk3A16);
    for(iVar1 = 0; iVar1 < DUNGEON_MAX_SIZE_Y; iVar1++)
    {

        for(iVar2 = 0; iVar2 < DUNGEON_MAX_SIZE_X; iVar2++)
        {
            WriteDungeonTile(param_1,&gDungeon->tiles[iVar1][iVar2]);
        }
    }


    WritePosition8(param_1,&gDungeon->unkE218);
    WritePosition8(param_1,&gDungeon->unkE21C);



    for(iVar4 = 0; iVar4 < 8; iVar4++)
    {
        WritePosition8(param_1,&gDungeon->unkE220[iVar4]);
    }
    sub_80830F8(param_1, gDungeon->unkE240);
    sub_80830F8(param_1, gDungeon->unkE250);
    sub_808312C(param_1, gDungeon->unkE260);

    for(iVar1 = 0; iVar1 < 8; iVar1++)
    {
        for(iVar2 = 0; iVar2 < 8; iVar2++)
        {
            WriteDungeonTile(param_1, &gDungeon->unkE27C[iVar1][iVar2]);
            WriteU8(param_1, gDungeon->unkE87C[iVar1][iVar2]);
        }
    }
    WriteDungeonWeather(param_1,&gDungeon->weather);
}

void sub_808165C(DataSerializer *param_1)
{

    Write8Bytes(param_1,gMisakiSan);
    WriteU8(param_1, gDungeon->unk181e8.unk18208);
    WriteU8(param_1, gDungeon->unk181e8.visibilityRange);
    WriteBool8(param_1, gDungeon->unk181e8.blinded);
    WriteBool8(param_1, gDungeon->unk181e8.unk1820B);
    WriteBool8(param_1, gDungeon->unk181e8.unk1820C);
    WriteBool8(param_1, gDungeon->unk181e8.unk1820D);
    WriteBool8(param_1, gDungeon->unk181e8.unk1820E);
    WriteBool8(param_1, gDungeon->unk181e8.unk1820F);
    WriteBool8(param_1, gDungeon->unk181e8.hallucinating);
    WriteBool8(param_1, gDungeon->unk181e8.unk18211);
    WriteBool8(param_1, gDungeon->unk181e8.unk18213);
}

// NOTE: forcing this s16 for now - Seth
void SaveDungeonMusic(DataSerializer *param_1)
{
    WriteS16(param_1, (s16)gDungeon->musPlayer.songIndex);
    WriteS16(param_1, (s16)gDungeon->musPlayer.pastSongIndex);
    WriteS16(param_1, (s16)gDungeon->musPlayer.queuedSongIndex);
}

void WriteDungeonItem(DataSerializer *param_1, Item *param_2)
{
    WriteBytes(param_1, &param_2->flags, 1);
    WriteBytes(param_1, &param_2->quantity, 1);
    WriteBytes(param_1, &param_2->id, 1);
}

void sub_80817B0(DataSerializer *param_1, u32 param_2)
{
    u8 stack;
    stack = param_2;
    WriteBytes(param_1, &stack, 1);
}

void SaveActionContainer(DataSerializer *param_1, ActionContainer *param_2)
{
    WriteBytes(param_1, &param_2->direction, 1);
    WriteBytes(param_1, &param_2->itemTargetPosition.x, 1);
    WriteBytes(param_1, &param_2->itemTargetPosition.y, 1);
}

void sub_80817F4(DataSerializer *param_1, u32 param_2)
{
    u16 stack;
    stack = param_2;
    WriteBytes(param_1, &stack, 2);
}

void sub_808180C(DataSerializer *param_1, u32 param_2)
{
    u8 stack;
    stack = param_2;
    WriteBytes(param_1, &stack, 1);
}

void sub_8081824(DataSerializer *param_1, u32 param_2)
{
    u8 stack;
    stack = param_2;
    WriteBytes(param_1, &stack, 1);
}

void sub_808183C(DataSerializer *param_1, s32 param_2)
{
    u8 stack;
    stack = param_2;
    WriteBytes(param_1, &stack, 1);
}

void sub_8081854(DataSerializer *param_1, s32 param_2)
{
    u8 stack;
    stack = param_2;
    WriteBytes(param_1, &stack, 1);
}

void SaveSpeedStage(DataSerializer *param_1, s32 param_2)
{
    WriteBytes(param_1, &param_2, 4);
}

void SaveTactic(DataSerializer *param_1, u8 param_2)
{
    WriteBytes(param_1, &param_2, 1);
}

void SaveDungeonHiddenPower(DataSerializer *param_1, HiddenPower *param_2)
{
    WriteS16(param_1, param_2->hiddenPowerBasePower);
    sub_808180C(param_1, param_2->hiddenPowerType);
}

void SaveClientType(DataSerializer *param_1, u8 param_2)
{
    WriteU8(param_1, param_2);
}

static void WriteJoinedAt(DataSerializer *param_1, JoinedAt *param_2)
{
    WriteU8(param_1, param_2->joinedAt);
    WriteU8(param_1, param_2->unk1);
}

void SaveAITargetStatus(DataSerializer *param_1, AITarget* param_2)
{
    WriteBytes(param_1, &param_2->aiObjective, 1);
    WriteBool8(param_1, param_2->aiNotNextToTarget);
    WriteBool8(param_1, param_2->aiTargetingEnemy);
    WriteBool8(param_1, param_2->aiTurningAround);
    WriteU16(param_1, param_2->aiTargetSpawnGenID);
    WritePosition8(param_1, &param_2->aiTargetPos);
}

void SaveEntitySleep(DataSerializer *param_1, Sleep* param_2)
{
    WriteBytes(param_1, &param_2->sleep, 1);
    WriteU8(param_1, param_2->sleepTurns);
}

void SaveNonVolatileStatus(DataSerializer *param_1, NonVolatile *param_2)
{
    WriteBytes(param_1, &param_2->nonVolatileStatus, 1);
    WriteU8(param_1, param_2->nonVolatileStatusTurns);
    WriteU8(param_1, param_2->nonVolatileStatusDamageCountdown);
    WriteU8(param_1, param_2->unk4);
}

void SaveImmobilizeStatus(DataSerializer *param_1, Immobilize *param_2)
{
    WriteBytes(param_1, &param_2->immobilizeStatus, 1);
    WriteU8(param_1, param_2->immobilizeStatusTurns);
    WriteU8(param_1, param_2->immobilizeStatusDamageCountdown);
    WriteU32(param_1, param_2->unk4);
}

void SaveVolatileStatus(DataSerializer *param_1, Volatile *param_2)
{
    WriteBytes(param_1, &param_2->volatileStatus, 1);
    WriteU8(param_1, param_2->volatileStatusTurns);
}

void SaveChargingStatus(DataSerializer *param_1, Charging *param_2)
{
    WriteBytes(param_1, &param_2->chargingStatus, 1);
    WriteU8(param_1, param_2->chargingStatusTurns);
    WriteU8(param_1, param_2->chargingStatusMoveIndex);
}

void SaveProtectionStatus(DataSerializer *param_1, Protection *param_2)
{
    WriteBytes(param_1, &param_2->protectionStatus, 1);
    WriteU8(param_1, param_2->protectionStatusTurns);
}

void SaveWaitingStatus(DataSerializer *param_1, Waiting *param_2)
{
    WriteBytes(param_1, &param_2->waitingStatus, 1);
    WriteBool8(param_1, param_2->enemyDecoy);
    WriteBool8(param_1, param_2->unkCA);
    WriteU8(param_1, param_2->waitingStatusTurns);
    WriteU8(param_1, param_2->curseDamageCountdown);
}

void SaveLinkedStatus(DataSerializer *param_1, Linked *param_2)
{
    WriteBytes(param_1, &param_2->linkedStatus, 1);
    WriteU32(param_1, param_2->unkD4);
    WriteU8(param_1, param_2->unkD8);
    WriteU8(param_1, param_2->linkedStatusTurns);
    WriteU8(param_1, param_2->linkedStatusDamageCountdown);
}

void SaveMoveStatus(DataSerializer *param_1, MoveStatus* param_2)
{
    WriteBytes(param_1, &param_2->moveStatus, 1);
    WriteU8(param_1, param_2->moveStatusTurns);
}

void SaveItemStatus(DataSerializer *param_1, ItemStatus *param_2)
{
    WriteBytes(param_1, &param_2->itemStatus, 1);
}

void SaveTransformStatus(DataSerializer *param_1, TransformStatus *param_2)
{
    WriteBytes(param_1, &param_2->transformStatus, 1);
    WriteU8(param_1, param_2->transformStatusTurns);
}

void SaveEyesightStatus(DataSerializer *param_1, EyesightStatus *param_2)
{
    WriteBytes(param_1, &param_2->eyesightStatus, 1);
    WriteU8(param_1, param_2->eyesightStatusTurns);
}

void SaveMuzzledStatus(DataSerializer *param_1, Muzzled *param_2)
{
    WriteBytes(param_1, &param_2->muzzled, 1);
    WriteU8(param_1, param_2->muzzledTurns);
}

void SaveEntityMove(DataSerializer *r0, Move *r1)
{
    WriteU8(r0, r1->moveFlags);
    WriteU8(r0, r1->moveFlags2);
    WriteBytes(r0, &r1->id, 2);
    WriteU8(r0, r1->PP);
    WriteU8(r0, r1->ginseng);
}

void SaveEntityMoves(DataSerializer *r0, Moves *move)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        SaveEntityMove(r0, &move->moves[i]);

    WriteU8(r0, move->struggleMoveFlags);
}

void sub_8081B34(DataSerializer *r0, s16 *r1)
{
    WriteS16(r0, r1[0]);
    WriteS16(r0, r1[1]);
}

void SaveIQFlags(DataSerializer *r0, u8 *r1)
{
    WriteBytes(r0, r1, NUM_PICKED_IQ_SKILLS);
}

static void WriteDungeonTile(DataSerializer *r0, Tile *tile)
{
    WriteU16(r0, tile->terrainType);
    WriteU16(r0, tile->unk4);
    WriteBytes(r0, &tile->room, 1);
    WriteBytes(r0, &tile->unkE, 1);
}

static void WriteDungeonWeather(DataSerializer *r0, Weather *weather)
{
    s32 i;

    WriteBytes(r0, &weather->weather, 1);
    WriteBytes(r0, &weather->unkE265, 1);

    for (i = 0; i < 8; i++) {
        WriteU8(r0, weather->unkE267[i]);
        WriteU8(r0, weather->naturalWeather[i]);
    }

    WriteU8(r0, weather->weatherDamageCounter);
    WriteU8(r0, weather->mudSportTurns);
    WriteU8(r0, weather->waterSportTurns);
    WriteBool8(r0, weather->nullifyWeather);
}

// Read func

void ReadDungeonState(u8 *buffer, u32 bufLen)
{
    DataSerializer seri;

    InitByteReader(&seri, buffer, bufLen);

    ReadBytes(&seri, &seri.unkC, 4);
    sub_8081C50(&seri);
    sub_8081C7C(&seri);
    sub_8081F2C(&seri);
    RestoreDungeonMusic(&seri);
    RestoreItemData(&seri);
    RestoreTrapData(&seri);
    sub_808217C(&seri);

    sub_8083018(&seri, gYayoiSan);
    nullsub_98(&seri);
}

void sub_8081C50(DataSerializer *r0)
{
    sub_8083018(r0, gMisakiSan);
    ReadBytes(r0, &gDungeon->dungeonLocation, 0x58);
}

void sub_8081C7C(DataSerializer *r0)
{
    int x;
    int y;
    s32 iVar7;

    sub_8083018(r0,gMisakiSan);
    gDungeon->unk3A08 = ReadBool8(r0);
    gDungeon->unk3A09 = ReadBool8(r0);
    gDungeon->unk3A0A = ReadBool8(r0);
    gDungeon->unk3A0B = ReadBool8(r0);
    gDungeon->unk3A0C = ReadU8(r0);
    gDungeon->unk3A0D = ReadU8(r0);
    gDungeon->tileset = ReadS16(r0);
    gDungeon->unk3A10 = ReadS16(r0);
    gDungeon->unk3A12 = ReadS16(r0);
    gDungeon->bossBattleIndex = ReadS16(r0);
    gDungeon->unk3A16 = ReadS16(r0);

    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
        {
            RestoreTile(r0,&gDungeon->tiles[y][x]);
        }
    }
    ReadPosition8(r0,&gDungeon->unkE218);
    ReadPosition8(r0,&gDungeon->unkE21C);

    for(iVar7 = 0; iVar7 < 8; iVar7++)
    {
        ReadPosition8(r0,&gDungeon->unkE220[iVar7]);
    }
    sub_8083220(r0, gDungeon->unkE240);
    sub_8083220(r0, gDungeon->unkE250);
    sub_8083260(r0, gDungeon->unkE260);


    for(y = 0; y < 8; y++)
    {
        for(x = 0; x < 8; x++)
        {
            RestoreTile(r0,&gDungeon->unkE27C[y][x]);
            gDungeon->unkE87C[y][x] = ReadU8(r0);
        }
    }
    RestoreDungeonWeather(r0,&gDungeon->weather);
}

void RestoreTile(DataSerializer *r0, Tile *tile)
{
    memset(tile, 0, sizeof(Tile));
    tile->terrainType = ReadU16(r0);
    tile->unk4 = ReadU16(r0);

    ReadBytes(r0, (u32 *)&tile->room, 1);
    ReadBytes(r0, (u32 *)&tile->unkE, 1);

    tile->monster = NULL;
    tile->object = NULL;
}

void RestoreDungeonWeather(DataSerializer *r0, Weather *weather)
{
    s32 index;
    memset(weather, 0, sizeof(Weather));
    ReadBytes(r0, (u32 *)&weather->weather, 1);
    ReadBytes(r0, (u32 *)&weather->unkE265, 1);
    for(index = 0; index < 8; index++)
    {
        weather->unkE267[index] = ReadU8(r0);
        weather->naturalWeather[index] = ReadU8(r0);
    }
    weather->weatherDamageCounter = ReadU8(r0);
    weather->mudSportTurns = ReadU8(r0);
    weather->waterSportTurns = ReadU8(r0);
    weather->nullifyWeather = ReadBool8(r0);
}

void sub_8081F2C(DataSerializer *param_1)
{
    sub_8083018(param_1,gMisakiSan);
    gDungeon->unk181e8.cameraTarget = NULL;
    gDungeon->unk181e8.unk18208 = ReadU8(param_1);
    gDungeon->unk181e8.visibilityRange = ReadU8(param_1);
    gDungeon->unk181e8.blinded        = ReadBool8(param_1);
    gDungeon->unk181e8.unk1820B       = ReadBool8(param_1);
    gDungeon->unk181e8.unk1820C       = ReadBool8(param_1);
    gDungeon->unk181e8.unk1820D       = ReadBool8(param_1);
    gDungeon->unk181e8.unk1820E       = ReadBool8(param_1);
    gDungeon->unk181e8.unk1820F       = ReadBool8(param_1);
    gDungeon->unk181e8.hallucinating  = ReadBool8(param_1);
    gDungeon->unk181e8.unk18211 = ReadBool8(param_1);
    gDungeon->unk181e8.unk18213 = ReadBool8(param_1);
}

void RestoreDungeonMusic(DataSerializer *r0)
{
    gDungeon->musPlayer.songIndex = ReadS16(r0);
    gDungeon->musPlayer.pastSongIndex = ReadS16(r0);
    gDungeon->musPlayer.queuedSongIndex = ReadS16(r0);
}

void RestoreItemData(DataSerializer *r0) {
    s32 index;
    Item item;
    Position pos;
    sub_8083018(r0, gMisakiSan);
    for(index = 0; index < DUNGEON_MAX_ITEMS; index++)
    {
        sub_80820A8(r0, &item);
        ReadPosition8(r0, &pos);
        if(item.flags & ITEM_FLAG_EXISTS)
            sub_80460F8(&pos, &item, 0);
    }
}

void sub_80820A8(DataSerializer *param_1, Item *item)
{
    memset(item, 0, sizeof(Item));
    ReadBytes(param_1,(u32 *)&item->flags,1);
    ReadBytes(param_1,(u32 *)&item->quantity,1);
    ReadBytes(param_1,(u32 *)&item->id,1);
}


void RestoreTrapData(DataSerializer *param_1)
{
    int counter;
    Tile *tile;
    Entity *entity;
    Position pos;
    u8 isVisible;
    u8 unk1;
    u8 trapID;

    sub_8083018(param_1, gMisakiSan);

    for(counter = 0; counter < DUNGEON_MAX_TRAPS; counter++)
    {
        trapID = 6;
        unk1 = 0;
        ReadBytes(param_1,(u32 *)&trapID,1);
        ReadBytes(param_1,(u32 *)&unk1,1);
        isVisible = ReadBool8(param_1);
        ReadPosition8(param_1, &pos);

        if(trapID != 0xFF)
        {
            tile = GetTileSafe(pos.x, pos.y);
            entity = sub_8045684(trapID, &pos, unk1);
            if(entity)
            {
                tile->object = entity;
                entity->isVisible = isVisible;
            }
        }
    }
}

void sub_808217C(DataSerializer *param_1)
{
    s32 counter;

    sub_8083018(param_1,gMisakiSan);
    gDungeon->unk37F0 = sub_80831A0(param_1);
    gDungeon->unk37F4 = sub_80831A0(param_1);
    gDungeon->plusIsActive[0] = ReadBool8(param_1);
    gDungeon->plusIsActive[1] = ReadBool8(param_1);
    gDungeon->minusIsActive[0] = ReadBool8(param_1);
    gDungeon->minusIsActive[1] = ReadBool8(param_1);
    gDungeon->decoyActive = ReadBool8(param_1);
    gDungeon->unk37FD = ReadBool8(param_1);
    gDungeon->deoxysDefeat = ReadBool8(param_1);
    gDungeon->unk37FF = ReadBool8(param_1);
    gDungeon->unk3800 = ReadU16(param_1);
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        RestoreDungeonEntity(param_1, TRUE, counter);
    }
    for(counter = 0; counter < DUNGEON_MAX_WILD_POKEMON; counter++)
    {
        RestoreDungeonEntity(param_1, FALSE, counter);
    }
}

// RestoreDungeonEntity should be here