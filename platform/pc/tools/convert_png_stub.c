// platform/pc/tools/convert_png_stub.c — libpng-free stubs for gbagfx.
//
// Lets us build a working gbagfx (palette/lz/rl/huff/font paths) on machines
// without libpng. PNG-pixel paths abort with an error; palette/asset paths
// used by the PC pipeline work normally. Rebuild full gbagfx once libpng
// exists (INSTALL.md: `brew install libpng`).
#include <stdio.h>
#include <stdlib.h>

#include "gfx.h"
#include "convert_png.h"

void ReadPng(char *path, struct Image *image) {
    (void)path; (void)image;
    fprintf(stderr, "gbagfx-nopng: PNG support needs libpng (see INSTALL.md)\n");
    exit(1);
}

void WritePng(char *path, struct Image *image) {
    (void)path; (void)image;
    fprintf(stderr, "gbagfx-nopng: PNG support needs libpng (see INSTALL.md)\n");
    exit(1);
}

void ReadPngPalette(char *path, struct Palette *palette) {
    (void)path; (void)palette;
    fprintf(stderr, "gbagfx-nopng: PNG support needs libpng (see INSTALL.md)\n");
    exit(1);
}
