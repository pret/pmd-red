#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "memory.h"
#include "moves.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "gulpin_shop.h"
#include "menu_input.h"

extern struct unkStruct_203B26C *gUnknown_203B26C;
extern const struct UnkTextStruct2 gUnknown_80DC11C;
extern const struct UnkTextStruct2 gUnknown_80DC134;
extern const u8 *gUnknown_80D4920[];
extern const u8 *gUnknown_80D4928[];
extern const u8 *gUnknown_80D4970[];
extern const u8 *gUnknown_80DC164[];
extern const u8 gUnknown_80DC1A0[];
extern const u8 gUnknown_80DC1FC[];
extern const u8 gUnknown_80DC230[];
extern u8 gAvailablePokemonNames[0x50 * 2];
extern const u8 *gGulpinDialogue[2][25];

extern void sub_8014248(const u8 *, u32, u32, const struct MenuItem *, void *, u32, u32, struct OpenedFile **, u32);
extern u32 sub_80144A4(s32 *);
void sub_801EC7C(void);
void sub_801ECBC(void);
void sub_801ED28(void);
void sub_801EDA4(void);
void sub_801EDC0(void);
void sub_801E980(void);
void sub_801EA28(void);
void sub_801EBC4(void);
extern void sub_801EE10(u32, s16, struct Move *, u32, void *, u32);
extern u32 sub_801EF38(u32);
extern u32 sub_801F194(void);
extern void sub_801F1B0(u32, u32);
extern void sub_801F214(void);
extern void sub_801F280(u32);
extern void sub_801F808(u16 *);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern void PlaySound(u32);
void UpdateGulpinShopState(u32);

u32 DisplayGulpinDialogueSprite(s32 param_1,s16 pokeSpecies,struct Move *param_3)
{
  struct OpenedFile *faceFile;
  s32 species_32;

  species_32 = pokeSpecies; // dumb cast needed to get lsr/asr combo
  
  gUnknown_203B26C = MemoryAlloc(sizeof(struct unkStruct_203B26C),8);
  gUnknown_203B26C->unk0 = param_1;
  gUnknown_203B26C->speciesNum = species_32;
  gUnknown_203B26C->moves = param_3;
  gUnknown_203B26C->unk1C = param_3[4].id;

  if (param_1 == 0) {
   gUnknown_203B26C->unk128 = &gUnknown_203B26C->faceFile;
  }
  else {
    gUnknown_203B26C->unk128 = NULL;
  }
  faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
  gUnknown_203B26C->faceFile = faceFile;
  gUnknown_203B26C->faceData = faceFile->data;

  gUnknown_203B26C->unk124 = 0;
  gUnknown_203B26C->unk125 = 0;
  gUnknown_203B26C->unk126 = 0;

  gUnknown_203B26C->unk120 = 2;
  gUnknown_203B26C->unk122 = 8;
  UpdateGulpinShopState(0);
  return 1;
}

u32 sub_801E8C0(void)
{
    switch(gUnknown_203B26C->state)
    {
        case 0:
        case 1:
            sub_801ECBC();
            break;
        case 2:
            sub_801ED28();
            break;
        case 3:
            sub_801EDA4();
            break;
        case 4:
            sub_801EDC0();
            if(gUnknown_203B26C->state == 5)
                return 3;
            break;
        case 5:
            return 3;
        case 6:
            return 2;
    }
  return 0;
}

bool8 GulpinIsNextMoveLinked(void)
{
    return gUnknown_203B26C->isNextMoveLinked;
}

void sub_801E93C(void)
{
    if(gUnknown_203B26C != NULL)
    {
        CloseFile(gUnknown_203B26C->faceFile);
        MemoryFree(gUnknown_203B26C);
        gUnknown_203B26C = NULL;
    }
}

void UpdateGulpinShopState(u32 newState)
{
    gUnknown_203B26C->state = newState;
    sub_801E980();
    sub_801EA28();
}

void sub_801E980(void)
{
    s32 index;

    sub_8006518(gUnknown_203B26C->unk12C);
    switch(gUnknown_203B26C->state)
    {
        case 2:
            sub_801EBC4();
            gUnknown_203B26C->unk12C[1] = gUnknown_80DC11C;
            gUnknown_203B26C->unk12C[2] = gUnknown_80DC134;
            sub_8012CAC(&gUnknown_203B26C->unk12C[2], gUnknown_203B26C->unk28);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B26C->unk12C[index] = gUnknown_80DC11C;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B26C->unk12C, 1, 1);
}

