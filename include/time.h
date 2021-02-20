#ifndef TIME_H
#define TIME_H

struct PlayTimeStruct
{
    s16 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};

void IncrementPlayTime(struct PlayTimeStruct *Time);
void ResetPlayTime(struct PlayTimeStruct *Time);
struct PlayTimeStruct *GetPlayTime(void);
void DeconstructPlayTime(struct PlayTimeStruct *r0, u32 *outHours, u32 *outMinutes, u32 *outSeconds);
void InitializePlayTime(void);


#endif // TIME_H  

