#include "global.h"
#include "file_system.h"
#include "memory.h"
#include "code_800E9E4.h"
#include "dungeon_pokemon_sprites.h"
#include "sprite.h"

struct unkStruct_203B0D0_sub
{
    // size: 0x24
    u32 unk0;
    struct unkStruct_203B0D0_sub *unk4;
    struct unkStruct_203B0D0_sub *unk8;
    u32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u32 unk20;
};

struct unkStruct_203B0D0 {
    // size: 0x4C
    u32 unk0;
    struct unkStruct_203B0D0_sub unk4[2];
};

EWRAM_INIT struct unkStruct_203B0D0 *gUnknown_203B0D0 = NULL;
EWRAM_INIT void *gUnknown_203B0D4 = NULL; // TODO: figure out the actual struct
EWRAM_INIT DungeonPokemonSprites *gDungeonPokemonSprites = NULL; // Todo: move to a different file, or merge files in this rom region
EWRAM_INIT SpriteOAM gUnknown_203B0DC = {0};

extern s32 sub_8000728();
OpenedFile *sub_800F1C0(s32, s32);
s32 sub_800F0F4(s32, s32);
void sub_800F204(OpenedFile *file);
void sub_800F13C(s32, OpenedFile *, unkStruct_80B9CC4 *);
void sub_800F15C(s32);

void sub_800ED38(s32 r0)
{
    if(gUnknown_203B0D0 == 0)
    {
        gUnknown_203B0D0 = MemoryAlloc(sizeof(struct unkStruct_203B0D0), 0xB);
        MemoryClear8(gUnknown_203B0D0, sizeof(struct unkStruct_203B0D0));
    }
    gUnknown_203B0D0->unk0 = r0;
}

void sub_800ED64(void)
{
    if(gUnknown_203B0D0)
    {
        MemoryFree(gUnknown_203B0D0);
        gUnknown_203B0D0 = NULL;
    }
}

void sub_800ED80(void)
{
    s32 index;
    struct unkStruct_203B0D0_sub *sub;

    gUnknown_203B0D0->unk0 = 0;
    for(index = 0; index < 2; index++)
    {
        sub = &gUnknown_203B0D0->unk4[index];
        sub->unk0 = 0;
        sub->unk4 = 0;
        sub->unk8 = 0;
    }
}

bool8 sub_800EDB0(struct unkStruct_203B0D0_sub *r0)
{
    s32 index;

    for(index = 0; index < 2; index++)
    {
        if(gUnknown_203B0D0->unk4[index].unk0 == 0)
        {
            gUnknown_203B0D0->unk4[index] = *r0;
            return TRUE;
        }
    }
    return FALSE;
}

void sub_800EDF0(u32 r0, struct unkStruct_203B0D0_sub *r1) {
    struct unkStruct_203B0D0_sub stack;
    s32 uVar1;

    switch(r0)
    {
        case 0:
            stack.unk0 = 3;
            stack.unkC = 0xE;
            stack.unk10 = -1;
            stack.unk18 = 0xDC << 2;
            stack.unk1C = 0x1F;
            stack.unk14  = -1;
            stack.unk4 = r1;
            break;
        case 1:
            stack.unk0 = 4;
            stack.unkC = 0xE;
            stack.unk10 = 0xF0 << 4;
            stack.unk18 = -1;
            stack.unk1C = -1;

            // TODO: what math op is this again?
            uVar1 = sub_8000728();
            stack.unk14 = (((int)(-(uVar1 ^ 2) | (uVar1 ^ 2)) >> 0x1f) & 2);
            stack.unk4 = r1;
            break;
    }
    stack.unk8 = r1->unk4;
    stack.unk20 = 0;
    sub_800EDB0(&stack);
}

void sub_800EE5C(s32 r0)
{
    unkStruct_80B9CC4 *ret;
    OpenedFile *file;
    s32 ret2;

    ret = sub_800ECA4(r0);
    if(r0 != 0)
    {
        switch (ret->animType - 1) {
        case 1 - 1:
        case 2 - 1:
            return;
        default:
            file = sub_800F1C0(ret->animType, ret->effectId);
            if(file)
            {
                ret2 = sub_800F0F4(ret->animType, ret->effectId);
                if(ret2 == -1)
                {
                    sub_800F204(file);
                    return;
                }
                else if(ret2 != -2)
                {
                    sub_800F13C(ret2, file, ret);
                    sub_800EDF0(ret2, (void *)file);
                }
                else {
                    sub_800F204(file);
                }
                sub_800F15C(ret->effectId);
            }
        }
    }
}

void sub_800EEC8(u16 r0)
{
    unkStruct_80BDBC4 *ret;
    ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk0);
}

void sub_800EEE0(u16 r0)
{
    unkStruct_80BDBC4 *ret;
    ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk4);
}

void sub_800EEF8(u16 r0)
{
    unkStruct_80BDBC4 *ret;
    ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk2);
}

void sub_800EF10(u16 r0)
{
    unkStruct_80BDBC4 *ret;
    ret = sub_800ECB8(r0);
    sub_800EE5C(ret->unk6);
}

void sub_800EF28(u8 r0)
{
    sub_800EE5C(sub_800ECE4(r0));
}

void sub_800EF40(u8 r0, u8 r1)
{
    s32 ret;
    if(r1)
    {
        ret = sub_800ECF8(r0);
    }
    else
    {
        ret = sub_800ED0C(r0);
    }
    sub_800EE5C(ret);
}
