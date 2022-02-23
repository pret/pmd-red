#include "global.h"
#include "dungeon_ai_attack_1.h"

#include "constants/direction.h"
#include "dungeon_pokemon_attributes.h"
#include "position_util.h"

extern bool8 gCanAttackInDirection[NUM_DIRECTIONS];
extern s32 gPotentialAttackTargetWeights[NUM_DIRECTIONS];
extern u8 gPotentialAttackTargetDirections[NUM_DIRECTIONS];
extern struct DungeonEntity *gPotentialTargets[NUM_DIRECTIONS];

extern bool8 CanUseStatusMove(s32, struct DungeonEntity*, struct DungeonEntity*, struct PokemonMove*, bool8);
extern s32 WeightMove(struct DungeonEntity*, s32, struct DungeonEntity*, u8);

s32 WeightMoveIfUsable(s32 numPotentialTargets, s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, bool32 hasStatusChecker)
{
    s32 facingDir;
    s32 targetingFlags2 = (s16) targetingFlags;
    bool8 hasStatusChecker2 = hasStatusChecker;
    struct DungeonEntityData *userData = user->entityData;
    if ((user->posWorld.x == target->posWorld.x && user->posWorld.y == target->posWorld.y) ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_ROOM ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_FLOOR ||
        (targetingFlags2 & 0xF0) == TARGETING_FLAG_TARGET_SELF)
    {
        facingDir = userData->action.facingDir;
    }
    else
    {
        facingDir = CalculateFacingDir(&user->posWorld, &target->posWorld);
    }
    if (!gCanAttackInDirection[facingDir] &&
        CanUseStatusMove(targetingFlags2, user, target, move, hasStatusChecker2))
    {
        gCanAttackInDirection[facingDir] = TRUE;
        do { gPotentialAttackTargetDirections[numPotentialTargets] = facingDir; } while (0);
        gPotentialAttackTargetWeights[numPotentialTargets] = WeightMove(user, targetingFlags2, target, GetMoveTypeForPokemon(user, move));
        gPotentialTargets[numPotentialTargets] = target;
        numPotentialTargets++;
    }
    return numPotentialTargets;
}

// NAKED
// s32 WeightMoveIfUsable(s32 numPotentialTargets, s32 targetingFlags, struct DungeonEntity *user, struct DungeonEntity *target, struct PokemonMove *move, bool8 hasStatusChecker)
// {
//     asm_unified("push {r4-r7,lr}\n"
// "mov r7, r10\n"
// "mov r6, r9\n"
// "mov r5, r8\n"
// "push {r5-r7}\n"
// "sub sp, 0x4\n"
// "adds r6, r0, 0\n"
// "adds r5, r2, 0\n"
// "adds r7, r3, 0\n"
// "ldr r0, [sp, 0x28]\n"
// "lsls r1, 16\n"
// "asrs r1, 16\n"
// "mov r9, r1\n"
// "lsls r0, 24\n"
// "lsrs r0, 24\n"
// "mov r10, r0\n"
// "ldr r2, [r5, 0x70]\n"
// "ldr r1, [r5, 0x4]\n"
// "ldr r0, [r7, 0x4]\n"
// "cmp r1, r0\n"
// "beq _0807C5BC\n"
// "movs r0, 0xF0\n"
// "mov r1, r9\n"
// "ands r0, r1\n"
// "cmp r0, 0x30\n"
// "beq _0807C5BC\n"
// "cmp r0, 0x60\n"
// "beq _0807C5BC\n"
// "cmp r0, 0x70\n"
// "bne _0807C5C4\n"
// "_0807C5BC:\n"
// "adds r0, r2, 0\n"
// "adds r0, 0x46\n"
// "ldrb r4, [r0]\n"
// "b _0807C5CE\n"
// "_0807C5C4:\n"
// "adds r0, r5, 0x4\n"
// "adds r1, r7, 0x4\n"
// "bl CalculateFacingDir\n"
// "adds r4, r0, 0\n"
// "_0807C5CE:\n"
// "ldr r0, _0807C638\n"
// "adds r0, r4\n"
// "mov r8, r0\n"
// "ldrb r0, [r0]\n"
// "cmp r0, 0\n"
// "bne _0807C624\n"
// "mov r0, r10\n"
// "str r0, [sp]\n"
// "mov r0, r9\n"
// "adds r1, r5, 0\n"
// "adds r2, r7, 0\n"
// "ldr r3, [sp, 0x24]\n"
// "bl CanUseStatusMove\n"
// "lsls r0, 24\n"
// "cmp r0, 0\n"
// "beq _0807C624\n"
// "movs r0, 0x1\n"
// "mov r1, r8\n"
// "strb r0, [r1]\n"
// "ldr r0, _0807C63C\n"
// "adds r0, r6, r0\n"
// "strb r4, [r0]\n"
// "adds r0, r5, 0\n"
// "ldr r1, [sp, 0x24]\n"
// "bl GetMoveTypeForPokemon\n"
// "adds r3, r0, 0\n"
// "lsls r3, 24\n"
// "lsrs r3, 24\n"
// "adds r0, r5, 0\n"
// "mov r1, r9\n"
// "adds r2, r7, 0\n"
// "bl WeightMove\n"
// "ldr r1, _0807C640\n"
// "lsls r2, r6, 2\n"
// "adds r1, r2, r1\n"
// "str r0, [r1]\n"
// "ldr r0, _0807C644\n"
// "adds r2, r0\n"
// "str r7, [r2]\n"
// "adds r6, 0x1\n"
// "_0807C624:\n"
// "adds r0, r6, 0\n"
// "add sp, 0x4\n"
// "pop {r3-r5}\n"
// "mov r8, r3\n"
// "mov r9, r4\n"
// "mov r10, r5\n"
// "pop {r4-r7}\n"
// "pop {r1}\n"
// "bx r1\n"
// ".align 2, 0\n"
// "_0807C638: .4byte gCanAttackInDirection\n"
// "_0807C63C: .4byte gPotentialAttackTargetDirections\n"
// "_0807C640: .4byte gPotentialAttackTargetWeights\n"
// "_0807C644: .4byte gPotentialTargets");
// }
