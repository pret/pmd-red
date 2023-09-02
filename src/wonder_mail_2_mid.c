#include "global.h"
#include "constants/input.h"
#include "constants/mailbox.h"
#include "code_800D090.h"
#include "input.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "pokemon_mail.h"
#include "wonder_mail.h"
#include "code_802C39C.h"
#include "menu_input.h"
#include "code_80118A4.h"

bool8 IsMailSlotEmpty(u8);
extern s32 CountPelipperBoardSlots(void);
extern void sub_802C328(void);
extern void DrawPelipperBoardJobMenu(void);
extern u8 HasNoPelipperBoardJobs(void);

extern WonderMail *GetPelipperBoardSlotInfo(u32);
extern void sub_803B35C(WonderMail *, u32 *);
extern u8 gBulletinBoardText[];
extern bool8 IsMailinJobSlot(WonderMail *);
extern void CreateRescueTitle(unkStruct_802C39C *);

struct unkStruct_203B2D8
{
    // size: 0xA4
    u8 unk0[4];
    MenuInputStruct input;
    u32 unk38;
    UnkTextStruct2 *unk3C;
    UnkTextStruct2 unk40[4];
    u8 unkA0[4];
};

extern struct unkStruct_203B2D8 *gUnknown_203B2D8;

struct unkStruct_203B2E0
{
    // size: 0xA8
    u8 unk0[0x8];
    MenuInputStruct input;
    s32 unk3C;
    UnkTextStruct2 *unk40;
    UnkTextStruct2 unk44[4];
    u8 unkA4[4];
};
extern struct unkStruct_203B2E0 *gUnknown_203B2E0;

extern UnkTextStruct2 gUnknown_80DFCB4;
extern UnkTextStruct2 gUnknown_80DFC9C;

extern u16 gUnknown_203B2E4;

extern WonderMail *GetMailboxSlotInfo(u8);
extern PokemonStruct1 *GetPlayerPokemonStruct(void);
extern u8 gMailboxText[];
extern u8 gAvailablePokemonNames[];
extern void PrintPokeNameToBuffer(u8 *buffer, PokemonStruct1 *pokemon);
extern void sub_803B6B0(u32, u32, u32, u32);

void CreateMailMenu(void)
{
    WonderMail *mail;
    s32 y;
    s32 index;
    unkStruct_802C39C local;
    u8 buffer [128];

    sub_8008C54(gUnknown_203B2D8->unk38);
    sub_80073B8(gUnknown_203B2D8->unk38);
    xxx_call_draw_string(gUnknown_203B2D8->input.unk1E * 8 + 10,0,gMailboxText,gUnknown_203B2D8->unk38,0);
    for (index = 0; index < gUnknown_203B2D8->input.unk1A; index++) {
        mail = GetMailboxSlotInfo(gUnknown_203B2D8->unk0[(gUnknown_203B2D8->input.unk1E * gUnknown_203B2D8->input.unk1C) + index]);
        local.unk0[0] = gUnknown_203B2D8->unk38;
        local.y = sub_8013800(&gUnknown_203B2D8->input, index);
        if (mail->mailType == MAIL_TYPE_UNK1) {
            y = sub_8013800(&gUnknown_203B2D8->input, index);
            sub_803B6B0(10,y,6,gUnknown_203B2D8->unk38);
            PrintPokeNameToBuffer(gAvailablePokemonNames, GetPlayerPokemonStruct());
            sprintfStatic(buffer, GetPokemonMailHeadline(mail->unk4.dungeon.floor), gAvailablePokemonNames);
            xxx_call_draw_string(0x15,y,buffer,gUnknown_203B2D8->unk38,0);
        }
        else {
            sub_803B35C(mail,local.unk0);
            if (IsMailinJobSlot(mail)) {
                local.unk43 = 2;
            }
            CreateRescueTitle(&local);
        }
    }
    sub_80073E0(gUnknown_203B2D8->unk38);
}

s32 CountEmptyMailSlots(void)
{
    s32 mailSlots;
    s32 index;

    mailSlots = 0;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(!IsMailSlotEmpty(index))
        {
            gUnknown_203B2D8->unk0[mailSlots] = index;
            mailSlots++;
        }
    }
    return mailSlots;
}

bool8 HasNoMailinMailbox(void)
{
    s32 index;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(!IsMailSlotEmpty(index))
            return FALSE;
    }
    return TRUE;
}


