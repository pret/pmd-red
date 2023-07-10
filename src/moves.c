#include "global.h"
#include "moves.h"
#include "code_8092334.h"
#include "memory.h"
#include "pokemon.h"
#include "subStruct_203B240.h"
#include "code_809447C.h"
#include "text_util.h"

#include "constants/colors.h"
#include "constants/monster.h"
#include "file_system.h"
#include "code_800D090.h"

struct MoveLearnset {
    u8 *levelUpMoves;
    u8 *HMTMMoves;
};

struct MoveDataFile
{
    struct MoveDataEntry *moveData;
    struct MoveLearnset *moveLearnsets;
};


extern struct unkStruct_80928C0 gUnknown_81098C4;
extern struct FileArchive gSystemFileArchive;

extern struct OpenedFile *gWazaParametersFile;
extern struct MoveDataEntry *gMovesData;
extern struct MoveLearnset *gMoveLearnsets[420];

extern u8 gUnknown_81098D0[];
extern u8 gUnknown_81098DC[];
extern u8 gUnknown_810990C[];
extern u8 gUnknown_8109908[];
extern u8 gUnknown_8109928[];
extern u8 gUnknown_8109910[];
extern u8 gUnknown_81098E0[];
extern u8 gUnknown_81098EC[];
extern u8 *gRangeNames[];
extern u8 gUnknown_810992C[];
extern u8 gUnknown_810992B;

extern void sub_8093F10(struct Move *, struct Move *);
extern void sub_80928C0(u8 *, struct Move *, struct unkStruct_80928C0 *);

extern u8 gAvailablePokemonNames[];
extern const char gUnknown_8109930[];
extern struct MoveDataEntry *gMovesData;

bool8 UnlinkMovesAfter(int param_1, struct Move* src_struct);
bool8 TryLinkMovesAfter(int param_1, struct Move* src_struct);
bool8 sub_80933D8(int param_1, void* src_struct);
bool8 DoesMoveCharge(u16 move);

int unk_PrintMoveDescription(int, struct Move*, int, struct subStruct_203B240**);

extern void sub_80073B8(u32);
void sub_80928C0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *param_3);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);
extern void unk_MovePrintData(struct Move*, int);  // print something
extern void sub_80073E0(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);

extern void sub_80078A4(u32, u32, u32, u32, u32);
extern u8 sub_8092B00(struct Move*);
extern u32 sub_8092BC0(struct Move*);
extern u32 gUnknown_202DE30;
extern u8* gPtrTypeText;     // "Type"
extern u8* gUnknown_810CF00; // "Range#=@.$m0 "

void LoadWazaParameters(void)
{
    gWazaParametersFile = OpenFileAndGetFileDataPtr(gUnknown_81098D0, &gSystemFileArchive);

    gMovesData = ((struct MoveDataFile *)(gWazaParametersFile->data))->moveData;
    *gMoveLearnsets = ((struct MoveDataFile *)(gWazaParametersFile->data))->moveLearnsets;
}

u8 sub_809287C(struct Move *move)
{
    if((move->moveFlags & MOVE_FLAG_DISABLED) != 0)
        return 0x32;
    else if((move->moveFlags2 & MOVE_FLAG_SEALED) == 0)
        return 0x34;
    else
        return 0x32;
}

void sub_80928A0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *r2)
{
    struct Move stack;
    CopyAndResetMove(&stack, move);
    sub_80928C0(buffer, &stack, r2);
}

void sub_80928C0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *param_3)
{
  u32 uVar2;
  u32 basePP;
  u8 localBuffer[12];

  uVar2 = sub_809287C(move);
  if (param_3 == NULL) {
    param_3 = &gUnknown_81098C4;
  }

  if (move->ginseng != 0)
      sprintfStatic(localBuffer,gUnknown_81098DC,move->ginseng); // %+d
  else
      localBuffer[0] = '\0';

  if (param_3->unk8 != 0) {
        uVar2 = 2;
  }
  if (param_3->unk9 != 0 && DoesMoveCharge(move->id)) {
        uVar2 = 2;
  }
  switch(param_3->unk0) {
        case 0:
            sprintfStatic
                    (buffer,gUnknown_81098E0,uVar2,
                    gMovesData[move->id].name,localBuffer);
            break;

        case 1:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_81098EC,uVar2,move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;

        case 2:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_8109910,uVar2,move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;

        case 3:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_81098EC,uVar2,move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? gUnknown_8109928 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;

        case 4:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_8109910,uVar2, move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? gUnknown_8109928 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;
        }
}

void InitPokemonMove(struct Move *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
    move->moveFlags2 = 0;
    move->id = moveID;
    move->PP = GetMoveBasePP(move);
    move->ginseng = 0;
}

void sub_8092AA8(struct Move *move, u16 moveID)
{
    if(moveID == 0)
        move->moveFlags = 0;
    else
    {
        move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
        move->moveFlags2 = 0;
        move->id = moveID;
        move->PP = GetMoveBasePP(move);
        move->ginseng = 0;
    }
}

