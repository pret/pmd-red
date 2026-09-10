// platform/pc/ui_pc.cpp — Dear ImGui overlay for the PC port.
//
// Owns the ImGui context and draws a main menu bar toggled with F1:
//   Game   -> Restart / Settings / Exit
//   Render -> Placeholder
//
// The Settings window is tabbed (Graphics/Audio/Controls/Boot). Controls
// rebind the actions from pmd-red.ini (see config_pc.c) — every action takes
// any number of keys and/or mouse buttons. Boot exposes the launch-arg toggles.
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
#include <cstdio>
#include <cstring>

#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_sdlrenderer2.h"

static bool gUiReady = false;
static bool gMenuVisible = false;
static bool gSettingsOpen = false;
static int  gCaptureAction = -1; // action awaiting a key press, or -1

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
    gSettingsOpen = false;
    gCaptureAction = -1;
}

extern "C" int Pc_UiIsActive(void) {
    return gUiReady ? 1 : 0;
}

extern "C" int Pc_UiWantsCaptureInput(void) {
    // Any visible overlay (menu bar, settings window) or an in-progress bind
    // capture means game input must not reach the GBA shadow.
    return (gMenuVisible || gSettingsOpen || gCaptureAction >= 0) ? 1 : 0;
}

extern "C" void Pc_UiProcessEvent(const void *sdlEvent) {
    const SDL_Event *ev = (const SDL_Event *)sdlEvent;
    if (!gUiReady || ev == NULL)
        return;

    if (ev->type == SDL_KEYDOWN) {
        if (gCaptureAction >= 0) {
            // A bind is pending: the next non-Esc key becomes it.
            if (ev->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                gCaptureAction = -1;
            } else if (ev->key.repeat == 0) {
                Pc_ConfigAddBind(gCaptureAction, 0, (int)ev->key.keysym.scancode);
                Pc_ConfigSave();
                gCaptureAction = -1;
            }
        } else if (ev->key.repeat == 0 &&
                   ev->key.keysym.scancode == SDL_SCANCODE_F1) {
            gMenuVisible = !gMenuVisible;
        }
    }

    ImGui_ImplSDL2_ProcessEvent(ev);
}

extern "C" void Pc_UiToggle(void) {
    gMenuVisible = !gMenuVisible;
}

static void Pc_UiControlsTab(void) {
    int a;

    if (ImGui::Button("Reset to Defaults")) {
        Pc_ConfigResetBinds();
        Pc_ConfigSave();
    }
    ImGui::SameLine();
    ImGui::TextDisabled("Click a bind to remove it; + to add.");

    ImGui::Separator();
    ImGui::BeginChild("controls_list");
    for (a = 0; a < PC_ACT_COUNT; a++) {
        PcActionBinds *ab = &Pc_ConfigBinds()[a];
        char pid[40];
        int i;

        ImGui::TextUnformatted(Pc_ActionName(a));
        ImGui::SameLine();

        for (i = 0; i < ab->count; i++) {
            char label[80];
            char id[96];
            Pc_BindLabel(ab->binds[i].kind, ab->binds[i].code, label, sizeof(label));
            snprintf(id, sizeof(id), "%s##del_%d_%d", label, a, i);
            if (ImGui::SmallButton(id)) {
                Pc_ConfigRemoveBind(a, ab->binds[i].kind, ab->binds[i].code);
                Pc_ConfigSave();
            }
            ImGui::SameLine();
        }

        snprintf(pid, sizeof(pid), "+##add_%d", a);
        if (ImGui::SmallButton(pid))
            ImGui::OpenPopup(pid);
        if (ImGui::BeginPopup(pid)) {
            char mitem[64];
            if (ImGui::MenuItem("Capture next key...")) {
                gCaptureAction = a;
                ImGui::CloseCurrentPopup();
            }
            snprintf(mitem, sizeof(mitem), "Mouse Left");
            if (ImGui::MenuItem(mitem)) { Pc_ConfigAddBind(a, 1, 1); Pc_ConfigSave(); }
            if (ImGui::MenuItem("Mouse Middle")) { Pc_ConfigAddBind(a, 1, 2); Pc_ConfigSave(); }
            if (ImGui::MenuItem("Mouse Right")) { Pc_ConfigAddBind(a, 1, 3); Pc_ConfigSave(); }
            if (ImGui::MenuItem("Mouse X1")) { Pc_ConfigAddBind(a, 1, 4); Pc_ConfigSave(); }
            if (ImGui::MenuItem("Mouse X2")) { Pc_ConfigAddBind(a, 1, 5); Pc_ConfigSave(); }
            ImGui::EndPopup();
        }

        ImGui::NewLine();
    }
    ImGui::EndChild();
}

