#include "global.h"

#include "constants/ability.h"
#include "code_803E46C.h"
#include "code_8045A00.h"
#include "code_80521D0.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "structs/str_dungeon.h"
#include "code_8077274_1.h"
#include "dungeon_ai.h"
#include "dungeon_engine.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "moves.h"
#include "move_util.h"

extern u32 gUnknown_202EDCC;
extern u8 gAvailablePokemonNames[];

extern s16 gUnknown_80F4F90;
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

bool8 ExposeTrap(s32 x, s32 y);
void sub_8040A84();
void sub_8049ED4();
void sub_806A5B8(Entity *);
void sub_80522F4(Entity *, Entity *, u8 *);
void sub_80421C0(Entity *, u32);
u8 sub_8045888(Entity *);
void sub_807EC28(u32);
void sub_80694C0(Entity *, s32, s32, s32);
void sub_807D068(Entity *, Position *);
u8 sub_8044B28(void);
extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
void sub_80421AC(Entity * pokemon, Entity * target);
void sub_807BB78(Entity *pokemon);
extern void sub_803F580(u32);
bool8 sub_808384C(Position *, Position *);
u8 sub_8083660(Position *);

void sub_807CD9C(Entity *pokemon, Entity *target, u32 direction)
{
    Tile *tile;
    int iVar8;
    bool8 flag;
    Position sp_0x18;
    Move move;
    int sp_0x24;
    Entity *sp_0x28;
    Position32 sp_0x2C;

    sp_0x24 = 10;
    if (IsCurrentFixedRoomBossFight()) {
        sub_80522F4(pokemon,target,*gUnknown_80FC9E8); // It couldn't be knocked flying!
        return;
    }
    else
    {
        if (pokemon == target) {
            SetMessageArgument(gAvailablePokemonNames,target,0);
            sub_80522F4(pokemon,target,*gUnknown_80FCA10); // {ARG_POKEMON_0} couldn't be knocked flying!
            return;
        }
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (HasAbility(target,ABILITY_SUCTION_CUPS)) {
            sub_80522F4(pokemon,target,*gUnknown_80FCBCC); // {ARG_POKEMON_0} is anchored! It can't be knocked flying!
            return;
        }
        else
        {
            (target->info->action).direction = (direction + 4) & DIRECTION_MASK;
            sub_806CDD4(target, 6, (direction + 4) & DIRECTION_MASK);
            sub_80421C0(target,0x1a3);
            sub_80522F4(pokemon,target,*gUnknown_80F8A0C); // {ARG_POKEMON_0} was blown away!
            flag = TRUE;
            sp_0x28 = NULL;

            for(; sp_0x24 > 0; sp_0x24--)
            {
                sp_0x18 = target->pos;
                sp_0x18.x += gAdjacentTileOffsets[direction].x;
                sp_0x18.y += gAdjacentTileOffsets[direction].y;
                if ((((sp_0x18.x < 0) || (sp_0x18.y < 0)) || (DUNGEON_MAX_SIZE_X <= sp_0x18.x)) ||
                    (DUNGEON_MAX_SIZE_Y <= sp_0x18.y)) goto _0807CF20;
                sp_0x2C.x = gAdjacentTileOffsets[direction].x << 0xA;
                sp_0x2C.y = gAdjacentTileOffsets[direction].y << 0xA;

                for(iVar8 = 0; iVar8 < 6; iVar8++)
                {
                    IncreaseEntityPixelPos(target,sp_0x2C.x,sp_0x2C.y);
                    if (sub_8045888(target) != 0) {
                        sub_803E46C(0x19);
                    }
                }
                tile = GetTile(sp_0x18.x, sp_0x18.y);
                if (tile->monster != NULL) {
                    sp_0x28 = tile->monster;
                    goto _0807CF26;
                }
                if (sub_80705F0(target,&sp_0x18)){
                    flag = (tile->terrainType & 3) == 0 ? FALSE : TRUE;
                    goto _0807CF20;
                }
                sub_80694C0(target,sp_0x18.x,sp_0x18.y,1);
            }


            flag = TRUE;
        _0807CF20:
            if (!flag) {
            _0807CF26:

                sub_807D068(target,&target->pos);
                sub_806F370(pokemon,target,gUnknown_80F4F90,0,0,0,0x219,0,0,0);
            }
            if (sub_8044B28()) {
                return;
            }
            if (sp_0x28 != NULL) {
                InitPokemonMove(&move,0x163);
                if (!sub_80571F0(sp_0x28,&move)) {
                    sub_807A96C(pokemon,sp_0x28);
                    sub_806F370(pokemon,sp_0x28,gUnknown_80F4F90,0,0,0,0x21a,0,0,0);
                }
            }
            if (sub_8044B28()) {
                return;
            }
            if (!EntityExists(target)) {
                return;
            }
            sub_806A5B8(target);
            if (sub_80706A4(target,&target->pos)) {
                sub_807D148(target,target,0,0);
            }
            if (!EntityExists(target)) {
                return;
            }
            sub_806CE68(target,8);
            if (target->info->isTeamLeader) {
                gDungeon->unk1 = 0;
                gDungeon->unk5C0 = -1;
                sub_804AC20(&target->pos);
                sub_807EC28(FALSE);
            }
            sub_806A5B8(target);
            sub_8075900(target,gDungeon->unk3A08);
        }
    }
}

