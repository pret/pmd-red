#include "global.h"
#include "effect_files_table.h"

const FileArchive gEffectFileArchive = {
    .magic = "pksdir0",
    .count = EFFECT_FILES_COUNT,
    .entries = gEffectFiles,
};
