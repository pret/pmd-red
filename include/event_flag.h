#ifndef GUARD_EVENT_FLAG_H
#define GUARD_EVENT_FLAG_H

struct UnkEventStruct
{
    /* 0x0 */ s16 *unk0;
    /* 0x4 */ u32 *unk4;
};


bool8 sub_80026CC(s16 r0);
void sub_80026E8(s16 r0);
bool8 sub_8002700(void *r0);
bool8 sub_8002718(u8 *r0);
void sub_8002758(u32 *r0);
u8 sub_800276C(void);

#endif // GUARD_EVENT_FLAG_H
