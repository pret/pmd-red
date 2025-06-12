#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "structs/struct_sub80095e4.h"
#include "music_util.h"
#include "code_80958E8.h"
#include "code_80A26CC.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"

struct unkStruct_203B314
{
    // size: 0x15C
    s16 unk0[2];
    u8 fill4[0x5C - 0x4];
    u8 unk5C[2];
    u8 fill5E[0x8A - 0x5E];
    u8 unk8A[2];
    u8 unk8C[0xB8 - 0x8C];
    u8 unkB8;
    u8 unkB9;
    u8 unkBA;
    u8 unkBB;
    struct struct_Sub80095E4_2 sBC;
};

EWRAM_INIT struct unkStruct_203B314 *gUnknown_203B314 = {NULL};

const WindowTemplate gUnknown_80E06FC = {
    0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const WindowTemplate gUnknown_80E0714 = {
    0x00,
    0x06,
    0x02, 0x02,
    0x0E, 0x0E,
    0x0E, 0x00,
    NULL
};
const WindowTemplate gUnknown_80E072C = {
    0x00,
    0x06,
    0x02, 0x02,
    0x10, 0x10,
    0x10, 0x00,
    NULL
};

ALIGNED(4) const u8 gUnknown_80E0744[] = "Dungeons";
ALIGNED(4) const u8 gUnknown_80E0750[] =  {0x83, 0xC2};
ALIGNED(4) const u8 gUnknown_80E0754[] = {0x83, 0xC0};

void sub_802F9C0(void);
void sub_802FA50(void);
const u8 *sub_80974A0(s16 index);
extern bool8 sub_802FCF0(void);
s32 sub_802FBF4(void);
extern u8 sub_8097384(s16);

u32 sub_802F73C(u32 r0, DungeonPos *r1, u32 r2, u8 r3)
{
    if (sub_802FCF0())
        return 0;

    if (gUnknown_203B314 == NULL)
        gUnknown_203B314 = MemoryAlloc(sizeof(struct unkStruct_203B314), 8);

    gUnknown_203B314->unkB8 = r3;
    gUnknown_203B314->sBC.s0.winId = r0;
    gUnknown_203B314->sBC.s0.unk38 = &gUnknown_203B314->sBC.s0.windows.id[gUnknown_203B314->sBC.s0.winId];
    RestoreSavedWindows(&gUnknown_203B314->sBC.s0.windows);

    if (r3 != 0)
        gUnknown_203B314->sBC.s0.windows.id[gUnknown_203B314->sBC.s0.winId] = gUnknown_80E072C;
    else
        gUnknown_203B314->sBC.s0.windows.id[gUnknown_203B314->sBC.s0.winId] = gUnknown_80E0714;

    gUnknown_203B314->sBC.s0.unk38->header = &gUnknown_203B314->sBC.header;

    if (r1 != 0)
        gUnknown_203B314->sBC.s0.windows.id[gUnknown_203B314->sBC.s0.winId].pos = *r1;

    sub_8012D08(gUnknown_203B314->sBC.s0.unk38, r2);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B314->sBC.s0.windows, TRUE, TRUE);
    CreateMenuOnWindow(&gUnknown_203B314->sBC.s0.input, sub_802FBF4(), r2, r0);
    sub_802F9C0();
    sub_802FA50();
    return 1;
}

u32 sub_802F848(s16 param_1)
{
    int index;
    s32 param_1_32;

    param_1_32 = param_1; // cast needed

    for( index = 0; index < gUnknown_203B314->sBC.s0.input.totalEntriesCount; index++ ) {
        if (gUnknown_203B314->unk0[index] == param_1_32) {
            sub_8013878(&gUnknown_203B314->sBC.s0.input,index);
            sub_802F9C0();
            sub_802FA50();
            return 1;
        }
    }
    sub_8013878(&gUnknown_203B314->sBC.s0.input,0);
    return 0;
}

u32 sub_802F8A0(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B314->sBC.s0.input);
        return 0;
    }
    else
    {
        switch(GetKeyPress(&gUnknown_203B314->sBC.s0.input))
        {
            case INPUT_B_BUTTON:
                PlayMenuSoundEffect(1);
                return 2;
            case INPUT_A_BUTTON:
                PlayMenuSoundEffect(0);
                return 3;
            default:
                if(sub_80138B8(&gUnknown_203B314->sBC.s0.input, 1) != 0)
                {
                    sub_802F9C0();
                    sub_802FA50();
                    return 1;
                }
                else
                {
                    return 0;
                }
        }
    }
}

s16 sub_802F90C(void)
{
    return gUnknown_203B314->unk0[(gUnknown_203B314->sBC.s0.input.currPage * gUnknown_203B314->sBC.s0.input.entriesPerPage) + gUnknown_203B314->sBC.s0.input.menuIndex];
}

void sub_802F938(u8 r0)
{
    gUnknown_203B314->sBC.s0.input.totalEntriesCount = sub_802FBF4();
    sub_8013984(&gUnknown_203B314->sBC.s0.input);
    sub_802F9C0();
    sub_802FA50();

    if(r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B314->sBC.s0.input);
}

