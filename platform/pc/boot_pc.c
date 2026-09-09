// platform/pc/boot_pc.c — host side of the boot sequence (warning, logos, intro).
//
// The visible boot scenes themselves are the game's DEMO ground scripts; this
// file only owns the host-side bookkeeping: the per-scene frame budget and the
// input/quit skip that src/ground_main.c polls once per rendered frame. Nothing
// here depends on game headers, so it compiles cleanly in the backend-only
// smoke build too.
#include "gba/gba.h"
#include "gba_shim.h"
#include "boot_pc.h"

static int sSceneActive = 0;
static int sSceneMaxFrames = 0;
static int sSceneFrames = 0;

void Pc_BootSceneBegin(int maxFrames)
{
    sSceneActive = 1;
    sSceneMaxFrames = maxFrames > 0 ? maxFrames : 1;
    sSceneFrames = 0;
}

void Pc_BootSceneEnd(void)
{
    sSceneActive = 0;
    sSceneMaxFrames = 0;
    sSceneFrames = 0;
}

int Pc_BootTick(int inputPressed)
{
    if (!sSceneActive)
        return 0;
    sSceneFrames++;
    if (sSceneFrames > sSceneMaxFrames)
        return 1;
    if (inputPressed)
        return 1;
    if (Pc_QuitRequested())
        return 1;
    return 0;
}