#include "global.h"
#include "status_checker.h"

#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "charge_move.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "map.h"
#include "moves.h"
#include "number_util.h"
//#include "pokemon.h" // NOTE: overriding some of the funcs below... when fixed, uncomment this
#include "status.h"
#include "status_checks_1.h"
#include "team_inventory.h"
#include "text_util.h"
#include "tile_types.h"
#include "trap.h"
#include "weather.h"

extern void sub_807F43C(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_8078F50(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_807DC68(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_8077BB4(struct DungeonEntity *, struct DungeonEntity *, u8);
extern void sub_8078A58(struct DungeonEntity *, struct DungeonEntity *, s16, u32);
extern void sub_807885C(struct DungeonEntity *, struct DungeonEntity *);
extern u32 sub_803D73C(u32);
extern void sub_8045C28(struct ItemSlot *, u8 , u8 *);
extern void sub_80464C8(struct DungeonEntity *, struct Position *, struct ItemSlot *);
extern void sub_8068FE0(struct DungeonEntity *, u32, struct DungeonEntity *r2);
extern void sub_80522F4(struct DungeonEntity *r1, struct DungeonEntity *r2, const char []);
extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_807FC3C(struct Position *, u32, u32);
extern void sub_8042A64(struct Position *);
extern void sub_8040A84(void);
extern void sub_8049ED4(void);
extern void sub_80498A8(s32, s32);
extern void sub_806CF60();
extern void sub_8042A54(struct Position *);
extern void sub_8049BB0(s32, s32);
extern s16 sub_8057600(struct PokemonMove*, u32);
extern u32 sub_8055864(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *param_3, s32 param_4, s32 param_5);
extern void sub_807D148(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u32 r2, struct Position *r3);
extern void sub_807FE04(u32 *, u32);
extern void sub_807DB74(struct DungeonEntity *);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
extern void HandleLuminousOrbAction(struct DungeonEntity *pokemon);
extern void sub_8076D10(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_807D510(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_807DA14(struct DungeonEntity *, struct DungeonEntity *, s32);
extern s16 sub_803D970(u32);
extern u8 sub_806AA0C(s32, u32);
extern void sub_806BB6C(struct DungeonEntity *, s32);
extern void sub_8075C58(struct DungeonEntity *, struct DungeonEntity *, s32, s32);
extern void sub_807E254(struct DungeonEntity *, struct DungeonEntity *, u32);
extern bool8 sub_805727C(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 chance);
extern u32 sub_8055640(struct DungeonEntity *, struct DungeonEntity *, struct PokemonMove *, u32, u32);
extern void sub_806A6E8(struct DungeonEntity *);
extern void sub_807D3CC(struct DungeonEntity *, struct DungeonEntity *);
extern u8 sub_8069D18(s32 *);
extern u8 sub_804AD34(s32 *);
extern u8 sub_8057308(struct DungeonEntity *, u32);
extern void sub_8076F80(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32, u32);
extern void sub_8077084(struct DungeonEntity *, struct DungeonEntity *, u32, u32);
extern void SnatchStatusTarget(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_806F324(struct DungeonEntity *, s32, u32, u32);
extern void sub_8077160(struct DungeonEntity *, struct DungeonEntity *, u32, u32);
extern bool8 sub_805755C(struct DungeonEntity* pokemon,u16 moveID);
extern void sub_807614C(struct DungeonEntity *, struct DungeonEntity *, u32);
extern void DestinyBondStatusTarget(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_8076E20(struct DungeonEntity *, struct DungeonEntity *, u32, u32, u32, u32);
extern void sub_80783C4(struct DungeonEntity *, struct DungeonEntity *, u32);
extern bool8 sub_807FCD4(struct Position *, u32, u8);
extern void PerishSongTarget(struct DungeonEntity *, struct DungeonEntity *);
extern void WrapTarget(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_80768DC(struct DungeonEntity *, struct DungeonEntity *, s32, s32);
extern void sub_807CD9C(struct DungeonEntity *, struct DungeonEntity *, u8 facingDir);


// NOTE: Override pokemon.c types for these two funcs
// GetSizeOrbDmg is ok
extern u8 GetPokemonSize(s32 index);
extern void CopyCyanSpeciesNametoBuffer(u8 *buffer, s32 index);
extern u32 GetSizeOrbDmg(s16 index);

extern s16 gUnknown_80F55EC[];
extern s16 gUnknown_80F4DCE;
extern u8 *gUnknown_80FDD00[];
extern u8 *gUnknown_80FDCE4[];
extern u32 gUnknown_8106A50;
extern u8 *gPtrSleepingTargetOnlyMessage[];
extern u8 *gUnknown_80FAFF0[];
extern u32 gUnknown_80F4F58;
extern u32 gUnknown_8106A4C;
extern s16 gUnknown_80F4E74[];
extern u8 gAvailablePokemonNames[];
extern u8 *gUnknown_80FD450[];
extern u8 *gUnknown_80FD434[];
extern u8 gUnknown_202DFE8[];
extern s16 gUnknown_80F4F80;
extern u8 *gUnknown_80FF678[];
extern u8 *gUnknown_80FD0B8[];
extern u8 *gUnknown_80FD0B4[];
extern u8 *gUnknown_80FD454[];
extern s16 gUnknown_80F4FC6;
extern u8 *gUnknown_81004F0[];
extern u8 *gUnknown_80FD1CC[];
extern u8 *gUnknown_80FD1B0[];
extern u8 *gUnknown_80FD1EC[];
extern u8 *gUnknown_80FD4C4[];
extern u8 *gUnknown_80FD4DC[];
extern u8 *gUnknown_80FC920[];
extern u8 *gUnknown_80FC8F0[];
extern u8 *gUnknown_80FC614[];
extern u8 *gUnknown_80FC678[];
extern u8 *gUnknown_80FC654[];
extern u8 *gUnknown_80FD574[];
extern u8 *gUnknown_80FD430[];
extern u8 *gUnknown_80FD40C[];
extern u8 *gUnknown_80FD3F0[];
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4DDC;
extern s16 gUnknown_80F4F7E;
extern u8 *gUnknown_80FDCA0[];
extern u8 *gUnknown_80FDC9C[];
extern s16 gUnknown_80F4DD8;
extern u32 gUnknown_202F224;
extern u32 gUnknown_8106A8C[];
extern s16 gUnknown_80F4F94[];
extern u8 *gUnknown_80FC5A8[];
extern u8 *gPtrForecastPreventsTypeSwitchMessage[];
extern u8 *gUnknown_80FEB08[];
extern u8 gUnknown_202DE58[];
extern s16 gUnknown_80F4E08;

struct Position_Alt
{
    union PositionAlt
    {
        struct Position norm;
        u32 full_bits;
    } temp;
};

// Array indices correspond to the current dungeon tileset.
const u8 gDungeonCamouflageTypes[76] = {
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_GRASS,
    TYPE_ICE,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_ICE,
    TYPE_ICE,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GROUND,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_ICE,
    TYPE_ROCK,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_GROUND,
    TYPE_WATER,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_GRASS,
    TYPE_ROCK,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_NORMAL,
    TYPE_ROCK,
    TYPE_NORMAL,
    TYPE_ICE,
    TYPE_WATER,
    TYPE_WATER,
    TYPE_ROCK
};

extern s16 gUnknown_80F4DC6;
extern u8 *gUnknown_80FEFF4[];
extern void sub_80763F8(struct DungeonEntity *, struct DungeonEntity *, u32);

extern u32 gUnknown_80F51C4[];

bool8 sub_805AFA4(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, u32 param_4)
{
  s32 r0;
  s32 r2;
  s32 r1;
  bool8 flag;

#ifndef NONMATCHING
  register struct DungeonEntityData *entityData asm("r3");
#else
  struct DungeonEntityData *entityData;
#endif
  
  SendThawedMessage(pokemon, target);
  entityData = pokemon->entityData;
  r2 = entityData->maxHP;
  r0 = r2;
  if (r2 < 0) {
    r0 = r2 + 3;
  }
  if (entityData->HP <= r0 >> 2) {
    r2 = 0;
  }
  else if (r1 = entityData->HP, r1 <= r2 / 2) {
      r2 = 1;
  }
  else
  {
    r0 = r2 * 3;
    if (r0 < 0) {
        r0 = r0 + 3;
    }
    if (r0 >>= 2, r2 = 3, r1 <= r0) {
        r2 = 2;
    }
  }
  flag =  sub_8055640(pokemon,target,move,gUnknown_80F51C4[r2],param_4) ? TRUE : FALSE;
  return flag;
}

bool8 sub_805B028(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move)
{ 
    sub_8077780(pokemon,target, 1);
    return TRUE;
}

bool8 TransformMoveAction(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move)
{ 
  if (IsBossBattle()) {
    sub_80522F4(pokemon,target,*gUnknown_80FEFF4);
    return FALSE;
  }
  else {
    move->PP = 0;
    sub_8078E18(pokemon,target);
    return TRUE;
  }
}

bool8 sub_805B074(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{ 
    bool8 uVar5;

    uVar5 = FALSE;
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
        uVar5 = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DC6) != 0) {
            sub_80763F8(pokemon,target,0);
        }
    }
    return uVar5;
}

bool8 sub_805B0BC(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{ 
    sub_807CD9C(pokemon, target, pokemon->entityData->action.facingDir);
    return TRUE;
}

bool8 HandleColorChange(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    u8 newType;
    const char *typeString;
    struct DungeonEntityData *entityData;

    entityData = target->entityData;
    newType = gDungeonCamouflageTypes[gDungeonGlobalData->tileset];
    if (HasAbility(target, ABILITY_FORECAST)) {
        sub_80522F4(pokemon,target,*gPtrForecastPreventsTypeSwitchMessage);
        return FALSE;
    }
    else {
        entityData->types[0] = newType;
        entityData->types[1] = TYPE_NONE;
        entityData->isColorChanged = TRUE;
        SetMessageArgument(gUnknown_202DFE8,target,0);
        typeString = GetUnformattedTypeString(newType);
        strcpy(gUnknown_202DE58, typeString);
        sub_80522F4(pokemon,target,*gUnknown_80FEB08);
        return TRUE;
    }
}

bool8 sub_805B164(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    sub_8077084(pokemon,target,gUnknown_8106A50, 2);
    return TRUE;
}

bool8 sub_805B17C(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    s32 uVar4;
    bool8 uVar5;

    uVar5 = FALSE;
    if (move->moveID == MOVE_FIRE_SPIN) {
        SendThawedMessage(pokemon,target);
        uVar4 = 0x13c;
    }
    else {
        uVar4 = 0x75;
        if ((move->moveID != MOVE_CLAMP) && (uVar4 = 0xf1, move->moveID == MOVE_BIND)) {
            uVar4 = 0x7e;
        }
    }
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
        uVar5 = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4E08) != 0) {
            sub_80768DC(pokemon,target,uVar4,0);
        }
    }
    return uVar5;
}

bool8 PerishSongMoveAction(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    PerishSongTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B214(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    WrapTarget(pokemon, target);
    return TRUE;
}

bool8 TrapperOrbAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    bool8 trapLaid;
    u8 uVar2;
    bool8 isEnemy;
    
    trapLaid = FALSE;
    isEnemy = pokemon->entityData->isEnemy;
    uVar2 = 1;
    
    if (isEnemy) {
        uVar2 = 2;
    }
    if (sub_807FCD4(&pokemon->posWorld,0x13,uVar2) != 0) {
        trapLaid = TRUE;
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FC5A8); // A trap can't be laid here!
    }
    sub_8049ED4();
    return trapLaid;
}

s32 sub_805B264(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    u32 uVar2;
    s32 r3;
    s32 r6;
    s32 iVar5;
    struct DungeonEntityData *entityData;

    entityData = target->entityData;  
    r3 = gUnknown_202F224;
    r6 = 0;

    gDungeonGlobalData->unk18200 = gUnknown_8106A8C[r3];
    gDungeonGlobalData->unk18204 = 0;
    iVar5 = gUnknown_80F4F94[r3];
    if (entityData->chargingStatus == 0xA) {
        iVar5 = iVar5 << 1;
    }
    uVar2 = sub_8055864(pokemon,target,move,iVar5,param_4);
    r6 =  -((int)(-uVar2 | uVar2) >> 0x1f);
    return r6;
}

bool8 sub_805B2E4(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    MagicCoatStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B2F0(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    ProtectStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B2FC(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    sub_8077160(pokemon,target,gUnknown_8106A4C,1);
    return TRUE;
}

bool8 sub_805B314(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{
    sub_80783C4(pokemon, target, 1);
    return TRUE;
}

bool8 sub_805B324(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{
    bool8 uVar3;

    uVar3 = FALSE;
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
        uVar3 = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DD8) != 0) {
            sub_8076E20(pokemon,target,gUnknown_8106A50,1,1,0);
        }
    }
    return uVar3;
}

bool8 sub_805B37C(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    DestinyBondStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B388(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    return (sub_8055640(pokemon,target,move,0x100,param_4)) ? TRUE : FALSE;
}

bool8 sub_805B3A8(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    MirrorCoatStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B3B4(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    u32 uVar1 = gUnknown_8106A50;
    sub_8077084(pokemon,target,uVar1,1);
    sub_8077160(pokemon,target,uVar1,1);
    return TRUE;
}

bool8 sub_805B3E0(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4)
{ 
    sub_8055640(pokemon,target,move,0x100,param_4);
    return TRUE;
}

bool8 sub_805B3FC(struct DungeonEntity * pokemon,struct DungeonEntity * target,struct PokemonMove *move, s32 param_4, s32 param_5)
{
    struct DungeonEntityData *iVar2;
    bool8 uVar4;

    uVar4 = FALSE;
    if (sub_8055640(pokemon,target,move,0x100,param_5) != 0) {
        uVar4 = TRUE;
        if (sub_805727C(pokemon,pokemon,gUnknown_80F4DCE) != 0) {
            iVar2 = pokemon->entityData;
            sub_8077084(pokemon,pokemon,param_4,1);
            if (iVar2->unkFB == 0) {
                iVar2->unkFB = 1;
            }
        }
    }
    return uVar4;
}

bool8 sub_805B454(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_807614C(pokemon, target, 1);
    return TRUE;
}

bool8 MimicMoveAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    struct DungeonEntityData *entityData;
    struct DungeonEntityData *targetEntityData;
    struct PokemonMove *move;
    s32 moveCounter;
    s32 moveIndex;
    bool8 mimicSuccess;

    mimicSuccess = FALSE;
    entityData = pokemon->entityData;
    targetEntityData = target->entityData;
    moveCounter = 0;

    for(moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        move = &targetEntityData->moves[moveIndex];
        if (((move->moveFlags & MOVE_FLAG_EXISTS)) && !sub_805755C(pokemon,move->moveID)) {
            if ((move->moveID != MOVE_MIMIC) && (move->moveID != MOVE_ASSIST) && (move->moveID != MOVE_SKETCH) && (move->moveID != MOVE_MIRROR_MOVE) &&
                (move->moveID != MOVE_ENCORE) && ((move->moveFlags & MOVE_FLAG_LAST_USED))) {
                entityData->mimicMoveIDs[moveCounter] = move->moveID;
                moveCounter++;
            }
        }
    }
    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    if (moveCounter != 0) {
        if (entityData->unkFB == 0) {
            entityData->unkFB = 1;
        }
        sub_80522F4(pokemon,target,*gUnknown_80FDCE4);
        mimicSuccess = TRUE;
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FDD00);
    }
    return mimicSuccess;
}

bool8 sub_805B53C(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    s16 *r1;
    s32 index;
    s32 r5;
    s32 IQ;
    u8 local_24;
    struct DungeonEntityData *entityData;

    local_24 = 0;
    entityData = pokemon->entityData;
    r5 = 1;
    index = 0;
    if (0 <= gUnknown_80F55EC[0]) {
        IQ = entityData->IQ;
        for(r1 = &gUnknown_80F55EC[index]; (999 > index) && (*r1 >= 0); r1 = r1 + 2, index++)
            {
                if ((IQ < *r1)){
                    r5 = (int)r1[1];
                    goto _0805B598;
                }
            }
    }
_0805B598:
    sub_806F370(pokemon,target,r5,1,&local_24, GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = local_24 == 0;
    return local_24;
}

bool8 LeechSeedMoveAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    HandleLeechSeed(pokemon, target, TRUE);
    if (pokemon->entityData->unkFB == 0) {
        pokemon->entityData->unkFB = 1;
    }
    return TRUE;
}

NAKED
bool8 sub_805B618(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tmov r6, r9\n"
	"\tmov r5, r8\n"
	"\tpush {r5,r6}\n"
	"\tsub sp, 0x8\n"
	"\tadds r6, r0, 0\n"
	"\tmov r8, r1\n"
	"\tmov r9, r3\n"
	"\tldr r0, _0805B660\n"
	"\tldr r4, [r0]\n"
	"\tldr r5, _0805B664\n"
	"\tlsls r4, 3\n"
	"\tadds r0, r4, r5\n"
	"\tldrh r1, [r0]\n"
	"\tmov r0, sp\n"
	"\tbl InitPokemonMove\n"
	"\tadds r5, 0x4\n"
	"\tadds r4, r5\n"
	"\tldr r4, [r4]\n"
	"\tadds r0, r6, 0\n"
	"\tmov r1, r8\n"
	"\tmov r2, sp\n"
	"\tmov r3, r9\n"
	"\tbl _call_via_r4\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tadd sp, 0x8\n"
	"\tpop {r3,r4}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tpop {r4-r6}\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_0805B660: .4byte gUnknown_202F228\n"
"_0805B664: .4byte gUnknown_80F59C8");
}

bool8 sub_805B668(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
  bool8 hasLiquidOoze;
  s32 iVar3;
  s32 iVar4;
  bool8 uVar5;
  
  uVar5 = FALSE;
  hasLiquidOoze = HasAbility(target, ABILITY_LIQUID_OOZE);
  if (IsSleeping(target)) {
    iVar3 = sub_8055640(pokemon,target,move,0x100,param_4);
    if (iVar3 != 0) {
      uVar5 = TRUE;
      iVar4 = iVar3 / 2;
      if (iVar4 < 1) {
        iVar4 = 1;
      }
      if (sub_8057308(pokemon,0) != 0) {
        if (pokemon->entityData->unkFB == 0) {
          pokemon->entityData->unkFB = 1;
        }
        if (sub_8057308(pokemon,0) != 0) {
          if (hasLiquidOoze) {
            sub_806F324(pokemon,iVar4,0xd,0x1fa);
          }
          else {
            HealTargetHP(pokemon,pokemon,iVar4,0,1);
          }
        }
      }
    }
  }
  else {
    sub_80522F4(pokemon,target,*gPtrSleepingTargetOnlyMessage);
  }
  return uVar5;
}

bool8 sub_805B734(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    SnatchStatusTarget(pokemon, target);
    return TRUE;
}

bool8 RecycleMoveAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct ItemSlot *item;
  s32 index;
  struct DungeonEntityData *entityData;
  bool8 isTMRecycled;
  
  entityData = target->entityData;
  isTMRecycled = FALSE;
  if (!entityData->isEnemy) {
    for(index = 0; index < INVENTORY_SIZE; index++)
    {
#ifdef NONMATCHING
    item = &gTeamInventory_203B460->teamItems[index];
#else
        register size_t offset asm("r1") = offsetof(struct TeamInventory, teamItems[index]);
        struct ItemSlot* p = gTeamInventory_203B460->teamItems;
        size_t addr = offset + (size_t)p;
        item = (struct ItemSlot*)addr;
#endif
        if ((item->itemFlags & ITEM_FLAG_EXISTS) && ((item->itemFlags & ITEM_FLAG_FOR_SALE) == 0))
            if(item->itemIndex == ITEM_ID_USED_TM) {
                xxx_init_itemslot_8090A8C(item, item->numItems + 0x7d,0);
                isTMRecycled = TRUE;
            }
        }
    if ((entityData->heldItem.itemFlags & ITEM_FLAG_EXISTS) && (entityData->heldItem.itemIndex == ITEM_ID_USED_TM)) {
      xxx_init_itemslot_8090A8C(&entityData->heldItem,entityData->heldItem.numItems + 0x7D,0);
      isTMRecycled = TRUE;
    }
  }
  if (isTMRecycled) {
    sub_80522F4(pokemon,target,*gUnknown_80FDC9C); // The Used TM was recharged!
  }
  else {
    sub_80522F4(pokemon,target,*gUnknown_80FDCA0); // But nothing happened!
  }
  return isTMRecycled;
}

bool8 sub_805B7FC(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    ReflectStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B808(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    u8 local_20;

    local_20 = 0;
    sub_806F370(pokemon,target,gUnknown_80F4F7E,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = (local_20 == 0);
    return local_20;
}

bool8 sub_805B884( struct DungeonEntity * pokemon, struct DungeonEntity * target)
{ 
    sub_8077084(pokemon, target, gUnknown_8106A4C, 1);
    sub_8077910(pokemon, target, 0, TRUE);
    return TRUE;
}

bool8 SkullBashMoveAction(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove * move, s32 param_4)
{
    bool8 flag;

    if (MoveMatchesChargingStatus(pokemon,move)) {
        flag = sub_8055640(pokemon,target,move,gUnknown_80F4F58,param_4) != 0 ? 1 : 0;
        sub_8079764(pokemon);
    }
    else {
        sub_8079618(pokemon,target,6,move,*gUnknown_80FAFF0);
        flag = TRUE;
    }
    return flag;
}

bool8 sub_805B910(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove * move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if(sub_805727C(pokemon, target, gUnknown_80F4DDC))
        {
            sub_8076F80(pokemon, target, gUnknown_8106A50, 1, 1, 0);
        }
    }
    return flag;
}

bool8 sub_805B968(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove * move, s32 param_4)
{
    s32 entityHP;
    s32 iVar5;
    bool8 flag;

    flag = FALSE;
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if (sub_8057308(pokemon,0) != 0) {
            entityHP = pokemon->entityData->maxHP;
            if (entityHP < 0) {
                entityHP = entityHP + 3;
            }
            iVar5 = entityHP >> 2;
            if (iVar5 < 1) {
                iVar5 = 1;
            }
            sub_806F370(pokemon,pokemon,iVar5,0,0,0,sub_8057600(move,param_4),0,1,0);
        }
    }
    return flag;
}

bool8 RockSmashMoveAction(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    bool8 uVar3;
    s32 auStack20;

#ifdef NONMATCHING
    struct DungeonEntity *temp;
    struct DungeonEntity *temp1;
#else
    register struct DungeonEntity *temp asm("r5");
    register struct DungeonEntity *temp1 asm("r4");
#endif

    temp = pokemon;
    temp1 = target;

    uVar3 = 0;
    if (sub_8069D18(&auStack20) != 0) {
        sub_80522F4(temp,temp1,*gUnknown_80FD430); // Can't use that diagonally!
    }
    else if (uVar3 = (sub_804AD34(&auStack20)), uVar3 != 0) {
        sub_80522F4(temp,temp1,*gUnknown_80FD3F0); // It dug the wall in front!
    }
    else {
        sub_80522F4(temp,temp1,*gUnknown_80FD40C); // Can't use that here!
    }
    return uVar3;
}

bool8 sub_805BA44(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_807D3CC(pokemon, target);
    return TRUE;
}

bool8 sub_805BA50(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    struct DungeonEntityData *iVar2;
    struct DungeonEntityData *iVar3;
    struct DungeonEntityData *iVar5;
    struct DungeonEntityData *iVar6;
    bool8 uVar6;
    struct ItemSlot *pokeItem;
    struct ItemSlot *targetItem;

    uVar6 = FALSE;
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
        uVar6 = TRUE;
        if (sub_805727C(pokemon,target, 0) != 0) {
            iVar2 = pokemon->entityData;
            iVar3 = pokemon->entityData;
            iVar5 = target->entityData;
            iVar6 = target->entityData;
            SetMessageArgument(gAvailablePokemonNames, pokemon, 0);
            SetMessageArgument(gAvailablePokemonNames + 0x50, target, 0);
            if (HasAbility(target, ABILITY_STICKY_HOLD)) {
                return TRUE;
            }
            else if (HasItem(target, ITEM_ID_ALERT_SPECS)) {
                sub_80522F4(pokemon,target,*gUnknown_80FD574); // $m1 was protected by its Specs!
                return TRUE;
            }
            else {
                pokeItem = &iVar2->heldItem;
                targetItem = &iVar5->heldItem;
                if ((pokeItem->itemFlags & ITEM_FLAG_EXISTS) != 0) {
                    sub_80522F4(pokemon,target,*gUnknown_80FC654); // $m0 has an item already!
                    return TRUE;
                }
                else if ((targetItem->itemFlags & ITEM_FLAG_EXISTS) == 0) {
                    sub_80522F4(pokemon,target,*gUnknown_80FC678); // $m1 doesn't have anything
                    return TRUE;
                }
                else {
                    iVar3->heldItem = iVar6->heldItem;
                    targetItem->itemIndex = ITEM_ID_NOTHING;
                    targetItem->numItems = 0;
                    targetItem->itemFlags = 0;
                    sub_806A6E8(pokemon);
                    sub_806A6E8(target);
                    if (iVar3->unkFB == 0) {
                        iVar3->unkFB = 1;
                    }
                    sub_80522F4(pokemon,target,*gUnknown_80FC614); // Got $m1's item!
                }
            }
        }
    }
    return uVar6;
}

bool8 sub_805BB64(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_80797A0(pokemon, target, PROTECTION_STATUS_MINI_COUNTER);
    return TRUE;
}

bool8 sub_805BB74(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    if(pokemon->entityData->unkFB == 0)
    {
        pokemon->entityData->unkFB = 1;
    }
    sub_807E254(pokemon, target, 1);
    return TRUE;
}

bool8 sub_805BB98(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_807D148(pokemon, target, 1, NULL);
    return TRUE;
}

bool8 CleanseOrbAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    struct ItemSlot *item;
    struct DungeonEntity *entity;
    struct DungeonEntityData *entityData;
    s32 index;
    bool8 isItemCleaned;

#ifdef NONMATCHING
    u8 flag;
#else
    register u8 flag asm("r2");
#endif

    entityData = target->entityData;
    isItemCleaned = FALSE;
    if (!entityData->isEnemy) {
        for(index = 0; index < INVENTORY_SIZE; index++){
            // WTF why does this work...
            UNUSED struct ItemSlot* current = &gTeamInventory_203B460->teamItems[index];
            flag = index[gTeamInventory_203B460->teamItems].itemFlags;
            if (((flag & ITEM_FLAG_EXISTS) != 0) && ((flag & ITEM_FLAG_FOR_SALE) == 0))
                if((flag & ITEM_FLAG_STICKY) != 0) {
                    gTeamInventory_203B460->teamItems[index].itemFlags = flag & 0xf7;
                    isItemCleaned = TRUE;
                }
        }
        for(index = 0; index < MAX_TEAM_MEMBERS; index++)
            {
                entity = gDungeonGlobalData->teamPokemon[index];
                if (EntityExists(entity)) {
                    item = &entity->entityData->heldItem;
                    if (((item->itemFlags & ITEM_FLAG_EXISTS) != 0) && ((item->itemFlags & ITEM_FLAG_STICKY) != 0)) {
                        item->itemFlags &= 0xf7;
                        isItemCleaned = TRUE;
                    }
                }
            }
    }
    if (isItemCleaned) {
        sub_80522F4(pokemon,target,*gUnknown_80FC8F0);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FC920);
    }
    return isItemCleaned;
}

