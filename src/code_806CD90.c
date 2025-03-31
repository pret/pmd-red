#include "global.h"
#include "globaldata.h"
#include "constants/direction.h"
#include "constants/status.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "structs/str_dungeon.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "dungeon_logic.h"
#include "dungeon_config.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_misc.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "move_effects_target.h"
#include "pokemon.h"
#include "position_util.h"
#include "random.h"
#include "sprite.h"
#include "status.h"
#include "text_util.h"
#include "sprite.h"
#include "random.h"
#include "code_800F958.h"
#include "structs/str_202ED28.h"

const u8 gUnknown_8106EC8[][13] = {
    {0, 1, 7, 7, 7, 5, 6, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 5, 6, 7, 7, 7, 7, 7, 7},
    {7, 7, 7, 7, 7, 5, 6, 7, 7, 7, 7, 11, 7},
};

const u8 gUnknown_8106EEF[] = {0x03, 0x04, 0x05, 0x00, 0x00, 0x70, 0x6b, 0x73, 0x64, 0x69, 0x72, 0x30, 0x00 };

extern s32 gDungeonFramesCounter;

extern void sub_8042EC8(Entity *a0, s32 a1);
extern void sub_800F958(s32 dungeonSpriteID, DungeonPos *pos, DungeonPos *statusOffsets, u32 a3);

static inline u16 GetUnkFlag(Entity *entity)
{
    if ((entity->axObj.axdata.flags & 0x2000))
        return 0;
    else
        return entity->axObj.axdata.flags >> 15;
}