void sub_801EA28(void) {
    switch(gUnknown_203B26C->state) {
        case 0:
            sub_801EE10(2, gUnknown_203B26C->speciesNum, gUnknown_203B26C->moves, 0, &gUnknown_80DC164, 0);
            break;
        case 1:
            sub_801F1B0(1, 0);
            break;
        case 2:
            sub_801F280(0);
            sub_8012D60(&gUnknown_203B26C->unk78, gUnknown_203B26C->unk28, 0, gUnknown_203B26C->unk68, gUnknown_203B26C->unk24, 2);
            break;
        case 3:
            GetLinkedSequence(gUnknown_203B26C->unk20, gUnknown_203B26C->moves, &gUnknown_203B26C->unk14[0]);
            sub_801F808(&gUnknown_203B26C->unk14[0]);
            break;
        case 4:
            sub_801EC7C();
            sub_8092C84(gAvailablePokemonNames, gUnknown_203B26C->unk1C);
            sub_8092C84(&gAvailablePokemonNames[0x50], gUnknown_203B26C->unk1E);

            switch (gUnknown_203B26C->unk0) {
                case 0:
                case 1:
                    if (gUnknown_203B26C->isNextMoveLinked) {
                        sub_8014248(gGulpinDialogue[gUnknown_203B26C->unk0][12], 0, 5, &gUnknown_203B26C->unk28[0],
                            &gUnknown_203B26C->unk68, 4, 0, gUnknown_203B26C->unk128, 12); // Forget the move and any moves linked to it and learn?
                    }
                    else {
                        sub_8014248(gGulpinDialogue[gUnknown_203B26C->unk0][11], 0, 5, &gUnknown_203B26C->unk28[0],
                            &gUnknown_203B26C->unk68, 4, 0, gUnknown_203B26C->unk128, 12); // Forget the move and learn?
                    }
                break;
                case 2:
                    if (gUnknown_203B26C->isNextMoveLinked)
                        sub_8014248(gUnknown_80DC1A0, 0, 5, &gUnknown_203B26C->unk28[0],
                            &gUnknown_203B26C->unk68, 4, 0, NULL, 32);
                    else
                        sub_8014248(gUnknown_80DC1FC, 0, 5, &gUnknown_203B26C->unk28[0],
                            &gUnknown_203B26C->unk68, 4, 0, NULL, 32);
                break;
            }
            break;
    }
}

void sub_801EBC4(void) {
    s32 which;
    s32 i;
    which = 0;
    
    MemoryFill16(&gUnknown_203B26C->unk68[0], 0, sizeof(gUnknown_203B26C->unk68));
    
    gUnknown_203B26C->unk28[which].text = gUnknown_80DC230; // "Forget"
    gUnknown_203B26C->unk28[which].menuAction = 2;
    
    if (!IsAnyMoveLinked(gUnknown_203B26C->unk1E, gUnknown_203B26C->moves)
        || (s32)gUnknown_203B26C->unk20 >= 4) {
        gUnknown_203B26C->unk68[0] = 1;
    }
    
    which++;
    gUnknown_203B26C->unk28[which].text = *gUnknown_80D4970; // "Info"
    gUnknown_203B26C->unk28[which].menuAction = 3;
    which++;
    gUnknown_203B26C->unk28[which].text = NULL;
    gUnknown_203B26C->unk28[which].menuAction = 1;

    i = 0;
    if (i < which) {
        if (gUnknown_203B26C->unk68[0] == 0) {
            gUnknown_203B26C->unk24 = gUnknown_203B26C->unk28[0].menuAction;
        }
        else {
            while (i < which) {
                if (gUnknown_203B26C->unk68[i] == 0) {
                    gUnknown_203B26C->unk24 = gUnknown_203B26C->unk28[i].menuAction;
                    break;
                }
                i++;
            }
        }
    }    
}

void sub_801EC7C(void) {
    s32 which;
    which = 0;
    
    MemoryFill16(&gUnknown_203B26C->unk68[0], 0, sizeof(gUnknown_203B26C->unk68));
    gUnknown_203B26C->unk28[which].text = *gUnknown_80D4920; // "Yes"
    gUnknown_203B26C->unk28[which].menuAction = 4;
    which++;
    gUnknown_203B26C->unk28[which].text = *gUnknown_80D4928; // "No"
    gUnknown_203B26C->unk28[which].menuAction = 5;
    which++;
    gUnknown_203B26C->unk28[which].text = NULL;
    gUnknown_203B26C->unk28[which].menuAction = 1;
}

void sub_801ECBC(void)
{
    switch (sub_801EF38(1)) {
        case 3:
        {
            struct Move* move;
            gUnknown_203B26C->unk20 = sub_801F194();
            move = gUnknown_203B26C->moves;
            move = &move[gUnknown_203B26C->unk20];
            gUnknown_203B26C->unk1E = move->id;
            UpdateGulpinShopState(2);
            break;
        }
        case 4:
        {
            struct Move* move;
            gUnknown_203B26C->unk20 = sub_801F194();
            move = gUnknown_203B26C->moves;
            move = &move[gUnknown_203B26C->unk20];
            gUnknown_203B26C->unk1E = move->id;
            UpdateGulpinShopState(3);
            break;
        }
        case 2:
            sub_801F214();
            UpdateGulpinShopState(6);
            break;
    }
}

void sub_801ED28(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801EF38(0);
    if (sub_8012FD8(&gUnknown_203B26C->unk78) == 0)
        sub_8013114(&gUnknown_203B26C->unk78, &menuAction);

    switch(menuAction) {
        case 1:
        case 5:
            UpdateGulpinShopState(1);
            break;
        case 2:
            PlaySound(0x133);
            gUnknown_203B26C->isNextMoveLinked = IsNextMoveLinked(gUnknown_203B26C->unk20, gUnknown_203B26C->moves);
            UpdateGulpinShopState(4);
            break;
        case 3:
            UpdateGulpinShopState(3);
            break;
    }
}

void sub_801EDA4(void)
{
    switch (sub_801F890()) {
        case 2:
        case 3:
            sub_801F8D0();
            UpdateGulpinShopState(1);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_801EDC0(void)
{
    s32 temp;
    if (sub_80144A4(&temp) == 0) {
        switch (temp)
        {
            case 4:
                sub_801F214();
                RemoveLinkSequenceFromMoves8(gUnknown_203B26C->moves, gUnknown_203B26C->unk20);
                gUnknown_203B26C->state = 5;
                break;
            case 1:
            case 5:
                UpdateGulpinShopState(1);
                break;
        }
    }
}