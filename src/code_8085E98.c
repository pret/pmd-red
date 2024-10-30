#include "global.h"
#include "code_8085E98.h"
#include "code_800E9A8.h"
#include "code_803E46C.h"
#include "dungeon_util.h"
#include "items.h"
#include "code_800DAC0.h"

#include "structs/str_dungeon.h"

extern const unkStruct_2039DB0 gUnknown_8107374;


void sub_800EF64(void);
void sub_800EE5C(s32);
void sub_8085F44(s32);
void sub_800E90C(Position *);
void sub_8088EE8(void);
void sub_8088848(void);
void sub_808A718(void);


void sub_8085E98(void)
{
    gDungeon->unk181e8.unk18215 = 0;
}

void sub_8085EB0(void)
{
    gDungeon->unk181e8.unk18215 = 1;
}

u32 sub_8085EC8(s16 param_1,u32 param_2,u32 param_3,Position *param_4,bool32 param_5)
{
    u32 uVar1;
    unkStruct_80416E0 local_40;

    bool8 param_5_bool8;
    s32 param_1_s32 = param_1;


    param_5_bool8 = param_5;

    sub_800EE5C(param_1_s32);
    sub_800EF64();
    sub_803E46C(0x46);
    local_40.unk0 = param_1;
    local_40.unk4 = param_2;
    local_40.unk8 = param_3;
    local_40.x = param_4->x;
    local_40.y = param_4->y;
    local_40.unk10 = 0;
    local_40.unk12 = 0;
    local_40.unk18 = 0xffff;
    local_40.unk1C = gUnknown_8107374;

    uVar1 = sub_800E890(&local_40);
    if (param_5_bool8) {
        sub_8085F44(uVar1);
        uVar1 = -1;
    }
    return uVar1;
}

void sub_8085F44(s32 param_1)
{
    while (sub_800E9A8(param_1)) {
        sub_800E90C(&gDungeon->unk181e8.cameraPixelPos);
        sub_803E46C(0x46);
    }
}

void sub_8085F78(void)
{
    switch(gDungeon->unk3A0D) {
        case 0x12:
        case 0x13:
        case 0x14:
            sub_8088848();
            break;
        case 0x15:
            sub_8088EE8();
            break;
        case 0x29:
        case 0x2A:
            sub_808A718();
            break;

        case 0:
        case 0x3C:
        default:
            break;
    }
    return;
}

bool8 sub_80860A8(u8 id)
{

    Item *item;
    EntityInfo *info;
    Entity *entity;
    int index;


    for(index = 0; index < INVENTORY_SIZE; index++)
    {
        item = &gTeamInventoryRef->teamItems[index];
        if((item->flags & 1) != 0)
        {
            if((item->id) == id) return TRUE;
        }
    }

    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if (((EntityExists(entity)) && (info = GetEntInfo(entity), ((info->heldItem).flags & 1))) && ((info->heldItem).id == id)) return TRUE;
    }
    return FALSE;
}
