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
