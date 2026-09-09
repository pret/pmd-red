// platform/pc/video_pc.c — native Mode-0 compositor (SDL optional).
//
// Reads the game-produced display state every frame and renders the 240x160
// internal framebuffer:
//   - 4 text-mode BG layers (all 4bpp, 256x256 maps; per-BG priority/char base/
//     screen base/scroll from the REG_BGxCNT/HOFS/VOFS shadows)
//   - 128 OAM sprites (OBJ_1D_MAP, 4bpp, per-sprite 4-bit palette)
//   - per-scanline WIN0/WIN1 windows from the game's gWinBufferPtr stream
//     (the same data VBlank_CB's HBlank DMA would have fed), WININ/WINOUT
//     layer membership per pixel
//   - BLDCNT/BLDALPHA alpha blending (BG1 dim layer over the scene) and
//     BLDY brightness, all gated by each region's color-effect enable bit.
//
// No emulation: the decompiled game runs natively; this mirrors the GBA's
// display pipeline over the VRAM/PLTT/OAM shadows. Mosaic and affine are not
// used by the game and are intentionally unsupported.
#include <stdio.h>
#include <string.h>

#include "gba/gba.h"
#include "gba_shim.h"
#include "window_buffer.h"

// The game defines these (EWRAM_DATA in src/window_buffer.c). The backend-only
// smoke binary links no game objects, so provide weak defaults here; the
// full-game link overrides them with the real symbols.
__attribute__((weak)) bool8 gDrawWindow = FALSE;
__attribute__((weak)) s16 *gWinBufferPtr = NULL;

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

// Precomputed RGB555 -> RGBA table so the per-pixel color conversion is a
// single indexed load instead of 3 multiplies + shifts. Built lazily once.
static unsigned int gPc_RgbaLut[32768];
static int gPc_RgbaLutReady = 0;

static void Pc_EnsureRgbaLut(void) {
    unsigned i;
    if (gPc_RgbaLutReady)
        return;
    for (i = 0; i < 32768; i++) {
        unsigned r = (i & 0x1F) * 255u / 31u;
        unsigned g = ((i >> 5) & 0x1F) * 255u / 31u;
        unsigned b = ((i >> 10) & 0x1F) * 255u / 31u;
        gPc_RgbaLut[i] = (0xFFu << 24) | (b << 16) | (g << 8) | r;
    }
    gPc_RgbaLutReady = 1;
}

static inline unsigned int Bgr555ToRgba(unsigned short c) {
    return gPc_RgbaLut[c & 0x7FFF];
}

// Blended color result, still in RGB555 space.
static inline unsigned short Pc_BlendRgb555(unsigned short top, unsigned short under,
                                            int eva, int evb, int evy, int bld) {
    if (bld == 1) { // alpha blend
        int tr = top & 0x1F, tg = (top >> 5) & 0x1F, tb = (top >> 10) & 0x1F;
        int ur = under & 0x1F, ug = (under >> 5) & 0x1F, ub = (under >> 10) & 0x1F;
        int nr = (tr * eva + ur * evb) >> 4; if (nr > 31) nr = 31;
        int ng = (tg * eva + ug * evb) >> 4; if (ng > 31) ng = 31;
        int nb = (tb * eva + ub * evb) >> 4; if (nb > 31) nb = 31;
        return (unsigned short)(nr | (ng << 5) | (nb << 10));
    } else if (bld == 2) { // brightness increase
        int tr = top & 0x1F, tg = (top >> 5) & 0x1F, tb = (top >> 10) & 0x1F;
        tr += ((31 - tr) * evy) >> 4;
        tg += ((31 - tg) * evy) >> 4;
        tb += ((31 - tb) * evy) >> 4;
        return (unsigned short)(tr | (tg << 5) | (tb << 10));
    } else if (bld == 3) { // brightness decrease
        int tr = top & 0x1F, tg = (top >> 5) & 0x1F, tb = (top >> 10) & 0x1F;
        tr -= (tr * 16) >> 4;
        tg -= (tg * 16) >> 4;
        tb -= (tb * 16) >> 4;
        return (unsigned short)(tr | (tg << 5) | (tb << 10));
    }
    return top;
}

