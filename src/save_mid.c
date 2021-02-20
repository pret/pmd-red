#include "global.h"
#include "save.h"
#include "friend_area.h"
#include "pokemon.h"
#include "file_system.h"
#include "time.h"

extern struct UnkStruct_203B184 *gUnknown_203B184;
extern struct PlayTimeStruct *gPlayTimeRef;

struct unk_203B188
{
    u32 unk0;
    u32 unk4;
};

struct unk_struct
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 padding[504];
};

extern struct unk_203B188 *gUnknown_203B188;

struct unkStruct_203B18C
{
    u32 unk0;
    s32 unk4;
    u32 unk8;
    struct OpenedFile *faceFile;
    u8 *faceData;
     u16 unk14;
     u16 unk16;
     u8 unk18;
     u8 unk19;
     u8 unk1A;
     u8 unk1B;
     u16 pokeID;
};

extern struct unkStruct_203B18C *gUnknown_203B18C;

struct unkStruct_203B190
{
    s32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
};
extern struct unkStruct_203B190 *gUnknown_203B190;

struct unkStruct_203B194
{
    s32 unk0;
    u8 *unk4;
    u32 unk8;
    u8 unkC;
    u8 padding[0x10 - 0xD];
    u32 unk10;
};
extern struct unkStruct_203B194 *gUnknown_203B194;

extern u32 *gUnknown_203B45C;
extern u32 *gUnknown_203B460;
extern u32 gUnknown_203B464;
extern u8 *gFriendAreas;
extern u32 gUnknown_203B46C;
extern u8 *gUnknown_203B480;
extern u8 *gUnknown_203B484;
extern u32 *gUnknown_203B488;
extern u32 *gUnknown_203B48C;
extern u32 gUnknown_203B490;
extern u32 gUnknown_203B494;
extern u8 *gUnknown_203B498;

extern const char gSaveCorrupted;
extern const char gSavingAdventure;
extern const char gWriteGamePak;
extern const char gSaveCompleted;
extern const char gSaveNotWritten;
extern const char gSaveFailed;
extern const char gUnknown_80D44C8;
extern const char gUnknown_80D45AC;

extern const char gUnknown_80D45F4;
extern const char gUnknown_80D4668;
extern const char gUnknown_80D473C;
extern const char gSaveFailed2;

extern void sub_800135C(void);
extern u32 *sub_808CE00(void);
extern void sub_808CE08(void);
extern u32 *sub_80909D0(void);
extern void sub_80909D8(void);
extern u32 sub_809208C(void);
extern void sub_8092094(void);
extern u32 sub_8094990(void);
extern void sub_8094998(u8 r0);
extern u8 *sub_80950F8(void);
extern u8 *sub_8095100(void);
extern u32 *sub_8095108(void);
extern u32 *sub_8095110(void);
extern void sub_8095118(void);
extern u32 sub_80958F8(void);
extern void sub_8095900(void);
extern u32 sub_8097680(void);
extern void sub_80972F4(void);
extern void sub_80974E8(void);
extern u8 *sub_8097F6C(void);
extern void sub_8097F74(void);
extern void sub_80993D8(void);

extern void sub_8011C28(u32 r0);
extern void sub_8011C40(s32 r0);
extern void sub_8097748(void);

extern void* MemoryAlloc(u32 a, u32 b);
extern void MemoryFree(void* a);
extern void MemoryFill8(u8 *dest, u8 value, s32 size);
extern void sub_8011830(void);
extern s32 WriteFlashData(s32 sector, u8 *src, s32 size);
extern void xxx_call_start_bg_music(void);
extern u32 *sub_809769C(void);
u32 *sub_8011C4C(void);
extern void sub_80958E4(u8 *a, u32 b);
extern s32 WriteSaveSector(s32 *a, u8 *src, s32 size);
extern u32 sub_8011DAC(u32 *a);
extern u32 sub_80144A4(u32 *a);
extern bool8 sub_8011FF8(void);
extern void sub_80141B4(const char *r0, u32 r1, u8 *r2, u16 r3);