void InitZeroedPPPokemonMove(struct Move *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
    move->id = moveID;
    move->PP = 0;
}

s16 GetMoveTargetAndRange(struct Move *move, bool32 isAI)
{
    return gMovesData[move->id].targetingFlags[isAI];
}

u8 GetMoveType(struct Move *move)
{
    return gMovesData[move->id].type;
}


u8 *GetLevelUpMoves(s16 species)
{

#ifndef NONMATCHING
    register s32 species1 asm("r1"), species2;
#else
    s32 species1, species2;
#endif

    species1 = species;
    species2 = species1;
    if (species1 == MONSTER_DECOY || species1 == MONSTER_NONE)
    {
        return &gUnknown_810992B;
    }
    if (species2 == MONSTER_MUNCHLAX)
    {
        return &gUnknown_810992B;
    }
    return (*gMoveLearnsets)[species2].levelUpMoves;
}

u8 *GetHMTMMoves(s16 species)
{

#ifndef NONMATCHING
    register s32 species1 asm("r1"), species2;
#else
    s32 species1, species2;
#endif

    species1 = species;
    species2 = species1;
    if (species1 == MONSTER_DECOY || species1 == MONSTER_NONE)
    {
        return &gUnknown_810992B;
    }
    if (species2 == MONSTER_MUNCHLAX)
    {
        return &gUnknown_810992B;
    }
    return (*gMoveLearnsets)[species2].HMTMMoves;
}

u8 GetMoveAIWeight(struct Move *move)
{
    return gMovesData[move->id].aiWeight;
}

u32 GetMoveNumberOfChainedHits(struct Move *move)
{
    return gMovesData[move->id].numberOfChainedHits;
}

s32 GetMoveBasePower(struct Move *move)
{
    return gMovesData[move->id].basePower;
}

s32 GetMoveAccuracyOrAIChance(struct Move *move, u32 accuracyType)
{
    return gMovesData[move->id].accuracy[accuracyType];
}

u32 GetMoveBasePP(struct Move *move)
{
    return gMovesData[move->id].basePP;
}

u32 GetMoveMaxUpgradeLevel(struct Move *move)
{
    return gMovesData[move->id].maxUpgradeLevel;
}

u32 GetMoveCritChance(struct Move *move)
{
    return gMovesData[move->id].critChance;
}

bool8 MoveCannotHitFrozen(struct Move *move)
{
    return gMovesData[move->id].cannotHitFrozen;
}

bool8 MovesIgnoresTaunted(struct Move *move)
{
    return gMovesData[move->id].ignoresTaunted;
}

u32 GetMoveRangeID(struct Move *move)
{
    return gMovesData[move->id].rangeID;
}

void sub_8092C84(u8 *buffer, u16 moveID)
{
    struct Move stack;
    InitPokemonMove(&stack, moveID);
    sub_80928C0(buffer, &stack, NULL);
}

u8 *GetMoveUseText(u16 moveID)
{
    return gMovesData[moveID].useText;
}

bool8 IsReflectedByMagicCoat(u16 moveID)
{
    return gMovesData[moveID].affectedByMagicCoat;
}

bool8 CanBeSnatched(u16 moveID)
{
    return gMovesData[moveID].isSnatchable;
}

bool8 FailsWhileMuzzled(u16 moveID)
{
    return gMovesData[moveID].usesMouth;
}

bool8 IsSoundMove(struct Move *move)
{
    if(move->id == MOVE_GROWL)  return TRUE;
    if(move->id == MOVE_ROAR)  return TRUE;
    if(move->id == MOVE_METAL_SOUND)  return TRUE;
    if(move->id == MOVE_SING)  return TRUE;
    if(move->id == MOVE_GRASSWHISTLE)  return TRUE;
    if(move->id == MOVE_SUPERSONIC)  return TRUE;
    if(move->id == MOVE_PERISH_SONG)  return TRUE;
    if(move->id == MOVE_SCREECH)  return TRUE;
    if(move->id == MOVE_HYPER_VOICE)  return TRUE;
    if(move->id == MOVE_SNORE)  return TRUE;
    if(move->id == MOVE_HEAL_BELL)  return TRUE;

    return FALSE;
}

void sub_8092D54(u8 *buffer, struct Move *move)
{
    sprintfStatic(buffer, gUnknown_810992C, gRangeNames[GetMoveRangeID(move)]);
}

// this function is the same as the two after the next one
// except this one is for 4, and the other 2 for 8 and 8_v2
int unk_FindMoveEnabledForAIAfter4(struct Move* moves, int index) {
    int i;
    
    for (i = 0; i < 4; i++) {
        u8 flag;
        
        if (++index == 4) {
            return 0;
        }
        
        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS)) {
            return 0;
        }
        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1)) {
            return index;
        }
    }
    return 0;
}

