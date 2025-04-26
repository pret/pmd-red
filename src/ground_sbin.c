#include "global.h"
#include "file_system.h"

#define GROUND_FILES_COUNT 0x2A5

extern const File gGroundFiles[GROUND_FILES_COUNT];

const FileArchive gGroundFileArchive = {
    .magic = "pksdir0",
    .count = GROUND_FILES_COUNT,
    .entries = gGroundFiles,
};

UNUSED static const char sPksDir2[] = "pksdir0";
