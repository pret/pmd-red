#include "global.h"
#include "event_flag.h"

extern void xxx_dungeon_8042F6C(u32 r0);
extern void NDS_LoadOverlay_GroundMain();
extern u32 xxx_script_related_8098468(u32);

void NDS_LoadOverlay_GroundMain()
{

}

void nullsub_2(u32 r0)
{

}

u32 xxx_script_related_8001334(u32 r0)
{
    return xxx_script_related_8098468(r0);
}

void xxx_dungeon_8001340(u32 r0)
{
    nullsub_2(r0);
    xxx_dungeon_8042F6C(r0);
    NDS_LoadOverlay_GroundMain();
}

void nullsub_3(s32 a0, s32 a1)
{

}

/////////////////////////////////
/// TODO merge with event_flag
/////////////////////////////////

extern void sub_80972F4(void);
extern void nullsub_128(void);

void ThoroughlyResetScriptVars(void)
{
  s32 iVar1;
  s32 iVar3;
  u16 uVar2;
  struct ScriptVarInfo *puVar1;
  
  for(iVar3 = 0; iVar3 < 0x400; iVar3++)
  {
    gScriptVarBuffer[iVar3] = 0;
  }

  for(iVar1 = 0; iVar1 < 0x51; iVar1 = (iVar1 + 1) * 0x10000 >> 0x10)
  {
    puVar1 = &gScriptVarInfo[iVar1];
    if (((puVar1->type != 0) && ((puVar1->type != 8)))) {
      for (uVar2 = 0; uVar2 < puVar1->arrayLen; uVar2++) {
        SetScriptVarArrayValue(NULL, iVar1, uVar2, puVar1->defaultValue);
      }
    }
  }
  ClearScriptVarArray(NULL,1);
  ScenarioCalc(2,0,0);
  ScenarioCalc(3,0,0);
  ScenarioCalc(4,0,0);
  ScenarioCalc(5,0,0);
  ScenarioCalc(6,0,0);
  ScenarioCalc(7,0,0);
  ScenarioCalc(8,0,0);
  ScenarioCalc(9,0,0);
  ScenarioCalc(10,0,0);
  ScenarioCalc(0xb,0,0);
  ScenarioCalc(0xc,0,0);
  SetScriptVarValue(NULL,0xd,0xa2);
  SetScriptVarValue(NULL,0xe,0);
  SetScriptVarValue(NULL,0xf,0xa2);
  SetScriptVarValue(NULL,0x10,-1);
  SetScriptVarValue(NULL,0x11,0x24);
  SetScriptVarValue(NULL,0x12,-1);
  SetScriptVarValue(NULL,0x13,0);
  SetScriptVarValue(NULL,0x14,-1);
  SetScriptVarValue(NULL,0x16,0);
  SetScriptVarValue(NULL,0x18,0);
  SetScriptVarValue(NULL,0x19,0);
  SetScriptVarValue(NULL,0x1b,-1);
  SetScriptVarValue(NULL,0x1c,0);
  SetScriptVarValue(NULL,0x1d,0);
  SetScriptVarValue(NULL,0x1e,0);
  SetScriptVarValue(NULL,0x1f,0);
  ClearScriptVarArray(NULL,0x24);
  SetScriptVarValue(NULL,0x25,0);
  SetScriptVarValue(NULL,0x26,0);
  SetScriptVarValue(NULL,0x27,0);
  SetScriptVarValue(NULL,0x28,0);
  SetScriptVarValue(NULL,0x29,0);
  SetScriptVarValue(NULL,0x2a,0);
  ClearScriptVarArray(NULL,0x2b);
  ClearScriptVarArray(NULL,0x2c);
  ClearScriptVarArray(NULL,0x2d);
  ClearScriptVarArray(NULL,0x2e);
  ClearScriptVarArray(NULL,0x2f);
  ClearScriptVarArray(NULL,0x30);
  ClearScriptVarArray(NULL,0x31);
  ClearScriptVarArray(NULL,0x41);
  sub_80972F4();
}

void sub_8001564(void)
{
    nullsub_128();
}
