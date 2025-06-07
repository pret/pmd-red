#include "global.h"
#include "globaldata.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "constants/ability.h"
#include "constants/monster.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon.h"
#include "dungeon_ai.h"
#include "dungeon_config.h"
#include "dungeon_generation.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "math.h"
#include "moves.h"
#include "move_effects_target.h"
#include "move_util.h"
#include "pokemon.h"
#include "position_util.h"
#include "run_dungeon.h"
#include "sprite.h"
#include "string_format.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "weather.h"

extern void sub_80833E8(DungeonPos *param_1, s32 *param_2);
extern void sub_806A5B8(Entity *);
extern bool8 sub_8045888(Entity *ent);
extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
extern void sub_807D068(Entity *, DungeonPos *);
extern void sub_807EC28(bool8 arg0);

void sub_807F9BC(Entity *entity);

void sub_807F43C(Entity *target, Entity *attacker)
{
    s32 attackerDirection;
    s32 var_3C;
    DungeonPos attackerPos;
    s32 pixelPosX, pixelPosY;
    PixelPos var_54;
    s32 var_30, r10;
    s32 r6;
    s32 newDir;
    s32 i, directionId;
    Entity *tileEntity;
    s32 var_2C;
    DungeonPos positions[40];
    s32 var_74[4];
    s32 positionsCounter;

    if (AbilityIsActive(attacker, ABILITY_SUCTION_CUPS)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FCB40); // is anchored, cannot be moved
        return;
    }
    if (target == attacker) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FCB70); // couldn't be thrown for some reason
        return;
    }

    attackerPos = attacker->pos;
    for (var_3C = 0; var_3C < 2; var_3C++) {
        positionsCounter = 0;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *mon = gDungeon->activePokemon[i];
            if (EntityIsValid(mon) && target != mon && attacker != mon && CanSeeTarget(target, mon)) {
                if (var_3C == 0) {
                    if (GetTreatmentBetweenMonsters(target, mon, FALSE, TRUE) != 1)
                        continue;
                }
                else {
                    if (GetTreatmentBetweenMonsters(target, mon, FALSE, TRUE) != 0)
                        continue;
                }

                if (var_3C == 0) {
                    DungeonPos pos;
                    for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
                        pos.x = gAdjacentTileOffsets[directionId].x + mon->pos.x;
                        pos.y = gAdjacentTileOffsets[directionId].y + mon->pos.y;
                        if (!sub_80703A0(attacker, &pos))
                            break;
                    }

                    if (directionId != NUM_DIRECTIONS && positionsCounter < 40) {
                        positions[positionsCounter++] = mon->pos;
                    }
                }
                else {
                    DungeonPos pos;
                    for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
                        pos.x = gAdjacentTileOffsets[directionId].x + mon->pos.x;
                        pos.y = gAdjacentTileOffsets[directionId].y + mon->pos.y;
                        if (!sub_80703A0(attacker, &pos) && positionsCounter < 40) {
                            positions[positionsCounter++] = pos;
                        }
                    }
                }
            }
        }

        if (positionsCounter != 0)
            break;
    }

    if (positionsCounter != 0) {
        s32 rnd = DungeonRandInt(positionsCounter);
        attackerPos = positions[rnd];
    }
    else {
        sub_80833E8(&target->pos, var_74);
        for (i = 0; i < 100; i++) {
            DungeonPos pos;
            pos.x = DungeonRandRange(var_74[0], var_74[2]);
            pos.y = DungeonRandRange(var_74[1], var_74[3]);
            if (!sub_80703A0(attacker, &pos)) {
                attackerPos = pos;
                break;
            }
        }
        if (i == 100) {
            TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FE6B4); // But it didn~27t go anywhere.
            return;
        }
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
    TryDisplayDungeonLoggableMessage3(target, attacker, gUnknown_80FE690); // m0 was sent flying!
    if (sub_8045888(attacker)) {
        PlaySoundEffect(0x1A3);
    }

    var_2C = 0;
    attackerDirection = GetEntInfo(attacker)->action.direction;
    r6 = max(attackerPos.x - attacker->pos.x, attackerPos.y - attacker->pos.y) << 4;
    if (r6 > 80)
        r6 = 80;
    if (r6 < 10)
        r6 = 10;

    newDir = GetDirectionTowardsPosition(&attackerPos, &attacker->pos);

    pixelPosX = X_POS_TO_PIXELPOS(attackerPos.x) + ((gAdjacentTileOffsets[newDir].x << 8) / 3);
    pixelPosY = Y_POS_TO_PIXELPOS(attackerPos.y) + ((gAdjacentTileOffsets[newDir].y << 8) / 3);

    var_30 = (pixelPosX - attacker->pixelPos.x) / r6;
    r10 = (pixelPosY - attacker->pixelPos.y) / r6;
    var_54.x = attacker->pixelPos.x;
    var_54.y = attacker->pixelPos.y;
    for (i = 0; i < r6; i++) {
        var_54.x += var_30;
        var_54.y += r10;
        sub_804535C(attacker, &var_54);
        if (sub_8045888(attacker)) {
            attacker->unk1C.raw = sin_4096(var_2C) << 5;
            DungeonRunFrameActions(0x3B);
            if (!(i & 3)) {
                attackerDirection &= DIRECTION_MASK;
                sub_806CDD4(attacker, 6, attackerDirection);
                attackerDirection++;
            }
        }
        var_2C += (0x800 / r6);
    }

    var_54.x = pixelPosX;
    var_54.y = pixelPosY;
    attacker->unk1C.raw = 0;
    sub_804535C(attacker, &var_54);
    DungeonRunFrameActions(0x3B);
    GetEntInfo(attacker)->action.direction = attackerDirection & DIRECTION_MASK;

    tileEntity = GetTile(attackerPos.x, attackerPos.y)->monster;
    if (!EntityIsValid(tileEntity)) {
        sub_80694C0(attacker, attackerPos.x, attackerPos.y, 1);
        sub_807F9BC(attacker);
    }
    else {
        for (directionId = 0; directionId < NUM_DIRECTIONS; directionId++) {
            DungeonPos pos;

            pos.x = gAdjacentTileOffsets[directionId].x + attackerPos.x;
            pos.y = gAdjacentTileOffsets[directionId].y + attackerPos.y;
            if (!sub_80703A0(attacker, &pos)) {
                attackerPos = pos;
                break;
            }
        }
        if (directionId == NUM_DIRECTIONS) {
            WarpTarget(target, attacker, 0, NULL);
        }
        else {
            sub_807D068(attacker, &attackerPos);
            sub_80694C0(attacker, attackerPos.x, attackerPos.y, 1);
        }

        if (GetEntityType(tileEntity) == ENTITY_MONSTER) {
            Move move;

            InitPokemonMove(&move, MOVE_REGULAR_ATTACK);
            if (!sub_80571F0(tileEntity, &move)) {
                sub_806F370(target, tileEntity, gHurlOrbDmgValue, FALSE, NULL, TYPE_NONE, 0x21A, 0, 0, 0);
            }
            if (EntityIsValid(tileEntity)) {
                sub_806CE68(tileEntity, GetEntInfo(tileEntity)->action.direction);
            }
        }

        sub_806F370(target, attacker, gHurlOrbDmgValue, FALSE, NULL, TYPE_NONE, 0x219, 0, 0, 0);
        if (EntityIsValid(attacker)) {
            sub_806CE68(attacker, GetEntInfo(attacker)->action.direction);
        }
        sub_803E708(0x1E, 0x3B);
        sub_807F9BC(attacker);
    }
}

void sub_807F9BC(Entity *entity)
{
    if (EntityIsValid(entity)) {
        EntityInfo *entInfo = GetEntInfo(entity);
        if (entInfo->isTeamLeader) {
            gDungeon->unk1 = 0;
            gDungeon->unk5C0 = -1;
            sub_804AC20(&entity->pos);
            sub_807EC28(FALSE);
        }
        sub_806A5B8(entity);
        sub_8075900(entity, gDungeon->forceMonsterHouse);
    }
}
