#include "global.h"
#include "structs/str_dungeon.h"
#include "code_803E724.h"
#include "code_80450F8.h"
#include "dungeon_map_access.h"
#include "dungeon_range.h"
#include "dungeon_util.h"
#include "tile_types.h"
#include "pokemon.h"
#include "code_805D8C8.h"

extern u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE];
extern u8 gUnknown_202EE76[DUNGEON_MAX_WILD_POKEMON_BODY_SIZE];
extern void sub_8045ACC(void);
extern s32 GetMonsterApparentID(Entity *pokemon, s32 id);

Entity *sub_80453AC(s32 _species)
{
    s32 i;
    s32 species = (s16) _species;
    s32 validId = -1;
    s32 bodySize = GetBodySize(species);

    for (i = 0; i <= MAX_TEAM_BODY_SIZE - bodySize; i++) {
        s32 j;
        for (j = 0; j < bodySize; j++) {
            if (gUnknown_202EE70[i + j] != 0)
                break;
        }

        if (j == bodySize) {
            validId = i;
            break;
        }
    }

    if (validId != -1) {
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            s32 apparentId;
            s32 j;
            Entity *entity = gDungeon->teamPokemon[i];

            if (!EntityExists(entity)) {
                entity->type = ENTITY_MONSTER;
                entity->unk24 = i;
                entity->axObj.info.monster = &gDungeon->unk69C[i];
                entity->axObj.info.monster->id = species;
                apparentId = (s16) GetMonsterApparentID(NULL, species);
                entity->axObj.info.monster->apparentID = apparentId;
                entity->axObj.info.monster->isNotTeamMember = FALSE;

                entity->axObj.spriteFile = GetSpriteData((s16)GetMonsterApparentID(NULL, species));
                entity->axObj.unk40_maybeAnimTimer = (validId  * 16) + 0x40;
                entity->axObj.unk42_animId1 = 7;
                entity->axObj.unk44_direction1 = 0;
                entity->axObj.unk43_animId2 = 0xFF;
                entity->axObj.unk45_orientation = 1;
                entity->axObj.unk47 = 1;

                entity->unk1C = 0;
                sub_8045ACC();
                entity->axObj.info.monster->unk167 = validId;
                entity->axObj.info.monster->unk168 = bodySize;

                for (j = 0; j < bodySize; j++) {
                    gUnknown_202EE70[validId] = 1;
                    validId++;
                }

                entity->spawnGenID = gDungeon->unk644.unk24++;
                return entity;
            }
        }
    }

    return NULL;
}

Entity *sub_804550C(s32 _species)
{
    s32 i;
    s32 species = (s16) _species;
    s32 validId = -1;
    s32 bodySize = GetBodySize(species);

    for (i = 0; i <= DUNGEON_MAX_WILD_POKEMON_BODY_SIZE - bodySize; i++) {
        s32 j;
        for (j = 0; j < bodySize; j++) {
            if (gUnknown_202EE76[i + j] != 0)
                break;
        }

        if (j == bodySize) {
            validId = i;
            break;
        }
    }

    if (validId != -1) {
        for (i = 0; i < DUNGEON_MAX_WILD_POKEMON_BODY_SIZE; i++) {
            s32 j;
            Entity *entity = gDungeon->wildPokemon[i];

            if (!EntityExists(entity)) {
                entity->type = ENTITY_MONSTER;
                entity->unk24 = i;
                entity->unk22 = 0;
                entity->axObj.info.monster = &gDungeon->unkEBC[i];
                entity->axObj.info.monster->id = species;
                entity->axObj.info.monster->apparentID = GetMonsterApparentID(NULL, species);
                entity->axObj.info.monster->isNotTeamMember = TRUE;

                entity->axObj.spriteFile = GetSpriteData((s16)GetMonsterApparentID(NULL, species));
                entity->axObj.unk40_maybeAnimTimer = ((validId + 6) * 16) + 0x40;
                entity->axObj.unk42_animId1 = 7;
                entity->axObj.unk44_direction1 = 0;
                entity->axObj.unk43_animId2 = 0xFF;
                entity->axObj.unk45_orientation = 1;
                entity->axObj.unk47 = 1;

                entity->unk1C = 0;

                entity->axObj.info.monster->unk167 = validId;
                entity->axObj.info.monster->unk168 = bodySize;

                for (j = 0; j < bodySize; j++) {
                    gUnknown_202EE76[validId] = 1;
                    validId++;
                }

                sub_8045ACC();

                entity->spawnGenID = gDungeon->unk644.unk24++;
                return entity;
            }
        }
    }

    return NULL;
}

