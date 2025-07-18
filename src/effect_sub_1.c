#include "global.h"
#include "globaldata.h"
#include "effect_sub_1.h"
#include "effect_sub_2.h"
#include "bg_control.h"
#include "structs/axdata.h"
#include "graphics_memory.h"
#include "code_800C9CC.h"
#include "effect_data.h"
#include "code_803E724.h"
#include "dungeon_message.h"
#include "file_system.h"
#include "main_loops.h"
#include "memory.h"
#include "sprite.h"
#include "text_2.h"
#include "effect_anim_file.h"

struct unkStruct_203B0D0_sub
{
    // size: 0x24
    u32 unk0;
    OpenedFile *file;
    const EfoFileData *fileData;
    u32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    const RGB *ramp;
};

struct unkStruct_203B0D0 {
    // size: 0x4C
    u32 unk0;
    struct unkStruct_203B0D0_sub unk4[2];
};

static EWRAM_INIT struct unkStruct_203B0D0 *gUnknown_203B0D0 = NULL;

extern void sub_809971C(u16 a0, const RGB *a1, int a2);

void sub_800ED38(s32 r0)
{
    if (gUnknown_203B0D0 == NULL) {
        gUnknown_203B0D0 = MemoryAlloc(sizeof(struct unkStruct_203B0D0), 0xB);
        MemoryClear8(gUnknown_203B0D0, sizeof(struct unkStruct_203B0D0));
    }
    gUnknown_203B0D0->unk0 = r0;
}

void sub_800ED64(void)
{
    TRY_FREE_AND_SET_NULL(gUnknown_203B0D0);
}

void sub_800ED80(void)
{
    s32 index;

    gUnknown_203B0D0->unk0 = 0;
    for (index = 0; index < 2; index++) {
        struct unkStruct_203B0D0_sub *sub = &gUnknown_203B0D0->unk4[index];

        sub->unk0 = 0;
        sub->file = NULL;
        sub->fileData = NULL;
    }
}

static bool8 sub_800EDB0(struct unkStruct_203B0D0_sub *r0)
{
    s32 index;

    for (index = 0; index < 2; index++) {
        if (gUnknown_203B0D0->unk4[index].unk0 == 0) {
            gUnknown_203B0D0->unk4[index] = *r0;
            return TRUE;
        }
    }
    return FALSE;
}

static void sub_800EDF0(u32 r0, OpenedFile *file)
{
    struct unkStruct_203B0D0_sub stack;

    switch (r0) {
        case 0:
            stack.unk0 = 3;
            stack.unkC = 0xE;
            stack.unk10 = -1;
            stack.unk18 = 0x370;
            stack.unk1C = 0x1F;
            stack.unk14 = -1;
            stack.file = file;
            break;
        case 1:
            stack.unk0 = 4;
            stack.unkC = 0xE;
            stack.unk10 = 0xF00;
            stack.unk18 = -1;
            stack.unk1C = -1;
            stack.unk14 = (sub_8000728() != 2) ? 2 : 0;
            stack.file = file;
            break;
    }
    stack.fileData = (void *) file->data;
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
        else if(ret2 != -2) {
            sub_800F13C(ret2, file, ret);
            sub_800EDF0(ret2, file);
        }
        else {
            CloseEffectFile(file);
        }
        sub_800F15C(ret->effectId);
    }
}

void sub_800EEC8(u16 r0)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk0);
}

void sub_800EEE0(u16 r0)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk4);
}

void sub_800EEF8(u16 r0)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk2);
}

void sub_800EF10(u16 r0)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk6);
}

void sub_800EF28(u8 r0)
{
    sub_800EE5C(sub_800ECE4(r0));
}

void sub_800EF40(u8 r0, bool8 r1)
{
    s32 ret;
    if (r1) {
        ret = sub_800ECF8(r0);
    }
    else {
        ret = sub_800ED0C(r0);
    }
    sub_800EE5C(ret);
}

void sub_800EF64(void)
{
    s32 i;
    struct unkStruct_203B0D0_sub *sub;

    for (i = 0; i < 2; i++) {
        if (gUnknown_203B0D0->unk4[i].unk0 == 0)
            continue;

        sub = &gUnknown_203B0D0->unk4[i];
        switch (sub->unk0) {
            case 1:
            case 2:
                 break;
            case 3:
                sub_8005674(sub->fileData, sub->unk18);
                switch (gUnknown_203B0D0->unk0) {
                    case 1: {
                        const RGB *pal = sub->fileData->pal;
                        sub_809971C((sub->unkC + 16) * 16, pal, 0x10);
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
                if (sub_8000728() == 1) {
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
