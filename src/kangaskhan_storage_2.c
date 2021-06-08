#include "global.h"
#include "input.h"
#include "memory.h"
#include "text.h"
#include "item.h"
#include "kangaskhan_storage.h"

extern struct unkStruct_203B208 *gUnknown_203B208;

struct unkStruct_203B20C
{
    u32 state;
    u8 unk4[0x10];
    u32 unk14;
    u32 unk18;
    u32 unk1C;
};
extern struct unkStruct_203B20C *gUnknown_203B20C;

extern void sub_8017F10(u32);
extern void sub_8018588(void);
extern void sub_8018620(void);
extern void sub_8018904(void);
extern void sub_8018AC8(void);
extern void sub_80186F8(void);
extern void sub_8018854(void);
extern void sub_80189C8(void);
extern void sub_8018AE4(void);


extern void sub_8017F28();
extern void sub_8018100();
extern void UpdateKangaskhanStorageState(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_801B450();
extern u32 sub_801B410(void);

extern u8 sub_8012FD8(u32 *r0);
extern void sub_8013114(u32 *, s32 *);
extern void sub_801CBB8();
extern void sub_801CA08();

void sub_8017D24(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801CA08();
    if (sub_8012FD8(&gUnknown_203B208->unk58) == 0) {
        sub_8013114(&gUnknown_203B208->unk58, &menuAction);
        if(menuAction != 1) gUnknown_203B208->unk20 = menuAction;
    }

    switch(menuAction)
    {
      case 3:
        if (sub_8090A34() > 0x13)
        {
            sub_801CBB8();
            UpdateKangaskhanStorageState(0x6);
        }
        else
        {
            if(sub_8090A60(gUnknown_203B208->itemIndex))
                UpdateKangaskhanStorageState(0x18);
            else
                UpdateKangaskhanStorageState(0x1B);
        }
        break;
      case 6:
        UpdateKangaskhanStorageState(0x1A);
        break;
      case 1:
        UpdateKangaskhanStorageState(0x17);
        break;
    }
}

void sub_8017DC0(void)
{
    switch(sub_801B410())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(0xE);
            break;
    }
}

void sub_8017DDC(void)
{
    switch(sub_801B410())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(0x17);
            break;
    }
}

void sub_8017DF8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateKangaskhanStorageState(gUnknown_203B208->unk8);
    }
}

u32 sub_8017E1C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    gUnknown_203B20C = MemoryAlloc(0x150, 8);
    gUnknown_203B20C->unk14 = 0;
    gUnknown_203B20C->unk18 = 0;
    gUnknown_203B20C->unk1C = 0;
    sub_8017F10(0);
    return 1;
}

u32 sub_8017E54(void)
{
  switch(gUnknown_203B20C->state)
  {
      case 0:
        sub_8017F10(1);
        break;
      case 1:
        sub_8018588();
        break;
      case 4:
      case 5:
        sub_8018620();
        break;
      case 6:
        sub_8018904();
        break;
      case 7:
        sub_8018AC8();
        break;
      case 10:
      case 11:
        sub_80186F8();
        break;
      case 12:
        sub_8018854();
        break;
      case 13:
        sub_80189C8();
        break;
      case 14:
        sub_8018AE4();
        break;
      case 3:
        return 3;
  }
  return 0;
}

void sub_8017EF4(void)
{
    if(gUnknown_203B20C != NULL)
    {
        MemoryFree(gUnknown_203B20C);
        gUnknown_203B20C = NULL;
    }
}

void sub_8017F10(u32 newState)
{
    gUnknown_203B20C->state = newState;
    sub_8017F28();
    sub_8018100();
}
