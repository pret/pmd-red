// platform/pc/input_pc.c — keyboard/mouse backend.
//
// Maps host inputs to the active-low REG_KEYINPUT shadow bits the game reads via
// ReadKeyInput (code_800C9CC.c: `REG_KEYINPUT ^ KEYS_MASK` -> pressed set).
// Bindings come from pmd-red.ini (see config_pc.c): every action supports any
// number of keys and/or mouse buttons. Defaults are arrows+WASD to move, Z/
// Space/mouse-left = A, X/mouse-right = B, Enter = Start, RShift = Select,
// Q = L, E = R.
//
// Uses SDL_GetKeyboardState for held-state each pump + one SDL_PollEvent pass
// so window close can end the game loop (Pc_QuitRequested). Esc is reserved for
// the UI (cancel a bind capture), not for quitting.
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

void Pc_RequestQuit(void) {
    gPcQuit = 1;
}

#ifdef HAVE_SDL2

// KEYINPUT bit cleared when the action is held (active-low).
static const u16 sActionBits[PC_ACT_COUNT] = {
    DPAD_UP, DPAD_DOWN, DPAD_LEFT, DPAD_RIGHT,
    A_BUTTON, B_BUTTON, START_BUTTON, SELECT_BUTTON, L_BUTTON, R_BUTTON
};

static int Pc_ActionHeld(int action, const Uint8 *ks, Uint32 mouseState)
{
    const PcActionBinds *ab = &Pc_ConfigBinds()[action];
    int i;
    for (i = 0; i < ab->count; i++) {
        int code = ab->binds[i].code;
        if (ab->binds[i].kind == 0 && code >= 0 && code < SDL_NUM_SCANCODES &&
            ks[code])
            return 1;
        if (ab->binds[i].kind == 1 && (mouseState & SDL_BUTTON(code)))
            return 1;
    }
    return 0;
}

#endif

void Pc_InputPump(void) {
    // KEYINPUT is active-low: start all-released and clear a bit per held key.
    u16 keys = KEYS_MASK;

#ifdef HAVE_SDL2
    {
        const Uint8 *ks = SDL_GetKeyboardState(NULL);
        Uint32 mouseState = SDL_GetMouseState(NULL, NULL);
        SDL_Event ev;
        int i;

        // Handle window close / quit requests.
        while (SDL_PollEvent(&ev)) {
            Pc_UiProcessEvent(&ev); // F1 menu toggle + ImGui event feeding
            if (ev.type == SDL_QUIT) {
                gPcQuit = 1;
            }
        }

        for (i = 0; i < PC_ACT_COUNT; i++)
            if (Pc_ActionHeld(i, ks, mouseState))
                keys &= ~sActionBits[i];

        // While the ImGui menu/settings are up, don't feed game input at all
        // (e.g. so clicking UI doesn't also press A/B in-game).
        if (Pc_UiWantsCaptureInput())
            keys = KEYS_MASK;

        (void)mouseState;
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