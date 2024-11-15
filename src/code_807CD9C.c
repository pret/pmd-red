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

extern u32 gUnknown_202EDCC;
extern u32 gUnknown_203B444[];

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

void sub_804EB30();
bool8 ExposeTrap(s32 x, s32 y);
void sub_8040A84();
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

void sub_807CD9C(Entity *pokemon, Entity *target, u32 direction)
{
    const Tile *tile;
    int iVar8;
    bool8 flag;
    DungeonPos sp_0x18;
    Move move;
    int sp_0x24;
    Entity *sp_0x28;
    PixelPos sp_0x2C;

    sp_0x24 = 10;
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
        if (HasAbility(target,ABILITY_SUCTION_CUPS)) {
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
                    flag = (tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == 0 ? FALSE : TRUE;
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
                    TrySendImmobilizeSleepEndMsg(pokemon,sp_0x28);
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
        pokemon->unk1C = sin_4096(iVar8) * 0xc;
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

void sub_807D148(Entity *pokemon, Entity *target, u32 param_3, DungeonPos *pos)
{
    EntityInfo *info;
    u32 direction;
    DungeonPos local_2c;
    bool8 flag;

    info = GetEntInfo(target);
    flag = FALSE;

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (HasAbility(target,ABILITY_SUCTION_CUPS)) {
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
        sub_8040A84();
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

// https://decomp.me/scratch/P5sBc
NAKED
void HandleTrawlOrbAction(Entity *pokemon, Entity *target)
{
asm_unified(
"push {r4-r7,lr}\n"
"mov r7, r10\n"
"mov r6, r9\n"
"mov r5, r8\n"
"push {r5-r7}\n"
"ldr r4, _0807D540\n"
"add sp, r4\n"
"ldr r1, _0807D544\n"
"add r1, sp\n"
"str r0, [r1]\n"
"movs r2, 0\n"
"movs r3, 0xD1\n"
"lsls r3, 4\n"
"add r3, sp\n"
"str r2, [r3]\n"
"ldr r4, _0807D548\n"
"add r4, sp\n"
"str r2, [r4]\n"
"add r5, sp, 0x4\n"
"mov r8, r5\n"
"mov r10, r2\n"
"mov r9, r2\n"
"add r7, sp, 0x8\n"
"b _0807D606\n"
".align 2, 0\n"
"_0807D540: .4byte 0xfffff2d4\n"
"_0807D544: .4byte 0x00000d08\n"
"_0807D548: .4byte 0x00000d0c\n"
"_0807D54C:\n"
"movs r0, 0x4\n"
"ldrsh r1, [r5, r0]\n"
"ldr r2, _0807D650\n"
"add r2, sp\n"
"ldr r2, [r2]\n"
"movs r3, 0x4\n"
"ldrsh r0, [r2, r3]\n"
"subs r1, r0\n"
"cmp r1, 0\n"
"bge _0807D562\n"
"negs r1, r1\n"
"_0807D562:\n"
"cmp r1, 0x2\n"
"bgt _0807D580\n"
"movs r3, 0x6\n"
"ldrsh r1, [r5, r3]\n"
"ldr r4, _0807D650\n"
"add r4, sp\n"
"ldr r4, [r4]\n"
"movs r2, 0x6\n"
"ldrsh r0, [r4, r2]\n"
"subs r1, r0\n"
"cmp r1, 0\n"
"bge _0807D57C\n"
"negs r1, r1\n"
"_0807D57C:\n"
"cmp r1, 0x2\n"
"ble _0807D5FE\n"
"_0807D580:\n"
"movs r1, 0x4\n"
"ldrsh r0, [r5, r1]\n"
"movs r2, 0x6\n"
"ldrsh r1, [r5, r2]\n"
"bl GetTile\n"
"ldrh r1, [r0]\n"
"movs r2, 0x3\n"
"adds r0, r2, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"beq _0807D5FE\n"
"mov r3, r8\n"
"str r2, [r3]\n"
"ldr r4, _0807D654\n"
"add r4, sp\n"
"ldr r1, _0807D658\n"
"add r1, sp\n"
"ldr r1, [r1]\n"
"lsls r0, r1, 2\n"
"adds r4, r0\n"
"str r4, [r7, 0x6C]\n"
"ldr r0, [r5, 0x4]\n"
"str r0, [r7]\n"
"movs r2, 0x4\n"
"ldrsh r0, [r5, r2]\n"
"lsls r1, r0, 1\n"
"adds r1, r0\n"
"lsls r1, 3\n"
"adds r1, 0x4\n"
"lsls r1, 8\n"
"movs r3, 0x6\n"
"ldrsh r0, [r5, r3]\n"
"lsls r2, r0, 1\n"
"adds r2, r0\n"
"lsls r2, 3\n"
"adds r2, 0x4\n"
"lsls r2, 8\n"
"mov r0, r8\n"
"bl SetEntityPixelPos\n"
"movs r2, 0\n"
"movs r1, 0\n"
"strh r1, [r7, 0x22]\n"
"movs r0, 0x1\n"
"strb r0, [r7, 0x1C]\n"
"strb r2, [r7, 0x1E]\n"
"str r1, [r7, 0x18]\n"
"ldr r0, _0807D65C\n"
"ldr r0, [r0]\n"
"ldr r5, _0807D660\n"
"adds r0, r5\n"
"add r0, r9\n"
"ldr r0, [r0]\n"
"str r0, [r4]\n"
"adds r7, 0x74\n"
"movs r0, 0x74\n"
"add r8, r0\n"
"ldr r2, _0807D658\n"
"add r2, sp\n"
"ldr r1, [r2]\n"
"adds r1, 0x1\n"
"str r1, [r2]\n"
"_0807D5FE:\n"
"movs r3, 0x4\n"
"add r9, r3\n"
"movs r4, 0x1\n"
"add r10, r4\n"
"_0807D606:\n"
"ldr r0, _0807D65C\n"
"ldr r1, [r0]\n"
"ldr r5, _0807D664\n"
"adds r0, r1, r5\n"
"movs r2, 0\n"
"ldrsh r0, [r0, r2]\n"
"cmp r10, r0\n"
"bge _0807D634\n"
"ldr r3, _0807D668\n"
"adds r0, r1, r3\n"
"add r0, r9\n"
"ldr r5, [r0]\n"
"adds r0, r5, 0\n"
"bl EntityExists\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0807D5FE\n"
"ldr r4, _0807D658\n"
"add r4, sp\n"
"ldr r4, [r4]\n"
"cmp r4, 0x18\n"
"ble _0807D54C\n"
"_0807D634:\n"
"ldr r5, _0807D658\n"
"add r5, sp\n"
"ldr r5, [r5]\n"
"cmp r5, 0\n"
"bne _0807D670\n"
"ldr r0, _0807D66C\n"
"ldr r1, [r0]\n"
"ldr r2, _0807D650\n"
"add r2, sp\n"
"ldr r0, [r2]\n"
"bl LogMessageByIdWithPopupCheckUser\n"
"b _0807D9F4\n"
".align 2, 0\n"
"_0807D650: .4byte 0x00000d08\n"
"_0807D654: .4byte 0x00000b58\n"
"_0807D658: .4byte 0x00000d0c\n"
"_0807D65C: .4byte gDungeon\n"
"_0807D660: .4byte 0x00003804\n"
"_0807D664: .4byte 0x00003904\n"
"_0807D668: .4byte 0x0001361c\n"
"_0807D66C: .4byte gUnknown_80FE034\n"
"_0807D670:\n"
"movs r1, 0\n"
"movs r7, 0x1D\n"
"ldr r0, _0807D754\n"
"add r0, sp\n"
"_0807D678:\n"
"strb r1, [r0]\n"
"subs r0, 0x1\n"
"subs r7, 0x1\n"
"cmp r7, 0\n"
"bge _0807D678\n"
"movs r7, 0\n"
"ldr r3, _0807D758\n"
"add r3, sp\n"
"ldr r3, [r3]\n"
"cmp r7, r3\n"
"blt _0807D690\n"
"b _0807D7CC\n"
"_0807D690:\n"
"ldr r4, _0807D75C\n"
"mov r10, r4\n"
"ldr r5, _0807D760\n"
"movs r0, 0\n"
"ldrsh r5, [r5, r0]\n"
"ldr r0, _0807D764\n"
"add r0, sp\n"
"str r5, [r0]\n"
"_0807D6A0:\n"
"movs r1, 0\n"
"mov r9, r1\n"
"ldr r2, _0807D768\n"
"add r2, sp\n"
"ldr r2, [r2]\n"
"ldrh r0, [r2, 0x4]\n"
"ldr r1, _0807D76C\n"
"ands r6, r1\n"
"orrs r6, r0\n"
"ldrh r0, [r2, 0x6]\n"
"lsls r0, 16\n"
"mov r4, r10\n"
"ands r6, r4\n"
"orrs r6, r0\n"
"mov r4, r9\n"
"adds r5, r7, 0x1\n"
"movs r0, 0xD2\n"
"lsls r0, 4\n"
"add r0, sp\n"
"str r5, [r0]\n"
"ldr r1, _0807D760\n"
"ldr r2, _0807D764\n"
"add r2, sp\n"
"ldr r2, [r2]\n"
"cmp r2, 0x63\n"
"beq _0807D790\n"
"ldr r3, _0807D770\n"
"add r3, sp\n"
"mov r8, r3\n"
"_0807D6DA:\n"
"ldr r0, _0807D774\n"
"add r0, sp\n"
"adds r0, r4\n"
"ldr r5, _0807D778\n"
"add r5, sp\n"
"str r0, [r5]\n"
"ldrb r0, [r0]\n"
"cmp r0, 0\n"
"bne _0807D77C\n"
"lsls r2, r4, 2\n"
"adds r2, r1\n"
"ldrh r0, [r2]\n"
"ldr r1, _0807D768\n"
"add r1, sp\n"
"ldr r1, [r1]\n"
"ldrh r1, [r1, 0x4]\n"
"adds r0, r1\n"
"lsls r0, 16\n"
"lsrs r0, 16\n"
"ldr r1, _0807D76C\n"
"ands r6, r1\n"
"orrs r6, r0\n"
"ldrh r0, [r2, 0x2]\n"
"ldr r2, _0807D768\n"
"add r2, sp\n"
"ldr r2, [r2]\n"
"ldrh r2, [r2, 0x6]\n"
"adds r0, r2\n"
"lsls r0, 16\n"
"mov r3, r10\n"
"ands r6, r3\n"
"orrs r6, r0\n"
"lsls r0, r6, 16\n"
"asrs r0, 16\n"
"asrs r1, r6, 16\n"
"bl GetTile\n"
"adds r2, r0, 0\n"
"ldrh r1, [r2]\n"
"movs r3, 0x3\n"
"ands r3, r1\n"
"cmp r3, 0x1\n"
"bne _0807D77C\n"
"movs r5, 0x80\n"
"lsls r5, 2\n"
"adds r0, r5, 0\n"
"ands r0, r1\n"
"cmp r0, 0\n"
"bne _0807D77C\n"
"ldr r0, [r2, 0x14]\n"
"cmp r0, 0\n"
"bne _0807D77C\n"
"lsls r0, r7, 2\n"
"add r0, r8\n"
"str r6, [r0]\n"
"ldr r0, _0807D778\n"
"add r0, sp\n"
"ldr r0, [r0]\n"
"strb r3, [r0]\n"
"b _0807D7B8\n"
".align 2, 0\n"
"_0807D754: .4byte 0x00000d05\n"
"_0807D758: .4byte 0x00000d0c\n"
"_0807D75C: .4byte 0x0000ffff\n"
"_0807D760: .4byte gUnknown_80F4468\n"
"_0807D764: .4byte 0x00000d18\n"
"_0807D768: .4byte 0x00000d08\n"
"_0807D76C: .4byte 0xffff0000\n"
"_0807D770: .4byte 0x00000bbc\n"
"_0807D774: .4byte 0x00000ce8\n"
"_0807D778: .4byte 0x00000d28\n"
"_0807D77C:\n"
"adds r4, 0x1\n"
"cmp r4, 0x1D\n"
"bgt _0807D790\n"
"lsls r0, r4, 2\n"
"ldr r1, _0807D9B4\n"
"adds r0, r1\n"
"movs r2, 0\n"
"ldrsh r0, [r0, r2]\n"
"cmp r0, 0x63\n"
"bne _0807D6DA\n"
"_0807D790:\n"
"mov r3, r9\n"
"cmp r3, 0\n"
"bne _0807D7B8\n"
"movs r0, 0x74\n"
"muls r0, r7\n"
"add r0, sp\n"
"adds r0, 0x4\n"
"str r3, [r0]\n"
"ldr r1, _0807D9B8\n"
"add r1, sp\n"
"lsls r0, r7, 2\n"
"adds r1, r0\n"
"ldrh r2, [r1]\n"
"mov r0, r10\n"
"orrs r0, r2\n"
"strh r0, [r1]\n"
"ldrh r2, [r1, 0x2]\n"
"mov r0, r10\n"
"orrs r0, r2\n"
"strh r0, [r1, 0x2]\n"
"_0807D7B8:\n"
"movs r4, 0xD2\n"
"lsls r4, 4\n"
"add r4, sp\n"
"ldr r7, [r4]\n"
"ldr r5, _0807D9BC\n"
"add r5, sp\n"
"ldr r5, [r5]\n"
"cmp r7, r5\n"
"bge _0807D7CC\n"
"b _0807D6A0\n"
"_0807D7CC:\n"
"movs r7, 0\n"
"ldr r0, _0807D9BC\n"
"add r0, sp\n"
"ldr r0, [r0]\n"
"cmp r7, r0\n"
"bge _0807D866\n"
"_0807D7D8:\n"
"movs r0, 0x74\n"
"adds r1, r7, 0\n"
"muls r1, r0\n"
"mov r8, r1\n"
"mov r4, sp\n"
"add r4, r8\n"
"adds r4, 0x4\n"
"adds r0, r4, 0\n"
"bl EntityExists\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0807D85A\n"
"adds r0, r4, 0x4\n"
"movs r1, 0x1\n"
"bl sub_80461C8\n"
"movs r2, 0x4\n"
"ldrsh r0, [r4, r2]\n"
"movs r3, 0x6\n"
"ldrsh r1, [r4, r3]\n"
"bl sub_80402AC\n"
"movs r5, 0xC2\n"
"lsls r5, 4\n"
"add r5, sp\n"
"lsls r6, r7, 3\n"
"adds r5, r6\n"
"ldr r4, _0807D9B8\n"
"add r4, sp\n"
"lsls r0, r7, 2\n"
"adds r4, r0\n"
"movs r0, 0\n"
"ldrsh r1, [r4, r0]\n"
"lsls r0, r1, 1\n"
"adds r0, r1\n"
"lsls r0, 3\n"
"adds r0, 0x4\n"
"lsls r0, 8\n"
"add r1, sp, 0x10\n"
"add r1, r8\n"
"ldr r1, [r1]\n"
"subs r0, r1\n"
"movs r1, 0x3C\n"
"bl __divsi3\n"
"str r0, [r5]\n"
"ldr r5, _0807D9C0\n"
"add r5, sp\n"
"adds r5, r6\n"
"movs r2, 0x2\n"
"ldrsh r1, [r4, r2]\n"
"lsls r0, r1, 1\n"
"adds r0, r1\n"
"lsls r0, 3\n"
"adds r0, 0x4\n"
"lsls r0, 8\n"
"add r1, sp, 0x14\n"
"add r1, r8\n"
"ldr r1, [r1]\n"
"subs r0, r1\n"
"movs r1, 0x3C\n"
"bl __divsi3\n"
"str r0, [r5]\n"
"_0807D85A:\n"
"adds r7, 0x1\n"
"ldr r3, _0807D9BC\n"
"add r3, sp\n"
"ldr r3, [r3]\n"
"cmp r7, r3\n"
"blt _0807D7D8\n"
"_0807D866:\n"
"movs r1, 0xD1\n"
"lsls r1, 1\n"
"ldr r4, _0807D9C4\n"
"add r4, sp\n"
"ldr r0, [r4]\n"
"bl sub_80421C0\n"
"movs r5, 0\n"
"mov r9, r5\n"
"ldr r0, _0807D9C8\n"
"ldr r0, [r0]\n"
"ldr r1, _0807D9CC\n"
"adds r0, r1\n"
"ldrb r0, [r0]\n"
"ldr r2, _0807D9D0\n"
"add r2, sp\n"
"str r0, [r2]\n"
"mov r10, r5\n"
"movs r6, 0\n"
"_0807D88C:\n"
"movs r7, 0\n"
"mov r3, r10\n"
"adds r3, 0x22\n"
"ldr r4, _0807D9D4\n"
"add r4, sp\n"
"str r3, [r4]\n"
"adds r5, r6, 0x1\n"
"ldr r0, _0807D9D8\n"
"add r0, sp\n"
"str r5, [r0]\n"
"ldr r1, _0807D9BC\n"
"add r1, sp\n"
"ldr r1, [r1]\n"
"cmp r7, r1\n"
"bge _0807D916\n"
"mov r2, r9\n"
"lsls r2, 24\n"
"mov r8, r2\n"
"_0807D8B0:\n"
"movs r0, 0x74\n"
"adds r5, r7, 0\n"
"muls r5, r0\n"
"mov r4, sp\n"
"adds r4, r5\n"
"adds r4, 0x4\n"
"adds r0, r4, 0\n"
"bl EntityExists\n"
"lsls r0, 24\n"
"cmp r0, 0\n"
"beq _0807D90A\n"
"movs r0, 0xC2\n"
"lsls r0, 4\n"
"add r0, sp\n"
"lsls r2, r7, 3\n"
"adds r0, r2\n"
"ldr r1, [r0]\n"
"ldr r0, _0807D9C0\n"
"add r0, sp\n"
"adds r0, r2\n"
"ldr r2, [r0]\n"
"adds r0, r4, 0\n"
"bl IncreaseEntityPixelPos\n"
"mov r0, r10\n"
"bl sin_4096\n"
"add r2, sp, 0x20\n"
"adds r2, r5\n"
"lsls r1, r0, 1\n"
"adds r1, r0\n"
"lsls r1, 2\n"
"str r1, [r2]\n"
"movs r0, 0\n"
"str r0, [sp]\n"
"adds r0, r4, 0\n"
"ldr r3, _0807D9D0\n"
"add r3, sp\n"
"ldr r1, [r3]\n"
"movs r2, 0\n"
"mov r4, r8\n"
"lsrs r3, r4, 24\n"
"bl sub_80462AC\n"
"_0807D90A:\n"
"adds r7, 0x1\n"
"ldr r5, _0807D9BC\n"
"add r5, sp\n"
"ldr r5, [r5]\n"
"cmp r7, r5\n"
"blt _0807D8B0\n"
"_0807D916:\n"
"movs r0, 0x13\n"
"bl sub_803E46C\n"
"ldr r0, _0807D9D4\n"
"add r0, sp\n"
"ldr r0, [r0]\n"
"mov r10, r0\n"
"movs r0, 0x3\n"
"ands r0, r6\n"
"cmp r0, 0\n"
"bne _0807D930\n"
"movs r1, 0x1\n"
"add r9, r1\n"
"_0807D930:\n"
"movs r0, 0x7\n"
"mov r2, r9\n"
"ands r2, r0\n"
"mov r9, r2\n"
"ldr r3, _0807D9D8\n"
"add r3, sp\n"
"ldr r6, [r3]\n"
"cmp r6, 0x3B\n"
"ble _0807D88C\n"
"movs r7, 0\n"
"ldr r4, _0807D9BC\n"
"add r4, sp\n"
"ldr r4, [r4]\n"
"cmp r7, r4\n"
"bge _0807D996\n"
"_0807D94E:\n"
"ldr r0, _0807D9B8\n"
"add r0, sp\n"
"lsls r1, r7, 2\n"
"adds r4, r0, r1\n"
"movs r5, 0\n"
"ldrsh r0, [r4, r5]\n"
"cmp r0, 0\n"
"blt _0807D98A\n"
"movs r0, 0x74\n"
"muls r0, r7\n"
"add r0, sp\n"
"adds r0, 0x4\n"
"bl GetItemData\n"
"adds r1, r0, 0\n"
"adds r0, r4, 0\n"
"movs r2, 0x1\n"
"bl sub_80460F8\n"
"movs r1, 0\n"
"ldrsh r0, [r4, r1]\n"
"movs r2, 0x2\n"
"ldrsh r1, [r4, r2]\n"
"bl sub_80402AC\n"
"movs r3, 0x1\n"
"movs r4, 0xD1\n"
"lsls r4, 4\n"
"add r4, sp\n"
"str r3, [r4]\n"
"_0807D98A:\n"
"adds r7, 0x1\n"
"ldr r5, _0807D9BC\n"
"add r5, sp\n"
"ldr r5, [r5]\n"
"cmp r7, r5\n"
"blt _0807D94E\n"
"_0807D996:\n"
"movs r0, 0xD1\n"
"lsls r0, 4\n"
"add r0, sp\n"
"ldr r0, [r0]\n"
"cmp r0, 0\n"
"beq _0807D9E0\n"
"ldr r0, _0807D9DC\n"
"ldr r1, [r0]\n"
"ldr r2, _0807D9C4\n"
"add r2, sp\n"
"ldr r0, [r2]\n"
"bl LogMessageByIdWithPopupCheckUser\n"
"b _0807D9EE\n"
".align 2, 0\n"
"_0807D9B4: .4byte gUnknown_80F4468\n"
"_0807D9B8: .4byte 0x00000bbc\n"
"_0807D9BC: .4byte 0x00000d0c\n"
"_0807D9C0: .4byte 0x00000c24\n"
"_0807D9C4: .4byte 0x00000d08\n"
"_0807D9C8: .4byte gDungeon\n"
"_0807D9CC: .4byte 0x00018210\n"
"_0807D9D0: .4byte 0x00000d14\n"
"_0807D9D4: .4byte 0x00000d1c\n"
"_0807D9D8: .4byte 0x00000d24\n"
"_0807D9DC: .4byte gUnknown_80FE060\n"
"_0807D9E0:\n"
"ldr r0, _0807DA08\n"
"ldr r1, [r0]\n"
"ldr r3, _0807DA0C\n"
"add r3, sp\n"
"ldr r0, [r3]\n"
"bl LogMessageByIdWithPopupCheckUser\n"
"_0807D9EE:\n"
"movs r0, 0x1\n"
"bl sub_807EC28\n"
"_0807D9F4:\n"
"ldr r3, _0807DA10\n"
"add sp, r3\n"
"pop {r3-r5}\n"
"mov r8, r3\n"
"mov r9, r4\n"
"mov r10, r5\n"
"pop {r4-r7}\n"
"pop {r0}\n"
"bx r0\n"
".align 2, 0\n"
"_0807DA08: .4byte gUnknown_80FE034\n"
"_0807DA0C: .4byte 0x00000d08\n"
"_0807DA10: .4byte 0x00000d2c");
}


void HandlePounceOrbAction(Entity *pokemon, Entity *target, u8 r2) {
    EntityInfo *info;
    const Tile *tile;
    DungeonPos pos;
    u32 direction = r2;
    info = GetEntInfo(target);
    if(HasAbility(target, 0xE))
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

        if(pos.x <= 0 || pos.y <= 0 || pos.x > 0x36 || pos.y > 0x1E) break;
        
        tile = GetTile(pos.x, pos.y);

        if(tile->monster) break;
        if(!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY))) break;
    
        sub_80694C0(target, pos.x, pos.y, 0);
    
        sub_804535C(target, 0);
        if(!sub_8045888(target)) continue;
        sub_803E46C(0x3A);
    }
    
    sub_806A5B8(target);
    if(sub_80706A4(target, &target->pos))
        sub_807D148(target, target, 0, 0);
    if(EntityExists(target))
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

	for (y = 0; y < 0x20; y++)
		for(x = 0; x < 0x38; x++)
		{
			tile = GetTileMut(x, y);
			if((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY)
			{   
				tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
				tile->terrainType |= TERRAIN_TYPE_NORMAL;
				sub_80498A8(x, y);
				flag = TRUE;
			}
		}
	for (y = 0; y < 0x20; y++)
		for(x = 0; x < 0x38; x++)
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
	sub_8040A84();
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
					if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_SECONDARY) 
						if(((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY))) {
							if (((x == 1) || (((y == 1 || (x == DUNGEON_MAX_SIZE_X - 2)) || (y == DUNGEON_MAX_SIZE_Y - 2)))) &&
								((tile->object == NULL && (gDungeon->unk644.unk2C == 0)))) {
								bVar1 = TRUE;
							}
							if (bVar1) {
								tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
								tile->terrainType |= TERRAIN_TYPE_SECONDARY;
							}
							else {
								if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_NORMAL) continue;
								tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
								tile->terrainType |= TERRAIN_TYPE_NORMAL;
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
						tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
						tile->terrainType |= TERRAIN_TYPE_SECONDARY;
					}
			}
		}
	}
	if (isMonsterHouse) {
		gDungeon->monsterHouseRoom = 0;
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
		if (EntityExists(entity)) {
			entity->room = GetTile(entity->pos.x,entity->pos.y)->room;
		}
	}
	sub_804EB30();
	sub_804AAD4();
	sub_8049884();
	sub_806CF60();
	sub_8040A84();
	sub_8049ED4();
	LogMessageByIdWithPopupCheckUser(pokemon,*gUnknown_80FD3A0);
	sub_803E708(0x28,0x2b);
	sub_8075900(pokemon,1);
	for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
	{
		entity = gDungeon->activePokemon[index];
		if (EntityExists(entity)) {
			sub_806A5B8(entity);
			if ((EntityExists(entity)) && (sub_80706A4(entity,&entity->pos))) {
				sub_807D148(entity,entity,0,0);
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
        if ((EntityExists(entity1)) && (HasAbility(entity1, ABILITY_DAMP))) break;
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
                        && (tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == 0)))
                    )) && (tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0) {
                        tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
                        tile->terrainType |= TERRAIN_TYPE_NORMAL;
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
        sub_8040A84();
        sub_8049ED4();
    }
}

