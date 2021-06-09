# Dungeon Floor data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

DUNGEON_DIRS := $(dir $(wildcard $(DUNGEONS_DIR)/*/floor_id.json))
DUNGEON_FLOOR := $(patsubst $(DUNGEONS_DIR)/%/,$(DUNGEONS_DIR)/%/floor_id.inc,$(DUNGEON_DIRS))


dungeon_floor: $(DUNGEON_FLOOR);

$(DUNGEONS_DIR)/%/floor_id.inc: $(DUNGEONS_DIR)/%/floor_id.json
	$(DUNGEONJSON) floor pmd-red $<