extern void sub_8014114();
extern void sub_80140DC();
extern u32 sub_8011C1C();
extern u32 sub_801203C(u32 *r0, u32);
extern void sub_80993E4();
extern u32 sub_8011F9C(u32 *r0, u32, u32);

void sub_8012298();
void sub_80122D0();
void sub_80122F4();
void sub_8012300();
void sub_80976A8();
void sub_80122A8();


s32 sub_80121D4(s32 *a, u8 *src, s32 size)
{
    return WriteSaveSector(a, src, size);
}

u32 sub_80121E0(u32 r0)
{
    u32 temp;
    u32 *temp2;
    u32 temp3;
    struct unk_struct *r4 = MemoryAlloc(sizeof(struct unk_struct), 5);
    temp = 0x1F;

    r4->unk18 = r0;
    r4->unk1C = *sub_809769C();
    r4->unk14 = 0x5071412;

    temp2 = sub_8011C4C();
    strncpy((u8 *)r4 + 4, (u8*)temp2, 16);
    sub_80958E4((u8 *)r4 + 32, 0);
    temp3 = WriteSaveSector(&temp, (u8 *)r4, sizeof(struct unk_struct));
    MemoryFree(r4);
    return temp3;
}

u32 sub_8012240(void)
{
    s32 temp;
    struct unk_struct *r5 = MemoryAlloc(sizeof(struct unk_struct), 5);
    MemoryFill8((u8 *)r5, 0xFF, 0x4);
    sub_8011830();
    temp = WriteFlashData(0x1F, (u8 *)r5, sizeof(struct unk_struct));
    xxx_call_start_bg_music();
    MemoryFree(r5);
    if(temp != 0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void sub_8012284(void)
{
    sub_80122D0();
    sub_80122F4();
    sub_8012300();
}

void sub_8012298(void)
{
    sub_80976A8();
    sub_80122A8();
}

void sub_80122A8(void)
{
    sub_80122D0();
    sub_80122F4();
    sub_8012300();
    sub_8012240();

}

void nullsub_33(void)
{
}

void sub_80122C4(void)
{
    sub_80122A8();
}

void sub_80122D0(void)
{
    sub_8011C28(0);
    sub_8011C40(-1);
    sub_8097748();
    ResetPlayTime(gPlayTimeRef);
}

void sub_80122F4(void)
{
    sub_800135C();
}

void sub_8012300(void)
{
    InitializeFriendAreas();
    sub_808CE08();
    sub_80909D8();
    sub_8092094();
    sub_80972F4();
    sub_8095118();
    sub_8095900();
    sub_80974E8();
    sub_8094998(1);
    sub_8097F74();
}


// Unused
void nullsub_200(u32 r0)
{
}

// Unused
void sub_8012334(struct UnkStruct_203B184 *r0)
{
    gUnknown_203B184 = r0;
    if(r0 != NULL)
    {
       gUnknown_203B460 = r0->unk0;
       gUnknown_203B45C = r0->unk4;
       gUnknown_203B480 = r0->unk8;
       gUnknown_203B484 = r0->unkC;
       gUnknown_203B488 = r0->unk10;
       gUnknown_203B48C = r0->unk14;
       gUnknown_203B490 = r0->unk18;
       gUnknown_203B464 = r0->unk1C;
       gUnknown_203B494 = r0->unk20;
       gUnknown_203B498 = r0->unk24;
       gFriendAreas     = r0->BoughtFriendAreas;
       gUnknown_203B46C = r0->unk2C;
       gPlayTimeRef = r0->playTime;
       return;
    }
       gUnknown_203B460 = sub_80909D0();
       gUnknown_203B45C = sub_808CE00();
       gUnknown_203B480 = sub_80950F8();
       gUnknown_203B484 = sub_8095100();
       gUnknown_203B488 = sub_8095108();
       gUnknown_203B48C = sub_8095110();
       gUnknown_203B490 = sub_80958F8();
       gUnknown_203B464 = sub_809208C();
       gUnknown_203B494 = sub_8097680();
       gUnknown_203B498 = sub_8097F6C();
       gFriendAreas     = GetBoughtFriendAreas();
       gUnknown_203B46C = sub_8094990();
       gPlayTimeRef = GetPlayTime();

}

void sub_8012468(void)
{
    gUnknown_203B188 = MemoryAlloc(sizeof(struct unk_203B188), 5);
    gUnknown_203B188->unk0 = 1;

}

u8 sub_8012484(void)
{
    u32 temp;
    u32 temp2;
    switch(gUnknown_203B188->unk0)
    {
        case 0:
            gUnknown_203B188->unk0 = 1;
            break;
        case 1:
            temp = 0;
            gUnknown_203B188->unk4 = sub_8011DAC(&temp);
            gUnknown_203B188->unk0 = 2;
            break;
        case 2:
            if(gUnknown_203B188->unk4 != 0)
            {
                if(sub_8011FF8())
                {
                    sub_80141B4(&gSaveCorrupted, 0, 0, 0x301);
                    gUnknown_203B188->unk0 = 3;
                    break;
                }
                else
                {
                    gUnknown_203B188->unk0 = 4;
                    break;
                }
            }
            else
            {
                gUnknown_203B188->unk0 = 6;
                break; 
            }
        case 3:
            if(sub_80144A4(&temp2) == 0)
            {
                gUnknown_203B188->unk0 = 4;
                break;
            }
            else
            {
                break;
            }
        case 4:
            sub_8012298();
            gUnknown_203B188->unk0 = 6;
        case 5:
            break;
        case 6:
            return 0;
    }
    return 1;
}

void sub_8012558(void)
{
    if(gUnknown_203B188 != NULL)
    {
        MemoryFree(gUnknown_203B188);
        gUnknown_203B188 = NULL;
    }
}

#ifdef NONMATCHING
void sub_8012574(s16 PokemonID)
{
  struct OpenedFile *file;
  s32 id_s32;

  id_s32 = PokemonID; // had to cast for asr shift
  
  sub_80993D8();
  gUnknown_203B18C = MemoryAlloc(sizeof(struct unkStruct_203B18C),5);
  gUnknown_203B18C->pokeID = id_s32;
  gUnknown_203B18C->faceFile = NULL;
  gUnknown_203B18C->faceData = NULL;
  if (PokemonID != 0) {
    file = GetDialogueSpriteDataPtr(id_s32);
    gUnknown_203B18C->faceFile = file;
    gUnknown_203B18C->faceData = file->data;
    gUnknown_203B18C->unk18 = 0;
    gUnknown_203B18C->unk19 = 0;
    gUnknown_203B18C->unk1A = 0;
    gUnknown_203B18C->unk14 = 2;
    gUnknown_203B18C->unk16 = 8;
  }
  if (gUnknown_203B18C->faceFile != 0) {
      // LDR r0 and R2 statements get flipped... basically matches
      sub_80141B4(&gSavingAdventure,0,(u8 *)&gUnknown_203B18C->faceFile,0x20);
  }
  else {
      sub_80141B4(&gSavingAdventure,0,0,0x20);
  }
  gUnknown_203B18C->unk0 = 3;
}
#else
NAKED
void sub_8012574(s16 PokemonID)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tlsls r0, 16\n"
	"\tasrs r4, r0, 16\n"
	"\tbl sub_80993D8\n"
	"\tldr r5, _080125D4\n"
	"\tmovs r0, 0x20\n"
	"\tmovs r1, 0x5\n"
	"\tbl MemoryAlloc\n"
	"\tstr r0, [r5]\n"
	"\tmovs r6, 0\n"
	"\tmovs r1, 0\n"
	"\tstrh r4, [r0, 0x1C]\n"
	"\tstr r1, [r0, 0xC]\n"
	"\tstr r1, [r0, 0x10]\n"
	"\tcmp r4, 0\n"
	"\tbeq _080125BA\n"
	"\tadds r0, r4, 0\n"
	"\tbl GetDialogueSpriteDataPtr\n"
	"\tldr r1, [r5]\n"
	"\tstr r0, [r1, 0xC]\n"
	"\tldr r0, [r0, 0x4]\n"
	"\tstr r0, [r1, 0x10]\n"
	"\tstrb r6, [r1, 0x18]\n"
	"\tldr r0, [r5]\n"
	"\tstrb r6, [r0, 0x19]\n"
	"\tldr r0, [r5]\n"
	"\tstrb r6, [r0, 0x1A]\n"
	"\tldr r1, [r5]\n"
	"\tmovs r0, 0x2\n"
	"\tstrh r0, [r1, 0x14]\n"
	"\tmovs r0, 0x8\n"
	"\tstrh r0, [r1, 0x16]\n"
"_080125BA:\n"
	"\tldr r1, [r5]\n"
	"\tldr r0, [r1, 0xC]\n"
	"\tcmp r0, 0\n"
	"\tbeq _080125DC\n"
	"\tadds r2, r1, 0\n"
	"\tadds r2, 0xC\n"
	"\tldr r0, _080125D8\n"
	"\tmovs r1, 0\n"
	"\tmovs r3, 0x20\n"
	"\tbl sub_80141B4\n"
	"\tb _080125E8\n"
	"\t.align 2, 0\n"
"_080125D4: .4byte gUnknown_203B18C\n"
"_080125D8: .4byte gSavingAdventure\n"
"_080125DC:\n"
	"\tldr r0, _080125F8\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x20\n"
	"\tbl sub_80141B4\n"
"_080125E8:\n"
	"\tldr r0, _080125FC\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0x3\n"
	"\tstr r0, [r1]\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_080125F8: .4byte gSavingAdventure\n"
"_080125FC: .4byte gUnknown_203B18C");

}
#endif

