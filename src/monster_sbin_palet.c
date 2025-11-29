#include "global.h"
#include "structs/rgb.h"

// These correspond to the 'overworldPalette' field in the monster data. Only slots 0-12 are actually used, slot 13 seems to be a placeholder.
const RGB_Struct gAxMonsPalette[] = {
    INCBIN_RGB("graphics/ax/pal/0.pmdpal",
               "graphics/ax/pal/1.pmdpal",
               "graphics/ax/pal/2.pmdpal",
               "graphics/ax/pal/3.pmdpal",
               "graphics/ax/pal/4.pmdpal",
               "graphics/ax/pal/5.pmdpal",
               "graphics/ax/pal/6.pmdpal",
               "graphics/ax/pal/7.pmdpal",
               "graphics/ax/pal/8.pmdpal",
               "graphics/ax/pal/9.pmdpal",
               "graphics/ax/pal/10.pmdpal",
               "graphics/ax/pal/11.pmdpal",
               "graphics/ax/pal/12.pmdpal",
               "graphics/ax/pal/13.pmdpal")
};
