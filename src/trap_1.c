#include "global.h"
#include "trap.h"
#include "code_806CD90.h"
#include "code_8092334.h"
#include "items.h"
#include "dungeon_util.h"
#include "structs/str_dungeon.h"
#include "structs/str_traps.h"

extern u8 gUnknown_81071E0[];
extern u8 gUnknown_81071D4[];

extern void sub_8082FA8(void *, void *, u32);

void sub_8081B60(void *, Tile *);
void sub_80830F8(void * , u32*);
void sub_808312C(void *, u32 *);
void sub_8081B94(void *, u8 *);
void sub_8083078(void *, u32);
void sub_80830B4(void *, u8);
void sub_8083030(void *, u16);
void sub_8080E0C(unkStruct_8094924 *, Entity *);
void sub_808300C(void *, u8 *);
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
void sub_8083060(void *, u32);
void sub_80817F4(unkStruct_8094924 *param_1, u32 param_2);
void sub_80830A0(void *, u32);
void sub_808180C(unkStruct_8094924 *param_1, u32 param_2);
void sub_8083048(void *, u32);
void sub_80818C8(unkStruct_8094924 *param_1, JoinedAt *param_2);
void sub_80817C8(unkStruct_8094924 *param_1, ActionContainer *param_2);
void sub_8081B34(void *, void *);
void sub_8081B08(void *, Move *);
void sub_8081824(unkStruct_8094924 *param_1, u32 param_2);
void sub_80817B0(unkStruct_8094924 *param_1, u32 param_2);
void SavePosition(void*, Position *);
void sub_80818E4(unkStruct_8094924 *param_1, AITarget* param_2);
void sub_8081B54(void *, u8 *);
void sub_808186C(unkStruct_8094924 *param_1, s32 param_2);
void sub_8081854(unkStruct_8094924 *param_1, s32 param_2);
void sub_808183C(unkStruct_8094924 *param_1, s32 param_2);
void sub_8081AB8(void *, bool8 *);
void sub_8081A9C(void *, u8*);
void sub_8081A80(void *, u8*);
void sub_8081A74(void *, u8*);
void sub_8081A58(void *, u8*);
void sub_8081A24(void *, u8*);
void sub_8081994(void *, u8*);
void sub_8081968(void *, u8*);
void sub_808193C(void *, u8*);
void sub_8081920(unkStruct_8094924 *param_1, Sleep* param_2);
void sub_8081880(unkStruct_8094924 *param_1, u8 param_2);
void SaveHiddenPower(unkStruct_8094924 *param_1, HiddenPower *param_2);
void sub_80819B0(void *, u8 *);
void sub_80819D4(void *, u8 *);
void sub_80819F0(void *, u8 *);
void SaveSpeedCounters(void *, u8 *, u32);
void sub_80818B8(unkStruct_8094924 *param_1, u8 param_2);
void sub_803E708(u32, u32);
void sub_80421C0(Entity *, u32);
void sub_804687C(Entity *, Position *, Position *, Item *, u32);

