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

extern void sub_8082FA8(unkStruct_8094924 *, void *, s32);

void SaveTile(unkStruct_8094924 *r0, Tile *tile);
void sub_80830F8(void * , u32*);
void sub_808312C(void *, u32 *);
void SaveDungeonWeather(unkStruct_8094924 *r0, Weather *weather);
void sub_8083078(void *, u32);
void sub_80830B4(void *, u8);
void sub_8083030(void *, u16);
void SaveEntity(unkStruct_8094924 *param_1, Entity *);
void sub_808300C(unkStruct_8094924 *param_1, u8 *);
void sub_8081788(unkStruct_8094924 *param_1, Item *param_2);
void sub_8080B90(unkStruct_8094924 *param_1);
void SaveItemData(unkStruct_8094924 *param_1);
void sub_8081454(unkStruct_8094924 *param_1);
void sub_808165C(unkStruct_8094924 *param_1);
void SaveDungeonMusic(unkStruct_8094924 *param_1);
void SaveTrapData(unkStruct_8094924 *param_1);
void sub_8080CF0(unkStruct_8094924 *param_1);
void nullsub_98(unkStruct_8094924 *param_1);
void sub_8082F9C(unkStruct_8094924 *param_1, u32, u32);
void sub_8049ED4(void);
void sub_8083060(unkStruct_8094924 *param_1, u32);
void sub_80817F4(unkStruct_8094924 *param_1, u32 param_2);
void sub_80830A0(unkStruct_8094924 *param_1, u32);
void sub_808180C(unkStruct_8094924 *param_1, u32 param_2);
void sub_8083048(unkStruct_8094924 *param_1, u32);
void sub_80818C8(unkStruct_8094924 *param_1, JoinedAt *param_2);
void SaveActionContainer(unkStruct_8094924 *param_1, ActionContainer *param_2);
void sub_8081B34(unkStruct_8094924 *r0, s16 *r1);
void SaveEntityMoves(unkStruct_8094924 *r0, Move *move);
void sub_8081824(unkStruct_8094924 *param_1, u32 param_2);
void sub_80817B0(unkStruct_8094924 *param_1, u32 param_2);
void SavePosition(void*, Position *);
void SaveAITargetStatus(unkStruct_8094924 *param_1, AITarget* param_2);
void SaveIQFlags(unkStruct_8094924 *r0, u8 *r1);
void SaveSpeedStage(unkStruct_8094924 *param_1, s32 param_2);
void sub_8081854(unkStruct_8094924 *param_1, s32 param_2);
void sub_808183C(unkStruct_8094924 *param_1, s32 param_2);
void SaveMuzzledStatus(unkStruct_8094924 *param_1, Muzzled *param_2);
void SaveEyesightStatus(unkStruct_8094924 *param_1, EyesightStatus *param_2);
void SaveTransformStatus(unkStruct_8094924 *param_1, TransformStatus *param_2);
void SaveItemStatus(unkStruct_8094924 *param_1, ItemStatus *param_2);
void SaveMoveStatus(unkStruct_8094924 *param_1, MoveStatus* param_2);
void SaveLinkedStatus(unkStruct_8094924 *param_1, Linked *param_2);
void SaveVolatileStatus(unkStruct_8094924 *param_1, Volatile *param_2);
void SaveImmobilizeStatus(unkStruct_8094924 *param_1, Immobilize *param_2);
void SaveNonVolatileStatus(unkStruct_8094924 *param_1, NonVolatile *param_2);
void SaveEntitySleep(unkStruct_8094924 *param_1, Sleep* param_2);
void SaveTactic(unkStruct_8094924 *param_1, u8 param_2);
void SaveDungeonHiddenPower(unkStruct_8094924 *param_1, HiddenPower *param_2);
void SaveChargingStatus(unkStruct_8094924 *param_1, Charging *param_2);
void SaveProtectionStatus(unkStruct_8094924 *param_1, Protection *param_2);
void SaveWaitingStatus(unkStruct_8094924 *param_1, Waiting *param_2);
void SaveSpeedCounters(unkStruct_8094924 *param_1, u8 *speedCounters, u32 numCounters);
void SaveClientType(unkStruct_8094924 *param_1, u8 param_2);
void sub_80421C0(Entity *, u16);
void sub_804687C(Entity *, Position *, Position *, Item *, u32);
extern void sub_8083018(unkStruct_8094924 *, u8 *);
extern void sub_8081C50(unkStruct_8094924 *);
extern void sub_8081C7C(unkStruct_8094924 *);
extern void sub_8081F2C(unkStruct_8094924 *);
extern void RestoreDungeonMusic(unkStruct_8094924 *);
extern void RestoreItemData(unkStruct_8094924 *);
extern void RestoreTrapData(unkStruct_8094924 *);
extern void sub_808217C(unkStruct_8094924 *);
extern void sub_8082FD4(unkStruct_8094924 *param_1, u8 *r1, u32 r2);
extern void sub_8082FE0(unkStruct_8094924 *, u32 *, u32);
u8 sub_80831DC(unkStruct_8094924 *r0);
u8 sub_8083188(unkStruct_8094924 *r0);
s16 sub_8083170(unkStruct_8094924 *r0);
void sub_80831F8(unkStruct_8094924 *r0, Position *);
void RestoreDungeonWeather(unkStruct_8094924 *r0, Weather *);
void sub_8083220(unkStruct_8094924 *r0, u32 *);
void sub_8083260(unkStruct_8094924 *r0, u32 *);
void RestoreTile(unkStruct_8094924 *r0, Tile *);
extern u16 sub_8083158(unkStruct_8094924 *param_1);
void sub_80820A8(unkStruct_8094924 *r0, Item *);
void sub_80460F8(Position *, Item *, u32);
Entity *sub_8045684(u8, Position *, u8);
u32 sub_80831A0(unkStruct_8094924 *param_1);
void sub_8082280(unkStruct_8094924 *param_1,bool8 isTeamMember,s32 index);

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
        info = target->info;
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

