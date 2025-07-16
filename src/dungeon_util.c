#include "global.h"
#include "globaldata.h"
#include "dungeon_util.h"
#include "structs/str_dungeon.h"
#include "structs/str_traps.h"
#include "structs/map.h"
#include "code_8041AD0.h"
#include "code_806CD90.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "code_803E724.h"
#include "dungeon_range.h"
#include "pokemon.h"
#include "code_805D8C8.h"
#include "constants/status.h"
#include "constants/item.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "dungeon_pokemon_sprites.h"
#include "dungeon_music.h"
#include "dungeon_map.h"
#include "string_format.h"
#include "items.h"
#include "trap.h"

extern const u8 *gUnknown_80FE6F4[];

extern void sub_8045ACC(void);
extern s32 GetMonsterApparentID(Entity *pokemon, s32 id);
extern void sub_8045BF8(u8 *, Item *);

EWRAM_DATA u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE] = {0};
EWRAM_DATA u8 gUnknown_202EE76[DUNGEON_MAX_WILD_POKEMON_BODY_SIZE] = {0};

bool8 EntityIsValid(Entity *entity)
{
    if (!entity)
    {
        return FALSE;
    }
    return entity->type != ENTITY_NOTHING;
}

u32 GetEntityType(Entity *entity)
{
    return entity->type;
}

u8 GetEntityRoom(Entity *entity)
{
    return entity->room;
}

Trap* GetTrapInfo(Entity *entity)
{
    return entity->axObj.info.trap;
}

Item* GetItemInfo(Entity *entity)
{
    return entity->axObj.info.item;
}

Trap* GetTrapData_1(Entity *entity)
{
    return entity->axObj.info.trap;
}

Item* GetItemData_1(Entity *entity)
{
    return entity->axObj.info.item;
}

const Tile *GetTileAtEntity(Entity *entity)
{
    return GetTile(entity->pos.x, entity->pos.y);
}

Tile *GetTileAtEntitySafe(Entity *entity)
{
    return GetTileMut(entity->pos.x, entity->pos.y);
}

void sub_804513C(void)
{
  s32 index;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
      gDungeon->teamPokemon[index] = &gDungeon->teamPokemonEntities[index];
      gDungeon->teamPokemon[index]->type = ENTITY_NOTHING;
  }

  for(index = 0; index < MAX_TEAM_BODY_SIZE; index++)
  {
      gUnknown_202EE70[index] = 0;
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
  {
      gDungeon->wildPokemon[index] = &gDungeon->wildPokemonEntities[index];
      gDungeon->wildPokemon[index]->type = ENTITY_NOTHING;
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON_BODY_SIZE; index++)
  {
      gUnknown_202EE76[index] = 0;
  }

  for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
  {
      gDungeon->activePokemon[index] = NULL;
  }

  for (index = 0; index < DUNGEON_MAX_ITEMS; index++)
  {
      gDungeon->items[index] = &gDungeon->itemEntities[index];
      gDungeon->items[index]->type = ENTITY_NOTHING;
  }

  for(index = 0; index < DUNGEON_MAX_TRAPS; index++)
  {
      gDungeon->traps[index] = &gDungeon->trapEntites[index];
      gDungeon->traps[index]->type = ENTITY_NOTHING;
  }
}

void sub_804522C(void)
{
    s32 index;
    Entity *entity;
    Entity *entity2;
    EntityInfo *info;
    u32 statusSprites;
    bool8 crossEyed;

    crossEyed = gDungeon->unk181e8.hallucinating;
    if (gDungeon->unk181e8.blinded)
    {
        for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
        {
            entity = gDungeon->activePokemon[index];
            if(EntityIsValid(entity))
            {
                if(entity == gDungeon->unk181e8.cameraTarget)
                {
                    sub_806C51C(entity);
                }
                else
                {
                    info = GetEntInfo(entity);
                    statusSprites = EntityGetStatusSprites(entity);
                    UpdateDungeonPokemonSprite(info->dungeonSpriteId, info->apparentID, statusSprites, FALSE);
                }
            }
        }
    }
    else
    {
        for(index = 0; index < MAX_TEAM_MEMBERS; index++)
        {
            entity2 = gDungeon->teamPokemon[index];
            if(EntityIsValid(entity2))
            {
                sub_806C51C(entity2);
            }
        }
        for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
        {
            entity2 = gDungeon->wildPokemon[index];
            if(EntityIsValid(entity2))
            {
                sub_806C51C(entity2);
            }
        }

        for(index = 0; index < gDungeon->numItems; index++)
        {
            sub_80462AC(gDungeon->items[index], crossEyed, 1, 0xFF, 0);
        }

        if(crossEyed)
            sub_807FA9C();
    }
}

