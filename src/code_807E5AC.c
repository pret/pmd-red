#include "global.h"
#include "weather.h"
#include "code_804267C.h"
#include "code_803E46C.h"
#include "dungeon.h"
#include "dungeon_config.h"
#include "dungeon_leader.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "structs/map.h"
#include "dungeon_message.h"
#include "dungeon_logic.h"
#include "string_format.h"
#include "dungeon_logic.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_logic.h"
#include "position_util.h"
#include "dungeon_ai.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "code_805D8C8.h"
#include "code_803E668.h"
#include "dungeon_items.h"
#include "move_util.h"
#include "moves.h"
#include "math.h"
#include "constants/ability.h"
#include "constants/monster.h"
#include "constants/type.h"
#include "dungeon_misc.h"
#include "code_807E5AC.h"
#include "sprite.h"

extern SpriteOAM gUnknown_202EDC0;

extern s32 GetMonsterApparentID(Entity *pokemon, s32 id);
extern void sub_807EC28(bool8 arg0);

void sub_807EFFC(bool8 arg0);
s32 sub_807F19C(bool8 arg0);
void sub_807E8F0(Entity *pokemon);
bool8 sub_807EF48(void);
void sub_807F33C(void);

extern const u8 *gWeatherNames[];

extern const u8 *const gUnknown_80FC5E0;
extern const u8 *const gUnknown_80FA778;
extern const u8 *const gUnknown_80FA758;
extern const u8 *const gUnknown_80FE674;
extern const u8 *const gUnknown_80FE65C;
extern const u8 *const gUnknown_80FE63C;
extern const u8 *const gUnknown_80FE5F0;
extern const u8 *const gUnknown_80FAD8C;
extern const u8 *const gUnknown_80FADB0;
extern const u8 *const gUnknown_80FE5C0;
extern const u8 *const gUnknown_80FE4F4;
extern const u8 *const gUnknown_80FE568;
extern const u8 *const gUnknown_80FE520;
extern const u8 *const gUnknown_80FE4D4;
extern const u8 *const gUnknown_80FE4B8;


extern void sub_80833E8(DungeonPos *param_1, s32 *param_2);
extern void sub_806A5B8(Entity *);
extern bool8 sub_8045888(Entity *ent);
extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
extern void sub_807D068(Entity *, DungeonPos *);

void sub_807F9BC(Entity *entity);

extern const u8 *const gUnknown_80FCB40;
extern const u8 *const gUnknown_80FCB70;
extern const u8 *const gUnknown_80FE6B4;
extern const u8 *const gUnknown_80FE690;

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

extern u8 sub_803D6FC(void);

void sub_807FA18(void)
{
    s32 x, y;

    for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++) {
        for (x = 0; x < DUNGEON_MAX_SIZE_X; x++) {
            Tile *tile = GetTileMut(x, y);

            if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_TRAP) {
                s32 trapId;
                DungeonPos pos = {x, y};

                if (tile->spawnOrVisibilityFlags & SPAWN_FLAG_UNK6) {
                    trapId = TRAP_WARP_TRAP;
                }
                else {
                    trapId = sub_803D6FC();
                }

                if (trapId == TRAP_WONDER_TILE) {
                    Entity *trap = SpawnTrap(trapId, &pos, 2);
                    if (trap != NULL) {
                        tile->object = trap;
                        trap->isVisible = TRUE;
                    }
                }
                else {
                    Entity *trap = SpawnTrap(trapId, &pos, 0);
                    if (trap != NULL) {
                        tile->object = trap;
                        trap->isVisible = FALSE;
                    }
                }
            }
        }
    }
}

void sub_807FA9C(void)
{
    s32 x, y;
    bool8 showInvisibles = gDungeon->unk181e8.showInvisibleTrapsMonsters;

    for (y = gDungeon->unk181e8.cameraPos.y - 5; y < gDungeon->unk181e8.cameraPos.y + 5; y++) {
        for (x = gDungeon->unk181e8.cameraPos.x - 6; x < gDungeon->unk181e8.cameraPos.x + 6; x++) {
            bool8 r6 = FALSE;
            const Tile *tile = GetTile(x, y);

            if (tile->object != NULL && GetEntityType(tile->object) == ENTITY_TRAP && (tile->object->isVisible || showInvisibles)) {
                r6 = TRUE;
            }
            if (tile->terrainType & TERRAIN_TYPE_STAIRS) {
                r6 = TRUE;
            }

            if (r6) {
                s32 spriteX = (x * 24) - gDungeon->unk181e8.cameraPixelPos.x;
                s32 spriteY = (y * 24) - gDungeon->unk181e8.cameraPixelPos.y;
                if (spriteX >= -32 && spriteY >= -32 && spriteX <= 272 && spriteY <= 192)  {
                    SpriteSetObjMode(&gUnknown_202EDC0, 0);
                    SpriteSetY(&gUnknown_202EDC0, spriteY);
                    SpriteSetX(&gUnknown_202EDC0, spriteX);
                    SpriteSetPriority(&gUnknown_202EDC0, 3);
                    SpriteSetPalNum(&gUnknown_202EDC0, 10);
                    SpriteSetTileNum(&gUnknown_202EDC0, 0x1FC);

                    AddSprite(&gUnknown_202EDC0, 0, NULL, NULL);
                }
            }
        }
    }
}

//