void sub_8080B30(u32 param_1,u32 param_2)
{
    unkStruct_8094924 uStack_14;

    sub_8082F9C(&uStack_14,param_1,param_2);
    uStack_14.unkC = 0;
    sub_8082FA8(&uStack_14,&uStack_14.unkC,4);
    sub_8080B90(&uStack_14);
    sub_8081454(&uStack_14);
    sub_808165C(&uStack_14);
    SaveDungeonMusic(&uStack_14);
    SaveItemData(&uStack_14);
    SaveTrapData(&uStack_14);
    sub_8080CF0(&uStack_14);
    sub_808300C(&uStack_14,gYayoiSan);
    nullsub_98(&uStack_14);
}

void sub_8080B90(unkStruct_8094924 *param_1)
{
    sub_808300C(param_1,gMisakiSan);
    sub_8082FA8(param_1,&gDungeon->dungeonLocation,0x58);
}

void SaveItemData(unkStruct_8094924 *param_1)
{
    bool8 flag;
    Item *item;
    Entity *entity;
    int counter;
    u8 local_1c [5];

    for(counter = 0; counter < 5; counter++)
    {
        local_1c[counter] = 0;
    }
    sub_808300C(param_1,gMisakiSan);

    for(counter = 0; counter < DUNGEON_MAX_ITEMS; counter++)
    {
        entity = gDungeon->items[counter];
        flag = FALSE;
        if ((entity != NULL) && (GetEntityType(entity) == ENTITY_ITEM)) {
            item = GetItemData(entity);
            sub_8081788(param_1,item);
            sub_8082FA8(param_1,&entity->pos.x,1);
            sub_8082FA8(param_1,&entity->pos.y,1);
            flag = TRUE;
        }
        if (!flag) {
            sub_8082FA8(param_1,local_1c,5);
        }
    }
}

void SaveTrapData(unkStruct_8094924 *param_1)
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
    sub_808300C(param_1,gMisakiSan);

    for(counter = 0; counter < DUNGEON_MAX_TRAPS; counter++)
    {
        entity = gDungeon->traps[counter];
        flag = FALSE;
        if ((entity != NULL) && (GetEntityType(entity) == ENTITY_TRAP)) {
            trap = GetTrapData(entity);
            sub_8082FA8(param_1,&trap->id,1);
            sub_8082FA8(param_1,&trap->unk1,1);
            sub_8082FA8(param_1,&entity->isVisible,1);
            sub_8082FA8(param_1,&entity->pos.x,1);
            sub_8082FA8(param_1,&entity->pos.y,1);
            flag = TRUE;
        }
        if (!flag) {
            sub_8082FA8(param_1,local_1c,5);
        }
    }
}

