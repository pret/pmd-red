#ifndef GUARD_PLAY_TIME_H
#define GUARD_PLAY_TIME_H

#include "data_serializer.h"

struct PlayTimeStruct
{
    s16 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};


extern struct PlayTimeStruct *gPlayTimeRef;
extern struct PlayTimeStruct gPlayTime;

void InitializePlayTime(void);
struct PlayTimeStruct *GetPlayTime(void);
void ResetPlayTime(struct PlayTimeStruct *Time);
void IncrementPlayTime(struct PlayTimeStruct *Time);
void DeconstructPlayTime(struct PlayTimeStruct *r0, u32 *outHours, u32 *outMinutes, u32 *outSeconds);
void WritePlayTimeBits(DataSerializer *r0);
void ReadPlayTimeBits(DataSerializer *r0);

#endif // GUARD_PLAY_TIME_H

