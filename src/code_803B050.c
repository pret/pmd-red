#include "global.h"
#include "globaldata.h"
#include "structs/str_ground_script.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "music_util.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

struct unkStruct_203B3FC
{
    // size: 0x3D0
    MenuHeaderWindow mh;
    s16 unkA0[10];
};
EWRAM_INIT struct unkStruct_203B3FC *gUnknown_203B3FC = NULL;

extern WindowTemplate gUnknown_80E7F3C;

NAKED
bool8 sub_803B050(void)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tldr r4, _0803B0F4\n"
	"\tmovs r0, 0xF4\n"
	"\tlsls r0, 2\n"
	"\tmovs r1, 0x8\n"
	"\tbl MemoryAlloc\n"
	"\tstr r0, [r4]\n"
	"\tmovs r1, 0x3\n"
	"\tstr r1, [r0, 0x34]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x84\n"
	"\tstr r1, [r0, 0x38]\n"
	"\tadds r0, 0x3C\n"
	"\tbl RestoreSavedWindows\n"
	"\tldr r1, [r4]\n"
	"\tldr r2, [r1, 0x34]\n"
	"\tlsls r0, r2, 1\n"
	"\tadds r0, r2\n"
	"\tlsls r0, 3\n"
	"\tadds r1, r0\n"
	"\tadds r1, 0x3C\n"
	"\tldr r0, _0803B0F8\n"
	"\tldm r0!, {r2,r3,r5}\n"
	"\tstm r1!, {r2,r3,r5}\n"
	"\tldm r0!, {r2,r3,r5}\n"
	"\tstm r1!, {r2,r3,r5}\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, [r0, 0x38]\n"
	"\tadds r0, 0x9C\n"
	"\tstr r0, [r1, 0x14]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl ShowWindows\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0\n"
	"\tmovs r7, 0xCB\n"
	"\tlsls r7, 1\n"
	"\tmovs r6, 0x80\n"
	"\tlsls r6, 9\n"
	"\tmovs r5, 0\n"
"_0803B0AE:\n"
	"\tldr r0, _0803B0FC\n"
	"\tadds r0, r5, r0\n"
	"\tmovs r1, 0x2\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tldr r4, _0803B0F4\n"
	"\tcmp r0, 0xA\n"
	"\tbne _0803B0C8\n"
	"\tldr r0, [r4]\n"
	"\tlsls r1, r2, 1\n"
	"\tadds r0, 0xA0\n"
	"\tadds r0, r1\n"
	"\tstrh r3, [r0]\n"
	"\tadds r2, 0x1\n"
"_0803B0C8:\n"
	"\tadds r0, r6, 0\n"
	"\tmovs r3, 0x80\n"
	"\tlsls r3, 9\n"
	"\tadds r6, r3\n"
	"\tadds r5, 0xC\n"
	"\tasrs r3, r0, 16\n"
	"\tcmp r3, r7\n"
	"\tble _0803B0AE\n"
	"\tldr r0, [r4]\n"
	"\tldr r3, [r0, 0x34]\n"
	"\tadds r1, r2, 0\n"
	"\tmovs r2, 0xA\n"
	"\tbl CreateMenuOnWindow\n"
	"\tbl sub_803B204\n"
	"\tbl sub_803B284\n"
	"\tmovs r0, 0x1\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_0803B0F4: .4byte gUnknown_203B3FC\n"
"_0803B0F8: .4byte gUnknown_80E7F54\n"
"_0803B0FC: .4byte gFunctionScriptTable");
}

void sub_803B204(void);
void sub_803B284(void);

void sub_803B100(s32 _id) {
    s32 id = (s16)_id;

    MoveMenuToEntryId(&gUnknown_203B3FC->mh.m.input, id);
    sub_803B204();
    sub_803B284();
}

s32 sub_803B120(void)
{
    switch(GetKeyPress(&gUnknown_203B3FC->mh.m.input))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            return 3;
        default:
            break;
    }
    if((MenuCursorUpdate(&gUnknown_203B3FC->mh.m.input, TRUE) != FALSE))
    {
        sub_803B204();
        sub_803B284();
        return 1;
    }
    else
        return 0;
}

s16 sub_803B168(void)
{
    return gUnknown_203B3FC->unkA0[GET_CURRENT_MENU_ENTRY(gUnknown_203B3FC->mh.m.input)];
}

void sub_803B18C(u8 r0) 
{
    gUnknown_203B3FC->mh.m.input.totalEntriesCount = 0xE5;
    MenuUpdatePagesData(&gUnknown_203B3FC->mh.m.input);
    sub_803B204();
    sub_803B284();

    if(r0)
        AddMenuCursorSprite(&gUnknown_203B3FC->mh.m.input);
}

void sub_803B1BC(void)
{
    if(gUnknown_203B3FC)
    {
        gUnknown_203B3FC->mh.m.windows.id[gUnknown_203B3FC->mh.m.menuWinId] = gUnknown_80E7F3C;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B3FC->mh.m.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B3FC);
        gUnknown_203B3FC = NULL;
    }
}

void sub_803B204(void) 
{
    gUnknown_203B3FC->mh.header.count = 1;
    gUnknown_203B3FC->mh.header.currId = 0;
    gUnknown_203B3FC->mh.header.width = 8;
    gUnknown_203B3FC->mh.header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B3FC->mh.m.windows, TRUE, TRUE);
    UPDATE_MENU_WINDOW_HEIGHT(gUnknown_203B3FC->mh.m);
}

extern u8 gUnknown_80E7F6C[];

void sub_803B284(void) 
{
    s32 x, y, i;
    s32 pageNum;
    const ScriptRef *ptr;
    
    CallPrepareTextbox_8008C54(gUnknown_203B3FC->mh.m.menuWinId);
    sub_80073B8(gUnknown_203B3FC->mh.m.menuWinId);
    PrintStringOnWindow(0xA, 0, gUnknown_80E7F6C, gUnknown_203B3FC->mh.m.menuWinId, 0);
    
    x = (gUnknown_203B3FC->mh.header.width * 8) - 2;
    pageNum = gUnknown_203B3FC->mh.m.input.currPage + 1;
    PrintNumOnWindow(x, 0, pageNum, 2, 7, gUnknown_203B3FC->mh.m.menuWinId);
   
    // This line has no real effect. It's a magic 'fakematch' to fool agb into generating the same asm. It can be removed if you don't care about matching.
    if (x) { i = 0; }
    
    for (i = 0; i < gUnknown_203B3FC->mh.m.input.currPageEntries; i++) {
        ptr = &gFunctionScriptTable[gUnknown_203B3FC->unkA0[(gUnknown_203B3FC->mh.m.input.currPage * gUnknown_203B3FC->mh.m.input.entriesPerPage) + i]];
        y = GetMenuEntryYCoord(&gUnknown_203B3FC->mh.m.input, i);
        PrintStringOnWindow(8, y, ptr->name, gUnknown_203B3FC->mh.m.menuWinId, 0);
    }
    
    sub_80073E0(gUnknown_203B3FC->mh.m.menuWinId);
}
