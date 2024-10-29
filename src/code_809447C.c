#include "global.h"
#include "code_80130A8.h"
#include "code_8092334.h"
#include "code_809447C.h"
#include "dungeon.h"
#include "structs/str_dungeon.h"
#include "items.h"
#include "moves.h"
#include "text_util.h"
#include "text2.h"

struct unkStruct_8113080
{
    u8 unk0;
    u8 *text;
};

extern const u8 *gUnknown_811383C[];
extern const u8 *gUnknown_8113850[];
extern const u8 *gUnknown_8113868[];
extern const u8 *gUnknown_8113898[];
extern const u8 *gUnknown_81138C0[];
extern const u8 *gUnknown_81138D0[];
extern const u8 *gUnknown_81138E4[];
extern const u8 *gUnknown_8113950[];
extern const u8 *gUnknown_8113900[];
extern const u8 *gUnknown_8113974[];
extern const u8 *gUnknown_8113918[];
extern const u8 *gUnknown_8113990[];
extern const u8 *gUnknown_8113934[];
extern const u8 *gUnknown_81139B4[];
extern const u8 *gUnknown_81139B8[];
extern const u8 *gUnknown_81139CC[];
extern const u8 *gUnknown_8113870[];

extern struct unkStruct_8113080 gUnknown_8113080[];

void sub_809447C(struct unkStruct_8094924 *r0, u8 *r1)
{
    RestoreIntegerBits(r0, r1, 0x10);
    RestoreIntegerBits(r0, r1 + 2, 0x10);
}

void sub_809449C(struct unkStruct_8094924 *r0, u8 *r1)
{
    SaveIntegerBits(r0, r1, 0x10);
    SaveIntegerBits(r0, r1 + 2, 0x10);
}

static void sub_80944BC(s16 moveID, u8 *buffer)
{
    u16 moveID_u16;
    s32 moveID_s32 = moveID;
    Move move;

    if (moveID_s32 < 0x1F4) {
        // Needed this cast/variable to match
        moveID_u16 = moveID_s32;
        sub_8092AA8(&move, moveID_u16);
        sub_80928C0(gFormatItems[0], &move, NULL);
        xxx_format_string(*gUnknown_811383C, buffer, buffer + 200, 0); // $m0's $i0
    } else {
        strncpy(buffer, gUnknown_8113080[moveID - 0x1F4].text, 200);
    }
}

static u8 sub_8094528(s16 moveID)
{
    if(moveID < 0x1F4)
    {
        return 1;
    }
    else
    {
        return gUnknown_8113080[moveID  - 0x1F4].unk0;
    }
}

void sub_8094558(u32 param_1,u8 *param_2,UnkDungeonGlobal_unk1CE98_sub *param_3)
{
    u8 buffer [200];
    s32 x, y;
    Item *item;

    sub_80073B8(param_1);
    PrintFormatStringOnWindow(0x10,0,param_2,param_1,0);
    PrintYellowDungeonNametoBuffer(gAvailablePokemonNames[0], &param_3->dungeonLocation);
    PrintFormatStringOnWindow(4,0x10,*gUnknown_8113850,param_1,0); // #+Place: $m0
    y = 0x1A;
    sub_80922B4(gAvailablePokemonNames[0], param_3->buffer1, POKEMON_NAME_LENGTH);
    sub_80922B4(gAvailablePokemonNames[1], param_3->buffer2, POKEMON_NAME_LENGTH);
    if (sub_8094528(param_3->moveID) != 0) {
        // $m1 was defeated by
        xxx_format_string(*gUnknown_8113868,buffer,(u8*)((u32 **)&buffer + 50),0); // TODO: fix this hack
    }
    else {
        // $m1
        xxx_format_string(*gUnknown_8113870,buffer,(u8*)((u32 **)&buffer + 50),0); // TODO: fix this hack
    }

    x = (0xb0 - sub_8008ED0(buffer)) / 2;
    PrintFormatStringOnWindow(x,y,buffer,param_1,0);

    y += 0xA;
    sub_80944BC(param_3->moveID, buffer);

    x = (0xb0 - sub_8008ED0(buffer)) / 2;
    PrintFormatStringOnWindow(x,y,buffer,param_1,0);

    y += 0x10;
    gFormatData_202DE30[0] = param_3->exp;
    gFormatData_202DE30[1] = param_3->level;
    if (gFormatData_202DE30[1] >= 100) {
        PrintFormatStringOnWindow(4,y,*gUnknown_81138C0,param_1,0);
    }
    else {
        PrintFormatStringOnWindow(4,y,*gUnknown_8113898,param_1,0);
    }
    y += 0xA;
    gFormatData_202DE30[0] = param_3->maxHPStat;
    PrintFormatStringOnWindow(4,y,*gUnknown_81138D0,param_1,0);
    y += 0xA;
    gFormatData_202DE30[0] = param_3->atk;
    gFormatData_202DE30[1] = param_3->def;
    if (param_3->attBoost) {
        gFormatData_202DE30[0] = gFormatData_202DE30[0] + param_3->attBoost;
        PrintFormatStringOnWindow(4,y,*gUnknown_8113950,param_1,0);
    }
    else {
        PrintFormatStringOnWindow(4,y,*gUnknown_81138E4,param_1,0);
    }
    if (param_3->defBoost) {
        gFormatData_202DE30[1] = gFormatData_202DE30[1] + param_3->defBoost;
        PrintFormatStringOnWindow(4,y,*gUnknown_8113974,param_1,0);
    }
    else {
        PrintFormatStringOnWindow(4,y,*gUnknown_8113900,param_1,0);
    }
    y += 0xA;
    gFormatData_202DE30[0] = param_3->spAtk;
    gFormatData_202DE30[1] = param_3->spDef;
    if (param_3->spAttBoost) {
        gFormatData_202DE30[0] = gFormatData_202DE30[0] + param_3->spAttBoost;
        PrintFormatStringOnWindow(4,y,*gUnknown_8113990,param_1,0);
    }
    else {
        PrintFormatStringOnWindow(4,y,*gUnknown_8113918,param_1,0);
    }
    if (param_3->spDefBoost) {
        gFormatData_202DE30[1] = gFormatData_202DE30[1] + param_3->spDefBoost;
        PrintFormatStringOnWindow(4,y,*gUnknown_81139B4,param_1,0);
    }
    else {
        PrintFormatStringOnWindow(4,y,*gUnknown_8113934,param_1,0);
    }
    y += 0x10;
    item = &(param_3->heldItem);
    if ((param_3->heldItem.flags & ITEM_FLAG_EXISTS)) {
        sub_8090E14(gFormatItems[0],item,0);
    }
    else {
        strcpy(gFormatItems[0],*gUnknown_81139B8);
    }
    PrintFormatStringOnWindow(4,y,*gUnknown_81139CC,param_1,0);
    sub_80073E0(param_1);
}
