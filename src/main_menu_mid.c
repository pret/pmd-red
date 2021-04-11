#include "global.h"
#include "main_menu.h"
#include "input.h"

struct unkData
{
    u8 unk0[24];
};

struct unkSubStruct
{
    u32 unk0;
    u32 unk4;
};

struct unkStruct_203B34C
{
    // size: 0x1A8
    u32 unk0;
    u32 unk4;
    struct unkSubStruct *unk8; // Array of menu choices??
    u8 fillC[0x30 - 0xC];
    s16 unk30;
    u8 fill32[0x144 - 0x32];
    struct unkData unk144[4];
    /* 0x1A4 */ u32 currMenuChoice;
};

extern struct unkStruct_203B34C *gUnknown_203B34C;



extern struct MainMenu *gMainMenu;
extern struct unkData gUnknown_80E59A8;
extern struct unkData gUnknown_80E59C8;
extern void sub_8006518(struct unkData *);
extern void sub_800641C(struct unkData *, u32, u32);
extern void *MemoryAlloc(u32, u32);
extern void MemoryFill8(u8*, u8, s32);
extern void MemoryFree(void *);

extern u8 SetMainMenuText();
extern void SetMainMenuItems();

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
    gMainMenu->unk38 = -1;
}

void sub_8035D30(s32 r0)
{
    gMainMenu->unk38 = r0;
}

s16 sub_8035D3C(void)
{
    return gMainMenu->unk38;
}

struct MainMenu *GetMainMenu(void)
{
    return gMainMenu;
}

void sub_8035D58(void)
{
    gMainMenu->unk3C = -1;
}

void sub_8035D68(s32 r0)
{
    gMainMenu->unk3C = r0;
}

s32 sub_8035D74(void)
{
    return gMainMenu->unk3C;
}

NAKED
void sub_8035D80(void *r0)
{
    asm_unified(
	"\tldr r1, _08035D90\n"
	"\tldr r2, [r1]\n"
	"\tldr r1, [r0, 0x4]\n"
	"\tldr r0, [r0]\n"
	"\tstr r0, [r2, 0x30]\n"
	"\tstr r1, [r2, 0x34]\n"
	"\tbx lr\n"
	"\t.align 2, 0\n"
"_08035D90: .4byte gMainMenu");
}

u8 *sub_8035D94(void)
{
    return &gMainMenu->unk30;
}


void sub_8035DA0(void)
{
    gMainMenu->unk30 = 0;
    gMainMenu->unk34 = 0;
}

u32 sub_8035DB4(u32 r0)
{
    u32 returnVar = 8;
    switch(r0)
    {
    case MENU_COMMUNICATION_1:
        returnVar = 0;
        break;
    case MENU_COMMUNICATION_2:
        returnVar = 1;
        break;
    case 0x15:
        returnVar = 2;
        break;
    case 0x16:
        returnVar = 3;
        break;
    case 0x17:
        returnVar = 4;
        break;
    case 0x18:
        returnVar = 5;
        break;
    case 0x19:
        returnVar = 6;
        break;
    case 0x1a:
        returnVar = 7;
    }
    return returnVar;
}

void DrawMainMenu(void)
{
    s32 iVar3;

    if(gUnknown_203B34C == NULL)
    {
        gUnknown_203B34C = MemoryAlloc(0x1A8, 8);
        MemoryFill8((u8 *)gUnknown_203B34C, 0, 0x1A8);
    }

    for(iVar3 = 0; iVar3 < 4; iVar3++)
    {
        gUnknown_203B34C->unk144[iVar3] = gUnknown_80E59C8;
    }

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B34C->unk144, 1, 1);
    SetMainMenuItems();
    gUnknown_203B34C->currMenuChoice = -1;

    if(SetMainMenuText() != 0)
    {
        sub_8035CF4(&gUnknown_203B34C->unk4,2,0);
    }

    sub_8035CF4(&gUnknown_203B34C->unk4,0,1);
    gUnknown_203B34C->unk0 = 1;
}

void CleanMainMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    if(gUnknown_203B34C != NULL)
    {
        MemoryFree(gUnknown_203B34C);
        gUnknown_203B34C = NULL;
    }
}
