// platform/pc/input_pc.c — keyboard/gamepad backend (headless-safe stub).
//
// PC mapping (final, when HAVE_SDL2): SDL scancodes/gamepad -> active-low
// REG_KEYINPUT bits using the A_BUTTON/B_BUTTON/SELECT/START/DPAD_*/L/R_BUTTON
// masks from include/gba/io_reg.h. Until then the shadow stays idle so game
// boot code waiting on key input keeps its GBA timing behavior.
#include "gba/gba.h"
#include "gba_shim.h"

void Pc_InputInit(void) {
    gPcRegs.KEYINPUT = KEYS_MASK; // all released
    gPcRegs.KEYCNT = 0;
}

void Pc_InputPump(void) {
#ifdef HAVE_SDL2
    // TODO: SDL_PollEvent -> clear bits in gPcRegs.KEYINPUT for pressed keys.
    // Kept idle until the SDL event map lands so this file links headless too.
#endif
}

void Pc_InputShutdown(void) {}
