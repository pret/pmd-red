#ifndef GUARD_GROUND_MAIN_H
#define GUARD_GROUND_MAIN_H

// size: 0xC
typedef struct GroundConversionStruct
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    /* 0x8 */ u8 *text;
} GroundConversionStruct;

bool8 sub_8098F88(void);
const char *sub_8098FB4(void);

bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2);
bool8 GroundMainRescueRequest(s32 r0, s32 r1);
bool32 GroundMainGameEndRequest(u32 r0);
bool32 GroundMainGameCancelRequest(u32 r0);
bool8 sub_8098D80(u32 speed);

extern GroundConversionStruct gGroundConversion_811BAF4[10];

#endif // GUARD_GROUND_MAIN_H