int sub_8092DB8(struct Move* moves, int index) {
    int i, j;
    
    for (i = 0; i < 4; i++) {
        u8 flag;
        
        if (--index < 0) {
            for (j = 3; j >= 0; j--) {
                if (!(moves[j].moveFlags & MOVE_FLAG_EXISTS)) {
                    continue;
                }

                index = j;
                break;
            }

            // return 0 if loop ends without setting index
            if (j < 0) 
                return 0;
        }
        
        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS)) {
            return 0;
        }
        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1)) {
            return index;
        }
    }
    return 0;
}

int unk_FindMoveEnabledForAIAfter8(struct Move* moves, int index) {
    int i;
    
    for (i = 0; i < 8; i++) {
        u8 flag;
        
        if (++index == 8) {
            return 0;
        }
        
        if (!(moves[index].moveFlags & 1)) {
            return 0;
        }
        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1)) {
            return index;
        }
    }
    return 0;
}

int unk_FindMoveEnabledForAIAfter8_v2(struct Move* moves, int index) {
    int i;
    
    for (i = 0; i < 8; i++) {
        u8 flag;
        
        if (++index == 8) {
            return 0;
        }
        
        if (!(moves[index].moveFlags & 1)) {
            return 0;
        }
        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1)) {
            return index;
        }
    }
    return 0;
}

// the next 2 functions are the same
// should be 8 and 8_v2
int unk_FindMoveEnabledForAIBefore8(struct Move* moves, int index) {
    int i, j;
    
    for (i = 0; i < 8; i++) {
        u8 flag;
        
        if (--index < 0) {
            for (j = 7; j > 0; j--) {
                if (!(moves[j].moveFlags & MOVE_FLAG_EXISTS)) {
                    continue;
                }
                
                // checks MOVE_FLAG_ENABLED_FOR_AI
                flag = (moves[j].moveFlags >> 1);
                if (!(flag & 1)) {
                    return j;
                }
            }
            return 0;
        }
        
        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS)) {
            return 0;
        }
        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1)) {
            return index;
        }
    }
    return 0;
}

int unk_FindMoveEnabledForAIBefore8_v2(struct Move* moves, int index) {
    int i, j;
    
    for (i = 0; i < 8; i++) {
        u8 flag;
        
        if (--index < 0) {
            for (j = 7; j > 0; j--) {
                if (!(moves[j].moveFlags & MOVE_FLAG_EXISTS)) {
                    continue;
                }
                
                // checks MOVE_FLAG_ENABLED_FOR_AI
                flag = (moves[j].moveFlags >> 1);
                if (!(flag & 1)) {
                    return j;
                }
            }
            return 0;
        }
        
        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS)) {
            return 0;
        }
        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1)) {
            return index;
        }
    }
    return 0;
}

int sub_8092F4C(struct Move* moves, int index) {
    int i;
    for (i = index; i > 0; i--) {
        struct Move* move = &moves[i];
        u8 flag;
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            return 0;
        }
        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (move->moveFlags >> 1);
        if (!(flag & 1)) {
            return i;
        }
    }
    return 0;
}

// the next 3 functions are the same, except the first
// is for 4, then for 8 then for 8_v2
int unk_SetMoveToLastInLinkedSequence4(struct Move* moves, int index) {
    struct Move* move;
    struct Move linkedSequence[4][4];
    s32 startIndex;
    int result;
    int i;
    
    result = index;
    
    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences4(moves, linkedSequence);
    
    startIndex = unk_FindMarkedMoveInLinkedSequences44(linkedSequence);
    if (startIndex >= 0 && startIndex < 3) {
        for (i = 0; i < 4; i++) {
            const struct Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[startIndex + 1][i];
            linkedSequence[startIndex + 1][i] = temp;
        }
    }
    
    unk_LinkedSequencesToMoves4(moves, linkedSequence);
    for (startIndex = 0; startIndex < 4; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }
    return result;
}

int unk_SetMoveToLastInLinkedSequence8(struct Move* moves, int index) {
    struct Move* move;
    struct Move linkedSequence[8][8];
    s32 startIndex;
    int result;
    int i;
    
    result = index;
    
    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8(moves, linkedSequence);
    
    startIndex = unk_FindMarkedMoveInLinkedSequences88(linkedSequence);
    if (startIndex >= 0 && startIndex < 7) {
        for (i = 0; i < 8; i++) {
            const struct Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[startIndex + 1][i];
            linkedSequence[startIndex + 1][i] = temp;
        }
    }
    
    unk_LinkedSequencesToMoves8(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }
    return result;
}

