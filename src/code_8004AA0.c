#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"

void nullsub_6(void)
{
}

void ReadAnimatedColorData(AnimatedColor *destColors, OpenedFile *file, s32 numColors)
{
    AnimatedColorData **data;
    AnimatedColorData *colorData;
    s32 i;

    data = (AnimatedColorData **)file->data;
    for (i = 0; i < numColors; i++) {
        colorData = *data++;

        if (colorData->colorCount != 0) {
            destColors->flags = 0x80000000;
            destColors->timer = colorData->duration;
            destColors->duration = colorData->duration;
            destColors->colorsStart = colorData->colors;
            destColors->currentColor = colorData->colors;
            destColors->colorsEnd = &colorData->colors[colorData->colorCount];
            destColors->color = colorData->colors[0];
        }
        else
            destColors->flags = 0;

        destColors++;
    }
}

bool8 UpdateAnimatedColors(bool8 forcePaletteUpdate, AnimatedColor *animatedColors, s32 index, s32 numAnimatedColors, s32 brightness, const RGB_Struct *ramp)
{
    bool8 update;
    bool8 ret;
    s32 i;

    ret = FALSE;

    for (i = 0; i < numAnimatedColors; i++, animatedColors++, index++) {
        if (!sub_8004D14(animatedColors, 1) || sub_8004D40(animatedColors, 1))
            continue;

        update = forcePaletteUpdate;
        animatedColors->timer--;

        if (animatedColors->timer <= 0) {
            animatedColors->timer = animatedColors->duration;
            if (animatedColors->currentColor >= animatedColors->colorsEnd)
                animatedColors->currentColor = animatedColors->colorsStart;

            animatedColors->color = *animatedColors->currentColor++;
            update = TRUE;
            ret = TRUE;
        }

        if (update)
            SetBGPaletteBufferColorRGB(index, &animatedColors->color, brightness, ramp);
    }

    return ret;
}

UNUSED static bool8 sub_8004B78(bool8 forcePaletteUpdate, AnimatedColor *animatedColors, s32 index, s32 numAnimatedColors, s32 brightness, const RGB_Struct *ramp)
{
    bool8 update;
    bool8 ret;
    s32 i;

    ret = FALSE;

    for (i = 0; i < numAnimatedColors; i++, animatedColors++, index++) {
        if (!sub_8004D14(animatedColors, 1) || sub_8004D40(animatedColors, 1))
            continue;

        update = forcePaletteUpdate;
        animatedColors->timer--;

        if (animatedColors->timer <= 0) {
            animatedColors->timer = animatedColors->duration;
            if (animatedColors->currentColor >= animatedColors->colorsEnd)
                animatedColors->currentColor = animatedColors->colorsStart;

            animatedColors->color = *animatedColors->currentColor++;
            update = TRUE;
            ret = TRUE;
        }

        if (update)
            nullsub_4(index, &animatedColors->color, brightness, ramp);
    }

    return ret;
}

bool8 sub_8004C00(AnimatedColor *animatedColors, s32 index, s32 numAnimatedColors, s32 brightness, const RGB_Struct *ramp, RGB_Struct16 *a5)
{
    bool8 ret;
    s32 i;
    s32 r;
    s32 g;
    s32 b;
    RGB_Struct color;

    ret = FALSE;

    for (i = 0; i < numAnimatedColors; i++, animatedColors++, index++) {
        if (!sub_8004D14(animatedColors, 1) || sub_8004D40(animatedColors, 1))
            continue;

        animatedColors->timer--;

        if (animatedColors->timer <= 0) {
            animatedColors->timer = animatedColors->duration;
            if (animatedColors->currentColor >= animatedColors->colorsEnd)
                animatedColors->currentColor = animatedColors->colorsStart;

            animatedColors->color = *animatedColors->currentColor++;
            ret = TRUE;
        }

        r = a5->r + animatedColors->color.r;
        g = a5->g + animatedColors->color.g;
        b = a5->b + animatedColors->color.b;

        if (r > 0xFF)
            r = 0xFF;
        if (g > 0xFF)
            g = 0xFF;
        if (b > 0xFF)
            b = 0xFF;
        if (r < 0)
            r = 0;
        if (g < 0)
            g = 0;
        if (b < 0)
            b = 0;

        color.r = r;
        color.g = g;
        color.b = b;

        SetBGPaletteBufferColorRGB(index, &color, brightness, ramp);
    }

    return ret;
}

UNUSED static void sub_8004CFC(AnimatedColor *animatedColors, s32 numAnimatedColors)
{
    s32 i;

    for (i = 0; i < numAnimatedColors; animatedColors++, i++) {
        animatedColors->flags = 0;
    }
}

bool8 sub_8004D14(AnimatedColor *animatedColors, s32 numAnimatedColors)
{
    s32 i;

    for (i = 0; i < numAnimatedColors; i++) {
        if (animatedColors->flags & 0x80000000)
            return TRUE;
        animatedColors++;
    }
    return FALSE;
}

bool8 sub_8004D40(AnimatedColor *animatedColors, s32 numAnimatedColors)
{
    s32 i;

    for (i = 0; i < numAnimatedColors; i++) {
        if (animatedColors->flags & 0x80000000) {
            if (!(animatedColors->flags & 0x20000000))
                return FALSE;
            // BUG: this increment should be in outer scope.
            // if this function is called with numAnimatedColors > 1
            // and first color has flag not set, then
            // this for loop will keep checking the same flags.
            // luckily this function is only used with numAnimatedColors = 1
            animatedColors++;
        }
    }
    return TRUE;
}