void HandleTripTrap(Entity *param_1, Entity *param_2)
{
    u32 direction;
    EntityInfo *info;
    Position pos;
    Item item;

    if (param_2 != NULL) {
        sub_806CDD4(param_2, 6, NUM_DIRECTIONS);
        sub_803E708(0x10, 0x55);
        sub_806CE68(param_2, NUM_DIRECTIONS);
        info = param_2->info;
        if ((info->heldItem).flags & ITEM_FLAG_EXISTS) {
            item =  (info->heldItem);
            (info->heldItem).flags = 0;
            FillInventoryGaps();
            sub_80421C0(param_2, 400);
            direction = (info->action).direction & DIRECTION_MASK;
            pos.x = (param_2->pos).x + gAdjacentTileOffsets[direction].x;
            pos.y =  (param_2->pos).y + gAdjacentTileOffsets[direction].y;
            sub_804687C(param_1, &param_2->pos, &pos, &item, 1);
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
    sub_808300C(&uStack_14,gUnknown_81071D4);
    nullsub_98(&uStack_14);
}

void sub_8080B90(unkStruct_8094924 *param_1)
{
    sub_808300C(param_1,gUnknown_81071E0);
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
    sub_808300C(param_1,gUnknown_81071E0);

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
    sub_808300C(param_1,gUnknown_81071E0);

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

    sub_808300C(param_1,gUnknown_81071E0);
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
        sub_8080E0C(param_1,gDungeon->teamPokemon[counter]);
    }
    for(counter = 0; counter < DUNGEON_MAX_WILD_POKEMON; counter++)
    {
        sub_8080E0C(param_1,gDungeon->wildPokemon[counter]);
    }
}

void sub_8080E0C(unkStruct_8094924 *param_1,Entity *param_2)
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
    u8 *puStack_88;
    u8 *puStack_84;
    u8 *puStack_80;
    u8 *puStack_7c;
    u8 *puStack_78;
    u8 *puStack_74;
    u8 *puStack_70;
    u8 *puStack_6c;
    u8 *puStack_68;
    u8 *puStack_64;
    u8 *puStack_60;
    bool8 *pbStack_5c;
    bool8 *pbStack_58;
    bool8 *pbStack_54;
    bool8 *pbStack_50;
    u8 *puStack_4c;
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
    sub_80817C8(param_1,&info->action);
    sub_808180C(param_1,info->types[0]);
    sub_808180C(param_1,info->types[1]);
    sub_8081824(param_1,info->abilities[0]);
    sub_8081824(param_1,info->abilities[1]);
    sub_8081788(param_1,&info->heldItem);
    sub_80817B0(param_1,info->fill64[0]);
    temp3 = &info->aiTarget;
    temp2 = info->IQSkillMenuFlags;
    temp1 = info->IQSkillFlags;
    puStack_a0 = &info->tactic;
    psStack_a4 = &info->hiddenPower;
    puStack_9c = &info->unk98;
    puStack_98 = &info->unk9C;
    puStack_94 = &info->unkA0;
    puStack_8c = &info->sleep;
    puStack_88 = &info->nonVolatileStatus;
    puStack_84 = &info->immobilizeStatus;
    puStack_80 = &info->volatileStatus;
    puStack_7c = &info->chargingStatus;
    puStack_78 = &info->protectionStatus;
    puStack_74 = &info->waitingStatus;
    puStack_70 = &info->linkedStatus;
    puStack_6c = &info->moveStatus;
    puStack_68 = &info->itemStatus;
    puStack_64 = &info->transformStatus;
    puStack_60 = &info->eyesightStatus;
    pbStack_5c = &info->muzzled;
    pbStack_58 = &info->powerEars;
    pbStack_54 = &info->scanning;
    pbStack_50 = &info->stairSpotter;
    puStack_4c = &info->fillF3;
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

    sub_80818E4(param_1,temp3);
    sub_8081B54(param_1,temp2);
    sub_8081B54(param_1,temp1);
    sub_8081880(param_1,*puStack_a0);
    SaveHiddenPower(param_1,psStack_a4);
    sub_8083078(param_1,*puStack_9c);
    sub_8083078(param_1,*puStack_98);
    sub_8083078(param_1,*puStack_94);
    sub_8081920(param_1,puStack_8c);
    sub_808193C(param_1,puStack_88);
    sub_8081968(param_1,puStack_84);
    sub_8081994(param_1,puStack_80);
    sub_80819B0(param_1,puStack_7c);
    sub_80819D4(param_1,puStack_78);
    sub_80819F0(param_1,puStack_74);
    sub_8081A24(param_1,puStack_70);
    sub_8081A58(param_1,puStack_6c);
    sub_8081A74(param_1,puStack_68);
    sub_8081A80(param_1,puStack_64);
    sub_8081A9C(param_1,puStack_60);
    sub_8081AB8(param_1,pbStack_5c);
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
    sub_808186C(param_1,info->speedStage);
    SaveSpeedCounters(param_1,info->speedUpCounters,NUM_SPEED_COUNTERS);
    SaveSpeedCounters(param_1,info->speedDownCounters,NUM_SPEED_COUNTERS);
    sub_8083060(param_1,info->stockpileStage);
    sub_8083060(param_1,info->fill113);
    sub_8083060(param_1,(u8)info->moveRandomly);
    sub_8081B08(param_1,info->moves);
    sub_8081B34(param_1,&info->belly);
    sub_8081B34(param_1,&info->maxBelly);
    sub_80830B4(param_1,info->aiNextToTarget);
    sub_80830B4(param_1,info->recalculateFollow);
    sub_80830B4(param_1,info->waiting);
    sub_80830B4(param_1,info->fill146);
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
    sub_80818B8(param_1,*puStack_90);
}