int unk_SetMoveToLastInLinkedSequence8_v2(struct Move* moves, int index) {
    struct Move* move;
    struct Move linkedSequence[8][8];
    s32 startIndex;
    int result;
    int i;
    
    result = index;
    
    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8_v2(moves, linkedSequence);
    
    startIndex = unk_FindMarkedMoveInLinkedSequences88_v2(linkedSequence);
    if (startIndex >= 0 && startIndex < 7) {
        for (i = 0; i < 8; i++) {
            const struct Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[startIndex + 1][i];
            linkedSequence[startIndex + 1][i] = temp;
        }
    }
    
    unk_LinkedSequencesToMoves8_v2(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }
    return result;
}

// the next 3 functions are the same, but for
// 4, 8 and 8_v2
int unk_SetMoveToFirstInLinkedSequence4(struct Move* moves, int index) {
    struct Move* move;
    struct Move linkedSequence[4][4];
    s32 startIndex, prevIndex;
    int result;
    int i;
    
    result = index;
    
    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences4(moves, linkedSequence);
    
    startIndex = unk_FindMarkedMoveInLinkedSequences44(linkedSequence);
    prevIndex = startIndex - 1;
    if (prevIndex >= 0 && prevIndex < 3) {
        for (i = 0; i < 4; i++) {
            const struct Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[prevIndex][i];
            linkedSequence[prevIndex][i] = temp;
        }
    }
    
    unk_LinkedSequencesToMoves4(moves, linkedSequence);
    for (startIndex = 0; startIndex < 4; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }
    return result;
}

int unk_SetMoveToFirstInLinkedSequence8(struct Move* moves, int index) {
    struct Move* move;
    struct Move linkedSequence[8][8];
    s32 startIndex, prevIndex;
    int result;
    int i;
    
    result = index;
    
    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8(moves, linkedSequence);
    
    startIndex = unk_FindMarkedMoveInLinkedSequences88(linkedSequence);
    prevIndex = startIndex - 1;
    if (prevIndex >= 0 && prevIndex < 7) {
        for (i = 0; i < 8; i++) {
            const struct Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[prevIndex][i];
            linkedSequence[prevIndex][i] = temp;
        }
    }
    
    unk_LinkedSequencesToMoves8(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }
    return result;
}

int unk_SetMoveToFirstInLinkedSequence8_v2(struct Move* moves, int index) {
    struct Move* move;
    struct Move linkedSequence[8][8];
    s32 startIndex, prevIndex;
    int result;
    int i;
    
    result = index;
    
    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8_v2(moves, linkedSequence);
    
    startIndex = unk_FindMarkedMoveInLinkedSequences88_v2(linkedSequence);
    prevIndex = startIndex - 1;
    if (prevIndex >= 0 && prevIndex < 7) {
        for (i = 0; i < 8; i++) {
            const struct Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[prevIndex][i];
            linkedSequence[prevIndex][i] = temp;
        }
    }
    
    unk_LinkedSequencesToMoves8_v2(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }
    return result;
}

bool8 IsMoveSet(int index, struct Move* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_SET) != 0) {
        return TRUE;
    }
    return FALSE;
}

bool8 IsMoveEnabled(int index, struct Move* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) != 0) {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8093318(int param_1, void* src_struct)
{
    struct Move dest_struct[8];
    MemoryCopy8((void*)dest_struct, src_struct, 64);
    return TryLinkMovesAfter(param_1, dest_struct);
}

bool8 sub_809333C(int param_1, void* src_struct)
{
    struct Move dest_struct[8];
    MemoryCopy8((void*)dest_struct, src_struct, 64);
    return UnlinkMovesAfter(param_1, dest_struct);
}

bool8 sub_8093360(int param_1, void* src_struct)
{
    u8 dest_struct[64];
    MemoryCopy8(dest_struct, src_struct, 64);
    return sub_80933D8(param_1, dest_struct);
}

// appears unused
bool8 IsMoveNotSet(int index, struct Move* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_SET) != 0) {
        return FALSE;
    }
    return TRUE;
}

