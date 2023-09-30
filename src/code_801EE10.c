#include "global.h"
#include "input.h"
#include "text1.h"
#include "text2.h"
#include "memory.h"
#include "code_801EE10.h"
#include "menu_input.h"

extern unkStruct_203B270 *gUnknown_203B270;
extern UnkTextStruct2 gUnknown_80DC25C;
extern UnkTextStruct2 gUnknown_80DC274;

u32 sub_8006544(u32 index);
s32 sub_801F3F8(void);

u8 sub_801EE10(u32 param_1, s16 species, Move *moves, u32 param_4, const u8 *text, u32 param_6)
{
  s32 iVar5;
  s32 iVar8;
  s32 species_s32;
  u8 param_4_u8;
  s32 four;
    
  species_s32 = species;
  param_4_u8 = param_4;
  gUnknown_203B270 = MemoryAlloc(sizeof(unkStruct_203B270), 8);
  gUnknown_203B270->unk4 = param_4_u8;
  gUnknown_203B270->unk5 = 1;
  gUnknown_203B270->unk6 = 1;
  gUnknown_203B270->unk7 = 1;
  gUnknown_203B270->unk0 = param_1;
  switch(param_1)
  {
      case 2:
      case 3:
        gUnknown_203B270->unk5 = 0;
        gUnknown_203B270->unk6 = 0;
        gUnknown_203B270->unk7 = 0;
        break;
      case 0:
      case 1:
          break;
  }
  gUnknown_203B270->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
  gUnknown_203B270->isTeamLeader = gUnknown_203B270->pokeStruct->isTeamLeader;
  gUnknown_203B270->moves = moves;
  gUnknown_203B270->text = text;
  iVar8 = iVar5 = sub_801F3F8();
  four = 4;
  if (iVar8 < four) {
    iVar8 = 4;
  }
  sub_8006518(gUnknown_203B270->unk58);
  gUnknown_203B270->unk50 = param_6;
  gUnknown_203B270->unk58[param_6] = gUnknown_80DC25C;
  if (gUnknown_203B270->text != NULL) {
    gUnknown_203B270->unk54 = sub_8006544(param_6);
    gUnknown_203B270->unk58[gUnknown_203B270->unk54] = gUnknown_80DC274;
  }
  sub_8012D08(&gUnknown_203B270->unk58[gUnknown_203B270->unk50],iVar8);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B270->unk58, TRUE, TRUE);
  sub_8013818(&gUnknown_203B270->input,iVar5,iVar5,param_6);
  sub_8013780(&gUnknown_203B270->input,0);
  sub_801F280(1);
  return 1;
}