void sub_8080CF0(unkStruct_8094924 *param_1)
{
    s32 counter;

    sub_808300C(param_1,gMisakiSan);
    sub_8083078(param_1,gDungeon->unk37F0);
    sub_8083078(param_1,gDungeon->unk37F4);
    sub_80830B4(param_1,gDungeon->plusIsActive[0]);
    sub_80830B4(param_1,gDungeon->plusIsActive[1]);
    sub_80830B4(param_1,gDungeon->minusIsActive[0]);
    sub_80830B4(param_1,gDungeon->minusIsActive[1]);
    sub_80830B4(param_1,gDungeon->decoyActive);
    sub_80830B4(param_1,gDungeon->fill37FD);
    sub_80830B4(param_1,gDungeon->deoxysDefeat);
    sub_80830B4(param_1,gDungeon->fill37FF);
    sub_8083030(param_1,gDungeon->unk3800);
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        SaveEntity(param_1,gDungeon->teamPokemon[counter]);
    }
    for(counter = 0; counter < DUNGEON_MAX_WILD_POKEMON; counter++)
    {
        SaveEntity(param_1,gDungeon->wildPokemon[counter]);
    }
}

void SaveEntity(unkStruct_8094924 *param_1, Entity *param_2)
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
    sub_8083060(param_1,0xaa);
    sub_8083060(param_1,0x55);
    if (EntityExists(param_2)) {
        info = param_2->info;
        sub_8082FA8(param_1,&uStack_ac,1);
        sub_8082FA8(param_1,&param_2->pos.x,1);
        sub_8082FA8(param_1,&param_2->pos.y,1);
        sub_8082FA8(param_1,&param_2->isVisible,1);
        sub_8082FA8(param_1,&param_2->spawnGenID,2);
    }
    else {
        memset(&info2,0,sizeof(EntityInfo));
        info = &info2;
        sub_8082FA8(param_1,&uStack_a8,1);
        sub_8082FA8(param_1,&uStack_a8,1);
        sub_8082FA8(param_1,&uStack_a8,1);
        sub_8082FA8(param_1,&uStack_a8,1);
        sub_8082FA8(param_1,&uStack_a8,2);
    }
    sub_8083030(param_1,info->flags);
    sub_80817F4(param_1,info->apparentID);
    sub_80817F4(param_1,info->id);
    sub_80830B4(param_1,info->isNotTeamMember);
    sub_80830B4(param_1,info->isTeamLeader);
    sub_8083060(param_1,info->shopkeeper);
    sub_8083060(param_1,info->level);
    sub_8083060(param_1,info->teamIndex);
    sub_80818C8(param_1,&info->joinedAt);
    sub_8083048(param_1,info->IQ);
    sub_8083048(param_1,info->HP);
    sub_8083048(param_1,info->maxHPStat);
    sub_8083048(param_1,info->originalHP);
    sub_8083060(param_1,info->atk);
    sub_8083060(param_1,info->spAtk);
    sub_8083060(param_1,info->def);
    sub_8083060(param_1,info->spDef);
    sub_8083078(param_1,info->exp);
    sub_8083048(param_1,info->offensiveStages[0]);
    sub_8083048(param_1,info->offensiveStages[1]);
    sub_8083048(param_1,info->defensiveStages[0]);
    sub_8083048(param_1,info->defensiveStages[1]);
    sub_8083048(param_1,info->hitChanceStages[0]);
    sub_8083048(param_1,info->hitChanceStages[1]);
    sub_8083048(param_1,info->flashFireBoost);
    sub_80830A0(param_1,info->offensiveMultipliers[0]);
    sub_80830A0(param_1,info->offensiveMultipliers[1]);
    sub_80830A0(param_1,info->defensiveMultipliers[0]);
    sub_80830A0(param_1,info->defensiveMultipliers[1]);
    SaveActionContainer(param_1,&info->action);
    sub_808180C(param_1,info->types[0]);
    sub_808180C(param_1,info->types[1]);
    sub_8081824(param_1,info->abilities[0]);
    sub_8081824(param_1,info->abilities[1]);
    sub_8081788(param_1,&info->heldItem);
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
    puStack_34 = &info->unkFB;
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
        SavePosition(param_1,pos);
        pos++;
    }

    SaveAITargetStatus(param_1,temp3);
    SaveIQFlags(param_1,temp2);
    SaveIQFlags(param_1,temp1);
    SaveTactic(param_1,*puStack_a0);
    SaveDungeonHiddenPower(param_1,psStack_a4);
    sub_8083078(param_1,*puStack_9c);
    sub_8083078(param_1,*puStack_98);
    sub_8083078(param_1,*puStack_94);
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
    sub_80830B4(param_1,*pbStack_58);
    sub_80830B4(param_1,*pbStack_54);
    sub_80830B4(param_1,*pbStack_50);
    sub_80830B4(param_1,*puStack_4c);
    sub_80830B4(param_1,*pbStack_48);
    sub_8083060(param_1,*puStack_34);
    sub_80830B4(param_1,*pbStack_44);
    sub_80830B4(param_1,*pbStack_40);
    sub_80830B4(param_1,*pbStack_3c);
    sub_8083060(param_1,*puStack_38);
    sub_80830B4(param_1,*pbStack_30);
    sub_8083060(param_1,*puStack_2c);
    sub_8083060(param_1,*puStack_28);
    sub_808183C(param_1,*puStack_24);
    sub_8081854(param_1,info->targetingDecoy);
    SaveSpeedStage(param_1,info->speedStage);
    SaveSpeedCounters(param_1,info->speedUpCounters,NUM_SPEED_COUNTERS);
    SaveSpeedCounters(param_1,info->speedDownCounters,NUM_SPEED_COUNTERS);
    sub_8083060(param_1,info->stockpileStage);
    sub_8083060(param_1,info->unk113);
    sub_8083060(param_1,(u8)info->moveRandomly);
    SaveEntityMoves(param_1,info->moves);
    sub_8081B34(param_1,(s16 *)&info->belly);
    sub_8081B34(param_1,(s16 *)&info->maxBelly);
    sub_80830B4(param_1,info->aiNextToTarget);
    sub_80830B4(param_1,info->recalculateFollow);
    sub_80830B4(param_1,info->waiting);
    sub_80830B4(param_1,info->unk146);
    sub_80830B4(param_1,info->attacking);
    sub_80830B4(param_1,info->unk149);
    sub_80830B4(param_1,info->unk14A);
    sub_80830B4(param_1,info->unk14B);
    sub_80830B4(param_1,info->unk14C);
    sub_8083030(param_1,info->visualFlags);
    sub_8083030(param_1,info->previousVisualFlags);
    sub_80830B4(param_1,info->unk152);
    sub_8083060(param_1,info->unk153);
    sub_80830B4(param_1,info->unk154);
    sub_80830B4(param_1,info->unk155);
    sub_80830B4(param_1,info->unk156);
    sub_8083060(param_1,info->unk164);
    sub_8083060(param_1,info->unk165);
    sub_8083060(param_1,info->unk166);
    sub_8083060(param_1,info->unk167);
    sub_8083060(param_1,info->unk168);
    sub_8083060(param_1,info->turnsSinceWarpScarfActivation);
    SavePosition(param_1,&(info->targetPos));
    sub_80830A0(param_1,info->unk174);
    sub_8083030(param_1,info->unk178);
    sub_8083048(param_1,info->unk1F8);
    sub_8083048(param_1,info->mobileTurnTimer);
    sub_8083078(param_1,info->expGainedInTurn);
    SaveClientType(param_1,*puStack_90);
}

