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
struct PlayTimeStruct *sub_8094FA0(void);
void DeconstructPlayTime(struct PlayTimeStruct *r0, u32 *outHours, u32 *outMinutes, u32 *outSeconds);
void sub_8094F88(void);


#endif // TIME_H  

