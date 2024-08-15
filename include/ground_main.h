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

#if !defined(NONMATCHING) && defined(GROUND_SCRIPT_INCOMPLETE_DECLARATIONS)
// Workaround for ExecuteScriptCommand relying on s32 behavior of arguments
// Arguments could be left fully implicit (as I think they were in the original code),
// but this way at least verifies the argument count
bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2);
bool8 GroundMainRescueRequest(s32 r0, s32 r1);
#else
bool8 GroundMainGroundRequest(s16 r0, u32 r1, s32 r2);
bool8 GroundMainRescueRequest(s16 r0, u32 r1);
#endif

bool32 GroundMainGameEndRequest(u32 r0);
bool32 GroundMainGameCancelRequest(u32 r0);
bool8 sub_8098D80(u32 speed);

extern GroundConversionStruct gGroundConversion_811BAF4[10];

#endif // GUARD_GROUND_MAIN_H
