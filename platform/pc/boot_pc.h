// platform/pc/boot_pc.h — host boot-sequence plumbing (PLATFORM_PC only).
//
// The real GBA boot sequence is driven by the game's own DEMO ground scripts
// (warning = DEMO_01 / STARTMODE_14, logos = DEMO_02 / STARTMODE_15, intro+
// title = DEMO_03 / STARTMODE_16, title = DEMO_04 / STARTMODE_17). On the PC
// port these run through the ground engine, so this header only wires the
// host-side knobs: the skip config and a per-scene frame budget / input-skip
// tick that src/ground_main.c consults once per rendered frame.
#ifndef PMDRED_PC_BOOT_PC_H
#define PMDRED_PC_BOOT_PC_H

// Skippable boot stages. Launch args (case-insensitive, with or without a
// leading `--`): SkipWarning, SkipLogos, SkipIntro.
typedef struct PcBootConfig
{
    int skipWarning;
    int skipLogos;
    int skipIntro;
} PcBootConfig;

#ifdef PLATFORM_PC

// Called by src/main_loops.c:Pc_RunBootSequence around each DEMO scene.
void Pc_BootSceneBegin(int maxFrames);
void Pc_BootSceneEnd(void);

// Called once per rendered frame from the ground main loop while a boot scene
// runs. Returns 1 when the scene should end (budget exhausted, the given input
// was pressed, or quit requested). No-op (returns 0) outside boot scenes.
int Pc_BootTick(int inputPressed);

#endif // PLATFORM_PC
#endif // PMDRED_PC_BOOT_PC_H