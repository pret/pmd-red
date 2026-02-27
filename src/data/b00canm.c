#include "global.h"
#include "decompress_sir.h"
#include "code_8004AA0.h"

const AnimatedColorData *const gUnknown_83B22DC[];
const SiroArchive gUnknown_83B1CCC = { "SIRO", &gUnknown_83B22DC };

const AnimatedColorData gUnknown_83B1CDC = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_0.pmdpal") } };
const AnimatedColorData gUnknown_83B1D08 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_1.pmdpal") } };
const AnimatedColorData gUnknown_83B1D34 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_2.pmdpal") } };
const AnimatedColorData gUnknown_83B1D60 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_3.pmdpal") } };
const AnimatedColorData gUnknown_83B1D8C = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_4.pmdpal") } };
const AnimatedColorData gUnknown_83B1DB8 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_5.pmdpal") } };
const AnimatedColorData gUnknown_83B1DE4 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_6.pmdpal") } };
const AnimatedColorData gUnknown_83B1E10 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_7.pmdpal") } };
const AnimatedColorData gUnknown_83B1E3C = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_8.pmdpal") } };
const AnimatedColorData gUnknown_83B1E68 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_9.pmdpal") } };
const AnimatedColorData gUnknown_83B1E94 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_10.pmdpal") } };
const AnimatedColorData gUnknown_83B1EC0 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_11.pmdpal") } };
const AnimatedColorData gUnknown_83B1EEC = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_12.pmdpal") } };
const AnimatedColorData gUnknown_83B1F18 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_13.pmdpal") } };
const AnimatedColorData gUnknown_83B1F44 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_14.pmdpal") } };
const AnimatedColorData gUnknown_83B1F70 = { 10, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_15.pmdpal") } };
const AnimatedColorData gUnknown_83B1F9C = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_16.pmdpal") } };
const AnimatedColorData gUnknown_83B1FD0 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_17.pmdpal") } };
const AnimatedColorData gUnknown_83B2004 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_18.pmdpal") } };
const AnimatedColorData gUnknown_83B2038 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_19.pmdpal") } };
const AnimatedColorData gUnknown_83B206C = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_20.pmdpal") } };
const AnimatedColorData gUnknown_83B20A0 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_21.pmdpal") } };
const AnimatedColorData gUnknown_83B20D4 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_22.pmdpal") } };
const AnimatedColorData gUnknown_83B2108 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_23.pmdpal") } };
const AnimatedColorData gUnknown_83B213C = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_24.pmdpal") } };
const AnimatedColorData gUnknown_83B2170 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_25.pmdpal") } };
const AnimatedColorData gUnknown_83B21A4 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_26.pmdpal") } };
const AnimatedColorData gUnknown_83B21D8 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_27.pmdpal") } };
const AnimatedColorData gUnknown_83B220C = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_28.pmdpal") } };
const AnimatedColorData gUnknown_83B2240 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_29.pmdpal") } };
const AnimatedColorData gUnknown_83B2274 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_30.pmdpal") } };
const AnimatedColorData gUnknown_83B22A8 = { 12, 4, { INCBIN_RGB("graphics/dungeon/b00canm/animated_color_31.pmdpal") } };

const AnimatedColorData *const gUnknown_83B22DC[] = {
    &gUnknown_83B1CDC,
    &gUnknown_83B1D08,
    &gUnknown_83B1D34,
    &gUnknown_83B1D60,
    &gUnknown_83B1D8C,
    &gUnknown_83B1DB8,
    &gUnknown_83B1DE4,
    &gUnknown_83B1E10,
    &gUnknown_83B1E3C,
    &gUnknown_83B1E68,
    &gUnknown_83B1E94,
    &gUnknown_83B1EC0,
    &gUnknown_83B1EEC,
    &gUnknown_83B1F18,
    &gUnknown_83B1F44,
    &gUnknown_83B1F70,
    &gUnknown_83B1F9C,
    &gUnknown_83B1FD0,
    &gUnknown_83B2004,
    &gUnknown_83B2038,
    &gUnknown_83B206C,
    &gUnknown_83B20A0,
    &gUnknown_83B20D4,
    &gUnknown_83B2108,
    &gUnknown_83B213C,
    &gUnknown_83B2170,
    &gUnknown_83B21A4,
    &gUnknown_83B21D8,
    &gUnknown_83B220C,
    &gUnknown_83B2240,
    &gUnknown_83B2274,
    &gUnknown_83B22A8,
};
