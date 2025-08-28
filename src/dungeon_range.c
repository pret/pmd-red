#include "global.h"
#include "globaldata.h"
#include "dungeon_range.h"
#include "dungeon_leader.h"
#include "dungeon_random.h"
#include "dungeon_logic.h"
#include "dungeon_pos_data.h"
#include "dungeon_util.h"
#include "dungeon_vram.h"
#include "sprite.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "structs/map.h"

EWRAM_INIT Entity *gLeaderPointer = NULL;

bool8 IsPositionActuallyInSight(DungeonPos *pos1, DungeonPos *pos2)
{
    u8 pos1Room;
    u8 visibility = gDungeon->unk181e8.visibilityRange;
    const Tile *tile1;
    if (visibility == 0)
    {
        visibility = 2;
    }
    tile1 = GetTile(pos1->x, pos1->y);
    pos1Room = tile1->room;
    if (pos1Room == CORRIDOR_ROOM)
    {
        s32 xDiff = pos1->x - pos2->x;
        s32 yDiff;
        xDiff = xDiff < 0 ? -xDiff : xDiff;
        if (xDiff > visibility)
        {
            return FALSE;
        }

        yDiff = pos1->y - pos2->y;
        yDiff = yDiff < 0 ? -yDiff : yDiff;
        if (yDiff > visibility)
        {
            return FALSE;
        }
        returnTrue:
        return TRUE;
    }
    else
    {
        struct RoomData *pos1RoomData = &gDungeon->roomData[pos1Room];
        if (pos1RoomData->bottomRightCornerX - 1 > pos2->x || pos1RoomData->bottomRightCornerY - 1 > pos2->y ||
            pos1RoomData->topLeftCornerX + 1 <= pos2->x || pos1RoomData->topLeftCornerY + 1 <= pos2->y)
        {
            return FALSE;
        }
        goto returnTrue;
    }
}

bool8 IsPositionInSight(DungeonPos *pos1, DungeonPos *pos2)
{
  const Tile *tile;
  u8 pos1Room;
  s32 xDiff;
  s32 yDiff;
  s32 x1;
  s32 x2;
  s32 y1;
  s32 y2;

  tile = GetTile(pos1->x,pos1->y);
  pos1Room = tile->room;
  if (pos1Room != CORRIDOR_ROOM) {
        struct RoomData *pos1RoomData = &gDungeon->roomData[pos1Room];
        if (pos1RoomData->bottomRightCornerX - 1 > pos2->x || pos1RoomData->bottomRightCornerY - 1 > pos2->y ||
            pos1RoomData->topLeftCornerX + 1 <= pos2->x || pos1RoomData->topLeftCornerY + 1 <= pos2->y)
        {
            goto _08083394;
        }
  }
  else
  {
_08083394:

    x1 = pos1->x;
    x2 = pos2->x;

    y1 = pos1->y;
    y2 = pos2->y;

    yDiff = y1 - y2;
    xDiff = x1 - x2;

    xDiff = xDiff < 0 ? -xDiff : xDiff;
    yDiff = yDiff < 0 ? -yDiff : yDiff;

    if (yDiff < xDiff) {
      yDiff = xDiff;
    }
    if ((2 < yDiff))
returnFalse:
        return FALSE;
    else if((yDiff == 2) && (!IsTargetTwoTilesAway(pos1,pos2))) {
      goto returnFalse;
    }
  }
  return TRUE;
}

void sub_80833E8(DungeonPos *param_1, s32 *param_2)
{
  const Tile *tile;
  struct RoomData *mapRoom;
  u32 visibility;
  u32 room;

  tile = GetTile(param_1->x, param_1->y);
  visibility = gDungeon->unk181e8.visibilityRange;
  if (visibility == 0) {
    visibility = 2;
  }
  room = tile->room;
  if (room == CORRIDOR_ROOM) {
    param_2[0] = param_1->x - visibility;
    param_2[2] = param_1->x + visibility + 1;
    param_2[1] = param_1->y - visibility;
    param_2[3] = param_1->y + visibility + 1;
  }
  else {
    mapRoom = &gDungeon->roomData[room];
    param_2[0] = mapRoom->bottomRightCornerX - 1;
    param_2[2] = mapRoom->topLeftCornerX + 2;
    param_2[1] = mapRoom->bottomRightCornerY - 1;
    param_2[3] = mapRoom->topLeftCornerY + 2;
  }
}

