#include "global.h"
#include "text.h"
#include "input.h"
#include "memory.h"

struct unkStruct_203B320
{
    // size: 0xC4
    u8 unk0[4];
    u8 fill4[0x20 - 4];
    u32 unk20;
    u8 fill24[0x3C - 0x24];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u8 fill48[0x58 - 0x48];
    u32 unk58;
    struct UnkTextStruct2 *unk5C;
    struct UnkTextStruct2 unk60[4];
    u8 unkC0[4];
};
extern struct unkStruct_203B320 *gUnknown_203B320;
extern struct UnkTextStruct2 gUnknown_80E083C;
extern struct UnkTextStruct2 gUnknown_80E0854;

extern u8 sub_8030C20(u32);
extern s32 sub_8030A74(void);
extern void sub_80308A0(void);
extern void sub_803092C(void);
extern void sub_8012D08(struct UnkTextStruct2 *, s32);
extern void sub_8013818(void *, u32, u32, u32);

extern u8 sub_80138B8(u8 *, u32);
extern void sub_8013660(u8 *);
extern s32 GetKeyPress(u8 *);
extern void PlayMenuSoundEffect(u32);
extern void sub_8013984(u8 *);
extern void AddMenuCursorSprite(u8 *);

u32 sub_80306A8(u32 r0, u32 r1, struct UnkTextStruct2_sub *r2, u32 r3)
{
    if(sub_8030C20(r0))
        return 0;
    gUnknown_203B320 = MemoryAlloc(sizeof(struct unkStruct_203B320), 0x8);
    gUnknown_203B320->unk20 = r0;
    gUnknown_203B320->unk58 = r1;

    gUnknown_203B320->unk5C = &gUnknown_203B320->unk60[gUnknown_203B320->unk58];
    sub_8006518(gUnknown_203B320->unk60);

    gUnknown_203B320->unk60[gUnknown_203B320->unk58] = gUnknown_80E0854;
    gUnknown_203B320->unk5C->unk14 = gUnknown_203B320->unkC0;

    if(r2 != 0)
    {
        gUnknown_203B320->unk60[gUnknown_203B320->unk58].unk08 = *r2;
    }


    sub_8012D08(gUnknown_203B320->unk5C, r3);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B320->unk60, 1, 1);
    sub_8013818(gUnknown_203B320->fill24, sub_8030A74(), r3, r1);
    sub_80308A0();
    sub_803092C();
    return 1;
}

u32 sub_8030768(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(gUnknown_203B320->fill24);
        return 0;
    }
    switch(GetKeyPress(gUnknown_203B320->fill24))
    {
        case 4:
            PlayMenuSoundEffect(4);
            return 4;
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if(sub_80138B8(gUnknown_203B320->fill24, 1) != 0)
            {
                sub_80308A0();
                sub_803092C();
                return 1;
            }
            else
                return 0;
    }
}

u8 sub_80307EC(void)
{
    return gUnknown_203B320->unk0[(gUnknown_203B320->unk42 * gUnknown_203B320->unk40) + gUnknown_203B320->unk3C];
}

void sub_8030810(u32 r0)
{
    u8 r0_u8;

    r0_u8 = r0; // cast needed..

    gUnknown_203B320->unk46 = sub_8030A74();
    sub_8013984(gUnknown_203B320->fill24);

    sub_80308A0();
    sub_803092C();
    if(r0_u8 != 0)
        AddMenuCursorSprite(gUnknown_203B320->fill24);
}

void sub_803084C()
{
    if(gUnknown_203B320 != NULL)
    {
        gUnknown_203B320->unk60[gUnknown_203B320->unk58] = gUnknown_80E083C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B320->unk60, 1, 1);
        MemoryFree(gUnknown_203B320);
        gUnknown_203B320 = NULL;
    }
}

u8 *sub_8030894()
{
    return gUnknown_203B320->unk0;
}