void sub_807D068(Entity *pokemon, Position *pos)
{
    int pixelX;
    int posY;
    int pixelY;
    int posX;
    int counter;
    int iVar8;
    s32 diff;
    Position32 local_34;
    int incrementX;
    int incrementY;

    posX = pos->x * 0x1800 + 0xc00;
    posY = pos->y * 0x1800 + 0x1000;
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
        pokemon->unk1C = sin_abs_4096(iVar8) * 0xc;
        sub_804535C(pokemon, &local_34);
        if (sub_8045888(pokemon)) {
            sub_803E46C(0x1a);
        }
        iVar8 = iVar8 + 0xaa;
    }
_0807D11E:
    local_34.x = posX;
    local_34.y = posY;
    pokemon->unk1C = 0;
    sub_804535C(pokemon,&local_34);
    sub_803E46C(0x1a);
}

void sub_807D148(Entity *pokemon, Entity *target, u32 param_3, Position *pos)
{
    EntityInfo *info;
    u32 direction;
    Position local_2c;
    Position pos2;
    bool8 flag;

    info = target->info;
    flag = FALSE;

    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (HasAbility(target,ABILITY_SUCTION_CUPS)) {
        sub_80522F4(pokemon,target,*gUnknown_80FCAE8);
        return;
    }
    if (IsCurrentFixedRoomBossFight()) {
        sub_80522F4(pokemon,target,*gUnknown_80FC97C);
        return;
    }
    if (param_3 == 1)
    {
        pos2 = gDungeon->unkE21C;
        if(pos2.x == target->pos.x && pos2.y == target->pos.y) {
            sub_80522F4(pokemon,target,*gUnknown_80FC9A0); // It's already on the stairs!
            PetrifiedStatusTarget(pokemon,target);
            return;
        }
    }

    sub_80522F4(pokemon,target,*gUnknown_80FC584); // $m0 warped!
    sub_807A96C(target,target);
    sub_80421AC(pokemon,target);
    if (sub_8045888(target)) {
        direction = (info->action).direction;
        target->unk1C += + 0x800;
        while ( target->unk1C < 0xa000) {
            if ((gUnknown_202EDCC & 3) == 0) {
                direction = (direction + 1) & DIRECTION_MASK;
                info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(target,direction);
            }
            sub_803E46C(0x22);
            target->unk1C += 0x800;
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
            if (!sub_808384C(&local_2c,&gDungeon->unkE21C)) {
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
        target->unk1C = 0x9c00;
        do {
            if ((gUnknown_202EDCC & 3) == 0) {
                direction = (direction + 1) & DIRECTION_MASK;
                info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(target,direction);
            }
            sub_803E46C(0x22);
            target->unk1C -= 0x400;
        } while (0 < target->unk1C);
    }
    target->unk1C = 0;
    sub_803E46C(0x22);
    if (flag) {
        sub_80522F4(pokemon,target,*gUnknown_80FCB14); // But it dropped back at the same spot!
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
    sub_8075900(target,gDungeon->unk3A08);
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
        SendMessage(param_1,*gUnknown_80FD2F8); // All traps were exposed
        sub_8040A84();
        sub_8049ED4();
    }
    else {
        SendMessage(param_1,*gUnknown_80FD320); // There appears to be no hidden traps.
    }
}

bool8 ExposeTrap(s32 x,s32 y)
{
    Tile *tile;
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