void UpdateEntityPixelPos(Entity *entity, PixelPos *pos)
{
    if (pos != NULL) {
        entity->pixelPos.x = pos->x;
        entity->pixelPos.y = pos->y;
    }
    else {
        entity->pixelPos.x = X_POS_TO_PIXELPOS(entity->pos.x);
        entity->pixelPos.y = Y_POS_TO_PIXELPOS(entity->pos.y);
    }
}

void SetEntityPixelPos(Entity *entity, s32 x, s32 y)
{
    entity->pixelPos.x = x;
    entity->pixelPos.y = y;
}

void IncreaseEntityPixelPos(Entity *entity, s32 x, s32 y)
{
    entity->pixelPos.x += x;
    entity->pixelPos.y += y;
}

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

            if (!EntityIsValid(entity)) {
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

                entity->unk1C = IntToF248(0);
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

            if (!EntityIsValid(entity)) {
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

                entity->unk1C = IntToF248(0);

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
        if (!EntityIsValid(entity)) {
            entity->type = ENTITY_TRAP;
            entity->axObj.info.trap = &gDungeon->unk3908[i];
            entity->axObj.info.trap->id = trapID;
            entity->axObj.info.trap->unk1 = c;

            entity->unk1C = IntToF248(0);
            entity->unk22 = 0;
            entity->pos = *pos;
            entity->spawnGenID = 0;
            return entity;
        }
    }

    return NULL;
}

