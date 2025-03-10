#include "global.h"
#include "constants/ability.h"
#include "constants/weather.h"
#include "code_803E46C.h"
#include "code_8045A00.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "structs/str_dungeon.h"
#include "code_8077274_1.h"
#include "dungeon_ai.h"
#include "dungeon_engine.h"
#include "dungeon_generation.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "moves.h"
#include "move_util.h"
#include "code_8041AD0.h"
#include "tile_types.h"
#include "code_803E668.h"
#include "weather.h"
#include "dungeon_config.h"

extern u32 gDungeonFramesCounter;

extern u8 *gUnknown_80FCA10[];
extern u8 *gUnknown_80F8A0C[];
extern u8 *gUnknown_80FCBCC[];
extern u8 *gUnknown_80FC9E8[];
extern u8 *gUnknown_80FCB14[];
extern u8 *gUnknown_80FCAE8[];
extern u8 *gUnknown_80FC97C[];
extern u8 *gUnknown_80FC9A0[];
extern u8 *gUnknown_80FC584[];
extern u8 *gUnknown_80FD320[];
extern u8 *gUnknown_80FD2F8[];
extern u8 *gUnknown_80FCB98[];
extern u8 *gUnknown_80FC9C0[];
extern u8 *gUnknown_80FD060[];
extern u8 *gUnknown_80FD08C[];
extern u8 *gUnknown_80FD05C[];
extern u8 *gUnknown_80FD3D0[];
extern u8 *gUnknown_80FD3CC[];
extern u8 *gUnknown_80FD3C8[];
extern u8 *gUnknown_80FD3A0[];
extern u8 *gUnknown_80F96BC[];
extern u8 *gUnknown_80F96EC[];
extern struct DungeonPos *gUnknown_8107178[3];

extern void sub_807E1A0(Entity *pokemon,Entity *target,u8 moveType,s32 param_4,s32 param_5); // TODO: param_4 should be s16
extern void sub_804216C(Entity *pokemon, Entity *target, u32 r2);
extern void sub_80461C8(DungeonPos *, u32);
extern void sub_804218C(Entity *pokemon, Entity *target);

EWRAM_INIT u32 gUnknown_203B444[3] = {0x28, 0x28, 0x50};

void sub_804EB30();
bool8 ExposeTrap(s32 x, s32 y);
void ShowWholeRevealedDungeonMap();
void sub_8049ED4();
void sub_806A5B8(Entity *);
u8 sub_8045888(Entity *);
void sub_807EC28(u32);
void sub_80694C0(Entity *, s32, s32, s32);
void sub_807D068(Entity *, DungeonPos *);
u8 sub_8044B28(void);
extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
void sub_80421AC(Entity * pokemon, Entity * target);
void sub_807BB78(Entity *pokemon);
extern void sub_803F580(u32);
bool8 sub_808384C(DungeonPos *, DungeonPos *);
u8 sub_8083660(DungeonPos *);
void sub_80460F8(DungeonPos *, Item *, u32);
void sub_80462AC(Entity * ,u32, u32, u8, u32);
extern void ShowDungeonMapAtPos(s32, s32);

