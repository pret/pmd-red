#include "global.h"
#include "play_time.h"
#include "file_system.h"
#include "dungeon_global_data.h"

extern struct DungeonGlobalData *gDungeonGlobalData;
extern s32 gUnknown_80F6568[];
extern u8 gUnknown_202EE01;
extern const char gUnknown_80F6604; // "zmappat"
extern struct FileArchive gDungeonFileArchive;
extern struct OpenedFile *gUnknown_202EE04;

extern void sub_803F7BC(void);
extern void sub_80060EC(void);
extern void sub_800CB20(void);
extern void LoadBufferedInputs(void);
extern void xxx_call_update_bg_sound_input(void);
extern void sub_8083F58(void);
extern void sub_8011860(void);

extern void sub_803F580(u32);
extern void sub_8049ED4();
extern void sub_8040A84();
extern void SendMessage(u32, const char *);

extern const char *gUnknown_80FD040; // It became brighter on the floor

struct unk8049590
{
    u32 unk0;
    u16 unk4;
};

extern struct unk8049590 *sub_8049590(u32, u32);

// Luminous Orb???
void sub_804002C(u32 param_1)
{
  struct unk8049590 *iVar1;
  int innerCounter;
  int iVar3;
  int iVar4;

  gDungeonGlobalData->unk1820B = 1;
  iVar3 = 0;
  do {
    innerCounter = 0;
    iVar4 = iVar3 + 1;
    do {
      iVar1 = sub_8049590(innerCounter, iVar3);
      iVar1->unk4 = iVar1->unk4 | 1;
      innerCounter++;
    } while (innerCounter < 0x38);
    iVar3 = iVar4;
  } while (iVar4 < 0x20);
  sub_803F580(0);
  sub_8049ED4();
  sub_8040A84();
  SendMessage(param_1, gUnknown_80FD040);
}

void sub_8040094(u8 r0)
{
    gDungeonGlobalData->unk18217 = r0;
    sub_803F7BC();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    xxx_call_update_bg_sound_input();
    sub_8083F58();
    sub_8011860();
}

void sub_80400D4(void)
{
    s32 temp;
    temp = gDungeonGlobalData->unk18200;
    if(temp == 0)
        return;
    if(temp > 0x1E)
        temp = 0x1F;
    gDungeonGlobalData->unk181FC = gUnknown_80F6568[temp];
    gDungeonGlobalData->unk18200--;
    if(gDungeonGlobalData->unk18200 == 0)
        gDungeonGlobalData->unk18200 = gDungeonGlobalData->unk18204;
}

void sub_8040124(void)
{
    gUnknown_202EE01 = 0;
}

void sub_8040130(void)
{
    gUnknown_202EE04 = OpenFileAndGetFileDataPtr(&gUnknown_80F6604, &gDungeonFileArchive);
}
