#include "global.h"
#include "string_format.h"
#include "code_8092334.h"
#include "code_809447C.h"
#include "dungeon.h"
#include "structs/str_dungeon.h"
#include "items.h"
#include "moves.h"
#include "text_util.h"
#include "text.h"

struct unkStruct_8113080
{
    u8 unk0;
    u8 *text;
};

extern const u8 *gPtrDeathToMoveText[];
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

extern struct unkStruct_8113080 gSpecialDeathText[];

void ReadBellyBits(DataSerializer *r0, FixedPoint *dst)
{
    ReadBits(r0, &dst->unk0, 16);
    ReadBits(r0, &dst->unk2, 16);
}

void WriteBellyBits(DataSerializer *r0, FixedPoint *src)
{
    WriteBits(r0, &src->unk0, 16);
    WriteBits(r0, &src->unk2, 16);
}

static void WriteDeathText(s16 moveID, u8 *buffer)
{
    u16 moveID_u16;
    s32 moveID_s32 = moveID;
    Move move;

    if (moveID_s32 < 0x1F4) {
        // Needed this cast/variable to match
        moveID_u16 = moveID_s32;
        InitPokemonMoveOrNullObject(&move, moveID_u16);
        BufferMoveName(gFormatBuffer_Items[0], &move, NULL);
        FormatString(*gPtrDeathToMoveText, buffer, buffer + 200, 0); // $m0's $i0
    } else {
        strncpy(buffer, gSpecialDeathText[moveID - 0x1F4].text, 200);
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
        return gSpecialDeathText[moveID  - 0x1F4].unk0;
    }
}

void sub_8094558(u32 param_1,u8 *param_2,UnkDungeonGlobal_unk1CE98_sub *param_3)
{
    u8 buffer [200];
    s32 x, y;
    Item *item;

    sub_80073B8(param_1);
    PrintFormattedStringOnWindow(0x10,0,param_2,param_1,0);
    PrintYellowDungeonNametoBuffer(gFormatBuffer_Monsters[0], &param_3->dungeonLocation);
    PrintFormattedStringOnWindow(4,0x10,*gUnknown_8113850,param_1,0); // #+Place: $m0
    y = 0x1A;
    sub_80922B4(gFormatBuffer_Monsters[0], param_3->buffer1, POKEMON_NAME_LENGTH);
    sub_80922B4(gFormatBuffer_Monsters[1], param_3->buffer2, POKEMON_NAME_LENGTH);
    if (sub_8094528(param_3->moveID) != 0) {
        // $m1 was defeated by
        FormatString(*gUnknown_8113868,buffer, buffer + sizeof(buffer),0);
    }
    else {
        // $m1
        FormatString(*gUnknown_8113870,buffer, buffer + sizeof(buffer),0);
    }

    x = (0xb0 - sub_8008ED0(buffer)) / 2;
    PrintFormattedStringOnWindow(x,y,buffer,param_1,0);

    y += 0xA;
    WriteDeathText(param_3->moveID, buffer);

    x = (0xb0 - sub_8008ED0(buffer)) / 2;
    PrintFormattedStringOnWindow(x,y,buffer,param_1,0);

    y += 0x10;
    gFormatArgs[0] = param_3->exp;
    gFormatArgs[1] = param_3->level;
    if (gFormatArgs[1] >= 100) {
        PrintFormattedStringOnWindow(4,y,*gUnknown_81138C0,param_1,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,*gUnknown_8113898,param_1,0);
    }
    y += 0xA;
    gFormatArgs[0] = param_3->maxHPStat;
    PrintFormattedStringOnWindow(4,y,*gUnknown_81138D0,param_1,0);
    y += 0xA;
    gFormatArgs[0] = param_3->atk;
    gFormatArgs[1] = param_3->def;
    if (param_3->attBoost) {
        gFormatArgs[0] = gFormatArgs[0] + param_3->attBoost;
        PrintFormattedStringOnWindow(4,y,*gUnknown_8113950,param_1,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,*gUnknown_81138E4,param_1,0);
    }
    if (param_3->defBoost) {
        gFormatArgs[1] = gFormatArgs[1] + param_3->defBoost;
        PrintFormattedStringOnWindow(4,y,*gUnknown_8113974,param_1,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,*gUnknown_8113900,param_1,0);
    }
    y += 0xA;
    gFormatArgs[0] = param_3->spAtk;
    gFormatArgs[1] = param_3->spDef;
    if (param_3->spAttBoost) {
        gFormatArgs[0] = gFormatArgs[0] + param_3->spAttBoost;
        PrintFormattedStringOnWindow(4,y,*gUnknown_8113990,param_1,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,*gUnknown_8113918,param_1,0);
    }
    if (param_3->spDefBoost) {
        gFormatArgs[1] = gFormatArgs[1] + param_3->spDefBoost;
        PrintFormattedStringOnWindow(4,y,*gUnknown_81139B4,param_1,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,*gUnknown_8113934,param_1,0);
    }
    y += 0x10;
    item = &(param_3->heldItem);
    if ((param_3->heldItem.flags & ITEM_FLAG_EXISTS)) {
        sub_8090E14(gFormatBuffer_Items[0],item,0);
    }
    else {
        strcpy(gFormatBuffer_Items[0],*gUnknown_81139B8);
    }
    PrintFormattedStringOnWindow(4,y,*gUnknown_81139CC,param_1,0);
    sub_80073E0(param_1);
}