void sub_8081454(unkStruct_8094924 *param_1)
{
    int iVar1;
    int iVar2;
    int iVar4;

    sub_808300C(param_1,gMisakiSan);
    sub_80830B4(param_1, gDungeon->unk3A08);
    sub_80830B4(param_1, gDungeon->unk3A09);
    sub_80830B4(param_1, gDungeon->unk3A0A);
    sub_80830B4(param_1, gDungeon->unk3A0B);
    sub_8083060(param_1, gDungeon->unk3A0C);
    sub_8083060(param_1, gDungeon->unk3A0D);
    sub_8083048(param_1, gDungeon->tileset);
    sub_8083048(param_1,gDungeon->unk3A10);
    sub_8083048(param_1, gDungeon->unk3A12);
    sub_8083048(param_1, gDungeon->bossBattleIndex);
    sub_8083048(param_1, gDungeon->unk3A16);
    for(iVar1 = 0; iVar1 < DUNGEON_MAX_SIZE_Y; iVar1++)
    {

        for(iVar2 = 0; iVar2 < DUNGEON_MAX_SIZE_X; iVar2++)
        {
            SaveTile(param_1,&gDungeon->tiles[iVar1][iVar2]);
        }
    }


    SavePosition(param_1,&gDungeon->unkE218);
    SavePosition(param_1,&gDungeon->unkE21C);



    for(iVar4 = 0; iVar4 < 8; iVar4++)
    {
        SavePosition(param_1,&gDungeon->unkE220[iVar4]);
    }
    sub_80830F8(param_1,&gDungeon->unkE240);
    sub_80830F8(param_1,&gDungeon->unkE250);
    sub_808312C(param_1,&gDungeon->unkE260);

    for(iVar1 = 0; iVar1 < 8; iVar1++)
    {
        for(iVar2 = 0; iVar2 < 8; iVar2++)
        {
            SaveTile(param_1, &gDungeon->unkE27C[iVar1][iVar2]);
            sub_8083060(param_1, gDungeon->unkE87C[iVar1][iVar2]);
        }
    }
    SaveDungeonWeather(param_1,&gDungeon->weather);
}

