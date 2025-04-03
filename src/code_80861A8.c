#include "global.h"
#include "constants/direction.h"
#include "structs/sprite_oam.h"
#include "code_800DAC0.h"
#include "code_800ED38.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_806CD90.h"
#include "code_80861A8.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "sprite.h"

extern const unkStruct_2039DB0 gUnknown_8107380;

extern const u8 *gUnknown_810665C[];
extern const u8 *gUnknown_810668C[];
extern const u8 *gUnknown_81066D4[];
extern const u8 *gUnknown_81066F0[];
extern const u8 *gUnknown_810671C[];

static void sub_80861EC(Entity *);

s32 sub_800E700(s32);
void sub_8085F44(s32);

void sub_8052FB8(const u8 *);

UNUSED static void sub_8086124(Entity *entity, u8 param_2)
{
    GetEntInfo(entity)->unk160 = param_2;
}

void sub_8086130(void)
{
    DungeonFadeOutBGM(0x3c);
    sub_803E708(0x3c,0x46);
    sub_8052FB8(*gUnknown_810665C);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_810668C);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_81066D4);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_81066F0);
    sub_803E708(0x1e,0x46);
    sub_8052FB8(*gUnknown_810671C);
    sub_803E708(0x1e,0x46);
}

void sub_80861A8(Entity *a0)
{
    sub_806CDD4(a0, 0, NUM_DIRECTIONS);
}

void sub_80861B8(Entity *a0, u8 r1, s32 direction)
{
    EntityInfo *info;

    info = GetEntInfo(a0);

    sub_806CDD4(a0, r1, direction);
    info->unkFE = r1;
}

void sub_80861D4(Entity *a0, u8 r1, s32 direction)
{
    sub_806CDD4(a0, r1, direction);
    sub_80861EC(a0);
}

void sub_80861EC(Entity *a0)
{
    GetEntInfo(a0)->unkFE = 0x63;
}

s32 sub_80861F8(s32 param_1,Entity *param_2,bool32 param_3)
{
    EntityInfo *info;
    s32 uVar2;
    s32 uStack_38;
    DungeonPos pos;
    unkStruct_80416E0 stack;
    unkStruct_2039DB0 stack1C;

    // Needed to match.
    s32 param_1Copy2 = (s16) param_1;
    s32 param_1Copy = param_1Copy2;
    u8 param_3_bool32 = param_3;

    sub_800EE5C(param_1Copy2);
    sub_800EF64();
    DungeonRunFrameActions(0x46);
    info = GetEntInfo(param_2);
    pos.x = 0;
    pos.y = 0;
    uStack_38 = sub_800E700(param_1Copy);
    if (uStack_38 != -1) {
        sub_800569C(&pos, &param_2->axObj, uStack_38);
    }
    stack.unk0 = param_1Copy;
    stack.unk4 = 0;
    stack.dir = info->action.direction;
    stack.x = (param_2->pixelPos).x / 256;
    stack.y = (param_2->pixelPos).y / 256;

    stack.unk10 = pos.x;
    stack.unk12 = pos.y;
    stack.unk14 = uStack_38;
    stack.unk18 = 0xffff;
    stack1C = gUnknown_8107380;

    uVar2 = sub_800E890(&stack);
    if (param_3_bool32) {
        sub_8085F44(uVar2);
        uVar2 = -1;
    }
    return uVar2;
}