u8 sub_8012600(void)
{
  struct OpenedFile **faceFile;
  u32 local_14;
  u32 other_stack;
  
  faceFile = NULL;
  if (gUnknown_203B18C->faceFile != 0) {
    faceFile = &gUnknown_203B18C->faceFile;
  }
  switch(gUnknown_203B18C->unk0) 
  {
    case 0:
        gUnknown_203B18C->unk0 = 7;
        break;
    case 1:
        gUnknown_203B18C->unk4++;
        if (8 < gUnknown_203B18C->unk4) {
            sub_80141B4(&gWriteGamePak, 0, 0, 0x20);
            gUnknown_203B18C->unk0 = 3;
        }
        break;
    case 2:
        break;
    case 3:
        gUnknown_203B18C->unk0 = 4;
        break;
    case 4:
        local_14 = 0;
        sub_80140DC();
        gUnknown_203B18C->unk8 = sub_801203C(&local_14, sub_8011C1C());
        switch(gUnknown_203B18C->unk8)
        {
            case 0:
                if(gUnknown_203B18C->faceFile != NULL)
                {
                    sub_80141B4(&gSaveCompleted, 0, (u8 *)faceFile, 0x101);
                }
                else
                {
                    sub_80141B4(&gSaveCompleted, 0, (u8 *)faceFile, 0x101);
                }
                gUnknown_203B18C->unk0 = 5;
                break;
            case 1:
                sub_80141B4(&gSaveNotWritten, 0, 0, 0);
                gUnknown_203B18C->unk0 = 6;
                break;
            default:
                if(gUnknown_203B18C->faceFile != NULL)
                {
                    sub_80141B4(&gSaveFailed, 0, (u8 *)faceFile, 0x101);
                }
                else
                {
                    sub_80141B4(&gSaveFailed, 0, (u8 *)faceFile, 0x101);
                }
                gUnknown_203B18C->unk0 = 5;
                break;
        }
        sub_8014114();
        break;
    case 5:
        if (sub_80144A4(&other_stack) == 0)
            gUnknown_203B18C->unk0 = 7;
        break;
    case 6:
        break;
    case 7:
        return 0;
    }
    return 1;
}

