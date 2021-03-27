#include "global.h"
#include "main_menu.h"
#include "input.h"

struct unkData
{
    u8 unk0[24];
};


extern struct MainMenu *gUnknown_203B348;
extern struct unkData gUnknown_80E59A8;
extern void sub_8006518(struct unkData *);
extern void sub_800641C(struct unkData *, u32, u32);

void sub_8035CC0(struct unkData *dataArray, u32 index)
{
    sub_8006518(dataArray);
    dataArray[index] = gUnknown_80E59A8;
    ResetUnusedInputStruct();
    sub_800641C(dataArray, 1, 1);
}

NAKED
void sub_8035CF4(void * Menu, u32 index, u8 r2)
{
	asm_unified("\tpush {lr}\n"
	"\tadds r3, r0, 0\n"
	"\tlsls r0, r1, 2\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 4\n"
	"\tadds r0, r3\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x4C\n"
	"\tstrb r2, [r1]\n"
	"\tadds r2, r0, 0\n"
	"\tadds r2, 0x4D\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r2]\n"
	"\tsubs r1, 0x2\n"
	"\tstr r1, [r0, 0x48]\n"
	"\tbl sub_8012EBC\n"
	"\tpop {r0}\n"
	"\tbx r0");
}

void sub_8035D1C(void)
{
    gUnknown_203B348->unk38 = -1;
}

void sub_8035D30(s32 r0)
{
    gUnknown_203B348->unk38 = r0;
}

s16 sub_8035D3C(void)
{
    return gUnknown_203B348->unk38;
}

s32 *sub_8035D4C(void)
{
    return &gUnknown_203B348->currMenu;
}

void sub_8035D58(void)
{
    gUnknown_203B348->unk3C = -1;
}

void sub_8035D68(s32 r0)
{
    gUnknown_203B348->unk3C = r0;
}

s32 sub_8035D74(void)
{
    return gUnknown_203B348->unk3C;
}
