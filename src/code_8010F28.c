#include "global.h"
#include "sprite.h"
#include "code_8004AA0.h"
#include "input.h"
#include "text.h"
#include "code_8009804.h"
#include "bg_palette_buffer.h"
#include "string_format.h"
#include "code_800D090.h"
#include "friend_area.h"
#include "bg_control.h"
#include "code_800558C.h"
#include "game_options.h"
#include "play_time.h"
#include "code_80118A4.h"
#include "code_800C9CC.h"

extern void sub_800CB20(void);
extern void xxx_call_update_bg_sound_input(void);
extern bool8 sub_800FFE8(u8);
extern void sub_80101F8(u8 *, u8);

EWRAM_INIT struct UnkBgStruct *gUnknown_203B0E4 = NULL;
EWRAM_INIT void *gUnknown_203B0E8 = NULL; // Pointer to some unknown struct
EWRAM_INIT UnkTextStruct2 gUnknown_203B0EC[4] = {
    [0] = {
        .unk4 = 3,
        .pos = {2, 10},
        .unkC = 26,
        .unkE = 9,
        .unk10 = 9,
    },
    [1] = {
        .unk4 = 3,
        .pos = {23, 6},
        .unkC = 5,
        .unkE = 3,
        .unk10 = 3,
    },
    [2] = {
        .unk4 = 3,
    },
    [3] = {
        .unk4 = 3,
    },
};

static inline bool8 CheckAxFlag8000(axdata *ptr)
{
    return (ptr->flags & 0x8000) != 0;
}

static inline bool8 ResetFlags(axdata *ptr)
{
    return ptr->flags = 0;
}

extern const DungeonPos gUnknown_80D40C4[];
extern const u8 gUnknown_80D40FC[];
extern const u8 gUnknown_80D4104[];
extern const u8 gUnknown_80D4120[];
extern const u8 gUnknown_80D4124[];

void sub_8010EF0(void)
{
    CloseFile(gUnknown_203B0E4->unk0[4]);
    CloseFile(gUnknown_203B0E4->unk0[2]);
    CloseFile(gUnknown_203B0E4->unk0[3]);
    CloseFile(gUnknown_203B0E4->unk0[0]);
    CloseFile(gUnknown_203B0E4->unk0[1]);
}

void sub_8010F28(void)
{
    s32 i;
    unkStruct_2039DB0 var_30;
    DungeonPos pos;

    sub_8004E8C(&var_30);
    var_30.unk4 = 0xF3FF;
    var_30.unkA = 0x800;
    pos = gUnknown_203B0E4->unk4DD4;
    RunAxAnimationFrame(&gUnknown_203B0E4->unk4C10);
    DoAxFrame_800558C(&gUnknown_203B0E4->unk4C10, gUnknown_203B0E4->unk4DD8 - pos.x, gUnknown_203B0E4->unk4DDA - pos.y, 3, gUnknown_203B0E4->unk4DD0, &var_30);

    for (i = 0; i < 32; i++) {
        struct UnkStruct_4018 *r0 = &gUnknown_203B0E4->unk4018[i];
        struct UnkStruct_4014Ptr *r5 = &gUnknown_203B0E4->unk4014->array[i];
        if (r0->unk4018 != 0) {
            RunAxAnimationFrame(&r0->unk14);
            DoAxFrame_800558C(&r0->unk14, r5->unk4.x - pos.x, r5->unk4.y- pos.y, 1, 0, &var_30);
        }
    }

{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (CheckAxFlag8000(&gUnknown_203B0E4->unk4A30[i])) {
            RunAxAnimationFrame(&gUnknown_203B0E4->unk4A30[i]);
            if (!(gRealInputs.held & R_BUTTON) || (i % 2) != 0) {
                DoAxFrame_800558C(&gUnknown_203B0E4->unk4A30[i],
                                  (gUnknown_80D40C4[i].x + gUnknown_203B0E4->unk4DD8) - pos.x,
                                  (gUnknown_80D40C4[i].y + gUnknown_203B0E4->unk4DDA) - pos.y,
                                  2, 0, &var_30);
            }
        }
    }
}
}

