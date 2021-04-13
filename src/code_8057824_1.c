#include "global.h"
#include "gUnknown_203B418.h"
#include "code_8041D5C.h"
#include "constants/species.h"

extern struct unkStruct_203B418 *gUnknown_203B418;

extern struct unkDungeon_8041D5C *sub_8085480(void);
extern struct unkDungeon_8041D5C *sub_8085680(u32);
extern u8 gUnknown_202E038[0x50];
extern u32 gUnknown_810554C;
extern u32 gUnknown_8105558;
extern u32 gUnknown_81055F4;
extern void sub_808BBA8(struct unkDungeon_8041D5C * );
extern void CopySpeciesNametoBuffer(char *r0, u32 r1);
extern void sub_80855E4(void *);
extern void sub_8041888(u32);
extern void sub_80861B8(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_8083ED8(u32);
extern void sub_803E708(u32, u32);
extern void sub_8052910(u32 *r0);
extern void sub_8083E88(u32);
extern void sub_808BC20(struct unkDungeon_8041D5C *);

extern u32 gUnknown_8105438;
extern u32 gUnknown_81054A0;
extern u32 gUnknown_81054E4;
extern u32 gUnknown_810550C;
extern void sub_80862BC(struct unkDungeon_8041D5C *);
void sub_808BBB8(struct unkDungeon_8041D5C *param_1);
extern void sub_8086448();
extern void sub_808696C();
extern u32 sub_80861F8(u32, struct unkDungeon_8041D5C *, u32);
extern void sub_8086A70(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_80858AC(u32 *, u32);

void sub_808B45C(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x1a);
  sub_8086448();
  sub_803E708(0x40,0x46);
  sub_8052910(&gUnknown_8105438);
  sub_803E708(10,0x46);
  sub_808696C(iVar1);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_81054A0);
  sub_80861F8(0x37,uVar2,1);
  sub_80855E4(sub_80862BC);
  sub_803E708(0x3c,0x46);
  sub_808BBB8(uVar2);
  sub_803E708(0x5a,0x46);
  sub_8052910(&gUnknown_81054E4);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_810550C);
  sub_803E708(10,0x46);
  sub_8086A70(uVar2,0x15e,0x20);
  sub_80858AC(&iVar1->unkC,0x10);
}

void sub_808B50C(void)
{
  struct unkDungeon_8041D5C * iVar1;
  
  iVar1 = sub_8085680(0x1a);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(iVar1);
  sub_8041888(0);
  iVar1->unk70->unk15C = 1;
  iVar1->unk70->unk15E = 0;
  sub_80861B8(iVar1,0xe,0);
  sub_8083ED8(0x1e);
  sub_803E708(0x1e,0x46);
  // Fwaaaahhhh
  sub_8052910(&gUnknown_810554C);
  sub_8083E88(0x79);
  // I think I had a dream, and I was fighting in it
  // Did I imagine it?
  // I'm sleepy so I'm going back to sleep.
  sub_8052910(&gUnknown_8105558);
  sub_803E708(10,0x46);
  sub_808BC20(iVar1);
  sub_8052910(&gUnknown_81055F4);
  sub_803E708(10,0x46);
  gUnknown_203B418->unk2 = 1;
}
