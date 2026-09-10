// platform/pc/config_pc.c — pmd-red.ini persistence for controls + boot toggles.
//
// Reads/writes a tiny INI next to the executable:
//
//   [Controls]
//   Up=key:82 key:26          (SDL_Scancode for keys, SDL button id for mouse)
//   A=key:29 key:44 mouse:1
//   [Boot]
//   NoConsole=1
//   SkipWarning=0
//
// Defaults mirror the classic emulator layout (arrows+WASD move, Z/Space/mouse
// left = A, X/mouse right = B, Enter = Start, RShift = Select, Q = L, E = R).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config_pc.h"

#ifdef HAVE_SDL2
#include <SDL2/SDL.h>
#endif

static char sConfigPath[1024 + 1];
static PcActionBinds sBinds[PC_ACT_COUNT];
static PcBootPrefs sBoot;
static PcAudioPrefs sAudio;

static const char *const kActionNames[PC_ACT_COUNT] = {
    "Move Up", "Move Down", "Move Left", "Move Right",
    "A", "B", "Start", "Select", "L", "R"
};
static const char *const kActionKeys[PC_ACT_COUNT] = {
    "Up", "Down", "Left", "Right", "A", "B", "Start", "Select", "L", "R"
};

static int Pc_AddBindInternal(int action, int kind, int code)
{
    PcActionBinds *ab;
    int i;
    if (action < 0 || action >= PC_ACT_COUNT)
        return 0;
    ab = &sBinds[action];
    for (i = 0; i < ab->count; i++)
        if (ab->binds[i].kind == kind && ab->binds[i].code == code)
            return 0; // duplicate
    if (ab->count >= PC_MAX_BINDS)
        return 0;
    ab->binds[ab->count].kind = kind;
    ab->binds[ab->count].code = code;
    ab->count++;
    return 1;
}

static void Pc_ResetBindsDefault(void)
{
    memset(sBinds, 0, sizeof(sBinds));
#ifdef HAVE_SDL2
    Pc_AddBindInternal(PC_ACT_UP,    0, SDL_SCANCODE_UP);
    Pc_AddBindInternal(PC_ACT_UP,    0, SDL_SCANCODE_W);
    Pc_AddBindInternal(PC_ACT_DOWN,  0, SDL_SCANCODE_DOWN);
    Pc_AddBindInternal(PC_ACT_DOWN,  0, SDL_SCANCODE_S);
    Pc_AddBindInternal(PC_ACT_LEFT,  0, SDL_SCANCODE_LEFT);
    Pc_AddBindInternal(PC_ACT_LEFT,  0, SDL_SCANCODE_A);
    Pc_AddBindInternal(PC_ACT_RIGHT, 0, SDL_SCANCODE_RIGHT);
    Pc_AddBindInternal(PC_ACT_RIGHT, 0, SDL_SCANCODE_D);
    Pc_AddBindInternal(PC_ACT_A,     0, SDL_SCANCODE_Z);
    Pc_AddBindInternal(PC_ACT_A,     0, SDL_SCANCODE_SPACE);
    Pc_AddBindInternal(PC_ACT_A,     1, SDL_BUTTON_LEFT);
    Pc_AddBindInternal(PC_ACT_B,     0, SDL_SCANCODE_X);
    Pc_AddBindInternal(PC_ACT_B,     1, SDL_BUTTON_RIGHT);
    Pc_AddBindInternal(PC_ACT_START, 0, SDL_SCANCODE_RETURN);
    Pc_AddBindInternal(PC_ACT_START, 0, SDL_SCANCODE_KP_ENTER);
    Pc_AddBindInternal(PC_ACT_SELECT, 0, SDL_SCANCODE_RSHIFT);
    Pc_AddBindInternal(PC_ACT_L,     0, SDL_SCANCODE_Q);
    Pc_AddBindInternal(PC_ACT_R,     0, SDL_SCANCODE_E);
#else
    (void)0;
#endif
}

void Pc_ConfigResetBinds(void)
{
    Pc_ResetBindsDefault();
}

PcActionBinds *Pc_ConfigBinds(void)
{
    return sBinds;
}

void Pc_ConfigAddBind(int action, int kind, int code)
{
    Pc_AddBindInternal(action, kind, code);
}

