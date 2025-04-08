#include "global.h"
#include "globaldata.h"
#include "constants/ability.h"
#include "constants/weather.h"
#include "dungeon_vram.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "structs/str_dungeon.h"
#include "code_8077274_1.h"
#include "dungeon_ai.h"
#include "run_dungeon.h"
#include "dungeon_generation.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "moves.h"
#include "move_util.h"
#include "code_8041AD0.h"
#include "code_803E668.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"

extern void sub_807EC28(u32);
extern const DungeonPos gUnknown_80F4468[];

void HandleTrawlOrbAction(Entity *user, Entity *target)
{
    Entity itemEntities[25];
    Item itemInfo[25];
    DungeonPos targetTilePos[25];
    PixelPos itemVelocity[25];
    bool8 targetTileUsed[30];
    s32 i;
    s32 itemsCount;
    bool8 hasTrawled;
    bool8 hallucinating;
    Entity *currItemEntity;

    hasTrawled = FALSE;
    itemsCount = 0;
    currItemEntity = &itemEntities[0];

    for (i = 0; i < gDungeon->numItems; i++) {
        Entity *dungeonItem = gDungeon->items[i];
        if (EntityIsValid(dungeonItem)) {
            if (itemsCount >= 25)
                break;

            if ((abs(dungeonItem->pos.x - user->pos.x) > 2 || abs(dungeonItem->pos.y - user->pos.y) > 2)
                && GetTerrainType(GetTile(dungeonItem->pos.x, dungeonItem->pos.y)) != TERRAIN_TYPE_WALL)
            {
                currItemEntity->type = ENTITY_ITEM;
                currItemEntity->axObj.info.item = &itemInfo[itemsCount];
                currItemEntity->pos = dungeonItem->pos;
                SetEntityPixelPos(currItemEntity, (dungeonItem->pos.x * 24 + 4) * 256, (dungeonItem->pos.y * 24 + 4) * 256);
                currItemEntity->spawnGenID = 0;
                currItemEntity->isVisible = TRUE;
                currItemEntity->unk22 = 0;
                currItemEntity->unk1C = IntToF248_2(0);
                itemInfo[itemsCount] = gDungeon->unk3804[i];
                currItemEntity++;
                itemsCount++;
            }
        }
    }

    if (itemsCount == 0) {
        LogMessageByIdWithPopupCheckUser(user, gUnknown_80FE034);
    }
    else {
        s32 var;
        s32 i;
        s32 unkAngle;
        s32 animFrame;

        for (i = 0; i < 30; i++) {
            targetTileUsed[i] = FALSE;
        }
        for (i = 0; i < itemsCount; i++) {
            s32 j = 0;
            bool8 foundTile = FALSE;
            DungeonPos pos;

            pos.x = user->pos.x;
            pos.y = user->pos.y;

            for (j = 0; j < 30; j++) {
                if (gUnknown_80F4468[j].x == 99)
                    break;
                if (!targetTileUsed[j]) {
                    const Tile *tile;

                    pos.x = user->pos.x + gUnknown_80F4468[j].x;
                    pos.y = user->pos.y + gUnknown_80F4468[j].y;

                    tile = GetTile(pos.x, pos.y);
                    if (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL && !(tile->terrainType & TERRAIN_TYPE_STAIRS) && tile->object == NULL) {
                        targetTilePos[i] = pos;
                        targetTileUsed[j] = TRUE;
                        foundTile = TRUE;
                        break;
                    }
                }
            }

            if (!foundTile) {
                itemEntities[i].type = ENTITY_NOTHING;
                targetTilePos[i].x = -1;
                targetTilePos[i].y = -1;
            }
        }

        for (i = 0; i < itemsCount; i++) {
            if (EntityIsValid(&itemEntities[i])) {
                RemoveItemFromDungeonAt(&itemEntities[i].pos, 1);
                ShowDungeonMapAtPos(itemEntities[i].pos.x, itemEntities[i].pos.y);
                itemVelocity[i].x = (((targetTilePos[i].x * 24 + 4) * 256) - itemEntities[i].pixelPos.x) / 60;
                itemVelocity[i].y = (((targetTilePos[i].y * 24 + 4) * 256) - itemEntities[i].pixelPos.y) / 60;
            }
        }

        sub_80421C0(user, 0x1A2);

        var = 0;
        hallucinating = gDungeon->unk181e8.hallucinating;
        unkAngle = 0;
        for (animFrame = 0; animFrame < 60; animFrame++) {
            for (i = 0; i < itemsCount; i++) {
                if (EntityIsValid(&itemEntities[i])) {
                    IncreaseEntityPixelPos(&itemEntities[i], itemVelocity[i].x, itemVelocity[i].y);
                    itemEntities[i].unk1C.raw = sin_4096(unkAngle) * 0xC;
                    sub_80462AC(&itemEntities[i], hallucinating, 0, var, 0);
                }
            }

            DungeonRunFrameActions(0x13);
            unkAngle += 0x22;
            if (!(animFrame & 3)) {
                var++;
            }
            var &= 7;
        }

        for (i = 0; i < itemsCount; i++) {
            if (targetTilePos[i].x >= 0) {
                AddItemToDungeonAt(&targetTilePos[i], GetItemData(&itemEntities[i]), 1);
                ShowDungeonMapAtPos(targetTilePos[i].x, targetTilePos[i].y);
                hasTrawled = TRUE;
            }
        }

        if (hasTrawled) {
            LogMessageByIdWithPopupCheckUser(user, gUnknown_80FE060);
        }
        else {
            LogMessageByIdWithPopupCheckUser(user, gUnknown_80FE034);
        }
        sub_807EC28(1);
    }
}

