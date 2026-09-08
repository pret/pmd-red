// platform/pc/input_pc.c — keyboard backend.
//
// Maps host keys to the active-low REG_KEYINPUT shadow bits the game reads via
// ReadKeyInput (code_800C9CC.c: `REG_KEYINPUT ^ KEYS_MASK` -> pressed set).
// Uses SDL_GetKeyboardState for held-state each pump + one SDL_PollEvent pass
// so window close (and Esc) can end the game loop (Pc_QuitRequested). The
// layout mirrors typical GBA emulator binds:
//   Z / Space = A        X = B        Enter = Start    RShift = Select
//   Arrows = D-Pad       A = L        S = R
#include "gba/gba.h"
#include "gba_shim.h"

#ifdef HAVE_SDL2
#include <SDL2/SDL.h>
#endif

volatile int gPcQuit = 0;

// Optional scripted key hold for CI/smoke runs: while the paced-vblank frame
// counter is in [start, start+dur) the given keys are treated as held, which
// on the title allows a menu selection without a real keyboard.
static int sAutoStart = -1;
static int sAutoDur = 0;
static u16 sAutoKeys = 0;

void Pc_SetAutopress(int startFrame, int durFrames, u16 keys)
{
    sAutoStart = startFrame;
    sAutoDur = durFrames < 1 ? 1 : durFrames;
    sAutoKeys = keys;
}

void Pc_InputInit(void) {
    gPcRegs.KEYINPUT = KEYS_MASK; // all released
    gPcRegs.KEYCNT = 0;
    gPcQuit = 0;
}

int Pc_QuitRequested(void) {
    return gPcQuit;
}

void Pc_InputPump(void) {
    // KEYINPUT is active-low: start all-released and clear a bit per held key.
    u16 keys = KEYS_MASK;

#ifdef HAVE_SDL2
    {
        const Uint8 *ks = SDL_GetKeyboardState(NULL);
        SDL_Event ev;
        int i;

        // Handle window close / quit requests and keyboard-released events.
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) {
                gPcQuit = 1;
            } else if (ev.type == SDL_KEYDOWN && ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                gPcQuit = 1;
            }
        }

        if (ks[SDL_SCANCODE_Z] || ks[SDL_SCANCODE_SPACE]) keys &= ~A_BUTTON;
        if (ks[SDL_SCANCODE_X]) keys &= ~B_BUTTON;
        if (ks[SDL_SCANCODE_RSHIFT]) keys &= ~SELECT_BUTTON;
        if (ks[SDL_SCANCODE_RETURN] || ks[SDL_SCANCODE_KP_ENTER]) keys &= ~START_BUTTON;
        if (ks[SDL_SCANCODE_RIGHT]) keys &= ~DPAD_RIGHT;
        if (ks[SDL_SCANCODE_LEFT]) keys &= ~DPAD_LEFT;
        if (ks[SDL_SCANCODE_UP]) keys &= ~DPAD_UP;
        if (ks[SDL_SCANCODE_DOWN]) keys &= ~DPAD_DOWN;
        if (ks[SDL_SCANCODE_A]) keys &= ~L_BUTTON;
        if (ks[SDL_SCANCODE_S]) keys &= ~R_BUTTON;

        (void)i; // reserved for a later gamepad pass
    }
#endif

    // Scripted auto-hold (active-low: clearing a bit = pressing that key).
    if (sAutoStart >= 0) {
        int cur = (int)Pc_VBlankFrameCount();
        if (cur >= sAutoStart && cur < sAutoStart + sAutoDur)
            keys &= ~sAutoKeys;
    }

    gPcRegs.KEYINPUT = keys;
}

void Pc_InputShutdown(void) {}