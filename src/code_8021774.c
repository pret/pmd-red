#include "constants/friend_area.h"
#include "global.h"
#include "input.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "pokemon.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "code_800D090.h"
#include "menu_input.h"
#include "code_8021774.h"

struct unkStruct_203B28C
{
    struct MenuInputStructSub unk0;
    u8 friendArea;
    u8 unkD;
    s16 unkE[0x10];
    u32 unk30[0x10];
    s32 unk70;
    s32 unk74;
    struct UnkTextStruct2 *unk78;
    struct UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
};
extern struct unkStruct_203B28C *gUnknown_203B28C;

struct unkStruct_203B280
{
    u8 unk0[NUM_FRIEND_AREAS];
    u32 unk3C;
    struct MenuInputStruct unk40;
    s32 unk74;
    struct UnkTextStruct2 *unk78;
    struct UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
};
extern struct unkStruct_203B280 *gUnknown_203B280;



extern struct UnkTextStruct2 gUnknown_80DC4BC;
extern struct UnkTextStruct2 gUnknown_80DC4D8;
s16 GetBaseSpeciesNoUnown(s16 index);
s32 sub_8021B58(s16 param_1);

extern u8 gUnknown_80DC518[];
extern u8 gUnknown_80DC4F0[];
extern u8 *gUnknown_80D49BC[];
extern u8 gUnknown_80DC524[];
extern void sub_8008C54(u32);
extern void sub_8092578(u8 *buffer, u8 index, u8 r2);

extern void sub_8021878(void);
extern void sub_8021894(void);
extern void PlayMenuSoundEffect(u32);
extern void sub_8021A60(void);
void sub_8021820(void);
u8 sub_80023E4(u32);

s32 sub_8021664(void)
{
    s32 index;
    s32 counter;

    counter = 0;
    switch(gUnknown_203B280->unk3C)
    {
        case 0:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                gUnknown_203B280->unk0[counter] = index;
                counter++;
            }
            break;
        case 1:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if(gFriendAreas[index])
                {
                    gUnknown_203B280->unk0[counter] = index;
                    counter++;
                }
            }
            break;
        case 2:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if (gFriendAreas[index] == 0) {
                    switch(GetFriendAreaUnlockCondition(index))
                    {
                        case UNLOCK_SHOP_STORY:
                            gUnknown_203B280->unk0[counter] = index;
                            counter++;
                            break;
                        case UNLOCK_SHOP_POST_GAME:
                            if(sub_80023E4(6) != 0) {
                                gUnknown_203B280->unk0[counter] = index;
                                counter++;
                            }
                            break;
                    }
                }
            }
            break;
    }
    return counter;
}


u8 sub_8021700(u32 mode)
{
    s32 index;

    switch(mode)
    {
        case 0:
            return FALSE;
        case 1:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if (gFriendAreas[index] != 0) {
                    return FALSE;
                }
            }
            break;
        case 2:
            for(index = BOUNTIFUL_SEA; index < NUM_FRIEND_AREAS; index++)
            {
                if (gFriendAreas[index] == 0) {
                    switch(GetFriendAreaUnlockCondition(index))
                    {
                        case UNLOCK_SHOP_STORY:
                            return FALSE;
                        case UNLOCK_SHOP_POST_GAME:
                            if(sub_80023E4(6) != 0) {
                                return FALSE;
                            }
                            break;
                    }
                }
            }
            break;
    }
    return TRUE;
}


bool8 sub_8021774(u8 friendArea, u8 param_2, s32 param_3)
{
    gUnknown_203B28C = MemoryAlloc(sizeof(struct unkStruct_203B28C), 8);
    gUnknown_203B28C->friendArea = friendArea;
    gUnknown_203B28C->unkD = param_2;
    sub_801317C(&gUnknown_203B28C->unk0);
    sub_8021A60();
    gUnknown_203B28C->unk74 = param_3;
    gUnknown_203B28C->unk78 = &gUnknown_203B28C->unk7C[param_3];
    sub_8006518(gUnknown_203B28C->unk7C);
    gUnknown_203B28C->unk7C[gUnknown_203B28C->unk74] = gUnknown_80DC4D8;
    sub_8021820();
    return TRUE;
}

u32 sub_80217EC(void)
{
    switch(sub_8012A64(&gUnknown_203B28C->unk0, gUnknown_203B28C->unk74))
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

void sub_8021820(void)
{
    sub_8021878();
    sub_8021894();
}

void sub_8021830(void)
{
    if(gUnknown_203B28C)
    {
        gUnknown_203B28C->unk7C[gUnknown_203B28C->unk74] = gUnknown_80DC4BC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B28C->unk7C, 1, 1);
        MemoryFree(gUnknown_203B28C);
        gUnknown_203B28C = NULL;
    }
}