void sub_80110B0(void)
{
    s32 i, j;
    s32 y1 = gUnknown_203B0E4->unk4DD4.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = gUnknown_203B0E4->unk4DD4.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gUnknown_202B038[2][y1][x1] = gUnknown_203B0E4->unk2014[y2][x2];
            gUnknown_202B038[3][y1][x1] = gUnknown_203B0E4->unk14[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    sub_80098F8(2);
    sub_80098F8(3);
}

void sub_8011168(void)
{
    s32 i;

    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    gUnknown_203B0E4->unk4DDC = 0;
    gUnknown_203B0E4->unk4DE0 = 0;
    gUnknown_203B0E4->unk4DE4 = 0;
    gUnknown_203B0E4->unk4DE8 = 0;
    for (i = 0; i < 8; i++) {
        ResetFlags(&gUnknown_203B0E4->unk4A30[i]);
    }
}

bool8 sub_80111C4(void)
{
    bool8 ret = FALSE;

    if (gUnknown_203B0E4->unk4DCC < 31) {
        s32 i;
        RGB *color = (void *) gUnknown_203B0E4->unk0[0]->data;

        if (++gUnknown_203B0E4->unk4DCC >= 31) {
            gUnknown_203B0E4->unk4DCC = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, gUnknown_203B0E4->unk4DCC, NULL);
        }

        color = (void *) gUnknown_203B0E4->unk0[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, gUnknown_203B0E4->unk4DCC, NULL);
        }

        ret = TRUE;
    }

    return ret;
}

void sub_8011240(void)
{
    if (gUnknown_203B0E4->unk4DD8 - gUnknown_203B0E4->unk4DD4.x < 48) {
        gUnknown_203B0E4->unk4DD4.x = gUnknown_203B0E4->unk4DD8 - 48;
    }
    else if (gUnknown_203B0E4->unk4DD8 - gUnknown_203B0E4->unk4DD4.x > 192) {
        gUnknown_203B0E4->unk4DD4.x = gUnknown_203B0E4->unk4DD8 - 192;
    }

    if (gUnknown_203B0E4->unk4DDA - gUnknown_203B0E4->unk4DD4.y < 48) {
        gUnknown_203B0E4->unk4DD4.y = gUnknown_203B0E4->unk4DDA - 48;
    }
    else if (gUnknown_203B0E4->unk4DDA - gUnknown_203B0E4->unk4DD4.y > 112) {
        gUnknown_203B0E4->unk4DD4.y = gUnknown_203B0E4->unk4DDA - 112;
    }

    if (gUnknown_203B0E4->unk4DD4.x < 0) {
        gUnknown_203B0E4->unk4DD4.x = 0;
    }
    if (gUnknown_203B0E4->unk4DD4.y < 0) {
        gUnknown_203B0E4->unk4DD4.y = 0;
    }
    if (gUnknown_203B0E4->unk4DD4.x > 239) {
        gUnknown_203B0E4->unk4DD4.x = 239;
    }
    if (gUnknown_203B0E4->unk4DD4.y > 151) {
        gUnknown_203B0E4->unk4DD4.y = 151;
    }
}

void sub_8011300(void)
{
    s32 i;
    struct UnkStruct_4018 *r9 = &gUnknown_203B0E4->unk4018[gUnknown_203B0E4->unk4A18];

    for (i = 0; i < 8; i++) {
        ResetFlags(&gUnknown_203B0E4->unk4A30[i]);
        if (r9->unk2[i] >= 0) {
            struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[r9->unk2[i]];
            if (ptr->unk4018 != 0) {
                AxResInitFile(&gUnknown_203B0E4->unk4A30[i], gUnknown_203B0E4->unk0[2], i + 4, 0, 0x40, 0, TRUE);
            }
        }
    }
}

void sub_8011398(void)
{
    u8 txt[200];
    s32 id = gUnknown_203B0E4->unk4A18;
    struct UnkStruct_4014Ptr *r6 = &gUnknown_203B0E4->unk4014->array[id];
    UnkTextStruct3 spTxtStruct = {0};

    spTxtStruct.a0[0].unk4 = 3;
    spTxtStruct.a0[0].pos.x = 7;
    spTxtStruct.a0[0].pos.y = 2;
    spTxtStruct.a0[0].unkC = 21;
    spTxtStruct.a0[0].unkE = 2;
    spTxtStruct.a0[0].unk10 = 2;
    spTxtStruct.a0[1].unk4 = 3;
    spTxtStruct.a0[2].unk4 = 3;
    spTxtStruct.a0[3].unk4 = 3;

    if (gUnknown_203B0E4->unk4DDA - gUnknown_203B0E4->unk4DD4.y <= 80) {
        spTxtStruct.a0[0].pos.y = 17;
    }
    else {
        spTxtStruct.a0[0].pos.y = 1;
    }

    xxx_call_save_unk_text_struct_800641C(&spTxtStruct, TRUE, TRUE);
    sub_80073B8(0);
    sprintfStatic(txt, gUnknown_80D40FC, r6->unk0);
    PrintFormattedStringOnWindow(12, 2, txt, 0, '\0');
    sub_80073E0(0);
    gUnknown_203B0E4->unk4DDC = (spTxtStruct.a0[0].pos.x * 8) - 5;
    gUnknown_203B0E4->unk4DE0 = (spTxtStruct.a0[0].pos.y * 8) + 5;
    gUnknown_203B0E4->unk4DE4 = (spTxtStruct.a0[0].unkC * 8) + 10;
    gUnknown_203B0E4->unk4DE8 = (spTxtStruct.a0[0].unkE * 8) + 10;
}

