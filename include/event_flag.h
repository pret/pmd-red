#ifndef GUARD_EVENT_FLAG_H
#define GUARD_EVENT_FLAG_H

// size: 0x8
struct UnkEventStruct
{
    /* 0x0 */ s16 *unk0;
    /* 0x4 */ u8 *unk4;
};

void sub_8001B88(s32 param_1,u32 *param_2,u32 *param_3);
void ScenarioCalc(s16 param_1, s32 param_2, s32 param_3);
bool8 sub_8001CC4(s16 param_1, u32 param_2, s32 param_3);
bool8 sub_8001D08(s16 param_1, u32 param_2, s32 param_3);
bool8 sub_8001D44(s16 param_1, u32 param_2, s32 param_3);
void sub_8001D88(void);
u32 _FlagCalc(s32 param_1, s32 param_2, u32 operation);
u8 _FlagJudge(s32 param_1, s32 param_2, u32 operation);
u32 FlagCalc(s32 r0, s32 r1, u32 operation);
void sub_800226C(u32 param_1, s16 param_2, s32 param_3, u32 operation);
void sub_80022A0(u32 param_1, s16 param_2, s16 param_3, u32 operation);
u8 FlagJudge(s32 r0, s32 r1, u32 operation);
u8 sub_80022F8(u32 param_1, s16 param_2, s32 param_3, u32 operation);
u8 sub_8002318(u32 param_1, s16 param_2, s16 param_3, u32 operation);
bool8 sub_80023E4(u32 param_1);
u8 sub_8002658(s16 param_1);
s16 sub_8002694(u8 param_1);
bool8 sub_80026CC(s16 r0);
void sub_80026E8(s16 r0);
bool8 sub_8002700(void *r0);
bool8 sub_8002718(u8 *r0);
void sub_8002758(s32 r0);
u8 sub_800276C(void);

// event_flag.s
extern u32 sub_8001658(u32, u32);

#endif // GUARD_EVENT_FLAG_H
