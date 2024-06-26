#ifndef GUARD_GROUND_SCRIPT_H
#define GUARD_GROUND_SCRIPT_H

typedef struct GroundScript_ExecutePP_3
{
    // size: 0xC
    u8 *scriptPointer;
    s16 scriptType;
    s16 unk6;
    u8 unk8;
} GroundScript_ExecutePP_3;

typedef struct __attribute__((packed)) GroundScript_ExecutePP_1_sub
{
    // size: 0x60
    /* 0x0 */ s16 scriptType;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 *scriptPointer1;
    /* 0x8 */ u8 *scriptPointer2;
    /* 0xC */ u16 unkC;
    /* 0xE */ u8 unkE;
    /* 0xF */ u8 fillF;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 *unk14;
    /* 0x18 */ u8 fill18[0x22 - 0x18];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u32 unk26;
    u8 fill50[0x60 - 0x2A];
} GroundScript_ExecutePP_1_sub;

typedef void (*Callback)(u32, void *);
typedef struct GroundScript_ExecutePP_1_sub2
{
    Callback callbacks[10]; // IDK the size..
} GroundScript_ExecutePP_1_sub2;

// size: 0x110
typedef struct GroundScript_ExecutePP_1
{
    GroundScript_ExecutePP_1_sub2 *unk0;
    u32 unk4;
    u32 fill8;
    u32 unkC;
    u16 unk10;
    u8 unk12;
    u8 *unk14[4];
    GroundScript_ExecutePP_1_sub unk24;
    GroundScript_ExecutePP_1_sub unk84;
    u16 unkE4;
    u8 fillE8[0x110 - 0xE8];
} GroundScript_ExecutePP_1;

bool8 GroundScript_ExecutePP(GroundScript_ExecutePP_1 *, s32 *, GroundScript_ExecutePP_3 *, const DebugLocation *unused);

#endif // GUARD_GROUND_SCRIPT_H