bool8 IsAnyMoveLinked(int unused, struct Move* moves) {
    int i;
    int counter;

    counter = 0;
    for (i = 0; i < 8; i++) {
        if ((moves[i].moveFlags & MOVE_FLAG_EXISTS) && !(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            counter++;
        }
    }
    if (counter > 1) {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80933D8(int param_1, void* src_struct)
{
  int result;

  if (!TryLinkMovesAfter(param_1, src_struct)) {
    result = UnlinkMovesAfter(param_1, src_struct);
  }
  else {
    result = TRUE;
  }
  return result;
}

bool8 TryLinkMovesAfter(int index, struct Move* moves) {
    int i;
    const struct Move *move = &moves[index];
    if (DoesMoveCharge(move->id)) {
        return FALSE;
    }
    
    for (i = index + 1; i < 8; i++) {
        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS)) {
            return FALSE;
        }
        if (DoesMoveCharge(moves[i].id)) {
            return FALSE;
        }
        if (!(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moves[i].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            unk_FixLinkedMovesSetEnabled8_v2(moves);
            return TRUE;
        }
    }
    return FALSE;
}

bool8 UnlinkMovesAfter(int index, struct Move* moves) {
    int i;
    bool8 result = FALSE;
    int r4;

    for (i = index + 1, r4 = 0; r4 < 8 && i < 8; i++, r4++) {
        if (!(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            goto label; // for some reason we can't use break here
        moves[i].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
        result = TRUE;
    }
label:
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return result;
}


bool8 IsNextMoveLinked(int index, struct Move* moves) {
    struct Move* move;
    if (index + 1 >= 8) {
        return FALSE;
    }
    move = &moves[index + 1];
    if (!(move->moveFlags & MOVE_FLAG_EXISTS))
        return FALSE;
    if ((move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
        return TRUE;
    return FALSE;
}

bool8 ToggleSetMove(int index, struct Move* moves) {
    struct Move* move;
    u8 flags;
    int i;

    move = &moves[index];
    if (moves[index].moveFlags & MOVE_FLAG_SET) {
        flags = move->moveFlags & ~MOVE_FLAG_SET;
    }
    else {
        // clear set flag from other moves
        for (i = 0; i < 4; i++) {
            if (moves[i].moveFlags & MOVE_FLAG_EXISTS) {
                moves[i].moveFlags &= ~MOVE_FLAG_SET;
            }
        }
        flags = move->moveFlags | MOVE_FLAG_SET;
    }
    move->moveFlags = flags;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return TRUE;
}

void UnSetMove(int index, struct Move* moves) {
    struct Move* move = &moves[index];
    move->moveFlags &= ~MOVE_FLAG_SET;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
}

bool8 ToggleMoveEnabled(int index, struct Move* moves) {
    struct Move* move = &moves[index];
    move->moveFlags ^= MOVE_FLAG_ENABLED_FOR_AI;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return TRUE;
}

int GetLinkedSequence(int index, struct Move* moves, u16* sequenceMoveIDs) {
    int i;
    int linkedSequenceLength;
    struct Move* move;

    linkedSequenceLength = 1;
    move = &moves[index];
    sequenceMoveIDs[0] = move->id;
    for (i = 1; i < 4; i++) {
        sequenceMoveIDs[i] = 0;
    }

    for (index++, sequenceMoveIDs++; index < 8 && linkedSequenceLength <= 3; index++) {
        move = &moves[index];
        if ((move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN) == 0) {
            return linkedSequenceLength;
        }

        *sequenceMoveIDs++ = move->id;
        linkedSequenceLength++;
    }
    return linkedSequenceLength;
}

int sub_80935B8(struct Move *moves, int index) {
    int i;
    int linkSequenceStart;
    int isNonTrivialLinkSequence;
    int any_move_linked;
    int pp;
    int v1;
    
    pp = 99;
    any_move_linked = 0;
    isNonTrivialLinkSequence = 0;

    linkSequenceStart = index;
    while (linkSequenceStart >= 0) {
        struct Move *move = &moves[linkSequenceStart];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))) {
            break;
        }
        
        linkSequenceStart--;
    }

    // this is so stupid but it works
    isNonTrivialLinkSequence++;isNonTrivialLinkSequence--;

    for (i = linkSequenceStart + 1; i < 4; i++) {
        struct Move *move = &moves[i];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))) {
            break;
        }
        
        isNonTrivialLinkSequence = 1;
    }

    if (!isNonTrivialLinkSequence) {
        return 99;
    }

    v1 = 0;
    while (--i >= linkSequenceStart) {
        struct Move* move = &moves[i];
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        if (pp > move->PP) {
            pp = move->PP;
        }
        if (move->PP == 0) {
            v1 = 1;
        }
        if (move->moveFlags2 & MOVE_FLAG_REPLACE) {
            v1 = 1;
        }
    }

    if (!v1) {
        return pp;
    }

    for (i = linkSequenceStart + 1; i < 4; i++) {
        struct Move* move = &moves[i];
        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        
        if (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN) {
            move->moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            any_move_linked = 1;
        }
        else {
            break;
        }
    }

    if (any_move_linked) {
        return 0;
    }
    else {
        return pp;
    }
}

void unk_FixLinkedMovesSetEnabled4(struct Move* moves) {
    struct Move linkedSequences[4][4];

    // all that doing these in a row seems to do is
    // fix the set/enabled flags by moving them to
    // the first move of every linked sequence
    unk_GetLinkedSequences4(moves, linkedSequences);
    unk_LinkedSequencesToMoves4(moves, linkedSequences);
}

void unk_FixLinkedMovesSetEnabled8(struct Move* moves) {
    struct Move linkedSequences[8][8];
    unk_GetLinkedSequences8(moves, linkedSequences);
    unk_LinkedSequencesToMoves8(moves, linkedSequences);
}

void unk_FixLinkedMovesSetEnabled8_v2(struct Move* moves) {
    struct Move linkedSequences[8][8];

    unk_GetLinkedSequences8_v2(moves, linkedSequences);
    unk_LinkedSequencesToMoves8_v2(moves, linkedSequences);
}

