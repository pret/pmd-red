// platform/pc/video_pc.c — 240x160 framebuffer backend (SDL optional).
//
// Stage 1 (this file): software framebuffer `gPc_Frame` (32-bit RGBA) fed from
// the palette shadow (gPc_Pltt, 15-bit BGR) + a test pattern; present via SDL
// when compiled with -DHAVE_SDL2, otherwise headless with PPM dumps.
// Stage 2: full tile compositor reading BGxCNT/HOFS/VOFS, VRAM char/screen
// blocks, OAM sprite list, WIN/BLD shadows (see docs/PC_PORT_INVENTORY.md).
#include <stdio.h>
#include <string.h>

#include "gba/gba.h"
#include "gba_shim.h"

#define PC_W 240
#define PC_H 160

static unsigned int gPc_Frame[PC_W * PC_H];
static int gPc_Scale = 3;
static unsigned gPc_FrameNo = 0;

#ifdef HAVE_SDL2
#include <SDL2/SDL.h>
static SDL_Window *sWin;
static SDL_Renderer *sRen;
static SDL_Texture *sTex;
#endif

static unsigned int Bgr555ToRgba(unsigned short c) {
    unsigned r = (c & 0x1F) * 255u / 31u;
    unsigned g = ((c >> 5) & 0x1F) * 255u / 31u;
    unsigned b = ((c >> 10) & 0x1F) * 255u / 31u;
    return (0xFFu << 24) | (b << 16) | (g << 8) | r;
}

void Pc_VideoInit(int scale) {
    gPc_Scale = (scale > 0) ? scale : 3;
    gPc_FrameNo = 0;
    memset(gPc_Frame, 0, sizeof(gPc_Frame));
#ifdef HAVE_SDL2
    SDL_Init(SDL_INIT_VIDEO);
    SDL_RenderSetLogicalSize(sRen, PC_W, PC_H);
    sWin = SDL_CreateWindow("pmd-red-pc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            PC_W * gPc_Scale, PC_H * gPc_Scale, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    sRen = SDL_CreateRenderer(sWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(sRen, PC_W, PC_H);
    sTex = SDL_CreateTexture(sRen, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, PC_W, PC_H);
#endif
}

// Stage-1 composite: clear to backdrop color (palette[0]) + draw a palette
// test strip so headless dumps prove the PLTT shadow path works end to end.
void Pc_VideoPresent(void) {
    unsigned short *pltt = (unsigned short *)gPc_Pltt;
    unsigned int bg = Bgr555ToRgba(pltt[0]);
    unsigned x, y;
    for (y = 0; y < PC_H; y++)
        for (x = 0; x < PC_W; x++)
            gPc_Frame[y * PC_W + x] = bg;
    // 16-entry palette strip along the bottom using BG palette entries 0..15.
    for (x = 0; x < PC_W; x++) {
        unsigned idx = (x * 16u) / PC_W;
        unsigned int c = Bgr555ToRgba(pltt[idx & 15u]);
        for (y = PC_H - 12; y < PC_H; y++)
            gPc_Frame[y * PC_W + x] = c;
    }
    gPc_FrameNo++;
#ifdef HAVE_SDL2
    if (sTex != NULL) {
        SDL_UpdateTexture(sTex, NULL, gPc_Frame, PC_W * (int)sizeof(gPc_Frame[0]));
        SDL_RenderClear(sRen);
        SDL_RenderCopy(sRen, sTex, NULL, NULL);
        SDL_RenderPresent(sRen);
    }
#endif
}

void Pc_VideoShutdown(void) {
#ifdef HAVE_SDL2
    if (sTex != NULL) SDL_DestroyTexture(sTex);
    if (sRen != NULL) SDL_DestroyRenderer(sRen);
    if (sWin != NULL) SDL_DestroyWindow(sWin);
    SDL_Quit();
    sTex = NULL; sRen = NULL; sWin = NULL;
#endif
}

void Pc_VideoDumpPPM(const char *path) {
    FILE *f = fopen(path, "wb");
    unsigned x, y;
    if (f == NULL)
        return;
    fprintf(f, "P6\n%d %d\n255\n", PC_W, PC_H);
    for (y = 0; y < PC_H; y++)
        for (x = 0; x < PC_W; x++) {
            unsigned int c = gPc_Frame[y * PC_W + x];
            unsigned char px[3];
            px[0] = (unsigned char)(c & 0xFF);
            px[1] = (unsigned char)((c >> 8) & 0xFF);
            px[2] = (unsigned char)((c >> 16) & 0xFF);
            fwrite(px, 1, 3, f);
        }
    fclose(f);
}
