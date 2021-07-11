# Dungeon Floor data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

DUNGEON_DIRS := $(dir $(wildcard $(DUNGEONS_DIR)/*/main_data.json))
DUNGEON_FLOOR := $(patsubst $(DUNGEONS_DIR)/%/,$(DUNGEONS_DIR)/%/main_data.inc,$(DUNGEON_DIRS))


dungeon_main_data: $(DUNGEON_FLOOR);

$(DUNGEONS_DIR)/%/main_data.inc: $(DUNGEONS_DIR)/%/main_data.json
	$(DUNGEONJSON) main_data pmd-red $<
