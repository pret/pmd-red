#ifndef GUARD_DUNGEON_GENERATION_H
#define GUARD_DUNGEON_GENERATION_H

/*
 * Defines key constant values for floor generation, providing a way
 * to modify these constants if desired.
 */
#define GENERATION_CONSTANT_MERGE_ROOMS_CHANCE 5 // (0 to 100) probability to merge two rooms together
#define GENERATION_CONSTANT_NO_IMPERFECTIONS_CHANCE 60 // (0 to 100) probability that a room will not have imperfections, if it was already flagged for them
#define GENERATION_CONSTANT_SECONDARY_STRUCTURE_FLAG_CHANCE 80 // (0 to 100) probability that a room will be flagged to have a secondary structure.

enum FloorType {
	FLOOR_TYPE_NORMAL,
	FLOOR_TYPE_FIXED, // Fixed room
	FLOOR_TYPE_RESCUE, // Rescuing another player
};

#endif
