#include "global.h"
#include "constants/dungeon_action.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "code_8092334.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "structs/str_position.h"


u16 sub_8083158(unkStruct_8094924 *param_1);
s16 sub_8083170(unkStruct_8094924 *param_1);
u8 sub_8083188(unkStruct_8094924 *param_1);
u32 sub_80831A0(unkStruct_8094924 *param_1);
bool8 sub_80831DC(unkStruct_8094924 *param_1);
void sub_8082FE0(unkStruct_8094924 *param_1, u8 *param_2, s32 size);
void sub_80831F8(unkStruct_8094924 *param_1,Position *param_2);

void AddPokemonDungeonSprite(u32, s16, Position *, u32);

void sub_8082B40(void)
{
  EntityInfo *info;
  Entity *entity;
  int index;
  Position pos;
  
  for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
  {
    entity = gDungeon->allPokemon[index];
    if (EntityExists(entity)) {
      info = entity->axObj.info;
      entity->axObj.spriteFile = GetSpriteData(info->apparentID);
      sub_806CCB4(entity,sub_806CEBC(entity));
      pos = entity->pos;
      AddPokemonDungeonSprite(info->unk98,info->apparentID,&pos,3);
      entity->room = GetTileSafe(entity->pos.x,entity->pos.y)->room;
    }
  }
}

s16 sub_8082BC0(unkStruct_8094924 *param_1)
{
    s16 temp[2];

    temp[0] = 0;

    sub_8082FE0(param_1, (u8 *)temp, 2);
    return temp[0];
}


u8 sub_8082BE0(unkStruct_8094924 *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    sub_8082FE0(param_1, temp, 1);
    return temp[0];
}