void sub_806C51C(Entity *entity)
{
    s32 x, y, y2;
    bool8 var_3C;
    bool8 decoySprite;
    s32 var_34;
    DungeonPos pos1;
    DungeonPos posArray[4];
    u32 statusSprites;
    bool8 r4;
    u8 r7;
    unkStruct_2039DB0 spriteMasks;
    s32 xSprite, ySprite;

    EntityInfo *entInfo = GetEntInfo(entity);
    if (gDungeon->unk181e8.cameraTarget == entity) {
        decoySprite = FALSE;
    }
    else {
        decoySprite = gDungeon->unk181e8.hallucinating;
    }

    if (entInfo->curseClassStatus.status == STATUS_DECOY) {
        decoySprite = TRUE;
    }

    if (entity->axObj.unk43_animId2 == entity->axObj.unk42_animId1 && entity->axObj.unk45_orientation == entity->axObj.unk44_direction1 && entity->axObj.unk47 == 0) {
        bool8 r2 = FALSE;

        if (!GetUnkFlag(entity))
            r2 = TRUE;

        if (r2) {
            s32 r0;
            s32 r3 = sub_806CEBC(entity);
            entity->unk21 = 1;
            if (entInfo->unkFE == 99) {
                if (entity->axObj.unk43_animId2 <= 12) {
                    s32 r2;
                    if (entInfo->bideClassStatus.status == STATUS_BIDE) {
                        r2 = 2;
                    }
                    else if (entity->unk23 < 3) {
                        r2 = 0;
                    }
                    else {
                        r2 = 1;
                    }

                    r0 = gUnknown_8106EC8[r2][entity->axObj.unk43_animId2];
                    if (r0 == 7) {
                        r0 = r3;
                    }
                }
                else {
                    r0 = 99;
                }
            }
            else {
                r0 = entInfo->unkFE;
            }

            if (r0 != 99) {
                entity->axObj.unk42_animId1 = r0;
                entity->axObj.unk44_direction1 = entity->axObj.unk45_orientation & DIRECTION_MASK;
                entity->axObj.unk47 = 1;
                if (entity->axObj.unk42_animId1 == 6 && ++entity->axObj.unk46 == 16) {
                    entity->axObj.unk42_animId1 = r3;
                }
            }
        }
    }

    if (entity->axObj.unk43_animId2 != entity->axObj.unk42_animId1 || entity->axObj.unk45_orientation != entity->axObj.unk44_direction1 || entity->axObj.unk47 != 0) {
        s32 r7;

        entity->axObj.unk43_animId2 = entity->axObj.unk42_animId1;
        entity->axObj.unk45_orientation = entity->axObj.unk44_direction1;
        entity->axObj.unk47 = 0;
        r7 = entity->axObj.unk40_maybeAnimTimer;
        if (sub_808DA44(entInfo->apparentID, entity->axObj.unk42_animId1)) {
            r7 = 0;
        }

        if (!decoySprite) {
            s32 rnd = Rand32Bit() & 3;
            AxResInitFile(&entity->axObj.axdata, entity->axObj.spriteFile, entity->axObj.unk42_animId1, entity->axObj.unk44_direction1, r7, rnd, FALSE);
        }
        else {
            OpenedFile *spriteData = GetSpriteData(MONSTER_DECOY);
            s32 rnd = Rand32Bit() & 3;
            AxResInitFile(&entity->axObj.axdata, spriteData, entity->axObj.unk42_animId1, entity->axObj.unk44_direction1, r7, rnd, FALSE);
        }

        if (entity->axObj.unk42_animId1 != 6) {
            entity->axObj.unk46 = 0;
        }
    }

    if (gDungeon->unk1356C) {
        if (entity->axObj.unk43_animId2 != 7 || GetMovementType(entInfo->apparentID) == 2) {
            if (entInfo->unk15C != 0) {
                if (entInfo->unk160 == 0) {
                    if (entInfo->unk15F != 0) {
                        RunAxAnimationFrame(&entity->axObj.axdata);
                        RunAxAnimationFrame(&entity->axObj.axdata);
                        RunAxAnimationFrame(&entity->axObj.axdata);
                    }
                    else {
                        RunAxAnimationFrame(&entity->axObj.axdata);
                    }
                }
            }
            else {
                RunAxAnimationFrame(&entity->axObj.axdata);
            }
        }
    }
    else {
        if (entInfo->frozenClassStatus.status != STATUS_FROZEN && entInfo->frozenClassStatus.status != STATUS_PETRIFIED) {
            if (gDungeon->unk644.unk28 != 0 && gDungeon->unk1BDD4.unk1C05F == 0) {
                RunAxAnimationFrame(&entity->axObj.axdata);
                RunAxAnimationFrame(&entity->axObj.axdata);
            }
            else if ((entity->axObj.unk43_animId2 == 0 || entity->axObj.unk43_animId2 == 7) && GetEntInfo(entity)->speedStage > 1) {
                RunAxAnimationFrame(&entity->axObj.axdata);
            }
            RunAxAnimationFrame(&entity->axObj.axdata);
        }
    }

    if (entity->pixelPos.x == entity->prevPixelPos.x && entity->pixelPos.y == entity->prevPixelPos.y) {
        if (entity->unk23 < 10) {
            entity->unk23++;
        }
    }
    else {
        entity->unk23 = 0;
    }

    entity->prevPixelPos.x = entity->pixelPos.x;
    entity->prevPixelPos.y = entity->pixelPos.y;

    x = (entity->pixelPos.x / 256) - gDungeon->unk181e8.cameraPixelPos.x;
    y = (((entity->pixelPos.y - entity->unk1C.raw) - entInfo->unk174.raw) / 256) - gDungeon->unk181e8.cameraPixelPos.y;
    y2 = (entity->pixelPos.y / 256) - gDungeon->unk181e8.cameraPixelPos.y;
    y2 /= 2;
    if (entInfo->unk156 == 0) {
        y2--;
    }

    if (entInfo->unk15C == 0) {
        var_3C = sub_8042768(entity);
    }
    else {
        if (entInfo->unk15D != 0) {
            if (gDungeonFramesCounter & 4) {
                x++;
            }
            else {
                x--;
            }
        }
        var_3C = (entInfo->unk15E == 0);
    }

    pos1.x = entity->pixelPos.x / 256;
    pos1.y = ((entity->pixelPos.y - entity->unk1C.raw) - entInfo->unk174.raw) / 256;

    sub_8005700(posArray, &entity->axObj);
    sub_800F958(entInfo->unk98, &pos1, posArray, gDungeon->unk181e8.priority);

    statusSprites = EntityGetStatusSprites(entity);
    UpdateDungeonPokemonSprite(entInfo->unk98, entInfo->apparentID, statusSprites, (var_3C && entInfo->unk14C));

    sub_8042EC8(entity, y2);
    if (entInfo->unk15C == 0) {
        if (entInfo->unkFF == 1) {
            if (entInfo->unk174.raw <= IntToF248_2(199.999).raw) {
                entInfo->unk174.raw += IntToF248_2(8).raw;
                if (entInfo->unk174.raw > IntToF248_2(200).raw) {
                    entInfo->unk174.raw = IntToF248_2(200).raw;
                }
            }
        }
        else {
            entInfo->unk174.raw -= IntToF248_2(12).raw;
            if (entInfo->unk174.raw < IntToF248_2(0).raw) {
                entInfo->unk174.raw = IntToF248_2(0).raw;
            }
        }
    }

    if (!var_3C)
        return;

    r4 = FALSE;
    r7 = sub_806CF54(entity);

    spriteMasks.unk0 = 0xF3FF;
    spriteMasks.unk2 = 0xFFFF;
    spriteMasks.unk4 = 0xF3FF;
    spriteMasks.unk6 = 0;
    spriteMasks.unk8 = 0;
    spriteMasks.unkA = gDungeon->unk181e8.priority << 10;

    if (entInfo->isNotTeamMember && (entInfo->apparentID == MONSTER_DEOXYS_ATTACK || entInfo->apparentID == MONSTER_DEOXYS_DEFENSE || entInfo->apparentID == MONSTER_DEOXYS_SPEED)) {
        r4 = TRUE;
    }
    if (entInfo->invisibleClassStatus.status == STATUS_INVISIBLE && !gDungeon->unk181e8.showInvisibleTrapsMonsters) {
        r4 = TRUE;
    }
    if (r4) {
        spriteMasks.unk6 |= 0x400;
    }

    var_34 = 0;
    if (!entInfo->isNotTeamMember || entInfo->curseClassStatus.status == STATUS_DECOY) {
        var_34 = 1;
    }
    if (IsExperienceLocked(entInfo->joinedAt.id) || entInfo->monsterBehavior == 1) {
        var_34 = 1;
    }

    if (entInfo->unkFF != 2) {
        s32 overworldPal;

        if (entInfo->frozenClassStatus.status == STATUS_PETRIFIED || entInfo->burnClassStatus.status == STATUS_PARALYSIS || entInfo->frozenClassStatus.status == STATUS_SHADOW_HOLD) {
            x += gDungeonFramesCounter & 2;
        }

        if (decoySprite) {
            overworldPal = GetPokemonOverworldPalette(MONSTER_DECOY, FALSE);
        }
        else {
            overworldPal = GetPokemonOverworldPalette(entInfo->apparentID, FALSE);
        }

        if (entity->unk22 == 0) {
            DoAxFrame_800558C(&entity->axObj.axdata, x, y, y2, overworldPal, &spriteMasks);
        }
        else if (entity->unk22 == 1 && (gDungeonFramesCounter & 1)) {
            DoAxFrame_800558C(&entity->axObj.axdata, x, y, y2, overworldPal, &spriteMasks);
        }
    }

    entInfo->pixelPos.x = (entity->pixelPos.x / 256) + entity->axObj.axdata.sub1.shadow.x;
    entInfo->pixelPos.y = (entity->pixelPos.y / 256) + entity->axObj.axdata.sub1.shadow.y;

    xSprite = entInfo->pixelPos.x - gDungeon->unk181e8.cameraPixelPos.x;
    ySprite = entInfo->pixelPos.y - gDungeon->unk181e8.cameraPixelPos.y;
    if (xSprite >= -32 && ySprite >= -32 && xSprite <= 271 && ySprite <= 191 && r7 != 6 && entity->unk22 == 0) {
        struct unkStruct_202ED28 *spriteStructPtr = &gUnknown_202ED28[var_34][r7];
        if (entInfo->unk156 != 0) {
            SpriteSetX(&spriteStructPtr->sprite, xSprite + spriteStructPtr->pos.x);
            SpriteSetY(&spriteStructPtr->sprite, ySprite + spriteStructPtr->pos.y);

            AddSprite(&spriteStructPtr->sprite, 0, NULL, NULL);
        }
    }
}

