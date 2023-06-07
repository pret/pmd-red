#include "global.h"
#include "constants/wonder_mail.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "dungeon.h"
#include "pokemon.h"
#include "code_8094F88.h"
#include "code_800D090.h"
#include "code_802C39C.h"

struct unkStruct_203B324
{
    // size: 0x78
    u8 fill0[0xC];
    u8 mailIndex;
    u32 unk10;
    struct UnkTextStruct2 *unk14;
    struct UnkTextStruct2 unk18[4];
};
extern struct unkStruct_203B324 *gUnknown_203B324;
extern struct unkStruct_203B480 *gUnknown_203B480;


const struct UnkTextStruct2 gUnknown_80E0900 = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const u8 DATA_80E0918[] = {0x01, 0x00, 0x12, 0x00};

const struct UnkTextStruct2 gUnknown_80E091C = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x00, 0x02, 0x00,
    0x1A, 0x10,
    0x10, 0x00,
    DATA_80E0918
};

const u8 gUnknown_80E0934[] = "ID:";
const u8 gUnknown_80E0938[] = "%-4d";
static const u8 wonder_mail_fill[] = "pksdir0";

extern void sub_8030DD4(void);
extern void sub_801317C(void *);
extern void PlayMenuSoundEffect(u32);
extern u32 sub_8012A64(void *, u32);
extern void CreateRescueDescription(struct unkStruct_802C39C *);
extern void xxx_call_draw_string(u32, u32, const char *, u32, u32);
extern void sub_80073E0(u32);
extern void sub_80073B8(u32);

void sub_8030E2C(void);
void sub_8030E48(void);

bool8 sub_8030D40(u8 mailIndex, s32 param_2)
{ 
  gUnknown_203B324 = MemoryAlloc(sizeof(struct unkStruct_203B324), 8);
  gUnknown_203B324->mailIndex = mailIndex;
  sub_801317C(gUnknown_203B324);
  gUnknown_203B324->unk10 = param_2;
  gUnknown_203B324->unk14 = &gUnknown_203B324->unk18[param_2];
  sub_8006518(gUnknown_203B324->unk18);
  gUnknown_203B324->unk18[gUnknown_203B324->unk10] = gUnknown_80E091C;
  sub_8030DD4();
  return TRUE;
}

u8 sub_8030DA0(void)
{ 
  switch(sub_8012A64(gUnknown_203B324, gUnknown_203B324->unk10))
  {
    case 2:
        PlayMenuSoundEffect(1);
        return 2;
    case 1:
        PlayMenuSoundEffect(0);
        return 3;
    default:
        return 0;
  }
}

void sub_8030DD4(void)
{
    sub_8030E2C();
    sub_8030E48();
}

void sub_8030DE4(void)
{ 
  if(gUnknown_203B324 != NULL)
  {
      gUnknown_203B324->unk18[gUnknown_203B324->unk10] = gUnknown_80E0900;
      ResetUnusedInputStruct();
      sub_800641C(gUnknown_203B324->unk18, 1, 1);
      MemoryFree(gUnknown_203B324);
      gUnknown_203B324 = NULL;
  }
}

void sub_8030E2C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B324->unk18, 1, 1);
}

void sub_8030E48(void)
{
  u16 uVar2;
  struct unkStruct_203B480 *mail;
  struct unkStruct_802C39C stack;
  u8 buffer [256];
  
  mail = &gUnknown_203B480[gUnknown_203B324->mailIndex];
  sub_80073B8(gUnknown_203B324->unk10);
  stack.unk0[0] = gUnknown_203B324->unk10;
  stack.unk40 = 7;
  stack.unk42 = 0;
  stack.unk44 = 0;
  stack.dungeon = &mail->dungeon;
  stack.playerName = mail->playerName;
  stack.clientSpecies = mail->clientSpecies;
  stack.targetSpecies = mail->clientSpecies;
  stack.targetItem = ITEM_NOTHING;
  if (mail->unk20.id == ITEM_NOTHING) {
    stack.unk2E = 5;
  }
  else {
    stack.unk2E = 2;
    stack.unk34 = mail->unk20.id;
  }
  switch(mail->mailType)
  {
    case 2:
    case WONDER_MAIL_TYPE_AOK:
        stack.unk41 = 10;
        break;
    case 5:
        stack.unk41 = 11;
        break;
    case WONDER_MAIL_TYPE_NONE:
    default:
        stack.unk41 = 9;
        break;
  }
  CreateRescueDescription(&stack);
  uVar2 = mail->unk10.unk10_u16 % 10000;
  xxx_call_draw_string(10,0x68,gUnknown_80E0934,gUnknown_203B324->unk10,0); // ID:
  sprintfStatic(buffer,gUnknown_80E0938,uVar2); // %-4d
  xxx_call_draw_string(0x44,0x68,buffer,gUnknown_203B324->unk10,0);
  sub_80073E0(gUnknown_203B324->unk10);
}