void BlowAwayTarget(Entity *pokemon, Entity *target, u32 direction)
{
    const Tile *tile;
    int iVar8;
    bool8 flag;
    DungeonPos pos;
    Move move;
    int counter;
    Entity *entity;
    PixelPos pos32;

    counter = 10;
    if (IsCurrentFixedRoomBossFight()) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC9E8); // It couldn't be knocked flying!
        return;
    }
    else
    {
        if (pokemon == target) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCA10); // {POKEMON_0} couldn't be knocked flying!
            return;
        }
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if (AbilityIsActive(target,ABILITY_SUCTION_CUPS)) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCBCC); // {POKEMON_0} is anchored! It can't be knocked flying!
            return;
        }
        else
        {
            (GetEntInfo(target)->action).direction = (direction + 4) & DIRECTION_MASK;
            sub_806CDD4(target, 6, (direction + 4) & DIRECTION_MASK);
            sub_80421C0(target,0x1a3);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80F8A0C); // {POKEMON_0} was blown away!
            flag = TRUE;
            entity = NULL;

            for(; counter > 0; counter--)
            {
                pos = target->pos;
                pos.x += gAdjacentTileOffsets[direction].x;
                pos.y += gAdjacentTileOffsets[direction].y;
                if ((((pos.x < 0) || (pos.y < 0)) || (DUNGEON_MAX_SIZE_X <= pos.x)) ||
                    (DUNGEON_MAX_SIZE_Y <= pos.y)) goto _0807CF20;
                pos32.x = gAdjacentTileOffsets[direction].x << 0xA;
                pos32.y = gAdjacentTileOffsets[direction].y << 0xA;

                for(iVar8 = 0; iVar8 < 6; iVar8++)
                {
                    IncreaseEntityPixelPos(target,pos32.x,pos32.y);
                    if (sub_8045888(target) != 0) {
                        DungeonRunFrameActions(0x19);
                    }
                }
                tile = GetTile(pos.x, pos.y);
                if (tile->monster != NULL) {
                    entity = tile->monster;
                    goto _0807CF26;
                }
                if (sub_80705F0(target,&pos)){
                    flag = (GetTerrainType(tile) != TERRAIN_TYPE_WALL);
                    goto _0807CF20;
                }
                sub_80694C0(target,pos.x,pos.y,1);
            }


            flag = TRUE;
        _0807CF20:
            if (!flag) {
            _0807CF26:

                sub_807D068(target,&target->pos);
                sub_806F370(pokemon,target,gBlowAwayDmgValue,0,0,0,0x219,0,0,0);
            }
            if (sub_8044B28()) {
                return;
            }
            if (entity != NULL) {
                InitPokemonMove(&move,0x163);
                if (!sub_80571F0(entity,&move)) {
                    TrySendImmobilizeSleepEndMsg(pokemon,entity);
                    sub_806F370(pokemon,entity,gBlowAwayDmgValue,0,0,0,0x21a,0,0,0);
                }
            }
            if (sub_8044B28()) {
                return;
            }
            if (!EntityIsValid(target)) {
                return;
            }
            sub_806A5B8(target);
            if (sub_80706A4(target,&target->pos)) {
                WarpTarget(target,target,0,0);
            }
            if (!EntityIsValid(target)) {
                return;
            }
            sub_806CE68(target,8);
            if (GetEntInfo(target)->isTeamLeader) {
                gDungeon->unk1 = 0;
                gDungeon->unk5C0 = -1;
                sub_804AC20(&target->pos);
                sub_807EC28(FALSE);
            }
            sub_806A5B8(target);
            sub_8075900(target,gDungeon->forceMonsterHouse);
        }
    }
}

void sub_807D068(Entity *pokemon, DungeonPos *pos)
{
    int pixelX;
    int posY;
    int pixelY;
    int posX;
    int counter;
    int iVar8;
    s32 diff;
    PixelPos local_34;
    int incrementX;
    int incrementY;

    posX = X_POS_TO_PIXELPOS(pos->x);
    posY = Y_POS_TO_PIXELPOS(pos->y);
    diff = (pokemon->pixelPos).x - posX;
    if (diff < 0) {
        diff = -diff;
    }
    if (diff < 0xc) {
        diff = (pokemon->pixelPos).y - posY;
        if (diff < 0) {
            diff = -diff;
        }
        if (diff < 0xc) goto _0807D11E;
    }
    iVar8 = 0;
    pixelX = (pokemon->pixelPos).x;
    pixelY = (pokemon->pixelPos).y;
    incrementX = (posX - pixelX) / 0xc;
    incrementY = (posY - pixelY) / 0xc;

    for(counter = 0; counter < 0xC; counter++)
    {
        pixelX += incrementX;
        pixelY += incrementY;
        local_34.x = pixelX;
        local_34.y = pixelY;
        pokemon->unk1C.raw = sin_4096(iVar8) * 0xc;
        sub_804535C(pokemon, &local_34);
        if (sub_8045888(pokemon)) {
            DungeonRunFrameActions(0x1a);
        }
        iVar8 = iVar8 + 0xaa;
    }
_0807D11E:
    local_34.x = posX;
    local_34.y = posY;
    pokemon->unk1C = IntToF248(0);
    sub_804535C(pokemon,&local_34);
    DungeonRunFrameActions(0x1a);
}

