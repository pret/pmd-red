// platform/pc/ui_pc.cpp — Dear ImGui overlay for the PC port.
//
// Owns the ImGui context and draws a main menu bar toggled with F1:
//   Game   -> Restart / Settings (ImGui demo window) / Exit
//   Render -> Placeholder
//
// Uses the SDL_Renderer backend (imgui_impl_sdlrenderer2) to match the renderer
// already owned by video_pc.c. video_pc.c blits the 240x160 game frame with an
// explicit scaled rect (no SDL logical-size transform) and calls Pc_UiRender
// right before SDL_RenderPresent, so ImGui draws in window pixels where its
// mouse/hit-testing aligns exactly with the rendered menu.
//
// Compiled as C++ (ImGui is C++); the C callers see the extern "C" API
// declared in gba_shim.h. Restart/quit flags live outside HAVE_SDL2 so the
// rest of the port always links.
#include "gba/types.h" // u8/s32 used by the save API in gba_shim.h
#include "gba_shim.h"

static int gUiRestartRequested = 0;

extern "C" void Pc_RequestRestart(void) {
    gUiRestartRequested = 1;
    Pc_RequestQuit(); // make the game/boot loops unwind so main can re-exec
}

extern "C" int Pc_RestartRequested(void) {
    return gUiRestartRequested;
}

#ifdef HAVE_SDL2

#include <SDL2/SDL.h>

#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_sdlrenderer2.h"

static bool gUiReady = false;
static bool gMenuVisible = false;
static bool gShowDemo = false;

extern "C" void Pc_UiInit(void) {
    SDL_Window *win;
    SDL_Renderer *ren;
    ImGuiIO *io;

    if (gUiReady)
        return;
    win = (SDL_Window *)Pc_VideoGetSdlWindow();
    ren = (SDL_Renderer *)Pc_VideoGetSdlRenderer();
    if (win == NULL || ren == NULL)
        return;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO();
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io->IniFilename = NULL; // don't scatter imgui.ini next to the exe
    ImGui::StyleColorsDark();
    ImGui_ImplSDL2_InitForSDLRenderer(win, ren);
    ImGui_ImplSDLRenderer2_Init(ren);
    gUiReady = true;
}

extern "C" void Pc_UiShutdown(void) {
    if (!gUiReady)
        return;
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    gUiReady = false;
    gMenuVisible = false;
    gShowDemo = false;
}

extern "C" int Pc_UiIsActive(void) {
    return gUiReady ? 1 : 0;
}

extern "C" void Pc_UiProcessEvent(const void *sdlEvent) {
    const SDL_Event *ev = (const SDL_Event *)sdlEvent;
    if (!gUiReady || ev == NULL)
        return;
    if (ev->type == SDL_KEYDOWN && ev->key.repeat == 0 &&
        ev->key.keysym.scancode == SDL_SCANCODE_F1) {
        gMenuVisible = !gMenuVisible;
    }
    ImGui_ImplSDL2_ProcessEvent(ev);
}

extern "C" void Pc_UiToggle(void) {
    gMenuVisible = !gMenuVisible;
}

extern "C" void Pc_UiRender(void) {
    if (!gUiReady)
        return;

    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    if (gMenuVisible && ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Game")) {
            if (ImGui::Selectable("Restart"))
                Pc_RequestRestart();
            if (ImGui::Selectable("Settings"))
                gShowDemo = true;
            if (ImGui::Selectable("Exit"))
                Pc_RequestQuit();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Render")) {
            ImGui::Selectable("Placeholder");
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if (gShowDemo)
        ImGui::ShowDemoWindow(&gShowDemo);

    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(
        ImGui::GetDrawData(), (SDL_Renderer *)Pc_VideoGetSdlRenderer());
}

#else // !HAVE_SDL2 — headless stubs so the C callers always link.

extern "C" void Pc_UiInit(void) {}
extern "C" void Pc_UiShutdown(void) {}
extern "C" int Pc_UiIsActive(void) { return 0; }
extern "C" void Pc_UiProcessEvent(const void *sdlEvent) { (void)sdlEvent; }
extern "C" void Pc_UiToggle(void) {}
extern "C" void Pc_UiRender(void) {}

#endif // HAVE_SDL2
