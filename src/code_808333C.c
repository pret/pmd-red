#include "global.h"
#include "structs/str_dungeon.h"

struct unkStruct_202ED28
{
    SpriteOAM sp;
    s16 unk8;
    s16 unkA;
};

struct unkStruct_202ED28 gUnknown_202ED28[4]; // seeing index 3 used a lot

bool8 sub_8083568(s32 inX, s32 inY, u8 index) {
    s32 x;
    s32 y;
    SpriteOAM *sp;
    s32 tmp2;
#ifdef NONMATCHING
    s32 tmp;
#else
    register s32 tmp asm("r2");
#endif

    x = inX - gDungeon->cameraPixelPos.x;
    y = inY - gDungeon->cameraPixelPos.y;

    if (x >= -16 && y >= -16 && x <= 255 && y <= 175)
    {
        struct unkStruct_202ED28 *ptr = gUnknown_202ED28;
        sp = &ptr[index].sp;

        tmp = ptr[index].unk8;
        tmp = x + ptr[index].unk8;
        tmp &= SPRITEOAM_MASK_X;

        x = sp->attrib2;
        tmp2 = (0xFE00);
        tmp2 &= x;
        tmp2 |= tmp;
        sp->attrib2 = tmp2;

        tmp = ptr[index].unkA;
        tmp = y + ptr[index].unkA;
        tmp &= SPRITEOAM_MAX_UNK6_4;
        tmp <<= SPRITEOAM_SHIFT_UNK6_4;

        x = sp->unk6;
        tmp2 = 0xF;
        tmp2 &= x;
        tmp2 |= tmp;
        sp->unk6 = tmp2;


        AddSprite(sp, 0, NULL, NULL);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