static void Pc_UiBootTab(void) {
    PcBootPrefs *boot = Pc_ConfigBootPrefs();
    bool b;

    b = boot->noConsole != 0;
    if (ImGui::Checkbox("No console (log to client.log only)", &b)) { boot->noConsole = b ? 1 : 0; Pc_ConfigSave(); }
    b = boot->skipWarning != 0;
    if (ImGui::Checkbox("Skip health & safety warning", &b)) { boot->skipWarning = b ? 1 : 0; Pc_ConfigSave(); }
    b = boot->skipLogos != 0;
    if (ImGui::Checkbox("Skip logos", &b)) { boot->skipLogos = b ? 1 : 0; Pc_ConfigSave(); }
    b = boot->skipIntro != 0;
    if (ImGui::Checkbox("Skip intro / opening", &b)) { boot->skipIntro = b ? 1 : 0; Pc_ConfigSave(); }
    b = boot->autoload != 0;
    if (ImGui::Checkbox("Auto-load save at launch", &b)) { boot->autoload = b ? 1 : 0; Pc_ConfigSave(); }
    b = boot->fpsLog != 0;
    if (ImGui::Checkbox("Log FPS", &b)) { boot->fpsLog = b ? 1 : 0; Pc_ConfigSave(); }

    ImGui::Spacing();
    ImGui::TextDisabled("These mirror launch arguments (e.g. --noconsole, SkipIntro)\nand take effect the next time the game starts (Game > Restart).");
}

static const char *const kPlayerNames[PC_AUDIO_PLAYERS] = {
    "BGM", "Fanfare", "SE1", "SE2", "SE3", "SE4", "SE5", "SE6"
};

