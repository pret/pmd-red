
DUNGEONS_DIR = $(DATA_ASM_SUBDIR)/dungeon

DUNGEON_ITEM = $(DUNGEONS_DIR)/dungeon_item_data.inc

dungeon_item: $(DUNGEON_ITEM);

$(DUNGEON_ITEM): $(DUNGEONS_DIR)/dungeon_item_data.json
	$(DUNGEONJSON) dungeon_item pmd-red $<