void WarpTarget(Entity *pokemon, Entity *target, u32 param_3, DungeonPos *pos)
{
    EntityInfo *info;
    u32 direction;
    DungeonPos local_2c;
    bool8 flag;

    info = GetEntInfo(target);
    flag = FALSE;

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (AbilityIsActive(target,ABILITY_SUCTION_CUPS)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCAE8);
        return;
    }
    if (IsCurrentFixedRoomBossFight()) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC97C);
        return;
    }
    if (param_3 == 1)
    {
        DungeonPos stairsPosition = gDungeon->stairsSpawn;
        if(stairsPosition.x == target->pos.x && stairsPosition.y == target->pos.y) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC9A0); // It's already on the stairs!
            PetrifiedStatusTarget(pokemon,target);
            return;
        }
    }

    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC584); // $m0 warped!
    TrySendImmobilizeSleepEndMsg(target,target);
    sub_80421AC(pokemon,target);
    if (sub_8045888(target)) {
        direction = (info->action).direction;
        target->unk1C.raw += + 0x800;
        while ( target->unk1C.raw < 0xa000) {
            if ((gDungeonFramesCounter & 3) == 0) {
                direction = (direction + 1) & DIRECTION_MASK;
                info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(target,direction);
            }
            DungeonRunFrameActions(0x22);
            target->unk1C.raw += 0x800;
        }
    }


    switch(param_3)
    {
        default:
        case 0:
            if (!sub_8083660(&local_2c)) {
                local_2c = target->pos;
                flag = TRUE;
            }
            break;
        case 1:
            if (!sub_808384C(&local_2c,&gDungeon->stairsSpawn)) {
                local_2c = target->pos;
                flag = TRUE;
            }
            break;
        case 2:
            if (!sub_808384C(&local_2c,pos)) {
                local_2c = target->pos;
                flag = TRUE;
            }
            break;
        case 3:
            local_2c = *pos;
            break;

    }

    sub_80694C0(target,local_2c.x,local_2c.y,1);
    sub_804535C(target,0);
    sub_807BB78(target);
    sub_803F580(1);
    if (sub_8045888(target)) {
        direction = (info->action).direction;
        target->unk1C.raw = 0x9c00;
        do {
            if ((gDungeonFramesCounter & 3) == 0) {
                direction = (direction + 1) & DIRECTION_MASK;
                info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(target,direction);
            }
            DungeonRunFrameActions(0x22);
            target->unk1C.raw -= 0x400;
        } while (0 < target->unk1C.raw);
    }
    target->unk1C = IntToF248_2(0);
    DungeonRunFrameActions(0x22);
    if (flag) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCB14); // But it dropped back at the same spot!
    }
    if (param_3 == 1) {
        PetrifiedStatusTarget(pokemon,target);
    }
    if (info->isTeamLeader) {
        sub_804AC20(&target->pos);
        gDungeon->unk1 = 0;
        gDungeon->unk5C0 = -1;
        sub_807EC28(0);
    }
    sub_806A5B8(target);
    sub_8075900(target,gDungeon->forceMonsterHouse);
}

