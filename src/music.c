#include "global.h"
#include "m4a.h"

#define NUM_BG_SONGS 128

extern u8 sub_80023E4(u32);
extern void sub_80118C4(u16);
extern void sub_809C730();

extern bool8 DisableInterrupts();
extern bool8 EnableInterrupts();

extern void sub_800C3F8(u16, u16);
extern void Random();
extern void sub_800BA5C();
extern void xxx_update_bg_sound_input();

extern u16 gUnknown_202D688;
extern u16 gUnknown_202D68A;
extern u16 gUnknown_202D690;
extern u8 gUnknown_202D694;
extern u32 gUnknown_203B0B8;
extern u16 gRawKeyInput;

bool8 IsBGSong(u32);
bool8 sub_800CAAC(u32);
bool8 sub_800CACC(u32);
u16 sub_800CAE0(u16);

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

u8 sub_800CA38(u32 songIndex)
{
    if(IsBGSong(songIndex))
    {
        if(sub_800CAE0(songIndex) == 0)
        {
            return 1;
        }
    }
    if(sub_800CACC(songIndex))
    {
        if(sub_800CAE0(songIndex) == 1)
        {
            return 1;
        }
    }
    else if(sub_800CAAC(songIndex))
    {
        if(sub_800CAE0(songIndex) > 1)
        {
            return 1;
        }
    }
    return 0;
}

void nullsub_19(void)
{
}

bool8 IsBGSong(u32 songIndex)
{
    if(songIndex <= NUM_BG_SONGS)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_800CAAC(u32 songIndex)
{
    if(songIndex - 300 <= 639)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_800CACC(u32 songIndex)
{
    if(songIndex - 200 <= 19)
    {
        return TRUE;
    }
    return FALSE;
}

u16 sub_800CAE0(u16 songIndex)
{
    return gSongTable[songIndex].ms;
}

bool8 sub_800CAF0(u16 songIndex)
{
    // Had to cast this.. m4a_internal header has this as u32
    if((u16)gMPlayTable[songIndex].info->status == 0)
    {
        return 0;
    }
    return 1;
}

void nullsub_20(u16 songIndex)
{
}

void nullsub_21(void)
{
}

void sub_800CB20(void)
{
    sub_800BA5C();
    gUnknown_203B0B8++;
    if((gRawKeyInput & (A_BUTTON | SELECT_BUTTON)) != 0)
    {
        Random();
    }
    Random();
}

u32 sub_800CB50(void)
{
    return gUnknown_203B0B8;
}

void nullsub_180(void)
{
}

void xxx_call_update_bg_sound_input(void)
{
    xxx_update_bg_sound_input();
}

void nullsub_181(void)
{
}

u32 sub_800CB70(void)
{
    return 0;
}