// One row per m4a player: tempo (%) and pitch (semitones) sliders.
static void Pc_UiAudioPlayerTable(PcAudioPrefs *ap)
{
    if (ImGui::BeginTable("player_tempo", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
    {
        ImGui::TableSetupColumn("Player", ImGuiTableColumnFlags_WidthFixed, 90.0f);
        ImGui::TableSetupColumn("Tempo", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Pitch", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableHeadersRow();
        for (int i = 0; i < PC_AUDIO_PLAYERS; i++)
        {
            int t = ap->tempoScale[i];
            int p = ap->pitchShift[i];
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            ImGui::TextUnformatted(kPlayerNames[i]);
            ImGui::TableSetColumnIndex(1);
            if (ImGui::SliderInt("##tempo", &t, 50, 200, "%d%%"))
            {
                ap->tempoScale[i] = t;
                Pc_ConfigSave();
            }
            ImGui::TableSetColumnIndex(2);
            if (ImGui::SliderInt("##pitch", &p, -12, 12, "%+d st"))
            {
                ap->pitchShift[i] = p;
                Pc_ConfigSave();
            }
        }
        ImGui::EndTable();
    }
}

static void Pc_UiAudioTab(void) {
    PcAudioPrefs *ap = Pc_ConfigAudioPrefs();
    int v;

    v = ap->masterVolume;
    if (ImGui::SliderInt("Volume", &v, 0, 100, "%d%%")) {
        ap->masterVolume = v;
        Pc_ConfigSave();
    }
    ImGui::SameLine();
    {
        bool b = ap->muted != 0;
        if (ImGui::Checkbox("Mute", &b)) {
            ap->muted = b ? 1 : 0;
            Pc_ConfigSave();
        }
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextUnformatted("Mix");
    v = ap->dsVolume;
    if (ImGui::SliderInt("DirectSound", &v, 0, 200, "%d%%")) {
        ap->dsVolume = v;
        Pc_ConfigSave();
    }
    v = ap->psgVolume;
    if (ImGui::SliderInt("PSG (square/wave/noise)", &v, 0, 200, "%d%%")) {
        ap->psgVolume = v;
        Pc_ConfigSave();
    }
    v = ap->saturate;
    if (ImGui::SliderInt("Limiter threshold", &v, 50, 100, "%d%%")) {
        ap->saturate = v;
        Pc_ConfigSave();
    }
    ImGui::TextDisabled("DirectSound = sample voices, PSG = the 4 CGB channels.\nLower the limiter threshold for a softer, compressed sound.");

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextUnformatted("Equalizer");
    v = ap->bassDb;
    if (ImGui::SliderInt("Bass", &v, -15, 15, "%+d dB")) {
        ap->bassDb = v;
        Pc_ConfigSave();
    }
    v = ap->trebleDb;
    if (ImGui::SliderInt("Treble", &v, -15, 15, "%+d dB")) {
        ap->trebleDb = v;
        Pc_ConfigSave();
    }
    ImGui::TextDisabled("Shelving EQ on the final mix: bass at 200 Hz, treble at 4 kHz.");

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextUnformatted("Stereo");
    v = ap->stereoWidth;
    if (ImGui::SliderInt("Width", &v, 0, 200, "%d%%")) {
        ap->stereoWidth = v;
        Pc_ConfigSave();
    }
    ImGui::TextDisabled("100% is normal; 0% is mono; 200% doubles the spread.");

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextUnformatted("Reverb");
    {
        static const char *modes[] = { "Off", "Follow song", "Override" };
        v = ap->reverbMode;
        if (v < 0 || v > 2)
            v = 1;
        if (ImGui::Combo("##reverb_mode", &v, modes, 3)) {
            ap->reverbMode = v;
            Pc_ConfigSave();
        }
        ImGui::SameLine();
        ImGui::TextDisabled("current song: %d", Pc_AudioSongReverb());
        if (ap->reverbMode == 2) {
            v = ap->reverbOverride;
            if (ImGui::SliderInt("Amount", &v, 0, 127)) {
                ap->reverbOverride = v;
                Pc_ConfigSave();
            }
        }
    }

    ImGui::Spacing();
    ImGui::Separator();
    {
        bool b = ap->lowPass != 0;
        if (ImGui::Checkbox("GBA analog low-pass filter", &b)) {
            ap->lowPass = b ? 1 : 0;
            Pc_ConfigSave();
        }
        v = ap->lowPassCutoff;
        if (ImGui::SliderInt("Cutoff", &v, 1000, 16000, "%d Hz")) {
            ap->lowPassCutoff = v;
            Pc_ConfigSave();
        }
        ImGui::TextDisabled("The GBA's output is band-limited; this warms the mix toward the hardware.");
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextUnformatted("Tempo & Pitch");
    ImGui::TextDisabled("Per m4a player; SE players are single-shot effects.");
    if (ImGui::BeginChild("player_prefs", ImVec2(0.0f, 230.0f), true)) {
        Pc_UiAudioPlayerTable(ap);
    }
    ImGui::EndChild();

    ImGui::Spacing();
    ImGui::Separator();
    if (ImGui::Button("Reset to Defaults")) {
        PcAudioPrefs d;
        int i;
        memset(&d, 0, sizeof(d));
        d.masterVolume = 100;
        d.dsVolume = 100;
        d.psgVolume = 100;
        d.saturate = 85;
        d.reverbMode = 1;
        d.reverbOverride = 60;
        d.lowPass = 1;
        d.lowPassCutoff = 2200;
        d.bassDb = 0;
        d.trebleDb = 0;
        d.stereoWidth = 100;
        for (i = 0; i < PC_AUDIO_PLAYERS; i++) {
            d.tempoScale[i] = 100;
            d.pitchShift[i] = 0;
        }
        *ap = d;
        Pc_ConfigSave();
    }
    ImGui::SameLine();
    if (ImGui::Button("Capture 30s WAV")) {
        char dir[1024 + 1];
        char path[1024 + 1];
        Pc_ExeDir(dir, sizeof(dir), NULL);
        snprintf(path, sizeof(path), "%spmd-red-audio.wav", dir);
        Pc_AudioWavDump(path, 30);
    }
    ImGui::TextDisabled("Audio is rendered natively (GBA sample math at the host rate).\nChanges apply immediately.");
}

static void Pc_UiGraphicsTab(void) {
    PcVideoPrefs *vp = Pc_ConfigVideoPrefs();
    int v;
    bool b;

    ImGui::TextUnformatted("Window");
    v = vp->windowScale;
    if (ImGui::SliderInt("Scale", &v, PC_VIDEO_SCALE_MIN, PC_VIDEO_SCALE_MAX, "%dx")) {
        vp->windowScale = v;
        Pc_VideoResizeScale(v);
        Pc_ConfigSave();
    }
    ImGui::TextDisabled("Multiplier of the 240x160 internal frame.\nResizes the window immediately.");

    b = vp->fullscreen != 0;
    if (ImGui::Checkbox("Fullscreen", &b)) {
        vp->fullscreen = b ? 1 : 0;
        Pc_VideoSetFullscreen(b ? 1 : 0);
        Pc_ConfigSave();
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextUnformatted("Scaling");
    {
        static const char *modes[] = { "Integer", "Fit", "Stretch" };
        v = vp->scaleMode;
        if (v < 0 || v > 2)
            v = PC_SCALE_INTEGER;
        if (ImGui::Combo("Mode", &v, modes, 3)) {
            vp->scaleMode = v;
            Pc_VideoSetScaleMode(v);
            Pc_ConfigSave();
        }
        ImGui::TextDisabled("Integer = sharp pixels, Fit = fills the window\npreserving ratio, Stretch = fills ignoring ratio.");
    }

    b = vp->smoothing != 0;
    if (ImGui::Checkbox("Bilinear smoothing", &b)) {
        vp->smoothing = b ? 1 : 0;
        Pc_VideoSetSmoothing(b ? 1 : 0);
        Pc_ConfigSave();
    }
    ImGui::TextDisabled("Nearest is crisp and pixelated; bilinear blurs when upscaled.");

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextUnformatted("Backdrop");
    {
        float col[3];
        col[0] = (float)vp->letterboxR / 255.0f;
        col[1] = (float)vp->letterboxG / 255.0f;
        col[2] = (float)vp->letterboxB / 255.0f;
        if (ImGui::ColorEdit3("Letterbox", col)) {
            vp->letterboxR = (int)(col[0] * 255.0f + 0.5f);
            vp->letterboxG = (int)(col[1] * 255.0f + 0.5f);
            vp->letterboxB = (int)(col[2] * 255.0f + 0.5f);
            Pc_VideoSetLetterbox(vp->letterboxR, vp->letterboxG, vp->letterboxB);
            Pc_ConfigSave();
        }
        ImGui::TextDisabled("Color shown around the frame when the window\ndoesn't match the 3:2 ratio.");
    }

    ImGui::Spacing();
    ImGui::Separator();
    b = vp->vsync != 0;
    if (ImGui::Checkbox("Vertical sync", &b)) {
        vp->vsync = b ? 1 : 0;
        Pc_ConfigSave();
    }
    ImGui::TextDisabled("Waits for the display refresh to avoid tearing.\nTakes effect the next time the game starts (Game > Restart).");

    ImGui::Spacing();
    ImGui::Separator();
    if (ImGui::Button("Reset to Defaults")) {
        PcVideoPrefs d;
        memset(&d, 0, sizeof(d));
        d.windowScale = 3;
        d.scaleMode = PC_SCALE_INTEGER;
        d.vsync = 1;
        *vp = d;
        Pc_VideoSetScaleMode(vp->scaleMode);
        Pc_VideoSetSmoothing(vp->smoothing);
        Pc_VideoSetFullscreen(vp->fullscreen);
        Pc_VideoSetLetterbox(vp->letterboxR, vp->letterboxG, vp->letterboxB);
        Pc_VideoResizeScale(vp->windowScale);
        Pc_ConfigSave();
    }
    ImGui::SameLine();
    ImGui::TextDisabled("Most changes apply immediately.");
}

static void Pc_UiSettingsWindow(void) {
    ImGui::SetNextWindowSize(ImVec2(640, 560), ImGuiCond_FirstUseEver);
    if (!ImGui::Begin("Settings", &gSettingsOpen)) {
        ImGui::End();
        return;
    }

    if (ImGui::BeginTabBar("settings_tabs")) {
        if (ImGui::BeginTabItem("Graphics")) {
            ImGui::Spacing();
            Pc_UiGraphicsTab();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Audio")) {
            Pc_UiAudioTab();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Controls")) {
            Pc_UiControlsTab();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Boot")) {
            Pc_UiBootTab();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    ImGui::End();

    // Bind-capture modal: shown while a "Capture next key..." is pending.
    if (gCaptureAction >= 0) {
        ImGui::OpenPopup("capture_key");
        if (ImGui::BeginPopupModal("capture_key", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
            char msg[96];
            snprintf(msg, sizeof(msg), "Press a key for %s...", Pc_ActionName(gCaptureAction));
            ImGui::TextUnformatted(msg);
            ImGui::TextDisabled("Esc cancels");
            if (ImGui::IsKeyPressed(ImGuiKey_Escape))
                gCaptureAction = -1;
            ImGui::EndPopup();
        }
    }
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
                gSettingsOpen = true;
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

    if (gSettingsOpen)
        Pc_UiSettingsWindow();

    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(
        ImGui::GetDrawData(), (SDL_Renderer *)Pc_VideoGetSdlRenderer());
}

#else // !HAVE_SDL2 — headless stubs so the C callers always link.

extern "C" void Pc_UiInit(void) {}
extern "C" void Pc_UiShutdown(void) {}
extern "C" int Pc_UiIsActive(void) { return 0; }
extern "C" int Pc_UiWantsCaptureInput(void) { return 0; }
extern "C" void Pc_UiProcessEvent(const void *sdlEvent) { (void)sdlEvent; }
extern "C" void Pc_UiToggle(void) {}
extern "C" void Pc_UiRender(void) {}

#endif // HAVE_SDL2