void sub_807D3CC(Entity *param_1)
{
    u32 room;
    u8 flag;
    int x;
    int y;
    s32 range;
    RoomData *roomData;

    flag = FALSE;
    range = gDungeon->unk181e8.visibilityRange;
    if (range == 0) {
        range = 2;
    }
    room = GetEntityRoom(param_1);

    if (room == CORRIDOR_ROOM) {
        for (y = (param_1->pos).y - range; y <= ((param_1->pos).y + range); y++)
        {
            for (x = (param_1->pos).x - range; x <= ((param_1->pos).x + range); x++) {
                flag |= ExposeTrap(x,y);
            }
        }
    }
    else {
        roomData = &gDungeon->roomData[room];
        for (y = roomData->bottomRightCornerY + -1; y <= roomData->topLeftCornerY + 1; y++) {
            for (x = roomData->bottomRightCornerX + -1; x <= roomData->topLeftCornerX + 1; x++) {
                flag |= ExposeTrap(x,y);
            }
        }
    }
    if (flag) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80FD2F8); // All traps were exposed
        ShowWholeRevealedDungeonMap();
        sub_8049ED4();
    }
    else {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80FD320); // There appears to be no hidden traps.
    }
}

bool8 ExposeTrap(s32 x,s32 y)
{
    const Tile *tile;
    Entity *trap;

    tile = GetTile(x,y);
    trap = tile->object;
    if (((trap != NULL) && (GetEntityType(trap) == ENTITY_TRAP)) && (!trap->isVisible)) {
        trap->isVisible = TRUE;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

extern const u8 *const gUnknown_80FE034;
extern const u8 *const gUnknown_80FE060;
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
                sub_80461C8(&itemEntities[i].pos, 1);
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
                sub_80460F8(&targetTilePos[i], GetItemData(&itemEntities[i]), 1);
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

void HandlePounceOrbAction(Entity *pokemon, Entity *target, u8 r2) {
    EntityInfo *info;
    const Tile *tile;
    DungeonPos pos;
    u32 direction = r2;
    info = GetEntInfo(target);
    if(AbilityIsActive(target, ABILITY_SUCTION_CUPS))
    {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FCB98);
        return;
    }
    if(IsCurrentFixedRoomBossFight())
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FC9C0);
        return;
    }
    if(direction == NUM_DIRECTIONS)
        direction = info->action.direction;
    sub_806CDD4(target, 6, direction);


    while (1)
    {
        pos.x = target->pos.x + gAdjacentTileOffsets[direction].x;
        pos.y = target->pos.y + gAdjacentTileOffsets[direction].y;

        if(pos.x <= 0 || pos.y <= 0 || pos.x > DUNGEON_MAX_SIZE_X - 2 || pos.y > DUNGEON_MAX_SIZE_Y - 2) break;

        tile = GetTile(pos.x, pos.y);

        if(tile->monster) break;
        if(GetTerrainType(tile) == TERRAIN_TYPE_WALL) break;

        sub_80694C0(target, pos.x, pos.y, 0);

        sub_804535C(target, 0);
        if(!sub_8045888(target)) continue;
        DungeonRunFrameActions(0x3A);
    }

    sub_806A5B8(target);
    if(sub_80706A4(target, &target->pos))
        WarpTarget(target, target, 0, 0);
    if(EntityIsValid(target))
    {
        sub_806CE68(target, 8);
        if(info->isTeamLeader)
        {
            sub_804AC20(&target->pos);
            sub_807EC28(0);
        }
        sub_806A5B8(target);

        sub_8075900(target, gDungeon->forceMonsterHouse);
    }
}

void HandleDroughtOrbAction(Entity *pokemon, Entity *target) {
	s32 x;
	s32 y;
	Tile *tile;
	bool8 flag;

	flag = FALSE;
	if(IsCurrentFixedRoomBossFight())
	{
		LogMessageByIdWithPopupCheckUser(pokemon, *gUnknown_80FD060);
		return;
	}

	if(IsWaterTileset())
	{
		LogMessageByIdWithPopupCheckUser(pokemon, *gUnknown_80FD08C);
		return;
	}

	for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
		for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
		{
			tile = GetTileMut(x, y);
			if(GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY)
			{
			    SetTerrainNormal(tile);
				sub_80498A8(x, y);
				flag = TRUE;
			}
		}
	for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
		for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
			sub_8049BB0(x, y);

	if(flag)
	{
		sub_80421C0(pokemon, 0x1A1);
		LogMessageByIdWithPopupCheckUser(pokemon, *gUnknown_80FD05C);
	}
	else
	{
		LogMessageByIdWithPopupCheckUser(pokemon, *gUnknown_80FD060);
	}
	gDungeon->unk644.unk2C = 1;
	sub_806CF60();
	ShowWholeRevealedDungeonMap();
	sub_8049ED4();
}

