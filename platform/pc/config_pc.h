// platform/pc/config_pc.h — persisted settings (pmd-red.ini next to the exe).
//
// Holds the rebindable controls (multiple keys/mouse buttons per action) and
// the boot-launch toggles. Plain C so it is shared by the C input/save backends
// and the C++ ImGui settings window. Format is a tiny INI:
//
//   [Controls]
//   Up=key:82 key:26
//   A=key:29 key:44 mouse:1
//   [Boot]
//   NoConsole=1
#ifndef PMDRED_PC_CONFIG_PC_H
#define PMDRED_PC_CONFIG_PC_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Action ids — index into the Pc_ConfigBinds() table.
enum PcActionId
{
    PC_ACT_UP = 0,
    PC_ACT_DOWN,
    PC_ACT_LEFT,
    PC_ACT_RIGHT,
    PC_ACT_A,
    PC_ACT_B,
    PC_ACT_START,
    PC_ACT_SELECT,
    PC_ACT_L,
    PC_ACT_R,
    PC_ACT_COUNT
};

#define PC_MAX_BINDS 8

// kind: 0 = keyboard key (SDL_Scancode), 1 = mouse button (SDL button id).
typedef struct PcBind
{
    int kind;
    int code;
} PcBind;

typedef struct PcActionBinds
{
    PcBind binds[PC_MAX_BINDS];
    int count;
} PcActionBinds;

// Boot-launch toggles. Command-line args override these at startup.
typedef struct PcBootPrefs
{
    int noConsole;   // --noconsole
    int skipWarning; // SkipWarning
    int skipLogos;   // SkipLogos
    int skipIntro;   // SkipIntro
    int autoload;    // --autoload
    int fpsLog;      // --fps
} PcBootPrefs;

// Window-scale bounds for the 240x160 internal framebuffer.
#define PC_VIDEO_SCALE_MIN 1
#define PC_VIDEO_SCALE_MAX 8

// Scale-to-window modes for PcVideoPrefs.scaleMode.
enum PcVideoScaleMode
{
    PC_SCALE_INTEGER = 0, // largest integer multiple that fits, centered
    PC_SCALE_FIT,         // fractional fit, aspect preserved, centered
    PC_SCALE_STRETCH      // fill the whole window (aspect not preserved)
};

// Live video settings (applied by video_pc.c; saved to [Video]). vsync only
// takes effect when the renderer is (re)created, i.e. at the next restart.
typedef struct PcVideoPrefs
{
    int windowScale;   // 1-8 initial window multiplier (240x160 base)
    int fullscreen;    // 0/1 start (and live-toggle) fullscreen
    int scaleMode;     // PC_SCALE_*: how the frame maps into the window
    int smoothing;     // 0 = nearest (pixelated), 1 = bilinear
    int vsync;         // 0/1 present-vsync (renderer flag; needs restart)
    int letterboxR;    // 0-255 backdrop color around the scaled frame
    int letterboxG;    // 0-255
    int letterboxB;    // 0-255
    int presentHz;     // present rate: 0 = match display, >0 = target Hz, <0 = uncapped
    int interpolate;   // 0/1 interpolate frames between 60Hz logic ticks (Phase 2)
} PcVideoPrefs;

// Number of m4a music players (INDEX_BGM..INDEX_SE6; must match music.h).
#define PC_AUDIO_PLAYERS 8

// Live audio settings (applied by audio_pc.c every render; saved to [Audio]).
typedef struct PcAudioPrefs
{
    int masterVolume;   // 0-100 output volume
    int muted;          // 0/1 master mute
    int dsVolume;       // 0-200 DirectSound (sample) level
    int psgVolume;      // 0-200 PSG (square/wave/noise) level
    int saturate;       // 50-100 soft-knee limiter threshold (% of full scale)
    int reverbMode;     // 0 = off, 1 = follow song (default), 2 = override
    int reverbOverride; // 0-127 used when reverbMode == 2
    int lowPass;        // 0/1 GBA analog low-pass filter
    int lowPassCutoff;  // Hz cutoff (when lowPass != 0)
    int bassDb;         // -15..+15 low-shelf EQ gain (dB)
    int trebleDb;       // -15..+15 high-shelf EQ gain (dB)
    int stereoWidth;    // 0-200 stereo width (% of normal)
    int tempoScale[PC_AUDIO_PLAYERS]; // 50-200 per-player tempo (%)
    int pitchShift[PC_AUDIO_PLAYERS]; // -12..+12 per-player pitch (semitones)
} PcAudioPrefs;

// Load pmd-red.ini from the exe directory (trailing sep optional; NULL -> cwd).
// Resets binds/prefs to defaults first, then applies the file on top.
void Pc_ConfigLoad(const char *exeDir);
// Write the current binds/prefs back to pmd-red.ini.
void Pc_ConfigSave(void);
// Full path of the config file (valid after Pc_ConfigLoad).
const char *Pc_ConfigPath(void);

// Current binds, PC_ACT_COUNT entries (mutable — call Pc_ConfigSave to persist).
PcActionBinds *Pc_ConfigBinds(void);
// Replace every action's binds with the built-in defaults.
void Pc_ConfigResetBinds(void);
// Add a bind to an action if it isn't already there and room remains.
void Pc_ConfigAddBind(int action, int kind, int code);
// Remove one specific bind.
void Pc_ConfigRemoveBind(int action, int kind, int code);

// Current boot-launch toggles (mutable — call Pc_ConfigSave to persist).
PcBootPrefs *Pc_ConfigBootPrefs(void);

// Current video settings (mutable — call Pc_ConfigSave to persist).
PcVideoPrefs *Pc_ConfigVideoPrefs(void);

// Current audio settings (mutable — call Pc_ConfigSave to persist).
PcAudioPrefs *Pc_ConfigAudioPrefs(void);

// Human-readable labels for the settings UI.
const char *Pc_ActionName(int action);            // "Move Up", "A", ...
void Pc_BindLabel(int kind, int code, char *out, size_t cap); // "W", "Mouse Left", ...

#ifdef __cplusplus
} // extern "C"
#endif

#endif // PMDRED_PC_CONFIG_PC_H