bool8 sub_805BC70(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_8075C58(pokemon,target,CalculateStatusTurns(target, gUnknown_80F4E74, TRUE), 1);
    return TRUE;
}

bool8 sub_805BC98(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    struct DungeonEntityData *entityData;
    bool8 uVar3;
    s32 targetHP;
    s32 pokeHP;
    u8 local_28;
    u8 local_27;

    local_28 = 0;
    local_27 = 0;
    entityData = pokemon->entityData;
    targetHP = target->entityData->HP - 1;
    if (targetHP < 0) {
        targetHP = 0;
    }
    sub_806F370(pokemon,target,targetHP,0,&local_28,0,sub_8057600(move,param_4),0,0,0);
    pokeHP = entityData->HP / 2;
    if (pokeHP < 0) {
        pokeHP = 0;
    }
    sub_806F370(pokemon,pokemon,pokeHP,0,&local_27,0,sub_8057600(move,param_4),0,0,0);

    local_28 = (local_28 == 0);
    local_27 = (local_27 == 0);

    uVar3 = FALSE;
    if ((local_28 != 0) || (local_27 != 0)) {
        uVar3 = TRUE;
    }
    return uVar3;
}

bool8 SilenceOrbAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    MuzzleTarget(pokemon, target);
    return TRUE;
}