void sub_8021878(void)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B28C->unk7C, 1, 1);
}

void sub_8021894(void)
{
    u8 *string;
    s32 iVar1;
    u32 y;
    u32 x;
    s32 index;
    u8 buffer1 [256];
    u8 buffer2 [100];

    sub_80073B8(gUnknown_203B28C->unk74);
    sub_8092578(buffer1,gUnknown_203B28C->friendArea,0);
    xxx_call_draw_string(0x14,0,buffer1,gUnknown_203B28C->unk74,0);
    string = GetFriendAreaDescription(gUnknown_203B28C->friendArea);
    xxx_call_draw_string(10,0x14,string,gUnknown_203B28C->unk74,0);
    if (gUnknown_203B28C->unkD != 0) {
        xxx_call_draw_string(0x20,0x3c,gUnknown_80DC4F0,gUnknown_203B28C->unk74,0);
    }
    else {
        xxx_call_draw_string(0x20,0x3c,gUnknown_80DC518,gUnknown_203B28C->unk74,0); // Inhabitants
    }
    sub_800792C(gUnknown_203B28C->unk74,4,0x40,0x14,4);
    if (gUnknown_203B28C->unkD != 0) {
        sub_800792C(gUnknown_203B28C->unk74,0xb8,0x40,0x14,4);
    }
    else {
        sub_800792C(gUnknown_203B28C->unk74,0x5e,0x40,0x6e,4);
    }
    sub_800792C(gUnknown_203B28C->unk74,4,0x82,200,4);
    sub_8007A78(gUnknown_203B28C->unk74,3,0x40,0x43,4);
    sub_8007A78(gUnknown_203B28C->unk74,0xcc,0x40,0x43,4);
    for(index = 0; index < gUnknown_203B28C->unk70; index++)
    {
        iVar1 = index % 3;
        x = iVar1 * 0x3f + 7;
        iVar1 = index / 3;
        y = iVar1 * 0xc + 0x47;
        sub_808D930(buffer2, gUnknown_203B28C->unkE[index]);
        switch(gUnknown_203B28C->unk30[index])
        {
            case 0:
                xxx_call_draw_string(x,y,*gUnknown_80D49BC,gUnknown_203B28C->unk74,0); // ???
                break;
            case 1:
                xxx_call_draw_string(x,y,buffer2,gUnknown_203B28C->unk74,0); // %s
                break;
            case 2:
                sprintfStatic(buffer1,gUnknown_80DC524,buffer2); // {CYAN} %s {END_COLOR}
                xxx_call_draw_string(x,y,buffer1,gUnknown_203B28C->unk74,0);
                break;
        }
    }
    sub_80073E0(gUnknown_203B28C->unk74);
}

// https://decomp.me/scratch/P2BiC 
// 99.40% matching (Seth)
#ifndef NONMATCHING
NAKED
void sub_8021A60(void)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tldr r2, _08021B4C\n"
	"\tldr r1, [r2]\n"
	"\tmovs r0, 0\n"
	"\tstr r0, [r1, 0x70]\n"
	"\tmovs r6, 0\n"
	"\tadds r4, r2, 0\n"
	"\tmovs r3, 0\n"
"_08021A70:\n"
	"\tldr r1, [r4]\n"
	"\tlsls r2, r6, 1\n"
	"\tadds r0, r1, 0\n"
	"\tadds r0, 0xE\n"
	"\tadds r0, r2\n"
	"\tstrh r3, [r0]\n"
	"\tlsls r0, r6, 2\n"
	"\tadds r1, 0x30\n"
	"\tadds r1, r0\n"
	"\tstr r3, [r1]\n"
	"\tadds r6, 0x1\n"
	"\tcmp r6, 0xF\n"
	"\tble _08021A70\n"
	"\tmovs r6, 0\n"
	"\tldr r7, _08021B4C\n"
"_08021A8E:\n"
	"\tlsls r0, r6, 16\n"
	"\tasrs r5, r0, 16\n"
	"\tldr r4, [r7]\n"
	"\tadds r0, r5, 0\n"
	"\tbl GetFriendArea\n"
	"\tldrb r1, [r4, 0xC]\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r1, r0\n"
	"\tbne _08021AC4\n"
	"\tadds r0, r5, 0\n"
	"\tbl GetBaseSpeciesNoUnown\n"
	"\tlsls r0, 16\n"
	"\tasrs r0, 16\n"
	"\tcmp r5, r0\n"
	"\tbne _08021AC4\n"
	"\tldr r3, [r7]\n"
	"\tldr r1, [r3, 0x70]\n"
	"\tlsls r2, r1, 1\n"
	"\tadds r0, r3, 0\n"
	"\tadds r0, 0xE\n"
	"\tadds r0, r2\n"
	"\tstrh r5, [r0]\n"
	"\tadds r1, 0x1\n"
	"\tstr r1, [r3, 0x70]\n"
