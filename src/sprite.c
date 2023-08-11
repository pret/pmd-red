#include "global.h"
#include "sprite.h"

extern struct SpriteList gUnknown_20256A0;
extern struct UnkSpriteLink gUnknown_2025EA8[128];
extern struct UnkSpriteLink gUnknown_20262A8[128];
extern u32 gSpriteCount; /* 20266A8 */
extern u32 gUnknown_20266B0;
extern u32 *gCharMemCursor; /* 2026E30 */
extern u32 *gUnknown_203B074;

void InitSprites(void)
{
    ResetSprites(TRUE);
    SetSavingIconCoords(0);
}

void ResetSprites(bool8 a0)
{
    s32 i;
    struct UnkSpriteLink *a;
    struct UnkSpriteLink *b;
    struct UnkSpriteLink *c;

    gSpriteCount = 0;
    gCharMemCursor = (u32*)0x6010000;
    gUnknown_203B074 = &gUnknown_20266B0;

    a = &gUnknown_20256A0.sprites[0][0];
    b = a + 1;

    // 16 loops, very smart
    for (i = 0; i < 0x100; i += 0x10) {
        c = NULL;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
    }

    if (a0) {
        c = NULL;
        b = &gUnknown_20262A8[0];
        a = &gUnknown_2025EA8[0];
        for (i = 0; i < 128; i++) {
            a->unk0 = c;
            a->unk4 = b;
            b++;
            a++;
        }
    }

    gUnknown_20256A0.unk800 = 0;
    gUnknown_20256A0.unk804 = 0;
}