bool8 ScannerOrbAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    HandleScannerOrb(pokemon, target);
    return TRUE;
}

bool8 RadarOrbAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    HandleRadarOrb(pokemon, target);
    return TRUE;
}

bool8 TransferOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity * target)
{
    struct DungeonEntityData *entityData;
    s32 oldID; //r8
    s32 targetID; // r5
    s32 r6; // r6
    bool8 didTransfer;

    didTransfer = FALSE;
    if (target->entityData->isEnemy) {
        entityData = target->entityData;
        targetID = entityData->entityID;
        oldID = entityData->entityID;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (entityData->clientType != 0) {
            sub_80522F4(pokemon,target,*gUnknown_80FD450);
            return FALSE;
        }
        else
        {
            for (r6 = 0; r6 < 0x1E; r6++) {
                targetID = sub_803D970(0);
                if ((sub_806AA0C(targetID,0) != 0) && (oldID != targetID)) {
                    if (GetPokemonSize(oldID) == GetPokemonSize(targetID)) break;
                }
            }
            if ((r6 == 0x1e) || (entityData->entityID == targetID)) {
                sub_80522F4(pokemon,target,*gUnknown_80FD450);
            }
            else {
                CopyCyanSpeciesNametoBuffer(gUnknown_202DFE8, targetID);
                sub_80522F4(pokemon,target,*gUnknown_80FD434);
                sub_806BB6C(target, targetID);
                didTransfer = TRUE;
            }
        }
    }
    else {
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_80522F4(pokemon,target,*gUnknown_80FD450);
    }
    return didTransfer;
}