void Pc_VideoInit(int scale) {
    gPc_Scale = (scale > 0) ? scale : 3;
    gPc_FrameNo = 0;
    memset(gPc_Frame, 0, sizeof(gPc_Frame));
#ifdef HAVE_SDL2
    SDL_Init(SDL_INIT_VIDEO);
    sWin = SDL_CreateWindow("pmd-red-pc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            PC_W * gPc_Scale, PC_H * gPc_Scale, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    sRen = SDL_CreateRenderer(sWin, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(sRen, PC_W, PC_H);
    sTex = SDL_CreateTexture(sRen, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, PC_W, PC_H);
#endif
}

// ---------------- Mode-0 renderer ----------------

// OBJ dimensions: width/height in pixels for (shape<<2 | size).
static const s8 sObjW[12] = {  8, 16, 32, 64,  16, 32, 32, 64,   8,  8, 16, 32 };
static const s8 sObjH[12] = {  8, 16, 32, 64,   8,  8, 16, 32,  16, 32, 32, 64 };

enum {
    REGION_OUTSIDE,
    REGION_WIN0,
    REGION_WIN1,
    REGION_OBJ,
};

// Window membership, matching GBATEK WINxH semantics:
//   high byte = X1 (left), low byte = X2 (right, +1).
//   X1==X2 -> disabled; X1<X2 -> [X1,X2); X1>X2 -> wraps (x>=X1 || x<X2)
//   (the game stores exactly this layout, e.g. corridor-dim holes).
static int Pc_InWin(int x, s16 v) {
    int x1 = (v >> 8) & 0xFF;
    int x2 = v & 0xFF;
    if (x1 == x2)
        return 0;
    if (x1 < x2)
        return (x >= x1) && (x < x2);
    return (x >= x1) || (x < x2);
}

// Fetch one BG text-mode pixel. Returns 0 (transparent) or palette index used.
// Writes *palOut = index into the 512-entry PLTT array.
static unsigned Pc_BgPixel(const u8 *vram, int charBase, int bpp8,
                           int screenBase, int hofs, int vofs, int x, int y,
                           unsigned *palOut) {
    // 256x256 map; text BGs wrap at 256 (other text sizes unused by game).
    int sx = ((x + hofs) & 0xFF);
    int sy = ((y + vofs) & 0xFF);

    // Map entry (2 bytes) at screenBase*0x800.
    int cell = ((sy >> 3) & 31) * 32 + ((sx >> 3) & 31);
    const u16 *map = (const u16 *)(vram + screenBase * 0x800);
    u16 entry = map[cell];

    int tileId = entry & 0x3FF;
    int flipH = (entry >> 10) & 1;
    int flipV = (entry >> 11) & 1;
    int palBank = (entry >> 12) & 0xF;

    int px = (sx & 7);
    int py = (sy & 7);
    if (flipH) px = 7 - px;
    if (flipV) py = 7 - py;

    if (bpp8) {
        const u8 *tile = vram + charBase * 0x4000 + tileId * 64 + py * 8;
        unsigned c = tile[px];
        if (c == 0)
            return 0;
        *palOut = c;
        return c;
    } else {
        const u8 *tile = vram + charBase * 0x4000 + tileId * 32 + py * 4;
        unsigned nib = (px & 1) ? (tile[px >> 1] >> 4) : (tile[px >> 1] & 0xF);
        if (nib == 0)
            return 0;
        *palOut = palBank * 16 + nib;
        return nib;
    }
}

// Fetch one OAM sprite pixel (1D mapping, 4bpp). Returns 0 if transparent.
static unsigned Pc_ObjPixel(const u8 *vram, const struct OamData *o,
                            int ox, int oy, int w, int h,
                            int pdx, int pdy, unsigned *palOut) {
    (void)ox;
    (void)oy;
    int flipH = (o->matrixNum >> 3) & 1; // attr1 bit 12 (matrixNum bit 3)
    int flipV = (o->matrixNum >> 4) & 1; // attr1 bit 13 (matrixNum bit 4)
    if (flipH) pdx = w - 1 - pdx;
    if (flipV) pdy = h - 1 - pdy;

    int tilesW = w >> 3;
    int tile = (pdy >> 3) * tilesW + (pdx >> 3);
    int tileNo = (o->tileNum + tile) & 0x3FF;
    int px7 = pdx & 7, py7 = pdy & 7;
    if (o->bpp) { // 8bpp: each tile takes two 32-byte tile slots
        tileNo = (o->tileNum + tile * 2) & 0x3FF;
        const u8 *t = vram + 0x10000 + tileNo * 64 + py7 * 8;
        unsigned c = t[px7];
        if (c == 0)
            return 0;
        *palOut = 0x100 + c;
        return c;
    } else {
        const u8 *t = vram + 0x10000 + tileNo * 32 + py7 * 4;
        unsigned nib = (px7 & 1) ? (t[px7 >> 1] >> 4) : (t[px7 >> 1] & 0xF);
        if (nib == 0)
            return 0;
        *palOut = 0x100 + o->paletteNum * 16 + nib;
        return nib;
    }
}

// Per-scanline active-OAM record (indices into the OAM table that touch the
// current row). Built once per scanline so the per-pixel OBJ work never
// scans all 128 sprites. 128 covers the whole table.
struct Pc_ActiveSprite {
    int idx;   // OAM index
    int prio;  // o->priority
    int w, h;  // dimensions
    int ox, oy;// x/y
};

// Composite one full frame from the shadows into gPc_Frame.
static void Pc_RenderFrame(void) {
    const u8 *vram = gPc_Vram;
    const u16 *pltt = (const u16 *)gPc_Pltt;
    const struct OamData *oam = (const struct OamData *)gPc_Oam;
    unsigned short disp = gPcRegs.DISPCNT;
    const u16 bgCnt[4] = { gPcRegs.BG0CNT, gPcRegs.BG1CNT,
                           gPcRegs.BG2CNT, gPcRegs.BG3CNT };
    const u16 bgHofs[4] = { gPcRegs.BG0HOFS, gPcRegs.BG1HOFS,
                            gPcRegs.BG2HOFS, gPcRegs.BG3HOFS };
    const u16 bgVofs[4] = { gPcRegs.BG0VOFS, gPcRegs.BG1VOFS,
                            gPcRegs.BG2VOFS, gPcRegs.BG3VOFS };
    const int win0On = (disp & DISPCNT_WIN0_ON) != 0;
    const int win1On = (disp & DISPCNT_WIN1_ON) != 0;
    const int objWinOn = (disp & DISPCNT_OBJWIN_ON) != 0;
    const int winAny = (disp & (DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON)) != 0;
    const unsigned short winin = gPcRegs.WININ;
    const unsigned short winout = gPcRegs.WINOUT;
    const unsigned short bldcnt = gPcRegs.BLDCNT;
    const unsigned short bldalpha = gPcRegs.BLDALPHA;
    const unsigned short bldy = gPcRegs.BLDY;
    const int bldEffect = (bldcnt >> 6) & 3;
    const int eva = (bldalpha & 0x1F) > 16 ? 16 : (bldalpha & 0x1F);
    const int evb = ((bldalpha >> 8) & 0x1F) > 16 ? 16 : ((bldalpha >> 8) & 0x1F);
    const int evy = (bldy & 0x1F) > 16 ? 16 : (bldy & 0x1F);
    const int objOn = (disp & DISPCNT_OBJ_ON) != 0;
    // BG layer on/off + a compact per-priority BG list built once.
    int bgOn[4], bgPrio[4];
    int prioBg[4][4]; // prioBg[p] = list of BG indexes at priority p
    int prioBgN[4] = { 0, 0, 0, 0 };
    int dispBg[4] = { DISPCNT_BG0_ON, DISPCNT_BG1_ON, DISPCNT_BG2_ON, DISPCNT_BG3_ON };
    int p, i, y, x;

    Pc_EnsureRgbaLut();

    for (i = 0; i < 4; i++) {
        bgOn[i] = (disp & dispBg[i]) != 0;
        bgPrio[i] = bgCnt[i] & 3;
    }

    if (disp & DISPCNT_FORCED_BLANK) {
        // Forced blank displays white lines.
        for (y = 0; y < PC_H; y++) {
            unsigned int *row = gPc_Frame + y * PC_W;
            for (x = 0; x < PC_W; x++)
                row[x] = 0xFFFFFFFFu;
        }
        return;
    }

    for (y = 0; y < PC_H; y++) {
        unsigned int *row = gPc_Frame + y * PC_W;
        const s16 *win = gWinBufferPtr; // sBuffer pairs: [WIN0H,WN1H] per line
        s16 w0v = 0, w1v = 0;
        if (win != NULL && gDrawWindow) {
            w0v = win[y * 2];
            w1v = win[y * 2 + 1];
        }

        // Build the per-row active-sprite list once.
        struct Pc_ActiveSprite act[128];
        int nAct = 0;
        if (objOn) {
            int s;
            for (s = 0; s < 128; s++) {
                const struct OamData *o = &oam[s];
                int w, h, ox, oy;
                if (o->objMode == 2 || (int)o->y >= PC_H)
                    continue;
                w = sObjW[(o->shape << 2) | o->size];
                h = sObjH[(o->shape << 2) | o->size];
                ox = o->x; oy = o->y;
                if (y < oy || y >= oy + h)
                    continue;
                act[nAct].idx = s;
                act[nAct].prio = o->priority;
                act[nAct].w = w;
                act[nAct].h = h;
                act[nAct].ox = ox;
                act[nAct].oy = oy;
                nAct++;
            }
        }

        // For each priority (0 = front, drawn last), which BGs are present.
        for (p = 0; p < 4; p++)
            prioBgN[p] = 0;
        for (i = 0; i < 4; i++)
            if (bgOn[i])
                prioBg[bgPrio[i]][prioBgN[bgPrio[i]]++] = i;

        for (x = 0; x < PC_W; x++) {
            int region = REGION_OUTSIDE;
            int layerBits, effectOn;
            unsigned int rgba;

            if (winAny) {
                if (win0On && Pc_InWin(x, w0v))
                    region = REGION_WIN0;
                else if (win1On && Pc_InWin(x, w1v))
                    region = REGION_WIN1;
                else if (objWinOn && region == REGION_OUTSIDE) {
                    // OBJ window: covered by any objMode==2 opaque pixel.
                    int s;
                    for (s = 0; s < nAct; s++) {
                        const struct OamData *o = &oam[act[s].idx];
                        unsigned pal;
                        if (o->objMode != 2)
                            continue;
                        if (x < act[s].ox || x >= act[s].ox + act[s].w)
                            continue;
                        if (Pc_ObjPixel(vram, o, act[s].ox, act[s].oy, act[s].w,
                                        act[s].h, x - act[s].ox, y - act[s].oy, &pal)) {
                            region = REGION_OBJ;
                            break;
                        }
                    }
                }

                if (region == REGION_WIN0) {
                    layerBits = winin & 0x3F;
                    effectOn = (winin >> 5) & 1;
                } else if (region == REGION_WIN1) {
                    layerBits = (winin >> 8) & 0x3F;
                    effectOn = (winin >> 13) & 1;
                } else if (region == REGION_OBJ) {
                    layerBits = (winout >> 8) & 0x3F;
                    effectOn = (winout >> 13) & 1;
                } else {
                    layerBits = winout & 0x3F;
                    effectOn = (winout >> 5) & 1;
                }
            } else {
                // No windows: layers gated by DISPCNT only.
                layerBits = ((disp & DISPCNT_BG0_ON) ? 1 : 0)
                          | ((disp & DISPCNT_BG1_ON) ? 2 : 0)
                          | ((disp & DISPCNT_BG2_ON) ? 4 : 0)
                          | ((disp & DISPCNT_BG3_ON) ? 8 : 0)
                          | (objOn ? 16 : 0);
                effectOn = 1;
            }

            // Composite back-to-front (priority 3..0; within a priority OBJ
            // draws on top). `top` ends as the frontmost opaque color and
            // `under` as the layer directly below it, matching the GBA's
            // alpha-blend second target. Uses the per-priority BG lists and
            // the per-row active-sprite list so we never re-scan 128 OAM.
            unsigned top = pltt[0];   // backdrop
            unsigned under = pltt[0]; // 2nd target candidate (layer below top)
            int topLayer = -1;        // drawn layer id: 0-3 BG, 4 OBJ
            int objSemi = 0;

            for (p = 3; p >= 0; p--) {
                int nb = prioBgN[p];
                // BGs at this priority (lowest index wins when overlapping).
                int bi;
                for (bi = 0; bi < nb; bi++) {
                    unsigned pal;
                    i = prioBg[p][bi];
                    if (!(layerBits & (1 << i)))
                        continue;
                    if (Pc_BgPixel(vram, (bgCnt[i] >> 2) & 3, (bgCnt[i] >> 7) & 1,
                                   (bgCnt[i] >> 8) & 0x1F, bgHofs[i], bgVofs[i],
                                   x, y, &pal)) {
                        under = (topLayer < 0) ? pltt[0] : top; // layer below
                        top = pltt[pal];
                        topLayer = i;
                        objSemi = 0;
                    }
                }
                // OBJ at this priority: top-most opaque pixel. Among
                // overlapping sprites the lower OAM index is drawn on top
                // (OBJ0 over OBJ1-127), matching the GBA hardware.
                if ((layerBits & 16) && objOn) {
                    const struct OamData *winO = NULL;
                    int winIdx = 128;
                    int s;
                    for (s = 0; s < nAct; s++) {
                        unsigned pal;
                        if (act[s].prio != p)
                            continue;
                        if (x < act[s].ox || x >= act[s].ox + act[s].w)
                            continue;
                        if (Pc_ObjPixel(vram, &oam[act[s].idx], act[s].ox, act[s].oy,
                                        act[s].w, act[s].h, x - act[s].ox,
                                        y - act[s].oy, &pal)) {
                            if (winO == NULL || act[s].idx < winIdx) {
                                winO = &oam[act[s].idx];
                                winIdx = act[s].idx;
                                under = (topLayer < 0) ? pltt[0] : top;
                                top = pltt[pal];
                                topLayer = 4;
                                objSemi = (oam[act[s].idx].objMode == 1) ? 1 : 0;
                            }
                        }
                    }
                    (void)winO;
                }
            }

            // Fast path: no color effect, or nothing drawn / backdrop only.
            rgba = Bgr555ToRgba((unsigned short)top);
            if (effectOn && bldEffect != 0 && topLayer >= 0) {
                int is1st, is2nd;
                int bld;

                if (topLayer == 4)
                    is1st = objSemi || ((bldcnt >> 4) & 1);
                else
                    is1st = (bldcnt >> topLayer) & 1;

                if (topLayer == 4)
                    is2nd = (bldcnt >> 12) & 1;
                else
                    is2nd = (bldcnt >> (8 + topLayer)) & 1;

                bld = 0;
                if (is1st && is2nd)
                    bld = bldEffect;

                if (bld != 0) {
                    // `under` was only updated when a BG drew a pixel; if the
                    // winning layer is a BG drawn first at its priority, `under`
                    // holds the previous composite (layer below). If it's an OBJ
                    // or the first opaque BG, `under` is the backdrop (correct).
                    unsigned short blended = Pc_BlendRgb555((unsigned short)top,
                                                            (unsigned short)under,
                                                            eva, evb, evy, bld);
                    rgba = Bgr555ToRgba(blended);
                }
            }

            row[x] = rgba;
        }
    }
}

void Pc_VideoPresent(void) {
    Pc_RenderFrame();
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