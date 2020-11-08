#include "global.h"
#include "gba/m4a_internal.h"

extern u8 sub_80023E4(u32);
extern void sub_80118C4(u16);
extern void sub_809C730();

extern bool8 DisableInterrupts();
extern bool8 EnableInterrupts();
extern void m4aSoundVSyncOn();
extern void m4aSongNumStart(u16);
extern void m4aMPlayContinue(struct MusicPlayerInfo *mplayInfo);
extern void m4aSoundVSyncOff();
extern void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo);

extern u16 sub_800CAE0(u16);
extern u8 sub_800CACC(u32);
extern u8 sub_800CAAC(u32);
extern void sub_800C3F8(u16, u16);


extern u16 gUnknown_202D690;
extern u16 gUnknown_202D68A;
extern u16 gUnknown_202D688;
extern u8 gUnknown_202D694;
extern struct MusicPlayerInfo gUnknown_20008F0;


void sub_800C93C(void)
{
    bool8 interrupt_flag;
    u16 temp;

    sub_800C3F8(0x3e5, 0x10);
    sub_800C3F8(0x3e6, 0x10);

    interrupt_flag = DisableInterrupts();
    if(gUnknown_202D690 == 0)
    {
        if(gUnknown_202D68A != 0x3e7)
        {
            temp = gUnknown_202D688 - 1;
            if(temp <= 1)
            {
                if(gUnknown_202D688 == 2)
                {
                    gUnknown_202D694 = gUnknown_202D690;
                }
                else
                {
                    if(gUnknown_202D688 == 1)
                    {
                        gUnknown_202D694 = 1;
                    }
                }
                gUnknown_202D688 = 4;
            }
        }
    }
    m4aMPlayStop(&gUnknown_20008F0);
    m4aSoundVSyncOff();
    if(interrupt_flag)
    {
        EnableInterrupts();
    }
}

void sub_800C9CC(void)
{
    bool8 interrupt_flag = DisableInterrupts();
    m4aSoundVSyncOn();
    if(gUnknown_202D690 == 0)
    {
        if(gUnknown_202D68A != 0x3e7)
        {
            if(gUnknown_202D688 == 4)
            {
                gUnknown_202D688 = 1;
                if(gUnknown_202D694 != 0)
                {
                    m4aSongNumStart(gUnknown_202D68A);
                }
                else
                {
                    m4aMPlayContinue(&gUnknown_20008F0);
                }
            }
        }
    }
    if(interrupt_flag)
    {
        EnableInterrupts();
    }

}

void nullsub_179(void)
{
}

