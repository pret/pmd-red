#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "gulpin_shop.h"
#include "pokemon.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "text1.h"
#include "text2.h"

extern struct GulpinShopWork *gGulpinShopWork;
extern const UnkTextStruct2 gUnknown_80DC11C;
extern const UnkTextStruct2 gUnknown_80DC134;
extern const u8 *gUnknown_80D4920[];
extern const u8 *gUnknown_80D4928[];
extern const u8 *gUnknown_80D4970[];
extern const u8 *gUnknown_80DC164[];
extern const u8 gUnknown_80DC1A0[];
extern const u8 gUnknown_80DC1FC[];
extern const u8 gUnknown_80DC230[];
extern u8 gAvailablePokemonNames[0x50 * 2];
extern const u8 *gGulpinDialogue[2][25];

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
void SetGulpinShopState(u32);

u32 CreateGulpinShop(s32 isAsleep, s16 pokeSpecies, struct Move *moves)
{
  OpenedFile *faceFile;
  s32 species_32;

  species_32 = pokeSpecies; // dumb cast needed to get lsr/asr combo
  
  gGulpinShopWork = MemoryAlloc(sizeof(struct GulpinShopWork), 8);
  gGulpinShopWork->isAsleep = isAsleep;
  gGulpinShopWork->speciesNum = species_32;
  gGulpinShopWork->moves = moves;
  gGulpinShopWork->unk1C = moves[4].id; // 5th move..?

  if (isAsleep == 0)
    gGulpinShopWork->unk128 = &gGulpinShopWork->faceFile;
  else
    gGulpinShopWork->unk128 = NULL;

  faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
  gGulpinShopWork->faceFile = faceFile;
  gGulpinShopWork->faceData = faceFile->data;

  gGulpinShopWork->unk124 = 0;
  gGulpinShopWork->unk125 = 0;
  gGulpinShopWork->unk126 = 0;

  gGulpinShopWork->unk120 = 2;
  gGulpinShopWork->unk122 = 8;
  SetGulpinShopState(0);
  return 1;
}