void sub_806CC10(void)
{
    EntityInfo *entityInfo;
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity)) {
            entityInfo = GetEntInfo(entity);

            if (entityInfo->unk166 != 0) {
                entityInfo->unk166--;
                if ((entityInfo->unk166 & 1) == 0) // If value is even:
                    sub_806CDD4(entity, 0, (entityInfo->action.direction - 1) & DIRECTION_MASK);
            }
        }
    }
}

void sub_806CC70(void)
{
    s32 i;
    Entity *entity;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CCB4(Entity *entity, u8 a1)
{
    s32 sVar1;
    bool8 flag;
    EntityInfo *info;

    info = GetEntInfo(entity);
    flag = gDungeon->unk181e8.hallucinating;

    if (entity == gDungeon->unk181e8.cameraTarget)
        flag = FALSE;

    entity->axObj.unk43_animId2 = a1;
    entity->axObj.unk42_animId1 = a1;
    entity->axObj.unk45_orientation = info->action.direction;
    entity->axObj.unk44_direction1 = info->action.direction;
    entity->axObj.unk47 = 0;
    sVar1 = entity->axObj.unk40_maybeAnimTimer;

    if (info->curseClassStatus.status != STATUS_DECOY && !flag)
        AxResInitFile(&entity->axObj.axdata,
                      entity->axObj.spriteFile, entity->axObj.unk42_animId1,
                      entity->axObj.unk44_direction1, sVar1,
                      Rand32Bit() & 3, FALSE);
    else
        AxResInitFile(&entity->axObj.axdata,
                      GetSpriteData(MONSTER_DECOY),
                      entity->axObj.unk42_animId1,
                      entity->axObj.unk44_direction1, sVar1, Rand32Bit() & 3,
                      FALSE);

    entity->axObj.unk46 = 0;
}

void sub_806CD90(void)
{
    s32 i;
    Entity *entity;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity))
            sub_806CCB4(entity, sub_806CEBC(entity));
    }
}

