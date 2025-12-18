#include "global.h"
#include "globaldata.h"
#include "bg_control.h"
#include "code_800C9CC.h"
#include "code_8099360.h"
#include "dungeon_message.h"
#include "dungeon_vram.h"
#include "effect_anim_file.h"
#include "effect_data.h"
#include "effect_sub_1.h"
#include "effect_sub_2.h"
#include "graphics_memory.h"
#include "main_loops.h"
#include "memory.h"
#include "sprite.h"
#include "text_2.h"

#define NUM_SUBS 2

// Size: 0x24
typedef struct EffectSub1Work_sub
{
    /* 0x00 */ u32 unk0;
    /* 0x04 */ OpenedFile *file;
    /* 0x08 */ const EfoFileData *fileData;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ const RGB_Struct *ramp;
} EffectSub1Work_sub;

// Size: 0x4C
typedef struct EffectSub1Work
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ EffectSub1Work_sub unk4[NUM_SUBS];
} EffectSub1Work;

static EWRAM_INIT EffectSub1Work *sWork = NULL;

void sub_800ED38(s32 r0)
{
    if (sWork == NULL) {
        sWork = MemoryAlloc(sizeof(EffectSub1Work), MEMALLOC_GROUP_11);
        MemoryClear8(sWork, sizeof(EffectSub1Work));
    }
    sWork->unk0 = r0;
}

void sub_800ED64(void)
{
    TRY_FREE_AND_SET_NULL(sWork);
}

void sub_800ED80(void)
{
    s32 i;

    sWork->unk0 = 0;

    for (i = 0; i < NUM_SUBS; i++) {
        EffectSub1Work_sub *sub = &sWork->unk4[i];

        sub->unk0 = 0;
        sub->file = NULL;
        sub->fileData = NULL;
    }
}

static bool8 sub_800EDB0(EffectSub1Work_sub *dst)
{
    s32 i;

    for (i = 0; i < NUM_SUBS; i++) {
        if (sWork->unk4[i].unk0 == 0) {
            sWork->unk4[i] = *dst;
            return TRUE;
        }
    }

    return FALSE;
}

static void sub_800EDF0(u32 r0, OpenedFile *file)
{
    EffectSub1Work_sub stack;

    switch (r0) {
        case 0: {
            stack.unk0 = 3;
            stack.unkC = 0xE;
            stack.unk10 = -1;
            stack.unk18 = 0x370;
            stack.unk1C = 0x1F;
            stack.unk14 = -1;
            stack.file = file;
            break;
        }
        case 1: {
            stack.unk0 = 4;
            stack.unkC = 0xE;
            stack.unk10 = 0xF00;
            stack.unk18 = -1;
            stack.unk1C = -1;
            stack.unk14 = (GetMainLoopsUnk() != MAINLOOPS_UNK_2) ? 2 : 0;
            stack.file = file;
            break;
        }
    }

    stack.fileData = (void *)file->data;
    stack.ramp = NULL;
    sub_800EDB0(&stack);
}

void sub_800EE5C(s32 r0)
{
    OpenedFile *file;
    const unkStruct_80B9CC4 *ret = sub_800ECA4(r0);

    if (r0 == 0)
        return;
    if (ret->animType == 1 || ret->animType == 2)
        return;

    file = OpenEffectFile(ret->animType, ret->effectId);
    if (file != NULL) {
        s32 ret2 = sub_800F0F4(ret->animType, ret->effectId);
        if (ret2 == -1) {
            CloseEffectFile(file);
            return;
        }

        if (ret2 != -2) {
            sub_800F13C(ret2, file, ret);
            sub_800EDF0(ret2, file);
        }
        else {
            CloseEffectFile(file);
        }

        sub_800F15C(ret->effectId);
    }
}

void sub_800EEC8(u16 moveID)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(moveID);
    sub_800EE5C(ret->unk0);
}

void sub_800EEE0(u16 moveID)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(moveID);
    sub_800EE5C(ret->unk4);
}

void sub_800EEF8(u16 moveID)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(moveID);
    sub_800EE5C(ret->unk2);
}

void sub_800EF10(u16 moveID)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(moveID);
    sub_800EE5C(ret->unk6);
}

void sub_800EF28(u8 trapID)
{
    sub_800EE5C(GetTrapEffect(trapID));
}

void sub_800EF40(u8 itemID, bool8 r1)
{
    s32 ret;

    if (r1)
        ret = sub_800ECF8(itemID);
    else
        ret = sub_800ED0C(itemID);

    sub_800EE5C(ret);
}

void sub_800EF64(void)
{
    s32 i;
    EffectSub1Work_sub *sub;

    for (i = 0; i < NUM_SUBS; i++) {
        if (sWork->unk4[i].unk0 == 0)
            continue;

        sub = &sWork->unk4[i];
        switch (sub->unk0) {
            case 1:
            case 2:
                 break;
            case 3:
                sub_8005674(sub->fileData, sub->unk18);
                switch (sWork->unk0) {
                    case 1: {
                        const RGB_Struct *pal = sub->fileData->pal;
                        sub_809971C((sub->unkC + 16) * 16, (RGB_Array*)pal, 0x10);
                        break;
                    }
                    case 0: {
                        sub_8005770(sub->unkC, sub->fileData->pal, sub->unk1C, sub->ramp);
                        break;
                    }
                }
                if(sub->file != 0) {
                    CloseEffectFile(sub->file);
                    sub->file = NULL;
                }
                break;
            case 4:
                if (GetMainLoopsUnk() == MAINLOOPS_UNK_1) {
                    sub_800CD64(0, TRUE);
                    sub_8052210(0);
                    sub_803EAF0(5, NULL);
                    WaitForNextFrameAndAdvanceRNG();
                    xxx_call_update_bg_vram();
                }
                sub_8009A1C(sub->fileData, sub->unkC, sub->unk10, sub->unk14);
                if(sub->file != NULL) {
                    CloseEffectFile(sub->file);
                    sub->file = NULL;
                }
                break;
        }
        sub->unk0 = 0;
    }
}
