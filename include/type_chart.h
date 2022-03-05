#ifndef GUARD_TYPE_CHART_H
#define GUARD_TYPE_CHART_H

#include "global.h"
#include "constants/type.h"

#define NUM_EFFECTIVENESS 4

#define EFFECTIVENESS_IMMUNE 0
#define EFFECTIVENESS_RESIST 1
#define EFFECTIVENESS_NEUTRAL 2
#define EFFECTIVENESS_SUPER 3

// [Attacking type][Defending type]
extern const s16 gTypeEffectivenessChart[NUM_TYPES][NUM_TYPES];

#endif