void sub_808165C(unkStruct_8094924 *param_1)
{

    sub_808300C(param_1,gMisakiSan);
    sub_8083060(param_1, gDungeon->unk181e8.unk18208);
    sub_8083060(param_1, gDungeon->unk181e8.visibilityRange);
    sub_80830B4(param_1, gDungeon->unk181e8.blinded);
    sub_80830B4(param_1, gDungeon->unk181e8.unk1820B);
    sub_80830B4(param_1, gDungeon->unk181e8.unk1820C);
    sub_80830B4(param_1, gDungeon->unk181e8.unk1820D);
    sub_80830B4(param_1, gDungeon->unk181e8.unk1820E);
    sub_80830B4(param_1, gDungeon->unk181e8.unk1820F);
    sub_80830B4(param_1, gDungeon->unk181e8.hallucinating);
    sub_80830B4(param_1, gDungeon->unk181e8.unk18211);
    sub_80830B4(param_1, gDungeon->unk181e8.unk18213);
}

// NOTE: forcing this s16 for now - Seth
void SaveDungeonMusic(unkStruct_8094924 *param_1)
{
    sub_8083048(param_1, (s16)gDungeon->musPlayer.songIndex);
    sub_8083048(param_1, (s16)gDungeon->musPlayer.pastSongIndex);
    sub_8083048(param_1, (s16)gDungeon->musPlayer.queuedSongIndex);
}

void sub_8081788(unkStruct_8094924 *param_1, Item *param_2)
{
    sub_8082FA8(param_1, &param_2->flags, 1);
    sub_8082FA8(param_1, &param_2->quantity, 1);
    sub_8082FA8(param_1, &param_2->id, 1);
}

void sub_80817B0(unkStruct_8094924 *param_1, u32 param_2)
{
    u8 stack;
    stack = param_2;
    sub_8082FA8(param_1, &stack, 1);
}

void SaveActionContainer(unkStruct_8094924 *param_1, ActionContainer *param_2)
{
    sub_8082FA8(param_1, &param_2->direction, 1);
    sub_8082FA8(param_1, &param_2->itemTargetPosition.x, 1);
    sub_8082FA8(param_1, &param_2->itemTargetPosition.y, 1);
}

void sub_80817F4(unkStruct_8094924 *param_1, u32 param_2)
{
    u16 stack;
    stack = param_2;
    sub_8082FA8(param_1, &stack, 2);
}

void sub_808180C(unkStruct_8094924 *param_1, u32 param_2)
{
    u8 stack;
    stack = param_2;
    sub_8082FA8(param_1, &stack, 1);
}

void sub_8081824(unkStruct_8094924 *param_1, u32 param_2)
{
    u8 stack;
    stack = param_2;
    sub_8082FA8(param_1, &stack, 1);
}

void sub_808183C(unkStruct_8094924 *param_1, s32 param_2)
{
    u8 stack;
    stack = param_2;
    sub_8082FA8(param_1, &stack, 1);
}

void sub_8081854(unkStruct_8094924 *param_1, s32 param_2)
{
    u8 stack;
    stack = param_2;
    sub_8082FA8(param_1, &stack, 1);
}

void SaveSpeedStage(unkStruct_8094924 *param_1, s32 param_2)
{
    sub_8082FA8(param_1, &param_2, 4);
}

void SaveTactic(unkStruct_8094924 *param_1, u8 param_2)
{
    sub_8082FA8(param_1, &param_2, 1);
}

void SaveDungeonHiddenPower(unkStruct_8094924 *param_1, HiddenPower *param_2)
{
    sub_8083048(param_1, param_2->hiddenPowerBasePower);
    sub_808180C(param_1, param_2->hiddenPowerType);
}

void SaveClientType(unkStruct_8094924 *param_1, u8 param_2)
{
    sub_8083060(param_1, param_2);
}

void sub_80818C8(unkStruct_8094924 *param_1, JoinedAt *param_2)
{
    sub_8083060(param_1, param_2->joinedAt);
    sub_8083060(param_1, param_2->unk1);
}