u32 sub_801E8C0(void)
{
    switch (gGulpinShopWork->state) {
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
            if (gGulpinShopWork->state == 5)
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
    return gGulpinShopWork->isNextMoveLinked;
}

void DestroyGulpinShop(void)
{
    if (gGulpinShopWork != NULL) {
        CloseFile(gGulpinShopWork->faceFile);
        MemoryFree(gGulpinShopWork);
        gGulpinShopWork = NULL;
    }
}

void SetGulpinShopState(u32 newState)
{
    gGulpinShopWork->state = newState;
    sub_801E980();
    sub_801EA28();
}

void sub_801E980(void)
{
    s32 index;

    sub_8006518(gGulpinShopWork->unk12C);

    switch (gGulpinShopWork->state) {
        case 2:
            sub_801EBC4();
            gGulpinShopWork->unk12C[1] = gUnknown_80DC11C;
            gGulpinShopWork->unk12C[2] = gUnknown_80DC134;
            sub_8012CAC(&gGulpinShopWork->unk12C[2], gGulpinShopWork->unk28);
            break;
        default:
            for(index = 0; index < 4; index++) {
                gGulpinShopWork->unk12C[index] = gUnknown_80DC11C;
            }
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(gGulpinShopWork->unk12C, TRUE, TRUE);
}

void sub_801EA28(void)
{
    switch (gGulpinShopWork->state) {
        case 0:
            sub_801EE10(2, gGulpinShopWork->speciesNum, gGulpinShopWork->moves, 0, gUnknown_80DC164, 0);
            break;
        case 1:
            sub_801F1B0(1, 0);
            break;
        case 2:
            sub_801F280(0);
            sub_8012D60(&gGulpinShopWork->unk78, gGulpinShopWork->unk28, 0, gGulpinShopWork->unk68, gGulpinShopWork->unk24, 2);
            break;
        case 3:
            GetLinkedSequence(gGulpinShopWork->unk20, gGulpinShopWork->moves, &gGulpinShopWork->unk14[0]);
            sub_801F808(&gGulpinShopWork->unk14[0]);
            break;
        case 4:
            sub_801EC7C();
            sub_8092C84(gAvailablePokemonNames, gGulpinShopWork->unk1C);
            sub_8092C84(&gAvailablePokemonNames[0x50], gGulpinShopWork->unk1E);

            switch (gGulpinShopWork->isAsleep) {
                case 0:
                case 1:
                    if (gGulpinShopWork->isNextMoveLinked)
                        sub_8014248(gGulpinDialogue[gGulpinShopWork->isAsleep][12], 0, 5, &gGulpinShopWork->unk28[0],
                            &gGulpinShopWork->unk68, 4, 0, gGulpinShopWork->unk128, 12); // Forget the move and any moves linked to it and learn?
                    else
                        sub_8014248(gGulpinDialogue[gGulpinShopWork->isAsleep][11], 0, 5, &gGulpinShopWork->unk28[0],
                            &gGulpinShopWork->unk68, 4, 0, gGulpinShopWork->unk128, 12); // Forget the move and learn?
                    break;
                case 2:
                    if (gGulpinShopWork->isNextMoveLinked)
                        sub_8014248(gUnknown_80DC1A0, 0, 5, &gGulpinShopWork->unk28[0],
                            &gGulpinShopWork->unk68, 4, 0, NULL, 32);
                    else
                        sub_8014248(gUnknown_80DC1FC, 0, 5, &gGulpinShopWork->unk28[0],
                            &gGulpinShopWork->unk68, 4, 0, NULL, 32);
                    break;
            }
            break;
    }
}

void sub_801EBC4(void)
{
    s32 which;
    s32 i;
    which = 0;
    
    MemoryFill16(gGulpinShopWork->unk68, 0, sizeof(gGulpinShopWork->unk68));
    
    gGulpinShopWork->unk28[which].text = gUnknown_80DC230; // "Forget"
    gGulpinShopWork->unk28[which].menuAction = 2;
    
    if (!IsAnyMoveLinked(gGulpinShopWork->unk1E, gGulpinShopWork->moves) || (s32)gGulpinShopWork->unk20 >= 4)
        gGulpinShopWork->unk68[0] = 1;
    
    which++;
    gGulpinShopWork->unk28[which].text = *gUnknown_80D4970; // "Info"
    gGulpinShopWork->unk28[which].menuAction = 3;
    which++;
    gGulpinShopWork->unk28[which].text = NULL;
    gGulpinShopWork->unk28[which].menuAction = 1;

    i = 0;
    if (i < which) {
        if (gGulpinShopWork->unk68[0] == 0)
            gGulpinShopWork->unk24 = gGulpinShopWork->unk28[0].menuAction;
        else {
            while (i < which) {
                if (gGulpinShopWork->unk68[i] == 0) {
                    gGulpinShopWork->unk24 = gGulpinShopWork->unk28[i].menuAction;
                    break;
                }
                i++;
            }
        }
    }
}

void sub_801EC7C(void)
{
    s32 which;
    which = 0;
    
    MemoryFill16(gGulpinShopWork->unk68, 0, sizeof(gGulpinShopWork->unk68));
    gGulpinShopWork->unk28[which].text = *gUnknown_80D4920; // "Yes"
    gGulpinShopWork->unk28[which].menuAction = 4;
    which++;
    gGulpinShopWork->unk28[which].text = *gUnknown_80D4928; // "No"
    gGulpinShopWork->unk28[which].menuAction = 5;
    which++;
    gGulpinShopWork->unk28[which].text = NULL;
    gGulpinShopWork->unk28[which].menuAction = 1;
}

void sub_801ECBC(void)
{
    switch (sub_801EF38(1)) {
        case 3:
        {
            struct Move* move;
            gGulpinShopWork->unk20 = sub_801F194();
            move = gGulpinShopWork->moves;
            move = &move[gGulpinShopWork->unk20];
            gGulpinShopWork->unk1E = move->id;
            SetGulpinShopState(2);
            break;
        }
        case 4:
        {
            struct Move* move;
            gGulpinShopWork->unk20 = sub_801F194();
            move = gGulpinShopWork->moves;
            move = &move[gGulpinShopWork->unk20];
            gGulpinShopWork->unk1E = move->id;
            SetGulpinShopState(3);
            break;
        }
        case 2:
            sub_801F214();
            SetGulpinShopState(6);
            break;
    }
}

void sub_801ED28(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801EF38(0);
    if (sub_8012FD8(&gGulpinShopWork->unk78) == 0)
        sub_8013114(&gGulpinShopWork->unk78, &menuAction);

    switch (menuAction) {
        case 1:
        case 5:
            SetGulpinShopState(1);
            break;
        case 2:
            PlaySound(0x133);
            gGulpinShopWork->isNextMoveLinked = IsNextMoveLinked(gGulpinShopWork->unk20, gGulpinShopWork->moves);
            SetGulpinShopState(4);
            break;
        case 3:
            SetGulpinShopState(3);
            break;
    }
}

void sub_801EDA4(void)
{
    switch (sub_801F890()) {
        case 2:
        case 3:
            sub_801F8D0();
            SetGulpinShopState(1);
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
        switch (temp) {
            case 4:
                sub_801F214();
                RemoveLinkSequenceFromMoves8(gGulpinShopWork->moves, gGulpinShopWork->unk20);
                gGulpinShopWork->state = 5;
                break;
            case 1:
            case 5:
                SetGulpinShopState(1);
                break;
        }
    }
}
