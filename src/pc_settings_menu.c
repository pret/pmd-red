// src/pc_settings_menu.c - in-game (GBA UI) PC settings screen.
//
// PC-port only. Adds a "PC Settings" entry to the title-screen main menu,
// opening Video / Audio / Controls sub-screens that edit the same pmd-red.ini
// prefs the ImGui overlay owns. Boot stays ImGui-only.
//
// The whole file is PLATFORM_PC so the GBA/decomp build is untouched.
#ifdef PLATFORM_PC

#include "global.h"
#include "globaldata.h"
#include "gba_shim.h"
#include "input.h"
#include "main_loops.h"
#include "menu_input.h"
#include "music_util.h"
#include "string_format.h"
#include "text_1.h"
#include "text_3.h"

static const u8 sTextPcSettings[] = _("PC Settings");
static const u8 sTextVideo[] = _("Video");
static const u8 sTextAudio[] = _("Audio");
static const u8 sTextControls[] = _("Controls");
static const u8 sTextWindowScale[] = _("Window Scale");
static const u8 sTextFullscreen[] = _("Fullscreen");
static const u8 sTextScalingMode[] = _("Scaling Mode");
static const u8 sTextSmoothing[] = _("Smoothing");
static const u8 sTextVolume[] = _("Volume");
static const u8 sTextMute[] = _("Mute");
static const u8 sTextResetDefaults[] = _("Reset to Defaults");
static const u8 sTextInteger[] = _("Integer");
static const u8 sTextFit[] = _("Fit");
static const u8 sTextStretch[] = _("Stretch");
static const u8 sTextNo[] = _("No");
static const u8 sTextYes[] = _("Yes");
static const u8 sTextEscCancels[] = _("Esc cancels");

static MenuInputStruct sMenu;

enum {
    PC_SETTINGS_TOP_VIDEO,
    PC_SETTINGS_TOP_AUDIO,
    PC_SETTINGS_TOP_CONTROLS,
    PC_SETTINGS_TOP_COUNT
};

enum {
    PC_VIDEO_SCALE,
    PC_VIDEO_FULLSCREEN,
    PC_VIDEO_MODE,
    PC_VIDEO_SMOOTHING,
    PC_VIDEO_COUNT
};

enum {
    PC_AUDIO_VOLUME,
    PC_AUDIO_MUTE,
    PC_AUDIO_COUNT
};

// Controls list = every rebindable action, plus a trailing reset entry.
#define PC_CONTROLS_RESET PC_ACT_COUNT
#define PC_CONTROLS_COUNT (PC_ACT_COUNT + 1)

static void PcSettingsTick(void)
{
    Pc_FrameActions();
}

static void PcSettingsShowWindow(const u8 *headerText, s32 count, s32 width, s32 posX, s32 posY, s32 calcEntryHeight)
{
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .flags = WINTEMPLATE_FLAG_NONE,
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = { 2, 2 },
                .width = 16,
                .height = 16,
                .totalHeight = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    header.count = 1;
    header.currId = 0;
    header.f3 = 0;
    sMenu.currPageEntries = count;
    sMenu.entriesPerPage = count;
    sMenu.currPage = 0;
    sMenu.pagesCount = 0;
    sMenu.unk4 = 0;
    sMenu.firstEntryY = 16;
    sMenu.leftRightArrowsPos.x = 0;
    sMenu.leftRightArrowsPos.y = 0;
    sMenu.unk14.x = 0;
    sMenu.windowId = 0;
    ResetTouchScreenMenuInput(&sMenu.touchScreen);
    windows.id[0].width = width;
    windows.id[0].pos.x = posX;
    windows.id[0].pos.y = posY;
    windows.id[0].height = windows.id[0].totalHeight = CalcEntriesTotalHeight(count, calcEntryHeight) + 2;
    header.width = 10;

    ResetUnusedInputStruct();
    ShowWindows(&windows, TRUE, TRUE);
    sub_80137B0(&sMenu, 0);
    sub_80073B8(0);
    PrintStringOnWindow(16, 0, headerText, 0, 0);
}

static void PcSettingsClearWindows(void)
{
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
}

// Wait for A (returns menuIndex) or B (returns -1). Handles up/down.
static s32 PcSettingsVerticalInput(void)
{
    while (TRUE) {
        AddMenuCursorSprite(&sMenu);
        PcSettingsTick();

        if (gRealInputs.repeated & DPAD_DOWN) {
            PlayMenuSoundEffect(MENU_SFX_NAVIGATE);
            MoveMenuCursorDownWrapAround(&sMenu, TRUE);
        }
        if (gRealInputs.repeated & DPAD_UP) {
            PlayMenuSoundEffect(MENU_SFX_NAVIGATE);
            MoveMenuCursorUpWrapAround(&sMenu, TRUE);
        }
        if (gRealInputs.pressed & A_BUTTON) {
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return sMenu.menuIndex;
        }
        if (gRealInputs.pressed & B_BUTTON) {
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return -1;
        }
    }
}