void SaveAITargetStatus(unkStruct_8094924 *param_1, AITarget* param_2)
{
    sub_8082FA8(param_1, &param_2->aiObjective, 1);
    sub_80830B4(param_1, param_2->aiNotNextToTarget);
    sub_80830B4(param_1, param_2->aiTargetingEnemy);
    sub_80830B4(param_1, param_2->aiTurningAround);
    sub_8083030(param_1, param_2->aiTargetSpawnGenID);
    SavePosition(param_1, &param_2->aiTargetPos);
}

void SaveEntitySleep(unkStruct_8094924 *param_1, Sleep* param_2)
{
    sub_8082FA8(param_1, &param_2->sleep, 1);
    sub_8083060(param_1, param_2->sleepTurns);
}

void SaveNonVolatileStatus(unkStruct_8094924 *param_1, NonVolatile *param_2)
{
    sub_8082FA8(param_1, &param_2->nonVolatileStatus, 1);
    sub_8083060(param_1, param_2->nonVolatileStatusTurns);
    sub_8083060(param_1, param_2->nonVolatileStatusDamageCountdown);
    sub_8083060(param_1, param_2->unk4);
}

void SaveImmobilizeStatus(unkStruct_8094924 *param_1, Immobilize *param_2)
{
    sub_8082FA8(param_1, &param_2->immobilizeStatus, 1);
    sub_8083060(param_1, param_2->immobilizeStatusTurns);
    sub_8083060(param_1, param_2->immobilizeStatusDamageCountdown);
    sub_8083078(param_1, param_2->unk4);
}

void SaveVolatileStatus(unkStruct_8094924 *param_1, Volatile *param_2)
{
    sub_8082FA8(param_1, &param_2->volatileStatus, 1);
    sub_8083060(param_1, param_2->volatileStatusTurns);
}

void SaveChargingStatus(unkStruct_8094924 *param_1, Charging *param_2)
{
    sub_8082FA8(param_1, &param_2->chargingStatus, 1);
    sub_8083060(param_1, param_2->chargingStatusTurns);
    sub_8083060(param_1, param_2->chargingStatusMoveIndex);
}

void SaveProtectionStatus(unkStruct_8094924 *param_1, Protection *param_2)
{
    sub_8082FA8(param_1, &param_2->protectionStatus, 1);
    sub_8083060(param_1, param_2->protectionStatusTurns);
}

void SaveWaitingStatus(unkStruct_8094924 *param_1, Waiting *param_2)
{
    sub_8082FA8(param_1, &param_2->waitingStatus, 1);
    sub_80830B4(param_1, param_2->enemyDecoy);
    sub_80830B4(param_1, param_2->unkCA);
    sub_8083060(param_1, param_2->waitingStatusTurns);
    sub_8083060(param_1, param_2->curseDamageCountdown);
}

void SaveLinkedStatus(unkStruct_8094924 *param_1, Linked *param_2)
{
    sub_8082FA8(param_1, &param_2->linkedStatus, 1);
    sub_8083078(param_1, param_2->unkD4);
    sub_8083060(param_1, param_2->unkD8);
    sub_8083060(param_1, param_2->linkedStatusTurns);
    sub_8083060(param_1, param_2->linkedStatusDamageCountdown);
}

void SaveMoveStatus(unkStruct_8094924 *param_1, MoveStatus* param_2)
{
    sub_8082FA8(param_1, &param_2->moveStatus, 1);
    sub_8083060(param_1, param_2->moveStatusTurns);
}

void SaveItemStatus(unkStruct_8094924 *param_1, ItemStatus *param_2)
{
    sub_8082FA8(param_1, &param_2->itemStatus, 1);
}

void SaveTransformStatus(unkStruct_8094924 *param_1, TransformStatus *param_2)
{
    sub_8082FA8(param_1, &param_2->transformStatus, 1);
    sub_8083060(param_1, param_2->transformStatusTurns);
}

void SaveEyesightStatus(unkStruct_8094924 *param_1, EyesightStatus *param_2)
{
    sub_8082FA8(param_1, &param_2->eyesightStatus, 1);
    sub_8083060(param_1, param_2->eyesightStatusTurns);
}

void SaveMuzzledStatus(unkStruct_8094924 *param_1, Muzzled *param_2)
{
    sub_8082FA8(param_1, &param_2->muzzled, 1);
    sub_8083060(param_1, param_2->muzzledTurns);
}

void SaveEntityMove(unkStruct_8094924 *r0, Move *r1)
{
    sub_8083060(r0, r1->moveFlags);
    sub_8083060(r0, r1->moveFlags2);
    sub_8082FA8(r0, &r1->id, 2);
    sub_8083060(r0, r1->PP);
    sub_8083060(r0, r1->ginseng);
}

