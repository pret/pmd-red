#include "global.h"
#include "ground_files_table.h"

const FileArchive gGroundFileArchive = {
    .magic = "pksdir0",
    .count = GROUND_FILES_COUNT,
    .entries = gGroundFiles,
};