u32 sub_8012744(void)
{
    return gUnknown_203B18C->unk8;
}

void sub_8012750(void)
{
    if(gUnknown_203B18C != NULL)
    {
        if(gUnknown_203B18C->faceFile != NULL)
        {
            CloseFile(gUnknown_203B18C->faceFile);
        }
        MemoryFree(gUnknown_203B18C);
        gUnknown_203B18C = NULL;
    }
    sub_80993E4();
}

void sub_801277C(u32 r0, u32 r1)
{
    gUnknown_203B190 = MemoryAlloc(sizeof(struct unkStruct_203B190), 5);
    gUnknown_203B190->unk4 = r0;
    gUnknown_203B190->unk8 = r1;
    gUnknown_203B190->unkC = 0;
    gUnknown_203B190->unk0 = 1;
}

u32 sub_80127A8(void)
{
    u32 stack_1;
    u32 stack_2;

    switch(gUnknown_203B190->unk0)
    {
        case 0:
            gUnknown_203B190->unk0 = 1;
            break;
        case 1:
            stack_1 = 16;
            if(sub_8011F9C(&stack_1, gUnknown_203B190->unk4, gUnknown_203B190->unk8) == 0)
            {
                gUnknown_203B190->unkC = 1;
                gUnknown_203B190->unk0 = 3;
            }
            else
            {
                sub_80141B4(&gUnknown_80D44C8, 0, 0, 0x301);
                gUnknown_203B190->unk0 = 2;
            }
            break;
        case 2:
            if(sub_80144A4(&stack_2) == 0)
                gUnknown_203B190->unk0 = 3;
            break;
        case 3:
            return 0;
        default:
            break;
    }
    return 1;
}