Entity *SpawnItemEntity(DungeonPos *pos)
{
    s32 i;
    Entity *ent;

    if (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA
        && (GetTileMut(pos->x, pos->y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY) {
        return NULL;
    }

    for (i = 0; i < DUNGEON_MAX_ITEMS; i++) {
        ent = gDungeon->items[i];
        if (!EntityIsValid(ent)) {
            ent->type = ENTITY_ITEM;
            ent->axObj.info.item = &gDungeon->unk3804[i];

            ent->pos = *pos;
            SetEntityPixelPos(ent, ((pos->x * 24) + 4) * 0x100, ((pos->y * 24) + 4) * 0x100);
            ent->spawnGenID = 0;
            ent->unk22 = 0;
            ent->unk1C = IntToF248(0);
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

                if (!saveTyping->showInvisibleTrapsMonsters && monInfo->invisibleClassStatus.status == STATUS_INVISIBLE)
                    return FALSE;

                if (saveTyping->allTilesRevealed || saveTyping->unk1820D)
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

bool8 ShouldDisplayEntity(Entity *ent)
{
    if (ent->isVisible) {
        s32 x = (ent->pixelPos.x / 256) - gDungeon->unk181e8.cameraPixelPos.x;
        s32 y = (ent->pixelPos.y / 256) - gDungeon->unk181e8.cameraPixelPos.y;

        if (x >= -32 && y >= -32 && x <= 272 && y <= 192) {
            UnkDungeonGlobal_unk181E8_sub *saveTyping = &gDungeon->unk181e8;

            switch (GetEntityType(ent)) {
                case ENTITY_ITEM: {
                    if (!saveTyping->showAllFloorItems && !sub_803F428(&ent->pos))
                        return FALSE;
                    break;
                }
                case ENTITY_MONSTER: {
                    EntityInfo *monInfo = GetEntInfo(ent);

                    if (monInfo->isNotTeamMember) {
                        if (!gDungeon->unk181e8.showInvisibleTrapsMonsters && monInfo->invisibleClassStatus.status == STATUS_INVISIBLE)
                            return FALSE;

                        if (!saveTyping->unk1820D && !sub_803F428(&ent->pos))
                            return FALSE;
                    }
                    break;
                }
                case ENTITY_TRAP: {
                    if (!gDungeon->unk181e8.showInvisibleTrapsMonsters && !ent->isVisible)
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

bool8 CanSeeTarget(Entity *entity, Entity *targetEntity)
{
    if (!EntityIsValid(entity) || !EntityIsValid(targetEntity) || !targetEntity->isVisible)
    {
        return FALSE;
    }
    if (targetEntity->type == ENTITY_MONSTER)
    {
        if (entity->type == ENTITY_MONSTER)
        {
            if (!CanSeeInvisibleMonsters(entity) && GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
            {
                return FALSE;
            }
            if (GetEntInfo(entity)->blinkerClassStatus.status == STATUS_BLINKER)
            {
                return FALSE;
            }
        }
        else if (GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
        {
            return FALSE;
        }
    }
    return IsPositionActuallyInSight(&entity->pos, &targetEntity->pos);
}

bool8 CanTargetEntity(Entity *entity, Entity *targetEntity)
{
    if (!EntityIsValid(entity) || !EntityIsValid(targetEntity) || !targetEntity->isVisible)
    {
        return FALSE;
    }
    if (targetEntity->type == ENTITY_MONSTER)
    {
        if (entity->type == ENTITY_MONSTER)
        {
            if (!CanSeeInvisibleMonsters(entity) && GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
            {
                return FALSE;
            }
            if (GetEntInfo(entity)->blinkerClassStatus.status == STATUS_BLINKER)
            {
                return FALSE;
            }
        }
        else if (GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
        {
            return FALSE;
        }
    }
    return IsPositionInSight(&entity->pos, &targetEntity->pos);
}

bool8 sub_8045A70(Entity *entity, Entity *targetEntity)
{
    if (EntityIsValid(entity) && EntityIsValid(targetEntity) && targetEntity->isVisible)
    {
         return IsPositionActuallyInSight(&entity->pos, &targetEntity->pos);
    }
   return FALSE;
}

bool8 sub_8045AAC(Entity *entity, DungeonPos *pos)
{
    return IsPositionActuallyInSight(&entity->pos, pos);
}

bool8 CanTargetPosition(Entity *entity, DungeonPos *pos)
{
    return IsPositionInSight(&entity->pos, pos);
}

void sub_8045ACC(void)
{
  Entity *entity;
  s32 index;
  s32 pokeCount;

  pokeCount = 0;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (EntityIsValid(entity)) {
      gDungeon->activePokemon[pokeCount] = entity;
      pokeCount++;
    }
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
  {
    entity = gDungeon->wildPokemon[index];
    if (EntityIsValid(entity)) {
      gDungeon->activePokemon[pokeCount] = entity;
      pokeCount++;
    }
  }
  for (; pokeCount < DUNGEON_MAX_POKEMON; pokeCount++) {
    gDungeon->activePokemon[pokeCount] = NULL;
  }
}

s32 GetTeamMemberEntityIndex(Entity *pokemon)
{
  Entity *entity;
  s32 index;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (pokemon == entity)
      return index;
  }
  return -1;
}

void SubstitutePlaceholderStringTags(u8 *buffer, Entity *entity, u32 param_3)
{
  switch(GetEntityType(entity))
  {
    case ENTITY_MONSTER:
        SetMessageArgument_2(buffer, GetEntInfo(entity), param_3);
        break;
    case ENTITY_ITEM:
        sub_8045BF8(buffer, GetItemData_1(entity));
        break;
    case ENTITY_TRAP:
        GetTrapName(buffer, GetTrapData_1(entity)->id);
        break;
    default:
        strcpy(buffer, *gUnknown_80FE6F4);
        break;
  }
}