void HandleOneRoomOrb(Entity *pokemon, Entity *target) {
	bool8 bVar1;
	Tile *tile;
	s32 y;
	Entity *entity;
	s32 x;
	s32 index;
	bool8 isMonsterHouse;

	if (gDungeon->forceMonsterHouse != 0) {
		LogMessageByIdWithPopupCheckUser(pokemon,*gUnknown_80FD3C8);
		return;
	}

	if (gDungeon->unk3A0B != 0) {
		LogMessageByIdWithPopupCheckUser(pokemon,*gUnknown_80FD3CC);
		return;
	}

	if (IsBossFight()) {
		LogMessageByIdWithPopupCheckUser(pokemon,*gUnknown_80FD3D0);
		return;
	}
	isMonsterHouse = FALSE;

	for(x = 1; x < DUNGEON_MAX_SIZE_X - 1; x++)
	{
		for(y = 1; y < DUNGEON_MAX_SIZE_Y - 1; y++)
		{
			bVar1 = 0;
			tile = GetTileMut(x,y);
			tile->terrainType &= ~(TERRAIN_TYPE_UNK_x400);
			tile->room = 0;
			if ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)
			{
				if((tile->terrainType & TERRAIN_TYPE_UNBREAKABLE) == 0) {
					tile->spawnOrVisibilityFlags |= SPAWN_FLAG_STAIRS | SPAWN_FLAG_ITEM;
					tile->terrainType &= ~(TERRAIN_TYPE_NATURAL_JUNCTION);
					if ((tile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE)) {
						isMonsterHouse = TRUE;
					}
					if (GetTerrainType(tile) != TERRAIN_TYPE_SECONDARY)
						if((GetTerrainType(tile) != (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY))) {
							if (((x == 1) || (((y == 1 || (x == DUNGEON_MAX_SIZE_X - 2)) || (y == DUNGEON_MAX_SIZE_Y - 2)))) &&
								((tile->object == NULL && (gDungeon->unk644.unk2C == 0)))) {
								bVar1 = TRUE;
							}
							if (bVar1) {
                                SetTerrainSecondary(tile);
							}
							else {
								if (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL) continue;
								SetTerrainNormal(tile);
								tile->terrainType |= TERRAIN_TYPE_UNK_x400;
							}
						}
				}
			}
		}
	}


	if (StairsAlwaysReachable(gDungeon->stairsSpawn.x,gDungeon->stairsSpawn.y,TRUE)) {
		for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
		{
			for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
			{
				tile = GetTileMut(x,y);
				if (!(tile->terrainType & TERRAIN_TYPE_UNBREAKABLE))
					if(((tile->terrainType & (TERRAIN_TYPE_UNREACHABLE_FROM_STAIRS| TERRAIN_TYPE_UNK_x400)) == (TERRAIN_TYPE_UNREACHABLE_FROM_STAIRS| TERRAIN_TYPE_UNK_x400))) {
						SetTerrainSecondary(tile);
					}
			}
		}
	}
	if (isMonsterHouse) {
		gDungeon->monsterHouseRoom = FALSE;
	}
	for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
	{

		for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
		{
			if (isMonsterHouse) {
				GetTileMut(x,y)->terrainType |= TERRAIN_TYPE_IN_MONSTER_HOUSE;
			}
			sub_8049BB0(x,y);
		}
	}

	for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
	{
		entity = gDungeon->activePokemon[index];
		if (EntityIsValid(entity)) {
			entity->room = GetTile(entity->pos.x,entity->pos.y)->room;
		}
	}
	sub_804EB30();
	sub_804AAD4();
	sub_8049884();
	sub_806CF60();
	ShowWholeRevealedDungeonMap();
	sub_8049ED4();
	LogMessageByIdWithPopupCheckUser(pokemon,*gUnknown_80FD3A0);
	sub_803E708(0x28,0x2b);
	sub_8075900(pokemon,1);
	for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
	{
		entity = gDungeon->activePokemon[index];
		if (EntityIsValid(entity)) {
			sub_806A5B8(entity);
			if ((EntityIsValid(entity)) && (sub_80706A4(entity,&entity->pos))) {
				WarpTarget(entity,entity,0,0);
			}
		}
	}
	gDungeon->forceMonsterHouse = TRUE;
	sub_803E708(0x14,0x2b);
}


