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
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"
#include "dungeon_pos_data.h"
#include "dungeon_damage.h"

void sub_804EB30();
bool8 ExposeTrap(s32 x, s32 y);
void sub_807EC28(u32);
u8 IsFloorOver(void);
void sub_80421AC(Entity * pokemon, Entity * target);
void sub_807BB78(Entity *pokemon);
extern void UpdateCamera(u32);
bool8 sub_808384C(DungeonPos *, DungeonPos *);
u8 sub_8083660(DungeonPos *);

extern u32 gDungeonFramesCounter;

void sub_807D068(Entity *pokemon, DungeonPos *pos);

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
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC9E8); // It couldn't be knocked flying!
        return;
    }
    else
    {
        if (pokemon == target) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCA10); // {POKEMON_0} couldn't be knocked flying!
            return;
        }
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if (AbilityIsActive(target,ABILITY_SUCTION_CUPS)) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCBCC); // {POKEMON_0} is anchored! It can't be knocked flying!
            return;
        }
        else
        {
            (GetEntInfo(target)->action).direction = (direction + 4) & DIRECTION_MASK;
            sub_806CDD4(target, 6, (direction + 4) & DIRECTION_MASK);
            sub_80421C0(target,0x1a3);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80F8A0C); // {POKEMON_0} was blown away!
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
                    if (ShouldDisplayEntity(target) != 0) {
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
            if (IsFloorOver()) {
                return;
            }
            if (entity != NULL) {
                InitPokemonMove(&move,0x163);
                if (!sub_80571F0(entity,&move)) {
                    TrySendImmobilizeSleepEndMsg(pokemon,entity);
                    sub_806F370(pokemon,entity,gBlowAwayDmgValue,0,0,0,0x21a,0,0,0);
                }
            }
            if (IsFloorOver()) {
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
                DiscoverMinimap(&target->pos);
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
    diff = abs(pokemon->pixelPos.x - posX);
    if (diff < 0xc)
        diff = abs(pokemon->pixelPos.y - posY);
    if (diff >= 0xc)
    {
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
            UpdateEntityPixelPos(pokemon, &local_34);
            if (ShouldDisplayEntity(pokemon)) {
                DungeonRunFrameActions(0x1a);
            }
            iVar8 = iVar8 + 0xaa;
        }
    }
    local_34.x = posX;
    local_34.y = posY;
    pokemon->unk1C = IntToF248(0);
    UpdateEntityPixelPos(pokemon,&local_34);
    DungeonRunFrameActions(0x1a);
}
