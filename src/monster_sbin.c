#include "global.h"
#include "file_system.h"
#include "monster_files_table.h"

const FileArchive gMonsterFileArchive = {
    .magic = "pksdir0",
    .count = MONSTER_FILES_COUNT,
    .entries = gMonsterFiles,
};
