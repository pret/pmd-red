#ifndef GUARD_CODE_800B5F0_H
#define GUARD_CODE_800B5F0_H

typedef void (*IntrCallback)(void);

extern IntrCallback gIntrCallbacks[6];

void AckInterrupt(u16);
bool8 EnableInterrupts(void);
bool8 DisableInterrupts(void);

// size: 0x8
typedef struct unkStruct_202D648
{
    s16 unk0;
    s16 unk2; // Vcount??
    IntrCallback unk4; // some function... just making it IntrCallback for now
} unkStruct_202D648;

extern s16 gUnknown_203B0A8;
extern s16 gUnknown_203B0AA;
extern s16 gUnknown_203B0AC;
extern s16 gUnknown_203B0AE;

void sub_800B540(void);
void InitIntrTable(const IntrCallback *interrupt_table);
IntrCallback SetInterruptCallback(u32 index, IntrCallback new_callback);
void nullsub_17(void);
void xxx_update_bg_sound_input(void);

void sub_800BA5C(void);

#endif // GUARD_CODE_800B5F0_H