void SaveEntityMoves(unkStruct_8094924 *r0, Move *move)
{
    s32 index;
    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        SaveEntityMove(r0, &move[index]);
    }
    sub_8083060(r0, *(u8 *)(move + 0x4)); // Struggle Move flags?
}

void sub_8081B34(unkStruct_8094924 *r0, s16 *r1)
{
    sub_8083048(r0, r1[0]);
    sub_8083048(r0, r1[1]);
}

void SaveIQFlags(unkStruct_8094924 *r0, u8 *r1)
{
    sub_8082FA8(r0, r1, 3);
}

void SaveTile(unkStruct_8094924 *r0, Tile *tile)
{
    sub_8083030(r0, tile->terrainType);
    sub_8083030(r0, tile->unk4);
    sub_8082FA8(r0, &tile->room, 1);
    sub_8082FA8(r0, &tile->unkE, 1);
}

void SaveDungeonWeather(unkStruct_8094924 *r0, Weather *weather)
{
    s32 index;
    sub_8082FA8(r0, &weather->weather, 1);
    sub_8082FA8(r0, &weather->unkE265, 1);
    for(index = 0; index < 8; index++)
    {
        sub_8083060(r0, weather->unkE267[index]);
        sub_8083060(r0, weather->naturalWeather[index]);
    }
    sub_8083060(r0, weather->weatherDamageCounter);
    sub_8083060(r0, weather->mudSportTurns);
    sub_8083060(r0, weather->waterSportTurns);
    sub_80830B4(r0, weather->nullifyWeather);
}

void sub_8081BF4(u8 *r0, u32 r1)
{
    unkStruct_8094924 uStack_14;

    sub_8082FD4(&uStack_14, r0, r1);

    sub_8082FE0(&uStack_14, &uStack_14.unkC, 4);
    sub_8081C50(&uStack_14);
    sub_8081C7C(&uStack_14);
    sub_8081F2C(&uStack_14);
    RestoreDungeonMusic(&uStack_14);
    RestoreItemData(&uStack_14);
    RestoreTrapData(&uStack_14);
    sub_808217C(&uStack_14);

    sub_8083018(&uStack_14, gYayoiSan);
    nullsub_98(&uStack_14);
}

void sub_8081C50(unkStruct_8094924 *r0)
{
    sub_8083018(r0, gMisakiSan);
    sub_8082FE0(r0, (u32 *)&gDungeon->dungeonLocation, 0x58);
}

void sub_8081C7C(unkStruct_8094924 *r0)
{
    int x;
    int y;
    s32 iVar7;

    sub_8083018(r0,gMisakiSan);
    gDungeon->unk3A08 = sub_80831DC(r0);
    gDungeon->unk3A09 = sub_80831DC(r0);
    gDungeon->unk3A0A = sub_80831DC(r0);
    gDungeon->unk3A0B = sub_80831DC(r0);
    gDungeon->unk3A0C = sub_8083188(r0);
    gDungeon->unk3A0D = sub_8083188(r0);
    gDungeon->tileset = sub_8083170(r0);
    gDungeon->unk3A10 = sub_8083170(r0);
    gDungeon->unk3A12 = sub_8083170(r0);
    gDungeon->bossBattleIndex = sub_8083170(r0);
    gDungeon->unk3A16 = sub_8083170(r0);

    for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
    {
        for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
        {
            RestoreTile(r0,&gDungeon->tiles[y][x]);
        }
    }
    sub_80831F8(r0,&gDungeon->unkE218);
    sub_80831F8(r0,&gDungeon->unkE21C);

    for(iVar7 = 0; iVar7 < 8; iVar7++)
    {
        sub_80831F8(r0,&gDungeon->unkE220[iVar7]);
    }
    sub_8083220(r0,&gDungeon->unkE240);
    sub_8083220(r0,&gDungeon->unkE240 + 0x4);
    sub_8083260(r0,&gDungeon->unkE240 + 0x8);


    for(y = 0; y < 8; y++)
    {
        for(x = 0; x < 8; x++)
        {
            RestoreTile(r0,&gDungeon->unkE27C[y][x]);
            gDungeon->unkE87C[y][x] = sub_8083188(r0);
        }
    }
    RestoreDungeonWeather(r0,&gDungeon->weather);
}

void RestoreTile(unkStruct_8094924 *r0, Tile *tile)
{
    memset(tile, 0, sizeof(Tile));
    tile->terrainType = sub_8083158(r0);
    tile->unk4 = sub_8083158(r0);

    sub_8082FE0(r0, (u32 *)&tile->room, 1);
    sub_8082FE0(r0, (u32 *)&tile->unkE, 1);

    tile->monster = NULL;
    tile->object = NULL;
}

