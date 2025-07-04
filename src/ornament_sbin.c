#include "global.h"
#include "file_system.h"
#include "ornament_files_table.h"

const FileArchive gOrnamentFileArchive = {
    .magic = "pksdir0",
    .count = ORNAMENT_FILES_COUNT,
    .entries = gOrnamentFiles,
};
