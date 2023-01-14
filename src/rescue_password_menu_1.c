#include "global.h"
#include "memory.h"
#include "input.h"
#include "item.h"
#include "text.h"
#include "rescue_password_menu.h"

extern struct RescuePasswordMenu *gRescuePasswordMenu;
extern void AddSprite(struct unkSprite *, u32, u32, u32);
extern void xxx_draw_string_80144C4(void);

void sub_80391F8(void)
{
  struct unkSprite *iVar2;
  u32 temp;
  u32 temp2;

  iVar2 = &gRescuePasswordMenu->unk208;
  
  temp = (iVar2->unk20A & 0xfe00); 
  iVar2->unk20A = temp | 0x70;

  temp2 = 0x700;
  temp = (iVar2->unk20E & 0xf);
  iVar2->unk20E = temp | temp2;

  if ((gRescuePasswordMenu->unk210 & 8) != 0) {
    AddSprite(iVar2,0x100,0,0);
  }
  xxx_draw_string_80144C4();
  gRescuePasswordMenu->unk210 += 1;
}
