#ifndef GUARD_PLAY_TIME_H
#define GUARD_PLAY_TIME_H

struct PlayTimeStruct
{
    s16 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};


extern struct PlayTimeStruct *gPlayTimeRef;
extern struct PlayTimeStruct gPlayTime;

void IncrementPlayTime(struct PlayTimeStruct *Time);
void ResetPlayTime(struct PlayTimeStruct *Time);
struct PlayTimeStruct *GetPlayTime(void);
void DeconstructPlayTime(struct PlayTimeStruct *r0, u32 *outHours, u32 *outMinutes, u32 *outSeconds);
void InitializePlayTime(void);


#endif // GUARD_PLAY_TIME_H  