"_08021AC4:\n"
	"\tadds r6, 0x1\n"
	"\tldr r0, _08021B50\n"
	"\tcmp r6, r0\n"
	"\tble _08021A8E\n"
	"\tmovs r6, 0\n"
"_08021ACE:\n"
	"\tlsls r0, r6, 16\n"
	"\tasrs r4, r0, 16\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_8098134\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08021AFC\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_8021B58\n"
	"\tadds r2, r0, 0\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r2, r0\n"
	"\tbeq _08021AFC\n"
	"\tldr r0, _08021B4C\n"
	"\tldr r1, [r0]\n"
	"\tlsls r0, r2, 2\n"
	"\tadds r1, 0x30\n"
	"\tadds r1, r0\n"
	"\tmovs r0, 0x1\n"
	"\tstr r0, [r1]\n"
"_08021AFC:\n"
	"\tadds r6, 0x1\n"
	"\tldr r0, _08021B50\n"
	"\tcmp r6, r0\n"
	"\tble _08021ACE\n"
	"\tmovs r6, 0\n"
	"\tldr r4, _08021B54\n"
"_08021B08:\n"
	"\tmovs r0, 0x58\n"
	"\tadds r1, r6, 0\n"
	"\tmuls r1, r0\n"
	"\tldr r0, [r4]\n"
	"\tadds r2, r0, r1\n"
	"\tldrb r1, [r2]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _08021B3C\n"
	"\tmovs r1, 0x8\n"
	"\tldrsh r0, [r2, r1]\n"
	"\tbl sub_8021B58\n"
	"\tadds r2, r0, 0\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r2, r0\n"
	"\tbeq _08021B3C\n"
	"\tldr r0, _08021B4C\n"
	"\tldr r1, [r0]\n"
	"\tlsls r0, r2, 2\n"
	"\tadds r1, 0x30\n"
	"\tadds r1, r0\n"
	"\tmovs r0, 0x2\n"
	"\tstr r0, [r1]\n"
"_08021B3C:\n"
	"\tadds r6, 0x1\n"
	"\tmovs r0, 0xCE\n"
	"\tlsls r0, 1\n"
	"\tcmp r6, r0\n"
	"\tble _08021B08\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08021B4C: .4byte gUnknown_203B28C\n"
"_08021B50: .4byte 0x000001a7\n"
"_08021B54: .4byte gRecruitedPokemonRef");

}
#else
void sub_8021A60(void)
{
  s32 sVar4;
  s32 iVar6;
  s32 index;
  struct PokemonStruct *pokeStruct;
  
  gUnknown_203B28C->unk70 = 0;
  for(index = 0; index < 0x10; index++)
  {
    gUnknown_203B28C->unkE[index] = 0;
    gUnknown_203B28C->unk30[index] = 0;
  }
  for(index = 0; index < 0x1A8; index++)
  {
    if ((gUnknown_203B28C->friendArea == GetFriendArea((s16)index)) &&
       ((s16)index == GetBaseSpeciesNoUnown(index))) {
      iVar6 = gUnknown_203B28C->unk70;
      gUnknown_203B28C->unkE[iVar6] = index;
      gUnknown_203B28C->unk70 = iVar6 + 1;
    }
  }
  for(index = 0; index < 0x1A8; index++)
  {
    if ((sub_8098134(index) != '\0') && (sVar4 = sub_8021B58(index), sVar4 != -1)) {
      gUnknown_203B28C->unk30[sVar4] = 1;
    }
  }
  for(index = 0; index < 0x19d; index++)
  {
    pokeStruct = &gRecruitedPokemonRef->pokemon[index];
    if (((*(u8 *)&pokeStruct->unk0 & 1) != 0) &&
       (sVar4 = sub_8021B58(pokeStruct->speciesNum), sVar4 != -1)) {
      gUnknown_203B28C->unk30[sVar4] = 2;
    }
  }
  return;
}
#endif

s32 sub_8021B58(s16 species)
{
  s32 baseSpecies;
  int index;
  
  baseSpecies = GetBaseSpeciesNoUnown(species);
  for(index = 0; index < gUnknown_203B28C->unk70; index++)
  {
    if (baseSpecies == gUnknown_203B28C->unkE[index]) return index;
  }
  return -1;
}