Entity *SpawnTrap(u8 trapID, DungeonPos *pos, u8 c)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_TRAPS; i++) {
        entity = gDungeon->traps[i];
        if (!EntityExists(entity)) {
            entity->type = ENTITY_TRAP;
            entity->axObj.info.trap = &gDungeon->unk3908[i];
            entity->axObj.info.trap->id = trapID;
            entity->axObj.info.trap->unk1 = c;

            entity->unk1C = 0;
            entity->unk22 = 0;
            entity->pos = *pos;
            entity->spawnGenID = 0;
            return entity;
        }
    }

    return NULL;
}

Entity *sub_8045708(DungeonPos *pos)
{
    s32 i;
    Entity *ent;

    if (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA
        && (GetTileMut(pos->x, pos->y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY) {
        return NULL;
    }

    for (i = 0; i < DUNGEON_MAX_ITEMS; i++) {
        ent = gDungeon->items[i];
        if (!EntityExists(ent)) {
            ent->type = ENTITY_ITEM;
            ent->axObj.info.item = &gDungeon->unk3804[i];

            ent->pos = *pos;
            SetEntityPixelPos(ent, ((pos->x * 24) + 4) * 0x100, ((pos->y * 24) + 4) * 0x100);
            ent->spawnGenID = 0;
            ent->unk22 = 0;
            ent->unk1C = 0;
            return ent;
        }
    }

    return NULL;
}

void sub_80457DC(Entity* ent)
{
    ent->type = ENTITY_UNK_5;
    ent->pos.x = 0;
    ent->pos.y = 0;
    SetEntityPixelPos(ent, 0, 0);
    ent->spawnGenID = 0;
    ent->unk22 = 0;
}

bool8 sub_8045804(Entity *ent)
{
    UnkDungeonGlobal_unk181E8_sub* saveTyping;
    Entity* camTarget;
    EntityInfo *monInfo;

    switch (GetEntityType(ent)) {
        case ENTITY_MONSTER: {
            if (ent->isVisible) {
                saveTyping = &gDungeon->unk181e8;
                camTarget = saveTyping->cameraTarget;
                monInfo = GetEntInfo(ent);

                if (!monInfo->isNotTeamMember)
                    return TRUE;

                if (!saveTyping->unk1820F && monInfo->invisibleClassStatus.status == STATUS_INVISIBLE)
                    return FALSE;

                if (saveTyping->unk1820B || saveTyping->unk1820D)
                    return TRUE;

                if (camTarget != NULL)
                    return IsPositionActuallyInSight(&saveTyping->cameraPos, &ent->pos);
            }
            return FALSE;
        }
        /*case ENTITY_TRAP:
        case ENTITY_ITEM:
        case ENTITY_UNK_4:*/
        default: {
            return TRUE;
        }
        case ENTITY_NOTHING:
        case ENTITY_UNK_5: {
            return FALSE;
        }
    }
}

bool8 sub_8045888(Entity *ent)
{
    if (ent->isVisible) {
        s32 x = (ent->pixelPos.x / 256) - gDungeon->unk181e8.cameraPixelPos.x;
        s32 y = (ent->pixelPos.y / 256) - gDungeon->unk181e8.cameraPixelPos.y;

        if (x >= -32 && y >= -32 && x <= 272 && y <= 192) {
            UnkDungeonGlobal_unk181E8_sub *saveTyping = &gDungeon->unk181e8;

            switch (GetEntityType(ent)) {
                case ENTITY_ITEM: {
                    if (!saveTyping->unk1820E && !sub_803F428(&ent->pos))
                        return FALSE;
                    break;
                }
                case ENTITY_MONSTER: {
                    EntityInfo *monInfo = GetEntInfo(ent);

                    if (monInfo->isNotTeamMember) {
                        if (!gDungeon->unk181e8.unk1820F && monInfo->invisibleClassStatus.status == STATUS_INVISIBLE)
                            return FALSE;

                        if (!saveTyping->unk1820D && !sub_803F428(&ent->pos))
                            return FALSE;
                    }
                    break;
                }
                case ENTITY_TRAP: {
                    if (!gDungeon->unk181e8.unk1820F && !ent->isVisible)
                        return FALSE;
                    break;
                }
                case ENTITY_NOTHING:
                case ENTITY_UNK_5: {
                    return FALSE;
                }
                case ENTITY_UNK_4:
                default: {
                    break;
                }
            }

            return TRUE;
        }
    }

    return FALSE;
}
