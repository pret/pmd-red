// platform/pc/main_pc.c — native PC entry point.
//
// Mirrors src/main.c:AgbMain() init order minus hardware:
//   AgbMain: WAITCNT, DmaStop x4, EWRAM/IWRAM init-copy, WIN/BLD/BGxCNT/
//   DISPCNT=FORCED_BLANK, sub_800CDA8, sub_800B540 (ISR install), InitFlash,
//   SeedRng, InitSprites, InitInput, InitBGPaletteBuffer, WindowBgBufferInit,
//   InitFileSystem, LoadCharmaps, InitGraphics, SetInterruptCallback(1,VBlank_CB),
//   clear forced blank, GameLoop_Async(), Hang().
//
// PC equivalent here: Pc_MemInit (replaces WAITCNT/DmaStop/mem-init), same
// WIN/BLD/BG shadow defaults as main.c:65-78, backend inits, then a 60Hz frame
// pump (Pc_RequestVBlank -> Pc_VBlankCommit -> Pc_VideoPresent) with a --frames
// smoke mode that dumps build/frame.ppm. GameLoop_Async() plugs into the pump
// once game sources join the host build (see platform/pc/Makefile.pc).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gba/gba.h"
#include "gba_shim.h"
#include "cpu_pc.h"

static void Pc_ApplyBootShadows(void) {
    // Same values as src/main.c:65-78 so later game code sees identical state.
    gPcRegs.WIN0H = 0;
    gPcRegs.WIN1H = 0;
    gPcRegs.WIN0V = 0;
    gPcRegs.WIN1V = 0;
    gPcRegs.WININ = WININ_WIN0_ALL | WININ_WIN1_ALL;
    gPcRegs.WINOUT = WINOUT_WIN01_BG0 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
    gPcRegs.BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD | BLDCNT_TGT2_OBJ;
    gPcRegs.BLDALPHA = BLDALPHA_BLEND(10, 6);
    gPcRegs.BG0CNT = BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_WRAP | BGCNT_SCREENBASE(12);
    gPcRegs.BG1CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_WRAP | BGCNT_SCREENBASE(13);
    gPcRegs.BG2CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_WRAP | BGCNT_SCREENBASE(14);
    gPcRegs.BG3CNT = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(2) | BGCNT_WRAP | BGCNT_SCREENBASE(15);
    gPcRegs.DISPCNT = DISPCNT_WIN1_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP;
}

int main(int argc, char **argv) {
    int scale = 3, frames = 60, i;
    const char *dump = NULL;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--scale") == 0 && i + 1 < argc)
            scale = atoi(argv[++i]);
        else if (strcmp(argv[i], "--frames") == 0 && i + 1 < argc)
            frames = atoi(argv[++i]);
        else if (strcmp(argv[i], "--dump") == 0 && i + 1 < argc)
            dump = argv[++i];
    }

    Pc_MemInit();
    Pc_ApplyBootShadows();
    Pc_VideoInit(scale);
    Pc_InputInit();
    Pc_AudioInit();
    Pc_SaveInit(NULL);

    // Seed a visible palette so the smoke dump proves the PLTT path works.
    {
        unsigned short *pltt = (unsigned short *)gPc_Pltt;
        pltt[0] = RGB2(4, 8, 16); // backdrop
        for (i = 1; i < 16; i++)
            pltt[i] = RGB2((i * 2) & 31, (i * 3) & 31, (i * 4) & 31);
    }

    for (i = 0; i < frames; i++) {
        Pc_InputPump();
        Pc_RequestVBlank();  // host 60Hz tick (replaces VBlank+Timer3 ISRs)
        Pc_VBlankCommit();   // WIN/BLD shadow reload (replaces VBlank_CB DMA)
        Pc_AudioFrame();
        Pc_VideoPresent();   // composite -> SDL texture / headless framebuffer
    }
    if (dump != NULL)
        Pc_VideoDumpPPM(dump);
    Pc_SaveFlush();

    printf("pmd-red-pc: %d frame(s), DISPCNT=0x%04X BLDCNT=0x%04X\n", frames, gPcRegs.DISPCNT, gPcRegs.BLDCNT);

    Pc_AudioShutdown();
    Pc_InputShutdown();
    Pc_VideoShutdown();
    return 0;
}