bool8 IsTargetTwoTilesAway(DungeonPos *pos1, DungeonPos *pos2)
{
    s32 i;
    const Tile *tile;
    s32 diff;
    s32 x1;
    s32 y1;
    s32 xDiff;
    s32 yDiff;
    s32 x2;
    s32 y2;

    diff = abs(pos1->x - pos2->x);
    if (diff < 2)
    {
        diff = abs(pos1->y - pos2->y);
        if (diff < 2)
        {
            return TRUE;
        }
    }
    xDiff = abs(pos1->x - pos2->x);
    yDiff = abs(pos1->y - pos2->y);
    if (yDiff < xDiff)
    {
        yDiff = xDiff;
    }
    if (yDiff == 2)
    {
        x1 = pos1->x;
        y1 = pos1->y;

        for (i = 0; i < 2; i++)
        {
            if (x1 < pos2->x)
            {
                x1++;
            }
            if (x1 > pos2->x)
            {
                x1--;
            }
            if (y1 < pos2->y)
            {
                y1++;
            }
            if (y1 > pos2->y)
            {
                y1--;
            }
            tile = GetTile(x1, y1);
            if ((tile->terrainFlags & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == 0)
            {
                return FALSE;
            }
        }

        x2 = pos2->x;
        y2 = pos2->y;

        for (i = 0; i < 2; i++)
        {
            if (x2 < pos1->x)
            {
                x2 = x2 + 1;
            }
            if (x2 > pos1->x)
            {
                x2 = x2 - 1;
            }
            if (y2 < pos1->y)
            {
                y2 = y2 + 1;
            }
            if (y2 > pos1->y)
            {
                y2 = y2 - 1;
            }
            tile = GetTile(x2, y2);
            if ((tile->terrainFlags & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == 0)
            {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8083568(s32 inX, s32 inY, u8 index)
{
    s32 x = inX - gDungeon->unk181e8.cameraPixelPos.x;
    s32 y = inY - gDungeon->unk181e8.cameraPixelPos.y;

    if (x >= -16 && y >= -16 && x <= 255 && y <= 175)
    {
        SpriteSetX(&gUnknown_202ED28[0][index].sprite, x + gUnknown_202ED28[0][index].pos.x);
        SpriteSetY(&gUnknown_202ED28[0][index].sprite, y + gUnknown_202ED28[0][index].pos.y);

        AddSprite(&gUnknown_202ED28[0][index].sprite, 0, NULL, NULL);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Entity* GetLeader(void)
{
    Entity *leader = gLeaderPointer;
    if (leader == NULL) {
        s32 i;
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            Entity *currentPokemon = gDungeon->teamPokemon[i];
            if (EntityIsValid(currentPokemon) && GetEntInfo(currentPokemon)->isTeamLeader) {
                gLeaderPointer = currentPokemon;
                return currentPokemon;
            }
        }
        return NULL;
    }
    return leader;
}

EntityInfo* GetLeaderInfo(void)
{
    return GetEntInfo(GetLeader());
}

bool8 sub_8083660(DungeonPos *posDst)
{
    struct PositionU8 positions[DUNGEON_MAX_NUM_TILES];
    s32 yLoop, xLoop;
    Entity *leader = GetLeader();
    s32 randX, randY;
    s32 i;
    s32 x, y;
    s32 count = 0;

    for (i = 0; i < 3; i++) {
        DungeonPos leaderPos;

        randX = DungeonRandInt(DUNGEON_MAX_SIZE_X);
        randY = DungeonRandInt(DUNGEON_MAX_SIZE_Y);
        leaderPos = leader->pos;
        x = randX;

        for (xLoop = 0; xLoop < DUNGEON_MAX_SIZE_X; xLoop++) {
            y = randY;
            if (count >= DUNGEON_MAX_NUM_TILES)
                break;

            for (yLoop = 0; yLoop < DUNGEON_MAX_SIZE_Y; yLoop++) {
                bool8 setPosition = FALSE;
                const Tile *tile = GetTile(x, y);
                if (count >= DUNGEON_MAX_NUM_TILES)
                    break;
                if (i == 0) {
                    if (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL
                        && tile->room != CORRIDOR_ROOM
                        && tile->object == NULL
                        && tile->monster == NULL
                        && (abs(leaderPos.x - x) >= 6 || abs(leaderPos.y - y) >= 6))
                    {
                        setPosition = TRUE;
                    }
                }
                // No abs checks
                else if (i == 1) {
                    if (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL
                        && tile->room != CORRIDOR_ROOM
                        && tile->object == NULL
                        && tile->monster == NULL)
                    {
                        setPosition = TRUE;
                    }
                }
                // No abs checks and no CORRIDOR_ROOM check
                else {
                    if (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL
                        && tile->object == NULL
                        && tile->monster == NULL)
                    {
                        setPosition = TRUE;
                    }
                }

                if (setPosition) {
                    positions[count].x = x;
                    positions[count].y = y;
                    count++;
                }

                if (++y >= DUNGEON_MAX_SIZE_Y) {
                    y = 0;
                }
            }

            if (++x >= DUNGEON_MAX_SIZE_X) {
                x = 0;
            }
        }

        if (count != 0) {
            s32 posId = DungeonRandInt(count);
            posDst->x = positions[posId].x;
            posDst->y = positions[posId].y;
            return TRUE;
        }
    }

    return FALSE;
}

bool8 sub_808384C(DungeonPos *posDst, const DungeonPos *posSrc)
{
    s32 i;
    s32 x, y;
    const Tile *tile;

    for (i = 0; i < 25; i++) {
        if (gUnknown_80F4468[i].x == 99)
            break;

        x = gUnknown_80F4468[i].x + posSrc->x;
        y = gUnknown_80F4468[i].y + posSrc->y;
        tile = GetTile(x, y);
        if (!(tile->terrainFlags & TERRAIN_TYPE_UNK_x800)
            && GetTerrainType(tile) == TERRAIN_TYPE_NORMAL
            && tile->object == NULL
            && tile->monster == NULL)
        {
            posDst->x = x;
            posDst->y = y;
            return TRUE;
        }
    }

    return FALSE;
}

void sub_80838EC(u8 *a0)
{
    if (*a0 == 0x7F)
        return;
    if (*a0 != 0) {
        *a0 -= 1;
    }
}

void sub_8083904(struct DungeonPos *posDst, struct Entity *entityArg)
{
    struct EntityInfo *info;
    s32 xOffset, yOffset;
    s32 pokeX, pokeY;
    s32 i;
    const struct DungeonPos *posArray;
    Entity **possibleTargets;
    s32 maxTargets;
    s32 direction;

    info = GetEntInfo(entityArg);
    direction = info->action.direction;
    if (CheckVariousStatuses2(entityArg, TRUE)) {
        posDst->x = (gAdjacentTileOffsets[direction].x * 3) + entityArg->pos.x;
        posDst->y = (gAdjacentTileOffsets[direction].y * 3) + entityArg->pos.y;
    }
    else if (info->action.itemTargetPosition.x == -1 && info->action.itemTargetPosition.y == -1) {
        s32 strId = info->action.direction;
        posArray = gUnknown_80F4CC4[strId].posArray;
        xOffset = gUnknown_80F4CC4[strId].xOffset;
        yOffset = gUnknown_80F4CC4[strId].yOffset;
        pokeX = entityArg->pos.x;
        pokeY = entityArg->pos.y;
        if (gDungeon->decoyIsActive) {
            possibleTargets = gDungeon->activePokemon;
            maxTargets = DUNGEON_MAX_POKEMON;
        }
        else if (!info->isNotTeamMember) {
            possibleTargets = gDungeon->wildPokemon;
            maxTargets = DUNGEON_MAX_WILD_POKEMON;
        }
        else {
            possibleTargets = gDungeon->teamPokemon;
            maxTargets = MAX_TEAM_MEMBERS;
        }

        while (posArray->x != 99) {
            s32 x = pokeX + (xOffset * posArray->x);
            s32 y = pokeY + (yOffset * posArray->y);

            for (i = 0; i < maxTargets; i++) {
                Entity *entity = possibleTargets[i];
                if (EntityIsValid(entity)
                    && entity->pos.x == x
                    && entity->pos.y == y
                    && GetTreatmentBetweenMonsters(entityArg,entity,FALSE,FALSE) == 1)
                {
                    posDst->x = x;
                    posDst->y = y;
                    return;
                }
            }
            posArray++;
        }
        posDst->x = (gAdjacentTileOffsets[info->action.direction].x * 2) + entityArg->pos.x;
        posDst->y = (gAdjacentTileOffsets[info->action.direction].y * 2) + entityArg->pos.y;
    }
    else {
        posDst->x = info->action.itemTargetPosition.x;
        posDst->y = info->action.itemTargetPosition.y;
    }
}
