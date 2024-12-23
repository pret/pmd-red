#include "global.h"
#include "structs/str_dungeon.h"
#include "structs/str_202ED28.h"

bool8 sub_8083568(s32 inX, s32 inY, u8 index)
{
    s32 x = inX - gDungeon->unk181e8.cameraPixelPos.x;
    s32 y = inY - gDungeon->unk181e8.cameraPixelPos.y;

    if (x >= -16 && y >= -16 && x <= 255 && y <= 175)
    {
        SpriteSetX(&gUnknown_202ED28[0][index].sprite, x + gUnknown_202ED28[0][index].x);
        SpriteSetY(&gUnknown_202ED28[0][index].sprite, y + gUnknown_202ED28[0][index].y);

        AddSprite(&gUnknown_202ED28[0][index].sprite, 0, NULL, NULL);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
