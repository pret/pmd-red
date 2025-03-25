#ifndef GUARD_STR_IQ_SKILL_FLAGS_H
#define GUARD_STR_IQ_SKILL_FLAGS_H

#define NUM_PICKED_IQ_SKILLS 3

// size: R=0x4 | B=0x3
typedef struct IqSkillFlags
{
    /* 0x0 */ u8 flags[NUM_PICKED_IQ_SKILLS];
} IqSkillFlags;

#endif // GUARD_STR_IQ_SKILL_FLAGS_H
