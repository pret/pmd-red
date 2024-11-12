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

// Helper type used to make explicit the possible secondary structures which can be randomly rolled to generate in the dungeon algorithm.
enum SecondaryStructureType {
    SECONDARY_STRUCTURE_NONE, // No secondary structure will be generated.
    SECONDARY_STRUCTURE_MAZE_PLUS_DOT, // One of 3 secondary structures depending on the dimensions of the room. If the room has odd dimensions, the result is a maze room. Otherwise, if the room has dimensions of at least `5x5`, a cross or plus pattern is made instead. If both fail, a single tile of secondary terrain will be placed in the center of the room.
    SECONDARY_STRUCTURE_CHECKERBOARD, // If the room has odd dimensions, a checkerboard pattern made of randomly placed diagonal stripes of secondary terrain will be generated. If not, no secondary structure will be generated.
    SECONDARY_STRUCTURE_POOL, // If the room has dimensions of at least `5x5`, a rectangular pool of secondary terrain will be generated. If not, no secondary structure will be generated.
    SECONDARY_STRUCTURE_ISLAND, // If the room has dimensions of at least `6x6`, an island of items and a warp tile surrounded by secondary terrain will be generated. If not, no secondary structure will be generated.
    SECONDARY_STRUCTURE_DIVIDER, // A "divider" of secondary terrain will split the room in half randomly either horizontally or vertically.
};


#endif