void sub_806CDD4(Entity *entity, u8 a1, u32 direction)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = a1;

        if (direction < NUM_DIRECTIONS)
            entity->axObj.unk44_direction1 = direction;
    }
}

void sub_806CDFC(Entity *entity, u8 a1, u32 direction)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        if (entity->axObj.unk43_animId2 == a1 && entity->axObj.unk45_orientation == direction)
            return;
        sub_806CDD4(entity, a1, direction);
    }
}

void sub_806CE34(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = sub_806CEBC(entity);

        if (newDir < NUM_DIRECTIONS) {
            GetEntInfo(entity)->action.direction = newDir & DIRECTION_MASK;
            entity->axObj.unk44_direction1 = newDir & DIRECTION_MASK;
        }
    }
}

void sub_806CE68(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = sub_806CEBC(entity);

        if (newDir < NUM_DIRECTIONS)
            entity->axObj.unk44_direction1 = newDir;
    }
}

void sub_806CE94(Entity *entity, u32 newDir)
{
    if (GetEntityType(entity) == ENTITY_MONSTER) {
        entity->axObj.unk42_animId1 = 6;

        if (newDir < NUM_DIRECTIONS)
            entity->axObj.unk44_direction1 = newDir;
    }
}

u8 sub_806CEBC(Entity *entity)
{
    u8 sleepClassStatus;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(entity);
    sleepClassStatus = entityInfo->sleepClassStatus.status;

    if (sleepClassStatus == STATUS_SLEEP || sleepClassStatus == STATUS_NAPPING || sleepClassStatus == STATUS_NIGHTMARE) {
        if (entityInfo->apparentID != MONSTER_SUDOWOODO || entityInfo->sleepClassStatus.turns != 0x7F)
            return 5;
        else
            return 7;
    }
    if (entityInfo->bideClassStatus.status == STATUS_BIDE)
        return 11;
    return 7;
}

void sub_806CEFC(Entity *entity, u32 newDir)
{
    GetEntInfo(entity)->action.direction = newDir & DIRECTION_MASK;
    sub_806CE68(entity, newDir & DIRECTION_MASK);
}

void sub_806CF18(Entity *entity)
{
    s32 i;
    EntityInfo *entityInfo;

    if (!EntityIsValid(entity))
        return;

    entityInfo = GetEntInfo(entity);
    for (i = 0; i < 100; i++) {
        DungeonRunFrameActions(33);

        if (!sub_808DA44(entityInfo->apparentID, entity->axObj.unk43_animId2))
            break;
    }
}

u8 sub_806CF54(Entity *entity)
{
    return GetEntInfo(entity)->unk204;
}

void sub_806CF60(void)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (EntityIsValid(entity))
            sub_806CF98(entity);
    }
}

u32 sub_806CF98(Entity *entity)
{
    const Tile *mapTile;
    u32 shadowSize;
    u16 terrainType;
    EntityInfo *entityInfo;

    mapTile = GetTileAtEntitySafe(entity);
    terrainType = mapTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    entityInfo = GetEntInfo(entity);
    shadowSize = GetShadowSize(entityInfo->apparentID);

    if (terrainType == (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY))
        return 6;

    if (terrainType == TERRAIN_TYPE_NORMAL) {
        if (IsWaterTileset())
            shadowSize = gUnknown_8106EEF[shadowSize];
    }
    else if (terrainType == TERRAIN_TYPE_SECONDARY && gDungeonWaterType[gDungeon->tileset] != DUNGEON_WATER_TYPE_LAVA)
        shadowSize = gUnknown_8106EEF[shadowSize];

    entityInfo->unk204 = shadowSize;
    return shadowSize;
}