void sub_8011494(void)
{
    s32 i, count, var;
    s32 id = gUnknown_203B0E4->unk4A18;
    struct UnkStruct_4014Ptr *r8 = &gUnknown_203B0E4->unk4014->array[id];
    MenuInputStruct *menuInput = &gUnknown_203B0E4->unk4DFC;
    UnkTextStruct2_sub2 subTxt;
    UnkTextStruct3 spTxtStruct = {
        .a0 = {
            [0] = {
                .unk4 = 6,
                .pos = {7, 2},
                .unkC = 21,
                .unkE = 2,
                .unk10 = 2,
                .unk14 = &subTxt,
            },
            [1] = {
                .unk4 = 3,
            },
            [2] = {
                .unk4 = 3,
            },
            [3] = {
                .unk4 = 3,
            },
        }
    };

    count = 0;
    for (i = 0; i < 8; i++) {
        if (sub_800FFE8(r8->unk8[i])) {
            gUnknown_203B0E4->unk4DEC[count] = r8->unk8[i];
            count++;
        }
    }

    gUnknown_203B0E4->unk4DF8 = count;
    subTxt.f0 = 1;
    subTxt.f1 = 0;
    subTxt.f2 = 18;
    subTxt.f3 = 0;
    menuInput->menuIndex = 0;
    menuInput->unk1A = count;
    menuInput->unk1C = count;
    menuInput->unk1E = 0;
    menuInput->unk20 = 0;
    menuInput->unk4 = 0;
    menuInput->unk6 = 16;
    menuInput->unk0 = 0;
    menuInput->unkC = 0;
    menuInput->unkE = 0;
    menuInput->unk14.x = 0;
    menuInput->unk14.y = 0;
    menuInput->unk8.x = 8;
    menuInput->unk8.y = 8;
    sub_801317C(&menuInput->unk28);
    var = sub_80095E4(menuInput->unk1C, 0);
    spTxtStruct.a0[0].unk10 = spTxtStruct.a0[0].unkE = var + 2;
    sub_80137B0(menuInput, var * 8);

    xxx_call_save_unk_text_struct_800641C(&spTxtStruct, TRUE, TRUE);

    gUnknown_203B0E4->unk4DDC = 0;
    gUnknown_203B0E4->unk4DE0 = 0;
    gUnknown_203B0E4->unk4DE4 = 0;
    gUnknown_203B0E4->unk4DE8 = 0;
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, gUnknown_80D4104, 0, '\0');

    for (i = 0; i < count; i++) {
        unkStruct_8092638 unkFriendAreaStruct;
        s32 r4 = sub_8013800(menuInput, i);
        u8 r5 = gUnknown_203B0E4->unk4DEC[i];

        sub_80101F8(gFormatBuffer_Items[0], r5);
        if (r5 == 0) {
            PrintFormattedStringOnWindow(12, r4, gUnknown_80D4120, 0, '\0');
        }
        else {
            sub_80926F8(r5, &unkFriendAreaStruct, gUnknown_203B0E4->unk4A2C); // TODO FIX R8
            gFormatArgs[0] = unkFriendAreaStruct.unk2;
            gFormatArgs[1] = unkFriendAreaStruct.numPokemon;
            PrintFormattedStringOnWindow(12, r4, gUnknown_80D4124, 0, '\0');
        }
    }

    sub_80073E0(0);
}

void sub_801169C(void)
{
    SetBG2RegOffsets(gUnknown_203B0E4->unk4DD4.x, gUnknown_203B0E4->unk4DD4.y);
    SetBG3RegOffsets(gUnknown_203B0E4->unk4DD4.x, gUnknown_203B0E4->unk4DD4.y);
    sub_8010F28();
    sub_8004AF0(sub_80111C4(), gUnknown_203B0E4->unk4C4C, 0xB0, 16, gUnknown_203B0E4->unk4DCC, NULL);
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    sub_8011860();
    ResetSprites(FALSE);
}
