#include "global.h"
#include "pokemon.h"

extern u32 gIQSkillNames[];
extern u32 gIQSkillDescriptions[];
extern u32 gTacticsDescriptions[];
extern u8 *gTactics[];
extern u8 gUnknown_810A36B[];

extern s16 gUnknown_810A378[];
extern s32 gUnknown_810A390[];
extern u32 gUnknown_81076E4[];
extern struct unkStruct_203B45C *gRecruitedPokemonRef;

struct unkStruct_808E9EC
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
};

extern s16 gUnknown_810AC60; // 0xC
extern s16 gUnknown_810AC62; // 0xC
extern s16 gUnknown_810AC68; // 0x8
extern s16 gUnknown_810AC64; // 0x8
extern s16 gUnknown_810AC66; // 0x8

extern bool8 sub_808ECD0(u8 *, u32);
extern void sub_808EC30(u8 *, u32);

s32 GetUnownIndex(s16 index)
{
    if(index == SPECIES_UNOWN_B)
        return 1;
    if(index == SPECIES_UNOWN_C)
        return 2;
    if(index == SPECIES_UNOWN_D)
        return 3;
    if(index == SPECIES_UNOWN_E)
        return 4;
    if(index == SPECIES_UNOWN_F)
        return 5;
    if(index == SPECIES_UNOWN_G)
        return 6;
    if(index == SPECIES_UNOWN_H)
        return 7;
    if(index == SPECIES_UNOWN_I)
        return 8;
    if(index == SPECIES_UNOWN_J)
        return 9;
    if(index == SPECIES_UNOWN_K)
        return 10;
    if(index == SPECIES_UNOWN_L)
        return 11;
    if(index == SPECIES_UNOWN_M)
        return 12;
    if(index == SPECIES_UNOWN_N)
        return 13;
    if(index == SPECIES_UNOWN_O)
        return 14;
    if(index == SPECIES_UNOWN_P)
        return 15;
    if(index == SPECIES_UNOWN_Q)
        return 16;
    if(index == SPECIES_UNOWN_R)
        return 17;
    if(index == SPECIES_UNOWN_S)
        return 18;
    if(index == SPECIES_UNOWN_T)
        return 19;
    if(index == SPECIES_UNOWN_U)
        return 20;
    if(index == SPECIES_UNOWN_V)
        return 21;
    if(index == SPECIES_UNOWN_W)
        return 22;
    if(index == SPECIES_UNOWN_X)
        return 23;
    if(index == SPECIES_UNOWN_Y)
        return 24;
    if(index == SPECIES_UNOWN_Z)
        return 25;
    if(index == SPECIES_UNOWN_EMARK)
        return 26;
    if(index == SPECIES_UNOWN_QMARK)
        return 27;
    return 0;
}

u32 sub_808E9B8(struct PokemonStruct *r0)
{
    return r0->unk0 & 0x000001ff;
}

void sub_808E9C4(struct PokemonStruct *r0, s16 r1)
{
    s32 r1_s32 = r1; // cast needed to match
    r0->unk0 =  ((0xFE << 8) & r0->unk0) | r1_s32 ;
}

void sub_808E9D8(struct PokemonStruct *r0, s32 r1, s16 r2)
{
    s32 r2_32 = r2; // dumb cast to match
    r0->unk0 =  r2_32 | (r1 << 9) ;
}

u32 sub_808E9E4(struct PokemonStruct *r0)
{
    return (r0->unk0 >> 9);
}

