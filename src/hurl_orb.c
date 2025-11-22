#include "global.h"
#include "globaldata.h"
#include "hurl_orb.h"
#include "dungeon_vram.h"
#include "dungeon_8041AD0.h"
#include "code_805D8C8.h"
#include "dungeon_mon_sprite_render.h"
#include "constants/ability.h"
#include "constants/dungeon_exit.h"
#include "constants/monster.h"
#include "constants/residual_damage.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_info.h"
#include "dungeon_entity_movement.h"
#include "dungeon_config.h"
#include "dungeon_generation.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
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
#include "move_orb_effects_1.h"
#include "move_util.h"
#include "pokemon.h"
#include "position_util.h"
#include "run_dungeon.h"
#include "sprite.h"
#include "string_format.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "weather.h"
#include "dungeon_pos_data.h"
#include "dungeon_damage.h"
#include "dungeon_kecleon_shop.h"
#include "blow_away.h"
#include "warp_target.h"

static void sub_807F9BC(Entity *entity);

void HandleHurlOrb(Entity *target, Entity *attacker)
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
        TryDisplayDungeonLoggableMessage3_Async(target, attacker, gUnknown_80FCB40); // is anchored, cannot be moved
        return;
    }
    if (target == attacker) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
        TryDisplayDungeonLoggableMessage3_Async(target, attacker, gUnknown_80FCB70); // couldn't be thrown for some reason
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
            TryDisplayDungeonLoggableMessage3_Async(target, attacker, gUnknown_80FE6B4); // But it didn~27t go anywhere.
            return;
        }
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], attacker, 0);
    TryDisplayDungeonLoggableMessage3_Async(target, attacker, gUnknown_80FE690); // m0 was sent flying!
    if (ShouldDisplayEntity(attacker)) {
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
        UpdateEntityPixelPos(attacker, &var_54);
        if (ShouldDisplayEntity(attacker)) {
            attacker->unk1C = sin_4096(var_2C) << 5;
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
    attacker->unk1C = 0;
    UpdateEntityPixelPos(attacker, &var_54);
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
                sub_806F370_Async(target, tileEntity, gHurlOrbDmgValue, FALSE, NULL, TYPE_NONE, DUNGEON_EXIT_FELLED_BY_POKEMON_FLYING, RESIDUAL_DAMAGE_REGULAR, 0, 0);
            }
            if (EntityIsValid(tileEntity)) {
                sub_806CE68(tileEntity, GetEntInfo(tileEntity)->action.direction);
            }
        }

        sub_806F370_Async(target, attacker, gHurlOrbDmgValue, FALSE, NULL, TYPE_NONE, DUNGEON_EXIT_FAINTED_FROM_BEING_KNOCKED, RESIDUAL_DAMAGE_REGULAR, 0, 0);
        if (EntityIsValid(attacker)) {
            sub_806CE68(attacker, GetEntInfo(attacker)->action.direction);
        }
        sub_803E708(0x1E, 0x3B);
        sub_807F9BC(attacker);
    }
}

static void sub_807F9BC(Entity *entity)
{
    if (EntityIsValid(entity)) {
        EntityInfo *entInfo = GetEntInfo(entity);
        if (entInfo->isTeamLeader) {
            gDungeon->unk1 = 0;
            gDungeon->unk5C0 = -1;
            DiscoverMinimap(&entity->pos);
            sub_807EC28(FALSE);
        }
        sub_806A5B8(entity);
        TryTriggerMonsterHouseWithMsg_Async(entity, gDungeon->forceMonsterHouse);
    }
}
