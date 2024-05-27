#ifndef GUARD_GROUND_MAIN_H
#define GUARD_GROUND_MAIN_H

// size: 0xC
typedef struct unkStruct_811BAF4
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    /* 0x8 */ u8 *text;
} unkStruct_811BAF4;

bool8 sub_8098F88(void);
const char *sub_8098FB4(void);
bool8 GroundMainGroundRequest(s16 r0, u32 r1, s32 r2);

#endif // GUARD_GROUND_MAIN_H