// Unused
#ifdef NONMATCHING
void sub_808E9EC(struct PokemonStruct *r0, struct unkStruct_808E9EC *r1)
{
    u8 pokeAtt;
    u8 r4;
    u32 reg1_8;
    s16 reg1;

    pokeAtt = r0->pokeAtt;

    r1->unk0 = pokeAtt;
    r1->unk4 = r0->pokeSPAtt;
    r1->unk8 = r0->pokeDef;
    r1->unkC = r0->pokeSPDef;
    r1->unk10 = 0;
    r1->unk11 = 0;
    r1->unk12 = 0;
    r1->unk13 = 0;
    if(r0->unk28 != 0)
    {
        r4 = r0->unk28;
        if(r4 == 0x13)
        {
            r1->unk10 = gUnknown_810AC60;
            r1->unk0 = pokeAtt + gUnknown_810AC60;
        }
        if(r4 == 0x21)
        {
            r1->unk11 += gUnknown_810AC62;
            r1->unk4 += gUnknown_810AC62;
        }
        if(r4 == 0x2B)
        {
            // TODO: regs get a little f**ked
            reg1_8 = (u8)gUnknown_810AC68;
            r1->unk10 += reg1_8;
            r1->unk11 += reg1_8;

            reg1 = gUnknown_810AC68;
            r1->unk0 += reg1;
            r1->unk4 += reg1;
        }
        if(r4 == 0x1E)
        {
            r1->unk12 += gUnknown_810AC64;
            r1->unk8 += gUnknown_810AC64;
        }
        if(r4 == 0x22)
        {
            r1->unk13 += gUnknown_810AC66;
            r1->unkC += gUnknown_810AC66;
        }
    }
}
#else
NAKED
void sub_808E9EC(struct PokemonStruct *r0, struct unkStruct_808E9EC *r1)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tadds r3, r1, 0\n"
	"\tldrb r2, [r0, 0x18]\n"
	"\tstr r2, [r3]\n"
	"\tldrb r1, [r0, 0x19]\n"
	"\tstr r1, [r3, 0x4]\n"
	"\tldrb r1, [r0, 0x1A]\n"
	"\tstr r1, [r3, 0x8]\n"
	"\tldrb r1, [r0, 0x1B]\n"
	"\tstr r1, [r3, 0xC]\n"
	"\tmovs r1, 0\n"
	"\tstrb r1, [r3, 0x10]\n"
	"\tstrb r1, [r3, 0x11]\n"
	"\tstrb r1, [r3, 0x12]\n"
	"\tstrb r1, [r3, 0x13]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x28\n"
	"\tldrb r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808EA96\n"
	"\tadds r4, r0, 0\n"
	"\tadds r5, r4, 0\n"
	"\tcmp r4, 0x13\n"
	"\tbne _0808EA2A\n"
	"\tldr r1, _0808EA9C\n"
	"\tldrh r0, [r1]\n"
	"\tstrb r0, [r3, 0x10]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r0, [r1, r6]\n"
	"\tadds r0, r2, r0\n"
	"\tstr r0, [r3]\n"
"_0808EA2A:\n"
	"\tcmp r4, 0x21\n"
	"\tbne _0808EA42\n"
	"\tldr r1, _0808EAA0\n"
	"\tldrb r0, [r1]\n"
	"\tldrb r2, [r3, 0x11]\n"
	"\tadds r0, r2\n"
	"\tstrb r0, [r3, 0x11]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r1, r6]\n"
	"\tldr r0, [r3, 0x4]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0x4]\n"
"_0808EA42:\n"
	"\tcmp r4, 0x2B\n"
	"\tbne _0808EA66\n"
	"\tldr r2, _0808EAA4\n"
	"\tldrb r0, [r2]\n"
	"\tldrb r6, [r3, 0x10]\n"
	"\tadds r1, r0, r6\n"
	"\tstrb r1, [r3, 0x10]\n"
	"\tldrb r1, [r3, 0x11]\n"
	"\tadds r0, r1\n"
	"\tstrb r0, [r3, 0x11]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r2, r6]\n"
	"\tldr r0, [r3]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3]\n"
	"\tldr r0, [r3, 0x4]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0x4]\n"
"_0808EA66:\n"
	"\tcmp r4, 0x1E\n"
	"\tbne _0808EA7E\n"
	"\tldr r1, _0808EAA8\n"
	"\tldrb r0, [r1]\n"
	"\tldrb r2, [r3, 0x12]\n"
	"\tadds r0, r2\n"
	"\tstrb r0, [r3, 0x12]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r1, r6]\n"
	"\tldr r0, [r3, 0x8]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0x8]\n"
"_0808EA7E:\n"
	"\tcmp r5, 0x22\n"
	"\tbne _0808EA96\n"
	"\tldr r1, _0808EAAC\n"
	"\tldrb r0, [r1]\n"
	"\tldrb r2, [r3, 0x13]\n"
	"\tadds r0, r2\n"
	"\tstrb r0, [r3, 0x13]\n"
	"\tmovs r6, 0\n"
	"\tldrsh r1, [r1, r6]\n"
	"\tldr r0, [r3, 0xC]\n"
	"\tadds r0, r1\n"
	"\tstr r0, [r3, 0xC]\n"
"_0808EA96:\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808EA9C: .4byte gUnknown_810AC60\n"
"_0808EAA0: .4byte gUnknown_810AC62\n"
"_0808EAA4: .4byte gUnknown_810AC68\n"
"_0808EAA8: .4byte gUnknown_810AC64\n"
"_0808EAAC: .4byte gUnknown_810AC66");
}
#endif

u32 GetIQSkillName(u8 r0)
{
    return gIQSkillNames[r0];
}

void CopyTacticsNameToBuffer(char *r0, u8 r1)
{
    strncpy(r0, gTactics[r1], 0x14);
}

u32 GetIQSkillDescription(u8 r0)
{
    return gIQSkillDescriptions[r0];
}

u32 GetTacticsDescription(u8 r0)
{
    return gTacticsDescriptions[r0];
}

u8 sub_808EAFC(u8 r0)
{
    return gUnknown_810A36B[r0];
}