void RestoreDungeonWeather(unkStruct_8094924 *r0, Weather *weather)
{
    s32 index;
    memset(weather, 0, sizeof(Weather));
    sub_8082FE0(r0, (u32 *)&weather->weather, 1);
    sub_8082FE0(r0, (u32 *)&weather->unkE265, 1);
    for(index = 0; index < 8; index++)
    {
        weather->unkE267[index] = sub_8083188(r0);
        weather->naturalWeather[index] = sub_8083188(r0);
    }
    weather->weatherDamageCounter = sub_8083188(r0);
    weather->mudSportTurns = sub_8083188(r0);
    weather->waterSportTurns = sub_8083188(r0);
    weather->nullifyWeather = sub_80831DC(r0);
}

void sub_8081F2C(unkStruct_8094924 *param_1)
{
    sub_8083018(param_1,gMisakiSan);
    gDungeon->unk181e8.cameraTarget = NULL;
    gDungeon->unk181e8.unk18208 = sub_8083188(param_1);
    gDungeon->unk181e8.visibilityRange = sub_8083188(param_1);
    gDungeon->unk181e8.blinded        = sub_80831DC(param_1);
    gDungeon->unk181e8.unk1820B       = sub_80831DC(param_1);
    gDungeon->unk181e8.unk1820C       = sub_80831DC(param_1);
    gDungeon->unk181e8.unk1820D       = sub_80831DC(param_1);
    gDungeon->unk181e8.unk1820E       = sub_80831DC(param_1);
    gDungeon->unk181e8.unk1820F       = sub_80831DC(param_1);
    gDungeon->unk181e8.hallucinating  = sub_80831DC(param_1);
    gDungeon->unk181e8.unk18211 = sub_80831DC(param_1);
    gDungeon->unk181e8.unk18213 = sub_80831DC(param_1);
}

void RestoreDungeonMusic(unkStruct_8094924 *r0)
{
    gDungeon->musPlayer.songIndex = sub_8083170(r0);
    gDungeon->musPlayer.pastSongIndex = sub_8083170(r0);
    gDungeon->musPlayer.queuedSongIndex = sub_8083170(r0);
}

void RestoreItemData(unkStruct_8094924 *r0) {
    s32 index;
    Item item;
    Position pos;
    sub_8083018(r0, gMisakiSan);
    for(index = 0; index < DUNGEON_MAX_ITEMS; index++)
    {
        sub_80820A8(r0, &item);
        sub_80831F8(r0, &pos);
        if(item.flags & ITEM_FLAG_EXISTS)
            sub_80460F8(&pos, &item, 0);
    }
}

void sub_80820A8(unkStruct_8094924 *param_1, Item *item)
{
    memset(item, 0, sizeof(Item));
    sub_8082FE0(param_1,(u32 *)&item->flags,1);
    sub_8082FE0(param_1,(u32 *)&item->quantity,1);
    sub_8082FE0(param_1,(u32 *)&item->id,1);
}


void RestoreTrapData(unkStruct_8094924 *param_1)
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
        sub_8082FE0(param_1,(u32 *)&trapID,1);
        sub_8082FE0(param_1,(u32 *)&unk1,1);
        isVisible = sub_80831DC(param_1);
        sub_80831F8(param_1, &pos);

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

void sub_808217C(unkStruct_8094924 *param_1)
{
    s32 counter;

    sub_8083018(param_1,gMisakiSan);
    gDungeon->unk37F0 = sub_80831A0(param_1);
    gDungeon->unk37F4 = sub_80831A0(param_1);
    gDungeon->plusIsActive[0] = sub_80831DC(param_1);
    gDungeon->plusIsActive[1] = sub_80831DC(param_1);
    gDungeon->minusIsActive[0] = sub_80831DC(param_1);
    gDungeon->minusIsActive[1] = sub_80831DC(param_1);
    gDungeon->decoyActive = sub_80831DC(param_1);
    gDungeon->fill37FD = sub_80831DC(param_1);
    gDungeon->deoxysDefeat = sub_80831DC(param_1);
    gDungeon->fill37FF = sub_80831DC(param_1);
    gDungeon->unk3800 = sub_8083158(param_1);
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        sub_8082280(param_1, TRUE, counter);
    }
    for(counter = 0; counter < DUNGEON_MAX_WILD_POKEMON; counter++)
    {
        sub_8082280(param_1, FALSE, counter);
    }
}

