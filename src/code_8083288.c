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


u16 ReadU16(DataSerializer *param_1);
s16 ReadS16(DataSerializer *param_1);
u8 ReadU8(DataSerializer *param_1);
u32 sub_80831A0(DataSerializer *param_1);
bool8 ReadBool8(DataSerializer *param_1);
void ReadBytes(DataSerializer *param_1, void *param_2, s32 size);
void ReadPosition8(DataSerializer *param_1,Position *param_2);

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
      info = GetEntInfo(entity);
      entity->axObj.spriteFile = GetSpriteData(info->apparentID);
      sub_806CCB4(entity,sub_806CEBC(entity));
      pos = entity->pos;
      AddPokemonDungeonSprite(info->unk98,info->apparentID,&pos,3);
      entity->room = GetTileSafe(entity->pos.x,entity->pos.y)->room;
    }
  }
}








// Seems to be a new file (regarding serialization) starting here








s16 sub_8082BC0(DataSerializer *param_1)
{
    s16 temp[2];

    temp[0] = 0;

    ReadBytes(param_1, temp, 2);
    return temp[0];
}

u8 sub_8082BE0(DataSerializer *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082BFC(DataSerializer *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082C18(DataSerializer *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082C34(DataSerializer *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082C50(DataSerializer *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(param_1, temp, 1);
    return temp[0];
}

// Read some enum ?
u32 sub_8082C6C(DataSerializer *param_1)
{
    u32 temp;

    temp = 0;

    ReadBytes(param_1, &temp, 4);
    return temp;
}

u8 sub_8082C84(DataSerializer *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(param_1, temp, 1);
    return temp[0];
}

u8 sub_8082CA0(DataSerializer *param_1)
{
    u8 temp[4];

    temp[0] = 0;

    ReadBytes(param_1, temp, 1);
    return temp[0];
}

void ReadActionContainer(DataSerializer *param_1, ActionContainer *action)
{
    action->action = ACTION_NOTHING;
    ReadBytes(param_1, &action->direction, 1);
    action->unk3 = 7;
    ReadPosition8(param_1, &action->itemTargetPosition);
}

void ReadAITarget(DataSerializer *param_1, AITarget *aitarget)
{
    ReadBytes(param_1, &aitarget->aiObjective, 1);
    aitarget->aiNotNextToTarget = ReadBool8(param_1);
    aitarget->aiTargetingEnemy = ReadBool8(param_1);
    aitarget->aiTurningAround = ReadBool8(param_1);
    aitarget->aiTargetSpawnGenID = ReadU16(param_1);
    aitarget->aiTarget = NULL;
    aitarget->unkC = 0;
    ReadPosition8(param_1, &aitarget->aiTargetPos);
}

void Read3Bytes(DataSerializer *param_1, u8 *dst)
{
    ReadBytes(param_1, dst, 3);
}

void ReadSleep(DataSerializer *param_1, Sleep *sleep)
{
    ReadBytes(param_1, &sleep->sleep, 1);
    sleep->sleepTurns = ReadU8(param_1);
}

void ReadNonVolatile(DataSerializer *param_1, NonVolatile *nonvolatile)
{
    ReadBytes(param_1, &nonvolatile->nonVolatileStatus, 1);
    nonvolatile->nonVolatileStatusTurns = ReadU8(param_1);
    nonvolatile->nonVolatileStatusDamageCountdown = ReadU8(param_1);
    nonvolatile->unk4 = ReadU8(param_1);
}

void ReadImmobilize(DataSerializer *param_1, Immobilize *immobilize)
{
    ReadBytes(param_1, &immobilize->immobilizeStatus, 1);
    immobilize->immobilizeStatusTurns = ReadU8(param_1);
    immobilize->immobilizeStatusDamageCountdown = ReadU8(param_1);
    immobilize->unk4 = sub_80831A0(param_1);
}

void ReadVolatileStatus(DataSerializer *param_1, Volatile *volatileStatus)
{
    ReadBytes(param_1, &volatileStatus->volatileStatus, 1);
    volatileStatus->volatileStatusTurns = ReadU8(param_1);
}

void ReadCharging(DataSerializer *param_1, Charging *charging)
{
    ReadBytes(param_1, &charging->chargingStatus, 1);
    charging->chargingStatusTurns = ReadU8(param_1);
    charging->chargingStatusMoveIndex = ReadU8(param_1);
}

void ReadProtection(DataSerializer *param_1, Protection *protect)
{
    ReadBytes(param_1, &protect->protectionStatus, 1);
    protect->protectionStatusTurns = ReadU8(param_1);
}

void ReadWaiting(DataSerializer *param_1, Waiting *waiting)
{
    ReadBytes(param_1, &waiting->waitingStatus, 1);
    waiting->enemyDecoy = ReadBool8(param_1);
    waiting->unkCA = ReadBool8(param_1);
    waiting->waitingStatusTurns = ReadU8(param_1);
    waiting->curseDamageCountdown = ReadU8(param_1);
}

void ReadLinked(DataSerializer *param_1, Linked *linked)
{
    ReadBytes(param_1, &linked->linkedStatus, 1);
    linked->unkD4 = sub_80831A0(param_1);
    linked->unkD8 = ReadU8(param_1);
    linked->linkedStatusTurns = ReadU8(param_1);
    linked->linkedStatusDamageCountdown = ReadU8(param_1);
}

void ReadMoveStatus(DataSerializer *param_1, MoveStatus *moveStatus)
{
    ReadBytes(param_1, &moveStatus->moveStatus, 1);
    moveStatus->moveStatusTurns = ReadU8(param_1);
}

void sub_8082E88(DataSerializer *param_1, void *dst, s32 param_3)
{
    ReadBytes(param_1, dst, 1);
}

void ReadTransformStatus(DataSerializer *param_1, TransformStatus *transform)
{
    ReadBytes(param_1, &transform->transformStatus, 1);
    transform->transformStatusTurns = ReadU8(param_1);
}

void ReadEyesightStatus(DataSerializer *param_1, EyesightStatus *eyesight)
{
    ReadBytes(param_1, &eyesight->eyesightStatus, 1);
    eyesight->eyesightStatusTurns = ReadU8(param_1);
}

void ReadMuzzled(DataSerializer *param_1, Muzzled *muzzle)
{
    ReadBytes(param_1, &muzzle->muzzled, 1);
    muzzle->muzzledTurns = ReadU8(param_1);
}

void RestoreDungeonPokemonMove(DataSerializer *param_1, Move *move)
{
    move->moveFlags = ReadU8(param_1);
    move->moveFlags2 = ReadU8(param_1);
    ReadBytes(param_1, &move->id, 2);
    move->PP = ReadU8(param_1);
    move->ginseng = ReadU8(param_1);
}

void ReadMoves(DataSerializer *param_1, Moves *moves)
{
    s32 index;
    Move *move;

    for (index = 0; index < MAX_MON_MOVES; index++) {
        move = &moves->moves[index];
        RestoreDungeonPokemonMove(param_1, move);
    }

    moves->struggleMoveFlags = ReadU8(param_1);
}

// TODO: R1 struct
void sub_8082F48(DataSerializer *param_1, u16 *r1)
{
    r1[0] = ReadS16(param_1);
    r1[1] = ReadS16(param_1);
}

void ReadJoinedAt(DataSerializer *param_1, JoinedAt *joined)
{
    joined->joinedAt = ReadU8(param_1);
    joined->unk1 = ReadU8(param_1);
}

void ReadHiddenPower(DataSerializer *param_1, HiddenPower *hidden)
{
    hidden->hiddenPowerBasePower = ReadS16(param_1);
    hidden->hiddenPowerType = sub_8082BFC(param_1);
}

void InitByteWriter(DataSerializer *param_1, u8 *dst, u32 capacity)
{
    param_1->stream = dst;
    param_1->count = 0;
    param_1->end = dst + capacity;
}

void WriteBytes(DataSerializer *param_1, void *src, s32 numBytes)
{
    u8 *curByte;

    curByte = src;

    while (numBytes != 0) {
        *param_1->stream = *curByte;
        param_1->stream++;
        curByte++;
        numBytes--;
        param_1->count++;
    } 
}

void InitByteReader(DataSerializer *param_1, u8 *src, u32 length)
{
    param_1->stream = src;
    param_1->count = 0;
    param_1->end = src + length;
}

void ReadBytes(DataSerializer *param_1, void *dst, s32 numBytes)
{
    u8 *curByte;

    curByte = dst;

    while (numBytes != 0) {
        *curByte = *param_1->stream;
        param_1->stream++;
        curByte++;
        numBytes--;
        param_1->count++;
    } 
}

// Finished reading/writing dungeon
void nullsub_98(DataSerializer *param_1)
{
}

void Write8Bytes(DataSerializer *param_1, u8 *src)
{
    WriteBytes(param_1, src, 8);
}

void sub_8083018(DataSerializer *param_1)
{
    u8 auStack_10 [12];

    ReadBytes(param_1, auStack_10, 8);
    auStack_10[8] = 0;
}

void WriteU16(DataSerializer *param_1, u16 value)
{
    u16 uStack_8;

    uStack_8 = value;

    WriteBytes(param_1, &uStack_8, 2);
}

void WriteS16(DataSerializer *param_1, u32 value)
{
    u16 uStack_8;

    uStack_8 = value;

    WriteBytes(param_1, &uStack_8, 2);
}

void WriteU8(DataSerializer *param_1, u32 value)
{
    u8 uStack_8;

    uStack_8 = value;

    WriteBytes(param_1, &uStack_8, 1);
}

void WriteU32(DataSerializer *param_1, u32 value)
{
    u32 uStack_8;

    uStack_8 = value;

    WriteBytes(param_1, &uStack_8, 4);
}

UNUSED void sub_808308C(DataSerializer *param_1, u32 value)
{
    u32 uStack_8;

    uStack_8 = value;

    WriteBytes(param_1, &uStack_8, 4);
}

void WriteS32(DataSerializer *param_1, u32 value)
{
    u32 uStack_8;

    uStack_8 = value;

    WriteBytes(param_1, &uStack_8, 4);
}

void WriteBool8(DataSerializer *param_1, bool8 value)
{
    u8 local_8;

    local_8 = value ? -1 : 0;

    WriteBytes(param_1, &local_8, 1);
}

void WritePosition8(DataSerializer *param_1, Position *param_2)
{
    WriteBytes(param_1, &param_2->x, 1);
    WriteBytes(param_1, &param_2->y, 1);
}

// TODO: param_2 struct
void sub_80830F8(DataSerializer *param_1, u32 *param_2)
{
    WriteBytes(param_1, &param_2[0], 1);
    WriteBytes(param_1, &param_2[1], 1);
    WriteBytes(param_1, &param_2[2], 1);
    WriteBytes(param_1, &param_2[3], 1);
}

// TODO: param_2 struct
void sub_808312C(DataSerializer *param_1, u16 *param_2)
{
    WriteBytes(param_1, &param_2[0], 1);
    WriteBytes(param_1, &param_2[1], 1);
}

void xxx_WriteBytes(DataSerializer *param_1, void *src, u32 numBytes)
{
    WriteBytes(param_1, src, numBytes);
}

u16 ReadU16(DataSerializer *param_1)
{
    u16 local_8;

    ReadBytes(param_1, &local_8, 2);
    return local_8;
}

s16 ReadS16(DataSerializer *param_1)
{
    s16 local_8;

    ReadBytes(param_1, &local_8, 2);
    return local_8;
}

u8 ReadU8(DataSerializer *param_1)
{
    u8 local_8;

    ReadBytes(param_1, &local_8, 1);
    return local_8;
}

// ReadS32 or ReadU32 ?
u32 sub_80831A0(DataSerializer *param_1)
{
    u32 local_8;

    ReadBytes(param_1, &local_8, 4);
    return local_8;
}

UNUSED u32 sub_80831B4(DataSerializer *param_1)
{
    u32 local_8;

    ReadBytes(param_1, &local_8, 4);
    return local_8;
}

// ?
u32 sub_80831C8(DataSerializer *param_1)
{
    u32 local_8;

    ReadBytes(param_1, &local_8, 4);
    return local_8;
}

bool8 ReadBool8(DataSerializer *param_1)
{
    u8 local_8;

    ReadBytes(param_1, &local_8, 1);
    return local_8 != 0;
}

void ReadPosition8(DataSerializer *param_1, Position *param_2)
{
    param_2->x = 0;
    param_2->y = 0;
    ReadBytes(param_1, &param_2->x, 1);
    ReadBytes(param_1, &param_2->y, 1);
}

// TODO: param_2 struct
void sub_8083220(DataSerializer *param_1, u32 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    ReadBytes(param_1, &param_2[0], 1);
    ReadBytes(param_1, &param_2[1], 1);
    ReadBytes(param_1, &param_2[2], 1);
    ReadBytes(param_1, &param_2[3], 1);
}

// TODO: param_2 struct
void sub_8083260(DataSerializer *param_1, u16 *param_2)
{
    param_2[0] = 0;
    param_2[1] = 0;
    ReadBytes(param_1, &param_2[0], 1);
    ReadBytes(param_1, &param_2[1], 1);
}

void xxx_ReadBytes(DataSerializer *r0, u8 *dst, u32 numBytes)
{
    ReadBytes(r0, dst, numBytes);
}