int unk_FindMarkedMoveInLinkedSequences44(struct Move moves[4][4]) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if ((moves[i][j].moveFlags & MOVE_FLAG_EXISTS) && (moves[i][j].moveFlags & MOVE_FLAG_INTERNAL_MARKER)) {
                return i;
            }
        }
    }
    return -1;
}

void unk_GetLinkedSequences4(struct Move* moves, struct Move linkedSequences[4][4]) {
    int i, j;
    int k;
    int moveSetIndex;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            linkedSequences[i][j].moveFlags = 0;
        }
    }

    moveSetIndex = -1;
    for (j = 0, k = 0; k < 4; j++, k++) {
        if (k == 0 || !(moves[k].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moveSetIndex++;
            j = 0;
        }
        linkedSequences[moveSetIndex][j] = moves[k];
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}


void unk_LinkedSequencesToMoves4(struct Move* moves, struct Move linkedSequences[4][4]) {
    int i, j;
    int movesCopied;
    
    bool8 moves_set[4];
    bool8 moves_enabled[4];

    movesCopied = 0;
    
    // figure out which linked sequences contain set / enabled moves
    for (i = 0; i < 4; i++) {
        moves_set[i] = 0;
        moves_enabled[i] = 0;

        for (j = 0; j < 4; j++) {
            u8 flag;
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;
            if (flag) {
                moves_set[i] = TRUE;
            }
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) {
                moves_enabled[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = linkedSequences[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;
                if (moves_set[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moves_enabled[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;
                }

                movesCopied++;
                if (movesCopied == 4) {
                    return;
                }
            }
        }
    }
}

// the next two functions are exactly the same
int unk_FindMarkedMoveInLinkedSequences88(struct Move linkedSequences[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) && (linkedSequences[i][j].moveFlags & MOVE_FLAG_INTERNAL_MARKER)) {
                return i;
            }
        }
    }
    
    return -1;
}

// I expect the intent was to check for a different flag in this one
// or the argument is a struct type that does hold the moves as a field
int unk_FindMarkedMoveInLinkedSequences88_v2(struct Move linkedSequences[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) && (linkedSequences[i][j].moveFlags & MOVE_FLAG_INTERNAL_MARKER)) {
                return i;
            }
        }
    }
    
    return -1;
}

// again, the next two functions are exactly the same
// they are also the same as unk_GetLinkedSequences4 but for [8][8] linkedSequences instead of
// [4][4] linkedSequences

// it seems to find all the _actually_ separate moves, and split them
// out into link sequences in the destination linkedSequences
void unk_GetLinkedSequences8(struct Move* moves, struct Move linkedSequences[8][8]) {
    int i, j;
    int k;
    int moveSetIndex;

    // clear out linkedSequences
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            linkedSequences[i][j].moveFlags = 0;
        }
    }

    moveSetIndex = -1;
    for (j = 0, k = 0; k < 8; j++, k++) {
        struct Move* move = &moves[k];
        if (k == 0 || !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moveSetIndex++;
            j = 0;
        }
        linkedSequences[moveSetIndex][j] = *move;
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}

void unk_GetLinkedSequences8_v2(struct Move* moves, struct Move linkedSequences[8][8]) {
    int i, j;
    int k;
    int moveSetIndex;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            linkedSequences[i][j].moveFlags = 0;
        }
    }
    moveSetIndex = -1;
    for (j = 0, k = 0; k < 8; j++, k++) {
        struct Move* move = &moves[k];
        if (k == 0 || !(move->moveFlags & 2)) {
            moveSetIndex++;
            j = 0;
        }
        linkedSequences[moveSetIndex][j] = *move;
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}