void sub_802F974(void)
{
    if(gUnknown_203B314 != NULL)
    {
        gUnknown_203B314->sBC.s0.windows.id[gUnknown_203B314->sBC.s0.winId] = gUnknown_80E06FC;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B314->sBC.s0.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B314);
        gUnknown_203B314 = NULL;
    }
}

void sub_802F9C0(void)
{
    gUnknown_203B314->sBC.header.count = 1;
    gUnknown_203B314->sBC.header.currId = 0;
    gUnknown_203B314->sBC.header.width = 8;
    gUnknown_203B314->sBC.header.f3 = 0;

    SUB_80095E4_CALL(gUnknown_203B314->sBC.s0);
}

void sub_802FA50(void)
{
  s32 sVar1;
  const u8 *text;
  u32 y;
  u32 y2;
  int index;
  int counter;

  CallPrepareTextbox_8008C54(gUnknown_203B314->sBC.s0.winId);
  sub_80073B8(gUnknown_203B314->sBC.s0.winId);
  PrintStringOnWindow(10,0,gUnknown_80E0744,gUnknown_203B314->sBC.s0.winId,0);
  sub_8012BC4(gUnknown_203B314->sBC.header.width * 8 + 4,0,gUnknown_203B314->sBC.s0.input.currPage + 1,2,7,gUnknown_203B314->sBC.s0.winId);
  if (gUnknown_203B314->unkB8 != 0) {
    for(counter = 0; counter < gUnknown_203B314->sBC.s0.input.unk1A; counter++)
    {
        y = GetMenuEntryYCoord(&gUnknown_203B314->sBC.s0.input,counter);
        index = gUnknown_203B314->sBC.s0.input.currPage * gUnknown_203B314->sBC.s0.input.entriesPerPage + counter;
        sVar1 = gUnknown_203B314->unk0[index];
        if (gUnknown_203B314->unk5C[index] != 0) {
            PrintStringOnWindow(10,y,gUnknown_80E0750,gUnknown_203B314->sBC.s0.winId,0);
        }
        else if (gUnknown_203B314->unk8A[index] != 0) {
            PrintStringOnWindow(10,y,gUnknown_80E0754,gUnknown_203B314->sBC.s0.winId,0);
        }
        PrintStringOnWindow(0x18,y,sub_80974A0(sVar1),gUnknown_203B314->sBC.s0.winId,0);
    }
  }
  else {
    for(counter = 0; counter < gUnknown_203B314->sBC.s0.input.unk1A; counter++)
    {
        y2 = GetMenuEntryYCoord(&gUnknown_203B314->sBC.s0.input,counter);
        text = sub_80974A0(gUnknown_203B314->unk0[gUnknown_203B314->sBC.s0.input.currPage * gUnknown_203B314->sBC.s0.input.entriesPerPage + counter]);
        PrintStringOnWindow(8,y2,text,gUnknown_203B314->sBC.s0.winId,0);
    }
  }
  sub_80073E0(gUnknown_203B314->sBC.s0.winId);
}

static inline void sub_802FBF4_sub(u8 *test, s32 counter)
{
    test[counter] = 0;
}

s32 sub_802FBF4(void)
{
    bool8 bVar1;
    u32 dungeonIndex;
    s32 iVar6;
    s32 counter;
    s32 index;

    counter = 0;
    for(index = 0; index  < 0x2E; index++)
    {
        iVar6 = iVar6 = (s16)index; // NOTE: LOLOL
        if (((sub_80A27CC(index) != 0) && (iVar6 != 0x13)) && (iVar6 != 0x1d)) {
            gUnknown_203B314->unk0[counter] = iVar6;
            sub_802FBF4_sub(gUnknown_203B314->unk5C, counter);
            sub_802FBF4_sub(gUnknown_203B314->unk8A, counter);
            if ((gUnknown_203B314->unkB8 != 0) && (iVar6 != 0xd)) {
                dungeonIndex = sub_80A270C(index);
                bVar1 = FALSE;
                if (0x1e >= iVar6)
                {
                    if (sub_8097384(iVar6) == 0) {
                        if (iVar6 == 6) {
                            if (sub_8097384(0x13) != 0) {
                                gUnknown_203B314->unk0[counter] = 0x13;
                                bVar1 = TRUE;
                            }
                        }
                        else if ((iVar6 == 10) && (sub_8097384(0x1d) != 0)) {
                            gUnknown_203B314->unk0[counter] = 0x1d;
                            bVar1 = TRUE;
                        }
                    }
                    else {
                        bVar1 = TRUE;
                    }
                }
                gUnknown_203B314->unk5C[counter] = bVar1;
                if ((!bVar1) && (0 < CountJobsinDungeon(dungeonIndex))) {
                    gUnknown_203B314->unk8A[counter] = 1;
                }
            }
            counter++;
        }
    }
    return counter;
}

bool8 sub_802FCF0(void)
{
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sub_80A27CC(i))
            return FALSE;
    }

    return TRUE;
}