bool8 sub_805BE90(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  sub_80779F0(pokemon, target, 1, TRUE);
  return TRUE;
}

bool8 LuminousOrbAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    HandleLuminousOrbAction(pokemon);
    return TRUE;
}

bool8 sub_805BEAC(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_8076D10(pokemon, target);
    return TRUE;
}

bool8 sub_805BEB8(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_807DA14(pokemon, target, 8);
    return TRUE;
}

bool8 sub_805BEC8(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_807D510(pokemon, target);
    return TRUE;
}

bool8 EscapeOrbAction(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    SetMessageArgument(gAvailablePokemonNames,pokemon,0);
    if (gDungeonGlobalData->unk66E != 0) {
        sub_80522F4(pokemon,target,*gUnknown_80FD4DC); // $m0 can't escape!
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FD4C4); // $m0 escaped!
        gDungeonGlobalData->unk4 = 1;
        gDungeonGlobalData->unk11 = 1;
    }
    return FALSE;
}

bool8 sub_805BF34(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_807DB74(pokemon);
    return TRUE;
}

bool8 TrapbustOrbAction(struct DungeonEntity * pokemon,struct DungeonEntity * target)
{
    struct MapTile *tile;
    struct DungeonEntity *mapObject;
    u8 *trapData;
    s32 startX, startY;
    s32 xCoord, yCoord;
    struct MapRoom *room;
    s32 endX, endY;
    u32 sp;
    bool8 foundTrap = FALSE;
    tile = GetMapTileForDungeonEntity_2(target);
    if (IsBossBattle()) {
        SendMessage(pokemon,*gUnknown_80FD1EC);
        return FALSE;
    }
    else
    {
        if (tile->roomIndex == 0xFF) {
            startX    =   target->posWorld.x - gDungeonGlobalData->visibility;
            startY    =   target->posWorld.y - gDungeonGlobalData->visibility;
            endX      =   startX + gDungeonGlobalData->visibility;
            endY      =   startY + gDungeonGlobalData->visibility;
        }
        else {
            room       =   &gDungeonGlobalData->roomData[tile->roomIndex];
            startX     =   room->startX - 1;
            startY     =   room->startY - 1;
            endX       =   room->endX + 1;
            endY       =   room->endY + 1;
        }
        ++endY; --endY;
        for (xCoord = startX; xCoord <= endX; xCoord++) {
            for (yCoord = startY; yCoord <= endY; yCoord++) {
                mapObject = GetMapTile_2(xCoord, yCoord)->mapObject;
                if (((mapObject != 0) && (GetEntityType(mapObject) == ENTITY_TRAP)) &&
                    (trapData = (u8*)GetTrapData(mapObject), trapData[0] != 0x11)) {
                    sp = yCoord << 0x10 | (u16)xCoord;
                    sub_807FE04(&sp, 0);
                    foundTrap = TRUE;
                }
            }
        }
        if (foundTrap) {
            sub_80522F4(pokemon, target, *gUnknown_80FD1B0);
            sub_8040A84();
            sub_8049ED4();
        }
        else {
            sub_80522F4(pokemon, target, *gUnknown_80FD1CC);
        }
    }
    return foundTrap;
}

