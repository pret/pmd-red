# Dungeon trap data

DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

DUNGEON_TRAP = $(DUNGEONS_DIR)/trap_data.inc

dungeon_trap: $(DUNGEON_TRAP);

$(DUNGEON_TRAP): $(DUNGEONS_DIR)/trap_data.json
	$(DUNGEONJSON) trap pmd-red $<