u8 sub_8082BFC(unkStruct_8094924 *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    sub_8082FE0(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082C18(unkStruct_8094924 *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    sub_8082FE0(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082C34(unkStruct_8094924 *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    sub_8082FE0(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082C50(unkStruct_8094924 *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    sub_8082FE0(param_1, temp, 1);
    return temp[0];
}

u32 sub_8082C6C(unkStruct_8094924 *param_1)
{
    u32 temp;

    temp = 0;

    sub_8082FE0(param_1, (u8 *)&temp, 4);
    return temp;
}

u8 sub_8082C84(unkStruct_8094924 *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    sub_8082FE0(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082CA0(unkStruct_8094924 *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    sub_8082FE0(param_1, temp, 1);
    return temp[0];
}

void sub_8082CBC(unkStruct_8094924 *param_1, ActionContainer *action)
{
    action->action = ACTION_NOTHING;
    sub_8082FE0(param_1, &action->direction, 1);
    action->fill3 = 7;
    sub_80831F8(param_1, &action->itemTargetPosition);
}

void sub_8082CE4(unkStruct_8094924 *param_1, AITarget *aitarget)
{
    sub_8082FE0(param_1, (u8 *)&aitarget->aiObjective, 1);
    aitarget->aiNotNextToTarget = sub_80831DC(param_1);
    aitarget->aiTargetingEnemy = sub_80831DC(param_1);
    aitarget->aiTurningAround = sub_80831DC(param_1);
    aitarget->aiTargetSpawnGenID = sub_8083158(param_1);
    aitarget->aiTarget = NULL;
    aitarget->unkC = 0;
    sub_80831F8(param_1, &aitarget->aiTargetPos);
}

void sub_8082D28(unkStruct_8094924 *param_1, u8 *param_2)
{
    sub_8082FE0(param_1, param_2, 3);
}

void sub_8082D34(unkStruct_8094924 *param_1, Sleep *sleep)
{
    sub_8082FE0(param_1, &sleep->sleep, 1);
    sleep->sleepTurns = sub_8083188(param_1);
}

void sub_8082D50(unkStruct_8094924 *param_1, NonVolatile *nonvoltaile)
{
    sub_8082FE0(param_1, &nonvoltaile->nonVolatileStatus, 1);
    nonvoltaile->nonVolatileStatusTurns = sub_8083188(param_1);
    nonvoltaile->nonVolatileStatusDamageCountdown = sub_8083188(param_1);
    nonvoltaile->unk4 = sub_8083188(param_1);
}

void sub_8082D7C(unkStruct_8094924 *param_1, Immobilize *immobilze)
{
    sub_8082FE0(param_1, &immobilze->immobilizeStatus, 1);
    immobilze->immobilizeStatusTurns = sub_8083188(param_1);
    immobilze->immobilizeStatusDamageCountdown = sub_8083188(param_1);
    immobilze->unk4 = sub_80831A0(param_1);
}

void sub_8082DA8(unkStruct_8094924 *param_1, Volatile *volatileStatus)
{
    sub_8082FE0(param_1, &volatileStatus->volatileStatus, 1);
    volatileStatus->volatileStatusTurns = sub_8083188(param_1);
}

void sub_8082DC4(unkStruct_8094924 *param_1, Charging *charging)
{
    sub_8082FE0(param_1, &charging->chargingStatus, 1);
    charging->chargingStatusTurns = sub_8083188(param_1);
    charging->chargingStatusMoveIndex = sub_8083188(param_1);
}

void sub_8082DE8(unkStruct_8094924 *param_1, Protection *protect)
{
    sub_8082FE0(param_1, &protect->protectionStatus, 1);
    protect->protectionStatusTurns = sub_8083188(param_1);
}

void sub_8082E04(unkStruct_8094924 *param_1, Waiting *waiting)
{
    sub_8082FE0(param_1, &waiting->waitingStatus, 1);
    waiting->enemyDecoy = sub_80831DC(param_1);
    waiting->unkCA = sub_80831DC(param_1);
    waiting->waitingStatusTurns = sub_8083188(param_1);
    waiting->curseDamageCountdown = sub_8083188(param_1);
}

void sub_8082E38(unkStruct_8094924 *param_1, Linked *linked)
{
    sub_8082FE0(param_1, &linked->linkedStatus, 1);
    linked->unkD4 = sub_80831A0(param_1);
    linked->unkD8 = sub_8083188(param_1);
    linked->linkedStatusTurns = sub_8083188(param_1);
    linked->linkedStatusDamageCountdown = sub_8083188(param_1);
}

void sub_8082E6C(unkStruct_8094924 *param_1, MoveStatus *moveStatus)
{
    sub_8082FE0(param_1, &moveStatus->moveStatus, 1);
    moveStatus->moveStatusTurns = sub_8083188(param_1);
}

void sub_8082E88(unkStruct_8094924 *param_1, u8 *param_2, s32 size)
{
    sub_8082FE0(param_1, param_2, 1);
}

void sub_8082E94(unkStruct_8094924 *param_1, TransformStatus *transform)
{
    sub_8082FE0(param_1, &transform->transformStatus, 1);
    transform->transformStatusTurns = sub_8083188(param_1);
}

void sub_8082EB0(unkStruct_8094924 *param_1, EyesightStatus *eyesight)
{
    sub_8082FE0(param_1, &eyesight->eyesightStatus, 1);
    eyesight->eyesightStatusTurns = sub_8083188(param_1);
}

void sub_8082ECC(unkStruct_8094924 *param_1, Muzzled *muzzle)
{
    sub_8082FE0(param_1, (u8 *)&muzzle->muzzled, 1);
    muzzle->muzzledTurns = sub_8083188(param_1);
}

void RestoreDungeonPokemonMove(unkStruct_8094924 *param_1, Move *move)
{
    move->moveFlags = sub_8083188(param_1);
    move->moveFlags2 = sub_8083188(param_1);
    sub_8082FE0(param_1, (u8 *)&move->id, 2);
    move->PP = sub_8083188(param_1);
    move->ginseng = sub_8083188(param_1);
}

void sub_8082F1C(unkStruct_8094924 *param_1,Move *moves)
{
    s32 index;
    Move *move;
    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &moves[index];
        RestoreDungeonPokemonMove(param_1, move);
    }
    *(u8 *)(moves + 4) = sub_8083188(param_1); // TODO: struggleMoveFlags again
}


void sub_8082F48(unkStruct_8094924 *param_1, u16 *r1)
{
    r1[0] = sub_8083170(param_1);
    r1[1] = sub_8083170(param_1);
}

void sub_8082F64(unkStruct_8094924 *param_1, JoinedAt *joined)
{
    joined->joinedAt = sub_8083188(param_1);
    joined->unk1 = sub_8083188(param_1);
}

void sub_8082F80(unkStruct_8094924 *param_1, HiddenPower *hidden)
{
    hidden->hiddenPowerBasePower = sub_8083170(param_1);
    hidden->hiddenPowerType = sub_8082BFC(param_1);
}

void sub_8082F9C(unkStruct_8094924 *param_1, u8 *r1, u32 r2)
{
    param_1->unk0 = r1;
    param_1->unk8 = 0;
    param_1->unk4 = r1 + r2;
}

void sub_8082FA8(unkStruct_8094924 *param_1, u8 *param_2, s32 size)
{
    while (size != 0) {
        *(param_1->unk0) = *param_2;
        param_1->unk0++;
        param_2++;
        size--;
        param_1->unk8++;
    } 
}

void sub_8082FD4(unkStruct_8094924 *param_1, u8 *r1, u32 r2)
{
    param_1->unk0 = r1;
    param_1->unk8 = 0;
    param_1->unk4 = r1 + r2;
}

void sub_8082FE0(unkStruct_8094924 *param_1, u8 *param_2, s32 size)
{
    while (size != 0) {
        *param_2 = *(param_1->unk0);
        param_1->unk0++;
        param_2++;
        size--;
        param_1->unk8++;
    } 
}

void nullsub_98(unkStruct_8094924 *param_1)
{}

void sub_808300C(unkStruct_8094924 *param_1, u8 *param_2)
{
    sub_8082FA8(param_1, param_2, 8);
}

void sub_8083018(unkStruct_8094924 *param_1)
{
    u8 auStack_10 [12];

    sub_8082FE0(param_1,auStack_10,8);
    auStack_10[8] = 0;
}

void sub_8083030(unkStruct_8094924 *param_1, u16 param_2)
{
    u16 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,(u8 *)&uStack_8,2);
}

void sub_8083048(unkStruct_8094924 *param_1, u32 param_2)
{
    u16 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,(u8 *)&uStack_8,2);
}

void sub_8083060(unkStruct_8094924 *param_1, u32 param_2)
{
    u8 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,&uStack_8,1);
}

void sub_8083078(unkStruct_8094924 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,(u8 *)&uStack_8,4);
}

void sub_808308C(unkStruct_8094924 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,(u8 *)&uStack_8,4);
}

void sub_80830A0(unkStruct_8094924 *param_1, u32 param_2)
{
    u32 uStack_8;

    uStack_8 = param_2;
    sub_8082FA8(param_1,(u8 *)&uStack_8,4);
}

void sub_80830B4(unkStruct_8094924 *param_1, u8 param_2)
{
    u8 local_8;

    local_8 = (param_2 != 0) ? -1 : 0;
    sub_8082FA8(param_1,&local_8,1);
}

void SavePosition(unkStruct_8094924 *param_1, Position *param_2)
{
    sub_8082FA8(param_1, (u8 *)&param_2->x, 1);
    sub_8082FA8(param_1, (u8 *)&param_2->y, 1);
}

void sub_80830F8(unkStruct_8094924 *param_1, u32 *param_2)
{
    sub_8082FA8(param_1, (u8 *)&param_2[0], 1);
    sub_8082FA8(param_1, (u8 *)&param_2[1], 1);
    sub_8082FA8(param_1, (u8 *)&param_2[2], 1);
    sub_8082FA8(param_1, (u8 *)&param_2[3], 1);
}

void sub_808312C(unkStruct_8094924 *param_1, u16 *param_2)
{
    sub_8082FA8(param_1, (u8 *)&param_2[0], 1);
    sub_8082FA8(param_1, (u8 *)&param_2[1], 1);
}

void SaveSpeedCounters(unkStruct_8094924 *param_1, u32 *speedCounters, u32 numCounters)
{
    sub_8082FA8(param_1, (u8 *)speedCounters, numCounters);
}

u16 sub_8083158(unkStruct_8094924 *param_1)
{
    u16 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,2);
    return local_8;
}

s16 sub_8083170(unkStruct_8094924 *param_1)
{
    s16 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,2);
    return local_8;
}