// https://decomp.me/scratch/JZ51a -- sub_807E1A0 param_4 should be s16 but using s32 to match this func
void HandleExplosion(Entity *pokemon,Entity *target,DungeonPos *param_3,s32 param_4,u8 moveType,s16 param_6)
{
    bool8 flag;
    DungeonPos *posPtr;
    Tile *tile;
    Entity * entity1;
    Entity *entity2;
    int x;
    int y;
    int index;
    DungeonPos pos;

    u32 uStack_2c;

    uStack_2c = param_6;
    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
        entity1 = gDungeon->activePokemon[index];
        if ((EntityIsValid(entity1)) && (AbilityIsActive(entity1, ABILITY_DAMP))) break;
    }
    if (index != DUNGEON_MAX_POKEMON) {
        sub_804218C(pokemon,target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80F96EC);
    }
    else if (GetApparentWeather(target) == WEATHER_RAIN) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80F96EC);
    }
    else
    {
        sub_804216C(pokemon,target,param_4);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80F96BC);
        flag = FALSE;

        posPtr = (gUnknown_8107178)[param_4];
        if (posPtr->x != 99) {
            while (posPtr->x != 99) {
                pos.x = posPtr->x + param_3->x;
                pos.y = posPtr->y + param_3->y;
                if ((0 <= pos.x) && (0 <= pos.y) && (pos.x < DUNGEON_MAX_SIZE_X) && (pos.y < DUNGEON_MAX_SIZE_Y)) {
                    tile = GetTileMut(pos.x,pos.y);
                    if ((0 < pos.x) && (0 < pos.y && ((pos.x < (DUNGEON_MAX_SIZE_X - 1) && ((pos.y < (DUNGEON_MAX_SIZE_Y - 1)
                        && GetTerrainType(tile) == TERRAIN_TYPE_WALL)))
                    )) && (tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0) {
                        SetTerrainNormal(tile);
                        for(y = -1; y < 2; y++)
                        {
                            for(x = -1; x < 2; x++)
                            {
                                sub_80498A8(pos.x + x,pos.y + y);
                            }
                        }
                        flag = TRUE;
                    }
                    entity2 = tile->object;
                    if (((entity2 != NULL) && (entity2 != target)) && (GetEntityType(entity2) == ENTITY_ITEM)) {
                        sub_80461C8(&pos, 0);
                    }
                    entity2 = tile->monster;
                    if (((entity2 != NULL) && (entity2 != target)) && (GetEntityType(entity2) == ENTITY_MONSTER)) {
                        sub_807E1A0(pokemon,entity2,moveType,uStack_2c,gUnknown_203B444[param_4]);
                        if (sub_8044B28()) break;
                    }
                }
                posPtr++;
            }
        }
        if (sub_8044B28()) {
            return;
        }
        if (GetEntityType(target) == ENTITY_MONSTER) {
            sub_807E1A0(pokemon,target,moveType,uStack_2c,gUnknown_203B444[param_4]);
        }
        if (!flag) {
            return;
        }
        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
        {
            for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
            {
                sub_8049BB0(x,y);
            }
        }
        ShowWholeRevealedDungeonMap();
        sub_8049ED4();
    }
}

