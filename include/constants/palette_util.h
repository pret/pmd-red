#ifndef GUARD_CONSTANTS_PALETTE_UTIL_H
#define GUARD_CONSTANTS_PALETTE_UTIL_H

enum PaletteUtilUnk0Kind
{
    // None?
    PALUTIL_KIND_00,
    // Blend Pals [0, 15] then [16, 31]
    PALUTIL_KIND_01,
    // FadeToBlack Pals [0, 15] then [16, 31]
    PALUTIL_KIND_02,
    // Desaturate Pals [0, 15] then [16, 31]
    PALUTIL_KIND_03,
    // Modulate Pals [0, 15] then [16, 31]
    PALUTIL_KIND_04,
    // Blend Pals [0, 13] then [16, 30]
    PALUTIL_KIND_05,
    // FadeToBlack Pals [0, 13] then [16, 30]
    PALUTIL_KIND_06,
    // Desaturate Pals [0, 13] then [16, 30]
    PALUTIL_KIND_07,
    // Modulate Pals [0, 13] then [16, 30]
    PALUTIL_KIND_08,
    // Blend Pals [14, 15] then [31, 31]
    PALUTIL_KIND_09,
    // FadeToBlack Pals [14, 15] then [31, 31]
    PALUTIL_KIND_10,
    // Desaturate Pals [14, 15] then [31, 31]
    PALUTIL_KIND_11,
    // Modulate Pals [14, 15] then [31, 31]
    PALUTIL_KIND_12,
    // ModulatePurple Pals [0, 13] then [16, 30]
    PALUTIL_KIND_13,
    // ModulateOrange Pals [0, 13] then [16, 30]
    PALUTIL_KIND_14,
};

#endif // GUARD_CONSTANTS_PALETTE_UTIL_H