static void PcSettingsRunVideo(void)
{
    bool8 dpadMoved;
    bool8 bPress;

    sMenu.menuIndex = 0;
    while (TRUE) {
        s32 i;
        s32 y[PC_VIDEO_COUNT];
        PcVideoPrefs *vp = Pc_ConfigVideoPrefs();

        dpadMoved = FALSE;
        bPress = FALSE;

        PcSettingsShowWindow(sTextVideo, PC_VIDEO_COUNT, 24, 2, 2, DEFAULT_MENU_ENTRY_HEIGHT);
        for (i = 0; i < PC_VIDEO_COUNT; i++)
            y[i] = GetMenuEntryYCoord(&sMenu, i);

        PrintStringOnWindow(8, y[0], sTextWindowScale, 0, 0);
        PrintNumOnWindow(144, y[0], vp->windowScale, 1, 7, 0);
        PrintStringOnWindow(8, y[1], sTextFullscreen, 0, 0);
        PrintStringOnWindow(144, y[1], vp->fullscreen ? sTextYes : sTextNo, 0, 0);
        PrintStringOnWindow(8, y[2], sTextScalingMode, 0, 0);
        if (vp->scaleMode == PC_SCALE_FIT)
            PrintStringOnWindow(144, y[2], sTextFit, 0, 0);
        else if (vp->scaleMode == PC_SCALE_STRETCH)
            PrintStringOnWindow(144, y[2], sTextStretch, 0, 0);
        else
            PrintStringOnWindow(144, y[2], sTextInteger, 0, 0);
        PrintStringOnWindow(8, y[3], sTextSmoothing, 0, 0);
        PrintStringOnWindow(144, y[3], vp->smoothing ? sTextYes : sTextNo, 0, 0);
        sub_80073E0(0);

        while (TRUE) {
            AddMenuCursorSprite(&sMenu);
            PcSettingsTick();

            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayMenuSoundEffect(MENU_SFX_NAVIGATE);
                MoveMenuCursorDownWrapAround(&sMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayMenuSoundEffect(MENU_SFX_NAVIGATE);
                MoveMenuCursorUpWrapAround(&sMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_LEFT) {
                PlayMenuSoundEffect(MENU_SFX_TOGGLE);
                if (sMenu.menuIndex == PC_VIDEO_SCALE) {
                    if (vp->windowScale > PC_VIDEO_SCALE_MIN) {
                        vp->windowScale--;
                        Pc_VideoResizeScale(vp->windowScale);
                        Pc_ConfigSave();
                    }
                }
                else if (sMenu.menuIndex == PC_VIDEO_FULLSCREEN) {
                    vp->fullscreen = !vp->fullscreen;
                    Pc_VideoSetFullscreen(vp->fullscreen);
                    Pc_ConfigSave();
                }
                else if (sMenu.menuIndex == PC_VIDEO_MODE) {
                    vp->scaleMode = (vp->scaleMode == PC_SCALE_INTEGER) ? PC_SCALE_STRETCH : vp->scaleMode - 1;
                    Pc_VideoSetScaleMode(vp->scaleMode);
                    Pc_ConfigSave();
                }
                else if (sMenu.menuIndex == PC_VIDEO_SMOOTHING) {
                    vp->smoothing = !vp->smoothing;
                    Pc_VideoSetSmoothing(vp->smoothing);
                    Pc_ConfigSave();
                }
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.repeated & DPAD_RIGHT) {
                PlayMenuSoundEffect(MENU_SFX_TOGGLE);
                if (sMenu.menuIndex == PC_VIDEO_SCALE) {
                    if (vp->windowScale < PC_VIDEO_SCALE_MAX) {
                        vp->windowScale++;
                        Pc_VideoResizeScale(vp->windowScale);
                        Pc_ConfigSave();
                    }
                }
                else if (sMenu.menuIndex == PC_VIDEO_FULLSCREEN) {
                    vp->fullscreen = !vp->fullscreen;
                    Pc_VideoSetFullscreen(vp->fullscreen);
                    Pc_ConfigSave();
                }
                else if (sMenu.menuIndex == PC_VIDEO_MODE) {
                    vp->scaleMode = (vp->scaleMode == PC_SCALE_STRETCH) ? PC_SCALE_INTEGER : vp->scaleMode + 1;
                    Pc_VideoSetScaleMode(vp->scaleMode);
                    Pc_ConfigSave();
                }
                else if (sMenu.menuIndex == PC_VIDEO_SMOOTHING) {
                    vp->smoothing = !vp->smoothing;
                    Pc_VideoSetSmoothing(vp->smoothing);
                    Pc_ConfigSave();
                }
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.pressed & A_BUTTON) {
                PlayMenuSoundEffect(MENU_SFX_ACCEPT);
                break;
            }
            if (gRealInputs.pressed & B_BUTTON) {
                PlayMenuSoundEffect(MENU_SFX_BACK);
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&sMenu);
        PcSettingsTick();
        if (!dpadMoved)
            break;
    }

    (void)bPress;
}

static void PcSettingsRunAudio(void)
{
    bool8 dpadMoved;
    bool8 bPress;

    sMenu.menuIndex = 0;
    while (TRUE) {
        s32 i;
        s32 y[PC_AUDIO_COUNT];
        PcAudioPrefs *ap = Pc_ConfigAudioPrefs();

        dpadMoved = FALSE;
        bPress = FALSE;

        PcSettingsShowWindow(sTextAudio, PC_AUDIO_COUNT, 24, 2, 2, DEFAULT_MENU_ENTRY_HEIGHT);
        for (i = 0; i < PC_AUDIO_COUNT; i++)
            y[i] = GetMenuEntryYCoord(&sMenu, i);

        PrintStringOnWindow(8, y[0], sTextVolume, 0, 0);
        PrintNumOnWindow(144, y[0], ap->masterVolume, 3, 7, 0);
        PrintStringOnWindow(8, y[1], sTextMute, 0, 0);
        PrintStringOnWindow(144, y[1], ap->muted ? sTextYes : sTextNo, 0, 0);
        sub_80073E0(0);

        while (TRUE) {
            AddMenuCursorSprite(&sMenu);
            PcSettingsTick();

            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayMenuSoundEffect(MENU_SFX_NAVIGATE);
                MoveMenuCursorDownWrapAround(&sMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayMenuSoundEffect(MENU_SFX_NAVIGATE);
                MoveMenuCursorUpWrapAround(&sMenu, TRUE);
            }
            if ((gRealInputs.repeated & DPAD_LEFT) || (gRealInputs.repeated & DPAD_RIGHT)) {
                s32 delta = (gRealInputs.repeated & DPAD_RIGHT) ? 5 : -5;
                PlayMenuSoundEffect(MENU_SFX_TOGGLE);
                if (sMenu.menuIndex == PC_AUDIO_VOLUME) {
                    s32 v = ap->masterVolume + delta;
                    if (v < 0)
                        v = 0;
                    if (v > 100)
                        v = 100;
                    ap->masterVolume = v;
                    Pc_ConfigSave();
                }
                else if (sMenu.menuIndex == PC_AUDIO_MUTE) {
                    ap->muted = !ap->muted;
                    Pc_ConfigSave();
                }
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.pressed & A_BUTTON) {
                PlayMenuSoundEffect(MENU_SFX_ACCEPT);
                break;
            }
            if (gRealInputs.pressed & B_BUTTON) {
                PlayMenuSoundEffect(MENU_SFX_BACK);
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&sMenu);
        PcSettingsTick();
        if (!dpadMoved)
            break;
    }

    (void)bPress;
}

static void PcSettingsBuildBindText(s32 action, u8 *out, s32 cap)
{
    PcActionBinds *ab = &Pc_ConfigBinds()[action];
    char tmp[160];
    int len = 0;
    int i;

    tmp[0] = '\0';
    for (i = 0; i < ab->count; i++) {
        char lbl[48];
        int j;
        Pc_BindLabel(ab->binds[i].kind, ab->binds[i].code, lbl, sizeof(lbl));
        if (i > 0 && len < (int)sizeof(tmp) - 2)
            tmp[len++] = ' ';
        for (j = 0; lbl[j] != '\0' && len < (int)sizeof(tmp) - 2; j++) {
            char c = lbl[j];
            if (c < 32 || c > 126)
                c = '?';
            tmp[len++] = c;
        }
        tmp[len] = '\0';
    }
    if (len == 0) {
        tmp[0] = '-';
        tmp[1] = '\0';
    }

    for (i = 0; i < cap - 1 && tmp[i] != '\0'; i++)
        out[i] = (u8)tmp[i];
    out[i] = '\0';
}

static void PcSettingsRunKeyCapture(s32 action)
{
    WindowTemplates windows = {
        .id = {
            [0] = {
                .flags = WINTEMPLATE_FLAG_NONE,
                .type = WINDOW_TYPE_NORMAL,
                .pos = { 2, 6 },
                .width = 26,
                .height = 5,
                .totalHeight = 5,
                .unk12 = 0,
                .header = NULL,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };
    char prompt[96];
    u8 uPrompt[96];
    s32 i;
    s32 result;

    snprintf(prompt, sizeof(prompt), "Press a key for %s", Pc_ActionName(action));
    for (i = 0; i < (s32)sizeof(uPrompt) - 1 && prompt[i] != '\0'; i++)
        uPrompt[i] = (u8)prompt[i];
    uPrompt[i] = '\0';

    ResetUnusedInputStruct();
    ShowWindows(&windows, TRUE, TRUE);
    sub_80073B8(0);
    PrintStringOnWindow(8, 16, uPrompt, 0, 0);
    PrintStringOnWindow(8, 32, sTextEscCancels, 0, 0);
    sub_80073E0(0);

    Pc_InputStartKeyCapture();
    while (Pc_InputKeyCaptureResult() == 0)
        PcSettingsTick();

    result = Pc_InputKeyCaptureResult();
    if (result == 1) {
        Pc_ConfigAddBind(action, 0, Pc_InputKeyCaptureScancode());
        Pc_ConfigSave();
    }

    // Swallow the key-up so it can't immediately trigger a menu action.
    UnpressButtons();
    PcSettingsTick();
}

static void PcSettingsRunControls(void)
{
    sMenu.menuIndex = 0;
    while (TRUE) {
        s32 i;
        s32 y[PC_CONTROLS_COUNT];
        s32 choice;

        PcSettingsShowWindow(sTextControls, PC_CONTROLS_COUNT, 26, 2, 2, 10);
        for (i = 0; i < PC_CONTROLS_COUNT; i++)
            y[i] = GetMenuEntryYCoord(&sMenu, i);

        for (i = 0; i < PC_ACT_COUNT; i++) {
            u8 bindText[96];
            PcSettingsBuildBindText(i, bindText, sizeof(bindText));
            PrintStringOnWindow(8, y[i], (const u8 *)Pc_ActionName(i), 0, 0);
            PrintStringOnWindow(96, y[i], bindText, 0, 0);
        }
        PrintStringOnWindow(8, y[PC_CONTROLS_RESET], sTextResetDefaults, 0, 0);
        sub_80073E0(0);

        choice = PcSettingsVerticalInput();
        if (choice < 0)
            break;
        if (choice == PC_CONTROLS_RESET) {
            Pc_ConfigResetBinds();
            Pc_ConfigSave();
        }
        else {
            PcSettingsRunKeyCapture(choice);
        }
    }
}

static void PcSettingsRunTop(void)
{
    sMenu.menuIndex = 0;
    while (TRUE) {
        s32 i;
        s32 y[PC_SETTINGS_TOP_COUNT];
        const u8 *labels[PC_SETTINGS_TOP_COUNT];
        s32 choice;

        labels[PC_SETTINGS_TOP_VIDEO] = sTextVideo;
        labels[PC_SETTINGS_TOP_AUDIO] = sTextAudio;
        labels[PC_SETTINGS_TOP_CONTROLS] = sTextControls;

        PcSettingsShowWindow(sTextPcSettings, PC_SETTINGS_TOP_COUNT, 12, 2, 2, DEFAULT_MENU_ENTRY_HEIGHT);
        for (i = 0; i < PC_SETTINGS_TOP_COUNT; i++) {
            y[i] = GetMenuEntryYCoord(&sMenu, i);
            PrintStringOnWindow(8, y[i], labels[i], 0, 0);
        }
        sub_80073E0(0);

        choice = PcSettingsVerticalInput();
        if (choice < 0)
            return;
        if (choice == PC_SETTINGS_TOP_VIDEO)
            PcSettingsRunVideo();
        else if (choice == PC_SETTINGS_TOP_AUDIO)
            PcSettingsRunAudio();
        else if (choice == PC_SETTINGS_TOP_CONTROLS)
            PcSettingsRunControls();
    }
}

static void PcSettingsRun(void)
{
    PcSettingsRunTop();
    PcSettingsClearWindows();
    PcSettingsTick();
}

void ShowPcSettingsMenu_AtTitle(void)
{
    PcSettingsRun();
}

#endif // PLATFORM_PC