bool8 sub_805C080(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
    struct DungeonEntity **possibleTargets;
    s32 numPossibleTargets;
    struct DungeonEntity *targetEntity;
    bool8 foundTarget;
    s32 index;

    foundTarget = FALSE;
    if (pokemon->entityData->isEnemy) {
        possibleTargets = gDungeonGlobalData->wildPokemon;
        numPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
    }
    else {
        possibleTargets = gDungeonGlobalData->teamPokemon;
        numPossibleTargets = MAX_TEAM_MEMBERS;
    }
    for(index = 0; index < numPossibleTargets; index++){
        targetEntity = possibleTargets[index];
        if (((EntityExists(targetEntity)) && (pokemon != targetEntity)) &&
            (CanTarget(pokemon,targetEntity,1,FALSE) == 0)) {
            sub_807D148(pokemon,targetEntity,2,&pokemon->posWorld);
            foundTarget = TRUE;
        }
    }
    if (!foundTarget) {
        sub_80522F4(pokemon,target,*gUnknown_81004F0);
    }
    return foundTarget;
}

bool8 sub_805C128(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    sub_807885C(pokemon, pokemon);
    return TRUE;
}

bool8 sub_805C138(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove *move, s32 param_4)
{
    u8 local_20;

    local_20 = 0;
    sub_806F370(pokemon,target,9999,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = (local_20 == 0);
    return local_20;
}

bool8 sub_805C1B0(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    IdentityItemHolders(pokemon, target);
    return TRUE;
}

u32 sub_805C1BC(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, s32 param_4)
{
    u32 uVar1;

    uVar1 = sub_8055864(pokemon, target, move, gUnknown_80F4F80, param_4);
    return ((-uVar1 | uVar1) >> 0x1f);
}

bool8 sub_805C1E4(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_80522F4(pokemon, target, *gUnknown_80FD454);
    return FALSE;
}

bool8 sub_805C1F8(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8077BB4(pokemon, target, 1);
    return TRUE;
}

bool8 sub_805C208(struct DungeonEntity *pokemon, struct DungeonEntity *target, struct PokemonMove *move, u32 param_4)
{
    u32 uVar3;
    u8 local_24;

    local_24 = 0;
    uVar3 = GetSizeOrbDmg(target->entityData->transformSpecies);
    sub_806F370(pokemon,target,uVar3,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);

    local_24 = local_24 == 0;
    return local_24;
}

bool8 sub_805C288(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8078A58(pokemon, target, gUnknown_80F4FC6, 0);
    return TRUE;
}

bool8 sub_805C2A0(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_807DC68(pokemon, target);
    return TRUE;
}

bool8 FillInOrbAction(struct DungeonEntity *pokemon,struct DungeonEntity *target)
{
    struct MapTile *tileToFill;
    struct DungeonEntityData *iVar5;
    int y;
    bool8 filledInTile;
    int x;
    u16 cast_x;
    u32 cast_y;
    struct Position_Alt tileCoords;

    filledInTile = FALSE;
    iVar5 = target->entityData;
    if (IsBossBattle()) {
        SendMessage(pokemon,*gUnknown_80FD0B8);
        return FALSE;
    }
    else
    {
        // Calculate the coordinates of the tile in front of the user
        cast_x = target->posWorld.x + gAdjacentTileOffsets[iVar5->action.facingDir].x;
        tileCoords.temp.full_bits = (tileCoords.temp.full_bits & 0xffff0000) | cast_x;

        cast_y = ((u16)(target->posWorld.y + gAdjacentTileOffsets[iVar5->action.facingDir].y)) << 0x10;
        tileCoords.temp.full_bits = (tileCoords.temp.full_bits & 0x0000ffff) | cast_y;

        sub_8042A54((struct Position *)&tileCoords);
        tileToFill = GetMapTile_2(tileCoords.temp.norm.x,tileCoords.temp.norm.y);
        if ((tileToFill->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) == TILE_TYPE_LIQUID) {
            tileToFill->tileType = (tileToFill->tileType & ~(TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) | TILE_TYPE_FLOOR;

            for(y = -1; y < 2; y++)
                for(x = -1; x < 2; x++)
                    sub_80498A8(tileCoords.temp.norm.x + x, tileCoords.temp.norm.y + y);
            filledInTile = TRUE;
            sub_806CF60();
        }

        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
            for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
                sub_8049BB0(x,y);

        if (filledInTile) {
            sub_8042A64((struct Position *)&tileCoords);
            sub_80522F4(pokemon,target,*gUnknown_80FD0B4);
        }
        else {
            sub_80522F4(pokemon,target,*gUnknown_80FD0B8);
        }
        sub_8040A84();
        sub_8049ED4();
        return filledInTile;
    }
}

bool8 sub_805C3DC(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    u32 var;
    var = (target->entityData->isEnemy ? 2 : 1);
    sub_807FC3C(&target->posWorld, 0x14, var);
    return TRUE;
}

bool8 sub_805C3F8(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    struct ItemSlot stack;
    struct Position posStruct = target->posWorld;

    if(target->entityData->clientType != CLIENT_TYPE_NONE)
    {
        sub_80522F4(pokemon, target, *gUnknown_80FF678);
        return FALSE;
    }
    else
    {
        target->visible = FALSE;
        sub_8045C28(&stack, sub_803D73C(0), 0);
        sub_80464C8(pokemon, &posStruct, &stack);
        sub_8068FE0(target, 0x218, pokemon);
        return TRUE;
    }
}

bool8 sub_805C45C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_807F43C(pokemon, target);
    return TRUE;
}

bool8 sub_805C468(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    sub_8078F50(pokemon, target);
    return TRUE;
}

bool8 StairsOrbAction(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    HandleStairsOrb(pokemon, target);
    return TRUE;
}

bool8 sub_805C480(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    LongTossStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805C48C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    PierceStatusTarget(pokemon, target);
    return TRUE;
}

bool8 CanUseOnSelfWithStatusChecker(struct DungeonEntity *pokemon, struct PokemonMove *move)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    switch (move->moveID)
    {
        case MOVE_HAIL:
            if (GetWeather(pokemon) == WEATHER_HAIL)
            {
                return FALSE;
            }
            break;
        case MOVE_RAGE:
            if (pokemonData->chargingStatus == CHARGING_STATUS_RAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_COUNTER:
        case MOVE_PURSUIT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_COUNTER)
            {
                return FALSE;
            }
            break;
        case MOVE_MIRROR_MOVE:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MIRROR_MOVE)
            {
                return FALSE;
            }
            break;
        case MOVE_HOWL:
        case MOVE_MEDITATE:
        case MOVE_SHARPEN:
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BELLY_DRUM:
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE || RoundUpFixedPoint(pokemonData->belly) <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_ACID_ARMOR:
        case MOVE_BARRIER:
        case MOVE_DEFENSE_CURL:
        case MOVE_HARDEN:
        case MOVE_IRON_DEFENSE:
        case MOVE_WITHDRAW:
            if (pokemonData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BIDE:
        case MOVE_REVENGE:
            if (pokemonData->chargingStatus == CHARGING_STATUS_BIDE)
            {
                return FALSE;
            }
            break;
        case MOVE_AGILITY:
        {
            u32 r1;
#ifndef NONMATCHING
            asm("":"=r"(r1));
#else
            r1 = 0;
#endif
            if (pokemon->entityData->movementSpeed >= MAX_MOVEMENT_SPEED)
            {
                r1 = !r1;
                return FALSE;
            }
            break;
        }
        case MOVE_LOCK_ON:
        case MOVE_MIND_READER:
            if (pokemonData->moveStatus == MOVE_STATUS_SURE_SHOT)
            {
                return FALSE;
            }
            break;
        case MOVE_COSMIC_POWER:
            if (pokemonData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE && pokemonData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_ENDURE:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_ENDURE)
            {
                return FALSE;
            }
            break;
        case MOVE_CHARGE:
            if (pokemonData->chargingStatus == CHARGING_STATUS_CHARGE)
            {
                return FALSE;
            }
            break;
        case MOVE_MIST:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MIST)
            {
                return FALSE;
            }
            break;
        case MOVE_LIGHT_SCREEN:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_LIGHT_SCREEN)
            {
                return FALSE;
            }
            break;
        case MOVE_MINIMIZE:
            if (pokemonData->accuracyStages[STAT_STAGE_EVASION] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_INGRAIN:
            if (pokemonData->immobilizeStatus == IMMOBILIZE_STATUS_INGRAIN || pokemonData->maxHP / 2 < pokemonData->HP)
            {
                return FALSE;
            }
            break;
        case MOVE_SWALLOW:
            if (pokemonData->maxHP <= pokemonData->HP || pokemonData->stockpileCount == 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SPIT_UP:
            if (pokemonData->stockpileCount == 0)
            {
                return FALSE;
            }
            break;
        case MOVE_DOOM_DESIRE:
        case MOVE_FUTURE_SIGHT:
            if (pokemonData->moveStatus == MOVE_STATUS_SET_DAMAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_BULK_UP:
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE && pokemonData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_CAMOUFLAGE:
            if (HasType(pokemon, gDungeonCamouflageTypes[gDungeonGlobalData->tileset]))
            {
                return FALSE;
            }
            break;
        case MOVE_TAIL_GLOW:
            if (pokemonData->attackStages[STAT_STAGE_SPECIAL_ATTACK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_DESTINY_BOND:
            if (pokemonData->linkedStatus == LINKED_STATUS_DESTINY_BOND)
            {
                return FALSE;
            }
            break;
        case MOVE_MIRROR_COAT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MIRROR_COAT)
            {
                return FALSE;
            }
            break;
        case MOVE_REFLECT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_REFLECT)
            {
                return FALSE;
            }
            break;
        case MOVE_DRAGON_DANCE:
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE && pokemon->entityData->movementSpeed >= MAX_MOVEMENT_SPEED)
            {
                return FALSE;
            }
            break;
        case MOVE_MAGIC_COAT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_MAGIC_COAT)
            {
                return FALSE;
            }
            break;
        case MOVE_DETECT:
        case MOVE_PROTECT:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_PROTECT)
            {
                return FALSE;
            }
            break;
        case MOVE_RAIN_DANCE:
            if (GetWeather(pokemon) == WEATHER_RAIN)
            {
                return FALSE;
            }
            break;
        case MOVE_SANDSTORM:
            if (GetWeather(pokemon) == WEATHER_SANDSTORM)
            {
                return FALSE;
            }
            break;
        case MOVE_SUNNY_DAY:
            if (GetWeather(pokemon) == WEATHER_SUNNY)
            {
                return FALSE;
            }
            break;
        case MOVE_SAFEGUARD:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_SAFEGUARD)
            {
                return FALSE;
            }
            break;
        case MOVE_INVISIFY:
            if (pokemonData->transformStatus == TRANSFORM_STATUS_INVISIBLE)
            {
                return FALSE;
            }
            break;
        case MOVE_FOCUS_ENERGY:
            if (pokemonData->moveStatus == MOVE_STATUS_FOCUS_ENERGY)
            {
                return FALSE;
            }
            break;
        case MOVE_TAKEAWAY:
            if (pokemonData->heldItem.itemFlags & ITEM_FLAG_EXISTS)
            {
                return FALSE;
            }
            break;
        case MOVE_REST:
            if (!HasQuarterHPOrLess(pokemon) && !HasNegativeStatus(pokemon))
            {
                return FALSE;
            }
            break;
        case MOVE_DIVE:
            if (IsTileGround(GetMapTileForDungeonEntity_2(pokemon)))
            {
                return FALSE;
            }
            break;
        case MOVE_DIG:
        {
            struct MapTile *tile = GetMapTileForDungeonEntity_2(pokemon);
            if (!IsTileGround(tile) || (tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) != TILE_TYPE_FLOOR)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_TRAP_BUSTER:
        {
            struct DungeonEntity *mapObject = GetMapTileForDungeonEntity_2(pokemon)->mapObject;
            if (mapObject == NULL || GetEntityType(mapObject) != ENTITY_TRAP)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_MUD_SPORT:
            if (gDungeonGlobalData->mudSportTurnsLeft > 0)
            {
                return FALSE;
            }
            break;
        case MOVE_WATER_SPORT:
            if (gDungeonGlobalData->waterSportTurnsLeft > 0)
            {
                return FALSE;
            }
            break;
        case MOVE_GRUDGE:
            if (pokemonData->grudgeStatus)
            {
                return FALSE;
            }
            break;
        case MOVE_DECOY_MAKER:
        case MOVE_FOLLOW_ME:
        case MOVE_SUBSTITUTE:
            if (gDungeonGlobalData->decoyActive)
            {
                return FALSE;
            }
            break;
        case MOVE_STOCKPILE:
            if (pokemonData->stockpileCount >= MAX_STOCKPILE_COUNT)
            {
                return FALSE;
            }
            break;
        case MOVE_CLEANSE:
            if (pokemonData->heldItem.itemFlags & ITEM_FLAG_EXISTS &&
                !(pokemonData->heldItem.itemFlags & ITEM_FLAG_STICKY))
            {
                return FALSE;
            }
            break;
        case MOVE_DOUBLE_TEAM:
            if (pokemonData->accuracyStages[STAT_STAGE_EVASION] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_GROWTH:
            if (pokemonData->attackStages[STAT_STAGE_SPECIAL_ATTACK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_SWORDS_DANCE:
            if (pokemonData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_WISH:
            if (pokemonData->isEnemy || pokemonData->protectionStatus == PROTECTION_STATUS_WISH)
            {
                return FALSE;
            }
            break;
        case MOVE_TRANSFORM:
            if (pokemonData->transformStatus == TRANSFORM_STATUS_TRANSFORMED)
            {
                return FALSE;
            }
            break;
        case MOVE_SPIKES:
            if (!CanLayTrap(&pokemon->posWorld))
            {
                return FALSE;
            }
            break;
        case MOVE_CALM_MIND:
            if (pokemonData->attackStages[STAT_STAGE_SPECIAL_ATTACK] < MAX_STAT_STAGE)
            {
                break;
            }
        case MOVE_AMNESIA:
            if (pokemonData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] >= MAX_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_SNATCH:
            if (pokemonData->waitingStatus == WAITING_STATUS_SNATCH)
            {
                return FALSE;
            }
            break;
        case MOVE_BEAT_UP:
        case MOVE_BLOWBACK:
        case MOVE_HURL:
        case MOVE_MEMENTO:
        case MOVE_ROAR:
        case MOVE_STAY_AWAY:
        case MOVE_SWITCHER:
        case MOVE_TELEPORT:
        case MOVE_VITAL_THROW:
        case MOVE_WARP:
        case MOVE_WHIRLWIND:
            if (IsBossBattle())
            {
                return FALSE;
            }
            break;
        case MOVE_CONVERSION_2:
            if (pokemonData->protectionStatus == PROTECTION_STATUS_CONVERSION_2)
            {
                return FALSE;
            }
            break;
        case MOVE_HELPING_HAND:
            if (pokemonData->isEnemy)
            {
                s32 i;
                for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++)
                {
                    struct DungeonEntity *target = gDungeonGlobalData->wildPokemon[i];
                    if (EntityExists(target) && target != pokemon && CanSee(pokemon, target))
                    {
                        if (target->entityData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->entityData->attackStages[STAT_STAGE_SPECIAL_ATTACK] < MAX_STAT_STAGE)
                        {
                            break;
                        }
                    }
                }
                if (i == DUNGEON_MAX_WILD_POKEMON)
                {
                    return FALSE;
                }
                break;
            }
            else
            {
                s32 i;
                for (i = 0; i < MAX_TEAM_MEMBERS; i++)
                {
                    struct DungeonEntity *target = gDungeonGlobalData->teamPokemon[i];
                    if (EntityExists(target) && target != pokemon && CanSee(pokemon, target))
                    {
                        if (target->entityData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE)
                        {
                            continue;
                        }
                        if (target->entityData->attackStages[STAT_STAGE_SPECIAL_ATTACK] < MAX_STAT_STAGE)
                        {
                            break;
                        }
                    }
                }
                if (i == MAX_TEAM_MEMBERS)
                {
                    return FALSE;
                }
                break;
            }
    }
    return TRUE;
}

bool8 CanUseOnTargetWithStatusChecker(struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move)
{
    struct DungeonEntityData *userData = user->entityData;
    struct DungeonEntityData *targetData = target->entityData;
    s32 i;
    if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN && MoveCannotHitFrozen(move))
    {
        return FALSE;
    }
    switch (move->moveID)
    {
        case MOVE_GRASSWHISTLE:
        case MOVE_HYPNOSIS:
        case MOVE_LOVELY_KISS:
        case MOVE_SING:
        case MOVE_SLEEP_POWDER:
        case MOVE_SPORE:
            if (IsSleeping(target))
            {
                return FALSE;
            }
            break;
        case MOVE_YAWN:
            if (targetData->sleepStatus == SLEEP_STATUS_YAWNING)
            {
                return FALSE;
            }
            if (IsSleeping(target))
            {
                return FALSE;
            }
            break;
        case MOVE_NIGHTMARE:
            if (targetData->sleepStatus == SLEEP_STATUS_NIGHTMARE)
            {
                return FALSE;
            }
            break;
        case MOVE_SWEET_SCENT:
            if (targetData->accuracyStages[STAT_STAGE_EVASION] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_CHARM:
            if (targetData->attackMultipliers[STAT_STAGE_ATTACK] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_ENCORE:
            if (targetData->volatileStatus == VOLATILE_STATUS_ENCORE)
            {
                return FALSE;
            }
            if (!HasLastUsedMove(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_SUPER_FANG:
            if (targetData->HP <= 1)
            {
                return FALSE;
            }
            break;
        case MOVE_PAIN_SPLIT:
            if (targetData->HP <= userData->HP)
            {
                return FALSE;
            }
            break;
        case MOVE_TORMENT:
            if (HasDisabledMove(targetData->moves) || !HasLastUsedMove(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_COTTON_SPORE:
        case MOVE_SCARY_FACE:
        case MOVE_STRING_SHOT:
            if (target->entityData->movementSpeed <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SCREECH:
            if (targetData->defenseMultipliers[STAT_STAGE_DEFENSE] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_FAKE_TEARS:
            if (targetData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_SPITE:
            if (LastUsedMoveOutOfPP(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_SMOKESCREEN:
            if (targetData->moveStatus == MOVE_STATUS_WHIFFER)
            {
                return FALSE;
            }
            break;
        case MOVE_MEMENTO:
            if (targetData->attackMultipliers[STAT_STAGE_ATTACK] < STAT_MULTIPLIER_THRESHOLD &&
                targetData->attackMultipliers[STAT_STAGE_SPECIAL_ATTACK] < STAT_MULTIPLIER_THRESHOLD)
            {
                return FALSE;
            }
            break;
        case MOVE_WILL_O_WISP:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_BURNED)
            {
                return FALSE;
            }
            break;
        case MOVE_FORESIGHT:
        case MOVE_ODOR_SLEUTH:
            if (targetData->types[0] == TYPE_GHOST || targetData->types[1] == TYPE_GHOST)
            {
                if (!targetData->exposedStatus)
                {
                    break;
                }
            }
            if (targetData->accuracyStages[STAT_STAGE_EVASION] <= DEFAULT_STAT_STAGE)
            {
                return FALSE;
            }
            break;
        case MOVE_DISABLE:
        case MOVE_GLARE:
        case MOVE_STUN_SPORE:
        case MOVE_THUNDER_WAVE:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_PARALYZED)
            {
                return FALSE;
            }
            break;
        case MOVE_ENDEAVOR:
            if (targetData->HP - userData->HP <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_LEER:
        case MOVE_TAIL_WHIP:
            if (targetData->defenseStages[STAT_STAGE_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_METAL_SOUND:
            if (targetData->defenseStages[STAT_STAGE_SPECIAL_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_TICKLE:
            if (targetData->attackStages[STAT_STAGE_ATTACK] <= 0 &&
                targetData->defenseStages[STAT_STAGE_DEFENSE] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_BLOCK:
        case MOVE_MEAN_LOOK:
        case MOVE_SPIDER_WEB:
            if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_IMMOBILIZED)
            {
                return FALSE;
            }
            break;
        case MOVE_HAZE:
        {
            for (i = 0; i < 2; i++)
            {
                if (targetData->attackStages[i] < DEFAULT_STAT_STAGE) break;
                if (targetData->defenseStages[i] < DEFAULT_STAT_STAGE) break;
                if (targetData->accuracyStages[i] < DEFAULT_STAT_STAGE ||
                    targetData->attackMultipliers[i] < DEFAULT_STAT_MULTIPLIER ||
                    targetData->defenseMultipliers[i] < DEFAULT_STAT_MULTIPLIER)
                {
                    break;
                }
            }
            if (i == 2)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_UPROAR:
            if (targetData->sleepStatus == SLEEP_STATUS_SLEEPLESS)
            {
                return FALSE;
            }
            break;
        case MOVE_PSYCH_UP:
        {
            for (i = 0; i < 2; i++)
            {
                if (userData->attackStages[i] < targetData->attackStages[i]) break;
                if (userData->defenseStages[i] < targetData->defenseStages[i] ||
                    userData->accuracyStages[i] < targetData->accuracyStages[i] ||
                    userData->attackMultipliers[i] < targetData->attackMultipliers[i] ||
                    userData->defenseMultipliers[i] < targetData->defenseMultipliers[i])
                {
                    break;
                }
            }
            if (i == 2)
            {
                return FALSE;
            }
            break;
        }
        case MOVE_FLASH:
        case MOVE_KINESIS:
        case MOVE_SAND_ATTACK:
            if (targetData->accuracyStages[STAT_STAGE_ACCURACY] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_TAUNT:
            if (targetData->volatileStatus == VOLATILE_STATUS_TAUNTED)
            {
                return FALSE;
            }
            break;
        case MOVE_TRICK:
            if (!(userData->heldItem.itemFlags & ITEM_FLAG_EXISTS) ||
                !(targetData->heldItem.itemFlags & ITEM_FLAG_EXISTS))
            {
                return FALSE;
            }
            break;
        case MOVE_KNOCK_OFF:
            if (!(targetData->heldItem.itemFlags & ITEM_FLAG_EXISTS))
            {
                return FALSE;
            }
            break;
        case MOVE_FEATHERDANCE:
        case MOVE_GROWL:
            if (targetData->attackStages[STAT_STAGE_ATTACK] <= 0)
            {
                return FALSE;
            }
            break;
        case MOVE_ROLE_PLAY:
            if (userData->abilities[0] == targetData->abilities[0] &&
                userData->abilities[1] == targetData->abilities[1])
            {
                return FALSE;
            }
            break;
        case MOVE_CURSE:
            if (HasType(user, TYPE_GHOST))
            {
                if (targetData->waitingStatus == WAITING_STATUS_CURSED)
                {
                    return FALSE;
                }
            }
            else
            {
                if (userData->attackStages[STAT_STAGE_ATTACK] >= MAX_STAT_STAGE &&
                    userData->defenseStages[STAT_STAGE_DEFENSE] >= MAX_STAT_STAGE)
                {
                    return FALSE;
                }
            }
            break;
        case MOVE_IMPRISON:
        case MOVE_OBSERVER:
            if (targetData->volatileStatus == VOLATILE_STATUS_PAUSED)
            {
                return FALSE;
            }
            break;
        case MOVE_FALSE_SWIPE:
            if (targetData->HP <= 1)
            {
                return FALSE;
            }
            break;
        case MOVE_LEECH_SEED:
            if (targetData->linkedStatus == LINKED_STATUS_LEECH_SEED)
            {
                return FALSE;
            }
            break;
        case MOVE_PERISH_SONG:
            if (targetData->perishSongTimer != 0)
            {
                return FALSE;
            }
            break;
        case MOVE_MIMIC:
        case MOVE_SKETCH:
            if (!HasLastUsedMove(targetData->moves))
            {
                return FALSE;
            }
            break;
        case MOVE_ATTRACT:
            if (targetData->volatileStatus == VOLATILE_STATUS_INFATUATED)
            {
                return FALSE;
            }
            break;
        case MOVE_WRAP:
            if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE)
            {
                return FALSE;
            }
            if (targetData->immobilizeStatus == IMMOBILIZE_STATUS_WRAPPED_BY_FOE)
            {
                return FALSE;
            }
            break;
        case MOVE_TOXIC:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                return FALSE;
            }
            break;
        case MOVE_POISON_GAS:
        case MOVE_POISONPOWDER:
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_POISONED)
            {
                return FALSE;
            }
            if (targetData->nonVolatileStatus == NON_VOLATILE_STATUS_BADLY_POISONED)
            {
                return FALSE;
            }
            break;
        case MOVE_CONFUSE_RAY:
        case MOVE_FLATTER:
        case MOVE_SUPERSONIC:
        case MOVE_SWAGGER:
        case MOVE_SWEET_KISS:
        case MOVE_TEETER_DANCE:
        case MOVE_TOTTER:
            if (targetData->volatileStatus == VOLATILE_STATUS_CONFUSED)
            {
                return FALSE;
            }
            break;
    }
    return TRUE;
}

bool8 HasDisabledMove(struct PokemonMove *moves)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags & MOVE_FLAG_DISABLED)
        {
            return TRUE;
        }
    }
    if (moves[STRUGGLE_MOVE_INDEX].moveFlags & MOVE_FLAG_DISABLED)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 LastUsedMoveOutOfPP(struct PokemonMove *moves)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS &&
            moves[i].moveFlags & MOVE_FLAG_LAST_USED &&
            moves[i].PP == 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 HasLastUsedMove(struct PokemonMove *moves)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags & MOVE_FLAG_LAST_USED)
        {
            return TRUE;
        }
    }
    if (moves[STRUGGLE_MOVE_INDEX].moveFlags & MOVE_FLAG_LAST_USED)
    {
        return TRUE;
    }
    return FALSE;
}
