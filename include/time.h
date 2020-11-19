#ifndef TIME_H
#define TIME_H

struct PlayTimeStruct
{
    s16 unk0;
    u8 hours;
    u8 minutes;
    u8 seconds;
};

void sub_8094FB4(struct PlayTimeStruct *Time);
void ResetPlayTime(struct PlayTimeStruct *Time);
struct PlayTimeStruct *sub_8094FA0(void);
void sub_8094F88(void);


#endif // TIME_H  

