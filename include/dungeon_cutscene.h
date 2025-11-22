#ifndef GUARD_DUNGEON_CUTSCENE_H
#define GUARD_DUNGEON_CUTSCENE_H

#include "structs/str_position.h"
#include "structs/dungeon_entity.h"
#include "dungeon_message.h"

typedef void (*DungeonCallback)(Entity *);
typedef struct struct_8085B80 {
    u8 unk0;
    Entity *unk4;
    s32 unk8;
    s16 *unkC;
} struct_8085B80;

void sub_80847D4(void);
bool8 ShouldShowDungeonBanner(void);
void sub_80848F0(void);
void DisplayPreFightDialogue(void);
void sub_8084E00(Entity *entity, u8 param_2, bool8 param_3);
void sub_8085140(void);
bool8 sub_808529C(s32 speciesId_);
void sub_8085374(void);
Entity *CutsceneGetLeader(void);
Entity *CutsceneGetPartner(void);
void sub_80854D4(void);
void sub_80855E4(DungeonCallback func);
void sub_808563C(DungeonCallback func);
Entity *GetEntityFromMonsterBehavior(u8 entityType);
void sub_80856C8(Entity * pokemon, s32 x, s32 y);
void sub_80856E0(Entity * pokemon, s32 direction);
void sub_8085860(s32 x, s32 y);
void ShiftCameraToPosition(PixelPos *posStruct, s32 cameraSteps);
void SetFacingDirection(Entity *pokemon, s32 direction);
void sub_8085930(s32 direction);
bool8 ShouldRunMonsterAI(Entity *pokemon);
void sub_8085B4C(struct_8085B80 a0[], s16 *a1[], Entity *a2[], s32 a3);
bool8 sub_8085B80(struct_8085B80 *a0);
void SetDungeonBGColorRGB(s32 r, s32 g, s32 b, bool8 a3, bool8 a4);
void sub_8085E98(void);
void sub_8085EB0(void);
u32 sub_8085EC8(s16 param_1,u32 param_2,u32 param_3,DungeonPos *param_4, bool32 param_5);
void sub_8085F44(s32 param_1);
void sub_8085F78(void);
bool8 sub_80860A8(u8 id);
void sub_8086130(void);
void sub_80861A8(Entity *a0);
void sub_80861B8(Entity *a0, u8 r1, s32 direction);
void sub_80861D4(Entity *a0, u8 r1, s32 direction);
s32 sub_80861F8(s32 param_1,Entity *param_2,bool32 param_3);
void SpriteShockEffect(Entity *entity);
void sub_8086448(void);
void sub_8086500(void);
void sub_808654C(void);
void sub_8086598(void);
void sub_80865E8(void);
void sub_808663C(void);
void sub_8086690(void);
void sub_80866C4(const struct DungeonDialogueStruct *dialogue);
void sub_8086738(void);
void sub_8086764(void);
void sub_8086794(void);
void sub_80867F4(void);
void sub_808680C(void);
void sub_808682C(void);
void sub_8086838(u8 entity, u8 r1, u8 r2);
void sub_8086848(u8 entity, u8 r1);
void sub_8086854(void);
void sub_80868F4(Entity *entity);
void sub_8086910(Entity *entity);
void sub_808692C(void);
void SpriteLookAroundEffect(Entity *entity);
void sub_80869E4(struct Entity *entity, s32 a1, u8 a2, s32 _someDirection);
void sub_8086A3C(Entity *pokemon);
void sub_8086A54(Entity *pokemon);
void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
void sub_8086AC0(void);
bool8 sub_8086AE4(s16 _index);

#endif // GUARD_DUNGEON_CUTSCENE_H
