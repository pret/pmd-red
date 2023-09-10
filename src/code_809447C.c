#include "global.h"
#include "code_80130A8.h"
#include "code_8092334.h"
#include "code_809447C.h"
#include "dungeon.h"
#include "dungeon_global_data.h"
#include "items.h"
#include "moves.h"
#include "text_util.h"
#include "text2.h"

struct unkStruct_8113080
{
    u8 unk0;
    u8 *text;
};

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[];
extern s32 gUnknown_202DE30[2];

extern u8 *gUnknown_811383C[];
extern u8 *gUnknown_8113850[];
extern u8 *gUnknown_8113868[];
extern u8 *gUnknown_8113898[];
extern u8 *gUnknown_81138C0[];
extern u8 *gUnknown_81138D0[];
extern u8 *gUnknown_81138E4[];
extern u8 *gUnknown_8113950[];
extern u8 *gUnknown_8113900[];
extern u8 *gUnknown_8113974[];
extern u8 *gUnknown_8113918[];
extern u8 *gUnknown_8113990[];
extern u8 *gUnknown_8113934[];
extern u8 *gUnknown_81139B4[];
extern u8 *gUnknown_81139B8[];
extern u8 *gUnknown_81139CC[];
extern u8 *gUnknown_8113870[];

extern struct unkStruct_8113080 gUnknown_8113080[];

extern void xxx_format_string(const char *, u8 *, void *, u32);
extern s32 sub_8008ED0(u8 *);

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
        sub_80928C0(gUnknown_202DE58, &move, NULL);
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

void sub_8094558(u32 param_1,u8 *param_2,unkDungeonGlobal_unk1CE98_sub *param_3)
{
    int iVar2;
    u8 buffer [200];
    s32 y;
    Item *item;
    s32 var;

    sub_80073B8(param_1);
    xxx_format_and_draw(0x10,0,param_2,param_1,0);
    PrintYellowDungeonNametoBuffer(gAvailablePokemonNames, &param_3->dungeonLocation);
    xxx_format_and_draw(4,0x10,*gUnknown_8113850,param_1,0); // #+Place: $m0
    y = 0x1A;
    sub_80922B4(gAvailablePokemonNames, param_3->buffer1, POKEMON_NAME_LENGTH);
    sub_80922B4(gAvailablePokemonNames + 0x50, param_3->buffer2, POKEMON_NAME_LENGTH);
    if (sub_8094528(param_3->moveID) != 0) {
        // $m1 was defeated by
        xxx_format_string(*gUnknown_8113868,buffer,(u32 **)&buffer + 50,0); // TODO: fix this hack
    }
    else {
        // $m1
        xxx_format_string(*gUnknown_8113870,buffer,(u32 **)&buffer + 50,0); // TODO: fix this hack
    }
    iVar2 = sub_8008ED0(buffer);
    xxx_format_and_draw(((0xb0 - iVar2) / 2),y,buffer,param_1,0);
    y += 0xA;
    sub_80944BC(param_3->moveID, buffer);
#ifndef NONMATCHING
    var = 0xb0 - sub_8008ED0(buffer);
    var += (var < 0);
    xxx_format_and_draw(var >> 1,y,buffer,param_1,0);
    asm(""::"r"(var));
#else
    xxx_format_and_draw((0xb0 - sub_8008ED0(buffer) / 2),y,buffer,param_1,0);
#endif
    y += 0x10;
    gUnknown_202DE30[0] = param_3->exp;
    gUnknown_202DE30[1] = param_3->level;
    if (gUnknown_202DE30[1] >= 100) {
        xxx_format_and_draw(4,y,*gUnknown_81138C0,param_1,0);
    }
    else {
        xxx_format_and_draw(4,y,*gUnknown_8113898,param_1,0);
    }
    y += 0xA;
    gUnknown_202DE30[0] = param_3->maxHPStat;
    xxx_format_and_draw(4,y,*gUnknown_81138D0,param_1,0);
    y += 0xA;
    gUnknown_202DE30[0] = param_3->atk;
    gUnknown_202DE30[1] = param_3->def;
    if (param_3->attBoost) {
        gUnknown_202DE30[0] = gUnknown_202DE30[0] + param_3->attBoost;
        xxx_format_and_draw(4,y,*gUnknown_8113950,param_1,0);
    }
    else {
        xxx_format_and_draw(4,y,*gUnknown_81138E4,param_1,0);
    }
    if (param_3->defBoost) {
        gUnknown_202DE30[1] = gUnknown_202DE30[1] + param_3->defBoost;
        xxx_format_and_draw(4,y,*gUnknown_8113974,param_1,0);
    }
    else {
        xxx_format_and_draw(4,y,*gUnknown_8113900,param_1,0);
    }
    y += 0xA;
    gUnknown_202DE30[0] = param_3->spAtk;
    gUnknown_202DE30[1] = param_3->spDef;
    if (param_3->spAttBoost) {
        gUnknown_202DE30[0] = gUnknown_202DE30[0] + param_3->spAttBoost;
        xxx_format_and_draw(4,y,*gUnknown_8113990,param_1,0);
    }
    else {
        xxx_format_and_draw(4,y,*gUnknown_8113918,param_1,0);
    }
    if (param_3->spDefBoost) {
        gUnknown_202DE30[1] = gUnknown_202DE30[1] + param_3->spDefBoost;
        xxx_format_and_draw(4,y,*gUnknown_81139B4,param_1,0);
    }
    else {
        xxx_format_and_draw(4,y,*gUnknown_8113934,param_1,0);
    }
    y += 0x10;
    item = &(param_3->heldItem);
    if ((param_3->heldItem.flags & ITEM_FLAG_EXISTS)) {
        sub_8090E14(gUnknown_202DE58,item,0);
    }
    else {
        strcpy(gUnknown_202DE58,*gUnknown_81139B8);
    }
    xxx_format_and_draw(4,y,*gUnknown_81139CC,param_1,0);
    sub_80073E0(param_1);
}