// the next 2 functions are again exactly the same
// these functions are the same as unk_LinkedSequencesToMoves4 but for [8][8] linkedSequences
// instead of [4][4] linkedSequences
void unk_LinkedSequencesToMoves8(struct Move* moves, struct Move linkedSequences[8][8]) {
    int i, j;
    int movesCopied;
    
    bool8 moveFlags8[8];
    bool8 moveFlags4[8];

    movesCopied = 0;
    
    for (i = 0; i < 8; i++) {
        moveFlags8[i] = 0;
        moveFlags4[i] = 0;

        for (j = 0; j < 8; j++) {
            u8 flag;
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;
            if (flag) {
                moveFlags8[i] = TRUE;
            }
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) {
                moveFlags4[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = linkedSequences[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;
                if (moveFlags8[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moveFlags4[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;
                }

                movesCopied++;
                if (movesCopied == 8) {
                    return;
                }
            }
        }
    }
}

void unk_LinkedSequencesToMoves8_v2(struct Move* moves, struct Move linkedSequences[8][8]) {
    int i, j;
    int movesCopied;
    
    bool8 moveFlags8[8];
    bool8 moveFlags4[8];

    movesCopied = 0;
    
    for (i = 0; i < 8; i++) {
        moveFlags8[i] = 0;
        moveFlags4[i] = 0;

        for (j = 0; j < 8; j++) {
            u8 flag;
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;
            if (flag) {
                moveFlags8[i] = TRUE;
            }
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) {
                moveFlags4[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = linkedSequences[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;
                if (moveFlags8[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moveFlags4[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;
                }

                movesCopied++;
                if (movesCopied == 8) {
                    return;
                }
            }
        }
    }
}


// the next two are again the same
void RemoveLinkSequenceFromMoves8_v2(struct Move* moves, int index) {
    int i;
    int copiedMoves;
    struct Move moveSet[8];
    
    moves[index].moveFlags = 0;
    for (i = index + 1; i < 8; i++) {
        struct Move* move = &moves[i];

        // TODO: don't do this trickery
        asm("");
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            break;
        }

        move->moveFlags = 0;
    }

    copiedMoves = 0;
    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS) {
            moveSet[copiedMoves++] = moves[i];
        }
    }

    while (copiedMoves < 8) {
        moveSet[copiedMoves++].moveFlags = 0;
    }

    for (i = 0; i < 8; i++) {
        moves[i] = moveSet[i];
    }
}

void RemoveLinkSequenceFromMoves8(struct Move* moves, int index) {
    int i;
    int copiedMoves;
    struct Move moveSet[8];
    
    // remove link sequence (set flags to 0)
    moves[index].moveFlags = 0;
    for (i = index + 1; i < 8; i++) {
        struct Move* move = &moves[i];
        asm("");
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            break;
        }

        move->moveFlags = 0;
    }

    // copy over other moves
    copiedMoves = 0;
    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS) {
            moveSet[copiedMoves++] = moves[i];
        }
    }

    // fill with nonexistent moves
    while (copiedMoves < 8) {
        moveSet[copiedMoves++].moveFlags = 0;
    }

    // copy back to original moves pointer
    for (i = 0; i < 8; i++) {
        moves[i] = moveSet[i];
    }
}

int unk_MoveIDPrintMoveDescription(int a1, u16 moveID, int a3, struct subStruct_203B240** a4) {
    struct Move move;

    InitPokemonMove(&move, moveID);
    return unk_PrintMoveDescription(a1, &move, a3, a4);
}

int unk_MovePrintMoveDescription(int a1, struct Move* move, int a3, struct subStruct_203B240** a4) {
    struct Move newMove;

    CopyAndResetMove(&newMove, move);
    return unk_PrintMoveDescription(a1, &newMove, a3, a4);
}

int unk_PrintMoveDescription(int x, struct Move* move, int a3, struct subStruct_203B240** a4) {
    char* moveDescription;
    int y;
    char buffer[800];
    
    sub_80073B8(a3);
    sub_80928C0(gAvailablePokemonNames, move, 0);
    xxx_format_and_draw(8 * x + 16, 0, gUnknown_8109930, a3, 0);
    y = 19;
    moveDescription = gMovesData[move->id].description;
    if (moveDescription[0] == '*')
    {
        y = 16;
        ++moveDescription;
    }
    xxx_format_and_draw(4, y, moveDescription, a3, 0);
    unk_MovePrintData(move, a3);
    sub_80073E0(a3);
    strcpy(buffer, gMovesData[move->id].description);
    return sub_8097DF0(buffer, a4);
}

void unk_MovePrintData(struct Move* move, int y) {
    u8 type;
    s32 power;
    const char* text;
    
    sub_80078A4(y, 4, 72, 200, COLOR_WHITE_2);
    sub_8092D54(gAvailablePokemonNames, move);
    xxx_format_and_draw(4, 74, gUnknown_810CF00, y, 0);
    xxx_format_and_draw(4, 86, gPtrTypeText, y, 0);
    type = GetMoveType(move);
    text = GetUnformattedTypeString(type);
    xxx_format_and_draw(64, 86, text, y, 0);
    power = GetMoveBasePower(move);
    gUnknown_202DE30 = power;
}

void CopyAndResetMove(struct Move* dest, struct Move* src) {
    if (src->moveFlags & MOVE_FLAG_EXISTS) {
        dest->moveFlags = src->moveFlags;
        dest->moveFlags2 = 0;
        dest->id = src->id;
        dest->PP = gMovesData[src->id].basePP;
        dest->ginseng = src->PP;  // this seems horribly bugged
    }
    else {
        dest->moveFlags = 0;
    }
}