void sub_808EB0C(u8 *r0, s32 r1)
{
    s32 counter;
    s32 storage;
    u32 index;
    storage = 0;
    index = 0;
    for(counter = 0; counter <= 0xB; counter++)
    {
        if(gUnknown_810A378[index] <= r1)
        {
            r0[storage] = counter;
            storage++;
        }
        index++;
    }
    if(storage > 0xB)
    {
        return;
    }
    while(storage <= 0xB)
    {
        r0[storage] = 0xB;
        storage++;
    }
}

void sub_808EB48(u8 *r0, s32 r1)
{
    s32 counter;

    for(counter = 0; counter <= 0xB; counter++)
    {
        if(gUnknown_810A378[counter] <= r1)
        {
            r0[counter] = TRUE;
        }
        else
        {
            r0[counter] = FALSE;
        }
    }
}

bool8 sub_808EB7C(s32 r0, u8 r1)
{
    if(r1 == 0)
    {
        return FALSE;
    }

    return gUnknown_810A390[r1] <= r0;
}

s32 sub_808EBA8(u8 param_1[], s32 param_2)
{
  s32 counter_2;
  s32 counter_1;
  u8 cast_u8;
  s32 index;
  
  index = 0;

  for(counter_1 = 1; counter_1 < 0x18; counter_1++) {
    cast_u8 = counter_1; // force this cast to be in a reg
    if (sub_808EB7C(param_2, cast_u8)) {
      param_1[index] = cast_u8;
      index++;
    }
  }

  counter_2 = index; // set counter to where the first loop ended

  while (counter_2 < 0x18) {
    param_1[counter_2] = 0;
    counter_2++;
  }
  return index;
}

void sub_808EBF4(u8 *param_1, u32 param_2)
{
  int iVar2; // a mask?

  iVar2 = 1 << (param_2);
  if (sub_808ECD0(param_1,iVar2)) {
    param_1[0] = param_1[0] & ~iVar2;
    param_1[1] = param_1[1] & ~(iVar2 >> 8);
    param_1[2] = param_1[2] & ~(iVar2 >> 0x10);
  }
  else
  {
    sub_808EC30(param_1,param_2);
  }
}

void sub_808EC30(u8 *param_1, u32 param_2)
{
  s32 iVar1;
  s32 counter;
  s32 iVar4;
  s32 iVar5;

  counter = 0;
  iVar4 = gUnknown_81076E4[param_2];
  do {
    if (iVar4 == gUnknown_81076E4[counter]) {
      iVar1 = 1 << (counter);
      param_1[0] = param_1[0] & ~iVar1;
      param_1[1] = param_1[1] & ~(iVar1 >> 8);
      param_1[2] = param_1[2] & ~(iVar1 >> 0x10);
    }
    counter++;
  } while (counter < 0x18);

  iVar5 = 1 << (param_2);
  param_1[0] = iVar5           | param_1[0];
  param_1[1] = (iVar5 >> 8)    | param_1[1];
  param_1[2] = (iVar5 >> 0x10) | param_1[2];
}

void sub_808EC94(u8 *param_1, u8 param_2)
{

  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  sub_808EC30(param_1, 2);
  sub_808EC30(param_1, 3);
  sub_808EC30(param_1, 0x16);
  if (param_2 != 0) {
    sub_808EC30(param_1, 0x12);
  }
}

bool8 sub_808ECD0(u8 *param_1, u32 param_2)
{

  if ((((param_1[0] & param_2) == 0) && 
       ((param_1[1] & param_2 >> 8) == 0)) &&
       ((param_1[2] & param_2 >> 0x10) == 0)) 
  {
    return 0;
  }
  else {
    return 1;
  }
}

u32 sub_808ECFC(void)
{
    return 0;
}

extern s32 sub_808D580(s32*);

void sub_808ED00() {
    s32 team[4];
    s32 i;
    s32 length = sub_808D580(team);

    for (i = 0; i < length; i++) {
#ifdef NONMATCHING
        memcpy(&gRecruitedPokemonRef->team[i], &gRecruitedPokemonRef->pokemon[buffer[i]], sizeof(struct PokemonStruct));
#else
        // all this to swap 2 registers...
        size_t grpmr = (size_t)gRecruitedPokemonRef;
        size_t offs = offsetof(struct unkStruct_203B45C, team);
        struct PokemonStruct* dest = (void*)(
            grpmr 
            + sizeof(struct PokemonStruct) * i
            + offs
        );
        size_t grpmr2 = (size_t)gRecruitedPokemonRef;
        struct PokemonStruct* src = (void*)grpmr2;
        size_t index = team[i];
        src += index;
        
        memcpy(dest, src, sizeof(struct PokemonStruct));
#endif
    }

    for (; i < 4; i++) {
        gRecruitedPokemonRef->team[i].unk0 = 0;
    }
}