void Pc_ConfigRemoveBind(int action, int kind, int code)
{
    PcActionBinds *ab;
    int i;
    if (action < 0 || action >= PC_ACT_COUNT)
        return;
    ab = &sBinds[action];
    for (i = 0; i < ab->count; i++) {
        if (ab->binds[i].kind == kind && ab->binds[i].code == code) {
            memmove(&ab->binds[i], &ab->binds[i + 1],
                    (size_t)(ab->count - i - 1) * sizeof(PcBind));
            ab->count--;
            return;
        }
    }
}

PcBootPrefs *Pc_ConfigBootPrefs(void)
{
    return &sBoot;
}

static void Pc_ResetAudioDefault(void)
{
    memset(&sAudio, 0, sizeof(sAudio));
    sAudio.masterVolume = 100;
    sAudio.reverbMode = 1;   // follow the song
    sAudio.reverbOverride = 60;
    sAudio.lowPassCutoff = 9000;
}

PcAudioPrefs *Pc_ConfigAudioPrefs(void)
{
    return &sAudio;
}

const char *Pc_ActionName(int action)
{
    if (action < 0 || action >= PC_ACT_COUNT)
        return "?";
    return kActionNames[action];
}

const char *Pc_ConfigPath(void)
{
    return sConfigPath;
}

void Pc_BindLabel(int kind, int code, char *out, size_t cap)
{
    if (out == NULL || cap == 0)
        return;
    out[0] = '\0';
    if (kind == 0) {
#ifdef HAVE_SDL2
        SDL_Keycode kc = SDL_GetKeyFromScancode((SDL_Scancode)code);
        const char *name = SDL_GetKeyName(kc);
        if (name != NULL && name[0] != '\0') {
            snprintf(out, cap, "%s", name);
            return;
        }
#endif
        snprintf(out, cap, "Key %d", code);
    } else {
        switch (code) {
        case 1:  snprintf(out, cap, "Mouse Left"); break;
        case 2:  snprintf(out, cap, "Mouse Middle"); break;
        case 3:  snprintf(out, cap, "Mouse Right"); break;
        case 4:  snprintf(out, cap, "Mouse X1"); break;
        case 5:  snprintf(out, cap, "Mouse X2"); break;
        default: snprintf(out, cap, "Mouse %d", code); break;
        }
    }
}

// ---- INI read/write ----

static int Pc_ActionFromKey(const char *key)
{
    int a;
    for (a = 0; a < PC_ACT_COUNT; a++)
        if (strcmp(key, kActionKeys[a]) == 0)
            return a;
    return -1;
}

static void Pc_Trim(char *s)
{
    char *end;
    while (*s == ' ' || *s == '\t')
        s++;
    end = s + strlen(s);
    while (end > s && (end[-1] == ' ' || end[-1] == '\t' || end[-1] == '\r' ||
                       end[-1] == '\n'))
        end--;
    *end = '\0';
}

static void Pc_ParseBinds(const char *val, int action)
{
    const char *p = val;
    // A file line fully replaces the action's binds (defaults were seeded
    // before parsing; entries not mentioned in the file keep their defaults).
    if (action >= 0 && action < PC_ACT_COUNT)
        memset(&sBinds[action], 0, sizeof(sBinds[action]));
    while (*p != '\0') {
        int kind = -1, code = 0;
        int n = 0;
        while (*p == ' ' || *p == '\t')
            p++;
        if (sscanf(p, "key:%d%n", &code, &n) == 1)
            kind = 0;
        else if (sscanf(p, "mouse:%d%n", &code, &n) == 1)
            kind = 1;
        if (n == 0)
            break; // no valid token left
        p += n;
        if (kind >= 0)
            Pc_AddBindInternal(action, kind, code);
    }
}