void sub_8081454(unkStruct_8094924 *param_1)
{
    int iVar1;
    int iVar2;
    int iVar4;

    sub_808300C(param_1,gUnknown_81071E0);
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
            sub_8081B60(param_1,&gDungeon->tiles[iVar1][iVar2]);
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
            sub_8081B60(param_1, &gDungeon->unkE27C[iVar1][iVar2]);
            sub_8083060(param_1, gDungeon->unkE87C[iVar1][iVar2]);
        }
    }
    sub_8081B94(param_1,&gDungeon->weather);
}

void sub_808165C(unkStruct_8094924 *param_1)
{

    sub_808300C(param_1,gUnknown_81071E0);
    sub_8083060(param_1, gDungeon->unk18208);
    sub_8083060(param_1, gDungeon->visibilityRange);
    sub_80830B4(param_1, gDungeon->blinded);
    sub_80830B4(param_1, gDungeon->unk1820B);
    sub_80830B4(param_1, gDungeon->unk1820C);
    sub_80830B4(param_1, gDungeon->unk1820D);
    sub_80830B4(param_1, gDungeon->unk1820E);
    sub_80830B4(param_1, gDungeon->unk1820F);
    sub_80830B4(param_1, gDungeon->hallucinating);
    sub_80830B4(param_1, gDungeon->unk18211);
    sub_80830B4(param_1, gDungeon->unk18213);
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

void sub_80817C8(unkStruct_8094924 *param_1, ActionContainer *param_2)
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

void sub_808186C(unkStruct_8094924 *param_1, s32 param_2)
{
    sub_8082FA8(param_1, &param_2, 4);
}

void sub_8081880(unkStruct_8094924 *param_1, u8 param_2)
{
    sub_8082FA8(param_1, &param_2, 1);
}

void SaveHiddenPower(unkStruct_8094924 *param_1, HiddenPower *param_2)
{
    sub_8083048(param_1, param_2->hiddenPowerBasePower);
    sub_808180C(param_1, param_2->hiddenPowerType);
}

void sub_80818B8(unkStruct_8094924 *param_1, u8 param_2)
{
    sub_8083060(param_1, param_2);
}

void sub_80818C8(unkStruct_8094924 *param_1, JoinedAt *param_2)
{
    sub_8083060(param_1, param_2->joinedAt);
    sub_8083060(param_1, param_2->unk1);
}

void sub_80818E4(unkStruct_8094924 *param_1, AITarget* param_2)
{
    sub_8082FA8(param_1, &param_2->aiObjective, 1);
    sub_80830B4(param_1, param_2->aiNotNextToTarget);
    sub_80830B4(param_1, param_2->aiTargetingEnemy);
    sub_80830B4(param_1, param_2->aiTurningAround);
    sub_8083030(param_1, param_2->aiTargetSpawnGenID);
    SavePosition(param_1, &param_2->aiTargetPos);
}

void sub_8081920(unkStruct_8094924 *param_1, Sleep* param_2)
{
    sub_8082FA8(param_1, &param_2->sleep, 1);
    sub_8083060(param_1, param_2->sleepTurns);
}
