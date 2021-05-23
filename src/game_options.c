#include "global.h"
#include "gUnknown_203B46C.h"

extern struct UnkSaveStruct1 *gUnknown_203B46C;
extern struct UnkSaveStruct1 gUnknown_2038C70;
extern void sub_8094C14();

void LoadGameOptions(void)
{
    gUnknown_203B46C = &gUnknown_2038C70;
}

struct UnkSaveStruct1 * GetGameOptions(void)
{
    return &gUnknown_2038C70;
}

void InitializeGameOptions(u8 r0)
{
    gUnknown_203B46C->unk8 = 0;
    if(r0 != 0)
    {
        gUnknown_203B46C->playerGender = 0;
    }
    gUnknown_203B46C->unk9 = 0;
    gUnknown_203B46C->unkA = 0;
    gUnknown_203B46C->unk0 = 0; 
    gUnknown_203B46C->unk1 = 1;
    gUnknown_203B46C->unk2 = 1;
    gUnknown_203B46C->unk3 = 1;
    gUnknown_203B46C->unk4 = 1;
    gUnknown_203B46C->unkC = 0;
    sub_8094C14();
}