void Pc_ConfigLoad(const char *exeDir)
{
    FILE *f;
    char line[512];
    char section[32];

    if (exeDir != NULL && exeDir[0] != '\0')
        snprintf(sConfigPath, sizeof(sConfigPath), "%spmd-red.ini", exeDir);
    else
        snprintf(sConfigPath, sizeof(sConfigPath), "pmd-red.ini");

    Pc_ResetBindsDefault();
    memset(&sBoot, 0, sizeof(sBoot));
    Pc_ResetAudioDefault();

    f = fopen(sConfigPath, "r");
    if (f == NULL)
        return;

    section[0] = '\0';
    while (fgets(line, sizeof(line), f) != NULL) {
        char *p = line;
        char *eq;
        char key[64];
        char val[256];

        while (*p == ' ' || *p == '\t')
            p++;
        if (*p == '\0' || *p == '\n' || *p == '#' || *p == ';')
            continue;
        if (*p == '[') {
            char *end = strchr(p, ']');
            if (end != NULL) {
                *end = '\0';
                snprintf(section, sizeof(section), "%s", p + 1);
            }
            continue;
        }
        eq = strchr(p, '=');
        if (eq == NULL)
            continue;
        {
            size_t kl = (size_t)(eq - p);
            if (kl >= sizeof(key))
                kl = sizeof(key) - 1;
            memcpy(key, p, kl);
            key[kl] = '\0';
        }
        snprintf(val, sizeof(val), "%s", eq + 1);
        Pc_Trim(key);
        Pc_Trim(val);

        if (strcmp(section, "Controls") == 0) {
            int action = Pc_ActionFromKey(key);
            if (action >= 0)
                Pc_ParseBinds(val, action);
        } else if (strcmp(section, "Boot") == 0) {
            int b = atoi(val);
            if (strcmp(key, "NoConsole") == 0) sBoot.noConsole = b;
            else if (strcmp(key, "SkipWarning") == 0) sBoot.skipWarning = b;
            else if (strcmp(key, "SkipLogos") == 0) sBoot.skipLogos = b;
            else if (strcmp(key, "SkipIntro") == 0) sBoot.skipIntro = b;
            else if (strcmp(key, "Autoload") == 0) sBoot.autoload = b;
            else if (strcmp(key, "FpsLog") == 0) sBoot.fpsLog = b;
        } else if (strcmp(section, "Audio") == 0) {
            int v = atoi(val);
            if (strcmp(key, "MasterVolume") == 0) sAudio.masterVolume = v;
            else if (strcmp(key, "Muted") == 0) sAudio.muted = v;
            else if (strcmp(key, "ReverbMode") == 0) sAudio.reverbMode = v;
            else if (strcmp(key, "ReverbOverride") == 0) sAudio.reverbOverride = v;
            else if (strcmp(key, "LowPass") == 0) sAudio.lowPass = v;
            else if (strcmp(key, "LowPassCutoff") == 0) sAudio.lowPassCutoff = v;
        }
    }
    fclose(f);
}

void Pc_ConfigSave(void)
{
    FILE *f;
    int a;
    if (sConfigPath[0] == '\0')
        snprintf(sConfigPath, sizeof(sConfigPath), "pmd-red.ini");
    f = fopen(sConfigPath, "w");
    if (f == NULL)
        return;

    fprintf(f, "# pmd-red config (written by the settings menu)\n");
    fprintf(f, "[Controls]\n");
    for (a = 0; a < PC_ACT_COUNT; a++) {
        PcActionBinds *ab = &sBinds[a];
        int i;
        fprintf(f, "%s=", kActionKeys[a]);
        for (i = 0; i < ab->count; i++) {
            if (ab->binds[i].kind == 0)
                fprintf(f, "key:%d ", ab->binds[i].code);
            else
                fprintf(f, "mouse:%d ", ab->binds[i].code);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "[Boot]\n");
    fprintf(f, "NoConsole=%d\n", sBoot.noConsole);
    fprintf(f, "SkipWarning=%d\n", sBoot.skipWarning);
    fprintf(f, "SkipLogos=%d\n", sBoot.skipLogos);
    fprintf(f, "SkipIntro=%d\n", sBoot.skipIntro);
    fprintf(f, "Autoload=%d\n", sBoot.autoload);
    fprintf(f, "FpsLog=%d\n", sBoot.fpsLog);
    fprintf(f, "[Audio]\n");
    fprintf(f, "MasterVolume=%d\n", sAudio.masterVolume);
    fprintf(f, "Muted=%d\n", sAudio.muted);
    fprintf(f, "ReverbMode=%d\n", sAudio.reverbMode);
    fprintf(f, "ReverbOverride=%d\n", sAudio.reverbOverride);
    fprintf(f, "LowPass=%d\n", sAudio.lowPass);
    fprintf(f, "LowPassCutoff=%d\n", sAudio.lowPassCutoff);
    fclose(f);
}