u8 sub_8083188(unkStruct_8094924 *param_1)
{
    u8 local_8;

    sub_8082FE0(param_1,&local_8,1);
    return local_8;
}

u32 sub_80831A0(unkStruct_8094924 *param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,4);
    return local_8;
}

u32 sub_80831B4(unkStruct_8094924 *param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,4);
    return local_8;
}

u32 sub_80831C8(unkStruct_8094924 *param_1)
{
    u32 local_8;

    sub_8082FE0(param_1,(u8 *)&local_8,4);
    return local_8;
}

bool8 sub_80831DC(unkStruct_8094924 *param_1)
{
    u8 local_8;

    sub_8082FE0(param_1,&local_8,1);
    return local_8 != 0;
}

void sub_80831F8(unkStruct_8094924 *param_1,Position *param_2)
{
    param_2->x = 0;
    param_2->y = 0;
    sub_8082FE0(param_1,(u8 *)&param_2->x,1);
    sub_8082FE0(param_1,(u8 *)&param_2->y,1);
}


void sub_8083220(unkStruct_8094924 *param_1,u32 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    sub_8082FE0(param_1,(u8 *)&param_2[0],1);
    sub_8082FE0(param_1,(u8 *)&param_2[1],1);
    sub_8082FE0(param_1,(u8 *)&param_2[2],1);
    sub_8082FE0(param_1,(u8 *)&param_2[3],1);
}

void sub_8083260(unkStruct_8094924 *param_1,u16 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    sub_8082FE0(param_1,(u8 *)&param_2[0],1);
    sub_8082FE0(param_1,(u8 *)&param_2[1],1);
}

void sub_8083288(unkStruct_8094924 *r0, u16 *r1, u32 size)
{
    sub_8082FE0(r0, (u8 *)r1, size);
}