bool8 sub_802C10C(s32 param_1,UnkTextStruct2_sub *param_2,s32 param_3)
{
  if (HasNoPelipperBoardJobs() != 0) {
      return FALSE;
  }
  else
  {
    if (gUnknown_203B2E0 == NULL)
      gUnknown_203B2E0 = MemoryAlloc(sizeof(struct unkStruct_203B2E0), 8);

    gUnknown_203B2E0->unk3C = param_1;
    gUnknown_203B2E0->unk40 = &gUnknown_203B2E0->unk44[param_1];
    sub_8006518(gUnknown_203B2E0->unk44);

    gUnknown_203B2E0->unk44[gUnknown_203B2E0->unk3C] = gUnknown_80DFCB4;
    gUnknown_203B2E0->unk40->unk14 = gUnknown_203B2E0->unkA4;

    if (param_2 != NULL)
      gUnknown_203B2E0->unk44[gUnknown_203B2E0->unk3C].unk8 = *param_2;

    sub_8012D34(gUnknown_203B2E0->unk40,param_3);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2E0->unk44, TRUE, TRUE);
    sub_8013848(&gUnknown_203B2E0->input,CountPelipperBoardSlots(),param_3,param_1);
    gUnknown_203B2E0->input.menuIndex = gUnknown_203B2E4;
    sub_8013984(&gUnknown_203B2E0->input);
    sub_802C328();
    DrawPelipperBoardJobMenu();
    return TRUE;
  }
}

u32 sub_802C1E4(u8 param_1)
{
  if (param_1 == '\0') {
    sub_8013660(&gUnknown_203B2E0->input);
    return 0;
  }
  else {
    switch(GetKeyPress(&gUnknown_203B2E0->input))
    {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B2E0->input,1)) {
                sub_802C328();
                DrawPelipperBoardJobMenu();
                return 1;
            }
            else {
                return 0;
            }
    }
  }
}

u8 sub_802C26C(void)
{
    return gUnknown_203B2E0->unk0[(gUnknown_203B2E0->input.unk1E * gUnknown_203B2E0->input.unk1C) + gUnknown_203B2E0->input.menuIndex];
}

void sub_802C28C(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2E0->unk44, FALSE, FALSE);
    gUnknown_203B2E0->input.unk22 = CountPelipperBoardSlots();
    sub_8013984(&gUnknown_203B2E0->input);
    sub_802C328();
    DrawPelipperBoardJobMenu();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B2E0->input);
}

void sub_802C2D4(void)
{
    if(gUnknown_203B2E0 != NULL)
    {
        gUnknown_203B2E4 = gUnknown_203B2E0->input.menuIndex;
        gUnknown_203B2E0->unk44[gUnknown_203B2E0->unk3C] = gUnknown_80DFC9C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2E0->unk44, TRUE, TRUE);
        MemoryFree(gUnknown_203B2E0);
        gUnknown_203B2E0 = NULL;
    }
}

NAKED
void sub_802C328(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _0802C398\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x28]\n"
	"\tadds r0, 0xA4\n"
	"\tmovs r2, 0\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x26]\n"
	"\tadds r0, 0xA5\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xA6\n"
	"\tmovs r1, 0xC\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xA7\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x22\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0x18\n"
	"\tbl sub_8009614\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x3C]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x52\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x3C]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x54\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x44\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0802C398: .4byte gUnknown_203B2E0");
}

void DrawPelipperBoardJobMenu(void)
{
    u32 slotIndex;
    WonderMail *mail;
    s32 iVar4;
    s32 x;
    s32 index;
    unkStruct_802C39C local;

    sub_8008C54(gUnknown_203B2E0->unk3C);
    sub_80073B8(gUnknown_203B2E0->unk3C);
    iVar4 = gUnknown_203B2E0->input.unk1E * 8;
    x = iVar4;
    x += 10;
    xxx_call_draw_string(x,0,gBulletinBoardText,gUnknown_203B2E0->unk3C,0);
    iVar4 += 4;
    x = iVar4 + gUnknown_203B2E0->unkA4[2] * 8;
    sub_8012BC4(x,0,gUnknown_203B2E0->input.unk1E + 1,2,7,gUnknown_203B2E0->unk3C);

    for(index = 0; index < gUnknown_203B2E0->input.unk1A; index++)
    {
        slotIndex = (gUnknown_203B2E0->unk0[gUnknown_203B2E0->input.unk1E * gUnknown_203B2E0->input.unk1C + index]);
        mail = GetPelipperBoardSlotInfo(slotIndex);
        local.unk0[0] = gUnknown_203B2E0->unk3C;
        local.y = sub_8013800(&gUnknown_203B2E0->input,index);
        sub_803B35C(mail,local.unk0);
        if (IsMailinJobSlot(GetPelipperBoardSlotInfo(slotIndex))) {
            local.unk43 = 2;
        }
        CreateRescueTitle(&local);
    }
    sub_80073E0(gUnknown_203B2E0->unk3C);
}