void CopyAndResetMoves(struct Move *destMoves, struct Move *srcMoves) {
    int i;

    for (i = 0; i < 4; i++) {
        if (srcMoves[i].moveFlags & 1) {
            destMoves[i].moveFlags = srcMoves[i].moveFlags;
            destMoves[i].moveFlags2 = 0;
            destMoves[i].id = srcMoves[i].id;
            destMoves[i].PP = gMovesData[srcMoves[i].id].basePP;
            destMoves[i].ginseng = srcMoves[i].PP;
        }
        else {
            destMoves[i].moveFlags = 0;
        }
    }

    // possibly destMoves is not just an array and this is the
    // next struct field
    // this index would be out of bounds after all
    destMoves[4].moveFlags = 0;
}

void CopyBareMoveData(struct Move *destMoves, struct Move *srcMoves) {
    int i;

    for (i = 0; i < 4; i++) {
        destMoves[i].moveFlags = srcMoves[i].moveFlags;
        destMoves[i].id = srcMoves[i].id;
        destMoves[i].PP = srcMoves[i].ginseng;
    }
}

void unk_CopyMoves4To8AndClearFlag2Unk4(struct Move* destMoves, struct Move* srcMoves) {
    int movesCopied;

    movesCopied = 0;
    for (movesCopied = 0; movesCopied < 4; movesCopied++) {
        if (!(srcMoves[movesCopied].moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }

        destMoves[movesCopied] = srcMoves[movesCopied];
        destMoves[movesCopied].moveFlags2 &= ~MOVE_FLAG2_UNK4;
    }

    while (movesCopied < 8) {
        destMoves[movesCopied++].moveFlags = 0;
    }
}

void unk_CopyMoves4To8(struct Move* destMoves, struct Move* srcMoves) {
    int movesCopied;

    movesCopied = 0;
    for (movesCopied = 0; movesCopied < 4; movesCopied++) {
        if (!(srcMoves[movesCopied].moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }

        destMoves[movesCopied] = srcMoves[movesCopied];
    }

    while (movesCopied < 8) {
        destMoves[movesCopied++].moveFlags = 0;
    }
}

void sub_8094060(struct Move* srcMoves, struct Move* destMoves) {
    int i, j;

    j = 0;
    for (i = 0; i < 8; i++) {
        struct Move* srcMove = &srcMoves[i];
        struct Move* destMove;
        if (!(srcMove->moveFlags & MOVE_FLAG_EXISTS)) {
            continue;
        }
        
        if (j >= 4) {
            break;
        }
        destMove = &destMoves[j];
        *destMove = *srcMove;
        j++;
    }

    while (j < 4) {
        destMoves[j++].moveFlags = 0;
    }
}

void SavePokemonMove(struct unkStruct_8094924 *r0, struct Move *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->id, 9);
    SaveIntegerBits(r0, &move->PP, 7);
}

void RestorePokemonMove(struct unkStruct_8094924 *r0, struct Move *move)
{
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->id, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
}

void SavePokemonMoves(struct unkStruct_8094924 *r0, struct Move *moveSet)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        SavePokemonMove(r0, &moveSet[iVar4]);
    }
}

void RestorePokemonMoves(struct unkStruct_8094924 *r0, struct Move *moveSet)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        RestorePokemonMove(r0, &moveSet[iVar4]);
    }
}

void sub_8094148(struct unkStruct_8094924 *r0, struct Move *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->moveFlags2, 1);
    SaveIntegerBits(r0, &move->id, 9);
    SaveIntegerBits(r0, &move->PP, 7);
    SaveIntegerBits(r0, &move->ginseng, 7);
}

void sub_8094184(struct unkStruct_8094924 *r0, struct unkStruct_8094184 *r1)
{
    s32 r4;

    for(r4 = 0; r4 < MAX_MON_MOVES; r4++)
    {
        sub_8094148(r0, &r1->moves[r4]);
    }
    SaveIntegerBits(r0, &r1->unk20, 8);
}

void sub_80941B0(struct unkStruct_8094924 *r0, struct Move *move)
{
    memset(move, 0, sizeof(struct Move));
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->moveFlags2, 1);
    RestoreIntegerBits(r0, &move->id, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
    RestoreIntegerBits(r0, &move->ginseng, 7);
}

void sub_80941FC(struct unkStruct_8094924 *r0, struct unkStruct_8094184 *r1)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        sub_80941B0(r0, &r1->moves[iVar4]);
    }
    r1->unk20 = 0;
    RestoreIntegerBits(r0, &r1->unk20, 8);
}

bool8 DoesMoveCharge(u16 move)
{
    if(move == MOVE_SOLARBEAM)
        return TRUE;
    if(move == MOVE_SKY_ATTACK)
        return TRUE;
    if(move == MOVE_RAZOR_WIND)
        return TRUE;
    if(move == MOVE_FOCUS_PUNCH)
        return TRUE;
    if(move == MOVE_SKULL_BASH)
        return TRUE;
    if(move == MOVE_FLY)
        return TRUE;
    if(move == MOVE_BOUNCE)
        return TRUE;
    if(move == MOVE_DIVE)
        return TRUE;
    if(move == MOVE_DIG)
        return TRUE;
    return FALSE;
}
