#include "global.h"
#include "globaldata.h"
#include "gba_color_util.h"

// Note: All of these functions are unused, because RGBToGbaColor and GbaColorToRGB are only called by unused functions. Could've been used for testing only?

u16 RGBToGbaColor(RGB_Array s)
{
    return ((s.c[RGB_B] & 0xF8) << 7) | ((s.c[RGB_G] & 0xF8) << 2) | ((s.c[RGB_R] & 0xF8) >> 3);
}

RGB_Array GbaColorToRGB(u16 color)
{
    RGB_Array ret;

    ret.c[RGB_R] = (color & 0x1F)      << 3 | ((color & 1)     ? 7 : 0);
    ret.c[RGB_G] = (color & 0x3E0)     >> 2 | ((color & 0x20)  ? 7 : 0);
    ret.c[RGB_B] = (color & 0x7C00)    >> 7 | ((color & 0x400) ? 7 : 0);
    ret.c[RGB_UNK] = 0;
    return ret;
}

UNUSED static void ScaleRGBColor(RGB_Array *dst, s32 factor, RGB_Array *src)
{
    s32 i;

    for (i = 0; i < RGB_FIELDS_COUNT; i++) {
        dst->c[i] = (factor * src->c[i]) / 256;
    }
}

UNUSED static void InterpolateRGBColorGradient(RGB_Array *dst, s32 steps, RGB_Array *start, RGB_Array *end)
{
    s32 i, j;
    float spFloats[4];
    float floatsMul[4];
    float f0 = 1.0f / steps;

    for (i = 0; i < RGB_FIELDS_COUNT; i++) {
        s8 asSigned = (s8) start->c[i];
        float f = (float)(asSigned);
        if (asSigned < 0) {
            f += 256.0f;
        }
        spFloats[i] = f;
        floatsMul[i] = (float)(end->c[i] - start->c[i]) * f0;
    }

    *dst++ = *start;
    for (i = 1; i < steps - 1; dst++, i++) {
        for (j = 0; j < RGB_FIELDS_COUNT; j++) {
            dst->c[j] = (unsigned int)((spFloats[j] += floatsMul[j]));
        }
    }

    *dst = *end;
}