u8 sub_8012828(void)
{
    return gUnknown_203B190->unkC;
}

void sub_8012834(void)
{
    if(gUnknown_203B190 != NULL){
        MemoryFree(gUnknown_203B190);
        gUnknown_203B190 = 0;
    }
}

void sub_8012850(u8 *r0, u32 r1, u8 r2)
{
    gUnknown_203B194 = MemoryAlloc(sizeof(struct unkStruct_203B194), 5);
    gUnknown_203B194->unk4 = r0;
    gUnknown_203B194->unk8 = r1;
    gUnknown_203B194->unkC = r2;
    gUnknown_203B194->unk0 = 0;
    if(gUnknown_203B194->unkC != 0)
    {
        sub_80141B4(&gUnknown_80D45AC, 0, 0, 0x20);
    }
    else
    {
        sub_80141B4(&gUnknown_80D45AC, 0, 0, 0x20);
    }
}

u32 sub_80128B0(void)
{
    u32 stack_1;
    u32 stack_2;
    switch(gUnknown_203B194->unk0)
    {
        case 0:
            gUnknown_203B194->unk0 = 1;
            break;
        case 1:
            sub_80140DC();
            stack_1 = 16;
            gUnknown_203B194->unk10 = sub_80121D4(&stack_1, gUnknown_203B194->unk4, gUnknown_203B194->unk8);
            gUnknown_203B194->unk0 = 2;
            return 1;
        case 2:
            stack_1 = 0;
            if(gUnknown_203B194->unk10 == 0)
            {
                gUnknown_203B194->unk10 = sub_801203C(&stack_1, 2);
            }
            switch(gUnknown_203B194->unk10)
            {
                case 0:
                    sub_80121E0(0xf1207);
                    if(gUnknown_203B194->unkC != 0)
                    {
                        sub_80141B4(&gUnknown_80D45F4, 0, 0, 0x301);
                    }
                    else
                    {
                        sub_80141B4(&gUnknown_80D4668, 0, 0, 0x301);
                    }
                    gUnknown_203B194->unk0 = 3;
                    break;
                case 1:
                    sub_80141B4(&gUnknown_80D473C, 0, 0, 0);
                    gUnknown_203B194->unk0 = 4;
                    break;
                default:
                    sub_80121E0(0xf1209);
                    sub_80141B4(&gSaveFailed2, 0, 0, 0x301);
                    gUnknown_203B194->unk0 = 3;
                    break;
            }
            sub_8014114();
            break;
        case 3:
            if(sub_80144A4(&stack_2) == 0)
                gUnknown_203B194->unk0 = 5;
            break;
        case 4:
            break;
        case 5:
            if(gUnknown_203B194->unk10 == 0)
            {
                return 2;
            }
            else
            {
                return 3;
            }
            break;
        default:
            break;
    }
    return 0;
}

void sub_80129FC()
{
    if (gUnknown_203B194) {
        MemoryFree(gUnknown_203B194);
        gUnknown_203B194 = NULL;
    }
}

